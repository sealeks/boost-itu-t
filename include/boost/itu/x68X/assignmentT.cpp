//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {

        void Modules_grammar::initT() {

            Tag = qi::omit[qi::lit("[")]
                    >> -(EncodingReferenceDefault[bind(&tag_encoding, qi::_val, qi::_1)] >> qi::omit[qi::lit(":")])
                    >> -(Class[bind(&tag_class, qi::_val, qi::_1)])
                    >> (pos_number_str | DefinedValue_)[bind(&tag_number, qi::_val, qi::_1)]
                    >> qi::omit[qi::lit("]")]
                    >> -(Rule[bind(&tag_rule, qi::_val, qi::_1)]);

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  UnknownTCAssigment grammar (Type or Class)
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////             

            UnknownReferencedTC = UnknownTCValueSetFromObjects | 
                    UnknownTCFromObject | UnknownTC;

            UnknownTC = DefinedType_[bind(&unknown_tc_refference, qi::_val, qi::_1)] 
                    >> -(ActualParameters[bind(&unknown_tc_parameters, qi::_val, qi::_1)]);

            UnknownTCFromObject = LittleFromObject_[bind(&unknown_tc_refference, qi::_val, qi::_1)]; 

            UnknownTCValueSetFromObjects = BigFromObjects_[bind(&unknown_tc_refference, qi::_val, qi::_1)]; 

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  TypeAssigment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            Type = BuitinType | TaggedType | ReferencedType;

            GovernorType = SimpleValueSetFromObjects | SimpleTypeFromObject | BuitinType | StrictDefinedType;

            NamedType = (identifier_ >> Type)[bind(&type_named, qi::_val, qi::_1, qi::_2)];

            TypeA = Type[bind(&typea_type, qi::_val, qi::_1) ];

            StrictType = BuitinType | TaggedType | ConstraintReferencedType | StrictDefinedType;

            ConstraintReferencedType = SimpleReferencedType[ qi::_val = qi::_1 ] >> Constraints[bind(&type_constraints, qi::_val, qi::_1)];

            BuitinType = SimpleType | IntegerType | EnumeratedType | BitStringType
                    | SelectionType | SequenceOfType | SetOfType | SequenceType 
                    | ChoiceType | SetType | InstanceOfType;

            TaggedType = (Tag
                    >> Type)[bind(&type_tagged, qi::_val, qi::_1, qi::_2)];

            SimpleTaggedType = (Tag
                    >> SimpleType)[bind(&type_tagged, qi::_val, qi::_1, qi::_2)];

            ObjectClassFieldType = ObjectClassFieldType_[bind(&type_objectfield, qi::_val, qi::_1)]
                    >> -(ActualParameters[bind(&type_parameters, qi::_val, qi::_1)]);

            SimpleTypeFromObject = LittleFromObject_[bind(&type_fromobject, qi::_val, qi::_1)]; 

            SimpleValueSetFromObjects = BigFromObjects_[bind(&type_fromobjectset, qi::_val, qi::_1)];       

            SimpleDefinedType = DefinedType_[bind(&type_refference, qi::_val, qi::_1)];

            DefinedType = DefinedType_[bind(&type_refference, qi::_val, qi::_1)] 
                    >> -(ActualParameters[bind(&type_parameters, qi::_val, qi::_1)]);

            StrictDefinedType = DefinedType_strict[bind(&type_refference, qi::_val, qi::_1)] 
                    >> -(ActualParameters[bind(&type_parameters, qi::_val, qi::_1)]);

            InstanceOfType = qi::omit[qi::lexeme[INSTANCE_ >> +qi::space >> OF_]]
                    >> DefinedObjectClass_[bind(&type_instance, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            SimpleReferencedType = ObjectClassFieldType | SimpleTypeFromObject
                    | SimpleValueSetFromObjects | DefinedType;

            ReferencedType = SimpleReferencedType[ qi::_val = qi::_1 ] 
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            SimpleType = ((qi::lexeme[OCTET_ >> +qi::space >> STRING_])[bind(&type_deff, qi::_val, t_OCTET_STRING)]
                    | (qi::lexeme[CHARACTER_ >> +qi::space >> STRING_])[bind(&type_deff, qi::_val, t_CHARACTER_STRING)]
                    | (qi::lexeme[EMBEDDED_ >> +qi::space >> PDV_])[bind(&type_deff, qi::_val, t_EMBEDDED_PDV)]
                    | (qi::lexeme[OBJECT_ >> +qi::space >> IDENTIFIER_])[bind(&type_deff, qi::_val, t_OBJECT_IDENTIFIER)]
                    | (qi::lexeme[DATE_ >> +qi::space >> TIME_])[bind(&type_deff, qi::_val, t_DATE_TIME)]
                    | (distinct(qi::alnum | '-')[simple_typer[bind(&type_deff, qi::_val, qi::_1)]])
                    )
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            IntegerType = INTEGER_[bind(&type_deff, qi::_val, t_INTEGER)]
                    >> -NamedNumberList[bind(&type_deffinit, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            EnumeratedType = ENUMERATED_[bind(&type_deff, qi::_val, t_ENUMERATED)]
                    >> -Enumerations[bind(&type_deffinit, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);

            BitStringType = (qi::lexeme[BIT_ >> +qi::space >> STRING_])[bind(&type_deff, qi::_val, t_BIT_STRING)]
                    >> -NameBitList[bind(&type_deffinit, qi::_val, qi::_1)]
                    >> -(Constraints[bind(&type_constraints, qi::_val, qi::_1)]);




            SequenceOfType = (SEQUENCE_
                    >> -((SizeConstraints[bind(&type_constraints, qi::_val, qi::_1)]) 
                    | (Constraints[bind(&type_constraints, qi::_val, qi::_1)]))
                    >> OF_)[bind(&type_deff, qi::_val, t_SEQUENCE_OF)]
                    >> (TypeA | NamedType)[bind(&type_push, qi::_val, qi::_1) ];

            SetOfType = (SET_
                    >> -((SizeConstraints[bind(&type_constraints, qi::_val, qi::_1)]) 
                    | (Constraints[bind(&type_constraints, qi::_val, qi::_1)]))
                    >> OF_)[bind(&type_deff, qi::_val, t_SET_OF)]
                    >> (TypeA | NamedType)[bind(&type_push, qi::_val, qi::_1) ];





            ExceptionSpec = qi::omit[qi::lit("!")] >> (pos_number_str[bind(&type_exceptnumber, qi::_val, qi::_1) ]
                    | DefinedValue_[bind(&type_exceptidetifier, qi::_val, qi::_1) ]
                    | (TypeA[qi::_val = qi::_1 ] >> qi::omit[ qi::lit(":")] >> Value[bind(&type_exceptvalue, qi::_val, qi::_1) ])
                    );


            //    


            ComponentType %= ((qi::omit[qi::lexeme[COMPONENTS_ >> +qi::space >> OF_]] >> TypeA)[bind(&type_marker, qi::_val, mk_components_of)]
                    | (NamedType >> qi::omit[OPTIONAL_])[bind(&type_marker, qi::_val, mk_optional)]
                    | ((NamedType >> qi::omit[DEFAULT_])[bind(&type_marker, qi::_val, mk_default)] >> qi::omit[Value[bind(&type_defaultvalue, qi::_val, qi::_1)]])
                    | NamedType);

            ComponentTypeList = (ComponentType % qi::omit[qi::lit(",")]);

            ExtensionAdditionGroup1 = qi::omit[qi::lit("[[")
                    >> -(pos_number_str
                    >> qi::lit(":"))]
                    >> ComponentTypeList
                    >> qi::omit[qi::lit("]]")];

            ExtensionAdditionGroup = ExtensionAdditionGroup1 | ComponentTypeList;

            ExtensionAddition = qi::omit[qi::lit(",")] >> (ExtensionAdditionGroup | ComponentType);

            ExtensionAdditions = qi::omit[qi::lit(",")] >> ExtensionAdditionGroup >> -(ExtensionAddition);

            Extension = qi::lit("...")[qi::_val = extention_type_assignment ];

            ExtensionAndException = Extension >> -ExceptionSpec;

            ExtensionEndMarker = qi::omit[qi::lit(",")] >> Extension;

            ComponentTypeListsKrn = ExtensionAndException 
                    >> -ExtensionAdditions >> -ExtensionEndMarker;

            ComponentTypeListsEx = ExtensionAndException 
                    >> -ExtensionEndMarker;

            ComponentTypeLists = -ComponentTypeList >> -qi::lit(",") 
                    >> -ComponentTypeListsKrn >> -(qi::lit(",") >> ComponentTypeList);

            RootComponentTypeLists = ComponentTypeListsEx | ComponentTypeLists;


            AlternativeTypeList = (NamedType % qi::omit[qi::lit(",")]);

            RootAlternativeTypeList = AlternativeTypeList;

            ExtensionAdditionAlternativesGroup1 = qi::omit[qi::lit("[[")
                    >> -(pos_number_str
                    >> qi::lit(":"))]
                    >> AlternativeTypeList
                    >> qi::omit[qi::lit("]]")];

            ExtensionAdditionAlternativesGroup = ExtensionAdditionAlternativesGroup1 | AlternativeTypeList;

            ExtensionAdditionAlternative = qi::omit[qi::lit(",")] 
                    >> (ExtensionAdditionAlternativesGroup | NamedType);

            ExtensionAdditionAlternatives = qi::omit[qi::lit(",")] 
                    >> ExtensionAdditionAlternativesGroup >> -(ExtensionAdditionAlternative);

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



        }

    }
}