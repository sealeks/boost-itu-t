//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {




        // Type_grammar

        void Assignments_grammar::initV() {



            Value = NullValue | BooleanValue | RealValue | IntegerValue | HStringValue | BStringValue | CStringValue | NumberList | ObjectIdentifierValue | NamedValueList | ChoiceValue | EmptySetValue | ValueFromObject | ObjectClassFieldValue | DefinedValue;

            SimpleDefinedValue = DefinedValue_[bind(&value_setdefined, qi::_val, qi::_1)];

            DefinedValue = DefinedValue_[bind(&value_setdefined, qi::_val, qi::_1)] >> -(ActualParameters[bind(&value_parameters, qi::_val, qi::_1)]);

            StrictValue = NullValue | BooleanValue | RealValue | IntegerValue | HStringValue | BStringValue | CStringValue;

            RangeValue = RealValue | IntegerValue | CStringValue | NumberList | DefinedValue;

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

            NumberList = qi::omit[qi::lexeme[qi::lit("{")]] >> NumberValues[bind(&value_setvalues, qi::_val, qi::_1, v_number_list)] >> qi::omit[qi::lexeme[qi::lit("}")]];

            NamedValue = (identifier_ >> Value)[bind(&value_namedval, qi::_val, qi::_1, qi::_2)];

            NamedValues = NamedValue % qi::omit[qi::lit(",")];

            NamedValueList = qi::omit[qi::lexeme[qi::lit("{")]] >> NamedValues[bind(&value_setvalues, qi::_val, qi::_1, v_namedvalue_list)] >> qi::omit[qi::lexeme[qi::lit("}")]];

            Values = Value % qi::omit[qi::lit(",")];

            ValueList = qi::omit[qi::lexeme[qi::lit("{")]] >> Values[bind(&value_setvalues, qi::_val, qi::_1, v_value_list)] >> qi::omit[qi::lexeme[qi::lit("}")]];

            ChoiceValue = (identifier_
                    >> qi::omit[ qi::lit(":")]
                    >> Value)[bind(&value_choiceval, qi::_val, qi::_1, qi::_2)];

            EmptySetValue = (qi::omit[qi::lexeme[qi::lit("{")]] >> qi::omit[qi::lexeme[qi::lit("}")]])[bind(&value_emptyset, qi::_val)];

            OpenTypeFieldVal = (Type >> qi::omit[qi::lit(":")] >> Value)[bind(&typevalue_set, qi::_val, qi::_1, qi::_2)];

            OpenTypeFieldValv = (Type >> qi::omit[qi::lit(":")] >> Value)[bind(&typevalues_set, qi::_val, qi::_1, qi::_2)];

            ObjectClassFieldValue = OpenTypeFieldValv[bind(&value_typevalue, qi::_val, qi::_1)];

            ValueFromObject = SimpleTypeFromObject_[bind(&value_fromobject, qi::_val, qi::_1)];


        }

    }
}