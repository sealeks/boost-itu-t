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


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Simple declareted type
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename Iterator>
        struct SympleTypeDecl_grammar : qi::grammar<Iterator, builtin_type_element(), skip_cmt_type> {

            typedef SympleTypeDecl_grammar self_type;
            typedef builtin_type_element holder_type;

            struct check_type_simple : qi::symbols<std::string::value_type, defined_type > {

                check_type_simple() {

                    add
                            ("BOOLEAN", t_BOOLEAN)
                            ("NULL", t_NULL)
                            ("ObjectDescriptor" , t_ObjectDescriptor)
                            ("EXTERNAL", t_EXTERNAL)
                            ("REAL",  t_REAL)
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
                            ("TIME-OF-DAY",t_TIME_OF_DAY)
                            ;
                }
            };

            SympleTypeDecl_grammar() :
            SympleTypeDecl_grammar::base_type(start_rule) {

                start_rule =  ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&self_type::operator(), *this, qi::_val, t_OCTET_STRING)]
                        | (qi::lexeme[CHARACTER_>> +qi::blank >> STRING_])[bind(&self_type::operator(), *this, qi::_val, t_CHARACTER_STRING)]                        
                        | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&self_type::operator(), *this, qi::_val, t_EMBEDDED_PDV)]
                        | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&self_type::operator(), *this, qi::_val, t_OBJECT_IDENTIFIER)]
                        | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&self_type::operator(), *this, qi::_val, t_DATE_TIME)]                 
                        | simple_typer[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        );                        

                
            }


            void operator()(builtin_type_element& holder, const defined_type & tp) {
                holder.builtin_t = tp;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            check_type_simple simple_typer;

        };
        
        extern SympleTypeDecl_grammar<std::string::iterator> SympleTypeDecl_;
        

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // INTEGER
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // IntegerType

        template <typename Iterator>
        struct IntegerType_grammar : qi::grammar<Iterator, builtin_type_element(), skip_cmt_type> {

            typedef IntegerType_grammar self_type;
            typedef builtin_type_element holder_type;

            IntegerType_grammar() :
            IntegerType_grammar::base_type(start_rule) {

                start_rule = INTEGER_[bind(&self_type::operator(), *this, qi::_val)]
                        >> -NamedNumberList[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(builtin_type_element & holder) {
                holder.builtin_t = t_INTEGER;
            }

            void operator()(builtin_type_element& holder, const value_element_vector & val) {
                holder.predefined = val;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            NamedNumberList_grammar<Iterator> NamedNumberList;

        };

        extern IntegerType_grammar<std::string::iterator> IntegerType_;


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // ENUMERATED
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        // EnumeratedType

        template <typename Iterator>
        struct EnumeratedType_grammar : qi::grammar<Iterator, builtin_type_element(), skip_cmt_type> {

            typedef EnumeratedType_grammar self_type;
            typedef builtin_type_element holder_type;

            EnumeratedType_grammar() :
            EnumeratedType_grammar::base_type(start_rule) {

                start_rule = ENUMERATED_[bind(&self_type::operator(), *this, qi::_val)]
                        >> -Enumerations[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(builtin_type_element & holder) {
                holder.builtin_t = t_ENUMERATED;
            }

            void operator()(builtin_type_element& holder, const value_element_vector & val) {
                holder.predefined = val;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            Enumerations_grammar<Iterator> Enumerations;

        };    
                
        extern EnumeratedType_grammar<std::string::iterator> EnumeratedType_;


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // BIT STRING
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // BitStringTypeType

        template <typename Iterator>
        struct BitStringType_grammar : qi::grammar<Iterator, builtin_type_element(), skip_cmt_type> {

            typedef BitStringType_grammar self_type;
            typedef builtin_type_element holder_type;

            BitStringType_grammar() :
            BitStringType_grammar::base_type(start_rule) {

                start_rule = qi::lexeme[BIT_ >> +qi::blank >> STRING_[bind(&self_type::operator(), *this, qi::_val)]]
                        >> -NameBitList[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }


            void operator()(builtin_type_element & holder) {
                holder.builtin_t = t_BIT_STRING;
            }

            void operator()(builtin_type_element& holder, const value_element_vector & val) {
                holder.predefined = val;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            NamedNumberList_grammar<Iterator> NameBitList;

        };
        
        extern BitStringType_grammar<std::string::iterator> BitStringType_;        


        
        
        
        
        //BuiltinType

        template <typename Iterator>
        struct BuiltinType_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef BuiltinType_grammar self_type;
            typedef type_element holder_type;

            BuiltinType_grammar() :
            BuiltinType_grammar::base_type(start_rule) {

                start_rule = (IntegerType_ | EnumeratedType_ | BitStringType_ | SympleTypeDecl_)[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder, const builtin_type_element& val) {
               holder.from(val);
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;

        };
        
       extern BuiltinType_grammar<std::string::iterator> BuiltinType_;   
        
        
        
        //DefindeType

        template <typename Iterator>
        struct DefinedType_grammar : qi::grammar<Iterator, defined_type_element(), skip_cmt_type> {

            typedef DefinedType_grammar self_type;
            typedef defined_type_element holder_type;

            DefinedType_grammar() :
            DefinedType_grammar::base_type(start_rule) {

                start_rule = DefinedType_[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder, const std::string& val) {
               holder.reference =val;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;

        };        
        
        extern DefinedType_grammar<std::string::iterator> DefinedType; 
        
        
         //ReferencedType

        template <typename Iterator>
        struct ReferencedType_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef ReferencedType_grammar self_type;
            typedef type_element holder_type;

            ReferencedType_grammar() :
            ReferencedType_grammar::base_type(start_rule) {

                start_rule = DefinedType[bind(&self_type::operator(), *this, qi::_val, qi::_1)];;

            }

            void operator()(holder_type& holder, const defined_type_element& val) {
               holder.from(val);
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;

        };     
        
        extern ReferencedType_grammar<std::string::iterator> ReferencedType_;       
        
        
        
        
        
            //Type

        template <typename Iterator>
        struct Type_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef Type_grammar self_type;
            typedef type_element holder_type;

            Type_grammar() :
            Type_grammar::base_type(start_rule) {

                start_rule = (BuiltinType_ | ReferencedType_)/* | ConstrainedType_[bind(&self_type::operator(), *this, qi::_val, qi::_1)];*/;

            }

            //void operator()(holder_type& holder, const defined_type_element& val) {
            //    holder.from(val);
            //}

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;

        };     
        
        extern Type_grammar<std::string::iterator> Type_;      
        
        

        //TypeAssignment

        template <typename Iterator>
        struct TypeAssignment_grammar : qi::grammar<Iterator, type_assigment(), skip_cmt_type> {

            typedef TypeAssignment_grammar self_type;
            typedef type_assigment holder_type;

            TypeAssignment_grammar() :
            TypeAssignment_grammar::base_type(start_rule) {

                start_rule = typereference_[bind(&self_type::operator(), *this, qi::_val, qi::_1)] 
                        >> qi::lexeme[qi::lit("::=")] 
                        >>Type_[bind(&self_type::element, *this, qi::_val, qi::_1)];

            }
            
            void operator()(holder_type& holder, const std::string& val) {
                holder.identifier=val;
            }            

            void element(holder_type& holder, const type_element& val) {
                holder.from(val);
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;

        };

        extern TypeAssignment_grammar<std::string::iterator> TypeAssignment_;



        //extern syn_elements_sk_rule Types_;

        template <typename Iterator>
        struct Types_grammar : qi::grammar<Iterator, type_assigment_vector(), skip_cmt_type> {

            typedef Types_grammar self_type;
            typedef type_assigment_vector holder_type;

            Types_grammar() :
            Types_grammar::base_type(start_rule) {

                start_rule = *TypeAssignment_;

            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar<std::string::iterator> Type_;
        };

    }
}



#endif	

