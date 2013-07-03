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

            SimpleDefinedObjectClass = DefinedObjectClass_[bind(&class_reference, qi::_val, qi::_1)];

            ObjectClassDefn = qi::omit[CLASS_ >> qi::lit("{")] >> FieldSpecs[bind(&class_fields, qi::_val, qi::_1)] >> qi::omit[qi::lit("}")]
                    >> -(WithSyntaxSpec[bind(&class_syntaxes, qi::_val, qi::_1)]);

            UsefulObjectClass = TYPE_IDENTIFIER_[qi::_val = CLASS_TYPE_IDENTIFIER] | ABSTRACT_SYNTAX_[qi::_val = CLASS_ABSTRACT_SYNTAX];

            DefinedObjectClass = UsefulObjectClass | SimpleDefinedObjectClass;

            ParameterizedObjectClass = DefinedObjectClass[qi::_val = qi::_1] >> -(ActualParameters[bind(&class_parameters, qi::_val, qi::_1)]);

            FieldSpecs = FieldSpec % qi::omit[qi::lit(",")];

            FieldSpec = TypeFieldSpecS | FixedTypeValueFieldSpec | FixedTypeValueSetFieldSpec | VariableTypeValueSetFieldSpec | VariableTypeValueFieldSpec | ObjectFieldSpec | ObjectSetFieldSpec | TypeFieldSpec; //;     

            TypeFieldSpecS = (typefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> (OPTIONAL_[bind(&classfield_optional, qi::_val)] | (qi::omit[DEFAULT_]
                    >> Type[bind(&classfield_defaulttype, qi::_val, qi::_1)])))[bind(&classfield_tp, qi::_val, fkind_TypeFieldSpec)];

            TypeFieldSpec = (typefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] | (qi::omit[DEFAULT_]
                    >> Type[bind(&classfield_defaulttype, qi::_val, qi::_1)])))[bind(&classfield_tp, qi::_val, fkind_TypeFieldSpec)];

            FixedTypeValueFieldSpec = valuefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> Type[bind(&classfield_holder_ft, qi::_val, qi::_1, true)]
                    >> -(((UNIQUE_[bind(&classfield_unique, qi::_val)])
                    || OPTIONAL_[bind(&classfield_optional, qi::_val)])
                    | (OPTIONAL_[bind(&classfield_optional, qi::_val)])
                    | (qi::omit[DEFAULT_]
                    >> (Value[bind(&classfield_defaultvalue, qi::_val, qi::_1)])));


            VariableTypeValueFieldSpec = (valuefieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> FieldName_[bind(&classfield_holder, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (Value[bind(&classfield_defaultvalue, qi::_val, qi::_1)]))))[bind(&classfield_tp, qi::_val, fkind_VariableTypeValueFieldSpec)];


            FixedTypeValueSetFieldSpec = (valuesetfieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> Type[bind(&classfield_holder_ft, qi::_val, qi::_1, false)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ValueSet[bind(&classfield_defaultset, qi::_val, qi::_1)]))));


            VariableTypeValueSetFieldSpec = (valuesetfieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> FieldName_[bind(&classfield_holder, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ValueSet[bind(&classfield_defaultset, qi::_val, qi::_1)]))))[bind(&classfield_tp, qi::_val, fkind_VariableTypeValueSetFieldSpec)];


            ObjectFieldSpec = objectfieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> DefinedObjectClass_[bind(&classfield_holder_ov, qi::_val, qi::_1)]
                    >> -((OPTIONAL_[bind(&classfield_optional, qi::_val)])
                    | (qi::omit[DEFAULT_]
                    >> (Object[bind(&classfield_defaultovalue, qi::_val, qi::_1)])));

            ObjectSetFieldSpec = (objectsetfieldreference_[bind(&classfield_field, qi::_val, qi::_1)]
                    >> DefinedObjectClass_[bind(&classfield_holder_ov, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&classfield_optional, qi::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ObjectSet[bind(&classfield_defaultoset, qi::_val, qi::_1)]))));
            ;


            WithSyntaxSpec = qi::omit[ qi::lexeme[WITH_ >> +qi::blank >> SYNTAX_]] >> SyntaxList;
            SyntaxList = qi::omit[qi::lit("{")] >> TokenOrGroupSpec >> qi::omit[qi::lit("}")];
            TokenOrGroupSpec = +(AiasTokenOToken | RequiredToken | OptionalToken | TokenOToken);
            OptionalGroup = qi::omit[qi::lit("[")] >> TokenOrGroupSpec >> qi::omit[qi::lit("]")] >> -qi::omit[qi::lit(",")];
            TokenOToken = OptionalGroup[bind(&classsyntax_group, qi::_val, qi::_1)];
            AiasTokenOToken = (SyntaxField_ >> OptionalGroup)[bind(&classsyntax_agroup, qi::_val, qi::_1, qi::_2)];
            RequiredToken = -(SyntaxField_[bind(&classsyntax_alias, qi::_val, qi::_1)]) >> PrimitiveFieldName_[bind(&classsyntax_field, qi::_val, qi::_1)] >> -qi::omit[qi::lit(",")];
            OptionalToken %= (qi::omit[qi::lit("[")] >> RequiredToken >> qi::omit[qi::lit("]")] >> -qi::omit[qi::lit(",")])[bind(&classsyntax_optional, qi::_val)];














        }

    }
}