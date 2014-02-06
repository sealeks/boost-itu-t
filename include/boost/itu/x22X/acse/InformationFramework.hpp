#ifndef ___INFORMATIONFRAMEWORK
#define ___INFORMATIONFRAMEWORK

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace InformationFramework {

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

    struct Name;
    struct AttributeTypeAndDistinguishedValue;
    struct Context;

    typedef enumerated_type AttributeUsage;


}
#include "UsefulDefinitions.hpp"

namespace InformationFramework {

    // import   from  UsefulDefinitions




    extern const int AttributeUsage_userApplications;
    extern const int AttributeUsage_directoryOperation;
    extern const int AttributeUsage_distributedOperation;
    extern const int AttributeUsage_dSAOperation;

    extern const boost::asn1::oid_type id_mr_distinguishedNameMatch;

    extern const boost::asn1::oid_type id_mr_objectIdentifierMatch;

    extern const boost::asn1::oid_type id_at_objectClass;

    extern const boost::asn1::oid_type id_at_aliasedEntryName;


}

BOOST_ASN_CHOICE_REGESTRATE(InformationFramework::Name)

#endif  /*___INFORMATIONFRAMEWORK */

