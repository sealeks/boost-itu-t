#ifndef ___ISO8823_PRESENTATION
#define ___ISO8823_PRESENTATION

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO8823_PRESENTATION {

    ITU_T_USE_UNIVESAL_DECL;


    struct CP_type;
    struct CPA_PPDU;
    struct CPR_PPDU;
    struct Abort_type;
    struct ARU_PPDU;
    struct ARP_PPDU;
    struct Typed_data_type;
    struct AC_PPDU;
    struct ACA_PPDU;
    struct RS_PPDU;
    struct RSA_PPDU;
    struct Default_context_name;
    struct Mode_selector;
    struct User_data;
    struct PDV_list;
    struct Context_list_sequence_of;
    struct Presentation_context_identifier_list_sequence_of;
    struct Result_list_sequence_of;


    typedef integer_type Abort_reason;
    typedef oid_type Abstract_syntax_name;
    typedef integer_type Event_identifier;
    typedef integer_type Presentation_context_identifier; //   Ic(  [ 1  ...   127 ]   ...ext...) 
    typedef bitstring_type Presentation_requirements;
    typedef octetstring_type Presentation_selector; //    Sc (  [ 1  ...   4 ]   ...ext...) 
    typedef bitstring_type Protocol_options;
    typedef bitstring_type Protocol_version;
    typedef integer_type Provider_reason;
    typedef integer_type Result;
    typedef oid_type Transfer_syntax_name;
    typedef octetstring_type Simply_encoded_data;
    typedef bitstring_type User_session_requirements;
    typedef sequence_of< integer_type > Presentation_context_deletion_result_list; //    Sc (  [ 0  ...   7 ]   ...ext...)   //  struct of ->  

    typedef User_data CPC_type;
    typedef Presentation_selector Called_presentation_selector; //    Sc (  [ 1  ...   4 ]   ...ext...) 
    typedef Presentation_selector Calling_presentation_selector; //    Sc (  [ 1  ...   4 ]   ...ext...) 
    typedef Result Default_context_result;
    typedef Presentation_selector Responding_presentation_selector; //    Sc (  [ 1  ...   4 ]   ...ext...) 
    typedef sequence_of< Context_list_sequence_of > Context_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef Context_list Presentation_context_definition_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef Context_list Presentation_context_addition_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef sequence_of< Presentation_context_identifier > Presentation_context_deletion_list; //    Sc (  [ 0  ...   7 ]   ...ext...)   //  struct of ->    //   Ic(  [ 1  ...   127 ]   ...ext...) 
    typedef sequence_of< Presentation_context_identifier_list_sequence_of > Presentation_context_identifier_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef sequence_of< Result_list_sequence_of > Result_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef Result_list Presentation_context_addition_result_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef Result_list Presentation_context_definition_result_list; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef sequence_of< PDV_list > Fully_encoded_data; //    Sc (  [ 1 ]   ...ext...) 


}

#include "Reliable-Transfer-APDU.hpp"

namespace ISO8823_PRESENTATION {

    // import   from  Reliable-Transfer-APDU

    using Reliable_Transfer_APDU::RTORQapdu;
    using Reliable_Transfer_APDU::RTOACapdu;
    using Reliable_Transfer_APDU::RTORJapdu;
    using Reliable_Transfer_APDU::RTABapdu;



    // set  CP-type

    struct CP_type {

        struct X410_mode_parameters_type;
        struct Normal_mode_parameters_type;

        struct X410_mode_parameters_type {

            static const integer_type dialogueMode_monologue;
            static const integer_type dialogueMode_twa;

            static const integer_type checkpointSize__default;
            static const integer_type windowSize__default;
            static const integer_type dialogueMode__default;

            X410_mode_parameters_type();

            X410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataRQ);

            X410_mode_parameters_type(shared_ptr< integer_type> arg__checkpointSize,
                    shared_ptr< integer_type> arg__windowSize,
                    shared_ptr< integer_type> arg__dialogueMode,
                    shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataRQ,
                    shared_ptr< integer_type> arg__applicationProtocol);

