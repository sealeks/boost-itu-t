#include "Reliable-Transfer-APDU.hpp"

namespace Reliable_Transfer_APDU {

    const boost::array<boost::asn1::oidindx_type, 3> rTSE_abstract_syntax_OID_ARR = {2, 3, 2};
    const oid_type rTSE_abstract_syntax = boost::asn1::oid_type(rTSE_abstract_syntax_OID_ARR);

    // choice RTSE-apdus

    template<> void RTSE_apdus::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RTSE_apdus_rtorq_apdu:
            {
                ITU_T_IMPLICIT_TAG(value<RTORQapdu > (false, RTSE_apdus_rtorq_apdu), 16);
                break;
            }
            case RTSE_apdus_rtoac_apdu:
            {
                ITU_T_IMPLICIT_TAG(value<RTOACapdu > (false, RTSE_apdus_rtoac_apdu), 17);
                break;
            }
            case RTSE_apdus_rtorj_apdu:
            {
                ITU_T_IMPLICIT_TAG(value<RTORJapdu > (false, RTSE_apdus_rtorj_apdu), 18);
                break;
            }
            case RTSE_apdus_rttp_apdu:
            {
                ITU_T_BIND_TAG(value<RTTPapdu > (false, RTSE_apdus_rttp_apdu));
                break;
            }
            case RTSE_apdus_rttr_apdu:
            {
                ITU_T_BIND_TAG(value<RTTRapdu > (false, RTSE_apdus_rttr_apdu));
                break;
            }
            case RTSE_apdus_rtab_apdu:
            {
                ITU_T_IMPLICIT_TAG(value<RTABapdu > (false, RTSE_apdus_rtab_apdu), 22);
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
                        if (ITU_T_IMPLICIT_TAG(value<RTORQapdu > (true, RTSE_apdus_rtorq_apdu), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RTOACapdu > (true, RTSE_apdus_rtoac_apdu), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RTORJapdu > (true, RTSE_apdus_rtorj_apdu), 18)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RTABapdu > (true, RTSE_apdus_rtab_apdu), 22)) return;
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
                if (ITU_T_BIND_TAG(value<RTTPapdu > (true, RTSE_apdus_rttp_apdu))) return;
                else free();
                if (ITU_T_BIND_TAG(value<RTTRapdu > (true, RTSE_apdus_rttr_apdu))) return;
                else free();
            }
        }
    }


    // set RTORQapdu
    const int RTORQapdu::dialogueMode_monologue = 0;
    const int RTORQapdu::dialogueMode_twa = 1;

    RTORQapdu::RTORQapdu() : connectionDataRQ_() {
    };

    RTORQapdu::RTORQapdu(const ConnectionData& arg__connectionDataRQ) :
    connectionDataRQ_(arg__connectionDataRQ) {
    };

    RTORQapdu::RTORQapdu(boost::shared_ptr< int> arg__checkpointSize,
            boost::shared_ptr< int> arg__windowSize,
            boost::shared_ptr< int> arg__dialogueMode,
            boost::shared_ptr< ConnectionData> arg__connectionDataRQ,
            boost::shared_ptr< int> arg__applicationProtocol) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    dialogueMode_(arg__dialogueMode),
    connectionDataRQ_(arg__connectionDataRQ),
    applicationProtocol_(arg__applicationProtocol) {
    };

    const int RTORQapdu::checkpointSize__default = 0;

    const int RTORQapdu::windowSize__default = 3;

    const int RTORQapdu::dialogueMode__default = 0;

    template<> void RTORQapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_, 2);
        ITU_T_CHOICE_TAG(connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void RTORQapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_, 2);
        ITU_T_CHOICE_TAG(connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    const int& RTORQapdu::checkpointSize() const {
        return *checkpointSize_;
    }

    void RTORQapdu::checkpointSize(const int& vl) {
        checkpointSize_ = vl;
    }

    void RTORQapdu::checkpointSize(boost::shared_ptr< int> vl) {
        checkpointSize_ = vl;
    }

    const int& RTORQapdu::windowSize() const {
        return *windowSize_;
    }

    void RTORQapdu::windowSize(const int& vl) {
        windowSize_ = vl;
    }

    void RTORQapdu::windowSize(boost::shared_ptr< int> vl) {
        windowSize_ = vl;
    }

    const int& RTORQapdu::dialogueMode() const {
        return *dialogueMode_;
    }

    void RTORQapdu::dialogueMode(const int& vl) {
        dialogueMode_ = vl;
    }

    void RTORQapdu::dialogueMode(boost::shared_ptr< int> vl) {
        dialogueMode_ = vl;
    }

    ConnectionData& RTORQapdu::connectionDataRQ() {
        return *connectionDataRQ_;
    }

    const ConnectionData& RTORQapdu::connectionDataRQ() const {
        return *connectionDataRQ_;
    }

    void RTORQapdu::connectionDataRQ(const ConnectionData& vl) {
        connectionDataRQ_ = vl;
    }

    void RTORQapdu::connectionDataRQ(boost::shared_ptr< ConnectionData> vl) {
        connectionDataRQ_ = vl;
    }

    boost::shared_ptr<int> RTORQapdu::applicationProtocol__new() {
        return applicationProtocol_ = boost::shared_ptr<int>(new int());
    }

    void RTORQapdu::applicationProtocol(const int& vl) {
        applicationProtocol_ = boost::shared_ptr<int>(new int(vl));
    }


    // set RTOACapdu

    RTOACapdu::RTOACapdu() : connectionDataAC_() {
    };

    RTOACapdu::RTOACapdu(const ConnectionData& arg__connectionDataAC) :
    connectionDataAC_(arg__connectionDataAC) {
    };

    RTOACapdu::RTOACapdu(boost::shared_ptr< int> arg__checkpointSize,
            boost::shared_ptr< int> arg__windowSize,
            boost::shared_ptr< ConnectionData> arg__connectionDataAC) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    connectionDataAC_(arg__connectionDataAC) {
    };

    const int RTOACapdu::checkpointSize__default = 0;

    const int RTOACapdu::windowSize__default = 3;

    template<> void RTOACapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_CHOICE_TAG(connectionDataAC_, 2);
    }

    template<> void RTOACapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_CHOICE_TAG(connectionDataAC_, 2);
    }

    const int& RTOACapdu::checkpointSize() const {
        return *checkpointSize_;
    }

    void RTOACapdu::checkpointSize(const int& vl) {
        checkpointSize_ = vl;
    }

    void RTOACapdu::checkpointSize(boost::shared_ptr< int> vl) {
        checkpointSize_ = vl;
    }

    const int& RTOACapdu::windowSize() const {
        return *windowSize_;
    }

    void RTOACapdu::windowSize(const int& vl) {
        windowSize_ = vl;
    }

    void RTOACapdu::windowSize(boost::shared_ptr< int> vl) {
        windowSize_ = vl;
    }

    ConnectionData& RTOACapdu::connectionDataAC() {
        return *connectionDataAC_;
    }

    const ConnectionData& RTOACapdu::connectionDataAC() const {
        return *connectionDataAC_;
    }

    void RTOACapdu::connectionDataAC(const ConnectionData& vl) {
        connectionDataAC_ = vl;
    }

    void RTOACapdu::connectionDataAC(boost::shared_ptr< ConnectionData> vl) {
        connectionDataAC_ = vl;
    }


    // set RTORJapdu

    RTORJapdu::RTORJapdu() {
    };

    RTORJapdu::RTORJapdu(boost::shared_ptr< RefuseReason> arg__refuseReason,
            boost::shared_ptr< any_type> arg__userDataRJ) :
    refuseReason_(arg__refuseReason),
    userDataRJ_(arg__userDataRJ) {
    };

    template<> void RTORJapdu::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void RTORJapdu::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    boost::shared_ptr<RefuseReason> RTORJapdu::refuseReason__new() {
        return refuseReason_ = boost::shared_ptr<RefuseReason>(new RefuseReason());
    }

    void RTORJapdu::refuseReason(const RefuseReason& vl) {
        refuseReason_ = boost::shared_ptr<RefuseReason>(new RefuseReason(vl));
    }

    boost::shared_ptr<any_type> RTORJapdu::userDataRJ__new() {
        return userDataRJ_ = boost::shared_ptr<any_type>(new any_type());
    }

    void RTORJapdu::userDataRJ(const any_type& vl) {
        userDataRJ_ = boost::shared_ptr<any_type>(new any_type(vl));
    }


    // set RTABapdu

    RTABapdu::RTABapdu() {
    };

    RTABapdu::RTABapdu(boost::shared_ptr< AbortReason> arg__abortReason,
            boost::shared_ptr< bitstring_type> arg__reflectedParameter,
            boost::shared_ptr< any_type> arg__userdataAB) :
    abortReason_(arg__abortReason),
    reflectedParameter_(arg__reflectedParameter),
    userdataAB_(arg__userdataAB) {
    };

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

    boost::shared_ptr<AbortReason> RTABapdu::abortReason__new() {
        return abortReason_ = boost::shared_ptr<AbortReason>(new AbortReason());
    }

    void RTABapdu::abortReason(const AbortReason& vl) {
        abortReason_ = boost::shared_ptr<AbortReason>(new AbortReason(vl));
    }

    boost::shared_ptr<bitstring_type> RTABapdu::reflectedParameter__new() {
        return reflectedParameter_ = boost::shared_ptr<bitstring_type>(new bitstring_type());
    }

    void RTABapdu::reflectedParameter(const bitstring_type& vl) {
        reflectedParameter_ = boost::shared_ptr<bitstring_type>(new bitstring_type(vl));
    }

    boost::shared_ptr<any_type> RTABapdu::userdataAB__new() {
        return userdataAB_ = boost::shared_ptr<any_type>(new any_type());
    }

    void RTABapdu::userdataAB(const any_type& vl) {
        userdataAB_ = boost::shared_ptr<any_type>(new any_type(vl));
    }


    // choice ConnectionData

    template<> void ConnectionData::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConnectionData_open:
            {
                ITU_T_EXPLICIT_TAG(value<any_type > (false, ConnectionData_open), 0);
                break;
            }
            case ConnectionData_recover:
            {
                ITU_T_IMPLICIT_TAG(value<SessionConnectionIdentifier > (false, ConnectionData_recover), 1);
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
                        if (ITU_T_EXPLICIT_TAG(value<any_type > (true, ConnectionData_open), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<SessionConnectionIdentifier > (true, ConnectionData_recover), 1)) return;
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


    // sequence SessionConnectionIdentifier

    SessionConnectionIdentifier::SessionConnectionIdentifier() : callingSSuserReference_(), commonReference_() {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(const CallingSSuserReference& arg__callingSSuserReference,
            const CommonReference& arg__commonReference) :
    callingSSuserReference_(arg__callingSSuserReference),
    commonReference_(arg__commonReference) {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(boost::shared_ptr< CallingSSuserReference> arg__callingSSuserReference,
            boost::shared_ptr< CommonReference> arg__commonReference,
            boost::shared_ptr< AdditionalReferenceInformation> arg__additionalReferenceInformation) :
    callingSSuserReference_(arg__callingSSuserReference),
    commonReference_(arg__commonReference),
    additionalReferenceInformation_(arg__additionalReferenceInformation) {
    };

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE(callingSSuserReference_);
        ITU_T_BIND_TAG(commonReference_);
        ITU_T_IMPLICIT_TAG(additionalReferenceInformation_, 0);
    }

    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE(callingSSuserReference_);
        ITU_T_BIND_TAG(commonReference_);
        ITU_T_IMPLICIT_TAG(additionalReferenceInformation_, 0);
    }

    CallingSSuserReference& SessionConnectionIdentifier::callingSSuserReference() {
        return *callingSSuserReference_;
    }

    const CallingSSuserReference& SessionConnectionIdentifier::callingSSuserReference() const {
        return *callingSSuserReference_;
    }

    void SessionConnectionIdentifier::callingSSuserReference(const CallingSSuserReference& vl) {
        callingSSuserReference_ = vl;
    }

    void SessionConnectionIdentifier::callingSSuserReference(boost::shared_ptr< CallingSSuserReference> vl) {
        callingSSuserReference_ = vl;
    }

    CommonReference& SessionConnectionIdentifier::commonReference() {
        return *commonReference_;
    }

    const CommonReference& SessionConnectionIdentifier::commonReference() const {
        return *commonReference_;
    }

    void SessionConnectionIdentifier::commonReference(const CommonReference& vl) {
        commonReference_ = vl;
    }

    void SessionConnectionIdentifier::commonReference(boost::shared_ptr< CommonReference> vl) {
        commonReference_ = vl;
    }

    boost::shared_ptr<AdditionalReferenceInformation> SessionConnectionIdentifier::additionalReferenceInformation__new() {
        return additionalReferenceInformation_ = boost::shared_ptr<AdditionalReferenceInformation>(new AdditionalReferenceInformation());
    }

    void SessionConnectionIdentifier::additionalReferenceInformation(const AdditionalReferenceInformation& vl) {
        additionalReferenceInformation_ = boost::shared_ptr<AdditionalReferenceInformation>(new AdditionalReferenceInformation(vl));
    }


    const RefuseReason RefuseReason_rtsBusy = 0;
    const RefuseReason RefuseReason_cannotRecover = 1;
    const RefuseReason RefuseReason_validationFailure = 2;
    const RefuseReason RefuseReason_unacceptableDialogueMode = 3;

    // choice CallingSSuserReference

    template<> void CallingSSuserReference::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CallingSSuserReference_t61String:
            {
                ITU_T_BIND_TAG(value<t61string_type > (false, CallingSSuserReference_t61String));
                break;
            }
            case CallingSSuserReference_octetString:
            {
                ITU_T_BIND_TAG(value<octetstring_type > (false, CallingSSuserReference_octetString));
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
                if (ITU_T_BIND_TAG(value<t61string_type > (true, CallingSSuserReference_t61String))) return;
                else free();
                if (ITU_T_BIND_TAG(value<octetstring_type > (true, CallingSSuserReference_octetString))) return;
                else free();
            }
        }
    }


    const AbortReason AbortReason_localSystemProblem = 0;
    const AbortReason AbortReason_invalidParameter = 1;
    const AbortReason AbortReason_unrecognizedActivity = 2;
    const AbortReason AbortReason_temporaryProblem = 3;
    const AbortReason AbortReason_protocolError = 4;
    const AbortReason AbortReason_permanentProblem = 5;
    const AbortReason AbortReason_userError = 6;
    const AbortReason AbortReason_transferCompleted = 7;

}
