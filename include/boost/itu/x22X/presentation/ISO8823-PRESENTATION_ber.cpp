#include "ISO8823-PRESENTATION.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO8823_PRESENTATION {

    template<> void CP_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    template<> void CP_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    template<> void CP_type::X410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_, 2);
        ITU_T_EXPLICIT_TAG(*connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void CP_type::X410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_, 2);
        ITU_T_EXPLICIT_TAG(*connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void CP_type::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(calling_presentation_selector_, 1);
        ITU_T_IMPLICIT_TAG(called_presentation_selector_, 2);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_list_, 4);
        ITU_T_IMPLICIT_TAG(default_context_name_, 6);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(initiators_nominated_context_, 12);
        ITU_T_EXPLICIT_TAG(extensions_, 14);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CP_type::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(calling_presentation_selector_, 1);
        ITU_T_IMPLICIT_TAG(called_presentation_selector_, 2);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_list_, 4);
        ITU_T_IMPLICIT_TAG(default_context_name_, 6);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(initiators_nominated_context_, 12);
        ITU_T_EXPLICIT_TAG(extensions_, 14);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CP_type::Normal_mode_parameters_type::Extensions_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXTENTION;
    }

    template<> void CP_type::Normal_mode_parameters_type::Extensions_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXTENTION;
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    template<> void CPA_PPDU::X410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_EXPLICIT_TAG(*connectionDataAC_, 2);
    }

    template<> void CPA_PPDU::X410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_EXPLICIT_TAG(*connectionDataAC_, 2);
    }

    template<> void CPA_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(responders_nominated_context_, 13);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CPA_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(responders_nominated_context_, 13);
        ITU_T_BIND_CHOICE(user_data_);
    }

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
                if (ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (true, CPR_PPDU_x400_mode_parameters))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<Normal_mode_parameters_type > (true, CPR_PPDU_normal_mode_parameters))) return;
                else free();
            }
        }
    }

    template<> void CPR_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void CPR_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void CPR_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(default_context_result_, 7);
        ITU_T_IMPLICIT_TAG(provider_reason_, 10);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CPR_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(default_context_result_, 7);
        ITU_T_IMPLICIT_TAG(provider_reason_, 10);
        ITU_T_BIND_CHOICE(user_data_);
    }

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
                if (ITU_T_BIND_CHOICE(*value<ARU_PPDU > (true, Abort_type_aru_ppdu))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<ARP_PPDU > (true, Abort_type_arp_ppdu))) return;
                else free();
            }
        }
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ARU_PPDU_x400_mode_parameters:
            {
                ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (false, ARU_PPDU_x400_mode_parameters));
                break;
            }
            case ARU_PPDU_normal_mode_parameters:
            {
                ITU_T_IMPLICIT_TAG(*value<Normal_mode_parameters_type > (false, ARU_PPDU_normal_mode_parameters), 0);
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
                        if (ITU_T_IMPLICIT_TAG(*value<Normal_mode_parameters_type > (true, ARU_PPDU_normal_mode_parameters), 0)) return;
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
                if (ITU_T_BIND_TAG(*value<X400_mode_parameters_type > (true, ARU_PPDU_x400_mode_parameters))) return;
                else free();
            }
        }
    }

    template<> void ARU_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abortReason_, 0);
        ITU_T_IMPLICIT_TAG(reflectedParameter_, 1);
        ITU_T_EXPLICIT_TAG(userdataAB_, 2);
    }

    template<> void ARU_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abortReason_, 0);
        ITU_T_IMPLICIT_TAG(reflectedParameter_, 1);
        ITU_T_EXPLICIT_TAG(userdataAB_, 2);
    }

    template<> void ARU_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ARU_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(provider_reason_, 0);
        ITU_T_IMPLICIT_TAG(event_identifier_, 1);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(provider_reason_, 0);
        ITU_T_IMPLICIT_TAG(event_identifier_, 1);
    }

    template<> void Typed_data_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Typed_data_type_acPPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<AC_PPDU > (false, Typed_data_type_acPPDU), 0);
                break;
            }
            case Typed_data_type_acaPPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<ACA_PPDU > (false, Typed_data_type_acaPPDU), 1);
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
                        if (ITU_T_IMPLICIT_TAG(*value<AC_PPDU > (true, Typed_data_type_acPPDU), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ACA_PPDU > (true, Typed_data_type_acaPPDU), 1)) return;
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
                if (ITU_T_BIND_CHOICE(*value<User_data > (true, Typed_data_type_ttdPPDU))) return;
                else free();
            }
        }
    }

    template<> void AC_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void AC_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_result_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_result_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_result_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_result_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

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

    template<> void Default_context_name::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(*transfer_syntax_name_, 1);
    }

    template<> void Default_context_name::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(*transfer_syntax_name_, 1);
    }

    template<> void Mode_selector::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mode_value_, 0);
    }

    template<> void Mode_selector::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mode_value_, 0);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_TAG(*transfer_syntax_name_);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*presentation_context_identifier_);
        ITU_T_BIND_TAG(*transfer_syntax_name_);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*result_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*result_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    template<> void User_data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_data_simply_encoded_data:
            {
                ITU_T_IMPLICIT_APPLICATION_TAG(*value<Simply_encoded_data > (false, User_data_simply_encoded_data), 0);
                break;
            }
            case User_data_fully_encoded_data:
            {
                ITU_T_IMPLICIT_APPLICATION_TAG(*value<Fully_encoded_data > (false, User_data_fully_encoded_data), 1);
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
                        if (ITU_T_IMPLICIT_APPLICATION_TAG(*value<Simply_encoded_data > (true, User_data_simply_encoded_data), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_APPLICATION_TAG(*value<Fully_encoded_data > (true, User_data_fully_encoded_data), 1)) return;
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

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Presentation_data_values_type_single_ASN1_type:
            {
                ITU_T_EXPLICIT_TAG(*value<any_type > (false, Presentation_data_values_type_single_ASN1_type), 0);
                break;
            }
            case Presentation_data_values_type_octet_aligned:
            {
                ITU_T_IMPLICIT_TAG(*value<octetstring_type > (false, Presentation_data_values_type_octet_aligned), 1);
                break;
            }
            case Presentation_data_values_type_arbitrary:
            {
                ITU_T_IMPLICIT_TAG(*value<bitstring_type > (false, Presentation_data_values_type_arbitrary), 2);
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
                        if (ITU_T_EXPLICIT_TAG(*value<any_type > (true, Presentation_data_values_type_single_ASN1_type), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<octetstring_type > (true, Presentation_data_values_type_octet_aligned), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<bitstring_type > (true, Presentation_data_values_type_arbitrary), 2)) return;
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

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

