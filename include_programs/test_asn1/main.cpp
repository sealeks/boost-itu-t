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
#include <regex>

#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/asnbase.hpp>

#include "Test1.hpp"

typedef boost::asn1::x690::input_coder x690_input_coder_type;
typedef boost::asn1::x690::output_coder x690_output_coder_type;
typedef boost::itu::asn_coder_templ<x690_input_coder_type, x690_output_coder_type> x690_coder_type;

template<typename INPUT_TYPE, typename OUTPUT_TYPE>
class asn1_stream_adaptor {
public:

    typedef INPUT_TYPE input_stream_type;
    typedef OUTPUT_TYPE output_stream_type;
    typedef asn1_stream_adaptor<INPUT_TYPE, OUTPUT_TYPE> self_type;

    asn1_stream_adaptor(input_stream_type& in_, output_stream_type& out_)
    : in(in_), out(out_) {
    }

    virtual ~asn1_stream_adaptor() {
    }

    template<typename T>
    friend self_type& operator<<(self_type& stream, const T& vl) {
        /*boost::asn1::bind_basic(*/stream.coder.output() & vl/*)*/;
        const boost::itu::const_sequences& seq = stream.coder.output().buffers();
        for (boost::itu::const_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it) {
            stream.out << boost::itu::binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
            //stream.out << seq;
        }
        return stream;
    }

private:

    input_stream_type& in;
    output_stream_type& out;
    x690_coder_type coder;
};





#define DEBUG_BS(a)  std::cout << #a" = "  << a  << "    bitcnt=" <<  a.sizebits()   << "  unuse="  << a.unusebits()  << " to int="   <<  a.operator uint64_t()<<  std::endl;

typedef boost::asn1::bitstring_type bitstring_type;
typedef std::vector<std::string> intvector_type;

using namespace Test1;

typedef asn1_stream_adaptor<std::istream, std::ostream> asn1_adaptor;


int main(int argc, char* argv[]) {

     /*intvector_type tp {"111", "222", "333"};
     for(const auto itt : tp ) {
        std::cout << itt << " " << std::endl;
     }

    std::vector<int> someList{1,3,2,4,5};
    int total = 0;
    std::for_each(someList.begin(), someList.end(), [&total](int x) {
        total += x;
    });
    std::cout << total;
    
    typedef std::shared_ptr<int> intshared_type;
    
     intshared_type tstint( new int(10));
     
    // std::string ttt =u8"yyyyy : \u2018";


    const char *reg_esp = "[ ,.\\t\\n;:]"; 

    std::regex rgx(reg_esp);
    std::cmatch match;
    const char *target = "Unseen, University - Ankh-Morpork";*/

    //if (std::regex_search(target, match, rgx)) {

      /*  const size_t n = match.size();
        for (size_t a = 0; a < n; a++) {
            std::string str(match[a].first, match[a].second);
            std::cout << str << "\n";
        }*/
    //}
    
    
    
     
    /*bitstring_type tV0(static_cast<boost::int8_t>('\xFF'),7);
    bitstring_type tV1(static_cast<boost::int8_t>('\xFF'),4);
    bitstring_type tV2=bitstring_type::create_from_string("0111010101011101010101011101010");
    bitstring_type tV2n=~tV2;
    bitstring_type tV3=bitstring_type::create_from_string("10101010101010101010101010101010");
    bitstring_type tV4=bitstring_type::create_from_string("010101010101010101010101010101010"); 
    bitstring_type tV0_1=tV0 ^ tV1;
    bitstring_type tV1_0=tV1 ^ tV0;    
    bitstring_type tV2_3=tV2 ^ tV3;
    bitstring_type tV3_4=tV3 ^ tV4;
    
    
    DEBUG_BS(tV0)    
    DEBUG_BS(tV1)
    DEBUG_BS(tV2)    
    DEBUG_BS(tV2n)             
    DEBUG_BS(tV3)  
    DEBUG_BS(tV4)     
    DEBUG_BS(tV0_1)   
    DEBUG_BS(tV1_0)             
    DEBUG_BS(tV2_3)   
    DEBUG_BS(tV3_4)               
    std::cout << "bool oper = " << (bool)tV2_3  << std::endl;
    std::cout << "bool oper = " << (bool)tV3_4  << std::endl;  */
    
    

    PersonnelRecord PR(PersonnelRecord_impl(Name(Name_impl(std::string("John"), std::string("P"), std::string("Smith"))),
            "Director",
            EmployeeNumber(51),
            Date("19710917"),
            Name(Name_impl(std::string("Mary"), std::string("T"), std::string("Smith")))));

    PersonnelRecord_impl::Children_type& chlds = *(PR->children__new());
    chlds.push_back(ChildInformation(Name(Name_impl(std::string("Ralph"), std::string("T"), std::string("Smith"))), Date("19571111")));
    chlds.push_back(ChildInformation(Name(Name_impl(std::string("Susan"), std::string("B"), std::string("Jones"))), Date("19590717")));

    asn1_adaptor adaptor(std::cin, std::cout);

    adaptor << PR;


}

