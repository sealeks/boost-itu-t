#ifndef ___RELIABLE_TRANSFER_APDU
#define ___RELIABLE_TRANSFER_APDU

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {

    using boost::asn1::null_type;
    using boost::asn1::enumerated_type;
    using boost::asn1::bitstring_type;
    using boost::asn1::octetstring_type;
    using boost::asn1::oid_type;
    using boost::asn1::reloid_type;
    using boost::asn1::utctime_type;
    using boost::asn1::gentime_type;
    using boost::asn1::ia5string_type;
    using boost::asn1::printablestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::numericstring_type;
    using boost::asn1::universalstring_type;
    using boost::asn1::bmpstring_type;
    using boost::asn1::utf8string_type;
    using boost::asn1::generalstring_type;
    using boost::asn1::graphicstring_type;
    using boost::asn1::t61string_type;
    using boost::asn1::t61string_type;
    using boost::asn1::videotexstring_type;
    using boost::asn1::objectdescriptor_type;
    using boost::asn1::external_type;
    using boost::asn1::embeded_type;
    using boost::asn1::characterstring_type;
    using boost::asn1::any_type;
    using boost::asn1::value_holder;
    using boost::asn1::default_holder;


    struct RTSE_apdus;
    struct RTORQapdu;
    struct RTOACapdu;
    struct RTORJapdu;
    struct RTABapdu;
    struct ConnectionData;
    struct SessionConnectionIdentifier;
    struct CallingSSuserReference;


    typedef int RTTPapdu;
    typedef octetstring_type RTTRapdu;
    typedef int RefuseReason;
    typedef utctime_type CommonReference;
    typedef t61string_type AdditionalReferenceInformation;
    typedef int AbortReason;

    extern const oid_type rTSE_abstract_syntax;

}

#include <boost/itu/x22X/presentation/Remote-Operations-Information-Objects.hpp>

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

    struct RTSE_apdus : public ITU_T_CHOICE_STRUCT(RTSE_apdus_enum) {

        RTSE_apdus() : ITU_T_CHOICE_STRUCT(RTSE_apdus_enum) () {
        }

        template<typename T > RTSE_apdus(boost::shared_ptr< T> vl, RTSE_apdus_enum enm) :
                ITU_T_CHOICE_STRUCT(RTSE_apdus_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_VALUE_CHOICE(rtorq_apdu, RTORQapdu, RTSE_apdus_rtorq_apdu);
        ITU_T_VALUE_CHOICE(rtoac_apdu, RTOACapdu, RTSE_apdus_rtoac_apdu);
        ITU_T_VALUE_CHOICE(rtorj_apdu, RTORJapdu, RTSE_apdus_rtorj_apdu);
        ITU_T_VALUE_CHOICE(rttp_apdu, RTTPapdu, RTSE_apdus_rttp_apdu);
        ITU_T_VALUE_CHOICE(rttr_apdu, RTTRapdu, RTSE_apdus_rttr_apdu);
        ITU_T_VALUE_CHOICE(rtab_apdu, RTABapdu, RTSE_apdus_rtab_apdu);

        ITU_T_ARCHIVE_FUNC;
    };

    // set RTORQapdu

    struct RTORQapdu {

        static const int dialogueMode_monologue;
        static const int dialogueMode_twa;

        static const int checkpointSize__default;
        static const int windowSize__default;
        static const int dialogueMode__default;

        RTORQapdu();

        RTORQapdu(const ConnectionData& arg__connectionDataRQ);

        RTORQapdu(boost::shared_ptr< int> arg__checkpointSize,
                boost::shared_ptr< int> arg__windowSize,
                boost::shared_ptr< int> arg__dialogueMode,
                boost::shared_ptr< ConnectionData> arg__connectionDataRQ,
                boost::shared_ptr< int> arg__applicationProtocol);

        ITU_T_VALUE_DEFAULT_DECL(checkpointSize, int, checkpointSize__default);
        ITU_T_VALUE_DEFAULT_DECL(windowSize, int, windowSize__default);
        ITU_T_VALUE_DEFAULT_DECL(dialogueMode, int, dialogueMode__default);
        ITU_T_VALUE_HOLDERH_DECL(connectionDataRQ, ConnectionData);
        ITU_T_VALUE_OPTIONAL_DECL(applicationProtocol, int);

        ITU_T_ARCHIVE_FUNC;
    };

    // set RTOACapdu

    struct RTOACapdu {

        static const int checkpointSize__default;
        static const int windowSize__default;

        RTOACapdu();

        RTOACapdu(const ConnectionData& arg__connectionDataAC);

        RTOACapdu(boost::shared_ptr< int> arg__checkpointSize,
                boost::shared_ptr< int> arg__windowSize,
                boost::shared_ptr< ConnectionData> arg__connectionDataAC);

        ITU_T_VALUE_DEFAULT_DECL(checkpointSize, int, checkpointSize__default);
        ITU_T_VALUE_DEFAULT_DECL(windowSize, int, windowSize__default);
        ITU_T_VALUE_HOLDERH_DECL(connectionDataAC, ConnectionData);

        ITU_T_ARCHIVE_FUNC;
    };

    // set RTORJapdu

    struct RTORJapdu {

        RTORJapdu();

        RTORJapdu(boost::shared_ptr< RefuseReason> arg__refuseReason,
                boost::shared_ptr< any_type> arg__userDataRJ);

        ITU_T_VALUE_OPTIONAL_DECL(refuseReason, RefuseReason);
        ITU_T_VALUE_OPTIONAL_DECL(userDataRJ, any_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // set RTABapdu

    struct RTABapdu {

        RTABapdu();

        RTABapdu(boost::shared_ptr< AbortReason> arg__abortReason,
                boost::shared_ptr< bitstring_type> arg__reflectedParameter,
                boost::shared_ptr< any_type> arg__userdataAB);

        ITU_T_VALUE_OPTIONAL_DECL(abortReason, AbortReason);
        ITU_T_VALUE_OPTIONAL_DECL(reflectedParameter, bitstring_type);
        ITU_T_VALUE_OPTIONAL_DECL(userdataAB, any_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ConnectionData

    enum ConnectionData_enum {

        ConnectionData_null = 0,
        ConnectionData_open,
        ConnectionData_recover,
    };

    struct ConnectionData : public ITU_T_CHOICE_STRUCT(ConnectionData_enum) {

        ConnectionData() : ITU_T_CHOICE_STRUCT(ConnectionData_enum) () {
        }

        template<typename T > ConnectionData(boost::shared_ptr< T> vl, ConnectionData_enum enm) :
                ITU_T_CHOICE_STRUCT(ConnectionData_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_VALUE_CHOICE(open, any_type, ConnectionData_open);
        ITU_T_VALUE_CHOICE(recover, SessionConnectionIdentifier, ConnectionData_recover);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence SessionConnectionIdentifier

    struct SessionConnectionIdentifier {

        SessionConnectionIdentifier();

        SessionConnectionIdentifier(const CallingSSuserReference& arg__callingSSuserReference,
                const CommonReference& arg__commonReference);

        SessionConnectionIdentifier(boost::shared_ptr< CallingSSuserReference> arg__callingSSuserReference,
                boost::shared_ptr< CommonReference> arg__commonReference,
                boost::shared_ptr< AdditionalReferenceInformation> arg__additionalReferenceInformation);

        ITU_T_VALUE_HOLDERH_DECL(callingSSuserReference, CallingSSuserReference);
        ITU_T_VALUE_HOLDERH_DECL(commonReference, CommonReference);
        ITU_T_VALUE_OPTIONAL_DECL(additionalReferenceInformation, AdditionalReferenceInformation);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const RefuseReason RefuseReason_rtsBusy;
    extern const RefuseReason RefuseReason_cannotRecover;
    extern const RefuseReason RefuseReason_validationFailure;
    extern const RefuseReason RefuseReason_unacceptableDialogueMode;

    // choice CallingSSuserReference

    enum CallingSSuserReference_enum {

        CallingSSuserReference_null = 0,
        CallingSSuserReference_t61String,
        CallingSSuserReference_octetString,
    };

    struct CallingSSuserReference : public ITU_T_CHOICE_STRUCT(CallingSSuserReference_enum) {

        CallingSSuserReference() : ITU_T_CHOICE_STRUCT(CallingSSuserReference_enum) () {
        }

        template<typename T > CallingSSuserReference(boost::shared_ptr< T> vl, CallingSSuserReference_enum enm) :
                ITU_T_CHOICE_STRUCT(CallingSSuserReference_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_VALUE_CHOICE(t61String, t61string_type, CallingSSuserReference_t61String);
        ITU_T_VALUE_CHOICE(octetString, octetstring_type, CallingSSuserReference_octetString);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const AbortReason AbortReason_localSystemProblem;
    extern const AbortReason AbortReason_invalidParameter;
    extern const AbortReason AbortReason_unrecognizedActivity;
    extern const AbortReason AbortReason_temporaryProblem;
    extern const AbortReason AbortReason_protocolError;
    extern const AbortReason AbortReason_permanentProblem;
    extern const AbortReason AbortReason_userError;
    extern const AbortReason AbortReason_transferCompleted;

    template<> void RTSE_apdus::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RTSE_apdus::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RTORQapdu::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RTORQapdu::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RTOACapdu::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RTOACapdu::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RTORJapdu::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RTORJapdu::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RTABapdu::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RTABapdu::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ConnectionData::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ConnectionData::serialize(boost::asn1::x690::input_coder& arch);
    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::output_coder& arch);
    template<> void SessionConnectionIdentifier::serialize(boost::asn1::x690::input_coder& arch);
    template<> void CallingSSuserReference::serialize(boost::asn1::x690::output_coder& arch);
    template<> void CallingSSuserReference::serialize(boost::asn1::x690::input_coder& arch);
}

ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTORQapdu)
ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTOACapdu)
ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTORJapdu)
ITU_T_SET_REGESTRATE(Reliable_Transfer_APDU::RTABapdu)

ITU_T_CHOICE_REGESTRATE(Reliable_Transfer_APDU::RTSE_apdus)
ITU_T_CHOICE_REGESTRATE(Reliable_Transfer_APDU::ConnectionData)
ITU_T_CHOICE_REGESTRATE(Reliable_Transfer_APDU::CallingSSuserReference)

#endif  /*___RELIABLE_TRANSFER_APDU */

