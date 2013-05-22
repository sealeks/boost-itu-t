//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/value.hpp>

namespace x680 {
    namespace bnf {

        // NamedNumber_grammar

        void NamedNumber_grammar::init() {
            pair = (identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                    >> qi::lit("(")
                    >> (number_str[bind(&self_type::second_n, *this, qi::_val, qi::_1)]
                    | identifier_[bind(&self_type::second_i, *this, qi::_val, qi::_1)])
                    >> qi::lit(")"));
        }


        // NamedNumberList_grammar

        void NamedNumberList_grammar::init() {

            vect = qi::lit("{")
                    >> -(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::omit[","])
                    >> qi::lit("}");
        }


        // Enumeration_grammar

        void Enumeration_grammar::init() {

            pair = component[ qi::_val = qi::_1 ] |
                    identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                    | qi::lit("...")[bind(&self_type::extention, *this, qi::_val)];
        }


        //Enumerations_grammar

        void Enumerations_grammar::init() {

            vect = qi::lit("{")
                    >> -(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::omit[","])
                    >> qi::lit("}");
        }


        //objNameId_grammar

        void objNameId_grammar::init() {

            pair = (identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                    >> qi::lit("(")
                    >> pos_number_str[bind(&self_type::second, *this, qi::_val, qi::_1)]
                    >> qi::lit(")"))
                    | identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                    | pos_number_str[bind(&self_type::second, *this, qi::_val, qi::_1)];
        }


        //ObjectIdentifierSet_grammar

        void ObjectIdentifierSet_grammar::init() {

            vect = qi::lit("{")
                    >> *(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)])
                    >> qi::lit("}");
        }



        //BooleanValue_grammar

        void BooleanValue_grammar::init() {

            startrule = TRUE_[bind(&self_type::operator(), *this, qi::_val, std::string("TRUE"))]
                    | FALSE_[bind(&self_type::operator(), *this, qi::_val, std::string("FALSE"))];
        }


        //IntegerValue_grammar

        void IntegerValue_grammar::init() {

            startrule = number_str[bind(&self_type::number, *this, qi::_val, qi::_1)]
                    | identifier_[bind(&self_type::identifier, *this, qi::_val, qi::_1)];
        }


        //IdentifierValue_grammar

        void IdentifierValue_grammar::init() {

            startrule = identifier_[bind(&self_type::identifier, *this, qi::_val, qi::_1)];
        }


        //RealValue_grammar

        void RealValue_grammar::init() {

            startrule = realnumber_str[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                    | PLUS_INFINITY_[bind(&self_type::operator(), *this, qi::_val, std::string("PLUS-INFINITY"))]
                    | MINUS_INFINITY_[bind(&self_type::operator(), *this, qi::_val, std::string("MINUS-INFINITY"))]
                    | NOT_A_NUMBER_[bind(&self_type::operator(), *this, qi::_val, std::string("NOT-A-NUMBER"))];
        }


        //HStringValue_grammar

        void HStringValue_grammar::init() {

            startrule = hstring_str[bind(&self_type::operator(), *this, qi::_val, qi::_1)];
        }


        //BStringValue_grammar

        void BStringValue_grammar::init() {

            startrule = bstring_str[bind(&self_type::operator(), *this, qi::_val, qi::_1)];
        }


        //CStringValue_grammar

        void CStringValue_grammar::init() {

            startrule = cstring_str[bind(&self_type::operator(), *this, qi::_val, qi::_1)];
        }

        //NullValue_grammar

        void NullValue_grammar::init() {
            startrule = NULL_[bind(&self_type::operator(), *this, qi::_val) ];
        }

        //IdentifierList_grammar

        void IdentifierList_grammar::init() {
            startrule = (qi::lit("{")
                    >> qi::lit("}"))[bind(&self_type::operator (), *this, qi::_val)]
                    | (qi::lit("{")
                    >> (identifier_[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::lit(","))
                    >> qi::lit("}"));
        }


        //ObjectIdentifierValue

        void ObjectIdentifierValue_grammar::init() {
            startrule = ObjectIdentifierSet[bind(&self_type::operator (), *this, qi::_val, qi::_1)];
        }


        //SimpleValue_grammar

        void SimpleValue_grammar::init() {
            startrule = NullValue | BooleanValue | RealValue | IntegerValue | HStringValue | BStringValue | CStringValue | IdentifierList | ObjectIdentifierValue;

        }

        //NamedValue_grammar

        void NamedValue_grammar::init() {
            startrule = identifier_[bind(&self_type::idetifier, *this, qi::_val, qi::_1)] >> SimpleValue[bind(&self_type::value, *this, qi::_val, qi::_1)];

        }

        //StructValue_grammar

        void StructValue_grammar::init() {

            startrule = ComponentValueList[bind(&self_type::values, *this, qi::_val, qi::_1)];

            NamedValue = identifier_[bind(&self_type::idetifier, *this, qi::_val, qi::_1)]
                    >> (SimpleValue[bind(&self_type::named_value, *this, qi::_val, qi::_1)]
                    | ComponentValueList[bind(&self_type::named_values, *this, qi::_val, qi::_1)]);

            Value = SimpleValue[bind(&self_type::named_value, *this, qi::_val, qi::_1)]
                    | ComponentValueList[bind(&self_type::values, *this, qi::_val, qi::_1)];

            ChoiceValue = identifier_[bind(&self_type::idetifier, *this, qi::_val, qi::_1)]
                    >> qi::lit(":")
                    >> (SimpleValue[bind(&self_type::choice_value, *this, qi::_val, qi::_1)]
                    | ComponentValueList[bind(&self_type::values, *this, qi::_val, qi::_1)]);

            ComplexValue = ChoiceValue | NamedValue | Value;

            ComponentValueList = ChoiceValue
                    | (qi::lit("{")
                    >> ((ComplexValue % qi::lit(",")) | (Value % qi::lit(",")))
                    >> qi::lit("}"));



        }



        // ReferencedValue    

        void ReferencedValue_grammar::init() {
            startrule = DefinedValue_[bind(&self_type::defined, *this, qi::_val, qi::_1)];
        }



        //Value_grammar

        void Value_grammar::init() {
            startrule = SimpleValue | StructValue | ReferencedValue;
        }


    }
}