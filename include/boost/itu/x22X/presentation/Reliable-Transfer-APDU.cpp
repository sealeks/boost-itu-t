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

    SessionConnectionIdentifier::SessionConnectionIdentifier() : callingSSuserReference_(), commonReference_() {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(const CallingSSuserReference& __callingSSuserReference,
            const CommonReference& __commonReference) :
    callingSSuserReference_(__callingSSuserReference),
    commonReference_(__commonReference) {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(boost::shared_ptr< CallingSSuserReference> __callingSSuserReference,
            boost::shared_ptr< CommonReference> __commonReference,
            boost::shared_ptr< AdditionalReferenceInformation> __additionalReferenceInformation) :
    callingSSuserReference_(*__callingSSuserReference),
    commonReference_(*__commonReference),
    additionalReferenceInformation_(__additionalReferenceInformation) {
    };

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_CHOICE(callingSSuserReference_);
        BOOST_ASN_BIND_TAG(commonReference_);
        BOOST_ASN_IMPLICIT_TAG(additionalReferenceInformation_, 0);
    }

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_CHOICE(callingSSuserReference_);
        BOOST_ASN_BIND_TAG(commonReference_);
        BOOST_ASN_IMPLICIT_TAG(additionalReferenceInformation_, 0);
    }

    CallingSSuserReference& SessionConnectionIdentifier::callingSSuserReference() {
        return callingSSuserReference_;
    }

    void SessionConnectionIdentifier::callingSSuserReference(const CallingSSuserReference& vl) {
        callingSSuserReference_ = vl;
    }

    CommonReference& SessionConnectionIdentifier::commonReference() {
        return commonReference_;
    }

    void SessionConnectionIdentifier::commonReference(const CommonReference& vl) {
        commonReference_ = vl;
    }

    AdditionalReferenceInformation& SessionConnectionIdentifier::additionalReferenceInformation() {
        return *additionalReferenceInformation_;
    }

    void SessionConnectionIdentifier::additionalReferenceInformation(const AdditionalReferenceInformation& vl) {
        additionalReferenceInformation_ = boost::shared_ptr<AdditionalReferenceInformation>(new AdditionalReferenceInformation(vl));
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
    abortReason_(__abortReason),
    reflectedParameter_(__reflectedParameter),
    userdataAB_(__userdataAB) {
    };

    template<> void RTABapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abortReason_, 0);
        BOOST_ASN_IMPLICIT_TAG(reflectedParameter_, 1);
        BOOST_ASN_EXPLICIT_TAG(userdataAB_, 2);
    }

    template<> void RTABapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(abortReason_, 0);
        BOOST_ASN_IMPLICIT_TAG(reflectedParameter_, 1);
        BOOST_ASN_EXPLICIT_TAG(userdataAB_, 2);
    }

    AbortReason& RTABapdu::abortReason() {
        return *abortReason_;
    }

    void RTABapdu::abortReason(const AbortReason& vl) {
        abortReason_ = boost::shared_ptr<AbortReason>(new AbortReason(vl));
    }

    bitstring_type& RTABapdu::reflectedParameter() {
        return *reflectedParameter_;
    }

    void RTABapdu::reflectedParameter(const bitstring_type& vl) {
        reflectedParameter_ = boost::shared_ptr<bitstring_type>(new bitstring_type(vl));
    }

    any_type& RTABapdu::userdataAB() {
        return *userdataAB_;
    }

    void RTABapdu::userdataAB(const any_type& vl) {
        userdataAB_ = boost::shared_ptr<any_type>(new any_type(vl));
    }


    // set RTORJapdu

    RTORJapdu::RTORJapdu() {
    };

    RTORJapdu::RTORJapdu(boost::shared_ptr< RefuseReason> __refuseReason,
            boost::shared_ptr< any_type> __userDataRJ) :
    refuseReason_(__refuseReason),
    userDataRJ_(__userDataRJ) {
    };

    template<> void RTORJapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(refuseReason_, 0);
        BOOST_ASN_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(refuseReason_, 0);
        BOOST_ASN_EXPLICIT_TAG(userDataRJ_, 1);
    }

    RefuseReason& RTORJapdu::refuseReason() {
        return *refuseReason_;
    }

    void RTORJapdu::refuseReason(const RefuseReason& vl) {
        refuseReason_ = boost::shared_ptr<RefuseReason>(new RefuseReason(vl));
    }

    any_type& RTORJapdu::userDataRJ() {
        return *userDataRJ_;
    }

    void RTORJapdu::userDataRJ(const any_type& vl) {
        userDataRJ_ = boost::shared_ptr<any_type>(new any_type(vl));
    }


    // set RTOACapdu

    RTOACapdu::RTOACapdu() : connectionDataAC_() {
    };

    RTOACapdu::RTOACapdu(const ConnectionData& __connectionDataAC) :
    connectionDataAC_(__connectionDataAC) {
    };

    RTOACapdu::RTOACapdu(boost::shared_ptr< int> __checkpointSize,
            boost::shared_ptr< int> __windowSize,
            boost::shared_ptr< ConnectionData> __connectionDataAC) :
    checkpointSize_(__checkpointSize),
    windowSize_(__windowSize),
    connectionDataAC_(*__connectionDataAC) {
    };

    template<> void RTOACapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize_, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize_, 1);
        BOOST_ASN_EXPLICIT_TAG(connectionDataAC_, 2);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize_, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize_, 1);
        BOOST_ASN_EXPLICIT_TAG(connectionDataAC_, 2);
    }

    int& RTOACapdu::checkpointSize() {
        return *checkpointSize_;
    }

    void RTOACapdu::checkpointSize(const int& vl) {
        checkpointSize_ = boost::shared_ptr<int>(new int(vl));
    }

    int& RTOACapdu::windowSize() {
        return *windowSize_;
    }

    void RTOACapdu::windowSize(const int& vl) {
        windowSize_ = boost::shared_ptr<int>(new int(vl));
    }

    ConnectionData& RTOACapdu::connectionDataAC() {
        return connectionDataAC_;
    }

    void RTOACapdu::connectionDataAC(const ConnectionData& vl) {
        connectionDataAC_ = vl;
    }


    // set RTORQapdu
    const int RTORQapdu::monologue = 0;
    const int RTORQapdu::twa = 1;

    RTORQapdu::RTORQapdu() : connectionDataRQ_() {
    };

    RTORQapdu::RTORQapdu(const ConnectionData& __connectionDataRQ) :
    connectionDataRQ_(__connectionDataRQ) {
    };

    RTORQapdu::RTORQapdu(boost::shared_ptr< int> __checkpointSize,
            boost::shared_ptr< int> __windowSize,
            boost::shared_ptr< int> __dialogueMode,
            boost::shared_ptr< ConnectionData> __connectionDataRQ,
            boost::shared_ptr< int> __applicationProtocol) :
    checkpointSize_(__checkpointSize),
    windowSize_(__windowSize),
    dialogueMode_(__dialogueMode),
    connectionDataRQ_(*__connectionDataRQ),
    applicationProtocol_(__applicationProtocol) {
    };

    template<> void RTORQapdu::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize_, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize_, 1);
        BOOST_ASN_IMPLICIT_TAG(dialogueMode_, 2);
        BOOST_ASN_EXPLICIT_TAG(connectionDataRQ_, 3);
        BOOST_ASN_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void RTORQapdu::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(checkpointSize_, 0);
        BOOST_ASN_IMPLICIT_TAG(windowSize_, 1);
        BOOST_ASN_IMPLICIT_TAG(dialogueMode_, 2);
        BOOST_ASN_EXPLICIT_TAG(connectionDataRQ_, 3);
        BOOST_ASN_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    int& RTORQapdu::checkpointSize() {
        return *checkpointSize_;
    }

    void RTORQapdu::checkpointSize(const int& vl) {
        checkpointSize_ = boost::shared_ptr<int>(new int(vl));
    }

    int& RTORQapdu::windowSize() {
        return *windowSize_;
    }

    void RTORQapdu::windowSize(const int& vl) {
        windowSize_ = boost::shared_ptr<int>(new int(vl));
    }

    int& RTORQapdu::dialogueMode() {
        return *dialogueMode_;
    }

    void RTORQapdu::dialogueMode(const int& vl) {
        dialogueMode_ = boost::shared_ptr<int>(new int(vl));
    }

    ConnectionData& RTORQapdu::connectionDataRQ() {
        return connectionDataRQ_;
    }

    void RTORQapdu::connectionDataRQ(const ConnectionData& vl) {
        connectionDataRQ_ = vl;
    }

    int& RTORQapdu::applicationProtocol() {
        return *applicationProtocol_;
    }

    void RTORQapdu::applicationProtocol(const int& vl) {
        applicationProtocol_ = boost::shared_ptr<int>(new int(vl));
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
