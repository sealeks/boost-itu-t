#include "Reliable-Transfer-APDU.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {



    // choice RTSE-apdus

    template<> void RTSE_apdus::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RTSE_apdus_rtorq_apdu:
            {
                ITU_T_BIND_IMPLICIT(*value<RTORQapdu > (false, RTSE_apdus_rtorq_apdu), 16, CONTEXT_CLASS);
                break;
            }
            case RTSE_apdus_rtoac_apdu:
            {
                ITU_T_BIND_IMPLICIT(*value<RTOACapdu > (false, RTSE_apdus_rtoac_apdu), 17, CONTEXT_CLASS);
                break;
            }
            case RTSE_apdus_rtorj_apdu:
            {
                ITU_T_BIND_IMPLICIT(*value<RTORJapdu > (false, RTSE_apdus_rtorj_apdu), 18, CONTEXT_CLASS);
                break;
            }
            case RTSE_apdus_rttp_apdu:
            {
                ITU_T_BIND_TAG(*value<RTTPapdu > (false, RTSE_apdus_rttp_apdu));
                break;
            }
            case RTSE_apdus_rttr_apdu:
            {
                ITU_T_BIND_TAG(*value<RTTRapdu > (false, RTSE_apdus_rttr_apdu));
                break;
            }
            case RTSE_apdus_rtab_apdu:
            {
                ITU_T_BIND_IMPLICIT(*value<RTABapdu > (false, RTSE_apdus_rtab_apdu), 22, CONTEXT_CLASS);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RTSE_apdus::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    case 2:
                    {
                        if (ITU_T_BIND_TAG(*value<RTTPapdu > (true, RTSE_apdus_rttp_apdu))) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_BIND_TAG(*value<RTTRapdu > (true, RTSE_apdus_rttr_apdu))) return;
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
                    case 16:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<RTORQapdu > (true, RTSE_apdus_rtorq_apdu), 16, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<RTOACapdu > (true, RTSE_apdus_rtoac_apdu), 17, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<RTORJapdu > (true, RTSE_apdus_rtorj_apdu), 18, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<RTABapdu > (true, RTSE_apdus_rtab_apdu), 22, CONTEXT_CLASS)) return;
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

    // set  RTORQapdu

    template<> void RTORQapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dialogueMode_, 2, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*connectionDataRQ_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(applicationProtocol_, 4, CONTEXT_CLASS);
    }

    template<> void RTORQapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dialogueMode_, 2, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*connectionDataRQ_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(applicationProtocol_, 4, CONTEXT_CLASS);
    }

    // set  RTOACapdu

    template<> void RTOACapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*connectionDataAC_, 2, CONTEXT_CLASS);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(checkpointSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(windowSize_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(*connectionDataAC_, 2, CONTEXT_CLASS);
    }

    // set  RTORJapdu

    template<> void RTORJapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(refuseReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userDataRJ_, 1, CONTEXT_CLASS);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(refuseReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userDataRJ_, 1, CONTEXT_CLASS);
    }

    // set  RTABapdu

    template<> void RTABapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(abortReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(reflectedParameter_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userdataAB_, 2, CONTEXT_CLASS);
    }

    template<> void RTABapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(abortReason_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(reflectedParameter_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(userdataAB_, 2, CONTEXT_CLASS);
    }

    // choice ConnectionData

    template<> void ConnectionData::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConnectionData_open:
            {
                ITU_T_BIND_EXPLICIT(*value<any_type > (false, ConnectionData_open), 0, CONTEXT_CLASS);
                break;
            }
            case ConnectionData_recover:
            {
                ITU_T_BIND_IMPLICIT(*value<SessionConnectionIdentifier > (false, ConnectionData_recover), 1, CONTEXT_CLASS);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ConnectionData::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_BIND_EXPLICIT(*value<any_type > (true, ConnectionData_open), 0, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_IMPLICIT(*value<SessionConnectionIdentifier > (true, ConnectionData_recover), 1, CONTEXT_CLASS)) return;
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

    // sequence SessionConnectionIdentifier

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*callingSSuserReference_);
        ITU_T_BIND_TAG(*commonReference_);
        ITU_T_BIND_IMPLICIT(additionalReferenceInformation_, 0, CONTEXT_CLASS);
    }

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*callingSSuserReference_);
        ITU_T_BIND_TAG(*commonReference_);
        ITU_T_BIND_IMPLICIT(additionalReferenceInformation_, 0, CONTEXT_CLASS);
    }

    // choice CallingSSuserReference

    template<> void CallingSSuserReference::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CallingSSuserReference_t61String:
            {
                ITU_T_BIND_TAG(*value<t61_string > (false, CallingSSuserReference_t61String));
                break;
            }
            case CallingSSuserReference_octetString:
            {
                ITU_T_BIND_TAG(*value<octet_string > (false, CallingSSuserReference_octetString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CallingSSuserReference::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    case 20:
                    {
                        if (ITU_T_BIND_TAG(*value<t61_string > (true, CallingSSuserReference_t61String))) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_BIND_TAG(*value<octet_string > (true, CallingSSuserReference_octetString))) return;
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

