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

        struct Problem_type;

        enum Problem_type_enum {

            Problem_type_null = 0,
            Problem_type_general,
            Problem_type_invoke,
            Problem_type_returnResult,
            Problem_type_returnError,
        };

        struct Problem_type : public ITU_T_CHOICE(Problem_type_enum) {

            Problem_type() : ITU_T_CHOICE(Problem_type_enum) () {
            }

            template<typename T > Problem_type(boost::shared_ptr< T> vl, Problem_type_enum enm) :
                    ITU_T_CHOICE(Problem_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Problem_type(const T& vl, Problem_type_enum enm) :
                    ITU_T_CHOICE(Problem_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

            ITU_T_CHOICES_DECL(general, GeneralProblem, Problem_type_general); // primitive
            ITU_T_CHOICES_DECL(invoke, InvokeProblem, Problem_type_invoke); // primitive
            ITU_T_CHOICES_DECL(returnResult, ReturnResultProblem, Problem_type_returnResult); // primitive
            ITU_T_CHOICES_DECL(returnError, ReturnErrorProblem, Problem_type_returnError); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        Reject();

        Reject(const InvokeId& arg__invokeId,
                const Problem_type& arg__problem);

        ITU_T_HOLDERH_DECL(invokeId, InvokeId);
        ITU_T_HOLDERH_DECL(problem, Problem_type);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const GeneralProblem generalProblem_unrecognizedPDU;
    extern const GeneralProblem generalProblem_mistypedPDU;
    extern const GeneralProblem generalProblem_badlyStructuredPDU;

    extern const InvokeProblem invokeProblem_duplicateInvocation;
    extern const InvokeProblem invokeProblem_unrecognizedOperation;
    extern const InvokeProblem invokeProblem_mistypedArgument;
    extern const InvokeProblem invokeProblem_resourceLimitation;
    extern const InvokeProblem invokeProblem_releaseInProgress;
    extern const InvokeProblem invokeProblem_unrecognizedLinkedId;
    extern const InvokeProblem invokeProblem_linkedResponseUnexpected;
    extern const InvokeProblem invokeProblem_unexpectedLinkedOperation;

    extern const ReturnResultProblem returnResultProblem_unrecognizedInvocation;
    extern const ReturnResultProblem returnResultProblem_resultResponseUnexpected;
    extern const ReturnResultProblem returnResultProblem_mistypedResult;

    extern const ReturnErrorProblem returnErrorProblem_unrecognizedInvocation;
    extern const ReturnErrorProblem returnErrorProblem_errorResponseUnexpected;
    extern const ReturnErrorProblem returnErrorProblem_unrecognizedError;
    extern const ReturnErrorProblem returnErrorProblem_unexpectedError;
    extern const ReturnErrorProblem returnErrorProblem_mistypedParameter;

    extern const RejectProblem rejectProblem_general_unrecognizedPDU;
    extern const RejectProblem rejectProblem_general_mistypedPDU;
    extern const RejectProblem rejectProblem_general_badlyStructuredPDU;
    extern const RejectProblem rejectProblem_invoke_duplicateInvocation;
    extern const RejectProblem rejectProblem_invoke_unrecognizedOperation;
    extern const RejectProblem rejectProblem_invoke_mistypedArgument;
    extern const RejectProblem rejectProblem_invoke_resourceLimitation;
    extern const RejectProblem rejectProblem_invoke_releaseInProgress;
    extern const RejectProblem rejectProblem_invoke_unrecognizedLinkedId;
    extern const RejectProblem rejectProblem_invoke_linkedResponseUnexpected;
    extern const RejectProblem rejectProblem_invoke_unexpectedLinkedOperation;
    extern const RejectProblem rejectProblem_returnResult_unrecognizedInvocation;
    extern const RejectProblem rejectProblem_returnResult_resultResponseUnexpected;
    extern const RejectProblem rejectProblem_returnResult_mistypedResult;
    extern const RejectProblem rejectProblem_returnError_unrecognizedInvocation;
    extern const RejectProblem rejectProblem_returnError_errorResponseUnexpected;
    extern const RejectProblem rejectProblem_returnError_unrecognizedError;
    extern const RejectProblem rejectProblem_returnError_unexpectedError;
    extern const RejectProblem rejectProblem_returnError_mistypedParameter;

    // choice InvokeId

    enum InvokeId_enum {

        InvokeId_null = 0,
        InvokeId_present,
        InvokeId_absent,
    };

    struct InvokeId : public ITU_T_CHOICE(InvokeId_enum) {

        InvokeId() : ITU_T_CHOICE(InvokeId_enum) () {
        }

        template<typename T > InvokeId(boost::shared_ptr< T> vl, InvokeId_enum enm) :
                ITU_T_CHOICE(InvokeId_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > InvokeId(const T& vl, InvokeId_enum enm) :
                ITU_T_CHOICE(InvokeId_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICES_DECL(present, int, InvokeId_present); // primitive
        ITU_T_CHOICES_DECL(absent, null_type, InvokeId_absent); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    template<> void Reject::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Reject::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Reject::Problem_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Reject::Problem_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void InvokeId::serialize(boost::asn1::x690::output_coder& arch);
    template<> void InvokeId::serialize(boost::asn1::x690::input_coder& arch);
}

ITU_T_CHOICE_REGESTRATE(Remote_Operations_Generic_ROS_PDUs::Reject::Problem_type)
ITU_T_CHOICE_REGESTRATE(Remote_Operations_Generic_ROS_PDUs::InvokeId)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___REMOTE_OPERATIONS_GENERIC_ROS_PDUS */
