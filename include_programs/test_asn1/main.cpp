//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt



#include <boost/itu/coder/asn1_stream.hpp>
#include "unitTest.hpp"


const std::string work_dir = "F:\\test_asn\\";


using namespace boost::asn1;

int main(int argc, char* argv[]) {

    boost::asn1::ioasn1_stream tststrm(boost::itu::BER_ENCODING/*boost::itu::PER_UNALIGNED_ENCODING*/, 1);

    //boost::asn1::fasn1_stream tsstr(boost::itu::PER_UNALIGNED_ENCODING, work_dir + "test.ber");

    //Test1::test(tststrm);
    //Test1b::test(tststrm);

    TestTm::test(tststrm);


}
