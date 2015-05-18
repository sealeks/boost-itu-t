#ifndef ___REMOTE_OPERATIONS_USEFUL_DEFINITIONS
#define ___REMOTE_OPERATIONS_USEFUL_DEFINITIONS

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Remote_Operations_Useful_Definitions {

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
    using boost::asn1::value_holder;
    using boost::asn1::default_holder;
    using boost::shared_ptr;



}

#include <boost/itu/x22X/presentation/Remote-Operations-Information-Objects.hpp>
#include <boost/itu/x22X/presentation/Remote-Operations-Generic-ROS-PDUs.hpp>

namespace Remote_Operations_Useful_Definitions {

    // import   from  Remote-Operations-Information-Objects

    using Remote_Operations_Information_Objects::Code;


    // import   from  Remote-Operations-Generic-ROS-PDUs

    using Remote_Operations_Generic_ROS_PDUs::InvokeId;


}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___REMOTE_OPERATIONS_USEFUL_DEFINITIONS */
