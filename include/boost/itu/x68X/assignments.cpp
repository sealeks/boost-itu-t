//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>


namespace x680 {
    namespace syntactic {

        namespace phx = boost::phoenix;

        //Modules_grammar

        void Modules_grammar::initA() {


            Assignments = *(ObjectClassAssignment | TypeAssignment
                    | TypeAssignmentSS | UnknownTCAssignment
                    | ValueAssignmentLS | ObjectAssignmentLS | ObjectAssignmentRS
                    | ValueSetTypeAssignmentLS | ObjectSetAssignmentLS
                    | UnknownValObjAssignment | UnknownValSetObjSetAssignment);


            ObjectClassAssignment = objectclassreference_[phx::bind(&classa_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&classa_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictObjectClassO[phx::bind(&classa_class, sprt::_val, sprt::_1)];

            ObjectClassAssignment0 = objectclassreference_[phx::bind(&classa_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&classa_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectClass[phx::bind(&classa_class, sprt::_val, sprt::_1)];

            TypeAssignment = typereference_[phx::bind(&type_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&typea_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> /*Type*/StrictType[phx::bind(&typea_type, sprt::_val, sprt::_1)];

            TypeAssignmentSS = typereference_strict[phx::bind(&type_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&typea_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[phx::bind(&typea_type, sprt::_val, sprt::_1)];

            TypeAssignment0 = typereference_[phx::bind(&type_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&typea_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[phx::bind(&typea_type, sprt::_val, sprt::_1)];



            ValueAssignmentLS = valuereference_[phx::bind(&valuea_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valuea_arguments, sprt::_val, sprt::_1)])
                    >> StrictType[phx::bind(&valuea_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[phx::bind(&valuea_value, sprt::_val, sprt::_1)];

            ValueAssignmentRS = valuereference_[phx::bind(&valuea_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valuea_arguments, sprt::_val, sprt::_1)])
                    >> Type[phx::bind(&valuea_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictValue[phx::bind(&valuea_value, sprt::_val, sprt::_1)];

            ValueAssignment = valuereference_[phx::bind(&valuea_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valuea_arguments, sprt::_val, sprt::_1)])
                    >> Type[phx::bind(&valuea_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[phx::bind(&valuea_value, sprt::_val, sprt::_1)];

            ObjectAssignmentLS = objectreference_[phx::bind(&objecta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objecta_arguments, sprt::_val, sprt::_1)])
                    >> UsefulObjectClass[phx::bind(&objecta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[phx::bind(&objecta_object, sprt::_val, sprt::_1)];

            ObjectAssignmentRS = objectreference_[phx::bind(&objecta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objecta_arguments, sprt::_val, sprt::_1)])
                    >> SimpleDefinedObjectClass[phx::bind(&objecta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> DefaultSyntax[phx::bind(&objecta_object, sprt::_val, sprt::_1)];

            ObjectAssignment = objectreference_[phx::bind(&objecta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objecta_arguments, sprt::_val, sprt::_1)])
                    >> SimpleDefinedObjectClass[phx::bind(&objecta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Object[phx::bind(&objecta_object, sprt::_val, sprt::_1)];


            ValueSetTypeAssignmentLS = valuesetreference_[phx::bind(&valueset_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valueseta_arguments, sprt::_val, sprt::_1)])
                    >> StrictType[phx::bind(&valueseta_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[phx::bind(&valueseta_set, sprt::_val, sprt::_1)];

            ValueSetTypeAssignment = valuesetreference_[phx::bind(&valueset_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valueseta_arguments, sprt::_val, sprt::_1)])
                    >> Type[phx::bind(&valueseta_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[phx::bind(&valueseta_set, sprt::_val, sprt::_1)];

            ObjectSetAssignmentLS = objectsetreference_[phx::bind(&objectseta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objectseta_arguments, sprt::_val, sprt::_1)])
                    >> UsefulObjectClass[phx::bind(&objectseta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[phx::bind(&objectseta_objectset, sprt::_val, sprt::_1)];

            ObjectSetAssignment = objectsetreference_[phx::bind(&objectseta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objectseta_arguments, sprt::_val, sprt::_1)])
                    >> SimpleDefinedObjectClass[phx::bind(&objectseta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[phx::bind(&objectseta_objectset, sprt::_val, sprt::_1)];



            UnknownTCAssignment = ((qi::hold[TypeAssignment0[phx::bind(&unknown_tca_type, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectClassAssignment0[phx::bind(&unknown_tca_class, sprt::_val, sprt::_1)] >> qi::omit[';']])) |
                    (objectclassreference_[phx::bind(&unknown_tca_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&unknown_tca_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> UnknownReferencedTC[phx::bind(&unknown_tca, sprt::_val, sprt::_1)]);
          
        }

    }
}