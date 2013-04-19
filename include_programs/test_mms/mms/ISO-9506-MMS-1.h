#ifndef	_ISO_9506_MMS_1_H_
#define	_ISO_9506_MMS_1_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif


const boost::array<boost::asn1::oidindx_type, 5 >  ISO_9506_MMS_1_OID_ARR = { 2  ,  2  ,  9506  ,  2  ,  1 };
const boost::asn1::oid_type ISO_9506_MMS_1_OID = boost::asn1::oid_type(ISO_9506_MMS_1_OID_ARR);


namespace ISO_9506_MMS_1  {


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
	struct  MMSpdu;

 	//  type is  SEQUENCE
	struct  Confirmed_RequestPDU;

 	//  type is  CHOICE
	struct  ConfirmedServiceRequest;

 	//  type is  CHOICE
	struct  AdditionalService_Request;

 	//  type is  CHOICE
	struct  Request_Detail;

 	//  type is  SEQUENCE
	struct  Unconfirmed_PDU;

 	//  type is  CHOICE
	struct  UnconfirmedService;

 	//  type is  CHOICE
	struct  Unconfirmed_Detail;

 	//  type is  SEQUENCE
	struct  Confirmed_ResponsePDU;

 	//  type is  CHOICE
	struct  ConfirmedServiceResponse;

 	//  type is  CHOICE
	struct  AdditionalService_Response;

 	//  type is  CHOICE
	struct  Response_Detail;

 	//  type is  SEQUENCE
	struct  Confirmed_ErrorPDU;

 	//  type is  SEQUENCE
	struct  ServiceError;

 	//  type is  CHOICE
	struct  AdditionalService_Error;

 	//  type is  CHOICE
	struct  ObjectName;

 	//  type is  CHOICE
	struct  ObjectClass;

 	//  type is  SEQUENCE
	struct  Initiate_RequestPDU;

 	//  type is  SEQUENCE
	struct  Initiate_ResponsePDU;

 	//  type is  SEQUENCE
	struct  Cancel_ErrorPDU;

 	//  type is  SEQUENCE
	struct  RejectPDU;

 	//  type is  SEQUENCE
	struct  DefineAccessControlList_Request;

 	//  type is  CHOICE
	struct  GetAccessControlListAttributes_Request;

 	//  type is  SEQUENCE
	struct  GetAccessControlListAttributes_Response;

 	//  type is  SEQUENCE
	struct  ReportAccessControlledObjects_Request;

 	//  type is  SEQUENCE
	struct  ReportAccessControlledObjects_Response;

 	//  type is  SEQUENCE
	struct  ChangeAccessControl_Request;

 	//  type is  SEQUENCE
	struct  ChangeAccessControl_Response;

 	//  type is  SEQUENCE
	struct  StatusResponse;

 	//  type is  CHOICE
	struct  CS_Status_Response;

 	//  type is  SEQUENCE
	struct  GetNameList_Request;

 	//  type is  SEQUENCE
	struct  GetNameList_Response;

 	//  type is  SEQUENCE
	struct  Identify_Response;

 	//  type is  SEQUENCE
	struct  Rename_Request;

 	//  type is  SEQUENCE
	struct  GetCapabilityList_Request;

 	//  type is  SEQUENCE
	struct  GetCapabilityList_Response;

 	//  type is  SEQUENCE
	struct  InitiateDownloadSequence_Request;

 	//  type is  SEQUENCE
	struct  DownloadSegment_Response;

 	//  type is  CHOICE
	struct  LoadData;

 	//  type is  SEQUENCE
	struct  TerminateDownloadSequence_Request;

 	//  type is  SEQUENCE
	struct  InitiateUploadSequence_Response;

 	//  type is  SEQUENCE
	struct  UploadSegment_Response;

 	//  type is  SEQUENCE
	struct  RequestDomainDownload_Request;

 	//  type is  SEQUENCE
	struct  RequestDomainUpload_Request;

 	//  type is  SEQUENCE
	struct  LoadDomainContent_Request;

 	//  type is  SEQUENCE
	struct  StoreDomainContent_Request;

 	//  type is  SEQUENCE
	struct  GetDomainAttributes_Response;

 	//  type is  SEQUENCE
	struct  CreateProgramInvocation_Request;

 	//  type is  SEQUENCE
	struct  Start_Request;

 	//  type is  preextend CHOICE
	struct  CS_Start_Request__impl;

 	//  type is  CHOICE
	struct  StartCount;

 	//  type is  SEQUENCE
	struct  Stop_Request;

 	//  type is  SEQUENCE
	struct  Resume_Request;

 	//  type is  preextend CHOICE
	struct  CS_Resume_Request__impl;

 	//  type is  SEQUENCE
	struct  Reset_Request;

 	//  type is  SEQUENCE
	struct  Kill_Request;

 	//  type is  SEQUENCE
	struct  GetProgramInvocationAttributes_Response;

 	//  type is  SEQUENCE
	struct  CS_GetProgramInvocationAttributes_Response;

 	//  type is  SEQUENCE
	struct  Select_Request;

 	//  type is  SEQUENCE
	struct  AlterProgramInvocationAttributes_Request;

 	//  type is  SEQUENCE
	struct  ReconfigureProgramInvocation_Request;

 	//  type is  CHOICE
	struct  ControlElement;

 	//  type is  CHOICE
	struct  InitiateUnitControl_Error;

 	//  type is  SEQUENCE
	struct  UnitControlLoadSegment_Response;

 	//  type is  SEQUENCE
	struct  UnitControlUpload_Request;

 	//  type is  SEQUENCE
	struct  UnitControlUpload_Response;

 	//  type is  SEQUENCE
	struct  StartUnitControl_Request;

 	//  type is  SEQUENCE
	struct  StartUnitControl_Error;

 	//  type is  SEQUENCE
	struct  StopUnitControl_Error;

 	//  type is  SEQUENCE
	struct  CreateUnitControl_Request;

 	//  type is  SEQUENCE
	struct  AddToUnitControl_Request;

 	//  type is  SEQUENCE
	struct  RemoveFromUnitControl_Request;

 	//  type is  SEQUENCE
	struct  GetUnitControlAttributes_Response;

 	//  type is  SEQUENCE
	struct  LoadUnitControlFromFile_Request;

 	//  type is  CHOICE
	struct  LoadUnitControlFromFile_Error;

 	//  type is  SEQUENCE
	struct  StoreUnitControlToFile_Request;

 	//  type is  CHOICE
	struct  DeleteUnitControl_Error;

 	//  type is  CHOICE
	struct  TypeSpecification;

 	//  type is  CHOICE
	struct  AlternateAccessSelection;

 	//  type is  CHOICE
	struct  AccessResult;

 	//  type is  CHOICE
	struct  Data;

 	//  type is  CHOICE
	struct  VariableAccessSpecification;

 	//  type is  CHOICE
	struct  VariableSpecification;

 	//  type is  SEQUENCE
	struct  Read_Request;

 	//  type is  SEQUENCE
	struct  Read_Response;

 	//  type is  SEQUENCE
	struct  Write_Request;

 	//  type is  SEQUENCE
	struct  InformationReport;

 	//  type is  CHOICE
	struct  GetVariableAccessAttributes_Request;

 	//  type is  SEQUENCE
	struct  GetVariableAccessAttributes_Response;

 	//  type is  SEQUENCE
	struct  DefineNamedVariable_Request;

 	//  type is  SEQUENCE
	struct  DeleteVariableAccess_Request;

 	//  type is  SEQUENCE
	struct  DeleteVariableAccess_Response;

 	//  type is  SEQUENCE
	struct  DefineNamedVariableList_Request;

 	//  type is  SEQUENCE
	struct  GetNamedVariableListAttributes_Response;

 	//  type is  SEQUENCE
	struct  DeleteNamedVariableList_Request;

 	//  type is  SEQUENCE
	struct  DeleteNamedVariableList_Response;

 	//  type is  SEQUENCE
	struct  DefineNamedType_Request;

 	//  type is  SEQUENCE
	struct  GetNamedTypeAttributes_Response;

 	//  type is  SEQUENCE
	struct  DeleteNamedType_Request;

 	//  type is  SEQUENCE
	struct  DeleteNamedType_Response;

 	//  type is  SEQUENCE
	struct  ExchangeData_Request;

 	//  type is  SEQUENCE
	struct  ExchangeData_Response;

 	//  type is  SEQUENCE
	struct  GetDataExchangeAttributes_Response;

 	//  type is  SEQUENCE
	struct  TakeControl_Request;

 	//  type is  CHOICE
	struct  TakeControl_Response;

 	//  type is  SEQUENCE
	struct  RelinquishControl_Request;

 	//  type is  SEQUENCE
	struct  DefineSemaphore_Request;

 	//  type is  SEQUENCE
	struct  ReportSemaphoreStatus_Response;

 	//  type is  SEQUENCE
	struct  ReportPoolSemaphoreStatus_Request;

 	//  type is  SEQUENCE
	struct  ReportPoolSemaphoreStatus_Response;

 	//  type is  SEQUENCE
	struct  ReportSemaphoreEntryStatus_Request;

 	//  type is  SEQUENCE
	struct  ReportSemaphoreEntryStatus_Response;

 	//  type is  SEQUENCE
	struct  SemaphoreEntry;

 	//  type is  SEQUENCE
	struct  AttachToSemaphore;

 	//  type is  SEQUENCE
	struct  Input_Request;

 	//  type is  SEQUENCE
	struct  Output_Request;

 	//  type is  SEQUENCE
	struct  TriggerEvent_Request;

 	//  type is  SEQUENCE
	struct  EventNotification;

 	//  type is  preextend CHOICE
	struct  CS_EventNotification__impl;

 	//  type is  SEQUENCE
	struct  AcknowledgeEventNotification_Request;

 	//  type is  SEQUENCE
	struct  GetAlarmSummary_Request;

 	//  type is  SEQUENCE
	struct  GetAlarmSummary_Response;

 	//  type is  SEQUENCE
	struct  AlarmSummary;

 	//  type is  preextend CHOICE
	struct  EN_Additional_Detail__impl;

 	//  type is  SEQUENCE
	struct  GetAlarmEnrollmentSummary_Request;

 	//  type is  SEQUENCE
	struct  GetAlarmEnrollmentSummary_Response;

 	//  type is  SEQUENCE
	struct  AlarmEnrollmentSummary;

 	//  type is  SEQUENCE
	struct  AttachToEventCondition;

 	//  type is  SEQUENCE
	struct  DefineEventCondition_Request;

 	//  type is  preextend CHOICE
	struct  CS_DefineEventCondition_Request__impl;

 	//  type is  CHOICE
	struct  DeleteEventCondition_Request;

 	//  type is  SEQUENCE
	struct  GetEventConditionAttributes_Response;

 	//  type is  SEQUENCE
	struct  CS_GetEventConditionAttributes_Response;

 	//  type is  SEQUENCE
	struct  ReportEventConditionStatus_Response;

 	//  type is  SEQUENCE
	struct  AlterEventConditionMonitoring_Request;

 	//  type is  SEQUENCE
	struct  CS_AlterEventConditionMonitoring_Request;

 	//  type is  SEQUENCE
	struct  DefineEventAction_Request;

 	//  type is  CHOICE
	struct  DeleteEventAction_Request;

 	//  type is  SEQUENCE
	struct  GetEventActionAttributes_Response;

 	//  type is  SEQUENCE
	struct  DefineEventEnrollment_Request;

 	//  type is  preextend CHOICE
	struct  CS_DefineEventEnrollment_Request__impl;

 	//  type is  CHOICE
	struct  DeleteEventEnrollment_Request;

 	//  type is  SEQUENCE
	struct  GetEventEnrollmentAttributes_Request;

 	//  type is  SEQUENCE
	struct  GetEventEnrollmentAttributes_Response;

 	//  type is  SEQUENCE
	struct  EEAttributes;

 	//  type is  SEQUENCE
	struct  ReportEventEnrollmentStatus_Response;

 	//  type is  SEQUENCE
	struct  AlterEventEnrollment_Request;

 	//  type is  SEQUENCE
	struct  AlterEventEnrollment_Response;

 	//  type is  SEQUENCE
	struct  CS_AlterEventEnrollment_Request;

 	//  type is  SEQUENCE
	struct  DefineEventConditionList_Request;

 	//  type is  SEQUENCE
	struct  AddEventConditionListReference_Request;

 	//  type is  SEQUENCE
	struct  RemoveEventConditionListReference_Request;

 	//  type is  CHOICE
	struct  RemoveEventConditionListReference_Error;

 	//  type is  SEQUENCE
	struct  GetEventConditionListAttributes_Response;

 	//  type is  SEQUENCE
	struct  ReportEventConditionListStatus_Request;

 	//  type is  SEQUENCE
	struct  ReportEventConditionListStatus_Response;

 	//  type is  SEQUENCE
	struct  EventConditionStatus;

 	//  type is  SEQUENCE
	struct  AlterEventConditionListMonitoring_Request;

 	//  type is  SEQUENCE
	struct  ReadJournal_Request;

 	//  type is  SEQUENCE
	struct  ReadJournal_Response;

 	//  type is  SEQUENCE
	struct  JournalEntry;

 	//  type is  SEQUENCE
	struct  WriteJournal_Request;

 	//  type is  SEQUENCE
	struct  InitializeJournal_Request;

 	//  type is  SEQUENCE
	struct  ReportJournalStatus_Response;

 	//  type is  SEQUENCE
	struct  CreateJournal_Request;

 	//  type is  SEQUENCE
	struct  DeleteJournal_Request;

 	//  type is  SEQUENCE
	struct  EntryContent;

 	//  type is  OCTET STRING
	typedef  octetstring_type   TimeOfDay;

 	//  type is  UTF8String
	typedef  visiblestring_type   Identifier;

 	//  type is  INTEGER
	typedef  boost::int8_t   Integer8;

 	//  type is  INTEGER
	typedef  boost::int16_t   Integer16;

 	//  type is  INTEGER
	typedef  boost::int32_t   Integer32;

 	//  type is  INTEGER
	typedef  boost::uint8_t   Unsigned8;

 	//  type is  INTEGER
	typedef  boost::uint16_t   Unsigned16;

 	//  type is  INTEGER
	typedef  boost::uint32_t   Unsigned32;

 	//  type is  UTF8String
	typedef  visiblestring_type   MMSString;

 	//  type is  UTF8String
	typedef  visiblestring_type   MMS255String;

 	//  type is  NULL
	typedef  null_type   Conclude_RequestPDU;

 	//  type is  NULL
	typedef  null_type   Conclude_ResponsePDU;

 	//  type is  NULL
	typedef  null_type   DefineAccessControlList_Response;

 	//  type is  NULL
	typedef  null_type   DeleteAccessControlList_Response;

 	//  type is  INTEGER
	typedef  int   OperationState;

 	//  type is  BIT STRING
	typedef  bitstring_type   ExtendedStatus;

 	//  type is  BOOLEAN
	typedef  bool   Status_Request;

 	//  type is  NULL
	typedef  null_type   Identify_Request;

 	//  type is  NULL
	typedef  null_type   Rename_Response;

 	//  type is  NULL
	typedef  null_type   VMDStop_Request;

 	//  type is  NULL
	typedef  null_type   VMDStop_Response;

 	//  type is  BOOLEAN
	typedef  bool   VMDReset_Request;

 	//  type is  NULL
	typedef  null_type   InitiateDownloadSequence_Response;

 	//  type is  NULL
	typedef  null_type   TerminateDownloadSequence_Response;

 	//  type is  NULL
	typedef  null_type   TerminateUploadSequence_Response;

 	//  type is  NULL
	typedef  null_type   RequestDomainDownload_Response;

 	//  type is  NULL
	typedef  null_type   RequestDomainUpload_Response;

 	//  type is  NULL
	typedef  null_type   LoadDomainContent_Response;

 	//  type is  NULL
	typedef  null_type   StoreDomainContent_Response;

 	//  type is  NULL
	typedef  null_type   DeleteDomain_Response;

 	//  type is  NULL
	typedef  null_type   CreateProgramInvocation_Response;

 	//  type is  INTEGER
	typedef  int   CS_CreateProgramInvocation_Request;

 	//  type is  NULL
	typedef  null_type   DeleteProgramInvocation_Response;

 	//  type is  NULL
	typedef  null_type   Start_Response;

 	//  type is extended  CHOICE
	BOOST_ASN_EXPLICIT_TYPEDEF(CS_Start_Request , CS_Start_Request__impl , 0  ,CONTEXT_CLASS)
 
 
 	//  type is  NULL
	typedef  null_type   Stop_Response;

 	//  type is  NULL
	typedef  null_type   Resume_Response;

 	//  type is extended  CHOICE
	BOOST_ASN_EXPLICIT_TYPEDEF(CS_Resume_Request , CS_Resume_Request__impl , 0  ,CONTEXT_CLASS)
 
 
 	//  type is  NULL
	typedef  null_type   Reset_Response;

 	//  type is  NULL
	typedef  null_type   Kill_Response;

 	//  type is  NULL
	typedef  null_type   Select_Response;

 	//  type is  NULL
	typedef  null_type   AlterProgramInvocationAttributes_Response;

 	//  type is  NULL
	typedef  null_type   ReconfigureProgramInvocation_Response;

 	//  type is  NULL
	typedef  null_type   InitiateUnitControlLoad_Response;

 	//  type is  NULL
	typedef  null_type   StartUnitControl_Response;

 	//  type is  NULL
	typedef  null_type   StopUnitControl_Response;

 	//  type is  NULL
	typedef  null_type   CreateUnitControl_Response;

 	//  type is  NULL
	typedef  null_type   AddToUnitControl_Response;

 	//  type is  NULL
	typedef  null_type   RemoveFromUnitControl_Response;

 	//  type is  NULL
	typedef  null_type   LoadUnitControlFromFile_Response;

 	//  type is  NULL
	typedef  null_type   StoreUnitControlToFile_Response;

 	//  type is  NULL
	typedef  null_type   DeleteUnitControl_Response;

 	//  type is  OCTET STRING
	typedef  octetstring_type   FloatingPoint;

 	//  type is  INTEGER
	typedef  int   DataAccessError;

 	//  type is  NULL
	typedef  null_type   DefineNamedVariable_Response;

 	//  type is  NULL
	typedef  null_type   DefineNamedVariableList_Response;

 	//  type is  NULL
	typedef  null_type   DefineNamedType_Response;

 	//  type is  NULL
	typedef  null_type   RelinquishControl_Response;

 	//  type is  NULL
	typedef  null_type   DefineSemaphore_Response;

 	//  type is  NULL
	typedef  null_type   DeleteSemaphore_Response;

 	//  type is  NULL
	typedef  null_type   Output_Response;

 	//  type is  NULL
	typedef  null_type   TriggerEvent_Response;

 	//  type is extended  CHOICE
	BOOST_ASN_EXPLICIT_TYPEDEF(CS_EventNotification , CS_EventNotification__impl , 0  ,CONTEXT_CLASS)
 
 
 	//  type is  NULL
	typedef  null_type   AcknowledgeEventNotification_Response;

 	//  type is extended  CHOICE
	BOOST_ASN_EXPLICIT_TYPEDEF(EN_Additional_Detail , EN_Additional_Detail__impl , 0  ,CONTEXT_CLASS)
 
 
 	//  type is  NULL
	typedef  null_type   DefineEventCondition_Response;

 	//  type is extended  CHOICE
	BOOST_ASN_EXPLICIT_TYPEDEF(CS_DefineEventCondition_Request , CS_DefineEventCondition_Request__impl , 0  ,CONTEXT_CLASS)
 
 
 	//  type is  NULL
	typedef  null_type   AlterEventConditionMonitoring_Response;

 	//  type is  NULL
	typedef  null_type   DefineEventAction_Response;

 	//  type is  NULL
	typedef  null_type   DefineEventEnrollment_Response;

 	//  type is extended  CHOICE
	BOOST_ASN_EXPLICIT_TYPEDEF(CS_DefineEventEnrollment_Request , CS_DefineEventEnrollment_Request__impl , 0  ,CONTEXT_CLASS)
 
 
 	//  type is  INTEGER
	typedef  int   EE_State;

 	//  type is  NULL
	typedef  null_type   DefineEventConditionList_Response;

 	//  type is  NULL
	typedef  null_type   DeleteEventConditionList_Response;

 	//  type is  NULL
	typedef  null_type   AddEventConditionListReference_Response;

 	//  type is  NULL
	typedef  null_type   RemoveEventConditionListReference_Response;

 	//  type is  NULL
	typedef  null_type   AlterEventConditionListMonitoring_Response;

 	//  type is  NULL
	typedef  null_type   WriteJournal_Response;

 	//  type is  NULL
	typedef  null_type   CreateJournal_Response;

 	//  type is  NULL
	typedef  null_type   DeleteJournal_Response;

 	//   SEQUENCE_OF is FileName 
	typedef std::vector<graphicstring_type >   FileName;

	//   SEQUENCE_OF is AlternateAccess 
	struct AlternateAccess_sequence_of;
	typedef std::vector<AlternateAccess_sequence_of >   AlternateAccess;

	//   SEQUENCE_OF is Write-Response 
	struct Write_Response_sequence_of;
	typedef std::vector<Write_Response_sequence_of >   Write_Response;

}
#include "MMS-Environment-1.h"
#include "MMS-Environment-1.h"
#include "ISO-9506-MMS-1A.h"
#include "MMS-Object-Module-1.h"
 


namespace ISO_9506_MMS_1  {

 
	//import type
	using MMS_Environment_1::ApplicationReference;
	using MMS_Environment_1::Authentication_value;
	using ISO_9506_MMS_1A::ObtainFile_Request;
	using ISO_9506_MMS_1A::ObtainFile_Response;
	using ISO_9506_MMS_1A::ObtainFile_Error;
	using ISO_9506_MMS_1A::FileOpen_Request;
	using ISO_9506_MMS_1A::FileOpen_Response;
	using ISO_9506_MMS_1A::FileRead_Request;
	using ISO_9506_MMS_1A::FileRead_Response;
	using ISO_9506_MMS_1A::FileClose_Request;
	using ISO_9506_MMS_1A::FileClose_Response;
	using ISO_9506_MMS_1A::FileRename_Request;
	using ISO_9506_MMS_1A::FileRename_Response;
	using ISO_9506_MMS_1A::FileRename_Error;
	using ISO_9506_MMS_1A::FileDelete_Request;
	using ISO_9506_MMS_1A::FileDelete_Response;
	using ISO_9506_MMS_1A::FileDirectory_Request;
	using ISO_9506_MMS_1A::FileDirectory_Response;
	using ISO_9506_MMS_1A::DefineScatteredAccess_Request;
	using ISO_9506_MMS_1A::DefineScatteredAccess_Response;
	using ISO_9506_MMS_1A::ScatteredAccessDescription;
	using ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request;
	using ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response;
	using MMS_Object_Module_1::AccessCondition;
	using MMS_Object_Module_1::AdditionalCBBOptions;
	using MMS_Object_Module_1::AdditionalSupportOptions;
	using MMS_Object_Module_1::Address;
	using MMS_Object_Module_1::AlarmAckRule;
	using MMS_Object_Module_1::Control_State;
	using MMS_Object_Module_1::DomainState;
	using MMS_Object_Module_1::EC_State;
	using MMS_Object_Module_1::EC_Class;
	using MMS_Object_Module_1::EE_Duration;
	using MMS_Object_Module_1::EE_Class;
	using MMS_Object_Module_1::EventTime;
	using MMS_Object_Module_1::Journal_Variable;
	using MMS_Object_Module_1::LogicalStatus;
	using MMS_Object_Module_1::Modifier;
	//using MMS_Object_Module_1::normalPriority;
	//using MMS_Object_Module_1::normalSeverity;
	using MMS_Object_Module_1::ParameterSupportOptions;
	using MMS_Object_Module_1::PhysicalStatus;
	using MMS_Object_Module_1::Priority;
	using MMS_Object_Module_1::ProgramInvocationState;
	using MMS_Object_Module_1::Running_Mode;
	using MMS_Object_Module_1::ServiceSupportOptions;
	using MMS_Object_Module_1::Severity;
	using MMS_Object_Module_1::Transitions;
	using MMS_Object_Module_1::TypeDescription;
	using MMS_Object_Module_1::ULState;
	using MMS_Object_Module_1::VMDState;
 
	//   SEQUENCE_OF is FileName 
	typedef std::vector<graphicstring_type >   FileName;

	//   SEQUENCE_OF is AlternateAccess 
	//start==============================================================
	//It is  INTERNAL CHOICE

			enum AlternateAccess_sequence_of_enum {
			AlternateAccess_sequence_of_null = 0  , 
			AlternateAccess_sequence_of_unnamed , 
			AlternateAccess_sequence_of_named , 
		};

	struct  AlternateAccess_sequence_of : public BOOST_ASN_CHOICE_STRUCT(AlternateAccess_sequence_of_enum) {


		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  named_type{

				boost::asn1::value_holder<Identifier >  componentName;
				boost::asn1::value_holder<AlternateAccessSelection >  access;

				named_type()  : componentName() , access()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(componentName ,0);
					BOOST_ASN_CHOICE(access);
				}
			};

		//end==============================================================

			AlternateAccess_sequence_of() : BOOST_ASN_CHOICE_STRUCT(AlternateAccess_sequence_of_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(unnamed, AlternateAccessSelection,  AlternateAccess_sequence_of_unnamed)
			BOOST_ASN_VALUE_CHOICE(named, named_type,  AlternateAccess_sequence_of_named)

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
								case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<named_type > (true , AlternateAccess_sequence_of_named) ,5)) return; else free(); break;}
							default:{}}
							;}
						default:{
								 if(BOOST_ASN_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free();
						;}}}
				else {
					 switch(type()){
						case AlternateAccess_sequence_of_unnamed: {BOOST_ASN_CHOICE(value<AlternateAccessSelection > (false , AlternateAccess_sequence_of_unnamed)); break;}
						case AlternateAccess_sequence_of_named: {BOOST_ASN_IMPLICIT_TAG(value<named_type > (false , AlternateAccess_sequence_of_named) ,5); break;}
						default:{}}}
			}
		};

	typedef std::vector<AlternateAccess_sequence_of >   AlternateAccess;

	//   SEQUENCE_OF is Write-Response 
	//start==============================================================
	//It is  INTERNAL CHOICE

			enum Write_Response_sequence_of_enum {
			Write_Response_sequence_of_null = 0  , 
			Write_Response_sequence_of_failure , 
			Write_Response_sequence_of_success , 
		};

	struct  Write_Response_sequence_of : public BOOST_ASN_CHOICE_STRUCT(Write_Response_sequence_of_enum) {



			Write_Response_sequence_of() : BOOST_ASN_CHOICE_STRUCT(Write_Response_sequence_of_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(failure, DataAccessError,  Write_Response_sequence_of_failure)
			BOOST_ASN_VALUE_CHOICE(success, null_type,  Write_Response_sequence_of_success)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (true , Write_Response_sequence_of_failure) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , Write_Response_sequence_of_success) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case Write_Response_sequence_of_failure: {BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (false , Write_Response_sequence_of_failure) ,0); break;}
						case Write_Response_sequence_of_success: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , Write_Response_sequence_of_success) ,1); break;}
						default:{}}}
			}
		};

	typedef std::vector<Write_Response_sequence_of >   Write_Response;

	//  ref is  ServiceError
	typedef ServiceError Initiate_ErrorPDU;

 	//  ref is  ServiceError
	typedef ServiceError Conclude_ErrorPDU;

 	//  ref is  Unsigned32
	typedef Unsigned32 Cancel_RequestPDU;

 	//  ref is  Unsigned32
	typedef Unsigned32 Cancel_ResponsePDU;

 	//  ref is  Identifier
	typedef Identifier DeleteAccessControlList_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 ChangeAccessControl_Error;

 	//  ref is  StatusResponse
	typedef StatusResponse Status_Response;

 	//  ref is  StatusResponse
	typedef StatusResponse UnsolicitedStatus;

 	//  ref is  StatusResponse
	typedef StatusResponse VMDReset_Response;

 	//  ref is  Identifier
	typedef Identifier DownloadSegment_Request;

 	//  ref is  Identifier
	typedef Identifier InitiateUploadSequence_Request;

 	//  ref is  Integer32
	typedef Integer32 UploadSegment_Request;

 	//  ref is  Integer32
	typedef Integer32 TerminateUploadSequence_Request;

 	//  ref is  Identifier
	typedef Identifier DeleteDomain_Request;

 	//  ref is  Identifier
	typedef Identifier GetDomainAttributes_Request;

 	//  ref is  Identifier
	typedef Identifier DeleteProgramInvocation_Request;

 	//  ref is  ProgramInvocationState
	typedef ProgramInvocationState Start_Error;

 	//  ref is  ProgramInvocationState
	typedef ProgramInvocationState Stop_Error;

 	//  ref is  ProgramInvocationState
	typedef ProgramInvocationState Resume_Error;

 	//  ref is  ProgramInvocationState
	typedef ProgramInvocationState Reset_Error;

 	//  ref is  Identifier
	typedef Identifier GetProgramInvocationAttributes_Request;

 	//  ref is  Identifier
	typedef Identifier InitiateUnitControlLoad_Request;

 	//  ref is  Identifier
	typedef Identifier UnitControlLoadSegment_Request;

 	//  ref is  Identifier
	typedef Identifier StopUnitControl_Request;

 	//  ref is  Identifier
	typedef Identifier GetUnitControlAttributes_Request;

 	//  ref is  Identifier
	typedef Identifier DeleteUnitControl_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 DeleteVariableAccess_Error;

 	//  ref is  ObjectName
	typedef ObjectName GetNamedVariableListAttributes_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 DeleteNamedVariableList_Error;

 	//  ref is  ObjectName
	typedef ObjectName GetNamedTypeAttributes_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 DeleteNamedType_Error;

 	//  ref is  ObjectName
	typedef ObjectName GetDataExchangeAttributes_Request;

 	//  ref is  ObjectName
	typedef ObjectName DeleteSemaphore_Request;

 	//  ref is  ObjectName
	typedef ObjectName ReportSemaphoreStatus_Request;

 	//  ref is  MMSString
	typedef MMSString Input_Response;

 	//  ref is  Unsigned32
	typedef Unsigned32 DeleteEventCondition_Response;

 	//  ref is  ObjectName
	typedef ObjectName GetEventConditionAttributes_Request;

 	//  ref is  ObjectName
	typedef ObjectName ReportEventConditionStatus_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 DeleteEventAction_Response;

 	//  ref is  ObjectName
	typedef ObjectName GetEventActionAttributes_Request;

 	//  ref is  ObjectName
	typedef ObjectName ReportEventActionStatus_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 ReportEventActionStatus_Response;

 	//  ref is  ObjectName
	typedef ObjectName DefineEventEnrollment_Error;

 	//  ref is  Unsigned32
	typedef Unsigned32 DeleteEventEnrollment_Response;

 	//  ref is  ObjectName
	typedef ObjectName ReportEventEnrollmentStatus_Request;

 	//  ref is  ObjectName
	typedef ObjectName DefineEventConditionList_Error;

 	//  ref is  ObjectName
	typedef ObjectName DeleteEventConditionList_Request;

 	//  ref is  ObjectName
	typedef ObjectName AddEventConditionListReference_Error;

 	//  ref is  ObjectName
	typedef ObjectName GetEventConditionListAttributes_Request;

 	//  ref is  Unsigned32
	typedef Unsigned32 InitializeJournal_Response;

 	//  ref is  ObjectName
	typedef ObjectName ReportJournalStatus_Request;

 //start==============================================================
//It is   SEQUENCE  

	struct  EntryContent{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum entryForm_type_enum {
			entryForm_type_null = 0  , 
			entryForm_type_data , 
			entryForm_type_annotation , 
		};

	struct  entryForm_type : public BOOST_ASN_CHOICE_STRUCT(entryForm_type_enum) {


		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  data_type{

			//start==============================================================
			//It is  INTERNAL SEQUENCE  

				struct  event_type{

					boost::asn1::value_holder<ObjectName >  eventConditionName;
					boost::asn1::value_holder<EC_State >  currentState;

					event_type()  : eventConditionName() , currentState()  {}

					 template<typename Archive> void serialize(Archive& arch){

						BOOST_ASN_CHOICE_TAG(eventConditionName ,0);
						BOOST_ASN_IMPLICIT_TAG(currentState ,1);
					}
				};

			//end==============================================================
				//   SEQUENCE_OF is listOfVariables 
				typedef std::vector<Journal_Variable >   listOfVariables_type;


				boost::shared_ptr<event_type > event;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(event_type ,  event)

 				boost::shared_ptr<listOfVariables_type > listOfVariables;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(listOfVariables_type ,  listOfVariables)

 
				data_type()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(event ,0);
					BOOST_ASN_IMPLICIT_TAG(listOfVariables ,1);
				}
			};

		//end==============================================================

			entryForm_type() : BOOST_ASN_CHOICE_STRUCT(entryForm_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(data, data_type,  entryForm_type_data)
			BOOST_ASN_VALUE_CHOICE(annotation, MMSString,  entryForm_type_annotation)

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
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<data_type > (true , entryForm_type_data) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_EXPLICIT_TAG(value<MMSString > (true , entryForm_type_annotation) ,3)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case entryForm_type_data: {BOOST_ASN_IMPLICIT_TAG(value<data_type > (false , entryForm_type_data) ,2); break;}
						case entryForm_type_annotation: {BOOST_ASN_EXPLICIT_TAG(value<MMSString > (false , entryForm_type_annotation) ,3); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<TimeOfDay >  occurrenceTime;
		boost::asn1::value_holder<entryForm_type >  entryForm;

		EntryContent()  : occurrenceTime() , entryForm()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(occurrenceTime ,0);
			BOOST_ASN_CHOICE(entryForm);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteJournal_Request{

		boost::asn1::value_holder<ObjectName >  journalName;

		DeleteJournal_Request()  : journalName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(journalName ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  CreateJournal_Request{

		boost::asn1::value_holder<ObjectName >  journalName;

		CreateJournal_Request()  : journalName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(journalName ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportJournalStatus_Response{


		boost::asn1::value_holder<Unsigned32 >  currentEntries;
		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		ReportJournalStatus_Response()  : currentEntries() , mmsDeletable()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(currentEntries ,0);
			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,1);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  InitializeJournal_Request{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  limitSpecification_type{


			boost::asn1::value_holder<TimeOfDay >  limitingTime;
			boost::shared_ptr<octetstring_type > limitingEntry;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(octetstring_type ,  limitingEntry)

 
			limitSpecification_type()  : limitingTime()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(limitingTime ,0);
				BOOST_ASN_IMPLICIT_TAG(limitingEntry ,1);
			}
		};

	//end==============================================================

		boost::asn1::value_holder<ObjectName >  journalName;
		boost::shared_ptr<limitSpecification_type > limitSpecification;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(limitSpecification_type ,  limitSpecification)

 
		InitializeJournal_Request()  : journalName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(journalName ,0);
			BOOST_ASN_IMPLICIT_TAG(limitSpecification ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  WriteJournal_Request{
		//   SEQUENCE_OF is listOfJournalEntry 
		typedef std::vector<EntryContent >   listOfJournalEntry_type;


		boost::asn1::value_holder<ObjectName >  journalName;
		boost::asn1::value_holder<listOfJournalEntry_type >  listOfJournalEntry;

		WriteJournal_Request()  : journalName() , listOfJournalEntry()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(journalName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfJournalEntry ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  JournalEntry{


		boost::asn1::value_holder<octetstring_type >  entryIdentifier;
		boost::asn1::value_holder<ApplicationReference >  originatingApplication;
		boost::asn1::value_holder<EntryContent >  entryContent;

		JournalEntry()  : entryIdentifier() , originatingApplication() , entryContent()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(entryIdentifier ,0);
			BOOST_ASN_EXPLICIT_TAG(originatingApplication ,1);
			BOOST_ASN_IMPLICIT_TAG(entryContent ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReadJournal_Response{
		//   SEQUENCE_OF is listOfJournalEntry 
		typedef std::vector<JournalEntry >   listOfJournalEntry_type;



		boost::asn1::value_holder<listOfJournalEntry_type >  listOfJournalEntry;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		ReadJournal_Response()  : listOfJournalEntry()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfJournalEntry ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReadJournal_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum rangeStartSpecification_type_enum {
			rangeStartSpecification_type_null = 0  , 
			rangeStartSpecification_type_startingTime , 
			rangeStartSpecification_type_startingEntry , 
		};

	struct  rangeStartSpecification_type : public BOOST_ASN_CHOICE_STRUCT(rangeStartSpecification_type_enum) {



			rangeStartSpecification_type() : BOOST_ASN_CHOICE_STRUCT(rangeStartSpecification_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(startingTime, TimeOfDay,  rangeStartSpecification_type_startingTime)
			BOOST_ASN_VALUE_CHOICE(startingEntry, octetstring_type,  rangeStartSpecification_type_startingEntry)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , rangeStartSpecification_type_startingTime) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , rangeStartSpecification_type_startingEntry) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case rangeStartSpecification_type_startingTime: {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , rangeStartSpecification_type_startingTime) ,0); break;}
						case rangeStartSpecification_type_startingEntry: {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , rangeStartSpecification_type_startingEntry) ,1); break;}
						default:{}}}
			}
		};


	//start==============================================================
	//It is  INTERNAL CHOICE

			enum rangeStopSpecification_type_enum {
			rangeStopSpecification_type_null = 0  , 
			rangeStopSpecification_type_endingTime , 
			rangeStopSpecification_type_numberOfEntries , 
		};

	struct  rangeStopSpecification_type : public BOOST_ASN_CHOICE_STRUCT(rangeStopSpecification_type_enum) {


			rangeStopSpecification_type() : BOOST_ASN_CHOICE_STRUCT(rangeStopSpecification_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(endingTime, TimeOfDay,  rangeStopSpecification_type_endingTime)
			BOOST_ASN_VALUE_CHOICE(numberOfEntries, Integer32,  rangeStopSpecification_type_numberOfEntries)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , rangeStopSpecification_type_endingTime) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (true , rangeStopSpecification_type_numberOfEntries) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case rangeStopSpecification_type_endingTime: {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , rangeStopSpecification_type_endingTime) ,0); break;}
						case rangeStopSpecification_type_numberOfEntries: {BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (false , rangeStopSpecification_type_numberOfEntries) ,1); break;}
						default:{}}}
			}
		};

		//   SEQUENCE_OF is listOfVariables 
		typedef std::vector<visiblestring_type >   listOfVariables_type;


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  entryToStartAfter_type{


			boost::asn1::value_holder<TimeOfDay >  timeSpecification;
			boost::asn1::value_holder<octetstring_type >  entrySpecification;

			entryToStartAfter_type()  : timeSpecification() , entrySpecification()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(timeSpecification ,0);
				BOOST_ASN_IMPLICIT_TAG(entrySpecification ,1);
			}
		};

	//end==============================================================

		boost::asn1::value_holder<ObjectName >  journalName;
		boost::asn1::value_holder<rangeStartSpecification_type >  rangeStartSpecification;
		boost::asn1::value_holder<rangeStopSpecification_type >  rangeStopSpecification;
		boost::shared_ptr<listOfVariables_type > listOfVariables;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfVariables_type ,  listOfVariables)

 		boost::shared_ptr<entryToStartAfter_type > entryToStartAfter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(entryToStartAfter_type ,  entryToStartAfter)

 
		ReadJournal_Request()  : journalName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(journalName ,0);
			BOOST_ASN_CHOICE_TAG(rangeStartSpecification ,1);
			BOOST_ASN_CHOICE_TAG(rangeStopSpecification ,2);
			BOOST_ASN_IMPLICIT_TAG(listOfVariables ,4);
			BOOST_ASN_IMPLICIT_TAG(entryToStartAfter ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AlterEventConditionListMonitoring_Request{


	//start==============================================================
	//It is  INTERNAL CHOICE

			enum priorityChange_type_enum {
			priorityChange_type_null = 0  , 
			priorityChange_type_priorityValue , 
			priorityChange_type_priorityReset , 
		};

	struct  priorityChange_type : public BOOST_ASN_CHOICE_STRUCT(priorityChange_type_enum) {




			priorityChange_type() : BOOST_ASN_CHOICE_STRUCT(priorityChange_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(priorityValue, int,  priorityChange_type_priorityValue)
			BOOST_ASN_VALUE_CHOICE(priorityReset, null_type,  priorityChange_type_priorityReset)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , priorityChange_type_priorityValue) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , priorityChange_type_priorityReset) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case priorityChange_type_priorityValue: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , priorityChange_type_priorityValue) ,0); break;}
						case priorityChange_type_priorityReset: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , priorityChange_type_priorityReset) ,1); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  eventConditionListName;
		boost::asn1::value_holder<bool >  enabled;
		boost::asn1::value_holder<priorityChange_type >  priorityChange;

		AlterEventConditionListMonitoring_Request()  : eventConditionListName() , enabled()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionListName ,0);
			BOOST_ASN_IMPLICIT_TAG(enabled ,1);
			BOOST_ASN_CHOICE_TAG(priorityChange ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  EventConditionStatus{


		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<EC_State >  currentState;
		boost::asn1::value_holder<Unsigned32 >  numberOfEventEnrollments;
		boost::shared_ptr<bool > enabled;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  enabled)

 		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToActive;
		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToIdle;

		EventConditionStatus()  : eventConditionName() , currentState() , numberOfEventEnrollments() , timeOfLastTransitionToActive() , timeOfLastTransitionToIdle()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionName ,0);
			BOOST_ASN_IMPLICIT_TAG(currentState ,1);
			BOOST_ASN_IMPLICIT_TAG(numberOfEventEnrollments ,2);
			BOOST_ASN_IMPLICIT_TAG(enabled ,3);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive ,4);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportEventConditionListStatus_Response{
		//   SEQUENCE_OF is listOfEventConditionStatus 
		typedef std::vector<EventConditionStatus >   listOfEventConditionStatus_type;



		boost::asn1::value_holder<listOfEventConditionStatus_type >  listOfEventConditionStatus;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		ReportEventConditionListStatus_Response()  : listOfEventConditionStatus()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionStatus ,1);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportEventConditionListStatus_Request{

		boost::asn1::value_holder<ObjectName >  eventConditionListName;
		boost::shared_ptr<Identifier > continueAfter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  continueAfter)

 
		ReportEventConditionListStatus_Request()  : eventConditionListName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionListName ,0);
			BOOST_ASN_IMPLICIT_TAG(continueAfter ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetEventConditionListAttributes_Response{
		//   SEQUENCE_OF is listOfEventConditionName 
		typedef std::vector<ObjectName >   listOfEventConditionName_type;

		//   SEQUENCE_OF is listOfEventConditionListName 
		typedef std::vector<ObjectName >   listOfEventConditionListName_type;


		boost::asn1::value_holder<listOfEventConditionName_type >  listOfEventConditionName;
		boost::shared_ptr<listOfEventConditionListName_type > listOfEventConditionListName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfEventConditionListName_type ,  listOfEventConditionListName)

 
		GetEventConditionListAttributes_Response()  : listOfEventConditionName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum RemoveEventConditionListReference_Error_enum {
		RemoveEventConditionListReference_Error_null = 0  , 
		RemoveEventConditionListReference_Error_eventCondition , 
		RemoveEventConditionListReference_Error_eventConditionList , 
	};

	struct  RemoveEventConditionListReference_Error : public BOOST_ASN_CHOICE_STRUCT(RemoveEventConditionListReference_Error_enum) {


		RemoveEventConditionListReference_Error() : BOOST_ASN_CHOICE_STRUCT(RemoveEventConditionListReference_Error_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(eventCondition, ObjectName,  RemoveEventConditionListReference_Error_eventCondition)
		BOOST_ASN_VALUE_CHOICE(eventConditionList, ObjectName,  RemoveEventConditionListReference_Error_eventConditionList)

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
							case 0: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , RemoveEventConditionListReference_Error_eventCondition) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , RemoveEventConditionListReference_Error_eventConditionList) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case RemoveEventConditionListReference_Error_eventCondition: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , RemoveEventConditionListReference_Error_eventCondition) ,0); break;}
					case RemoveEventConditionListReference_Error_eventConditionList: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , RemoveEventConditionListReference_Error_eventConditionList) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  RemoveEventConditionListReference_Request{
		//   SEQUENCE_OF is listOfEventConditionName 
		typedef std::vector<ObjectName >   listOfEventConditionName_type;

		//   SEQUENCE_OF is listOfEventConditionListName 
		typedef std::vector<ObjectName >   listOfEventConditionListName_type;


		boost::asn1::value_holder<ObjectName >  eventConditionListName;
		boost::asn1::value_holder<listOfEventConditionName_type >  listOfEventConditionName;
		boost::asn1::value_holder<listOfEventConditionListName_type >  listOfEventConditionListName;

		RemoveEventConditionListReference_Request()  : eventConditionListName() , listOfEventConditionName() , listOfEventConditionListName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionListName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AddEventConditionListReference_Request{
		//   SEQUENCE_OF is listOfEventConditionName 
		typedef std::vector<ObjectName >   listOfEventConditionName_type;

		//   SEQUENCE_OF is listOfEventConditionListName 
		typedef std::vector<ObjectName >   listOfEventConditionListName_type;


		boost::asn1::value_holder<ObjectName >  eventConditionListName;
		boost::asn1::value_holder<listOfEventConditionName_type >  listOfEventConditionName;
		boost::shared_ptr<listOfEventConditionListName_type > listOfEventConditionListName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfEventConditionListName_type ,  listOfEventConditionListName)

 
		AddEventConditionListReference_Request()  : eventConditionListName() , listOfEventConditionName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionListName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DefineEventConditionList_Request{
		//   SEQUENCE_OF is listOfEventConditionName 
		typedef std::vector<ObjectName >   listOfEventConditionName_type;

		//   SEQUENCE_OF is listOfEventConditionListName 
		typedef std::vector<ObjectName >   listOfEventConditionListName_type;


		boost::asn1::value_holder<ObjectName >  eventConditionListName;
		boost::asn1::value_holder<listOfEventConditionName_type >  listOfEventConditionName;
		boost::shared_ptr<listOfEventConditionListName_type > listOfEventConditionListName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfEventConditionListName_type ,  listOfEventConditionListName)

 
		DefineEventConditionList_Request()  : eventConditionListName() , listOfEventConditionName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionListName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName ,2);
		}
	};

//end==============================================================

	const int EE_State_disabled = 0;
	const int EE_State_idle = 1;
	const int EE_State_active = 2;
	const int EE_State_activeNoAckA = 3;
	const int EE_State_idleNoAckI = 4;
	const int EE_State_idleNoAckA = 5;
	const int EE_State_idleAcked = 6;
	const int EE_State_activeAcked = 7;
	const int EE_State_undefined = 8;

//start==============================================================
//It is   SEQUENCE  

	struct  CS_AlterEventEnrollment_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum changeDisplay_type_enum {
			changeDisplay_type_null = 0  , 
			changeDisplay_type_string , 
			changeDisplay_type_index , 
			changeDisplay_type_noEnhancement , 
		};

	struct  changeDisplay_type : public BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) {





			changeDisplay_type() : BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  changeDisplay_type_string)
			BOOST_ASN_VALUE_CHOICE(index, int,  changeDisplay_type_index)
			BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  changeDisplay_type_noEnhancement)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , changeDisplay_type_string) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , changeDisplay_type_index) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_EXPLICIT_TAG(value<null_type > (true , changeDisplay_type_noEnhancement) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case changeDisplay_type_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , changeDisplay_type_string) ,0); break;}
						case changeDisplay_type_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , changeDisplay_type_index) ,1); break;}
						case changeDisplay_type_noEnhancement: {BOOST_ASN_EXPLICIT_TAG(value<null_type > (false , changeDisplay_type_noEnhancement) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<changeDisplay_type >  changeDisplay;

		CS_AlterEventEnrollment_Request()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(changeDisplay);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AlterEventEnrollment_Response{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum currentState_type_enum {
			currentState_type_null = 0  , 
			currentState_type_state , 
			currentState_type_undefined , 
		};

	struct  currentState_type : public BOOST_ASN_CHOICE_STRUCT(currentState_type_enum) {



			currentState_type() : BOOST_ASN_CHOICE_STRUCT(currentState_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(state, EE_State,  currentState_type_state)
			BOOST_ASN_VALUE_CHOICE(undefined, null_type,  currentState_type_undefined)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<EE_State > (true , currentState_type_state) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , currentState_type_undefined) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case currentState_type_state: {BOOST_ASN_IMPLICIT_TAG(value<EE_State > (false , currentState_type_state) ,0); break;}
						case currentState_type_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , currentState_type_undefined) ,1); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<currentState_type >  currentState;
		boost::asn1::value_holder<EventTime >  transitionTime;

		AlterEventEnrollment_Response()  : currentState() , transitionTime()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(currentState ,0);
			BOOST_ASN_CHOICE_TAG(transitionTime ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AlterEventEnrollment_Request{

		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::shared_ptr<Transitions > eventConditionTransitions;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Transitions ,  eventConditionTransitions)

 		boost::shared_ptr<AlarmAckRule > alarmAcknowledgmentRule;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AlarmAckRule ,  alarmAcknowledgmentRule)

 
		AlterEventEnrollment_Request()  : eventEnrollmentName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions ,1);
			BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportEventEnrollmentStatus_Response{


		boost::asn1::value_holder<Transitions >  eventConditionTransitions;
		boost::shared_ptr<bool > notificationLost;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  notificationLost)

 		boost::asn1::value_holder<EE_Duration >  duration;
		boost::shared_ptr<AlarmAckRule > alarmAcknowledgmentRule;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AlarmAckRule ,  alarmAcknowledgmentRule)

 		boost::asn1::value_holder<EE_State >  currentState;

		ReportEventEnrollmentStatus_Response()  : eventConditionTransitions() , duration() , currentState()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions ,0);
			BOOST_ASN_IMPLICIT_TAG(notificationLost ,1);
			BOOST_ASN_IMPLICIT_TAG(duration ,2);
			BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule ,3);
			BOOST_ASN_IMPLICIT_TAG(currentState ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  EEAttributes{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum eventConditionName_type_enum {
			eventConditionName_type_null = 0  , 
			eventConditionName_type_eventCondition , 
			eventConditionName_type_undefined , 
		};

	struct  eventConditionName_type : public BOOST_ASN_CHOICE_STRUCT(eventConditionName_type_enum) {



			eventConditionName_type() : BOOST_ASN_CHOICE_STRUCT(eventConditionName_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(eventCondition, ObjectName,  eventConditionName_type_eventCondition)
			BOOST_ASN_VALUE_CHOICE(undefined, null_type,  eventConditionName_type_undefined)

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
								case 0: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , eventConditionName_type_eventCondition) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , eventConditionName_type_undefined) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case eventConditionName_type_eventCondition: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , eventConditionName_type_eventCondition) ,0); break;}
						case eventConditionName_type_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , eventConditionName_type_undefined) ,1); break;}
						default:{}}}
			}
		};


	//start==============================================================
	//It is  INTERNAL CHOICE

			enum eventActionName_type_enum {
			eventActionName_type_null = 0  , 
			eventActionName_type_eventAction , 
			eventActionName_type_undefined , 
		};

	struct  eventActionName_type : public BOOST_ASN_CHOICE_STRUCT(eventActionName_type_enum) {



			eventActionName_type() : BOOST_ASN_CHOICE_STRUCT(eventActionName_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(eventAction, ObjectName,  eventActionName_type_eventAction)
			BOOST_ASN_VALUE_CHOICE(undefined, null_type,  eventActionName_type_undefined)

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
								case 0: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , eventActionName_type_eventAction) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , eventActionName_type_undefined) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case eventActionName_type_eventAction: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , eventActionName_type_eventAction) ,0); break;}
						case eventActionName_type_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , eventActionName_type_undefined) ,1); break;}
						default:{}}}
			}
		};



	//start==============================================================
	//It is  INTERNAL CHOICE

			enum displayEnhancement_type_enum {
			displayEnhancement_type_null = 0  , 
			displayEnhancement_type_string , 
			displayEnhancement_type_index , 
			displayEnhancement_type_noEnhancement , 
		};

	struct  displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {





			displayEnhancement_type() : BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  displayEnhancement_type_string)
			BOOST_ASN_VALUE_CHOICE(index, int,  displayEnhancement_type_index)
			BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  displayEnhancement_type_noEnhancement)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , displayEnhancement_type_string) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_index) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								 if(BOOST_ASN_BIND_TAG(value<null_type > (true , displayEnhancement_type_noEnhancement))) return; else free();
						;}}}
				else {
					 switch(type()){
						case displayEnhancement_type_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , displayEnhancement_type_string) ,0); break;}
						case displayEnhancement_type_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_index) ,1); break;}
						case displayEnhancement_type_noEnhancement: {BOOST_ASN_BIND_TAG(value<null_type > (false , displayEnhancement_type_noEnhancement)); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::asn1::value_holder<eventConditionName_type >  eventConditionName;
		boost::asn1::value_holder<eventActionName_type >  eventActionName;
		boost::shared_ptr<ApplicationReference > clientApplication;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  clientApplication)

 		boost::shared_ptr<bool > mmsDeletable;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  mmsDeletable)

 		boost::asn1::value_holder<EE_Class >  enrollmentClass;
		boost::shared_ptr<EE_Duration > duration;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(EE_Duration ,  duration)

 		boost::shared_ptr<Unsigned32 > invokeID;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  invokeID)

 		boost::shared_ptr<Unsigned32 > remainingAcceptableDelay;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  remainingAcceptableDelay)

 		boost::asn1::value_holder<displayEnhancement_type >  displayEnhancement;

		EEAttributes()  : eventEnrollmentName() , eventConditionName() , clientApplication() , enrollmentClass() , duration() , displayEnhancement()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_CHOICE_TAG(eventConditionName ,1);
			BOOST_ASN_CHOICE_TAG(eventActionName ,2);
			BOOST_ASN_EXPLICIT_TAG(clientApplication ,3);
			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,4);
			BOOST_ASN_IMPLICIT_TAG(enrollmentClass ,5);
			BOOST_ASN_IMPLICIT_TAG(duration ,6);
			BOOST_ASN_IMPLICIT_TAG(invokeID ,7);
			BOOST_ASN_IMPLICIT_TAG(remainingAcceptableDelay ,8);
			BOOST_ASN_CHOICE_TAG(displayEnhancement ,9);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetEventEnrollmentAttributes_Response{
		//   SEQUENCE_OF is listOfEEAttributes 
		typedef std::vector<EEAttributes >   listOfEEAttributes_type;



		boost::asn1::value_holder<listOfEEAttributes_type >  listOfEEAttributes;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		GetEventEnrollmentAttributes_Response()  : listOfEEAttributes()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfEEAttributes ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetEventEnrollmentAttributes_Request{


		static const int scopeOfRequest_specific = 0;
		static const int scopeOfRequest_client = 1;
		static const int scopeOfRequest_ec = 2;
		static const int scopeOfRequest_ea = 3;

		//   SEQUENCE_OF is eventEnrollmentNames 
		typedef std::vector<ObjectName >   eventEnrollmentNames_type;


		boost::shared_ptr<int > scopeOfRequest;   //  DEFAULT  int  1  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  scopeOfRequest)

 		boost::shared_ptr<eventEnrollmentNames_type > eventEnrollmentNames;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(eventEnrollmentNames_type ,  eventEnrollmentNames)

 		boost::shared_ptr<ApplicationReference > clientApplication;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  clientApplication)

 		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<ObjectName >  eventActionName;
		boost::asn1::value_holder<ObjectName >  continueAfter;

		GetEventEnrollmentAttributes_Request()  : clientApplication() , eventConditionName() , eventActionName() , continueAfter()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(scopeOfRequest ,0);
			BOOST_ASN_IMPLICIT_TAG(eventEnrollmentNames ,1);
			BOOST_ASN_EXPLICIT_TAG(clientApplication ,2);
			BOOST_ASN_CHOICE_TAG(eventConditionName ,3);
			BOOST_ASN_CHOICE_TAG(eventActionName ,4);
			BOOST_ASN_CHOICE_TAG(continueAfter ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum DeleteEventEnrollment_Request_enum {
		DeleteEventEnrollment_Request_null = 0  , 
		DeleteEventEnrollment_Request_specific , 
		DeleteEventEnrollment_Request_ec , 
		DeleteEventEnrollment_Request_ea , 
	};

	struct  DeleteEventEnrollment_Request : public BOOST_ASN_CHOICE_STRUCT(DeleteEventEnrollment_Request_enum) {

		//   SEQUENCE_OF is specific 
		typedef std::vector<ObjectName >   specific_type;


		DeleteEventEnrollment_Request() : BOOST_ASN_CHOICE_STRUCT(DeleteEventEnrollment_Request_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(specific, specific_type,  DeleteEventEnrollment_Request_specific)
		BOOST_ASN_VALUE_CHOICE(ec, ObjectName,  DeleteEventEnrollment_Request_ec)
		BOOST_ASN_VALUE_CHOICE(ea, ObjectName,  DeleteEventEnrollment_Request_ea)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , DeleteEventEnrollment_Request_specific) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , DeleteEventEnrollment_Request_ec) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , DeleteEventEnrollment_Request_ea) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case DeleteEventEnrollment_Request_specific: {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , DeleteEventEnrollment_Request_specific) ,0); break;}
					case DeleteEventEnrollment_Request_ec: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , DeleteEventEnrollment_Request_ec) ,1); break;}
					case DeleteEventEnrollment_Request_ea: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , DeleteEventEnrollment_Request_ea) ,2); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum CS_DefineEventEnrollment_Request__impl_enum {
		CS_DefineEventEnrollment_Request__impl_null = 0  , 
		CS_DefineEventEnrollment_Request__impl_string , 
		CS_DefineEventEnrollment_Request__impl_index , 
		CS_DefineEventEnrollment_Request__impl_noEnhancement , 
	};

	struct  CS_DefineEventEnrollment_Request__impl : public BOOST_ASN_CHOICE_STRUCT(CS_DefineEventEnrollment_Request__impl_enum) {





		CS_DefineEventEnrollment_Request__impl() : BOOST_ASN_CHOICE_STRUCT(CS_DefineEventEnrollment_Request__impl_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  CS_DefineEventEnrollment_Request__impl_string)
		BOOST_ASN_VALUE_CHOICE(index, int,  CS_DefineEventEnrollment_Request__impl_index)
		BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  CS_DefineEventEnrollment_Request__impl_noEnhancement)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , CS_DefineEventEnrollment_Request__impl_string) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , CS_DefineEventEnrollment_Request__impl_index) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , CS_DefineEventEnrollment_Request__impl_noEnhancement))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CS_DefineEventEnrollment_Request__impl_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , CS_DefineEventEnrollment_Request__impl_string) ,0); break;}
					case CS_DefineEventEnrollment_Request__impl_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , CS_DefineEventEnrollment_Request__impl_index) ,1); break;}
					case CS_DefineEventEnrollment_Request__impl_noEnhancement: {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_DefineEventEnrollment_Request__impl_noEnhancement)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  DefineEventEnrollment_Request{

		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<Transitions >  eventConditionTransitions;
		boost::asn1::value_holder<AlarmAckRule >  alarmAcknowledgmentRule;
		boost::asn1::value_holder<ObjectName >  eventActionName;
		boost::shared_ptr<ApplicationReference > clientApplication;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  clientApplication)

 
		DefineEventEnrollment_Request()  : eventEnrollmentName() , eventConditionName() , eventConditionTransitions() , alarmAcknowledgmentRule() , eventActionName() , clientApplication()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_CHOICE_TAG(eventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions ,2);
			BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule ,3);
			BOOST_ASN_CHOICE_TAG(eventActionName ,4);
			BOOST_ASN_EXPLICIT_TAG(clientApplication ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetEventActionAttributes_Response{

		//   SEQUENCE_OF is listOfModifier 
		typedef std::vector<Modifier >   listOfModifier_type;


		boost::shared_ptr<bool > mmsDeletable;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  mmsDeletable)

 		boost::asn1::value_holder<listOfModifier_type >  listOfModifier;
		boost::asn1::value_holder<ConfirmedServiceRequest >  confirmedServiceRequest;
		boost::asn1::value_holder<Request_Detail >  cs_extension;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetEventActionAttributes_Response()  : listOfModifier() , confirmedServiceRequest() , cs_extension()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfModifier ,1);
			BOOST_ASN_CHOICE_TAG(confirmedServiceRequest ,2);
			BOOST_ASN_CHOICE_TAG(cs_extension ,79);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum DeleteEventAction_Request_enum {
		DeleteEventAction_Request_null = 0  , 
		DeleteEventAction_Request_specific , 
		DeleteEventAction_Request_aa_specific , 
		DeleteEventAction_Request_domain , 
		DeleteEventAction_Request_vmd , 
	};

	struct  DeleteEventAction_Request : public BOOST_ASN_CHOICE_STRUCT(DeleteEventAction_Request_enum) {

		//   SEQUENCE_OF is specific 
		typedef std::vector<ObjectName >   specific_type;




		DeleteEventAction_Request() : BOOST_ASN_CHOICE_STRUCT(DeleteEventAction_Request_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(specific, specific_type,  DeleteEventAction_Request_specific)
		BOOST_ASN_VALUE_CHOICE(aa_specific, null_type,  DeleteEventAction_Request_aa_specific)
		BOOST_ASN_VALUE_CHOICE(domain, Identifier,  DeleteEventAction_Request_domain)
		BOOST_ASN_VALUE_CHOICE(vmd, null_type,  DeleteEventAction_Request_vmd)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , DeleteEventAction_Request_specific) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventAction_Request_aa_specific) ,1)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteEventAction_Request_domain) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventAction_Request_vmd) ,4)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case DeleteEventAction_Request_specific: {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , DeleteEventAction_Request_specific) ,0); break;}
					case DeleteEventAction_Request_aa_specific: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventAction_Request_aa_specific) ,1); break;}
					case DeleteEventAction_Request_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteEventAction_Request_domain) ,3); break;}
					case DeleteEventAction_Request_vmd: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventAction_Request_vmd) ,4); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  DefineEventAction_Request{
		//   SEQUENCE_OF is listOfModifier 
		typedef std::vector<Modifier >   listOfModifier_type;


		boost::asn1::value_holder<ObjectName >  eventActionName;
		boost::shared_ptr<listOfModifier_type > listOfModifier;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfModifier_type ,  listOfModifier)

 		boost::asn1::value_holder<ConfirmedServiceRequest >  confirmedServiceRequest;
		boost::asn1::value_holder<Request_Detail >  cs_extension;

		DefineEventAction_Request()  : eventActionName() , confirmedServiceRequest() , cs_extension()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventActionName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfModifier ,1);
			BOOST_ASN_CHOICE_TAG(confirmedServiceRequest ,2);
			BOOST_ASN_CHOICE_TAG(cs_extension ,79);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  CS_AlterEventConditionMonitoring_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum changeDisplay_type_enum {
			changeDisplay_type_null = 0  , 
			changeDisplay_type_string , 
			changeDisplay_type_index , 
			changeDisplay_type_noEnhancement , 
		};

	struct  changeDisplay_type : public BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) {





			changeDisplay_type() : BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  changeDisplay_type_string)
			BOOST_ASN_VALUE_CHOICE(index, int,  changeDisplay_type_index)
			BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  changeDisplay_type_noEnhancement)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , changeDisplay_type_string) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , changeDisplay_type_index) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_EXPLICIT_TAG(value<null_type > (true , changeDisplay_type_noEnhancement) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case changeDisplay_type_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , changeDisplay_type_string) ,0); break;}
						case changeDisplay_type_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , changeDisplay_type_index) ,1); break;}
						case changeDisplay_type_noEnhancement: {BOOST_ASN_EXPLICIT_TAG(value<null_type > (false , changeDisplay_type_noEnhancement) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<changeDisplay_type >  changeDisplay;

		CS_AlterEventConditionMonitoring_Request()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(changeDisplay);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AlterEventConditionMonitoring_Request{



		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::shared_ptr<bool > enabled;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  enabled)

 		boost::shared_ptr<Priority > priority;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 		boost::shared_ptr<bool > alarmSummaryReports;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  alarmSummaryReports)

 		boost::shared_ptr<Unsigned32 > evaluationInterval;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  evaluationInterval)

 
		AlterEventConditionMonitoring_Request()  : eventConditionName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionName ,0);
			BOOST_ASN_IMPLICIT_TAG(enabled ,1);
			BOOST_ASN_IMPLICIT_TAG(priority ,2);
			BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports ,3);
			BOOST_ASN_IMPLICIT_TAG(evaluationInterval ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportEventConditionStatus_Response{


		boost::asn1::value_holder<EC_State >  currentState;
		boost::asn1::value_holder<Unsigned32 >  numberOfEventEnrollments;
		boost::shared_ptr<bool > enabled;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  enabled)

 		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToActive;
		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToIdle;

		ReportEventConditionStatus_Response()  : currentState() , numberOfEventEnrollments() , timeOfLastTransitionToActive() , timeOfLastTransitionToIdle()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(currentState ,0);
			BOOST_ASN_IMPLICIT_TAG(numberOfEventEnrollments ,1);
			BOOST_ASN_IMPLICIT_TAG(enabled ,2);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive ,3);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  CS_GetEventConditionAttributes_Response{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum groupPriorityOverride_type_enum {
			groupPriorityOverride_type_null = 0  , 
			groupPriorityOverride_type_priority , 
			groupPriorityOverride_type_undefined , 
		};

	struct  groupPriorityOverride_type : public BOOST_ASN_CHOICE_STRUCT(groupPriorityOverride_type_enum) {



			groupPriorityOverride_type() : BOOST_ASN_CHOICE_STRUCT(groupPriorityOverride_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(priority, Priority,  groupPriorityOverride_type_priority)
			BOOST_ASN_VALUE_CHOICE(undefined, null_type,  groupPriorityOverride_type_undefined)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Priority > (true , groupPriorityOverride_type_priority) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , groupPriorityOverride_type_undefined) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case groupPriorityOverride_type_priority: {BOOST_ASN_IMPLICIT_TAG(value<Priority > (false , groupPriorityOverride_type_priority) ,0); break;}
						case groupPriorityOverride_type_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , groupPriorityOverride_type_undefined) ,1); break;}
						default:{}}}
			}
		};

		//   SEQUENCE_OF is listOfReferencingECL 
		typedef std::vector<ObjectName >   listOfReferencingECL_type;


	//start==============================================================
	//It is  INTERNAL CHOICE

			enum displayEnhancement_type_enum {
			displayEnhancement_type_null = 0  , 
			displayEnhancement_type_string , 
			displayEnhancement_type_index , 
			displayEnhancement_type_noEnhancement , 
		};

	struct  displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {





			displayEnhancement_type() : BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  displayEnhancement_type_string)
			BOOST_ASN_VALUE_CHOICE(index, int,  displayEnhancement_type_index)
			BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  displayEnhancement_type_noEnhancement)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , displayEnhancement_type_string) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_index) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , displayEnhancement_type_noEnhancement) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case displayEnhancement_type_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , displayEnhancement_type_string) ,0); break;}
						case displayEnhancement_type_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_index) ,1); break;}
						case displayEnhancement_type_noEnhancement: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , displayEnhancement_type_noEnhancement) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<groupPriorityOverride_type >  groupPriorityOverride;
		boost::shared_ptr<listOfReferencingECL_type > listOfReferencingECL;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfReferencingECL_type ,  listOfReferencingECL)

 		boost::asn1::value_holder<displayEnhancement_type >  displayEnhancement;

		CS_GetEventConditionAttributes_Response()  : displayEnhancement()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(groupPriorityOverride ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfReferencingECL ,1);
			BOOST_ASN_CHOICE_TAG(displayEnhancement ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetEventConditionAttributes_Response{



	//start==============================================================
	//It is  INTERNAL CHOICE

			enum monitoredVariable_type_enum {
			monitoredVariable_type_null = 0  , 
			monitoredVariable_type_variableReference , 
			monitoredVariable_type_undefined , 
		};

	struct  monitoredVariable_type : public BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) {



			monitoredVariable_type() : BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(variableReference, VariableSpecification,  monitoredVariable_type_variableReference)
			BOOST_ASN_VALUE_CHOICE(undefined, null_type,  monitoredVariable_type_undefined)

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
								case 0: { if(BOOST_ASN_CHOICE_TAG(value<VariableSpecification > (true , monitoredVariable_type_variableReference) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , monitoredVariable_type_undefined) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case monitoredVariable_type_variableReference: {BOOST_ASN_CHOICE_TAG(value<VariableSpecification > (false , monitoredVariable_type_variableReference) ,0); break;}
						case monitoredVariable_type_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , monitoredVariable_type_undefined) ,1); break;}
						default:{}}}
			}
		};


		boost::shared_ptr<bool > mmsDeletable;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  mmsDeletable)

 		boost::asn1::value_holder<EC_Class >  classV;
		boost::shared_ptr<Priority > priority;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 		boost::shared_ptr<Unsigned8 > severity;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned8 ,  severity)

 		boost::shared_ptr<bool > alarmSummaryReports;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  alarmSummaryReports)

 		boost::asn1::value_holder<monitoredVariable_type >  monitoredVariable;
		boost::shared_ptr<Unsigned32 > evaluationInterval;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  evaluationInterval)

 		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetEventConditionAttributes_Response()  : classV()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,0);
			BOOST_ASN_IMPLICIT_TAG(classV ,1);
			BOOST_ASN_IMPLICIT_TAG(priority ,2);
			BOOST_ASN_IMPLICIT_TAG(severity ,3);
			BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports ,4);
			BOOST_ASN_CHOICE_TAG(monitoredVariable ,6);
			BOOST_ASN_IMPLICIT_TAG(evaluationInterval ,7);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,8);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum DeleteEventCondition_Request_enum {
		DeleteEventCondition_Request_null = 0  , 
		DeleteEventCondition_Request_specific , 
		DeleteEventCondition_Request_aa_specific , 
		DeleteEventCondition_Request_domain , 
		DeleteEventCondition_Request_vmd , 
	};

	struct  DeleteEventCondition_Request : public BOOST_ASN_CHOICE_STRUCT(DeleteEventCondition_Request_enum) {

		//   SEQUENCE_OF is specific 
		typedef std::vector<ObjectName >   specific_type;




		DeleteEventCondition_Request() : BOOST_ASN_CHOICE_STRUCT(DeleteEventCondition_Request_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(specific, specific_type,  DeleteEventCondition_Request_specific)
		BOOST_ASN_VALUE_CHOICE(aa_specific, null_type,  DeleteEventCondition_Request_aa_specific)
		BOOST_ASN_VALUE_CHOICE(domain, Identifier,  DeleteEventCondition_Request_domain)
		BOOST_ASN_VALUE_CHOICE(vmd, null_type,  DeleteEventCondition_Request_vmd)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , DeleteEventCondition_Request_specific) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventCondition_Request_aa_specific) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteEventCondition_Request_domain) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventCondition_Request_vmd) ,3)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case DeleteEventCondition_Request_specific: {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , DeleteEventCondition_Request_specific) ,0); break;}
					case DeleteEventCondition_Request_aa_specific: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventCondition_Request_aa_specific) ,1); break;}
					case DeleteEventCondition_Request_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteEventCondition_Request_domain) ,2); break;}
					case DeleteEventCondition_Request_vmd: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventCondition_Request_vmd) ,3); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum CS_DefineEventCondition_Request__impl_enum {
		CS_DefineEventCondition_Request__impl_null = 0  , 
		CS_DefineEventCondition_Request__impl_string , 
		CS_DefineEventCondition_Request__impl_index , 
		CS_DefineEventCondition_Request__impl_noEnhancement , 
	};

	struct  CS_DefineEventCondition_Request__impl : public BOOST_ASN_CHOICE_STRUCT(CS_DefineEventCondition_Request__impl_enum) {





		CS_DefineEventCondition_Request__impl() : BOOST_ASN_CHOICE_STRUCT(CS_DefineEventCondition_Request__impl_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  CS_DefineEventCondition_Request__impl_string)
		BOOST_ASN_VALUE_CHOICE(index, int,  CS_DefineEventCondition_Request__impl_index)
		BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  CS_DefineEventCondition_Request__impl_noEnhancement)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , CS_DefineEventCondition_Request__impl_string) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , CS_DefineEventCondition_Request__impl_index) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , CS_DefineEventCondition_Request__impl_noEnhancement))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CS_DefineEventCondition_Request__impl_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , CS_DefineEventCondition_Request__impl_string) ,0); break;}
					case CS_DefineEventCondition_Request__impl_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , CS_DefineEventCondition_Request__impl_index) ,1); break;}
					case CS_DefineEventCondition_Request__impl_noEnhancement: {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_DefineEventCondition_Request__impl_noEnhancement)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  DefineEventCondition_Request{


		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<EC_Class >  classV;
		boost::shared_ptr<Priority > priority;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 		boost::shared_ptr<Unsigned8 > severity;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned8 ,  severity)

 		boost::shared_ptr<bool > alarmSummaryReports;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  alarmSummaryReports)

 		boost::asn1::value_holder<VariableSpecification >  monitoredVariable;
		boost::shared_ptr<Unsigned32 > evaluationInterval;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  evaluationInterval)

 
		DefineEventCondition_Request()  : eventConditionName() , classV() , monitoredVariable()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionName ,0);
			BOOST_ASN_IMPLICIT_TAG(classV ,1);
			BOOST_ASN_IMPLICIT_TAG(priority ,2);
			BOOST_ASN_IMPLICIT_TAG(severity ,3);
			BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports ,4);
			BOOST_ASN_CHOICE_TAG(monitoredVariable ,6);
			BOOST_ASN_IMPLICIT_TAG(evaluationInterval ,7);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AttachToEventCondition{

		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<Transitions >  causingTransitions;
		boost::shared_ptr<Unsigned32 > acceptableDelay;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  acceptableDelay)

 
		AttachToEventCondition()  : eventEnrollmentName() , eventConditionName() , causingTransitions()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_CHOICE_TAG(eventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(causingTransitions ,2);
			BOOST_ASN_IMPLICIT_TAG(acceptableDelay ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AlarmEnrollmentSummary{


		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::shared_ptr<ApplicationReference > clientApplication;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  clientApplication)

 		boost::asn1::value_holder<Unsigned8 >  severity;
		boost::asn1::value_holder<EC_State >  currentState;
		boost::asn1::value_holder<EN_Additional_Detail >  displayEnhancement;
		boost::shared_ptr<bool > notificationLost;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  notificationLost)

 		boost::asn1::value_holder<AlarmAckRule >  alarmAcknowledgmentRule;
		boost::shared_ptr<EE_State > enrollmentState;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(EE_State ,  enrollmentState)

 		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToActive;
		boost::asn1::value_holder<EventTime >  timeActiveAcknowledged;
		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToIdle;
		boost::asn1::value_holder<EventTime >  timeIdleAcknowledged;

		AlarmEnrollmentSummary()  : eventEnrollmentName() , clientApplication() , severity() , currentState() , displayEnhancement() , alarmAcknowledgmentRule() , timeOfLastTransitionToActive() , timeActiveAcknowledged() , timeOfLastTransitionToIdle() , timeIdleAcknowledged()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_EXPLICIT_TAG(clientApplication ,2);
			BOOST_ASN_IMPLICIT_TAG(severity ,3);
			BOOST_ASN_IMPLICIT_TAG(currentState ,4);
			BOOST_ASN_BIND_TAG(displayEnhancement);
			BOOST_ASN_IMPLICIT_TAG(notificationLost ,6);
			BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule ,7);
			BOOST_ASN_IMPLICIT_TAG(enrollmentState ,8);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive ,9);
			BOOST_ASN_CHOICE_TAG(timeActiveAcknowledged ,10);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle ,11);
			BOOST_ASN_CHOICE_TAG(timeIdleAcknowledged ,12);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetAlarmEnrollmentSummary_Response{
		//   SEQUENCE_OF is listOfAlarmEnrollmentSummary 
		typedef std::vector<AlarmEnrollmentSummary >   listOfAlarmEnrollmentSummary_type;



		boost::asn1::value_holder<listOfAlarmEnrollmentSummary_type >  listOfAlarmEnrollmentSummary;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		GetAlarmEnrollmentSummary_Response()  : listOfAlarmEnrollmentSummary()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfAlarmEnrollmentSummary ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetAlarmEnrollmentSummary_Request{




		static const int acknowledgementFilter_not_acked = 0;
		static const int acknowledgementFilter_acked = 1;
		static const int acknowledgementFilter_all = 2;


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  severityFilter_type{

			boost::asn1::value_holder<Unsigned8 >  mostSevere;
			boost::asn1::value_holder<Unsigned8 >  leastSevere;

			severityFilter_type()  : mostSevere() , leastSevere()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(mostSevere ,0);
				BOOST_ASN_IMPLICIT_TAG(leastSevere ,1);
			}
		};

	//end==============================================================

		boost::shared_ptr<bool > enrollmentsOnly;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  enrollmentsOnly)

 		boost::shared_ptr<bool > activeAlarmsOnly;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  activeAlarmsOnly)

 		boost::shared_ptr<int > acknowledgementFilter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  acknowledgementFilter)

 		boost::shared_ptr<severityFilter_type > severityFilter;   //  DEFAULT  { mostSevere 0, leastSevere 127 } 
 		BOOST_ASN_VALUE_FUNC_DECLARATE(severityFilter_type ,  severityFilter)

 		boost::asn1::value_holder<ObjectName >  continueAfter;

		GetAlarmEnrollmentSummary_Request()  : acknowledgementFilter() , continueAfter()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(enrollmentsOnly ,0);
			BOOST_ASN_IMPLICIT_TAG(activeAlarmsOnly ,1);
			BOOST_ASN_IMPLICIT_TAG(acknowledgementFilter ,2);
			BOOST_ASN_IMPLICIT_TAG(severityFilter ,3);
			BOOST_ASN_CHOICE_TAG(continueAfter ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum EN_Additional_Detail__impl_enum {
		EN_Additional_Detail__impl_null = 0  , 
		EN_Additional_Detail__impl_string , 
		EN_Additional_Detail__impl_index , 
		EN_Additional_Detail__impl_noEnhancement , 
	};

	struct  EN_Additional_Detail__impl : public BOOST_ASN_CHOICE_STRUCT(EN_Additional_Detail__impl_enum) {





		EN_Additional_Detail__impl() : BOOST_ASN_CHOICE_STRUCT(EN_Additional_Detail__impl_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  EN_Additional_Detail__impl_string)
		BOOST_ASN_VALUE_CHOICE(index, int,  EN_Additional_Detail__impl_index)
		BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  EN_Additional_Detail__impl_noEnhancement)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , EN_Additional_Detail__impl_string) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , EN_Additional_Detail__impl_index) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , EN_Additional_Detail__impl_noEnhancement))) return; else free();
					;}}}
			else {
				 switch(type()){
					case EN_Additional_Detail__impl_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , EN_Additional_Detail__impl_string) ,0); break;}
					case EN_Additional_Detail__impl_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , EN_Additional_Detail__impl_index) ,1); break;}
					case EN_Additional_Detail__impl_noEnhancement: {BOOST_ASN_BIND_TAG(value<null_type > (false , EN_Additional_Detail__impl_noEnhancement)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  AlarmSummary{


		static const int unacknowledgedState_none = 0;
		static const int unacknowledgedState_active = 1;
		static const int unacknowledgedState_idle = 2;
		static const int unacknowledgedState_both = 3;


		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<Unsigned8 >  severity;
		boost::asn1::value_holder<EC_State >  currentState;
		boost::asn1::value_holder<int >  unacknowledgedState;
		boost::asn1::value_holder<EN_Additional_Detail >  displayEnhancement;
		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToActive;
		boost::asn1::value_holder<EventTime >  timeOfLastTransitionToIdle;

		AlarmSummary()  : eventConditionName() , severity() , currentState() , unacknowledgedState() , displayEnhancement() , timeOfLastTransitionToActive() , timeOfLastTransitionToIdle()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionName ,0);
			BOOST_ASN_IMPLICIT_TAG(severity ,1);
			BOOST_ASN_IMPLICIT_TAG(currentState ,2);
			BOOST_ASN_IMPLICIT_TAG(unacknowledgedState ,3);
			BOOST_ASN_BIND_TAG(displayEnhancement);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive ,5);
			BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle ,6);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetAlarmSummary_Response{
		//   SEQUENCE_OF is listOfAlarmSummary 
		typedef std::vector<AlarmSummary >   listOfAlarmSummary_type;



		boost::asn1::value_holder<listOfAlarmSummary_type >  listOfAlarmSummary;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		GetAlarmSummary_Response()  : listOfAlarmSummary()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfAlarmSummary ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetAlarmSummary_Request{




		static const int acknowledgementFilter_not_acked = 0;
		static const int acknowledgementFilter_acked = 1;
		static const int acknowledgementFilter_all = 2;


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  severityFilter_type{

			boost::asn1::value_holder<Unsigned8 >  mostSevere;
			boost::asn1::value_holder<Unsigned8 >  leastSevere;

			severityFilter_type()  : mostSevere() , leastSevere()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(mostSevere ,0);
				BOOST_ASN_IMPLICIT_TAG(leastSevere ,1);
			}
		};

	//end==============================================================

		boost::shared_ptr<bool > enrollmentsOnly;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  enrollmentsOnly)

 		boost::shared_ptr<bool > activeAlarmsOnly;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  activeAlarmsOnly)

 		boost::shared_ptr<int > acknowledgementFilter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  acknowledgementFilter)

 		boost::shared_ptr<severityFilter_type > severityFilter;   //  DEFAULT  { mostSevere 0, leastSevere 127 } 
 		BOOST_ASN_VALUE_FUNC_DECLARATE(severityFilter_type ,  severityFilter)

 		boost::asn1::value_holder<ObjectName >  continueAfter;

		GetAlarmSummary_Request()  : acknowledgementFilter() , continueAfter()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(enrollmentsOnly ,0);
			BOOST_ASN_IMPLICIT_TAG(activeAlarmsOnly ,1);
			BOOST_ASN_IMPLICIT_TAG(acknowledgementFilter ,2);
			BOOST_ASN_IMPLICIT_TAG(severityFilter ,3);
			BOOST_ASN_CHOICE_TAG(continueAfter ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AcknowledgeEventNotification_Request{

		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::asn1::value_holder<EC_State >  acknowledgedState;
		boost::asn1::value_holder<EventTime >  timeOfAcknowledgedTransition;

		AcknowledgeEventNotification_Request()  : eventEnrollmentName() , acknowledgedState() , timeOfAcknowledgedTransition()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_IMPLICIT_TAG(acknowledgedState ,2);
			BOOST_ASN_CHOICE_TAG(timeOfAcknowledgedTransition ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum CS_EventNotification__impl_enum {
		CS_EventNotification__impl_null = 0  , 
		CS_EventNotification__impl_string , 
		CS_EventNotification__impl_index , 
		CS_EventNotification__impl_noEnhancement , 
	};

	struct  CS_EventNotification__impl : public BOOST_ASN_CHOICE_STRUCT(CS_EventNotification__impl_enum) {





		CS_EventNotification__impl() : BOOST_ASN_CHOICE_STRUCT(CS_EventNotification__impl_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(string, visiblestring_type,  CS_EventNotification__impl_string)
		BOOST_ASN_VALUE_CHOICE(index, int,  CS_EventNotification__impl_index)
		BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type,  CS_EventNotification__impl_noEnhancement)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , CS_EventNotification__impl_string) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , CS_EventNotification__impl_index) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , CS_EventNotification__impl_noEnhancement))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CS_EventNotification__impl_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , CS_EventNotification__impl_string) ,0); break;}
					case CS_EventNotification__impl_index: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , CS_EventNotification__impl_index) ,1); break;}
					case CS_EventNotification__impl_noEnhancement: {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_EventNotification__impl_noEnhancement)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  EventNotification{


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  actionResult_type{

		//start==============================================================
		//It is  INTERNAL CHOICE

					enum successOrFailure_type_enum {
				successOrFailure_type_null = 0  , 
				successOrFailure_type_success , 
				successOrFailure_type_failure , 
			};

	struct  successOrFailure_type : public BOOST_ASN_CHOICE_STRUCT(successOrFailure_type_enum) {


			//start==============================================================
			//It is  INTERNAL SEQUENCE  

				struct  success_type{

					boost::asn1::value_holder<ConfirmedServiceResponse >  confirmedServiceResponse;
					boost::asn1::value_holder<Response_Detail >  cs_Response_Detail;

					success_type()  : confirmedServiceResponse() , cs_Response_Detail()  {}

					 template<typename Archive> void serialize(Archive& arch){

						BOOST_ASN_CHOICE(confirmedServiceResponse);
						BOOST_ASN_CHOICE_TAG(cs_Response_Detail ,79);
					}
				};

			//end==============================================================

			//start==============================================================
			//It is  INTERNAL SEQUENCE  

				struct  failure_type{

					boost::shared_ptr<Unsigned32 > modifierPosition;   //  OPTIONAL
					BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  modifierPosition)

 					boost::asn1::value_holder<ServiceError >  serviceError;

					failure_type()  : serviceError()  {}

					 template<typename Archive> void serialize(Archive& arch){

						BOOST_ASN_IMPLICIT_TAG(modifierPosition ,0);
						BOOST_ASN_IMPLICIT_TAG(serviceError ,1);
					}
				};

			//end==============================================================

				successOrFailure_type() : BOOST_ASN_CHOICE_STRUCT(successOrFailure_type_enum) ()  {}


				BOOST_ASN_VALUE_CHOICE(success, success_type,  successOrFailure_type_success)
				BOOST_ASN_VALUE_CHOICE(failure, failure_type,  successOrFailure_type_failure)

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
									case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<success_type > (true , successOrFailure_type_success) ,0)) return; else free(); break;}
									case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<failure_type > (true , successOrFailure_type_failure) ,1)) return; else free(); break;}
								default:{}}
								;}
							default:{
										;}}}
					else {
						 switch(type()){
							case successOrFailure_type_success: {BOOST_ASN_IMPLICIT_TAG(value<success_type > (false , successOrFailure_type_success) ,0); break;}
							case successOrFailure_type_failure: {BOOST_ASN_IMPLICIT_TAG(value<failure_type > (false , successOrFailure_type_failure) ,1); break;}
							default:{}}}
				}
			};


			boost::asn1::value_holder<ObjectName >  eventActionName;
			boost::asn1::value_holder<successOrFailure_type >  successOrFailure;

			actionResult_type()  : eventActionName() , successOrFailure()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE(eventActionName);
				BOOST_ASN_CHOICE(successOrFailure);
			}
		};

	//end==============================================================

		boost::asn1::value_holder<ObjectName >  eventEnrollmentName;
		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::asn1::value_holder<Severity >  severity;
		boost::shared_ptr<EC_State > currentState;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(EC_State ,  currentState)

 		boost::asn1::value_holder<EventTime >  transitionTime;
		boost::shared_ptr<bool > notificationLost;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  notificationLost)

 		boost::shared_ptr<AlarmAckRule > alarmAcknowledgmentRule;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AlarmAckRule ,  alarmAcknowledgmentRule)

 		boost::shared_ptr<actionResult_type > actionResult;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(actionResult_type ,  actionResult)

 
		EventNotification()  : eventEnrollmentName() , eventConditionName() , severity() , transitionTime()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventEnrollmentName ,0);
			BOOST_ASN_CHOICE_TAG(eventConditionName ,1);
			BOOST_ASN_IMPLICIT_TAG(severity ,2);
			BOOST_ASN_IMPLICIT_TAG(currentState ,3);
			BOOST_ASN_CHOICE_TAG(transitionTime ,4);
			BOOST_ASN_IMPLICIT_TAG(notificationLost ,6);
			BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule ,7);
			BOOST_ASN_IMPLICIT_TAG(actionResult ,8);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  TriggerEvent_Request{

		boost::asn1::value_holder<ObjectName >  eventConditionName;
		boost::shared_ptr<Priority > priority;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 
		TriggerEvent_Request()  : eventConditionName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(eventConditionName ,0);
			BOOST_ASN_IMPLICIT_TAG(priority ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Output_Request{
		//   SEQUENCE_OF is listOfOutputData 
		typedef std::vector<MMSString >   listOfOutputData_type;


		boost::asn1::value_holder<Identifier >  operatorStationName;
		boost::asn1::value_holder<listOfOutputData_type >  listOfOutputData;

		Output_Request()  : operatorStationName() , listOfOutputData()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(operatorStationName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfOutputData ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Input_Request{

		//   SEQUENCE_OF is listOfPromptData 
		typedef std::vector<MMSString >   listOfPromptData_type;


		boost::asn1::value_holder<Identifier >  operatorStationName;
		boost::shared_ptr<bool > echo;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  echo)

 		boost::shared_ptr<listOfPromptData_type > listOfPromptData;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfPromptData_type ,  listOfPromptData)

 		boost::shared_ptr<Unsigned32 > inputTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  inputTimeOut)

 
		Input_Request()  : operatorStationName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(operatorStationName ,0);
			BOOST_ASN_IMPLICIT_TAG(echo ,1);
			BOOST_ASN_IMPLICIT_TAG(listOfPromptData ,2);
			BOOST_ASN_IMPLICIT_TAG(inputTimeOut ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AttachToSemaphore{



		boost::asn1::value_holder<ObjectName >  semaphoreName;
		boost::shared_ptr<Identifier > namedToken;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  namedToken)

 		boost::shared_ptr<Priority > priority;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 		boost::shared_ptr<Unsigned32 > acceptableDelay;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  acceptableDelay)

 		boost::shared_ptr<Unsigned32 > controlTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  controlTimeOut)

 		boost::shared_ptr<bool > abortOnTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  abortOnTimeOut)

 		boost::shared_ptr<bool > relinquishIfConnectionLost;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  relinquishIfConnectionLost)

 
		AttachToSemaphore()  : semaphoreName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(semaphoreName ,0);
			BOOST_ASN_IMPLICIT_TAG(namedToken ,1);
			BOOST_ASN_IMPLICIT_TAG(priority ,2);
			BOOST_ASN_IMPLICIT_TAG(acceptableDelay ,3);
			BOOST_ASN_IMPLICIT_TAG(controlTimeOut ,4);
			BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut ,5);
			BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost ,6);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  SemaphoreEntry{



		static const int entryClass_simple = 0;
		static const int entryClass_modifier = 1;




		boost::asn1::value_holder<octetstring_type >  entryID;
		boost::asn1::value_holder<int >  entryClass;
		boost::asn1::value_holder<ApplicationReference >  applicationReference;
		boost::shared_ptr<Identifier > namedToken;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  namedToken)

 		boost::shared_ptr<Priority > priority;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 		boost::shared_ptr<Unsigned32 > remainingTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  remainingTimeOut)

 		boost::shared_ptr<bool > abortOnTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  abortOnTimeOut)

 		boost::shared_ptr<bool > relinquishIfConnectionLost;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  relinquishIfConnectionLost)

 
		SemaphoreEntry()  : entryID() , entryClass() , applicationReference()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(entryID ,0);
			BOOST_ASN_IMPLICIT_TAG(entryClass ,1);
			BOOST_ASN_EXPLICIT_TAG(applicationReference ,2);
			BOOST_ASN_IMPLICIT_TAG(namedToken ,3);
			BOOST_ASN_IMPLICIT_TAG(priority ,4);
			BOOST_ASN_IMPLICIT_TAG(remainingTimeOut ,5);
			BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut ,6);
			BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost ,7);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportSemaphoreEntryStatus_Response{
		//   SEQUENCE_OF is listOfSemaphoreEntry 
		typedef std::vector<SemaphoreEntry >   listOfSemaphoreEntry_type;



		boost::asn1::value_holder<listOfSemaphoreEntry_type >  listOfSemaphoreEntry;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		ReportSemaphoreEntryStatus_Response()  : listOfSemaphoreEntry()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfSemaphoreEntry ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportSemaphoreEntryStatus_Request{


		static const int state_queued = 0;
		static const int state_owner = 1;
		static const int state_hung = 2;



		boost::asn1::value_holder<ObjectName >  semaphoreName;
		boost::asn1::value_holder<int >  state;
		boost::shared_ptr<octetstring_type > entryIDToStartAfter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(octetstring_type ,  entryIDToStartAfter)

 
		ReportSemaphoreEntryStatus_Request()  : semaphoreName() , state()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(semaphoreName ,0);
			BOOST_ASN_IMPLICIT_TAG(state ,1);
			BOOST_ASN_IMPLICIT_TAG(entryIDToStartAfter ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportPoolSemaphoreStatus_Response{
		//   SEQUENCE_OF is listOfNamedTokens 
			//start==============================================================
		//It is  INTERNAL CHOICE

					enum listOfNamedTokens_type_sequence_of_enum {
				listOfNamedTokens_type_sequence_of_null = 0  , 
				listOfNamedTokens_type_sequence_of_freeNamedToken , 
				listOfNamedTokens_type_sequence_of_ownedNamedToken , 
				listOfNamedTokens_type_sequence_of_hungNamedToken , 
			};

	struct  listOfNamedTokens_type_sequence_of : public BOOST_ASN_CHOICE_STRUCT(listOfNamedTokens_type_sequence_of_enum) {


				listOfNamedTokens_type_sequence_of() : BOOST_ASN_CHOICE_STRUCT(listOfNamedTokens_type_sequence_of_enum) ()  {}


				BOOST_ASN_VALUE_CHOICE(freeNamedToken, Identifier,  listOfNamedTokens_type_sequence_of_freeNamedToken)
				BOOST_ASN_VALUE_CHOICE(ownedNamedToken, Identifier,  listOfNamedTokens_type_sequence_of_ownedNamedToken)
				BOOST_ASN_VALUE_CHOICE(hungNamedToken, Identifier,  listOfNamedTokens_type_sequence_of_hungNamedToken)

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
									case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , listOfNamedTokens_type_sequence_of_freeNamedToken) ,0)) return; else free(); break;}
									case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , listOfNamedTokens_type_sequence_of_ownedNamedToken) ,1)) return; else free(); break;}
									case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , listOfNamedTokens_type_sequence_of_hungNamedToken) ,2)) return; else free(); break;}
								default:{}}
								;}
							default:{
										;}}}
					else {
						 switch(type()){
							case listOfNamedTokens_type_sequence_of_freeNamedToken: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , listOfNamedTokens_type_sequence_of_freeNamedToken) ,0); break;}
							case listOfNamedTokens_type_sequence_of_ownedNamedToken: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , listOfNamedTokens_type_sequence_of_ownedNamedToken) ,1); break;}
							case listOfNamedTokens_type_sequence_of_hungNamedToken: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , listOfNamedTokens_type_sequence_of_hungNamedToken) ,2); break;}
							default:{}}}
				}
			};

	typedef std::vector<listOfNamedTokens_type_sequence_of >   listOfNamedTokens_type;



		boost::asn1::value_holder<listOfNamedTokens_type >  listOfNamedTokens;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		ReportPoolSemaphoreStatus_Response()  : listOfNamedTokens()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfNamedTokens ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportPoolSemaphoreStatus_Request{

		boost::asn1::value_holder<ObjectName >  semaphoreName;
		boost::shared_ptr<Identifier > nameToStartAfter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  nameToStartAfter)

 
		ReportPoolSemaphoreStatus_Request()  : semaphoreName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(semaphoreName ,0);
			BOOST_ASN_IMPLICIT_TAG(nameToStartAfter ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportSemaphoreStatus_Response{



		static const int classV_token = 0;
		static const int classV_pool = 1;


		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::asn1::value_holder<int >  classV;
		boost::asn1::value_holder<Unsigned16 >  numberOfTokens;
		boost::asn1::value_holder<Unsigned16 >  numberOfOwnedTokens;
		boost::asn1::value_holder<Unsigned16 >  numberOfHungTokens;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		ReportSemaphoreStatus_Response()  : mmsDeletable() , classV() , numberOfTokens() , numberOfOwnedTokens() , numberOfHungTokens()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,0);
			BOOST_ASN_IMPLICIT_TAG(classV ,1);
			BOOST_ASN_IMPLICIT_TAG(numberOfTokens ,2);
			BOOST_ASN_IMPLICIT_TAG(numberOfOwnedTokens ,3);
			BOOST_ASN_IMPLICIT_TAG(numberOfHungTokens ,4);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DefineSemaphore_Request{

		boost::asn1::value_holder<ObjectName >  semaphoreName;
		boost::asn1::value_holder<Unsigned16 >  numberOfTokens;

		DefineSemaphore_Request()  : semaphoreName() , numberOfTokens()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(semaphoreName ,0);
			BOOST_ASN_IMPLICIT_TAG(numberOfTokens ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RelinquishControl_Request{

		boost::asn1::value_holder<ObjectName >  semaphoreName;
		boost::shared_ptr<Identifier > namedToken;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  namedToken)

 
		RelinquishControl_Request()  : semaphoreName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(semaphoreName ,0);
			BOOST_ASN_IMPLICIT_TAG(namedToken ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum TakeControl_Response_enum {
		TakeControl_Response_null = 0  , 
		TakeControl_Response_noResult , 
		TakeControl_Response_namedToken , 
	};

	struct  TakeControl_Response : public BOOST_ASN_CHOICE_STRUCT(TakeControl_Response_enum) {



		TakeControl_Response() : BOOST_ASN_CHOICE_STRUCT(TakeControl_Response_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(noResult, null_type,  TakeControl_Response_noResult)
		BOOST_ASN_VALUE_CHOICE(namedToken, Identifier,  TakeControl_Response_namedToken)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TakeControl_Response_noResult) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , TakeControl_Response_namedToken) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case TakeControl_Response_noResult: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TakeControl_Response_noResult) ,0); break;}
					case TakeControl_Response_namedToken: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , TakeControl_Response_namedToken) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  TakeControl_Request{



		boost::asn1::value_holder<ObjectName >  semaphoreName;
		boost::shared_ptr<Identifier > namedToken;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  namedToken)

 		boost::shared_ptr<Priority > priority;   //  DEFAULT  int  64  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(Priority ,  priority)

 		boost::shared_ptr<Unsigned32 > acceptableDelay;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  acceptableDelay)

 		boost::shared_ptr<Unsigned32 > controlTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  controlTimeOut)

 		boost::shared_ptr<bool > abortOnTimeOut;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  abortOnTimeOut)

 		boost::shared_ptr<bool > relinquishIfConnectionLost;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  relinquishIfConnectionLost)

 		boost::shared_ptr<ApplicationReference > applicationToPreempt;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  applicationToPreempt)

 
		TakeControl_Request()  : semaphoreName() , applicationToPreempt()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(semaphoreName ,0);
			BOOST_ASN_IMPLICIT_TAG(namedToken ,1);
			BOOST_ASN_IMPLICIT_TAG(priority ,2);
			BOOST_ASN_IMPLICIT_TAG(acceptableDelay ,3);
			BOOST_ASN_IMPLICIT_TAG(controlTimeOut ,4);
			BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut ,5);
			BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost ,6);
			BOOST_ASN_IMPLICIT_TAG(applicationToPreempt ,7);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetDataExchangeAttributes_Response{

		//   SEQUENCE_OF is listOfRequestTypeDescriptions 
		typedef std::vector<TypeDescription >   listOfRequestTypeDescriptions_type;

		//   SEQUENCE_OF is listOfResponseTypeDescriptions 
		typedef std::vector<TypeDescription >   listOfResponseTypeDescriptions_type;


		boost::asn1::value_holder<bool >  inUse;
		boost::asn1::value_holder<listOfRequestTypeDescriptions_type >  listOfRequestTypeDescriptions;
		boost::asn1::value_holder<listOfResponseTypeDescriptions_type >  listOfResponseTypeDescriptions;
		boost::shared_ptr<Identifier > programInvocation;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  programInvocation)

 		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetDataExchangeAttributes_Response()  : inUse() , listOfRequestTypeDescriptions() , listOfResponseTypeDescriptions()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(inUse ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfRequestTypeDescriptions ,1);
			BOOST_ASN_IMPLICIT_TAG(listOfResponseTypeDescriptions ,2);
			BOOST_ASN_IMPLICIT_TAG(programInvocation ,3);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ExchangeData_Response{
		//   SEQUENCE_OF is listOfResponseData 
		typedef std::vector<Data >   listOfResponseData_type;


		boost::asn1::value_holder<listOfResponseData_type >  listOfResponseData;

		ExchangeData_Response()  : listOfResponseData()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfResponseData ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ExchangeData_Request{
		//   SEQUENCE_OF is listOfRequestData 
		typedef std::vector<Data >   listOfRequestData_type;


		boost::asn1::value_holder<ObjectName >  dataExchangeName;
		boost::asn1::value_holder<listOfRequestData_type >  listOfRequestData;

		ExchangeData_Request()  : dataExchangeName() , listOfRequestData()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(dataExchangeName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfRequestData ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteNamedType_Response{

		boost::asn1::value_holder<Unsigned32 >  numberMatched;
		boost::asn1::value_holder<Unsigned32 >  numberDeleted;

		DeleteNamedType_Response()  : numberMatched() , numberDeleted()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(numberMatched ,0);
			BOOST_ASN_IMPLICIT_TAG(numberDeleted ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteNamedType_Request{


		static const int scopeOfDelete_specific = 0;
		static const int scopeOfDelete_aa_specific = 1;
		static const int scopeOfDelete_domain = 2;
		static const int scopeOfDelete_vmd = 3;

		//   SEQUENCE_OF is listOfTypeName 
		typedef std::vector<ObjectName >   listOfTypeName_type;


		boost::shared_ptr<int > scopeOfDelete;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  scopeOfDelete)

 		boost::shared_ptr<listOfTypeName_type > listOfTypeName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfTypeName_type ,  listOfTypeName)

 		boost::shared_ptr<Identifier > domainName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  domainName)

 
		DeleteNamedType_Request()  : scopeOfDelete()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(scopeOfDelete ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfTypeName ,1);
			BOOST_ASN_IMPLICIT_TAG(domainName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetNamedTypeAttributes_Response{



		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::asn1::value_holder<TypeSpecification >  typeSpecification;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 		boost::shared_ptr<visiblestring_type > meaning;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  meaning)

 
		GetNamedTypeAttributes_Response()  : mmsDeletable() , typeSpecification()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,0);
			BOOST_ASN_CHOICE(typeSpecification);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,1);
			BOOST_ASN_IMPLICIT_TAG(meaning ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DefineNamedType_Request{

		boost::asn1::value_holder<ObjectName >  typeName;
		boost::asn1::value_holder<TypeSpecification >  typeSpecification;

		DefineNamedType_Request()  : typeName() , typeSpecification()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(typeName);
			BOOST_ASN_CHOICE(typeSpecification);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteNamedVariableList_Response{

		boost::asn1::value_holder<Unsigned32 >  numberMatched;
		boost::asn1::value_holder<Unsigned32 >  numberDeleted;

		DeleteNamedVariableList_Response()  : numberMatched() , numberDeleted()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(numberMatched ,0);
			BOOST_ASN_IMPLICIT_TAG(numberDeleted ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteNamedVariableList_Request{


		static const int scopeOfDelete_specific = 0;
		static const int scopeOfDelete_aa_specific = 1;
		static const int scopeOfDelete_domain = 2;
		static const int scopeOfDelete_vmd = 3;

		//   SEQUENCE_OF is listOfVariableListName 
		typedef std::vector<ObjectName >   listOfVariableListName_type;


		boost::shared_ptr<int > scopeOfDelete;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  scopeOfDelete)

 		boost::shared_ptr<listOfVariableListName_type > listOfVariableListName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfVariableListName_type ,  listOfVariableListName)

 		boost::shared_ptr<Identifier > domainName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  domainName)

 
		DeleteNamedVariableList_Request()  : scopeOfDelete()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(scopeOfDelete ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfVariableListName ,1);
			BOOST_ASN_IMPLICIT_TAG(domainName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetNamedVariableListAttributes_Response{

		//   SEQUENCE_OF is listOfVariable 
			//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  listOfVariable_type_sequence_of{

				boost::asn1::value_holder<VariableSpecification >  variableSpecification;
				boost::shared_ptr<AlternateAccess > alternateAccess;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess ,  alternateAccess)

 
				listOfVariable_type_sequence_of()  : variableSpecification() , alternateAccess()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_CHOICE(variableSpecification);
					BOOST_ASN_IMPLICIT_TAG(alternateAccess ,5);
				}
			};

		//end==============================================================
	typedef std::vector<listOfVariable_type_sequence_of >   listOfVariable_type;


		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::asn1::value_holder<listOfVariable_type >  listOfVariable;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetNamedVariableListAttributes_Response()  : mmsDeletable() , listOfVariable()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfVariable ,1);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DefineNamedVariableList_Request{
		//   SEQUENCE_OF is listOfVariable 
			//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  listOfVariable_type_sequence_of{

				boost::asn1::value_holder<VariableSpecification >  variableSpecification;
				boost::shared_ptr<AlternateAccess > alternateAccess;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess ,  alternateAccess)

 
				listOfVariable_type_sequence_of()  : variableSpecification() , alternateAccess()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_CHOICE(variableSpecification);
					BOOST_ASN_IMPLICIT_TAG(alternateAccess ,5);
				}
			};

		//end==============================================================
	typedef std::vector<listOfVariable_type_sequence_of >   listOfVariable_type;


		boost::asn1::value_holder<ObjectName >  variableListName;
		boost::asn1::value_holder<listOfVariable_type >  listOfVariable;

		DefineNamedVariableList_Request()  : variableListName() , listOfVariable()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(variableListName);
			BOOST_ASN_IMPLICIT_TAG(listOfVariable ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteVariableAccess_Response{

		boost::asn1::value_holder<Unsigned32 >  numberMatched;
		boost::asn1::value_holder<Unsigned32 >  numberDeleted;

		DeleteVariableAccess_Response()  : numberMatched() , numberDeleted()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(numberMatched ,0);
			BOOST_ASN_IMPLICIT_TAG(numberDeleted ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DeleteVariableAccess_Request{


		static const int scopeOfDelete_specific = 0;
		static const int scopeOfDelete_aa_specific = 1;
		static const int scopeOfDelete_domain = 2;
		static const int scopeOfDelete_vmd = 3;

		//   SEQUENCE_OF is listOfName 
		typedef std::vector<ObjectName >   listOfName_type;


		boost::shared_ptr<int > scopeOfDelete;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  scopeOfDelete)

 		boost::shared_ptr<listOfName_type > listOfName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfName_type ,  listOfName)

 		boost::shared_ptr<Identifier > domainName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  domainName)

 
		DeleteVariableAccess_Request()  : scopeOfDelete()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(scopeOfDelete ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfName ,1);
			BOOST_ASN_IMPLICIT_TAG(domainName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  DefineNamedVariable_Request{

		boost::asn1::value_holder<ObjectName >  variableName;
		boost::asn1::value_holder<Address >  address;
		boost::asn1::value_holder<TypeSpecification >  typeSpecification;

		DefineNamedVariable_Request()  : variableName() , address() , typeSpecification()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(variableName ,0);
			BOOST_ASN_CHOICE_TAG(address ,1);
			BOOST_ASN_CHOICE_TAG(typeSpecification ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetVariableAccessAttributes_Response{



		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::shared_ptr<Address >  address;
		boost::asn1::value_holder<TypeDescription >  typeDescription;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 		boost::shared_ptr<visiblestring_type > meaning;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  meaning)

 
		GetVariableAccessAttributes_Response()  : mmsDeletable() , address() , typeDescription()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,0);
			BOOST_ASN_CHOICE_TAG(address ,1);
			BOOST_ASN_CHOICE_TAG(typeDescription ,2);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,3);
			BOOST_ASN_IMPLICIT_TAG(meaning ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum GetVariableAccessAttributes_Request_enum {
		GetVariableAccessAttributes_Request_null = 0  , 
		GetVariableAccessAttributes_Request_name , 
		GetVariableAccessAttributes_Request_address , 
	};

	struct  GetVariableAccessAttributes_Request : public BOOST_ASN_CHOICE_STRUCT(GetVariableAccessAttributes_Request_enum) {


		GetVariableAccessAttributes_Request() : BOOST_ASN_CHOICE_STRUCT(GetVariableAccessAttributes_Request_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(name, ObjectName,  GetVariableAccessAttributes_Request_name)
		BOOST_ASN_VALUE_CHOICE(address, Address,  GetVariableAccessAttributes_Request_address)

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
							case 0: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , GetVariableAccessAttributes_Request_name) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_CHOICE_TAG(value<Address > (true , GetVariableAccessAttributes_Request_address) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case GetVariableAccessAttributes_Request_name: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , GetVariableAccessAttributes_Request_name) ,0); break;}
					case GetVariableAccessAttributes_Request_address: {BOOST_ASN_CHOICE_TAG(value<Address > (false , GetVariableAccessAttributes_Request_address) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  InformationReport{
		//   SEQUENCE_OF is listOfAccessResult 
		typedef std::vector<AccessResult >   listOfAccessResult_type;


		boost::asn1::value_holder<VariableAccessSpecification >  variableAccessSpecification;
		boost::asn1::value_holder<listOfAccessResult_type >  listOfAccessResult;

		InformationReport()  : variableAccessSpecification() , listOfAccessResult()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(variableAccessSpecification);
			BOOST_ASN_IMPLICIT_TAG(listOfAccessResult ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Write_Request{
		//   SEQUENCE_OF is listOfData 
		typedef std::vector<Data >   listOfData_type;


		boost::asn1::value_holder<VariableAccessSpecification >  variableAccessSpecification;
		boost::asn1::value_holder<listOfData_type >  listOfData;

		Write_Request()  : variableAccessSpecification() , listOfData()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(variableAccessSpecification);
			BOOST_ASN_IMPLICIT_TAG(listOfData ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Read_Response{
		//   SEQUENCE_OF is listOfAccessResult 
		typedef std::vector<AccessResult >   listOfAccessResult_type;


		boost::shared_ptr<VariableAccessSpecification >  variableAccessSpecification;
		boost::asn1::value_holder<listOfAccessResult_type >  listOfAccessResult;

		Read_Response()  : variableAccessSpecification() , listOfAccessResult()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(variableAccessSpecification ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfAccessResult ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Read_Request{


		boost::shared_ptr<bool > specificationWithResult;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  specificationWithResult)

 		boost::asn1::value_holder<VariableAccessSpecification >  variableAccessSpecification;

		Read_Request()  : variableAccessSpecification()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(specificationWithResult ,0);
			BOOST_ASN_CHOICE_TAG(variableAccessSpecification ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum VariableSpecification_enum {
		VariableSpecification_null = 0  , 
		VariableSpecification_name , 
		VariableSpecification_address , 
		VariableSpecification_variableDescription , 
		VariableSpecification_scatteredAccessDescription , 
		VariableSpecification_invalidated , 
	};

	struct  VariableSpecification : public BOOST_ASN_CHOICE_STRUCT(VariableSpecification_enum) {


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  variableDescription_type{

			boost::asn1::value_holder<Address >  address;
			boost::asn1::value_holder<TypeSpecification >  typeSpecification;

			variableDescription_type()  : address() , typeSpecification()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE(address);
				BOOST_ASN_CHOICE(typeSpecification);
			}
		};

	//end==============================================================


		VariableSpecification() : BOOST_ASN_CHOICE_STRUCT(VariableSpecification_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(name, ObjectName,  VariableSpecification_name)
		BOOST_ASN_VALUE_CHOICE(address, Address,  VariableSpecification_address)
		BOOST_ASN_VALUE_CHOICE(variableDescription, variableDescription_type,  VariableSpecification_variableDescription)
		BOOST_ASN_VALUE_CHOICE(scatteredAccessDescription, ScatteredAccessDescription,  VariableSpecification_scatteredAccessDescription)
		BOOST_ASN_VALUE_CHOICE(invalidated, null_type,  VariableSpecification_invalidated)

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
							case 0: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , VariableSpecification_name) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_CHOICE_TAG(value<Address > (true , VariableSpecification_address) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<variableDescription_type > (true , VariableSpecification_variableDescription) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<ScatteredAccessDescription > (true , VariableSpecification_scatteredAccessDescription) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , VariableSpecification_invalidated) ,4)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case VariableSpecification_name: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , VariableSpecification_name) ,0); break;}
					case VariableSpecification_address: {BOOST_ASN_CHOICE_TAG(value<Address > (false , VariableSpecification_address) ,1); break;}
					case VariableSpecification_variableDescription: {BOOST_ASN_IMPLICIT_TAG(value<variableDescription_type > (false , VariableSpecification_variableDescription) ,2); break;}
					case VariableSpecification_scatteredAccessDescription: {BOOST_ASN_IMPLICIT_TAG(value<ScatteredAccessDescription > (false , VariableSpecification_scatteredAccessDescription) ,3); break;}
					case VariableSpecification_invalidated: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , VariableSpecification_invalidated) ,4); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum VariableAccessSpecification_enum {
		VariableAccessSpecification_null = 0  , 
		VariableAccessSpecification_listOfVariable , 
		VariableAccessSpecification_variableListName , 
	};

	struct  VariableAccessSpecification : public BOOST_ASN_CHOICE_STRUCT(VariableAccessSpecification_enum) {

		//   SEQUENCE_OF is listOfVariable 
			//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  listOfVariable_type_sequence_of{

				boost::asn1::value_holder<VariableSpecification >  variableSpecification;
				boost::shared_ptr<AlternateAccess > alternateAccess;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess ,  alternateAccess)

 
				listOfVariable_type_sequence_of()  : variableSpecification() , alternateAccess()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_CHOICE(variableSpecification);
					BOOST_ASN_IMPLICIT_TAG(alternateAccess ,5);
				}
			};

		//end==============================================================
	typedef std::vector<listOfVariable_type_sequence_of >   listOfVariable_type;


		VariableAccessSpecification() : BOOST_ASN_CHOICE_STRUCT(VariableAccessSpecification_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(listOfVariable, listOfVariable_type,  VariableAccessSpecification_listOfVariable)
		BOOST_ASN_VALUE_CHOICE(variableListName, ObjectName,  VariableAccessSpecification_variableListName)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<listOfVariable_type > (true , VariableAccessSpecification_listOfVariable) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , VariableAccessSpecification_variableListName) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case VariableAccessSpecification_listOfVariable: {BOOST_ASN_IMPLICIT_TAG(value<listOfVariable_type > (false , VariableAccessSpecification_listOfVariable) ,0); break;}
					case VariableAccessSpecification_variableListName: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , VariableAccessSpecification_variableListName) ,1); break;}
					default:{}}}
		}
	};


	const int DataAccessError_object_invalidated = 0;
	const int DataAccessError_hardware_fault = 1;
	const int DataAccessError_temporarily_unavailable = 2;
	const int DataAccessError_object_access_denied = 3;
	const int DataAccessError_object_undefined = 4;
	const int DataAccessError_invalid_address = 5;
	const int DataAccessError_type_unsupported = 6;
	const int DataAccessError_type_inconsistent = 7;
	const int DataAccessError_object_attribute_inconsistent = 8;
	const int DataAccessError_object_access_unsupported = 9;
	const int DataAccessError_object_non_existent = 10;
	const int DataAccessError_object_value_invalid = 11;

//start==============================================================
//It is   CHOICE

	enum Data_enum {
		Data_null = 0  , 
		Data_array , 
		Data_structure , 
		Data_boolean , 
		Data_bit_string , 
		Data_integer , 
		Data_unsignedV , 
		Data_floating_point , 
		Data_octet_string , 
		Data_visible_string , 
		Data_generalized_time , 
		Data_binary_time , 
		Data_bcd , 
		Data_booleanArray , 
		Data_objId , 
		Data_mMSString , 
	};

	struct  Data : public BOOST_ASN_CHOICE_STRUCT(Data_enum) {

		//   SEQUENCE_OF is array 
		typedef std::vector<Data >   array_type;

		//   SEQUENCE_OF is structure 
		typedef std::vector<Data >   structure_type;













		Data() : BOOST_ASN_CHOICE_STRUCT(Data_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(array, array_type,  Data_array)
		BOOST_ASN_VALUE_CHOICE(structure, structure_type,  Data_structure)
		BOOST_ASN_VALUE_CHOICE(boolean, bool,  Data_boolean)
		BOOST_ASN_VALUE_CHOICE(bit_string, bitstring_type,  Data_bit_string)
		BOOST_ASN_VALUE_CHOICE(integer, int,  Data_integer)
		BOOST_ASN_VALUE_CHOICE(unsignedV, int,  Data_unsignedV)
		BOOST_ASN_VALUE_CHOICE(floating_point, FloatingPoint,  Data_floating_point)
		BOOST_ASN_VALUE_CHOICE(octet_string, octetstring_type,  Data_octet_string)
		BOOST_ASN_VALUE_CHOICE(visible_string, visiblestring_type,  Data_visible_string)
		BOOST_ASN_VALUE_CHOICE(generalized_time, gentime_type,  Data_generalized_time)
		BOOST_ASN_VALUE_CHOICE(binary_time, TimeOfDay,  Data_binary_time)
		BOOST_ASN_VALUE_CHOICE(bcd, int,  Data_bcd)
		BOOST_ASN_VALUE_CHOICE(booleanArray, bitstring_type,  Data_booleanArray)
		BOOST_ASN_VALUE_CHOICE(objId, oid_type,  Data_objId)
		BOOST_ASN_VALUE_CHOICE(mMSString, MMSString,  Data_mMSString)

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
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<array_type > (true , Data_array) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<structure_type > (true , Data_structure) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<bool > (true , Data_boolean) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , Data_bit_string) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , Data_integer) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , Data_unsignedV) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<FloatingPoint > (true , Data_floating_point) ,7)) return; else free(); break;}
							case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , Data_octet_string) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , Data_visible_string) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<gentime_type > (true , Data_generalized_time) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , Data_binary_time) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , Data_bcd) ,13)) return; else free(); break;}
							case 14: { if(BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , Data_booleanArray) ,14)) return; else free(); break;}
							case 15: { if(BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , Data_objId) ,15)) return; else free(); break;}
							case 16: { if(BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , Data_mMSString) ,16)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case Data_array: {BOOST_ASN_IMPLICIT_TAG(value<array_type > (false , Data_array) ,1); break;}
					case Data_structure: {BOOST_ASN_IMPLICIT_TAG(value<structure_type > (false , Data_structure) ,2); break;}
					case Data_boolean: {BOOST_ASN_IMPLICIT_TAG(value<bool > (false , Data_boolean) ,3); break;}
					case Data_bit_string: {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , Data_bit_string) ,4); break;}
					case Data_integer: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , Data_integer) ,5); break;}
					case Data_unsignedV: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , Data_unsignedV) ,6); break;}
					case Data_floating_point: {BOOST_ASN_IMPLICIT_TAG(value<FloatingPoint > (false , Data_floating_point) ,7); break;}
					case Data_octet_string: {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , Data_octet_string) ,9); break;}
					case Data_visible_string: {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , Data_visible_string) ,10); break;}
					case Data_generalized_time: {BOOST_ASN_IMPLICIT_TAG(value<gentime_type > (false , Data_generalized_time) ,11); break;}
					case Data_binary_time: {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , Data_binary_time) ,12); break;}
					case Data_bcd: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , Data_bcd) ,13); break;}
					case Data_booleanArray: {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , Data_booleanArray) ,14); break;}
					case Data_objId: {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , Data_objId) ,15); break;}
					case Data_mMSString: {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , Data_mMSString) ,16); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AccessResult_enum {
		AccessResult_null = 0  , 
		AccessResult_failure , 
		AccessResult_success , 
	};

	struct  AccessResult : public BOOST_ASN_CHOICE_STRUCT(AccessResult_enum) {


		AccessResult() : BOOST_ASN_CHOICE_STRUCT(AccessResult_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(failure, DataAccessError,  AccessResult_failure)
		BOOST_ASN_VALUE_CHOICE(success, Data,  AccessResult_success)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (true , AccessResult_failure) ,0)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_CHOICE(value<Data > (true , AccessResult_success))) return; else free();
					;}}}
			else {
				 switch(type()){
					case AccessResult_failure: {BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (false , AccessResult_failure) ,0); break;}
					case AccessResult_success: {BOOST_ASN_CHOICE(value<Data > (false , AccessResult_success)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AlternateAccessSelection_enum {
		AlternateAccessSelection_null = 0  , 
		AlternateAccessSelection_selectAlternateAccess , 
		AlternateAccessSelection_selectAccess , 
	};

	struct  AlternateAccessSelection : public BOOST_ASN_CHOICE_STRUCT(AlternateAccessSelection_enum) {


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  selectAlternateAccess_type{

		//start==============================================================
		//It is  INTERNAL CHOICE

					enum accessSelection_type_enum {
				accessSelection_type_null = 0  , 
				accessSelection_type_component , 
				accessSelection_type_index , 
				accessSelection_type_indexRange , 
				accessSelection_type_allElements , 
			};

	struct  accessSelection_type : public BOOST_ASN_CHOICE_STRUCT(accessSelection_type_enum) {


			//start==============================================================
			//It is  INTERNAL SEQUENCE  

				struct  indexRange_type{

					boost::asn1::value_holder<Unsigned32 >  lowIndex;
					boost::asn1::value_holder<Unsigned32 >  numberOfElements;

					indexRange_type()  : lowIndex() , numberOfElements()  {}

					 template<typename Archive> void serialize(Archive& arch){

						BOOST_ASN_IMPLICIT_TAG(lowIndex ,0);
						BOOST_ASN_IMPLICIT_TAG(numberOfElements ,1);
					}
				};

			//end==============================================================


				accessSelection_type() : BOOST_ASN_CHOICE_STRUCT(accessSelection_type_enum) ()  {}


				BOOST_ASN_VALUE_CHOICE(component, Identifier,  accessSelection_type_component)
				BOOST_ASN_VALUE_CHOICE(index, Unsigned32,  accessSelection_type_index)
				BOOST_ASN_VALUE_CHOICE(indexRange, indexRange_type,  accessSelection_type_indexRange)
				BOOST_ASN_VALUE_CHOICE(allElements, null_type,  accessSelection_type_allElements)

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
									case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , accessSelection_type_component) ,0)) return; else free(); break;}
									case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (true , accessSelection_type_index) ,1)) return; else free(); break;}
									case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (true , accessSelection_type_indexRange) ,2)) return; else free(); break;}
									case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , accessSelection_type_allElements) ,3)) return; else free(); break;}
								default:{}}
								;}
							default:{
										;}}}
					else {
						 switch(type()){
							case accessSelection_type_component: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , accessSelection_type_component) ,0); break;}
							case accessSelection_type_index: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (false , accessSelection_type_index) ,1); break;}
							case accessSelection_type_indexRange: {BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (false , accessSelection_type_indexRange) ,2); break;}
							case accessSelection_type_allElements: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , accessSelection_type_allElements) ,3); break;}
							default:{}}}
				}
			};


			boost::asn1::value_holder<accessSelection_type >  accessSelection;
			boost::shared_ptr<AlternateAccess > alternateAccess;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess ,  alternateAccess)

 
			selectAlternateAccess_type()  : accessSelection() , alternateAccess()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE(accessSelection);
				BOOST_ASN_BIND_TAG(alternateAccess);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum selectAccess_type_enum {
			selectAccess_type_null = 0  , 
			selectAccess_type_component , 
			selectAccess_type_index , 
			selectAccess_type_indexRange , 
			selectAccess_type_allElements , 
		};

	struct  selectAccess_type : public BOOST_ASN_CHOICE_STRUCT(selectAccess_type_enum) {


		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  indexRange_type{

				boost::asn1::value_holder<Unsigned32 >  lowIndex;
				boost::asn1::value_holder<Unsigned32 >  numberOfElements;

				indexRange_type()  : lowIndex() , numberOfElements()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(lowIndex ,0);
					BOOST_ASN_IMPLICIT_TAG(numberOfElements ,1);
				}
			};

		//end==============================================================


			selectAccess_type() : BOOST_ASN_CHOICE_STRUCT(selectAccess_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(component, Identifier,  selectAccess_type_component)
			BOOST_ASN_VALUE_CHOICE(index, Unsigned32,  selectAccess_type_index)
			BOOST_ASN_VALUE_CHOICE(indexRange, indexRange_type,  selectAccess_type_indexRange)
			BOOST_ASN_VALUE_CHOICE(allElements, null_type,  selectAccess_type_allElements)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , selectAccess_type_component) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (true , selectAccess_type_index) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (true , selectAccess_type_indexRange) ,3)) return; else free(); break;}
								case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , selectAccess_type_allElements) ,4)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case selectAccess_type_component: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , selectAccess_type_component) ,1); break;}
						case selectAccess_type_index: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (false , selectAccess_type_index) ,2); break;}
						case selectAccess_type_indexRange: {BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (false , selectAccess_type_indexRange) ,3); break;}
						case selectAccess_type_allElements: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , selectAccess_type_allElements) ,4); break;}
						default:{}}}
			}
		};


		AlternateAccessSelection() : BOOST_ASN_CHOICE_STRUCT(AlternateAccessSelection_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(selectAlternateAccess, selectAlternateAccess_type,  AlternateAccessSelection_selectAlternateAccess)
		BOOST_ASN_VALUE_CHOICE(selectAccess, selectAccess_type,  AlternateAccessSelection_selectAccess)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<selectAlternateAccess_type > (true , AlternateAccessSelection_selectAlternateAccess) ,0)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_CHOICE(value<selectAccess_type > (true , AlternateAccessSelection_selectAccess))) return; else free();
					;}}}
			else {
				 switch(type()){
					case AlternateAccessSelection_selectAlternateAccess: {BOOST_ASN_IMPLICIT_TAG(value<selectAlternateAccess_type > (false , AlternateAccessSelection_selectAlternateAccess) ,0); break;}
					case AlternateAccessSelection_selectAccess: {BOOST_ASN_CHOICE(value<selectAccess_type > (false , AlternateAccessSelection_selectAccess)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum TypeSpecification_enum {
		TypeSpecification_null = 0  , 
		TypeSpecification_typeName , 
		TypeSpecification_typeDescription , 
	};

	struct  TypeSpecification : public BOOST_ASN_CHOICE_STRUCT(TypeSpecification_enum) {


		TypeSpecification() : BOOST_ASN_CHOICE_STRUCT(TypeSpecification_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(typeName, ObjectName,  TypeSpecification_typeName)
		BOOST_ASN_VALUE_CHOICE(typeDescription, TypeDescription,  TypeSpecification_typeDescription)

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
							case 0: { if(BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , TypeSpecification_typeName) ,0)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_CHOICE(value<TypeDescription > (true , TypeSpecification_typeDescription))) return; else free();
					;}}}
			else {
				 switch(type()){
					case TypeSpecification_typeName: {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , TypeSpecification_typeName) ,0); break;}
					case TypeSpecification_typeDescription: {BOOST_ASN_CHOICE(value<TypeDescription > (false , TypeSpecification_typeDescription)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum DeleteUnitControl_Error_enum {
		DeleteUnitControl_Error_null = 0  , 
		DeleteUnitControl_Error_domain , 
		DeleteUnitControl_Error_programInvocation , 
	};

	struct  DeleteUnitControl_Error : public BOOST_ASN_CHOICE_STRUCT(DeleteUnitControl_Error_enum) {


		DeleteUnitControl_Error() : BOOST_ASN_CHOICE_STRUCT(DeleteUnitControl_Error_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(domain, Identifier,  DeleteUnitControl_Error_domain)
		BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier,  DeleteUnitControl_Error_programInvocation)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteUnitControl_Error_domain) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteUnitControl_Error_programInvocation) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case DeleteUnitControl_Error_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteUnitControl_Error_domain) ,0); break;}
					case DeleteUnitControl_Error_programInvocation: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteUnitControl_Error_programInvocation) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  StoreUnitControlToFile_Request{

		boost::asn1::value_holder<Identifier >  unitControlName;
		boost::asn1::value_holder<FileName >  fileName;
		boost::shared_ptr<ApplicationReference > thirdParty;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  thirdParty)

 
		StoreUnitControlToFile_Request()  : unitControlName() , fileName() , thirdParty()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControlName ,0);
			BOOST_ASN_IMPLICIT_TAG(fileName ,1);
			BOOST_ASN_IMPLICIT_TAG(thirdParty ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum LoadUnitControlFromFile_Error_enum {
		LoadUnitControlFromFile_Error_null = 0  , 
		LoadUnitControlFromFile_Error_none , 
		LoadUnitControlFromFile_Error_domain , 
		LoadUnitControlFromFile_Error_programInvocation , 
	};

	struct  LoadUnitControlFromFile_Error : public BOOST_ASN_CHOICE_STRUCT(LoadUnitControlFromFile_Error_enum) {



		LoadUnitControlFromFile_Error() : BOOST_ASN_CHOICE_STRUCT(LoadUnitControlFromFile_Error_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(none, null_type,  LoadUnitControlFromFile_Error_none)
		BOOST_ASN_VALUE_CHOICE(domain, Identifier,  LoadUnitControlFromFile_Error_domain)
		BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier,  LoadUnitControlFromFile_Error_programInvocation)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , LoadUnitControlFromFile_Error_none) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , LoadUnitControlFromFile_Error_domain) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , LoadUnitControlFromFile_Error_programInvocation) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case LoadUnitControlFromFile_Error_none: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , LoadUnitControlFromFile_Error_none) ,0); break;}
					case LoadUnitControlFromFile_Error_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , LoadUnitControlFromFile_Error_domain) ,1); break;}
					case LoadUnitControlFromFile_Error_programInvocation: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , LoadUnitControlFromFile_Error_programInvocation) ,2); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  LoadUnitControlFromFile_Request{

		boost::asn1::value_holder<Identifier >  unitControlName;
		boost::asn1::value_holder<FileName >  fileName;
		boost::shared_ptr<ApplicationReference > thirdParty;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  thirdParty)

 
		LoadUnitControlFromFile_Request()  : unitControlName() , fileName() , thirdParty()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControlName ,0);
			BOOST_ASN_IMPLICIT_TAG(fileName ,1);
			BOOST_ASN_IMPLICIT_TAG(thirdParty ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetUnitControlAttributes_Response{
		//   SEQUENCE_OF is domains 
		typedef std::vector<Identifier >   domains_type;

		//   SEQUENCE_OF is programInvocations 
		typedef std::vector<Identifier >   programInvocations_type;


		boost::asn1::value_holder<domains_type >  domains;
		boost::asn1::value_holder<programInvocations_type >  programInvocations;

		GetUnitControlAttributes_Response()  : domains() , programInvocations()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domains ,0);
			BOOST_ASN_IMPLICIT_TAG(programInvocations ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RemoveFromUnitControl_Request{
		//   SEQUENCE_OF is domains 
		typedef std::vector<Identifier >   domains_type;

		//   SEQUENCE_OF is programInvocations 
		typedef std::vector<Identifier >   programInvocations_type;


		boost::asn1::value_holder<Identifier >  unitControl;
		boost::asn1::value_holder<domains_type >  domains;
		boost::asn1::value_holder<programInvocations_type >  programInvocations;

		RemoveFromUnitControl_Request()  : unitControl() , domains() , programInvocations()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControl ,0);
			BOOST_ASN_IMPLICIT_TAG(domains ,1);
			BOOST_ASN_IMPLICIT_TAG(programInvocations ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AddToUnitControl_Request{
		//   SEQUENCE_OF is domains 
		typedef std::vector<Identifier >   domains_type;

		//   SEQUENCE_OF is programInvocations 
		typedef std::vector<Identifier >   programInvocations_type;


		boost::asn1::value_holder<Identifier >  unitControl;
		boost::asn1::value_holder<domains_type >  domains;
		boost::asn1::value_holder<programInvocations_type >  programInvocations;

		AddToUnitControl_Request()  : unitControl() , domains() , programInvocations()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControl ,0);
			BOOST_ASN_IMPLICIT_TAG(domains ,1);
			BOOST_ASN_IMPLICIT_TAG(programInvocations ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  CreateUnitControl_Request{
		//   SEQUENCE_OF is domains 
		typedef std::vector<Identifier >   domains_type;

		//   SEQUENCE_OF is programInvocations 
		typedef std::vector<Identifier >   programInvocations_type;


		boost::asn1::value_holder<Identifier >  unitControl;
		boost::asn1::value_holder<domains_type >  domains;
		boost::asn1::value_holder<programInvocations_type >  programInvocations;

		CreateUnitControl_Request()  : unitControl() , domains() , programInvocations()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControl ,0);
			BOOST_ASN_IMPLICIT_TAG(domains ,1);
			BOOST_ASN_IMPLICIT_TAG(programInvocations ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  StopUnitControl_Error{

		boost::asn1::value_holder<Identifier >  programInvocationName;
		boost::asn1::value_holder<ProgramInvocationState >  programInvocationState;

		StopUnitControl_Error()  : programInvocationName() , programInvocationState()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
			BOOST_ASN_IMPLICIT_TAG(programInvocationState ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  StartUnitControl_Error{

		boost::asn1::value_holder<Identifier >  programInvocationName;
		boost::asn1::value_holder<ProgramInvocationState >  programInvocationState;

		StartUnitControl_Error()  : programInvocationName() , programInvocationState()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
			BOOST_ASN_IMPLICIT_TAG(programInvocationState ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  StartUnitControl_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum executionArgument_type_enum {
			executionArgument_type_null = 0  , 
			executionArgument_type_simpleString , 
			executionArgument_type_encodedString , 
			executionArgument_type_enmbeddedString , 
		};

	struct  executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {




			executionArgument_type() : BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(simpleString, MMSString,  executionArgument_type_simpleString)
			BOOST_ASN_VALUE_CHOICE(encodedString, external_type,  executionArgument_type_encodedString)
			BOOST_ASN_VALUE_CHOICE(enmbeddedString, embeded_type,  executionArgument_type_enmbeddedString)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								 if(BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
						 if(BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_enmbeddedString))) return; else free();
						;}}}
				else {
					 switch(type()){
						case executionArgument_type_simpleString: {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString) ,1); break;}
						case executionArgument_type_encodedString: {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break;}
						case executionArgument_type_enmbeddedString: {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_enmbeddedString)); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  unitControlName;
		boost::asn1::value_holder<executionArgument_type >  executionArgument;

		StartUnitControl_Request()  : unitControlName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControlName ,0);
			BOOST_ASN_CHOICE(executionArgument);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  UnitControlUpload_Response{
		//   SEQUENCE_OF is controlElements 
		typedef std::vector<ControlElement >   controlElements_type;


	//start==============================================================
	//It is  INTERNAL CHOICE

			enum nextElement_type_enum {
			nextElement_type_null = 0  , 
			nextElement_type_domain , 
			nextElement_type_ulsmID , 
			nextElement_type_programInvocation , 
		};

	struct  nextElement_type : public BOOST_ASN_CHOICE_STRUCT(nextElement_type_enum) {



			nextElement_type() : BOOST_ASN_CHOICE_STRUCT(nextElement_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(domain, Identifier,  nextElement_type_domain)
			BOOST_ASN_VALUE_CHOICE(ulsmID, int,  nextElement_type_ulsmID)
			BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier,  nextElement_type_programInvocation)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , nextElement_type_domain) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , nextElement_type_ulsmID) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , nextElement_type_programInvocation) ,3)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case nextElement_type_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , nextElement_type_domain) ,1); break;}
						case nextElement_type_ulsmID: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , nextElement_type_ulsmID) ,2); break;}
						case nextElement_type_programInvocation: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , nextElement_type_programInvocation) ,3); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<controlElements_type >  controlElements;
		boost::asn1::value_holder<nextElement_type >  nextElement;

		UnitControlUpload_Response()  : controlElements()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(controlElements ,0);
			BOOST_ASN_CHOICE(nextElement);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  UnitControlUpload_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum continueAfter_type_enum {
			continueAfter_type_null = 0  , 
			continueAfter_type_domain , 
			continueAfter_type_ulsmID , 
			continueAfter_type_programInvocation , 
		};

	struct  continueAfter_type : public BOOST_ASN_CHOICE_STRUCT(continueAfter_type_enum) {



			continueAfter_type() : BOOST_ASN_CHOICE_STRUCT(continueAfter_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(domain, Identifier,  continueAfter_type_domain)
			BOOST_ASN_VALUE_CHOICE(ulsmID, int,  continueAfter_type_ulsmID)
			BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier,  continueAfter_type_programInvocation)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , continueAfter_type_domain) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , continueAfter_type_ulsmID) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , continueAfter_type_programInvocation) ,3)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case continueAfter_type_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , continueAfter_type_domain) ,1); break;}
						case continueAfter_type_ulsmID: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , continueAfter_type_ulsmID) ,2); break;}
						case continueAfter_type_programInvocation: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , continueAfter_type_programInvocation) ,3); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  unitControlName;
		boost::asn1::value_holder<continueAfter_type >  continueAfter;

		UnitControlUpload_Request()  : unitControlName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(unitControlName ,0);
			BOOST_ASN_CHOICE(continueAfter);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  UnitControlLoadSegment_Response{
		//   SEQUENCE_OF is controlElements 
		typedef std::vector<ControlElement >   controlElements_type;



		boost::asn1::value_holder<controlElements_type >  controlElements;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		UnitControlLoadSegment_Response()  : controlElements()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(controlElements ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum InitiateUnitControl_Error_enum {
		InitiateUnitControl_Error_null = 0  , 
		InitiateUnitControl_Error_domain , 
		InitiateUnitControl_Error_programInvocation , 
	};

	struct  InitiateUnitControl_Error : public BOOST_ASN_CHOICE_STRUCT(InitiateUnitControl_Error_enum) {


		InitiateUnitControl_Error() : BOOST_ASN_CHOICE_STRUCT(InitiateUnitControl_Error_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(domain, Identifier,  InitiateUnitControl_Error_domain)
		BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier,  InitiateUnitControl_Error_programInvocation)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , InitiateUnitControl_Error_domain) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , InitiateUnitControl_Error_programInvocation) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case InitiateUnitControl_Error_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , InitiateUnitControl_Error_domain) ,0); break;}
					case InitiateUnitControl_Error_programInvocation: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , InitiateUnitControl_Error_programInvocation) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum ControlElement_enum {
		ControlElement_null = 0  , 
		ControlElement_beginDomainDef , 
		ControlElement_continueDomainDef , 
		ControlElement_endDomainDef , 
		ControlElement_piDefinition , 
	};

	struct  ControlElement : public BOOST_ASN_CHOICE_STRUCT(ControlElement_enum) {


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  beginDomainDef_type{
			//   SEQUENCE_OF is capabilities 
			typedef std::vector<MMSString >   capabilities_type;



			boost::asn1::value_holder<Identifier >  domainName;
			boost::asn1::value_holder<capabilities_type >  capabilities;
			boost::asn1::value_holder<bool >  sharable;
			boost::asn1::value_holder<LoadData >  loadData;

			beginDomainDef_type()  : domainName() , capabilities() , sharable() , loadData()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(domainName ,1);
				BOOST_ASN_IMPLICIT_TAG(capabilities ,2);
				BOOST_ASN_IMPLICIT_TAG(sharable ,3);
				BOOST_ASN_CHOICE_TAG(loadData ,4);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  continueDomainDef_type{

			boost::asn1::value_holder<Identifier >  domainName;
			boost::asn1::value_holder<LoadData >  loadData;

			continueDomainDef_type()  : domainName() , loadData()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(domainName ,1);
				BOOST_ASN_CHOICE_TAG(loadData ,3);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  piDefinition_type{
			//   SEQUENCE_OF is listOfDomains 
			typedef std::vector<Identifier >   listOfDomains_type;




			boost::asn1::value_holder<Identifier >  piName;
			boost::asn1::value_holder<listOfDomains_type >  listOfDomains;
			boost::shared_ptr<bool > reusable;   //  DEFAULT   
 			BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  reusable)

 			boost::shared_ptr<bool > monitorType;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  monitorType)

 			boost::shared_ptr<ProgramInvocationState > pIState;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(ProgramInvocationState ,  pIState)

 
			piDefinition_type()  : piName() , listOfDomains()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(piName ,0);
				BOOST_ASN_IMPLICIT_TAG(listOfDomains ,1);
				BOOST_ASN_IMPLICIT_TAG(reusable ,2);
				BOOST_ASN_IMPLICIT_TAG(monitorType ,3);
				BOOST_ASN_IMPLICIT_TAG(pIState ,4);
			}
		};

	//end==============================================================

		ControlElement() : BOOST_ASN_CHOICE_STRUCT(ControlElement_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(beginDomainDef, beginDomainDef_type,  ControlElement_beginDomainDef)
		BOOST_ASN_VALUE_CHOICE(continueDomainDef, continueDomainDef_type,  ControlElement_continueDomainDef)
		BOOST_ASN_VALUE_CHOICE(endDomainDef, Identifier,  ControlElement_endDomainDef)
		BOOST_ASN_VALUE_CHOICE(piDefinition, piDefinition_type,  ControlElement_piDefinition)

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
							case 0: { if(BOOST_ASN_EXPLICIT_TAG(value<beginDomainDef_type > (true , ControlElement_beginDomainDef) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_EXPLICIT_TAG(value<continueDomainDef_type > (true , ControlElement_continueDomainDef) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , ControlElement_endDomainDef) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<piDefinition_type > (true , ControlElement_piDefinition) ,3)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case ControlElement_beginDomainDef: {BOOST_ASN_EXPLICIT_TAG(value<beginDomainDef_type > (false , ControlElement_beginDomainDef) ,0); break;}
					case ControlElement_continueDomainDef: {BOOST_ASN_EXPLICIT_TAG(value<continueDomainDef_type > (false , ControlElement_continueDomainDef) ,1); break;}
					case ControlElement_endDomainDef: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , ControlElement_endDomainDef) ,2); break;}
					case ControlElement_piDefinition: {BOOST_ASN_IMPLICIT_TAG(value<piDefinition_type > (false , ControlElement_piDefinition) ,3); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  ReconfigureProgramInvocation_Request{
		//   SEQUENCE_OF is domainsToAdd 
		typedef std::vector<Identifier >   domainsToAdd_type;

		//   SEQUENCE_OF is domainsToRemove 
		typedef std::vector<Identifier >   domainsToRemove_type;


		boost::asn1::value_holder<Identifier >  oldProgramInvocationName;
		boost::shared_ptr<Identifier > newProgramInvocationName;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  newProgramInvocationName)

 		boost::asn1::value_holder<domainsToAdd_type >  domainsToAdd;
		boost::asn1::value_holder<domainsToRemove_type >  domainsToRemove;

		ReconfigureProgramInvocation_Request()  : oldProgramInvocationName() , domainsToAdd() , domainsToRemove()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(oldProgramInvocationName ,0);
			BOOST_ASN_IMPLICIT_TAG(newProgramInvocationName ,1);
			BOOST_ASN_IMPLICIT_TAG(domainsToAdd ,2);
			BOOST_ASN_IMPLICIT_TAG(domainsToRemove ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  AlterProgramInvocationAttributes_Request{

		boost::asn1::value_holder<Identifier >  programInvocation;
		boost::asn1::value_holder<StartCount >  startCount;

		AlterProgramInvocationAttributes_Request()  : programInvocation() , startCount()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocation ,0);
			BOOST_ASN_CHOICE_TAG(startCount ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Select_Request{
		//   SEQUENCE_OF is controlled 
		typedef std::vector<Identifier >   controlled_type;


		boost::shared_ptr<Identifier > controlling;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  controlling)

 		boost::shared_ptr<controlled_type > controlled;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(controlled_type ,  controlled)

 
		Select_Request()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(controlling ,0);
			BOOST_ASN_IMPLICIT_TAG(controlled ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  CS_GetProgramInvocationAttributes_Response{


	//start==============================================================
	//It is  INTERNAL CHOICE

			enum control_type_enum {
			control_type_null = 0  , 
			control_type_controlling , 
			control_type_controlled , 
			control_type_normal , 
		};

	struct  control_type : public BOOST_ASN_CHOICE_STRUCT(control_type_enum) {


		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  controlling_type{
				//   SEQUENCE_OF is controlledPI 
				typedef std::vector<Identifier >   controlledPI_type;



			//start==============================================================
			//It is  INTERNAL CHOICE

							enum runningMode_type_enum {
					runningMode_type_null = 0  , 
					runningMode_type_freeRunning , 
					runningMode_type_cycleLimited , 
					runningMode_type_stepLimited , 
				};

	struct  runningMode_type : public BOOST_ASN_CHOICE_STRUCT(runningMode_type_enum) {





					runningMode_type() : BOOST_ASN_CHOICE_STRUCT(runningMode_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(freeRunning, null_type,  runningMode_type_freeRunning)
					BOOST_ASN_VALUE_CHOICE(cycleLimited, int,  runningMode_type_cycleLimited)
					BOOST_ASN_VALUE_CHOICE(stepLimited, int,  runningMode_type_stepLimited)

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
										case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , runningMode_type_freeRunning) ,0)) return; else free(); break;}
										case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , runningMode_type_cycleLimited) ,1)) return; else free(); break;}
										case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , runningMode_type_stepLimited) ,2)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case runningMode_type_freeRunning: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , runningMode_type_freeRunning) ,0); break;}
								case runningMode_type_cycleLimited: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , runningMode_type_cycleLimited) ,1); break;}
								case runningMode_type_stepLimited: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , runningMode_type_stepLimited) ,2); break;}
								default:{}}}
					}
				};


				boost::asn1::value_holder<controlledPI_type >  controlledPI;
				boost::shared_ptr<visiblestring_type > programLocation;   //  OPTIONAL
				BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  programLocation)

 				boost::asn1::value_holder<runningMode_type >  runningMode;

				controlling_type()  : controlledPI() , runningMode()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_IMPLICIT_TAG(controlledPI ,0);
					BOOST_ASN_IMPLICIT_TAG(programLocation ,1);
					BOOST_ASN_CHOICE_TAG(runningMode ,2);
				}
			};

		//end==============================================================

		//start==============================================================
		//It is  INTERNAL CHOICE

					enum controlled_type_enum {
				controlled_type_null = 0  , 
				controlled_type_controllingPI , 
				controlled_type_none , 
			};

	struct  controlled_type : public BOOST_ASN_CHOICE_STRUCT(controlled_type_enum) {



				controlled_type() : BOOST_ASN_CHOICE_STRUCT(controlled_type_enum) ()  {}


				BOOST_ASN_VALUE_CHOICE(controllingPI, Identifier,  controlled_type_controllingPI)
				BOOST_ASN_VALUE_CHOICE(none, null_type,  controlled_type_none)

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
									case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , controlled_type_controllingPI) ,0)) return; else free(); break;}
									case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , controlled_type_none) ,1)) return; else free(); break;}
								default:{}}
								;}
							default:{
										;}}}
					else {
						 switch(type()){
							case controlled_type_controllingPI: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , controlled_type_controllingPI) ,0); break;}
							case controlled_type_none: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , controlled_type_none) ,1); break;}
							default:{}}}
				}
			};



			control_type() : BOOST_ASN_CHOICE_STRUCT(control_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(controlling, controlling_type,  control_type_controlling)
			BOOST_ASN_VALUE_CHOICE(controlled, controlled_type,  control_type_controlled)
			BOOST_ASN_VALUE_CHOICE(normal, null_type,  control_type_normal)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<controlling_type > (true , control_type_controlling) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_CHOICE_TAG(value<controlled_type > (true , control_type_controlled) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , control_type_normal) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case control_type_controlling: {BOOST_ASN_IMPLICIT_TAG(value<controlling_type > (false , control_type_controlling) ,0); break;}
						case control_type_controlled: {BOOST_ASN_CHOICE_TAG(value<controlled_type > (false , control_type_controlled) ,1); break;}
						case control_type_normal: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , control_type_normal) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<int >  errorCode;
		boost::asn1::value_holder<control_type >  control;

		CS_GetProgramInvocationAttributes_Response()  : errorCode() , control()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(errorCode ,0);
			BOOST_ASN_CHOICE_TAG(control ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetProgramInvocationAttributes_Response{
		//   SEQUENCE_OF is listOfDomainNames 
		typedef std::vector<Identifier >   listOfDomainNames_type;





	//start==============================================================
	//It is  INTERNAL CHOICE

			enum executionArgument_type_enum {
			executionArgument_type_null = 0  , 
			executionArgument_type_simpleString , 
			executionArgument_type_encodedString , 
			executionArgument_type_enmbeddedString , 
		};

	struct  executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {




			executionArgument_type() : BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(simpleString, MMSString,  executionArgument_type_simpleString)
			BOOST_ASN_VALUE_CHOICE(encodedString, external_type,  executionArgument_type_encodedString)
			BOOST_ASN_VALUE_CHOICE(enmbeddedString, embeded_type,  executionArgument_type_enmbeddedString)

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
								case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString) ,5)) return; else free(); break;}
							default:{}}
							;}
						default:{
								 if(BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
						 if(BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_enmbeddedString))) return; else free();
						;}}}
				else {
					 switch(type()){
						case executionArgument_type_simpleString: {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString) ,5); break;}
						case executionArgument_type_encodedString: {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break;}
						case executionArgument_type_enmbeddedString: {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_enmbeddedString)); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ProgramInvocationState >  state;
		boost::asn1::value_holder<listOfDomainNames_type >  listOfDomainNames;
		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::asn1::value_holder<bool >  reusable;
		boost::asn1::value_holder<bool >  monitor;
		boost::asn1::value_holder<executionArgument_type >  executionArgument;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetProgramInvocationAttributes_Response()  : state() , listOfDomainNames() , mmsDeletable() , reusable() , monitor() , executionArgument()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(state ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfDomainNames ,1);
			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,2);
			BOOST_ASN_IMPLICIT_TAG(reusable ,3);
			BOOST_ASN_IMPLICIT_TAG(monitor ,4);
			BOOST_ASN_CHOICE(executionArgument);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,6);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Kill_Request{

		boost::asn1::value_holder<Identifier >  programInvocationName;

		Kill_Request()  : programInvocationName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Reset_Request{

		boost::asn1::value_holder<Identifier >  programInvocationName;

		Reset_Request()  : programInvocationName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum CS_Resume_Request__impl_enum {
		CS_Resume_Request__impl_null = 0  , 
		CS_Resume_Request__impl_normal , 
		CS_Resume_Request__impl_controlling , 
	};

	struct  CS_Resume_Request__impl : public BOOST_ASN_CHOICE_STRUCT(CS_Resume_Request__impl_enum) {



	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  controlling_type{

		//start==============================================================
		//It is  INTERNAL CHOICE

					enum modeType_type_enum {
				modeType_type_null = 0  , 
				modeType_type_continueMode , 
				modeType_type_changeMode , 
			};

	struct  modeType_type : public BOOST_ASN_CHOICE_STRUCT(modeType_type_enum) {



				modeType_type() : BOOST_ASN_CHOICE_STRUCT(modeType_type_enum) ()  {}


				BOOST_ASN_VALUE_CHOICE(continueMode, null_type,  modeType_type_continueMode)
				BOOST_ASN_VALUE_CHOICE(changeMode, StartCount,  modeType_type_changeMode)

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
									case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , modeType_type_continueMode) ,0)) return; else free(); break;}
									case 1: { if(BOOST_ASN_CHOICE_TAG(value<StartCount > (true , modeType_type_changeMode) ,1)) return; else free(); break;}
								default:{}}
								;}
							default:{
										;}}}
					else {
						 switch(type()){
							case modeType_type_continueMode: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , modeType_type_continueMode) ,0); break;}
							case modeType_type_changeMode: {BOOST_ASN_CHOICE_TAG(value<StartCount > (false , modeType_type_changeMode) ,1); break;}
							default:{}}}
				}
			};


			boost::asn1::value_holder<modeType_type >  modeType;

			controlling_type()  : modeType()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE(modeType);
			}
		};

	//end==============================================================

		CS_Resume_Request__impl() : BOOST_ASN_CHOICE_STRUCT(CS_Resume_Request__impl_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(normal, null_type,  CS_Resume_Request__impl_normal)
		BOOST_ASN_VALUE_CHOICE(controlling, controlling_type,  CS_Resume_Request__impl_controlling)

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
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , CS_Resume_Request__impl_normal))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<controlling_type > (true , CS_Resume_Request__impl_controlling))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CS_Resume_Request__impl_normal: {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_Resume_Request__impl_normal)); break;}
					case CS_Resume_Request__impl_controlling: {BOOST_ASN_BIND_TAG(value<controlling_type > (false , CS_Resume_Request__impl_controlling)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  Resume_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum executionArgument_type_enum {
			executionArgument_type_null = 0  , 
			executionArgument_type_simpleString , 
			executionArgument_type_encodedString , 
			executionArgument_type_enmbeddedString , 
		};

	struct  executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {




			executionArgument_type() : BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(simpleString, MMSString,  executionArgument_type_simpleString)
			BOOST_ASN_VALUE_CHOICE(encodedString, external_type,  executionArgument_type_encodedString)
			BOOST_ASN_VALUE_CHOICE(enmbeddedString, embeded_type,  executionArgument_type_enmbeddedString)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								 if(BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
						 if(BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_enmbeddedString))) return; else free();
						;}}}
				else {
					 switch(type()){
						case executionArgument_type_simpleString: {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString) ,1); break;}
						case executionArgument_type_encodedString: {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break;}
						case executionArgument_type_enmbeddedString: {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_enmbeddedString)); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  programInvocationName;
		boost::asn1::value_holder<executionArgument_type >  executionArgument;

		Resume_Request()  : programInvocationName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
			BOOST_ASN_CHOICE(executionArgument);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Stop_Request{

		boost::asn1::value_holder<Identifier >  programInvocationName;

		Stop_Request()  : programInvocationName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum StartCount_enum {
		StartCount_null = 0  , 
		StartCount_noLimit , 
		StartCount_cycleCount , 
		StartCount_stepCount , 
	};

	struct  StartCount : public BOOST_ASN_CHOICE_STRUCT(StartCount_enum) {





		StartCount() : BOOST_ASN_CHOICE_STRUCT(StartCount_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(noLimit, null_type,  StartCount_noLimit)
		BOOST_ASN_VALUE_CHOICE(cycleCount, int,  StartCount_cycleCount)
		BOOST_ASN_VALUE_CHOICE(stepCount, int,  StartCount_stepCount)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , StartCount_noLimit) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , StartCount_cycleCount) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , StartCount_stepCount) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case StartCount_noLimit: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , StartCount_noLimit) ,0); break;}
					case StartCount_cycleCount: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , StartCount_cycleCount) ,1); break;}
					case StartCount_stepCount: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , StartCount_stepCount) ,2); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum CS_Start_Request__impl_enum {
		CS_Start_Request__impl_null = 0  , 
		CS_Start_Request__impl_normal , 
		CS_Start_Request__impl_controlling , 
	};

	struct  CS_Start_Request__impl : public BOOST_ASN_CHOICE_STRUCT(CS_Start_Request__impl_enum) {



	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  controlling_type{


			boost::shared_ptr<visiblestring_type > startLocation;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  startLocation)

 			boost::asn1::value_holder<StartCount >  startCount;

			controlling_type()  : startCount()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(startLocation ,0);
				BOOST_ASN_CHOICE_TAG(startCount ,1);
			}
		};

	//end==============================================================

		CS_Start_Request__impl() : BOOST_ASN_CHOICE_STRUCT(CS_Start_Request__impl_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(normal, null_type,  CS_Start_Request__impl_normal)
		BOOST_ASN_VALUE_CHOICE(controlling, controlling_type,  CS_Start_Request__impl_controlling)

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
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , CS_Start_Request__impl_normal))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<controlling_type > (true , CS_Start_Request__impl_controlling))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CS_Start_Request__impl_normal: {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_Start_Request__impl_normal)); break;}
					case CS_Start_Request__impl_controlling: {BOOST_ASN_BIND_TAG(value<controlling_type > (false , CS_Start_Request__impl_controlling)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  Start_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum executionArgument_type_enum {
			executionArgument_type_null = 0  , 
			executionArgument_type_simpleString , 
			executionArgument_type_encodedString , 
			executionArgument_type_embeddedString , 
		};

	struct  executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {




			executionArgument_type() : BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(simpleString, MMSString,  executionArgument_type_simpleString)
			BOOST_ASN_VALUE_CHOICE(encodedString, external_type,  executionArgument_type_encodedString)
			BOOST_ASN_VALUE_CHOICE(embeddedString, embeded_type,  executionArgument_type_embeddedString)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								 if(BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
						 if(BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_embeddedString))) return; else free();
						;}}}
				else {
					 switch(type()){
						case executionArgument_type_simpleString: {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString) ,1); break;}
						case executionArgument_type_encodedString: {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break;}
						case executionArgument_type_embeddedString: {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_embeddedString)); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<Identifier >  programInvocationName;
		boost::asn1::value_holder<executionArgument_type >  executionArgument;

		Start_Request()  : programInvocationName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
			BOOST_ASN_CHOICE(executionArgument);
		}
	};

//end==============================================================

	const int CS_CreateProgramInvocation_Request_normal = 0;
	const int CS_CreateProgramInvocation_Request_controlling = 1;
	const int CS_CreateProgramInvocation_Request_controlled = 2;

//start==============================================================
//It is   SEQUENCE  

	struct  CreateProgramInvocation_Request{
		//   SEQUENCE_OF is listOfDomainNames 
		typedef std::vector<Identifier >   listOfDomainNames_type;




		boost::asn1::value_holder<Identifier >  programInvocationName;
		boost::asn1::value_holder<listOfDomainNames_type >  listOfDomainNames;
		boost::shared_ptr<bool > reusable;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  reusable)

 		boost::shared_ptr<bool > monitorType;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  monitorType)

 
		CreateProgramInvocation_Request()  : programInvocationName() , listOfDomainNames()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(programInvocationName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfDomainNames ,1);
			BOOST_ASN_IMPLICIT_TAG(reusable ,2);
			BOOST_ASN_IMPLICIT_TAG(monitorType ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetDomainAttributes_Response{
		//   SEQUENCE_OF is listOfCapabilities 
		typedef std::vector<MMSString >   listOfCapabilities_type;



		//   SEQUENCE_OF is listOfProgramInvocations 
		typedef std::vector<Identifier >   listOfProgramInvocations_type;


		boost::asn1::value_holder<listOfCapabilities_type >  listOfCapabilities;
		boost::asn1::value_holder<DomainState >  state;
		boost::asn1::value_holder<bool >  mmsDeletable;
		boost::asn1::value_holder<bool >  sharable;
		boost::asn1::value_holder<listOfProgramInvocations_type >  listOfProgramInvocations;
		boost::asn1::value_holder<Integer8 >  uploadInProgress;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetDomainAttributes_Response()  : listOfCapabilities() , state() , mmsDeletable() , sharable() , listOfProgramInvocations() , uploadInProgress()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfCapabilities ,0);
			BOOST_ASN_IMPLICIT_TAG(state ,1);
			BOOST_ASN_IMPLICIT_TAG(mmsDeletable ,2);
			BOOST_ASN_IMPLICIT_TAG(sharable ,3);
			BOOST_ASN_IMPLICIT_TAG(listOfProgramInvocations ,4);
			BOOST_ASN_IMPLICIT_TAG(uploadInProgress ,5);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,6);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  StoreDomainContent_Request{

		boost::asn1::value_holder<Identifier >  domainName;
		boost::asn1::value_holder<FileName >  fileName;
		boost::shared_ptr<ApplicationReference > thirdParty;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  thirdParty)

 
		StoreDomainContent_Request()  : domainName() , fileName() , thirdParty()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domainName ,0);
			BOOST_ASN_IMPLICIT_TAG(fileName ,1);
			BOOST_ASN_IMPLICIT_TAG(thirdParty ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  LoadDomainContent_Request{
		//   SEQUENCE_OF is listOfCapabilities 
		typedef std::vector<MMSString >   listOfCapabilities_type;



		boost::asn1::value_holder<Identifier >  domainName;
		boost::shared_ptr<listOfCapabilities_type > listOfCapabilities;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfCapabilities_type ,  listOfCapabilities)

 		boost::asn1::value_holder<bool >  sharable;
		boost::asn1::value_holder<FileName >  fileName;
		boost::shared_ptr<ApplicationReference > thirdParty;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ApplicationReference ,  thirdParty)

 
		LoadDomainContent_Request()  : domainName() , sharable() , fileName() , thirdParty()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domainName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfCapabilities ,1);
			BOOST_ASN_IMPLICIT_TAG(sharable ,2);
			BOOST_ASN_IMPLICIT_TAG(fileName ,4);
			BOOST_ASN_IMPLICIT_TAG(thirdParty ,5);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RequestDomainUpload_Request{

		boost::asn1::value_holder<Identifier >  domainName;
		boost::asn1::value_holder<FileName >  fileName;

		RequestDomainUpload_Request()  : domainName() , fileName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domainName ,0);
			BOOST_ASN_IMPLICIT_TAG(fileName ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RequestDomainDownload_Request{
		//   SEQUENCE_OF is listOfCapabilities 
		typedef std::vector<MMSString >   listOfCapabilities_type;



		boost::asn1::value_holder<Identifier >  domainName;
		boost::shared_ptr<listOfCapabilities_type > listOfCapabilities;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfCapabilities_type ,  listOfCapabilities)

 		boost::asn1::value_holder<bool >  sharable;
		boost::asn1::value_holder<FileName >  fileName;

		RequestDomainDownload_Request()  : domainName() , sharable() , fileName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domainName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfCapabilities ,1);
			BOOST_ASN_IMPLICIT_TAG(sharable ,2);
			BOOST_ASN_IMPLICIT_TAG(fileName ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  UploadSegment_Response{


		boost::asn1::value_holder<LoadData >  loadData;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		UploadSegment_Response()  : loadData()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(loadData);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  InitiateUploadSequence_Response{
		//   SEQUENCE_OF is listOfCapabilities 
		typedef std::vector<MMSString >   listOfCapabilities_type;


		boost::asn1::value_holder<Integer32 >  ulsmID;
		boost::asn1::value_holder<listOfCapabilities_type >  listOfCapabilities;

		InitiateUploadSequence_Response()  : ulsmID() , listOfCapabilities()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(ulsmID ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfCapabilities ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  TerminateDownloadSequence_Request{

		boost::asn1::value_holder<Identifier >  domainName;
		boost::shared_ptr<ServiceError > discard;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(ServiceError ,  discard)

 
		TerminateDownloadSequence_Request()  : domainName() , discard()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domainName ,0);
			BOOST_ASN_IMPLICIT_TAG(discard ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum LoadData_enum {
		LoadData_null = 0  , 
		LoadData_non_coded , 
		LoadData_coded , 
		LoadData_embedded , 
	};

	struct  LoadData : public BOOST_ASN_CHOICE_STRUCT(LoadData_enum) {





		LoadData() : BOOST_ASN_CHOICE_STRUCT(LoadData_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(non_coded, octetstring_type,  LoadData_non_coded)
		BOOST_ASN_VALUE_CHOICE(coded, external_type,  LoadData_coded)
		BOOST_ASN_VALUE_CHOICE(embedded, embeded_type,  LoadData_embedded)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , LoadData_non_coded) ,0)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<external_type > (true , LoadData_coded))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<embeded_type > (true , LoadData_embedded))) return; else free();
					;}}}
			else {
				 switch(type()){
					case LoadData_non_coded: {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , LoadData_non_coded) ,0); break;}
					case LoadData_coded: {BOOST_ASN_BIND_TAG(value<external_type > (false , LoadData_coded)); break;}
					case LoadData_embedded: {BOOST_ASN_BIND_TAG(value<embeded_type > (false , LoadData_embedded)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  DownloadSegment_Response{


		boost::asn1::value_holder<LoadData >  loadData;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		DownloadSegment_Response()  : loadData()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(loadData);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  InitiateDownloadSequence_Request{
		//   SEQUENCE_OF is listOfCapabilities 
		typedef std::vector<MMSString >   listOfCapabilities_type;



		boost::asn1::value_holder<Identifier >  domainName;
		boost::asn1::value_holder<listOfCapabilities_type >  listOfCapabilities;
		boost::asn1::value_holder<bool >  sharable;

		InitiateDownloadSequence_Request()  : domainName() , listOfCapabilities() , sharable()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(domainName ,0);
			BOOST_ASN_IMPLICIT_TAG(listOfCapabilities ,1);
			BOOST_ASN_IMPLICIT_TAG(sharable ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetCapabilityList_Response{
		//   SEQUENCE_OF is listOfCapabilities 
		typedef std::vector<MMSString >   listOfCapabilities_type;



		boost::asn1::value_holder<listOfCapabilities_type >  listOfCapabilities;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		GetCapabilityList_Response()  : listOfCapabilities()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfCapabilities ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetCapabilityList_Request{

		boost::shared_ptr<MMSString > continueAfter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(MMSString ,  continueAfter)

 
		GetCapabilityList_Request()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_BIND_TAG(continueAfter);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Rename_Request{

		boost::asn1::value_holder<ObjectClass >  objectClass;
		boost::asn1::value_holder<ObjectName >  currentName;
		boost::asn1::value_holder<Identifier >  newIdentifier;

		Rename_Request()  : objectClass() , currentName() , newIdentifier()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(objectClass ,0);
			BOOST_ASN_CHOICE_TAG(currentName ,1);
			BOOST_ASN_IMPLICIT_TAG(newIdentifier ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Identify_Response{
		//   SEQUENCE_OF is listOfAbstractSyntaxes 
		typedef std::vector<oid_type >   listOfAbstractSyntaxes_type;


		boost::asn1::value_holder<MMSString >  vendorName;
		boost::asn1::value_holder<MMSString >  modelName;
		boost::asn1::value_holder<MMSString >  revision;
		boost::shared_ptr<listOfAbstractSyntaxes_type > listOfAbstractSyntaxes;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfAbstractSyntaxes_type ,  listOfAbstractSyntaxes)

 
		Identify_Response()  : vendorName() , modelName() , revision()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(vendorName ,0);
			BOOST_ASN_IMPLICIT_TAG(modelName ,1);
			BOOST_ASN_IMPLICIT_TAG(revision ,2);
			BOOST_ASN_IMPLICIT_TAG(listOfAbstractSyntaxes ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetNameList_Response{
		//   SEQUENCE_OF is listOfIdentifier 
		typedef std::vector<Identifier >   listOfIdentifier_type;



		boost::asn1::value_holder<listOfIdentifier_type >  listOfIdentifier;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		GetNameList_Response()  : listOfIdentifier()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfIdentifier ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetNameList_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum objectScope_type_enum {
			objectScope_type_null = 0  , 
			objectScope_type_vmdSpecific , 
			objectScope_type_domainSpecific , 
			objectScope_type_aaSpecific , 
		};

	struct  objectScope_type : public BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) {




			objectScope_type() : BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(vmdSpecific, null_type,  objectScope_type_vmdSpecific)
			BOOST_ASN_VALUE_CHOICE(domainSpecific, Identifier,  objectScope_type_domainSpecific)
			BOOST_ASN_VALUE_CHOICE(aaSpecific, null_type,  objectScope_type_aaSpecific)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_vmdSpecific) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , objectScope_type_domainSpecific) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_aaSpecific) ,2)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case objectScope_type_vmdSpecific: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_vmdSpecific) ,0); break;}
						case objectScope_type_domainSpecific: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , objectScope_type_domainSpecific) ,1); break;}
						case objectScope_type_aaSpecific: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_aaSpecific) ,2); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<ObjectClass >  objectClass;
		boost::asn1::value_holder<objectScope_type >  objectScope;
		boost::shared_ptr<Identifier > continueAfter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  continueAfter)

 
		GetNameList_Request()  : objectClass() , objectScope()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(objectClass ,0);
			BOOST_ASN_CHOICE_TAG(objectScope ,1);
			BOOST_ASN_IMPLICIT_TAG(continueAfter ,2);
		}
	};

//end==============================================================

	const bitstring_type ExtendedStatus_safetyInterlocksViolated= bitstring_type(true, 0);
	const bitstring_type ExtendedStatus_anyPhysicalResourcePowerOn= bitstring_type(true, 1);
	const bitstring_type ExtendedStatus_allPhysicalResourcesCalibrated= bitstring_type(true, 2);
	const bitstring_type ExtendedStatus_localControl= bitstring_type(true, 3);


	const int OperationState_idle = 0;
	const int OperationState_loaded = 1;
	const int OperationState_ready = 2;
	const int OperationState_executing = 3;
	const int OperationState_motion_paused = 4;
	const int OperationState_manualInterventionRequired = 5;

//start==============================================================
//It is   CHOICE

	enum CS_Status_Response_enum {
		CS_Status_Response_null = 0  , 
		CS_Status_Response_fullResponse , 
		CS_Status_Response_noExtraResponse , 
	};

	struct  CS_Status_Response : public BOOST_ASN_CHOICE_STRUCT(CS_Status_Response_enum) {


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  fullResponse_type{

		//start==============================================================
		//It is  INTERNAL CHOICE

					enum selectedProgramInvocation_type_enum {
				selectedProgramInvocation_type_null = 0  , 
				selectedProgramInvocation_type_programInvocation , 
				selectedProgramInvocation_type_noneSelected , 
			};

	struct  selectedProgramInvocation_type : public BOOST_ASN_CHOICE_STRUCT(selectedProgramInvocation_type_enum) {



				selectedProgramInvocation_type() : BOOST_ASN_CHOICE_STRUCT(selectedProgramInvocation_type_enum) ()  {}


				BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier,  selectedProgramInvocation_type_programInvocation)
				BOOST_ASN_VALUE_CHOICE(noneSelected, null_type,  selectedProgramInvocation_type_noneSelected)

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
									case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , selectedProgramInvocation_type_programInvocation) ,3)) return; else free(); break;}
									case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , selectedProgramInvocation_type_noneSelected) ,4)) return; else free(); break;}
								default:{}}
								;}
							default:{
										;}}}
					else {
						 switch(type()){
							case selectedProgramInvocation_type_programInvocation: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , selectedProgramInvocation_type_programInvocation) ,3); break;}
							case selectedProgramInvocation_type_noneSelected: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , selectedProgramInvocation_type_noneSelected) ,4); break;}
							default:{}}}
				}
			};


			boost::asn1::value_holder<OperationState >  operationState;
			boost::asn1::value_holder<ExtendedStatus >  extendedStatus;
			boost::shared_ptr<ExtendedStatus > extendedStatusMask;   //  DEFAULT  � 
 			BOOST_ASN_VALUE_FUNC_DECLARATE(ExtendedStatus ,  extendedStatusMask)

 			boost::asn1::value_holder<selectedProgramInvocation_type >  selectedProgramInvocation;

			fullResponse_type()  : operationState() , extendedStatus() , selectedProgramInvocation()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(operationState ,0);
				BOOST_ASN_IMPLICIT_TAG(extendedStatus ,1);
				BOOST_ASN_IMPLICIT_TAG(extendedStatusMask ,2);
				BOOST_ASN_CHOICE(selectedProgramInvocation);
			}
		};

	//end==============================================================


		CS_Status_Response() : BOOST_ASN_CHOICE_STRUCT(CS_Status_Response_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(fullResponse, fullResponse_type,  CS_Status_Response_fullResponse)
		BOOST_ASN_VALUE_CHOICE(noExtraResponse, null_type,  CS_Status_Response_noExtraResponse)

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
						 if(BOOST_ASN_BIND_TAG(value<fullResponse_type > (true , CS_Status_Response_fullResponse))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<null_type > (true , CS_Status_Response_noExtraResponse))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CS_Status_Response_fullResponse: {BOOST_ASN_BIND_TAG(value<fullResponse_type > (false , CS_Status_Response_fullResponse)); break;}
					case CS_Status_Response_noExtraResponse: {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_Status_Response_noExtraResponse)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  StatusResponse{


		static const int vmdLogicalStatus_state_changes_allowed = 0;
		static const int vmdLogicalStatus_no_state_changes_allowed = 1;
		static const int vmdLogicalStatus_limited_services_permitted = 2;
		static const int vmdLogicalStatus_support_services_allowed = 3;



		static const int vmdPhysicalStatus_operational = 0;
		static const int vmdPhysicalStatus_partially_operational = 1;
		static const int vmdPhysicalStatus_inoperable = 2;
		static const int vmdPhysicalStatus_needs_commissioning = 3;



		boost::asn1::value_holder<int >  vmdLogicalStatus;
		boost::asn1::value_holder<int >  vmdPhysicalStatus;
		boost::shared_ptr<bitstring_type > localDetail;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type ,  localDetail)

 
		StatusResponse()  : vmdLogicalStatus() , vmdPhysicalStatus()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(vmdLogicalStatus ,0);
			BOOST_ASN_IMPLICIT_TAG(vmdPhysicalStatus ,1);
			BOOST_ASN_IMPLICIT_TAG(localDetail ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ChangeAccessControl_Response{

		boost::asn1::value_holder<Unsigned32 >  numberMatched;
		boost::asn1::value_holder<Unsigned32 >  numberChanged;

		ChangeAccessControl_Response()  : numberMatched() , numberChanged()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(numberMatched ,0);
			BOOST_ASN_IMPLICIT_TAG(numberChanged ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ChangeAccessControl_Request{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum scopeOfChange_type_enum {
			scopeOfChange_type_null = 0  , 
			scopeOfChange_type_vMDOnly , 
			scopeOfChange_type_listOfObjects , 
		};

	struct  scopeOfChange_type : public BOOST_ASN_CHOICE_STRUCT(scopeOfChange_type_enum) {



		//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  listOfObjects_type{

			//start==============================================================
			//It is  INTERNAL CHOICE

							enum objectScope_type_enum {
					objectScope_type_null = 0  , 
					objectScope_type_specific , 
					objectScope_type_aa_specific , 
					objectScope_type_domain , 
					objectScope_type_vmd , 
				};

	struct  objectScope_type : public BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) {

					//   SEQUENCE_OF is specific 
					typedef std::vector<ObjectName >   specific_type;




					objectScope_type() : BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) ()  {}


					BOOST_ASN_VALUE_CHOICE(specific, specific_type,  objectScope_type_specific)
					BOOST_ASN_VALUE_CHOICE(aa_specific, null_type,  objectScope_type_aa_specific)
					BOOST_ASN_VALUE_CHOICE(domain, Identifier,  objectScope_type_domain)
					BOOST_ASN_VALUE_CHOICE(vmd, null_type,  objectScope_type_vmd)

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
										case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , objectScope_type_specific) ,0)) return; else free(); break;}
										case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_aa_specific) ,1)) return; else free(); break;}
										case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , objectScope_type_domain) ,2)) return; else free(); break;}
										case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_vmd) ,3)) return; else free(); break;}
									default:{}}
									;}
								default:{
												;}}}
						else {
							 switch(type()){
								case objectScope_type_specific: {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , objectScope_type_specific) ,0); break;}
								case objectScope_type_aa_specific: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_aa_specific) ,1); break;}
								case objectScope_type_domain: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , objectScope_type_domain) ,2); break;}
								case objectScope_type_vmd: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_vmd) ,3); break;}
								default:{}}}
					}
				};


				boost::asn1::value_holder<ObjectClass >  objectClass;
				boost::asn1::value_holder<objectScope_type >  objectScope;

				listOfObjects_type()  : objectClass() , objectScope()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_CHOICE_TAG(objectClass ,0);
					BOOST_ASN_CHOICE_TAG(objectScope ,1);
				}
			};

		//end==============================================================

			scopeOfChange_type() : BOOST_ASN_CHOICE_STRUCT(scopeOfChange_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(vMDOnly, null_type,  scopeOfChange_type_vMDOnly)
			BOOST_ASN_VALUE_CHOICE(listOfObjects, listOfObjects_type,  scopeOfChange_type_listOfObjects)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , scopeOfChange_type_vMDOnly) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<listOfObjects_type > (true , scopeOfChange_type_listOfObjects) ,1)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case scopeOfChange_type_vMDOnly: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , scopeOfChange_type_vMDOnly) ,0); break;}
						case scopeOfChange_type_listOfObjects: {BOOST_ASN_IMPLICIT_TAG(value<listOfObjects_type > (false , scopeOfChange_type_listOfObjects) ,1); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<scopeOfChange_type >  scopeOfChange;
		boost::asn1::value_holder<Identifier >  accessControlListName;

		ChangeAccessControl_Request()  : scopeOfChange() , accessControlListName()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(scopeOfChange);
			BOOST_ASN_IMPLICIT_TAG(accessControlListName ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportAccessControlledObjects_Response{
		//   SEQUENCE_OF is listOfNames 
		typedef std::vector<ObjectName >   listOfNames_type;



		boost::asn1::value_holder<listOfNames_type >  listOfNames;
		boost::shared_ptr<bool > moreFollows;   //  DEFAULT   
 		BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  moreFollows)

 
		ReportAccessControlledObjects_Response()  : listOfNames()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(listOfNames ,0);
			BOOST_ASN_IMPLICIT_TAG(moreFollows ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  ReportAccessControlledObjects_Request{

		boost::asn1::value_holder<Identifier >  accessControlList;
		boost::asn1::value_holder<ObjectClass >  objectClass;
		boost::asn1::value_holder<ObjectName >  continueAfter;

		ReportAccessControlledObjects_Request()  : accessControlList() , objectClass() , continueAfter()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(accessControlList ,0);
			BOOST_ASN_CHOICE_TAG(objectClass ,1);
			BOOST_ASN_CHOICE_TAG(continueAfter ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  GetAccessControlListAttributes_Response{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  accessControlListElements_type{

			boost::asn1::value_holder<AccessCondition >  readAccessCondition;
			boost::asn1::value_holder<AccessCondition >  storeAccessCondition;
			boost::asn1::value_holder<AccessCondition >  writeAccessCondition;
			boost::asn1::value_holder<AccessCondition >  loadAccessCondition;
			boost::asn1::value_holder<AccessCondition >  executeAccessCondition;
			boost::asn1::value_holder<AccessCondition >  deleteAccessCondition;
			boost::asn1::value_holder<AccessCondition >  editAccessCondition;

			accessControlListElements_type()  : readAccessCondition() , storeAccessCondition() , writeAccessCondition() , loadAccessCondition() , executeAccessCondition() , deleteAccessCondition() , editAccessCondition()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE_TAG(readAccessCondition ,0);
				BOOST_ASN_CHOICE_TAG(storeAccessCondition ,1);
				BOOST_ASN_CHOICE_TAG(writeAccessCondition ,2);
				BOOST_ASN_CHOICE_TAG(loadAccessCondition ,3);
				BOOST_ASN_CHOICE_TAG(executeAccessCondition ,4);
				BOOST_ASN_CHOICE_TAG(deleteAccessCondition ,5);
				BOOST_ASN_CHOICE_TAG(editAccessCondition ,6);
			}
		};

	//end==============================================================

		//   SEQUENCE_OF is references 
			//start==============================================================
		//It is  INTERNAL SEQUENCE  

			struct  references_type_sequence_of{


				boost::asn1::value_holder<ObjectClass >  objectClass;
				boost::asn1::value_holder<int >  objectCount;

				references_type_sequence_of()  : objectClass() , objectCount()  {}

				 template<typename Archive> void serialize(Archive& arch){

					BOOST_ASN_CHOICE_TAG(objectClass ,0);
					BOOST_ASN_IMPLICIT_TAG(objectCount ,1);
				}
			};

		//end==============================================================
	typedef std::vector<references_type_sequence_of >   references_type;


		boost::asn1::value_holder<Identifier >  name;
		boost::asn1::value_holder<accessControlListElements_type >  accessControlListElements;
		boost::asn1::value_holder<bool >  vMDuse;
		boost::asn1::value_holder<references_type >  references;
		boost::shared_ptr<Identifier > accessControlList;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  accessControlList)

 
		GetAccessControlListAttributes_Response()  : name() , accessControlListElements() , vMDuse() , references()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_EXPLICIT_TAG(name ,0);
			BOOST_ASN_IMPLICIT_TAG(accessControlListElements ,1);
			BOOST_ASN_IMPLICIT_TAG(vMDuse ,2);
			BOOST_ASN_IMPLICIT_TAG(references ,3);
			BOOST_ASN_IMPLICIT_TAG(accessControlList ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum GetAccessControlListAttributes_Request_enum {
		GetAccessControlListAttributes_Request_null = 0  , 
		GetAccessControlListAttributes_Request_accessControlListName , 
		GetAccessControlListAttributes_Request_vMD , 
		GetAccessControlListAttributes_Request_namedObject , 
	};

	struct  GetAccessControlListAttributes_Request : public BOOST_ASN_CHOICE_STRUCT(GetAccessControlListAttributes_Request_enum) {



	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  namedObject_type{

			boost::asn1::value_holder<ObjectClass >  objectClass;
			boost::asn1::value_holder<ObjectName >  objectName;

			namedObject_type()  : objectClass() , objectName()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE_TAG(objectClass ,0);
				BOOST_ASN_CHOICE_TAG(objectName ,1);
			}
		};

	//end==============================================================

		GetAccessControlListAttributes_Request() : BOOST_ASN_CHOICE_STRUCT(GetAccessControlListAttributes_Request_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(accessControlListName, Identifier,  GetAccessControlListAttributes_Request_accessControlListName)
		BOOST_ASN_VALUE_CHOICE(vMD, null_type,  GetAccessControlListAttributes_Request_vMD)
		BOOST_ASN_VALUE_CHOICE(namedObject, namedObject_type,  GetAccessControlListAttributes_Request_namedObject)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , GetAccessControlListAttributes_Request_accessControlListName) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , GetAccessControlListAttributes_Request_vMD) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<namedObject_type > (true , GetAccessControlListAttributes_Request_namedObject) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case GetAccessControlListAttributes_Request_accessControlListName: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , GetAccessControlListAttributes_Request_accessControlListName) ,0); break;}
					case GetAccessControlListAttributes_Request_vMD: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , GetAccessControlListAttributes_Request_vMD) ,1); break;}
					case GetAccessControlListAttributes_Request_namedObject: {BOOST_ASN_IMPLICIT_TAG(value<namedObject_type > (false , GetAccessControlListAttributes_Request_namedObject) ,2); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  DefineAccessControlList_Request{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  accessControlListElements_type{

			boost::asn1::value_holder<AccessCondition >  readAccessCondition;
			boost::asn1::value_holder<AccessCondition >  storeAccessCondition;
			boost::asn1::value_holder<AccessCondition >  writeAccessCondition;
			boost::asn1::value_holder<AccessCondition >  loadAccessCondition;
			boost::asn1::value_holder<AccessCondition >  executeAccessCondition;
			boost::asn1::value_holder<AccessCondition >  deleteAccessCondition;
			boost::asn1::value_holder<AccessCondition >  editAccessCondition;

			accessControlListElements_type()  : readAccessCondition() , storeAccessCondition() , writeAccessCondition() , loadAccessCondition() , executeAccessCondition() , deleteAccessCondition() , editAccessCondition()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_CHOICE_TAG(readAccessCondition ,0);
				BOOST_ASN_CHOICE_TAG(storeAccessCondition ,1);
				BOOST_ASN_CHOICE_TAG(writeAccessCondition ,2);
				BOOST_ASN_CHOICE_TAG(loadAccessCondition ,3);
				BOOST_ASN_CHOICE_TAG(executeAccessCondition ,4);
				BOOST_ASN_CHOICE_TAG(deleteAccessCondition ,5);
				BOOST_ASN_CHOICE_TAG(editAccessCondition ,6);
			}
		};

	//end==============================================================

		boost::asn1::value_holder<Identifier >  accessControlListName;
		boost::asn1::value_holder<accessControlListElements_type >  accessControlListElements;

		DefineAccessControlList_Request()  : accessControlListName() , accessControlListElements()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(accessControlListName ,0);
			BOOST_ASN_IMPLICIT_TAG(accessControlListElements ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  RejectPDU{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum rejectReason_type_enum {
			rejectReason_type_null = 0  , 
			rejectReason_type_confirmed_requestPDU , 
			rejectReason_type_confirmed_responsePDU , 
			rejectReason_type_confirmed_errorPDU , 
			rejectReason_type_unconfirmedPDU , 
			rejectReason_type_pdu_error , 
			rejectReason_type_cancel_requestPDU , 
			rejectReason_type_cancel_responsePDU , 
			rejectReason_type_cancel_errorPDU , 
			rejectReason_type_conclude_requestPDU , 
			rejectReason_type_conclude_responsePDU , 
			rejectReason_type_conclude_errorPDU , 
		};

	struct  rejectReason_type : public BOOST_ASN_CHOICE_STRUCT(rejectReason_type_enum) {



			static const int confirmed_requestPDU_other = 0;
			static const int confirmed_requestPDU_unrecognized_service = 1;
			static const int confirmed_requestPDU_unrecognized_modifier = 2;
			static const int confirmed_requestPDU_invalid_invokeID = 3;
			static const int confirmed_requestPDU_invalid_argument = 4;
			static const int confirmed_requestPDU_invalid_modifier = 5;
			static const int confirmed_requestPDU_max_serv_outstanding_exceeded = 6;
			static const int confirmed_requestPDU_max_recursion_exceeded = 8;
			static const int confirmed_requestPDU_value_out_of_range = 9;



			static const int confirmed_responsePDU_other = 0;
			static const int confirmed_responsePDU_unrecognized_service = 1;
			static const int confirmed_responsePDU_invalid_invokeID = 2;
			static const int confirmed_responsePDU_invalid_result = 3;
			static const int confirmed_responsePDU_max_recursion_exceeded = 5;
			static const int confirmed_responsePDU_value_out_of_range = 6;



			static const int confirmed_errorPDU_other = 0;
			static const int confirmed_errorPDU_unrecognized_service = 1;
			static const int confirmed_errorPDU_invalid_invokeID = 2;
			static const int confirmed_errorPDU_invalid_serviceError = 3;
			static const int confirmed_errorPDU_value_out_of_range = 4;



			static const int unconfirmedPDU_other = 0;
			static const int unconfirmedPDU_unrecognized_service = 1;
			static const int unconfirmedPDU_invalid_argument = 2;
			static const int unconfirmedPDU_max_recursion_exceeded = 3;
			static const int unconfirmedPDU_value_out_of_range = 4;



			static const int pdu_error_unknown_pdu_type = 0;
			static const int pdu_error_invalid_pdu = 1;
			static const int pdu_error_illegal_acse_mapping = 2;



			static const int cancel_requestPDU_other = 0;
			static const int cancel_requestPDU_invalid_invokeID = 1;



			static const int cancel_responsePDU_other = 0;
			static const int cancel_responsePDU_invalid_invokeID = 1;



			static const int cancel_errorPDU_other = 0;
			static const int cancel_errorPDU_invalid_invokeID = 1;
			static const int cancel_errorPDU_invalid_serviceError = 2;
			static const int cancel_errorPDU_value_out_of_range = 3;



			static const int conclude_requestPDU_other = 0;
			static const int conclude_requestPDU_invalid_argument = 1;



			static const int conclude_responsePDU_other = 0;
			static const int conclude_responsePDU_invalid_result = 1;



			static const int conclude_errorPDU_other = 0;
			static const int conclude_errorPDU_invalid_serviceError = 1;
			static const int conclude_errorPDU_value_out_of_range = 2;


			rejectReason_type() : BOOST_ASN_CHOICE_STRUCT(rejectReason_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(confirmed_requestPDU, int,  rejectReason_type_confirmed_requestPDU)
			BOOST_ASN_VALUE_CHOICE(confirmed_responsePDU, int,  rejectReason_type_confirmed_responsePDU)
			BOOST_ASN_VALUE_CHOICE(confirmed_errorPDU, int,  rejectReason_type_confirmed_errorPDU)
			BOOST_ASN_VALUE_CHOICE(unconfirmedPDU, int,  rejectReason_type_unconfirmedPDU)
			BOOST_ASN_VALUE_CHOICE(pdu_error, int,  rejectReason_type_pdu_error)
			BOOST_ASN_VALUE_CHOICE(cancel_requestPDU, int,  rejectReason_type_cancel_requestPDU)
			BOOST_ASN_VALUE_CHOICE(cancel_responsePDU, int,  rejectReason_type_cancel_responsePDU)
			BOOST_ASN_VALUE_CHOICE(cancel_errorPDU, int,  rejectReason_type_cancel_errorPDU)
			BOOST_ASN_VALUE_CHOICE(conclude_requestPDU, int,  rejectReason_type_conclude_requestPDU)
			BOOST_ASN_VALUE_CHOICE(conclude_responsePDU, int,  rejectReason_type_conclude_responsePDU)
			BOOST_ASN_VALUE_CHOICE(conclude_errorPDU, int,  rejectReason_type_conclude_errorPDU)

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
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_confirmed_requestPDU) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_confirmed_responsePDU) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_confirmed_errorPDU) ,3)) return; else free(); break;}
								case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_unconfirmedPDU) ,4)) return; else free(); break;}
								case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_pdu_error) ,5)) return; else free(); break;}
								case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_cancel_requestPDU) ,6)) return; else free(); break;}
								case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_cancel_responsePDU) ,7)) return; else free(); break;}
								case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_cancel_errorPDU) ,8)) return; else free(); break;}
								case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_conclude_requestPDU) ,9)) return; else free(); break;}
								case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_conclude_responsePDU) ,10)) return; else free(); break;}
								case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_conclude_errorPDU) ,11)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case rejectReason_type_confirmed_requestPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_confirmed_requestPDU) ,1); break;}
						case rejectReason_type_confirmed_responsePDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_confirmed_responsePDU) ,2); break;}
						case rejectReason_type_confirmed_errorPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_confirmed_errorPDU) ,3); break;}
						case rejectReason_type_unconfirmedPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_unconfirmedPDU) ,4); break;}
						case rejectReason_type_pdu_error: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_pdu_error) ,5); break;}
						case rejectReason_type_cancel_requestPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_cancel_requestPDU) ,6); break;}
						case rejectReason_type_cancel_responsePDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_cancel_responsePDU) ,7); break;}
						case rejectReason_type_cancel_errorPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_cancel_errorPDU) ,8); break;}
						case rejectReason_type_conclude_requestPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_conclude_requestPDU) ,9); break;}
						case rejectReason_type_conclude_responsePDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_conclude_responsePDU) ,10); break;}
						case rejectReason_type_conclude_errorPDU: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_conclude_errorPDU) ,11); break;}
						default:{}}}
			}
		};


		boost::shared_ptr<Unsigned32 > originalInvokeID;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  originalInvokeID)

 		boost::asn1::value_holder<rejectReason_type >  rejectReason;

		RejectPDU()  : rejectReason()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(originalInvokeID ,0);
			BOOST_ASN_CHOICE(rejectReason);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Cancel_ErrorPDU{

		boost::asn1::value_holder<Unsigned32 >  originalInvokeID;
		boost::asn1::value_holder<ServiceError >  serviceError;

		Cancel_ErrorPDU()  : originalInvokeID() , serviceError()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(originalInvokeID ,0);
			BOOST_ASN_IMPLICIT_TAG(serviceError ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Initiate_ResponsePDU{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  initResponseDetail_type{



			boost::asn1::value_holder<Integer16 >  negotiatedVersionNumber;
			boost::asn1::value_holder<ParameterSupportOptions >  negotiatedParameterCBB;
			boost::asn1::value_holder<ServiceSupportOptions >  servicesSupportedCalled;
			boost::shared_ptr<AdditionalSupportOptions > additionalSupportedCalled;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalSupportOptions ,  additionalSupportedCalled)

 			boost::shared_ptr<AdditionalCBBOptions > additionalCbbSupportedCalled;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalCBBOptions ,  additionalCbbSupportedCalled)

 			boost::shared_ptr<visiblestring_type > privilegeClassIdentityCalled;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  privilegeClassIdentityCalled)

 
			initResponseDetail_type()  : negotiatedVersionNumber() , negotiatedParameterCBB() , servicesSupportedCalled() , additionalSupportedCalled() , additionalCbbSupportedCalled() , privilegeClassIdentityCalled()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(negotiatedVersionNumber ,0);
				BOOST_ASN_IMPLICIT_TAG(negotiatedParameterCBB ,1);
				BOOST_ASN_IMPLICIT_TAG(servicesSupportedCalled ,2);
				BOOST_ASN_EXTENTION;
				BOOST_ASN_IMPLICIT_TAG(additionalSupportedCalled ,3);
				BOOST_ASN_IMPLICIT_TAG(additionalCbbSupportedCalled ,4);
				BOOST_ASN_IMPLICIT_TAG(privilegeClassIdentityCalled ,5);
			}
		};

	//end==============================================================

		boost::shared_ptr<Integer32 > localDetailCalled;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Integer32 ,  localDetailCalled)

 		boost::asn1::value_holder<Integer16 >  negotiatedMaxServOutstandingCalling;
		boost::asn1::value_holder<Integer16 >  negotiatedMaxServOutstandingCalled;
		boost::shared_ptr<Integer8 > negotiatedDataStructureNestingLevel;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Integer8 ,  negotiatedDataStructureNestingLevel)

 		boost::asn1::value_holder<initResponseDetail_type >  initResponseDetail;

		Initiate_ResponsePDU()  : negotiatedMaxServOutstandingCalling() , negotiatedMaxServOutstandingCalled() , initResponseDetail()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(localDetailCalled ,0);
			BOOST_ASN_IMPLICIT_TAG(negotiatedMaxServOutstandingCalling ,1);
			BOOST_ASN_IMPLICIT_TAG(negotiatedMaxServOutstandingCalled ,2);
			BOOST_ASN_IMPLICIT_TAG(negotiatedDataStructureNestingLevel ,3);
			BOOST_ASN_IMPLICIT_TAG(initResponseDetail ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Initiate_RequestPDU{

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  initRequestDetail_type{



			boost::asn1::value_holder<Integer16 >  proposedVersionNumber;
			boost::asn1::value_holder<ParameterSupportOptions >  proposedParameterCBB;
			boost::asn1::value_holder<ServiceSupportOptions >  servicesSupportedCalling;
			boost::shared_ptr<AdditionalSupportOptions > additionalSupportedCalling;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalSupportOptions ,  additionalSupportedCalling)

 			boost::shared_ptr<AdditionalCBBOptions > additionalCbbSupportedCalling;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalCBBOptions ,  additionalCbbSupportedCalling)

 			boost::shared_ptr<visiblestring_type > privilegeClassIdentityCalling;   //  OPTIONAL
			BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  privilegeClassIdentityCalling)

 
			initRequestDetail_type()  : proposedVersionNumber() , proposedParameterCBB() , servicesSupportedCalling() , additionalSupportedCalling() , additionalCbbSupportedCalling() , privilegeClassIdentityCalling()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(proposedVersionNumber ,0);
				BOOST_ASN_IMPLICIT_TAG(proposedParameterCBB ,1);
				BOOST_ASN_IMPLICIT_TAG(servicesSupportedCalling ,2);
				BOOST_ASN_EXTENTION;
				BOOST_ASN_IMPLICIT_TAG(additionalSupportedCalling ,3);
				BOOST_ASN_IMPLICIT_TAG(additionalCbbSupportedCalling ,4);
				BOOST_ASN_IMPLICIT_TAG(privilegeClassIdentityCalling ,5);
			}
		};

	//end==============================================================

		boost::shared_ptr<Integer32 > localDetailCalling;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Integer32 ,  localDetailCalling)

 		boost::asn1::value_holder<Integer16 >  proposedMaxServOutstandingCalling;
		boost::asn1::value_holder<Integer16 >  proposedMaxServOutstandingCalled;
		boost::shared_ptr<Integer8 > proposedDataStructureNestingLevel;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Integer8 ,  proposedDataStructureNestingLevel)

 		boost::asn1::value_holder<initRequestDetail_type >  initRequestDetail;

		Initiate_RequestPDU()  : proposedMaxServOutstandingCalling() , proposedMaxServOutstandingCalled() , initRequestDetail()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(localDetailCalling ,0);
			BOOST_ASN_IMPLICIT_TAG(proposedMaxServOutstandingCalling ,1);
			BOOST_ASN_IMPLICIT_TAG(proposedMaxServOutstandingCalled ,2);
			BOOST_ASN_IMPLICIT_TAG(proposedDataStructureNestingLevel ,3);
			BOOST_ASN_IMPLICIT_TAG(initRequestDetail ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum ObjectClass_enum {
		ObjectClass_null = 0  , 
		ObjectClass_basicObjectClass , 
		ObjectClass_csObjectClass , 
	};

	struct  ObjectClass : public BOOST_ASN_CHOICE_STRUCT(ObjectClass_enum) {



		static const int basicObjectClass_namedVariable = 0;
		static const int basicObjectClass_scatteredAccess = 1;
		static const int basicObjectClass_namedVariableList = 2;
		static const int basicObjectClass_namedType = 3;
		static const int basicObjectClass_semaphore = 4;
		static const int basicObjectClass_eventCondition = 5;
		static const int basicObjectClass_eventAction = 6;
		static const int basicObjectClass_eventEnrollment = 7;
		static const int basicObjectClass_journal = 8;
		static const int basicObjectClass_domain = 9;
		static const int basicObjectClass_programInvocation = 10;
		static const int basicObjectClass_operatorStation = 11;
		static const int basicObjectClass_dataExchange = 12;
		static const int basicObjectClass_accessControlList = 13;




		static const int csObjectClass_eventConditionList = 0;
		static const int csObjectClass_unitControl = 1;


		ObjectClass() : BOOST_ASN_CHOICE_STRUCT(ObjectClass_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(basicObjectClass, int,  ObjectClass_basicObjectClass)
		BOOST_ASN_VALUE_CHOICE(csObjectClass, int,  ObjectClass_csObjectClass)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , ObjectClass_basicObjectClass) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , ObjectClass_csObjectClass) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case ObjectClass_basicObjectClass: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , ObjectClass_basicObjectClass) ,0); break;}
					case ObjectClass_csObjectClass: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , ObjectClass_csObjectClass) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum ObjectName_enum {
		ObjectName_null = 0  , 
		ObjectName_vmd_specific , 
		ObjectName_domain_specific , 
		ObjectName_aa_specific , 
	};

	struct  ObjectName : public BOOST_ASN_CHOICE_STRUCT(ObjectName_enum) {


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  domain_specific_type{

			boost::asn1::value_holder<Identifier >  domainID;
			boost::asn1::value_holder<Identifier >  itemID;

			domain_specific_type()  : domainID() , itemID()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_BIND_TAG(domainID);
				BOOST_ASN_BIND_TAG(itemID);
			}
		};

	//end==============================================================

		ObjectName() : BOOST_ASN_CHOICE_STRUCT(ObjectName_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(vmd_specific, Identifier,  ObjectName_vmd_specific)
		BOOST_ASN_VALUE_CHOICE(domain_specific, domain_specific_type,  ObjectName_domain_specific)
		BOOST_ASN_VALUE_CHOICE(aa_specific, Identifier,  ObjectName_aa_specific)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , ObjectName_vmd_specific) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<domain_specific_type > (true , ObjectName_domain_specific) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , ObjectName_aa_specific) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case ObjectName_vmd_specific: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , ObjectName_vmd_specific) ,0); break;}
					case ObjectName_domain_specific: {BOOST_ASN_IMPLICIT_TAG(value<domain_specific_type > (false , ObjectName_domain_specific) ,1); break;}
					case ObjectName_aa_specific: {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , ObjectName_aa_specific) ,2); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AdditionalService_Error_enum {
		AdditionalService_Error_null = 0  , 
		AdditionalService_Error_defineEcl , 
		AdditionalService_Error_addECLReference , 
		AdditionalService_Error_removeECLReference , 
		AdditionalService_Error_initiateUC , 
		AdditionalService_Error_startUC , 
		AdditionalService_Error_stopUC , 
		AdditionalService_Error_deleteUC , 
		AdditionalService_Error_loadUCFromFile , 
	};

	struct  AdditionalService_Error : public BOOST_ASN_CHOICE_STRUCT(AdditionalService_Error_enum) {


		AdditionalService_Error() : BOOST_ASN_CHOICE_STRUCT(AdditionalService_Error_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(defineEcl, DefineEventConditionList_Error,  AdditionalService_Error_defineEcl)
		BOOST_ASN_VALUE_CHOICE(addECLReference, AddEventConditionListReference_Error,  AdditionalService_Error_addECLReference)
		BOOST_ASN_VALUE_CHOICE(removeECLReference, RemoveEventConditionListReference_Error,  AdditionalService_Error_removeECLReference)
		BOOST_ASN_VALUE_CHOICE(initiateUC, InitiateUnitControl_Error,  AdditionalService_Error_initiateUC)
		BOOST_ASN_VALUE_CHOICE(startUC, StartUnitControl_Error,  AdditionalService_Error_startUC)
		BOOST_ASN_VALUE_CHOICE(stopUC, StopUnitControl_Error,  AdditionalService_Error_stopUC)
		BOOST_ASN_VALUE_CHOICE(deleteUC, DeleteUnitControl_Error,  AdditionalService_Error_deleteUC)
		BOOST_ASN_VALUE_CHOICE(loadUCFromFile, LoadUnitControlFromFile_Error,  AdditionalService_Error_loadUCFromFile)

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
							case 0: { if(BOOST_ASN_CHOICE_TAG(value<DefineEventConditionList_Error > (true , AdditionalService_Error_defineEcl) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_CHOICE_TAG(value<AddEventConditionListReference_Error > (true , AdditionalService_Error_addECLReference) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (true , AdditionalService_Error_removeECLReference) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_CHOICE_TAG(value<InitiateUnitControl_Error > (true , AdditionalService_Error_initiateUC) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Error > (true , AdditionalService_Error_startUC) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Error > (true , AdditionalService_Error_stopUC) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_CHOICE_TAG(value<DeleteUnitControl_Error > (true , AdditionalService_Error_deleteUC) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (true , AdditionalService_Error_loadUCFromFile) ,7)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case AdditionalService_Error_defineEcl: {BOOST_ASN_CHOICE_TAG(value<DefineEventConditionList_Error > (false , AdditionalService_Error_defineEcl) ,0); break;}
					case AdditionalService_Error_addECLReference: {BOOST_ASN_CHOICE_TAG(value<AddEventConditionListReference_Error > (false , AdditionalService_Error_addECLReference) ,1); break;}
					case AdditionalService_Error_removeECLReference: {BOOST_ASN_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (false , AdditionalService_Error_removeECLReference) ,2); break;}
					case AdditionalService_Error_initiateUC: {BOOST_ASN_CHOICE_TAG(value<InitiateUnitControl_Error > (false , AdditionalService_Error_initiateUC) ,3); break;}
					case AdditionalService_Error_startUC: {BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Error > (false , AdditionalService_Error_startUC) ,4); break;}
					case AdditionalService_Error_stopUC: {BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Error > (false , AdditionalService_Error_stopUC) ,5); break;}
					case AdditionalService_Error_deleteUC: {BOOST_ASN_CHOICE_TAG(value<DeleteUnitControl_Error > (false , AdditionalService_Error_deleteUC) ,6); break;}
					case AdditionalService_Error_loadUCFromFile: {BOOST_ASN_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (false , AdditionalService_Error_loadUCFromFile) ,7); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  ServiceError{

	//start==============================================================
	//It is  INTERNAL CHOICE

			enum errorClass_type_enum {
			errorClass_type_null = 0  , 
			errorClass_type_vmd_state , 
			errorClass_type_application_reference , 
			errorClass_type_definition , 
			errorClass_type_resource , 
			errorClass_type_service , 
			errorClass_type_service_preempt , 
			errorClass_type_time_resolution , 
			errorClass_type_access , 
			errorClass_type_initiate , 
			errorClass_type_conclude , 
			errorClass_type_cancel , 
			errorClass_type_file , 
			errorClass_type_others , 
		};

	struct  errorClass_type : public BOOST_ASN_CHOICE_STRUCT(errorClass_type_enum) {



			static const int vmd_state_other = 0;
			static const int vmd_state_vmd_state_conflict = 1;
			static const int vmd_state_vmd_operational_problem = 2;
			static const int vmd_state_domain_transfer_problem = 3;
			static const int vmd_state_state_machine_id_invalid = 4;



			static const int application_reference_other = 0;
			static const int application_reference_application_unreachable = 1;
			static const int application_reference_connection_lost = 2;
			static const int application_reference_application_reference_invalid = 3;
			static const int application_reference_context_unsupported = 4;



			static const int definition_other = 0;
			static const int definition_object_undefined = 1;
			static const int definition_invalid_address = 2;
			static const int definition_type_unsupported = 3;
			static const int definition_type_inconsistent = 4;
			static const int definition_object_exists = 5;
			static const int definition_object_attribute_inconsistent = 6;



			static const int resource_other = 0;
			static const int resource_memory_unavailable = 1;
			static const int resource_processor_resource_unavailable = 2;
			static const int resource_mass_storage_unavailable = 3;
			static const int resource_capability_unavailable = 4;
			static const int resource_capability_unknown = 5;



			static const int service_other = 0;
			static const int service_primitives_out_of_sequence = 1;
			static const int service_object_state_conflict = 2;
			static const int service_continuation_invalid = 4;
			static const int service_object_constraint_conflict = 5;



			static const int service_preempt_other = 0;
			static const int service_preempt_timeout = 1;
			static const int service_preempt_deadlock = 2;
			static const int service_preempt_cancel = 3;



			static const int time_resolution_other = 0;
			static const int time_resolution_unsupportable_time_resolution = 1;



			static const int access_other = 0;
			static const int access_object_access_unsupported = 1;
			static const int access_object_non_existent = 2;
			static const int access_object_access_denied = 3;
			static const int access_object_invalidated = 4;



			static const int initiate_other = 0;
			static const int initiate_max_services_outstanding_calling_insufficient = 3;
			static const int initiate_max_services_outstanding_called_insufficient = 4;
			static const int initiate_service_CBB_insufficient = 5;
			static const int initiate_parameter_CBB_insufficient = 6;
			static const int initiate_nesting_level_insufficient = 7;



			static const int conclude_other = 0;
			static const int conclude_further_communication_required = 1;



			static const int cancel_other = 0;
			static const int cancel_invoke_id_unknown = 1;
			static const int cancel_cancel_not_possible = 2;



			static const int file_other = 0;
			static const int file_filename_ambiguous = 1;
			static const int file_file_busy = 2;
			static const int file_filename_syntax_error = 3;
			static const int file_content_type_invalid = 4;
			static const int file_position_invalid = 5;
			static const int file_file_access_denied = 6;
			static const int file_file_non_existent = 7;
			static const int file_duplicate_filename = 8;
			static const int file_insufficient_space_in_filestore = 9;



			errorClass_type() : BOOST_ASN_CHOICE_STRUCT(errorClass_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(vmd_state, int,  errorClass_type_vmd_state)
			BOOST_ASN_VALUE_CHOICE(application_reference, int,  errorClass_type_application_reference)
			BOOST_ASN_VALUE_CHOICE(definition, int,  errorClass_type_definition)
			BOOST_ASN_VALUE_CHOICE(resource, int,  errorClass_type_resource)
			BOOST_ASN_VALUE_CHOICE(service, int,  errorClass_type_service)
			BOOST_ASN_VALUE_CHOICE(service_preempt, int,  errorClass_type_service_preempt)
			BOOST_ASN_VALUE_CHOICE(time_resolution, int,  errorClass_type_time_resolution)
			BOOST_ASN_VALUE_CHOICE(access, int,  errorClass_type_access)
			BOOST_ASN_VALUE_CHOICE(initiate, int,  errorClass_type_initiate)
			BOOST_ASN_VALUE_CHOICE(conclude, int,  errorClass_type_conclude)
			BOOST_ASN_VALUE_CHOICE(cancel, int,  errorClass_type_cancel)
			BOOST_ASN_VALUE_CHOICE(file, int,  errorClass_type_file)
			BOOST_ASN_VALUE_CHOICE(others, int,  errorClass_type_others)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_vmd_state) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_application_reference) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_definition) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_resource) ,3)) return; else free(); break;}
								case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_service) ,4)) return; else free(); break;}
								case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_service_preempt) ,5)) return; else free(); break;}
								case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_time_resolution) ,6)) return; else free(); break;}
								case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_access) ,7)) return; else free(); break;}
								case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_initiate) ,8)) return; else free(); break;}
								case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_conclude) ,9)) return; else free(); break;}
								case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_cancel) ,10)) return; else free(); break;}
								case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_file) ,11)) return; else free(); break;}
								case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_others) ,12)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case errorClass_type_vmd_state: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_vmd_state) ,0); break;}
						case errorClass_type_application_reference: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_application_reference) ,1); break;}
						case errorClass_type_definition: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_definition) ,2); break;}
						case errorClass_type_resource: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_resource) ,3); break;}
						case errorClass_type_service: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_service) ,4); break;}
						case errorClass_type_service_preempt: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_service_preempt) ,5); break;}
						case errorClass_type_time_resolution: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_time_resolution) ,6); break;}
						case errorClass_type_access: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_access) ,7); break;}
						case errorClass_type_initiate: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_initiate) ,8); break;}
						case errorClass_type_conclude: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_conclude) ,9); break;}
						case errorClass_type_cancel: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_cancel) ,10); break;}
						case errorClass_type_file: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_file) ,11); break;}
						case errorClass_type_others: {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_others) ,12); break;}
						default:{}}}
			}
		};




	//start==============================================================
	//It is  INTERNAL CHOICE

			enum serviceSpecificInfo_type_enum {
			serviceSpecificInfo_type_null = 0  , 
			serviceSpecificInfo_type_obtainFile , 
			serviceSpecificInfo_type_start , 
			serviceSpecificInfo_type_stop , 
			serviceSpecificInfo_type_resume , 
			serviceSpecificInfo_type_reset , 
			serviceSpecificInfo_type_deleteVariableAccess , 
			serviceSpecificInfo_type_deleteNamedVariableList , 
			serviceSpecificInfo_type_deleteNamedType , 
			serviceSpecificInfo_type_defineEventEnrollment_Error , 
			serviceSpecificInfo_type_fileRename , 
			serviceSpecificInfo_type_additionalService , 
			serviceSpecificInfo_type_changeAccessControl , 
		};

	struct  serviceSpecificInfo_type : public BOOST_ASN_CHOICE_STRUCT(serviceSpecificInfo_type_enum) {


			serviceSpecificInfo_type() : BOOST_ASN_CHOICE_STRUCT(serviceSpecificInfo_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(obtainFile, ObtainFile_Error,  serviceSpecificInfo_type_obtainFile)
			BOOST_ASN_VALUE_CHOICE(start, Start_Error,  serviceSpecificInfo_type_start)
			BOOST_ASN_VALUE_CHOICE(stop, Stop_Error,  serviceSpecificInfo_type_stop)
			BOOST_ASN_VALUE_CHOICE(resume, Resume_Error,  serviceSpecificInfo_type_resume)
			BOOST_ASN_VALUE_CHOICE(reset, Reset_Error,  serviceSpecificInfo_type_reset)
			BOOST_ASN_VALUE_CHOICE(deleteVariableAccess, DeleteVariableAccess_Error,  serviceSpecificInfo_type_deleteVariableAccess)
			BOOST_ASN_VALUE_CHOICE(deleteNamedVariableList, DeleteNamedVariableList_Error,  serviceSpecificInfo_type_deleteNamedVariableList)
			BOOST_ASN_VALUE_CHOICE(deleteNamedType, DeleteNamedType_Error,  serviceSpecificInfo_type_deleteNamedType)
			BOOST_ASN_VALUE_CHOICE(defineEventEnrollment_Error, DefineEventEnrollment_Error,  serviceSpecificInfo_type_defineEventEnrollment_Error)
			BOOST_ASN_VALUE_CHOICE(fileRename, FileRename_Error,  serviceSpecificInfo_type_fileRename)
			BOOST_ASN_VALUE_CHOICE(additionalService, AdditionalService_Error,  serviceSpecificInfo_type_additionalService)
			BOOST_ASN_VALUE_CHOICE(changeAccessControl, ChangeAccessControl_Error,  serviceSpecificInfo_type_changeAccessControl)

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
								case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<ObtainFile_Error > (true , serviceSpecificInfo_type_obtainFile) ,0)) return; else free(); break;}
								case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Start_Error > (true , serviceSpecificInfo_type_start) ,1)) return; else free(); break;}
								case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Stop_Error > (true , serviceSpecificInfo_type_stop) ,2)) return; else free(); break;}
								case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Resume_Error > (true , serviceSpecificInfo_type_resume) ,3)) return; else free(); break;}
								case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<Reset_Error > (true , serviceSpecificInfo_type_reset) ,4)) return; else free(); break;}
								case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Error > (true , serviceSpecificInfo_type_deleteVariableAccess) ,5)) return; else free(); break;}
								case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Error > (true , serviceSpecificInfo_type_deleteNamedVariableList) ,6)) return; else free(); break;}
								case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Error > (true , serviceSpecificInfo_type_deleteNamedType) ,7)) return; else free(); break;}
								case 8: { if(BOOST_ASN_CHOICE_TAG(value<DefineEventEnrollment_Error > (true , serviceSpecificInfo_type_defineEventEnrollment_Error) ,8)) return; else free(); break;}
								case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<FileRename_Error > (true , serviceSpecificInfo_type_fileRename) ,9)) return; else free(); break;}
								case 10: { if(BOOST_ASN_CHOICE_TAG(value<AdditionalService_Error > (true , serviceSpecificInfo_type_additionalService) ,10)) return; else free(); break;}
								case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Error > (true , serviceSpecificInfo_type_changeAccessControl) ,11)) return; else free(); break;}
							default:{}}
							;}
						default:{
								;}}}
				else {
					 switch(type()){
						case serviceSpecificInfo_type_obtainFile: {BOOST_ASN_IMPLICIT_TAG(value<ObtainFile_Error > (false , serviceSpecificInfo_type_obtainFile) ,0); break;}
						case serviceSpecificInfo_type_start: {BOOST_ASN_IMPLICIT_TAG(value<Start_Error > (false , serviceSpecificInfo_type_start) ,1); break;}
						case serviceSpecificInfo_type_stop: {BOOST_ASN_IMPLICIT_TAG(value<Stop_Error > (false , serviceSpecificInfo_type_stop) ,2); break;}
						case serviceSpecificInfo_type_resume: {BOOST_ASN_IMPLICIT_TAG(value<Resume_Error > (false , serviceSpecificInfo_type_resume) ,3); break;}
						case serviceSpecificInfo_type_reset: {BOOST_ASN_IMPLICIT_TAG(value<Reset_Error > (false , serviceSpecificInfo_type_reset) ,4); break;}
						case serviceSpecificInfo_type_deleteVariableAccess: {BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Error > (false , serviceSpecificInfo_type_deleteVariableAccess) ,5); break;}
						case serviceSpecificInfo_type_deleteNamedVariableList: {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Error > (false , serviceSpecificInfo_type_deleteNamedVariableList) ,6); break;}
						case serviceSpecificInfo_type_deleteNamedType: {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Error > (false , serviceSpecificInfo_type_deleteNamedType) ,7); break;}
						case serviceSpecificInfo_type_defineEventEnrollment_Error: {BOOST_ASN_CHOICE_TAG(value<DefineEventEnrollment_Error > (false , serviceSpecificInfo_type_defineEventEnrollment_Error) ,8); break;}
						case serviceSpecificInfo_type_fileRename: {BOOST_ASN_IMPLICIT_TAG(value<FileRename_Error > (false , serviceSpecificInfo_type_fileRename) ,9); break;}
						case serviceSpecificInfo_type_additionalService: {BOOST_ASN_CHOICE_TAG(value<AdditionalService_Error > (false , serviceSpecificInfo_type_additionalService) ,10); break;}
						case serviceSpecificInfo_type_changeAccessControl: {BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Error > (false , serviceSpecificInfo_type_changeAccessControl) ,11); break;}
						default:{}}}
			}
		};


		boost::asn1::value_holder<errorClass_type >  errorClass;
		boost::shared_ptr<int > additionalCode;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  additionalCode)

 		boost::shared_ptr<visiblestring_type > additionalDescription;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type ,  additionalDescription)

 		boost::asn1::value_holder<serviceSpecificInfo_type >  serviceSpecificInfo;

		ServiceError()  : errorClass()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE_TAG(errorClass ,0);
			BOOST_ASN_IMPLICIT_TAG(additionalCode ,1);
			BOOST_ASN_IMPLICIT_TAG(additionalDescription ,2);
			BOOST_ASN_CHOICE_TAG(serviceSpecificInfo ,3);
		}
	};

//end==============================================================
//start==============================================================
//It is   SEQUENCE  

	struct  Confirmed_ErrorPDU{

		boost::asn1::value_holder<Unsigned32 >  invokeID;
		boost::shared_ptr<Unsigned32 > modifierPosition;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32 ,  modifierPosition)

 		boost::asn1::value_holder<ServiceError >  serviceError;

		Confirmed_ErrorPDU()  : invokeID() , serviceError()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(invokeID ,0);
			BOOST_ASN_IMPLICIT_TAG(modifierPosition ,1);
			BOOST_ASN_IMPLICIT_TAG(serviceError ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum Response_Detail_enum {
		Response_Detail_null = 0  , 
		Response_Detail_otherRequests , 
		Response_Detail_status , 
		Response_Detail_getProgramInvocationAttributes , 
		Response_Detail_getEventConditionAttributes , 
	};

	struct  Response_Detail : public BOOST_ASN_CHOICE_STRUCT(Response_Detail_enum) {



		Response_Detail() : BOOST_ASN_CHOICE_STRUCT(Response_Detail_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(otherRequests, null_type,  Response_Detail_otherRequests)
		BOOST_ASN_VALUE_CHOICE(status, CS_Status_Response,  Response_Detail_status)
		BOOST_ASN_VALUE_CHOICE(getProgramInvocationAttributes, CS_GetProgramInvocationAttributes_Response,  Response_Detail_getProgramInvocationAttributes)
		BOOST_ASN_VALUE_CHOICE(getEventConditionAttributes, CS_GetEventConditionAttributes_Response,  Response_Detail_getEventConditionAttributes)

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
							case 0: { if(BOOST_ASN_CHOICE_TAG(value<CS_Status_Response > (true , Response_Detail_status) ,0)) return; else free(); break;}
							case 45: { if(BOOST_ASN_IMPLICIT_TAG(value<CS_GetProgramInvocationAttributes_Response > (true , Response_Detail_getProgramInvocationAttributes) ,45)) return; else free(); break;}
							case 49: { if(BOOST_ASN_IMPLICIT_TAG(value<CS_GetEventConditionAttributes_Response > (true , Response_Detail_getEventConditionAttributes) ,49)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , Response_Detail_otherRequests))) return; else free();
					;}}}
			else {
				 switch(type()){
					case Response_Detail_otherRequests: {BOOST_ASN_BIND_TAG(value<null_type > (false , Response_Detail_otherRequests)); break;}
					case Response_Detail_status: {BOOST_ASN_CHOICE_TAG(value<CS_Status_Response > (false , Response_Detail_status) ,0); break;}
					case Response_Detail_getProgramInvocationAttributes: {BOOST_ASN_IMPLICIT_TAG(value<CS_GetProgramInvocationAttributes_Response > (false , Response_Detail_getProgramInvocationAttributes) ,45); break;}
					case Response_Detail_getEventConditionAttributes: {BOOST_ASN_IMPLICIT_TAG(value<CS_GetEventConditionAttributes_Response > (false , Response_Detail_getEventConditionAttributes) ,49); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AdditionalService_Response_enum {
		AdditionalService_Response_null = 0  , 
		AdditionalService_Response_vMDStop , 
		AdditionalService_Response_vMDReset , 
		AdditionalService_Response_select , 
		AdditionalService_Response_alterPI , 
		AdditionalService_Response_initiateUCLoad , 
		AdditionalService_Response_uCLoad , 
		AdditionalService_Response_uCUpload , 
		AdditionalService_Response_startUC , 
		AdditionalService_Response_stopUC , 
		AdditionalService_Response_createUC , 
		AdditionalService_Response_addToUC , 
		AdditionalService_Response_removeFromUC , 
		AdditionalService_Response_getUCAttributes , 
		AdditionalService_Response_loadUCFromFile , 
		AdditionalService_Response_storeUCToFile , 
		AdditionalService_Response_deleteUC , 
		AdditionalService_Response_defineECL , 
		AdditionalService_Response_deleteECL , 
		AdditionalService_Response_addECLReference , 
		AdditionalService_Response_removeECLReference , 
		AdditionalService_Response_getECLAttributes , 
		AdditionalService_Response_reportECLStatus , 
		AdditionalService_Response_alterECLMonitoring , 
	};

	struct  AdditionalService_Response : public BOOST_ASN_CHOICE_STRUCT(AdditionalService_Response_enum) {


		AdditionalService_Response() : BOOST_ASN_CHOICE_STRUCT(AdditionalService_Response_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(vMDStop, VMDStop_Response,  AdditionalService_Response_vMDStop)
		BOOST_ASN_VALUE_CHOICE(vMDReset, VMDReset_Response,  AdditionalService_Response_vMDReset)
		BOOST_ASN_VALUE_CHOICE(select, Select_Response,  AdditionalService_Response_select)
		BOOST_ASN_VALUE_CHOICE(alterPI, AlterProgramInvocationAttributes_Response,  AdditionalService_Response_alterPI)
		BOOST_ASN_VALUE_CHOICE(initiateUCLoad, InitiateUnitControlLoad_Response,  AdditionalService_Response_initiateUCLoad)
		BOOST_ASN_VALUE_CHOICE(uCLoad, UnitControlLoadSegment_Response,  AdditionalService_Response_uCLoad)
		BOOST_ASN_VALUE_CHOICE(uCUpload, UnitControlUpload_Response,  AdditionalService_Response_uCUpload)
		BOOST_ASN_VALUE_CHOICE(startUC, StartUnitControl_Response,  AdditionalService_Response_startUC)
		BOOST_ASN_VALUE_CHOICE(stopUC, StopUnitControl_Response,  AdditionalService_Response_stopUC)
		BOOST_ASN_VALUE_CHOICE(createUC, CreateUnitControl_Response,  AdditionalService_Response_createUC)
		BOOST_ASN_VALUE_CHOICE(addToUC, AddToUnitControl_Response,  AdditionalService_Response_addToUC)
		BOOST_ASN_VALUE_CHOICE(removeFromUC, RemoveFromUnitControl_Response,  AdditionalService_Response_removeFromUC)
		BOOST_ASN_VALUE_CHOICE(getUCAttributes, GetUnitControlAttributes_Response,  AdditionalService_Response_getUCAttributes)
		BOOST_ASN_VALUE_CHOICE(loadUCFromFile, LoadUnitControlFromFile_Response,  AdditionalService_Response_loadUCFromFile)
		BOOST_ASN_VALUE_CHOICE(storeUCToFile, StoreUnitControlToFile_Response,  AdditionalService_Response_storeUCToFile)
		BOOST_ASN_VALUE_CHOICE(deleteUC, DeleteUnitControl_Response,  AdditionalService_Response_deleteUC)
		BOOST_ASN_VALUE_CHOICE(defineECL, DefineEventConditionList_Response,  AdditionalService_Response_defineECL)
		BOOST_ASN_VALUE_CHOICE(deleteECL, DeleteEventConditionList_Response,  AdditionalService_Response_deleteECL)
		BOOST_ASN_VALUE_CHOICE(addECLReference, AddEventConditionListReference_Response,  AdditionalService_Response_addECLReference)
		BOOST_ASN_VALUE_CHOICE(removeECLReference, RemoveEventConditionListReference_Response,  AdditionalService_Response_removeECLReference)
		BOOST_ASN_VALUE_CHOICE(getECLAttributes, GetEventConditionListAttributes_Response,  AdditionalService_Response_getECLAttributes)
		BOOST_ASN_VALUE_CHOICE(reportECLStatus, ReportEventConditionListStatus_Response,  AdditionalService_Response_reportECLStatus)
		BOOST_ASN_VALUE_CHOICE(alterECLMonitoring, AlterEventConditionListMonitoring_Response,  AdditionalService_Response_alterECLMonitoring)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Response > (true , AdditionalService_Response_vMDStop) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Response > (true , AdditionalService_Response_vMDReset) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Select_Response > (true , AdditionalService_Response_select) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Response > (true , AdditionalService_Response_alterPI) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Response > (true , AdditionalService_Response_initiateUCLoad) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Response > (true , AdditionalService_Response_uCLoad) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Response > (true , AdditionalService_Response_uCUpload) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Response > (true , AdditionalService_Response_startUC) ,7)) return; else free(); break;}
							case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Response > (true , AdditionalService_Response_stopUC) ,8)) return; else free(); break;}
							case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Response > (true , AdditionalService_Response_createUC) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Response > (true , AdditionalService_Response_addToUC) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Response > (true , AdditionalService_Response_removeFromUC) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Response > (true , AdditionalService_Response_getUCAttributes) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Response > (true , AdditionalService_Response_loadUCFromFile) ,13)) return; else free(); break;}
							case 14: { if(BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Response > (true , AdditionalService_Response_storeUCToFile) ,14)) return; else free(); break;}
							case 15: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Response > (true , AdditionalService_Response_deleteUC) ,15)) return; else free(); break;}
							case 16: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventConditionList_Response > (true , AdditionalService_Response_defineECL) ,16)) return; else free(); break;}
							case 17: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteEventConditionList_Response > (true , AdditionalService_Response_deleteECL) ,17)) return; else free(); break;}
							case 18: { if(BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Response > (true , AdditionalService_Response_addECLReference) ,18)) return; else free(); break;}
							case 19: { if(BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Response > (true , AdditionalService_Response_removeECLReference) ,19)) return; else free(); break;}
							case 20: { if(BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionListAttributes_Response > (true , AdditionalService_Response_getECLAttributes) ,20)) return; else free(); break;}
							case 21: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Response > (true , AdditionalService_Response_reportECLStatus) ,21)) return; else free(); break;}
							case 22: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Response > (true , AdditionalService_Response_alterECLMonitoring) ,22)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case AdditionalService_Response_vMDStop: {BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Response > (false , AdditionalService_Response_vMDStop) ,0); break;}
					case AdditionalService_Response_vMDReset: {BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Response > (false , AdditionalService_Response_vMDReset) ,1); break;}
					case AdditionalService_Response_select: {BOOST_ASN_IMPLICIT_TAG(value<Select_Response > (false , AdditionalService_Response_select) ,2); break;}
					case AdditionalService_Response_alterPI: {BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Response > (false , AdditionalService_Response_alterPI) ,3); break;}
					case AdditionalService_Response_initiateUCLoad: {BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Response > (false , AdditionalService_Response_initiateUCLoad) ,4); break;}
					case AdditionalService_Response_uCLoad: {BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Response > (false , AdditionalService_Response_uCLoad) ,5); break;}
					case AdditionalService_Response_uCUpload: {BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Response > (false , AdditionalService_Response_uCUpload) ,6); break;}
					case AdditionalService_Response_startUC: {BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Response > (false , AdditionalService_Response_startUC) ,7); break;}
					case AdditionalService_Response_stopUC: {BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Response > (false , AdditionalService_Response_stopUC) ,8); break;}
					case AdditionalService_Response_createUC: {BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Response > (false , AdditionalService_Response_createUC) ,9); break;}
					case AdditionalService_Response_addToUC: {BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Response > (false , AdditionalService_Response_addToUC) ,10); break;}
					case AdditionalService_Response_removeFromUC: {BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Response > (false , AdditionalService_Response_removeFromUC) ,11); break;}
					case AdditionalService_Response_getUCAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Response > (false , AdditionalService_Response_getUCAttributes) ,12); break;}
					case AdditionalService_Response_loadUCFromFile: {BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Response > (false , AdditionalService_Response_loadUCFromFile) ,13); break;}
					case AdditionalService_Response_storeUCToFile: {BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Response > (false , AdditionalService_Response_storeUCToFile) ,14); break;}
					case AdditionalService_Response_deleteUC: {BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Response > (false , AdditionalService_Response_deleteUC) ,15); break;}
					case AdditionalService_Response_defineECL: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventConditionList_Response > (false , AdditionalService_Response_defineECL) ,16); break;}
					case AdditionalService_Response_deleteECL: {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventConditionList_Response > (false , AdditionalService_Response_deleteECL) ,17); break;}
					case AdditionalService_Response_addECLReference: {BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Response > (false , AdditionalService_Response_addECLReference) ,18); break;}
					case AdditionalService_Response_removeECLReference: {BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Response > (false , AdditionalService_Response_removeECLReference) ,19); break;}
					case AdditionalService_Response_getECLAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionListAttributes_Response > (false , AdditionalService_Response_getECLAttributes) ,20); break;}
					case AdditionalService_Response_reportECLStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Response > (false , AdditionalService_Response_reportECLStatus) ,21); break;}
					case AdditionalService_Response_alterECLMonitoring: {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Response > (false , AdditionalService_Response_alterECLMonitoring) ,22); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum ConfirmedServiceResponse_enum {
		ConfirmedServiceResponse_null = 0  , 
		ConfirmedServiceResponse_status , 
		ConfirmedServiceResponse_getNameList , 
		ConfirmedServiceResponse_identify , 
		ConfirmedServiceResponse_rename , 
		ConfirmedServiceResponse_read , 
		ConfirmedServiceResponse_getVariableAccessAttributes , 
		ConfirmedServiceResponse_defineNamedVariable , 
		ConfirmedServiceResponse_defineScatteredAccess , 
		ConfirmedServiceResponse_getScatteredAccessAttributes , 
		ConfirmedServiceResponse_deleteVariableAccess , 
		ConfirmedServiceResponse_defineNamedVariableList , 
		ConfirmedServiceResponse_getNamedVariableListAttributes , 
		ConfirmedServiceResponse_deleteNamedVariableList , 
		ConfirmedServiceResponse_defineNamedType , 
		ConfirmedServiceResponse_getNamedTypeAttributes , 
		ConfirmedServiceResponse_deleteNamedType , 
		ConfirmedServiceResponse_input , 
		ConfirmedServiceResponse_output , 
		ConfirmedServiceResponse_takeControl , 
		ConfirmedServiceResponse_relinquishControl , 
		ConfirmedServiceResponse_defineSemaphore , 
		ConfirmedServiceResponse_deleteSemaphore , 
		ConfirmedServiceResponse_reportSemaphoreStatus , 
		ConfirmedServiceResponse_reportPoolSemaphoreStatus , 
		ConfirmedServiceResponse_reportSemaphoreEntryStatus , 
		ConfirmedServiceResponse_initiateDownloadSequence , 
		ConfirmedServiceResponse_downloadSegment , 
		ConfirmedServiceResponse_terminateDownloadSequence , 
		ConfirmedServiceResponse_initiateUploadSequence , 
		ConfirmedServiceResponse_uploadSegment , 
		ConfirmedServiceResponse_terminateUploadSequence , 
		ConfirmedServiceResponse_requestDomainDownload , 
		ConfirmedServiceResponse_requestDomainUpload , 
		ConfirmedServiceResponse_loadDomainContent , 
		ConfirmedServiceResponse_storeDomainContent , 
		ConfirmedServiceResponse_deleteDomain , 
		ConfirmedServiceResponse_getDomainAttributes , 
		ConfirmedServiceResponse_createProgramInvocation , 
		ConfirmedServiceResponse_deleteProgramInvocation , 
		ConfirmedServiceResponse_start , 
		ConfirmedServiceResponse_stop , 
		ConfirmedServiceResponse_resume , 
		ConfirmedServiceResponse_reset , 
		ConfirmedServiceResponse_kill , 
		ConfirmedServiceResponse_getProgramInvocationAttributes , 
		ConfirmedServiceResponse_obtainFile , 
		ConfirmedServiceResponse_defineEventCondition , 
		ConfirmedServiceResponse_deleteEventCondition , 
		ConfirmedServiceResponse_getEventConditionAttributes , 
		ConfirmedServiceResponse_reportEventConditionStatus , 
		ConfirmedServiceResponse_alterEventConditionMonitoring , 
		ConfirmedServiceResponse_triggerEvent , 
		ConfirmedServiceResponse_defineEventAction , 
		ConfirmedServiceResponse_deleteEventAction , 
		ConfirmedServiceResponse_getEventActionAttributes , 
		ConfirmedServiceResponse_reportEventActionStatus , 
		ConfirmedServiceResponse_defineEventEnrollment , 
		ConfirmedServiceResponse_deleteEventEnrollment , 
		ConfirmedServiceResponse_alterEventEnrollment , 
		ConfirmedServiceResponse_reportEventEnrollmentStatus , 
		ConfirmedServiceResponse_getEventEnrollmentAttributes , 
		ConfirmedServiceResponse_acknowledgeEventNotification , 
		ConfirmedServiceResponse_getAlarmSummary , 
		ConfirmedServiceResponse_getAlarmEnrollmentSummary , 
		ConfirmedServiceResponse_readJournal , 
		ConfirmedServiceResponse_writeJournal , 
		ConfirmedServiceResponse_initializeJournal , 
		ConfirmedServiceResponse_reportJournalStatus , 
		ConfirmedServiceResponse_createJournal , 
		ConfirmedServiceResponse_deleteJournal , 
		ConfirmedServiceResponse_getCapabilityList , 
		ConfirmedServiceResponse_fileOpen , 
		ConfirmedServiceResponse_fileRead , 
		ConfirmedServiceResponse_fileClose , 
		ConfirmedServiceResponse_fileRename , 
		ConfirmedServiceResponse_fileDelete , 
		ConfirmedServiceResponse_fileDirectory , 
		ConfirmedServiceResponse_additionalService , 
		ConfirmedServiceResponse_getDataExchangeAttributes , 
		ConfirmedServiceResponse_exchangeData , 
		ConfirmedServiceResponse_defineAccessControlList , 
		ConfirmedServiceResponse_getAccessControlListAttributes , 
		ConfirmedServiceResponse_reportAccessControlledObjects , 
		ConfirmedServiceResponse_deleteAccessControlList , 
		ConfirmedServiceResponse_changeAccessControl , 
	};

	struct  ConfirmedServiceResponse : public BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceResponse_enum) {



		ConfirmedServiceResponse() : BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceResponse_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(status, Status_Response,  ConfirmedServiceResponse_status)
		BOOST_ASN_VALUE_CHOICE(getNameList, GetNameList_Response,  ConfirmedServiceResponse_getNameList)
		BOOST_ASN_VALUE_CHOICE(identify, Identify_Response,  ConfirmedServiceResponse_identify)
		BOOST_ASN_VALUE_CHOICE(rename, Rename_Response,  ConfirmedServiceResponse_rename)
		BOOST_ASN_VALUE_CHOICE(read, Read_Response,  ConfirmedServiceResponse_read)
		BOOST_ASN_VALUE_CHOICE(getVariableAccessAttributes, GetVariableAccessAttributes_Response,  ConfirmedServiceResponse_getVariableAccessAttributes)
		BOOST_ASN_VALUE_CHOICE(defineNamedVariable, DefineNamedVariable_Response,  ConfirmedServiceResponse_defineNamedVariable)
		BOOST_ASN_VALUE_CHOICE(defineScatteredAccess, DefineScatteredAccess_Response,  ConfirmedServiceResponse_defineScatteredAccess)
		BOOST_ASN_VALUE_CHOICE(getScatteredAccessAttributes, GetScatteredAccessAttributes_Response,  ConfirmedServiceResponse_getScatteredAccessAttributes)
		BOOST_ASN_VALUE_CHOICE(deleteVariableAccess, DeleteVariableAccess_Response,  ConfirmedServiceResponse_deleteVariableAccess)
		BOOST_ASN_VALUE_CHOICE(defineNamedVariableList, DefineNamedVariableList_Response,  ConfirmedServiceResponse_defineNamedVariableList)
		BOOST_ASN_VALUE_CHOICE(getNamedVariableListAttributes, GetNamedVariableListAttributes_Response,  ConfirmedServiceResponse_getNamedVariableListAttributes)
		BOOST_ASN_VALUE_CHOICE(deleteNamedVariableList, DeleteNamedVariableList_Response,  ConfirmedServiceResponse_deleteNamedVariableList)
		BOOST_ASN_VALUE_CHOICE(defineNamedType, DefineNamedType_Response,  ConfirmedServiceResponse_defineNamedType)
		BOOST_ASN_VALUE_CHOICE(getNamedTypeAttributes, GetNamedTypeAttributes_Response,  ConfirmedServiceResponse_getNamedTypeAttributes)
		BOOST_ASN_VALUE_CHOICE(deleteNamedType, DeleteNamedType_Response,  ConfirmedServiceResponse_deleteNamedType)
		BOOST_ASN_VALUE_CHOICE(input, Input_Response,  ConfirmedServiceResponse_input)
		BOOST_ASN_VALUE_CHOICE(output, Output_Response,  ConfirmedServiceResponse_output)
		BOOST_ASN_VALUE_CHOICE(takeControl, TakeControl_Response,  ConfirmedServiceResponse_takeControl)
		BOOST_ASN_VALUE_CHOICE(relinquishControl, RelinquishControl_Response,  ConfirmedServiceResponse_relinquishControl)
		BOOST_ASN_VALUE_CHOICE(defineSemaphore, DefineSemaphore_Response,  ConfirmedServiceResponse_defineSemaphore)
		BOOST_ASN_VALUE_CHOICE(deleteSemaphore, DeleteSemaphore_Response,  ConfirmedServiceResponse_deleteSemaphore)
		BOOST_ASN_VALUE_CHOICE(reportSemaphoreStatus, ReportSemaphoreStatus_Response,  ConfirmedServiceResponse_reportSemaphoreStatus)
		BOOST_ASN_VALUE_CHOICE(reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Response,  ConfirmedServiceResponse_reportPoolSemaphoreStatus)
		BOOST_ASN_VALUE_CHOICE(reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Response,  ConfirmedServiceResponse_reportSemaphoreEntryStatus)
		BOOST_ASN_VALUE_CHOICE(initiateDownloadSequence, InitiateDownloadSequence_Response,  ConfirmedServiceResponse_initiateDownloadSequence)
		BOOST_ASN_VALUE_CHOICE(downloadSegment, DownloadSegment_Response,  ConfirmedServiceResponse_downloadSegment)
		BOOST_ASN_VALUE_CHOICE(terminateDownloadSequence, TerminateDownloadSequence_Response,  ConfirmedServiceResponse_terminateDownloadSequence)
		BOOST_ASN_VALUE_CHOICE(initiateUploadSequence, InitiateUploadSequence_Response,  ConfirmedServiceResponse_initiateUploadSequence)
		BOOST_ASN_VALUE_CHOICE(uploadSegment, UploadSegment_Response,  ConfirmedServiceResponse_uploadSegment)
		BOOST_ASN_VALUE_CHOICE(terminateUploadSequence, TerminateUploadSequence_Response,  ConfirmedServiceResponse_terminateUploadSequence)
		BOOST_ASN_VALUE_CHOICE(requestDomainDownload, RequestDomainDownload_Response,  ConfirmedServiceResponse_requestDomainDownload)
		BOOST_ASN_VALUE_CHOICE(requestDomainUpload, RequestDomainUpload_Response,  ConfirmedServiceResponse_requestDomainUpload)
		BOOST_ASN_VALUE_CHOICE(loadDomainContent, LoadDomainContent_Response,  ConfirmedServiceResponse_loadDomainContent)
		BOOST_ASN_VALUE_CHOICE(storeDomainContent, StoreDomainContent_Response,  ConfirmedServiceResponse_storeDomainContent)
		BOOST_ASN_VALUE_CHOICE(deleteDomain, DeleteDomain_Response,  ConfirmedServiceResponse_deleteDomain)
		BOOST_ASN_VALUE_CHOICE(getDomainAttributes, GetDomainAttributes_Response,  ConfirmedServiceResponse_getDomainAttributes)
		BOOST_ASN_VALUE_CHOICE(createProgramInvocation, CreateProgramInvocation_Response,  ConfirmedServiceResponse_createProgramInvocation)
		BOOST_ASN_VALUE_CHOICE(deleteProgramInvocation, DeleteProgramInvocation_Response,  ConfirmedServiceResponse_deleteProgramInvocation)
		BOOST_ASN_VALUE_CHOICE(start, Start_Response,  ConfirmedServiceResponse_start)
		BOOST_ASN_VALUE_CHOICE(stop, Stop_Response,  ConfirmedServiceResponse_stop)
		BOOST_ASN_VALUE_CHOICE(resume, Resume_Response,  ConfirmedServiceResponse_resume)
		BOOST_ASN_VALUE_CHOICE(reset, Reset_Response,  ConfirmedServiceResponse_reset)
		BOOST_ASN_VALUE_CHOICE(kill, Kill_Response,  ConfirmedServiceResponse_kill)
		BOOST_ASN_VALUE_CHOICE(getProgramInvocationAttributes, GetProgramInvocationAttributes_Response,  ConfirmedServiceResponse_getProgramInvocationAttributes)
		BOOST_ASN_VALUE_CHOICE(obtainFile, ObtainFile_Response,  ConfirmedServiceResponse_obtainFile)
		BOOST_ASN_VALUE_CHOICE(defineEventCondition, DefineEventCondition_Response,  ConfirmedServiceResponse_defineEventCondition)
		BOOST_ASN_VALUE_CHOICE(deleteEventCondition, DeleteEventCondition_Response,  ConfirmedServiceResponse_deleteEventCondition)
		BOOST_ASN_VALUE_CHOICE(getEventConditionAttributes, GetEventConditionAttributes_Response,  ConfirmedServiceResponse_getEventConditionAttributes)
		BOOST_ASN_VALUE_CHOICE(reportEventConditionStatus, ReportEventConditionStatus_Response,  ConfirmedServiceResponse_reportEventConditionStatus)
		BOOST_ASN_VALUE_CHOICE(alterEventConditionMonitoring, AlterEventConditionMonitoring_Response,  ConfirmedServiceResponse_alterEventConditionMonitoring)
		BOOST_ASN_VALUE_CHOICE(triggerEvent, TriggerEvent_Response,  ConfirmedServiceResponse_triggerEvent)
		BOOST_ASN_VALUE_CHOICE(defineEventAction, DefineEventAction_Response,  ConfirmedServiceResponse_defineEventAction)
		BOOST_ASN_VALUE_CHOICE(deleteEventAction, DeleteEventAction_Response,  ConfirmedServiceResponse_deleteEventAction)
		BOOST_ASN_VALUE_CHOICE(getEventActionAttributes, GetEventActionAttributes_Response,  ConfirmedServiceResponse_getEventActionAttributes)
		BOOST_ASN_VALUE_CHOICE(reportEventActionStatus, ReportEventActionStatus_Response,  ConfirmedServiceResponse_reportEventActionStatus)
		BOOST_ASN_VALUE_CHOICE(defineEventEnrollment, DefineEventEnrollment_Response,  ConfirmedServiceResponse_defineEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(deleteEventEnrollment, DeleteEventEnrollment_Response,  ConfirmedServiceResponse_deleteEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(alterEventEnrollment, AlterEventEnrollment_Response,  ConfirmedServiceResponse_alterEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Response,  ConfirmedServiceResponse_reportEventEnrollmentStatus)
		BOOST_ASN_VALUE_CHOICE(getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Response,  ConfirmedServiceResponse_getEventEnrollmentAttributes)
		BOOST_ASN_VALUE_CHOICE(acknowledgeEventNotification, AcknowledgeEventNotification_Response,  ConfirmedServiceResponse_acknowledgeEventNotification)
		BOOST_ASN_VALUE_CHOICE(getAlarmSummary, GetAlarmSummary_Response,  ConfirmedServiceResponse_getAlarmSummary)
		BOOST_ASN_VALUE_CHOICE(getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Response,  ConfirmedServiceResponse_getAlarmEnrollmentSummary)
		BOOST_ASN_VALUE_CHOICE(readJournal, ReadJournal_Response,  ConfirmedServiceResponse_readJournal)
		BOOST_ASN_VALUE_CHOICE(writeJournal, WriteJournal_Response,  ConfirmedServiceResponse_writeJournal)
		BOOST_ASN_VALUE_CHOICE(initializeJournal, InitializeJournal_Response,  ConfirmedServiceResponse_initializeJournal)
		BOOST_ASN_VALUE_CHOICE(reportJournalStatus, ReportJournalStatus_Response,  ConfirmedServiceResponse_reportJournalStatus)
		BOOST_ASN_VALUE_CHOICE(createJournal, CreateJournal_Response,  ConfirmedServiceResponse_createJournal)
		BOOST_ASN_VALUE_CHOICE(deleteJournal, DeleteJournal_Response,  ConfirmedServiceResponse_deleteJournal)
		BOOST_ASN_VALUE_CHOICE(getCapabilityList, GetCapabilityList_Response,  ConfirmedServiceResponse_getCapabilityList)
		BOOST_ASN_VALUE_CHOICE(fileOpen, FileOpen_Response,  ConfirmedServiceResponse_fileOpen)
		BOOST_ASN_VALUE_CHOICE(fileRead, FileRead_Response,  ConfirmedServiceResponse_fileRead)
		BOOST_ASN_VALUE_CHOICE(fileClose, FileClose_Response,  ConfirmedServiceResponse_fileClose)
		BOOST_ASN_VALUE_CHOICE(fileRename, FileRename_Response,  ConfirmedServiceResponse_fileRename)
		BOOST_ASN_VALUE_CHOICE(fileDelete, FileDelete_Response,  ConfirmedServiceResponse_fileDelete)
		BOOST_ASN_VALUE_CHOICE(fileDirectory, FileDirectory_Response,  ConfirmedServiceResponse_fileDirectory)
		BOOST_ASN_VALUE_CHOICE(additionalService, AdditionalService_Response,  ConfirmedServiceResponse_additionalService)
		BOOST_ASN_VALUE_CHOICE(getDataExchangeAttributes, GetDataExchangeAttributes_Response,  ConfirmedServiceResponse_getDataExchangeAttributes)
		BOOST_ASN_VALUE_CHOICE(exchangeData, ExchangeData_Response,  ConfirmedServiceResponse_exchangeData)
		BOOST_ASN_VALUE_CHOICE(defineAccessControlList, DefineAccessControlList_Response,  ConfirmedServiceResponse_defineAccessControlList)
		BOOST_ASN_VALUE_CHOICE(getAccessControlListAttributes, GetAccessControlListAttributes_Response,  ConfirmedServiceResponse_getAccessControlListAttributes)
		BOOST_ASN_VALUE_CHOICE(reportAccessControlledObjects, ReportAccessControlledObjects_Response,  ConfirmedServiceResponse_reportAccessControlledObjects)
		BOOST_ASN_VALUE_CHOICE(deleteAccessControlList, DeleteAccessControlList_Response,  ConfirmedServiceResponse_deleteAccessControlList)
		BOOST_ASN_VALUE_CHOICE(changeAccessControl, ChangeAccessControl_Response,  ConfirmedServiceResponse_changeAccessControl)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Status_Response > (true , ConfirmedServiceResponse_status) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Response > (true , ConfirmedServiceResponse_getNameList) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identify_Response > (true , ConfirmedServiceResponse_identify) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Rename_Response > (true , ConfirmedServiceResponse_rename) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<Read_Response > (true , ConfirmedServiceResponse_read) ,4)) return; else free(); break;}
							case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<GetVariableAccessAttributes_Response > (true , ConfirmedServiceResponse_getVariableAccessAttributes) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Response > (true , ConfirmedServiceResponse_defineNamedVariable) ,7)) return; else free(); break;}
							case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineScatteredAccess_Response > (true , ConfirmedServiceResponse_defineScatteredAccess) ,8)) return; else free(); break;}
							case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<GetScatteredAccessAttributes_Response > (true , ConfirmedServiceResponse_getScatteredAccessAttributes) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Response > (true , ConfirmedServiceResponse_deleteVariableAccess) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Response > (true , ConfirmedServiceResponse_defineNamedVariableList) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<GetNamedVariableListAttributes_Response > (true , ConfirmedServiceResponse_getNamedVariableListAttributes) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Response > (true , ConfirmedServiceResponse_deleteNamedVariableList) ,13)) return; else free(); break;}
							case 14: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Response > (true , ConfirmedServiceResponse_defineNamedType) ,14)) return; else free(); break;}
							case 15: { if(BOOST_ASN_IMPLICIT_TAG(value<GetNamedTypeAttributes_Response > (true , ConfirmedServiceResponse_getNamedTypeAttributes) ,15)) return; else free(); break;}
							case 16: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Response > (true , ConfirmedServiceResponse_deleteNamedType) ,16)) return; else free(); break;}
							case 17: { if(BOOST_ASN_IMPLICIT_TAG(value<Input_Response > (true , ConfirmedServiceResponse_input) ,17)) return; else free(); break;}
							case 18: { if(BOOST_ASN_IMPLICIT_TAG(value<Output_Response > (true , ConfirmedServiceResponse_output) ,18)) return; else free(); break;}
							case 19: { if(BOOST_ASN_CHOICE_TAG(value<TakeControl_Response > (true , ConfirmedServiceResponse_takeControl) ,19)) return; else free(); break;}
							case 20: { if(BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Response > (true , ConfirmedServiceResponse_relinquishControl) ,20)) return; else free(); break;}
							case 21: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Response > (true , ConfirmedServiceResponse_defineSemaphore) ,21)) return; else free(); break;}
							case 22: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteSemaphore_Response > (true , ConfirmedServiceResponse_deleteSemaphore) ,22)) return; else free(); break;}
							case 23: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreStatus_Response > (true , ConfirmedServiceResponse_reportSemaphoreStatus) ,23)) return; else free(); break;}
							case 24: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Response > (true , ConfirmedServiceResponse_reportPoolSemaphoreStatus) ,24)) return; else free(); break;}
							case 25: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Response > (true , ConfirmedServiceResponse_reportSemaphoreEntryStatus) ,25)) return; else free(); break;}
							case 26: { if(BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Response > (true , ConfirmedServiceResponse_initiateDownloadSequence) ,26)) return; else free(); break;}
							case 27: { if(BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Response > (true , ConfirmedServiceResponse_downloadSegment) ,27)) return; else free(); break;}
							case 28: { if(BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Response > (true , ConfirmedServiceResponse_terminateDownloadSequence) ,28)) return; else free(); break;}
							case 29: { if(BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Response > (true , ConfirmedServiceResponse_initiateUploadSequence) ,29)) return; else free(); break;}
							case 30: { if(BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Response > (true , ConfirmedServiceResponse_uploadSegment) ,30)) return; else free(); break;}
							case 31: { if(BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Response > (true , ConfirmedServiceResponse_terminateUploadSequence) ,31)) return; else free(); break;}
							case 32: { if(BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Response > (true , ConfirmedServiceResponse_requestDomainDownload) ,32)) return; else free(); break;}
							case 33: { if(BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Response > (true , ConfirmedServiceResponse_requestDomainUpload) ,33)) return; else free(); break;}
							case 34: { if(BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Response > (true , ConfirmedServiceResponse_loadDomainContent) ,34)) return; else free(); break;}
							case 35: { if(BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Response > (true , ConfirmedServiceResponse_storeDomainContent) ,35)) return; else free(); break;}
							case 36: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Response > (true , ConfirmedServiceResponse_deleteDomain) ,36)) return; else free(); break;}
							case 37: { if(BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Response > (true , ConfirmedServiceResponse_getDomainAttributes) ,37)) return; else free(); break;}
							case 38: { if(BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Response > (true , ConfirmedServiceResponse_createProgramInvocation) ,38)) return; else free(); break;}
							case 39: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Response > (true , ConfirmedServiceResponse_deleteProgramInvocation) ,39)) return; else free(); break;}
							case 40: { if(BOOST_ASN_IMPLICIT_TAG(value<Start_Response > (true , ConfirmedServiceResponse_start) ,40)) return; else free(); break;}
							case 41: { if(BOOST_ASN_IMPLICIT_TAG(value<Stop_Response > (true , ConfirmedServiceResponse_stop) ,41)) return; else free(); break;}
							case 42: { if(BOOST_ASN_IMPLICIT_TAG(value<Resume_Response > (true , ConfirmedServiceResponse_resume) ,42)) return; else free(); break;}
							case 43: { if(BOOST_ASN_IMPLICIT_TAG(value<Reset_Response > (true , ConfirmedServiceResponse_reset) ,43)) return; else free(); break;}
							case 44: { if(BOOST_ASN_IMPLICIT_TAG(value<Kill_Response > (true , ConfirmedServiceResponse_kill) ,44)) return; else free(); break;}
							case 45: { if(BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Response > (true , ConfirmedServiceResponse_getProgramInvocationAttributes) ,45)) return; else free(); break;}
							case 46: { if(BOOST_ASN_IMPLICIT_TAG(value<ObtainFile_Response > (true , ConfirmedServiceResponse_obtainFile) ,46)) return; else free(); break;}
							case 47: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Response > (true , ConfirmedServiceResponse_defineEventCondition) ,47)) return; else free(); break;}
							case 48: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteEventCondition_Response > (true , ConfirmedServiceResponse_deleteEventCondition) ,48)) return; else free(); break;}
							case 49: { if(BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionAttributes_Response > (true , ConfirmedServiceResponse_getEventConditionAttributes) ,49)) return; else free(); break;}
							case 50: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionStatus_Response > (true , ConfirmedServiceResponse_reportEventConditionStatus) ,50)) return; else free(); break;}
							case 51: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Response > (true , ConfirmedServiceResponse_alterEventConditionMonitoring) ,51)) return; else free(); break;}
							case 52: { if(BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Response > (true , ConfirmedServiceResponse_triggerEvent) ,52)) return; else free(); break;}
							case 53: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Response > (true , ConfirmedServiceResponse_defineEventAction) ,53)) return; else free(); break;}
							case 54: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteEventAction_Response > (true , ConfirmedServiceResponse_deleteEventAction) ,54)) return; else free(); break;}
							case 55: { if(BOOST_ASN_IMPLICIT_TAG(value<GetEventActionAttributes_Response > (true , ConfirmedServiceResponse_getEventActionAttributes) ,55)) return; else free(); break;}
							case 56: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportEventActionStatus_Response > (true , ConfirmedServiceResponse_reportEventActionStatus) ,56)) return; else free(); break;}
							case 57: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Response > (true , ConfirmedServiceResponse_defineEventEnrollment) ,57)) return; else free(); break;}
							case 58: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteEventEnrollment_Response > (true , ConfirmedServiceResponse_deleteEventEnrollment) ,58)) return; else free(); break;}
							case 59: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Response > (true , ConfirmedServiceResponse_alterEventEnrollment) ,59)) return; else free(); break;}
							case 60: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportEventEnrollmentStatus_Response > (true , ConfirmedServiceResponse_reportEventEnrollmentStatus) ,60)) return; else free(); break;}
							case 61: { if(BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Response > (true , ConfirmedServiceResponse_getEventEnrollmentAttributes) ,61)) return; else free(); break;}
							case 62: { if(BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Response > (true , ConfirmedServiceResponse_acknowledgeEventNotification) ,62)) return; else free(); break;}
							case 63: { if(BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Response > (true , ConfirmedServiceResponse_getAlarmSummary) ,63)) return; else free(); break;}
							case 64: { if(BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Response > (true , ConfirmedServiceResponse_getAlarmEnrollmentSummary) ,64)) return; else free(); break;}
							case 65: { if(BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Response > (true , ConfirmedServiceResponse_readJournal) ,65)) return; else free(); break;}
							case 66: { if(BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Response > (true , ConfirmedServiceResponse_writeJournal) ,66)) return; else free(); break;}
							case 67: { if(BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Response > (true , ConfirmedServiceResponse_initializeJournal) ,67)) return; else free(); break;}
							case 68: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportJournalStatus_Response > (true , ConfirmedServiceResponse_reportJournalStatus) ,68)) return; else free(); break;}
							case 69: { if(BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Response > (true , ConfirmedServiceResponse_createJournal) ,69)) return; else free(); break;}
							case 70: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Response > (true , ConfirmedServiceResponse_deleteJournal) ,70)) return; else free(); break;}
							case 71: { if(BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Response > (true , ConfirmedServiceResponse_getCapabilityList) ,71)) return; else free(); break;}
							case 72: { if(BOOST_ASN_IMPLICIT_TAG(value<FileOpen_Response > (true , ConfirmedServiceResponse_fileOpen) ,72)) return; else free(); break;}
							case 73: { if(BOOST_ASN_IMPLICIT_TAG(value<FileRead_Response > (true , ConfirmedServiceResponse_fileRead) ,73)) return; else free(); break;}
							case 74: { if(BOOST_ASN_IMPLICIT_TAG(value<FileClose_Response > (true , ConfirmedServiceResponse_fileClose) ,74)) return; else free(); break;}
							case 75: { if(BOOST_ASN_IMPLICIT_TAG(value<FileRename_Response > (true , ConfirmedServiceResponse_fileRename) ,75)) return; else free(); break;}
							case 76: { if(BOOST_ASN_IMPLICIT_TAG(value<FileDelete_Response > (true , ConfirmedServiceResponse_fileDelete) ,76)) return; else free(); break;}
							case 77: { if(BOOST_ASN_IMPLICIT_TAG(value<FileDirectory_Response > (true , ConfirmedServiceResponse_fileDirectory) ,77)) return; else free(); break;}
							case 78: { if(BOOST_ASN_CHOICE_TAG(value<AdditionalService_Response > (true , ConfirmedServiceResponse_additionalService) ,78)) return; else free(); break;}
							case 80: { if(BOOST_ASN_EXPLICIT_TAG(value<GetDataExchangeAttributes_Response > (true , ConfirmedServiceResponse_getDataExchangeAttributes) ,80)) return; else free(); break;}
							case 81: { if(BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Response > (true , ConfirmedServiceResponse_exchangeData) ,81)) return; else free(); break;}
							case 82: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Response > (true , ConfirmedServiceResponse_defineAccessControlList) ,82)) return; else free(); break;}
							case 83: { if(BOOST_ASN_IMPLICIT_TAG(value<GetAccessControlListAttributes_Response > (true , ConfirmedServiceResponse_getAccessControlListAttributes) ,83)) return; else free(); break;}
							case 84: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Response > (true , ConfirmedServiceResponse_reportAccessControlledObjects) ,84)) return; else free(); break;}
							case 85: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Response > (true , ConfirmedServiceResponse_deleteAccessControlList) ,85)) return; else free(); break;}
							case 86: { if(BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Response > (true , ConfirmedServiceResponse_changeAccessControl) ,86)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case ConfirmedServiceResponse_status: {BOOST_ASN_IMPLICIT_TAG(value<Status_Response > (false , ConfirmedServiceResponse_status) ,0); break;}
					case ConfirmedServiceResponse_getNameList: {BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Response > (false , ConfirmedServiceResponse_getNameList) ,1); break;}
					case ConfirmedServiceResponse_identify: {BOOST_ASN_IMPLICIT_TAG(value<Identify_Response > (false , ConfirmedServiceResponse_identify) ,2); break;}
					case ConfirmedServiceResponse_rename: {BOOST_ASN_IMPLICIT_TAG(value<Rename_Response > (false , ConfirmedServiceResponse_rename) ,3); break;}
					case ConfirmedServiceResponse_read: {BOOST_ASN_IMPLICIT_TAG(value<Read_Response > (false , ConfirmedServiceResponse_read) ,4); break;}
					case ConfirmedServiceResponse_getVariableAccessAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetVariableAccessAttributes_Response > (false , ConfirmedServiceResponse_getVariableAccessAttributes) ,6); break;}
					case ConfirmedServiceResponse_defineNamedVariable: {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Response > (false , ConfirmedServiceResponse_defineNamedVariable) ,7); break;}
					case ConfirmedServiceResponse_defineScatteredAccess: {BOOST_ASN_IMPLICIT_TAG(value<DefineScatteredAccess_Response > (false , ConfirmedServiceResponse_defineScatteredAccess) ,8); break;}
					case ConfirmedServiceResponse_getScatteredAccessAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetScatteredAccessAttributes_Response > (false , ConfirmedServiceResponse_getScatteredAccessAttributes) ,9); break;}
					case ConfirmedServiceResponse_deleteVariableAccess: {BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Response > (false , ConfirmedServiceResponse_deleteVariableAccess) ,10); break;}
					case ConfirmedServiceResponse_defineNamedVariableList: {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Response > (false , ConfirmedServiceResponse_defineNamedVariableList) ,11); break;}
					case ConfirmedServiceResponse_getNamedVariableListAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetNamedVariableListAttributes_Response > (false , ConfirmedServiceResponse_getNamedVariableListAttributes) ,12); break;}
					case ConfirmedServiceResponse_deleteNamedVariableList: {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Response > (false , ConfirmedServiceResponse_deleteNamedVariableList) ,13); break;}
					case ConfirmedServiceResponse_defineNamedType: {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Response > (false , ConfirmedServiceResponse_defineNamedType) ,14); break;}
					case ConfirmedServiceResponse_getNamedTypeAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetNamedTypeAttributes_Response > (false , ConfirmedServiceResponse_getNamedTypeAttributes) ,15); break;}
					case ConfirmedServiceResponse_deleteNamedType: {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Response > (false , ConfirmedServiceResponse_deleteNamedType) ,16); break;}
					case ConfirmedServiceResponse_input: {BOOST_ASN_IMPLICIT_TAG(value<Input_Response > (false , ConfirmedServiceResponse_input) ,17); break;}
					case ConfirmedServiceResponse_output: {BOOST_ASN_IMPLICIT_TAG(value<Output_Response > (false , ConfirmedServiceResponse_output) ,18); break;}
					case ConfirmedServiceResponse_takeControl: {BOOST_ASN_CHOICE_TAG(value<TakeControl_Response > (false , ConfirmedServiceResponse_takeControl) ,19); break;}
					case ConfirmedServiceResponse_relinquishControl: {BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Response > (false , ConfirmedServiceResponse_relinquishControl) ,20); break;}
					case ConfirmedServiceResponse_defineSemaphore: {BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Response > (false , ConfirmedServiceResponse_defineSemaphore) ,21); break;}
					case ConfirmedServiceResponse_deleteSemaphore: {BOOST_ASN_IMPLICIT_TAG(value<DeleteSemaphore_Response > (false , ConfirmedServiceResponse_deleteSemaphore) ,22); break;}
					case ConfirmedServiceResponse_reportSemaphoreStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreStatus_Response > (false , ConfirmedServiceResponse_reportSemaphoreStatus) ,23); break;}
					case ConfirmedServiceResponse_reportPoolSemaphoreStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Response > (false , ConfirmedServiceResponse_reportPoolSemaphoreStatus) ,24); break;}
					case ConfirmedServiceResponse_reportSemaphoreEntryStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Response > (false , ConfirmedServiceResponse_reportSemaphoreEntryStatus) ,25); break;}
					case ConfirmedServiceResponse_initiateDownloadSequence: {BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Response > (false , ConfirmedServiceResponse_initiateDownloadSequence) ,26); break;}
					case ConfirmedServiceResponse_downloadSegment: {BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Response > (false , ConfirmedServiceResponse_downloadSegment) ,27); break;}
					case ConfirmedServiceResponse_terminateDownloadSequence: {BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Response > (false , ConfirmedServiceResponse_terminateDownloadSequence) ,28); break;}
					case ConfirmedServiceResponse_initiateUploadSequence: {BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Response > (false , ConfirmedServiceResponse_initiateUploadSequence) ,29); break;}
					case ConfirmedServiceResponse_uploadSegment: {BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Response > (false , ConfirmedServiceResponse_uploadSegment) ,30); break;}
					case ConfirmedServiceResponse_terminateUploadSequence: {BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Response > (false , ConfirmedServiceResponse_terminateUploadSequence) ,31); break;}
					case ConfirmedServiceResponse_requestDomainDownload: {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Response > (false , ConfirmedServiceResponse_requestDomainDownload) ,32); break;}
					case ConfirmedServiceResponse_requestDomainUpload: {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Response > (false , ConfirmedServiceResponse_requestDomainUpload) ,33); break;}
					case ConfirmedServiceResponse_loadDomainContent: {BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Response > (false , ConfirmedServiceResponse_loadDomainContent) ,34); break;}
					case ConfirmedServiceResponse_storeDomainContent: {BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Response > (false , ConfirmedServiceResponse_storeDomainContent) ,35); break;}
					case ConfirmedServiceResponse_deleteDomain: {BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Response > (false , ConfirmedServiceResponse_deleteDomain) ,36); break;}
					case ConfirmedServiceResponse_getDomainAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Response > (false , ConfirmedServiceResponse_getDomainAttributes) ,37); break;}
					case ConfirmedServiceResponse_createProgramInvocation: {BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Response > (false , ConfirmedServiceResponse_createProgramInvocation) ,38); break;}
					case ConfirmedServiceResponse_deleteProgramInvocation: {BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Response > (false , ConfirmedServiceResponse_deleteProgramInvocation) ,39); break;}
					case ConfirmedServiceResponse_start: {BOOST_ASN_IMPLICIT_TAG(value<Start_Response > (false , ConfirmedServiceResponse_start) ,40); break;}
					case ConfirmedServiceResponse_stop: {BOOST_ASN_IMPLICIT_TAG(value<Stop_Response > (false , ConfirmedServiceResponse_stop) ,41); break;}
					case ConfirmedServiceResponse_resume: {BOOST_ASN_IMPLICIT_TAG(value<Resume_Response > (false , ConfirmedServiceResponse_resume) ,42); break;}
					case ConfirmedServiceResponse_reset: {BOOST_ASN_IMPLICIT_TAG(value<Reset_Response > (false , ConfirmedServiceResponse_reset) ,43); break;}
					case ConfirmedServiceResponse_kill: {BOOST_ASN_IMPLICIT_TAG(value<Kill_Response > (false , ConfirmedServiceResponse_kill) ,44); break;}
					case ConfirmedServiceResponse_getProgramInvocationAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Response > (false , ConfirmedServiceResponse_getProgramInvocationAttributes) ,45); break;}
					case ConfirmedServiceResponse_obtainFile: {BOOST_ASN_IMPLICIT_TAG(value<ObtainFile_Response > (false , ConfirmedServiceResponse_obtainFile) ,46); break;}
					case ConfirmedServiceResponse_defineEventCondition: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Response > (false , ConfirmedServiceResponse_defineEventCondition) ,47); break;}
					case ConfirmedServiceResponse_deleteEventCondition: {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventCondition_Response > (false , ConfirmedServiceResponse_deleteEventCondition) ,48); break;}
					case ConfirmedServiceResponse_getEventConditionAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionAttributes_Response > (false , ConfirmedServiceResponse_getEventConditionAttributes) ,49); break;}
					case ConfirmedServiceResponse_reportEventConditionStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionStatus_Response > (false , ConfirmedServiceResponse_reportEventConditionStatus) ,50); break;}
					case ConfirmedServiceResponse_alterEventConditionMonitoring: {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Response > (false , ConfirmedServiceResponse_alterEventConditionMonitoring) ,51); break;}
					case ConfirmedServiceResponse_triggerEvent: {BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Response > (false , ConfirmedServiceResponse_triggerEvent) ,52); break;}
					case ConfirmedServiceResponse_defineEventAction: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Response > (false , ConfirmedServiceResponse_defineEventAction) ,53); break;}
					case ConfirmedServiceResponse_deleteEventAction: {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventAction_Response > (false , ConfirmedServiceResponse_deleteEventAction) ,54); break;}
					case ConfirmedServiceResponse_getEventActionAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetEventActionAttributes_Response > (false , ConfirmedServiceResponse_getEventActionAttributes) ,55); break;}
					case ConfirmedServiceResponse_reportEventActionStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportEventActionStatus_Response > (false , ConfirmedServiceResponse_reportEventActionStatus) ,56); break;}
					case ConfirmedServiceResponse_defineEventEnrollment: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Response > (false , ConfirmedServiceResponse_defineEventEnrollment) ,57); break;}
					case ConfirmedServiceResponse_deleteEventEnrollment: {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventEnrollment_Response > (false , ConfirmedServiceResponse_deleteEventEnrollment) ,58); break;}
					case ConfirmedServiceResponse_alterEventEnrollment: {BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Response > (false , ConfirmedServiceResponse_alterEventEnrollment) ,59); break;}
					case ConfirmedServiceResponse_reportEventEnrollmentStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportEventEnrollmentStatus_Response > (false , ConfirmedServiceResponse_reportEventEnrollmentStatus) ,60); break;}
					case ConfirmedServiceResponse_getEventEnrollmentAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Response > (false , ConfirmedServiceResponse_getEventEnrollmentAttributes) ,61); break;}
					case ConfirmedServiceResponse_acknowledgeEventNotification: {BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Response > (false , ConfirmedServiceResponse_acknowledgeEventNotification) ,62); break;}
					case ConfirmedServiceResponse_getAlarmSummary: {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Response > (false , ConfirmedServiceResponse_getAlarmSummary) ,63); break;}
					case ConfirmedServiceResponse_getAlarmEnrollmentSummary: {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Response > (false , ConfirmedServiceResponse_getAlarmEnrollmentSummary) ,64); break;}
					case ConfirmedServiceResponse_readJournal: {BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Response > (false , ConfirmedServiceResponse_readJournal) ,65); break;}
					case ConfirmedServiceResponse_writeJournal: {BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Response > (false , ConfirmedServiceResponse_writeJournal) ,66); break;}
					case ConfirmedServiceResponse_initializeJournal: {BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Response > (false , ConfirmedServiceResponse_initializeJournal) ,67); break;}
					case ConfirmedServiceResponse_reportJournalStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportJournalStatus_Response > (false , ConfirmedServiceResponse_reportJournalStatus) ,68); break;}
					case ConfirmedServiceResponse_createJournal: {BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Response > (false , ConfirmedServiceResponse_createJournal) ,69); break;}
					case ConfirmedServiceResponse_deleteJournal: {BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Response > (false , ConfirmedServiceResponse_deleteJournal) ,70); break;}
					case ConfirmedServiceResponse_getCapabilityList: {BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Response > (false , ConfirmedServiceResponse_getCapabilityList) ,71); break;}
					case ConfirmedServiceResponse_fileOpen: {BOOST_ASN_IMPLICIT_TAG(value<FileOpen_Response > (false , ConfirmedServiceResponse_fileOpen) ,72); break;}
					case ConfirmedServiceResponse_fileRead: {BOOST_ASN_IMPLICIT_TAG(value<FileRead_Response > (false , ConfirmedServiceResponse_fileRead) ,73); break;}
					case ConfirmedServiceResponse_fileClose: {BOOST_ASN_IMPLICIT_TAG(value<FileClose_Response > (false , ConfirmedServiceResponse_fileClose) ,74); break;}
					case ConfirmedServiceResponse_fileRename: {BOOST_ASN_IMPLICIT_TAG(value<FileRename_Response > (false , ConfirmedServiceResponse_fileRename) ,75); break;}
					case ConfirmedServiceResponse_fileDelete: {BOOST_ASN_IMPLICIT_TAG(value<FileDelete_Response > (false , ConfirmedServiceResponse_fileDelete) ,76); break;}
					case ConfirmedServiceResponse_fileDirectory: {BOOST_ASN_IMPLICIT_TAG(value<FileDirectory_Response > (false , ConfirmedServiceResponse_fileDirectory) ,77); break;}
					case ConfirmedServiceResponse_additionalService: {BOOST_ASN_CHOICE_TAG(value<AdditionalService_Response > (false , ConfirmedServiceResponse_additionalService) ,78); break;}
					case ConfirmedServiceResponse_getDataExchangeAttributes: {BOOST_ASN_EXPLICIT_TAG(value<GetDataExchangeAttributes_Response > (false , ConfirmedServiceResponse_getDataExchangeAttributes) ,80); break;}
					case ConfirmedServiceResponse_exchangeData: {BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Response > (false , ConfirmedServiceResponse_exchangeData) ,81); break;}
					case ConfirmedServiceResponse_defineAccessControlList: {BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Response > (false , ConfirmedServiceResponse_defineAccessControlList) ,82); break;}
					case ConfirmedServiceResponse_getAccessControlListAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetAccessControlListAttributes_Response > (false , ConfirmedServiceResponse_getAccessControlListAttributes) ,83); break;}
					case ConfirmedServiceResponse_reportAccessControlledObjects: {BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Response > (false , ConfirmedServiceResponse_reportAccessControlledObjects) ,84); break;}
					case ConfirmedServiceResponse_deleteAccessControlList: {BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Response > (false , ConfirmedServiceResponse_deleteAccessControlList) ,85); break;}
					case ConfirmedServiceResponse_changeAccessControl: {BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Response > (false , ConfirmedServiceResponse_changeAccessControl) ,86); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  Confirmed_ResponsePDU{


		boost::asn1::value_holder<Unsigned32 >  invokeID;
		boost::asn1::value_holder<ConfirmedServiceResponse >  service;
		boost::shared_ptr<Response_Detail >  service_ext;

		Confirmed_ResponsePDU()  : invokeID() , service() , service_ext()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_BIND_TAG(invokeID);
			BOOST_ASN_CHOICE(service);
			BOOST_ASN_EXTENTION;
			BOOST_ASN_CHOICE_TAG(service_ext ,79);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum Unconfirmed_Detail_enum {
		Unconfirmed_Detail_null = 0  , 
		Unconfirmed_Detail_otherRequests , 
		Unconfirmed_Detail_eventNotification , 
	};

	struct  Unconfirmed_Detail : public BOOST_ASN_CHOICE_STRUCT(Unconfirmed_Detail_enum) {



		Unconfirmed_Detail() : BOOST_ASN_CHOICE_STRUCT(Unconfirmed_Detail_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(otherRequests, null_type,  Unconfirmed_Detail_otherRequests)
		BOOST_ASN_VALUE_CHOICE(eventNotification, CS_EventNotification,  Unconfirmed_Detail_eventNotification)

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
							case 2: { if(BOOST_ASN_BIND_TAG(value<CS_EventNotification > (true , Unconfirmed_Detail_eventNotification))) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , Unconfirmed_Detail_otherRequests))) return; else free();
					;}}}
			else {
				 switch(type()){
					case Unconfirmed_Detail_otherRequests: {BOOST_ASN_BIND_TAG(value<null_type > (false , Unconfirmed_Detail_otherRequests)); break;}
					case Unconfirmed_Detail_eventNotification: {BOOST_ASN_BIND_TAG(value<CS_EventNotification > (false , Unconfirmed_Detail_eventNotification)); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum UnconfirmedService_enum {
		UnconfirmedService_null = 0  , 
		UnconfirmedService_informationReport , 
		UnconfirmedService_unsolicitedStatus , 
		UnconfirmedService_eventNotification , 
	};

	struct  UnconfirmedService : public BOOST_ASN_CHOICE_STRUCT(UnconfirmedService_enum) {


		UnconfirmedService() : BOOST_ASN_CHOICE_STRUCT(UnconfirmedService_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(informationReport, InformationReport,  UnconfirmedService_informationReport)
		BOOST_ASN_VALUE_CHOICE(unsolicitedStatus, UnsolicitedStatus,  UnconfirmedService_unsolicitedStatus)
		BOOST_ASN_VALUE_CHOICE(eventNotification, EventNotification,  UnconfirmedService_eventNotification)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<InformationReport > (true , UnconfirmedService_informationReport) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<UnsolicitedStatus > (true , UnconfirmedService_unsolicitedStatus) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<EventNotification > (true , UnconfirmedService_eventNotification) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case UnconfirmedService_informationReport: {BOOST_ASN_IMPLICIT_TAG(value<InformationReport > (false , UnconfirmedService_informationReport) ,0); break;}
					case UnconfirmedService_unsolicitedStatus: {BOOST_ASN_IMPLICIT_TAG(value<UnsolicitedStatus > (false , UnconfirmedService_unsolicitedStatus) ,1); break;}
					case UnconfirmedService_eventNotification: {BOOST_ASN_IMPLICIT_TAG(value<EventNotification > (false , UnconfirmedService_eventNotification) ,2); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  Unconfirmed_PDU{


		boost::asn1::value_holder<UnconfirmedService >  service;
		boost::asn1::value_holder<Unconfirmed_Detail >  service_ext;

		Unconfirmed_PDU()  : service() , service_ext()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(service);
			BOOST_ASN_EXTENTION;
			BOOST_ASN_CHOICE_TAG(service_ext ,79);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum Request_Detail_enum {
		Request_Detail_null = 0  , 
		Request_Detail_otherRequests , 
		Request_Detail_createProgramInvocation , 
		Request_Detail_start , 
		Request_Detail_resume , 
		Request_Detail_defineEventCondition , 
		Request_Detail_alterEventConditionMonitoring , 
		Request_Detail_defineEventEnrollment , 
		Request_Detail_alterEventEnrollment , 
	};

	struct  Request_Detail : public BOOST_ASN_CHOICE_STRUCT(Request_Detail_enum) {



		Request_Detail() : BOOST_ASN_CHOICE_STRUCT(Request_Detail_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(otherRequests, null_type,  Request_Detail_otherRequests)
		BOOST_ASN_VALUE_CHOICE(createProgramInvocation, CS_CreateProgramInvocation_Request,  Request_Detail_createProgramInvocation)
		BOOST_ASN_VALUE_CHOICE(start, CS_Start_Request,  Request_Detail_start)
		BOOST_ASN_VALUE_CHOICE(resume, CS_Resume_Request,  Request_Detail_resume)
		BOOST_ASN_VALUE_CHOICE(defineEventCondition, CS_DefineEventCondition_Request,  Request_Detail_defineEventCondition)
		BOOST_ASN_VALUE_CHOICE(alterEventConditionMonitoring, CS_AlterEventConditionMonitoring_Request,  Request_Detail_alterEventConditionMonitoring)
		BOOST_ASN_VALUE_CHOICE(defineEventEnrollment, CS_DefineEventEnrollment_Request,  Request_Detail_defineEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(alterEventEnrollment, CS_AlterEventEnrollment_Request,  Request_Detail_alterEventEnrollment)

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
							case 38: { if(BOOST_ASN_IMPLICIT_TAG(value<CS_CreateProgramInvocation_Request > (true , Request_Detail_createProgramInvocation) ,38)) return; else free(); break;}
							case 40: { if(BOOST_ASN_BIND_TAG(value<CS_Start_Request > (true , Request_Detail_start))) return; else free(); break;}
							case 42: { if(BOOST_ASN_BIND_TAG(value<CS_Resume_Request > (true , Request_Detail_resume))) return; else free(); break;}
							case 47: { if(BOOST_ASN_BIND_TAG(value<CS_DefineEventCondition_Request > (true , Request_Detail_defineEventCondition))) return; else free(); break;}
							case 51: { if(BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventConditionMonitoring_Request > (true , Request_Detail_alterEventConditionMonitoring) ,51)) return; else free(); break;}
							case 57: { if(BOOST_ASN_BIND_TAG(value<CS_DefineEventEnrollment_Request > (true , Request_Detail_defineEventEnrollment))) return; else free(); break;}
							case 59: { if(BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventEnrollment_Request > (true , Request_Detail_alterEventEnrollment) ,59)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , Request_Detail_otherRequests))) return; else free();
					;}}}
			else {
				 switch(type()){
					case Request_Detail_otherRequests: {BOOST_ASN_BIND_TAG(value<null_type > (false , Request_Detail_otherRequests)); break;}
					case Request_Detail_createProgramInvocation: {BOOST_ASN_IMPLICIT_TAG(value<CS_CreateProgramInvocation_Request > (false , Request_Detail_createProgramInvocation) ,38); break;}
					case Request_Detail_start: {BOOST_ASN_BIND_TAG(value<CS_Start_Request > (false , Request_Detail_start)); break;}
					case Request_Detail_resume: {BOOST_ASN_BIND_TAG(value<CS_Resume_Request > (false , Request_Detail_resume)); break;}
					case Request_Detail_defineEventCondition: {BOOST_ASN_BIND_TAG(value<CS_DefineEventCondition_Request > (false , Request_Detail_defineEventCondition)); break;}
					case Request_Detail_alterEventConditionMonitoring: {BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventConditionMonitoring_Request > (false , Request_Detail_alterEventConditionMonitoring) ,51); break;}
					case Request_Detail_defineEventEnrollment: {BOOST_ASN_BIND_TAG(value<CS_DefineEventEnrollment_Request > (false , Request_Detail_defineEventEnrollment)); break;}
					case Request_Detail_alterEventEnrollment: {BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventEnrollment_Request > (false , Request_Detail_alterEventEnrollment) ,59); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum AdditionalService_Request_enum {
		AdditionalService_Request_null = 0  , 
		AdditionalService_Request_vMDStop , 
		AdditionalService_Request_vMDReset , 
		AdditionalService_Request_select , 
		AdditionalService_Request_alterPI , 
		AdditionalService_Request_initiateUCLoad , 
		AdditionalService_Request_uCLoad , 
		AdditionalService_Request_uCUpload , 
		AdditionalService_Request_startUC , 
		AdditionalService_Request_stopUC , 
		AdditionalService_Request_createUC , 
		AdditionalService_Request_addToUC , 
		AdditionalService_Request_removeFromUC , 
		AdditionalService_Request_getUCAttributes , 
		AdditionalService_Request_loadUCFromFile , 
		AdditionalService_Request_storeUCToFile , 
		AdditionalService_Request_deleteUC , 
		AdditionalService_Request_defineECL , 
		AdditionalService_Request_deleteECL , 
		AdditionalService_Request_addECLReference , 
		AdditionalService_Request_removeECLReference , 
		AdditionalService_Request_getECLAttributes , 
		AdditionalService_Request_reportECLStatus , 
		AdditionalService_Request_alterECLMonitoring , 
	};

	struct  AdditionalService_Request : public BOOST_ASN_CHOICE_STRUCT(AdditionalService_Request_enum) {


		AdditionalService_Request() : BOOST_ASN_CHOICE_STRUCT(AdditionalService_Request_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(vMDStop, VMDStop_Request,  AdditionalService_Request_vMDStop)
		BOOST_ASN_VALUE_CHOICE(vMDReset, VMDReset_Request,  AdditionalService_Request_vMDReset)
		BOOST_ASN_VALUE_CHOICE(select, Select_Request,  AdditionalService_Request_select)
		BOOST_ASN_VALUE_CHOICE(alterPI, AlterProgramInvocationAttributes_Request,  AdditionalService_Request_alterPI)
		BOOST_ASN_VALUE_CHOICE(initiateUCLoad, InitiateUnitControlLoad_Request,  AdditionalService_Request_initiateUCLoad)
		BOOST_ASN_VALUE_CHOICE(uCLoad, UnitControlLoadSegment_Request,  AdditionalService_Request_uCLoad)
		BOOST_ASN_VALUE_CHOICE(uCUpload, UnitControlUpload_Request,  AdditionalService_Request_uCUpload)
		BOOST_ASN_VALUE_CHOICE(startUC, StartUnitControl_Request,  AdditionalService_Request_startUC)
		BOOST_ASN_VALUE_CHOICE(stopUC, StopUnitControl_Request,  AdditionalService_Request_stopUC)
		BOOST_ASN_VALUE_CHOICE(createUC, CreateUnitControl_Request,  AdditionalService_Request_createUC)
		BOOST_ASN_VALUE_CHOICE(addToUC, AddToUnitControl_Request,  AdditionalService_Request_addToUC)
		BOOST_ASN_VALUE_CHOICE(removeFromUC, RemoveFromUnitControl_Request,  AdditionalService_Request_removeFromUC)
		BOOST_ASN_VALUE_CHOICE(getUCAttributes, GetUnitControlAttributes_Request,  AdditionalService_Request_getUCAttributes)
		BOOST_ASN_VALUE_CHOICE(loadUCFromFile, LoadUnitControlFromFile_Request,  AdditionalService_Request_loadUCFromFile)
		BOOST_ASN_VALUE_CHOICE(storeUCToFile, StoreUnitControlToFile_Request,  AdditionalService_Request_storeUCToFile)
		BOOST_ASN_VALUE_CHOICE(deleteUC, DeleteUnitControl_Request,  AdditionalService_Request_deleteUC)
		BOOST_ASN_VALUE_CHOICE(defineECL, DefineEventConditionList_Request,  AdditionalService_Request_defineECL)
		BOOST_ASN_VALUE_CHOICE(deleteECL, DeleteEventConditionList_Request,  AdditionalService_Request_deleteECL)
		BOOST_ASN_VALUE_CHOICE(addECLReference, AddEventConditionListReference_Request,  AdditionalService_Request_addECLReference)
		BOOST_ASN_VALUE_CHOICE(removeECLReference, RemoveEventConditionListReference_Request,  AdditionalService_Request_removeECLReference)
		BOOST_ASN_VALUE_CHOICE(getECLAttributes, GetEventConditionListAttributes_Request,  AdditionalService_Request_getECLAttributes)
		BOOST_ASN_VALUE_CHOICE(reportECLStatus, ReportEventConditionListStatus_Request,  AdditionalService_Request_reportECLStatus)
		BOOST_ASN_VALUE_CHOICE(alterECLMonitoring, AlterEventConditionListMonitoring_Request,  AdditionalService_Request_alterECLMonitoring)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Request > (true , AdditionalService_Request_vMDStop) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Request > (true , AdditionalService_Request_vMDReset) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Select_Request > (true , AdditionalService_Request_select) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Request > (true , AdditionalService_Request_alterPI) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Request > (true , AdditionalService_Request_initiateUCLoad) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Request > (true , AdditionalService_Request_uCLoad) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Request > (true , AdditionalService_Request_uCUpload) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Request > (true , AdditionalService_Request_startUC) ,7)) return; else free(); break;}
							case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Request > (true , AdditionalService_Request_stopUC) ,8)) return; else free(); break;}
							case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Request > (true , AdditionalService_Request_createUC) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Request > (true , AdditionalService_Request_addToUC) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Request > (true , AdditionalService_Request_removeFromUC) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Request > (true , AdditionalService_Request_getUCAttributes) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Request > (true , AdditionalService_Request_loadUCFromFile) ,13)) return; else free(); break;}
							case 14: { if(BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Request > (true , AdditionalService_Request_storeUCToFile) ,14)) return; else free(); break;}
							case 15: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Request > (true , AdditionalService_Request_deleteUC) ,15)) return; else free(); break;}
							case 16: { if(BOOST_ASN_EXPLICIT_TAG(value<DefineEventConditionList_Request > (true , AdditionalService_Request_defineECL) ,16)) return; else free(); break;}
							case 17: { if(BOOST_ASN_CHOICE_TAG(value<DeleteEventConditionList_Request > (true , AdditionalService_Request_deleteECL) ,17)) return; else free(); break;}
							case 18: { if(BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Request > (true , AdditionalService_Request_addECLReference) ,18)) return; else free(); break;}
							case 19: { if(BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Request > (true , AdditionalService_Request_removeECLReference) ,19)) return; else free(); break;}
							case 20: { if(BOOST_ASN_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (true , AdditionalService_Request_getECLAttributes) ,20)) return; else free(); break;}
							case 21: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Request > (true , AdditionalService_Request_reportECLStatus) ,21)) return; else free(); break;}
							case 22: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Request > (true , AdditionalService_Request_alterECLMonitoring) ,22)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case AdditionalService_Request_vMDStop: {BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Request > (false , AdditionalService_Request_vMDStop) ,0); break;}
					case AdditionalService_Request_vMDReset: {BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Request > (false , AdditionalService_Request_vMDReset) ,1); break;}
					case AdditionalService_Request_select: {BOOST_ASN_IMPLICIT_TAG(value<Select_Request > (false , AdditionalService_Request_select) ,2); break;}
					case AdditionalService_Request_alterPI: {BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Request > (false , AdditionalService_Request_alterPI) ,3); break;}
					case AdditionalService_Request_initiateUCLoad: {BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Request > (false , AdditionalService_Request_initiateUCLoad) ,4); break;}
					case AdditionalService_Request_uCLoad: {BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Request > (false , AdditionalService_Request_uCLoad) ,5); break;}
					case AdditionalService_Request_uCUpload: {BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Request > (false , AdditionalService_Request_uCUpload) ,6); break;}
					case AdditionalService_Request_startUC: {BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Request > (false , AdditionalService_Request_startUC) ,7); break;}
					case AdditionalService_Request_stopUC: {BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Request > (false , AdditionalService_Request_stopUC) ,8); break;}
					case AdditionalService_Request_createUC: {BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Request > (false , AdditionalService_Request_createUC) ,9); break;}
					case AdditionalService_Request_addToUC: {BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Request > (false , AdditionalService_Request_addToUC) ,10); break;}
					case AdditionalService_Request_removeFromUC: {BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Request > (false , AdditionalService_Request_removeFromUC) ,11); break;}
					case AdditionalService_Request_getUCAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Request > (false , AdditionalService_Request_getUCAttributes) ,12); break;}
					case AdditionalService_Request_loadUCFromFile: {BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Request > (false , AdditionalService_Request_loadUCFromFile) ,13); break;}
					case AdditionalService_Request_storeUCToFile: {BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Request > (false , AdditionalService_Request_storeUCToFile) ,14); break;}
					case AdditionalService_Request_deleteUC: {BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Request > (false , AdditionalService_Request_deleteUC) ,15); break;}
					case AdditionalService_Request_defineECL: {BOOST_ASN_EXPLICIT_TAG(value<DefineEventConditionList_Request > (false , AdditionalService_Request_defineECL) ,16); break;}
					case AdditionalService_Request_deleteECL: {BOOST_ASN_CHOICE_TAG(value<DeleteEventConditionList_Request > (false , AdditionalService_Request_deleteECL) ,17); break;}
					case AdditionalService_Request_addECLReference: {BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Request > (false , AdditionalService_Request_addECLReference) ,18); break;}
					case AdditionalService_Request_removeECLReference: {BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Request > (false , AdditionalService_Request_removeECLReference) ,19); break;}
					case AdditionalService_Request_getECLAttributes: {BOOST_ASN_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (false , AdditionalService_Request_getECLAttributes) ,20); break;}
					case AdditionalService_Request_reportECLStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Request > (false , AdditionalService_Request_reportECLStatus) ,21); break;}
					case AdditionalService_Request_alterECLMonitoring: {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Request > (false , AdditionalService_Request_alterECLMonitoring) ,22); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum ConfirmedServiceRequest_enum {
		ConfirmedServiceRequest_null = 0  , 
		ConfirmedServiceRequest_status , 
		ConfirmedServiceRequest_getNameList , 
		ConfirmedServiceRequest_identify , 
		ConfirmedServiceRequest_rename , 
		ConfirmedServiceRequest_read , 
		ConfirmedServiceRequest_write , 
		ConfirmedServiceRequest_getVariableAccessAttributes , 
		ConfirmedServiceRequest_defineNamedVariable , 
		ConfirmedServiceRequest_defineScatteredAccess , 
		ConfirmedServiceRequest_getScatteredAccessAttributes , 
		ConfirmedServiceRequest_deleteVariableAccess , 
		ConfirmedServiceRequest_defineNamedVariableList , 
		ConfirmedServiceRequest_getNamedVariableListAttributes , 
		ConfirmedServiceRequest_deleteNamedVariableList , 
		ConfirmedServiceRequest_defineNamedType , 
		ConfirmedServiceRequest_getNamedTypeAttributes , 
		ConfirmedServiceRequest_deleteNamedType , 
		ConfirmedServiceRequest_input , 
		ConfirmedServiceRequest_output , 
		ConfirmedServiceRequest_takeControl , 
		ConfirmedServiceRequest_relinquishControl , 
		ConfirmedServiceRequest_defineSemaphore , 
		ConfirmedServiceRequest_deleteSemaphore , 
		ConfirmedServiceRequest_reportSemaphoreStatus , 
		ConfirmedServiceRequest_reportPoolSemaphoreStatus , 
		ConfirmedServiceRequest_reportSemaphoreEntryStatus , 
		ConfirmedServiceRequest_initiateDownloadSequence , 
		ConfirmedServiceRequest_downloadSegment , 
		ConfirmedServiceRequest_terminateDownloadSequence , 
		ConfirmedServiceRequest_initiateUploadSequence , 
		ConfirmedServiceRequest_uploadSegment , 
		ConfirmedServiceRequest_terminateUploadSequence , 
		ConfirmedServiceRequest_requestDomainDownload , 
		ConfirmedServiceRequest_requestDomainUpload , 
		ConfirmedServiceRequest_loadDomainContent , 
		ConfirmedServiceRequest_storeDomainContent , 
		ConfirmedServiceRequest_deleteDomain , 
		ConfirmedServiceRequest_getDomainAttributes , 
		ConfirmedServiceRequest_createProgramInvocation , 
		ConfirmedServiceRequest_deleteProgramInvocation , 
		ConfirmedServiceRequest_start , 
		ConfirmedServiceRequest_stop , 
		ConfirmedServiceRequest_resume , 
		ConfirmedServiceRequest_reset , 
		ConfirmedServiceRequest_kill , 
		ConfirmedServiceRequest_getProgramInvocationAttributes , 
		ConfirmedServiceRequest_obtainFile , 
		ConfirmedServiceRequest_defineEventCondition , 
		ConfirmedServiceRequest_deleteEventCondition , 
		ConfirmedServiceRequest_getEventConditionAttributes , 
		ConfirmedServiceRequest_reportEventConditionStatus , 
		ConfirmedServiceRequest_alterEventConditionMonitoring , 
		ConfirmedServiceRequest_triggerEvent , 
		ConfirmedServiceRequest_defineEventAction , 
		ConfirmedServiceRequest_deleteEventAction , 
		ConfirmedServiceRequest_getEventActionAttributes , 
		ConfirmedServiceRequest_reportEventActionStatus , 
		ConfirmedServiceRequest_defineEventEnrollment , 
		ConfirmedServiceRequest_deleteEventEnrollment , 
		ConfirmedServiceRequest_alterEventEnrollment , 
		ConfirmedServiceRequest_reportEventEnrollmentStatus , 
		ConfirmedServiceRequest_getEventEnrollmentAttributes , 
		ConfirmedServiceRequest_acknowledgeEventNotification , 
		ConfirmedServiceRequest_getAlarmSummary , 
		ConfirmedServiceRequest_getAlarmEnrollmentSummary , 
		ConfirmedServiceRequest_readJournal , 
		ConfirmedServiceRequest_writeJournal , 
		ConfirmedServiceRequest_initializeJournal , 
		ConfirmedServiceRequest_reportJournalStatus , 
		ConfirmedServiceRequest_createJournal , 
		ConfirmedServiceRequest_deleteJournal , 
		ConfirmedServiceRequest_getCapabilityList , 
		ConfirmedServiceRequest_fileOpen , 
		ConfirmedServiceRequest_fileRead , 
		ConfirmedServiceRequest_fileClose , 
		ConfirmedServiceRequest_fileRename , 
		ConfirmedServiceRequest_fileDelete , 
		ConfirmedServiceRequest_fileDirectory , 
		ConfirmedServiceRequest_additionalService , 
		ConfirmedServiceRequest_getDataExchangeAttributes , 
		ConfirmedServiceRequest_exchangeData , 
		ConfirmedServiceRequest_defineAccessControlList , 
		ConfirmedServiceRequest_getAccessControlListAttributes , 
		ConfirmedServiceRequest_reportAccessControlledObjects , 
		ConfirmedServiceRequest_deleteAccessControlList , 
		ConfirmedServiceRequest_changeAccessControl , 
	};

	struct  ConfirmedServiceRequest : public BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceRequest_enum) {



		ConfirmedServiceRequest() : BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceRequest_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(status, Status_Request,  ConfirmedServiceRequest_status)
		BOOST_ASN_VALUE_CHOICE(getNameList, GetNameList_Request,  ConfirmedServiceRequest_getNameList)
		BOOST_ASN_VALUE_CHOICE(identify, Identify_Request,  ConfirmedServiceRequest_identify)
		BOOST_ASN_VALUE_CHOICE(rename, Rename_Request,  ConfirmedServiceRequest_rename)
		BOOST_ASN_VALUE_CHOICE(read, Read_Request,  ConfirmedServiceRequest_read)
		BOOST_ASN_VALUE_CHOICE(write, Write_Request,  ConfirmedServiceRequest_write)
		BOOST_ASN_VALUE_CHOICE(getVariableAccessAttributes, GetVariableAccessAttributes_Request,  ConfirmedServiceRequest_getVariableAccessAttributes)
		BOOST_ASN_VALUE_CHOICE(defineNamedVariable, DefineNamedVariable_Request,  ConfirmedServiceRequest_defineNamedVariable)
		BOOST_ASN_VALUE_CHOICE(defineScatteredAccess, DefineScatteredAccess_Request,  ConfirmedServiceRequest_defineScatteredAccess)
		BOOST_ASN_VALUE_CHOICE(getScatteredAccessAttributes, GetScatteredAccessAttributes_Request,  ConfirmedServiceRequest_getScatteredAccessAttributes)
		BOOST_ASN_VALUE_CHOICE(deleteVariableAccess, DeleteVariableAccess_Request,  ConfirmedServiceRequest_deleteVariableAccess)
		BOOST_ASN_VALUE_CHOICE(defineNamedVariableList, DefineNamedVariableList_Request,  ConfirmedServiceRequest_defineNamedVariableList)
		BOOST_ASN_VALUE_CHOICE(getNamedVariableListAttributes, GetNamedVariableListAttributes_Request,  ConfirmedServiceRequest_getNamedVariableListAttributes)
		BOOST_ASN_VALUE_CHOICE(deleteNamedVariableList, DeleteNamedVariableList_Request,  ConfirmedServiceRequest_deleteNamedVariableList)
		BOOST_ASN_VALUE_CHOICE(defineNamedType, DefineNamedType_Request,  ConfirmedServiceRequest_defineNamedType)
		BOOST_ASN_VALUE_CHOICE(getNamedTypeAttributes, GetNamedTypeAttributes_Request,  ConfirmedServiceRequest_getNamedTypeAttributes)
		BOOST_ASN_VALUE_CHOICE(deleteNamedType, DeleteNamedType_Request,  ConfirmedServiceRequest_deleteNamedType)
		BOOST_ASN_VALUE_CHOICE(input, Input_Request,  ConfirmedServiceRequest_input)
		BOOST_ASN_VALUE_CHOICE(output, Output_Request,  ConfirmedServiceRequest_output)
		BOOST_ASN_VALUE_CHOICE(takeControl, TakeControl_Request,  ConfirmedServiceRequest_takeControl)
		BOOST_ASN_VALUE_CHOICE(relinquishControl, RelinquishControl_Request,  ConfirmedServiceRequest_relinquishControl)
		BOOST_ASN_VALUE_CHOICE(defineSemaphore, DefineSemaphore_Request,  ConfirmedServiceRequest_defineSemaphore)
		BOOST_ASN_VALUE_CHOICE(deleteSemaphore, DeleteSemaphore_Request,  ConfirmedServiceRequest_deleteSemaphore)
		BOOST_ASN_VALUE_CHOICE(reportSemaphoreStatus, ReportSemaphoreStatus_Request,  ConfirmedServiceRequest_reportSemaphoreStatus)
		BOOST_ASN_VALUE_CHOICE(reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Request,  ConfirmedServiceRequest_reportPoolSemaphoreStatus)
		BOOST_ASN_VALUE_CHOICE(reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Request,  ConfirmedServiceRequest_reportSemaphoreEntryStatus)
		BOOST_ASN_VALUE_CHOICE(initiateDownloadSequence, InitiateDownloadSequence_Request,  ConfirmedServiceRequest_initiateDownloadSequence)
		BOOST_ASN_VALUE_CHOICE(downloadSegment, DownloadSegment_Request,  ConfirmedServiceRequest_downloadSegment)
		BOOST_ASN_VALUE_CHOICE(terminateDownloadSequence, TerminateDownloadSequence_Request,  ConfirmedServiceRequest_terminateDownloadSequence)
		BOOST_ASN_VALUE_CHOICE(initiateUploadSequence, InitiateUploadSequence_Request,  ConfirmedServiceRequest_initiateUploadSequence)
		BOOST_ASN_VALUE_CHOICE(uploadSegment, UploadSegment_Request,  ConfirmedServiceRequest_uploadSegment)
		BOOST_ASN_VALUE_CHOICE(terminateUploadSequence, TerminateUploadSequence_Request,  ConfirmedServiceRequest_terminateUploadSequence)
		BOOST_ASN_VALUE_CHOICE(requestDomainDownload, RequestDomainDownload_Request,  ConfirmedServiceRequest_requestDomainDownload)
		BOOST_ASN_VALUE_CHOICE(requestDomainUpload, RequestDomainUpload_Request,  ConfirmedServiceRequest_requestDomainUpload)
		BOOST_ASN_VALUE_CHOICE(loadDomainContent, LoadDomainContent_Request,  ConfirmedServiceRequest_loadDomainContent)
		BOOST_ASN_VALUE_CHOICE(storeDomainContent, StoreDomainContent_Request,  ConfirmedServiceRequest_storeDomainContent)
		BOOST_ASN_VALUE_CHOICE(deleteDomain, DeleteDomain_Request,  ConfirmedServiceRequest_deleteDomain)
		BOOST_ASN_VALUE_CHOICE(getDomainAttributes, GetDomainAttributes_Request,  ConfirmedServiceRequest_getDomainAttributes)
		BOOST_ASN_VALUE_CHOICE(createProgramInvocation, CreateProgramInvocation_Request,  ConfirmedServiceRequest_createProgramInvocation)
		BOOST_ASN_VALUE_CHOICE(deleteProgramInvocation, DeleteProgramInvocation_Request,  ConfirmedServiceRequest_deleteProgramInvocation)
		BOOST_ASN_VALUE_CHOICE(start, Start_Request,  ConfirmedServiceRequest_start)
		BOOST_ASN_VALUE_CHOICE(stop, Stop_Request,  ConfirmedServiceRequest_stop)
		BOOST_ASN_VALUE_CHOICE(resume, Resume_Request,  ConfirmedServiceRequest_resume)
		BOOST_ASN_VALUE_CHOICE(reset, Reset_Request,  ConfirmedServiceRequest_reset)
		BOOST_ASN_VALUE_CHOICE(kill, Kill_Request,  ConfirmedServiceRequest_kill)
		BOOST_ASN_VALUE_CHOICE(getProgramInvocationAttributes, GetProgramInvocationAttributes_Request,  ConfirmedServiceRequest_getProgramInvocationAttributes)
		BOOST_ASN_VALUE_CHOICE(obtainFile, ObtainFile_Request,  ConfirmedServiceRequest_obtainFile)
		BOOST_ASN_VALUE_CHOICE(defineEventCondition, DefineEventCondition_Request,  ConfirmedServiceRequest_defineEventCondition)
		BOOST_ASN_VALUE_CHOICE(deleteEventCondition, DeleteEventCondition_Request,  ConfirmedServiceRequest_deleteEventCondition)
		BOOST_ASN_VALUE_CHOICE(getEventConditionAttributes, GetEventConditionAttributes_Request,  ConfirmedServiceRequest_getEventConditionAttributes)
		BOOST_ASN_VALUE_CHOICE(reportEventConditionStatus, ReportEventConditionStatus_Request,  ConfirmedServiceRequest_reportEventConditionStatus)
		BOOST_ASN_VALUE_CHOICE(alterEventConditionMonitoring, AlterEventConditionMonitoring_Request,  ConfirmedServiceRequest_alterEventConditionMonitoring)
		BOOST_ASN_VALUE_CHOICE(triggerEvent, TriggerEvent_Request,  ConfirmedServiceRequest_triggerEvent)
		BOOST_ASN_VALUE_CHOICE(defineEventAction, DefineEventAction_Request,  ConfirmedServiceRequest_defineEventAction)
		BOOST_ASN_VALUE_CHOICE(deleteEventAction, DeleteEventAction_Request,  ConfirmedServiceRequest_deleteEventAction)
		BOOST_ASN_VALUE_CHOICE(getEventActionAttributes, GetEventActionAttributes_Request,  ConfirmedServiceRequest_getEventActionAttributes)
		BOOST_ASN_VALUE_CHOICE(reportEventActionStatus, ReportEventActionStatus_Request,  ConfirmedServiceRequest_reportEventActionStatus)
		BOOST_ASN_VALUE_CHOICE(defineEventEnrollment, DefineEventEnrollment_Request,  ConfirmedServiceRequest_defineEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(deleteEventEnrollment, DeleteEventEnrollment_Request,  ConfirmedServiceRequest_deleteEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(alterEventEnrollment, AlterEventEnrollment_Request,  ConfirmedServiceRequest_alterEventEnrollment)
		BOOST_ASN_VALUE_CHOICE(reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Request,  ConfirmedServiceRequest_reportEventEnrollmentStatus)
		BOOST_ASN_VALUE_CHOICE(getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Request,  ConfirmedServiceRequest_getEventEnrollmentAttributes)
		BOOST_ASN_VALUE_CHOICE(acknowledgeEventNotification, AcknowledgeEventNotification_Request,  ConfirmedServiceRequest_acknowledgeEventNotification)
		BOOST_ASN_VALUE_CHOICE(getAlarmSummary, GetAlarmSummary_Request,  ConfirmedServiceRequest_getAlarmSummary)
		BOOST_ASN_VALUE_CHOICE(getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Request,  ConfirmedServiceRequest_getAlarmEnrollmentSummary)
		BOOST_ASN_VALUE_CHOICE(readJournal, ReadJournal_Request,  ConfirmedServiceRequest_readJournal)
		BOOST_ASN_VALUE_CHOICE(writeJournal, WriteJournal_Request,  ConfirmedServiceRequest_writeJournal)
		BOOST_ASN_VALUE_CHOICE(initializeJournal, InitializeJournal_Request,  ConfirmedServiceRequest_initializeJournal)
		BOOST_ASN_VALUE_CHOICE(reportJournalStatus, ReportJournalStatus_Request,  ConfirmedServiceRequest_reportJournalStatus)
		BOOST_ASN_VALUE_CHOICE(createJournal, CreateJournal_Request,  ConfirmedServiceRequest_createJournal)
		BOOST_ASN_VALUE_CHOICE(deleteJournal, DeleteJournal_Request,  ConfirmedServiceRequest_deleteJournal)
		BOOST_ASN_VALUE_CHOICE(getCapabilityList, GetCapabilityList_Request,  ConfirmedServiceRequest_getCapabilityList)
		BOOST_ASN_VALUE_CHOICE(fileOpen, FileOpen_Request,  ConfirmedServiceRequest_fileOpen)
		BOOST_ASN_VALUE_CHOICE(fileRead, FileRead_Request,  ConfirmedServiceRequest_fileRead)
		BOOST_ASN_VALUE_CHOICE(fileClose, FileClose_Request,  ConfirmedServiceRequest_fileClose)
		BOOST_ASN_VALUE_CHOICE(fileRename, FileRename_Request,  ConfirmedServiceRequest_fileRename)
		BOOST_ASN_VALUE_CHOICE(fileDelete, FileDelete_Request,  ConfirmedServiceRequest_fileDelete)
		BOOST_ASN_VALUE_CHOICE(fileDirectory, FileDirectory_Request,  ConfirmedServiceRequest_fileDirectory)
		BOOST_ASN_VALUE_CHOICE(additionalService, AdditionalService_Request,  ConfirmedServiceRequest_additionalService)
		BOOST_ASN_VALUE_CHOICE(getDataExchangeAttributes, GetDataExchangeAttributes_Request,  ConfirmedServiceRequest_getDataExchangeAttributes)
		BOOST_ASN_VALUE_CHOICE(exchangeData, ExchangeData_Request,  ConfirmedServiceRequest_exchangeData)
		BOOST_ASN_VALUE_CHOICE(defineAccessControlList, DefineAccessControlList_Request,  ConfirmedServiceRequest_defineAccessControlList)
		BOOST_ASN_VALUE_CHOICE(getAccessControlListAttributes, GetAccessControlListAttributes_Request,  ConfirmedServiceRequest_getAccessControlListAttributes)
		BOOST_ASN_VALUE_CHOICE(reportAccessControlledObjects, ReportAccessControlledObjects_Request,  ConfirmedServiceRequest_reportAccessControlledObjects)
		BOOST_ASN_VALUE_CHOICE(deleteAccessControlList, DeleteAccessControlList_Request,  ConfirmedServiceRequest_deleteAccessControlList)
		BOOST_ASN_VALUE_CHOICE(changeAccessControl, ChangeAccessControl_Request,  ConfirmedServiceRequest_changeAccessControl)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Status_Request > (true , ConfirmedServiceRequest_status) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Request > (true , ConfirmedServiceRequest_getNameList) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Identify_Request > (true , ConfirmedServiceRequest_identify) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Rename_Request > (true , ConfirmedServiceRequest_rename) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<Read_Request > (true , ConfirmedServiceRequest_read) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<Write_Request > (true , ConfirmedServiceRequest_write) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (true , ConfirmedServiceRequest_getVariableAccessAttributes) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Request > (true , ConfirmedServiceRequest_defineNamedVariable) ,7)) return; else free(); break;}
							case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineScatteredAccess_Request > (true , ConfirmedServiceRequest_defineScatteredAccess) ,8)) return; else free(); break;}
							case 9: { if(BOOST_ASN_CHOICE_TAG(value<GetScatteredAccessAttributes_Request > (true , ConfirmedServiceRequest_getScatteredAccessAttributes) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Request > (true , ConfirmedServiceRequest_deleteVariableAccess) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Request > (true , ConfirmedServiceRequest_defineNamedVariableList) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (true , ConfirmedServiceRequest_getNamedVariableListAttributes) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Request > (true , ConfirmedServiceRequest_deleteNamedVariableList) ,13)) return; else free(); break;}
							case 14: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Request > (true , ConfirmedServiceRequest_defineNamedType) ,14)) return; else free(); break;}
							case 15: { if(BOOST_ASN_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (true , ConfirmedServiceRequest_getNamedTypeAttributes) ,15)) return; else free(); break;}
							case 16: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Request > (true , ConfirmedServiceRequest_deleteNamedType) ,16)) return; else free(); break;}
							case 17: { if(BOOST_ASN_IMPLICIT_TAG(value<Input_Request > (true , ConfirmedServiceRequest_input) ,17)) return; else free(); break;}
							case 18: { if(BOOST_ASN_IMPLICIT_TAG(value<Output_Request > (true , ConfirmedServiceRequest_output) ,18)) return; else free(); break;}
							case 19: { if(BOOST_ASN_IMPLICIT_TAG(value<TakeControl_Request > (true , ConfirmedServiceRequest_takeControl) ,19)) return; else free(); break;}
							case 20: { if(BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Request > (true , ConfirmedServiceRequest_relinquishControl) ,20)) return; else free(); break;}
							case 21: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Request > (true , ConfirmedServiceRequest_defineSemaphore) ,21)) return; else free(); break;}
							case 22: { if(BOOST_ASN_CHOICE_TAG(value<DeleteSemaphore_Request > (true , ConfirmedServiceRequest_deleteSemaphore) ,22)) return; else free(); break;}
							case 23: { if(BOOST_ASN_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (true , ConfirmedServiceRequest_reportSemaphoreStatus) ,23)) return; else free(); break;}
							case 24: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Request > (true , ConfirmedServiceRequest_reportPoolSemaphoreStatus) ,24)) return; else free(); break;}
							case 25: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Request > (true , ConfirmedServiceRequest_reportSemaphoreEntryStatus) ,25)) return; else free(); break;}
							case 26: { if(BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Request > (true , ConfirmedServiceRequest_initiateDownloadSequence) ,26)) return; else free(); break;}
							case 27: { if(BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Request > (true , ConfirmedServiceRequest_downloadSegment) ,27)) return; else free(); break;}
							case 28: { if(BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Request > (true , ConfirmedServiceRequest_terminateDownloadSequence) ,28)) return; else free(); break;}
							case 29: { if(BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Request > (true , ConfirmedServiceRequest_initiateUploadSequence) ,29)) return; else free(); break;}
							case 30: { if(BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Request > (true , ConfirmedServiceRequest_uploadSegment) ,30)) return; else free(); break;}
							case 31: { if(BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Request > (true , ConfirmedServiceRequest_terminateUploadSequence) ,31)) return; else free(); break;}
							case 32: { if(BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Request > (true , ConfirmedServiceRequest_requestDomainDownload) ,32)) return; else free(); break;}
							case 33: { if(BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Request > (true , ConfirmedServiceRequest_requestDomainUpload) ,33)) return; else free(); break;}
							case 34: { if(BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Request > (true , ConfirmedServiceRequest_loadDomainContent) ,34)) return; else free(); break;}
							case 35: { if(BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Request > (true , ConfirmedServiceRequest_storeDomainContent) ,35)) return; else free(); break;}
							case 36: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Request > (true , ConfirmedServiceRequest_deleteDomain) ,36)) return; else free(); break;}
							case 37: { if(BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Request > (true , ConfirmedServiceRequest_getDomainAttributes) ,37)) return; else free(); break;}
							case 38: { if(BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Request > (true , ConfirmedServiceRequest_createProgramInvocation) ,38)) return; else free(); break;}
							case 39: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Request > (true , ConfirmedServiceRequest_deleteProgramInvocation) ,39)) return; else free(); break;}
							case 40: { if(BOOST_ASN_IMPLICIT_TAG(value<Start_Request > (true , ConfirmedServiceRequest_start) ,40)) return; else free(); break;}
							case 41: { if(BOOST_ASN_IMPLICIT_TAG(value<Stop_Request > (true , ConfirmedServiceRequest_stop) ,41)) return; else free(); break;}
							case 42: { if(BOOST_ASN_IMPLICIT_TAG(value<Resume_Request > (true , ConfirmedServiceRequest_resume) ,42)) return; else free(); break;}
							case 43: { if(BOOST_ASN_IMPLICIT_TAG(value<Reset_Request > (true , ConfirmedServiceRequest_reset) ,43)) return; else free(); break;}
							case 44: { if(BOOST_ASN_IMPLICIT_TAG(value<Kill_Request > (true , ConfirmedServiceRequest_kill) ,44)) return; else free(); break;}
							case 45: { if(BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Request > (true , ConfirmedServiceRequest_getProgramInvocationAttributes) ,45)) return; else free(); break;}
							case 46: { if(BOOST_ASN_IMPLICIT_TAG(value<ObtainFile_Request > (true , ConfirmedServiceRequest_obtainFile) ,46)) return; else free(); break;}
							case 47: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Request > (true , ConfirmedServiceRequest_defineEventCondition) ,47)) return; else free(); break;}
							case 48: { if(BOOST_ASN_CHOICE_TAG(value<DeleteEventCondition_Request > (true , ConfirmedServiceRequest_deleteEventCondition) ,48)) return; else free(); break;}
							case 49: { if(BOOST_ASN_CHOICE_TAG(value<GetEventConditionAttributes_Request > (true , ConfirmedServiceRequest_getEventConditionAttributes) ,49)) return; else free(); break;}
							case 50: { if(BOOST_ASN_CHOICE_TAG(value<ReportEventConditionStatus_Request > (true , ConfirmedServiceRequest_reportEventConditionStatus) ,50)) return; else free(); break;}
							case 51: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Request > (true , ConfirmedServiceRequest_alterEventConditionMonitoring) ,51)) return; else free(); break;}
							case 52: { if(BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Request > (true , ConfirmedServiceRequest_triggerEvent) ,52)) return; else free(); break;}
							case 53: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Request > (true , ConfirmedServiceRequest_defineEventAction) ,53)) return; else free(); break;}
							case 54: { if(BOOST_ASN_CHOICE_TAG(value<DeleteEventAction_Request > (true , ConfirmedServiceRequest_deleteEventAction) ,54)) return; else free(); break;}
							case 55: { if(BOOST_ASN_CHOICE_TAG(value<GetEventActionAttributes_Request > (true , ConfirmedServiceRequest_getEventActionAttributes) ,55)) return; else free(); break;}
							case 56: { if(BOOST_ASN_CHOICE_TAG(value<ReportEventActionStatus_Request > (true , ConfirmedServiceRequest_reportEventActionStatus) ,56)) return; else free(); break;}
							case 57: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Request > (true , ConfirmedServiceRequest_defineEventEnrollment) ,57)) return; else free(); break;}
							case 58: { if(BOOST_ASN_CHOICE_TAG(value<DeleteEventEnrollment_Request > (true , ConfirmedServiceRequest_deleteEventEnrollment) ,58)) return; else free(); break;}
							case 59: { if(BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Request > (true , ConfirmedServiceRequest_alterEventEnrollment) ,59)) return; else free(); break;}
							case 60: { if(BOOST_ASN_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (true , ConfirmedServiceRequest_reportEventEnrollmentStatus) ,60)) return; else free(); break;}
							case 61: { if(BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Request > (true , ConfirmedServiceRequest_getEventEnrollmentAttributes) ,61)) return; else free(); break;}
							case 62: { if(BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Request > (true , ConfirmedServiceRequest_acknowledgeEventNotification) ,62)) return; else free(); break;}
							case 63: { if(BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Request > (true , ConfirmedServiceRequest_getAlarmSummary) ,63)) return; else free(); break;}
							case 64: { if(BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Request > (true , ConfirmedServiceRequest_getAlarmEnrollmentSummary) ,64)) return; else free(); break;}
							case 65: { if(BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Request > (true , ConfirmedServiceRequest_readJournal) ,65)) return; else free(); break;}
							case 66: { if(BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Request > (true , ConfirmedServiceRequest_writeJournal) ,66)) return; else free(); break;}
							case 67: { if(BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Request > (true , ConfirmedServiceRequest_initializeJournal) ,67)) return; else free(); break;}
							case 68: { if(BOOST_ASN_CHOICE_TAG(value<ReportJournalStatus_Request > (true , ConfirmedServiceRequest_reportJournalStatus) ,68)) return; else free(); break;}
							case 69: { if(BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Request > (true , ConfirmedServiceRequest_createJournal) ,69)) return; else free(); break;}
							case 70: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Request > (true , ConfirmedServiceRequest_deleteJournal) ,70)) return; else free(); break;}
							case 71: { if(BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Request > (true , ConfirmedServiceRequest_getCapabilityList) ,71)) return; else free(); break;}
							case 72: { if(BOOST_ASN_IMPLICIT_TAG(value<FileOpen_Request > (true , ConfirmedServiceRequest_fileOpen) ,72)) return; else free(); break;}
							case 73: { if(BOOST_ASN_IMPLICIT_TAG(value<FileRead_Request > (true , ConfirmedServiceRequest_fileRead) ,73)) return; else free(); break;}
							case 74: { if(BOOST_ASN_IMPLICIT_TAG(value<FileClose_Request > (true , ConfirmedServiceRequest_fileClose) ,74)) return; else free(); break;}
							case 75: { if(BOOST_ASN_IMPLICIT_TAG(value<FileRename_Request > (true , ConfirmedServiceRequest_fileRename) ,75)) return; else free(); break;}
							case 76: { if(BOOST_ASN_IMPLICIT_TAG(value<FileDelete_Request > (true , ConfirmedServiceRequest_fileDelete) ,76)) return; else free(); break;}
							case 77: { if(BOOST_ASN_IMPLICIT_TAG(value<FileDirectory_Request > (true , ConfirmedServiceRequest_fileDirectory) ,77)) return; else free(); break;}
							case 78: { if(BOOST_ASN_CHOICE_TAG(value<AdditionalService_Request > (true , ConfirmedServiceRequest_additionalService) ,78)) return; else free(); break;}
							case 80: { if(BOOST_ASN_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (true , ConfirmedServiceRequest_getDataExchangeAttributes) ,80)) return; else free(); break;}
							case 81: { if(BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Request > (true , ConfirmedServiceRequest_exchangeData) ,81)) return; else free(); break;}
							case 82: { if(BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Request > (true , ConfirmedServiceRequest_defineAccessControlList) ,82)) return; else free(); break;}
							case 83: { if(BOOST_ASN_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (true , ConfirmedServiceRequest_getAccessControlListAttributes) ,83)) return; else free(); break;}
							case 84: { if(BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Request > (true , ConfirmedServiceRequest_reportAccessControlledObjects) ,84)) return; else free(); break;}
							case 85: { if(BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Request > (true , ConfirmedServiceRequest_deleteAccessControlList) ,85)) return; else free(); break;}
							case 86: { if(BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Request > (true , ConfirmedServiceRequest_changeAccessControl) ,86)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case ConfirmedServiceRequest_status: {BOOST_ASN_IMPLICIT_TAG(value<Status_Request > (false , ConfirmedServiceRequest_status) ,0); break;}
					case ConfirmedServiceRequest_getNameList: {BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Request > (false , ConfirmedServiceRequest_getNameList) ,1); break;}
					case ConfirmedServiceRequest_identify: {BOOST_ASN_IMPLICIT_TAG(value<Identify_Request > (false , ConfirmedServiceRequest_identify) ,2); break;}
					case ConfirmedServiceRequest_rename: {BOOST_ASN_IMPLICIT_TAG(value<Rename_Request > (false , ConfirmedServiceRequest_rename) ,3); break;}
					case ConfirmedServiceRequest_read: {BOOST_ASN_IMPLICIT_TAG(value<Read_Request > (false , ConfirmedServiceRequest_read) ,4); break;}
					case ConfirmedServiceRequest_write: {BOOST_ASN_IMPLICIT_TAG(value<Write_Request > (false , ConfirmedServiceRequest_write) ,5); break;}
					case ConfirmedServiceRequest_getVariableAccessAttributes: {BOOST_ASN_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (false , ConfirmedServiceRequest_getVariableAccessAttributes) ,6); break;}
					case ConfirmedServiceRequest_defineNamedVariable: {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Request > (false , ConfirmedServiceRequest_defineNamedVariable) ,7); break;}
					case ConfirmedServiceRequest_defineScatteredAccess: {BOOST_ASN_IMPLICIT_TAG(value<DefineScatteredAccess_Request > (false , ConfirmedServiceRequest_defineScatteredAccess) ,8); break;}
					case ConfirmedServiceRequest_getScatteredAccessAttributes: {BOOST_ASN_CHOICE_TAG(value<GetScatteredAccessAttributes_Request > (false , ConfirmedServiceRequest_getScatteredAccessAttributes) ,9); break;}
					case ConfirmedServiceRequest_deleteVariableAccess: {BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Request > (false , ConfirmedServiceRequest_deleteVariableAccess) ,10); break;}
					case ConfirmedServiceRequest_defineNamedVariableList: {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Request > (false , ConfirmedServiceRequest_defineNamedVariableList) ,11); break;}
					case ConfirmedServiceRequest_getNamedVariableListAttributes: {BOOST_ASN_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (false , ConfirmedServiceRequest_getNamedVariableListAttributes) ,12); break;}
					case ConfirmedServiceRequest_deleteNamedVariableList: {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Request > (false , ConfirmedServiceRequest_deleteNamedVariableList) ,13); break;}
					case ConfirmedServiceRequest_defineNamedType: {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Request > (false , ConfirmedServiceRequest_defineNamedType) ,14); break;}
					case ConfirmedServiceRequest_getNamedTypeAttributes: {BOOST_ASN_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (false , ConfirmedServiceRequest_getNamedTypeAttributes) ,15); break;}
					case ConfirmedServiceRequest_deleteNamedType: {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Request > (false , ConfirmedServiceRequest_deleteNamedType) ,16); break;}
					case ConfirmedServiceRequest_input: {BOOST_ASN_IMPLICIT_TAG(value<Input_Request > (false , ConfirmedServiceRequest_input) ,17); break;}
					case ConfirmedServiceRequest_output: {BOOST_ASN_IMPLICIT_TAG(value<Output_Request > (false , ConfirmedServiceRequest_output) ,18); break;}
					case ConfirmedServiceRequest_takeControl: {BOOST_ASN_IMPLICIT_TAG(value<TakeControl_Request > (false , ConfirmedServiceRequest_takeControl) ,19); break;}
					case ConfirmedServiceRequest_relinquishControl: {BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Request > (false , ConfirmedServiceRequest_relinquishControl) ,20); break;}
					case ConfirmedServiceRequest_defineSemaphore: {BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Request > (false , ConfirmedServiceRequest_defineSemaphore) ,21); break;}
					case ConfirmedServiceRequest_deleteSemaphore: {BOOST_ASN_CHOICE_TAG(value<DeleteSemaphore_Request > (false , ConfirmedServiceRequest_deleteSemaphore) ,22); break;}
					case ConfirmedServiceRequest_reportSemaphoreStatus: {BOOST_ASN_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (false , ConfirmedServiceRequest_reportSemaphoreStatus) ,23); break;}
					case ConfirmedServiceRequest_reportPoolSemaphoreStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Request > (false , ConfirmedServiceRequest_reportPoolSemaphoreStatus) ,24); break;}
					case ConfirmedServiceRequest_reportSemaphoreEntryStatus: {BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Request > (false , ConfirmedServiceRequest_reportSemaphoreEntryStatus) ,25); break;}
					case ConfirmedServiceRequest_initiateDownloadSequence: {BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Request > (false , ConfirmedServiceRequest_initiateDownloadSequence) ,26); break;}
					case ConfirmedServiceRequest_downloadSegment: {BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Request > (false , ConfirmedServiceRequest_downloadSegment) ,27); break;}
					case ConfirmedServiceRequest_terminateDownloadSequence: {BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Request > (false , ConfirmedServiceRequest_terminateDownloadSequence) ,28); break;}
					case ConfirmedServiceRequest_initiateUploadSequence: {BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Request > (false , ConfirmedServiceRequest_initiateUploadSequence) ,29); break;}
					case ConfirmedServiceRequest_uploadSegment: {BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Request > (false , ConfirmedServiceRequest_uploadSegment) ,30); break;}
					case ConfirmedServiceRequest_terminateUploadSequence: {BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Request > (false , ConfirmedServiceRequest_terminateUploadSequence) ,31); break;}
					case ConfirmedServiceRequest_requestDomainDownload: {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Request > (false , ConfirmedServiceRequest_requestDomainDownload) ,32); break;}
					case ConfirmedServiceRequest_requestDomainUpload: {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Request > (false , ConfirmedServiceRequest_requestDomainUpload) ,33); break;}
					case ConfirmedServiceRequest_loadDomainContent: {BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Request > (false , ConfirmedServiceRequest_loadDomainContent) ,34); break;}
					case ConfirmedServiceRequest_storeDomainContent: {BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Request > (false , ConfirmedServiceRequest_storeDomainContent) ,35); break;}
					case ConfirmedServiceRequest_deleteDomain: {BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Request > (false , ConfirmedServiceRequest_deleteDomain) ,36); break;}
					case ConfirmedServiceRequest_getDomainAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Request > (false , ConfirmedServiceRequest_getDomainAttributes) ,37); break;}
					case ConfirmedServiceRequest_createProgramInvocation: {BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Request > (false , ConfirmedServiceRequest_createProgramInvocation) ,38); break;}
					case ConfirmedServiceRequest_deleteProgramInvocation: {BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Request > (false , ConfirmedServiceRequest_deleteProgramInvocation) ,39); break;}
					case ConfirmedServiceRequest_start: {BOOST_ASN_IMPLICIT_TAG(value<Start_Request > (false , ConfirmedServiceRequest_start) ,40); break;}
					case ConfirmedServiceRequest_stop: {BOOST_ASN_IMPLICIT_TAG(value<Stop_Request > (false , ConfirmedServiceRequest_stop) ,41); break;}
					case ConfirmedServiceRequest_resume: {BOOST_ASN_IMPLICIT_TAG(value<Resume_Request > (false , ConfirmedServiceRequest_resume) ,42); break;}
					case ConfirmedServiceRequest_reset: {BOOST_ASN_IMPLICIT_TAG(value<Reset_Request > (false , ConfirmedServiceRequest_reset) ,43); break;}
					case ConfirmedServiceRequest_kill: {BOOST_ASN_IMPLICIT_TAG(value<Kill_Request > (false , ConfirmedServiceRequest_kill) ,44); break;}
					case ConfirmedServiceRequest_getProgramInvocationAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Request > (false , ConfirmedServiceRequest_getProgramInvocationAttributes) ,45); break;}
					case ConfirmedServiceRequest_obtainFile: {BOOST_ASN_IMPLICIT_TAG(value<ObtainFile_Request > (false , ConfirmedServiceRequest_obtainFile) ,46); break;}
					case ConfirmedServiceRequest_defineEventCondition: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Request > (false , ConfirmedServiceRequest_defineEventCondition) ,47); break;}
					case ConfirmedServiceRequest_deleteEventCondition: {BOOST_ASN_CHOICE_TAG(value<DeleteEventCondition_Request > (false , ConfirmedServiceRequest_deleteEventCondition) ,48); break;}
					case ConfirmedServiceRequest_getEventConditionAttributes: {BOOST_ASN_CHOICE_TAG(value<GetEventConditionAttributes_Request > (false , ConfirmedServiceRequest_getEventConditionAttributes) ,49); break;}
					case ConfirmedServiceRequest_reportEventConditionStatus: {BOOST_ASN_CHOICE_TAG(value<ReportEventConditionStatus_Request > (false , ConfirmedServiceRequest_reportEventConditionStatus) ,50); break;}
					case ConfirmedServiceRequest_alterEventConditionMonitoring: {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Request > (false , ConfirmedServiceRequest_alterEventConditionMonitoring) ,51); break;}
					case ConfirmedServiceRequest_triggerEvent: {BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Request > (false , ConfirmedServiceRequest_triggerEvent) ,52); break;}
					case ConfirmedServiceRequest_defineEventAction: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Request > (false , ConfirmedServiceRequest_defineEventAction) ,53); break;}
					case ConfirmedServiceRequest_deleteEventAction: {BOOST_ASN_CHOICE_TAG(value<DeleteEventAction_Request > (false , ConfirmedServiceRequest_deleteEventAction) ,54); break;}
					case ConfirmedServiceRequest_getEventActionAttributes: {BOOST_ASN_CHOICE_TAG(value<GetEventActionAttributes_Request > (false , ConfirmedServiceRequest_getEventActionAttributes) ,55); break;}
					case ConfirmedServiceRequest_reportEventActionStatus: {BOOST_ASN_CHOICE_TAG(value<ReportEventActionStatus_Request > (false , ConfirmedServiceRequest_reportEventActionStatus) ,56); break;}
					case ConfirmedServiceRequest_defineEventEnrollment: {BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Request > (false , ConfirmedServiceRequest_defineEventEnrollment) ,57); break;}
					case ConfirmedServiceRequest_deleteEventEnrollment: {BOOST_ASN_CHOICE_TAG(value<DeleteEventEnrollment_Request > (false , ConfirmedServiceRequest_deleteEventEnrollment) ,58); break;}
					case ConfirmedServiceRequest_alterEventEnrollment: {BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Request > (false , ConfirmedServiceRequest_alterEventEnrollment) ,59); break;}
					case ConfirmedServiceRequest_reportEventEnrollmentStatus: {BOOST_ASN_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (false , ConfirmedServiceRequest_reportEventEnrollmentStatus) ,60); break;}
					case ConfirmedServiceRequest_getEventEnrollmentAttributes: {BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Request > (false , ConfirmedServiceRequest_getEventEnrollmentAttributes) ,61); break;}
					case ConfirmedServiceRequest_acknowledgeEventNotification: {BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Request > (false , ConfirmedServiceRequest_acknowledgeEventNotification) ,62); break;}
					case ConfirmedServiceRequest_getAlarmSummary: {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Request > (false , ConfirmedServiceRequest_getAlarmSummary) ,63); break;}
					case ConfirmedServiceRequest_getAlarmEnrollmentSummary: {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Request > (false , ConfirmedServiceRequest_getAlarmEnrollmentSummary) ,64); break;}
					case ConfirmedServiceRequest_readJournal: {BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Request > (false , ConfirmedServiceRequest_readJournal) ,65); break;}
					case ConfirmedServiceRequest_writeJournal: {BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Request > (false , ConfirmedServiceRequest_writeJournal) ,66); break;}
					case ConfirmedServiceRequest_initializeJournal: {BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Request > (false , ConfirmedServiceRequest_initializeJournal) ,67); break;}
					case ConfirmedServiceRequest_reportJournalStatus: {BOOST_ASN_CHOICE_TAG(value<ReportJournalStatus_Request > (false , ConfirmedServiceRequest_reportJournalStatus) ,68); break;}
					case ConfirmedServiceRequest_createJournal: {BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Request > (false , ConfirmedServiceRequest_createJournal) ,69); break;}
					case ConfirmedServiceRequest_deleteJournal: {BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Request > (false , ConfirmedServiceRequest_deleteJournal) ,70); break;}
					case ConfirmedServiceRequest_getCapabilityList: {BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Request > (false , ConfirmedServiceRequest_getCapabilityList) ,71); break;}
					case ConfirmedServiceRequest_fileOpen: {BOOST_ASN_IMPLICIT_TAG(value<FileOpen_Request > (false , ConfirmedServiceRequest_fileOpen) ,72); break;}
					case ConfirmedServiceRequest_fileRead: {BOOST_ASN_IMPLICIT_TAG(value<FileRead_Request > (false , ConfirmedServiceRequest_fileRead) ,73); break;}
					case ConfirmedServiceRequest_fileClose: {BOOST_ASN_IMPLICIT_TAG(value<FileClose_Request > (false , ConfirmedServiceRequest_fileClose) ,74); break;}
					case ConfirmedServiceRequest_fileRename: {BOOST_ASN_IMPLICIT_TAG(value<FileRename_Request > (false , ConfirmedServiceRequest_fileRename) ,75); break;}
					case ConfirmedServiceRequest_fileDelete: {BOOST_ASN_IMPLICIT_TAG(value<FileDelete_Request > (false , ConfirmedServiceRequest_fileDelete) ,76); break;}
					case ConfirmedServiceRequest_fileDirectory: {BOOST_ASN_IMPLICIT_TAG(value<FileDirectory_Request > (false , ConfirmedServiceRequest_fileDirectory) ,77); break;}
					case ConfirmedServiceRequest_additionalService: {BOOST_ASN_CHOICE_TAG(value<AdditionalService_Request > (false , ConfirmedServiceRequest_additionalService) ,78); break;}
					case ConfirmedServiceRequest_getDataExchangeAttributes: {BOOST_ASN_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (false , ConfirmedServiceRequest_getDataExchangeAttributes) ,80); break;}
					case ConfirmedServiceRequest_exchangeData: {BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Request > (false , ConfirmedServiceRequest_exchangeData) ,81); break;}
					case ConfirmedServiceRequest_defineAccessControlList: {BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Request > (false , ConfirmedServiceRequest_defineAccessControlList) ,82); break;}
					case ConfirmedServiceRequest_getAccessControlListAttributes: {BOOST_ASN_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (false , ConfirmedServiceRequest_getAccessControlListAttributes) ,83); break;}
					case ConfirmedServiceRequest_reportAccessControlledObjects: {BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Request > (false , ConfirmedServiceRequest_reportAccessControlledObjects) ,84); break;}
					case ConfirmedServiceRequest_deleteAccessControlList: {BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Request > (false , ConfirmedServiceRequest_deleteAccessControlList) ,85); break;}
					case ConfirmedServiceRequest_changeAccessControl: {BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Request > (false , ConfirmedServiceRequest_changeAccessControl) ,86); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  Confirmed_RequestPDU{
		//   SEQUENCE_OF is listOfModifiers 
		typedef std::vector<Modifier >   listOfModifiers_type;



		boost::asn1::value_holder<Unsigned32 >  invokeID;
		boost::shared_ptr<listOfModifiers_type > listOfModifiers;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(listOfModifiers_type ,  listOfModifiers)

 		boost::asn1::value_holder<ConfirmedServiceRequest >  service;
		boost::shared_ptr<Request_Detail >  service_ext;

		Confirmed_RequestPDU()  : invokeID() , service() , service_ext()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_BIND_TAG(invokeID);
			BOOST_ASN_BIND_TAG(listOfModifiers);
			BOOST_ASN_CHOICE(service);
			BOOST_ASN_EXTENTION;
			BOOST_ASN_CHOICE_TAG(service_ext ,79);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum MMSpdu_enum {
		MMSpdu_null = 0  , 
		MMSpdu_confirmed_RequestPDU , 
		MMSpdu_confirmed_ResponsePDU , 
		MMSpdu_confirmed_ErrorPDU , 
		MMSpdu_unconfirmed_PDU , 
		MMSpdu_rejectPDU , 
		MMSpdu_cancel_RequestPDU , 
		MMSpdu_cancel_ResponsePDU , 
		MMSpdu_cancel_ErrorPDU , 
		MMSpdu_initiate_RequestPDU , 
		MMSpdu_initiate_ResponsePDU , 
		MMSpdu_initiate_ErrorPDU , 
		MMSpdu_conclude_RequestPDU , 
		MMSpdu_conclude_ResponsePDU , 
		MMSpdu_conclude_ErrorPDU , 
	};

	struct  MMSpdu : public BOOST_ASN_CHOICE_STRUCT(MMSpdu_enum) {


		MMSpdu() : BOOST_ASN_CHOICE_STRUCT(MMSpdu_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(confirmed_RequestPDU, Confirmed_RequestPDU,  MMSpdu_confirmed_RequestPDU)
		BOOST_ASN_VALUE_CHOICE(confirmed_ResponsePDU, Confirmed_ResponsePDU,  MMSpdu_confirmed_ResponsePDU)
		BOOST_ASN_VALUE_CHOICE(confirmed_ErrorPDU, Confirmed_ErrorPDU,  MMSpdu_confirmed_ErrorPDU)
		BOOST_ASN_VALUE_CHOICE(unconfirmed_PDU, Unconfirmed_PDU,  MMSpdu_unconfirmed_PDU)
		BOOST_ASN_VALUE_CHOICE(rejectPDU, RejectPDU,  MMSpdu_rejectPDU)
		BOOST_ASN_VALUE_CHOICE(cancel_RequestPDU, Cancel_RequestPDU,  MMSpdu_cancel_RequestPDU)
		BOOST_ASN_VALUE_CHOICE(cancel_ResponsePDU, Cancel_ResponsePDU,  MMSpdu_cancel_ResponsePDU)
		BOOST_ASN_VALUE_CHOICE(cancel_ErrorPDU, Cancel_ErrorPDU,  MMSpdu_cancel_ErrorPDU)
		BOOST_ASN_VALUE_CHOICE(initiate_RequestPDU, Initiate_RequestPDU,  MMSpdu_initiate_RequestPDU)
		BOOST_ASN_VALUE_CHOICE(initiate_ResponsePDU, Initiate_ResponsePDU,  MMSpdu_initiate_ResponsePDU)
		BOOST_ASN_VALUE_CHOICE(initiate_ErrorPDU, Initiate_ErrorPDU,  MMSpdu_initiate_ErrorPDU)
		BOOST_ASN_VALUE_CHOICE(conclude_RequestPDU, Conclude_RequestPDU,  MMSpdu_conclude_RequestPDU)
		BOOST_ASN_VALUE_CHOICE(conclude_ResponsePDU, Conclude_ResponsePDU,  MMSpdu_conclude_ResponsePDU)
		BOOST_ASN_VALUE_CHOICE(conclude_ErrorPDU, Conclude_ErrorPDU,  MMSpdu_conclude_ErrorPDU)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Confirmed_RequestPDU > (true , MMSpdu_confirmed_RequestPDU) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ResponsePDU > (true , MMSpdu_confirmed_ResponsePDU) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ErrorPDU > (true , MMSpdu_confirmed_ErrorPDU) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<Unconfirmed_PDU > (true , MMSpdu_unconfirmed_PDU) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<RejectPDU > (true , MMSpdu_rejectPDU) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<Cancel_RequestPDU > (true , MMSpdu_cancel_RequestPDU) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<Cancel_ResponsePDU > (true , MMSpdu_cancel_ResponsePDU) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<Cancel_ErrorPDU > (true , MMSpdu_cancel_ErrorPDU) ,7)) return; else free(); break;}
							case 8: { if(BOOST_ASN_IMPLICIT_TAG(value<Initiate_RequestPDU > (true , MMSpdu_initiate_RequestPDU) ,8)) return; else free(); break;}
							case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<Initiate_ResponsePDU > (true , MMSpdu_initiate_ResponsePDU) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<Initiate_ErrorPDU > (true , MMSpdu_initiate_ErrorPDU) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<Conclude_RequestPDU > (true , MMSpdu_conclude_RequestPDU) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<Conclude_ResponsePDU > (true , MMSpdu_conclude_ResponsePDU) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<Conclude_ErrorPDU > (true , MMSpdu_conclude_ErrorPDU) ,13)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case MMSpdu_confirmed_RequestPDU: {BOOST_ASN_IMPLICIT_TAG(value<Confirmed_RequestPDU > (false , MMSpdu_confirmed_RequestPDU) ,0); break;}
					case MMSpdu_confirmed_ResponsePDU: {BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ResponsePDU > (false , MMSpdu_confirmed_ResponsePDU) ,1); break;}
					case MMSpdu_confirmed_ErrorPDU: {BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ErrorPDU > (false , MMSpdu_confirmed_ErrorPDU) ,2); break;}
					case MMSpdu_unconfirmed_PDU: {BOOST_ASN_IMPLICIT_TAG(value<Unconfirmed_PDU > (false , MMSpdu_unconfirmed_PDU) ,3); break;}
					case MMSpdu_rejectPDU: {BOOST_ASN_IMPLICIT_TAG(value<RejectPDU > (false , MMSpdu_rejectPDU) ,4); break;}
					case MMSpdu_cancel_RequestPDU: {BOOST_ASN_IMPLICIT_TAG(value<Cancel_RequestPDU > (false , MMSpdu_cancel_RequestPDU) ,5); break;}
					case MMSpdu_cancel_ResponsePDU: {BOOST_ASN_IMPLICIT_TAG(value<Cancel_ResponsePDU > (false , MMSpdu_cancel_ResponsePDU) ,6); break;}
					case MMSpdu_cancel_ErrorPDU: {BOOST_ASN_IMPLICIT_TAG(value<Cancel_ErrorPDU > (false , MMSpdu_cancel_ErrorPDU) ,7); break;}
					case MMSpdu_initiate_RequestPDU: {BOOST_ASN_IMPLICIT_TAG(value<Initiate_RequestPDU > (false , MMSpdu_initiate_RequestPDU) ,8); break;}
					case MMSpdu_initiate_ResponsePDU: {BOOST_ASN_IMPLICIT_TAG(value<Initiate_ResponsePDU > (false , MMSpdu_initiate_ResponsePDU) ,9); break;}
					case MMSpdu_initiate_ErrorPDU: {BOOST_ASN_IMPLICIT_TAG(value<Initiate_ErrorPDU > (false , MMSpdu_initiate_ErrorPDU) ,10); break;}
					case MMSpdu_conclude_RequestPDU: {BOOST_ASN_IMPLICIT_TAG(value<Conclude_RequestPDU > (false , MMSpdu_conclude_RequestPDU) ,11); break;}
					case MMSpdu_conclude_ResponsePDU: {BOOST_ASN_IMPLICIT_TAG(value<Conclude_ResponsePDU > (false , MMSpdu_conclude_ResponsePDU) ,12); break;}
					case MMSpdu_conclude_ErrorPDU: {BOOST_ASN_IMPLICIT_TAG(value<Conclude_ErrorPDU > (false , MMSpdu_conclude_ErrorPDU) ,13); break;}
					default:{}}}
		}
	};


}


BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::MMSpdu) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ConfirmedServiceRequest) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Request_Detail) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::UnconfirmedService) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Unconfirmed_Detail) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ConfirmedServiceResponse) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Response) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Response_Detail) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ServiceError::errorClass_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ServiceError::serviceSpecificInfo_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Error) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ObjectName) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ObjectClass) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::RejectPDU::rejectReason_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::GetAccessControlListAttributes_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ChangeAccessControl_Request::scopeOfChange_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_Status_Response) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_Status_Response::fullResponse_type::selectedProgramInvocation_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::GetNameList_Request::objectScope_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::LoadData) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Start_Request::executionArgument_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_Start_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::StartCount) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Resume_Request::executionArgument_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_Resume_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_Resume_Request__impl::controlling_type::modeType_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::GetProgramInvocationAttributes_Response::executionArgument_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::control_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::control_type::controlled_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ControlElement) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::InitiateUnitControl_Error) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::UnitControlUpload_Request::continueAfter_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::UnitControlUpload_Response::nextElement_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::StartUnitControl_Request::executionArgument_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::LoadUnitControlFromFile_Error) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::DeleteUnitControl_Error) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::TypeSpecification) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AlternateAccess_sequence_of) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection::selectAccess_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AccessResult) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Data) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::VariableAccessSpecification) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::VariableSpecification) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::Write_Response_sequence_of) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::GetVariableAccessAttributes_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::TakeControl_Response) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::EventNotification::actionResult_type::successOrFailure_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_EventNotification) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::EN_Additional_Detail) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_DefineEventCondition_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::DeleteEventCondition_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::GetEventConditionAttributes_Response::monitoredVariable_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_GetEventConditionAttributes_Response::groupPriorityOverride_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_GetEventConditionAttributes_Response::displayEnhancement_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_AlterEventConditionMonitoring_Request::changeDisplay_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::DeleteEventAction_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_DefineEventEnrollment_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::DeleteEventEnrollment_Request) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::eventConditionName_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::eventActionName_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::displayEnhancement_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AlterEventEnrollment_Response::currentState_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::CS_AlterEventEnrollment_Request::changeDisplay_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::RemoveEventConditionListReference_Error) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::AlterEventConditionListMonitoring_Request::priorityChange_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ReadJournal_Request::rangeStartSpecification_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::ReadJournal_Request::rangeStopSpecification_type) 
BOOST_ASN_CHOISE_REGESTRATE(ISO_9506_MMS_1::EntryContent::entryForm_type) 

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif