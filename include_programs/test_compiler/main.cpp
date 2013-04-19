/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/


#include <iostream>
#include <string>

#include <boost/itu/x68X/parser.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

std::string IN_FILE = "test.asn";

//#define DEBUGT
#define DEBUG_SUBTYPE_BNF(attr, type) x680::bnf:: ## attr out; success =phrase_parse(beg, src.end(),  x680::bnf:: ## type ,  x680::bnf::comment_skip, out);
#define DEBUG_SUBTYPE(attr, type) attr out; success =phrase_parse(beg, src.end(),   type ,  x680::bnf::comment_skip, out);

int main(int argc, char* argv[]) {
    std::string src;
    std::size_t rs = x680::read_module_file(IN_FILE, src);
    std::cout << "Size: " << rs << std::endl;

    using boost::spirit::qi::parse;
    using boost::spirit::qi::phrase_parse;
    using boost::spirit::qi::_1;
    using boost::spirit::qi::int_;
    using boost::spirit::qi::lexeme;
    using boost::spirit::qi::space;
    using boost::spirit::qi::_val;
    using x680::asn1modules_ptr;
    using x680::asn1modules;




#ifdef DEBUGT
    src = (argc < 2) ? src : std::string(argv[1]);
#endif     
    std::cout << "input:" << src << std::endl;


    bool success = false;
    std::string::iterator beg = src.begin();

x680::bnf::skip_comment_grammar<std::string::iterator> skipper;

#ifdef DEBUGT   
    
    DEBUG_SUBTYPE(x680::bnf::imports, x680::bnf::Imports_)
    out = out;
    
#else
   
    x680::bnf::ModuleDefinition_grammar<std::string::iterator> ModuleDef;
    x680::bnf::module modul ;
    success = phrase_parse(beg, src.end(), ModuleDef, x680::bnf::comment_skip, modul );
    
#endif         

    if (success)
        std::cout << "success:" << (beg == src.end()) << std::endl;
    else {
        std::cout << std::string(beg, src.end()) << std::endl;
    }
}


namespace asn1 {




}
