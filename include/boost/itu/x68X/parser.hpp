//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680ROOTPARSER_H_
#define          _ITU_X680ROOTPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/type.hpp>


namespace x680 {
    namespace bnf {

        // Exports
        
        extern strvect_sk_rule Exports_;

        //SymbolsFromModule

        template <typename Iterator>
        struct SymbolsFromModule_grammar
        : qi::grammar<Iterator, import(), skip_cmt_type> {

            typedef SymbolsFromModule_grammar self_type;
            typedef import holder_type;

            SymbolsFromModule_grammar()
            : SymbolsFromModule_grammar::base_type(start_rule) {

                start_rule = SymbolList_[ bind(&self_type::imports_add, *this, qi::_val, qi::_1) ]
                        >> FROM_
                        >> modulereference_[ bind(&self_type::module_name, *this, qi::_val, qi::_1) ]
                        >> -ObjectIdentifierValue_[ bind(&self_type::module_oid, *this, qi::_val, qi::_1) ];
            }

            void module_name(holder_type& holder, const std::string & val) {
                holder.name = val;
            }

            void module_oid(holder_type& holder, const value_element_vector & val) {
                holder.oid = val;
            }

            void imports_add(holder_type& holder, const string_vector & val) {
                holder.names = val;
            }

            qi::rule<Iterator, import(), skip_cmt_type > start_rule;
            ObjectIdentifierValue_grammar< std::string::iterator> ObjectIdentifierValue_;
        };

        extern SymbolsFromModule_grammar<std::string::iterator> SymbolsFromModule_;

        extern imports_sk_rule SymbolsFromModules_;

        extern imports_sk_rule Imports_;        
        

        // ModuleDefinition

        template <typename Iterator>
        struct ModuleDefinition_grammar
        : qi::grammar<Iterator, module(), skip_cmt_type> {

            typedef ModuleDefinition_grammar self_type;
            typedef module holder_type;

            struct tag_default : qi::symbols<std::string::value_type, default_tags_type > {

                tag_default() {
                    add
                            ("EXPLICIT", explicit_tags)
                            ("IMPLICIT", implicit_tags)
                            ("AUTOMATIC", automatic_tags)
                            ;
                }
            };

            struct encoding_references : qi::symbols<std::string::value_type, encoding_references_type > {

                encoding_references() {
                    add
                            ("TAG", encoding_tag)
                            ("XER", encoding_tag)
                            ("PER", encoding_tag)
                            ;
                }
            };

            ModuleDefinition_grammar()
            : ModuleDefinition_grammar::base_type(start_rule) {


                start_rule = qi::lexeme[ modulereference_[ bind(&self_type::module_name, *this, qi::_val, qi::_1) ]]
                        >> -ObjectIdentifierValue_[ bind(&self_type::module_oid, *this, qi::_val, qi::_1) ]
                        >> qi::lexeme[DEFINITIONS_ ]

                        >> -(qi::lexeme[encodingreference[bind(&self_type::encoding, *this, qi::_val, qi::_1)]]
                        >> qi::lexeme[INSTRUCTIONS_])

                        >> -(qi::lexeme[ tagdefault[bind(&self_type::default_tags, *this, qi::_val, qi::_1)]
                        >> +qi::blank >> TAGS_])

                        >> -(qi::lexeme[EXTENSIBILITY_
                        >> +qi::blank
                        >> IMPLIED_[ bind(&self_type::extesibility_implied, *this, qi::_val) ]])

                        >> qi::lexeme[qi::lit("::=")]
                        >> qi::lexeme[BEGIN_]
                        >> -(Exports_[bind(&self_type::exports, *this, qi::_val, qi::_1)])
                        >> -(Imports_[bind(&self_type::add_imports, *this, qi::_val, qi::_1)])
                        >> -(Types[bind(&self_type::add_types, *this, qi::_val, qi::_1)])
                        >> END_;


            }

            void module_name(holder_type& holder, const std::string & val) {
                holder.name = val;
            }

            void module_oid(holder_type& holder, const value_element_vector & val) {
                holder.oid = val;
            }

            void default_tags(holder_type& holder, const default_tags_type & val) {
                holder.default_tags_t = val;
            }

            void encoding(holder_type& holder, const encoding_references_type & val) {
                holder.encoding_references_t = val;
            }

            void extesibility_implied(holder_type & holder) {
                holder.extesibility_implied = true;
            }

            void exports(holder_type& holder, const string_vector & val) {
                holder.exports_ = val;
            }

            void add_imports(holder_type& holder, const imports & val) {
                holder.imports_ = val;
            }
            
            void add_types(holder_type& holder, const type_element_vector & val) {
                holder.elements = val;
            }

            // declaring rules

            qi::rule<Iterator, module(), skip_cmt_type > start_rule;
            tag_default tagdefault;
            encoding_references encodingreference;
            Types_grammar<Iterator> Types;

        };

        extern ModuleDefinition_grammar<std::string::iterator> ModuleDefinition_;

    }
}



#endif	

