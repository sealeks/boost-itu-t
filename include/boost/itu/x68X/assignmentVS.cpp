//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {



        // Type_grammar

        void Modules_grammar::initVS() {


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  Constraint grammar
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            ValueSet = ValueSetFromObject | ValueSetFromObjects | StrictValueSet | ParameterizedValueSet;

            ValueSetNA = ValueSetFromObjectNA | ValueSetFromObjectsNA | StrictValueSet | SimpleValueSet;

            SimpleValueSet = DefinedType_[phx::bind(&valueset_defined, sprt::_val, sprt::_1)];

            ParameterizedValueSet = DefinedType_[phx::bind(&valueset_defined, sprt::_val, sprt::_1)]
                    >> -(ActualParameters[phx::bind(&valueset_parameters, sprt::_val, sprt::_1)]);

            ValueSetFromObject = (DefinedObject
                    >> qi::omit[qi::string(".") >> (*qi::space)]
                    >> FieldName_)[phx::bind(&valueset_fromobject, sprt::_val, sprt::_1, sprt::_2)];

            ValueSetFromObjectNA = (SimpleDefinedObject
                    >> qi::omit[qi::string(".") >> (*qi::space)]
                    >> FieldName_)[phx::bind(&valueset_fromobject, sprt::_val, sprt::_1, sprt::_2)];

            ValueSetFromObjects = (DefinedObjectSet
                    >> qi::omit[qi::string(".") >> (*qi::space)]
                    >> FieldName_)[phx::bind(&valueset_fromobjects, sprt::_val, sprt::_1, sprt::_2)];

            ValueSetFromObjectsNA = (SimpleDefinedObjectSet
                    >> qi::omit[qi::string(".") >> (*qi::space)]
                    >> FieldName_)[phx::bind(&valueset_fromobjects, sprt::_val, sprt::_1, sprt::_2)];

            StrictValueSet = ValueSetdecl[phx::bind(&valueset_set, sprt::_val, sprt::_1)];

            ValueSetdecl = qi::omit[qi::lit("{")]
                    >> ElementSetSpecs
                    >> qi::omit[qi::lit("}")];

            Constraints = +Constraint;

            SizeConstraints = SizeConstraint[phx::bind(&pushs_constraint, sprt::_val, sprt::_1)];

            Constraint %= qi::omit[qi::lit("(")] >> ConstraintSpec
                    >> -ExceptionSpecConstraints
                    >> qi::omit[qi::lit(")")];

            ConstraintSpec = GeneralConstraint | ElementSetSpecs;

            ElementSetSpecs %= ElementSetSpec >>
                    -(qi::omit[qi::lit(",")] >> Extention >>
                    -(qi::omit[qi::lit(",")] >> ElementSetSpec));

            GeneralConstraintdecl = (UserDefinedConstraint
                    | ContentsConstraintTypeValue
                    | ContentsConstraintValue
                    | ContentsConstraintType
                    | ComponentRelationConstraint | SimpleTableConstraint);

            GeneralConstraint = GeneralConstraintdecl[ phx::bind(&push_constraints, sprt::_val, sprt::_1) ];




            UElems %= ((qi::omit[(UNION_ | qi::lit("|"))]
                    >> Unions)[ phx::bind(&push_constraint, sprt::_val, CONSTRAINT_UNION) ]);

            ElementSetSpec
                    = Unions[phx::bind(&push_constraints, sprt::_val, sprt::_1)]
                    >> *(UElems[phx::bind(&push_constraints, sprt::_val, sprt::_1)]);

            IElems %= (qi::omit[(INTERSECTION_ | qi::lit("^"))]
                    >> Intersections)
                    [phx::bind(&push_constraint, sprt::_val, CONSTRAINT_INTERSECTION)];

            Unions =
                    Intersections[phx::bind(&push_constraints, sprt::_val, sprt::_1)]
                    >> *(IElems[phx::bind(&push_constraints, sprt::_val, sprt::_1)]);


            EElems %= (qi::omit[EXCEPT_ ]
                    >> Exclusions)[phx::bind(&push_constraint, sprt::_val, CONSTRAINT_EXCEPT)];

            Intersections = Exclusions[phx::bind(&push_constraints, sprt::_val, sprt::_1)] 
                    >> *(EElems[phx::bind(&push_constraints, sprt::_val, sprt::_1)]);


            AElems %=
                    (qi::omit[ALL_ >> (+qi::space) >> EXCEPT_]
                    >> Exclusions)[phx::bind(&push_constraint, sprt::_val, CONSTRAINT_ALLEXCEPT)];

            Exclusions
                    = Element
                    | qi::omit[qi::lit("(")]
                    >> ElementSetSpec
                    >> qi::omit[ qi::lit(")")]
                    | AElems
                    ;

            Extention = qi::lit("...")[sprt::_val = CONSTRAINT_EXTENTION];

            ContainedSubtype = INCLUDES_ >> Type[phx::bind(&constraint_subtype, sprt::_val, sprt::_1)];

            PatternConstraint = PATTERN_ >> CStringValue[phx::bind(&constraint_patterntype, sprt::_val, sprt::_1)];

            SingleValue = Value[phx::bind(&constraint_singlevalue, sprt::_val, sprt::_1)];
            
            ConstraintFromObjects =  (DefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&constraint_fromobjects, sprt::_val, sprt::_1, sprt::_2)];
                    
            ConstraintFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&constraint_fromobject, sprt::_val, sprt::_1, sprt::_2)];            

            PropertySettings = SETTINGS_ 
                    >> (CStringValue | DefinedValue)[phx::bind(&constraint_property, sprt::_val, sprt::_1)];

            ValueRange = (MIN_[phx::bind(&constraint_fromtype, sprt::_val, min_range)]
                    | (RangeValue)[phx::bind(&constraint_from, sprt::_val, sprt::_1)])
                    >> -(qi::lit("<")[phx::bind(&constraint_fromtype, sprt::_val, open_range)])
                    >> qi::lit("..")
                    >> -(qi::lit("<")[phx::bind(&constraint_totype, sprt::_val, open_range)])
                    >> (MAX_[phx::bind(&constraint_totype, sprt::_val, max_range)]
                    | (RangeValue)[phx::bind(&constraint_to, sprt::_val, sprt::_1)]);




            TypeConstraint = BuitinType[phx::bind(&constraint_typeset, sprt::_val, sprt::_1)];  /// ??

            SimpleElement = ConstraintFromObjects| ConstraintFromObject
                    | ContainedSubtype | PatternConstraint
                    | PropertySettings | ValueRange | SingleValue | TypeConstraint;

            SizeConstraint = qi::omit[SIZE_]
                    >> Constraint[phx::bind(&constraint_size, sprt::_val, sprt::_1)];

            PermittedAlphabet = qi::omit[FROM_]
                    >> Constraint[phx::bind(&constraint_alphabet, sprt::_val, sprt::_1)];

            SingleTypeConstraint = qi::omit[qi::lexeme[WITH_ >> +qi::space >> COMPONENT_]]
                    >> Constraint[phx::bind(&constraint_singletype, sprt::_val, sprt::_1)];

            NamedConstraint = identifier_[phx::bind(&constraint_identifier, sprt::_val, sprt::_1)]
                    >> -Constraint[phx::bind(&constraint_namedtype, sprt::_val, sprt::_1)]
                    >> -(PRESENT_[phx::bind(&constraint_marker, sprt::_val, cmk_present)]
                    | ABSENT_[phx::bind(&constraint_marker, sprt::_val, cmk_absent)]
                    | OPTIONAL_[phx::bind(&constraint_marker, sprt::_val, cmk_optional)]);

            FullSpecification = qi::omit[qi::lit("{")]
                    >> -(Extention >> qi::omit[qi::lit(",")])
                    >> (NamedConstraint % qi::omit[qi::lit(",")])
                    >> qi::omit[qi::lit("}")];

            MultipleTypeConstraints = qi::omit[qi::lexeme[WITH_ >> +qi::space >> COMPONENTS_]]
                    >> FullSpecification[phx::bind(&constraint_multitype, sprt::_val, sprt::_1)];

            Element = SizeConstraint | PermittedAlphabet
                    | MultipleTypeConstraints | SingleTypeConstraint | SimpleElement
                    | ConstraintTVSOS;




            ExceptionSpecConstraint = qi::omit[qi::lit("!")] 
                    >> (number_str[phx::bind(&constraint_exceptnumber, sprt::_val, sprt::_1) ]
                    | DefinedValue_[phx::bind(&constraint_exceptidentifier, sprt::_val, sprt::_1) ]
                    | (Type >> qi::omit[ qi::lit(":")] >> Value)[phx::bind(&constraint_excepttypevalue, sprt::_val, sprt::_1, sprt::_2) ]
                    );

            ExceptionSpecConstraints = ExceptionSpecConstraint[ phx::bind(&push_constraint, sprt::_val, sprt::_1) ];



            UserDefinedConstraint = (qi::omit[qi::lexeme[CONSTRAINED_ >> +qi::space >> BY_]]
                    >> UParameters)[phx::bind(&constraint_userdef, sprt::_val, sprt::_1)];

            SimpleTableConstraint = StrictObjectSet[phx::bind(&constraint_setelement, sprt::_val, sprt::_1)];

            AtNotations = AtNotation_ % qi::omit[qi::lit(",")];

            ComponentRelationConstraint = (qi::omit[qi::lit("{")]
                    >> SimpleDefinedObjectSet
                    >> qi::omit[qi::lit("}")]
                    >> qi::omit[qi::lit("{")]
                    >> AtNotations
                    >> qi::omit[qi::lit("}")])[phx::bind(&constraint_relation, sprt::_val, sprt::_1, sprt::_2)];

            ContentsConstraintType = qi::omit[CONTAINING_]
                    >> Type[phx::bind(&constraint_content_t, sprt::_val, sprt::_1)];

            ContentsConstraintValue = qi::omit[qi::lexeme[ENCODED_ >> +qi::space >> BY_]]
                    >> (DefinedValue | ObjectIdentifierValue)[phx::bind(&constraint_content_v, sprt::_val, sprt::_1)];

            ContentsConstraintTypeValue = (qi::omit[CONTAINING_]
                    >> Type
                    >> qi::omit[qi::lexeme[ENCODED_ >> +qi::space >> BY_]]
                    >> (DefinedValue | ObjectIdentifierValue))[phx::bind(&constraint_content_tv, sprt::_val, sprt::_1, sprt::_2)];

            ConstraintTVSOS = SettingCN[phx::bind(&constraint_tvsos, sprt::_val, sprt::_1)];         

        }

    }
}