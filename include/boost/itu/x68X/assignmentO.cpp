//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {



        // Type_grammar

        void Modules_grammar::initO() {



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     

            Object = ObjectFromObject | DefinedObject | ObjectDefn;

            DefinedObject = DefinedObject_[bind(&object_refference, qi::_val, qi::_1)] >>
                    -(ActualParameters[bind(&object_parameters, qi::_val, qi::_1)]);

            ObjectFromObject = SimpleTypeFromObject_[bind(&object_fromobject, qi::_val, qi::_1)];

            ObjectDefn = DefaultSyntax | DefinedSyntax;


            DefaultSyntax = qi::omit[qi::lit("{")] >> FieldSettings[bind(&object_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")];

            FieldSettings = FieldSetting % qi::omit[qi::lit(",")];

            FieldSetting = PrimitiveFieldName_[bind(&objectfield_field, qi::_val, qi::_1)] >> Setting[bind(&objectfield_setting, qi::_val, qi::_1)];

            DefinedSyntax = qi::omit[qi::lit("{")] >> DefinedSyntaxTokens[bind(&object_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")];

            DefinedSyntaxTokens = +DefinedSyntaxToken;

            DefinedSyntaxToken = DefinedSyntaxToken2 | DefinedSyntaxToken1;

            DefinedSyntaxToken1 = SyntaxField_[bind(&objectfield_field, qi::_val, qi::_1)];

            DefinedSyntaxToken2 = Setting[bind(&objectfield_setting, qi::_val, qi::_1)];




        }

    }
}