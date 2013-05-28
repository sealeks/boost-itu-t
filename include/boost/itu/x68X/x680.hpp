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
#include <boost/fusion/include/insert_range.hpp>
#include <boost/fusion/include/begin.hpp>
#include <boost/fusion/include/end.hpp>
#include <boost/fusion/include/push_back.hpp>

#include <boost/lambda/lambda.hpp>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/repository/include/qi_confix.hpp>
#include <boost/variant.hpp>




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
        t_DURATION,
        t_CHOICE,
        t_Selection,
        t_Instance_Of,
        t_Reference
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
        mk_exception,
    };

    enum constraintmarker_type {

        cmk_none,
        cmk_optional,
        cmk_absent,
        cmk_present,
        cmk_extention,
        cmk_exception
    };

    enum value_type {

        v_nodef,
        v_empty_set, // { }      
        v_identifier, // x
        v_identifier_assign, // x(n)     
        v_boolean, // TRUE, FALSE  /
        v_number, // n  /
        v_real, // n.n  /
        v_null, // NULL /
        v_bstring, // BitStringValue, OctetStringValue
        v_hstring, // BitStringValue, OctetStringValue
        v_cstring, // StringValue        
        v_identifier_list, // BitStringValue  { x, y ,....}  
        v_named_list, // ObjectIdentifierSet  { x y(n1) n2....}     
        v_named_value, // name1 val1     
        v_variable_list, // SetValue, SequenceValue,  { name1 val1, name2 val2 ....}   
        v_variables_list, // SetOfValue, SequenceOfValue,  { {...} , {...}....}       
        v_choice, // SetOfValue, SequenceOfValue,  { {...} , {...}....}      
        v_defined, // DefinedValue
        v_extention
    };

    enum constraint_type {

        cns_nodef,
        cns_SingleValue,
        cns_ContainedSubtype,
        cns_ValueRange,
        cns_PermittedAlphabet,
        cns_SizeConstraint,
        cns_TypeConstraint,
        cns_SingleTypeConstraint,
        cns_MultipleTypeConstraints,
        cns_NamedConstraint,
        cns_PatternConstraint,
        cns_PropertySettings,
        cns_DurationRange,
        cns_TimePointRange,
        cns_RecurrenceRange,
        cns_UserDefinedConstraint,
        cns_SimpleTableConstraint,
        cns_ComponentRelation,
        cns_ContentsType,
        cns_ContentsValue,
        cns_ContentsTypeValue,
        cns_UNION,
        cns_INTERSECTION,
        cns_EXCEPT,
        cns_ALLEXCEPT,
        cns_EXTENTION,
        cns_EXCEPTION
    };

    enum range_type {

        close_range,
        open_range,
        min_range,
        max_range
    };

    enum syntactic_type {

        s_NODEF,
        s_BuiltinType,
        s_SimpleValue
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
        rule(noset_tags),
        encoding(encoding_no) {
        }

        std::string number;
        tagclass_type class_;
        tagrule_type rule;
        encoding_references_type encoding;
    };

    inline void tag_rule(tag_type& holder, const tagrule_type& val) {
        holder.rule = val;
    }

    inline void tag_class(tag_type& holder, const tagclass_type& val) {
        holder.class_ = val;
    }

    inline void tag_encoding(tag_type& holder, const encoding_references_type& val) {
        holder.encoding = val;
    }

    inline void tag_number(tag_type& holder, const std::string& val) {
        holder.number = val;
    }

}


namespace x680 {

    namespace bnf {

        typedef std::vector<std::string> string_vector;
        typedef std::pair<std::string, std::string> string_pair;
        typedef std::vector<string_pair> string_pair_vector;

        struct type_assignment;
        typedef std::vector<type_assignment> type_assignment_vector;
        typedef type_assignment_vector named_type_element_vector;

        struct value_element;
        typedef std::vector<value_element> value_element_vector;

