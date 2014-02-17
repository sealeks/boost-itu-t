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



    extern const int AbortReason_localSystemProblem;
    extern const int AbortReason_invalidParameter;
    extern const int AbortReason_unrecognizedActivity;
    extern const int AbortReason_temporaryProblem;
    extern const int AbortReason_protocolError;
    extern const int AbortReason_permanentProblem;
    extern const int AbortReason_userError;
    extern const int AbortReason_transferCompleted;

    // choice CallingSSuserReference

    enum CallingSSuserReference_enum {

        CallingSSuserReference_null = 0,
        CallingSSuserReference_t61String,
        CallingSSuserReference_octetString,
    };

    struct CallingSSuserReference : public BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) {

        CallingSSuserReference() : BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) () {
        }

        template<typename T > CallingSSuserReference(boost::shared_ptr< T> vl, CallingSSuserReference_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(t61String, t61string_type, CallingSSuserReference_t61String);
        BOOST_ASN_VALUE_CHOICE(octetString, octetstring_type, CallingSSuserReference_octetString);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    extern const int RefuseReason_rtsBusy;
    extern const int RefuseReason_cannotRecover;
    extern const int RefuseReason_validationFailure;
    extern const int RefuseReason_unacceptableDialogueMode;

    // sequence SessionConnectionIdentifier

    struct SessionConnectionIdentifier {

        SessionConnectionIdentifier();

        SessionConnectionIdentifier(const CallingSSuserReference& __callingSSuserReference,
                const CommonReference& __commonReference);

        SessionConnectionIdentifier(boost::shared_ptr< CallingSSuserReference> __callingSSuserReference,
                boost::shared_ptr< CommonReference> __commonReference,
                boost::shared_ptr< AdditionalReferenceInformation> __additionalReferenceInformation);

        CallingSSuserReference callingSSuserReference;
        CommonReference commonReference;
        boost::shared_ptr<AdditionalReferenceInformation> additionalReferenceInformation;
        BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalReferenceInformation, additionalReferenceInformation)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // choice ConnectionData

    enum ConnectionData_enum {

        ConnectionData_null = 0,
        ConnectionData_open,
        ConnectionData_recover,
    };

    struct ConnectionData : public BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) {

        ConnectionData() : BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) () {
        }

        template<typename T > ConnectionData(boost::shared_ptr< T> vl, ConnectionData_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(open, any_type, ConnectionData_open);
        BOOST_ASN_VALUE_CHOICE(recover, SessionConnectionIdentifier, ConnectionData_recover);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set RTABapdu

    struct RTABapdu {

        RTABapdu();

        RTABapdu(boost::shared_ptr< AbortReason> __abortReason,
                boost::shared_ptr< bitstring_type> __reflectedParameter,
                boost::shared_ptr< any_type> __userdataAB);

        boost::shared_ptr<AbortReason> abortReason;
        BOOST_ASN_VALUE_FUNC_DECLARATE(AbortReason, abortReason)

        boost::shared_ptr<bitstring_type> reflectedParameter;
        BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type, reflectedParameter)

        boost::shared_ptr<any_type> userdataAB;
        BOOST_ASN_VALUE_FUNC_DECLARATE(any_type, userdataAB)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set RTORJapdu

    struct RTORJapdu {

        RTORJapdu();

        RTORJapdu(boost::shared_ptr< RefuseReason> __refuseReason,
                boost::shared_ptr< any_type> __userDataRJ);

        boost::shared_ptr<RefuseReason> refuseReason;
        BOOST_ASN_VALUE_FUNC_DECLARATE(RefuseReason, refuseReason)

        boost::shared_ptr<any_type> userDataRJ;
        BOOST_ASN_VALUE_FUNC_DECLARATE(any_type, userDataRJ)


        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set RTOACapdu

    struct RTOACapdu {

        RTOACapdu();

        RTOACapdu(const ConnectionData& __connectionDataAC);

        RTOACapdu(boost::shared_ptr< int> __checkpointSize,
                boost::shared_ptr< int> __windowSize,
                boost::shared_ptr< ConnectionData> __connectionDataAC);

        boost::shared_ptr<int> checkpointSize;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, checkpointSize)

        boost::shared_ptr<int> windowSize;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, windowSize)

        ConnectionData connectionDataAC;

        BOOST_ASN_ARCHIVE_FUNC;
    };

    // set RTORQapdu

    struct RTORQapdu {

        static const int dialogueMode_monologue;
        static const int dialogueMode_twa;


        RTORQapdu();

        RTORQapdu(const ConnectionData& __connectionDataRQ);

        RTORQapdu(boost::shared_ptr< int> __checkpointSize,
                boost::shared_ptr< int> __windowSize,
                boost::shared_ptr< int> __dialogueMode,
                boost::shared_ptr< ConnectionData> __connectionDataRQ,
                boost::shared_ptr< int> __applicationProtocol);

        boost::shared_ptr<int> checkpointSize;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, checkpointSize)

        boost::shared_ptr<int> windowSize;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, windowSize)

        boost::shared_ptr<int> dialogueMode;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, dialogueMode)

        ConnectionData connectionDataRQ;
        boost::shared_ptr<int> applicationProtocol;
        BOOST_ASN_VALUE_FUNC_DECLARATE(int, applicationProtocol)


        BOOST_ASN_ARCHIVE_FUNC;
    };

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

    struct RTSE_apdus : public BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) {

        RTSE_apdus() : BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) () {
        }

        template<typename T > RTSE_apdus(boost::shared_ptr< T> vl, RTSE_apdus_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(rtorq_apdu, RTORQapdu, RTSE_apdus_rtorq_apdu);
        BOOST_ASN_VALUE_CHOICE(rtoac_apdu, RTOACapdu, RTSE_apdus_rtoac_apdu);
        BOOST_ASN_VALUE_CHOICE(rtorj_apdu, RTORJapdu, RTSE_apdus_rtorj_apdu);
        BOOST_ASN_VALUE_CHOICE(rttp_apdu, RTTPapdu, RTSE_apdus_rttp_apdu);
        BOOST_ASN_VALUE_CHOICE(rttr_apdu, RTTRapdu, RTSE_apdus_rttr_apdu);
        BOOST_ASN_VALUE_CHOICE(rtab_apdu, RTABapdu, RTSE_apdus_rtab_apdu);

        BOOST_ASN_ARCHIVE_FUNC;
    };

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

BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTORQapdu)
BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTOACapdu)
BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTORJapdu)
BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTABapdu)

BOOST_ASN_CHOICE_REGESTRATE(Reliable_Transfer_APDU::RTSE_apdus)
BOOST_ASN_CHOICE_REGESTRATE(Reliable_Transfer_APDU::ConnectionData)
BOOST_ASN_CHOICE_REGESTRATE(Reliable_Transfer_APDU::CallingSSuserReference)

#endif  /*___RELIABLE_TRANSFER_APDU */

