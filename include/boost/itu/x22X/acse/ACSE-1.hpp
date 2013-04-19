#ifndef	_ACSE_1_H_
#define	_ACSE_1_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif


const boost::array<boost::asn1::oidindx_type, 5 >  ACSE_1_OID_ARR = { 2  ,  2  ,  1  ,  0  ,  1 };
const boost::asn1::oid_type ACSE_1_OID = boost::asn1::oid_type(ACSE_1_OID_ARR);


namespace ACSE_1  {


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

	//  type is  CHOICE
	struct  ACSE_apdu;

 	//  type is  preextend SEQUENCE
	struct  AARQ_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  AARE_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  RLRQ_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  RLRE_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  ABRT_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  A_DT_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  ACRQ_apdu__impl;

 	//  type is  preextend SEQUENCE
	struct  ACRP_apdu__impl;

 	//  type is  CHOICE
	struct  AP_title;

 	//  type is  CHOICE
	struct  ASO_qualifier;

 	//  type is  CHOICE
	struct  AE_title;

 	//  type is  CHOICE
	struct  Syntactic_context_list;

 	//  type is  CHOICE
	struct  Associate_source_diagnostic;

 	//  type is  CHOICE
	struct  User_Data;

 	//  type is  SEQUENCE
	struct  PDV_list;

 	//  type is  CHOICE
	struct  Authentication_value;

 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(AARQ_apdu , AARQ_apdu__impl , 0  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(AARE_apdu , AARE_apdu__impl , 1  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(RLRQ_apdu , RLRQ_apdu__impl , 2  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(RLRE_apdu , RLRE_apdu__impl , 3  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(ABRT_apdu , ABRT_apdu__impl , 4  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(A_DT_apdu , A_DT_apdu__impl , 5  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(ACRQ_apdu , ACRQ_apdu__impl , 6  ,APPLICATION_CLASS)
 
 
 	//  type is extended  SEQUENCE
	BOOST_ASN_IMPLICIT_TYPEDEF(ACRP_apdu , ACRP_apdu__impl , 7  ,APPLICATION_CLASS)
 
 
 	//  type is  ENUMERATED
	typedef  enumerated_type   ABRT_diagnostic;

 	//  type is  INTEGER
	typedef  int   ABRT_source;

 	//  type is  BIT STRING
	typedef  bitstring_type   ACSE_requirements;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   ASO_context_name;

 	//  type is  OCTET STRING
	typedef  octetstring_type   AP_title_form1;

 	//  type is  OCTET STRING
	typedef  octetstring_type   ASO_qualifier_form1;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   AP_title_form2;

 	//  type is  INTEGER
	typedef  int   ASO_qualifier_form2;

 	//  type is  PrintableString
	typedef  printablestring_type   AP_title_form3;

 	//  type is  PrintableString
	typedef  printablestring_type   ASO_qualifier_form3;

 	//  type is  OCTET STRING
	typedef  octetstring_type   AE_title_form1;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   AE_title_form2;

 	//  type is  INTEGER
	typedef  int   AE_invocation_identifier;

 	//  type is  INTEGER
	typedef  int   AP_invocation_identifier;

 	//  type is  INTEGER
	typedef  int   ASOI_identifier;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   Abstract_syntax_name;

 	//  type is  INTEGER
	typedef  int   Result;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   Transfer_syntax_name;

 	//  type is  INTEGER
	typedef  int   Associate_result;

 	//  type is  OCTET STRING
	typedef  octetstring_type   Simply_encoded_data;

 	//  type is  INTEGER
	typedef  int   Presentation_context_identifier;

 	//  type is  GraphicString
	typedef  graphicstring_type   Implementation_data;

 	//  type is  OBJECT IDENTIFIER
	typedef  oid_type   Mechanism_name;

 	//  type is  INTEGER
	typedef  int   Release_request_reason;

 	//  type is  INTEGER
	typedef  int   Release_response_reason;

 	//   SEQUENCE_OF is ASOI-tag 
	struct ASOI_tag_sequence_of;
	typedef std::vector<ASOI_tag_sequence_of >   ASOI_tag;

	//   SEQUENCE_OF is ASO-context-name-list 
	typedef std::vector<ASO_context_name >   ASO_context_name_list;

	//   SEQUENCE_OF is Context-list 
	struct Context_list_sequence_of;
	typedef std::vector<Context_list_sequence_of >   Context_list;

	//   SEQUENCE_OF is Default-Context-List 
	struct Default_Context_List_sequence_of;
	typedef std::vector<Default_Context_List_sequence_of >   Default_Context_List;

	//   SEQUENCE_OF is P-context-result-list 
	struct P_context_result_list_sequence_of;
	typedef std::vector<P_context_result_list_sequence_of >   P_context_result_list;

	//   SEQUENCE_OF is Association-data 
	typedef std::vector<external_type >   Association_data;

  	//  ref is  Transfer-syntax-name
	typedef Transfer_syntax_name Concrete_syntax_name;      
        
}


namespace ACSE_1  {

	//   SEQUENCE_OF is ASOI-tag 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  ASOI_tag_sequence_of{

			boost::asn1::value_holder<ASO_qualifier >  qualifier;
			boost::shared_ptr<ASOI_identifier > identifier;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  identifier)

 
			ASOI_tag_sequence_of()  : qualifier()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE_TAG(qualifier ,0);
				BOOST_ASN_EXPLICIT_TAG(identifier ,1);
			}
		};

	//end==============================================================
	typedef std::vector<ASOI_tag_sequence_of >   ASOI_tag;

	//   SEQUENCE_OF is ASO-context-name-list 
	typedef std::vector<ASO_context_name >   ASO_context_name_list;

	//   SEQUENCE_OF is Context-list 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  Context_list_sequence_of{
			//   SEQUENCE_OF is transfer-syntaxes 
			typedef std::vector<Transfer_syntax_name >   transfer_syntaxes_type;


			boost::asn1::value_holder<Presentation_context_identifier >  pci;
			boost::asn1::value_holder<Abstract_syntax_name >  abstract_syntax;
			boost::asn1::value_holder<transfer_syntaxes_type >  transfer_syntaxes;

			Context_list_sequence_of()  : pci() , abstract_syntax() , transfer_syntaxes()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_BIND_TAG(pci);
				BOOST_ASN_BIND_TAG(abstract_syntax);
				BOOST_ASN_BIND_TAG(transfer_syntaxes);
			}
		};

	//end==============================================================
	typedef std::vector<Context_list_sequence_of >   Context_list;

	//   SEQUENCE_OF is Default-Context-List 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  Default_Context_List_sequence_of{

			boost::shared_ptr<Abstract_syntax_name > abstract_syntax_name;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Abstract_syntax_name ,  abstract_syntax_name)

