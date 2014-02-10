#ifndef ___ISO_9506_MMS_1
#define ___ISO_9506_MMS_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1 {

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

    struct MMSpdu;  
    struct Confirmed_RequestPDU;  
    struct ConfirmedServiceRequest;  
    struct AdditionalService_Request;  
    struct Request_Detail;  
    struct Unconfirmed_PDU;  
    struct UnconfirmedService;  
    struct Unconfirmed_Detail;  
    struct Confirmed_ResponsePDU;  
    struct ConfirmedServiceResponse;  
    struct AdditionalService_Response;  
    struct Response_Detail;  
    struct Confirmed_ErrorPDU;  
    struct ServiceError;  
    struct AdditionalService_Error;  
    struct ObjectName;  
    struct ObjectClass;  
    struct Initiate_RequestPDU;  
    struct Initiate_ResponsePDU;  
    struct Cancel_ErrorPDU;  
    struct RejectPDU;  
    struct DefineAccessControlList_Request;  
    struct GetAccessControlListAttributes_Request;  
    struct GetAccessControlListAttributes_Response;  
    struct ReportAccessControlledObjects_Request;  
    struct ReportAccessControlledObjects_Response;  
    struct ChangeAccessControl_Request;  
    struct ChangeAccessControl_Response;  
    struct StatusResponse;  
    struct CS_Status_Response;  
    struct GetNameList_Request;  
    struct GetNameList_Response;  
    struct Identify_Response;  
    struct Rename_Request;  
    struct GetCapabilityList_Request;  
    struct GetCapabilityList_Response;  
    struct InitiateDownloadSequence_Request;  
    struct DownloadSegment_Response;  
    struct LoadData;  
    struct TerminateDownloadSequence_Request;  
    struct InitiateUploadSequence_Response;  
    struct UploadSegment_Response;  
    struct RequestDomainDownload_Request;  
    struct RequestDomainUpload_Request;  
    struct LoadDomainContent_Request;  
    struct StoreDomainContent_Request;  
    struct GetDomainAttributes_Response;  
    struct CreateProgramInvocation_Request;  
    struct Start_Request;  
    struct CS_Start_Request_impl;  
    struct StartCount;  
    struct Stop_Request;  
    struct Resume_Request;  
    struct CS_Resume_Request_impl;  
    struct Reset_Request;  
    struct Kill_Request;  
    struct GetProgramInvocationAttributes_Response;  
    struct CS_GetProgramInvocationAttributes_Response;  
    struct Select_Request;  
    struct AlterProgramInvocationAttributes_Request;  
    struct ReconfigureProgramInvocation_Request;  
    struct ControlElement;  
    struct InitiateUnitControl_Error;  
    struct UnitControlLoadSegment_Response;  
    struct UnitControlUpload_Request;  
    struct UnitControlUpload_Response;  
    struct StartUnitControl_Request;  
    struct StartUnitControl_Error;  
    struct StopUnitControl_Error;  
    struct CreateUnitControl_Request;  
    struct AddToUnitControl_Request;  
    struct RemoveFromUnitControl_Request;  
    struct GetUnitControlAttributes_Response;  
    struct LoadUnitControlFromFile_Request;  
    struct LoadUnitControlFromFile_Error;  
    struct StoreUnitControlToFile_Request;  
    struct DeleteUnitControl_Error;  
    struct TypeSpecification;  
    struct AlternateAccessSelection;  
    struct AccessResult;  
    struct Data;  
    struct VariableAccessSpecification;  
    struct VariableSpecification;  
    struct Read_Request;  
    struct Read_Response;  
    struct Write_Request;  
    struct InformationReport;  
    struct GetVariableAccessAttributes_Request;  
    struct GetVariableAccessAttributes_Response;  
    struct DefineNamedVariable_Request;  
    struct DeleteVariableAccess_Request;  
    struct DeleteVariableAccess_Response;  
    struct DefineNamedVariableList_Request;  
    struct GetNamedVariableListAttributes_Response;  
    struct DeleteNamedVariableList_Request;  
    struct DeleteNamedVariableList_Response;  
    struct DefineNamedType_Request;  
    struct GetNamedTypeAttributes_Response;  
    struct DeleteNamedType_Request;  
    struct DeleteNamedType_Response;  
    struct ExchangeData_Request;  
    struct ExchangeData_Response;  
    struct GetDataExchangeAttributes_Response;  
    struct TakeControl_Request;  
    struct TakeControl_Response;  
    struct RelinquishControl_Request;  
    struct DefineSemaphore_Request;  
    struct ReportSemaphoreStatus_Response;  
    struct ReportPoolSemaphoreStatus_Request;  
    struct ReportPoolSemaphoreStatus_Response;  
    struct ReportSemaphoreEntryStatus_Request;  
    struct ReportSemaphoreEntryStatus_Response;  
    struct SemaphoreEntry;  
    struct AttachToSemaphore;  
    struct Input_Request;  
    struct Output_Request;  
    struct TriggerEvent_Request;  
    struct EventNotification;  
    struct CS_EventNotification_impl;  
    struct AcknowledgeEventNotification_Request;  
    struct GetAlarmSummary_Request;  
    struct GetAlarmSummary_Response;  
    struct AlarmSummary;  
    struct EN_Additional_Detail_impl;  
    struct GetAlarmEnrollmentSummary_Request;  
    struct GetAlarmEnrollmentSummary_Response;  
    struct AlarmEnrollmentSummary;  
    struct AttachToEventCondition;  
    struct DefineEventCondition_Request;  
    struct CS_DefineEventCondition_Request_impl;  
    struct DeleteEventCondition_Request;  
    struct GetEventConditionAttributes_Response;  
    struct CS_GetEventConditionAttributes_Response;  
    struct ReportEventConditionStatus_Response;  
    struct AlterEventConditionMonitoring_Request;  
    struct CS_AlterEventConditionMonitoring_Request;  
    struct DefineEventAction_Request;  
    struct DeleteEventAction_Request;  
    struct GetEventActionAttributes_Response;  
    struct DefineEventEnrollment_Request;  
    struct CS_DefineEventEnrollment_Request_impl;  
    struct DeleteEventEnrollment_Request;  
    struct GetEventEnrollmentAttributes_Request;  
    struct GetEventEnrollmentAttributes_Response;  
    struct EEAttributes;  
    struct ReportEventEnrollmentStatus_Response;  
    struct AlterEventEnrollment_Request;  
    struct AlterEventEnrollment_Response;  
    struct CS_AlterEventEnrollment_Request;  
    struct DefineEventConditionList_Request;  
    struct AddEventConditionListReference_Request;  
    struct RemoveEventConditionListReference_Request;  
    struct RemoveEventConditionListReference_Error;  
    struct GetEventConditionListAttributes_Response;  
    struct ReportEventConditionListStatus_Request;  
    struct ReportEventConditionListStatus_Response;  
    struct EventConditionStatus;  
    struct AlterEventConditionListMonitoring_Request;  
    struct ReadJournal_Request;  
    struct ReadJournal_Response;  
    struct JournalEntry;  
    struct WriteJournal_Request;  
    struct InitializeJournal_Request;  
    struct ReportJournalStatus_Response;  
    struct CreateJournal_Request;  
    struct DeleteJournal_Request;  
    struct EntryContent;  

    struct AlternateAccess_sequence_of;
    struct Write_Response_sequence_of;
    typedef octetstring_type TimeOfDay;  
    typedef visiblestring_type Identifier;  
    typedef int Integer8;  
    typedef int Integer16;  
    typedef int Integer32;  
    typedef int Unsigned8;  
    typedef int Unsigned16;  
    typedef int Unsigned32;  
    typedef visiblestring_type MMSString;  
    typedef visiblestring_type MMS255String;  
    typedef null_type Conclude_RequestPDU;  
    typedef null_type Conclude_ResponsePDU;  
    typedef null_type DefineAccessControlList_Response;  
    typedef null_type DeleteAccessControlList_Response;  
    typedef int OperationState;  
    typedef bitstring_type ExtendedStatus;  
    typedef bool Status_Request;  
    typedef null_type Identify_Request;  
    typedef null_type Rename_Response;  
    typedef null_type VMDStop_Request;  
    typedef null_type VMDStop_Response;  
    typedef bool VMDReset_Request;  
    typedef null_type InitiateDownloadSequence_Response;  
    typedef null_type TerminateDownloadSequence_Response;  
    typedef null_type TerminateUploadSequence_Response;  
    typedef null_type RequestDomainDownload_Response;  
    typedef null_type RequestDomainUpload_Response;  
    typedef null_type LoadDomainContent_Response;  
    typedef null_type StoreDomainContent_Response;  
    typedef null_type DeleteDomain_Response;  
    typedef null_type CreateProgramInvocation_Response;  
    typedef int CS_CreateProgramInvocation_Request;  
    typedef null_type DeleteProgramInvocation_Response;  
    typedef null_type Start_Response;  
    typedef null_type Stop_Response;  
    typedef null_type Resume_Response;  
    typedef null_type Reset_Response;  
    typedef null_type Kill_Response;  
    typedef null_type Select_Response;  
    typedef null_type AlterProgramInvocationAttributes_Response;  
    typedef null_type ReconfigureProgramInvocation_Response;  
    typedef null_type InitiateUnitControlLoad_Response;  
    typedef null_type StartUnitControl_Response;  
    typedef null_type StopUnitControl_Response;  
    typedef null_type CreateUnitControl_Response;  
    typedef null_type AddToUnitControl_Response;  
    typedef null_type RemoveFromUnitControl_Response;  
    typedef null_type LoadUnitControlFromFile_Response;  
    typedef null_type StoreUnitControlToFile_Response;  
    typedef null_type DeleteUnitControl_Response;  
    typedef octetstring_type FloatingPoint;  
    typedef int DataAccessError;  
    typedef null_type DefineNamedVariable_Response;  
    typedef null_type DefineNamedVariableList_Response;  
    typedef null_type DefineNamedType_Response;  
    typedef null_type RelinquishControl_Response;  
    typedef null_type DefineSemaphore_Response;  
    typedef null_type DeleteSemaphore_Response;  
    typedef null_type Output_Response;  
    typedef null_type TriggerEvent_Response;  
    typedef null_type AcknowledgeEventNotification_Response;  
    typedef null_type DefineEventCondition_Response;  
    typedef null_type AlterEventConditionMonitoring_Response;  
    typedef null_type DefineEventAction_Response;  
    typedef null_type DefineEventEnrollment_Response;  
    typedef int EE_State;  
    typedef null_type DefineEventConditionList_Response;  
    typedef null_type DeleteEventConditionList_Response;  
    typedef null_type AddEventConditionListReference_Response;  
    typedef null_type RemoveEventConditionListReference_Response;  
    typedef null_type AlterEventConditionListMonitoring_Response;  
    typedef null_type WriteJournal_Response;  
    typedef null_type CreateJournal_Response;  
    typedef null_type DeleteJournal_Response;  


    typedef std::vector< graphicstring_type> FileName;


    typedef ServiceError Initiate_ErrorPDU;
    typedef ServiceError Conclude_ErrorPDU;
    typedef Unsigned32 Cancel_RequestPDU;
    typedef Unsigned32 Cancel_ResponsePDU;
    typedef Identifier DeleteAccessControlList_Request;
    typedef Unsigned32 ChangeAccessControl_Error;
    typedef StatusResponse Status_Response;
    typedef StatusResponse UnsolicitedStatus;
    typedef StatusResponse VMDReset_Response;
    typedef Identifier DownloadSegment_Request;
    typedef Identifier InitiateUploadSequence_Request;
    typedef Integer32 UploadSegment_Request;
    typedef Integer32 TerminateUploadSequence_Request;
    typedef Identifier DeleteDomain_Request;
    typedef Identifier GetDomainAttributes_Request;
    typedef Identifier DeleteProgramInvocation_Request;
    BOOST_ASN_EXPLICIT_TYPEDEF( CS_Start_Request, CS_Start_Request_impl, 0, CONTEXT_CLASS);
    BOOST_ASN_EXPLICIT_TYPEDEF( CS_Resume_Request, CS_Resume_Request_impl, 0, CONTEXT_CLASS);
    typedef Identifier GetProgramInvocationAttributes_Request;
    typedef Identifier InitiateUnitControlLoad_Request;
    typedef Identifier UnitControlLoadSegment_Request;
    typedef Identifier StopUnitControl_Request;
    typedef Identifier GetUnitControlAttributes_Request;
    typedef Identifier DeleteUnitControl_Request;
    typedef Unsigned32 DeleteVariableAccess_Error;
    typedef ObjectName GetNamedVariableListAttributes_Request;
    typedef Unsigned32 DeleteNamedVariableList_Error;
    typedef ObjectName GetNamedTypeAttributes_Request;
    typedef Unsigned32 DeleteNamedType_Error;
    typedef ObjectName GetDataExchangeAttributes_Request;
    typedef ObjectName DeleteSemaphore_Request;
    typedef ObjectName ReportSemaphoreStatus_Request;
    typedef MMSString Input_Response;
    BOOST_ASN_EXPLICIT_TYPEDEF( CS_EventNotification, CS_EventNotification_impl, 0, CONTEXT_CLASS);
    BOOST_ASN_EXPLICIT_TYPEDEF( EN_Additional_Detail, EN_Additional_Detail_impl, 0, CONTEXT_CLASS);
    BOOST_ASN_EXPLICIT_TYPEDEF( CS_DefineEventCondition_Request, CS_DefineEventCondition_Request_impl, 0, CONTEXT_CLASS);
    typedef Unsigned32 DeleteEventCondition_Response;
    typedef ObjectName GetEventConditionAttributes_Request;
    typedef ObjectName ReportEventConditionStatus_Request;
    typedef Unsigned32 DeleteEventAction_Response;
    typedef ObjectName GetEventActionAttributes_Request;
    typedef ObjectName ReportEventActionStatus_Request;
    typedef Unsigned32 ReportEventActionStatus_Response;
    typedef ObjectName DefineEventEnrollment_Error;
    BOOST_ASN_EXPLICIT_TYPEDEF( CS_DefineEventEnrollment_Request, CS_DefineEventEnrollment_Request_impl, 0, CONTEXT_CLASS);
    typedef Unsigned32 DeleteEventEnrollment_Response;
    typedef ObjectName ReportEventEnrollmentStatus_Request;
    typedef ObjectName DefineEventConditionList_Error;
    typedef ObjectName DeleteEventConditionList_Request;
    typedef ObjectName AddEventConditionListReference_Error;
    typedef ObjectName GetEventConditionListAttributes_Request;
    typedef Unsigned32 InitializeJournal_Response;
    typedef ObjectName ReportJournalStatus_Request;
    typedef std::deque< AlternateAccess_sequence_of > AlternateAccess;
    typedef std::deque< Write_Response_sequence_of > Write_Response;

        extern const int maxIdentifier;

} 

#include "MMS-Environment-1.hpp"
#include "MMS-Environment-1.hpp"
#include "ISO-9506-MMS-1A.hpp"
#include "MMS-Object-Module-1.hpp"

namespace ISO_9506_MMS_1 {

  // import   from  MMS-Environment-1

    using MMS_Environment_1::ApplicationReference;


  // import   from  MMS-Environment-1



  // import   from  ISO-9506-MMS-1A

    using ISO_9506_MMS_1A::ScatteredAccessDescription;


  // import   from  MMS-Object-Module-1

    using MMS_Object_Module_1::AccessCondition;
    using MMS_Object_Module_1::AdditionalCBBOptions;
    using MMS_Object_Module_1::AdditionalSupportOptions;
    using MMS_Object_Module_1::Address;
    using MMS_Object_Module_1::AlarmAckRule;
    using MMS_Object_Module_1::DomainState;
    using MMS_Object_Module_1::EventTime;
    using MMS_Object_Module_1::LogicalStatus;
    using MMS_Object_Module_1::Modifier;
    using MMS_Object_Module_1::normalPriority;
    using MMS_Object_Module_1::normalSeverity;
    using MMS_Object_Module_1::ParameterSupportOptions;
    using MMS_Object_Module_1::PhysicalStatus;
    using MMS_Object_Module_1::Priority;
    using MMS_Object_Module_1::ProgramInvocationState;
    using MMS_Object_Module_1::ServiceSupportOptions;
    using MMS_Object_Module_1::Severity;
    using MMS_Object_Module_1::Transitions;
    using MMS_Object_Module_1::TypeDescription;
    using MMS_Object_Module_1::ULState;
    using MMS_Object_Module_1::VMDState;



    typedef MMS_Object_Module_1::ProgramInvocationState Start_Error;
    typedef MMS_Object_Module_1::ProgramInvocationState Stop_Error;
    typedef MMS_Object_Module_1::ProgramInvocationState Resume_Error;
    typedef MMS_Object_Module_1::ProgramInvocationState Reset_Error;

        // choice MMSpdu
        enum MMSpdu_enum {
            MMSpdu_null = 0, 
            MMSpdu_confirmed_RequestPDU,
            MMSpdu_confirmed_ResponsePDU,
            MMSpdu_confirmed_ErrorPDU,
            MMSpdu_unconfirmed_PDU,
            MMSpdu_rejectPDU,
            MMSpdu_cancel_RequestPDU,
            MMSpdu_cancel_ResponsePDU,
            MMSpdu_cancel_ErrorPDU,
            MMSpdu_initiate_RequestPDU,
            MMSpdu_initiate_ResponsePDU,
            MMSpdu_initiate_ErrorPDU,
            MMSpdu_conclude_RequestPDU,
            MMSpdu_conclude_ResponsePDU,
            MMSpdu_conclude_ErrorPDU,}; 
 
        struct MMSpdu : public BOOST_ASN_CHOICE_STRUCT(MMSpdu_enum) {



            MMSpdu() :  BOOST_ASN_CHOICE_STRUCT(MMSpdu_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(confirmed_RequestPDU, Confirmed_RequestPDU, MMSpdu_confirmed_RequestPDU);
            BOOST_ASN_VALUE_CHOICE(confirmed_ResponsePDU, Confirmed_ResponsePDU, MMSpdu_confirmed_ResponsePDU);
            BOOST_ASN_VALUE_CHOICE(confirmed_ErrorPDU, Confirmed_ErrorPDU, MMSpdu_confirmed_ErrorPDU);
            BOOST_ASN_VALUE_CHOICE(unconfirmed_PDU, Unconfirmed_PDU, MMSpdu_unconfirmed_PDU);
            BOOST_ASN_VALUE_CHOICE(rejectPDU, RejectPDU, MMSpdu_rejectPDU);
            BOOST_ASN_VALUE_CHOICE(cancel_RequestPDU, Cancel_RequestPDU, MMSpdu_cancel_RequestPDU);
            BOOST_ASN_VALUE_CHOICE(cancel_ResponsePDU, Cancel_ResponsePDU, MMSpdu_cancel_ResponsePDU);
            BOOST_ASN_VALUE_CHOICE(cancel_ErrorPDU, Cancel_ErrorPDU, MMSpdu_cancel_ErrorPDU);
            BOOST_ASN_VALUE_CHOICE(initiate_RequestPDU, Initiate_RequestPDU, MMSpdu_initiate_RequestPDU);
            BOOST_ASN_VALUE_CHOICE(initiate_ResponsePDU, Initiate_ResponsePDU, MMSpdu_initiate_ResponsePDU);
            BOOST_ASN_VALUE_CHOICE(initiate_ErrorPDU, Initiate_ErrorPDU, MMSpdu_initiate_ErrorPDU);
            BOOST_ASN_VALUE_CHOICE(conclude_RequestPDU, Conclude_RequestPDU, MMSpdu_conclude_RequestPDU);
            BOOST_ASN_VALUE_CHOICE(conclude_ResponsePDU, Conclude_ResponsePDU, MMSpdu_conclude_ResponsePDU);
            BOOST_ASN_VALUE_CHOICE(conclude_ErrorPDU, Conclude_ErrorPDU, MMSpdu_conclude_ErrorPDU);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Confirmed-RequestPDU
        struct Confirmed_RequestPDU{

        typedef std::vector< MMS_Object_Module_1::Modifier> listOfModifiers_type;


            Confirmed_RequestPDU() : invokeID(), service() {} 
 
            boost::asn1::value_holder<Unsigned32> invokeID;
            boost::shared_ptr<listOfModifiers_type> listOfModifiers;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfModifiers_type, listOfModifiers)

            boost::asn1::value_holder<ConfirmedServiceRequest> service;
            boost::shared_ptr<Request_Detail> service_ext;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Request_Detail, service_ext)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice ConfirmedServiceRequest
        enum ConfirmedServiceRequest_enum {
            ConfirmedServiceRequest_null = 0, 
            ConfirmedServiceRequest_status,
            ConfirmedServiceRequest_getNameList,
            ConfirmedServiceRequest_identify,
            ConfirmedServiceRequest_rename,
            ConfirmedServiceRequest_read,
            ConfirmedServiceRequest_write,
            ConfirmedServiceRequest_getVariableAccessAttributes,
            ConfirmedServiceRequest_defineNamedVariable,
            ConfirmedServiceRequest_defineScatteredAccess,
            ConfirmedServiceRequest_getScatteredAccessAttributes,
            ConfirmedServiceRequest_deleteVariableAccess,
            ConfirmedServiceRequest_defineNamedVariableList,
            ConfirmedServiceRequest_getNamedVariableListAttributes,
            ConfirmedServiceRequest_deleteNamedVariableList,
            ConfirmedServiceRequest_defineNamedType,
            ConfirmedServiceRequest_getNamedTypeAttributes,
            ConfirmedServiceRequest_deleteNamedType,
            ConfirmedServiceRequest_input,
            ConfirmedServiceRequest_output,
            ConfirmedServiceRequest_takeControl,
            ConfirmedServiceRequest_relinquishControl,
            ConfirmedServiceRequest_defineSemaphore,
            ConfirmedServiceRequest_deleteSemaphore,
            ConfirmedServiceRequest_reportSemaphoreStatus,
            ConfirmedServiceRequest_reportPoolSemaphoreStatus,
            ConfirmedServiceRequest_reportSemaphoreEntryStatus,
            ConfirmedServiceRequest_initiateDownloadSequence,
            ConfirmedServiceRequest_downloadSegment,
            ConfirmedServiceRequest_terminateDownloadSequence,
            ConfirmedServiceRequest_initiateUploadSequence,
            ConfirmedServiceRequest_uploadSegment,
            ConfirmedServiceRequest_terminateUploadSequence,
            ConfirmedServiceRequest_requestDomainDownload,
            ConfirmedServiceRequest_requestDomainUpload,
            ConfirmedServiceRequest_loadDomainContent,
            ConfirmedServiceRequest_storeDomainContent,
            ConfirmedServiceRequest_deleteDomain,
            ConfirmedServiceRequest_getDomainAttributes,
            ConfirmedServiceRequest_createProgramInvocation,
            ConfirmedServiceRequest_deleteProgramInvocation,
            ConfirmedServiceRequest_start,
            ConfirmedServiceRequest_stop,
            ConfirmedServiceRequest_resume,
            ConfirmedServiceRequest_reset,
            ConfirmedServiceRequest_kill,
            ConfirmedServiceRequest_getProgramInvocationAttributes,
            ConfirmedServiceRequest_obtainFile,
            ConfirmedServiceRequest_defineEventCondition,
            ConfirmedServiceRequest_deleteEventCondition,
            ConfirmedServiceRequest_getEventConditionAttributes,
            ConfirmedServiceRequest_reportEventConditionStatus,
            ConfirmedServiceRequest_alterEventConditionMonitoring,
            ConfirmedServiceRequest_triggerEvent,
            ConfirmedServiceRequest_defineEventAction,
            ConfirmedServiceRequest_deleteEventAction,
            ConfirmedServiceRequest_getEventActionAttributes,
            ConfirmedServiceRequest_reportEventActionStatus,
            ConfirmedServiceRequest_defineEventEnrollment,
            ConfirmedServiceRequest_deleteEventEnrollment,
            ConfirmedServiceRequest_alterEventEnrollment,
            ConfirmedServiceRequest_reportEventEnrollmentStatus,
            ConfirmedServiceRequest_getEventEnrollmentAttributes,
            ConfirmedServiceRequest_acknowledgeEventNotification,
            ConfirmedServiceRequest_getAlarmSummary,
            ConfirmedServiceRequest_getAlarmEnrollmentSummary,
            ConfirmedServiceRequest_readJournal,
            ConfirmedServiceRequest_writeJournal,
            ConfirmedServiceRequest_initializeJournal,
            ConfirmedServiceRequest_reportJournalStatus,
            ConfirmedServiceRequest_createJournal,
            ConfirmedServiceRequest_deleteJournal,
            ConfirmedServiceRequest_getCapabilityList,
            ConfirmedServiceRequest_fileOpen,
            ConfirmedServiceRequest_fileRead,
            ConfirmedServiceRequest_fileClose,
            ConfirmedServiceRequest_fileRename,
            ConfirmedServiceRequest_fileDelete,
            ConfirmedServiceRequest_fileDirectory,
            ConfirmedServiceRequest_additionalService,
            ConfirmedServiceRequest_getDataExchangeAttributes,
            ConfirmedServiceRequest_exchangeData,
            ConfirmedServiceRequest_defineAccessControlList,
            ConfirmedServiceRequest_getAccessControlListAttributes,
            ConfirmedServiceRequest_reportAccessControlledObjects,
            ConfirmedServiceRequest_deleteAccessControlList,
            ConfirmedServiceRequest_changeAccessControl,}; 
 
        struct ConfirmedServiceRequest : public BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceRequest_enum) {



