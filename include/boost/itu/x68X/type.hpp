//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680TYPEPARSER_H_
#define         _ITU_X680TYPEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace bnf {

        template <typename Iterator>
        struct Type : qi::grammar<Iterator, syntax_element() , skip_cmt_type> {

            struct check_type_simple : qi::symbols<std::string::value_type, defined_type > {

                check_type_simple() {
                    add
                            ("BOOLEAN", t_BOOLEAN)
                            ("INTEGER", t_INTEGER)
                            ("NULL", t_NULL)
                            ("EXTERNAL", t_EXTERNAL)
                            ("REAL", t_REAL)
                            ("ENUMERATED", t_ENUMERATED)
                            ("UTCTime", t_UTCTime)
                            ("GeneralizedTime", t_GeneralizedTime)
                            ("TIME", t_TIME)
                            ("DATE", t_DATE)
                            ("CHOICE", t_CHOICE)
                            ;
                }
            };
            
            
             struct check_type_simple2 : qi::symbols<std::string::value_type, defined_type > {           
                 check_type_simple2() {
                    add
                            ("BIT", t_BIT_STRING)
                            ("OCTET", t_OCTET_STRING)
                            ("OBJECT IDENTIFIER", t_OBJECT_IDENTIFIER)
                            ("Object Descriptor", t_Object_Descriptor)
                            ("EMBEDDED PDV", t_EMBEDDED_PDV)
                            ("RELATIVE OID", t_RELATIVE_OID)
                            ("TIME OF DAY", t_TIME_OF_DAY)
                            ("DATE TIME", t_DATE_TIME)
                            ;
                }
            };           
            
            struct check_type_string : qi::symbols<std::string::value_type, defined_type > {

                check_type_string() {
                    add

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
                            ("CHARACTER STRING", t_CHARACTER_STRING)
                            ("BMPString", t_BMPString)
                            ;
                }
            };

            struct check_type_struct : qi::symbols<std::string::value_type, defined_type > {

                check_type_struct() {
                    add

                            ("SEQUENCE", t_SEQUENCE)
                            ("SET", t_SET)
                            ;
                }
            };





            /*              struct check_type1 : qi::symbols<std::string::value_type, defined_type > {
             * check_type1() {
          add
                              ("BOOLEAN", t_BOOLEAN)
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
                              ("CHOICE", t_CHOICE)
                  ;
      }
  };*/

            Type() : Type::base_type(start_rule) {


                start_rule = *qi::space >> typereference_[bind(&Type::identificator, *this, qi::_val, qi::_1)]
                        >> *qi::space >> "::=" >> *qi::space >> simple_typer[bind(&Type::type, *this, qi::_val, qi::_1)];


            }

            void identificator(syntax_element& holder, const std::string & val) {
                holder.identifier = val;
            }

            void type(syntax_element& holder, const defined_type & tp) {
                holder.builtin_t = tp;
            }


            qi::rule<Iterator, syntax_element() > start_rule;
            check_type_struct struct_typer;
            check_type_simple simple_typer;
            check_type_simple2 simple_typer2;            
            check_type_string string_typer;


        };

    }
}



#endif	

