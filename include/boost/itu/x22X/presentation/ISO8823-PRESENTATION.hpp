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


    typedef std::vector< int> Presentation_context_deletion_result_list;


    typedef User_data CPC_type;
    typedef Presentation_selector Called_presentation_selector;
    typedef Presentation_selector Calling_presentation_selector;
    typedef Result Default_context_result;
    typedef Presentation_selector Responding_presentation_selector;
    typedef std::deque< Context_list_sequence_of > Context_list;
    typedef Context_list Presentation_context_definition_list;
    typedef Context_list Presentation_context_addition_list;
    typedef std::deque< Presentation_context_identifier > Presentation_context_deletion_list;
    typedef std::deque< Presentation_context_identifier_list_sequence_of > Presentation_context_identifier_list;
    typedef std::deque< Result_list_sequence_of > Result_list;
    typedef Result_list Presentation_context_addition_result_list;
    typedef Result_list Presentation_context_definition_result_list;
    typedef std::deque< PDV_list > Fully_encoded_data;

}

#include <boost/itu/x22X/presentation/Reliable-Transfer-APDU.hpp>


namespace ISO8823_PRESENTATION {

    // import   from  Reliable-Transfer-APDU

    using Reliable_Transfer_APDU::RTORQapdu;
    using Reliable_Transfer_APDU::RTOACapdu;
    using Reliable_Transfer_APDU::RTORJapdu;
    using Reliable_Transfer_APDU::RTABapdu;




    extern const bitstring_type User_session_requirements_half_duplex;
    extern const bitstring_type User_session_requirements_duplex;
    extern const bitstring_type User_session_requirements_expedited_data;
    extern const bitstring_type User_session_requirements_minor_synchronize;
    extern const bitstring_type User_session_requirements_major_synchronize;
    extern const bitstring_type User_session_requirements_resynchronize;
    extern const bitstring_type User_session_requirements_activity_management;
    extern const bitstring_type User_session_requirements_negotiated_release;
    extern const bitstring_type User_session_requirements_capability_data;
    extern const bitstring_type User_session_requirements_exceptions;
    extern const bitstring_type User_session_requirements_typed_data;
    extern const bitstring_type User_session_requirements_symmetric_synchronize;
    extern const bitstring_type User_session_requirements_data_separation;

    // sequence PDV-list

    struct PDV_list {

        enum presentation_data_values_type_enum {

            presentation_data_values_type_null = 0,
            presentation_data_values_type_single_ASN1_type,
            presentation_data_values_type_octet_aligned,
            presentation_data_values_type_arbitrary,
        };

        struct presentation_data_values_type : public BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) {

            presentation_data_values_type() : BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) () {
            }

            BOOST_ASN_VALUE_CHOICE(single_ASN1_type, any_type, presentation_data_values_type_single_ASN1_type);
            BOOST_ASN_VALUE_CHOICE(octet_aligned, octetstring_type, presentation_data_values_type_octet_aligned);
            BOOST_ASN_VALUE_CHOICE(arbitrary, bitstring_type, presentation_data_values_type_arbitrary);

            BOOST_ASN_ARCHIVE_FUNC;
        };

        PDV_list() : presentation_context_identifier(), presentation_data_values() {
        }

        boost::shared_ptr<Transfer_syntax_name> transfer_syntax_name;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Transfer_syntax_name, transfer_syntax_name)

        Presentation_context_identifier presentation_context_identifier;
        presentation_data_values_type presentation_data_values;

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice User-data

    enum User_data_enum {

        User_data_null = 0,
        User_data_simply_encoded_data,
        User_data_fully_encoded_data,
    };

    struct User_data : public BOOST_ASN_CHOICE_STRUCT(User_data_enum) {

        User_data() : BOOST_ASN_CHOICE_STRUCT(User_data_enum) () {
        }

        BOOST_ASN_VALUE_CHOICE(simply_encoded_data, Simply_encoded_data, User_data_simply_encoded_data);
        BOOST_ASN_VALUE_CHOICE(fully_encoded_data, Fully_encoded_data, User_data_fully_encoded_data);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    struct Result_list_sequence_of {

        static const int provider_reason_reason_not_specified;
        static const int provider_reason_abstract_syntax_not_supported;
        static const int provider_reason_proposed_transfer_syntaxes_not_supported;
        static const int provider_reason_local_limit_on_DCS_exceeded;

        Result_list_sequence_of() : result() {
        }

        Result result;
        boost::shared_ptr<Transfer_syntax_name> transfer_syntax_name;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Transfer_syntax_name, transfer_syntax_name)

        boost::shared_ptr<int> provider_reason;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, provider_reason)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    extern const int Result_acceptance;
    extern const int Result_user_rejection;
    extern const int Result_provider_rejection;

    extern const int Provider_reason_reason_not_specified;
    extern const int Provider_reason_temporary_congestion;
    extern const int Provider_reason_local_limit_exceeded;
    extern const int Provider_reason_called_presentation_address_unknown;
    extern const int Provider_reason_protocol_version_not_supported;
    extern const int Provider_reason_default_context_not_supported;
    extern const int Provider_reason_user_data_not_readable;
    extern const int Provider_reason_no_PSAP_available;

    extern const bitstring_type Protocol_version_version_1;

    extern const bitstring_type Protocol_options_nominated_context;
    extern const bitstring_type Protocol_options_short_encoding;
    extern const bitstring_type Protocol_options_packed_encoding_rules;

    extern const bitstring_type Presentation_requirements_context_management;
    extern const bitstring_type Presentation_requirements_restoration;

    struct Presentation_context_identifier_list_sequence_of {

        Presentation_context_identifier_list_sequence_of() : presentation_context_identifier(), transfer_syntax_name() {
        }

        Presentation_context_identifier presentation_context_identifier;
        Transfer_syntax_name transfer_syntax_name;

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set Mode-selector

    struct Mode_selector {

        static const int mode_value_x410_1984_mode;
        static const int mode_value_normal_mode;

        Mode_selector() : mode_value() {
        }

        int mode_value;

        BOOST_ASN_ARCHIVE_FUNC;
    };

    extern const int Event_identifier_cp_PPDU;
    extern const int Event_identifier_cpa_PPDU;
    extern const int Event_identifier_cpr_PPDU;
    extern const int Event_identifier_aru_PPDU;
    extern const int Event_identifier_arp_PPDU;
    extern const int Event_identifier_ac_PPDU;
    extern const int Event_identifier_aca_PPDU;
    extern const int Event_identifier_td_PPDU;
    extern const int Event_identifier_ttd_PPDU;
    extern const int Event_identifier_te_PPDU;
    extern const int Event_identifier_tc_PPDU;
    extern const int Event_identifier_tcc_PPDU;
    extern const int Event_identifier_rs_PPDU;
    extern const int Event_identifier_rsa_PPDU;
    extern const int Event_identifier_s_release_indication;
    extern const int Event_identifier_s_release_confirm;
    extern const int Event_identifier_s_token_give_indication;
    extern const int Event_identifier_s_token_please_indication;
    extern const int Event_identifier_s_control_give_indication;
    extern const int Event_identifier_s_sync_minor_indication;
    extern const int Event_identifier_s_sync_minor_confirm;
    extern const int Event_identifier_s_sync_major_indication;
    extern const int Event_identifier_s_sync_major_confirm;
    extern const int Event_identifier_s_p_exception_report_indication;
    extern const int Event_identifier_s_u_exception_report_indication;
    extern const int Event_identifier_s_activity_start_indication;
    extern const int Event_identifier_s_activity_resume_indication;
    extern const int Event_identifier_s_activity_interrupt_indication;
    extern const int Event_identifier_s_activity_interrupt_confirm;
    extern const int Event_identifier_s_activity_discard_indication;
    extern const int Event_identifier_s_activity_discard_confirm;
    extern const int Event_identifier_s_activity_end_indication;
    extern const int Event_identifier_s_activity_end_confirm;

    // sequence Default-context-name

    struct Default_context_name {

        Default_context_name() : abstract_syntax_name(), transfer_syntax_name() {
        }

        Abstract_syntax_name abstract_syntax_name;
        Transfer_syntax_name transfer_syntax_name;

        BOOST_ASN_ARCHIVE_FUNC;
    };

    struct Context_list_sequence_of {

        typedef std::vector< Transfer_syntax_name> transfer_syntax_name_list_type;

        Context_list_sequence_of() : presentation_context_identifier(), abstract_syntax_name(), transfer_syntax_name_list() {
        }

        Presentation_context_identifier presentation_context_identifier;
        Abstract_syntax_name abstract_syntax_name;
        transfer_syntax_name_list_type transfer_syntax_name_list;

        BOOST_ASN_ARCHIVE_FUNC;
    };

    extern const int Abort_reason_reason_not_specified;
    extern const int Abort_reason_unrecognized_ppdu;
    extern const int Abort_reason_unexpected_ppdu;
    extern const int Abort_reason_unexpected_session_service_primitive;
    extern const int Abort_reason_unrecognized_ppdu_parameter;
    extern const int Abort_reason_unexpected_ppdu_parameter;
    extern const int Abort_reason_invalid_ppdu_parameter_value;

    // sequence RSA-PPDU

    struct RSA_PPDU {

        RSA_PPDU() {
        }

        boost::shared_ptr<Presentation_context_identifier_list> presentation_context_identifier_list;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier_list, presentation_context_identifier_list)

        boost::shared_ptr<User_data> user_data;
        BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // sequence RS-PPDU

    struct RS_PPDU {

        RS_PPDU() {
        }

        boost::shared_ptr<Presentation_context_identifier_list> presentation_context_identifier_list;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier_list, presentation_context_identifier_list)

        boost::shared_ptr<User_data> user_data;
        BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // sequence ACA-PPDU

    struct ACA_PPDU {

        ACA_PPDU() {
        }

        boost::shared_ptr<Presentation_context_addition_result_list> presentation_context_addition_result_list;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_addition_result_list, presentation_context_addition_result_list)

        boost::shared_ptr<Presentation_context_deletion_result_list> presentation_context_deletion_result_list;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_deletion_result_list, presentation_context_deletion_result_list)

        boost::shared_ptr<User_data> user_data;
        BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // sequence AC-PPDU

    struct AC_PPDU {

        AC_PPDU() {
        }

        boost::shared_ptr<Presentation_context_addition_list> presentation_context_addition_list;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_addition_list, presentation_context_addition_list)

        boost::shared_ptr<Presentation_context_deletion_list> presentation_context_deletion_list;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_deletion_list, presentation_context_deletion_list)

        boost::shared_ptr<User_data> user_data;
        BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice Typed-data-type

    enum Typed_data_type_enum {

        Typed_data_type_null = 0,
        Typed_data_type_acPPDU,
        Typed_data_type_acaPPDU,
        Typed_data_type_ttdPPDU,
    };

    struct Typed_data_type : public BOOST_ASN_CHOICE_STRUCT(Typed_data_type_enum) {

        Typed_data_type() : BOOST_ASN_CHOICE_STRUCT(Typed_data_type_enum) () {
        }

        BOOST_ASN_VALUE_CHOICE(acPPDU, AC_PPDU, Typed_data_type_acPPDU);
        BOOST_ASN_VALUE_CHOICE(acaPPDU, ACA_PPDU, Typed_data_type_acaPPDU);
        BOOST_ASN_VALUE_CHOICE(ttdPPDU, User_data, Typed_data_type_ttdPPDU);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // sequence ARP-PPDU

    struct ARP_PPDU {

        ARP_PPDU() {
        }

        boost::shared_ptr<Abort_reason> provider_reason;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Abort_reason, provider_reason)

        boost::shared_ptr<Event_identifier> event_identifier;
        BOOST_ASN_VALUE_FUNC_DECLARATE(Event_identifier, event_identifier)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice ARU-PPDU

    enum ARU_PPDU_enum {

        ARU_PPDU_null = 0,
        ARU_PPDU_x400_mode_parameters,
        ARU_PPDU_normal_mode_parameters,
    };

    struct ARU_PPDU : public BOOST_ASN_CHOICE_STRUCT(ARU_PPDU_enum) {

        struct x400_mode_parameters_type {

            x400_mode_parameters_type() {
            }

            boost::shared_ptr<Reliable_Transfer_APDU::AbortReason> abortReason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Reliable_Transfer_APDU::AbortReason, abortReason)

            boost::shared_ptr<bitstring_type> reflectedParameter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type, reflectedParameter)

            boost::shared_ptr<any_type> userdataAB;
            BOOST_ASN_VALUE_FUNC_DECLARATE(any_type, userdataAB)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            normal_mode_parameters_type() {
            }

            boost::shared_ptr<Presentation_context_identifier_list> presentation_context_identifier_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier_list, presentation_context_identifier_list)

            boost::shared_ptr<User_data> user_data;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        ARU_PPDU() : BOOST_ASN_CHOICE_STRUCT(ARU_PPDU_enum) () {
        }

        BOOST_ASN_VALUE_CHOICE(x400_mode_parameters, x400_mode_parameters_type, ARU_PPDU_x400_mode_parameters);
        BOOST_ASN_VALUE_CHOICE(normal_mode_parameters, normal_mode_parameters_type, ARU_PPDU_normal_mode_parameters);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice Abort-type

    enum Abort_type_enum {

        Abort_type_null = 0,
        Abort_type_aru_ppdu,
        Abort_type_arp_ppdu,
    };

    struct Abort_type : public BOOST_ASN_CHOICE_STRUCT(Abort_type_enum) {

        Abort_type() : BOOST_ASN_CHOICE_STRUCT(Abort_type_enum) () {
        }

        BOOST_ASN_VALUE_CHOICE(aru_ppdu, ARU_PPDU, Abort_type_aru_ppdu);
        BOOST_ASN_VALUE_CHOICE(arp_ppdu, ARP_PPDU, Abort_type_arp_ppdu);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice CPR-PPDU

    enum CPR_PPDU_enum {

        CPR_PPDU_null = 0,
        CPR_PPDU_x400_mode_parameters,
        CPR_PPDU_normal_mode_parameters,
    };

    struct CPR_PPDU : public BOOST_ASN_CHOICE_STRUCT(CPR_PPDU_enum) {

        struct x400_mode_parameters_type {

            x400_mode_parameters_type() {
            }

            boost::shared_ptr<Reliable_Transfer_APDU::RefuseReason> refuseReason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Reliable_Transfer_APDU::RefuseReason, refuseReason)

            boost::shared_ptr<any_type> userDataRJ;
            BOOST_ASN_VALUE_FUNC_DECLARATE(any_type, userDataRJ)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            normal_mode_parameters_type() {
            }

            boost::shared_ptr<Protocol_version> protocol_version;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_version, protocol_version)

            boost::shared_ptr<Responding_presentation_selector> responding_presentation_selector;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Responding_presentation_selector, responding_presentation_selector)

            boost::shared_ptr<Presentation_context_definition_result_list> presentation_context_definition_result_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_definition_result_list, presentation_context_definition_result_list)

            boost::shared_ptr<Default_context_result> default_context_result;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Default_context_result, default_context_result)

            boost::shared_ptr<Provider_reason> provider_reason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Provider_reason, provider_reason)

            boost::shared_ptr<User_data> user_data;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        CPR_PPDU() : BOOST_ASN_CHOICE_STRUCT(CPR_PPDU_enum) () {
        }

        BOOST_ASN_VALUE_CHOICE(x400_mode_parameters, x400_mode_parameters_type, CPR_PPDU_x400_mode_parameters);
        BOOST_ASN_VALUE_CHOICE(normal_mode_parameters, normal_mode_parameters_type, CPR_PPDU_normal_mode_parameters);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set CPA-PPDU

    struct CPA_PPDU {

        struct x410_mode_parameters_type {

            x410_mode_parameters_type() : connectionDataAC() {
            }

            boost::shared_ptr<int> checkpointSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, checkpointSize)

            boost::shared_ptr<int> windowSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, windowSize)

            Reliable_Transfer_APDU::ConnectionData connectionDataAC;

            BOOST_ASN_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            normal_mode_parameters_type() {
            }

            boost::shared_ptr<Protocol_version> protocol_version;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_version, protocol_version)

            boost::shared_ptr<Responding_presentation_selector> responding_presentation_selector;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Responding_presentation_selector, responding_presentation_selector)

            boost::shared_ptr<Presentation_context_definition_result_list> presentation_context_definition_result_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_definition_result_list, presentation_context_definition_result_list)

            boost::shared_ptr<Presentation_requirements> presentation_requirements;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_requirements, presentation_requirements)

            boost::shared_ptr<User_session_requirements> user_session_requirements;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_session_requirements, user_session_requirements)

            boost::shared_ptr<Protocol_options> protocol_options;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_options, protocol_options)

            boost::shared_ptr<Presentation_context_identifier> responders_nominated_context;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier, responders_nominated_context)

            boost::shared_ptr<User_data> user_data;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        CPA_PPDU() : mode_selector() {
        }

        Mode_selector mode_selector;
        boost::shared_ptr<x410_mode_parameters_type> x410_mode_parameters;
        BOOST_ASN_VALUE_FUNC_DECLARATE(x410_mode_parameters_type, x410_mode_parameters)

        boost::shared_ptr<normal_mode_parameters_type> normal_mode_parameters;
        BOOST_ASN_VALUE_FUNC_DECLARATE(normal_mode_parameters_type, normal_mode_parameters)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set CP-type

    struct CP_type {

        struct x410_mode_parameters_type {

            static const int dialogueMode_monologue;
            static const int dialogueMode_twa;

            x410_mode_parameters_type() : connectionDataRQ() {
            }

            boost::shared_ptr<int> checkpointSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, checkpointSize)

            boost::shared_ptr<int> windowSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, windowSize)

            boost::shared_ptr<int> dialogueMode;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, dialogueMode)

            Reliable_Transfer_APDU::ConnectionData connectionDataRQ;
            boost::shared_ptr<int> applicationProtocol;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, applicationProtocol)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        struct normal_mode_parameters_type {

            normal_mode_parameters_type() {
            }

            boost::shared_ptr<Protocol_version> protocol_version;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_version, protocol_version)

            boost::shared_ptr<Calling_presentation_selector> calling_presentation_selector;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Calling_presentation_selector, calling_presentation_selector)

            boost::shared_ptr<Called_presentation_selector> called_presentation_selector;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Called_presentation_selector, called_presentation_selector)

            boost::shared_ptr<Presentation_context_definition_list> presentation_context_definition_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_definition_list, presentation_context_definition_list)

            boost::shared_ptr<Default_context_name> default_context_name;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Default_context_name, default_context_name)

            boost::shared_ptr<Presentation_requirements> presentation_requirements;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_requirements, presentation_requirements)

            boost::shared_ptr<User_session_requirements> user_session_requirements;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_session_requirements, user_session_requirements)

            boost::shared_ptr<Protocol_options> protocol_options;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_options, protocol_options)

            boost::shared_ptr<Presentation_context_identifier> initiators_nominated_context;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier, initiators_nominated_context)

            boost::shared_ptr<User_data> user_data;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_data, user_data)


            BOOST_ASN_ARCHIVE_FUNC;
        };

        CP_type() : mode_selector() {
        }

        Mode_selector mode_selector;
        boost::shared_ptr<x410_mode_parameters_type> x410_mode_parameters;
        BOOST_ASN_VALUE_FUNC_DECLARATE(x410_mode_parameters_type, x410_mode_parameters)

        boost::shared_ptr<normal_mode_parameters_type> normal_mode_parameters;
        BOOST_ASN_VALUE_FUNC_DECLARATE(normal_mode_parameters_type, normal_mode_parameters)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    template<> void CP_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch);
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

BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type)
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type::x410_mode_parameters_type)
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU)
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU::x410_mode_parameters_type)
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU::x400_mode_parameters_type)
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU::x400_mode_parameters_type)
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::Mode_selector)

BOOST_ASN_CHOICE_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU)
BOOST_ASN_CHOICE_REGESTRATE(ISO8823_PRESENTATION::Abort_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU)
BOOST_ASN_CHOICE_REGESTRATE(ISO8823_PRESENTATION::Typed_data_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO8823_PRESENTATION::User_data)
BOOST_ASN_CHOICE_REGESTRATE(ISO8823_PRESENTATION::PDV_list::presentation_data_values_type)

#endif  /*___ISO8823_PRESENTATION */

