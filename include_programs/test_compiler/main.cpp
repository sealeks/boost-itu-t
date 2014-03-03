/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/


#include <iostream>
#include <string>

#include <boost/itu/x68X/parser.hpp>
#include <boost/itu/x68X/cpp_cout.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/utility/value_init.hpp>


std::string IN_FILE = "F:\\test_680\\sourceasn5\\"; // "test.asn";

// -nh
bool getOptRev(int argc, char* argv[]){
    for(int i=0;i<argc;++i)
        if ((std::string(argv[i])=="-r") || (std::string(argv[i])=="r"))
            return true;
    return false;
}

// -nh
bool getOptHolder(int argc, char* argv[]){
    for(int i=0;i<argc;++i)
        if ((std::string(argv[i])=="-nh") || (std::string(argv[i])=="nh"))
            return true;
    return false;
}



int main(int argc, char* argv[]) {

    try {

        if (argc>1){
             IN_FILE = argv[1];
             std::cout << "path : " << IN_FILE << std::endl;}

        x680::global_entity_ptr rsl = x680::semantics::compile_fs(IN_FILE);


       std::cout << "!!!!!!!!!!!!: " << rsl << std::endl;
       
       x680::cpp::fileout fls(rsl, IN_FILE/*,"out", getOptRev(argc, argv ), getOptHolder(argc, argv)*/) ;
       fls.execute();
       
    } catch (const x680::syntactic::synxtas_error& e) {
        std::cout << e << std::endl;
    } catch (const x680::semantics::error& ec) {
        std::cout << ec << std::endl;
    } catch (boost::filesystem::filesystem_error fe) {
        std::cout << "file error: " << fe.what() << std::endl;
    }
    catch(...){}
    return 0;




}


