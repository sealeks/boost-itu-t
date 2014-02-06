#ifndef ___ACSE_1
#define ___ACSE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ACSE_1 {

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

    struct ASOI_tag_sequence_of;
    struct Context_list_sequence_of;
    struct Default_Context_List_sequence_of;
    struct P_context_result_list_sequence_of;
    struct ACSE_apdu;  
    struct AARQ_apdu_impl;  
    struct AARE_apdu_impl;  
    struct RLRQ_apdu_impl;  
    struct RLRE_apdu_impl;  
    struct ABRT_apdu_impl;  
    struct A_DT_apdu_impl;  
    struct ACRQ_apdu_impl;  
    struct ACRP_apdu_impl;  
    struct AP_title;  
    struct ASO_qualifier;  
    struct AE_title;  
    struct Syntactic_context_list;  
    struct Associate_source_diagnostic;  
    struct User_Data;  
    struct PDV_list;  
    struct Authentication_value;  

    typedef enumerated_type ABRT_diagnostic;  
    typedef int ABRT_source;  
    typedef bitstring_type ACSE_requirements;  
    typedef oid_type ASO_context_name;  
    typedef octetstring_type AP_title_form1;  
    typedef octetstring_type ASO_qualifier_form1;  
    typedef oid_type AP_title_form2;  
    typedef int ASO_qualifier_form2;  
    typedef printablestring_type AP_title_form3;  
    typedef printablestring_type ASO_qualifier_form3;  
    typedef octetstring_type AE_title_form1;  
    typedef oid_type AE_title_form2;  
    typedef int AE_invocation_identifier;  
    typedef int AP_invocation_identifier;  
    typedef int ASOI_identifier;  
    typedef oid_type Abstract_syntax_name;  
    typedef int Result;  
    typedef oid_type Transfer_syntax_name;  
    typedef int Associate_result;  
    typedef octetstring_type Simply_encoded_data;  
    typedef int Presentation_context_identifier;  
    typedef graphicstring_type Implementation_data;  
    typedef oid_type Mechanism_name;  
    typedef int Release_request_reason;  
    typedef int Release_response_reason;  


} 

namespace ACSE_1 {

    typedef std::vector< ASOI_tag_sequence_of> ASOI_tag;
    typedef std::vector< ASO_context_name> ASO_context_name_list;
    typedef std::vector< Context_list_sequence_of> Context_list;
    typedef std::vector< Default_Context_List_sequence_of> Default_Context_List;
    typedef std::vector< P_context_result_list_sequence_of> P_context_result_list;
    typedef std::vector< external_type> Association_data;
    typedef ASO_context_name Application_context_name;  
    typedef ASO_qualifier AE_qualifier;  
    typedef Transfer_syntax_name Concrete_syntax_name;  
    typedef Association_data User_information;  

    BOOST_ASN_IMPLICIT_TYPEDEF(AARQ_apdu, AARQ_apdu_impl,  0, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(AARE_apdu, AARE_apdu_impl,  1, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(RLRQ_apdu, RLRQ_apdu_impl,  2, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(RLRE_apdu, RLRE_apdu_impl,  3, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(ABRT_apdu, ABRT_apdu_impl,  4, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(A_DT_apdu, A_DT_apdu_impl,  5, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(ACRQ_apdu, ACRQ_apdu_impl,  6, APPLICATION_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(ACRP_apdu, ACRP_apdu_impl,  7, APPLICATION_CLASS);  


    extern const boost::asn1::oid_type acse_as_id;

    extern const boost::asn1::oid_type aCSE_id;

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
            ACSE_apdu_acrp,}; 
 
        struct ACSE_apdu : public BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) {


            ACSE_apdu() :  BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(aarq, AARQ_apdu, ACSE_apdu_aarq);
            BOOST_ASN_VALUE_CHOICE(aare, AARE_apdu, ACSE_apdu_aare);
            BOOST_ASN_VALUE_CHOICE(rlrq, RLRQ_apdu, ACSE_apdu_rlrq);
            BOOST_ASN_VALUE_CHOICE(rlre, RLRE_apdu, ACSE_apdu_rlre);
            BOOST_ASN_VALUE_CHOICE(abrt, ABRT_apdu, ACSE_apdu_abrt);
            BOOST_ASN_VALUE_CHOICE(adt, A_DT_apdu, ACSE_apdu_adt);
            BOOST_ASN_VALUE_CHOICE(acrq, ACRQ_apdu, ACSE_apdu_acrq);
            BOOST_ASN_VALUE_CHOICE(acrp, ACRP_apdu, ACSE_apdu_acrp);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence AARQ-apdu
        struct AARQ_apdu_impl{

            static const bitstring_type protocol_version_version1;


            AARQ_apdu_impl() : aSO_context_name() {} 
 
            boost::shared_ptr<bitstring_type> protocol_version;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type, protocol_version)

            boost::asn1::value_holder<ASO_context_name> aSO_context_name;
            boost::shared_ptr<AP_title> called_AP_title;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AP_title, called_AP_title)

            boost::shared_ptr<AE_qualifier> called_AE_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AE_qualifier, called_AE_qualifier)

            boost::shared_ptr<AP_invocation_identifier> called_AP_invocation_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AP_invocation_identifier, called_AP_invocation_identifier)

            boost::shared_ptr<AE_invocation_identifier> called_AE_invocation_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AE_invocation_identifier, called_AE_invocation_identifier)

            boost::shared_ptr<AP_title> calling_AP_title;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AP_title, calling_AP_title)

            boost::shared_ptr<AE_qualifier> calling_AE_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AE_qualifier, calling_AE_qualifier)

            boost::shared_ptr<AP_invocation_identifier> calling_AP_invocation_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AP_invocation_identifier, calling_AP_invocation_identifier)

            boost::shared_ptr<AE_invocation_identifier> calling_AE_invocation_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AE_invocation_identifier, calling_AE_invocation_identifier)

            boost::shared_ptr<ACSE_requirements> sender_acse_requirements;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ACSE_requirements, sender_acse_requirements)

            boost::shared_ptr<Mechanism_name> mechanism_name;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Mechanism_name, mechanism_name)

            boost::shared_ptr<Authentication_value> calling_authentication_value;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Authentication_value, calling_authentication_value)

            boost::shared_ptr<ASO_context_name_list> aSO_context_name_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list, aSO_context_name_list)

            boost::shared_ptr<Implementation_data> implementation_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Implementation_data, implementation_information)

            boost::shared_ptr<Syntactic_context_list> p_context_definition_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Syntactic_context_list, p_context_definition_list)

            boost::shared_ptr<ASOI_tag> called_asoi_tag;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag, called_asoi_tag)

            boost::shared_ptr<ASOI_tag> calling_asoi_tag;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag, calling_asoi_tag)

            boost::shared_ptr<Association_data> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AARE-apdu
        struct AARE_apdu_impl{

            static const bitstring_type protocol_version_version1;


            AARE_apdu_impl() : aSO_context_name(), result(), result_source_diagnostic() {} 
 
            boost::shared_ptr<bitstring_type> protocol_version;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type, protocol_version)

            boost::asn1::value_holder<ASO_context_name> aSO_context_name;
            boost::asn1::value_holder<Associate_result> result;
            boost::asn1::value_holder<Associate_source_diagnostic> result_source_diagnostic;
            boost::shared_ptr<AP_title> responding_AP_title;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AP_title, responding_AP_title)

            boost::shared_ptr<AE_qualifier> responding_AE_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AE_qualifier, responding_AE_qualifier)

            boost::shared_ptr<AP_invocation_identifier> responding_AP_invocation_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AP_invocation_identifier, responding_AP_invocation_identifier)

            boost::shared_ptr<AE_invocation_identifier> responding_AE_invocation_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(AE_invocation_identifier, responding_AE_invocation_identifier)

            boost::shared_ptr<ACSE_requirements> responder_acse_requirements;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ACSE_requirements, responder_acse_requirements)

            boost::shared_ptr<Mechanism_name> mechanism_name;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Mechanism_name, mechanism_name)

            boost::shared_ptr<Authentication_value> responding_authentication_value;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Authentication_value, responding_authentication_value)

            boost::shared_ptr<ASO_context_name_list> aSO_context_name_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list, aSO_context_name_list)

            boost::shared_ptr<Implementation_data> implementation_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Implementation_data, implementation_information)

            boost::shared_ptr<P_context_result_list> p_context_result_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(P_context_result_list, p_context_result_list)

            boost::shared_ptr<ASOI_tag> called_asoi_tag;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag, called_asoi_tag)

            boost::shared_ptr<ASOI_tag> calling_asoi_tag;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag, calling_asoi_tag)

            boost::shared_ptr<Association_data> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RLRQ-apdu
        struct RLRQ_apdu_impl{


            RLRQ_apdu_impl() {} 
 
            boost::shared_ptr<Release_request_reason> reason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Release_request_reason, reason)

            boost::shared_ptr<ASO_qualifier> aso_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, aso_qualifier)

            boost::shared_ptr<ASOI_identifier> asoi_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, asoi_identifier)

            boost::shared_ptr<Association_data> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RLRE-apdu
        struct RLRE_apdu_impl{


            RLRE_apdu_impl() {} 
 
            boost::shared_ptr<Release_response_reason> reason;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Release_response_reason, reason)

            boost::shared_ptr<ASO_qualifier> aso_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, aso_qualifier)

            boost::shared_ptr<ASOI_identifier> asoi_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, asoi_identifier)

            boost::shared_ptr<Association_data> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ABRT-apdu
        struct ABRT_apdu_impl{


            ABRT_apdu_impl() : abort_source() {} 
 
            boost::asn1::value_holder<ABRT_source> abort_source;
            boost::shared_ptr<ABRT_diagnostic> abort_diagnostic;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ABRT_diagnostic, abort_diagnostic)

            boost::shared_ptr<ASO_qualifier> aso_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, aso_qualifier)

            boost::shared_ptr<ASOI_identifier> asoi_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, asoi_identifier)

            boost::shared_ptr<Association_data> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence A-DT-apdu
        struct A_DT_apdu_impl{


            A_DT_apdu_impl() : a_user_data() {} 
 
            boost::shared_ptr<ASO_qualifier> aso_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, aso_qualifier)

            boost::shared_ptr<ASOI_identifier> asoi_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, asoi_identifier)

            boost::asn1::value_holder<User_Data> a_user_data;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ACRQ-apdu
        struct ACRQ_apdu_impl{


            ACRQ_apdu_impl() {} 
 
            boost::shared_ptr<ASO_qualifier> aso_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, aso_qualifier)

            boost::shared_ptr<ASOI_identifier> asoi_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, asoi_identifier)

            boost::shared_ptr<ASO_context_name> aSO_context_name;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name, aSO_context_name)

            boost::shared_ptr<ASO_context_name_list> aSO_context_name_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list, aSO_context_name_list)

            boost::shared_ptr<Syntactic_context_list> p_context_definition_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Syntactic_context_list, p_context_definition_list)

            boost::shared_ptr<User_information> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_information, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ACRP-apdu
        struct ACRP_apdu_impl{


            ACRP_apdu_impl() {} 
 
            boost::shared_ptr<ASO_qualifier> aso_qualifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, aso_qualifier)

            boost::shared_ptr<ASOI_identifier> asoi_identifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, asoi_identifier)

            boost::shared_ptr<ASO_context_name_list> aSO_context_name;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list, aSO_context_name)

            boost::shared_ptr<P_context_result_list> p_context_result_list;
            BOOST_ASN_VALUE_FUNC_DECLARATE(P_context_result_list, p_context_result_list)

            boost::shared_ptr<User_information> user_information;
            BOOST_ASN_VALUE_FUNC_DECLARATE(User_information, user_information)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        extern const int ABRT_diagnostic_no_reason_given;
        extern const int ABRT_diagnostic_protocol_error;
        extern const int ABRT_diagnostic_authentication_mechanism_name_not_recognized;
        extern const int ABRT_diagnostic_authentication_mechanism_name_required;
        extern const int ABRT_diagnostic_authentication_failure;
        extern const int ABRT_diagnostic_authentication_required;

        extern const int ABRT_source_acse_service_user;
        extern const int ABRT_source_acse_service_provider;

        extern const bitstring_type ACSE_requirements_authentication;
        extern const bitstring_type ACSE_requirements_aSO_context_negotiation;
        extern const bitstring_type ACSE_requirements_higher_level_association;
        extern const bitstring_type ACSE_requirements_nested_association;

        // choice AP-title
        enum AP_title_enum {
            AP_title_null = 0, 
            AP_title_ap_title_form1,
            AP_title_ap_title_form2,
            AP_title_ap_title_form3,}; 
 
        struct AP_title : public BOOST_ASN_CHOICE_STRUCT(AP_title_enum) {


            AP_title() :  BOOST_ASN_CHOICE_STRUCT(AP_title_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(ap_title_form1, AP_title_form1, AP_title_ap_title_form1);
            BOOST_ASN_VALUE_CHOICE(ap_title_form2, AP_title_form2, AP_title_ap_title_form2);
            BOOST_ASN_VALUE_CHOICE(ap_title_form3, AP_title_form3, AP_title_ap_title_form3);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice ASO-qualifier
        enum ASO_qualifier_enum {
            ASO_qualifier_null = 0, 
            ASO_qualifier_aso_qualifier_form1,
            ASO_qualifier_aso_qualifier_form2,
            ASO_qualifier_aso_qualifier_form3,}; 
 
        struct ASO_qualifier : public BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) {


            ASO_qualifier() :  BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(aso_qualifier_form1, ASO_qualifier_form1, ASO_qualifier_aso_qualifier_form1);
            BOOST_ASN_VALUE_CHOICE(aso_qualifier_form2, ASO_qualifier_form2, ASO_qualifier_aso_qualifier_form2);
            BOOST_ASN_VALUE_CHOICE(aso_qualifier_form3, ASO_qualifier_form3, ASO_qualifier_aso_qualifier_form3);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice AE-title
        enum AE_title_enum {
            AE_title_null = 0, 
            AE_title_ae_title_form1,
            AE_title_ae_title_form2,}; 
 
        struct AE_title : public BOOST_ASN_CHOICE_STRUCT(AE_title_enum) {


            AE_title() :  BOOST_ASN_CHOICE_STRUCT(AE_title_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(ae_title_form1, AE_title_form1, AE_title_ae_title_form1);
            BOOST_ASN_VALUE_CHOICE(ae_title_form2, AE_title_form2, AE_title_ae_title_form2);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 

            struct ASOI_tag_sequence_of{


                ASOI_tag_sequence_of() {} 
 
                boost::shared_ptr<ASO_qualifier> qualifier;
                BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_qualifier, qualifier)

                boost::shared_ptr<ASOI_identifier> identifier;
                BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier, identifier)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 
        // choice Syntactic-context-list
        enum Syntactic_context_list_enum {
            Syntactic_context_list_null = 0, 
            Syntactic_context_list_context_list,
            Syntactic_context_list_default_contact_list,}; 
 
        struct Syntactic_context_list : public BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) {


            Syntactic_context_list() :  BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(context_list, Context_list, Syntactic_context_list_context_list);
            BOOST_ASN_VALUE_CHOICE(default_contact_list, Default_Context_List, Syntactic_context_list_default_contact_list);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 

            struct Context_list_sequence_of{
            typedef std::vector< Transfer_syntax_name> transfer_syntaxes_type;


                Context_list_sequence_of() : pci(), abstract_syntax(), transfer_syntaxes() {} 
 
                boost::asn1::value_holder<Presentation_context_identifier> pci;
                boost::asn1::value_holder<Abstract_syntax_name> abstract_syntax;
                boost::asn1::value_holder<transfer_syntaxes_type> transfer_syntaxes;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            struct Default_Context_List_sequence_of{


                Default_Context_List_sequence_of() : transfer_syntax_name() {} 
 
                boost::shared_ptr<Abstract_syntax_name> abstract_syntax_name;
                BOOST_ASN_VALUE_FUNC_DECLARATE(Abstract_syntax_name, abstract_syntax_name)

                boost::asn1::value_holder<Transfer_syntax_name> transfer_syntax_name;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            struct P_context_result_list_sequence_of{

                static const int provider_reason_reason_not_specified;
                static const int provider_reason_abstract_syntax_not_supported;
                static const int provider_reason_proposed_transfer_syntaxes_not_supported;
                static const int provider_reason_local_limit_on_DCS_exceeded;


                P_context_result_list_sequence_of() : result() {} 
 
                boost::asn1::value_holder<Result> result;
                boost::shared_ptr<Concrete_syntax_name> concrete_syntax_name;
                BOOST_ASN_VALUE_FUNC_DECLARATE(Concrete_syntax_name, concrete_syntax_name)

                boost::shared_ptr<int> provider_reason;
                BOOST_ASN_VALUE_FUNC_DECLARATE(int, provider_reason)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 
        extern const int Result_acceptance;
        extern const int Result_user_rejection;
        extern const int Result_provider_rejection;

        extern const int Associate_result_accepted;
        extern const int Associate_result_rejected_permanent;
        extern const int Associate_result_rejected_transient;

        // choice Associate-source-diagnostic
        enum Associate_source_diagnostic_enum {
            Associate_source_diagnostic_null = 0, 
            Associate_source_diagnostic_acse_service_user,
            Associate_source_diagnostic_acse_service_provider,}; 
 
        struct Associate_source_diagnostic : public BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) {

            static const int acse_service_user_null;
            static const int acse_service_user_no_reason_given;
            static const int acse_service_user_application_context_name_not_supported;
            static const int acse_service_user_calling_AP_title_not_recognized;
            static const int acse_service_user_calling_AP_invocation_identifier_not_recognized;
            static const int acse_service_user_calling_AE_qualifier_not_recognized;
            static const int acse_service_user_calling_AE_invocation_identifier_not_recognized;
            static const int acse_service_user_called_AP_title_not_recognized;
            static const int acse_service_user_called_AP_invocation_identifier_not_recognized;
            static const int acse_service_user_called_AE_qualifier_not_recognized;
            static const int acse_service_user_called_AE_invocation_identifier_not_recognized;
            static const int acse_service_user_authentication_mechanism_name_not_recognized;
            static const int acse_service_user_authentication_mechanism_name_required;
            static const int acse_service_user_authentication_failure;
            static const int acse_service_user_authentication_required;

            static const int acse_service_provider_null;
            static const int acse_service_provider_no_reason_given;
            static const int acse_service_provider_no_common_acse_version;


            Associate_source_diagnostic() :  BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(acse_service_user, int, Associate_source_diagnostic_acse_service_user);
            BOOST_ASN_VALUE_CHOICE(acse_service_provider, int, Associate_source_diagnostic_acse_service_provider);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice User-Data
        enum User_Data_enum {
            User_Data_null = 0, 
            User_Data_user_information,
            User_Data_simply_encoded_data,
            User_Data_fully_encoded_data,}; 
 
        struct User_Data : public BOOST_ASN_CHOICE_STRUCT(User_Data_enum) {


            User_Data() :  BOOST_ASN_CHOICE_STRUCT(User_Data_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(user_information, User_information, User_Data_user_information);
            BOOST_ASN_VALUE_CHOICE(simply_encoded_data, Simply_encoded_data, User_Data_simply_encoded_data);
            BOOST_ASN_VALUE_CHOICE(fully_encoded_data, PDV_list, User_Data_fully_encoded_data);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence PDV-list
        struct PDV_list{

            enum presentation_data_values_type_enum {
                presentation_data_values_type_null = 0, 
                presentation_data_values_type_simple_ASN1_type,
                presentation_data_values_type_octet_aligned,
                presentation_data_values_type_arbitrary,}; 
 
            struct presentation_data_values_type : public BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) {


                presentation_data_values_type() :  BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(simple_ASN1_type, any_type, presentation_data_values_type_simple_ASN1_type);
                BOOST_ASN_VALUE_CHOICE(octet_aligned, octetstring_type, presentation_data_values_type_octet_aligned);
                BOOST_ASN_VALUE_CHOICE(arbitrary, bitstring_type, presentation_data_values_type_arbitrary);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            PDV_list() : presentation_context_identifier(), presentation_data_values() {} 
 
            boost::shared_ptr<Transfer_syntax_name> transfer_syntax_name;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Transfer_syntax_name, transfer_syntax_name)

            boost::asn1::value_holder<Presentation_context_identifier> presentation_context_identifier;
            boost::asn1::value_holder<presentation_data_values_type> presentation_data_values;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice Authentication-value
        enum Authentication_value_enum {
            Authentication_value_null = 0, 
            Authentication_value_charstring,
            Authentication_value_bitstring,
            Authentication_value_external,
            Authentication_value_other,}; 
 
        struct Authentication_value : public BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) {

            struct other_type{


                other_type() : other_mechanism_name(), other_mechanism_value() {} 
 
                boost::asn1::value_holder<any_type> other_mechanism_name;
                boost::asn1::value_holder<any_type> other_mechanism_value;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            Authentication_value() :  BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(charstring, graphicstring_type, Authentication_value_charstring);
            BOOST_ASN_VALUE_CHOICE(bitstring, bitstring_type, Authentication_value_bitstring);
            BOOST_ASN_VALUE_CHOICE(external, external_type, Authentication_value_external);
            BOOST_ASN_VALUE_CHOICE(other, other_type, Authentication_value_other);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const int Release_request_reason_normal;
        extern const int Release_request_reason_urgent;
        extern const int Release_request_reason_user_defined;

        extern const int Release_response_reason_normal;
        extern const int Release_response_reason_not_finished;
        extern const int Release_response_reason_user_defined;

    template<> void ACSE_apdu::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACSE_apdu::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AP_title::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AP_title::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ASO_qualifier::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ASO_qualifier::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AE_title::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AE_title::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Syntactic_context_list::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Syntactic_context_list::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::input_coder& arch);
    template<> void User_Data::serialize(boost::asn1::x690::output_coder& arch);
    template<> void User_Data::serialize(boost::asn1::x690::input_coder& arch);
    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch);
    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Authentication_value::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Authentication_value::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::input_coder& arch);
} 

BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::ACSE_apdu)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::AP_title)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::ASO_qualifier)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::AE_title)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::Syntactic_context_list)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::Associate_source_diagnostic)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::User_Data)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::PDV_list::presentation_data_values_type)
BOOST_ASN_CHOICE_REGESTRATE(ACSE_1::Authentication_value)

#endif  /*___ACSE_1 */

