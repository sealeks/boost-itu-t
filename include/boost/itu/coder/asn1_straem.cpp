//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>


#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#include <boost/itu/coder/asn1_stream.hpp>



namespace boost {
    namespace asn1 {

        typedef boost::asn1::x690::input_coder X690_input_coder_type;
        typedef boost::asn1::x690::output_coder X690_output_coder_type;
        typedef boost::itu::asn_coder_templ<X690_input_coder_type, X690_output_coder_type> X690_coder_type;

        typedef boost::asn1::x691::input_coder X691_input_coder_type;
        typedef boost::asn1::x691::output_coder X691_output_coder_type;
        typedef boost::itu::asn_coder_templ<X691_input_coder_type, X691_output_coder_type> X691_coder_type;

        static asn_coder_ptr build_coder(encoding_rule rl) {

            switch (rl) {
                case boost::itu::BER_ENCODING:
                case boost::itu::DER_ENCODING:
                case boost::itu::CER_ENCODING: return asn_coder_ptr(new X690_coder_type(NULL_OID, rl));
                case boost::itu::PER_ALIGNED_ENCODING:
                case boost::itu::PER_UNALIGNED_ENCODING:
                case boost::itu::CPER_ALIGNED_ENCODING:
                case boost::itu::CPER_UNALIGNED_ENCODING: return asn_coder_ptr(new X691_coder_type(NULL_OID, rl));
                default:
                {
                }
            }
            return asn_coder_ptr();
        }

        asn1_stream::asn1_stream(encoding_rule rl)
        : coder(build_coder(rl)) {
        }
    


    }


}
