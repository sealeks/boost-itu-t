#ifndef	_ISO8823_PRESENTATION_H_
#define	_ISO8823_PRESENTATION_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif



namespace ISO8823_PRESENTATION  {


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

	//  type is  SET
	struct  CP_type;

 	//  type is  SET
	struct  CPA_PPDU;

 	//  type is  CHOICE
	struct  CPR_PPDU;

 	//  type is  CHOICE
	struct  Abort_type;

 	//  type is  CHOICE
	struct  ARU_PPDU;

 	//  type is  SEQUENCE
	struct  ARP_PPDU;

 	//  type is  CHOICE
	struct  Typed_data_type;

 	//  type is  SEQUENCE
	struct  AC_PPDU;

 	//  type is  SEQUENCE
	struct  ACA_PPDU;

 	//  type is  SEQUENCE
	struct  RS_PPDU;

 	//  type is  SEQUENCE
	struct  RSA_PPDU;

 	//  type is  SEQUENCE
	struct  Default_context_name;

 	//  type is  SET
	struct  Mode_selector;

 	//  type is  CHOICE
	struct  User_data;

 	//  type is  SEQUENCE
	struct  PDV_list;

 	//  type is  INTEGER
	typedef  int   Abort_reason;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   Abstract_syntax_name;

 	//  type is  INTEGER
	typedef  int   Event_identifier;

 	//  type is  INTEGER
	typedef  int   Presentation_context_identifier;

 	//  type is  BIT STRING
	typedef  bitstring_type   Presentation_requirements;

 	//  type is  OCTET STRING
	typedef  octetstring_type   Presentation_selector;

 	//  type is  BIT STRING
	typedef  bitstring_type   Protocol_version;

 	//  type is  INTEGER
	typedef  int   Provider_reason;

 	//  type is  INTEGER
	typedef  int   Result;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   Transfer_syntax_name;

 	//  type is  OCTET STRING
	typedef  octetstring_type   Simply_encoded_data;

 	//  type is  BIT STRING
	typedef  bitstring_type   User_session_requirements;

 	//   SEQUENCE_OF is Context-list 
	struct Context_list_sequence_of;
	typedef std::vector<Context_list_sequence_of >   Context_list;

	//   SEQUENCE_OF is Presentation-context-deletion-list 
	typedef std::vector<Presentation_context_identifier >   Presentation_context_deletion_list;

	//   SEQUENCE_OF is Presentation-context-deletion-result-list 
	typedef std::vector<int >   Presentation_context_deletion_result_list;

	//   SEQUENCE_OF is Presentation-context-identifier-list 
	struct Presentation_context_identifier_list_sequence_of;
	typedef std::vector<Presentation_context_identifier_list_sequence_of >   Presentation_context_identifier_list;

	//   SEQUENCE_OF is Result-list 
	struct Result_list_sequence_of;
	typedef std::vector<Result_list_sequence_of >   Result_list;

	//   SEQUENCE_OF is Fully-encoded-data 
	typedef std::vector<PDV_list >   Fully_encoded_data;

}
#include <boost/itu/x22X/presentation/Reliable-Transfer-APDUs.hpp>
 


namespace ISO8823_PRESENTATION  {

 
	//import type
	using Reliable_Transfer_APDUs::RTORQapdu;
	using Reliable_Transfer_APDUs::RTOACapdu;
	using Reliable_Transfer_APDUs::RTORJapdu;
	using Reliable_Transfer_APDUs::RTABapdu;
 
	//   SEQUENCE_OF is Context-list 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  Context_list_sequence_of{
			//   SEQUENCE_OF is transfer-syntax-name-list 
			typedef std::vector<Transfer_syntax_name >   transfer_syntax_name_list_type;


			Presentation_context_identifier   presentation_context_identifier;
			Abstract_syntax_name   abstract_syntax_name;
			transfer_syntax_name_list_type   transfer_syntax_name_list;

			Context_list_sequence_of()  : presentation_context_identifier() , abstract_syntax_name() , transfer_syntax_name_list()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_BIND_TAG(presentation_context_identifier);
				BOOST_ASN_BIND_TAG(abstract_syntax_name);
				BOOST_ASN_BIND_TAG(transfer_syntax_name_list);
			}
		};

	//end==============================================================
	typedef std::vector<Context_list_sequence_of >   Context_list;

	//   SEQUENCE_OF is Presentation-context-deletion-list 
	typedef std::vector<Presentation_context_identifier >   Presentation_context_deletion_list;

	//   SEQUENCE_OF is Presentation-context-deletion-result-list 

		static const int Member_acceptance = 0;
		static const int Member_user_rejection = 1;

	typedef std::vector<int >   Presentation_context_deletion_result_list;

	//   SEQUENCE_OF is Presentation-context-identifier-list 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  Presentation_context_identifier_list_sequence_of{

			Presentation_context_identifier   presentation_context_identifier;
			Transfer_syntax_name   transfer_syntax_name;

			Presentation_context_identifier_list_sequence_of()  : presentation_context_identifier() , transfer_syntax_name()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_BIND_TAG(presentation_context_identifier);
				BOOST_ASN_BIND_TAG(transfer_syntax_name);
			}
		};

	//end==============================================================
	typedef std::vector<Presentation_context_identifier_list_sequence_of >   Presentation_context_identifier_list;

	//   SEQUENCE_OF is Result-list 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  Result_list_sequence_of{


			static const int provider_reason_reason_not_specified = 0;
			static const int provider_reason_abstract_syntax_not_supported = 1;
			static const int provider_reason_proposed_transfer_syntaxes_not_supported = 2;
			static const int provider_reason_local_limit_on_DCS_exceeded = 3;


			Result   result;
			boost::shared_ptr<Transfer_syntax_name > transfer_syntax_name;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Transfer_syntax_name ,  transfer_syntax_name)

 			boost::shared_ptr<int > provider_reason;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  provider_reason)

 
			Result_list_sequence_of()  : result()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(result ,0);
				BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name ,1);
				BOOST_ASN_IMPLICIT_TAG(provider_reason ,2);
			}
		};

	//end==============================================================
	typedef std::vector<Result_list_sequence_of >   Result_list;

	//   SEQUENCE_OF is Fully-encoded-data 
	typedef std::vector<PDV_list >   Fully_encoded_data;

	//  ref is  User-data
	typedef User_data CPC_type;

 	//  ref is  Presentation-selector
	typedef Presentation_selector Called_presentation_selector;

 	//  ref is  Presentation-selector
	typedef Presentation_selector Calling_presentation_selector;

 	//  ref is  Result
	typedef Result Default_context_result;

 	//  ref is  Context-list
	typedef Context_list Presentation_context_addition_list;

 	//  ref is  Result-list
	typedef Result_list Presentation_context_addition_result_list;

 	//  ref is  Context-list
	typedef Context_list Presentation_context_definition_list;

 	//  ref is  Result-list
	typedef Result_list Presentation_context_definition_result_list;

 	//  ref is  Presentation-selector
	typedef Presentation_selector Responding_presentation_selector;

 
	const bitstring_type User_session_requirements_half_duplex= bitstring_type(true, 0);
	const bitstring_type User_session_requirements_duplex= bitstring_type(true, 1);
	const bitstring_type User_session_requirements_expedited_data= bitstring_type(true, 2);
	const bitstring_type User_session_requirements_minor_synchronize= bitstring_type(true, 3);
	const bitstring_type User_session_requirements_major_synchronize= bitstring_type(true, 4);
	const bitstring_type User_session_requirements_resynchronize= bitstring_type(true, 5);
	const bitstring_type User_session_requirements_activity_management= bitstring_type(true, 6);
	const bitstring_type User_session_requirements_negotiated_release= bitstring_type(true, 7);
	const bitstring_type User_session_requirements_capability_data= bitstring_type(true, 8);
	const bitstring_type User_session_requirements_exceptions= bitstring_type(true, 9);
	const bitstring_type User_session_requirements_typed_data= bitstring_type(true, 10);
	const bitstring_type User_session_requirements_symmetric_synchronize= bitstring_type(true, 11);
	const bitstring_type User_session_requirements_data_separation= bitstring_type(true, 12);

