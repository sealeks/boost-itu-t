#include "ACSE-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {




    //  helper name:   ABRT_diagnostic           type:  enumerated helper    
    ITU_T_PER_ENUMCODER_EXT(ABRT_diagnostic__helper, ITU_T_ARRAY(1, 2, 3, 4, 5, 6), ITU_T_ARRAY());

    template<> void ACSE_apdu::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ACSE_apdu_aarq:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 7);
                ITU_T_BIND_PER(*(*value<AARQ_apdu > (false, ACSE_apdu_aarq)));
                break;
            }
            case ACSE_apdu_aare:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 7);
                ITU_T_BIND_PER(*(*value<AARE_apdu > (false, ACSE_apdu_aare)));
                break;
            }
            case ACSE_apdu_rlrq:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 7);
                ITU_T_BIND_PER(*(*value<RLRQ_apdu > (false, ACSE_apdu_rlrq)));
                break;
            }
            case ACSE_apdu_rlre:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 7);
                ITU_T_BIND_PER(*(*value<RLRE_apdu > (false, ACSE_apdu_rlre)));
                break;
            }
            case ACSE_apdu_abrt:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 7);
                ITU_T_BIND_PER(*(*value<ABRT_apdu > (false, ACSE_apdu_abrt)));
                break;
            }
            case ACSE_apdu_adt:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 7);
                ITU_T_BIND_PER(*(*value<A_DT_apdu > (false, ACSE_apdu_adt)));
                break;
            }
            case ACSE_apdu_acrq:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 7);
                ITU_T_BIND_PER(*(*value<ACRQ_apdu > (false, ACSE_apdu_acrq)));
                break;
            }
            case ACSE_apdu_acrp:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 7);
                ITU_T_BIND_PER(*(*value<ACRP_apdu > (false, ACSE_apdu_acrp)));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ACSE_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(7);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*(*value<AARQ_apdu > (true, ACSE_apdu_aarq)));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*(*value<AARE_apdu > (true, ACSE_apdu_aare)));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*(*value<RLRQ_apdu > (true, ACSE_apdu_rlrq)));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*(*value<RLRE_apdu > (true, ACSE_apdu_rlre)));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*(*value<ABRT_apdu > (true, ACSE_apdu_abrt)));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*(*value<A_DT_apdu > (true, ACSE_apdu_adt)));
                break;
            }
            case 6:
            {
                ITU_T_BIND_PER(*(*value<ACRQ_apdu > (true, ACSE_apdu_acrq)));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(*(*value<ACRP_apdu > (true, ACSE_apdu_acrp)));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(protocol_version_) + ITU_T_OPTIONAL_PER(called_AP_title_) + ITU_T_OPTIONAL_PER(called_AE_qualifier_) + ITU_T_OPTIONAL_PER(called_AP_invocation_identifier_) + ITU_T_OPTIONAL_PER(called_AE_invocation_identifier_) + ITU_T_OPTIONAL_PER(calling_AP_title_) + ITU_T_OPTIONAL_PER(calling_AE_qualifier_) + ITU_T_OPTIONAL_PER(calling_AP_invocation_identifier_) + ITU_T_OPTIONAL_PER(calling_AE_invocation_identifier_) + ITU_T_OPTIONAL_PER(sender_acse_requirements_) + ITU_T_OPTIONAL_PER(mechanism_name_) + ITU_T_OPTIONAL_PER(calling_authentication_value_) + ITU_T_OPTIONAL_PER(aSO_context_name_list_) + ITU_T_OPTIONAL_PER(implementation_information_) + ITU_T_OPTIONAL_PER(p_context_definition_list_) + ITU_T_OPTIONAL_PER(called_asoi_tag_) + ITU_T_OPTIONAL_PER(calling_asoi_tag_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(*aSO_context_name_);
        ITU_T_BIND_PER(called_AP_title_);
        ITU_T_BIND_PER(called_AE_qualifier_);
        ITU_T_BIND_PER(called_AP_invocation_identifier_);
        ITU_T_BIND_PER(called_AE_invocation_identifier_);
        ITU_T_BIND_PER(calling_AP_title_);
        ITU_T_BIND_PER(calling_AE_qualifier_);
        ITU_T_BIND_PER(calling_AP_invocation_identifier_);
        ITU_T_BIND_PER(calling_AE_invocation_identifier_);
        ITU_T_BIND_PER(sender_acse_requirements_);
        ITU_T_BIND_PER(mechanism_name_);
        ITU_T_BIND_PER(calling_authentication_value_);
        ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_BIND_PER(implementation_information_);
        ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_BIND_SIZE_CONSTRE(called_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_CONSTRE(calling_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(18);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(*aSO_context_name_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(called_AP_title_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(called_AE_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(called_AP_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(called_AE_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(calling_AP_title_);
        ITU_T_OPTIONAL_CHECK_PER(6) ITU_T_BIND_PER(calling_AE_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(7) ITU_T_BIND_PER(calling_AP_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK_PER(8) ITU_T_BIND_PER(calling_AE_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK_PER(9) ITU_T_BIND_PER(sender_acse_requirements_);
        ITU_T_OPTIONAL_CHECK_PER(10) ITU_T_BIND_PER(mechanism_name_);
        ITU_T_OPTIONAL_CHECK_PER(11) ITU_T_BIND_PER(calling_authentication_value_);
        ITU_T_OPTIONAL_CHECK_PER(12) ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_OPTIONAL_CHECK_PER(13) ITU_T_BIND_PER(implementation_information_);
        ITU_T_OPTIONAL_CHECK_PER(14) ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_OPTIONAL_CHECK_PER(15) ITU_T_BIND_SIZE_CONSTRE(called_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(16) ITU_T_BIND_SIZE_CONSTRE(calling_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(17) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void AARE_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(protocol_version_) + ITU_T_OPTIONAL_PER(responding_AP_title_) + ITU_T_OPTIONAL_PER(responding_AE_qualifier_) + ITU_T_OPTIONAL_PER(responding_AP_invocation_identifier_) + ITU_T_OPTIONAL_PER(responding_AE_invocation_identifier_) + ITU_T_OPTIONAL_PER(responder_acse_requirements_) + ITU_T_OPTIONAL_PER(mechanism_name_) + ITU_T_OPTIONAL_PER(responding_authentication_value_) + ITU_T_OPTIONAL_PER(aSO_context_name_list_) + ITU_T_OPTIONAL_PER(implementation_information_) + ITU_T_OPTIONAL_PER(p_context_result_list_) + ITU_T_OPTIONAL_PER(called_asoi_tag_) + ITU_T_OPTIONAL_PER(calling_asoi_tag_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(*aSO_context_name_);
        ITU_T_BIND_NUM_CONSTRE(*result_, 0, 2);
        ITU_T_BIND_PER(*result_source_diagnostic_);
        ITU_T_BIND_PER(responding_AP_title_);
        ITU_T_BIND_PER(responding_AE_qualifier_);
        ITU_T_BIND_PER(responding_AP_invocation_identifier_);
        ITU_T_BIND_PER(responding_AE_invocation_identifier_);
        ITU_T_BIND_PER(responder_acse_requirements_);
        ITU_T_BIND_PER(mechanism_name_);
        ITU_T_BIND_PER(responding_authentication_value_);
        ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_BIND_PER(implementation_information_);
        ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_BIND_SIZE_CONSTRE(called_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_CONSTRE(calling_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void AARE_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(14);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(*aSO_context_name_);
        ITU_T_BIND_NUM_CONSTRE(*result_, 0, 2);
        ITU_T_BIND_PER(*result_source_diagnostic_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(responding_AP_title_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(responding_AE_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(responding_AP_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(responding_AE_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(responder_acse_requirements_);
        ITU_T_OPTIONAL_CHECK_PER(6) ITU_T_BIND_PER(mechanism_name_);
        ITU_T_OPTIONAL_CHECK_PER(7) ITU_T_BIND_PER(responding_authentication_value_);
        ITU_T_OPTIONAL_CHECK_PER(8) ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_OPTIONAL_CHECK_PER(9) ITU_T_BIND_PER(implementation_information_);
        ITU_T_OPTIONAL_CHECK_PER(10) ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_OPTIONAL_CHECK_PER(11) ITU_T_BIND_SIZE_CONSTRE(called_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(12) ITU_T_BIND_SIZE_CONSTRE(calling_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK_PER(13) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(reason_) + ITU_T_OPTIONAL_PER(aso_qualifier_) + ITU_T_OPTIONAL_PER(asoi_identifier_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_NUM_CONSTRE(reason_, 0, 30);
        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(4);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_NUM_CONSTRE(reason_, 0, 30);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(reason_) + ITU_T_OPTIONAL_PER(aso_qualifier_) + ITU_T_OPTIONAL_PER(asoi_identifier_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_NUM_CONSTRE(reason_, 0, 30);
        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(4);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_NUM_CONSTRE(reason_, 0, 30);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(abort_diagnostic_) + ITU_T_OPTIONAL_PER(aso_qualifier_) + ITU_T_OPTIONAL_PER(asoi_identifier_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_NUM_CONSTRE(*abort_source_, 0, 1);
        ITU_T_BIND_PER_ENUM(abort_diagnostic_, ABRT_diagnostic__helper);
        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(4);

        ITU_T_BIND_NUM_CONSTRE(*abort_source_, 0, 1);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER_ENUM(abort_diagnostic_, ABRT_diagnostic__helper);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(aso_qualifier_) + ITU_T_OPTIONAL_PER(asoi_identifier_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_PER(*a_user_data_);
    }

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_PER(*a_user_data_);
    }

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(aso_qualifier_) + ITU_T_OPTIONAL_PER(asoi_identifier_) + ITU_T_OPTIONAL_PER(aSO_context_name_) + ITU_T_OPTIONAL_PER(aSO_context_name_list_) + ITU_T_OPTIONAL_PER(p_context_definition_list_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(6);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(aso_qualifier_) + ITU_T_OPTIONAL_PER(asoi_identifier_) + ITU_T_OPTIONAL_PER(aSO_context_name_) + ITU_T_OPTIONAL_PER(p_context_result_list_) + ITU_T_OPTIONAL_PER(user_information_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(5);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_NUM_CONSTRE(asoi_identifier_, 1, 128);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_SIZE_SNGLCONSTRE(user_information_, 1);
    }

    template<> void AP_title::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AP_title_ap_title_form1:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<AP_title_form1 > (false, AP_title_ap_title_form1));
                break;
            }
            case AP_title_ap_title_form2:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<AP_title_form2 > (false, AP_title_ap_title_form2));
                break;
            }
            case AP_title_ap_title_form3:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<AP_title_form3 > (false, AP_title_ap_title_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AP_title::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<AP_title_form1 > (true, AP_title_ap_title_form1));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<AP_title_form2 > (true, AP_title_ap_title_form2));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<AP_title_form3 > (true, AP_title_ap_title_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ASO_qualifier::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ASO_qualifier_aso_qualifier_form2:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<ASO_qualifier_form2 > (false, ASO_qualifier_aso_qualifier_form2));
                break;
            }
            case ASO_qualifier_aso_qualifier_form1:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<ASO_qualifier_form1 > (false, ASO_qualifier_aso_qualifier_form1));
                break;
            }
            case ASO_qualifier_aso_qualifier_form3:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<ASO_qualifier_form3 > (false, ASO_qualifier_aso_qualifier_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ASO_qualifier::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ASO_qualifier_form2 > (true, ASO_qualifier_aso_qualifier_form2));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ASO_qualifier_form1 > (true, ASO_qualifier_aso_qualifier_form1));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<ASO_qualifier_form3 > (true, ASO_qualifier_aso_qualifier_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AE_title::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AE_title_ae_title_form1:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<AE_title_form1 > (false, AE_title_ae_title_form1));
                break;
            }
            case AE_title_ae_title_form2:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<AE_title_form2 > (false, AE_title_ae_title_form2));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AE_title::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<AE_title_form1 > (true, AE_title_ae_title_form1));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<AE_title_form2 > (true, AE_title_ae_title_form2));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(qualifier_) + ITU_T_OPTIONAL_PER(identifier_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(qualifier_);
        ITU_T_BIND_NUM_CONSTRE(identifier_, 1, 128);
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_NUM_CONSTRE(identifier_, 1, 128);
    }

    template<> void Syntactic_context_list::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Syntactic_context_list_context_list:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Context_list > (false, Syntactic_context_list_context_list));
                break;
            }
            case Syntactic_context_list_default_contact_list:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Default_Context_List > (false, Syntactic_context_list_default_contact_list));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Syntactic_context_list::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Context_list > (true, Syntactic_context_list_context_list));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Default_Context_List > (true, Syntactic_context_list_default_contact_list));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*pci_);
        ITU_T_BIND_PER(*abstract_syntax_);
        ITU_T_BIND_PER(*transfer_syntaxes_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*pci_);
        ITU_T_BIND_PER(*abstract_syntax_);
        ITU_T_BIND_PER(*transfer_syntaxes_);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(abstract_syntax_name_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(abstract_syntax_name_);
        ITU_T_BIND_PER(*transfer_syntax_name_);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(abstract_syntax_name_);
        ITU_T_BIND_PER(*transfer_syntax_name_);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(concrete_syntax_name_) + ITU_T_OPTIONAL_PER(provider_reason_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*result_);
        ITU_T_BIND_PER(concrete_syntax_name_);
        ITU_T_BIND_PER(provider_reason_);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_BIND_PER(*result_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(concrete_syntax_name_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(provider_reason_);
    }

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Associate_source_diagnostic_acse_service_user:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_NUM_CONSTRE(*value<int > (false, Associate_source_diagnostic_acse_service_user), 0, 14);
                break;
            }
            case Associate_source_diagnostic_acse_service_provider:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_NUM_CONSTRE(*value<int > (false, Associate_source_diagnostic_acse_service_provider), 0, 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRE(*value<int > (true, Associate_source_diagnostic_acse_service_user), 0, 14);
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRE(*value<int > (true, Associate_source_diagnostic_acse_service_provider), 0, 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_Data::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case User_Data_simply_encoded_data:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Simply_encoded_data > (false, User_Data_simply_encoded_data));
                break;
            }
            case User_Data_user_information:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_SIZE_SNGLCONSTRE(*value<User_information > (false, User_Data_user_information), 1);
                break;
            }
            case User_Data_fully_encoded_data:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<PDV_list > (false, User_Data_fully_encoded_data));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_Data::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Simply_encoded_data > (true, User_Data_simply_encoded_data));
                break;
            }
            case 1:
            {
                ITU_T_BIND_SIZE_SNGLCONSTRE(*value<User_information > (true, User_Data_user_information), 1);
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<PDV_list > (true, User_Data_fully_encoded_data));
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
        ITU_T_BIND_PER(*presentation_context_identifier_);
        ITU_T_BIND_PER(*presentation_data_values_);
    }

    template<> void PDV_list::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_BIND_PER(*presentation_context_identifier_);
        ITU_T_BIND_PER(*presentation_data_values_);
    }

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Presentation_data_values_type_simple_ASN1_type:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<any_type > (false, Presentation_data_values_type_simple_ASN1_type));
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
                ITU_T_BIND_PER(*value<any_type > (true, Presentation_data_values_type_simple_ASN1_type));
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

    template<> void Authentication_value::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Authentication_value_charstring:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<graphicstring_type > (false, Authentication_value_charstring));
                break;
            }
            case Authentication_value_bitstring:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(*value<bitstring_type > (false, Authentication_value_bitstring));
                break;
            }
            case Authentication_value_external:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<external_type > (false, Authentication_value_external));
                break;
            }
            case Authentication_value_other:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<Other_type > (false, Authentication_value_other));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Authentication_value::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<graphicstring_type > (true, Authentication_value_charstring));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<bitstring_type > (true, Authentication_value_bitstring));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<external_type > (true, Authentication_value_external));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<Other_type > (true, Authentication_value_other));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Authentication_value::Other_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*other_mechanism_name_);
        ITU_T_BIND_PER(*other_mechanism_value_);
    }

    template<> void Authentication_value::Other_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*other_mechanism_name_);
        ITU_T_BIND_PER(*other_mechanism_value_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

