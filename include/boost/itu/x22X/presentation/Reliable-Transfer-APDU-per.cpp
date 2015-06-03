#include "Reliable-Transfer-APDU.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {



    // choice RTSE-apdus

    template<> void RTSE_apdus::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RTSE_apdus_rttp_apdu:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 5);
                ITU_T_BIND_PER(*value<RTTPapdu > (false, RTSE_apdus_rttp_apdu));
                break;
            }
            case RTSE_apdus_rttr_apdu:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 5);
                ITU_T_BIND_PER(*value<RTTRapdu > (false, RTSE_apdus_rttr_apdu));
                break;
            }
            case RTSE_apdus_rtorq_apdu:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 5);
                ITU_T_BIND_PER(*value<RTORQapdu > (false, RTSE_apdus_rtorq_apdu));
                break;
            }
            case RTSE_apdus_rtoac_apdu:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 5);
                ITU_T_BIND_PER(*value<RTOACapdu > (false, RTSE_apdus_rtoac_apdu));
                break;
            }
            case RTSE_apdus_rtorj_apdu:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 5);
                ITU_T_BIND_PER(*value<RTORJapdu > (false, RTSE_apdus_rtorj_apdu));
                break;
            }
            case RTSE_apdus_rtab_apdu:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 5);
                ITU_T_BIND_PER(*value<RTABapdu > (false, RTSE_apdus_rtab_apdu));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RTSE_apdus::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(5);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<RTTPapdu > (true, RTSE_apdus_rttp_apdu));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<RTTRapdu > (true, RTSE_apdus_rttr_apdu));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<RTORQapdu > (true, RTSE_apdus_rtorq_apdu));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<RTOACapdu > (true, RTSE_apdus_rtoac_apdu));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<RTORJapdu > (true, RTSE_apdus_rtorj_apdu));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*value<RTABapdu > (true, RTSE_apdus_rtab_apdu));
                break;
            }
            default:
            {
            }
        }
    }

    // set  RTORQapdu

    template<> void RTORQapdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(checkpointSize_) +
                ITU_T_EXISTS_BMP(windowSize_) +
                ITU_T_EXISTS_BMP(dialogueMode_) +
                ITU_T_EXISTS_BMP(applicationProtocol_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(checkpointSize_);
        ITU_T_BIND_PER(windowSize_);
        ITU_T_BIND_PER(dialogueMode_);
        ITU_T_BIND_PER(*connectionDataRQ_);
        ITU_T_BIND_PER(applicationProtocol_);
    }

    template<> void RTORQapdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(checkpointSize_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(windowSize_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(dialogueMode_);
        ITU_T_BIND_PER(*connectionDataRQ_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(applicationProtocol_);
    }

    // set  RTOACapdu

    template<> void RTOACapdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(checkpointSize_) +
                ITU_T_EXISTS_BMP(windowSize_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(checkpointSize_);
        ITU_T_BIND_PER(windowSize_);
        ITU_T_BIND_PER(*connectionDataAC_);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(checkpointSize_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(windowSize_);
        ITU_T_BIND_PER(*connectionDataAC_);
    }

    // set  RTORJapdu

    template<> void RTORJapdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(refuseReason_) +
                ITU_T_EXISTS_BMP(userDataRJ_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(refuseReason_);
        ITU_T_BIND_PER(userDataRJ_);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(refuseReason_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(userDataRJ_);
    }

    // set  RTABapdu

    template<> void RTABapdu::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(abortReason_) +
                ITU_T_EXISTS_BMP(reflectedParameter_) +
                ITU_T_EXISTS_BMP(userdataAB_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(abortReason_);
        ITU_T_BIND_PER(reflectedParameter_);
        ITU_T_BIND_PER(userdataAB_);
    }

    template<> void RTABapdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(abortReason_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(reflectedParameter_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(userdataAB_);
    }

    // choice ConnectionData

    template<> void ConnectionData::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ConnectionData_open:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<any_type > (false, ConnectionData_open));
                break;
            }
            case ConnectionData_recover:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<SessionConnectionIdentifier > (false, ConnectionData_recover));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ConnectionData::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<any_type > (true, ConnectionData_open));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<SessionConnectionIdentifier > (true, ConnectionData_recover));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence SessionConnectionIdentifier

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(additionalReferenceInformation_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*callingSSuserReference_);
        ITU_T_BIND_PER(*commonReference_);
        ITU_T_BIND_PER(additionalReferenceInformation_);
    }

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*callingSSuserReference_);
        ITU_T_BIND_PER(*commonReference_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(additionalReferenceInformation_);
    }

    // choice CallingSSuserReference

    template<> void CallingSSuserReference::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CallingSSuserReference_octetString:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<octet_string > (false, CallingSSuserReference_octetString));
                break;
            }
            case CallingSSuserReference_t61String:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<t61_string > (false, CallingSSuserReference_t61String));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CallingSSuserReference::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<octet_string > (true, CallingSSuserReference_octetString));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<t61_string > (true, CallingSSuserReference_t61String));
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