//start==============================================================
//It is   SEQUENCE  

	struct  PDV_list{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum presentation_data_values_type_enum {
			presentation_data_values_type_null = 0  , 
			presentation_data_values_type_single_ASN1_type , 
			presentation_data_values_type_octet_aligned , 
			presentation_data_values_type_arbitrary , 
		};

	struct  presentation_data_values_type : public BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) {




			presentation_data_values_type() : BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(single_ASN1_type, any_type,  presentation_data_values_type_single_ASN1_type)
			BOOST_ASN_VALUE_CHOICE(octet_aligned, octetstring_type,  presentation_data_values_type_octet_aligned)
			BOOST_ASN_VALUE_CHOICE(arbitrary, bitstring_type,  presentation_data_values_type_arbitrary)

			 template<typename Archive> void serialize(Archive& arch){

				if (arch.__input__()){
					int __tag_id__ =arch.test_id();
					switch(arch.test_class()){
						case 0x0: {
							switch(__tag_id__){
							default:{}}
							;}
						case 0x40: {
							switch(__tag_id__){
							default:{}}
							;}
						case 0xC0: {
							switch(__tag_id__){
							default:{}}
							;}
						case 0x80: {
							switch(__tag_id__){
								case 0: { if(BOOST_ASN_EXPLICIT_TAG(value<any_type > (true , presentation_data_values_type_single_ASN1_type) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , presentation_data_values_type_octet_aligned) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , presentation_data_values_type_arbitrary) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case presentation_data_values_type_single_ASN1_type: {BOOST_ASN_EXPLICIT_TAG(value<any_type > (false , presentation_data_values_type_single_ASN1_type) ,0); break;}
						case presentation_data_values_type_octet_aligned: {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , presentation_data_values_type_octet_aligned) ,1); break;}
						case presentation_data_values_type_arbitrary: {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , presentation_data_values_type_arbitrary) ,2); break;}
						default:{}}}
			}
		};


		boost::shared_ptr<Transfer_syntax_name > transfer_syntax_name;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Transfer_syntax_name ,  transfer_syntax_name)

 		Presentation_context_identifier   presentation_context_identifier;
		presentation_data_values_type   presentation_data_values;

		PDV_list()  : presentation_context_identifier() , presentation_data_values()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_BIND_TAG(transfer_syntax_name);
			BOOST_ASN_BIND_TAG(presentation_context_identifier);
			BOOST_ASN_CHOICE(presentation_data_values);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum User_data_enum {
		User_data_null = 0  , 
		User_data_simply_encoded_data , 
		User_data_fully_encoded_data , 
	};

	struct  User_data : public BOOST_ASN_CHOICE_STRUCT(User_data_enum) {


		User_data() : BOOST_ASN_CHOICE_STRUCT(User_data_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(simply_encoded_data, Simply_encoded_data,  User_data_simply_encoded_data)
		BOOST_ASN_VALUE_CHOICE(fully_encoded_data, Fully_encoded_data,  User_data_fully_encoded_data)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
							case 0: { if(BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Simply_encoded_data > (true , User_data_simply_encoded_data) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Fully_encoded_data > (true , User_data_fully_encoded_data) ,1)) return; else free(); break;}
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case User_data_simply_encoded_data: {BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Simply_encoded_data > (false , User_data_simply_encoded_data) ,0); break;}
					case User_data_fully_encoded_data: {BOOST_ASN_IMPLICIT_APPLICATION_TAG(value<Fully_encoded_data > (false , User_data_fully_encoded_data) ,1); break;}
					default:{}}}
		}
	};


	const int Result_acceptance = 0;
	const int Result_user_rejection = 1;
	const int Result_provider_rejection = 2;


	const int Provider_reason_reason_not_specified = 0;
	const int Provider_reason_temporary_congestion = 1;
	const int Provider_reason_local_limit_exceeded = 2;
	const int Provider_reason_called_presentation_address_unknown = 3;
	const int Provider_reason_protocol_version_not_supported = 4;
	const int Provider_reason_default_context_not_supported = 5;
	const int Provider_reason_user_data_not_readable = 6;
	const int Provider_reason_no_PSAP_available = 7;


	const bitstring_type Protocol_version_version_1= bitstring_type(true, 0);


	const bitstring_type Presentation_requirements_context_management= bitstring_type(true, 0);
	const bitstring_type Presentation_requirements_restoration= bitstring_type(true, 1);

