#include "Reliable-Transfer-APDU.hpp"

namespace Reliable_Transfer_APDU {

    const AbortReason AbortReason_localSystemProblem = 0;
    const AbortReason AbortReason_invalidParameter = 1;
    const AbortReason AbortReason_unrecognizedActivity = 2;
    const AbortReason AbortReason_temporaryProblem = 3;
    const AbortReason AbortReason_protocolError = 4;
    const AbortReason AbortReason_permanentProblem = 5;
    const AbortReason AbortReason_userError = 6;
    const AbortReason AbortReason_transferCompleted = 7;

    // choice CallingSSuserReference

    template<> void CallingSSuserReference::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CallingSSuserReference_t61String:
            {
                BOOST_ASN_BIND_TAG(value<t61string_type > (false, CallingSSuserReference_t61String));
                break;
            }
            case CallingSSuserReference_octetString:
            {
                BOOST_ASN_BIND_TAG(value<octetstring_type > (false, CallingSSuserReference_octetString));
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
                if (BOOST_ASN_BIND_TAG(value<t61string_type > (true, CallingSSuserReference_t61String))) return;
                else free();
                if (BOOST_ASN_BIND_TAG(value<octetstring_type > (true, CallingSSuserReference_octetString))) return;
                else free();
            }
        }
    }


    const RefuseReason RefuseReason_rtsBusy = 0;
    const RefuseReason RefuseReason_cannotRecover = 1;
    const RefuseReason RefuseReason_validationFailure = 2;
    const RefuseReason RefuseReason_unacceptableDialogueMode = 3;

    // sequence SessionConnectionIdentifier

    SessionConnectionIdentifier::SessionConnectionIdentifier() : callingSSuserReference(), commonReference() {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(const CallingSSuserReference& __callingSSuserReference,
            const CommonReference& __commonReference) :
    callingSSuserReference(__callingSSuserReference),
    commonReference(__commonReference) {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(boost::shared_ptr< CallingSSuserReference> __callingSSuserReference,
            boost::shared_ptr< CommonReference> __commonReference,
            boost::shared_ptr< AdditionalReferenceInformation> __additionalReferenceInformation) :
    callingSSuserReference(*__callingSSuserReference),
    commonReference(*__commonReference),
    additionalReferenceInformation(__additionalReferenceInformation) {
    };

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_CHOICE(callingSSuserReference);
        BOOST_ASN_BIND_TAG(commonReference);
        BOOST_ASN_IMPLICIT_TAG(additionalReferenceInformation, 0);
    }

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_CHOICE(callingSSuserReference);
        BOOST_ASN_BIND_TAG(commonReference);
        BOOST_ASN_IMPLICIT_TAG(additionalReferenceInformation, 0);
    }


    // choice ConnectionData

    template<> void ConnectionData::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConnectionData_open:
            {
                BOOST_ASN_EXPLICIT_TAG(value<any_type > (false, ConnectionData_open), 0);
                break;
            }
            case ConnectionData_recover:
            {
                BOOST_ASN_IMPLICIT_TAG(value<SessionConnectionIdentifier > (false, ConnectionData_recover), 1);
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
                        if (BOOST_ASN_EXPLICIT_TAG(value<any_type > (true, ConnectionData_open), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<SessionConnectionIdentifier > (true, ConnectionData_recover), 1)) return;
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


    // set RTABapdu

    RTABapdu::RTABapdu() {
    };

    RTABapdu::RTABapdu(boost::shared_ptr< AbortReason> __abortReason,
            boost::shared_ptr< bitstring_type> __reflectedParameter,
            boost::shared_ptr< any_type> __userdataAB) :
    abortReason(__abortReason),
    reflectedParameter(__reflectedParameter),
    userdataAB(__userdataAB) {
    };

    template<> void RTABapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abortReason, 0);
        BOOST_ASN_IMPLICIT_TAG(reflectedParameter, 1);
        BOOST_ASN_EXPLICIT_TAG(userdataAB, 2);
    }

    template<> void RTABapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abortReason, 0);
        BOOST_ASN_IMPLICIT_TAG(reflectedParameter, 1);
        BOOST_ASN_EXPLICIT_TAG(userdataAB, 2);
    }


    // set RTORJapdu

    RTORJapdu::RTORJapdu() {
    };

    RTORJapdu::RTORJapdu(boost::shared_ptr< RefuseReason> __refuseReason,
            boost::shared_ptr< any_type> __userDataRJ) :
    refuseReason(__refuseReason),
    userDataRJ(__userDataRJ) {
    };

    template<> void RTORJapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(refuseReason, 0);
        BOOST_ASN_EXPLICIT_TAG(userDataRJ, 1);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(refuseReason, 0);
        BOOST_ASN_EXPLICIT_TAG(userDataRJ, 1);
    }


    // set RTOACapdu

    RTOACapdu::RTOACapdu() : connectionDataAC() {
    };

    RTOACapdu::RTOACapdu(const ConnectionData& __connectionDataAC) :
    connectionDataAC(__connectionDataAC) {
    };

    RTOACapdu::RTOACapdu(boost::shared_ptr< int> __checkpointSize,
            boost::shared_ptr< int> __windowSize,
            boost::shared_ptr< ConnectionData> __connectionDataAC) :
    checkpointSize(__checkpointSize),
    windowSize(__windowSize),
    connectionDataAC(*__connectionDataAC) {
    };

    template<> void RTOACapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_EXPLICIT_TAG(connectionDataAC, 2);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_EXPLICIT_TAG(connectionDataAC, 2);
    }


    // set RTORQapdu
    const int RTORQapdu::monologue = 0;
    const int RTORQapdu::twa = 1;

    RTORQapdu::RTORQapdu() : connectionDataRQ() {
    };

    RTORQapdu::RTORQapdu(const ConnectionData& __connectionDataRQ) :
    connectionDataRQ(__connectionDataRQ) {
    };

    RTORQapdu::RTORQapdu(boost::shared_ptr< int> __checkpointSize,
            boost::shared_ptr< int> __windowSize,
            boost::shared_ptr< int> __dialogueMode,
            boost::shared_ptr< ConnectionData> __connectionDataRQ,
            boost::shared_ptr< int> __applicationProtocol) :
    checkpointSize(__checkpointSize),
    windowSize(__windowSize),
    dialogueMode(__dialogueMode),
    connectionDataRQ(*__connectionDataRQ),
    applicationProtocol(__applicationProtocol) {
    };

    template<> void RTORQapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_IMPLICIT_TAG(dialogueMode, 2);
        BOOST_ASN_EXPLICIT_TAG(connectionDataRQ, 3);
        BOOST_ASN_IMPLICIT_TAG(applicationProtocol, 4);
    }

    template<> void RTORQapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
        BOOST_ASN_IMPLICIT_TAG(dialogueMode, 2);
        BOOST_ASN_EXPLICIT_TAG(connectionDataRQ, 3);
        BOOST_ASN_IMPLICIT_TAG(applicationProtocol, 4);
    }


    // choice RTSE-apdus

    template<> void RTSE_apdus::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RTSE_apdus_rtorq_apdu:
            {
                BOOST_ASN_IMPLICIT_TAG(value<RTORQapdu > (false, RTSE_apdus_rtorq_apdu), 16);
                break;
            }
            case RTSE_apdus_rtoac_apdu:
            {
                BOOST_ASN_IMPLICIT_TAG(value<RTOACapdu > (false, RTSE_apdus_rtoac_apdu), 17);
                break;
            }
            case RTSE_apdus_rtorj_apdu:
            {
                BOOST_ASN_IMPLICIT_TAG(value<RTORJapdu > (false, RTSE_apdus_rtorj_apdu), 18);
                break;
            }
            case RTSE_apdus_rttp_apdu:
            {
                BOOST_ASN_BIND_TAG(value<RTTPapdu > (false, RTSE_apdus_rttp_apdu));
                break;
            }
            case RTSE_apdus_rttr_apdu:
            {
                BOOST_ASN_BIND_TAG(value<RTTRapdu > (false, RTSE_apdus_rttr_apdu));
                break;
            }
            case RTSE_apdus_rtab_apdu:
            {
                BOOST_ASN_IMPLICIT_TAG(value<RTABapdu > (false, RTSE_apdus_rtab_apdu), 22);
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
                        if (BOOST_ASN_IMPLICIT_TAG(value<RTORQapdu > (true, RTSE_apdus_rtorq_apdu), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<RTOACapdu > (true, RTSE_apdus_rtoac_apdu), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<RTORJapdu > (true, RTSE_apdus_rtorj_apdu), 18)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<RTABapdu > (true, RTSE_apdus_rtab_apdu), 22)) return;
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
                if (BOOST_ASN_BIND_TAG(value<RTTPapdu > (true, RTSE_apdus_rttp_apdu))) return;
                else free();
                if (BOOST_ASN_BIND_TAG(value<RTTRapdu > (true, RTSE_apdus_rttr_apdu))) return;
                else free();
            }
        }
    }


    const boost::array<boost::asn1::oidindx_type, 3> rTSE_abstract_syntax_OID_ARR = {2, 3, 2};
    const oid_type rTSE_abstract_syntax = boost::asn1::oid_type(rTSE_abstract_syntax_OID_ARR);

}
