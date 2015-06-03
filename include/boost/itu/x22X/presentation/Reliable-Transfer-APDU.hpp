#ifndef ___RELIABLE_TRANSFER_APDU
#define ___RELIABLE_TRANSFER_APDU

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {

    ITU_T_USE_UNIVESAL_DECL;


    struct RTSE_apdus;
    struct RTORQapdu;
    struct RTOACapdu;
    struct RTORJapdu;
    struct RTABapdu;
    struct ConnectionData;
    struct SessionConnectionIdentifier;
    struct CallingSSuserReference;


    typedef integer_type RTTPapdu;
    typedef octet_string RTTRapdu;
    typedef integer_type RefuseReason;
    typedef utctime CommonReference;
    typedef t61_string AdditionalReferenceInformation;
    typedef integer_type AbortReason;

    ITU_T_OID(rTSE_abstract_syntax, ITU_T_VARRAY(2, 3, 2));

}

//#include "Remote-Operations-Information-Objects.hpp"

namespace Reliable_Transfer_APDU {

    // import   from  Remote-Operations-Information-Objects



    // choice RTSE-apdus

    enum RTSE_apdus_enum {

        RTSE_apdus_null = 0,
        RTSE_apdus_rtorq_apdu,
        RTSE_apdus_rtoac_apdu,
        RTSE_apdus_rtorj_apdu,
        RTSE_apdus_rttp_apdu,
        RTSE_apdus_rttr_apdu,
        RTSE_apdus_rtab_apdu,
    };

    struct RTSE_apdus : public ITU_T_CHOICE(RTSE_apdus_enum) {


        ITU_T_CHOICE_CTORS(RTSE_apdus);

        ITU_T_CHOICEC_DECL(rtorq_apdu, RTORQapdu, RTSE_apdus_rtorq_apdu);
        ITU_T_CHOICEC_DECL(rtoac_apdu, RTOACapdu, RTSE_apdus_rtoac_apdu);
        ITU_T_CHOICEC_DECL(rtorj_apdu, RTORJapdu, RTSE_apdus_rtorj_apdu);
        ITU_T_CHOICES_DECL(rttp_apdu, RTTPapdu, RTSE_apdus_rttp_apdu); // primitive
        ITU_T_CHOICES_DECL(rttr_apdu, RTTRapdu, RTSE_apdus_rttr_apdu); // primitive
        ITU_T_CHOICEC_DECL(rtab_apdu, RTABapdu, RTSE_apdus_rtab_apdu);

        ITU_T_ARCHIVE_FUNC;
    };

    // set  RTORQapdu

    struct RTORQapdu {

        static const integer_type dialogueMode_monologue;
        static const integer_type dialogueMode_twa;

        static const integer_type checkpointSize__default;
        static const integer_type windowSize__default;
        static const integer_type dialogueMode__default;

        RTORQapdu();

        RTORQapdu(const ConnectionData& arg__connectionDataRQ);

        RTORQapdu(shared_ptr< integer_type> arg__checkpointSize,
                shared_ptr< integer_type> arg__windowSize,
                shared_ptr< integer_type> arg__dialogueMode,
                shared_ptr< ConnectionData> arg__connectionDataRQ,
                shared_ptr< integer_type> arg__applicationProtocol);