//start==============================================================
//It is   SET  

	struct  Mode_selector{


		static const int mode_value_x410_1984_mode = 0;
		static const int mode_value_normal_mode = 1;


		int   mode_value;

		Mode_selector()  : mode_value()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mode_value ,0);
		}
	};

//end==============================================================

	const int Event_identifier_cp_PPDU = 0;
	const int Event_identifier_cpa_PPDU = 1;
	const int Event_identifier_cpr_PPDU = 2;
	const int Event_identifier_aru_PPDU = 3;
	const int Event_identifier_arp_PPDU = 4;
	const int Event_identifier_ac_PPDU = 5;
	const int Event_identifier_aca_PPDU = 6;
	const int Event_identifier_td_PPDU = 7;
	const int Event_identifier_ttd_PPDU = 8;
	const int Event_identifier_te_PPDU = 9;
	const int Event_identifier_tc_PPDU = 10;
	const int Event_identifier_tcc_PPDU = 11;
	const int Event_identifier_rs_PPDU = 12;
	const int Event_identifier_rsa_PPDU = 13;
	const int Event_identifier_s_release_indication = 14;
	const int Event_identifier_s_release_confirm = 15;
	const int Event_identifier_s_token_give_indication = 16;
	const int Event_identifier_s_token_please_indication = 17;
	const int Event_identifier_s_control_give_indication = 18;
	const int Event_identifier_s_sync_minor_indication = 19;
	const int Event_identifier_s_sync_minor_confirm = 20;
	const int Event_identifier_s_sync_major_indication = 21;
	const int Event_identifier_s_sync_major_confirm = 22;
	const int Event_identifier_s_p_exception_report_indication = 23;
	const int Event_identifier_s_u_exception_report_indication = 24;
	const int Event_identifier_s_activity_start_indication = 25;
	const int Event_identifier_s_activity_resume_indication = 26;
	const int Event_identifier_s_activity_interrupt_indication = 27;
	const int Event_identifier_s_activity_interrupt_confirm = 28;
	const int Event_identifier_s_activity_discard_indication = 29;
	const int Event_identifier_s_activity_discard_confirm = 30;
	const int Event_identifier_s_activity_end_indication = 31;
	const int Event_identifier_s_activity_end_confirm = 32;

//start==============================================================
//It is   SEQUENCE  

	struct  Default_context_name{

		Abstract_syntax_name   abstract_syntax_name;
		Transfer_syntax_name   transfer_syntax_name;

		Default_context_name()  : abstract_syntax_name() , transfer_syntax_name()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(abstract_syntax_name ,0);
			BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name ,1);
		}
	};

//end==============================================================

	const int Abort_reason_reason_not_specified = 0;
	const int Abort_reason_unrecognized_ppdu = 1;
	const int Abort_reason_unexpected_ppdu = 2;
	const int Abort_reason_unexpected_session_service_primitive = 3;
	const int Abort_reason_unrecognized_ppdu_parameter = 4;
	const int Abort_reason_unexpected_ppdu_parameter = 5;
	const int Abort_reason_invalid_ppdu_parameter_value = 6;

