//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>


namespace x680 {
    namespace syntactic {

        namespace phx = boost::phoenix;

        //Modules_grammar

        void Modules_grammar::initSt() {

            SettingType = Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)];

            SettingValue = Value[phx::bind(&setting_value, sprt::_val, sprt::_1)];

            SettingValueSet = ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)];

            SettingClass = DefinedObjectClass[phx::bind(&setting_class, sprt::_val, sprt::_1)];

            SettingObject = Object[phx::bind(&setting_object, sprt::_val, sprt::_1)];

            SettingObjectSet = ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)];

            SettingLiteral = SyntaxField_[phx::bind(&setting_literal, sprt::_val, sprt::_1)];
            
            SettingSLiteral = Literal_[phx::bind(&setting_literal, sprt::_val, sprt::_1)];

            SettingArgument = bothreference_[phx::bind(&setting_literal, sprt::_val, sprt::_1)];

            SettingTypeNA = TypeNA[phx::bind(&setting_settype, sprt::_val, sprt::_1)];

            SettingValueNA = ValueNA[phx::bind(&setting_value, sprt::_val, sprt::_1)];

            SettingValueSetNA = ValueSetNA[phx::bind(&setting_valueset, sprt::_val, sprt::_1)];

            SettingObjectNA = ObjectNA[phx::bind(&setting_object, sprt::_val, sprt::_1)];

            SettingObjectSetNA = ObjectSetNA[phx::bind(&setting_objectset, sprt::_val, sprt::_1)];



            SettingMCN= SettingType | SettingValueSet | SettingObjectSet;

            SettingCN = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSetNA[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingMCN;

            SettingM0 = SettingValue | SettingValueSet | SettingObject | SettingObjectSet;

            Setting0 = ((qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM0;


            SettingM1 = SettingType | SettingValue | SettingValueSet | SettingObject | SettingObjectSet | SettingLiteral;

            Setting = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[SyntaxField_[phx::bind(&setting_literal, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM1;

            SettingM1NA = SettingTypeNA | SettingValueNA | SettingValueSetNA | SettingObjectNA | SettingObjectSetNA | SettingSLiteral;

            SettingNA = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Literal_[phx::bind(&setting_literal, sprt::_val, sprt::_1)] >> qi::omit[';']])) |  SettingM1NA;

            SettingM2 = SettingType | SettingValue | SettingValueSet | SettingClass | SettingObject | SettingObjectSet | SettingArgument;

            ActualParameter = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[DefinedObjectClass[phx::bind(&setting_class, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[bothreference_[phx::bind(&setting_literal, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM2;

            SettingM3 = SettingValue | SettingObject;

            SettingU1 = ((qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM3;

            SettingM4 = SettingType | SettingClass | SettingObjectSet;

            SettingU2 = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[DefinedObjectClass[phx::bind(&setting_class, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM4;


            SettingCValueSet = SimpleValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)];

            SettingM5 = SettingType | SettingCValueSet | SettingObjectSet;

            SettingC = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[SimpleValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM5;



            Parameters = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> (Parameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];


            Parameter = ParameterA1 | ParameterA1 | ParameterB1
                    | ParameterB2 | ParameterC1 | ParameterC2 | ParameterD1 | ParameterD2;

            ParameterA1 = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[phx::bind(&argument_governor_cl, sprt::_val, sprt::_1, sprt::_2, true)];

            ParameterA2 = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[phx::bind(&argument_governor_cl, sprt::_val, sprt::_1, sprt::_2, false)];

            ParameterB1 = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[phx::bind(&argument_governor_tp, sprt::_val, sprt::_1, sprt::_2, true)];

            ParameterB2 = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[phx::bind(&argument_governor_tp, sprt::_val, sprt::_1, sprt::_2, false)];

            ParameterC1 = (DefinedType_ >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[phx::bind(&argument_governor_reff, sprt::_val, sprt::_1, sprt::_2, true)];

            ParameterC2 = (DefinedType_ >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[phx::bind(&argument_governor_reff, sprt::_val, sprt::_1, sprt::_2, false)];

            ParameterD1 = typereference_[phx::bind(&argument_argument, sprt::_val, sprt::_1, true)];

            ParameterD2 = valuereference_[phx::bind(&argument_argument, sprt::_val, sprt::_1, false)];



            ActualParameters = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> (ActualParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];



            UParameterA = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Setting0)[phx::bind(&uargument_governor_cl, sprt::_val, sprt::_1, sprt::_2)];

            UParameterB = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Setting0)[phx::bind(&uargument_governor_tp, sprt::_val, sprt::_1, sprt::_2)];

            UParameterC = (DefinedType_ >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Setting0)[phx::bind(&uargument_governor_reff, sprt::_val, sprt::_1, sprt::_2)];

            UParameterD = (SettingM2)[phx::bind(&uargument_setting, sprt::_val, sprt::_1)];

            UParameter = UParameterA | UParameterB | UParameterC | UParameterD;

            UParameters = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> -(UParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];


        }

    }
}