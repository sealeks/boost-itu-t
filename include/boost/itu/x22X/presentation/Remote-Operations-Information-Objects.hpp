#ifndef ___REMOTE_OPERATIONS_INFORMATION_OBJECTS
#define ___REMOTE_OPERATIONS_INFORMATION_OBJECTS

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Remote_Operations_Information_Objects {

    using boost::asn1::null_type;
    using boost::asn1::enumerated_type;
    using boost::asn1::bitstring_type;
    using boost::asn1::octetstring_type;
    using boost::asn1::oid_type;
    using boost::asn1::reloid_type;
    using boost::asn1::utctime_type;
    using boost::asn1::gentime_type;
    using boost::asn1::ia5string_type;
    using boost::asn1::printablestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::numericstring_type;
    using boost::asn1::universalstring_type;
    using boost::asn1::bmpstring_type;
    using boost::asn1::utf8string_type;
    using boost::asn1::generalstring_type;
    using boost::asn1::graphicstring_type;
    using boost::asn1::t61string_type;
    using boost::asn1::t61string_type;
    using boost::asn1::videotexstring_type;
    using boost::asn1::objectdescriptor_type;
    using boost::asn1::external_type;
    using boost::asn1::embeded_type;
    using boost::asn1::characterstring_type;
    using boost::asn1::any_type;

    struct Code;

    typedef int Priority;




}

#include <boost/itu/x22X/presentation/Remote-Operations-Useful-Definitions.hpp>

namespace Remote_Operations_Information_Objects {

    // import   from  Remote-Operations-Useful-Definitions




    // choice Code

    enum Code_enum {

        Code_null = 0,
        Code_local,
        Code_global,
    };

    struct Code : public BOOST_ASN_CHOICE_STRUCT(Code_enum) {

        Code() : BOOST_ASN_CHOICE_STRUCT(Code_enum) () {
        }

        BOOST_ASN_VALUE_CHOICE(local, int, Code_local);
        BOOST_ASN_VALUE_CHOICE(global, oid_type, Code_global);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    template<> void Code::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Code::serialize(boost::asn1::x690::input_coder& arch);
}

BOOST_ASN_CHOICE_REGESTRATE(Remote_Operations_Information_Objects::Code)

#endif  /*___REMOTE_OPERATIONS_INFORMATION_OBJECTS */