        struct constraint_element;
        typedef std::vector<constraint_element> constraint_element_vector;
        typedef std::vector<constraint_element_vector> constraints_vector;





        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  value_element
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct value_element {

            value_element() :
            type(v_nodef) {
            }

            std::string identifier;
            std::string value;
            value_type type;
            value_element_vector values;
        };









        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  type_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct type_element {

            type_element() :
            builtin_t(t_NODEF), marker(mk_none) {
            }

            bool tagged() const {
                return !tag.number.empty();
            }



            tag_type tag;
            std::string reference;
            tagmarker_type marker;
            value_element value;
            defined_type builtin_t;
            value_element_vector predefined;
            named_type_element_vector elements;
            constraints_vector constraints;
        };


        //  type_element setter        

        inline void type_deff(type_element& holder, const defined_type& type) {
            holder.builtin_t = type;
        }

        inline void type_refference(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_Reference;
        }

        inline void type_instance(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_Instance_Of;
        }

        inline void type_deffinit(type_element& holder, const value_element_vector & val) {
            holder.predefined = val;
        }

        inline void type_tag(type_element& holder, const tag_type& val) {
            holder.tag = val;
        }

        inline void type_tagged(type_element& holder, const tag_type& tg, const type_element& val) {
            holder = val;
            holder.tag = tg;
        }

        inline void type_pushs(type_element& holder, const type_assignment_vector& val) {
            holder.elements.insert(holder.elements.end(), val.begin(), val.end());
        }

        inline void type_constraints(type_element& holder, const constraints_vector& val) {
            holder.constraints= val;
        }




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  constraint_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct constraint_element {

            constraint_element() :
            tp(cns_nodef), marker(cmk_none),
            fromtype_(close_range), totype_(close_range) {
            }

            constraint_element(constraint_type t, constraintmarker_type m = cmk_none) :
            tp(t), marker(m),
            fromtype_(close_range),
            totype_(close_range) {
            }

            std::string identifier;
            constraint_type tp;
            value_element value;
            value_element from_;
            range_type fromtype_;
            value_element to_;
            range_type totype_;
            type_element type;
            constraintmarker_type marker;
            x680::bnf::string_vector parameters;
            std::string objsetref;
            constraint_element_vector constraint;
        };



        //  constraint_element setter

        inline void constraint_tp(constraint_element& holder, const constraint_type& val) {
            holder.tp = val;
        }

        inline void constraint_identifier(constraint_element& holder, const std::string& val) {
            holder.identifier = val;
            holder.tp = cns_NamedConstraint;
        }

        inline void constraint_singlevalue(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_SingleValue;
        }

        inline void constraint_subtype(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_ContainedSubtype;
        }

        inline void constraint_type(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_TypeConstraint;
        }

        inline void constraint_patterntype(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_PatternConstraint;
        }

        inline void constraint_property(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_PropertySettings;
        }

        inline void constraint_from(constraint_element& holder, const value_element& val) {
            holder.from_ = val;
        }

        inline void constraint_fromtype(constraint_element& holder, const range_type& val) {
            holder.fromtype_ = val;
        }

        inline void constraint_to(constraint_element& holder, const value_element& val) {
            holder.to_ = val;
            holder.tp = cns_ValueRange;
        }

        inline void constraint_totype(constraint_element& holder, const range_type& val) {
            holder.totype_ = val;
            holder.tp = cns_ValueRange;
        }

        inline void constraint_size(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_SizeConstraint;
        }

        inline void constraint_alphabet(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_PermittedAlphabet;
        }

        inline void constraint_singletype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_SingleTypeConstraint;
        }

