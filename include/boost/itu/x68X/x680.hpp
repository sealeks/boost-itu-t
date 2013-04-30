//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680IMPLEMENTATIUON_H_
#define	_ITU_X680IMPLEMENTATIUON_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include <boost/config/warning_disable.hpp>

#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/std_pair.hpp>

#include <boost/lambda/lambda.hpp>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/repository/include/qi_confix.hpp>





namespace x680 {

    enum defined_type {

        t_NODEF,
        t_BOOLEAN,
        t_INTEGER,
        t_BIT_STRING,
        t_OCTET_STRING,
        t_NULL,
        t_OBJECT_IDENTIFIER,
        t_ObjectDescriptor,
        t_EXTERNAL,
        t_REAL,
        t_ENUMERATED,
        t_EMBEDDED_PDV,
        t_UTF8String,
        t_RELATIVE_OID,
        t_SEQUENCE,
        t_SEQUENCE_OF,
        t_SET,
        t_SET_OF,
        t_NumericString,
        t_PrintableString,
        t_T61String,
        t_VideotexString,
        t_IA5String,
        t_UTCTime,
        t_GeneralizedTime,
        t_GraphicString,
        t_VisibleString,
        t_GeneralString,
        t_UniversalString,
        t_CHARACTER_STRING,
        t_BMPString,
        t_TIME,
        t_TIME_OF_DAY,
        t_DATE,
        t_DATE_TIME,
        t_CHOICE
    };

    enum tagclass_type {

        tcl_universal,
        tcl_application,
        tcl_private,
        tcl_context

    };

    enum tagrule_type {

        noset_tags,
        explicit_tags,
        implicit_tags,
        automatic_tags
    };

    enum tagmarker_type {

        mk_none,
        mk_default,
        mk_optional,
        mk_components_of,      
        mk_extention, 
        mk_exception                
    };

    enum value_type {

        v_nodef,
        v_identifier,
        v_boolean,
        v_number,
        v_real,
        v_null,
        v_binary,
        v_hexnum,
        v_octnum,
        v_array,
        v_struct,
        v_extention
    };

    enum syntactic_type {

        s_NODEF,
        s_BuiltinType,
        s_BuiltinValue
    };

    enum encoding_references_type {

        encoding_no,
        encoding_tag,
        encoding_xer,
        encoding_per
    };

    struct tag_type {

        tag_type() :
        class_(tcl_context),
        rule(noset_tags) {
        }

        std::string number;
        tagclass_type class_;
        tagrule_type rule;
    };

}


namespace x680 {

    namespace bnf {

        typedef std::vector<std::string> string_vector;
        typedef std::pair<std::string, std::string> string_pair;
        typedef std::vector<string_pair> string_pair_vector;

        struct type_assigment;
        typedef std::vector<type_assigment> type_assigment_vector;
        typedef type_assigment_vector  named_type_element_vector;

        struct value_element;
        typedef std::vector<value_element> value_element_vector;

        struct value_element {

            value_element() :
            type(v_nodef) {
            }

            std::string identifier;
            std::string value;
            value_type type;
            value_element_vector values;
        };


        // Type

        struct type_element {

            type_element() :
            builtin_t(t_NODEF) {
            }

            bool tagged() const {
                return !tag.number.empty();
            }



            tag_type tag;
            std::string reference;
            defined_type builtin_t;
            value_element_vector predefined;
            named_type_element_vector elements;
        };
        
        
        


        struct type_assigment {

            type_assigment() : marker(mk_none) {
            }

            type_assigment(tagmarker_type mrkr) : marker(mrkr) {
            }
            
            void operator()(const tagmarker_type& val){
                marker = val;
            }
            
            std::string identifier;
            type_element type;
            tagmarker_type marker;
        };

        const type_assigment extention_type_assigment(mk_extention);
        const type_assigment exception_type_assigment(mk_exception);                

        typedef std::vector<std::string> exports;

        struct import {

            std::string name;
            value_element_vector oid;
            string_vector names;
        };

        typedef std::vector<import> imports;

        struct module {

            module() :
            encoding_references_t(encoding_no),
            default_tags_t(explicit_tags),
            extesibility_implied(false) {
            }

            std::string name;
            value_element_vector oid;
            encoding_references_type encoding_references_t;
            tagrule_type default_tags_t;
            bool extesibility_implied;
            exports exports_;
            imports imports_;
            type_assigment_vector elements;
        };

    }
}




BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::string_pair_vector,
        (std::vector<x680::bnf::string_pair>, first)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::tag_type,
        (std::string, number)
        (x680::tagclass_type, class_)
        (x680::tagrule_type, rule)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::value_element,
        (std::string, identifier)
        (std::string, value)
        (x680::value_type, type)
        (x680::bnf::value_element_vector, values)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::type_element,
        (x680::tag_type, tag)
        (std::string, reference)
        (x680::defined_type, builtin_t)
        (x680::bnf::named_type_element_vector, elements)
        (x680::bnf::value_element_vector, predefined)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::type_assigment,
        (std::string, identifier)
        (x680::bnf::type_element, type)
        (x680::tagmarker_type, marker)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::import,
        (std::string, name)
        (x680::bnf::value_element_vector, oid)
        (x680::bnf::string_vector, names)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::module,
        (std::string, name)
        (x680::bnf::value_element_vector, oid)
        (x680::encoding_references_type, encoding_references_t)
        (x680::tagrule_type, default_tags_t)
        (bool, extesibility_implied)
        (x680::bnf::exports, exports_)
        (x680::bnf::imports, imports_)
        (x680::bnf::type_assigment_vector, elements)
        )






namespace x680 {
    namespace bnf {
        
        typedef  std::string basic_character_type;
        typedef  basic_character_type::iterator str_iterator;
        typedef  basic_character_type::value_type str_value_type;
        
        using namespace boost::spirit;

        using boost::phoenix::bind;

        namespace ascii = boost::spirit::ascii;
        namespace repository = boost::spirit::repository;

        struct skip_comment_grammar : public qi::grammar<str_iterator> {

            skip_comment_grammar()
            : skip_comment_grammar::base_type(skip) {
                skip
                        = qi::space |
                        repository::confix("/*", "*/")[*(qi::char_ - "*/")] |
                        repository::confix("--", qi::eol)[*(qi::char_ - qi::eol)] |
                        repository::confix("--", "--")[*(qi::char_ - "--")];
                ;
            }
            qi::rule<str_iterator> skip;
        };

        typedef skip_comment_grammar skip_cmt_type;

        extern skip_cmt_type comment_skip;

        typedef qi::rule<str_iterator> term_rule;

        typedef qi::rule<str_iterator, std::string() > str_rule;
        typedef qi::rule<str_iterator, std::string(), skip_cmt_type > str_sk_rule;

        typedef qi::rule<str_iterator, string_vector() > strvect_rule;
        typedef qi::rule<str_iterator, string_vector(), skip_cmt_type > strvect_sk_rule;

        typedef qi::rule<str_iterator, string_pair() > strpair_rule;
        typedef qi::rule<str_iterator, string_pair(), skip_cmt_type > strpair_sk_rule;

        typedef qi::rule<str_iterator, string_pair_vector() > strpairs_rule;
        typedef qi::rule<str_iterator, string_pair_vector(), skip_cmt_type > strpairs_sk_rule;

        typedef qi::rule<str_iterator, imports() > imports_rule;
        typedef qi::rule<str_iterator, imports(), skip_cmt_type > imports_sk_rule;

        typedef qi::rule<str_iterator, type_element() > type_element_rule;
        typedef qi::rule<str_iterator, type_element(), skip_cmt_type > type_element_sk_rule;

        typedef qi::rule<str_iterator, type_assigment_vector() > type_elements_rule;
        typedef qi::rule<str_iterator, type_assigment_vector(), skip_cmt_type > type_elements_sk_rule;

        typedef qi::rule<str_iterator, value_element() > value_element_rule;
        typedef qi::rule<str_iterator, value_element(), skip_cmt_type > value_element_sk_rule;

        typedef qi::rule<str_iterator, value_element_vector() > value_elements_rule;
        typedef qi::rule<str_iterator, value_element_vector(), skip_cmt_type > value_elements_sk_rule;

        //typedef qi::rule<str_iterator, type_assigment_vector() > syn_elements_rule;
        //typedef qi::rule<str_iterator, type_assigment_vector(), skip_cmt_type > syn_elements_sk_rule;

        typedef qi::rule<str_iterator, unsigned() > unum_rule;


        extern str_rule comment_beg;
        extern str_rule comment_end;
        extern str_rule pos_number_str;
        extern str_rule number_str;
        extern str_rule realnumber_str;
        extern str_rule curly_barket_pair;

