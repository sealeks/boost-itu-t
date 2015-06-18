//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/parser.hpp>

namespace x680 {
    

    namespace fsnsp = boost::filesystem;

    bool dir_exists(const std::string& path) {
        fsnsp::path p(path.c_str());
        return (fsnsp::exists(p) && fsnsp::is_directory(p));
    }

    bool dir_create(const std::string& path, const std::string& outdir) {
        //std::string newpath = path  + outdir;
        boost::filesystem::path p(path.c_str());
        boost::filesystem::path f(outdir.c_str());
        boost::filesystem::path r = p / f;
        std::string newpath = r.generic_string();
        if (!dir_exists(newpath))
            return fsnsp::create_directory(fsnsp::path(newpath.c_str()));
        return true;
    }    
    

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

    bool base_options::option_define_struct() const {
        return static_cast<bool>(opt_.count("def_struct"));
    }

    bool base_options::option_c11() const {
        return static_cast<bool>(opt_.count("standard11"));
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
    
    std::string base_options::option_httpoutdir() const {
        std::string rslt = opt_.count("httpoutdir") ? 
            opt_["httpoutdir"].as<std::string>() :  "";
        return !rslt.empty() ? rslt : "httpout";
    }         
    

    
}