//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680IMPLEMENTATIUON_H_
#define	_ITU_X680IMPLEMENTATIUON_H_


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include  <iterator>


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
#include <boost/spirit/repository/include/qi_distinct.hpp>

#include <boost/spirit/include/support_multi_pass.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include <boost/variant.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

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
        t_RELATIVE_OID_IRI,
        t_OID_IRI,
        t_ANY,
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

        tcl_universal = 0,
        tcl_application = 1,
        tcl_context = 2,
        tcl_private = 3

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
        mk_group_beg,
        mk_group_end,
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
        v_empty, // { }      
        v_defined, // x  // DefinedValue
        v_defined_assign, // x(n)     
        //v_defined_assignval, // x(y)             
        v_boolean, // TRUE, FALSE  /
        v_number, // n  /
        v_real, // n.n  /
        v_null, // NULL /
        v_bstring, // BitStringValue, OctetStringValue
        v_hstring, // BitStringValue, OctetStringValue
        v_cstring, // StringValue        
        v_defined_list, // BitStringValue  { x, y ,....}  
        v_number_list, // Tuple, Quadruple  { x, y ,....}        
        v_objectid, // ObjectIdentifierSet  { x y(n1) n2....}             
        v_named_value, // name1 val1     
        v_struct, // SetValue, SequenceValue,  { name1 val1, name2 val2 ....}   
        v_value_list, // SetOfValue, SequenceOfValue,  { {...} , {...}....}       
        v_choice, // SetOfValue, SequenceOfValue,  { {...} , {...}....}      
        v_open, // Type : Value     
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
        cns_Contents,
        cns_ValueSet,
        cns_ValueSetFromObjects,
        cns_ValueSetFromObject,
        cns_Undef_T_ST_VS,
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
        vs_ValueSetFromObjects,
        vs_ValueSetFromObject
    };

    enum objectset_type {

        os_Strait,
        os_defined,
        os_ObjectSetFromObjects,
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
        field_defaultoset,
        field_defaultovalue,
        field_defaultov,
        field_defaultos
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

    enum object_type {

        ot_Nodef,
        ot_Object,
        ot_ObjectDefineSyn,
        ot_Refference,
        ot_FromObject,
        ot_DefinedObjectSet,
        ot_ObjectSetFromObjects,
        ot_ObjectSetFromObject,
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

    enum argumentsize_type {

        argm_No,
        argm_Big,
        argm_Little
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


    typedef int alternmask;

    const alternmask AS_NODEF = 0x0;
    const alternmask AS_VALUE = 0x1;
    const alternmask AS_OBJECT = 0x2;
    const alternmask AS_VALUESET = 0x4;
    const alternmask AS_OBJECTSET = 0x8;
    const alternmask AS_TYPE = 0x10;
    const alternmask AS_CLASS = 0x20;
    const alternmask AS_LITERAL = 0x40;


    namespace syntactic {



        typedef std::vector<std::string> string_vector;
        typedef std::pair<std::string, std::string> string_pair;
        typedef std::vector<string_pair> string_pair_vector;

        struct type_assignment;
        typedef boost::shared_ptr<type_assignment> type_assignment_ptr;
        typedef std::vector<type_assignment> type_assignment_vector;
        typedef type_assignment_vector named_type_element_vector;

        struct value_assignment;
        typedef boost::shared_ptr<value_assignment> value_assignment_ptr;

        struct valueset_assignment;
        typedef boost::shared_ptr<valueset_assignment> valueset_assignment_ptr;

        struct class_assignment;
        typedef boost::shared_ptr<class_assignment> class_assignment_ptr;

        struct object_assignment;
        typedef boost::shared_ptr<object_assignment> object_assignment_ptr;

        struct objectset_assignment;
        typedef boost::shared_ptr<objectset_assignment> objectset_assignment_ptr;

        struct type_element;
        typedef boost::shared_ptr<type_element> type_element_ptr;

        struct class_element;
        typedef boost::shared_ptr<class_element> class_element_ptr;

        struct value_element;
        typedef std::vector<value_element> value_element_vector;
        typedef boost::shared_ptr<value_element> value_element_ptr;

        struct valueset_element;
        typedef boost::shared_ptr<valueset_element> valueset_element_ptr;

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

        struct uargument_type;
        typedef std::vector<uargument_type> uargument_vector;

        struct typevalue_element;
        typedef boost::shared_ptr<typevalue_element> typevalue_element_ptr;

        struct setting_element;
        typedef std::vector<setting_element> parameter_vector;
        typedef boost::shared_ptr<setting_element> setting_element_ptr;

        struct module;
        typedef std::vector<module> modules;

        using boost::spirit::repository::distinct;




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  tag_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

            unknown_tc_assignment() : alternative_(0) {
            }

            std::string identifier;
            argument_vector arguments;
            unknown_tc_element unknown_tc;
            type_assignment_ptr typea;
            class_assignment_ptr classa;
            alternmask alternative_;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  unknown_vo_element (Value or Object)
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct unknown_vo_element {

            unknown_vo_element() : alternative_(0) {
            };

            std::string reff;
            value_element_ptr value_;
            object_element_ptr object_;
            parameter_vector parameters;
            alternmask alternative_;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  unknown_tc_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct unknown_vo_assignment {

            unknown_vo_assignment() : alternative_(0) {
            }

            std::string identifier;
            std::string reff;
            value_assignment_ptr valuea;
            object_assignment_ptr objecta;
            alternmask alternative_;
        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  unknown_vo_element (ValueSet or ObjectSet)
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct unknown_so_element {

            unknown_so_element() : alternative_(0) {
            };

            valueset_element_ptr valueset_;
            objectset_element_ptr objectset_;
            parameter_vector parameters;
            alternmask alternative_;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  unknown_tc_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct unknown_so_assignment {

            unknown_so_assignment() : alternative_(0) {
            }

            std::string identifier;
            std::string reff;
            valueset_assignment_ptr valueseta;
            objectset_assignment_ptr objectseta;
            alternmask alternative_;

        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  value_element
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct value_element {

            value_element() :
            type(v_nodef) {
            }

            value_element(bool v)
            : value(v ? "TRUE" : "FALSE"), type(v_boolean) {
            }

            value_element(value_type t) : type(t) {
            }

            parameter_vector parameters;
            std::string value;
            std::string identifier;
            value_type type;
            value_element_vector values;
            typevalue_element_ptr typevalue;
            std::string fromreff;
            object_element_ptr objectref;
            std::string fieldreference;
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
            defined_type builtin_t;
            tagmarker_type marker;
            value_element value;
            value_element_vector predefined;
            named_type_element_vector elements;
            constraints_vector constraints;
            std::string fieldreference;
            object_element_ptr objectref;
            objectset_element_ptr objectsetref;
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
            string_vector parameters;
            uargument_vector uparameters;
            constraint_type tp;
            constraintmarker_type marker;
            value_element value;
            value_element from_;
            range_type fromtype_;
            value_element to_;
            range_type totype_;
            type_element type;
            std::string objsetref;
            constraint_element_vector constraint;
            std::string fieldreference;
            object_element_ptr objectref;
            objectset_element_ptr objectsetref;
            setting_element_ptr setting;

        };





        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  value_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct value_assignment {

            value_assignment() {
            }

            std::string identifier;
            argument_vector arguments;
            type_element type;
            value_element value;

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
            std::string fieldreference;
            object_element_ptr objectref;
            objectset_element_ptr objectsetref;
        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  valueset_assignment
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct valueset_assignment {

            valueset_assignment() {
            }

            std::string identifier;
            argument_vector arguments;
            type_element type;
            valueset_element set;

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
            class_element_ptr holderclass;
            fieldmarker_type marker;
            fieldkind_type tp;
            bool unique;
            type_element defaulttype;
            value_element defaultvalue;
            valueset_element defaultset;
            object_element_ptr defaultovalue;
            objectset_element_ptr defaultoset;
            unknown_vo_element defvalobj;
            unknown_so_element defvalobjset;
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

            setting_element() : alternative(0) {
            }

            type_element_ptr type;
            class_element_ptr class_;
            value_element_ptr value;
            object_element_ptr object;
            valueset_element_ptr valueset;
            objectset_element_ptr objectset;
            std::string literal;
            alternmask alternative;
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
            object_element_ptr objectref;
            objectset_element_ptr objectsetref;
            std::string fieldreference;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  objectassignment_element
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
            std::string fieldreference;
            object_element_ptr objectref;
            objectset_element_ptr objectsetref;
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

            argument_type() : tp(gvr_No), atp(argm_No) {
            }

            std::string reff;
            type_element governortype;
            class_element governorclass;
            governor_type tp;
            argumentsize_type atp;
            std::string argument;

        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //  argument_type
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        struct uargument_type {

            uargument_type() : tp(gvr_No) {
            }

            std::string reff;
            type_element governortype;
            class_element governorclass;
            governor_type tp;
            setting_element parameter;


        };








        // Assigment       

        typedef boost::variant<
        type_assignment,
        value_assignment,
        valueset_assignment,
        class_assignment,
        object_assignment,
        objectset_assignment,
        unknown_tc_assignment,
        unknown_vo_assignment,
        unknown_so_assignment>
        assignment;

        typedef std::vector<assignment> assignment_vector;

        typedef std::vector<std::string> exports;

        struct import {

            std::string name;
            value_element oid;
            value_element defined;
            string_vector names;
        };

        typedef std::vector<import> imports;

        struct module {

            module() :
            encoding_references_t(encoding_no),
            default_tags_t(explicit_tags),
            extesibility_implied(false),
            allexport(false) {
            }

            std::string name;
            value_element oid;
            std::string iri;
            encoding_references_type encoding_references_t;
            tagrule_type default_tags_t;
            bool extesibility_implied;
            exports exports_;
            imports imports_;
            assignment_vector elements;
            bool allexport;
            std::string file;
        };

    }
}






namespace x680 {
    namespace syntactic {

        const int PARSE_SUCCESS = 0;
        const int PARSE_EFILESTREAM = 1;
        const int PARSE_ESYNXTAS = 3;

        class position_iterator : public std::string::iterator {

        public:

            typedef std::string::iterator supertype;
            typedef boost::shared_ptr<supertype> supertypeptr;
            typedef boost::shared_ptr<difference_type> differenceptr;

            position_iterator(const supertype& s);

            position_iterator&
            operator++();

            position_iterator
            operator++(int);

            position_iterator&
            operator--();

            position_iterator
            operator--(int);

#ifdef __GNUC__                

            position_iterator&
                    operator+=(const difference_type& n);

            position_iterator
            operator+(const difference_type& n) const;

            position_iterator&
                    operator-=(const difference_type& n);

            position_iterator
            operator-(const difference_type& n) const;

#endif            

            difference_type pos() const;

            supertype& super() const;

            supertype& base() const;

        private:

            void checkpos() const;

            position_iterator private_ctr(const supertype& s, supertypeptr b, differenceptr p) const;

            mutable supertypeptr base_;
            mutable differenceptr pos_;
        };

        class synxtas_error {

        public:


            synxtas_error(const std::string& file, const std::string& src, std::size_t pos);

            std::size_t filepos() const {
                return filepos_;
            };

            std::size_t linepos() const {
                return linepos_;
            };

            std::size_t linenum() const {
                return linenum_;
            };

            std::string line() const {
                return line_;
            };

            std::string file() const {
                return file_;
            };


        private:

            std::size_t build(const std::string& src, std::size_t pos, std::size_t& symb, std::string& line);

            std::size_t filepos_;
            std::size_t linepos_;
            std::size_t linenum_;
            std::string line_;
            std::string file_;
        };

        std::ostream& operator<<(std::ostream& stream, const synxtas_error& self);


        typedef position_iterator str_iterator;

        using namespace boost::spirit;

        using boost::phoenix::bind;

        namespace ascii = boost::spirit::ascii;
        namespace repository = boost::spirit::repository;
        namespace sprt = boost::spirit;
        namespace phx = boost::phoenix;

        struct skip_comment_grammar : public qi::grammar<str_iterator> {

            skip_comment_grammar()
            : skip_comment_grammar::base_type(skip) {
                skip
                        = qi::space |
                        repository::confix("/*", "*/")[*(qi::char_ - "*/")] |
                        repository::confix("--", "--")[*(qi::char_ - ("--" | qi::eol | qi::eoi))] |
                        repository::confix("--", (qi::eol | qi::eoi))[*(qi::char_ - (qi::eol | qi::eoi))]
                        ;
                ;
            }
            qi::rule<str_iterator> skip;
        };



        typedef skip_comment_grammar skip_cmt_type;

        //extern skip_cmt_type comment_skip;
        static skip_comment_grammar comment_skip;

        typedef qi::rule<str_iterator> term_rule;

        typedef qi::rule<str_iterator, std::string() > str_rule;

        typedef qi::rule<str_iterator, string_vector() > strvect_rule;
        //typedef qi::rule<str_iterator, string_vector(), skip_cmt_type > strvect_sk_rule;


       static  str_rule pos_number_str = distinct(qi::alnum | ('-' >> qi::alnum))[qi::char_("0")[ sprt::_val = sprt::_1 ]
                | (qi::char_("1-9")[ sprt::_val = sprt::_1]
                >> *(qi::char_("0-9")[ sprt::_val += sprt::_1]))];

       static  str_rule pos_onumber_str = distinct(qi::alnum | ('-' >> qi::alnum))[ (qi::char_("0-9")[ sprt::_val = sprt::_1]
                >> *(qi::char_("0-9")[ sprt::_val += sprt::_1]))];

       static  str_rule number_str = distinct(qi::alnum | ('-' >> qi::alnum))[(qi::string("-")[ sprt::_val = sprt::_1 ]
                >> qi::omit[*qi::blank]
                >> pos_number_str[ sprt::_val += sprt::_1 ])
        | pos_number_str[ sprt::_val = sprt::_1 ]];

       static  str_rule realnumber_str = distinct(qi::alnum | ('-' >> qi::alnum))[number_str[ sprt::_val = sprt::_1 ]
                >> (qi::string(".")[ sprt::_val += sprt::_1 ] >> pos_onumber_str[ sprt::_val += sprt::_1 ])];

       static  str_rule bstring_str = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::omit[qi::char_("'")]
        >> *(qi::char_("0-1")[ sprt::_val += sprt::_1] | qi::omit[qi::space])
        >> qi::omit[ qi::char_("'")
        >> qi::char_("B")]];

       static  str_rule hstring_str = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::omit[qi::char_("'")]
        >> *(qi::char_("0-9ABCDEF")[ sprt::_val += sprt::_1] | qi::omit[qi::space])
        >> qi::omit[ qi::char_("'")
        >> qi::char_("H")]];

       static  str_rule cstring_str = /*distinct(qi::alnum | ('-' >> qi::alnum))[*/ qi::char_("\"")
        >> *(qi::char_[ sprt::_val += sprt::_1] - qi::char_("\""))
        >> qi::char_("\"")/*]*/;

       static  str_rule IRIValue = cstring_str;



       static  str_rule curly_barket_pair = qi::char_("{")[ sprt::_val = sprt::_1 ]
                >> *qi::space
                >> qi::char_("}")[ sprt::_val += sprt::_1];

       static term_rule ECODED_ = distinct(qi::alnum | ('-' >> qi::alnum))["ECODED"];
       static term_rule INTERSECTION_ = distinct(qi::alnum | ('-' >> qi::alnum))["INTERSECTION"];
       static term_rule SEQUENCE_ = distinct(qi::alnum | ('-' >> qi::alnum))["SEQUENCE"];
       static term_rule ABSTRACT_SYNTAX_ = distinct(qi::alnum | ('-' >> qi::alnum))["ABSTRACT-SYNTAX"];
       static term_rule ABSENT_ = distinct(qi::alnum | ('-' >> qi::alnum))["ABSENT"];
       static term_rule ENCODING_CONTROL_ = distinct(qi::alnum | ('-' >> qi::alnum))["ENCODING-CONTROL"];
       static term_rule ISO646String_ = distinct(qi::alnum | ('-' >> qi::alnum))["ISO646String"];
       static term_rule SET_ = distinct(qi::alnum | ('-' >> qi::alnum))["SET"];
       static term_rule ALL_ = distinct(qi::alnum | ('-' >> qi::alnum))["ALL"];
       static term_rule END_ = distinct(qi::alnum | ('-' >> qi::alnum))["END"];
       static term_rule MAX_ = distinct(qi::alnum | ('-' >> qi::alnum))["MAX"];
       static term_rule SETTINGS_ = distinct(qi::alnum | ('-' >> qi::alnum))["SETTINGS"];
       static term_rule APPLICATION_ = distinct(qi::alnum | ('-' >> qi::alnum))["APPLICATION"];
       static term_rule ENUMERATED_ = distinct(qi::alnum | ('-' >> qi::alnum))["ENUMERATED"];
       static term_rule MIN_ = distinct(qi::alnum | ('-' >> qi::alnum))["MIN"];
       static term_rule SIZE_ = distinct(qi::alnum | ('-' >> qi::alnum))["SIZE"];
       static term_rule AUTOMATIC_ = distinct(qi::alnum | ('-' >> qi::alnum))["AUTOMATIC"];
       static term_rule EXCEPT_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXCEPT"];
       static term_rule ENCODED_ = distinct(qi::alnum | ('-' >> qi::alnum))["ENCODED"];
       static term_rule MINUS_INFINITY_ = distinct(qi::alnum | ('-' >> qi::alnum))["MINUS-INFINITY"];
       static term_rule STRING_ = distinct(qi::alnum | ('-' >> qi::alnum))["STRING"];
       static term_rule BEGIN_ = distinct(qi::alnum | ('-' >> qi::alnum))["BEGIN"];
       static term_rule EXPLICIT_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXPLICIT"];
       static term_rule NOT_A_NUMBER_ = distinct(qi::alnum | ('-' >> qi::alnum))["NOT-A-NUMBER"];
       static term_rule SYNTAX_ = distinct(qi::alnum | ('-' >> qi::alnum))["SYNTAX"];
       static term_rule BIT_ = distinct(qi::alnum | ('-' >> qi::alnum))["BIT"];
       static term_rule EXPORTS_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXPORTS"];
       static term_rule NULL_ = distinct(qi::alnum | ('-' >> qi::alnum))["NULL"];
       static term_rule T61String_ = distinct(qi::alnum | ('-' >> qi::alnum))["T61String"];
       static term_rule BMPString_ = distinct(qi::alnum | ('-' >> qi::alnum))["BMPString"];
       static term_rule EXTENSIBILITY_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXTENSIBILITY"];
       static term_rule NumericString_ = distinct(qi::alnum | ('-' >> qi::alnum))["NumericString"];
       static term_rule TAGS_ = distinct(qi::alnum | ('-' >> qi::alnum))["TAGS"];
       static term_rule BOOLEAN_ = distinct(qi::alnum | ('-' >> qi::alnum))["BOOLEAN"];
       static term_rule EXTERNAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXTERNAL "];
       static term_rule OBJECT_ = distinct(qi::alnum | ('-' >> qi::alnum))["OBJECT"];
       static term_rule TeletexString_ = distinct(qi::alnum | ('-' >> qi::alnum))["TeletexString"];
       static term_rule BY_ = distinct(qi::alnum | ('-' >> qi::alnum))["BY"];
       static term_rule FALSE_ = distinct(qi::alnum | ('-' >> qi::alnum))["FALSE"];
       static term_rule ObjectDescriptor_ = distinct(qi::alnum | ('-' >> qi::alnum))["ObjectDescriptor"];
       static term_rule TIME_ = distinct(qi::alnum | ('-' >> qi::alnum))["TIME"];
       static term_rule CHARACTER_ = distinct(qi::alnum | ('-' >> qi::alnum))["CHARACTER"];
       static term_rule FROM_ = distinct(qi::alnum | ('-' >> qi::alnum))["FROM"];
       static term_rule OCTET_ = distinct(qi::alnum | ('-' >> qi::alnum))["OCTET"];
       static term_rule TIME_OF_DAY_ = distinct(qi::alnum | ('-' >> qi::alnum))["TIME-OF-DAY"];
       static term_rule CHOICE_ = distinct(qi::alnum | ('-' >> qi::alnum))["CHOICE"];
       static term_rule GeneralizedTime_ = distinct(qi::alnum | ('-' >> qi::alnum))["GeneralizedTime"];
       static term_rule OF_ = distinct(qi::alnum | ('-' >> qi::alnum))["OF"];
       static term_rule TRUE_ = distinct(qi::alnum | ('-' >> qi::alnum))["TRUE"];
       static term_rule CLASS_ = distinct(qi::alnum | ('-' >> qi::alnum))["CLASS"];
       static term_rule GeneralString_ = distinct(qi::alnum | ('-' >> qi::alnum))["GeneralString"];
       static term_rule OID_IRI_ = distinct(qi::alnum | ('-' >> qi::alnum))["OID-IRI"];
       static term_rule TYPE_IDENTIFIER_ = distinct(qi::alnum | ('-' >> qi::alnum))["TYPE-IDENTIFIER"];
       static term_rule COMPONENT_ = distinct(qi::alnum | ('-' >> qi::alnum))["COMPONENT"];
       static term_rule GraphicString_ = distinct(qi::alnum | ('-' >> qi::alnum))["GraphicString"];
       static term_rule OPTIONAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["OPTIONAL"];
       static term_rule UNION_ = distinct(qi::alnum | ('-' >> qi::alnum))["UNION"];
       static term_rule COMPONENTS_ = distinct(qi::alnum | ('-' >> qi::alnum))["COMPONENTS"];
       static term_rule IA5String_ = distinct(qi::alnum | ('-' >> qi::alnum))["IA5String"];
       static term_rule PATTERN_ = distinct(qi::alnum | ('-' >> qi::alnum))["PATTERN"];
       static term_rule UNIQUE_ = distinct(qi::alnum | ('-' >> qi::alnum))["UNIQUE"];
       static term_rule CONSTRAINED_ = distinct(qi::alnum | ('-' >> qi::alnum))["CONSTRAINED"];
       static term_rule IDENTIFIER_ = distinct(qi::alnum | ('-' >> qi::alnum))["IDENTIFIER"];
       static term_rule PDV_ = distinct(qi::alnum | ('-' >> qi::alnum))["PDV"];
       static term_rule UNIVERSAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["UNIVERSAL"];
       static term_rule CONTAINING_ = distinct(qi::alnum | ('-' >> qi::alnum))["CONTAINING"];
       static term_rule IMPLICIT_ = distinct(qi::alnum | ('-' >> qi::alnum))["IMPLICIT"];
       static term_rule PLUS_INFINITY_ = distinct(qi::alnum | ('-' >> qi::alnum))["PLUS-INFINITY"];
       static term_rule UniversalString_ = distinct(qi::alnum | ('-' >> qi::alnum))["UniversalString"];
       static term_rule DATE_ = distinct(qi::alnum | ('-' >> qi::alnum))["DATE"];
       static term_rule IMPLIED_ = distinct(qi::alnum | ('-' >> qi::alnum))["IMPLIED"];
       static term_rule PRESENT_ = distinct(qi::alnum | ('-' >> qi::alnum))["PRESENT"];
       static term_rule UTCTime_ = distinct(qi::alnum | ('-' >> qi::alnum))["UTCTime"];
       static term_rule DATE_TIME_ = distinct(qi::alnum | ('-' >> qi::alnum))["DATE-TIME"];
       static term_rule IMPORTS_ = distinct(qi::alnum | ('-' >> qi::alnum))["IMPORTS"];
       static term_rule PrintableString_ = distinct(qi::alnum | ('-' >> qi::alnum))["PrintableString"];
       static term_rule UTF8String_ = distinct(qi::alnum | ('-' >> qi::alnum))["UTF8String"];
       static term_rule DEFAULT_ = distinct(qi::alnum | ('-' >> qi::alnum))["DEFAULT"];
       static term_rule INCLUDES_ = distinct(qi::alnum | ('-' >> qi::alnum))["INCLUDES"];
       static term_rule PRIVATE_ = distinct(qi::alnum | ('-' >> qi::alnum))["PRIVATE"];
       static term_rule VideotexString_ = distinct(qi::alnum | ('-' >> qi::alnum))["VideotexString"];
       static term_rule DEFINITIONS_ = distinct(qi::alnum | ('-' >> qi::alnum))["DEFINITIONS"];
       static term_rule INSTANCE_ = distinct(qi::alnum | ('-' >> qi::alnum))["INSTANCE"];
       static term_rule REAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["REAL"];
       static term_rule VisibleString_ = distinct(qi::alnum | ('-' >> qi::alnum))["VisibleString"];
       static term_rule DURATION_ = distinct(qi::alnum | ('-' >> qi::alnum))["DURATION"];
       static term_rule INSTRUCTIONS_ = distinct(qi::alnum | ('-' >> qi::alnum))["INSTRUCTIONS"];
       static term_rule RELATIVE_OID_ = distinct(qi::alnum | ('-' >> qi::alnum))["RELATIVE-OID"];
       static term_rule WITH_ = distinct(qi::alnum | ('-' >> qi::alnum))["WITH"];
       static term_rule EMBEDDED_ = distinct(qi::alnum | ('-' >> qi::alnum))["EMBEDDED"];
       static term_rule INTEGER_ = distinct(qi::alnum | ('-' >> qi::alnum))["INTEGER"];
       static term_rule RELATIVE_OID_IRI_ = distinct(qi::alnum | ('-' >> qi::alnum))["RELATIVE-OID-IRI"];

       static  str_rule ABSTRACT_SYNTAX__ = distinct(qi::alnum | ('-' >> qi::alnum))["ABSTRACT-SYNTAX"];
       static  str_rule TYPE_IDENTIFIER__ = distinct(qi::alnum | ('-' >> qi::alnum))["TYPE-IDENTIFIER"];

       static  str_rule literal_except_token = distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("BIT")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("BOOLEAN")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("CHARACTER")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("CHOICE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("DATE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("DATE-TIME")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("DURATION")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("EMBEDDED")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("END")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("ENUMERATED")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("EXTERNAL")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("FALSE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("INSTANCE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("INTEGER")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("INTERSECTION")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("MINUS-INFINITY")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("NULL")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("OBJECT")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("OCTET")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("PLUS-INFINITY")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("REAL")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("RELATIVE-OID")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("SEQUENCE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("SET")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("TIME")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("TIME-OF-DAY")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("TRUE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("UNION")];


       static  str_rule word_ = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::lexeme[qi::upper[ sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::upper[sprt::_val += sprt::_1])
                | (qi::upper[sprt::_val += sprt::_1]
                >> -qi::upper[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::upper))))]];

       static  str_rule spaces_ = distinct((*qi::space) >> '&')[qi::space[ sprt::_val = sprt::_1 ] >> *(qi::space[sprt::_val += sprt::_1 ])];

       static  str_rule Literal_ = (word_ - literal_except_token) | qi::string(",");

       static  str_rule SyntaxField_ = Literal_[sprt::_val = sprt::_1 ] >> *(spaces_[ sprt::_val += ' '] >> Literal_[ sprt::_val += sprt::_1 ]);

       static  str_rule typereference_ = distinct(qi::alnum | ('-' >> qi::alnum))[qi::lexeme[qi::upper[ sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::alnum[sprt::_val += sprt::_1])
                | (qi::alnum[sprt::_val += sprt::_1]
                >> -qi::alnum[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::alnum))))]];

       static  str_rule identifier_ = distinct(qi::alnum | ('-' >> qi::alnum))[qi::lexeme[qi::lower[sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::alnum[sprt::_val += sprt::_1])
                | (qi::alnum[sprt::_val += sprt::_1]
                >> -qi::alnum[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::alnum))))]];

       static  str_rule valuereference_ = identifier_;

       static  str_rule valuesetreference_ = typereference_;

       static  str_rule modulereference_ = typereference_;

       static  str_rule objectreference_ = valuereference_;

       static  str_rule objectsetreference_ = typereference_;

       static  str_rule objectclassreference_ = distinct(qi::alnum | ('-' >> qi::alnum))[qi::lexeme[qi::upper[sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::char_("A-Z0-9")[sprt::_val += sprt::_1])
                | (qi::char_("A-Z0-9")[sprt::_val += sprt::_1]
                >> -qi::char_("A-Z0-9")[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::char_("A-Z0-9")))))]]; //(~typereference_)      

       static  str_rule typereference_strict = distinct(qi::alnum | ('-' >> qi::alnum))[typereference_ - qi::omit[objectclassreference_]];

       static  str_rule typefieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> typereference_[sprt::_val += sprt::_1 ]]; //(&typereference_[sprt::_val += sprt::_1 ])   

       static  str_rule valuefieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> valuereference_[sprt::_val += sprt::_1 ]]; //(&valuereference_)  

       static  str_rule valuesetfieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> typereference_[sprt::_val += sprt::_1 ]]; //(&typereference_)   

       static  str_rule objectfieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> objectreference_[sprt::_val += sprt::_1 ]]; //(&objectreference_)

       static  str_rule objectsetfieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> objectsetreference_[sprt::_val += sprt::_1 ]]; //(&objectsetreference_)  


       static  str_rule bigreference_ = typereference_;

       static  str_rule littlereference_ = valuereference_;

       static  str_rule bothreference_ = bigreference_ | littlereference_;

       static  str_rule bigfieldreference_ = typefieldreference_;

       static  str_rule littlefieldreference_ = valuefieldreference_;

       static  str_rule PrimitiveFieldName_ = bigfieldreference_ | littlefieldreference_;

       static  str_rule FieldName_ = PrimitiveFieldName_[sprt::_val = sprt::_1 ] >> -(qi::string(".")[sprt::_val += sprt::_1 ]
                >> qi::omit[(*qi::space)] >> (PrimitiveFieldName_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ]));

       static  str_rule BFieldName_ = bigfieldreference_[sprt::_val = sprt::_1 ] >> -(qi::string(".")[sprt::_val += sprt::_1 ]
                >> qi::omit[(*qi::space)] >> (bigfieldreference_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ]));

       static  str_rule LFieldName_ = littlefieldreference_[sprt::_val = sprt::_1 ] >> -(qi::string(".")[sprt::_val += sprt::_1 ]
                >> qi::omit[(*qi::space)] >> (littlefieldreference_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ]));



       static  str_rule ExternalTypeReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> typereference_[sprt::_val += sprt::_1 ];

       static  str_rule ExternalTypeReference_strict = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> typereference_strict[sprt::_val += sprt::_1 ];


       static  str_rule ExternalValueReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> valuereference_[sprt::_val += sprt::_1 ];

       static  str_rule ExternalValueSetReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> valuesetreference_[sprt::_val += sprt::_1 ];

       static  str_rule ExternalObjectClassReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> objectclassreference_[sprt::_val += sprt::_1 ];

       static  str_rule ExternalObjectReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> objectreference_[sprt::_val += sprt::_1 ];

       static  str_rule ExternalObjectSetReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> objectsetreference_[sprt::_val += sprt::_1 ];

       static  str_rule UsefulObjectClass_ = TYPE_IDENTIFIER__
                | ABSTRACT_SYNTAX__;

       static  str_rule DefinedObjectClass_ = TYPE_IDENTIFIER__
                | ABSTRACT_SYNTAX__
                | ExternalObjectClassReference_
                | objectclassreference_;



       static  str_rule DefinedType_ = ExternalTypeReference_ | typereference_; //| ParameterizedType | ParameterizedValueSetType

       static  str_rule DefinedType_strict = ExternalTypeReference_strict | typereference_strict; //| ParameterizedType | ParameterizedValueSetType        

       static  str_rule DefinedValue_ = ExternalValueReference_ | valuereference_; //| ParameterizedValue        

       static  str_rule DefinedValueSet_ = ExternalValueSetReference_ | valuesetreference_; //| ParameterizedValue          

       static  str_rule DefinedObject_ = ExternalObjectReference_ | objectreference_;

       static  str_rule DefinedObjectSet_ = ExternalObjectSetReference_ | objectsetreference_;

       static  str_rule UserDefinedConstraintParameter_ = (DefinedType_ | DefinedObjectClass_)
        >> -(qi::string(".") >> DefinedValue_);

       static  str_rule AtNotation_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.' | '@')[qi::string("@")[sprt::_val = sprt::_1 ]
                >> *(qi::string(".")[sprt::_val += sprt::_1 ]) >> (identifier_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ])];

       static  str_rule Reference_ = typereference_ | valuereference_;

       static  str_rule ObjectClassFieldType_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.')[DefinedObjectClass_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ] >> qi::omit[(*qi::space)] >> FieldName_[sprt::_val += sprt::_1 ] ];

       static  str_rule LittleFromObject_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.')[DefinedObject_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ] >> qi::omit[(*qi::space)] >> FieldName_[sprt::_val += sprt::_1 ]];

       static  str_rule BigFromObjects_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.')[DefinedObjectSet_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ] >> qi::omit[(*qi::space)] >> FieldName_[sprt::_val += sprt::_1 ]];

       static  str_rule ParameterizedReference_ = Reference_
                >> qi::omit[*qi::space
                >> curly_barket_pair];

       static  str_rule Symbol_ = ParameterizedReference_ | Reference_;




    }
}



#endif	

