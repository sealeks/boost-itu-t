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
                    >> -(Parameters[bind(&typea_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> /*Type*/StrictType[bind(&typea_type, qi::_val, qi::_1)];

            ValueAssignment = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[bind(&valuea_value, qi::_val, qi::_1)];

            ValueSetTypeAssignment = valuesetreference_[bind(&valueset_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valueseta_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valueseta_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[bind(&valueset_set, qi::_val, qi::_1)];

            ObjectClassAssignment = objectclassreference_[bind(&classa_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&classa_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectClassDefn[bind(&classa_class, qi::_val, qi::_1)];

            ObjectAssignment = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> DefinedObjectClass_
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> DefaultSyntax[bind(&objecta_object, qi::_val, qi::_1)];


            ObjectSetAssignment = objectsetreference_[bind(&objectseta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objectseta_arguments, qi::_val, qi::_1)])
                    >> DefinedObjectClass_
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[bind(&objectseta_objectset, qi::_val, qi::_1)];



            Parameters = qi::omit[qi::lexeme[qi::lit("{")]] >> (Parameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];
            
            Parameter = ParameterA | ParameterB;

            ParameterA = (Type >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> bothreference_)[bind(&argument_governor_tp, qi::_val, qi::_1, qi::_2)];
                    
            ParameterB = bothreference_[bind(&argument_argument, qi::_val, qi::_1)];     
            
            
            
            ActualParameters = qi::omit[qi::lexeme[qi::lit("{")]] >> (ActualParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];            
            
            ActualParameter = ActualParameterT | ActualParameterV | ActualParameterVS |ActualParameterC | ActualParameterO | ActualParameterOS; 
            
            ActualParameterT = Type[bind(&parameter_type, qi::_val, qi::_1)];
            ActualParameterV = Value[bind(&parameter_value, qi::_val, qi::_1)];        
            ActualParameterVS = ValueSet[bind(&parameter_valueset, qi::_val, qi::_1)]; ;
            ActualParameterC = DefinedObjectClass_[bind(&parameter_class, qi::_val, qi::_1)]; 
            ActualParameterO = DefaultSyntax[bind(&parameter_object, qi::_val, qi::_1)]; 
            ActualParameterOS = ObjectSet[bind(&parameter_objectset, qi::_val, qi::_1)]; 
              

            initT();
            initVS();
            initCl();
            initO();
            initOS();


        }

    }
}