            ConfirmedServiceRequest() :  BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceRequest_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(status, Status_Request, ConfirmedServiceRequest_status);
            BOOST_ASN_VALUE_CHOICE(getNameList, GetNameList_Request, ConfirmedServiceRequest_getNameList);
            BOOST_ASN_VALUE_CHOICE(identify, Identify_Request, ConfirmedServiceRequest_identify);
            BOOST_ASN_VALUE_CHOICE(rename, Rename_Request, ConfirmedServiceRequest_rename);
            BOOST_ASN_VALUE_CHOICE(read, Read_Request, ConfirmedServiceRequest_read);
            BOOST_ASN_VALUE_CHOICE(write, Write_Request, ConfirmedServiceRequest_write);
            BOOST_ASN_VALUE_CHOICE(getVariableAccessAttributes, GetVariableAccessAttributes_Request, ConfirmedServiceRequest_getVariableAccessAttributes);
            BOOST_ASN_VALUE_CHOICE(defineNamedVariable, DefineNamedVariable_Request, ConfirmedServiceRequest_defineNamedVariable);
            BOOST_ASN_VALUE_CHOICE(defineScatteredAccess, ObjectName, ConfirmedServiceRequest_defineScatteredAccess);
            BOOST_ASN_VALUE_CHOICE(getScatteredAccessAttributes, ObjectName, ConfirmedServiceRequest_getScatteredAccessAttributes);
            BOOST_ASN_VALUE_CHOICE(deleteVariableAccess, DeleteVariableAccess_Request, ConfirmedServiceRequest_deleteVariableAccess);
            BOOST_ASN_VALUE_CHOICE(defineNamedVariableList, DefineNamedVariableList_Request, ConfirmedServiceRequest_defineNamedVariableList);
            BOOST_ASN_VALUE_CHOICE(getNamedVariableListAttributes, GetNamedVariableListAttributes_Request, ConfirmedServiceRequest_getNamedVariableListAttributes);
            BOOST_ASN_VALUE_CHOICE(deleteNamedVariableList, DeleteNamedVariableList_Request, ConfirmedServiceRequest_deleteNamedVariableList);
            BOOST_ASN_VALUE_CHOICE(defineNamedType, DefineNamedType_Request, ConfirmedServiceRequest_defineNamedType);
            BOOST_ASN_VALUE_CHOICE(getNamedTypeAttributes, GetNamedTypeAttributes_Request, ConfirmedServiceRequest_getNamedTypeAttributes);
            BOOST_ASN_VALUE_CHOICE(deleteNamedType, DeleteNamedType_Request, ConfirmedServiceRequest_deleteNamedType);
            BOOST_ASN_VALUE_CHOICE(input, Input_Request, ConfirmedServiceRequest_input);
            BOOST_ASN_VALUE_CHOICE(output, Output_Request, ConfirmedServiceRequest_output);
            BOOST_ASN_VALUE_CHOICE(takeControl, TakeControl_Request, ConfirmedServiceRequest_takeControl);
            BOOST_ASN_VALUE_CHOICE(relinquishControl, RelinquishControl_Request, ConfirmedServiceRequest_relinquishControl);
            BOOST_ASN_VALUE_CHOICE(defineSemaphore, DefineSemaphore_Request, ConfirmedServiceRequest_defineSemaphore);
            BOOST_ASN_VALUE_CHOICE(deleteSemaphore, DeleteSemaphore_Request, ConfirmedServiceRequest_deleteSemaphore);
            BOOST_ASN_VALUE_CHOICE(reportSemaphoreStatus, ReportSemaphoreStatus_Request, ConfirmedServiceRequest_reportSemaphoreStatus);
            BOOST_ASN_VALUE_CHOICE(reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Request, ConfirmedServiceRequest_reportPoolSemaphoreStatus);
            BOOST_ASN_VALUE_CHOICE(reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Request, ConfirmedServiceRequest_reportSemaphoreEntryStatus);
            BOOST_ASN_VALUE_CHOICE(initiateDownloadSequence, InitiateDownloadSequence_Request, ConfirmedServiceRequest_initiateDownloadSequence);
            BOOST_ASN_VALUE_CHOICE(downloadSegment, DownloadSegment_Request, ConfirmedServiceRequest_downloadSegment);
            BOOST_ASN_VALUE_CHOICE(terminateDownloadSequence, TerminateDownloadSequence_Request, ConfirmedServiceRequest_terminateDownloadSequence);
            BOOST_ASN_VALUE_CHOICE(initiateUploadSequence, InitiateUploadSequence_Request, ConfirmedServiceRequest_initiateUploadSequence);
            BOOST_ASN_VALUE_CHOICE(uploadSegment, UploadSegment_Request, ConfirmedServiceRequest_uploadSegment);
            BOOST_ASN_VALUE_CHOICE(terminateUploadSequence, TerminateUploadSequence_Request, ConfirmedServiceRequest_terminateUploadSequence);
            BOOST_ASN_VALUE_CHOICE(requestDomainDownload, RequestDomainDownload_Request, ConfirmedServiceRequest_requestDomainDownload);
            BOOST_ASN_VALUE_CHOICE(requestDomainUpload, RequestDomainUpload_Request, ConfirmedServiceRequest_requestDomainUpload);
            BOOST_ASN_VALUE_CHOICE(loadDomainContent, LoadDomainContent_Request, ConfirmedServiceRequest_loadDomainContent);
            BOOST_ASN_VALUE_CHOICE(storeDomainContent, StoreDomainContent_Request, ConfirmedServiceRequest_storeDomainContent);
            BOOST_ASN_VALUE_CHOICE(deleteDomain, DeleteDomain_Request, ConfirmedServiceRequest_deleteDomain);
            BOOST_ASN_VALUE_CHOICE(getDomainAttributes, GetDomainAttributes_Request, ConfirmedServiceRequest_getDomainAttributes);
            BOOST_ASN_VALUE_CHOICE(createProgramInvocation, CreateProgramInvocation_Request, ConfirmedServiceRequest_createProgramInvocation);
            BOOST_ASN_VALUE_CHOICE(deleteProgramInvocation, DeleteProgramInvocation_Request, ConfirmedServiceRequest_deleteProgramInvocation);
            BOOST_ASN_VALUE_CHOICE(start, Start_Request, ConfirmedServiceRequest_start);
            BOOST_ASN_VALUE_CHOICE(stop, Stop_Request, ConfirmedServiceRequest_stop);
            BOOST_ASN_VALUE_CHOICE(resume, Resume_Request, ConfirmedServiceRequest_resume);
            BOOST_ASN_VALUE_CHOICE(reset, Reset_Request, ConfirmedServiceRequest_reset);
            BOOST_ASN_VALUE_CHOICE(kill, Kill_Request, ConfirmedServiceRequest_kill);
            BOOST_ASN_VALUE_CHOICE(getProgramInvocationAttributes, GetProgramInvocationAttributes_Request, ConfirmedServiceRequest_getProgramInvocationAttributes);
            BOOST_ASN_VALUE_CHOICE(obtainFile, ISO_9506_MMS_1A::ObtainFile_Request, ConfirmedServiceRequest_obtainFile);
            BOOST_ASN_VALUE_CHOICE(defineEventCondition, DefineEventCondition_Request, ConfirmedServiceRequest_defineEventCondition);
            BOOST_ASN_VALUE_CHOICE(deleteEventCondition, DeleteEventCondition_Request, ConfirmedServiceRequest_deleteEventCondition);
            BOOST_ASN_VALUE_CHOICE(getEventConditionAttributes, GetEventConditionAttributes_Request, ConfirmedServiceRequest_getEventConditionAttributes);
            BOOST_ASN_VALUE_CHOICE(reportEventConditionStatus, ReportEventConditionStatus_Request, ConfirmedServiceRequest_reportEventConditionStatus);
            BOOST_ASN_VALUE_CHOICE(alterEventConditionMonitoring, AlterEventConditionMonitoring_Request, ConfirmedServiceRequest_alterEventConditionMonitoring);
            BOOST_ASN_VALUE_CHOICE(triggerEvent, TriggerEvent_Request, ConfirmedServiceRequest_triggerEvent);
            BOOST_ASN_VALUE_CHOICE(defineEventAction, DefineEventAction_Request, ConfirmedServiceRequest_defineEventAction);
            BOOST_ASN_VALUE_CHOICE(deleteEventAction, DeleteEventAction_Request, ConfirmedServiceRequest_deleteEventAction);
            BOOST_ASN_VALUE_CHOICE(getEventActionAttributes, GetEventActionAttributes_Request, ConfirmedServiceRequest_getEventActionAttributes);
            BOOST_ASN_VALUE_CHOICE(reportEventActionStatus, ReportEventActionStatus_Request, ConfirmedServiceRequest_reportEventActionStatus);
            BOOST_ASN_VALUE_CHOICE(defineEventEnrollment, DefineEventEnrollment_Request, ConfirmedServiceRequest_defineEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(deleteEventEnrollment, DeleteEventEnrollment_Request, ConfirmedServiceRequest_deleteEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(alterEventEnrollment, AlterEventEnrollment_Request, ConfirmedServiceRequest_alterEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Request, ConfirmedServiceRequest_reportEventEnrollmentStatus);
            BOOST_ASN_VALUE_CHOICE(getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Request, ConfirmedServiceRequest_getEventEnrollmentAttributes);
            BOOST_ASN_VALUE_CHOICE(acknowledgeEventNotification, AcknowledgeEventNotification_Request, ConfirmedServiceRequest_acknowledgeEventNotification);
            BOOST_ASN_VALUE_CHOICE(getAlarmSummary, GetAlarmSummary_Request, ConfirmedServiceRequest_getAlarmSummary);
            BOOST_ASN_VALUE_CHOICE(getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Request, ConfirmedServiceRequest_getAlarmEnrollmentSummary);
            BOOST_ASN_VALUE_CHOICE(readJournal, ReadJournal_Request, ConfirmedServiceRequest_readJournal);
            BOOST_ASN_VALUE_CHOICE(writeJournal, WriteJournal_Request, ConfirmedServiceRequest_writeJournal);
            BOOST_ASN_VALUE_CHOICE(initializeJournal, InitializeJournal_Request, ConfirmedServiceRequest_initializeJournal);
            BOOST_ASN_VALUE_CHOICE(reportJournalStatus, ReportJournalStatus_Request, ConfirmedServiceRequest_reportJournalStatus);
            BOOST_ASN_VALUE_CHOICE(createJournal, CreateJournal_Request, ConfirmedServiceRequest_createJournal);
            BOOST_ASN_VALUE_CHOICE(deleteJournal, DeleteJournal_Request, ConfirmedServiceRequest_deleteJournal);
            BOOST_ASN_VALUE_CHOICE(getCapabilityList, GetCapabilityList_Request, ConfirmedServiceRequest_getCapabilityList);
            BOOST_ASN_VALUE_CHOICE(fileOpen, ISO_9506_MMS_1A::FileOpen_Request, ConfirmedServiceRequest_fileOpen);
            BOOST_ASN_VALUE_CHOICE(fileRead, Integer32, ConfirmedServiceRequest_fileRead);
            BOOST_ASN_VALUE_CHOICE(fileClose, Integer32 , ConfirmedServiceRequest_fileClose);
            BOOST_ASN_VALUE_CHOICE(fileRename, ISO_9506_MMS_1A::FileRename_Request, ConfirmedServiceRequest_fileRename);
            BOOST_ASN_VALUE_CHOICE(fileDelete, FileName, ConfirmedServiceRequest_fileDelete);
            BOOST_ASN_VALUE_CHOICE(fileDirectory, ISO_9506_MMS_1A::FileDirectory_Request, ConfirmedServiceRequest_fileDirectory);
            BOOST_ASN_VALUE_CHOICE(additionalService, AdditionalService_Request, ConfirmedServiceRequest_additionalService);
            BOOST_ASN_VALUE_CHOICE(getDataExchangeAttributes, GetDataExchangeAttributes_Request, ConfirmedServiceRequest_getDataExchangeAttributes);
            BOOST_ASN_VALUE_CHOICE(exchangeData, ExchangeData_Request, ConfirmedServiceRequest_exchangeData);
            BOOST_ASN_VALUE_CHOICE(defineAccessControlList, DefineAccessControlList_Request, ConfirmedServiceRequest_defineAccessControlList);
            BOOST_ASN_VALUE_CHOICE(getAccessControlListAttributes, GetAccessControlListAttributes_Request, ConfirmedServiceRequest_getAccessControlListAttributes);
            BOOST_ASN_VALUE_CHOICE(reportAccessControlledObjects, ReportAccessControlledObjects_Request, ConfirmedServiceRequest_reportAccessControlledObjects);
            BOOST_ASN_VALUE_CHOICE(deleteAccessControlList, DeleteAccessControlList_Request, ConfirmedServiceRequest_deleteAccessControlList);
            BOOST_ASN_VALUE_CHOICE(changeAccessControl, ChangeAccessControl_Request, ConfirmedServiceRequest_changeAccessControl);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice AdditionalService-Request
        enum AdditionalService_Request_enum {
            AdditionalService_Request_null = 0, 
            AdditionalService_Request_vMDStop,
            AdditionalService_Request_vMDReset,
            AdditionalService_Request_select,
            AdditionalService_Request_alterPI,
            AdditionalService_Request_initiateUCLoad,
            AdditionalService_Request_uCLoad,
            AdditionalService_Request_uCUpload,
            AdditionalService_Request_startUC,
            AdditionalService_Request_stopUC,
            AdditionalService_Request_createUC,
            AdditionalService_Request_addToUC,
            AdditionalService_Request_removeFromUC,
            AdditionalService_Request_getUCAttributes,
            AdditionalService_Request_loadUCFromFile,
            AdditionalService_Request_storeUCToFile,
            AdditionalService_Request_deleteUC,
            AdditionalService_Request_defineECL,
            AdditionalService_Request_deleteECL,
            AdditionalService_Request_addECLReference,
            AdditionalService_Request_removeECLReference,
            AdditionalService_Request_getECLAttributes,
            AdditionalService_Request_reportECLStatus,
            AdditionalService_Request_alterECLMonitoring,}; 
 
        struct AdditionalService_Request : public BOOST_ASN_CHOICE_STRUCT(AdditionalService_Request_enum) {



            AdditionalService_Request() :  BOOST_ASN_CHOICE_STRUCT(AdditionalService_Request_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(vMDStop, VMDStop_Request, AdditionalService_Request_vMDStop);
            BOOST_ASN_VALUE_CHOICE(vMDReset, VMDReset_Request, AdditionalService_Request_vMDReset);
            BOOST_ASN_VALUE_CHOICE(select, Select_Request, AdditionalService_Request_select);
            BOOST_ASN_VALUE_CHOICE(alterPI, AlterProgramInvocationAttributes_Request, AdditionalService_Request_alterPI);
            BOOST_ASN_VALUE_CHOICE(initiateUCLoad, InitiateUnitControlLoad_Request, AdditionalService_Request_initiateUCLoad);
            BOOST_ASN_VALUE_CHOICE(uCLoad, UnitControlLoadSegment_Request, AdditionalService_Request_uCLoad);
            BOOST_ASN_VALUE_CHOICE(uCUpload, UnitControlUpload_Request, AdditionalService_Request_uCUpload);
            BOOST_ASN_VALUE_CHOICE(startUC, StartUnitControl_Request, AdditionalService_Request_startUC);
            BOOST_ASN_VALUE_CHOICE(stopUC, StopUnitControl_Request, AdditionalService_Request_stopUC);
            BOOST_ASN_VALUE_CHOICE(createUC, CreateUnitControl_Request, AdditionalService_Request_createUC);
            BOOST_ASN_VALUE_CHOICE(addToUC, AddToUnitControl_Request, AdditionalService_Request_addToUC);
            BOOST_ASN_VALUE_CHOICE(removeFromUC, RemoveFromUnitControl_Request, AdditionalService_Request_removeFromUC);
            BOOST_ASN_VALUE_CHOICE(getUCAttributes, GetUnitControlAttributes_Request, AdditionalService_Request_getUCAttributes);
            BOOST_ASN_VALUE_CHOICE(loadUCFromFile, LoadUnitControlFromFile_Request, AdditionalService_Request_loadUCFromFile);
            BOOST_ASN_VALUE_CHOICE(storeUCToFile, StoreUnitControlToFile_Request, AdditionalService_Request_storeUCToFile);
            BOOST_ASN_VALUE_CHOICE(deleteUC, DeleteUnitControl_Request, AdditionalService_Request_deleteUC);
            BOOST_ASN_VALUE_CHOICE(defineECL, DefineEventConditionList_Request, AdditionalService_Request_defineECL);
            BOOST_ASN_VALUE_CHOICE(deleteECL, DeleteEventConditionList_Request, AdditionalService_Request_deleteECL);
            BOOST_ASN_VALUE_CHOICE(addECLReference, AddEventConditionListReference_Request, AdditionalService_Request_addECLReference);
            BOOST_ASN_VALUE_CHOICE(removeECLReference, RemoveEventConditionListReference_Request, AdditionalService_Request_removeECLReference);
            BOOST_ASN_VALUE_CHOICE(getECLAttributes, GetEventConditionListAttributes_Request, AdditionalService_Request_getECLAttributes);
            BOOST_ASN_VALUE_CHOICE(reportECLStatus, ReportEventConditionListStatus_Request, AdditionalService_Request_reportECLStatus);
            BOOST_ASN_VALUE_CHOICE(alterECLMonitoring, AlterEventConditionListMonitoring_Request, AdditionalService_Request_alterECLMonitoring);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice Request-Detail
        enum Request_Detail_enum {
            Request_Detail_null = 0, 
            Request_Detail_otherRequests,
            Request_Detail_createProgramInvocation,
            Request_Detail_start,
            Request_Detail_resume,
            Request_Detail_defineEventCondition,
            Request_Detail_alterEventConditionMonitoring,
            Request_Detail_defineEventEnrollment,
            Request_Detail_alterEventEnrollment,}; 
 
        struct Request_Detail : public BOOST_ASN_CHOICE_STRUCT(Request_Detail_enum) {



            Request_Detail() :  BOOST_ASN_CHOICE_STRUCT(Request_Detail_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(otherRequests, null_type, Request_Detail_otherRequests);
            BOOST_ASN_VALUE_CHOICE(createProgramInvocation, CS_CreateProgramInvocation_Request, Request_Detail_createProgramInvocation);
            BOOST_ASN_VALUE_CHOICE(start, CS_Start_Request, Request_Detail_start);
            BOOST_ASN_VALUE_CHOICE(resume, CS_Resume_Request, Request_Detail_resume);
            BOOST_ASN_VALUE_CHOICE(defineEventCondition, CS_DefineEventCondition_Request, Request_Detail_defineEventCondition);
            BOOST_ASN_VALUE_CHOICE(alterEventConditionMonitoring, CS_AlterEventConditionMonitoring_Request, Request_Detail_alterEventConditionMonitoring);
            BOOST_ASN_VALUE_CHOICE(defineEventEnrollment, CS_DefineEventEnrollment_Request, Request_Detail_defineEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(alterEventEnrollment, CS_AlterEventEnrollment_Request, Request_Detail_alterEventEnrollment);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Unconfirmed-PDU
        struct Unconfirmed_PDU{



            Unconfirmed_PDU() : service() {} 
 
            boost::asn1::value_holder<UnconfirmedService> service;
            boost::shared_ptr<Unconfirmed_Detail> service_ext;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unconfirmed_Detail, service_ext)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice UnconfirmedService
        enum UnconfirmedService_enum {
            UnconfirmedService_null = 0, 
            UnconfirmedService_informationReport,
            UnconfirmedService_unsolicitedStatus,
            UnconfirmedService_eventNotification,}; 
 
        struct UnconfirmedService : public BOOST_ASN_CHOICE_STRUCT(UnconfirmedService_enum) {



            UnconfirmedService() :  BOOST_ASN_CHOICE_STRUCT(UnconfirmedService_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(informationReport, InformationReport, UnconfirmedService_informationReport);
            BOOST_ASN_VALUE_CHOICE(unsolicitedStatus, UnsolicitedStatus, UnconfirmedService_unsolicitedStatus);
            BOOST_ASN_VALUE_CHOICE(eventNotification, EventNotification, UnconfirmedService_eventNotification);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice Unconfirmed-Detail
        enum Unconfirmed_Detail_enum {
            Unconfirmed_Detail_null = 0, 
            Unconfirmed_Detail_otherRequests,
            Unconfirmed_Detail_eventNotification,}; 
 
        struct Unconfirmed_Detail : public BOOST_ASN_CHOICE_STRUCT(Unconfirmed_Detail_enum) {



            Unconfirmed_Detail() :  BOOST_ASN_CHOICE_STRUCT(Unconfirmed_Detail_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(otherRequests, null_type, Unconfirmed_Detail_otherRequests);
            BOOST_ASN_VALUE_CHOICE(eventNotification, CS_EventNotification, Unconfirmed_Detail_eventNotification);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Confirmed-ResponsePDU
        struct Confirmed_ResponsePDU{



            Confirmed_ResponsePDU() : invokeID(), service() {} 
 
            boost::asn1::value_holder<Unsigned32> invokeID;
            boost::asn1::value_holder<ConfirmedServiceResponse> service;
            boost::shared_ptr<Response_Detail> service_ext;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Response_Detail, service_ext)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice ConfirmedServiceResponse
        enum ConfirmedServiceResponse_enum {
            ConfirmedServiceResponse_null = 0, 
            ConfirmedServiceResponse_status,
            ConfirmedServiceResponse_getNameList,
            ConfirmedServiceResponse_identify,
            ConfirmedServiceResponse_rename,
            ConfirmedServiceResponse_read,
            ConfirmedServiceResponse_getVariableAccessAttributes,
            ConfirmedServiceResponse_defineNamedVariable,
            ConfirmedServiceResponse_defineScatteredAccess,
            ConfirmedServiceResponse_getScatteredAccessAttributes,
            ConfirmedServiceResponse_deleteVariableAccess,
            ConfirmedServiceResponse_defineNamedVariableList,
            ConfirmedServiceResponse_getNamedVariableListAttributes,
            ConfirmedServiceResponse_deleteNamedVariableList,
            ConfirmedServiceResponse_defineNamedType,
            ConfirmedServiceResponse_getNamedTypeAttributes,
            ConfirmedServiceResponse_deleteNamedType,
            ConfirmedServiceResponse_input,
            ConfirmedServiceResponse_output,
            ConfirmedServiceResponse_takeControl,
            ConfirmedServiceResponse_relinquishControl,
            ConfirmedServiceResponse_defineSemaphore,
            ConfirmedServiceResponse_deleteSemaphore,
            ConfirmedServiceResponse_reportSemaphoreStatus,
            ConfirmedServiceResponse_reportPoolSemaphoreStatus,
            ConfirmedServiceResponse_reportSemaphoreEntryStatus,
            ConfirmedServiceResponse_initiateDownloadSequence,
            ConfirmedServiceResponse_downloadSegment,
            ConfirmedServiceResponse_terminateDownloadSequence,
            ConfirmedServiceResponse_initiateUploadSequence,
            ConfirmedServiceResponse_uploadSegment,
            ConfirmedServiceResponse_terminateUploadSequence,
            ConfirmedServiceResponse_requestDomainDownload,
            ConfirmedServiceResponse_requestDomainUpload,
            ConfirmedServiceResponse_loadDomainContent,
            ConfirmedServiceResponse_storeDomainContent,
            ConfirmedServiceResponse_deleteDomain,
            ConfirmedServiceResponse_getDomainAttributes,
            ConfirmedServiceResponse_createProgramInvocation,
            ConfirmedServiceResponse_deleteProgramInvocation,
            ConfirmedServiceResponse_start,
            ConfirmedServiceResponse_stop,
            ConfirmedServiceResponse_resume,
            ConfirmedServiceResponse_reset,
            ConfirmedServiceResponse_kill,
            ConfirmedServiceResponse_getProgramInvocationAttributes,
            ConfirmedServiceResponse_obtainFile,
            ConfirmedServiceResponse_defineEventCondition,
            ConfirmedServiceResponse_deleteEventCondition,
            ConfirmedServiceResponse_getEventConditionAttributes,
            ConfirmedServiceResponse_reportEventConditionStatus,
            ConfirmedServiceResponse_alterEventConditionMonitoring,
            ConfirmedServiceResponse_triggerEvent,
            ConfirmedServiceResponse_defineEventAction,
            ConfirmedServiceResponse_deleteEventAction,
            ConfirmedServiceResponse_getEventActionAttributes,
            ConfirmedServiceResponse_reportEventActionStatus,
            ConfirmedServiceResponse_defineEventEnrollment,
            ConfirmedServiceResponse_deleteEventEnrollment,
            ConfirmedServiceResponse_alterEventEnrollment,
            ConfirmedServiceResponse_reportEventEnrollmentStatus,
            ConfirmedServiceResponse_getEventEnrollmentAttributes,
            ConfirmedServiceResponse_acknowledgeEventNotification,
            ConfirmedServiceResponse_getAlarmSummary,
            ConfirmedServiceResponse_getAlarmEnrollmentSummary,
            ConfirmedServiceResponse_readJournal,
            ConfirmedServiceResponse_writeJournal,
            ConfirmedServiceResponse_initializeJournal,
            ConfirmedServiceResponse_reportJournalStatus,
            ConfirmedServiceResponse_createJournal,
            ConfirmedServiceResponse_deleteJournal,
            ConfirmedServiceResponse_getCapabilityList,
            ConfirmedServiceResponse_fileOpen,
            ConfirmedServiceResponse_fileRead,
            ConfirmedServiceResponse_fileClose,
            ConfirmedServiceResponse_fileRename,
            ConfirmedServiceResponse_fileDelete,
            ConfirmedServiceResponse_fileDirectory,
            ConfirmedServiceResponse_additionalService,
            ConfirmedServiceResponse_getDataExchangeAttributes,
            ConfirmedServiceResponse_exchangeData,
            ConfirmedServiceResponse_defineAccessControlList,
            ConfirmedServiceResponse_getAccessControlListAttributes,
            ConfirmedServiceResponse_reportAccessControlledObjects,
            ConfirmedServiceResponse_deleteAccessControlList,
            ConfirmedServiceResponse_changeAccessControl,}; 
 
        struct ConfirmedServiceResponse : public BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceResponse_enum) {



            ConfirmedServiceResponse() :  BOOST_ASN_CHOICE_STRUCT(ConfirmedServiceResponse_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(status, Status_Response, ConfirmedServiceResponse_status);
            BOOST_ASN_VALUE_CHOICE(getNameList, GetNameList_Response, ConfirmedServiceResponse_getNameList);
            BOOST_ASN_VALUE_CHOICE(identify, Identify_Response, ConfirmedServiceResponse_identify);
            BOOST_ASN_VALUE_CHOICE(rename, Rename_Response, ConfirmedServiceResponse_rename);
            BOOST_ASN_VALUE_CHOICE(read, Read_Response, ConfirmedServiceResponse_read);
            BOOST_ASN_VALUE_CHOICE(getVariableAccessAttributes, GetVariableAccessAttributes_Response, ConfirmedServiceResponse_getVariableAccessAttributes);
            BOOST_ASN_VALUE_CHOICE(defineNamedVariable, DefineNamedVariable_Response, ConfirmedServiceResponse_defineNamedVariable);
            BOOST_ASN_VALUE_CHOICE(defineScatteredAccess, ISO_9506_MMS_1A::DefineScatteredAccess_Response, ConfirmedServiceResponse_defineScatteredAccess);
            BOOST_ASN_VALUE_CHOICE(getScatteredAccessAttributes, ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response, ConfirmedServiceResponse_getScatteredAccessAttributes);
            BOOST_ASN_VALUE_CHOICE(deleteVariableAccess, DeleteVariableAccess_Response, ConfirmedServiceResponse_deleteVariableAccess);
            BOOST_ASN_VALUE_CHOICE(defineNamedVariableList, DefineNamedVariableList_Response, ConfirmedServiceResponse_defineNamedVariableList);
            BOOST_ASN_VALUE_CHOICE(getNamedVariableListAttributes, GetNamedVariableListAttributes_Response, ConfirmedServiceResponse_getNamedVariableListAttributes);
            BOOST_ASN_VALUE_CHOICE(deleteNamedVariableList, DeleteNamedVariableList_Response, ConfirmedServiceResponse_deleteNamedVariableList);
            BOOST_ASN_VALUE_CHOICE(defineNamedType, DefineNamedType_Response, ConfirmedServiceResponse_defineNamedType);
            BOOST_ASN_VALUE_CHOICE(getNamedTypeAttributes, GetNamedTypeAttributes_Response, ConfirmedServiceResponse_getNamedTypeAttributes);
            BOOST_ASN_VALUE_CHOICE(deleteNamedType, DeleteNamedType_Response, ConfirmedServiceResponse_deleteNamedType);
            BOOST_ASN_VALUE_CHOICE(input, Input_Response, ConfirmedServiceResponse_input);
            BOOST_ASN_VALUE_CHOICE(output, Output_Response, ConfirmedServiceResponse_output);
            BOOST_ASN_VALUE_CHOICE(takeControl, TakeControl_Response, ConfirmedServiceResponse_takeControl);
            BOOST_ASN_VALUE_CHOICE(relinquishControl, RelinquishControl_Response, ConfirmedServiceResponse_relinquishControl);
            BOOST_ASN_VALUE_CHOICE(defineSemaphore, DefineSemaphore_Response, ConfirmedServiceResponse_defineSemaphore);
            BOOST_ASN_VALUE_CHOICE(deleteSemaphore, DeleteSemaphore_Response, ConfirmedServiceResponse_deleteSemaphore);
            BOOST_ASN_VALUE_CHOICE(reportSemaphoreStatus, ReportSemaphoreStatus_Response, ConfirmedServiceResponse_reportSemaphoreStatus);
            BOOST_ASN_VALUE_CHOICE(reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Response, ConfirmedServiceResponse_reportPoolSemaphoreStatus);
            BOOST_ASN_VALUE_CHOICE(reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Response, ConfirmedServiceResponse_reportSemaphoreEntryStatus);
            BOOST_ASN_VALUE_CHOICE(initiateDownloadSequence, InitiateDownloadSequence_Response, ConfirmedServiceResponse_initiateDownloadSequence);
            BOOST_ASN_VALUE_CHOICE(downloadSegment, DownloadSegment_Response, ConfirmedServiceResponse_downloadSegment);
            BOOST_ASN_VALUE_CHOICE(terminateDownloadSequence, TerminateDownloadSequence_Response, ConfirmedServiceResponse_terminateDownloadSequence);
            BOOST_ASN_VALUE_CHOICE(initiateUploadSequence, InitiateUploadSequence_Response, ConfirmedServiceResponse_initiateUploadSequence);
            BOOST_ASN_VALUE_CHOICE(uploadSegment, UploadSegment_Response, ConfirmedServiceResponse_uploadSegment);
            BOOST_ASN_VALUE_CHOICE(terminateUploadSequence, TerminateUploadSequence_Response, ConfirmedServiceResponse_terminateUploadSequence);
            BOOST_ASN_VALUE_CHOICE(requestDomainDownload, RequestDomainDownload_Response, ConfirmedServiceResponse_requestDomainDownload);
            BOOST_ASN_VALUE_CHOICE(requestDomainUpload, RequestDomainUpload_Response, ConfirmedServiceResponse_requestDomainUpload);
            BOOST_ASN_VALUE_CHOICE(loadDomainContent, LoadDomainContent_Response, ConfirmedServiceResponse_loadDomainContent);
            BOOST_ASN_VALUE_CHOICE(storeDomainContent, StoreDomainContent_Response, ConfirmedServiceResponse_storeDomainContent);
            BOOST_ASN_VALUE_CHOICE(deleteDomain, DeleteDomain_Response, ConfirmedServiceResponse_deleteDomain);
            BOOST_ASN_VALUE_CHOICE(getDomainAttributes, GetDomainAttributes_Response, ConfirmedServiceResponse_getDomainAttributes);
            BOOST_ASN_VALUE_CHOICE(createProgramInvocation, CreateProgramInvocation_Response, ConfirmedServiceResponse_createProgramInvocation);
            BOOST_ASN_VALUE_CHOICE(deleteProgramInvocation, DeleteProgramInvocation_Response, ConfirmedServiceResponse_deleteProgramInvocation);
            BOOST_ASN_VALUE_CHOICE(start, Start_Response, ConfirmedServiceResponse_start);
            BOOST_ASN_VALUE_CHOICE(stop, Stop_Response, ConfirmedServiceResponse_stop);
            BOOST_ASN_VALUE_CHOICE(resume, Resume_Response, ConfirmedServiceResponse_resume);
            BOOST_ASN_VALUE_CHOICE(reset, Reset_Response, ConfirmedServiceResponse_reset);
            BOOST_ASN_VALUE_CHOICE(kill, Kill_Response, ConfirmedServiceResponse_kill);
            BOOST_ASN_VALUE_CHOICE(getProgramInvocationAttributes, GetProgramInvocationAttributes_Response, ConfirmedServiceResponse_getProgramInvocationAttributes);
            BOOST_ASN_VALUE_CHOICE(obtainFile, ISO_9506_MMS_1A::ObtainFile_Response, ConfirmedServiceResponse_obtainFile);
            BOOST_ASN_VALUE_CHOICE(defineEventCondition, DefineEventCondition_Response, ConfirmedServiceResponse_defineEventCondition);
            BOOST_ASN_VALUE_CHOICE(deleteEventCondition, DeleteEventCondition_Response, ConfirmedServiceResponse_deleteEventCondition);
            BOOST_ASN_VALUE_CHOICE(getEventConditionAttributes, GetEventConditionAttributes_Response, ConfirmedServiceResponse_getEventConditionAttributes);
            BOOST_ASN_VALUE_CHOICE(reportEventConditionStatus, ReportEventConditionStatus_Response, ConfirmedServiceResponse_reportEventConditionStatus);
            BOOST_ASN_VALUE_CHOICE(alterEventConditionMonitoring, AlterEventConditionMonitoring_Response, ConfirmedServiceResponse_alterEventConditionMonitoring);
            BOOST_ASN_VALUE_CHOICE(triggerEvent, TriggerEvent_Response, ConfirmedServiceResponse_triggerEvent);
            BOOST_ASN_VALUE_CHOICE(defineEventAction, DefineEventAction_Response, ConfirmedServiceResponse_defineEventAction);
            BOOST_ASN_VALUE_CHOICE(deleteEventAction, DeleteEventAction_Response, ConfirmedServiceResponse_deleteEventAction);
            BOOST_ASN_VALUE_CHOICE(getEventActionAttributes, GetEventActionAttributes_Response, ConfirmedServiceResponse_getEventActionAttributes);
            BOOST_ASN_VALUE_CHOICE(reportEventActionStatus, ReportEventActionStatus_Response, ConfirmedServiceResponse_reportEventActionStatus);
            BOOST_ASN_VALUE_CHOICE(defineEventEnrollment, DefineEventEnrollment_Response, ConfirmedServiceResponse_defineEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(deleteEventEnrollment, DeleteEventEnrollment_Response, ConfirmedServiceResponse_deleteEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(alterEventEnrollment, AlterEventEnrollment_Response, ConfirmedServiceResponse_alterEventEnrollment);
            BOOST_ASN_VALUE_CHOICE(reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Response, ConfirmedServiceResponse_reportEventEnrollmentStatus);
            BOOST_ASN_VALUE_CHOICE(getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Response, ConfirmedServiceResponse_getEventEnrollmentAttributes);
            BOOST_ASN_VALUE_CHOICE(acknowledgeEventNotification, AcknowledgeEventNotification_Response, ConfirmedServiceResponse_acknowledgeEventNotification);
            BOOST_ASN_VALUE_CHOICE(getAlarmSummary, GetAlarmSummary_Response, ConfirmedServiceResponse_getAlarmSummary);
            BOOST_ASN_VALUE_CHOICE(getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Response, ConfirmedServiceResponse_getAlarmEnrollmentSummary);
            BOOST_ASN_VALUE_CHOICE(readJournal, ReadJournal_Response, ConfirmedServiceResponse_readJournal);
            BOOST_ASN_VALUE_CHOICE(writeJournal, WriteJournal_Response, ConfirmedServiceResponse_writeJournal);
            BOOST_ASN_VALUE_CHOICE(initializeJournal, InitializeJournal_Response, ConfirmedServiceResponse_initializeJournal);
            BOOST_ASN_VALUE_CHOICE(reportJournalStatus, ReportJournalStatus_Response, ConfirmedServiceResponse_reportJournalStatus);
            BOOST_ASN_VALUE_CHOICE(createJournal, CreateJournal_Response, ConfirmedServiceResponse_createJournal);
            BOOST_ASN_VALUE_CHOICE(deleteJournal, DeleteJournal_Response, ConfirmedServiceResponse_deleteJournal);
            BOOST_ASN_VALUE_CHOICE(getCapabilityList, GetCapabilityList_Response, ConfirmedServiceResponse_getCapabilityList);
            BOOST_ASN_VALUE_CHOICE(fileOpen, ISO_9506_MMS_1A::FileOpen_Response, ConfirmedServiceResponse_fileOpen);
            BOOST_ASN_VALUE_CHOICE(fileRead, ISO_9506_MMS_1A::FileRead_Response, ConfirmedServiceResponse_fileRead);
            BOOST_ASN_VALUE_CHOICE(fileClose, ISO_9506_MMS_1A::FileClose_Response, ConfirmedServiceResponse_fileClose);
            BOOST_ASN_VALUE_CHOICE(fileRename, ISO_9506_MMS_1A::FileRename_Response, ConfirmedServiceResponse_fileRename);
            BOOST_ASN_VALUE_CHOICE(fileDelete, ISO_9506_MMS_1A::FileDelete_Response, ConfirmedServiceResponse_fileDelete);
            BOOST_ASN_VALUE_CHOICE(fileDirectory, ISO_9506_MMS_1A::FileDirectory_Response, ConfirmedServiceResponse_fileDirectory);
            BOOST_ASN_VALUE_CHOICE(additionalService, AdditionalService_Response, ConfirmedServiceResponse_additionalService);
            BOOST_ASN_VALUE_CHOICE(getDataExchangeAttributes, GetDataExchangeAttributes_Response, ConfirmedServiceResponse_getDataExchangeAttributes);
            BOOST_ASN_VALUE_CHOICE(exchangeData, ExchangeData_Response, ConfirmedServiceResponse_exchangeData);
            BOOST_ASN_VALUE_CHOICE(defineAccessControlList, DefineAccessControlList_Response, ConfirmedServiceResponse_defineAccessControlList);
            BOOST_ASN_VALUE_CHOICE(getAccessControlListAttributes, GetAccessControlListAttributes_Response, ConfirmedServiceResponse_getAccessControlListAttributes);
            BOOST_ASN_VALUE_CHOICE(reportAccessControlledObjects, ReportAccessControlledObjects_Response, ConfirmedServiceResponse_reportAccessControlledObjects);
            BOOST_ASN_VALUE_CHOICE(deleteAccessControlList, DeleteAccessControlList_Response, ConfirmedServiceResponse_deleteAccessControlList);
            BOOST_ASN_VALUE_CHOICE(changeAccessControl, ChangeAccessControl_Response, ConfirmedServiceResponse_changeAccessControl);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice AdditionalService-Response
        enum AdditionalService_Response_enum {
            AdditionalService_Response_null = 0, 
            AdditionalService_Response_vMDStop,
            AdditionalService_Response_vMDReset,
            AdditionalService_Response_select,
            AdditionalService_Response_alterPI,
            AdditionalService_Response_initiateUCLoad,
            AdditionalService_Response_uCLoad,
            AdditionalService_Response_uCUpload,
            AdditionalService_Response_startUC,
            AdditionalService_Response_stopUC,
            AdditionalService_Response_createUC,
            AdditionalService_Response_addToUC,
            AdditionalService_Response_removeFromUC,
            AdditionalService_Response_getUCAttributes,
            AdditionalService_Response_loadUCFromFile,
            AdditionalService_Response_storeUCToFile,
            AdditionalService_Response_deleteUC,
            AdditionalService_Response_defineECL,
            AdditionalService_Response_deleteECL,
            AdditionalService_Response_addECLReference,
            AdditionalService_Response_removeECLReference,
            AdditionalService_Response_getECLAttributes,
            AdditionalService_Response_reportECLStatus,
            AdditionalService_Response_alterECLMonitoring,}; 
 
        struct AdditionalService_Response : public BOOST_ASN_CHOICE_STRUCT(AdditionalService_Response_enum) {



            AdditionalService_Response() :  BOOST_ASN_CHOICE_STRUCT(AdditionalService_Response_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(vMDStop, VMDStop_Response, AdditionalService_Response_vMDStop);
            BOOST_ASN_VALUE_CHOICE(vMDReset, VMDReset_Response, AdditionalService_Response_vMDReset);
            BOOST_ASN_VALUE_CHOICE(select, Select_Response, AdditionalService_Response_select);
            BOOST_ASN_VALUE_CHOICE(alterPI, AlterProgramInvocationAttributes_Response, AdditionalService_Response_alterPI);
            BOOST_ASN_VALUE_CHOICE(initiateUCLoad, InitiateUnitControlLoad_Response, AdditionalService_Response_initiateUCLoad);
            BOOST_ASN_VALUE_CHOICE(uCLoad, UnitControlLoadSegment_Response, AdditionalService_Response_uCLoad);
            BOOST_ASN_VALUE_CHOICE(uCUpload, UnitControlUpload_Response, AdditionalService_Response_uCUpload);
            BOOST_ASN_VALUE_CHOICE(startUC, StartUnitControl_Response, AdditionalService_Response_startUC);
            BOOST_ASN_VALUE_CHOICE(stopUC, StopUnitControl_Response, AdditionalService_Response_stopUC);
            BOOST_ASN_VALUE_CHOICE(createUC, CreateUnitControl_Response, AdditionalService_Response_createUC);
            BOOST_ASN_VALUE_CHOICE(addToUC, AddToUnitControl_Response, AdditionalService_Response_addToUC);
            BOOST_ASN_VALUE_CHOICE(removeFromUC, RemoveFromUnitControl_Response, AdditionalService_Response_removeFromUC);
            BOOST_ASN_VALUE_CHOICE(getUCAttributes, GetUnitControlAttributes_Response, AdditionalService_Response_getUCAttributes);
            BOOST_ASN_VALUE_CHOICE(loadUCFromFile, LoadUnitControlFromFile_Response, AdditionalService_Response_loadUCFromFile);
            BOOST_ASN_VALUE_CHOICE(storeUCToFile, StoreUnitControlToFile_Response, AdditionalService_Response_storeUCToFile);
            BOOST_ASN_VALUE_CHOICE(deleteUC, DeleteUnitControl_Response, AdditionalService_Response_deleteUC);
            BOOST_ASN_VALUE_CHOICE(defineECL, DefineEventConditionList_Response, AdditionalService_Response_defineECL);
            BOOST_ASN_VALUE_CHOICE(deleteECL, DeleteEventConditionList_Response, AdditionalService_Response_deleteECL);
            BOOST_ASN_VALUE_CHOICE(addECLReference, AddEventConditionListReference_Response, AdditionalService_Response_addECLReference);
            BOOST_ASN_VALUE_CHOICE(removeECLReference, RemoveEventConditionListReference_Response, AdditionalService_Response_removeECLReference);
            BOOST_ASN_VALUE_CHOICE(getECLAttributes, GetEventConditionListAttributes_Response, AdditionalService_Response_getECLAttributes);
            BOOST_ASN_VALUE_CHOICE(reportECLStatus, ReportEventConditionListStatus_Response, AdditionalService_Response_reportECLStatus);
            BOOST_ASN_VALUE_CHOICE(alterECLMonitoring, AlterEventConditionListMonitoring_Response, AdditionalService_Response_alterECLMonitoring);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice Response-Detail
        enum Response_Detail_enum {
            Response_Detail_null = 0, 
            Response_Detail_otherRequests,
            Response_Detail_status,
            Response_Detail_getProgramInvocationAttributes,
            Response_Detail_getEventConditionAttributes,}; 
 
        struct Response_Detail : public BOOST_ASN_CHOICE_STRUCT(Response_Detail_enum) {



            Response_Detail() :  BOOST_ASN_CHOICE_STRUCT(Response_Detail_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(otherRequests, null_type, Response_Detail_otherRequests);
            BOOST_ASN_VALUE_CHOICE(status, CS_Status_Response, Response_Detail_status);
            BOOST_ASN_VALUE_CHOICE(getProgramInvocationAttributes, CS_GetProgramInvocationAttributes_Response, Response_Detail_getProgramInvocationAttributes);
            BOOST_ASN_VALUE_CHOICE(getEventConditionAttributes, CS_GetEventConditionAttributes_Response, Response_Detail_getEventConditionAttributes);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Confirmed-ErrorPDU
        struct Confirmed_ErrorPDU{



            Confirmed_ErrorPDU() : invokeID(), serviceError() {} 
 
            boost::asn1::value_holder<Unsigned32> invokeID;
            boost::shared_ptr<Unsigned32> modifierPosition;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, modifierPosition)

            boost::asn1::value_holder<ServiceError> serviceError;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ServiceError
        struct ServiceError{


            enum errorClass_type_enum {
                errorClass_type_null = 0, 
                errorClass_type_vmd_state,
                errorClass_type_application_reference,
                errorClass_type_definition,
                errorClass_type_resource,
                errorClass_type_service,
                errorClass_type_service_preempt,
                errorClass_type_time_resolution,
                errorClass_type_access,
                errorClass_type_initiate,
                errorClass_type_conclude,
                errorClass_type_cancel,
                errorClass_type_file,
                errorClass_type_others,}; 
 
            struct errorClass_type : public BOOST_ASN_CHOICE_STRUCT(errorClass_type_enum) {


                static const int vmd_state_other;
                static const int vmd_state_vmd_state_conflict;
                static const int vmd_state_vmd_operational_problem;
                static const int vmd_state_domain_transfer_problem;
                static const int vmd_state_state_machine_id_invalid;

                static const int application_reference_other;
                static const int application_reference_application_unreachable;
                static const int application_reference_connection_lost;
                static const int application_reference_application_reference_invalid;
                static const int application_reference_context_unsupported;

                static const int definition_other;
                static const int definition_object_undefined;
                static const int definition_invalid_address;
                static const int definition_type_unsupported;
                static const int definition_type_inconsistent;
                static const int definition_object_exists;
                static const int definition_object_attribute_inconsistent;

                static const int resource_other;
                static const int resource_memory_unavailable;
                static const int resource_processor_resource_unavailable;
                static const int resource_mass_storage_unavailable;
                static const int resource_capability_unavailable;
                static const int resource_capability_unknown;

                static const int service_other;
                static const int service_primitives_out_of_sequence;
                static const int service_object_state_conflict;
                static const int service_continuation_invalid;
                static const int service_object_constraint_conflict;

                static const int service_preempt_other;
                static const int service_preempt_timeout;
                static const int service_preempt_deadlock;
                static const int service_preempt_cancel;

                static const int time_resolution_other;
                static const int time_resolution_unsupportable_time_resolution;

                static const int access_other;
                static const int access_object_access_unsupported;
                static const int access_object_non_existent;
                static const int access_object_access_denied;
                static const int access_object_invalidated;

                static const int initiate_other;
                static const int initiate_max_services_outstanding_calling_insufficient;
                static const int initiate_max_services_outstanding_called_insufficient;
                static const int initiate_service_CBB_insufficient;
                static const int initiate_parameter_CBB_insufficient;
                static const int initiate_nesting_level_insufficient;

                static const int conclude_other;
                static const int conclude_further_communication_required;

                static const int cancel_other;
                static const int cancel_invoke_id_unknown;
                static const int cancel_cancel_not_possible;

                static const int file_other;
                static const int file_filename_ambiguous;
                static const int file_file_busy;
                static const int file_filename_syntax_error;
                static const int file_content_type_invalid;
                static const int file_position_invalid;
                static const int file_file_access_denied;
                static const int file_file_non_existent;
                static const int file_duplicate_filename;
                static const int file_insufficient_space_in_filestore;


                errorClass_type() :  BOOST_ASN_CHOICE_STRUCT(errorClass_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(vmd_state, int, errorClass_type_vmd_state);
                BOOST_ASN_VALUE_CHOICE(application_reference, int, errorClass_type_application_reference);
                BOOST_ASN_VALUE_CHOICE(definition, int, errorClass_type_definition);
                BOOST_ASN_VALUE_CHOICE(resource, int, errorClass_type_resource);
                BOOST_ASN_VALUE_CHOICE(service, int, errorClass_type_service);
                BOOST_ASN_VALUE_CHOICE(service_preempt, int, errorClass_type_service_preempt);
                BOOST_ASN_VALUE_CHOICE(time_resolution, int, errorClass_type_time_resolution);
                BOOST_ASN_VALUE_CHOICE(access, int, errorClass_type_access);
                BOOST_ASN_VALUE_CHOICE(initiate, int, errorClass_type_initiate);
                BOOST_ASN_VALUE_CHOICE(conclude, int, errorClass_type_conclude);
                BOOST_ASN_VALUE_CHOICE(cancel, int, errorClass_type_cancel);
                BOOST_ASN_VALUE_CHOICE(file, int, errorClass_type_file);
                BOOST_ASN_VALUE_CHOICE(others, int, errorClass_type_others);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 

            enum serviceSpecificInfo_type_enum {
                serviceSpecificInfo_type_null = 0, 
                serviceSpecificInfo_type_obtainFile,
                serviceSpecificInfo_type_start,
                serviceSpecificInfo_type_stop,
                serviceSpecificInfo_type_resume,
                serviceSpecificInfo_type_reset,
                serviceSpecificInfo_type_deleteVariableAccess,
                serviceSpecificInfo_type_deleteNamedVariableList,
                serviceSpecificInfo_type_deleteNamedType,
                serviceSpecificInfo_type_defineEventEnrollment_Error,
                serviceSpecificInfo_type_fileRename,
                serviceSpecificInfo_type_additionalService,
                serviceSpecificInfo_type_changeAccessControl,}; 
 
            struct serviceSpecificInfo_type : public BOOST_ASN_CHOICE_STRUCT(serviceSpecificInfo_type_enum) {



                serviceSpecificInfo_type() :  BOOST_ASN_CHOICE_STRUCT(serviceSpecificInfo_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(obtainFile, ISO_9506_MMS_1A::ObtainFile_Error, serviceSpecificInfo_type_obtainFile);
                BOOST_ASN_VALUE_CHOICE(start, Start_Error, serviceSpecificInfo_type_start);
                BOOST_ASN_VALUE_CHOICE(stop, Stop_Error, serviceSpecificInfo_type_stop);
                BOOST_ASN_VALUE_CHOICE(resume, Resume_Error, serviceSpecificInfo_type_resume);
                BOOST_ASN_VALUE_CHOICE(reset, Reset_Error, serviceSpecificInfo_type_reset);
                BOOST_ASN_VALUE_CHOICE(deleteVariableAccess, DeleteVariableAccess_Error, serviceSpecificInfo_type_deleteVariableAccess);
                BOOST_ASN_VALUE_CHOICE(deleteNamedVariableList, DeleteNamedVariableList_Error, serviceSpecificInfo_type_deleteNamedVariableList);
                BOOST_ASN_VALUE_CHOICE(deleteNamedType, DeleteNamedType_Error, serviceSpecificInfo_type_deleteNamedType);
                BOOST_ASN_VALUE_CHOICE(defineEventEnrollment_Error, DefineEventEnrollment_Error, serviceSpecificInfo_type_defineEventEnrollment_Error);
                BOOST_ASN_VALUE_CHOICE(fileRename, ISO_9506_MMS_1A::FileRename_Error, serviceSpecificInfo_type_fileRename);
                BOOST_ASN_VALUE_CHOICE(additionalService, AdditionalService_Error, serviceSpecificInfo_type_additionalService);
                BOOST_ASN_VALUE_CHOICE(changeAccessControl, ChangeAccessControl_Error, serviceSpecificInfo_type_changeAccessControl);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            ServiceError() : errorClass() {} 
 
            boost::asn1::value_holder<errorClass_type> errorClass;
            boost::shared_ptr<int> additionalCode;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, additionalCode)

            boost::shared_ptr<visiblestring_type> additionalDescription;
            BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, additionalDescription)

            boost::shared_ptr<serviceSpecificInfo_type> serviceSpecificInfo;
            BOOST_ASN_VALUE_FUNC_DECLARATE(serviceSpecificInfo_type, serviceSpecificInfo)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice AdditionalService-Error
        enum AdditionalService_Error_enum {
            AdditionalService_Error_null = 0, 
            AdditionalService_Error_defineEcl,
            AdditionalService_Error_addECLReference,
            AdditionalService_Error_removeECLReference,
            AdditionalService_Error_initiateUC,
            AdditionalService_Error_startUC,
            AdditionalService_Error_stopUC,
            AdditionalService_Error_deleteUC,
            AdditionalService_Error_loadUCFromFile,}; 
 
        struct AdditionalService_Error : public BOOST_ASN_CHOICE_STRUCT(AdditionalService_Error_enum) {



            AdditionalService_Error() :  BOOST_ASN_CHOICE_STRUCT(AdditionalService_Error_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(defineEcl, DefineEventConditionList_Error, AdditionalService_Error_defineEcl);
            BOOST_ASN_VALUE_CHOICE(addECLReference, AddEventConditionListReference_Error, AdditionalService_Error_addECLReference);
            BOOST_ASN_VALUE_CHOICE(removeECLReference, RemoveEventConditionListReference_Error, AdditionalService_Error_removeECLReference);
            BOOST_ASN_VALUE_CHOICE(initiateUC, InitiateUnitControl_Error, AdditionalService_Error_initiateUC);
            BOOST_ASN_VALUE_CHOICE(startUC, StartUnitControl_Error, AdditionalService_Error_startUC);
            BOOST_ASN_VALUE_CHOICE(stopUC, StopUnitControl_Error, AdditionalService_Error_stopUC);
            BOOST_ASN_VALUE_CHOICE(deleteUC, DeleteUnitControl_Error, AdditionalService_Error_deleteUC);
            BOOST_ASN_VALUE_CHOICE(loadUCFromFile, LoadUnitControlFromFile_Error, AdditionalService_Error_loadUCFromFile);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice ObjectName
        enum ObjectName_enum {
            ObjectName_null = 0, 
            ObjectName_vmd_specific,
            ObjectName_domain_specific,
            ObjectName_aa_specific,}; 
 
        struct ObjectName : public BOOST_ASN_CHOICE_STRUCT(ObjectName_enum) {


            struct domain_specific_type{



                domain_specific_type() : domainID(), itemID() {} 
 
                boost::asn1::value_holder<Identifier> domainID;
                boost::asn1::value_holder<Identifier> itemID;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            ObjectName() :  BOOST_ASN_CHOICE_STRUCT(ObjectName_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(vmd_specific, Identifier, ObjectName_vmd_specific);
            BOOST_ASN_VALUE_CHOICE(domain_specific, domain_specific_type, ObjectName_domain_specific);
            BOOST_ASN_VALUE_CHOICE(aa_specific, Identifier, ObjectName_aa_specific);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice ObjectClass
        enum ObjectClass_enum {
            ObjectClass_null = 0, 
            ObjectClass_basicObjectClass,
            ObjectClass_csObjectClass,}; 
 
        struct ObjectClass : public BOOST_ASN_CHOICE_STRUCT(ObjectClass_enum) {


            static const int basicObjectClass_namedVariable;
            static const int basicObjectClass_scatteredAccess;
            static const int basicObjectClass_namedVariableList;
            static const int basicObjectClass_namedType;
            static const int basicObjectClass_semaphore;
            static const int basicObjectClass_eventCondition;
            static const int basicObjectClass_eventAction;
            static const int basicObjectClass_eventEnrollment;
            static const int basicObjectClass_journal;
            static const int basicObjectClass_domain;
            static const int basicObjectClass_programInvocation;
            static const int basicObjectClass_operatorStation;
            static const int basicObjectClass_dataExchange;
            static const int basicObjectClass_accessControlList;

            static const int csObjectClass_eventConditionList;
            static const int csObjectClass_unitControl;


            ObjectClass() :  BOOST_ASN_CHOICE_STRUCT(ObjectClass_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(basicObjectClass, int, ObjectClass_basicObjectClass);
            BOOST_ASN_VALUE_CHOICE(csObjectClass, int, ObjectClass_csObjectClass);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Initiate-RequestPDU
        struct Initiate_RequestPDU{


            struct initRequestDetail_type{



                initRequestDetail_type() : proposedVersionNumber(), proposedParameterCBB(), servicesSupportedCalling(), additionalSupportedCalling(), additionalCbbSupportedCalling(), privilegeClassIdentityCalling() {} 
 
                boost::asn1::value_holder<Integer16> proposedVersionNumber;
                boost::asn1::value_holder<MMS_Object_Module_1::ParameterSupportOptions> proposedParameterCBB;
                boost::asn1::value_holder<MMS_Object_Module_1::ServiceSupportOptions> servicesSupportedCalling;
                boost::asn1::value_holder<MMS_Object_Module_1::AdditionalSupportOptions> additionalSupportedCalling;
                boost::asn1::value_holder<MMS_Object_Module_1::AdditionalCBBOptions> additionalCbbSupportedCalling;
                boost::asn1::value_holder<visiblestring_type> privilegeClassIdentityCalling;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            Initiate_RequestPDU() : proposedMaxServOutstandingCalling(), proposedMaxServOutstandingCalled(), initRequestDetail() {} 
 
            boost::shared_ptr<Integer32> localDetailCalling;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Integer32, localDetailCalling)

            boost::asn1::value_holder<Integer16> proposedMaxServOutstandingCalling;
            boost::asn1::value_holder<Integer16> proposedMaxServOutstandingCalled;
            boost::shared_ptr<Integer8> proposedDataStructureNestingLevel;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Integer8, proposedDataStructureNestingLevel)

            boost::asn1::value_holder<initRequestDetail_type> initRequestDetail;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Initiate-ResponsePDU
        struct Initiate_ResponsePDU{


            struct initResponseDetail_type{



                initResponseDetail_type() : negotiatedVersionNumber(), negotiatedParameterCBB(), servicesSupportedCalled(), additionalSupportedCalled(), additionalCbbSupportedCalled(), privilegeClassIdentityCalled() {} 
 
                boost::asn1::value_holder<Integer16> negotiatedVersionNumber;
                boost::asn1::value_holder<MMS_Object_Module_1::ParameterSupportOptions> negotiatedParameterCBB;
                boost::asn1::value_holder<MMS_Object_Module_1::ServiceSupportOptions> servicesSupportedCalled;
                boost::asn1::value_holder<MMS_Object_Module_1::AdditionalSupportOptions> additionalSupportedCalled;
                boost::asn1::value_holder<MMS_Object_Module_1::AdditionalCBBOptions> additionalCbbSupportedCalled;
                boost::asn1::value_holder<visiblestring_type> privilegeClassIdentityCalled;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            Initiate_ResponsePDU() : negotiatedMaxServOutstandingCalling(), negotiatedMaxServOutstandingCalled(), initResponseDetail() {} 
 
            boost::shared_ptr<Integer32> localDetailCalled;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Integer32, localDetailCalled)

            boost::asn1::value_holder<Integer16> negotiatedMaxServOutstandingCalling;
            boost::asn1::value_holder<Integer16> negotiatedMaxServOutstandingCalled;
            boost::shared_ptr<Integer8> negotiatedDataStructureNestingLevel;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Integer8, negotiatedDataStructureNestingLevel)

            boost::asn1::value_holder<initResponseDetail_type> initResponseDetail;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Cancel-ErrorPDU
        struct Cancel_ErrorPDU{



            Cancel_ErrorPDU() : originalInvokeID(), serviceError() {} 
 
            boost::asn1::value_holder<Unsigned32> originalInvokeID;
            boost::asn1::value_holder<ServiceError> serviceError;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RejectPDU
        struct RejectPDU{


            enum rejectReason_type_enum {
                rejectReason_type_null = 0, 
                rejectReason_type_confirmed_requestPDU,
                rejectReason_type_confirmed_responsePDU,
                rejectReason_type_confirmed_errorPDU,
                rejectReason_type_unconfirmedPDU,
                rejectReason_type_pdu_error,
                rejectReason_type_cancel_requestPDU,
                rejectReason_type_cancel_responsePDU,
                rejectReason_type_cancel_errorPDU,
                rejectReason_type_conclude_requestPDU,
                rejectReason_type_conclude_responsePDU,
                rejectReason_type_conclude_errorPDU,}; 
 
            struct rejectReason_type : public BOOST_ASN_CHOICE_STRUCT(rejectReason_type_enum) {


                static const int confirmed_requestPDU_other;
                static const int confirmed_requestPDU_unrecognized_service;
                static const int confirmed_requestPDU_unrecognized_modifier;
                static const int confirmed_requestPDU_invalid_invokeID;
                static const int confirmed_requestPDU_invalid_argument;
                static const int confirmed_requestPDU_invalid_modifier;
                static const int confirmed_requestPDU_max_serv_outstanding_exceeded;
                static const int confirmed_requestPDU_max_recursion_exceeded;
                static const int confirmed_requestPDU_value_out_of_range;

                static const int confirmed_responsePDU_other;
                static const int confirmed_responsePDU_unrecognized_service;
                static const int confirmed_responsePDU_invalid_invokeID;
                static const int confirmed_responsePDU_invalid_result;
                static const int confirmed_responsePDU_max_recursion_exceeded;
                static const int confirmed_responsePDU_value_out_of_range;

                static const int confirmed_errorPDU_other;
                static const int confirmed_errorPDU_unrecognized_service;
                static const int confirmed_errorPDU_invalid_invokeID;
                static const int confirmed_errorPDU_invalid_serviceError;
                static const int confirmed_errorPDU_value_out_of_range;

                static const int unconfirmedPDU_other;
                static const int unconfirmedPDU_unrecognized_service;
                static const int unconfirmedPDU_invalid_argument;
                static const int unconfirmedPDU_max_recursion_exceeded;
                static const int unconfirmedPDU_value_out_of_range;

                static const int pdu_error_unknown_pdu_type;
                static const int pdu_error_invalid_pdu;
                static const int pdu_error_illegal_acse_mapping;

                static const int cancel_requestPDU_other;
                static const int cancel_requestPDU_invalid_invokeID;

                static const int cancel_responsePDU_other;
                static const int cancel_responsePDU_invalid_invokeID;

                static const int cancel_errorPDU_other;
                static const int cancel_errorPDU_invalid_invokeID;
                static const int cancel_errorPDU_invalid_serviceError;
                static const int cancel_errorPDU_value_out_of_range;

                static const int conclude_requestPDU_other;
                static const int conclude_requestPDU_invalid_argument;

                static const int conclude_responsePDU_other;
                static const int conclude_responsePDU_invalid_result;

                static const int conclude_errorPDU_other;
                static const int conclude_errorPDU_invalid_serviceError;
                static const int conclude_errorPDU_value_out_of_range;


                rejectReason_type() :  BOOST_ASN_CHOICE_STRUCT(rejectReason_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(confirmed_requestPDU, int, rejectReason_type_confirmed_requestPDU);
                BOOST_ASN_VALUE_CHOICE(confirmed_responsePDU, int, rejectReason_type_confirmed_responsePDU);
                BOOST_ASN_VALUE_CHOICE(confirmed_errorPDU, int, rejectReason_type_confirmed_errorPDU);
                BOOST_ASN_VALUE_CHOICE(unconfirmedPDU, int, rejectReason_type_unconfirmedPDU);
                BOOST_ASN_VALUE_CHOICE(pdu_error, int, rejectReason_type_pdu_error);
                BOOST_ASN_VALUE_CHOICE(cancel_requestPDU, int, rejectReason_type_cancel_requestPDU);
                BOOST_ASN_VALUE_CHOICE(cancel_responsePDU, int, rejectReason_type_cancel_responsePDU);
                BOOST_ASN_VALUE_CHOICE(cancel_errorPDU, int, rejectReason_type_cancel_errorPDU);
                BOOST_ASN_VALUE_CHOICE(conclude_requestPDU, int, rejectReason_type_conclude_requestPDU);
                BOOST_ASN_VALUE_CHOICE(conclude_responsePDU, int, rejectReason_type_conclude_responsePDU);
                BOOST_ASN_VALUE_CHOICE(conclude_errorPDU, int, rejectReason_type_conclude_errorPDU);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            RejectPDU() : rejectReason() {} 
 
            boost::shared_ptr<Unsigned32> originalInvokeID;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, originalInvokeID)

            boost::asn1::value_holder<rejectReason_type> rejectReason;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineAccessControlList-Request
        struct DefineAccessControlList_Request{


            struct accessControlListElements_type{



                accessControlListElements_type() {} 
 
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> readAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, readAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> storeAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, storeAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> writeAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, writeAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> loadAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, loadAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> executeAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, executeAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> deleteAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, deleteAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> editAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, editAccessCondition)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            DefineAccessControlList_Request() : accessControlListName(), accessControlListElements() {} 
 
            boost::asn1::value_holder<Identifier> accessControlListName;
            boost::asn1::value_holder<accessControlListElements_type> accessControlListElements;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice GetAccessControlListAttributes-Request
        enum GetAccessControlListAttributes_Request_enum {
            GetAccessControlListAttributes_Request_null = 0, 
            GetAccessControlListAttributes_Request_accessControlListName,
            GetAccessControlListAttributes_Request_vMD,
            GetAccessControlListAttributes_Request_namedObject,}; 
 
        struct GetAccessControlListAttributes_Request : public BOOST_ASN_CHOICE_STRUCT(GetAccessControlListAttributes_Request_enum) {


            struct namedObject_type{



                namedObject_type() : objectClass(), objectName() {} 
 
                boost::asn1::value_holder<ObjectClass> objectClass;
                boost::asn1::value_holder<ObjectName> objectName;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            GetAccessControlListAttributes_Request() :  BOOST_ASN_CHOICE_STRUCT(GetAccessControlListAttributes_Request_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(accessControlListName, Identifier, GetAccessControlListAttributes_Request_accessControlListName);
            BOOST_ASN_VALUE_CHOICE(vMD, null_type, GetAccessControlListAttributes_Request_vMD);
            BOOST_ASN_VALUE_CHOICE(namedObject, namedObject_type, GetAccessControlListAttributes_Request_namedObject);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetAccessControlListAttributes-Response
        struct GetAccessControlListAttributes_Response{
        struct references_type_sequence_of;


            struct accessControlListElements_type{



                accessControlListElements_type() {} 
 
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> readAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, readAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> storeAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, storeAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> writeAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, writeAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> loadAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, loadAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> executeAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, executeAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> deleteAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, deleteAccessCondition)

                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> editAccessCondition;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AccessCondition, editAccessCondition)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 

                struct references_type_sequence_of{



                    references_type_sequence_of() : objectClass(), objectCount() {} 
 
                    boost::asn1::value_holder<ObjectClass> objectClass;
                    boost::asn1::value_holder<int> objectCount;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 
        typedef std::vector< references_type_sequence_of> references_type;


            GetAccessControlListAttributes_Response() : name(), accessControlListElements(), vMDuse(), references() {} 
 
            boost::asn1::value_holder<Identifier> name;
            boost::asn1::value_holder<accessControlListElements_type> accessControlListElements;
            boost::asn1::value_holder<bool> vMDuse;
            boost::asn1::value_holder<references_type> references;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportAccessControlledObjects-Request
        struct ReportAccessControlledObjects_Request{



            ReportAccessControlledObjects_Request() : accessControlList(), objectClass() {} 
 
            boost::asn1::value_holder<Identifier> accessControlList;
            boost::asn1::value_holder<ObjectClass> objectClass;
            boost::shared_ptr<ObjectName> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportAccessControlledObjects-Response
        struct ReportAccessControlledObjects_Response{

        typedef std::vector< ObjectName> listOfNames_type;


            ReportAccessControlledObjects_Response() : listOfNames() {} 
 
            boost::asn1::value_holder<listOfNames_type> listOfNames;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ChangeAccessControl-Request
        struct ChangeAccessControl_Request{


            enum scopeOfChange_type_enum {
                scopeOfChange_type_null = 0, 
                scopeOfChange_type_vMDOnly,
                scopeOfChange_type_listOfObjects,}; 
 
            struct scopeOfChange_type : public BOOST_ASN_CHOICE_STRUCT(scopeOfChange_type_enum) {


                struct listOfObjects_type{


                    enum objectScope_type_enum {
                        objectScope_type_null = 0, 
                        objectScope_type_specific,
                        objectScope_type_aa_specific,
                        objectScope_type_domain,
                        objectScope_type_vmd,}; 
 
                    struct objectScope_type : public BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) {

                    typedef std::vector< ObjectName> specific_type;


                        objectScope_type() :  BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(specific, specific_type, objectScope_type_specific);
                        BOOST_ASN_VALUE_CHOICE(aa_specific, null_type, objectScope_type_aa_specific);
                        BOOST_ASN_VALUE_CHOICE(domain, Identifier, objectScope_type_domain);
                        BOOST_ASN_VALUE_CHOICE(vmd, null_type, objectScope_type_vmd);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 


                    listOfObjects_type() : objectClass(), objectScope() {} 
 
                    boost::asn1::value_holder<ObjectClass> objectClass;
                    boost::asn1::value_holder<objectScope_type> objectScope;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                scopeOfChange_type() :  BOOST_ASN_CHOICE_STRUCT(scopeOfChange_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(vMDOnly, null_type, scopeOfChange_type_vMDOnly);
                BOOST_ASN_VALUE_CHOICE(listOfObjects, listOfObjects_type, scopeOfChange_type_listOfObjects);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            ChangeAccessControl_Request() : scopeOfChange(), accessControlListName() {} 
 
            boost::asn1::value_holder<scopeOfChange_type> scopeOfChange;
            boost::asn1::value_holder<Identifier> accessControlListName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ChangeAccessControl-Response
        struct ChangeAccessControl_Response{



            ChangeAccessControl_Response() : numberMatched(), numberChanged() {} 
 
            boost::asn1::value_holder<Unsigned32> numberMatched;
            boost::asn1::value_holder<Unsigned32> numberChanged;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence StatusResponse
        struct StatusResponse{


            static const int vmdLogicalStatus_state_changes_allowed;
            static const int vmdLogicalStatus_no_state_changes_allowed;
            static const int vmdLogicalStatus_limited_services_permitted;
            static const int vmdLogicalStatus_support_services_allowed;

            static const int vmdPhysicalStatus_operational;
            static const int vmdPhysicalStatus_partially_operational;
            static const int vmdPhysicalStatus_inoperable;
            static const int vmdPhysicalStatus_needs_commissioning;


            StatusResponse() : vmdLogicalStatus(), vmdPhysicalStatus() {} 
 
            boost::asn1::value_holder<int> vmdLogicalStatus;
            boost::asn1::value_holder<int> vmdPhysicalStatus;
            boost::shared_ptr<bitstring_type> localDetail;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type, localDetail)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice CS-Status-Response
        enum CS_Status_Response_enum {
            CS_Status_Response_null = 0, 
            CS_Status_Response_fullResponse,
            CS_Status_Response_noExtraResponse,}; 
 
        struct CS_Status_Response : public BOOST_ASN_CHOICE_STRUCT(CS_Status_Response_enum) {


            struct fullResponse_type{


                enum selectedProgramInvocation_type_enum {
                    selectedProgramInvocation_type_null = 0, 
                    selectedProgramInvocation_type_programInvocation,
                    selectedProgramInvocation_type_noneSelected,}; 
 
                struct selectedProgramInvocation_type : public BOOST_ASN_CHOICE_STRUCT(selectedProgramInvocation_type_enum) {



                    selectedProgramInvocation_type() :  BOOST_ASN_CHOICE_STRUCT(selectedProgramInvocation_type_enum) () {}
 
                    BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier, selectedProgramInvocation_type_programInvocation);
                    BOOST_ASN_VALUE_CHOICE(noneSelected, null_type, selectedProgramInvocation_type_noneSelected);

                    BOOST_ASN_ARCHIVE_FUNC;
                }; 
 


                fullResponse_type() : operationState(), extendedStatus(), selectedProgramInvocation() {} 
 
                boost::asn1::value_holder<OperationState> operationState;
                boost::asn1::value_holder<ExtendedStatus> extendedStatus;
                boost::shared_ptr<ExtendedStatus> extendedStatusMask;
                BOOST_ASN_VALUE_FUNC_DECLARATE(ExtendedStatus, extendedStatusMask)

                boost::asn1::value_holder<selectedProgramInvocation_type> selectedProgramInvocation;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            CS_Status_Response() :  BOOST_ASN_CHOICE_STRUCT(CS_Status_Response_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(fullResponse, fullResponse_type, CS_Status_Response_fullResponse);
            BOOST_ASN_VALUE_CHOICE(noExtraResponse, null_type, CS_Status_Response_noExtraResponse);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const int OperationState_idle;
        extern const int OperationState_loaded;
        extern const int OperationState_ready;
        extern const int OperationState_executing;
        extern const int OperationState_motion_paused;
        extern const int OperationState_manualInterventionRequired;

        extern const bitstring_type ExtendedStatus_safetyInterlocksViolated;
        extern const bitstring_type ExtendedStatus_anyPhysicalResourcePowerOn;
        extern const bitstring_type ExtendedStatus_allPhysicalResourcesCalibrated;
        extern const bitstring_type ExtendedStatus_localControl;

        // sequence GetNameList-Request
        struct GetNameList_Request{


            enum objectScope_type_enum {
                objectScope_type_null = 0, 
                objectScope_type_vmdSpecific,
                objectScope_type_domainSpecific,
                objectScope_type_aaSpecific,}; 
 
            struct objectScope_type : public BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) {



                objectScope_type() :  BOOST_ASN_CHOICE_STRUCT(objectScope_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(vmdSpecific, null_type, objectScope_type_vmdSpecific);
                BOOST_ASN_VALUE_CHOICE(domainSpecific, Identifier, objectScope_type_domainSpecific);
                BOOST_ASN_VALUE_CHOICE(aaSpecific, null_type, objectScope_type_aaSpecific);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            GetNameList_Request() : objectClass(), objectScope() {} 
 
            boost::asn1::value_holder<ObjectClass> objectClass;
            boost::asn1::value_holder<objectScope_type> objectScope;
            boost::shared_ptr<Identifier> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetNameList-Response
        struct GetNameList_Response{

        typedef std::vector< Identifier> listOfIdentifier_type;


            GetNameList_Response() : listOfIdentifier() {} 
 
            boost::asn1::value_holder<listOfIdentifier_type> listOfIdentifier;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Identify-Response
        struct Identify_Response{

        typedef std::vector< oid_type> listOfAbstractSyntaxes_type;


            Identify_Response() : vendorName(), modelName(), revision() {} 
 
            boost::asn1::value_holder<MMSString> vendorName;
            boost::asn1::value_holder<MMSString> modelName;
            boost::asn1::value_holder<MMSString> revision;
            boost::shared_ptr<listOfAbstractSyntaxes_type> listOfAbstractSyntaxes;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfAbstractSyntaxes_type, listOfAbstractSyntaxes)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Rename-Request
        struct Rename_Request{



            Rename_Request() : objectClass(), currentName(), newIdentifier() {} 
 
            boost::asn1::value_holder<ObjectClass> objectClass;
            boost::asn1::value_holder<ObjectName> currentName;
            boost::asn1::value_holder<Identifier> newIdentifier;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetCapabilityList-Request
        struct GetCapabilityList_Request{



            GetCapabilityList_Request() {} 
 
            boost::shared_ptr<MMSString> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMSString, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetCapabilityList-Response
        struct GetCapabilityList_Response{

        typedef std::vector< MMSString> listOfCapabilities_type;


            GetCapabilityList_Response() : listOfCapabilities() {} 
 
            boost::asn1::value_holder<listOfCapabilities_type> listOfCapabilities;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence InitiateDownloadSequence-Request
        struct InitiateDownloadSequence_Request{

        typedef std::vector< MMSString> listOfCapabilities_type;


            InitiateDownloadSequence_Request() : domainName(), listOfCapabilities(), sharable() {} 
 
            boost::asn1::value_holder<Identifier> domainName;
            boost::asn1::value_holder<listOfCapabilities_type> listOfCapabilities;
            boost::asn1::value_holder<bool> sharable;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DownloadSegment-Response
        struct DownloadSegment_Response{



            DownloadSegment_Response() : loadData() {} 
 
            boost::asn1::value_holder<LoadData> loadData;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice LoadData
        enum LoadData_enum {
            LoadData_null = 0, 
            LoadData_non_coded,
            LoadData_coded,
            LoadData_embedded,}; 
 
        struct LoadData : public BOOST_ASN_CHOICE_STRUCT(LoadData_enum) {



            LoadData() :  BOOST_ASN_CHOICE_STRUCT(LoadData_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(non_coded, octetstring_type, LoadData_non_coded);
            BOOST_ASN_VALUE_CHOICE(coded, external_type, LoadData_coded);
            BOOST_ASN_VALUE_CHOICE(embedded, embeded_type, LoadData_embedded);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence TerminateDownloadSequence-Request
        struct TerminateDownloadSequence_Request{



            TerminateDownloadSequence_Request() : domainName() {} 
 
            boost::asn1::value_holder<Identifier> domainName;
            boost::shared_ptr<ServiceError> discard;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ServiceError, discard)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence InitiateUploadSequence-Response
        struct InitiateUploadSequence_Response{

        typedef std::vector< MMSString> listOfCapabilities_type;


            InitiateUploadSequence_Response() : ulsmID(), listOfCapabilities() {} 
 
            boost::asn1::value_holder<Integer32> ulsmID;
            boost::asn1::value_holder<listOfCapabilities_type> listOfCapabilities;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence UploadSegment-Response
        struct UploadSegment_Response{



            UploadSegment_Response() : loadData() {} 
 
            boost::asn1::value_holder<LoadData> loadData;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RequestDomainDownload-Request
        struct RequestDomainDownload_Request{

        typedef std::vector< MMSString> listOfCapabilities_type;


            RequestDomainDownload_Request() : domainName(), sharable(), fileName() {} 
 
            boost::asn1::value_holder<Identifier> domainName;
            boost::shared_ptr<listOfCapabilities_type> listOfCapabilities;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfCapabilities_type, listOfCapabilities)

            boost::asn1::value_holder<bool> sharable;
            boost::asn1::value_holder<FileName> fileName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RequestDomainUpload-Request
        struct RequestDomainUpload_Request{



            RequestDomainUpload_Request() : domainName(), fileName() {} 
 
            boost::asn1::value_holder<Identifier> domainName;
            boost::asn1::value_holder<FileName> fileName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence LoadDomainContent-Request
        struct LoadDomainContent_Request{

        typedef std::vector< MMSString> listOfCapabilities_type;


            LoadDomainContent_Request() : domainName(), sharable(), fileName() {} 
 
            boost::asn1::value_holder<Identifier> domainName;
            boost::shared_ptr<listOfCapabilities_type> listOfCapabilities;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfCapabilities_type, listOfCapabilities)

            boost::asn1::value_holder<bool> sharable;
            boost::asn1::value_holder<FileName> fileName;
            boost::shared_ptr<MMS_Environment_1::ApplicationReference> thirdParty;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, thirdParty)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence StoreDomainContent-Request
        struct StoreDomainContent_Request{



            StoreDomainContent_Request() : domainName(), fileName() {} 
 
            boost::asn1::value_holder<Identifier> domainName;
            boost::asn1::value_holder<FileName> fileName;
            boost::shared_ptr<MMS_Environment_1::ApplicationReference> thirdParty;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, thirdParty)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetDomainAttributes-Response
        struct GetDomainAttributes_Response{

        typedef std::vector< MMSString> listOfCapabilities_type;
        typedef std::vector< Identifier> listOfProgramInvocations_type;


            GetDomainAttributes_Response() : listOfCapabilities(), state(), mmsDeletable(), sharable(), listOfProgramInvocations(), uploadInProgress() {} 
 
            boost::asn1::value_holder<listOfCapabilities_type> listOfCapabilities;
            boost::asn1::value_holder<MMS_Object_Module_1::DomainState> state;
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::asn1::value_holder<bool> sharable;
            boost::asn1::value_holder<listOfProgramInvocations_type> listOfProgramInvocations;
            boost::asn1::value_holder<Integer8> uploadInProgress;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CreateProgramInvocation-Request
        struct CreateProgramInvocation_Request{

        typedef std::vector< Identifier> listOfDomainNames_type;


            CreateProgramInvocation_Request() : programInvocationName(), listOfDomainNames() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;
            boost::asn1::value_holder<listOfDomainNames_type> listOfDomainNames;
            boost::shared_ptr<bool> reusable;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, reusable)

            boost::shared_ptr<bool> monitorType;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, monitorType)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        extern const int CS_CreateProgramInvocation_Request_normal;
        extern const int CS_CreateProgramInvocation_Request_controlling;
        extern const int CS_CreateProgramInvocation_Request_controlled;

        // sequence Start-Request
        struct Start_Request{


            enum executionArgument_type_enum {
                executionArgument_type_null = 0, 
                executionArgument_type_simpleString,
                executionArgument_type_encodedString,
                executionArgument_type_embeddedString,}; 
 
            struct executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {



                executionArgument_type() :  BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(simpleString, MMSString, executionArgument_type_simpleString);
                BOOST_ASN_VALUE_CHOICE(encodedString, external_type, executionArgument_type_encodedString);
                BOOST_ASN_VALUE_CHOICE(embeddedString, embeded_type, executionArgument_type_embeddedString);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Start_Request() : programInvocationName() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;
            boost::asn1::value_holder<executionArgument_type> executionArgument;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice CS-Start-Request
        enum CS_Start_Request_impl_enum {
            CS_Start_Request_impl_null = 0, 
            CS_Start_Request_impl_normal,
            CS_Start_Request_impl_controlling,}; 
 
        struct CS_Start_Request_impl : public BOOST_ASN_CHOICE_STRUCT(CS_Start_Request_impl_enum) {


            struct controlling_type{



                controlling_type() {} 
 
                boost::shared_ptr<visiblestring_type> startLocation;
                BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, startLocation)

                boost::shared_ptr<StartCount> startCount;
                BOOST_ASN_VALUE_FUNC_DECLARATE(StartCount, startCount)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            CS_Start_Request_impl() :  BOOST_ASN_CHOICE_STRUCT(CS_Start_Request_impl_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(normal, null_type, CS_Start_Request_impl_normal);
            BOOST_ASN_VALUE_CHOICE(controlling, controlling_type, CS_Start_Request_impl_controlling);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice StartCount
        enum StartCount_enum {
            StartCount_null = 0, 
            StartCount_noLimit,
            StartCount_cycleCount,
            StartCount_stepCount,}; 
 
        struct StartCount : public BOOST_ASN_CHOICE_STRUCT(StartCount_enum) {



            StartCount() :  BOOST_ASN_CHOICE_STRUCT(StartCount_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(noLimit, null_type, StartCount_noLimit);
            BOOST_ASN_VALUE_CHOICE(cycleCount, int, StartCount_cycleCount);
            BOOST_ASN_VALUE_CHOICE(stepCount, int, StartCount_stepCount);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Stop-Request
        struct Stop_Request{



            Stop_Request() : programInvocationName() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Resume-Request
        struct Resume_Request{


            enum executionArgument_type_enum {
                executionArgument_type_null = 0, 
                executionArgument_type_simpleString,
                executionArgument_type_encodedString,
                executionArgument_type_enmbeddedString,}; 
 
            struct executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {



                executionArgument_type() :  BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(simpleString, MMSString, executionArgument_type_simpleString);
                BOOST_ASN_VALUE_CHOICE(encodedString, external_type, executionArgument_type_encodedString);
                BOOST_ASN_VALUE_CHOICE(enmbeddedString, embeded_type, executionArgument_type_enmbeddedString);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Resume_Request() : programInvocationName() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;
            boost::asn1::value_holder<executionArgument_type> executionArgument;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice CS-Resume-Request
        enum CS_Resume_Request_impl_enum {
            CS_Resume_Request_impl_null = 0, 
            CS_Resume_Request_impl_normal,
            CS_Resume_Request_impl_controlling,}; 
 
        struct CS_Resume_Request_impl : public BOOST_ASN_CHOICE_STRUCT(CS_Resume_Request_impl_enum) {


            struct controlling_type{


                enum modeType_type_enum {
                    modeType_type_null = 0, 
                    modeType_type_continueMode,
                    modeType_type_changeMode,}; 
 
                struct modeType_type : public BOOST_ASN_CHOICE_STRUCT(modeType_type_enum) {



                    modeType_type() :  BOOST_ASN_CHOICE_STRUCT(modeType_type_enum) () {}
 
                    BOOST_ASN_VALUE_CHOICE(continueMode, null_type, modeType_type_continueMode);
                    BOOST_ASN_VALUE_CHOICE(changeMode, StartCount, modeType_type_changeMode);

                    BOOST_ASN_ARCHIVE_FUNC;
                }; 
 


                controlling_type() : modeType() {} 
 
                boost::asn1::value_holder<modeType_type> modeType;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            CS_Resume_Request_impl() :  BOOST_ASN_CHOICE_STRUCT(CS_Resume_Request_impl_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(normal, null_type, CS_Resume_Request_impl_normal);
            BOOST_ASN_VALUE_CHOICE(controlling, controlling_type, CS_Resume_Request_impl_controlling);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Reset-Request
        struct Reset_Request{



            Reset_Request() : programInvocationName() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Kill-Request
        struct Kill_Request{



            Kill_Request() : programInvocationName() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetProgramInvocationAttributes-Response
        struct GetProgramInvocationAttributes_Response{


            enum executionArgument_type_enum {
                executionArgument_type_null = 0, 
                executionArgument_type_simpleString,
                executionArgument_type_encodedString,
                executionArgument_type_enmbeddedString,}; 
 
            struct executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {



                executionArgument_type() :  BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(simpleString, MMSString, executionArgument_type_simpleString);
                BOOST_ASN_VALUE_CHOICE(encodedString, external_type, executionArgument_type_encodedString);
                BOOST_ASN_VALUE_CHOICE(enmbeddedString, embeded_type, executionArgument_type_enmbeddedString);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        typedef std::vector< Identifier> listOfDomainNames_type;


            GetProgramInvocationAttributes_Response() : state(), listOfDomainNames(), mmsDeletable(), reusable(), monitor(), executionArgument() {} 
 
            boost::asn1::value_holder<MMS_Object_Module_1::ProgramInvocationState> state;
            boost::asn1::value_holder<listOfDomainNames_type> listOfDomainNames;
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::asn1::value_holder<bool> reusable;
            boost::asn1::value_holder<bool> monitor;
            boost::asn1::value_holder<executionArgument_type> executionArgument;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CS-GetProgramInvocationAttributes-Response
        struct CS_GetProgramInvocationAttributes_Response{


            enum control_type_enum {
                control_type_null = 0, 
                control_type_controlling,
                control_type_controlled,
                control_type_normal,}; 
 
            struct control_type : public BOOST_ASN_CHOICE_STRUCT(control_type_enum) {


                struct controlling_type{


                    enum runningMode_type_enum {
                        runningMode_type_null = 0, 
                        runningMode_type_freeRunning,
                        runningMode_type_cycleLimited,
                        runningMode_type_stepLimited,}; 
 
                    struct runningMode_type : public BOOST_ASN_CHOICE_STRUCT(runningMode_type_enum) {



                        runningMode_type() :  BOOST_ASN_CHOICE_STRUCT(runningMode_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(freeRunning, null_type, runningMode_type_freeRunning);
                        BOOST_ASN_VALUE_CHOICE(cycleLimited, int, runningMode_type_cycleLimited);
                        BOOST_ASN_VALUE_CHOICE(stepLimited, int, runningMode_type_stepLimited);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 
                typedef std::vector< Identifier> controlledPI_type;


                    controlling_type() : controlledPI(), runningMode() {} 
 
                    boost::asn1::value_holder<controlledPI_type> controlledPI;
                    boost::shared_ptr<visiblestring_type> programLocation;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, programLocation)

                    boost::asn1::value_holder<runningMode_type> runningMode;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 

                enum controlled_type_enum {
                    controlled_type_null = 0, 
                    controlled_type_controllingPI,
                    controlled_type_none,}; 
 
                struct controlled_type : public BOOST_ASN_CHOICE_STRUCT(controlled_type_enum) {



                    controlled_type() :  BOOST_ASN_CHOICE_STRUCT(controlled_type_enum) () {}
 
                    BOOST_ASN_VALUE_CHOICE(controllingPI, Identifier, controlled_type_controllingPI);
                    BOOST_ASN_VALUE_CHOICE(none, null_type, controlled_type_none);

                    BOOST_ASN_ARCHIVE_FUNC;
                }; 
 


                control_type() :  BOOST_ASN_CHOICE_STRUCT(control_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(controlling, controlling_type, control_type_controlling);
                BOOST_ASN_VALUE_CHOICE(controlled, controlled_type, control_type_controlled);
                BOOST_ASN_VALUE_CHOICE(normal, null_type, control_type_normal);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            CS_GetProgramInvocationAttributes_Response() : errorCode(), control() {} 
 
            boost::asn1::value_holder<int> errorCode;
            boost::asn1::value_holder<control_type> control;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Select-Request
        struct Select_Request{

        typedef std::vector< Identifier> controlled_type;


            Select_Request() {} 
 
            boost::shared_ptr<Identifier> controlling;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, controlling)

            boost::shared_ptr<controlled_type> controlled;
            BOOST_ASN_VALUE_FUNC_DECLARATE(controlled_type, controlled)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlterProgramInvocationAttributes-Request
        struct AlterProgramInvocationAttributes_Request{



            AlterProgramInvocationAttributes_Request() : programInvocation() {} 
 
            boost::asn1::value_holder<Identifier> programInvocation;
            boost::shared_ptr<StartCount> startCount;
            BOOST_ASN_VALUE_FUNC_DECLARATE(StartCount, startCount)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReconfigureProgramInvocation-Request
        struct ReconfigureProgramInvocation_Request{

        typedef std::vector< Identifier> domainsToAdd_type;
        typedef std::vector< Identifier> domainsToRemove_type;


            ReconfigureProgramInvocation_Request() : oldProgramInvocationName(), domainsToAdd(), domainsToRemove() {} 
 
            boost::asn1::value_holder<Identifier> oldProgramInvocationName;
            boost::shared_ptr<Identifier> newProgramInvocationName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, newProgramInvocationName)

            boost::asn1::value_holder<domainsToAdd_type> domainsToAdd;
            boost::asn1::value_holder<domainsToRemove_type> domainsToRemove;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice ControlElement
        enum ControlElement_enum {
            ControlElement_null = 0, 
            ControlElement_beginDomainDef,
            ControlElement_continueDomainDef,
            ControlElement_endDomainDef,
            ControlElement_piDefinition,}; 
 
        struct ControlElement : public BOOST_ASN_CHOICE_STRUCT(ControlElement_enum) {


            struct beginDomainDef_type{

            typedef std::vector< MMSString> capabilities_type;


                beginDomainDef_type() : domainName(), capabilities(), sharable() {} 
 
                boost::asn1::value_holder<Identifier> domainName;
                boost::asn1::value_holder<capabilities_type> capabilities;
                boost::asn1::value_holder<bool> sharable;
                boost::shared_ptr<LoadData> loadData;
                BOOST_ASN_VALUE_FUNC_DECLARATE(LoadData, loadData)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            struct continueDomainDef_type{



                continueDomainDef_type() : domainName(), loadData() {} 
 
                boost::asn1::value_holder<Identifier> domainName;
                boost::asn1::value_holder<LoadData> loadData;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            struct piDefinition_type{

            typedef std::vector< Identifier> listOfDomains_type;


                piDefinition_type() : piName(), listOfDomains() {} 
 
                boost::asn1::value_holder<Identifier> piName;
                boost::asn1::value_holder<listOfDomains_type> listOfDomains;
                boost::shared_ptr<bool> reusable;
                BOOST_ASN_VALUE_FUNC_DECLARATE(bool, reusable)

                boost::shared_ptr<bool> monitorType;
                BOOST_ASN_VALUE_FUNC_DECLARATE(bool, monitorType)

                boost::shared_ptr<MMS_Object_Module_1::ProgramInvocationState> pIState;
                BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::ProgramInvocationState, pIState)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            ControlElement() :  BOOST_ASN_CHOICE_STRUCT(ControlElement_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(beginDomainDef, beginDomainDef_type, ControlElement_beginDomainDef);
            BOOST_ASN_VALUE_CHOICE(continueDomainDef, continueDomainDef_type, ControlElement_continueDomainDef);
            BOOST_ASN_VALUE_CHOICE(endDomainDef, Identifier, ControlElement_endDomainDef);
            BOOST_ASN_VALUE_CHOICE(piDefinition, piDefinition_type, ControlElement_piDefinition);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice InitiateUnitControl-Error
        enum InitiateUnitControl_Error_enum {
            InitiateUnitControl_Error_null = 0, 
            InitiateUnitControl_Error_domain,
            InitiateUnitControl_Error_programInvocation,}; 
 
        struct InitiateUnitControl_Error : public BOOST_ASN_CHOICE_STRUCT(InitiateUnitControl_Error_enum) {



            InitiateUnitControl_Error() :  BOOST_ASN_CHOICE_STRUCT(InitiateUnitControl_Error_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(domain, Identifier, InitiateUnitControl_Error_domain);
            BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier, InitiateUnitControl_Error_programInvocation);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence UnitControlLoadSegment-Response
        struct UnitControlLoadSegment_Response{

        typedef std::vector< ControlElement> controlElements_type;


            UnitControlLoadSegment_Response() : controlElements() {} 
 
            boost::asn1::value_holder<controlElements_type> controlElements;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence UnitControlUpload-Request
        struct UnitControlUpload_Request{


            enum continueAfter_type_enum {
                continueAfter_type_null = 0, 
                continueAfter_type_domain,
                continueAfter_type_ulsmID,
                continueAfter_type_programInvocation,}; 
 
            struct continueAfter_type : public BOOST_ASN_CHOICE_STRUCT(continueAfter_type_enum) {



                continueAfter_type() :  BOOST_ASN_CHOICE_STRUCT(continueAfter_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(domain, Identifier, continueAfter_type_domain);
                BOOST_ASN_VALUE_CHOICE(ulsmID, int, continueAfter_type_ulsmID);
                BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier, continueAfter_type_programInvocation);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            UnitControlUpload_Request() : unitControlName() {} 
 
            boost::asn1::value_holder<Identifier> unitControlName;
            boost::asn1::value_holder<continueAfter_type> continueAfter;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence UnitControlUpload-Response
        struct UnitControlUpload_Response{


            enum nextElement_type_enum {
                nextElement_type_null = 0, 
                nextElement_type_domain,
                nextElement_type_ulsmID,
                nextElement_type_programInvocation,}; 
 
            struct nextElement_type : public BOOST_ASN_CHOICE_STRUCT(nextElement_type_enum) {



                nextElement_type() :  BOOST_ASN_CHOICE_STRUCT(nextElement_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(domain, Identifier, nextElement_type_domain);
                BOOST_ASN_VALUE_CHOICE(ulsmID, int, nextElement_type_ulsmID);
                BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier, nextElement_type_programInvocation);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        typedef std::vector< ControlElement> controlElements_type;


            UnitControlUpload_Response() : controlElements() {} 
 
            boost::asn1::value_holder<controlElements_type> controlElements;
            boost::asn1::value_holder<nextElement_type> nextElement;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence StartUnitControl-Request
        struct StartUnitControl_Request{


            enum executionArgument_type_enum {
                executionArgument_type_null = 0, 
                executionArgument_type_simpleString,
                executionArgument_type_encodedString,
                executionArgument_type_enmbeddedString,}; 
 
            struct executionArgument_type : public BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) {



                executionArgument_type() :  BOOST_ASN_CHOICE_STRUCT(executionArgument_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(simpleString, MMSString, executionArgument_type_simpleString);
                BOOST_ASN_VALUE_CHOICE(encodedString, external_type, executionArgument_type_encodedString);
                BOOST_ASN_VALUE_CHOICE(enmbeddedString, embeded_type, executionArgument_type_enmbeddedString);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            StartUnitControl_Request() : unitControlName() {} 
 
            boost::asn1::value_holder<Identifier> unitControlName;
            boost::asn1::value_holder<executionArgument_type> executionArgument;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence StartUnitControl-Error
        struct StartUnitControl_Error{



            StartUnitControl_Error() : programInvocationName(), programInvocationState() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;
            boost::asn1::value_holder<MMS_Object_Module_1::ProgramInvocationState> programInvocationState;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence StopUnitControl-Error
        struct StopUnitControl_Error{



            StopUnitControl_Error() : programInvocationName(), programInvocationState() {} 
 
            boost::asn1::value_holder<Identifier> programInvocationName;
            boost::asn1::value_holder<MMS_Object_Module_1::ProgramInvocationState> programInvocationState;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CreateUnitControl-Request
        struct CreateUnitControl_Request{

        typedef std::vector< Identifier> domains_type;
        typedef std::vector< Identifier> programInvocations_type;


            CreateUnitControl_Request() : unitControl(), domains(), programInvocations() {} 
 
            boost::asn1::value_holder<Identifier> unitControl;
            boost::asn1::value_holder<domains_type> domains;
            boost::asn1::value_holder<programInvocations_type> programInvocations;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AddToUnitControl-Request
        struct AddToUnitControl_Request{

        typedef std::vector< Identifier> domains_type;
        typedef std::vector< Identifier> programInvocations_type;


            AddToUnitControl_Request() : unitControl(), domains(), programInvocations() {} 
 
            boost::asn1::value_holder<Identifier> unitControl;
            boost::asn1::value_holder<domains_type> domains;
            boost::asn1::value_holder<programInvocations_type> programInvocations;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RemoveFromUnitControl-Request
        struct RemoveFromUnitControl_Request{

        typedef std::vector< Identifier> domains_type;
        typedef std::vector< Identifier> programInvocations_type;


            RemoveFromUnitControl_Request() : unitControl(), domains(), programInvocations() {} 
 
            boost::asn1::value_holder<Identifier> unitControl;
            boost::asn1::value_holder<domains_type> domains;
            boost::asn1::value_holder<programInvocations_type> programInvocations;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetUnitControlAttributes-Response
        struct GetUnitControlAttributes_Response{

        typedef std::vector< Identifier> domains_type;
        typedef std::vector< Identifier> programInvocations_type;


            GetUnitControlAttributes_Response() : domains(), programInvocations() {} 
 
            boost::asn1::value_holder<domains_type> domains;
            boost::asn1::value_holder<programInvocations_type> programInvocations;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence LoadUnitControlFromFile-Request
        struct LoadUnitControlFromFile_Request{



            LoadUnitControlFromFile_Request() : unitControlName(), fileName() {} 
 
            boost::asn1::value_holder<Identifier> unitControlName;
            boost::asn1::value_holder<FileName> fileName;
            boost::shared_ptr<MMS_Environment_1::ApplicationReference> thirdParty;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, thirdParty)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice LoadUnitControlFromFile-Error
        enum LoadUnitControlFromFile_Error_enum {
            LoadUnitControlFromFile_Error_null = 0, 
            LoadUnitControlFromFile_Error_none,
            LoadUnitControlFromFile_Error_domain,
            LoadUnitControlFromFile_Error_programInvocation,}; 
 
        struct LoadUnitControlFromFile_Error : public BOOST_ASN_CHOICE_STRUCT(LoadUnitControlFromFile_Error_enum) {



            LoadUnitControlFromFile_Error() :  BOOST_ASN_CHOICE_STRUCT(LoadUnitControlFromFile_Error_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(none, null_type, LoadUnitControlFromFile_Error_none);
            BOOST_ASN_VALUE_CHOICE(domain, Identifier, LoadUnitControlFromFile_Error_domain);
            BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier, LoadUnitControlFromFile_Error_programInvocation);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence StoreUnitControlToFile-Request
        struct StoreUnitControlToFile_Request{



            StoreUnitControlToFile_Request() : unitControlName(), fileName() {} 
 
            boost::asn1::value_holder<Identifier> unitControlName;
            boost::asn1::value_holder<FileName> fileName;
            boost::shared_ptr<MMS_Environment_1::ApplicationReference> thirdParty;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, thirdParty)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice DeleteUnitControl-Error
        enum DeleteUnitControl_Error_enum {
            DeleteUnitControl_Error_null = 0, 
            DeleteUnitControl_Error_domain,
            DeleteUnitControl_Error_programInvocation,}; 
 
        struct DeleteUnitControl_Error : public BOOST_ASN_CHOICE_STRUCT(DeleteUnitControl_Error_enum) {



            DeleteUnitControl_Error() :  BOOST_ASN_CHOICE_STRUCT(DeleteUnitControl_Error_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(domain, Identifier, DeleteUnitControl_Error_domain);
            BOOST_ASN_VALUE_CHOICE(programInvocation, Identifier, DeleteUnitControl_Error_programInvocation);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice TypeSpecification
        enum TypeSpecification_enum {
            TypeSpecification_null = 0, 
            TypeSpecification_typeName,
            TypeSpecification_typeDescription,}; 
 
        struct TypeSpecification : public BOOST_ASN_CHOICE_STRUCT(TypeSpecification_enum) {



            TypeSpecification() :  BOOST_ASN_CHOICE_STRUCT(TypeSpecification_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(typeName, ObjectName, TypeSpecification_typeName);
            BOOST_ASN_VALUE_CHOICE(typeDescription, MMS_Object_Module_1::TypeDescription, TypeSpecification_typeDescription);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 

            enum AlternateAccess_sequence_of_enum {
                AlternateAccess_sequence_of_null = 0, 
                AlternateAccess_sequence_of_unnamed,
                AlternateAccess_sequence_of_named,}; 
 
            struct AlternateAccess_sequence_of : public BOOST_ASN_CHOICE_STRUCT(AlternateAccess_sequence_of_enum) {


                struct named_type{



                    named_type() : componentName(), access() {} 
 
                    boost::asn1::value_holder<Identifier> componentName;
                    boost::asn1::value_holder<AlternateAccessSelection> access;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                AlternateAccess_sequence_of() :  BOOST_ASN_CHOICE_STRUCT(AlternateAccess_sequence_of_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(unnamed, AlternateAccessSelection, AlternateAccess_sequence_of_unnamed);
                BOOST_ASN_VALUE_CHOICE(named, named_type, AlternateAccess_sequence_of_named);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        // choice AlternateAccessSelection
        enum AlternateAccessSelection_enum {
            AlternateAccessSelection_null = 0, 
            AlternateAccessSelection_selectAlternateAccess,
            AlternateAccessSelection_selectAccess,}; 
 
        struct AlternateAccessSelection : public BOOST_ASN_CHOICE_STRUCT(AlternateAccessSelection_enum) {


            struct selectAlternateAccess_type{


                enum accessSelection_type_enum {
                    accessSelection_type_null = 0, 
                    accessSelection_type_component,
                    accessSelection_type_index,
                    accessSelection_type_indexRange,
                    accessSelection_type_allElements,}; 
 
                struct accessSelection_type : public BOOST_ASN_CHOICE_STRUCT(accessSelection_type_enum) {


                    struct indexRange_type{



                        indexRange_type() : lowIndex(), numberOfElements() {} 
 
                        boost::asn1::value_holder<Unsigned32> lowIndex;
                        boost::asn1::value_holder<Unsigned32> numberOfElements;

                        BOOST_ASN_ARCHIVE_FUNC;
                    };
 


                    accessSelection_type() :  BOOST_ASN_CHOICE_STRUCT(accessSelection_type_enum) () {}
 
                    BOOST_ASN_VALUE_CHOICE(component, Identifier, accessSelection_type_component);
                    BOOST_ASN_VALUE_CHOICE(index, Unsigned32, accessSelection_type_index);
                    BOOST_ASN_VALUE_CHOICE(indexRange, indexRange_type, accessSelection_type_indexRange);
                    BOOST_ASN_VALUE_CHOICE(allElements, null_type, accessSelection_type_allElements);

                    BOOST_ASN_ARCHIVE_FUNC;
                }; 
 


                selectAlternateAccess_type() : accessSelection(), alternateAccess() {} 
 
                boost::asn1::value_holder<accessSelection_type> accessSelection;
                boost::asn1::value_holder<AlternateAccess> alternateAccess;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            enum selectAccess_type_enum {
                selectAccess_type_null = 0, 
                selectAccess_type_component,
                selectAccess_type_index,
                selectAccess_type_indexRange,
                selectAccess_type_allElements,}; 
 
            struct selectAccess_type : public BOOST_ASN_CHOICE_STRUCT(selectAccess_type_enum) {


                struct indexRange_type{



                    indexRange_type() : lowIndex(), numberOfElements() {} 
 
                    boost::asn1::value_holder<Unsigned32> lowIndex;
                    boost::asn1::value_holder<Unsigned32> numberOfElements;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                selectAccess_type() :  BOOST_ASN_CHOICE_STRUCT(selectAccess_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(component, Identifier, selectAccess_type_component);
                BOOST_ASN_VALUE_CHOICE(index, Unsigned32, selectAccess_type_index);
                BOOST_ASN_VALUE_CHOICE(indexRange, indexRange_type, selectAccess_type_indexRange);
                BOOST_ASN_VALUE_CHOICE(allElements, null_type, selectAccess_type_allElements);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            AlternateAccessSelection() :  BOOST_ASN_CHOICE_STRUCT(AlternateAccessSelection_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(selectAlternateAccess, selectAlternateAccess_type, AlternateAccessSelection_selectAlternateAccess);
            BOOST_ASN_VALUE_CHOICE(selectAccess, selectAccess_type, AlternateAccessSelection_selectAccess);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice AccessResult
        enum AccessResult_enum {
            AccessResult_null = 0, 
            AccessResult_failure,
            AccessResult_success,}; 
 
        struct AccessResult : public BOOST_ASN_CHOICE_STRUCT(AccessResult_enum) {



            AccessResult() :  BOOST_ASN_CHOICE_STRUCT(AccessResult_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(failure, DataAccessError, AccessResult_failure);
            BOOST_ASN_VALUE_CHOICE(success, Data, AccessResult_success);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice Data
        enum Data_enum {
            Data_null = 0, 
            Data_array,
            Data_structure,
            Data_boolean,
            Data_bit_string,
            Data_integer,
            Data_unsignedV,
            Data_floating_point,
            Data_octet_string,
            Data_visible_string,
            Data_generalized_time,
            Data_binary_time,
            Data_bcd,
            Data_booleanArray,
            Data_objId,
            Data_mMSString,}; 
 
        struct Data : public BOOST_ASN_CHOICE_STRUCT(Data_enum) {

        typedef std::vector< Data> array_type;
        typedef std::vector< Data> structure_type;


            Data() :  BOOST_ASN_CHOICE_STRUCT(Data_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(array, array_type, Data_array);
            BOOST_ASN_VALUE_CHOICE(structure, structure_type, Data_structure);
            BOOST_ASN_VALUE_CHOICE(boolean, bool, Data_boolean);
            BOOST_ASN_VALUE_CHOICE(bit_string, bitstring_type, Data_bit_string);
            BOOST_ASN_VALUE_CHOICE(integer, int, Data_integer);
            BOOST_ASN_VALUE_CHOICE(unsignedV, int, Data_unsignedV);
            BOOST_ASN_VALUE_CHOICE(floating_point, FloatingPoint, Data_floating_point);
            BOOST_ASN_VALUE_CHOICE(octet_string, octetstring_type, Data_octet_string);
            BOOST_ASN_VALUE_CHOICE(visible_string, visiblestring_type, Data_visible_string);
            BOOST_ASN_VALUE_CHOICE(generalized_time, gentime_type, Data_generalized_time);
            BOOST_ASN_VALUE_CHOICE(binary_time, TimeOfDay, Data_binary_time);
            BOOST_ASN_VALUE_CHOICE(bcd, int, Data_bcd);
            BOOST_ASN_VALUE_CHOICE(booleanArray, bitstring_type, Data_booleanArray);
            BOOST_ASN_VALUE_CHOICE(objId, oid_type, Data_objId);
            BOOST_ASN_VALUE_CHOICE(mMSString, MMSString, Data_mMSString);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const int DataAccessError_object_invalidated;
        extern const int DataAccessError_hardware_fault;
        extern const int DataAccessError_temporarily_unavailable;
        extern const int DataAccessError_object_access_denied;
        extern const int DataAccessError_object_undefined;
        extern const int DataAccessError_invalid_address;
        extern const int DataAccessError_type_unsupported;
        extern const int DataAccessError_type_inconsistent;
        extern const int DataAccessError_object_attribute_inconsistent;
        extern const int DataAccessError_object_access_unsupported;
        extern const int DataAccessError_object_non_existent;
        extern const int DataAccessError_object_value_invalid;

        // choice VariableAccessSpecification
        enum VariableAccessSpecification_enum {
            VariableAccessSpecification_null = 0, 
            VariableAccessSpecification_listOfVariable,
            VariableAccessSpecification_variableListName,}; 
 
        struct VariableAccessSpecification : public BOOST_ASN_CHOICE_STRUCT(VariableAccessSpecification_enum) {
        struct listOfVariable_type_sequence_of;


                struct listOfVariable_type_sequence_of{



                    listOfVariable_type_sequence_of() : variableSpecification() {} 
 
                    boost::asn1::value_holder<VariableSpecification> variableSpecification;
                    boost::shared_ptr<AlternateAccess> alternateAccess;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess, alternateAccess)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 
        typedef std::vector< listOfVariable_type_sequence_of> listOfVariable_type;


            VariableAccessSpecification() :  BOOST_ASN_CHOICE_STRUCT(VariableAccessSpecification_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(listOfVariable, listOfVariable_type, VariableAccessSpecification_listOfVariable);
            BOOST_ASN_VALUE_CHOICE(variableListName, ObjectName, VariableAccessSpecification_variableListName);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice VariableSpecification
        enum VariableSpecification_enum {
            VariableSpecification_null = 0, 
            VariableSpecification_name,
            VariableSpecification_address,
            VariableSpecification_variableDescription,
            VariableSpecification_scatteredAccessDescription,
            VariableSpecification_invalidated,}; 
 
        struct VariableSpecification : public BOOST_ASN_CHOICE_STRUCT(VariableSpecification_enum) {


            struct variableDescription_type{



                variableDescription_type() : address(), typeSpecification() {} 
 
                boost::asn1::value_holder<MMS_Object_Module_1::Address> address;
                boost::asn1::value_holder<TypeSpecification> typeSpecification;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            VariableSpecification() :  BOOST_ASN_CHOICE_STRUCT(VariableSpecification_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(name, ObjectName, VariableSpecification_name);
            BOOST_ASN_VALUE_CHOICE(address, MMS_Object_Module_1::Address, VariableSpecification_address);
            BOOST_ASN_VALUE_CHOICE(variableDescription, variableDescription_type, VariableSpecification_variableDescription);
            BOOST_ASN_VALUE_CHOICE(scatteredAccessDescription, ISO_9506_MMS_1A::ScatteredAccessDescription, VariableSpecification_scatteredAccessDescription);
            BOOST_ASN_VALUE_CHOICE(invalidated, null_type, VariableSpecification_invalidated);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence Read-Request
        struct Read_Request{



            Read_Request() : variableAccessSpecification() {} 
 
            boost::shared_ptr<bool> specificationWithResult;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, specificationWithResult)

            boost::asn1::value_holder<VariableAccessSpecification> variableAccessSpecification;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Read-Response
        struct Read_Response{

        typedef std::vector< AccessResult> listOfAccessResult_type;


            Read_Response() : listOfAccessResult() {} 
 
            boost::shared_ptr<VariableAccessSpecification> variableAccessSpecification;
            BOOST_ASN_VALUE_FUNC_DECLARATE(VariableAccessSpecification, variableAccessSpecification)

            boost::asn1::value_holder<listOfAccessResult_type> listOfAccessResult;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Write-Request
        struct Write_Request{

        typedef std::vector< Data> listOfData_type;


            Write_Request() : variableAccessSpecification(), listOfData() {} 
 
            boost::asn1::value_holder<VariableAccessSpecification> variableAccessSpecification;
            boost::asn1::value_holder<listOfData_type> listOfData;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 

            enum Write_Response_sequence_of_enum {
                Write_Response_sequence_of_null = 0, 
                Write_Response_sequence_of_failure,
                Write_Response_sequence_of_success,}; 
 
            struct Write_Response_sequence_of : public BOOST_ASN_CHOICE_STRUCT(Write_Response_sequence_of_enum) {



                Write_Response_sequence_of() :  BOOST_ASN_CHOICE_STRUCT(Write_Response_sequence_of_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(failure, DataAccessError, Write_Response_sequence_of_failure);
                BOOST_ASN_VALUE_CHOICE(success, null_type, Write_Response_sequence_of_success);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        // sequence InformationReport
        struct InformationReport{

        typedef std::vector< AccessResult> listOfAccessResult_type;


            InformationReport() : variableAccessSpecification(), listOfAccessResult() {} 
 
            boost::asn1::value_holder<VariableAccessSpecification> variableAccessSpecification;
            boost::asn1::value_holder<listOfAccessResult_type> listOfAccessResult;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice GetVariableAccessAttributes-Request
        enum GetVariableAccessAttributes_Request_enum {
            GetVariableAccessAttributes_Request_null = 0, 
            GetVariableAccessAttributes_Request_name,
            GetVariableAccessAttributes_Request_address,}; 
 
        struct GetVariableAccessAttributes_Request : public BOOST_ASN_CHOICE_STRUCT(GetVariableAccessAttributes_Request_enum) {



            GetVariableAccessAttributes_Request() :  BOOST_ASN_CHOICE_STRUCT(GetVariableAccessAttributes_Request_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(name, ObjectName, GetVariableAccessAttributes_Request_name);
            BOOST_ASN_VALUE_CHOICE(address, MMS_Object_Module_1::Address, GetVariableAccessAttributes_Request_address);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetVariableAccessAttributes-Response
        struct GetVariableAccessAttributes_Response{



            GetVariableAccessAttributes_Response() : mmsDeletable(), typeDescription() {} 
 
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::shared_ptr<MMS_Object_Module_1::Address> address;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Address, address)

            boost::asn1::value_holder<MMS_Object_Module_1::TypeDescription> typeDescription;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)

            boost::shared_ptr<visiblestring_type> meaning;
            BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, meaning)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineNamedVariable-Request
        struct DefineNamedVariable_Request{



            DefineNamedVariable_Request() : variableName(), address() {} 
 
            boost::asn1::value_holder<ObjectName> variableName;
            boost::asn1::value_holder<MMS_Object_Module_1::Address> address;
            boost::shared_ptr<TypeSpecification> typeSpecification;
            BOOST_ASN_VALUE_FUNC_DECLARATE(TypeSpecification, typeSpecification)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteVariableAccess-Request
        struct DeleteVariableAccess_Request{

        typedef std::vector< ObjectName> listOfName_type;

            static const int scopeOfDelete_specific;
            static const int scopeOfDelete_aa_specific;
            static const int scopeOfDelete_domain;
            static const int scopeOfDelete_vmd;


            DeleteVariableAccess_Request() {} 
 
            boost::shared_ptr<int> scopeOfDelete;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, scopeOfDelete)

            boost::shared_ptr<listOfName_type> listOfName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfName_type, listOfName)

            boost::shared_ptr<Identifier> domainName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, domainName)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteVariableAccess-Response
        struct DeleteVariableAccess_Response{



            DeleteVariableAccess_Response() : numberMatched(), numberDeleted() {} 
 
            boost::asn1::value_holder<Unsigned32> numberMatched;
            boost::asn1::value_holder<Unsigned32> numberDeleted;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineNamedVariableList-Request
        struct DefineNamedVariableList_Request{
        struct listOfVariable_type_sequence_of;


                struct listOfVariable_type_sequence_of{



                    listOfVariable_type_sequence_of() : variableSpecification() {} 
 
                    boost::asn1::value_holder<VariableSpecification> variableSpecification;
                    boost::shared_ptr<AlternateAccess> alternateAccess;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess, alternateAccess)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 
        typedef std::vector< listOfVariable_type_sequence_of> listOfVariable_type;


            DefineNamedVariableList_Request() : variableListName(), listOfVariable() {} 
 
            boost::asn1::value_holder<ObjectName> variableListName;
            boost::asn1::value_holder<listOfVariable_type> listOfVariable;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetNamedVariableListAttributes-Response
        struct GetNamedVariableListAttributes_Response{
        struct listOfVariable_type_sequence_of;


                struct listOfVariable_type_sequence_of{



                    listOfVariable_type_sequence_of() : variableSpecification() {} 
 
                    boost::asn1::value_holder<VariableSpecification> variableSpecification;
                    boost::shared_ptr<AlternateAccess> alternateAccess;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(AlternateAccess, alternateAccess)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 
        typedef std::vector< listOfVariable_type_sequence_of> listOfVariable_type;


            GetNamedVariableListAttributes_Response() : mmsDeletable(), listOfVariable() {} 
 
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::asn1::value_holder<listOfVariable_type> listOfVariable;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteNamedVariableList-Request
        struct DeleteNamedVariableList_Request{

        typedef std::vector< ObjectName> listOfVariableListName_type;

            static const int scopeOfDelete_specific;
            static const int scopeOfDelete_aa_specific;
            static const int scopeOfDelete_domain;
            static const int scopeOfDelete_vmd;


            DeleteNamedVariableList_Request() {} 
 
            boost::shared_ptr<int> scopeOfDelete;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, scopeOfDelete)

            boost::shared_ptr<listOfVariableListName_type> listOfVariableListName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfVariableListName_type, listOfVariableListName)

            boost::shared_ptr<Identifier> domainName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, domainName)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteNamedVariableList-Response
        struct DeleteNamedVariableList_Response{



            DeleteNamedVariableList_Response() : numberMatched(), numberDeleted() {} 
 
            boost::asn1::value_holder<Unsigned32> numberMatched;
            boost::asn1::value_holder<Unsigned32> numberDeleted;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineNamedType-Request
        struct DefineNamedType_Request{



            DefineNamedType_Request() : typeName(), typeSpecification() {} 
 
            boost::asn1::value_holder<ObjectName> typeName;
            boost::asn1::value_holder<TypeSpecification> typeSpecification;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetNamedTypeAttributes-Response
        struct GetNamedTypeAttributes_Response{



            GetNamedTypeAttributes_Response() : mmsDeletable(), typeSpecification() {} 
 
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::asn1::value_holder<TypeSpecification> typeSpecification;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)

            boost::shared_ptr<visiblestring_type> meaning;
            BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, meaning)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteNamedType-Request
        struct DeleteNamedType_Request{

        typedef std::vector< ObjectName> listOfTypeName_type;

            static const int scopeOfDelete_specific;
            static const int scopeOfDelete_aa_specific;
            static const int scopeOfDelete_domain;
            static const int scopeOfDelete_vmd;


            DeleteNamedType_Request() {} 
 
            boost::shared_ptr<int> scopeOfDelete;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, scopeOfDelete)

            boost::shared_ptr<listOfTypeName_type> listOfTypeName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfTypeName_type, listOfTypeName)

            boost::shared_ptr<Identifier> domainName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, domainName)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteNamedType-Response
        struct DeleteNamedType_Response{



            DeleteNamedType_Response() : numberMatched(), numberDeleted() {} 
 
            boost::asn1::value_holder<Unsigned32> numberMatched;
            boost::asn1::value_holder<Unsigned32> numberDeleted;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ExchangeData-Request
        struct ExchangeData_Request{

        typedef std::vector< Data> listOfRequestData_type;


            ExchangeData_Request() : dataExchangeName(), listOfRequestData() {} 
 
            boost::asn1::value_holder<ObjectName> dataExchangeName;
            boost::asn1::value_holder<listOfRequestData_type> listOfRequestData;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ExchangeData-Response
        struct ExchangeData_Response{

        typedef std::vector< Data> listOfResponseData_type;


            ExchangeData_Response() : listOfResponseData() {} 
 
            boost::asn1::value_holder<listOfResponseData_type> listOfResponseData;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetDataExchangeAttributes-Response
        struct GetDataExchangeAttributes_Response{

        typedef std::vector< MMS_Object_Module_1::TypeDescription> listOfRequestTypeDescriptions_type;
        typedef std::vector< MMS_Object_Module_1::TypeDescription> listOfResponseTypeDescriptions_type;


            GetDataExchangeAttributes_Response() : inUse(), listOfRequestTypeDescriptions(), listOfResponseTypeDescriptions() {} 
 
            boost::asn1::value_holder<bool> inUse;
            boost::asn1::value_holder<listOfRequestTypeDescriptions_type> listOfRequestTypeDescriptions;
            boost::asn1::value_holder<listOfResponseTypeDescriptions_type> listOfResponseTypeDescriptions;
            boost::shared_ptr<Identifier> programInvocation;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, programInvocation)

            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence TakeControl-Request
        struct TakeControl_Request{



            TakeControl_Request() : semaphoreName() {} 
 
            boost::asn1::value_holder<ObjectName> semaphoreName;
            boost::shared_ptr<Identifier> namedToken;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, namedToken)

            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)

            boost::shared_ptr<Unsigned32> acceptableDelay;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, acceptableDelay)

            boost::shared_ptr<Unsigned32> controlTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, controlTimeOut)

            boost::shared_ptr<bool> abortOnTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, abortOnTimeOut)

            boost::shared_ptr<bool> relinquishIfConnectionLost;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, relinquishIfConnectionLost)

            boost::shared_ptr<MMS_Environment_1::ApplicationReference> applicationToPreempt;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, applicationToPreempt)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice TakeControl-Response
        enum TakeControl_Response_enum {
            TakeControl_Response_null = 0, 
            TakeControl_Response_noResult,
            TakeControl_Response_namedToken,}; 
 
        struct TakeControl_Response : public BOOST_ASN_CHOICE_STRUCT(TakeControl_Response_enum) {



            TakeControl_Response() :  BOOST_ASN_CHOICE_STRUCT(TakeControl_Response_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(noResult, null_type, TakeControl_Response_noResult);
            BOOST_ASN_VALUE_CHOICE(namedToken, Identifier, TakeControl_Response_namedToken);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence RelinquishControl-Request
        struct RelinquishControl_Request{



            RelinquishControl_Request() : semaphoreName() {} 
 
            boost::asn1::value_holder<ObjectName> semaphoreName;
            boost::shared_ptr<Identifier> namedToken;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, namedToken)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineSemaphore-Request
        struct DefineSemaphore_Request{



            DefineSemaphore_Request() : semaphoreName(), numberOfTokens() {} 
 
            boost::asn1::value_holder<ObjectName> semaphoreName;
            boost::asn1::value_holder<Unsigned16> numberOfTokens;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportSemaphoreStatus-Response
        struct ReportSemaphoreStatus_Response{


            static const int classV_token;
            static const int classV_pool;


            ReportSemaphoreStatus_Response() : mmsDeletable(), classV(), numberOfTokens(), numberOfOwnedTokens(), numberOfHungTokens() {} 
 
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::asn1::value_holder<int> classV;
            boost::asn1::value_holder<Unsigned16> numberOfTokens;
            boost::asn1::value_holder<Unsigned16> numberOfOwnedTokens;
            boost::asn1::value_holder<Unsigned16> numberOfHungTokens;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportPoolSemaphoreStatus-Request
        struct ReportPoolSemaphoreStatus_Request{



            ReportPoolSemaphoreStatus_Request() : semaphoreName() {} 
 
            boost::asn1::value_holder<ObjectName> semaphoreName;
            boost::shared_ptr<Identifier> nameToStartAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, nameToStartAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportPoolSemaphoreStatus-Response
        struct ReportPoolSemaphoreStatus_Response{
        struct listOfNamedTokens_type_sequence_of;


                enum listOfNamedTokens_type_sequence_of_enum {
                    listOfNamedTokens_type_sequence_of_null = 0, 
                    listOfNamedTokens_type_sequence_of_freeNamedToken,
                    listOfNamedTokens_type_sequence_of_ownedNamedToken,
                    listOfNamedTokens_type_sequence_of_hungNamedToken,}; 
 
                struct listOfNamedTokens_type_sequence_of : public BOOST_ASN_CHOICE_STRUCT(listOfNamedTokens_type_sequence_of_enum) {



                    listOfNamedTokens_type_sequence_of() :  BOOST_ASN_CHOICE_STRUCT(listOfNamedTokens_type_sequence_of_enum) () {}
 
                    BOOST_ASN_VALUE_CHOICE(freeNamedToken, Identifier, listOfNamedTokens_type_sequence_of_freeNamedToken);
                    BOOST_ASN_VALUE_CHOICE(ownedNamedToken, Identifier, listOfNamedTokens_type_sequence_of_ownedNamedToken);
                    BOOST_ASN_VALUE_CHOICE(hungNamedToken, Identifier, listOfNamedTokens_type_sequence_of_hungNamedToken);

                    BOOST_ASN_ARCHIVE_FUNC;
                }; 
 
        typedef std::vector< listOfNamedTokens_type_sequence_of> listOfNamedTokens_type;


            ReportPoolSemaphoreStatus_Response() : listOfNamedTokens() {} 
 
            boost::asn1::value_holder<listOfNamedTokens_type> listOfNamedTokens;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportSemaphoreEntryStatus-Request
        struct ReportSemaphoreEntryStatus_Request{


            static const int state_queued;
            static const int state_owner;
            static const int state_hung;


            ReportSemaphoreEntryStatus_Request() : semaphoreName(), state() {} 
 
            boost::asn1::value_holder<ObjectName> semaphoreName;
            boost::asn1::value_holder<int> state;
            boost::shared_ptr<octetstring_type> entryIDToStartAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(octetstring_type, entryIDToStartAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportSemaphoreEntryStatus-Response
        struct ReportSemaphoreEntryStatus_Response{

        typedef std::vector< SemaphoreEntry> listOfSemaphoreEntry_type;


            ReportSemaphoreEntryStatus_Response() : listOfSemaphoreEntry() {} 
 
            boost::asn1::value_holder<listOfSemaphoreEntry_type> listOfSemaphoreEntry;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence SemaphoreEntry
        struct SemaphoreEntry{


            static const int entryClass_simple;
            static const int entryClass_modifier;


            SemaphoreEntry() : entryID(), entryClass(), applicationReference() {} 
 
            boost::asn1::value_holder<octetstring_type> entryID;
            boost::asn1::value_holder<int> entryClass;
            boost::asn1::value_holder<MMS_Environment_1::ApplicationReference> applicationReference;
            boost::shared_ptr<Identifier> namedToken;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, namedToken)

            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)

            boost::shared_ptr<Unsigned32> remainingTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, remainingTimeOut)

            boost::shared_ptr<bool> abortOnTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, abortOnTimeOut)

            boost::shared_ptr<bool> relinquishIfConnectionLost;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, relinquishIfConnectionLost)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AttachToSemaphore
        struct AttachToSemaphore{



            AttachToSemaphore() : semaphoreName() {} 
 
            boost::asn1::value_holder<ObjectName> semaphoreName;
            boost::shared_ptr<Identifier> namedToken;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, namedToken)

            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)

            boost::shared_ptr<Unsigned32> acceptableDelay;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, acceptableDelay)

            boost::shared_ptr<Unsigned32> controlTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, controlTimeOut)

            boost::shared_ptr<bool> abortOnTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, abortOnTimeOut)

            boost::shared_ptr<bool> relinquishIfConnectionLost;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, relinquishIfConnectionLost)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Input-Request
        struct Input_Request{

        typedef std::vector< MMSString> listOfPromptData_type;


            Input_Request() : operatorStationName() {} 
 
            boost::asn1::value_holder<Identifier> operatorStationName;
            boost::shared_ptr<bool> echo;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, echo)

            boost::shared_ptr<listOfPromptData_type> listOfPromptData;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfPromptData_type, listOfPromptData)

            boost::shared_ptr<Unsigned32> inputTimeOut;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, inputTimeOut)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Output-Request
        struct Output_Request{

        typedef std::vector< MMSString> listOfOutputData_type;


            Output_Request() : operatorStationName(), listOfOutputData() {} 
 
            boost::asn1::value_holder<Identifier> operatorStationName;
            boost::asn1::value_holder<listOfOutputData_type> listOfOutputData;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence TriggerEvent-Request
        struct TriggerEvent_Request{



            TriggerEvent_Request() : eventConditionName() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence EventNotification
        struct EventNotification{


            struct actionResult_type{


                enum successOrFailure_type_enum {
                    successOrFailure_type_null = 0, 
                    successOrFailure_type_success,
                    successOrFailure_type_failure,}; 
 
                struct successOrFailure_type : public BOOST_ASN_CHOICE_STRUCT(successOrFailure_type_enum) {


                    struct success_type{



                        success_type() : confirmedServiceResponse() {} 
 
                        boost::asn1::value_holder<ConfirmedServiceResponse> confirmedServiceResponse;
                        boost::shared_ptr<Response_Detail> cs_Response_Detail;
                        BOOST_ASN_VALUE_FUNC_DECLARATE(Response_Detail, cs_Response_Detail)


                        BOOST_ASN_ARCHIVE_FUNC;
                    };
 

                    struct failure_type{



                        failure_type() : serviceError() {} 
 
                        boost::shared_ptr<Unsigned32> modifierPosition;
                        BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, modifierPosition)

                        boost::asn1::value_holder<ServiceError> serviceError;

                        BOOST_ASN_ARCHIVE_FUNC;
                    };
 


                    successOrFailure_type() :  BOOST_ASN_CHOICE_STRUCT(successOrFailure_type_enum) () {}
 
                    BOOST_ASN_VALUE_CHOICE(success, success_type, successOrFailure_type_success);
                    BOOST_ASN_VALUE_CHOICE(failure, failure_type, successOrFailure_type_failure);

                    BOOST_ASN_ARCHIVE_FUNC;
                }; 
 


                actionResult_type() : eventActionName(), successOrFailure() {} 
 
                boost::asn1::value_holder<ObjectName> eventActionName;
                boost::asn1::value_holder<successOrFailure_type> successOrFailure;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            EventNotification() : eventEnrollmentName(), eventConditionName(), severity(), transitionTime() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::asn1::value_holder<MMS_Object_Module_1::Severity> severity;
            boost::shared_ptr<MMS_Object_Module_1::EC_State> currentState;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EC_State, currentState)

            boost::asn1::value_holder<MMS_Object_Module_1::EventTime> transitionTime;
            boost::shared_ptr<bool> notificationLost;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, notificationLost)

            boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> alarmAcknowledgmentRule;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AlarmAckRule, alarmAcknowledgmentRule)

            boost::shared_ptr<actionResult_type> actionResult;
            BOOST_ASN_VALUE_FUNC_DECLARATE(actionResult_type, actionResult)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice CS-EventNotification
        enum CS_EventNotification_impl_enum {
            CS_EventNotification_impl_null = 0, 
            CS_EventNotification_impl_string,
            CS_EventNotification_impl_index,
            CS_EventNotification_impl_noEnhancement,}; 
 
        struct CS_EventNotification_impl : public BOOST_ASN_CHOICE_STRUCT(CS_EventNotification_impl_enum) {



            CS_EventNotification_impl() :  BOOST_ASN_CHOICE_STRUCT(CS_EventNotification_impl_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, CS_EventNotification_impl_string);
            BOOST_ASN_VALUE_CHOICE(index, int, CS_EventNotification_impl_index);
            BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, CS_EventNotification_impl_noEnhancement);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence AcknowledgeEventNotification-Request
        struct AcknowledgeEventNotification_Request{



            AcknowledgeEventNotification_Request() : eventEnrollmentName(), acknowledgedState(), timeOfAcknowledgedTransition() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::asn1::value_holder<MMS_Object_Module_1::EC_State> acknowledgedState;
            boost::asn1::value_holder<MMS_Object_Module_1::EventTime> timeOfAcknowledgedTransition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetAlarmSummary-Request
        struct GetAlarmSummary_Request{


            struct severityFilter_type{



                severityFilter_type() : mostSevere(), leastSevere() {} 
 
                boost::asn1::value_holder<Unsigned8> mostSevere;
                boost::asn1::value_holder<Unsigned8> leastSevere;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            static const int acknowledgementFilter_not_acked;
            static const int acknowledgementFilter_acked;
            static const int acknowledgementFilter_all;


            GetAlarmSummary_Request() {} 
 
            boost::shared_ptr<bool> enrollmentsOnly;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, enrollmentsOnly)

            boost::shared_ptr<bool> activeAlarmsOnly;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, activeAlarmsOnly)

            boost::shared_ptr<int> acknowledgementFilter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, acknowledgementFilter)

            boost::shared_ptr<severityFilter_type> severityFilter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(severityFilter_type, severityFilter)

            boost::shared_ptr<ObjectName> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetAlarmSummary-Response
        struct GetAlarmSummary_Response{

        typedef std::vector< AlarmSummary> listOfAlarmSummary_type;


            GetAlarmSummary_Response() : listOfAlarmSummary() {} 
 
            boost::asn1::value_holder<listOfAlarmSummary_type> listOfAlarmSummary;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlarmSummary
        struct AlarmSummary{


            static const int unacknowledgedState_none;
            static const int unacknowledgedState_active;
            static const int unacknowledgedState_idle;
            static const int unacknowledgedState_both;


            AlarmSummary() : eventConditionName(), severity(), currentState(), unacknowledgedState() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::asn1::value_holder<Unsigned8> severity;
            boost::asn1::value_holder<MMS_Object_Module_1::EC_State> currentState;
            boost::asn1::value_holder<int> unacknowledgedState;
            boost::shared_ptr<EN_Additional_Detail> displayEnhancement;
            BOOST_ASN_VALUE_FUNC_DECLARATE(EN_Additional_Detail, displayEnhancement)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToActive;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToActive)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToIdle;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToIdle)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice EN-Additional-Detail
        enum EN_Additional_Detail_impl_enum {
            EN_Additional_Detail_impl_null = 0, 
            EN_Additional_Detail_impl_string,
            EN_Additional_Detail_impl_index,
            EN_Additional_Detail_impl_noEnhancement,}; 
 
        struct EN_Additional_Detail_impl : public BOOST_ASN_CHOICE_STRUCT(EN_Additional_Detail_impl_enum) {



            EN_Additional_Detail_impl() :  BOOST_ASN_CHOICE_STRUCT(EN_Additional_Detail_impl_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, EN_Additional_Detail_impl_string);
            BOOST_ASN_VALUE_CHOICE(index, int, EN_Additional_Detail_impl_index);
            BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, EN_Additional_Detail_impl_noEnhancement);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetAlarmEnrollmentSummary-Request
        struct GetAlarmEnrollmentSummary_Request{


            struct severityFilter_type{



                severityFilter_type() : mostSevere(), leastSevere() {} 
 
                boost::asn1::value_holder<Unsigned8> mostSevere;
                boost::asn1::value_holder<Unsigned8> leastSevere;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            static const int acknowledgementFilter_not_acked;
            static const int acknowledgementFilter_acked;
            static const int acknowledgementFilter_all;


            GetAlarmEnrollmentSummary_Request() {} 
 
            boost::shared_ptr<bool> enrollmentsOnly;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, enrollmentsOnly)

            boost::shared_ptr<bool> activeAlarmsOnly;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, activeAlarmsOnly)

            boost::shared_ptr<int> acknowledgementFilter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, acknowledgementFilter)

            boost::shared_ptr<severityFilter_type> severityFilter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(severityFilter_type, severityFilter)

            boost::shared_ptr<ObjectName> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetAlarmEnrollmentSummary-Response
        struct GetAlarmEnrollmentSummary_Response{

        typedef std::vector< AlarmEnrollmentSummary> listOfAlarmEnrollmentSummary_type;


            GetAlarmEnrollmentSummary_Response() : listOfAlarmEnrollmentSummary() {} 
 
            boost::asn1::value_holder<listOfAlarmEnrollmentSummary_type> listOfAlarmEnrollmentSummary;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlarmEnrollmentSummary
        struct AlarmEnrollmentSummary{



            AlarmEnrollmentSummary() : eventEnrollmentName(), severity(), currentState(), alarmAcknowledgmentRule() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::shared_ptr<MMS_Environment_1::ApplicationReference> clientApplication;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, clientApplication)

            boost::asn1::value_holder<Unsigned8> severity;
            boost::asn1::value_holder<MMS_Object_Module_1::EC_State> currentState;
            boost::shared_ptr<EN_Additional_Detail> displayEnhancement;
            BOOST_ASN_VALUE_FUNC_DECLARATE(EN_Additional_Detail, displayEnhancement)

            boost::shared_ptr<bool> notificationLost;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, notificationLost)

            boost::asn1::value_holder<MMS_Object_Module_1::AlarmAckRule> alarmAcknowledgmentRule;
            boost::shared_ptr<EE_State> enrollmentState;
            BOOST_ASN_VALUE_FUNC_DECLARATE(EE_State, enrollmentState)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToActive;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToActive)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeActiveAcknowledged;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeActiveAcknowledged)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToIdle;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToIdle)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeIdleAcknowledged;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeIdleAcknowledged)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AttachToEventCondition
        struct AttachToEventCondition{



            AttachToEventCondition() : eventEnrollmentName(), eventConditionName(), causingTransitions() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::asn1::value_holder<MMS_Object_Module_1::Transitions> causingTransitions;
            boost::shared_ptr<Unsigned32> acceptableDelay;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, acceptableDelay)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineEventCondition-Request
        struct DefineEventCondition_Request{



            DefineEventCondition_Request() : eventConditionName(), classV() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::asn1::value_holder<MMS_Object_Module_1::EC_Class> classV;
            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)

            boost::shared_ptr<Unsigned8> severity;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned8, severity)

            boost::shared_ptr<bool> alarmSummaryReports;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, alarmSummaryReports)

            boost::shared_ptr<VariableSpecification> monitoredVariable;
            BOOST_ASN_VALUE_FUNC_DECLARATE(VariableSpecification, monitoredVariable)

            boost::shared_ptr<Unsigned32> evaluationInterval;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, evaluationInterval)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice CS-DefineEventCondition-Request
        enum CS_DefineEventCondition_Request_impl_enum {
            CS_DefineEventCondition_Request_impl_null = 0, 
            CS_DefineEventCondition_Request_impl_string,
            CS_DefineEventCondition_Request_impl_index,
            CS_DefineEventCondition_Request_impl_noEnhancement,}; 
 
        struct CS_DefineEventCondition_Request_impl : public BOOST_ASN_CHOICE_STRUCT(CS_DefineEventCondition_Request_impl_enum) {



            CS_DefineEventCondition_Request_impl() :  BOOST_ASN_CHOICE_STRUCT(CS_DefineEventCondition_Request_impl_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, CS_DefineEventCondition_Request_impl_string);
            BOOST_ASN_VALUE_CHOICE(index, int, CS_DefineEventCondition_Request_impl_index);
            BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, CS_DefineEventCondition_Request_impl_noEnhancement);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice DeleteEventCondition-Request
        enum DeleteEventCondition_Request_enum {
            DeleteEventCondition_Request_null = 0, 
            DeleteEventCondition_Request_specific,
            DeleteEventCondition_Request_aa_specific,
            DeleteEventCondition_Request_domain,
            DeleteEventCondition_Request_vmd,}; 
 
        struct DeleteEventCondition_Request : public BOOST_ASN_CHOICE_STRUCT(DeleteEventCondition_Request_enum) {

        typedef std::vector< ObjectName> specific_type;


            DeleteEventCondition_Request() :  BOOST_ASN_CHOICE_STRUCT(DeleteEventCondition_Request_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(specific, specific_type, DeleteEventCondition_Request_specific);
            BOOST_ASN_VALUE_CHOICE(aa_specific, null_type, DeleteEventCondition_Request_aa_specific);
            BOOST_ASN_VALUE_CHOICE(domain, Identifier, DeleteEventCondition_Request_domain);
            BOOST_ASN_VALUE_CHOICE(vmd, null_type, DeleteEventCondition_Request_vmd);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetEventConditionAttributes-Response
        struct GetEventConditionAttributes_Response{


            enum monitoredVariable_type_enum {
                monitoredVariable_type_null = 0, 
                monitoredVariable_type_variableReference,
                monitoredVariable_type_undefined,}; 
 
            struct monitoredVariable_type : public BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) {



                monitoredVariable_type() :  BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(variableReference, VariableSpecification, monitoredVariable_type_variableReference);
                BOOST_ASN_VALUE_CHOICE(undefined, null_type, monitoredVariable_type_undefined);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            GetEventConditionAttributes_Response() : classV() {} 
 
            boost::shared_ptr<bool> mmsDeletable;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, mmsDeletable)

            boost::asn1::value_holder<MMS_Object_Module_1::EC_Class> classV;
            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)

            boost::shared_ptr<Unsigned8> severity;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned8, severity)

            boost::shared_ptr<bool> alarmSummaryReports;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, alarmSummaryReports)

            boost::shared_ptr<monitoredVariable_type> monitoredVariable;
            BOOST_ASN_VALUE_FUNC_DECLARATE(monitoredVariable_type, monitoredVariable)

            boost::shared_ptr<Unsigned32> evaluationInterval;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, evaluationInterval)

            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CS-GetEventConditionAttributes-Response
        struct CS_GetEventConditionAttributes_Response{


            enum groupPriorityOverride_type_enum {
                groupPriorityOverride_type_null = 0, 
                groupPriorityOverride_type_priority,
                groupPriorityOverride_type_undefined,}; 
 
            struct groupPriorityOverride_type : public BOOST_ASN_CHOICE_STRUCT(groupPriorityOverride_type_enum) {



                groupPriorityOverride_type() :  BOOST_ASN_CHOICE_STRUCT(groupPriorityOverride_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(priority, MMS_Object_Module_1::Priority, groupPriorityOverride_type_priority);
                BOOST_ASN_VALUE_CHOICE(undefined, null_type, groupPriorityOverride_type_undefined);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 

            enum displayEnhancement_type_enum {
                displayEnhancement_type_null = 0, 
                displayEnhancement_type_string,
                displayEnhancement_type_index,
                displayEnhancement_type_noEnhancement,}; 
 
            struct displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {



                displayEnhancement_type() :  BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, displayEnhancement_type_string);
                BOOST_ASN_VALUE_CHOICE(index, int, displayEnhancement_type_index);
                BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, displayEnhancement_type_noEnhancement);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        typedef std::vector< ObjectName> listOfReferencingECL_type;


            CS_GetEventConditionAttributes_Response() : displayEnhancement() {} 
 
            boost::shared_ptr<groupPriorityOverride_type> groupPriorityOverride;
            BOOST_ASN_VALUE_FUNC_DECLARATE(groupPriorityOverride_type, groupPriorityOverride)

            boost::shared_ptr<listOfReferencingECL_type> listOfReferencingECL;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfReferencingECL_type, listOfReferencingECL)

            boost::asn1::value_holder<displayEnhancement_type> displayEnhancement;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportEventConditionStatus-Response
        struct ReportEventConditionStatus_Response{



            ReportEventConditionStatus_Response() : currentState(), numberOfEventEnrollments() {} 
 
            boost::asn1::value_holder<MMS_Object_Module_1::EC_State> currentState;
            boost::asn1::value_holder<Unsigned32> numberOfEventEnrollments;
            boost::shared_ptr<bool> enabled;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, enabled)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToActive;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToActive)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToIdle;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToIdle)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlterEventConditionMonitoring-Request
        struct AlterEventConditionMonitoring_Request{



            AlterEventConditionMonitoring_Request() : eventConditionName() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::shared_ptr<bool> enabled;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, enabled)

            boost::shared_ptr<MMS_Object_Module_1::Priority> priority;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Priority, priority)

            boost::shared_ptr<bool> alarmSummaryReports;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, alarmSummaryReports)

            boost::shared_ptr<Unsigned32> evaluationInterval;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, evaluationInterval)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CS-AlterEventConditionMonitoring-Request
        struct CS_AlterEventConditionMonitoring_Request{


            enum changeDisplay_type_enum {
                changeDisplay_type_null = 0, 
                changeDisplay_type_string,
                changeDisplay_type_index,
                changeDisplay_type_noEnhancement,}; 
 
            struct changeDisplay_type : public BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) {



                changeDisplay_type() :  BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, changeDisplay_type_string);
                BOOST_ASN_VALUE_CHOICE(index, int, changeDisplay_type_index);
                BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, changeDisplay_type_noEnhancement);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            CS_AlterEventConditionMonitoring_Request() {} 
 
            boost::asn1::value_holder<changeDisplay_type> changeDisplay;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineEventAction-Request
        struct DefineEventAction_Request{

        typedef std::vector< MMS_Object_Module_1::Modifier> listOfModifier_type;


            DefineEventAction_Request() : eventActionName(), confirmedServiceRequest() {} 
 
            boost::asn1::value_holder<ObjectName> eventActionName;
            boost::shared_ptr<listOfModifier_type> listOfModifier;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfModifier_type, listOfModifier)

            boost::asn1::value_holder<ConfirmedServiceRequest> confirmedServiceRequest;
            boost::shared_ptr<Request_Detail> cs_extension;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Request_Detail, cs_extension)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice DeleteEventAction-Request
        enum DeleteEventAction_Request_enum {
            DeleteEventAction_Request_null = 0, 
            DeleteEventAction_Request_specific,
            DeleteEventAction_Request_aa_specific,
            DeleteEventAction_Request_domain,
            DeleteEventAction_Request_vmd,}; 
 
        struct DeleteEventAction_Request : public BOOST_ASN_CHOICE_STRUCT(DeleteEventAction_Request_enum) {

        typedef std::vector< ObjectName> specific_type;


            DeleteEventAction_Request() :  BOOST_ASN_CHOICE_STRUCT(DeleteEventAction_Request_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(specific, specific_type, DeleteEventAction_Request_specific);
            BOOST_ASN_VALUE_CHOICE(aa_specific, null_type, DeleteEventAction_Request_aa_specific);
            BOOST_ASN_VALUE_CHOICE(domain, Identifier, DeleteEventAction_Request_domain);
            BOOST_ASN_VALUE_CHOICE(vmd, null_type, DeleteEventAction_Request_vmd);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetEventActionAttributes-Response
        struct GetEventActionAttributes_Response{

        typedef std::vector< MMS_Object_Module_1::Modifier> listOfModifier_type;


            GetEventActionAttributes_Response() : listOfModifier(), confirmedServiceRequest() {} 
 
            boost::shared_ptr<bool> mmsDeletable;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, mmsDeletable)

            boost::asn1::value_holder<listOfModifier_type> listOfModifier;
            boost::asn1::value_holder<ConfirmedServiceRequest> confirmedServiceRequest;
            boost::shared_ptr<Request_Detail> cs_extension;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Request_Detail, cs_extension)

            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DefineEventEnrollment-Request
        struct DefineEventEnrollment_Request{



            DefineEventEnrollment_Request() : eventEnrollmentName(), eventConditionName(), eventConditionTransitions(), alarmAcknowledgmentRule() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::asn1::value_holder<MMS_Object_Module_1::Transitions> eventConditionTransitions;
            boost::asn1::value_holder<MMS_Object_Module_1::AlarmAckRule> alarmAcknowledgmentRule;
            boost::shared_ptr<ObjectName> eventActionName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, eventActionName)

            boost::shared_ptr<MMS_Environment_1::ApplicationReference> clientApplication;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, clientApplication)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice CS-DefineEventEnrollment-Request
        enum CS_DefineEventEnrollment_Request_impl_enum {
            CS_DefineEventEnrollment_Request_impl_null = 0, 
            CS_DefineEventEnrollment_Request_impl_string,
            CS_DefineEventEnrollment_Request_impl_index,
            CS_DefineEventEnrollment_Request_impl_noEnhancement,}; 
 
        struct CS_DefineEventEnrollment_Request_impl : public BOOST_ASN_CHOICE_STRUCT(CS_DefineEventEnrollment_Request_impl_enum) {



            CS_DefineEventEnrollment_Request_impl() :  BOOST_ASN_CHOICE_STRUCT(CS_DefineEventEnrollment_Request_impl_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, CS_DefineEventEnrollment_Request_impl_string);
            BOOST_ASN_VALUE_CHOICE(index, int, CS_DefineEventEnrollment_Request_impl_index);
            BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, CS_DefineEventEnrollment_Request_impl_noEnhancement);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // choice DeleteEventEnrollment-Request
        enum DeleteEventEnrollment_Request_enum {
            DeleteEventEnrollment_Request_null = 0, 
            DeleteEventEnrollment_Request_specific,
            DeleteEventEnrollment_Request_ec,
            DeleteEventEnrollment_Request_ea,}; 
 
        struct DeleteEventEnrollment_Request : public BOOST_ASN_CHOICE_STRUCT(DeleteEventEnrollment_Request_enum) {

        typedef std::vector< ObjectName> specific_type;


            DeleteEventEnrollment_Request() :  BOOST_ASN_CHOICE_STRUCT(DeleteEventEnrollment_Request_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(specific, specific_type, DeleteEventEnrollment_Request_specific);
            BOOST_ASN_VALUE_CHOICE(ec, ObjectName, DeleteEventEnrollment_Request_ec);
            BOOST_ASN_VALUE_CHOICE(ea, ObjectName, DeleteEventEnrollment_Request_ea);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetEventEnrollmentAttributes-Request
        struct GetEventEnrollmentAttributes_Request{

        typedef std::vector< ObjectName> eventEnrollmentNames_type;

            static const int scopeOfRequest_specific;
            static const int scopeOfRequest_client;
            static const int scopeOfRequest_ec;
            static const int scopeOfRequest_ea;


            GetEventEnrollmentAttributes_Request() {} 
 
            boost::shared_ptr<int> scopeOfRequest;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, scopeOfRequest)

            boost::shared_ptr<eventEnrollmentNames_type> eventEnrollmentNames;
            BOOST_ASN_VALUE_FUNC_DECLARATE(eventEnrollmentNames_type, eventEnrollmentNames)

            boost::shared_ptr<MMS_Environment_1::ApplicationReference> clientApplication;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, clientApplication)

            boost::shared_ptr<ObjectName> eventConditionName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, eventConditionName)

            boost::shared_ptr<ObjectName> eventActionName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, eventActionName)

            boost::shared_ptr<ObjectName> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ObjectName, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetEventEnrollmentAttributes-Response
        struct GetEventEnrollmentAttributes_Response{

        typedef std::vector< EEAttributes> listOfEEAttributes_type;


            GetEventEnrollmentAttributes_Response() : listOfEEAttributes() {} 
 
            boost::asn1::value_holder<listOfEEAttributes_type> listOfEEAttributes;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence EEAttributes
        struct EEAttributes{


            enum eventConditionName_type_enum {
                eventConditionName_type_null = 0, 
                eventConditionName_type_eventCondition,
                eventConditionName_type_undefined,}; 
 
            struct eventConditionName_type : public BOOST_ASN_CHOICE_STRUCT(eventConditionName_type_enum) {



                eventConditionName_type() :  BOOST_ASN_CHOICE_STRUCT(eventConditionName_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(eventCondition, ObjectName, eventConditionName_type_eventCondition);
                BOOST_ASN_VALUE_CHOICE(undefined, null_type, eventConditionName_type_undefined);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 

            enum eventActionName_type_enum {
                eventActionName_type_null = 0, 
                eventActionName_type_eventAction,
                eventActionName_type_undefined,}; 
 
            struct eventActionName_type : public BOOST_ASN_CHOICE_STRUCT(eventActionName_type_enum) {



                eventActionName_type() :  BOOST_ASN_CHOICE_STRUCT(eventActionName_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(eventAction, ObjectName, eventActionName_type_eventAction);
                BOOST_ASN_VALUE_CHOICE(undefined, null_type, eventActionName_type_undefined);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 

            enum displayEnhancement_type_enum {
                displayEnhancement_type_null = 0, 
                displayEnhancement_type_string,
                displayEnhancement_type_index,
                displayEnhancement_type_noEnhancement,}; 
 
            struct displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {



                displayEnhancement_type() :  BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, displayEnhancement_type_string);
                BOOST_ASN_VALUE_CHOICE(index, int, displayEnhancement_type_index);
                BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, displayEnhancement_type_noEnhancement);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            EEAttributes() : eventEnrollmentName(), eventConditionName(), enrollmentClass(), displayEnhancement() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::asn1::value_holder<eventConditionName_type> eventConditionName;
            boost::shared_ptr<eventActionName_type> eventActionName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(eventActionName_type, eventActionName)

            boost::shared_ptr<MMS_Environment_1::ApplicationReference> clientApplication;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, clientApplication)

            boost::shared_ptr<bool> mmsDeletable;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, mmsDeletable)

            boost::asn1::value_holder<MMS_Object_Module_1::EE_Class> enrollmentClass;
            boost::shared_ptr<MMS_Object_Module_1::EE_Duration> duration;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EE_Duration, duration)

            boost::shared_ptr<Unsigned32> invokeID;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, invokeID)

            boost::shared_ptr<Unsigned32> remainingAcceptableDelay;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unsigned32, remainingAcceptableDelay)

            boost::asn1::value_holder<displayEnhancement_type> displayEnhancement;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportEventEnrollmentStatus-Response
        struct ReportEventEnrollmentStatus_Response{



            ReportEventEnrollmentStatus_Response() : eventConditionTransitions(), duration(), currentState() {} 
 
            boost::asn1::value_holder<MMS_Object_Module_1::Transitions> eventConditionTransitions;
            boost::shared_ptr<bool> notificationLost;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, notificationLost)

            boost::asn1::value_holder<MMS_Object_Module_1::EE_Duration> duration;
            boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> alarmAcknowledgmentRule;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AlarmAckRule, alarmAcknowledgmentRule)

            boost::asn1::value_holder<EE_State> currentState;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlterEventEnrollment-Request
        struct AlterEventEnrollment_Request{



            AlterEventEnrollment_Request() : eventEnrollmentName() {} 
 
            boost::asn1::value_holder<ObjectName> eventEnrollmentName;
            boost::shared_ptr<MMS_Object_Module_1::Transitions> eventConditionTransitions;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Transitions, eventConditionTransitions)

            boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> alarmAcknowledgmentRule;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AlarmAckRule, alarmAcknowledgmentRule)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlterEventEnrollment-Response
        struct AlterEventEnrollment_Response{


            enum currentState_type_enum {
                currentState_type_null = 0, 
                currentState_type_state,
                currentState_type_undefined,}; 
 
            struct currentState_type : public BOOST_ASN_CHOICE_STRUCT(currentState_type_enum) {



                currentState_type() :  BOOST_ASN_CHOICE_STRUCT(currentState_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(state, EE_State, currentState_type_state);
                BOOST_ASN_VALUE_CHOICE(undefined, null_type, currentState_type_undefined);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            AlterEventEnrollment_Response() : currentState(), transitionTime() {} 
 
            boost::asn1::value_holder<currentState_type> currentState;
            boost::asn1::value_holder<MMS_Object_Module_1::EventTime> transitionTime;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CS-AlterEventEnrollment-Request
        struct CS_AlterEventEnrollment_Request{


            enum changeDisplay_type_enum {
                changeDisplay_type_null = 0, 
                changeDisplay_type_string,
                changeDisplay_type_index,
                changeDisplay_type_noEnhancement,}; 
 
            struct changeDisplay_type : public BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) {



                changeDisplay_type() :  BOOST_ASN_CHOICE_STRUCT(changeDisplay_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(string, visiblestring_type, changeDisplay_type_string);
                BOOST_ASN_VALUE_CHOICE(index, int, changeDisplay_type_index);
                BOOST_ASN_VALUE_CHOICE(noEnhancement, null_type, changeDisplay_type_noEnhancement);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            CS_AlterEventEnrollment_Request() {} 
 
            boost::asn1::value_holder<changeDisplay_type> changeDisplay;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        extern const int EE_State_disabled;
        extern const int EE_State_idle;
        extern const int EE_State_active;
        extern const int EE_State_activeNoAckA;
        extern const int EE_State_idleNoAckI;
        extern const int EE_State_idleNoAckA;
        extern const int EE_State_idleAcked;
        extern const int EE_State_activeAcked;
        extern const int EE_State_undefined;

        // sequence DefineEventConditionList-Request
        struct DefineEventConditionList_Request{

        typedef std::vector< ObjectName> listOfEventConditionName_type;
        typedef std::vector< ObjectName> listOfEventConditionListName_type;


            DefineEventConditionList_Request() : eventConditionListName(), listOfEventConditionName() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionListName;
            boost::asn1::value_holder<listOfEventConditionName_type> listOfEventConditionName;
            boost::shared_ptr<listOfEventConditionListName_type> listOfEventConditionListName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfEventConditionListName_type, listOfEventConditionListName)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AddEventConditionListReference-Request
        struct AddEventConditionListReference_Request{

        typedef std::vector< ObjectName> listOfEventConditionName_type;
        typedef std::vector< ObjectName> listOfEventConditionListName_type;


            AddEventConditionListReference_Request() : eventConditionListName(), listOfEventConditionName() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionListName;
            boost::asn1::value_holder<listOfEventConditionName_type> listOfEventConditionName;
            boost::shared_ptr<listOfEventConditionListName_type> listOfEventConditionListName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfEventConditionListName_type, listOfEventConditionListName)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence RemoveEventConditionListReference-Request
        struct RemoveEventConditionListReference_Request{

        typedef std::vector< ObjectName> listOfEventConditionName_type;
        typedef std::vector< ObjectName> listOfEventConditionListName_type;


            RemoveEventConditionListReference_Request() : eventConditionListName(), listOfEventConditionName(), listOfEventConditionListName() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionListName;
            boost::asn1::value_holder<listOfEventConditionName_type> listOfEventConditionName;
            boost::asn1::value_holder<listOfEventConditionListName_type> listOfEventConditionListName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice RemoveEventConditionListReference-Error
        enum RemoveEventConditionListReference_Error_enum {
            RemoveEventConditionListReference_Error_null = 0, 
            RemoveEventConditionListReference_Error_eventCondition,
            RemoveEventConditionListReference_Error_eventConditionList,}; 
 
        struct RemoveEventConditionListReference_Error : public BOOST_ASN_CHOICE_STRUCT(RemoveEventConditionListReference_Error_enum) {



            RemoveEventConditionListReference_Error() :  BOOST_ASN_CHOICE_STRUCT(RemoveEventConditionListReference_Error_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(eventCondition, ObjectName, RemoveEventConditionListReference_Error_eventCondition);
            BOOST_ASN_VALUE_CHOICE(eventConditionList, ObjectName, RemoveEventConditionListReference_Error_eventConditionList);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        // sequence GetEventConditionListAttributes-Response
        struct GetEventConditionListAttributes_Response{

        typedef std::vector< ObjectName> listOfEventConditionName_type;
        typedef std::vector< ObjectName> listOfEventConditionListName_type;


            GetEventConditionListAttributes_Response() : listOfEventConditionName() {} 
 
            boost::asn1::value_holder<listOfEventConditionName_type> listOfEventConditionName;
            boost::shared_ptr<listOfEventConditionListName_type> listOfEventConditionListName;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfEventConditionListName_type, listOfEventConditionListName)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportEventConditionListStatus-Request
        struct ReportEventConditionListStatus_Request{



            ReportEventConditionListStatus_Request() : eventConditionListName() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionListName;
            boost::shared_ptr<Identifier> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportEventConditionListStatus-Response
        struct ReportEventConditionListStatus_Response{

        typedef std::vector< EventConditionStatus> listOfEventConditionStatus_type;


            ReportEventConditionListStatus_Response() : listOfEventConditionStatus() {} 
 
            boost::asn1::value_holder<listOfEventConditionStatus_type> listOfEventConditionStatus;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence EventConditionStatus
        struct EventConditionStatus{



            EventConditionStatus() : eventConditionName(), currentState(), numberOfEventEnrollments() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionName;
            boost::asn1::value_holder<MMS_Object_Module_1::EC_State> currentState;
            boost::asn1::value_holder<Unsigned32> numberOfEventEnrollments;
            boost::shared_ptr<bool> enabled;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, enabled)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToActive;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToActive)

            boost::shared_ptr<MMS_Object_Module_1::EventTime> timeOfLastTransitionToIdle;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EventTime, timeOfLastTransitionToIdle)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence AlterEventConditionListMonitoring-Request
        struct AlterEventConditionListMonitoring_Request{


            enum priorityChange_type_enum {
                priorityChange_type_null = 0, 
                priorityChange_type_priorityValue,
                priorityChange_type_priorityReset,}; 
 
            struct priorityChange_type : public BOOST_ASN_CHOICE_STRUCT(priorityChange_type_enum) {



                priorityChange_type() :  BOOST_ASN_CHOICE_STRUCT(priorityChange_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(priorityValue, int, priorityChange_type_priorityValue);
                BOOST_ASN_VALUE_CHOICE(priorityReset, null_type, priorityChange_type_priorityReset);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            AlterEventConditionListMonitoring_Request() : eventConditionListName(), enabled() {} 
 
            boost::asn1::value_holder<ObjectName> eventConditionListName;
            boost::asn1::value_holder<bool> enabled;
            boost::shared_ptr<priorityChange_type> priorityChange;
            BOOST_ASN_VALUE_FUNC_DECLARATE(priorityChange_type, priorityChange)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReadJournal-Request
        struct ReadJournal_Request{


            enum rangeStartSpecification_type_enum {
                rangeStartSpecification_type_null = 0, 
                rangeStartSpecification_type_startingTime,
                rangeStartSpecification_type_startingEntry,}; 
 
            struct rangeStartSpecification_type : public BOOST_ASN_CHOICE_STRUCT(rangeStartSpecification_type_enum) {



                rangeStartSpecification_type() :  BOOST_ASN_CHOICE_STRUCT(rangeStartSpecification_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(startingTime, TimeOfDay, rangeStartSpecification_type_startingTime);
                BOOST_ASN_VALUE_CHOICE(startingEntry, octetstring_type, rangeStartSpecification_type_startingEntry);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 

            enum rangeStopSpecification_type_enum {
                rangeStopSpecification_type_null = 0, 
                rangeStopSpecification_type_endingTime,
                rangeStopSpecification_type_numberOfEntries,}; 
 
            struct rangeStopSpecification_type : public BOOST_ASN_CHOICE_STRUCT(rangeStopSpecification_type_enum) {



                rangeStopSpecification_type() :  BOOST_ASN_CHOICE_STRUCT(rangeStopSpecification_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(endingTime, TimeOfDay, rangeStopSpecification_type_endingTime);
                BOOST_ASN_VALUE_CHOICE(numberOfEntries, Integer32, rangeStopSpecification_type_numberOfEntries);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 

            struct entryToStartAfter_type{



                entryToStartAfter_type() : timeSpecification(), entrySpecification() {} 
 
                boost::asn1::value_holder<TimeOfDay> timeSpecification;
                boost::asn1::value_holder<octetstring_type> entrySpecification;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 
        typedef std::vector< visiblestring_type> listOfVariables_type;


            ReadJournal_Request() : journalName() {} 
 
            boost::asn1::value_holder<ObjectName> journalName;
            boost::shared_ptr<rangeStartSpecification_type> rangeStartSpecification;
            BOOST_ASN_VALUE_FUNC_DECLARATE(rangeStartSpecification_type, rangeStartSpecification)

            boost::shared_ptr<rangeStopSpecification_type> rangeStopSpecification;
            BOOST_ASN_VALUE_FUNC_DECLARATE(rangeStopSpecification_type, rangeStopSpecification)

            boost::shared_ptr<listOfVariables_type> listOfVariables;
            BOOST_ASN_VALUE_FUNC_DECLARATE(listOfVariables_type, listOfVariables)

            boost::shared_ptr<entryToStartAfter_type> entryToStartAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(entryToStartAfter_type, entryToStartAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReadJournal-Response
        struct ReadJournal_Response{

        typedef std::vector< JournalEntry> listOfJournalEntry_type;


            ReadJournal_Response() : listOfJournalEntry() {} 
 
            boost::asn1::value_holder<listOfJournalEntry_type> listOfJournalEntry;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence JournalEntry
        struct JournalEntry{



            JournalEntry() : entryIdentifier(), originatingApplication(), entryContent() {} 
 
            boost::asn1::value_holder<octetstring_type> entryIdentifier;
            boost::asn1::value_holder<MMS_Environment_1::ApplicationReference> originatingApplication;
            boost::asn1::value_holder<EntryContent> entryContent;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence WriteJournal-Request
        struct WriteJournal_Request{

        typedef std::vector< EntryContent> listOfJournalEntry_type;


            WriteJournal_Request() : journalName(), listOfJournalEntry() {} 
 
            boost::asn1::value_holder<ObjectName> journalName;
            boost::asn1::value_holder<listOfJournalEntry_type> listOfJournalEntry;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence InitializeJournal-Request
        struct InitializeJournal_Request{


            struct limitSpecification_type{



                limitSpecification_type() : limitingTime() {} 
 
                boost::asn1::value_holder<TimeOfDay> limitingTime;
                boost::shared_ptr<octetstring_type> limitingEntry;
                BOOST_ASN_VALUE_FUNC_DECLARATE(octetstring_type, limitingEntry)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            InitializeJournal_Request() : journalName() {} 
 
            boost::asn1::value_holder<ObjectName> journalName;
            boost::shared_ptr<limitSpecification_type> limitSpecification;
            BOOST_ASN_VALUE_FUNC_DECLARATE(limitSpecification_type, limitSpecification)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ReportJournalStatus-Response
        struct ReportJournalStatus_Response{



            ReportJournalStatus_Response() : currentEntries(), mmsDeletable() {} 
 
            boost::asn1::value_holder<Unsigned32> currentEntries;
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::shared_ptr<Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence CreateJournal-Request
        struct CreateJournal_Request{



            CreateJournal_Request() : journalName() {} 
 
            boost::asn1::value_holder<ObjectName> journalName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DeleteJournal-Request
        struct DeleteJournal_Request{



            DeleteJournal_Request() : journalName() {} 
 
            boost::asn1::value_holder<ObjectName> journalName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence EntryContent
        struct EntryContent{


            enum entryForm_type_enum {
                entryForm_type_null = 0, 
                entryForm_type_data,
                entryForm_type_annotation,}; 
 
            struct entryForm_type : public BOOST_ASN_CHOICE_STRUCT(entryForm_type_enum) {


                struct data_type{


                    struct event_type{



                        event_type() : eventConditionName(), currentState() {} 
 
                        boost::asn1::value_holder<ObjectName> eventConditionName;
                        boost::asn1::value_holder<MMS_Object_Module_1::EC_State> currentState;

                        BOOST_ASN_ARCHIVE_FUNC;
                    };
 
                typedef std::vector< MMS_Object_Module_1::Journal_Variable> listOfVariables_type;


                    data_type() {} 
 
                    boost::shared_ptr<event_type> event;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(event_type, event)

                    boost::shared_ptr<listOfVariables_type> listOfVariables;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(listOfVariables_type, listOfVariables)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                entryForm_type() :  BOOST_ASN_CHOICE_STRUCT(entryForm_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(data, data_type, entryForm_type_data);
                BOOST_ASN_VALUE_CHOICE(annotation, MMSString, entryForm_type_annotation);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            EntryContent() : occurrenceTime(), entryForm() {} 
 
            boost::asn1::value_holder<TimeOfDay> occurrenceTime;
            boost::asn1::value_holder<entryForm_type> entryForm;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        template<> void MMSpdu::serialize(boost::asn1::x690::output_coder& arch);
        template<> void MMSpdu::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AdditionalService_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AdditionalService_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Request_Detail::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Request_Detail::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UnconfirmedService::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UnconfirmedService::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AdditionalService_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AdditionalService_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Response_Detail::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Response_Detail::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ServiceError::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ServiceError::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ServiceError::errorClass_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ServiceError::errorClass_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ServiceError::serviceSpecificInfo_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ServiceError::serviceSpecificInfo_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AdditionalService_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AdditionalService_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ObjectName::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ObjectName::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ObjectName::domain_specific_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ObjectName::domain_specific_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ObjectClass::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ObjectClass::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Initiate_RequestPDU::initRequestDetail_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Initiate_RequestPDU::initRequestDetail_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Initiate_ResponsePDU::initResponseDetail_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Initiate_ResponsePDU::initResponseDetail_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RejectPDU::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RejectPDU::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RejectPDU::rejectReason_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RejectPDU::rejectReason_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineAccessControlList_Request::accessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineAccessControlList_Request::accessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAccessControlListAttributes_Request::namedObject_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAccessControlListAttributes_Request::namedObject_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAccessControlListAttributes_Response::accessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAccessControlListAttributes_Response::accessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAccessControlListAttributes_Response::references_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAccessControlListAttributes_Response::references_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ChangeAccessControl_Request::scopeOfChange_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ChangeAccessControl_Request::scopeOfChange_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StatusResponse::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StatusResponse::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Status_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Status_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Status_Response::fullResponse_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Status_Response::fullResponse_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetNameList_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetNameList_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetNameList_Request::objectScope_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetNameList_Request::objectScope_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetNameList_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetNameList_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Identify_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Identify_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Rename_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Rename_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DownloadSegment_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DownloadSegment_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void LoadData::serialize(boost::asn1::x690::output_coder& arch);
        template<> void LoadData::serialize(boost::asn1::x690::input_coder& arch);
        template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UploadSegment_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UploadSegment_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Start_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Start_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Start_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Start_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Start_Request_impl::controlling_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Start_Request_impl::controlling_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StartCount::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StartCount::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Stop_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Stop_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Resume_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Resume_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Resume_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Resume_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Resume_Request_impl::controlling_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Resume_Request_impl::controlling_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_Resume_Request_impl::controlling_type::modeType_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_Resume_Request_impl::controlling_type::modeType_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Reset_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Reset_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Kill_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Kill_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetProgramInvocationAttributes_Response::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetProgramInvocationAttributes_Response::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Select_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Select_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ControlElement::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ControlElement::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ControlElement::beginDomainDef_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ControlElement::beginDomainDef_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ControlElement::continueDomainDef_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ControlElement::continueDomainDef_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ControlElement::piDefinition_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ControlElement::piDefinition_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UnitControlUpload_Request::continueAfter_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UnitControlUpload_Request::continueAfter_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void UnitControlUpload_Response::nextElement_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void UnitControlUpload_Response::nextElement_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StartUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StartUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StartUnitControl_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StartUnitControl_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StartUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StartUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StopUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StopUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void TypeSpecification::serialize(boost::asn1::x690::output_coder& arch);
        template<> void TypeSpecification::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccess_sequence_of::named_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccess_sequence_of::named_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccessSelection::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccessSelection::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccessSelection::selectAlternateAccess_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccessSelection::selectAlternateAccess_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccessSelection::selectAccess_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccessSelection::selectAccess_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlternateAccessSelection::selectAccess_type::indexRange_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlternateAccessSelection::selectAccess_type::indexRange_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AccessResult::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AccessResult::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Data::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Data::serialize(boost::asn1::x690::input_coder& arch);
        template<> void VariableAccessSpecification::serialize(boost::asn1::x690::output_coder& arch);
        template<> void VariableAccessSpecification::serialize(boost::asn1::x690::input_coder& arch);
        template<> void VariableAccessSpecification::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void VariableAccessSpecification::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void VariableSpecification::serialize(boost::asn1::x690::output_coder& arch);
        template<> void VariableSpecification::serialize(boost::asn1::x690::input_coder& arch);
        template<> void VariableSpecification::variableDescription_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void VariableSpecification::variableDescription_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Read_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Read_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Read_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Read_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Write_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Write_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void InformationReport::serialize(boost::asn1::x690::output_coder& arch);
        template<> void InformationReport::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineNamedType_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineNamedType_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ExchangeData_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ExchangeData_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ExchangeData_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ExchangeData_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void TakeControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void TakeControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void TakeControl_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void TakeControl_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RelinquishControl_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RelinquishControl_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void SemaphoreEntry::serialize(boost::asn1::x690::output_coder& arch);
        template<> void SemaphoreEntry::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AttachToSemaphore::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AttachToSemaphore::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Input_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Input_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void Output_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void Output_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void TriggerEvent_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void TriggerEvent_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EventNotification::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EventNotification::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EventNotification::actionResult_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EventNotification::actionResult_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EventNotification::actionResult_type::successOrFailure_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EventNotification::actionResult_type::successOrFailure_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EventNotification::actionResult_type::successOrFailure_type::success_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EventNotification::actionResult_type::successOrFailure_type::success_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EventNotification::actionResult_type::successOrFailure_type::failure_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EventNotification::actionResult_type::successOrFailure_type::failure_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAlarmSummary_Request::severityFilter_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAlarmSummary_Request::severityFilter_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlarmSummary::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlarmSummary::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAlarmEnrollmentSummary_Request::severityFilter_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAlarmEnrollmentSummary_Request::severityFilter_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AttachToEventCondition::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AttachToEventCondition::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetEventConditionAttributes_Response::monitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetEventConditionAttributes_Response::monitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_GetEventConditionAttributes_Response::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_GetEventConditionAttributes_Response::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineEventAction_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineEventAction_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EEAttributes::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EEAttributes::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EEAttributes::eventConditionName_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EEAttributes::eventConditionName_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EEAttributes::eventActionName_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EEAttributes::eventActionName_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EEAttributes::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EEAttributes::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterEventEnrollment_Response::currentState_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterEventEnrollment_Response::currentState_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CS_AlterEventEnrollment_Request::changeDisplay_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CS_AlterEventEnrollment_Request::changeDisplay_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::output_coder& arch);
        template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EventConditionStatus::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EventConditionStatus::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void AlterEventConditionListMonitoring_Request::priorityChange_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void AlterEventConditionListMonitoring_Request::priorityChange_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReadJournal_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReadJournal_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReadJournal_Request::rangeStartSpecification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReadJournal_Request::rangeStartSpecification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReadJournal_Request::rangeStopSpecification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReadJournal_Request::rangeStopSpecification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReadJournal_Request::entryToStartAfter_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReadJournal_Request::entryToStartAfter_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReadJournal_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReadJournal_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void JournalEntry::serialize(boost::asn1::x690::output_coder& arch);
        template<> void JournalEntry::serialize(boost::asn1::x690::input_coder& arch);
        template<> void WriteJournal_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void WriteJournal_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void InitializeJournal_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void InitializeJournal_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void InitializeJournal_Request::limitSpecification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void InitializeJournal_Request::limitSpecification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void CreateJournal_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void CreateJournal_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DeleteJournal_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DeleteJournal_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EntryContent::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EntryContent::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EntryContent::entryForm_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EntryContent::entryForm_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EntryContent::entryForm_type::data_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EntryContent::entryForm_type::data_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void EntryContent::entryForm_type::data_type::event_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void EntryContent::entryForm_type::data_type::event_type::serialize(boost::asn1::x690::input_coder& arch);
} 

BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::MMSpdu)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ConfirmedServiceRequest)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Request)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Request_Detail)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::UnconfirmedService)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Unconfirmed_Detail)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ConfirmedServiceResponse)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Response)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Response_Detail)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ServiceError::errorClass_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ServiceError::serviceSpecificInfo_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Error)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ObjectName)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ObjectClass)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::RejectPDU::rejectReason_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetAccessControlListAttributes_Request)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ChangeAccessControl_Request::scopeOfChange_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Status_Response)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Status_Response::fullResponse_type::selectedProgramInvocation_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetNameList_Request::objectScope_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::LoadData)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Start_Request::executionArgument_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Start_Request_impl)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::StartCount)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Resume_Request::executionArgument_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Resume_Request_impl)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Resume_Request_impl::controlling_type::modeType_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetProgramInvocationAttributes_Response::executionArgument_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::control_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::control_type::controlled_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ControlElement)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::InitiateUnitControl_Error)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::UnitControlUpload_Request::continueAfter_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::UnitControlUpload_Response::nextElement_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::StartUnitControl_Request::executionArgument_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::LoadUnitControlFromFile_Error)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteUnitControl_Error)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::TypeSpecification)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccess_sequence_of)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection::selectAccess_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AccessResult)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Data)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::VariableAccessSpecification)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::VariableSpecification)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::Write_Response_sequence_of)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetVariableAccessAttributes_Request)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::TakeControl_Response)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::EventNotification::actionResult_type::successOrFailure_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_EventNotification_impl)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::EN_Additional_Detail_impl)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_DefineEventCondition_Request_impl)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteEventCondition_Request)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetEventConditionAttributes_Response::monitoredVariable_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetEventConditionAttributes_Response::groupPriorityOverride_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetEventConditionAttributes_Response::displayEnhancement_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_AlterEventConditionMonitoring_Request::changeDisplay_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteEventAction_Request)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_DefineEventEnrollment_Request_impl)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteEventEnrollment_Request)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::eventConditionName_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::eventActionName_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::displayEnhancement_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlterEventEnrollment_Response::currentState_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_AlterEventEnrollment_Request::changeDisplay_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::RemoveEventConditionListReference_Error)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlterEventConditionListMonitoring_Request::priorityChange_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ReadJournal_Request::rangeStartSpecification_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::ReadJournal_Request::rangeStopSpecification_type)
BOOST_ASN_CHOICE_REGESTRATE(ISO_9506_MMS_1::EntryContent::entryForm_type)

#endif  /*___ISO_9506_MMS_1 */