 			boost::asn1::value_holder<Transfer_syntax_name >  transfer_syntax_name;

			Default_Context_List_sequence_of()  : transfer_syntax_name()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(abstract_syntax_name ,0);
				BOOST_ASN_IMPLICIT_TAG(transfer_syntax_name ,1);
			}
		};

	//end==============================================================
	typedef std::vector<Default_Context_List_sequence_of >   Default_Context_List;

	//   SEQUENCE_OF is P-context-result-list 
	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  P_context_result_list_sequence_of{


			static const int provider_reason_reason_not_specified = 0;
			static const int provider_reason_abstract_syntax_not_supported = 1;
			static const int provider_reason_proposed_transfer_syntaxes_not_supported = 2;
			static const int provider_reason_local_limit_on_DCS_exceeded = 3;


			boost::asn1::value_holder<Result >  result;
			boost::shared_ptr<Concrete_syntax_name > concrete_syntax_name;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(Concrete_syntax_name ,  concrete_syntax_name)

 			boost::shared_ptr<int > provider_reason;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  provider_reason)

 
			P_context_result_list_sequence_of()  : result()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(result ,0);
				BOOST_ASN_IMPLICIT_TAG(concrete_syntax_name ,1);
				BOOST_ASN_IMPLICIT_TAG(provider_reason ,2);
			}
		};

	//end==============================================================
	typedef std::vector<P_context_result_list_sequence_of >   P_context_result_list;

	//   SEQUENCE_OF is Association-data 
	typedef std::vector<external_type >   Association_data;

	//  ref is  ASO-context-name
	typedef ASO_context_name Application_context_name;

 	//  ref is  ASO-qualifier
	typedef ASO_qualifier AE_qualifier;



 	//  ref is  Association-data
	typedef Association_data User_information;

 	//  ref is  TYPE-IDENTIFIER
	typedef octetstring_type MECHANISM_NAME;

 
	const int Release_response_reason_normal = 0;
	const int Release_response_reason_not_finished = 1;
	const int Release_response_reason_user_defined = 30;


	const int Release_request_reason_normal = 0;
	const int Release_request_reason_urgent = 1;
	const int Release_request_reason_user_defined = 30;

