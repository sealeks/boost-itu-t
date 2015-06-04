#ifndef ___ISO_9506_MMS_1
#define ___ISO_9506_MMS_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1 {

    ITU_T_USE_UNIVESAL_DECL;


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
    struct CS_Start_Request;
    struct StartCount;
    struct Stop_Request;
    struct Resume_Request;
    struct CS_Resume_Request;
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
    struct CS_EventNotification;
    struct AcknowledgeEventNotification_Request;
    struct GetAlarmSummary_Request;
    struct GetAlarmSummary_Response;
    struct AlarmSummary;
    struct EN_Additional_Detail;
    struct GetAlarmEnrollmentSummary_Request;
    struct GetAlarmEnrollmentSummary_Response;
    struct AlarmEnrollmentSummary;
    struct AttachToEventCondition;
    struct DefineEventCondition_Request;
    struct CS_DefineEventCondition_Request;
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
    struct CS_DefineEventEnrollment_Request;
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


    typedef octet_string TimeOfDay; //    Sc (  [ 4  ...   6 ]   
    typedef visible_string Identifier;
    typedef int8_t Integer8; //   Ic(  [ -128  ...   127 ]   
    typedef int16_t Integer16; //   Ic(  [ -32768  ...   32767 ]   
    typedef int32_t Integer32; //   Ic(  [ -2147483648  ...   2147483647 ]   
    typedef uint8_t Unsigned8; //   Ic(  [ 0  ...   127 ]   
    typedef uint16_t Unsigned16; //   Ic(  [ 0  ...   32767 ]   
    typedef uint32_t Unsigned32; //   Ic(  [ 0  ...   2147483647 ]   
    typedef visible_string MMSString;
    typedef visible_string MMS255String;
    typedef null_type Conclude_RequestPDU;
    typedef null_type Conclude_ResponsePDU;
    typedef null_type DefineAccessControlList_Response;
    typedef null_type DeleteAccessControlList_Response;
    typedef uint8_t OperationState; //   Ic(  [ 0  ...   5 ]   
    typedef bit_string ExtendedStatus; //    Sc (  [ 4 ]   
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
    typedef uint8_t CS_CreateProgramInvocation_Request; //   Ic(  [ 0  ...   2 ]   
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
    typedef octet_string FloatingPoint;
    typedef uint8_t DataAccessError; //   Ic(  [ 0  ...   11 ]   
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
    typedef integer_type EE_State;
    typedef null_type DefineEventConditionList_Response;
    typedef null_type DeleteEventConditionList_Response;
    typedef null_type AddEventConditionListReference_Response;
    typedef null_type RemoveEventConditionListReference_Response;
    typedef null_type AlterEventConditionListMonitoring_Response;
    typedef null_type WriteJournal_Response;
    typedef null_type CreateJournal_Response;
    typedef null_type DeleteJournal_Response;
    typedef sequence_of< graphic_string > FileName;

    typedef ServiceError Initiate_ErrorPDU;
    typedef ServiceError Conclude_ErrorPDU;
    typedef Unsigned32 Cancel_RequestPDU; //   Ic(  [ 0  ...   2147483647 ]   
    typedef Unsigned32 Cancel_ResponsePDU; //   Ic(  [ 0  ...   2147483647 ]   
    typedef Identifier DeleteAccessControlList_Request;
    typedef Unsigned32 ChangeAccessControl_Error; //   Ic(  [ 0  ...   2147483647 ]   
    typedef StatusResponse Status_Response;
    typedef StatusResponse UnsolicitedStatus;
    typedef StatusResponse VMDReset_Response;
    typedef Identifier DownloadSegment_Request;
    typedef Identifier InitiateUploadSequence_Request;
    typedef Integer32 UploadSegment_Request; //   Ic(  [ -2147483648  ...   2147483647 ]   
    typedef Integer32 TerminateUploadSequence_Request; //   Ic(  [ -2147483648  ...   2147483647 ]   
    typedef Identifier DeleteDomain_Request;
    typedef Identifier GetDomainAttributes_Request;
    typedef Identifier DeleteProgramInvocation_Request;
    typedef Identifier GetProgramInvocationAttributes_Request;
    typedef Identifier InitiateUnitControlLoad_Request;
    typedef Identifier UnitControlLoadSegment_Request;
    typedef Identifier StopUnitControl_Request;
    typedef Identifier GetUnitControlAttributes_Request;
    typedef Identifier DeleteUnitControl_Request;
    typedef Unsigned32 DeleteVariableAccess_Error; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName GetNamedVariableListAttributes_Request;
    typedef Unsigned32 DeleteNamedVariableList_Error; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName GetNamedTypeAttributes_Request;
    typedef Unsigned32 DeleteNamedType_Error; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName GetDataExchangeAttributes_Request;
    typedef ObjectName DeleteSemaphore_Request;
    typedef ObjectName ReportSemaphoreStatus_Request;
    typedef MMSString Input_Response;
    typedef Unsigned32 DeleteEventCondition_Response; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName GetEventConditionAttributes_Request;
    typedef ObjectName ReportEventConditionStatus_Request;
    typedef Unsigned32 DeleteEventAction_Response; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName GetEventActionAttributes_Request;
    typedef ObjectName ReportEventActionStatus_Request;
    typedef Unsigned32 ReportEventActionStatus_Response; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName DefineEventEnrollment_Error;
    typedef Unsigned32 DeleteEventEnrollment_Response; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName ReportEventEnrollmentStatus_Request;
    typedef ObjectName DefineEventConditionList_Error;
    typedef ObjectName DeleteEventConditionList_Request;
    typedef ObjectName AddEventConditionListReference_Error;
    typedef ObjectName GetEventConditionListAttributes_Request;
    typedef Unsigned32 InitializeJournal_Response; //   Ic(  [ 0  ...   2147483647 ]   
    typedef ObjectName ReportJournalStatus_Request;
    typedef sequence_of< AlternateAccess_sequence_of > AlternateAccess;
    typedef sequence_of< Write_Response_sequence_of > Write_Response;
    ITU_T_EXPLICIT_TYPEDEF(CS_EventNotification__expl_helper, CS_EventNotification, 0, CONTEXT_CLASS);
    ITU_T_PREFIXED_DECLARE(CS_EventNotification, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), true); //  initial =explicit
    ITU_T_EXPLICIT_TYPEDEF(CS_DefineEventEnrollment_Request__expl_helper, CS_DefineEventEnrollment_Request, 0, CONTEXT_CLASS);
    ITU_T_PREFIXED_DECLARE(CS_DefineEventEnrollment_Request, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), true); //  initial =explicit
    ITU_T_EXPLICIT_TYPEDEF(EN_Additional_Detail__expl_helper, EN_Additional_Detail, 0, CONTEXT_CLASS);
    ITU_T_PREFIXED_DECLARE(EN_Additional_Detail, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), true); //  initial =explicit
    ITU_T_EXPLICIT_TYPEDEF(CS_DefineEventCondition_Request__expl_helper, CS_DefineEventCondition_Request, 0, CONTEXT_CLASS);
    ITU_T_PREFIXED_DECLARE(CS_DefineEventCondition_Request, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), true); //  initial =explicit
    ITU_T_EXPLICIT_TYPEDEF(CS_Start_Request__expl_helper, CS_Start_Request, 0, CONTEXT_CLASS);
    ITU_T_PREFIXED_DECLARE(CS_Start_Request, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), true); //  initial =explicit
    ITU_T_EXPLICIT_TYPEDEF(CS_Resume_Request__expl_helper, CS_Resume_Request, 0, CONTEXT_CLASS);
    ITU_T_PREFIXED_DECLARE(CS_Resume_Request, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), true); //  initial =explicit

    const integer_type maxIdentifier = 32;


}

