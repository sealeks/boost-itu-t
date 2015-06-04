#include "ISO-9506-MMS-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1 {


        ITU_T_PREFIXED_DECLARE( AlarmSummary__DisplayEnhancement, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS), prefixed_type(4, CONTEXT_CLASS) ), true); //  initial =explicit
        ITU_T_PREFIXED_DECLARE( AlarmEnrollmentSummary__DisplayEnhancement, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS), prefixed_type(5, CONTEXT_CLASS) ), true); //  initial =explicit

    // choice MMSpdu

        template<> void MMSpdu::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case MMSpdu_confirmed_RequestPDU:  {ITU_T_BIND_IMPLICIT(value<Confirmed_RequestPDU > (false , MMSpdu_confirmed_RequestPDU), 0, CONTEXT_CLASS); break; }
                case MMSpdu_confirmed_ResponsePDU:  {ITU_T_BIND_IMPLICIT(value<Confirmed_ResponsePDU > (false , MMSpdu_confirmed_ResponsePDU), 1, CONTEXT_CLASS); break; }
                case MMSpdu_confirmed_ErrorPDU:  {ITU_T_BIND_IMPLICIT(value<Confirmed_ErrorPDU > (false , MMSpdu_confirmed_ErrorPDU), 2, CONTEXT_CLASS); break; }
                case MMSpdu_unconfirmed_PDU:  {ITU_T_BIND_IMPLICIT(value<Unconfirmed_PDU > (false , MMSpdu_unconfirmed_PDU), 3, CONTEXT_CLASS); break; }
                case MMSpdu_rejectPDU:  {ITU_T_BIND_IMPLICIT(value<RejectPDU > (false , MMSpdu_rejectPDU), 4, CONTEXT_CLASS); break; }
                case MMSpdu_cancel_RequestPDU:  {ITU_T_BIND_IMPLICIT(value<Cancel_RequestPDU > (false , MMSpdu_cancel_RequestPDU), 5, CONTEXT_CLASS); break; }
                case MMSpdu_cancel_ResponsePDU:  {ITU_T_BIND_IMPLICIT(value<Cancel_ResponsePDU > (false , MMSpdu_cancel_ResponsePDU), 6, CONTEXT_CLASS); break; }
                case MMSpdu_cancel_ErrorPDU:  {ITU_T_BIND_IMPLICIT(value<Cancel_ErrorPDU > (false , MMSpdu_cancel_ErrorPDU), 7, CONTEXT_CLASS); break; }
                case MMSpdu_initiate_RequestPDU:  {ITU_T_BIND_IMPLICIT(value<Initiate_RequestPDU > (false , MMSpdu_initiate_RequestPDU), 8, CONTEXT_CLASS); break; }
                case MMSpdu_initiate_ResponsePDU:  {ITU_T_BIND_IMPLICIT(value<Initiate_ResponsePDU > (false , MMSpdu_initiate_ResponsePDU), 9, CONTEXT_CLASS); break; }
                case MMSpdu_initiate_ErrorPDU:  {ITU_T_BIND_IMPLICIT(value<Initiate_ErrorPDU > (false , MMSpdu_initiate_ErrorPDU), 10, CONTEXT_CLASS); break; }
                case MMSpdu_conclude_RequestPDU:  {ITU_T_BIND_IMPLICIT(value<Conclude_RequestPDU > (false , MMSpdu_conclude_RequestPDU), 11, CONTEXT_CLASS); break; }
                case MMSpdu_conclude_ResponsePDU:  {ITU_T_BIND_IMPLICIT(value<Conclude_ResponsePDU > (false , MMSpdu_conclude_ResponsePDU), 12, CONTEXT_CLASS); break; }
                case MMSpdu_conclude_ErrorPDU:  {ITU_T_BIND_IMPLICIT(value<Conclude_ErrorPDU > (false , MMSpdu_conclude_ErrorPDU), 13, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void MMSpdu::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Confirmed_RequestPDU > (true , MMSpdu_confirmed_RequestPDU), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Confirmed_ResponsePDU > (true , MMSpdu_confirmed_ResponsePDU), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Confirmed_ErrorPDU > (true , MMSpdu_confirmed_ErrorPDU), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Unconfirmed_PDU > (true , MMSpdu_unconfirmed_PDU), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<RejectPDU > (true , MMSpdu_rejectPDU), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<Cancel_RequestPDU > (true , MMSpdu_cancel_RequestPDU), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<Cancel_ResponsePDU > (true , MMSpdu_cancel_ResponsePDU), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<Cancel_ErrorPDU > (true , MMSpdu_cancel_ErrorPDU), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<Initiate_RequestPDU > (true , MMSpdu_initiate_RequestPDU), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<Initiate_ResponsePDU > (true , MMSpdu_initiate_ResponsePDU), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<Initiate_ErrorPDU > (true , MMSpdu_initiate_ErrorPDU), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<Conclude_RequestPDU > (true , MMSpdu_conclude_RequestPDU), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_IMPLICIT(value<Conclude_ResponsePDU > (true , MMSpdu_conclude_ResponsePDU), 12, CONTEXT_CLASS)) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_IMPLICIT(value<Conclude_ErrorPDU > (true , MMSpdu_conclude_ErrorPDU), 13, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Confirmed-RequestPDU

        template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(invokeID_);
            ITU_T_BIND_TAG(listOfModifiers_);
            ITU_T_BIND_CHOICE(service_);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_CHOICE_TAG(service_ext_, 79, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

        template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(invokeID_);
            ITU_T_BIND_TAG(listOfModifiers_);
            ITU_T_BIND_CHOICE(service_);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_CHOICE_TAG(service_ext_, 79, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

    // choice ConfirmedServiceRequest

        template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ConfirmedServiceRequest_status:  {ITU_T_BIND_IMPLICIT(value<Status_Request > (false , ConfirmedServiceRequest_status), 0, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getNameList:  {ITU_T_BIND_IMPLICIT(value<GetNameList_Request > (false , ConfirmedServiceRequest_getNameList), 1, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_identify:  {ITU_T_BIND_IMPLICIT(value<Identify_Request > (false , ConfirmedServiceRequest_identify), 2, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_rename:  {ITU_T_BIND_IMPLICIT(value<Rename_Request > (false , ConfirmedServiceRequest_rename), 3, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_read:  {ITU_T_BIND_IMPLICIT(value<Read_Request > (false , ConfirmedServiceRequest_read), 4, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_write:  {ITU_T_BIND_IMPLICIT(value<Write_Request > (false , ConfirmedServiceRequest_write), 5, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getVariableAccessAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (false , ConfirmedServiceRequest_getVariableAccessAttributes), 6, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineNamedVariable:  {ITU_T_BIND_IMPLICIT(value<DefineNamedVariable_Request > (false , ConfirmedServiceRequest_defineNamedVariable), 7, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineScatteredAccess:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (false , ConfirmedServiceRequest_defineScatteredAccess), 8, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getScatteredAccessAttributes:  {ITU_T_BIND_CHOICE_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (false , ConfirmedServiceRequest_getScatteredAccessAttributes), 9, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteVariableAccess:  {ITU_T_BIND_IMPLICIT(value<DeleteVariableAccess_Request > (false , ConfirmedServiceRequest_deleteVariableAccess), 10, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineNamedVariableList:  {ITU_T_BIND_IMPLICIT(value<DefineNamedVariableList_Request > (false , ConfirmedServiceRequest_defineNamedVariableList), 11, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getNamedVariableListAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (false , ConfirmedServiceRequest_getNamedVariableListAttributes), 12, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteNamedVariableList:  {ITU_T_BIND_IMPLICIT(value<DeleteNamedVariableList_Request > (false , ConfirmedServiceRequest_deleteNamedVariableList), 13, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineNamedType:  {ITU_T_BIND_IMPLICIT(value<DefineNamedType_Request > (false , ConfirmedServiceRequest_defineNamedType), 14, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getNamedTypeAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (false , ConfirmedServiceRequest_getNamedTypeAttributes), 15, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteNamedType:  {ITU_T_BIND_IMPLICIT(value<DeleteNamedType_Request > (false , ConfirmedServiceRequest_deleteNamedType), 16, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_input:  {ITU_T_BIND_IMPLICIT(value<Input_Request > (false , ConfirmedServiceRequest_input), 17, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_output:  {ITU_T_BIND_IMPLICIT(value<Output_Request > (false , ConfirmedServiceRequest_output), 18, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_takeControl:  {ITU_T_BIND_IMPLICIT(value<TakeControl_Request > (false , ConfirmedServiceRequest_takeControl), 19, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_relinquishControl:  {ITU_T_BIND_IMPLICIT(value<RelinquishControl_Request > (false , ConfirmedServiceRequest_relinquishControl), 20, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineSemaphore:  {ITU_T_BIND_IMPLICIT(value<DefineSemaphore_Request > (false , ConfirmedServiceRequest_defineSemaphore), 21, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteSemaphore:  {ITU_T_BIND_CHOICE_TAG(value<DeleteSemaphore_Request > (false , ConfirmedServiceRequest_deleteSemaphore), 22, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportSemaphoreStatus:  {ITU_T_BIND_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (false , ConfirmedServiceRequest_reportSemaphoreStatus), 23, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportPoolSemaphoreStatus:  {ITU_T_BIND_IMPLICIT(value<ReportPoolSemaphoreStatus_Request > (false , ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportSemaphoreEntryStatus:  {ITU_T_BIND_IMPLICIT(value<ReportSemaphoreEntryStatus_Request > (false , ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_initiateDownloadSequence:  {ITU_T_BIND_IMPLICIT(value<InitiateDownloadSequence_Request > (false , ConfirmedServiceRequest_initiateDownloadSequence), 26, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_downloadSegment:  {ITU_T_BIND_IMPLICIT(value<DownloadSegment_Request > (false , ConfirmedServiceRequest_downloadSegment), 27, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_terminateDownloadSequence:  {ITU_T_BIND_IMPLICIT(value<TerminateDownloadSequence_Request > (false , ConfirmedServiceRequest_terminateDownloadSequence), 28, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_initiateUploadSequence:  {ITU_T_BIND_IMPLICIT(value<InitiateUploadSequence_Request > (false , ConfirmedServiceRequest_initiateUploadSequence), 29, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_uploadSegment:  {ITU_T_BIND_IMPLICIT(value<UploadSegment_Request > (false , ConfirmedServiceRequest_uploadSegment), 30, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_terminateUploadSequence:  {ITU_T_BIND_IMPLICIT(value<TerminateUploadSequence_Request > (false , ConfirmedServiceRequest_terminateUploadSequence), 31, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_requestDomainDownload:  {ITU_T_BIND_IMPLICIT(value<RequestDomainDownload_Request > (false , ConfirmedServiceRequest_requestDomainDownload), 32, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_requestDomainUpload:  {ITU_T_BIND_IMPLICIT(value<RequestDomainUpload_Request > (false , ConfirmedServiceRequest_requestDomainUpload), 33, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_loadDomainContent:  {ITU_T_BIND_IMPLICIT(value<LoadDomainContent_Request > (false , ConfirmedServiceRequest_loadDomainContent), 34, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_storeDomainContent:  {ITU_T_BIND_IMPLICIT(value<StoreDomainContent_Request > (false , ConfirmedServiceRequest_storeDomainContent), 35, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteDomain:  {ITU_T_BIND_IMPLICIT(value<DeleteDomain_Request > (false , ConfirmedServiceRequest_deleteDomain), 36, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getDomainAttributes:  {ITU_T_BIND_IMPLICIT(value<GetDomainAttributes_Request > (false , ConfirmedServiceRequest_getDomainAttributes), 37, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_createProgramInvocation:  {ITU_T_BIND_IMPLICIT(value<CreateProgramInvocation_Request > (false , ConfirmedServiceRequest_createProgramInvocation), 38, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteProgramInvocation:  {ITU_T_BIND_IMPLICIT(value<DeleteProgramInvocation_Request > (false , ConfirmedServiceRequest_deleteProgramInvocation), 39, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_start:  {ITU_T_BIND_IMPLICIT(value<Start_Request > (false , ConfirmedServiceRequest_start), 40, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_stop:  {ITU_T_BIND_IMPLICIT(value<Stop_Request > (false , ConfirmedServiceRequest_stop), 41, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_resume:  {ITU_T_BIND_IMPLICIT(value<Resume_Request > (false , ConfirmedServiceRequest_resume), 42, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reset:  {ITU_T_BIND_IMPLICIT(value<Reset_Request > (false , ConfirmedServiceRequest_reset), 43, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_kill:  {ITU_T_BIND_IMPLICIT(value<Kill_Request > (false , ConfirmedServiceRequest_kill), 44, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getProgramInvocationAttributes:  {ITU_T_BIND_IMPLICIT(value<GetProgramInvocationAttributes_Request > (false , ConfirmedServiceRequest_getProgramInvocationAttributes), 45, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_obtainFile:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ObtainFile_Request > (false , ConfirmedServiceRequest_obtainFile), 46, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineEventCondition:  {ITU_T_BIND_IMPLICIT(value<DefineEventCondition_Request > (false , ConfirmedServiceRequest_defineEventCondition), 47, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteEventCondition:  {ITU_T_BIND_CHOICE_TAG(value<DeleteEventCondition_Request > (false , ConfirmedServiceRequest_deleteEventCondition), 48, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getEventConditionAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetEventConditionAttributes_Request > (false , ConfirmedServiceRequest_getEventConditionAttributes), 49, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportEventConditionStatus:  {ITU_T_BIND_CHOICE_TAG(value<ReportEventConditionStatus_Request > (false , ConfirmedServiceRequest_reportEventConditionStatus), 50, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_alterEventConditionMonitoring:  {ITU_T_BIND_IMPLICIT(value<AlterEventConditionMonitoring_Request > (false , ConfirmedServiceRequest_alterEventConditionMonitoring), 51, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_triggerEvent:  {ITU_T_BIND_IMPLICIT(value<TriggerEvent_Request > (false , ConfirmedServiceRequest_triggerEvent), 52, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineEventAction:  {ITU_T_BIND_IMPLICIT(value<DefineEventAction_Request > (false , ConfirmedServiceRequest_defineEventAction), 53, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteEventAction:  {ITU_T_BIND_CHOICE_TAG(value<DeleteEventAction_Request > (false , ConfirmedServiceRequest_deleteEventAction), 54, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getEventActionAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetEventActionAttributes_Request > (false , ConfirmedServiceRequest_getEventActionAttributes), 55, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportEventActionStatus:  {ITU_T_BIND_CHOICE_TAG(value<ReportEventActionStatus_Request > (false , ConfirmedServiceRequest_reportEventActionStatus), 56, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<DefineEventEnrollment_Request > (false , ConfirmedServiceRequest_defineEventEnrollment), 57, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteEventEnrollment:  {ITU_T_BIND_CHOICE_TAG(value<DeleteEventEnrollment_Request > (false , ConfirmedServiceRequest_deleteEventEnrollment), 58, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_alterEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<AlterEventEnrollment_Request > (false , ConfirmedServiceRequest_alterEventEnrollment), 59, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportEventEnrollmentStatus:  {ITU_T_BIND_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (false , ConfirmedServiceRequest_reportEventEnrollmentStatus), 60, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getEventEnrollmentAttributes:  {ITU_T_BIND_IMPLICIT(value<GetEventEnrollmentAttributes_Request > (false , ConfirmedServiceRequest_getEventEnrollmentAttributes), 61, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_acknowledgeEventNotification:  {ITU_T_BIND_IMPLICIT(value<AcknowledgeEventNotification_Request > (false , ConfirmedServiceRequest_acknowledgeEventNotification), 62, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getAlarmSummary:  {ITU_T_BIND_IMPLICIT(value<GetAlarmSummary_Request > (false , ConfirmedServiceRequest_getAlarmSummary), 63, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getAlarmEnrollmentSummary:  {ITU_T_BIND_IMPLICIT(value<GetAlarmEnrollmentSummary_Request > (false , ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_readJournal:  {ITU_T_BIND_IMPLICIT(value<ReadJournal_Request > (false , ConfirmedServiceRequest_readJournal), 65, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_writeJournal:  {ITU_T_BIND_IMPLICIT(value<WriteJournal_Request > (false , ConfirmedServiceRequest_writeJournal), 66, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_initializeJournal:  {ITU_T_BIND_IMPLICIT(value<InitializeJournal_Request > (false , ConfirmedServiceRequest_initializeJournal), 67, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportJournalStatus:  {ITU_T_BIND_CHOICE_TAG(value<ReportJournalStatus_Request > (false , ConfirmedServiceRequest_reportJournalStatus), 68, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_createJournal:  {ITU_T_BIND_IMPLICIT(value<CreateJournal_Request > (false , ConfirmedServiceRequest_createJournal), 69, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteJournal:  {ITU_T_BIND_IMPLICIT(value<DeleteJournal_Request > (false , ConfirmedServiceRequest_deleteJournal), 70, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getCapabilityList:  {ITU_T_BIND_IMPLICIT(value<GetCapabilityList_Request > (false , ConfirmedServiceRequest_getCapabilityList), 71, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_fileOpen:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileOpen_Request > (false , ConfirmedServiceRequest_fileOpen), 72, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_fileRead:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRead_Request > (false , ConfirmedServiceRequest_fileRead), 73, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_fileClose:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileClose_Request > (false , ConfirmedServiceRequest_fileClose), 74, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_fileRename:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRename_Request > (false , ConfirmedServiceRequest_fileRename), 75, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_fileDelete:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDelete_Request > (false , ConfirmedServiceRequest_fileDelete), 76, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_fileDirectory:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDirectory_Request > (false , ConfirmedServiceRequest_fileDirectory), 77, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_additionalService:  {ITU_T_BIND_CHOICE_TAG(value<AdditionalService_Request > (false , ConfirmedServiceRequest_additionalService), 78, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getDataExchangeAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (false , ConfirmedServiceRequest_getDataExchangeAttributes), 80, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_exchangeData:  {ITU_T_BIND_IMPLICIT(value<ExchangeData_Request > (false , ConfirmedServiceRequest_exchangeData), 81, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_defineAccessControlList:  {ITU_T_BIND_IMPLICIT(value<DefineAccessControlList_Request > (false , ConfirmedServiceRequest_defineAccessControlList), 82, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_getAccessControlListAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (false , ConfirmedServiceRequest_getAccessControlListAttributes), 83, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_reportAccessControlledObjects:  {ITU_T_BIND_IMPLICIT(value<ReportAccessControlledObjects_Request > (false , ConfirmedServiceRequest_reportAccessControlledObjects), 84, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_deleteAccessControlList:  {ITU_T_BIND_IMPLICIT(value<DeleteAccessControlList_Request > (false , ConfirmedServiceRequest_deleteAccessControlList), 85, CONTEXT_CLASS); break; }
                case ConfirmedServiceRequest_changeAccessControl:  {ITU_T_BIND_IMPLICIT(value<ChangeAccessControl_Request > (false , ConfirmedServiceRequest_changeAccessControl), 86, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Status_Request > (true , ConfirmedServiceRequest_status), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<GetNameList_Request > (true , ConfirmedServiceRequest_getNameList), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identify_Request > (true , ConfirmedServiceRequest_identify), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Rename_Request > (true , ConfirmedServiceRequest_rename), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<Read_Request > (true , ConfirmedServiceRequest_read), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<Write_Request > (true , ConfirmedServiceRequest_write), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (true , ConfirmedServiceRequest_getVariableAccessAttributes), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<DefineNamedVariable_Request > (true , ConfirmedServiceRequest_defineNamedVariable), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (true , ConfirmedServiceRequest_defineScatteredAccess), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_CHOICE_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (true , ConfirmedServiceRequest_getScatteredAccessAttributes), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<DeleteVariableAccess_Request > (true , ConfirmedServiceRequest_deleteVariableAccess), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<DefineNamedVariableList_Request > (true , ConfirmedServiceRequest_defineNamedVariableList), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (true , ConfirmedServiceRequest_getNamedVariableListAttributes), 12, CONTEXT_CLASS)) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_IMPLICIT(value<DeleteNamedVariableList_Request > (true , ConfirmedServiceRequest_deleteNamedVariableList), 13, CONTEXT_CLASS)) return; else free(); break;}
                        case 14:  { if (ITU_T_BIND_IMPLICIT(value<DefineNamedType_Request > (true , ConfirmedServiceRequest_defineNamedType), 14, CONTEXT_CLASS)) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (true , ConfirmedServiceRequest_getNamedTypeAttributes), 15, CONTEXT_CLASS)) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_IMPLICIT(value<DeleteNamedType_Request > (true , ConfirmedServiceRequest_deleteNamedType), 16, CONTEXT_CLASS)) return; else free(); break;}
                        case 17:  { if (ITU_T_BIND_IMPLICIT(value<Input_Request > (true , ConfirmedServiceRequest_input), 17, CONTEXT_CLASS)) return; else free(); break;}
                        case 18:  { if (ITU_T_BIND_IMPLICIT(value<Output_Request > (true , ConfirmedServiceRequest_output), 18, CONTEXT_CLASS)) return; else free(); break;}
                        case 19:  { if (ITU_T_BIND_IMPLICIT(value<TakeControl_Request > (true , ConfirmedServiceRequest_takeControl), 19, CONTEXT_CLASS)) return; else free(); break;}
                        case 20:  { if (ITU_T_BIND_IMPLICIT(value<RelinquishControl_Request > (true , ConfirmedServiceRequest_relinquishControl), 20, CONTEXT_CLASS)) return; else free(); break;}
                        case 21:  { if (ITU_T_BIND_IMPLICIT(value<DefineSemaphore_Request > (true , ConfirmedServiceRequest_defineSemaphore), 21, CONTEXT_CLASS)) return; else free(); break;}
                        case 22:  { if (ITU_T_BIND_CHOICE_TAG(value<DeleteSemaphore_Request > (true , ConfirmedServiceRequest_deleteSemaphore), 22, CONTEXT_CLASS)) return; else free(); break;}
                        case 23:  { if (ITU_T_BIND_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (true , ConfirmedServiceRequest_reportSemaphoreStatus), 23, CONTEXT_CLASS)) return; else free(); break;}
                        case 24:  { if (ITU_T_BIND_IMPLICIT(value<ReportPoolSemaphoreStatus_Request > (true , ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24, CONTEXT_CLASS)) return; else free(); break;}
                        case 25:  { if (ITU_T_BIND_IMPLICIT(value<ReportSemaphoreEntryStatus_Request > (true , ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25, CONTEXT_CLASS)) return; else free(); break;}
                        case 26:  { if (ITU_T_BIND_IMPLICIT(value<InitiateDownloadSequence_Request > (true , ConfirmedServiceRequest_initiateDownloadSequence), 26, CONTEXT_CLASS)) return; else free(); break;}
                        case 27:  { if (ITU_T_BIND_IMPLICIT(value<DownloadSegment_Request > (true , ConfirmedServiceRequest_downloadSegment), 27, CONTEXT_CLASS)) return; else free(); break;}
                        case 28:  { if (ITU_T_BIND_IMPLICIT(value<TerminateDownloadSequence_Request > (true , ConfirmedServiceRequest_terminateDownloadSequence), 28, CONTEXT_CLASS)) return; else free(); break;}
                        case 29:  { if (ITU_T_BIND_IMPLICIT(value<InitiateUploadSequence_Request > (true , ConfirmedServiceRequest_initiateUploadSequence), 29, CONTEXT_CLASS)) return; else free(); break;}
                        case 30:  { if (ITU_T_BIND_IMPLICIT(value<UploadSegment_Request > (true , ConfirmedServiceRequest_uploadSegment), 30, CONTEXT_CLASS)) return; else free(); break;}
                        case 31:  { if (ITU_T_BIND_IMPLICIT(value<TerminateUploadSequence_Request > (true , ConfirmedServiceRequest_terminateUploadSequence), 31, CONTEXT_CLASS)) return; else free(); break;}
                        case 32:  { if (ITU_T_BIND_IMPLICIT(value<RequestDomainDownload_Request > (true , ConfirmedServiceRequest_requestDomainDownload), 32, CONTEXT_CLASS)) return; else free(); break;}
                        case 33:  { if (ITU_T_BIND_IMPLICIT(value<RequestDomainUpload_Request > (true , ConfirmedServiceRequest_requestDomainUpload), 33, CONTEXT_CLASS)) return; else free(); break;}
                        case 34:  { if (ITU_T_BIND_IMPLICIT(value<LoadDomainContent_Request > (true , ConfirmedServiceRequest_loadDomainContent), 34, CONTEXT_CLASS)) return; else free(); break;}
                        case 35:  { if (ITU_T_BIND_IMPLICIT(value<StoreDomainContent_Request > (true , ConfirmedServiceRequest_storeDomainContent), 35, CONTEXT_CLASS)) return; else free(); break;}
                        case 36:  { if (ITU_T_BIND_IMPLICIT(value<DeleteDomain_Request > (true , ConfirmedServiceRequest_deleteDomain), 36, CONTEXT_CLASS)) return; else free(); break;}
                        case 37:  { if (ITU_T_BIND_IMPLICIT(value<GetDomainAttributes_Request > (true , ConfirmedServiceRequest_getDomainAttributes), 37, CONTEXT_CLASS)) return; else free(); break;}
                        case 38:  { if (ITU_T_BIND_IMPLICIT(value<CreateProgramInvocation_Request > (true , ConfirmedServiceRequest_createProgramInvocation), 38, CONTEXT_CLASS)) return; else free(); break;}
                        case 39:  { if (ITU_T_BIND_IMPLICIT(value<DeleteProgramInvocation_Request > (true , ConfirmedServiceRequest_deleteProgramInvocation), 39, CONTEXT_CLASS)) return; else free(); break;}
                        case 40:  { if (ITU_T_BIND_IMPLICIT(value<Start_Request > (true , ConfirmedServiceRequest_start), 40, CONTEXT_CLASS)) return; else free(); break;}
                        case 41:  { if (ITU_T_BIND_IMPLICIT(value<Stop_Request > (true , ConfirmedServiceRequest_stop), 41, CONTEXT_CLASS)) return; else free(); break;}
                        case 42:  { if (ITU_T_BIND_IMPLICIT(value<Resume_Request > (true , ConfirmedServiceRequest_resume), 42, CONTEXT_CLASS)) return; else free(); break;}
                        case 43:  { if (ITU_T_BIND_IMPLICIT(value<Reset_Request > (true , ConfirmedServiceRequest_reset), 43, CONTEXT_CLASS)) return; else free(); break;}
                        case 44:  { if (ITU_T_BIND_IMPLICIT(value<Kill_Request > (true , ConfirmedServiceRequest_kill), 44, CONTEXT_CLASS)) return; else free(); break;}
                        case 45:  { if (ITU_T_BIND_IMPLICIT(value<GetProgramInvocationAttributes_Request > (true , ConfirmedServiceRequest_getProgramInvocationAttributes), 45, CONTEXT_CLASS)) return; else free(); break;}
                        case 46:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ObtainFile_Request > (true , ConfirmedServiceRequest_obtainFile), 46, CONTEXT_CLASS)) return; else free(); break;}
                        case 47:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventCondition_Request > (true , ConfirmedServiceRequest_defineEventCondition), 47, CONTEXT_CLASS)) return; else free(); break;}
                        case 48:  { if (ITU_T_BIND_CHOICE_TAG(value<DeleteEventCondition_Request > (true , ConfirmedServiceRequest_deleteEventCondition), 48, CONTEXT_CLASS)) return; else free(); break;}
                        case 49:  { if (ITU_T_BIND_CHOICE_TAG(value<GetEventConditionAttributes_Request > (true , ConfirmedServiceRequest_getEventConditionAttributes), 49, CONTEXT_CLASS)) return; else free(); break;}
                        case 50:  { if (ITU_T_BIND_CHOICE_TAG(value<ReportEventConditionStatus_Request > (true , ConfirmedServiceRequest_reportEventConditionStatus), 50, CONTEXT_CLASS)) return; else free(); break;}
                        case 51:  { if (ITU_T_BIND_IMPLICIT(value<AlterEventConditionMonitoring_Request > (true , ConfirmedServiceRequest_alterEventConditionMonitoring), 51, CONTEXT_CLASS)) return; else free(); break;}
                        case 52:  { if (ITU_T_BIND_IMPLICIT(value<TriggerEvent_Request > (true , ConfirmedServiceRequest_triggerEvent), 52, CONTEXT_CLASS)) return; else free(); break;}
                        case 53:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventAction_Request > (true , ConfirmedServiceRequest_defineEventAction), 53, CONTEXT_CLASS)) return; else free(); break;}
                        case 54:  { if (ITU_T_BIND_CHOICE_TAG(value<DeleteEventAction_Request > (true , ConfirmedServiceRequest_deleteEventAction), 54, CONTEXT_CLASS)) return; else free(); break;}
                        case 55:  { if (ITU_T_BIND_CHOICE_TAG(value<GetEventActionAttributes_Request > (true , ConfirmedServiceRequest_getEventActionAttributes), 55, CONTEXT_CLASS)) return; else free(); break;}
                        case 56:  { if (ITU_T_BIND_CHOICE_TAG(value<ReportEventActionStatus_Request > (true , ConfirmedServiceRequest_reportEventActionStatus), 56, CONTEXT_CLASS)) return; else free(); break;}
                        case 57:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventEnrollment_Request > (true , ConfirmedServiceRequest_defineEventEnrollment), 57, CONTEXT_CLASS)) return; else free(); break;}
                        case 58:  { if (ITU_T_BIND_CHOICE_TAG(value<DeleteEventEnrollment_Request > (true , ConfirmedServiceRequest_deleteEventEnrollment), 58, CONTEXT_CLASS)) return; else free(); break;}
                        case 59:  { if (ITU_T_BIND_IMPLICIT(value<AlterEventEnrollment_Request > (true , ConfirmedServiceRequest_alterEventEnrollment), 59, CONTEXT_CLASS)) return; else free(); break;}
                        case 60:  { if (ITU_T_BIND_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (true , ConfirmedServiceRequest_reportEventEnrollmentStatus), 60, CONTEXT_CLASS)) return; else free(); break;}
                        case 61:  { if (ITU_T_BIND_IMPLICIT(value<GetEventEnrollmentAttributes_Request > (true , ConfirmedServiceRequest_getEventEnrollmentAttributes), 61, CONTEXT_CLASS)) return; else free(); break;}
                        case 62:  { if (ITU_T_BIND_IMPLICIT(value<AcknowledgeEventNotification_Request > (true , ConfirmedServiceRequest_acknowledgeEventNotification), 62, CONTEXT_CLASS)) return; else free(); break;}
                        case 63:  { if (ITU_T_BIND_IMPLICIT(value<GetAlarmSummary_Request > (true , ConfirmedServiceRequest_getAlarmSummary), 63, CONTEXT_CLASS)) return; else free(); break;}
                        case 64:  { if (ITU_T_BIND_IMPLICIT(value<GetAlarmEnrollmentSummary_Request > (true , ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64, CONTEXT_CLASS)) return; else free(); break;}
                        case 65:  { if (ITU_T_BIND_IMPLICIT(value<ReadJournal_Request > (true , ConfirmedServiceRequest_readJournal), 65, CONTEXT_CLASS)) return; else free(); break;}
                        case 66:  { if (ITU_T_BIND_IMPLICIT(value<WriteJournal_Request > (true , ConfirmedServiceRequest_writeJournal), 66, CONTEXT_CLASS)) return; else free(); break;}
                        case 67:  { if (ITU_T_BIND_IMPLICIT(value<InitializeJournal_Request > (true , ConfirmedServiceRequest_initializeJournal), 67, CONTEXT_CLASS)) return; else free(); break;}
                        case 68:  { if (ITU_T_BIND_CHOICE_TAG(value<ReportJournalStatus_Request > (true , ConfirmedServiceRequest_reportJournalStatus), 68, CONTEXT_CLASS)) return; else free(); break;}
                        case 69:  { if (ITU_T_BIND_IMPLICIT(value<CreateJournal_Request > (true , ConfirmedServiceRequest_createJournal), 69, CONTEXT_CLASS)) return; else free(); break;}
                        case 70:  { if (ITU_T_BIND_IMPLICIT(value<DeleteJournal_Request > (true , ConfirmedServiceRequest_deleteJournal), 70, CONTEXT_CLASS)) return; else free(); break;}
                        case 71:  { if (ITU_T_BIND_IMPLICIT(value<GetCapabilityList_Request > (true , ConfirmedServiceRequest_getCapabilityList), 71, CONTEXT_CLASS)) return; else free(); break;}
                        case 72:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileOpen_Request > (true , ConfirmedServiceRequest_fileOpen), 72, CONTEXT_CLASS)) return; else free(); break;}
                        case 73:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRead_Request > (true , ConfirmedServiceRequest_fileRead), 73, CONTEXT_CLASS)) return; else free(); break;}
                        case 74:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileClose_Request > (true , ConfirmedServiceRequest_fileClose), 74, CONTEXT_CLASS)) return; else free(); break;}
                        case 75:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRename_Request > (true , ConfirmedServiceRequest_fileRename), 75, CONTEXT_CLASS)) return; else free(); break;}
                        case 76:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDelete_Request > (true , ConfirmedServiceRequest_fileDelete), 76, CONTEXT_CLASS)) return; else free(); break;}
                        case 77:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDirectory_Request > (true , ConfirmedServiceRequest_fileDirectory), 77, CONTEXT_CLASS)) return; else free(); break;}
                        case 78:  { if (ITU_T_BIND_CHOICE_TAG(value<AdditionalService_Request > (true , ConfirmedServiceRequest_additionalService), 78, CONTEXT_CLASS)) return; else free(); break;}
                        case 80:  { if (ITU_T_BIND_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (true , ConfirmedServiceRequest_getDataExchangeAttributes), 80, CONTEXT_CLASS)) return; else free(); break;}
                        case 81:  { if (ITU_T_BIND_IMPLICIT(value<ExchangeData_Request > (true , ConfirmedServiceRequest_exchangeData), 81, CONTEXT_CLASS)) return; else free(); break;}
                        case 82:  { if (ITU_T_BIND_IMPLICIT(value<DefineAccessControlList_Request > (true , ConfirmedServiceRequest_defineAccessControlList), 82, CONTEXT_CLASS)) return; else free(); break;}
                        case 83:  { if (ITU_T_BIND_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (true , ConfirmedServiceRequest_getAccessControlListAttributes), 83, CONTEXT_CLASS)) return; else free(); break;}
                        case 84:  { if (ITU_T_BIND_IMPLICIT(value<ReportAccessControlledObjects_Request > (true , ConfirmedServiceRequest_reportAccessControlledObjects), 84, CONTEXT_CLASS)) return; else free(); break;}
                        case 85:  { if (ITU_T_BIND_IMPLICIT(value<DeleteAccessControlList_Request > (true , ConfirmedServiceRequest_deleteAccessControlList), 85, CONTEXT_CLASS)) return; else free(); break;}
                        case 86:  { if (ITU_T_BIND_IMPLICIT(value<ChangeAccessControl_Request > (true , ConfirmedServiceRequest_changeAccessControl), 86, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice AdditionalService-Request

        template<> void AdditionalService_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AdditionalService_Request_vMDStop:  {ITU_T_BIND_IMPLICIT(value<VMDStop_Request > (false , AdditionalService_Request_vMDStop), 0, CONTEXT_CLASS); break; }
                case AdditionalService_Request_vMDReset:  {ITU_T_BIND_IMPLICIT(value<VMDReset_Request > (false , AdditionalService_Request_vMDReset), 1, CONTEXT_CLASS); break; }
                case AdditionalService_Request_select:  {ITU_T_BIND_IMPLICIT(value<Select_Request > (false , AdditionalService_Request_select), 2, CONTEXT_CLASS); break; }
                case AdditionalService_Request_alterPI:  {ITU_T_BIND_IMPLICIT(value<AlterProgramInvocationAttributes_Request > (false , AdditionalService_Request_alterPI), 3, CONTEXT_CLASS); break; }
                case AdditionalService_Request_initiateUCLoad:  {ITU_T_BIND_IMPLICIT(value<InitiateUnitControlLoad_Request > (false , AdditionalService_Request_initiateUCLoad), 4, CONTEXT_CLASS); break; }
                case AdditionalService_Request_uCLoad:  {ITU_T_BIND_IMPLICIT(value<UnitControlLoadSegment_Request > (false , AdditionalService_Request_uCLoad), 5, CONTEXT_CLASS); break; }
                case AdditionalService_Request_uCUpload:  {ITU_T_BIND_IMPLICIT(value<UnitControlUpload_Request > (false , AdditionalService_Request_uCUpload), 6, CONTEXT_CLASS); break; }
                case AdditionalService_Request_startUC:  {ITU_T_BIND_IMPLICIT(value<StartUnitControl_Request > (false , AdditionalService_Request_startUC), 7, CONTEXT_CLASS); break; }
                case AdditionalService_Request_stopUC:  {ITU_T_BIND_IMPLICIT(value<StopUnitControl_Request > (false , AdditionalService_Request_stopUC), 8, CONTEXT_CLASS); break; }
                case AdditionalService_Request_createUC:  {ITU_T_BIND_IMPLICIT(value<CreateUnitControl_Request > (false , AdditionalService_Request_createUC), 9, CONTEXT_CLASS); break; }
                case AdditionalService_Request_addToUC:  {ITU_T_BIND_IMPLICIT(value<AddToUnitControl_Request > (false , AdditionalService_Request_addToUC), 10, CONTEXT_CLASS); break; }
                case AdditionalService_Request_removeFromUC:  {ITU_T_BIND_IMPLICIT(value<RemoveFromUnitControl_Request > (false , AdditionalService_Request_removeFromUC), 11, CONTEXT_CLASS); break; }
                case AdditionalService_Request_getUCAttributes:  {ITU_T_BIND_IMPLICIT(value<GetUnitControlAttributes_Request > (false , AdditionalService_Request_getUCAttributes), 12, CONTEXT_CLASS); break; }
                case AdditionalService_Request_loadUCFromFile:  {ITU_T_BIND_IMPLICIT(value<LoadUnitControlFromFile_Request > (false , AdditionalService_Request_loadUCFromFile), 13, CONTEXT_CLASS); break; }
                case AdditionalService_Request_storeUCToFile:  {ITU_T_BIND_IMPLICIT(value<StoreUnitControlToFile_Request > (false , AdditionalService_Request_storeUCToFile), 14, CONTEXT_CLASS); break; }
                case AdditionalService_Request_deleteUC:  {ITU_T_BIND_IMPLICIT(value<DeleteUnitControl_Request > (false , AdditionalService_Request_deleteUC), 15, CONTEXT_CLASS); break; }
                case AdditionalService_Request_defineECL:  {ITU_T_BIND_EXPLICIT(value<DefineEventConditionList_Request > (false , AdditionalService_Request_defineECL), 16, CONTEXT_CLASS); break; }
                case AdditionalService_Request_deleteECL:  {ITU_T_BIND_CHOICE_TAG(value<DeleteEventConditionList_Request > (false , AdditionalService_Request_deleteECL), 17, CONTEXT_CLASS); break; }
                case AdditionalService_Request_addECLReference:  {ITU_T_BIND_IMPLICIT(value<AddEventConditionListReference_Request > (false , AdditionalService_Request_addECLReference), 18, CONTEXT_CLASS); break; }
                case AdditionalService_Request_removeECLReference:  {ITU_T_BIND_IMPLICIT(value<RemoveEventConditionListReference_Request > (false , AdditionalService_Request_removeECLReference), 19, CONTEXT_CLASS); break; }
                case AdditionalService_Request_getECLAttributes:  {ITU_T_BIND_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (false , AdditionalService_Request_getECLAttributes), 20, CONTEXT_CLASS); break; }
                case AdditionalService_Request_reportECLStatus:  {ITU_T_BIND_IMPLICIT(value<ReportEventConditionListStatus_Request > (false , AdditionalService_Request_reportECLStatus), 21, CONTEXT_CLASS); break; }
                case AdditionalService_Request_alterECLMonitoring:  {ITU_T_BIND_IMPLICIT(value<AlterEventConditionListMonitoring_Request > (false , AdditionalService_Request_alterECLMonitoring), 22, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AdditionalService_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<VMDStop_Request > (true , AdditionalService_Request_vMDStop), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<VMDReset_Request > (true , AdditionalService_Request_vMDReset), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Select_Request > (true , AdditionalService_Request_select), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<AlterProgramInvocationAttributes_Request > (true , AdditionalService_Request_alterPI), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<InitiateUnitControlLoad_Request > (true , AdditionalService_Request_initiateUCLoad), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<UnitControlLoadSegment_Request > (true , AdditionalService_Request_uCLoad), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<UnitControlUpload_Request > (true , AdditionalService_Request_uCUpload), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<StartUnitControl_Request > (true , AdditionalService_Request_startUC), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<StopUnitControl_Request > (true , AdditionalService_Request_stopUC), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<CreateUnitControl_Request > (true , AdditionalService_Request_createUC), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<AddToUnitControl_Request > (true , AdditionalService_Request_addToUC), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<RemoveFromUnitControl_Request > (true , AdditionalService_Request_removeFromUC), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_IMPLICIT(value<GetUnitControlAttributes_Request > (true , AdditionalService_Request_getUCAttributes), 12, CONTEXT_CLASS)) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_IMPLICIT(value<LoadUnitControlFromFile_Request > (true , AdditionalService_Request_loadUCFromFile), 13, CONTEXT_CLASS)) return; else free(); break;}
                        case 14:  { if (ITU_T_BIND_IMPLICIT(value<StoreUnitControlToFile_Request > (true , AdditionalService_Request_storeUCToFile), 14, CONTEXT_CLASS)) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_IMPLICIT(value<DeleteUnitControl_Request > (true , AdditionalService_Request_deleteUC), 15, CONTEXT_CLASS)) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_EXPLICIT(value<DefineEventConditionList_Request > (true , AdditionalService_Request_defineECL), 16, CONTEXT_CLASS)) return; else free(); break;}
                        case 17:  { if (ITU_T_BIND_CHOICE_TAG(value<DeleteEventConditionList_Request > (true , AdditionalService_Request_deleteECL), 17, CONTEXT_CLASS)) return; else free(); break;}
                        case 18:  { if (ITU_T_BIND_IMPLICIT(value<AddEventConditionListReference_Request > (true , AdditionalService_Request_addECLReference), 18, CONTEXT_CLASS)) return; else free(); break;}
                        case 19:  { if (ITU_T_BIND_IMPLICIT(value<RemoveEventConditionListReference_Request > (true , AdditionalService_Request_removeECLReference), 19, CONTEXT_CLASS)) return; else free(); break;}
                        case 20:  { if (ITU_T_BIND_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (true , AdditionalService_Request_getECLAttributes), 20, CONTEXT_CLASS)) return; else free(); break;}
                        case 21:  { if (ITU_T_BIND_IMPLICIT(value<ReportEventConditionListStatus_Request > (true , AdditionalService_Request_reportECLStatus), 21, CONTEXT_CLASS)) return; else free(); break;}
                        case 22:  { if (ITU_T_BIND_IMPLICIT(value<AlterEventConditionListMonitoring_Request > (true , AdditionalService_Request_alterECLMonitoring), 22, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice Request-Detail

        template<> void Request_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Request_Detail_otherRequests:  {ITU_T_BIND_TAG(value<null_type > (false , Request_Detail_otherRequests)); break; }
                case Request_Detail_createProgramInvocation:  {ITU_T_BIND_IMPLICIT(value<CS_CreateProgramInvocation_Request > (false , Request_Detail_createProgramInvocation), 38, CONTEXT_CLASS); break; }
                case Request_Detail_start:  {ITU_T_BIND_IMPLICIT(value<CS_Start_Request > (false , Request_Detail_start), 40, CONTEXT_CLASS); break; }
                case Request_Detail_resume:  {ITU_T_BIND_IMPLICIT(value<CS_Resume_Request > (false , Request_Detail_resume), 42, CONTEXT_CLASS); break; }
                case Request_Detail_defineEventCondition:  {ITU_T_BIND_IMPLICIT(value<CS_DefineEventCondition_Request > (false , Request_Detail_defineEventCondition), 47, CONTEXT_CLASS); break; }
                case Request_Detail_alterEventConditionMonitoring:  {ITU_T_BIND_IMPLICIT(value<CS_AlterEventConditionMonitoring_Request > (false , Request_Detail_alterEventConditionMonitoring), 51, CONTEXT_CLASS); break; }
                case Request_Detail_defineEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<CS_DefineEventEnrollment_Request > (false , Request_Detail_defineEventEnrollment), 57, CONTEXT_CLASS); break; }
                case Request_Detail_alterEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<CS_AlterEventEnrollment_Request > (false , Request_Detail_alterEventEnrollment), 59, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void Request_Detail::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , Request_Detail_otherRequests))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 38:  { if (ITU_T_BIND_IMPLICIT(value<CS_CreateProgramInvocation_Request > (true , Request_Detail_createProgramInvocation), 38, CONTEXT_CLASS)) return; else free(); break;}
                        case 40:  { if (ITU_T_BIND_IMPLICIT(value<CS_Start_Request > (true , Request_Detail_start), 40, CONTEXT_CLASS)) return; else free(); break;}
                        case 42:  { if (ITU_T_BIND_IMPLICIT(value<CS_Resume_Request > (true , Request_Detail_resume), 42, CONTEXT_CLASS)) return; else free(); break;}
                        case 47:  { if (ITU_T_BIND_IMPLICIT(value<CS_DefineEventCondition_Request > (true , Request_Detail_defineEventCondition), 47, CONTEXT_CLASS)) return; else free(); break;}
                        case 51:  { if (ITU_T_BIND_IMPLICIT(value<CS_AlterEventConditionMonitoring_Request > (true , Request_Detail_alterEventConditionMonitoring), 51, CONTEXT_CLASS)) return; else free(); break;}
                        case 57:  { if (ITU_T_BIND_IMPLICIT(value<CS_DefineEventEnrollment_Request > (true , Request_Detail_defineEventEnrollment), 57, CONTEXT_CLASS)) return; else free(); break;}
                        case 59:  { if (ITU_T_BIND_IMPLICIT(value<CS_AlterEventEnrollment_Request > (true , Request_Detail_alterEventEnrollment), 59, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Unconfirmed-PDU

        template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(service_);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_CHOICE_TAG(service_ext_, 79, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

        template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(service_);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_CHOICE_TAG(service_ext_, 79, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

    // choice UnconfirmedService

        template<> void UnconfirmedService::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case UnconfirmedService_informationReport:  {ITU_T_BIND_IMPLICIT(value<InformationReport > (false , UnconfirmedService_informationReport), 0, CONTEXT_CLASS); break; }
                case UnconfirmedService_unsolicitedStatus:  {ITU_T_BIND_IMPLICIT(value<UnsolicitedStatus > (false , UnconfirmedService_unsolicitedStatus), 1, CONTEXT_CLASS); break; }
                case UnconfirmedService_eventNotification:  {ITU_T_BIND_IMPLICIT(value<EventNotification > (false , UnconfirmedService_eventNotification), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void UnconfirmedService::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<InformationReport > (true , UnconfirmedService_informationReport), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<UnsolicitedStatus > (true , UnconfirmedService_unsolicitedStatus), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<EventNotification > (true , UnconfirmedService_eventNotification), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice Unconfirmed-Detail

        template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Unconfirmed_Detail_otherRequests:  {ITU_T_BIND_TAG(value<null_type > (false , Unconfirmed_Detail_otherRequests)); break; }
                case Unconfirmed_Detail_eventNotification:  {ITU_T_BIND_IMPLICIT(value<CS_EventNotification > (false , Unconfirmed_Detail_eventNotification), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , Unconfirmed_Detail_otherRequests))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<CS_EventNotification > (true , Unconfirmed_Detail_eventNotification), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Confirmed-ResponsePDU

        template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(invokeID_);
            ITU_T_BIND_CHOICE(service_);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_CHOICE_TAG(service_ext_, 79, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

        template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(invokeID_);
            ITU_T_BIND_CHOICE(service_);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_CHOICE_TAG(service_ext_, 79, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

    // choice ConfirmedServiceResponse

        template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ConfirmedServiceResponse_status:  {ITU_T_BIND_IMPLICIT(value<Status_Response > (false , ConfirmedServiceResponse_status), 0, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getNameList:  {ITU_T_BIND_IMPLICIT(value<GetNameList_Response > (false , ConfirmedServiceResponse_getNameList), 1, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_identify:  {ITU_T_BIND_IMPLICIT(value<Identify_Response > (false , ConfirmedServiceResponse_identify), 2, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_rename:  {ITU_T_BIND_IMPLICIT(value<Rename_Response > (false , ConfirmedServiceResponse_rename), 3, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_read:  {ITU_T_BIND_IMPLICIT(value<Read_Response > (false , ConfirmedServiceResponse_read), 4, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getVariableAccessAttributes:  {ITU_T_BIND_IMPLICIT(value<GetVariableAccessAttributes_Response > (false , ConfirmedServiceResponse_getVariableAccessAttributes), 6, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineNamedVariable:  {ITU_T_BIND_IMPLICIT(value<DefineNamedVariable_Response > (false , ConfirmedServiceResponse_defineNamedVariable), 7, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineScatteredAccess:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (false , ConfirmedServiceResponse_defineScatteredAccess), 8, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getScatteredAccessAttributes:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (false , ConfirmedServiceResponse_getScatteredAccessAttributes), 9, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteVariableAccess:  {ITU_T_BIND_IMPLICIT(value<DeleteVariableAccess_Response > (false , ConfirmedServiceResponse_deleteVariableAccess), 10, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineNamedVariableList:  {ITU_T_BIND_IMPLICIT(value<DefineNamedVariableList_Response > (false , ConfirmedServiceResponse_defineNamedVariableList), 11, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getNamedVariableListAttributes:  {ITU_T_BIND_IMPLICIT(value<GetNamedVariableListAttributes_Response > (false , ConfirmedServiceResponse_getNamedVariableListAttributes), 12, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteNamedVariableList:  {ITU_T_BIND_IMPLICIT(value<DeleteNamedVariableList_Response > (false , ConfirmedServiceResponse_deleteNamedVariableList), 13, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineNamedType:  {ITU_T_BIND_IMPLICIT(value<DefineNamedType_Response > (false , ConfirmedServiceResponse_defineNamedType), 14, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getNamedTypeAttributes:  {ITU_T_BIND_IMPLICIT(value<GetNamedTypeAttributes_Response > (false , ConfirmedServiceResponse_getNamedTypeAttributes), 15, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteNamedType:  {ITU_T_BIND_IMPLICIT(value<DeleteNamedType_Response > (false , ConfirmedServiceResponse_deleteNamedType), 16, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_input:  {ITU_T_BIND_IMPLICIT(value<Input_Response > (false , ConfirmedServiceResponse_input), 17, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_output:  {ITU_T_BIND_IMPLICIT(value<Output_Response > (false , ConfirmedServiceResponse_output), 18, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_takeControl:  {ITU_T_BIND_CHOICE_TAG(value<TakeControl_Response > (false , ConfirmedServiceResponse_takeControl), 19, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_relinquishControl:  {ITU_T_BIND_IMPLICIT(value<RelinquishControl_Response > (false , ConfirmedServiceResponse_relinquishControl), 20, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineSemaphore:  {ITU_T_BIND_IMPLICIT(value<DefineSemaphore_Response > (false , ConfirmedServiceResponse_defineSemaphore), 21, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteSemaphore:  {ITU_T_BIND_IMPLICIT(value<DeleteSemaphore_Response > (false , ConfirmedServiceResponse_deleteSemaphore), 22, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportSemaphoreStatus:  {ITU_T_BIND_IMPLICIT(value<ReportSemaphoreStatus_Response > (false , ConfirmedServiceResponse_reportSemaphoreStatus), 23, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportPoolSemaphoreStatus:  {ITU_T_BIND_IMPLICIT(value<ReportPoolSemaphoreStatus_Response > (false , ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportSemaphoreEntryStatus:  {ITU_T_BIND_IMPLICIT(value<ReportSemaphoreEntryStatus_Response > (false , ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_initiateDownloadSequence:  {ITU_T_BIND_IMPLICIT(value<InitiateDownloadSequence_Response > (false , ConfirmedServiceResponse_initiateDownloadSequence), 26, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_downloadSegment:  {ITU_T_BIND_IMPLICIT(value<DownloadSegment_Response > (false , ConfirmedServiceResponse_downloadSegment), 27, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_terminateDownloadSequence:  {ITU_T_BIND_IMPLICIT(value<TerminateDownloadSequence_Response > (false , ConfirmedServiceResponse_terminateDownloadSequence), 28, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_initiateUploadSequence:  {ITU_T_BIND_IMPLICIT(value<InitiateUploadSequence_Response > (false , ConfirmedServiceResponse_initiateUploadSequence), 29, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_uploadSegment:  {ITU_T_BIND_IMPLICIT(value<UploadSegment_Response > (false , ConfirmedServiceResponse_uploadSegment), 30, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_terminateUploadSequence:  {ITU_T_BIND_IMPLICIT(value<TerminateUploadSequence_Response > (false , ConfirmedServiceResponse_terminateUploadSequence), 31, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_requestDomainDownload:  {ITU_T_BIND_IMPLICIT(value<RequestDomainDownload_Response > (false , ConfirmedServiceResponse_requestDomainDownload), 32, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_requestDomainUpload:  {ITU_T_BIND_IMPLICIT(value<RequestDomainUpload_Response > (false , ConfirmedServiceResponse_requestDomainUpload), 33, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_loadDomainContent:  {ITU_T_BIND_IMPLICIT(value<LoadDomainContent_Response > (false , ConfirmedServiceResponse_loadDomainContent), 34, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_storeDomainContent:  {ITU_T_BIND_IMPLICIT(value<StoreDomainContent_Response > (false , ConfirmedServiceResponse_storeDomainContent), 35, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteDomain:  {ITU_T_BIND_IMPLICIT(value<DeleteDomain_Response > (false , ConfirmedServiceResponse_deleteDomain), 36, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getDomainAttributes:  {ITU_T_BIND_IMPLICIT(value<GetDomainAttributes_Response > (false , ConfirmedServiceResponse_getDomainAttributes), 37, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_createProgramInvocation:  {ITU_T_BIND_IMPLICIT(value<CreateProgramInvocation_Response > (false , ConfirmedServiceResponse_createProgramInvocation), 38, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteProgramInvocation:  {ITU_T_BIND_IMPLICIT(value<DeleteProgramInvocation_Response > (false , ConfirmedServiceResponse_deleteProgramInvocation), 39, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_start:  {ITU_T_BIND_IMPLICIT(value<Start_Response > (false , ConfirmedServiceResponse_start), 40, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_stop:  {ITU_T_BIND_IMPLICIT(value<Stop_Response > (false , ConfirmedServiceResponse_stop), 41, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_resume:  {ITU_T_BIND_IMPLICIT(value<Resume_Response > (false , ConfirmedServiceResponse_resume), 42, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reset:  {ITU_T_BIND_IMPLICIT(value<Reset_Response > (false , ConfirmedServiceResponse_reset), 43, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_kill:  {ITU_T_BIND_IMPLICIT(value<Kill_Response > (false , ConfirmedServiceResponse_kill), 44, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getProgramInvocationAttributes:  {ITU_T_BIND_IMPLICIT(value<GetProgramInvocationAttributes_Response > (false , ConfirmedServiceResponse_getProgramInvocationAttributes), 45, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_obtainFile:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ObtainFile_Response > (false , ConfirmedServiceResponse_obtainFile), 46, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineEventCondition:  {ITU_T_BIND_IMPLICIT(value<DefineEventCondition_Response > (false , ConfirmedServiceResponse_defineEventCondition), 47, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteEventCondition:  {ITU_T_BIND_IMPLICIT(value<DeleteEventCondition_Response > (false , ConfirmedServiceResponse_deleteEventCondition), 48, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getEventConditionAttributes:  {ITU_T_BIND_IMPLICIT(value<GetEventConditionAttributes_Response > (false , ConfirmedServiceResponse_getEventConditionAttributes), 49, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportEventConditionStatus:  {ITU_T_BIND_IMPLICIT(value<ReportEventConditionStatus_Response > (false , ConfirmedServiceResponse_reportEventConditionStatus), 50, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_alterEventConditionMonitoring:  {ITU_T_BIND_IMPLICIT(value<AlterEventConditionMonitoring_Response > (false , ConfirmedServiceResponse_alterEventConditionMonitoring), 51, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_triggerEvent:  {ITU_T_BIND_IMPLICIT(value<TriggerEvent_Response > (false , ConfirmedServiceResponse_triggerEvent), 52, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineEventAction:  {ITU_T_BIND_IMPLICIT(value<DefineEventAction_Response > (false , ConfirmedServiceResponse_defineEventAction), 53, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteEventAction:  {ITU_T_BIND_IMPLICIT(value<DeleteEventAction_Response > (false , ConfirmedServiceResponse_deleteEventAction), 54, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getEventActionAttributes:  {ITU_T_BIND_IMPLICIT(value<GetEventActionAttributes_Response > (false , ConfirmedServiceResponse_getEventActionAttributes), 55, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportEventActionStatus:  {ITU_T_BIND_IMPLICIT(value<ReportEventActionStatus_Response > (false , ConfirmedServiceResponse_reportEventActionStatus), 56, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<DefineEventEnrollment_Response > (false , ConfirmedServiceResponse_defineEventEnrollment), 57, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<DeleteEventEnrollment_Response > (false , ConfirmedServiceResponse_deleteEventEnrollment), 58, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_alterEventEnrollment:  {ITU_T_BIND_IMPLICIT(value<AlterEventEnrollment_Response > (false , ConfirmedServiceResponse_alterEventEnrollment), 59, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportEventEnrollmentStatus:  {ITU_T_BIND_IMPLICIT(value<ReportEventEnrollmentStatus_Response > (false , ConfirmedServiceResponse_reportEventEnrollmentStatus), 60, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getEventEnrollmentAttributes:  {ITU_T_BIND_IMPLICIT(value<GetEventEnrollmentAttributes_Response > (false , ConfirmedServiceResponse_getEventEnrollmentAttributes), 61, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_acknowledgeEventNotification:  {ITU_T_BIND_IMPLICIT(value<AcknowledgeEventNotification_Response > (false , ConfirmedServiceResponse_acknowledgeEventNotification), 62, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getAlarmSummary:  {ITU_T_BIND_IMPLICIT(value<GetAlarmSummary_Response > (false , ConfirmedServiceResponse_getAlarmSummary), 63, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getAlarmEnrollmentSummary:  {ITU_T_BIND_IMPLICIT(value<GetAlarmEnrollmentSummary_Response > (false , ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_readJournal:  {ITU_T_BIND_IMPLICIT(value<ReadJournal_Response > (false , ConfirmedServiceResponse_readJournal), 65, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_writeJournal:  {ITU_T_BIND_IMPLICIT(value<WriteJournal_Response > (false , ConfirmedServiceResponse_writeJournal), 66, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_initializeJournal:  {ITU_T_BIND_IMPLICIT(value<InitializeJournal_Response > (false , ConfirmedServiceResponse_initializeJournal), 67, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportJournalStatus:  {ITU_T_BIND_IMPLICIT(value<ReportJournalStatus_Response > (false , ConfirmedServiceResponse_reportJournalStatus), 68, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_createJournal:  {ITU_T_BIND_IMPLICIT(value<CreateJournal_Response > (false , ConfirmedServiceResponse_createJournal), 69, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteJournal:  {ITU_T_BIND_IMPLICIT(value<DeleteJournal_Response > (false , ConfirmedServiceResponse_deleteJournal), 70, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getCapabilityList:  {ITU_T_BIND_IMPLICIT(value<GetCapabilityList_Response > (false , ConfirmedServiceResponse_getCapabilityList), 71, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_fileOpen:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileOpen_Response > (false , ConfirmedServiceResponse_fileOpen), 72, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_fileRead:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRead_Response > (false , ConfirmedServiceResponse_fileRead), 73, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_fileClose:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileClose_Response > (false , ConfirmedServiceResponse_fileClose), 74, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_fileRename:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRename_Response > (false , ConfirmedServiceResponse_fileRename), 75, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_fileDelete:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDelete_Response > (false , ConfirmedServiceResponse_fileDelete), 76, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_fileDirectory:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDirectory_Response > (false , ConfirmedServiceResponse_fileDirectory), 77, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_additionalService:  {ITU_T_BIND_CHOICE_TAG(value<AdditionalService_Response > (false , ConfirmedServiceResponse_additionalService), 78, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getDataExchangeAttributes:  {ITU_T_BIND_EXPLICIT(value<GetDataExchangeAttributes_Response > (false , ConfirmedServiceResponse_getDataExchangeAttributes), 80, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_exchangeData:  {ITU_T_BIND_IMPLICIT(value<ExchangeData_Response > (false , ConfirmedServiceResponse_exchangeData), 81, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_defineAccessControlList:  {ITU_T_BIND_IMPLICIT(value<DefineAccessControlList_Response > (false , ConfirmedServiceResponse_defineAccessControlList), 82, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_getAccessControlListAttributes:  {ITU_T_BIND_IMPLICIT(value<GetAccessControlListAttributes_Response > (false , ConfirmedServiceResponse_getAccessControlListAttributes), 83, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_reportAccessControlledObjects:  {ITU_T_BIND_IMPLICIT(value<ReportAccessControlledObjects_Response > (false , ConfirmedServiceResponse_reportAccessControlledObjects), 84, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_deleteAccessControlList:  {ITU_T_BIND_IMPLICIT(value<DeleteAccessControlList_Response > (false , ConfirmedServiceResponse_deleteAccessControlList), 85, CONTEXT_CLASS); break; }
                case ConfirmedServiceResponse_changeAccessControl:  {ITU_T_BIND_IMPLICIT(value<ChangeAccessControl_Response > (false , ConfirmedServiceResponse_changeAccessControl), 86, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Status_Response > (true , ConfirmedServiceResponse_status), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<GetNameList_Response > (true , ConfirmedServiceResponse_getNameList), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identify_Response > (true , ConfirmedServiceResponse_identify), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Rename_Response > (true , ConfirmedServiceResponse_rename), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<Read_Response > (true , ConfirmedServiceResponse_read), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<GetVariableAccessAttributes_Response > (true , ConfirmedServiceResponse_getVariableAccessAttributes), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<DefineNamedVariable_Response > (true , ConfirmedServiceResponse_defineNamedVariable), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (true , ConfirmedServiceResponse_defineScatteredAccess), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (true , ConfirmedServiceResponse_getScatteredAccessAttributes), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<DeleteVariableAccess_Response > (true , ConfirmedServiceResponse_deleteVariableAccess), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<DefineNamedVariableList_Response > (true , ConfirmedServiceResponse_defineNamedVariableList), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_IMPLICIT(value<GetNamedVariableListAttributes_Response > (true , ConfirmedServiceResponse_getNamedVariableListAttributes), 12, CONTEXT_CLASS)) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_IMPLICIT(value<DeleteNamedVariableList_Response > (true , ConfirmedServiceResponse_deleteNamedVariableList), 13, CONTEXT_CLASS)) return; else free(); break;}
                        case 14:  { if (ITU_T_BIND_IMPLICIT(value<DefineNamedType_Response > (true , ConfirmedServiceResponse_defineNamedType), 14, CONTEXT_CLASS)) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_IMPLICIT(value<GetNamedTypeAttributes_Response > (true , ConfirmedServiceResponse_getNamedTypeAttributes), 15, CONTEXT_CLASS)) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_IMPLICIT(value<DeleteNamedType_Response > (true , ConfirmedServiceResponse_deleteNamedType), 16, CONTEXT_CLASS)) return; else free(); break;}
                        case 17:  { if (ITU_T_BIND_IMPLICIT(value<Input_Response > (true , ConfirmedServiceResponse_input), 17, CONTEXT_CLASS)) return; else free(); break;}
                        case 18:  { if (ITU_T_BIND_IMPLICIT(value<Output_Response > (true , ConfirmedServiceResponse_output), 18, CONTEXT_CLASS)) return; else free(); break;}
                        case 19:  { if (ITU_T_BIND_CHOICE_TAG(value<TakeControl_Response > (true , ConfirmedServiceResponse_takeControl), 19, CONTEXT_CLASS)) return; else free(); break;}
                        case 20:  { if (ITU_T_BIND_IMPLICIT(value<RelinquishControl_Response > (true , ConfirmedServiceResponse_relinquishControl), 20, CONTEXT_CLASS)) return; else free(); break;}
                        case 21:  { if (ITU_T_BIND_IMPLICIT(value<DefineSemaphore_Response > (true , ConfirmedServiceResponse_defineSemaphore), 21, CONTEXT_CLASS)) return; else free(); break;}
                        case 22:  { if (ITU_T_BIND_IMPLICIT(value<DeleteSemaphore_Response > (true , ConfirmedServiceResponse_deleteSemaphore), 22, CONTEXT_CLASS)) return; else free(); break;}
                        case 23:  { if (ITU_T_BIND_IMPLICIT(value<ReportSemaphoreStatus_Response > (true , ConfirmedServiceResponse_reportSemaphoreStatus), 23, CONTEXT_CLASS)) return; else free(); break;}
                        case 24:  { if (ITU_T_BIND_IMPLICIT(value<ReportPoolSemaphoreStatus_Response > (true , ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24, CONTEXT_CLASS)) return; else free(); break;}
                        case 25:  { if (ITU_T_BIND_IMPLICIT(value<ReportSemaphoreEntryStatus_Response > (true , ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25, CONTEXT_CLASS)) return; else free(); break;}
                        case 26:  { if (ITU_T_BIND_IMPLICIT(value<InitiateDownloadSequence_Response > (true , ConfirmedServiceResponse_initiateDownloadSequence), 26, CONTEXT_CLASS)) return; else free(); break;}
                        case 27:  { if (ITU_T_BIND_IMPLICIT(value<DownloadSegment_Response > (true , ConfirmedServiceResponse_downloadSegment), 27, CONTEXT_CLASS)) return; else free(); break;}
                        case 28:  { if (ITU_T_BIND_IMPLICIT(value<TerminateDownloadSequence_Response > (true , ConfirmedServiceResponse_terminateDownloadSequence), 28, CONTEXT_CLASS)) return; else free(); break;}
                        case 29:  { if (ITU_T_BIND_IMPLICIT(value<InitiateUploadSequence_Response > (true , ConfirmedServiceResponse_initiateUploadSequence), 29, CONTEXT_CLASS)) return; else free(); break;}
                        case 30:  { if (ITU_T_BIND_IMPLICIT(value<UploadSegment_Response > (true , ConfirmedServiceResponse_uploadSegment), 30, CONTEXT_CLASS)) return; else free(); break;}
                        case 31:  { if (ITU_T_BIND_IMPLICIT(value<TerminateUploadSequence_Response > (true , ConfirmedServiceResponse_terminateUploadSequence), 31, CONTEXT_CLASS)) return; else free(); break;}
                        case 32:  { if (ITU_T_BIND_IMPLICIT(value<RequestDomainDownload_Response > (true , ConfirmedServiceResponse_requestDomainDownload), 32, CONTEXT_CLASS)) return; else free(); break;}
                        case 33:  { if (ITU_T_BIND_IMPLICIT(value<RequestDomainUpload_Response > (true , ConfirmedServiceResponse_requestDomainUpload), 33, CONTEXT_CLASS)) return; else free(); break;}
                        case 34:  { if (ITU_T_BIND_IMPLICIT(value<LoadDomainContent_Response > (true , ConfirmedServiceResponse_loadDomainContent), 34, CONTEXT_CLASS)) return; else free(); break;}
                        case 35:  { if (ITU_T_BIND_IMPLICIT(value<StoreDomainContent_Response > (true , ConfirmedServiceResponse_storeDomainContent), 35, CONTEXT_CLASS)) return; else free(); break;}
                        case 36:  { if (ITU_T_BIND_IMPLICIT(value<DeleteDomain_Response > (true , ConfirmedServiceResponse_deleteDomain), 36, CONTEXT_CLASS)) return; else free(); break;}
                        case 37:  { if (ITU_T_BIND_IMPLICIT(value<GetDomainAttributes_Response > (true , ConfirmedServiceResponse_getDomainAttributes), 37, CONTEXT_CLASS)) return; else free(); break;}
                        case 38:  { if (ITU_T_BIND_IMPLICIT(value<CreateProgramInvocation_Response > (true , ConfirmedServiceResponse_createProgramInvocation), 38, CONTEXT_CLASS)) return; else free(); break;}
                        case 39:  { if (ITU_T_BIND_IMPLICIT(value<DeleteProgramInvocation_Response > (true , ConfirmedServiceResponse_deleteProgramInvocation), 39, CONTEXT_CLASS)) return; else free(); break;}
                        case 40:  { if (ITU_T_BIND_IMPLICIT(value<Start_Response > (true , ConfirmedServiceResponse_start), 40, CONTEXT_CLASS)) return; else free(); break;}
                        case 41:  { if (ITU_T_BIND_IMPLICIT(value<Stop_Response > (true , ConfirmedServiceResponse_stop), 41, CONTEXT_CLASS)) return; else free(); break;}
                        case 42:  { if (ITU_T_BIND_IMPLICIT(value<Resume_Response > (true , ConfirmedServiceResponse_resume), 42, CONTEXT_CLASS)) return; else free(); break;}
                        case 43:  { if (ITU_T_BIND_IMPLICIT(value<Reset_Response > (true , ConfirmedServiceResponse_reset), 43, CONTEXT_CLASS)) return; else free(); break;}
                        case 44:  { if (ITU_T_BIND_IMPLICIT(value<Kill_Response > (true , ConfirmedServiceResponse_kill), 44, CONTEXT_CLASS)) return; else free(); break;}
                        case 45:  { if (ITU_T_BIND_IMPLICIT(value<GetProgramInvocationAttributes_Response > (true , ConfirmedServiceResponse_getProgramInvocationAttributes), 45, CONTEXT_CLASS)) return; else free(); break;}
                        case 46:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ObtainFile_Response > (true , ConfirmedServiceResponse_obtainFile), 46, CONTEXT_CLASS)) return; else free(); break;}
                        case 47:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventCondition_Response > (true , ConfirmedServiceResponse_defineEventCondition), 47, CONTEXT_CLASS)) return; else free(); break;}
                        case 48:  { if (ITU_T_BIND_IMPLICIT(value<DeleteEventCondition_Response > (true , ConfirmedServiceResponse_deleteEventCondition), 48, CONTEXT_CLASS)) return; else free(); break;}
                        case 49:  { if (ITU_T_BIND_IMPLICIT(value<GetEventConditionAttributes_Response > (true , ConfirmedServiceResponse_getEventConditionAttributes), 49, CONTEXT_CLASS)) return; else free(); break;}
                        case 50:  { if (ITU_T_BIND_IMPLICIT(value<ReportEventConditionStatus_Response > (true , ConfirmedServiceResponse_reportEventConditionStatus), 50, CONTEXT_CLASS)) return; else free(); break;}
                        case 51:  { if (ITU_T_BIND_IMPLICIT(value<AlterEventConditionMonitoring_Response > (true , ConfirmedServiceResponse_alterEventConditionMonitoring), 51, CONTEXT_CLASS)) return; else free(); break;}
                        case 52:  { if (ITU_T_BIND_IMPLICIT(value<TriggerEvent_Response > (true , ConfirmedServiceResponse_triggerEvent), 52, CONTEXT_CLASS)) return; else free(); break;}
                        case 53:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventAction_Response > (true , ConfirmedServiceResponse_defineEventAction), 53, CONTEXT_CLASS)) return; else free(); break;}
                        case 54:  { if (ITU_T_BIND_IMPLICIT(value<DeleteEventAction_Response > (true , ConfirmedServiceResponse_deleteEventAction), 54, CONTEXT_CLASS)) return; else free(); break;}
                        case 55:  { if (ITU_T_BIND_IMPLICIT(value<GetEventActionAttributes_Response > (true , ConfirmedServiceResponse_getEventActionAttributes), 55, CONTEXT_CLASS)) return; else free(); break;}
                        case 56:  { if (ITU_T_BIND_IMPLICIT(value<ReportEventActionStatus_Response > (true , ConfirmedServiceResponse_reportEventActionStatus), 56, CONTEXT_CLASS)) return; else free(); break;}
                        case 57:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventEnrollment_Response > (true , ConfirmedServiceResponse_defineEventEnrollment), 57, CONTEXT_CLASS)) return; else free(); break;}
                        case 58:  { if (ITU_T_BIND_IMPLICIT(value<DeleteEventEnrollment_Response > (true , ConfirmedServiceResponse_deleteEventEnrollment), 58, CONTEXT_CLASS)) return; else free(); break;}
                        case 59:  { if (ITU_T_BIND_IMPLICIT(value<AlterEventEnrollment_Response > (true , ConfirmedServiceResponse_alterEventEnrollment), 59, CONTEXT_CLASS)) return; else free(); break;}
                        case 60:  { if (ITU_T_BIND_IMPLICIT(value<ReportEventEnrollmentStatus_Response > (true , ConfirmedServiceResponse_reportEventEnrollmentStatus), 60, CONTEXT_CLASS)) return; else free(); break;}
                        case 61:  { if (ITU_T_BIND_IMPLICIT(value<GetEventEnrollmentAttributes_Response > (true , ConfirmedServiceResponse_getEventEnrollmentAttributes), 61, CONTEXT_CLASS)) return; else free(); break;}
                        case 62:  { if (ITU_T_BIND_IMPLICIT(value<AcknowledgeEventNotification_Response > (true , ConfirmedServiceResponse_acknowledgeEventNotification), 62, CONTEXT_CLASS)) return; else free(); break;}
                        case 63:  { if (ITU_T_BIND_IMPLICIT(value<GetAlarmSummary_Response > (true , ConfirmedServiceResponse_getAlarmSummary), 63, CONTEXT_CLASS)) return; else free(); break;}
                        case 64:  { if (ITU_T_BIND_IMPLICIT(value<GetAlarmEnrollmentSummary_Response > (true , ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64, CONTEXT_CLASS)) return; else free(); break;}
                        case 65:  { if (ITU_T_BIND_IMPLICIT(value<ReadJournal_Response > (true , ConfirmedServiceResponse_readJournal), 65, CONTEXT_CLASS)) return; else free(); break;}
                        case 66:  { if (ITU_T_BIND_IMPLICIT(value<WriteJournal_Response > (true , ConfirmedServiceResponse_writeJournal), 66, CONTEXT_CLASS)) return; else free(); break;}
                        case 67:  { if (ITU_T_BIND_IMPLICIT(value<InitializeJournal_Response > (true , ConfirmedServiceResponse_initializeJournal), 67, CONTEXT_CLASS)) return; else free(); break;}
                        case 68:  { if (ITU_T_BIND_IMPLICIT(value<ReportJournalStatus_Response > (true , ConfirmedServiceResponse_reportJournalStatus), 68, CONTEXT_CLASS)) return; else free(); break;}
                        case 69:  { if (ITU_T_BIND_IMPLICIT(value<CreateJournal_Response > (true , ConfirmedServiceResponse_createJournal), 69, CONTEXT_CLASS)) return; else free(); break;}
                        case 70:  { if (ITU_T_BIND_IMPLICIT(value<DeleteJournal_Response > (true , ConfirmedServiceResponse_deleteJournal), 70, CONTEXT_CLASS)) return; else free(); break;}
                        case 71:  { if (ITU_T_BIND_IMPLICIT(value<GetCapabilityList_Response > (true , ConfirmedServiceResponse_getCapabilityList), 71, CONTEXT_CLASS)) return; else free(); break;}
                        case 72:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileOpen_Response > (true , ConfirmedServiceResponse_fileOpen), 72, CONTEXT_CLASS)) return; else free(); break;}
                        case 73:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRead_Response > (true , ConfirmedServiceResponse_fileRead), 73, CONTEXT_CLASS)) return; else free(); break;}
                        case 74:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileClose_Response > (true , ConfirmedServiceResponse_fileClose), 74, CONTEXT_CLASS)) return; else free(); break;}
                        case 75:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRename_Response > (true , ConfirmedServiceResponse_fileRename), 75, CONTEXT_CLASS)) return; else free(); break;}
                        case 76:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDelete_Response > (true , ConfirmedServiceResponse_fileDelete), 76, CONTEXT_CLASS)) return; else free(); break;}
                        case 77:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileDirectory_Response > (true , ConfirmedServiceResponse_fileDirectory), 77, CONTEXT_CLASS)) return; else free(); break;}
                        case 78:  { if (ITU_T_BIND_CHOICE_TAG(value<AdditionalService_Response > (true , ConfirmedServiceResponse_additionalService), 78, CONTEXT_CLASS)) return; else free(); break;}
                        case 80:  { if (ITU_T_BIND_EXPLICIT(value<GetDataExchangeAttributes_Response > (true , ConfirmedServiceResponse_getDataExchangeAttributes), 80, CONTEXT_CLASS)) return; else free(); break;}
                        case 81:  { if (ITU_T_BIND_IMPLICIT(value<ExchangeData_Response > (true , ConfirmedServiceResponse_exchangeData), 81, CONTEXT_CLASS)) return; else free(); break;}
                        case 82:  { if (ITU_T_BIND_IMPLICIT(value<DefineAccessControlList_Response > (true , ConfirmedServiceResponse_defineAccessControlList), 82, CONTEXT_CLASS)) return; else free(); break;}
                        case 83:  { if (ITU_T_BIND_IMPLICIT(value<GetAccessControlListAttributes_Response > (true , ConfirmedServiceResponse_getAccessControlListAttributes), 83, CONTEXT_CLASS)) return; else free(); break;}
                        case 84:  { if (ITU_T_BIND_IMPLICIT(value<ReportAccessControlledObjects_Response > (true , ConfirmedServiceResponse_reportAccessControlledObjects), 84, CONTEXT_CLASS)) return; else free(); break;}
                        case 85:  { if (ITU_T_BIND_IMPLICIT(value<DeleteAccessControlList_Response > (true , ConfirmedServiceResponse_deleteAccessControlList), 85, CONTEXT_CLASS)) return; else free(); break;}
                        case 86:  { if (ITU_T_BIND_IMPLICIT(value<ChangeAccessControl_Response > (true , ConfirmedServiceResponse_changeAccessControl), 86, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice AdditionalService-Response

        template<> void AdditionalService_Response::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AdditionalService_Response_vMDStop:  {ITU_T_BIND_IMPLICIT(value<VMDStop_Response > (false , AdditionalService_Response_vMDStop), 0, CONTEXT_CLASS); break; }
                case AdditionalService_Response_vMDReset:  {ITU_T_BIND_IMPLICIT(value<VMDReset_Response > (false , AdditionalService_Response_vMDReset), 1, CONTEXT_CLASS); break; }
                case AdditionalService_Response_select:  {ITU_T_BIND_IMPLICIT(value<Select_Response > (false , AdditionalService_Response_select), 2, CONTEXT_CLASS); break; }
                case AdditionalService_Response_alterPI:  {ITU_T_BIND_IMPLICIT(value<AlterProgramInvocationAttributes_Response > (false , AdditionalService_Response_alterPI), 3, CONTEXT_CLASS); break; }
                case AdditionalService_Response_initiateUCLoad:  {ITU_T_BIND_IMPLICIT(value<InitiateUnitControlLoad_Response > (false , AdditionalService_Response_initiateUCLoad), 4, CONTEXT_CLASS); break; }
                case AdditionalService_Response_uCLoad:  {ITU_T_BIND_IMPLICIT(value<UnitControlLoadSegment_Response > (false , AdditionalService_Response_uCLoad), 5, CONTEXT_CLASS); break; }
                case AdditionalService_Response_uCUpload:  {ITU_T_BIND_IMPLICIT(value<UnitControlUpload_Response > (false , AdditionalService_Response_uCUpload), 6, CONTEXT_CLASS); break; }
                case AdditionalService_Response_startUC:  {ITU_T_BIND_IMPLICIT(value<StartUnitControl_Response > (false , AdditionalService_Response_startUC), 7, CONTEXT_CLASS); break; }
                case AdditionalService_Response_stopUC:  {ITU_T_BIND_IMPLICIT(value<StopUnitControl_Response > (false , AdditionalService_Response_stopUC), 8, CONTEXT_CLASS); break; }
                case AdditionalService_Response_createUC:  {ITU_T_BIND_IMPLICIT(value<CreateUnitControl_Response > (false , AdditionalService_Response_createUC), 9, CONTEXT_CLASS); break; }
                case AdditionalService_Response_addToUC:  {ITU_T_BIND_IMPLICIT(value<AddToUnitControl_Response > (false , AdditionalService_Response_addToUC), 10, CONTEXT_CLASS); break; }
                case AdditionalService_Response_removeFromUC:  {ITU_T_BIND_IMPLICIT(value<RemoveFromUnitControl_Response > (false , AdditionalService_Response_removeFromUC), 11, CONTEXT_CLASS); break; }
                case AdditionalService_Response_getUCAttributes:  {ITU_T_BIND_IMPLICIT(value<GetUnitControlAttributes_Response > (false , AdditionalService_Response_getUCAttributes), 12, CONTEXT_CLASS); break; }
                case AdditionalService_Response_loadUCFromFile:  {ITU_T_BIND_IMPLICIT(value<LoadUnitControlFromFile_Response > (false , AdditionalService_Response_loadUCFromFile), 13, CONTEXT_CLASS); break; }
                case AdditionalService_Response_storeUCToFile:  {ITU_T_BIND_IMPLICIT(value<StoreUnitControlToFile_Response > (false , AdditionalService_Response_storeUCToFile), 14, CONTEXT_CLASS); break; }
                case AdditionalService_Response_deleteUC:  {ITU_T_BIND_IMPLICIT(value<DeleteUnitControl_Response > (false , AdditionalService_Response_deleteUC), 15, CONTEXT_CLASS); break; }
                case AdditionalService_Response_defineECL:  {ITU_T_BIND_IMPLICIT(value<DefineEventConditionList_Response > (false , AdditionalService_Response_defineECL), 16, CONTEXT_CLASS); break; }
                case AdditionalService_Response_deleteECL:  {ITU_T_BIND_IMPLICIT(value<DeleteEventConditionList_Response > (false , AdditionalService_Response_deleteECL), 17, CONTEXT_CLASS); break; }
                case AdditionalService_Response_addECLReference:  {ITU_T_BIND_IMPLICIT(value<AddEventConditionListReference_Response > (false , AdditionalService_Response_addECLReference), 18, CONTEXT_CLASS); break; }
                case AdditionalService_Response_removeECLReference:  {ITU_T_BIND_IMPLICIT(value<RemoveEventConditionListReference_Response > (false , AdditionalService_Response_removeECLReference), 19, CONTEXT_CLASS); break; }
                case AdditionalService_Response_getECLAttributes:  {ITU_T_BIND_IMPLICIT(value<GetEventConditionListAttributes_Response > (false , AdditionalService_Response_getECLAttributes), 20, CONTEXT_CLASS); break; }
                case AdditionalService_Response_reportECLStatus:  {ITU_T_BIND_IMPLICIT(value<ReportEventConditionListStatus_Response > (false , AdditionalService_Response_reportECLStatus), 21, CONTEXT_CLASS); break; }
                case AdditionalService_Response_alterECLMonitoring:  {ITU_T_BIND_IMPLICIT(value<AlterEventConditionListMonitoring_Response > (false , AdditionalService_Response_alterECLMonitoring), 22, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AdditionalService_Response::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<VMDStop_Response > (true , AdditionalService_Response_vMDStop), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<VMDReset_Response > (true , AdditionalService_Response_vMDReset), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Select_Response > (true , AdditionalService_Response_select), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<AlterProgramInvocationAttributes_Response > (true , AdditionalService_Response_alterPI), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<InitiateUnitControlLoad_Response > (true , AdditionalService_Response_initiateUCLoad), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<UnitControlLoadSegment_Response > (true , AdditionalService_Response_uCLoad), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<UnitControlUpload_Response > (true , AdditionalService_Response_uCUpload), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<StartUnitControl_Response > (true , AdditionalService_Response_startUC), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<StopUnitControl_Response > (true , AdditionalService_Response_stopUC), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<CreateUnitControl_Response > (true , AdditionalService_Response_createUC), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<AddToUnitControl_Response > (true , AdditionalService_Response_addToUC), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<RemoveFromUnitControl_Response > (true , AdditionalService_Response_removeFromUC), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_IMPLICIT(value<GetUnitControlAttributes_Response > (true , AdditionalService_Response_getUCAttributes), 12, CONTEXT_CLASS)) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_IMPLICIT(value<LoadUnitControlFromFile_Response > (true , AdditionalService_Response_loadUCFromFile), 13, CONTEXT_CLASS)) return; else free(); break;}
                        case 14:  { if (ITU_T_BIND_IMPLICIT(value<StoreUnitControlToFile_Response > (true , AdditionalService_Response_storeUCToFile), 14, CONTEXT_CLASS)) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_IMPLICIT(value<DeleteUnitControl_Response > (true , AdditionalService_Response_deleteUC), 15, CONTEXT_CLASS)) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_IMPLICIT(value<DefineEventConditionList_Response > (true , AdditionalService_Response_defineECL), 16, CONTEXT_CLASS)) return; else free(); break;}
                        case 17:  { if (ITU_T_BIND_IMPLICIT(value<DeleteEventConditionList_Response > (true , AdditionalService_Response_deleteECL), 17, CONTEXT_CLASS)) return; else free(); break;}
                        case 18:  { if (ITU_T_BIND_IMPLICIT(value<AddEventConditionListReference_Response > (true , AdditionalService_Response_addECLReference), 18, CONTEXT_CLASS)) return; else free(); break;}
                        case 19:  { if (ITU_T_BIND_IMPLICIT(value<RemoveEventConditionListReference_Response > (true , AdditionalService_Response_removeECLReference), 19, CONTEXT_CLASS)) return; else free(); break;}
                        case 20:  { if (ITU_T_BIND_IMPLICIT(value<GetEventConditionListAttributes_Response > (true , AdditionalService_Response_getECLAttributes), 20, CONTEXT_CLASS)) return; else free(); break;}
                        case 21:  { if (ITU_T_BIND_IMPLICIT(value<ReportEventConditionListStatus_Response > (true , AdditionalService_Response_reportECLStatus), 21, CONTEXT_CLASS)) return; else free(); break;}
                        case 22:  { if (ITU_T_BIND_IMPLICIT(value<AlterEventConditionListMonitoring_Response > (true , AdditionalService_Response_alterECLMonitoring), 22, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice Response-Detail

        template<> void Response_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Response_Detail_otherRequests:  {ITU_T_BIND_TAG(value<null_type > (false , Response_Detail_otherRequests)); break; }
                case Response_Detail_status:  {ITU_T_BIND_CHOICE_TAG(value<CS_Status_Response > (false , Response_Detail_status), 0, CONTEXT_CLASS); break; }
                case Response_Detail_getProgramInvocationAttributes:  {ITU_T_BIND_IMPLICIT(value<CS_GetProgramInvocationAttributes_Response > (false , Response_Detail_getProgramInvocationAttributes), 45, CONTEXT_CLASS); break; }
                case Response_Detail_getEventConditionAttributes:  {ITU_T_BIND_IMPLICIT(value<CS_GetEventConditionAttributes_Response > (false , Response_Detail_getEventConditionAttributes), 49, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void Response_Detail::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , Response_Detail_otherRequests))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<CS_Status_Response > (true , Response_Detail_status), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 45:  { if (ITU_T_BIND_IMPLICIT(value<CS_GetProgramInvocationAttributes_Response > (true , Response_Detail_getProgramInvocationAttributes), 45, CONTEXT_CLASS)) return; else free(); break;}
                        case 49:  { if (ITU_T_BIND_IMPLICIT(value<CS_GetEventConditionAttributes_Response > (true , Response_Detail_getEventConditionAttributes), 49, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Confirmed-ErrorPDU

        template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(invokeID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(modifierPosition_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(serviceError_, 2, CONTEXT_CLASS);
        }

        template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(invokeID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(modifierPosition_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(serviceError_, 2, CONTEXT_CLASS);
        }

    // sequence ServiceError

        template<> void ServiceError::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(errorClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalCode_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalDescription_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(serviceSpecificInfo_, 3, CONTEXT_CLASS);
        }

        template<> void ServiceError::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(errorClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalCode_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalDescription_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(serviceSpecificInfo_, 3, CONTEXT_CLASS);
        }

    // choice errorClass

        template<> void ServiceError::ErrorClass_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ErrorClass_type_vmd_state:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_vmd_state), 0, CONTEXT_CLASS); break; }
                case ErrorClass_type_application_reference:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_application_reference), 1, CONTEXT_CLASS); break; }
                case ErrorClass_type_definition:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_definition), 2, CONTEXT_CLASS); break; }
                case ErrorClass_type_resource:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_resource), 3, CONTEXT_CLASS); break; }
                case ErrorClass_type_service:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_service), 4, CONTEXT_CLASS); break; }
                case ErrorClass_type_service_preempt:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_service_preempt), 5, CONTEXT_CLASS); break; }
                case ErrorClass_type_time_resolution:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_time_resolution), 6, CONTEXT_CLASS); break; }
                case ErrorClass_type_access:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_access), 7, CONTEXT_CLASS); break; }
                case ErrorClass_type_initiate:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_initiate), 8, CONTEXT_CLASS); break; }
                case ErrorClass_type_conclude:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_conclude), 9, CONTEXT_CLASS); break; }
                case ErrorClass_type_cancel:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_cancel), 10, CONTEXT_CLASS); break; }
                case ErrorClass_type_file:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ErrorClass_type_file), 11, CONTEXT_CLASS); break; }
                case ErrorClass_type_others:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , ErrorClass_type_others), 12, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ServiceError::ErrorClass_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_vmd_state), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_application_reference), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_definition), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_resource), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_service), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_service_preempt), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_time_resolution), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_access), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_initiate), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_conclude), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_cancel), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ErrorClass_type_file), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , ErrorClass_type_others), 12, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice serviceSpecificInfo

        template<> void ServiceError::ServiceSpecificInfo_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ServiceSpecificInfo_type_obtainFile:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ObtainFile_Error > (false , ServiceSpecificInfo_type_obtainFile), 0, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_start:  {ITU_T_BIND_IMPLICIT(value<Start_Error > (false , ServiceSpecificInfo_type_start), 1, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_stop:  {ITU_T_BIND_IMPLICIT(value<Stop_Error > (false , ServiceSpecificInfo_type_stop), 2, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_resume:  {ITU_T_BIND_IMPLICIT(value<Resume_Error > (false , ServiceSpecificInfo_type_resume), 3, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_reset:  {ITU_T_BIND_IMPLICIT(value<Reset_Error > (false , ServiceSpecificInfo_type_reset), 4, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_deleteVariableAccess:  {ITU_T_BIND_IMPLICIT(value<DeleteVariableAccess_Error > (false , ServiceSpecificInfo_type_deleteVariableAccess), 5, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_deleteNamedVariableList:  {ITU_T_BIND_IMPLICIT(value<DeleteNamedVariableList_Error > (false , ServiceSpecificInfo_type_deleteNamedVariableList), 6, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_deleteNamedType:  {ITU_T_BIND_IMPLICIT(value<DeleteNamedType_Error > (false , ServiceSpecificInfo_type_deleteNamedType), 7, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_defineEventEnrollment_Error:  {ITU_T_BIND_CHOICE_TAG(value<DefineEventEnrollment_Error > (false , ServiceSpecificInfo_type_defineEventEnrollment_Error), 8, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_fileRename:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRename_Error > (false , ServiceSpecificInfo_type_fileRename), 9, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_additionalService:  {ITU_T_BIND_CHOICE_TAG(value<AdditionalService_Error > (false , ServiceSpecificInfo_type_additionalService), 10, CONTEXT_CLASS); break; }
                case ServiceSpecificInfo_type_changeAccessControl:  {ITU_T_BIND_IMPLICIT(value<ChangeAccessControl_Error > (false , ServiceSpecificInfo_type_changeAccessControl), 11, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ServiceError::ServiceSpecificInfo_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ObtainFile_Error > (true , ServiceSpecificInfo_type_obtainFile), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Start_Error > (true , ServiceSpecificInfo_type_start), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Stop_Error > (true , ServiceSpecificInfo_type_stop), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Resume_Error > (true , ServiceSpecificInfo_type_resume), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<Reset_Error > (true , ServiceSpecificInfo_type_reset), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<DeleteVariableAccess_Error > (true , ServiceSpecificInfo_type_deleteVariableAccess), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<DeleteNamedVariableList_Error > (true , ServiceSpecificInfo_type_deleteNamedVariableList), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<DeleteNamedType_Error > (true , ServiceSpecificInfo_type_deleteNamedType), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_CHOICE_TAG(value<DefineEventEnrollment_Error > (true , ServiceSpecificInfo_type_defineEventEnrollment_Error), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::FileRename_Error > (true , ServiceSpecificInfo_type_fileRename), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_CHOICE_TAG(value<AdditionalService_Error > (true , ServiceSpecificInfo_type_additionalService), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<ChangeAccessControl_Error > (true , ServiceSpecificInfo_type_changeAccessControl), 11, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice AdditionalService-Error

        template<> void AdditionalService_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AdditionalService_Error_defineEcl:  {ITU_T_BIND_CHOICE_TAG(value<DefineEventConditionList_Error > (false , AdditionalService_Error_defineEcl), 0, CONTEXT_CLASS); break; }
                case AdditionalService_Error_addECLReference:  {ITU_T_BIND_CHOICE_TAG(value<AddEventConditionListReference_Error > (false , AdditionalService_Error_addECLReference), 1, CONTEXT_CLASS); break; }
                case AdditionalService_Error_removeECLReference:  {ITU_T_BIND_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (false , AdditionalService_Error_removeECLReference), 2, CONTEXT_CLASS); break; }
                case AdditionalService_Error_initiateUC:  {ITU_T_BIND_CHOICE_TAG(value<InitiateUnitControl_Error > (false , AdditionalService_Error_initiateUC), 3, CONTEXT_CLASS); break; }
                case AdditionalService_Error_startUC:  {ITU_T_BIND_IMPLICIT(value<StartUnitControl_Error > (false , AdditionalService_Error_startUC), 4, CONTEXT_CLASS); break; }
                case AdditionalService_Error_stopUC:  {ITU_T_BIND_IMPLICIT(value<StopUnitControl_Error > (false , AdditionalService_Error_stopUC), 5, CONTEXT_CLASS); break; }
                case AdditionalService_Error_deleteUC:  {ITU_T_BIND_CHOICE_TAG(value<DeleteUnitControl_Error > (false , AdditionalService_Error_deleteUC), 6, CONTEXT_CLASS); break; }
                case AdditionalService_Error_loadUCFromFile:  {ITU_T_BIND_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (false , AdditionalService_Error_loadUCFromFile), 7, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AdditionalService_Error::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<DefineEventConditionList_Error > (true , AdditionalService_Error_defineEcl), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<AddEventConditionListReference_Error > (true , AdditionalService_Error_addECLReference), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (true , AdditionalService_Error_removeECLReference), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_CHOICE_TAG(value<InitiateUnitControl_Error > (true , AdditionalService_Error_initiateUC), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<StartUnitControl_Error > (true , AdditionalService_Error_startUC), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<StopUnitControl_Error > (true , AdditionalService_Error_stopUC), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_CHOICE_TAG(value<DeleteUnitControl_Error > (true , AdditionalService_Error_deleteUC), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (true , AdditionalService_Error_loadUCFromFile), 7, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice ObjectName

        template<> void ObjectName::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ObjectName_vmd_specific:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ObjectName_vmd_specific), 0, CONTEXT_CLASS); break; }
                case ObjectName_domain_specific:  {ITU_T_BIND_IMPLICIT(value<Domain_specific_type > (false , ObjectName_domain_specific), 1, CONTEXT_CLASS); break; }
                case ObjectName_aa_specific:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ObjectName_aa_specific), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ObjectName::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ObjectName_vmd_specific), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Domain_specific_type > (true , ObjectName_domain_specific), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ObjectName_aa_specific), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence domain-specific

        template<> void ObjectName::Domain_specific_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(domainID_);
            ITU_T_BIND_TAG(itemID_);
        }

        template<> void ObjectName::Domain_specific_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(domainID_);
            ITU_T_BIND_TAG(itemID_);
        }

    // choice ObjectClass

        template<> void ObjectClass::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ObjectClass_basicObjectClass:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ObjectClass_basicObjectClass), 0, CONTEXT_CLASS); break; }
                case ObjectClass_csObjectClass:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , ObjectClass_csObjectClass), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ObjectClass::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ObjectClass_basicObjectClass), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , ObjectClass_csObjectClass), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Initiate-RequestPDU

        template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(localDetailCalling_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedMaxServOutstandingCalling_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedMaxServOutstandingCalled_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedDataStructureNestingLevel_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(initRequestDetail_, 4, CONTEXT_CLASS);
        }

        template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(localDetailCalling_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedMaxServOutstandingCalling_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedMaxServOutstandingCalled_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedDataStructureNestingLevel_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(initRequestDetail_, 4, CONTEXT_CLASS);
        }

    // sequence initRequestDetail

        template<> void Initiate_RequestPDU::InitRequestDetail_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(proposedVersionNumber_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedParameterCBB_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(servicesSupportedCalling_, 2, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_IMPLICIT(additionalSupportedCalling_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalCbbSupportedCalling_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(privilegeClassIdentityCalling_, 5, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

        template<> void Initiate_RequestPDU::InitRequestDetail_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(proposedVersionNumber_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(proposedParameterCBB_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(servicesSupportedCalling_, 2, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_IMPLICIT(additionalSupportedCalling_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalCbbSupportedCalling_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(privilegeClassIdentityCalling_, 5, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

    // sequence Initiate-ResponsePDU

        template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(localDetailCalled_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedMaxServOutstandingCalling_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedMaxServOutstandingCalled_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedDataStructureNestingLevel_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(initResponseDetail_, 4, CONTEXT_CLASS);
        }

        template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(localDetailCalled_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedMaxServOutstandingCalling_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedMaxServOutstandingCalled_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedDataStructureNestingLevel_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(initResponseDetail_, 4, CONTEXT_CLASS);
        }

    // sequence initResponseDetail

        template<> void Initiate_ResponsePDU::InitResponseDetail_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(negotiatedVersionNumber_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedParameterCBB_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(servicesSupportedCalled_, 2, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_IMPLICIT(additionalSupportedCalled_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalCbbSupportedCalled_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(privilegeClassIdentityCalled_, 5, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

        template<> void Initiate_ResponsePDU::InitResponseDetail_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(negotiatedVersionNumber_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(negotiatedParameterCBB_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(servicesSupportedCalled_, 2, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

            ITU_T_BIND_IMPLICIT(additionalSupportedCalled_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(additionalCbbSupportedCalled_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(privilegeClassIdentityCalled_, 5, CONTEXT_CLASS);

            ITU_T_RESET_EXTENTION;

        }

    // sequence Cancel-ErrorPDU

        template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(originalInvokeID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(serviceError_, 1, CONTEXT_CLASS);
        }

        template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(originalInvokeID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(serviceError_, 1, CONTEXT_CLASS);
        }

    // sequence RejectPDU

        template<> void RejectPDU::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(originalInvokeID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(rejectReason_);
        }

        template<> void RejectPDU::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(originalInvokeID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(rejectReason_);
        }

    // choice rejectReason

        template<> void RejectPDU::RejectReason_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case RejectReason_type_confirmed_requestPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_confirmed_requestPDU), 1, CONTEXT_CLASS); break; }
                case RejectReason_type_confirmed_responsePDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_confirmed_responsePDU), 2, CONTEXT_CLASS); break; }
                case RejectReason_type_confirmed_errorPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_confirmed_errorPDU), 3, CONTEXT_CLASS); break; }
                case RejectReason_type_unconfirmedPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_unconfirmedPDU), 4, CONTEXT_CLASS); break; }
                case RejectReason_type_pdu_error:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , RejectReason_type_pdu_error), 5, CONTEXT_CLASS); break; }
                case RejectReason_type_cancel_requestPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_cancel_requestPDU), 6, CONTEXT_CLASS); break; }
                case RejectReason_type_cancel_responsePDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_cancel_responsePDU), 7, CONTEXT_CLASS); break; }
                case RejectReason_type_cancel_errorPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_cancel_errorPDU), 8, CONTEXT_CLASS); break; }
                case RejectReason_type_conclude_requestPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_conclude_requestPDU), 9, CONTEXT_CLASS); break; }
                case RejectReason_type_conclude_responsePDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_conclude_responsePDU), 10, CONTEXT_CLASS); break; }
                case RejectReason_type_conclude_errorPDU:  {ITU_T_BIND_IMPLICIT(value<uint8_t > (false , RejectReason_type_conclude_errorPDU), 11, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void RejectPDU::RejectReason_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_confirmed_requestPDU), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_confirmed_responsePDU), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_confirmed_errorPDU), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_unconfirmedPDU), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , RejectReason_type_pdu_error), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_cancel_requestPDU), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_cancel_responsePDU), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 8:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_cancel_errorPDU), 8, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_conclude_requestPDU), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_conclude_responsePDU), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<uint8_t > (true , RejectReason_type_conclude_errorPDU), 11, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence DefineAccessControlList-Request

        template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(accessControlListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlListElements_, 1, CONTEXT_CLASS);
        }

        template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(accessControlListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlListElements_, 1, CONTEXT_CLASS);
        }

    // sequence accessControlListElements

        template<> void DefineAccessControlList_Request::AccessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(readAccessCondition_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(storeAccessCondition_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(writeAccessCondition_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadAccessCondition_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(executeAccessCondition_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(deleteAccessCondition_, 5, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(editAccessCondition_, 6, CONTEXT_CLASS);
        }

        template<> void DefineAccessControlList_Request::AccessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(readAccessCondition_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(storeAccessCondition_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(writeAccessCondition_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadAccessCondition_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(executeAccessCondition_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(deleteAccessCondition_, 5, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(editAccessCondition_, 6, CONTEXT_CLASS);
        }

    // choice GetAccessControlListAttributes-Request

        template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case GetAccessControlListAttributes_Request_accessControlListName:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , GetAccessControlListAttributes_Request_accessControlListName), 0, CONTEXT_CLASS); break; }
                case GetAccessControlListAttributes_Request_vMD:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , GetAccessControlListAttributes_Request_vMD), 1, CONTEXT_CLASS); break; }
                case GetAccessControlListAttributes_Request_namedObject:  {ITU_T_BIND_IMPLICIT(value<NamedObject_type > (false , GetAccessControlListAttributes_Request_namedObject), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , GetAccessControlListAttributes_Request_accessControlListName), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , GetAccessControlListAttributes_Request_vMD), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<NamedObject_type > (true , GetAccessControlListAttributes_Request_namedObject), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence namedObject

        template<> void GetAccessControlListAttributes_Request::NamedObject_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectName_, 1, CONTEXT_CLASS);
        }

        template<> void GetAccessControlListAttributes_Request::NamedObject_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectName_, 1, CONTEXT_CLASS);
        }

    // sequence GetAccessControlListAttributes-Response

        template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_EXPLICIT(name_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlListElements_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(vMDuse_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(references_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 4, CONTEXT_CLASS);
        }

        template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_EXPLICIT(name_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlListElements_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(vMDuse_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(references_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 4, CONTEXT_CLASS);
        }

    // sequence accessControlListElements

        template<> void GetAccessControlListAttributes_Response::AccessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(readAccessCondition_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(storeAccessCondition_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(writeAccessCondition_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadAccessCondition_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(executeAccessCondition_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(deleteAccessCondition_, 5, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(editAccessCondition_, 6, CONTEXT_CLASS);
        }

        template<> void GetAccessControlListAttributes_Response::AccessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(readAccessCondition_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(storeAccessCondition_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(writeAccessCondition_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadAccessCondition_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(executeAccessCondition_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(deleteAccessCondition_, 5, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(editAccessCondition_, 6, CONTEXT_CLASS);
        }

    // sequence 

        template<> void GetAccessControlListAttributes_Response::References_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(objectCount_, 1, CONTEXT_CLASS);
        }

        template<> void GetAccessControlListAttributes_Response::References_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(objectCount_, 1, CONTEXT_CLASS);
        }

    // sequence ReportAccessControlledObjects-Request

        template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(accessControlList_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectClass_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 2, CONTEXT_CLASS);
        }

        template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(accessControlList_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectClass_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 2, CONTEXT_CLASS);
        }

    // sequence ReportAccessControlledObjects-Response

        template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfNames_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfNames_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence ChangeAccessControl-Request

        template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(scopeOfChange_);
            ITU_T_BIND_IMPLICIT(accessControlListName_, 2, CONTEXT_CLASS);
        }

        template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(scopeOfChange_);
            ITU_T_BIND_IMPLICIT(accessControlListName_, 2, CONTEXT_CLASS);
        }

    // choice scopeOfChange

        template<> void ChangeAccessControl_Request::ScopeOfChange_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ScopeOfChange_type_vMDOnly:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , ScopeOfChange_type_vMDOnly), 0, CONTEXT_CLASS); break; }
                case ScopeOfChange_type_listOfObjects:  {ITU_T_BIND_IMPLICIT(value<ListOfObjects_type > (false , ScopeOfChange_type_listOfObjects), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ChangeAccessControl_Request::ScopeOfChange_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , ScopeOfChange_type_vMDOnly), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<ListOfObjects_type > (true , ScopeOfChange_type_listOfObjects), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence listOfObjects

        template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectScope_, 1, CONTEXT_CLASS);
        }

        template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectScope_, 1, CONTEXT_CLASS);
        }

    // choice objectScope

        template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ObjectScope_type_specific:  {ITU_T_BIND_IMPLICIT(value<Specific_type > (false , ObjectScope_type_specific), 0, CONTEXT_CLASS); break; }
                case ObjectScope_type_aa_specific:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , ObjectScope_type_aa_specific), 1, CONTEXT_CLASS); break; }
                case ObjectScope_type_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ObjectScope_type_domain), 2, CONTEXT_CLASS); break; }
                case ObjectScope_type_vmd:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , ObjectScope_type_vmd), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Specific_type > (true , ObjectScope_type_specific), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , ObjectScope_type_aa_specific), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ObjectScope_type_domain), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , ObjectScope_type_vmd), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence ChangeAccessControl-Response

        template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberChanged_, 1, CONTEXT_CLASS);
        }

        template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberChanged_, 1, CONTEXT_CLASS);
        }

    // sequence StatusResponse

        template<> void StatusResponse::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(vmdLogicalStatus_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(vmdPhysicalStatus_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(localDetail_, 2, CONTEXT_CLASS);
        }

        template<> void StatusResponse::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(vmdLogicalStatus_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(vmdPhysicalStatus_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(localDetail_, 2, CONTEXT_CLASS);
        }

    // choice CS-Status-Response

        template<> void CS_Status_Response::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_Status_Response_fullResponse:  {ITU_T_BIND_TAG(value<FullResponse_type > (false , CS_Status_Response_fullResponse)); break; }
                case CS_Status_Response_noExtraResponse:  {ITU_T_BIND_TAG(value<null_type > (false , CS_Status_Response_noExtraResponse)); break; }
                default:{}
            }
        }

        template<> void CS_Status_Response::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 16:  { if (ITU_T_BIND_TAG(value<FullResponse_type > (true , CS_Status_Response_fullResponse))) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , CS_Status_Response_noExtraResponse))) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence fullResponse

        template<> void CS_Status_Response::FullResponse_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(operationState_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(extendedStatus_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(extendedStatusMask_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(selectedProgramInvocation_);
        }

        template<> void CS_Status_Response::FullResponse_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(operationState_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(extendedStatus_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(extendedStatusMask_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(selectedProgramInvocation_);
        }

    // choice selectedProgramInvocation

        template<> void CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case SelectedProgramInvocation_type_programInvocation:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , SelectedProgramInvocation_type_programInvocation), 3, CONTEXT_CLASS); break; }
                case SelectedProgramInvocation_type_noneSelected:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , SelectedProgramInvocation_type_noneSelected), 4, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , SelectedProgramInvocation_type_programInvocation), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , SelectedProgramInvocation_type_noneSelected), 4, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetNameList-Request

        template<> void GetNameList_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectScope_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(continueAfter_, 2, CONTEXT_CLASS);
        }

        template<> void GetNameList_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(objectScope_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(continueAfter_, 2, CONTEXT_CLASS);
        }

    // choice objectScope

        template<> void GetNameList_Request::ObjectScope_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ObjectScope_type_vmdSpecific:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , ObjectScope_type_vmdSpecific), 0, CONTEXT_CLASS); break; }
                case ObjectScope_type_domainSpecific:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ObjectScope_type_domainSpecific), 1, CONTEXT_CLASS); break; }
                case ObjectScope_type_aaSpecific:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , ObjectScope_type_aaSpecific), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void GetNameList_Request::ObjectScope_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , ObjectScope_type_vmdSpecific), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ObjectScope_type_domainSpecific), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , ObjectScope_type_aaSpecific), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetNameList-Response

        template<> void GetNameList_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfIdentifier_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void GetNameList_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfIdentifier_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence Identify-Response

        template<> void Identify_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(vendorName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(modelName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(revision_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfAbstractSyntaxes_, 3, CONTEXT_CLASS);
        }

        template<> void Identify_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(vendorName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(modelName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(revision_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfAbstractSyntaxes_, 3, CONTEXT_CLASS);
        }

    // sequence Rename-Request

        template<> void Rename_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(currentName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(newIdentifier_, 2, CONTEXT_CLASS);
        }

        template<> void Rename_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(objectClass_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(currentName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(newIdentifier_, 2, CONTEXT_CLASS);
        }

    // sequence GetCapabilityList-Request

        template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(continueAfter_);
        }

        template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(continueAfter_);
        }

    // sequence GetCapabilityList-Response

        template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence InitiateDownloadSequence-Request

        template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 2, CONTEXT_CLASS);
        }

        template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 2, CONTEXT_CLASS);
        }

    // sequence DownloadSegment-Response

        template<> void DownloadSegment_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(loadData_);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void DownloadSegment_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(loadData_);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // choice LoadData

        template<> void LoadData::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case LoadData_non_coded:  {ITU_T_BIND_IMPLICIT(value<octet_string > (false , LoadData_non_coded), 0, CONTEXT_CLASS); break; }
                case LoadData_coded:  {ITU_T_BIND_TAG(value<external_type > (false , LoadData_coded)); break; }
                case LoadData_embedded:  {ITU_T_BIND_TAG(value<embeded_pdv > (false , LoadData_embedded)); break; }
                default:{}
            }
        }

        template<> void LoadData::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 8:  { if (ITU_T_BIND_TAG(value<external_type > (true , LoadData_coded))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_TAG(value<embeded_pdv > (true , LoadData_embedded))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<octet_string > (true , LoadData_non_coded), 0, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence TerminateDownloadSequence-Request

        template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(discard_, 1, CONTEXT_CLASS);
        }

        template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(discard_, 1, CONTEXT_CLASS);
        }

    // sequence InitiateUploadSequence-Response

        template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(ulsmID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
        }

        template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(ulsmID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
        }

    // sequence UploadSegment-Response

        template<> void UploadSegment_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(loadData_);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void UploadSegment_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(loadData_);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence RequestDomainDownload-Request

        template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 4, CONTEXT_CLASS);
        }

        template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 4, CONTEXT_CLASS);
        }

    // sequence RequestDomainUpload-Request

        template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
        }

        template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
        }

    // sequence LoadDomainContent-Request

        template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 5, CONTEXT_CLASS);
        }

        template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 5, CONTEXT_CLASS);
        }

    // sequence StoreDomainContent-Request

        template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 2, CONTEXT_CLASS);
        }

        template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 2, CONTEXT_CLASS);
        }

    // sequence GetDomainAttributes-Response

        template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(state_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfProgramInvocations_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(uploadInProgress_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 6, CONTEXT_CLASS);
        }

        template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfCapabilities_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(state_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfProgramInvocations_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(uploadInProgress_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 6, CONTEXT_CLASS);
        }

    // sequence CreateProgramInvocation-Request

        template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfDomainNames_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(reusable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(monitorType_, 3, CONTEXT_CLASS);
        }

        template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfDomainNames_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(reusable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(monitorType_, 3, CONTEXT_CLASS);
        }

    // sequence Start-Request

        template<> void Start_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
        }

        template<> void Start_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
        }

    // choice executionArgument

        template<> void Start_Request::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ExecutionArgument_type_simpleString:  {ITU_T_BIND_IMPLICIT(value<MMSString > (false , ExecutionArgument_type_simpleString), 1, CONTEXT_CLASS); break; }
                case ExecutionArgument_type_encodedString:  {ITU_T_BIND_TAG(value<external_type > (false , ExecutionArgument_type_encodedString)); break; }
                case ExecutionArgument_type_embeddedString:  {ITU_T_BIND_TAG(value<embeded_pdv > (false , ExecutionArgument_type_embeddedString)); break; }
                default:{}
            }
        }

        template<> void Start_Request::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 8:  { if (ITU_T_BIND_TAG(value<external_type > (true , ExecutionArgument_type_encodedString))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_TAG(value<embeded_pdv > (true , ExecutionArgument_type_embeddedString))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<MMSString > (true , ExecutionArgument_type_simpleString), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice CS-Start-Request

        template<> void CS_Start_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_Start_Request_normal:  {ITU_T_BIND_TAG(value<null_type > (false , CS_Start_Request_normal)); break; }
                case CS_Start_Request_controlling:  {ITU_T_BIND_TAG(value<Controlling_type > (false , CS_Start_Request_controlling)); break; }
                default:{}
            }
        }

        template<> void CS_Start_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , CS_Start_Request_normal))) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_TAG(value<Controlling_type > (true , CS_Start_Request_controlling))) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence controlling

        template<> void CS_Start_Request::Controlling_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(startLocation_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(startCount_, 1, CONTEXT_CLASS);
        }

        template<> void CS_Start_Request::Controlling_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(startLocation_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(startCount_, 1, CONTEXT_CLASS);
        }

    // choice StartCount

        template<> void StartCount::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case StartCount_noLimit:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , StartCount_noLimit), 0, CONTEXT_CLASS); break; }
                case StartCount_cycleCount:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , StartCount_cycleCount), 1, CONTEXT_CLASS); break; }
                case StartCount_stepCount:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , StartCount_stepCount), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void StartCount::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , StartCount_noLimit), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , StartCount_cycleCount), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , StartCount_stepCount), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Stop-Request

        template<> void Stop_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
        }

        template<> void Stop_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
        }

    // sequence Resume-Request

        template<> void Resume_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
        }

        template<> void Resume_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
        }

    // choice executionArgument

        template<> void Resume_Request::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ExecutionArgument_type_simpleString:  {ITU_T_BIND_IMPLICIT(value<MMSString > (false , ExecutionArgument_type_simpleString), 1, CONTEXT_CLASS); break; }
                case ExecutionArgument_type_encodedString:  {ITU_T_BIND_TAG(value<external_type > (false , ExecutionArgument_type_encodedString)); break; }
                case ExecutionArgument_type_enmbeddedString:  {ITU_T_BIND_TAG(value<embeded_pdv > (false , ExecutionArgument_type_enmbeddedString)); break; }
                default:{}
            }
        }

        template<> void Resume_Request::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 8:  { if (ITU_T_BIND_TAG(value<external_type > (true , ExecutionArgument_type_encodedString))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_TAG(value<embeded_pdv > (true , ExecutionArgument_type_enmbeddedString))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<MMSString > (true , ExecutionArgument_type_simpleString), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice CS-Resume-Request

        template<> void CS_Resume_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_Resume_Request_normal:  {ITU_T_BIND_TAG(value<null_type > (false , CS_Resume_Request_normal)); break; }
                case CS_Resume_Request_controlling:  {ITU_T_BIND_TAG(value<Controlling_type > (false , CS_Resume_Request_controlling)); break; }
                default:{}
            }
        }

        template<> void CS_Resume_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , CS_Resume_Request_normal))) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_TAG(value<Controlling_type > (true , CS_Resume_Request_controlling))) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence controlling

        template<> void CS_Resume_Request::Controlling_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(modeType_);
        }

        template<> void CS_Resume_Request::Controlling_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(modeType_);
        }

    // choice modeType

        template<> void CS_Resume_Request::Controlling_type::ModeType_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ModeType_type_continueMode:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , ModeType_type_continueMode), 0, CONTEXT_CLASS); break; }
                case ModeType_type_changeMode:  {ITU_T_BIND_CHOICE_TAG(value<StartCount > (false , ModeType_type_changeMode), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_Resume_Request::Controlling_type::ModeType_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , ModeType_type_continueMode), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<StartCount > (true , ModeType_type_changeMode), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Reset-Request

        template<> void Reset_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
        }

        template<> void Reset_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
        }

    // sequence Kill-Request

        template<> void Kill_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
        }

        template<> void Kill_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
        }

    // sequence GetProgramInvocationAttributes-Response

        template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(state_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfDomainNames_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(reusable_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(monitor_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
            ITU_T_BIND_IMPLICIT(accessControlList_, 6, CONTEXT_CLASS);
        }

        template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(state_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfDomainNames_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(reusable_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(monitor_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
            ITU_T_BIND_IMPLICIT(accessControlList_, 6, CONTEXT_CLASS);
        }

    // choice executionArgument

        template<> void GetProgramInvocationAttributes_Response::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ExecutionArgument_type_simpleString:  {ITU_T_BIND_IMPLICIT(value<MMSString > (false , ExecutionArgument_type_simpleString), 5, CONTEXT_CLASS); break; }
                case ExecutionArgument_type_encodedString:  {ITU_T_BIND_TAG(value<external_type > (false , ExecutionArgument_type_encodedString)); break; }
                case ExecutionArgument_type_enmbeddedString:  {ITU_T_BIND_TAG(value<embeded_pdv > (false , ExecutionArgument_type_enmbeddedString)); break; }
                default:{}
            }
        }

        template<> void GetProgramInvocationAttributes_Response::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 8:  { if (ITU_T_BIND_TAG(value<external_type > (true , ExecutionArgument_type_encodedString))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_TAG(value<embeded_pdv > (true , ExecutionArgument_type_enmbeddedString))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<MMSString > (true , ExecutionArgument_type_simpleString), 5, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence CS-GetProgramInvocationAttributes-Response

        template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(errorCode_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(control_, 1, CONTEXT_CLASS);
        }

        template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(errorCode_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(control_, 1, CONTEXT_CLASS);
        }

    // choice control

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Control_type_controlling:  {ITU_T_BIND_IMPLICIT(value<Controlling_type > (false , Control_type_controlling), 0, CONTEXT_CLASS); break; }
                case Control_type_controlled:  {ITU_T_BIND_CHOICE_TAG(value<Controlled_type > (false , Control_type_controlled), 1, CONTEXT_CLASS); break; }
                case Control_type_normal:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , Control_type_normal), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Controlling_type > (true , Control_type_controlling), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<Controlled_type > (true , Control_type_controlled), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , Control_type_normal), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence controlling

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(controlledPI_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programLocation_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(runningMode_, 2, CONTEXT_CLASS);
        }

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(controlledPI_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programLocation_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(runningMode_, 2, CONTEXT_CLASS);
        }

    // choice runningMode

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case RunningMode_type_freeRunning:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , RunningMode_type_freeRunning), 0, CONTEXT_CLASS); break; }
                case RunningMode_type_cycleLimited:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , RunningMode_type_cycleLimited), 1, CONTEXT_CLASS); break; }
                case RunningMode_type_stepLimited:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , RunningMode_type_stepLimited), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , RunningMode_type_freeRunning), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , RunningMode_type_cycleLimited), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , RunningMode_type_stepLimited), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice controlled

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Controlled_type_controllingPI:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , Controlled_type_controllingPI), 0, CONTEXT_CLASS); break; }
                case Controlled_type_none:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , Controlled_type_none), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , Controlled_type_controllingPI), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , Controlled_type_none), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence Select-Request

        template<> void Select_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(controlling_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(controlled_, 1, CONTEXT_CLASS);
        }

        template<> void Select_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(controlling_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(controlled_, 1, CONTEXT_CLASS);
        }

    // sequence AlterProgramInvocationAttributes-Request

        template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocation_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(startCount_, 1, CONTEXT_CLASS);
        }

        template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocation_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(startCount_, 1, CONTEXT_CLASS);
        }

    // sequence ReconfigureProgramInvocation-Request

        template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(oldProgramInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(newProgramInvocationName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainsToAdd_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainsToRemove_, 3, CONTEXT_CLASS);
        }

        template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(oldProgramInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(newProgramInvocationName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainsToAdd_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainsToRemove_, 3, CONTEXT_CLASS);
        }

    // choice ControlElement

        template<> void ControlElement::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ControlElement_beginDomainDef:  {ITU_T_BIND_EXPLICIT(value<BeginDomainDef_type > (false , ControlElement_beginDomainDef), 0, CONTEXT_CLASS); break; }
                case ControlElement_continueDomainDef:  {ITU_T_BIND_EXPLICIT(value<ContinueDomainDef_type > (false , ControlElement_continueDomainDef), 1, CONTEXT_CLASS); break; }
                case ControlElement_endDomainDef:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ControlElement_endDomainDef), 2, CONTEXT_CLASS); break; }
                case ControlElement_piDefinition:  {ITU_T_BIND_IMPLICIT(value<PiDefinition_type > (false , ControlElement_piDefinition), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ControlElement::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_EXPLICIT(value<BeginDomainDef_type > (true , ControlElement_beginDomainDef), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_EXPLICIT(value<ContinueDomainDef_type > (true , ControlElement_continueDomainDef), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ControlElement_endDomainDef), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<PiDefinition_type > (true , ControlElement_piDefinition), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence beginDomainDef

        template<> void ControlElement::BeginDomainDef_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(capabilities_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadData_, 4, CONTEXT_CLASS);
        }

        template<> void ControlElement::BeginDomainDef_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(capabilities_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(sharable_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadData_, 4, CONTEXT_CLASS);
        }

    // sequence continueDomainDef

        template<> void ControlElement::ContinueDomainDef_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadData_, 3, CONTEXT_CLASS);
        }

        template<> void ControlElement::ContinueDomainDef_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domainName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(loadData_, 3, CONTEXT_CLASS);
        }

    // sequence piDefinition

        template<> void ControlElement::PiDefinition_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(piName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfDomains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(reusable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(monitorType_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(pIState_, 4, CONTEXT_CLASS);
        }

        template<> void ControlElement::PiDefinition_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(piName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfDomains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(reusable_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(monitorType_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(pIState_, 4, CONTEXT_CLASS);
        }

    // choice InitiateUnitControl-Error

        template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case InitiateUnitControl_Error_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , InitiateUnitControl_Error_domain), 0, CONTEXT_CLASS); break; }
                case InitiateUnitControl_Error_programInvocation:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , InitiateUnitControl_Error_programInvocation), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , InitiateUnitControl_Error_domain), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , InitiateUnitControl_Error_programInvocation), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence UnitControlLoadSegment-Response

        template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(controlElements_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(controlElements_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence UnitControlUpload-Request

        template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(continueAfter_);
        }

        template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(continueAfter_);
        }

    // choice continueAfter

        template<> void UnitControlUpload_Request::ContinueAfter_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ContinueAfter_type_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ContinueAfter_type_domain), 1, CONTEXT_CLASS); break; }
                case ContinueAfter_type_ulsmID:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , ContinueAfter_type_ulsmID), 2, CONTEXT_CLASS); break; }
                case ContinueAfter_type_programInvocation:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ContinueAfter_type_programInvocation), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void UnitControlUpload_Request::ContinueAfter_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ContinueAfter_type_domain), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , ContinueAfter_type_ulsmID), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ContinueAfter_type_programInvocation), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence UnitControlUpload-Response

        template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(controlElements_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(nextElement_);
        }

        template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(controlElements_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(nextElement_);
        }

    // choice nextElement

        template<> void UnitControlUpload_Response::NextElement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case NextElement_type_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , NextElement_type_domain), 1, CONTEXT_CLASS); break; }
                case NextElement_type_ulsmID:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , NextElement_type_ulsmID), 2, CONTEXT_CLASS); break; }
                case NextElement_type_programInvocation:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , NextElement_type_programInvocation), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void UnitControlUpload_Response::NextElement_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , NextElement_type_domain), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , NextElement_type_ulsmID), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , NextElement_type_programInvocation), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence StartUnitControl-Request

        template<> void StartUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
        }

        template<> void StartUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(executionArgument_);
        }

    // choice executionArgument

        template<> void StartUnitControl_Request::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ExecutionArgument_type_simpleString:  {ITU_T_BIND_IMPLICIT(value<MMSString > (false , ExecutionArgument_type_simpleString), 1, CONTEXT_CLASS); break; }
                case ExecutionArgument_type_encodedString:  {ITU_T_BIND_TAG(value<external_type > (false , ExecutionArgument_type_encodedString)); break; }
                case ExecutionArgument_type_enmbeddedString:  {ITU_T_BIND_TAG(value<embeded_pdv > (false , ExecutionArgument_type_enmbeddedString)); break; }
                default:{}
            }
        }

        template<> void StartUnitControl_Request::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 8:  { if (ITU_T_BIND_TAG(value<external_type > (true , ExecutionArgument_type_encodedString))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_TAG(value<embeded_pdv > (true , ExecutionArgument_type_enmbeddedString))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<MMSString > (true , ExecutionArgument_type_simpleString), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence StartUnitControl-Error

        template<> void StartUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocationState_, 1, CONTEXT_CLASS);
        }

        template<> void StartUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocationState_, 1, CONTEXT_CLASS);
        }

    // sequence StopUnitControl-Error

        template<> void StopUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocationState_, 1, CONTEXT_CLASS);
        }

        template<> void StopUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(programInvocationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocationState_, 1, CONTEXT_CLASS);
        }

    // sequence CreateUnitControl-Request

        template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControl_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 2, CONTEXT_CLASS);
        }

        template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControl_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 2, CONTEXT_CLASS);
        }

    // sequence AddToUnitControl-Request

        template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControl_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 2, CONTEXT_CLASS);
        }

        template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControl_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 2, CONTEXT_CLASS);
        }

    // sequence RemoveFromUnitControl-Request

        template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControl_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 2, CONTEXT_CLASS);
        }

        template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControl_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domains_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 2, CONTEXT_CLASS);
        }

    // sequence GetUnitControlAttributes-Response

        template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(domains_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 1, CONTEXT_CLASS);
        }

        template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(domains_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocations_, 1, CONTEXT_CLASS);
        }

    // sequence LoadUnitControlFromFile-Request

        template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 2, CONTEXT_CLASS);
        }

        template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 2, CONTEXT_CLASS);
        }

    // choice LoadUnitControlFromFile-Error

        template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case LoadUnitControlFromFile_Error_none:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , LoadUnitControlFromFile_Error_none), 0, CONTEXT_CLASS); break; }
                case LoadUnitControlFromFile_Error_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , LoadUnitControlFromFile_Error_domain), 1, CONTEXT_CLASS); break; }
                case LoadUnitControlFromFile_Error_programInvocation:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , LoadUnitControlFromFile_Error_programInvocation), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , LoadUnitControlFromFile_Error_none), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , LoadUnitControlFromFile_Error_domain), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , LoadUnitControlFromFile_Error_programInvocation), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence StoreUnitControlToFile-Request

        template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 2, CONTEXT_CLASS);
        }

        template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(unitControlName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fileName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(thirdParty_, 2, CONTEXT_CLASS);
        }

    // choice DeleteUnitControl-Error

        template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteUnitControl_Error_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , DeleteUnitControl_Error_domain), 0, CONTEXT_CLASS); break; }
                case DeleteUnitControl_Error_programInvocation:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , DeleteUnitControl_Error_programInvocation), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , DeleteUnitControl_Error_domain), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , DeleteUnitControl_Error_programInvocation), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice TypeSpecification

        template<> void TypeSpecification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case TypeSpecification_typeName:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , TypeSpecification_typeName), 0, CONTEXT_CLASS); break; }
                case TypeSpecification_typeDescription:  {ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (false , TypeSpecification_typeDescription)); break; }
                default:{}
            }
        }

        template<> void TypeSpecification::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , TypeSpecification_typeName), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice 

        template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AlternateAccess_sequence_of_unnamed:  {ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (false , AlternateAccess_sequence_of_unnamed)); break; }
                case AlternateAccess_sequence_of_named:  {ITU_T_BIND_IMPLICIT(value<Named_type > (false , AlternateAccess_sequence_of_named), 5, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<Named_type > (true , AlternateAccess_sequence_of_named), 5, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence named

        template<> void AlternateAccess_sequence_of::Named_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(componentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(access_);
        }

        template<> void AlternateAccess_sequence_of::Named_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(componentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(access_);
        }

    // choice AlternateAccessSelection

        template<> void AlternateAccessSelection::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AlternateAccessSelection_selectAlternateAccess:  {ITU_T_BIND_IMPLICIT(value<SelectAlternateAccess_type > (false , AlternateAccessSelection_selectAlternateAccess), 0, CONTEXT_CLASS); break; }
                case AlternateAccessSelection_selectAccess:  {ITU_T_BIND_CHOICE(value<SelectAccess_type > (false , AlternateAccessSelection_selectAccess)); break; }
                default:{}
            }
        }

        template<> void AlternateAccessSelection::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<SelectAlternateAccess_type > (true , AlternateAccessSelection_selectAlternateAccess), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE(value<SelectAccess_type > (true , AlternateAccessSelection_selectAccess))) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_CHOICE(value<SelectAccess_type > (true , AlternateAccessSelection_selectAccess))) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_CHOICE(value<SelectAccess_type > (true , AlternateAccessSelection_selectAccess))) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_CHOICE(value<SelectAccess_type > (true , AlternateAccessSelection_selectAccess))) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence selectAlternateAccess

        template<> void AlternateAccessSelection::SelectAlternateAccess_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(accessSelection_);
            ITU_T_BIND_TAG(alternateAccess_);
        }

        template<> void AlternateAccessSelection::SelectAlternateAccess_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(accessSelection_);
            ITU_T_BIND_TAG(alternateAccess_);
        }

    // choice accessSelection

        template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AccessSelection_type_component:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , AccessSelection_type_component), 0, CONTEXT_CLASS); break; }
                case AccessSelection_type_index:  {ITU_T_BIND_IMPLICIT(value<Unsigned32 > (false , AccessSelection_type_index), 1, CONTEXT_CLASS); break; }
                case AccessSelection_type_indexRange:  {ITU_T_BIND_IMPLICIT(value<IndexRange_type > (false , AccessSelection_type_indexRange), 2, CONTEXT_CLASS); break; }
                case AccessSelection_type_allElements:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , AccessSelection_type_allElements), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , AccessSelection_type_component), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Unsigned32 > (true , AccessSelection_type_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<IndexRange_type > (true , AccessSelection_type_indexRange), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , AccessSelection_type_allElements), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence indexRange

        template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(lowIndex_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfElements_, 1, CONTEXT_CLASS);
        }

        template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(lowIndex_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfElements_, 1, CONTEXT_CLASS);
        }

    // choice selectAccess

        template<> void AlternateAccessSelection::SelectAccess_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case SelectAccess_type_component:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , SelectAccess_type_component), 1, CONTEXT_CLASS); break; }
                case SelectAccess_type_index:  {ITU_T_BIND_IMPLICIT(value<Unsigned32 > (false , SelectAccess_type_index), 2, CONTEXT_CLASS); break; }
                case SelectAccess_type_indexRange:  {ITU_T_BIND_IMPLICIT(value<IndexRange_type > (false , SelectAccess_type_indexRange), 3, CONTEXT_CLASS); break; }
                case SelectAccess_type_allElements:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , SelectAccess_type_allElements), 4, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AlternateAccessSelection::SelectAccess_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , SelectAccess_type_component), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Unsigned32 > (true , SelectAccess_type_index), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<IndexRange_type > (true , SelectAccess_type_indexRange), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , SelectAccess_type_allElements), 4, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence indexRange

        template<> void AlternateAccessSelection::SelectAccess_type::IndexRange_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(lowIndex_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfElements_, 1, CONTEXT_CLASS);
        }

        template<> void AlternateAccessSelection::SelectAccess_type::IndexRange_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(lowIndex_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfElements_, 1, CONTEXT_CLASS);
        }

    // choice AccessResult

        template<> void AccessResult::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AccessResult_failure:  {ITU_T_BIND_IMPLICIT(value<DataAccessError > (false , AccessResult_failure), 0, CONTEXT_CLASS); break; }
                case AccessResult_success:  {ITU_T_BIND_CHOICE(value<Data > (false , AccessResult_success)); break; }
                default:{}
            }
        }

        template<> void AccessResult::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<DataAccessError > (true , AccessResult_failure), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 14:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_CHOICE(value<Data > (true , AccessResult_success))) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice Data

        template<> void Data::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Data_array:  {ITU_T_BIND_IMPLICIT(value<Array_type > (false , Data_array), 1, CONTEXT_CLASS); break; }
                case Data_structure:  {ITU_T_BIND_IMPLICIT(value<Structure_type > (false , Data_structure), 2, CONTEXT_CLASS); break; }
                case Data_boolean:  {ITU_T_BIND_IMPLICIT(value<bool > (false , Data_boolean), 3, CONTEXT_CLASS); break; }
                case Data_bit_stringV:  {ITU_T_BIND_IMPLICIT(value<bit_string > (false , Data_bit_stringV), 4, CONTEXT_CLASS); break; }
                case Data_integer:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , Data_integer), 5, CONTEXT_CLASS); break; }
                case Data_unsignedV:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , Data_unsignedV), 6, CONTEXT_CLASS); break; }
                case Data_floating_point:  {ITU_T_BIND_IMPLICIT(value<FloatingPoint > (false , Data_floating_point), 7, CONTEXT_CLASS); break; }
                case Data_octet_stringV:  {ITU_T_BIND_IMPLICIT(value<octet_string > (false , Data_octet_stringV), 9, CONTEXT_CLASS); break; }
                case Data_visible_stringV:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , Data_visible_stringV), 10, CONTEXT_CLASS); break; }
                case Data_generalized_time:  {ITU_T_BIND_IMPLICIT(value<gentime > (false , Data_generalized_time), 11, CONTEXT_CLASS); break; }
                case Data_binary_time:  {ITU_T_BIND_IMPLICIT(value<TimeOfDay > (false , Data_binary_time), 12, CONTEXT_CLASS); break; }
                case Data_bcd:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , Data_bcd), 13, CONTEXT_CLASS); break; }
                case Data_booleanArray:  {ITU_T_BIND_IMPLICIT(value<bit_string > (false , Data_booleanArray), 14, CONTEXT_CLASS); break; }
                case Data_objId:  {ITU_T_BIND_IMPLICIT(value<oid_type > (false , Data_objId), 15, CONTEXT_CLASS); break; }
                case Data_mMSString:  {ITU_T_BIND_IMPLICIT(value<MMSString > (false , Data_mMSString), 16, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void Data::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Array_type > (true , Data_array), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Structure_type > (true , Data_structure), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<bool > (true , Data_boolean), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<bit_string > (true , Data_bit_stringV), 4, CONTEXT_CLASS)) return; else free(); break;}
                        case 5:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , Data_integer), 5, CONTEXT_CLASS)) return; else free(); break;}
                        case 6:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , Data_unsignedV), 6, CONTEXT_CLASS)) return; else free(); break;}
                        case 7:  { if (ITU_T_BIND_IMPLICIT(value<FloatingPoint > (true , Data_floating_point), 7, CONTEXT_CLASS)) return; else free(); break;}
                        case 9:  { if (ITU_T_BIND_IMPLICIT(value<octet_string > (true , Data_octet_stringV), 9, CONTEXT_CLASS)) return; else free(); break;}
                        case 10:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , Data_visible_stringV), 10, CONTEXT_CLASS)) return; else free(); break;}
                        case 11:  { if (ITU_T_BIND_IMPLICIT(value<gentime > (true , Data_generalized_time), 11, CONTEXT_CLASS)) return; else free(); break;}
                        case 12:  { if (ITU_T_BIND_IMPLICIT(value<TimeOfDay > (true , Data_binary_time), 12, CONTEXT_CLASS)) return; else free(); break;}
                        case 13:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , Data_bcd), 13, CONTEXT_CLASS)) return; else free(); break;}
                        case 14:  { if (ITU_T_BIND_IMPLICIT(value<bit_string > (true , Data_booleanArray), 14, CONTEXT_CLASS)) return; else free(); break;}
                        case 15:  { if (ITU_T_BIND_IMPLICIT(value<oid_type > (true , Data_objId), 15, CONTEXT_CLASS)) return; else free(); break;}
                        case 16:  { if (ITU_T_BIND_IMPLICIT(value<MMSString > (true , Data_mMSString), 16, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice VariableAccessSpecification

        template<> void VariableAccessSpecification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case VariableAccessSpecification_listOfVariable:  {ITU_T_BIND_IMPLICIT(value<ListOfVariable_type > (false , VariableAccessSpecification_listOfVariable), 0, CONTEXT_CLASS); break; }
                case VariableAccessSpecification_variableListName:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , VariableAccessSpecification_variableListName), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void VariableAccessSpecification::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<ListOfVariable_type > (true , VariableAccessSpecification_listOfVariable), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , VariableAccessSpecification_variableListName), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence 

        template<> void VariableAccessSpecification::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(variableSpecification_);
            ITU_T_BIND_IMPLICIT(alternateAccess_, 5, CONTEXT_CLASS);
        }

        template<> void VariableAccessSpecification::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(variableSpecification_);
            ITU_T_BIND_IMPLICIT(alternateAccess_, 5, CONTEXT_CLASS);
        }

    // choice VariableSpecification

        template<> void VariableSpecification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case VariableSpecification_name:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , VariableSpecification_name), 0, CONTEXT_CLASS); break; }
                case VariableSpecification_address:  {ITU_T_BIND_CHOICE_TAG(value<MMS_Object_Module_1::Address > (false , VariableSpecification_address), 1, CONTEXT_CLASS); break; }
                case VariableSpecification_variableDescription:  {ITU_T_BIND_IMPLICIT(value<VariableDescription_type > (false , VariableSpecification_variableDescription), 2, CONTEXT_CLASS); break; }
                case VariableSpecification_scatteredAccessDescription:  {ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ScatteredAccessDescription > (false , VariableSpecification_scatteredAccessDescription), 3, CONTEXT_CLASS); break; }
                case VariableSpecification_invalidated:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , VariableSpecification_invalidated), 4, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void VariableSpecification::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , VariableSpecification_name), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<MMS_Object_Module_1::Address > (true , VariableSpecification_address), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<VariableDescription_type > (true , VariableSpecification_variableDescription), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<ISO_9506_MMS_1A::ScatteredAccessDescription > (true , VariableSpecification_scatteredAccessDescription), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , VariableSpecification_invalidated), 4, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence variableDescription

        template<> void VariableSpecification::VariableDescription_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(address_);
            ITU_T_BIND_CHOICE(typeSpecification_);
        }

        template<> void VariableSpecification::VariableDescription_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(address_);
            ITU_T_BIND_CHOICE(typeSpecification_);
        }

    // sequence Read-Request

        template<> void Read_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(specificationWithResult_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(variableAccessSpecification_, 1, CONTEXT_CLASS);
        }

        template<> void Read_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(specificationWithResult_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(variableAccessSpecification_, 1, CONTEXT_CLASS);
        }

    // sequence Read-Response

        template<> void Read_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(variableAccessSpecification_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfAccessResult_, 1, CONTEXT_CLASS);
        }

        template<> void Read_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(variableAccessSpecification_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfAccessResult_, 1, CONTEXT_CLASS);
        }

    // sequence Write-Request

        template<> void Write_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(variableAccessSpecification_);
            ITU_T_BIND_IMPLICIT(listOfData_, 0, CONTEXT_CLASS);
        }

        template<> void Write_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(variableAccessSpecification_);
            ITU_T_BIND_IMPLICIT(listOfData_, 0, CONTEXT_CLASS);
        }

    // choice 

        template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Write_Response_sequence_of_failure:  {ITU_T_BIND_IMPLICIT(value<DataAccessError > (false , Write_Response_sequence_of_failure), 0, CONTEXT_CLASS); break; }
                case Write_Response_sequence_of_success:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , Write_Response_sequence_of_success), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<DataAccessError > (true , Write_Response_sequence_of_failure), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , Write_Response_sequence_of_success), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence InformationReport

        template<> void InformationReport::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(variableAccessSpecification_);
            ITU_T_BIND_IMPLICIT(listOfAccessResult_, 0, CONTEXT_CLASS);
        }

        template<> void InformationReport::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(variableAccessSpecification_);
            ITU_T_BIND_IMPLICIT(listOfAccessResult_, 0, CONTEXT_CLASS);
        }

    // choice GetVariableAccessAttributes-Request

        template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case GetVariableAccessAttributes_Request_name:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , GetVariableAccessAttributes_Request_name), 0, CONTEXT_CLASS); break; }
                case GetVariableAccessAttributes_Request_address:  {ITU_T_BIND_CHOICE_TAG(value<MMS_Object_Module_1::Address > (false , GetVariableAccessAttributes_Request_address), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , GetVariableAccessAttributes_Request_name), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<MMS_Object_Module_1::Address > (true , GetVariableAccessAttributes_Request_address), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetVariableAccessAttributes-Response

        template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(address_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(typeDescription_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(meaning_, 4, CONTEXT_CLASS);
        }

        template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(address_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(typeDescription_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(meaning_, 4, CONTEXT_CLASS);
        }

    // sequence DefineNamedVariable-Request

        template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(variableName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(address_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(typeSpecification_, 2, CONTEXT_CLASS);
        }

        template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(variableName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(address_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(typeSpecification_, 2, CONTEXT_CLASS);
        }

    // sequence DeleteVariableAccess-Request

        template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfDelete_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainName_, 2, CONTEXT_CLASS);
        }

        template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfDelete_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainName_, 2, CONTEXT_CLASS);
        }

    // sequence DeleteVariableAccess-Response

        template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberDeleted_, 1, CONTEXT_CLASS);
        }

        template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberDeleted_, 1, CONTEXT_CLASS);
        }

    // sequence DefineNamedVariableList-Request

        template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(variableListName_);
            ITU_T_BIND_IMPLICIT(listOfVariable_, 0, CONTEXT_CLASS);
        }

        template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(variableListName_);
            ITU_T_BIND_IMPLICIT(listOfVariable_, 0, CONTEXT_CLASS);
        }

    // sequence 

        template<> void DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(variableSpecification_);
            ITU_T_BIND_IMPLICIT(alternateAccess_, 5, CONTEXT_CLASS);
        }

        template<> void DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(variableSpecification_);
            ITU_T_BIND_IMPLICIT(alternateAccess_, 5, CONTEXT_CLASS);
        }

    // sequence GetNamedVariableListAttributes-Response

        template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariable_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 2, CONTEXT_CLASS);
        }

        template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariable_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 2, CONTEXT_CLASS);
        }

    // sequence 

        template<> void GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(variableSpecification_);
            ITU_T_BIND_IMPLICIT(alternateAccess_, 5, CONTEXT_CLASS);
        }

        template<> void GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(variableSpecification_);
            ITU_T_BIND_IMPLICIT(alternateAccess_, 5, CONTEXT_CLASS);
        }

    // sequence DeleteNamedVariableList-Request

        template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfDelete_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariableListName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainName_, 2, CONTEXT_CLASS);
        }

        template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfDelete_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariableListName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainName_, 2, CONTEXT_CLASS);
        }

    // sequence DeleteNamedVariableList-Response

        template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberDeleted_, 1, CONTEXT_CLASS);
        }

        template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberDeleted_, 1, CONTEXT_CLASS);
        }

    // sequence DefineNamedType-Request

        template<> void DefineNamedType_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(typeName_);
            ITU_T_BIND_CHOICE(typeSpecification_);
        }

        template<> void DefineNamedType_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(typeName_);
            ITU_T_BIND_CHOICE(typeSpecification_);
        }

    // sequence GetNamedTypeAttributes-Response

        template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(typeSpecification_);
            ITU_T_BIND_IMPLICIT(accessControlList_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(meaning_, 4, CONTEXT_CLASS);
        }

        template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(typeSpecification_);
            ITU_T_BIND_IMPLICIT(accessControlList_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(meaning_, 4, CONTEXT_CLASS);
        }

    // sequence DeleteNamedType-Request

        template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfDelete_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfTypeName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainName_, 2, CONTEXT_CLASS);
        }

        template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfDelete_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfTypeName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(domainName_, 2, CONTEXT_CLASS);
        }

    // sequence DeleteNamedType-Response

        template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberDeleted_, 1, CONTEXT_CLASS);
        }

        template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(numberMatched_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberDeleted_, 1, CONTEXT_CLASS);
        }

    // sequence ExchangeData-Request

        template<> void ExchangeData_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(dataExchangeName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfRequestData_, 1, CONTEXT_CLASS);
        }

        template<> void ExchangeData_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(dataExchangeName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfRequestData_, 1, CONTEXT_CLASS);
        }

    // sequence ExchangeData-Response

        template<> void ExchangeData_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfResponseData_, 0, CONTEXT_CLASS);
        }

        template<> void ExchangeData_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfResponseData_, 0, CONTEXT_CLASS);
        }

    // sequence GetDataExchangeAttributes-Response

        template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(inUse_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfRequestTypeDescriptions_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfResponseTypeDescriptions_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocation_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 4, CONTEXT_CLASS);
        }

        template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(inUse_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfRequestTypeDescriptions_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfResponseTypeDescriptions_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(programInvocation_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 4, CONTEXT_CLASS);
        }

    // sequence TakeControl-Request

        template<> void TakeControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acceptableDelay_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(controlTimeOut_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(abortOnTimeOut_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(relinquishIfConnectionLost_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(applicationToPreempt_, 7, CONTEXT_CLASS);
        }

        template<> void TakeControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acceptableDelay_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(controlTimeOut_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(abortOnTimeOut_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(relinquishIfConnectionLost_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(applicationToPreempt_, 7, CONTEXT_CLASS);
        }

    // choice TakeControl-Response

        template<> void TakeControl_Response::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case TakeControl_Response_noResult:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , TakeControl_Response_noResult), 0, CONTEXT_CLASS); break; }
                case TakeControl_Response_namedToken:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , TakeControl_Response_namedToken), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void TakeControl_Response::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , TakeControl_Response_noResult), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , TakeControl_Response_namedToken), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence RelinquishControl-Request

        template<> void RelinquishControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 1, CONTEXT_CLASS);
        }

        template<> void RelinquishControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 1, CONTEXT_CLASS);
        }

    // sequence DefineSemaphore-Request

        template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfTokens_, 1, CONTEXT_CLASS);
        }

        template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfTokens_, 1, CONTEXT_CLASS);
        }

    // sequence ReportSemaphoreStatus-Response

        template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(classV_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfTokens_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfOwnedTokens_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfHungTokens_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 5, CONTEXT_CLASS);
        }

        template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(classV_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfTokens_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfOwnedTokens_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfHungTokens_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 5, CONTEXT_CLASS);
        }

    // sequence ReportPoolSemaphoreStatus-Request

        template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(nameToStartAfter_, 1, CONTEXT_CLASS);
        }

        template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(nameToStartAfter_, 1, CONTEXT_CLASS);
        }

    // sequence ReportPoolSemaphoreStatus-Response

        template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfNamedTokens_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfNamedTokens_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // choice 

        template<> void ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ListOfNamedTokens_type_sequence_of_freeNamedToken:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ListOfNamedTokens_type_sequence_of_freeNamedToken), 0, CONTEXT_CLASS); break; }
                case ListOfNamedTokens_type_sequence_of_ownedNamedToken:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ListOfNamedTokens_type_sequence_of_ownedNamedToken), 1, CONTEXT_CLASS); break; }
                case ListOfNamedTokens_type_sequence_of_hungNamedToken:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , ListOfNamedTokens_type_sequence_of_hungNamedToken), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ListOfNamedTokens_type_sequence_of_freeNamedToken), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ListOfNamedTokens_type_sequence_of_ownedNamedToken), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , ListOfNamedTokens_type_sequence_of_hungNamedToken), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence ReportSemaphoreEntryStatus-Request

        template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(state_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryIDToStartAfter_, 2, CONTEXT_CLASS);
        }

        template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(state_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryIDToStartAfter_, 2, CONTEXT_CLASS);
        }

    // sequence ReportSemaphoreEntryStatus-Response

        template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfSemaphoreEntry_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfSemaphoreEntry_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence SemaphoreEntry

        template<> void SemaphoreEntry::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(entryID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryClass_, 1, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(applicationReference_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(remainingTimeOut_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(abortOnTimeOut_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(relinquishIfConnectionLost_, 7, CONTEXT_CLASS);
        }

        template<> void SemaphoreEntry::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(entryID_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryClass_, 1, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(applicationReference_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(remainingTimeOut_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(abortOnTimeOut_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(relinquishIfConnectionLost_, 7, CONTEXT_CLASS);
        }

    // sequence AttachToSemaphore

        template<> void AttachToSemaphore::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acceptableDelay_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(controlTimeOut_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(abortOnTimeOut_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(relinquishIfConnectionLost_, 6, CONTEXT_CLASS);
        }

        template<> void AttachToSemaphore::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(semaphoreName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(namedToken_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acceptableDelay_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(controlTimeOut_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(abortOnTimeOut_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(relinquishIfConnectionLost_, 6, CONTEXT_CLASS);
        }

    // sequence Input-Request

        template<> void Input_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(operatorStationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(echo_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfPromptData_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(inputTimeOut_, 3, CONTEXT_CLASS);
        }

        template<> void Input_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(operatorStationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(echo_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfPromptData_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(inputTimeOut_, 3, CONTEXT_CLASS);
        }

    // sequence Output-Request

        template<> void Output_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(operatorStationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfOutputData_, 1, CONTEXT_CLASS);
        }

        template<> void Output_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(operatorStationName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfOutputData_, 1, CONTEXT_CLASS);
        }

    // sequence TriggerEvent-Request

        template<> void TriggerEvent_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 1, CONTEXT_CLASS);
        }

        template<> void TriggerEvent_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 1, CONTEXT_CLASS);
        }

    // sequence EventNotification

        template<> void EventNotification::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(transitionTime_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(notificationLost_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(actionResult_, 8, CONTEXT_CLASS);
        }

        template<> void EventNotification::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(transitionTime_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(notificationLost_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(actionResult_, 8, CONTEXT_CLASS);
        }

    // sequence actionResult

        template<> void EventNotification::ActionResult_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(eventActionName_);
            ITU_T_BIND_CHOICE(successOrFailure_);
        }

        template<> void EventNotification::ActionResult_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(eventActionName_);
            ITU_T_BIND_CHOICE(successOrFailure_);
        }

    // choice successOrFailure

        template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case SuccessOrFailure_type_success:  {ITU_T_BIND_IMPLICIT(value<Success_type > (false , SuccessOrFailure_type_success), 0, CONTEXT_CLASS); break; }
                case SuccessOrFailure_type_failure:  {ITU_T_BIND_IMPLICIT(value<Failure_type > (false , SuccessOrFailure_type_failure), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Success_type > (true , SuccessOrFailure_type_success), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Failure_type > (true , SuccessOrFailure_type_failure), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence success

        template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(confirmedServiceResponse_);
            ITU_T_BIND_CHOICE_TAG(cs_Response_Detail_, 79, CONTEXT_CLASS);
        }

        template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(confirmedServiceResponse_);
            ITU_T_BIND_CHOICE_TAG(cs_Response_Detail_, 79, CONTEXT_CLASS);
        }

    // sequence failure

        template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(modifierPosition_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(serviceError_, 1, CONTEXT_CLASS);
        }

        template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(modifierPosition_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(serviceError_, 1, CONTEXT_CLASS);
        }

    // choice CS-EventNotification

        template<> void CS_EventNotification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_EventNotification_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , CS_EventNotification_string), 0, CONTEXT_CLASS); break; }
                case CS_EventNotification_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , CS_EventNotification_index), 1, CONTEXT_CLASS); break; }
                case CS_EventNotification_noEnhancement:  {ITU_T_BIND_TAG(value<null_type > (false , CS_EventNotification_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void CS_EventNotification::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , CS_EventNotification_noEnhancement))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , CS_EventNotification_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , CS_EventNotification_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence AcknowledgeEventNotification-Request

        template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acknowledgedState_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfAcknowledgedTransition_, 3, CONTEXT_CLASS);
        }

        template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acknowledgedState_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfAcknowledgedTransition_, 3, CONTEXT_CLASS);
        }

    // sequence GetAlarmSummary-Request

        template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(enrollmentsOnly_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(activeAlarmsOnly_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acknowledgementFilter_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severityFilter_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 5, CONTEXT_CLASS);
        }

        template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(enrollmentsOnly_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(activeAlarmsOnly_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acknowledgementFilter_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severityFilter_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 5, CONTEXT_CLASS);
        }

    // sequence severityFilter

        template<> void GetAlarmSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mostSevere_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(leastSevere_, 1, CONTEXT_CLASS);
        }

        template<> void GetAlarmSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mostSevere_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(leastSevere_, 1, CONTEXT_CLASS);
        }

    // sequence GetAlarmSummary-Response

        template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfAlarmSummary_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfAlarmSummary_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence AlarmSummary

        template<> void AlarmSummary::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(unacknowledgedState_, 3, CONTEXT_CLASS);
            ITU_T_BIND_PREFIXED(displayEnhancement_, AlarmSummary__DisplayEnhancement);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 5, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 6, CONTEXT_CLASS);
        }

        template<> void AlarmSummary::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(unacknowledgedState_, 3, CONTEXT_CLASS);
            ITU_T_BIND_PREFIXED(displayEnhancement_, AlarmSummary__DisplayEnhancement);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 5, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 6, CONTEXT_CLASS);
        }

    // choice EN-Additional-Detail

        template<> void EN_Additional_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case EN_Additional_Detail_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , EN_Additional_Detail_string), 0, CONTEXT_CLASS); break; }
                case EN_Additional_Detail_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , EN_Additional_Detail_index), 1, CONTEXT_CLASS); break; }
                case EN_Additional_Detail_noEnhancement:  {ITU_T_BIND_TAG(value<null_type > (false , EN_Additional_Detail_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void EN_Additional_Detail::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , EN_Additional_Detail_noEnhancement))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , EN_Additional_Detail_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , EN_Additional_Detail_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetAlarmEnrollmentSummary-Request

        template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(enrollmentsOnly_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(activeAlarmsOnly_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acknowledgementFilter_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severityFilter_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 5, CONTEXT_CLASS);
        }

        template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(enrollmentsOnly_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(activeAlarmsOnly_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acknowledgementFilter_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severityFilter_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 5, CONTEXT_CLASS);
        }

    // sequence severityFilter

        template<> void GetAlarmEnrollmentSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mostSevere_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(leastSevere_, 1, CONTEXT_CLASS);
        }

        template<> void GetAlarmEnrollmentSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mostSevere_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(leastSevere_, 1, CONTEXT_CLASS);
        }

    // sequence GetAlarmEnrollmentSummary-Response

        template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfAlarmEnrollmentSummary_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfAlarmEnrollmentSummary_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence AlarmEnrollmentSummary

        template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 4, CONTEXT_CLASS);
            ITU_T_BIND_PREFIXED(displayEnhancement_, AlarmEnrollmentSummary__DisplayEnhancement);
            ITU_T_BIND_IMPLICIT(notificationLost_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enrollmentState_, 8, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 9, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeActiveAcknowledged_, 10, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 11, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeIdleAcknowledged_, 12, CONTEXT_CLASS);
        }

        template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 4, CONTEXT_CLASS);
            ITU_T_BIND_PREFIXED(displayEnhancement_, AlarmEnrollmentSummary__DisplayEnhancement);
            ITU_T_BIND_IMPLICIT(notificationLost_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enrollmentState_, 8, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 9, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeActiveAcknowledged_, 10, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 11, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeIdleAcknowledged_, 12, CONTEXT_CLASS);
        }

    // sequence AttachToEventCondition

        template<> void AttachToEventCondition::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(causingTransitions_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acceptableDelay_, 3, CONTEXT_CLASS);
        }

        template<> void AttachToEventCondition::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(causingTransitions_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(acceptableDelay_, 3, CONTEXT_CLASS);
        }

    // sequence DefineEventCondition-Request

        template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(classV_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(monitoredVariable_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(evaluationInterval_, 7, CONTEXT_CLASS);
        }

        template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(classV_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(monitoredVariable_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(evaluationInterval_, 7, CONTEXT_CLASS);
        }

    // choice CS-DefineEventCondition-Request

        template<> void CS_DefineEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_DefineEventCondition_Request_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , CS_DefineEventCondition_Request_string), 0, CONTEXT_CLASS); break; }
                case CS_DefineEventCondition_Request_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , CS_DefineEventCondition_Request_index), 1, CONTEXT_CLASS); break; }
                case CS_DefineEventCondition_Request_noEnhancement:  {ITU_T_BIND_TAG(value<null_type > (false , CS_DefineEventCondition_Request_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void CS_DefineEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , CS_DefineEventCondition_Request_noEnhancement))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , CS_DefineEventCondition_Request_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , CS_DefineEventCondition_Request_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice DeleteEventCondition-Request

        template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteEventCondition_Request_specific:  {ITU_T_BIND_IMPLICIT(value<Specific_type > (false , DeleteEventCondition_Request_specific), 0, CONTEXT_CLASS); break; }
                case DeleteEventCondition_Request_aa_specific:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , DeleteEventCondition_Request_aa_specific), 1, CONTEXT_CLASS); break; }
                case DeleteEventCondition_Request_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , DeleteEventCondition_Request_domain), 2, CONTEXT_CLASS); break; }
                case DeleteEventCondition_Request_vmd:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , DeleteEventCondition_Request_vmd), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Specific_type > (true , DeleteEventCondition_Request_specific), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , DeleteEventCondition_Request_aa_specific), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , DeleteEventCondition_Request_domain), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , DeleteEventCondition_Request_vmd), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetEventConditionAttributes-Response

        template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(classV_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(monitoredVariable_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(evaluationInterval_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 8, CONTEXT_CLASS);
        }

        template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(classV_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(severity_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(monitoredVariable_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(evaluationInterval_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 8, CONTEXT_CLASS);
        }

    // choice monitoredVariable

        template<> void GetEventConditionAttributes_Response::MonitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case MonitoredVariable_type_variableReference:  {ITU_T_BIND_CHOICE_TAG(value<VariableSpecification > (false , MonitoredVariable_type_variableReference), 0, CONTEXT_CLASS); break; }
                case MonitoredVariable_type_undefined:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , MonitoredVariable_type_undefined), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void GetEventConditionAttributes_Response::MonitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<VariableSpecification > (true , MonitoredVariable_type_variableReference), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , MonitoredVariable_type_undefined), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence CS-GetEventConditionAttributes-Response

        template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(groupPriorityOverride_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfReferencingECL_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(displayEnhancement_, 2, CONTEXT_CLASS);
        }

        template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(groupPriorityOverride_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfReferencingECL_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(displayEnhancement_, 2, CONTEXT_CLASS);
        }

    // choice groupPriorityOverride

        template<> void CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case GroupPriorityOverride_type_priority:  {ITU_T_BIND_IMPLICIT(value<MMS_Object_Module_1::Priority > (false , GroupPriorityOverride_type_priority), 0, CONTEXT_CLASS); break; }
                case GroupPriorityOverride_type_undefined:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , GroupPriorityOverride_type_undefined), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<MMS_Object_Module_1::Priority > (true , GroupPriorityOverride_type_priority), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , GroupPriorityOverride_type_undefined), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice displayEnhancement

        template<> void CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DisplayEnhancement_type_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , DisplayEnhancement_type_string), 0, CONTEXT_CLASS); break; }
                case DisplayEnhancement_type_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , DisplayEnhancement_type_index), 1, CONTEXT_CLASS); break; }
                case DisplayEnhancement_type_noEnhancement:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , DisplayEnhancement_type_noEnhancement), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , DisplayEnhancement_type_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , DisplayEnhancement_type_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , DisplayEnhancement_type_noEnhancement), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence ReportEventConditionStatus-Response

        template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(currentState_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfEventEnrollments_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 4, CONTEXT_CLASS);
        }

        template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(currentState_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfEventEnrollments_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 4, CONTEXT_CLASS);
        }

    // sequence AlterEventConditionMonitoring-Request

        template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(evaluationInterval_, 4, CONTEXT_CLASS);
        }

        template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(priority_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(evaluationInterval_, 4, CONTEXT_CLASS);
        }

    // sequence CS-AlterEventConditionMonitoring-Request

        template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(changeDisplay_);
        }

        template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(changeDisplay_);
        }

    // choice changeDisplay

        template<> void CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ChangeDisplay_type_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , ChangeDisplay_type_string), 0, CONTEXT_CLASS); break; }
                case ChangeDisplay_type_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , ChangeDisplay_type_index), 1, CONTEXT_CLASS); break; }
                case ChangeDisplay_type_noEnhancement:  {ITU_T_BIND_EXPLICIT(value<null_type > (false , ChangeDisplay_type_noEnhancement), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , ChangeDisplay_type_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , ChangeDisplay_type_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_EXPLICIT(value<null_type > (true , ChangeDisplay_type_noEnhancement), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence DefineEventAction-Request

        template<> void DefineEventAction_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfModifier_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(confirmedServiceRequest_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(cs_extension_, 79, CONTEXT_CLASS);
        }

        template<> void DefineEventAction_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfModifier_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(confirmedServiceRequest_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(cs_extension_, 79, CONTEXT_CLASS);
        }

    // choice DeleteEventAction-Request

        template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteEventAction_Request_specific:  {ITU_T_BIND_IMPLICIT(value<Specific_type > (false , DeleteEventAction_Request_specific), 0, CONTEXT_CLASS); break; }
                case DeleteEventAction_Request_aa_specific:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , DeleteEventAction_Request_aa_specific), 1, CONTEXT_CLASS); break; }
                case DeleteEventAction_Request_domain:  {ITU_T_BIND_IMPLICIT(value<Identifier > (false , DeleteEventAction_Request_domain), 3, CONTEXT_CLASS); break; }
                case DeleteEventAction_Request_vmd:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , DeleteEventAction_Request_vmd), 4, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Specific_type > (true , DeleteEventAction_Request_specific), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , DeleteEventAction_Request_aa_specific), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_IMPLICIT(value<Identifier > (true , DeleteEventAction_Request_domain), 3, CONTEXT_CLASS)) return; else free(); break;}
                        case 4:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , DeleteEventAction_Request_vmd), 4, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetEventActionAttributes-Response

        template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfModifier_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(confirmedServiceRequest_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(cs_extension_, 79, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 3, CONTEXT_CLASS);
        }

        template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfModifier_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(confirmedServiceRequest_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(cs_extension_, 79, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 3, CONTEXT_CLASS);
        }

    // sequence DefineEventEnrollment-Request

        template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(eventConditionTransitions_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 4, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 5, CONTEXT_CLASS);
        }

        template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(eventConditionTransitions_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 4, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 5, CONTEXT_CLASS);
        }

    // choice CS-DefineEventEnrollment-Request

        template<> void CS_DefineEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_DefineEventEnrollment_Request_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , CS_DefineEventEnrollment_Request_string), 0, CONTEXT_CLASS); break; }
                case CS_DefineEventEnrollment_Request_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , CS_DefineEventEnrollment_Request_index), 1, CONTEXT_CLASS); break; }
                case CS_DefineEventEnrollment_Request_noEnhancement:  {ITU_T_BIND_TAG(value<null_type > (false , CS_DefineEventEnrollment_Request_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void CS_DefineEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , CS_DefineEventEnrollment_Request_noEnhancement))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , CS_DefineEventEnrollment_Request_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , CS_DefineEventEnrollment_Request_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice DeleteEventEnrollment-Request

        template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteEventEnrollment_Request_specific:  {ITU_T_BIND_IMPLICIT(value<Specific_type > (false , DeleteEventEnrollment_Request_specific), 0, CONTEXT_CLASS); break; }
                case DeleteEventEnrollment_Request_ec:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , DeleteEventEnrollment_Request_ec), 1, CONTEXT_CLASS); break; }
                case DeleteEventEnrollment_Request_ea:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , DeleteEventEnrollment_Request_ea), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<Specific_type > (true , DeleteEventEnrollment_Request_specific), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , DeleteEventEnrollment_Request_ec), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , DeleteEventEnrollment_Request_ea), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetEventEnrollmentAttributes-Request

        template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfRequest_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(eventEnrollmentNames_, 1, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 5, CONTEXT_CLASS);
        }

        template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(scopeOfRequest_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(eventEnrollmentNames_, 1, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 2, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(continueAfter_, 5, CONTEXT_CLASS);
        }

    // sequence GetEventEnrollmentAttributes-Response

        template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfEEAttributes_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfEEAttributes_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence EEAttributes

        template<> void EEAttributes::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 2, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enrollmentClass_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(invokeID_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(remainingAcceptableDelay_, 8, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(displayEnhancement_, 9, CONTEXT_CLASS);
        }

        template<> void EEAttributes::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(eventActionName_, 2, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(clientApplication_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enrollmentClass_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(invokeID_, 7, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(remainingAcceptableDelay_, 8, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(displayEnhancement_, 9, CONTEXT_CLASS);
        }

    // choice eventConditionName

        template<> void EEAttributes::EventConditionName_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case EventConditionName_type_eventCondition:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , EventConditionName_type_eventCondition), 0, CONTEXT_CLASS); break; }
                case EventConditionName_type_undefined:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , EventConditionName_type_undefined), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void EEAttributes::EventConditionName_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , EventConditionName_type_eventCondition), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , EventConditionName_type_undefined), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice eventActionName

        template<> void EEAttributes::EventActionName_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case EventActionName_type_eventAction:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , EventActionName_type_eventAction), 0, CONTEXT_CLASS); break; }
                case EventActionName_type_undefined:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , EventActionName_type_undefined), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void EEAttributes::EventActionName_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , EventActionName_type_eventAction), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , EventActionName_type_undefined), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice displayEnhancement

        template<> void EEAttributes::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DisplayEnhancement_type_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , DisplayEnhancement_type_string), 0, CONTEXT_CLASS); break; }
                case DisplayEnhancement_type_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , DisplayEnhancement_type_index), 1, CONTEXT_CLASS); break; }
                case DisplayEnhancement_type_noEnhancement:  {ITU_T_BIND_TAG(value<null_type > (false , DisplayEnhancement_type_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void EEAttributes::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                        case 5:  { if (ITU_T_BIND_TAG(value<null_type > (true , DisplayEnhancement_type_noEnhancement))) return; else free(); break;}
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , DisplayEnhancement_type_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , DisplayEnhancement_type_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence ReportEventEnrollmentStatus-Response

        template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(eventConditionTransitions_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(notificationLost_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 4, CONTEXT_CLASS);
        }

        template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(eventConditionTransitions_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(notificationLost_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 4, CONTEXT_CLASS);
        }

    // sequence AlterEventEnrollment-Request

        template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(eventConditionTransitions_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 2, CONTEXT_CLASS);
        }

        template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventEnrollmentName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(eventConditionTransitions_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(alarmAcknowledgmentRule_, 2, CONTEXT_CLASS);
        }

    // sequence AlterEventEnrollment-Response

        template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(currentState_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(transitionTime_, 1, CONTEXT_CLASS);
        }

        template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(currentState_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(transitionTime_, 1, CONTEXT_CLASS);
        }

    // choice currentState

        template<> void AlterEventEnrollment_Response::CurrentState_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CurrentState_type_state:  {ITU_T_BIND_IMPLICIT(value<EE_State > (false , CurrentState_type_state), 0, CONTEXT_CLASS); break; }
                case CurrentState_type_undefined:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , CurrentState_type_undefined), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AlterEventEnrollment_Response::CurrentState_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<EE_State > (true , CurrentState_type_state), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , CurrentState_type_undefined), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence CS-AlterEventEnrollment-Request

        template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE(changeDisplay_);
        }

        template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE(changeDisplay_);
        }

    // choice changeDisplay

        template<> void CS_AlterEventEnrollment_Request::ChangeDisplay_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ChangeDisplay_type_string:  {ITU_T_BIND_IMPLICIT(value<visible_string > (false , ChangeDisplay_type_string), 0, CONTEXT_CLASS); break; }
                case ChangeDisplay_type_index:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , ChangeDisplay_type_index), 1, CONTEXT_CLASS); break; }
                case ChangeDisplay_type_noEnhancement:  {ITU_T_BIND_EXPLICIT(value<null_type > (false , ChangeDisplay_type_noEnhancement), 2, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void CS_AlterEventEnrollment_Request::ChangeDisplay_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<visible_string > (true , ChangeDisplay_type_string), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , ChangeDisplay_type_index), 1, CONTEXT_CLASS)) return; else free(); break;}
                        case 2:  { if (ITU_T_BIND_EXPLICIT(value<null_type > (true , ChangeDisplay_type_noEnhancement), 2, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence DefineEventConditionList-Request

        template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

        template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

    // sequence AddEventConditionListReference-Request

        template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

        template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

    // sequence RemoveEventConditionListReference-Request

        template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

        template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

    // choice RemoveEventConditionListReference-Error

        template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case RemoveEventConditionListReference_Error_eventCondition:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , RemoveEventConditionListReference_Error_eventCondition), 0, CONTEXT_CLASS); break; }
                case RemoveEventConditionListReference_Error_eventConditionList:  {ITU_T_BIND_CHOICE_TAG(value<ObjectName > (false , RemoveEventConditionListReference_Error_eventConditionList), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , RemoveEventConditionListReference_Error_eventCondition), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_CHOICE_TAG(value<ObjectName > (true , RemoveEventConditionListReference_Error_eventConditionList), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence GetEventConditionListAttributes-Response

        template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

        template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfEventConditionName_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfEventConditionListName_, 2, CONTEXT_CLASS);
        }

    // sequence ReportEventConditionListStatus-Request

        template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(continueAfter_, 1, CONTEXT_CLASS);
        }

        template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(continueAfter_, 1, CONTEXT_CLASS);
        }

    // sequence ReportEventConditionListStatus-Response

        template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfEventConditionStatus_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 2, CONTEXT_CLASS);
        }

        template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfEventConditionStatus_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 2, CONTEXT_CLASS);
        }

    // sequence EventConditionStatus

        template<> void EventConditionStatus::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfEventEnrollments_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 5, CONTEXT_CLASS);
        }

        template<> void EventConditionStatus::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(numberOfEventEnrollments_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 3, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToActive_, 4, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(timeOfLastTransitionToIdle_, 5, CONTEXT_CLASS);
        }

    // sequence AlterEventConditionListMonitoring-Request

        template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(priorityChange_, 2, CONTEXT_CLASS);
        }

        template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionListName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(enabled_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(priorityChange_, 2, CONTEXT_CLASS);
        }

    // choice priorityChange

        template<> void AlterEventConditionListMonitoring_Request::PriorityChange_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case PriorityChange_type_priorityValue:  {ITU_T_BIND_IMPLICIT(value<integer_type > (false , PriorityChange_type_priorityValue), 0, CONTEXT_CLASS); break; }
                case PriorityChange_type_priorityReset:  {ITU_T_BIND_IMPLICIT(value<null_type > (false , PriorityChange_type_priorityReset), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void AlterEventConditionListMonitoring_Request::PriorityChange_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<integer_type > (true , PriorityChange_type_priorityValue), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<null_type > (true , PriorityChange_type_priorityReset), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence ReadJournal-Request

        template<> void ReadJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(rangeStartSpecification_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(rangeStopSpecification_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariables_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryToStartAfter_, 5, CONTEXT_CLASS);
        }

        template<> void ReadJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(rangeStartSpecification_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(rangeStopSpecification_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariables_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryToStartAfter_, 5, CONTEXT_CLASS);
        }

    // choice rangeStartSpecification

        template<> void ReadJournal_Request::RangeStartSpecification_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case RangeStartSpecification_type_startingTime:  {ITU_T_BIND_IMPLICIT(value<TimeOfDay > (false , RangeStartSpecification_type_startingTime), 0, CONTEXT_CLASS); break; }
                case RangeStartSpecification_type_startingEntry:  {ITU_T_BIND_IMPLICIT(value<octet_string > (false , RangeStartSpecification_type_startingEntry), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ReadJournal_Request::RangeStartSpecification_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<TimeOfDay > (true , RangeStartSpecification_type_startingTime), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<octet_string > (true , RangeStartSpecification_type_startingEntry), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // choice rangeStopSpecification

        template<> void ReadJournal_Request::RangeStopSpecification_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case RangeStopSpecification_type_endingTime:  {ITU_T_BIND_IMPLICIT(value<TimeOfDay > (false , RangeStopSpecification_type_endingTime), 0, CONTEXT_CLASS); break; }
                case RangeStopSpecification_type_numberOfEntries:  {ITU_T_BIND_IMPLICIT(value<Integer32 > (false , RangeStopSpecification_type_numberOfEntries), 1, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void ReadJournal_Request::RangeStopSpecification_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 0:  { if (ITU_T_BIND_IMPLICIT(value<TimeOfDay > (true , RangeStopSpecification_type_endingTime), 0, CONTEXT_CLASS)) return; else free(); break;}
                        case 1:  { if (ITU_T_BIND_IMPLICIT(value<Integer32 > (true , RangeStopSpecification_type_numberOfEntries), 1, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence entryToStartAfter

        template<> void ReadJournal_Request::EntryToStartAfter_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(timeSpecification_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entrySpecification_, 1, CONTEXT_CLASS);
        }

        template<> void ReadJournal_Request::EntryToStartAfter_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(timeSpecification_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entrySpecification_, 1, CONTEXT_CLASS);
        }

    // sequence ReadJournal-Response

        template<> void ReadJournal_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfJournalEntry_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

        template<> void ReadJournal_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(listOfJournalEntry_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
        }

    // sequence JournalEntry

        template<> void JournalEntry::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(entryIdentifier_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(originatingApplication_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryContent_, 2, CONTEXT_CLASS);
        }

        template<> void JournalEntry::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(entryIdentifier_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(originatingApplication_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(entryContent_, 2, CONTEXT_CLASS);
        }

    // sequence WriteJournal-Request

        template<> void WriteJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfJournalEntry_, 1, CONTEXT_CLASS);
        }

        template<> void WriteJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfJournalEntry_, 1, CONTEXT_CLASS);
        }

    // sequence InitializeJournal-Request

        template<> void InitializeJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(limitSpecification_, 1, CONTEXT_CLASS);
        }

        template<> void InitializeJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(limitSpecification_, 1, CONTEXT_CLASS);
        }

    // sequence limitSpecification

        template<> void InitializeJournal_Request::LimitSpecification_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(limitingTime_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(limitingEntry_, 1, CONTEXT_CLASS);
        }

        template<> void InitializeJournal_Request::LimitSpecification_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(limitingTime_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(limitingEntry_, 1, CONTEXT_CLASS);
        }

    // sequence ReportJournalStatus-Response

        template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(currentEntries_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 2, CONTEXT_CLASS);
        }

        template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(currentEntries_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(mmsDeletable_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(accessControlList_, 2, CONTEXT_CLASS);
        }

    // sequence CreateJournal-Request

        template<> void CreateJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
        }

        template<> void CreateJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
        }

    // sequence DeleteJournal-Request

        template<> void DeleteJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
        }

        template<> void DeleteJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(journalName_, 0, CONTEXT_CLASS);
        }

    // sequence EntryContent

        template<> void EntryContent::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(occurrenceTime_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(entryForm_);
        }

        template<> void EntryContent::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(occurrenceTime_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE(entryForm_);
        }

    // choice entryForm

        template<> void EntryContent::EntryForm_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case EntryForm_type_data:  {ITU_T_BIND_IMPLICIT(value<Data_type > (false , EntryForm_type_data), 2, CONTEXT_CLASS); break; }
                case EntryForm_type_annotation:  {ITU_T_BIND_EXPLICIT(value<MMSString > (false , EntryForm_type_annotation), 3, CONTEXT_CLASS); break; }
                default:{}
            }
        }

        template<> void EntryContent::EntryForm_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x80: {
                    switch(__tag_id__){
                        case 2:  { if (ITU_T_BIND_IMPLICIT(value<Data_type > (true , EntryForm_type_data), 2, CONTEXT_CLASS)) return; else free(); break;}
                        case 3:  { if (ITU_T_BIND_EXPLICIT(value<MMSString > (true , EntryForm_type_annotation), 3, CONTEXT_CLASS)) return; else free(); break;}
                    default:{}
                    }
                }
                default: {
                }
            }
        }

    // sequence data

        template<> void EntryContent::EntryForm_type::Data_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_IMPLICIT(event_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariables_, 1, CONTEXT_CLASS);
        }

        template<> void EntryContent::EntryForm_type::Data_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_IMPLICIT(event_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(listOfVariables_, 1, CONTEXT_CLASS);
        }

    // sequence event

        template<> void EntryContent::EntryForm_type::Data_type::Event_type::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 1, CONTEXT_CLASS);
        }

        template<> void EntryContent::EntryForm_type::Data_type::Event_type::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_CHOICE_TAG(eventConditionName_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(currentState_, 1, CONTEXT_CLASS);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

