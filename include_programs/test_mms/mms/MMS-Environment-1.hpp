#ifndef ___MMS_ENVIRONMENT_1
#define ___MMS_ENVIRONMENT_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {

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


    struct ApplicationReference;



}

#include <boost/itu/x22X/acse/ACSE-1.hpp>

namespace MMS_Environment_1 {

    // import   from  ACSE-1



    // sequence ApplicationReference

    struct ApplicationReference {

        ApplicationReference();

        ApplicationReference(boost::shared_ptr< ACSE_1::AP_title> __ap_title,
                boost::shared_ptr< ACSE_1::AP_invocation_identifier> __ap_invocation_id,
                boost::shared_ptr< ACSE_1::AE_qualifier> __ae_qualifier,
                boost::shared_ptr< ACSE_1::AE_invocation_identifier> __ae_invocation_id);

        BOOST_ASN_VALUE_OPTIONAL_DECL(ap_title, ACSE_1::AP_title);
        BOOST_ASN_VALUE_OPTIONAL_DECL(ap_invocation_id, ACSE_1::AP_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(ae_qualifier, ACSE_1::AE_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(ae_invocation_id, ACSE_1::AE_invocation_identifier);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ACSE_1::AP_title> ap_title_;
        boost::shared_ptr<ACSE_1::AP_invocation_identifier> ap_invocation_id_;
        boost::shared_ptr<ACSE_1::AE_qualifier> ae_qualifier_;
        boost::shared_ptr<ACSE_1::AE_invocation_identifier> ae_invocation_id_;
    };

    template<> void ApplicationReference::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ApplicationReference::serialize(boost::asn1::x690::input_coder& arch);
}


#endif  /*___MMS_ENVIRONMENT_1 */