#include <mms/MMS-Environment-1.hpp>
#include <mms/MMS-Environment-1.hpp>
#include <mms/ISO-9506-MMS-1A.hpp>
#include <mms/MMS-Object-Module-1.hpp>

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



    typedef MMS_Object_Module_1::ProgramInvocationState Start_Error; //   Ic(  [ 0  ...   8 ]   
    typedef MMS_Object_Module_1::ProgramInvocationState Stop_Error; //   Ic(  [ 0  ...   8 ]   
    typedef MMS_Object_Module_1::ProgramInvocationState Resume_Error; //   Ic(  [ 0  ...   8 ]   
    typedef MMS_Object_Module_1::ProgramInvocationState Reset_Error; //   Ic(  [ 0  ...   8 ]   
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
        MMSpdu_conclude_ErrorPDU,
    };

    struct MMSpdu : public ITU_T_CHOICE(MMSpdu_enum) {


        ITU_T_CHOICE_CTORS(MMSpdu);

        ITU_T_CHOICEC_DECL(confirmed_RequestPDU, Confirmed_RequestPDU, MMSpdu_confirmed_RequestPDU);
        ITU_T_CHOICEC_DECL(confirmed_ResponsePDU, Confirmed_ResponsePDU, MMSpdu_confirmed_ResponsePDU);
        ITU_T_CHOICEC_DECL(confirmed_ErrorPDU, Confirmed_ErrorPDU, MMSpdu_confirmed_ErrorPDU);
        ITU_T_CHOICEC_DECL(unconfirmed_PDU, Unconfirmed_PDU, MMSpdu_unconfirmed_PDU);
        ITU_T_CHOICEC_DECL(rejectPDU, RejectPDU, MMSpdu_rejectPDU);
        ITU_T_CHOICES_DECL(cancel_RequestPDU, Cancel_RequestPDU, MMSpdu_cancel_RequestPDU); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(cancel_ResponsePDU, Cancel_ResponsePDU, MMSpdu_cancel_ResponsePDU); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(cancel_ErrorPDU, Cancel_ErrorPDU, MMSpdu_cancel_ErrorPDU);
        ITU_T_CHOICEC_DECL(initiate_RequestPDU, Initiate_RequestPDU, MMSpdu_initiate_RequestPDU);
        ITU_T_CHOICEC_DECL(initiate_ResponsePDU, Initiate_ResponsePDU, MMSpdu_initiate_ResponsePDU);
        ITU_T_CHOICEC_DECL(initiate_ErrorPDU, Initiate_ErrorPDU, MMSpdu_initiate_ErrorPDU);
        ITU_T_CHOICES_DECL(conclude_RequestPDU, Conclude_RequestPDU, MMSpdu_conclude_RequestPDU); // primitive
        ITU_T_CHOICES_DECL(conclude_ResponsePDU, Conclude_ResponsePDU, MMSpdu_conclude_ResponsePDU); // primitive
        ITU_T_CHOICEC_DECL(conclude_ErrorPDU, Conclude_ErrorPDU, MMSpdu_conclude_ErrorPDU);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Confirmed-RequestPDU

    struct Confirmed_RequestPDU {

        typedef sequence_of< MMS_Object_Module_1::Modifier > ListOfModifiers_type;

        Confirmed_RequestPDU();

        Confirmed_RequestPDU(const Unsigned32& arg__invokeID,
                const ConfirmedServiceRequest& arg__service);

        Confirmed_RequestPDU(shared_ptr< Unsigned32> arg__invokeID,
                shared_ptr< ListOfModifiers_type> arg__listOfModifiers,
                shared_ptr< ConfirmedServiceRequest> arg__service,
                shared_ptr< Request_Detail> arg__service_ext = shared_ptr< Request_Detail>());

        ITU_T_HOLDERH_DECL(invokeID, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(listOfModifiers, ListOfModifiers_type);
        ITU_T_HOLDERH_DECL(service, ConfirmedServiceRequest);
        ITU_T_OPTIONAL_DECL(service_ext, Request_Detail);

        ITU_T_ARCHIVE_FUNC;
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
        ConfirmedServiceRequest_changeAccessControl,
    };

    struct ConfirmedServiceRequest : public ITU_T_CHOICE(ConfirmedServiceRequest_enum) {


        ITU_T_CHOICE_CTORS(ConfirmedServiceRequest);

        ITU_T_CHOICES_DECL(status, Status_Request, ConfirmedServiceRequest_status); // primitive
        ITU_T_CHOICEC_DECL(getNameList, GetNameList_Request, ConfirmedServiceRequest_getNameList);
        ITU_T_CHOICES_DECL(identify, Identify_Request, ConfirmedServiceRequest_identify); // primitive
        ITU_T_CHOICEC_DECL(rename, Rename_Request, ConfirmedServiceRequest_rename);
        ITU_T_CHOICEC_DECL(read, Read_Request, ConfirmedServiceRequest_read);
        ITU_T_CHOICEC_DECL(write, Write_Request, ConfirmedServiceRequest_write);
        ITU_T_CHOICEC_DECL(getVariableAccessAttributes, GetVariableAccessAttributes_Request, ConfirmedServiceRequest_getVariableAccessAttributes);
        ITU_T_CHOICEC_DECL(defineNamedVariable, DefineNamedVariable_Request, ConfirmedServiceRequest_defineNamedVariable);
        ITU_T_CHOICEC_DECL(defineScatteredAccess, ISO_9506_MMS_1A::DefineScatteredAccess_Request, ConfirmedServiceRequest_defineScatteredAccess);
        ITU_T_CHOICEC_DECL(getScatteredAccessAttributes, ObjectName, ConfirmedServiceRequest_getScatteredAccessAttributes);
        ITU_T_CHOICEC_DECL(deleteVariableAccess, DeleteVariableAccess_Request, ConfirmedServiceRequest_deleteVariableAccess);
        ITU_T_CHOICEC_DECL(defineNamedVariableList, DefineNamedVariableList_Request, ConfirmedServiceRequest_defineNamedVariableList);
        ITU_T_CHOICEC_DECL(getNamedVariableListAttributes, GetNamedVariableListAttributes_Request, ConfirmedServiceRequest_getNamedVariableListAttributes);
        ITU_T_CHOICEC_DECL(deleteNamedVariableList, DeleteNamedVariableList_Request, ConfirmedServiceRequest_deleteNamedVariableList);
        ITU_T_CHOICEC_DECL(defineNamedType, DefineNamedType_Request, ConfirmedServiceRequest_defineNamedType);
        ITU_T_CHOICEC_DECL(getNamedTypeAttributes, GetNamedTypeAttributes_Request, ConfirmedServiceRequest_getNamedTypeAttributes);
        ITU_T_CHOICEC_DECL(deleteNamedType, DeleteNamedType_Request, ConfirmedServiceRequest_deleteNamedType);
        ITU_T_CHOICEC_DECL(input, Input_Request, ConfirmedServiceRequest_input);
        ITU_T_CHOICEC_DECL(output, Output_Request, ConfirmedServiceRequest_output);
        ITU_T_CHOICEC_DECL(takeControl, TakeControl_Request, ConfirmedServiceRequest_takeControl);
        ITU_T_CHOICEC_DECL(relinquishControl, RelinquishControl_Request, ConfirmedServiceRequest_relinquishControl);
        ITU_T_CHOICEC_DECL(defineSemaphore, DefineSemaphore_Request, ConfirmedServiceRequest_defineSemaphore);
        ITU_T_CHOICEC_DECL(deleteSemaphore, DeleteSemaphore_Request, ConfirmedServiceRequest_deleteSemaphore);
        ITU_T_CHOICEC_DECL(reportSemaphoreStatus, ReportSemaphoreStatus_Request, ConfirmedServiceRequest_reportSemaphoreStatus);
        ITU_T_CHOICEC_DECL(reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Request, ConfirmedServiceRequest_reportPoolSemaphoreStatus);
        ITU_T_CHOICEC_DECL(reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Request, ConfirmedServiceRequest_reportSemaphoreEntryStatus);
        ITU_T_CHOICEC_DECL(initiateDownloadSequence, InitiateDownloadSequence_Request, ConfirmedServiceRequest_initiateDownloadSequence);
        ITU_T_CHOICES_DECL(downloadSegment, DownloadSegment_Request, ConfirmedServiceRequest_downloadSegment); // primitive
        ITU_T_CHOICEC_DECL(terminateDownloadSequence, TerminateDownloadSequence_Request, ConfirmedServiceRequest_terminateDownloadSequence);
        ITU_T_CHOICES_DECL(initiateUploadSequence, InitiateUploadSequence_Request, ConfirmedServiceRequest_initiateUploadSequence); // primitive
        ITU_T_CHOICES_DECL(uploadSegment, UploadSegment_Request, ConfirmedServiceRequest_uploadSegment); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(terminateUploadSequence, TerminateUploadSequence_Request, ConfirmedServiceRequest_terminateUploadSequence); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(requestDomainDownload, RequestDomainDownload_Request, ConfirmedServiceRequest_requestDomainDownload);
        ITU_T_CHOICEC_DECL(requestDomainUpload, RequestDomainUpload_Request, ConfirmedServiceRequest_requestDomainUpload);
        ITU_T_CHOICEC_DECL(loadDomainContent, LoadDomainContent_Request, ConfirmedServiceRequest_loadDomainContent);
        ITU_T_CHOICEC_DECL(storeDomainContent, StoreDomainContent_Request, ConfirmedServiceRequest_storeDomainContent);
        ITU_T_CHOICES_DECL(deleteDomain, DeleteDomain_Request, ConfirmedServiceRequest_deleteDomain); // primitive
        ITU_T_CHOICES_DECL(getDomainAttributes, GetDomainAttributes_Request, ConfirmedServiceRequest_getDomainAttributes); // primitive
        ITU_T_CHOICEC_DECL(createProgramInvocation, CreateProgramInvocation_Request, ConfirmedServiceRequest_createProgramInvocation);
        ITU_T_CHOICES_DECL(deleteProgramInvocation, DeleteProgramInvocation_Request, ConfirmedServiceRequest_deleteProgramInvocation); // primitive
        ITU_T_CHOICEC_DECL(start, Start_Request, ConfirmedServiceRequest_start);
        ITU_T_CHOICEC_DECL(stop, Stop_Request, ConfirmedServiceRequest_stop);
        ITU_T_CHOICEC_DECL(resume, Resume_Request, ConfirmedServiceRequest_resume);
        ITU_T_CHOICEC_DECL(reset, Reset_Request, ConfirmedServiceRequest_reset);
        ITU_T_CHOICEC_DECL(kill, Kill_Request, ConfirmedServiceRequest_kill);
        ITU_T_CHOICES_DECL(getProgramInvocationAttributes, GetProgramInvocationAttributes_Request, ConfirmedServiceRequest_getProgramInvocationAttributes); // primitive
        ITU_T_CHOICEC_DECL(obtainFile, ISO_9506_MMS_1A::ObtainFile_Request, ConfirmedServiceRequest_obtainFile);
        ITU_T_CHOICEC_DECL(defineEventCondition, DefineEventCondition_Request, ConfirmedServiceRequest_defineEventCondition);
        ITU_T_CHOICEC_DECL(deleteEventCondition, DeleteEventCondition_Request, ConfirmedServiceRequest_deleteEventCondition);
        ITU_T_CHOICEC_DECL(getEventConditionAttributes, GetEventConditionAttributes_Request, ConfirmedServiceRequest_getEventConditionAttributes);
        ITU_T_CHOICEC_DECL(reportEventConditionStatus, ReportEventConditionStatus_Request, ConfirmedServiceRequest_reportEventConditionStatus);
        ITU_T_CHOICEC_DECL(alterEventConditionMonitoring, AlterEventConditionMonitoring_Request, ConfirmedServiceRequest_alterEventConditionMonitoring);
        ITU_T_CHOICEC_DECL(triggerEvent, TriggerEvent_Request, ConfirmedServiceRequest_triggerEvent);
        ITU_T_CHOICEC_DECL(defineEventAction, DefineEventAction_Request, ConfirmedServiceRequest_defineEventAction);
        ITU_T_CHOICEC_DECL(deleteEventAction, DeleteEventAction_Request, ConfirmedServiceRequest_deleteEventAction);
        ITU_T_CHOICEC_DECL(getEventActionAttributes, GetEventActionAttributes_Request, ConfirmedServiceRequest_getEventActionAttributes);
        ITU_T_CHOICEC_DECL(reportEventActionStatus, ReportEventActionStatus_Request, ConfirmedServiceRequest_reportEventActionStatus);
        ITU_T_CHOICEC_DECL(defineEventEnrollment, DefineEventEnrollment_Request, ConfirmedServiceRequest_defineEventEnrollment);
        ITU_T_CHOICEC_DECL(deleteEventEnrollment, DeleteEventEnrollment_Request, ConfirmedServiceRequest_deleteEventEnrollment);
        ITU_T_CHOICEC_DECL(alterEventEnrollment, AlterEventEnrollment_Request, ConfirmedServiceRequest_alterEventEnrollment);
        ITU_T_CHOICEC_DECL(reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Request, ConfirmedServiceRequest_reportEventEnrollmentStatus);
        ITU_T_CHOICEC_DECL(getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Request, ConfirmedServiceRequest_getEventEnrollmentAttributes);
        ITU_T_CHOICEC_DECL(acknowledgeEventNotification, AcknowledgeEventNotification_Request, ConfirmedServiceRequest_acknowledgeEventNotification);
        ITU_T_CHOICEC_DECL(getAlarmSummary, GetAlarmSummary_Request, ConfirmedServiceRequest_getAlarmSummary);
        ITU_T_CHOICEC_DECL(getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Request, ConfirmedServiceRequest_getAlarmEnrollmentSummary);
        ITU_T_CHOICEC_DECL(readJournal, ReadJournal_Request, ConfirmedServiceRequest_readJournal);
        ITU_T_CHOICEC_DECL(writeJournal, WriteJournal_Request, ConfirmedServiceRequest_writeJournal);
        ITU_T_CHOICEC_DECL(initializeJournal, InitializeJournal_Request, ConfirmedServiceRequest_initializeJournal);
        ITU_T_CHOICEC_DECL(reportJournalStatus, ReportJournalStatus_Request, ConfirmedServiceRequest_reportJournalStatus);
        ITU_T_CHOICEC_DECL(createJournal, CreateJournal_Request, ConfirmedServiceRequest_createJournal);
        ITU_T_CHOICEC_DECL(deleteJournal, DeleteJournal_Request, ConfirmedServiceRequest_deleteJournal);
        ITU_T_CHOICEC_DECL(getCapabilityList, GetCapabilityList_Request, ConfirmedServiceRequest_getCapabilityList);
        ITU_T_CHOICEC_DECL(fileOpen, ISO_9506_MMS_1A::FileOpen_Request, ConfirmedServiceRequest_fileOpen);
        ITU_T_CHOICES_DECL(fileRead, Integer32, ConfirmedServiceRequest_fileRead); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(fileClose, Integer32, ConfirmedServiceRequest_fileClose); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(fileRename, ISO_9506_MMS_1A::FileRename_Request, ConfirmedServiceRequest_fileRename);
        ITU_T_CHOICEC_DECL(fileDelete, FileName, ConfirmedServiceRequest_fileDelete);
        ITU_T_CHOICEC_DECL(fileDirectory, ISO_9506_MMS_1A::FileDirectory_Request, ConfirmedServiceRequest_fileDirectory);
        ITU_T_CHOICEC_DECL(additionalService, AdditionalService_Request, ConfirmedServiceRequest_additionalService);
        ITU_T_CHOICEC_DECL(getDataExchangeAttributes, GetDataExchangeAttributes_Request, ConfirmedServiceRequest_getDataExchangeAttributes);
        ITU_T_CHOICEC_DECL(exchangeData, ExchangeData_Request, ConfirmedServiceRequest_exchangeData);
        ITU_T_CHOICEC_DECL(defineAccessControlList, DefineAccessControlList_Request, ConfirmedServiceRequest_defineAccessControlList);
        ITU_T_CHOICEC_DECL(getAccessControlListAttributes, GetAccessControlListAttributes_Request, ConfirmedServiceRequest_getAccessControlListAttributes);
        ITU_T_CHOICEC_DECL(reportAccessControlledObjects, ReportAccessControlledObjects_Request, ConfirmedServiceRequest_reportAccessControlledObjects);
        ITU_T_CHOICES_DECL(deleteAccessControlList, DeleteAccessControlList_Request, ConfirmedServiceRequest_deleteAccessControlList); // primitive
        ITU_T_CHOICEC_DECL(changeAccessControl, ChangeAccessControl_Request, ConfirmedServiceRequest_changeAccessControl);

        ITU_T_ARCHIVE_FUNC;
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
        AdditionalService_Request_alterECLMonitoring,
    };

    struct AdditionalService_Request : public ITU_T_CHOICE(AdditionalService_Request_enum) {


        ITU_T_CHOICE_CTORS(AdditionalService_Request);

        ITU_T_CHOICES_DECL(vMDStop, VMDStop_Request, AdditionalService_Request_vMDStop); // primitive
        ITU_T_CHOICES_DECL(vMDReset, VMDReset_Request, AdditionalService_Request_vMDReset); // primitive
        ITU_T_CHOICEC_DECL(select, Select_Request, AdditionalService_Request_select);
        ITU_T_CHOICEC_DECL(alterPI, AlterProgramInvocationAttributes_Request, AdditionalService_Request_alterPI);
        ITU_T_CHOICES_DECL(initiateUCLoad, InitiateUnitControlLoad_Request, AdditionalService_Request_initiateUCLoad); // primitive
        ITU_T_CHOICES_DECL(uCLoad, UnitControlLoadSegment_Request, AdditionalService_Request_uCLoad); // primitive
        ITU_T_CHOICEC_DECL(uCUpload, UnitControlUpload_Request, AdditionalService_Request_uCUpload);
        ITU_T_CHOICEC_DECL(startUC, StartUnitControl_Request, AdditionalService_Request_startUC);
        ITU_T_CHOICES_DECL(stopUC, StopUnitControl_Request, AdditionalService_Request_stopUC); // primitive
        ITU_T_CHOICEC_DECL(createUC, CreateUnitControl_Request, AdditionalService_Request_createUC);
        ITU_T_CHOICEC_DECL(addToUC, AddToUnitControl_Request, AdditionalService_Request_addToUC);
        ITU_T_CHOICEC_DECL(removeFromUC, RemoveFromUnitControl_Request, AdditionalService_Request_removeFromUC);
        ITU_T_CHOICES_DECL(getUCAttributes, GetUnitControlAttributes_Request, AdditionalService_Request_getUCAttributes); // primitive
        ITU_T_CHOICEC_DECL(loadUCFromFile, LoadUnitControlFromFile_Request, AdditionalService_Request_loadUCFromFile);
        ITU_T_CHOICEC_DECL(storeUCToFile, StoreUnitControlToFile_Request, AdditionalService_Request_storeUCToFile);
        ITU_T_CHOICES_DECL(deleteUC, DeleteUnitControl_Request, AdditionalService_Request_deleteUC); // primitive
        ITU_T_CHOICEC_DECL(defineECL, DefineEventConditionList_Request, AdditionalService_Request_defineECL);
        ITU_T_CHOICEC_DECL(deleteECL, DeleteEventConditionList_Request, AdditionalService_Request_deleteECL);
        ITU_T_CHOICEC_DECL(addECLReference, AddEventConditionListReference_Request, AdditionalService_Request_addECLReference);
        ITU_T_CHOICEC_DECL(removeECLReference, RemoveEventConditionListReference_Request, AdditionalService_Request_removeECLReference);
        ITU_T_CHOICEC_DECL(getECLAttributes, GetEventConditionListAttributes_Request, AdditionalService_Request_getECLAttributes);
        ITU_T_CHOICEC_DECL(reportECLStatus, ReportEventConditionListStatus_Request, AdditionalService_Request_reportECLStatus);
        ITU_T_CHOICEC_DECL(alterECLMonitoring, AlterEventConditionListMonitoring_Request, AdditionalService_Request_alterECLMonitoring);

        ITU_T_ARCHIVE_FUNC;
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
        Request_Detail_alterEventEnrollment,
    };

    struct Request_Detail : public ITU_T_CHOICE(Request_Detail_enum) {


        ITU_T_CHOICE_CTORS(Request_Detail);

        ITU_T_CHOICES_DECL(otherRequests, null_type, Request_Detail_otherRequests); // primitive
        ITU_T_CHOICES_DECL(createProgramInvocation, CS_CreateProgramInvocation_Request, Request_Detail_createProgramInvocation); // primitive  //   Ic(  [ 0  ...   2 ]   
        ITU_T_CHOICEC_DECL(start, CS_Start_Request, Request_Detail_start);
        ITU_T_CHOICEC_DECL(resume, CS_Resume_Request, Request_Detail_resume);
        ITU_T_CHOICEC_DECL(defineEventCondition, CS_DefineEventCondition_Request, Request_Detail_defineEventCondition);
        ITU_T_CHOICEC_DECL(alterEventConditionMonitoring, CS_AlterEventConditionMonitoring_Request, Request_Detail_alterEventConditionMonitoring);
        ITU_T_CHOICEC_DECL(defineEventEnrollment, CS_DefineEventEnrollment_Request, Request_Detail_defineEventEnrollment);
        ITU_T_CHOICEC_DECL(alterEventEnrollment, CS_AlterEventEnrollment_Request, Request_Detail_alterEventEnrollment);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Unconfirmed-PDU

    struct Unconfirmed_PDU {

        Unconfirmed_PDU();

        Unconfirmed_PDU(const UnconfirmedService& arg__service);

        Unconfirmed_PDU(shared_ptr< UnconfirmedService> arg__service,
                shared_ptr< Unconfirmed_Detail> arg__service_ext = shared_ptr< Unconfirmed_Detail>());

        ITU_T_HOLDERH_DECL(service, UnconfirmedService);
        ITU_T_OPTIONAL_DECL(service_ext, Unconfirmed_Detail);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice UnconfirmedService

    enum UnconfirmedService_enum {

        UnconfirmedService_null = 0,
        UnconfirmedService_informationReport,
        UnconfirmedService_unsolicitedStatus,
        UnconfirmedService_eventNotification,
    };

    struct UnconfirmedService : public ITU_T_CHOICE(UnconfirmedService_enum) {


        ITU_T_CHOICE_CTORS(UnconfirmedService);

        ITU_T_CHOICEC_DECL(informationReport, InformationReport, UnconfirmedService_informationReport);
        ITU_T_CHOICEC_DECL(unsolicitedStatus, UnsolicitedStatus, UnconfirmedService_unsolicitedStatus);
        ITU_T_CHOICEC_DECL(eventNotification, EventNotification, UnconfirmedService_eventNotification);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Unconfirmed-Detail

    enum Unconfirmed_Detail_enum {

        Unconfirmed_Detail_null = 0,
        Unconfirmed_Detail_otherRequests,
        Unconfirmed_Detail_eventNotification,
    };

    struct Unconfirmed_Detail : public ITU_T_CHOICE(Unconfirmed_Detail_enum) {


        ITU_T_CHOICE_CTORS(Unconfirmed_Detail);

        ITU_T_CHOICES_DECL(otherRequests, null_type, Unconfirmed_Detail_otherRequests); // primitive
        ITU_T_CHOICEC_DECL(eventNotification, CS_EventNotification, Unconfirmed_Detail_eventNotification);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Confirmed-ResponsePDU

    struct Confirmed_ResponsePDU {

        Confirmed_ResponsePDU();

        Confirmed_ResponsePDU(const Unsigned32& arg__invokeID,
                const ConfirmedServiceResponse& arg__service);

        Confirmed_ResponsePDU(shared_ptr< Unsigned32> arg__invokeID,
                shared_ptr< ConfirmedServiceResponse> arg__service,
                shared_ptr< Response_Detail> arg__service_ext = shared_ptr< Response_Detail>());

        ITU_T_HOLDERH_DECL(invokeID, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(service, ConfirmedServiceResponse);
        ITU_T_OPTIONAL_DECL(service_ext, Response_Detail);

        ITU_T_ARCHIVE_FUNC;
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
        ConfirmedServiceResponse_changeAccessControl,
    };

    struct ConfirmedServiceResponse : public ITU_T_CHOICE(ConfirmedServiceResponse_enum) {


        ITU_T_CHOICE_CTORS(ConfirmedServiceResponse);

        ITU_T_CHOICEC_DECL(status, Status_Response, ConfirmedServiceResponse_status);
        ITU_T_CHOICEC_DECL(getNameList, GetNameList_Response, ConfirmedServiceResponse_getNameList);
        ITU_T_CHOICEC_DECL(identify, Identify_Response, ConfirmedServiceResponse_identify);
        ITU_T_CHOICES_DECL(rename, Rename_Response, ConfirmedServiceResponse_rename); // primitive
        ITU_T_CHOICEC_DECL(read, Read_Response, ConfirmedServiceResponse_read);
        ITU_T_CHOICEC_DECL(getVariableAccessAttributes, GetVariableAccessAttributes_Response, ConfirmedServiceResponse_getVariableAccessAttributes);
        ITU_T_CHOICES_DECL(defineNamedVariable, DefineNamedVariable_Response, ConfirmedServiceResponse_defineNamedVariable); // primitive
        ITU_T_CHOICES_DECL(defineScatteredAccess, ISO_9506_MMS_1A::DefineScatteredAccess_Response, ConfirmedServiceResponse_defineScatteredAccess); // primitive
        ITU_T_CHOICEC_DECL(getScatteredAccessAttributes, ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response, ConfirmedServiceResponse_getScatteredAccessAttributes);
        ITU_T_CHOICEC_DECL(deleteVariableAccess, DeleteVariableAccess_Response, ConfirmedServiceResponse_deleteVariableAccess);
        ITU_T_CHOICES_DECL(defineNamedVariableList, DefineNamedVariableList_Response, ConfirmedServiceResponse_defineNamedVariableList); // primitive
        ITU_T_CHOICEC_DECL(getNamedVariableListAttributes, GetNamedVariableListAttributes_Response, ConfirmedServiceResponse_getNamedVariableListAttributes);
        ITU_T_CHOICEC_DECL(deleteNamedVariableList, DeleteNamedVariableList_Response, ConfirmedServiceResponse_deleteNamedVariableList);
        ITU_T_CHOICES_DECL(defineNamedType, DefineNamedType_Response, ConfirmedServiceResponse_defineNamedType); // primitive
        ITU_T_CHOICEC_DECL(getNamedTypeAttributes, GetNamedTypeAttributes_Response, ConfirmedServiceResponse_getNamedTypeAttributes);
        ITU_T_CHOICEC_DECL(deleteNamedType, DeleteNamedType_Response, ConfirmedServiceResponse_deleteNamedType);
        ITU_T_CHOICES_DECL(input, Input_Response, ConfirmedServiceResponse_input); // primitive
        ITU_T_CHOICES_DECL(output, Output_Response, ConfirmedServiceResponse_output); // primitive
        ITU_T_CHOICEC_DECL(takeControl, TakeControl_Response, ConfirmedServiceResponse_takeControl);
        ITU_T_CHOICES_DECL(relinquishControl, RelinquishControl_Response, ConfirmedServiceResponse_relinquishControl); // primitive
        ITU_T_CHOICES_DECL(defineSemaphore, DefineSemaphore_Response, ConfirmedServiceResponse_defineSemaphore); // primitive
        ITU_T_CHOICES_DECL(deleteSemaphore, DeleteSemaphore_Response, ConfirmedServiceResponse_deleteSemaphore); // primitive
        ITU_T_CHOICEC_DECL(reportSemaphoreStatus, ReportSemaphoreStatus_Response, ConfirmedServiceResponse_reportSemaphoreStatus);
        ITU_T_CHOICEC_DECL(reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Response, ConfirmedServiceResponse_reportPoolSemaphoreStatus);
        ITU_T_CHOICEC_DECL(reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Response, ConfirmedServiceResponse_reportSemaphoreEntryStatus);
        ITU_T_CHOICES_DECL(initiateDownloadSequence, InitiateDownloadSequence_Response, ConfirmedServiceResponse_initiateDownloadSequence); // primitive
        ITU_T_CHOICEC_DECL(downloadSegment, DownloadSegment_Response, ConfirmedServiceResponse_downloadSegment);
        ITU_T_CHOICES_DECL(terminateDownloadSequence, TerminateDownloadSequence_Response, ConfirmedServiceResponse_terminateDownloadSequence); // primitive
        ITU_T_CHOICEC_DECL(initiateUploadSequence, InitiateUploadSequence_Response, ConfirmedServiceResponse_initiateUploadSequence);
        ITU_T_CHOICEC_DECL(uploadSegment, UploadSegment_Response, ConfirmedServiceResponse_uploadSegment);
        ITU_T_CHOICES_DECL(terminateUploadSequence, TerminateUploadSequence_Response, ConfirmedServiceResponse_terminateUploadSequence); // primitive
        ITU_T_CHOICES_DECL(requestDomainDownload, RequestDomainDownload_Response, ConfirmedServiceResponse_requestDomainDownload); // primitive
        ITU_T_CHOICES_DECL(requestDomainUpload, RequestDomainUpload_Response, ConfirmedServiceResponse_requestDomainUpload); // primitive
        ITU_T_CHOICES_DECL(loadDomainContent, LoadDomainContent_Response, ConfirmedServiceResponse_loadDomainContent); // primitive
        ITU_T_CHOICES_DECL(storeDomainContent, StoreDomainContent_Response, ConfirmedServiceResponse_storeDomainContent); // primitive
        ITU_T_CHOICES_DECL(deleteDomain, DeleteDomain_Response, ConfirmedServiceResponse_deleteDomain); // primitive
        ITU_T_CHOICEC_DECL(getDomainAttributes, GetDomainAttributes_Response, ConfirmedServiceResponse_getDomainAttributes);
        ITU_T_CHOICES_DECL(createProgramInvocation, CreateProgramInvocation_Response, ConfirmedServiceResponse_createProgramInvocation); // primitive
        ITU_T_CHOICES_DECL(deleteProgramInvocation, DeleteProgramInvocation_Response, ConfirmedServiceResponse_deleteProgramInvocation); // primitive
        ITU_T_CHOICES_DECL(start, Start_Response, ConfirmedServiceResponse_start); // primitive
        ITU_T_CHOICES_DECL(stop, Stop_Response, ConfirmedServiceResponse_stop); // primitive
        ITU_T_CHOICES_DECL(resume, Resume_Response, ConfirmedServiceResponse_resume); // primitive
        ITU_T_CHOICES_DECL(reset, Reset_Response, ConfirmedServiceResponse_reset); // primitive
        ITU_T_CHOICES_DECL(kill, Kill_Response, ConfirmedServiceResponse_kill); // primitive
        ITU_T_CHOICEC_DECL(getProgramInvocationAttributes, GetProgramInvocationAttributes_Response, ConfirmedServiceResponse_getProgramInvocationAttributes);
        ITU_T_CHOICES_DECL(obtainFile, ISO_9506_MMS_1A::ObtainFile_Response, ConfirmedServiceResponse_obtainFile); // primitive
        ITU_T_CHOICES_DECL(defineEventCondition, DefineEventCondition_Response, ConfirmedServiceResponse_defineEventCondition); // primitive
        ITU_T_CHOICES_DECL(deleteEventCondition, DeleteEventCondition_Response, ConfirmedServiceResponse_deleteEventCondition); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(getEventConditionAttributes, GetEventConditionAttributes_Response, ConfirmedServiceResponse_getEventConditionAttributes);
        ITU_T_CHOICEC_DECL(reportEventConditionStatus, ReportEventConditionStatus_Response, ConfirmedServiceResponse_reportEventConditionStatus);
        ITU_T_CHOICES_DECL(alterEventConditionMonitoring, AlterEventConditionMonitoring_Response, ConfirmedServiceResponse_alterEventConditionMonitoring); // primitive
        ITU_T_CHOICES_DECL(triggerEvent, TriggerEvent_Response, ConfirmedServiceResponse_triggerEvent); // primitive
        ITU_T_CHOICES_DECL(defineEventAction, DefineEventAction_Response, ConfirmedServiceResponse_defineEventAction); // primitive
        ITU_T_CHOICES_DECL(deleteEventAction, DeleteEventAction_Response, ConfirmedServiceResponse_deleteEventAction); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(getEventActionAttributes, GetEventActionAttributes_Response, ConfirmedServiceResponse_getEventActionAttributes);
        ITU_T_CHOICES_DECL(reportEventActionStatus, ReportEventActionStatus_Response, ConfirmedServiceResponse_reportEventActionStatus); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(defineEventEnrollment, DefineEventEnrollment_Response, ConfirmedServiceResponse_defineEventEnrollment); // primitive
        ITU_T_CHOICES_DECL(deleteEventEnrollment, DeleteEventEnrollment_Response, ConfirmedServiceResponse_deleteEventEnrollment); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(alterEventEnrollment, AlterEventEnrollment_Response, ConfirmedServiceResponse_alterEventEnrollment);
        ITU_T_CHOICEC_DECL(reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Response, ConfirmedServiceResponse_reportEventEnrollmentStatus);
        ITU_T_CHOICEC_DECL(getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Response, ConfirmedServiceResponse_getEventEnrollmentAttributes);
        ITU_T_CHOICES_DECL(acknowledgeEventNotification, AcknowledgeEventNotification_Response, ConfirmedServiceResponse_acknowledgeEventNotification); // primitive
        ITU_T_CHOICEC_DECL(getAlarmSummary, GetAlarmSummary_Response, ConfirmedServiceResponse_getAlarmSummary);
        ITU_T_CHOICEC_DECL(getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Response, ConfirmedServiceResponse_getAlarmEnrollmentSummary);
        ITU_T_CHOICEC_DECL(readJournal, ReadJournal_Response, ConfirmedServiceResponse_readJournal);
        ITU_T_CHOICES_DECL(writeJournal, WriteJournal_Response, ConfirmedServiceResponse_writeJournal); // primitive
        ITU_T_CHOICES_DECL(initializeJournal, InitializeJournal_Response, ConfirmedServiceResponse_initializeJournal); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICEC_DECL(reportJournalStatus, ReportJournalStatus_Response, ConfirmedServiceResponse_reportJournalStatus);
        ITU_T_CHOICES_DECL(createJournal, CreateJournal_Response, ConfirmedServiceResponse_createJournal); // primitive
        ITU_T_CHOICES_DECL(deleteJournal, DeleteJournal_Response, ConfirmedServiceResponse_deleteJournal); // primitive
        ITU_T_CHOICEC_DECL(getCapabilityList, GetCapabilityList_Response, ConfirmedServiceResponse_getCapabilityList);
        ITU_T_CHOICEC_DECL(fileOpen, ISO_9506_MMS_1A::FileOpen_Response, ConfirmedServiceResponse_fileOpen);
        ITU_T_CHOICEC_DECL(fileRead, ISO_9506_MMS_1A::FileRead_Response, ConfirmedServiceResponse_fileRead);
        ITU_T_CHOICES_DECL(fileClose, ISO_9506_MMS_1A::FileClose_Response, ConfirmedServiceResponse_fileClose); // primitive
        ITU_T_CHOICES_DECL(fileRename, ISO_9506_MMS_1A::FileRename_Response, ConfirmedServiceResponse_fileRename); // primitive
        ITU_T_CHOICES_DECL(fileDelete, ISO_9506_MMS_1A::FileDelete_Response, ConfirmedServiceResponse_fileDelete); // primitive
        ITU_T_CHOICEC_DECL(fileDirectory, ISO_9506_MMS_1A::FileDirectory_Response, ConfirmedServiceResponse_fileDirectory);
        ITU_T_CHOICEC_DECL(additionalService, AdditionalService_Response, ConfirmedServiceResponse_additionalService);
        ITU_T_CHOICEC_DECL(getDataExchangeAttributes, GetDataExchangeAttributes_Response, ConfirmedServiceResponse_getDataExchangeAttributes);
        ITU_T_CHOICEC_DECL(exchangeData, ExchangeData_Response, ConfirmedServiceResponse_exchangeData);
        ITU_T_CHOICES_DECL(defineAccessControlList, DefineAccessControlList_Response, ConfirmedServiceResponse_defineAccessControlList); // primitive
        ITU_T_CHOICEC_DECL(getAccessControlListAttributes, GetAccessControlListAttributes_Response, ConfirmedServiceResponse_getAccessControlListAttributes);
        ITU_T_CHOICEC_DECL(reportAccessControlledObjects, ReportAccessControlledObjects_Response, ConfirmedServiceResponse_reportAccessControlledObjects);
        ITU_T_CHOICES_DECL(deleteAccessControlList, DeleteAccessControlList_Response, ConfirmedServiceResponse_deleteAccessControlList); // primitive
        ITU_T_CHOICEC_DECL(changeAccessControl, ChangeAccessControl_Response, ConfirmedServiceResponse_changeAccessControl);

        ITU_T_ARCHIVE_FUNC;
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
        AdditionalService_Response_alterECLMonitoring,
    };

    struct AdditionalService_Response : public ITU_T_CHOICE(AdditionalService_Response_enum) {


        ITU_T_CHOICE_CTORS(AdditionalService_Response);

        ITU_T_CHOICES_DECL(vMDStop, VMDStop_Response, AdditionalService_Response_vMDStop); // primitive
        ITU_T_CHOICEC_DECL(vMDReset, VMDReset_Response, AdditionalService_Response_vMDReset);
        ITU_T_CHOICES_DECL(select, Select_Response, AdditionalService_Response_select); // primitive
        ITU_T_CHOICES_DECL(alterPI, AlterProgramInvocationAttributes_Response, AdditionalService_Response_alterPI); // primitive
        ITU_T_CHOICES_DECL(initiateUCLoad, InitiateUnitControlLoad_Response, AdditionalService_Response_initiateUCLoad); // primitive
        ITU_T_CHOICEC_DECL(uCLoad, UnitControlLoadSegment_Response, AdditionalService_Response_uCLoad);
        ITU_T_CHOICEC_DECL(uCUpload, UnitControlUpload_Response, AdditionalService_Response_uCUpload);
        ITU_T_CHOICES_DECL(startUC, StartUnitControl_Response, AdditionalService_Response_startUC); // primitive
        ITU_T_CHOICES_DECL(stopUC, StopUnitControl_Response, AdditionalService_Response_stopUC); // primitive
        ITU_T_CHOICES_DECL(createUC, CreateUnitControl_Response, AdditionalService_Response_createUC); // primitive
        ITU_T_CHOICES_DECL(addToUC, AddToUnitControl_Response, AdditionalService_Response_addToUC); // primitive
        ITU_T_CHOICES_DECL(removeFromUC, RemoveFromUnitControl_Response, AdditionalService_Response_removeFromUC); // primitive
        ITU_T_CHOICEC_DECL(getUCAttributes, GetUnitControlAttributes_Response, AdditionalService_Response_getUCAttributes);
        ITU_T_CHOICES_DECL(loadUCFromFile, LoadUnitControlFromFile_Response, AdditionalService_Response_loadUCFromFile); // primitive
        ITU_T_CHOICES_DECL(storeUCToFile, StoreUnitControlToFile_Response, AdditionalService_Response_storeUCToFile); // primitive
        ITU_T_CHOICES_DECL(deleteUC, DeleteUnitControl_Response, AdditionalService_Response_deleteUC); // primitive
        ITU_T_CHOICES_DECL(defineECL, DefineEventConditionList_Response, AdditionalService_Response_defineECL); // primitive
        ITU_T_CHOICES_DECL(deleteECL, DeleteEventConditionList_Response, AdditionalService_Response_deleteECL); // primitive
        ITU_T_CHOICES_DECL(addECLReference, AddEventConditionListReference_Response, AdditionalService_Response_addECLReference); // primitive
        ITU_T_CHOICES_DECL(removeECLReference, RemoveEventConditionListReference_Response, AdditionalService_Response_removeECLReference); // primitive
        ITU_T_CHOICEC_DECL(getECLAttributes, GetEventConditionListAttributes_Response, AdditionalService_Response_getECLAttributes);
        ITU_T_CHOICEC_DECL(reportECLStatus, ReportEventConditionListStatus_Response, AdditionalService_Response_reportECLStatus);
        ITU_T_CHOICES_DECL(alterECLMonitoring, AlterEventConditionListMonitoring_Response, AdditionalService_Response_alterECLMonitoring); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Response-Detail

    enum Response_Detail_enum {

        Response_Detail_null = 0,
        Response_Detail_otherRequests,
        Response_Detail_status,
        Response_Detail_getProgramInvocationAttributes,
        Response_Detail_getEventConditionAttributes,
    };

    struct Response_Detail : public ITU_T_CHOICE(Response_Detail_enum) {


        ITU_T_CHOICE_CTORS(Response_Detail);

        ITU_T_CHOICES_DECL(otherRequests, null_type, Response_Detail_otherRequests); // primitive
        ITU_T_CHOICEC_DECL(status, CS_Status_Response, Response_Detail_status);
        ITU_T_CHOICEC_DECL(getProgramInvocationAttributes, CS_GetProgramInvocationAttributes_Response, Response_Detail_getProgramInvocationAttributes);
        ITU_T_CHOICEC_DECL(getEventConditionAttributes, CS_GetEventConditionAttributes_Response, Response_Detail_getEventConditionAttributes);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Confirmed-ErrorPDU

    struct Confirmed_ErrorPDU {

        Confirmed_ErrorPDU();

        Confirmed_ErrorPDU(const Unsigned32& arg__invokeID,
                const ServiceError& arg__serviceError);

        Confirmed_ErrorPDU(shared_ptr< Unsigned32> arg__invokeID,
                shared_ptr< Unsigned32> arg__modifierPosition,
                shared_ptr< ServiceError> arg__serviceError);

        ITU_T_HOLDERH_DECL(invokeID, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(modifierPosition, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(serviceError, ServiceError);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ServiceError

    struct ServiceError {

        struct ErrorClass_type;
        struct ServiceSpecificInfo_type;

        enum ErrorClass_type_enum {

            ErrorClass_type_null = 0,
            ErrorClass_type_vmd_state,
            ErrorClass_type_application_reference,
            ErrorClass_type_definition,
            ErrorClass_type_resource,
            ErrorClass_type_service,
            ErrorClass_type_service_preempt,
            ErrorClass_type_time_resolution,
            ErrorClass_type_access,
            ErrorClass_type_initiate,
            ErrorClass_type_conclude,
            ErrorClass_type_cancel,
            ErrorClass_type_file,
            ErrorClass_type_others,
        };

        struct ErrorClass_type : public ITU_T_CHOICE(ErrorClass_type_enum) {

            static const uint8_t vmd_state_other;
            static const uint8_t vmd_state_vmd_state_conflict;
            static const uint8_t vmd_state_vmd_operational_problem;
            static const uint8_t vmd_state_domain_transfer_problem;
            static const uint8_t vmd_state_state_machine_id_invalid;

            static const uint8_t application_reference_other;
            static const uint8_t application_reference_application_unreachable;
            static const uint8_t application_reference_connection_lost;
            static const uint8_t application_reference_application_reference_invalid;
            static const uint8_t application_reference_context_unsupported;

            static const uint8_t definition_other;
            static const uint8_t definition_object_undefined;
            static const uint8_t definition_invalid_address;
            static const uint8_t definition_type_unsupported;
            static const uint8_t definition_type_inconsistent;
            static const uint8_t definition_object_exists;
            static const uint8_t definition_object_attribute_inconsistent;

            static const uint8_t resource_other;
            static const uint8_t resource_memory_unavailable;
            static const uint8_t resource_processor_resource_unavailable;
            static const uint8_t resource_mass_storage_unavailable;
            static const uint8_t resource_capability_unavailable;
            static const uint8_t resource_capability_unknown;

            static const uint8_t service_other;
            static const uint8_t service_primitives_out_of_sequence;
            static const uint8_t service_object_state_conflict;
            static const uint8_t service_continuation_invalid;
            static const uint8_t service_object_constraint_conflict;

            static const uint8_t service_preempt_other;
            static const uint8_t service_preempt_timeout;
            static const uint8_t service_preempt_deadlock;
            static const uint8_t service_preempt_cancel;

            static const uint8_t time_resolution_other;
            static const uint8_t time_resolution_unsupportable_time_resolution;

            static const uint8_t access_other;
            static const uint8_t access_object_access_unsupported;
            static const uint8_t access_object_non_existent;
            static const uint8_t access_object_access_denied;
            static const uint8_t access_object_invalidated;

            static const uint8_t initiate_other;
            static const uint8_t initiate_max_services_outstanding_calling_insufficient;
            static const uint8_t initiate_max_services_outstanding_called_insufficient;
            static const uint8_t initiate_service_CBB_insufficient;
            static const uint8_t initiate_parameter_CBB_insufficient;
            static const uint8_t initiate_nesting_level_insufficient;

            static const uint8_t conclude_other;
            static const uint8_t conclude_further_communication_required;

            static const uint8_t cancel_other;
            static const uint8_t cancel_invoke_id_unknown;
            static const uint8_t cancel_cancel_not_possible;

            static const uint8_t file_other;
            static const uint8_t file_filename_ambiguous;
            static const uint8_t file_file_busy;
            static const uint8_t file_filename_syntax_error;
            static const uint8_t file_content_type_invalid;
            static const uint8_t file_position_invalid;
            static const uint8_t file_file_access_denied;
            static const uint8_t file_file_non_existent;
            static const uint8_t file_duplicate_filename;
            static const uint8_t file_insufficient_space_in_filestore;


            ITU_T_CHOICE_CTORS(ErrorClass_type);

            ITU_T_CHOICES_DECL(vmd_state, uint8_t, ErrorClass_type_vmd_state); // primitive  //   Ic(  [ 0  ...   4 ]   
            ITU_T_CHOICES_DECL(application_reference, uint8_t, ErrorClass_type_application_reference); // primitive  //   Ic(  [ 0  ...   4 ]   
            ITU_T_CHOICES_DECL(definition, uint8_t, ErrorClass_type_definition); // primitive  //   Ic(  [ 0  ...   6 ]   
            ITU_T_CHOICES_DECL(resource, uint8_t, ErrorClass_type_resource); // primitive  //   Ic(  [ 0  ...   5 ]   
            ITU_T_CHOICES_DECL(service, uint8_t, ErrorClass_type_service); // primitive  //   Ic(  [ 0  ...   5 ]   
            ITU_T_CHOICES_DECL(service_preempt, uint8_t, ErrorClass_type_service_preempt); // primitive  //   Ic(  [ 0  ...   3 ]   
            ITU_T_CHOICES_DECL(time_resolution, uint8_t, ErrorClass_type_time_resolution); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(access, uint8_t, ErrorClass_type_access); // primitive  //   Ic(  [ 0  ...   4 ]   
            ITU_T_CHOICES_DECL(initiate, uint8_t, ErrorClass_type_initiate); // primitive  //   Ic(  [ 0  ...   7 ]   
            ITU_T_CHOICES_DECL(conclude, uint8_t, ErrorClass_type_conclude); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(cancel, uint8_t, ErrorClass_type_cancel); // primitive  //   Ic(  [ 0  ...   2 ]   
            ITU_T_CHOICES_DECL(file, uint8_t, ErrorClass_type_file); // primitive  //   Ic(  [ 0  ...   9 ]   
            ITU_T_CHOICES_DECL(others, integer_type, ErrorClass_type_others); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        enum ServiceSpecificInfo_type_enum {

            ServiceSpecificInfo_type_null = 0,
            ServiceSpecificInfo_type_obtainFile,
            ServiceSpecificInfo_type_start,
            ServiceSpecificInfo_type_stop,
            ServiceSpecificInfo_type_resume,
            ServiceSpecificInfo_type_reset,
            ServiceSpecificInfo_type_deleteVariableAccess,
            ServiceSpecificInfo_type_deleteNamedVariableList,
            ServiceSpecificInfo_type_deleteNamedType,
            ServiceSpecificInfo_type_defineEventEnrollment_Error,
            ServiceSpecificInfo_type_fileRename,
            ServiceSpecificInfo_type_additionalService,
            ServiceSpecificInfo_type_changeAccessControl,
        };

        struct ServiceSpecificInfo_type : public ITU_T_CHOICE(ServiceSpecificInfo_type_enum) {


            ITU_T_CHOICE_CTORS(ServiceSpecificInfo_type);

            ITU_T_CHOICES_DECL(obtainFile, ISO_9506_MMS_1A::ObtainFile_Error, ServiceSpecificInfo_type_obtainFile); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(start, Start_Error, ServiceSpecificInfo_type_start); // primitive  //   Ic(  [ 0  ...   8 ]   
            ITU_T_CHOICES_DECL(stop, Stop_Error, ServiceSpecificInfo_type_stop); // primitive  //   Ic(  [ 0  ...   8 ]   
            ITU_T_CHOICES_DECL(resume, Resume_Error, ServiceSpecificInfo_type_resume); // primitive  //   Ic(  [ 0  ...   8 ]   
            ITU_T_CHOICES_DECL(reset, Reset_Error, ServiceSpecificInfo_type_reset); // primitive  //   Ic(  [ 0  ...   8 ]   
            ITU_T_CHOICES_DECL(deleteVariableAccess, DeleteVariableAccess_Error, ServiceSpecificInfo_type_deleteVariableAccess); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
            ITU_T_CHOICES_DECL(deleteNamedVariableList, DeleteNamedVariableList_Error, ServiceSpecificInfo_type_deleteNamedVariableList); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
            ITU_T_CHOICES_DECL(deleteNamedType, DeleteNamedType_Error, ServiceSpecificInfo_type_deleteNamedType); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
            ITU_T_CHOICEC_DECL(defineEventEnrollment_Error, DefineEventEnrollment_Error, ServiceSpecificInfo_type_defineEventEnrollment_Error);
            ITU_T_CHOICES_DECL(fileRename, ISO_9506_MMS_1A::FileRename_Error, ServiceSpecificInfo_type_fileRename); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICEC_DECL(additionalService, AdditionalService_Error, ServiceSpecificInfo_type_additionalService);
            ITU_T_CHOICES_DECL(changeAccessControl, ChangeAccessControl_Error, ServiceSpecificInfo_type_changeAccessControl); // primitive  //   Ic(  [ 0  ...   2147483647 ]   

            ITU_T_ARCHIVE_FUNC;
        };


        ServiceError();

        ServiceError(const ErrorClass_type& arg__errorClass);

        ServiceError(shared_ptr< ErrorClass_type> arg__errorClass,
                shared_ptr< integer_type> arg__additionalCode,
                shared_ptr< visible_string> arg__additionalDescription,
                shared_ptr< ServiceSpecificInfo_type> arg__serviceSpecificInfo);

        ITU_T_HOLDERH_DECL(errorClass, ErrorClass_type);
        ITU_T_OPTIONAL_DECL(additionalCode, integer_type);
        ITU_T_OPTIONAL_DECL(additionalDescription, visible_string);
        ITU_T_OPTIONAL_DECL(serviceSpecificInfo, ServiceSpecificInfo_type);

        ITU_T_ARCHIVE_FUNC;
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
        AdditionalService_Error_loadUCFromFile,
    };

    struct AdditionalService_Error : public ITU_T_CHOICE(AdditionalService_Error_enum) {


        ITU_T_CHOICE_CTORS(AdditionalService_Error);

        ITU_T_CHOICEC_DECL(defineEcl, DefineEventConditionList_Error, AdditionalService_Error_defineEcl);
        ITU_T_CHOICEC_DECL(addECLReference, AddEventConditionListReference_Error, AdditionalService_Error_addECLReference);
        ITU_T_CHOICEC_DECL(removeECLReference, RemoveEventConditionListReference_Error, AdditionalService_Error_removeECLReference);
        ITU_T_CHOICEC_DECL(initiateUC, InitiateUnitControl_Error, AdditionalService_Error_initiateUC);
        ITU_T_CHOICEC_DECL(startUC, StartUnitControl_Error, AdditionalService_Error_startUC);
        ITU_T_CHOICEC_DECL(stopUC, StopUnitControl_Error, AdditionalService_Error_stopUC);
        ITU_T_CHOICEC_DECL(deleteUC, DeleteUnitControl_Error, AdditionalService_Error_deleteUC);
        ITU_T_CHOICEC_DECL(loadUCFromFile, LoadUnitControlFromFile_Error, AdditionalService_Error_loadUCFromFile);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ObjectName

    enum ObjectName_enum {

        ObjectName_null = 0,
        ObjectName_vmd_specific,
        ObjectName_domain_specific,
        ObjectName_aa_specific,
    };

    struct ObjectName : public ITU_T_CHOICE(ObjectName_enum) {


        struct Domain_specific_type;

        struct Domain_specific_type {

            Domain_specific_type();

            Domain_specific_type(const Identifier& arg__domainID,
                    const Identifier& arg__itemID);

            ITU_T_HOLDERH_DECL(domainID, Identifier);
            ITU_T_HOLDERH_DECL(itemID, Identifier);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(ObjectName);

        ITU_T_CHOICES_DECL(vmd_specific, Identifier, ObjectName_vmd_specific); // primitive
        ITU_T_CHOICEC_DECL(domain_specific, Domain_specific_type, ObjectName_domain_specific);
        ITU_T_CHOICES_DECL(aa_specific, Identifier, ObjectName_aa_specific); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ObjectClass

    enum ObjectClass_enum {

        ObjectClass_null = 0,
        ObjectClass_basicObjectClass,
        ObjectClass_csObjectClass,
    };

    struct ObjectClass : public ITU_T_CHOICE(ObjectClass_enum) {

        static const uint8_t basicObjectClass_namedVariable;
        static const uint8_t basicObjectClass_scatteredAccess;
        static const uint8_t basicObjectClass_namedVariableList;
        static const uint8_t basicObjectClass_namedType;
        static const uint8_t basicObjectClass_semaphore;
        static const uint8_t basicObjectClass_eventCondition;
        static const uint8_t basicObjectClass_eventAction;
        static const uint8_t basicObjectClass_eventEnrollment;
        static const uint8_t basicObjectClass_journal;
        static const uint8_t basicObjectClass_domain;
        static const uint8_t basicObjectClass_programInvocation;
        static const uint8_t basicObjectClass_operatorStation;
        static const uint8_t basicObjectClass_dataExchange;
        static const uint8_t basicObjectClass_accessControlList;

        static const uint8_t csObjectClass_eventConditionList;
        static const uint8_t csObjectClass_unitControl;


        ITU_T_CHOICE_CTORS(ObjectClass);

        ITU_T_CHOICES_DECL(basicObjectClass, uint8_t, ObjectClass_basicObjectClass); // primitive  //   Ic(  [ 0  ...   13 ]   
        ITU_T_CHOICES_DECL(csObjectClass, uint8_t, ObjectClass_csObjectClass); // primitive  //   Ic(  [ 0  ...   1 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Initiate-RequestPDU

    struct Initiate_RequestPDU {

        struct InitRequestDetail_type;

        struct InitRequestDetail_type {

            InitRequestDetail_type();

            InitRequestDetail_type(const Integer16& arg__proposedVersionNumber,
                    const MMS_Object_Module_1::ParameterSupportOptions& arg__proposedParameterCBB,
                    const MMS_Object_Module_1::ServiceSupportOptions& arg__servicesSupportedCalling);

            InitRequestDetail_type(shared_ptr< Integer16> arg__proposedVersionNumber,
                    shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> arg__proposedParameterCBB,
                    shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> arg__servicesSupportedCalling,
                    shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> arg__additionalSupportedCalling = shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions>(),
                    shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> arg__additionalCbbSupportedCalling = shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions>(),
                    shared_ptr< visible_string> arg__privilegeClassIdentityCalling = shared_ptr< visible_string>());

            ITU_T_HOLDERH_DECL(proposedVersionNumber, Integer16); //   Ic(  [ -32768  ...   32767 ]   
            ITU_T_HOLDERH_DECL(proposedParameterCBB, MMS_Object_Module_1::ParameterSupportOptions); //    Sc (  [ 18 ]   
            ITU_T_HOLDERH_DECL(servicesSupportedCalling, MMS_Object_Module_1::ServiceSupportOptions); //    Sc (  [ 93 ]   
            ITU_T_OPTIONAL_DECL(additionalSupportedCalling, MMS_Object_Module_1::AdditionalSupportOptions); //    Sc (  [ 23 ]   
            ITU_T_OPTIONAL_DECL(additionalCbbSupportedCalling, MMS_Object_Module_1::AdditionalCBBOptions); //    Sc (  [ 3 ]   
            ITU_T_OPTIONAL_DECL(privilegeClassIdentityCalling, visible_string);

            ITU_T_ARCHIVE_FUNC;
        };


        Initiate_RequestPDU();

        Initiate_RequestPDU(const Integer16& arg__proposedMaxServOutstandingCalling,
                const Integer16& arg__proposedMaxServOutstandingCalled,
                const InitRequestDetail_type& arg__initRequestDetail);

        Initiate_RequestPDU(shared_ptr< Integer32> arg__localDetailCalling,
                shared_ptr< Integer16> arg__proposedMaxServOutstandingCalling,
                shared_ptr< Integer16> arg__proposedMaxServOutstandingCalled,
                shared_ptr< Integer8> arg__proposedDataStructureNestingLevel,
                shared_ptr< InitRequestDetail_type> arg__initRequestDetail);

        ITU_T_OPTIONAL_DECL(localDetailCalling, Integer32); //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(proposedMaxServOutstandingCalling, Integer16); //   Ic(  [ -32768  ...   32767 ]   
        ITU_T_HOLDERH_DECL(proposedMaxServOutstandingCalled, Integer16); //   Ic(  [ -32768  ...   32767 ]   
        ITU_T_OPTIONAL_DECL(proposedDataStructureNestingLevel, Integer8); //   Ic(  [ -128  ...   127 ]   
        ITU_T_HOLDERH_DECL(initRequestDetail, InitRequestDetail_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Initiate-ResponsePDU

    struct Initiate_ResponsePDU {

        struct InitResponseDetail_type;

        struct InitResponseDetail_type {

            InitResponseDetail_type();

            InitResponseDetail_type(const Integer16& arg__negotiatedVersionNumber,
                    const MMS_Object_Module_1::ParameterSupportOptions& arg__negotiatedParameterCBB,
                    const MMS_Object_Module_1::ServiceSupportOptions& arg__servicesSupportedCalled);

            InitResponseDetail_type(shared_ptr< Integer16> arg__negotiatedVersionNumber,
                    shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> arg__negotiatedParameterCBB,
                    shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> arg__servicesSupportedCalled,
                    shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> arg__additionalSupportedCalled = shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions>(),
                    shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> arg__additionalCbbSupportedCalled = shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions>(),
                    shared_ptr< visible_string> arg__privilegeClassIdentityCalled = shared_ptr< visible_string>());

            ITU_T_HOLDERH_DECL(negotiatedVersionNumber, Integer16); //   Ic(  [ -32768  ...   32767 ]   
            ITU_T_HOLDERH_DECL(negotiatedParameterCBB, MMS_Object_Module_1::ParameterSupportOptions); //    Sc (  [ 18 ]   
            ITU_T_HOLDERH_DECL(servicesSupportedCalled, MMS_Object_Module_1::ServiceSupportOptions); //    Sc (  [ 93 ]   
            ITU_T_OPTIONAL_DECL(additionalSupportedCalled, MMS_Object_Module_1::AdditionalSupportOptions); //    Sc (  [ 23 ]   
            ITU_T_OPTIONAL_DECL(additionalCbbSupportedCalled, MMS_Object_Module_1::AdditionalCBBOptions); //    Sc (  [ 3 ]   
            ITU_T_OPTIONAL_DECL(privilegeClassIdentityCalled, visible_string);

            ITU_T_ARCHIVE_FUNC;
        };


        Initiate_ResponsePDU();

        Initiate_ResponsePDU(const Integer16& arg__negotiatedMaxServOutstandingCalling,
                const Integer16& arg__negotiatedMaxServOutstandingCalled,
                const InitResponseDetail_type& arg__initResponseDetail);

        Initiate_ResponsePDU(shared_ptr< Integer32> arg__localDetailCalled,
                shared_ptr< Integer16> arg__negotiatedMaxServOutstandingCalling,
                shared_ptr< Integer16> arg__negotiatedMaxServOutstandingCalled,
                shared_ptr< Integer8> arg__negotiatedDataStructureNestingLevel,
                shared_ptr< InitResponseDetail_type> arg__initResponseDetail);

        ITU_T_OPTIONAL_DECL(localDetailCalled, Integer32); //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(negotiatedMaxServOutstandingCalling, Integer16); //   Ic(  [ -32768  ...   32767 ]   
        ITU_T_HOLDERH_DECL(negotiatedMaxServOutstandingCalled, Integer16); //   Ic(  [ -32768  ...   32767 ]   
        ITU_T_OPTIONAL_DECL(negotiatedDataStructureNestingLevel, Integer8); //   Ic(  [ -128  ...   127 ]   
        ITU_T_HOLDERH_DECL(initResponseDetail, InitResponseDetail_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Cancel-ErrorPDU

    struct Cancel_ErrorPDU {

        Cancel_ErrorPDU();

        Cancel_ErrorPDU(const Unsigned32& arg__originalInvokeID,
                const ServiceError& arg__serviceError);

        ITU_T_HOLDERH_DECL(originalInvokeID, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(serviceError, ServiceError);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RejectPDU

    struct RejectPDU {

        struct RejectReason_type;

        enum RejectReason_type_enum {

            RejectReason_type_null = 0,
            RejectReason_type_confirmed_requestPDU,
            RejectReason_type_confirmed_responsePDU,
            RejectReason_type_confirmed_errorPDU,
            RejectReason_type_unconfirmedPDU,
            RejectReason_type_pdu_error,
            RejectReason_type_cancel_requestPDU,
            RejectReason_type_cancel_responsePDU,
            RejectReason_type_cancel_errorPDU,
            RejectReason_type_conclude_requestPDU,
            RejectReason_type_conclude_responsePDU,
            RejectReason_type_conclude_errorPDU,
        };

        struct RejectReason_type : public ITU_T_CHOICE(RejectReason_type_enum) {

            static const uint8_t confirmed_requestPDU_other;
            static const uint8_t confirmed_requestPDU_unrecognized_service;
            static const uint8_t confirmed_requestPDU_unrecognized_modifier;
            static const uint8_t confirmed_requestPDU_invalid_invokeID;
            static const uint8_t confirmed_requestPDU_invalid_argument;
            static const uint8_t confirmed_requestPDU_invalid_modifier;
            static const uint8_t confirmed_requestPDU_max_serv_outstanding_exceeded;
            static const uint8_t confirmed_requestPDU_max_recursion_exceeded;
            static const uint8_t confirmed_requestPDU_value_out_of_range;

            static const uint8_t confirmed_responsePDU_other;
            static const uint8_t confirmed_responsePDU_unrecognized_service;
            static const uint8_t confirmed_responsePDU_invalid_invokeID;
            static const uint8_t confirmed_responsePDU_invalid_result;
            static const uint8_t confirmed_responsePDU_max_recursion_exceeded;
            static const uint8_t confirmed_responsePDU_value_out_of_range;

            static const uint8_t confirmed_errorPDU_other;
            static const uint8_t confirmed_errorPDU_unrecognized_service;
            static const uint8_t confirmed_errorPDU_invalid_invokeID;
            static const uint8_t confirmed_errorPDU_invalid_serviceError;
            static const uint8_t confirmed_errorPDU_value_out_of_range;

            static const uint8_t unconfirmedPDU_other;
            static const uint8_t unconfirmedPDU_unrecognized_service;
            static const uint8_t unconfirmedPDU_invalid_argument;
            static const uint8_t unconfirmedPDU_max_recursion_exceeded;
            static const uint8_t unconfirmedPDU_value_out_of_range;

            static const integer_type pdu_error_unknown_pdu_type;
            static const integer_type pdu_error_invalid_pdu;
            static const integer_type pdu_error_illegal_acse_mapping;

            static const uint8_t cancel_requestPDU_other;
            static const uint8_t cancel_requestPDU_invalid_invokeID;

            static const uint8_t cancel_responsePDU_other;
            static const uint8_t cancel_responsePDU_invalid_invokeID;

            static const uint8_t cancel_errorPDU_other;
            static const uint8_t cancel_errorPDU_invalid_invokeID;
            static const uint8_t cancel_errorPDU_invalid_serviceError;
            static const uint8_t cancel_errorPDU_value_out_of_range;

            static const uint8_t conclude_requestPDU_other;
            static const uint8_t conclude_requestPDU_invalid_argument;

            static const uint8_t conclude_responsePDU_other;
            static const uint8_t conclude_responsePDU_invalid_result;

            static const uint8_t conclude_errorPDU_other;
            static const uint8_t conclude_errorPDU_invalid_serviceError;
            static const uint8_t conclude_errorPDU_value_out_of_range;


            ITU_T_CHOICE_CTORS(RejectReason_type);

            ITU_T_CHOICES_DECL(confirmed_requestPDU, uint8_t, RejectReason_type_confirmed_requestPDU); // primitive  //   Ic(  [ 0  ...   9 ]   
            ITU_T_CHOICES_DECL(confirmed_responsePDU, uint8_t, RejectReason_type_confirmed_responsePDU); // primitive  //   Ic(  [ 0  ...   6 ]   
            ITU_T_CHOICES_DECL(confirmed_errorPDU, uint8_t, RejectReason_type_confirmed_errorPDU); // primitive  //   Ic(  [ 0  ...   4 ]   
            ITU_T_CHOICES_DECL(unconfirmedPDU, uint8_t, RejectReason_type_unconfirmedPDU); // primitive  //   Ic(  [ 0  ...   4 ]   
            ITU_T_CHOICES_DECL(pdu_error, integer_type, RejectReason_type_pdu_error); // primitive
            ITU_T_CHOICES_DECL(cancel_requestPDU, uint8_t, RejectReason_type_cancel_requestPDU); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(cancel_responsePDU, uint8_t, RejectReason_type_cancel_responsePDU); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(cancel_errorPDU, uint8_t, RejectReason_type_cancel_errorPDU); // primitive  //   Ic(  [ 0  ...   3 ]   
            ITU_T_CHOICES_DECL(conclude_requestPDU, uint8_t, RejectReason_type_conclude_requestPDU); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(conclude_responsePDU, uint8_t, RejectReason_type_conclude_responsePDU); // primitive  //   Ic(  [ 0  ...   1 ]   
            ITU_T_CHOICES_DECL(conclude_errorPDU, uint8_t, RejectReason_type_conclude_errorPDU); // primitive  //   Ic(  [ 0  ...   2 ]   

            ITU_T_ARCHIVE_FUNC;
        };


        RejectPDU();

        RejectPDU(const RejectReason_type& arg__rejectReason);

        RejectPDU(shared_ptr< Unsigned32> arg__originalInvokeID,
                shared_ptr< RejectReason_type> arg__rejectReason);

        ITU_T_OPTIONAL_DECL(originalInvokeID, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(rejectReason, RejectReason_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineAccessControlList-Request

    struct DefineAccessControlList_Request {

        struct AccessControlListElements_type;

        struct AccessControlListElements_type {

            AccessControlListElements_type();

            AccessControlListElements_type(shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition);

            ITU_T_OPTIONAL_DECL(readAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(storeAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(writeAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(loadAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(executeAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(editAccessCondition, MMS_Object_Module_1::AccessCondition);

            ITU_T_ARCHIVE_FUNC;
        };


        DefineAccessControlList_Request();

        DefineAccessControlList_Request(const Identifier& arg__accessControlListName,
                const AccessControlListElements_type& arg__accessControlListElements);

        ITU_T_HOLDERH_DECL(accessControlListName, Identifier);
        ITU_T_HOLDERH_DECL(accessControlListElements, AccessControlListElements_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice GetAccessControlListAttributes-Request

    enum GetAccessControlListAttributes_Request_enum {

        GetAccessControlListAttributes_Request_null = 0,
        GetAccessControlListAttributes_Request_accessControlListName,
        GetAccessControlListAttributes_Request_vMD,
        GetAccessControlListAttributes_Request_namedObject,
    };

    struct GetAccessControlListAttributes_Request : public ITU_T_CHOICE(GetAccessControlListAttributes_Request_enum) {


        struct NamedObject_type;

        struct NamedObject_type {

            NamedObject_type();

            NamedObject_type(const ObjectClass& arg__objectClass,
                    const ObjectName& arg__objectName);

            ITU_T_HOLDERH_DECL(objectClass, ObjectClass);
            ITU_T_HOLDERH_DECL(objectName, ObjectName);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(GetAccessControlListAttributes_Request);

        ITU_T_CHOICES_DECL(accessControlListName, Identifier, GetAccessControlListAttributes_Request_accessControlListName); // primitive
        ITU_T_CHOICES_DECL(vMD, null_type, GetAccessControlListAttributes_Request_vMD); // primitive
        ITU_T_CHOICEC_DECL(namedObject, NamedObject_type, GetAccessControlListAttributes_Request_namedObject);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetAccessControlListAttributes-Response

    struct GetAccessControlListAttributes_Response {

        struct AccessControlListElements_type;
        struct References_type_sequence_of;

        struct AccessControlListElements_type {

            AccessControlListElements_type();

            AccessControlListElements_type(shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
                    shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition);

            ITU_T_OPTIONAL_DECL(readAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(storeAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(writeAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(loadAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(executeAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
            ITU_T_OPTIONAL_DECL(editAccessCondition, MMS_Object_Module_1::AccessCondition);

            ITU_T_ARCHIVE_FUNC;
        };

        struct References_type_sequence_of {

            References_type_sequence_of();

            References_type_sequence_of(const ObjectClass& arg__objectClass,
                    const integer_type& arg__objectCount);

            ITU_T_HOLDERH_DECL(objectClass, ObjectClass);
            ITU_T_HOLDERH_DECL(objectCount, integer_type);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< References_type_sequence_of > References_type;


        GetAccessControlListAttributes_Response();

        GetAccessControlListAttributes_Response(const Identifier& arg__name,
                const AccessControlListElements_type& arg__accessControlListElements,
                const bool& arg__vMDuse,
                const References_type& arg__references);

        GetAccessControlListAttributes_Response(shared_ptr< Identifier> arg__name,
                shared_ptr< AccessControlListElements_type> arg__accessControlListElements,
                shared_ptr< bool> arg__vMDuse,
                shared_ptr< References_type> arg__references,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(name, Identifier);
        ITU_T_HOLDERH_DECL(accessControlListElements, AccessControlListElements_type);
        ITU_T_HOLDERH_DECL(vMDuse, bool);
        ITU_T_HOLDERH_DECL(references, References_type);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportAccessControlledObjects-Request

    struct ReportAccessControlledObjects_Request {

        ReportAccessControlledObjects_Request();

        ReportAccessControlledObjects_Request(const Identifier& arg__accessControlList,
                const ObjectClass& arg__objectClass);

        ReportAccessControlledObjects_Request(shared_ptr< Identifier> arg__accessControlList,
                shared_ptr< ObjectClass> arg__objectClass,
                shared_ptr< ObjectName> arg__continueAfter);

        ITU_T_HOLDERH_DECL(accessControlList, Identifier);
        ITU_T_HOLDERH_DECL(objectClass, ObjectClass);
        ITU_T_OPTIONAL_DECL(continueAfter, ObjectName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportAccessControlledObjects-Response

    struct ReportAccessControlledObjects_Response {

        typedef sequence_of< ObjectName > ListOfNames_type;

        static const bool moreFollows__default;

        ReportAccessControlledObjects_Response();

        ReportAccessControlledObjects_Response(const ListOfNames_type& arg__listOfNames);

        ReportAccessControlledObjects_Response(shared_ptr< ListOfNames_type> arg__listOfNames,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfNames, ListOfNames_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ChangeAccessControl-Request

    struct ChangeAccessControl_Request {

        struct ScopeOfChange_type;

        enum ScopeOfChange_type_enum {

            ScopeOfChange_type_null = 0,
            ScopeOfChange_type_vMDOnly,
            ScopeOfChange_type_listOfObjects,
        };

        struct ScopeOfChange_type : public ITU_T_CHOICE(ScopeOfChange_type_enum) {


            struct ListOfObjects_type;

            struct ListOfObjects_type {

                struct ObjectScope_type;

                enum ObjectScope_type_enum {

                    ObjectScope_type_null = 0,
                    ObjectScope_type_specific,
                    ObjectScope_type_aa_specific,
                    ObjectScope_type_domain,
                    ObjectScope_type_vmd,
                };

                struct ObjectScope_type : public ITU_T_CHOICE(ObjectScope_type_enum) {



                    typedef sequence_of< ObjectName > Specific_type;


                    ITU_T_CHOICE_CTORS(ObjectScope_type);

                    ITU_T_CHOICEC_DECL(specific, Specific_type, ObjectScope_type_specific);
                    ITU_T_CHOICES_DECL(aa_specific, null_type, ObjectScope_type_aa_specific); // primitive
                    ITU_T_CHOICES_DECL(domain, Identifier, ObjectScope_type_domain); // primitive
                    ITU_T_CHOICES_DECL(vmd, null_type, ObjectScope_type_vmd); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };


                ListOfObjects_type();

                ListOfObjects_type(const ObjectClass& arg__objectClass,
                        const ObjectScope_type& arg__objectScope);

                ITU_T_HOLDERH_DECL(objectClass, ObjectClass);
                ITU_T_HOLDERH_DECL(objectScope, ObjectScope_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(ScopeOfChange_type);

            ITU_T_CHOICES_DECL(vMDOnly, null_type, ScopeOfChange_type_vMDOnly); // primitive
            ITU_T_CHOICEC_DECL(listOfObjects, ListOfObjects_type, ScopeOfChange_type_listOfObjects);

            ITU_T_ARCHIVE_FUNC;
        };


        ChangeAccessControl_Request();

        ChangeAccessControl_Request(const ScopeOfChange_type& arg__scopeOfChange,
                const Identifier& arg__accessControlListName);

        ITU_T_HOLDERH_DECL(scopeOfChange, ScopeOfChange_type);
        ITU_T_HOLDERH_DECL(accessControlListName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ChangeAccessControl-Response

    struct ChangeAccessControl_Response {

        ChangeAccessControl_Response();

        ChangeAccessControl_Response(const Unsigned32& arg__numberMatched,
                const Unsigned32& arg__numberChanged);

        ITU_T_HOLDERH_DECL(numberMatched, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(numberChanged, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence StatusResponse

    struct StatusResponse {

        static const uint8_t vmdLogicalStatus_state_changes_allowed;
        static const uint8_t vmdLogicalStatus_no_state_changes_allowed;
        static const uint8_t vmdLogicalStatus_limited_services_permitted;
        static const uint8_t vmdLogicalStatus_support_services_allowed;

        static const uint8_t vmdPhysicalStatus_operational;
        static const uint8_t vmdPhysicalStatus_partially_operational;
        static const uint8_t vmdPhysicalStatus_inoperable;
        static const uint8_t vmdPhysicalStatus_needs_commissioning;


        StatusResponse();

        StatusResponse(const uint8_t& arg__vmdLogicalStatus,
                const uint8_t& arg__vmdPhysicalStatus);

        StatusResponse(shared_ptr< uint8_t> arg__vmdLogicalStatus,
                shared_ptr< uint8_t> arg__vmdPhysicalStatus,
                shared_ptr< bit_string> arg__localDetail);

        ITU_T_HOLDERH_DECL(vmdLogicalStatus, uint8_t); //   Ic(  [ 0  ...   3 ]   
        ITU_T_HOLDERH_DECL(vmdPhysicalStatus, uint8_t); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(localDetail, bit_string); //    Sc (  [ 0  ...   128 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CS-Status-Response

    enum CS_Status_Response_enum {

        CS_Status_Response_null = 0,
        CS_Status_Response_fullResponse,
        CS_Status_Response_noExtraResponse,
    };

    struct CS_Status_Response : public ITU_T_CHOICE(CS_Status_Response_enum) {


        struct FullResponse_type;

        struct FullResponse_type {

            struct SelectedProgramInvocation_type;

            enum SelectedProgramInvocation_type_enum {

                SelectedProgramInvocation_type_null = 0,
                SelectedProgramInvocation_type_programInvocation,
                SelectedProgramInvocation_type_noneSelected,
            };

            struct SelectedProgramInvocation_type : public ITU_T_CHOICE(SelectedProgramInvocation_type_enum) {


                ITU_T_CHOICE_CTORS(SelectedProgramInvocation_type);

                ITU_T_CHOICES_DECL(programInvocation, Identifier, SelectedProgramInvocation_type_programInvocation); // primitive
                ITU_T_CHOICES_DECL(noneSelected, null_type, SelectedProgramInvocation_type_noneSelected); // primitive

                ITU_T_ARCHIVE_FUNC;
            };

            static const ExtendedStatus extendedStatusMask__default;

            FullResponse_type();

            FullResponse_type(const OperationState& arg__operationState,
                    const ExtendedStatus& arg__extendedStatus,
                    const SelectedProgramInvocation_type& arg__selectedProgramInvocation);

            FullResponse_type(shared_ptr< OperationState> arg__operationState,
                    shared_ptr< ExtendedStatus> arg__extendedStatus,
                    shared_ptr< ExtendedStatus> arg__extendedStatusMask,
                    shared_ptr< SelectedProgramInvocation_type> arg__selectedProgramInvocation);

            ITU_T_HOLDERH_DECL(operationState, OperationState); //   Ic(  [ 0  ...   5 ]   
            ITU_T_HOLDERH_DECL(extendedStatus, ExtendedStatus); //    Sc (  [ 4 ]   
            ITU_T_DEFAULTH_DECL(extendedStatusMask, ExtendedStatus, extendedStatusMask__default); //    Sc (  [ 4 ]   
            ITU_T_HOLDERH_DECL(selectedProgramInvocation, SelectedProgramInvocation_type);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(CS_Status_Response);

        ITU_T_CHOICEC_DECL(fullResponse, FullResponse_type, CS_Status_Response_fullResponse);
        ITU_T_CHOICES_DECL(noExtraResponse, null_type, CS_Status_Response_noExtraResponse); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    const OperationState operationState_idle = 0;
    const OperationState operationState_loaded = 1;
    const OperationState operationState_ready = 2;
    const OperationState operationState_executing = 3;
    const OperationState operationState_motion_paused = 4;
    const OperationState operationState_manualInterventionRequired = 5;

    const ExtendedStatus extendedStatus_safetyInterlocksViolated = bit_string(true, 0);
    const ExtendedStatus extendedStatus_anyPhysicalResourcePowerOn = bit_string(true, 1);
    const ExtendedStatus extendedStatus_allPhysicalResourcesCalibrated = bit_string(true, 2);
    const ExtendedStatus extendedStatus_localControl = bit_string(true, 3);

    // sequence GetNameList-Request

    struct GetNameList_Request {

        struct ObjectScope_type;

        enum ObjectScope_type_enum {

            ObjectScope_type_null = 0,
            ObjectScope_type_vmdSpecific,
            ObjectScope_type_domainSpecific,
            ObjectScope_type_aaSpecific,
        };

        struct ObjectScope_type : public ITU_T_CHOICE(ObjectScope_type_enum) {


            ITU_T_CHOICE_CTORS(ObjectScope_type);

            ITU_T_CHOICES_DECL(vmdSpecific, null_type, ObjectScope_type_vmdSpecific); // primitive
            ITU_T_CHOICES_DECL(domainSpecific, Identifier, ObjectScope_type_domainSpecific); // primitive
            ITU_T_CHOICES_DECL(aaSpecific, null_type, ObjectScope_type_aaSpecific); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        GetNameList_Request();

        GetNameList_Request(const ObjectClass& arg__objectClass,
                const ObjectScope_type& arg__objectScope);

        GetNameList_Request(shared_ptr< ObjectClass> arg__objectClass,
                shared_ptr< ObjectScope_type> arg__objectScope,
                shared_ptr< Identifier> arg__continueAfter);

        ITU_T_HOLDERH_DECL(objectClass, ObjectClass);
        ITU_T_HOLDERH_DECL(objectScope, ObjectScope_type);
        ITU_T_OPTIONAL_DECL(continueAfter, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetNameList-Response

    struct GetNameList_Response {

        typedef sequence_of< Identifier > ListOfIdentifier_type;

        static const bool moreFollows__default;

        GetNameList_Response();

        GetNameList_Response(const ListOfIdentifier_type& arg__listOfIdentifier);

        GetNameList_Response(shared_ptr< ListOfIdentifier_type> arg__listOfIdentifier,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfIdentifier, ListOfIdentifier_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Identify-Response

    struct Identify_Response {

        typedef sequence_of< oid_type > ListOfAbstractSyntaxes_type;


        Identify_Response();

        Identify_Response(const MMSString& arg__vendorName,
                const MMSString& arg__modelName,
                const MMSString& arg__revision);

        Identify_Response(shared_ptr< MMSString> arg__vendorName,
                shared_ptr< MMSString> arg__modelName,
                shared_ptr< MMSString> arg__revision,
                shared_ptr< ListOfAbstractSyntaxes_type> arg__listOfAbstractSyntaxes);

        ITU_T_HOLDERH_DECL(vendorName, MMSString);
        ITU_T_HOLDERH_DECL(modelName, MMSString);
        ITU_T_HOLDERH_DECL(revision, MMSString);
        ITU_T_OPTIONAL_DECL(listOfAbstractSyntaxes, ListOfAbstractSyntaxes_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Rename-Request

    struct Rename_Request {

        Rename_Request();

        Rename_Request(const ObjectClass& arg__objectClass,
                const ObjectName& arg__currentName,
                const Identifier& arg__newIdentifier);

        ITU_T_HOLDERH_DECL(objectClass, ObjectClass);
        ITU_T_HOLDERH_DECL(currentName, ObjectName);
        ITU_T_HOLDERH_DECL(newIdentifier, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetCapabilityList-Request

    struct GetCapabilityList_Request {

        GetCapabilityList_Request();

        GetCapabilityList_Request(shared_ptr< MMSString> arg__continueAfter);

        ITU_T_OPTIONAL_DECL(continueAfter, MMSString);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetCapabilityList-Response

    struct GetCapabilityList_Response {

        typedef sequence_of< MMSString > ListOfCapabilities_type;

        static const bool moreFollows__default;

        GetCapabilityList_Response();

        GetCapabilityList_Response(const ListOfCapabilities_type& arg__listOfCapabilities);

        GetCapabilityList_Response(shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfCapabilities, ListOfCapabilities_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence InitiateDownloadSequence-Request

    struct InitiateDownloadSequence_Request {

        typedef sequence_of< MMSString > ListOfCapabilities_type;


        InitiateDownloadSequence_Request();

        InitiateDownloadSequence_Request(const Identifier& arg__domainName,
                const ListOfCapabilities_type& arg__listOfCapabilities,
                const bool& arg__sharable);

        ITU_T_HOLDERH_DECL(domainName, Identifier);
        ITU_T_HOLDERH_DECL(listOfCapabilities, ListOfCapabilities_type);
        ITU_T_HOLDERH_DECL(sharable, bool);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DownloadSegment-Response

    struct DownloadSegment_Response {

        static const bool moreFollows__default;

        DownloadSegment_Response();

        DownloadSegment_Response(const LoadData& arg__loadData);

        DownloadSegment_Response(shared_ptr< LoadData> arg__loadData,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(loadData, LoadData);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice LoadData

    enum LoadData_enum {

        LoadData_null = 0,
        LoadData_non_coded,
        LoadData_coded,
        LoadData_embedded,
    };

    struct LoadData : public ITU_T_CHOICE(LoadData_enum) {


        ITU_T_CHOICE_CTORS(LoadData);

        ITU_T_CHOICES_DECL(non_coded, octet_string, LoadData_non_coded); // primitive
        ITU_T_CHOICES_DECL(coded, external_type, LoadData_coded); // primitive
        ITU_T_CHOICES_DECL(embedded, embeded_pdv, LoadData_embedded); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence TerminateDownloadSequence-Request

    struct TerminateDownloadSequence_Request {

        TerminateDownloadSequence_Request();

        TerminateDownloadSequence_Request(const Identifier& arg__domainName);

        TerminateDownloadSequence_Request(shared_ptr< Identifier> arg__domainName,
                shared_ptr< ServiceError> arg__discard);

        ITU_T_HOLDERH_DECL(domainName, Identifier);
        ITU_T_OPTIONAL_DECL(discard, ServiceError);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence InitiateUploadSequence-Response

    struct InitiateUploadSequence_Response {

        typedef sequence_of< MMSString > ListOfCapabilities_type;


        InitiateUploadSequence_Response();

        InitiateUploadSequence_Response(const Integer32& arg__ulsmID,
                const ListOfCapabilities_type& arg__listOfCapabilities);

        ITU_T_HOLDERH_DECL(ulsmID, Integer32); //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(listOfCapabilities, ListOfCapabilities_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence UploadSegment-Response

    struct UploadSegment_Response {

        static const bool moreFollows__default;

        UploadSegment_Response();

        UploadSegment_Response(const LoadData& arg__loadData);

        UploadSegment_Response(shared_ptr< LoadData> arg__loadData,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(loadData, LoadData);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RequestDomainDownload-Request

    struct RequestDomainDownload_Request {

        typedef sequence_of< MMSString > ListOfCapabilities_type;


        RequestDomainDownload_Request();

        RequestDomainDownload_Request(const Identifier& arg__domainName,
                const bool& arg__sharable,
                const FileName& arg__fileName);

        RequestDomainDownload_Request(shared_ptr< Identifier> arg__domainName,
                shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
                shared_ptr< bool> arg__sharable,
                shared_ptr< FileName> arg__fileName);

        ITU_T_HOLDERH_DECL(domainName, Identifier);
        ITU_T_OPTIONAL_DECL(listOfCapabilities, ListOfCapabilities_type);
        ITU_T_HOLDERH_DECL(sharable, bool);
        ITU_T_HOLDERH_DECL(fileName, FileName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RequestDomainUpload-Request

    struct RequestDomainUpload_Request {

        RequestDomainUpload_Request();

        RequestDomainUpload_Request(const Identifier& arg__domainName,
                const FileName& arg__fileName);

        ITU_T_HOLDERH_DECL(domainName, Identifier);
        ITU_T_HOLDERH_DECL(fileName, FileName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence LoadDomainContent-Request

    struct LoadDomainContent_Request {

        typedef sequence_of< MMSString > ListOfCapabilities_type;


        LoadDomainContent_Request();

        LoadDomainContent_Request(const Identifier& arg__domainName,
                const bool& arg__sharable,
                const FileName& arg__fileName);

        LoadDomainContent_Request(shared_ptr< Identifier> arg__domainName,
                shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
                shared_ptr< bool> arg__sharable,
                shared_ptr< FileName> arg__fileName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty);

        ITU_T_HOLDERH_DECL(domainName, Identifier);
        ITU_T_OPTIONAL_DECL(listOfCapabilities, ListOfCapabilities_type);
        ITU_T_HOLDERH_DECL(sharable, bool);
        ITU_T_HOLDERH_DECL(fileName, FileName);
        ITU_T_OPTIONAL_DECL(thirdParty, MMS_Environment_1::ApplicationReference);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence StoreDomainContent-Request

    struct StoreDomainContent_Request {

        StoreDomainContent_Request();

        StoreDomainContent_Request(const Identifier& arg__domainName,
                const FileName& arg__fileName);

        StoreDomainContent_Request(shared_ptr< Identifier> arg__domainName,
                shared_ptr< FileName> arg__fileName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty);

        ITU_T_HOLDERH_DECL(domainName, Identifier);
        ITU_T_HOLDERH_DECL(fileName, FileName);
        ITU_T_OPTIONAL_DECL(thirdParty, MMS_Environment_1::ApplicationReference);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetDomainAttributes-Response

    struct GetDomainAttributes_Response {

        typedef sequence_of< MMSString > ListOfCapabilities_type;
        typedef sequence_of< Identifier > ListOfProgramInvocations_type;


        GetDomainAttributes_Response();

        GetDomainAttributes_Response(const ListOfCapabilities_type& arg__listOfCapabilities,
                const MMS_Object_Module_1::DomainState& arg__state,
                const bool& arg__mmsDeletable,
                const bool& arg__sharable,
                const ListOfProgramInvocations_type& arg__listOfProgramInvocations,
                const Integer8& arg__uploadInProgress);

        GetDomainAttributes_Response(shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
                shared_ptr< MMS_Object_Module_1::DomainState> arg__state,
                shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< bool> arg__sharable,
                shared_ptr< ListOfProgramInvocations_type> arg__listOfProgramInvocations,
                shared_ptr< Integer8> arg__uploadInProgress,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(listOfCapabilities, ListOfCapabilities_type);
        ITU_T_HOLDERH_DECL(state, MMS_Object_Module_1::DomainState); //   Ic(  [ 0  ...   15 ]   
        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_HOLDERH_DECL(sharable, bool);
        ITU_T_HOLDERH_DECL(listOfProgramInvocations, ListOfProgramInvocations_type);
        ITU_T_HOLDERH_DECL(uploadInProgress, Integer8); //   Ic(  [ -128  ...   127 ]   
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CreateProgramInvocation-Request

    struct CreateProgramInvocation_Request {

        typedef sequence_of< Identifier > ListOfDomainNames_type;

        static const bool reusable__default;

        CreateProgramInvocation_Request();

        CreateProgramInvocation_Request(const Identifier& arg__programInvocationName,
                const ListOfDomainNames_type& arg__listOfDomainNames);

        CreateProgramInvocation_Request(shared_ptr< Identifier> arg__programInvocationName,
                shared_ptr< ListOfDomainNames_type> arg__listOfDomainNames,
                shared_ptr< bool> arg__reusable,
                shared_ptr< bool> arg__monitorType);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);
        ITU_T_HOLDERH_DECL(listOfDomainNames, ListOfDomainNames_type);
        ITU_T_DEFAULTH_DECL(reusable, bool, reusable__default);
        ITU_T_OPTIONAL_DECL(monitorType, bool);

        ITU_T_ARCHIVE_FUNC;
    };

    const CS_CreateProgramInvocation_Request cS_CreateProgramInvocation_Request_normal = 0;
    const CS_CreateProgramInvocation_Request cS_CreateProgramInvocation_Request_controlling = 1;
    const CS_CreateProgramInvocation_Request cS_CreateProgramInvocation_Request_controlled = 2;

    // sequence Start-Request

    struct Start_Request {

        struct ExecutionArgument_type;

        enum ExecutionArgument_type_enum {

            ExecutionArgument_type_null = 0,
            ExecutionArgument_type_simpleString,
            ExecutionArgument_type_encodedString,
            ExecutionArgument_type_embeddedString,
        };

        struct ExecutionArgument_type : public ITU_T_CHOICE(ExecutionArgument_type_enum) {


            ITU_T_CHOICE_CTORS(ExecutionArgument_type);

            ITU_T_CHOICES_DECL(simpleString, MMSString, ExecutionArgument_type_simpleString); // primitive
            ITU_T_CHOICES_DECL(encodedString, external_type, ExecutionArgument_type_encodedString); // primitive
            ITU_T_CHOICES_DECL(embeddedString, embeded_pdv, ExecutionArgument_type_embeddedString); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        Start_Request();

        Start_Request(const Identifier& arg__programInvocationName);

        Start_Request(shared_ptr< Identifier> arg__programInvocationName,
                shared_ptr< ExecutionArgument_type> arg__executionArgument);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);
        ITU_T_OPTIONAL_DECL(executionArgument, ExecutionArgument_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CS-Start-Request

    enum CS_Start_Request_enum {

        CS_Start_Request_null = 0,
        CS_Start_Request_normal,
        CS_Start_Request_controlling,
    };

    struct CS_Start_Request : public ITU_T_CHOICE(CS_Start_Request_enum) {


        struct Controlling_type;

        struct Controlling_type {

            Controlling_type();

            Controlling_type(shared_ptr< visible_string> arg__startLocation,
                    shared_ptr< StartCount> arg__startCount);

            ITU_T_OPTIONAL_DECL(startLocation, visible_string);
            ITU_T_OPTIONAL_DECL(startCount, StartCount);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(CS_Start_Request);

        ITU_T_CHOICES_DECL(normal, null_type, CS_Start_Request_normal); // primitive
        ITU_T_CHOICEC_DECL(controlling, Controlling_type, CS_Start_Request_controlling);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice StartCount

    enum StartCount_enum {

        StartCount_null = 0,
        StartCount_noLimit,
        StartCount_cycleCount,
        StartCount_stepCount,
    };

    struct StartCount : public ITU_T_CHOICE(StartCount_enum) {


        ITU_T_CHOICE_CTORS(StartCount);

        ITU_T_CHOICES_DECL(noLimit, null_type, StartCount_noLimit); // primitive
        ITU_T_CHOICES_DECL(cycleCount, integer_type, StartCount_cycleCount); // primitive
        ITU_T_CHOICES_DECL(stepCount, integer_type, StartCount_stepCount); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Stop-Request

    struct Stop_Request {

        Stop_Request();

        Stop_Request(const Identifier& arg__programInvocationName);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Resume-Request

    struct Resume_Request {

        struct ExecutionArgument_type;

        enum ExecutionArgument_type_enum {

            ExecutionArgument_type_null = 0,
            ExecutionArgument_type_simpleString,
            ExecutionArgument_type_encodedString,
            ExecutionArgument_type_enmbeddedString,
        };

        struct ExecutionArgument_type : public ITU_T_CHOICE(ExecutionArgument_type_enum) {


            ITU_T_CHOICE_CTORS(ExecutionArgument_type);

            ITU_T_CHOICES_DECL(simpleString, MMSString, ExecutionArgument_type_simpleString); // primitive
            ITU_T_CHOICES_DECL(encodedString, external_type, ExecutionArgument_type_encodedString); // primitive
            ITU_T_CHOICES_DECL(enmbeddedString, embeded_pdv, ExecutionArgument_type_enmbeddedString); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        Resume_Request();

        Resume_Request(const Identifier& arg__programInvocationName);

        Resume_Request(shared_ptr< Identifier> arg__programInvocationName,
                shared_ptr< ExecutionArgument_type> arg__executionArgument);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);
        ITU_T_OPTIONAL_DECL(executionArgument, ExecutionArgument_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CS-Resume-Request

    enum CS_Resume_Request_enum {

        CS_Resume_Request_null = 0,
        CS_Resume_Request_normal,
        CS_Resume_Request_controlling,
    };

    struct CS_Resume_Request : public ITU_T_CHOICE(CS_Resume_Request_enum) {


        struct Controlling_type;

        struct Controlling_type {

            struct ModeType_type;

            enum ModeType_type_enum {

                ModeType_type_null = 0,
                ModeType_type_continueMode,
                ModeType_type_changeMode,
            };

            struct ModeType_type : public ITU_T_CHOICE(ModeType_type_enum) {


                ITU_T_CHOICE_CTORS(ModeType_type);

                ITU_T_CHOICES_DECL(continueMode, null_type, ModeType_type_continueMode); // primitive
                ITU_T_CHOICEC_DECL(changeMode, StartCount, ModeType_type_changeMode);

                ITU_T_ARCHIVE_FUNC;
            };


            Controlling_type();

            Controlling_type(const ModeType_type& arg__modeType);

            ITU_T_HOLDERH_DECL(modeType, ModeType_type);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(CS_Resume_Request);

        ITU_T_CHOICES_DECL(normal, null_type, CS_Resume_Request_normal); // primitive
        ITU_T_CHOICEC_DECL(controlling, Controlling_type, CS_Resume_Request_controlling);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Reset-Request

    struct Reset_Request {

        Reset_Request();

        Reset_Request(const Identifier& arg__programInvocationName);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Kill-Request

    struct Kill_Request {

        Kill_Request();

        Kill_Request(const Identifier& arg__programInvocationName);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetProgramInvocationAttributes-Response

    struct GetProgramInvocationAttributes_Response {

        struct ExecutionArgument_type;

        enum ExecutionArgument_type_enum {

            ExecutionArgument_type_null = 0,
            ExecutionArgument_type_simpleString,
            ExecutionArgument_type_encodedString,
            ExecutionArgument_type_enmbeddedString,
        };

        struct ExecutionArgument_type : public ITU_T_CHOICE(ExecutionArgument_type_enum) {


            ITU_T_CHOICE_CTORS(ExecutionArgument_type);

            ITU_T_CHOICES_DECL(simpleString, MMSString, ExecutionArgument_type_simpleString); // primitive
            ITU_T_CHOICES_DECL(encodedString, external_type, ExecutionArgument_type_encodedString); // primitive
            ITU_T_CHOICES_DECL(enmbeddedString, embeded_pdv, ExecutionArgument_type_enmbeddedString); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< Identifier > ListOfDomainNames_type;


        GetProgramInvocationAttributes_Response();

        GetProgramInvocationAttributes_Response(const MMS_Object_Module_1::ProgramInvocationState& arg__state,
                const ListOfDomainNames_type& arg__listOfDomainNames,
                const bool& arg__mmsDeletable,
                const bool& arg__reusable,
                const bool& arg__monitor,
                const ExecutionArgument_type& arg__executionArgument);

        GetProgramInvocationAttributes_Response(shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__state,
                shared_ptr< ListOfDomainNames_type> arg__listOfDomainNames,
                shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< bool> arg__reusable,
                shared_ptr< bool> arg__monitor,
                shared_ptr< ExecutionArgument_type> arg__executionArgument,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(state, MMS_Object_Module_1::ProgramInvocationState); //   Ic(  [ 0  ...   8 ]   
        ITU_T_HOLDERH_DECL(listOfDomainNames, ListOfDomainNames_type);
        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_HOLDERH_DECL(reusable, bool);
        ITU_T_HOLDERH_DECL(monitor, bool);
        ITU_T_HOLDERH_DECL(executionArgument, ExecutionArgument_type);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CS-GetProgramInvocationAttributes-Response

    struct CS_GetProgramInvocationAttributes_Response {

        struct Control_type;

        enum Control_type_enum {

            Control_type_null = 0,
            Control_type_controlling,
            Control_type_controlled,
            Control_type_normal,
        };

        struct Control_type : public ITU_T_CHOICE(Control_type_enum) {


            struct Controlling_type;
            struct Controlled_type;

            struct Controlling_type {

                struct RunningMode_type;

                enum RunningMode_type_enum {

                    RunningMode_type_null = 0,
                    RunningMode_type_freeRunning,
                    RunningMode_type_cycleLimited,
                    RunningMode_type_stepLimited,
                };

                struct RunningMode_type : public ITU_T_CHOICE(RunningMode_type_enum) {


                    ITU_T_CHOICE_CTORS(RunningMode_type);

                    ITU_T_CHOICES_DECL(freeRunning, null_type, RunningMode_type_freeRunning); // primitive
                    ITU_T_CHOICES_DECL(cycleLimited, integer_type, RunningMode_type_cycleLimited); // primitive
                    ITU_T_CHOICES_DECL(stepLimited, integer_type, RunningMode_type_stepLimited); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };



                typedef sequence_of< Identifier > ControlledPI_type;


                Controlling_type();

                Controlling_type(const ControlledPI_type& arg__controlledPI,
                        const RunningMode_type& arg__runningMode);

                Controlling_type(shared_ptr< ControlledPI_type> arg__controlledPI,
                        shared_ptr< visible_string> arg__programLocation,
                        shared_ptr< RunningMode_type> arg__runningMode);

                ITU_T_HOLDERH_DECL(controlledPI, ControlledPI_type);
                ITU_T_OPTIONAL_DECL(programLocation, visible_string);
                ITU_T_HOLDERH_DECL(runningMode, RunningMode_type);

                ITU_T_ARCHIVE_FUNC;
            };

            enum Controlled_type_enum {

                Controlled_type_null = 0,
                Controlled_type_controllingPI,
                Controlled_type_none,
            };

            struct Controlled_type : public ITU_T_CHOICE(Controlled_type_enum) {


                ITU_T_CHOICE_CTORS(Controlled_type);

                ITU_T_CHOICES_DECL(controllingPI, Identifier, Controlled_type_controllingPI); // primitive
                ITU_T_CHOICES_DECL(none, null_type, Controlled_type_none); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Control_type);

            ITU_T_CHOICEC_DECL(controlling, Controlling_type, Control_type_controlling);
            ITU_T_CHOICEC_DECL(controlled, Controlled_type, Control_type_controlled);
            ITU_T_CHOICES_DECL(normal, null_type, Control_type_normal); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        CS_GetProgramInvocationAttributes_Response();

        CS_GetProgramInvocationAttributes_Response(const integer_type& arg__errorCode,
                const Control_type& arg__control);

        ITU_T_HOLDERH_DECL(errorCode, integer_type);
        ITU_T_HOLDERH_DECL(control, Control_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Select-Request

    struct Select_Request {

        typedef sequence_of< Identifier > Controlled_type;


        Select_Request();

        Select_Request(shared_ptr< Identifier> arg__controlling,
                shared_ptr< Controlled_type> arg__controlled);

        ITU_T_OPTIONAL_DECL(controlling, Identifier);
        ITU_T_OPTIONAL_DECL(controlled, Controlled_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlterProgramInvocationAttributes-Request

    struct AlterProgramInvocationAttributes_Request {

        AlterProgramInvocationAttributes_Request();

        AlterProgramInvocationAttributes_Request(const Identifier& arg__programInvocation);

        AlterProgramInvocationAttributes_Request(shared_ptr< Identifier> arg__programInvocation,
                shared_ptr< StartCount> arg__startCount);

        ITU_T_HOLDERH_DECL(programInvocation, Identifier);
        ITU_T_OPTIONAL_DECL(startCount, StartCount);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReconfigureProgramInvocation-Request

    struct ReconfigureProgramInvocation_Request {

        typedef sequence_of< Identifier > DomainsToAdd_type;
        typedef sequence_of< Identifier > DomainsToRemove_type;


        ReconfigureProgramInvocation_Request();

        ReconfigureProgramInvocation_Request(const Identifier& arg__oldProgramInvocationName,
                const DomainsToAdd_type& arg__domainsToAdd,
                const DomainsToRemove_type& arg__domainsToRemove);

        ReconfigureProgramInvocation_Request(shared_ptr< Identifier> arg__oldProgramInvocationName,
                shared_ptr< Identifier> arg__newProgramInvocationName,
                shared_ptr< DomainsToAdd_type> arg__domainsToAdd,
                shared_ptr< DomainsToRemove_type> arg__domainsToRemove);

        ITU_T_HOLDERH_DECL(oldProgramInvocationName, Identifier);
        ITU_T_OPTIONAL_DECL(newProgramInvocationName, Identifier);
        ITU_T_HOLDERH_DECL(domainsToAdd, DomainsToAdd_type);
        ITU_T_HOLDERH_DECL(domainsToRemove, DomainsToRemove_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice ControlElement

    enum ControlElement_enum {

        ControlElement_null = 0,
        ControlElement_beginDomainDef,
        ControlElement_continueDomainDef,
        ControlElement_endDomainDef,
        ControlElement_piDefinition,
    };

    struct ControlElement : public ITU_T_CHOICE(ControlElement_enum) {


        struct BeginDomainDef_type;
        struct ContinueDomainDef_type;
        struct PiDefinition_type;

        struct BeginDomainDef_type {

            typedef sequence_of< MMSString > Capabilities_type;


            BeginDomainDef_type();

            BeginDomainDef_type(const Identifier& arg__domainName,
                    const Capabilities_type& arg__capabilities,
                    const bool& arg__sharable);

            BeginDomainDef_type(shared_ptr< Identifier> arg__domainName,
                    shared_ptr< Capabilities_type> arg__capabilities,
                    shared_ptr< bool> arg__sharable,
                    shared_ptr< LoadData> arg__loadData);

            ITU_T_HOLDERH_DECL(domainName, Identifier);
            ITU_T_HOLDERH_DECL(capabilities, Capabilities_type);
            ITU_T_HOLDERH_DECL(sharable, bool);
            ITU_T_OPTIONAL_DECL(loadData, LoadData);

            ITU_T_ARCHIVE_FUNC;
        };

        struct ContinueDomainDef_type {

            ContinueDomainDef_type();

            ContinueDomainDef_type(const Identifier& arg__domainName,
                    const LoadData& arg__loadData);

            ITU_T_HOLDERH_DECL(domainName, Identifier);
            ITU_T_HOLDERH_DECL(loadData, LoadData);

            ITU_T_ARCHIVE_FUNC;
        };

        struct PiDefinition_type {

            typedef sequence_of< Identifier > ListOfDomains_type;

            static const bool reusable__default;

            PiDefinition_type();

            PiDefinition_type(const Identifier& arg__piName,
                    const ListOfDomains_type& arg__listOfDomains);

            PiDefinition_type(shared_ptr< Identifier> arg__piName,
                    shared_ptr< ListOfDomains_type> arg__listOfDomains,
                    shared_ptr< bool> arg__reusable,
                    shared_ptr< bool> arg__monitorType,
                    shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__pIState);

            ITU_T_HOLDERH_DECL(piName, Identifier);
            ITU_T_HOLDERH_DECL(listOfDomains, ListOfDomains_type);
            ITU_T_DEFAULTH_DECL(reusable, bool, reusable__default);
            ITU_T_OPTIONAL_DECL(monitorType, bool);
            ITU_T_OPTIONAL_DECL(pIState, MMS_Object_Module_1::ProgramInvocationState); //   Ic(  [ 0  ...   8 ]   

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(ControlElement);

        ITU_T_CHOICEC_DECL(beginDomainDef, BeginDomainDef_type, ControlElement_beginDomainDef);
        ITU_T_CHOICEC_DECL(continueDomainDef, ContinueDomainDef_type, ControlElement_continueDomainDef);
        ITU_T_CHOICES_DECL(endDomainDef, Identifier, ControlElement_endDomainDef); // primitive
        ITU_T_CHOICEC_DECL(piDefinition, PiDefinition_type, ControlElement_piDefinition);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice InitiateUnitControl-Error

    enum InitiateUnitControl_Error_enum {

        InitiateUnitControl_Error_null = 0,
        InitiateUnitControl_Error_domain,
        InitiateUnitControl_Error_programInvocation,
    };

    struct InitiateUnitControl_Error : public ITU_T_CHOICE(InitiateUnitControl_Error_enum) {


        ITU_T_CHOICE_CTORS(InitiateUnitControl_Error);

        ITU_T_CHOICES_DECL(domain, Identifier, InitiateUnitControl_Error_domain); // primitive
        ITU_T_CHOICES_DECL(programInvocation, Identifier, InitiateUnitControl_Error_programInvocation); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence UnitControlLoadSegment-Response

    struct UnitControlLoadSegment_Response {

        typedef sequence_of< ControlElement > ControlElements_type;

        static const bool moreFollows__default;

        UnitControlLoadSegment_Response();

        UnitControlLoadSegment_Response(const ControlElements_type& arg__controlElements);

        UnitControlLoadSegment_Response(shared_ptr< ControlElements_type> arg__controlElements,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(controlElements, ControlElements_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence UnitControlUpload-Request

    struct UnitControlUpload_Request {

        struct ContinueAfter_type;

        enum ContinueAfter_type_enum {

            ContinueAfter_type_null = 0,
            ContinueAfter_type_domain,
            ContinueAfter_type_ulsmID,
            ContinueAfter_type_programInvocation,
        };

        struct ContinueAfter_type : public ITU_T_CHOICE(ContinueAfter_type_enum) {


            ITU_T_CHOICE_CTORS(ContinueAfter_type);

            ITU_T_CHOICES_DECL(domain, Identifier, ContinueAfter_type_domain); // primitive
            ITU_T_CHOICES_DECL(ulsmID, integer_type, ContinueAfter_type_ulsmID); // primitive
            ITU_T_CHOICES_DECL(programInvocation, Identifier, ContinueAfter_type_programInvocation); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        UnitControlUpload_Request();

        UnitControlUpload_Request(const Identifier& arg__unitControlName);

        UnitControlUpload_Request(shared_ptr< Identifier> arg__unitControlName,
                shared_ptr< ContinueAfter_type> arg__continueAfter);

        ITU_T_HOLDERH_DECL(unitControlName, Identifier);
        ITU_T_OPTIONAL_DECL(continueAfter, ContinueAfter_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence UnitControlUpload-Response

    struct UnitControlUpload_Response {

        struct NextElement_type;

        enum NextElement_type_enum {

            NextElement_type_null = 0,
            NextElement_type_domain,
            NextElement_type_ulsmID,
            NextElement_type_programInvocation,
        };

        struct NextElement_type : public ITU_T_CHOICE(NextElement_type_enum) {


            ITU_T_CHOICE_CTORS(NextElement_type);

            ITU_T_CHOICES_DECL(domain, Identifier, NextElement_type_domain); // primitive
            ITU_T_CHOICES_DECL(ulsmID, integer_type, NextElement_type_ulsmID); // primitive
            ITU_T_CHOICES_DECL(programInvocation, Identifier, NextElement_type_programInvocation); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< ControlElement > ControlElements_type;


        UnitControlUpload_Response();

        UnitControlUpload_Response(const ControlElements_type& arg__controlElements);

        UnitControlUpload_Response(shared_ptr< ControlElements_type> arg__controlElements,
                shared_ptr< NextElement_type> arg__nextElement);

        ITU_T_HOLDERH_DECL(controlElements, ControlElements_type);
        ITU_T_OPTIONAL_DECL(nextElement, NextElement_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence StartUnitControl-Request

    struct StartUnitControl_Request {

        struct ExecutionArgument_type;

        enum ExecutionArgument_type_enum {

            ExecutionArgument_type_null = 0,
            ExecutionArgument_type_simpleString,
            ExecutionArgument_type_encodedString,
            ExecutionArgument_type_enmbeddedString,
        };

        struct ExecutionArgument_type : public ITU_T_CHOICE(ExecutionArgument_type_enum) {


            ITU_T_CHOICE_CTORS(ExecutionArgument_type);

            ITU_T_CHOICES_DECL(simpleString, MMSString, ExecutionArgument_type_simpleString); // primitive
            ITU_T_CHOICES_DECL(encodedString, external_type, ExecutionArgument_type_encodedString); // primitive
            ITU_T_CHOICES_DECL(enmbeddedString, embeded_pdv, ExecutionArgument_type_enmbeddedString); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        StartUnitControl_Request();

        StartUnitControl_Request(const Identifier& arg__unitControlName);

        StartUnitControl_Request(shared_ptr< Identifier> arg__unitControlName,
                shared_ptr< ExecutionArgument_type> arg__executionArgument);

        ITU_T_HOLDERH_DECL(unitControlName, Identifier);
        ITU_T_OPTIONAL_DECL(executionArgument, ExecutionArgument_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence StartUnitControl-Error

    struct StartUnitControl_Error {

        StartUnitControl_Error();

        StartUnitControl_Error(const Identifier& arg__programInvocationName,
                const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);
        ITU_T_HOLDERH_DECL(programInvocationState, MMS_Object_Module_1::ProgramInvocationState); //   Ic(  [ 0  ...   8 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence StopUnitControl-Error

    struct StopUnitControl_Error {

        StopUnitControl_Error();

        StopUnitControl_Error(const Identifier& arg__programInvocationName,
                const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState);

        ITU_T_HOLDERH_DECL(programInvocationName, Identifier);
        ITU_T_HOLDERH_DECL(programInvocationState, MMS_Object_Module_1::ProgramInvocationState); //   Ic(  [ 0  ...   8 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CreateUnitControl-Request

    struct CreateUnitControl_Request {

        typedef sequence_of< Identifier > Domains_type;
        typedef sequence_of< Identifier > ProgramInvocations_type;


        CreateUnitControl_Request();

        CreateUnitControl_Request(const Identifier& arg__unitControl,
                const Domains_type& arg__domains,
                const ProgramInvocations_type& arg__programInvocations);

        ITU_T_HOLDERH_DECL(unitControl, Identifier);
        ITU_T_HOLDERH_DECL(domains, Domains_type);
        ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AddToUnitControl-Request

    struct AddToUnitControl_Request {

        typedef sequence_of< Identifier > Domains_type;
        typedef sequence_of< Identifier > ProgramInvocations_type;


        AddToUnitControl_Request();

        AddToUnitControl_Request(const Identifier& arg__unitControl,
                const Domains_type& arg__domains,
                const ProgramInvocations_type& arg__programInvocations);

        ITU_T_HOLDERH_DECL(unitControl, Identifier);
        ITU_T_HOLDERH_DECL(domains, Domains_type);
        ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RemoveFromUnitControl-Request

    struct RemoveFromUnitControl_Request {

        typedef sequence_of< Identifier > Domains_type;
        typedef sequence_of< Identifier > ProgramInvocations_type;


        RemoveFromUnitControl_Request();

        RemoveFromUnitControl_Request(const Identifier& arg__unitControl,
                const Domains_type& arg__domains,
                const ProgramInvocations_type& arg__programInvocations);

        ITU_T_HOLDERH_DECL(unitControl, Identifier);
        ITU_T_HOLDERH_DECL(domains, Domains_type);
        ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetUnitControlAttributes-Response

    struct GetUnitControlAttributes_Response {

        typedef sequence_of< Identifier > Domains_type;
        typedef sequence_of< Identifier > ProgramInvocations_type;


        GetUnitControlAttributes_Response();

        GetUnitControlAttributes_Response(const Domains_type& arg__domains,
                const ProgramInvocations_type& arg__programInvocations);

        ITU_T_HOLDERH_DECL(domains, Domains_type);
        ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence LoadUnitControlFromFile-Request

    struct LoadUnitControlFromFile_Request {

        LoadUnitControlFromFile_Request();

        LoadUnitControlFromFile_Request(const Identifier& arg__unitControlName,
                const FileName& arg__fileName);

        LoadUnitControlFromFile_Request(shared_ptr< Identifier> arg__unitControlName,
                shared_ptr< FileName> arg__fileName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty);

        ITU_T_HOLDERH_DECL(unitControlName, Identifier);
        ITU_T_HOLDERH_DECL(fileName, FileName);
        ITU_T_OPTIONAL_DECL(thirdParty, MMS_Environment_1::ApplicationReference);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice LoadUnitControlFromFile-Error

    enum LoadUnitControlFromFile_Error_enum {

        LoadUnitControlFromFile_Error_null = 0,
        LoadUnitControlFromFile_Error_none,
        LoadUnitControlFromFile_Error_domain,
        LoadUnitControlFromFile_Error_programInvocation,
    };

    struct LoadUnitControlFromFile_Error : public ITU_T_CHOICE(LoadUnitControlFromFile_Error_enum) {


        ITU_T_CHOICE_CTORS(LoadUnitControlFromFile_Error);

        ITU_T_CHOICES_DECL(none, null_type, LoadUnitControlFromFile_Error_none); // primitive
        ITU_T_CHOICES_DECL(domain, Identifier, LoadUnitControlFromFile_Error_domain); // primitive
        ITU_T_CHOICES_DECL(programInvocation, Identifier, LoadUnitControlFromFile_Error_programInvocation); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence StoreUnitControlToFile-Request

    struct StoreUnitControlToFile_Request {

        StoreUnitControlToFile_Request();

        StoreUnitControlToFile_Request(const Identifier& arg__unitControlName,
                const FileName& arg__fileName);

        StoreUnitControlToFile_Request(shared_ptr< Identifier> arg__unitControlName,
                shared_ptr< FileName> arg__fileName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty);

        ITU_T_HOLDERH_DECL(unitControlName, Identifier);
        ITU_T_HOLDERH_DECL(fileName, FileName);
        ITU_T_OPTIONAL_DECL(thirdParty, MMS_Environment_1::ApplicationReference);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice DeleteUnitControl-Error

    enum DeleteUnitControl_Error_enum {

        DeleteUnitControl_Error_null = 0,
        DeleteUnitControl_Error_domain,
        DeleteUnitControl_Error_programInvocation,
    };

    struct DeleteUnitControl_Error : public ITU_T_CHOICE(DeleteUnitControl_Error_enum) {


        ITU_T_CHOICE_CTORS(DeleteUnitControl_Error);

        ITU_T_CHOICES_DECL(domain, Identifier, DeleteUnitControl_Error_domain); // primitive
        ITU_T_CHOICES_DECL(programInvocation, Identifier, DeleteUnitControl_Error_programInvocation); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice TypeSpecification

    enum TypeSpecification_enum {

        TypeSpecification_null = 0,
        TypeSpecification_typeName,
        TypeSpecification_typeDescription,
    };

    struct TypeSpecification : public ITU_T_CHOICE(TypeSpecification_enum) {


        ITU_T_CHOICE_CTORS(TypeSpecification);

        ITU_T_CHOICEC_DECL(typeName, ObjectName, TypeSpecification_typeName);
        ITU_T_CHOICEC_DECL(typeDescription, MMS_Object_Module_1::TypeDescription, TypeSpecification_typeDescription);

        ITU_T_ARCHIVE_FUNC;
    };

    enum AlternateAccess_sequence_of_enum {

        AlternateAccess_sequence_of_null = 0,
        AlternateAccess_sequence_of_unnamed,
        AlternateAccess_sequence_of_named,
    };

    struct AlternateAccess_sequence_of : public ITU_T_CHOICE(AlternateAccess_sequence_of_enum) {


        struct Named_type;

        struct Named_type {

            Named_type();

            Named_type(const Identifier& arg__componentName,
                    const AlternateAccessSelection& arg__access);

            ITU_T_HOLDERH_DECL(componentName, Identifier);
            ITU_T_HOLDERH_DECL(access, AlternateAccessSelection);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(AlternateAccess_sequence_of);

        ITU_T_CHOICEC_DECL(unnamed, AlternateAccessSelection, AlternateAccess_sequence_of_unnamed);
        ITU_T_CHOICEC_DECL(named, Named_type, AlternateAccess_sequence_of_named);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice AlternateAccessSelection

    enum AlternateAccessSelection_enum {

        AlternateAccessSelection_null = 0,
        AlternateAccessSelection_selectAlternateAccess,
        AlternateAccessSelection_selectAccess,
    };

    struct AlternateAccessSelection : public ITU_T_CHOICE(AlternateAccessSelection_enum) {


        struct SelectAlternateAccess_type;
        struct SelectAccess_type;

        struct SelectAlternateAccess_type {

            struct AccessSelection_type;

            enum AccessSelection_type_enum {

                AccessSelection_type_null = 0,
                AccessSelection_type_component,
                AccessSelection_type_index,
                AccessSelection_type_indexRange,
                AccessSelection_type_allElements,
            };

            struct AccessSelection_type : public ITU_T_CHOICE(AccessSelection_type_enum) {


                struct IndexRange_type;

                struct IndexRange_type {

                    IndexRange_type();

                    IndexRange_type(const Unsigned32& arg__lowIndex,
                            const Unsigned32& arg__numberOfElements);

                    ITU_T_HOLDERH_DECL(lowIndex, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
                    ITU_T_HOLDERH_DECL(numberOfElements, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

                    ITU_T_ARCHIVE_FUNC;
                };


                ITU_T_CHOICE_CTORS(AccessSelection_type);

                ITU_T_CHOICES_DECL(component, Identifier, AccessSelection_type_component); // primitive
                ITU_T_CHOICES_DECL(index, Unsigned32, AccessSelection_type_index); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
                ITU_T_CHOICEC_DECL(indexRange, IndexRange_type, AccessSelection_type_indexRange);
                ITU_T_CHOICES_DECL(allElements, null_type, AccessSelection_type_allElements); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            SelectAlternateAccess_type();

            SelectAlternateAccess_type(const AccessSelection_type& arg__accessSelection,
                    const AlternateAccess& arg__alternateAccess);

            ITU_T_HOLDERH_DECL(accessSelection, AccessSelection_type);
            ITU_T_HOLDERH_DECL(alternateAccess, AlternateAccess);

            ITU_T_ARCHIVE_FUNC;
        };

        enum SelectAccess_type_enum {

            SelectAccess_type_null = 0,
            SelectAccess_type_component,
            SelectAccess_type_index,
            SelectAccess_type_indexRange,
            SelectAccess_type_allElements,
        };

        struct SelectAccess_type : public ITU_T_CHOICE(SelectAccess_type_enum) {


            struct IndexRange_type;

            struct IndexRange_type {

                IndexRange_type();

                IndexRange_type(const Unsigned32& arg__lowIndex,
                        const Unsigned32& arg__numberOfElements);

                ITU_T_HOLDERH_DECL(lowIndex, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
                ITU_T_HOLDERH_DECL(numberOfElements, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(SelectAccess_type);

            ITU_T_CHOICES_DECL(component, Identifier, SelectAccess_type_component); // primitive
            ITU_T_CHOICES_DECL(index, Unsigned32, SelectAccess_type_index); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
            ITU_T_CHOICEC_DECL(indexRange, IndexRange_type, SelectAccess_type_indexRange);
            ITU_T_CHOICES_DECL(allElements, null_type, SelectAccess_type_allElements); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(AlternateAccessSelection);

        ITU_T_CHOICEC_DECL(selectAlternateAccess, SelectAlternateAccess_type, AlternateAccessSelection_selectAlternateAccess);
        ITU_T_CHOICEC_DECL(selectAccess, SelectAccess_type, AlternateAccessSelection_selectAccess);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice AccessResult

    enum AccessResult_enum {

        AccessResult_null = 0,
        AccessResult_failure,
        AccessResult_success,
    };

    struct AccessResult : public ITU_T_CHOICE(AccessResult_enum) {


        ITU_T_CHOICE_CTORS(AccessResult);

        ITU_T_CHOICES_DECL(failure, DataAccessError, AccessResult_failure); // primitive  //   Ic(  [ 0  ...   11 ]   
        ITU_T_CHOICEC_DECL(success, Data, AccessResult_success);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Data

    enum Data_enum {

        Data_null = 0,
        Data_array,
        Data_structure,
        Data_boolean,
        Data_bit_stringV,
        Data_integer,
        Data_unsignedV,
        Data_floating_point,
        Data_octet_stringV,
        Data_visible_stringV,
        Data_generalized_time,
        Data_binary_time,
        Data_bcd,
        Data_booleanArray,
        Data_objId,
        Data_mMSString,
    };

    struct Data : public ITU_T_CHOICE(Data_enum) {



        typedef sequence_of< Data > Array_type;
        typedef sequence_of< Data > Structure_type;


        ITU_T_CHOICE_CTORS(Data);

        ITU_T_CHOICEC_DECL(array, Array_type, Data_array);
        ITU_T_CHOICEC_DECL(structure, Structure_type, Data_structure);
        ITU_T_CHOICES_DECL(boolean, bool, Data_boolean); // primitive
        ITU_T_CHOICES_DECL(bit_stringV, bit_string, Data_bit_stringV); // primitive
        ITU_T_CHOICES_DECL(integer, integer_type, Data_integer); // primitive
        ITU_T_CHOICES_DECL(unsignedV, integer_type, Data_unsignedV); // primitive
        ITU_T_CHOICES_DECL(floating_point, FloatingPoint, Data_floating_point); // primitive
        ITU_T_CHOICES_DECL(octet_stringV, octet_string, Data_octet_stringV); // primitive
        ITU_T_CHOICES_DECL(visible_stringV, visible_string, Data_visible_stringV); // primitive
        ITU_T_CHOICES_DECL(generalized_time, gentime, Data_generalized_time); // primitive
        ITU_T_CHOICES_DECL(binary_time, TimeOfDay, Data_binary_time); // primitive  //    Sc (  [ 4  ...   6 ]   
        ITU_T_CHOICES_DECL(bcd, integer_type, Data_bcd); // primitive
        ITU_T_CHOICES_DECL(booleanArray, bit_string, Data_booleanArray); // primitive
        ITU_T_CHOICES_DECL(objId, oid_type, Data_objId); // primitive
        ITU_T_CHOICES_DECL(mMSString, MMSString, Data_mMSString); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    const DataAccessError dataAccessError_object_invalidated = 0;
    const DataAccessError dataAccessError_hardware_fault = 1;
    const DataAccessError dataAccessError_temporarily_unavailable = 2;
    const DataAccessError dataAccessError_object_access_denied = 3;
    const DataAccessError dataAccessError_object_undefined = 4;
    const DataAccessError dataAccessError_invalid_address = 5;
    const DataAccessError dataAccessError_type_unsupported = 6;
    const DataAccessError dataAccessError_type_inconsistent = 7;
    const DataAccessError dataAccessError_object_attribute_inconsistent = 8;
    const DataAccessError dataAccessError_object_access_unsupported = 9;
    const DataAccessError dataAccessError_object_non_existent = 10;
    const DataAccessError dataAccessError_object_value_invalid = 11;

    // choice VariableAccessSpecification

    enum VariableAccessSpecification_enum {

        VariableAccessSpecification_null = 0,
        VariableAccessSpecification_listOfVariable,
        VariableAccessSpecification_variableListName,
    };

    struct VariableAccessSpecification : public ITU_T_CHOICE(VariableAccessSpecification_enum) {


        struct ListOfVariable_type_sequence_of;

        struct ListOfVariable_type_sequence_of {

            ListOfVariable_type_sequence_of();

            ListOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification);

            ListOfVariable_type_sequence_of(shared_ptr< VariableSpecification> arg__variableSpecification,
                    shared_ptr< AlternateAccess> arg__alternateAccess);

            ITU_T_HOLDERH_DECL(variableSpecification, VariableSpecification);
            ITU_T_OPTIONAL_DECL(alternateAccess, AlternateAccess);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< ListOfVariable_type_sequence_of > ListOfVariable_type;


        ITU_T_CHOICE_CTORS(VariableAccessSpecification);

        ITU_T_CHOICEC_DECL(listOfVariable, ListOfVariable_type, VariableAccessSpecification_listOfVariable);
        ITU_T_CHOICEC_DECL(variableListName, ObjectName, VariableAccessSpecification_variableListName);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice VariableSpecification

    enum VariableSpecification_enum {

        VariableSpecification_null = 0,
        VariableSpecification_name,
        VariableSpecification_address,
        VariableSpecification_variableDescription,
        VariableSpecification_scatteredAccessDescription,
        VariableSpecification_invalidated,
    };

    struct VariableSpecification : public ITU_T_CHOICE(VariableSpecification_enum) {


        struct VariableDescription_type;

        struct VariableDescription_type {

            VariableDescription_type();

            VariableDescription_type(const MMS_Object_Module_1::Address& arg__address,
                    const TypeSpecification& arg__typeSpecification);

            ITU_T_HOLDERH_DECL(address, MMS_Object_Module_1::Address);
            ITU_T_HOLDERH_DECL(typeSpecification, TypeSpecification);

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(VariableSpecification);

        ITU_T_CHOICEC_DECL(name, ObjectName, VariableSpecification_name);
        ITU_T_CHOICEC_DECL(address, MMS_Object_Module_1::Address, VariableSpecification_address);
        ITU_T_CHOICEC_DECL(variableDescription, VariableDescription_type, VariableSpecification_variableDescription);
        ITU_T_CHOICEC_DECL(scatteredAccessDescription, ISO_9506_MMS_1A::ScatteredAccessDescription, VariableSpecification_scatteredAccessDescription);
        ITU_T_CHOICES_DECL(invalidated, null_type, VariableSpecification_invalidated); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Read-Request

    struct Read_Request {

        static const bool specificationWithResult__default;

        Read_Request();

        Read_Request(const VariableAccessSpecification& arg__variableAccessSpecification);

        Read_Request(shared_ptr< bool> arg__specificationWithResult,
                shared_ptr< VariableAccessSpecification> arg__variableAccessSpecification);

        ITU_T_DEFAULTH_DECL(specificationWithResult, bool, specificationWithResult__default);
        ITU_T_HOLDERH_DECL(variableAccessSpecification, VariableAccessSpecification);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Read-Response

    struct Read_Response {

        typedef sequence_of< AccessResult > ListOfAccessResult_type;


        Read_Response();

        Read_Response(const ListOfAccessResult_type& arg__listOfAccessResult);

        Read_Response(shared_ptr< VariableAccessSpecification> arg__variableAccessSpecification,
                shared_ptr< ListOfAccessResult_type> arg__listOfAccessResult);

        ITU_T_OPTIONAL_DECL(variableAccessSpecification, VariableAccessSpecification);
        ITU_T_HOLDERH_DECL(listOfAccessResult, ListOfAccessResult_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Write-Request

    struct Write_Request {

        typedef sequence_of< Data > ListOfData_type;


        Write_Request();

        Write_Request(const VariableAccessSpecification& arg__variableAccessSpecification,
                const ListOfData_type& arg__listOfData);

        ITU_T_HOLDERH_DECL(variableAccessSpecification, VariableAccessSpecification);
        ITU_T_HOLDERH_DECL(listOfData, ListOfData_type);

        ITU_T_ARCHIVE_FUNC;
    };

    enum Write_Response_sequence_of_enum {

        Write_Response_sequence_of_null = 0,
        Write_Response_sequence_of_failure,
        Write_Response_sequence_of_success,
    };

    struct Write_Response_sequence_of : public ITU_T_CHOICE(Write_Response_sequence_of_enum) {


        ITU_T_CHOICE_CTORS(Write_Response_sequence_of);

        ITU_T_CHOICES_DECL(failure, DataAccessError, Write_Response_sequence_of_failure); // primitive  //   Ic(  [ 0  ...   11 ]   
        ITU_T_CHOICES_DECL(success, null_type, Write_Response_sequence_of_success); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence InformationReport

    struct InformationReport {

        typedef sequence_of< AccessResult > ListOfAccessResult_type;


        InformationReport();

        InformationReport(const VariableAccessSpecification& arg__variableAccessSpecification,
                const ListOfAccessResult_type& arg__listOfAccessResult);

        ITU_T_HOLDERH_DECL(variableAccessSpecification, VariableAccessSpecification);
        ITU_T_HOLDERH_DECL(listOfAccessResult, ListOfAccessResult_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice GetVariableAccessAttributes-Request

    enum GetVariableAccessAttributes_Request_enum {

        GetVariableAccessAttributes_Request_null = 0,
        GetVariableAccessAttributes_Request_name,
        GetVariableAccessAttributes_Request_address,
    };

    struct GetVariableAccessAttributes_Request : public ITU_T_CHOICE(GetVariableAccessAttributes_Request_enum) {


        ITU_T_CHOICE_CTORS(GetVariableAccessAttributes_Request);

        ITU_T_CHOICEC_DECL(name, ObjectName, GetVariableAccessAttributes_Request_name);
        ITU_T_CHOICEC_DECL(address, MMS_Object_Module_1::Address, GetVariableAccessAttributes_Request_address);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetVariableAccessAttributes-Response

    struct GetVariableAccessAttributes_Response {

        GetVariableAccessAttributes_Response();

        GetVariableAccessAttributes_Response(const bool& arg__mmsDeletable,
                const MMS_Object_Module_1::TypeDescription& arg__typeDescription);

        GetVariableAccessAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< MMS_Object_Module_1::Address> arg__address,
                shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
                shared_ptr< Identifier> arg__accessControlList,
                shared_ptr< visible_string> arg__meaning);

        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_OPTIONAL_DECL(address, MMS_Object_Module_1::Address);
        ITU_T_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);
        ITU_T_OPTIONAL_DECL(meaning, visible_string);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineNamedVariable-Request

    struct DefineNamedVariable_Request {

        DefineNamedVariable_Request();

        DefineNamedVariable_Request(const ObjectName& arg__variableName,
                const MMS_Object_Module_1::Address& arg__address);

        DefineNamedVariable_Request(shared_ptr< ObjectName> arg__variableName,
                shared_ptr< MMS_Object_Module_1::Address> arg__address,
                shared_ptr< TypeSpecification> arg__typeSpecification);

        ITU_T_HOLDERH_DECL(variableName, ObjectName);
        ITU_T_HOLDERH_DECL(address, MMS_Object_Module_1::Address);
        ITU_T_OPTIONAL_DECL(typeSpecification, TypeSpecification);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteVariableAccess-Request

    struct DeleteVariableAccess_Request {

        typedef sequence_of< ObjectName > ListOfName_type;

        static const uint8_t scopeOfDelete_specific;
        static const uint8_t scopeOfDelete_aa_specific;
        static const uint8_t scopeOfDelete_domain;
        static const uint8_t scopeOfDelete_vmd;

        static const uint8_t scopeOfDelete__default;

        DeleteVariableAccess_Request();

        DeleteVariableAccess_Request(shared_ptr< uint8_t> arg__scopeOfDelete,
                shared_ptr< ListOfName_type> arg__listOfName,
                shared_ptr< Identifier> arg__domainName);

        ITU_T_DEFAULTH_DECL(scopeOfDelete, uint8_t, scopeOfDelete__default); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(listOfName, ListOfName_type);
        ITU_T_OPTIONAL_DECL(domainName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteVariableAccess-Response

    struct DeleteVariableAccess_Response {

        DeleteVariableAccess_Response();

        DeleteVariableAccess_Response(const Unsigned32& arg__numberMatched,
                const Unsigned32& arg__numberDeleted);

        ITU_T_HOLDERH_DECL(numberMatched, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(numberDeleted, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineNamedVariableList-Request

    struct DefineNamedVariableList_Request {

        struct ListOfVariable_type_sequence_of;

        struct ListOfVariable_type_sequence_of {

            ListOfVariable_type_sequence_of();

            ListOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification);

            ListOfVariable_type_sequence_of(shared_ptr< VariableSpecification> arg__variableSpecification,
                    shared_ptr< AlternateAccess> arg__alternateAccess);

            ITU_T_HOLDERH_DECL(variableSpecification, VariableSpecification);
            ITU_T_OPTIONAL_DECL(alternateAccess, AlternateAccess);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< ListOfVariable_type_sequence_of > ListOfVariable_type;


        DefineNamedVariableList_Request();

        DefineNamedVariableList_Request(const ObjectName& arg__variableListName,
                const ListOfVariable_type& arg__listOfVariable);

        ITU_T_HOLDERH_DECL(variableListName, ObjectName);
        ITU_T_HOLDERH_DECL(listOfVariable, ListOfVariable_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetNamedVariableListAttributes-Response

    struct GetNamedVariableListAttributes_Response {

        struct ListOfVariable_type_sequence_of;

        struct ListOfVariable_type_sequence_of {

            ListOfVariable_type_sequence_of();

            ListOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification);

            ListOfVariable_type_sequence_of(shared_ptr< VariableSpecification> arg__variableSpecification,
                    shared_ptr< AlternateAccess> arg__alternateAccess);

            ITU_T_HOLDERH_DECL(variableSpecification, VariableSpecification);
            ITU_T_OPTIONAL_DECL(alternateAccess, AlternateAccess);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< ListOfVariable_type_sequence_of > ListOfVariable_type;


        GetNamedVariableListAttributes_Response();

        GetNamedVariableListAttributes_Response(const bool& arg__mmsDeletable,
                const ListOfVariable_type& arg__listOfVariable);

        GetNamedVariableListAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< ListOfVariable_type> arg__listOfVariable,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_HOLDERH_DECL(listOfVariable, ListOfVariable_type);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteNamedVariableList-Request

    struct DeleteNamedVariableList_Request {

        typedef sequence_of< ObjectName > ListOfVariableListName_type;

        static const uint8_t scopeOfDelete_specific;
        static const uint8_t scopeOfDelete_aa_specific;
        static const uint8_t scopeOfDelete_domain;
        static const uint8_t scopeOfDelete_vmd;

        static const uint8_t scopeOfDelete__default;

        DeleteNamedVariableList_Request();

        DeleteNamedVariableList_Request(shared_ptr< uint8_t> arg__scopeOfDelete,
                shared_ptr< ListOfVariableListName_type> arg__listOfVariableListName,
                shared_ptr< Identifier> arg__domainName);

        ITU_T_DEFAULTH_DECL(scopeOfDelete, uint8_t, scopeOfDelete__default); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(listOfVariableListName, ListOfVariableListName_type);
        ITU_T_OPTIONAL_DECL(domainName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteNamedVariableList-Response

    struct DeleteNamedVariableList_Response {

        DeleteNamedVariableList_Response();

        DeleteNamedVariableList_Response(const Unsigned32& arg__numberMatched,
                const Unsigned32& arg__numberDeleted);

        ITU_T_HOLDERH_DECL(numberMatched, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(numberDeleted, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineNamedType-Request

    struct DefineNamedType_Request {

        DefineNamedType_Request();

        DefineNamedType_Request(const ObjectName& arg__typeName,
                const TypeSpecification& arg__typeSpecification);

        ITU_T_HOLDERH_DECL(typeName, ObjectName);
        ITU_T_HOLDERH_DECL(typeSpecification, TypeSpecification);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetNamedTypeAttributes-Response

    struct GetNamedTypeAttributes_Response {

        GetNamedTypeAttributes_Response();

        GetNamedTypeAttributes_Response(const bool& arg__mmsDeletable,
                const TypeSpecification& arg__typeSpecification);

        GetNamedTypeAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< TypeSpecification> arg__typeSpecification,
                shared_ptr< Identifier> arg__accessControlList,
                shared_ptr< visible_string> arg__meaning);

        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_HOLDERH_DECL(typeSpecification, TypeSpecification);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);
        ITU_T_OPTIONAL_DECL(meaning, visible_string);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteNamedType-Request

    struct DeleteNamedType_Request {

        typedef sequence_of< ObjectName > ListOfTypeName_type;

        static const uint8_t scopeOfDelete_specific;
        static const uint8_t scopeOfDelete_aa_specific;
        static const uint8_t scopeOfDelete_domain;
        static const uint8_t scopeOfDelete_vmd;

        static const uint8_t scopeOfDelete__default;

        DeleteNamedType_Request();

        DeleteNamedType_Request(shared_ptr< uint8_t> arg__scopeOfDelete,
                shared_ptr< ListOfTypeName_type> arg__listOfTypeName,
                shared_ptr< Identifier> arg__domainName);

        ITU_T_DEFAULTH_DECL(scopeOfDelete, uint8_t, scopeOfDelete__default); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(listOfTypeName, ListOfTypeName_type);
        ITU_T_OPTIONAL_DECL(domainName, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteNamedType-Response

    struct DeleteNamedType_Response {

        DeleteNamedType_Response();

        DeleteNamedType_Response(const Unsigned32& arg__numberMatched,
                const Unsigned32& arg__numberDeleted);

        ITU_T_HOLDERH_DECL(numberMatched, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(numberDeleted, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ExchangeData-Request

    struct ExchangeData_Request {

        typedef sequence_of< Data > ListOfRequestData_type;


        ExchangeData_Request();

        ExchangeData_Request(const ObjectName& arg__dataExchangeName,
                const ListOfRequestData_type& arg__listOfRequestData);

        ITU_T_HOLDERH_DECL(dataExchangeName, ObjectName);
        ITU_T_HOLDERH_DECL(listOfRequestData, ListOfRequestData_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ExchangeData-Response

    struct ExchangeData_Response {

        typedef sequence_of< Data > ListOfResponseData_type;


        ExchangeData_Response();

        ExchangeData_Response(const ListOfResponseData_type& arg__listOfResponseData);

        ITU_T_HOLDERH_DECL(listOfResponseData, ListOfResponseData_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetDataExchangeAttributes-Response

    struct GetDataExchangeAttributes_Response {

        typedef sequence_of< MMS_Object_Module_1::TypeDescription > ListOfRequestTypeDescriptions_type;
        typedef sequence_of< MMS_Object_Module_1::TypeDescription > ListOfResponseTypeDescriptions_type;

        GetDataExchangeAttributes_Response();

        GetDataExchangeAttributes_Response(const bool& arg__inUse,
                const ListOfRequestTypeDescriptions_type& arg__listOfRequestTypeDescriptions,
                const ListOfResponseTypeDescriptions_type& arg__listOfResponseTypeDescriptions);

        GetDataExchangeAttributes_Response(shared_ptr< bool> arg__inUse,
                shared_ptr< ListOfRequestTypeDescriptions_type> arg__listOfRequestTypeDescriptions,
                shared_ptr< ListOfResponseTypeDescriptions_type> arg__listOfResponseTypeDescriptions,
                shared_ptr< Identifier> arg__programInvocation,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(inUse, bool);
        ITU_T_HOLDERH_DECL(listOfRequestTypeDescriptions, ListOfRequestTypeDescriptions_type);
        ITU_T_HOLDERH_DECL(listOfResponseTypeDescriptions, ListOfResponseTypeDescriptions_type);
        ITU_T_OPTIONAL_DECL(programInvocation, Identifier);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence TakeControl-Request

    struct TakeControl_Request {

        static const MMS_Object_Module_1::Priority priority__default;
        static const bool relinquishIfConnectionLost__default;

        TakeControl_Request();

        TakeControl_Request(const ObjectName& arg__semaphoreName);

        TakeControl_Request(shared_ptr< ObjectName> arg__semaphoreName,
                shared_ptr< Identifier> arg__namedToken,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                shared_ptr< Unsigned32> arg__acceptableDelay,
                shared_ptr< Unsigned32> arg__controlTimeOut,
                shared_ptr< bool> arg__abortOnTimeOut,
                shared_ptr< bool> arg__relinquishIfConnectionLost,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__applicationToPreempt);

        ITU_T_HOLDERH_DECL(semaphoreName, ObjectName);
        ITU_T_OPTIONAL_DECL(namedToken, Identifier);
        ITU_T_DEFAULTH_DECL(priority, MMS_Object_Module_1::Priority, priority__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_OPTIONAL_DECL(acceptableDelay, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(controlTimeOut, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(abortOnTimeOut, bool);
        ITU_T_DEFAULTH_DECL(relinquishIfConnectionLost, bool, relinquishIfConnectionLost__default);
        ITU_T_OPTIONAL_DECL(applicationToPreempt, MMS_Environment_1::ApplicationReference);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice TakeControl-Response

    enum TakeControl_Response_enum {

        TakeControl_Response_null = 0,
        TakeControl_Response_noResult,
        TakeControl_Response_namedToken,
    };

    struct TakeControl_Response : public ITU_T_CHOICE(TakeControl_Response_enum) {


        ITU_T_CHOICE_CTORS(TakeControl_Response);

        ITU_T_CHOICES_DECL(noResult, null_type, TakeControl_Response_noResult); // primitive
        ITU_T_CHOICES_DECL(namedToken, Identifier, TakeControl_Response_namedToken); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RelinquishControl-Request

    struct RelinquishControl_Request {

        RelinquishControl_Request();

        RelinquishControl_Request(const ObjectName& arg__semaphoreName);

        RelinquishControl_Request(shared_ptr< ObjectName> arg__semaphoreName,
                shared_ptr< Identifier> arg__namedToken);

        ITU_T_HOLDERH_DECL(semaphoreName, ObjectName);
        ITU_T_OPTIONAL_DECL(namedToken, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineSemaphore-Request

    struct DefineSemaphore_Request {

        DefineSemaphore_Request();

        DefineSemaphore_Request(const ObjectName& arg__semaphoreName,
                const Unsigned16& arg__numberOfTokens);

        ITU_T_HOLDERH_DECL(semaphoreName, ObjectName);
        ITU_T_HOLDERH_DECL(numberOfTokens, Unsigned16); //   Ic(  [ 0  ...   32767 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportSemaphoreStatus-Response

    struct ReportSemaphoreStatus_Response {

        static const uint8_t classV_token;
        static const uint8_t classV_pool;


        ReportSemaphoreStatus_Response();

        ReportSemaphoreStatus_Response(const bool& arg__mmsDeletable,
                const uint8_t& arg__classV,
                const Unsigned16& arg__numberOfTokens,
                const Unsigned16& arg__numberOfOwnedTokens,
                const Unsigned16& arg__numberOfHungTokens);

        ReportSemaphoreStatus_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< uint8_t> arg__classV,
                shared_ptr< Unsigned16> arg__numberOfTokens,
                shared_ptr< Unsigned16> arg__numberOfOwnedTokens,
                shared_ptr< Unsigned16> arg__numberOfHungTokens,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_HOLDERH_DECL(classV, uint8_t); //   Ic(  [ 0  ...   1 ]   
        ITU_T_HOLDERH_DECL(numberOfTokens, Unsigned16); //   Ic(  [ 0  ...   32767 ]   
        ITU_T_HOLDERH_DECL(numberOfOwnedTokens, Unsigned16); //   Ic(  [ 0  ...   32767 ]   
        ITU_T_HOLDERH_DECL(numberOfHungTokens, Unsigned16); //   Ic(  [ 0  ...   32767 ]   
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportPoolSemaphoreStatus-Request

    struct ReportPoolSemaphoreStatus_Request {

        ReportPoolSemaphoreStatus_Request();

        ReportPoolSemaphoreStatus_Request(const ObjectName& arg__semaphoreName);

        ReportPoolSemaphoreStatus_Request(shared_ptr< ObjectName> arg__semaphoreName,
                shared_ptr< Identifier> arg__nameToStartAfter);

        ITU_T_HOLDERH_DECL(semaphoreName, ObjectName);
        ITU_T_OPTIONAL_DECL(nameToStartAfter, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportPoolSemaphoreStatus-Response

    struct ReportPoolSemaphoreStatus_Response {

        struct ListOfNamedTokens_type_sequence_of;

        enum ListOfNamedTokens_type_sequence_of_enum {

            ListOfNamedTokens_type_sequence_of_null = 0,
            ListOfNamedTokens_type_sequence_of_freeNamedToken,
            ListOfNamedTokens_type_sequence_of_ownedNamedToken,
            ListOfNamedTokens_type_sequence_of_hungNamedToken,
        };

        struct ListOfNamedTokens_type_sequence_of : public ITU_T_CHOICE(ListOfNamedTokens_type_sequence_of_enum) {


            ITU_T_CHOICE_CTORS(ListOfNamedTokens_type_sequence_of);

            ITU_T_CHOICES_DECL(freeNamedToken, Identifier, ListOfNamedTokens_type_sequence_of_freeNamedToken); // primitive
            ITU_T_CHOICES_DECL(ownedNamedToken, Identifier, ListOfNamedTokens_type_sequence_of_ownedNamedToken); // primitive
            ITU_T_CHOICES_DECL(hungNamedToken, Identifier, ListOfNamedTokens_type_sequence_of_hungNamedToken); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< ListOfNamedTokens_type_sequence_of > ListOfNamedTokens_type;

        static const bool moreFollows__default;

        ReportPoolSemaphoreStatus_Response();

        ReportPoolSemaphoreStatus_Response(const ListOfNamedTokens_type& arg__listOfNamedTokens);

        ReportPoolSemaphoreStatus_Response(shared_ptr< ListOfNamedTokens_type> arg__listOfNamedTokens,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfNamedTokens, ListOfNamedTokens_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportSemaphoreEntryStatus-Request

    struct ReportSemaphoreEntryStatus_Request {

        static const uint8_t state_queued;
        static const uint8_t state_owner;
        static const uint8_t state_hung;


        ReportSemaphoreEntryStatus_Request();

        ReportSemaphoreEntryStatus_Request(const ObjectName& arg__semaphoreName,
                const uint8_t& arg__state);

        ReportSemaphoreEntryStatus_Request(shared_ptr< ObjectName> arg__semaphoreName,
                shared_ptr< uint8_t> arg__state,
                shared_ptr< octet_string> arg__entryIDToStartAfter);

        ITU_T_HOLDERH_DECL(semaphoreName, ObjectName);
        ITU_T_HOLDERH_DECL(state, uint8_t); //   Ic(  [ 0  ...   2 ]   
        ITU_T_OPTIONAL_DECL(entryIDToStartAfter, octet_string);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportSemaphoreEntryStatus-Response

    struct ReportSemaphoreEntryStatus_Response {

        typedef sequence_of< SemaphoreEntry > ListOfSemaphoreEntry_type;

        static const bool moreFollows__default;

        ReportSemaphoreEntryStatus_Response();

        ReportSemaphoreEntryStatus_Response(const ListOfSemaphoreEntry_type& arg__listOfSemaphoreEntry);

        ReportSemaphoreEntryStatus_Response(shared_ptr< ListOfSemaphoreEntry_type> arg__listOfSemaphoreEntry,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfSemaphoreEntry, ListOfSemaphoreEntry_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence SemaphoreEntry

    struct SemaphoreEntry {

        static const uint8_t entryClass_simple;
        static const uint8_t entryClass_modifier;

        static const MMS_Object_Module_1::Priority priority__default;
        static const bool relinquishIfConnectionLost__default;

        SemaphoreEntry();

        SemaphoreEntry(const octet_string& arg__entryID,
                const uint8_t& arg__entryClass,
                const MMS_Environment_1::ApplicationReference& arg__applicationReference);

        SemaphoreEntry(shared_ptr< octet_string> arg__entryID,
                shared_ptr< uint8_t> arg__entryClass,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__applicationReference,
                shared_ptr< Identifier> arg__namedToken,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                shared_ptr< Unsigned32> arg__remainingTimeOut,
                shared_ptr< bool> arg__abortOnTimeOut,
                shared_ptr< bool> arg__relinquishIfConnectionLost);

        ITU_T_HOLDERH_DECL(entryID, octet_string);
        ITU_T_HOLDERH_DECL(entryClass, uint8_t); //   Ic(  [ 0  ...   1 ]   
        ITU_T_HOLDERH_DECL(applicationReference, MMS_Environment_1::ApplicationReference);
        ITU_T_OPTIONAL_DECL(namedToken, Identifier);
        ITU_T_DEFAULTH_DECL(priority, MMS_Object_Module_1::Priority, priority__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_OPTIONAL_DECL(remainingTimeOut, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(abortOnTimeOut, bool);
        ITU_T_DEFAULTH_DECL(relinquishIfConnectionLost, bool, relinquishIfConnectionLost__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AttachToSemaphore

    struct AttachToSemaphore {

        static const MMS_Object_Module_1::Priority priority__default;
        static const bool relinquishIfConnectionLost__default;

        AttachToSemaphore();

        AttachToSemaphore(const ObjectName& arg__semaphoreName);

        AttachToSemaphore(shared_ptr< ObjectName> arg__semaphoreName,
                shared_ptr< Identifier> arg__namedToken,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                shared_ptr< Unsigned32> arg__acceptableDelay,
                shared_ptr< Unsigned32> arg__controlTimeOut,
                shared_ptr< bool> arg__abortOnTimeOut,
                shared_ptr< bool> arg__relinquishIfConnectionLost);

        ITU_T_HOLDERH_DECL(semaphoreName, ObjectName);
        ITU_T_OPTIONAL_DECL(namedToken, Identifier);
        ITU_T_DEFAULTH_DECL(priority, MMS_Object_Module_1::Priority, priority__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_OPTIONAL_DECL(acceptableDelay, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(controlTimeOut, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(abortOnTimeOut, bool);
        ITU_T_DEFAULTH_DECL(relinquishIfConnectionLost, bool, relinquishIfConnectionLost__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Input-Request

    struct Input_Request {

        typedef sequence_of< MMSString > ListOfPromptData_type;

        static const bool echo__default;

        Input_Request();

        Input_Request(const Identifier& arg__operatorStationName);

        Input_Request(shared_ptr< Identifier> arg__operatorStationName,
                shared_ptr< bool> arg__echo,
                shared_ptr< ListOfPromptData_type> arg__listOfPromptData,
                shared_ptr< Unsigned32> arg__inputTimeOut);

        ITU_T_HOLDERH_DECL(operatorStationName, Identifier);
        ITU_T_DEFAULTH_DECL(echo, bool, echo__default);
        ITU_T_OPTIONAL_DECL(listOfPromptData, ListOfPromptData_type);
        ITU_T_OPTIONAL_DECL(inputTimeOut, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Output-Request

    struct Output_Request {

        typedef sequence_of< MMSString > ListOfOutputData_type;


        Output_Request();

        Output_Request(const Identifier& arg__operatorStationName,
                const ListOfOutputData_type& arg__listOfOutputData);

        ITU_T_HOLDERH_DECL(operatorStationName, Identifier);
        ITU_T_HOLDERH_DECL(listOfOutputData, ListOfOutputData_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence TriggerEvent-Request

    struct TriggerEvent_Request {

        TriggerEvent_Request();

        TriggerEvent_Request(const ObjectName& arg__eventConditionName);

        TriggerEvent_Request(shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority);

        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_OPTIONAL_DECL(priority, MMS_Object_Module_1::Priority); //   Ic(  [ 0  ...   127 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence EventNotification

    struct EventNotification {

        struct ActionResult_type;

        struct ActionResult_type {

            struct SuccessOrFailure_type;

            enum SuccessOrFailure_type_enum {

                SuccessOrFailure_type_null = 0,
                SuccessOrFailure_type_success,
                SuccessOrFailure_type_failure,
            };

            struct SuccessOrFailure_type : public ITU_T_CHOICE(SuccessOrFailure_type_enum) {


                struct Success_type;
                struct Failure_type;

                struct Success_type {

                    Success_type();

                    Success_type(const ConfirmedServiceResponse& arg__confirmedServiceResponse);

                    Success_type(shared_ptr< ConfirmedServiceResponse> arg__confirmedServiceResponse,
                            shared_ptr< Response_Detail> arg__cs_Response_Detail);

                    ITU_T_HOLDERH_DECL(confirmedServiceResponse, ConfirmedServiceResponse);
                    ITU_T_OPTIONAL_DECL(cs_Response_Detail, Response_Detail);

                    ITU_T_ARCHIVE_FUNC;
                };

                struct Failure_type {

                    Failure_type();

                    Failure_type(const ServiceError& arg__serviceError);

                    Failure_type(shared_ptr< Unsigned32> arg__modifierPosition,
                            shared_ptr< ServiceError> arg__serviceError);

                    ITU_T_OPTIONAL_DECL(modifierPosition, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
                    ITU_T_HOLDERH_DECL(serviceError, ServiceError);

                    ITU_T_ARCHIVE_FUNC;
                };


                ITU_T_CHOICE_CTORS(SuccessOrFailure_type);

                ITU_T_CHOICEC_DECL(success, Success_type, SuccessOrFailure_type_success);
                ITU_T_CHOICEC_DECL(failure, Failure_type, SuccessOrFailure_type_failure);

                ITU_T_ARCHIVE_FUNC;
            };


            ActionResult_type();

            ActionResult_type(const ObjectName& arg__eventActionName,
                    const SuccessOrFailure_type& arg__successOrFailure);

            ITU_T_HOLDERH_DECL(eventActionName, ObjectName);
            ITU_T_HOLDERH_DECL(successOrFailure, SuccessOrFailure_type);

            ITU_T_ARCHIVE_FUNC;
        };

        static const bool notificationLost__default;

        EventNotification();

        EventNotification(const ObjectName& arg__eventEnrollmentName,
                const ObjectName& arg__eventConditionName,
                const MMS_Object_Module_1::Severity& arg__severity,
                const MMS_Object_Module_1::EventTime& arg__transitionTime);

        EventNotification(shared_ptr< ObjectName> arg__eventEnrollmentName,
                shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
                shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__transitionTime,
                shared_ptr< bool> arg__notificationLost,
                shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
                shared_ptr< ActionResult_type> arg__actionResult);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_HOLDERH_DECL(severity, MMS_Object_Module_1::Severity); //   Ic(  [ 0  ...   127 ]   
        ITU_T_OPTIONAL_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
        ITU_T_HOLDERH_DECL(transitionTime, MMS_Object_Module_1::EventTime);
        ITU_T_DEFAULTH_DECL(notificationLost, bool, notificationLost__default);
        ITU_T_OPTIONAL_DECL(alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(actionResult, ActionResult_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CS-EventNotification

    enum CS_EventNotification_enum {

        CS_EventNotification_null = 0,
        CS_EventNotification_string,
        CS_EventNotification_index,
        CS_EventNotification_noEnhancement,
    };

    struct CS_EventNotification : public ITU_T_CHOICE(CS_EventNotification_enum) {


        ITU_T_CHOICE_CTORS(CS_EventNotification);

        ITU_T_CHOICES_DECL(string, visible_string, CS_EventNotification_string); // primitive
        ITU_T_CHOICES_DECL(index, integer_type, CS_EventNotification_index); // primitive
        ITU_T_CHOICES_DECL(noEnhancement, null_type, CS_EventNotification_noEnhancement); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AcknowledgeEventNotification-Request

    struct AcknowledgeEventNotification_Request {

        AcknowledgeEventNotification_Request();

        AcknowledgeEventNotification_Request(const ObjectName& arg__eventEnrollmentName,
                const MMS_Object_Module_1::EC_State& arg__acknowledgedState,
                const MMS_Object_Module_1::EventTime& arg__timeOfAcknowledgedTransition);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_HOLDERH_DECL(acknowledgedState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
        ITU_T_HOLDERH_DECL(timeOfAcknowledgedTransition, MMS_Object_Module_1::EventTime);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetAlarmSummary-Request

    struct GetAlarmSummary_Request {

        struct SeverityFilter_type;

        struct SeverityFilter_type {

            SeverityFilter_type();

            SeverityFilter_type(const Unsigned8& arg__mostSevere,
                    const Unsigned8& arg__leastSevere);

            ITU_T_HOLDERH_DECL(mostSevere, Unsigned8); //   Ic(  [ 0  ...   127 ]   
            ITU_T_HOLDERH_DECL(leastSevere, Unsigned8); //   Ic(  [ 0  ...   127 ]   

            ITU_T_ARCHIVE_FUNC;
        };

        static const uint8_t acknowledgementFilter_not_acked;
        static const uint8_t acknowledgementFilter_acked;
        static const uint8_t acknowledgementFilter_all;

        static const bool enrollmentsOnly__default;
        static const bool activeAlarmsOnly__default;
        static const uint8_t acknowledgementFilter__default;

        GetAlarmSummary_Request();

        GetAlarmSummary_Request(shared_ptr< bool> arg__enrollmentsOnly,
                shared_ptr< bool> arg__activeAlarmsOnly,
                shared_ptr< uint8_t> arg__acknowledgementFilter,
                shared_ptr< SeverityFilter_type> arg__severityFilter,
                shared_ptr< ObjectName> arg__continueAfter);

        ITU_T_DEFAULTH_DECL(enrollmentsOnly, bool, enrollmentsOnly__default);
        ITU_T_DEFAULTH_DECL(activeAlarmsOnly, bool, activeAlarmsOnly__default);
        ITU_T_DEFAULTH_DECL(acknowledgementFilter, uint8_t, acknowledgementFilter__default); //   Ic(  [ 0  ...   2 ]   
        ITU_T_OPTIONAL_DECL(severityFilter, SeverityFilter_type);
        ITU_T_OPTIONAL_DECL(continueAfter, ObjectName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetAlarmSummary-Response

    struct GetAlarmSummary_Response {

        typedef sequence_of< AlarmSummary > ListOfAlarmSummary_type;

        static const bool moreFollows__default;

        GetAlarmSummary_Response();

        GetAlarmSummary_Response(const ListOfAlarmSummary_type& arg__listOfAlarmSummary);

        GetAlarmSummary_Response(shared_ptr< ListOfAlarmSummary_type> arg__listOfAlarmSummary,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfAlarmSummary, ListOfAlarmSummary_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlarmSummary

    struct AlarmSummary {

        static const uint8_t unacknowledgedState_none;
        static const uint8_t unacknowledgedState_active;
        static const uint8_t unacknowledgedState_idle;
        static const uint8_t unacknowledgedState_both;


        AlarmSummary();

        AlarmSummary(const ObjectName& arg__eventConditionName,
                const Unsigned8& arg__severity,
                const MMS_Object_Module_1::EC_State& arg__currentState,
                const uint8_t& arg__unacknowledgedState);

        AlarmSummary(shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< Unsigned8> arg__severity,
                shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
                shared_ptr< uint8_t> arg__unacknowledgedState,
                shared_ptr< EN_Additional_Detail> arg__displayEnhancement,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle);

        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_HOLDERH_DECL(severity, Unsigned8); //   Ic(  [ 0  ...   127 ]   
        ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
        ITU_T_HOLDERH_DECL(unacknowledgedState, uint8_t); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(displayEnhancement, EN_Additional_Detail);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice EN-Additional-Detail

    enum EN_Additional_Detail_enum {

        EN_Additional_Detail_null = 0,
        EN_Additional_Detail_string,
        EN_Additional_Detail_index,
        EN_Additional_Detail_noEnhancement,
    };

    struct EN_Additional_Detail : public ITU_T_CHOICE(EN_Additional_Detail_enum) {


        ITU_T_CHOICE_CTORS(EN_Additional_Detail);

        ITU_T_CHOICES_DECL(string, visible_string, EN_Additional_Detail_string); // primitive
        ITU_T_CHOICES_DECL(index, integer_type, EN_Additional_Detail_index); // primitive
        ITU_T_CHOICES_DECL(noEnhancement, null_type, EN_Additional_Detail_noEnhancement); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetAlarmEnrollmentSummary-Request

    struct GetAlarmEnrollmentSummary_Request {

        struct SeverityFilter_type;

        struct SeverityFilter_type {

            SeverityFilter_type();

            SeverityFilter_type(const Unsigned8& arg__mostSevere,
                    const Unsigned8& arg__leastSevere);

            ITU_T_HOLDERH_DECL(mostSevere, Unsigned8); //   Ic(  [ 0  ...   127 ]   
            ITU_T_HOLDERH_DECL(leastSevere, Unsigned8); //   Ic(  [ 0  ...   127 ]   

            ITU_T_ARCHIVE_FUNC;
        };

        static const uint8_t acknowledgementFilter_not_acked;
        static const uint8_t acknowledgementFilter_acked;
        static const uint8_t acknowledgementFilter_all;

        static const bool enrollmentsOnly__default;
        static const bool activeAlarmsOnly__default;
        static const uint8_t acknowledgementFilter__default;

        GetAlarmEnrollmentSummary_Request();

        GetAlarmEnrollmentSummary_Request(shared_ptr< bool> arg__enrollmentsOnly,
                shared_ptr< bool> arg__activeAlarmsOnly,
                shared_ptr< uint8_t> arg__acknowledgementFilter,
                shared_ptr< SeverityFilter_type> arg__severityFilter,
                shared_ptr< ObjectName> arg__continueAfter);

        ITU_T_DEFAULTH_DECL(enrollmentsOnly, bool, enrollmentsOnly__default);
        ITU_T_DEFAULTH_DECL(activeAlarmsOnly, bool, activeAlarmsOnly__default);
        ITU_T_DEFAULTH_DECL(acknowledgementFilter, uint8_t, acknowledgementFilter__default); //   Ic(  [ 0  ...   2 ]   
        ITU_T_OPTIONAL_DECL(severityFilter, SeverityFilter_type);
        ITU_T_OPTIONAL_DECL(continueAfter, ObjectName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetAlarmEnrollmentSummary-Response

    struct GetAlarmEnrollmentSummary_Response {

        typedef sequence_of< AlarmEnrollmentSummary > ListOfAlarmEnrollmentSummary_type;

        static const bool moreFollows__default;

        GetAlarmEnrollmentSummary_Response();

        GetAlarmEnrollmentSummary_Response(const ListOfAlarmEnrollmentSummary_type& arg__listOfAlarmEnrollmentSummary);

        GetAlarmEnrollmentSummary_Response(shared_ptr< ListOfAlarmEnrollmentSummary_type> arg__listOfAlarmEnrollmentSummary,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfAlarmEnrollmentSummary, ListOfAlarmEnrollmentSummary_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlarmEnrollmentSummary

    struct AlarmEnrollmentSummary {

        static const bool notificationLost__default;

        AlarmEnrollmentSummary();

        AlarmEnrollmentSummary(const ObjectName& arg__eventEnrollmentName,
                const Unsigned8& arg__severity,
                const MMS_Object_Module_1::EC_State& arg__currentState,
                const MMS_Object_Module_1::AlarmAckRule& arg__alarmAcknowledgmentRule);

        AlarmEnrollmentSummary(shared_ptr< ObjectName> arg__eventEnrollmentName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                shared_ptr< Unsigned8> arg__severity,
                shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
                shared_ptr< EN_Additional_Detail> arg__displayEnhancement,
                shared_ptr< bool> arg__notificationLost,
                shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
                shared_ptr< EE_State> arg__enrollmentState,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeActiveAcknowledged,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeIdleAcknowledged);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(severity, Unsigned8); //   Ic(  [ 0  ...   127 ]   
        ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
        ITU_T_OPTIONAL_DECL(displayEnhancement, EN_Additional_Detail);
        ITU_T_DEFAULTH_DECL(notificationLost, bool, notificationLost__default);
        ITU_T_HOLDERH_DECL(alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(enrollmentState, EE_State);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
        ITU_T_OPTIONAL_DECL(timeActiveAcknowledged, MMS_Object_Module_1::EventTime);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);
        ITU_T_OPTIONAL_DECL(timeIdleAcknowledged, MMS_Object_Module_1::EventTime);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AttachToEventCondition

    struct AttachToEventCondition {

        AttachToEventCondition();

        AttachToEventCondition(const ObjectName& arg__eventEnrollmentName,
                const ObjectName& arg__eventConditionName,
                const MMS_Object_Module_1::Transitions& arg__causingTransitions);

        AttachToEventCondition(shared_ptr< ObjectName> arg__eventEnrollmentName,
                shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< MMS_Object_Module_1::Transitions> arg__causingTransitions,
                shared_ptr< Unsigned32> arg__acceptableDelay);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_HOLDERH_DECL(causingTransitions, MMS_Object_Module_1::Transitions); //    Sc (  [ 7 ]   
        ITU_T_OPTIONAL_DECL(acceptableDelay, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineEventCondition-Request

    struct DefineEventCondition_Request {

        static const MMS_Object_Module_1::Priority priority__default;
        static const Unsigned8 severity__default;

        DefineEventCondition_Request();

        DefineEventCondition_Request(const ObjectName& arg__eventConditionName,
                const MMS_Object_Module_1::EC_Class& arg__classV);

        DefineEventCondition_Request(shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< MMS_Object_Module_1::EC_Class> arg__classV,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                shared_ptr< Unsigned8> arg__severity,
                shared_ptr< bool> arg__alarmSummaryReports,
                shared_ptr< VariableSpecification> arg__monitoredVariable,
                shared_ptr< Unsigned32> arg__evaluationInterval);

        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_HOLDERH_DECL(classV, MMS_Object_Module_1::EC_Class); //   Ic(  [ 0  ...   1 ]   
        ITU_T_DEFAULTH_DECL(priority, MMS_Object_Module_1::Priority, priority__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_DEFAULTH_DECL(severity, Unsigned8, severity__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_OPTIONAL_DECL(alarmSummaryReports, bool);
        ITU_T_OPTIONAL_DECL(monitoredVariable, VariableSpecification);
        ITU_T_OPTIONAL_DECL(evaluationInterval, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CS-DefineEventCondition-Request

    enum CS_DefineEventCondition_Request_enum {

        CS_DefineEventCondition_Request_null = 0,
        CS_DefineEventCondition_Request_string,
        CS_DefineEventCondition_Request_index,
        CS_DefineEventCondition_Request_noEnhancement,
    };

    struct CS_DefineEventCondition_Request : public ITU_T_CHOICE(CS_DefineEventCondition_Request_enum) {


        ITU_T_CHOICE_CTORS(CS_DefineEventCondition_Request);

        ITU_T_CHOICES_DECL(string, visible_string, CS_DefineEventCondition_Request_string); // primitive
        ITU_T_CHOICES_DECL(index, integer_type, CS_DefineEventCondition_Request_index); // primitive
        ITU_T_CHOICES_DECL(noEnhancement, null_type, CS_DefineEventCondition_Request_noEnhancement); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice DeleteEventCondition-Request

    enum DeleteEventCondition_Request_enum {

        DeleteEventCondition_Request_null = 0,
        DeleteEventCondition_Request_specific,
        DeleteEventCondition_Request_aa_specific,
        DeleteEventCondition_Request_domain,
        DeleteEventCondition_Request_vmd,
    };

    struct DeleteEventCondition_Request : public ITU_T_CHOICE(DeleteEventCondition_Request_enum) {



        typedef sequence_of< ObjectName > Specific_type;


        ITU_T_CHOICE_CTORS(DeleteEventCondition_Request);

        ITU_T_CHOICEC_DECL(specific, Specific_type, DeleteEventCondition_Request_specific);
        ITU_T_CHOICES_DECL(aa_specific, null_type, DeleteEventCondition_Request_aa_specific); // primitive
        ITU_T_CHOICES_DECL(domain, Identifier, DeleteEventCondition_Request_domain); // primitive
        ITU_T_CHOICES_DECL(vmd, null_type, DeleteEventCondition_Request_vmd); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetEventConditionAttributes-Response

    struct GetEventConditionAttributes_Response {

        struct MonitoredVariable_type;

        enum MonitoredVariable_type_enum {

            MonitoredVariable_type_null = 0,
            MonitoredVariable_type_variableReference,
            MonitoredVariable_type_undefined,
        };

        struct MonitoredVariable_type : public ITU_T_CHOICE(MonitoredVariable_type_enum) {


            ITU_T_CHOICE_CTORS(MonitoredVariable_type);

            ITU_T_CHOICEC_DECL(variableReference, VariableSpecification, MonitoredVariable_type_variableReference);
            ITU_T_CHOICES_DECL(undefined, null_type, MonitoredVariable_type_undefined); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        static const bool mmsDeletable__default;
        static const MMS_Object_Module_1::Priority priority__default;
        static const Unsigned8 severity__default;
        static const bool alarmSummaryReports__default;

        GetEventConditionAttributes_Response();

        GetEventConditionAttributes_Response(const MMS_Object_Module_1::EC_Class& arg__classV);

        GetEventConditionAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< MMS_Object_Module_1::EC_Class> arg__classV,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                shared_ptr< Unsigned8> arg__severity,
                shared_ptr< bool> arg__alarmSummaryReports,
                shared_ptr< MonitoredVariable_type> arg__monitoredVariable,
                shared_ptr< Unsigned32> arg__evaluationInterval,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_DEFAULTH_DECL(mmsDeletable, bool, mmsDeletable__default);
        ITU_T_HOLDERH_DECL(classV, MMS_Object_Module_1::EC_Class); //   Ic(  [ 0  ...   1 ]   
        ITU_T_DEFAULTH_DECL(priority, MMS_Object_Module_1::Priority, priority__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_DEFAULTH_DECL(severity, Unsigned8, severity__default); //   Ic(  [ 0  ...   127 ]   
        ITU_T_DEFAULTH_DECL(alarmSummaryReports, bool, alarmSummaryReports__default);
        ITU_T_OPTIONAL_DECL(monitoredVariable, MonitoredVariable_type);
        ITU_T_OPTIONAL_DECL(evaluationInterval, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CS-GetEventConditionAttributes-Response

    struct CS_GetEventConditionAttributes_Response {

        struct GroupPriorityOverride_type;
        struct DisplayEnhancement_type;

        enum GroupPriorityOverride_type_enum {

            GroupPriorityOverride_type_null = 0,
            GroupPriorityOverride_type_priority,
            GroupPriorityOverride_type_undefined,
        };

        struct GroupPriorityOverride_type : public ITU_T_CHOICE(GroupPriorityOverride_type_enum) {


            ITU_T_CHOICE_CTORS(GroupPriorityOverride_type);

            ITU_T_CHOICES_DECL(priority, MMS_Object_Module_1::Priority, GroupPriorityOverride_type_priority); // primitive  //   Ic(  [ 0  ...   127 ]   
            ITU_T_CHOICES_DECL(undefined, null_type, GroupPriorityOverride_type_undefined); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        enum DisplayEnhancement_type_enum {

            DisplayEnhancement_type_null = 0,
            DisplayEnhancement_type_string,
            DisplayEnhancement_type_index,
            DisplayEnhancement_type_noEnhancement,
        };

        struct DisplayEnhancement_type : public ITU_T_CHOICE(DisplayEnhancement_type_enum) {


            ITU_T_CHOICE_CTORS(DisplayEnhancement_type);

            ITU_T_CHOICES_DECL(string, visible_string, DisplayEnhancement_type_string); // primitive
            ITU_T_CHOICES_DECL(index, integer_type, DisplayEnhancement_type_index); // primitive
            ITU_T_CHOICES_DECL(noEnhancement, null_type, DisplayEnhancement_type_noEnhancement); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< ObjectName > ListOfReferencingECL_type;


        CS_GetEventConditionAttributes_Response();

        CS_GetEventConditionAttributes_Response(const DisplayEnhancement_type& arg__displayEnhancement);

        CS_GetEventConditionAttributes_Response(shared_ptr< GroupPriorityOverride_type> arg__groupPriorityOverride,
                shared_ptr< ListOfReferencingECL_type> arg__listOfReferencingECL,
                shared_ptr< DisplayEnhancement_type> arg__displayEnhancement);

        ITU_T_OPTIONAL_DECL(groupPriorityOverride, GroupPriorityOverride_type);
        ITU_T_OPTIONAL_DECL(listOfReferencingECL, ListOfReferencingECL_type);
        ITU_T_HOLDERH_DECL(displayEnhancement, DisplayEnhancement_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportEventConditionStatus-Response

    struct ReportEventConditionStatus_Response {

        ReportEventConditionStatus_Response();

        ReportEventConditionStatus_Response(const MMS_Object_Module_1::EC_State& arg__currentState,
                const Unsigned32& arg__numberOfEventEnrollments);

        ReportEventConditionStatus_Response(shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
                shared_ptr< Unsigned32> arg__numberOfEventEnrollments,
                shared_ptr< bool> arg__enabled,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle);

        ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
        ITU_T_HOLDERH_DECL(numberOfEventEnrollments, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(enabled, bool);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlterEventConditionMonitoring-Request

    struct AlterEventConditionMonitoring_Request {

        AlterEventConditionMonitoring_Request();

        AlterEventConditionMonitoring_Request(const ObjectName& arg__eventConditionName);

        AlterEventConditionMonitoring_Request(shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< bool> arg__enabled,
                shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                shared_ptr< bool> arg__alarmSummaryReports,
                shared_ptr< Unsigned32> arg__evaluationInterval);

        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_OPTIONAL_DECL(enabled, bool);
        ITU_T_OPTIONAL_DECL(priority, MMS_Object_Module_1::Priority); //   Ic(  [ 0  ...   127 ]   
        ITU_T_OPTIONAL_DECL(alarmSummaryReports, bool);
        ITU_T_OPTIONAL_DECL(evaluationInterval, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CS-AlterEventConditionMonitoring-Request

    struct CS_AlterEventConditionMonitoring_Request {

        struct ChangeDisplay_type;

        enum ChangeDisplay_type_enum {

            ChangeDisplay_type_null = 0,
            ChangeDisplay_type_string,
            ChangeDisplay_type_index,
            ChangeDisplay_type_noEnhancement,
        };

        struct ChangeDisplay_type : public ITU_T_CHOICE(ChangeDisplay_type_enum) {


            ITU_T_CHOICE_CTORS(ChangeDisplay_type);

            ITU_T_CHOICES_DECL(string, visible_string, ChangeDisplay_type_string); // primitive
            ITU_T_CHOICES_DECL(index, integer_type, ChangeDisplay_type_index); // primitive
            ITU_T_CHOICES_DECL(noEnhancement, null_type, ChangeDisplay_type_noEnhancement); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        CS_AlterEventConditionMonitoring_Request();

        CS_AlterEventConditionMonitoring_Request(shared_ptr< ChangeDisplay_type> arg__changeDisplay);

        ITU_T_OPTIONAL_DECL(changeDisplay, ChangeDisplay_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineEventAction-Request

    struct DefineEventAction_Request {

        typedef sequence_of< MMS_Object_Module_1::Modifier > ListOfModifier_type;

        DefineEventAction_Request();

        DefineEventAction_Request(const ObjectName& arg__eventActionName,
                const ConfirmedServiceRequest& arg__confirmedServiceRequest);

        DefineEventAction_Request(shared_ptr< ObjectName> arg__eventActionName,
                shared_ptr< ListOfModifier_type> arg__listOfModifier,
                shared_ptr< ConfirmedServiceRequest> arg__confirmedServiceRequest,
                shared_ptr< Request_Detail> arg__cs_extension);

        ITU_T_HOLDERH_DECL(eventActionName, ObjectName);
        ITU_T_OPTIONAL_DECL(listOfModifier, ListOfModifier_type);
        ITU_T_HOLDERH_DECL(confirmedServiceRequest, ConfirmedServiceRequest);
        ITU_T_OPTIONAL_DECL(cs_extension, Request_Detail);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice DeleteEventAction-Request

    enum DeleteEventAction_Request_enum {

        DeleteEventAction_Request_null = 0,
        DeleteEventAction_Request_specific,
        DeleteEventAction_Request_aa_specific,
        DeleteEventAction_Request_domain,
        DeleteEventAction_Request_vmd,
    };

    struct DeleteEventAction_Request : public ITU_T_CHOICE(DeleteEventAction_Request_enum) {



        typedef sequence_of< ObjectName > Specific_type;


        ITU_T_CHOICE_CTORS(DeleteEventAction_Request);

        ITU_T_CHOICEC_DECL(specific, Specific_type, DeleteEventAction_Request_specific);
        ITU_T_CHOICES_DECL(aa_specific, null_type, DeleteEventAction_Request_aa_specific); // primitive
        ITU_T_CHOICES_DECL(domain, Identifier, DeleteEventAction_Request_domain); // primitive
        ITU_T_CHOICES_DECL(vmd, null_type, DeleteEventAction_Request_vmd); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetEventActionAttributes-Response

    struct GetEventActionAttributes_Response {

        typedef sequence_of< MMS_Object_Module_1::Modifier > ListOfModifier_type;
        static const bool mmsDeletable__default;

        GetEventActionAttributes_Response();

        GetEventActionAttributes_Response(const ListOfModifier_type& arg__listOfModifier,
                const ConfirmedServiceRequest& arg__confirmedServiceRequest);

        GetEventActionAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< ListOfModifier_type> arg__listOfModifier,
                shared_ptr< ConfirmedServiceRequest> arg__confirmedServiceRequest,
                shared_ptr< Request_Detail> arg__cs_extension,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_DEFAULTH_DECL(mmsDeletable, bool, mmsDeletable__default);
        ITU_T_HOLDERH_DECL(listOfModifier, ListOfModifier_type);
        ITU_T_HOLDERH_DECL(confirmedServiceRequest, ConfirmedServiceRequest);
        ITU_T_OPTIONAL_DECL(cs_extension, Request_Detail);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineEventEnrollment-Request

    struct DefineEventEnrollment_Request {

        DefineEventEnrollment_Request();

        DefineEventEnrollment_Request(const ObjectName& arg__eventEnrollmentName,
                const ObjectName& arg__eventConditionName,
                const MMS_Object_Module_1::Transitions& arg__eventConditionTransitions,
                const MMS_Object_Module_1::AlarmAckRule& arg__alarmAcknowledgmentRule);

        DefineEventEnrollment_Request(shared_ptr< ObjectName> arg__eventEnrollmentName,
                shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
                shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
                shared_ptr< ObjectName> arg__eventActionName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_HOLDERH_DECL(eventConditionTransitions, MMS_Object_Module_1::Transitions); //    Sc (  [ 7 ]   
        ITU_T_HOLDERH_DECL(alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(eventActionName, ObjectName);
        ITU_T_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice CS-DefineEventEnrollment-Request

    enum CS_DefineEventEnrollment_Request_enum {

        CS_DefineEventEnrollment_Request_null = 0,
        CS_DefineEventEnrollment_Request_string,
        CS_DefineEventEnrollment_Request_index,
        CS_DefineEventEnrollment_Request_noEnhancement,
    };

    struct CS_DefineEventEnrollment_Request : public ITU_T_CHOICE(CS_DefineEventEnrollment_Request_enum) {


        ITU_T_CHOICE_CTORS(CS_DefineEventEnrollment_Request);

        ITU_T_CHOICES_DECL(string, visible_string, CS_DefineEventEnrollment_Request_string); // primitive
        ITU_T_CHOICES_DECL(index, integer_type, CS_DefineEventEnrollment_Request_index); // primitive
        ITU_T_CHOICES_DECL(noEnhancement, null_type, CS_DefineEventEnrollment_Request_noEnhancement); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice DeleteEventEnrollment-Request

    enum DeleteEventEnrollment_Request_enum {

        DeleteEventEnrollment_Request_null = 0,
        DeleteEventEnrollment_Request_specific,
        DeleteEventEnrollment_Request_ec,
        DeleteEventEnrollment_Request_ea,
    };

    struct DeleteEventEnrollment_Request : public ITU_T_CHOICE(DeleteEventEnrollment_Request_enum) {



        typedef sequence_of< ObjectName > Specific_type;


        ITU_T_CHOICE_CTORS(DeleteEventEnrollment_Request);

        ITU_T_CHOICEC_DECL(specific, Specific_type, DeleteEventEnrollment_Request_specific);
        ITU_T_CHOICEC_DECL(ec, ObjectName, DeleteEventEnrollment_Request_ec);
        ITU_T_CHOICEC_DECL(ea, ObjectName, DeleteEventEnrollment_Request_ea);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetEventEnrollmentAttributes-Request

    struct GetEventEnrollmentAttributes_Request {

        typedef sequence_of< ObjectName > EventEnrollmentNames_type;

        static const uint8_t scopeOfRequest_specific;
        static const uint8_t scopeOfRequest_client;
        static const uint8_t scopeOfRequest_ec;
        static const uint8_t scopeOfRequest_ea;

        static const uint8_t scopeOfRequest__default;

        GetEventEnrollmentAttributes_Request();

        GetEventEnrollmentAttributes_Request(shared_ptr< uint8_t> arg__scopeOfRequest,
                shared_ptr< EventEnrollmentNames_type> arg__eventEnrollmentNames,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< ObjectName> arg__eventActionName,
                shared_ptr< ObjectName> arg__continueAfter);

        ITU_T_DEFAULTH_DECL(scopeOfRequest, uint8_t, scopeOfRequest__default); //   Ic(  [ 0  ...   3 ]   
        ITU_T_OPTIONAL_DECL(eventEnrollmentNames, EventEnrollmentNames_type);
        ITU_T_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
        ITU_T_OPTIONAL_DECL(eventConditionName, ObjectName);
        ITU_T_OPTIONAL_DECL(eventActionName, ObjectName);
        ITU_T_OPTIONAL_DECL(continueAfter, ObjectName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetEventEnrollmentAttributes-Response

    struct GetEventEnrollmentAttributes_Response {

        typedef sequence_of< EEAttributes > ListOfEEAttributes_type;

        static const bool moreFollows__default;

        GetEventEnrollmentAttributes_Response();

        GetEventEnrollmentAttributes_Response(const ListOfEEAttributes_type& arg__listOfEEAttributes);

        GetEventEnrollmentAttributes_Response(shared_ptr< ListOfEEAttributes_type> arg__listOfEEAttributes,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfEEAttributes, ListOfEEAttributes_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence EEAttributes

    struct EEAttributes {

        struct EventConditionName_type;
        struct EventActionName_type;
        struct DisplayEnhancement_type;

        enum EventConditionName_type_enum {

            EventConditionName_type_null = 0,
            EventConditionName_type_eventCondition,
            EventConditionName_type_undefined,
        };

        struct EventConditionName_type : public ITU_T_CHOICE(EventConditionName_type_enum) {


            ITU_T_CHOICE_CTORS(EventConditionName_type);

            ITU_T_CHOICEC_DECL(eventCondition, ObjectName, EventConditionName_type_eventCondition);
            ITU_T_CHOICES_DECL(undefined, null_type, EventConditionName_type_undefined); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        enum EventActionName_type_enum {

            EventActionName_type_null = 0,
            EventActionName_type_eventAction,
            EventActionName_type_undefined,
        };

        struct EventActionName_type : public ITU_T_CHOICE(EventActionName_type_enum) {


            ITU_T_CHOICE_CTORS(EventActionName_type);

            ITU_T_CHOICEC_DECL(eventAction, ObjectName, EventActionName_type_eventAction);
            ITU_T_CHOICES_DECL(undefined, null_type, EventActionName_type_undefined); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        enum DisplayEnhancement_type_enum {

            DisplayEnhancement_type_null = 0,
            DisplayEnhancement_type_string,
            DisplayEnhancement_type_index,
            DisplayEnhancement_type_noEnhancement,
        };

        struct DisplayEnhancement_type : public ITU_T_CHOICE(DisplayEnhancement_type_enum) {


            ITU_T_CHOICE_CTORS(DisplayEnhancement_type);

            ITU_T_CHOICES_DECL(string, visible_string, DisplayEnhancement_type_string); // primitive
            ITU_T_CHOICES_DECL(index, integer_type, DisplayEnhancement_type_index); // primitive
            ITU_T_CHOICES_DECL(noEnhancement, null_type, DisplayEnhancement_type_noEnhancement); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        static const bool mmsDeletable__default;
        static const MMS_Object_Module_1::EE_Duration duration__default;

        EEAttributes();

        EEAttributes(const ObjectName& arg__eventEnrollmentName,
                const EventConditionName_type& arg__eventConditionName,
                const MMS_Object_Module_1::EE_Class& arg__enrollmentClass,
                const DisplayEnhancement_type& arg__displayEnhancement);

        EEAttributes(shared_ptr< ObjectName> arg__eventEnrollmentName,
                shared_ptr< EventConditionName_type> arg__eventConditionName,
                shared_ptr< EventActionName_type> arg__eventActionName,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< MMS_Object_Module_1::EE_Class> arg__enrollmentClass,
                shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
                shared_ptr< Unsigned32> arg__invokeID,
                shared_ptr< Unsigned32> arg__remainingAcceptableDelay,
                shared_ptr< DisplayEnhancement_type> arg__displayEnhancement);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_HOLDERH_DECL(eventConditionName, EventConditionName_type);
        ITU_T_OPTIONAL_DECL(eventActionName, EventActionName_type);
        ITU_T_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
        ITU_T_DEFAULTH_DECL(mmsDeletable, bool, mmsDeletable__default);
        ITU_T_HOLDERH_DECL(enrollmentClass, MMS_Object_Module_1::EE_Class); //   Ic(  [ 0  ...   1 ]   
        ITU_T_DEFAULTH_DECL(duration, MMS_Object_Module_1::EE_Duration, duration__default); //   Ic(  [ 0  ...   1 ]   
        ITU_T_OPTIONAL_DECL(invokeID, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(remainingAcceptableDelay, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(displayEnhancement, DisplayEnhancement_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportEventEnrollmentStatus-Response

    struct ReportEventEnrollmentStatus_Response {

        static const bool notificationLost__default;

        ReportEventEnrollmentStatus_Response();

        ReportEventEnrollmentStatus_Response(const MMS_Object_Module_1::Transitions& arg__eventConditionTransitions,
                const MMS_Object_Module_1::EE_Duration& arg__duration,
                const EE_State& arg__currentState);

        ReportEventEnrollmentStatus_Response(shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
                shared_ptr< bool> arg__notificationLost,
                shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
                shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
                shared_ptr< EE_State> arg__currentState);

        ITU_T_HOLDERH_DECL(eventConditionTransitions, MMS_Object_Module_1::Transitions); //    Sc (  [ 7 ]   
        ITU_T_DEFAULTH_DECL(notificationLost, bool, notificationLost__default);
        ITU_T_HOLDERH_DECL(duration, MMS_Object_Module_1::EE_Duration); //   Ic(  [ 0  ...   1 ]   
        ITU_T_OPTIONAL_DECL(alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule); //   Ic(  [ 0  ...   3 ]   
        ITU_T_HOLDERH_DECL(currentState, EE_State);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlterEventEnrollment-Request

    struct AlterEventEnrollment_Request {

        AlterEventEnrollment_Request();

        AlterEventEnrollment_Request(const ObjectName& arg__eventEnrollmentName);

        AlterEventEnrollment_Request(shared_ptr< ObjectName> arg__eventEnrollmentName,
                shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
                shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule);

        ITU_T_HOLDERH_DECL(eventEnrollmentName, ObjectName);
        ITU_T_OPTIONAL_DECL(eventConditionTransitions, MMS_Object_Module_1::Transitions); //    Sc (  [ 7 ]   
        ITU_T_OPTIONAL_DECL(alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule); //   Ic(  [ 0  ...   3 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlterEventEnrollment-Response

    struct AlterEventEnrollment_Response {

        struct CurrentState_type;

        enum CurrentState_type_enum {

            CurrentState_type_null = 0,
            CurrentState_type_state,
            CurrentState_type_undefined,
        };

        struct CurrentState_type : public ITU_T_CHOICE(CurrentState_type_enum) {


            ITU_T_CHOICE_CTORS(CurrentState_type);

            ITU_T_CHOICES_DECL(state, EE_State, CurrentState_type_state); // primitive
            ITU_T_CHOICES_DECL(undefined, null_type, CurrentState_type_undefined); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        AlterEventEnrollment_Response();

        AlterEventEnrollment_Response(const CurrentState_type& arg__currentState,
                const MMS_Object_Module_1::EventTime& arg__transitionTime);

        ITU_T_HOLDERH_DECL(currentState, CurrentState_type);
        ITU_T_HOLDERH_DECL(transitionTime, MMS_Object_Module_1::EventTime);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CS-AlterEventEnrollment-Request

    struct CS_AlterEventEnrollment_Request {

        struct ChangeDisplay_type;

        enum ChangeDisplay_type_enum {

            ChangeDisplay_type_null = 0,
            ChangeDisplay_type_string,
            ChangeDisplay_type_index,
            ChangeDisplay_type_noEnhancement,
        };

        struct ChangeDisplay_type : public ITU_T_CHOICE(ChangeDisplay_type_enum) {


            ITU_T_CHOICE_CTORS(ChangeDisplay_type);

            ITU_T_CHOICES_DECL(string, visible_string, ChangeDisplay_type_string); // primitive
            ITU_T_CHOICES_DECL(index, integer_type, ChangeDisplay_type_index); // primitive
            ITU_T_CHOICES_DECL(noEnhancement, null_type, ChangeDisplay_type_noEnhancement); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        CS_AlterEventEnrollment_Request();

        CS_AlterEventEnrollment_Request(shared_ptr< ChangeDisplay_type> arg__changeDisplay);

        ITU_T_OPTIONAL_DECL(changeDisplay, ChangeDisplay_type);

        ITU_T_ARCHIVE_FUNC;
    };

    const EE_State eE_State_disabled = 0;
    const EE_State eE_State_idle = 1;
    const EE_State eE_State_active = 2;
    const EE_State eE_State_activeNoAckA = 3;
    const EE_State eE_State_idleNoAckI = 4;
    const EE_State eE_State_idleNoAckA = 5;
    const EE_State eE_State_idleAcked = 6;
    const EE_State eE_State_activeAcked = 7;
    const EE_State eE_State_undefined = 8;

    // sequence DefineEventConditionList-Request

    struct DefineEventConditionList_Request {

        typedef sequence_of< ObjectName > ListOfEventConditionName_type;
        typedef sequence_of< ObjectName > ListOfEventConditionListName_type;


        DefineEventConditionList_Request();

        DefineEventConditionList_Request(const ObjectName& arg__eventConditionListName,
                const ListOfEventConditionName_type& arg__listOfEventConditionName);

        DefineEventConditionList_Request(shared_ptr< ObjectName> arg__eventConditionListName,
                shared_ptr< ListOfEventConditionName_type> arg__listOfEventConditionName,
                shared_ptr< ListOfEventConditionListName_type> arg__listOfEventConditionListName);

        ITU_T_HOLDERH_DECL(eventConditionListName, ObjectName);
        ITU_T_HOLDERH_DECL(listOfEventConditionName, ListOfEventConditionName_type);
        ITU_T_OPTIONAL_DECL(listOfEventConditionListName, ListOfEventConditionListName_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AddEventConditionListReference-Request

    struct AddEventConditionListReference_Request {

        typedef sequence_of< ObjectName > ListOfEventConditionName_type;
        typedef sequence_of< ObjectName > ListOfEventConditionListName_type;


        AddEventConditionListReference_Request();

        AddEventConditionListReference_Request(const ObjectName& arg__eventConditionListName,
                const ListOfEventConditionName_type& arg__listOfEventConditionName);

        AddEventConditionListReference_Request(shared_ptr< ObjectName> arg__eventConditionListName,
                shared_ptr< ListOfEventConditionName_type> arg__listOfEventConditionName,
                shared_ptr< ListOfEventConditionListName_type> arg__listOfEventConditionListName);

        ITU_T_HOLDERH_DECL(eventConditionListName, ObjectName);
        ITU_T_HOLDERH_DECL(listOfEventConditionName, ListOfEventConditionName_type);
        ITU_T_OPTIONAL_DECL(listOfEventConditionListName, ListOfEventConditionListName_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence RemoveEventConditionListReference-Request

    struct RemoveEventConditionListReference_Request {

        typedef sequence_of< ObjectName > ListOfEventConditionName_type;
        typedef sequence_of< ObjectName > ListOfEventConditionListName_type;


        RemoveEventConditionListReference_Request();

        RemoveEventConditionListReference_Request(const ObjectName& arg__eventConditionListName,
                const ListOfEventConditionName_type& arg__listOfEventConditionName,
                const ListOfEventConditionListName_type& arg__listOfEventConditionListName);

        ITU_T_HOLDERH_DECL(eventConditionListName, ObjectName);
        ITU_T_HOLDERH_DECL(listOfEventConditionName, ListOfEventConditionName_type);
        ITU_T_HOLDERH_DECL(listOfEventConditionListName, ListOfEventConditionListName_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice RemoveEventConditionListReference-Error

    enum RemoveEventConditionListReference_Error_enum {

        RemoveEventConditionListReference_Error_null = 0,
        RemoveEventConditionListReference_Error_eventCondition,
        RemoveEventConditionListReference_Error_eventConditionList,
    };

    struct RemoveEventConditionListReference_Error : public ITU_T_CHOICE(RemoveEventConditionListReference_Error_enum) {


        ITU_T_CHOICE_CTORS(RemoveEventConditionListReference_Error);

        ITU_T_CHOICEC_DECL(eventCondition, ObjectName, RemoveEventConditionListReference_Error_eventCondition);
        ITU_T_CHOICEC_DECL(eventConditionList, ObjectName, RemoveEventConditionListReference_Error_eventConditionList);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetEventConditionListAttributes-Response

    struct GetEventConditionListAttributes_Response {

        typedef sequence_of< ObjectName > ListOfEventConditionName_type;
        typedef sequence_of< ObjectName > ListOfEventConditionListName_type;


        GetEventConditionListAttributes_Response();

        GetEventConditionListAttributes_Response(const ListOfEventConditionName_type& arg__listOfEventConditionName);

        GetEventConditionListAttributes_Response(shared_ptr< ListOfEventConditionName_type> arg__listOfEventConditionName,
                shared_ptr< ListOfEventConditionListName_type> arg__listOfEventConditionListName);

        ITU_T_HOLDERH_DECL(listOfEventConditionName, ListOfEventConditionName_type);
        ITU_T_OPTIONAL_DECL(listOfEventConditionListName, ListOfEventConditionListName_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportEventConditionListStatus-Request

    struct ReportEventConditionListStatus_Request {

        ReportEventConditionListStatus_Request();

        ReportEventConditionListStatus_Request(const ObjectName& arg__eventConditionListName);

        ReportEventConditionListStatus_Request(shared_ptr< ObjectName> arg__eventConditionListName,
                shared_ptr< Identifier> arg__continueAfter);

        ITU_T_HOLDERH_DECL(eventConditionListName, ObjectName);
        ITU_T_OPTIONAL_DECL(continueAfter, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportEventConditionListStatus-Response

    struct ReportEventConditionListStatus_Response {

        typedef sequence_of< EventConditionStatus > ListOfEventConditionStatus_type;

        static const bool moreFollows__default;

        ReportEventConditionListStatus_Response();

        ReportEventConditionListStatus_Response(const ListOfEventConditionStatus_type& arg__listOfEventConditionStatus);

        ReportEventConditionListStatus_Response(shared_ptr< ListOfEventConditionStatus_type> arg__listOfEventConditionStatus,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfEventConditionStatus, ListOfEventConditionStatus_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence EventConditionStatus

    struct EventConditionStatus {

        EventConditionStatus();

        EventConditionStatus(const ObjectName& arg__eventConditionName,
                const MMS_Object_Module_1::EC_State& arg__currentState,
                const Unsigned32& arg__numberOfEventEnrollments);

        EventConditionStatus(shared_ptr< ObjectName> arg__eventConditionName,
                shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
                shared_ptr< Unsigned32> arg__numberOfEventEnrollments,
                shared_ptr< bool> arg__enabled,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
                shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle);

        ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
        ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
        ITU_T_HOLDERH_DECL(numberOfEventEnrollments, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(enabled, bool);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
        ITU_T_OPTIONAL_DECL(timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence AlterEventConditionListMonitoring-Request

    struct AlterEventConditionListMonitoring_Request {

        struct PriorityChange_type;

        enum PriorityChange_type_enum {

            PriorityChange_type_null = 0,
            PriorityChange_type_priorityValue,
            PriorityChange_type_priorityReset,
        };

        struct PriorityChange_type : public ITU_T_CHOICE(PriorityChange_type_enum) {


            ITU_T_CHOICE_CTORS(PriorityChange_type);

            ITU_T_CHOICES_DECL(priorityValue, integer_type, PriorityChange_type_priorityValue); // primitive
            ITU_T_CHOICES_DECL(priorityReset, null_type, PriorityChange_type_priorityReset); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        AlterEventConditionListMonitoring_Request();

        AlterEventConditionListMonitoring_Request(const ObjectName& arg__eventConditionListName,
                const bool& arg__enabled);

        AlterEventConditionListMonitoring_Request(shared_ptr< ObjectName> arg__eventConditionListName,
                shared_ptr< bool> arg__enabled,
                shared_ptr< PriorityChange_type> arg__priorityChange);

        ITU_T_HOLDERH_DECL(eventConditionListName, ObjectName);
        ITU_T_HOLDERH_DECL(enabled, bool);
        ITU_T_OPTIONAL_DECL(priorityChange, PriorityChange_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReadJournal-Request

    struct ReadJournal_Request {

        struct RangeStartSpecification_type;
        struct RangeStopSpecification_type;
        struct EntryToStartAfter_type;

        enum RangeStartSpecification_type_enum {

            RangeStartSpecification_type_null = 0,
            RangeStartSpecification_type_startingTime,
            RangeStartSpecification_type_startingEntry,
        };

        struct RangeStartSpecification_type : public ITU_T_CHOICE(RangeStartSpecification_type_enum) {


            ITU_T_CHOICE_CTORS(RangeStartSpecification_type);

            ITU_T_CHOICES_DECL(startingTime, TimeOfDay, RangeStartSpecification_type_startingTime); // primitive  //    Sc (  [ 4  ...   6 ]   
            ITU_T_CHOICES_DECL(startingEntry, octet_string, RangeStartSpecification_type_startingEntry); // primitive

            ITU_T_ARCHIVE_FUNC;
        };

        enum RangeStopSpecification_type_enum {

            RangeStopSpecification_type_null = 0,
            RangeStopSpecification_type_endingTime,
            RangeStopSpecification_type_numberOfEntries,
        };

        struct RangeStopSpecification_type : public ITU_T_CHOICE(RangeStopSpecification_type_enum) {


            ITU_T_CHOICE_CTORS(RangeStopSpecification_type);

            ITU_T_CHOICES_DECL(endingTime, TimeOfDay, RangeStopSpecification_type_endingTime); // primitive  //    Sc (  [ 4  ...   6 ]   
            ITU_T_CHOICES_DECL(numberOfEntries, Integer32, RangeStopSpecification_type_numberOfEntries); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   

            ITU_T_ARCHIVE_FUNC;
        };

        struct EntryToStartAfter_type {

            EntryToStartAfter_type();

            EntryToStartAfter_type(const TimeOfDay& arg__timeSpecification,
                    const octet_string& arg__entrySpecification);

            ITU_T_HOLDERH_DECL(timeSpecification, TimeOfDay); //    Sc (  [ 4  ...   6 ]   
            ITU_T_HOLDERH_DECL(entrySpecification, octet_string);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< visible_string > ListOfVariables_type; //  struct of ->  


        ReadJournal_Request();

        ReadJournal_Request(const ObjectName& arg__journalName);

        ReadJournal_Request(shared_ptr< ObjectName> arg__journalName,
                shared_ptr< RangeStartSpecification_type> arg__rangeStartSpecification,
                shared_ptr< RangeStopSpecification_type> arg__rangeStopSpecification,
                shared_ptr< ListOfVariables_type> arg__listOfVariables,
                shared_ptr< EntryToStartAfter_type> arg__entryToStartAfter);

        ITU_T_HOLDERH_DECL(journalName, ObjectName);
        ITU_T_OPTIONAL_DECL(rangeStartSpecification, RangeStartSpecification_type);
        ITU_T_OPTIONAL_DECL(rangeStopSpecification, RangeStopSpecification_type);
        ITU_T_OPTIONAL_DECL(listOfVariables, ListOfVariables_type); //  struct of ->  
        ITU_T_OPTIONAL_DECL(entryToStartAfter, EntryToStartAfter_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReadJournal-Response

    struct ReadJournal_Response {

        typedef sequence_of< JournalEntry > ListOfJournalEntry_type;

        static const bool moreFollows__default;

        ReadJournal_Response();

        ReadJournal_Response(const ListOfJournalEntry_type& arg__listOfJournalEntry);

        ReadJournal_Response(shared_ptr< ListOfJournalEntry_type> arg__listOfJournalEntry,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfJournalEntry, ListOfJournalEntry_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence JournalEntry

    struct JournalEntry {

        JournalEntry();

        JournalEntry(const octet_string& arg__entryIdentifier,
                const MMS_Environment_1::ApplicationReference& arg__originatingApplication,
                const EntryContent& arg__entryContent);

        ITU_T_HOLDERH_DECL(entryIdentifier, octet_string);
        ITU_T_HOLDERH_DECL(originatingApplication, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(entryContent, EntryContent);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence WriteJournal-Request

    struct WriteJournal_Request {

        typedef sequence_of< EntryContent > ListOfJournalEntry_type;


        WriteJournal_Request();

        WriteJournal_Request(const ObjectName& arg__journalName,
                const ListOfJournalEntry_type& arg__listOfJournalEntry);

        ITU_T_HOLDERH_DECL(journalName, ObjectName);
        ITU_T_HOLDERH_DECL(listOfJournalEntry, ListOfJournalEntry_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence InitializeJournal-Request

    struct InitializeJournal_Request {

        struct LimitSpecification_type;

        struct LimitSpecification_type {

            LimitSpecification_type();

            LimitSpecification_type(const TimeOfDay& arg__limitingTime);

            LimitSpecification_type(shared_ptr< TimeOfDay> arg__limitingTime,
                    shared_ptr< octet_string> arg__limitingEntry);

            ITU_T_HOLDERH_DECL(limitingTime, TimeOfDay); //    Sc (  [ 4  ...   6 ]   
            ITU_T_OPTIONAL_DECL(limitingEntry, octet_string);

            ITU_T_ARCHIVE_FUNC;
        };


        InitializeJournal_Request();

        InitializeJournal_Request(const ObjectName& arg__journalName);

        InitializeJournal_Request(shared_ptr< ObjectName> arg__journalName,
                shared_ptr< LimitSpecification_type> arg__limitSpecification);

        ITU_T_HOLDERH_DECL(journalName, ObjectName);
        ITU_T_OPTIONAL_DECL(limitSpecification, LimitSpecification_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ReportJournalStatus-Response

    struct ReportJournalStatus_Response {

        ReportJournalStatus_Response();

        ReportJournalStatus_Response(const Unsigned32& arg__currentEntries,
                const bool& arg__mmsDeletable);

        ReportJournalStatus_Response(shared_ptr< Unsigned32> arg__currentEntries,
                shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(currentEntries, Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_OPTIONAL_DECL(accessControlList, Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence CreateJournal-Request

    struct CreateJournal_Request {

        CreateJournal_Request();

        CreateJournal_Request(const ObjectName& arg__journalName);

        ITU_T_HOLDERH_DECL(journalName, ObjectName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DeleteJournal-Request

    struct DeleteJournal_Request {

        DeleteJournal_Request();

        DeleteJournal_Request(const ObjectName& arg__journalName);

        ITU_T_HOLDERH_DECL(journalName, ObjectName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence EntryContent

    struct EntryContent {

        struct EntryForm_type;

        enum EntryForm_type_enum {

            EntryForm_type_null = 0,
            EntryForm_type_data,
            EntryForm_type_annotation,
        };

        struct EntryForm_type : public ITU_T_CHOICE(EntryForm_type_enum) {


            struct Data_type;

            struct Data_type {

                struct Event_type;

                struct Event_type {

                    Event_type();

                    Event_type(const ObjectName& arg__eventConditionName,
                            const MMS_Object_Module_1::EC_State& arg__currentState);

                    ITU_T_HOLDERH_DECL(eventConditionName, ObjectName);
                    ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   

                    ITU_T_ARCHIVE_FUNC;
                };




                typedef sequence_of< MMS_Object_Module_1::Journal_Variable > ListOfVariables_type;

                Data_type();

                Data_type(shared_ptr< Event_type> arg__event,
                        shared_ptr< ListOfVariables_type> arg__listOfVariables);

                ITU_T_OPTIONAL_DECL(event, Event_type);
                ITU_T_OPTIONAL_DECL(listOfVariables, ListOfVariables_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(EntryForm_type);

            ITU_T_CHOICEC_DECL(data, Data_type, EntryForm_type_data);
            ITU_T_CHOICES_DECL(annotation, MMSString, EntryForm_type_annotation); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        EntryContent();

        EntryContent(const TimeOfDay& arg__occurrenceTime,
                const EntryForm_type& arg__entryForm);

        ITU_T_HOLDERH_DECL(occurrenceTime, TimeOfDay); //    Sc (  [ 4  ...   6 ]   
        ITU_T_HOLDERH_DECL(entryForm, EntryForm_type);

        ITU_T_ARCHIVE_FUNC;
    };

    ITU_T_ARCHIVE_X690_DECL(MMSpdu);
    ITU_T_ARCHIVE_X690_DECL(Confirmed_RequestPDU);
    ITU_T_ARCHIVE_X690_DECL(ConfirmedServiceRequest);
    ITU_T_ARCHIVE_X690_DECL(AdditionalService_Request);
    ITU_T_ARCHIVE_X690_DECL(Request_Detail);
    ITU_T_ARCHIVE_X690_DECL(Unconfirmed_PDU);
    ITU_T_ARCHIVE_X690_DECL(UnconfirmedService);
    ITU_T_ARCHIVE_X690_DECL(Unconfirmed_Detail);
    ITU_T_ARCHIVE_X690_DECL(Confirmed_ResponsePDU);
    ITU_T_ARCHIVE_X690_DECL(ConfirmedServiceResponse);
    ITU_T_ARCHIVE_X690_DECL(AdditionalService_Response);
    ITU_T_ARCHIVE_X690_DECL(Response_Detail);
    ITU_T_ARCHIVE_X690_DECL(Confirmed_ErrorPDU);
    ITU_T_ARCHIVE_X690_DECL(ServiceError);
    ITU_T_ARCHIVE_X690_DECL(ServiceError::ErrorClass_type);
    ITU_T_ARCHIVE_X690_DECL(ServiceError::ServiceSpecificInfo_type);
    ITU_T_ARCHIVE_X690_DECL(AdditionalService_Error);
    ITU_T_ARCHIVE_X690_DECL(ObjectName);
    ITU_T_ARCHIVE_X690_DECL(ObjectName::Domain_specific_type);
    ITU_T_ARCHIVE_X690_DECL(ObjectClass);
    ITU_T_ARCHIVE_X690_DECL(Initiate_RequestPDU);
    ITU_T_ARCHIVE_X690_DECL(Initiate_RequestPDU::InitRequestDetail_type);
    ITU_T_ARCHIVE_X690_DECL(Initiate_ResponsePDU);
    ITU_T_ARCHIVE_X690_DECL(Initiate_ResponsePDU::InitResponseDetail_type);
    ITU_T_ARCHIVE_X690_DECL(Cancel_ErrorPDU);
    ITU_T_ARCHIVE_X690_DECL(RejectPDU);
    ITU_T_ARCHIVE_X690_DECL(RejectPDU::RejectReason_type);
    ITU_T_ARCHIVE_X690_DECL(DefineAccessControlList_Request);
    ITU_T_ARCHIVE_X690_DECL(DefineAccessControlList_Request::AccessControlListElements_type);
    ITU_T_ARCHIVE_X690_DECL(GetAccessControlListAttributes_Request);
    ITU_T_ARCHIVE_X690_DECL(GetAccessControlListAttributes_Request::NamedObject_type);
    ITU_T_ARCHIVE_X690_DECL(GetAccessControlListAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(GetAccessControlListAttributes_Response::AccessControlListElements_type);
    ITU_T_ARCHIVE_X690_DECL(GetAccessControlListAttributes_Response::References_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(ReportAccessControlledObjects_Request);
    ITU_T_ARCHIVE_X690_DECL(ReportAccessControlledObjects_Response);
    ITU_T_ARCHIVE_X690_DECL(ChangeAccessControl_Request);
    ITU_T_ARCHIVE_X690_DECL(ChangeAccessControl_Request::ScopeOfChange_type);
    ITU_T_ARCHIVE_X690_DECL(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type);
    ITU_T_ARCHIVE_X690_DECL(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type);
    ITU_T_ARCHIVE_X690_DECL(ChangeAccessControl_Response);
    ITU_T_ARCHIVE_X690_DECL(StatusResponse);
    ITU_T_ARCHIVE_X690_DECL(CS_Status_Response);
    ITU_T_ARCHIVE_X690_DECL(CS_Status_Response::FullResponse_type);
    ITU_T_ARCHIVE_X690_DECL(CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type);
    ITU_T_ARCHIVE_X690_DECL(GetNameList_Request);
    ITU_T_ARCHIVE_X690_DECL(GetNameList_Request::ObjectScope_type);
    ITU_T_ARCHIVE_X690_DECL(GetNameList_Response);
    ITU_T_ARCHIVE_X690_DECL(Identify_Response);
    ITU_T_ARCHIVE_X690_DECL(Rename_Request);
    ITU_T_ARCHIVE_X690_DECL(GetCapabilityList_Request);
    ITU_T_ARCHIVE_X690_DECL(GetCapabilityList_Response);
    ITU_T_ARCHIVE_X690_DECL(InitiateDownloadSequence_Request);
    ITU_T_ARCHIVE_X690_DECL(DownloadSegment_Response);
    ITU_T_ARCHIVE_X690_DECL(LoadData);
    ITU_T_ARCHIVE_X690_DECL(TerminateDownloadSequence_Request);
    ITU_T_ARCHIVE_X690_DECL(InitiateUploadSequence_Response);
    ITU_T_ARCHIVE_X690_DECL(UploadSegment_Response);
    ITU_T_ARCHIVE_X690_DECL(RequestDomainDownload_Request);
    ITU_T_ARCHIVE_X690_DECL(RequestDomainUpload_Request);
    ITU_T_ARCHIVE_X690_DECL(LoadDomainContent_Request);
    ITU_T_ARCHIVE_X690_DECL(StoreDomainContent_Request);
    ITU_T_ARCHIVE_X690_DECL(GetDomainAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(CreateProgramInvocation_Request);
    ITU_T_ARCHIVE_X690_DECL(Start_Request);
    ITU_T_ARCHIVE_X690_DECL(Start_Request::ExecutionArgument_type);
    ITU_T_ARCHIVE_X690_DECL(CS_Start_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_Start_Request::Controlling_type);
    ITU_T_ARCHIVE_X690_DECL(StartCount);
    ITU_T_ARCHIVE_X690_DECL(Stop_Request);
    ITU_T_ARCHIVE_X690_DECL(Resume_Request);
    ITU_T_ARCHIVE_X690_DECL(Resume_Request::ExecutionArgument_type);
    ITU_T_ARCHIVE_X690_DECL(CS_Resume_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_Resume_Request::Controlling_type);
    ITU_T_ARCHIVE_X690_DECL(CS_Resume_Request::Controlling_type::ModeType_type);
    ITU_T_ARCHIVE_X690_DECL(Reset_Request);
    ITU_T_ARCHIVE_X690_DECL(Kill_Request);
    ITU_T_ARCHIVE_X690_DECL(GetProgramInvocationAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(GetProgramInvocationAttributes_Response::ExecutionArgument_type);
    ITU_T_ARCHIVE_X690_DECL(CS_GetProgramInvocationAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(CS_GetProgramInvocationAttributes_Response::Control_type);
    ITU_T_ARCHIVE_X690_DECL(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type);
    ITU_T_ARCHIVE_X690_DECL(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type);
    ITU_T_ARCHIVE_X690_DECL(CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type);
    ITU_T_ARCHIVE_X690_DECL(Select_Request);
    ITU_T_ARCHIVE_X690_DECL(AlterProgramInvocationAttributes_Request);
    ITU_T_ARCHIVE_X690_DECL(ReconfigureProgramInvocation_Request);
    ITU_T_ARCHIVE_X690_DECL(ControlElement);
    ITU_T_ARCHIVE_X690_DECL(ControlElement::BeginDomainDef_type);
    ITU_T_ARCHIVE_X690_DECL(ControlElement::ContinueDomainDef_type);
    ITU_T_ARCHIVE_X690_DECL(ControlElement::PiDefinition_type);
    ITU_T_ARCHIVE_X690_DECL(InitiateUnitControl_Error);
    ITU_T_ARCHIVE_X690_DECL(UnitControlLoadSegment_Response);
    ITU_T_ARCHIVE_X690_DECL(UnitControlUpload_Request);
    ITU_T_ARCHIVE_X690_DECL(UnitControlUpload_Request::ContinueAfter_type);
    ITU_T_ARCHIVE_X690_DECL(UnitControlUpload_Response);
    ITU_T_ARCHIVE_X690_DECL(UnitControlUpload_Response::NextElement_type);
    ITU_T_ARCHIVE_X690_DECL(StartUnitControl_Request);
    ITU_T_ARCHIVE_X690_DECL(StartUnitControl_Request::ExecutionArgument_type);
    ITU_T_ARCHIVE_X690_DECL(StartUnitControl_Error);
    ITU_T_ARCHIVE_X690_DECL(StopUnitControl_Error);
    ITU_T_ARCHIVE_X690_DECL(CreateUnitControl_Request);
    ITU_T_ARCHIVE_X690_DECL(AddToUnitControl_Request);
    ITU_T_ARCHIVE_X690_DECL(RemoveFromUnitControl_Request);
    ITU_T_ARCHIVE_X690_DECL(GetUnitControlAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(LoadUnitControlFromFile_Request);
    ITU_T_ARCHIVE_X690_DECL(LoadUnitControlFromFile_Error);
    ITU_T_ARCHIVE_X690_DECL(StoreUnitControlToFile_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteUnitControl_Error);
    ITU_T_ARCHIVE_X690_DECL(TypeSpecification);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccess_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccess_sequence_of::Named_type);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccessSelection);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccessSelection::SelectAlternateAccess_type);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccessSelection::SelectAccess_type);
    ITU_T_ARCHIVE_X690_DECL(AlternateAccessSelection::SelectAccess_type::IndexRange_type);
    ITU_T_ARCHIVE_X690_DECL(AccessResult);
    ITU_T_ARCHIVE_X690_DECL(Data);
    ITU_T_ARCHIVE_X690_DECL(VariableAccessSpecification);
    ITU_T_ARCHIVE_X690_DECL(VariableAccessSpecification::ListOfVariable_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(VariableSpecification);
    ITU_T_ARCHIVE_X690_DECL(VariableSpecification::VariableDescription_type);
    ITU_T_ARCHIVE_X690_DECL(Read_Request);
    ITU_T_ARCHIVE_X690_DECL(Read_Response);
    ITU_T_ARCHIVE_X690_DECL(Write_Request);
    ITU_T_ARCHIVE_X690_DECL(Write_Response_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(InformationReport);
    ITU_T_ARCHIVE_X690_DECL(GetVariableAccessAttributes_Request);
    ITU_T_ARCHIVE_X690_DECL(GetVariableAccessAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(DefineNamedVariable_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteVariableAccess_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteVariableAccess_Response);
    ITU_T_ARCHIVE_X690_DECL(DefineNamedVariableList_Request);
    ITU_T_ARCHIVE_X690_DECL(DefineNamedVariableList_Request::ListOfVariable_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(GetNamedVariableListAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(DeleteNamedVariableList_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteNamedVariableList_Response);
    ITU_T_ARCHIVE_X690_DECL(DefineNamedType_Request);
    ITU_T_ARCHIVE_X690_DECL(GetNamedTypeAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(DeleteNamedType_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteNamedType_Response);
    ITU_T_ARCHIVE_X690_DECL(ExchangeData_Request);
    ITU_T_ARCHIVE_X690_DECL(ExchangeData_Response);
    ITU_T_ARCHIVE_X690_DECL(GetDataExchangeAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(TakeControl_Request);
    ITU_T_ARCHIVE_X690_DECL(TakeControl_Response);
    ITU_T_ARCHIVE_X690_DECL(RelinquishControl_Request);
    ITU_T_ARCHIVE_X690_DECL(DefineSemaphore_Request);
    ITU_T_ARCHIVE_X690_DECL(ReportSemaphoreStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(ReportPoolSemaphoreStatus_Request);
    ITU_T_ARCHIVE_X690_DECL(ReportPoolSemaphoreStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(ReportSemaphoreEntryStatus_Request);
    ITU_T_ARCHIVE_X690_DECL(ReportSemaphoreEntryStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(SemaphoreEntry);
    ITU_T_ARCHIVE_X690_DECL(AttachToSemaphore);
    ITU_T_ARCHIVE_X690_DECL(Input_Request);
    ITU_T_ARCHIVE_X690_DECL(Output_Request);
    ITU_T_ARCHIVE_X690_DECL(TriggerEvent_Request);
    ITU_T_ARCHIVE_X690_DECL(EventNotification);
    ITU_T_ARCHIVE_X690_DECL(EventNotification::ActionResult_type);
    ITU_T_ARCHIVE_X690_DECL(EventNotification::ActionResult_type::SuccessOrFailure_type);
    ITU_T_ARCHIVE_X690_DECL(EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type);
    ITU_T_ARCHIVE_X690_DECL(EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type);
    ITU_T_ARCHIVE_X690_DECL(CS_EventNotification);
    ITU_T_ARCHIVE_X690_DECL(AcknowledgeEventNotification_Request);
    ITU_T_ARCHIVE_X690_DECL(GetAlarmSummary_Request);
    ITU_T_ARCHIVE_X690_DECL(GetAlarmSummary_Request::SeverityFilter_type);
    ITU_T_ARCHIVE_X690_DECL(GetAlarmSummary_Response);
    ITU_T_ARCHIVE_X690_DECL(AlarmSummary);
    ITU_T_ARCHIVE_X690_DECL(EN_Additional_Detail);
    ITU_T_ARCHIVE_X690_DECL(GetAlarmEnrollmentSummary_Request);
    ITU_T_ARCHIVE_X690_DECL(GetAlarmEnrollmentSummary_Request::SeverityFilter_type);
    ITU_T_ARCHIVE_X690_DECL(GetAlarmEnrollmentSummary_Response);
    ITU_T_ARCHIVE_X690_DECL(AlarmEnrollmentSummary);
    ITU_T_ARCHIVE_X690_DECL(AttachToEventCondition);
    ITU_T_ARCHIVE_X690_DECL(DefineEventCondition_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_DefineEventCondition_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteEventCondition_Request);
    ITU_T_ARCHIVE_X690_DECL(GetEventConditionAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(GetEventConditionAttributes_Response::MonitoredVariable_type);
    ITU_T_ARCHIVE_X690_DECL(CS_GetEventConditionAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type);
    ITU_T_ARCHIVE_X690_DECL(CS_GetEventConditionAttributes_Response::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X690_DECL(ReportEventConditionStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(AlterEventConditionMonitoring_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_AlterEventConditionMonitoring_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type);
    ITU_T_ARCHIVE_X690_DECL(DefineEventAction_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteEventAction_Request);
    ITU_T_ARCHIVE_X690_DECL(GetEventActionAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(DefineEventEnrollment_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_DefineEventEnrollment_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteEventEnrollment_Request);
    ITU_T_ARCHIVE_X690_DECL(GetEventEnrollmentAttributes_Request);
    ITU_T_ARCHIVE_X690_DECL(GetEventEnrollmentAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(EEAttributes);
    ITU_T_ARCHIVE_X690_DECL(EEAttributes::EventConditionName_type);
    ITU_T_ARCHIVE_X690_DECL(EEAttributes::EventActionName_type);
    ITU_T_ARCHIVE_X690_DECL(EEAttributes::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X690_DECL(ReportEventEnrollmentStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(AlterEventEnrollment_Request);
    ITU_T_ARCHIVE_X690_DECL(AlterEventEnrollment_Response);
    ITU_T_ARCHIVE_X690_DECL(AlterEventEnrollment_Response::CurrentState_type);
    ITU_T_ARCHIVE_X690_DECL(CS_AlterEventEnrollment_Request);
    ITU_T_ARCHIVE_X690_DECL(CS_AlterEventEnrollment_Request::ChangeDisplay_type);
    ITU_T_ARCHIVE_X690_DECL(DefineEventConditionList_Request);
    ITU_T_ARCHIVE_X690_DECL(AddEventConditionListReference_Request);
    ITU_T_ARCHIVE_X690_DECL(RemoveEventConditionListReference_Request);
    ITU_T_ARCHIVE_X690_DECL(RemoveEventConditionListReference_Error);
    ITU_T_ARCHIVE_X690_DECL(GetEventConditionListAttributes_Response);
    ITU_T_ARCHIVE_X690_DECL(ReportEventConditionListStatus_Request);
    ITU_T_ARCHIVE_X690_DECL(ReportEventConditionListStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(EventConditionStatus);
    ITU_T_ARCHIVE_X690_DECL(AlterEventConditionListMonitoring_Request);
    ITU_T_ARCHIVE_X690_DECL(AlterEventConditionListMonitoring_Request::PriorityChange_type);
    ITU_T_ARCHIVE_X690_DECL(ReadJournal_Request);
    ITU_T_ARCHIVE_X690_DECL(ReadJournal_Request::RangeStartSpecification_type);
    ITU_T_ARCHIVE_X690_DECL(ReadJournal_Request::RangeStopSpecification_type);
    ITU_T_ARCHIVE_X690_DECL(ReadJournal_Request::EntryToStartAfter_type);
    ITU_T_ARCHIVE_X690_DECL(ReadJournal_Response);
    ITU_T_ARCHIVE_X690_DECL(JournalEntry);
    ITU_T_ARCHIVE_X690_DECL(WriteJournal_Request);
    ITU_T_ARCHIVE_X690_DECL(InitializeJournal_Request);
    ITU_T_ARCHIVE_X690_DECL(InitializeJournal_Request::LimitSpecification_type);
    ITU_T_ARCHIVE_X690_DECL(ReportJournalStatus_Response);
    ITU_T_ARCHIVE_X690_DECL(CreateJournal_Request);
    ITU_T_ARCHIVE_X690_DECL(DeleteJournal_Request);
    ITU_T_ARCHIVE_X690_DECL(EntryContent);
    ITU_T_ARCHIVE_X690_DECL(EntryContent::EntryForm_type);
    ITU_T_ARCHIVE_X690_DECL(EntryContent::EntryForm_type::Data_type);
    ITU_T_ARCHIVE_X690_DECL(EntryContent::EntryForm_type::Data_type::Event_type);

    ITU_T_ARCHIVE_X691_DECL(MMSpdu);
    ITU_T_ARCHIVE_X691_DECL(Confirmed_RequestPDU);
    ITU_T_ARCHIVE_X691_DECL(ConfirmedServiceRequest);
    ITU_T_ARCHIVE_X691_DECL(AdditionalService_Request);
    ITU_T_ARCHIVE_X691_DECL(Request_Detail);
    ITU_T_ARCHIVE_X691_DECL(Unconfirmed_PDU);
    ITU_T_ARCHIVE_X691_DECL(UnconfirmedService);
    ITU_T_ARCHIVE_X691_DECL(Unconfirmed_Detail);
    ITU_T_ARCHIVE_X691_DECL(Confirmed_ResponsePDU);
    ITU_T_ARCHIVE_X691_DECL(ConfirmedServiceResponse);
    ITU_T_ARCHIVE_X691_DECL(AdditionalService_Response);
    ITU_T_ARCHIVE_X691_DECL(Response_Detail);
    ITU_T_ARCHIVE_X691_DECL(Confirmed_ErrorPDU);
    ITU_T_ARCHIVE_X691_DECL(ServiceError);
    ITU_T_ARCHIVE_X691_DECL(ServiceError::ErrorClass_type);
    ITU_T_ARCHIVE_X691_DECL(ServiceError::ServiceSpecificInfo_type);
    ITU_T_ARCHIVE_X691_DECL(AdditionalService_Error);
    ITU_T_ARCHIVE_X691_DECL(ObjectName);
    ITU_T_ARCHIVE_X691_DECL(ObjectName::Domain_specific_type);
    ITU_T_ARCHIVE_X691_DECL(ObjectClass);
    ITU_T_ARCHIVE_X691_DECL(Initiate_RequestPDU);
    ITU_T_ARCHIVE_X691_DECL(Initiate_RequestPDU::InitRequestDetail_type);
    ITU_T_ARCHIVE_X691_DECL(Initiate_ResponsePDU);
    ITU_T_ARCHIVE_X691_DECL(Initiate_ResponsePDU::InitResponseDetail_type);
    ITU_T_ARCHIVE_X691_DECL(Cancel_ErrorPDU);
    ITU_T_ARCHIVE_X691_DECL(RejectPDU);
    ITU_T_ARCHIVE_X691_DECL(RejectPDU::RejectReason_type);
    ITU_T_ARCHIVE_X691_DECL(DefineAccessControlList_Request);
    ITU_T_ARCHIVE_X691_DECL(DefineAccessControlList_Request::AccessControlListElements_type);
    ITU_T_ARCHIVE_X691_DECL(GetAccessControlListAttributes_Request);
    ITU_T_ARCHIVE_X691_DECL(GetAccessControlListAttributes_Request::NamedObject_type);
    ITU_T_ARCHIVE_X691_DECL(GetAccessControlListAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(GetAccessControlListAttributes_Response::AccessControlListElements_type);
    ITU_T_ARCHIVE_X691_DECL(GetAccessControlListAttributes_Response::References_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(ReportAccessControlledObjects_Request);
    ITU_T_ARCHIVE_X691_DECL(ReportAccessControlledObjects_Response);
    ITU_T_ARCHIVE_X691_DECL(ChangeAccessControl_Request);
    ITU_T_ARCHIVE_X691_DECL(ChangeAccessControl_Request::ScopeOfChange_type);
    ITU_T_ARCHIVE_X691_DECL(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type);
    ITU_T_ARCHIVE_X691_DECL(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type);
    ITU_T_ARCHIVE_X691_DECL(ChangeAccessControl_Response);
    ITU_T_ARCHIVE_X691_DECL(StatusResponse);
    ITU_T_ARCHIVE_X691_DECL(CS_Status_Response);
    ITU_T_ARCHIVE_X691_DECL(CS_Status_Response::FullResponse_type);
    ITU_T_ARCHIVE_X691_DECL(CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type);
    ITU_T_ARCHIVE_X691_DECL(GetNameList_Request);
    ITU_T_ARCHIVE_X691_DECL(GetNameList_Request::ObjectScope_type);
    ITU_T_ARCHIVE_X691_DECL(GetNameList_Response);
    ITU_T_ARCHIVE_X691_DECL(Identify_Response);
    ITU_T_ARCHIVE_X691_DECL(Rename_Request);
    ITU_T_ARCHIVE_X691_DECL(GetCapabilityList_Request);
    ITU_T_ARCHIVE_X691_DECL(GetCapabilityList_Response);
    ITU_T_ARCHIVE_X691_DECL(InitiateDownloadSequence_Request);
    ITU_T_ARCHIVE_X691_DECL(DownloadSegment_Response);
    ITU_T_ARCHIVE_X691_DECL(LoadData);
    ITU_T_ARCHIVE_X691_DECL(TerminateDownloadSequence_Request);
    ITU_T_ARCHIVE_X691_DECL(InitiateUploadSequence_Response);
    ITU_T_ARCHIVE_X691_DECL(UploadSegment_Response);
    ITU_T_ARCHIVE_X691_DECL(RequestDomainDownload_Request);
    ITU_T_ARCHIVE_X691_DECL(RequestDomainUpload_Request);
    ITU_T_ARCHIVE_X691_DECL(LoadDomainContent_Request);
    ITU_T_ARCHIVE_X691_DECL(StoreDomainContent_Request);
    ITU_T_ARCHIVE_X691_DECL(GetDomainAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(CreateProgramInvocation_Request);
    ITU_T_ARCHIVE_X691_DECL(Start_Request);
    ITU_T_ARCHIVE_X691_DECL(Start_Request::ExecutionArgument_type);
    ITU_T_ARCHIVE_X691_DECL(CS_Start_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_Start_Request::Controlling_type);
    ITU_T_ARCHIVE_X691_DECL(StartCount);
    ITU_T_ARCHIVE_X691_DECL(Stop_Request);
    ITU_T_ARCHIVE_X691_DECL(Resume_Request);
    ITU_T_ARCHIVE_X691_DECL(Resume_Request::ExecutionArgument_type);
    ITU_T_ARCHIVE_X691_DECL(CS_Resume_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_Resume_Request::Controlling_type);
    ITU_T_ARCHIVE_X691_DECL(CS_Resume_Request::Controlling_type::ModeType_type);
    ITU_T_ARCHIVE_X691_DECL(Reset_Request);
    ITU_T_ARCHIVE_X691_DECL(Kill_Request);
    ITU_T_ARCHIVE_X691_DECL(GetProgramInvocationAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(GetProgramInvocationAttributes_Response::ExecutionArgument_type);
    ITU_T_ARCHIVE_X691_DECL(CS_GetProgramInvocationAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(CS_GetProgramInvocationAttributes_Response::Control_type);
    ITU_T_ARCHIVE_X691_DECL(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type);
    ITU_T_ARCHIVE_X691_DECL(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type);
    ITU_T_ARCHIVE_X691_DECL(CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type);
    ITU_T_ARCHIVE_X691_DECL(Select_Request);
    ITU_T_ARCHIVE_X691_DECL(AlterProgramInvocationAttributes_Request);
    ITU_T_ARCHIVE_X691_DECL(ReconfigureProgramInvocation_Request);
    ITU_T_ARCHIVE_X691_DECL(ControlElement);
    ITU_T_ARCHIVE_X691_DECL(ControlElement::BeginDomainDef_type);
    ITU_T_ARCHIVE_X691_DECL(ControlElement::ContinueDomainDef_type);
    ITU_T_ARCHIVE_X691_DECL(ControlElement::PiDefinition_type);
    ITU_T_ARCHIVE_X691_DECL(InitiateUnitControl_Error);
    ITU_T_ARCHIVE_X691_DECL(UnitControlLoadSegment_Response);
    ITU_T_ARCHIVE_X691_DECL(UnitControlUpload_Request);
    ITU_T_ARCHIVE_X691_DECL(UnitControlUpload_Request::ContinueAfter_type);
    ITU_T_ARCHIVE_X691_DECL(UnitControlUpload_Response);
    ITU_T_ARCHIVE_X691_DECL(UnitControlUpload_Response::NextElement_type);
    ITU_T_ARCHIVE_X691_DECL(StartUnitControl_Request);
    ITU_T_ARCHIVE_X691_DECL(StartUnitControl_Request::ExecutionArgument_type);
    ITU_T_ARCHIVE_X691_DECL(StartUnitControl_Error);
    ITU_T_ARCHIVE_X691_DECL(StopUnitControl_Error);
    ITU_T_ARCHIVE_X691_DECL(CreateUnitControl_Request);
    ITU_T_ARCHIVE_X691_DECL(AddToUnitControl_Request);
    ITU_T_ARCHIVE_X691_DECL(RemoveFromUnitControl_Request);
    ITU_T_ARCHIVE_X691_DECL(GetUnitControlAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(LoadUnitControlFromFile_Request);
    ITU_T_ARCHIVE_X691_DECL(LoadUnitControlFromFile_Error);
    ITU_T_ARCHIVE_X691_DECL(StoreUnitControlToFile_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteUnitControl_Error);
    ITU_T_ARCHIVE_X691_DECL(TypeSpecification);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccess_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccess_sequence_of::Named_type);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccessSelection);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccessSelection::SelectAlternateAccess_type);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccessSelection::SelectAccess_type);
    ITU_T_ARCHIVE_X691_DECL(AlternateAccessSelection::SelectAccess_type::IndexRange_type);
    ITU_T_ARCHIVE_X691_DECL(AccessResult);
    ITU_T_ARCHIVE_X691_DECL(Data);
    ITU_T_ARCHIVE_X691_DECL(VariableAccessSpecification);
    ITU_T_ARCHIVE_X691_DECL(VariableAccessSpecification::ListOfVariable_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(VariableSpecification);
    ITU_T_ARCHIVE_X691_DECL(VariableSpecification::VariableDescription_type);
    ITU_T_ARCHIVE_X691_DECL(Read_Request);
    ITU_T_ARCHIVE_X691_DECL(Read_Response);
    ITU_T_ARCHIVE_X691_DECL(Write_Request);
    ITU_T_ARCHIVE_X691_DECL(Write_Response_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(InformationReport);
    ITU_T_ARCHIVE_X691_DECL(GetVariableAccessAttributes_Request);
    ITU_T_ARCHIVE_X691_DECL(GetVariableAccessAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(DefineNamedVariable_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteVariableAccess_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteVariableAccess_Response);
    ITU_T_ARCHIVE_X691_DECL(DefineNamedVariableList_Request);
    ITU_T_ARCHIVE_X691_DECL(DefineNamedVariableList_Request::ListOfVariable_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(GetNamedVariableListAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(DeleteNamedVariableList_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteNamedVariableList_Response);
    ITU_T_ARCHIVE_X691_DECL(DefineNamedType_Request);
    ITU_T_ARCHIVE_X691_DECL(GetNamedTypeAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(DeleteNamedType_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteNamedType_Response);
    ITU_T_ARCHIVE_X691_DECL(ExchangeData_Request);
    ITU_T_ARCHIVE_X691_DECL(ExchangeData_Response);
    ITU_T_ARCHIVE_X691_DECL(GetDataExchangeAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(TakeControl_Request);
    ITU_T_ARCHIVE_X691_DECL(TakeControl_Response);
    ITU_T_ARCHIVE_X691_DECL(RelinquishControl_Request);
    ITU_T_ARCHIVE_X691_DECL(DefineSemaphore_Request);
    ITU_T_ARCHIVE_X691_DECL(ReportSemaphoreStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(ReportPoolSemaphoreStatus_Request);
    ITU_T_ARCHIVE_X691_DECL(ReportPoolSemaphoreStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(ReportSemaphoreEntryStatus_Request);
    ITU_T_ARCHIVE_X691_DECL(ReportSemaphoreEntryStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(SemaphoreEntry);
    ITU_T_ARCHIVE_X691_DECL(AttachToSemaphore);
    ITU_T_ARCHIVE_X691_DECL(Input_Request);
    ITU_T_ARCHIVE_X691_DECL(Output_Request);
    ITU_T_ARCHIVE_X691_DECL(TriggerEvent_Request);
    ITU_T_ARCHIVE_X691_DECL(EventNotification);
    ITU_T_ARCHIVE_X691_DECL(EventNotification::ActionResult_type);
    ITU_T_ARCHIVE_X691_DECL(EventNotification::ActionResult_type::SuccessOrFailure_type);
    ITU_T_ARCHIVE_X691_DECL(EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type);
    ITU_T_ARCHIVE_X691_DECL(EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type);
    ITU_T_ARCHIVE_X691_DECL(CS_EventNotification);
    ITU_T_ARCHIVE_X691_DECL(AcknowledgeEventNotification_Request);
    ITU_T_ARCHIVE_X691_DECL(GetAlarmSummary_Request);
    ITU_T_ARCHIVE_X691_DECL(GetAlarmSummary_Request::SeverityFilter_type);
    ITU_T_ARCHIVE_X691_DECL(GetAlarmSummary_Response);
    ITU_T_ARCHIVE_X691_DECL(AlarmSummary);
    ITU_T_ARCHIVE_X691_DECL(EN_Additional_Detail);
    ITU_T_ARCHIVE_X691_DECL(GetAlarmEnrollmentSummary_Request);
    ITU_T_ARCHIVE_X691_DECL(GetAlarmEnrollmentSummary_Request::SeverityFilter_type);
    ITU_T_ARCHIVE_X691_DECL(GetAlarmEnrollmentSummary_Response);
    ITU_T_ARCHIVE_X691_DECL(AlarmEnrollmentSummary);
    ITU_T_ARCHIVE_X691_DECL(AttachToEventCondition);
    ITU_T_ARCHIVE_X691_DECL(DefineEventCondition_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_DefineEventCondition_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteEventCondition_Request);
    ITU_T_ARCHIVE_X691_DECL(GetEventConditionAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(GetEventConditionAttributes_Response::MonitoredVariable_type);
    ITU_T_ARCHIVE_X691_DECL(CS_GetEventConditionAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type);
    ITU_T_ARCHIVE_X691_DECL(CS_GetEventConditionAttributes_Response::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X691_DECL(ReportEventConditionStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(AlterEventConditionMonitoring_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_AlterEventConditionMonitoring_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type);
    ITU_T_ARCHIVE_X691_DECL(DefineEventAction_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteEventAction_Request);
    ITU_T_ARCHIVE_X691_DECL(GetEventActionAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(DefineEventEnrollment_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_DefineEventEnrollment_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteEventEnrollment_Request);
    ITU_T_ARCHIVE_X691_DECL(GetEventEnrollmentAttributes_Request);
    ITU_T_ARCHIVE_X691_DECL(GetEventEnrollmentAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(EEAttributes);
    ITU_T_ARCHIVE_X691_DECL(EEAttributes::EventConditionName_type);
    ITU_T_ARCHIVE_X691_DECL(EEAttributes::EventActionName_type);
    ITU_T_ARCHIVE_X691_DECL(EEAttributes::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X691_DECL(ReportEventEnrollmentStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(AlterEventEnrollment_Request);
    ITU_T_ARCHIVE_X691_DECL(AlterEventEnrollment_Response);
    ITU_T_ARCHIVE_X691_DECL(AlterEventEnrollment_Response::CurrentState_type);
    ITU_T_ARCHIVE_X691_DECL(CS_AlterEventEnrollment_Request);
    ITU_T_ARCHIVE_X691_DECL(CS_AlterEventEnrollment_Request::ChangeDisplay_type);
    ITU_T_ARCHIVE_X691_DECL(DefineEventConditionList_Request);
    ITU_T_ARCHIVE_X691_DECL(AddEventConditionListReference_Request);
    ITU_T_ARCHIVE_X691_DECL(RemoveEventConditionListReference_Request);
    ITU_T_ARCHIVE_X691_DECL(RemoveEventConditionListReference_Error);
    ITU_T_ARCHIVE_X691_DECL(GetEventConditionListAttributes_Response);
    ITU_T_ARCHIVE_X691_DECL(ReportEventConditionListStatus_Request);
    ITU_T_ARCHIVE_X691_DECL(ReportEventConditionListStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(EventConditionStatus);
    ITU_T_ARCHIVE_X691_DECL(AlterEventConditionListMonitoring_Request);
    ITU_T_ARCHIVE_X691_DECL(AlterEventConditionListMonitoring_Request::PriorityChange_type);
    ITU_T_ARCHIVE_X691_DECL(ReadJournal_Request);
    ITU_T_ARCHIVE_X691_DECL(ReadJournal_Request::RangeStartSpecification_type);
    ITU_T_ARCHIVE_X691_DECL(ReadJournal_Request::RangeStopSpecification_type);
    ITU_T_ARCHIVE_X691_DECL(ReadJournal_Request::EntryToStartAfter_type);
    ITU_T_ARCHIVE_X691_DECL(ReadJournal_Response);
    ITU_T_ARCHIVE_X691_DECL(JournalEntry);
    ITU_T_ARCHIVE_X691_DECL(WriteJournal_Request);
    ITU_T_ARCHIVE_X691_DECL(InitializeJournal_Request);
    ITU_T_ARCHIVE_X691_DECL(InitializeJournal_Request::LimitSpecification_type);
    ITU_T_ARCHIVE_X691_DECL(ReportJournalStatus_Response);
    ITU_T_ARCHIVE_X691_DECL(CreateJournal_Request);
    ITU_T_ARCHIVE_X691_DECL(DeleteJournal_Request);
    ITU_T_ARCHIVE_X691_DECL(EntryContent);
    ITU_T_ARCHIVE_X691_DECL(EntryContent::EntryForm_type);
    ITU_T_ARCHIVE_X691_DECL(EntryContent::EntryForm_type::Data_type);
    ITU_T_ARCHIVE_X691_DECL(EntryContent::EntryForm_type::Data_type::Event_type);

}

ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::MMSpdu)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ConfirmedServiceRequest)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Request_Detail)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::UnconfirmedService)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Unconfirmed_Detail)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ConfirmedServiceResponse)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Response)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Response_Detail)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ServiceError::ErrorClass_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ServiceError::ServiceSpecificInfo_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AdditionalService_Error)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ObjectName)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ObjectClass)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::RejectPDU::RejectReason_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetAccessControlListAttributes_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ChangeAccessControl_Request::ScopeOfChange_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Status_Response)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetNameList_Request::ObjectScope_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::LoadData)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Start_Request::ExecutionArgument_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Start_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::StartCount)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Resume_Request::ExecutionArgument_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Resume_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_Resume_Request::Controlling_type::ModeType_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetProgramInvocationAttributes_Response::ExecutionArgument_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::Control_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ControlElement)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::InitiateUnitControl_Error)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::UnitControlUpload_Request::ContinueAfter_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::UnitControlUpload_Response::NextElement_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::StartUnitControl_Request::ExecutionArgument_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::LoadUnitControlFromFile_Error)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteUnitControl_Error)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::TypeSpecification)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccess_sequence_of)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlternateAccessSelection::SelectAccess_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AccessResult)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Data)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::VariableAccessSpecification)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::VariableSpecification)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::Write_Response_sequence_of)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetVariableAccessAttributes_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::TakeControl_Response)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::EventNotification::ActionResult_type::SuccessOrFailure_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_EventNotification)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::EN_Additional_Detail)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_DefineEventCondition_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteEventCondition_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::GetEventConditionAttributes_Response::MonitoredVariable_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_GetEventConditionAttributes_Response::DisplayEnhancement_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteEventAction_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_DefineEventEnrollment_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::DeleteEventEnrollment_Request)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::EventConditionName_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::EventActionName_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::EEAttributes::DisplayEnhancement_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlterEventEnrollment_Response::CurrentState_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::CS_AlterEventEnrollment_Request::ChangeDisplay_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::RemoveEventConditionListReference_Error)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::AlterEventConditionListMonitoring_Request::PriorityChange_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ReadJournal_Request::RangeStartSpecification_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::ReadJournal_Request::RangeStopSpecification_type)
ITU_T_CHOICE_REGESTRATE(ISO_9506_MMS_1::EntryContent::EntryForm_type)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___ISO_9506_MMS_1 */
