//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {



        // Type_grammar

        void Assignments_grammar::initO() {



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////              

            ObjectDefn = DefaultSyntax | DefinedSyntax;


            DefaultSyntax = qi::omit[qi::lit("{")] >> FieldSettings[bind(&object_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")];

            FieldSettings = FieldSetting % qi::omit[qi::lit(",")];

            FieldSetting = PrimitiveFieldName_[bind(&objectfield_field, qi::_val, qi::_1)] >> (Type[bind(&objectfield_typeset, qi::_val, qi::_1)] | Value[bind(&objectfield_value, qi::_val, qi::_1)] | ValueSet[bind(&objectfield_valueset, qi::_val, qi::_1)]);

            DefinedSyntax = qi::omit[qi::lit("{")] >> DefinedSyntaxTokens[bind(&object_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")];

            DefinedSyntaxTokens = +DefinedSyntaxToken;

            DefinedSyntaxToken = DefinedSyntaxToken2 | DefinedSyntaxToken1;

            DefinedSyntaxToken1 = SyntaxField_[bind(&objectfield_field, qi::_val, qi::_1)];

            DefinedSyntaxToken2 = Type[bind(&objectfield_typeset, qi::_val, qi::_1)] | Value[bind(&objectfield_value, qi::_val, qi::_1)] | ValueSet[bind(&objectfield_valueset, qi::_val, qi::_1)];




        }

    }
}