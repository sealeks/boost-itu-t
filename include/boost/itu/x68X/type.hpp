//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680TYPEPARSER_H_
#define         _ITU_X680TYPEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>
#include <boost/itu/x68X/value.hpp>

namespace x680 {
    namespace bnf {
        
        //Tag

        struct Tag_grammar : qi::grammar<str_iterator, tag_type(), skip_cmt_type> {

            typedef Tag_grammar self_type;
            typedef tag_type holder_type;

            struct check_class : qi::symbols<std::string::value_type, tagclass_type > {

                check_class() {

                    add
                            ("UNIVERSAL", tcl_universal)
                            ("APPLICATION", tcl_application)
                            ("PRIVATE", tcl_private)
                            ;
                }
            };

            struct check_rule : qi::symbols<std::string::value_type, tagrule_type > {

                check_rule() {

                    add
                            ("IMPLICIT", implicit_tags)
                            ("EXPLICIT", explicit_tags)
                            ;
                }
            };

            Tag_grammar() :
            Tag_grammar::base_type(start_rule) {

                start_rule = -(Rule[bind(&self_type::ruleset, *this, qi::_val, qi::_1)])
                        >> qi::lit("[")
                        >> -(Class[bind(&self_type::classset, *this, qi::_val, qi::_1)])
                        >> (pos_number_str | DefinedValue_)[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        >> qi::lit("]");

            }

            void ruleset(holder_type& holder, const tagrule_type& val) {
                holder.rule = val;
            }

            void classset(holder_type& holder, const tagclass_type& val) {
                holder.class_ = val;
            }

            void operator()(holder_type& holder, const std::string& val) {
                holder.number = val;
            }

            check_class Class;
            check_rule Rule;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
        };      
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // ReferencedType
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
        
        struct Type_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef Type_grammar self_type;
            typedef type_element holder_type;
            
            
            struct check_type_simple : qi::symbols<std::string::value_type, defined_type > {

                check_type_simple() {

                    add
                            ("BOOLEAN", t_BOOLEAN)
                            ("NULL", t_NULL)
                            ("ObjectDescriptor", t_ObjectDescriptor)
                            ("EXTERNAL", t_EXTERNAL)
                            ("REAL", t_REAL)
                            ("UTCTime", t_UTCTime)
                            ("GeneralizedTime", t_GeneralizedTime)
                            ("TIME", t_TIME)
                            ("DATE", t_DATE)
                            ("DURATION", t_TIME)
                            ("UTF8String", t_UTF8String)
                            ("NumericString", t_NumericString)
                            ("PrintableString", t_PrintableString)
                            ("T61String", t_T61String)
                            ("VideotexString", t_VideotexString)
                            ("IA5String", t_IA5String)
                            ("GraphicString", t_GraphicString)
                            ("VisibleString", t_VisibleString)
                            ("GeneralString", t_GeneralString)
                            ("UniversalString", t_UniversalString)
                            ("BMPString", t_BMPString)
                            ("TIME-OF-DAY", t_TIME_OF_DAY)
                            ;
                }
            };            
            

            Type_grammar() :
            Type_grammar::base_type(start_rule) {
                init();
            }

            void init();
 

            void defftype(holder_type& holder, const defined_type& type) {
                holder.builtin_t = type;
            }

            
            void refference(holder_type& holder, const std::string& val) {
                holder.reference = val;
            }
            

            void deffinit(holder_type& holder, const value_element_vector & val) {
                holder.predefined = val;
            }   
            
            void tagset(holder_type& holder, const tag_type& val) {
                holder.tag = val;
            }
            
 
            
            
            
           // void operator()(holder_type& holder, const named_type_element& val) {
            //    holder.elements.push_back(val);
            //}


            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            
            qi::rule<str_iterator, holder_type(), skip_cmt_type> Type;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> BuitinType;            
            qi::rule<str_iterator, holder_type(), skip_cmt_type> DefinedType;    
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ReferencedType;
            check_type_simple simple_typer;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SimpleType;
            
            qi::rule<str_iterator, holder_type(), skip_cmt_type> IntegerType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> EnumeratedType;            
            qi::rule<str_iterator, holder_type(), skip_cmt_type> BitStringType;
            Enumerations_grammar Enumerations;
            NamedNumberList_grammar NamedNumberList;
            NamedNumberList_grammar NameBitList;
            Tag_grammar Tag;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> TaggedType;           

        }; 





        //TypeAssignment

        struct TypeAssignment_grammar : qi::grammar<str_iterator, type_assigment(), skip_cmt_type> {

            typedef TypeAssignment_grammar self_type;
            typedef type_assigment holder_type;

            TypeAssignment_grammar() :
            TypeAssignment_grammar::base_type(start_rule) {

                start_rule = typereference_[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        >> qi::lexeme[qi::lit("::=")]
                        >> Type[bind(&self_type::element, *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void element(holder_type& holder, const type_element& val) {
                holder.from(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar Type;

        };



        //extern syn_elements_sk_rule Types_;

        struct Types_grammar : qi::grammar<str_iterator, type_assigment_vector(), skip_cmt_type> {

            typedef Types_grammar self_type;
            typedef type_assigment_vector holder_type;

            Types_grammar() :
            Types_grammar::base_type(start_rule) {

                start_rule = *TypeAssignment;

            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            ;
            TypeAssignment_grammar TypeAssignment;
        };

    }
}



#endif	

