//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {




        // Type_grammar

        void Modules_grammar::initV() {



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ValueAssigment grammar 
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


            Value = ObjectClassFieldValue | ValueFromObject | NullValue
                    | BooleanValue | RealValue | IntegerValue | HStringValue
                    | BStringValue | CStringValue | NumberList | ObjectIdentifierValue
                    | NamedValueList | ValueList | ChoiceValue | EmptySetValue
                    | DefinedValue;

            ValueNA = ObjectClassFieldValue | ValueFromObject | NullValue
                    | BooleanValue | RealValue | IntegerValue | HStringValue
                    | BStringValue | CStringValue | NumberList | ObjectIdentifierValue
                    | NamedValueList | ValueList | ChoiceValue | EmptySetValue
                    | SimpleDefinedValue;

            SimpleDefinedValue = DefinedValue_[bind(&value_setdefined, qi::_val, qi::_1)];

            DefinedValue = DefinedValue_[bind(&value_setdefined, qi::_val, qi::_1)]
                    >> -(ActualParameters[bind(&value_parameters, qi::_val, qi::_1)]);

            StrictValue = NullValue | BooleanValue | RealValue
                    | IntegerValue | HStringValue | BStringValue | CStringValue;

            RangeValue = RealValue | IntegerValue
                    | CStringValue | NumberList | DefinedValue;

            NullValue = NULL_[bind(&value_setnull, qi::_val)];

            BooleanValue = TRUE_[ qi::_val = VALUE_BOOL_TRUE ] | FALSE_[qi::_val = VALUE_BOOL_FALSE];

            IntegerValue = number_str[bind(&value_setnumber, qi::_val, qi::_1)];

            CStringValue = cstring_str[bind(&value_setcstring, qi::_val, qi::_1)];

            HStringValue = hstring_str[bind(&value_sethstring, qi::_val, qi::_1)];

            BStringValue = bstring_str[bind(&value_setbstring, qi::_val, qi::_1)];

            RealValue = realnumber_str[bind(&value_setreal, qi::_val, qi::_1)]
                    | PLUS_INFINITY_[bind(&value_setreal, qi::_val, std::string("PLUS-INFINITY"))]
                    | MINUS_INFINITY_[bind(&value_setreal, qi::_val, std::string("MINUS-INFINITY"))]
                    | NOT_A_NUMBER_[bind(&value_setreal, qi::_val, std::string("NOT-A-NUMBER"))];

            NumberValues = IntegerValue % qi::omit[qi::lit(",")];

            NumberList = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> NumberValues[bind(&value_setvalues, qi::_val, qi::_1, v_number_list)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            NamedValue = (identifier_ >> Value)[bind(&value_namedval, qi::_val, qi::_1, qi::_2)];

            NamedValues = NamedValue % qi::omit[qi::lit(",")];

            NamedValueList = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> NamedValues[bind(&value_setvalues, qi::_val, qi::_1, v_struct)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            Values = Value % qi::omit[qi::lit(",")];

            ValueList = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> Values[bind(&value_setvalues, qi::_val, qi::_1, v_value_list)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            ChoiceValue = (identifier_
                    >> qi::omit[ qi::lit(":")]
                    >> Value)[bind(&value_choiceval, qi::_val, qi::_1, qi::_2)];


            ObjectIdentifierValue = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> ObjIdComponents[bind(&value_setvalues, qi::_val, qi::_1, v_objectid)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            NumberFormN = pos_number_str[bind(&value_setnumber, qi::_val, qi::_1)];

            NumberForm = NumberFormN | DefinedValue;

            NameForm = identifier_[bind(&value_setdefined, qi::_val, qi::_1)];

            NameAndNumberForm1 = (identifier_
                    >> qi::omit[qi::lit("(")]
                    >> number_str
                    >> qi::omit[qi::lit(")")])[bind(&value_setassigned, qi::_val, qi::_1, qi::_2)];

            NameAndNumberForm2 = (identifier_
                    >> qi::omit[qi::lit("(")]
                    >> pos_number_str
                    >> qi::omit[qi::lit(")")])[bind(&value_setassigned, qi::_val, qi::_1, qi::_2)];

            NameAndNumberForm3 = (identifier_
                    >> qi::omit[qi::lit("(")]
                    >> DefinedValue
                    >> qi::omit[qi::lit(")")])[bind(&value_setassignedval, qi::_val, qi::_1, qi::_2)];

            NameAndNumberForm = NameAndNumberForm2 | NameAndNumberForm3;

            ObjIdComponent = NameAndNumberForm | NumberForm | NameForm;

            ObjIdComponents = +ObjIdComponent;

            NameBitList = qi::omit[qi::lexeme[qi::lit("{")]] >>
                    (NameAndNumberForm2 | NameAndNumberForm3) % qi::omit[qi::lit(",")] >>
                    qi::omit[qi::lexeme[qi::lit("}")]];

            NamedNumberList = qi::omit[qi::lexeme[qi::lit("{")]] >>
                    (NameAndNumberForm1 | NameAndNumberForm3) % qi::omit[qi::lit(",")] >>
                    qi::omit[qi::lexeme[qi::lit("}")]];

            EnumerationItem = NameAndNumberForm2 | DefinedValue;

            RootEnumerations = EnumerationItem % qi::omit[qi::lit(",")];

            ValueExtention = qi::lit("...")[qi::_val = VALUE_EXTENTION];

            ValueException1 = (qi::omit[qi::lexeme[qi::lit("!")]] >> pos_number_str)[bind(&value_exception, qi::_val, qi::_1)];

            ValueException2 = (qi::omit[qi::lexeme[qi::lit("!")]] >> DefinedValue_)[bind(&value_exception, qi::_val, qi::_1)];

            ValueException = ValueException1 | ValueException2;

            Enumerations = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> RootEnumerations[bind(&values_enum_pushs, qi::_val, qi::_1)]
                    >> -(qi::omit[qi::lexeme[qi::lit(",")]] >> ValueExtention[bind(&values_enum_push, qi::_val, qi::_1)]
                    >> -(ValueException[bind(&values_enum_push, qi::_val, qi::_1)])
                    >> -(qi::omit[qi::lexeme[qi::lit(",")]] >> RootEnumerations[bind(&values_enum_pushs, qi::_val, qi::_1)]))
                    >> qi::omit[qi::lexeme[qi::lit("}")]];




            EmptySetValue = (qi::omit[qi::lexeme[qi::lit("{")]]
                    >> qi::omit[qi::lexeme[qi::lit("}")]])[bind(&value_emptyset, qi::_val)];

            OpenTypeFieldVal = (Type >> qi::omit[qi::lit(":")]
                    >> Value)[bind(&typevalue_set, qi::_val, qi::_1, qi::_2)];

            OpenTypeFieldValv = (Type >> qi::omit[qi::lit(":")]
                    >> Value)[bind(&typevalues_set, qi::_val, qi::_1, qi::_2)];

            ObjectClassFieldValue = OpenTypeFieldValv[bind(&value_typevalue, qi::_val, qi::_1)];

            ValueFromObject = LittleFromObject_[bind(&value_fromobject, qi::_val, qi::_1)];


        }

    }
}