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

            SimpleDefinedObject = DefinedObject_[phx::bind(&object_refference, sprt::_val, sprt::_1)];

            DefinedObject = DefinedObject_[phx::bind(&object_refference, sprt::_val, sprt::_1)] >>
                    -(ActualParameters[phx::bind(&object_parameters, sprt::_val, sprt::_1)]);

            ObjectFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>LFieldName_)[phx::bind(&object_fromobject, sprt::_val, sprt::_1, sprt::_2)];
                    
            ObjectFromObjectNA = (SimpleDefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>LFieldName_)[phx::bind(&object_fromobject, sprt::_val, sprt::_1, sprt::_2)];                   

            ObjectDefn = DefaultSyntax | DefinedSyntax;


            DefaultSyntax = (qi::omit[qi::lit("{")]
                    >> FieldSettings[phx::bind(&object_fields, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lit("}")])[phx::bind(&object_typeset, sprt::_val, ot_Object)];

            FieldSettings = FieldSetting % qi::omit[qi::lit(",")];

            FieldSetting = PrimitiveFieldName_[phx::bind(&objectfield_field, sprt::_val, sprt::_1)]
                    >> Setting[phx::bind(&objectfield_setting, sprt::_val, sprt::_1)];

            DefinedSyntax = (qi::omit[qi::lit("{")]
                    >> DefinedSyntaxTokens[phx::bind(&object_fields, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lit("}")])[phx::bind(&object_typeset, sprt::_val, ot_ObjectDefineSyn)];

            DefinedSyntaxTokens = +DefinedSyntaxToken2;

            DefinedSyntaxToken = DefinedSyntaxToken2 | DefinedSyntaxToken1;

            DefinedSyntaxToken1 = Literal_[phx::bind(&objectfield_field, sprt::_val, sprt::_1)];

            DefinedSyntaxToken2 = SettingNA[phx::bind(&objectfield_setting, sprt::_val, sprt::_1)];


        }

    }
}