//start==============================================================
//It is   SEQUENCE  

	struct  RSA_PPDU{

		boost::shared_ptr<Presentation_context_identifier_list > presentation_context_identifier_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier_list ,  presentation_context_identifier_list)

 		User_data   user_data;

		RSA_PPDU()  : presentation_context_identifier_list() , user_data()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list ,0);
			BOOST_ASN_CHOICE(user_data);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RS_PPDU{

		boost::shared_ptr<Presentation_context_identifier_list > presentation_context_identifier_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier_list ,  presentation_context_identifier_list)

 		User_data   user_data;

		RS_PPDU()  : presentation_context_identifier_list() , user_data()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list ,0);
			BOOST_ASN_CHOICE(user_data);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ACA_PPDU{

		boost::shared_ptr<Presentation_context_addition_result_list > presentation_context_addition_result_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_addition_result_list ,  presentation_context_addition_result_list)

 		boost::shared_ptr<Presentation_context_deletion_result_list > presentation_context_deletion_result_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_deletion_result_list ,  presentation_context_deletion_result_list)

 		User_data   user_data;

		ACA_PPDU()  : presentation_context_addition_result_list() , presentation_context_deletion_result_list() , user_data()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(presentation_context_addition_result_list ,0);
			BOOST_ASN_IMPLICIT_TAG(presentation_context_deletion_result_list ,1);
			BOOST_ASN_CHOICE(user_data);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AC_PPDU{

		boost::shared_ptr<Presentation_context_addition_list > presentation_context_addition_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_addition_list ,  presentation_context_addition_list)

 		boost::shared_ptr<Presentation_context_deletion_list > presentation_context_deletion_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_deletion_list ,  presentation_context_deletion_list)

 		User_data   user_data;

		AC_PPDU()  : presentation_context_addition_list() , presentation_context_deletion_list() , user_data()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(presentation_context_addition_list ,0);
			BOOST_ASN_IMPLICIT_TAG(presentation_context_deletion_list ,1);
			BOOST_ASN_CHOICE(user_data);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum Typed_data_type_enum {
		Typed_data_type_null = 0  , 
		Typed_data_type_acPPDU , 
		Typed_data_type_acaPPDU , 
		Typed_data_type_ttdPPDU , 
	};

	struct  Typed_data_type : public BOOST_ASN_CHOICE_STRUCT(Typed_data_type_enum) {


		Typed_data_type() : BOOST_ASN_CHOICE_STRUCT(Typed_data_type_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(acPPDU, AC_PPDU,  Typed_data_type_acPPDU)
		BOOST_ASN_VALUE_CHOICE(acaPPDU, ACA_PPDU,  Typed_data_type_acaPPDU)
		BOOST_ASN_VALUE_CHOICE(ttdPPDU, User_data,  Typed_data_type_ttdPPDU)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<AC_PPDU > (true , Typed_data_type_acPPDU) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<ACA_PPDU > (true , Typed_data_type_acaPPDU) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_CHOICE(value<User_data > (true , Typed_data_type_ttdPPDU))) return; else free();
					;}}}
			else {
				 switch(type()){
					case Typed_data_type_acPPDU: {BOOST_ASN_IMPLICIT_TAG(value<AC_PPDU > (false , Typed_data_type_acPPDU) ,0); break;}
					case Typed_data_type_acaPPDU: {BOOST_ASN_IMPLICIT_TAG(value<ACA_PPDU > (false , Typed_data_type_acaPPDU) ,1); break;}
					case Typed_data_type_ttdPPDU: {BOOST_ASN_CHOICE(value<User_data > (false , Typed_data_type_ttdPPDU)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  ARP_PPDU{

		boost::shared_ptr<Abort_reason > provider_reason;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Abort_reason ,  provider_reason)

 		boost::shared_ptr<Event_identifier > event_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Event_identifier ,  event_identifier)

 
		ARP_PPDU()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(provider_reason ,0);
			BOOST_ASN_IMPLICIT_TAG(event_identifier ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum ARU_PPDU_enum {
		ARU_PPDU_null = 0  , 
		ARU_PPDU_x400_mode_parameters , 
		ARU_PPDU_normal_mode_parameters , 
	};

	struct  ARU_PPDU : public BOOST_ASN_CHOICE_STRUCT(ARU_PPDU_enum) {


	//start==============================================================
	//It is  INTERNAL SET  

		struct  x400_mode_parameters_type{


			boost::shared_ptr<Reliable_Transfer_APDUs::AbortReason > abortReason;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Reliable_Transfer_APDUs::AbortReason ,  abortReason)

 			boost::shared_ptr<bitstring_type > reflectedParameter;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type ,  reflectedParameter)

 			boost::shared_ptr<any_type > userdataAB;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(any_type ,  userdataAB)

 
			x400_mode_parameters_type()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(abortReason ,0);
				BOOST_ASN_IMPLICIT_TAG(reflectedParameter ,1);
				BOOST_ASN_BIND_TAG(userdataAB);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  normal_mode_parameters_type{

			boost::shared_ptr<Presentation_context_identifier_list > presentation_context_identifier_list;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_identifier_list ,  presentation_context_identifier_list)

 			User_data   user_data;

			normal_mode_parameters_type()  : presentation_context_identifier_list() , user_data()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(presentation_context_identifier_list ,0);
				BOOST_ASN_CHOICE(user_data);
			}
		};

	//end==============================================================

		ARU_PPDU() : BOOST_ASN_CHOICE_STRUCT(ARU_PPDU_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(x400_mode_parameters, x400_mode_parameters_type,  ARU_PPDU_x400_mode_parameters)
		BOOST_ASN_VALUE_CHOICE(normal_mode_parameters, normal_mode_parameters_type,  ARU_PPDU_normal_mode_parameters)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<normal_mode_parameters_type > (true , ARU_PPDU_normal_mode_parameters) ,0)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (true , ARU_PPDU_x400_mode_parameters))) return; else free();
					;}}}
			else {
				 switch(type()){
					case ARU_PPDU_x400_mode_parameters: {BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (false , ARU_PPDU_x400_mode_parameters)); break;}
					case ARU_PPDU_normal_mode_parameters: {BOOST_ASN_IMPLICIT_TAG(value<normal_mode_parameters_type > (false , ARU_PPDU_normal_mode_parameters) ,0); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum Abort_type_enum {
		Abort_type_null = 0  , 
		Abort_type_aru_ppdu , 
		Abort_type_arp_ppdu , 
	};

	struct  Abort_type : public BOOST_ASN_CHOICE_STRUCT(Abort_type_enum) {


		Abort_type() : BOOST_ASN_CHOICE_STRUCT(Abort_type_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(aru_ppdu, ARU_PPDU,  Abort_type_aru_ppdu)
		BOOST_ASN_VALUE_CHOICE(arp_ppdu, ARP_PPDU,  Abort_type_arp_ppdu)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_CHOICE(value<ARU_PPDU > (true , Abort_type_aru_ppdu))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<ARP_PPDU > (true , Abort_type_arp_ppdu))) return; else free();
					;}}}
			else {
				 switch(type()){
					case Abort_type_aru_ppdu: {BOOST_ASN_CHOICE(value<ARU_PPDU > (false , Abort_type_aru_ppdu)); break;}
					case Abort_type_arp_ppdu: {BOOST_ASN_BIND_TAG(value<ARP_PPDU > (false , Abort_type_arp_ppdu)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum CPR_PPDU_enum {
		CPR_PPDU_null = 0  , 
		CPR_PPDU_x400_mode_parameters , 
		CPR_PPDU_normal_mode_parameters , 
	};

	struct  CPR_PPDU : public BOOST_ASN_CHOICE_STRUCT(CPR_PPDU_enum) {


	//start==============================================================
	//It is  INTERNAL SET  

		struct  x400_mode_parameters_type{

			boost::shared_ptr<Reliable_Transfer_APDUs::RefuseReason > refuseReason;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Reliable_Transfer_APDUs::RefuseReason ,  refuseReason)

 			boost::shared_ptr<any_type > userDataRJ;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(any_type ,  userDataRJ)

 
			x400_mode_parameters_type()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(refuseReason ,0);
				BOOST_ASN_BIND_TAG(userDataRJ);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  normal_mode_parameters_type{

			boost::shared_ptr<Protocol_version > protocol_version;   //  DEFAULT  {version-1} 
 			BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_version ,  protocol_version)

 			boost::shared_ptr<Responding_presentation_selector > responding_presentation_selector;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Responding_presentation_selector ,  responding_presentation_selector)

 			boost::shared_ptr<Presentation_context_definition_result_list > presentation_context_definition_result_list;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_definition_result_list ,  presentation_context_definition_result_list)

 			boost::shared_ptr<Default_context_result > default_context_result;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Default_context_result ,  default_context_result)

 			boost::shared_ptr<Provider_reason > provider_reason;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Provider_reason ,  provider_reason)

 			User_data   user_data;

			normal_mode_parameters_type()  : presentation_context_definition_result_list() , user_data()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(protocol_version ,0);
				BOOST_ASN_IMPLICIT_TAG(responding_presentation_selector ,3);
				BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_result_list ,5);
				BOOST_ASN_IMPLICIT_TAG(default_context_result ,7);
				BOOST_ASN_IMPLICIT_TAG(provider_reason ,10);
				BOOST_ASN_CHOICE(user_data);
			}
		};

	//end==============================================================

		CPR_PPDU() : BOOST_ASN_CHOICE_STRUCT(CPR_PPDU_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(x400_mode_parameters, x400_mode_parameters_type,  CPR_PPDU_x400_mode_parameters)
		BOOST_ASN_VALUE_CHOICE(normal_mode_parameters, normal_mode_parameters_type,  CPR_PPDU_normal_mode_parameters)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (true , CPR_PPDU_x400_mode_parameters))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<normal_mode_parameters_type > (true , CPR_PPDU_normal_mode_parameters))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CPR_PPDU_x400_mode_parameters: {BOOST_ASN_BIND_TAG(value<x400_mode_parameters_type > (false , CPR_PPDU_x400_mode_parameters)); break;}
					case CPR_PPDU_normal_mode_parameters: {BOOST_ASN_BIND_TAG(value<normal_mode_parameters_type > (false , CPR_PPDU_normal_mode_parameters)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SET  

	struct  CPA_PPDU{

	//start==============================================================
	//It is  INTERNAL SET  

		struct  x410_mode_parameters_type{



			boost::shared_ptr<int > checkpointSize;   //  DEFAULT  int  0  
 			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  checkpointSize)

 			boost::shared_ptr<int > windowSize;   //  DEFAULT  int  3  
 			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  windowSize)

 			Reliable_Transfer_APDUs::ConnectionData   connectionDataAC;

			x410_mode_parameters_type()  : connectionDataAC()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(checkpointSize ,0);
				BOOST_ASN_IMPLICIT_TAG(windowSize ,1);
				BOOST_ASN_CHOICE(connectionDataAC);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  normal_mode_parameters_type{

			boost::shared_ptr<Protocol_version > protocol_version;   //  DEFAULT  {version-1} 
 			BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_version ,  protocol_version)

 			boost::shared_ptr<Responding_presentation_selector > responding_presentation_selector;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Responding_presentation_selector ,  responding_presentation_selector)

 			boost::shared_ptr<Presentation_context_definition_result_list > presentation_context_definition_result_list;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_definition_result_list ,  presentation_context_definition_result_list)

 			boost::shared_ptr<Presentation_requirements > presentation_requirements;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_requirements ,  presentation_requirements)

 			boost::shared_ptr<User_session_requirements > user_session_requirements;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(User_session_requirements ,  user_session_requirements)

 			User_data   user_data;

			normal_mode_parameters_type()  : presentation_context_definition_result_list() , user_data()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(protocol_version ,0);
				BOOST_ASN_IMPLICIT_TAG(responding_presentation_selector ,3);
				BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_result_list ,5);
				BOOST_ASN_IMPLICIT_TAG(presentation_requirements ,8);
				BOOST_ASN_IMPLICIT_TAG(user_session_requirements ,9);
				BOOST_ASN_CHOICE(user_data);
			}
		};

	//end==============================================================

		Mode_selector   mode_selector;
		boost::shared_ptr<x410_mode_parameters_type > x410_mode_parameters;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(x410_mode_parameters_type ,  x410_mode_parameters)

 		boost::shared_ptr<normal_mode_parameters_type > normal_mode_parameters;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(normal_mode_parameters_type ,  normal_mode_parameters)

 
		CPA_PPDU()  : mode_selector()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mode_selector ,0);
			BOOST_ASN_IMPLICIT_TAG(x410_mode_parameters ,1);
			BOOST_ASN_IMPLICIT_TAG(normal_mode_parameters ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SET  

	struct  CP_type{

	//start==============================================================
	//It is  INTERNAL SET  

		struct  x410_mode_parameters_type{




			static const int dialogueMode_monologue = 0;
			static const int dialogueMode_twa = 1;



			boost::shared_ptr<int > checkpointSize;   //  DEFAULT  int  0  
 			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  checkpointSize)

 			boost::shared_ptr<int > windowSize;   //  DEFAULT  int  3  
 			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  windowSize)

 			boost::shared_ptr<int > dialogueMode;   //  DEFAULT  int  0  
 			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  dialogueMode)

 			Reliable_Transfer_APDUs::ConnectionData   connectionDataRQ;
			boost::shared_ptr<int > applicationProtocol;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  applicationProtocol)

 
			x410_mode_parameters_type()  : connectionDataRQ()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(checkpointSize ,0);
				BOOST_ASN_IMPLICIT_TAG(windowSize ,1);
				BOOST_ASN_IMPLICIT_TAG(dialogueMode ,2);
				BOOST_ASN_CHOICE(connectionDataRQ);
				BOOST_ASN_IMPLICIT_TAG(applicationProtocol ,4);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  normal_mode_parameters_type{

			boost::shared_ptr<Protocol_version > protocol_version;   //  DEFAULT  {version-1} 
 			BOOST_ASN_VALUE_FUNC_DECLARATE(Protocol_version ,  protocol_version)

 			boost::shared_ptr<Calling_presentation_selector > calling_presentation_selector;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Calling_presentation_selector ,  calling_presentation_selector)

 			boost::shared_ptr<Called_presentation_selector > called_presentation_selector;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Called_presentation_selector ,  called_presentation_selector)

 			boost::shared_ptr<Presentation_context_definition_list > presentation_context_definition_list;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_context_definition_list ,  presentation_context_definition_list)

 			boost::shared_ptr<Default_context_name > default_context_name;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Default_context_name ,  default_context_name)

 			boost::shared_ptr<Presentation_requirements > presentation_requirements;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Presentation_requirements ,  presentation_requirements)

 			boost::shared_ptr<User_session_requirements > user_session_requirements;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(User_session_requirements ,  user_session_requirements)

 			User_data   user_data;

			normal_mode_parameters_type()  : presentation_context_definition_list() , default_context_name() , user_data()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(protocol_version ,0);
				BOOST_ASN_IMPLICIT_TAG(calling_presentation_selector ,1);
				BOOST_ASN_IMPLICIT_TAG(called_presentation_selector ,2);
				BOOST_ASN_IMPLICIT_TAG(presentation_context_definition_list ,4);
				BOOST_ASN_IMPLICIT_TAG(default_context_name ,6);
				BOOST_ASN_IMPLICIT_TAG(presentation_requirements ,8);
				BOOST_ASN_IMPLICIT_TAG(user_session_requirements ,9);
				BOOST_ASN_CHOICE(user_data);
			}
		};

	//end==============================================================

		Mode_selector   mode_selector;
		boost::shared_ptr<x410_mode_parameters_type > x410_mode_parameters;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(x410_mode_parameters_type ,  x410_mode_parameters)

 		boost::shared_ptr<normal_mode_parameters_type > normal_mode_parameters;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(normal_mode_parameters_type ,  normal_mode_parameters)

 
		CP_type()  : mode_selector()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mode_selector ,0);
			BOOST_ASN_IMPLICIT_TAG(x410_mode_parameters ,1);
			BOOST_ASN_IMPLICIT_TAG(normal_mode_parameters ,2);
		}
	};

//end==============================================================

}

BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type) 
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CP_type::x410_mode_parameters_type) 
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU) 
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CPA_PPDU::x410_mode_parameters_type) 
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU::x400_mode_parameters_type) 
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU::x400_mode_parameters_type) 
BOOST_ASN_SET_REGESTRATE(ISO8823_PRESENTATION::Mode_selector) 

BOOST_ASN_CHOISE_REGESTRATE(ISO8823_PRESENTATION::CPR_PPDU) 
BOOST_ASN_CHOISE_REGESTRATE(ISO8823_PRESENTATION::Abort_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO8823_PRESENTATION::ARU_PPDU) 
BOOST_ASN_CHOISE_REGESTRATE(ISO8823_PRESENTATION::Typed_data_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO8823_PRESENTATION::User_data) 
BOOST_ASN_CHOISE_REGESTRATE(ISO8823_PRESENTATION::PDV_list::presentation_data_values_type) 

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif