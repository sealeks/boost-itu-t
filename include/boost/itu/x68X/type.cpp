//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {

        void Type_grammar::init() {
            
             start_rule = typereference_[bind(&self_type::identifier, *this, qi::_val, qi::_1)]
                        >> qi::lexeme[qi::lit("::=")]
                        >> FullType[bind(&self_type::type, *this, qi::_val, qi::_1)];          
            
             FullType =TaggedType  | Type;

            DefinedType = DefinedType_[bind(&self_type::refference, *this, qi::_val, qi::_1)];

            ReferencedType = DefinedType;

            SimpleType = ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&self_type::defftype, *this, qi::_val, t_OCTET_STRING)]
                    | (qi::lexeme[CHARACTER_ >> +qi::blank >> STRING_])[bind(&self_type::defftype, *this, qi::_val, t_CHARACTER_STRING)]
                    | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&self_type::defftype, *this, qi::_val, t_EMBEDDED_PDV)]
                    | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&self_type::defftype, *this, qi::_val, t_OBJECT_IDENTIFIER)]
                    | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&self_type::defftype, *this, qi::_val, t_DATE_TIME)]
                    | simple_typer[bind(&self_type::defftype, *this, qi::_val, qi::_1)]
                    );

            IntegerType = INTEGER_[bind(&self_type::defftype, *this, qi::_val, t_INTEGER)]
                    >> -NamedNumberList[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];

            EnumeratedType = ENUMERATED_[bind(&self_type::defftype, *this, qi::_val, t_ENUMERATED)]
                    >> -Enumerations[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];

            BitStringType = qi::lexeme[BIT_ >> +qi::blank >> STRING_[bind(&self_type::defftype, *this, qi::_val, t_BIT_STRING)]]
                    >> -NameBitList[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];
            
            

            BuitinType = SimpleType | IntegerType | EnumeratedType | BitStringType;

            Type = BuitinType | DefinedType;
            
            TaggedType = Tag[bind(&self_type::tagset, *this, qi::_val, qi::_1)]
                    >> Type;

        }
    }
}