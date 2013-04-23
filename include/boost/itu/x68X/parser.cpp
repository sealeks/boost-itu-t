//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/parser.hpp>

namespace x680 {
    namespace bnf {

        strvect_sk_rule Exports_ = qi::lexeme[ qi::omit[EXPORTS_ >> +qi::space] ]
                >> -(!qi::lit(";")
                >> (qi::omit[ALL_] | SymbolList_))
        >> qi::omit[qi::lit(";")];


        SymbolsFromModule_grammar<std::string::iterator> SymbolsFromModule_;

        imports_sk_rule SymbolsFromModules_ = *SymbolsFromModule_;

        imports_sk_rule Imports_ = qi::lexeme[ qi::omit[IMPORTS_ >> +qi::space] ]
                >> -(!qi::lit(";")
                >> (SymbolsFromModules_))
        >> qi::omit[qi::lit(";")];

        ModuleDefinition_grammar<std::string::iterator> ModuleDefinition_;

    }
}