        extern term_rule ECODED_;
        extern term_rule INTERSECTION_;
        extern term_rule SEQUENCE_;
        extern term_rule ABSTRACT_SYNTAX_;
        extern term_rule ENCODING_CONTROL_;
        extern term_rule ISO646String_;
        extern term_rule SET_;
        extern term_rule ALL_;
        extern term_rule END_;
        extern term_rule MAX_;
        extern term_rule SETTINGS_;
        extern term_rule APPLICATION_;
        extern term_rule ENUMERATED_;
        extern term_rule MIN_;
        extern term_rule SIZE_;
        extern term_rule AUTOMATIC_;
        extern term_rule EXCEPT_;
        extern term_rule MINUS_INFINITY_;
        extern term_rule STRING_;
        extern term_rule BEGIN_;
        extern term_rule EXPLICIT_;
        extern term_rule NOT_A_NUMBER_;
        extern term_rule SYNTAX_;
        extern term_rule BIT_;
        extern term_rule EXPORTS_;
        extern term_rule NULL_;
        extern term_rule T61String_;
        extern term_rule BMPString_;
        extern term_rule EXTENSIBILITY_;
        extern term_rule NumericString_;
        extern term_rule TAGS_;
        extern term_rule BOOLEAN_;
        extern term_rule EXTERNAL_;
        extern term_rule OBJECT_;
        extern term_rule TeletexString_;
        extern term_rule BY_;
        extern term_rule FALSE_;
        extern term_rule ObjectDescriptor_;
        extern term_rule TIME_;
        extern term_rule CHARACTER_;
        extern term_rule FROM_;
        extern term_rule OCTET_;
        extern term_rule TIME_OF_DAY_;
        extern term_rule CHOICE_;
        extern term_rule GeneralizedTime_;
        extern term_rule OF_;
        extern term_rule TRUE_;
        extern term_rule CLASS_;
        extern term_rule GeneralString_;
        extern term_rule OID_IRI_;
        extern term_rule TYPE_IDENTIFIER_;
        extern term_rule COMPONENT_;
        extern term_rule GraphicString_;
        extern term_rule OPTIONAL_;
        extern term_rule UNION_;
        extern term_rule COMPONENTS_;
        extern term_rule IA5String_;
        extern term_rule PATTERN_;
        extern term_rule UNIQUE_;
        extern term_rule CONSTRAINED_;
        extern term_rule IDENTIFIER_;
        extern term_rule PDV_;
        extern term_rule UNIVERSAL_;
        extern term_rule CONTAINING_;
        extern term_rule IMPLICIT_;
        extern term_rule PLUS_INFINITY_;
        extern term_rule UniversalString_;
        extern term_rule DATE_;
        extern term_rule IMPLIED_;
        extern term_rule PRESENT_;
        extern term_rule UTCTime_;
        extern term_rule DATE_TIME_;
        extern term_rule IMPORTS_;
        extern term_rule PrintableString_;
        extern term_rule UTF8String_;
        extern term_rule DEFAULT_;
        extern term_rule INCLUDES_;
        extern term_rule PRIVATE_;
        extern term_rule VideotexString_;
        extern term_rule DEFINITIONS_;
        extern term_rule INSTANCE_;
        extern term_rule REAL_;
        extern term_rule VisibleString_;
        extern term_rule DURATION_;
        extern term_rule INSTRUCTIONS_;
        extern term_rule RELATIVE_OID_;
        extern term_rule WITH_;
        extern term_rule EMBEDDED_;
        extern term_rule INTEGER_;
        extern term_rule RELATIVE_OID_IRI_;
        extern term_rule EXTENSIBILITY_IMPLIED_;



        extern str_rule typereference_; //(=objectreference_, modulereference_ )
        extern str_rule identifier_; //(=objectsetreference,valuereference_ )
        extern str_rule valuereference_; //(=objectsetreference,identifier_ )
        extern str_rule modulereference_; //(=typereference_,objectreference)
        extern str_rule objectreference_; //(=typereference_,modulereference_)
        extern str_rule objectsetreference_; //(=valuereference_,identifier_)
        extern str_rule objectclassreference_; //(~typereference_)        
        extern str_rule comment_;
        extern str_rule ExternalTypeReference_;
        extern str_rule DefinedType_;
        extern str_rule Externalvaluereference_;
        extern str_rule DefinedValue_;


        extern unum_rule number;
        extern unum_rule bstring;
        extern unum_rule hstring;

        extern str_rule cstring;


        extern str_rule Reference_;
        extern str_rule ParameterizedReference_; // x.683
        extern str_rule Symbol_;
        extern strvect_sk_rule SymbolList_;



        //extern strpair_rule ObjNameValComponent;

        /*      DefinedType ::=
              ExternalTypeReference
              | typereference
              | ParameterizedType
              | ParameterizedValueSetType
   
              ExternalTypereference : : =
              modulereference
              "."
              typereference
   
              ParameterizedType ::=
              !!!!SimpleDefinedType
              ActualParameterList
  
               !!!!SimpleDefinedType ::=
              ExternalTypeReference |
              typereference
   
   
               ParameterizedValueSetType ::=
              !!!SimpleDefinedType
              !!!ActualParameterList

   
   
              ActualParameterList ::=
              "{" ActualParameter "," + "}"
  
              ActualParameter ::=
              Type
              | Value
              | ValueSet
              | DefinedObjectClass
              | Object
              | ObjectSet
   
         */





    }
}



#endif	

