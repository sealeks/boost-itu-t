#ifndef ___ISO8823_PRESENTATION
#define ___ISO8823_PRESENTATION

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO8823_PRESENTATION {

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


    typedef int Abort_reason;
    typedef oid_type Abstract_syntax_name;
    typedef int Event_identifier;
    typedef int Presentation_context_identifier;
    typedef bitstring_type Presentation_requirements;
    typedef octetstring_type Presentation_selector;
    typedef bitstring_type Protocol_options;
    typedef bitstring_type Protocol_version;
    typedef int Provider_reason;
    typedef int Result;
    typedef oid_type Transfer_syntax_name;
    typedef octetstring_type Simply_encoded_data;
    typedef bitstring_type User_session_requirements;
    typedef std::vector< int > Presentation_context_deletion_result_list;

    typedef User_data CPC_type;
    typedef Presentation_selector Called_presentation_selector;
    typedef Presentation_selector Calling_presentation_selector;
    typedef Result Default_context_result;
    typedef Presentation_selector Responding_presentation_selector;
    typedef std::vector< Context_list_sequence_of > Context_list;
    typedef Context_list Presentation_context_definition_list;
    typedef Context_list Presentation_context_addition_list;
    typedef std::vector< Presentation_context_identifier > Presentation_context_deletion_list;
    typedef std::vector< Presentation_context_identifier_list_sequence_of > Presentation_context_identifier_list;
    typedef std::vector< Result_list_sequence_of > Result_list;
    typedef Result_list Presentation_context_addition_result_list;
    typedef Result_list Presentation_context_definition_result_list;
    typedef std::vector< PDV_list > Fully_encoded_data;


}

#include <boost/itu/x22X/presentation/Reliable-Transfer-APDU.hpp>

namespace ISO8823_PRESENTATION {

    // import   from  Reliable-Transfer-APDU

    using Reliable_Transfer_APDU::RTORQapdu;
    using Reliable_Transfer_APDU::RTOACapdu;
    using Reliable_Transfer_APDU::RTORJapdu;
    using Reliable_Transfer_APDU::RTABapdu;



    // set CP-type

    struct CP_type {

        struct x410_mode_parameters_type;
        struct normal_mode_parameters_type;

        struct x410_mode_parameters_type {

            static const int dialogueMode_monologue;
            static const int dialogueMode_twa;

            static const int checkpointSize__default;
            static const int windowSize__default;
            static const int dialogueMode__default;

            x410_mode_parameters_type();

            x410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataRQ);

            x410_mode_parameters_type(boost::shared_ptr< int> arg__checkpointSize,
                    boost::shared_ptr< int> arg__windowSize,
                    boost::shared_ptr< int> arg__dialogueMode,
                    boost::shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataRQ,
                    boost::shared_ptr< int> arg__applicationProtocol);

            ITU_T_DEFAULTH_DECL(checkpointSize, int, checkpointSize__default);
            ITU_T_DEFAULTH_DECL(windowSize, int, windowSize__default);
            ITU_T_DEFAULTH_DECL(dialogueMode, int, dialogueMode__default);
            ITU_T_HOLDERH_DECL(connectionDataRQ, Reliable_Transfer_APDU::ConnectionData);
            ITU_T_OPTIONAL_DECL(applicationProtocol, int);

            ITU_T_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            struct extensions_type;

            struct extensions_type {

                extensions_type();


                ITU_T_ARCHIVE_FUNC;
            };

            static const Protocol_version protocol_version__default;
            static const Protocol_options protocol_options__default;

            normal_mode_parameters_type();

            normal_mode_parameters_type(boost::shared_ptr< Protocol_version> arg__protocol_version,
                    boost::shared_ptr< Calling_presentation_selector> arg__calling_presentation_selector,
                    boost::shared_ptr< Called_presentation_selector> arg__called_presentation_selector,
                    boost::shared_ptr< Presentation_context_definition_list> arg__presentation_context_definition_list,
                    boost::shared_ptr< Default_context_name> arg__default_context_name,
                    boost::shared_ptr< Presentation_requirements> arg__presentation_requirements,
                    boost::shared_ptr< User_session_requirements> arg__user_session_requirements,
                    boost::shared_ptr< Protocol_options> arg__protocol_options,
                    boost::shared_ptr< Presentation_context_identifier> arg__initiators_nominated_context,
                    boost::shared_ptr< extensions_type> arg__extensions,
                    boost::shared_ptr< User_data> arg__user_data);

