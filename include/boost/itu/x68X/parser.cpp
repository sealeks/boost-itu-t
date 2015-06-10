//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/parser.hpp>

namespace x680 {

    bool base_options::option_no_holder() const {
        return static_cast<bool>(opt_.count("noholder"));
    }

    bool base_options::option_reverse_decl() const {
        return static_cast<bool>(opt_.count("reverse"));
    }

    bool base_options::option_ber_main() const {
        return static_cast<bool>(opt_.count("bermain"));
    }

    bool base_options::option_cout_metod() const {
        return static_cast<bool>(opt_.count("cout_meth"));
    }

    std::string base_options::option_path() const {
        return opt_.count("path") ?
                opt_["path"].as<std::string>() : "";
    }

    std::string base_options::option_outdir() const {
        std::string rslt = opt_.count("outdir") ? 
            opt_["outdir"].as<std::string>() :  "";
        return !rslt.empty() ? rslt : "out";
    }     
    

    
}