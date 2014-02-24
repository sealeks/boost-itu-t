#ifndef ___ACSE_1
#define ___ACSE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {

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


    struct ACSE_apdu;
    struct AARQ_apdu_impl;
    struct AARE_apdu_impl;
    struct RLRQ_apdu_impl;
    struct RLRE_apdu_impl;
    struct ABRT_apdu_impl;
    struct A_DT_apdu_impl;
    struct ACRQ_apdu_impl;
    struct ACRP_apdu_impl;
    struct AP_title;
    struct ASO_qualifier;
    struct AE_title;
    struct Syntactic_context_list;
    struct Associate_source_diagnostic;
    struct User_Data;
    struct PDV_list;
    struct Authentication_value;
    struct ASOI_tag_sequence_of;
    struct Context_list_sequence_of;
    struct Default_Context_List_sequence_of;
    struct P_context_result_list_sequence_of;


    typedef enumerated_type ABRT_diagnostic;
    typedef int ABRT_source;
    typedef bitstring_type ACSE_requirements;
    typedef oid_type ASO_context_name;
    typedef octetstring_type AP_title_form1;
    typedef octetstring_type ASO_qualifier_form1;
    typedef oid_type AP_title_form2;
    typedef int ASO_qualifier_form2;
    typedef printablestring_type AP_title_form3;
    typedef printablestring_type ASO_qualifier_form3;
    typedef octetstring_type AE_title_form1;
    typedef oid_type AE_title_form2;
    typedef int AE_invocation_identifier;
    typedef int AP_invocation_identifier;
    typedef int ASOI_identifier;
    typedef oid_type Abstract_syntax_name;
    typedef int Result;
    typedef oid_type Transfer_syntax_name;
    typedef int Associate_result;
    typedef octetstring_type Simply_encoded_data;
    typedef int Presentation_context_identifier;
    typedef graphicstring_type Implementation_data;
    typedef oid_type Mechanism_name;
    typedef int Release_request_reason;
    typedef int Release_response_reason;
    typedef std::vector< external_type > Association_data;

    BOOST_ASN_IMPLICIT_TYPEDEF(AARQ_apdu, AARQ_apdu_impl, 0, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(AARE_apdu, AARE_apdu_impl, 1, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(RLRQ_apdu, RLRQ_apdu_impl, 2, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(RLRE_apdu, RLRE_apdu_impl, 3, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(ABRT_apdu, ABRT_apdu_impl, 4, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(A_DT_apdu, A_DT_apdu_impl, 5, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(ACRQ_apdu, ACRQ_apdu_impl, 6, APPLICATION_CLASS);
    BOOST_ASN_IMPLICIT_TYPEDEF(ACRP_apdu, ACRP_apdu_impl, 7, APPLICATION_CLASS);
    typedef ASO_context_name Application_context_name;
    typedef ASO_qualifier AE_qualifier;
    typedef Transfer_syntax_name Concrete_syntax_name;
    typedef Association_data User_information;
    typedef std::vector< ASOI_tag_sequence_of > ASOI_tag;
    typedef std::vector< ASO_context_name > ASO_context_name_list;
    typedef std::vector< Context_list_sequence_of > Context_list;
    typedef std::vector< Default_Context_List_sequence_of > Default_Context_List;
    typedef std::vector< P_context_result_list_sequence_of > P_context_result_list;

    extern const oid_type acse_as_id;
    extern const oid_type aCSE_id;

}


namespace ACSE_1 {


    // choice ACSE-apdu

    enum ACSE_apdu_enum {

        ACSE_apdu_null = 0,
        ACSE_apdu_aarq,
        ACSE_apdu_aare,
        ACSE_apdu_rlrq,
        ACSE_apdu_rlre,
        ACSE_apdu_abrt,
        ACSE_apdu_adt,
        ACSE_apdu_acrq,
        ACSE_apdu_acrp,
    };

    struct ACSE_apdu : public BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) {

        ACSE_apdu() : BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) () {
        }

        template<typename T > ACSE_apdu(boost::shared_ptr< T> vl, ACSE_apdu_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(aarq, AARQ_apdu, ACSE_apdu_aarq);
        BOOST_ASN_VALUE_CHOICE(aare, AARE_apdu, ACSE_apdu_aare);
        BOOST_ASN_VALUE_CHOICE(rlrq, RLRQ_apdu, ACSE_apdu_rlrq);
        BOOST_ASN_VALUE_CHOICE(rlre, RLRE_apdu, ACSE_apdu_rlre);
        BOOST_ASN_VALUE_CHOICE(abrt, ABRT_apdu, ACSE_apdu_abrt);
        BOOST_ASN_VALUE_CHOICE(adt, A_DT_apdu, ACSE_apdu_adt);
        BOOST_ASN_VALUE_CHOICE(acrq, ACRQ_apdu, ACSE_apdu_acrq);
        BOOST_ASN_VALUE_CHOICE(acrp, ACRP_apdu, ACSE_apdu_acrp);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // sequence AARQ-apdu

    struct AARQ_apdu_impl {

        static const bitstring_type version1;

        static const bitstring_type protocol_version__default;

        AARQ_apdu_impl();

        AARQ_apdu_impl(const ASO_context_name& __aSO_context_name);

        AARQ_apdu_impl(boost::shared_ptr< bitstring_type> __protocol_version,
                boost::shared_ptr< ASO_context_name> __aSO_context_name,
                boost::shared_ptr< AP_title> __called_AP_title,
                boost::shared_ptr< AE_qualifier> __called_AE_qualifier,
                boost::shared_ptr< AP_invocation_identifier> __called_AP_invocation_identifier,
                boost::shared_ptr< AE_invocation_identifier> __called_AE_invocation_identifier,
                boost::shared_ptr< AP_title> __calling_AP_title,
                boost::shared_ptr< AE_qualifier> __calling_AE_qualifier,
                boost::shared_ptr< AP_invocation_identifier> __calling_AP_invocation_identifier,
                boost::shared_ptr< AE_invocation_identifier> __calling_AE_invocation_identifier,
                boost::shared_ptr< ACSE_requirements> __sender_acse_requirements,
                boost::shared_ptr< Mechanism_name> __mechanism_name,
                boost::shared_ptr< Authentication_value> __calling_authentication_value,
                boost::shared_ptr< ASO_context_name_list> __aSO_context_name_list,
                boost::shared_ptr< Implementation_data> __implementation_information,
                boost::shared_ptr< Syntactic_context_list> __p_context_definition_list,
                boost::shared_ptr< ASOI_tag> __called_asoi_tag,
                boost::shared_ptr< ASOI_tag> __calling_asoi_tag,
                boost::shared_ptr< Association_data> __user_information);

        BOOST_ASN_VALUE_DEFAULT_DECL(protocol_version, bitstring_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(aSO_context_name, ASO_context_name);
        BOOST_ASN_VALUE_OPTIONAL_DECL(called_AP_title, AP_title);
        BOOST_ASN_VALUE_OPTIONAL_DECL(called_AE_qualifier, AE_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(called_AP_invocation_identifier, AP_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(called_AE_invocation_identifier, AE_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_AP_title, AP_title);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_AE_qualifier, AE_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_AP_invocation_identifier, AP_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_AE_invocation_identifier, AE_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(sender_acse_requirements, ACSE_requirements);
        BOOST_ASN_VALUE_OPTIONAL_DECL(mechanism_name, Mechanism_name);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_authentication_value, Authentication_value);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(implementation_information, Implementation_data);
        BOOST_ASN_VALUE_OPTIONAL_DECL(p_context_definition_list, Syntactic_context_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(called_asoi_tag, ASOI_tag);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_asoi_tag, ASOI_tag);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, Association_data);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        default_holder<bitstring_type, protocol_version__default> protocol_version_;
        value_holder<ASO_context_name> aSO_context_name_;
        boost::shared_ptr<AP_title> called_AP_title_;
        boost::shared_ptr<AE_qualifier> called_AE_qualifier_;
        boost::shared_ptr<AP_invocation_identifier> called_AP_invocation_identifier_;
        boost::shared_ptr<AE_invocation_identifier> called_AE_invocation_identifier_;
        boost::shared_ptr<AP_title> calling_AP_title_;
        boost::shared_ptr<AE_qualifier> calling_AE_qualifier_;
        boost::shared_ptr<AP_invocation_identifier> calling_AP_invocation_identifier_;
        boost::shared_ptr<AE_invocation_identifier> calling_AE_invocation_identifier_;
        boost::shared_ptr<ACSE_requirements> sender_acse_requirements_;
        boost::shared_ptr<Mechanism_name> mechanism_name_;
        boost::shared_ptr<Authentication_value> calling_authentication_value_;
        boost::shared_ptr<ASO_context_name_list> aSO_context_name_list_;
        boost::shared_ptr<Implementation_data> implementation_information_;
        boost::shared_ptr<Syntactic_context_list> p_context_definition_list_;
        boost::shared_ptr<ASOI_tag> called_asoi_tag_;
        boost::shared_ptr<ASOI_tag> calling_asoi_tag_;
        boost::shared_ptr<Association_data> user_information_;
    };

    // sequence AARE-apdu

    struct AARE_apdu_impl {

        static const bitstring_type version1;

        static const bitstring_type protocol_version__default;

        AARE_apdu_impl();

        AARE_apdu_impl(const ASO_context_name& __aSO_context_name,
                const Associate_result& __result,
                const Associate_source_diagnostic& __result_source_diagnostic);

        AARE_apdu_impl(boost::shared_ptr< bitstring_type> __protocol_version,
                boost::shared_ptr< ASO_context_name> __aSO_context_name,
                boost::shared_ptr< Associate_result> __result,
                boost::shared_ptr< Associate_source_diagnostic> __result_source_diagnostic,
                boost::shared_ptr< AP_title> __responding_AP_title,
                boost::shared_ptr< AE_qualifier> __responding_AE_qualifier,
                boost::shared_ptr< AP_invocation_identifier> __responding_AP_invocation_identifier,
                boost::shared_ptr< AE_invocation_identifier> __responding_AE_invocation_identifier,
                boost::shared_ptr< ACSE_requirements> __responder_acse_requirements,
                boost::shared_ptr< Mechanism_name> __mechanism_name,
                boost::shared_ptr< Authentication_value> __responding_authentication_value,
                boost::shared_ptr< ASO_context_name_list> __aSO_context_name_list,
                boost::shared_ptr< Implementation_data> __implementation_information,
                boost::shared_ptr< P_context_result_list> __p_context_result_list,
                boost::shared_ptr< ASOI_tag> __called_asoi_tag,
                boost::shared_ptr< ASOI_tag> __calling_asoi_tag,
                boost::shared_ptr< Association_data> __user_information);

        BOOST_ASN_VALUE_DEFAULT_DECL(protocol_version, bitstring_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(aSO_context_name, ASO_context_name);
        BOOST_ASN_VALUE_HOLDERH_DECL(result, Associate_result);
        BOOST_ASN_VALUE_HOLDERH_DECL(result_source_diagnostic, Associate_source_diagnostic);
        BOOST_ASN_VALUE_OPTIONAL_DECL(responding_AP_title, AP_title);
        BOOST_ASN_VALUE_OPTIONAL_DECL(responding_AE_qualifier, AE_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(responding_AP_invocation_identifier, AP_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(responding_AE_invocation_identifier, AE_invocation_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(responder_acse_requirements, ACSE_requirements);
        BOOST_ASN_VALUE_OPTIONAL_DECL(mechanism_name, Mechanism_name);
        BOOST_ASN_VALUE_OPTIONAL_DECL(responding_authentication_value, Authentication_value);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(implementation_information, Implementation_data);
        BOOST_ASN_VALUE_OPTIONAL_DECL(p_context_result_list, P_context_result_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(called_asoi_tag, ASOI_tag);
        BOOST_ASN_VALUE_OPTIONAL_DECL(calling_asoi_tag, ASOI_tag);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, Association_data);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        default_holder<bitstring_type, protocol_version__default> protocol_version_;
        value_holder<ASO_context_name> aSO_context_name_;
        value_holder<Associate_result> result_;
        value_holder<Associate_source_diagnostic> result_source_diagnostic_;
        boost::shared_ptr<AP_title> responding_AP_title_;
        boost::shared_ptr<AE_qualifier> responding_AE_qualifier_;
        boost::shared_ptr<AP_invocation_identifier> responding_AP_invocation_identifier_;
        boost::shared_ptr<AE_invocation_identifier> responding_AE_invocation_identifier_;
        boost::shared_ptr<ACSE_requirements> responder_acse_requirements_;
        boost::shared_ptr<Mechanism_name> mechanism_name_;
        boost::shared_ptr<Authentication_value> responding_authentication_value_;
        boost::shared_ptr<ASO_context_name_list> aSO_context_name_list_;
        boost::shared_ptr<Implementation_data> implementation_information_;
        boost::shared_ptr<P_context_result_list> p_context_result_list_;
        boost::shared_ptr<ASOI_tag> called_asoi_tag_;
        boost::shared_ptr<ASOI_tag> calling_asoi_tag_;
        boost::shared_ptr<Association_data> user_information_;
    };

    // sequence RLRQ-apdu

    struct RLRQ_apdu_impl {

        RLRQ_apdu_impl();

        RLRQ_apdu_impl(boost::shared_ptr< Release_request_reason> __reason,
                boost::shared_ptr< ASO_qualifier> __aso_qualifier,
                boost::shared_ptr< ASOI_identifier> __asoi_identifier,
                boost::shared_ptr< Association_data> __user_information);

        BOOST_ASN_VALUE_OPTIONAL_DECL(reason, Release_request_reason);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, Association_data);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<Release_request_reason> reason_;
        boost::shared_ptr<ASO_qualifier> aso_qualifier_;
        boost::shared_ptr<ASOI_identifier> asoi_identifier_;
        boost::shared_ptr<Association_data> user_information_;
    };

    // sequence RLRE-apdu

    struct RLRE_apdu_impl {

        RLRE_apdu_impl();

        RLRE_apdu_impl(boost::shared_ptr< Release_response_reason> __reason,
                boost::shared_ptr< ASO_qualifier> __aso_qualifier,
                boost::shared_ptr< ASOI_identifier> __asoi_identifier,
                boost::shared_ptr< Association_data> __user_information);

        BOOST_ASN_VALUE_OPTIONAL_DECL(reason, Release_response_reason);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, Association_data);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<Release_response_reason> reason_;
        boost::shared_ptr<ASO_qualifier> aso_qualifier_;
        boost::shared_ptr<ASOI_identifier> asoi_identifier_;
        boost::shared_ptr<Association_data> user_information_;
    };

    // sequence ABRT-apdu

    struct ABRT_apdu_impl {

        ABRT_apdu_impl();

        ABRT_apdu_impl(const ABRT_source& __abort_source);

        ABRT_apdu_impl(boost::shared_ptr< ABRT_source> __abort_source,
                boost::shared_ptr< ABRT_diagnostic> __abort_diagnostic,
                boost::shared_ptr< ASO_qualifier> __aso_qualifier,
                boost::shared_ptr< ASOI_identifier> __asoi_identifier,
                boost::shared_ptr< Association_data> __user_information);

        BOOST_ASN_VALUE_HOLDERH_DECL(abort_source, ABRT_source);
        BOOST_ASN_VALUE_OPTIONAL_DECL(abort_diagnostic, ABRT_diagnostic);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, Association_data);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ABRT_source> abort_source_;
        boost::shared_ptr<ABRT_diagnostic> abort_diagnostic_;
        boost::shared_ptr<ASO_qualifier> aso_qualifier_;
        boost::shared_ptr<ASOI_identifier> asoi_identifier_;
        boost::shared_ptr<Association_data> user_information_;
    };

    // sequence A-DT-apdu

    struct A_DT_apdu_impl {

        A_DT_apdu_impl();

        A_DT_apdu_impl(const User_Data& __a_user_data);

        A_DT_apdu_impl(boost::shared_ptr< ASO_qualifier> __aso_qualifier,
                boost::shared_ptr< ASOI_identifier> __asoi_identifier,
                boost::shared_ptr< User_Data> __a_user_data);

        BOOST_ASN_VALUE_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(a_user_data, User_Data);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ASO_qualifier> aso_qualifier_;
        boost::shared_ptr<ASOI_identifier> asoi_identifier_;
        value_holder<User_Data> a_user_data_;
    };

    // sequence ACRQ-apdu

    struct ACRQ_apdu_impl {

        ACRQ_apdu_impl();

        ACRQ_apdu_impl(boost::shared_ptr< ASO_qualifier> __aso_qualifier,
                boost::shared_ptr< ASOI_identifier> __asoi_identifier,
                boost::shared_ptr< ASO_context_name> __aSO_context_name,
                boost::shared_ptr< ASO_context_name_list> __aSO_context_name_list,
                boost::shared_ptr< Syntactic_context_list> __p_context_definition_list,
                boost::shared_ptr< User_information> __user_information);

        BOOST_ASN_VALUE_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aSO_context_name, ASO_context_name);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(p_context_definition_list, Syntactic_context_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, User_information);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ASO_qualifier> aso_qualifier_;
        boost::shared_ptr<ASOI_identifier> asoi_identifier_;
        boost::shared_ptr<ASO_context_name> aSO_context_name_;
        boost::shared_ptr<ASO_context_name_list> aSO_context_name_list_;
        boost::shared_ptr<Syntactic_context_list> p_context_definition_list_;
        boost::shared_ptr<User_information> user_information_;
    };

    // sequence ACRP-apdu

    struct ACRP_apdu_impl {

        ACRP_apdu_impl();

        ACRP_apdu_impl(boost::shared_ptr< ASO_qualifier> __aso_qualifier,
                boost::shared_ptr< ASOI_identifier> __asoi_identifier,
                boost::shared_ptr< ASO_context_name_list> __aSO_context_name,
                boost::shared_ptr< P_context_result_list> __p_context_result_list,
                boost::shared_ptr< User_information> __user_information);

        BOOST_ASN_VALUE_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(aSO_context_name, ASO_context_name_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(p_context_result_list, P_context_result_list);
        BOOST_ASN_VALUE_OPTIONAL_DECL(user_information, User_information);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ASO_qualifier> aso_qualifier_;
        boost::shared_ptr<ASOI_identifier> asoi_identifier_;
        boost::shared_ptr<ASO_context_name_list> aSO_context_name_;
        boost::shared_ptr<P_context_result_list> p_context_result_list_;
        boost::shared_ptr<User_information> user_information_;
    };

    extern const ABRT_diagnostic ABRT_diagnostic_no_reason_given;
    extern const ABRT_diagnostic ABRT_diagnostic_protocol_error;
    extern const ABRT_diagnostic ABRT_diagnostic_authentication_mechanism_name_not_recognized;
    extern const ABRT_diagnostic ABRT_diagnostic_authentication_mechanism_name_required;
    extern const ABRT_diagnostic ABRT_diagnostic_authentication_failure;
    extern const ABRT_diagnostic ABRT_diagnostic_authentication_required;

    extern const ABRT_source ABRT_source_acse_service_user;
    extern const ABRT_source ABRT_source_acse_service_provider;

    extern const ACSE_requirements ACSE_requirements_authentication;
    extern const ACSE_requirements ACSE_requirements_aSO_context_negotiation;
    extern const ACSE_requirements ACSE_requirements_higher_level_association;
    extern const ACSE_requirements ACSE_requirements_nested_association;

    // choice AP-title

    enum AP_title_enum {

        AP_title_null = 0,
        AP_title_ap_title_form1,
        AP_title_ap_title_form2,
        AP_title_ap_title_form3,
    };

    struct AP_title : public BOOST_ASN_CHOICE_STRUCT(AP_title_enum) {

        AP_title() : BOOST_ASN_CHOICE_STRUCT(AP_title_enum) () {
        }

        template<typename T > AP_title(boost::shared_ptr< T> vl, AP_title_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(AP_title_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(ap_title_form1, AP_title_form1, AP_title_ap_title_form1);
        BOOST_ASN_VALUE_CHOICE(ap_title_form2, AP_title_form2, AP_title_ap_title_form2);
        BOOST_ASN_VALUE_CHOICE(ap_title_form3, AP_title_form3, AP_title_ap_title_form3);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice ASO-qualifier

    enum ASO_qualifier_enum {

        ASO_qualifier_null = 0,
        ASO_qualifier_aso_qualifier_form1,
        ASO_qualifier_aso_qualifier_form2,
        ASO_qualifier_aso_qualifier_form3,
    };

    struct ASO_qualifier : public BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) {

        ASO_qualifier() : BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) () {
        }

        template<typename T > ASO_qualifier(boost::shared_ptr< T> vl, ASO_qualifier_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(aso_qualifier_form1, ASO_qualifier_form1, ASO_qualifier_aso_qualifier_form1);
        BOOST_ASN_VALUE_CHOICE(aso_qualifier_form2, ASO_qualifier_form2, ASO_qualifier_aso_qualifier_form2);
        BOOST_ASN_VALUE_CHOICE(aso_qualifier_form3, ASO_qualifier_form3, ASO_qualifier_aso_qualifier_form3);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice AE-title

    enum AE_title_enum {

        AE_title_null = 0,
        AE_title_ae_title_form1,
        AE_title_ae_title_form2,
    };

    struct AE_title : public BOOST_ASN_CHOICE_STRUCT(AE_title_enum) {

        AE_title() : BOOST_ASN_CHOICE_STRUCT(AE_title_enum) () {
        }

        template<typename T > AE_title(boost::shared_ptr< T> vl, AE_title_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(AE_title_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(ae_title_form1, AE_title_form1, AE_title_ae_title_form1);
        BOOST_ASN_VALUE_CHOICE(ae_title_form2, AE_title_form2, AE_title_ae_title_form2);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    struct ASOI_tag_sequence_of {

        ASOI_tag_sequence_of();

        ASOI_tag_sequence_of(boost::shared_ptr< ASO_qualifier> __qualifier,
                boost::shared_ptr< ASOI_identifier> __identifier);

        BOOST_ASN_VALUE_OPTIONAL_DECL(qualifier, ASO_qualifier);
        BOOST_ASN_VALUE_OPTIONAL_DECL(identifier, ASOI_identifier);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ASO_qualifier> qualifier_;
        boost::shared_ptr<ASOI_identifier> identifier_;
    };

    // choice Syntactic-context-list

    enum Syntactic_context_list_enum {

        Syntactic_context_list_null = 0,
        Syntactic_context_list_context_list,
        Syntactic_context_list_default_contact_list,
    };

    struct Syntactic_context_list : public BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) {

        Syntactic_context_list() : BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) () {
        }

        template<typename T > Syntactic_context_list(boost::shared_ptr< T> vl, Syntactic_context_list_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(context_list, Context_list, Syntactic_context_list_context_list);
        BOOST_ASN_VALUE_CHOICE(default_contact_list, Default_Context_List, Syntactic_context_list_default_contact_list);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    struct Context_list_sequence_of {

        typedef std::vector< Transfer_syntax_name > transfer_syntaxes_type;

        Context_list_sequence_of();

        Context_list_sequence_of(const Presentation_context_identifier& __pci,
                const Abstract_syntax_name& __abstract_syntax,
                const transfer_syntaxes_type& __transfer_syntaxes);

        BOOST_ASN_VALUE_HOLDERH_DECL(pci, Presentation_context_identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(abstract_syntax, Abstract_syntax_name);
        BOOST_ASN_VALUE_HOLDERH_DECL(transfer_syntaxes, transfer_syntaxes_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<Presentation_context_identifier> pci_;
        value_holder<Abstract_syntax_name> abstract_syntax_;
        value_holder<transfer_syntaxes_type> transfer_syntaxes_;
    };

    struct Default_Context_List_sequence_of {

        Default_Context_List_sequence_of();

        Default_Context_List_sequence_of(const Transfer_syntax_name& __transfer_syntax_name);

        Default_Context_List_sequence_of(boost::shared_ptr< Abstract_syntax_name> __abstract_syntax_name,
                boost::shared_ptr< Transfer_syntax_name> __transfer_syntax_name);

        BOOST_ASN_VALUE_OPTIONAL_DECL(abstract_syntax_name, Abstract_syntax_name);
        BOOST_ASN_VALUE_HOLDERH_DECL(transfer_syntax_name, Transfer_syntax_name);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<Abstract_syntax_name> abstract_syntax_name_;
        value_holder<Transfer_syntax_name> transfer_syntax_name_;
    };

    struct P_context_result_list_sequence_of {

        static const int reason_not_specified;
        static const int abstract_syntax_not_supported;
        static const int proposed_transfer_syntaxes_not_supported;
        static const int local_limit_on_DCS_exceeded;


        P_context_result_list_sequence_of();

        P_context_result_list_sequence_of(const Result& __result);

        P_context_result_list_sequence_of(boost::shared_ptr< Result> __result,
                boost::shared_ptr< Concrete_syntax_name> __concrete_syntax_name,
                boost::shared_ptr< int> __provider_reason);

        BOOST_ASN_VALUE_HOLDERH_DECL(result, Result);
        BOOST_ASN_VALUE_OPTIONAL_DECL(concrete_syntax_name, Concrete_syntax_name);
        BOOST_ASN_VALUE_OPTIONAL_DECL(provider_reason, int);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<Result> result_;
        boost::shared_ptr<Concrete_syntax_name> concrete_syntax_name_;
        boost::shared_ptr<int> provider_reason_;
    };

    extern const Result Result_acceptance;
    extern const Result Result_user_rejection;
    extern const Result Result_provider_rejection;

    extern const Associate_result Associate_result_accepted;
    extern const Associate_result Associate_result_rejected_permanent;
    extern const Associate_result Associate_result_rejected_transient;

    // choice Associate-source-diagnostic

    enum Associate_source_diagnostic_enum {

        Associate_source_diagnostic_null = 0,
        Associate_source_diagnostic_acse_service_user,
        Associate_source_diagnostic_acse_service_provider,
    };

    struct Associate_source_diagnostic : public BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) {

        static const int null;
        static const int no_reason_given;
        static const int application_context_name_not_supported;
        static const int calling_AP_title_not_recognized;
        static const int calling_AP_invocation_identifier_not_recognized;
        static const int calling_AE_qualifier_not_recognized;
        static const int calling_AE_invocation_identifier_not_recognized;
        static const int called_AP_title_not_recognized;
        static const int called_AP_invocation_identifier_not_recognized;
        static const int called_AE_qualifier_not_recognized;
        static const int called_AE_invocation_identifier_not_recognized;
        static const int authentication_mechanism_name_not_recognized;
        static const int authentication_mechanism_name_required;
        static const int authentication_failure;
        static const int authentication_required;

        //static const int null;
        //static const int no_reason_given;
        static const int no_common_acse_version;

        Associate_source_diagnostic() : BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) () {
        }

        template<typename T > Associate_source_diagnostic(boost::shared_ptr< T> vl, Associate_source_diagnostic_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(acse_service_user, int, Associate_source_diagnostic_acse_service_user);
        BOOST_ASN_VALUE_CHOICE(acse_service_provider, int, Associate_source_diagnostic_acse_service_provider);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice User-Data

    enum User_Data_enum {

        User_Data_null = 0,
        User_Data_user_information,
        User_Data_simply_encoded_data,
        User_Data_fully_encoded_data,
    };

    struct User_Data : public BOOST_ASN_CHOICE_STRUCT(User_Data_enum) {

        User_Data() : BOOST_ASN_CHOICE_STRUCT(User_Data_enum) () {
        }

        template<typename T > User_Data(boost::shared_ptr< T> vl, User_Data_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(User_Data_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(user_information, User_information, User_Data_user_information);
        BOOST_ASN_VALUE_CHOICE(simply_encoded_data, Simply_encoded_data, User_Data_simply_encoded_data);
        BOOST_ASN_VALUE_CHOICE(fully_encoded_data, PDV_list, User_Data_fully_encoded_data);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // sequence PDV-list

    struct PDV_list {

        struct presentation_data_values_type;

        enum presentation_data_values_type_enum {

            presentation_data_values_type_null = 0,
            presentation_data_values_type_simple_ASN1_type,
            presentation_data_values_type_octet_aligned,
            presentation_data_values_type_arbitrary,
        };

        struct presentation_data_values_type : public BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) {

            presentation_data_values_type() : BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) () {
            }

            template<typename T > presentation_data_values_type(boost::shared_ptr< T> vl, presentation_data_values_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(simple_ASN1_type, any_type, presentation_data_values_type_simple_ASN1_type);
            BOOST_ASN_VALUE_CHOICE(octet_aligned, octetstring_type, presentation_data_values_type_octet_aligned);
            BOOST_ASN_VALUE_CHOICE(arbitrary, bitstring_type, presentation_data_values_type_arbitrary);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        PDV_list();

        PDV_list(const Presentation_context_identifier& __presentation_context_identifier,
                const presentation_data_values_type& __presentation_data_values);

        PDV_list(boost::shared_ptr< Transfer_syntax_name> __transfer_syntax_name,
                boost::shared_ptr< Presentation_context_identifier> __presentation_context_identifier,
                boost::shared_ptr< presentation_data_values_type> __presentation_data_values);

        BOOST_ASN_VALUE_OPTIONAL_DECL(transfer_syntax_name, Transfer_syntax_name);
        BOOST_ASN_VALUE_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(presentation_data_values, presentation_data_values_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<Transfer_syntax_name> transfer_syntax_name_;
        value_holder<Presentation_context_identifier> presentation_context_identifier_;
        value_holder<presentation_data_values_type> presentation_data_values_;
    };

    // choice Authentication-value

    enum Authentication_value_enum {

        Authentication_value_null = 0,
        Authentication_value_charstring,
        Authentication_value_bitstring,
        Authentication_value_external,
        Authentication_value_other,
    };

    struct Authentication_value : public BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) {


        struct other_type;

        struct other_type {

            other_type();

            other_type(const any_type& __other_mechanism_name,
                    const any_type& __other_mechanism_value);

            BOOST_ASN_VALUE_HOLDERH_DECL(other_mechanism_name, any_type);
            BOOST_ASN_VALUE_HOLDERH_DECL(other_mechanism_value, any_type);

            BOOST_ASN_ARCHIVE_FUNC;

        private:

            value_holder<any_type> other_mechanism_name_;
            value_holder<any_type> other_mechanism_value_;
        };

        Authentication_value() : BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) () {
        }

        template<typename T > Authentication_value(boost::shared_ptr< T> vl, Authentication_value_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(charstring, graphicstring_type, Authentication_value_charstring);
        BOOST_ASN_VALUE_CHOICE(bitstring, bitstring_type, Authentication_value_bitstring);
        BOOST_ASN_VALUE_CHOICE(external, external_type, Authentication_value_external);
        BOOST_ASN_VALUE_CHOICE(other, other_type, Authentication_value_other);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    extern const Release_request_reason Release_request_reason_normal;
    extern const Release_request_reason Release_request_reason_urgent;
    extern const Release_request_reason Release_request_reason_user_defined;

    extern const Release_response_reason Release_response_reason_normal;
    extern const Release_response_reason Release_response_reason_not_finished;
    extern const Release_response_reason Release_response_reason_user_defined;

    template<> void ACSE_apdu::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACSE_apdu::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AP_title::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AP_title::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ASO_qualifier::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ASO_qualifier::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AE_title::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AE_title::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Syntactic_context_list::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Syntactic_context_list::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::input_coder& arch);
    template<> void User_Data::serialize(boost::asn1::x690::output_coder& arch);
    template<> void User_Data::serialize(boost::asn1::x690::input_coder& arch);
    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch);
    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Authentication_value::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Authentication_value::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::input_coder& arch);
}

BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::ACSE_apdu)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::AP_title)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::ASO_qualifier)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::AE_title)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::Syntactic_context_list)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::Associate_source_diagnostic)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::User_Data)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::PDV_list::presentation_data_values_type)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::Authentication_value)

#endif  /*___ACSE_1 */

