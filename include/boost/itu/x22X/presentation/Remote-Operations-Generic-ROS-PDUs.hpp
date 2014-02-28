#ifndef ___REMOTE_OPERATIONS_GENERIC_ROS_PDUS
#define ___REMOTE_OPERATIONS_GENERIC_ROS_PDUS

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Remote_Operations_Generic_ROS_PDUs {

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



    // sequence Reject

    struct Reject {

        struct problem_type;

        enum problem_type_enum {

            problem_type_null = 0,
            problem_type_general,
            problem_type_invoke,
            problem_type_returnResult,
            problem_type_returnError,
        };

        struct problem_type : public BOOST_ASN_CHOICE_STRUCT(problem_type_enum) {

            problem_type() : BOOST_ASN_CHOICE_STRUCT(problem_type_enum) () {
            }

            template<typename T > problem_type(boost::shared_ptr< T> vl, problem_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(problem_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(general, GeneralProblem, problem_type_general);
            BOOST_ASN_VALUE_CHOICE(invoke, InvokeProblem, problem_type_invoke);
            BOOST_ASN_VALUE_CHOICE(returnResult, ReturnResultProblem, problem_type_returnResult);
            BOOST_ASN_VALUE_CHOICE(returnError, ReturnErrorProblem, problem_type_returnError);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Reject();

        Reject(const InvokeId& arg__invokeId,
                const problem_type& arg__problem);

        BOOST_ASN_VALUE_HOLDERH_DECL(invokeId, InvokeId);
        BOOST_ASN_VALUE_HOLDERH_DECL(problem, problem_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<InvokeId> invokeId_;
        value_holder<problem_type> problem_;
    };

    extern const GeneralProblem GeneralProblem_unrecognizedPDU;
    extern const GeneralProblem GeneralProblem_mistypedPDU;
    extern const GeneralProblem GeneralProblem_badlyStructuredPDU;

    extern const InvokeProblem InvokeProblem_duplicateInvocation;
    extern const InvokeProblem InvokeProblem_unrecognizedOperation;
    extern const InvokeProblem InvokeProblem_mistypedArgument;
    extern const InvokeProblem InvokeProblem_resourceLimitation;
    extern const InvokeProblem InvokeProblem_releaseInProgress;
    extern const InvokeProblem InvokeProblem_unrecognizedLinkedId;
    extern const InvokeProblem InvokeProblem_linkedResponseUnexpected;
    extern const InvokeProblem InvokeProblem_unexpectedLinkedOperation;

    extern const ReturnResultProblem ReturnResultProblem_unrecognizedInvocation;
    extern const ReturnResultProblem ReturnResultProblem_resultResponseUnexpected;
    extern const ReturnResultProblem ReturnResultProblem_mistypedResult;

    extern const ReturnErrorProblem ReturnErrorProblem_unrecognizedInvocation;
    extern const ReturnErrorProblem ReturnErrorProblem_errorResponseUnexpected;
    extern const ReturnErrorProblem ReturnErrorProblem_unrecognizedError;
    extern const ReturnErrorProblem ReturnErrorProblem_unexpectedError;
    extern const ReturnErrorProblem ReturnErrorProblem_mistypedParameter;

    extern const RejectProblem RejectProblem_general_unrecognizedPDU;
    extern const RejectProblem RejectProblem_general_mistypedPDU;
    extern const RejectProblem RejectProblem_general_badlyStructuredPDU;
    extern const RejectProblem RejectProblem_invoke_duplicateInvocation;
    extern const RejectProblem RejectProblem_invoke_unrecognizedOperation;
    extern const RejectProblem RejectProblem_invoke_mistypedArgument;
    extern const RejectProblem RejectProblem_invoke_resourceLimitation;
    extern const RejectProblem RejectProblem_invoke_releaseInProgress;
    extern const RejectProblem RejectProblem_invoke_unrecognizedLinkedId;
    extern const RejectProblem RejectProblem_invoke_linkedResponseUnexpected;
    extern const RejectProblem RejectProblem_invoke_unexpectedLinkedOperation;
    extern const RejectProblem RejectProblem_returnResult_unrecognizedInvocation;
    extern const RejectProblem RejectProblem_returnResult_resultResponseUnexpected;
    extern const RejectProblem RejectProblem_returnResult_mistypedResult;
    extern const RejectProblem RejectProblem_returnError_unrecognizedInvocation;
    extern const RejectProblem RejectProblem_returnError_errorResponseUnexpected;
    extern const RejectProblem RejectProblem_returnError_unrecognizedError;
    extern const RejectProblem RejectProblem_returnError_unexpectedError;
    extern const RejectProblem RejectProblem_returnError_mistypedParameter;

    // choice InvokeId

    enum InvokeId_enum {

        InvokeId_null = 0,
        InvokeId_present,
        InvokeId_absent,
    };

    struct InvokeId : public BOOST_ASN_CHOICE_STRUCT(InvokeId_enum) {

        InvokeId() : BOOST_ASN_CHOICE_STRUCT(InvokeId_enum) () {
        }

        template<typename T > InvokeId(boost::shared_ptr< T> vl, InvokeId_enum enm) :
                BOOST_ASN_CHOICE_STRUCT(InvokeId_enum) (vl, static_cast<int> (enm)) {
        }

        BOOST_ASN_VALUE_CHOICE(present, int, InvokeId_present);
        BOOST_ASN_VALUE_CHOICE(absent, null_type, InvokeId_absent);

        BOOST_ASN_ARCHIVE_FUNC;
    };

    template<> void Reject::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Reject::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Reject::problem_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Reject::problem_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void InvokeId::serialize(boost::asn1::x690::output_coder& arch);
    template<> void InvokeId::serialize(boost::asn1::x690::input_coder& arch);
}

BOOST_ASN_CHOICE_REGESTRATE(Remote_Operations_Generic_ROS_PDUs::Reject::problem_type)
BOOST_ASN_CHOICE_REGESTRATE(Remote_Operations_Generic_ROS_PDUs::InvokeId)

#endif  /*___REMOTE_OPERATIONS_GENERIC_ROS_PDUS */