            ITU_T_DEFAULTH_DECL(checkpointSize, integer_type, checkpointSize__default);
            ITU_T_DEFAULTH_DECL(windowSize, integer_type, windowSize__default);
            ITU_T_DEFAULTH_DECL(dialogueMode, integer_type, dialogueMode__default);
            ITU_T_HOLDERH_DECL(connectionDataRQ, Reliable_Transfer_APDU::ConnectionData);
            ITU_T_OPTIONAL_DECL(applicationProtocol, integer_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct Normal_mode_parameters_type {

            struct Extensions_type;

            struct Extensions_type {

                Extensions_type();


                ITU_T_ARCHIVE_FUNC;
            };

            static const Protocol_version protocol_version__default;
            static const Protocol_options protocol_options__default;

            Normal_mode_parameters_type();

            Normal_mode_parameters_type(shared_ptr< Protocol_version> arg__protocol_version,
                    shared_ptr< Calling_presentation_selector> arg__calling_presentation_selector,
                    shared_ptr< Called_presentation_selector> arg__called_presentation_selector,
                    shared_ptr< Presentation_context_definition_list> arg__presentation_context_definition_list,
                    shared_ptr< Default_context_name> arg__default_context_name,
                    shared_ptr< Presentation_requirements> arg__presentation_requirements,
                    shared_ptr< User_session_requirements> arg__user_session_requirements,
                    shared_ptr< Protocol_options> arg__protocol_options,
                    shared_ptr< Presentation_context_identifier> arg__initiators_nominated_context,
                    shared_ptr< Extensions_type> arg__extensions,
                    shared_ptr< User_data> arg__user_data);

            ITU_T_DEFAULTH_DECL(protocol_version, Protocol_version, protocol_version__default);
            ITU_T_OPTIONAL_DECL(calling_presentation_selector, Calling_presentation_selector); //    Sc (  [ 1  ...   4 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(called_presentation_selector, Called_presentation_selector); //    Sc (  [ 1  ...   4 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(presentation_context_definition_list, Presentation_context_definition_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(default_context_name, Default_context_name);
            ITU_T_OPTIONAL_DECL(presentation_requirements, Presentation_requirements);
            ITU_T_OPTIONAL_DECL(user_session_requirements, User_session_requirements);
            ITU_T_DEFAULTH_DECL(protocol_options, Protocol_options, protocol_options__default);
            ITU_T_OPTIONAL_DECL(initiators_nominated_context, Presentation_context_identifier); //   Ic(  [ 1  ...   127 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(extensions, Extensions_type);
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };


        CP_type();

        CP_type(const Mode_selector& arg__mode_selector);

        CP_type(shared_ptr< Mode_selector> arg__mode_selector,
                shared_ptr< X410_mode_parameters_type> arg__x410_mode_parameters,
                shared_ptr< Normal_mode_parameters_type> arg__normal_mode_parameters);

        ITU_T_HOLDERH_DECL(mode_selector, Mode_selector);
        ITU_T_OPTIONAL_DECL(x410_mode_parameters, X410_mode_parameters_type);
        ITU_T_OPTIONAL_DECL(normal_mode_parameters, Normal_mode_parameters_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // set  CPA-PPDU

    struct CPA_PPDU {

        struct X410_mode_parameters_type;
        struct Normal_mode_parameters_type;

        struct X410_mode_parameters_type {

            static const integer_type checkpointSize__default;
            static const integer_type windowSize__default;

            X410_mode_parameters_type();

            X410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataAC);

            X410_mode_parameters_type(shared_ptr< integer_type> arg__checkpointSize,
                    shared_ptr< integer_type> arg__windowSize,
                    shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataAC);

            ITU_T_DEFAULTH_DECL(checkpointSize, integer_type, checkpointSize__default);
            ITU_T_DEFAULTH_DECL(windowSize, integer_type, windowSize__default);
            ITU_T_HOLDERH_DECL(connectionDataAC, Reliable_Transfer_APDU::ConnectionData);

            ITU_T_ARCHIVE_FUNC;
        };

        struct Normal_mode_parameters_type {

            static const Protocol_version protocol_version__default;
            static const Protocol_options protocol_options__default;

            Normal_mode_parameters_type();

            Normal_mode_parameters_type(shared_ptr< Protocol_version> arg__protocol_version,
                    shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
                    shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
                    shared_ptr< Presentation_requirements> arg__presentation_requirements,
                    shared_ptr< User_session_requirements> arg__user_session_requirements,
                    shared_ptr< Protocol_options> arg__protocol_options,
                    shared_ptr< Presentation_context_identifier> arg__responders_nominated_context,
                    shared_ptr< User_data> arg__user_data);

            ITU_T_DEFAULTH_DECL(protocol_version, Protocol_version, protocol_version__default);
            ITU_T_OPTIONAL_DECL(responding_presentation_selector, Responding_presentation_selector); //    Sc (  [ 1  ...   4 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(presentation_context_definition_result_list, Presentation_context_definition_result_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(presentation_requirements, Presentation_requirements);
            ITU_T_OPTIONAL_DECL(user_session_requirements, User_session_requirements);
            ITU_T_DEFAULTH_DECL(protocol_options, Protocol_options, protocol_options__default);
            ITU_T_OPTIONAL_DECL(responders_nominated_context, Presentation_context_identifier); //   Ic(  [ 1  ...   127 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };


        CPA_PPDU();

        CPA_PPDU(const Mode_selector& arg__mode_selector);

        CPA_PPDU(shared_ptr< Mode_selector> arg__mode_selector,
                shared_ptr< X410_mode_parameters_type> arg__x410_mode_parameters,
                shared_ptr< Normal_mode_parameters_type> arg__normal_mode_parameters);

        ITU_T_HOLDERH_DECL(mode_selector, Mode_selector);
        ITU_T_OPTIONAL_DECL(x410_mode_parameters, X410_mode_parameters_type);
        ITU_T_OPTIONAL_DECL(normal_mode_parameters, Normal_mode_parameters_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CPR-PPDU

    enum CPR_PPDU_enum {

        CPR_PPDU_null = 0,
        CPR_PPDU_x400_mode_parameters,
        CPR_PPDU_normal_mode_parameters,
    };

    struct CPR_PPDU : public ITU_T_CHOICE(CPR_PPDU_enum) {


        struct X400_mode_parameters_type;
        struct Normal_mode_parameters_type;

        struct X400_mode_parameters_type {

            X400_mode_parameters_type();

            X400_mode_parameters_type(shared_ptr< Reliable_Transfer_APDU::RefuseReason> arg__refuseReason,
                    shared_ptr< any_type> arg__userDataRJ);

            ITU_T_OPTIONAL_DECL(refuseReason, Reliable_Transfer_APDU::RefuseReason);
            ITU_T_OPTIONAL_DECL(userDataRJ, any_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct Normal_mode_parameters_type {

            static const Protocol_version protocol_version__default;

            Normal_mode_parameters_type();

            Normal_mode_parameters_type(shared_ptr< Protocol_version> arg__protocol_version,
                    shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
                    shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
                    shared_ptr< Default_context_result> arg__default_context_result,
                    shared_ptr< Provider_reason> arg__provider_reason,
                    shared_ptr< User_data> arg__user_data);

            ITU_T_DEFAULTH_DECL(protocol_version, Protocol_version, protocol_version__default);
            ITU_T_OPTIONAL_DECL(responding_presentation_selector, Responding_presentation_selector); //    Sc (  [ 1  ...   4 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(presentation_context_definition_result_list, Presentation_context_definition_result_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(default_context_result, Default_context_result);
            ITU_T_OPTIONAL_DECL(provider_reason, Provider_reason);
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(CPR_PPDU);

        ITU_T_CHOICEC_DECL(x400_mode_parameters, X400_mode_parameters_type, CPR_PPDU_x400_mode_parameters);
        ITU_T_CHOICEC_DECL(normal_mode_parameters, Normal_mode_parameters_type, CPR_PPDU_normal_mode_parameters);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Abort-type

    enum Abort_type_enum {

        Abort_type_null = 0,
        Abort_type_aru_ppdu,
        Abort_type_arp_ppdu,
    };

    struct Abort_type : public ITU_T_CHOICE(Abort_type_enum) {


        ITU_T_CHOICE_CTORS(Abort_type);

        ITU_T_CHOICEC_DECL(aru_ppdu, ARU_PPDU, Abort_type_aru_ppdu);
        ITU_T_CHOICEC_DECL(arp_ppdu, ARP_PPDU, Abort_type_arp_ppdu);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ARU-PPDU

    enum ARU_PPDU_enum {

        ARU_PPDU_null = 0,
        ARU_PPDU_x400_mode_parameters,
        ARU_PPDU_normal_mode_parameters,
    };

    struct ARU_PPDU : public ITU_T_CHOICE(ARU_PPDU_enum) {


        struct X400_mode_parameters_type;
        struct Normal_mode_parameters_type;

        struct X400_mode_parameters_type {

            X400_mode_parameters_type();

            X400_mode_parameters_type(shared_ptr< Reliable_Transfer_APDU::AbortReason> arg__abortReason,
                    shared_ptr< bitstring_type> arg__reflectedParameter,
                    shared_ptr< any_type> arg__userdataAB);

            ITU_T_OPTIONAL_DECL(abortReason, Reliable_Transfer_APDU::AbortReason);
            ITU_T_OPTIONAL_DECL(reflectedParameter, bitstring_type);
            ITU_T_OPTIONAL_DECL(userdataAB, any_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct Normal_mode_parameters_type {

            Normal_mode_parameters_type();

            Normal_mode_parameters_type(shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
                    shared_ptr< User_data> arg__user_data);

            ITU_T_OPTIONAL_DECL(presentation_context_identifier_list, Presentation_context_identifier_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(ARU_PPDU);

        ITU_T_CHOICEC_DECL(x400_mode_parameters, X400_mode_parameters_type, ARU_PPDU_x400_mode_parameters);
        ITU_T_CHOICEC_DECL(normal_mode_parameters, Normal_mode_parameters_type, ARU_PPDU_normal_mode_parameters);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ARP-PPDU

    struct ARP_PPDU {

        ARP_PPDU();

        ARP_PPDU(shared_ptr< Abort_reason> arg__provider_reason,
                shared_ptr< Event_identifier> arg__event_identifier);

        ITU_T_OPTIONAL_DECL(provider_reason, Abort_reason);
        ITU_T_OPTIONAL_DECL(event_identifier, Event_identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Typed-data-type

    enum Typed_data_type_enum {

        Typed_data_type_null = 0,
        Typed_data_type_acPPDU,
        Typed_data_type_acaPPDU,
        Typed_data_type_ttdPPDU,
    };

    struct Typed_data_type : public ITU_T_CHOICE(Typed_data_type_enum) {


        ITU_T_CHOICE_CTORS(Typed_data_type);

        ITU_T_CHOICEC_DECL(acPPDU, AC_PPDU, Typed_data_type_acPPDU);
        ITU_T_CHOICEC_DECL(acaPPDU, ACA_PPDU, Typed_data_type_acaPPDU);
        ITU_T_CHOICEC_DECL(ttdPPDU, User_data, Typed_data_type_ttdPPDU);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AC-PPDU

    struct AC_PPDU {

        AC_PPDU();

        AC_PPDU(shared_ptr< Presentation_context_addition_list> arg__presentation_context_addition_list,
                shared_ptr< Presentation_context_deletion_list> arg__presentation_context_deletion_list,
                shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_addition_list, Presentation_context_addition_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(presentation_context_deletion_list, Presentation_context_deletion_list); //    Sc (  [ 0  ...   7 ]   ...ext...)   //  struct of ->    //   Ic(  [ 1  ...   127 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ACA-PPDU

    struct ACA_PPDU {

        ACA_PPDU();

        ACA_PPDU(shared_ptr< Presentation_context_addition_result_list> arg__presentation_context_addition_result_list,
                shared_ptr< Presentation_context_deletion_result_list> arg__presentation_context_deletion_result_list,
                shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_addition_result_list, Presentation_context_addition_result_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(presentation_context_deletion_result_list, Presentation_context_deletion_result_list); //    Sc (  [ 0  ...   7 ]   ...ext...)   //  struct of ->  
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RS-PPDU

    struct RS_PPDU {

        RS_PPDU();

        RS_PPDU(shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
                shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_identifier_list, Presentation_context_identifier_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RSA-PPDU

    struct RSA_PPDU {

        RSA_PPDU();

        RSA_PPDU(shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
                shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_identifier_list, Presentation_context_identifier_list); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    const Abort_reason abort_reason_reason_not_specified = 0;
    const Abort_reason abort_reason_unrecognized_ppdu = 1;
    const Abort_reason abort_reason_unexpected_ppdu = 2;
    const Abort_reason abort_reason_unexpected_session_service_primitive = 3;
    const Abort_reason abort_reason_unrecognized_ppdu_parameter = 4;
    const Abort_reason abort_reason_unexpected_ppdu_parameter = 5;
    const Abort_reason abort_reason_invalid_ppdu_parameter_value = 6;

    struct Context_list_sequence_of {

        typedef sequence_of< Transfer_syntax_name > Transfer_syntax_name_list_type;


        Context_list_sequence_of();

        Context_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
                const Abstract_syntax_name& arg__abstract_syntax_name,
                const Transfer_syntax_name_list_type& arg__transfer_syntax_name_list);

        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier); //   Ic(  [ 1  ...   127 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(abstract_syntax_name, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntax_name_list, Transfer_syntax_name_list_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Default-context-name

    struct Default_context_name {

        Default_context_name();

        Default_context_name(const Abstract_syntax_name& arg__abstract_syntax_name,
                const Transfer_syntax_name& arg__transfer_syntax_name);

        ITU_T_HOLDERH_DECL(abstract_syntax_name, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntax_name, Transfer_syntax_name);

        ITU_T_ARCHIVE_FUNC;
    };

    const Event_identifier event_identifier_cp_PPDU = 0;
    const Event_identifier event_identifier_cpa_PPDU = 1;
    const Event_identifier event_identifier_cpr_PPDU = 2;
    const Event_identifier event_identifier_aru_PPDU = 3;
    const Event_identifier event_identifier_arp_PPDU = 4;
    const Event_identifier event_identifier_ac_PPDU = 5;
    const Event_identifier event_identifier_aca_PPDU = 6;
    const Event_identifier event_identifier_td_PPDU = 7;
    const Event_identifier event_identifier_ttd_PPDU = 8;
    const Event_identifier event_identifier_te_PPDU = 9;
    const Event_identifier event_identifier_tc_PPDU = 10;
    const Event_identifier event_identifier_tcc_PPDU = 11;
    const Event_identifier event_identifier_rs_PPDU = 12;
    const Event_identifier event_identifier_rsa_PPDU = 13;
    const Event_identifier event_identifier_s_release_indication = 14;
    const Event_identifier event_identifier_s_release_confirm = 15;
    const Event_identifier event_identifier_s_token_give_indication = 16;
    const Event_identifier event_identifier_s_token_please_indication = 17;
    const Event_identifier event_identifier_s_control_give_indication = 18;
    const Event_identifier event_identifier_s_sync_minor_indication = 19;
    const Event_identifier event_identifier_s_sync_minor_confirm = 20;
    const Event_identifier event_identifier_s_sync_major_indication = 21;
    const Event_identifier event_identifier_s_sync_major_confirm = 22;
    const Event_identifier event_identifier_s_p_exception_report_indication = 23;
    const Event_identifier event_identifier_s_u_exception_report_indication = 24;
    const Event_identifier event_identifier_s_activity_start_indication = 25;
    const Event_identifier event_identifier_s_activity_resume_indication = 26;
    const Event_identifier event_identifier_s_activity_interrupt_indication = 27;
    const Event_identifier event_identifier_s_activity_interrupt_confirm = 28;
    const Event_identifier event_identifier_s_activity_discard_indication = 29;
    const Event_identifier event_identifier_s_activity_discard_confirm = 30;
    const Event_identifier event_identifier_s_activity_end_indication = 31;
    const Event_identifier event_identifier_s_activity_end_confirm = 32;

    // set  Mode-selector

    struct Mode_selector {

        static const integer_type mode_value_x410_1984_mode;
        static const integer_type mode_value_normal_mode;


        Mode_selector();

        Mode_selector(const integer_type& arg__mode_value);

        ITU_T_HOLDERH_DECL(mode_value, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    struct Presentation_context_identifier_list_sequence_of {

        Presentation_context_identifier_list_sequence_of();

        Presentation_context_identifier_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
                const Transfer_syntax_name& arg__transfer_syntax_name);

        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier); //   Ic(  [ 1  ...   127 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(transfer_syntax_name, Transfer_syntax_name);

        ITU_T_ARCHIVE_FUNC;
    };

    const Presentation_requirements presentation_requirements_context_management = bitstring_type(true, 0);
    const Presentation_requirements presentation_requirements_restoration = bitstring_type(true, 1);

    const Protocol_options protocol_options_nominated_context = bitstring_type(true, 0);
    const Protocol_options protocol_options_short_encoding = bitstring_type(true, 1);
    const Protocol_options protocol_options_packed_encoding_rules = bitstring_type(true, 2);

    const Protocol_version protocol_version_version_1 = bitstring_type(true, 0);

    const Provider_reason provider_reason_reason_not_specified = 0;
    const Provider_reason provider_reason_temporary_congestion = 1;
    const Provider_reason provider_reason_local_limit_exceeded = 2;
    const Provider_reason provider_reason_called_presentation_address_unknown = 3;
    const Provider_reason provider_reason_protocol_version_not_supported = 4;
    const Provider_reason provider_reason_default_context_not_supported = 5;
    const Provider_reason provider_reason_user_data_not_readable = 6;
    const Provider_reason provider_reason_no_PSAP_available = 7;

    const Result result_acceptance = 0;
    const Result result_user_rejection = 1;
    const Result result_provider_rejection = 2;

    struct Result_list_sequence_of {

        static const integer_type provider_reason_reason_not_specified;
        static const integer_type provider_reason_abstract_syntax_not_supported;
        static const integer_type provider_reason_proposed_transfer_syntaxes_not_supported;
        static const integer_type provider_reason_local_limit_on_DCS_exceeded;


        Result_list_sequence_of();

        Result_list_sequence_of(const Result& arg__result);

        Result_list_sequence_of(shared_ptr< Result> arg__result,
                shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
                shared_ptr< integer_type> arg__provider_reason);

        ITU_T_HOLDERH_DECL(result, Result);
        ITU_T_OPTIONAL_DECL(transfer_syntax_name, Transfer_syntax_name);
        ITU_T_OPTIONAL_DECL(provider_reason, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice User-data

    enum User_data_enum {

        User_data_null = 0,
        User_data_simply_encoded_data,
        User_data_fully_encoded_data,
    };

    struct User_data : public ITU_T_CHOICE(User_data_enum) {


        ITU_T_CHOICE_CTORS(User_data);

        ITU_T_CHOICES_DECL(simply_encoded_data, Simply_encoded_data, User_data_simply_encoded_data); // primitive
        ITU_T_CHOICEC_DECL(fully_encoded_data, Fully_encoded_data, User_data_fully_encoded_data); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence PDV-list

    struct PDV_list {

        struct Presentation_data_values_type;

        enum Presentation_data_values_type_enum {

            Presentation_data_values_type_null = 0,
            Presentation_data_values_type_single_ASN1_type,
            Presentation_data_values_type_octet_aligned,
            Presentation_data_values_type_arbitrary,
        };

        struct Presentation_data_values_type : public ITU_T_CHOICE(Presentation_data_values_type_enum) {


            ITU_T_CHOICE_CTORS(Presentation_data_values_type);

            ITU_T_CHOICES_DECL(single_ASN1_type, any_type, Presentation_data_values_type_single_ASN1_type); // primitive
            ITU_T_CHOICES_DECL(octet_aligned, octetstring_type, Presentation_data_values_type_octet_aligned); // primitive
            ITU_T_CHOICES_DECL(arbitrary, bitstring_type, Presentation_data_values_type_arbitrary); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        PDV_list();

        PDV_list(const Presentation_context_identifier& arg__presentation_context_identifier,
                const Presentation_data_values_type& arg__presentation_data_values);

        PDV_list(shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
                shared_ptr< Presentation_context_identifier> arg__presentation_context_identifier,
                shared_ptr< Presentation_data_values_type> arg__presentation_data_values);

        ITU_T_OPTIONAL_DECL(transfer_syntax_name, Transfer_syntax_name);
        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier); //   Ic(  [ 1  ...   127 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(presentation_data_values, Presentation_data_values_type);

        ITU_T_ARCHIVE_FUNC;
    };

    const User_session_requirements user_session_requirements_half_duplex = bitstring_type(true, 0);
    const User_session_requirements user_session_requirements_duplex = bitstring_type(true, 1);
    const User_session_requirements user_session_requirements_expedited_data = bitstring_type(true, 2);
    const User_session_requirements user_session_requirements_minor_synchronize = bitstring_type(true, 3);
    const User_session_requirements user_session_requirements_major_synchronize = bitstring_type(true, 4);
    const User_session_requirements user_session_requirements_resynchronize = bitstring_type(true, 5);
    const User_session_requirements user_session_requirements_activity_management = bitstring_type(true, 6);
    const User_session_requirements user_session_requirements_negotiated_release = bitstring_type(true, 7);
    const User_session_requirements user_session_requirements_capability_data = bitstring_type(true, 8);
    const User_session_requirements user_session_requirements_exceptions = bitstring_type(true, 9);
    const User_session_requirements user_session_requirements_typed_data = bitstring_type(true, 10);
    const User_session_requirements user_session_requirements_symmetric_synchronize = bitstring_type(true, 11);
    const User_session_requirements user_session_requirements_data_separation = bitstring_type(true, 12);

    ITU_T_ARCHIVE_X690_DECL(CP_type);
    ITU_T_ARCHIVE_X690_DECL(CP_type::X410_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(CP_type::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(CP_type::Normal_mode_parameters_type::Extensions_type);
    ITU_T_ARCHIVE_X690_DECL(CPA_PPDU);
    ITU_T_ARCHIVE_X690_DECL(CPA_PPDU::X410_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(CPA_PPDU::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(CPR_PPDU);
    ITU_T_ARCHIVE_X690_DECL(CPR_PPDU::X400_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(CPR_PPDU::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(Abort_type);
    ITU_T_ARCHIVE_X690_DECL(ARU_PPDU);
    ITU_T_ARCHIVE_X690_DECL(ARU_PPDU::X400_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(ARU_PPDU::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X690_DECL(ARP_PPDU);
    ITU_T_ARCHIVE_X690_DECL(Typed_data_type);
    ITU_T_ARCHIVE_X690_DECL(AC_PPDU);
    ITU_T_ARCHIVE_X690_DECL(ACA_PPDU);
    ITU_T_ARCHIVE_X690_DECL(RS_PPDU);
    ITU_T_ARCHIVE_X690_DECL(RSA_PPDU);
    ITU_T_ARCHIVE_X690_DECL(Context_list_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(Default_context_name);
    ITU_T_ARCHIVE_X690_DECL(Mode_selector);
    ITU_T_ARCHIVE_X690_DECL(Presentation_context_identifier_list_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(Result_list_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(User_data);
    ITU_T_ARCHIVE_X690_DECL(PDV_list);
    ITU_T_ARCHIVE_X690_DECL(PDV_list::Presentation_data_values_type);

    ITU_T_ARCHIVE_X691_DECL(CP_type);
    ITU_T_ARCHIVE_X691_DECL(CP_type::X410_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(CP_type::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(CP_type::Normal_mode_parameters_type::Extensions_type);
    ITU_T_ARCHIVE_X691_DECL(CPA_PPDU);
    ITU_T_ARCHIVE_X691_DECL(CPA_PPDU::X410_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(CPA_PPDU::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(CPR_PPDU);
    ITU_T_ARCHIVE_X691_DECL(CPR_PPDU::X400_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(CPR_PPDU::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(Abort_type);
    ITU_T_ARCHIVE_X691_DECL(ARU_PPDU);
    ITU_T_ARCHIVE_X691_DECL(ARU_PPDU::X400_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(ARU_PPDU::Normal_mode_parameters_type);
    ITU_T_ARCHIVE_X691_DECL(ARP_PPDU);
    ITU_T_ARCHIVE_X691_DECL(Typed_data_type);
    ITU_T_ARCHIVE_X691_DECL(AC_PPDU);
    ITU_T_ARCHIVE_X691_DECL(ACA_PPDU);
    ITU_T_ARCHIVE_X691_DECL(RS_PPDU);
    ITU_T_ARCHIVE_X691_DECL(RSA_PPDU);
    ITU_T_ARCHIVE_X691_DECL(Context_list_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(Default_context_name);
    ITU_T_ARCHIVE_X691_DECL(Mode_selector);
    ITU_T_ARCHIVE_X691_DECL(Presentation_context_identifier_list_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(Result_list_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(User_data);
    ITU_T_ARCHIVE_X691_DECL(PDV_list);
    ITU_T_ARCHIVE_X691_DECL(PDV_list::Presentation_data_values_type);

}

ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type::X410_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU::X410_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU::X400_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU::X400_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::Mode_selector)

ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::Abort_type)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::Typed_data_type)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::User_data)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::PDV_list::Presentation_data_values_type)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___ISO8823_PRESENTATION */
