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
#include <boost/utility/value_init.hpp>


std::string IN_FILE = "F:\\sourceasn1\\"; // "test.asn";

int main(int argc, char* argv[]) {

    try {


        x680::global_entity_ptr rsl = x680::semantics::compile_fs(IN_FILE);


        std::cout << "!!!!!!!!!!!!: " << (rsl.get()) << std::endl;
    } catch (x680::syntactic::synxtas_error& e) {
        std::cout << e << std::endl;
    } catch (x680::semantics::error& ec) {
        std::cout << ec << std::endl;
    } catch (boost::filesystem::filesystem_error fe) {
        std::cout << "file error: " << fe.what() << std::endl;
    }




}


