//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {

        Type_grammar<std::string::iterator> Type_;

        //syn_elements_sk_rule Types_ = Type_ % qi::omit[*qi::space];


    }
}