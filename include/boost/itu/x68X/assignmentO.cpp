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

            ObjectNA = ObjectFromObject | SimpleDefinedObject | ObjectDefn;

            SimpleDefinedObject = DefinedObject_[bind(&object_refference, qi::_val, qi::_1)];

            DefinedObject = DefinedObject_[bind(&object_refference, qi::_val, qi::_1)] >>
                    -(ActualParameters[bind(&object_parameters, qi::_val, qi::_1)]);

            ObjectFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>LFieldName_)[bind(&object_fromobject, qi::_val, qi::_1, qi::_2)];
                    
            ObjectFromObjectNA = (SimpleDefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>LFieldName_)[bind(&object_fromobject, qi::_val, qi::_1, qi::_2)];                   

            ObjectDefn = DefaultSyntax | DefinedSyntax;


            DefaultSyntax = (qi::omit[qi::lit("{")]
                    >> FieldSettings[bind(&object_fields, qi::_val, qi::_1)]
                    >> qi::omit[qi::lit("}")])[bind(&object_typeset, qi::_val, ot_Object)];

            FieldSettings = FieldSetting % qi::omit[qi::lit(",")];

            FieldSetting = PrimitiveFieldName_[bind(&objectfield_field, qi::_val, qi::_1)]
                    >> Setting[bind(&objectfield_setting, qi::_val, qi::_1)];

            DefinedSyntax = (qi::omit[qi::lit("{")]
                    >> DefinedSyntaxTokens[bind(&object_fields, qi::_val, qi::_1)]
                    >> qi::omit[qi::lit("}")])[bind(&object_typeset, qi::_val, ot_ObjectDefineSyn)];

            DefinedSyntaxTokens = +DefinedSyntaxToken2;

            DefinedSyntaxToken = DefinedSyntaxToken2 | DefinedSyntaxToken1;

            DefinedSyntaxToken1 = SyntaxField_[bind(&objectfield_field, qi::_val, qi::_1)];

            DefinedSyntaxToken2 = SettingNA[bind(&objectfield_setting, qi::_val, qi::_1)];




        }

    }
}