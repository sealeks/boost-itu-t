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
//#include <regex>

#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/asnbase.hpp>
#include <set>
#include <limits>

#define ASN1TST
#define X961_TEST

#ifdef ASN1TST

#include "Test1.hpp"

#ifdef X961_TEST
typedef boost::asn1::x691::input_coder x69X_input_coder_type;
typedef boost::asn1::x691::output_coder x69X_output_coder_type;
typedef boost::itu::asn_coder_templ<x69X_input_coder_type, x69X_output_coder_type> x69X_coder_type;
#else
typedef boost::asn1::x690::input_coder x69X_input_coder_type;
typedef boost::asn1::x690::output_coder x69X_output_coder_type;
typedef boost::itu::asn_coder_templ<x69X_input_coder_type, x69X_output_coder_type> x69X_coder_type;
#endif

using boost::itu::octet_sequnce;
using boost::itu::encoding_rule;


template<typename INPUT_TYPE, typename OUTPUT_TYPE>
class asn1_stream_adaptor {
public:

    typedef INPUT_TYPE input_stream_type;
    typedef OUTPUT_TYPE output_stream_type;
    typedef asn1_stream_adaptor<INPUT_TYPE, OUTPUT_TYPE> self_type;

    asn1_stream_adaptor(input_stream_type& in_, output_stream_type& out_, boost::itu::encoding_rule rl=boost::itu::PER_UNALIGNED_ENCODING)
    : in(in_), out(out_), coder(rl) {
    }

    virtual ~asn1_stream_adaptor() {
    }

    template<typename T>
    friend self_type& operator<<(self_type& stream, const T& vl) {
        /*boost::asn1::bind_basic(*/stream.coder.output() & vl/*)*/;
        const boost::itu::const_sequences& seq = stream.coder.output().buffers();
        std::string strout;
        for (boost::itu::const_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it) {
            strout += std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it));
        }
        stream.out << boost::itu::binary_to_hexsequence_debug(strout,4);
        if ((stream.coder.output().unusebits()) && (!seq.empty())) {
            std::string tmp1(boost::asio::buffer_cast<const char*>(seq.back()), boost::asio::buffer_size(seq.back()));
            if (!tmp1.empty()) {
                std::string tmp(tmp1.rbegin(), tmp1.rbegin() + 1);
                stream.out << " {" << boost::asn1::bitstring_type(tmp, stream.coder.output().unusebits()) << " unus =" << stream.coder.output().unusebits() << "}";
            }
        };
        //stream.out << seq;
        octet_sequnce oseq;
        stream.coder.output().bind(oseq);
        stream.coder.input().add(oseq);
        return stream;
    }

    friend void print_input(self_type& stream) {

        const boost::itu::mutable_sequences& seq = stream.coder.input().buffers();

        if ((stream.coder.input().unusebits()) && (!seq.empty()) && (boost::asio::buffer_size(seq.front()))) {
            std::string tmp(boost::asio::buffer_cast<const char*>(seq.front()), boost::asio::buffer_size(seq.front()));
            boost::uint8_t frnt = tmp.at(0);
            stream.out << " {" << boost::asn1::bitstring_type(frnt, stream.coder.input().unusebits()) << " unus =" << stream.coder.input().unusebits() << "}";
        };

        for (boost::itu::mutable_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it) {
            stream.out << boost::itu::binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
        }

    }

    template<typename T>
    friend self_type& operator>>(self_type& stream, const T& vl) {

        stream.out << "\nbefore: ";
        print_input(stream);

        /*boost::asn1::bind_basic(*/stream.coder.input() & vl/*)*/;

        stream.out << "\n   after: ";
        print_input(stream);

        //stream.out << seq;
        return stream;
    }

private:

    input_stream_type& in;
    output_stream_type& out;
    x69X_coder_type coder;
};


using namespace Test1;
typedef asn1_stream_adaptor<std::istream, std::ostream> asn1_adaptor;

struct testoctet {

    testoctet(octet_sequnce oc, std::size_t un = 0) : oct(oc), unuse(un) {
    }
    octet_sequnce oct;
    std::size_t unuse;
};

