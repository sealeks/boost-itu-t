//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <cstdlib>
#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/asnbase.hpp>
#include <set>
#include <limits>

#include <boost/itu/coder/asn1_stream.hpp>
#include "Test1.hpp"


using namespace Test1;

int main(int argc, char* argv[]) {
    
    boost::asn1::ioasn1_stream tsstr(boost::itu::BER_ENCODING);

    PersonnelRecord PRt(Name("John", "P", "Smith"),
            "Director",
            EmployeeNumber(51),
            Date("19710917"),
            Name("Mary", "T", "Smith"));

    PersonnelRecord::Children_type& chlds = *(PRt.children__new());
    chlds.push_back(ChildInformation(Name("Ralph", "T", "Smith"), Date("19571111")));
    chlds.push_back(ChildInformation(Name("Susan", "B", "Jones"), Date("19590717")));
    chlds.back().sex(boost::shared_ptr< enumerated>(new enumerated(ChildInformation::sex_female)));

    PersonnelRecord_s iPRt;

    Ax TstA(253, true, Ax::C_type(true, Ax::C_type_e));
    TstA.g("123");
    TstA.h(true);
    Ax iTstA;


    tsstr << PRt;
    tsstr >> iPRt;
}





















/*void print_in(boost::asn1::x691::input_coder& stream) {

    const boost::itu::mutable_sequences& seq = stream.buffers();

    std::size_t szx = stream.unusebits();

    if ((stream.unusebits()) && (!seq.empty()) && (boost::asio::buffer_size(seq.front()))) {
        std::string tmp(boost::asio::buffer_cast<const char*>(seq.front()), boost::asio::buffer_size(seq.front()));
        boost::uint8_t frnts = tmp.at(0);
        if (szx)
            frnts <<= szx;
        octet_sequnce frnt(1, frnts);
        std::cout << " {" << boost::asn1::bit_string(frnt, stream.unusebits()) << " unus =" << stream.unusebits() << "}";
    };

    for (boost::itu::mutable_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it) {
        std::cout << boost::itu::binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
    }

}*/