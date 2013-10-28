//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {


        // Type_grammar

        void Modules_grammar::initClf() {



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectClassAssignment grammar
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////   


            

            FieldSpec = TypeFieldSpecS | FixedTypeValueFieldSpecMS
                    | FixedTypeValueFieldSpecLS | FixedTypeValueSetFieldSpecLS
                    | VariableTypeValueSetFieldSpec | VariableTypeValueFieldSpec
                    | ObjectFieldSpecLS | ObjectSetFieldSpecLS
                    | FixedUndefFieldSpec | FixedUndefSetFieldSpec
                    | TypeFieldSpec; //;     

            TypeFieldSpecS = (typefieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> (OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] | (qi::omit[DEFAULT_]
                    >> Type[phx::bind(&classfield_defaulttype, sprt::_val, sprt::_1)])))
                    [phx::bind(&classfield_tp, sprt::_val, fkind_TypeFieldSpec)];

            TypeFieldSpec = (typefieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] | (qi::omit[DEFAULT_]
                    >> Type[phx::bind(&classfield_defaulttype, sprt::_val, sprt::_1)])))
                    [phx::bind(&classfield_tp, sprt::_val, fkind_TypeFieldSpec)];


            FixedTypeValueFieldSpecMS = valuefieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> Type[phx::bind(&classfield_holder_ft, sprt::_val, sprt::_1, true)]
                    >> UNIQUE_[phx::bind(&classfield_unique, sprt::_val)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)]);

            FixedTypeValueFieldSpecLS = valuefieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> StrictType[phx::bind(&classfield_holder_ft, sprt::_val, sprt::_1, true)]
                    >> -(((UNIQUE_[phx::bind(&classfield_unique, sprt::_val)])
                    || OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)])
                    | (qi::omit[DEFAULT_]
                    >> (Value[phx::bind(&classfield_defaultvalue, sprt::_val, sprt::_1)])));


            VariableTypeValueFieldSpec = (valuefieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> FieldName_[phx::bind(&classfield_holder, sprt::_val, sprt::_1)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (Value[phx::bind(&classfield_defaultvalue, sprt::_val, sprt::_1)]))))
                    [phx::bind(&classfield_tp, sprt::_val, fkind_VariableTypeValueFieldSpec)];


            FixedTypeValueSetFieldSpecLS = (valuesetfieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> StrictType[phx::bind(&classfield_holder_ft, sprt::_val, sprt::_1, false)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ValueSet[phx::bind(&classfield_defaultset, sprt::_val, sprt::_1)]))));


            VariableTypeValueSetFieldSpec = (valuesetfieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> FieldName_[phx::bind(&classfield_holder, sprt::_val, sprt::_1)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ValueSet[phx::bind(&classfield_defaultset, sprt::_val, sprt::_1)]))))
                    [phx::bind(&classfield_tp, sprt::_val, fkind_VariableTypeValueSetFieldSpec)];


            ObjectFieldSpecLS = objectfieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> UsefulObjectClass[phx::bind(&classfield_holder_cl, sprt::_val, sprt::_1, true)]
                    >> -((OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)])
                    | (qi::omit[DEFAULT_]
                    >> (Object[phx::bind(&classfield_defaultovalue, sprt::_val, sprt::_1)])));

            ObjectSetFieldSpecLS = (objectsetfieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> UsefulObjectClass[phx::bind(&classfield_holder_cl, sprt::_val, sprt::_1, false)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ObjectSet[phx::bind(&classfield_defaultoset, sprt::_val, sprt::_1)]))));

            FixedUndefFieldSpec = valuefieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> DefinedType_[phx::bind(&classfield_holder_undf, sprt::_val, sprt::_1, true)]
                    >> -(((UNIQUE_[phx::bind(&classfield_unique, sprt::_val)])
                    || OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)])
                    | (OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)])
                    | (qi::omit[DEFAULT_]
                    >> (ValueOrObject[phx::bind(&classfield_defaultov, sprt::_val, sprt::_1)])));

            FixedUndefSetFieldSpec = (valuesetfieldreference_[phx::bind(&classfield_field, sprt::_val, sprt::_1)]
                    >> DefinedType_[phx::bind(&classfield_holder_undf, sprt::_val, sprt::_1, false)]
                    >> -(OPTIONAL_[phx::bind(&classfield_optional, sprt::_val)] |
                    (qi::omit[DEFAULT_]
                    >> (ValueSetOrObjectSet[phx::bind(&classfield_defaultos, sprt::_val, sprt::_1)]))));



        }

    }
}