            ITU_T_DEFAULTH_DECL(protocol_version, Protocol_version, protocol_version__default);
            ITU_T_OPTIONAL_DECL(calling_presentation_selector, Calling_presentation_selector);
            ITU_T_OPTIONAL_DECL(called_presentation_selector, Called_presentation_selector);
            ITU_T_OPTIONAL_DECL(presentation_context_definition_list, Presentation_context_definition_list);
            ITU_T_OPTIONAL_DECL(default_context_name, Default_context_name);
            ITU_T_OPTIONAL_DECL(presentation_requirements, Presentation_requirements);
            ITU_T_OPTIONAL_DECL(user_session_requirements, User_session_requirements);
            ITU_T_DEFAULTH_DECL(protocol_options, Protocol_options, protocol_options__default);
            ITU_T_OPTIONAL_DECL(initiators_nominated_context, Presentation_context_identifier);
            ITU_T_OPTIONAL_DECL(extensions, extensions_type);
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };


        CP_type();

        CP_type(const Mode_selector& arg__mode_selector);

        CP_type(boost::shared_ptr< Mode_selector> arg__mode_selector,
                boost::shared_ptr< x410_mode_parameters_type> arg__x410_mode_parameters,
                boost::shared_ptr< normal_mode_parameters_type> arg__normal_mode_parameters);

