//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/asn1module.hpp>


namespace x680 {

    std::size_t read_module_file(const std::string path, std::string& src) {

        std::ifstream ifs(path.c_str(), std::ifstream::binary);
        src.clear();
        if (ifs) {
            ifs.seekg(0, ifs.end);
            std::size_t length = ifs.tellg();
            ifs.seekg(0, ifs.beg);
            char * buffer = new char [length];
            ifs.read(buffer, length);
            src.insert(src.end(), buffer, buffer + length);
            delete[] buffer;
        }
        return src.size();
    }


}