void print(const octet_sequnce& vl, std::size_t unuse = 0) {
    std::cout << "  [" << boost::itu::binary_to_hexsequence_debug(std::string((const char*) vl.data(), vl.size()));
    if (unuse) {
        std::cout << " { " << boost::asn1::bitstring_type(octet_sequnce(1, vl.back()), unuse) << " unus =" << unuse << " } ";
    }
    std::cout << "  sz =" << vl.size() << "  ]";
}

void print(const testoctet& vl) {
    print(vl.oct, vl.unuse);
}

void print_in(boost::asn1::x691::input_coder& stream) {

    const boost::itu::mutable_sequences& seq = stream.buffers();

    std::size_t szx = stream.unusebits();

    if ((stream.unusebits()) && (!seq.empty()) && (boost::asio::buffer_size(seq.front()))) {
        std::string tmp(boost::asio::buffer_cast<const char*>(seq.front()), boost::asio::buffer_size(seq.front()));
        boost::uint8_t frnts = tmp.at(0);
        if (szx)
            frnts <<= szx;
        octet_sequnce frnt(1, frnts);
        std::cout << " {" << boost::asn1::bitstring_type(frnt, stream.unusebits()) << " unus =" << stream.unusebits() << "}";
    };

    for (boost::itu::mutable_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it) {
        std::cout << boost::itu::binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
    }

}

testoctet split_bits_in_octets(const testoctet& f1, const testoctet& f2) {
    testoctet tsoct(f1.oct, f1.unuse);
    std::size_t rsltunuse = boost::itu::split_bits_in_octets(tsoct.oct, tsoct.unuse, f2.oct, f2.unuse);
    tsoct.unuse = rsltunuse;
    return tsoct;
}

#else

#define DEBUG_BS(a)  std::cout << #a" = "  << a  << "    bitcnt=" <<  a.sizebits()   << "  unuse="  << a.unusebits()  << " to int="   <<  a.operator uint64_t()<<  std::endl;
typedef boost::asn1::bitstring_type bitstring_type;

#endif

ITU_T_OID(GBASIC_ENCODING_OID, ITU_T_VARRAY(2, 1, 1, 45, 67))

//ITU_T_PER_ENUMCODER_EXT(test,  ITU_T_ARRAY(2, 1, 100, 45, -67), ITU_T_ARRAY(0))


