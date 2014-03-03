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

    ITU_T_IMPLICIT_TYPEDEF(AARQ_apdu, AARQ_apdu_impl, 0, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(AARE_apdu, AARE_apdu_impl, 1, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(RLRQ_apdu, RLRQ_apdu_impl, 2, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(RLRE_apdu, RLRE_apdu_impl, 3, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(ABRT_apdu, ABRT_apdu_impl, 4, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(A_DT_apdu, A_DT_apdu_impl, 5, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(ACRQ_apdu, ACRQ_apdu_impl, 6, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(ACRP_apdu, ACRP_apdu_impl, 7, APPLICATION_CLASS);
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

    struct ACSE_apdu : public ITU_T_STRUCT(ACSE_apdu_enum) {

        ACSE_apdu() : ITU_T_STRUCT(ACSE_apdu_enum) () {
        }

        template<typename T > ACSE_apdu(boost::shared_ptr< T> vl, ACSE_apdu_enum enm) :
                ITU_T_STRUCT(ACSE_apdu_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(aarq, AARQ_apdu, ACSE_apdu_aarq);
        ITU_T_CHOICE_DECL(aare, AARE_apdu, ACSE_apdu_aare);
        ITU_T_CHOICE_DECL(rlrq, RLRQ_apdu, ACSE_apdu_rlrq);
        ITU_T_CHOICE_DECL(rlre, RLRE_apdu, ACSE_apdu_rlre);
        ITU_T_CHOICE_DECL(abrt, ABRT_apdu, ACSE_apdu_abrt);
        ITU_T_CHOICE_DECL(adt, A_DT_apdu, ACSE_apdu_adt);
        ITU_T_CHOICE_DECL(acrq, ACRQ_apdu, ACSE_apdu_acrq);
        ITU_T_CHOICE_DECL(acrp, ACRP_apdu, ACSE_apdu_acrp);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AARQ-apdu

    struct AARQ_apdu_impl {

        static const bitstring_type protocol_version_version1;

        static const bitstring_type protocol_version__default;

        AARQ_apdu_impl();

        AARQ_apdu_impl(const ASO_context_name& arg__aSO_context_name);

        AARQ_apdu_impl(boost::shared_ptr< bitstring_type> arg__protocol_version,
                boost::shared_ptr< ASO_context_name> arg__aSO_context_name,
                boost::shared_ptr< AP_title> arg__called_AP_title,
                boost::shared_ptr< AE_qualifier> arg__called_AE_qualifier,
                boost::shared_ptr< AP_invocation_identifier> arg__called_AP_invocation_identifier,
                boost::shared_ptr< AE_invocation_identifier> arg__called_AE_invocation_identifier,
                boost::shared_ptr< AP_title> arg__calling_AP_title,
                boost::shared_ptr< AE_qualifier> arg__calling_AE_qualifier,
                boost::shared_ptr< AP_invocation_identifier> arg__calling_AP_invocation_identifier,
                boost::shared_ptr< AE_invocation_identifier> arg__calling_AE_invocation_identifier,
                boost::shared_ptr< ACSE_requirements> arg__sender_acse_requirements,
                boost::shared_ptr< Mechanism_name> arg__mechanism_name,
                boost::shared_ptr< Authentication_value> arg__calling_authentication_value,
                boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
                boost::shared_ptr< Implementation_data> arg__implementation_information,
                boost::shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
                boost::shared_ptr< ASOI_tag> arg__called_asoi_tag,
                boost::shared_ptr< ASOI_tag> arg__calling_asoi_tag,
                boost::shared_ptr< Association_data> arg__user_information);

        ITU_T_DEFAULTH_DECL(protocol_version, bitstring_type, protocol_version__default);
        ITU_T_HOLDERH_DECL(aSO_context_name, ASO_context_name);
        ITU_T_OPTIONAL_DECL(called_AP_title, AP_title);
        ITU_T_OPTIONAL_DECL(called_AE_qualifier, AE_qualifier);
        ITU_T_OPTIONAL_DECL(called_AP_invocation_identifier, AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(called_AE_invocation_identifier, AE_invocation_identifier);
        ITU_T_OPTIONAL_DECL(calling_AP_title, AP_title);
        ITU_T_OPTIONAL_DECL(calling_AE_qualifier, AE_qualifier);
        ITU_T_OPTIONAL_DECL(calling_AP_invocation_identifier, AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(calling_AE_invocation_identifier, AE_invocation_identifier);
        ITU_T_OPTIONAL_DECL(sender_acse_requirements, ACSE_requirements);
        ITU_T_OPTIONAL_DECL(mechanism_name, Mechanism_name);
        ITU_T_OPTIONAL_DECL(calling_authentication_value, Authentication_value);
        ITU_T_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(implementation_information, Implementation_data);
        ITU_T_OPTIONAL_DECL(p_context_definition_list, Syntactic_context_list);
        ITU_T_OPTIONAL_DECL(called_asoi_tag, ASOI_tag);
        ITU_T_OPTIONAL_DECL(calling_asoi_tag, ASOI_tag);
        ITU_T_OPTIONAL_DECL(user_information, Association_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AARE-apdu

    struct AARE_apdu_impl {

        static const bitstring_type protocol_version_version1;

        static const bitstring_type protocol_version__default;

        AARE_apdu_impl();

        AARE_apdu_impl(const ASO_context_name& arg__aSO_context_name,
                const Associate_result& arg__result,
                const Associate_source_diagnostic& arg__result_source_diagnostic);

        AARE_apdu_impl(boost::shared_ptr< bitstring_type> arg__protocol_version,
                boost::shared_ptr< ASO_context_name> arg__aSO_context_name,
                boost::shared_ptr< Associate_result> arg__result,
                boost::shared_ptr< Associate_source_diagnostic> arg__result_source_diagnostic,
                boost::shared_ptr< AP_title> arg__responding_AP_title,
                boost::shared_ptr< AE_qualifier> arg__responding_AE_qualifier,
                boost::shared_ptr< AP_invocation_identifier> arg__responding_AP_invocation_identifier,
                boost::shared_ptr< AE_invocation_identifier> arg__responding_AE_invocation_identifier,
                boost::shared_ptr< ACSE_requirements> arg__responder_acse_requirements,
                boost::shared_ptr< Mechanism_name> arg__mechanism_name,
                boost::shared_ptr< Authentication_value> arg__responding_authentication_value,
                boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
                boost::shared_ptr< Implementation_data> arg__implementation_information,
                boost::shared_ptr< P_context_result_list> arg__p_context_result_list,
                boost::shared_ptr< ASOI_tag> arg__called_asoi_tag,
                boost::shared_ptr< ASOI_tag> arg__calling_asoi_tag,
                boost::shared_ptr< Association_data> arg__user_information);

        ITU_T_DEFAULTH_DECL(protocol_version, bitstring_type, protocol_version__default);
        ITU_T_HOLDERH_DECL(aSO_context_name, ASO_context_name);
        ITU_T_HOLDERH_DECL(result, Associate_result);
        ITU_T_HOLDERH_DECL(result_source_diagnostic, Associate_source_diagnostic);
        ITU_T_OPTIONAL_DECL(responding_AP_title, AP_title);
        ITU_T_OPTIONAL_DECL(responding_AE_qualifier, AE_qualifier);
        ITU_T_OPTIONAL_DECL(responding_AP_invocation_identifier, AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(responding_AE_invocation_identifier, AE_invocation_identifier);
        ITU_T_OPTIONAL_DECL(responder_acse_requirements, ACSE_requirements);
        ITU_T_OPTIONAL_DECL(mechanism_name, Mechanism_name);
        ITU_T_OPTIONAL_DECL(responding_authentication_value, Authentication_value);
        ITU_T_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(implementation_information, Implementation_data);
        ITU_T_OPTIONAL_DECL(p_context_result_list, P_context_result_list);
        ITU_T_OPTIONAL_DECL(called_asoi_tag, ASOI_tag);
        ITU_T_OPTIONAL_DECL(calling_asoi_tag, ASOI_tag);
        ITU_T_OPTIONAL_DECL(user_information, Association_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RLRQ-apdu

    struct RLRQ_apdu_impl {

        RLRQ_apdu_impl();

        RLRQ_apdu_impl(boost::shared_ptr< Release_request_reason> arg__reason,
                boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
                boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
                boost::shared_ptr< Association_data> arg__user_information);

        ITU_T_OPTIONAL_DECL(reason, Release_request_reason);
        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        ITU_T_OPTIONAL_DECL(user_information, Association_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RLRE-apdu

    struct RLRE_apdu_impl {

        RLRE_apdu_impl();

        RLRE_apdu_impl(boost::shared_ptr< Release_response_reason> arg__reason,
                boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
                boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
                boost::shared_ptr< Association_data> arg__user_information);

        ITU_T_OPTIONAL_DECL(reason, Release_response_reason);
        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        ITU_T_OPTIONAL_DECL(user_information, Association_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ABRT-apdu

    struct ABRT_apdu_impl {

        ABRT_apdu_impl();

        ABRT_apdu_impl(const ABRT_source& arg__abort_source);

        ABRT_apdu_impl(boost::shared_ptr< ABRT_source> arg__abort_source,
                boost::shared_ptr< ABRT_diagnostic> arg__abort_diagnostic,
                boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
                boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
                boost::shared_ptr< Association_data> arg__user_information);

        ITU_T_HOLDERH_DECL(abort_source, ABRT_source);
        ITU_T_OPTIONAL_DECL(abort_diagnostic, ABRT_diagnostic);
        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        ITU_T_OPTIONAL_DECL(user_information, Association_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence A-DT-apdu

    struct A_DT_apdu_impl {

        A_DT_apdu_impl();

        A_DT_apdu_impl(const User_Data& arg__a_user_data);

        A_DT_apdu_impl(boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
                boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
                boost::shared_ptr< User_Data> arg__a_user_data);

        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        ITU_T_HOLDERH_DECL(a_user_data, User_Data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ACRQ-apdu

    struct ACRQ_apdu_impl {

        ACRQ_apdu_impl();

        ACRQ_apdu_impl(boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
                boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
                boost::shared_ptr< ASO_context_name> arg__aSO_context_name,
                boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
                boost::shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
                boost::shared_ptr< User_information> arg__user_information);

        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        ITU_T_OPTIONAL_DECL(aSO_context_name, ASO_context_name);
        ITU_T_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(p_context_definition_list, Syntactic_context_list);
        ITU_T_OPTIONAL_DECL(user_information, User_information);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ACRP-apdu

    struct ACRP_apdu_impl {

        ACRP_apdu_impl();

        ACRP_apdu_impl(boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
                boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
                boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name,
                boost::shared_ptr< P_context_result_list> arg__p_context_result_list,
                boost::shared_ptr< User_information> arg__user_information);

        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier);
        ITU_T_OPTIONAL_DECL(aSO_context_name, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(p_context_result_list, P_context_result_list);
        ITU_T_OPTIONAL_DECL(user_information, User_information);

        ITU_T_ARCHIVE_FUNC;
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

    struct AP_title : public ITU_T_STRUCT(AP_title_enum) {

        AP_title() : ITU_T_STRUCT(AP_title_enum) () {
        }

        template<typename T > AP_title(boost::shared_ptr< T> vl, AP_title_enum enm) :
                ITU_T_STRUCT(AP_title_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(ap_title_form1, AP_title_form1, AP_title_ap_title_form1);
        ITU_T_CHOICE_DECL(ap_title_form2, AP_title_form2, AP_title_ap_title_form2);
        ITU_T_CHOICE_DECL(ap_title_form3, AP_title_form3, AP_title_ap_title_form3);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ASO-qualifier

    enum ASO_qualifier_enum {

        ASO_qualifier_null = 0,
        ASO_qualifier_aso_qualifier_form1,
        ASO_qualifier_aso_qualifier_form2,
        ASO_qualifier_aso_qualifier_form3,
    };

    struct ASO_qualifier : public ITU_T_STRUCT(ASO_qualifier_enum) {

        ASO_qualifier() : ITU_T_STRUCT(ASO_qualifier_enum) () {
        }

        template<typename T > ASO_qualifier(boost::shared_ptr< T> vl, ASO_qualifier_enum enm) :
                ITU_T_STRUCT(ASO_qualifier_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(aso_qualifier_form1, ASO_qualifier_form1, ASO_qualifier_aso_qualifier_form1);
        ITU_T_CHOICE_DECL(aso_qualifier_form2, ASO_qualifier_form2, ASO_qualifier_aso_qualifier_form2);
        ITU_T_CHOICE_DECL(aso_qualifier_form3, ASO_qualifier_form3, ASO_qualifier_aso_qualifier_form3);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice AE-title

    enum AE_title_enum {

        AE_title_null = 0,
        AE_title_ae_title_form1,
        AE_title_ae_title_form2,
    };

    struct AE_title : public ITU_T_STRUCT(AE_title_enum) {

        AE_title() : ITU_T_STRUCT(AE_title_enum) () {
        }

        template<typename T > AE_title(boost::shared_ptr< T> vl, AE_title_enum enm) :
                ITU_T_STRUCT(AE_title_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(ae_title_form1, AE_title_form1, AE_title_ae_title_form1);
        ITU_T_CHOICE_DECL(ae_title_form2, AE_title_form2, AE_title_ae_title_form2);

        ITU_T_ARCHIVE_FUNC;
    };

    struct ASOI_tag_sequence_of {

        ASOI_tag_sequence_of();

        ASOI_tag_sequence_of(boost::shared_ptr< ASO_qualifier> arg__qualifier,
                boost::shared_ptr< ASOI_identifier> arg__identifier);

        ITU_T_OPTIONAL_DECL(qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(identifier, ASOI_identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Syntactic-context-list

    enum Syntactic_context_list_enum {

        Syntactic_context_list_null = 0,
        Syntactic_context_list_context_list,
        Syntactic_context_list_default_contact_list,
    };

    struct Syntactic_context_list : public ITU_T_STRUCT(Syntactic_context_list_enum) {

        Syntactic_context_list() : ITU_T_STRUCT(Syntactic_context_list_enum) () {
        }

        template<typename T > Syntactic_context_list(boost::shared_ptr< T> vl, Syntactic_context_list_enum enm) :
                ITU_T_STRUCT(Syntactic_context_list_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(context_list, Context_list, Syntactic_context_list_context_list);
        ITU_T_CHOICE_DECL(default_contact_list, Default_Context_List, Syntactic_context_list_default_contact_list);

        ITU_T_ARCHIVE_FUNC;
    };

    struct Context_list_sequence_of {

        typedef std::vector< Transfer_syntax_name > transfer_syntaxes_type;


        Context_list_sequence_of();

        Context_list_sequence_of(const Presentation_context_identifier& arg__pci,
                const Abstract_syntax_name& arg__abstract_syntax,
                const transfer_syntaxes_type& arg__transfer_syntaxes);

        ITU_T_HOLDERH_DECL(pci, Presentation_context_identifier);
        ITU_T_HOLDERH_DECL(abstract_syntax, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntaxes, transfer_syntaxes_type);

        ITU_T_ARCHIVE_FUNC;
    };

    struct Default_Context_List_sequence_of {

        Default_Context_List_sequence_of();

        Default_Context_List_sequence_of(const Transfer_syntax_name& arg__transfer_syntax_name);

        Default_Context_List_sequence_of(boost::shared_ptr< Abstract_syntax_name> arg__abstract_syntax_name,
                boost::shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name);

        ITU_T_OPTIONAL_DECL(abstract_syntax_name, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntax_name, Transfer_syntax_name);

        ITU_T_ARCHIVE_FUNC;
    };

    struct P_context_result_list_sequence_of {

        static const int provider_reason_reason_not_specified;
        static const int provider_reason_abstract_syntax_not_supported;
        static const int provider_reason_proposed_transfer_syntaxes_not_supported;
        static const int provider_reason_local_limit_on_DCS_exceeded;


        P_context_result_list_sequence_of();

        P_context_result_list_sequence_of(const Result& arg__result);

        P_context_result_list_sequence_of(boost::shared_ptr< Result> arg__result,
                boost::shared_ptr< Concrete_syntax_name> arg__concrete_syntax_name,
                boost::shared_ptr< int> arg__provider_reason);

        ITU_T_HOLDERH_DECL(result, Result);
        ITU_T_OPTIONAL_DECL(concrete_syntax_name, Concrete_syntax_name);
        ITU_T_OPTIONAL_DECL(provider_reason, int);

        ITU_T_ARCHIVE_FUNC;
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

    struct Associate_source_diagnostic : public ITU_T_STRUCT(Associate_source_diagnostic_enum) {

        static const int acse_service_user_null;
        static const int acse_service_user_no_reason_given;
        static const int acse_service_user_application_context_name_not_supported;
        static const int acse_service_user_calling_AP_title_not_recognized;
        static const int acse_service_user_calling_AP_invocation_identifier_not_recognized;
        static const int acse_service_user_calling_AE_qualifier_not_recognized;
        static const int acse_service_user_calling_AE_invocation_identifier_not_recognized;
        static const int acse_service_user_called_AP_title_not_recognized;
        static const int acse_service_user_called_AP_invocation_identifier_not_recognized;
        static const int acse_service_user_called_AE_qualifier_not_recognized;
        static const int acse_service_user_called_AE_invocation_identifier_not_recognized;
        static const int acse_service_user_authentication_mechanism_name_not_recognized;
        static const int acse_service_user_authentication_mechanism_name_required;
        static const int acse_service_user_authentication_failure;
        static const int acse_service_user_authentication_required;

        static const int acse_service_provider_null;
        static const int acse_service_provider_no_reason_given;
        static const int acse_service_provider_no_common_acse_version;

        Associate_source_diagnostic() : ITU_T_STRUCT(Associate_source_diagnostic_enum) () {
        }

        template<typename T > Associate_source_diagnostic(boost::shared_ptr< T> vl, Associate_source_diagnostic_enum enm) :
                ITU_T_STRUCT(Associate_source_diagnostic_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(acse_service_user, int, Associate_source_diagnostic_acse_service_user);
        ITU_T_CHOICE_DECL(acse_service_provider, int, Associate_source_diagnostic_acse_service_provider);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice User-Data

    enum User_Data_enum {

        User_Data_null = 0,
        User_Data_user_information,
        User_Data_simply_encoded_data,
        User_Data_fully_encoded_data,
    };

    struct User_Data : public ITU_T_STRUCT(User_Data_enum) {

        User_Data() : ITU_T_STRUCT(User_Data_enum) () {
        }

        template<typename T > User_Data(boost::shared_ptr< T> vl, User_Data_enum enm) :
                ITU_T_STRUCT(User_Data_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(user_information, User_information, User_Data_user_information);
        ITU_T_CHOICE_DECL(simply_encoded_data, Simply_encoded_data, User_Data_simply_encoded_data);
        ITU_T_CHOICE_DECL(fully_encoded_data, PDV_list, User_Data_fully_encoded_data);

        ITU_T_ARCHIVE_FUNC;
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

        struct presentation_data_values_type : public ITU_T_STRUCT(presentation_data_values_type_enum) {

            presentation_data_values_type() : ITU_T_STRUCT(presentation_data_values_type_enum) () {
            }

            template<typename T > presentation_data_values_type(boost::shared_ptr< T> vl, presentation_data_values_type_enum enm) :
                    ITU_T_STRUCT(presentation_data_values_type_enum) (vl, static_cast<int> (enm)) {
            }

            ITU_T_CHOICE_DECL(simple_ASN1_type, any_type, presentation_data_values_type_simple_ASN1_type);
            ITU_T_CHOICE_DECL(octet_aligned, octetstring_type, presentation_data_values_type_octet_aligned);
            ITU_T_CHOICE_DECL(arbitrary, bitstring_type, presentation_data_values_type_arbitrary);

            ITU_T_ARCHIVE_FUNC;
        };


        PDV_list();

        PDV_list(const Presentation_context_identifier& arg__presentation_context_identifier,
                const presentation_data_values_type& arg__presentation_data_values);

        PDV_list(boost::shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
                boost::shared_ptr< Presentation_context_identifier> arg__presentation_context_identifier,
                boost::shared_ptr< presentation_data_values_type> arg__presentation_data_values);

        ITU_T_OPTIONAL_DECL(transfer_syntax_name, Transfer_syntax_name);
        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier);
        ITU_T_HOLDERH_DECL(presentation_data_values, presentation_data_values_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Authentication-value

    enum Authentication_value_enum {

        Authentication_value_null = 0,
        Authentication_value_charstring,
        Authentication_value_bitstring,
        Authentication_value_external,
        Authentication_value_other,
    };

    struct Authentication_value : public ITU_T_STRUCT(Authentication_value_enum) {


        struct other_type;

        struct other_type {

            other_type();

            other_type(const any_type& arg__other_mechanism_name,
                    const any_type& arg__other_mechanism_value);

            ITU_T_HOLDERH_DECL(other_mechanism_name, any_type);
            ITU_T_HOLDERH_DECL(other_mechanism_value, any_type);

            ITU_T_ARCHIVE_FUNC;
        };

        Authentication_value() : ITU_T_STRUCT(Authentication_value_enum) () {
        }

        template<typename T > Authentication_value(boost::shared_ptr< T> vl, Authentication_value_enum enm) :
                ITU_T_STRUCT(Authentication_value_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(charstring, graphicstring_type, Authentication_value_charstring);
        ITU_T_CHOICE_DECL(bitstring, bitstring_type, Authentication_value_bitstring);
        ITU_T_CHOICE_DECL(external, external_type, Authentication_value_external);
        ITU_T_CHOICE_DECL(other, other_type, Authentication_value_other);

        ITU_T_ARCHIVE_FUNC;
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

ITU_T_CHOICE_REGESTRATE(ACSE_1::ACSE_apdu)
ITU_T_CHOICE_REGESTRATE(ACSE_1::AP_title)
ITU_T_CHOICE_REGESTRATE(ACSE_1::ASO_qualifier)
ITU_T_CHOICE_REGESTRATE(ACSE_1::AE_title)
ITU_T_CHOICE_REGESTRATE(ACSE_1::Syntactic_context_list)
ITU_T_CHOICE_REGESTRATE(ACSE_1::Associate_source_diagnostic)
ITU_T_CHOICE_REGESTRATE(ACSE_1::User_Data)
ITU_T_CHOICE_REGESTRATE(ACSE_1::PDV_list::presentation_data_values_type)
ITU_T_CHOICE_REGESTRATE(ACSE_1::Authentication_value)

#endif  /*___ACSE_1 */

