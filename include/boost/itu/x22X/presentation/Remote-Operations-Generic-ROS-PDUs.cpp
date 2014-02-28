#include "Remote-Operations-Generic-ROS-PDUs.hpp"

namespace Remote_Operations_Generic_ROS_PDUs {

    // sequence Reject

    Reject::Reject() : invokeId_(), problem_() {
    };

    Reject::Reject(const InvokeId& a__invokeId,
            const problem_type& a__problem) :
    invokeId_(a__invokeId),
    problem_(a__problem) {
    };

    template<> void Reject::problem_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case problem_type_general:
            {
                BOOST_ASN_IMPLICIT_TAG(value<GeneralProblem > (false, problem_type_general), 0);
                break;
            }
            case problem_type_invoke:
            {
                BOOST_ASN_IMPLICIT_TAG(value<InvokeProblem > (false, problem_type_invoke), 1);
                break;
            }
            case problem_type_returnResult:
            {
                BOOST_ASN_IMPLICIT_TAG(value<ReturnResultProblem > (false, problem_type_returnResult), 2);
                break;
            }
            case problem_type_returnError:
            {
                BOOST_ASN_IMPLICIT_TAG(value<ReturnErrorProblem > (false, problem_type_returnError), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Reject::problem_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (BOOST_ASN_IMPLICIT_TAG(value<GeneralProblem > (true, problem_type_general), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<InvokeProblem > (true, problem_type_invoke), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<ReturnResultProblem > (true, problem_type_returnResult), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (BOOST_ASN_IMPLICIT_TAG(value<ReturnErrorProblem > (true, problem_type_returnError), 3)) return;
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

    template<> void Reject::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_CHOICE(invokeId_);
        BOOST_ASN_CHOICE(problem_);
    }

    template<> void Reject::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_CHOICE(invokeId_);
        BOOST_ASN_CHOICE(problem_);
    }

    InvokeId& Reject::invokeId() {
        return *invokeId_;
    }

    const InvokeId& Reject::invokeId() const {
        return *invokeId_;
    }

    void Reject::invokeId(const InvokeId& vl) {
        invokeId_ = vl;
    }

    void Reject::invokeId(boost::shared_ptr< InvokeId> vl) {
        invokeId_ = vl;
    }

    Reject::problem_type& Reject::problem() {
        return *problem_;
    }

    const Reject::problem_type& Reject::problem() const {
        return *problem_;
    }

    void Reject::problem(const problem_type& vl) {
        problem_ = vl;
    }

    void Reject::problem(boost::shared_ptr< problem_type> vl) {
        problem_ = vl;
    }


    const GeneralProblem GeneralProblem_unrecognizedPDU = 0;
    const GeneralProblem GeneralProblem_mistypedPDU = 1;
    const GeneralProblem GeneralProblem_badlyStructuredPDU = 2;

    const InvokeProblem InvokeProblem_duplicateInvocation = 0;
    const InvokeProblem InvokeProblem_unrecognizedOperation = 1;
    const InvokeProblem InvokeProblem_mistypedArgument = 2;
    const InvokeProblem InvokeProblem_resourceLimitation = 3;
    const InvokeProblem InvokeProblem_releaseInProgress = 4;
    const InvokeProblem InvokeProblem_unrecognizedLinkedId = 5;
    const InvokeProblem InvokeProblem_linkedResponseUnexpected = 6;
    const InvokeProblem InvokeProblem_unexpectedLinkedOperation = 7;

    const ReturnResultProblem ReturnResultProblem_unrecognizedInvocation = 0;
    const ReturnResultProblem ReturnResultProblem_resultResponseUnexpected = 1;
    const ReturnResultProblem ReturnResultProblem_mistypedResult = 2;

    const ReturnErrorProblem ReturnErrorProblem_unrecognizedInvocation = 0;
    const ReturnErrorProblem ReturnErrorProblem_errorResponseUnexpected = 1;
    const ReturnErrorProblem ReturnErrorProblem_unrecognizedError = 2;
    const ReturnErrorProblem ReturnErrorProblem_unexpectedError = 3;
    const ReturnErrorProblem ReturnErrorProblem_mistypedParameter = 4;

    const RejectProblem RejectProblem_general_unrecognizedPDU = 0;
    const RejectProblem RejectProblem_general_mistypedPDU = 1;
    const RejectProblem RejectProblem_general_badlyStructuredPDU = 2;
    const RejectProblem RejectProblem_invoke_duplicateInvocation = 10;
    const RejectProblem RejectProblem_invoke_unrecognizedOperation = 11;
    const RejectProblem RejectProblem_invoke_mistypedArgument = 12;
    const RejectProblem RejectProblem_invoke_resourceLimitation = 13;
    const RejectProblem RejectProblem_invoke_releaseInProgress = 14;
    const RejectProblem RejectProblem_invoke_unrecognizedLinkedId = 15;
    const RejectProblem RejectProblem_invoke_linkedResponseUnexpected = 16;
    const RejectProblem RejectProblem_invoke_unexpectedLinkedOperation = 17;
    const RejectProblem RejectProblem_returnResult_unrecognizedInvocation = 20;
    const RejectProblem RejectProblem_returnResult_resultResponseUnexpected = 21;
    const RejectProblem RejectProblem_returnResult_mistypedResult = 22;
    const RejectProblem RejectProblem_returnError_unrecognizedInvocation = 30;
    const RejectProblem RejectProblem_returnError_errorResponseUnexpected = 31;
    const RejectProblem RejectProblem_returnError_unrecognizedError = 32;
    const RejectProblem RejectProblem_returnError_unexpectedError = 33;
    const RejectProblem RejectProblem_returnError_mistypedParameter = 34;

    // choice InvokeId

    template<> void InvokeId::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case InvokeId_present:
            {
                BOOST_ASN_BIND_TAG(value<int > (false, InvokeId_present));
                break;
            }
            case InvokeId_absent:
            {
                BOOST_ASN_BIND_TAG(value<null_type > (false, InvokeId_absent));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void InvokeId::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (BOOST_ASN_BIND_TAG(value<int > (true, InvokeId_present))) return;
                else free();
                if (BOOST_ASN_BIND_TAG(value<null_type > (true, InvokeId_absent))) return;
                else free();
            }
        }
    }


}
