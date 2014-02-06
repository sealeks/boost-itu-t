#include "Remote-Operations-Generic-ROS-PDUs.hpp"

namespace Remote_Operations_Generic_ROS_PDUs {

        // choice InvokeId

    template<> void InvokeId::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case InvokeId_present:  {BOOST_ASN_BIND_TAG(value<int > (false , InvokeId_present)); break; }
                case InvokeId_absent:  {BOOST_ASN_BIND_TAG(value<null_type > (false , InvokeId_absent)); break; }
                default:{}
        }
    }

    template<> void InvokeId::serialize(boost::asn1::x690::input_coder& arch){
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
    }

 
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


    template<> void Reject::problem_type::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case problem_type_general:  {BOOST_ASN_IMPLICIT_TAG(value<GeneralProblem > (false , problem_type_general), 0); break; }
                case problem_type_invoke:  {BOOST_ASN_IMPLICIT_TAG(value<InvokeProblem > (false , problem_type_invoke), 1); break; }
                case problem_type_returnResult:  {BOOST_ASN_IMPLICIT_TAG(value<ReturnResultProblem > (false , problem_type_returnResult), 2); break; }
                case problem_type_returnError:  {BOOST_ASN_IMPLICIT_TAG(value<ReturnErrorProblem > (false , problem_type_returnError), 3); break; }
                default:{}
        }
    }

    template<> void Reject::problem_type::serialize(boost::asn1::x690::input_coder& arch){
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
    }

 

    template<> void Reject::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_CHOICE(invokeId);
        BOOST_ASN_CHOICE(problem);
    }

    template<> void Reject::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_CHOICE(invokeId);
        BOOST_ASN_CHOICE(problem);
    }

 
} 
