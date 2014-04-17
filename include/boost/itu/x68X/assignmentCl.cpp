//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {


        // Type_grammar

        void Modules_grammar::initCl() {



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectClassAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////   


            ObjectClass = UsefulObjectClass | ObjectClassDefn | ParameterizedObjectClass;

            StrictObjectClass = UsefulObjectClass | ObjectClassDefn;
            
            StrictObjectClassO = UsefulObjectClassO | ObjectClassDefn;            

            SimpleDefinedObjectClass = DefinedObjectClass_[phx::bind(&class_reference, sprt::_val, sprt::_1)];

            ObjectClassDefn = qi::omit[CLASS_ >> qi::lit("{")]
                    >> FieldSpecs[phx::bind(&class_fields, sprt::_val, sprt::_1)] >> qi::omit[qi::lit("}")]
                    >> -(WithSyntaxSpec[phx::bind(&class_syntaxes, sprt::_val, sprt::_1)]);

            UsefulObjectClass = TYPE_IDENTIFIER_[sprt::_val = CLASS_TYPE_IDENTIFIER]
                    | ABSTRACT_SYNTAX_[sprt::_val = CLASS_ABSTRACT_SYNTAX];
            
            UsefulObjectClassO = distinct('.')[TYPE_IDENTIFIER_[sprt::_val = CLASS_TYPE_IDENTIFIER]
                    | ABSTRACT_SYNTAX_[sprt::_val = CLASS_ABSTRACT_SYNTAX]];            

            DefinedObjectClass = UsefulObjectClass | SimpleDefinedObjectClass;

            ParameterizedObjectClass = DefinedObjectClass[sprt::_val = sprt::_1]
                    >> -(ActualParameters[phx::bind(&class_parameters, sprt::_val, sprt::_1)]);

            FieldSpecs = FieldSpec % qi::omit[qi::lit(",")];


            WithSyntaxSpec = qi::omit[ qi::lexeme[WITH_ >> +qi::blank >> SYNTAX_]] >> SyntaxList;

            SyntaxList = qi::omit[qi::lit("{")] >> TokenOrGroupSpec >> qi::omit[qi::lit("}")];

            TokenOrGroupSpec = +(AiasTokenOToken | TokenOToken | RequiredToken | OptionalToken);

            OptionalGroup = qi::omit[qi::lit("[")] >> qi::repeat(2, qi::inf)[(AiasTokenOToken
                    | TokenOToken | RequiredToken | OptionalToken)] >> qi::omit[qi::lit("]")];

            TokenOToken = OptionalGroup[phx::bind(&classsyntax_group, sprt::_val, sprt::_1)];

            AiasTokenOToken = (SyntaxField_ >> OptionalGroup)
                    [phx::bind(&classsyntax_agroup, sprt::_val, sprt::_1, sprt::_2)];

            RequiredToken = (SyntaxField_[phx::bind(&classsyntax_alias, sprt::_val, sprt::_1)])
                    || PrimitiveFieldName_[phx::bind(&classsyntax_field, sprt::_val, sprt::_1)];

            OptionalToken %= (qi::omit[qi::lit("[")] >> RequiredToken >> qi::omit[qi::lit("]")]
                    )[phx::bind(&classsyntax_optional, sprt::_val)];




        }

    }
}