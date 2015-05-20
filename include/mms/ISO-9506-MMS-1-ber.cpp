#include "ISO-9506-MMS-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1 {

    // choice MMSpdu

    template<> void MMSpdu::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case MMSpdu_confirmed_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Confirmed_RequestPDU > (false, MMSpdu_confirmed_RequestPDU), 0);
                break;
            }
            case MMSpdu_confirmed_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Confirmed_ResponsePDU > (false, MMSpdu_confirmed_ResponsePDU), 1);
                break;
            }
            case MMSpdu_confirmed_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Confirmed_ErrorPDU > (false, MMSpdu_confirmed_ErrorPDU), 2);
                break;
            }
            case MMSpdu_unconfirmed_PDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Unconfirmed_PDU > (false, MMSpdu_unconfirmed_PDU), 3);
                break;
            }
            case MMSpdu_rejectPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<RejectPDU > (false, MMSpdu_rejectPDU), 4);
                break;
            }
            case MMSpdu_cancel_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Cancel_RequestPDU > (false, MMSpdu_cancel_RequestPDU), 5);
                break;
            }
            case MMSpdu_cancel_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Cancel_ResponsePDU > (false, MMSpdu_cancel_ResponsePDU), 6);
                break;
            }
            case MMSpdu_cancel_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Cancel_ErrorPDU > (false, MMSpdu_cancel_ErrorPDU), 7);
                break;
            }
            case MMSpdu_initiate_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Initiate_RequestPDU > (false, MMSpdu_initiate_RequestPDU), 8);
                break;
            }
            case MMSpdu_initiate_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Initiate_ResponsePDU > (false, MMSpdu_initiate_ResponsePDU), 9);
                break;
            }
            case MMSpdu_initiate_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Initiate_ErrorPDU > (false, MMSpdu_initiate_ErrorPDU), 10);
                break;
            }
            case MMSpdu_conclude_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Conclude_RequestPDU > (false, MMSpdu_conclude_RequestPDU), 11);
                break;
            }
            case MMSpdu_conclude_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Conclude_ResponsePDU > (false, MMSpdu_conclude_ResponsePDU), 12);
                break;
            }
            case MMSpdu_conclude_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<Conclude_ErrorPDU > (false, MMSpdu_conclude_ErrorPDU), 13);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void MMSpdu::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Confirmed_RequestPDU > (true, MMSpdu_confirmed_RequestPDU), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Confirmed_ResponsePDU > (true, MMSpdu_confirmed_ResponsePDU), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Confirmed_ErrorPDU > (true, MMSpdu_confirmed_ErrorPDU), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Unconfirmed_PDU > (true, MMSpdu_unconfirmed_PDU), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RejectPDU > (true, MMSpdu_rejectPDU), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Cancel_RequestPDU > (true, MMSpdu_cancel_RequestPDU), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Cancel_ResponsePDU > (true, MMSpdu_cancel_ResponsePDU), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Cancel_ErrorPDU > (true, MMSpdu_cancel_ErrorPDU), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Initiate_RequestPDU > (true, MMSpdu_initiate_RequestPDU), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Initiate_ResponsePDU > (true, MMSpdu_initiate_ResponsePDU), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Initiate_ErrorPDU > (true, MMSpdu_initiate_ErrorPDU), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Conclude_RequestPDU > (true, MMSpdu_conclude_RequestPDU), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Conclude_ResponsePDU > (true, MMSpdu_conclude_ResponsePDU), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Conclude_ErrorPDU > (true, MMSpdu_conclude_ErrorPDU), 13)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence Confirmed-RequestPDU

    template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*invokeID_);
        ITU_T_BIND_TAG(listOfModifiers_);
        ITU_T_BIND_CHOICE(*service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*invokeID_);
        ITU_T_BIND_TAG(listOfModifiers_);
        ITU_T_BIND_CHOICE(*service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    // choice ConfirmedServiceRequest

    template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConfirmedServiceRequest_status:
            {
                ITU_T_IMPLICIT_TAG(*value<Status_Request > (false, ConfirmedServiceRequest_status), 0);
                break;
            }
            case ConfirmedServiceRequest_getNameList:
            {
                ITU_T_IMPLICIT_TAG(*value<GetNameList_Request > (false, ConfirmedServiceRequest_getNameList), 1);
                break;
            }
            case ConfirmedServiceRequest_identify:
            {
                ITU_T_IMPLICIT_TAG(*value<Identify_Request > (false, ConfirmedServiceRequest_identify), 2);
                break;
            }
            case ConfirmedServiceRequest_rename:
            {
                ITU_T_IMPLICIT_TAG(*value<Rename_Request > (false, ConfirmedServiceRequest_rename), 3);
                break;
            }
            case ConfirmedServiceRequest_read:
            {
                ITU_T_IMPLICIT_TAG(*value<Read_Request > (false, ConfirmedServiceRequest_read), 4);
                break;
            }
            case ConfirmedServiceRequest_write:
            {
                ITU_T_IMPLICIT_TAG(*value<Write_Request > (false, ConfirmedServiceRequest_write), 5);
                break;
            }
            case ConfirmedServiceRequest_getVariableAccessAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetVariableAccessAttributes_Request > (false, ConfirmedServiceRequest_getVariableAccessAttributes), 6);
                break;
            }
            case ConfirmedServiceRequest_defineNamedVariable:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineNamedVariable_Request > (false, ConfirmedServiceRequest_defineNamedVariable), 7);
                break;
            }
            case ConfirmedServiceRequest_defineScatteredAccess:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (false, ConfirmedServiceRequest_defineScatteredAccess), 8);
                break;
            }
            case ConfirmedServiceRequest_getScatteredAccessAttributes:
            {
                ITU_T_CHOICE_TAG(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (false, ConfirmedServiceRequest_getScatteredAccessAttributes), 9);
                break;
            }
            case ConfirmedServiceRequest_deleteVariableAccess:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteVariableAccess_Request > (false, ConfirmedServiceRequest_deleteVariableAccess), 10);
                break;
            }
            case ConfirmedServiceRequest_defineNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineNamedVariableList_Request > (false, ConfirmedServiceRequest_defineNamedVariableList), 11);
                break;
            }
            case ConfirmedServiceRequest_getNamedVariableListAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetNamedVariableListAttributes_Request > (false, ConfirmedServiceRequest_getNamedVariableListAttributes), 12);
                break;
            }
            case ConfirmedServiceRequest_deleteNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteNamedVariableList_Request > (false, ConfirmedServiceRequest_deleteNamedVariableList), 13);
                break;
            }
            case ConfirmedServiceRequest_defineNamedType:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineNamedType_Request > (false, ConfirmedServiceRequest_defineNamedType), 14);
                break;
            }
            case ConfirmedServiceRequest_getNamedTypeAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetNamedTypeAttributes_Request > (false, ConfirmedServiceRequest_getNamedTypeAttributes), 15);
                break;
            }
            case ConfirmedServiceRequest_deleteNamedType:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteNamedType_Request > (false, ConfirmedServiceRequest_deleteNamedType), 16);
                break;
            }
            case ConfirmedServiceRequest_input:
            {
                ITU_T_IMPLICIT_TAG(*value<Input_Request > (false, ConfirmedServiceRequest_input), 17);
                break;
            }
            case ConfirmedServiceRequest_output:
            {
                ITU_T_IMPLICIT_TAG(*value<Output_Request > (false, ConfirmedServiceRequest_output), 18);
                break;
            }
            case ConfirmedServiceRequest_takeControl:
            {
                ITU_T_IMPLICIT_TAG(*value<TakeControl_Request > (false, ConfirmedServiceRequest_takeControl), 19);
                break;
            }
            case ConfirmedServiceRequest_relinquishControl:
            {
                ITU_T_IMPLICIT_TAG(*value<RelinquishControl_Request > (false, ConfirmedServiceRequest_relinquishControl), 20);
                break;
            }
            case ConfirmedServiceRequest_defineSemaphore:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineSemaphore_Request > (false, ConfirmedServiceRequest_defineSemaphore), 21);
                break;
            }
            case ConfirmedServiceRequest_deleteSemaphore:
            {
                ITU_T_CHOICE_TAG(*value<DeleteSemaphore_Request > (false, ConfirmedServiceRequest_deleteSemaphore), 22);
                break;
            }
            case ConfirmedServiceRequest_reportSemaphoreStatus:
            {
                ITU_T_CHOICE_TAG(*value<ReportSemaphoreStatus_Request > (false, ConfirmedServiceRequest_reportSemaphoreStatus), 23);
                break;
            }
            case ConfirmedServiceRequest_reportPoolSemaphoreStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportPoolSemaphoreStatus_Request > (false, ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24);
                break;
            }
            case ConfirmedServiceRequest_reportSemaphoreEntryStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportSemaphoreEntryStatus_Request > (false, ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25);
                break;
            }
            case ConfirmedServiceRequest_initiateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<InitiateDownloadSequence_Request > (false, ConfirmedServiceRequest_initiateDownloadSequence), 26);
                break;
            }
            case ConfirmedServiceRequest_downloadSegment:
            {
                ITU_T_IMPLICIT_TAG(*value<DownloadSegment_Request > (false, ConfirmedServiceRequest_downloadSegment), 27);
                break;
            }
            case ConfirmedServiceRequest_terminateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<TerminateDownloadSequence_Request > (false, ConfirmedServiceRequest_terminateDownloadSequence), 28);
                break;
            }
            case ConfirmedServiceRequest_initiateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<InitiateUploadSequence_Request > (false, ConfirmedServiceRequest_initiateUploadSequence), 29);
                break;
            }
            case ConfirmedServiceRequest_uploadSegment:
            {
                ITU_T_IMPLICIT_TAG(*value<UploadSegment_Request > (false, ConfirmedServiceRequest_uploadSegment), 30);
                break;
            }
            case ConfirmedServiceRequest_terminateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<TerminateUploadSequence_Request > (false, ConfirmedServiceRequest_terminateUploadSequence), 31);
                break;
            }
            case ConfirmedServiceRequest_requestDomainDownload:
            {
                ITU_T_IMPLICIT_TAG(*value<RequestDomainDownload_Request > (false, ConfirmedServiceRequest_requestDomainDownload), 32);
                break;
            }
            case ConfirmedServiceRequest_requestDomainUpload:
            {
                ITU_T_IMPLICIT_TAG(*value<RequestDomainUpload_Request > (false, ConfirmedServiceRequest_requestDomainUpload), 33);
                break;
            }
            case ConfirmedServiceRequest_loadDomainContent:
            {
                ITU_T_IMPLICIT_TAG(*value<LoadDomainContent_Request > (false, ConfirmedServiceRequest_loadDomainContent), 34);
                break;
            }
            case ConfirmedServiceRequest_storeDomainContent:
            {
                ITU_T_IMPLICIT_TAG(*value<StoreDomainContent_Request > (false, ConfirmedServiceRequest_storeDomainContent), 35);
                break;
            }
            case ConfirmedServiceRequest_deleteDomain:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteDomain_Request > (false, ConfirmedServiceRequest_deleteDomain), 36);
                break;
            }
            case ConfirmedServiceRequest_getDomainAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetDomainAttributes_Request > (false, ConfirmedServiceRequest_getDomainAttributes), 37);
                break;
            }
            case ConfirmedServiceRequest_createProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<CreateProgramInvocation_Request > (false, ConfirmedServiceRequest_createProgramInvocation), 38);
                break;
            }
            case ConfirmedServiceRequest_deleteProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteProgramInvocation_Request > (false, ConfirmedServiceRequest_deleteProgramInvocation), 39);
                break;
            }
            case ConfirmedServiceRequest_start:
            {
                ITU_T_IMPLICIT_TAG(*value<Start_Request > (false, ConfirmedServiceRequest_start), 40);
                break;
            }
            case ConfirmedServiceRequest_stop:
            {
                ITU_T_IMPLICIT_TAG(*value<Stop_Request > (false, ConfirmedServiceRequest_stop), 41);
                break;
            }
            case ConfirmedServiceRequest_resume:
            {
                ITU_T_IMPLICIT_TAG(*value<Resume_Request > (false, ConfirmedServiceRequest_resume), 42);
                break;
            }
            case ConfirmedServiceRequest_reset:
            {
                ITU_T_IMPLICIT_TAG(*value<Reset_Request > (false, ConfirmedServiceRequest_reset), 43);
                break;
            }
            case ConfirmedServiceRequest_kill:
            {
                ITU_T_IMPLICIT_TAG(*value<Kill_Request > (false, ConfirmedServiceRequest_kill), 44);
                break;
            }
            case ConfirmedServiceRequest_getProgramInvocationAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetProgramInvocationAttributes_Request > (false, ConfirmedServiceRequest_getProgramInvocationAttributes), 45);
                break;
            }
            case ConfirmedServiceRequest_obtainFile:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ObtainFile_Request > (false, ConfirmedServiceRequest_obtainFile), 46);
                break;
            }
            case ConfirmedServiceRequest_defineEventCondition:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventCondition_Request > (false, ConfirmedServiceRequest_defineEventCondition), 47);
                break;
            }
            case ConfirmedServiceRequest_deleteEventCondition:
            {
                ITU_T_CHOICE_TAG(*value<DeleteEventCondition_Request > (false, ConfirmedServiceRequest_deleteEventCondition), 48);
                break;
            }
            case ConfirmedServiceRequest_getEventConditionAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetEventConditionAttributes_Request > (false, ConfirmedServiceRequest_getEventConditionAttributes), 49);
                break;
            }
            case ConfirmedServiceRequest_reportEventConditionStatus:
            {
                ITU_T_CHOICE_TAG(*value<ReportEventConditionStatus_Request > (false, ConfirmedServiceRequest_reportEventConditionStatus), 50);
                break;
            }
            case ConfirmedServiceRequest_alterEventConditionMonitoring:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterEventConditionMonitoring_Request > (false, ConfirmedServiceRequest_alterEventConditionMonitoring), 51);
                break;
            }
            case ConfirmedServiceRequest_triggerEvent:
            {
                ITU_T_IMPLICIT_TAG(*value<TriggerEvent_Request > (false, ConfirmedServiceRequest_triggerEvent), 52);
                break;
            }
            case ConfirmedServiceRequest_defineEventAction:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventAction_Request > (false, ConfirmedServiceRequest_defineEventAction), 53);
                break;
            }
            case ConfirmedServiceRequest_deleteEventAction:
            {
                ITU_T_CHOICE_TAG(*value<DeleteEventAction_Request > (false, ConfirmedServiceRequest_deleteEventAction), 54);
                break;
            }
            case ConfirmedServiceRequest_getEventActionAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetEventActionAttributes_Request > (false, ConfirmedServiceRequest_getEventActionAttributes), 55);
                break;
            }
            case ConfirmedServiceRequest_reportEventActionStatus:
            {
                ITU_T_CHOICE_TAG(*value<ReportEventActionStatus_Request > (false, ConfirmedServiceRequest_reportEventActionStatus), 56);
                break;
            }
            case ConfirmedServiceRequest_defineEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventEnrollment_Request > (false, ConfirmedServiceRequest_defineEventEnrollment), 57);
                break;
            }
            case ConfirmedServiceRequest_deleteEventEnrollment:
            {
                ITU_T_CHOICE_TAG(*value<DeleteEventEnrollment_Request > (false, ConfirmedServiceRequest_deleteEventEnrollment), 58);
                break;
            }
            case ConfirmedServiceRequest_alterEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterEventEnrollment_Request > (false, ConfirmedServiceRequest_alterEventEnrollment), 59);
                break;
            }
            case ConfirmedServiceRequest_reportEventEnrollmentStatus:
            {
                ITU_T_CHOICE_TAG(*value<ReportEventEnrollmentStatus_Request > (false, ConfirmedServiceRequest_reportEventEnrollmentStatus), 60);
                break;
            }
            case ConfirmedServiceRequest_getEventEnrollmentAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetEventEnrollmentAttributes_Request > (false, ConfirmedServiceRequest_getEventEnrollmentAttributes), 61);
                break;
            }
            case ConfirmedServiceRequest_acknowledgeEventNotification:
            {
                ITU_T_IMPLICIT_TAG(*value<AcknowledgeEventNotification_Request > (false, ConfirmedServiceRequest_acknowledgeEventNotification), 62);
                break;
            }
            case ConfirmedServiceRequest_getAlarmSummary:
            {
                ITU_T_IMPLICIT_TAG(*value<GetAlarmSummary_Request > (false, ConfirmedServiceRequest_getAlarmSummary), 63);
                break;
            }
            case ConfirmedServiceRequest_getAlarmEnrollmentSummary:
            {
                ITU_T_IMPLICIT_TAG(*value<GetAlarmEnrollmentSummary_Request > (false, ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64);
                break;
            }
            case ConfirmedServiceRequest_readJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<ReadJournal_Request > (false, ConfirmedServiceRequest_readJournal), 65);
                break;
            }
            case ConfirmedServiceRequest_writeJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<WriteJournal_Request > (false, ConfirmedServiceRequest_writeJournal), 66);
                break;
            }
            case ConfirmedServiceRequest_initializeJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<InitializeJournal_Request > (false, ConfirmedServiceRequest_initializeJournal), 67);
                break;
            }
            case ConfirmedServiceRequest_reportJournalStatus:
            {
                ITU_T_CHOICE_TAG(*value<ReportJournalStatus_Request > (false, ConfirmedServiceRequest_reportJournalStatus), 68);
                break;
            }
            case ConfirmedServiceRequest_createJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<CreateJournal_Request > (false, ConfirmedServiceRequest_createJournal), 69);
                break;
            }
            case ConfirmedServiceRequest_deleteJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteJournal_Request > (false, ConfirmedServiceRequest_deleteJournal), 70);
                break;
            }
            case ConfirmedServiceRequest_getCapabilityList:
            {
                ITU_T_IMPLICIT_TAG(*value<GetCapabilityList_Request > (false, ConfirmedServiceRequest_getCapabilityList), 71);
                break;
            }
            case ConfirmedServiceRequest_fileOpen:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileOpen_Request > (false, ConfirmedServiceRequest_fileOpen), 72);
                break;
            }
            case ConfirmedServiceRequest_fileRead:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRead_Request > (false, ConfirmedServiceRequest_fileRead), 73);
                break;
            }
            case ConfirmedServiceRequest_fileClose:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileClose_Request > (false, ConfirmedServiceRequest_fileClose), 74);
                break;
            }
            case ConfirmedServiceRequest_fileRename:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRename_Request > (false, ConfirmedServiceRequest_fileRename), 75);
                break;
            }
            case ConfirmedServiceRequest_fileDelete:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDelete_Request > (false, ConfirmedServiceRequest_fileDelete), 76);
                break;
            }
            case ConfirmedServiceRequest_fileDirectory:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDirectory_Request > (false, ConfirmedServiceRequest_fileDirectory), 77);
                break;
            }
            case ConfirmedServiceRequest_additionalService:
            {
                ITU_T_CHOICE_TAG(*value<AdditionalService_Request > (false, ConfirmedServiceRequest_additionalService), 78);
                break;
            }
            case ConfirmedServiceRequest_getDataExchangeAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetDataExchangeAttributes_Request > (false, ConfirmedServiceRequest_getDataExchangeAttributes), 80);
                break;
            }
            case ConfirmedServiceRequest_exchangeData:
            {
                ITU_T_IMPLICIT_TAG(*value<ExchangeData_Request > (false, ConfirmedServiceRequest_exchangeData), 81);
                break;
            }
            case ConfirmedServiceRequest_defineAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineAccessControlList_Request > (false, ConfirmedServiceRequest_defineAccessControlList), 82);
                break;
            }
            case ConfirmedServiceRequest_getAccessControlListAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetAccessControlListAttributes_Request > (false, ConfirmedServiceRequest_getAccessControlListAttributes), 83);
                break;
            }
            case ConfirmedServiceRequest_reportAccessControlledObjects:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportAccessControlledObjects_Request > (false, ConfirmedServiceRequest_reportAccessControlledObjects), 84);
                break;
            }
            case ConfirmedServiceRequest_deleteAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteAccessControlList_Request > (false, ConfirmedServiceRequest_deleteAccessControlList), 85);
                break;
            }
            case ConfirmedServiceRequest_changeAccessControl:
            {
                ITU_T_IMPLICIT_TAG(*value<ChangeAccessControl_Request > (false, ConfirmedServiceRequest_changeAccessControl), 86);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Status_Request > (true, ConfirmedServiceRequest_status), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetNameList_Request > (true, ConfirmedServiceRequest_getNameList), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identify_Request > (true, ConfirmedServiceRequest_identify), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Rename_Request > (true, ConfirmedServiceRequest_rename), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Read_Request > (true, ConfirmedServiceRequest_read), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Write_Request > (true, ConfirmedServiceRequest_write), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetVariableAccessAttributes_Request > (true, ConfirmedServiceRequest_getVariableAccessAttributes), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineNamedVariable_Request > (true, ConfirmedServiceRequest_defineNamedVariable), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (true, ConfirmedServiceRequest_defineScatteredAccess), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (true, ConfirmedServiceRequest_getScatteredAccessAttributes), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteVariableAccess_Request > (true, ConfirmedServiceRequest_deleteVariableAccess), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineNamedVariableList_Request > (true, ConfirmedServiceRequest_defineNamedVariableList), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetNamedVariableListAttributes_Request > (true, ConfirmedServiceRequest_getNamedVariableListAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteNamedVariableList_Request > (true, ConfirmedServiceRequest_deleteNamedVariableList), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineNamedType_Request > (true, ConfirmedServiceRequest_defineNamedType), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetNamedTypeAttributes_Request > (true, ConfirmedServiceRequest_getNamedTypeAttributes), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteNamedType_Request > (true, ConfirmedServiceRequest_deleteNamedType), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Input_Request > (true, ConfirmedServiceRequest_input), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Output_Request > (true, ConfirmedServiceRequest_output), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TakeControl_Request > (true, ConfirmedServiceRequest_takeControl), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RelinquishControl_Request > (true, ConfirmedServiceRequest_relinquishControl), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineSemaphore_Request > (true, ConfirmedServiceRequest_defineSemaphore), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DeleteSemaphore_Request > (true, ConfirmedServiceRequest_deleteSemaphore), 22)) return;
                        else free();
                        break;
                    }
                    case 23:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ReportSemaphoreStatus_Request > (true, ConfirmedServiceRequest_reportSemaphoreStatus), 23)) return;
                        else free();
                        break;
                    }
                    case 24:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportPoolSemaphoreStatus_Request > (true, ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24)) return;
                        else free();
                        break;
                    }
                    case 25:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportSemaphoreEntryStatus_Request > (true, ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25)) return;
                        else free();
                        break;
                    }
                    case 26:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitiateDownloadSequence_Request > (true, ConfirmedServiceRequest_initiateDownloadSequence), 26)) return;
                        else free();
                        break;
                    }
                    case 27:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DownloadSegment_Request > (true, ConfirmedServiceRequest_downloadSegment), 27)) return;
                        else free();
                        break;
                    }
                    case 28:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TerminateDownloadSequence_Request > (true, ConfirmedServiceRequest_terminateDownloadSequence), 28)) return;
                        else free();
                        break;
                    }
                    case 29:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitiateUploadSequence_Request > (true, ConfirmedServiceRequest_initiateUploadSequence), 29)) return;
                        else free();
                        break;
                    }
                    case 30:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UploadSegment_Request > (true, ConfirmedServiceRequest_uploadSegment), 30)) return;
                        else free();
                        break;
                    }
                    case 31:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TerminateUploadSequence_Request > (true, ConfirmedServiceRequest_terminateUploadSequence), 31)) return;
                        else free();
                        break;
                    }
                    case 32:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RequestDomainDownload_Request > (true, ConfirmedServiceRequest_requestDomainDownload), 32)) return;
                        else free();
                        break;
                    }
                    case 33:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RequestDomainUpload_Request > (true, ConfirmedServiceRequest_requestDomainUpload), 33)) return;
                        else free();
                        break;
                    }
                    case 34:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<LoadDomainContent_Request > (true, ConfirmedServiceRequest_loadDomainContent), 34)) return;
                        else free();
                        break;
                    }
                    case 35:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StoreDomainContent_Request > (true, ConfirmedServiceRequest_storeDomainContent), 35)) return;
                        else free();
                        break;
                    }
                    case 36:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteDomain_Request > (true, ConfirmedServiceRequest_deleteDomain), 36)) return;
                        else free();
                        break;
                    }
                    case 37:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetDomainAttributes_Request > (true, ConfirmedServiceRequest_getDomainAttributes), 37)) return;
                        else free();
                        break;
                    }
                    case 38:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CreateProgramInvocation_Request > (true, ConfirmedServiceRequest_createProgramInvocation), 38)) return;
                        else free();
                        break;
                    }
                    case 39:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteProgramInvocation_Request > (true, ConfirmedServiceRequest_deleteProgramInvocation), 39)) return;
                        else free();
                        break;
                    }
                    case 40:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Start_Request > (true, ConfirmedServiceRequest_start), 40)) return;
                        else free();
                        break;
                    }
                    case 41:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Stop_Request > (true, ConfirmedServiceRequest_stop), 41)) return;
                        else free();
                        break;
                    }
                    case 42:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Resume_Request > (true, ConfirmedServiceRequest_resume), 42)) return;
                        else free();
                        break;
                    }
                    case 43:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Reset_Request > (true, ConfirmedServiceRequest_reset), 43)) return;
                        else free();
                        break;
                    }
                    case 44:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Kill_Request > (true, ConfirmedServiceRequest_kill), 44)) return;
                        else free();
                        break;
                    }
                    case 45:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetProgramInvocationAttributes_Request > (true, ConfirmedServiceRequest_getProgramInvocationAttributes), 45)) return;
                        else free();
                        break;
                    }
                    case 46:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ObtainFile_Request > (true, ConfirmedServiceRequest_obtainFile), 46)) return;
                        else free();
                        break;
                    }
                    case 47:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventCondition_Request > (true, ConfirmedServiceRequest_defineEventCondition), 47)) return;
                        else free();
                        break;
                    }
                    case 48:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DeleteEventCondition_Request > (true, ConfirmedServiceRequest_deleteEventCondition), 48)) return;
                        else free();
                        break;
                    }
                    case 49:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetEventConditionAttributes_Request > (true, ConfirmedServiceRequest_getEventConditionAttributes), 49)) return;
                        else free();
                        break;
                    }
                    case 50:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ReportEventConditionStatus_Request > (true, ConfirmedServiceRequest_reportEventConditionStatus), 50)) return;
                        else free();
                        break;
                    }
                    case 51:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterEventConditionMonitoring_Request > (true, ConfirmedServiceRequest_alterEventConditionMonitoring), 51)) return;
                        else free();
                        break;
                    }
                    case 52:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TriggerEvent_Request > (true, ConfirmedServiceRequest_triggerEvent), 52)) return;
                        else free();
                        break;
                    }
                    case 53:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventAction_Request > (true, ConfirmedServiceRequest_defineEventAction), 53)) return;
                        else free();
                        break;
                    }
                    case 54:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DeleteEventAction_Request > (true, ConfirmedServiceRequest_deleteEventAction), 54)) return;
                        else free();
                        break;
                    }
                    case 55:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetEventActionAttributes_Request > (true, ConfirmedServiceRequest_getEventActionAttributes), 55)) return;
                        else free();
                        break;
                    }
                    case 56:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ReportEventActionStatus_Request > (true, ConfirmedServiceRequest_reportEventActionStatus), 56)) return;
                        else free();
                        break;
                    }
                    case 57:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventEnrollment_Request > (true, ConfirmedServiceRequest_defineEventEnrollment), 57)) return;
                        else free();
                        break;
                    }
                    case 58:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DeleteEventEnrollment_Request > (true, ConfirmedServiceRequest_deleteEventEnrollment), 58)) return;
                        else free();
                        break;
                    }
                    case 59:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterEventEnrollment_Request > (true, ConfirmedServiceRequest_alterEventEnrollment), 59)) return;
                        else free();
                        break;
                    }
                    case 60:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ReportEventEnrollmentStatus_Request > (true, ConfirmedServiceRequest_reportEventEnrollmentStatus), 60)) return;
                        else free();
                        break;
                    }
                    case 61:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetEventEnrollmentAttributes_Request > (true, ConfirmedServiceRequest_getEventEnrollmentAttributes), 61)) return;
                        else free();
                        break;
                    }
                    case 62:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AcknowledgeEventNotification_Request > (true, ConfirmedServiceRequest_acknowledgeEventNotification), 62)) return;
                        else free();
                        break;
                    }
                    case 63:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetAlarmSummary_Request > (true, ConfirmedServiceRequest_getAlarmSummary), 63)) return;
                        else free();
                        break;
                    }
                    case 64:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetAlarmEnrollmentSummary_Request > (true, ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64)) return;
                        else free();
                        break;
                    }
                    case 65:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReadJournal_Request > (true, ConfirmedServiceRequest_readJournal), 65)) return;
                        else free();
                        break;
                    }
                    case 66:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<WriteJournal_Request > (true, ConfirmedServiceRequest_writeJournal), 66)) return;
                        else free();
                        break;
                    }
                    case 67:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitializeJournal_Request > (true, ConfirmedServiceRequest_initializeJournal), 67)) return;
                        else free();
                        break;
                    }
                    case 68:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ReportJournalStatus_Request > (true, ConfirmedServiceRequest_reportJournalStatus), 68)) return;
                        else free();
                        break;
                    }
                    case 69:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CreateJournal_Request > (true, ConfirmedServiceRequest_createJournal), 69)) return;
                        else free();
                        break;
                    }
                    case 70:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteJournal_Request > (true, ConfirmedServiceRequest_deleteJournal), 70)) return;
                        else free();
                        break;
                    }
                    case 71:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetCapabilityList_Request > (true, ConfirmedServiceRequest_getCapabilityList), 71)) return;
                        else free();
                        break;
                    }
                    case 72:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileOpen_Request > (true, ConfirmedServiceRequest_fileOpen), 72)) return;
                        else free();
                        break;
                    }
                    case 73:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRead_Request > (true, ConfirmedServiceRequest_fileRead), 73)) return;
                        else free();
                        break;
                    }
                    case 74:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileClose_Request > (true, ConfirmedServiceRequest_fileClose), 74)) return;
                        else free();
                        break;
                    }
                    case 75:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRename_Request > (true, ConfirmedServiceRequest_fileRename), 75)) return;
                        else free();
                        break;
                    }
                    case 76:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDelete_Request > (true, ConfirmedServiceRequest_fileDelete), 76)) return;
                        else free();
                        break;
                    }
                    case 77:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDirectory_Request > (true, ConfirmedServiceRequest_fileDirectory), 77)) return;
                        else free();
                        break;
                    }
                    case 78:
                    {
                        if (ITU_T_CHOICE_TAG(*value<AdditionalService_Request > (true, ConfirmedServiceRequest_additionalService), 78)) return;
                        else free();
                        break;
                    }
                    case 80:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetDataExchangeAttributes_Request > (true, ConfirmedServiceRequest_getDataExchangeAttributes), 80)) return;
                        else free();
                        break;
                    }
                    case 81:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ExchangeData_Request > (true, ConfirmedServiceRequest_exchangeData), 81)) return;
                        else free();
                        break;
                    }
                    case 82:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineAccessControlList_Request > (true, ConfirmedServiceRequest_defineAccessControlList), 82)) return;
                        else free();
                        break;
                    }
                    case 83:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetAccessControlListAttributes_Request > (true, ConfirmedServiceRequest_getAccessControlListAttributes), 83)) return;
                        else free();
                        break;
                    }
                    case 84:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportAccessControlledObjects_Request > (true, ConfirmedServiceRequest_reportAccessControlledObjects), 84)) return;
                        else free();
                        break;
                    }
                    case 85:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteAccessControlList_Request > (true, ConfirmedServiceRequest_deleteAccessControlList), 85)) return;
                        else free();
                        break;
                    }
                    case 86:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ChangeAccessControl_Request > (true, ConfirmedServiceRequest_changeAccessControl), 86)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice AdditionalService-Request

    template<> void AdditionalService_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Request_vMDStop:
            {
                ITU_T_IMPLICIT_TAG(*value<VMDStop_Request > (false, AdditionalService_Request_vMDStop), 0);
                break;
            }
            case AdditionalService_Request_vMDReset:
            {
                ITU_T_IMPLICIT_TAG(*value<VMDReset_Request > (false, AdditionalService_Request_vMDReset), 1);
                break;
            }
            case AdditionalService_Request_select:
            {
                ITU_T_IMPLICIT_TAG(*value<Select_Request > (false, AdditionalService_Request_select), 2);
                break;
            }
            case AdditionalService_Request_alterPI:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterProgramInvocationAttributes_Request > (false, AdditionalService_Request_alterPI), 3);
                break;
            }
            case AdditionalService_Request_initiateUCLoad:
            {
                ITU_T_IMPLICIT_TAG(*value<InitiateUnitControlLoad_Request > (false, AdditionalService_Request_initiateUCLoad), 4);
                break;
            }
            case AdditionalService_Request_uCLoad:
            {
                ITU_T_IMPLICIT_TAG(*value<UnitControlLoadSegment_Request > (false, AdditionalService_Request_uCLoad), 5);
                break;
            }
            case AdditionalService_Request_uCUpload:
            {
                ITU_T_IMPLICIT_TAG(*value<UnitControlUpload_Request > (false, AdditionalService_Request_uCUpload), 6);
                break;
            }
            case AdditionalService_Request_startUC:
            {
                ITU_T_IMPLICIT_TAG(*value<StartUnitControl_Request > (false, AdditionalService_Request_startUC), 7);
                break;
            }
            case AdditionalService_Request_stopUC:
            {
                ITU_T_IMPLICIT_TAG(*value<StopUnitControl_Request > (false, AdditionalService_Request_stopUC), 8);
                break;
            }
            case AdditionalService_Request_createUC:
            {
                ITU_T_IMPLICIT_TAG(*value<CreateUnitControl_Request > (false, AdditionalService_Request_createUC), 9);
                break;
            }
            case AdditionalService_Request_addToUC:
            {
                ITU_T_IMPLICIT_TAG(*value<AddToUnitControl_Request > (false, AdditionalService_Request_addToUC), 10);
                break;
            }
            case AdditionalService_Request_removeFromUC:
            {
                ITU_T_IMPLICIT_TAG(*value<RemoveFromUnitControl_Request > (false, AdditionalService_Request_removeFromUC), 11);
                break;
            }
            case AdditionalService_Request_getUCAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetUnitControlAttributes_Request > (false, AdditionalService_Request_getUCAttributes), 12);
                break;
            }
            case AdditionalService_Request_loadUCFromFile:
            {
                ITU_T_IMPLICIT_TAG(*value<LoadUnitControlFromFile_Request > (false, AdditionalService_Request_loadUCFromFile), 13);
                break;
            }
            case AdditionalService_Request_storeUCToFile:
            {
                ITU_T_IMPLICIT_TAG(*value<StoreUnitControlToFile_Request > (false, AdditionalService_Request_storeUCToFile), 14);
                break;
            }
            case AdditionalService_Request_deleteUC:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteUnitControl_Request > (false, AdditionalService_Request_deleteUC), 15);
                break;
            }
            case AdditionalService_Request_defineECL:
            {
                ITU_T_EXPLICIT_TAG(*value<DefineEventConditionList_Request > (false, AdditionalService_Request_defineECL), 16);
                break;
            }
            case AdditionalService_Request_deleteECL:
            {
                ITU_T_CHOICE_TAG(*value<DeleteEventConditionList_Request > (false, AdditionalService_Request_deleteECL), 17);
                break;
            }
            case AdditionalService_Request_addECLReference:
            {
                ITU_T_IMPLICIT_TAG(*value<AddEventConditionListReference_Request > (false, AdditionalService_Request_addECLReference), 18);
                break;
            }
            case AdditionalService_Request_removeECLReference:
            {
                ITU_T_IMPLICIT_TAG(*value<RemoveEventConditionListReference_Request > (false, AdditionalService_Request_removeECLReference), 19);
                break;
            }
            case AdditionalService_Request_getECLAttributes:
            {
                ITU_T_CHOICE_TAG(*value<GetEventConditionListAttributes_Request > (false, AdditionalService_Request_getECLAttributes), 20);
                break;
            }
            case AdditionalService_Request_reportECLStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportEventConditionListStatus_Request > (false, AdditionalService_Request_reportECLStatus), 21);
                break;
            }
            case AdditionalService_Request_alterECLMonitoring:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterEventConditionListMonitoring_Request > (false, AdditionalService_Request_alterECLMonitoring), 22);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AdditionalService_Request::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<VMDStop_Request > (true, AdditionalService_Request_vMDStop), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<VMDReset_Request > (true, AdditionalService_Request_vMDReset), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Select_Request > (true, AdditionalService_Request_select), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterProgramInvocationAttributes_Request > (true, AdditionalService_Request_alterPI), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitiateUnitControlLoad_Request > (true, AdditionalService_Request_initiateUCLoad), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UnitControlLoadSegment_Request > (true, AdditionalService_Request_uCLoad), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UnitControlUpload_Request > (true, AdditionalService_Request_uCUpload), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StartUnitControl_Request > (true, AdditionalService_Request_startUC), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StopUnitControl_Request > (true, AdditionalService_Request_stopUC), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CreateUnitControl_Request > (true, AdditionalService_Request_createUC), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AddToUnitControl_Request > (true, AdditionalService_Request_addToUC), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RemoveFromUnitControl_Request > (true, AdditionalService_Request_removeFromUC), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetUnitControlAttributes_Request > (true, AdditionalService_Request_getUCAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<LoadUnitControlFromFile_Request > (true, AdditionalService_Request_loadUCFromFile), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StoreUnitControlToFile_Request > (true, AdditionalService_Request_storeUCToFile), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteUnitControl_Request > (true, AdditionalService_Request_deleteUC), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<DefineEventConditionList_Request > (true, AdditionalService_Request_defineECL), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DeleteEventConditionList_Request > (true, AdditionalService_Request_deleteECL), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AddEventConditionListReference_Request > (true, AdditionalService_Request_addECLReference), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RemoveEventConditionListReference_Request > (true, AdditionalService_Request_removeECLReference), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_CHOICE_TAG(*value<GetEventConditionListAttributes_Request > (true, AdditionalService_Request_getECLAttributes), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportEventConditionListStatus_Request > (true, AdditionalService_Request_reportECLStatus), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterEventConditionListMonitoring_Request > (true, AdditionalService_Request_alterECLMonitoring), 22)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice Request-Detail

    template<> void Request_Detail::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Request_Detail_otherRequests:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, Request_Detail_otherRequests));
                break;
            }
            case Request_Detail_createProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_CreateProgramInvocation_Request > (false, Request_Detail_createProgramInvocation), 38);
                break;
            }
            case Request_Detail_start:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_Start_Request > (false, Request_Detail_start), 40);
                break;
            }
            case Request_Detail_resume:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_Resume_Request > (false, Request_Detail_resume), 42);
                break;
            }
            case Request_Detail_defineEventCondition:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_DefineEventCondition_Request > (false, Request_Detail_defineEventCondition), 47);
                break;
            }
            case Request_Detail_alterEventConditionMonitoring:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_AlterEventConditionMonitoring_Request > (false, Request_Detail_alterEventConditionMonitoring), 51);
                break;
            }
            case Request_Detail_defineEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_DefineEventEnrollment_Request > (false, Request_Detail_defineEventEnrollment), 57);
                break;
            }
            case Request_Detail_alterEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_AlterEventEnrollment_Request > (false, Request_Detail_alterEventEnrollment), 59);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Request_Detail::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 38:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_CreateProgramInvocation_Request > (true, Request_Detail_createProgramInvocation), 38)) return;
                        else free();
                        break;
                    }
                    case 40:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_Start_Request > (true, Request_Detail_start), 40)) return;
                        else free();
                        break;
                    }
                    case 42:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_Resume_Request > (true, Request_Detail_resume), 42)) return;
                        else free();
                        break;
                    }
                    case 47:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_DefineEventCondition_Request > (true, Request_Detail_defineEventCondition), 47)) return;
                        else free();
                        break;
                    }
                    case 51:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_AlterEventConditionMonitoring_Request > (true, Request_Detail_alterEventConditionMonitoring), 51)) return;
                        else free();
                        break;
                    }
                    case 57:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_DefineEventEnrollment_Request > (true, Request_Detail_defineEventEnrollment), 57)) return;
                        else free();
                        break;
                    }
                    case 59:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_AlterEventEnrollment_Request > (true, Request_Detail_alterEventEnrollment), 59)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, Request_Detail_otherRequests))) return;
                else free();
            }
        }
    }

    // sequence Unconfirmed-PDU

    template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    // choice UnconfirmedService

    template<> void UnconfirmedService::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case UnconfirmedService_informationReport:
            {
                ITU_T_IMPLICIT_TAG(*value<InformationReport > (false, UnconfirmedService_informationReport), 0);
                break;
            }
            case UnconfirmedService_unsolicitedStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<UnsolicitedStatus > (false, UnconfirmedService_unsolicitedStatus), 1);
                break;
            }
            case UnconfirmedService_eventNotification:
            {
                ITU_T_IMPLICIT_TAG(*value<EventNotification > (false, UnconfirmedService_eventNotification), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnconfirmedService::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InformationReport > (true, UnconfirmedService_informationReport), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UnsolicitedStatus > (true, UnconfirmedService_unsolicitedStatus), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<EventNotification > (true, UnconfirmedService_eventNotification), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice Unconfirmed-Detail

    template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Unconfirmed_Detail_otherRequests:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, Unconfirmed_Detail_otherRequests));
                break;
            }
            case Unconfirmed_Detail_eventNotification:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_EventNotification > (false, Unconfirmed_Detail_eventNotification), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_EventNotification > (true, Unconfirmed_Detail_eventNotification), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, Unconfirmed_Detail_otherRequests))) return;
                else free();
            }
        }
    }

    // sequence Confirmed-ResponsePDU

    template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*invokeID_);
        ITU_T_BIND_CHOICE(*service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*invokeID_);
        ITU_T_BIND_CHOICE(*service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    // choice ConfirmedServiceResponse

    template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConfirmedServiceResponse_status:
            {
                ITU_T_IMPLICIT_TAG(*value<Status_Response > (false, ConfirmedServiceResponse_status), 0);
                break;
            }
            case ConfirmedServiceResponse_getNameList:
            {
                ITU_T_IMPLICIT_TAG(*value<GetNameList_Response > (false, ConfirmedServiceResponse_getNameList), 1);
                break;
            }
            case ConfirmedServiceResponse_identify:
            {
                ITU_T_IMPLICIT_TAG(*value<Identify_Response > (false, ConfirmedServiceResponse_identify), 2);
                break;
            }
            case ConfirmedServiceResponse_rename:
            {
                ITU_T_IMPLICIT_TAG(*value<Rename_Response > (false, ConfirmedServiceResponse_rename), 3);
                break;
            }
            case ConfirmedServiceResponse_read:
            {
                ITU_T_IMPLICIT_TAG(*value<Read_Response > (false, ConfirmedServiceResponse_read), 4);
                break;
            }
            case ConfirmedServiceResponse_getVariableAccessAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetVariableAccessAttributes_Response > (false, ConfirmedServiceResponse_getVariableAccessAttributes), 6);
                break;
            }
            case ConfirmedServiceResponse_defineNamedVariable:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineNamedVariable_Response > (false, ConfirmedServiceResponse_defineNamedVariable), 7);
                break;
            }
            case ConfirmedServiceResponse_defineScatteredAccess:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (false, ConfirmedServiceResponse_defineScatteredAccess), 8);
                break;
            }
            case ConfirmedServiceResponse_getScatteredAccessAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (false, ConfirmedServiceResponse_getScatteredAccessAttributes), 9);
                break;
            }
            case ConfirmedServiceResponse_deleteVariableAccess:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteVariableAccess_Response > (false, ConfirmedServiceResponse_deleteVariableAccess), 10);
                break;
            }
            case ConfirmedServiceResponse_defineNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineNamedVariableList_Response > (false, ConfirmedServiceResponse_defineNamedVariableList), 11);
                break;
            }
            case ConfirmedServiceResponse_getNamedVariableListAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetNamedVariableListAttributes_Response > (false, ConfirmedServiceResponse_getNamedVariableListAttributes), 12);
                break;
            }
            case ConfirmedServiceResponse_deleteNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteNamedVariableList_Response > (false, ConfirmedServiceResponse_deleteNamedVariableList), 13);
                break;
            }
            case ConfirmedServiceResponse_defineNamedType:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineNamedType_Response > (false, ConfirmedServiceResponse_defineNamedType), 14);
                break;
            }
            case ConfirmedServiceResponse_getNamedTypeAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetNamedTypeAttributes_Response > (false, ConfirmedServiceResponse_getNamedTypeAttributes), 15);
                break;
            }
            case ConfirmedServiceResponse_deleteNamedType:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteNamedType_Response > (false, ConfirmedServiceResponse_deleteNamedType), 16);
                break;
            }
            case ConfirmedServiceResponse_input:
            {
                ITU_T_IMPLICIT_TAG(*value<Input_Response > (false, ConfirmedServiceResponse_input), 17);
                break;
            }
            case ConfirmedServiceResponse_output:
            {
                ITU_T_IMPLICIT_TAG(*value<Output_Response > (false, ConfirmedServiceResponse_output), 18);
                break;
            }
            case ConfirmedServiceResponse_takeControl:
            {
                ITU_T_CHOICE_TAG(*value<TakeControl_Response > (false, ConfirmedServiceResponse_takeControl), 19);
                break;
            }
            case ConfirmedServiceResponse_relinquishControl:
            {
                ITU_T_IMPLICIT_TAG(*value<RelinquishControl_Response > (false, ConfirmedServiceResponse_relinquishControl), 20);
                break;
            }
            case ConfirmedServiceResponse_defineSemaphore:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineSemaphore_Response > (false, ConfirmedServiceResponse_defineSemaphore), 21);
                break;
            }
            case ConfirmedServiceResponse_deleteSemaphore:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteSemaphore_Response > (false, ConfirmedServiceResponse_deleteSemaphore), 22);
                break;
            }
            case ConfirmedServiceResponse_reportSemaphoreStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportSemaphoreStatus_Response > (false, ConfirmedServiceResponse_reportSemaphoreStatus), 23);
                break;
            }
            case ConfirmedServiceResponse_reportPoolSemaphoreStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportPoolSemaphoreStatus_Response > (false, ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24);
                break;
            }
            case ConfirmedServiceResponse_reportSemaphoreEntryStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportSemaphoreEntryStatus_Response > (false, ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25);
                break;
            }
            case ConfirmedServiceResponse_initiateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<InitiateDownloadSequence_Response > (false, ConfirmedServiceResponse_initiateDownloadSequence), 26);
                break;
            }
            case ConfirmedServiceResponse_downloadSegment:
            {
                ITU_T_IMPLICIT_TAG(*value<DownloadSegment_Response > (false, ConfirmedServiceResponse_downloadSegment), 27);
                break;
            }
            case ConfirmedServiceResponse_terminateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<TerminateDownloadSequence_Response > (false, ConfirmedServiceResponse_terminateDownloadSequence), 28);
                break;
            }
            case ConfirmedServiceResponse_initiateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<InitiateUploadSequence_Response > (false, ConfirmedServiceResponse_initiateUploadSequence), 29);
                break;
            }
            case ConfirmedServiceResponse_uploadSegment:
            {
                ITU_T_IMPLICIT_TAG(*value<UploadSegment_Response > (false, ConfirmedServiceResponse_uploadSegment), 30);
                break;
            }
            case ConfirmedServiceResponse_terminateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(*value<TerminateUploadSequence_Response > (false, ConfirmedServiceResponse_terminateUploadSequence), 31);
                break;
            }
            case ConfirmedServiceResponse_requestDomainDownload:
            {
                ITU_T_IMPLICIT_TAG(*value<RequestDomainDownload_Response > (false, ConfirmedServiceResponse_requestDomainDownload), 32);
                break;
            }
            case ConfirmedServiceResponse_requestDomainUpload:
            {
                ITU_T_IMPLICIT_TAG(*value<RequestDomainUpload_Response > (false, ConfirmedServiceResponse_requestDomainUpload), 33);
                break;
            }
            case ConfirmedServiceResponse_loadDomainContent:
            {
                ITU_T_IMPLICIT_TAG(*value<LoadDomainContent_Response > (false, ConfirmedServiceResponse_loadDomainContent), 34);
                break;
            }
            case ConfirmedServiceResponse_storeDomainContent:
            {
                ITU_T_IMPLICIT_TAG(*value<StoreDomainContent_Response > (false, ConfirmedServiceResponse_storeDomainContent), 35);
                break;
            }
            case ConfirmedServiceResponse_deleteDomain:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteDomain_Response > (false, ConfirmedServiceResponse_deleteDomain), 36);
                break;
            }
            case ConfirmedServiceResponse_getDomainAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetDomainAttributes_Response > (false, ConfirmedServiceResponse_getDomainAttributes), 37);
                break;
            }
            case ConfirmedServiceResponse_createProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<CreateProgramInvocation_Response > (false, ConfirmedServiceResponse_createProgramInvocation), 38);
                break;
            }
            case ConfirmedServiceResponse_deleteProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteProgramInvocation_Response > (false, ConfirmedServiceResponse_deleteProgramInvocation), 39);
                break;
            }
            case ConfirmedServiceResponse_start:
            {
                ITU_T_IMPLICIT_TAG(*value<Start_Response > (false, ConfirmedServiceResponse_start), 40);
                break;
            }
            case ConfirmedServiceResponse_stop:
            {
                ITU_T_IMPLICIT_TAG(*value<Stop_Response > (false, ConfirmedServiceResponse_stop), 41);
                break;
            }
            case ConfirmedServiceResponse_resume:
            {
                ITU_T_IMPLICIT_TAG(*value<Resume_Response > (false, ConfirmedServiceResponse_resume), 42);
                break;
            }
            case ConfirmedServiceResponse_reset:
            {
                ITU_T_IMPLICIT_TAG(*value<Reset_Response > (false, ConfirmedServiceResponse_reset), 43);
                break;
            }
            case ConfirmedServiceResponse_kill:
            {
                ITU_T_IMPLICIT_TAG(*value<Kill_Response > (false, ConfirmedServiceResponse_kill), 44);
                break;
            }
            case ConfirmedServiceResponse_getProgramInvocationAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetProgramInvocationAttributes_Response > (false, ConfirmedServiceResponse_getProgramInvocationAttributes), 45);
                break;
            }
            case ConfirmedServiceResponse_obtainFile:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ObtainFile_Response > (false, ConfirmedServiceResponse_obtainFile), 46);
                break;
            }
            case ConfirmedServiceResponse_defineEventCondition:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventCondition_Response > (false, ConfirmedServiceResponse_defineEventCondition), 47);
                break;
            }
            case ConfirmedServiceResponse_deleteEventCondition:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteEventCondition_Response > (false, ConfirmedServiceResponse_deleteEventCondition), 48);
                break;
            }
            case ConfirmedServiceResponse_getEventConditionAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetEventConditionAttributes_Response > (false, ConfirmedServiceResponse_getEventConditionAttributes), 49);
                break;
            }
            case ConfirmedServiceResponse_reportEventConditionStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportEventConditionStatus_Response > (false, ConfirmedServiceResponse_reportEventConditionStatus), 50);
                break;
            }
            case ConfirmedServiceResponse_alterEventConditionMonitoring:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterEventConditionMonitoring_Response > (false, ConfirmedServiceResponse_alterEventConditionMonitoring), 51);
                break;
            }
            case ConfirmedServiceResponse_triggerEvent:
            {
                ITU_T_IMPLICIT_TAG(*value<TriggerEvent_Response > (false, ConfirmedServiceResponse_triggerEvent), 52);
                break;
            }
            case ConfirmedServiceResponse_defineEventAction:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventAction_Response > (false, ConfirmedServiceResponse_defineEventAction), 53);
                break;
            }
            case ConfirmedServiceResponse_deleteEventAction:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteEventAction_Response > (false, ConfirmedServiceResponse_deleteEventAction), 54);
                break;
            }
            case ConfirmedServiceResponse_getEventActionAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetEventActionAttributes_Response > (false, ConfirmedServiceResponse_getEventActionAttributes), 55);
                break;
            }
            case ConfirmedServiceResponse_reportEventActionStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportEventActionStatus_Response > (false, ConfirmedServiceResponse_reportEventActionStatus), 56);
                break;
            }
            case ConfirmedServiceResponse_defineEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventEnrollment_Response > (false, ConfirmedServiceResponse_defineEventEnrollment), 57);
                break;
            }
            case ConfirmedServiceResponse_deleteEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteEventEnrollment_Response > (false, ConfirmedServiceResponse_deleteEventEnrollment), 58);
                break;
            }
            case ConfirmedServiceResponse_alterEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterEventEnrollment_Response > (false, ConfirmedServiceResponse_alterEventEnrollment), 59);
                break;
            }
            case ConfirmedServiceResponse_reportEventEnrollmentStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportEventEnrollmentStatus_Response > (false, ConfirmedServiceResponse_reportEventEnrollmentStatus), 60);
                break;
            }
            case ConfirmedServiceResponse_getEventEnrollmentAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetEventEnrollmentAttributes_Response > (false, ConfirmedServiceResponse_getEventEnrollmentAttributes), 61);
                break;
            }
            case ConfirmedServiceResponse_acknowledgeEventNotification:
            {
                ITU_T_IMPLICIT_TAG(*value<AcknowledgeEventNotification_Response > (false, ConfirmedServiceResponse_acknowledgeEventNotification), 62);
                break;
            }
            case ConfirmedServiceResponse_getAlarmSummary:
            {
                ITU_T_IMPLICIT_TAG(*value<GetAlarmSummary_Response > (false, ConfirmedServiceResponse_getAlarmSummary), 63);
                break;
            }
            case ConfirmedServiceResponse_getAlarmEnrollmentSummary:
            {
                ITU_T_IMPLICIT_TAG(*value<GetAlarmEnrollmentSummary_Response > (false, ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64);
                break;
            }
            case ConfirmedServiceResponse_readJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<ReadJournal_Response > (false, ConfirmedServiceResponse_readJournal), 65);
                break;
            }
            case ConfirmedServiceResponse_writeJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<WriteJournal_Response > (false, ConfirmedServiceResponse_writeJournal), 66);
                break;
            }
            case ConfirmedServiceResponse_initializeJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<InitializeJournal_Response > (false, ConfirmedServiceResponse_initializeJournal), 67);
                break;
            }
            case ConfirmedServiceResponse_reportJournalStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportJournalStatus_Response > (false, ConfirmedServiceResponse_reportJournalStatus), 68);
                break;
            }
            case ConfirmedServiceResponse_createJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<CreateJournal_Response > (false, ConfirmedServiceResponse_createJournal), 69);
                break;
            }
            case ConfirmedServiceResponse_deleteJournal:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteJournal_Response > (false, ConfirmedServiceResponse_deleteJournal), 70);
                break;
            }
            case ConfirmedServiceResponse_getCapabilityList:
            {
                ITU_T_IMPLICIT_TAG(*value<GetCapabilityList_Response > (false, ConfirmedServiceResponse_getCapabilityList), 71);
                break;
            }
            case ConfirmedServiceResponse_fileOpen:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileOpen_Response > (false, ConfirmedServiceResponse_fileOpen), 72);
                break;
            }
            case ConfirmedServiceResponse_fileRead:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRead_Response > (false, ConfirmedServiceResponse_fileRead), 73);
                break;
            }
            case ConfirmedServiceResponse_fileClose:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileClose_Response > (false, ConfirmedServiceResponse_fileClose), 74);
                break;
            }
            case ConfirmedServiceResponse_fileRename:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRename_Response > (false, ConfirmedServiceResponse_fileRename), 75);
                break;
            }
            case ConfirmedServiceResponse_fileDelete:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDelete_Response > (false, ConfirmedServiceResponse_fileDelete), 76);
                break;
            }
            case ConfirmedServiceResponse_fileDirectory:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDirectory_Response > (false, ConfirmedServiceResponse_fileDirectory), 77);
                break;
            }
            case ConfirmedServiceResponse_additionalService:
            {
                ITU_T_CHOICE_TAG(*value<AdditionalService_Response > (false, ConfirmedServiceResponse_additionalService), 78);
                break;
            }
            case ConfirmedServiceResponse_getDataExchangeAttributes:
            {
                ITU_T_EXPLICIT_TAG(*value<GetDataExchangeAttributes_Response > (false, ConfirmedServiceResponse_getDataExchangeAttributes), 80);
                break;
            }
            case ConfirmedServiceResponse_exchangeData:
            {
                ITU_T_IMPLICIT_TAG(*value<ExchangeData_Response > (false, ConfirmedServiceResponse_exchangeData), 81);
                break;
            }
            case ConfirmedServiceResponse_defineAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineAccessControlList_Response > (false, ConfirmedServiceResponse_defineAccessControlList), 82);
                break;
            }
            case ConfirmedServiceResponse_getAccessControlListAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetAccessControlListAttributes_Response > (false, ConfirmedServiceResponse_getAccessControlListAttributes), 83);
                break;
            }
            case ConfirmedServiceResponse_reportAccessControlledObjects:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportAccessControlledObjects_Response > (false, ConfirmedServiceResponse_reportAccessControlledObjects), 84);
                break;
            }
            case ConfirmedServiceResponse_deleteAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteAccessControlList_Response > (false, ConfirmedServiceResponse_deleteAccessControlList), 85);
                break;
            }
            case ConfirmedServiceResponse_changeAccessControl:
            {
                ITU_T_IMPLICIT_TAG(*value<ChangeAccessControl_Response > (false, ConfirmedServiceResponse_changeAccessControl), 86);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Status_Response > (true, ConfirmedServiceResponse_status), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetNameList_Response > (true, ConfirmedServiceResponse_getNameList), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identify_Response > (true, ConfirmedServiceResponse_identify), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Rename_Response > (true, ConfirmedServiceResponse_rename), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Read_Response > (true, ConfirmedServiceResponse_read), 4)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetVariableAccessAttributes_Response > (true, ConfirmedServiceResponse_getVariableAccessAttributes), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineNamedVariable_Response > (true, ConfirmedServiceResponse_defineNamedVariable), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (true, ConfirmedServiceResponse_defineScatteredAccess), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (true, ConfirmedServiceResponse_getScatteredAccessAttributes), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteVariableAccess_Response > (true, ConfirmedServiceResponse_deleteVariableAccess), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineNamedVariableList_Response > (true, ConfirmedServiceResponse_defineNamedVariableList), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetNamedVariableListAttributes_Response > (true, ConfirmedServiceResponse_getNamedVariableListAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteNamedVariableList_Response > (true, ConfirmedServiceResponse_deleteNamedVariableList), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineNamedType_Response > (true, ConfirmedServiceResponse_defineNamedType), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetNamedTypeAttributes_Response > (true, ConfirmedServiceResponse_getNamedTypeAttributes), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteNamedType_Response > (true, ConfirmedServiceResponse_deleteNamedType), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Input_Response > (true, ConfirmedServiceResponse_input), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Output_Response > (true, ConfirmedServiceResponse_output), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_CHOICE_TAG(*value<TakeControl_Response > (true, ConfirmedServiceResponse_takeControl), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RelinquishControl_Response > (true, ConfirmedServiceResponse_relinquishControl), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineSemaphore_Response > (true, ConfirmedServiceResponse_defineSemaphore), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteSemaphore_Response > (true, ConfirmedServiceResponse_deleteSemaphore), 22)) return;
                        else free();
                        break;
                    }
                    case 23:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportSemaphoreStatus_Response > (true, ConfirmedServiceResponse_reportSemaphoreStatus), 23)) return;
                        else free();
                        break;
                    }
                    case 24:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportPoolSemaphoreStatus_Response > (true, ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24)) return;
                        else free();
                        break;
                    }
                    case 25:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportSemaphoreEntryStatus_Response > (true, ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25)) return;
                        else free();
                        break;
                    }
                    case 26:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitiateDownloadSequence_Response > (true, ConfirmedServiceResponse_initiateDownloadSequence), 26)) return;
                        else free();
                        break;
                    }
                    case 27:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DownloadSegment_Response > (true, ConfirmedServiceResponse_downloadSegment), 27)) return;
                        else free();
                        break;
                    }
                    case 28:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TerminateDownloadSequence_Response > (true, ConfirmedServiceResponse_terminateDownloadSequence), 28)) return;
                        else free();
                        break;
                    }
                    case 29:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitiateUploadSequence_Response > (true, ConfirmedServiceResponse_initiateUploadSequence), 29)) return;
                        else free();
                        break;
                    }
                    case 30:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UploadSegment_Response > (true, ConfirmedServiceResponse_uploadSegment), 30)) return;
                        else free();
                        break;
                    }
                    case 31:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TerminateUploadSequence_Response > (true, ConfirmedServiceResponse_terminateUploadSequence), 31)) return;
                        else free();
                        break;
                    }
                    case 32:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RequestDomainDownload_Response > (true, ConfirmedServiceResponse_requestDomainDownload), 32)) return;
                        else free();
                        break;
                    }
                    case 33:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RequestDomainUpload_Response > (true, ConfirmedServiceResponse_requestDomainUpload), 33)) return;
                        else free();
                        break;
                    }
                    case 34:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<LoadDomainContent_Response > (true, ConfirmedServiceResponse_loadDomainContent), 34)) return;
                        else free();
                        break;
                    }
                    case 35:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StoreDomainContent_Response > (true, ConfirmedServiceResponse_storeDomainContent), 35)) return;
                        else free();
                        break;
                    }
                    case 36:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteDomain_Response > (true, ConfirmedServiceResponse_deleteDomain), 36)) return;
                        else free();
                        break;
                    }
                    case 37:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetDomainAttributes_Response > (true, ConfirmedServiceResponse_getDomainAttributes), 37)) return;
                        else free();
                        break;
                    }
                    case 38:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CreateProgramInvocation_Response > (true, ConfirmedServiceResponse_createProgramInvocation), 38)) return;
                        else free();
                        break;
                    }
                    case 39:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteProgramInvocation_Response > (true, ConfirmedServiceResponse_deleteProgramInvocation), 39)) return;
                        else free();
                        break;
                    }
                    case 40:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Start_Response > (true, ConfirmedServiceResponse_start), 40)) return;
                        else free();
                        break;
                    }
                    case 41:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Stop_Response > (true, ConfirmedServiceResponse_stop), 41)) return;
                        else free();
                        break;
                    }
                    case 42:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Resume_Response > (true, ConfirmedServiceResponse_resume), 42)) return;
                        else free();
                        break;
                    }
                    case 43:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Reset_Response > (true, ConfirmedServiceResponse_reset), 43)) return;
                        else free();
                        break;
                    }
                    case 44:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Kill_Response > (true, ConfirmedServiceResponse_kill), 44)) return;
                        else free();
                        break;
                    }
                    case 45:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetProgramInvocationAttributes_Response > (true, ConfirmedServiceResponse_getProgramInvocationAttributes), 45)) return;
                        else free();
                        break;
                    }
                    case 46:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ObtainFile_Response > (true, ConfirmedServiceResponse_obtainFile), 46)) return;
                        else free();
                        break;
                    }
                    case 47:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventCondition_Response > (true, ConfirmedServiceResponse_defineEventCondition), 47)) return;
                        else free();
                        break;
                    }
                    case 48:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteEventCondition_Response > (true, ConfirmedServiceResponse_deleteEventCondition), 48)) return;
                        else free();
                        break;
                    }
                    case 49:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetEventConditionAttributes_Response > (true, ConfirmedServiceResponse_getEventConditionAttributes), 49)) return;
                        else free();
                        break;
                    }
                    case 50:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportEventConditionStatus_Response > (true, ConfirmedServiceResponse_reportEventConditionStatus), 50)) return;
                        else free();
                        break;
                    }
                    case 51:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterEventConditionMonitoring_Response > (true, ConfirmedServiceResponse_alterEventConditionMonitoring), 51)) return;
                        else free();
                        break;
                    }
                    case 52:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TriggerEvent_Response > (true, ConfirmedServiceResponse_triggerEvent), 52)) return;
                        else free();
                        break;
                    }
                    case 53:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventAction_Response > (true, ConfirmedServiceResponse_defineEventAction), 53)) return;
                        else free();
                        break;
                    }
                    case 54:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteEventAction_Response > (true, ConfirmedServiceResponse_deleteEventAction), 54)) return;
                        else free();
                        break;
                    }
                    case 55:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetEventActionAttributes_Response > (true, ConfirmedServiceResponse_getEventActionAttributes), 55)) return;
                        else free();
                        break;
                    }
                    case 56:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportEventActionStatus_Response > (true, ConfirmedServiceResponse_reportEventActionStatus), 56)) return;
                        else free();
                        break;
                    }
                    case 57:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventEnrollment_Response > (true, ConfirmedServiceResponse_defineEventEnrollment), 57)) return;
                        else free();
                        break;
                    }
                    case 58:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteEventEnrollment_Response > (true, ConfirmedServiceResponse_deleteEventEnrollment), 58)) return;
                        else free();
                        break;
                    }
                    case 59:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterEventEnrollment_Response > (true, ConfirmedServiceResponse_alterEventEnrollment), 59)) return;
                        else free();
                        break;
                    }
                    case 60:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportEventEnrollmentStatus_Response > (true, ConfirmedServiceResponse_reportEventEnrollmentStatus), 60)) return;
                        else free();
                        break;
                    }
                    case 61:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetEventEnrollmentAttributes_Response > (true, ConfirmedServiceResponse_getEventEnrollmentAttributes), 61)) return;
                        else free();
                        break;
                    }
                    case 62:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AcknowledgeEventNotification_Response > (true, ConfirmedServiceResponse_acknowledgeEventNotification), 62)) return;
                        else free();
                        break;
                    }
                    case 63:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetAlarmSummary_Response > (true, ConfirmedServiceResponse_getAlarmSummary), 63)) return;
                        else free();
                        break;
                    }
                    case 64:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetAlarmEnrollmentSummary_Response > (true, ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64)) return;
                        else free();
                        break;
                    }
                    case 65:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReadJournal_Response > (true, ConfirmedServiceResponse_readJournal), 65)) return;
                        else free();
                        break;
                    }
                    case 66:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<WriteJournal_Response > (true, ConfirmedServiceResponse_writeJournal), 66)) return;
                        else free();
                        break;
                    }
                    case 67:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitializeJournal_Response > (true, ConfirmedServiceResponse_initializeJournal), 67)) return;
                        else free();
                        break;
                    }
                    case 68:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportJournalStatus_Response > (true, ConfirmedServiceResponse_reportJournalStatus), 68)) return;
                        else free();
                        break;
                    }
                    case 69:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CreateJournal_Response > (true, ConfirmedServiceResponse_createJournal), 69)) return;
                        else free();
                        break;
                    }
                    case 70:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteJournal_Response > (true, ConfirmedServiceResponse_deleteJournal), 70)) return;
                        else free();
                        break;
                    }
                    case 71:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetCapabilityList_Response > (true, ConfirmedServiceResponse_getCapabilityList), 71)) return;
                        else free();
                        break;
                    }
                    case 72:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileOpen_Response > (true, ConfirmedServiceResponse_fileOpen), 72)) return;
                        else free();
                        break;
                    }
                    case 73:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRead_Response > (true, ConfirmedServiceResponse_fileRead), 73)) return;
                        else free();
                        break;
                    }
                    case 74:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileClose_Response > (true, ConfirmedServiceResponse_fileClose), 74)) return;
                        else free();
                        break;
                    }
                    case 75:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRename_Response > (true, ConfirmedServiceResponse_fileRename), 75)) return;
                        else free();
                        break;
                    }
                    case 76:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDelete_Response > (true, ConfirmedServiceResponse_fileDelete), 76)) return;
                        else free();
                        break;
                    }
                    case 77:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileDirectory_Response > (true, ConfirmedServiceResponse_fileDirectory), 77)) return;
                        else free();
                        break;
                    }
                    case 78:
                    {
                        if (ITU_T_CHOICE_TAG(*value<AdditionalService_Response > (true, ConfirmedServiceResponse_additionalService), 78)) return;
                        else free();
                        break;
                    }
                    case 80:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<GetDataExchangeAttributes_Response > (true, ConfirmedServiceResponse_getDataExchangeAttributes), 80)) return;
                        else free();
                        break;
                    }
                    case 81:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ExchangeData_Response > (true, ConfirmedServiceResponse_exchangeData), 81)) return;
                        else free();
                        break;
                    }
                    case 82:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineAccessControlList_Response > (true, ConfirmedServiceResponse_defineAccessControlList), 82)) return;
                        else free();
                        break;
                    }
                    case 83:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetAccessControlListAttributes_Response > (true, ConfirmedServiceResponse_getAccessControlListAttributes), 83)) return;
                        else free();
                        break;
                    }
                    case 84:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportAccessControlledObjects_Response > (true, ConfirmedServiceResponse_reportAccessControlledObjects), 84)) return;
                        else free();
                        break;
                    }
                    case 85:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteAccessControlList_Response > (true, ConfirmedServiceResponse_deleteAccessControlList), 85)) return;
                        else free();
                        break;
                    }
                    case 86:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ChangeAccessControl_Response > (true, ConfirmedServiceResponse_changeAccessControl), 86)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice AdditionalService-Response

    template<> void AdditionalService_Response::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Response_vMDStop:
            {
                ITU_T_IMPLICIT_TAG(*value<VMDStop_Response > (false, AdditionalService_Response_vMDStop), 0);
                break;
            }
            case AdditionalService_Response_vMDReset:
            {
                ITU_T_IMPLICIT_TAG(*value<VMDReset_Response > (false, AdditionalService_Response_vMDReset), 1);
                break;
            }
            case AdditionalService_Response_select:
            {
                ITU_T_IMPLICIT_TAG(*value<Select_Response > (false, AdditionalService_Response_select), 2);
                break;
            }
            case AdditionalService_Response_alterPI:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterProgramInvocationAttributes_Response > (false, AdditionalService_Response_alterPI), 3);
                break;
            }
            case AdditionalService_Response_initiateUCLoad:
            {
                ITU_T_IMPLICIT_TAG(*value<InitiateUnitControlLoad_Response > (false, AdditionalService_Response_initiateUCLoad), 4);
                break;
            }
            case AdditionalService_Response_uCLoad:
            {
                ITU_T_IMPLICIT_TAG(*value<UnitControlLoadSegment_Response > (false, AdditionalService_Response_uCLoad), 5);
                break;
            }
            case AdditionalService_Response_uCUpload:
            {
                ITU_T_IMPLICIT_TAG(*value<UnitControlUpload_Response > (false, AdditionalService_Response_uCUpload), 6);
                break;
            }
            case AdditionalService_Response_startUC:
            {
                ITU_T_IMPLICIT_TAG(*value<StartUnitControl_Response > (false, AdditionalService_Response_startUC), 7);
                break;
            }
            case AdditionalService_Response_stopUC:
            {
                ITU_T_IMPLICIT_TAG(*value<StopUnitControl_Response > (false, AdditionalService_Response_stopUC), 8);
                break;
            }
            case AdditionalService_Response_createUC:
            {
                ITU_T_IMPLICIT_TAG(*value<CreateUnitControl_Response > (false, AdditionalService_Response_createUC), 9);
                break;
            }
            case AdditionalService_Response_addToUC:
            {
                ITU_T_IMPLICIT_TAG(*value<AddToUnitControl_Response > (false, AdditionalService_Response_addToUC), 10);
                break;
            }
            case AdditionalService_Response_removeFromUC:
            {
                ITU_T_IMPLICIT_TAG(*value<RemoveFromUnitControl_Response > (false, AdditionalService_Response_removeFromUC), 11);
                break;
            }
            case AdditionalService_Response_getUCAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetUnitControlAttributes_Response > (false, AdditionalService_Response_getUCAttributes), 12);
                break;
            }
            case AdditionalService_Response_loadUCFromFile:
            {
                ITU_T_IMPLICIT_TAG(*value<LoadUnitControlFromFile_Response > (false, AdditionalService_Response_loadUCFromFile), 13);
                break;
            }
            case AdditionalService_Response_storeUCToFile:
            {
                ITU_T_IMPLICIT_TAG(*value<StoreUnitControlToFile_Response > (false, AdditionalService_Response_storeUCToFile), 14);
                break;
            }
            case AdditionalService_Response_deleteUC:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteUnitControl_Response > (false, AdditionalService_Response_deleteUC), 15);
                break;
            }
            case AdditionalService_Response_defineECL:
            {
                ITU_T_IMPLICIT_TAG(*value<DefineEventConditionList_Response > (false, AdditionalService_Response_defineECL), 16);
                break;
            }
            case AdditionalService_Response_deleteECL:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteEventConditionList_Response > (false, AdditionalService_Response_deleteECL), 17);
                break;
            }
            case AdditionalService_Response_addECLReference:
            {
                ITU_T_IMPLICIT_TAG(*value<AddEventConditionListReference_Response > (false, AdditionalService_Response_addECLReference), 18);
                break;
            }
            case AdditionalService_Response_removeECLReference:
            {
                ITU_T_IMPLICIT_TAG(*value<RemoveEventConditionListReference_Response > (false, AdditionalService_Response_removeECLReference), 19);
                break;
            }
            case AdditionalService_Response_getECLAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<GetEventConditionListAttributes_Response > (false, AdditionalService_Response_getECLAttributes), 20);
                break;
            }
            case AdditionalService_Response_reportECLStatus:
            {
                ITU_T_IMPLICIT_TAG(*value<ReportEventConditionListStatus_Response > (false, AdditionalService_Response_reportECLStatus), 21);
                break;
            }
            case AdditionalService_Response_alterECLMonitoring:
            {
                ITU_T_IMPLICIT_TAG(*value<AlterEventConditionListMonitoring_Response > (false, AdditionalService_Response_alterECLMonitoring), 22);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AdditionalService_Response::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<VMDStop_Response > (true, AdditionalService_Response_vMDStop), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<VMDReset_Response > (true, AdditionalService_Response_vMDReset), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Select_Response > (true, AdditionalService_Response_select), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterProgramInvocationAttributes_Response > (true, AdditionalService_Response_alterPI), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<InitiateUnitControlLoad_Response > (true, AdditionalService_Response_initiateUCLoad), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UnitControlLoadSegment_Response > (true, AdditionalService_Response_uCLoad), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<UnitControlUpload_Response > (true, AdditionalService_Response_uCUpload), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StartUnitControl_Response > (true, AdditionalService_Response_startUC), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StopUnitControl_Response > (true, AdditionalService_Response_stopUC), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CreateUnitControl_Response > (true, AdditionalService_Response_createUC), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AddToUnitControl_Response > (true, AdditionalService_Response_addToUC), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RemoveFromUnitControl_Response > (true, AdditionalService_Response_removeFromUC), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetUnitControlAttributes_Response > (true, AdditionalService_Response_getUCAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<LoadUnitControlFromFile_Response > (true, AdditionalService_Response_loadUCFromFile), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StoreUnitControlToFile_Response > (true, AdditionalService_Response_storeUCToFile), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteUnitControl_Response > (true, AdditionalService_Response_deleteUC), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DefineEventConditionList_Response > (true, AdditionalService_Response_defineECL), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteEventConditionList_Response > (true, AdditionalService_Response_deleteECL), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AddEventConditionListReference_Response > (true, AdditionalService_Response_addECLReference), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<RemoveEventConditionListReference_Response > (true, AdditionalService_Response_removeECLReference), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<GetEventConditionListAttributes_Response > (true, AdditionalService_Response_getECLAttributes), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ReportEventConditionListStatus_Response > (true, AdditionalService_Response_reportECLStatus), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<AlterEventConditionListMonitoring_Response > (true, AdditionalService_Response_alterECLMonitoring), 22)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice Response-Detail

    template<> void Response_Detail::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Response_Detail_otherRequests:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, Response_Detail_otherRequests));
                break;
            }
            case Response_Detail_status:
            {
                ITU_T_CHOICE_TAG(*value<CS_Status_Response > (false, Response_Detail_status), 0);
                break;
            }
            case Response_Detail_getProgramInvocationAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_GetProgramInvocationAttributes_Response > (false, Response_Detail_getProgramInvocationAttributes), 45);
                break;
            }
            case Response_Detail_getEventConditionAttributes:
            {
                ITU_T_IMPLICIT_TAG(*value<CS_GetEventConditionAttributes_Response > (false, Response_Detail_getEventConditionAttributes), 49);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Response_Detail::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<CS_Status_Response > (true, Response_Detail_status), 0)) return;
                        else free();
                        break;
                    }
                    case 45:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_GetProgramInvocationAttributes_Response > (true, Response_Detail_getProgramInvocationAttributes), 45)) return;
                        else free();
                        break;
                    }
                    case 49:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<CS_GetEventConditionAttributes_Response > (true, Response_Detail_getEventConditionAttributes), 49)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, Response_Detail_otherRequests))) return;
                else free();
            }
        }
    }

    // sequence Confirmed-ErrorPDU

    template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*invokeID_, 0);
        ITU_T_IMPLICIT_TAG(modifierPosition_, 1);
        ITU_T_IMPLICIT_TAG(*serviceError_, 2);
    }

    template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*invokeID_, 0);
        ITU_T_IMPLICIT_TAG(modifierPosition_, 1);
        ITU_T_IMPLICIT_TAG(*serviceError_, 2);
    }

    // sequence ServiceError

    template<> void ServiceError::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*errorClass_, 0);
        ITU_T_IMPLICIT_TAG(additionalCode_, 1);
        ITU_T_IMPLICIT_TAG(additionalDescription_, 2);
        ITU_T_CHOICE_TAG(serviceSpecificInfo_, 3);
    }

    template<> void ServiceError::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*errorClass_, 0);
        ITU_T_IMPLICIT_TAG(additionalCode_, 1);
        ITU_T_IMPLICIT_TAG(additionalDescription_, 2);
        ITU_T_CHOICE_TAG(serviceSpecificInfo_, 3);
    }

    // choice errorClass

    template<> void ServiceError::ErrorClass_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ErrorClass_type_vmd_state:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_vmd_state), 0);
                break;
            }
            case ErrorClass_type_application_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_application_reference), 1);
                break;
            }
            case ErrorClass_type_definition:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_definition), 2);
                break;
            }
            case ErrorClass_type_resource:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_resource), 3);
                break;
            }
            case ErrorClass_type_service:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_service), 4);
                break;
            }
            case ErrorClass_type_service_preempt:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_service_preempt), 5);
                break;
            }
            case ErrorClass_type_time_resolution:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_time_resolution), 6);
                break;
            }
            case ErrorClass_type_access:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_access), 7);
                break;
            }
            case ErrorClass_type_initiate:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_initiate), 8);
                break;
            }
            case ErrorClass_type_conclude:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_conclude), 9);
                break;
            }
            case ErrorClass_type_cancel:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_cancel), 10);
                break;
            }
            case ErrorClass_type_file:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ErrorClass_type_file), 11);
                break;
            }
            case ErrorClass_type_others:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, ErrorClass_type_others), 12);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ServiceError::ErrorClass_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_vmd_state), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_application_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_definition), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_resource), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_service), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_service_preempt), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_time_resolution), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_access), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_initiate), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_conclude), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_cancel), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ErrorClass_type_file), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, ErrorClass_type_others), 12)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice serviceSpecificInfo

    template<> void ServiceError::ServiceSpecificInfo_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ServiceSpecificInfo_type_obtainFile:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ObtainFile_Error > (false, ServiceSpecificInfo_type_obtainFile), 0);
                break;
            }
            case ServiceSpecificInfo_type_start:
            {
                ITU_T_IMPLICIT_TAG(*value<Start_Error > (false, ServiceSpecificInfo_type_start), 1);
                break;
            }
            case ServiceSpecificInfo_type_stop:
            {
                ITU_T_IMPLICIT_TAG(*value<Stop_Error > (false, ServiceSpecificInfo_type_stop), 2);
                break;
            }
            case ServiceSpecificInfo_type_resume:
            {
                ITU_T_IMPLICIT_TAG(*value<Resume_Error > (false, ServiceSpecificInfo_type_resume), 3);
                break;
            }
            case ServiceSpecificInfo_type_reset:
            {
                ITU_T_IMPLICIT_TAG(*value<Reset_Error > (false, ServiceSpecificInfo_type_reset), 4);
                break;
            }
            case ServiceSpecificInfo_type_deleteVariableAccess:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteVariableAccess_Error > (false, ServiceSpecificInfo_type_deleteVariableAccess), 5);
                break;
            }
            case ServiceSpecificInfo_type_deleteNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteNamedVariableList_Error > (false, ServiceSpecificInfo_type_deleteNamedVariableList), 6);
                break;
            }
            case ServiceSpecificInfo_type_deleteNamedType:
            {
                ITU_T_IMPLICIT_TAG(*value<DeleteNamedType_Error > (false, ServiceSpecificInfo_type_deleteNamedType), 7);
                break;
            }
            case ServiceSpecificInfo_type_defineEventEnrollment_Error:
            {
                ITU_T_CHOICE_TAG(*value<DefineEventEnrollment_Error > (false, ServiceSpecificInfo_type_defineEventEnrollment_Error), 8);
                break;
            }
            case ServiceSpecificInfo_type_fileRename:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRename_Error > (false, ServiceSpecificInfo_type_fileRename), 9);
                break;
            }
            case ServiceSpecificInfo_type_additionalService:
            {
                ITU_T_CHOICE_TAG(*value<AdditionalService_Error > (false, ServiceSpecificInfo_type_additionalService), 10);
                break;
            }
            case ServiceSpecificInfo_type_changeAccessControl:
            {
                ITU_T_IMPLICIT_TAG(*value<ChangeAccessControl_Error > (false, ServiceSpecificInfo_type_changeAccessControl), 11);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ServiceError::ServiceSpecificInfo_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ObtainFile_Error > (true, ServiceSpecificInfo_type_obtainFile), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Start_Error > (true, ServiceSpecificInfo_type_start), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Stop_Error > (true, ServiceSpecificInfo_type_stop), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Resume_Error > (true, ServiceSpecificInfo_type_resume), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Reset_Error > (true, ServiceSpecificInfo_type_reset), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteVariableAccess_Error > (true, ServiceSpecificInfo_type_deleteVariableAccess), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteNamedVariableList_Error > (true, ServiceSpecificInfo_type_deleteNamedVariableList), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DeleteNamedType_Error > (true, ServiceSpecificInfo_type_deleteNamedType), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DefineEventEnrollment_Error > (true, ServiceSpecificInfo_type_defineEventEnrollment_Error), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::FileRename_Error > (true, ServiceSpecificInfo_type_fileRename), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_CHOICE_TAG(*value<AdditionalService_Error > (true, ServiceSpecificInfo_type_additionalService), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ChangeAccessControl_Error > (true, ServiceSpecificInfo_type_changeAccessControl), 11)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice AdditionalService-Error

    template<> void AdditionalService_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Error_defineEcl:
            {
                ITU_T_CHOICE_TAG(*value<DefineEventConditionList_Error > (false, AdditionalService_Error_defineEcl), 0);
                break;
            }
            case AdditionalService_Error_addECLReference:
            {
                ITU_T_CHOICE_TAG(*value<AddEventConditionListReference_Error > (false, AdditionalService_Error_addECLReference), 1);
                break;
            }
            case AdditionalService_Error_removeECLReference:
            {
                ITU_T_CHOICE_TAG(*value<RemoveEventConditionListReference_Error > (false, AdditionalService_Error_removeECLReference), 2);
                break;
            }
            case AdditionalService_Error_initiateUC:
            {
                ITU_T_CHOICE_TAG(*value<InitiateUnitControl_Error > (false, AdditionalService_Error_initiateUC), 3);
                break;
            }
            case AdditionalService_Error_startUC:
            {
                ITU_T_IMPLICIT_TAG(*value<StartUnitControl_Error > (false, AdditionalService_Error_startUC), 4);
                break;
            }
            case AdditionalService_Error_stopUC:
            {
                ITU_T_IMPLICIT_TAG(*value<StopUnitControl_Error > (false, AdditionalService_Error_stopUC), 5);
                break;
            }
            case AdditionalService_Error_deleteUC:
            {
                ITU_T_CHOICE_TAG(*value<DeleteUnitControl_Error > (false, AdditionalService_Error_deleteUC), 6);
                break;
            }
            case AdditionalService_Error_loadUCFromFile:
            {
                ITU_T_CHOICE_TAG(*value<LoadUnitControlFromFile_Error > (false, AdditionalService_Error_loadUCFromFile), 7);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AdditionalService_Error::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DefineEventConditionList_Error > (true, AdditionalService_Error_defineEcl), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<AddEventConditionListReference_Error > (true, AdditionalService_Error_addECLReference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_CHOICE_TAG(*value<RemoveEventConditionListReference_Error > (true, AdditionalService_Error_removeECLReference), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_CHOICE_TAG(*value<InitiateUnitControl_Error > (true, AdditionalService_Error_initiateUC), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StartUnitControl_Error > (true, AdditionalService_Error_startUC), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<StopUnitControl_Error > (true, AdditionalService_Error_stopUC), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_CHOICE_TAG(*value<DeleteUnitControl_Error > (true, AdditionalService_Error_deleteUC), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_CHOICE_TAG(*value<LoadUnitControlFromFile_Error > (true, AdditionalService_Error_loadUCFromFile), 7)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice ObjectName

    template<> void ObjectName::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ObjectName_vmd_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ObjectName_vmd_specific), 0);
                break;
            }
            case ObjectName_domain_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Domain_specific_type > (false, ObjectName_domain_specific), 1);
                break;
            }
            case ObjectName_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ObjectName_aa_specific), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ObjectName::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ObjectName_vmd_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Domain_specific_type > (true, ObjectName_domain_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ObjectName_aa_specific), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence domain-specific

    template<> void ObjectName::Domain_specific_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*domainID_);
        ITU_T_BIND_TAG(*itemID_);
    }

    template<> void ObjectName::Domain_specific_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*domainID_);
        ITU_T_BIND_TAG(*itemID_);
    }

    // choice ObjectClass

    template<> void ObjectClass::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ObjectClass_basicObjectClass:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ObjectClass_basicObjectClass), 0);
                break;
            }
            case ObjectClass_csObjectClass:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, ObjectClass_csObjectClass), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ObjectClass::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ObjectClass_basicObjectClass), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, ObjectClass_csObjectClass), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence Initiate-RequestPDU

    template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalling_, 0);
        ITU_T_IMPLICIT_TAG(*proposedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(*proposedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(proposedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(*initRequestDetail_, 4);
    }

    template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalling_, 0);
        ITU_T_IMPLICIT_TAG(*proposedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(*proposedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(proposedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(*initRequestDetail_, 4);
    }

    // sequence initRequestDetail

    template<> void Initiate_RequestPDU::InitRequestDetail_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*proposedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(*proposedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(*servicesSupportedCalling_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalling_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalling_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalling_, 5);
    }

    template<> void Initiate_RequestPDU::InitRequestDetail_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*proposedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(*proposedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(*servicesSupportedCalling_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalling_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalling_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalling_, 5);
    }

    // sequence Initiate-ResponsePDU

    template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalled_, 0);
        ITU_T_IMPLICIT_TAG(*negotiatedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(*negotiatedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(negotiatedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(*initResponseDetail_, 4);
    }

    template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalled_, 0);
        ITU_T_IMPLICIT_TAG(*negotiatedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(*negotiatedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(negotiatedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(*initResponseDetail_, 4);
    }

    // sequence initResponseDetail

    template<> void Initiate_ResponsePDU::InitResponseDetail_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*negotiatedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(*negotiatedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(*servicesSupportedCalled_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalled_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalled_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalled_, 5);
    }

    template<> void Initiate_ResponsePDU::InitResponseDetail_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*negotiatedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(*negotiatedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(*servicesSupportedCalled_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalled_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalled_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalled_, 5);
    }

    // sequence Cancel-ErrorPDU

    template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*originalInvokeID_, 0);
        ITU_T_IMPLICIT_TAG(*serviceError_, 1);
    }

    template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*originalInvokeID_, 0);
        ITU_T_IMPLICIT_TAG(*serviceError_, 1);
    }

    // sequence RejectPDU

    template<> void RejectPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(originalInvokeID_, 0);
        ITU_T_BIND_CHOICE(*rejectReason_);
    }

    template<> void RejectPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(originalInvokeID_, 0);
        ITU_T_BIND_CHOICE(*rejectReason_);
    }

    // choice rejectReason

    template<> void RejectPDU::RejectReason_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RejectReason_type_confirmed_requestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_confirmed_requestPDU), 1);
                break;
            }
            case RejectReason_type_confirmed_responsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_confirmed_responsePDU), 2);
                break;
            }
            case RejectReason_type_confirmed_errorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_confirmed_errorPDU), 3);
                break;
            }
            case RejectReason_type_unconfirmedPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_unconfirmedPDU), 4);
                break;
            }
            case RejectReason_type_pdu_error:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, RejectReason_type_pdu_error), 5);
                break;
            }
            case RejectReason_type_cancel_requestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_cancel_requestPDU), 6);
                break;
            }
            case RejectReason_type_cancel_responsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_cancel_responsePDU), 7);
                break;
            }
            case RejectReason_type_cancel_errorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_cancel_errorPDU), 8);
                break;
            }
            case RejectReason_type_conclude_requestPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_conclude_requestPDU), 9);
                break;
            }
            case RejectReason_type_conclude_responsePDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_conclude_responsePDU), 10);
                break;
            }
            case RejectReason_type_conclude_errorPDU:
            {
                ITU_T_IMPLICIT_TAG(*value<uint8_t > (false, RejectReason_type_conclude_errorPDU), 11);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RejectPDU::RejectReason_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_confirmed_requestPDU), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_confirmed_responsePDU), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_confirmed_errorPDU), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_unconfirmedPDU), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, RejectReason_type_pdu_error), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_cancel_requestPDU), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_cancel_responsePDU), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_cancel_errorPDU), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_conclude_requestPDU), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_conclude_responsePDU), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<uint8_t > (true, RejectReason_type_conclude_errorPDU), 11)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence DefineAccessControlList-Request

    template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControlListName_, 0);
        ITU_T_IMPLICIT_TAG(*accessControlListElements_, 1);
    }

    template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControlListName_, 0);
        ITU_T_IMPLICIT_TAG(*accessControlListElements_, 1);
    }

    // sequence accessControlListElements

    template<> void DefineAccessControlList_Request::AccessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    template<> void DefineAccessControlList_Request::AccessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    // choice GetAccessControlListAttributes-Request

    template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case GetAccessControlListAttributes_Request_accessControlListName:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, GetAccessControlListAttributes_Request_accessControlListName), 0);
                break;
            }
            case GetAccessControlListAttributes_Request_vMD:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, GetAccessControlListAttributes_Request_vMD), 1);
                break;
            }
            case GetAccessControlListAttributes_Request_namedObject:
            {
                ITU_T_IMPLICIT_TAG(*value<NamedObject_type > (false, GetAccessControlListAttributes_Request_namedObject), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, GetAccessControlListAttributes_Request_accessControlListName), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, GetAccessControlListAttributes_Request_vMD), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<NamedObject_type > (true, GetAccessControlListAttributes_Request_namedObject), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence namedObject

    template<> void GetAccessControlListAttributes_Request::NamedObject_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*objectName_, 1);
    }

    template<> void GetAccessControlListAttributes_Request::NamedObject_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*objectName_, 1);
    }

    // sequence GetAccessControlListAttributes-Response

    template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*name_, 0);
        ITU_T_IMPLICIT_TAG(*accessControlListElements_, 1);
        ITU_T_IMPLICIT_TAG(*vMDuse_, 2);
        ITU_T_IMPLICIT_TAG(*references_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*name_, 0);
        ITU_T_IMPLICIT_TAG(*accessControlListElements_, 1);
        ITU_T_IMPLICIT_TAG(*vMDuse_, 2);
        ITU_T_IMPLICIT_TAG(*references_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    // sequence accessControlListElements

    template<> void GetAccessControlListAttributes_Response::AccessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    template<> void GetAccessControlListAttributes_Response::AccessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    // sequence 

    template<> void GetAccessControlListAttributes_Response::References_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_IMPLICIT_TAG(*objectCount_, 1);
    }

    template<> void GetAccessControlListAttributes_Response::References_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_IMPLICIT_TAG(*objectCount_, 1);
    }

    // sequence ReportAccessControlledObjects-Request

    template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControlList_, 0);
        ITU_T_CHOICE_TAG(*objectClass_, 1);
        ITU_T_CHOICE_TAG(continueAfter_, 2);
    }

    template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControlList_, 0);
        ITU_T_CHOICE_TAG(*objectClass_, 1);
        ITU_T_CHOICE_TAG(continueAfter_, 2);
    }

    // sequence ReportAccessControlledObjects-Response

    template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfNames_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfNames_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence ChangeAccessControl-Request

    template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*scopeOfChange_);
        ITU_T_IMPLICIT_TAG(*accessControlListName_, 2);
    }

    template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*scopeOfChange_);
        ITU_T_IMPLICIT_TAG(*accessControlListName_, 2);
    }

    // choice scopeOfChange

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ScopeOfChange_type_vMDOnly:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, ScopeOfChange_type_vMDOnly), 0);
                break;
            }
            case ScopeOfChange_type_listOfObjects:
            {
                ITU_T_IMPLICIT_TAG(*value<ListOfObjects_type > (false, ScopeOfChange_type_listOfObjects), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, ScopeOfChange_type_vMDOnly), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ListOfObjects_type > (true, ScopeOfChange_type_listOfObjects), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence listOfObjects

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*objectScope_, 1);
    }

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*objectScope_, 1);
    }

    // choice objectScope

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ObjectScope_type_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Specific_type > (false, ObjectScope_type_specific), 0);
                break;
            }
            case ObjectScope_type_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, ObjectScope_type_aa_specific), 1);
                break;
            }
            case ObjectScope_type_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ObjectScope_type_domain), 2);
                break;
            }
            case ObjectScope_type_vmd:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, ObjectScope_type_vmd), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Specific_type > (true, ObjectScope_type_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, ObjectScope_type_aa_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ObjectScope_type_domain), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, ObjectScope_type_vmd), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence ChangeAccessControl-Response

    template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberChanged_, 1);
    }

    template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberChanged_, 1);
    }

    // sequence StatusResponse

    template<> void StatusResponse::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*vmdLogicalStatus_, 0);
        ITU_T_IMPLICIT_TAG(*vmdPhysicalStatus_, 1);
        ITU_T_IMPLICIT_TAG(localDetail_, 2);
    }

    template<> void StatusResponse::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*vmdLogicalStatus_, 0);
        ITU_T_IMPLICIT_TAG(*vmdPhysicalStatus_, 1);
        ITU_T_IMPLICIT_TAG(localDetail_, 2);
    }

    // choice CS-Status-Response

    template<> void CS_Status_Response::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_Status_Response_fullResponse:
            {
                ITU_T_BIND_TAG(*value<FullResponse_type > (false, CS_Status_Response_fullResponse));
                break;
            }
            case CS_Status_Response_noExtraResponse:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, CS_Status_Response_noExtraResponse));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Status_Response::serialize(boost::asn1::x690::input_coder& arch) {

        if (ITU_T_BIND_TAG(*value<FullResponse_type > (true, CS_Status_Response_fullResponse))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<null_type > (true, CS_Status_Response_noExtraResponse))) return;
        else free();
    }

    // sequence fullResponse

    template<> void CS_Status_Response::FullResponse_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*operationState_, 0);
        ITU_T_IMPLICIT_TAG(*extendedStatus_, 1);
        ITU_T_IMPLICIT_TAG(extendedStatusMask_, 2);
        ITU_T_BIND_CHOICE(*selectedProgramInvocation_);
    }

    template<> void CS_Status_Response::FullResponse_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*operationState_, 0);
        ITU_T_IMPLICIT_TAG(*extendedStatus_, 1);
        ITU_T_IMPLICIT_TAG(extendedStatusMask_, 2);
        ITU_T_BIND_CHOICE(*selectedProgramInvocation_);
    }

    // choice selectedProgramInvocation

    template<> void CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case SelectedProgramInvocation_type_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, SelectedProgramInvocation_type_programInvocation), 3);
                break;
            }
            case SelectedProgramInvocation_type_noneSelected:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, SelectedProgramInvocation_type_noneSelected), 4);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, SelectedProgramInvocation_type_programInvocation), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, SelectedProgramInvocation_type_noneSelected), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetNameList-Request

    template<> void GetNameList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*objectScope_, 1);
        ITU_T_IMPLICIT_TAG(continueAfter_, 2);
    }

    template<> void GetNameList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*objectScope_, 1);
        ITU_T_IMPLICIT_TAG(continueAfter_, 2);
    }

    // choice objectScope

    template<> void GetNameList_Request::ObjectScope_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ObjectScope_type_vmdSpecific:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, ObjectScope_type_vmdSpecific), 0);
                break;
            }
            case ObjectScope_type_domainSpecific:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ObjectScope_type_domainSpecific), 1);
                break;
            }
            case ObjectScope_type_aaSpecific:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, ObjectScope_type_aaSpecific), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetNameList_Request::ObjectScope_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, ObjectScope_type_vmdSpecific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ObjectScope_type_domainSpecific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, ObjectScope_type_aaSpecific), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetNameList-Response

    template<> void GetNameList_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfIdentifier_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetNameList_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfIdentifier_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence Identify-Response

    template<> void Identify_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*vendorName_, 0);
        ITU_T_IMPLICIT_TAG(*modelName_, 1);
        ITU_T_IMPLICIT_TAG(*revision_, 2);
        ITU_T_IMPLICIT_TAG(listOfAbstractSyntaxes_, 3);
    }

    template<> void Identify_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*vendorName_, 0);
        ITU_T_IMPLICIT_TAG(*modelName_, 1);
        ITU_T_IMPLICIT_TAG(*revision_, 2);
        ITU_T_IMPLICIT_TAG(listOfAbstractSyntaxes_, 3);
    }

    // sequence Rename-Request

    template<> void Rename_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*currentName_, 1);
        ITU_T_IMPLICIT_TAG(*newIdentifier_, 2);
    }

    template<> void Rename_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*objectClass_, 0);
        ITU_T_CHOICE_TAG(*currentName_, 1);
        ITU_T_IMPLICIT_TAG(*newIdentifier_, 2);
    }

    // sequence GetCapabilityList-Request

    template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(continueAfter_);
    }

    template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(continueAfter_);
    }

    // sequence GetCapabilityList-Response

    template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence InitiateDownloadSequence-Request

    template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(*sharable_, 2);
    }

    template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(*sharable_, 2);
    }

    // sequence DownloadSegment-Response

    template<> void DownloadSegment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void DownloadSegment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // choice LoadData

    template<> void LoadData::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case LoadData_non_coded:
            {
                ITU_T_IMPLICIT_TAG(*value<octetstring_type > (false, LoadData_non_coded), 0);
                break;
            }
            case LoadData_coded:
            {
                ITU_T_BIND_TAG(*value<external_type > (false, LoadData_coded));
                break;
            }
            case LoadData_embedded:
            {
                ITU_T_BIND_TAG(*value<embeded_type > (false, LoadData_embedded));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void LoadData::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<octetstring_type > (true, LoadData_non_coded), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<external_type > (true, LoadData_coded))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<embeded_type > (true, LoadData_embedded))) return;
                else free();
            }
        }
    }

    // sequence TerminateDownloadSequence-Request

    template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(discard_, 1);
    }

    template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(discard_, 1);
    }

    // sequence InitiateUploadSequence-Response

    template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*ulsmID_, 0);
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 1);
    }

    template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*ulsmID_, 0);
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 1);
    }

    // sequence UploadSegment-Response

    template<> void UploadSegment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void UploadSegment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence RequestDomainDownload-Request

    template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(*sharable_, 2);
        ITU_T_IMPLICIT_TAG(*fileName_, 4);
    }

    template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(*sharable_, 2);
        ITU_T_IMPLICIT_TAG(*fileName_, 4);
    }

    // sequence RequestDomainUpload-Request

    template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
    }

    template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
    }

    // sequence LoadDomainContent-Request

    template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(*sharable_, 2);
        ITU_T_IMPLICIT_TAG(*fileName_, 4);
        ITU_T_IMPLICIT_TAG(thirdParty_, 5);
    }

    template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(*sharable_, 2);
        ITU_T_IMPLICIT_TAG(*fileName_, 4);
        ITU_T_IMPLICIT_TAG(thirdParty_, 5);
    }

    // sequence StoreDomainContent-Request

    template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    // sequence GetDomainAttributes-Response

    template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(*state_, 1);
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(*sharable_, 3);
        ITU_T_IMPLICIT_TAG(*listOfProgramInvocations_, 4);
        ITU_T_IMPLICIT_TAG(*uploadInProgress_, 5);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(*state_, 1);
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(*sharable_, 3);
        ITU_T_IMPLICIT_TAG(*listOfProgramInvocations_, 4);
        ITU_T_IMPLICIT_TAG(*uploadInProgress_, 5);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    // sequence CreateProgramInvocation-Request

    template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
    }

    template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
    }

    // sequence Start-Request

    template<> void Start_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    template<> void Start_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    // choice executionArgument

    template<> void Start_Request::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(*value<MMSString > (false, ExecutionArgument_type_simpleString), 1);
                break;
            }
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_embeddedString:
            {
                ITU_T_BIND_TAG(*value<embeded_type > (false, ExecutionArgument_type_embeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Start_Request::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMSString > (true, ExecutionArgument_type_simpleString), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<external_type > (true, ExecutionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<embeded_type > (true, ExecutionArgument_type_embeddedString))) return;
                else free();
            }
        }
    }

    // choice CS-Start-Request

    template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_Start_Request_impl_normal:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, CS_Start_Request_impl_normal));
                break;
            }
            case CS_Start_Request_impl_controlling:
            {
                ITU_T_BIND_TAG(*value<Controlling_type > (false, CS_Start_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::input_coder& arch) {

        if (ITU_T_BIND_TAG(*value<null_type > (true, CS_Start_Request_impl_normal))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<Controlling_type > (true, CS_Start_Request_impl_controlling))) return;
        else free();
    }

    // sequence controlling

    template<> void CS_Start_Request_impl::Controlling_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(startLocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    template<> void CS_Start_Request_impl::Controlling_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(startLocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    // choice StartCount

    template<> void StartCount::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case StartCount_noLimit:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, StartCount_noLimit), 0);
                break;
            }
            case StartCount_cycleCount:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, StartCount_cycleCount), 1);
                break;
            }
            case StartCount_stepCount:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, StartCount_stepCount), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void StartCount::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, StartCount_noLimit), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, StartCount_cycleCount), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, StartCount_stepCount), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence Stop-Request

    template<> void Stop_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
    }

    template<> void Stop_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
    }

    // sequence Resume-Request

    template<> void Resume_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    template<> void Resume_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    // choice executionArgument

    template<> void Resume_Request::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(*value<MMSString > (false, ExecutionArgument_type_simpleString), 1);
                break;
            }
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_enmbeddedString:
            {
                ITU_T_BIND_TAG(*value<embeded_type > (false, ExecutionArgument_type_enmbeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Resume_Request::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMSString > (true, ExecutionArgument_type_simpleString), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<external_type > (true, ExecutionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<embeded_type > (true, ExecutionArgument_type_enmbeddedString))) return;
                else free();
            }
        }
    }

    // choice CS-Resume-Request

    template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_Resume_Request_impl_normal:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, CS_Resume_Request_impl_normal));
                break;
            }
            case CS_Resume_Request_impl_controlling:
            {
                ITU_T_BIND_TAG(*value<Controlling_type > (false, CS_Resume_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::input_coder& arch) {

        if (ITU_T_BIND_TAG(*value<null_type > (true, CS_Resume_Request_impl_normal))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<Controlling_type > (true, CS_Resume_Request_impl_controlling))) return;
        else free();
    }

    // sequence controlling

    template<> void CS_Resume_Request_impl::Controlling_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*modeType_);
    }

    template<> void CS_Resume_Request_impl::Controlling_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*modeType_);
    }

    // choice modeType

    template<> void CS_Resume_Request_impl::Controlling_type::ModeType_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ModeType_type_continueMode:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, ModeType_type_continueMode), 0);
                break;
            }
            case ModeType_type_changeMode:
            {
                ITU_T_CHOICE_TAG(*value<StartCount > (false, ModeType_type_changeMode), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Resume_Request_impl::Controlling_type::ModeType_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, ModeType_type_continueMode), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<StartCount > (true, ModeType_type_changeMode), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence Reset-Request

    template<> void Reset_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
    }

    template<> void Reset_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
    }

    // sequence Kill-Request

    template<> void Kill_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
    }

    template<> void Kill_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
    }

    // sequence GetProgramInvocationAttributes-Response

    template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*state_, 0);
        ITU_T_IMPLICIT_TAG(*listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(*reusable_, 3);
        ITU_T_IMPLICIT_TAG(*monitor_, 4);
        ITU_T_BIND_CHOICE(*executionArgument_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*state_, 0);
        ITU_T_IMPLICIT_TAG(*listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(*reusable_, 3);
        ITU_T_IMPLICIT_TAG(*monitor_, 4);
        ITU_T_BIND_CHOICE(*executionArgument_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    // choice executionArgument

    template<> void GetProgramInvocationAttributes_Response::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(*value<MMSString > (false, ExecutionArgument_type_simpleString), 5);
                break;
            }
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_enmbeddedString:
            {
                ITU_T_BIND_TAG(*value<embeded_type > (false, ExecutionArgument_type_enmbeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetProgramInvocationAttributes_Response::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMSString > (true, ExecutionArgument_type_simpleString), 5)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<external_type > (true, ExecutionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<embeded_type > (true, ExecutionArgument_type_enmbeddedString))) return;
                else free();
            }
        }
    }

    // sequence CS-GetProgramInvocationAttributes-Response

    template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*errorCode_, 0);
        ITU_T_CHOICE_TAG(*control_, 1);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*errorCode_, 0);
        ITU_T_CHOICE_TAG(*control_, 1);
    }

    // choice control

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Control_type_controlling:
            {
                ITU_T_IMPLICIT_TAG(*value<Controlling_type > (false, Control_type_controlling), 0);
                break;
            }
            case Control_type_controlled:
            {
                ITU_T_CHOICE_TAG(*value<Controlled_type > (false, Control_type_controlled), 1);
                break;
            }
            case Control_type_normal:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, Control_type_normal), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Controlling_type > (true, Control_type_controlling), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<Controlled_type > (true, Control_type_controlled), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, Control_type_normal), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence controlling

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*controlledPI_, 0);
        ITU_T_IMPLICIT_TAG(programLocation_, 1);
        ITU_T_CHOICE_TAG(*runningMode_, 2);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*controlledPI_, 0);
        ITU_T_IMPLICIT_TAG(programLocation_, 1);
        ITU_T_CHOICE_TAG(*runningMode_, 2);
    }

    // choice runningMode

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RunningMode_type_freeRunning:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, RunningMode_type_freeRunning), 0);
                break;
            }
            case RunningMode_type_cycleLimited:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, RunningMode_type_cycleLimited), 1);
                break;
            }
            case RunningMode_type_stepLimited:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, RunningMode_type_stepLimited), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, RunningMode_type_freeRunning), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, RunningMode_type_cycleLimited), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, RunningMode_type_stepLimited), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice controlled

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Controlled_type_controllingPI:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, Controlled_type_controllingPI), 0);
                break;
            }
            case Controlled_type_none:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, Controlled_type_none), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, Controlled_type_controllingPI), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, Controlled_type_none), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence Select-Request

    template<> void Select_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlling_, 0);
        ITU_T_IMPLICIT_TAG(controlled_, 1);
    }

    template<> void Select_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlling_, 0);
        ITU_T_IMPLICIT_TAG(controlled_, 1);
    }

    // sequence AlterProgramInvocationAttributes-Request

    template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    // sequence ReconfigureProgramInvocation-Request

    template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*oldProgramInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(newProgramInvocationName_, 1);
        ITU_T_IMPLICIT_TAG(*domainsToAdd_, 2);
        ITU_T_IMPLICIT_TAG(*domainsToRemove_, 3);
    }

    template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*oldProgramInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(newProgramInvocationName_, 1);
        ITU_T_IMPLICIT_TAG(*domainsToAdd_, 2);
        ITU_T_IMPLICIT_TAG(*domainsToRemove_, 3);
    }

    // choice ControlElement

    template<> void ControlElement::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ControlElement_beginDomainDef:
            {
                ITU_T_EXPLICIT_TAG(*value<BeginDomainDef_type > (false, ControlElement_beginDomainDef), 0);
                break;
            }
            case ControlElement_continueDomainDef:
            {
                ITU_T_EXPLICIT_TAG(*value<ContinueDomainDef_type > (false, ControlElement_continueDomainDef), 1);
                break;
            }
            case ControlElement_endDomainDef:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ControlElement_endDomainDef), 2);
                break;
            }
            case ControlElement_piDefinition:
            {
                ITU_T_IMPLICIT_TAG(*value<PiDefinition_type > (false, ControlElement_piDefinition), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ControlElement::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<BeginDomainDef_type > (true, ControlElement_beginDomainDef), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<ContinueDomainDef_type > (true, ControlElement_continueDomainDef), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ControlElement_endDomainDef), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<PiDefinition_type > (true, ControlElement_piDefinition), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence beginDomainDef

    template<> void ControlElement::BeginDomainDef_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 1);
        ITU_T_IMPLICIT_TAG(*capabilities_, 2);
        ITU_T_IMPLICIT_TAG(*sharable_, 3);
        ITU_T_CHOICE_TAG(loadData_, 4);
    }

    template<> void ControlElement::BeginDomainDef_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 1);
        ITU_T_IMPLICIT_TAG(*capabilities_, 2);
        ITU_T_IMPLICIT_TAG(*sharable_, 3);
        ITU_T_CHOICE_TAG(loadData_, 4);
    }

    // sequence continueDomainDef

    template<> void ControlElement::ContinueDomainDef_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 1);
        ITU_T_CHOICE_TAG(*loadData_, 3);
    }

    template<> void ControlElement::ContinueDomainDef_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domainName_, 1);
        ITU_T_CHOICE_TAG(*loadData_, 3);
    }

    // sequence piDefinition

    template<> void ControlElement::PiDefinition_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*piName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfDomains_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
        ITU_T_IMPLICIT_TAG(pIState_, 4);
    }

    template<> void ControlElement::PiDefinition_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*piName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfDomains_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
        ITU_T_IMPLICIT_TAG(pIState_, 4);
    }

    // choice InitiateUnitControl-Error

    template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case InitiateUnitControl_Error_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, InitiateUnitControl_Error_domain), 0);
                break;
            }
            case InitiateUnitControl_Error_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, InitiateUnitControl_Error_programInvocation), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, InitiateUnitControl_Error_domain), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, InitiateUnitControl_Error_programInvocation), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence UnitControlLoadSegment-Response

    template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*controlElements_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*controlElements_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence UnitControlUpload-Request

    template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_BIND_CHOICE(continueAfter_);
    }

    template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_BIND_CHOICE(continueAfter_);
    }

    // choice continueAfter

    template<> void UnitControlUpload_Request::ContinueAfter_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ContinueAfter_type_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ContinueAfter_type_domain), 1);
                break;
            }
            case ContinueAfter_type_ulsmID:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, ContinueAfter_type_ulsmID), 2);
                break;
            }
            case ContinueAfter_type_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ContinueAfter_type_programInvocation), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnitControlUpload_Request::ContinueAfter_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ContinueAfter_type_domain), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, ContinueAfter_type_ulsmID), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ContinueAfter_type_programInvocation), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence UnitControlUpload-Response

    template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*controlElements_, 0);
        ITU_T_BIND_CHOICE(nextElement_);
    }

    template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*controlElements_, 0);
        ITU_T_BIND_CHOICE(nextElement_);
    }

    // choice nextElement

    template<> void UnitControlUpload_Response::NextElement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case NextElement_type_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, NextElement_type_domain), 1);
                break;
            }
            case NextElement_type_ulsmID:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, NextElement_type_ulsmID), 2);
                break;
            }
            case NextElement_type_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, NextElement_type_programInvocation), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnitControlUpload_Response::NextElement_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, NextElement_type_domain), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, NextElement_type_ulsmID), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, NextElement_type_programInvocation), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence StartUnitControl-Request

    template<> void StartUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    template<> void StartUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    // choice executionArgument

    template<> void StartUnitControl_Request::ExecutionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(*value<MMSString > (false, ExecutionArgument_type_simpleString), 1);
                break;
            }
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_enmbeddedString:
            {
                ITU_T_BIND_TAG(*value<embeded_type > (false, ExecutionArgument_type_enmbeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void StartUnitControl_Request::ExecutionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMSString > (true, ExecutionArgument_type_simpleString), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<external_type > (true, ExecutionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<embeded_type > (true, ExecutionArgument_type_enmbeddedString))) return;
                else free();
            }
        }
    }

    // sequence StartUnitControl-Error

    template<> void StartUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(*programInvocationState_, 1);
    }

    template<> void StartUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(*programInvocationState_, 1);
    }

    // sequence StopUnitControl-Error

    template<> void StopUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(*programInvocationState_, 1);
    }

    template<> void StopUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(*programInvocationState_, 1);
    }

    // sequence CreateUnitControl-Request

    template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControl_, 0);
        ITU_T_IMPLICIT_TAG(*domains_, 1);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 2);
    }

    template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControl_, 0);
        ITU_T_IMPLICIT_TAG(*domains_, 1);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 2);
    }

    // sequence AddToUnitControl-Request

    template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControl_, 0);
        ITU_T_IMPLICIT_TAG(*domains_, 1);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 2);
    }

    template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControl_, 0);
        ITU_T_IMPLICIT_TAG(*domains_, 1);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 2);
    }

    // sequence RemoveFromUnitControl-Request

    template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControl_, 0);
        ITU_T_IMPLICIT_TAG(*domains_, 1);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 2);
    }

    template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControl_, 0);
        ITU_T_IMPLICIT_TAG(*domains_, 1);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 2);
    }

    // sequence GetUnitControlAttributes-Response

    template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domains_, 0);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 1);
    }

    template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*domains_, 0);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 1);
    }

    // sequence LoadUnitControlFromFile-Request

    template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    // choice LoadUnitControlFromFile-Error

    template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case LoadUnitControlFromFile_Error_none:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, LoadUnitControlFromFile_Error_none), 0);
                break;
            }
            case LoadUnitControlFromFile_Error_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, LoadUnitControlFromFile_Error_domain), 1);
                break;
            }
            case LoadUnitControlFromFile_Error_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, LoadUnitControlFromFile_Error_programInvocation), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, LoadUnitControlFromFile_Error_none), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, LoadUnitControlFromFile_Error_domain), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, LoadUnitControlFromFile_Error_programInvocation), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence StoreUnitControlToFile-Request

    template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(*fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    // choice DeleteUnitControl-Error

    template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteUnitControl_Error_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, DeleteUnitControl_Error_domain), 0);
                break;
            }
            case DeleteUnitControl_Error_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, DeleteUnitControl_Error_programInvocation), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, DeleteUnitControl_Error_domain), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, DeleteUnitControl_Error_programInvocation), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice TypeSpecification

    template<> void TypeSpecification::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case TypeSpecification_typeName:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, TypeSpecification_typeName), 0);
                break;
            }
            case TypeSpecification_typeDescription:
            {
                ITU_T_BIND_CHOICE(*value<MMS_Object_Module_1::TypeDescription > (false, TypeSpecification_typeDescription));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void TypeSpecification::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, TypeSpecification_typeName), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(*value<MMS_Object_Module_1::TypeDescription > (true, TypeSpecification_typeDescription))) return;
                else free();
            }
        }
    }

    // choice 

    template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AlternateAccess_sequence_of_unnamed:
            {
                ITU_T_BIND_CHOICE(*value<AlternateAccessSelection > (false, AlternateAccess_sequence_of_unnamed));
                break;
            }
            case AlternateAccess_sequence_of_named:
            {
                ITU_T_IMPLICIT_TAG(*value<Named_type > (false, AlternateAccess_sequence_of_named), 5);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Named_type > (true, AlternateAccess_sequence_of_named), 5)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(*value<AlternateAccessSelection > (true, AlternateAccess_sequence_of_unnamed))) return;
                else free();
            }
        }
    }

    // sequence named

    template<> void AlternateAccess_sequence_of::Named_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*componentName_, 0);
        ITU_T_BIND_CHOICE(*access_);
    }

    template<> void AlternateAccess_sequence_of::Named_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*componentName_, 0);
        ITU_T_BIND_CHOICE(*access_);
    }

    // choice AlternateAccessSelection

    template<> void AlternateAccessSelection::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AlternateAccessSelection_selectAlternateAccess:
            {
                ITU_T_IMPLICIT_TAG(*value<SelectAlternateAccess_type > (false, AlternateAccessSelection_selectAlternateAccess), 0);
                break;
            }
            case AlternateAccessSelection_selectAccess:
            {
                ITU_T_BIND_CHOICE(*value<SelectAccess_type > (false, AlternateAccessSelection_selectAccess));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<SelectAlternateAccess_type > (true, AlternateAccessSelection_selectAlternateAccess), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(*value<SelectAccess_type > (true, AlternateAccessSelection_selectAccess))) return;
                else free();
            }
        }
    }

    // sequence selectAlternateAccess

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*accessSelection_);
        ITU_T_BIND_TAG(*alternateAccess_);
    }

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*accessSelection_);
        ITU_T_BIND_TAG(*alternateAccess_);
    }

    // choice accessSelection

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AccessSelection_type_component:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, AccessSelection_type_component), 0);
                break;
            }
            case AccessSelection_type_index:
            {
                ITU_T_IMPLICIT_TAG(*value<Unsigned32 > (false, AccessSelection_type_index), 1);
                break;
            }
            case AccessSelection_type_indexRange:
            {
                ITU_T_IMPLICIT_TAG(*value<IndexRange_type > (false, AccessSelection_type_indexRange), 2);
                break;
            }
            case AccessSelection_type_allElements:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, AccessSelection_type_allElements), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, AccessSelection_type_component), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Unsigned32 > (true, AccessSelection_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<IndexRange_type > (true, AccessSelection_type_indexRange), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, AccessSelection_type_allElements), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence indexRange

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfElements_, 1);
    }

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfElements_, 1);
    }

    // choice selectAccess

    template<> void AlternateAccessSelection::SelectAccess_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case SelectAccess_type_component:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, SelectAccess_type_component), 1);
                break;
            }
            case SelectAccess_type_index:
            {
                ITU_T_IMPLICIT_TAG(*value<Unsigned32 > (false, SelectAccess_type_index), 2);
                break;
            }
            case SelectAccess_type_indexRange:
            {
                ITU_T_IMPLICIT_TAG(*value<IndexRange_type > (false, SelectAccess_type_indexRange), 3);
                break;
            }
            case SelectAccess_type_allElements:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, SelectAccess_type_allElements), 4);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::SelectAccess_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, SelectAccess_type_component), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Unsigned32 > (true, SelectAccess_type_index), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<IndexRange_type > (true, SelectAccess_type_indexRange), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, SelectAccess_type_allElements), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence indexRange

    template<> void AlternateAccessSelection::SelectAccess_type::IndexRange_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfElements_, 1);
    }

    template<> void AlternateAccessSelection::SelectAccess_type::IndexRange_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfElements_, 1);
    }

    // choice AccessResult

    template<> void AccessResult::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AccessResult_failure:
            {
                ITU_T_IMPLICIT_TAG(*value<DataAccessError > (false, AccessResult_failure), 0);
                break;
            }
            case AccessResult_success:
            {
                ITU_T_BIND_CHOICE(*value<Data > (false, AccessResult_success));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessResult::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DataAccessError > (true, AccessResult_failure), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(*value<Data > (true, AccessResult_success))) return;
                else free();
            }
        }
    }

    // choice Data

    template<> void Data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Data_array:
            {
                ITU_T_IMPLICIT_TAG(*value<Array_type > (false, Data_array), 1);
                break;
            }
            case Data_structure:
            {
                ITU_T_IMPLICIT_TAG(*value<Structure_type > (false, Data_structure), 2);
                break;
            }
            case Data_boolean:
            {
                ITU_T_IMPLICIT_TAG(*value<bool > (false, Data_boolean), 3);
                break;
            }
            case Data_bit_string:
            {
                ITU_T_IMPLICIT_TAG(*value<bitstring_type > (false, Data_bit_string), 4);
                break;
            }
            case Data_integer:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, Data_integer), 5);
                break;
            }
            case Data_unsignedV:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, Data_unsignedV), 6);
                break;
            }
            case Data_floating_point:
            {
                ITU_T_IMPLICIT_TAG(*value<FloatingPoint > (false, Data_floating_point), 7);
                break;
            }
            case Data_octet_string:
            {
                ITU_T_IMPLICIT_TAG(*value<octetstring_type > (false, Data_octet_string), 9);
                break;
            }
            case Data_visible_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, Data_visible_string), 10);
                break;
            }
            case Data_generalized_time:
            {
                ITU_T_IMPLICIT_TAG(*value<gentime_type > (false, Data_generalized_time), 11);
                break;
            }
            case Data_binary_time:
            {
                ITU_T_IMPLICIT_TAG(*value<TimeOfDay > (false, Data_binary_time), 12);
                break;
            }
            case Data_bcd:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, Data_bcd), 13);
                break;
            }
            case Data_booleanArray:
            {
                ITU_T_IMPLICIT_TAG(*value<bitstring_type > (false, Data_booleanArray), 14);
                break;
            }
            case Data_objId:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Data_objId), 15);
                break;
            }
            case Data_mMSString:
            {
                ITU_T_IMPLICIT_TAG(*value<MMSString > (false, Data_mMSString), 16);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Data::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Array_type > (true, Data_array), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Structure_type > (true, Data_structure), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<bool > (true, Data_boolean), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<bitstring_type > (true, Data_bit_string), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, Data_integer), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, Data_unsignedV), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<FloatingPoint > (true, Data_floating_point), 7)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<octetstring_type > (true, Data_octet_string), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, Data_visible_string), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<gentime_type > (true, Data_generalized_time), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TimeOfDay > (true, Data_binary_time), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, Data_bcd), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<bitstring_type > (true, Data_booleanArray), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Data_objId), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMSString > (true, Data_mMSString), 16)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice VariableAccessSpecification

    template<> void VariableAccessSpecification::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case VariableAccessSpecification_listOfVariable:
            {
                ITU_T_IMPLICIT_TAG(*value<ListOfVariable_type > (false, VariableAccessSpecification_listOfVariable), 0);
                break;
            }
            case VariableAccessSpecification_variableListName:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, VariableAccessSpecification_variableListName), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void VariableAccessSpecification::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ListOfVariable_type > (true, VariableAccessSpecification_listOfVariable), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, VariableAccessSpecification_variableListName), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence 

    template<> void VariableAccessSpecification::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    template<> void VariableAccessSpecification::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    // choice VariableSpecification

    template<> void VariableSpecification::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case VariableSpecification_name:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, VariableSpecification_name), 0);
                break;
            }
            case VariableSpecification_address:
            {
                ITU_T_CHOICE_TAG(*value<MMS_Object_Module_1::Address > (false, VariableSpecification_address), 1);
                break;
            }
            case VariableSpecification_variableDescription:
            {
                ITU_T_IMPLICIT_TAG(*value<VariableDescription_type > (false, VariableSpecification_variableDescription), 2);
                break;
            }
            case VariableSpecification_scatteredAccessDescription:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ScatteredAccessDescription > (false, VariableSpecification_scatteredAccessDescription), 3);
                break;
            }
            case VariableSpecification_invalidated:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, VariableSpecification_invalidated), 4);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void VariableSpecification::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, VariableSpecification_name), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<MMS_Object_Module_1::Address > (true, VariableSpecification_address), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<VariableDescription_type > (true, VariableSpecification_variableDescription), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1A::ScatteredAccessDescription > (true, VariableSpecification_scatteredAccessDescription), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, VariableSpecification_invalidated), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence variableDescription

    template<> void VariableSpecification::VariableDescription_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*address_);
        ITU_T_BIND_CHOICE(*typeSpecification_);
    }

    template<> void VariableSpecification::VariableDescription_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*address_);
        ITU_T_BIND_CHOICE(*typeSpecification_);
    }

    // sequence Read-Request

    template<> void Read_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(specificationWithResult_, 0);
        ITU_T_CHOICE_TAG(*variableAccessSpecification_, 1);
    }

    template<> void Read_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(specificationWithResult_, 0);
        ITU_T_CHOICE_TAG(*variableAccessSpecification_, 1);
    }

    // sequence Read-Response

    template<> void Read_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(variableAccessSpecification_, 0);
        ITU_T_IMPLICIT_TAG(*listOfAccessResult_, 1);
    }

    template<> void Read_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(variableAccessSpecification_, 0);
        ITU_T_IMPLICIT_TAG(*listOfAccessResult_, 1);
    }

    // sequence Write-Request

    template<> void Write_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(*listOfData_, 0);
    }

    template<> void Write_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(*listOfData_, 0);
    }

    // choice 

    template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Write_Response_sequence_of_failure:
            {
                ITU_T_IMPLICIT_TAG(*value<DataAccessError > (false, Write_Response_sequence_of_failure), 0);
                break;
            }
            case Write_Response_sequence_of_success:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, Write_Response_sequence_of_success), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<DataAccessError > (true, Write_Response_sequence_of_failure), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, Write_Response_sequence_of_success), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence InformationReport

    template<> void InformationReport::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(*listOfAccessResult_, 0);
    }

    template<> void InformationReport::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(*listOfAccessResult_, 0);
    }

    // choice GetVariableAccessAttributes-Request

    template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case GetVariableAccessAttributes_Request_name:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, GetVariableAccessAttributes_Request_name), 0);
                break;
            }
            case GetVariableAccessAttributes_Request_address:
            {
                ITU_T_CHOICE_TAG(*value<MMS_Object_Module_1::Address > (false, GetVariableAccessAttributes_Request_address), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, GetVariableAccessAttributes_Request_name), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<MMS_Object_Module_1::Address > (true, GetVariableAccessAttributes_Request_address), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetVariableAccessAttributes-Response

    template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_CHOICE_TAG(address_, 1);
        ITU_T_CHOICE_TAG(*typeDescription_, 2);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_CHOICE_TAG(address_, 1);
        ITU_T_CHOICE_TAG(*typeDescription_, 2);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    // sequence DefineNamedVariable-Request

    template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*variableName_, 0);
        ITU_T_CHOICE_TAG(*address_, 1);
        ITU_T_CHOICE_TAG(typeSpecification_, 2);
    }

    template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*variableName_, 0);
        ITU_T_CHOICE_TAG(*address_, 1);
        ITU_T_CHOICE_TAG(typeSpecification_, 2);
    }

    // sequence DeleteVariableAccess-Request

    template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfDelete_, 0);
        ITU_T_IMPLICIT_TAG(listOfName_, 1);
        ITU_T_IMPLICIT_TAG(domainName_, 2);
    }

    template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfDelete_, 0);
        ITU_T_IMPLICIT_TAG(listOfName_, 1);
        ITU_T_IMPLICIT_TAG(domainName_, 2);
    }

    // sequence DeleteVariableAccess-Response

    template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberDeleted_, 1);
    }

    template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberDeleted_, 1);
    }

    // sequence DefineNamedVariableList-Request

    template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*variableListName_);
        ITU_T_IMPLICIT_TAG(*listOfVariable_, 0);
    }

    template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*variableListName_);
        ITU_T_IMPLICIT_TAG(*listOfVariable_, 0);
    }

    // sequence 

    template<> void DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    template<> void DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    // sequence GetNamedVariableListAttributes-Response

    template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*listOfVariable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*listOfVariable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    // sequence 

    template<> void GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    template<> void GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    // sequence DeleteNamedVariableList-Request

    template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfDelete_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariableListName_, 1);
        ITU_T_IMPLICIT_TAG(domainName_, 2);
    }

    template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfDelete_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariableListName_, 1);
        ITU_T_IMPLICIT_TAG(domainName_, 2);
    }

    // sequence DeleteNamedVariableList-Response

    template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberDeleted_, 1);
    }

    template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberDeleted_, 1);
    }

    // sequence DefineNamedType-Request

    template<> void DefineNamedType_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*typeName_);
        ITU_T_BIND_CHOICE(*typeSpecification_);
    }

    template<> void DefineNamedType_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*typeName_);
        ITU_T_BIND_CHOICE(*typeSpecification_);
    }

    // sequence GetNamedTypeAttributes-Response

    template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_BIND_CHOICE(*typeSpecification_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 1);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_BIND_CHOICE(*typeSpecification_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 1);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    // sequence DeleteNamedType-Request

    template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfDelete_, 0);
        ITU_T_IMPLICIT_TAG(listOfTypeName_, 1);
        ITU_T_IMPLICIT_TAG(domainName_, 2);
    }

    template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfDelete_, 0);
        ITU_T_IMPLICIT_TAG(listOfTypeName_, 1);
        ITU_T_IMPLICIT_TAG(domainName_, 2);
    }

    // sequence DeleteNamedType-Response

    template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberDeleted_, 1);
    }

    template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(*numberDeleted_, 1);
    }

    // sequence ExchangeData-Request

    template<> void ExchangeData_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*dataExchangeName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfRequestData_, 1);
    }

    template<> void ExchangeData_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*dataExchangeName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfRequestData_, 1);
    }

    // sequence ExchangeData-Response

    template<> void ExchangeData_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfResponseData_, 0);
    }

    template<> void ExchangeData_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfResponseData_, 0);
    }

    // sequence GetDataExchangeAttributes-Response

    template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*inUse_, 0);
        ITU_T_IMPLICIT_TAG(*listOfRequestTypeDescriptions_, 1);
        ITU_T_IMPLICIT_TAG(*listOfResponseTypeDescriptions_, 2);
        ITU_T_IMPLICIT_TAG(programInvocation_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*inUse_, 0);
        ITU_T_IMPLICIT_TAG(*listOfRequestTypeDescriptions_, 1);
        ITU_T_IMPLICIT_TAG(*listOfResponseTypeDescriptions_, 2);
        ITU_T_IMPLICIT_TAG(programInvocation_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    // sequence TakeControl-Request

    template<> void TakeControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
        ITU_T_IMPLICIT_TAG(applicationToPreempt_, 7);
    }

    template<> void TakeControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
        ITU_T_IMPLICIT_TAG(applicationToPreempt_, 7);
    }

    // choice TakeControl-Response

    template<> void TakeControl_Response::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case TakeControl_Response_noResult:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, TakeControl_Response_noResult), 0);
                break;
            }
            case TakeControl_Response_namedToken:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, TakeControl_Response_namedToken), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void TakeControl_Response::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, TakeControl_Response_noResult), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, TakeControl_Response_namedToken), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence RelinquishControl-Request

    template<> void RelinquishControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
    }

    template<> void RelinquishControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
    }

    // sequence DefineSemaphore-Request

    template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfTokens_, 1);
    }

    template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfTokens_, 1);
    }

    // sequence ReportSemaphoreStatus-Response

    template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*classV_, 1);
        ITU_T_IMPLICIT_TAG(*numberOfTokens_, 2);
        ITU_T_IMPLICIT_TAG(*numberOfOwnedTokens_, 3);
        ITU_T_IMPLICIT_TAG(*numberOfHungTokens_, 4);
        ITU_T_IMPLICIT_TAG(accessControlList_, 5);
    }

    template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*classV_, 1);
        ITU_T_IMPLICIT_TAG(*numberOfTokens_, 2);
        ITU_T_IMPLICIT_TAG(*numberOfOwnedTokens_, 3);
        ITU_T_IMPLICIT_TAG(*numberOfHungTokens_, 4);
        ITU_T_IMPLICIT_TAG(accessControlList_, 5);
    }

    // sequence ReportPoolSemaphoreStatus-Request

    template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(nameToStartAfter_, 1);
    }

    template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(nameToStartAfter_, 1);
    }

    // sequence ReportPoolSemaphoreStatus-Response

    template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfNamedTokens_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfNamedTokens_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // choice 

    template<> void ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ListOfNamedTokens_type_sequence_of_freeNamedToken:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ListOfNamedTokens_type_sequence_of_freeNamedToken), 0);
                break;
            }
            case ListOfNamedTokens_type_sequence_of_ownedNamedToken:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ListOfNamedTokens_type_sequence_of_ownedNamedToken), 1);
                break;
            }
            case ListOfNamedTokens_type_sequence_of_hungNamedToken:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, ListOfNamedTokens_type_sequence_of_hungNamedToken), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ListOfNamedTokens_type_sequence_of_freeNamedToken), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ListOfNamedTokens_type_sequence_of_ownedNamedToken), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, ListOfNamedTokens_type_sequence_of_hungNamedToken), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence ReportSemaphoreEntryStatus-Request

    template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(*state_, 1);
        ITU_T_IMPLICIT_TAG(entryIDToStartAfter_, 2);
    }

    template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(*state_, 1);
        ITU_T_IMPLICIT_TAG(entryIDToStartAfter_, 2);
    }

    // sequence ReportSemaphoreEntryStatus-Response

    template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfSemaphoreEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfSemaphoreEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence SemaphoreEntry

    template<> void SemaphoreEntry::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*entryID_, 0);
        ITU_T_IMPLICIT_TAG(*entryClass_, 1);
        ITU_T_EXPLICIT_TAG(*applicationReference_, 2);
        ITU_T_IMPLICIT_TAG(namedToken_, 3);
        ITU_T_IMPLICIT_TAG(priority_, 4);
        ITU_T_IMPLICIT_TAG(remainingTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 6);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 7);
    }

    template<> void SemaphoreEntry::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*entryID_, 0);
        ITU_T_IMPLICIT_TAG(*entryClass_, 1);
        ITU_T_EXPLICIT_TAG(*applicationReference_, 2);
        ITU_T_IMPLICIT_TAG(namedToken_, 3);
        ITU_T_IMPLICIT_TAG(priority_, 4);
        ITU_T_IMPLICIT_TAG(remainingTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 6);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 7);
    }

    // sequence AttachToSemaphore

    template<> void AttachToSemaphore::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
    }

    template<> void AttachToSemaphore::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
    }

    // sequence Input-Request

    template<> void Input_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(echo_, 1);
        ITU_T_IMPLICIT_TAG(listOfPromptData_, 2);
        ITU_T_IMPLICIT_TAG(inputTimeOut_, 3);
    }

    template<> void Input_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(echo_, 1);
        ITU_T_IMPLICIT_TAG(listOfPromptData_, 2);
        ITU_T_IMPLICIT_TAG(inputTimeOut_, 3);
    }

    // sequence Output-Request

    template<> void Output_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfOutputData_, 1);
    }

    template<> void Output_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfOutputData_, 1);
    }

    // sequence TriggerEvent-Request

    template<> void TriggerEvent_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(priority_, 1);
    }

    template<> void TriggerEvent_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(priority_, 1);
    }

    // sequence EventNotification

    template<> void EventNotification::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*severity_, 2);
        ITU_T_IMPLICIT_TAG(currentState_, 3);
        ITU_T_CHOICE_TAG(*transitionTime_, 4);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(actionResult_, 8);
    }

    template<> void EventNotification::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*severity_, 2);
        ITU_T_IMPLICIT_TAG(currentState_, 3);
        ITU_T_CHOICE_TAG(*transitionTime_, 4);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(actionResult_, 8);
    }

    // sequence actionResult

    template<> void EventNotification::ActionResult_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*eventActionName_);
        ITU_T_BIND_CHOICE(*successOrFailure_);
    }

    template<> void EventNotification::ActionResult_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*eventActionName_);
        ITU_T_BIND_CHOICE(*successOrFailure_);
    }

    // choice successOrFailure

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case SuccessOrFailure_type_success:
            {
                ITU_T_IMPLICIT_TAG(*value<Success_type > (false, SuccessOrFailure_type_success), 0);
                break;
            }
            case SuccessOrFailure_type_failure:
            {
                ITU_T_IMPLICIT_TAG(*value<Failure_type > (false, SuccessOrFailure_type_failure), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Success_type > (true, SuccessOrFailure_type_success), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Failure_type > (true, SuccessOrFailure_type_failure), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence success

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(*confirmedServiceResponse_);
        ITU_T_CHOICE_TAG(cs_Response_Detail_, 79);
    }

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(*confirmedServiceResponse_);
        ITU_T_CHOICE_TAG(cs_Response_Detail_, 79);
    }

    // sequence failure

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(modifierPosition_, 0);
        ITU_T_IMPLICIT_TAG(*serviceError_, 1);
    }

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(modifierPosition_, 0);
        ITU_T_IMPLICIT_TAG(*serviceError_, 1);
    }

    // choice CS-EventNotification

    template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_EventNotification_impl_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, CS_EventNotification_impl_string), 0);
                break;
            }
            case CS_EventNotification_impl_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, CS_EventNotification_impl_index), 1);
                break;
            }
            case CS_EventNotification_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, CS_EventNotification_impl_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, CS_EventNotification_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, CS_EventNotification_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, CS_EventNotification_impl_noEnhancement))) return;
                else free();
            }
        }
    }

    // sequence AcknowledgeEventNotification-Request

    template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(*acknowledgedState_, 2);
        ITU_T_CHOICE_TAG(*timeOfAcknowledgedTransition_, 3);
    }

    template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(*acknowledgedState_, 2);
        ITU_T_CHOICE_TAG(*timeOfAcknowledgedTransition_, 3);
    }

    // sequence GetAlarmSummary-Request

    template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(enrollmentsOnly_, 0);
        ITU_T_IMPLICIT_TAG(activeAlarmsOnly_, 1);
        ITU_T_IMPLICIT_TAG(acknowledgementFilter_, 2);
        ITU_T_IMPLICIT_TAG(severityFilter_, 3);
        ITU_T_CHOICE_TAG(continueAfter_, 5);
    }

    template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(enrollmentsOnly_, 0);
        ITU_T_IMPLICIT_TAG(activeAlarmsOnly_, 1);
        ITU_T_IMPLICIT_TAG(acknowledgementFilter_, 2);
        ITU_T_IMPLICIT_TAG(severityFilter_, 3);
        ITU_T_CHOICE_TAG(continueAfter_, 5);
    }

    // sequence severityFilter

    template<> void GetAlarmSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(*leastSevere_, 1);
    }

    template<> void GetAlarmSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(*leastSevere_, 1);
    }

    // sequence GetAlarmSummary-Response

    template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfAlarmSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfAlarmSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence AlarmSummary

    template<> void AlarmSummary::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*severity_, 1);
        ITU_T_IMPLICIT_TAG(*currentState_, 2);
        ITU_T_IMPLICIT_TAG(*unacknowledgedState_, 3);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 5);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 6);
    }

    template<> void AlarmSummary::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*severity_, 1);
        ITU_T_IMPLICIT_TAG(*currentState_, 2);
        ITU_T_IMPLICIT_TAG(*unacknowledgedState_, 3);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 5);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 6);
    }

    // choice EN-Additional-Detail

    template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EN_Additional_Detail_impl_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, EN_Additional_Detail_impl_string), 0);
                break;
            }
            case EN_Additional_Detail_impl_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, EN_Additional_Detail_impl_index), 1);
                break;
            }
            case EN_Additional_Detail_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, EN_Additional_Detail_impl_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, EN_Additional_Detail_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, EN_Additional_Detail_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, EN_Additional_Detail_impl_noEnhancement))) return;
                else free();
            }
        }
    }

    // sequence GetAlarmEnrollmentSummary-Request

    template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(enrollmentsOnly_, 0);
        ITU_T_IMPLICIT_TAG(activeAlarmsOnly_, 1);
        ITU_T_IMPLICIT_TAG(acknowledgementFilter_, 2);
        ITU_T_IMPLICIT_TAG(severityFilter_, 3);
        ITU_T_CHOICE_TAG(continueAfter_, 5);
    }

    template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(enrollmentsOnly_, 0);
        ITU_T_IMPLICIT_TAG(activeAlarmsOnly_, 1);
        ITU_T_IMPLICIT_TAG(acknowledgementFilter_, 2);
        ITU_T_IMPLICIT_TAG(severityFilter_, 3);
        ITU_T_CHOICE_TAG(continueAfter_, 5);
    }

    // sequence severityFilter

    template<> void GetAlarmEnrollmentSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(*leastSevere_, 1);
    }

    template<> void GetAlarmEnrollmentSummary_Request::SeverityFilter_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(*leastSevere_, 1);
    }

    // sequence GetAlarmEnrollmentSummary-Response

    template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfAlarmEnrollmentSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfAlarmEnrollmentSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence AlarmEnrollmentSummary

    template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_EXPLICIT_TAG(clientApplication_, 2);
        ITU_T_IMPLICIT_TAG(*severity_, 3);
        ITU_T_IMPLICIT_TAG(*currentState_, 4);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 5);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(*alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(enrollmentState_, 8);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 9);
        ITU_T_CHOICE_TAG(timeActiveAcknowledged_, 10);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 11);
        ITU_T_CHOICE_TAG(timeIdleAcknowledged_, 12);
    }

    template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_EXPLICIT_TAG(clientApplication_, 2);
        ITU_T_IMPLICIT_TAG(*severity_, 3);
        ITU_T_IMPLICIT_TAG(*currentState_, 4);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 5);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(*alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(enrollmentState_, 8);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 9);
        ITU_T_CHOICE_TAG(timeActiveAcknowledged_, 10);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 11);
        ITU_T_CHOICE_TAG(timeIdleAcknowledged_, 12);
    }

    // sequence AttachToEventCondition

    template<> void AttachToEventCondition::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*causingTransitions_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
    }

    template<> void AttachToEventCondition::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*causingTransitions_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
    }

    // sequence DefineEventCondition-Request

    template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
    }

    template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
    }

    // choice CS-DefineEventCondition-Request

    template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_DefineEventCondition_Request_impl_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, CS_DefineEventCondition_Request_impl_string), 0);
                break;
            }
            case CS_DefineEventCondition_Request_impl_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, CS_DefineEventCondition_Request_impl_index), 1);
                break;
            }
            case CS_DefineEventCondition_Request_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, CS_DefineEventCondition_Request_impl_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, CS_DefineEventCondition_Request_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, CS_DefineEventCondition_Request_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, CS_DefineEventCondition_Request_impl_noEnhancement))) return;
                else free();
            }
        }
    }

    // choice DeleteEventCondition-Request

    template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteEventCondition_Request_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Specific_type > (false, DeleteEventCondition_Request_specific), 0);
                break;
            }
            case DeleteEventCondition_Request_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DeleteEventCondition_Request_aa_specific), 1);
                break;
            }
            case DeleteEventCondition_Request_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, DeleteEventCondition_Request_domain), 2);
                break;
            }
            case DeleteEventCondition_Request_vmd:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DeleteEventCondition_Request_vmd), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Specific_type > (true, DeleteEventCondition_Request_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DeleteEventCondition_Request_aa_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, DeleteEventCondition_Request_domain), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DeleteEventCondition_Request_vmd), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetEventConditionAttributes-Response

    template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
        ITU_T_IMPLICIT_TAG(accessControlList_, 8);
    }

    template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
        ITU_T_IMPLICIT_TAG(accessControlList_, 8);
    }

    // choice monitoredVariable

    template<> void GetEventConditionAttributes_Response::MonitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case MonitoredVariable_type_variableReference:
            {
                ITU_T_CHOICE_TAG(*value<VariableSpecification > (false, MonitoredVariable_type_variableReference), 0);
                break;
            }
            case MonitoredVariable_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, MonitoredVariable_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetEventConditionAttributes_Response::MonitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<VariableSpecification > (true, MonitoredVariable_type_variableReference), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, MonitoredVariable_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence CS-GetEventConditionAttributes-Response

    template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(groupPriorityOverride_, 0);
        ITU_T_IMPLICIT_TAG(listOfReferencingECL_, 1);
        ITU_T_CHOICE_TAG(*displayEnhancement_, 2);
    }

    template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(groupPriorityOverride_, 0);
        ITU_T_IMPLICIT_TAG(listOfReferencingECL_, 1);
        ITU_T_CHOICE_TAG(*displayEnhancement_, 2);
    }

    // choice groupPriorityOverride

    template<> void CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case GroupPriorityOverride_type_priority:
            {
                ITU_T_IMPLICIT_TAG(*value<MMS_Object_Module_1::Priority > (false, GroupPriorityOverride_type_priority), 0);
                break;
            }
            case GroupPriorityOverride_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, GroupPriorityOverride_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMS_Object_Module_1::Priority > (true, GroupPriorityOverride_type_priority), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, GroupPriorityOverride_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, DisplayEnhancement_type_string), 0);
                break;
            }
            case DisplayEnhancement_type_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, DisplayEnhancement_type_index), 1);
                break;
            }
            case DisplayEnhancement_type_noEnhancement:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DisplayEnhancement_type_noEnhancement), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, DisplayEnhancement_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, DisplayEnhancement_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DisplayEnhancement_type_noEnhancement), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence ReportEventConditionStatus-Response

    template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*currentState_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfEventEnrollments_, 1);
        ITU_T_IMPLICIT_TAG(enabled_, 2);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 4);
    }

    template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*currentState_, 0);
        ITU_T_IMPLICIT_TAG(*numberOfEventEnrollments_, 1);
        ITU_T_IMPLICIT_TAG(enabled_, 2);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 4);
    }

    // sequence AlterEventConditionMonitoring-Request

    template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(enabled_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 3);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 4);
    }

    template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(enabled_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 3);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 4);
    }

    // sequence CS-AlterEventConditionMonitoring-Request

    template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    // choice changeDisplay

    template<> void CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ChangeDisplay_type_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, ChangeDisplay_type_string), 0);
                break;
            }
            case ChangeDisplay_type_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, ChangeDisplay_type_index), 1);
                break;
            }
            case ChangeDisplay_type_noEnhancement:
            {
                ITU_T_EXPLICIT_TAG(*value<null_type > (false, ChangeDisplay_type_noEnhancement), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, ChangeDisplay_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, ChangeDisplay_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<null_type > (true, ChangeDisplay_type_noEnhancement), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence DefineEventAction-Request

    template<> void DefineEventAction_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventActionName_, 0);
        ITU_T_IMPLICIT_TAG(listOfModifier_, 1);
        ITU_T_CHOICE_TAG(*confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
    }

    template<> void DefineEventAction_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventActionName_, 0);
        ITU_T_IMPLICIT_TAG(listOfModifier_, 1);
        ITU_T_CHOICE_TAG(*confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
    }

    // choice DeleteEventAction-Request

    template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteEventAction_Request_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Specific_type > (false, DeleteEventAction_Request_specific), 0);
                break;
            }
            case DeleteEventAction_Request_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DeleteEventAction_Request_aa_specific), 1);
                break;
            }
            case DeleteEventAction_Request_domain:
            {
                ITU_T_IMPLICIT_TAG(*value<Identifier > (false, DeleteEventAction_Request_domain), 3);
                break;
            }
            case DeleteEventAction_Request_vmd:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DeleteEventAction_Request_vmd), 4);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Specific_type > (true, DeleteEventAction_Request_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DeleteEventAction_Request_aa_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Identifier > (true, DeleteEventAction_Request_domain), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DeleteEventAction_Request_vmd), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetEventActionAttributes-Response

    template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*listOfModifier_, 1);
        ITU_T_CHOICE_TAG(*confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
    }

    template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*listOfModifier_, 1);
        ITU_T_CHOICE_TAG(*confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
    }

    // sequence DefineEventEnrollment-Request

    template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*eventConditionTransitions_, 2);
        ITU_T_IMPLICIT_TAG(*alarmAcknowledgmentRule_, 3);
        ITU_T_CHOICE_TAG(eventActionName_, 4);
        ITU_T_EXPLICIT_TAG(clientApplication_, 5);
    }

    template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*eventConditionTransitions_, 2);
        ITU_T_IMPLICIT_TAG(*alarmAcknowledgmentRule_, 3);
        ITU_T_CHOICE_TAG(eventActionName_, 4);
        ITU_T_EXPLICIT_TAG(clientApplication_, 5);
    }

    // choice CS-DefineEventEnrollment-Request

    template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_DefineEventEnrollment_Request_impl_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, CS_DefineEventEnrollment_Request_impl_string), 0);
                break;
            }
            case CS_DefineEventEnrollment_Request_impl_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, CS_DefineEventEnrollment_Request_impl_index), 1);
                break;
            }
            case CS_DefineEventEnrollment_Request_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, CS_DefineEventEnrollment_Request_impl_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, CS_DefineEventEnrollment_Request_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, CS_DefineEventEnrollment_Request_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, CS_DefineEventEnrollment_Request_impl_noEnhancement))) return;
                else free();
            }
        }
    }

    // choice DeleteEventEnrollment-Request

    template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteEventEnrollment_Request_specific:
            {
                ITU_T_IMPLICIT_TAG(*value<Specific_type > (false, DeleteEventEnrollment_Request_specific), 0);
                break;
            }
            case DeleteEventEnrollment_Request_ec:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, DeleteEventEnrollment_Request_ec), 1);
                break;
            }
            case DeleteEventEnrollment_Request_ea:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, DeleteEventEnrollment_Request_ea), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Specific_type > (true, DeleteEventEnrollment_Request_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, DeleteEventEnrollment_Request_ec), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, DeleteEventEnrollment_Request_ea), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetEventEnrollmentAttributes-Request

    template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfRequest_, 0);
        ITU_T_IMPLICIT_TAG(eventEnrollmentNames_, 1);
        ITU_T_EXPLICIT_TAG(clientApplication_, 2);
        ITU_T_CHOICE_TAG(eventConditionName_, 3);
        ITU_T_CHOICE_TAG(eventActionName_, 4);
        ITU_T_CHOICE_TAG(continueAfter_, 5);
    }

    template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(scopeOfRequest_, 0);
        ITU_T_IMPLICIT_TAG(eventEnrollmentNames_, 1);
        ITU_T_EXPLICIT_TAG(clientApplication_, 2);
        ITU_T_CHOICE_TAG(eventConditionName_, 3);
        ITU_T_CHOICE_TAG(eventActionName_, 4);
        ITU_T_CHOICE_TAG(continueAfter_, 5);
    }

    // sequence GetEventEnrollmentAttributes-Response

    template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfEEAttributes_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfEEAttributes_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence EEAttributes

    template<> void EEAttributes::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_CHOICE_TAG(eventActionName_, 2);
        ITU_T_EXPLICIT_TAG(clientApplication_, 3);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 4);
        ITU_T_IMPLICIT_TAG(*enrollmentClass_, 5);
        ITU_T_IMPLICIT_TAG(duration_, 6);
        ITU_T_IMPLICIT_TAG(invokeID_, 7);
        ITU_T_IMPLICIT_TAG(remainingAcceptableDelay_, 8);
        ITU_T_CHOICE_TAG(*displayEnhancement_, 9);
    }

    template<> void EEAttributes::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(*eventConditionName_, 1);
        ITU_T_CHOICE_TAG(eventActionName_, 2);
        ITU_T_EXPLICIT_TAG(clientApplication_, 3);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 4);
        ITU_T_IMPLICIT_TAG(*enrollmentClass_, 5);
        ITU_T_IMPLICIT_TAG(duration_, 6);
        ITU_T_IMPLICIT_TAG(invokeID_, 7);
        ITU_T_IMPLICIT_TAG(remainingAcceptableDelay_, 8);
        ITU_T_CHOICE_TAG(*displayEnhancement_, 9);
    }

    // choice eventConditionName

    template<> void EEAttributes::EventConditionName_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EventConditionName_type_eventCondition:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, EventConditionName_type_eventCondition), 0);
                break;
            }
            case EventConditionName_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, EventConditionName_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::EventConditionName_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, EventConditionName_type_eventCondition), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, EventConditionName_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice eventActionName

    template<> void EEAttributes::EventActionName_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EventActionName_type_eventAction:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, EventActionName_type_eventAction), 0);
                break;
            }
            case EventActionName_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, EventActionName_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::EventActionName_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, EventActionName_type_eventAction), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, EventActionName_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void EEAttributes::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, DisplayEnhancement_type_string), 0);
                break;
            }
            case DisplayEnhancement_type_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, DisplayEnhancement_type_index), 1);
                break;
            }
            case DisplayEnhancement_type_noEnhancement:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, DisplayEnhancement_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, DisplayEnhancement_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, DisplayEnhancement_type_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(*value<null_type > (true, DisplayEnhancement_type_noEnhancement))) return;
                else free();
            }
        }
    }

    // sequence ReportEventEnrollmentStatus-Response

    template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*eventConditionTransitions_, 0);
        ITU_T_IMPLICIT_TAG(notificationLost_, 1);
        ITU_T_IMPLICIT_TAG(*duration_, 2);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 3);
        ITU_T_IMPLICIT_TAG(*currentState_, 4);
    }

    template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*eventConditionTransitions_, 0);
        ITU_T_IMPLICIT_TAG(notificationLost_, 1);
        ITU_T_IMPLICIT_TAG(*duration_, 2);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 3);
        ITU_T_IMPLICIT_TAG(*currentState_, 4);
    }

    // sequence AlterEventEnrollment-Request

    template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 1);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 2);
    }

    template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 1);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 2);
    }

    // sequence AlterEventEnrollment-Response

    template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*currentState_, 0);
        ITU_T_CHOICE_TAG(*transitionTime_, 1);
    }

    template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*currentState_, 0);
        ITU_T_CHOICE_TAG(*transitionTime_, 1);
    }

    // choice currentState

    template<> void AlterEventEnrollment_Response::CurrentState_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CurrentState_type_state:
            {
                ITU_T_IMPLICIT_TAG(*value<EE_State > (false, CurrentState_type_state), 0);
                break;
            }
            case CurrentState_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, CurrentState_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlterEventEnrollment_Response::CurrentState_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<EE_State > (true, CurrentState_type_state), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, CurrentState_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence CS-AlterEventEnrollment-Request

    template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    // choice changeDisplay

    template<> void CS_AlterEventEnrollment_Request::ChangeDisplay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ChangeDisplay_type_string:
            {
                ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (false, ChangeDisplay_type_string), 0);
                break;
            }
            case ChangeDisplay_type_index:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, ChangeDisplay_type_index), 1);
                break;
            }
            case ChangeDisplay_type_noEnhancement:
            {
                ITU_T_EXPLICIT_TAG(*value<null_type > (false, ChangeDisplay_type_noEnhancement), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_AlterEventEnrollment_Request::ChangeDisplay_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<visiblestring_type > (true, ChangeDisplay_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, ChangeDisplay_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<null_type > (true, ChangeDisplay_type_noEnhancement), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence DefineEventConditionList-Request

    template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    // sequence AddEventConditionListReference-Request

    template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    // sequence RemoveEventConditionListReference-Request

    template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionListName_, 2);
    }

    template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(*listOfEventConditionListName_, 2);
    }

    // choice RemoveEventConditionListReference-Error

    template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RemoveEventConditionListReference_Error_eventCondition:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, RemoveEventConditionListReference_Error_eventCondition), 0);
                break;
            }
            case RemoveEventConditionListReference_Error_eventConditionList:
            {
                ITU_T_CHOICE_TAG(*value<ObjectName > (false, RemoveEventConditionListReference_Error_eventConditionList), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, RemoveEventConditionListReference_Error_eventCondition), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ObjectName > (true, RemoveEventConditionListReference_Error_eventConditionList), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence GetEventConditionListAttributes-Response

    template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    // sequence ReportEventConditionListStatus-Request

    template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(continueAfter_, 1);
    }

    template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(continueAfter_, 1);
    }

    // sequence ReportEventConditionListStatus-Response

    template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfEventConditionStatus_, 1);
        ITU_T_IMPLICIT_TAG(moreFollows_, 2);
    }

    template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfEventConditionStatus_, 1);
        ITU_T_IMPLICIT_TAG(moreFollows_, 2);
    }

    // sequence EventConditionStatus

    template<> void EventConditionStatus::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*currentState_, 1);
        ITU_T_IMPLICIT_TAG(*numberOfEventEnrollments_, 2);
        ITU_T_IMPLICIT_TAG(enabled_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 5);
    }

    template<> void EventConditionStatus::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*currentState_, 1);
        ITU_T_IMPLICIT_TAG(*numberOfEventEnrollments_, 2);
        ITU_T_IMPLICIT_TAG(enabled_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 5);
    }

    // sequence AlterEventConditionListMonitoring-Request

    template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*enabled_, 1);
        ITU_T_CHOICE_TAG(priorityChange_, 2);
    }

    template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(*enabled_, 1);
        ITU_T_CHOICE_TAG(priorityChange_, 2);
    }

    // choice priorityChange

    template<> void AlterEventConditionListMonitoring_Request::PriorityChange_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case PriorityChange_type_priorityValue:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, PriorityChange_type_priorityValue), 0);
                break;
            }
            case PriorityChange_type_priorityReset:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, PriorityChange_type_priorityReset), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlterEventConditionListMonitoring_Request::PriorityChange_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, PriorityChange_type_priorityValue), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, PriorityChange_type_priorityReset), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence ReadJournal-Request

    template<> void ReadJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
        ITU_T_CHOICE_TAG(rangeStartSpecification_, 1);
        ITU_T_CHOICE_TAG(rangeStopSpecification_, 2);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 4);
        ITU_T_IMPLICIT_TAG(entryToStartAfter_, 5);
    }

    template<> void ReadJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
        ITU_T_CHOICE_TAG(rangeStartSpecification_, 1);
        ITU_T_CHOICE_TAG(rangeStopSpecification_, 2);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 4);
        ITU_T_IMPLICIT_TAG(entryToStartAfter_, 5);
    }

    // choice rangeStartSpecification

    template<> void ReadJournal_Request::RangeStartSpecification_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RangeStartSpecification_type_startingTime:
            {
                ITU_T_IMPLICIT_TAG(*value<TimeOfDay > (false, RangeStartSpecification_type_startingTime), 0);
                break;
            }
            case RangeStartSpecification_type_startingEntry:
            {
                ITU_T_IMPLICIT_TAG(*value<octetstring_type > (false, RangeStartSpecification_type_startingEntry), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReadJournal_Request::RangeStartSpecification_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TimeOfDay > (true, RangeStartSpecification_type_startingTime), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<octetstring_type > (true, RangeStartSpecification_type_startingEntry), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // choice rangeStopSpecification

    template<> void ReadJournal_Request::RangeStopSpecification_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RangeStopSpecification_type_endingTime:
            {
                ITU_T_IMPLICIT_TAG(*value<TimeOfDay > (false, RangeStopSpecification_type_endingTime), 0);
                break;
            }
            case RangeStopSpecification_type_numberOfEntries:
            {
                ITU_T_IMPLICIT_TAG(*value<Integer32 > (false, RangeStopSpecification_type_numberOfEntries), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReadJournal_Request::RangeStopSpecification_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<TimeOfDay > (true, RangeStopSpecification_type_endingTime), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Integer32 > (true, RangeStopSpecification_type_numberOfEntries), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence entryToStartAfter

    template<> void ReadJournal_Request::EntryToStartAfter_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*timeSpecification_, 0);
        ITU_T_IMPLICIT_TAG(*entrySpecification_, 1);
    }

    template<> void ReadJournal_Request::EntryToStartAfter_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*timeSpecification_, 0);
        ITU_T_IMPLICIT_TAG(*entrySpecification_, 1);
    }

    // sequence ReadJournal-Response

    template<> void ReadJournal_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfJournalEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReadJournal_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*listOfJournalEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence JournalEntry

    template<> void JournalEntry::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*entryIdentifier_, 0);
        ITU_T_EXPLICIT_TAG(*originatingApplication_, 1);
        ITU_T_IMPLICIT_TAG(*entryContent_, 2);
    }

    template<> void JournalEntry::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*entryIdentifier_, 0);
        ITU_T_EXPLICIT_TAG(*originatingApplication_, 1);
        ITU_T_IMPLICIT_TAG(*entryContent_, 2);
    }

    // sequence WriteJournal-Request

    template<> void WriteJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfJournalEntry_, 1);
    }

    template<> void WriteJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
        ITU_T_IMPLICIT_TAG(*listOfJournalEntry_, 1);
    }

    // sequence InitializeJournal-Request

    template<> void InitializeJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
        ITU_T_IMPLICIT_TAG(limitSpecification_, 1);
    }

    template<> void InitializeJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
        ITU_T_IMPLICIT_TAG(limitSpecification_, 1);
    }

    // sequence limitSpecification

    template<> void InitializeJournal_Request::LimitSpecification_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*limitingTime_, 0);
        ITU_T_IMPLICIT_TAG(limitingEntry_, 1);
    }

    template<> void InitializeJournal_Request::LimitSpecification_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*limitingTime_, 0);
        ITU_T_IMPLICIT_TAG(limitingEntry_, 1);
    }

    // sequence ReportJournalStatus-Response

    template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*currentEntries_, 0);
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*currentEntries_, 0);
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    // sequence CreateJournal-Request

    template<> void CreateJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
    }

    template<> void CreateJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
    }

    // sequence DeleteJournal-Request

    template<> void DeleteJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
    }

    template<> void DeleteJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*journalName_, 0);
    }

    // sequence EntryContent

    template<> void EntryContent::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*occurrenceTime_, 0);
        ITU_T_BIND_CHOICE(*entryForm_);
    }

    template<> void EntryContent::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*occurrenceTime_, 0);
        ITU_T_BIND_CHOICE(*entryForm_);
    }

    // choice entryForm

    template<> void EntryContent::EntryForm_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EntryForm_type_data:
            {
                ITU_T_IMPLICIT_TAG(*value<Data_type > (false, EntryForm_type_data), 2);
                break;
            }
            case EntryForm_type_annotation:
            {
                ITU_T_EXPLICIT_TAG(*value<MMSString > (false, EntryForm_type_annotation), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EntryContent::EntryForm_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x80:
            {
                switch (__tag_id__) {
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Data_type > (true, EntryForm_type_data), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<MMSString > (true, EntryForm_type_annotation), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

    // sequence data

    template<> void EntryContent::EntryForm_type::Data_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(event_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 1);
    }

    template<> void EntryContent::EntryForm_type::Data_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(event_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 1);
    }

    // sequence event

    template<> void EntryContent::EntryForm_type::Data_type::Event_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*currentState_, 1);
    }

    template<> void EntryContent::EntryForm_type::Data_type::Event_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(*currentState_, 1);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

