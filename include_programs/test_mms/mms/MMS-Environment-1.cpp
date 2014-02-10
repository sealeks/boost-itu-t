#include "MMS-Environment-1.hpp"

namespace MMS_Environment_1 {

        // sequence ApplicationReference

        template<> void ApplicationReference::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(ap_title, 0);
            BOOST_ASN_EXPLICIT_TAG(ap_invocation_id, 1);
            BOOST_ASN_CHOICE_TAG(ae_qualifier, 2);
            BOOST_ASN_EXPLICIT_TAG(ae_invocation_id, 3);
        }

        template<> void ApplicationReference::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(ap_title, 0);
            BOOST_ASN_EXPLICIT_TAG(ap_invocation_id, 1);
            BOOST_ASN_CHOICE_TAG(ae_qualifier, 2);
            BOOST_ASN_EXPLICIT_TAG(ae_invocation_id, 3);
        }

 
} 
