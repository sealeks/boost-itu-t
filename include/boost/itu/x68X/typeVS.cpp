//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {



        // Type_grammar

        void Assignments_grammar::initVS() {


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

            UserDefinedConstraintParameters = qi::omit[qi::lit("{")] >> -(UserDefinedConstraintParameter_ % qi::omit[qi::lit(",")]) >>  qi::omit[qi::lit("}")];

            UserDefinedConstraint =
                    (qi::omit[qi::lexeme[CONSTRAINED_ >> +qi::blank >> BY_]])[bind(&constraint_tp, qi::_val, cns_UserDefinedConstraint)]
                    >> UserDefinedConstraintParameters[bind(&constraint_userdef, qi::_val, qi::_1)];

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





        }

    }
}