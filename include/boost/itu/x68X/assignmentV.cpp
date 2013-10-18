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

            SimpleDefinedValue = DefinedValue_[phx::bind(&value_setdefined, sprt::_val, sprt::_1)];

            DefinedValue = DefinedValue_[phx::bind(&value_setdefined, sprt::_val, sprt::_1)]
                    >> -(ActualParameters[phx::bind(&value_parameters, sprt::_val, sprt::_1)]);

            StrictValue = NullValue | BooleanValue | RealValue
                    | IntegerValue | HStringValue | BStringValue | CStringValue;

            RangeValue = RealValue | IntegerValue
                    | CStringValue | NumberList | DefinedValue;

            NullValue = NULL_[phx::bind(&value_setnull, sprt::_val)];

            BooleanValue = TRUE_[ sprt::_val = VALUE_BOOL_TRUE ]
                    | FALSE_[sprt::_val = VALUE_BOOL_FALSE];

            IntegerValue = number_str[phx::bind(&value_setnumber, sprt::_val, sprt::_1)];

            CStringValue = cstring_str[phx::bind(&value_setcstring, sprt::_val, sprt::_1)];

            HStringValue = hstring_str[phx::bind(&value_sethstring, sprt::_val, sprt::_1)];

            BStringValue = bstring_str[phx::bind(&value_setbstring, sprt::_val, sprt::_1)];

            RealValue = realnumber_str[phx::bind(&value_setreal, sprt::_val, sprt::_1)]
                    | PLUS_INFINITY_[phx::bind(&value_setreal, sprt::_val, std::string("PLUS-INFINITY"))]
                    | MINUS_INFINITY_[phx::bind(&value_setreal, sprt::_val, std::string("MINUS-INFINITY"))]
                    | NOT_A_NUMBER_[phx::bind(&value_setreal, sprt::_val, std::string("NOT-A-NUMBER"))];

            NumberValues = IntegerValue % qi::omit[qi::lit(",")];

            NumberList = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> NumberValues[phx::bind(&value_setvalues, sprt::_val, sprt::_1, v_number_list)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            NamedValue = (identifier_ >> Value)[phx::bind(&value_namedval, sprt::_val, sprt::_1, sprt::_2)];

            NamedValues = NamedValue % qi::omit[qi::lit(",")];

            NamedValueList = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> NamedValues[phx::bind(&value_setvalues, sprt::_val, sprt::_1, v_struct)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            Values = Value % qi::omit[qi::lit(",")];

            ValueList = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> Values[phx::bind(&value_setvalues, sprt::_val, sprt::_1, v_value_list)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            ChoiceValue = (identifier_
                    >> qi::omit[ qi::lit(":")]
                    >> Value)[phx::bind(&value_choiceval, sprt::_val, sprt::_1, sprt::_2)];


            ObjectIdentifierValue = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> ObjIdComponents[phx::bind(&value_setvalues, sprt::_val, sprt::_1, v_objectid)]
                    >> qi::omit[qi::lexeme[qi::lit("}")]];

            NumberFormN = pos_number_str[phx::bind(&value_setnumber, sprt::_val, sprt::_1)];

            NumberForm = NumberFormN | DefinedValue;

            NameForm = identifier_[phx::bind(&value_setdefined, sprt::_val, sprt::_1)];

            NameAndNumberForm1 = (identifier_
                    >> qi::omit[qi::lit("(")]
                    >> number_str
                    >> qi::omit[qi::lit(")")])[phx::bind(&value_setassigned, sprt::_val, sprt::_1, sprt::_2)];

            NameAndNumberForm2 = (identifier_
                    >> qi::omit[qi::lit("(")]
                    >> pos_number_str
                    >> qi::omit[qi::lit(")")])[phx::bind(&value_setassigned, sprt::_val, sprt::_1, sprt::_2)];

            NameAndNumberForm3 = (identifier_
                    >> qi::omit[qi::lit("(")]
                    >> DefinedValue
                    >> qi::omit[qi::lit(")")])[phx::bind(&value_setassignedval, sprt::_val, sprt::_1, sprt::_2)];

            NameAndNumberForm = NameAndNumberForm2 | NameAndNumberForm3;

            ObjIdComponent = NameAndNumberForm | NumberForm | NameForm;

            ObjIdComponents = qi::repeat(2, qi::inf)[ObjIdComponent];

            NameBitList = qi::omit[qi::lexeme[qi::lit("{")]] >>
                    (NameAndNumberForm2 | NameAndNumberForm3) % qi::omit[qi::lit(",")] >>
                    qi::omit[qi::lexeme[qi::lit("}")]];

            NamedNumberList = qi::omit[qi::lexeme[qi::lit("{")]] >>
                    (NameAndNumberForm1 | NameAndNumberForm3) % qi::omit[qi::lit(",")] >>
                    qi::omit[qi::lexeme[qi::lit("}")]];

            EnumerationItem = NameAndNumberForm2 | DefinedValue;

            RootEnumerations = EnumerationItem % qi::omit[qi::lit(",")];

            ValueExtention = qi::lit("...")[sprt::_val = VALUE_EXTENTION];

            ValueException1 = (qi::omit[qi::lexeme[qi::lit("!")]] >> pos_number_str)[phx::bind(&value_exception, sprt::_val, sprt::_1)];

            ValueException2 = (qi::omit[qi::lexeme[qi::lit("!")]] >> DefinedValue_)[phx::bind(&value_exception, sprt::_val, sprt::_1)];

            ValueException = ValueException1 | ValueException2;

            Enumerations = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> RootEnumerations[phx::bind(&values_enum_pushs, sprt::_val, sprt::_1)]
                    >> -(qi::omit[qi::lexeme[qi::lit(",")]] >> ValueExtention[phx::bind(&values_enum_push, sprt::_val, sprt::_1)]
                    >> -(ValueException[phx::bind(&values_enum_push, sprt::_val, sprt::_1)])
                    >> -(qi::omit[qi::lexeme[qi::lit(",")]] >> RootEnumerations[phx::bind(&values_enum_pushs, sprt::_val, sprt::_1)]))
                    >> qi::omit[qi::lexeme[qi::lit("}")]];




            EmptySetValue = (qi::omit[qi::lexeme[qi::lit("{")]]
                    >> qi::omit[qi::lexeme[qi::lit("}")]])[phx::bind(&value_emptyset, sprt::_val)];

            OpenTypeFieldVal = (Type >> qi::omit[qi::lit(":")]
                    >> Value)[phx::bind(&typevalue_set, sprt::_val, sprt::_1, sprt::_2)];

            OpenTypeFieldValv = (Type >> qi::omit[qi::lit(":")]
                    >> Value)[phx::bind(&typevalues_set, sprt::_val, sprt::_1, sprt::_2)];

            ObjectClassFieldValue = OpenTypeFieldValv[phx::bind(&value_typevalue, sprt::_val, sprt::_1)];

            ValueFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>LFieldName_)[phx::bind(&value_fromobject, sprt::_val, sprt::_1, sprt::_2)];
                    
            ValueFromObjectNA = (SimpleDefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>LFieldName_)[phx::bind(&value_fromobject, sprt::_val, sprt::_1, sprt::_2)];                    


        }

    }
}