        inline void constraint_namedtype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_NamedConstraint;
        }

        inline void constraint_marker(constraint_element& holder, const constraintmarker_type& val) {
            holder.marker = val;
        }

        inline void constraint_multitype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_MultipleTypeConstraints;
        }

        inline void constraint_userdef(constraint_element& holder, const string_vector& val) {
            holder.parameters = val;
            //holder.tp = cns_UserDefinedConstraint;
        }

        inline void constraint_relation(constraint_element& holder, const std::string& valr, const string_vector& valp) {
            holder.objsetref = valr;
            holder.parameters = valp;
            holder.tp = cns_ComponentRelation;
        }

        inline void constraint_content_t(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_ContentsType;
        }

        inline void constraint_content_v(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_ContentsValue;
        }

        inline void constraint_content_tv(constraint_element& holder, const type_element& valt, const value_element& valv) {
            holder.type = valt;
            holder.value = valv;
            holder.tp = cns_ContentsTypeValue;
        }

        inline void constraint_exceptnumber(constraint_element& holder, const std::string& val) {
            holder.type.value.type = v_number;
            holder.type.value.value = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        inline void constraint_exceptidentifier(constraint_element& holder, const std::string& val) {
            holder.type.value.type = v_identifier;
            holder.type.value.identifier = val;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        inline void constraint_excepttypevalue(constraint_element& holder, const type_element& valt, const value_element& valv) {
            holder.type = valt;
            holder.type.value = valv;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        inline void push_constraint(constraint_element_vector& holder, const constraint_element& val) {
            holder.push_back(val);
        }

        inline void push_constraints(constraint_element_vector& holder, const constraint_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }


        const constraint_element CONSTRAINT_UNION = constraint_element(cns_UNION);
        const constraint_element CONSTRAINT_INTERSECTION = constraint_element(cns_INTERSECTION);
        const constraint_element CONSTRAINT_EXCEPT = constraint_element(cns_EXCEPT);
        const constraint_element CONSTRAINT_ALLEXCEPT = constraint_element(cns_ALLEXCEPT);
        const constraint_element CONSTRAINT_EXTENTION = constraint_element(cns_EXTENTION, cmk_extention);







        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  value_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct value_assignment {

            value_assignment() {
            }

            std::string identifier;
            type_element type;
            value_element value;

        };


        //  value_assignment setter        

        inline void valuea_reference(value_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void valuea_type(value_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        inline void valuea_value(value_assignment& holder, const value_element& val) {
            holder.value = val;
        }



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  valueset_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct valueset_assignment {

            valueset_assignment() {
            }

            std::string identifier;
            type_element type;
            constraint_element_vector set;

        };
        
        
        
        //  valueset_assignment setter        
        
        inline void valueset_reference(valueset_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }
        
        inline void valueset_type(valueset_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        inline void valueset_set(valueset_assignment& holder, const constraint_element_vector& val) {
            holder.set = val;
        }


        
        



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  type_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct type_assignment {

            type_assignment() {
            }

            type_assignment(tagmarker_type mrkr) {
                type.marker = mrkr;
            }

            std::string identifier;
            type_element type;
            constraint_element_vector constraints;
        };


        //  type_assignment setter        

        inline void type_identifier(type_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void type_named(type_assignment& holder, const std::string& ind, const type_element& type) {
            holder.identifier = ind;
            holder.type = type;
        }

        inline void typea_type(type_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        inline void type_marker(type_assignment& holder, const tagmarker_type& val) {
            holder.type.marker = val;
        }

        inline void type_defaultvalue(type_assignment& holder, const value_element& val) {
            holder.type.marker = mk_default;
            holder.type.value = val;
        }

        inline void type_exceptnumber(type_assignment& holder, const std::string& val) {
            holder.type.value.type = v_number;
            holder.type.value.value = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
        }

        inline void type_exceptidetifier(type_assignment& holder, const std::string& val) {
            holder.type.value.type = v_identifier;
            holder.type.value.identifier = val;
            //holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
        }

        inline void type_exceptvalue(type_assignment& holder, const value_element& val) {
            holder.type.value = val;
            holder.type.marker = mk_exception;
        }

        inline void type_push(type_element& holder, const type_assignment& val) {
            holder.elements.push_back(val);
        }
        
        inline void type_select(type_element& holder, const std::string& ind, const type_element& type) {
            type_assignment tmp;
            tmp.identifier = ind;
            tmp.type = type;
            holder.elements.push_back(tmp);
            holder.builtin_t = t_Selection;
        }        


        const type_assignment extention_type_assignment(mk_extention);
        const type_assignment exception_type_assignment(mk_exception);




        // Assigment       

        typedef boost::variant<
        type_assignment,
        value_assignment,
        valueset_assignment>
        assignment;

        typedef std::vector<assignment> assignment_vector;


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
            assignment_vector elements;
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
        (x680::encoding_references_type, encoding)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::constraint_element,
        (std::string, identifier)
        (x680::constraint_type, tp)
        (x680::bnf::value_element, value)
        (x680::bnf::value_element, from_)
        (x680::range_type, fromtype_)
        (x680::bnf::value_element, to_)
        (x680::range_type, totype_)
        (x680::bnf::type_element, type)
        (x680::constraintmarker_type, marker)
        (x680::bnf::string_vector, parameters)
        (std::string, objsetref)
        (x680::bnf::constraint_element_vector, constraint)
        )



BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::value_element,
        (std::string, identifier)
        (std::string, value)
        (x680::value_type, type)
        (x680::bnf::value_element_vector, values)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::value_assignment,
        (std::string, identifier)
        (x680::bnf::type_element, type)
        (x680::bnf::value_element, value)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::valueset_assignment,
        (std::string, identifier)
        (x680::bnf::type_element, type)
        (x680::bnf::constraint_element_vector, set)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::type_element,
        (x680::tag_type, tag)
        (x680::tagmarker_type, marker)
        (x680::bnf::value_element, value)
        (std::string, reference)
        (x680::defined_type, builtin_t)
        (x680::bnf::named_type_element_vector, elements)
        (x680::bnf::value_element_vector, predefined)
        (x680::bnf::constraints_vector,  constraints)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::type_assignment,
        (std::string, identifier)
        (x680::bnf::type_element, type)
        (x680::bnf::constraint_element_vector, constraints)
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
        (x680::bnf::assignment_vector, elements)
        )






namespace x680 {
    namespace bnf {

        typedef std::string basic_character_type;
        typedef basic_character_type::iterator str_iterator;
        typedef basic_character_type::value_type str_value_type;

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

        typedef qi::rule<str_iterator, type_assignment_vector() > type_elements_rule;
        typedef qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type > type_elements_sk_rule;

        typedef qi::rule<str_iterator, value_element() > value_element_rule;
        typedef qi::rule<str_iterator, value_element(), skip_cmt_type > value_element_sk_rule;

        typedef qi::rule<str_iterator, value_element_vector() > value_elements_rule;
        typedef qi::rule<str_iterator, value_element_vector(), skip_cmt_type > value_elements_sk_rule;

        //typedef qi::rule<str_iterator, type_assignment_vector() > syn_elements_rule;
        //typedef qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type > syn_elements_sk_rule;

        typedef qi::rule<str_iterator, unsigned() > unum_rule;


        extern str_rule comment_beg;
        extern str_rule comment_end;
        extern str_rule pos_number_str;
        extern str_rule number_str;
        extern str_rule realnumber_str;
        extern str_rule bstring_str;
        extern str_rule hstring_str;
        extern str_rule cstring_str;
        extern str_rule curly_barket_pair;

        extern term_rule ECODED_;
        extern term_rule INTERSECTION_;
        extern term_rule SEQUENCE_;
        extern term_rule ABSTRACT_SYNTAX_;
        extern term_rule ABSENT_;
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
        extern term_rule ENCODED_;
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
        extern str_rule ExternalObjectClassReference_;
        extern str_rule DefinedObjectClass_;
        extern str_rule ExternalObjectSetReference;
        extern str_rule DefinedObjectSet_;
        /*??*/ extern str_rule UserDefinedConstraintParameter_;
        /*??*/ extern str_rule AtNotation_;


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

