#include "ACSE-1.hpp"

namespace ACSE_1 {

    const boost::array<boost::asn1::oidindx_type, 5> acse_as_id_OID_ARR = { 2, 2, 1, 0, 1};
    const boost::asn1::oid_type acse_as_id  = boost::asn1::oid_type(acse_as_id_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 5> aCSE_id_OID_ARR = { 2, 2, 3, 1, 1};
    const boost::asn1::oid_type aCSE_id  = boost::asn1::oid_type(aCSE_id_OID_ARR );

        // choice ACSE-apdu

    template<> void ACSE_apdu::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case ACSE_apdu_aarq:  {BOOST_ASN_BIND_TAG(value<AARQ_apdu > (false , ACSE_apdu_aarq)); break; }
                case ACSE_apdu_aare:  {BOOST_ASN_BIND_TAG(value<AARE_apdu > (false , ACSE_apdu_aare)); break; }
                case ACSE_apdu_rlrq:  {BOOST_ASN_BIND_TAG(value<RLRQ_apdu > (false , ACSE_apdu_rlrq)); break; }
                case ACSE_apdu_rlre:  {BOOST_ASN_BIND_TAG(value<RLRE_apdu > (false , ACSE_apdu_rlre)); break; }
                case ACSE_apdu_abrt:  {BOOST_ASN_BIND_TAG(value<ABRT_apdu > (false , ACSE_apdu_abrt)); break; }
                case ACSE_apdu_adt:  {BOOST_ASN_BIND_TAG(value<A_DT_apdu > (false , ACSE_apdu_adt)); break; }
                case ACSE_apdu_acrq:  {BOOST_ASN_BIND_TAG(value<ACRQ_apdu > (false , ACSE_apdu_acrq)); break; }
                case ACSE_apdu_acrp:  {BOOST_ASN_BIND_TAG(value<ACRP_apdu > (false , ACSE_apdu_acrp)); break; }
                default:{}
        }
    }

    template<> void ACSE_apdu::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<AARQ_apdu > (true , ACSE_apdu_aarq))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<AARE_apdu > (true , ACSE_apdu_aare))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<RLRQ_apdu > (true , ACSE_apdu_rlrq))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<RLRE_apdu > (true , ACSE_apdu_rlre))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<ABRT_apdu > (true , ACSE_apdu_abrt))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<A_DT_apdu > (true , ACSE_apdu_adt))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<ACRQ_apdu > (true , ACSE_apdu_acrq))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<ACRP_apdu > (true , ACSE_apdu_acrp))) return; else free();
                }
        }
    }

 
        // sequence AARQ-apdu
    const bitstring_type AARQ_apdu_impl::protocol_version_version1 = bitstring_type(true, 0);


    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_EXPLICIT_TAG(aSO_context_name, 1);
        BOOST_ASN_CHOICE_TAG(called_AP_title, 2);
        BOOST_ASN_CHOICE_TAG(called_AE_qualifier, 3);
        BOOST_ASN_EXPLICIT_TAG(called_AP_invocation_identifier, 4);
        BOOST_ASN_EXPLICIT_TAG(called_AE_invocation_identifier, 5);
        BOOST_ASN_CHOICE_TAG(calling_AP_title, 6);
        BOOST_ASN_CHOICE_TAG(calling_AE_qualifier, 7);
        BOOST_ASN_EXPLICIT_TAG(calling_AP_invocation_identifier, 8);
        BOOST_ASN_EXPLICIT_TAG(calling_AE_invocation_identifier, 9);
        BOOST_ASN_IMPLICIT_TAG(sender_acse_requirements, 10);
        BOOST_ASN_IMPLICIT_TAG(mechanism_name, 11);
        BOOST_ASN_CHOICE_TAG(calling_authentication_value, 12);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list, 13);
        BOOST_ASN_IMPLICIT_TAG(implementation_information, 29);
        BOOST_ASN_CHOICE_TAG(p_context_definition_list, 14);
        BOOST_ASN_IMPLICIT_TAG(called_asoi_tag, 15);
        BOOST_ASN_IMPLICIT_TAG(calling_asoi_tag, 16);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_EXPLICIT_TAG(aSO_context_name, 1);
        BOOST_ASN_CHOICE_TAG(called_AP_title, 2);
        BOOST_ASN_CHOICE_TAG(called_AE_qualifier, 3);
        BOOST_ASN_EXPLICIT_TAG(called_AP_invocation_identifier, 4);
        BOOST_ASN_EXPLICIT_TAG(called_AE_invocation_identifier, 5);
        BOOST_ASN_CHOICE_TAG(calling_AP_title, 6);
        BOOST_ASN_CHOICE_TAG(calling_AE_qualifier, 7);
        BOOST_ASN_EXPLICIT_TAG(calling_AP_invocation_identifier, 8);
        BOOST_ASN_EXPLICIT_TAG(calling_AE_invocation_identifier, 9);
        BOOST_ASN_IMPLICIT_TAG(sender_acse_requirements, 10);
        BOOST_ASN_IMPLICIT_TAG(mechanism_name, 11);
        BOOST_ASN_CHOICE_TAG(calling_authentication_value, 12);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list, 13);
        BOOST_ASN_IMPLICIT_TAG(implementation_information, 29);
        BOOST_ASN_CHOICE_TAG(p_context_definition_list, 14);
        BOOST_ASN_IMPLICIT_TAG(called_asoi_tag, 15);
        BOOST_ASN_IMPLICIT_TAG(calling_asoi_tag, 16);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
        // sequence AARE-apdu
    const bitstring_type AARE_apdu_impl::protocol_version_version1 = bitstring_type(true, 0);


    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_EXPLICIT_TAG(aSO_context_name, 1);
        BOOST_ASN_EXPLICIT_TAG(result, 2);
        BOOST_ASN_CHOICE_TAG(result_source_diagnostic, 3);
        BOOST_ASN_CHOICE_TAG(responding_AP_title, 4);
        BOOST_ASN_CHOICE_TAG(responding_AE_qualifier, 5);
        BOOST_ASN_EXPLICIT_TAG(responding_AP_invocation_identifier, 6);
        BOOST_ASN_EXPLICIT_TAG(responding_AE_invocation_identifier, 7);
        BOOST_ASN_IMPLICIT_TAG(responder_acse_requirements, 8);
        BOOST_ASN_IMPLICIT_TAG(mechanism_name, 9);
        BOOST_ASN_CHOICE_TAG(responding_authentication_value, 10);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list, 11);
        BOOST_ASN_IMPLICIT_TAG(implementation_information, 29);
        BOOST_ASN_IMPLICIT_TAG(p_context_result_list, 12);
        BOOST_ASN_IMPLICIT_TAG(called_asoi_tag, 13);
        BOOST_ASN_IMPLICIT_TAG(calling_asoi_tag, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(protocol_version, 0);
        BOOST_ASN_EXPLICIT_TAG(aSO_context_name, 1);
        BOOST_ASN_EXPLICIT_TAG(result, 2);
        BOOST_ASN_CHOICE_TAG(result_source_diagnostic, 3);
        BOOST_ASN_CHOICE_TAG(responding_AP_title, 4);
        BOOST_ASN_CHOICE_TAG(responding_AE_qualifier, 5);
        BOOST_ASN_EXPLICIT_TAG(responding_AP_invocation_identifier, 6);
        BOOST_ASN_EXPLICIT_TAG(responding_AE_invocation_identifier, 7);
        BOOST_ASN_IMPLICIT_TAG(responder_acse_requirements, 8);
        BOOST_ASN_IMPLICIT_TAG(mechanism_name, 9);
        BOOST_ASN_CHOICE_TAG(responding_authentication_value, 10);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list, 11);
        BOOST_ASN_IMPLICIT_TAG(implementation_information, 29);
        BOOST_ASN_IMPLICIT_TAG(p_context_result_list, 12);
        BOOST_ASN_IMPLICIT_TAG(called_asoi_tag, 13);
        BOOST_ASN_IMPLICIT_TAG(calling_asoi_tag, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
        // sequence RLRQ-apdu

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(reason, 0);
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 13);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(reason, 0);
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 13);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
        // sequence RLRE-apdu

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(reason, 0);
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 13);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(reason, 0);
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 13);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
        // sequence ABRT-apdu

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(abort_source, 0);
        BOOST_ASN_IMPLICIT_TAG(abort_diagnostic, 1);
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 13);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(abort_source, 0);
        BOOST_ASN_IMPLICIT_TAG(abort_diagnostic, 1);
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 13);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 14);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
        // sequence A-DT-apdu

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 0);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 1);
        BOOST_ASN_CHOICE_TAG(a_user_data, 30);
    }

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 0);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 1);
        BOOST_ASN_CHOICE_TAG(a_user_data, 30);
    }

 
        // sequence ACRQ-apdu

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 0);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 1);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name, 3);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list, 4);
        BOOST_ASN_CHOICE_TAG(p_context_definition_list, 5);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 0);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 1);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name, 3);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list, 4);
        BOOST_ASN_CHOICE_TAG(p_context_definition_list, 5);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
        // sequence ACRP-apdu

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 0);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 1);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name, 3);
        BOOST_ASN_IMPLICIT_TAG(p_context_result_list, 4);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_CHOICE_TAG(aso_qualifier, 0);
        BOOST_ASN_IMPLICIT_TAG(asoi_identifier, 1);
        BOOST_ASN_IMPLICIT_TAG(aSO_context_name, 3);
        BOOST_ASN_IMPLICIT_TAG(p_context_result_list, 4);
        BOOST_ASN_IMPLICIT_TAG(user_information, 30);
    }

 
    const int ABRT_diagnostic_no_reason_given = 1;
    const int ABRT_diagnostic_protocol_error = 2;
    const int ABRT_diagnostic_authentication_mechanism_name_not_recognized = 3;
    const int ABRT_diagnostic_authentication_mechanism_name_required = 4;
    const int ABRT_diagnostic_authentication_failure = 5;
    const int ABRT_diagnostic_authentication_required = 6;

    const int ABRT_source_acse_service_user = 0;
    const int ABRT_source_acse_service_provider = 1;

    const bitstring_type ACSE_requirements_authentication = bitstring_type(true, 0);
    const bitstring_type ACSE_requirements_aSO_context_negotiation = bitstring_type(true, 1);
    const bitstring_type ACSE_requirements_higher_level_association = bitstring_type(true, 2);
    const bitstring_type ACSE_requirements_nested_association = bitstring_type(true, 3);

        // choice AP-title

    template<> void AP_title::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case AP_title_ap_title_form1:  {BOOST_ASN_BIND_TAG(value<AP_title_form1 > (false , AP_title_ap_title_form1)); break; }
                case AP_title_ap_title_form2:  {BOOST_ASN_BIND_TAG(value<AP_title_form2 > (false , AP_title_ap_title_form2)); break; }
                case AP_title_ap_title_form3:  {BOOST_ASN_BIND_TAG(value<AP_title_form3 > (false , AP_title_ap_title_form3)); break; }
                default:{}
        }
    }

    template<> void AP_title::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<AP_title_form1 > (true , AP_title_ap_title_form1))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<AP_title_form2 > (true , AP_title_ap_title_form2))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<AP_title_form3 > (true , AP_title_ap_title_form3))) return; else free();
                }
        }
    }

 
        // choice ASO-qualifier

    template<> void ASO_qualifier::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case ASO_qualifier_aso_qualifier_form1:  {BOOST_ASN_BIND_TAG(value<ASO_qualifier_form1 > (false , ASO_qualifier_aso_qualifier_form1)); break; }
                case ASO_qualifier_aso_qualifier_form2:  {BOOST_ASN_BIND_TAG(value<ASO_qualifier_form2 > (false , ASO_qualifier_aso_qualifier_form2)); break; }
                case ASO_qualifier_aso_qualifier_form3:  {BOOST_ASN_BIND_TAG(value<ASO_qualifier_form3 > (false , ASO_qualifier_aso_qualifier_form3)); break; }
                default:{}
        }
    }

    template<> void ASO_qualifier::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<ASO_qualifier_form1 > (true , ASO_qualifier_aso_qualifier_form1))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<ASO_qualifier_form2 > (true , ASO_qualifier_aso_qualifier_form2))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<ASO_qualifier_form3 > (true , ASO_qualifier_aso_qualifier_form3))) return; else free();
                }
        }
    }

 
        // choice AE-title

    template<> void AE_title::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case AE_title_ae_title_form1:  {BOOST_ASN_BIND_TAG(value<AE_title_form1 > (false , AE_title_ae_title_form1)); break; }
                case AE_title_ae_title_form2:  {BOOST_ASN_BIND_TAG(value<AE_title_form2 > (false , AE_title_ae_title_form2)); break; }
                default:{}
        }
    }

    template<> void AE_title::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<AE_title_form1 > (true , AE_title_ae_title_form1))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<AE_title_form2 > (true , AE_title_ae_title_form2))) return; else free();
                }
        }
    }

 


    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_CHOICE_TAG(qualifier, 0);
        BOOST_ASN_EXPLICIT_TAG(identifier, 1);
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_CHOICE_TAG(qualifier, 0);
        BOOST_ASN_EXPLICIT_TAG(identifier, 1);
    }

 
        // choice Syntactic-context-list

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case Syntactic_context_list_context_list:  {BOOST_ASN_EXPLICIT_TAG(value<Context_list > (false , Syntactic_context_list_context_list), 0); break; }
                case Syntactic_context_list_default_contact_list:  {BOOST_ASN_EXPLICIT_TAG(value<Default_Context_List > (false , Syntactic_context_list_default_contact_list), 1); break; }
                default:{}
        }
    }

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_EXPLICIT_TAG(value<Context_list > (true , Syntactic_context_list_context_list), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_EXPLICIT_TAG(value<Default_Context_List > (true , Syntactic_context_list_default_contact_list), 1)) return; else free(); break;}
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

 


    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_BIND_TAG(pci);
        BOOST_ASN_BIND_TAG(abstract_syntax);
        BOOST_ASN_BIND_TAG(transfer_syntaxes);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_BIND_TAG(pci);
        BOOST_ASN_BIND_TAG(abstract_syntax);
        BOOST_ASN_BIND_TAG(transfer_syntaxes);
    }

 


    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(abstract_syntax_name, 0);
        BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name, 1);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(abstract_syntax_name, 0);
        BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name, 1);
    }

 

    const int P_context_result_list_sequence_of::provider_reason_reason_not_specified = 0;
    const int P_context_result_list_sequence_of::provider_reason_abstract_syntax_not_supported = 1;
    const int P_context_result_list_sequence_of::provider_reason_proposed_transfer_syntaxes_not_supported = 2;
    const int P_context_result_list_sequence_of::provider_reason_local_limit_on_DCS_exceeded = 3;


    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(result, 0);
        BOOST_ASN_IMPLICIT_TAG(concrete_syntax_name, 1);
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 2);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_IMPLICIT_TAG(result, 0);
        BOOST_ASN_IMPLICIT_TAG(concrete_syntax_name, 1);
        BOOST_ASN_IMPLICIT_TAG(provider_reason, 2);
    }

 
    const int Result_acceptance = 0;
    const int Result_user_rejection = 1;
    const int Result_provider_rejection = 2;

    const int Associate_result_accepted = 0;
    const int Associate_result_rejected_permanent = 1;
    const int Associate_result_rejected_transient = 2;

        // choice Associate-source-diagnostic
    const int Associate_source_diagnostic::acse_service_user_null = 0;
    const int Associate_source_diagnostic::acse_service_user_no_reason_given = 1;
    const int Associate_source_diagnostic::acse_service_user_application_context_name_not_supported = 2;
    const int Associate_source_diagnostic::acse_service_user_calling_AP_title_not_recognized = 3;
    const int Associate_source_diagnostic::acse_service_user_calling_AP_invocation_identifier_not_recognized = 4;
    const int Associate_source_diagnostic::acse_service_user_calling_AE_qualifier_not_recognized = 5;
    const int Associate_source_diagnostic::acse_service_user_calling_AE_invocation_identifier_not_recognized = 6;
    const int Associate_source_diagnostic::acse_service_user_called_AP_title_not_recognized = 7;
    const int Associate_source_diagnostic::acse_service_user_called_AP_invocation_identifier_not_recognized = 8;
    const int Associate_source_diagnostic::acse_service_user_called_AE_qualifier_not_recognized = 9;
    const int Associate_source_diagnostic::acse_service_user_called_AE_invocation_identifier_not_recognized = 10;
    const int Associate_source_diagnostic::acse_service_user_authentication_mechanism_name_not_recognized = 11;
    const int Associate_source_diagnostic::acse_service_user_authentication_mechanism_name_required = 12;
    const int Associate_source_diagnostic::acse_service_user_authentication_failure = 13;
    const int Associate_source_diagnostic::acse_service_user_authentication_required = 14;

    const int Associate_source_diagnostic::acse_service_provider_null = 0;
    const int Associate_source_diagnostic::acse_service_provider_no_reason_given = 1;
    const int Associate_source_diagnostic::acse_service_provider_no_common_acse_version = 2;


    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case Associate_source_diagnostic_acse_service_user:  {BOOST_ASN_EXPLICIT_TAG(value<int > (false , Associate_source_diagnostic_acse_service_user), 1); break; }
                case Associate_source_diagnostic_acse_service_provider:  {BOOST_ASN_EXPLICIT_TAG(value<int > (false , Associate_source_diagnostic_acse_service_provider), 2); break; }
                default:{}
        }
    }

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_EXPLICIT_TAG(value<int > (true , Associate_source_diagnostic_acse_service_user), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_EXPLICIT_TAG(value<int > (true , Associate_source_diagnostic_acse_service_provider), 2)) return; else free(); break;}
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

 
        // choice User-Data

    template<> void User_Data::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case User_Data_user_information:  {BOOST_ASN_BIND_TAG(value<User_information > (false , User_Data_user_information)); break; }
                case User_Data_simply_encoded_data:  {BOOST_ASN_BIND_TAG(value<Simply_encoded_data > (false , User_Data_simply_encoded_data)); break; }
                case User_Data_fully_encoded_data:  {BOOST_ASN_EXPLICIT_TAG(value<PDV_list > (false , User_Data_fully_encoded_data), 0); break; }
                default:{}
        }
    }

    template<> void User_Data::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_EXPLICIT_TAG(value<PDV_list > (true , User_Data_fully_encoded_data), 0)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<User_information > (true , User_Data_user_information))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<Simply_encoded_data > (true , User_Data_simply_encoded_data))) return; else free();
                }
        }
    }

 
        // sequence PDV-list


    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case presentation_data_values_type_simple_ASN1_type:  {BOOST_ASN_EXPLICIT_TAG(value<any_type > (false , presentation_data_values_type_simple_ASN1_type), 0); break; }
                case presentation_data_values_type_octet_aligned:  {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , presentation_data_values_type_octet_aligned), 1); break; }
                case presentation_data_values_type_arbitrary:  {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , presentation_data_values_type_arbitrary), 2); break; }
                default:{}
        }
    }

    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_EXPLICIT_TAG(value<any_type > (true , presentation_data_values_type_simple_ASN1_type), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , presentation_data_values_type_octet_aligned), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , presentation_data_values_type_arbitrary), 2)) return; else free(); break;}
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

 

    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_BIND_TAG(transfer_syntax_name);
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_CHOICE(presentation_data_values);
    }

    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_BIND_TAG(transfer_syntax_name);
        BOOST_ASN_BIND_TAG(presentation_context_identifier);
        BOOST_ASN_CHOICE(presentation_data_values);
    }

 
        // choice Authentication-value


    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::output_coder& arch){
        BOOST_ASN_BIND_TAG(other_mechanism_name);
        BOOST_ASN_BIND_TAG(other_mechanism_value);
    }

    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::input_coder& arch){
        BOOST_ASN_BIND_TAG(other_mechanism_name);
        BOOST_ASN_BIND_TAG(other_mechanism_value);
    }

 

    template<> void Authentication_value::serialize(boost::asn1::x690::output_coder& arch){
        switch(type()){
                case Authentication_value_charstring:  {BOOST_ASN_IMPLICIT_TAG(value<graphicstring_type > (false , Authentication_value_charstring), 0); break; }
                case Authentication_value_bitstring:  {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , Authentication_value_bitstring), 1); break; }
                case Authentication_value_external:  {BOOST_ASN_IMPLICIT_TAG(value<external_type > (false , Authentication_value_external), 2); break; }
                case Authentication_value_other:  {BOOST_ASN_IMPLICIT_TAG(value<other_type > (false , Authentication_value_other), 3); break; }
                default:{}
        }
    }

    template<> void Authentication_value::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<graphicstring_type > (true , Authentication_value_charstring), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , Authentication_value_bitstring), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<external_type > (true , Authentication_value_external), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<other_type > (true , Authentication_value_other), 3)) return; else free(); break;}
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

 
    const int Release_request_reason_normal = 0;
    const int Release_request_reason_urgent = 1;
    const int Release_request_reason_user_defined = 30;

    const int Release_response_reason_normal = 0;
    const int Release_response_reason_not_finished = 1;
    const int Release_response_reason_user_defined = 30;

} 
