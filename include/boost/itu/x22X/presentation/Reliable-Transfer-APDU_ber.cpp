#include "Reliable-Transfer-APDU.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {

    template<> void RTSE_apdus::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RTSE_apdus_rtorq_apdu:
            {
                ITU_T_IMPLICIT_TAG(*value<RTORQapdu > (false, RTSE_apdus_rtorq_apdu), 16);
                break;
            }
            case RTSE_apdus_rtoac_apdu:
            {
                ITU_T_IMPLICIT_TAG(*value<RTOACapdu > (false, RTSE_apdus_rtoac_apdu), 17);
                break;
            }
            case RTSE_apdus_rtorj_apdu:
            {
                ITU_T_IMPLICIT_TAG(*value<RTORJapdu > (false, RTSE_apdus_rtorj_apdu), 18);
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
                ITU_T_IMPLICIT_TAG(*value<RTABapdu > (false, RTSE_apdus_rtab_apdu), 22);
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
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RTORQapdu > (true, RTSE_apdus_rtorq_apdu), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RTOACapdu > (true, RTSE_apdus_rtoac_apdu), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RTORJapdu > (true, RTSE_apdus_rtorj_apdu), 18)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RTABapdu > (true, RTSE_apdus_rtab_apdu), 22)) return;
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
                if (ITU_T_BIND_TAG(*value<RTTPapdu > (true, RTSE_apdus_rttp_apdu))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<RTTRapdu > (true, RTSE_apdus_rttr_apdu))) return;
                else free();
            }
        }
    }

    template<> void RTORQapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(windowSize_.get_shared(), 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_.get_shared(), 2);
        ITU_T_CHOICE_TAG(*connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void RTORQapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(windowSize_.get_shared(), 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_.get_shared(), 2);
        ITU_T_CHOICE_TAG(*connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(windowSize_.get_shared(), 1);
        ITU_T_CHOICE_TAG(*connectionDataAC_, 2);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(windowSize_.get_shared(), 1);
        ITU_T_CHOICE_TAG(*connectionDataAC_, 2);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void RTABapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abortReason_, 0);
        ITU_T_IMPLICIT_TAG(reflectedParameter_, 1);
        ITU_T_EXPLICIT_TAG(userdataAB_, 2);
    }

    template<> void RTABapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abortReason_, 0);
        ITU_T_IMPLICIT_TAG(reflectedParameter_, 1);
        ITU_T_EXPLICIT_TAG(userdataAB_, 2);
    }

    template<> void ConnectionData::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConnectionData_open:
            {
                ITU_T_EXPLICIT_TAG(*value<any_type > (false, ConnectionData_open), 0);
                break;
            }
            case ConnectionData_recover:
            {
                ITU_T_IMPLICIT_TAG(*value<SessionConnectionIdentifier > (false, ConnectionData_recover), 1);
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
                        if (ITU_T_EXPLICIT_TAG(*value<any_type > (true, ConnectionData_open), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<SessionConnectionIdentifier > (true, ConnectionData_recover), 1)) return;
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

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*callingSSuserReference_);
        ITU_T_BIND_TAG(*commonReference_);
        ITU_T_IMPLICIT_TAG(additionalReferenceInformation_, 0);
    }

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*callingSSuserReference_);
        ITU_T_BIND_TAG(*commonReference_);
        ITU_T_IMPLICIT_TAG(additionalReferenceInformation_, 0);
    }

    template<> void CallingSSuserReference::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CallingSSuserReference_t61String:
            {
                ITU_T_BIND_TAG(*value<t61string_type > (false, CallingSSuserReference_t61String));
                break;
            }
            case CallingSSuserReference_octetString:
            {
                ITU_T_BIND_TAG(*value<octetstring_type > (false, CallingSSuserReference_octetString));
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
                if (ITU_T_BIND_TAG(*value<t61string_type > (true, CallingSSuserReference_t61String))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<octetstring_type > (true, CallingSSuserReference_octetString))) return;
                else free();
            }
        }
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