int main(int argc, char* argv[]) {

    //std::cout <<  "    "  <<  GBASIC_ENCODING_OID << std::endl;
    //std::cout <<  "    "  <<  test__coder::from_root(45) <<  "    "  <<   test__coder::to_root(0)  <<   "   "  << test__coder::ext() << std::endl;


#ifdef ASN1TST    

    //PersonnelRecord_impl::Tst_type tstvect({0x120, 0x140, 0x60, 0x121, 0x141, 0x61});

    PersonnelRecord PRt(PersonnelRecord_impl(/*enum1_red, tstvect, */Name(Name_impl(std::string("John"), std::string("P"), std::string("Smith"))),
            "Director",
            EmployeeNumber(51),
            Date("19710917"),
            Name(Name_impl(std::string("Mary"), std::string("T"), std::string("Smith")))));

    PersonnelRecord_impl::Children_type& chlds = *(PRt->children__new());
    chlds.push_back(ChildInformation(Name(Name_impl(std::string("Ralph"), std::string("T"), std::string("Smith"))), Date("19571111")));
    chlds.push_back(ChildInformation(Name(Name_impl(std::string("Susan"), std::string("B"), std::string("Jones"))), Date("19590717")));
    chlds.back().sex(boost::shared_ptr< enumerated_type>( new enumerated_type(ChildInformation::sex_female)));

    PersonnelRecord iPRt;


    testoctet tst1(octet_sequnce({'\xAA', '\xA0'}), 5);
    testoctet tst2(octet_sequnce(1, '\x80'), 7);

    testoctet tst3 = split_bits_in_octets(tst1, tst2);

    //std::size_t rsltunuse = boost::itu::split_bits_in_octets(f1,7,f2,4);


    //print(f1, rsltunuse );

    /* print(tst1);
     std::cout << " + ";
     print(tst2);
     std::cout << " =  ";
     print(tst3);
     std::cout << std::endl;*/


    int PRp = 828;
    int PRp1 = 10;
    boost::asn1::num_constrainter<int> PR(PRp, 88, 1188, true);

    asn1_adaptor adaptor(std::cin, std::cout);

    std::cout << "limits : " << std::numeric_limits<int>::min()  << " : "  << std::numeric_limits<int>::max()  << std::endl;

    adaptor << PRt;

    adaptor >> iPRt;





    /*octet_sequnce tst_seq({'\xAA', '\xAA','\xAA', '\xAA'});
    
     boost::asn1::x691::input_coder  incoder;
    
     incoder.add(tst_seq);

     std::cout << "\nbefore: ";
     print_in(incoder);
    
     bitstring_type tmp1 = incoder.get_pop_bmp(1);
    
    
     std::cout << "\n   tmp 1: " << tmp1;    
    
     std::cout << "\n   after 1: ";
     print_in(incoder);        
    
    
     bitstring_type tmp2 = incoder.get_pop_bmp(2);
    
    
     std::cout << "\n   tmp 2: " << tmp2;    
    
     std::cout << "\n   after 2: ";
     print_in(incoder);        

            
     bitstring_type tmp3 = incoder.get_pop_bmp(3);
    
    
     std::cout << "\n   tmp 3: " << tmp3;    
    
     std::cout << "\n   after 3: ";
     print_in(incoder);    
    
     bitstring_type tmp4 = incoder.get_pop_bmp(5);
    
    
     std::cout << "\n   tmp 4: " << tmp4;    
    
     std::cout << "\n   after 4: ";
     print_in(incoder);    
    
    
     octet_sequnce tmp5 = incoder.get_pop_octs(2);
    
    
     std::cout << "\n   tmp 5: ";;    
     print(tmp5);
    
     std::cout << "\n   after 5: ";
     print_in(incoder);    */

    /*boost::asn1::x691::small_nn_wnumber<std::size_t> SMszr = 63;
    bitstring_type rbmp = boost::asn1::x691::to_x691_cast(SMszr);
    std::cout << "\n small_nn_wnumber bs = " << SMszr.bitsize() << " bvalue= " << rbmp   << std::endl;
    
    boost::asn1::x691::constrained_wnumber<int> CMn(PRp, 0, 1578900444);
     std::cout << "\n constrained bs = " << CMn.bitsize()   << " bvalue = "  << CMn.as_bitmap() <<   " ovalue = "  << CMn.as_octetstring() << std::endl;
     
    boost::asn1::x691::semiconstrained_wnumber<int> semiCMn(PRp1, 3);
    std::cout << "\n semi - constrained bs = " << semiCMn.bitsize()   <<   " ovalue = "  << semiCMn.as_octetstring() << std::endl;     
    
    boost::asn1::x691::unconstrained_wnumber<int> unCMn=PRp;
    std::cout << "\n unconstrained_wnumber bs = " << unCMn.bitsize()   <<   " ovalue = "  << unCMn.as_octetstring() << std::endl;  */

#else    

    //bool a[] ={true, false, true, false};
    bitstring_type tV0 = bitstring_type(true) + bitstring_type(false) + bitstring_type(true);
    bitstring_type tV1(static_cast<boost::int8_t> ('\xFF'), 4);
    bitstring_type tV2 = bitstring_type::create_from_string("0111010101011101010101011101010");
    bitstring_type tV2n = ~tV2;
    bitstring_type tV3 = bitstring_type::create_from_string("10101010101010101010101010101010");
    bitstring_type tV4 = bitstring_type::create_from_string("010101010101010101010101010101010");
    bitstring_type tV0_1 = tV0 ^ tV1;
    bitstring_type tV1_0 = tV1 ^ tV0;
    bitstring_type tV2_3 = tV2 ^ tV3;
    bitstring_type tV3_4 = tV3 ^ tV4;


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
    std::cout << "bool oper = " << (bool)tV2_3 << std::endl;
    std::cout << "bool oper = " << (bool)tV3_4 << std::endl;


#endif











    /*
    typedef std::vector<std::string> intvector_type;

    intvector_type tp {"111", "222", "333"};
    for(const auto itt : tp ) {
       std::cout << itt << " " << std::endl;
    }

   std::vector<int> someList{1,3,2,4,5};
   int total = 0;
   std::for_each(someList.begin(), someList.end(), [&total](int x) {
       total += x;
   });
     * 
   std::cout << total;
    
   typedef std::shared_ptr<int> intshared_type;
    
    intshared_type tstint( new int(10));
   }*/



}

