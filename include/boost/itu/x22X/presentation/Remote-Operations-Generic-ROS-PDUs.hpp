#ifndef ___REMOTE_OPERATIONS_GENERIC_ROS_PDUS
#define ___REMOTE_OPERATIONS_GENERIC_ROS_PDUS

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Remote_Operations_Generic_ROS_PDUs {

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

    struct Reject;  
    struct InvokeId;  

    typedef int GeneralProblem;  
    typedef int InvokeProblem;  
    typedef int ReturnResultProblem;  
    typedef int ReturnErrorProblem;  
    typedef int RejectProblem;  


} 
#include <boost/itu/x22X/presentation/Remote-Operations-Information-Objects.hpp>

namespace Remote_Operations_Generic_ROS_PDUs {

  // import   from  Remote-Operations-Information-Objects




        // choice InvokeId
        enum InvokeId_enum {
            InvokeId_null = 0, 
            InvokeId_present,
            InvokeId_absent,}; 
 
        struct InvokeId : public BOOST_ASN_CHOICE_STRUCT(InvokeId_enum) {


            InvokeId() :  BOOST_ASN_CHOICE_STRUCT(InvokeId_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(present, int, InvokeId_present);
            BOOST_ASN_VALUE_CHOICE(absent, null_type, InvokeId_absent);

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
                                 if (BOOST_ASN_BIND_TAG(value<int > (true , InvokeId_present))) return; else free();
                                 if (BOOST_ASN_BIND_TAG(value<null_type > (true , InvokeId_absent))) return; else free();
                        }
                    }
                } else {
                    switch(type()){
                        case InvokeId_present:  {BOOST_ASN_BIND_TAG(value<int > (false , InvokeId_present)); break; }
                        case InvokeId_absent:  {BOOST_ASN_BIND_TAG(value<null_type > (false , InvokeId_absent)); break; }
                        default:{}
                    }
                }
            }
        }; 
 
        const int RejectProblem_general_unrecognizedPDU = 0;
        const int RejectProblem_general_mistypedPDU = 1;
        const int RejectProblem_general_badlyStructuredPDU = 2;
        const int RejectProblem_invoke_duplicateInvocation = 10;
        const int RejectProblem_invoke_unrecognizedOperation = 11;
        const int RejectProblem_invoke_mistypedArgument = 12;
        const int RejectProblem_invoke_resourceLimitation = 13;
        const int RejectProblem_invoke_releaseInProgress = 14;
        const int RejectProblem_invoke_unrecognizedLinkedId = 15;
        const int RejectProblem_invoke_linkedResponseUnexpected = 16;
        const int RejectProblem_invoke_unexpectedLinkedOperation = 17;
        const int RejectProblem_returnResult_unrecognizedInvocation = 20;
        const int RejectProblem_returnResult_resultResponseUnexpected = 21;
        const int RejectProblem_returnResult_mistypedResult = 22;
        const int RejectProblem_returnError_unrecognizedInvocation = 30;
        const int RejectProblem_returnError_errorResponseUnexpected = 31;
        const int RejectProblem_returnError_unrecognizedError = 32;
        const int RejectProblem_returnError_unexpectedError = 33;
        const int RejectProblem_returnError_mistypedParameter = 34;

        const int ReturnErrorProblem_unrecognizedInvocation = 0;
        const int ReturnErrorProblem_errorResponseUnexpected = 1;
        const int ReturnErrorProblem_unrecognizedError = 2;
        const int ReturnErrorProblem_unexpectedError = 3;
        const int ReturnErrorProblem_mistypedParameter = 4;

        const int ReturnResultProblem_unrecognizedInvocation = 0;
        const int ReturnResultProblem_resultResponseUnexpected = 1;
        const int ReturnResultProblem_mistypedResult = 2;

        const int InvokeProblem_duplicateInvocation = 0;
        const int InvokeProblem_unrecognizedOperation = 1;
        const int InvokeProblem_mistypedArgument = 2;
        const int InvokeProblem_resourceLimitation = 3;
        const int InvokeProblem_releaseInProgress = 4;
        const int InvokeProblem_unrecognizedLinkedId = 5;
        const int InvokeProblem_linkedResponseUnexpected = 6;
        const int InvokeProblem_unexpectedLinkedOperation = 7;

        const int GeneralProblem_unrecognizedPDU = 0;
        const int GeneralProblem_mistypedPDU = 1;
        const int GeneralProblem_badlyStructuredPDU = 2;

        // sequence Reject
        struct Reject{

            enum problem_type_enum {
                problem_type_null = 0, 
                problem_type_general,
                problem_type_invoke,
                problem_type_returnResult,
                problem_type_returnError,}; 
 
            struct problem_type : public BOOST_ASN_CHOICE_STRUCT(problem_type_enum) {


                problem_type() :  BOOST_ASN_CHOICE_STRUCT(problem_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(general, GeneralProblem, problem_type_general);
                BOOST_ASN_VALUE_CHOICE(invoke, InvokeProblem, problem_type_invoke);
                BOOST_ASN_VALUE_CHOICE(returnResult, ReturnResultProblem, problem_type_returnResult);
                BOOST_ASN_VALUE_CHOICE(returnError, ReturnErrorProblem, problem_type_returnError);

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
                                    case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<GeneralProblem > (true , problem_type_general), 0)) return; else free(); break;}
                                    case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<InvokeProblem > (true , problem_type_invoke), 1)) return; else free(); break;}
                                    case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReturnResultProblem > (true , problem_type_returnResult), 2)) return; else free(); break;}
                                    case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReturnErrorProblem > (true , problem_type_returnError), 3)) return; else free(); break;}
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
                            case problem_type_general:  {BOOST_ASN_IMPLICIT_TAG(value<GeneralProblem > (false , problem_type_general), 0); break; }
                            case problem_type_invoke:  {BOOST_ASN_IMPLICIT_TAG(value<InvokeProblem > (false , problem_type_invoke), 1); break; }
                            case problem_type_returnResult:  {BOOST_ASN_IMPLICIT_TAG(value<ReturnResultProblem > (false , problem_type_returnResult), 2); break; }
                            case problem_type_returnError:  {BOOST_ASN_IMPLICIT_TAG(value<ReturnErrorProblem > (false , problem_type_returnError), 3); break; }
                            default:{}
                        }
                    }
                }
            }; 
 


            Reject() : invokeId(), problem() {} 
 
            InvokeId invokeId;
            problem_type problem;

            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_CHOICE(invokeId);
                BOOST_ASN_CHOICE(problem);
            }
        };
 
} 


    BOOST_ASN_CHOICE_REGESTRATE(Remote_Operations_Generic_ROS_PDUs::Reject::problem_type)
    BOOST_ASN_CHOICE_REGESTRATE(Remote_Operations_Generic_ROS_PDUs::InvokeId)

#endif  /*___REMOTE_OPERATIONS_GENERIC_ROS_PDUS */
