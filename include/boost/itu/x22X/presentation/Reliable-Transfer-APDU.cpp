#include "Reliable-Transfer-APDU.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {

    // choice RTSE-apdus

    ITU_T_CHOICEC_DEFN(RTSE_apdus::rtorq_apdu, rtorq_apdu, RTORQapdu, RTSE_apdus_rtorq_apdu);
    ITU_T_CHOICEC_DEFN(RTSE_apdus::rtoac_apdu, rtoac_apdu, RTOACapdu, RTSE_apdus_rtoac_apdu);
    ITU_T_CHOICEC_DEFN(RTSE_apdus::rtorj_apdu, rtorj_apdu, RTORJapdu, RTSE_apdus_rtorj_apdu);
    ITU_T_CHOICES_DEFN(RTSE_apdus::rttp_apdu, rttp_apdu, RTTPapdu, RTSE_apdus_rttp_apdu);
    ITU_T_CHOICES_DEFN(RTSE_apdus::rttr_apdu, rttr_apdu, RTTRapdu, RTSE_apdus_rttr_apdu);
    ITU_T_CHOICEC_DEFN(RTSE_apdus::rtab_apdu, rtab_apdu, RTABapdu, RTSE_apdus_rtab_apdu);

    // set  RTORQapdu
    const integer_type RTORQapdu::dialogueMode_monologue = 0;
    const integer_type RTORQapdu::dialogueMode_twa = 1;

    RTORQapdu::RTORQapdu() : connectionDataRQ_() {
    };

    RTORQapdu::RTORQapdu(const ConnectionData& arg__connectionDataRQ) :
    connectionDataRQ_(arg__connectionDataRQ) {
    };

    RTORQapdu::RTORQapdu(shared_ptr< integer_type> arg__checkpointSize,
            shared_ptr< integer_type> arg__windowSize,
            shared_ptr< integer_type> arg__dialogueMode,
            shared_ptr< ConnectionData> arg__connectionDataRQ,
            shared_ptr< integer_type> arg__applicationProtocol) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    dialogueMode_(arg__dialogueMode),
    connectionDataRQ_(arg__connectionDataRQ),
    applicationProtocol_(arg__applicationProtocol) {
    };

    const integer_type RTORQapdu::checkpointSize__default = 0;

    const integer_type RTORQapdu::windowSize__default = 3;

    const integer_type RTORQapdu::dialogueMode__default = 0;


    ITU_T_DEFAULTH_DEFN(RTORQapdu::checkpointSize, checkpointSize, integer_type);
    ITU_T_DEFAULTH_DEFN(RTORQapdu::windowSize, windowSize, integer_type);
    ITU_T_DEFAULTH_DEFN(RTORQapdu::dialogueMode, dialogueMode, integer_type);
    ITU_T_HOLDERH_DEFN(RTORQapdu::connectionDataRQ, connectionDataRQ, ConnectionData);
    ITU_T_OPTIONAL_DEFN(RTORQapdu::applicationProtocol, applicationProtocol, integer_type);

    // set  RTOACapdu

    RTOACapdu::RTOACapdu() : connectionDataAC_() {
    };

    RTOACapdu::RTOACapdu(const ConnectionData& arg__connectionDataAC) :
    connectionDataAC_(arg__connectionDataAC) {
    };

    RTOACapdu::RTOACapdu(shared_ptr< integer_type> arg__checkpointSize,
            shared_ptr< integer_type> arg__windowSize,
            shared_ptr< ConnectionData> arg__connectionDataAC) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    connectionDataAC_(arg__connectionDataAC) {
    };

    const integer_type RTOACapdu::checkpointSize__default = 0;

    const integer_type RTOACapdu::windowSize__default = 3;


    ITU_T_DEFAULTH_DEFN(RTOACapdu::checkpointSize, checkpointSize, integer_type);
    ITU_T_DEFAULTH_DEFN(RTOACapdu::windowSize, windowSize, integer_type);
    ITU_T_HOLDERH_DEFN(RTOACapdu::connectionDataAC, connectionDataAC, ConnectionData);

    // set  RTORJapdu

    RTORJapdu::RTORJapdu() {
    };

    RTORJapdu::RTORJapdu(shared_ptr< RefuseReason> arg__refuseReason,
            shared_ptr< any_type> arg__userDataRJ) :
    refuseReason_(arg__refuseReason),
    userDataRJ_(arg__userDataRJ) {
    };


    ITU_T_OPTIONAL_DEFN(RTORJapdu::refuseReason, refuseReason, RefuseReason);
    ITU_T_OPTIONAL_DEFN(RTORJapdu::userDataRJ, userDataRJ, any_type);

    // set  RTABapdu

    RTABapdu::RTABapdu() {
    };

    RTABapdu::RTABapdu(shared_ptr< AbortReason> arg__abortReason,
            shared_ptr< bitstring_type> arg__reflectedParameter,
            shared_ptr< any_type> arg__userdataAB) :
    abortReason_(arg__abortReason),
    reflectedParameter_(arg__reflectedParameter),
    userdataAB_(arg__userdataAB) {
    };


    ITU_T_OPTIONAL_DEFN(RTABapdu::abortReason, abortReason, AbortReason);
    ITU_T_OPTIONAL_DEFN(RTABapdu::reflectedParameter, reflectedParameter, bitstring_type);
    ITU_T_OPTIONAL_DEFN(RTABapdu::userdataAB, userdataAB, any_type);

    // choice ConnectionData

    ITU_T_CHOICES_DEFN(ConnectionData::open, open, any_type, ConnectionData_open);
    ITU_T_CHOICEC_DEFN(ConnectionData::recover, recover, SessionConnectionIdentifier, ConnectionData_recover);

    // sequence SessionConnectionIdentifier

    SessionConnectionIdentifier::SessionConnectionIdentifier() : callingSSuserReference_(), commonReference_() {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(const CallingSSuserReference& arg__callingSSuserReference,
            const CommonReference& arg__commonReference) :
    callingSSuserReference_(arg__callingSSuserReference),
    commonReference_(arg__commonReference) {
    };

    SessionConnectionIdentifier::SessionConnectionIdentifier(shared_ptr< CallingSSuserReference> arg__callingSSuserReference,
            shared_ptr< CommonReference> arg__commonReference,
            shared_ptr< AdditionalReferenceInformation> arg__additionalReferenceInformation) :
    callingSSuserReference_(arg__callingSSuserReference),
    commonReference_(arg__commonReference),
    additionalReferenceInformation_(arg__additionalReferenceInformation) {
    };


    ITU_T_HOLDERH_DEFN(SessionConnectionIdentifier::callingSSuserReference, callingSSuserReference, CallingSSuserReference);
    ITU_T_HOLDERH_DEFN(SessionConnectionIdentifier::commonReference, commonReference, CommonReference);
    ITU_T_OPTIONAL_DEFN(SessionConnectionIdentifier::additionalReferenceInformation, additionalReferenceInformation, AdditionalReferenceInformation);

    // choice CallingSSuserReference

    ITU_T_CHOICES_DEFN(CallingSSuserReference::t61String, t61String, t61string_type, CallingSSuserReference_t61String);
    ITU_T_CHOICES_DEFN(CallingSSuserReference::octetString, octetString, octetstring_type, CallingSSuserReference_octetString);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

