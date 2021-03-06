#include "ACSE-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {




    //  helper name:   ABRT_diagnostic           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(ABRT_diagnostic__helper, true, ITU_T_ARRAY(1, 2, 3, 4, 5, 6));

    // choice ACSE-apdu

    template<> void ACSE_apdu::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ACSE_apdu_aarq:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 7);
                ITU_T_BIND_PER(value<AARQ_apdu > (false, ACSE_apdu_aarq));
                break;
            }
            case ACSE_apdu_aare:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 7);
                ITU_T_BIND_PER(value<AARE_apdu > (false, ACSE_apdu_aare));
                break;
            }
            case ACSE_apdu_rlrq:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 7);
                ITU_T_BIND_PER(value<RLRQ_apdu > (false, ACSE_apdu_rlrq));
                break;
            }
            case ACSE_apdu_rlre:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 7);
                ITU_T_BIND_PER(value<RLRE_apdu > (false, ACSE_apdu_rlre));
                break;
            }
            case ACSE_apdu_abrt:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 7);
                ITU_T_BIND_PER(value<ABRT_apdu > (false, ACSE_apdu_abrt));
                break;
            }
            case ACSE_apdu_adt:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 7);
                ITU_T_BIND_PER(value<A_DT_apdu > (false, ACSE_apdu_adt));
                break;
            }
            case ACSE_apdu_acrq:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 7);
                ITU_T_BIND_PER(value<ACRQ_apdu > (false, ACSE_apdu_acrq));
                break;
            }
            case ACSE_apdu_acrp:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 7);
                ITU_T_BIND_PER(value<ACRP_apdu > (false, ACSE_apdu_acrp));
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
                ITU_T_BIND_PER(value<AARQ_apdu > (true, ACSE_apdu_aarq));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<AARE_apdu > (true, ACSE_apdu_aare));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<RLRQ_apdu > (true, ACSE_apdu_rlrq));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(value<RLRE_apdu > (true, ACSE_apdu_rlre));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(value<ABRT_apdu > (true, ACSE_apdu_abrt));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(value<A_DT_apdu > (true, ACSE_apdu_adt));
                break;
            }
            case 6:
            {
                ITU_T_BIND_PER(value<ACRQ_apdu > (true, ACSE_apdu_acrq));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(value<ACRP_apdu > (true, ACSE_apdu_acrp));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence AARQ-apdu

    template<> void AARQ_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(protocol_version_) +
                ITU_T_EXISTS_BMP(called_AP_title_) +
                ITU_T_EXISTS_BMP(called_AE_qualifier_) +
                ITU_T_EXISTS_BMP(called_AP_invocation_identifier_) +
                ITU_T_EXISTS_BMP(called_AE_invocation_identifier_) +
                ITU_T_EXISTS_BMP(calling_AP_title_) +
                ITU_T_EXISTS_BMP(calling_AE_qualifier_) +
                ITU_T_EXISTS_BMP(calling_AP_invocation_identifier_) +
                ITU_T_EXISTS_BMP(calling_AE_invocation_identifier_) +
                ITU_T_EXISTS_BMP(sender_acse_requirements_) +
                ITU_T_EXISTS_BMP(mechanism_name_) +
                ITU_T_EXISTS_BMP(calling_authentication_value_) +
                ITU_T_EXISTS_BMP(aSO_context_name_list_) +
                ITU_T_EXISTS_BMP(implementation_information_) +
                ITU_T_EXISTS_BMP(p_context_definition_list_) +
                ITU_T_EXISTS_BMP(called_asoi_tag_) +
                ITU_T_EXISTS_BMP(calling_asoi_tag_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(aSO_context_name_);
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
        ITU_T_BIND_SIZE_CONSTRAINT_EXT(called_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_CONSTRAINT_EXT(calling_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void AARQ_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(18);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(called_AP_title_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(called_AE_qualifier_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(called_AP_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(called_AE_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(calling_AP_title_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(calling_AE_qualifier_);
        ITU_T_OPTIONAL_CHECK(7) ITU_T_BIND_PER(calling_AP_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK(8) ITU_T_BIND_PER(calling_AE_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK(9) ITU_T_BIND_PER(sender_acse_requirements_);
        ITU_T_OPTIONAL_CHECK(10) ITU_T_BIND_PER(mechanism_name_);
        ITU_T_OPTIONAL_CHECK(11) ITU_T_BIND_PER(calling_authentication_value_);
        ITU_T_OPTIONAL_CHECK(12) ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_OPTIONAL_CHECK(13) ITU_T_BIND_PER(implementation_information_);
        ITU_T_OPTIONAL_CHECK(14) ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_OPTIONAL_CHECK(15) ITU_T_BIND_SIZE_CONSTRAINT_EXT(called_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK(16) ITU_T_BIND_SIZE_CONSTRAINT_EXT(calling_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK(17) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // sequence AARE-apdu

    template<> void AARE_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(protocol_version_) +
                ITU_T_EXISTS_BMP(responding_AP_title_) +
                ITU_T_EXISTS_BMP(responding_AE_qualifier_) +
                ITU_T_EXISTS_BMP(responding_AP_invocation_identifier_) +
                ITU_T_EXISTS_BMP(responding_AE_invocation_identifier_) +
                ITU_T_EXISTS_BMP(responder_acse_requirements_) +
                ITU_T_EXISTS_BMP(mechanism_name_) +
                ITU_T_EXISTS_BMP(responding_authentication_value_) +
                ITU_T_EXISTS_BMP(aSO_context_name_list_) +
                ITU_T_EXISTS_BMP(implementation_information_) +
                ITU_T_EXISTS_BMP(p_context_result_list_) +
                ITU_T_EXISTS_BMP(called_asoi_tag_) +
                ITU_T_EXISTS_BMP(calling_asoi_tag_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(result_, static_cast<integer_type> (0), static_cast<integer_type> (2));
        ITU_T_BIND_PER(result_source_diagnostic_);
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
        ITU_T_BIND_SIZE_CONSTRAINT_EXT(called_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_CONSTRAINT_EXT(calling_asoi_tag_, 0, 7);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void AARE_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(14);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(protocol_version_);
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(result_, static_cast<integer_type> (0), static_cast<integer_type> (2));
        ITU_T_BIND_PER(result_source_diagnostic_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(responding_AP_title_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(responding_AE_qualifier_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(responding_AP_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(responding_AE_invocation_identifier_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(responder_acse_requirements_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(mechanism_name_);
        ITU_T_OPTIONAL_CHECK(7) ITU_T_BIND_PER(responding_authentication_value_);
        ITU_T_OPTIONAL_CHECK(8) ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_OPTIONAL_CHECK(9) ITU_T_BIND_PER(implementation_information_);
        ITU_T_OPTIONAL_CHECK(10) ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_OPTIONAL_CHECK(11) ITU_T_BIND_SIZE_CONSTRAINT_EXT(called_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK(12) ITU_T_BIND_SIZE_CONSTRAINT_EXT(calling_asoi_tag_, 0, 7);
        ITU_T_OPTIONAL_CHECK(13) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // sequence RLRQ-apdu

    template<> void RLRQ_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(reason_) +
                ITU_T_EXISTS_BMP(aso_qualifier_) +
                ITU_T_EXISTS_BMP(asoi_identifier_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRAINT_EXT(reason_, static_cast<integer_type> (0), static_cast<integer_type> (30));
        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void RLRQ_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRAINT_EXT(reason_, static_cast<integer_type> (0), static_cast<integer_type> (30));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // sequence RLRE-apdu

    template<> void RLRE_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(reason_) +
                ITU_T_EXISTS_BMP(aso_qualifier_) +
                ITU_T_EXISTS_BMP(asoi_identifier_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRAINT_EXT(reason_, static_cast<integer_type> (0), static_cast<integer_type> (30));
        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void RLRE_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRAINT_EXT(reason_, static_cast<integer_type> (0), static_cast<integer_type> (30));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // sequence ABRT-apdu

    template<> void ABRT_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(abort_diagnostic_) +
                ITU_T_EXISTS_BMP(aso_qualifier_) +
                ITU_T_EXISTS_BMP(asoi_identifier_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRAINT_EXT(abort_source_, static_cast<integer_type> (0), static_cast<integer_type> (1));
        ITU_T_BIND_PER_ENUM(abort_diagnostic_, ABRT_diagnostic__helper);
        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void ABRT_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_BIND_NUM_CONSTRAINT_EXT(abort_source_, static_cast<integer_type> (0), static_cast<integer_type> (1));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER_ENUM(abort_diagnostic_, ABRT_diagnostic__helper);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // sequence A-DT-apdu

    template<> void A_DT_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(aso_qualifier_) +
                ITU_T_EXISTS_BMP(asoi_identifier_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_PER(a_user_data_);
    }

    template<> void A_DT_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_PER(a_user_data_);
    }

    // sequence ACRQ-apdu

    template<> void ACRQ_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(aso_qualifier_) +
                ITU_T_EXISTS_BMP(asoi_identifier_) +
                ITU_T_EXISTS_BMP(aSO_context_name_) +
                ITU_T_EXISTS_BMP(aSO_context_name_list_) +
                ITU_T_EXISTS_BMP(p_context_definition_list_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void ACRQ_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(6);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(aSO_context_name_list_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(p_context_definition_list_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // sequence ACRP-apdu

    template<> void ACRP_apdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(aso_qualifier_) +
                ITU_T_EXISTS_BMP(asoi_identifier_) +
                ITU_T_EXISTS_BMP(aSO_context_name_) +
                ITU_T_EXISTS_BMP(p_context_result_list_) +
                ITU_T_EXISTS_BMP(user_information_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    template<> void ACRP_apdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(5);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(aso_qualifier_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRAINT_EXT(asoi_identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(aSO_context_name_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(p_context_result_list_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(user_information_, 1);
    }

    // choice AP-title

    template<> void AP_title::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AP_title_ap_title_form1:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<AP_title_form1 > (false, AP_title_ap_title_form1));
                break;
            }
            case AP_title_ap_title_form2:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(value<AP_title_form2 > (false, AP_title_ap_title_form2));
                break;
            }
            case AP_title_ap_title_form3:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<AP_title_form3 > (false, AP_title_ap_title_form3));
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
                ITU_T_BIND_PER(value<AP_title_form1 > (true, AP_title_ap_title_form1));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<AP_title_form2 > (true, AP_title_ap_title_form2));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<AP_title_form3 > (true, AP_title_ap_title_form3));
                break;
            }
            default:
            {
            }
        }
    }

    // choice ASO-qualifier

    template<> void ASO_qualifier::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ASO_qualifier_aso_qualifier_form2:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<ASO_qualifier_form2 > (false, ASO_qualifier_aso_qualifier_form2));
                break;
            }
            case ASO_qualifier_aso_qualifier_form1:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(value<ASO_qualifier_form1 > (false, ASO_qualifier_aso_qualifier_form1));
                break;
            }
            case ASO_qualifier_aso_qualifier_form3:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<ASO_qualifier_form3 > (false, ASO_qualifier_aso_qualifier_form3));
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
                ITU_T_BIND_PER(value<ASO_qualifier_form2 > (true, ASO_qualifier_aso_qualifier_form2));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<ASO_qualifier_form1 > (true, ASO_qualifier_aso_qualifier_form1));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<ASO_qualifier_form3 > (true, ASO_qualifier_aso_qualifier_form3));
                break;
            }
            default:
            {
            }
        }
    }

    // choice AE-title

    template<> void AE_title::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AE_title_ae_title_form1:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<AE_title_form1 > (false, AE_title_ae_title_form1));
                break;
            }
            case AE_title_ae_title_form2:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<AE_title_form2 > (false, AE_title_ae_title_form2));
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
                ITU_T_BIND_PER(value<AE_title_form1 > (true, AE_title_ae_title_form1));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<AE_title_form2 > (true, AE_title_ae_title_form2));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence 

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(qualifier_) +
                ITU_T_EXISTS_BMP(identifier_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(qualifier_);
        ITU_T_BIND_NUM_CONSTRAINT_EXT(identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(qualifier_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRAINT_EXT(identifier_, static_cast<integer_type> (1), static_cast<integer_type> (128));
    }

    // choice Syntactic-context-list

    template<> void Syntactic_context_list::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Syntactic_context_list_context_list:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<Context_list > (false, Syntactic_context_list_context_list));
                break;
            }
            case Syntactic_context_list_default_contact_list:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Default_Context_List > (false, Syntactic_context_list_default_contact_list));
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
                ITU_T_BIND_PER(value<Context_list > (true, Syntactic_context_list_context_list));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Default_Context_List > (true, Syntactic_context_list_default_contact_list));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence 

    template<> void Context_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(pci_);
        ITU_T_BIND_PER(abstract_syntax_);
        ITU_T_BIND_PER(transfer_syntaxes_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(pci_);
        ITU_T_BIND_PER(abstract_syntax_);
        ITU_T_BIND_PER(transfer_syntaxes_);
    }

    // sequence 

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(abstract_syntax_name_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(abstract_syntax_name_);
        ITU_T_BIND_PER(transfer_syntax_name_);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(abstract_syntax_name_);
        ITU_T_BIND_PER(transfer_syntax_name_);
    }

    // sequence 

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(concrete_syntax_name_) +
                ITU_T_EXISTS_BMP(provider_reason_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(result_);
        ITU_T_BIND_PER(concrete_syntax_name_);
        ITU_T_BIND_PER(provider_reason_);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(result_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(concrete_syntax_name_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(provider_reason_);
    }

    // choice Associate-source-diagnostic

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Associate_source_diagnostic_acse_service_user:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_NUM_CONSTRAINT_EXT(value<integer_type > (false, Associate_source_diagnostic_acse_service_user), static_cast<integer_type> (0), static_cast<integer_type> (14));
                break;
            }
            case Associate_source_diagnostic_acse_service_provider:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_NUM_CONSTRAINT_EXT(value<integer_type > (false, Associate_source_diagnostic_acse_service_provider), static_cast<integer_type> (0), static_cast<integer_type> (2));
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
                ITU_T_BIND_NUM_CONSTRAINT_EXT(value<integer_type > (true, Associate_source_diagnostic_acse_service_user), static_cast<integer_type> (0), static_cast<integer_type> (14));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRAINT_EXT(value<integer_type > (true, Associate_source_diagnostic_acse_service_provider), static_cast<integer_type> (0), static_cast<integer_type> (2));
                break;
            }
            default:
            {
            }
        }
    }

    // choice User-Data

    template<> void User_Data::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case User_Data_simply_encoded_data:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<Simply_encoded_data > (false, User_Data_simply_encoded_data));
                break;
            }
            case User_Data_user_information:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(value<User_information > (false, User_Data_user_information), 1);
                break;
            }
            case User_Data_fully_encoded_data:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<PDV_list > (false, User_Data_fully_encoded_data));
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
                ITU_T_BIND_PER(value<Simply_encoded_data > (true, User_Data_simply_encoded_data));
                break;
            }
            case 1:
            {
                ITU_T_BIND_SIZE_SNGLCONSTRAINT_EXT(value<User_information > (true, User_Data_user_information), 1);
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<PDV_list > (true, User_Data_fully_encoded_data));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence PDV-list

    template<> void PDV_list::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(transfer_syntax_name_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_BIND_PER(presentation_context_identifier_);
        ITU_T_BIND_PER(presentation_data_values_);
    }

    template<> void PDV_list::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(transfer_syntax_name_);
        ITU_T_BIND_PER(presentation_context_identifier_);
        ITU_T_BIND_PER(presentation_data_values_);
    }

    // choice presentation-data-values

    template<> void PDV_list::Presentation_data_values_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Presentation_data_values_type_simple_ASN1_type:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<any_type > (false, Presentation_data_values_type_simple_ASN1_type));
                break;
            }
            case Presentation_data_values_type_octet_aligned:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(value<octet_string > (false, Presentation_data_values_type_octet_aligned));
                break;
            }
            case Presentation_data_values_type_arbitrary:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<bit_string > (false, Presentation_data_values_type_arbitrary));
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
                ITU_T_BIND_PER(value<any_type > (true, Presentation_data_values_type_simple_ASN1_type));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<octet_string > (true, Presentation_data_values_type_octet_aligned));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<bit_string > (true, Presentation_data_values_type_arbitrary));
                break;
            }
            default:
            {
            }
        }
    }

    // choice Authentication-value

    template<> void Authentication_value::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Authentication_value_charstring:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(value<graphic_string > (false, Authentication_value_charstring));
                break;
            }
            case Authentication_value_bitstring:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(value<bit_string > (false, Authentication_value_bitstring));
                break;
            }
            case Authentication_value_external:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(value<external_type > (false, Authentication_value_external));
                break;
            }
            case Authentication_value_other:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(value<Other_type > (false, Authentication_value_other));
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
                ITU_T_BIND_PER(value<graphic_string > (true, Authentication_value_charstring));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<bit_string > (true, Authentication_value_bitstring));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<external_type > (true, Authentication_value_external));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(value<Other_type > (true, Authentication_value_other));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence other

    template<> void Authentication_value::Other_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(other_mechanism_name_);
        ITU_T_BIND_PER(other_mechanism_value_);
    }

    template<> void Authentication_value::Other_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(other_mechanism_name_);
        ITU_T_BIND_PER(other_mechanism_value_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

