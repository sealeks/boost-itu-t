#include "ACSE-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {

    // choice ACSE-apdu

    ITU_T_CHOICEC_DEFN(ACSE_apdu::aarq, aarq, AARQ_apdu, ACSE_apdu_aarq);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::aare, aare, AARE_apdu, ACSE_apdu_aare);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::rlrq, rlrq, RLRQ_apdu, ACSE_apdu_rlrq);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::rlre, rlre, RLRE_apdu, ACSE_apdu_rlre);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::abrt, abrt, ABRT_apdu, ACSE_apdu_abrt);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::adt, adt, A_DT_apdu, ACSE_apdu_adt);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::acrq, acrq, ACRQ_apdu, ACSE_apdu_acrq);
    ITU_T_CHOICEC_DEFN(ACSE_apdu::acrp, acrp, ACRP_apdu, ACSE_apdu_acrp);

    // sequence AARQ-apdu
    const bitstring_type AARQ_apdu_impl::protocol_version_version1 = bitstring_type(true, 0);

    AARQ_apdu_impl::AARQ_apdu_impl() : aSO_context_name_() {
    };

    AARQ_apdu_impl::AARQ_apdu_impl(const ASO_context_name& arg__aSO_context_name) :
    aSO_context_name_(arg__aSO_context_name) {
    };

    AARQ_apdu_impl::AARQ_apdu_impl(shared_ptr< bitstring_type> arg__protocol_version,
            shared_ptr< ASO_context_name> arg__aSO_context_name,
            shared_ptr< AP_title> arg__called_AP_title,
            shared_ptr< AE_qualifier> arg__called_AE_qualifier,
            shared_ptr< AP_invocation_identifier> arg__called_AP_invocation_identifier,
            shared_ptr< AE_invocation_identifier> arg__called_AE_invocation_identifier,
            shared_ptr< AP_title> arg__calling_AP_title,
            shared_ptr< AE_qualifier> arg__calling_AE_qualifier,
            shared_ptr< AP_invocation_identifier> arg__calling_AP_invocation_identifier,
            shared_ptr< AE_invocation_identifier> arg__calling_AE_invocation_identifier,
            shared_ptr< ACSE_requirements> arg__sender_acse_requirements,
            shared_ptr< Mechanism_name> arg__mechanism_name,
            shared_ptr< Authentication_value> arg__calling_authentication_value,
            shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
            shared_ptr< Implementation_data> arg__implementation_information,
            shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
            shared_ptr< ASOI_tag> arg__called_asoi_tag,
            shared_ptr< ASOI_tag> arg__calling_asoi_tag,
            shared_ptr< Association_data> arg__user_information) :
    protocol_version_(arg__protocol_version),
    aSO_context_name_(arg__aSO_context_name),
    called_AP_title_(arg__called_AP_title),
    called_AE_qualifier_(arg__called_AE_qualifier),
    called_AP_invocation_identifier_(arg__called_AP_invocation_identifier),
    called_AE_invocation_identifier_(arg__called_AE_invocation_identifier),
    calling_AP_title_(arg__calling_AP_title),
    calling_AE_qualifier_(arg__calling_AE_qualifier),
    calling_AP_invocation_identifier_(arg__calling_AP_invocation_identifier),
    calling_AE_invocation_identifier_(arg__calling_AE_invocation_identifier),
    sender_acse_requirements_(arg__sender_acse_requirements),
    mechanism_name_(arg__mechanism_name),
    calling_authentication_value_(arg__calling_authentication_value),
    aSO_context_name_list_(arg__aSO_context_name_list),
    implementation_information_(arg__implementation_information),
    p_context_definition_list_(arg__p_context_definition_list),
    called_asoi_tag_(arg__called_asoi_tag),
    calling_asoi_tag_(arg__calling_asoi_tag),
    user_information_(arg__user_information) {
    };

    const bitstring_type AARQ_apdu_impl::protocol_version__default = protocol_version_version1;


    ITU_T_DEFAULTH_DEFN(AARQ_apdu_impl::protocol_version, protocol_version, bitstring_type);
    ITU_T_HOLDERH_DEFN(AARQ_apdu_impl::aSO_context_name, aSO_context_name, ASO_context_name);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::called_AP_title, called_AP_title, AP_title);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::called_AE_qualifier, called_AE_qualifier, AE_qualifier);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::called_AP_invocation_identifier, called_AP_invocation_identifier, AP_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::called_AE_invocation_identifier, called_AE_invocation_identifier, AE_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::calling_AP_title, calling_AP_title, AP_title);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::calling_AE_qualifier, calling_AE_qualifier, AE_qualifier);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::calling_AP_invocation_identifier, calling_AP_invocation_identifier, AP_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::calling_AE_invocation_identifier, calling_AE_invocation_identifier, AE_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::sender_acse_requirements, sender_acse_requirements, ACSE_requirements);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::mechanism_name, mechanism_name, Mechanism_name);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::calling_authentication_value, calling_authentication_value, Authentication_value);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::aSO_context_name_list, aSO_context_name_list, ASO_context_name_list);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::implementation_information, implementation_information, Implementation_data);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::p_context_definition_list, p_context_definition_list, Syntactic_context_list);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::called_asoi_tag, called_asoi_tag, ASOI_tag);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::calling_asoi_tag, calling_asoi_tag, ASOI_tag);
    ITU_T_OPTIONAL_DEFN(AARQ_apdu_impl::user_information, user_information, Association_data);

    // sequence AARE-apdu
    const bitstring_type AARE_apdu_impl::protocol_version_version1 = bitstring_type(true, 0);

    AARE_apdu_impl::AARE_apdu_impl() : aSO_context_name_(), result_(), result_source_diagnostic_() {
    };

    AARE_apdu_impl::AARE_apdu_impl(const ASO_context_name& arg__aSO_context_name,
            const Associate_result& arg__result,
            const Associate_source_diagnostic& arg__result_source_diagnostic) :
    aSO_context_name_(arg__aSO_context_name),
    result_(arg__result),
    result_source_diagnostic_(arg__result_source_diagnostic) {
    };

    AARE_apdu_impl::AARE_apdu_impl(shared_ptr< bitstring_type> arg__protocol_version,
            shared_ptr< ASO_context_name> arg__aSO_context_name,
            shared_ptr< Associate_result> arg__result,
            shared_ptr< Associate_source_diagnostic> arg__result_source_diagnostic,
            shared_ptr< AP_title> arg__responding_AP_title,
            shared_ptr< AE_qualifier> arg__responding_AE_qualifier,
            shared_ptr< AP_invocation_identifier> arg__responding_AP_invocation_identifier,
            shared_ptr< AE_invocation_identifier> arg__responding_AE_invocation_identifier,
            shared_ptr< ACSE_requirements> arg__responder_acse_requirements,
            shared_ptr< Mechanism_name> arg__mechanism_name,
            shared_ptr< Authentication_value> arg__responding_authentication_value,
            shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
            shared_ptr< Implementation_data> arg__implementation_information,
            shared_ptr< P_context_result_list> arg__p_context_result_list,
            shared_ptr< ASOI_tag> arg__called_asoi_tag,
            shared_ptr< ASOI_tag> arg__calling_asoi_tag,
            shared_ptr< Association_data> arg__user_information) :
    protocol_version_(arg__protocol_version),
    aSO_context_name_(arg__aSO_context_name),
    result_(arg__result),
    result_source_diagnostic_(arg__result_source_diagnostic),
    responding_AP_title_(arg__responding_AP_title),
    responding_AE_qualifier_(arg__responding_AE_qualifier),
    responding_AP_invocation_identifier_(arg__responding_AP_invocation_identifier),
    responding_AE_invocation_identifier_(arg__responding_AE_invocation_identifier),
    responder_acse_requirements_(arg__responder_acse_requirements),
    mechanism_name_(arg__mechanism_name),
    responding_authentication_value_(arg__responding_authentication_value),
    aSO_context_name_list_(arg__aSO_context_name_list),
    implementation_information_(arg__implementation_information),
    p_context_result_list_(arg__p_context_result_list),
    called_asoi_tag_(arg__called_asoi_tag),
    calling_asoi_tag_(arg__calling_asoi_tag),
    user_information_(arg__user_information) {
    };

    const bitstring_type AARE_apdu_impl::protocol_version__default = protocol_version_version1;


    ITU_T_DEFAULTH_DEFN(AARE_apdu_impl::protocol_version, protocol_version, bitstring_type);
    ITU_T_HOLDERH_DEFN(AARE_apdu_impl::aSO_context_name, aSO_context_name, ASO_context_name);
    ITU_T_HOLDERH_DEFN(AARE_apdu_impl::result, result, Associate_result);
    ITU_T_HOLDERH_DEFN(AARE_apdu_impl::result_source_diagnostic, result_source_diagnostic, Associate_source_diagnostic);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::responding_AP_title, responding_AP_title, AP_title);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::responding_AE_qualifier, responding_AE_qualifier, AE_qualifier);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::responding_AP_invocation_identifier, responding_AP_invocation_identifier, AP_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::responding_AE_invocation_identifier, responding_AE_invocation_identifier, AE_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::responder_acse_requirements, responder_acse_requirements, ACSE_requirements);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::mechanism_name, mechanism_name, Mechanism_name);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::responding_authentication_value, responding_authentication_value, Authentication_value);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::aSO_context_name_list, aSO_context_name_list, ASO_context_name_list);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::implementation_information, implementation_information, Implementation_data);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::p_context_result_list, p_context_result_list, P_context_result_list);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::called_asoi_tag, called_asoi_tag, ASOI_tag);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::calling_asoi_tag, calling_asoi_tag, ASOI_tag);
    ITU_T_OPTIONAL_DEFN(AARE_apdu_impl::user_information, user_information, Association_data);

    // sequence RLRQ-apdu

    RLRQ_apdu_impl::RLRQ_apdu_impl() {
    };

    RLRQ_apdu_impl::RLRQ_apdu_impl(shared_ptr< Release_request_reason> arg__reason,
            shared_ptr< ASO_qualifier> arg__aso_qualifier,
            shared_ptr< ASOI_identifier> arg__asoi_identifier,
            shared_ptr< Association_data> arg__user_information) :
    reason_(arg__reason),
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    user_information_(arg__user_information) {
    };


    ITU_T_OPTIONAL_DEFN(RLRQ_apdu_impl::reason, reason, Release_request_reason);
    ITU_T_OPTIONAL_DEFN(RLRQ_apdu_impl::aso_qualifier, aso_qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(RLRQ_apdu_impl::asoi_identifier, asoi_identifier, ASOI_identifier);
    ITU_T_OPTIONAL_DEFN(RLRQ_apdu_impl::user_information, user_information, Association_data);

    // sequence RLRE-apdu

    RLRE_apdu_impl::RLRE_apdu_impl() {
    };

    RLRE_apdu_impl::RLRE_apdu_impl(shared_ptr< Release_response_reason> arg__reason,
            shared_ptr< ASO_qualifier> arg__aso_qualifier,
            shared_ptr< ASOI_identifier> arg__asoi_identifier,
            shared_ptr< Association_data> arg__user_information) :
    reason_(arg__reason),
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    user_information_(arg__user_information) {
    };


    ITU_T_OPTIONAL_DEFN(RLRE_apdu_impl::reason, reason, Release_response_reason);
    ITU_T_OPTIONAL_DEFN(RLRE_apdu_impl::aso_qualifier, aso_qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(RLRE_apdu_impl::asoi_identifier, asoi_identifier, ASOI_identifier);
    ITU_T_OPTIONAL_DEFN(RLRE_apdu_impl::user_information, user_information, Association_data);

    // sequence ABRT-apdu

    ABRT_apdu_impl::ABRT_apdu_impl() : abort_source_() {
    };

    ABRT_apdu_impl::ABRT_apdu_impl(const ABRT_source& arg__abort_source) :
    abort_source_(arg__abort_source) {
    };

    ABRT_apdu_impl::ABRT_apdu_impl(shared_ptr< ABRT_source> arg__abort_source,
            shared_ptr< ABRT_diagnostic> arg__abort_diagnostic,
            shared_ptr< ASO_qualifier> arg__aso_qualifier,
            shared_ptr< ASOI_identifier> arg__asoi_identifier,
            shared_ptr< Association_data> arg__user_information) :
    abort_source_(arg__abort_source),
    abort_diagnostic_(arg__abort_diagnostic),
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    user_information_(arg__user_information) {
    };


    ITU_T_HOLDERH_DEFN(ABRT_apdu_impl::abort_source, abort_source, ABRT_source);
    ITU_T_OPTIONAL_DEFN(ABRT_apdu_impl::abort_diagnostic, abort_diagnostic, ABRT_diagnostic);
    ITU_T_OPTIONAL_DEFN(ABRT_apdu_impl::aso_qualifier, aso_qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(ABRT_apdu_impl::asoi_identifier, asoi_identifier, ASOI_identifier);
    ITU_T_OPTIONAL_DEFN(ABRT_apdu_impl::user_information, user_information, Association_data);

    // sequence A-DT-apdu

    A_DT_apdu_impl::A_DT_apdu_impl() : a_user_data_() {
    };

    A_DT_apdu_impl::A_DT_apdu_impl(const User_Data& arg__a_user_data) :
    a_user_data_(arg__a_user_data) {
    };

    A_DT_apdu_impl::A_DT_apdu_impl(shared_ptr< ASO_qualifier> arg__aso_qualifier,
            shared_ptr< ASOI_identifier> arg__asoi_identifier,
            shared_ptr< User_Data> arg__a_user_data) :
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    a_user_data_(arg__a_user_data) {
    };


    ITU_T_OPTIONAL_DEFN(A_DT_apdu_impl::aso_qualifier, aso_qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(A_DT_apdu_impl::asoi_identifier, asoi_identifier, ASOI_identifier);
    ITU_T_HOLDERH_DEFN(A_DT_apdu_impl::a_user_data, a_user_data, User_Data);

    // sequence ACRQ-apdu

    ACRQ_apdu_impl::ACRQ_apdu_impl() {
    };

    ACRQ_apdu_impl::ACRQ_apdu_impl(shared_ptr< ASO_qualifier> arg__aso_qualifier,
            shared_ptr< ASOI_identifier> arg__asoi_identifier,
            shared_ptr< ASO_context_name> arg__aSO_context_name,
            shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
            shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
            shared_ptr< User_information> arg__user_information) :
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    aSO_context_name_(arg__aSO_context_name),
    aSO_context_name_list_(arg__aSO_context_name_list),
    p_context_definition_list_(arg__p_context_definition_list),
    user_information_(arg__user_information) {
    };


    ITU_T_OPTIONAL_DEFN(ACRQ_apdu_impl::aso_qualifier, aso_qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(ACRQ_apdu_impl::asoi_identifier, asoi_identifier, ASOI_identifier);
    ITU_T_OPTIONAL_DEFN(ACRQ_apdu_impl::aSO_context_name, aSO_context_name, ASO_context_name);
    ITU_T_OPTIONAL_DEFN(ACRQ_apdu_impl::aSO_context_name_list, aSO_context_name_list, ASO_context_name_list);
    ITU_T_OPTIONAL_DEFN(ACRQ_apdu_impl::p_context_definition_list, p_context_definition_list, Syntactic_context_list);
    ITU_T_OPTIONAL_DEFN(ACRQ_apdu_impl::user_information, user_information, User_information);

    // sequence ACRP-apdu

    ACRP_apdu_impl::ACRP_apdu_impl() {
    };

    ACRP_apdu_impl::ACRP_apdu_impl(shared_ptr< ASO_qualifier> arg__aso_qualifier,
            shared_ptr< ASOI_identifier> arg__asoi_identifier,
            shared_ptr< ASO_context_name_list> arg__aSO_context_name,
            shared_ptr< P_context_result_list> arg__p_context_result_list,
            shared_ptr< User_information> arg__user_information) :
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    aSO_context_name_(arg__aSO_context_name),
    p_context_result_list_(arg__p_context_result_list),
    user_information_(arg__user_information) {
    };


    ITU_T_OPTIONAL_DEFN(ACRP_apdu_impl::aso_qualifier, aso_qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(ACRP_apdu_impl::asoi_identifier, asoi_identifier, ASOI_identifier);
    ITU_T_OPTIONAL_DEFN(ACRP_apdu_impl::aSO_context_name, aSO_context_name, ASO_context_name_list);
    ITU_T_OPTIONAL_DEFN(ACRP_apdu_impl::p_context_result_list, p_context_result_list, P_context_result_list);
    ITU_T_OPTIONAL_DEFN(ACRP_apdu_impl::user_information, user_information, User_information);

    // choice AP-title

    ITU_T_CHOICES_DEFN(AP_title::ap_title_form1, ap_title_form1, AP_title_form1, AP_title_ap_title_form1);
    ITU_T_CHOICES_DEFN(AP_title::ap_title_form2, ap_title_form2, AP_title_form2, AP_title_ap_title_form2);
    ITU_T_CHOICES_DEFN(AP_title::ap_title_form3, ap_title_form3, AP_title_form3, AP_title_ap_title_form3);

    // choice ASO-qualifier

    ITU_T_CHOICES_DEFN(ASO_qualifier::aso_qualifier_form1, aso_qualifier_form1, ASO_qualifier_form1, ASO_qualifier_aso_qualifier_form1);
    ITU_T_CHOICES_DEFN(ASO_qualifier::aso_qualifier_form2, aso_qualifier_form2, ASO_qualifier_form2, ASO_qualifier_aso_qualifier_form2);
    ITU_T_CHOICES_DEFN(ASO_qualifier::aso_qualifier_form3, aso_qualifier_form3, ASO_qualifier_form3, ASO_qualifier_aso_qualifier_form3);

    // choice AE-title

    ITU_T_CHOICES_DEFN(AE_title::ae_title_form1, ae_title_form1, AE_title_form1, AE_title_ae_title_form1);
    ITU_T_CHOICES_DEFN(AE_title::ae_title_form2, ae_title_form2, AE_title_form2, AE_title_ae_title_form2);

    ASOI_tag_sequence_of::ASOI_tag_sequence_of() {
    };

    ASOI_tag_sequence_of::ASOI_tag_sequence_of(shared_ptr< ASO_qualifier> arg__qualifier,
            shared_ptr< ASOI_identifier> arg__identifier) :
    qualifier_(arg__qualifier),
    identifier_(arg__identifier) {
    };


    ITU_T_OPTIONAL_DEFN(ASOI_tag_sequence_of::qualifier, qualifier, ASO_qualifier);
    ITU_T_OPTIONAL_DEFN(ASOI_tag_sequence_of::identifier, identifier, ASOI_identifier);

    // choice Syntactic-context-list

    ITU_T_CHOICEC_DEFN(Syntactic_context_list::context_list, context_list, Context_list, Syntactic_context_list_context_list);
    ITU_T_CHOICEC_DEFN(Syntactic_context_list::default_contact_list, default_contact_list, Default_Context_List, Syntactic_context_list_default_contact_list);

    Context_list_sequence_of::Context_list_sequence_of() : pci_(), abstract_syntax_(), transfer_syntaxes_() {
    };

    Context_list_sequence_of::Context_list_sequence_of(const Presentation_context_identifier& arg__pci,
            const Abstract_syntax_name& arg__abstract_syntax,
            const Transfer_syntaxes_type& arg__transfer_syntaxes) :
    pci_(arg__pci),
    abstract_syntax_(arg__abstract_syntax),
    transfer_syntaxes_(arg__transfer_syntaxes) {
    };


    ITU_T_HOLDERH_DEFN(Context_list_sequence_of::pci, pci, Presentation_context_identifier);
    ITU_T_HOLDERH_DEFN(Context_list_sequence_of::abstract_syntax, abstract_syntax, Abstract_syntax_name);
    ITU_T_HOLDERH_DEFN(Context_list_sequence_of::transfer_syntaxes, transfer_syntaxes, Context_list_sequence_of::Transfer_syntaxes_type);

    Default_Context_List_sequence_of::Default_Context_List_sequence_of() : transfer_syntax_name_() {
    };

    Default_Context_List_sequence_of::Default_Context_List_sequence_of(const Transfer_syntax_name& arg__transfer_syntax_name) :
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };

    Default_Context_List_sequence_of::Default_Context_List_sequence_of(shared_ptr< Abstract_syntax_name> arg__abstract_syntax_name,
            shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name) :
    abstract_syntax_name_(arg__abstract_syntax_name),
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };


    ITU_T_OPTIONAL_DEFN(Default_Context_List_sequence_of::abstract_syntax_name, abstract_syntax_name, Abstract_syntax_name);
    ITU_T_HOLDERH_DEFN(Default_Context_List_sequence_of::transfer_syntax_name, transfer_syntax_name, Transfer_syntax_name);


    const int P_context_result_list_sequence_of::provider_reason_reason_not_specified = 0;
    const int P_context_result_list_sequence_of::provider_reason_abstract_syntax_not_supported = 1;
    const int P_context_result_list_sequence_of::provider_reason_proposed_transfer_syntaxes_not_supported = 2;
    const int P_context_result_list_sequence_of::provider_reason_local_limit_on_DCS_exceeded = 3;

    P_context_result_list_sequence_of::P_context_result_list_sequence_of() : result_() {
    };

    P_context_result_list_sequence_of::P_context_result_list_sequence_of(const Result& arg__result) :
    result_(arg__result) {
    };

    P_context_result_list_sequence_of::P_context_result_list_sequence_of(shared_ptr< Result> arg__result,
            shared_ptr< Concrete_syntax_name> arg__concrete_syntax_name,
            shared_ptr< int> arg__provider_reason) :
    result_(arg__result),
    concrete_syntax_name_(arg__concrete_syntax_name),
    provider_reason_(arg__provider_reason) {
    };


    ITU_T_HOLDERH_DEFN(P_context_result_list_sequence_of::result, result, Result);
    ITU_T_OPTIONAL_DEFN(P_context_result_list_sequence_of::concrete_syntax_name, concrete_syntax_name, Concrete_syntax_name);
    ITU_T_OPTIONAL_DEFN(P_context_result_list_sequence_of::provider_reason, provider_reason, int);

    // choice Associate-source-diagnostic
    const int Associate_source_diagnostic::acse_service_user_null = 0;
    const int Associate_source_diagnostic::acse_service_user_no_reason_given = 1;
    const int Associate_source_diagnostic::acse_service_user_application_context_name_not_supported = 2;
    const int Associate_source_diagnostic::acse_service_user_calling_AP_title_not_recognized = 3;
    const int Associate_source_diagnostic::acse_service_user_calling_AP_invocation_identifier_not_recognized = 4;
    const int Associate_source_diagnostic::acse_service_user_calling_AE_qualifier_not_recognized = 5;
    const int Associate_source_diagnostic::acse_service_user_calling_AE_invocation_identifier_not_recognized = 6;
    const int Associate_source_diagnostic::acse_service_user_called_AP_title_not_recognized = 7;
    const int Associate_source_diagnostic::acse_service_user_called_AP_invocation_identifier_not_recognized = 8;
    const int Associate_source_diagnostic::acse_service_user_called_AE_qualifier_not_recognized = 9;
    const int Associate_source_diagnostic::acse_service_user_called_AE_invocation_identifier_not_recognized = 10;
    const int Associate_source_diagnostic::acse_service_user_authentication_mechanism_name_not_recognized = 11;
    const int Associate_source_diagnostic::acse_service_user_authentication_mechanism_name_required = 12;
    const int Associate_source_diagnostic::acse_service_user_authentication_failure = 13;
    const int Associate_source_diagnostic::acse_service_user_authentication_required = 14;

    const int Associate_source_diagnostic::acse_service_provider_null = 0;
    const int Associate_source_diagnostic::acse_service_provider_no_reason_given = 1;
    const int Associate_source_diagnostic::acse_service_provider_no_common_acse_version = 2;


    ITU_T_CHOICES_DEFN(Associate_source_diagnostic::acse_service_user, acse_service_user, int, Associate_source_diagnostic_acse_service_user);
    ITU_T_CHOICES_DEFN(Associate_source_diagnostic::acse_service_provider, acse_service_provider, int, Associate_source_diagnostic_acse_service_provider);

    // choice User-Data

    ITU_T_CHOICEC_DEFN(User_Data::user_information, user_information, User_information, User_Data_user_information);
    ITU_T_CHOICES_DEFN(User_Data::simply_encoded_data, simply_encoded_data, Simply_encoded_data, User_Data_simply_encoded_data);
    ITU_T_CHOICEC_DEFN(User_Data::fully_encoded_data, fully_encoded_data, PDV_list, User_Data_fully_encoded_data);

    // sequence PDV-list

    PDV_list::PDV_list() : presentation_context_identifier_(), presentation_data_values_() {
    };

    PDV_list::PDV_list(const Presentation_context_identifier& arg__presentation_context_identifier,
            const Presentation_data_values_type& arg__presentation_data_values) :
    presentation_context_identifier_(arg__presentation_context_identifier),
    presentation_data_values_(arg__presentation_data_values) {
    };

    PDV_list::PDV_list(shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
            shared_ptr< Presentation_context_identifier> arg__presentation_context_identifier,
            shared_ptr< Presentation_data_values_type> arg__presentation_data_values) :
    transfer_syntax_name_(arg__transfer_syntax_name),
    presentation_context_identifier_(arg__presentation_context_identifier),
    presentation_data_values_(arg__presentation_data_values) {
    };



    ITU_T_CHOICES_DEFN(PDV_list::Presentation_data_values_type::simple_ASN1_type, simple_ASN1_type, any_type, Presentation_data_values_type_simple_ASN1_type);
    ITU_T_CHOICES_DEFN(PDV_list::Presentation_data_values_type::octet_aligned, octet_aligned, octetstring_type, Presentation_data_values_type_octet_aligned);
    ITU_T_CHOICES_DEFN(PDV_list::Presentation_data_values_type::arbitrary, arbitrary, bitstring_type, Presentation_data_values_type_arbitrary);


    ITU_T_OPTIONAL_DEFN(PDV_list::transfer_syntax_name, transfer_syntax_name, Transfer_syntax_name);
    ITU_T_HOLDERH_DEFN(PDV_list::presentation_context_identifier, presentation_context_identifier, Presentation_context_identifier);
    ITU_T_HOLDERH_DEFN(PDV_list::presentation_data_values, presentation_data_values, PDV_list::Presentation_data_values_type);

    // choice Authentication-value

    Authentication_value::Other_type::Other_type() : other_mechanism_name_(), other_mechanism_value_() {
    };

    Authentication_value::Other_type::Other_type(const any_type& arg__other_mechanism_name,
            const any_type& arg__other_mechanism_value) :
    other_mechanism_name_(arg__other_mechanism_name),
    other_mechanism_value_(arg__other_mechanism_value) {
    };


    ITU_T_HOLDERH_DEFN(Authentication_value::Other_type::other_mechanism_name, other_mechanism_name, any_type);
    ITU_T_HOLDERH_DEFN(Authentication_value::Other_type::other_mechanism_value, other_mechanism_value, any_type);


    ITU_T_CHOICES_DEFN(Authentication_value::charstring, charstring, graphicstring_type, Authentication_value_charstring);
    ITU_T_CHOICES_DEFN(Authentication_value::bitstring, bitstring, bitstring_type, Authentication_value_bitstring);
    ITU_T_CHOICES_DEFN(Authentication_value::external, external, external_type, Authentication_value_external);
    ITU_T_CHOICEC_DEFN(Authentication_value::other, other, Authentication_value::Other_type, Authentication_value_other);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

