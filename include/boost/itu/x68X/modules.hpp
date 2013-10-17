//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680TYPEPARSER_H_
#define         _ITU_X680TYPEPARSER_H_

#include <boost/itu/x68X/x680.hpp>
#include <boost/itu/x68X/setters.hpp>


namespace x680 {
    namespace syntactic {



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Modules_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

        struct Modules_grammar : qi::grammar<str_iterator, modules(), skip_cmt_type> {

            struct tag_default : qi::symbols<std::string::value_type, tagrule_type > {

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
                            ("XER", encoding_xer)
                            ("PER", encoding_per)
                            ;
                }
            };

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
                            ("OID-IRI", t_OID_IRI)
                            ("TIME-OF-DAY", t_TIME_OF_DAY)
                            ("RELATIVE-OID-IRI", t_RELATIVE_OID_IRI)
                            ("RELATIVE-OID", t_RELATIVE_OID)
                            ("ANY", t_ANY)
                            ;
                }
            };

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

            Modules_grammar() :
            Modules_grammar::base_type(start_rule) {
                init();
            }

            void init();
            void initT();
            void initV();
            void initVS();
            void initCl();
            void initO();
            void initOS();


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  Assigment grammar
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            qi::rule<str_iterator, modules(), skip_cmt_type> start_rule;


            qi::rule<str_iterator, module(), skip_cmt_type> ModuleDefinition;
            tag_default TagDefault;
            encoding_references EncodingReferenceDefault;
            qi::rule<str_iterator, import(), skip_cmt_type> Import;
            qi::rule<str_iterator, imports(), skip_cmt_type> Importsdecl;
            qi::rule<str_iterator, imports(), skip_cmt_type> Imports;
            qi::rule<str_iterator, string_vector(), skip_cmt_type> Exports;
            qi::rule<str_iterator, string_vector(), skip_cmt_type > SymbolList;
            qi::rule<str_iterator, assignment_vector(), skip_cmt_type> Assignments;


            qi::rule<str_iterator, class_assignment(), skip_cmt_type> ObjectClassAssignment;
            qi::rule<str_iterator, class_assignment(), skip_cmt_type> ObjectClassAssignment0;
            qi::rule<str_iterator, type_assignment(), skip_cmt_type> TypeAssignment; // strict
            qi::rule<str_iterator, type_assignment(), skip_cmt_type> TypeAssignment0; // strict            
            qi::rule<str_iterator, type_assignment(), skip_cmt_type> TypeAssignmentSS; // synctatic strict            
            qi::rule<str_iterator, value_assignment(), skip_cmt_type> ValueAssignmentLS; // left strict
            qi::rule<str_iterator, value_assignment(), skip_cmt_type> ValueAssignmentRS; // right strict      
            qi::rule<str_iterator, value_assignment(), skip_cmt_type> ValueAssignment;
            qi::rule<str_iterator, value_assignment(), skip_cmt_type> ValueAssignmentSS; // synctatic strict                          
            qi::rule<str_iterator, object_assignment(), skip_cmt_type> ObjectAssignmentRS; // right strict
            qi::rule<str_iterator, object_assignment(), skip_cmt_type> ObjectAssignmentLS; // left strict   
            qi::rule<str_iterator, object_assignment(), skip_cmt_type> ObjectAssignment;
            qi::rule<str_iterator, valueset_assignment(), skip_cmt_type> ValueSetTypeAssignmentLS; // left strict  
            qi::rule<str_iterator, valueset_assignment(), skip_cmt_type> ValueSetTypeAssignment;
            qi::rule<str_iterator, objectset_assignment(), skip_cmt_type> ObjectSetAssignmentLS; // left strict
            qi::rule<str_iterator, objectset_assignment(), skip_cmt_type> ObjectSetAssignment;
            qi::rule<str_iterator, unknown_tc_assignment(), skip_cmt_type> UnknownTCAssignment;
            qi::rule<str_iterator, unknown_vo_assignment(), skip_cmt_type> UnknownValObjAssignment;
            qi::rule<str_iterator, unknown_so_assignment(), skip_cmt_type> UnknownValSetObjSetAssignment;


            qi::rule<str_iterator, parameter_vector(), skip_cmt_type> ActualParameters;

            qi::rule<str_iterator, setting_element(), skip_cmt_type> ActualParameter;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> Setting;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> Setting0;           
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingCN;             
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingNA;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingU1;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingU2;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM0;    
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingMCN;            
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM1;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM1NA;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM2;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM3;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM4;

            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingType;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingValue;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingValueSet;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingClass;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingObject;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingObjectSet;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingLiteral;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingSLiteral;            
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingArgument;

            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingTypeNA;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingValueNA;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingValueSetNA;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingObjectNA;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingObjectSetNA;

            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingCValueSet;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingM5;
            qi::rule<str_iterator, setting_element(), skip_cmt_type> SettingC;

            qi::rule<str_iterator, argument_type(), skip_cmt_type> Parameter;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterA1;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterA2;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterB1;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterB2;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterC1;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterC2;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterD1;
            qi::rule<str_iterator, argument_type(), skip_cmt_type> ParameterD2;
            qi::rule<str_iterator, argument_vector(), skip_cmt_type> Parameters;
            
            qi::rule<str_iterator, uargument_type(), skip_cmt_type> UParameterA;
            qi::rule<str_iterator, uargument_type(), skip_cmt_type> UParameterB;
            qi::rule<str_iterator, uargument_type(), skip_cmt_type> UParameterC;        
            qi::rule<str_iterator, uargument_type(), skip_cmt_type> UParameterD;             
            qi::rule<str_iterator, uargument_type(), skip_cmt_type> UParameter;              
            qi::rule<str_iterator, uargument_vector(), skip_cmt_type> UParameters;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  UnknownTCAssigment grammar (Type or Class)
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     


            qi::rule<str_iterator, unknown_tc_element(), skip_cmt_type> UnknownReferencedTC;
            qi::rule<str_iterator, unknown_tc_element(), skip_cmt_type> UnknownTC;
            qi::rule<str_iterator, unknown_tc_element(), skip_cmt_type> UnknownTCFromObject;
            qi::rule<str_iterator, unknown_tc_element(), skip_cmt_type> UnknownTCValueSetFromObjects;


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  UnknownVOAssigment grammar (Value or Object)
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////      

            qi::rule<str_iterator, unknown_vo_element(), skip_cmt_type> ValueOrObjectM;
            qi::rule<str_iterator, unknown_vo_element(), skip_cmt_type> ValueOrObject;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  UnknownSOAssigment grammar (ValueSet or ObjectSet)
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

            qi::rule<str_iterator, unknown_so_element(), skip_cmt_type> ValueSetOrObjectSetM;
            qi::rule<str_iterator, unknown_so_element(), skip_cmt_type> ValueSetOrObjectSet;


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ValueAssigment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            qi::rule<str_iterator, value_element(), skip_cmt_type> Value;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueNA;
            qi::rule<str_iterator, value_element(), skip_cmt_type> SimpleDefinedValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> DefinedValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> StrictValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> RangeValue;


            qi::rule<str_iterator, value_element(), skip_cmt_type> NullValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> BooleanValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> IntegerValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> CStringValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> HStringValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> BStringValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> RealValue;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> Values;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueList;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> NumberValues;
            qi::rule<str_iterator, value_element(), skip_cmt_type> NumberList;
            qi::rule<str_iterator, value_element(), skip_cmt_type> NamedValue;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> NamedValues;
            qi::rule<str_iterator, value_element(), skip_cmt_type> NamedValueList;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ChoiceValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> EmptySetValue;


            qi::rule<str_iterator, value_element(), skip_cmt_type> ObjectIdentifierValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NumberFormN;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NumberForm;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NameForm;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NameAndNumberForm1;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NameAndNumberForm2;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NameAndNumberForm3;
            qi::rule<str_iterator, value_element(), skip_cmt_type>NameAndNumberForm;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ObjIdComponent;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> ObjIdComponents;

            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> NameBitList;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> NamedNumberList;

            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueExtention;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueException1;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueException2;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueException;
            qi::rule<str_iterator, value_element(), skip_cmt_type> EnumerationItem;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> RootEnumerations;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> Enumerations;


            qi::rule<str_iterator, value_element(), skip_cmt_type> ObjectClassFieldValue;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueFromObject;
            qi::rule<str_iterator, value_element(), skip_cmt_type> ValueFromObjectNA;

            qi::rule<str_iterator, typevalue_element(), skip_cmt_type> OpenTypeFieldVal;
            qi::rule<str_iterator, typevalue_element(), skip_cmt_type> OpenTypeFieldValv;




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  TypeAssigment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////       


            check_class Class;
            check_rule Rule;
            check_type_simple simple_typer;

            qi::rule<str_iterator, tag_type(), skip_cmt_type> Tag;


            qi::rule<str_iterator, type_element(), skip_cmt_type> Type;
            qi::rule<str_iterator, type_element(), skip_cmt_type> TypeNA;
            qi::rule<str_iterator, type_element(), skip_cmt_type> GovernorType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> StrictType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> ConstraintReferencedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> ObjectClassFieldType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleTypeFromObject;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleTypeFromObjectNA;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleValueSetFromObjects;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleValueSetFromObjectsNA;



            qi::rule<str_iterator, type_assignment(), skip_cmt_type> NamedType;
            qi::rule<str_iterator, type_assignment(), skip_cmt_type> TypeA;

            qi::rule<str_iterator, type_element(), skip_cmt_type> BuitinType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> DefinedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleDefinedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> StrictDefinedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> InstanceOfType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleReferencedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleReferencedTypeNA;
            qi::rule<str_iterator, type_element(), skip_cmt_type> ReferencedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> ReferencedTypeNA;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleType;

            qi::rule<str_iterator, type_element(), skip_cmt_type> IntegerType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> EnumeratedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> BitStringType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SequenceOfType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SetOfType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> TaggedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SimpleTaggedType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SequenceType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SetType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> SelectionType;
            qi::rule<str_iterator, type_element(), skip_cmt_type> ChoiceType;

            qi::rule<str_iterator, type_assignment(), skip_cmt_type> ComponentType;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ComponentTypeList;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> RootComponentTypeLists;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type>ExtensionAdditions;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionList;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAddition;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionGroup1;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionGroup;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ComponentTypeListsKrn;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ComponentTypeListsEx;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ComponentTypeLists;


            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> AlternativeTypeList;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> RootAlternativeTypeList;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionAlternativesGroup1;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionAlternativesGroup;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionAlternatives;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAdditionAlternative;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> AlternativeTypeLists;

            qi::rule<str_iterator, type_assignment(), skip_cmt_type> ExceptionSpec;
            qi::rule<str_iterator, type_assignment(), skip_cmt_type> Extension;
            qi::rule<str_iterator, type_assignment_vector(), skip_cmt_type> ExtensionAndException;
            qi::rule<str_iterator, type_assignment(), skip_cmt_type> ExtensionEndMarker;





            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  Constraint grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     

            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ValueSet;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ValueSetNA;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> SimpleValueSet;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ParameterizedValueSet;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> StrictValueSet;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ValueSetFromObject;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ValueSetFromObjectNA;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ValueSetFromObjects;
            qi::rule < str_iterator, valueset_element(), skip_cmt_type> ValueSetFromObjectsNA;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> ValueSetdecl;

            qi::rule < str_iterator, constraints_vector(), skip_cmt_type> Constraints;
            qi::rule < str_iterator, constraints_vector(), skip_cmt_type> SizeConstraints;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> Constraint;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> ConstraintSpec;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> ElementSetSpecs;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> GeneralConstraintdecl;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> GeneralConstraint;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> ElementSetSpec;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type>Intersections;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> Unions;
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> Exclusions;

            qi::rule<str_iterator, constraint_element_vector(), skip_cmt_type> UElems;
            qi::rule<str_iterator, constraint_element_vector(), skip_cmt_type> IElems;
            qi::rule<str_iterator, constraint_element_vector(), skip_cmt_type> EElems;
            qi::rule<str_iterator, constraint_element_vector(), skip_cmt_type> AElems;

            qi::rule<str_iterator, constraint_element(), skip_cmt_type> Element;

            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SingleValue;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ConstraintFromObjects;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ConstraintFromObject;
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
            qi::rule < str_iterator, constraint_element_vector(), skip_cmt_type> FullSpecification;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> MultipleTypeConstraints;

            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ExceptionSpecConstraint;
            qi::rule<str_iterator, constraint_element_vector(), skip_cmt_type> ExceptionSpecConstraints;


            qi::rule<str_iterator, constraint_element(), skip_cmt_type> UserDefinedConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> SimpleTableConstraint;
            qi::rule<str_iterator, string_vector(), skip_cmt_type> AtNotations;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ComponentRelationConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContentsConstraintType;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContentsConstraintValue;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ContentsConstraintTypeValue;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> UndefTVOConstraint;
            qi::rule<str_iterator, constraint_element(), skip_cmt_type> ConstraintTVSOS;








            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectClassAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


            qi::rule<str_iterator, class_element(), skip_cmt_type> ObjectClass;
            qi::rule<str_iterator, class_element(), skip_cmt_type> StrictObjectClass;
            qi::rule<str_iterator, class_element(), skip_cmt_type> ObjectClassDefn;
            qi::rule<str_iterator, class_element(), skip_cmt_type> UsefulObjectClass;
            qi::rule<str_iterator, class_element(), skip_cmt_type> DefinedObjectClass;
            qi::rule<str_iterator, class_element(), skip_cmt_type> SimpleDefinedObjectClass;
            qi::rule<str_iterator, class_element(), skip_cmt_type> ParameterizedObjectClass;

            qi::rule<str_iterator, classfield_vector(), skip_cmt_type> FieldSpecs;

            qi::rule<str_iterator, classfield_type(), skip_cmt_type> FieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> TypeFieldSpecS;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> TypeFieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> FixedTypeValueFieldSpecLS;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> FixedTypeValueFieldSpecMS;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> FixedUndefFieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> VariableTypeValueFieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> FixedTypeValueSetFieldSpecLS;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> FixedUndefSetFieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> VariableTypeValueSetFieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> ObjectFieldSpecLS;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> ObjectSetFieldSpecLS;

            qi::rule<str_iterator, classsyntax_vector(), skip_cmt_type> WithSyntaxSpec;
            qi::rule<str_iterator, classsyntax_vector(), skip_cmt_type> SyntaxList;
            qi::rule<str_iterator, classsyntax_vector(), skip_cmt_type> OptionalGroup;
            qi::rule<str_iterator, classsyntax_vector(), skip_cmt_type> TokenOrGroupSpec;
            qi::rule<str_iterator, classsyntax_type(), skip_cmt_type> RequiredToken;
            qi::rule<str_iterator, classsyntax_type(), skip_cmt_type> OptionalToken;
            qi::rule<str_iterator, classsyntax_type(), skip_cmt_type> AiasTokenOToken;
            qi::rule<str_iterator, classsyntax_type(), skip_cmt_type> TokenOToken;







            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


            qi::rule<str_iterator, object_element(), skip_cmt_type> Object;
            qi::rule<str_iterator, object_element(), skip_cmt_type> ObjectNA;
            qi::rule<str_iterator, object_element(), skip_cmt_type> DefinedObject;
            qi::rule<str_iterator, object_element(), skip_cmt_type> SimpleDefinedObject;
            qi::rule<str_iterator, object_element(), skip_cmt_type> ObjectFromObject;
            qi::rule<str_iterator, object_element(), skip_cmt_type> ObjectFromObjectNA;

            qi::rule<str_iterator, object_element(), skip_cmt_type> ObjectDefn;
            qi::rule<str_iterator, object_element(), skip_cmt_type> DefaultSyntax;
            qi::rule<str_iterator, object_element(), skip_cmt_type> DefinedSyntax;

            qi::rule<str_iterator, objectfield_vector(), skip_cmt_type> FieldSettings;
            qi::rule<str_iterator, objectfield_type(), skip_cmt_type> FieldSetting;

            qi::rule<str_iterator, objectfield_vector(), skip_cmt_type> DefinedSyntaxTokens;
            qi::rule<str_iterator, objectfield_type(), skip_cmt_type> DefinedSyntaxToken;
            qi::rule<str_iterator, objectfield_type(), skip_cmt_type> DefinedSyntaxToken1;
            qi::rule<str_iterator, objectfield_type(), skip_cmt_type> DefinedSyntaxToken2;




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectSetAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     

            qi::rule < str_iterator, objectset_element(), skip_cmt_type> ObjectSet;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> ObjectSetNA;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> SimpleDefinedObjectSet;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> DefinedObjectSet;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> ObjectSetFromObject;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> ObjectSetFromObjectNA;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> ObjectSetFromObjects;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> ObjectSetFromObjectsNA;
            qi::rule < str_iterator, objectset_element(), skip_cmt_type> StrictObjectSet;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> ObjectSetdecl;

            qi::rule<str_iterator, object_element(), skip_cmt_type> oDefinedObjectSet;
            qi::rule<str_iterator, object_element(), skip_cmt_type> oObjectSetFromObjects;
            qi::rule<str_iterator, object_element(), skip_cmt_type> oObjectSetFromObject;


            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oElementSetSpecs1;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oElementSetSpecs2;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oElementSetSpecs;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oElementSetSpec;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oIntersections;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oUnions;
            qi::rule < str_iterator, object_element_vector(), skip_cmt_type> oExclusions;

            qi::rule<str_iterator, object_element_vector(), skip_cmt_type> oUElems;
            qi::rule<str_iterator, object_element_vector(), skip_cmt_type> oIElems;
            qi::rule<str_iterator, object_element_vector(), skip_cmt_type> oEElems;
            qi::rule<str_iterator, object_element_vector(), skip_cmt_type> oAElems;

            qi::rule<str_iterator, object_element(), skip_cmt_type> oExtention;

            qi::rule<str_iterator, object_element(), skip_cmt_type> oElement;

        };


        int parse_fs(const std::string& path, modules& result, const std::string& ext = "asn");

        int parse_directory(const std::string& directory, modules& result, const std::string& ext = "asn");

        int parse_file(const std::string& filename, modules& result);


    }
}



#endif	