        ITU_T_HOLDERH_DECL(mode_selector, Mode_selector);
        ITU_T_OPTIONAL_DECL(x410_mode_parameters, x410_mode_parameters_type);
        ITU_T_OPTIONAL_DECL(normal_mode_parameters, normal_mode_parameters_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // set CPA-PPDU

    struct CPA_PPDU {

        struct x410_mode_parameters_type;
        struct normal_mode_parameters_type;

        struct x410_mode_parameters_type {

            static const int checkpointSize__default;
            static const int windowSize__default;

            x410_mode_parameters_type();

            x410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataAC);

            x410_mode_parameters_type(boost::shared_ptr< int> arg__checkpointSize,
                    boost::shared_ptr< int> arg__windowSize,
                    boost::shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataAC);

            ITU_T_DEFAULTH_DECL(checkpointSize, int, checkpointSize__default);
            ITU_T_DEFAULTH_DECL(windowSize, int, windowSize__default);
            ITU_T_HOLDERH_DECL(connectionDataAC, Reliable_Transfer_APDU::ConnectionData);

            ITU_T_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            static const Protocol_version protocol_version__default;
            static const Protocol_options protocol_options__default;

            normal_mode_parameters_type();

            normal_mode_parameters_type(boost::shared_ptr< Protocol_version> arg__protocol_version,
                    boost::shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
                    boost::shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
                    boost::shared_ptr< Presentation_requirements> arg__presentation_requirements,
                    boost::shared_ptr< User_session_requirements> arg__user_session_requirements,
                    boost::shared_ptr< Protocol_options> arg__protocol_options,
                    boost::shared_ptr< Presentation_context_identifier> arg__responders_nominated_context,
                    boost::shared_ptr< User_data> arg__user_data);

            ITU_T_DEFAULTH_DECL(protocol_version, Protocol_version, protocol_version__default);
            ITU_T_OPTIONAL_DECL(responding_presentation_selector, Responding_presentation_selector);
            ITU_T_OPTIONAL_DECL(presentation_context_definition_result_list, Presentation_context_definition_result_list);
            ITU_T_OPTIONAL_DECL(presentation_requirements, Presentation_requirements);
            ITU_T_OPTIONAL_DECL(user_session_requirements, User_session_requirements);
            ITU_T_DEFAULTH_DECL(protocol_options, Protocol_options, protocol_options__default);
            ITU_T_OPTIONAL_DECL(responders_nominated_context, Presentation_context_identifier);
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };


        CPA_PPDU();

        CPA_PPDU(const Mode_selector& arg__mode_selector);

        CPA_PPDU(boost::shared_ptr< Mode_selector> arg__mode_selector,
                boost::shared_ptr< x410_mode_parameters_type> arg__x410_mode_parameters,
                boost::shared_ptr< normal_mode_parameters_type> arg__normal_mode_parameters);

        ITU_T_HOLDERH_DECL(mode_selector, Mode_selector);
        ITU_T_OPTIONAL_DECL(x410_mode_parameters, x410_mode_parameters_type);
        ITU_T_OPTIONAL_DECL(normal_mode_parameters, normal_mode_parameters_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CPR-PPDU

    enum CPR_PPDU_enum {

        CPR_PPDU_null = 0,
        CPR_PPDU_x400_mode_parameters,
        CPR_PPDU_normal_mode_parameters,
    };

    struct CPR_PPDU : public ITU_T_CHOICE(CPR_PPDU_enum) {


        struct x400_mode_parameters_type;
        struct normal_mode_parameters_type;

        struct x400_mode_parameters_type {

            x400_mode_parameters_type();

            x400_mode_parameters_type(boost::shared_ptr< Reliable_Transfer_APDU::RefuseReason> arg__refuseReason,
                    boost::shared_ptr< any_type> arg__userDataRJ);

            ITU_T_OPTIONAL_DECL(refuseReason, Reliable_Transfer_APDU::RefuseReason);
            ITU_T_OPTIONAL_DECL(userDataRJ, any_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            static const Protocol_version protocol_version__default;

            normal_mode_parameters_type();

            normal_mode_parameters_type(boost::shared_ptr< Protocol_version> arg__protocol_version,
                    boost::shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
                    boost::shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
                    boost::shared_ptr< Default_context_result> arg__default_context_result,
                    boost::shared_ptr< Provider_reason> arg__provider_reason,
                    boost::shared_ptr< User_data> arg__user_data);

            ITU_T_DEFAULTH_DECL(protocol_version, Protocol_version, protocol_version__default);
            ITU_T_OPTIONAL_DECL(responding_presentation_selector, Responding_presentation_selector);
            ITU_T_OPTIONAL_DECL(presentation_context_definition_result_list, Presentation_context_definition_result_list);
            ITU_T_OPTIONAL_DECL(default_context_result, Default_context_result);
            ITU_T_OPTIONAL_DECL(provider_reason, Provider_reason);
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };

        CPR_PPDU() : ITU_T_CHOICE(CPR_PPDU_enum) () {
        }

        template<typename T > CPR_PPDU(boost::shared_ptr< T> vl, CPR_PPDU_enum enm) :
                ITU_T_CHOICE(CPR_PPDU_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > CPR_PPDU(const T& vl, CPR_PPDU_enum enm) :
                ITU_T_CHOICE(CPR_PPDU_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICEC_DECL(x400_mode_parameters, x400_mode_parameters_type, CPR_PPDU_x400_mode_parameters);
        ITU_T_CHOICEC_DECL(normal_mode_parameters, normal_mode_parameters_type, CPR_PPDU_normal_mode_parameters);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Abort-type

    enum Abort_type_enum {

        Abort_type_null = 0,
        Abort_type_aru_ppdu,
        Abort_type_arp_ppdu,
    };

    struct Abort_type : public ITU_T_CHOICE(Abort_type_enum) {

        Abort_type() : ITU_T_CHOICE(Abort_type_enum) () {
        }

        template<typename T > Abort_type(boost::shared_ptr< T> vl, Abort_type_enum enm) :
                ITU_T_CHOICE(Abort_type_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > Abort_type(const T& vl, Abort_type_enum enm) :
                ITU_T_CHOICE(Abort_type_enum) (new T(vl), static_cast<int> (enm)) {
        }

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


        struct x400_mode_parameters_type;
        struct normal_mode_parameters_type;

        struct x400_mode_parameters_type {

            x400_mode_parameters_type();

            x400_mode_parameters_type(boost::shared_ptr< Reliable_Transfer_APDU::AbortReason> arg__abortReason,
                    boost::shared_ptr< bitstring_type> arg__reflectedParameter,
                    boost::shared_ptr< any_type> arg__userdataAB);

            ITU_T_OPTIONAL_DECL(abortReason, Reliable_Transfer_APDU::AbortReason);
            ITU_T_OPTIONAL_DECL(reflectedParameter, bitstring_type);
            ITU_T_OPTIONAL_DECL(userdataAB, any_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            normal_mode_parameters_type();

            normal_mode_parameters_type(boost::shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
                    boost::shared_ptr< User_data> arg__user_data);

            ITU_T_OPTIONAL_DECL(presentation_context_identifier_list, Presentation_context_identifier_list);
            ITU_T_OPTIONAL_DECL(user_data, User_data);

            ITU_T_ARCHIVE_FUNC;
        };

        ARU_PPDU() : ITU_T_CHOICE(ARU_PPDU_enum) () {
        }

        template<typename T > ARU_PPDU(boost::shared_ptr< T> vl, ARU_PPDU_enum enm) :
                ITU_T_CHOICE(ARU_PPDU_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > ARU_PPDU(const T& vl, ARU_PPDU_enum enm) :
                ITU_T_CHOICE(ARU_PPDU_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICEC_DECL(x400_mode_parameters, x400_mode_parameters_type, ARU_PPDU_x400_mode_parameters);
        ITU_T_CHOICEC_DECL(normal_mode_parameters, normal_mode_parameters_type, ARU_PPDU_normal_mode_parameters);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ARP-PPDU

    struct ARP_PPDU {

        ARP_PPDU();

        ARP_PPDU(boost::shared_ptr< Abort_reason> arg__provider_reason,
                boost::shared_ptr< Event_identifier> arg__event_identifier);

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

        Typed_data_type() : ITU_T_CHOICE(Typed_data_type_enum) () {
        }

        template<typename T > Typed_data_type(boost::shared_ptr< T> vl, Typed_data_type_enum enm) :
                ITU_T_CHOICE(Typed_data_type_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > Typed_data_type(const T& vl, Typed_data_type_enum enm) :
                ITU_T_CHOICE(Typed_data_type_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICEC_DECL(acPPDU, AC_PPDU, Typed_data_type_acPPDU);
        ITU_T_CHOICEC_DECL(acaPPDU, ACA_PPDU, Typed_data_type_acaPPDU);
        ITU_T_CHOICEC_DECL(ttdPPDU, User_data, Typed_data_type_ttdPPDU);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AC-PPDU

    struct AC_PPDU {

        AC_PPDU();

        AC_PPDU(boost::shared_ptr< Presentation_context_addition_list> arg__presentation_context_addition_list,
                boost::shared_ptr< Presentation_context_deletion_list> arg__presentation_context_deletion_list,
                boost::shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_addition_list, Presentation_context_addition_list);
        ITU_T_OPTIONAL_DECL(presentation_context_deletion_list, Presentation_context_deletion_list);
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ACA-PPDU

    struct ACA_PPDU {

        ACA_PPDU();

        ACA_PPDU(boost::shared_ptr< Presentation_context_addition_result_list> arg__presentation_context_addition_result_list,
                boost::shared_ptr< Presentation_context_deletion_result_list> arg__presentation_context_deletion_result_list,
                boost::shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_addition_result_list, Presentation_context_addition_result_list);
        ITU_T_OPTIONAL_DECL(presentation_context_deletion_result_list, Presentation_context_deletion_result_list);
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RS-PPDU

    struct RS_PPDU {

        RS_PPDU();

        RS_PPDU(boost::shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
                boost::shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_identifier_list, Presentation_context_identifier_list);
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RSA-PPDU

    struct RSA_PPDU {

        RSA_PPDU();

        RSA_PPDU(boost::shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
                boost::shared_ptr< User_data> arg__user_data);

        ITU_T_OPTIONAL_DECL(presentation_context_identifier_list, Presentation_context_identifier_list);
        ITU_T_OPTIONAL_DECL(user_data, User_data);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const Abort_reason Abort_reason_reason_not_specified;
    extern const Abort_reason Abort_reason_unrecognized_ppdu;
    extern const Abort_reason Abort_reason_unexpected_ppdu;
    extern const Abort_reason Abort_reason_unexpected_session_service_primitive;
    extern const Abort_reason Abort_reason_unrecognized_ppdu_parameter;
    extern const Abort_reason Abort_reason_unexpected_ppdu_parameter;
    extern const Abort_reason Abort_reason_invalid_ppdu_parameter_value;

    struct Context_list_sequence_of {

        typedef std::vector< Transfer_syntax_name > transfer_syntax_name_list_type;


        Context_list_sequence_of();

        Context_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
                const Abstract_syntax_name& arg__abstract_syntax_name,
                const transfer_syntax_name_list_type& arg__transfer_syntax_name_list);

        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier);
        ITU_T_HOLDERH_DECL(abstract_syntax_name, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntax_name_list, transfer_syntax_name_list_type);

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

    extern const Event_identifier Event_identifier_cp_PPDU;
    extern const Event_identifier Event_identifier_cpa_PPDU;
    extern const Event_identifier Event_identifier_cpr_PPDU;
    extern const Event_identifier Event_identifier_aru_PPDU;
    extern const Event_identifier Event_identifier_arp_PPDU;
    extern const Event_identifier Event_identifier_ac_PPDU;
    extern const Event_identifier Event_identifier_aca_PPDU;
    extern const Event_identifier Event_identifier_td_PPDU;
    extern const Event_identifier Event_identifier_ttd_PPDU;
    extern const Event_identifier Event_identifier_te_PPDU;
    extern const Event_identifier Event_identifier_tc_PPDU;
    extern const Event_identifier Event_identifier_tcc_PPDU;
    extern const Event_identifier Event_identifier_rs_PPDU;
    extern const Event_identifier Event_identifier_rsa_PPDU;
    extern const Event_identifier Event_identifier_s_release_indication;
    extern const Event_identifier Event_identifier_s_release_confirm;
    extern const Event_identifier Event_identifier_s_token_give_indication;
    extern const Event_identifier Event_identifier_s_token_please_indication;
    extern const Event_identifier Event_identifier_s_control_give_indication;
    extern const Event_identifier Event_identifier_s_sync_minor_indication;
    extern const Event_identifier Event_identifier_s_sync_minor_confirm;
    extern const Event_identifier Event_identifier_s_sync_major_indication;
    extern const Event_identifier Event_identifier_s_sync_major_confirm;
    extern const Event_identifier Event_identifier_s_p_exception_report_indication;
    extern const Event_identifier Event_identifier_s_u_exception_report_indication;
    extern const Event_identifier Event_identifier_s_activity_start_indication;
    extern const Event_identifier Event_identifier_s_activity_resume_indication;
    extern const Event_identifier Event_identifier_s_activity_interrupt_indication;
    extern const Event_identifier Event_identifier_s_activity_interrupt_confirm;
    extern const Event_identifier Event_identifier_s_activity_discard_indication;
    extern const Event_identifier Event_identifier_s_activity_discard_confirm;
    extern const Event_identifier Event_identifier_s_activity_end_indication;
    extern const Event_identifier Event_identifier_s_activity_end_confirm;

    // set Mode-selector

    struct Mode_selector {

        static const int mode_value_x410_1984_mode;
        static const int mode_value_normal_mode;


        Mode_selector();

        Mode_selector(const int& arg__mode_value);

        ITU_T_HOLDERH_DECL(mode_value, int);

        ITU_T_ARCHIVE_FUNC;
    };

    struct Presentation_context_identifier_list_sequence_of {

        Presentation_context_identifier_list_sequence_of();

        Presentation_context_identifier_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
                const Transfer_syntax_name& arg__transfer_syntax_name);

        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier);
        ITU_T_HOLDERH_DECL(transfer_syntax_name, Transfer_syntax_name);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const Presentation_requirements Presentation_requirements_context_management;
    extern const Presentation_requirements Presentation_requirements_restoration;

    extern const Protocol_options Protocol_options_nominated_context;
    extern const Protocol_options Protocol_options_short_encoding;
    extern const Protocol_options Protocol_options_packed_encoding_rules;

    extern const Protocol_version Protocol_version_version_1;

    extern const Provider_reason Provider_reason_reason_not_specified;
    extern const Provider_reason Provider_reason_temporary_congestion;
    extern const Provider_reason Provider_reason_local_limit_exceeded;
    extern const Provider_reason Provider_reason_called_presentation_address_unknown;
    extern const Provider_reason Provider_reason_protocol_version_not_supported;
    extern const Provider_reason Provider_reason_default_context_not_supported;
    extern const Provider_reason Provider_reason_user_data_not_readable;
    extern const Provider_reason Provider_reason_no_PSAP_available;

    extern const Result Result_acceptance;
    extern const Result Result_user_rejection;
    extern const Result Result_provider_rejection;

    struct Result_list_sequence_of {

        static const int provider_reason_reason_not_specified;
        static const int provider_reason_abstract_syntax_not_supported;
        static const int provider_reason_proposed_transfer_syntaxes_not_supported;
        static const int provider_reason_local_limit_on_DCS_exceeded;


        Result_list_sequence_of();

        Result_list_sequence_of(const Result& arg__result);

        Result_list_sequence_of(boost::shared_ptr< Result> arg__result,
                boost::shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
                boost::shared_ptr< int> arg__provider_reason);

        ITU_T_HOLDERH_DECL(result, Result);
        ITU_T_OPTIONAL_DECL(transfer_syntax_name, Transfer_syntax_name);
        ITU_T_OPTIONAL_DECL(provider_reason, int);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice User-data

    enum User_data_enum {

        User_data_null = 0,
        User_data_simply_encoded_data,
        User_data_fully_encoded_data,
    };

    struct User_data : public ITU_T_CHOICE(User_data_enum) {

        User_data() : ITU_T_CHOICE(User_data_enum) () {
        }

        template<typename T > User_data(boost::shared_ptr< T> vl, User_data_enum enm) :
                ITU_T_CHOICE(User_data_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > User_data(const T& vl, User_data_enum enm) :
                ITU_T_CHOICE(User_data_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICES_DECL(simply_encoded_data, Simply_encoded_data, User_data_simply_encoded_data); // primitive
        ITU_T_CHOICEC_DECL(fully_encoded_data, Fully_encoded_data, User_data_fully_encoded_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence PDV-list

    struct PDV_list {

        struct presentation_data_values_type;

        enum presentation_data_values_type_enum {

            presentation_data_values_type_null = 0,
            presentation_data_values_type_single_ASN1_type,
            presentation_data_values_type_octet_aligned,
            presentation_data_values_type_arbitrary,
        };

        struct presentation_data_values_type : public ITU_T_CHOICE(presentation_data_values_type_enum) {

            presentation_data_values_type() : ITU_T_CHOICE(presentation_data_values_type_enum) () {
            }

            template<typename T > presentation_data_values_type(boost::shared_ptr< T> vl, presentation_data_values_type_enum enm) :
                    ITU_T_CHOICE(presentation_data_values_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > presentation_data_values_type(const T& vl, presentation_data_values_type_enum enm) :
                    ITU_T_CHOICE(presentation_data_values_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

            ITU_T_CHOICES_DECL(single_ASN1_type, any_type, presentation_data_values_type_single_ASN1_type); // primitive
            ITU_T_CHOICES_DECL(octet_aligned, octetstring_type, presentation_data_values_type_octet_aligned); // primitive
            ITU_T_CHOICES_DECL(arbitrary, bitstring_type, presentation_data_values_type_arbitrary); // primitive

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

    extern const User_session_requirements User_session_requirements_half_duplex;
    extern const User_session_requirements User_session_requirements_duplex;
    extern const User_session_requirements User_session_requirements_expedited_data;
    extern const User_session_requirements User_session_requirements_minor_synchronize;
    extern const User_session_requirements User_session_requirements_major_synchronize;
    extern const User_session_requirements User_session_requirements_resynchronize;
    extern const User_session_requirements User_session_requirements_activity_management;
    extern const User_session_requirements User_session_requirements_negotiated_release;
    extern const User_session_requirements User_session_requirements_capability_data;
    extern const User_session_requirements User_session_requirements_exceptions;
    extern const User_session_requirements User_session_requirements_typed_data;
    extern const User_session_requirements User_session_requirements_symmetric_synchronize;
    extern const User_session_requirements User_session_requirements_data_separation;

    template<> void CP_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CP_type::normal_mode_parameters_type::extensions_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::normal_mode_parameters_type::extensions_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CPA_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CPA_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CPA_PPDU::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CPA_PPDU::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CPA_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CPA_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CPR_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CPR_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CPR_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CPR_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CPR_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CPR_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Abort_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Abort_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ARU_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ARU_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ARU_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ARU_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ARU_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ARU_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ARP_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ARP_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Typed_data_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Typed_data_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AC_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AC_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ACA_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACA_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RS_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RS_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RSA_PPDU::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RSA_PPDU::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Default_context_name::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Default_context_name::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Mode_selector::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Mode_selector::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void User_data::serialize(boost::asn1::x690::output_coder& arch);
    template<> void User_data::serialize(boost::asn1::x690::input_coder& arch);
    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch);
    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch);
}

ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type::x410_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU::x410_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU::x400_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU::x400_mode_parameters_type)
ITU_T_SET_REGESTRATE(ISO8823_PRESENTATION::Mode_selector)

ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::Abort_type)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::Typed_data_type)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::User_data)
ITU_T_CHOICE_REGESTRATE(ISO8823_PRESENTATION::PDV_list::presentation_data_values_type)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___ISO8823_PRESENTATION */
