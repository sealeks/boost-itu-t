//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {

        void Tag_grammar::init() {

            start_rule = qi::lit("[")
                    >> -(encoding[bind(&tag_encoding, qi::_val, qi::_1)] >> qi::lit(":"))
                    >> -(Class[bind(&tag_class, qi::_val, qi::_1)])
                    >> (pos_number_str | DefinedValue_)[bind(&tag_number, qi::_val, qi::_1)]
                    >> qi::lit("]")
                    >> -(Rule[bind(&tag_rule, qi::_val, qi::_1)]);

        }


        // Type_grammar

        void Assignments_grammar::init() {

            start_rule = *(ObjectClassAssignment | TypeAssignment | ObjectAssignment | ObjectSetAssignment | ValueAssignment | ValueSetTypeAssignment);



            TypeAssignment = typereference_[bind(&type_identifier, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[bind(&typea_type, qi::_val, qi::_1)];

            ValueAssignment = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> Type[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[bind(&valuea_value, qi::_val, qi::_1)];

            ValueSetTypeAssignment = typereference_[bind(&valueset_reference, qi::_val, qi::_1)]
                    >> Type[bind(&valueset_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[bind(&valueset_set, qi::_val, qi::_1)];

            ObjectClassAssignment = (objectclassreference_
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectClassDefn)[bind(&classa_set, qi::_val, qi::_1, qi::_2)];

            ObjectAssignment = (objectreference_
                    >> DefinedObjectClass_
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> DefaultSyntax)[bind(&objecta_set, qi::_val, qi::_1, qi::_2, qi::_3)];


            ObjectSetAssignment = (objectsetreference_
                    >> DefinedObjectClass_
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet)[bind(&objectseta_set, qi::_val, qi::_1, qi::_2, qi::_3)];




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  TypeAssigment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            Type = BuitinType | TaggedType | DefinedType;

            NamedType = (identifier_ >> Type)[bind(&type_named, qi::_val, qi::_1, qi::_2)];

            TypeA = Type[bind(&typea_type, qi::_val, qi::_1) ];


            BuitinType = SimpleType | IntegerType | EnumeratedType | BitStringType | SelectionType | SequenceOfType | SetOfType | SequenceType | ChoiceType | SetType | InstanceOfType;

            TaggedType = (Tag
                    >> Type)[bind(&type_tagged, qi::_val, qi::_1, qi::_2)];

            DefinedType = DefinedType_[bind(&type_refference, qi::_val, qi::_1)];

            InstanceOfType = qi::omit[qi::lexeme[INSTANCE_ >> +qi::blank >> OF_]]
                    >> DefinedObjectClass_[bind(&type_instance, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            ReferencedType = DefinedType;

            SimpleType = ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&type_deff, qi::_val, t_OCTET_STRING)]
                    | (qi::lexeme[CHARACTER_ >> +qi::blank >> STRING_])[bind(&type_deff, qi::_val, t_CHARACTER_STRING)]
                    | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&type_deff, qi::_val, t_EMBEDDED_PDV)]
                    | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&type_deff, qi::_val, t_OBJECT_IDENTIFIER)]
                    | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&type_deff, qi::_val, t_DATE_TIME)]
                    | (distinct(qi::alnum | '-')[simple_typer[bind(&type_deff, qi::_val, qi::_1)]])
                    )
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            IntegerType = INTEGER_[bind(&type_deff, qi::_val, t_INTEGER)]
                    >> -NamedNumberList[bind(&type_deffinit, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            EnumeratedType = ENUMERATED_[bind(&type_deff, qi::_val, t_ENUMERATED)]
                    >> -Enumerations[bind(&type_deffinit, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            BitStringType = BIT_ >> +qi::blank >> STRING_[bind(&type_deff, qi::_val, t_BIT_STRING)]
                    >> -NameBitList[bind(&type_deffinit, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);




            SequenceOfType = (SEQUENCE_
                    >> -((SizeConstraints[bind(&type_constraints, qi::_val, qi::_1)]) | (Constraints[bind(&type_constraints, qi::_val, qi::_1)]))
                    >> OF_)[bind(&type_deff, qi::_val, t_SEQUENCE_OF)]
                    >> (TypeA | NamedType)[bind(&type_push, qi::_val, qi::_1) ];

            SetOfType = (SET_
                    >> -((SizeConstraints[bind(&type_constraints, qi::_val, qi::_1)]) | (Constraints[bind(&type_constraints, qi::_val, qi::_1)]))
                    >> OF_)[bind(&type_deff, qi::_val, t_SET_OF)]
                    >> (TypeA | NamedType)[bind(&type_push, qi::_val, qi::_1) ];





            ExceptionSpec = qi::omit[qi::lit("!")] >> (pos_number_str[bind(&type_exceptnumber, qi::_val, qi::_1) ]
                    | DefinedValue_[bind(&type_exceptidetifier, qi::_val, qi::_1) ]
                    | (TypeA[qi::_val = qi::_1 ] >> qi::omit[ qi::lit(":")] >> Value[bind(&type_exceptvalue, qi::_val, qi::_1) ])
                    );


            //    


            ComponentType %= ((qi::omit[qi::lexeme[COMPONENTS_ >> +qi::blank >> OF_]] >> TypeA)[bind(&type_marker, qi::_val, mk_components_of)]
                    | (NamedType >> qi::omit[OPTIONAL_])[bind(&type_marker, qi::_val, mk_optional)]
                    | ((NamedType >> qi::omit[DEFAULT_])[bind(&type_marker, qi::_val, mk_default)] >> qi::omit[Value[bind(&type_defaultvalue, qi::_val, qi::_1)]])
                    | NamedType);

            ComponentTypeList = (ComponentType % qi::omit[qi::lit(",")]);

            ExtensionAdditionGroup = qi::omit[qi::lit("[[")
                    >> -(pos_number_str
                    >> qi::lit(":"))]
                    >> ComponentTypeList
                    >> qi::omit[qi::lit("]]")];

            ExtensionAddition = qi::omit[qi::lit(",")] >> (ExtensionAdditionGroup | ComponentType);

            ExtensionAdditions = qi::omit[qi::lit(",")] >> ExtensionAdditionGroup >> -(ExtensionAddition);

            Extension = qi::lit("...")[qi::_val = extention_type_assignment ];

            ExtensionAndException = Extension >> -ExceptionSpec;

            ExtensionEndMarker = qi::omit[qi::lit(",")] >> Extension;

            ComponentTypeListsKrn = ExtensionAndException >> -ExtensionAdditions >> -ExtensionEndMarker;

            ComponentTypeListsEx = ExtensionAndException >> -ExtensionEndMarker;

            ComponentTypeLists = -ComponentTypeList >> -qi::lit(",") >> -ComponentTypeListsKrn >> -(qi::lit(",") >> ComponentTypeList);

            RootComponentTypeLists = ComponentTypeListsEx | ComponentTypeLists;


            AlternativeTypeList = (NamedType % qi::omit[qi::lit(",")]);

            RootAlternativeTypeList = AlternativeTypeList;

            ExtensionAdditionAlternativesGroup = qi::omit[qi::lit("[[")
                    >> -(pos_number_str
                    >> qi::lit(":"))]
                    >> AlternativeTypeList
                    >> qi::omit[qi::lit("]]")];

            ExtensionAdditionAlternative = qi::omit[qi::lit(",")] >> (ExtensionAdditionGroup | NamedType);

            ExtensionAdditionAlternatives = qi::omit[qi::lit(",")] >> ExtensionAdditionGroup >> -(ExtensionAdditionAlternative);

            AlternativeTypeLists = RootAlternativeTypeList
                    >> -(qi::lit(",")
                    >> ExtensionAndException
                    >> -ExtensionAdditionAlternatives
                    >> -ExtensionEndMarker);



            SelectionType = (identifier_
                    >> qi::omit[qi::lit("<")]
                    >> Type)[bind(&type_select, qi::_val, qi::_1, qi::_2)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);


            SequenceType = SEQUENCE_[bind(&type_deff, qi::_val, t_SEQUENCE)]
                    >> qi::lit("{")
                    >> -RootComponentTypeLists [bind(&type_pushs, qi::_val, qi::_1) ]
                    >> qi::lit("}")
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);


            SetType = SET_[bind(&type_deff, qi::_val, t_SET)]
                    >> qi::lit("{")
                    >> -RootComponentTypeLists[bind(&type_pushs, qi::_val, qi::_1) ]
                    >> qi::lit("}")
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            ChoiceType = CHOICE_[bind(&type_deff, qi::_val, t_CHOICE)]
                    >> qi::lit("{")
                    >> -(AlternativeTypeLists[bind(&type_pushs, qi::_val, qi::_1) ])
                    >> qi::lit("}")
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);










            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  Constraint grammar
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            ValueSet = qi::omit[qi::lit("{")]
                    >> ElementSetSpecs
                    >> qi::omit[qi::lit("}")];

            Constraints = +Constraint;

            SizeConstraints = SizeConstraint[bind(&pushs_constraint, qi::_val, qi::_1)];

            Constraint %= qi::omit[qi::lit("(")] >> ConstraintSpec
                    >> -ExceptionSpecConstraints
                    >> qi::omit[qi::lit(")")];

            ConstraintSpec = GeneralConstraint | ElementSetSpecs;

            ElementSetSpecs %= ElementSetSpec >>
                    -(qi::omit[qi::lit(",")] >> Extention >>
                    -(qi::omit[qi::lit(",")] >> ElementSetSpec));

            GeneralConstraint = (UserDefinedConstraint
                    | ContentsConstraintTypeValue
                    | ContentsConstraintValue
                    | ContentsConstraintType
                    | ComponentRelationConstraint/* | SimpleTableConstraint*/)[ bind(&constraint_element_vector::push_back, qi::_val, qi::_1) ];




            UElems %= ((qi::omit[(UNION_ | qi::lit("|"))]
                    >> Unions)[ bind(&constraint_element_vector::push_back, qi::_val, CONSTRAINT_UNION) ]);

            ElementSetSpec
                    = Unions[bind(&push_constraints, qi::_val, qi::_1)] >> *(UElems[bind(&push_constraints, qi::_val, qi::_1)]);

            IElems %= (qi::omit[(INTERSECTION_ | qi::lit("^"))]
                    >> Intersections)[bind(&constraint_element_vector::push_back, qi::_val, CONSTRAINT_INTERSECTION)];

            Unions =
                    Intersections[bind(&push_constraints, qi::_val, qi::_1)] >> *(IElems[bind(&push_constraints, qi::_val, qi::_1)]);


            EElems %= (qi::omit[EXCEPT_ ]
                    >> Exclusions)[bind(&constraint_element_vector::push_back, qi::_val, CONSTRAINT_EXCEPT)];

            Intersections =
                    Exclusions[bind(&push_constraints, qi::_val, qi::_1)] >> *(EElems[bind(&push_constraints, qi::_val, qi::_1)]);


            AElems %=
                    (qi::omit[qi::lit("ALL EXCEPT")]
                    >> Exclusions)[bind(&constraint_element_vector::push_back, qi::_val, CONSTRAINT_ALLEXCEPT)];

            Exclusions
                    = Element
                    | qi::omit[qi::lit("(")]
                    >> ElementSetSpec
                    >> qi::omit[ qi::lit(")")]
                    | AElems
                    ;

            Extention = qi::lit("...")[qi::_val = CONSTRAINT_EXTENTION];

            ContainedSubtype = INCLUDES_ >> Type[bind(&constraint_subtype, qi::_val, qi::_1)];

            PatternConstraint = PATTERN_ >> CStringValue[bind(&constraint_patterntype, qi::_val, qi::_1)];

            SingleValue = Value[bind(&constraint_singlevalue, qi::_val, qi::_1)];

            PropertySettings = SETTINGS_ >> (CStringValue | IdentifierValue)[bind(&constraint_property, qi::_val, qi::_1)];

            ValueRange = (MIN_[bind(&constraint_fromtype, qi::_val, min_range)]
                    | (IntegerValue | RealValue | CStringValue)[bind(&constraint_from, qi::_val, qi::_1)])
                    >> -(qi::lit("<")[bind(&constraint_fromtype, qi::_val, open_range)])
                    >> qi::lit("..")
                    >> -(qi::lit("<")[bind(&constraint_totype, qi::_val, open_range)])
                    >> (MAX_[bind(&constraint_totype, qi::_val, max_range)]
                    | (IntegerValue | RealValue | CStringValue)[bind(&constraint_to, qi::_val, qi::_1)]);




            TypeConstraint = Type[bind(&constraint_type, qi::_val, qi::_1)];

            SimpleElement = ContainedSubtype | PatternConstraint | PropertySettings | ValueRange | SingleValue | TypeConstraint;

            SizeConstraint = qi::omit[SIZE_]
                    >> Constraint[bind(&constraint_size, qi::_val, qi::_1)];

            PermittedAlphabet = qi::omit[FROM_]
                    >> Constraint[bind(&constraint_alphabet, qi::_val, qi::_1)];

            SingleTypeConstraint = qi::omit[qi::lexeme[WITH_ >> +qi::blank >> COMPONENT_]]
                    >> Constraint[bind(&constraint_singletype, qi::_val, qi::_1)];

            NamedConstraint = identifier_[bind(&constraint_identifier, qi::_val, qi::_1)]
                    >> -Constraint[bind(&constraint_namedtype, qi::_val, qi::_1)]
                    >> -(PRESENT_[bind(&constraint_marker, qi::_val, cmk_present)]
                    | ABSENT_[bind(&constraint_marker, qi::_val, cmk_absent)]
                    | OPTIONAL_[bind(&constraint_marker, qi::_val, cmk_optional)]);

            FullSpecification = qi::omit[qi::lit("{")]
                    >> -(Extention >> qi::omit[qi::lit(",")])
                    >> (NamedConstraint % qi::omit[qi::lit(",")])
                    >> qi::omit[qi::lit("}")];

            MultipleTypeConstraints = qi::omit[qi::lexeme[WITH_ >> +qi::blank >> COMPONENTS_]]
                    >> FullSpecification[bind(&constraint_multitype, qi::_val, qi::_1)];

            Element = SizeConstraint | PermittedAlphabet | MultipleTypeConstraints | SingleTypeConstraint | SimpleElement;




            ExceptionSpecConstraint = qi::omit[qi::lit("!")] >> (pos_number_str[bind(&constraint_exceptnumber, qi::_val, qi::_1) ]
                    | DefinedValue_[bind(&constraint_exceptidentifier, qi::_val, qi::_1) ]
                    | (Type >> qi::omit[ qi::lit(":")] >> Value)[bind(&constraint_excepttypevalue, qi::_val, qi::_1, qi::_2) ]
                    );

            ExceptionSpecConstraints = ExceptionSpecConstraint[ bind(&constraint_element_vector::push_back, qi::_val, qi::_1) ];

            UserDefinedConstraintParameters = UserDefinedConstraintParameter_ % qi::omit[qi::lit(",")];

            UserDefinedConstraint =
                    (qi::omit[qi::lexeme[CONSTRAINED_ >> +qi::blank >> BY_]])[bind(&constraint_tp, qi::_val, cns_UserDefinedConstraint)]
                    >> qi::omit[qi::lit("{")]
                    >> -(UserDefinedConstraintParameters[bind(&constraint_userdef, qi::_val, qi::_1)])
                    >> qi::omit[qi::lit("}")];

            //qi::rule<str_iterator, constraint_element(), skip_cmt_type> SimpleTableConstraint;

            AtNotations = *AtNotation_;

            ComponentRelationConstraint = (qi::omit[qi::lit("{")]
                    >> DefinedObjectSet_
                    >> qi::omit[qi::lit("}")]
                    >> qi::omit[qi::lit("{")]
                    >> AtNotations
                    >> qi::omit[qi::lit("}")])[bind(&constraint_relation, qi::_val, qi::_1, qi::_2)];

            ContentsConstraintType = qi::omit[CONTAINING_]
                    >> Type[bind(&constraint_content_t, qi::_val, qi::_1)];

            ContentsConstraintValue = qi::omit[qi::lexeme[ENCODED_ >> +qi::blank >> BY_]]
                    >> (IdentifierValue | ObjectIdentifierValue)[bind(&constraint_content_v, qi::_val, qi::_1)];

            ContentsConstraintTypeValue = (qi::omit[CONTAINING_]
                    >> Type
                    >> qi::omit[qi::lexeme[ENCODED_ >> +qi::blank >> BY_]]
                    >> (IdentifierValue | ObjectIdentifierValue))[bind(&constraint_content_tv, qi::_val, qi::_1, qi::_2)];










            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectClassAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////   



            //ObjectClass = ObjectClassDefn;

            ObjectClassDefn = qi::omit[CLASS_ >> qi::lit("{")] >> FieldSpecs[bind(&class_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")]
                    >> -(WithSyntaxSpec[bind(&class_syntaxes, qi::_val, qi::_1)]);

            FieldSpecs = FieldSpec % qi::omit[qi::lit(",")];

            FieldSpec = TypeFieldSpecS | FixedTypeValueFieldSpec | FixedTypeValueSetFieldSpec | VariableTypeValueSetFieldSpec | VariableTypeValueFieldSpec | TypeFieldSpec; //ObjectFieldSpec | ObjectSetFieldSpec;     

            TypeFieldSpecS = (typefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> (OPTIONAL_[bind(&classfield_optional, qi::_val)] | (qi::omit[DEFAULT_]
                    >> Type[bind(&classfield_defaulttype, qi::_val, qi::_1)])))[bind(&classfield_tp, qi::_val, fkind_TypeFieldSpec)];

            TypeFieldSpec = (typefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] | (qi::omit[DEFAULT_]
                    >> Type[bind(&classfield_defaulttype, qi::_val, qi::_1)])))[bind(&classfield_tp, qi::_val, fkind_TypeFieldSpec)];

            FixedTypeValueFieldSpec = valuefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> Type[bind(&classfield_holder_ft, qi::_val, qi::_1, true)]
                    >> -(((UNIQUE_[bind(&classfield_unique, qi::_val)])
                    || OPTIONAL_[bind(&classfield_optional, qi::_val)])
                    | (OPTIONAL_[bind(&classfield_optional, qi::_val)])
                    | (qi::omit[DEFAULT_]
                    >> (DefinedValue_[bind(&classfield_defaultref, qi::_val, qi::_1)] | Value[bind(&classfield_defaultvalue, qi::_val, qi::_1)])));


            VariableTypeValueFieldSpec = (valuefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> FieldName_[bind(&classfield_holder, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (DefinedValue_[bind(&classfield_defaultref, qi::_val, qi::_1)]
                    | Value[bind(&classfield_defaultvalue, qi::_val, qi::_1)]))))[bind(&classfield_tp, qi::_val, fkind_VariableTypeValueFieldSpec)];


            FixedTypeValueSetFieldSpec = (valuesetfieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> Type[bind(&classfield_holder_ft, qi::_val, qi::_1, false)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (DefinedType_[bind(&classfield_defaultref, qi::_val, qi::_1)] | ValueSet[bind(&classfield_defaultset, qi::_val, qi::_1)]))));


            VariableTypeValueSetFieldSpec = (valuesetfieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> FieldName_[bind(&classfield_holder, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (DefinedType_[bind(&classfield_defaultref, qi::_val, qi::_1)]
                    | ValueSet[bind(&classfield_defaultset, qi::_val, qi::_1)]))))[bind(&classfield_tp, qi::_val, fkind_VariableTypeValueSetFieldSpec)];


            /*qi::rule<str_iterator, classfield_type(), skip_cmt_type> ObjectFieldSpec;
            qi::rule<str_iterator, classfield_type(), skip_cmt_type> ObjectSetFieldSpec;*/


            WithSyntaxSpec = qi::omit[ qi::lexeme[WITH_ >> +qi::blank >> SYNTAX_]] >> SyntaxList;
            SyntaxList = qi::omit[qi::lit("{")] >> TokenOrGroupSpec >> qi::omit[qi::lit("}")];
            TokenOrGroupSpec = +(AiasTokenOToken | RequiredToken | OptionalToken | TokenOToken);
            OptionalGroup = qi::omit[qi::lit("[")] >> TokenOrGroupSpec >> qi::omit[qi::lit("]")];
            TokenOToken = OptionalGroup[bind(&classsyntax_group, qi::_val, qi::_1)];
            AiasTokenOToken = (SyntaxField_ >> OptionalGroup)[bind(&classsyntax_agroup, qi::_val, qi::_1, qi::_2)];
            RequiredToken = -(SyntaxField_[bind(&classsyntax_alias, qi::_val, qi::_1)]) >> PrimitiveFieldName_[bind(&classsyntax_field, qi::_val, qi::_1)];
            OptionalToken %= (qi::omit[qi::lit("[")] >> RequiredToken >> qi::omit[qi::lit("]")])[bind(&classsyntax_optional, qi::_val)];










            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////              

            ObjectDefn = DefaultSyntax | DefinedSyntax;


            DefaultSyntax = qi::omit[qi::lit("{")] >> FieldSettings[bind(&object_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")];

            FieldSettings = FieldSetting % qi::omit[qi::lit(",")];

            FieldSetting = PrimitiveFieldName_[bind(&objectfield_field, qi::_val, qi::_1)] >> (Type[bind(&objectfield_typeset, qi::_val, qi::_1)] | Value[bind(&objectfield_value, qi::_val, qi::_1)] | ValueSet[bind(&objectfield_valueset, qi::_val, qi::_1)]);








            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectSetAssignment grammar
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            ObjectSet = qi::omit[qi::lit("{")]
                    >> oElementSetSpecs
                    >> qi::omit[qi::lit("}")];




            oElementSetSpecs %= oElementSetSpec >>
                    -(qi::omit[qi::lit(",")] >> oExtention >>
                    -(qi::omit[qi::lit(",")] >> oElementSetSpec));


            oUElems %= ((qi::omit[(UNION_ | qi::lit("|"))]
                    >> oUnions)[ bind(&object_element_vector::push_back, qi::_val, OBJECT_UNION) ]);

            oElementSetSpec
                    = oUnions[bind(&push_objects, qi::_val, qi::_1)] >> *(oUElems[bind(&push_objects, qi::_val, qi::_1)]);

            oIElems %= (qi::omit[(INTERSECTION_ | qi::lit("^"))]
                    >> oIntersections)[bind(&object_element_vector::push_back, qi::_val, OBJECT_INTERSECTION)];

            oUnions =
                    oIntersections[bind(&push_objects, qi::_val, qi::_1)] >> *(oIElems[bind(&push_objects, qi::_val, qi::_1)]);


            oEElems %= (qi::omit[EXCEPT_ ]
                    >> oExclusions)[bind(&object_element_vector::push_back, qi::_val, OBJECT_EXCEPT)];

            oIntersections =
                    oExclusions[bind(&push_objects, qi::_val, qi::_1)] >> *(oEElems[bind(&push_objects, qi::_val, qi::_1)]);


            oAElems %=
                    (qi::omit[qi::lit("ALL EXCEPT")]
                    >> oExclusions)[bind(&object_element_vector::push_back, qi::_val, OBJECT_ALLEXCEPT)];

            oExclusions
                    = oElement
                    | qi::omit[qi::lit("(")]
                    >> oElementSetSpec
                    >> qi::omit[ qi::lit(")")]
                    | oAElems
                    ;

            oExtention = qi::lit("...")[qi::_val = OBJECT_EXTENTION];

            oElement = DefaultSyntax[qi::_val = qi::_1 ] | DefinedObject_[bind(&object_reff, qi::_val, qi::_1)];




        }

    }
}