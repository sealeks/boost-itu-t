//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1STREAM_IMPLEMENTATIUON_H_
#define         _ITU_ASN1STREAM_IMPLEMENTATIUON_H_


#ifdef _MSC_VER
#if _MSC_VER >= 1800
#ifndef UNICODE
#define UNICODE
#endif
#endif
#endif

#include <boost/itu/coder/base_coder.hpp>


namespace boost {
    namespace asn1 {

        using boost::itu::encoding_rule;
        
        using boost::itu::BER_ENCODING;
        using boost::itu::CER_ENCODING;
        using boost::itu::DER_ENCODING;
        using boost::itu::PER_ALIGNED_ENCODING;
        using boost::itu::PER_UNALIGNED_ENCODING;
        using boost::itu::CPER_ALIGNED_ENCODING;
        using boost::itu::CPER_UNALIGNED_ENCODING;
       


        class asn1_stream {

        public:

            asn1_stream(encoding_rule rl);

            ~asn1_stream() {
            }


        private:

            asn_coder_ptr coder;
        };

    }
} // namespace boost



#endif // _ITU_ASN1STREAM_IMPLEMENTATIUON_H_

