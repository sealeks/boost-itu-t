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
#include <boost/spirit/repository/include/qi_distinct.hpp>

#include <boost/shared_ptr.hpp>




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
        t_ClassField,
        t_TypeFromObject,
        t_ValueSetFromObjects,
        t_Reference
    };

    enum definedclass_type {

        cl_SpecDef,
        cl_Reference,
        cl_TYPE_IDENTIFIER,
        cl_ABSTRACT_SYNTAX
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
        v_identifier_assignval, // x(y)             
        v_boolean, // TRUE, FALSE  /
        v_number, // n  /
        v_real, // n.n  /
        v_null, // NULL /
        v_bstring, // BitStringValue, OctetStringValue
        v_hstring, // BitStringValue, OctetStringValue
        v_cstring, // StringValue        
        v_identifier_list, // BitStringValue  { x, y ,....}  
        v_number_list, // Tuple, Quadruple  { x, y ,....}        
        v_named_list, // ObjectIdentifierSet  { x y(n1) n2....}             
        v_named_value, // name1 val1     
        v_namedvalue_list, // SetValue, SequenceValue,  { name1 val1, name2 val2 ....}   
        v_value_list, // SetOfValue, SequenceOfValue,  { {...} , {...}....}       
        v_choice, // SetOfValue, SequenceOfValue,  { {...} , {...}....}      
        v_open, // Type : Value        
        v_defined, // DefinedValue   
        v_ValueFromObject,
        v_extention,
        v_exception
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

    enum valueset_type {

        vs_Strait,
        vs_defined,
        vs_ValueSetFromObject
    };

    enum objectset_type {

        os_Strait,
        os_defined,
        os_ObjectSetFromObject
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

    enum fieldmarker_type {

        field_no,
        field_optional,
        field_defaulttype,
        field_defaultvalue,
        field_defaultset,
        field_defaultref,
        field_defaultoset,
        field_defaultovalue
    };

    enum setting_type {

        sett_NoDef,
        sett_Type,
        sett_Value,
        sett_ValueSet,
        sett_DefineClass,
        sett_Object,
        sett_ObjectSet
    };

    enum fieldkind_type {

        fkind_NoDef,
        fkind_TypeFieldSpec,
        fkind_FixedTypeValueFieldSpec,
        fkind_VariableTypeValueFieldSpec,
        fkind_FixedTypeValueSetFieldSpec,
        fkind_VariableTypeValueSetFieldSpec,
        fkind_ObjectFieldSpec,
        fkind_ObjectSetFieldSpec,
        fkind_FixedType_or_Object,
        fkind_FixedTypeSet_or_ObjectSet
    };

    enum objectfieldkind_type {

        ofk_NoDef,
        ofk_Type,
        ofk_Value,
        ofk_ValueSet,
        ofk_Object,
        ofk_ObjectSet,
        ofk_Value_or_ObjectSet,
        ofk_Value_or_Object
    };

    enum object_type {

        ot_Nodef,
        ot_Object,
        ot_Refference,
        ot_FromObject,
        ot_DefinedObjectSet,
        ot_ObjectSetFromObjects,
        ot_UNION,
        ot_INTERSECTION,
        ot_EXCEPT,
        ot_ALLEXCEPT,
        ot_EXTENTION

    };

    enum governor_type {

        gvr_No,
        gvr_Type,
        gvr_Class,
        gvr_Type_or_Class
    };

    enum parameter_type {

        prm_NoDef,
        prm_Type,
        prm_Class,
        prm_ValueSet,
        prm_ObjectSet,
        prm_Type_or_Class_or_Set,
        prm_Value,
        prm_Object,
        prm_Value_or_Object,
        prm_Reff
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

        struct classfield_type;
        typedef std::vector<classfield_type> classfield_vector;

        struct classsyntax_type;
        typedef std::vector<classsyntax_type> classsyntax_vector;

        struct objectfield_type;
        typedef std::vector<objectfield_type> objectfield_vector;

        struct object_element;
        typedef std::vector<object_element> object_element_vector;
        typedef boost::shared_ptr<object_element> object_element_ptr;

        struct objectset_element;
        typedef boost::shared_ptr<objectset_element> objectset_element_ptr;

        struct argument_type;
        typedef std::vector<argument_type> argument_vector;

        struct typevalue_element;
        typedef boost::shared_ptr<typevalue_element> typevalue_element_ptr;

        struct setting_element;
        typedef std::vector<setting_element> parameter_vector;

        using boost::spirit::repository::distinct;







        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  unknown_tc_element (Type or Class)
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct unknown_tc_element {

            std::string reff;
            parameter_vector parameters;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  unknown_tc_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct unknown_tc_assignment {

            std::string identifier;
            argument_vector arguments;
            unknown_tc_element unknown_tc;

        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  value_element
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct value_element {

            value_element() :
            type(v_nodef) {
            }

            value_element(bool v)
            : type(v_boolean), value(v ? "TRUE" : "FALSE") {
            }

            value_element(value_type t) : type(t) {
            }

            parameter_vector parameters;
            std::string identifier;
            std::string value;
            value_type type;
            value_element_vector values;
            typevalue_element_ptr typevalue;
            std::string fromreff;
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
            parameter_vector parameters;
            std::string reference;
            tagmarker_type marker;
            value_element value;
            defined_type builtin_t;
            value_element_vector predefined;
            named_type_element_vector elements;
            constraints_vector constraints;
        };






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





        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  value_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct value_assignment {

            value_assignment() : exact(false) {
            }

            std::string identifier;
            argument_vector arguments;
            type_element type;
            value_element value;
            bool exact;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  valueset_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct valueset_element {

            valueset_element() : tp(vs_Strait) {
            }

            parameter_vector parameters;
            valueset_type tp;
            std::string reference;
            constraint_element_vector set;
        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  valueset_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct valueset_assignment {

            valueset_assignment() : exact(false) {
            }

            std::string identifier;
            argument_vector arguments;
            type_element type;
            valueset_element set;
            bool exact;

        };





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
            argument_vector arguments;
            type_element type;

        };







        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  class_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

        struct classfield_type {

            classfield_type() : marker(field_no), tp(fkind_NoDef), unique(false) {
            }

            std::string field;
            std::string holder;
            type_element holdertype;
            fieldmarker_type marker;
            fieldkind_type tp;
            bool unique;
            type_element defaulttype;
            value_element defaultvalue;
            valueset_element defaultset;
            object_element_ptr defaultovalue;
            objectset_element_ptr defaultoset;
            std::string defaultreff;
        };

        struct classsyntax_type {

            classsyntax_type() : optional(false) {
            }

            std::string alias;
            std::string field;
            bool optional;
            classsyntax_vector group;
        };

        struct class_element {

            class_element() : tp(cl_SpecDef) {
            }

            class_element(definedclass_type t) : tp(t) {
            }

            definedclass_type tp;
            parameter_vector parameters;
            std::string reference;
            classfield_vector fields;
            classsyntax_vector syntaxes;
        };






        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  class_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

        struct class_assignment {

            std::string identifier;
            argument_vector arguments;
            class_element class_;
        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  setting_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct setting_element {

            setting_element() : tp(sett_NoDef) {
            }

            setting_type tp;
            value_element value;
            type_element type;
            valueset_element valueset;
            class_element class_;
            object_element_ptr object;
            objectset_element_ptr objectset;
        };






        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  object_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

        struct objectfield_type {

            objectfield_type() {
            }

            std::string field;
            setting_element setting;
        };

        struct object_element {

            object_element() : tp(ot_Nodef) {
            }

            object_element(object_type t) : tp(t) {
            }

            object_type tp;
            parameter_vector parameters;
            objectfield_vector fields;
            std::string reff;
            std::string raw;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  objectassigment_element
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct object_assignment {

            std::string identifier;
            argument_vector arguments;
            class_element class_;
            object_element object;
        };





        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  objectset_element
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////         

        struct objectset_element {

            objectset_element() : tp(os_Strait) {
            }

            parameter_vector parameters;
            objectset_type tp;
            std::string reference;
            object_element_vector set;
        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  objectset_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

        struct objectset_assignment {

            std::string identifier;
            argument_vector arguments;
            class_element class_;
            objectset_element set;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  typevalue_element
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct typevalue_element {

            type_element type;
            value_element value;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  argument_type
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct argument_type {

            argument_type() : tp(gvr_No) {
            }

            std::string governorreff;
            type_element governortype;
            class_element governorclass;
            governor_type tp;
            std::string argument;
        };









        // Assigment       

        typedef boost::variant<
        type_assignment,
        value_assignment,
        valueset_assignment,
        class_assignment,
        object_assignment,
        objectset_assignment,
        unknown_tc_assignment>
        assignment;

        typedef std::vector<assignment> assignment_vector;

        typedef std::vector<std::string> exports;

        struct import {

            std::string name;
            value_element oid;
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
            value_element oid;
            encoding_references_type encoding_references_t;
            tagrule_type default_tags_t;
            bool extesibility_implied;
            exports exports_;
            imports imports_;
            assignment_vector elements;
        };

    }
}






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
                        repository::confix("--", "--")[*(qi::char_ - ("--" | qi::eol))] |
                        repository::confix("--", qi::eol)[*(qi::char_ - qi::eol)]
                        ;
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

        typedef qi::rule<str_iterator, unsigned() > unum_rule;


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


        extern str_rule literal_except_token;
        extern str_rule word_;
        extern str_rule spaces_;
        extern str_rule Literal_;
        extern str_rule SyntaxField_;
        extern str_rule typereference_; //(=objectreference_, modulereference_ )
        extern str_rule typereference_strict; //(!=objectreference_, modulereference_ )
        extern str_rule identifier_; //(=objectsetreference,valuereference_ )
        extern str_rule valuereference_; //(=objectsetreference,identifier_ )
        extern str_rule valuesetreference_; //(=typereference_ )        
        extern str_rule modulereference_; //(=typereference_,objectreference)
        extern str_rule objectreference_; //(=typereference_,modulereference_)
        extern str_rule objectsetreference_; //(=valuereference_,identifier_)
        extern str_rule objectclassreference_; //(~typereference_)        
        extern str_rule typefieldreference_; //(&typereference_)   
        extern str_rule valuefieldreference_; //(&valuereference)        
        extern str_rule valuesetfieldreference_; //(&typereference_)               
        extern str_rule objectfieldreference_; //(&objectreference_)
        extern str_rule objectsetfieldreference_; //(&objectsetreference_)  
        extern str_rule bigreference_; //(typereference_ | objectfieldreference_)
        extern str_rule littlereference_; //(valuefieldreference_ | valuesetfieldreference_ |objectsetfieldreference_ )     
        extern str_rule bothreference_; //(valuefieldreference_ | valuesetfieldreference_ |objectsetfieldreference_ )        
        extern str_rule bigfieldreference_; //(typefieldreference_ | objectfieldreference_)
        extern str_rule littlefieldreference_; //(valuefieldreference_ | valuesetfieldreference_ |objectsetfieldreference_ )    
        extern str_rule PrimitiveFieldName_;
        extern str_rule FieldName_;


        extern str_rule ExternalTypeReference_;
        extern str_rule ExternalTypeReference_strict;
        extern str_rule DefinedType_;
        extern str_rule DefinedType_strict;
        extern str_rule ExternalValueReference_;
        extern str_rule DefinedValue_;
        extern str_rule ExternalValueSetReference_;
        extern str_rule DefinedValueSet_;
        extern str_rule ExternalObjectClassReference_;
        extern str_rule DefinedObjectClass_;
        extern str_rule UsefulObjectClass_;
        extern str_rule ExternalObjectReference_;
        extern str_rule DefinedObject_;
        extern str_rule ExternalObjectSetReference_;
        extern str_rule DefinedObjectSet_;
        extern str_rule ObjectClassFieldType_;
        extern str_rule SimpleTypeFromObject_;
        extern str_rule SimpleValueSetFromObjects_;

        /*??*/ extern str_rule UserDefinedConstraintParameter_;
        /*??*/ extern str_rule AtNotation_;




        extern str_rule Reference_;
        extern str_rule ParameterizedReference_; // x.683
        extern str_rule Symbol_;
        extern strvect_sk_rule SymbolList_;



    }
}



#endif	