        ITU_T_DEFAULTH_DECL(checkpointSize, integer_type, checkpointSize__default);
        ITU_T_DEFAULTH_DECL(windowSize, integer_type, windowSize__default);
        ITU_T_DEFAULTH_DECL(dialogueMode, integer_type, dialogueMode__default);
        ITU_T_HOLDERH_DECL(connectionDataRQ, ConnectionData);
        ITU_T_OPTIONAL_DECL(applicationProtocol, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // set  RTOACapdu

    struct RTOACapdu {

        static const integer_type checkpointSize__default;
        static const integer_type windowSize__default;

        RTOACapdu();

        RTOACapdu(const ConnectionData& arg__connectionDataAC);

        RTOACapdu(shared_ptr< integer_type> arg__checkpointSize,
                shared_ptr< integer_type> arg__windowSize,
                shared_ptr< ConnectionData> arg__connectionDataAC);

        ITU_T_DEFAULTH_DECL(checkpointSize, integer_type, checkpointSize__default);
        ITU_T_DEFAULTH_DECL(windowSize, integer_type, windowSize__default);
        ITU_T_HOLDERH_DECL(connectionDataAC, ConnectionData);

        ITU_T_ARCHIVE_FUNC;
    };

    // set  RTORJapdu

    struct RTORJapdu {

        RTORJapdu();

        RTORJapdu(shared_ptr< RefuseReason> arg__refuseReason,
                shared_ptr< any_type> arg__userDataRJ);

        ITU_T_OPTIONAL_DECL(refuseReason, RefuseReason);
        ITU_T_OPTIONAL_DECL(userDataRJ, any_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // set  RTABapdu

    struct RTABapdu {

        RTABapdu();

        RTABapdu(shared_ptr< AbortReason> arg__abortReason,
                shared_ptr< bit_string> arg__reflectedParameter,
                shared_ptr< any_type> arg__userdataAB);

        ITU_T_OPTIONAL_DECL(abortReason, AbortReason);
        ITU_T_OPTIONAL_DECL(reflectedParameter, bit_string);
        ITU_T_OPTIONAL_DECL(userdataAB, any_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ConnectionData

    enum ConnectionData_enum {

        ConnectionData_null = 0,
        ConnectionData_open,
        ConnectionData_recover,
    };

    struct ConnectionData : public ITU_T_CHOICE(ConnectionData_enum) {


        ITU_T_CHOICE_CTORS(ConnectionData);

        ITU_T_CHOICES_DECL(open, any_type, ConnectionData_open); // primitive
        ITU_T_CHOICEC_DECL(recover, SessionConnectionIdentifier, ConnectionData_recover);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence SessionConnectionIdentifier

    struct SessionConnectionIdentifier {

        SessionConnectionIdentifier();

        SessionConnectionIdentifier(const CallingSSuserReference& arg__callingSSuserReference,
                const CommonReference& arg__commonReference);

        SessionConnectionIdentifier(shared_ptr< CallingSSuserReference> arg__callingSSuserReference,
                shared_ptr< CommonReference> arg__commonReference,
                shared_ptr< AdditionalReferenceInformation> arg__additionalReferenceInformation);

        ITU_T_HOLDERH_DECL(callingSSuserReference, CallingSSuserReference);
        ITU_T_HOLDERH_DECL(commonReference, CommonReference);
        ITU_T_OPTIONAL_DECL(additionalReferenceInformation, AdditionalReferenceInformation);

        ITU_T_ARCHIVE_FUNC;
    };

    const RefuseReason refuseReason_rtsBusy = 0;
    const RefuseReason refuseReason_cannotRecover = 1;
    const RefuseReason refuseReason_validationFailure = 2;
    const RefuseReason refuseReason_unacceptableDialogueMode = 3;

    // choice CallingSSuserReference

    enum CallingSSuserReference_enum {

        CallingSSuserReference_null = 0,
        CallingSSuserReference_t61String,
        CallingSSuserReference_octetString,
    };

    struct CallingSSuserReference : public ITU_T_CHOICE(CallingSSuserReference_enum) {


        ITU_T_CHOICE_CTORS(CallingSSuserReference);

        ITU_T_CHOICES_DECL(t61String, t61_string, CallingSSuserReference_t61String); // primitive
        ITU_T_CHOICES_DECL(octetString, octet_string, CallingSSuserReference_octetString); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    const AbortReason abortReason_localSystemProblem = 0;
    const AbortReason abortReason_invalidParameter = 1;
    const AbortReason abortReason_unrecognizedActivity = 2;
    const AbortReason abortReason_temporaryProblem = 3;
    const AbortReason abortReason_protocolError = 4;
    const AbortReason abortReason_permanentProblem = 5;
    const AbortReason abortReason_userError = 6;
    const AbortReason abortReason_transferCompleted = 7;

    ITU_T_ARCHIVE_X690_DECL(RTSE_apdus);
    ITU_T_ARCHIVE_X690_DECL(RTORQapdu);
    ITU_T_ARCHIVE_X690_DECL(RTOACapdu);
    ITU_T_ARCHIVE_X690_DECL(RTORJapdu);
    ITU_T_ARCHIVE_X690_DECL(RTABapdu);
    ITU_T_ARCHIVE_X690_DECL(ConnectionData);
    ITU_T_ARCHIVE_X690_DECL(SessionConnectionIdentifier);
    ITU_T_ARCHIVE_X690_DECL(CallingSSuserReference);

    ITU_T_ARCHIVE_X691_DECL(RTSE_apdus);
    ITU_T_ARCHIVE_X691_DECL(RTORQapdu);
    ITU_T_ARCHIVE_X691_DECL(RTOACapdu);
    ITU_T_ARCHIVE_X691_DECL(RTORJapdu);
    ITU_T_ARCHIVE_X691_DECL(RTABapdu);
    ITU_T_ARCHIVE_X691_DECL(ConnectionData);
    ITU_T_ARCHIVE_X691_DECL(SessionConnectionIdentifier);
    ITU_T_ARCHIVE_X691_DECL(CallingSSuserReference);

}

ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTORQapdu)
ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTOACapdu)
ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTORJapdu)
ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTABapdu)

ITU_T_CHOICE_REGESTRATE(Reliable_Transfer_APDU::RTSE_apdus)
ITU_T_CHOICE_REGESTRATE(Reliable_Transfer_APDU::ConnectionData)
ITU_T_CHOICE_REGESTRATE(Reliable_Transfer_APDU::CallingSSuserReference)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___RELIABLE_TRANSFER_APDU */