//start==============================================================
//It is   CHOICE

	enum Authentication_value_enum {
		Authentication_value_null = 0  , 
		Authentication_value_charstring , 
		Authentication_value_bitstring , 
		Authentication_value_external , 
		Authentication_value_other , 
	};

	struct  Authentication_value : public BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) {





	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  other_type{

			boost::asn1::value_holder<MECHANISM_NAME >  other_mechanism_name;
			boost::asn1::value_holder<any_type >  other_mechanism_value;

			other_type()  : other_mechanism_name() , other_mechanism_value()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_BIND_TAG(other_mechanism_name);
				BOOST_ASN_BIND_TAG(other_mechanism_value);
			}
		};

	//end==============================================================

		Authentication_value() : BOOST_ASN_CHOICE_STRUCT(Authentication_value_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(charstring, graphicstring_type,  Authentication_value_charstring)
		BOOST_ASN_VALUE_CHOICE(bitstring, bitstring_type,  Authentication_value_bitstring)
		BOOST_ASN_VALUE_CHOICE(external, external_type,  Authentication_value_external)
		BOOST_ASN_VALUE_CHOICE(other, other_type,  Authentication_value_other)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<graphicstring_type > (true , Authentication_value_charstring) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , Authentication_value_bitstring) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<external_type > (true , Authentication_value_external) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<other_type > (true , Authentication_value_other) ,3)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case Authentication_value_charstring: {BOOST_ASN_IMPLICIT_TAG(value<graphicstring_type > (false , Authentication_value_charstring) ,0); break;}
					case Authentication_value_bitstring: {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , Authentication_value_bitstring) ,1); break;}
					case Authentication_value_external: {BOOST_ASN_IMPLICIT_TAG(value<external_type > (false , Authentication_value_external) ,2); break;}
					case Authentication_value_other: {BOOST_ASN_IMPLICIT_TAG(value<other_type > (false , Authentication_value_other) ,3); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  PDV_list{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum presentation_data_values_type_enum {
			presentation_data_values_type_null = 0  , 
			presentation_data_values_type_simple_ASN1_type , 
			presentation_data_values_type_octet_aligned , 
			presentation_data_values_type_arbitrary , 
		};

	struct  presentation_data_values_type : public BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) {




			presentation_data_values_type() : BOOST_ASN_CHOICE_STRUCT(presentation_data_values_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(simple_ASN1_type, any_type,  presentation_data_values_type_simple_ASN1_type)
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
								case 0: { if(BOOST_ASN_EXPLICIT_TAG(value<any_type > (true , presentation_data_values_type_simple_ASN1_type) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , presentation_data_values_type_octet_aligned) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , presentation_data_values_type_arbitrary) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case presentation_data_values_type_simple_ASN1_type: {BOOST_ASN_EXPLICIT_TAG(value<any_type > (false , presentation_data_values_type_simple_ASN1_type) ,0); break;}
						case presentation_data_values_type_octet_aligned: {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , presentation_data_values_type_octet_aligned) ,1); break;}
						case presentation_data_values_type_arbitrary: {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , presentation_data_values_type_arbitrary) ,2); break;}
						default:{}}}
			}
		};


		boost::shared_ptr<Transfer_syntax_name > transfer_syntax_name;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Transfer_syntax_name ,  transfer_syntax_name)

 		boost::asn1::value_holder<Presentation_context_identifier >  presentation_context_identifier;
		boost::asn1::value_holder<presentation_data_values_type >  presentation_data_values;

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

	enum User_Data_enum {
		User_Data_null = 0  , 
		User_Data_user_information , 
		User_Data_simply_encoded_data , 
		User_Data_fully_encoded_data , 
	};

	struct  User_Data : public BOOST_ASN_CHOICE_STRUCT(User_Data_enum) {


		User_Data() : BOOST_ASN_CHOICE_STRUCT(User_Data_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(user_information, User_information,  User_Data_user_information)
		BOOST_ASN_VALUE_CHOICE(simply_encoded_data, Simply_encoded_data,  User_Data_simply_encoded_data)
		BOOST_ASN_VALUE_CHOICE(fully_encoded_data, PDV_list,  User_Data_fully_encoded_data)

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
							case 0: { if(BOOST_ASN_EXPLICIT_TAG(value<PDV_list > (true , User_Data_fully_encoded_data) ,0)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<User_information > (true , User_Data_user_information))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<Simply_encoded_data > (true , User_Data_simply_encoded_data))) return; else free();
					;}}}
			else {
				 switch(type()){
					case User_Data_user_information: {BOOST_ASN_BIND_TAG(value<User_information > (false , User_Data_user_information)); break;}
					case User_Data_simply_encoded_data: {BOOST_ASN_BIND_TAG(value<Simply_encoded_data > (false , User_Data_simply_encoded_data)); break;}
					case User_Data_fully_encoded_data: {BOOST_ASN_EXPLICIT_TAG(value<PDV_list > (false , User_Data_fully_encoded_data) ,0); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum Associate_source_diagnostic_enum {
		Associate_source_diagnostic_null = 0  , 
		Associate_source_diagnostic_acse_service_user , 
		Associate_source_diagnostic_acse_service_provider , 
	};

	struct  Associate_source_diagnostic : public BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) {



		static const int acse_service_user_null = 0;
		static const int acse_service_user_no_reason_given = 1;
		static const int acse_service_user_application_context_name_not_supported = 2;
		static const int acse_service_user_calling_AP_title_not_recognized = 3;
		static const int acse_service_user_calling_AP_invocation_identifier_not_recognized = 4;
		static const int acse_service_user_calling_AE_qualifier_not_recognized = 5;
		static const int acse_service_user_calling_AE_invocation_identifier_not_recognized = 6;
		static const int acse_service_user_called_AP_title_not_recognized = 7;
		static const int acse_service_user_called_AP_invocation_identifier_not_recognized = 8;
		static const int acse_service_user_called_AE_qualifier_not_recognized = 9;
		static const int acse_service_user_called_AE_invocation_identifier_not_recognized = 10;
		static const int acse_service_user_authentication_mechanism_name_not_recognized = 11;
		static const int acse_service_user_authentication_mechanism_name_required = 12;
		static const int acse_service_user_authentication_failure = 13;
		static const int acse_service_user_authentication_required = 14;



		static const int acse_service_provider_null = 0;
		static const int acse_service_provider_no_reason_given = 1;
		static const int acse_service_provider_no_common_acse_version = 2;


		Associate_source_diagnostic() : BOOST_ASN_CHOICE_STRUCT(Associate_source_diagnostic_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(acse_service_user, int,  Associate_source_diagnostic_acse_service_user)
		BOOST_ASN_VALUE_CHOICE(acse_service_provider, int,  Associate_source_diagnostic_acse_service_provider)

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
							case 1: { if(BOOST_ASN_EXPLICIT_TAG(value<int > (true , Associate_source_diagnostic_acse_service_user) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_EXPLICIT_TAG(value<int > (true , Associate_source_diagnostic_acse_service_provider) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case Associate_source_diagnostic_acse_service_user: {BOOST_ASN_EXPLICIT_TAG(value<int > (false , Associate_source_diagnostic_acse_service_user) ,1); break;}
					case Associate_source_diagnostic_acse_service_provider: {BOOST_ASN_EXPLICIT_TAG(value<int > (false , Associate_source_diagnostic_acse_service_provider) ,2); break;}
					default:{}}}
		}
	};


	const int Associate_result_accepted = 0;
	const int Associate_result_rejected_permanent = 1;
	const int Associate_result_rejected_transient = 2;


	const int Result_acceptance = 0;
	const int Result_user_rejection = 1;
	const int Result_provider_rejection = 2;

//start==============================================================
//It is   CHOICE

	enum Syntactic_context_list_enum {
		Syntactic_context_list_null = 0  , 
		Syntactic_context_list_context_list , 
		Syntactic_context_list_default_contact_list , 
	};

	struct  Syntactic_context_list : public BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) {


		Syntactic_context_list() : BOOST_ASN_CHOICE_STRUCT(Syntactic_context_list_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(context_list, Context_list,  Syntactic_context_list_context_list)
		BOOST_ASN_VALUE_CHOICE(default_contact_list, Default_Context_List,  Syntactic_context_list_default_contact_list)

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
							case 0: { if(BOOST_ASN_EXPLICIT_TAG(value<Context_list > (true , Syntactic_context_list_context_list) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_EXPLICIT_TAG(value<Default_Context_List > (true , Syntactic_context_list_default_contact_list) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case Syntactic_context_list_context_list: {BOOST_ASN_EXPLICIT_TAG(value<Context_list > (false , Syntactic_context_list_context_list) ,0); break;}
					case Syntactic_context_list_default_contact_list: {BOOST_ASN_EXPLICIT_TAG(value<Default_Context_List > (false , Syntactic_context_list_default_contact_list) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AE_title_enum {
		AE_title_null = 0  , 
		AE_title_ae_title_form1 , 
		AE_title_ae_title_form2 , 
	};

	struct  AE_title : public BOOST_ASN_CHOICE_STRUCT(AE_title_enum) {


		AE_title() : BOOST_ASN_CHOICE_STRUCT(AE_title_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(ae_title_form1, AE_title_form1,  AE_title_ae_title_form1)
		BOOST_ASN_VALUE_CHOICE(ae_title_form2, AE_title_form2,  AE_title_ae_title_form2)

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
						 if(BOOST_ASN_BIND_TAG(value<AE_title_form1 > (true , AE_title_ae_title_form1))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<AE_title_form2 > (true , AE_title_ae_title_form2))) return; else free();
					;}}}
			else {
				 switch(type()){
					case AE_title_ae_title_form1: {BOOST_ASN_BIND_TAG(value<AE_title_form1 > (false , AE_title_ae_title_form1)); break;}
					case AE_title_ae_title_form2: {BOOST_ASN_BIND_TAG(value<AE_title_form2 > (false , AE_title_ae_title_form2)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum ASO_qualifier_enum {
		ASO_qualifier_null = 0  , 
		ASO_qualifier_aso_qualifier_form1 , 
		ASO_qualifier_aso_qualifier_form2 , 
		ASO_qualifier_aso_qualifier_form3 , 
	};

	struct  ASO_qualifier : public BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) {


		ASO_qualifier() : BOOST_ASN_CHOICE_STRUCT(ASO_qualifier_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(aso_qualifier_form1, ASO_qualifier_form1,  ASO_qualifier_aso_qualifier_form1)
		BOOST_ASN_VALUE_CHOICE(aso_qualifier_form2, ASO_qualifier_form2,  ASO_qualifier_aso_qualifier_form2)
		BOOST_ASN_VALUE_CHOICE(aso_qualifier_form3, ASO_qualifier_form3,  ASO_qualifier_aso_qualifier_form3)

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
						 if(BOOST_ASN_BIND_TAG(value<ASO_qualifier_form1 > (true , ASO_qualifier_aso_qualifier_form1))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<ASO_qualifier_form2 > (true , ASO_qualifier_aso_qualifier_form2))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<ASO_qualifier_form3 > (true , ASO_qualifier_aso_qualifier_form3))) return; else free();
					;}}}
			else {
				 switch(type()){
					case ASO_qualifier_aso_qualifier_form1: {BOOST_ASN_BIND_TAG(value<ASO_qualifier_form1 > (false , ASO_qualifier_aso_qualifier_form1)); break;}
					case ASO_qualifier_aso_qualifier_form2: {BOOST_ASN_BIND_TAG(value<ASO_qualifier_form2 > (false , ASO_qualifier_aso_qualifier_form2)); break;}
					case ASO_qualifier_aso_qualifier_form3: {BOOST_ASN_BIND_TAG(value<ASO_qualifier_form3 > (false , ASO_qualifier_aso_qualifier_form3)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AP_title_enum {
		AP_title_null = 0  , 
		AP_title_ap_title_form1 , 
		AP_title_ap_title_form2 , 
		AP_title_ap_title_form3 , 
	};

	struct  AP_title : public BOOST_ASN_CHOICE_STRUCT(AP_title_enum) {


		AP_title() : BOOST_ASN_CHOICE_STRUCT(AP_title_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(ap_title_form1, AP_title_form1,  AP_title_ap_title_form1)
		BOOST_ASN_VALUE_CHOICE(ap_title_form2, AP_title_form2,  AP_title_ap_title_form2)
		BOOST_ASN_VALUE_CHOICE(ap_title_form3, AP_title_form3,  AP_title_ap_title_form3)

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
						 if(BOOST_ASN_BIND_TAG(value<AP_title_form1 > (true , AP_title_ap_title_form1))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<AP_title_form2 > (true , AP_title_ap_title_form2))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<AP_title_form3 > (true , AP_title_ap_title_form3))) return; else free();
					;}}}
			else {
				 switch(type()){
					case AP_title_ap_title_form1: {BOOST_ASN_BIND_TAG(value<AP_title_form1 > (false , AP_title_ap_title_form1)); break;}
					case AP_title_ap_title_form2: {BOOST_ASN_BIND_TAG(value<AP_title_form2 > (false , AP_title_ap_title_form2)); break;}
					case AP_title_ap_title_form3: {BOOST_ASN_BIND_TAG(value<AP_title_form3 > (false , AP_title_ap_title_form3)); break;}
					default:{}}}
		}
	};


	const bitstring_type ACSE_requirements_authentication= bitstring_type(true, 0);
	const bitstring_type ACSE_requirements_aSO_context_negotiation= bitstring_type(true, 1);
	const bitstring_type ACSE_requirements_higher_level_association= bitstring_type(true, 2);
	const bitstring_type ACSE_requirements_nested_association= bitstring_type(true, 3);


	const int ABRT_source_acse_service_user = 0;
	const int ABRT_source_acse_service_provider = 1;

//start==============================================================
//It is   SEQUENCE  

	struct  ACRP_apdu__impl{

		boost::asn1::value_holder<ASO_qualifier >  aso_qualifier;
		boost::shared_ptr<ASOI_identifier > asoi_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  asoi_identifier)

 		boost::shared_ptr<ASO_context_name_list > aSO_context_name;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list ,  aSO_context_name)

 		boost::shared_ptr<P_context_result_list > p_context_result_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(P_context_result_list ,  p_context_result_list)

 		boost::shared_ptr<User_information > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(User_information ,  user_information)

 
		ACRP_apdu__impl()  : aso_qualifier() , aSO_context_name() , p_context_result_list() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(aso_qualifier ,0);
			BOOST_ASN_IMPLICIT_TAG(asoi_identifier ,1);
			BOOST_ASN_IMPLICIT_TAG(aSO_context_name ,3);
			BOOST_ASN_IMPLICIT_TAG(p_context_result_list ,4);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ACRQ_apdu__impl{

		boost::asn1::value_holder<ASO_qualifier >  aso_qualifier;
		boost::shared_ptr<ASOI_identifier > asoi_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  asoi_identifier)

 		boost::shared_ptr<ASO_context_name > aSO_context_name;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name ,  aSO_context_name)

 		boost::shared_ptr<ASO_context_name_list > aSO_context_name_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list ,  aSO_context_name_list)

 		boost::asn1::value_holder<Syntactic_context_list >  p_context_definition_list;
		boost::shared_ptr<User_information > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(User_information ,  user_information)

 
		ACRQ_apdu__impl()  : aso_qualifier() , aSO_context_name_list() , p_context_definition_list() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(aso_qualifier ,0);
			BOOST_ASN_IMPLICIT_TAG(asoi_identifier ,1);
			BOOST_ASN_IMPLICIT_TAG(aSO_context_name ,3);
			BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list ,4);
			BOOST_ASN_CHOICE_TAG(p_context_definition_list ,5);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  A_DT_apdu__impl{

		boost::asn1::value_holder<ASO_qualifier >  aso_qualifier;
		boost::shared_ptr<ASOI_identifier > asoi_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  asoi_identifier)

 		boost::asn1::value_holder<User_Data >  a_user_data;

		A_DT_apdu__impl()  : aso_qualifier() , a_user_data()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(aso_qualifier ,0);
			BOOST_ASN_IMPLICIT_TAG(asoi_identifier ,1);
			BOOST_ASN_CHOICE_TAG(a_user_data ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ABRT_apdu__impl{

		boost::asn1::value_holder<ABRT_source >  abort_source;
		boost::shared_ptr<ABRT_diagnostic > abort_diagnostic;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ABRT_diagnostic ,  abort_diagnostic)

 		boost::asn1::value_holder<ASO_qualifier >  aso_qualifier;
		boost::shared_ptr<ASOI_identifier > asoi_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  asoi_identifier)

 		boost::shared_ptr<Association_data > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data ,  user_information)

 
		ABRT_apdu__impl()  : abort_source() , aso_qualifier() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(abort_source ,0);
			BOOST_ASN_IMPLICIT_TAG(abort_diagnostic ,1);
			BOOST_ASN_CHOICE_TAG(aso_qualifier ,13);
			BOOST_ASN_IMPLICIT_TAG(asoi_identifier ,14);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RLRE_apdu__impl{

		boost::shared_ptr<Release_response_reason > reason;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Release_response_reason ,  reason)

 		boost::asn1::value_holder<ASO_qualifier >  aso_qualifier;
		boost::shared_ptr<ASOI_identifier > asoi_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  asoi_identifier)

 		boost::shared_ptr<Association_data > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data ,  user_information)

 
		RLRE_apdu__impl()  : aso_qualifier() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(reason ,0);
			BOOST_ASN_CHOICE_TAG(aso_qualifier ,13);
			BOOST_ASN_IMPLICIT_TAG(asoi_identifier ,14);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RLRQ_apdu__impl{

		boost::shared_ptr<Release_request_reason > reason;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Release_request_reason ,  reason)

 		boost::asn1::value_holder<ASO_qualifier >  aso_qualifier;
		boost::shared_ptr<ASOI_identifier > asoi_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_identifier ,  asoi_identifier)

 		boost::shared_ptr<Association_data > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data ,  user_information)

 
		RLRQ_apdu__impl()  : aso_qualifier() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(reason ,0);
			BOOST_ASN_CHOICE_TAG(aso_qualifier ,13);
			BOOST_ASN_IMPLICIT_TAG(asoi_identifier ,14);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AARE_apdu__impl{


		//static const bitstring_type protocol_version_version1= bitstring_type(true, 0);


		boost::shared_ptr<bitstring_type > protocol_version;   //  DEFAULT  {version1} 
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type ,  protocol_version)

 		boost::asn1::value_holder<ASO_context_name >  aSO_context_name;
		boost::asn1::value_holder<Associate_result >  result;
		boost::asn1::value_holder<Associate_source_diagnostic >  result_source_diagnostic;
		boost::asn1::value_holder<AP_title >  responding_AP_title;
		boost::asn1::value_holder<AE_qualifier >  responding_AE_qualifier;
		boost::shared_ptr<AP_invocation_identifier > responding_AP_invocation_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AP_invocation_identifier ,  responding_AP_invocation_identifier)

 		boost::shared_ptr<AE_invocation_identifier > responding_AE_invocation_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AE_invocation_identifier ,  responding_AE_invocation_identifier)

 		boost::shared_ptr<ACSE_requirements > responder_acse_requirements;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ACSE_requirements ,  responder_acse_requirements)

 		boost::shared_ptr<Mechanism_name > mechanism_name;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Mechanism_name ,  mechanism_name)

 		boost::shared_ptr<Authentication_value >  responding_authentication_value;
		boost::shared_ptr<ASO_context_name_list > aSO_context_name_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list ,  aSO_context_name_list)

 		boost::shared_ptr<Implementation_data > implementation_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Implementation_data ,  implementation_information)

 		boost::shared_ptr<P_context_result_list > p_context_result_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(P_context_result_list ,  p_context_result_list)

 		boost::shared_ptr<ASOI_tag > called_asoi_tag;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag ,  called_asoi_tag)

 		boost::shared_ptr<ASOI_tag > calling_asoi_tag;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag ,  calling_asoi_tag)

 		boost::shared_ptr<Association_data > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data ,  user_information)

 
		AARE_apdu__impl()  : aSO_context_name() , result() , result_source_diagnostic() , responding_AP_title() , responding_AE_qualifier() , responding_authentication_value() , aSO_context_name_list() , p_context_result_list() , called_asoi_tag() , calling_asoi_tag() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(protocol_version ,0);
			BOOST_ASN_EXPLICIT_TAG(aSO_context_name ,1);
			BOOST_ASN_EXPLICIT_TAG(result ,2);
			BOOST_ASN_CHOICE_TAG(result_source_diagnostic ,3);
			BOOST_ASN_CHOICE_TAG(responding_AP_title ,4);
			BOOST_ASN_CHOICE_TAG(responding_AE_qualifier ,5);
			BOOST_ASN_EXPLICIT_TAG(responding_AP_invocation_identifier ,6);
			BOOST_ASN_EXPLICIT_TAG(responding_AE_invocation_identifier ,7);
			BOOST_ASN_IMPLICIT_TAG(responder_acse_requirements ,8);
			BOOST_ASN_IMPLICIT_TAG(mechanism_name ,9);
			BOOST_ASN_CHOICE_TAG(responding_authentication_value ,10);
			BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list ,11);
			BOOST_ASN_IMPLICIT_TAG(implementation_information ,29);
			BOOST_ASN_IMPLICIT_TAG(p_context_result_list ,12);
			BOOST_ASN_IMPLICIT_TAG(called_asoi_tag ,13);
			BOOST_ASN_IMPLICIT_TAG(calling_asoi_tag ,14);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AARQ_apdu__impl{


		//static const bitstring_type protocol_version_version1= bitstring_type(true, 0);


		boost::shared_ptr<bitstring_type > protocol_version;   //  DEFAULT  {version1} 
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type ,  protocol_version)

 		boost::asn1::value_holder<ASO_context_name >  aSO_context_name;
		boost::shared_ptr<AP_title >  called_AP_title;
		BOOST_ASN_VALUE_FUNC_DECLARATE(AP_title , called_AP_title)                
		boost::shared_ptr<AE_qualifier >  called_AE_qualifier;
		BOOST_ASN_VALUE_FUNC_DECLARATE(AE_qualifier ,  called_AE_qualifier)                      
		boost::shared_ptr<AP_invocation_identifier > called_AP_invocation_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AP_invocation_identifier ,  called_AP_invocation_identifier)

 		boost::shared_ptr<AE_invocation_identifier > called_AE_invocation_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AE_invocation_identifier ,  called_AE_invocation_identifier)

 		boost::shared_ptr<AP_title >  calling_AP_title;
		BOOST_ASN_VALUE_FUNC_DECLARATE(AP_title ,  calling_AP_title)                
		boost::shared_ptr<AE_qualifier >  calling_AE_qualifier;
		BOOST_ASN_VALUE_FUNC_DECLARATE(AE_qualifier ,  calling_AE_qualifier)
		boost::shared_ptr<AP_invocation_identifier > calling_AP_invocation_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AP_invocation_identifier ,  calling_AP_invocation_identifier)

 		boost::shared_ptr<AE_invocation_identifier > calling_AE_invocation_identifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AE_invocation_identifier ,  calling_AE_invocation_identifier)

 		boost::shared_ptr<ACSE_requirements > sender_acse_requirements;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ACSE_requirements ,  sender_acse_requirements)

 		boost::shared_ptr<Mechanism_name > mechanism_name;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Mechanism_name ,  mechanism_name)

 		boost::shared_ptr<Authentication_value >  calling_authentication_value;
		boost::shared_ptr<ASO_context_name_list > aSO_context_name_list;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASO_context_name_list ,  aSO_context_name_list)

 		boost::shared_ptr<Implementation_data > implementation_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Implementation_data ,  implementation_information)

 		boost::shared_ptr<Syntactic_context_list >  p_context_definition_list;
		boost::shared_ptr<ASOI_tag > called_asoi_tag;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag ,  called_asoi_tag)

 		boost::shared_ptr<ASOI_tag > calling_asoi_tag;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ASOI_tag ,  calling_asoi_tag)

 		boost::shared_ptr<Association_data > user_information;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Association_data ,  user_information)

 
		AARQ_apdu__impl()  : aSO_context_name() , called_AP_title() , called_AE_qualifier() , calling_AP_title() , calling_AE_qualifier() , calling_authentication_value() , aSO_context_name_list() , p_context_definition_list() , called_asoi_tag() , calling_asoi_tag() , user_information()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(protocol_version ,0);
			BOOST_ASN_EXPLICIT_TAG(aSO_context_name ,1);
			BOOST_ASN_CHOICE_TAG(called_AP_title ,2);
			BOOST_ASN_CHOICE_TAG(called_AE_qualifier ,3);
			BOOST_ASN_EXPLICIT_TAG(called_AP_invocation_identifier ,4);
			BOOST_ASN_EXPLICIT_TAG(called_AE_invocation_identifier ,5);
			BOOST_ASN_CHOICE_TAG(calling_AP_title ,6);
			BOOST_ASN_CHOICE_TAG(calling_AE_qualifier ,7);
			BOOST_ASN_EXPLICIT_TAG(calling_AP_invocation_identifier ,8);
			BOOST_ASN_EXPLICIT_TAG(calling_AE_invocation_identifier ,9);
			BOOST_ASN_IMPLICIT_TAG(sender_acse_requirements ,10);
			BOOST_ASN_IMPLICIT_TAG(mechanism_name ,11);
			BOOST_ASN_CHOICE_TAG(calling_authentication_value ,12);
			BOOST_ASN_IMPLICIT_TAG(aSO_context_name_list ,13);
			BOOST_ASN_IMPLICIT_TAG(implementation_information ,29);
			BOOST_ASN_CHOICE_TAG(p_context_definition_list ,14);
			BOOST_ASN_IMPLICIT_TAG(called_asoi_tag ,15);
			BOOST_ASN_IMPLICIT_TAG(calling_asoi_tag ,16);
			BOOST_ASN_IMPLICIT_TAG(user_information ,30);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum ACSE_apdu_enum {
		ACSE_apdu_null = 0  , 
		ACSE_apdu_aarq , 
		ACSE_apdu_aare , 
		ACSE_apdu_rlrq , 
		ACSE_apdu_rlre , 
		ACSE_apdu_abrt , 
		ACSE_apdu_adt , 
		ACSE_apdu_acrq , 
		ACSE_apdu_acrp , 
	};

	struct  ACSE_apdu : public BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) {


		ACSE_apdu() : BOOST_ASN_CHOICE_STRUCT(ACSE_apdu_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(aarq, AARQ_apdu,  ACSE_apdu_aarq)
		BOOST_ASN_VALUE_CHOICE(aare, AARE_apdu,  ACSE_apdu_aare)
		BOOST_ASN_VALUE_CHOICE(rlrq, RLRQ_apdu,  ACSE_apdu_rlrq)
		BOOST_ASN_VALUE_CHOICE(rlre, RLRE_apdu,  ACSE_apdu_rlre)
		BOOST_ASN_VALUE_CHOICE(abrt, ABRT_apdu,  ACSE_apdu_abrt)
		BOOST_ASN_VALUE_CHOICE(adt, A_DT_apdu,  ACSE_apdu_adt)
		BOOST_ASN_VALUE_CHOICE(acrq, ACRQ_apdu,  ACSE_apdu_acrq)
		BOOST_ASN_VALUE_CHOICE(acrp, ACRP_apdu,  ACSE_apdu_acrp)

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
						 if(BOOST_ASN_BIND_TAG(value<AARQ_apdu > (true , ACSE_apdu_aarq))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<AARE_apdu > (true , ACSE_apdu_aare))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<RLRQ_apdu > (true , ACSE_apdu_rlrq))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<RLRE_apdu > (true , ACSE_apdu_rlre))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<ABRT_apdu > (true , ACSE_apdu_abrt))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<A_DT_apdu > (true , ACSE_apdu_adt))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<ACRQ_apdu > (true , ACSE_apdu_acrq))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<ACRP_apdu > (true , ACSE_apdu_acrp))) return; else free();
					;}}}
			else {
				 switch(type()){
					case ACSE_apdu_aarq: {BOOST_ASN_BIND_TAG(value<AARQ_apdu > (false , ACSE_apdu_aarq)); break;}
					case ACSE_apdu_aare: {BOOST_ASN_BIND_TAG(value<AARE_apdu > (false , ACSE_apdu_aare)); break;}
					case ACSE_apdu_rlrq: {BOOST_ASN_BIND_TAG(value<RLRQ_apdu > (false , ACSE_apdu_rlrq)); break;}
					case ACSE_apdu_rlre: {BOOST_ASN_BIND_TAG(value<RLRE_apdu > (false , ACSE_apdu_rlre)); break;}
					case ACSE_apdu_abrt: {BOOST_ASN_BIND_TAG(value<ABRT_apdu > (false , ACSE_apdu_abrt)); break;}
					case ACSE_apdu_adt: {BOOST_ASN_BIND_TAG(value<A_DT_apdu > (false , ACSE_apdu_adt)); break;}
					case ACSE_apdu_acrq: {BOOST_ASN_BIND_TAG(value<ACRQ_apdu > (false , ACSE_apdu_acrq)); break;}
					case ACSE_apdu_acrp: {BOOST_ASN_BIND_TAG(value<ACRP_apdu > (false , ACSE_apdu_acrp)); break;}
					default:{}}}
		}
	};


}


BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::ACSE_apdu) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::AP_title) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::ASO_qualifier) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::AE_title) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::Syntactic_context_list) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::Associate_source_diagnostic) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::User_Data) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::PDV_list::presentation_data_values_type) 
BOOST_ASN_CHOISE_REGESTRATE(ACSE_1::Authentication_value) 

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif