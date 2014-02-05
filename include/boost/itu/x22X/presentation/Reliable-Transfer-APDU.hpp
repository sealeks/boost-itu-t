#ifndef ___RELIABLE_TRANSFER_APDU
#define ___RELIABLE_TRANSFER_APDU

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Reliable_Transfer_APDU {

    using  boost::asn1::null_type;
    using  boost::asn1::enumerated_type;
    using  boost::asn1::bitstring_type;
    using  boost::asn1::octetstring_type;
    using  boost::asn1::oid_type;
    using  boost::asn1::reloid_type;
    using  boost::asn1::utctime_type;
    using  boost::asn1::gentime_type;
    using  boost::asn1::ia5string_type;
    using  boost::asn1::printablestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::numericstring_type;
    using  boost::asn1::universalstring_type;
    using  boost::asn1::bmpstring_type;
    using  boost::asn1::utf8string_type;
    using  boost::asn1::generalstring_type;
    using  boost::asn1::graphicstring_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::videotexstring_type;
    using  boost::asn1::objectdescriptor_type;
    using  boost::asn1::external_type;
    using  boost::asn1::embeded_type;
    using  boost::asn1::characterstring_type;
    using  boost::asn1::any_type;

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


} 
#include <boost/itu/x22X/presentation/Remote-Operations-Information-Objects.hpp>

namespace Reliable_Transfer_APDU {

  // import   from  Remote-Operations-Information-Objects




        const int AbortReason_localSystemProblem = 0;
        const int AbortReason_invalidParameter = 1;
        const int AbortReason_unrecognizedActivity = 2;
        const int AbortReason_temporaryProblem = 3;
        const int AbortReason_protocolError = 4;
        const int AbortReason_permanentProblem = 5;
        const int AbortReason_userError = 6;
        const int AbortReason_transferCompleted = 7;

        // choice CallingSSuserReference
        enum CallingSSuserReference_enum {
            CallingSSuserReference_null = 0, 
            CallingSSuserReference_t61String,
            CallingSSuserReference_octetString,}; 
 
