#include "ISO8823-PRESENTATION.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO8823_PRESENTATION {



    // set  CP-type

    template<> void CP_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*mode_selector_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(x410_mode_parameters_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(normal_mode_parameters_, 2, CONTEXT_CLASS);
    }

    template<> void CP_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*mode_selector_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(x410_mode_parameters_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(normal_mode_parameters_, 2, CONTEXT_CLASS);
    }

    // set  x410-mode-parameters

    template<> void CP_type::X410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dialogueMode_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*connectionDataRQ_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(applicationProtocol_, 4, CONTEXT_CLASS);
    }

    template<> void CP_type::X410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dialogueMode_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*connectionDataRQ_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(applicationProtocol_, 4, CONTEXT_CLASS);
    }

    // sequence normal-mode-parameters

    template<> void CP_type::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(calling_presentation_selector_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(called_presentation_selector_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_definition_list_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(default_context_name_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_requirements_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_session_requirements_, 9, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(protocol_options_, 11, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(initiators_nominated_context_, 12, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(extensions_, 14, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CP_type::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(calling_presentation_selector_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(called_presentation_selector_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_definition_list_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(default_context_name_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_requirements_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_session_requirements_, 9, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(protocol_options_, 11, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(initiators_nominated_context_, 12, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(extensions_, 14, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // sequence extensions

    template<> void CP_type::Normal_mode_parameters_type::Extensions_type::serialize(boost::asn1::x690::output_coder& arch) {

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    template<> void CP_type::Normal_mode_parameters_type::Extensions_type::serialize(boost::asn1::x690::input_coder& arch) {

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    // set  CPA-PPDU

    template<> void CPA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*mode_selector_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(x410_mode_parameters_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(normal_mode_parameters_, 2, CONTEXT_CLASS);
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*mode_selector_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(x410_mode_parameters_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(normal_mode_parameters_, 2, CONTEXT_CLASS);
    }

    // set  x410-mode-parameters

    template<> void CPA_PPDU::X410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*connectionDataAC_, 2, CONTEXT_CLASS);
    }

    template<> void CPA_PPDU::X410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*connectionDataAC_, 2, CONTEXT_CLASS);
    }

    // sequence normal-mode-parameters

    template<> void CPA_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(responding_presentation_selector_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_definition_result_list_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_requirements_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_session_requirements_, 9, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(protocol_options_, 11, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(responders_nominated_context_, 13, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CPA_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(responding_presentation_selector_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_definition_result_list_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_requirements_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_session_requirements_, 9, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(protocol_options_, 11, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(responders_nominated_context_, 13, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // choice CPR-PPDU

    template<> void CPR_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CPR_PPDU_x400_mode_parameters:
            {
                ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (false, CPR_PPDU_x400_mode_parameters));
                break;
            }
            case CPR_PPDU_normal_mode_parameters:
            {
                ITU_T_BIND_TAG(*value<Normal_mode_parameters_type > (false, CPR_PPDU_normal_mode_parameters));
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
                    case 17:
                    {
                        if (ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (true, CPR_PPDU_x400_mode_parameters))) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_BIND_TAG(*value<Normal_mode_parameters_type > (true, CPR_PPDU_normal_mode_parameters))) return;
                        else free();
                        break;
                    }
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

    // set  x400-mode-parameters

    template<> void CPR_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(refuseReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userDataRJ_, 1, CONTEXT_CLASS);
    }

    template<> void CPR_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(refuseReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userDataRJ_, 1, CONTEXT_CLASS);
    }

    // sequence normal-mode-parameters

    template<> void CPR_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(responding_presentation_selector_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_definition_result_list_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(default_context_result_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(provider_reason_, 10, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CPR_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(responding_presentation_selector_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_definition_result_list_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(default_context_result_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(provider_reason_, 10, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // choice Abort-type

    template<> void Abort_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Abort_type_aru_ppdu:
            {
                ITU_T_BIND_CHOICE(*value<ARU_PPDU > (false, Abort_type_aru_ppdu));
                break;
            }
            case Abort_type_arp_ppdu:
            {
                ITU_T_BIND_TAG(*value<ARP_PPDU > (false, Abort_type_arp_ppdu));
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
                    case 17:
                    {
                        if (ITU_T_BIND_CHOICE(*value<ARU_PPDU > (true, Abort_type_aru_ppdu))) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_BIND_TAG(*value<ARP_PPDU > (true, Abort_type_arp_ppdu))) return;
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
                    case 0:
                    {
                        if (ITU_T_BIND_CHOICE(*value<ARU_PPDU > (true, Abort_type_aru_ppdu))) return;
                        else free();
                        break;
                    }
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

    // choice ARU-PPDU

    template<> void ARU_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ARU_PPDU_x400_mode_parameters:
            {
                ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (false, ARU_PPDU_x400_mode_parameters));
                break;
            }
            case ARU_PPDU_normal_mode_parameters:
            {
                ITU_T_BIND_IMPLICIT(*value<Normal_mode_parameters_type > (false, ARU_PPDU_normal_mode_parameters), 0, CONTEXT_CLASS);
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
                    case 17:
                    {
                        if (ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (true, ARU_PPDU_x400_mode_parameters))) return;
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
                    case 0:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<Normal_mode_parameters_type > (true, ARU_PPDU_normal_mode_parameters), 0, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
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

    // set  x400-mode-parameters

    template<> void ARU_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(abortReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(reflectedParameter_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userdataAB_, 2, CONTEXT_CLASS);
    }

    template<> void ARU_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(abortReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(reflectedParameter_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userdataAB_, 2, CONTEXT_CLASS);
    }

    // sequence normal-mode-parameters

    template<> void ARU_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_identifier_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ARU_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_identifier_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // sequence ARP-PPDU

    template<> void ARP_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(provider_reason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(event_identifier_, 1, CONTEXT_CLASS);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(provider_reason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(event_identifier_, 1, CONTEXT_CLASS);
    }

    // choice Typed-data-type

    template<> void Typed_data_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Typed_data_type_acPPDU:
            {
                ITU_T_BIND_IMPLICIT(*value<AC_PPDU > (false, Typed_data_type_acPPDU), 0, CONTEXT_CLASS);
                break;
            }
            case Typed_data_type_acaPPDU:
            {
                ITU_T_BIND_IMPLICIT(*value<ACA_PPDU > (false, Typed_data_type_acaPPDU), 1, CONTEXT_CLASS);
                break;
            }
            case Typed_data_type_ttdPPDU:
            {
                ITU_T_BIND_CHOICE(*value<User_data > (false, Typed_data_type_ttdPPDU));
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
            case 0x40:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_CHOICE(*value<User_data > (true, Typed_data_type_ttdPPDU))) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_CHOICE(*value<User_data > (true, Typed_data_type_ttdPPDU))) return;
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
                    case 0:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<AC_PPDU > (true, Typed_data_type_acPPDU), 0, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<ACA_PPDU > (true, Typed_data_type_acaPPDU), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
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

    // sequence AC-PPDU

    template<> void AC_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_addition_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_deletion_list_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void AC_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_addition_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_deletion_list_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // sequence ACA-PPDU

    template<> void ACA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_addition_result_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_deletion_result_list_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_addition_result_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(presentation_context_deletion_result_list_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // sequence RS-PPDU

    template<> void RS_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_identifier_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_identifier_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // sequence RSA-PPDU

    template<> void RSA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_identifier_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(presentation_context_identifier_list_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(user_data_);
    }

    // sequence 

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_TAG(*abstract_syntax_name_);
        ITU_T_BIND_TAG(*transfer_syntax_name_list_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_TAG(*abstract_syntax_name_);
        ITU_T_BIND_TAG(*transfer_syntax_name_list_);
    }

    // sequence Default-context-name

    template<> void Default_context_name::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*abstract_syntax_name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(*transfer_syntax_name_, 1, CONTEXT_CLASS);
    }

    template<> void Default_context_name::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*abstract_syntax_name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(*transfer_syntax_name_, 1, CONTEXT_CLASS);
    }

    // set  Mode-selector

    template<> void Mode_selector::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*mode_value_, 0, CONTEXT_CLASS);
    }

    template<> void Mode_selector::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*mode_value_, 0, CONTEXT_CLASS);
    }

    // sequence 

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_TAG(*transfer_syntax_name_);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_TAG(*transfer_syntax_name_);
    }

    // sequence 

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*result_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(transfer_syntax_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(provider_reason_, 2, CONTEXT_CLASS);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*result_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(transfer_syntax_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(provider_reason_, 2, CONTEXT_CLASS);
    }

    // choice User-data

    template<> void User_data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_data_simply_encoded_data:
            {
                ITU_T_BIND_IMPLICIT(*value<Simply_encoded_data > (false, User_data_simply_encoded_data), 0, APPLICATION_CLASS);
                break;
            }
            case User_data_fully_encoded_data:
            {
                ITU_T_BIND_IMPLICIT(*value<Fully_encoded_data > (false, User_data_fully_encoded_data), 1, APPLICATION_CLASS);
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
            case 0x40:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<Simply_encoded_data > (true, User_data_simply_encoded_data), 0, APPLICATION_CLASS)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<Fully_encoded_data > (true, User_data_fully_encoded_data), 1, APPLICATION_CLASS)) return;
                        else free();
                        break;
                    }
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

    // sequence PDV-list

    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(transfer_syntax_name_);
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_CHOICE(*presentation_data_values_);
    }

    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(transfer_syntax_name_);
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_CHOICE(*presentation_data_values_);
    }

    // choice presentation-data-values

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Presentation_data_values_type_single_ASN1_type:
            {
                ITU_T_BIND_EXPLICIT(*value<any_type > (false, Presentation_data_values_type_single_ASN1_type), 0, CONTEXT_CLASS);
                break;
            }
            case Presentation_data_values_type_octet_aligned:
            {
                ITU_T_BIND_IMPLICIT(*value<octetstring_type > (false, Presentation_data_values_type_octet_aligned), 1, CONTEXT_CLASS);
                break;
            }
            case Presentation_data_values_type_arbitrary:
            {
                ITU_T_BIND_IMPLICIT(*value<bitstring_type > (false, Presentation_data_values_type_arbitrary), 2, CONTEXT_CLASS);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<any_type > (true, Presentation_data_values_type_single_ASN1_type), 0, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<octetstring_type > (true, Presentation_data_values_type_octet_aligned), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<bitstring_type > (true, Presentation_data_values_type_arbitrary), 2, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
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

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

