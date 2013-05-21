//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {


        // Type_grammar

        void Type_grammar::init() {

            start_rule = Type[bind(&self_type::typeset, *this, qi::_val, qi::_1)];

            NamedType = identifier_[bind(&self_type::identifier, *this, qi::_val, qi::_1)]
                    >> Type[bind(&self_type::type, *this, qi::_val, qi::_1)];

            DefinedType = DefinedType_[bind(&self_type::refference, *this, qi::_val, qi::_1)];

            InstanceOfType = qi::omit[qi::lexeme[INSTANCE_ >> +qi::blank >> OF_]] >> DefinedObjectClass_[bind(&self_type::instancetype, *this, qi::_val, qi::_1)];

            ReferencedType = DefinedType;

            SimpleType = ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&self_type::defftype, *this, qi::_val, t_OCTET_STRING)]
                    | (qi::lexeme[CHARACTER_ >> +qi::blank >> STRING_])[bind(&self_type::defftype, *this, qi::_val, t_CHARACTER_STRING)]
                    | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&self_type::defftype, *this, qi::_val, t_EMBEDDED_PDV)]
                    | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&self_type::defftype, *this, qi::_val, t_OBJECT_IDENTIFIER)]
                    | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&self_type::defftype, *this, qi::_val, t_DATE_TIME)]
                    | simple_typer[bind(&self_type::defftype, *this, qi::_val, qi::_1)]
                    );

            IntegerType = INTEGER_[bind(&self_type::defftype, *this, qi::_val, t_INTEGER)]
                    >> -NamedNumberList[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];

            EnumeratedType = ENUMERATED_[bind(&self_type::defftype, *this, qi::_val, t_ENUMERATED)]
                    >> -Enumerations[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];

            BitStringType = qi::lexeme[BIT_ >> +qi::blank >> STRING_[bind(&self_type::defftype, *this, qi::_val, t_BIT_STRING)]]
                    >> -NameBitList[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];


            SequenceOfType = (qi::lexeme[SEQUENCE_ >> +qi::blank >> OF_])[bind(&self_type::defftype, *this, qi::_val, t_SEQUENCE_OF)]
                    >> (Type | NamedType)[bind(&self_type::push_component, *this, qi::_val, qi::_1) ];

            SetOfType = (qi::lexeme[SET_ >> +qi::blank >> OF_])[bind(&self_type::defftype, *this, qi::_val, t_SET_OF)]
                    >> (Type | NamedType)[bind(&self_type::push_component, *this, qi::_val, qi::_1) ];





            ExceptionSpec = qi::omit[qi::lit("!")] >> (pos_number_str[bind(&type_assignment::exceptnumber, qi::_val, qi::_1) ]
                    | DefinedValue_[bind(&type_assignment::exceptidetifier, qi::_val, qi::_1) ]
                    | (Type[qi::_val = qi::_1 ] >> qi::omit[ qi::lit(":")] >> Value[bind(&type_assignment::exceptvalue, qi::_val, qi::_1) ])
                    );


            //    


            ComponentType %= ((qi::omit[qi::lexeme[COMPONENTS_ >> +qi::blank >> OF_]] >> Type)[bind(&type_assignment::operator(), qi::_val, mk_components_of)]
                    | (NamedType >> qi::omit[OPTIONAL_])[bind(&type_assignment::operator(), qi::_val, mk_optional)]
                    | ((NamedType >> qi::omit[DEFAULT_])[bind(&type_assignment::operator(), qi::_val, mk_default)] >> qi::omit[Value[bind(&type_assignment::defaultvalue, qi::_val, qi::_1)]])
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



            /*ComponentTypeLists ::= RootComponentTypeList
             | RootComponentTypeList ","  ExtensionAndException ExtensionAdditions -ExtensionEndMarker
            |                                                     ExtensionAndException ExtensionAdditions -ExtensionEndMarker  
             | RootComponentTypeList "," ExtensionAndException ExtensionAdditions ExtensionEndMarker "," RootComponentTypeList
             |                                                   ExtensionAndException ExtensionAdditions ExtensionEndMarker "," RootComponentTypeList*/

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



            SelectionType = identifier_[bind(&self_type::identifier, *this, qi::_val, qi::_1)]
                    >> qi::lit("<")
                    >> Type[bind(&self_type::type_select, *this, qi::_val, qi::_1)];


            SequenceType = SEQUENCE_[bind(&self_type::defftype, *this, qi::_val, t_SEQUENCE)]
                    >> qi::lit("{")
                    >> -RootComponentTypeLists [bind(&self_type::push_components, *this, qi::_val, qi::_1) ]
                    >> qi::lit("}");


            SetType = SET_[bind(&self_type::defftype, *this, qi::_val, t_SET)]
                    >> qi::lit("{")
                    >> -RootComponentTypeLists[bind(&self_type::push_components, *this, qi::_val, qi::_1) ]
                    >> qi::lit("}");

            ChoiceType = CHOICE_[bind(&self_type::defftype, *this, qi::_val, t_CHOICE)]
                    >> qi::lit("{")
                    >> -(AlternativeTypeLists[bind(&self_type::push_components, *this, qi::_val, qi::_1) ])
                    >> qi::lit("}");

            BuitinType = SimpleType | IntegerType | EnumeratedType | BitStringType | SelectionType | SequenceOfType | SetOfType | SequenceType | ChoiceType | SetType | InstanceOfType;

            Type = BuitinType | TaggedType | DefinedType;

            TaggedType = Tag[bind(&self_type::tagset, *this, qi::_val, qi::_1)]
                    >> Type[bind(&self_type::for_taggedtype, *this, qi::_val, qi::_1)];

        }


        // Element_grammar

        void Element_grammar::init() {

            start_rule = ContainedSubtype | PatternConstraint | ValueRange | SingleValue ;
            
            ContainedSubtype = INCLUDES_ >> Type[bind(&constraint_element::subtypeset, qi::_val, qi::_1)];
            
            PatternConstraint =PATTERN_ >> CStringValue[bind(&constraint_element::patterntypeset,  qi::_val, qi::_1)];            

            SingleValue = Value[bind(&constraint_element::singleset,  qi::_val, qi::_1)];

            ValueRange = ((MIN_[bind(&constraint_element::fromtype,  qi::_val, min_range)]
                    | IntegerValue[bind(&constraint_element::fromset,  qi::_val, qi::_1)])
                    >> -(qi::lit("<")[bind(&constraint_element::fromtype,  qi::_val, open_range)])
                    >> qi::lit("..")
                    >> -(qi::lit("<")[bind(&constraint_element::totype,  qi::_val, open_range)])
                    >> (MAX_[bind(&constraint_element::totype,  qi::_val, max_range)]
                    | IntegerValue[bind(&constraint_element::toset,  qi::_val, qi::_1)]))
                    |
                    ((MIN_[bind(&constraint_element::fromtype,  qi::_val, min_range)]
                    | RealValue[bind(&constraint_element::fromset,  qi::_val, qi::_1)])
                    >> -(qi::lit("<")[bind(&constraint_element::fromtype,  qi::_val, open_range)])
                    >> qi::lit("..")
                    >> -(qi::lit("<")[bind(&constraint_element::totype,  qi::_val, open_range)])
                    >> (MAX_[bind(&constraint_element::totype,  qi::_val, max_range)]
                    | RealValue[bind(&constraint_element::toset,  qi::_val, qi::_1)]))
                    |
                    ((MIN_[bind(&constraint_element::fromtype,  qi::_val, min_range)]
                    | CStringValue[bind(&constraint_element::fromset,  qi::_val, qi::_1)])
                    >> -(qi::lit("<")[bind(&constraint_element::fromtype,  qi::_val, open_range)])
                    >> qi::lit("..")
                    >> -(qi::lit("<")[bind(&constraint_element::totype,  qi::_val, open_range)])
                    >> (MAX_[bind(&constraint_element::totype,  qi::_val, max_range)]
                    | CStringValue[bind(&constraint_element::toset,  qi::_val, qi::_1)]));
            

                    
        }       
        
        
        // Elements_grammar

        void Elements_grammar::init() {
            
            expression
                    = termi[bind(&self_type::pushs, *this, qi::_val, qi::_1)]
                    >> *(((qi::lit("|") | qi::lit("UNION")) 
                    >> termi[bind(&self_type::pushs, *this, qi::_val, qi::_1)])[bind(&self_type::push, *this , qi::_val, CONSTRAINT_UNION)]
                   )
                    ;

            termi =
                    terme[bind(&self_type::pushs, *this, qi::_val, qi::_1)]
                    >> *(((qi::lit("^") | qi::lit("INTERSECTION")) 
                    >> terme[bind(&self_type::pushs, *this, qi::_val, qi::_1)])[bind(&self_type::push, *this, qi::_val, CONSTRAINT_INTERSECTION)]
                    )
                    ;

            terme =
                    factor[bind(&self_type::pushs, *this, qi::_val, qi::_1)]
                    >> *((qi::lit("EXCEPT") 
                    >> factor[bind(&self_type::pushs, *this, qi::_val, qi::_1)])[bind(&self_type::push, *this, qi::_val, CONSTRAINT_EXCEPT)]
                    )
                    ;

            factor
                    = Element[bind(&self_type::push, *this, qi::_val, qi::_1)]
                    | qi::lit("(") 
                    >> expression[bind(&self_type::pushs, *this, qi::_val, qi::_1)] >> qi::lit(")")
                    | (qi::lit("ALL EXCEPT") 
                    >> factor[bind(&self_type::pushs, *this, qi::_val, qi::_1)])[bind(&self_type::push, *this, qi::_val, CONSTRAINT_ALLEXCEPT)]
                    ;
        }


        // TypeAssignment_grammar

        void TypeAssignment_grammar::init() {

            start_rule = typereference_[bind(&self_type::typereffrence, *this, qi::_val, qi::_1)]
                    >> qi::lexeme[qi::lit("::=")]
                    >> Type[bind(&self_type::type, *this, qi::_val, qi::_1)];
        }



        // ValueAssignment_grammar

        void ValueAssignment_grammar::init() {

            start_rule = valuereference_[bind(&self_type::valuereference, *this, qi::_val, qi::_1)]
                    >> Type[bind(&self_type::type, *this, qi::_val, qi::_1)]
                    >> qi::lexeme[qi::lit("::=")]
                    >> Value[bind(&self_type::value, *this, qi::_val, qi::_1)];
        }


        // Assignment_grammar

        void Assignments_grammar::init() {
            start_rule = *(TypeAssignment | ValueAssignment);

        }



    }
}