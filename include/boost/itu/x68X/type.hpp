//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680TYPEPARSER_H_
#define         _ITU_X680TYPEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace bnf {

        /*("BOOLEAN", t_BOOLEAN)
        ("INTEGER", t_INTEGER)
        ("BIT STRING", t_BIT_STRING)
        ("OCTET STRING", t_OCTET_STRING)
        ("NULL", t_NULL)
        ("OBJECT IDENTIFIER", t_OBJECT_IDENTIFIER)
        ("Object Descriptor", t_Object_Descriptor)
        ("EXTERNAL", t_EXTERNAL)
        ("REAL", t_REAL)
        ("ENUMERATED", t_ENUMERATED)
        ("EMBEDDED_PDV", t_EMBEDDED_PDV)
        ("UTF8String", t_UTF8String)
        ("RELATIVE OID", t_RELATIVE_OID)
        ("SEQUENCE", t_SEQUENCE)
        ("SEQUENCE OF", t_SEQUENCE_OF)
        ("SET", t_SET)
        ("SET OF", t_SET_OF)
        ("NumericString", t_NumericString)
        ("PrintableString", t_PrintableString)
        ("T61String", t_T61String)
        ("VideotexString", t_VideotexString)
        ("IA5String", t_IA5String)
        ("UTCTime", t_UTCTime)
        ("GeneralizedTime", t_GeneralizedTime)
        ("GraphicString", t_GraphicString)
        ("VisibleString", t_VisibleString)
        ("GeneralString", t_GeneralString)
        ("UniversalString", t_UniversalString)
        ("CHARACTER STRING", t_CHARACTER_STRING)
        ("BMPString", t_BMPString)
        ("TIME", t_TIME)
        ("TIME OF DAY", t_TIME_OF_DAY)
        ("DATE", t_DATE)
        ("DATE TIME", t_DATE_TIME)
        ("CHOICE", t_CHOICE)*/

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Cimple declareted type
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename Iterator>
        struct SympleTypeDecl_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef SympleTypeDecl_grammar self_type;
            typedef type_element holder_type;

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

                start_rule = typereference_[bind(&self_type::identificator, *this, qi::_val, qi::_1)]
                        >> "::="
                        >> ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&self_type::type, *this, qi::_val, t_OCTET_STRING)]
                        | (qi::lexeme[CHARACTER_>> +qi::blank >> STRING_])[bind(&self_type::type, *this, qi::_val, t_CHARACTER_STRING)]                        
                        | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&self_type::type, *this, qi::_val, t_EMBEDDED_PDV)]
                        | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&self_type::type, *this, qi::_val, t_OBJECT_IDENTIFIER)]
                        | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&self_type::type, *this, qi::_val, t_DATE_TIME)]                 
                        | simple_typer[bind(&self_type::type, *this, qi::_val, qi::_1)]
                        );                        

                
            }

            void identificator(type_element& holder, const std::string & val) {

                holder.identifier = val;
            }

            void type(type_element& holder, const defined_type & tp) {
                holder.builtin_t = tp;
            }



            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            check_type_simple simple_typer;

        };
        
        extern SympleTypeDecl_grammar<std::string::iterator> SympleTypeDecl_;
        

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // INTEGER
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // NamedNumber_grammar

        template <typename Iterator>
        struct NamedNumber_grammar : qi::grammar<Iterator, value_element(), skip_cmt_type> {

            typedef NamedNumber_grammar self_type;
            typedef value_element holder_type;

            NamedNumber_grammar() :
            NamedNumber_grammar::base_type(pair) {

                pair = (identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        >> qi::lit("(")
                        >> (number_str[bind(&self_type::second_n, *this, qi::_val, qi::_1)]  
                        | identifier_[bind(&self_type::second_i , *this, qi::_val, qi::_1)] )
                        >> qi::lit(")"));
            }

            void first(holder_type& holder, const std::string & val) {

                holder.identifier = val;
                
            }

            void second_n(holder_type& holder, const std::string & val) {
                holder.type =v_number;
                holder.value = val;
            }
            
            void second_i(holder_type& holder, const std::string & val) {
                holder.type =v_identifier;
                holder.value = val;
            }            


            qi::rule<Iterator, holder_type(), skip_cmt_type> pair;


        };

        //NamedNumberList        

        template <typename Iterator>
        struct NamedNumberList_grammar : qi::grammar<Iterator, value_element_vector(), skip_cmt_type> {

            typedef NamedNumberList_grammar self_type;
            typedef value_element_vector holder_type;

            NamedNumberList_grammar() :
            NamedNumberList_grammar::base_type(vect)  {

                vect = qi::lit("{")
                        >> -(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::omit[","])
                        >> qi::lit("}");
            }

            void operator()(holder_type& holder, const value_element & val) {
                holder.push_back(val);
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type > vect;
            NamedNumber_grammar<Iterator> components;

        };

        // IntegerType

        template <typename Iterator>
        struct IntegerType_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef IntegerType_grammar self_type;
            typedef type_element holder_type;

            IntegerType_grammar() :
            IntegerType_grammar::base_type(start_rule) {

                start_rule = typereference_[bind(&self_type::identificator, *this, qi::_val, qi::_1)]
                        >> "::="
                        >> INTEGER_[bind(&self_type::type, *this, qi::_val)]
                        >> -NamedNumberList[bind(&self_type::predefined, *this, qi::_val, qi::_1)];

            }

            void identificator(type_element& holder, const std::string & val) {

                holder.identifier = val;
            }

            void type(type_element & holder) {

                holder.builtin_t = t_INTEGER;
                holder.syntactic_t = s_BuiltinType;
            }

            void predefined(type_element& holder, const value_element_vector & val) {

                holder.predefined = val;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            NamedNumberList_grammar<Iterator> NamedNumberList;

        };

        extern IntegerType_grammar<std::string::iterator> IntegerType_;


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // ENUMERATED
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // Enumeration_grammar

        template <typename Iterator>
        struct Enumeration_grammar : qi::grammar<Iterator, value_element(), skip_cmt_type> {

            typedef Enumeration_grammar self_type;
            typedef value_element holder_type;

            Enumeration_grammar() :
            Enumeration_grammar::base_type(pair) {

                     pair = component[ qi::_val = qi::_1 ] |
                       identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        | qi::lit("...")[bind(&self_type::extention, *this, qi::_val)];
            }

            void first(holder_type& holder, const std::string & val) {
                holder.identifier = val;
                holder.type= v_identifier;
                
            }

            void extention(holder_type & holder) {
                holder.type= v_extention;
            }       



            qi::rule<Iterator, holder_type(), skip_cmt_type> pair;
            NamedNumber_grammar<Iterator> component;

        };

        //Enumerations       

        template <typename Iterator>
        struct Enumerations_grammar : qi::grammar<Iterator, value_element_vector(), skip_cmt_type> {

            typedef Enumerations_grammar self_type;
            typedef value_element_vector holder_type;

            Enumerations_grammar() :
            Enumerations_grammar::base_type(vect) {

                vect = qi::lit("{")
                        >> -(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::omit[","])
                        >> qi::lit("}");
            }

            void operator()(holder_type& holder, const value_element & val) {

                holder.push_back(val);
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type > vect;
            Enumeration_grammar<Iterator> components;

        };

        // EnumeratedType

        template <typename Iterator>
        struct EnumeratedType_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef EnumeratedType_grammar self_type;
            typedef type_element holder_type;

            EnumeratedType_grammar() :
            EnumeratedType_grammar::base_type(start_rule) {

                start_rule = typereference_[bind(&self_type::identificator, *this, qi::_val, qi::_1)]
                        >> "::="
                        >> ENUMERATED_[bind(&self_type::type, *this, qi::_val)]
                        >> -Enumerations[bind(&self_type::predefined, *this, qi::_val, qi::_1)];

            }

            void identificator(type_element& holder, const std::string & val) {

                holder.identifier = val;
            }

            void type(type_element & holder) {

                holder.builtin_t = t_ENUMERATED;
                holder.syntactic_t = s_BuiltinType;
            }

            void predefined(type_element& holder, const value_element_vector & val) {

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
        struct BitStringType_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef BitStringType_grammar self_type;
            typedef type_element holder_type;

            BitStringType_grammar() :
            BitStringType_grammar::base_type(start_rule) {

                start_rule = typereference_[bind(&self_type::identificator, *this, qi::_val, qi::_1)]
                        >> "::="
                        >> qi::lexeme[BIT_ >> +qi::blank >> STRING_[bind(&self_type::type, *this, qi::_val)]]
                        >> -NameBitList[bind(&self_type::predefined, *this, qi::_val, qi::_1)];

            }

            void identificator(type_element& holder, const std::string & val) {

                holder.identifier = val;
            }

            void type(type_element & holder) {

                holder.builtin_t = t_BIT_STRING;
                holder.syntactic_t = s_BuiltinType;
            }

            void predefined(type_element& holder, const value_element_vector & val) {

                holder.predefined = val;
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            NamedNumberList_grammar<Iterator> NameBitList;

        };
        
        extern BitStringType_grammar<std::string::iterator> BitStringType_;        
        
        
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // OBJECT IDENTIFIER
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
         //objNameId

        template <typename Iterator>
        struct objNameId_grammar : public qi::grammar<Iterator, value_element(), skip_cmt_type> {

            typedef objNameId_grammar self_type;
            typedef value_element holder_type;

            objNameId_grammar()
            : objNameId_grammar::base_type(pair) {

                pair = (identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        >> qi::lit("(")
                        >> pos_number_str[bind(&self_type::second, *this, qi::_val, qi::_1)]
                        >> qi::lit(")"))
                        | identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        | pos_number_str[bind(&self_type::second, *this, qi::_val, qi::_1)];
            }

            void first(holder_type& holder, const std::string & val) {
                holder.identifier = val;
                holder.type = v_identifier;
            }

            void second(holder_type& holder, const std::string & val) {
                holder.value = val;
                holder.type = v_number;                
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type > pair;
        };

        extern objNameId_grammar<std::string::iterator> ObjIdComponents_;





        //ObjectIdentifierValue

        template <typename Iterator>
        struct ObjectIdentifierValue_grammar :
        public qi::grammar<Iterator, value_element_vector(), skip_cmt_type > {

            typedef ObjectIdentifierValue_grammar self_type;
            typedef value_element_vector holder_type;

            ObjectIdentifierValue_grammar()
            : ObjectIdentifierValue_grammar::base_type(vect) {

                vect = qi::lit("{")
                        >> *(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)])
                        >> qi::lit("}");
            }

            void operator()(holder_type& holder, value_element & val) {
                holder.push_back(val);               
            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> vect;
            objNameId_grammar<Iterator> components;
        };

        extern ObjectIdentifierValue_grammar< std::string::iterator> ObjectIdentifierValue_;



        //Type

        template <typename Iterator>
        struct Type_grammar : qi::grammar<Iterator, type_element(), skip_cmt_type> {

            typedef Type_grammar self_type;
            typedef type_element holder_type;

            Type_grammar() :
            Type_grammar::base_type(start_rule) {

                start_rule = IntegerType_ | EnumeratedType_ | BitStringType_ | SympleTypeDecl_;

            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;

        };

        //extern Type_grammar<std::string::iterator> Type_;



        //extern syn_elements_sk_rule Types_;

        template <typename Iterator>
        struct Types_grammar : qi::grammar<Iterator, type_element_vector(), skip_cmt_type> {

            typedef Types_grammar self_type;
            typedef type_element_vector holder_type;

            Types_grammar() :
            Types_grammar::base_type(start_rule) {

                start_rule = *Type_;

            }

            qi::rule<Iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar<std::string::iterator> Type_;
        };

    }
}



#endif	

