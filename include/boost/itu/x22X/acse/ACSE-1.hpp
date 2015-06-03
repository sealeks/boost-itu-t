#ifndef ___ACSE_1
#define ___ACSE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {

    ITU_T_USE_UNIVESAL_DECL;


    struct ACSE_apdu;
    struct AARQ_apdu;
    struct AARE_apdu;
    struct RLRQ_apdu;
    struct RLRE_apdu;
    struct ABRT_apdu;
    struct A_DT_apdu;
    struct ACRQ_apdu;
    struct ACRP_apdu;
    struct AP_title;
    struct ASO_qualifier;
    struct AE_title;
    struct Syntactic_context_list;
    struct Associate_source_diagnostic;
    struct User_Data;
    struct PDV_list;
    struct Authentication_value;
    struct ASOI_tag_sequence_of;
    struct Context_list_sequence_of;
    struct Default_Context_List_sequence_of;
    struct P_context_result_list_sequence_of;


    typedef enumerated_type ABRT_diagnostic;
    typedef integer_type ABRT_source; //   Ic(  [ 0  ...   1 ]   ...ext...) 
    typedef bitstring_type ACSE_requirements;
    typedef oid_type ASO_context_name;
    typedef octetstring_type AP_title_form1;
    typedef octetstring_type ASO_qualifier_form1;
    typedef oid_type AP_title_form2;
    typedef integer_type ASO_qualifier_form2;
    typedef printablestring_type AP_title_form3;
    typedef printablestring_type ASO_qualifier_form3;
    typedef octetstring_type AE_title_form1;
    typedef oid_type AE_title_form2;
    typedef integer_type AE_invocation_identifier;
    typedef integer_type AP_invocation_identifier;
    typedef integer_type ASOI_identifier; //   Ic(  [ 1  ...   128 ]   ...ext...) 
    typedef oid_type Abstract_syntax_name;
    typedef integer_type Result;
    typedef oid_type Transfer_syntax_name;
    typedef integer_type Associate_result; //   Ic(  [ 0  ...   2 ]   ...ext...) 
    typedef octetstring_type Simply_encoded_data;
    typedef integer_type Presentation_context_identifier;
    typedef graphicstring_type Implementation_data;
    typedef oid_type Mechanism_name;
    typedef integer_type Release_request_reason; //   Ic(  [ 0  ...   30 ]   ...ext...) 
    typedef integer_type Release_response_reason; //   Ic(  [ 0  ...   30 ]   ...ext...) 
    typedef sequence_of< external_type > Association_data; //    Sc (  [ 1 ]   ...ext...) 

    typedef ASO_context_name Application_context_name;
    typedef ASO_qualifier AE_qualifier;
    typedef Transfer_syntax_name Concrete_syntax_name;
    typedef Association_data User_information; //    Sc (  [ 1 ]   ...ext...) 
    typedef sequence_of< ASOI_tag_sequence_of > ASOI_tag; //    Sc (  [ 0  ...   7 ]   ...ext...) 
    typedef sequence_of< ASO_context_name > ASO_context_name_list;
    typedef sequence_of< Context_list_sequence_of > Context_list;
    typedef sequence_of< Default_Context_List_sequence_of > Default_Context_List;
    typedef sequence_of< P_context_result_list_sequence_of > P_context_result_list;
    ITU_T_PREFIXED_DECLARE(AARE_apdu, ITU_T_ARRAY(prefixed_type(1, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(RLRQ_apdu, ITU_T_ARRAY(prefixed_type(2, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(RLRE_apdu, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(ABRT_apdu, ITU_T_ARRAY(prefixed_type(4, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(A_DT_apdu, ITU_T_ARRAY(prefixed_type(5, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(ACRQ_apdu, ITU_T_ARRAY(prefixed_type(6, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(ACRP_apdu, ITU_T_ARRAY(prefixed_type(7, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(AARQ_apdu, ITU_T_ARRAY(prefixed_type(0, APPLICATION_CLASS)), false); //  initial =implicit

    ITU_T_OID(acse_as_id, ITU_T_VARRAY(2, 2, 1, 0, 1));
    ITU_T_OID(aCSE_id, ITU_T_VARRAY(2, 2, 3, 1, 1));

}


namespace ACSE_1 {


    // choice ACSE-apdu

    enum ACSE_apdu_enum {

        ACSE_apdu_null = 0,
        ACSE_apdu_aarq,
        ACSE_apdu_aare,
        ACSE_apdu_rlrq,
        ACSE_apdu_rlre,
        ACSE_apdu_abrt,
        ACSE_apdu_adt,
        ACSE_apdu_acrq,
        ACSE_apdu_acrp,
    };

    struct ACSE_apdu : public ITU_T_CHOICE(ACSE_apdu_enum) {


        ITU_T_CHOICE_CTORS(ACSE_apdu);

        ITU_T_CHOICEC_DECL(aarq, AARQ_apdu, ACSE_apdu_aarq);
        ITU_T_CHOICEC_DECL(aare, AARE_apdu, ACSE_apdu_aare);
        ITU_T_CHOICEC_DECL(rlrq, RLRQ_apdu, ACSE_apdu_rlrq);
        ITU_T_CHOICEC_DECL(rlre, RLRE_apdu, ACSE_apdu_rlre);
        ITU_T_CHOICEC_DECL(abrt, ABRT_apdu, ACSE_apdu_abrt);
        ITU_T_CHOICEC_DECL(adt, A_DT_apdu, ACSE_apdu_adt);
        ITU_T_CHOICEC_DECL(acrq, ACRQ_apdu, ACSE_apdu_acrq);
        ITU_T_CHOICEC_DECL(acrp, ACRP_apdu, ACSE_apdu_acrp);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AARQ-apdu

    struct AARQ_apdu {

        static const bitstring_type protocol_version_version1;

        static const bitstring_type protocol_version__default;

        AARQ_apdu();

        AARQ_apdu(const ASO_context_name& arg__aSO_context_name);

        AARQ_apdu(shared_ptr< bitstring_type> arg__protocol_version,
                shared_ptr< ASO_context_name> arg__aSO_context_name,
                shared_ptr< AP_title> arg__called_AP_title,
                shared_ptr< AE_qualifier> arg__called_AE_qualifier,
                shared_ptr< AP_invocation_identifier> arg__called_AP_invocation_identifier,
                shared_ptr< AE_invocation_identifier> arg__called_AE_invocation_identifier,
                shared_ptr< AP_title> arg__calling_AP_title,
                shared_ptr< AE_qualifier> arg__calling_AE_qualifier,
                shared_ptr< AP_invocation_identifier> arg__calling_AP_invocation_identifier,
                shared_ptr< AE_invocation_identifier> arg__calling_AE_invocation_identifier,
                shared_ptr< ACSE_requirements> arg__sender_acse_requirements,
                shared_ptr< Mechanism_name> arg__mechanism_name,
                shared_ptr< Authentication_value> arg__calling_authentication_value,
                shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
                shared_ptr< Implementation_data> arg__implementation_information,
                shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
                shared_ptr< ASOI_tag> arg__called_asoi_tag,
                shared_ptr< ASOI_tag> arg__calling_asoi_tag,
                shared_ptr< Association_data> arg__user_information);

        ITU_T_DEFAULTH_DECL(protocol_version, bitstring_type, protocol_version__default);
        ITU_T_HOLDERH_DECL(aSO_context_name, ASO_context_name);
        ITU_T_OPTIONAL_DECL(called_AP_title, AP_title);
        ITU_T_OPTIONAL_DECL(called_AE_qualifier, AE_qualifier);
        ITU_T_OPTIONAL_DECL(called_AP_invocation_identifier, AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(called_AE_invocation_identifier, AE_invocation_identifier);
        ITU_T_OPTIONAL_DECL(calling_AP_title, AP_title);
        ITU_T_OPTIONAL_DECL(calling_AE_qualifier, AE_qualifier);
        ITU_T_OPTIONAL_DECL(calling_AP_invocation_identifier, AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(calling_AE_invocation_identifier, AE_invocation_identifier);
        ITU_T_OPTIONAL_DECL(sender_acse_requirements, ACSE_requirements);
        ITU_T_OPTIONAL_DECL(mechanism_name, Mechanism_name);
        ITU_T_OPTIONAL_DECL(calling_authentication_value, Authentication_value);
        ITU_T_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(implementation_information, Implementation_data);
        ITU_T_OPTIONAL_DECL(p_context_definition_list, Syntactic_context_list);
        ITU_T_OPTIONAL_DECL(called_asoi_tag, ASOI_tag); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(calling_asoi_tag, ASOI_tag); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_information, Association_data); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AARE-apdu

    struct AARE_apdu {

        static const bitstring_type protocol_version_version1;

        static const bitstring_type protocol_version__default;

        AARE_apdu();

        AARE_apdu(const ASO_context_name& arg__aSO_context_name,
                const Associate_result& arg__result,
                const Associate_source_diagnostic& arg__result_source_diagnostic);

        AARE_apdu(shared_ptr< bitstring_type> arg__protocol_version,
                shared_ptr< ASO_context_name> arg__aSO_context_name,
                shared_ptr< Associate_result> arg__result,
                shared_ptr< Associate_source_diagnostic> arg__result_source_diagnostic,
                shared_ptr< AP_title> arg__responding_AP_title,
                shared_ptr< AE_qualifier> arg__responding_AE_qualifier,
                shared_ptr< AP_invocation_identifier> arg__responding_AP_invocation_identifier,
                shared_ptr< AE_invocation_identifier> arg__responding_AE_invocation_identifier,
                shared_ptr< ACSE_requirements> arg__responder_acse_requirements,
                shared_ptr< Mechanism_name> arg__mechanism_name,
                shared_ptr< Authentication_value> arg__responding_authentication_value,
                shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
                shared_ptr< Implementation_data> arg__implementation_information,
                shared_ptr< P_context_result_list> arg__p_context_result_list,
                shared_ptr< ASOI_tag> arg__called_asoi_tag,
                shared_ptr< ASOI_tag> arg__calling_asoi_tag,
                shared_ptr< Association_data> arg__user_information);

        ITU_T_DEFAULTH_DECL(protocol_version, bitstring_type, protocol_version__default);
        ITU_T_HOLDERH_DECL(aSO_context_name, ASO_context_name);
        ITU_T_HOLDERH_DECL(result, Associate_result); //   Ic(  [ 0  ...   2 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(result_source_diagnostic, Associate_source_diagnostic);
        ITU_T_OPTIONAL_DECL(responding_AP_title, AP_title);
        ITU_T_OPTIONAL_DECL(responding_AE_qualifier, AE_qualifier);
        ITU_T_OPTIONAL_DECL(responding_AP_invocation_identifier, AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(responding_AE_invocation_identifier, AE_invocation_identifier);
        ITU_T_OPTIONAL_DECL(responder_acse_requirements, ACSE_requirements);
        ITU_T_OPTIONAL_DECL(mechanism_name, Mechanism_name);
        ITU_T_OPTIONAL_DECL(responding_authentication_value, Authentication_value);
        ITU_T_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(implementation_information, Implementation_data);
        ITU_T_OPTIONAL_DECL(p_context_result_list, P_context_result_list);
        ITU_T_OPTIONAL_DECL(called_asoi_tag, ASOI_tag); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(calling_asoi_tag, ASOI_tag); //    Sc (  [ 0  ...   7 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_information, Association_data); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RLRQ-apdu

    struct RLRQ_apdu {

        RLRQ_apdu();

        RLRQ_apdu(shared_ptr< Release_request_reason> arg__reason,
                shared_ptr< ASO_qualifier> arg__aso_qualifier,
                shared_ptr< ASOI_identifier> arg__asoi_identifier,
                shared_ptr< Association_data> arg__user_information);

        ITU_T_OPTIONAL_DECL(reason, Release_request_reason); //   Ic(  [ 0  ...   30 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_information, Association_data); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RLRE-apdu

    struct RLRE_apdu {

        RLRE_apdu();

        RLRE_apdu(shared_ptr< Release_response_reason> arg__reason,
                shared_ptr< ASO_qualifier> arg__aso_qualifier,
                shared_ptr< ASOI_identifier> arg__asoi_identifier,
                shared_ptr< Association_data> arg__user_information);

        ITU_T_OPTIONAL_DECL(reason, Release_response_reason); //   Ic(  [ 0  ...   30 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_information, Association_data); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ABRT-apdu

    struct ABRT_apdu {

        ABRT_apdu();

        ABRT_apdu(const ABRT_source& arg__abort_source);

        ABRT_apdu(shared_ptr< ABRT_source> arg__abort_source,
                shared_ptr< ABRT_diagnostic> arg__abort_diagnostic,
                shared_ptr< ASO_qualifier> arg__aso_qualifier,
                shared_ptr< ASOI_identifier> arg__asoi_identifier,
                shared_ptr< Association_data> arg__user_information);

        ITU_T_HOLDERH_DECL(abort_source, ABRT_source); //   Ic(  [ 0  ...   1 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(abort_diagnostic, ABRT_diagnostic);
        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(user_information, Association_data); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence A-DT-apdu

    struct A_DT_apdu {

        A_DT_apdu();

        A_DT_apdu(const User_Data& arg__a_user_data);

        A_DT_apdu(shared_ptr< ASO_qualifier> arg__aso_qualifier,
                shared_ptr< ASOI_identifier> arg__asoi_identifier,
                shared_ptr< User_Data> arg__a_user_data);

        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(a_user_data, User_Data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ACRQ-apdu

    struct ACRQ_apdu {

        ACRQ_apdu();

        ACRQ_apdu(shared_ptr< ASO_qualifier> arg__aso_qualifier,
                shared_ptr< ASOI_identifier> arg__asoi_identifier,
                shared_ptr< ASO_context_name> arg__aSO_context_name,
                shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
                shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
                shared_ptr< User_information> arg__user_information);

        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(aSO_context_name, ASO_context_name);
        ITU_T_OPTIONAL_DECL(aSO_context_name_list, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(p_context_definition_list, Syntactic_context_list);
        ITU_T_OPTIONAL_DECL(user_information, User_information); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ACRP-apdu

    struct ACRP_apdu {

        ACRP_apdu();

        ACRP_apdu(shared_ptr< ASO_qualifier> arg__aso_qualifier,
                shared_ptr< ASOI_identifier> arg__asoi_identifier,
                shared_ptr< ASO_context_name_list> arg__aSO_context_name,
                shared_ptr< P_context_result_list> arg__p_context_result_list,
                shared_ptr< User_information> arg__user_information);

        ITU_T_OPTIONAL_DECL(aso_qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(asoi_identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 
        ITU_T_OPTIONAL_DECL(aSO_context_name, ASO_context_name_list);
        ITU_T_OPTIONAL_DECL(p_context_result_list, P_context_result_list);
        ITU_T_OPTIONAL_DECL(user_information, User_information); //    Sc (  [ 1 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    const ABRT_diagnostic aBRT_diagnostic_no_reason_given = 1;
    const ABRT_diagnostic aBRT_diagnostic_protocol_error = 2;
    const ABRT_diagnostic aBRT_diagnostic_authentication_mechanism_name_not_recognized = 3;
    const ABRT_diagnostic aBRT_diagnostic_authentication_mechanism_name_required = 4;
    const ABRT_diagnostic aBRT_diagnostic_authentication_failure = 5;
    const ABRT_diagnostic aBRT_diagnostic_authentication_required = 6;

    const ABRT_source aBRT_source_acse_service_user = 0;
    const ABRT_source aBRT_source_acse_service_provider = 1;

    const ACSE_requirements aCSE_requirements_authentication = bitstring_type(true, 0);
    const ACSE_requirements aCSE_requirements_aSO_context_negotiation = bitstring_type(true, 1);
    const ACSE_requirements aCSE_requirements_higher_level_association = bitstring_type(true, 2);
    const ACSE_requirements aCSE_requirements_nested_association = bitstring_type(true, 3);

    // choice AP-title

    enum AP_title_enum {

        AP_title_null = 0,
        AP_title_ap_title_form1,
        AP_title_ap_title_form2,
        AP_title_ap_title_form3,
    };

    struct AP_title : public ITU_T_CHOICE(AP_title_enum) {


        ITU_T_CHOICE_CTORS(AP_title);

        ITU_T_CHOICES_DECL(ap_title_form1, AP_title_form1, AP_title_ap_title_form1); // primitive
        ITU_T_CHOICES_DECL(ap_title_form2, AP_title_form2, AP_title_ap_title_form2); // primitive
        ITU_T_CHOICES_DECL(ap_title_form3, AP_title_form3, AP_title_ap_title_form3); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ASO-qualifier

    enum ASO_qualifier_enum {

        ASO_qualifier_null = 0,
        ASO_qualifier_aso_qualifier_form1,
        ASO_qualifier_aso_qualifier_form2,
        ASO_qualifier_aso_qualifier_form3,
    };

    struct ASO_qualifier : public ITU_T_CHOICE(ASO_qualifier_enum) {


        ITU_T_CHOICE_CTORS(ASO_qualifier);

        ITU_T_CHOICES_DECL(aso_qualifier_form1, ASO_qualifier_form1, ASO_qualifier_aso_qualifier_form1); // primitive
        ITU_T_CHOICES_DECL(aso_qualifier_form2, ASO_qualifier_form2, ASO_qualifier_aso_qualifier_form2); // primitive
        ITU_T_CHOICES_DECL(aso_qualifier_form3, ASO_qualifier_form3, ASO_qualifier_aso_qualifier_form3); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice AE-title

    enum AE_title_enum {

        AE_title_null = 0,
        AE_title_ae_title_form1,
        AE_title_ae_title_form2,
    };

    struct AE_title : public ITU_T_CHOICE(AE_title_enum) {


        ITU_T_CHOICE_CTORS(AE_title);

        ITU_T_CHOICES_DECL(ae_title_form1, AE_title_form1, AE_title_ae_title_form1); // primitive
        ITU_T_CHOICES_DECL(ae_title_form2, AE_title_form2, AE_title_ae_title_form2); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    struct ASOI_tag_sequence_of {

        ASOI_tag_sequence_of();

        ASOI_tag_sequence_of(shared_ptr< ASO_qualifier> arg__qualifier,
                shared_ptr< ASOI_identifier> arg__identifier);

        ITU_T_OPTIONAL_DECL(qualifier, ASO_qualifier);
        ITU_T_OPTIONAL_DECL(identifier, ASOI_identifier); //   Ic(  [ 1  ...   128 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Syntactic-context-list

    enum Syntactic_context_list_enum {

        Syntactic_context_list_null = 0,
        Syntactic_context_list_context_list,
        Syntactic_context_list_default_contact_list,
    };

    struct Syntactic_context_list : public ITU_T_CHOICE(Syntactic_context_list_enum) {


        ITU_T_CHOICE_CTORS(Syntactic_context_list);

        ITU_T_CHOICEC_DECL(context_list, Context_list, Syntactic_context_list_context_list);
        ITU_T_CHOICEC_DECL(default_contact_list, Default_Context_List, Syntactic_context_list_default_contact_list);

        ITU_T_ARCHIVE_FUNC;
    };

    struct Context_list_sequence_of {

        typedef sequence_of< Transfer_syntax_name > Transfer_syntaxes_type;


        Context_list_sequence_of();

        Context_list_sequence_of(const Presentation_context_identifier& arg__pci,
                const Abstract_syntax_name& arg__abstract_syntax,
                const Transfer_syntaxes_type& arg__transfer_syntaxes);

        ITU_T_HOLDERH_DECL(pci, Presentation_context_identifier);
        ITU_T_HOLDERH_DECL(abstract_syntax, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntaxes, Transfer_syntaxes_type);

        ITU_T_ARCHIVE_FUNC;
    };

    struct Default_Context_List_sequence_of {

        Default_Context_List_sequence_of();

        Default_Context_List_sequence_of(const Transfer_syntax_name& arg__transfer_syntax_name);

        Default_Context_List_sequence_of(shared_ptr< Abstract_syntax_name> arg__abstract_syntax_name,
                shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name);

        ITU_T_OPTIONAL_DECL(abstract_syntax_name, Abstract_syntax_name);
        ITU_T_HOLDERH_DECL(transfer_syntax_name, Transfer_syntax_name);

        ITU_T_ARCHIVE_FUNC;
    };

    struct P_context_result_list_sequence_of {

        static const integer_type provider_reason_reason_not_specified;
        static const integer_type provider_reason_abstract_syntax_not_supported;
        static const integer_type provider_reason_proposed_transfer_syntaxes_not_supported;
        static const integer_type provider_reason_local_limit_on_DCS_exceeded;


        P_context_result_list_sequence_of();

        P_context_result_list_sequence_of(const Result& arg__result);

        P_context_result_list_sequence_of(shared_ptr< Result> arg__result,
                shared_ptr< Concrete_syntax_name> arg__concrete_syntax_name,
                shared_ptr< integer_type> arg__provider_reason);

        ITU_T_HOLDERH_DECL(result, Result);
        ITU_T_OPTIONAL_DECL(concrete_syntax_name, Concrete_syntax_name);
        ITU_T_OPTIONAL_DECL(provider_reason, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    const Result result_acceptance = 0;
    const Result result_user_rejection = 1;
    const Result result_provider_rejection = 2;

    const Associate_result associate_result_accepted = 0;
    const Associate_result associate_result_rejected_permanent = 1;
    const Associate_result associate_result_rejected_transient = 2;

    // choice Associate-source-diagnostic

    enum Associate_source_diagnostic_enum {

        Associate_source_diagnostic_null = 0,
        Associate_source_diagnostic_acse_service_user,
        Associate_source_diagnostic_acse_service_provider,
    };

    struct Associate_source_diagnostic : public ITU_T_CHOICE(Associate_source_diagnostic_enum) {

        static const integer_type acse_service_user_null;
        static const integer_type acse_service_user_no_reason_given;
        static const integer_type acse_service_user_application_context_name_not_supported;
        static const integer_type acse_service_user_calling_AP_title_not_recognized;
        static const integer_type acse_service_user_calling_AP_invocation_identifier_not_recognized;
        static const integer_type acse_service_user_calling_AE_qualifier_not_recognized;
        static const integer_type acse_service_user_calling_AE_invocation_identifier_not_recognized;
        static const integer_type acse_service_user_called_AP_title_not_recognized;
        static const integer_type acse_service_user_called_AP_invocation_identifier_not_recognized;
        static const integer_type acse_service_user_called_AE_qualifier_not_recognized;
        static const integer_type acse_service_user_called_AE_invocation_identifier_not_recognized;
        static const integer_type acse_service_user_authentication_mechanism_name_not_recognized;
        static const integer_type acse_service_user_authentication_mechanism_name_required;
        static const integer_type acse_service_user_authentication_failure;
        static const integer_type acse_service_user_authentication_required;

        static const integer_type acse_service_provider_null;
        static const integer_type acse_service_provider_no_reason_given;
        static const integer_type acse_service_provider_no_common_acse_version;


        ITU_T_CHOICE_CTORS(Associate_source_diagnostic);

        ITU_T_CHOICES_DECL(acse_service_user, integer_type, Associate_source_diagnostic_acse_service_user); // primitive  //   Ic(  [ 0  ...   14 ]   ...ext...) 
        ITU_T_CHOICES_DECL(acse_service_provider, integer_type, Associate_source_diagnostic_acse_service_provider); // primitive  //   Ic(  [ 0  ...   2 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // choice User-Data

    enum User_Data_enum {

        User_Data_null = 0,
        User_Data_user_information,
        User_Data_simply_encoded_data,
        User_Data_fully_encoded_data,
    };

    struct User_Data : public ITU_T_CHOICE(User_Data_enum) {


        ITU_T_CHOICE_CTORS(User_Data);

        ITU_T_CHOICEC_DECL(user_information, User_information, User_Data_user_information); //    Sc (  [ 1 ]   ...ext...) 
        ITU_T_CHOICES_DECL(simply_encoded_data, Simply_encoded_data, User_Data_simply_encoded_data); // primitive
        ITU_T_CHOICEC_DECL(fully_encoded_data, PDV_list, User_Data_fully_encoded_data);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence PDV-list

    struct PDV_list {

        struct Presentation_data_values_type;

        enum Presentation_data_values_type_enum {

            Presentation_data_values_type_null = 0,
            Presentation_data_values_type_simple_ASN1_type,
            Presentation_data_values_type_octet_aligned,
            Presentation_data_values_type_arbitrary,
        };

        struct Presentation_data_values_type : public ITU_T_CHOICE(Presentation_data_values_type_enum) {


            ITU_T_CHOICE_CTORS(Presentation_data_values_type);

            ITU_T_CHOICES_DECL(simple_ASN1_type, any_type, Presentation_data_values_type_simple_ASN1_type); // primitive
            ITU_T_CHOICES_DECL(octet_aligned, octetstring_type, Presentation_data_values_type_octet_aligned); // primitive
            ITU_T_CHOICES_DECL(arbitrary, bitstring_type, Presentation_data_values_type_arbitrary); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        PDV_list();

        PDV_list(const Presentation_context_identifier& arg__presentation_context_identifier,
                const Presentation_data_values_type& arg__presentation_data_values);

        PDV_list(shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
                shared_ptr< Presentation_context_identifier> arg__presentation_context_identifier,
                shared_ptr< Presentation_data_values_type> arg__presentation_data_values);

        ITU_T_OPTIONAL_DECL(transfer_syntax_name, Transfer_syntax_name);
        ITU_T_HOLDERH_DECL(presentation_context_identifier, Presentation_context_identifier);
        ITU_T_HOLDERH_DECL(presentation_data_values, Presentation_data_values_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Authentication-value

    enum Authentication_value_enum {

        Authentication_value_null = 0,
        Authentication_value_charstring,
        Authentication_value_bitstring,
        Authentication_value_external,
        Authentication_value_other,
    };

    struct Authentication_value : public ITU_T_CHOICE(Authentication_value_enum) {


        struct Other_type;

        struct Other_type {

            Other_type();

            Other_type(const any_type& arg__other_mechanism_name,
                    const any_type& arg__other_mechanism_value);

            ITU_T_HOLDERH_DECL(other_mechanism_name, any_type);
            ITU_T_HOLDERH_DECL(other_mechanism_value, any_type);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(Authentication_value);

        ITU_T_CHOICES_DECL(charstring, graphicstring_type, Authentication_value_charstring); // primitive
        ITU_T_CHOICES_DECL(bitstring, bitstring_type, Authentication_value_bitstring); // primitive
        ITU_T_CHOICES_DECL(external, external_type, Authentication_value_external); // primitive
        ITU_T_CHOICEC_DECL(other, Other_type, Authentication_value_other);

        ITU_T_ARCHIVE_FUNC;
    };

    const Release_request_reason release_request_reason_normal = 0;
    const Release_request_reason release_request_reason_urgent = 1;
    const Release_request_reason release_request_reason_user_defined = 30;

    const Release_response_reason release_response_reason_normal = 0;
    const Release_response_reason release_response_reason_not_finished = 1;
    const Release_response_reason release_response_reason_user_defined = 30;

    ITU_T_ARCHIVE_X690_DECL(ACSE_apdu);
    ITU_T_ARCHIVE_X690_DECL(AARQ_apdu);
    ITU_T_ARCHIVE_X690_DECL(AARE_apdu);
    ITU_T_ARCHIVE_X690_DECL(RLRQ_apdu);
    ITU_T_ARCHIVE_X690_DECL(RLRE_apdu);
    ITU_T_ARCHIVE_X690_DECL(ABRT_apdu);
    ITU_T_ARCHIVE_X690_DECL(A_DT_apdu);
    ITU_T_ARCHIVE_X690_DECL(ACRQ_apdu);
    ITU_T_ARCHIVE_X690_DECL(ACRP_apdu);
    ITU_T_ARCHIVE_X690_DECL(AP_title);
    ITU_T_ARCHIVE_X690_DECL(ASO_qualifier);
    ITU_T_ARCHIVE_X690_DECL(AE_title);
    ITU_T_ARCHIVE_X690_DECL(ASOI_tag_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(Syntactic_context_list);
    ITU_T_ARCHIVE_X690_DECL(Context_list_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(Default_Context_List_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(P_context_result_list_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(Associate_source_diagnostic);
    ITU_T_ARCHIVE_X690_DECL(User_Data);
    ITU_T_ARCHIVE_X690_DECL(PDV_list);
    ITU_T_ARCHIVE_X690_DECL(PDV_list::Presentation_data_values_type);
    ITU_T_ARCHIVE_X690_DECL(Authentication_value);
    ITU_T_ARCHIVE_X690_DECL(Authentication_value::Other_type);

    ITU_T_ARCHIVE_X691_DECL(ACSE_apdu);
    ITU_T_ARCHIVE_X691_DECL(AARQ_apdu);
    ITU_T_ARCHIVE_X691_DECL(AARE_apdu);
    ITU_T_ARCHIVE_X691_DECL(RLRQ_apdu);
    ITU_T_ARCHIVE_X691_DECL(RLRE_apdu);
    ITU_T_ARCHIVE_X691_DECL(ABRT_apdu);
    ITU_T_ARCHIVE_X691_DECL(A_DT_apdu);
    ITU_T_ARCHIVE_X691_DECL(ACRQ_apdu);
    ITU_T_ARCHIVE_X691_DECL(ACRP_apdu);
    ITU_T_ARCHIVE_X691_DECL(AP_title);
    ITU_T_ARCHIVE_X691_DECL(ASO_qualifier);
    ITU_T_ARCHIVE_X691_DECL(AE_title);
    ITU_T_ARCHIVE_X691_DECL(ASOI_tag_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(Syntactic_context_list);
    ITU_T_ARCHIVE_X691_DECL(Context_list_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(Default_Context_List_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(P_context_result_list_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(Associate_source_diagnostic);
    ITU_T_ARCHIVE_X691_DECL(User_Data);
    ITU_T_ARCHIVE_X691_DECL(PDV_list);
    ITU_T_ARCHIVE_X691_DECL(PDV_list::Presentation_data_values_type);
    ITU_T_ARCHIVE_X691_DECL(Authentication_value);
    ITU_T_ARCHIVE_X691_DECL(Authentication_value::Other_type);

}

ITU_T_CHOICE_REGESTRATE(ACSE_1::ACSE_apdu)
ITU_T_CHOICE_REGESTRATE(ACSE_1::AP_title)
ITU_T_CHOICE_REGESTRATE(ACSE_1::ASO_qualifier)
ITU_T_CHOICE_REGESTRATE(ACSE_1::AE_title)
ITU_T_CHOICE_REGESTRATE(ACSE_1::Syntactic_context_list)
ITU_T_CHOICE_REGESTRATE(ACSE_1::Associate_source_diagnostic)
ITU_T_CHOICE_REGESTRATE(ACSE_1::User_Data)
ITU_T_CHOICE_REGESTRATE(ACSE_1::PDV_list::Presentation_data_values_type)
ITU_T_CHOICE_REGESTRATE(ACSE_1::Authentication_value)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___ACSE_1 */
