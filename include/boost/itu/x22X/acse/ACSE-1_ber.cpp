#include "ACSE-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {

    template<> void ACSE_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ACSE_apdu_aarq:
            {
                ITU_T_BIND_TAG(*value<AARQ_apdu > (false, ACSE_apdu_aarq));
                break;
            }
            case ACSE_apdu_aare:
            {
                ITU_T_BIND_TAG(*value<AARE_apdu > (false, ACSE_apdu_aare));
                break;
            }
            case ACSE_apdu_rlrq:
            {
                ITU_T_BIND_TAG(*value<RLRQ_apdu > (false, ACSE_apdu_rlrq));
                break;
            }
            case ACSE_apdu_rlre:
            {
                ITU_T_BIND_TAG(*value<RLRE_apdu > (false, ACSE_apdu_rlre));
                break;
            }
            case ACSE_apdu_abrt:
            {
                ITU_T_BIND_TAG(*value<ABRT_apdu > (false, ACSE_apdu_abrt));
                break;
            }
            case ACSE_apdu_adt:
            {
                ITU_T_BIND_TAG(*value<A_DT_apdu > (false, ACSE_apdu_adt));
                break;
            }
            case ACSE_apdu_acrq:
            {
                ITU_T_BIND_TAG(*value<ACRQ_apdu > (false, ACSE_apdu_acrq));
                break;
            }
            case ACSE_apdu_acrp:
            {
                ITU_T_BIND_TAG(*value<ACRP_apdu > (false, ACSE_apdu_acrp));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ACSE_apdu::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(*value<AARQ_apdu > (true, ACSE_apdu_aarq))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<AARE_apdu > (true, ACSE_apdu_aare))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<RLRQ_apdu > (true, ACSE_apdu_rlrq))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<RLRE_apdu > (true, ACSE_apdu_rlre))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<ABRT_apdu > (true, ACSE_apdu_abrt))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<A_DT_apdu > (true, ACSE_apdu_adt))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<ACRQ_apdu > (true, ACSE_apdu_acrq))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<ACRP_apdu > (true, ACSE_apdu_acrp))) return;
                else free();
            }
        }
    }

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(*aSO_context_name_, 1);
        ITU_T_CHOICE_TAG(called_AP_title_, 2);
        ITU_T_CHOICE_TAG(called_AE_qualifier_, 3);
        ITU_T_EXPLICIT_TAG(called_AP_invocation_identifier_, 4);
        ITU_T_EXPLICIT_TAG(called_AE_invocation_identifier_, 5);
        ITU_T_CHOICE_TAG(calling_AP_title_, 6);
        ITU_T_CHOICE_TAG(calling_AE_qualifier_, 7);
        ITU_T_EXPLICIT_TAG(calling_AP_invocation_identifier_, 8);
        ITU_T_EXPLICIT_TAG(calling_AE_invocation_identifier_, 9);
        ITU_T_IMPLICIT_TAG(sender_acse_requirements_, 10);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 11);
        ITU_T_CHOICE_TAG(calling_authentication_value_, 12);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 13);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 14);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 15);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 16);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(*aSO_context_name_, 1);
        ITU_T_CHOICE_TAG(called_AP_title_, 2);
        ITU_T_CHOICE_TAG(called_AE_qualifier_, 3);
        ITU_T_EXPLICIT_TAG(called_AP_invocation_identifier_, 4);
        ITU_T_EXPLICIT_TAG(called_AE_invocation_identifier_, 5);
        ITU_T_CHOICE_TAG(calling_AP_title_, 6);
        ITU_T_CHOICE_TAG(calling_AE_qualifier_, 7);
        ITU_T_EXPLICIT_TAG(calling_AP_invocation_identifier_, 8);
        ITU_T_EXPLICIT_TAG(calling_AE_invocation_identifier_, 9);
        ITU_T_IMPLICIT_TAG(sender_acse_requirements_, 10);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 11);
        ITU_T_CHOICE_TAG(calling_authentication_value_, 12);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 13);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 14);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 15);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 16);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(*aSO_context_name_, 1);
        ITU_T_EXPLICIT_TAG(*result_, 2);
        ITU_T_CHOICE_TAG(*result_source_diagnostic_, 3);
        ITU_T_CHOICE_TAG(responding_AP_title_, 4);
        ITU_T_CHOICE_TAG(responding_AE_qualifier_, 5);
        ITU_T_EXPLICIT_TAG(responding_AP_invocation_identifier_, 6);
        ITU_T_EXPLICIT_TAG(responding_AE_invocation_identifier_, 7);
        ITU_T_IMPLICIT_TAG(responder_acse_requirements_, 8);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 9);
        ITU_T_CHOICE_TAG(responding_authentication_value_, 10);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 11);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 12);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 13);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(*aSO_context_name_, 1);
        ITU_T_EXPLICIT_TAG(*result_, 2);
        ITU_T_CHOICE_TAG(*result_source_diagnostic_, 3);
        ITU_T_CHOICE_TAG(responding_AP_title_, 4);
        ITU_T_CHOICE_TAG(responding_AE_qualifier_, 5);
        ITU_T_EXPLICIT_TAG(responding_AP_invocation_identifier_, 6);
        ITU_T_EXPLICIT_TAG(responding_AE_invocation_identifier_, 7);
        ITU_T_IMPLICIT_TAG(responder_acse_requirements_, 8);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 9);
        ITU_T_CHOICE_TAG(responding_authentication_value_, 10);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 11);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 12);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 13);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*abort_source_, 0);
        ITU_T_IMPLICIT_TAG(abort_diagnostic_, 1);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*abort_source_, 0);
        ITU_T_IMPLICIT_TAG(abort_diagnostic_, 1);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_CHOICE_TAG(*a_user_data_, 30);
    }

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_CHOICE_TAG(*a_user_data_, 30);
    }

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 4);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 5);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 4);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 5);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 4);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 4);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void AP_title::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AP_title_ap_title_form1:
            {
                ITU_T_BIND_TAG(*value<AP_title_form1 > (false, AP_title_ap_title_form1));
                break;
            }
            case AP_title_ap_title_form2:
            {
                ITU_T_BIND_TAG(*value<AP_title_form2 > (false, AP_title_ap_title_form2));
                break;
            }
            case AP_title_ap_title_form3:
            {
                ITU_T_BIND_TAG(*value<AP_title_form3 > (false, AP_title_ap_title_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AP_title::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(*value<AP_title_form1 > (true, AP_title_ap_title_form1))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<AP_title_form2 > (true, AP_title_ap_title_form2))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<AP_title_form3 > (true, AP_title_ap_title_form3))) return;
                else free();
            }
        }
    }

    template<> void ASO_qualifier::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ASO_qualifier_aso_qualifier_form1:
            {
                ITU_T_BIND_TAG(*value<ASO_qualifier_form1 > (false, ASO_qualifier_aso_qualifier_form1));
                break;
            }
            case ASO_qualifier_aso_qualifier_form2:
            {
                ITU_T_BIND_TAG(*value<ASO_qualifier_form2 > (false, ASO_qualifier_aso_qualifier_form2));
                break;
            }
            case ASO_qualifier_aso_qualifier_form3:
            {
                ITU_T_BIND_TAG(*value<ASO_qualifier_form3 > (false, ASO_qualifier_aso_qualifier_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ASO_qualifier::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(*value<ASO_qualifier_form1 > (true, ASO_qualifier_aso_qualifier_form1))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<ASO_qualifier_form2 > (true, ASO_qualifier_aso_qualifier_form2))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<ASO_qualifier_form3 > (true, ASO_qualifier_aso_qualifier_form3))) return;
                else free();
            }
        }
    }

    template<> void AE_title::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AE_title_ae_title_form1:
            {
                ITU_T_BIND_TAG(*value<AE_title_form1 > (false, AE_title_ae_title_form1));
                break;
            }
            case AE_title_ae_title_form2:
            {
                ITU_T_BIND_TAG(*value<AE_title_form2 > (false, AE_title_ae_title_form2));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AE_title::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(*value<AE_title_form1 > (true, AE_title_ae_title_form1))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<AE_title_form2 > (true, AE_title_ae_title_form2))) return;
                else free();
            }
        }
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(qualifier_, 0);
        ITU_T_EXPLICIT_TAG(identifier_, 1);
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(qualifier_, 0);
        ITU_T_EXPLICIT_TAG(identifier_, 1);
    }

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Syntactic_context_list_context_list:
            {
                ITU_T_EXPLICIT_TAG(*value<Context_list > (false, Syntactic_context_list_context_list), 0);
                break;
            }
            case Syntactic_context_list_default_contact_list:
            {
                ITU_T_EXPLICIT_TAG(*value<Default_Context_List > (false, Syntactic_context_list_default_contact_list), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_EXPLICIT_TAG(*value<Context_list > (true, Syntactic_context_list_context_list), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<Default_Context_List > (true, Syntactic_context_list_default_contact_list), 1)) return;
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

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*pci_);
        ITU_T_BIND_TAG(*abstract_syntax_);
        ITU_T_BIND_TAG(*transfer_syntaxes_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*pci_);
        ITU_T_BIND_TAG(*abstract_syntax_);
        ITU_T_BIND_TAG(*transfer_syntaxes_);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(*transfer_syntax_name_, 1);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(*transfer_syntax_name_, 1);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*result_, 0);
        ITU_T_IMPLICIT_TAG(concrete_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*result_, 0);
        ITU_T_IMPLICIT_TAG(concrete_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Associate_source_diagnostic_acse_service_user:
            {
                ITU_T_EXPLICIT_TAG(*value<int > (false, Associate_source_diagnostic_acse_service_user), 1);
                break;
            }
            case Associate_source_diagnostic_acse_service_provider:
            {
                ITU_T_EXPLICIT_TAG(*value<int > (false, Associate_source_diagnostic_acse_service_provider), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<int > (true, Associate_source_diagnostic_acse_service_user), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<int > (true, Associate_source_diagnostic_acse_service_provider), 2)) return;
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

    template<> void User_Data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_Data_user_information:
            {
                ITU_T_BIND_TAG(*value<User_information > (false, User_Data_user_information));
                break;
            }
            case User_Data_simply_encoded_data:
            {
                ITU_T_BIND_TAG(*value<Simply_encoded_data > (false, User_Data_simply_encoded_data));
                break;
            }
            case User_Data_fully_encoded_data:
            {
                ITU_T_EXPLICIT_TAG(*value<PDV_list > (false, User_Data_fully_encoded_data), 0);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_Data::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_EXPLICIT_TAG(*value<PDV_list > (true, User_Data_fully_encoded_data), 0)) return;
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
                if (ITU_T_BIND_TAG(*value<User_information > (true, User_Data_user_information))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<Simply_encoded_data > (true, User_Data_simply_encoded_data))) return;
                else free();
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
            case Presentation_data_values_type_simple_ASN1_type:
            {
                ITU_T_EXPLICIT_TAG(*value<any_type > (false, Presentation_data_values_type_simple_ASN1_type), 0);
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
                        if (ITU_T_EXPLICIT_TAG(*value<any_type > (true, Presentation_data_values_type_simple_ASN1_type), 0)) return;
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

    template<> void Authentication_value::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Authentication_value_charstring:
            {
                ITU_T_IMPLICIT_TAG(*value<graphicstring_type > (false, Authentication_value_charstring), 0);
                break;
            }
            case Authentication_value_bitstring:
            {
                ITU_T_IMPLICIT_TAG(*value<bitstring_type > (false, Authentication_value_bitstring), 1);
                break;
            }
            case Authentication_value_external:
            {
                ITU_T_IMPLICIT_TAG(*value<external_type > (false, Authentication_value_external), 2);
                break;
            }
            case Authentication_value_other:
            {
                ITU_T_IMPLICIT_TAG(*value<Other_type > (false, Authentication_value_other), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Authentication_value::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<graphicstring_type > (true, Authentication_value_charstring), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<bitstring_type > (true, Authentication_value_bitstring), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<external_type > (true, Authentication_value_external), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Other_type > (true, Authentication_value_other), 3)) return;
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

    template<> void Authentication_value::Other_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*other_mechanism_name_);
        ITU_T_BIND_TAG(*other_mechanism_value_);
    }

    template<> void Authentication_value::Other_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*other_mechanism_name_);
        ITU_T_BIND_TAG(*other_mechanism_value_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

