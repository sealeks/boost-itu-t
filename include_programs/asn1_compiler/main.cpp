//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/itu/x68X/parser.hpp>
#include <boost/itu/x68X/cpp_cout.hpp>
#include <boost/itu/x68X/debug_cout.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int ac, char* av[]) {

    try {

        po::options_description desc("Allowed options");
        desc.add_options()
                ("help,h", "produce a help screen")
                ("path,p", po::value<std::string>(), "compile path")
                ("outdir,o", po::value<std::string>(), "out directory")
                ("reverse,r", "reverserse type declaretion in module")
                ("bermain,b", "ber serialization method saves in main cpp module")
                ("cout_noprint,x", "no print cout")        
                ("cout_meth,c", "geterate cout methods for structured type")
                ("noholder,n", "compile strucrured type without asn1::holder<> ");

        x680::compile_option option;

        po::parsed_options parsed = po::command_line_parser(ac, av).options(desc).allow_unregistered().run();
        po::store(parsed, option);

        if (option.count("path")) {

            std::string PATH = option["path"].as<std::string>();

            std::cout << "Path = " << PATH << std::endl;

            x680::global_entity_ptr rsl = x680::semantics::compile_fs(PATH);

            if (!option.count("cout_noprint")) {
                x680::print(std::cout, rsl);
                std::cout << std::endl;
            }

            x680::cpp::cppout fls(rsl, option);
            fls.execute();
        } else {
            std::cout << "path doesn't found!" << std::endl;
            return 1;
        }
           
    } catch (const x680::syntactic::synxtas_error& e) {
        std::cout << e << std::endl;
    } catch (const x680::semantics::error& ec) {
        std::cout << ec << std::endl;
    } catch (boost::filesystem::filesystem_error fe) {
        std::cout << "file error: " << fe.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    } catch (...) {
        std::cout << "undefined ore options error " << std::endl;
        return 1;
    }
    return 0;

}


