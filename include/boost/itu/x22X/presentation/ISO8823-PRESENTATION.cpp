#include "ISO8823-PRESENTATION.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO8823_PRESENTATION {

    // set  CP-type

    CP_type::CP_type() : mode_selector_() {
    };

    CP_type::CP_type(const Mode_selector& arg__mode_selector) :
    mode_selector_(arg__mode_selector) {
    };

    CP_type::CP_type(shared_ptr< Mode_selector> arg__mode_selector,
            shared_ptr< X410_mode_parameters_type> arg__x410_mode_parameters,
            shared_ptr< Normal_mode_parameters_type> arg__normal_mode_parameters) :
    mode_selector_(arg__mode_selector),
    x410_mode_parameters_(arg__x410_mode_parameters),
    normal_mode_parameters_(arg__normal_mode_parameters) {
    };


    const integer_type CP_type::X410_mode_parameters_type::dialogueMode_monologue = 0;
    const integer_type CP_type::X410_mode_parameters_type::dialogueMode_twa = 1;

    CP_type::X410_mode_parameters_type::X410_mode_parameters_type() : connectionDataRQ_() {
    };

    CP_type::X410_mode_parameters_type::X410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataRQ) :
    connectionDataRQ_(arg__connectionDataRQ) {
    };

    CP_type::X410_mode_parameters_type::X410_mode_parameters_type(shared_ptr< integer_type> arg__checkpointSize,
            shared_ptr< integer_type> arg__windowSize,
            shared_ptr< integer_type> arg__dialogueMode,
            shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataRQ,
            shared_ptr< integer_type> arg__applicationProtocol) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    dialogueMode_(arg__dialogueMode),
    connectionDataRQ_(arg__connectionDataRQ),
    applicationProtocol_(arg__applicationProtocol) {
    };

    const integer_type CP_type::X410_mode_parameters_type::checkpointSize__default = 0;

    const integer_type CP_type::X410_mode_parameters_type::windowSize__default = 3;

    const integer_type CP_type::X410_mode_parameters_type::dialogueMode__default = 0;


    ITU_T_DEFAULTH_DEFN(CP_type::X410_mode_parameters_type::checkpointSize, checkpointSize, integer_type);
    ITU_T_DEFAULTH_DEFN(CP_type::X410_mode_parameters_type::windowSize, windowSize, integer_type);
    ITU_T_DEFAULTH_DEFN(CP_type::X410_mode_parameters_type::dialogueMode, dialogueMode, integer_type);
    ITU_T_HOLDERH_DEFN(CP_type::X410_mode_parameters_type::connectionDataRQ, connectionDataRQ, Reliable_Transfer_APDU::ConnectionData);
    ITU_T_OPTIONAL_DEFN(CP_type::X410_mode_parameters_type::applicationProtocol, applicationProtocol, integer_type);

    CP_type::Normal_mode_parameters_type::Normal_mode_parameters_type() {
    };

    CP_type::Normal_mode_parameters_type::Normal_mode_parameters_type(shared_ptr< Protocol_version> arg__protocol_version,
            shared_ptr< Calling_presentation_selector> arg__calling_presentation_selector,
            shared_ptr< Called_presentation_selector> arg__called_presentation_selector,
            shared_ptr< Presentation_context_definition_list> arg__presentation_context_definition_list,
            shared_ptr< Default_context_name> arg__default_context_name,
            shared_ptr< Presentation_requirements> arg__presentation_requirements,
            shared_ptr< User_session_requirements> arg__user_session_requirements,
            shared_ptr< Protocol_options> arg__protocol_options,
            shared_ptr< Presentation_context_identifier> arg__initiators_nominated_context,
            shared_ptr< Extensions_type> arg__extensions,
            shared_ptr< User_data> arg__user_data) :
    protocol_version_(arg__protocol_version),
    calling_presentation_selector_(arg__calling_presentation_selector),
    called_presentation_selector_(arg__called_presentation_selector),
    presentation_context_definition_list_(arg__presentation_context_definition_list),
    default_context_name_(arg__default_context_name),
    presentation_requirements_(arg__presentation_requirements),
    user_session_requirements_(arg__user_session_requirements),
    protocol_options_(arg__protocol_options),
    initiators_nominated_context_(arg__initiators_nominated_context),
    extensions_(arg__extensions),
    user_data_(arg__user_data) {
    };

    CP_type::Normal_mode_parameters_type::Extensions_type::Extensions_type() {
    };



    const Protocol_version CP_type::Normal_mode_parameters_type::protocol_version__default = Protocol_version(protocol_version_version_1);

    const Protocol_options CP_type::Normal_mode_parameters_type::protocol_options__default = Protocol_options();


    ITU_T_DEFAULTH_DEFN(CP_type::Normal_mode_parameters_type::protocol_version, protocol_version, Protocol_version);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::calling_presentation_selector, calling_presentation_selector, Calling_presentation_selector);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::called_presentation_selector, called_presentation_selector, Called_presentation_selector);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::presentation_context_definition_list, presentation_context_definition_list, Presentation_context_definition_list);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::default_context_name, default_context_name, Default_context_name);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::presentation_requirements, presentation_requirements, Presentation_requirements);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::user_session_requirements, user_session_requirements, User_session_requirements);
    ITU_T_DEFAULTH_DEFN(CP_type::Normal_mode_parameters_type::protocol_options, protocol_options, Protocol_options);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::initiators_nominated_context, initiators_nominated_context, Presentation_context_identifier);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::extensions, extensions, CP_type::Normal_mode_parameters_type::Extensions_type);
    ITU_T_OPTIONAL_DEFN(CP_type::Normal_mode_parameters_type::user_data, user_data, User_data);


    ITU_T_HOLDERH_DEFN(CP_type::mode_selector, mode_selector, Mode_selector);
    ITU_T_OPTIONAL_DEFN(CP_type::x410_mode_parameters, x410_mode_parameters, CP_type::X410_mode_parameters_type);
    ITU_T_OPTIONAL_DEFN(CP_type::normal_mode_parameters, normal_mode_parameters, CP_type::Normal_mode_parameters_type);

    // set  CPA-PPDU

    CPA_PPDU::CPA_PPDU() : mode_selector_() {
    };

    CPA_PPDU::CPA_PPDU(const Mode_selector& arg__mode_selector) :
    mode_selector_(arg__mode_selector) {
    };

    CPA_PPDU::CPA_PPDU(shared_ptr< Mode_selector> arg__mode_selector,
            shared_ptr< X410_mode_parameters_type> arg__x410_mode_parameters,
            shared_ptr< Normal_mode_parameters_type> arg__normal_mode_parameters) :
    mode_selector_(arg__mode_selector),
    x410_mode_parameters_(arg__x410_mode_parameters),
    normal_mode_parameters_(arg__normal_mode_parameters) {
    };

    CPA_PPDU::X410_mode_parameters_type::X410_mode_parameters_type() : connectionDataAC_() {
    };

    CPA_PPDU::X410_mode_parameters_type::X410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataAC) :
    connectionDataAC_(arg__connectionDataAC) {
    };

    CPA_PPDU::X410_mode_parameters_type::X410_mode_parameters_type(shared_ptr< integer_type> arg__checkpointSize,
            shared_ptr< integer_type> arg__windowSize,
            shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataAC) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    connectionDataAC_(arg__connectionDataAC) {
    };

    const integer_type CPA_PPDU::X410_mode_parameters_type::checkpointSize__default = 0;

    const integer_type CPA_PPDU::X410_mode_parameters_type::windowSize__default = 3;


    ITU_T_DEFAULTH_DEFN(CPA_PPDU::X410_mode_parameters_type::checkpointSize, checkpointSize, integer_type);
    ITU_T_DEFAULTH_DEFN(CPA_PPDU::X410_mode_parameters_type::windowSize, windowSize, integer_type);
    ITU_T_HOLDERH_DEFN(CPA_PPDU::X410_mode_parameters_type::connectionDataAC, connectionDataAC, Reliable_Transfer_APDU::ConnectionData);

    CPA_PPDU::Normal_mode_parameters_type::Normal_mode_parameters_type() {
    };

    CPA_PPDU::Normal_mode_parameters_type::Normal_mode_parameters_type(shared_ptr< Protocol_version> arg__protocol_version,
            shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
            shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
            shared_ptr< Presentation_requirements> arg__presentation_requirements,
            shared_ptr< User_session_requirements> arg__user_session_requirements,
            shared_ptr< Protocol_options> arg__protocol_options,
            shared_ptr< Presentation_context_identifier> arg__responders_nominated_context,
            shared_ptr< User_data> arg__user_data) :
    protocol_version_(arg__protocol_version),
    responding_presentation_selector_(arg__responding_presentation_selector),
    presentation_context_definition_result_list_(arg__presentation_context_definition_result_list),
    presentation_requirements_(arg__presentation_requirements),
    user_session_requirements_(arg__user_session_requirements),
    protocol_options_(arg__protocol_options),
    responders_nominated_context_(arg__responders_nominated_context),
    user_data_(arg__user_data) {
    };

    const Protocol_version CPA_PPDU::Normal_mode_parameters_type::protocol_version__default = Protocol_version(protocol_version_version_1);

    const Protocol_options CPA_PPDU::Normal_mode_parameters_type::protocol_options__default = Protocol_options();


    ITU_T_DEFAULTH_DEFN(CPA_PPDU::Normal_mode_parameters_type::protocol_version, protocol_version, Protocol_version);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::Normal_mode_parameters_type::responding_presentation_selector, responding_presentation_selector, Responding_presentation_selector);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::Normal_mode_parameters_type::presentation_context_definition_result_list, presentation_context_definition_result_list, Presentation_context_definition_result_list);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::Normal_mode_parameters_type::presentation_requirements, presentation_requirements, Presentation_requirements);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::Normal_mode_parameters_type::user_session_requirements, user_session_requirements, User_session_requirements);
    ITU_T_DEFAULTH_DEFN(CPA_PPDU::Normal_mode_parameters_type::protocol_options, protocol_options, Protocol_options);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::Normal_mode_parameters_type::responders_nominated_context, responders_nominated_context, Presentation_context_identifier);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::Normal_mode_parameters_type::user_data, user_data, User_data);


    ITU_T_HOLDERH_DEFN(CPA_PPDU::mode_selector, mode_selector, Mode_selector);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::x410_mode_parameters, x410_mode_parameters, CPA_PPDU::X410_mode_parameters_type);
    ITU_T_OPTIONAL_DEFN(CPA_PPDU::normal_mode_parameters, normal_mode_parameters, CPA_PPDU::Normal_mode_parameters_type);

    // choice CPR-PPDU

    CPR_PPDU::X400_mode_parameters_type::X400_mode_parameters_type() {
    };

    CPR_PPDU::X400_mode_parameters_type::X400_mode_parameters_type(shared_ptr< Reliable_Transfer_APDU::RefuseReason> arg__refuseReason,
            shared_ptr< any_type> arg__userDataRJ) :
    refuseReason_(arg__refuseReason),
    userDataRJ_(arg__userDataRJ) {
    };


    ITU_T_OPTIONAL_DEFN(CPR_PPDU::X400_mode_parameters_type::refuseReason, refuseReason, Reliable_Transfer_APDU::RefuseReason);
    ITU_T_OPTIONAL_DEFN(CPR_PPDU::X400_mode_parameters_type::userDataRJ, userDataRJ, any_type);

    CPR_PPDU::Normal_mode_parameters_type::Normal_mode_parameters_type() {
    };

    CPR_PPDU::Normal_mode_parameters_type::Normal_mode_parameters_type(shared_ptr< Protocol_version> arg__protocol_version,
            shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
            shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
            shared_ptr< Default_context_result> arg__default_context_result,
            shared_ptr< Provider_reason> arg__provider_reason,
            shared_ptr< User_data> arg__user_data) :
    protocol_version_(arg__protocol_version),
    responding_presentation_selector_(arg__responding_presentation_selector),
    presentation_context_definition_result_list_(arg__presentation_context_definition_result_list),
    default_context_result_(arg__default_context_result),
    provider_reason_(arg__provider_reason),
    user_data_(arg__user_data) {
    };

    const Protocol_version CPR_PPDU::Normal_mode_parameters_type::protocol_version__default = Protocol_version(protocol_version_version_1);


    ITU_T_DEFAULTH_DEFN(CPR_PPDU::Normal_mode_parameters_type::protocol_version, protocol_version, Protocol_version);
    ITU_T_OPTIONAL_DEFN(CPR_PPDU::Normal_mode_parameters_type::responding_presentation_selector, responding_presentation_selector, Responding_presentation_selector);
    ITU_T_OPTIONAL_DEFN(CPR_PPDU::Normal_mode_parameters_type::presentation_context_definition_result_list, presentation_context_definition_result_list, Presentation_context_definition_result_list);
    ITU_T_OPTIONAL_DEFN(CPR_PPDU::Normal_mode_parameters_type::default_context_result, default_context_result, Default_context_result);
    ITU_T_OPTIONAL_DEFN(CPR_PPDU::Normal_mode_parameters_type::provider_reason, provider_reason, Provider_reason);
    ITU_T_OPTIONAL_DEFN(CPR_PPDU::Normal_mode_parameters_type::user_data, user_data, User_data);


    ITU_T_CHOICEC_DEFN(CPR_PPDU::x400_mode_parameters, x400_mode_parameters, CPR_PPDU::X400_mode_parameters_type, CPR_PPDU_x400_mode_parameters);
    ITU_T_CHOICEC_DEFN(CPR_PPDU::normal_mode_parameters, normal_mode_parameters, CPR_PPDU::Normal_mode_parameters_type, CPR_PPDU_normal_mode_parameters);

    // choice Abort-type

    ITU_T_CHOICEC_DEFN(Abort_type::aru_ppdu, aru_ppdu, ARU_PPDU, Abort_type_aru_ppdu);
    ITU_T_CHOICEC_DEFN(Abort_type::arp_ppdu, arp_ppdu, ARP_PPDU, Abort_type_arp_ppdu);

    // choice ARU-PPDU

    ARU_PPDU::X400_mode_parameters_type::X400_mode_parameters_type() {
    };

    ARU_PPDU::X400_mode_parameters_type::X400_mode_parameters_type(shared_ptr< Reliable_Transfer_APDU::AbortReason> arg__abortReason,
            shared_ptr< bit_string> arg__reflectedParameter,
            shared_ptr< any_type> arg__userdataAB) :
    abortReason_(arg__abortReason),
    reflectedParameter_(arg__reflectedParameter),
    userdataAB_(arg__userdataAB) {
    };


    ITU_T_OPTIONAL_DEFN(ARU_PPDU::X400_mode_parameters_type::abortReason, abortReason, Reliable_Transfer_APDU::AbortReason);
    ITU_T_OPTIONAL_DEFN(ARU_PPDU::X400_mode_parameters_type::reflectedParameter, reflectedParameter, bit_string);
    ITU_T_OPTIONAL_DEFN(ARU_PPDU::X400_mode_parameters_type::userdataAB, userdataAB, any_type);

    ARU_PPDU::Normal_mode_parameters_type::Normal_mode_parameters_type() {
    };

    ARU_PPDU::Normal_mode_parameters_type::Normal_mode_parameters_type(shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
            shared_ptr< User_data> arg__user_data) :
    presentation_context_identifier_list_(arg__presentation_context_identifier_list),
    user_data_(arg__user_data) {
    };


    ITU_T_OPTIONAL_DEFN(ARU_PPDU::Normal_mode_parameters_type::presentation_context_identifier_list, presentation_context_identifier_list, Presentation_context_identifier_list);
    ITU_T_OPTIONAL_DEFN(ARU_PPDU::Normal_mode_parameters_type::user_data, user_data, User_data);


    ITU_T_CHOICEC_DEFN(ARU_PPDU::x400_mode_parameters, x400_mode_parameters, ARU_PPDU::X400_mode_parameters_type, ARU_PPDU_x400_mode_parameters);
    ITU_T_CHOICEC_DEFN(ARU_PPDU::normal_mode_parameters, normal_mode_parameters, ARU_PPDU::Normal_mode_parameters_type, ARU_PPDU_normal_mode_parameters);

    // sequence ARP-PPDU

    ARP_PPDU::ARP_PPDU() {
    };

    ARP_PPDU::ARP_PPDU(shared_ptr< Abort_reason> arg__provider_reason,
            shared_ptr< Event_identifier> arg__event_identifier) :
    provider_reason_(arg__provider_reason),
    event_identifier_(arg__event_identifier) {
    };


    ITU_T_OPTIONAL_DEFN(ARP_PPDU::provider_reason, provider_reason, Abort_reason);
    ITU_T_OPTIONAL_DEFN(ARP_PPDU::event_identifier, event_identifier, Event_identifier);

    // choice Typed-data-type

    ITU_T_CHOICEC_DEFN(Typed_data_type::acPPDU, acPPDU, AC_PPDU, Typed_data_type_acPPDU);
    ITU_T_CHOICEC_DEFN(Typed_data_type::acaPPDU, acaPPDU, ACA_PPDU, Typed_data_type_acaPPDU);
    ITU_T_CHOICEC_DEFN(Typed_data_type::ttdPPDU, ttdPPDU, User_data, Typed_data_type_ttdPPDU);

    // sequence AC-PPDU

    AC_PPDU::AC_PPDU() {
    };

    AC_PPDU::AC_PPDU(shared_ptr< Presentation_context_addition_list> arg__presentation_context_addition_list,
            shared_ptr< Presentation_context_deletion_list> arg__presentation_context_deletion_list,
            shared_ptr< User_data> arg__user_data) :
    presentation_context_addition_list_(arg__presentation_context_addition_list),
    presentation_context_deletion_list_(arg__presentation_context_deletion_list),
    user_data_(arg__user_data) {
    };


    ITU_T_OPTIONAL_DEFN(AC_PPDU::presentation_context_addition_list, presentation_context_addition_list, Presentation_context_addition_list);
    ITU_T_OPTIONAL_DEFN(AC_PPDU::presentation_context_deletion_list, presentation_context_deletion_list, Presentation_context_deletion_list);
    ITU_T_OPTIONAL_DEFN(AC_PPDU::user_data, user_data, User_data);

    // sequence ACA-PPDU

    ACA_PPDU::ACA_PPDU() {
    };

    ACA_PPDU::ACA_PPDU(shared_ptr< Presentation_context_addition_result_list> arg__presentation_context_addition_result_list,
            shared_ptr< Presentation_context_deletion_result_list> arg__presentation_context_deletion_result_list,
            shared_ptr< User_data> arg__user_data) :
    presentation_context_addition_result_list_(arg__presentation_context_addition_result_list),
    presentation_context_deletion_result_list_(arg__presentation_context_deletion_result_list),
    user_data_(arg__user_data) {
    };


    ITU_T_OPTIONAL_DEFN(ACA_PPDU::presentation_context_addition_result_list, presentation_context_addition_result_list, Presentation_context_addition_result_list);
    ITU_T_OPTIONAL_DEFN(ACA_PPDU::presentation_context_deletion_result_list, presentation_context_deletion_result_list, Presentation_context_deletion_result_list);
    ITU_T_OPTIONAL_DEFN(ACA_PPDU::user_data, user_data, User_data);

    // sequence RS-PPDU

    RS_PPDU::RS_PPDU() {
    };

    RS_PPDU::RS_PPDU(shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
            shared_ptr< User_data> arg__user_data) :
    presentation_context_identifier_list_(arg__presentation_context_identifier_list),
    user_data_(arg__user_data) {
    };


    ITU_T_OPTIONAL_DEFN(RS_PPDU::presentation_context_identifier_list, presentation_context_identifier_list, Presentation_context_identifier_list);
    ITU_T_OPTIONAL_DEFN(RS_PPDU::user_data, user_data, User_data);

    // sequence RSA-PPDU

    RSA_PPDU::RSA_PPDU() {
    };

    RSA_PPDU::RSA_PPDU(shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
            shared_ptr< User_data> arg__user_data) :
    presentation_context_identifier_list_(arg__presentation_context_identifier_list),
    user_data_(arg__user_data) {
    };


    ITU_T_OPTIONAL_DEFN(RSA_PPDU::presentation_context_identifier_list, presentation_context_identifier_list, Presentation_context_identifier_list);
    ITU_T_OPTIONAL_DEFN(RSA_PPDU::user_data, user_data, User_data);

    Context_list_sequence_of::Context_list_sequence_of() : presentation_context_identifier_(), abstract_syntax_name_(), transfer_syntax_name_list_() {
    };

    Context_list_sequence_of::Context_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
            const Abstract_syntax_name& arg__abstract_syntax_name,
            const Transfer_syntax_name_list_type& arg__transfer_syntax_name_list) :
    presentation_context_identifier_(arg__presentation_context_identifier),
    abstract_syntax_name_(arg__abstract_syntax_name),
    transfer_syntax_name_list_(arg__transfer_syntax_name_list) {
    };


    ITU_T_HOLDERH_DEFN(Context_list_sequence_of::presentation_context_identifier, presentation_context_identifier, Presentation_context_identifier);
    ITU_T_HOLDERH_DEFN(Context_list_sequence_of::abstract_syntax_name, abstract_syntax_name, Abstract_syntax_name);
    ITU_T_HOLDERH_DEFN(Context_list_sequence_of::transfer_syntax_name_list, transfer_syntax_name_list, Context_list_sequence_of::Transfer_syntax_name_list_type);

    // sequence Default-context-name

    Default_context_name::Default_context_name() : abstract_syntax_name_(), transfer_syntax_name_() {
    };

    Default_context_name::Default_context_name(const Abstract_syntax_name& arg__abstract_syntax_name,
            const Transfer_syntax_name& arg__transfer_syntax_name) :
    abstract_syntax_name_(arg__abstract_syntax_name),
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };


    ITU_T_HOLDERH_DEFN(Default_context_name::abstract_syntax_name, abstract_syntax_name, Abstract_syntax_name);
    ITU_T_HOLDERH_DEFN(Default_context_name::transfer_syntax_name, transfer_syntax_name, Transfer_syntax_name);

    // set  Mode-selector
    const integer_type Mode_selector::mode_value_x410_1984_mode = 0;
    const integer_type Mode_selector::mode_value_normal_mode = 1;

    Mode_selector::Mode_selector() : mode_value_() {
    };

    Mode_selector::Mode_selector(const integer_type& arg__mode_value) :
    mode_value_(arg__mode_value) {
    };


    ITU_T_HOLDERH_DEFN(Mode_selector::mode_value, mode_value, integer_type);

    Presentation_context_identifier_list_sequence_of::Presentation_context_identifier_list_sequence_of() : presentation_context_identifier_(), transfer_syntax_name_() {
    };

    Presentation_context_identifier_list_sequence_of::Presentation_context_identifier_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
            const Transfer_syntax_name& arg__transfer_syntax_name) :
    presentation_context_identifier_(arg__presentation_context_identifier),
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };


    ITU_T_HOLDERH_DEFN(Presentation_context_identifier_list_sequence_of::presentation_context_identifier, presentation_context_identifier, Presentation_context_identifier);
    ITU_T_HOLDERH_DEFN(Presentation_context_identifier_list_sequence_of::transfer_syntax_name, transfer_syntax_name, Transfer_syntax_name);


    const integer_type Result_list_sequence_of::provider_reason_reason_not_specified = 0;
    const integer_type Result_list_sequence_of::provider_reason_abstract_syntax_not_supported = 1;
    const integer_type Result_list_sequence_of::provider_reason_proposed_transfer_syntaxes_not_supported = 2;
    const integer_type Result_list_sequence_of::provider_reason_local_limit_on_DCS_exceeded = 3;

    Result_list_sequence_of::Result_list_sequence_of() : result_() {
    };

    Result_list_sequence_of::Result_list_sequence_of(const Result& arg__result) :
    result_(arg__result) {
    };

    Result_list_sequence_of::Result_list_sequence_of(shared_ptr< Result> arg__result,
            shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
            shared_ptr< integer_type> arg__provider_reason) :
    result_(arg__result),
    transfer_syntax_name_(arg__transfer_syntax_name),
    provider_reason_(arg__provider_reason) {
    };


    ITU_T_HOLDERH_DEFN(Result_list_sequence_of::result, result, Result);
    ITU_T_OPTIONAL_DEFN(Result_list_sequence_of::transfer_syntax_name, transfer_syntax_name, Transfer_syntax_name);
    ITU_T_OPTIONAL_DEFN(Result_list_sequence_of::provider_reason, provider_reason, integer_type);

    // choice User-data

    ITU_T_CHOICES_DEFN(User_data::simply_encoded_data, simply_encoded_data, Simply_encoded_data, User_data_simply_encoded_data);
    ITU_T_CHOICEC_DEFN(User_data::fully_encoded_data, fully_encoded_data, Fully_encoded_data, User_data_fully_encoded_data);

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



    ITU_T_CHOICES_DEFN(PDV_list::Presentation_data_values_type::single_ASN1_type, single_ASN1_type, any_type, Presentation_data_values_type_single_ASN1_type);
    ITU_T_CHOICES_DEFN(PDV_list::Presentation_data_values_type::octet_aligned, octet_aligned, octet_string, Presentation_data_values_type_octet_aligned);
    ITU_T_CHOICES_DEFN(PDV_list::Presentation_data_values_type::arbitrary, arbitrary, bit_string, Presentation_data_values_type_arbitrary);


    ITU_T_OPTIONAL_DEFN(PDV_list::transfer_syntax_name, transfer_syntax_name, Transfer_syntax_name);
    ITU_T_HOLDERH_DEFN(PDV_list::presentation_context_identifier, presentation_context_identifier, Presentation_context_identifier);
    ITU_T_HOLDERH_DEFN(PDV_list::presentation_data_values, presentation_data_values, PDV_list::Presentation_data_values_type);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

