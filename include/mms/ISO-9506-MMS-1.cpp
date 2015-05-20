#include "ISO-9506-MMS-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1 {

    // choice MMSpdu

    ITU_T_CHOICEC_DEFN(MMSpdu::confirmed_RequestPDU, confirmed_RequestPDU, Confirmed_RequestPDU, MMSpdu_confirmed_RequestPDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::confirmed_ResponsePDU, confirmed_ResponsePDU, Confirmed_ResponsePDU, MMSpdu_confirmed_ResponsePDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::confirmed_ErrorPDU, confirmed_ErrorPDU, Confirmed_ErrorPDU, MMSpdu_confirmed_ErrorPDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::unconfirmed_PDU, unconfirmed_PDU, Unconfirmed_PDU, MMSpdu_unconfirmed_PDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::rejectPDU, rejectPDU, RejectPDU, MMSpdu_rejectPDU);
    ITU_T_CHOICES_DEFN(MMSpdu::cancel_RequestPDU, cancel_RequestPDU, Cancel_RequestPDU, MMSpdu_cancel_RequestPDU);
    ITU_T_CHOICES_DEFN(MMSpdu::cancel_ResponsePDU, cancel_ResponsePDU, Cancel_ResponsePDU, MMSpdu_cancel_ResponsePDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::cancel_ErrorPDU, cancel_ErrorPDU, Cancel_ErrorPDU, MMSpdu_cancel_ErrorPDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::initiate_RequestPDU, initiate_RequestPDU, Initiate_RequestPDU, MMSpdu_initiate_RequestPDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::initiate_ResponsePDU, initiate_ResponsePDU, Initiate_ResponsePDU, MMSpdu_initiate_ResponsePDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::initiate_ErrorPDU, initiate_ErrorPDU, Initiate_ErrorPDU, MMSpdu_initiate_ErrorPDU);
    ITU_T_CHOICES_DEFN(MMSpdu::conclude_RequestPDU, conclude_RequestPDU, Conclude_RequestPDU, MMSpdu_conclude_RequestPDU);
    ITU_T_CHOICES_DEFN(MMSpdu::conclude_ResponsePDU, conclude_ResponsePDU, Conclude_ResponsePDU, MMSpdu_conclude_ResponsePDU);
    ITU_T_CHOICEC_DEFN(MMSpdu::conclude_ErrorPDU, conclude_ErrorPDU, Conclude_ErrorPDU, MMSpdu_conclude_ErrorPDU);

    // sequence Confirmed-RequestPDU

    Confirmed_RequestPDU::Confirmed_RequestPDU() : invokeID_(), service_() {
    };

    Confirmed_RequestPDU::Confirmed_RequestPDU(const Unsigned32& arg__invokeID,
            const ConfirmedServiceRequest& arg__service) :
    invokeID_(arg__invokeID),
    service_(arg__service) {
    };

    Confirmed_RequestPDU::Confirmed_RequestPDU(shared_ptr< Unsigned32> arg__invokeID,
            shared_ptr< ListOfModifiers_type> arg__listOfModifiers,
            shared_ptr< ConfirmedServiceRequest> arg__service,
            shared_ptr< Request_Detail> arg__service_ext) :
    invokeID_(arg__invokeID),
    listOfModifiers_(arg__listOfModifiers),
    service_(arg__service),
    service_ext_(arg__service_ext) {
    };


    ITU_T_HOLDERH_DEFN(Confirmed_RequestPDU::invokeID, invokeID, Unsigned32);
    ITU_T_OPTIONAL_DEFN(Confirmed_RequestPDU::listOfModifiers, listOfModifiers, Confirmed_RequestPDU::ListOfModifiers_type);
    ITU_T_HOLDERH_DEFN(Confirmed_RequestPDU::service, service, ConfirmedServiceRequest);
    ITU_T_OPTIONAL_DEFN(Confirmed_RequestPDU::service_ext, service_ext, Request_Detail);

    // choice ConfirmedServiceRequest

    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::status, status, Status_Request, ConfirmedServiceRequest_status);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getNameList, getNameList, GetNameList_Request, ConfirmedServiceRequest_getNameList);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::identify, identify, Identify_Request, ConfirmedServiceRequest_identify);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::rename, rename, Rename_Request, ConfirmedServiceRequest_rename);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::read, read, Read_Request, ConfirmedServiceRequest_read);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::write, write, Write_Request, ConfirmedServiceRequest_write);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getVariableAccessAttributes, getVariableAccessAttributes, GetVariableAccessAttributes_Request, ConfirmedServiceRequest_getVariableAccessAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineNamedVariable, defineNamedVariable, DefineNamedVariable_Request, ConfirmedServiceRequest_defineNamedVariable);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineScatteredAccess, defineScatteredAccess, ISO_9506_MMS_1A::DefineScatteredAccess_Request, ConfirmedServiceRequest_defineScatteredAccess);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getScatteredAccessAttributes, getScatteredAccessAttributes, ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request, ConfirmedServiceRequest_getScatteredAccessAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteVariableAccess, deleteVariableAccess, DeleteVariableAccess_Request, ConfirmedServiceRequest_deleteVariableAccess);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineNamedVariableList, defineNamedVariableList, DefineNamedVariableList_Request, ConfirmedServiceRequest_defineNamedVariableList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getNamedVariableListAttributes, getNamedVariableListAttributes, GetNamedVariableListAttributes_Request, ConfirmedServiceRequest_getNamedVariableListAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteNamedVariableList, deleteNamedVariableList, DeleteNamedVariableList_Request, ConfirmedServiceRequest_deleteNamedVariableList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineNamedType, defineNamedType, DefineNamedType_Request, ConfirmedServiceRequest_defineNamedType);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getNamedTypeAttributes, getNamedTypeAttributes, GetNamedTypeAttributes_Request, ConfirmedServiceRequest_getNamedTypeAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteNamedType, deleteNamedType, DeleteNamedType_Request, ConfirmedServiceRequest_deleteNamedType);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::input, input, Input_Request, ConfirmedServiceRequest_input);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::output, output, Output_Request, ConfirmedServiceRequest_output);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::takeControl, takeControl, TakeControl_Request, ConfirmedServiceRequest_takeControl);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::relinquishControl, relinquishControl, RelinquishControl_Request, ConfirmedServiceRequest_relinquishControl);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineSemaphore, defineSemaphore, DefineSemaphore_Request, ConfirmedServiceRequest_defineSemaphore);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteSemaphore, deleteSemaphore, DeleteSemaphore_Request, ConfirmedServiceRequest_deleteSemaphore);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportSemaphoreStatus, reportSemaphoreStatus, ReportSemaphoreStatus_Request, ConfirmedServiceRequest_reportSemaphoreStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportPoolSemaphoreStatus, reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Request, ConfirmedServiceRequest_reportPoolSemaphoreStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportSemaphoreEntryStatus, reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Request, ConfirmedServiceRequest_reportSemaphoreEntryStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::initiateDownloadSequence, initiateDownloadSequence, InitiateDownloadSequence_Request, ConfirmedServiceRequest_initiateDownloadSequence);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::downloadSegment, downloadSegment, DownloadSegment_Request, ConfirmedServiceRequest_downloadSegment);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::terminateDownloadSequence, terminateDownloadSequence, TerminateDownloadSequence_Request, ConfirmedServiceRequest_terminateDownloadSequence);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::initiateUploadSequence, initiateUploadSequence, InitiateUploadSequence_Request, ConfirmedServiceRequest_initiateUploadSequence);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::uploadSegment, uploadSegment, UploadSegment_Request, ConfirmedServiceRequest_uploadSegment);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::terminateUploadSequence, terminateUploadSequence, TerminateUploadSequence_Request, ConfirmedServiceRequest_terminateUploadSequence);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::requestDomainDownload, requestDomainDownload, RequestDomainDownload_Request, ConfirmedServiceRequest_requestDomainDownload);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::requestDomainUpload, requestDomainUpload, RequestDomainUpload_Request, ConfirmedServiceRequest_requestDomainUpload);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::loadDomainContent, loadDomainContent, LoadDomainContent_Request, ConfirmedServiceRequest_loadDomainContent);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::storeDomainContent, storeDomainContent, StoreDomainContent_Request, ConfirmedServiceRequest_storeDomainContent);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::deleteDomain, deleteDomain, DeleteDomain_Request, ConfirmedServiceRequest_deleteDomain);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::getDomainAttributes, getDomainAttributes, GetDomainAttributes_Request, ConfirmedServiceRequest_getDomainAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::createProgramInvocation, createProgramInvocation, CreateProgramInvocation_Request, ConfirmedServiceRequest_createProgramInvocation);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::deleteProgramInvocation, deleteProgramInvocation, DeleteProgramInvocation_Request, ConfirmedServiceRequest_deleteProgramInvocation);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::start, start, Start_Request, ConfirmedServiceRequest_start);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::stop, stop, Stop_Request, ConfirmedServiceRequest_stop);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::resume, resume, Resume_Request, ConfirmedServiceRequest_resume);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reset, reset, Reset_Request, ConfirmedServiceRequest_reset);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::kill, kill, Kill_Request, ConfirmedServiceRequest_kill);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::getProgramInvocationAttributes, getProgramInvocationAttributes, GetProgramInvocationAttributes_Request, ConfirmedServiceRequest_getProgramInvocationAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::obtainFile, obtainFile, ISO_9506_MMS_1A::ObtainFile_Request, ConfirmedServiceRequest_obtainFile);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineEventCondition, defineEventCondition, DefineEventCondition_Request, ConfirmedServiceRequest_defineEventCondition);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteEventCondition, deleteEventCondition, DeleteEventCondition_Request, ConfirmedServiceRequest_deleteEventCondition);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getEventConditionAttributes, getEventConditionAttributes, GetEventConditionAttributes_Request, ConfirmedServiceRequest_getEventConditionAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportEventConditionStatus, reportEventConditionStatus, ReportEventConditionStatus_Request, ConfirmedServiceRequest_reportEventConditionStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::alterEventConditionMonitoring, alterEventConditionMonitoring, AlterEventConditionMonitoring_Request, ConfirmedServiceRequest_alterEventConditionMonitoring);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::triggerEvent, triggerEvent, TriggerEvent_Request, ConfirmedServiceRequest_triggerEvent);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineEventAction, defineEventAction, DefineEventAction_Request, ConfirmedServiceRequest_defineEventAction);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteEventAction, deleteEventAction, DeleteEventAction_Request, ConfirmedServiceRequest_deleteEventAction);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getEventActionAttributes, getEventActionAttributes, GetEventActionAttributes_Request, ConfirmedServiceRequest_getEventActionAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportEventActionStatus, reportEventActionStatus, ReportEventActionStatus_Request, ConfirmedServiceRequest_reportEventActionStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineEventEnrollment, defineEventEnrollment, DefineEventEnrollment_Request, ConfirmedServiceRequest_defineEventEnrollment);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteEventEnrollment, deleteEventEnrollment, DeleteEventEnrollment_Request, ConfirmedServiceRequest_deleteEventEnrollment);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::alterEventEnrollment, alterEventEnrollment, AlterEventEnrollment_Request, ConfirmedServiceRequest_alterEventEnrollment);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportEventEnrollmentStatus, reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Request, ConfirmedServiceRequest_reportEventEnrollmentStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getEventEnrollmentAttributes, getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Request, ConfirmedServiceRequest_getEventEnrollmentAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::acknowledgeEventNotification, acknowledgeEventNotification, AcknowledgeEventNotification_Request, ConfirmedServiceRequest_acknowledgeEventNotification);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getAlarmSummary, getAlarmSummary, GetAlarmSummary_Request, ConfirmedServiceRequest_getAlarmSummary);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getAlarmEnrollmentSummary, getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Request, ConfirmedServiceRequest_getAlarmEnrollmentSummary);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::readJournal, readJournal, ReadJournal_Request, ConfirmedServiceRequest_readJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::writeJournal, writeJournal, WriteJournal_Request, ConfirmedServiceRequest_writeJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::initializeJournal, initializeJournal, InitializeJournal_Request, ConfirmedServiceRequest_initializeJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportJournalStatus, reportJournalStatus, ReportJournalStatus_Request, ConfirmedServiceRequest_reportJournalStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::createJournal, createJournal, CreateJournal_Request, ConfirmedServiceRequest_createJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::deleteJournal, deleteJournal, DeleteJournal_Request, ConfirmedServiceRequest_deleteJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getCapabilityList, getCapabilityList, GetCapabilityList_Request, ConfirmedServiceRequest_getCapabilityList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::fileOpen, fileOpen, ISO_9506_MMS_1A::FileOpen_Request, ConfirmedServiceRequest_fileOpen);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::fileRead, fileRead, ISO_9506_MMS_1A::FileRead_Request, ConfirmedServiceRequest_fileRead);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::fileClose, fileClose, ISO_9506_MMS_1A::FileClose_Request, ConfirmedServiceRequest_fileClose);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::fileRename, fileRename, ISO_9506_MMS_1A::FileRename_Request, ConfirmedServiceRequest_fileRename);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::fileDelete, fileDelete, ISO_9506_MMS_1A::FileDelete_Request, ConfirmedServiceRequest_fileDelete);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::fileDirectory, fileDirectory, ISO_9506_MMS_1A::FileDirectory_Request, ConfirmedServiceRequest_fileDirectory);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::additionalService, additionalService, AdditionalService_Request, ConfirmedServiceRequest_additionalService);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getDataExchangeAttributes, getDataExchangeAttributes, GetDataExchangeAttributes_Request, ConfirmedServiceRequest_getDataExchangeAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::exchangeData, exchangeData, ExchangeData_Request, ConfirmedServiceRequest_exchangeData);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::defineAccessControlList, defineAccessControlList, DefineAccessControlList_Request, ConfirmedServiceRequest_defineAccessControlList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::getAccessControlListAttributes, getAccessControlListAttributes, GetAccessControlListAttributes_Request, ConfirmedServiceRequest_getAccessControlListAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::reportAccessControlledObjects, reportAccessControlledObjects, ReportAccessControlledObjects_Request, ConfirmedServiceRequest_reportAccessControlledObjects);
    ITU_T_CHOICES_DEFN(ConfirmedServiceRequest::deleteAccessControlList, deleteAccessControlList, DeleteAccessControlList_Request, ConfirmedServiceRequest_deleteAccessControlList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceRequest::changeAccessControl, changeAccessControl, ChangeAccessControl_Request, ConfirmedServiceRequest_changeAccessControl);

    // choice AdditionalService-Request

    ITU_T_CHOICES_DEFN(AdditionalService_Request::vMDStop, vMDStop, VMDStop_Request, AdditionalService_Request_vMDStop);
    ITU_T_CHOICES_DEFN(AdditionalService_Request::vMDReset, vMDReset, VMDReset_Request, AdditionalService_Request_vMDReset);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::select, select, Select_Request, AdditionalService_Request_select);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::alterPI, alterPI, AlterProgramInvocationAttributes_Request, AdditionalService_Request_alterPI);
    ITU_T_CHOICES_DEFN(AdditionalService_Request::initiateUCLoad, initiateUCLoad, InitiateUnitControlLoad_Request, AdditionalService_Request_initiateUCLoad);
    ITU_T_CHOICES_DEFN(AdditionalService_Request::uCLoad, uCLoad, UnitControlLoadSegment_Request, AdditionalService_Request_uCLoad);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::uCUpload, uCUpload, UnitControlUpload_Request, AdditionalService_Request_uCUpload);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::startUC, startUC, StartUnitControl_Request, AdditionalService_Request_startUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Request::stopUC, stopUC, StopUnitControl_Request, AdditionalService_Request_stopUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::createUC, createUC, CreateUnitControl_Request, AdditionalService_Request_createUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::addToUC, addToUC, AddToUnitControl_Request, AdditionalService_Request_addToUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::removeFromUC, removeFromUC, RemoveFromUnitControl_Request, AdditionalService_Request_removeFromUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Request::getUCAttributes, getUCAttributes, GetUnitControlAttributes_Request, AdditionalService_Request_getUCAttributes);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::loadUCFromFile, loadUCFromFile, LoadUnitControlFromFile_Request, AdditionalService_Request_loadUCFromFile);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::storeUCToFile, storeUCToFile, StoreUnitControlToFile_Request, AdditionalService_Request_storeUCToFile);
    ITU_T_CHOICES_DEFN(AdditionalService_Request::deleteUC, deleteUC, DeleteUnitControl_Request, AdditionalService_Request_deleteUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::defineECL, defineECL, DefineEventConditionList_Request, AdditionalService_Request_defineECL);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::deleteECL, deleteECL, DeleteEventConditionList_Request, AdditionalService_Request_deleteECL);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::addECLReference, addECLReference, AddEventConditionListReference_Request, AdditionalService_Request_addECLReference);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::removeECLReference, removeECLReference, RemoveEventConditionListReference_Request, AdditionalService_Request_removeECLReference);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::getECLAttributes, getECLAttributes, GetEventConditionListAttributes_Request, AdditionalService_Request_getECLAttributes);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::reportECLStatus, reportECLStatus, ReportEventConditionListStatus_Request, AdditionalService_Request_reportECLStatus);
    ITU_T_CHOICEC_DEFN(AdditionalService_Request::alterECLMonitoring, alterECLMonitoring, AlterEventConditionListMonitoring_Request, AdditionalService_Request_alterECLMonitoring);

    // choice Request-Detail

    ITU_T_CHOICES_DEFN(Request_Detail::otherRequests, otherRequests, null_type, Request_Detail_otherRequests);
    ITU_T_CHOICES_DEFN(Request_Detail::createProgramInvocation, createProgramInvocation, CS_CreateProgramInvocation_Request, Request_Detail_createProgramInvocation);
    ITU_T_CHOICEC_DEFN(Request_Detail::start, start, CS_Start_Request, Request_Detail_start);
    ITU_T_CHOICEC_DEFN(Request_Detail::resume, resume, CS_Resume_Request, Request_Detail_resume);
    ITU_T_CHOICEC_DEFN(Request_Detail::defineEventCondition, defineEventCondition, CS_DefineEventCondition_Request, Request_Detail_defineEventCondition);
    ITU_T_CHOICEC_DEFN(Request_Detail::alterEventConditionMonitoring, alterEventConditionMonitoring, CS_AlterEventConditionMonitoring_Request, Request_Detail_alterEventConditionMonitoring);
    ITU_T_CHOICEC_DEFN(Request_Detail::defineEventEnrollment, defineEventEnrollment, CS_DefineEventEnrollment_Request, Request_Detail_defineEventEnrollment);
    ITU_T_CHOICEC_DEFN(Request_Detail::alterEventEnrollment, alterEventEnrollment, CS_AlterEventEnrollment_Request, Request_Detail_alterEventEnrollment);

    // sequence Unconfirmed-PDU

    Unconfirmed_PDU::Unconfirmed_PDU() : service_() {
    };

    Unconfirmed_PDU::Unconfirmed_PDU(const UnconfirmedService& arg__service) :
    service_(arg__service) {
    };

    Unconfirmed_PDU::Unconfirmed_PDU(shared_ptr< UnconfirmedService> arg__service,
            shared_ptr< Unconfirmed_Detail> arg__service_ext) :
    service_(arg__service),
    service_ext_(arg__service_ext) {
    };


    ITU_T_HOLDERH_DEFN(Unconfirmed_PDU::service, service, UnconfirmedService);
    ITU_T_OPTIONAL_DEFN(Unconfirmed_PDU::service_ext, service_ext, Unconfirmed_Detail);

    // choice UnconfirmedService

    ITU_T_CHOICEC_DEFN(UnconfirmedService::informationReport, informationReport, InformationReport, UnconfirmedService_informationReport);
    ITU_T_CHOICEC_DEFN(UnconfirmedService::unsolicitedStatus, unsolicitedStatus, UnsolicitedStatus, UnconfirmedService_unsolicitedStatus);
    ITU_T_CHOICEC_DEFN(UnconfirmedService::eventNotification, eventNotification, EventNotification, UnconfirmedService_eventNotification);

    // choice Unconfirmed-Detail

    ITU_T_CHOICES_DEFN(Unconfirmed_Detail::otherRequests, otherRequests, null_type, Unconfirmed_Detail_otherRequests);
    ITU_T_CHOICEC_DEFN(Unconfirmed_Detail::eventNotification, eventNotification, CS_EventNotification, Unconfirmed_Detail_eventNotification);

    // sequence Confirmed-ResponsePDU

    Confirmed_ResponsePDU::Confirmed_ResponsePDU() : invokeID_(), service_() {
    };

    Confirmed_ResponsePDU::Confirmed_ResponsePDU(const Unsigned32& arg__invokeID,
            const ConfirmedServiceResponse& arg__service) :
    invokeID_(arg__invokeID),
    service_(arg__service) {
    };

    Confirmed_ResponsePDU::Confirmed_ResponsePDU(shared_ptr< Unsigned32> arg__invokeID,
            shared_ptr< ConfirmedServiceResponse> arg__service,
            shared_ptr< Response_Detail> arg__service_ext) :
    invokeID_(arg__invokeID),
    service_(arg__service),
    service_ext_(arg__service_ext) {
    };


    ITU_T_HOLDERH_DEFN(Confirmed_ResponsePDU::invokeID, invokeID, Unsigned32);
    ITU_T_HOLDERH_DEFN(Confirmed_ResponsePDU::service, service, ConfirmedServiceResponse);
    ITU_T_OPTIONAL_DEFN(Confirmed_ResponsePDU::service_ext, service_ext, Response_Detail);

    // choice ConfirmedServiceResponse

    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::status, status, Status_Response, ConfirmedServiceResponse_status);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getNameList, getNameList, GetNameList_Response, ConfirmedServiceResponse_getNameList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::identify, identify, Identify_Response, ConfirmedServiceResponse_identify);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::rename, rename, Rename_Response, ConfirmedServiceResponse_rename);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::read, read, Read_Response, ConfirmedServiceResponse_read);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getVariableAccessAttributes, getVariableAccessAttributes, GetVariableAccessAttributes_Response, ConfirmedServiceResponse_getVariableAccessAttributes);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineNamedVariable, defineNamedVariable, DefineNamedVariable_Response, ConfirmedServiceResponse_defineNamedVariable);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineScatteredAccess, defineScatteredAccess, ISO_9506_MMS_1A::DefineScatteredAccess_Response, ConfirmedServiceResponse_defineScatteredAccess);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getScatteredAccessAttributes, getScatteredAccessAttributes, ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response, ConfirmedServiceResponse_getScatteredAccessAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::deleteVariableAccess, deleteVariableAccess, DeleteVariableAccess_Response, ConfirmedServiceResponse_deleteVariableAccess);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineNamedVariableList, defineNamedVariableList, DefineNamedVariableList_Response, ConfirmedServiceResponse_defineNamedVariableList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getNamedVariableListAttributes, getNamedVariableListAttributes, GetNamedVariableListAttributes_Response, ConfirmedServiceResponse_getNamedVariableListAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::deleteNamedVariableList, deleteNamedVariableList, DeleteNamedVariableList_Response, ConfirmedServiceResponse_deleteNamedVariableList);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineNamedType, defineNamedType, DefineNamedType_Response, ConfirmedServiceResponse_defineNamedType);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getNamedTypeAttributes, getNamedTypeAttributes, GetNamedTypeAttributes_Response, ConfirmedServiceResponse_getNamedTypeAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::deleteNamedType, deleteNamedType, DeleteNamedType_Response, ConfirmedServiceResponse_deleteNamedType);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::input, input, Input_Response, ConfirmedServiceResponse_input);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::output, output, Output_Response, ConfirmedServiceResponse_output);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::takeControl, takeControl, TakeControl_Response, ConfirmedServiceResponse_takeControl);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::relinquishControl, relinquishControl, RelinquishControl_Response, ConfirmedServiceResponse_relinquishControl);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineSemaphore, defineSemaphore, DefineSemaphore_Response, ConfirmedServiceResponse_defineSemaphore);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteSemaphore, deleteSemaphore, DeleteSemaphore_Response, ConfirmedServiceResponse_deleteSemaphore);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportSemaphoreStatus, reportSemaphoreStatus, ReportSemaphoreStatus_Response, ConfirmedServiceResponse_reportSemaphoreStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportPoolSemaphoreStatus, reportPoolSemaphoreStatus, ReportPoolSemaphoreStatus_Response, ConfirmedServiceResponse_reportPoolSemaphoreStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportSemaphoreEntryStatus, reportSemaphoreEntryStatus, ReportSemaphoreEntryStatus_Response, ConfirmedServiceResponse_reportSemaphoreEntryStatus);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::initiateDownloadSequence, initiateDownloadSequence, InitiateDownloadSequence_Response, ConfirmedServiceResponse_initiateDownloadSequence);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::downloadSegment, downloadSegment, DownloadSegment_Response, ConfirmedServiceResponse_downloadSegment);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::terminateDownloadSequence, terminateDownloadSequence, TerminateDownloadSequence_Response, ConfirmedServiceResponse_terminateDownloadSequence);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::initiateUploadSequence, initiateUploadSequence, InitiateUploadSequence_Response, ConfirmedServiceResponse_initiateUploadSequence);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::uploadSegment, uploadSegment, UploadSegment_Response, ConfirmedServiceResponse_uploadSegment);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::terminateUploadSequence, terminateUploadSequence, TerminateUploadSequence_Response, ConfirmedServiceResponse_terminateUploadSequence);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::requestDomainDownload, requestDomainDownload, RequestDomainDownload_Response, ConfirmedServiceResponse_requestDomainDownload);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::requestDomainUpload, requestDomainUpload, RequestDomainUpload_Response, ConfirmedServiceResponse_requestDomainUpload);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::loadDomainContent, loadDomainContent, LoadDomainContent_Response, ConfirmedServiceResponse_loadDomainContent);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::storeDomainContent, storeDomainContent, StoreDomainContent_Response, ConfirmedServiceResponse_storeDomainContent);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteDomain, deleteDomain, DeleteDomain_Response, ConfirmedServiceResponse_deleteDomain);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getDomainAttributes, getDomainAttributes, GetDomainAttributes_Response, ConfirmedServiceResponse_getDomainAttributes);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::createProgramInvocation, createProgramInvocation, CreateProgramInvocation_Response, ConfirmedServiceResponse_createProgramInvocation);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteProgramInvocation, deleteProgramInvocation, DeleteProgramInvocation_Response, ConfirmedServiceResponse_deleteProgramInvocation);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::start, start, Start_Response, ConfirmedServiceResponse_start);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::stop, stop, Stop_Response, ConfirmedServiceResponse_stop);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::resume, resume, Resume_Response, ConfirmedServiceResponse_resume);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::reset, reset, Reset_Response, ConfirmedServiceResponse_reset);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::kill, kill, Kill_Response, ConfirmedServiceResponse_kill);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getProgramInvocationAttributes, getProgramInvocationAttributes, GetProgramInvocationAttributes_Response, ConfirmedServiceResponse_getProgramInvocationAttributes);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::obtainFile, obtainFile, ISO_9506_MMS_1A::ObtainFile_Response, ConfirmedServiceResponse_obtainFile);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineEventCondition, defineEventCondition, DefineEventCondition_Response, ConfirmedServiceResponse_defineEventCondition);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteEventCondition, deleteEventCondition, DeleteEventCondition_Response, ConfirmedServiceResponse_deleteEventCondition);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getEventConditionAttributes, getEventConditionAttributes, GetEventConditionAttributes_Response, ConfirmedServiceResponse_getEventConditionAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportEventConditionStatus, reportEventConditionStatus, ReportEventConditionStatus_Response, ConfirmedServiceResponse_reportEventConditionStatus);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::alterEventConditionMonitoring, alterEventConditionMonitoring, AlterEventConditionMonitoring_Response, ConfirmedServiceResponse_alterEventConditionMonitoring);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::triggerEvent, triggerEvent, TriggerEvent_Response, ConfirmedServiceResponse_triggerEvent);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineEventAction, defineEventAction, DefineEventAction_Response, ConfirmedServiceResponse_defineEventAction);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteEventAction, deleteEventAction, DeleteEventAction_Response, ConfirmedServiceResponse_deleteEventAction);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getEventActionAttributes, getEventActionAttributes, GetEventActionAttributes_Response, ConfirmedServiceResponse_getEventActionAttributes);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::reportEventActionStatus, reportEventActionStatus, ReportEventActionStatus_Response, ConfirmedServiceResponse_reportEventActionStatus);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineEventEnrollment, defineEventEnrollment, DefineEventEnrollment_Response, ConfirmedServiceResponse_defineEventEnrollment);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteEventEnrollment, deleteEventEnrollment, DeleteEventEnrollment_Response, ConfirmedServiceResponse_deleteEventEnrollment);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::alterEventEnrollment, alterEventEnrollment, AlterEventEnrollment_Response, ConfirmedServiceResponse_alterEventEnrollment);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportEventEnrollmentStatus, reportEventEnrollmentStatus, ReportEventEnrollmentStatus_Response, ConfirmedServiceResponse_reportEventEnrollmentStatus);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getEventEnrollmentAttributes, getEventEnrollmentAttributes, GetEventEnrollmentAttributes_Response, ConfirmedServiceResponse_getEventEnrollmentAttributes);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::acknowledgeEventNotification, acknowledgeEventNotification, AcknowledgeEventNotification_Response, ConfirmedServiceResponse_acknowledgeEventNotification);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getAlarmSummary, getAlarmSummary, GetAlarmSummary_Response, ConfirmedServiceResponse_getAlarmSummary);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getAlarmEnrollmentSummary, getAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Response, ConfirmedServiceResponse_getAlarmEnrollmentSummary);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::readJournal, readJournal, ReadJournal_Response, ConfirmedServiceResponse_readJournal);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::writeJournal, writeJournal, WriteJournal_Response, ConfirmedServiceResponse_writeJournal);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::initializeJournal, initializeJournal, InitializeJournal_Response, ConfirmedServiceResponse_initializeJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportJournalStatus, reportJournalStatus, ReportJournalStatus_Response, ConfirmedServiceResponse_reportJournalStatus);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::createJournal, createJournal, CreateJournal_Response, ConfirmedServiceResponse_createJournal);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteJournal, deleteJournal, DeleteJournal_Response, ConfirmedServiceResponse_deleteJournal);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getCapabilityList, getCapabilityList, GetCapabilityList_Response, ConfirmedServiceResponse_getCapabilityList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::fileOpen, fileOpen, ISO_9506_MMS_1A::FileOpen_Response, ConfirmedServiceResponse_fileOpen);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::fileRead, fileRead, ISO_9506_MMS_1A::FileRead_Response, ConfirmedServiceResponse_fileRead);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::fileClose, fileClose, ISO_9506_MMS_1A::FileClose_Response, ConfirmedServiceResponse_fileClose);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::fileRename, fileRename, ISO_9506_MMS_1A::FileRename_Response, ConfirmedServiceResponse_fileRename);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::fileDelete, fileDelete, ISO_9506_MMS_1A::FileDelete_Response, ConfirmedServiceResponse_fileDelete);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::fileDirectory, fileDirectory, ISO_9506_MMS_1A::FileDirectory_Response, ConfirmedServiceResponse_fileDirectory);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::additionalService, additionalService, AdditionalService_Response, ConfirmedServiceResponse_additionalService);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getDataExchangeAttributes, getDataExchangeAttributes, GetDataExchangeAttributes_Response, ConfirmedServiceResponse_getDataExchangeAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::exchangeData, exchangeData, ExchangeData_Response, ConfirmedServiceResponse_exchangeData);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::defineAccessControlList, defineAccessControlList, DefineAccessControlList_Response, ConfirmedServiceResponse_defineAccessControlList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::getAccessControlListAttributes, getAccessControlListAttributes, GetAccessControlListAttributes_Response, ConfirmedServiceResponse_getAccessControlListAttributes);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::reportAccessControlledObjects, reportAccessControlledObjects, ReportAccessControlledObjects_Response, ConfirmedServiceResponse_reportAccessControlledObjects);
    ITU_T_CHOICES_DEFN(ConfirmedServiceResponse::deleteAccessControlList, deleteAccessControlList, DeleteAccessControlList_Response, ConfirmedServiceResponse_deleteAccessControlList);
    ITU_T_CHOICEC_DEFN(ConfirmedServiceResponse::changeAccessControl, changeAccessControl, ChangeAccessControl_Response, ConfirmedServiceResponse_changeAccessControl);

    // choice AdditionalService-Response

    ITU_T_CHOICES_DEFN(AdditionalService_Response::vMDStop, vMDStop, VMDStop_Response, AdditionalService_Response_vMDStop);
    ITU_T_CHOICEC_DEFN(AdditionalService_Response::vMDReset, vMDReset, VMDReset_Response, AdditionalService_Response_vMDReset);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::select, select, Select_Response, AdditionalService_Response_select);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::alterPI, alterPI, AlterProgramInvocationAttributes_Response, AdditionalService_Response_alterPI);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::initiateUCLoad, initiateUCLoad, InitiateUnitControlLoad_Response, AdditionalService_Response_initiateUCLoad);
    ITU_T_CHOICEC_DEFN(AdditionalService_Response::uCLoad, uCLoad, UnitControlLoadSegment_Response, AdditionalService_Response_uCLoad);
    ITU_T_CHOICEC_DEFN(AdditionalService_Response::uCUpload, uCUpload, UnitControlUpload_Response, AdditionalService_Response_uCUpload);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::startUC, startUC, StartUnitControl_Response, AdditionalService_Response_startUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::stopUC, stopUC, StopUnitControl_Response, AdditionalService_Response_stopUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::createUC, createUC, CreateUnitControl_Response, AdditionalService_Response_createUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::addToUC, addToUC, AddToUnitControl_Response, AdditionalService_Response_addToUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::removeFromUC, removeFromUC, RemoveFromUnitControl_Response, AdditionalService_Response_removeFromUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Response::getUCAttributes, getUCAttributes, GetUnitControlAttributes_Response, AdditionalService_Response_getUCAttributes);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::loadUCFromFile, loadUCFromFile, LoadUnitControlFromFile_Response, AdditionalService_Response_loadUCFromFile);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::storeUCToFile, storeUCToFile, StoreUnitControlToFile_Response, AdditionalService_Response_storeUCToFile);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::deleteUC, deleteUC, DeleteUnitControl_Response, AdditionalService_Response_deleteUC);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::defineECL, defineECL, DefineEventConditionList_Response, AdditionalService_Response_defineECL);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::deleteECL, deleteECL, DeleteEventConditionList_Response, AdditionalService_Response_deleteECL);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::addECLReference, addECLReference, AddEventConditionListReference_Response, AdditionalService_Response_addECLReference);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::removeECLReference, removeECLReference, RemoveEventConditionListReference_Response, AdditionalService_Response_removeECLReference);
    ITU_T_CHOICEC_DEFN(AdditionalService_Response::getECLAttributes, getECLAttributes, GetEventConditionListAttributes_Response, AdditionalService_Response_getECLAttributes);
    ITU_T_CHOICEC_DEFN(AdditionalService_Response::reportECLStatus, reportECLStatus, ReportEventConditionListStatus_Response, AdditionalService_Response_reportECLStatus);
    ITU_T_CHOICES_DEFN(AdditionalService_Response::alterECLMonitoring, alterECLMonitoring, AlterEventConditionListMonitoring_Response, AdditionalService_Response_alterECLMonitoring);

    // choice Response-Detail

    ITU_T_CHOICES_DEFN(Response_Detail::otherRequests, otherRequests, null_type, Response_Detail_otherRequests);
    ITU_T_CHOICEC_DEFN(Response_Detail::status, status, CS_Status_Response, Response_Detail_status);
    ITU_T_CHOICEC_DEFN(Response_Detail::getProgramInvocationAttributes, getProgramInvocationAttributes, CS_GetProgramInvocationAttributes_Response, Response_Detail_getProgramInvocationAttributes);
    ITU_T_CHOICEC_DEFN(Response_Detail::getEventConditionAttributes, getEventConditionAttributes, CS_GetEventConditionAttributes_Response, Response_Detail_getEventConditionAttributes);

    // sequence Confirmed-ErrorPDU

    Confirmed_ErrorPDU::Confirmed_ErrorPDU() : invokeID_(), serviceError_() {
    };

    Confirmed_ErrorPDU::Confirmed_ErrorPDU(const Unsigned32& arg__invokeID,
            const ServiceError& arg__serviceError) :
    invokeID_(arg__invokeID),
    serviceError_(arg__serviceError) {
    };

    Confirmed_ErrorPDU::Confirmed_ErrorPDU(shared_ptr< Unsigned32> arg__invokeID,
            shared_ptr< Unsigned32> arg__modifierPosition,
            shared_ptr< ServiceError> arg__serviceError) :
    invokeID_(arg__invokeID),
    modifierPosition_(arg__modifierPosition),
    serviceError_(arg__serviceError) {
    };


    ITU_T_HOLDERH_DEFN(Confirmed_ErrorPDU::invokeID, invokeID, Unsigned32);
    ITU_T_OPTIONAL_DEFN(Confirmed_ErrorPDU::modifierPosition, modifierPosition, Unsigned32);
    ITU_T_HOLDERH_DEFN(Confirmed_ErrorPDU::serviceError, serviceError, ServiceError);

    // sequence ServiceError

    ServiceError::ServiceError() : errorClass_() {
    };

    ServiceError::ServiceError(const ErrorClass_type& arg__errorClass) :
    errorClass_(arg__errorClass) {
    };

    ServiceError::ServiceError(shared_ptr< ErrorClass_type> arg__errorClass,
            shared_ptr< int> arg__additionalCode,
            shared_ptr< visiblestring_type> arg__additionalDescription,
            shared_ptr< ServiceSpecificInfo_type> arg__serviceSpecificInfo) :
    errorClass_(arg__errorClass),
    additionalCode_(arg__additionalCode),
    additionalDescription_(arg__additionalDescription),
    serviceSpecificInfo_(arg__serviceSpecificInfo) {
    };


    const uint8_t ServiceError::ErrorClass_type::vmd_state_other = 0;
    const uint8_t ServiceError::ErrorClass_type::vmd_state_vmd_state_conflict = 1;
    const uint8_t ServiceError::ErrorClass_type::vmd_state_vmd_operational_problem = 2;
    const uint8_t ServiceError::ErrorClass_type::vmd_state_domain_transfer_problem = 3;
    const uint8_t ServiceError::ErrorClass_type::vmd_state_state_machine_id_invalid = 4;

    const uint8_t ServiceError::ErrorClass_type::application_reference_other = 0;
    const uint8_t ServiceError::ErrorClass_type::application_reference_application_unreachable = 1;
    const uint8_t ServiceError::ErrorClass_type::application_reference_connection_lost = 2;
    const uint8_t ServiceError::ErrorClass_type::application_reference_application_reference_invalid = 3;
    const uint8_t ServiceError::ErrorClass_type::application_reference_context_unsupported = 4;

    const uint8_t ServiceError::ErrorClass_type::definition_other = 0;
    const uint8_t ServiceError::ErrorClass_type::definition_object_undefined = 1;
    const uint8_t ServiceError::ErrorClass_type::definition_invalid_address = 2;
    const uint8_t ServiceError::ErrorClass_type::definition_type_unsupported = 3;
    const uint8_t ServiceError::ErrorClass_type::definition_type_inconsistent = 4;
    const uint8_t ServiceError::ErrorClass_type::definition_object_exists = 5;
    const uint8_t ServiceError::ErrorClass_type::definition_object_attribute_inconsistent = 6;

    const uint8_t ServiceError::ErrorClass_type::resource_other = 0;
    const uint8_t ServiceError::ErrorClass_type::resource_memory_unavailable = 1;
    const uint8_t ServiceError::ErrorClass_type::resource_processor_resource_unavailable = 2;
    const uint8_t ServiceError::ErrorClass_type::resource_mass_storage_unavailable = 3;
    const uint8_t ServiceError::ErrorClass_type::resource_capability_unavailable = 4;
    const uint8_t ServiceError::ErrorClass_type::resource_capability_unknown = 5;

    const uint8_t ServiceError::ErrorClass_type::service_other = 0;
    const uint8_t ServiceError::ErrorClass_type::service_primitives_out_of_sequence = 1;
    const uint8_t ServiceError::ErrorClass_type::service_object_state_conflict = 2;
    const uint8_t ServiceError::ErrorClass_type::service_continuation_invalid = 4;
    const uint8_t ServiceError::ErrorClass_type::service_object_constraint_conflict = 5;

    const uint8_t ServiceError::ErrorClass_type::service_preempt_other = 0;
    const uint8_t ServiceError::ErrorClass_type::service_preempt_timeout = 1;
    const uint8_t ServiceError::ErrorClass_type::service_preempt_deadlock = 2;
    const uint8_t ServiceError::ErrorClass_type::service_preempt_cancel = 3;

    const uint8_t ServiceError::ErrorClass_type::time_resolution_other = 0;
    const uint8_t ServiceError::ErrorClass_type::time_resolution_unsupportable_time_resolution = 1;

    const uint8_t ServiceError::ErrorClass_type::access_other = 0;
    const uint8_t ServiceError::ErrorClass_type::access_object_access_unsupported = 1;
    const uint8_t ServiceError::ErrorClass_type::access_object_non_existent = 2;
    const uint8_t ServiceError::ErrorClass_type::access_object_access_denied = 3;
    const uint8_t ServiceError::ErrorClass_type::access_object_invalidated = 4;

    const uint8_t ServiceError::ErrorClass_type::initiate_other = 0;
    const uint8_t ServiceError::ErrorClass_type::initiate_max_services_outstanding_calling_insufficient = 3;
    const uint8_t ServiceError::ErrorClass_type::initiate_max_services_outstanding_called_insufficient = 4;
    const uint8_t ServiceError::ErrorClass_type::initiate_service_CBB_insufficient = 5;
    const uint8_t ServiceError::ErrorClass_type::initiate_parameter_CBB_insufficient = 6;
    const uint8_t ServiceError::ErrorClass_type::initiate_nesting_level_insufficient = 7;

    const uint8_t ServiceError::ErrorClass_type::conclude_other = 0;
    const uint8_t ServiceError::ErrorClass_type::conclude_further_communication_required = 1;

    const uint8_t ServiceError::ErrorClass_type::cancel_other = 0;
    const uint8_t ServiceError::ErrorClass_type::cancel_invoke_id_unknown = 1;
    const uint8_t ServiceError::ErrorClass_type::cancel_cancel_not_possible = 2;

    const uint8_t ServiceError::ErrorClass_type::file_other = 0;
    const uint8_t ServiceError::ErrorClass_type::file_filename_ambiguous = 1;
    const uint8_t ServiceError::ErrorClass_type::file_file_busy = 2;
    const uint8_t ServiceError::ErrorClass_type::file_filename_syntax_error = 3;
    const uint8_t ServiceError::ErrorClass_type::file_content_type_invalid = 4;
    const uint8_t ServiceError::ErrorClass_type::file_position_invalid = 5;
    const uint8_t ServiceError::ErrorClass_type::file_file_access_denied = 6;
    const uint8_t ServiceError::ErrorClass_type::file_file_non_existent = 7;
    const uint8_t ServiceError::ErrorClass_type::file_duplicate_filename = 8;
    const uint8_t ServiceError::ErrorClass_type::file_insufficient_space_in_filestore = 9;


    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::vmd_state, vmd_state, uint8_t, ErrorClass_type_vmd_state);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::application_reference, application_reference, uint8_t, ErrorClass_type_application_reference);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::definition, definition, uint8_t, ErrorClass_type_definition);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::resource, resource, uint8_t, ErrorClass_type_resource);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::service, service, uint8_t, ErrorClass_type_service);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::service_preempt, service_preempt, uint8_t, ErrorClass_type_service_preempt);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::time_resolution, time_resolution, uint8_t, ErrorClass_type_time_resolution);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::access, access, uint8_t, ErrorClass_type_access);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::initiate, initiate, uint8_t, ErrorClass_type_initiate);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::conclude, conclude, uint8_t, ErrorClass_type_conclude);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::cancel, cancel, uint8_t, ErrorClass_type_cancel);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::file, file, uint8_t, ErrorClass_type_file);
    ITU_T_CHOICES_DEFN(ServiceError::ErrorClass_type::others, others, int, ErrorClass_type_others);



    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::obtainFile, obtainFile, ISO_9506_MMS_1A::ObtainFile_Error, ServiceSpecificInfo_type_obtainFile);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::start, start, Start_Error, ServiceSpecificInfo_type_start);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::stop, stop, Stop_Error, ServiceSpecificInfo_type_stop);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::resume, resume, Resume_Error, ServiceSpecificInfo_type_resume);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::reset, reset, Reset_Error, ServiceSpecificInfo_type_reset);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::deleteVariableAccess, deleteVariableAccess, DeleteVariableAccess_Error, ServiceSpecificInfo_type_deleteVariableAccess);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::deleteNamedVariableList, deleteNamedVariableList, DeleteNamedVariableList_Error, ServiceSpecificInfo_type_deleteNamedVariableList);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::deleteNamedType, deleteNamedType, DeleteNamedType_Error, ServiceSpecificInfo_type_deleteNamedType);
    ITU_T_CHOICEC_DEFN(ServiceError::ServiceSpecificInfo_type::defineEventEnrollment_Error, defineEventEnrollment_Error, DefineEventEnrollment_Error, ServiceSpecificInfo_type_defineEventEnrollment_Error);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::fileRename, fileRename, ISO_9506_MMS_1A::FileRename_Error, ServiceSpecificInfo_type_fileRename);
    ITU_T_CHOICEC_DEFN(ServiceError::ServiceSpecificInfo_type::additionalService, additionalService, AdditionalService_Error, ServiceSpecificInfo_type_additionalService);
    ITU_T_CHOICES_DEFN(ServiceError::ServiceSpecificInfo_type::changeAccessControl, changeAccessControl, ChangeAccessControl_Error, ServiceSpecificInfo_type_changeAccessControl);


    ITU_T_HOLDERH_DEFN(ServiceError::errorClass, errorClass, ServiceError::ErrorClass_type);
    ITU_T_OPTIONAL_DEFN(ServiceError::additionalCode, additionalCode, int);
    ITU_T_OPTIONAL_DEFN(ServiceError::additionalDescription, additionalDescription, visiblestring_type);
    ITU_T_OPTIONAL_DEFN(ServiceError::serviceSpecificInfo, serviceSpecificInfo, ServiceError::ServiceSpecificInfo_type);

    // choice AdditionalService-Error

    ITU_T_CHOICEC_DEFN(AdditionalService_Error::defineEcl, defineEcl, DefineEventConditionList_Error, AdditionalService_Error_defineEcl);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::addECLReference, addECLReference, AddEventConditionListReference_Error, AdditionalService_Error_addECLReference);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::removeECLReference, removeECLReference, RemoveEventConditionListReference_Error, AdditionalService_Error_removeECLReference);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::initiateUC, initiateUC, InitiateUnitControl_Error, AdditionalService_Error_initiateUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::startUC, startUC, StartUnitControl_Error, AdditionalService_Error_startUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::stopUC, stopUC, StopUnitControl_Error, AdditionalService_Error_stopUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::deleteUC, deleteUC, DeleteUnitControl_Error, AdditionalService_Error_deleteUC);
    ITU_T_CHOICEC_DEFN(AdditionalService_Error::loadUCFromFile, loadUCFromFile, LoadUnitControlFromFile_Error, AdditionalService_Error_loadUCFromFile);

    // choice ObjectName

    ObjectName::Domain_specific_type::Domain_specific_type() : domainID_(), itemID_() {
    };

    ObjectName::Domain_specific_type::Domain_specific_type(const Identifier& arg__domainID,
            const Identifier& arg__itemID) :
    domainID_(arg__domainID),
    itemID_(arg__itemID) {
    };


    ITU_T_HOLDERH_DEFN(ObjectName::Domain_specific_type::domainID, domainID, Identifier);
    ITU_T_HOLDERH_DEFN(ObjectName::Domain_specific_type::itemID, itemID, Identifier);


    ITU_T_CHOICES_DEFN(ObjectName::vmd_specific, vmd_specific, Identifier, ObjectName_vmd_specific);
    ITU_T_CHOICEC_DEFN(ObjectName::domain_specific, domain_specific, ObjectName::Domain_specific_type, ObjectName_domain_specific);
    ITU_T_CHOICES_DEFN(ObjectName::aa_specific, aa_specific, Identifier, ObjectName_aa_specific);

    // choice ObjectClass
    const uint8_t ObjectClass::basicObjectClass_namedVariable = 0;
    const uint8_t ObjectClass::basicObjectClass_scatteredAccess = 1;
    const uint8_t ObjectClass::basicObjectClass_namedVariableList = 2;
    const uint8_t ObjectClass::basicObjectClass_namedType = 3;
    const uint8_t ObjectClass::basicObjectClass_semaphore = 4;
    const uint8_t ObjectClass::basicObjectClass_eventCondition = 5;
    const uint8_t ObjectClass::basicObjectClass_eventAction = 6;
    const uint8_t ObjectClass::basicObjectClass_eventEnrollment = 7;
    const uint8_t ObjectClass::basicObjectClass_journal = 8;
    const uint8_t ObjectClass::basicObjectClass_domain = 9;
    const uint8_t ObjectClass::basicObjectClass_programInvocation = 10;
    const uint8_t ObjectClass::basicObjectClass_operatorStation = 11;
    const uint8_t ObjectClass::basicObjectClass_dataExchange = 12;
    const uint8_t ObjectClass::basicObjectClass_accessControlList = 13;

    const uint8_t ObjectClass::csObjectClass_eventConditionList = 0;
    const uint8_t ObjectClass::csObjectClass_unitControl = 1;


    ITU_T_CHOICES_DEFN(ObjectClass::basicObjectClass, basicObjectClass, uint8_t, ObjectClass_basicObjectClass);
    ITU_T_CHOICES_DEFN(ObjectClass::csObjectClass, csObjectClass, uint8_t, ObjectClass_csObjectClass);

    // sequence Initiate-RequestPDU

    Initiate_RequestPDU::Initiate_RequestPDU() : proposedMaxServOutstandingCalling_(), proposedMaxServOutstandingCalled_(), initRequestDetail_() {
    };

    Initiate_RequestPDU::Initiate_RequestPDU(const Integer16& arg__proposedMaxServOutstandingCalling,
            const Integer16& arg__proposedMaxServOutstandingCalled,
            const InitRequestDetail_type& arg__initRequestDetail) :
    proposedMaxServOutstandingCalling_(arg__proposedMaxServOutstandingCalling),
    proposedMaxServOutstandingCalled_(arg__proposedMaxServOutstandingCalled),
    initRequestDetail_(arg__initRequestDetail) {
    };

    Initiate_RequestPDU::Initiate_RequestPDU(shared_ptr< Integer32> arg__localDetailCalling,
            shared_ptr< Integer16> arg__proposedMaxServOutstandingCalling,
            shared_ptr< Integer16> arg__proposedMaxServOutstandingCalled,
            shared_ptr< Integer8> arg__proposedDataStructureNestingLevel,
            shared_ptr< InitRequestDetail_type> arg__initRequestDetail) :
    localDetailCalling_(arg__localDetailCalling),
    proposedMaxServOutstandingCalling_(arg__proposedMaxServOutstandingCalling),
    proposedMaxServOutstandingCalled_(arg__proposedMaxServOutstandingCalled),
    proposedDataStructureNestingLevel_(arg__proposedDataStructureNestingLevel),
    initRequestDetail_(arg__initRequestDetail) {
    };

    Initiate_RequestPDU::InitRequestDetail_type::InitRequestDetail_type() : proposedVersionNumber_(), proposedParameterCBB_(), servicesSupportedCalling_() {
    };

    Initiate_RequestPDU::InitRequestDetail_type::InitRequestDetail_type(const Integer16& arg__proposedVersionNumber,
            const MMS_Object_Module_1::ParameterSupportOptions& arg__proposedParameterCBB,
            const MMS_Object_Module_1::ServiceSupportOptions& arg__servicesSupportedCalling) :
    proposedVersionNumber_(arg__proposedVersionNumber),
    proposedParameterCBB_(arg__proposedParameterCBB),
    servicesSupportedCalling_(arg__servicesSupportedCalling) {
    };

    Initiate_RequestPDU::InitRequestDetail_type::InitRequestDetail_type(shared_ptr< Integer16> arg__proposedVersionNumber,
            shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> arg__proposedParameterCBB,
            shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> arg__servicesSupportedCalling,
            shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> arg__additionalSupportedCalling,
            shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> arg__additionalCbbSupportedCalling,
            shared_ptr< visiblestring_type> arg__privilegeClassIdentityCalling) :
    proposedVersionNumber_(arg__proposedVersionNumber),
    proposedParameterCBB_(arg__proposedParameterCBB),
    servicesSupportedCalling_(arg__servicesSupportedCalling),
    additionalSupportedCalling_(arg__additionalSupportedCalling),
    additionalCbbSupportedCalling_(arg__additionalCbbSupportedCalling),
    privilegeClassIdentityCalling_(arg__privilegeClassIdentityCalling) {
    };


    ITU_T_HOLDERH_DEFN(Initiate_RequestPDU::InitRequestDetail_type::proposedVersionNumber, proposedVersionNumber, Integer16);
    ITU_T_HOLDERH_DEFN(Initiate_RequestPDU::InitRequestDetail_type::proposedParameterCBB, proposedParameterCBB, MMS_Object_Module_1::ParameterSupportOptions);
    ITU_T_HOLDERH_DEFN(Initiate_RequestPDU::InitRequestDetail_type::servicesSupportedCalling, servicesSupportedCalling, MMS_Object_Module_1::ServiceSupportOptions);
    ITU_T_OPTIONAL_DEFN(Initiate_RequestPDU::InitRequestDetail_type::additionalSupportedCalling, additionalSupportedCalling, MMS_Object_Module_1::AdditionalSupportOptions);
    ITU_T_OPTIONAL_DEFN(Initiate_RequestPDU::InitRequestDetail_type::additionalCbbSupportedCalling, additionalCbbSupportedCalling, MMS_Object_Module_1::AdditionalCBBOptions);
    ITU_T_OPTIONAL_DEFN(Initiate_RequestPDU::InitRequestDetail_type::privilegeClassIdentityCalling, privilegeClassIdentityCalling, visiblestring_type);


    ITU_T_OPTIONAL_DEFN(Initiate_RequestPDU::localDetailCalling, localDetailCalling, Integer32);
    ITU_T_HOLDERH_DEFN(Initiate_RequestPDU::proposedMaxServOutstandingCalling, proposedMaxServOutstandingCalling, Integer16);
    ITU_T_HOLDERH_DEFN(Initiate_RequestPDU::proposedMaxServOutstandingCalled, proposedMaxServOutstandingCalled, Integer16);
    ITU_T_OPTIONAL_DEFN(Initiate_RequestPDU::proposedDataStructureNestingLevel, proposedDataStructureNestingLevel, Integer8);
    ITU_T_HOLDERH_DEFN(Initiate_RequestPDU::initRequestDetail, initRequestDetail, Initiate_RequestPDU::InitRequestDetail_type);

    // sequence Initiate-ResponsePDU

    Initiate_ResponsePDU::Initiate_ResponsePDU() : negotiatedMaxServOutstandingCalling_(), negotiatedMaxServOutstandingCalled_(), initResponseDetail_() {
    };

    Initiate_ResponsePDU::Initiate_ResponsePDU(const Integer16& arg__negotiatedMaxServOutstandingCalling,
            const Integer16& arg__negotiatedMaxServOutstandingCalled,
            const InitResponseDetail_type& arg__initResponseDetail) :
    negotiatedMaxServOutstandingCalling_(arg__negotiatedMaxServOutstandingCalling),
    negotiatedMaxServOutstandingCalled_(arg__negotiatedMaxServOutstandingCalled),
    initResponseDetail_(arg__initResponseDetail) {
    };

    Initiate_ResponsePDU::Initiate_ResponsePDU(shared_ptr< Integer32> arg__localDetailCalled,
            shared_ptr< Integer16> arg__negotiatedMaxServOutstandingCalling,
            shared_ptr< Integer16> arg__negotiatedMaxServOutstandingCalled,
            shared_ptr< Integer8> arg__negotiatedDataStructureNestingLevel,
            shared_ptr< InitResponseDetail_type> arg__initResponseDetail) :
    localDetailCalled_(arg__localDetailCalled),
    negotiatedMaxServOutstandingCalling_(arg__negotiatedMaxServOutstandingCalling),
    negotiatedMaxServOutstandingCalled_(arg__negotiatedMaxServOutstandingCalled),
    negotiatedDataStructureNestingLevel_(arg__negotiatedDataStructureNestingLevel),
    initResponseDetail_(arg__initResponseDetail) {
    };

    Initiate_ResponsePDU::InitResponseDetail_type::InitResponseDetail_type() : negotiatedVersionNumber_(), negotiatedParameterCBB_(), servicesSupportedCalled_() {
    };

    Initiate_ResponsePDU::InitResponseDetail_type::InitResponseDetail_type(const Integer16& arg__negotiatedVersionNumber,
            const MMS_Object_Module_1::ParameterSupportOptions& arg__negotiatedParameterCBB,
            const MMS_Object_Module_1::ServiceSupportOptions& arg__servicesSupportedCalled) :
    negotiatedVersionNumber_(arg__negotiatedVersionNumber),
    negotiatedParameterCBB_(arg__negotiatedParameterCBB),
    servicesSupportedCalled_(arg__servicesSupportedCalled) {
    };

    Initiate_ResponsePDU::InitResponseDetail_type::InitResponseDetail_type(shared_ptr< Integer16> arg__negotiatedVersionNumber,
            shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> arg__negotiatedParameterCBB,
            shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> arg__servicesSupportedCalled,
            shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> arg__additionalSupportedCalled,
            shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> arg__additionalCbbSupportedCalled,
            shared_ptr< visiblestring_type> arg__privilegeClassIdentityCalled) :
    negotiatedVersionNumber_(arg__negotiatedVersionNumber),
    negotiatedParameterCBB_(arg__negotiatedParameterCBB),
    servicesSupportedCalled_(arg__servicesSupportedCalled),
    additionalSupportedCalled_(arg__additionalSupportedCalled),
    additionalCbbSupportedCalled_(arg__additionalCbbSupportedCalled),
    privilegeClassIdentityCalled_(arg__privilegeClassIdentityCalled) {
    };


    ITU_T_HOLDERH_DEFN(Initiate_ResponsePDU::InitResponseDetail_type::negotiatedVersionNumber, negotiatedVersionNumber, Integer16);
    ITU_T_HOLDERH_DEFN(Initiate_ResponsePDU::InitResponseDetail_type::negotiatedParameterCBB, negotiatedParameterCBB, MMS_Object_Module_1::ParameterSupportOptions);
    ITU_T_HOLDERH_DEFN(Initiate_ResponsePDU::InitResponseDetail_type::servicesSupportedCalled, servicesSupportedCalled, MMS_Object_Module_1::ServiceSupportOptions);
    ITU_T_OPTIONAL_DEFN(Initiate_ResponsePDU::InitResponseDetail_type::additionalSupportedCalled, additionalSupportedCalled, MMS_Object_Module_1::AdditionalSupportOptions);
    ITU_T_OPTIONAL_DEFN(Initiate_ResponsePDU::InitResponseDetail_type::additionalCbbSupportedCalled, additionalCbbSupportedCalled, MMS_Object_Module_1::AdditionalCBBOptions);
    ITU_T_OPTIONAL_DEFN(Initiate_ResponsePDU::InitResponseDetail_type::privilegeClassIdentityCalled, privilegeClassIdentityCalled, visiblestring_type);


    ITU_T_OPTIONAL_DEFN(Initiate_ResponsePDU::localDetailCalled, localDetailCalled, Integer32);
    ITU_T_HOLDERH_DEFN(Initiate_ResponsePDU::negotiatedMaxServOutstandingCalling, negotiatedMaxServOutstandingCalling, Integer16);
    ITU_T_HOLDERH_DEFN(Initiate_ResponsePDU::negotiatedMaxServOutstandingCalled, negotiatedMaxServOutstandingCalled, Integer16);
    ITU_T_OPTIONAL_DEFN(Initiate_ResponsePDU::negotiatedDataStructureNestingLevel, negotiatedDataStructureNestingLevel, Integer8);
    ITU_T_HOLDERH_DEFN(Initiate_ResponsePDU::initResponseDetail, initResponseDetail, Initiate_ResponsePDU::InitResponseDetail_type);

    // sequence Cancel-ErrorPDU

    Cancel_ErrorPDU::Cancel_ErrorPDU() : originalInvokeID_(), serviceError_() {
    };

    Cancel_ErrorPDU::Cancel_ErrorPDU(const Unsigned32& arg__originalInvokeID,
            const ServiceError& arg__serviceError) :
    originalInvokeID_(arg__originalInvokeID),
    serviceError_(arg__serviceError) {
    };


    ITU_T_HOLDERH_DEFN(Cancel_ErrorPDU::originalInvokeID, originalInvokeID, Unsigned32);
    ITU_T_HOLDERH_DEFN(Cancel_ErrorPDU::serviceError, serviceError, ServiceError);

    // sequence RejectPDU

    RejectPDU::RejectPDU() : rejectReason_() {
    };

    RejectPDU::RejectPDU(const RejectReason_type& arg__rejectReason) :
    rejectReason_(arg__rejectReason) {
    };

    RejectPDU::RejectPDU(shared_ptr< Unsigned32> arg__originalInvokeID,
            shared_ptr< RejectReason_type> arg__rejectReason) :
    originalInvokeID_(arg__originalInvokeID),
    rejectReason_(arg__rejectReason) {
    };


    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_unrecognized_service = 1;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_unrecognized_modifier = 2;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_invalid_invokeID = 3;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_invalid_argument = 4;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_invalid_modifier = 5;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_max_serv_outstanding_exceeded = 6;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_max_recursion_exceeded = 8;
    const uint8_t RejectPDU::RejectReason_type::confirmed_requestPDU_value_out_of_range = 9;

    const uint8_t RejectPDU::RejectReason_type::confirmed_responsePDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::confirmed_responsePDU_unrecognized_service = 1;
    const uint8_t RejectPDU::RejectReason_type::confirmed_responsePDU_invalid_invokeID = 2;
    const uint8_t RejectPDU::RejectReason_type::confirmed_responsePDU_invalid_result = 3;
    const uint8_t RejectPDU::RejectReason_type::confirmed_responsePDU_max_recursion_exceeded = 5;
    const uint8_t RejectPDU::RejectReason_type::confirmed_responsePDU_value_out_of_range = 6;

    const uint8_t RejectPDU::RejectReason_type::confirmed_errorPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::confirmed_errorPDU_unrecognized_service = 1;
    const uint8_t RejectPDU::RejectReason_type::confirmed_errorPDU_invalid_invokeID = 2;
    const uint8_t RejectPDU::RejectReason_type::confirmed_errorPDU_invalid_serviceError = 3;
    const uint8_t RejectPDU::RejectReason_type::confirmed_errorPDU_value_out_of_range = 4;

    const uint8_t RejectPDU::RejectReason_type::unconfirmedPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::unconfirmedPDU_unrecognized_service = 1;
    const uint8_t RejectPDU::RejectReason_type::unconfirmedPDU_invalid_argument = 2;
    const uint8_t RejectPDU::RejectReason_type::unconfirmedPDU_max_recursion_exceeded = 3;
    const uint8_t RejectPDU::RejectReason_type::unconfirmedPDU_value_out_of_range = 4;

    const int RejectPDU::RejectReason_type::pdu_error_unknown_pdu_type = 0;
    const int RejectPDU::RejectReason_type::pdu_error_invalid_pdu = 1;
    const int RejectPDU::RejectReason_type::pdu_error_illegal_acse_mapping = 2;

    const uint8_t RejectPDU::RejectReason_type::cancel_requestPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::cancel_requestPDU_invalid_invokeID = 1;

    const uint8_t RejectPDU::RejectReason_type::cancel_responsePDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::cancel_responsePDU_invalid_invokeID = 1;

    const uint8_t RejectPDU::RejectReason_type::cancel_errorPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::cancel_errorPDU_invalid_invokeID = 1;
    const uint8_t RejectPDU::RejectReason_type::cancel_errorPDU_invalid_serviceError = 2;
    const uint8_t RejectPDU::RejectReason_type::cancel_errorPDU_value_out_of_range = 3;

    const uint8_t RejectPDU::RejectReason_type::conclude_requestPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::conclude_requestPDU_invalid_argument = 1;

    const uint8_t RejectPDU::RejectReason_type::conclude_responsePDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::conclude_responsePDU_invalid_result = 1;

    const uint8_t RejectPDU::RejectReason_type::conclude_errorPDU_other = 0;
    const uint8_t RejectPDU::RejectReason_type::conclude_errorPDU_invalid_serviceError = 1;
    const uint8_t RejectPDU::RejectReason_type::conclude_errorPDU_value_out_of_range = 2;


    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::confirmed_requestPDU, confirmed_requestPDU, uint8_t, RejectReason_type_confirmed_requestPDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::confirmed_responsePDU, confirmed_responsePDU, uint8_t, RejectReason_type_confirmed_responsePDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::confirmed_errorPDU, confirmed_errorPDU, uint8_t, RejectReason_type_confirmed_errorPDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::unconfirmedPDU, unconfirmedPDU, uint8_t, RejectReason_type_unconfirmedPDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::pdu_error, pdu_error, int, RejectReason_type_pdu_error);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::cancel_requestPDU, cancel_requestPDU, uint8_t, RejectReason_type_cancel_requestPDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::cancel_responsePDU, cancel_responsePDU, uint8_t, RejectReason_type_cancel_responsePDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::cancel_errorPDU, cancel_errorPDU, uint8_t, RejectReason_type_cancel_errorPDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::conclude_requestPDU, conclude_requestPDU, uint8_t, RejectReason_type_conclude_requestPDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::conclude_responsePDU, conclude_responsePDU, uint8_t, RejectReason_type_conclude_responsePDU);
    ITU_T_CHOICES_DEFN(RejectPDU::RejectReason_type::conclude_errorPDU, conclude_errorPDU, uint8_t, RejectReason_type_conclude_errorPDU);


    ITU_T_OPTIONAL_DEFN(RejectPDU::originalInvokeID, originalInvokeID, Unsigned32);
    ITU_T_HOLDERH_DEFN(RejectPDU::rejectReason, rejectReason, RejectPDU::RejectReason_type);

    // sequence DefineAccessControlList-Request

    DefineAccessControlList_Request::DefineAccessControlList_Request() : accessControlListName_(), accessControlListElements_() {
    };

    DefineAccessControlList_Request::DefineAccessControlList_Request(const Identifier& arg__accessControlListName,
            const AccessControlListElements_type& arg__accessControlListElements) :
    accessControlListName_(arg__accessControlListName),
    accessControlListElements_(arg__accessControlListElements) {
    };

    DefineAccessControlList_Request::AccessControlListElements_type::AccessControlListElements_type() {
    };

    DefineAccessControlList_Request::AccessControlListElements_type::AccessControlListElements_type(shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition) :
    readAccessCondition_(arg__readAccessCondition),
    storeAccessCondition_(arg__storeAccessCondition),
    writeAccessCondition_(arg__writeAccessCondition),
    loadAccessCondition_(arg__loadAccessCondition),
    executeAccessCondition_(arg__executeAccessCondition),
    deleteAccessCondition_(arg__deleteAccessCondition),
    editAccessCondition_(arg__editAccessCondition) {
    };


    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::readAccessCondition, readAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::storeAccessCondition, storeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::writeAccessCondition, writeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::loadAccessCondition, loadAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::executeAccessCondition, executeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::deleteAccessCondition, deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(DefineAccessControlList_Request::AccessControlListElements_type::editAccessCondition, editAccessCondition, MMS_Object_Module_1::AccessCondition);


    ITU_T_HOLDERH_DEFN(DefineAccessControlList_Request::accessControlListName, accessControlListName, Identifier);
    ITU_T_HOLDERH_DEFN(DefineAccessControlList_Request::accessControlListElements, accessControlListElements, DefineAccessControlList_Request::AccessControlListElements_type);

    // choice GetAccessControlListAttributes-Request

    GetAccessControlListAttributes_Request::NamedObject_type::NamedObject_type() : objectClass_(), objectName_() {
    };

    GetAccessControlListAttributes_Request::NamedObject_type::NamedObject_type(const ObjectClass& arg__objectClass,
            const ObjectName& arg__objectName) :
    objectClass_(arg__objectClass),
    objectName_(arg__objectName) {
    };


    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Request::NamedObject_type::objectClass, objectClass, ObjectClass);
    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Request::NamedObject_type::objectName, objectName, ObjectName);


    ITU_T_CHOICES_DEFN(GetAccessControlListAttributes_Request::accessControlListName, accessControlListName, Identifier, GetAccessControlListAttributes_Request_accessControlListName);
    ITU_T_CHOICES_DEFN(GetAccessControlListAttributes_Request::vMD, vMD, null_type, GetAccessControlListAttributes_Request_vMD);
    ITU_T_CHOICEC_DEFN(GetAccessControlListAttributes_Request::namedObject, namedObject, GetAccessControlListAttributes_Request::NamedObject_type, GetAccessControlListAttributes_Request_namedObject);

    // sequence GetAccessControlListAttributes-Response

    GetAccessControlListAttributes_Response::GetAccessControlListAttributes_Response() : name_(), accessControlListElements_(), vMDuse_(), references_() {
    };

    GetAccessControlListAttributes_Response::GetAccessControlListAttributes_Response(const Identifier& arg__name,
            const AccessControlListElements_type& arg__accessControlListElements,
            const bool& arg__vMDuse,
            const References_type& arg__references) :
    name_(arg__name),
    accessControlListElements_(arg__accessControlListElements),
    vMDuse_(arg__vMDuse),
    references_(arg__references) {
    };

    GetAccessControlListAttributes_Response::GetAccessControlListAttributes_Response(shared_ptr< Identifier> arg__name,
            shared_ptr< AccessControlListElements_type> arg__accessControlListElements,
            shared_ptr< bool> arg__vMDuse,
            shared_ptr< References_type> arg__references,
            shared_ptr< Identifier> arg__accessControlList) :
    name_(arg__name),
    accessControlListElements_(arg__accessControlListElements),
    vMDuse_(arg__vMDuse),
    references_(arg__references),
    accessControlList_(arg__accessControlList) {
    };

    GetAccessControlListAttributes_Response::AccessControlListElements_type::AccessControlListElements_type() {
    };

    GetAccessControlListAttributes_Response::AccessControlListElements_type::AccessControlListElements_type(shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
            shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition) :
    readAccessCondition_(arg__readAccessCondition),
    storeAccessCondition_(arg__storeAccessCondition),
    writeAccessCondition_(arg__writeAccessCondition),
    loadAccessCondition_(arg__loadAccessCondition),
    executeAccessCondition_(arg__executeAccessCondition),
    deleteAccessCondition_(arg__deleteAccessCondition),
    editAccessCondition_(arg__editAccessCondition) {
    };


    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::readAccessCondition, readAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::storeAccessCondition, storeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::writeAccessCondition, writeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::loadAccessCondition, loadAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::executeAccessCondition, executeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::deleteAccessCondition, deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::AccessControlListElements_type::editAccessCondition, editAccessCondition, MMS_Object_Module_1::AccessCondition);

    GetAccessControlListAttributes_Response::References_type_sequence_of::References_type_sequence_of() : objectClass_(), objectCount_() {
    };

    GetAccessControlListAttributes_Response::References_type_sequence_of::References_type_sequence_of(const ObjectClass& arg__objectClass,
            const int& arg__objectCount) :
    objectClass_(arg__objectClass),
    objectCount_(arg__objectCount) {
    };


    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Response::References_type_sequence_of::objectClass, objectClass, ObjectClass);
    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Response::References_type_sequence_of::objectCount, objectCount, int);


    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Response::name, name, Identifier);
    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Response::accessControlListElements, accessControlListElements, GetAccessControlListAttributes_Response::AccessControlListElements_type);
    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Response::vMDuse, vMDuse, bool);
    ITU_T_HOLDERH_DEFN(GetAccessControlListAttributes_Response::references, references, GetAccessControlListAttributes_Response::References_type);
    ITU_T_OPTIONAL_DEFN(GetAccessControlListAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence ReportAccessControlledObjects-Request

    ReportAccessControlledObjects_Request::ReportAccessControlledObjects_Request() : accessControlList_(), objectClass_() {
    };

    ReportAccessControlledObjects_Request::ReportAccessControlledObjects_Request(const Identifier& arg__accessControlList,
            const ObjectClass& arg__objectClass) :
    accessControlList_(arg__accessControlList),
    objectClass_(arg__objectClass) {
    };

    ReportAccessControlledObjects_Request::ReportAccessControlledObjects_Request(shared_ptr< Identifier> arg__accessControlList,
            shared_ptr< ObjectClass> arg__objectClass,
            shared_ptr< ObjectName> arg__continueAfter) :
    accessControlList_(arg__accessControlList),
    objectClass_(arg__objectClass),
    continueAfter_(arg__continueAfter) {
    };


    ITU_T_HOLDERH_DEFN(ReportAccessControlledObjects_Request::accessControlList, accessControlList, Identifier);
    ITU_T_HOLDERH_DEFN(ReportAccessControlledObjects_Request::objectClass, objectClass, ObjectClass);
    ITU_T_OPTIONAL_DEFN(ReportAccessControlledObjects_Request::continueAfter, continueAfter, ObjectName);

    // sequence ReportAccessControlledObjects-Response

    ReportAccessControlledObjects_Response::ReportAccessControlledObjects_Response() : listOfNames_() {
    };

    ReportAccessControlledObjects_Response::ReportAccessControlledObjects_Response(const ListOfNames_type& arg__listOfNames) :
    listOfNames_(arg__listOfNames) {
    };

    ReportAccessControlledObjects_Response::ReportAccessControlledObjects_Response(shared_ptr< ListOfNames_type> arg__listOfNames,
            shared_ptr< bool> arg__moreFollows) :
    listOfNames_(arg__listOfNames),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReportAccessControlledObjects_Response::moreFollows__default = false;


    ITU_T_HOLDERH_DEFN(ReportAccessControlledObjects_Response::listOfNames, listOfNames, ReportAccessControlledObjects_Response::ListOfNames_type);
    ITU_T_DEFAULTH_DEFN(ReportAccessControlledObjects_Response::moreFollows, moreFollows, bool);

    // sequence ChangeAccessControl-Request

    ChangeAccessControl_Request::ChangeAccessControl_Request() : scopeOfChange_(), accessControlListName_() {
    };

    ChangeAccessControl_Request::ChangeAccessControl_Request(const ScopeOfChange_type& arg__scopeOfChange,
            const Identifier& arg__accessControlListName) :
    scopeOfChange_(arg__scopeOfChange),
    accessControlListName_(arg__accessControlListName) {
    };

    ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ListOfObjects_type() : objectClass_(), objectScope_() {
    };

    ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ListOfObjects_type(const ObjectClass& arg__objectClass,
            const ObjectScope_type& arg__objectScope) :
    objectClass_(arg__objectClass),
    objectScope_(arg__objectScope) {
    };



    ITU_T_CHOICEC_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::specific, specific, ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::Specific_type, ObjectScope_type_specific);
    ITU_T_CHOICES_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::aa_specific, aa_specific, null_type, ObjectScope_type_aa_specific);
    ITU_T_CHOICES_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::domain, domain, Identifier, ObjectScope_type_domain);
    ITU_T_CHOICES_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::vmd, vmd, null_type, ObjectScope_type_vmd);


    ITU_T_HOLDERH_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::objectClass, objectClass, ObjectClass);
    ITU_T_HOLDERH_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::objectScope, objectScope, ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type);


    ITU_T_CHOICES_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::vMDOnly, vMDOnly, null_type, ScopeOfChange_type_vMDOnly);
    ITU_T_CHOICEC_DEFN(ChangeAccessControl_Request::ScopeOfChange_type::listOfObjects, listOfObjects, ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type, ScopeOfChange_type_listOfObjects);


    ITU_T_HOLDERH_DEFN(ChangeAccessControl_Request::scopeOfChange, scopeOfChange, ChangeAccessControl_Request::ScopeOfChange_type);
    ITU_T_HOLDERH_DEFN(ChangeAccessControl_Request::accessControlListName, accessControlListName, Identifier);

    // sequence ChangeAccessControl-Response

    ChangeAccessControl_Response::ChangeAccessControl_Response() : numberMatched_(), numberChanged_() {
    };

    ChangeAccessControl_Response::ChangeAccessControl_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberChanged) :
    numberMatched_(arg__numberMatched),
    numberChanged_(arg__numberChanged) {
    };


    ITU_T_HOLDERH_DEFN(ChangeAccessControl_Response::numberMatched, numberMatched, Unsigned32);
    ITU_T_HOLDERH_DEFN(ChangeAccessControl_Response::numberChanged, numberChanged, Unsigned32);

    // sequence StatusResponse
    const uint8_t StatusResponse::vmdLogicalStatus_state_changes_allowed = 0;
    const uint8_t StatusResponse::vmdLogicalStatus_no_state_changes_allowed = 1;
    const uint8_t StatusResponse::vmdLogicalStatus_limited_services_permitted = 2;
    const uint8_t StatusResponse::vmdLogicalStatus_support_services_allowed = 3;

    const uint8_t StatusResponse::vmdPhysicalStatus_operational = 0;
    const uint8_t StatusResponse::vmdPhysicalStatus_partially_operational = 1;
    const uint8_t StatusResponse::vmdPhysicalStatus_inoperable = 2;
    const uint8_t StatusResponse::vmdPhysicalStatus_needs_commissioning = 3;

    StatusResponse::StatusResponse() : vmdLogicalStatus_(), vmdPhysicalStatus_() {
    };

    StatusResponse::StatusResponse(const uint8_t& arg__vmdLogicalStatus,
            const uint8_t& arg__vmdPhysicalStatus) :
    vmdLogicalStatus_(arg__vmdLogicalStatus),
    vmdPhysicalStatus_(arg__vmdPhysicalStatus) {
    };

    StatusResponse::StatusResponse(shared_ptr< uint8_t> arg__vmdLogicalStatus,
            shared_ptr< uint8_t> arg__vmdPhysicalStatus,
            shared_ptr< bitstring_type> arg__localDetail) :
    vmdLogicalStatus_(arg__vmdLogicalStatus),
    vmdPhysicalStatus_(arg__vmdPhysicalStatus),
    localDetail_(arg__localDetail) {
    };


    ITU_T_HOLDERH_DEFN(StatusResponse::vmdLogicalStatus, vmdLogicalStatus, uint8_t);
    ITU_T_HOLDERH_DEFN(StatusResponse::vmdPhysicalStatus, vmdPhysicalStatus, uint8_t);
    ITU_T_OPTIONAL_DEFN(StatusResponse::localDetail, localDetail, bitstring_type);

    // choice CS-Status-Response

    CS_Status_Response::FullResponse_type::FullResponse_type() : operationState_(), extendedStatus_(), selectedProgramInvocation_() {
    };

    CS_Status_Response::FullResponse_type::FullResponse_type(const OperationState& arg__operationState,
            const ExtendedStatus& arg__extendedStatus,
            const SelectedProgramInvocation_type& arg__selectedProgramInvocation) :
    operationState_(arg__operationState),
    extendedStatus_(arg__extendedStatus),
    selectedProgramInvocation_(arg__selectedProgramInvocation) {
    };

    CS_Status_Response::FullResponse_type::FullResponse_type(shared_ptr< OperationState> arg__operationState,
            shared_ptr< ExtendedStatus> arg__extendedStatus,
            shared_ptr< ExtendedStatus> arg__extendedStatusMask,
            shared_ptr< SelectedProgramInvocation_type> arg__selectedProgramInvocation) :
    operationState_(arg__operationState),
    extendedStatus_(arg__extendedStatus),
    extendedStatusMask_(arg__extendedStatusMask),
    selectedProgramInvocation_(arg__selectedProgramInvocation) {
    };



    ITU_T_CHOICES_DEFN(CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::programInvocation, programInvocation, Identifier, SelectedProgramInvocation_type_programInvocation);
    ITU_T_CHOICES_DEFN(CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::noneSelected, noneSelected, null_type, SelectedProgramInvocation_type_noneSelected);

    const ExtendedStatus CS_Status_Response::FullResponse_type::extendedStatusMask__default = ExtendedStatus(boost::asn1::bitstring_type(std::string("\xF", 1), 4));


    ITU_T_HOLDERH_DEFN(CS_Status_Response::FullResponse_type::operationState, operationState, OperationState);
    ITU_T_HOLDERH_DEFN(CS_Status_Response::FullResponse_type::extendedStatus, extendedStatus, ExtendedStatus);
    ITU_T_DEFAULTH_DEFN(CS_Status_Response::FullResponse_type::extendedStatusMask, extendedStatusMask, ExtendedStatus);
    ITU_T_HOLDERH_DEFN(CS_Status_Response::FullResponse_type::selectedProgramInvocation, selectedProgramInvocation, CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type);


    ITU_T_CHOICEC_DEFN(CS_Status_Response::fullResponse, fullResponse, CS_Status_Response::FullResponse_type, CS_Status_Response_fullResponse);
    ITU_T_CHOICES_DEFN(CS_Status_Response::noExtraResponse, noExtraResponse, null_type, CS_Status_Response_noExtraResponse);

    // sequence GetNameList-Request

    GetNameList_Request::GetNameList_Request() : objectClass_(), objectScope_() {
    };

    GetNameList_Request::GetNameList_Request(const ObjectClass& arg__objectClass,
            const ObjectScope_type& arg__objectScope) :
    objectClass_(arg__objectClass),
    objectScope_(arg__objectScope) {
    };

    GetNameList_Request::GetNameList_Request(shared_ptr< ObjectClass> arg__objectClass,
            shared_ptr< ObjectScope_type> arg__objectScope,
            shared_ptr< Identifier> arg__continueAfter) :
    objectClass_(arg__objectClass),
    objectScope_(arg__objectScope),
    continueAfter_(arg__continueAfter) {
    };



    ITU_T_CHOICES_DEFN(GetNameList_Request::ObjectScope_type::vmdSpecific, vmdSpecific, null_type, ObjectScope_type_vmdSpecific);
    ITU_T_CHOICES_DEFN(GetNameList_Request::ObjectScope_type::domainSpecific, domainSpecific, Identifier, ObjectScope_type_domainSpecific);
    ITU_T_CHOICES_DEFN(GetNameList_Request::ObjectScope_type::aaSpecific, aaSpecific, null_type, ObjectScope_type_aaSpecific);


    ITU_T_HOLDERH_DEFN(GetNameList_Request::objectClass, objectClass, ObjectClass);
    ITU_T_HOLDERH_DEFN(GetNameList_Request::objectScope, objectScope, GetNameList_Request::ObjectScope_type);
    ITU_T_OPTIONAL_DEFN(GetNameList_Request::continueAfter, continueAfter, Identifier);

    // sequence GetNameList-Response

    GetNameList_Response::GetNameList_Response() : listOfIdentifier_() {
    };

    GetNameList_Response::GetNameList_Response(const ListOfIdentifier_type& arg__listOfIdentifier) :
    listOfIdentifier_(arg__listOfIdentifier) {
    };

    GetNameList_Response::GetNameList_Response(shared_ptr< ListOfIdentifier_type> arg__listOfIdentifier,
            shared_ptr< bool> arg__moreFollows) :
    listOfIdentifier_(arg__listOfIdentifier),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetNameList_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(GetNameList_Response::listOfIdentifier, listOfIdentifier, GetNameList_Response::ListOfIdentifier_type);
    ITU_T_DEFAULTH_DEFN(GetNameList_Response::moreFollows, moreFollows, bool);

    // sequence Identify-Response

    Identify_Response::Identify_Response() : vendorName_(), modelName_(), revision_() {
    };

    Identify_Response::Identify_Response(const MMSString& arg__vendorName,
            const MMSString& arg__modelName,
            const MMSString& arg__revision) :
    vendorName_(arg__vendorName),
    modelName_(arg__modelName),
    revision_(arg__revision) {
    };

    Identify_Response::Identify_Response(shared_ptr< MMSString> arg__vendorName,
            shared_ptr< MMSString> arg__modelName,
            shared_ptr< MMSString> arg__revision,
            shared_ptr< ListOfAbstractSyntaxes_type> arg__listOfAbstractSyntaxes) :
    vendorName_(arg__vendorName),
    modelName_(arg__modelName),
    revision_(arg__revision),
    listOfAbstractSyntaxes_(arg__listOfAbstractSyntaxes) {
    };


    ITU_T_HOLDERH_DEFN(Identify_Response::vendorName, vendorName, MMSString);
    ITU_T_HOLDERH_DEFN(Identify_Response::modelName, modelName, MMSString);
    ITU_T_HOLDERH_DEFN(Identify_Response::revision, revision, MMSString);
    ITU_T_OPTIONAL_DEFN(Identify_Response::listOfAbstractSyntaxes, listOfAbstractSyntaxes, Identify_Response::ListOfAbstractSyntaxes_type);

    // sequence Rename-Request

    Rename_Request::Rename_Request() : objectClass_(), currentName_(), newIdentifier_() {
    };

    Rename_Request::Rename_Request(const ObjectClass& arg__objectClass,
            const ObjectName& arg__currentName,
            const Identifier& arg__newIdentifier) :
    objectClass_(arg__objectClass),
    currentName_(arg__currentName),
    newIdentifier_(arg__newIdentifier) {
    };


    ITU_T_HOLDERH_DEFN(Rename_Request::objectClass, objectClass, ObjectClass);
    ITU_T_HOLDERH_DEFN(Rename_Request::currentName, currentName, ObjectName);
    ITU_T_HOLDERH_DEFN(Rename_Request::newIdentifier, newIdentifier, Identifier);

    // sequence GetCapabilityList-Request

    GetCapabilityList_Request::GetCapabilityList_Request() {
    };

    GetCapabilityList_Request::GetCapabilityList_Request(shared_ptr< MMSString> arg__continueAfter) :
    continueAfter_(arg__continueAfter) {
    };


    ITU_T_OPTIONAL_DEFN(GetCapabilityList_Request::continueAfter, continueAfter, MMSString);

    // sequence GetCapabilityList-Response

    GetCapabilityList_Response::GetCapabilityList_Response() : listOfCapabilities_() {
    };

    GetCapabilityList_Response::GetCapabilityList_Response(const ListOfCapabilities_type& arg__listOfCapabilities) :
    listOfCapabilities_(arg__listOfCapabilities) {
    };

    GetCapabilityList_Response::GetCapabilityList_Response(shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
            shared_ptr< bool> arg__moreFollows) :
    listOfCapabilities_(arg__listOfCapabilities),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetCapabilityList_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(GetCapabilityList_Response::listOfCapabilities, listOfCapabilities, GetCapabilityList_Response::ListOfCapabilities_type);
    ITU_T_DEFAULTH_DEFN(GetCapabilityList_Response::moreFollows, moreFollows, bool);

    // sequence InitiateDownloadSequence-Request

    InitiateDownloadSequence_Request::InitiateDownloadSequence_Request() : domainName_(), listOfCapabilities_(), sharable_() {
    };

    InitiateDownloadSequence_Request::InitiateDownloadSequence_Request(const Identifier& arg__domainName,
            const ListOfCapabilities_type& arg__listOfCapabilities,
            const bool& arg__sharable) :
    domainName_(arg__domainName),
    listOfCapabilities_(arg__listOfCapabilities),
    sharable_(arg__sharable) {
    };


    ITU_T_HOLDERH_DEFN(InitiateDownloadSequence_Request::domainName, domainName, Identifier);
    ITU_T_HOLDERH_DEFN(InitiateDownloadSequence_Request::listOfCapabilities, listOfCapabilities, InitiateDownloadSequence_Request::ListOfCapabilities_type);
    ITU_T_HOLDERH_DEFN(InitiateDownloadSequence_Request::sharable, sharable, bool);

    // sequence DownloadSegment-Response

    DownloadSegment_Response::DownloadSegment_Response() : loadData_() {
    };

    DownloadSegment_Response::DownloadSegment_Response(const LoadData& arg__loadData) :
    loadData_(arg__loadData) {
    };

    DownloadSegment_Response::DownloadSegment_Response(shared_ptr< LoadData> arg__loadData,
            shared_ptr< bool> arg__moreFollows) :
    loadData_(arg__loadData),
    moreFollows_(arg__moreFollows) {
    };

    const bool DownloadSegment_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(DownloadSegment_Response::loadData, loadData, LoadData);
    ITU_T_DEFAULTH_DEFN(DownloadSegment_Response::moreFollows, moreFollows, bool);

    // choice LoadData

    ITU_T_CHOICES_DEFN(LoadData::non_coded, non_coded, octetstring_type, LoadData_non_coded);
    ITU_T_CHOICES_DEFN(LoadData::coded, coded, external_type, LoadData_coded);
    ITU_T_CHOICES_DEFN(LoadData::embedded, embedded, embeded_type, LoadData_embedded);

    // sequence TerminateDownloadSequence-Request

    TerminateDownloadSequence_Request::TerminateDownloadSequence_Request() : domainName_() {
    };

    TerminateDownloadSequence_Request::TerminateDownloadSequence_Request(const Identifier& arg__domainName) :
    domainName_(arg__domainName) {
    };

    TerminateDownloadSequence_Request::TerminateDownloadSequence_Request(shared_ptr< Identifier> arg__domainName,
            shared_ptr< ServiceError> arg__discard) :
    domainName_(arg__domainName),
    discard_(arg__discard) {
    };


    ITU_T_HOLDERH_DEFN(TerminateDownloadSequence_Request::domainName, domainName, Identifier);
    ITU_T_OPTIONAL_DEFN(TerminateDownloadSequence_Request::discard, discard, ServiceError);

    // sequence InitiateUploadSequence-Response

    InitiateUploadSequence_Response::InitiateUploadSequence_Response() : ulsmID_(), listOfCapabilities_() {
    };

    InitiateUploadSequence_Response::InitiateUploadSequence_Response(const Integer32& arg__ulsmID,
            const ListOfCapabilities_type& arg__listOfCapabilities) :
    ulsmID_(arg__ulsmID),
    listOfCapabilities_(arg__listOfCapabilities) {
    };


    ITU_T_HOLDERH_DEFN(InitiateUploadSequence_Response::ulsmID, ulsmID, Integer32);
    ITU_T_HOLDERH_DEFN(InitiateUploadSequence_Response::listOfCapabilities, listOfCapabilities, InitiateUploadSequence_Response::ListOfCapabilities_type);

    // sequence UploadSegment-Response

    UploadSegment_Response::UploadSegment_Response() : loadData_() {
    };

    UploadSegment_Response::UploadSegment_Response(const LoadData& arg__loadData) :
    loadData_(arg__loadData) {
    };

    UploadSegment_Response::UploadSegment_Response(shared_ptr< LoadData> arg__loadData,
            shared_ptr< bool> arg__moreFollows) :
    loadData_(arg__loadData),
    moreFollows_(arg__moreFollows) {
    };

    const bool UploadSegment_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(UploadSegment_Response::loadData, loadData, LoadData);
    ITU_T_DEFAULTH_DEFN(UploadSegment_Response::moreFollows, moreFollows, bool);

    // sequence RequestDomainDownload-Request

    RequestDomainDownload_Request::RequestDomainDownload_Request() : domainName_(), sharable_(), fileName_() {
    };

    RequestDomainDownload_Request::RequestDomainDownload_Request(const Identifier& arg__domainName,
            const bool& arg__sharable,
            const FileName& arg__fileName) :
    domainName_(arg__domainName),
    sharable_(arg__sharable),
    fileName_(arg__fileName) {
    };

    RequestDomainDownload_Request::RequestDomainDownload_Request(shared_ptr< Identifier> arg__domainName,
            shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
            shared_ptr< bool> arg__sharable,
            shared_ptr< FileName> arg__fileName) :
    domainName_(arg__domainName),
    listOfCapabilities_(arg__listOfCapabilities),
    sharable_(arg__sharable),
    fileName_(arg__fileName) {
    };


    ITU_T_HOLDERH_DEFN(RequestDomainDownload_Request::domainName, domainName, Identifier);
    ITU_T_OPTIONAL_DEFN(RequestDomainDownload_Request::listOfCapabilities, listOfCapabilities, RequestDomainDownload_Request::ListOfCapabilities_type);
    ITU_T_HOLDERH_DEFN(RequestDomainDownload_Request::sharable, sharable, bool);
    ITU_T_HOLDERH_DEFN(RequestDomainDownload_Request::fileName, fileName, FileName);

    // sequence RequestDomainUpload-Request

    RequestDomainUpload_Request::RequestDomainUpload_Request() : domainName_(), fileName_() {
    };

    RequestDomainUpload_Request::RequestDomainUpload_Request(const Identifier& arg__domainName,
            const FileName& arg__fileName) :
    domainName_(arg__domainName),
    fileName_(arg__fileName) {
    };


    ITU_T_HOLDERH_DEFN(RequestDomainUpload_Request::domainName, domainName, Identifier);
    ITU_T_HOLDERH_DEFN(RequestDomainUpload_Request::fileName, fileName, FileName);

    // sequence LoadDomainContent-Request

    LoadDomainContent_Request::LoadDomainContent_Request() : domainName_(), sharable_(), fileName_() {
    };

    LoadDomainContent_Request::LoadDomainContent_Request(const Identifier& arg__domainName,
            const bool& arg__sharable,
            const FileName& arg__fileName) :
    domainName_(arg__domainName),
    sharable_(arg__sharable),
    fileName_(arg__fileName) {
    };

    LoadDomainContent_Request::LoadDomainContent_Request(shared_ptr< Identifier> arg__domainName,
            shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
            shared_ptr< bool> arg__sharable,
            shared_ptr< FileName> arg__fileName,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    domainName_(arg__domainName),
    listOfCapabilities_(arg__listOfCapabilities),
    sharable_(arg__sharable),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };


    ITU_T_HOLDERH_DEFN(LoadDomainContent_Request::domainName, domainName, Identifier);
    ITU_T_OPTIONAL_DEFN(LoadDomainContent_Request::listOfCapabilities, listOfCapabilities, LoadDomainContent_Request::ListOfCapabilities_type);
    ITU_T_HOLDERH_DEFN(LoadDomainContent_Request::sharable, sharable, bool);
    ITU_T_HOLDERH_DEFN(LoadDomainContent_Request::fileName, fileName, FileName);
    ITU_T_OPTIONAL_DEFN(LoadDomainContent_Request::thirdParty, thirdParty, MMS_Environment_1::ApplicationReference);

    // sequence StoreDomainContent-Request

    StoreDomainContent_Request::StoreDomainContent_Request() : domainName_(), fileName_() {
    };

    StoreDomainContent_Request::StoreDomainContent_Request(const Identifier& arg__domainName,
            const FileName& arg__fileName) :
    domainName_(arg__domainName),
    fileName_(arg__fileName) {
    };

    StoreDomainContent_Request::StoreDomainContent_Request(shared_ptr< Identifier> arg__domainName,
            shared_ptr< FileName> arg__fileName,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    domainName_(arg__domainName),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };


    ITU_T_HOLDERH_DEFN(StoreDomainContent_Request::domainName, domainName, Identifier);
    ITU_T_HOLDERH_DEFN(StoreDomainContent_Request::fileName, fileName, FileName);
    ITU_T_OPTIONAL_DEFN(StoreDomainContent_Request::thirdParty, thirdParty, MMS_Environment_1::ApplicationReference);

    // sequence GetDomainAttributes-Response

    GetDomainAttributes_Response::GetDomainAttributes_Response() : listOfCapabilities_(), state_(), mmsDeletable_(), sharable_(), listOfProgramInvocations_(), uploadInProgress_() {
    };

    GetDomainAttributes_Response::GetDomainAttributes_Response(const ListOfCapabilities_type& arg__listOfCapabilities,
            const MMS_Object_Module_1::DomainState& arg__state,
            const bool& arg__mmsDeletable,
            const bool& arg__sharable,
            const ListOfProgramInvocations_type& arg__listOfProgramInvocations,
            const Integer8& arg__uploadInProgress) :
    listOfCapabilities_(arg__listOfCapabilities),
    state_(arg__state),
    mmsDeletable_(arg__mmsDeletable),
    sharable_(arg__sharable),
    listOfProgramInvocations_(arg__listOfProgramInvocations),
    uploadInProgress_(arg__uploadInProgress) {
    };

    GetDomainAttributes_Response::GetDomainAttributes_Response(shared_ptr< ListOfCapabilities_type> arg__listOfCapabilities,
            shared_ptr< MMS_Object_Module_1::DomainState> arg__state,
            shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< bool> arg__sharable,
            shared_ptr< ListOfProgramInvocations_type> arg__listOfProgramInvocations,
            shared_ptr< Integer8> arg__uploadInProgress,
            shared_ptr< Identifier> arg__accessControlList) :
    listOfCapabilities_(arg__listOfCapabilities),
    state_(arg__state),
    mmsDeletable_(arg__mmsDeletable),
    sharable_(arg__sharable),
    listOfProgramInvocations_(arg__listOfProgramInvocations),
    uploadInProgress_(arg__uploadInProgress),
    accessControlList_(arg__accessControlList) {
    };


    ITU_T_HOLDERH_DEFN(GetDomainAttributes_Response::listOfCapabilities, listOfCapabilities, GetDomainAttributes_Response::ListOfCapabilities_type);
    ITU_T_HOLDERH_DEFN(GetDomainAttributes_Response::state, state, MMS_Object_Module_1::DomainState);
    ITU_T_HOLDERH_DEFN(GetDomainAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetDomainAttributes_Response::sharable, sharable, bool);
    ITU_T_HOLDERH_DEFN(GetDomainAttributes_Response::listOfProgramInvocations, listOfProgramInvocations, GetDomainAttributes_Response::ListOfProgramInvocations_type);
    ITU_T_HOLDERH_DEFN(GetDomainAttributes_Response::uploadInProgress, uploadInProgress, Integer8);
    ITU_T_OPTIONAL_DEFN(GetDomainAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence CreateProgramInvocation-Request

    CreateProgramInvocation_Request::CreateProgramInvocation_Request() : programInvocationName_(), listOfDomainNames_() {
    };

    CreateProgramInvocation_Request::CreateProgramInvocation_Request(const Identifier& arg__programInvocationName,
            const ListOfDomainNames_type& arg__listOfDomainNames) :
    programInvocationName_(arg__programInvocationName),
    listOfDomainNames_(arg__listOfDomainNames) {
    };

    CreateProgramInvocation_Request::CreateProgramInvocation_Request(shared_ptr< Identifier> arg__programInvocationName,
            shared_ptr< ListOfDomainNames_type> arg__listOfDomainNames,
            shared_ptr< bool> arg__reusable,
            shared_ptr< bool> arg__monitorType) :
    programInvocationName_(arg__programInvocationName),
    listOfDomainNames_(arg__listOfDomainNames),
    reusable_(arg__reusable),
    monitorType_(arg__monitorType) {
    };

    const bool CreateProgramInvocation_Request::reusable__default = true;


    ITU_T_HOLDERH_DEFN(CreateProgramInvocation_Request::programInvocationName, programInvocationName, Identifier);
    ITU_T_HOLDERH_DEFN(CreateProgramInvocation_Request::listOfDomainNames, listOfDomainNames, CreateProgramInvocation_Request::ListOfDomainNames_type);
    ITU_T_DEFAULTH_DEFN(CreateProgramInvocation_Request::reusable, reusable, bool);
    ITU_T_OPTIONAL_DEFN(CreateProgramInvocation_Request::monitorType, monitorType, bool);

    // sequence Start-Request

    Start_Request::Start_Request() : programInvocationName_() {
    };

    Start_Request::Start_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    Start_Request::Start_Request(shared_ptr< Identifier> arg__programInvocationName,
            shared_ptr< ExecutionArgument_type> arg__executionArgument) :
    programInvocationName_(arg__programInvocationName),
    executionArgument_(arg__executionArgument) {
    };



    ITU_T_CHOICES_DEFN(Start_Request::ExecutionArgument_type::simpleString, simpleString, MMSString, ExecutionArgument_type_simpleString);
    ITU_T_CHOICES_DEFN(Start_Request::ExecutionArgument_type::encodedString, encodedString, external_type, ExecutionArgument_type_encodedString);
    ITU_T_CHOICES_DEFN(Start_Request::ExecutionArgument_type::embeddedString, embeddedString, embeded_type, ExecutionArgument_type_embeddedString);


    ITU_T_HOLDERH_DEFN(Start_Request::programInvocationName, programInvocationName, Identifier);
    ITU_T_OPTIONAL_DEFN(Start_Request::executionArgument, executionArgument, Start_Request::ExecutionArgument_type);

    // choice CS-Start-Request

    CS_Start_Request_impl::Controlling_type::Controlling_type() {
    };

    CS_Start_Request_impl::Controlling_type::Controlling_type(shared_ptr< visiblestring_type> arg__startLocation,
            shared_ptr< StartCount> arg__startCount) :
    startLocation_(arg__startLocation),
    startCount_(arg__startCount) {
    };


    ITU_T_OPTIONAL_DEFN(CS_Start_Request_impl::Controlling_type::startLocation, startLocation, visiblestring_type);
    ITU_T_OPTIONAL_DEFN(CS_Start_Request_impl::Controlling_type::startCount, startCount, StartCount);


    ITU_T_CHOICES_DEFN(CS_Start_Request_impl::normal, normal, null_type, CS_Start_Request_impl_normal);
    ITU_T_CHOICEC_DEFN(CS_Start_Request_impl::controlling, controlling, CS_Start_Request_impl::Controlling_type, CS_Start_Request_impl_controlling);

    // choice StartCount

    ITU_T_CHOICES_DEFN(StartCount::noLimit, noLimit, null_type, StartCount_noLimit);
    ITU_T_CHOICES_DEFN(StartCount::cycleCount, cycleCount, int, StartCount_cycleCount);
    ITU_T_CHOICES_DEFN(StartCount::stepCount, stepCount, int, StartCount_stepCount);

    // sequence Stop-Request

    Stop_Request::Stop_Request() : programInvocationName_() {
    };

    Stop_Request::Stop_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };


    ITU_T_HOLDERH_DEFN(Stop_Request::programInvocationName, programInvocationName, Identifier);

    // sequence Resume-Request

    Resume_Request::Resume_Request() : programInvocationName_() {
    };

    Resume_Request::Resume_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    Resume_Request::Resume_Request(shared_ptr< Identifier> arg__programInvocationName,
            shared_ptr< ExecutionArgument_type> arg__executionArgument) :
    programInvocationName_(arg__programInvocationName),
    executionArgument_(arg__executionArgument) {
    };



    ITU_T_CHOICES_DEFN(Resume_Request::ExecutionArgument_type::simpleString, simpleString, MMSString, ExecutionArgument_type_simpleString);
    ITU_T_CHOICES_DEFN(Resume_Request::ExecutionArgument_type::encodedString, encodedString, external_type, ExecutionArgument_type_encodedString);
    ITU_T_CHOICES_DEFN(Resume_Request::ExecutionArgument_type::enmbeddedString, enmbeddedString, embeded_type, ExecutionArgument_type_enmbeddedString);


    ITU_T_HOLDERH_DEFN(Resume_Request::programInvocationName, programInvocationName, Identifier);
    ITU_T_OPTIONAL_DEFN(Resume_Request::executionArgument, executionArgument, Resume_Request::ExecutionArgument_type);

    // choice CS-Resume-Request

    CS_Resume_Request_impl::Controlling_type::Controlling_type() : modeType_() {
    };

    CS_Resume_Request_impl::Controlling_type::Controlling_type(const ModeType_type& arg__modeType) :
    modeType_(arg__modeType) {
    };



    ITU_T_CHOICES_DEFN(CS_Resume_Request_impl::Controlling_type::ModeType_type::continueMode, continueMode, null_type, ModeType_type_continueMode);
    ITU_T_CHOICEC_DEFN(CS_Resume_Request_impl::Controlling_type::ModeType_type::changeMode, changeMode, StartCount, ModeType_type_changeMode);


    ITU_T_HOLDERH_DEFN(CS_Resume_Request_impl::Controlling_type::modeType, modeType, CS_Resume_Request_impl::Controlling_type::ModeType_type);


    ITU_T_CHOICES_DEFN(CS_Resume_Request_impl::normal, normal, null_type, CS_Resume_Request_impl_normal);
    ITU_T_CHOICEC_DEFN(CS_Resume_Request_impl::controlling, controlling, CS_Resume_Request_impl::Controlling_type, CS_Resume_Request_impl_controlling);

    // sequence Reset-Request

    Reset_Request::Reset_Request() : programInvocationName_() {
    };

    Reset_Request::Reset_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };


    ITU_T_HOLDERH_DEFN(Reset_Request::programInvocationName, programInvocationName, Identifier);

    // sequence Kill-Request

    Kill_Request::Kill_Request() : programInvocationName_() {
    };

    Kill_Request::Kill_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };


    ITU_T_HOLDERH_DEFN(Kill_Request::programInvocationName, programInvocationName, Identifier);

    // sequence GetProgramInvocationAttributes-Response

    GetProgramInvocationAttributes_Response::GetProgramInvocationAttributes_Response() : state_(), listOfDomainNames_(), mmsDeletable_(), reusable_(), monitor_(), executionArgument_() {
    };

    GetProgramInvocationAttributes_Response::GetProgramInvocationAttributes_Response(const MMS_Object_Module_1::ProgramInvocationState& arg__state,
            const ListOfDomainNames_type& arg__listOfDomainNames,
            const bool& arg__mmsDeletable,
            const bool& arg__reusable,
            const bool& arg__monitor,
            const ExecutionArgument_type& arg__executionArgument) :
    state_(arg__state),
    listOfDomainNames_(arg__listOfDomainNames),
    mmsDeletable_(arg__mmsDeletable),
    reusable_(arg__reusable),
    monitor_(arg__monitor),
    executionArgument_(arg__executionArgument) {
    };

    GetProgramInvocationAttributes_Response::GetProgramInvocationAttributes_Response(shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__state,
            shared_ptr< ListOfDomainNames_type> arg__listOfDomainNames,
            shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< bool> arg__reusable,
            shared_ptr< bool> arg__monitor,
            shared_ptr< ExecutionArgument_type> arg__executionArgument,
            shared_ptr< Identifier> arg__accessControlList) :
    state_(arg__state),
    listOfDomainNames_(arg__listOfDomainNames),
    mmsDeletable_(arg__mmsDeletable),
    reusable_(arg__reusable),
    monitor_(arg__monitor),
    executionArgument_(arg__executionArgument),
    accessControlList_(arg__accessControlList) {
    };



    ITU_T_CHOICES_DEFN(GetProgramInvocationAttributes_Response::ExecutionArgument_type::simpleString, simpleString, MMSString, ExecutionArgument_type_simpleString);
    ITU_T_CHOICES_DEFN(GetProgramInvocationAttributes_Response::ExecutionArgument_type::encodedString, encodedString, external_type, ExecutionArgument_type_encodedString);
    ITU_T_CHOICES_DEFN(GetProgramInvocationAttributes_Response::ExecutionArgument_type::enmbeddedString, enmbeddedString, embeded_type, ExecutionArgument_type_enmbeddedString);


    ITU_T_HOLDERH_DEFN(GetProgramInvocationAttributes_Response::state, state, MMS_Object_Module_1::ProgramInvocationState);
    ITU_T_HOLDERH_DEFN(GetProgramInvocationAttributes_Response::listOfDomainNames, listOfDomainNames, GetProgramInvocationAttributes_Response::ListOfDomainNames_type);
    ITU_T_HOLDERH_DEFN(GetProgramInvocationAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetProgramInvocationAttributes_Response::reusable, reusable, bool);
    ITU_T_HOLDERH_DEFN(GetProgramInvocationAttributes_Response::monitor, monitor, bool);
    ITU_T_HOLDERH_DEFN(GetProgramInvocationAttributes_Response::executionArgument, executionArgument, GetProgramInvocationAttributes_Response::ExecutionArgument_type);
    ITU_T_OPTIONAL_DEFN(GetProgramInvocationAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence CS-GetProgramInvocationAttributes-Response

    CS_GetProgramInvocationAttributes_Response::CS_GetProgramInvocationAttributes_Response() : errorCode_(), control_() {
    };

    CS_GetProgramInvocationAttributes_Response::CS_GetProgramInvocationAttributes_Response(const int& arg__errorCode,
            const Control_type& arg__control) :
    errorCode_(arg__errorCode),
    control_(arg__control) {
    };

    CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::Controlling_type() : controlledPI_(), runningMode_() {
    };

    CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::Controlling_type(const ControlledPI_type& arg__controlledPI,
            const RunningMode_type& arg__runningMode) :
    controlledPI_(arg__controlledPI),
    runningMode_(arg__runningMode) {
    };

    CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::Controlling_type(shared_ptr< ControlledPI_type> arg__controlledPI,
            shared_ptr< visiblestring_type> arg__programLocation,
            shared_ptr< RunningMode_type> arg__runningMode) :
    controlledPI_(arg__controlledPI),
    programLocation_(arg__programLocation),
    runningMode_(arg__runningMode) {
    };



    ITU_T_CHOICES_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::freeRunning, freeRunning, null_type, RunningMode_type_freeRunning);
    ITU_T_CHOICES_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::cycleLimited, cycleLimited, int, RunningMode_type_cycleLimited);
    ITU_T_CHOICES_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::stepLimited, stepLimited, int, RunningMode_type_stepLimited);


    ITU_T_HOLDERH_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::controlledPI, controlledPI, CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::ControlledPI_type);
    ITU_T_OPTIONAL_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::programLocation, programLocation, visiblestring_type);
    ITU_T_HOLDERH_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::runningMode, runningMode, CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type);



    ITU_T_CHOICES_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::controllingPI, controllingPI, Identifier, Controlled_type_controllingPI);
    ITU_T_CHOICES_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::none, none, null_type, Controlled_type_none);


    ITU_T_CHOICEC_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::controlling, controlling, CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type, Control_type_controlling);
    ITU_T_CHOICEC_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::controlled, controlled, CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type, Control_type_controlled);
    ITU_T_CHOICES_DEFN(CS_GetProgramInvocationAttributes_Response::Control_type::normal, normal, null_type, Control_type_normal);


    ITU_T_HOLDERH_DEFN(CS_GetProgramInvocationAttributes_Response::errorCode, errorCode, int);
    ITU_T_HOLDERH_DEFN(CS_GetProgramInvocationAttributes_Response::control, control, CS_GetProgramInvocationAttributes_Response::Control_type);

    // sequence Select-Request

    Select_Request::Select_Request() {
    };

    Select_Request::Select_Request(shared_ptr< Identifier> arg__controlling,
            shared_ptr< Controlled_type> arg__controlled) :
    controlling_(arg__controlling),
    controlled_(arg__controlled) {
    };


    ITU_T_OPTIONAL_DEFN(Select_Request::controlling, controlling, Identifier);
    ITU_T_OPTIONAL_DEFN(Select_Request::controlled, controlled, Select_Request::Controlled_type);

    // sequence AlterProgramInvocationAttributes-Request

    AlterProgramInvocationAttributes_Request::AlterProgramInvocationAttributes_Request() : programInvocation_() {
    };

    AlterProgramInvocationAttributes_Request::AlterProgramInvocationAttributes_Request(const Identifier& arg__programInvocation) :
    programInvocation_(arg__programInvocation) {
    };

    AlterProgramInvocationAttributes_Request::AlterProgramInvocationAttributes_Request(shared_ptr< Identifier> arg__programInvocation,
            shared_ptr< StartCount> arg__startCount) :
    programInvocation_(arg__programInvocation),
    startCount_(arg__startCount) {
    };


    ITU_T_HOLDERH_DEFN(AlterProgramInvocationAttributes_Request::programInvocation, programInvocation, Identifier);
    ITU_T_OPTIONAL_DEFN(AlterProgramInvocationAttributes_Request::startCount, startCount, StartCount);

    // sequence ReconfigureProgramInvocation-Request

    ReconfigureProgramInvocation_Request::ReconfigureProgramInvocation_Request() : oldProgramInvocationName_(), domainsToAdd_(), domainsToRemove_() {
    };

    ReconfigureProgramInvocation_Request::ReconfigureProgramInvocation_Request(const Identifier& arg__oldProgramInvocationName,
            const DomainsToAdd_type& arg__domainsToAdd,
            const DomainsToRemove_type& arg__domainsToRemove) :
    oldProgramInvocationName_(arg__oldProgramInvocationName),
    domainsToAdd_(arg__domainsToAdd),
    domainsToRemove_(arg__domainsToRemove) {
    };

    ReconfigureProgramInvocation_Request::ReconfigureProgramInvocation_Request(shared_ptr< Identifier> arg__oldProgramInvocationName,
            shared_ptr< Identifier> arg__newProgramInvocationName,
            shared_ptr< DomainsToAdd_type> arg__domainsToAdd,
            shared_ptr< DomainsToRemove_type> arg__domainsToRemove) :
    oldProgramInvocationName_(arg__oldProgramInvocationName),
    newProgramInvocationName_(arg__newProgramInvocationName),
    domainsToAdd_(arg__domainsToAdd),
    domainsToRemove_(arg__domainsToRemove) {
    };


    ITU_T_HOLDERH_DEFN(ReconfigureProgramInvocation_Request::oldProgramInvocationName, oldProgramInvocationName, Identifier);
    ITU_T_OPTIONAL_DEFN(ReconfigureProgramInvocation_Request::newProgramInvocationName, newProgramInvocationName, Identifier);
    ITU_T_HOLDERH_DEFN(ReconfigureProgramInvocation_Request::domainsToAdd, domainsToAdd, ReconfigureProgramInvocation_Request::DomainsToAdd_type);
    ITU_T_HOLDERH_DEFN(ReconfigureProgramInvocation_Request::domainsToRemove, domainsToRemove, ReconfigureProgramInvocation_Request::DomainsToRemove_type);

    // choice ControlElement

    ControlElement::BeginDomainDef_type::BeginDomainDef_type() : domainName_(), capabilities_(), sharable_() {
    };

    ControlElement::BeginDomainDef_type::BeginDomainDef_type(const Identifier& arg__domainName,
            const Capabilities_type& arg__capabilities,
            const bool& arg__sharable) :
    domainName_(arg__domainName),
    capabilities_(arg__capabilities),
    sharable_(arg__sharable) {
    };

    ControlElement::BeginDomainDef_type::BeginDomainDef_type(shared_ptr< Identifier> arg__domainName,
            shared_ptr< Capabilities_type> arg__capabilities,
            shared_ptr< bool> arg__sharable,
            shared_ptr< LoadData> arg__loadData) :
    domainName_(arg__domainName),
    capabilities_(arg__capabilities),
    sharable_(arg__sharable),
    loadData_(arg__loadData) {
    };


    ITU_T_HOLDERH_DEFN(ControlElement::BeginDomainDef_type::domainName, domainName, Identifier);
    ITU_T_HOLDERH_DEFN(ControlElement::BeginDomainDef_type::capabilities, capabilities, ControlElement::BeginDomainDef_type::Capabilities_type);
    ITU_T_HOLDERH_DEFN(ControlElement::BeginDomainDef_type::sharable, sharable, bool);
    ITU_T_OPTIONAL_DEFN(ControlElement::BeginDomainDef_type::loadData, loadData, LoadData);

    ControlElement::ContinueDomainDef_type::ContinueDomainDef_type() : domainName_(), loadData_() {
    };

    ControlElement::ContinueDomainDef_type::ContinueDomainDef_type(const Identifier& arg__domainName,
            const LoadData& arg__loadData) :
    domainName_(arg__domainName),
    loadData_(arg__loadData) {
    };


    ITU_T_HOLDERH_DEFN(ControlElement::ContinueDomainDef_type::domainName, domainName, Identifier);
    ITU_T_HOLDERH_DEFN(ControlElement::ContinueDomainDef_type::loadData, loadData, LoadData);

    ControlElement::PiDefinition_type::PiDefinition_type() : piName_(), listOfDomains_() {
    };

    ControlElement::PiDefinition_type::PiDefinition_type(const Identifier& arg__piName,
            const ListOfDomains_type& arg__listOfDomains) :
    piName_(arg__piName),
    listOfDomains_(arg__listOfDomains) {
    };

    ControlElement::PiDefinition_type::PiDefinition_type(shared_ptr< Identifier> arg__piName,
            shared_ptr< ListOfDomains_type> arg__listOfDomains,
            shared_ptr< bool> arg__reusable,
            shared_ptr< bool> arg__monitorType,
            shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__pIState) :
    piName_(arg__piName),
    listOfDomains_(arg__listOfDomains),
    reusable_(arg__reusable),
    monitorType_(arg__monitorType),
    pIState_(arg__pIState) {
    };

    const bool ControlElement::PiDefinition_type::reusable__default = true;


    ITU_T_HOLDERH_DEFN(ControlElement::PiDefinition_type::piName, piName, Identifier);
    ITU_T_HOLDERH_DEFN(ControlElement::PiDefinition_type::listOfDomains, listOfDomains, ControlElement::PiDefinition_type::ListOfDomains_type);
    ITU_T_DEFAULTH_DEFN(ControlElement::PiDefinition_type::reusable, reusable, bool);
    ITU_T_OPTIONAL_DEFN(ControlElement::PiDefinition_type::monitorType, monitorType, bool);
    ITU_T_OPTIONAL_DEFN(ControlElement::PiDefinition_type::pIState, pIState, MMS_Object_Module_1::ProgramInvocationState);


    ITU_T_CHOICEC_DEFN(ControlElement::beginDomainDef, beginDomainDef, ControlElement::BeginDomainDef_type, ControlElement_beginDomainDef);
    ITU_T_CHOICEC_DEFN(ControlElement::continueDomainDef, continueDomainDef, ControlElement::ContinueDomainDef_type, ControlElement_continueDomainDef);
    ITU_T_CHOICES_DEFN(ControlElement::endDomainDef, endDomainDef, Identifier, ControlElement_endDomainDef);
    ITU_T_CHOICEC_DEFN(ControlElement::piDefinition, piDefinition, ControlElement::PiDefinition_type, ControlElement_piDefinition);

    // choice InitiateUnitControl-Error

    ITU_T_CHOICES_DEFN(InitiateUnitControl_Error::domain, domain, Identifier, InitiateUnitControl_Error_domain);
    ITU_T_CHOICES_DEFN(InitiateUnitControl_Error::programInvocation, programInvocation, Identifier, InitiateUnitControl_Error_programInvocation);

    // sequence UnitControlLoadSegment-Response

    UnitControlLoadSegment_Response::UnitControlLoadSegment_Response() : controlElements_() {
    };

    UnitControlLoadSegment_Response::UnitControlLoadSegment_Response(const ControlElements_type& arg__controlElements) :
    controlElements_(arg__controlElements) {
    };

    UnitControlLoadSegment_Response::UnitControlLoadSegment_Response(shared_ptr< ControlElements_type> arg__controlElements,
            shared_ptr< bool> arg__moreFollows) :
    controlElements_(arg__controlElements),
    moreFollows_(arg__moreFollows) {
    };

    const bool UnitControlLoadSegment_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(UnitControlLoadSegment_Response::controlElements, controlElements, UnitControlLoadSegment_Response::ControlElements_type);
    ITU_T_DEFAULTH_DEFN(UnitControlLoadSegment_Response::moreFollows, moreFollows, bool);

    // sequence UnitControlUpload-Request

    UnitControlUpload_Request::UnitControlUpload_Request() : unitControlName_() {
    };

    UnitControlUpload_Request::UnitControlUpload_Request(const Identifier& arg__unitControlName) :
    unitControlName_(arg__unitControlName) {
    };

    UnitControlUpload_Request::UnitControlUpload_Request(shared_ptr< Identifier> arg__unitControlName,
            shared_ptr< ContinueAfter_type> arg__continueAfter) :
    unitControlName_(arg__unitControlName),
    continueAfter_(arg__continueAfter) {
    };



    ITU_T_CHOICES_DEFN(UnitControlUpload_Request::ContinueAfter_type::domain, domain, Identifier, ContinueAfter_type_domain);
    ITU_T_CHOICES_DEFN(UnitControlUpload_Request::ContinueAfter_type::ulsmID, ulsmID, int, ContinueAfter_type_ulsmID);
    ITU_T_CHOICES_DEFN(UnitControlUpload_Request::ContinueAfter_type::programInvocation, programInvocation, Identifier, ContinueAfter_type_programInvocation);


    ITU_T_HOLDERH_DEFN(UnitControlUpload_Request::unitControlName, unitControlName, Identifier);
    ITU_T_OPTIONAL_DEFN(UnitControlUpload_Request::continueAfter, continueAfter, UnitControlUpload_Request::ContinueAfter_type);

    // sequence UnitControlUpload-Response

    UnitControlUpload_Response::UnitControlUpload_Response() : controlElements_() {
    };

    UnitControlUpload_Response::UnitControlUpload_Response(const ControlElements_type& arg__controlElements) :
    controlElements_(arg__controlElements) {
    };

    UnitControlUpload_Response::UnitControlUpload_Response(shared_ptr< ControlElements_type> arg__controlElements,
            shared_ptr< NextElement_type> arg__nextElement) :
    controlElements_(arg__controlElements),
    nextElement_(arg__nextElement) {
    };



    ITU_T_CHOICES_DEFN(UnitControlUpload_Response::NextElement_type::domain, domain, Identifier, NextElement_type_domain);
    ITU_T_CHOICES_DEFN(UnitControlUpload_Response::NextElement_type::ulsmID, ulsmID, int, NextElement_type_ulsmID);
    ITU_T_CHOICES_DEFN(UnitControlUpload_Response::NextElement_type::programInvocation, programInvocation, Identifier, NextElement_type_programInvocation);


    ITU_T_HOLDERH_DEFN(UnitControlUpload_Response::controlElements, controlElements, UnitControlUpload_Response::ControlElements_type);
    ITU_T_OPTIONAL_DEFN(UnitControlUpload_Response::nextElement, nextElement, UnitControlUpload_Response::NextElement_type);

    // sequence StartUnitControl-Request

    StartUnitControl_Request::StartUnitControl_Request() : unitControlName_() {
    };

    StartUnitControl_Request::StartUnitControl_Request(const Identifier& arg__unitControlName) :
    unitControlName_(arg__unitControlName) {
    };

    StartUnitControl_Request::StartUnitControl_Request(shared_ptr< Identifier> arg__unitControlName,
            shared_ptr< ExecutionArgument_type> arg__executionArgument) :
    unitControlName_(arg__unitControlName),
    executionArgument_(arg__executionArgument) {
    };



    ITU_T_CHOICES_DEFN(StartUnitControl_Request::ExecutionArgument_type::simpleString, simpleString, MMSString, ExecutionArgument_type_simpleString);
    ITU_T_CHOICES_DEFN(StartUnitControl_Request::ExecutionArgument_type::encodedString, encodedString, external_type, ExecutionArgument_type_encodedString);
    ITU_T_CHOICES_DEFN(StartUnitControl_Request::ExecutionArgument_type::enmbeddedString, enmbeddedString, embeded_type, ExecutionArgument_type_enmbeddedString);


    ITU_T_HOLDERH_DEFN(StartUnitControl_Request::unitControlName, unitControlName, Identifier);
    ITU_T_OPTIONAL_DEFN(StartUnitControl_Request::executionArgument, executionArgument, StartUnitControl_Request::ExecutionArgument_type);

    // sequence StartUnitControl-Error

    StartUnitControl_Error::StartUnitControl_Error() : programInvocationName_(), programInvocationState_() {
    };

    StartUnitControl_Error::StartUnitControl_Error(const Identifier& arg__programInvocationName,
            const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState) :
    programInvocationName_(arg__programInvocationName),
    programInvocationState_(arg__programInvocationState) {
    };


    ITU_T_HOLDERH_DEFN(StartUnitControl_Error::programInvocationName, programInvocationName, Identifier);
    ITU_T_HOLDERH_DEFN(StartUnitControl_Error::programInvocationState, programInvocationState, MMS_Object_Module_1::ProgramInvocationState);

    // sequence StopUnitControl-Error

    StopUnitControl_Error::StopUnitControl_Error() : programInvocationName_(), programInvocationState_() {
    };

    StopUnitControl_Error::StopUnitControl_Error(const Identifier& arg__programInvocationName,
            const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState) :
    programInvocationName_(arg__programInvocationName),
    programInvocationState_(arg__programInvocationState) {
    };


    ITU_T_HOLDERH_DEFN(StopUnitControl_Error::programInvocationName, programInvocationName, Identifier);
    ITU_T_HOLDERH_DEFN(StopUnitControl_Error::programInvocationState, programInvocationState, MMS_Object_Module_1::ProgramInvocationState);

    // sequence CreateUnitControl-Request

    CreateUnitControl_Request::CreateUnitControl_Request() : unitControl_(), domains_(), programInvocations_() {
    };

    CreateUnitControl_Request::CreateUnitControl_Request(const Identifier& arg__unitControl,
            const Domains_type& arg__domains,
            const ProgramInvocations_type& arg__programInvocations) :
    unitControl_(arg__unitControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };


    ITU_T_HOLDERH_DEFN(CreateUnitControl_Request::unitControl, unitControl, Identifier);
    ITU_T_HOLDERH_DEFN(CreateUnitControl_Request::domains, domains, CreateUnitControl_Request::Domains_type);
    ITU_T_HOLDERH_DEFN(CreateUnitControl_Request::programInvocations, programInvocations, CreateUnitControl_Request::ProgramInvocations_type);

    // sequence AddToUnitControl-Request

    AddToUnitControl_Request::AddToUnitControl_Request() : unitControl_(), domains_(), programInvocations_() {
    };

    AddToUnitControl_Request::AddToUnitControl_Request(const Identifier& arg__unitControl,
            const Domains_type& arg__domains,
            const ProgramInvocations_type& arg__programInvocations) :
    unitControl_(arg__unitControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };


    ITU_T_HOLDERH_DEFN(AddToUnitControl_Request::unitControl, unitControl, Identifier);
    ITU_T_HOLDERH_DEFN(AddToUnitControl_Request::domains, domains, AddToUnitControl_Request::Domains_type);
    ITU_T_HOLDERH_DEFN(AddToUnitControl_Request::programInvocations, programInvocations, AddToUnitControl_Request::ProgramInvocations_type);

    // sequence RemoveFromUnitControl-Request

    RemoveFromUnitControl_Request::RemoveFromUnitControl_Request() : unitControl_(), domains_(), programInvocations_() {
    };

    RemoveFromUnitControl_Request::RemoveFromUnitControl_Request(const Identifier& arg__unitControl,
            const Domains_type& arg__domains,
            const ProgramInvocations_type& arg__programInvocations) :
    unitControl_(arg__unitControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };


    ITU_T_HOLDERH_DEFN(RemoveFromUnitControl_Request::unitControl, unitControl, Identifier);
    ITU_T_HOLDERH_DEFN(RemoveFromUnitControl_Request::domains, domains, RemoveFromUnitControl_Request::Domains_type);
    ITU_T_HOLDERH_DEFN(RemoveFromUnitControl_Request::programInvocations, programInvocations, RemoveFromUnitControl_Request::ProgramInvocations_type);

    // sequence GetUnitControlAttributes-Response

    GetUnitControlAttributes_Response::GetUnitControlAttributes_Response() : domains_(), programInvocations_() {
    };

    GetUnitControlAttributes_Response::GetUnitControlAttributes_Response(const Domains_type& arg__domains,
            const ProgramInvocations_type& arg__programInvocations) :
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };


    ITU_T_HOLDERH_DEFN(GetUnitControlAttributes_Response::domains, domains, GetUnitControlAttributes_Response::Domains_type);
    ITU_T_HOLDERH_DEFN(GetUnitControlAttributes_Response::programInvocations, programInvocations, GetUnitControlAttributes_Response::ProgramInvocations_type);

    // sequence LoadUnitControlFromFile-Request

    LoadUnitControlFromFile_Request::LoadUnitControlFromFile_Request() : unitControlName_(), fileName_() {
    };

    LoadUnitControlFromFile_Request::LoadUnitControlFromFile_Request(const Identifier& arg__unitControlName,
            const FileName& arg__fileName) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName) {
    };

    LoadUnitControlFromFile_Request::LoadUnitControlFromFile_Request(shared_ptr< Identifier> arg__unitControlName,
            shared_ptr< FileName> arg__fileName,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };


    ITU_T_HOLDERH_DEFN(LoadUnitControlFromFile_Request::unitControlName, unitControlName, Identifier);
    ITU_T_HOLDERH_DEFN(LoadUnitControlFromFile_Request::fileName, fileName, FileName);
    ITU_T_OPTIONAL_DEFN(LoadUnitControlFromFile_Request::thirdParty, thirdParty, MMS_Environment_1::ApplicationReference);

    // choice LoadUnitControlFromFile-Error

    ITU_T_CHOICES_DEFN(LoadUnitControlFromFile_Error::none, none, null_type, LoadUnitControlFromFile_Error_none);
    ITU_T_CHOICES_DEFN(LoadUnitControlFromFile_Error::domain, domain, Identifier, LoadUnitControlFromFile_Error_domain);
    ITU_T_CHOICES_DEFN(LoadUnitControlFromFile_Error::programInvocation, programInvocation, Identifier, LoadUnitControlFromFile_Error_programInvocation);

    // sequence StoreUnitControlToFile-Request

    StoreUnitControlToFile_Request::StoreUnitControlToFile_Request() : unitControlName_(), fileName_() {
    };

    StoreUnitControlToFile_Request::StoreUnitControlToFile_Request(const Identifier& arg__unitControlName,
            const FileName& arg__fileName) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName) {
    };

    StoreUnitControlToFile_Request::StoreUnitControlToFile_Request(shared_ptr< Identifier> arg__unitControlName,
            shared_ptr< FileName> arg__fileName,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };


    ITU_T_HOLDERH_DEFN(StoreUnitControlToFile_Request::unitControlName, unitControlName, Identifier);
    ITU_T_HOLDERH_DEFN(StoreUnitControlToFile_Request::fileName, fileName, FileName);
    ITU_T_OPTIONAL_DEFN(StoreUnitControlToFile_Request::thirdParty, thirdParty, MMS_Environment_1::ApplicationReference);

    // choice DeleteUnitControl-Error

    ITU_T_CHOICES_DEFN(DeleteUnitControl_Error::domain, domain, Identifier, DeleteUnitControl_Error_domain);
    ITU_T_CHOICES_DEFN(DeleteUnitControl_Error::programInvocation, programInvocation, Identifier, DeleteUnitControl_Error_programInvocation);

    // choice TypeSpecification

    ITU_T_CHOICEC_DEFN(TypeSpecification::typeName, typeName, ObjectName, TypeSpecification_typeName);
    ITU_T_CHOICEC_DEFN(TypeSpecification::typeDescription, typeDescription, MMS_Object_Module_1::TypeDescription, TypeSpecification_typeDescription);

    AlternateAccess_sequence_of::Named_type::Named_type() : componentName_(), access_() {
    };

    AlternateAccess_sequence_of::Named_type::Named_type(const Identifier& arg__componentName,
            const AlternateAccessSelection& arg__access) :
    componentName_(arg__componentName),
    access_(arg__access) {
    };


    ITU_T_HOLDERH_DEFN(AlternateAccess_sequence_of::Named_type::componentName, componentName, Identifier);
    ITU_T_HOLDERH_DEFN(AlternateAccess_sequence_of::Named_type::access, access, AlternateAccessSelection);


    ITU_T_CHOICEC_DEFN(AlternateAccess_sequence_of::unnamed, unnamed, AlternateAccessSelection, AlternateAccess_sequence_of_unnamed);
    ITU_T_CHOICEC_DEFN(AlternateAccess_sequence_of::named, named, AlternateAccess_sequence_of::Named_type, AlternateAccess_sequence_of_named);

    // choice AlternateAccessSelection

    AlternateAccessSelection::SelectAlternateAccess_type::SelectAlternateAccess_type() : accessSelection_(), alternateAccess_() {
    };

    AlternateAccessSelection::SelectAlternateAccess_type::SelectAlternateAccess_type(const AccessSelection_type& arg__accessSelection,
            const AlternateAccess& arg__alternateAccess) :
    accessSelection_(arg__accessSelection),
    alternateAccess_(arg__alternateAccess) {
    };

    AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::IndexRange_type() : lowIndex_(), numberOfElements_() {
    };

    AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::IndexRange_type(const Unsigned32& arg__lowIndex,
            const Unsigned32& arg__numberOfElements) :
    lowIndex_(arg__lowIndex),
    numberOfElements_(arg__numberOfElements) {
    };


    ITU_T_HOLDERH_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::lowIndex, lowIndex, Unsigned32);
    ITU_T_HOLDERH_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::numberOfElements, numberOfElements, Unsigned32);


    ITU_T_CHOICES_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::component, component, Identifier, AccessSelection_type_component);
    ITU_T_CHOICES_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::index, index, Unsigned32, AccessSelection_type_index);
    ITU_T_CHOICEC_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::indexRange, indexRange, AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type, AccessSelection_type_indexRange);
    ITU_T_CHOICES_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::allElements, allElements, null_type, AccessSelection_type_allElements);


    ITU_T_HOLDERH_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::accessSelection, accessSelection, AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type);
    ITU_T_HOLDERH_DEFN(AlternateAccessSelection::SelectAlternateAccess_type::alternateAccess, alternateAccess, AlternateAccess);

    AlternateAccessSelection::SelectAccess_type::IndexRange_type::IndexRange_type() : lowIndex_(), numberOfElements_() {
    };

    AlternateAccessSelection::SelectAccess_type::IndexRange_type::IndexRange_type(const Unsigned32& arg__lowIndex,
            const Unsigned32& arg__numberOfElements) :
    lowIndex_(arg__lowIndex),
    numberOfElements_(arg__numberOfElements) {
    };


    ITU_T_HOLDERH_DEFN(AlternateAccessSelection::SelectAccess_type::IndexRange_type::lowIndex, lowIndex, Unsigned32);
    ITU_T_HOLDERH_DEFN(AlternateAccessSelection::SelectAccess_type::IndexRange_type::numberOfElements, numberOfElements, Unsigned32);


    ITU_T_CHOICES_DEFN(AlternateAccessSelection::SelectAccess_type::component, component, Identifier, SelectAccess_type_component);
    ITU_T_CHOICES_DEFN(AlternateAccessSelection::SelectAccess_type::index, index, Unsigned32, SelectAccess_type_index);
    ITU_T_CHOICEC_DEFN(AlternateAccessSelection::SelectAccess_type::indexRange, indexRange, AlternateAccessSelection::SelectAccess_type::IndexRange_type, SelectAccess_type_indexRange);
    ITU_T_CHOICES_DEFN(AlternateAccessSelection::SelectAccess_type::allElements, allElements, null_type, SelectAccess_type_allElements);


    ITU_T_CHOICEC_DEFN(AlternateAccessSelection::selectAlternateAccess, selectAlternateAccess, AlternateAccessSelection::SelectAlternateAccess_type, AlternateAccessSelection_selectAlternateAccess);
    ITU_T_CHOICEC_DEFN(AlternateAccessSelection::selectAccess, selectAccess, AlternateAccessSelection::SelectAccess_type, AlternateAccessSelection_selectAccess);

    // choice AccessResult

    ITU_T_CHOICES_DEFN(AccessResult::failure, failure, DataAccessError, AccessResult_failure);
    ITU_T_CHOICEC_DEFN(AccessResult::success, success, Data, AccessResult_success);

    // choice Data

    ITU_T_CHOICEC_DEFN(Data::array, array, Data::Array_type, Data_array);
    ITU_T_CHOICEC_DEFN(Data::structure, structure, Data::Structure_type, Data_structure);
    ITU_T_CHOICES_DEFN(Data::boolean, boolean, bool, Data_boolean);
    ITU_T_CHOICES_DEFN(Data::bit_string, bit_string, bitstring_type, Data_bit_string);
    ITU_T_CHOICES_DEFN(Data::integer, integer, int, Data_integer);
    ITU_T_CHOICES_DEFN(Data::unsignedV, unsignedV, int, Data_unsignedV);
    ITU_T_CHOICES_DEFN(Data::floating_point, floating_point, FloatingPoint, Data_floating_point);
    ITU_T_CHOICES_DEFN(Data::octet_string, octet_string, octetstring_type, Data_octet_string);
    ITU_T_CHOICES_DEFN(Data::visible_string, visible_string, visiblestring_type, Data_visible_string);
    ITU_T_CHOICES_DEFN(Data::generalized_time, generalized_time, gentime_type, Data_generalized_time);
    ITU_T_CHOICES_DEFN(Data::binary_time, binary_time, TimeOfDay, Data_binary_time);
    ITU_T_CHOICES_DEFN(Data::bcd, bcd, int, Data_bcd);
    ITU_T_CHOICES_DEFN(Data::booleanArray, booleanArray, bitstring_type, Data_booleanArray);
    ITU_T_CHOICES_DEFN(Data::objId, objId, oid_type, Data_objId);
    ITU_T_CHOICES_DEFN(Data::mMSString, mMSString, MMSString, Data_mMSString);

    // choice VariableAccessSpecification

    VariableAccessSpecification::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of() : variableSpecification_() {
    };

    VariableAccessSpecification::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    VariableAccessSpecification::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of(shared_ptr< VariableSpecification> arg__variableSpecification,
            shared_ptr< AlternateAccess> arg__alternateAccess) :
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };


    ITU_T_HOLDERH_DEFN(VariableAccessSpecification::ListOfVariable_type_sequence_of::variableSpecification, variableSpecification, VariableSpecification);
    ITU_T_OPTIONAL_DEFN(VariableAccessSpecification::ListOfVariable_type_sequence_of::alternateAccess, alternateAccess, AlternateAccess);


    ITU_T_CHOICEC_DEFN(VariableAccessSpecification::listOfVariable, listOfVariable, VariableAccessSpecification::ListOfVariable_type, VariableAccessSpecification_listOfVariable);
    ITU_T_CHOICEC_DEFN(VariableAccessSpecification::variableListName, variableListName, ObjectName, VariableAccessSpecification_variableListName);

    // choice VariableSpecification

    VariableSpecification::VariableDescription_type::VariableDescription_type() : address_(), typeSpecification_() {
    };

    VariableSpecification::VariableDescription_type::VariableDescription_type(const MMS_Object_Module_1::Address& arg__address,
            const TypeSpecification& arg__typeSpecification) :
    address_(arg__address),
    typeSpecification_(arg__typeSpecification) {
    };


    ITU_T_HOLDERH_DEFN(VariableSpecification::VariableDescription_type::address, address, MMS_Object_Module_1::Address);
    ITU_T_HOLDERH_DEFN(VariableSpecification::VariableDescription_type::typeSpecification, typeSpecification, TypeSpecification);


    ITU_T_CHOICEC_DEFN(VariableSpecification::name, name, ObjectName, VariableSpecification_name);
    ITU_T_CHOICEC_DEFN(VariableSpecification::address, address, MMS_Object_Module_1::Address, VariableSpecification_address);
    ITU_T_CHOICEC_DEFN(VariableSpecification::variableDescription, variableDescription, VariableSpecification::VariableDescription_type, VariableSpecification_variableDescription);
    ITU_T_CHOICEC_DEFN(VariableSpecification::scatteredAccessDescription, scatteredAccessDescription, ISO_9506_MMS_1A::ScatteredAccessDescription, VariableSpecification_scatteredAccessDescription);
    ITU_T_CHOICES_DEFN(VariableSpecification::invalidated, invalidated, null_type, VariableSpecification_invalidated);

    // sequence Read-Request

    Read_Request::Read_Request() : variableAccessSpecification_() {
    };

    Read_Request::Read_Request(const VariableAccessSpecification& arg__variableAccessSpecification) :
    variableAccessSpecification_(arg__variableAccessSpecification) {
    };

    Read_Request::Read_Request(shared_ptr< bool> arg__specificationWithResult,
            shared_ptr< VariableAccessSpecification> arg__variableAccessSpecification) :
    specificationWithResult_(arg__specificationWithResult),
    variableAccessSpecification_(arg__variableAccessSpecification) {
    };

    const bool Read_Request::specificationWithResult__default = false;


    ITU_T_DEFAULTH_DEFN(Read_Request::specificationWithResult, specificationWithResult, bool);
    ITU_T_HOLDERH_DEFN(Read_Request::variableAccessSpecification, variableAccessSpecification, VariableAccessSpecification);

    // sequence Read-Response

    Read_Response::Read_Response() : listOfAccessResult_() {
    };

    Read_Response::Read_Response(const ListOfAccessResult_type& arg__listOfAccessResult) :
    listOfAccessResult_(arg__listOfAccessResult) {
    };

    Read_Response::Read_Response(shared_ptr< VariableAccessSpecification> arg__variableAccessSpecification,
            shared_ptr< ListOfAccessResult_type> arg__listOfAccessResult) :
    variableAccessSpecification_(arg__variableAccessSpecification),
    listOfAccessResult_(arg__listOfAccessResult) {
    };


    ITU_T_OPTIONAL_DEFN(Read_Response::variableAccessSpecification, variableAccessSpecification, VariableAccessSpecification);
    ITU_T_HOLDERH_DEFN(Read_Response::listOfAccessResult, listOfAccessResult, Read_Response::ListOfAccessResult_type);

    // sequence Write-Request

    Write_Request::Write_Request() : variableAccessSpecification_(), listOfData_() {
    };

    Write_Request::Write_Request(const VariableAccessSpecification& arg__variableAccessSpecification,
            const ListOfData_type& arg__listOfData) :
    variableAccessSpecification_(arg__variableAccessSpecification),
    listOfData_(arg__listOfData) {
    };


    ITU_T_HOLDERH_DEFN(Write_Request::variableAccessSpecification, variableAccessSpecification, VariableAccessSpecification);
    ITU_T_HOLDERH_DEFN(Write_Request::listOfData, listOfData, Write_Request::ListOfData_type);



    ITU_T_CHOICES_DEFN(Write_Response_sequence_of::failure, failure, DataAccessError, Write_Response_sequence_of_failure);
    ITU_T_CHOICES_DEFN(Write_Response_sequence_of::success, success, null_type, Write_Response_sequence_of_success);

    // sequence InformationReport

    InformationReport::InformationReport() : variableAccessSpecification_(), listOfAccessResult_() {
    };

    InformationReport::InformationReport(const VariableAccessSpecification& arg__variableAccessSpecification,
            const ListOfAccessResult_type& arg__listOfAccessResult) :
    variableAccessSpecification_(arg__variableAccessSpecification),
    listOfAccessResult_(arg__listOfAccessResult) {
    };


    ITU_T_HOLDERH_DEFN(InformationReport::variableAccessSpecification, variableAccessSpecification, VariableAccessSpecification);
    ITU_T_HOLDERH_DEFN(InformationReport::listOfAccessResult, listOfAccessResult, InformationReport::ListOfAccessResult_type);

    // choice GetVariableAccessAttributes-Request

    ITU_T_CHOICEC_DEFN(GetVariableAccessAttributes_Request::name, name, ObjectName, GetVariableAccessAttributes_Request_name);
    ITU_T_CHOICEC_DEFN(GetVariableAccessAttributes_Request::address, address, MMS_Object_Module_1::Address, GetVariableAccessAttributes_Request_address);

    // sequence GetVariableAccessAttributes-Response

    GetVariableAccessAttributes_Response::GetVariableAccessAttributes_Response() : mmsDeletable_(), typeDescription_() {
    };

    GetVariableAccessAttributes_Response::GetVariableAccessAttributes_Response(const bool& arg__mmsDeletable,
            const MMS_Object_Module_1::TypeDescription& arg__typeDescription) :
    mmsDeletable_(arg__mmsDeletable),
    typeDescription_(arg__typeDescription) {
    };

    GetVariableAccessAttributes_Response::GetVariableAccessAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< MMS_Object_Module_1::Address> arg__address,
            shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
            shared_ptr< Identifier> arg__accessControlList,
            shared_ptr< visiblestring_type> arg__meaning) :
    mmsDeletable_(arg__mmsDeletable),
    address_(arg__address),
    typeDescription_(arg__typeDescription),
    accessControlList_(arg__accessControlList),
    meaning_(arg__meaning) {
    };


    ITU_T_HOLDERH_DEFN(GetVariableAccessAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_OPTIONAL_DEFN(GetVariableAccessAttributes_Response::address, address, MMS_Object_Module_1::Address);
    ITU_T_HOLDERH_DEFN(GetVariableAccessAttributes_Response::typeDescription, typeDescription, MMS_Object_Module_1::TypeDescription);
    ITU_T_OPTIONAL_DEFN(GetVariableAccessAttributes_Response::accessControlList, accessControlList, Identifier);
    ITU_T_OPTIONAL_DEFN(GetVariableAccessAttributes_Response::meaning, meaning, visiblestring_type);

    // sequence DefineNamedVariable-Request

    DefineNamedVariable_Request::DefineNamedVariable_Request() : variableName_(), address_() {
    };

    DefineNamedVariable_Request::DefineNamedVariable_Request(const ObjectName& arg__variableName,
            const MMS_Object_Module_1::Address& arg__address) :
    variableName_(arg__variableName),
    address_(arg__address) {
    };

    DefineNamedVariable_Request::DefineNamedVariable_Request(shared_ptr< ObjectName> arg__variableName,
            shared_ptr< MMS_Object_Module_1::Address> arg__address,
            shared_ptr< TypeSpecification> arg__typeSpecification) :
    variableName_(arg__variableName),
    address_(arg__address),
    typeSpecification_(arg__typeSpecification) {
    };


    ITU_T_HOLDERH_DEFN(DefineNamedVariable_Request::variableName, variableName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineNamedVariable_Request::address, address, MMS_Object_Module_1::Address);
    ITU_T_OPTIONAL_DEFN(DefineNamedVariable_Request::typeSpecification, typeSpecification, TypeSpecification);

    // sequence DeleteVariableAccess-Request
    const uint8_t DeleteVariableAccess_Request::scopeOfDelete_specific = 0;
    const uint8_t DeleteVariableAccess_Request::scopeOfDelete_aa_specific = 1;
    const uint8_t DeleteVariableAccess_Request::scopeOfDelete_domain = 2;
    const uint8_t DeleteVariableAccess_Request::scopeOfDelete_vmd = 3;

    DeleteVariableAccess_Request::DeleteVariableAccess_Request() {
    };

    DeleteVariableAccess_Request::DeleteVariableAccess_Request(shared_ptr< uint8_t> arg__scopeOfDelete,
            shared_ptr< ListOfName_type> arg__listOfName,
            shared_ptr< Identifier> arg__domainName) :
    scopeOfDelete_(arg__scopeOfDelete),
    listOfName_(arg__listOfName),
    domainName_(arg__domainName) {
    };

    const uint8_t DeleteVariableAccess_Request::scopeOfDelete__default = 0;


    ITU_T_DEFAULTH_DEFN(DeleteVariableAccess_Request::scopeOfDelete, scopeOfDelete, uint8_t);
    ITU_T_OPTIONAL_DEFN(DeleteVariableAccess_Request::listOfName, listOfName, DeleteVariableAccess_Request::ListOfName_type);
    ITU_T_OPTIONAL_DEFN(DeleteVariableAccess_Request::domainName, domainName, Identifier);

    // sequence DeleteVariableAccess-Response

    DeleteVariableAccess_Response::DeleteVariableAccess_Response() : numberMatched_(), numberDeleted_() {
    };

    DeleteVariableAccess_Response::DeleteVariableAccess_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberDeleted) :
    numberMatched_(arg__numberMatched),
    numberDeleted_(arg__numberDeleted) {
    };


    ITU_T_HOLDERH_DEFN(DeleteVariableAccess_Response::numberMatched, numberMatched, Unsigned32);
    ITU_T_HOLDERH_DEFN(DeleteVariableAccess_Response::numberDeleted, numberDeleted, Unsigned32);

    // sequence DefineNamedVariableList-Request

    DefineNamedVariableList_Request::DefineNamedVariableList_Request() : variableListName_(), listOfVariable_() {
    };

    DefineNamedVariableList_Request::DefineNamedVariableList_Request(const ObjectName& arg__variableListName,
            const ListOfVariable_type& arg__listOfVariable) :
    variableListName_(arg__variableListName),
    listOfVariable_(arg__listOfVariable) {
    };

    DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of() : variableSpecification_() {
    };

    DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of(shared_ptr< VariableSpecification> arg__variableSpecification,
            shared_ptr< AlternateAccess> arg__alternateAccess) :
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };


    ITU_T_HOLDERH_DEFN(DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::variableSpecification, variableSpecification, VariableSpecification);
    ITU_T_OPTIONAL_DEFN(DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::alternateAccess, alternateAccess, AlternateAccess);


    ITU_T_HOLDERH_DEFN(DefineNamedVariableList_Request::variableListName, variableListName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineNamedVariableList_Request::listOfVariable, listOfVariable, DefineNamedVariableList_Request::ListOfVariable_type);

    // sequence GetNamedVariableListAttributes-Response

    GetNamedVariableListAttributes_Response::GetNamedVariableListAttributes_Response() : mmsDeletable_(), listOfVariable_() {
    };

    GetNamedVariableListAttributes_Response::GetNamedVariableListAttributes_Response(const bool& arg__mmsDeletable,
            const ListOfVariable_type& arg__listOfVariable) :
    mmsDeletable_(arg__mmsDeletable),
    listOfVariable_(arg__listOfVariable) {
    };

    GetNamedVariableListAttributes_Response::GetNamedVariableListAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< ListOfVariable_type> arg__listOfVariable,
            shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    listOfVariable_(arg__listOfVariable),
    accessControlList_(arg__accessControlList) {
    };

    GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of() : variableSpecification_() {
    };

    GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::ListOfVariable_type_sequence_of(shared_ptr< VariableSpecification> arg__variableSpecification,
            shared_ptr< AlternateAccess> arg__alternateAccess) :
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };


    ITU_T_HOLDERH_DEFN(GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::variableSpecification, variableSpecification, VariableSpecification);
    ITU_T_OPTIONAL_DEFN(GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::alternateAccess, alternateAccess, AlternateAccess);


    ITU_T_HOLDERH_DEFN(GetNamedVariableListAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetNamedVariableListAttributes_Response::listOfVariable, listOfVariable, GetNamedVariableListAttributes_Response::ListOfVariable_type);
    ITU_T_OPTIONAL_DEFN(GetNamedVariableListAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence DeleteNamedVariableList-Request
    const uint8_t DeleteNamedVariableList_Request::scopeOfDelete_specific = 0;
    const uint8_t DeleteNamedVariableList_Request::scopeOfDelete_aa_specific = 1;
    const uint8_t DeleteNamedVariableList_Request::scopeOfDelete_domain = 2;
    const uint8_t DeleteNamedVariableList_Request::scopeOfDelete_vmd = 3;

    DeleteNamedVariableList_Request::DeleteNamedVariableList_Request() {
    };

    DeleteNamedVariableList_Request::DeleteNamedVariableList_Request(shared_ptr< uint8_t> arg__scopeOfDelete,
            shared_ptr< ListOfVariableListName_type> arg__listOfVariableListName,
            shared_ptr< Identifier> arg__domainName) :
    scopeOfDelete_(arg__scopeOfDelete),
    listOfVariableListName_(arg__listOfVariableListName),
    domainName_(arg__domainName) {
    };

    const uint8_t DeleteNamedVariableList_Request::scopeOfDelete__default = 0;


    ITU_T_DEFAULTH_DEFN(DeleteNamedVariableList_Request::scopeOfDelete, scopeOfDelete, uint8_t);
    ITU_T_OPTIONAL_DEFN(DeleteNamedVariableList_Request::listOfVariableListName, listOfVariableListName, DeleteNamedVariableList_Request::ListOfVariableListName_type);
    ITU_T_OPTIONAL_DEFN(DeleteNamedVariableList_Request::domainName, domainName, Identifier);

    // sequence DeleteNamedVariableList-Response

    DeleteNamedVariableList_Response::DeleteNamedVariableList_Response() : numberMatched_(), numberDeleted_() {
    };

    DeleteNamedVariableList_Response::DeleteNamedVariableList_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberDeleted) :
    numberMatched_(arg__numberMatched),
    numberDeleted_(arg__numberDeleted) {
    };


    ITU_T_HOLDERH_DEFN(DeleteNamedVariableList_Response::numberMatched, numberMatched, Unsigned32);
    ITU_T_HOLDERH_DEFN(DeleteNamedVariableList_Response::numberDeleted, numberDeleted, Unsigned32);

    // sequence DefineNamedType-Request

    DefineNamedType_Request::DefineNamedType_Request() : typeName_(), typeSpecification_() {
    };

    DefineNamedType_Request::DefineNamedType_Request(const ObjectName& arg__typeName,
            const TypeSpecification& arg__typeSpecification) :
    typeName_(arg__typeName),
    typeSpecification_(arg__typeSpecification) {
    };


    ITU_T_HOLDERH_DEFN(DefineNamedType_Request::typeName, typeName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineNamedType_Request::typeSpecification, typeSpecification, TypeSpecification);

    // sequence GetNamedTypeAttributes-Response

    GetNamedTypeAttributes_Response::GetNamedTypeAttributes_Response() : mmsDeletable_(), typeSpecification_() {
    };

    GetNamedTypeAttributes_Response::GetNamedTypeAttributes_Response(const bool& arg__mmsDeletable,
            const TypeSpecification& arg__typeSpecification) :
    mmsDeletable_(arg__mmsDeletable),
    typeSpecification_(arg__typeSpecification) {
    };

    GetNamedTypeAttributes_Response::GetNamedTypeAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< TypeSpecification> arg__typeSpecification,
            shared_ptr< Identifier> arg__accessControlList,
            shared_ptr< visiblestring_type> arg__meaning) :
    mmsDeletable_(arg__mmsDeletable),
    typeSpecification_(arg__typeSpecification),
    accessControlList_(arg__accessControlList),
    meaning_(arg__meaning) {
    };


    ITU_T_HOLDERH_DEFN(GetNamedTypeAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetNamedTypeAttributes_Response::typeSpecification, typeSpecification, TypeSpecification);
    ITU_T_OPTIONAL_DEFN(GetNamedTypeAttributes_Response::accessControlList, accessControlList, Identifier);
    ITU_T_OPTIONAL_DEFN(GetNamedTypeAttributes_Response::meaning, meaning, visiblestring_type);

    // sequence DeleteNamedType-Request
    const uint8_t DeleteNamedType_Request::scopeOfDelete_specific = 0;
    const uint8_t DeleteNamedType_Request::scopeOfDelete_aa_specific = 1;
    const uint8_t DeleteNamedType_Request::scopeOfDelete_domain = 2;
    const uint8_t DeleteNamedType_Request::scopeOfDelete_vmd = 3;

    DeleteNamedType_Request::DeleteNamedType_Request() {
    };

    DeleteNamedType_Request::DeleteNamedType_Request(shared_ptr< uint8_t> arg__scopeOfDelete,
            shared_ptr< ListOfTypeName_type> arg__listOfTypeName,
            shared_ptr< Identifier> arg__domainName) :
    scopeOfDelete_(arg__scopeOfDelete),
    listOfTypeName_(arg__listOfTypeName),
    domainName_(arg__domainName) {
    };

    const uint8_t DeleteNamedType_Request::scopeOfDelete__default = 0;


    ITU_T_DEFAULTH_DEFN(DeleteNamedType_Request::scopeOfDelete, scopeOfDelete, uint8_t);
    ITU_T_OPTIONAL_DEFN(DeleteNamedType_Request::listOfTypeName, listOfTypeName, DeleteNamedType_Request::ListOfTypeName_type);
    ITU_T_OPTIONAL_DEFN(DeleteNamedType_Request::domainName, domainName, Identifier);

    // sequence DeleteNamedType-Response

    DeleteNamedType_Response::DeleteNamedType_Response() : numberMatched_(), numberDeleted_() {
    };

    DeleteNamedType_Response::DeleteNamedType_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberDeleted) :
    numberMatched_(arg__numberMatched),
    numberDeleted_(arg__numberDeleted) {
    };


    ITU_T_HOLDERH_DEFN(DeleteNamedType_Response::numberMatched, numberMatched, Unsigned32);
    ITU_T_HOLDERH_DEFN(DeleteNamedType_Response::numberDeleted, numberDeleted, Unsigned32);

    // sequence ExchangeData-Request

    ExchangeData_Request::ExchangeData_Request() : dataExchangeName_(), listOfRequestData_() {
    };

    ExchangeData_Request::ExchangeData_Request(const ObjectName& arg__dataExchangeName,
            const ListOfRequestData_type& arg__listOfRequestData) :
    dataExchangeName_(arg__dataExchangeName),
    listOfRequestData_(arg__listOfRequestData) {
    };


    ITU_T_HOLDERH_DEFN(ExchangeData_Request::dataExchangeName, dataExchangeName, ObjectName);
    ITU_T_HOLDERH_DEFN(ExchangeData_Request::listOfRequestData, listOfRequestData, ExchangeData_Request::ListOfRequestData_type);

    // sequence ExchangeData-Response

    ExchangeData_Response::ExchangeData_Response() : listOfResponseData_() {
    };

    ExchangeData_Response::ExchangeData_Response(const ListOfResponseData_type& arg__listOfResponseData) :
    listOfResponseData_(arg__listOfResponseData) {
    };


    ITU_T_HOLDERH_DEFN(ExchangeData_Response::listOfResponseData, listOfResponseData, ExchangeData_Response::ListOfResponseData_type);

    // sequence GetDataExchangeAttributes-Response

    GetDataExchangeAttributes_Response::GetDataExchangeAttributes_Response() : inUse_(), listOfRequestTypeDescriptions_(), listOfResponseTypeDescriptions_() {
    };

    GetDataExchangeAttributes_Response::GetDataExchangeAttributes_Response(const bool& arg__inUse,
            const ListOfRequestTypeDescriptions_type& arg__listOfRequestTypeDescriptions,
            const ListOfResponseTypeDescriptions_type& arg__listOfResponseTypeDescriptions) :
    inUse_(arg__inUse),
    listOfRequestTypeDescriptions_(arg__listOfRequestTypeDescriptions),
    listOfResponseTypeDescriptions_(arg__listOfResponseTypeDescriptions) {
    };

    GetDataExchangeAttributes_Response::GetDataExchangeAttributes_Response(shared_ptr< bool> arg__inUse,
            shared_ptr< ListOfRequestTypeDescriptions_type> arg__listOfRequestTypeDescriptions,
            shared_ptr< ListOfResponseTypeDescriptions_type> arg__listOfResponseTypeDescriptions,
            shared_ptr< Identifier> arg__programInvocation,
            shared_ptr< Identifier> arg__accessControlList) :
    inUse_(arg__inUse),
    listOfRequestTypeDescriptions_(arg__listOfRequestTypeDescriptions),
    listOfResponseTypeDescriptions_(arg__listOfResponseTypeDescriptions),
    programInvocation_(arg__programInvocation),
    accessControlList_(arg__accessControlList) {
    };


    ITU_T_HOLDERH_DEFN(GetDataExchangeAttributes_Response::inUse, inUse, bool);
    ITU_T_HOLDERH_DEFN(GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions, listOfRequestTypeDescriptions, GetDataExchangeAttributes_Response::ListOfRequestTypeDescriptions_type);
    ITU_T_HOLDERH_DEFN(GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions, listOfResponseTypeDescriptions, GetDataExchangeAttributes_Response::ListOfResponseTypeDescriptions_type);
    ITU_T_OPTIONAL_DEFN(GetDataExchangeAttributes_Response::programInvocation, programInvocation, Identifier);
    ITU_T_OPTIONAL_DEFN(GetDataExchangeAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence TakeControl-Request

    TakeControl_Request::TakeControl_Request() : semaphoreName_() {
    };

    TakeControl_Request::TakeControl_Request(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    TakeControl_Request::TakeControl_Request(shared_ptr< ObjectName> arg__semaphoreName,
            shared_ptr< Identifier> arg__namedToken,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< Unsigned32> arg__acceptableDelay,
            shared_ptr< Unsigned32> arg__controlTimeOut,
            shared_ptr< bool> arg__abortOnTimeOut,
            shared_ptr< bool> arg__relinquishIfConnectionLost,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__applicationToPreempt) :
    semaphoreName_(arg__semaphoreName),
    namedToken_(arg__namedToken),
    priority_(arg__priority),
    acceptableDelay_(arg__acceptableDelay),
    controlTimeOut_(arg__controlTimeOut),
    abortOnTimeOut_(arg__abortOnTimeOut),
    relinquishIfConnectionLost_(arg__relinquishIfConnectionLost),
    applicationToPreempt_(arg__applicationToPreempt) {
    };

    const MMS_Object_Module_1::Priority TakeControl_Request::priority__default = MMS_Object_Module_1::Priority(64);

    const bool TakeControl_Request::relinquishIfConnectionLost__default = true;


    ITU_T_HOLDERH_DEFN(TakeControl_Request::semaphoreName, semaphoreName, ObjectName);
    ITU_T_OPTIONAL_DEFN(TakeControl_Request::namedToken, namedToken, Identifier);
    ITU_T_DEFAULTH_DEFN(TakeControl_Request::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_OPTIONAL_DEFN(TakeControl_Request::acceptableDelay, acceptableDelay, Unsigned32);
    ITU_T_OPTIONAL_DEFN(TakeControl_Request::controlTimeOut, controlTimeOut, Unsigned32);
    ITU_T_OPTIONAL_DEFN(TakeControl_Request::abortOnTimeOut, abortOnTimeOut, bool);
    ITU_T_DEFAULTH_DEFN(TakeControl_Request::relinquishIfConnectionLost, relinquishIfConnectionLost, bool);
    ITU_T_OPTIONAL_DEFN(TakeControl_Request::applicationToPreempt, applicationToPreempt, MMS_Environment_1::ApplicationReference);

    // choice TakeControl-Response

    ITU_T_CHOICES_DEFN(TakeControl_Response::noResult, noResult, null_type, TakeControl_Response_noResult);
    ITU_T_CHOICES_DEFN(TakeControl_Response::namedToken, namedToken, Identifier, TakeControl_Response_namedToken);

    // sequence RelinquishControl-Request

    RelinquishControl_Request::RelinquishControl_Request() : semaphoreName_() {
    };

    RelinquishControl_Request::RelinquishControl_Request(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    RelinquishControl_Request::RelinquishControl_Request(shared_ptr< ObjectName> arg__semaphoreName,
            shared_ptr< Identifier> arg__namedToken) :
    semaphoreName_(arg__semaphoreName),
    namedToken_(arg__namedToken) {
    };


    ITU_T_HOLDERH_DEFN(RelinquishControl_Request::semaphoreName, semaphoreName, ObjectName);
    ITU_T_OPTIONAL_DEFN(RelinquishControl_Request::namedToken, namedToken, Identifier);

    // sequence DefineSemaphore-Request

    DefineSemaphore_Request::DefineSemaphore_Request() : semaphoreName_(), numberOfTokens_() {
    };

    DefineSemaphore_Request::DefineSemaphore_Request(const ObjectName& arg__semaphoreName,
            const Unsigned16& arg__numberOfTokens) :
    semaphoreName_(arg__semaphoreName),
    numberOfTokens_(arg__numberOfTokens) {
    };


    ITU_T_HOLDERH_DEFN(DefineSemaphore_Request::semaphoreName, semaphoreName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineSemaphore_Request::numberOfTokens, numberOfTokens, Unsigned16);

    // sequence ReportSemaphoreStatus-Response
    const uint8_t ReportSemaphoreStatus_Response::classV_token = 0;
    const uint8_t ReportSemaphoreStatus_Response::classV_pool = 1;

    ReportSemaphoreStatus_Response::ReportSemaphoreStatus_Response() : mmsDeletable_(), classV_(), numberOfTokens_(), numberOfOwnedTokens_(), numberOfHungTokens_() {
    };

    ReportSemaphoreStatus_Response::ReportSemaphoreStatus_Response(const bool& arg__mmsDeletable,
            const uint8_t& arg__classV,
            const Unsigned16& arg__numberOfTokens,
            const Unsigned16& arg__numberOfOwnedTokens,
            const Unsigned16& arg__numberOfHungTokens) :
    mmsDeletable_(arg__mmsDeletable),
    classV_(arg__classV),
    numberOfTokens_(arg__numberOfTokens),
    numberOfOwnedTokens_(arg__numberOfOwnedTokens),
    numberOfHungTokens_(arg__numberOfHungTokens) {
    };

    ReportSemaphoreStatus_Response::ReportSemaphoreStatus_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< uint8_t> arg__classV,
            shared_ptr< Unsigned16> arg__numberOfTokens,
            shared_ptr< Unsigned16> arg__numberOfOwnedTokens,
            shared_ptr< Unsigned16> arg__numberOfHungTokens,
            shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    classV_(arg__classV),
    numberOfTokens_(arg__numberOfTokens),
    numberOfOwnedTokens_(arg__numberOfOwnedTokens),
    numberOfHungTokens_(arg__numberOfHungTokens),
    accessControlList_(arg__accessControlList) {
    };


    ITU_T_HOLDERH_DEFN(ReportSemaphoreStatus_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(ReportSemaphoreStatus_Response::classV, classV, uint8_t);
    ITU_T_HOLDERH_DEFN(ReportSemaphoreStatus_Response::numberOfTokens, numberOfTokens, Unsigned16);
    ITU_T_HOLDERH_DEFN(ReportSemaphoreStatus_Response::numberOfOwnedTokens, numberOfOwnedTokens, Unsigned16);
    ITU_T_HOLDERH_DEFN(ReportSemaphoreStatus_Response::numberOfHungTokens, numberOfHungTokens, Unsigned16);
    ITU_T_OPTIONAL_DEFN(ReportSemaphoreStatus_Response::accessControlList, accessControlList, Identifier);

    // sequence ReportPoolSemaphoreStatus-Request

    ReportPoolSemaphoreStatus_Request::ReportPoolSemaphoreStatus_Request() : semaphoreName_() {
    };

    ReportPoolSemaphoreStatus_Request::ReportPoolSemaphoreStatus_Request(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    ReportPoolSemaphoreStatus_Request::ReportPoolSemaphoreStatus_Request(shared_ptr< ObjectName> arg__semaphoreName,
            shared_ptr< Identifier> arg__nameToStartAfter) :
    semaphoreName_(arg__semaphoreName),
    nameToStartAfter_(arg__nameToStartAfter) {
    };


    ITU_T_HOLDERH_DEFN(ReportPoolSemaphoreStatus_Request::semaphoreName, semaphoreName, ObjectName);
    ITU_T_OPTIONAL_DEFN(ReportPoolSemaphoreStatus_Request::nameToStartAfter, nameToStartAfter, Identifier);

    // sequence ReportPoolSemaphoreStatus-Response

    ReportPoolSemaphoreStatus_Response::ReportPoolSemaphoreStatus_Response() : listOfNamedTokens_() {
    };

    ReportPoolSemaphoreStatus_Response::ReportPoolSemaphoreStatus_Response(const ListOfNamedTokens_type& arg__listOfNamedTokens) :
    listOfNamedTokens_(arg__listOfNamedTokens) {
    };

    ReportPoolSemaphoreStatus_Response::ReportPoolSemaphoreStatus_Response(shared_ptr< ListOfNamedTokens_type> arg__listOfNamedTokens,
            shared_ptr< bool> arg__moreFollows) :
    listOfNamedTokens_(arg__listOfNamedTokens),
    moreFollows_(arg__moreFollows) {
    };



    ITU_T_CHOICES_DEFN(ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::freeNamedToken, freeNamedToken, Identifier, ListOfNamedTokens_type_sequence_of_freeNamedToken);
    ITU_T_CHOICES_DEFN(ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::ownedNamedToken, ownedNamedToken, Identifier, ListOfNamedTokens_type_sequence_of_ownedNamedToken);
    ITU_T_CHOICES_DEFN(ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::hungNamedToken, hungNamedToken, Identifier, ListOfNamedTokens_type_sequence_of_hungNamedToken);

    const bool ReportPoolSemaphoreStatus_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(ReportPoolSemaphoreStatus_Response::listOfNamedTokens, listOfNamedTokens, ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type);
    ITU_T_DEFAULTH_DEFN(ReportPoolSemaphoreStatus_Response::moreFollows, moreFollows, bool);

    // sequence ReportSemaphoreEntryStatus-Request
    const uint8_t ReportSemaphoreEntryStatus_Request::state_queued = 0;
    const uint8_t ReportSemaphoreEntryStatus_Request::state_owner = 1;
    const uint8_t ReportSemaphoreEntryStatus_Request::state_hung = 2;

    ReportSemaphoreEntryStatus_Request::ReportSemaphoreEntryStatus_Request() : semaphoreName_(), state_() {
    };

    ReportSemaphoreEntryStatus_Request::ReportSemaphoreEntryStatus_Request(const ObjectName& arg__semaphoreName,
            const uint8_t& arg__state) :
    semaphoreName_(arg__semaphoreName),
    state_(arg__state) {
    };

    ReportSemaphoreEntryStatus_Request::ReportSemaphoreEntryStatus_Request(shared_ptr< ObjectName> arg__semaphoreName,
            shared_ptr< uint8_t> arg__state,
            shared_ptr< octetstring_type> arg__entryIDToStartAfter) :
    semaphoreName_(arg__semaphoreName),
    state_(arg__state),
    entryIDToStartAfter_(arg__entryIDToStartAfter) {
    };


    ITU_T_HOLDERH_DEFN(ReportSemaphoreEntryStatus_Request::semaphoreName, semaphoreName, ObjectName);
    ITU_T_HOLDERH_DEFN(ReportSemaphoreEntryStatus_Request::state, state, uint8_t);
    ITU_T_OPTIONAL_DEFN(ReportSemaphoreEntryStatus_Request::entryIDToStartAfter, entryIDToStartAfter, octetstring_type);

    // sequence ReportSemaphoreEntryStatus-Response

    ReportSemaphoreEntryStatus_Response::ReportSemaphoreEntryStatus_Response() : listOfSemaphoreEntry_() {
    };

    ReportSemaphoreEntryStatus_Response::ReportSemaphoreEntryStatus_Response(const ListOfSemaphoreEntry_type& arg__listOfSemaphoreEntry) :
    listOfSemaphoreEntry_(arg__listOfSemaphoreEntry) {
    };

    ReportSemaphoreEntryStatus_Response::ReportSemaphoreEntryStatus_Response(shared_ptr< ListOfSemaphoreEntry_type> arg__listOfSemaphoreEntry,
            shared_ptr< bool> arg__moreFollows) :
    listOfSemaphoreEntry_(arg__listOfSemaphoreEntry),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReportSemaphoreEntryStatus_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry, listOfSemaphoreEntry, ReportSemaphoreEntryStatus_Response::ListOfSemaphoreEntry_type);
    ITU_T_DEFAULTH_DEFN(ReportSemaphoreEntryStatus_Response::moreFollows, moreFollows, bool);

    // sequence SemaphoreEntry
    const uint8_t SemaphoreEntry::entryClass_simple = 0;
    const uint8_t SemaphoreEntry::entryClass_modifier = 1;

    SemaphoreEntry::SemaphoreEntry() : entryID_(), entryClass_(), applicationReference_() {
    };

    SemaphoreEntry::SemaphoreEntry(const octetstring_type& arg__entryID,
            const uint8_t& arg__entryClass,
            const MMS_Environment_1::ApplicationReference& arg__applicationReference) :
    entryID_(arg__entryID),
    entryClass_(arg__entryClass),
    applicationReference_(arg__applicationReference) {
    };

    SemaphoreEntry::SemaphoreEntry(shared_ptr< octetstring_type> arg__entryID,
            shared_ptr< uint8_t> arg__entryClass,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__applicationReference,
            shared_ptr< Identifier> arg__namedToken,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< Unsigned32> arg__remainingTimeOut,
            shared_ptr< bool> arg__abortOnTimeOut,
            shared_ptr< bool> arg__relinquishIfConnectionLost) :
    entryID_(arg__entryID),
    entryClass_(arg__entryClass),
    applicationReference_(arg__applicationReference),
    namedToken_(arg__namedToken),
    priority_(arg__priority),
    remainingTimeOut_(arg__remainingTimeOut),
    abortOnTimeOut_(arg__abortOnTimeOut),
    relinquishIfConnectionLost_(arg__relinquishIfConnectionLost) {
    };

    const MMS_Object_Module_1::Priority SemaphoreEntry::priority__default = MMS_Object_Module_1::Priority(64);

    const bool SemaphoreEntry::relinquishIfConnectionLost__default = true;


    ITU_T_HOLDERH_DEFN(SemaphoreEntry::entryID, entryID, octetstring_type);
    ITU_T_HOLDERH_DEFN(SemaphoreEntry::entryClass, entryClass, uint8_t);
    ITU_T_HOLDERH_DEFN(SemaphoreEntry::applicationReference, applicationReference, MMS_Environment_1::ApplicationReference);
    ITU_T_OPTIONAL_DEFN(SemaphoreEntry::namedToken, namedToken, Identifier);
    ITU_T_DEFAULTH_DEFN(SemaphoreEntry::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_OPTIONAL_DEFN(SemaphoreEntry::remainingTimeOut, remainingTimeOut, Unsigned32);
    ITU_T_OPTIONAL_DEFN(SemaphoreEntry::abortOnTimeOut, abortOnTimeOut, bool);
    ITU_T_DEFAULTH_DEFN(SemaphoreEntry::relinquishIfConnectionLost, relinquishIfConnectionLost, bool);

    // sequence AttachToSemaphore

    AttachToSemaphore::AttachToSemaphore() : semaphoreName_() {
    };

    AttachToSemaphore::AttachToSemaphore(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    AttachToSemaphore::AttachToSemaphore(shared_ptr< ObjectName> arg__semaphoreName,
            shared_ptr< Identifier> arg__namedToken,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< Unsigned32> arg__acceptableDelay,
            shared_ptr< Unsigned32> arg__controlTimeOut,
            shared_ptr< bool> arg__abortOnTimeOut,
            shared_ptr< bool> arg__relinquishIfConnectionLost) :
    semaphoreName_(arg__semaphoreName),
    namedToken_(arg__namedToken),
    priority_(arg__priority),
    acceptableDelay_(arg__acceptableDelay),
    controlTimeOut_(arg__controlTimeOut),
    abortOnTimeOut_(arg__abortOnTimeOut),
    relinquishIfConnectionLost_(arg__relinquishIfConnectionLost) {
    };

    const MMS_Object_Module_1::Priority AttachToSemaphore::priority__default = MMS_Object_Module_1::Priority(64);

    const bool AttachToSemaphore::relinquishIfConnectionLost__default = true;


    ITU_T_HOLDERH_DEFN(AttachToSemaphore::semaphoreName, semaphoreName, ObjectName);
    ITU_T_OPTIONAL_DEFN(AttachToSemaphore::namedToken, namedToken, Identifier);
    ITU_T_DEFAULTH_DEFN(AttachToSemaphore::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_OPTIONAL_DEFN(AttachToSemaphore::acceptableDelay, acceptableDelay, Unsigned32);
    ITU_T_OPTIONAL_DEFN(AttachToSemaphore::controlTimeOut, controlTimeOut, Unsigned32);
    ITU_T_OPTIONAL_DEFN(AttachToSemaphore::abortOnTimeOut, abortOnTimeOut, bool);
    ITU_T_DEFAULTH_DEFN(AttachToSemaphore::relinquishIfConnectionLost, relinquishIfConnectionLost, bool);

    // sequence Input-Request

    Input_Request::Input_Request() : operatorStationName_() {
    };

    Input_Request::Input_Request(const Identifier& arg__operatorStationName) :
    operatorStationName_(arg__operatorStationName) {
    };

    Input_Request::Input_Request(shared_ptr< Identifier> arg__operatorStationName,
            shared_ptr< bool> arg__echo,
            shared_ptr< ListOfPromptData_type> arg__listOfPromptData,
            shared_ptr< Unsigned32> arg__inputTimeOut) :
    operatorStationName_(arg__operatorStationName),
    echo_(arg__echo),
    listOfPromptData_(arg__listOfPromptData),
    inputTimeOut_(arg__inputTimeOut) {
    };

    const bool Input_Request::echo__default = true;


    ITU_T_HOLDERH_DEFN(Input_Request::operatorStationName, operatorStationName, Identifier);
    ITU_T_DEFAULTH_DEFN(Input_Request::echo, echo, bool);
    ITU_T_OPTIONAL_DEFN(Input_Request::listOfPromptData, listOfPromptData, Input_Request::ListOfPromptData_type);
    ITU_T_OPTIONAL_DEFN(Input_Request::inputTimeOut, inputTimeOut, Unsigned32);

    // sequence Output-Request

    Output_Request::Output_Request() : operatorStationName_(), listOfOutputData_() {
    };

    Output_Request::Output_Request(const Identifier& arg__operatorStationName,
            const ListOfOutputData_type& arg__listOfOutputData) :
    operatorStationName_(arg__operatorStationName),
    listOfOutputData_(arg__listOfOutputData) {
    };


    ITU_T_HOLDERH_DEFN(Output_Request::operatorStationName, operatorStationName, Identifier);
    ITU_T_HOLDERH_DEFN(Output_Request::listOfOutputData, listOfOutputData, Output_Request::ListOfOutputData_type);

    // sequence TriggerEvent-Request

    TriggerEvent_Request::TriggerEvent_Request() : eventConditionName_() {
    };

    TriggerEvent_Request::TriggerEvent_Request(const ObjectName& arg__eventConditionName) :
    eventConditionName_(arg__eventConditionName) {
    };

    TriggerEvent_Request::TriggerEvent_Request(shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority) :
    eventConditionName_(arg__eventConditionName),
    priority_(arg__priority) {
    };


    ITU_T_HOLDERH_DEFN(TriggerEvent_Request::eventConditionName, eventConditionName, ObjectName);
    ITU_T_OPTIONAL_DEFN(TriggerEvent_Request::priority, priority, MMS_Object_Module_1::Priority);

    // sequence EventNotification

    EventNotification::EventNotification() : eventEnrollmentName_(), eventConditionName_(), severity_(), transitionTime_() {
    };

    EventNotification::EventNotification(const ObjectName& arg__eventEnrollmentName,
            const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::Severity& arg__severity,
            const MMS_Object_Module_1::EventTime& arg__transitionTime) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    transitionTime_(arg__transitionTime) {
    };

    EventNotification::EventNotification(shared_ptr< ObjectName> arg__eventEnrollmentName,
            shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
            shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__transitionTime,
            shared_ptr< bool> arg__notificationLost,
            shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            shared_ptr< ActionResult_type> arg__actionResult) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    transitionTime_(arg__transitionTime),
    notificationLost_(arg__notificationLost),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    actionResult_(arg__actionResult) {
    };

    EventNotification::ActionResult_type::ActionResult_type() : eventActionName_(), successOrFailure_() {
    };

    EventNotification::ActionResult_type::ActionResult_type(const ObjectName& arg__eventActionName,
            const SuccessOrFailure_type& arg__successOrFailure) :
    eventActionName_(arg__eventActionName),
    successOrFailure_(arg__successOrFailure) {
    };

    EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::Success_type() : confirmedServiceResponse_() {
    };

    EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::Success_type(const ConfirmedServiceResponse& arg__confirmedServiceResponse) :
    confirmedServiceResponse_(arg__confirmedServiceResponse) {
    };

    EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::Success_type(shared_ptr< ConfirmedServiceResponse> arg__confirmedServiceResponse,
            shared_ptr< Response_Detail> arg__cs_Response_Detail) :
    confirmedServiceResponse_(arg__confirmedServiceResponse),
    cs_Response_Detail_(arg__cs_Response_Detail) {
    };


    ITU_T_HOLDERH_DEFN(EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::confirmedServiceResponse, confirmedServiceResponse, ConfirmedServiceResponse);
    ITU_T_OPTIONAL_DEFN(EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::cs_Response_Detail, cs_Response_Detail, Response_Detail);

    EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::Failure_type() : serviceError_() {
    };

    EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::Failure_type(const ServiceError& arg__serviceError) :
    serviceError_(arg__serviceError) {
    };

    EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::Failure_type(shared_ptr< Unsigned32> arg__modifierPosition,
            shared_ptr< ServiceError> arg__serviceError) :
    modifierPosition_(arg__modifierPosition),
    serviceError_(arg__serviceError) {
    };


    ITU_T_OPTIONAL_DEFN(EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::modifierPosition, modifierPosition, Unsigned32);
    ITU_T_HOLDERH_DEFN(EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serviceError, serviceError, ServiceError);


    ITU_T_CHOICEC_DEFN(EventNotification::ActionResult_type::SuccessOrFailure_type::success, success, EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type, SuccessOrFailure_type_success);
    ITU_T_CHOICEC_DEFN(EventNotification::ActionResult_type::SuccessOrFailure_type::failure, failure, EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type, SuccessOrFailure_type_failure);


    ITU_T_HOLDERH_DEFN(EventNotification::ActionResult_type::eventActionName, eventActionName, ObjectName);
    ITU_T_HOLDERH_DEFN(EventNotification::ActionResult_type::successOrFailure, successOrFailure, EventNotification::ActionResult_type::SuccessOrFailure_type);

    const bool EventNotification::notificationLost__default = false;


    ITU_T_HOLDERH_DEFN(EventNotification::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_HOLDERH_DEFN(EventNotification::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(EventNotification::severity, severity, MMS_Object_Module_1::Severity);
    ITU_T_OPTIONAL_DEFN(EventNotification::currentState, currentState, MMS_Object_Module_1::EC_State);
    ITU_T_HOLDERH_DEFN(EventNotification::transitionTime, transitionTime, MMS_Object_Module_1::EventTime);
    ITU_T_DEFAULTH_DEFN(EventNotification::notificationLost, notificationLost, bool);
    ITU_T_OPTIONAL_DEFN(EventNotification::alarmAcknowledgmentRule, alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule);
    ITU_T_OPTIONAL_DEFN(EventNotification::actionResult, actionResult, EventNotification::ActionResult_type);

    // choice CS-EventNotification

    ITU_T_CHOICES_DEFN(CS_EventNotification_impl::string, string, visiblestring_type, CS_EventNotification_impl_string);
    ITU_T_CHOICES_DEFN(CS_EventNotification_impl::index, index, int, CS_EventNotification_impl_index);
    ITU_T_CHOICES_DEFN(CS_EventNotification_impl::noEnhancement, noEnhancement, null_type, CS_EventNotification_impl_noEnhancement);

    // sequence AcknowledgeEventNotification-Request

    AcknowledgeEventNotification_Request::AcknowledgeEventNotification_Request() : eventEnrollmentName_(), acknowledgedState_(), timeOfAcknowledgedTransition_() {
    };

    AcknowledgeEventNotification_Request::AcknowledgeEventNotification_Request(const ObjectName& arg__eventEnrollmentName,
            const MMS_Object_Module_1::EC_State& arg__acknowledgedState,
            const MMS_Object_Module_1::EventTime& arg__timeOfAcknowledgedTransition) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    acknowledgedState_(arg__acknowledgedState),
    timeOfAcknowledgedTransition_(arg__timeOfAcknowledgedTransition) {
    };


    ITU_T_HOLDERH_DEFN(AcknowledgeEventNotification_Request::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_HOLDERH_DEFN(AcknowledgeEventNotification_Request::acknowledgedState, acknowledgedState, MMS_Object_Module_1::EC_State);
    ITU_T_HOLDERH_DEFN(AcknowledgeEventNotification_Request::timeOfAcknowledgedTransition, timeOfAcknowledgedTransition, MMS_Object_Module_1::EventTime);

    // sequence GetAlarmSummary-Request
    const uint8_t GetAlarmSummary_Request::acknowledgementFilter_not_acked = 0;
    const uint8_t GetAlarmSummary_Request::acknowledgementFilter_acked = 1;
    const uint8_t GetAlarmSummary_Request::acknowledgementFilter_all = 2;

    GetAlarmSummary_Request::GetAlarmSummary_Request() {
    };

    GetAlarmSummary_Request::GetAlarmSummary_Request(shared_ptr< bool> arg__enrollmentsOnly,
            shared_ptr< bool> arg__activeAlarmsOnly,
            shared_ptr< uint8_t> arg__acknowledgementFilter,
            shared_ptr< SeverityFilter_type> arg__severityFilter,
            shared_ptr< ObjectName> arg__continueAfter) :
    enrollmentsOnly_(arg__enrollmentsOnly),
    activeAlarmsOnly_(arg__activeAlarmsOnly),
    acknowledgementFilter_(arg__acknowledgementFilter),
    severityFilter_(arg__severityFilter),
    continueAfter_(arg__continueAfter) {
    };

    GetAlarmSummary_Request::SeverityFilter_type::SeverityFilter_type() : mostSevere_(), leastSevere_() {
    };

    GetAlarmSummary_Request::SeverityFilter_type::SeverityFilter_type(const Unsigned8& arg__mostSevere,
            const Unsigned8& arg__leastSevere) :
    mostSevere_(arg__mostSevere),
    leastSevere_(arg__leastSevere) {
    };


    ITU_T_HOLDERH_DEFN(GetAlarmSummary_Request::SeverityFilter_type::mostSevere, mostSevere, Unsigned8);
    ITU_T_HOLDERH_DEFN(GetAlarmSummary_Request::SeverityFilter_type::leastSevere, leastSevere, Unsigned8);

    const bool GetAlarmSummary_Request::enrollmentsOnly__default = true;

    const bool GetAlarmSummary_Request::activeAlarmsOnly__default = true;

    const uint8_t GetAlarmSummary_Request::acknowledgementFilter__default = 0;


    ITU_T_DEFAULTH_DEFN(GetAlarmSummary_Request::enrollmentsOnly, enrollmentsOnly, bool);
    ITU_T_DEFAULTH_DEFN(GetAlarmSummary_Request::activeAlarmsOnly, activeAlarmsOnly, bool);
    ITU_T_DEFAULTH_DEFN(GetAlarmSummary_Request::acknowledgementFilter, acknowledgementFilter, uint8_t);
    ITU_T_OPTIONAL_DEFN(GetAlarmSummary_Request::severityFilter, severityFilter, GetAlarmSummary_Request::SeverityFilter_type);
    ITU_T_OPTIONAL_DEFN(GetAlarmSummary_Request::continueAfter, continueAfter, ObjectName);

    // sequence GetAlarmSummary-Response

    GetAlarmSummary_Response::GetAlarmSummary_Response() : listOfAlarmSummary_() {
    };

    GetAlarmSummary_Response::GetAlarmSummary_Response(const ListOfAlarmSummary_type& arg__listOfAlarmSummary) :
    listOfAlarmSummary_(arg__listOfAlarmSummary) {
    };

    GetAlarmSummary_Response::GetAlarmSummary_Response(shared_ptr< ListOfAlarmSummary_type> arg__listOfAlarmSummary,
            shared_ptr< bool> arg__moreFollows) :
    listOfAlarmSummary_(arg__listOfAlarmSummary),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetAlarmSummary_Response::moreFollows__default = false;


    ITU_T_HOLDERH_DEFN(GetAlarmSummary_Response::listOfAlarmSummary, listOfAlarmSummary, GetAlarmSummary_Response::ListOfAlarmSummary_type);
    ITU_T_DEFAULTH_DEFN(GetAlarmSummary_Response::moreFollows, moreFollows, bool);

    // sequence AlarmSummary
    const uint8_t AlarmSummary::unacknowledgedState_none = 0;
    const uint8_t AlarmSummary::unacknowledgedState_active = 1;
    const uint8_t AlarmSummary::unacknowledgedState_idle = 2;
    const uint8_t AlarmSummary::unacknowledgedState_both = 3;

    AlarmSummary::AlarmSummary() : eventConditionName_(), severity_(), currentState_(), unacknowledgedState_() {
    };

    AlarmSummary::AlarmSummary(const ObjectName& arg__eventConditionName,
            const Unsigned8& arg__severity,
            const MMS_Object_Module_1::EC_State& arg__currentState,
            const uint8_t& arg__unacknowledgedState) :
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    unacknowledgedState_(arg__unacknowledgedState) {
    };

    AlarmSummary::AlarmSummary(shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< Unsigned8> arg__severity,
            shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            shared_ptr< uint8_t> arg__unacknowledgedState,
            shared_ptr< EN_Additional_Detail> arg__displayEnhancement,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle) :
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    unacknowledgedState_(arg__unacknowledgedState),
    displayEnhancement_(arg__displayEnhancement),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle) {
    };


    ITU_T_HOLDERH_DEFN(AlarmSummary::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(AlarmSummary::severity, severity, Unsigned8);
    ITU_T_HOLDERH_DEFN(AlarmSummary::currentState, currentState, MMS_Object_Module_1::EC_State);
    ITU_T_HOLDERH_DEFN(AlarmSummary::unacknowledgedState, unacknowledgedState, uint8_t);
    ITU_T_OPTIONAL_DEFN(AlarmSummary::displayEnhancement, displayEnhancement, EN_Additional_Detail);
    ITU_T_OPTIONAL_DEFN(AlarmSummary::timeOfLastTransitionToActive, timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
    ITU_T_OPTIONAL_DEFN(AlarmSummary::timeOfLastTransitionToIdle, timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);

    // choice EN-Additional-Detail

    ITU_T_CHOICES_DEFN(EN_Additional_Detail_impl::string, string, visiblestring_type, EN_Additional_Detail_impl_string);
    ITU_T_CHOICES_DEFN(EN_Additional_Detail_impl::index, index, int, EN_Additional_Detail_impl_index);
    ITU_T_CHOICES_DEFN(EN_Additional_Detail_impl::noEnhancement, noEnhancement, null_type, EN_Additional_Detail_impl_noEnhancement);

    // sequence GetAlarmEnrollmentSummary-Request
    const uint8_t GetAlarmEnrollmentSummary_Request::acknowledgementFilter_not_acked = 0;
    const uint8_t GetAlarmEnrollmentSummary_Request::acknowledgementFilter_acked = 1;
    const uint8_t GetAlarmEnrollmentSummary_Request::acknowledgementFilter_all = 2;

    GetAlarmEnrollmentSummary_Request::GetAlarmEnrollmentSummary_Request() {
    };

    GetAlarmEnrollmentSummary_Request::GetAlarmEnrollmentSummary_Request(shared_ptr< bool> arg__enrollmentsOnly,
            shared_ptr< bool> arg__activeAlarmsOnly,
            shared_ptr< uint8_t> arg__acknowledgementFilter,
            shared_ptr< SeverityFilter_type> arg__severityFilter,
            shared_ptr< ObjectName> arg__continueAfter) :
    enrollmentsOnly_(arg__enrollmentsOnly),
    activeAlarmsOnly_(arg__activeAlarmsOnly),
    acknowledgementFilter_(arg__acknowledgementFilter),
    severityFilter_(arg__severityFilter),
    continueAfter_(arg__continueAfter) {
    };

    GetAlarmEnrollmentSummary_Request::SeverityFilter_type::SeverityFilter_type() : mostSevere_(), leastSevere_() {
    };

    GetAlarmEnrollmentSummary_Request::SeverityFilter_type::SeverityFilter_type(const Unsigned8& arg__mostSevere,
            const Unsigned8& arg__leastSevere) :
    mostSevere_(arg__mostSevere),
    leastSevere_(arg__leastSevere) {
    };


    ITU_T_HOLDERH_DEFN(GetAlarmEnrollmentSummary_Request::SeverityFilter_type::mostSevere, mostSevere, Unsigned8);
    ITU_T_HOLDERH_DEFN(GetAlarmEnrollmentSummary_Request::SeverityFilter_type::leastSevere, leastSevere, Unsigned8);

    const bool GetAlarmEnrollmentSummary_Request::enrollmentsOnly__default = true;

    const bool GetAlarmEnrollmentSummary_Request::activeAlarmsOnly__default = true;

    const uint8_t GetAlarmEnrollmentSummary_Request::acknowledgementFilter__default = 0;


    ITU_T_DEFAULTH_DEFN(GetAlarmEnrollmentSummary_Request::enrollmentsOnly, enrollmentsOnly, bool);
    ITU_T_DEFAULTH_DEFN(GetAlarmEnrollmentSummary_Request::activeAlarmsOnly, activeAlarmsOnly, bool);
    ITU_T_DEFAULTH_DEFN(GetAlarmEnrollmentSummary_Request::acknowledgementFilter, acknowledgementFilter, uint8_t);
    ITU_T_OPTIONAL_DEFN(GetAlarmEnrollmentSummary_Request::severityFilter, severityFilter, GetAlarmEnrollmentSummary_Request::SeverityFilter_type);
    ITU_T_OPTIONAL_DEFN(GetAlarmEnrollmentSummary_Request::continueAfter, continueAfter, ObjectName);

    // sequence GetAlarmEnrollmentSummary-Response

    GetAlarmEnrollmentSummary_Response::GetAlarmEnrollmentSummary_Response() : listOfAlarmEnrollmentSummary_() {
    };

    GetAlarmEnrollmentSummary_Response::GetAlarmEnrollmentSummary_Response(const ListOfAlarmEnrollmentSummary_type& arg__listOfAlarmEnrollmentSummary) :
    listOfAlarmEnrollmentSummary_(arg__listOfAlarmEnrollmentSummary) {
    };

    GetAlarmEnrollmentSummary_Response::GetAlarmEnrollmentSummary_Response(shared_ptr< ListOfAlarmEnrollmentSummary_type> arg__listOfAlarmEnrollmentSummary,
            shared_ptr< bool> arg__moreFollows) :
    listOfAlarmEnrollmentSummary_(arg__listOfAlarmEnrollmentSummary),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetAlarmEnrollmentSummary_Response::moreFollows__default = false;


    ITU_T_HOLDERH_DEFN(GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary, listOfAlarmEnrollmentSummary, GetAlarmEnrollmentSummary_Response::ListOfAlarmEnrollmentSummary_type);
    ITU_T_DEFAULTH_DEFN(GetAlarmEnrollmentSummary_Response::moreFollows, moreFollows, bool);

    // sequence AlarmEnrollmentSummary

    AlarmEnrollmentSummary::AlarmEnrollmentSummary() : eventEnrollmentName_(), severity_(), currentState_(), alarmAcknowledgmentRule_() {
    };

    AlarmEnrollmentSummary::AlarmEnrollmentSummary(const ObjectName& arg__eventEnrollmentName,
            const Unsigned8& arg__severity,
            const MMS_Object_Module_1::EC_State& arg__currentState,
            const MMS_Object_Module_1::AlarmAckRule& arg__alarmAcknowledgmentRule) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule) {
    };

    AlarmEnrollmentSummary::AlarmEnrollmentSummary(shared_ptr< ObjectName> arg__eventEnrollmentName,
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
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeIdleAcknowledged) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    clientApplication_(arg__clientApplication),
    severity_(arg__severity),
    currentState_(arg__currentState),
    displayEnhancement_(arg__displayEnhancement),
    notificationLost_(arg__notificationLost),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    enrollmentState_(arg__enrollmentState),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeActiveAcknowledged_(arg__timeActiveAcknowledged),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle),
    timeIdleAcknowledged_(arg__timeIdleAcknowledged) {
    };

    const bool AlarmEnrollmentSummary::notificationLost__default = false;


    ITU_T_HOLDERH_DEFN(AlarmEnrollmentSummary::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::clientApplication, clientApplication, MMS_Environment_1::ApplicationReference);
    ITU_T_HOLDERH_DEFN(AlarmEnrollmentSummary::severity, severity, Unsigned8);
    ITU_T_HOLDERH_DEFN(AlarmEnrollmentSummary::currentState, currentState, MMS_Object_Module_1::EC_State);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::displayEnhancement, displayEnhancement, EN_Additional_Detail);
    ITU_T_DEFAULTH_DEFN(AlarmEnrollmentSummary::notificationLost, notificationLost, bool);
    ITU_T_HOLDERH_DEFN(AlarmEnrollmentSummary::alarmAcknowledgmentRule, alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::enrollmentState, enrollmentState, EE_State);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::timeOfLastTransitionToActive, timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::timeActiveAcknowledged, timeActiveAcknowledged, MMS_Object_Module_1::EventTime);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::timeOfLastTransitionToIdle, timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);
    ITU_T_OPTIONAL_DEFN(AlarmEnrollmentSummary::timeIdleAcknowledged, timeIdleAcknowledged, MMS_Object_Module_1::EventTime);

    // sequence AttachToEventCondition

    AttachToEventCondition::AttachToEventCondition() : eventEnrollmentName_(), eventConditionName_(), causingTransitions_() {
    };

    AttachToEventCondition::AttachToEventCondition(const ObjectName& arg__eventEnrollmentName,
            const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::Transitions& arg__causingTransitions) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    causingTransitions_(arg__causingTransitions) {
    };

    AttachToEventCondition::AttachToEventCondition(shared_ptr< ObjectName> arg__eventEnrollmentName,
            shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< MMS_Object_Module_1::Transitions> arg__causingTransitions,
            shared_ptr< Unsigned32> arg__acceptableDelay) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    causingTransitions_(arg__causingTransitions),
    acceptableDelay_(arg__acceptableDelay) {
    };


    ITU_T_HOLDERH_DEFN(AttachToEventCondition::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_HOLDERH_DEFN(AttachToEventCondition::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(AttachToEventCondition::causingTransitions, causingTransitions, MMS_Object_Module_1::Transitions);
    ITU_T_OPTIONAL_DEFN(AttachToEventCondition::acceptableDelay, acceptableDelay, Unsigned32);

    // sequence DefineEventCondition-Request

    DefineEventCondition_Request::DefineEventCondition_Request() : eventConditionName_(), classV_() {
    };

    DefineEventCondition_Request::DefineEventCondition_Request(const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::EC_Class& arg__classV) :
    eventConditionName_(arg__eventConditionName),
    classV_(arg__classV) {
    };

    DefineEventCondition_Request::DefineEventCondition_Request(shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< MMS_Object_Module_1::EC_Class> arg__classV,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< Unsigned8> arg__severity,
            shared_ptr< bool> arg__alarmSummaryReports,
            shared_ptr< VariableSpecification> arg__monitoredVariable,
            shared_ptr< Unsigned32> arg__evaluationInterval) :
    eventConditionName_(arg__eventConditionName),
    classV_(arg__classV),
    priority_(arg__priority),
    severity_(arg__severity),
    alarmSummaryReports_(arg__alarmSummaryReports),
    monitoredVariable_(arg__monitoredVariable),
    evaluationInterval_(arg__evaluationInterval) {
    };

    const MMS_Object_Module_1::Priority DefineEventCondition_Request::priority__default = MMS_Object_Module_1::Priority(64);

    const Unsigned8 DefineEventCondition_Request::severity__default = Unsigned8(64);


    ITU_T_HOLDERH_DEFN(DefineEventCondition_Request::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineEventCondition_Request::classV, classV, MMS_Object_Module_1::EC_Class);
    ITU_T_DEFAULTH_DEFN(DefineEventCondition_Request::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_DEFAULTH_DEFN(DefineEventCondition_Request::severity, severity, Unsigned8);
    ITU_T_OPTIONAL_DEFN(DefineEventCondition_Request::alarmSummaryReports, alarmSummaryReports, bool);
    ITU_T_OPTIONAL_DEFN(DefineEventCondition_Request::monitoredVariable, monitoredVariable, VariableSpecification);
    ITU_T_OPTIONAL_DEFN(DefineEventCondition_Request::evaluationInterval, evaluationInterval, Unsigned32);

    // choice CS-DefineEventCondition-Request

    ITU_T_CHOICES_DEFN(CS_DefineEventCondition_Request_impl::string, string, visiblestring_type, CS_DefineEventCondition_Request_impl_string);
    ITU_T_CHOICES_DEFN(CS_DefineEventCondition_Request_impl::index, index, int, CS_DefineEventCondition_Request_impl_index);
    ITU_T_CHOICES_DEFN(CS_DefineEventCondition_Request_impl::noEnhancement, noEnhancement, null_type, CS_DefineEventCondition_Request_impl_noEnhancement);

    // choice DeleteEventCondition-Request

    ITU_T_CHOICEC_DEFN(DeleteEventCondition_Request::specific, specific, DeleteEventCondition_Request::Specific_type, DeleteEventCondition_Request_specific);
    ITU_T_CHOICES_DEFN(DeleteEventCondition_Request::aa_specific, aa_specific, null_type, DeleteEventCondition_Request_aa_specific);
    ITU_T_CHOICES_DEFN(DeleteEventCondition_Request::domain, domain, Identifier, DeleteEventCondition_Request_domain);
    ITU_T_CHOICES_DEFN(DeleteEventCondition_Request::vmd, vmd, null_type, DeleteEventCondition_Request_vmd);

    // sequence GetEventConditionAttributes-Response

    GetEventConditionAttributes_Response::GetEventConditionAttributes_Response() : classV_() {
    };

    GetEventConditionAttributes_Response::GetEventConditionAttributes_Response(const MMS_Object_Module_1::EC_Class& arg__classV) :
    classV_(arg__classV) {
    };

    GetEventConditionAttributes_Response::GetEventConditionAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< MMS_Object_Module_1::EC_Class> arg__classV,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< Unsigned8> arg__severity,
            shared_ptr< bool> arg__alarmSummaryReports,
            shared_ptr< MonitoredVariable_type> arg__monitoredVariable,
            shared_ptr< Unsigned32> arg__evaluationInterval,
            shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    classV_(arg__classV),
    priority_(arg__priority),
    severity_(arg__severity),
    alarmSummaryReports_(arg__alarmSummaryReports),
    monitoredVariable_(arg__monitoredVariable),
    evaluationInterval_(arg__evaluationInterval),
    accessControlList_(arg__accessControlList) {
    };



    ITU_T_CHOICEC_DEFN(GetEventConditionAttributes_Response::MonitoredVariable_type::variableReference, variableReference, VariableSpecification, MonitoredVariable_type_variableReference);
    ITU_T_CHOICES_DEFN(GetEventConditionAttributes_Response::MonitoredVariable_type::undefined, undefined, null_type, MonitoredVariable_type_undefined);

    const bool GetEventConditionAttributes_Response::mmsDeletable__default = false;

    const MMS_Object_Module_1::Priority GetEventConditionAttributes_Response::priority__default = MMS_Object_Module_1::Priority(64);

    const Unsigned8 GetEventConditionAttributes_Response::severity__default = Unsigned8(64);

    const bool GetEventConditionAttributes_Response::alarmSummaryReports__default = false;


    ITU_T_DEFAULTH_DEFN(GetEventConditionAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetEventConditionAttributes_Response::classV, classV, MMS_Object_Module_1::EC_Class);
    ITU_T_DEFAULTH_DEFN(GetEventConditionAttributes_Response::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_DEFAULTH_DEFN(GetEventConditionAttributes_Response::severity, severity, Unsigned8);
    ITU_T_DEFAULTH_DEFN(GetEventConditionAttributes_Response::alarmSummaryReports, alarmSummaryReports, bool);
    ITU_T_OPTIONAL_DEFN(GetEventConditionAttributes_Response::monitoredVariable, monitoredVariable, GetEventConditionAttributes_Response::MonitoredVariable_type);
    ITU_T_OPTIONAL_DEFN(GetEventConditionAttributes_Response::evaluationInterval, evaluationInterval, Unsigned32);
    ITU_T_OPTIONAL_DEFN(GetEventConditionAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence CS-GetEventConditionAttributes-Response

    CS_GetEventConditionAttributes_Response::CS_GetEventConditionAttributes_Response() : displayEnhancement_() {
    };

    CS_GetEventConditionAttributes_Response::CS_GetEventConditionAttributes_Response(const DisplayEnhancement_type& arg__displayEnhancement) :
    displayEnhancement_(arg__displayEnhancement) {
    };

    CS_GetEventConditionAttributes_Response::CS_GetEventConditionAttributes_Response(shared_ptr< GroupPriorityOverride_type> arg__groupPriorityOverride,
            shared_ptr< ListOfReferencingECL_type> arg__listOfReferencingECL,
            shared_ptr< DisplayEnhancement_type> arg__displayEnhancement) :
    groupPriorityOverride_(arg__groupPriorityOverride),
    listOfReferencingECL_(arg__listOfReferencingECL),
    displayEnhancement_(arg__displayEnhancement) {
    };



    ITU_T_CHOICES_DEFN(CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::priority, priority, MMS_Object_Module_1::Priority, GroupPriorityOverride_type_priority);
    ITU_T_CHOICES_DEFN(CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::undefined, undefined, null_type, GroupPriorityOverride_type_undefined);



    ITU_T_CHOICES_DEFN(CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::string, string, visiblestring_type, DisplayEnhancement_type_string);
    ITU_T_CHOICES_DEFN(CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::index, index, int, DisplayEnhancement_type_index);
    ITU_T_CHOICES_DEFN(CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::noEnhancement, noEnhancement, null_type, DisplayEnhancement_type_noEnhancement);


    ITU_T_OPTIONAL_DEFN(CS_GetEventConditionAttributes_Response::groupPriorityOverride, groupPriorityOverride, CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type);
    ITU_T_OPTIONAL_DEFN(CS_GetEventConditionAttributes_Response::listOfReferencingECL, listOfReferencingECL, CS_GetEventConditionAttributes_Response::ListOfReferencingECL_type);
    ITU_T_HOLDERH_DEFN(CS_GetEventConditionAttributes_Response::displayEnhancement, displayEnhancement, CS_GetEventConditionAttributes_Response::DisplayEnhancement_type);

    // sequence ReportEventConditionStatus-Response

    ReportEventConditionStatus_Response::ReportEventConditionStatus_Response() : currentState_(), numberOfEventEnrollments_() {
    };

    ReportEventConditionStatus_Response::ReportEventConditionStatus_Response(const MMS_Object_Module_1::EC_State& arg__currentState,
            const Unsigned32& arg__numberOfEventEnrollments) :
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments) {
    };

    ReportEventConditionStatus_Response::ReportEventConditionStatus_Response(shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            shared_ptr< Unsigned32> arg__numberOfEventEnrollments,
            shared_ptr< bool> arg__enabled,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle) :
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments),
    enabled_(arg__enabled),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle) {
    };


    ITU_T_HOLDERH_DEFN(ReportEventConditionStatus_Response::currentState, currentState, MMS_Object_Module_1::EC_State);
    ITU_T_HOLDERH_DEFN(ReportEventConditionStatus_Response::numberOfEventEnrollments, numberOfEventEnrollments, Unsigned32);
    ITU_T_OPTIONAL_DEFN(ReportEventConditionStatus_Response::enabled, enabled, bool);
    ITU_T_OPTIONAL_DEFN(ReportEventConditionStatus_Response::timeOfLastTransitionToActive, timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
    ITU_T_OPTIONAL_DEFN(ReportEventConditionStatus_Response::timeOfLastTransitionToIdle, timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);

    // sequence AlterEventConditionMonitoring-Request

    AlterEventConditionMonitoring_Request::AlterEventConditionMonitoring_Request() : eventConditionName_() {
    };

    AlterEventConditionMonitoring_Request::AlterEventConditionMonitoring_Request(const ObjectName& arg__eventConditionName) :
    eventConditionName_(arg__eventConditionName) {
    };

    AlterEventConditionMonitoring_Request::AlterEventConditionMonitoring_Request(shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< bool> arg__enabled,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< bool> arg__alarmSummaryReports,
            shared_ptr< Unsigned32> arg__evaluationInterval) :
    eventConditionName_(arg__eventConditionName),
    enabled_(arg__enabled),
    priority_(arg__priority),
    alarmSummaryReports_(arg__alarmSummaryReports),
    evaluationInterval_(arg__evaluationInterval) {
    };


    ITU_T_HOLDERH_DEFN(AlterEventConditionMonitoring_Request::eventConditionName, eventConditionName, ObjectName);
    ITU_T_OPTIONAL_DEFN(AlterEventConditionMonitoring_Request::enabled, enabled, bool);
    ITU_T_OPTIONAL_DEFN(AlterEventConditionMonitoring_Request::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_OPTIONAL_DEFN(AlterEventConditionMonitoring_Request::alarmSummaryReports, alarmSummaryReports, bool);
    ITU_T_OPTIONAL_DEFN(AlterEventConditionMonitoring_Request::evaluationInterval, evaluationInterval, Unsigned32);

    // sequence CS-AlterEventConditionMonitoring-Request

    CS_AlterEventConditionMonitoring_Request::CS_AlterEventConditionMonitoring_Request() {
    };

    CS_AlterEventConditionMonitoring_Request::CS_AlterEventConditionMonitoring_Request(shared_ptr< ChangeDisplay_type> arg__changeDisplay) :
    changeDisplay_(arg__changeDisplay) {
    };



    ITU_T_CHOICES_DEFN(CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::string, string, visiblestring_type, ChangeDisplay_type_string);
    ITU_T_CHOICES_DEFN(CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::index, index, int, ChangeDisplay_type_index);
    ITU_T_CHOICES_DEFN(CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::noEnhancement, noEnhancement, null_type, ChangeDisplay_type_noEnhancement);


    ITU_T_OPTIONAL_DEFN(CS_AlterEventConditionMonitoring_Request::changeDisplay, changeDisplay, CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type);

    // sequence DefineEventAction-Request

    DefineEventAction_Request::DefineEventAction_Request() : eventActionName_(), confirmedServiceRequest_() {
    };

    DefineEventAction_Request::DefineEventAction_Request(const ObjectName& arg__eventActionName,
            const ConfirmedServiceRequest& arg__confirmedServiceRequest) :
    eventActionName_(arg__eventActionName),
    confirmedServiceRequest_(arg__confirmedServiceRequest) {
    };

    DefineEventAction_Request::DefineEventAction_Request(shared_ptr< ObjectName> arg__eventActionName,
            shared_ptr< ListOfModifier_type> arg__listOfModifier,
            shared_ptr< ConfirmedServiceRequest> arg__confirmedServiceRequest,
            shared_ptr< Request_Detail> arg__cs_extension) :
    eventActionName_(arg__eventActionName),
    listOfModifier_(arg__listOfModifier),
    confirmedServiceRequest_(arg__confirmedServiceRequest),
    cs_extension_(arg__cs_extension) {
    };


    ITU_T_HOLDERH_DEFN(DefineEventAction_Request::eventActionName, eventActionName, ObjectName);
    ITU_T_OPTIONAL_DEFN(DefineEventAction_Request::listOfModifier, listOfModifier, DefineEventAction_Request::ListOfModifier_type);
    ITU_T_HOLDERH_DEFN(DefineEventAction_Request::confirmedServiceRequest, confirmedServiceRequest, ConfirmedServiceRequest);
    ITU_T_OPTIONAL_DEFN(DefineEventAction_Request::cs_extension, cs_extension, Request_Detail);

    // choice DeleteEventAction-Request

    ITU_T_CHOICEC_DEFN(DeleteEventAction_Request::specific, specific, DeleteEventAction_Request::Specific_type, DeleteEventAction_Request_specific);
    ITU_T_CHOICES_DEFN(DeleteEventAction_Request::aa_specific, aa_specific, null_type, DeleteEventAction_Request_aa_specific);
    ITU_T_CHOICES_DEFN(DeleteEventAction_Request::domain, domain, Identifier, DeleteEventAction_Request_domain);
    ITU_T_CHOICES_DEFN(DeleteEventAction_Request::vmd, vmd, null_type, DeleteEventAction_Request_vmd);

    // sequence GetEventActionAttributes-Response

    GetEventActionAttributes_Response::GetEventActionAttributes_Response() : listOfModifier_(), confirmedServiceRequest_() {
    };

    GetEventActionAttributes_Response::GetEventActionAttributes_Response(const ListOfModifier_type& arg__listOfModifier,
            const ConfirmedServiceRequest& arg__confirmedServiceRequest) :
    listOfModifier_(arg__listOfModifier),
    confirmedServiceRequest_(arg__confirmedServiceRequest) {
    };

    GetEventActionAttributes_Response::GetEventActionAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< ListOfModifier_type> arg__listOfModifier,
            shared_ptr< ConfirmedServiceRequest> arg__confirmedServiceRequest,
            shared_ptr< Request_Detail> arg__cs_extension,
            shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    listOfModifier_(arg__listOfModifier),
    confirmedServiceRequest_(arg__confirmedServiceRequest),
    cs_extension_(arg__cs_extension),
    accessControlList_(arg__accessControlList) {
    };

    const bool GetEventActionAttributes_Response::mmsDeletable__default = false;


    ITU_T_DEFAULTH_DEFN(GetEventActionAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetEventActionAttributes_Response::listOfModifier, listOfModifier, GetEventActionAttributes_Response::ListOfModifier_type);
    ITU_T_HOLDERH_DEFN(GetEventActionAttributes_Response::confirmedServiceRequest, confirmedServiceRequest, ConfirmedServiceRequest);
    ITU_T_OPTIONAL_DEFN(GetEventActionAttributes_Response::cs_extension, cs_extension, Request_Detail);
    ITU_T_OPTIONAL_DEFN(GetEventActionAttributes_Response::accessControlList, accessControlList, Identifier);

    // sequence DefineEventEnrollment-Request

    DefineEventEnrollment_Request::DefineEventEnrollment_Request() : eventEnrollmentName_(), eventConditionName_(), eventConditionTransitions_(), alarmAcknowledgmentRule_() {
    };

    DefineEventEnrollment_Request::DefineEventEnrollment_Request(const ObjectName& arg__eventEnrollmentName,
            const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::Transitions& arg__eventConditionTransitions,
            const MMS_Object_Module_1::AlarmAckRule& arg__alarmAcknowledgmentRule) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    eventConditionTransitions_(arg__eventConditionTransitions),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule) {
    };

    DefineEventEnrollment_Request::DefineEventEnrollment_Request(shared_ptr< ObjectName> arg__eventEnrollmentName,
            shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
            shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            shared_ptr< ObjectName> arg__eventActionName,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    eventConditionTransitions_(arg__eventConditionTransitions),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    eventActionName_(arg__eventActionName),
    clientApplication_(arg__clientApplication) {
    };


    ITU_T_HOLDERH_DEFN(DefineEventEnrollment_Request::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineEventEnrollment_Request::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineEventEnrollment_Request::eventConditionTransitions, eventConditionTransitions, MMS_Object_Module_1::Transitions);
    ITU_T_HOLDERH_DEFN(DefineEventEnrollment_Request::alarmAcknowledgmentRule, alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule);
    ITU_T_OPTIONAL_DEFN(DefineEventEnrollment_Request::eventActionName, eventActionName, ObjectName);
    ITU_T_OPTIONAL_DEFN(DefineEventEnrollment_Request::clientApplication, clientApplication, MMS_Environment_1::ApplicationReference);

    // choice CS-DefineEventEnrollment-Request

    ITU_T_CHOICES_DEFN(CS_DefineEventEnrollment_Request_impl::string, string, visiblestring_type, CS_DefineEventEnrollment_Request_impl_string);
    ITU_T_CHOICES_DEFN(CS_DefineEventEnrollment_Request_impl::index, index, int, CS_DefineEventEnrollment_Request_impl_index);
    ITU_T_CHOICES_DEFN(CS_DefineEventEnrollment_Request_impl::noEnhancement, noEnhancement, null_type, CS_DefineEventEnrollment_Request_impl_noEnhancement);

    // choice DeleteEventEnrollment-Request

    ITU_T_CHOICEC_DEFN(DeleteEventEnrollment_Request::specific, specific, DeleteEventEnrollment_Request::Specific_type, DeleteEventEnrollment_Request_specific);
    ITU_T_CHOICEC_DEFN(DeleteEventEnrollment_Request::ec, ec, ObjectName, DeleteEventEnrollment_Request_ec);
    ITU_T_CHOICEC_DEFN(DeleteEventEnrollment_Request::ea, ea, ObjectName, DeleteEventEnrollment_Request_ea);

    // sequence GetEventEnrollmentAttributes-Request
    const uint8_t GetEventEnrollmentAttributes_Request::scopeOfRequest_specific = 0;
    const uint8_t GetEventEnrollmentAttributes_Request::scopeOfRequest_client = 1;
    const uint8_t GetEventEnrollmentAttributes_Request::scopeOfRequest_ec = 2;
    const uint8_t GetEventEnrollmentAttributes_Request::scopeOfRequest_ea = 3;

    GetEventEnrollmentAttributes_Request::GetEventEnrollmentAttributes_Request() {
    };

    GetEventEnrollmentAttributes_Request::GetEventEnrollmentAttributes_Request(shared_ptr< uint8_t> arg__scopeOfRequest,
            shared_ptr< EventEnrollmentNames_type> arg__eventEnrollmentNames,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< ObjectName> arg__eventActionName,
            shared_ptr< ObjectName> arg__continueAfter) :
    scopeOfRequest_(arg__scopeOfRequest),
    eventEnrollmentNames_(arg__eventEnrollmentNames),
    clientApplication_(arg__clientApplication),
    eventConditionName_(arg__eventConditionName),
    eventActionName_(arg__eventActionName),
    continueAfter_(arg__continueAfter) {
    };

    const uint8_t GetEventEnrollmentAttributes_Request::scopeOfRequest__default = 1;


    ITU_T_DEFAULTH_DEFN(GetEventEnrollmentAttributes_Request::scopeOfRequest, scopeOfRequest, uint8_t);
    ITU_T_OPTIONAL_DEFN(GetEventEnrollmentAttributes_Request::eventEnrollmentNames, eventEnrollmentNames, GetEventEnrollmentAttributes_Request::EventEnrollmentNames_type);
    ITU_T_OPTIONAL_DEFN(GetEventEnrollmentAttributes_Request::clientApplication, clientApplication, MMS_Environment_1::ApplicationReference);
    ITU_T_OPTIONAL_DEFN(GetEventEnrollmentAttributes_Request::eventConditionName, eventConditionName, ObjectName);
    ITU_T_OPTIONAL_DEFN(GetEventEnrollmentAttributes_Request::eventActionName, eventActionName, ObjectName);
    ITU_T_OPTIONAL_DEFN(GetEventEnrollmentAttributes_Request::continueAfter, continueAfter, ObjectName);

    // sequence GetEventEnrollmentAttributes-Response

    GetEventEnrollmentAttributes_Response::GetEventEnrollmentAttributes_Response() : listOfEEAttributes_() {
    };

    GetEventEnrollmentAttributes_Response::GetEventEnrollmentAttributes_Response(const ListOfEEAttributes_type& arg__listOfEEAttributes) :
    listOfEEAttributes_(arg__listOfEEAttributes) {
    };

    GetEventEnrollmentAttributes_Response::GetEventEnrollmentAttributes_Response(shared_ptr< ListOfEEAttributes_type> arg__listOfEEAttributes,
            shared_ptr< bool> arg__moreFollows) :
    listOfEEAttributes_(arg__listOfEEAttributes),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetEventEnrollmentAttributes_Response::moreFollows__default = false;


    ITU_T_HOLDERH_DEFN(GetEventEnrollmentAttributes_Response::listOfEEAttributes, listOfEEAttributes, GetEventEnrollmentAttributes_Response::ListOfEEAttributes_type);
    ITU_T_DEFAULTH_DEFN(GetEventEnrollmentAttributes_Response::moreFollows, moreFollows, bool);

    // sequence EEAttributes

    EEAttributes::EEAttributes() : eventEnrollmentName_(), eventConditionName_(), enrollmentClass_(), displayEnhancement_() {
    };

    EEAttributes::EEAttributes(const ObjectName& arg__eventEnrollmentName,
            const EventConditionName_type& arg__eventConditionName,
            const MMS_Object_Module_1::EE_Class& arg__enrollmentClass,
            const DisplayEnhancement_type& arg__displayEnhancement) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    enrollmentClass_(arg__enrollmentClass),
    displayEnhancement_(arg__displayEnhancement) {
    };

    EEAttributes::EEAttributes(shared_ptr< ObjectName> arg__eventEnrollmentName,
            shared_ptr< EventConditionName_type> arg__eventConditionName,
            shared_ptr< EventActionName_type> arg__eventActionName,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< MMS_Object_Module_1::EE_Class> arg__enrollmentClass,
            shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
            shared_ptr< Unsigned32> arg__invokeID,
            shared_ptr< Unsigned32> arg__remainingAcceptableDelay,
            shared_ptr< DisplayEnhancement_type> arg__displayEnhancement) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    eventActionName_(arg__eventActionName),
    clientApplication_(arg__clientApplication),
    mmsDeletable_(arg__mmsDeletable),
    enrollmentClass_(arg__enrollmentClass),
    duration_(arg__duration),
    invokeID_(arg__invokeID),
    remainingAcceptableDelay_(arg__remainingAcceptableDelay),
    displayEnhancement_(arg__displayEnhancement) {
    };



    ITU_T_CHOICEC_DEFN(EEAttributes::EventConditionName_type::eventCondition, eventCondition, ObjectName, EventConditionName_type_eventCondition);
    ITU_T_CHOICES_DEFN(EEAttributes::EventConditionName_type::undefined, undefined, null_type, EventConditionName_type_undefined);



    ITU_T_CHOICEC_DEFN(EEAttributes::EventActionName_type::eventAction, eventAction, ObjectName, EventActionName_type_eventAction);
    ITU_T_CHOICES_DEFN(EEAttributes::EventActionName_type::undefined, undefined, null_type, EventActionName_type_undefined);



    ITU_T_CHOICES_DEFN(EEAttributes::DisplayEnhancement_type::string, string, visiblestring_type, DisplayEnhancement_type_string);
    ITU_T_CHOICES_DEFN(EEAttributes::DisplayEnhancement_type::index, index, int, DisplayEnhancement_type_index);
    ITU_T_CHOICES_DEFN(EEAttributes::DisplayEnhancement_type::noEnhancement, noEnhancement, null_type, DisplayEnhancement_type_noEnhancement);

    const bool EEAttributes::mmsDeletable__default = false;

    const MMS_Object_Module_1::EE_Duration EEAttributes::duration__default = MMS_Object_Module_1::EE_Duration(0);


    ITU_T_HOLDERH_DEFN(EEAttributes::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_HOLDERH_DEFN(EEAttributes::eventConditionName, eventConditionName, EEAttributes::EventConditionName_type);
    ITU_T_OPTIONAL_DEFN(EEAttributes::eventActionName, eventActionName, EEAttributes::EventActionName_type);
    ITU_T_OPTIONAL_DEFN(EEAttributes::clientApplication, clientApplication, MMS_Environment_1::ApplicationReference);
    ITU_T_DEFAULTH_DEFN(EEAttributes::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(EEAttributes::enrollmentClass, enrollmentClass, MMS_Object_Module_1::EE_Class);
    ITU_T_DEFAULTH_DEFN(EEAttributes::duration, duration, MMS_Object_Module_1::EE_Duration);
    ITU_T_OPTIONAL_DEFN(EEAttributes::invokeID, invokeID, Unsigned32);
    ITU_T_OPTIONAL_DEFN(EEAttributes::remainingAcceptableDelay, remainingAcceptableDelay, Unsigned32);
    ITU_T_HOLDERH_DEFN(EEAttributes::displayEnhancement, displayEnhancement, EEAttributes::DisplayEnhancement_type);

    // sequence ReportEventEnrollmentStatus-Response

    ReportEventEnrollmentStatus_Response::ReportEventEnrollmentStatus_Response() : eventConditionTransitions_(), duration_(), currentState_() {
    };

    ReportEventEnrollmentStatus_Response::ReportEventEnrollmentStatus_Response(const MMS_Object_Module_1::Transitions& arg__eventConditionTransitions,
            const MMS_Object_Module_1::EE_Duration& arg__duration,
            const EE_State& arg__currentState) :
    eventConditionTransitions_(arg__eventConditionTransitions),
    duration_(arg__duration),
    currentState_(arg__currentState) {
    };

    ReportEventEnrollmentStatus_Response::ReportEventEnrollmentStatus_Response(shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
            shared_ptr< bool> arg__notificationLost,
            shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
            shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            shared_ptr< EE_State> arg__currentState) :
    eventConditionTransitions_(arg__eventConditionTransitions),
    notificationLost_(arg__notificationLost),
    duration_(arg__duration),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    currentState_(arg__currentState) {
    };

    const bool ReportEventEnrollmentStatus_Response::notificationLost__default = false;


    ITU_T_HOLDERH_DEFN(ReportEventEnrollmentStatus_Response::eventConditionTransitions, eventConditionTransitions, MMS_Object_Module_1::Transitions);
    ITU_T_DEFAULTH_DEFN(ReportEventEnrollmentStatus_Response::notificationLost, notificationLost, bool);
    ITU_T_HOLDERH_DEFN(ReportEventEnrollmentStatus_Response::duration, duration, MMS_Object_Module_1::EE_Duration);
    ITU_T_OPTIONAL_DEFN(ReportEventEnrollmentStatus_Response::alarmAcknowledgmentRule, alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule);
    ITU_T_HOLDERH_DEFN(ReportEventEnrollmentStatus_Response::currentState, currentState, EE_State);

    // sequence AlterEventEnrollment-Request

    AlterEventEnrollment_Request::AlterEventEnrollment_Request() : eventEnrollmentName_() {
    };

    AlterEventEnrollment_Request::AlterEventEnrollment_Request(const ObjectName& arg__eventEnrollmentName) :
    eventEnrollmentName_(arg__eventEnrollmentName) {
    };

    AlterEventEnrollment_Request::AlterEventEnrollment_Request(shared_ptr< ObjectName> arg__eventEnrollmentName,
            shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
            shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionTransitions_(arg__eventConditionTransitions),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule) {
    };


    ITU_T_HOLDERH_DEFN(AlterEventEnrollment_Request::eventEnrollmentName, eventEnrollmentName, ObjectName);
    ITU_T_OPTIONAL_DEFN(AlterEventEnrollment_Request::eventConditionTransitions, eventConditionTransitions, MMS_Object_Module_1::Transitions);
    ITU_T_OPTIONAL_DEFN(AlterEventEnrollment_Request::alarmAcknowledgmentRule, alarmAcknowledgmentRule, MMS_Object_Module_1::AlarmAckRule);

    // sequence AlterEventEnrollment-Response

    AlterEventEnrollment_Response::AlterEventEnrollment_Response() : currentState_(), transitionTime_() {
    };

    AlterEventEnrollment_Response::AlterEventEnrollment_Response(const CurrentState_type& arg__currentState,
            const MMS_Object_Module_1::EventTime& arg__transitionTime) :
    currentState_(arg__currentState),
    transitionTime_(arg__transitionTime) {
    };



    ITU_T_CHOICES_DEFN(AlterEventEnrollment_Response::CurrentState_type::state, state, EE_State, CurrentState_type_state);
    ITU_T_CHOICES_DEFN(AlterEventEnrollment_Response::CurrentState_type::undefined, undefined, null_type, CurrentState_type_undefined);


    ITU_T_HOLDERH_DEFN(AlterEventEnrollment_Response::currentState, currentState, AlterEventEnrollment_Response::CurrentState_type);
    ITU_T_HOLDERH_DEFN(AlterEventEnrollment_Response::transitionTime, transitionTime, MMS_Object_Module_1::EventTime);

    // sequence CS-AlterEventEnrollment-Request

    CS_AlterEventEnrollment_Request::CS_AlterEventEnrollment_Request() {
    };

    CS_AlterEventEnrollment_Request::CS_AlterEventEnrollment_Request(shared_ptr< ChangeDisplay_type> arg__changeDisplay) :
    changeDisplay_(arg__changeDisplay) {
    };



    ITU_T_CHOICES_DEFN(CS_AlterEventEnrollment_Request::ChangeDisplay_type::string, string, visiblestring_type, ChangeDisplay_type_string);
    ITU_T_CHOICES_DEFN(CS_AlterEventEnrollment_Request::ChangeDisplay_type::index, index, int, ChangeDisplay_type_index);
    ITU_T_CHOICES_DEFN(CS_AlterEventEnrollment_Request::ChangeDisplay_type::noEnhancement, noEnhancement, null_type, ChangeDisplay_type_noEnhancement);


    ITU_T_OPTIONAL_DEFN(CS_AlterEventEnrollment_Request::changeDisplay, changeDisplay, CS_AlterEventEnrollment_Request::ChangeDisplay_type);

    // sequence DefineEventConditionList-Request

    DefineEventConditionList_Request::DefineEventConditionList_Request() : eventConditionListName_(), listOfEventConditionName_() {
    };

    DefineEventConditionList_Request::DefineEventConditionList_Request(const ObjectName& arg__eventConditionListName,
            const ListOfEventConditionName_type& arg__listOfEventConditionName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName) {
    };

    DefineEventConditionList_Request::DefineEventConditionList_Request(shared_ptr< ObjectName> arg__eventConditionListName,
            shared_ptr< ListOfEventConditionName_type> arg__listOfEventConditionName,
            shared_ptr< ListOfEventConditionListName_type> arg__listOfEventConditionListName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };


    ITU_T_HOLDERH_DEFN(DefineEventConditionList_Request::eventConditionListName, eventConditionListName, ObjectName);
    ITU_T_HOLDERH_DEFN(DefineEventConditionList_Request::listOfEventConditionName, listOfEventConditionName, DefineEventConditionList_Request::ListOfEventConditionName_type);
    ITU_T_OPTIONAL_DEFN(DefineEventConditionList_Request::listOfEventConditionListName, listOfEventConditionListName, DefineEventConditionList_Request::ListOfEventConditionListName_type);

    // sequence AddEventConditionListReference-Request

    AddEventConditionListReference_Request::AddEventConditionListReference_Request() : eventConditionListName_(), listOfEventConditionName_() {
    };

    AddEventConditionListReference_Request::AddEventConditionListReference_Request(const ObjectName& arg__eventConditionListName,
            const ListOfEventConditionName_type& arg__listOfEventConditionName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName) {
    };

    AddEventConditionListReference_Request::AddEventConditionListReference_Request(shared_ptr< ObjectName> arg__eventConditionListName,
            shared_ptr< ListOfEventConditionName_type> arg__listOfEventConditionName,
            shared_ptr< ListOfEventConditionListName_type> arg__listOfEventConditionListName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };


    ITU_T_HOLDERH_DEFN(AddEventConditionListReference_Request::eventConditionListName, eventConditionListName, ObjectName);
    ITU_T_HOLDERH_DEFN(AddEventConditionListReference_Request::listOfEventConditionName, listOfEventConditionName, AddEventConditionListReference_Request::ListOfEventConditionName_type);
    ITU_T_OPTIONAL_DEFN(AddEventConditionListReference_Request::listOfEventConditionListName, listOfEventConditionListName, AddEventConditionListReference_Request::ListOfEventConditionListName_type);

    // sequence RemoveEventConditionListReference-Request

    RemoveEventConditionListReference_Request::RemoveEventConditionListReference_Request() : eventConditionListName_(), listOfEventConditionName_(), listOfEventConditionListName_() {
    };

    RemoveEventConditionListReference_Request::RemoveEventConditionListReference_Request(const ObjectName& arg__eventConditionListName,
            const ListOfEventConditionName_type& arg__listOfEventConditionName,
            const ListOfEventConditionListName_type& arg__listOfEventConditionListName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };


    ITU_T_HOLDERH_DEFN(RemoveEventConditionListReference_Request::eventConditionListName, eventConditionListName, ObjectName);
    ITU_T_HOLDERH_DEFN(RemoveEventConditionListReference_Request::listOfEventConditionName, listOfEventConditionName, RemoveEventConditionListReference_Request::ListOfEventConditionName_type);
    ITU_T_HOLDERH_DEFN(RemoveEventConditionListReference_Request::listOfEventConditionListName, listOfEventConditionListName, RemoveEventConditionListReference_Request::ListOfEventConditionListName_type);

    // choice RemoveEventConditionListReference-Error

    ITU_T_CHOICEC_DEFN(RemoveEventConditionListReference_Error::eventCondition, eventCondition, ObjectName, RemoveEventConditionListReference_Error_eventCondition);
    ITU_T_CHOICEC_DEFN(RemoveEventConditionListReference_Error::eventConditionList, eventConditionList, ObjectName, RemoveEventConditionListReference_Error_eventConditionList);

    // sequence GetEventConditionListAttributes-Response

    GetEventConditionListAttributes_Response::GetEventConditionListAttributes_Response() : listOfEventConditionName_() {
    };

    GetEventConditionListAttributes_Response::GetEventConditionListAttributes_Response(const ListOfEventConditionName_type& arg__listOfEventConditionName) :
    listOfEventConditionName_(arg__listOfEventConditionName) {
    };

    GetEventConditionListAttributes_Response::GetEventConditionListAttributes_Response(shared_ptr< ListOfEventConditionName_type> arg__listOfEventConditionName,
            shared_ptr< ListOfEventConditionListName_type> arg__listOfEventConditionListName) :
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };


    ITU_T_HOLDERH_DEFN(GetEventConditionListAttributes_Response::listOfEventConditionName, listOfEventConditionName, GetEventConditionListAttributes_Response::ListOfEventConditionName_type);
    ITU_T_OPTIONAL_DEFN(GetEventConditionListAttributes_Response::listOfEventConditionListName, listOfEventConditionListName, GetEventConditionListAttributes_Response::ListOfEventConditionListName_type);

    // sequence ReportEventConditionListStatus-Request

    ReportEventConditionListStatus_Request::ReportEventConditionListStatus_Request() : eventConditionListName_() {
    };

    ReportEventConditionListStatus_Request::ReportEventConditionListStatus_Request(const ObjectName& arg__eventConditionListName) :
    eventConditionListName_(arg__eventConditionListName) {
    };

    ReportEventConditionListStatus_Request::ReportEventConditionListStatus_Request(shared_ptr< ObjectName> arg__eventConditionListName,
            shared_ptr< Identifier> arg__continueAfter) :
    eventConditionListName_(arg__eventConditionListName),
    continueAfter_(arg__continueAfter) {
    };


    ITU_T_HOLDERH_DEFN(ReportEventConditionListStatus_Request::eventConditionListName, eventConditionListName, ObjectName);
    ITU_T_OPTIONAL_DEFN(ReportEventConditionListStatus_Request::continueAfter, continueAfter, Identifier);

    // sequence ReportEventConditionListStatus-Response

    ReportEventConditionListStatus_Response::ReportEventConditionListStatus_Response() : listOfEventConditionStatus_() {
    };

    ReportEventConditionListStatus_Response::ReportEventConditionListStatus_Response(const ListOfEventConditionStatus_type& arg__listOfEventConditionStatus) :
    listOfEventConditionStatus_(arg__listOfEventConditionStatus) {
    };

    ReportEventConditionListStatus_Response::ReportEventConditionListStatus_Response(shared_ptr< ListOfEventConditionStatus_type> arg__listOfEventConditionStatus,
            shared_ptr< bool> arg__moreFollows) :
    listOfEventConditionStatus_(arg__listOfEventConditionStatus),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReportEventConditionListStatus_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(ReportEventConditionListStatus_Response::listOfEventConditionStatus, listOfEventConditionStatus, ReportEventConditionListStatus_Response::ListOfEventConditionStatus_type);
    ITU_T_DEFAULTH_DEFN(ReportEventConditionListStatus_Response::moreFollows, moreFollows, bool);

    // sequence EventConditionStatus

    EventConditionStatus::EventConditionStatus() : eventConditionName_(), currentState_(), numberOfEventEnrollments_() {
    };

    EventConditionStatus::EventConditionStatus(const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::EC_State& arg__currentState,
            const Unsigned32& arg__numberOfEventEnrollments) :
    eventConditionName_(arg__eventConditionName),
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments) {
    };

    EventConditionStatus::EventConditionStatus(shared_ptr< ObjectName> arg__eventConditionName,
            shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            shared_ptr< Unsigned32> arg__numberOfEventEnrollments,
            shared_ptr< bool> arg__enabled,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle) :
    eventConditionName_(arg__eventConditionName),
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments),
    enabled_(arg__enabled),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle) {
    };


    ITU_T_HOLDERH_DEFN(EventConditionStatus::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(EventConditionStatus::currentState, currentState, MMS_Object_Module_1::EC_State);
    ITU_T_HOLDERH_DEFN(EventConditionStatus::numberOfEventEnrollments, numberOfEventEnrollments, Unsigned32);
    ITU_T_OPTIONAL_DEFN(EventConditionStatus::enabled, enabled, bool);
    ITU_T_OPTIONAL_DEFN(EventConditionStatus::timeOfLastTransitionToActive, timeOfLastTransitionToActive, MMS_Object_Module_1::EventTime);
    ITU_T_OPTIONAL_DEFN(EventConditionStatus::timeOfLastTransitionToIdle, timeOfLastTransitionToIdle, MMS_Object_Module_1::EventTime);

    // sequence AlterEventConditionListMonitoring-Request

    AlterEventConditionListMonitoring_Request::AlterEventConditionListMonitoring_Request() : eventConditionListName_(), enabled_() {
    };

    AlterEventConditionListMonitoring_Request::AlterEventConditionListMonitoring_Request(const ObjectName& arg__eventConditionListName,
            const bool& arg__enabled) :
    eventConditionListName_(arg__eventConditionListName),
    enabled_(arg__enabled) {
    };

    AlterEventConditionListMonitoring_Request::AlterEventConditionListMonitoring_Request(shared_ptr< ObjectName> arg__eventConditionListName,
            shared_ptr< bool> arg__enabled,
            shared_ptr< PriorityChange_type> arg__priorityChange) :
    eventConditionListName_(arg__eventConditionListName),
    enabled_(arg__enabled),
    priorityChange_(arg__priorityChange) {
    };



    ITU_T_CHOICES_DEFN(AlterEventConditionListMonitoring_Request::PriorityChange_type::priorityValue, priorityValue, int, PriorityChange_type_priorityValue);
    ITU_T_CHOICES_DEFN(AlterEventConditionListMonitoring_Request::PriorityChange_type::priorityReset, priorityReset, null_type, PriorityChange_type_priorityReset);


    ITU_T_HOLDERH_DEFN(AlterEventConditionListMonitoring_Request::eventConditionListName, eventConditionListName, ObjectName);
    ITU_T_HOLDERH_DEFN(AlterEventConditionListMonitoring_Request::enabled, enabled, bool);
    ITU_T_OPTIONAL_DEFN(AlterEventConditionListMonitoring_Request::priorityChange, priorityChange, AlterEventConditionListMonitoring_Request::PriorityChange_type);

    // sequence ReadJournal-Request

    ReadJournal_Request::ReadJournal_Request() : journalName_() {
    };

    ReadJournal_Request::ReadJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };

    ReadJournal_Request::ReadJournal_Request(shared_ptr< ObjectName> arg__journalName,
            shared_ptr< RangeStartSpecification_type> arg__rangeStartSpecification,
            shared_ptr< RangeStopSpecification_type> arg__rangeStopSpecification,
            shared_ptr< ListOfVariables_type> arg__listOfVariables,
            shared_ptr< EntryToStartAfter_type> arg__entryToStartAfter) :
    journalName_(arg__journalName),
    rangeStartSpecification_(arg__rangeStartSpecification),
    rangeStopSpecification_(arg__rangeStopSpecification),
    listOfVariables_(arg__listOfVariables),
    entryToStartAfter_(arg__entryToStartAfter) {
    };



    ITU_T_CHOICES_DEFN(ReadJournal_Request::RangeStartSpecification_type::startingTime, startingTime, TimeOfDay, RangeStartSpecification_type_startingTime);
    ITU_T_CHOICES_DEFN(ReadJournal_Request::RangeStartSpecification_type::startingEntry, startingEntry, octetstring_type, RangeStartSpecification_type_startingEntry);



    ITU_T_CHOICES_DEFN(ReadJournal_Request::RangeStopSpecification_type::endingTime, endingTime, TimeOfDay, RangeStopSpecification_type_endingTime);
    ITU_T_CHOICES_DEFN(ReadJournal_Request::RangeStopSpecification_type::numberOfEntries, numberOfEntries, Integer32, RangeStopSpecification_type_numberOfEntries);

    ReadJournal_Request::EntryToStartAfter_type::EntryToStartAfter_type() : timeSpecification_(), entrySpecification_() {
    };

    ReadJournal_Request::EntryToStartAfter_type::EntryToStartAfter_type(const TimeOfDay& arg__timeSpecification,
            const octetstring_type& arg__entrySpecification) :
    timeSpecification_(arg__timeSpecification),
    entrySpecification_(arg__entrySpecification) {
    };


    ITU_T_HOLDERH_DEFN(ReadJournal_Request::EntryToStartAfter_type::timeSpecification, timeSpecification, TimeOfDay);
    ITU_T_HOLDERH_DEFN(ReadJournal_Request::EntryToStartAfter_type::entrySpecification, entrySpecification, octetstring_type);


    ITU_T_HOLDERH_DEFN(ReadJournal_Request::journalName, journalName, ObjectName);
    ITU_T_OPTIONAL_DEFN(ReadJournal_Request::rangeStartSpecification, rangeStartSpecification, ReadJournal_Request::RangeStartSpecification_type);
    ITU_T_OPTIONAL_DEFN(ReadJournal_Request::rangeStopSpecification, rangeStopSpecification, ReadJournal_Request::RangeStopSpecification_type);
    ITU_T_OPTIONAL_DEFN(ReadJournal_Request::listOfVariables, listOfVariables, ReadJournal_Request::ListOfVariables_type);
    ITU_T_OPTIONAL_DEFN(ReadJournal_Request::entryToStartAfter, entryToStartAfter, ReadJournal_Request::EntryToStartAfter_type);

    // sequence ReadJournal-Response

    ReadJournal_Response::ReadJournal_Response() : listOfJournalEntry_() {
    };

    ReadJournal_Response::ReadJournal_Response(const ListOfJournalEntry_type& arg__listOfJournalEntry) :
    listOfJournalEntry_(arg__listOfJournalEntry) {
    };

    ReadJournal_Response::ReadJournal_Response(shared_ptr< ListOfJournalEntry_type> arg__listOfJournalEntry,
            shared_ptr< bool> arg__moreFollows) :
    listOfJournalEntry_(arg__listOfJournalEntry),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReadJournal_Response::moreFollows__default = false;


    ITU_T_HOLDERH_DEFN(ReadJournal_Response::listOfJournalEntry, listOfJournalEntry, ReadJournal_Response::ListOfJournalEntry_type);
    ITU_T_DEFAULTH_DEFN(ReadJournal_Response::moreFollows, moreFollows, bool);

    // sequence JournalEntry

    JournalEntry::JournalEntry() : entryIdentifier_(), originatingApplication_(), entryContent_() {
    };

    JournalEntry::JournalEntry(const octetstring_type& arg__entryIdentifier,
            const MMS_Environment_1::ApplicationReference& arg__originatingApplication,
            const EntryContent& arg__entryContent) :
    entryIdentifier_(arg__entryIdentifier),
    originatingApplication_(arg__originatingApplication),
    entryContent_(arg__entryContent) {
    };


    ITU_T_HOLDERH_DEFN(JournalEntry::entryIdentifier, entryIdentifier, octetstring_type);
    ITU_T_HOLDERH_DEFN(JournalEntry::originatingApplication, originatingApplication, MMS_Environment_1::ApplicationReference);
    ITU_T_HOLDERH_DEFN(JournalEntry::entryContent, entryContent, EntryContent);

    // sequence WriteJournal-Request

    WriteJournal_Request::WriteJournal_Request() : journalName_(), listOfJournalEntry_() {
    };

    WriteJournal_Request::WriteJournal_Request(const ObjectName& arg__journalName,
            const ListOfJournalEntry_type& arg__listOfJournalEntry) :
    journalName_(arg__journalName),
    listOfJournalEntry_(arg__listOfJournalEntry) {
    };


    ITU_T_HOLDERH_DEFN(WriteJournal_Request::journalName, journalName, ObjectName);
    ITU_T_HOLDERH_DEFN(WriteJournal_Request::listOfJournalEntry, listOfJournalEntry, WriteJournal_Request::ListOfJournalEntry_type);

    // sequence InitializeJournal-Request

    InitializeJournal_Request::InitializeJournal_Request() : journalName_() {
    };

    InitializeJournal_Request::InitializeJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };

    InitializeJournal_Request::InitializeJournal_Request(shared_ptr< ObjectName> arg__journalName,
            shared_ptr< LimitSpecification_type> arg__limitSpecification) :
    journalName_(arg__journalName),
    limitSpecification_(arg__limitSpecification) {
    };

    InitializeJournal_Request::LimitSpecification_type::LimitSpecification_type() : limitingTime_() {
    };

    InitializeJournal_Request::LimitSpecification_type::LimitSpecification_type(const TimeOfDay& arg__limitingTime) :
    limitingTime_(arg__limitingTime) {
    };

    InitializeJournal_Request::LimitSpecification_type::LimitSpecification_type(shared_ptr< TimeOfDay> arg__limitingTime,
            shared_ptr< octetstring_type> arg__limitingEntry) :
    limitingTime_(arg__limitingTime),
    limitingEntry_(arg__limitingEntry) {
    };


    ITU_T_HOLDERH_DEFN(InitializeJournal_Request::LimitSpecification_type::limitingTime, limitingTime, TimeOfDay);
    ITU_T_OPTIONAL_DEFN(InitializeJournal_Request::LimitSpecification_type::limitingEntry, limitingEntry, octetstring_type);


    ITU_T_HOLDERH_DEFN(InitializeJournal_Request::journalName, journalName, ObjectName);
    ITU_T_OPTIONAL_DEFN(InitializeJournal_Request::limitSpecification, limitSpecification, InitializeJournal_Request::LimitSpecification_type);

    // sequence ReportJournalStatus-Response

    ReportJournalStatus_Response::ReportJournalStatus_Response() : currentEntries_(), mmsDeletable_() {
    };

    ReportJournalStatus_Response::ReportJournalStatus_Response(const Unsigned32& arg__currentEntries,
            const bool& arg__mmsDeletable) :
    currentEntries_(arg__currentEntries),
    mmsDeletable_(arg__mmsDeletable) {
    };

    ReportJournalStatus_Response::ReportJournalStatus_Response(shared_ptr< Unsigned32> arg__currentEntries,
            shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< Identifier> arg__accessControlList) :
    currentEntries_(arg__currentEntries),
    mmsDeletable_(arg__mmsDeletable),
    accessControlList_(arg__accessControlList) {
    };


    ITU_T_HOLDERH_DEFN(ReportJournalStatus_Response::currentEntries, currentEntries, Unsigned32);
    ITU_T_HOLDERH_DEFN(ReportJournalStatus_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_OPTIONAL_DEFN(ReportJournalStatus_Response::accessControlList, accessControlList, Identifier);

    // sequence CreateJournal-Request

    CreateJournal_Request::CreateJournal_Request() : journalName_() {
    };

    CreateJournal_Request::CreateJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };


    ITU_T_HOLDERH_DEFN(CreateJournal_Request::journalName, journalName, ObjectName);

    // sequence DeleteJournal-Request

    DeleteJournal_Request::DeleteJournal_Request() : journalName_() {
    };

    DeleteJournal_Request::DeleteJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };


    ITU_T_HOLDERH_DEFN(DeleteJournal_Request::journalName, journalName, ObjectName);

    // sequence EntryContent

    EntryContent::EntryContent() : occurrenceTime_(), entryForm_() {
    };

    EntryContent::EntryContent(const TimeOfDay& arg__occurrenceTime,
            const EntryForm_type& arg__entryForm) :
    occurrenceTime_(arg__occurrenceTime),
    entryForm_(arg__entryForm) {
    };

    EntryContent::EntryForm_type::Data_type::Data_type() {
    };

    EntryContent::EntryForm_type::Data_type::Data_type(shared_ptr< Event_type> arg__event,
            shared_ptr< ListOfVariables_type> arg__listOfVariables) :
    event_(arg__event),
    listOfVariables_(arg__listOfVariables) {
    };

    EntryContent::EntryForm_type::Data_type::Event_type::Event_type() : eventConditionName_(), currentState_() {
    };

    EntryContent::EntryForm_type::Data_type::Event_type::Event_type(const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::EC_State& arg__currentState) :
    eventConditionName_(arg__eventConditionName),
    currentState_(arg__currentState) {
    };


    ITU_T_HOLDERH_DEFN(EntryContent::EntryForm_type::Data_type::Event_type::eventConditionName, eventConditionName, ObjectName);
    ITU_T_HOLDERH_DEFN(EntryContent::EntryForm_type::Data_type::Event_type::currentState, currentState, MMS_Object_Module_1::EC_State);


    ITU_T_OPTIONAL_DEFN(EntryContent::EntryForm_type::Data_type::event, event, EntryContent::EntryForm_type::Data_type::Event_type);
    ITU_T_OPTIONAL_DEFN(EntryContent::EntryForm_type::Data_type::listOfVariables, listOfVariables, EntryContent::EntryForm_type::Data_type::ListOfVariables_type);


    ITU_T_CHOICEC_DEFN(EntryContent::EntryForm_type::data, data, EntryContent::EntryForm_type::Data_type, EntryForm_type_data);
    ITU_T_CHOICES_DEFN(EntryContent::EntryForm_type::annotation, annotation, MMSString, EntryForm_type_annotation);


    ITU_T_HOLDERH_DEFN(EntryContent::occurrenceTime, occurrenceTime, TimeOfDay);
    ITU_T_HOLDERH_DEFN(EntryContent::entryForm, entryForm, EntryContent::EntryForm_type);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

