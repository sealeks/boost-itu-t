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


std::string IN_FILE ="F:\\sourceasn\\"; // "test.asn";



int main(int argc, char* argv[]) {
    std::string src;


    try {
        x680::syntactic::modules moduls;
        success = x680::syntactic::parse_fs(IN_FILE, moduls);
 
        switch (success) {
            case 0:
            {
                for (x680::syntactic::modules::const_iterator mod = moduls.begin(); mod != moduls.end(); ++mod) {
                    x680::syntactic::module modul = *mod;
                    std::cout << "module:" << mod->name << std::endl;
                    for (x680::syntactic::assignment_vector::const_iterator it = modul.elements.begin(); it != modul.elements.end(); ++it) {
                        std::cout << "which:" << it->which() << std::endl;
                        switch (it->which()) {
                            case 0:
                            {
                                x680::syntactic::type_assignment type = boost::get<x680::syntactic::type_assignment>(*it);
                                type = type;
                                std::cout << "type :" << type.identifier << " type:" << (int) type.type.builtin_t << std::endl;
                                break;
                            }
                            case 1:
                            {
                                x680::syntactic::value_assignment value = boost::get<x680::syntactic::value_assignment>(*it);
                                value = value;
                                std::cout << "value :" << value.identifier << " type:" << (int) value.value.type << std::endl;
                                break;

                            }
                            case 2:
                            {
                                x680::syntactic::valueset_assignment value = boost::get<x680::syntactic::valueset_assignment>(*it);
                                value = value;
                                break;
                            }
                            case 3:
                            {
                                x680::syntactic::class_assignment value = boost::get<x680::syntactic::class_assignment>(*it);
                                value = value;
                                std::cout << "class :" << value.identifier << std::endl;
                                for (x680::syntactic::classfield_vector::const_iterator it = value.class_.fields.begin(); it != value.class_.fields.end(); ++it) {
                                    std::cout << "______classfield :" << it->field << " kind: " << (int) it->tp << std::endl;
                                }
                                break;
                            }
                            case 4:
                            {
                                x680::syntactic::object_assignment value = boost::get<x680::syntactic::object_assignment>(*it);
                                value = value;
                                break;
                            }
                            case 5:
                            {
                                x680::syntactic::objectset_assignment value = boost::get<x680::syntactic::objectset_assignment>(*it);
                                value = value;
                                break;
                            }
                            case 6:
                            {
                                x680::syntactic::unknown_tc_assignment value = boost::get<x680::syntactic::unknown_tc_assignment>(*it);
                                value = value;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case x680::syntactic::PARSE_ESYNXTAS:
            {
                std::cout << "Synctatic error: " << std::endl;
                break;
            }
            default:
            {
                std::cout << "File read error: " << std::endl;
                break;
            }
        }
    }    catch (x680::syntactic::synxtas_error& e) {
        std::cout << e << std::endl;
    }
    catch(boost::filesystem::filesystem_error fe){
        std::cout << "file error: " << fe.what() << std::endl;
    }



}


