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

            start_rule = *(ObjectClassAssignment | TypeAssignment | TypeAssignmentSS | UnknownTCAssignment
                    | ValueAssignmentLS | ValueAssignmentRS | ObjectAssignmentLS | ObjectAssignmentRS | ValueAssignment | ObjectAssignment
                    | ValueSetTypeAssignmentLS | ObjectSetAssignmentLS | ValueSetTypeAssignment | ObjectSetAssignment);

            ObjectClassAssignment = objectclassreference_[bind(&classa_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&classa_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictObjectClass[bind(&classa_class, qi::_val, qi::_1)];

            TypeAssignment = typereference_[bind(&type_identifier, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&typea_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> /*Type*/StrictType[bind(&typea_type, qi::_val, qi::_1)];

            TypeAssignmentSS = typereference_strict[bind(&type_identifier, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&typea_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[bind(&typea_type, qi::_val, qi::_1)];

            UnknownTCAssignment = objectclassreference_[bind(&unknown_tca_identifier, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&unknown_tca_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> UnknownReferencedTC[bind(&unknown_tca, qi::_val, qi::_1)];




            ValueAssignmentLS = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> StrictType[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[bind(&valuea_value, qi::_val, qi::_1, true)];

            ValueAssignmentRS = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictValue[bind(&valuea_value, qi::_val, qi::_1, true)];

            ValueAssignment = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[bind(&valuea_value, qi::_val, qi::_1, false)];

            ObjectAssignmentLS = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> UsefulObjectClass[bind(&objecta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[bind(&objecta_object, qi::_val, qi::_1)];

            ObjectAssignmentRS = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> SimpleDefinedObjectClass[bind(&objecta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> DefaultSyntax[bind(&objecta_object, qi::_val, qi::_1)];

            ObjectAssignment = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> SimpleDefinedObjectClass[bind(&objecta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[bind(&objecta_object, qi::_val, qi::_1)];


            ValueSetTypeAssignmentLS = valuesetreference_[bind(&valueset_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valueseta_arguments, qi::_val, qi::_1)])
                    >> StrictType[bind(&valueseta_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[bind(&valueset_set, qi::_val, qi::_1, true)];

            ValueSetTypeAssignment = valuesetreference_[bind(&valueset_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valueseta_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valueseta_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[bind(&valueset_set, qi::_val, qi::_1, false)];

            ObjectSetAssignmentLS = objectsetreference_[bind(&objectseta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objectseta_arguments, qi::_val, qi::_1)])
                    >> UsefulObjectClass[bind(&objectseta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[bind(&objectseta_objectset, qi::_val, qi::_1)];

            ObjectSetAssignment = objectsetreference_[bind(&objectseta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objectseta_arguments, qi::_val, qi::_1)])
                    >> SimpleDefinedObjectClass[bind(&objectseta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[bind(&objectseta_objectset, qi::_val, qi::_1)];




            Parameters = qi::omit[qi::lexeme[qi::lit("{")]] >> (Parameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];

            Parameter = ParameterA | ParameterB | ParameterC;

            ParameterA = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Reference_)[bind(&argument_governor_cl, qi::_val, qi::_1, qi::_2)];

            ParameterB = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Reference_)[bind(&argument_governor_tp, qi::_val, qi::_1, qi::_2)];

            ParameterC = Reference_[bind(&argument_argument, qi::_val, qi::_1)];



            ActualParameters = qi::omit[qi::lexeme[qi::lit("{")]] >> (ActualParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];

            ActualParameter = ActualParameterT | ActualParameterV | ActualParameterVS | ActualParameterC | ActualParameterO | ActualParameterOS;

            ActualParameterT = Type[bind(&parameter_type, qi::_val, qi::_1)];
            ActualParameterV = Value[bind(&parameter_value, qi::_val, qi::_1)];
            ActualParameterVS = ValueSet[bind(&parameter_valueset, qi::_val, qi::_1)];
            ;
            ActualParameterC = DefinedObjectClass_[bind(&parameter_class, qi::_val, qi::_1)];
            ActualParameterO = DefaultSyntax[bind(&parameter_object, qi::_val, qi::_1)];
            ActualParameterOS = ObjectSet[bind(&parameter_objectset, qi::_val, qi::_1)];


            initV();
            initT();
            initVS();
            initCl();
            initO();
            initOS();


        }

    }
}