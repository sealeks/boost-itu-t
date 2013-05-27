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

            struct encoding_references : qi::symbols<std::string::value_type, encoding_references_type > {

                encoding_references() {
                    add
                            ("TAG", encoding_tag)
                            ("XER", encoding_xer)
                            ("PER", encoding_per)
                            ;
                }
            };

            Tag_grammar() :
            Tag_grammar::base_type(start_rule) {
                init();
            }

            void init();

            check_class Class;
            check_rule Rule;
            encoding_references encoding;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Type_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct Type_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef Type_grammar self_type;
            typedef type_assignment holder_type;
            typedef type_assignment_vector holders_type;

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
                            ("DURATION", t_DURATION)
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
                            ("RELATIVE-OID", t_RELATIVE_OID)
                            ;
                }
            };

            Type_grammar() :
            Type_grammar::base_type(start_rule) {
                init();
            }

            void init();



            qi::rule<str_iterator, type_element(), skip_cmt_type> start_rule;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> TypeAssignment;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> NamedType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> Type;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> BuitinType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> DefinedType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> InstanceOfType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ReferencedType;
            check_type_simple simple_typer;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SimpleType;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> IntegerType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> EnumeratedType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> BitStringType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SequenceOfType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SetOfType;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> ComponentType;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ComponentTypeList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> RootComponentTypeLists;
            qi::rule<str_iterator, holders_type(), skip_cmt_type>ExtensionAdditions;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAddition;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionGroup;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ComponentTypeListsKrn;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ComponentTypeListsEx;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ComponentTypeLists;


            qi::rule<str_iterator, holders_type(), skip_cmt_type> AlternativeTypeList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> RootAlternativeTypeList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionAlternativesGroup;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionAlternatives;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionAlternative;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> AlternativeTypeLists;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> ExceptionSpec;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> Extension;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAndException;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ExtensionEndMarker;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SequenceType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SetType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SelectionType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ChoiceType;
            Enumerations_grammar Enumerations;
            NamedNumberList_grammar NamedNumberList;
            NamedNumberList_grammar NameBitList;
            Tag_grammar Tag;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> TaggedType;
            Value_grammar Value;

        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Elements_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////      

        struct Elements_grammar : qi::grammar<str_iterator, constraint_element_vector(), skip_cmt_type> {

            typedef Elements_grammar self_type;
            typedef constraint_element_vector holder_type;

            Elements_grammar() :
            Elements_grammar::base_type(Constraint) {
                init();
            }

            void init();
            
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> Constraint;
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> ConstraintSpec;
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> ElementSetSpecs;   
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> GeneralConstraint;            
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> ElementSetSpec;
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type>Intersections;
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> Unions;
            qi::rule < std::string::iterator, holder_type(), skip_cmt_type> Exclusions;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> UElems;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> IElems;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> EElems;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> AElems;

            qi::rule<str_iterator, constraint_element(), skip_cmt_type> Element;

            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SingleValue;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContainedSubtype;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ValueRange;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> TypeConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> PatternConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> PropertySettings;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> Extention;

            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SizeConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> PermittedAlphabet;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SingleTypeConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SimpleElement;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> NamedConstraint;
            qi::rule < std::string::iterator, constraint_element_vector(), skip_cmt_type> FullSpecification;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> MultipleTypeConstraints;
            
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ExceptionSpecConstraint;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ExceptionSpecConstraints;            
            
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> UserDefinedConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SimpleTableConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ComponentRelationConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContentsConstraintType;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContentsConstraintValue;            
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContentsConstraintTypeValue;             

            Type_grammar Type;
            Value_grammar Value;
            IntegerValue_grammar IntegerValue;
            HStringValue_grammar CStringValue;
            RealValue_grammar RealValue;
            IdentifierValue_grammar IdentifierValue;
            ObjectIdentifierValue_grammar ObjectIdentifierValue;


        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // TypeAssignment_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct TypeAssignment_grammar : qi::grammar<str_iterator, type_assignment(), skip_cmt_type> {

            typedef TypeAssignment_grammar self_type;
            typedef type_assignment holder_type;

            TypeAssignment_grammar() :
            TypeAssignment_grammar::base_type(start_rule) {
                init();
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar Type;
        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // TypeAssignment_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct ValueAssignment_grammar : qi::grammar<str_iterator, value_assignment(), skip_cmt_type> {

            typedef ValueAssignment_grammar self_type;
            typedef value_assignment holder_type;

            ValueAssignment_grammar() :
            ValueAssignment_grammar::base_type(start_rule) {
                init();
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar Type;
            Value_grammar Value;
        };


        //extern syn_elements_sk_rule Types_;

        struct Assignments_grammar : qi::grammar<str_iterator, assignment_vector(), skip_cmt_type> {

            typedef Assignments_grammar self_type;
            typedef assignment_vector holder_type;

            Assignments_grammar() :
            Assignments_grammar::base_type(start_rule) {
                init();
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            TypeAssignment_grammar TypeAssignment;
            ValueAssignment_grammar ValueAssignment;
        };

    }
}



#endif	

