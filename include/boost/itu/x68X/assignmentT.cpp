//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {

        void Modules_grammar::initT() {


            Tag = qi::omit[qi::lit("[")]
                    >> -(EncodingReferenceDefault[phx::bind(&tag_encoding, sprt::_val, sprt::_1)] 
                    >> qi::omit[qi::lit(":")])
                    >> -(Class[phx::bind(&tag_class, sprt::_val, sprt::_1)])
                    >> (pos_number_str | DefinedValue_)[phx::bind(&tag_number, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lit("]")]
                    >> -(Rule[phx::bind(&tag_rule, sprt::_val, sprt::_1)]);


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  UnknownTCAssigment grammar (Type or Class)
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////             

            UnknownReferencedTC = UnknownTCValueSetFromObjects |
                    UnknownTCFromObject | UnknownTC;

            UnknownTC = DefinedType_[phx::bind(&unknown_tc_refference, sprt::_val, sprt::_1)]
                    >> -(ActualParameters[phx::bind(&unknown_tc_parameters, sprt::_val, sprt::_1)]);

            UnknownTCFromObject = LittleFromObject_[phx::bind(&unknown_tc_refference, sprt::_val, sprt::_1)];

            UnknownTCValueSetFromObjects = BigFromObjects_[phx::bind(&unknown_tc_refference, sprt::_val, sprt::_1)];


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  TypeAssigment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            Type = BuitinType | TaggedType | ReferencedType;

            TypeNA = BuitinType | TaggedType | ReferencedTypeNA;

            GovernorType = SimpleValueSetFromObjects | SimpleTypeFromObject
                    | BuitinType | StrictDefinedType;

            NamedType = (identifier_ >> Type)[phx::bind(&type_named, sprt::_val, sprt::_1, sprt::_2)];

            TypeA = Type[phx::bind(&typea_type, sprt::_val, sprt::_1) ];

            StrictType = BuitinType | TaggedType | ConstraintReferencedType | ObjectClassFieldType
                    | StrictDefinedType | SimpleTypeFromObject | SimpleValueSetFromObjects;

            ConstraintReferencedType = SimpleReferencedType[ sprt::_val = sprt::_1 ] 
                    >> Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)];

            BuitinType = SimpleType | IntegerType | EnumeratedType | BitStringType
                    | SelectionType | SequenceOfType | SetOfType | SequenceType
                    | ChoiceType | SetType | InstanceOfType;

            TaggedType = (Tag
                    >> Type)[phx::bind(&type_tagged, sprt::_val, sprt::_1, sprt::_2)];

            SimpleTaggedType = (Tag
                    >> SimpleType)[phx::bind(&type_tagged, sprt::_val, sprt::_1, sprt::_2)];

            ObjectClassFieldType = (DefinedObjectClass_
                    >> qi::omit[qi::string(".") >> (*qi::space)] 
                    >> FieldName_)[phx::bind(&type_objectfield, sprt::_val, sprt::_1,sprt::_2)]
                    >> -(ActualParameters[phx::bind(&type_parameters, sprt::_val, sprt::_1)]);      

            SimpleTypeFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&type_fromobject, sprt::_val, sprt::_1, sprt::_2)];
                    
            SimpleTypeFromObjectNA = (SimpleDefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&type_fromobject, sprt::_val, sprt::_1, sprt::_2)];                    

            SimpleValueSetFromObjects = (DefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&type_fromobjectset, sprt::_val, sprt::_1, sprt::_2)];
                    
            SimpleValueSetFromObjectsNA = (SimpleDefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&type_fromobjectset, sprt::_val, sprt::_1, sprt::_2)];                    

            SimpleDefinedType = DefinedType_[phx::bind(&type_refference, sprt::_val, sprt::_1)];

            DefinedType = DefinedType_[phx::bind(&type_refference, sprt::_val, sprt::_1)]
                    >> -(ActualParameters[phx::bind(&type_parameters, sprt::_val, sprt::_1)]);

            StrictDefinedType = DefinedType_strict[phx::bind(&type_refference, sprt::_val, sprt::_1)]
                    >> -(ActualParameters[phx::bind(&type_parameters, sprt::_val, sprt::_1)]);

            InstanceOfType = qi::omit[qi::lexeme[INSTANCE_ >> +qi::space >> OF_]]
                    >> DefinedObjectClass_[phx::bind(&type_instance, sprt::_val, sprt::_1)]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            SimpleReferencedType = ObjectClassFieldType | SimpleTypeFromObject
                    | SimpleValueSetFromObjects | DefinedType;

            SimpleReferencedTypeNA = ObjectClassFieldType | SimpleTypeFromObjectNA
                    | SimpleValueSetFromObjectsNA | SimpleDefinedType;

            ReferencedType = SimpleReferencedType[ sprt::_val = sprt::_1 ]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            ReferencedTypeNA = SimpleReferencedTypeNA[ sprt::_val = sprt::_1 ]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            SimpleType = ((qi::lexeme[OCTET_ >> +qi::space 
                    >> STRING_])[phx::bind(&type_deff, sprt::_val, t_OCTET_STRING)]
                    | (qi::lexeme[CHARACTER_ >> +qi::space 
                    >> STRING_])[phx::bind(&type_deff, sprt::_val, t_CHARACTER_STRING)]
                    | (qi::lexeme[EMBEDDED_ >> +qi::space 
                    >> PDV_])[phx::bind(&type_deff, sprt::_val, t_EMBEDDED_PDV)]
                    | (qi::lexeme[OBJECT_ >> +qi::space 
                    >> IDENTIFIER_])[phx::bind(&type_deff, sprt::_val, t_OBJECT_IDENTIFIER)]
                    | (qi::lexeme[DATE_TIME_])[phx::bind(&type_deff, sprt::_val, t_DATE_TIME)]
                    | (distinct(qi::alnum | '-')[simple_typer[phx::bind(&type_deff, sprt::_val, sprt::_1)]])
                    )
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            IntegerType = INTEGER_[phx::bind(&type_deff, sprt::_val, t_INTEGER)]
                    >> -NamedNumberList[phx::bind(&type_deffinit, sprt::_val, sprt::_1)]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            EnumeratedType = ENUMERATED_[phx::bind(&type_deff, sprt::_val, t_ENUMERATED)]
                    >> -Enumerations[phx::bind(&type_deffinit, sprt::_val, sprt::_1)]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            BitStringType = (qi::lexeme[BIT_ >> +qi::space 
                    >> STRING_])[phx::bind(&type_deff, sprt::_val, t_BIT_STRING)]
                    >> -NameBitList[phx::bind(&type_deffinit, sprt::_val, sprt::_1)]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);




            SequenceOfType = (SEQUENCE_
                    >> -((SizeConstraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)])
                    | (Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]))
                    >> OF_)[phx::bind(&type_deff, sprt::_val, t_SEQUENCE_OF)]
                    >> (TypeA | NamedType)[phx::bind(&type_push, sprt::_val, sprt::_1) ];

            SetOfType = (SET_
                    >> -((SizeConstraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)])
                    | (Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]))
                    >> OF_)[phx::bind(&type_deff, sprt::_val, t_SET_OF)]
                    >> (TypeA | NamedType)[phx::bind(&type_push, sprt::_val, sprt::_1) ];





            ExceptionSpec = qi::omit[qi::lit("!")] 
                    >> (pos_number_str[phx::bind(&type_exceptnumber, sprt::_val, sprt::_1) ]
                    | DefinedValue_[phx::bind(&type_exceptidetifier, sprt::_val, sprt::_1) ]
                    | (TypeA[sprt::_val = sprt::_1 ] >> qi::omit[ qi::lit(":")]
                    >> Value[phx::bind(&type_exceptvalue, sprt::_val, sprt::_1) ])
                    );


            //    


            ComponentType %= ((qi::omit[qi::lexeme[COMPONENTS_ >> +qi::space >> OF_]] 
                    >> TypeA)[phx::bind(&type_marker, sprt::_val, mk_components_of)]
                    | (NamedType >> qi::omit[OPTIONAL_])[phx::bind(&type_marker, sprt::_val, mk_optional)]
                    | ((NamedType >> qi::omit[DEFAULT_])[phx::bind(&type_marker, sprt::_val, mk_default)] 
                    >> qi::omit[Value[phx::bind(&type_defaultvalue, sprt::_val, sprt::_1)]])
                    | NamedType);

            ComponentTypeList = (ComponentType % qi::omit[qi::lit(",")]);

            ExtensionAdditionGroup1 = OpenGroup
                    >> qi::omit[-(pos_number_str
                    >> qi::lit(":"))]
                    >> ComponentTypeList
                    >> CloseGroup;

            ExtensionAdditionGroup = ExtensionAdditionGroup1 | ComponentTypeList;

            ExtensionAddition = qi::omit[qi::lit(",")] 
                    >> (ExtensionAdditionGroup | ComponentType);

            ExtensionAdditions = qi::omit[qi::lit(",")] >> ExtensionAdditionGroup
                    >> *(ExtensionAddition);

            Extension = qi::lit("...")[sprt::_val = extention_type_assignment ];
            OpenGroup = qi::lit("[[")[sprt::_val = groupbeg_type_assignment ];
            CloseGroup = qi::lit("]]")[sprt::_val = groupend_type_assignment ];           

            ExtensionAndException = Extension >> -ExceptionSpec;

            ExtensionEndMarker = qi::omit[qi::lit(",")] >> Extension;

            ComponentTypeListsKrn = ExtensionAndException
                    >> -ExtensionAdditions >> -ExtensionEndMarker;

            ComponentTypeListsEx = ExtensionAndException
                    >> -ExtensionEndMarker >> -(qi::omit[qi::lit(",")]  >> ComponentTypeList);

            ComponentTypeLists = -ComponentTypeList >> -qi::lit(",")
                    >> -ComponentTypeListsKrn >> -(qi::lit(",") >> ComponentTypeList);

            RootComponentTypeLists = ComponentTypeListsEx | ComponentTypeLists;


            AlternativeTypeList = (NamedType % qi::omit[qi::lit(",")]);

            ExtensionAdditionAlternativesGroup1 = OpenGroup
                    >> qi::omit[-(pos_number_str
                    >> qi::lit(":"))]
                    >> AlternativeTypeList
                    >> CloseGroup;

            ExtensionAdditionAlternativesGroup = ExtensionAdditionAlternativesGroup1 
                    | AlternativeTypeList;

            ExtensionAdditionAlternative = qi::omit[qi::lit(",")]
                    >> (ExtensionAdditionAlternativesGroup | NamedType);

            ExtensionAdditionAlternatives = qi::omit[qi::lit(",")]
                    >> ExtensionAdditionAlternativesGroup 
                    >> *(ExtensionAdditionAlternative);
            
            AlternativeTypeListsKrn = ExtensionAndException
                    >> -ExtensionAdditionAlternatives >> -ExtensionEndMarker;
            
            AlternativeTypeListsEx = ExtensionAndException
                    >> -ExtensionEndMarker >> -(qi::omit[qi::lit(",")]  >> AlternativeTypeList);            

            AlternativeTypeLists = -AlternativeTypeList >> -qi::lit(",")
                    >> -AlternativeTypeListsKrn >> -(qi::lit(",") >> AlternativeTypeList);

            RootAlternativeTypeLists = AlternativeTypeListsEx | AlternativeTypeLists;



            SelectionType = (identifier_
                    >> qi::omit[qi::lit("<")]
                    >> Type)[phx::bind(&type_select, sprt::_val, sprt::_1, sprt::_2)]
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);


            SequenceType = SEQUENCE_[phx::bind(&type_deff, sprt::_val, t_SEQUENCE)]
                    >> qi::lit("{")
                    >> -RootComponentTypeLists [phx::bind(&type_pushs, sprt::_val, sprt::_1) ]
                    >> qi::lit("}")
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);


            SetType = SET_[phx::bind(&type_deff, sprt::_val, t_SET)]
                    >> qi::lit("{")
                    >> -RootComponentTypeLists[phx::bind(&type_pushs, sprt::_val, sprt::_1) ]
                    >> qi::lit("}")
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);

            ChoiceType = CHOICE_[phx::bind(&type_deff, sprt::_val, t_CHOICE)]
                    >> qi::lit("{")
                    >> -RootAlternativeTypeLists[phx::bind(&type_pushs, sprt::_val, sprt::_1) ]
                    >> qi::lit("}")
                    >> -(Constraints[phx::bind(&type_constraints, sprt::_val, sprt::_1)]);



        }

    }
}