        struct CallingSSuserReference : public BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) {


            CallingSSuserReference() :  BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(t61String, t61string_type, CallingSSuserReference_t61String);
            BOOST_ASN_VALUE_CHOICE(octetString, octetstring_type, CallingSSuserReference_octetString);

            template<typename Archive> void serialize(Archive& arch){
                if (arch.__input__()){
                    int __tag_id__ =arch.test_id();
                    switch(arch.test_class()){
                        case 0x0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x40: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x80: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0xC0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        default: {
                                 if (BOOST_ASN_BIND_TAG(value<t61string_type > (true , CallingSSuserReference_t61String))) return; else free();
                                 if (BOOST_ASN_BIND_TAG(value<octetstring_type > (true , CallingSSuserReference_octetString))) return; else free();
                        }
                    }
                } else {
                    switch(type()){
                        case CallingSSuserReference_t61String:  {BOOST_ASN_BIND_TAG(value<t61string_type > (false , CallingSSuserReference_t61String)); break; }
                        case CallingSSuserReference_octetString:  {BOOST_ASN_BIND_TAG(value<octetstring_type > (false , CallingSSuserReference_octetString)); break; }
                        default:{}
                    }
                }
            }
        }; 
 
        const int RefuseReason_rtsBusy = 0;
        const int RefuseReason_cannotRecover = 1;
        const int RefuseReason_validationFailure = 2;
        const int RefuseReason_unacceptableDialogueMode = 3;

        // sequence SessionConnectionIdentifier
        struct SessionConnectionIdentifier{


            SessionConnectionIdentifier() : callingSSuserReference(), commonReference() {} 
 
            CallingSSuserReference callingSSuserReference;
            CommonReference commonReference;
            boost::shared_ptr<AdditionalReferenceInformation> additionalReferenceInformation;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalReferenceInformation, additionalReferenceInformation)


            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_CHOICE(callingSSuserReference);
                BOOST_ASN_BIND_TAG(commonReference);
                BOOST_ASN_IMPLICIT_TAG(additionalReferenceInformation, 0);
            }
        };
 
        // choice ConnectionData
        enum ConnectionData_enum {
            ConnectionData_null = 0, 
            ConnectionData_open,
            ConnectionData_recover,}; 
 
        struct ConnectionData : public BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) {


            ConnectionData() :  BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(open, any_type, ConnectionData_open);
            BOOST_ASN_VALUE_CHOICE(recover, SessionConnectionIdentifier, ConnectionData_recover);

            template<typename Archive> void serialize(Archive& arch){
                if (arch.__input__()){
                    int __tag_id__ =arch.test_id();
                    switch(arch.test_class()){
                        case 0x0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x40: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x80: {
                            switch(__tag_id__){
                                case 0:  { if (BOOST_ASN_EXPLICIT_TAG(value<any_type > (true , ConnectionData_open), 0)) return; else free(); break;}
                                case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<SessionConnectionIdentifier > (true , ConnectionData_recover), 1)) return; else free(); break;}
                            default:{}
                            }
                        }
                        case 0xC0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        default: {
                        }
                    }
                } else {
                    switch(type()){
                        case ConnectionData_open:  {BOOST_ASN_EXPLICIT_TAG(value<any_type > (false , ConnectionData_open), 0); break; }
                        case ConnectionData_recover:  {BOOST_ASN_IMPLICIT_TAG(value<SessionConnectionIdentifier > (false , ConnectionData_recover), 1); break; }
                        default:{}
                    }
                }
            }
        }; 
 
        // set RTABapdu
        struct RTABapdu{


            RTABapdu() {} 
 
            boost::shared_ptr<AbortReason> abortReason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AbortReason, abortReason)

            boost::shared_ptr<bitstring_type> reflectedParameter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type, reflectedParameter)

            boost::shared_ptr<any_type> userdataAB;
            BOOST_ASN_VALUE_FUNC_DECLARATE(any_type, userdataAB)


            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_IMPLICIT_TAG(abortReason, 0);
                BOOST_ASN_IMPLICIT_TAG(reflectedParameter, 1);
                BOOST_ASN_EXPLICIT_TAG(userdataAB, 2);
            }
        };
 
        // set RTORJapdu
        struct RTORJapdu{


            RTORJapdu() {} 
 
            boost::shared_ptr<RefuseReason> refuseReason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(RefuseReason, refuseReason)

            boost::shared_ptr<any_type> userDataRJ;
            BOOST_ASN_VALUE_FUNC_DECLARATE(any_type, userDataRJ)


            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_IMPLICIT_TAG(refuseReason, 0);
                BOOST_ASN_EXPLICIT_TAG(userDataRJ, 1);
            }
        };
 
        // set RTOACapdu
        struct RTOACapdu{


            RTOACapdu() : connectionDataAC() {} 
 
            boost::shared_ptr<int> checkpointSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, checkpointSize)

            boost::shared_ptr<int> windowSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, windowSize)

            ConnectionData connectionDataAC;

            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
                BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
                BOOST_ASN_CHOICE_TAG(connectionDataAC, 2);
            }
        };
 
        // set RTORQapdu
        struct RTORQapdu{

            static const int dialogueMode_monologue = 0;
            static const int dialogueMode_twa = 1;


            RTORQapdu() : connectionDataRQ() {} 
 
            boost::shared_ptr<int> checkpointSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, checkpointSize)

            boost::shared_ptr<int> windowSize;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, windowSize)

            boost::shared_ptr<int> dialogueMode;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, dialogueMode)

            ConnectionData connectionDataRQ;
            boost::shared_ptr<int> applicationProtocol;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, applicationProtocol)


            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_IMPLICIT_TAG(checkpointSize, 0);
                BOOST_ASN_IMPLICIT_TAG(windowSize, 1);
                BOOST_ASN_IMPLICIT_TAG(dialogueMode, 2);
                BOOST_ASN_CHOICE_TAG(connectionDataRQ, 3);
                BOOST_ASN_IMPLICIT_TAG(applicationProtocol, 4);
            }
        };
 
        // choice RTSE-apdus
        enum RTSE_apdus_enum {
            RTSE_apdus_null = 0, 
            RTSE_apdus_rtorq_apdu,
            RTSE_apdus_rtoac_apdu,
            RTSE_apdus_rtorj_apdu,
            RTSE_apdus_rttp_apdu,
            RTSE_apdus_rttr_apdu,
            RTSE_apdus_rtab_apdu,}; 
 
        struct RTSE_apdus : public BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) {


            RTSE_apdus() :  BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(rtorq_apdu, RTORQapdu, RTSE_apdus_rtorq_apdu);
            BOOST_ASN_VALUE_CHOICE(rtoac_apdu, RTOACapdu, RTSE_apdus_rtoac_apdu);
            BOOST_ASN_VALUE_CHOICE(rtorj_apdu, RTORJapdu, RTSE_apdus_rtorj_apdu);
            BOOST_ASN_VALUE_CHOICE(rttp_apdu, RTTPapdu, RTSE_apdus_rttp_apdu);
            BOOST_ASN_VALUE_CHOICE(rttr_apdu, RTTRapdu, RTSE_apdus_rttr_apdu);
            BOOST_ASN_VALUE_CHOICE(rtab_apdu, RTABapdu, RTSE_apdus_rtab_apdu);

            template<typename Archive> void serialize(Archive& arch){
                if (arch.__input__()){
                    int __tag_id__ =arch.test_id();
                    switch(arch.test_class()){
                        case 0x0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x40: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x80: {
                            switch(__tag_id__){
                                case 16:  { if (BOOST_ASN_IMPLICIT_TAG(value<RTORQapdu > (true , RTSE_apdus_rtorq_apdu), 16)) return; else free(); break;}
                                case 17:  { if (BOOST_ASN_IMPLICIT_TAG(value<RTOACapdu > (true , RTSE_apdus_rtoac_apdu), 17)) return; else free(); break;}
                                case 18:  { if (BOOST_ASN_IMPLICIT_TAG(value<RTORJapdu > (true , RTSE_apdus_rtorj_apdu), 18)) return; else free(); break;}
                                case 22:  { if (BOOST_ASN_IMPLICIT_TAG(value<RTABapdu > (true , RTSE_apdus_rtab_apdu), 22)) return; else free(); break;}
                            default:{}
                            }
                        }
                        case 0xC0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        default: {
                                 if (BOOST_ASN_BIND_TAG(value<RTTPapdu > (true , RTSE_apdus_rttp_apdu))) return; else free();
                                 if (BOOST_ASN_BIND_TAG(value<RTTRapdu > (true , RTSE_apdus_rttr_apdu))) return; else free();
                        }
                    }
                } else {
                    switch(type()){
                        case RTSE_apdus_rtorq_apdu:  {BOOST_ASN_IMPLICIT_TAG(value<RTORQapdu > (false , RTSE_apdus_rtorq_apdu), 16); break; }
                        case RTSE_apdus_rtoac_apdu:  {BOOST_ASN_IMPLICIT_TAG(value<RTOACapdu > (false , RTSE_apdus_rtoac_apdu), 17); break; }
                        case RTSE_apdus_rtorj_apdu:  {BOOST_ASN_IMPLICIT_TAG(value<RTORJapdu > (false , RTSE_apdus_rtorj_apdu), 18); break; }
                        case RTSE_apdus_rttp_apdu:  {BOOST_ASN_BIND_TAG(value<RTTPapdu > (false , RTSE_apdus_rttp_apdu)); break; }
                        case RTSE_apdus_rttr_apdu:  {BOOST_ASN_BIND_TAG(value<RTTRapdu > (false , RTSE_apdus_rttr_apdu)); break; }
                        case RTSE_apdus_rtab_apdu:  {BOOST_ASN_IMPLICIT_TAG(value<RTABapdu > (false , RTSE_apdus_rtab_apdu), 22); break; }
                        default:{}
                    }
                }
            }
        }; 
 
    const boost::array<boost::asn1::oidindx_type, 3> rTSE_abstract_syntax_OID_ARR = { 2, 3, 2};
    const boost::asn1::oid_type rTSE_abstract_syntax  = boost::asn1::oid_type(rTSE_abstract_syntax_OID_ARR );

} 

    BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTORQapdu)
    BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTOACapdu)
    BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTORJapdu)
    BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDU::RTABapdu)

    BOOST_ASN_CHOICE_REGESTRATE(Reliable_Transfer_APDU::RTSE_apdus)
    BOOST_ASN_CHOICE_REGESTRATE(Reliable_Transfer_APDU::ConnectionData)
    BOOST_ASN_CHOICE_REGESTRATE(Reliable_Transfer_APDU::CallingSSuserReference)

#endif  /*___RELIABLE_TRANSFER_APDU */
