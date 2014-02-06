#ifndef	_MMS_SCI_Module_1_H_
#define	_MMS_SCI_Module_1_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif


const boost::array<boost::asn1::oidindx_type, 5 >  MMS_SCI_Module_1_OID_ARR = { 2  ,  2  ,  9506  ,  2  ,  2 };
const boost::asn1::oid_type MMS_SCI_Module_1_OID = boost::asn1::oid_type(MMS_SCI_Module_1_OID_ARR);


namespace MMS_SCI_Module_1  {


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

	//  type is  SEQUENCE
	struct  SCI_Information;

 	//  type is  SEQUENCE
	struct  VMD_File;

 	//  type is  SEQUENCE
	struct  Access_Control_List_instance;

 	//  type is  SEQUENCE
	struct  Domain_instance;

 	//  type is  SEQUENCE
	struct  Program_Invocation_instance;

 	//  type is  SEQUENCE
	struct  Unit_Control_instance;

 	//  type is  SEQUENCE
	struct  Unnamed_Variable_instance;

 	//  type is  SEQUENCE
	struct  Named_Variable_instance;

 	//  type is  SEQUENCE
	struct  Named_Variable_List_instance;

 	//  type is  SEQUENCE
	struct  Variable_List_Item_instance;

 	//  type is  SEQUENCE
	struct  Named_Type_instance;

 	//  type is  SEQUENCE
	struct  Data_Exchange_instance;

 	//  type is  SEQUENCE
	struct  Semaphore_instance;

 	//  type is  SEQUENCE
	struct  Operator_Station_instance;

 	//  type is  SEQUENCE
	struct  Event_Condition_instance;

 	//  type is  SEQUENCE
	struct  Event_Action_instance;

 	//  type is  SEQUENCE
	struct  Event_Enrollment_instance;

 	//  type is  SEQUENCE
	struct  Event_Condition_List_instance;

 	//  type is  SEQUENCE
	struct  Journal_instance;

 	//  type is  SEQUENCE
	struct  Journal_Entry_instance;

 	//  type is  SEQUENCE
	struct  Service_and_Parameter_CBBs;

 	//  type is  SEQUENCE
	struct  GeneralManagementParameters;

 	//  type is  SEQUENCE
	struct  VMDSupportParameters;

 	//  type is  SEQUENCE
	struct  DomainManagementParameters;

 	//  type is  SEQUENCE
	struct  ProgramInvocationManagementParameters;

 	//  type is  SEQUENCE
	struct  VariableAccessParameters;

 	//  type is  SEQUENCE
	struct  DataParameters;

 	//  type is  SEQUENCE
	struct  SemaphoreManagementParameters;

 	//  type is  SEQUENCE
	struct  OperatorCommunicationParameters;

 	//  type is  SEQUENCE
	struct  ErrorParameters;

 	//  type is  SEQUENCE
	struct  FileManagementParameters;

 }
#include "MMS-Environment-1.h"
#include "MMS-Object-Module-1.h"
#include "ISO-9506-MMS-1.h"
 


namespace MMS_SCI_Module_1  {

 
	//import type
	using MMS_Environment_1::ApplicationReference;
	using MMS_Object_Module_1::AccessCondition;
	using MMS_Object_Module_1::AdditionalCBBOptions;
	using MMS_Object_Module_1::AdditionalSupportOptions;
	using MMS_Object_Module_1::Address;
	using MMS_Object_Module_1::AlarmAckRule;
	using MMS_Object_Module_1::Control_State;
	using MMS_Object_Module_1::DomainState;
	using MMS_Object_Module_1::EC_Class;
	using MMS_Object_Module_1::EC_State;
	using MMS_Object_Module_1::EE_Duration;
	using MMS_Object_Module_1::EE_Class;
	using MMS_Object_Module_1::LogicalStatus;
	using MMS_Object_Module_1::Modifier;
	using MMS_Object_Module_1::ParameterSupportOptions;
	using MMS_Object_Module_1::PhysicalStatus;
	using MMS_Object_Module_1::Priority;
	using MMS_Object_Module_1::ProgramInvocationState;
	using MMS_Object_Module_1::ServiceSupportOptions;
	using MMS_Object_Module_1::Severity;
	using MMS_Object_Module_1::Transitions;
	using MMS_Object_Module_1::TypeDescription;
	using ISO_9506_MMS_1::AlternateAccess;
	using ISO_9506_MMS_1::ConfirmedServiceRequest;
	using ISO_9506_MMS_1::AttachToEventCondition;
	using ISO_9506_MMS_1::AttachToSemaphore;
	using ISO_9506_MMS_1::Data;
	using ISO_9506_MMS_1::EE_State;
	using ISO_9506_MMS_1::Identifier;
	using ISO_9506_MMS_1::Integer8;
	using ISO_9506_MMS_1::Integer32;
	using ISO_9506_MMS_1::MMSString;
	using ISO_9506_MMS_1::MMS255String;
	using ISO_9506_MMS_1::ObjectName;
	using ISO_9506_MMS_1::TimeOfDay;
	using ISO_9506_MMS_1::TypeSpecification;
	using ISO_9506_MMS_1::Unsigned32;
	using ISO_9506_MMS_1::Unsigned8;
 
//start==============================================================
//It is   SEQUENCE  

	struct  FileManagementParameters{

		boost::asn1::value_holder<MMSString >  fileName;

		FileManagementParameters()  : fileName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(fileName ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ErrorParameters{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  additionalDetial_type{


			boost::asn1::value_holder<int >  size;
			boost::asn1::value_holder<MMSString >  syntax;

			additionalDetial_type()  : size() , syntax()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(size ,2);
				BOOST_ASN_EXPLICIT_TAG(syntax ,3);
			}
		};

	//end==============================================================

		boost::asn1::value_holder<MMSString >  additionalCode;
		boost::asn1::value_holder<additionalDetial_type >  additionalDetial;

		ErrorParameters()  : additionalCode() , additionalDetial()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(additionalCode ,0);
			BOOST_ASN_IMPLICIT_TAG(additionalDetial ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  OperatorCommunicationParameters{


		boost::asn1::value_holder<int >  input_time_out;

		OperatorCommunicationParameters()  : input_time_out()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(input_time_out ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  SemaphoreManagementParameters{

		boost::asn1::value_holder<MMSString >  algorithm;

		SemaphoreManagementParameters()  : algorithm()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(algorithm ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DataParameters{




	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  floating_point_type{



			boost::asn1::value_holder<int >  total;
			boost::asn1::value_holder<int >  exponent;

			floating_point_type()  : total() , exponent()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(total ,4);
				BOOST_ASN_IMPLICIT_TAG(exponent ,5);
			}
		};

	//end==============================================================






		boost::shared_ptr<int > bit_string;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  bit_string)

 		boost::shared_ptr<int > integer;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  integer)

 		boost::shared_ptr<int > unsignedV;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  unsignedV)

 		boost::shared_ptr<floating_point_type > floating_point;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(floating_point_type ,  floating_point)

 		boost::shared_ptr<int > octet_string;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  octet_string)

 		boost::shared_ptr<int > visible_string;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  visible_string)

 		boost::shared_ptr<bool > binary_time;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  binary_time)

