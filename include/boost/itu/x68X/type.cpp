//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {
        
        static SequenceType_grammar SequenceType;

        void Type_grammar::init(){
        start_rule = (BuiltinType | ReferencedType)/* | ConstrainedType_[bind(&self_type::operator(), *this, qi::_val, qi::_1)];*/;
    }

        void ComponentType_grammar::init() {
           /* start_rule = identifier_[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                    >> Type[bind(&self_type::element, *this, qi::_val, qi::_1)]
                    >> -(OPTIONAL_[bind(&self_type::element, *this, qi::_val, mk_optional)]
                    | DEFAULT_[bind(&self_type::element, *this, qi::_val, mk_default)]);*/
        }
        
        
         void SequenceType_grammar::init() {       
                   /*    start_rule = qi::lexeme[SEQUENCE_[bind(&self_type::operator(), *this, qi::_val)]] 
                        >> qi::lit("{") 
                        >> *(Component[bind(&self_type::operator(), *this, qi::_val, qi::_1)])
                        >> qi::lit("}");*/
                       
         }


    }
}