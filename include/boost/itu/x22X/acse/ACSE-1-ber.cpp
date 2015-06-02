#include "ACSE-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {



    // choice ACSE-apdu

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

    // sequence AARQ-apdu

    template<> void AARQ_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*aSO_context_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(called_AP_title_, 2, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(called_AE_qualifier_, 3, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(called_AP_invocation_identifier_, 4, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(called_AE_invocation_identifier_, 5, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(calling_AP_title_, 6, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(calling_AE_qualifier_, 7, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(calling_AP_invocation_identifier_, 8, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(calling_AE_invocation_identifier_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(sender_acse_requirements_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(mechanism_name_, 11, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(calling_authentication_value_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_list_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(implementation_information_, 29, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(p_context_definition_list_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(called_asoi_tag_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(calling_asoi_tag_, 16, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void AARQ_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*aSO_context_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(called_AP_title_, 2, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(called_AE_qualifier_, 3, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(called_AP_invocation_identifier_, 4, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(called_AE_invocation_identifier_, 5, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(calling_AP_title_, 6, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(calling_AE_qualifier_, 7, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(calling_AP_invocation_identifier_, 8, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(calling_AE_invocation_identifier_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(sender_acse_requirements_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(mechanism_name_, 11, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(calling_authentication_value_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_list_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(implementation_information_, 29, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(p_context_definition_list_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(called_asoi_tag_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(calling_asoi_tag_, 16, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // sequence AARE-apdu

    template<> void AARE_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*aSO_context_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*result_, 2, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*result_source_diagnostic_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(responding_AP_title_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(responding_AE_qualifier_, 5, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(responding_AP_invocation_identifier_, 6, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(responding_AE_invocation_identifier_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(responder_acse_requirements_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(mechanism_name_, 9, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(responding_authentication_value_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_list_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(implementation_information_, 29, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(p_context_result_list_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(called_asoi_tag_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(calling_asoi_tag_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void AARE_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(protocol_version_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*aSO_context_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(*result_, 2, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*result_source_diagnostic_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(responding_AP_title_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(responding_AE_qualifier_, 5, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(responding_AP_invocation_identifier_, 6, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(responding_AE_invocation_identifier_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(responder_acse_requirements_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(mechanism_name_, 9, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(responding_authentication_value_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_list_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(implementation_information_, 29, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(p_context_result_list_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(called_asoi_tag_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(calling_asoi_tag_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // sequence RLRQ-apdu

    template<> void RLRQ_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(reason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void RLRQ_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(reason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // sequence RLRE-apdu

    template<> void RLRE_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(reason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void RLRE_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(reason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // sequence ABRT-apdu

    template<> void ABRT_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*abort_source_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(abort_diagnostic_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void ABRT_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*abort_source_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(abort_diagnostic_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // sequence A-DT-apdu

    template<> void A_DT_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*a_user_data_, 30, CONTEXT_CLASS);
    }

    template<> void A_DT_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*a_user_data_, 30, CONTEXT_CLASS);
    }

    // sequence ACRQ-apdu

    template<> void ACRQ_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_list_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(p_context_definition_list_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void ACRQ_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_list_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(p_context_definition_list_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // sequence ACRP-apdu

    template<> void ACRP_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(p_context_result_list_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    template<> void ACRP_apdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(aso_qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(asoi_identifier_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aSO_context_name_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(p_context_result_list_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(user_information_, 30, CONTEXT_CLASS);
    }

    // choice AP-title

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

        if (ITU_T_BIND_TAG(*value<AP_title_form1 > (true, AP_title_ap_title_form1))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<AP_title_form2 > (true, AP_title_ap_title_form2))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<AP_title_form3 > (true, AP_title_ap_title_form3))) return;
        else free();
    }

    // choice ASO-qualifier

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

        if (ITU_T_BIND_TAG(*value<ASO_qualifier_form1 > (true, ASO_qualifier_aso_qualifier_form1))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<ASO_qualifier_form2 > (true, ASO_qualifier_aso_qualifier_form2))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<ASO_qualifier_form3 > (true, ASO_qualifier_aso_qualifier_form3))) return;
        else free();
    }

    // choice AE-title

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

        if (ITU_T_BIND_TAG(*value<AE_title_form1 > (true, AE_title_ae_title_form1))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<AE_title_form2 > (true, AE_title_ae_title_form2))) return;
        else free();
    }

    // sequence 

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(identifier_, 1, CONTEXT_CLASS);
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(qualifier_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(identifier_, 1, CONTEXT_CLASS);
    }

    // choice Syntactic-context-list

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Syntactic_context_list_context_list:
            {
                ITU_T_BIND_EXPLICIT(*value<Context_list > (false, Syntactic_context_list_context_list), 0, CONTEXT_CLASS);
                break;
            }
            case Syntactic_context_list_default_contact_list:
            {
                ITU_T_BIND_EXPLICIT(*value<Default_Context_List > (false, Syntactic_context_list_default_contact_list), 1, CONTEXT_CLASS);
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
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<Context_list > (true, Syntactic_context_list_context_list), 0, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<Default_Context_List > (true, Syntactic_context_list_default_contact_list), 1, CONTEXT_CLASS)) return;
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

    // sequence 

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

    // sequence 

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(abstract_syntax_name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(*transfer_syntax_name_, 1, CONTEXT_CLASS);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(abstract_syntax_name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(*transfer_syntax_name_, 1, CONTEXT_CLASS);
    }

    // sequence 

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(*result_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(concrete_syntax_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(provider_reason_, 2, CONTEXT_CLASS);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(*result_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(concrete_syntax_name_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(provider_reason_, 2, CONTEXT_CLASS);
    }

    // choice Associate-source-diagnostic

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Associate_source_diagnostic_acse_service_user:
            {
                ITU_T_BIND_EXPLICIT(*value<integer_type > (false, Associate_source_diagnostic_acse_service_user), 1, CONTEXT_CLASS);
                break;
            }
            case Associate_source_diagnostic_acse_service_provider:
            {
                ITU_T_BIND_EXPLICIT(*value<integer_type > (false, Associate_source_diagnostic_acse_service_provider), 2, CONTEXT_CLASS);
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
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<integer_type > (true, Associate_source_diagnostic_acse_service_user), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<integer_type > (true, Associate_source_diagnostic_acse_service_provider), 2, CONTEXT_CLASS)) return;
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

    // choice User-Data

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
                ITU_T_BIND_EXPLICIT(*value<PDV_list > (false, User_Data_fully_encoded_data), 0, CONTEXT_CLASS);
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
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<PDV_list > (true, User_Data_fully_encoded_data), 0, CONTEXT_CLASS)) return;
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
                if (ITU_T_BIND_TAG(*value<User_information > (true, User_Data_user_information))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<Simply_encoded_data > (true, User_Data_simply_encoded_data))) return;
                else free();
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
            case Presentation_data_values_type_simple_ASN1_type:
            {
                ITU_T_BIND_EXPLICIT(*value<any_type > (false, Presentation_data_values_type_simple_ASN1_type), 0, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_EXPLICIT(*value<any_type > (true, Presentation_data_values_type_simple_ASN1_type), 0, CONTEXT_CLASS)) return;
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

    // choice Authentication-value

    template<> void Authentication_value::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Authentication_value_charstring:
            {
                ITU_T_BIND_IMPLICIT(*value<graphicstring_type > (false, Authentication_value_charstring), 0, CONTEXT_CLASS);
                break;
            }
            case Authentication_value_bitstring:
            {
                ITU_T_BIND_IMPLICIT(*value<bitstring_type > (false, Authentication_value_bitstring), 1, CONTEXT_CLASS);
                break;
            }
            case Authentication_value_external:
            {
                ITU_T_BIND_IMPLICIT(*value<external_type > (false, Authentication_value_external), 2, CONTEXT_CLASS);
                break;
            }
            case Authentication_value_other:
            {
                ITU_T_BIND_IMPLICIT(*value<Other_type > (false, Authentication_value_other), 3, CONTEXT_CLASS);
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
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<graphicstring_type > (true, Authentication_value_charstring), 0, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<bitstring_type > (true, Authentication_value_bitstring), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<external_type > (true, Authentication_value_external), 2, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<Other_type > (true, Authentication_value_other), 3, CONTEXT_CLASS)) return;
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

    // sequence other

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

