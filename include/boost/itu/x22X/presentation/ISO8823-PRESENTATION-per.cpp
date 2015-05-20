#include "ISO8823-PRESENTATION.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO8823_PRESENTATION {




    //  helper name:   Presentation_context_identifier           type:  struct of constrained int helper     //   Ic(  [ 1  ...   127 ]   ...ext...) 

    ITU_T_REGISTRATE_NUM_CONSTRE(Presentation_context_identifier__shelper, integer_type, (integer_type) (1), (integer_type) (127))

    template<> void CP_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(x410_mode_parameters_) + ITU_T_OPTIONAL_PER(normal_mode_parameters_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*mode_selector_);
        ITU_T_BIND_PER(x410_mode_parameters_);
        ITU_T_BIND_PER(normal_mode_parameters_);
    }

    template<> void CP_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_BIND_PER(*mode_selector_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(x410_mode_parameters_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(normal_mode_parameters_);
    }

    template<> void CP_type::X410_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(checkpointSize_) + ITU_T_OPTIONAL_PER(windowSize_) + ITU_T_OPTIONAL_PER(dialogueMode_) + ITU_T_OPTIONAL_PER(applicationProtocol_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(checkpointSize_);
        ITU_T_BIND_PER(windowSize_);
        ITU_T_BIND_PER(dialogueMode_);
        ITU_T_BIND_PER(*connectionDataRQ_);
        ITU_T_BIND_PER(applicationProtocol_);
    }

    template<> void CP_type::X410_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(4);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(checkpointSize_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(windowSize_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(dialogueMode_);
        ITU_T_BIND_PER(*connectionDataRQ_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(applicationProtocol_);
    }

    template<> void CP_type::Normal_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(protocol_version_) + ITU_T_OPTIONAL_PER(calling_presentation_selector_) + ITU_T_OPTIONAL_PER(called_presentation_selector_) + ITU_T_OPTIONAL_PER(presentation_context_definition_list_) + ITU_T_OPTIONAL_PER(default_context_name_) + ITU_T_OPTIONAL_PER(presentation_requirements_) + ITU_T_OPTIONAL_PER(user_session_requirements_) + ITU_T_OPTIONAL_PER(protocol_options_) + ITU_T_OPTIONAL_PER(initiators_nominated_context_) + ITU_T_OPTIONAL_PER(extensions_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_SIZE_CONSTRE(calling_presentation_selector_, 1, 4);
        ITU_T_BIND_SIZE_CONSTRE(called_presentation_selector_, 1, 4);
        ITU_T_BIND_SIZE_CONSTRE(presentation_context_definition_list_, 0, 7);
        ITU_T_BIND_PER(default_context_name_);
        ITU_T_BIND_PER(presentation_requirements_);
        ITU_T_BIND_PER(user_session_requirements_);
        ITU_T_BIND_PER(protocol_options_);
        ITU_T_BIND_NUM_CONSTRE(initiators_nominated_context_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(extensions_);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void CP_type::Normal_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(11);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_SIZE_CONSTRE(calling_presentation_selector_, 1, 4);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_SIZE_CONSTRE(called_presentation_selector_, 1, 4);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_SIZE_CONSTRE(presentation_context_definition_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(default_context_name_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(presentation_requirements_);
        ITU_T_OPTIONAL_CHECK_PER(6) ITU_T_BIND_PER(user_session_requirements_);
        ITU_T_OPTIONAL_CHECK_PER(7) ITU_T_BIND_PER(protocol_options_);
        ITU_T_OPTIONAL_CHECK_PER(8) ITU_T_BIND_NUM_CONSTRE(initiators_nominated_context_, (integer_type) (1), (integer_type) (127));
        ITU_T_OPTIONAL_CHECK_PER(9) ITU_T_BIND_PER(extensions_);
        ITU_T_OPTIONAL_CHECK_PER(10) ITU_T_BIND_PER(user_data_);
    }

    template<> void CP_type::Normal_mode_parameters_type::Extensions_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;
    }

    template<> void CP_type::Normal_mode_parameters_type::Extensions_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(x410_mode_parameters_) + ITU_T_OPTIONAL_PER(normal_mode_parameters_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*mode_selector_);
        ITU_T_BIND_PER(x410_mode_parameters_);
        ITU_T_BIND_PER(normal_mode_parameters_);
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_BIND_PER(*mode_selector_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(x410_mode_parameters_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(normal_mode_parameters_);
    }

    template<> void CPA_PPDU::X410_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(checkpointSize_) + ITU_T_OPTIONAL_PER(windowSize_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(checkpointSize_);
        ITU_T_BIND_PER(windowSize_);
        ITU_T_BIND_PER(*connectionDataAC_);
    }

    template<> void CPA_PPDU::X410_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(checkpointSize_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(windowSize_);
        ITU_T_BIND_PER(*connectionDataAC_);
    }

    template<> void CPA_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(protocol_version_) + ITU_T_OPTIONAL_PER(responding_presentation_selector_) + ITU_T_OPTIONAL_PER(presentation_context_definition_result_list_) + ITU_T_OPTIONAL_PER(presentation_requirements_) + ITU_T_OPTIONAL_PER(user_session_requirements_) + ITU_T_OPTIONAL_PER(protocol_options_) + ITU_T_OPTIONAL_PER(responders_nominated_context_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_SIZE_CONSTRE(responding_presentation_selector_, 1, 4);
        ITU_T_BIND_SIZE_CONSTRE(presentation_context_definition_result_list_, 0, 7);
        ITU_T_BIND_PER(presentation_requirements_);
        ITU_T_BIND_PER(user_session_requirements_);
        ITU_T_BIND_PER(protocol_options_);
        ITU_T_BIND_NUM_CONSTRE(responders_nominated_context_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(user_data_);
    }

    template<> void CPA_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(8);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_SIZE_CONSTRE(responding_presentation_selector_, 1, 4);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_SIZE_CONSTRE(presentation_context_definition_result_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(presentation_requirements_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(user_session_requirements_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(protocol_options_);
        ITU_T_OPTIONAL_CHECK_PER(6) ITU_T_BIND_NUM_CONSTRE(responders_nominated_context_, (integer_type) (1), (integer_type) (127));
        ITU_T_OPTIONAL_CHECK_PER(7) ITU_T_BIND_PER(user_data_);
    }

    template<> void CPR_PPDU::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CPR_PPDU_normal_mode_parameters:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Normal_mode_parameters_type > (false, CPR_PPDU_normal_mode_parameters));
                break;
            }
            case CPR_PPDU_x400_mode_parameters:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<X400_mode_parameters_type > (false, CPR_PPDU_x400_mode_parameters));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CPR_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Normal_mode_parameters_type > (true, CPR_PPDU_normal_mode_parameters));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<X400_mode_parameters_type > (true, CPR_PPDU_x400_mode_parameters));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CPR_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(refuseReason_) + ITU_T_OPTIONAL_PER(userDataRJ_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(refuseReason_);
        ITU_T_BIND_PER(userDataRJ_);
    }

    template<> void CPR_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(refuseReason_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(userDataRJ_);
    }

    template<> void CPR_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(protocol_version_) + ITU_T_OPTIONAL_PER(responding_presentation_selector_) + ITU_T_OPTIONAL_PER(presentation_context_definition_result_list_) + ITU_T_OPTIONAL_PER(default_context_result_) + ITU_T_OPTIONAL_PER(provider_reason_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_SIZE_CONSTRE(responding_presentation_selector_, 1, 4);
        ITU_T_BIND_SIZE_CONSTRE(presentation_context_definition_result_list_, 0, 7);
        ITU_T_BIND_PER(default_context_result_);
        ITU_T_BIND_PER(provider_reason_);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void CPR_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(6);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_SIZE_CONSTRE(responding_presentation_selector_, 1, 4);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_SIZE_CONSTRE(presentation_context_definition_result_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(default_context_result_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(provider_reason_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(user_data_);
    }

    template<> void Abort_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Abort_type_aru_ppdu:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ARU_PPDU > (false, Abort_type_aru_ppdu));
                break;
            }
            case Abort_type_arp_ppdu:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<ARP_PPDU > (false, Abort_type_arp_ppdu));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Abort_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ARU_PPDU > (true, Abort_type_aru_ppdu));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ARP_PPDU > (true, Abort_type_arp_ppdu));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ARU_PPDU_x400_mode_parameters:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<X400_mode_parameters_type > (false, ARU_PPDU_x400_mode_parameters));
                break;
            }
            case ARU_PPDU_normal_mode_parameters:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Normal_mode_parameters_type > (false, ARU_PPDU_normal_mode_parameters));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<X400_mode_parameters_type > (true, ARU_PPDU_x400_mode_parameters));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Normal_mode_parameters_type > (true, ARU_PPDU_normal_mode_parameters));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ARU_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(abortReason_) + ITU_T_OPTIONAL_PER(reflectedParameter_) + ITU_T_OPTIONAL_PER(userdataAB_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(abortReason_);
        ITU_T_BIND_PER(reflectedParameter_);
        ITU_T_BIND_PER(userdataAB_);
    }

    template<> void ARU_PPDU::X400_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(3);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(abortReason_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(reflectedParameter_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(userdataAB_);
    }

    template<> void ARU_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(presentation_context_identifier_list_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_SIZE_CONSTRE(presentation_context_identifier_list_, 0, 7);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void ARU_PPDU::Normal_mode_parameters_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_SIZE_CONSTRE(presentation_context_identifier_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(user_data_);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(provider_reason_) + ITU_T_OPTIONAL_PER(event_identifier_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(provider_reason_);
        ITU_T_BIND_PER(event_identifier_);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(provider_reason_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(event_identifier_);
    }

    template<> void Typed_data_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Typed_data_type_ttdPPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<User_data > (false, Typed_data_type_ttdPPDU));
                break;
            }
            case Typed_data_type_acPPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<AC_PPDU > (false, Typed_data_type_acPPDU));
                break;
            }
            case Typed_data_type_acaPPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<ACA_PPDU > (false, Typed_data_type_acaPPDU));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Typed_data_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<User_data > (true, Typed_data_type_ttdPPDU));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<AC_PPDU > (true, Typed_data_type_acPPDU));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<ACA_PPDU > (true, Typed_data_type_acaPPDU));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AC_PPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(presentation_context_addition_list_) + ITU_T_OPTIONAL_PER(presentation_context_deletion_list_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_SIZE_CONSTRE(presentation_context_addition_list_, 0, 7);
        ITU_T_BIND_SIZE_CONSTRE(presentation_context_deletion_list_, 0, 7);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void AC_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(3);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_SIZE_CONSTRE(presentation_context_addition_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_SIZE_CONSTRE(presentation_context_deletion_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(user_data_);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(presentation_context_addition_result_list_) + ITU_T_OPTIONAL_PER(presentation_context_deletion_result_list_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_SIZE_CONSTRE(presentation_context_addition_result_list_, 0, 7);
        ITU_T_BIND_SIZE_CONSTRE(presentation_context_deletion_result_list_, 0, 7);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(3);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_SIZE_CONSTRE(presentation_context_addition_result_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_SIZE_CONSTRE(presentation_context_deletion_result_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(user_data_);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(presentation_context_identifier_list_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_SIZE_CONSTRE(presentation_context_identifier_list_, 0, 7);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_SIZE_CONSTRE(presentation_context_identifier_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(user_data_);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(presentation_context_identifier_list_) + ITU_T_OPTIONAL_PER(user_data_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_SIZE_CONSTRE(presentation_context_identifier_list_, 0, 7);
        ITU_T_BIND_PER(user_data_);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_SIZE_CONSTRE(presentation_context_identifier_list_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(user_data_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRE(*presentation_context_identifier_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(*abstract_syntax_name_);
        ITU_T_BIND_PER(*transfer_syntax_name_list_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRE(*presentation_context_identifier_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(*abstract_syntax_name_);
        ITU_T_BIND_PER(*transfer_syntax_name_list_);
    }

    template<> void Default_context_name::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*abstract_syntax_name_);
        ITU_T_BIND_PER(*transfer_syntax_name_);
    }

    template<> void Default_context_name::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*abstract_syntax_name_);
        ITU_T_BIND_PER(*transfer_syntax_name_);
    }

    template<> void Mode_selector::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*mode_value_);
    }

    template<> void Mode_selector::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*mode_value_);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRE(*presentation_context_identifier_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(*transfer_syntax_name_);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRE(*presentation_context_identifier_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(*transfer_syntax_name_);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(transfer_syntax_name_) + ITU_T_OPTIONAL_PER(provider_reason_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*result_);
        ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_BIND_PER(provider_reason_);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_BIND_PER(*result_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(provider_reason_);
    }

    template<> void User_data::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;
        switch (type()) {
            case User_data_simply_encoded_data:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Simply_encoded_data > (false, User_data_simply_encoded_data));
                break;
            }
            case User_data_fully_encoded_data:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_SIZE_SNGLCONSTRE(*value<Fully_encoded_data > (false, User_data_fully_encoded_data), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_data::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Simply_encoded_data > (true, User_data_simply_encoded_data));
                break;
            }
            case 1:
            {
                ITU_T_BIND_SIZE_SNGLCONSTRE(*value<Fully_encoded_data > (true, User_data_fully_encoded_data), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void PDV_list::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(transfer_syntax_name_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_BIND_NUM_CONSTRE(*presentation_context_identifier_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(*presentation_data_values_);
    }

    template<> void PDV_list::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_BIND_NUM_CONSTRE(*presentation_context_identifier_, (integer_type) (1), (integer_type) (127));
        ITU_T_BIND_PER(*presentation_data_values_);
    }

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Presentation_data_values_type_single_ASN1_type:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<any_type > (false, Presentation_data_values_type_single_ASN1_type));
                break;
            }
            case Presentation_data_values_type_octet_aligned:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<octetstring_type > (false, Presentation_data_values_type_octet_aligned));
                break;
            }
            case Presentation_data_values_type_arbitrary:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<bitstring_type > (false, Presentation_data_values_type_arbitrary));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<any_type > (true, Presentation_data_values_type_single_ASN1_type));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<octetstring_type > (true, Presentation_data_values_type_octet_aligned));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<bitstring_type > (true, Presentation_data_values_type_arbitrary));
                break;
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