 		boost::shared_ptr<int > bcd;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  bcd)

 		boost::shared_ptr<int > mmsString;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  mmsString)

 
		DataParameters()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(bit_string ,0);
			BOOST_ASN_IMPLICIT_TAG(integer ,1);
			BOOST_ASN_IMPLICIT_TAG(unsignedV ,2);
			BOOST_ASN_IMPLICIT_TAG(floating_point ,3);
			BOOST_ASN_IMPLICIT_TAG(octet_string ,10);
			BOOST_ASN_IMPLICIT_TAG(visible_string ,11);
			BOOST_ASN_IMPLICIT_TAG(binary_time ,12);
			BOOST_ASN_IMPLICIT_TAG(bcd ,13);
			BOOST_ASN_IMPLICIT_TAG(mmsString ,14);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  VariableAccessParameters{



		boost::asn1::value_holder<MMSString >  uninterruptibleAccess;
		boost::asn1::value_holder<bool >  singleMode;
		boost::asn1::value_holder<bool >  unnamedMode;

		VariableAccessParameters()  : uninterruptibleAccess() , singleMode() , unnamedMode()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(uninterruptibleAccess ,0);
			BOOST_ASN_IMPLICIT_TAG(singleMode ,1);
			BOOST_ASN_IMPLICIT_TAG(unnamedMode ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ProgramInvocationManagementParameters{

		//   SEQUENCE_OF is executionArgSyntaxes 
		typedef std::vector<oid_type >   executionArgSyntaxes_type;



		boost::asn1::value_holder<int >  executionArgMaxSize;
		boost::asn1::value_holder<MMSString >  executionArgParseRules;
		boost::asn1::value_holder<executionArgSyntaxes_type >  executionArgSyntaxes;
		boost::asn1::value_holder<MMSString >  programLoction;
		boost::asn1::value_holder<bool >  stepMode;

		ProgramInvocationManagementParameters()  : executionArgMaxSize() , executionArgParseRules() , executionArgSyntaxes() , programLoction() , stepMode()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(executionArgMaxSize ,0);
			BOOST_ASN_EXPLICIT_TAG(executionArgParseRules ,1);
			BOOST_ASN_IMPLICIT_TAG(executionArgSyntaxes ,2);
			BOOST_ASN_EXPLICIT_TAG(programLoction ,3);
			BOOST_ASN_IMPLICIT_TAG(stepMode ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DomainManagementParameters{
		//   SEQUENCE_OF is loadDataSyntax 
		typedef std::vector<oid_type >   loadDataSyntax_type;



		boost::asn1::value_holder<MMSString >  loadDataOctet;
		boost::asn1::value_holder<loadDataSyntax_type >  loadDataSyntax;
		boost::asn1::value_holder<int >  maxUploads;

		DomainManagementParameters()  : loadDataOctet() , loadDataSyntax() , maxUploads()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(loadDataOctet ,0);
			BOOST_ASN_IMPLICIT_TAG(loadDataSyntax ,1);
			BOOST_ASN_IMPLICIT_TAG(maxUploads ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  VMDSupportParameters{

		boost::asn1::value_holder<MMSString >  localDetail;
		boost::asn1::value_holder<MMSString >  extendedDerivation;

		VMDSupportParameters()  : localDetail() , extendedDerivation()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(localDetail ,0);
			BOOST_ASN_EXPLICIT_TAG(extendedDerivation ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GeneralManagementParameters{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  supportForTime_type{



			boost::asn1::value_holder<bool >  timeOfDay;
			boost::asn1::value_holder<bool >  timeSequence;

			supportForTime_type()  : timeOfDay() , timeSequence()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(timeOfDay ,2);
				BOOST_ASN_IMPLICIT_TAG(timeSequence ,3);
			}
		};

	//end==============================================================


		boost::asn1::value_holder<MMSString >  localDetail;
		boost::asn1::value_holder<supportForTime_type >  supportForTime;
		boost::asn1::value_holder<int >  granularityOfTime;

		GeneralManagementParameters()  : localDetail() , supportForTime() , granularityOfTime()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(localDetail ,0);
			BOOST_ASN_IMPLICIT_TAG(supportForTime ,1);
			BOOST_ASN_IMPLICIT_TAG(granularityOfTime ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Service_and_Parameter_CBBs{


		boost::asn1::value_holder<ServiceSupportOptions >  services_Client;
		boost::asn1::value_holder<ServiceSupportOptions >  services_Server;
		boost::asn1::value_holder<ParameterSupportOptions >  parameters;
		boost::asn1::value_holder<int >  nest;
		boost::asn1::value_holder<AdditionalSupportOptions >  extendedServices_Client;
		boost::asn1::value_holder<AdditionalSupportOptions >  extendedServices_Server;
		boost::asn1::value_holder<AdditionalCBBOptions >  extendedParameters;
		boost::asn1::value_holder<GeneralManagementParameters >  generalManagement;
		boost::asn1::value_holder<VMDSupportParameters >  vMDSupport;
		boost::asn1::value_holder<DomainManagementParameters >  domainManagement;
		boost::asn1::value_holder<ProgramInvocationManagementParameters >  programInvocation;
		boost::asn1::value_holder<VariableAccessParameters >  variableAccess;
		boost::asn1::value_holder<DataParameters >  dataParameters;
		boost::asn1::value_holder<SemaphoreManagementParameters >  semaphoreManagement;
		boost::asn1::value_holder<OperatorCommunicationParameters >  operatorCommunication;
		boost::asn1::value_holder<ErrorParameters >  errors;
		boost::asn1::value_holder<FileManagementParameters >  fileManagement;

		Service_and_Parameter_CBBs()  : services_Client() , services_Server() , parameters() , nest() , extendedServices_Client() , extendedServices_Server() , extendedParameters() , generalManagement() , vMDSupport() , domainManagement() , programInvocation() , variableAccess() , dataParameters() , semaphoreManagement() , operatorCommunication() , errors() , fileManagement()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(services_Client ,0);
			BOOST_ASN_IMPLICIT_TAG(services_Server ,1);
			BOOST_ASN_IMPLICIT_TAG(parameters ,2);
			BOOST_ASN_IMPLICIT_TAG(nest ,3);
			BOOST_ASN_IMPLICIT_TAG(extendedServices_Client ,4);
			BOOST_ASN_IMPLICIT_TAG(extendedServices_Server ,5);
			BOOST_ASN_IMPLICIT_TAG(extendedParameters ,6);
			BOOST_ASN_IMPLICIT_TAG(generalManagement ,7);
			BOOST_ASN_IMPLICIT_TAG(vMDSupport ,8);
			BOOST_ASN_IMPLICIT_TAG(domainManagement ,9);
			BOOST_ASN_IMPLICIT_TAG(programInvocation ,10);
			BOOST_ASN_IMPLICIT_TAG(variableAccess ,11);
			BOOST_ASN_IMPLICIT_TAG(dataParameters ,12);
			BOOST_ASN_IMPLICIT_TAG(semaphoreManagement ,13);
			BOOST_ASN_IMPLICIT_TAG(operatorCommunication ,14);
			BOOST_ASN_IMPLICIT_TAG(errors ,15);
			BOOST_ASN_IMPLICIT_TAG(fileManagement ,16);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Journal_Entry_instance{




	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  eventTransitionRecord_type{

			boost::asn1::value_holder<ObjectName >  name;
			boost::asn1::value_holder<EC_State >  currentState;

			eventTransitionRecord_type()  : name() , currentState()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE_TAG(name ,8);
				BOOST_ASN_IMPLICIT_TAG(currentState ,9);
			}
		};

	//end==============================================================
		//   SEQUENCE_OF is journalVariables 
			//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  journalVariables_type_sequence_of{

				boost::asn1::value_holder<MMS255String >  variableTag;
				boost::asn1::value_holder<Data >  valueSpecification;

				journalVariables_type_sequence_of()  : variableTag() , valueSpecification()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_EXPLICIT_TAG(variableTag ,11);
					BOOST_ASN_CHOICE_TAG(valueSpecification ,12);
				}
			};

		//end==============================================================
	typedef std::vector<journalVariables_type_sequence_of >   journalVariables_type;


		boost::shared_ptr<Journal_instance > journal;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Journal_instance ,  journal)

 		boost::asn1::value_holder<octetstring_type >  entry;
		boost::asn1::value_holder<ApplicationReference >  clientApplication;
		boost::asn1::value_holder<TimeOfDay >  timeStamp;
		boost::asn1::value_holder<int >  orderOfReceipt;
		boost::asn1::value_holder<enumerated_type >  informationType;
		boost::shared_ptr<MMS255String > textComment;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(MMS255String ,  textComment)

 		boost::shared_ptr<eventTransitionRecord_type > eventTransitionRecord;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(eventTransitionRecord_type ,  eventTransitionRecord)

 		boost::shared_ptr<journalVariables_type > journalVariables;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(journalVariables_type ,  journalVariables)

 
		Journal_Entry_instance()  : journal() , entry() , clientApplication() , timeStamp() , orderOfReceipt() , informationType()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(journal ,0);
			BOOST_ASN_IMPLICIT_TAG(entry ,1);
			BOOST_ASN_IMPLICIT_TAG(clientApplication ,2);
			BOOST_ASN_IMPLICIT_TAG(timeStamp ,3);
			BOOST_ASN_IMPLICIT_TAG(orderOfReceipt ,4);
			BOOST_ASN_IMPLICIT_TAG(informationType ,5);
			BOOST_ASN_EXPLICIT_TAG(textComment ,6);
			BOOST_ASN_IMPLICIT_TAG(eventTransitionRecord ,7);
			BOOST_ASN_IMPLICIT_TAG(journalVariables ,10);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Journal_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is entries 
				typedef std::vector<Journal_Entry_instance >   entries_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<entries_type >  entries;

				details_type()  : accessControl() , entries()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(entries ,4);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Journal_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Event_Condition_List_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is eventConditions 
				typedef std::vector<Event_Condition_instance >   eventConditions_type;

				//   SEQUENCE_OF is eventConditionLists 
				typedef std::vector<Event_Condition_List_instance >   eventConditionLists_type;

				//   SEQUENCE_OF is referencingEventConditionLists 
				typedef std::vector<Event_Condition_List_instance >   referencingEventConditionLists_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<eventConditions_type >  eventConditions;
				boost::asn1::value_holder<eventConditionLists_type >  eventConditionLists;
				boost::asn1::value_holder<referencingEventConditionLists_type >  referencingEventConditionLists;

				details_type()  : accessControl() , eventConditions() , eventConditionLists() , referencingEventConditionLists()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(eventConditions ,4);
					BOOST_ASN_IMPLICIT_TAG(eventConditionLists ,5);
					BOOST_ASN_IMPLICIT_TAG(referencingEventConditionLists ,6);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Event_Condition_List_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Event_Enrollment_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{

			//start==============================================================
			//It is  INTERNAL CHOICE

							enum remainingDelay_type_enum {
					remainingDelay_type_null = 0  , 
					remainingDelay_type_time , 
					remainingDelay_type_forever , 
				};

	struct  remainingDelay_type : public BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) {




					remainingDelay_type() : BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(time, int,  remainingDelay_type_time)
					BOOST_ASN_VALUE_CHOICE(forever, null_type,  remainingDelay_type_forever)

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
										case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , remainingDelay_type_time) ,7)) return; else free(); break;}
										case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , remainingDelay_type_forever) ,8)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case remainingDelay_type_time: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , remainingDelay_type_time) ,7); break;}
								case remainingDelay_type_forever: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , remainingDelay_type_forever) ,8); break;}
								default:{}}}
					}
				};



			//start==============================================================
			//It is  INTERNAL CHOICE

							enum displayEnhancement_type_enum {
					displayEnhancement_type_null = 0  , 
					displayEnhancement_type_text , 
					displayEnhancement_type_number , 
					displayEnhancement_type_none , 
				};

	struct  displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {




					displayEnhancement_type() : BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(text, MMSString,  displayEnhancement_type_text)
					BOOST_ASN_VALUE_CHOICE(number, int,  displayEnhancement_type_number)
					BOOST_ASN_VALUE_CHOICE(none, null_type,  displayEnhancement_type_none)

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
										case 13: { if(BOOST_ASN_EXPLICIT_TAG(value<MMSString > (true , displayEnhancement_type_text) ,13)) return; else free(); break;}
										case 14: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_number) ,14)) return; else free(); break;}
										case 15: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , displayEnhancement_type_none) ,15)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case displayEnhancement_type_text: {BOOST_ASN_EXPLICIT_TAG(value<MMSString > (false , displayEnhancement_type_text) ,13); break;}
								case displayEnhancement_type_number: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_number) ,14); break;}
								case displayEnhancement_type_none: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , displayEnhancement_type_none) ,15); break;}
								default:{}}}
					}
				};


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<EE_Class >  eeClass;
				boost::shared_ptr<Event_Condition_instance > eventCondition;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Event_Condition_instance ,  eventCondition)

 				boost::asn1::value_holder<Transitions >  ecTransitions;
				boost::asn1::value_holder<remainingDelay_type >  remainingDelay;
				boost::shared_ptr<Event_Action_instance > eventAction;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Event_Action_instance ,  eventAction)

 				boost::shared_ptr<EE_Duration > duration;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(EE_Duration ,  duration)

 				boost::shared_ptr<ApplicationReference > clientApplication;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  clientApplication)

 				boost::shared_ptr<AlarmAckRule > aaRule;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(AlarmAckRule ,  aaRule)

 				boost::asn1::value_holder<displayEnhancement_type >  displayEnhancement;

				details_type()  : accessControl() , eeClass() , eventCondition() , ecTransitions() , eventAction() , clientApplication() , displayEnhancement()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(eeClass ,4);
					BOOST_ASN_IMPLICIT_TAG(eventCondition ,5);
					BOOST_ASN_IMPLICIT_TAG(ecTransitions ,6);
					BOOST_ASN_CHOICE(remainingDelay);
					BOOST_ASN_IMPLICIT_TAG(eventAction ,9);
					BOOST_ASN_IMPLICIT_TAG(duration ,10);
					BOOST_ASN_IMPLICIT_TAG(clientApplication ,11);
					BOOST_ASN_IMPLICIT_TAG(aaRule ,12);
					BOOST_ASN_EXTENTION;
					BOOST_ASN_CHOICE(displayEnhancement);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Event_Enrollment_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Event_Action_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is modifiers 
				typedef std::vector<Modifier >   modifiers_type;

				//   SEQUENCE_OF is eventEnrollments 
				typedef std::vector<Event_Enrollment_instance >   eventEnrollments_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<ConfirmedServiceRequest >  confirmedServiceRequest;
				boost::asn1::value_holder<modifiers_type >  modifiers;
				boost::asn1::value_holder<eventEnrollments_type >  eventEnrollments;

				details_type()  : accessControl() , confirmedServiceRequest() , modifiers() , eventEnrollments()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_CHOICE_TAG(confirmedServiceRequest ,4);
					BOOST_ASN_IMPLICIT_TAG(modifiers ,5);
					BOOST_ASN_IMPLICIT_TAG(eventEnrollments ,6);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Event_Action_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Event_Condition_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is eventEnrollments 
				typedef std::vector<Event_Enrollment_instance >   eventEnrollments_type;




			//start==============================================================
			//It is  INTERNAL CHOICE

							enum monitoredVariable_type_enum {
					monitoredVariable_type_null = 0  , 
					monitoredVariable_type_named , 
					monitoredVariable_type_unnamed , 
					monitoredVariable_type_unspecified , 
				};

	struct  monitoredVariable_type : public BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) {



					monitoredVariable_type() : BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(named, Named_Variable_instance,  monitoredVariable_type_named)
					BOOST_ASN_VALUE_CHOICE(unnamed, Unnamed_Variable_instance,  monitoredVariable_type_unnamed)
					BOOST_ASN_VALUE_CHOICE(unspecified, null_type,  monitoredVariable_type_unspecified)

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
										case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<Named_Variable_instance > (true , monitoredVariable_type_named) ,11)) return; else free(); break;}
										case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<Unnamed_Variable_instance > (true , monitoredVariable_type_unnamed) ,12)) return; else free(); break;}
										case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , monitoredVariable_type_unspecified) ,13)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case monitoredVariable_type_named: {BOOST_ASN_IMPLICIT_TAG(value<Named_Variable_instance > (false , monitoredVariable_type_named) ,11); break;}
								case monitoredVariable_type_unnamed: {BOOST_ASN_IMPLICIT_TAG(value<Unnamed_Variable_instance > (false , monitoredVariable_type_unnamed) ,12); break;}
								case monitoredVariable_type_unspecified: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , monitoredVariable_type_unspecified) ,13); break;}
								default:{}}}
					}
				};




			//start==============================================================
			//It is  INTERNAL CHOICE

							enum displayEnhancement_type_enum {
					displayEnhancement_type_null = 0  , 
					displayEnhancement_type_text , 
					displayEnhancement_type_number , 
					displayEnhancement_type_none , 
				};

	struct  displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {




					displayEnhancement_type() : BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(text, MMSString,  displayEnhancement_type_text)
					BOOST_ASN_VALUE_CHOICE(number, int,  displayEnhancement_type_number)
					BOOST_ASN_VALUE_CHOICE(none, null_type,  displayEnhancement_type_none)

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
										case 15: { if(BOOST_ASN_EXPLICIT_TAG(value<MMSString > (true , displayEnhancement_type_text) ,15)) return; else free(); break;}
										case 16: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_number) ,16)) return; else free(); break;}
										case 17: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , displayEnhancement_type_none) ,17)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case displayEnhancement_type_text: {BOOST_ASN_EXPLICIT_TAG(value<MMSString > (false , displayEnhancement_type_text) ,15); break;}
								case displayEnhancement_type_number: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_number) ,16); break;}
								case displayEnhancement_type_none: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , displayEnhancement_type_none) ,17); break;}
								default:{}}}
					}
				};


			//start==============================================================
			//It is  INTERNAL CHOICE

							enum group_Priority_Override_type_enum {
					group_Priority_Override_type_null = 0  , 
					group_Priority_Override_type_priority , 
					group_Priority_Override_type_undefined , 
				};

	struct  group_Priority_Override_type : public BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) {



					group_Priority_Override_type() : BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(priority, Priority,  group_Priority_Override_type_priority)
					BOOST_ASN_VALUE_CHOICE(undefined, null_type,  group_Priority_Override_type_undefined)

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
										case 18: { if(BOOST_ASN_IMPLICIT_TAG(value<Priority > (true , group_Priority_Override_type_priority) ,18)) return; else free(); break;}
										case 19: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , group_Priority_Override_type_undefined) ,19)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case group_Priority_Override_type_priority: {BOOST_ASN_IMPLICIT_TAG(value<Priority > (false , group_Priority_Override_type_priority) ,18); break;}
								case group_Priority_Override_type_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , group_Priority_Override_type_undefined) ,19); break;}
								default:{}}}
					}
				};

				//   SEQUENCE_OF is referencingEventConditionLists 
				typedef std::vector<Event_Condition_List_instance >   referencingEventConditionLists_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<EC_Class >  ecClass;
				boost::asn1::value_holder<EC_State >  ecState;
				boost::asn1::value_holder<Priority >  priority;
				boost::asn1::value_holder<Severity >  severity;
				boost::asn1::value_holder<eventEnrollments_type >  eventEnrollments;
				boost::shared_ptr<bool > enabled;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  enabled)

 				boost::shared_ptr<bool > alarmSummaryReports;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  alarmSummaryReports)

 				boost::asn1::value_holder<monitoredVariable_type >  monitoredVariable;
				boost::shared_ptr<int > evaluationInterval;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  evaluationInterval)

 				boost::asn1::value_holder<displayEnhancement_type >  displayEnhancement;
				boost::asn1::value_holder<group_Priority_Override_type >  group_Priority_Override;
				boost::shared_ptr<referencingEventConditionLists_type > referencingEventConditionLists;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(referencingEventConditionLists_type ,  referencingEventConditionLists)

 
				details_type()  : accessControl() , ecClass() , ecState() , priority() , severity() , eventEnrollments() , displayEnhancement() , referencingEventConditionLists()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(ecClass ,4);
					BOOST_ASN_IMPLICIT_TAG(ecState ,5);
					BOOST_ASN_IMPLICIT_TAG(priority ,6);
					BOOST_ASN_IMPLICIT_TAG(severity ,7);
					BOOST_ASN_IMPLICIT_TAG(eventEnrollments ,8);
					BOOST_ASN_IMPLICIT_TAG(enabled ,9);
					BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports ,10);
					BOOST_ASN_CHOICE(monitoredVariable);
					BOOST_ASN_IMPLICIT_TAG(evaluationInterval ,14);
					BOOST_ASN_EXTENTION;
					BOOST_ASN_CHOICE(displayEnhancement);
					BOOST_ASN_CHOICE(group_Priority_Override);
					BOOST_ASN_IMPLICIT_TAG(referencingEventConditionLists ,20);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Event_Condition_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Operator_Station_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<enumerated_type >  stationType;

				details_type()  : accessControl() , stationType()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(stationType ,4);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Operator_Station_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Semaphore_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{


				//   SEQUENCE_OF is namedTokens 
				typedef std::vector<visiblestring_type >   namedTokens_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<enumerated_type >  classV;
				boost::shared_ptr<int > numberOfTokens;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  numberOfTokens)

 				boost::shared_ptr<namedTokens_type > namedTokens;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(namedTokens_type ,  namedTokens)

 				boost::shared_ptr<Event_Condition_instance > eventCondition;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Event_Condition_instance ,  eventCondition)

 
				details_type()  : accessControl() , classV() , eventCondition()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(classV ,4);
					BOOST_ASN_IMPLICIT_TAG(numberOfTokens ,5);
					BOOST_ASN_IMPLICIT_TAG(namedTokens ,6);
					BOOST_ASN_IMPLICIT_TAG(eventCondition ,7);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Semaphore_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Data_Exchange_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is request 
				typedef std::vector<TypeDescription >   request_type;

				//   SEQUENCE_OF is response 
				typedef std::vector<TypeDescription >   response_type;



				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<request_type >  request;
				boost::asn1::value_holder<response_type >  response;
				boost::asn1::value_holder<bool >  linked;
				boost::shared_ptr<Program_Invocation_instance > programInvocation;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Program_Invocation_instance ,  programInvocation)

 
				details_type()  : accessControl() , request() , response() , linked() , programInvocation()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(request ,4);
					BOOST_ASN_IMPLICIT_TAG(response ,5);
					BOOST_ASN_IMPLICIT_TAG(linked ,6);
					BOOST_ASN_IMPLICIT_TAG(programInvocation ,7);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Data_Exchange_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Named_Type_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<TypeDescription >  typeDescription;
				boost::shared_ptr<visiblestring_type > meaning;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  meaning)

 
				details_type()  : accessControl() , typeDescription()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_CHOICE_TAG(typeDescription ,4);
					BOOST_ASN_IMPLICIT_TAG(meaning ,5);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Named_Type_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Variable_List_Item_instance{

		boost::shared_ptr<Unnamed_Variable_instance > unnamedItem;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unnamed_Variable_instance ,  unnamedItem)

 		boost::shared_ptr<Named_Variable_instance > namedItem;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Named_Variable_instance ,  namedItem)

 		boost::shared_ptr<AlternateAccess > alternateAccess;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess ,  alternateAccess)

 
		Variable_List_Item_instance()  : unnamedItem() , namedItem() , alternateAccess()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unnamedItem ,0);
			BOOST_ASN_IMPLICIT_TAG(namedItem ,1);
			BOOST_ASN_IMPLICIT_TAG(alternateAccess ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Named_Variable_List_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is listOfVariables 
				typedef std::vector<Variable_List_Item_instance >   listOfVariables_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<listOfVariables_type >  listOfVariables;

				details_type()  : accessControl() , listOfVariables()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(listOfVariables ,4);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Named_Variable_List_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Named_Variable_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<TypeDescription >  typeDescription;
				boost::asn1::value_holder<Address >  address;
				boost::shared_ptr<visiblestring_type > meaning;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  meaning)

 
				details_type()  : accessControl() , typeDescription() , address()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_CHOICE_TAG(typeDescription ,4);
					BOOST_ASN_CHOICE_TAG(address ,5);
					BOOST_ASN_IMPLICIT_TAG(meaning ,6);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Named_Variable_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Unnamed_Variable_instance{

		boost::asn1::value_holder<Address >  address;
		boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 		boost::asn1::value_holder<TypeDescription >  typeDescription;

		Unnamed_Variable_instance()  : address() , accessControl() , typeDescription()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(address ,0);
			BOOST_ASN_IMPLICIT_TAG(accessControl ,1);
			BOOST_ASN_CHOICE_TAG(typeDescription ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Unit_Control_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is domains 
				typedef std::vector<Domain_instance >   domains_type;

				//   SEQUENCE_OF is programInvocations 
				typedef std::vector<Program_Invocation_instance >   programInvocations_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<domains_type >  domains;
				boost::asn1::value_holder<programInvocations_type >  programInvocations;

				details_type()  : accessControl() , domains() , programInvocations()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_IMPLICIT_TAG(domains ,4);
					BOOST_ASN_IMPLICIT_TAG(programInvocations ,5);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Unit_Control_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Program_Invocation_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is domains 
				typedef std::vector<Domain_instance >   domains_type;

				//   SEQUENCE_OF is accessControl 
				typedef std::vector<Access_Control_List_instance >   accessControl_type;



				//   SEQUENCE_OF is eventCondition 
				typedef std::vector<Event_Condition_instance >   eventCondition_type;

				//   SEQUENCE_OF is eventAction 
				typedef std::vector<Event_Action_instance >   eventAction_type;

				//   SEQUENCE_OF is eventEnrollment 
				typedef std::vector<Event_Enrollment_instance >   eventEnrollment_type;


				//   SEQUENCE_OF is controlled-Program-Invocations 
				typedef std::vector<Program_Invocation_instance >   controlled_Program_Invocations_type;


				boost::asn1::value_holder<ProgramInvocationState >  programInvocationState;
				boost::asn1::value_holder<domains_type >  domains;
				boost::asn1::value_holder<accessControl_type >  accessControl;
				boost::asn1::value_holder<bool >  reusable;
				boost::asn1::value_holder<bool >  monitor;
				boost::shared_ptr<eventCondition_type > eventCondition;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(eventCondition_type ,  eventCondition)

 				boost::shared_ptr<eventAction_type > eventAction;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(eventAction_type ,  eventAction)

 				boost::shared_ptr<eventEnrollment_type > eventEnrollment;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(eventEnrollment_type ,  eventEnrollment)

 				boost::asn1::value_holder<MMSString >  executionArgument;
				boost::shared_ptr<Control_State > control;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Control_State ,  control)

 				boost::shared_ptr<Program_Invocation_instance > controlling_Program_Invocation;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Program_Invocation_instance ,  controlling_Program_Invocation)

 				boost::shared_ptr<controlled_Program_Invocations_type > controlled_Program_Invocations;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(controlled_Program_Invocations_type ,  controlled_Program_Invocations)

 
				details_type()  : programInvocationState() , domains() , accessControl() , reusable() , monitor() , executionArgument() , control() , controlling_Program_Invocation()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(programInvocationState ,3);
					BOOST_ASN_IMPLICIT_TAG(domains ,4);
					BOOST_ASN_IMPLICIT_TAG(accessControl ,5);
					BOOST_ASN_IMPLICIT_TAG(reusable ,6);
					BOOST_ASN_IMPLICIT_TAG(monitor ,7);
					BOOST_ASN_IMPLICIT_TAG(eventCondition ,8);
					BOOST_ASN_IMPLICIT_TAG(eventAction ,9);
					BOOST_ASN_IMPLICIT_TAG(eventEnrollment ,10);
					BOOST_ASN_EXPLICIT_TAG(executionArgument ,11);
					BOOST_ASN_EXTENTION;
					BOOST_ASN_IMPLICIT_TAG(control ,12);
					BOOST_ASN_IMPLICIT_TAG(controlling_Program_Invocation ,13);
					BOOST_ASN_IMPLICIT_TAG(controlled_Program_Invocations ,14);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Program_Invocation_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Domain_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is capabilities 
				typedef std::vector<MMSString >   capabilities_type;


				//   SEQUENCE_OF is programInvocations 
				typedef std::vector<Program_Invocation_instance >   programInvocations_type;

				//   SEQUENCE_OF is namedVariables 
				typedef std::vector<Named_Variable_instance >   namedVariables_type;

				//   SEQUENCE_OF is namedVariableLists 
				typedef std::vector<Named_Variable_List_instance >   namedVariableLists_type;

				//   SEQUENCE_OF is namedTypes 
				typedef std::vector<Named_Type_instance >   namedTypes_type;

				//   SEQUENCE_OF is eventConditions 
				typedef std::vector<Event_Condition_instance >   eventConditions_type;

				//   SEQUENCE_OF is eventActions 
				typedef std::vector<Event_Action_instance >   eventActions_type;

				//   SEQUENCE_OF is eventEnrollments 
				typedef std::vector<Event_Enrollment_instance >   eventEnrollments_type;

				//   SEQUENCE_OF is eventConditionLists 
				typedef std::vector<Event_Condition_List_instance >   eventConditionLists_type;


				boost::asn1::value_holder<capabilities_type >  capabilities;
				boost::asn1::value_holder<DomainState >  state;
				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<bool >  sharable;
				boost::asn1::value_holder<programInvocations_type >  programInvocations;
				boost::asn1::value_holder<namedVariables_type >  namedVariables;
				boost::asn1::value_holder<namedVariableLists_type >  namedVariableLists;
				boost::asn1::value_holder<namedTypes_type >  namedTypes;
				boost::asn1::value_holder<eventConditions_type >  eventConditions;
				boost::asn1::value_holder<eventActions_type >  eventActions;
				boost::asn1::value_holder<eventEnrollments_type >  eventEnrollments;
				boost::asn1::value_holder<eventConditionLists_type >  eventConditionLists;

				details_type()  : capabilities() , state() , accessControl() , sharable() , programInvocations() , namedVariables() , namedVariableLists() , namedTypes() , eventConditions() , eventActions() , eventEnrollments() , eventConditionLists()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(capabilities ,3);
					BOOST_ASN_IMPLICIT_TAG(state ,4);
					BOOST_ASN_IMPLICIT_TAG(accessControl ,5);
					BOOST_ASN_IMPLICIT_TAG(sharable ,6);
					BOOST_ASN_IMPLICIT_TAG(programInvocations ,7);
					BOOST_ASN_IMPLICIT_TAG(namedVariables ,8);
					BOOST_ASN_IMPLICIT_TAG(namedVariableLists ,9);
					BOOST_ASN_IMPLICIT_TAG(namedTypes ,10);
					BOOST_ASN_IMPLICIT_TAG(eventConditions ,11);
					BOOST_ASN_IMPLICIT_TAG(eventActions ,12);
					BOOST_ASN_IMPLICIT_TAG(eventEnrollments ,13);
					BOOST_ASN_IMPLICIT_TAG(eventConditionLists ,14);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Domain_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Access_Control_List_instance{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum definition_type_enum {
			definition_type_null = 0  , 
			definition_type_reference , 
			definition_type_details , 
		};

	struct  definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  details_type{
				//   SEQUENCE_OF is accessControlLists 
				typedef std::vector<Access_Control_List_instance >   accessControlLists_type;

				//   SEQUENCE_OF is domains 
				typedef std::vector<Domain_instance >   domains_type;

				//   SEQUENCE_OF is programInvocations 
				typedef std::vector<Program_Invocation_instance >   programInvocations_type;

				//   SEQUENCE_OF is unitControls 
				typedef std::vector<Unit_Control_instance >   unitControls_type;

				//   SEQUENCE_OF is unnamedVariables 
				typedef std::vector<Unnamed_Variable_instance >   unnamedVariables_type;

				//   SEQUENCE_OF is namedVariables 
				typedef std::vector<Named_Variable_instance >   namedVariables_type;

				//   SEQUENCE_OF is namedVariableLists 
				typedef std::vector<Named_Variable_List_instance >   namedVariableLists_type;

				//   SEQUENCE_OF is namedTypes 
				typedef std::vector<Named_Type_instance >   namedTypes_type;

				//   SEQUENCE_OF is dataExchanges 
				typedef std::vector<Data_Exchange_instance >   dataExchanges_type;

				//   SEQUENCE_OF is semaphores 
				typedef std::vector<Semaphore_instance >   semaphores_type;

				//   SEQUENCE_OF is operatorStations 
				typedef std::vector<Operator_Station_instance >   operatorStations_type;

				//   SEQUENCE_OF is eventConditions 
				typedef std::vector<Event_Condition_instance >   eventConditions_type;

				//   SEQUENCE_OF is eventActions 
				typedef std::vector<Event_Action_instance >   eventActions_type;

				//   SEQUENCE_OF is eventEnrollments 
				typedef std::vector<Event_Enrollment_instance >   eventEnrollments_type;

				//   SEQUENCE_OF is journals 
				typedef std::vector<Journal_instance >   journals_type;


				//   SEQUENCE_OF is eventConditionLists 
				typedef std::vector<Event_Condition_List_instance >   eventConditionLists_type;


				boost::shared_ptr<Access_Control_List_instance > accessControl;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(Access_Control_List_instance ,  accessControl)

 				boost::asn1::value_holder<AccessCondition >  readAccessCondition;
				boost::asn1::value_holder<AccessCondition >  storeAccessCondition;
				boost::asn1::value_holder<AccessCondition >  writeAccessCondition;
				boost::asn1::value_holder<AccessCondition >  loadAccessCondition;
				boost::asn1::value_holder<AccessCondition >  executeAccessCondition;
				boost::asn1::value_holder<AccessCondition >  deleteAccessCondition;
				boost::asn1::value_holder<AccessCondition >  editAccessCondition;
				boost::asn1::value_holder<accessControlLists_type >  accessControlLists;
				boost::asn1::value_holder<domains_type >  domains;
				boost::asn1::value_holder<programInvocations_type >  programInvocations;
				boost::asn1::value_holder<unitControls_type >  unitControls;
				boost::asn1::value_holder<unnamedVariables_type >  unnamedVariables;
				boost::asn1::value_holder<namedVariables_type >  namedVariables;
				boost::asn1::value_holder<namedVariableLists_type >  namedVariableLists;
				boost::asn1::value_holder<namedTypes_type >  namedTypes;
				boost::asn1::value_holder<dataExchanges_type >  dataExchanges;
				boost::asn1::value_holder<semaphores_type >  semaphores;
				boost::asn1::value_holder<operatorStations_type >  operatorStations;
				boost::asn1::value_holder<eventConditions_type >  eventConditions;
				boost::asn1::value_holder<eventActions_type >  eventActions;
				boost::asn1::value_holder<eventEnrollments_type >  eventEnrollments;
				boost::asn1::value_holder<journals_type >  journals;
				boost::shared_ptr<eventConditionLists_type > eventConditionLists;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(eventConditionLists_type ,  eventConditionLists)

 
				details_type()  : accessControl() , readAccessCondition() , storeAccessCondition() , writeAccessCondition() , loadAccessCondition() , executeAccessCondition() , deleteAccessCondition() , editAccessCondition() , accessControlLists() , domains() , programInvocations() , unitControls() , unnamedVariables() , namedVariables() , namedVariableLists() , namedTypes() , dataExchanges() , semaphores() , operatorStations() , eventConditions() , eventActions() , eventEnrollments() , journals() , eventConditionLists()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(accessControl ,3);
					BOOST_ASN_CHOICE_TAG(readAccessCondition ,4);
					BOOST_ASN_CHOICE_TAG(storeAccessCondition ,5);
					BOOST_ASN_CHOICE_TAG(writeAccessCondition ,6);
					BOOST_ASN_CHOICE_TAG(loadAccessCondition ,7);
					BOOST_ASN_CHOICE_TAG(executeAccessCondition ,8);
					BOOST_ASN_CHOICE_TAG(deleteAccessCondition ,9);
					BOOST_ASN_CHOICE_TAG(editAccessCondition ,10);
					BOOST_ASN_IMPLICIT_TAG(accessControlLists ,11);
					BOOST_ASN_IMPLICIT_TAG(domains ,12);
					BOOST_ASN_IMPLICIT_TAG(programInvocations ,13);
					BOOST_ASN_IMPLICIT_TAG(unitControls ,14);
					BOOST_ASN_IMPLICIT_TAG(unnamedVariables ,15);
					BOOST_ASN_IMPLICIT_TAG(namedVariables ,16);
					BOOST_ASN_IMPLICIT_TAG(namedVariableLists ,17);
					BOOST_ASN_IMPLICIT_TAG(namedTypes ,18);
					BOOST_ASN_IMPLICIT_TAG(dataExchanges ,19);
					BOOST_ASN_IMPLICIT_TAG(semaphores ,20);
					BOOST_ASN_IMPLICIT_TAG(operatorStations ,21);
					BOOST_ASN_IMPLICIT_TAG(eventConditions ,22);
					BOOST_ASN_IMPLICIT_TAG(eventActions ,23);
					BOOST_ASN_IMPLICIT_TAG(eventEnrollments ,24);
					BOOST_ASN_IMPLICIT_TAG(journals ,25);
					BOOST_ASN_EXTENTION;
					BOOST_ASN_IMPLICIT_TAG(eventConditionLists ,26);
				}
			};

		//end==============================================================

			definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(reference, oid_type,  definition_type_reference)
			BOOST_ASN_VALUE_CHOICE(details, details_type,  definition_type_details)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case definition_type_reference: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference) ,1); break;}
						case definition_type_details: {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<definition_type >  definition;

		Access_Control_List_instance()  : name() , definition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(name ,0);
			BOOST_ASN_CHOICE(definition);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  VMD_File{

		//   SEQUENCE_OF is capabilities 
		typedef std::vector<MMSString >   capabilities_type;


		//   SEQUENCE_OF is accessControlLists 
		typedef std::vector<Access_Control_List_instance >   accessControlLists_type;

		//   SEQUENCE_OF is domains 
		typedef std::vector<Domain_instance >   domains_type;

		//   SEQUENCE_OF is programInvocations 
		typedef std::vector<Program_Invocation_instance >   programInvocations_type;

		//   SEQUENCE_OF is unitControls 
		typedef std::vector<Unit_Control_instance >   unitControls_type;

		//   SEQUENCE_OF is unnamedVariables 
		typedef std::vector<Unnamed_Variable_instance >   unnamedVariables_type;

		//   SEQUENCE_OF is namedVariables 
		typedef std::vector<Named_Variable_instance >   namedVariables_type;

		//   SEQUENCE_OF is namedVariableLists 
		typedef std::vector<Named_Variable_List_instance >   namedVariableLists_type;

		//   SEQUENCE_OF is namedTypes 
		typedef std::vector<Named_Type_instance >   namedTypes_type;

		//   SEQUENCE_OF is dataExchanges 
		typedef std::vector<Data_Exchange_instance >   dataExchanges_type;

		//   SEQUENCE_OF is semaphores 
		typedef std::vector<Semaphore_instance >   semaphores_type;

		//   SEQUENCE_OF is operatorStations 
		typedef std::vector<Operator_Station_instance >   operatorStations_type;

		//   SEQUENCE_OF is eventConditions 
		typedef std::vector<Event_Condition_instance >   eventConditions_type;

		//   SEQUENCE_OF is eventActions 
		typedef std::vector<Event_Action_instance >   eventActions_type;

		//   SEQUENCE_OF is eventEnrollments 
		typedef std::vector<Event_Enrollment_instance >   eventEnrollments_type;

		//   SEQUENCE_OF is eventConditionLists 
		typedef std::vector<Event_Condition_List_instance >   eventConditionLists_type;

		//   SEQUENCE_OF is journals 
		typedef std::vector<Journal_instance >   journals_type;



	//start==============================================================
	//It is  INTERNAL CHOICE

			enum selected_Program_Invocation_type_enum {
			selected_Program_Invocation_type_null = 0  , 
			selected_Program_Invocation_type_selectedProgram , 
			selected_Program_Invocation_type_noneSelected , 
		};

	struct  selected_Program_Invocation_type : public BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) {



			selected_Program_Invocation_type() : BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(selectedProgram, Program_Invocation_instance,  selected_Program_Invocation_type_selectedProgram)
			BOOST_ASN_VALUE_CHOICE(noneSelected, null_type,  selected_Program_Invocation_type_noneSelected)

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
								case 26: { if(BOOST_ASN_IMPLICIT_TAG(value<Program_Invocation_instance > (true , selected_Program_Invocation_type_selectedProgram) ,26)) return; else free(); break;}
								case 27: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , selected_Program_Invocation_type_noneSelected) ,27)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case selected_Program_Invocation_type_selectedProgram: {BOOST_ASN_IMPLICIT_TAG(value<Program_Invocation_instance > (false , selected_Program_Invocation_type_selectedProgram) ,26); break;}
						case selected_Program_Invocation_type_noneSelected: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , selected_Program_Invocation_type_noneSelected) ,27); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ApplicationReference >  executiveFunction;
		boost::asn1::value_holder<MMSString >  vendorName;
		boost::asn1::value_holder<MMSString >  modelName;
		boost::asn1::value_holder<MMSString >  revision;
		boost::asn1::value_holder<oid_type >  abstractSyntaxes;
		boost::asn1::value_holder<Access_Control_List_instance >  accessControl;
		boost::asn1::value_holder<LogicalStatus >  logicalStatus;
		boost::asn1::value_holder<capabilities_type >  capabilities;
		boost::asn1::value_holder<PhysicalStatus >  physicalStatus;
		boost::asn1::value_holder<bitstring_type >  local_detail;
		boost::asn1::value_holder<accessControlLists_type >  accessControlLists;
		boost::asn1::value_holder<domains_type >  domains;
		boost::asn1::value_holder<programInvocations_type >  programInvocations;
		boost::asn1::value_holder<unitControls_type >  unitControls;
		boost::asn1::value_holder<unnamedVariables_type >  unnamedVariables;
		boost::asn1::value_holder<namedVariables_type >  namedVariables;
		boost::asn1::value_holder<namedVariableLists_type >  namedVariableLists;
		boost::asn1::value_holder<namedTypes_type >  namedTypes;
		boost::asn1::value_holder<dataExchanges_type >  dataExchanges;
		boost::asn1::value_holder<semaphores_type >  semaphores;
		boost::asn1::value_holder<operatorStations_type >  operatorStations;
		boost::asn1::value_holder<eventConditions_type >  eventConditions;
		boost::asn1::value_holder<eventActions_type >  eventActions;
		boost::asn1::value_holder<eventEnrollments_type >  eventEnrollments;
		boost::asn1::value_holder<eventConditionLists_type >  eventConditionLists;
		boost::asn1::value_holder<journals_type >  journals;
		boost::asn1::value_holder<selected_Program_Invocation_type >  selected_Program_Invocation;

		VMD_File()  : executiveFunction() , vendorName() , modelName() , revision() , abstractSyntaxes() , accessControl() , logicalStatus() , capabilities() , physicalStatus() , local_detail() , accessControlLists() , domains() , programInvocations() , unitControls() , unnamedVariables() , namedVariables() , namedVariableLists() , namedTypes() , dataExchanges() , semaphores() , operatorStations() , eventConditions() , eventActions() , eventEnrollments() , eventConditionLists() , journals() , selected_Program_Invocation()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(executiveFunction ,0);
			BOOST_ASN_EXPLICIT_TAG(vendorName ,1);
			BOOST_ASN_EXPLICIT_TAG(modelName ,2);
			BOOST_ASN_EXPLICIT_TAG(revision ,3);
			BOOST_ASN_IMPLICIT_TAG(abstractSyntaxes ,4);
			BOOST_ASN_IMPLICIT_TAG(accessControl ,5);
			BOOST_ASN_IMPLICIT_TAG(logicalStatus ,6);
			BOOST_ASN_IMPLICIT_TAG(capabilities ,7);
			BOOST_ASN_IMPLICIT_TAG(physicalStatus ,8);
			BOOST_ASN_IMPLICIT_TAG(local_detail ,9);
			BOOST_ASN_IMPLICIT_TAG(accessControlLists ,10);
			BOOST_ASN_IMPLICIT_TAG(domains ,11);
			BOOST_ASN_IMPLICIT_TAG(programInvocations ,12);
			BOOST_ASN_IMPLICIT_TAG(unitControls ,13);
			BOOST_ASN_IMPLICIT_TAG(unnamedVariables ,14);
			BOOST_ASN_IMPLICIT_TAG(namedVariables ,15);
			BOOST_ASN_IMPLICIT_TAG(namedVariableLists ,16);
			BOOST_ASN_IMPLICIT_TAG(namedTypes ,17);
			BOOST_ASN_IMPLICIT_TAG(dataExchanges ,18);
			BOOST_ASN_IMPLICIT_TAG(semaphores ,19);
			BOOST_ASN_IMPLICIT_TAG(operatorStations ,20);
			BOOST_ASN_IMPLICIT_TAG(eventConditions ,21);
			BOOST_ASN_IMPLICIT_TAG(eventActions ,22);
			BOOST_ASN_IMPLICIT_TAG(eventEnrollments ,23);
			BOOST_ASN_IMPLICIT_TAG(eventConditionLists ,24);
			BOOST_ASN_IMPLICIT_TAG(journals ,25);
			BOOST_ASN_EXTENTION;
			BOOST_ASN_CHOICE(selected_Program_Invocation);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  SCI_Information{

		boost::asn1::value_holder<VMD_File >  partOne;
		boost::asn1::value_holder<Service_and_Parameter_CBBs >  partTwo;

		SCI_Information()  : partOne() , partTwo()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(partOne ,0);
			BOOST_ASN_IMPLICIT_TAG(partTwo ,1);
		}
	};

//end==============================================================

}


BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::VMD_File::selected_Program_Invocation_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Access_Control_List_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Domain_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Program_Invocation_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Unit_Control_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Variable_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Variable_List_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Type_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Data_Exchange_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Semaphore_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Operator_Station_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type::details_type::monitoredVariable_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type::details_type::displayEnhancement_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type::details_type::group_Priority_Override_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Action_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::definition_type::details_type::remainingDelay_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::definition_type::details_type::displayEnhancement_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_List_instance::definition_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Journal_instance::definition_type) 

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif