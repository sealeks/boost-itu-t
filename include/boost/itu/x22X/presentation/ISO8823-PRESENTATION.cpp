#include "ISO8823-PRESENTATION.hpp"

namespace ISO8823_PRESENTATION {

    const bitstring_type User_session_requirements_half_duplex = bitstring_type(true, 0);
    const bitstring_type User_session_requirements_duplex = bitstring_type(true, 1);
    const bitstring_type User_session_requirements_expedited_data = bitstring_type(true, 2);
    const bitstring_type User_session_requirements_minor_synchronize = bitstring_type(true, 3);
    const bitstring_type User_session_requirements_major_synchronize = bitstring_type(true, 4);
    const bitstring_type User_session_requirements_resynchronize = bitstring_type(true, 5);
    const bitstring_type User_session_requirements_activity_management = bitstring_type(true, 6);
    const bitstring_type User_session_requirements_negotiated_release = bitstring_type(true, 7);
    const bitstring_type User_session_requirements_capability_data = bitstring_type(true, 8);
    const bitstring_type User_session_requirements_exceptions = bitstring_type(true, 9);
    const bitstring_type User_session_requirements_typed_data = bitstring_type(true, 10);
    const bitstring_type User_session_requirements_symmetric_synchronize = bitstring_type(true, 11);
    const bitstring_type User_session_requirements_data_separation = bitstring_type(true, 12);

    // sequence PDV-list

    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case presentation_data_values_type_single_ASN1_type:
            {
                BOOST_ASN_EXPLICIT_TAG(value<any_type > (false, presentation_data_values_type_single_ASN1_type), 0);
                break;
            }
            case presentation_data_values_type_octet_aligned:
            {
                BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false, presentation_data_values_type_octet_aligned), 1);
                break;
            }
            case presentation_data_values_type_arbitrary:
            {
                BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false, presentation_data_values_type_arbitrary), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (BOOST_ASN_EXPLICIT_TAG(value<any_type > (true, presentation_data_values_type_single_ASN1_type), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true, presentation_data_values_type_octet_aligned), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true, presentation_data_values_type_arbitrary), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_BIND_TAG(transfer_syntax_name);
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_CHOICE(presentation_data_values);
    }

    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_BIND_TAG(transfer_syntax_name);
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_CHOICE(presentation_data_values);
    }


    // choice User-data

    template<> void User_data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_data_simply_encoded_data:
            {
                BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Simply_encoded_data > (false, User_data_simply_encoded_data), 0);
                break;
            }
            case User_data_fully_encoded_data:
            {
                BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Fully_encoded_data > (false, User_data_fully_encoded_data), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_data::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Simply_encoded_data > (true, User_data_simply_encoded_data), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Fully_encoded_data > (true, User_data_fully_encoded_data), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }



    const int Result_list_sequence_of::provider_reason_reason_not_specified = 0;
    const int Result_list_sequence_of::provider_reason_abstract_syntax_not_supported = 1;
    const int Result_list_sequence_of::provider_reason_proposed_transfer_syntaxes_not_supported = 2;
    const int Result_list_sequence_of::provider_reason_local_limit_on_DCS_exceeded = 3;

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(result, 0);
        BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name, 1);
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 2);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(result, 0);
        BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name, 1);
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 2);
    }


    const int Result_acceptance = 0;
    const int Result_user_rejection = 1;
    const int Result_provider_rejection = 2;

    const int Provider_reason_reason_not_specified = 0;
    const int Provider_reason_temporary_congestion = 1;
    const int Provider_reason_local_limit_exceeded = 2;
    const int Provider_reason_called_presentation_address_unknown = 3;
    const int Provider_reason_protocol_version_not_supported = 4;
    const int Provider_reason_default_context_not_supported = 5;
    const int Provider_reason_user_data_not_readable = 6;
    const int Provider_reason_no_PSAP_available = 7;

    const bitstring_type Protocol_version_version_1 = bitstring_type(true, 0);

    const bitstring_type Protocol_options_nominated_context = bitstring_type(true, 0);
    const bitstring_type Protocol_options_short_encoding = bitstring_type(true, 1);
    const bitstring_type Protocol_options_packed_encoding_rules = bitstring_type(true, 2);

    const bitstring_type Presentation_requirements_context_management = bitstring_type(true, 0);
    const bitstring_type Presentation_requirements_restoration = bitstring_type(true, 1);

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_BIND_TAG(transfer_syntax_name);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_BIND_TAG(transfer_syntax_name);
    }


    // set Mode-selector
    const int Mode_selector::mode_value_x410_1984_mode = 0;
    const int Mode_selector::mode_value_normal_mode = 1;

    template<> void Mode_selector::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mode_value, 0);
    }

    template<> void Mode_selector::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mode_value, 0);
    }


    const int Event_identifier_cp_PPDU = 0;
    const int Event_identifier_cpa_PPDU = 1;
    const int Event_identifier_cpr_PPDU = 2;
    const int Event_identifier_aru_PPDU = 3;
    const int Event_identifier_arp_PPDU = 4;
    const int Event_identifier_ac_PPDU = 5;
    const int Event_identifier_aca_PPDU = 6;
    const int Event_identifier_td_PPDU = 7;
    const int Event_identifier_ttd_PPDU = 8;
    const int Event_identifier_te_PPDU = 9;
    const int Event_identifier_tc_PPDU = 10;
    const int Event_identifier_tcc_PPDU = 11;
    const int Event_identifier_rs_PPDU = 12;
    const int Event_identifier_rsa_PPDU = 13;
    const int Event_identifier_s_release_indication = 14;
    const int Event_identifier_s_release_confirm = 15;
    const int Event_identifier_s_token_give_indication = 16;
    const int Event_identifier_s_token_please_indication = 17;
    const int Event_identifier_s_control_give_indication = 18;
    const int Event_identifier_s_sync_minor_indication = 19;
    const int Event_identifier_s_sync_minor_confirm = 20;
    const int Event_identifier_s_sync_major_indication = 21;
    const int Event_identifier_s_sync_major_confirm = 22;
    const int Event_identifier_s_p_exception_report_indication = 23;
    const int Event_identifier_s_u_exception_report_indication = 24;
    const int Event_identifier_s_activity_start_indication = 25;
    const int Event_identifier_s_activity_resume_indication = 26;
    const int Event_identifier_s_activity_interrupt_indication = 27;
    const int Event_identifier_s_activity_interrupt_confirm = 28;
    const int Event_identifier_s_activity_discard_indication = 29;
    const int Event_identifier_s_activity_discard_confirm = 30;
    const int Event_identifier_s_activity_end_indication = 31;
    const int Event_identifier_s_activity_end_confirm = 32;

    // sequence Default-context-name

    template<> void Default_context_name::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abstract_syntax_name, 0);
        BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name, 1);
    }

    template<> void Default_context_name::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abstract_syntax_name, 0);
        BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name, 1);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_BIND_TAG(abstract_syntax_name);
        BOOST_ASN_BIND_TAG(transfer_syntax_name_list);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_BIND_TAG(abstract_syntax_name);
        BOOST_ASN_BIND_TAG(transfer_syntax_name_list);
    }


    const int Abort_reason_reason_not_specified = 0;
    const int Abort_reason_unrecognized_ppdu = 1;
    const int Abort_reason_unexpected_ppdu = 2;
    const int Abort_reason_unexpected_session_service_primitive = 3;
    const int Abort_reason_unrecognized_ppdu_parameter = 4;
    const int Abort_reason_unexpected_ppdu_parameter = 5;
    const int Abort_reason_invalid_ppdu_parameter_value = 6;

    // sequence RSA-PPDU

    template<> void RSA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list, 0);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list, 0);
        BOOST_ASN_CHOICE(user_data);
    }


    // sequence RS-PPDU

    template<> void RS_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list, 0);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list, 0);
        BOOST_ASN_CHOICE(user_data);
    }


    // sequence ACA-PPDU

    template<> void ACA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_addition_result_list, 0);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_deletion_result_list, 1);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_addition_result_list, 0);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_deletion_result_list, 1);
        BOOST_ASN_CHOICE(user_data);
    }


    // sequence AC-PPDU

    template<> void AC_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_addition_list, 0);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_deletion_list, 1);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void AC_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_addition_list, 0);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_deletion_list, 1);
        BOOST_ASN_CHOICE(user_data);
    }


    // choice Typed-data-type

    template<> void Typed_data_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Typed_data_type_acPPDU:
            {
                BOOST_ASN_IMPLICIT_TAG(value<AC_PPDU > (false, Typed_data_type_acPPDU), 0);
                break;
            }
            case Typed_data_type_acaPPDU:
            {
                BOOST_ASN_IMPLICIT_TAG(value<ACA_PPDU > (false, Typed_data_type_acaPPDU), 1);
                break;
            }
            case Typed_data_type_ttdPPDU:
            {
                BOOST_ASN_CHOICE(value<User_data > (false, Typed_data_type_ttdPPDU));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Typed_data_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<AC_PPDU > (true, Typed_data_type_acPPDU), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<ACA_PPDU > (true, Typed_data_type_acaPPDU), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (BOOST_ASN_CHOICE(value<User_data > (true, Typed_data_type_ttdPPDU))) return;
                else free();
            }
        }
    }


    // sequence ARP-PPDU

    template<> void ARP_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 0);
        BOOST_ASN_IMPLICIT_TAG(event_identifier, 1);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 0);
        BOOST_ASN_IMPLICIT_TAG(event_identifier, 1);
    }


    // choice ARU-PPDU

    template<> void ARU_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abortReason, 0);
        BOOST_ASN_IMPLICIT_TAG(reflectedParameter, 1);
        BOOST_ASN_EXPLICIT_TAG(userdataAB, 2);
    }

    template<> void ARU_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abortReason, 0);
        BOOST_ASN_IMPLICIT_TAG(reflectedParameter, 1);
        BOOST_ASN_EXPLICIT_TAG(userdataAB, 2);
    }

    template<> void ARU_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list, 0);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void ARU_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list, 0);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ARU_PPDU_x400_mode_parameters:
            {
                BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (false, ARU_PPDU_x400_mode_parameters));
                break;
            }
            case ARU_PPDU_normal_mode_parameters:
            {
                BOOST_ASN_IMPLICIT_TAG(value<normal_mode_parameters_type > (false, ARU_PPDU_normal_mode_parameters), 0);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<normal_mode_parameters_type > (true, ARU_PPDU_normal_mode_parameters), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (true, ARU_PPDU_x400_mode_parameters))) return;
                else free();
            }
        }
    }


    // choice Abort-type

    template<> void Abort_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Abort_type_aru_ppdu:
            {
                BOOST_ASN_CHOICE(value<ARU_PPDU > (false, Abort_type_aru_ppdu));
                break;
            }
            case Abort_type_arp_ppdu:
            {
                BOOST_ASN_BIND_TAG(value<ARP_PPDU > (false, Abort_type_arp_ppdu));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Abort_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (BOOST_ASN_CHOICE(value<ARU_PPDU > (true, Abort_type_aru_ppdu))) return;
                else free();
                if (BOOST_ASN_BIND_TAG(value<ARP_PPDU > (true, Abort_type_arp_ppdu))) return;
                else free();
            }
        }
    }


    // choice CPR-PPDU

    template<> void CPR_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(refuseReason, 0);
        BOOST_ASN_EXPLICIT_TAG(userDataRJ, 1);
    }

    template<> void CPR_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(refuseReason, 0);
        BOOST_ASN_EXPLICIT_TAG(userDataRJ, 1);
    }

    template<> void CPR_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_IMPLICIT_TAG(responding_presentation_selector, 3);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_result_list, 5);
        BOOST_ASN_IMPLICIT_TAG(default_context_result, 7);
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 10);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void CPR_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_IMPLICIT_TAG(responding_presentation_selector, 3);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_result_list, 5);
        BOOST_ASN_IMPLICIT_TAG(default_context_result, 7);
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 10);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void CPR_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CPR_PPDU_x400_mode_parameters:
            {
                BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (false, CPR_PPDU_x400_mode_parameters));
                break;
            }
            case CPR_PPDU_normal_mode_parameters:
            {
                BOOST_ASN_BIND_TAG(value<normal_mode_parameters_type > (false, CPR_PPDU_normal_mode_parameters));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CPR_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (true, CPR_PPDU_x400_mode_parameters))) return;
                else free();
                if (BOOST_ASN_BIND_TAG(value<normal_mode_parameters_type > (true, CPR_PPDU_normal_mode_parameters))) return;
                else free();
            }
        }
    }


    // set CPA-PPDU

    template<> void CPA_PPDU::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_CHOICE_TAG(connectionDataAC, 2);
    }

    template<> void CPA_PPDU::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_CHOICE_TAG(connectionDataAC, 2);
    }

    template<> void CPA_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_IMPLICIT_TAG(responding_presentation_selector, 3);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_result_list, 5);
        BOOST_ASN_IMPLICIT_TAG(presentation_requirements, 8);
        BOOST_ASN_IMPLICIT_TAG(user_session_requirements, 9);
        BOOST_ASN_EXPLICIT_TAG(protocol_options, 11);
        BOOST_ASN_EXPLICIT_TAG(responders_nominated_context, 13);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void CPA_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_IMPLICIT_TAG(responding_presentation_selector, 3);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_result_list, 5);
        BOOST_ASN_IMPLICIT_TAG(presentation_requirements, 8);
        BOOST_ASN_IMPLICIT_TAG(user_session_requirements, 9);
        BOOST_ASN_EXPLICIT_TAG(protocol_options, 11);
        BOOST_ASN_EXPLICIT_TAG(responders_nominated_context, 13);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mode_selector, 0);
        BOOST_ASN_IMPLICIT_TAG(x410_mode_parameters, 1);
        BOOST_ASN_IMPLICIT_TAG(normal_mode_parameters, 2);
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mode_selector, 0);
        BOOST_ASN_IMPLICIT_TAG(x410_mode_parameters, 1);
        BOOST_ASN_IMPLICIT_TAG(normal_mode_parameters, 2);
    }


    // set CP-type

    const int CP_type::x410_mode_parameters_type::dialogueMode_monologue = 0;
    const int CP_type::x410_mode_parameters_type::dialogueMode_twa = 1;

    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_IMPLICIT_TAG(dialogueMode, 2);
        BOOST_ASN_CHOICE_TAG(connectionDataRQ, 3);
        BOOST_ASN_IMPLICIT_TAG(applicationProtocol, 4);
    }

    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_IMPLICIT_TAG(dialogueMode, 2);
        BOOST_ASN_CHOICE_TAG(connectionDataRQ, 3);
        BOOST_ASN_IMPLICIT_TAG(applicationProtocol, 4);
    }

    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_IMPLICIT_TAG(calling_presentation_selector, 1);
        BOOST_ASN_IMPLICIT_TAG(called_presentation_selector, 2);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_list, 4);
        BOOST_ASN_IMPLICIT_TAG(default_context_name, 6);
        BOOST_ASN_IMPLICIT_TAG(presentation_requirements, 8);
        BOOST_ASN_IMPLICIT_TAG(user_session_requirements, 9);
        BOOST_ASN_EXPLICIT_TAG(protocol_options, 11);
        BOOST_ASN_EXPLICIT_TAG(initiators_nominated_context, 12);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_IMPLICIT_TAG(calling_presentation_selector, 1);
        BOOST_ASN_IMPLICIT_TAG(called_presentation_selector, 2);
        BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_list, 4);
        BOOST_ASN_IMPLICIT_TAG(default_context_name, 6);
        BOOST_ASN_IMPLICIT_TAG(presentation_requirements, 8);
        BOOST_ASN_IMPLICIT_TAG(user_session_requirements, 9);
        BOOST_ASN_EXPLICIT_TAG(protocol_options, 11);
        BOOST_ASN_EXPLICIT_TAG(initiators_nominated_context, 12);
        BOOST_ASN_CHOICE(user_data);
    }

    template<> void CP_type::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mode_selector, 0);
        BOOST_ASN_IMPLICIT_TAG(x410_mode_parameters, 1);
        BOOST_ASN_IMPLICIT_TAG(normal_mode_parameters, 2);
    }

    template<> void CP_type::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mode_selector, 0);
        BOOST_ASN_IMPLICIT_TAG(x410_mode_parameters, 1);
        BOOST_ASN_IMPLICIT_TAG(normal_mode_parameters, 2);
    }


}
