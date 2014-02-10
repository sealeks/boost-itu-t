#include "ISO-9506-MMS-1.hpp"

namespace ISO_9506_MMS_1 {

        // choice MMSpdu

        template<> void MMSpdu::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case MMSpdu_confirmed_RequestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Confirmed_RequestPDU > (false , MMSpdu_confirmed_RequestPDU), 0); break; }
                case MMSpdu_confirmed_ResponsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ResponsePDU > (false , MMSpdu_confirmed_ResponsePDU), 1); break; }
                case MMSpdu_confirmed_ErrorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ErrorPDU > (false , MMSpdu_confirmed_ErrorPDU), 2); break; }
                case MMSpdu_unconfirmed_PDU:  {BOOST_ASN_IMPLICIT_TAG(value<Unconfirmed_PDU > (false , MMSpdu_unconfirmed_PDU), 3); break; }
                case MMSpdu_rejectPDU:  {BOOST_ASN_IMPLICIT_TAG(value<RejectPDU > (false , MMSpdu_rejectPDU), 4); break; }
                case MMSpdu_cancel_RequestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Cancel_RequestPDU > (false , MMSpdu_cancel_RequestPDU), 5); break; }
                case MMSpdu_cancel_ResponsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<Cancel_ResponsePDU > (false , MMSpdu_cancel_ResponsePDU), 6); break; }
                case MMSpdu_cancel_ErrorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Cancel_ErrorPDU > (false , MMSpdu_cancel_ErrorPDU), 7); break; }
                case MMSpdu_initiate_RequestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Initiate_RequestPDU > (false , MMSpdu_initiate_RequestPDU), 8); break; }
                case MMSpdu_initiate_ResponsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<Initiate_ResponsePDU > (false , MMSpdu_initiate_ResponsePDU), 9); break; }
                case MMSpdu_initiate_ErrorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Initiate_ErrorPDU > (false , MMSpdu_initiate_ErrorPDU), 10); break; }
                case MMSpdu_conclude_RequestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Conclude_RequestPDU > (false , MMSpdu_conclude_RequestPDU), 11); break; }
                case MMSpdu_conclude_ResponsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<Conclude_ResponsePDU > (false , MMSpdu_conclude_ResponsePDU), 12); break; }
                case MMSpdu_conclude_ErrorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<Conclude_ErrorPDU > (false , MMSpdu_conclude_ErrorPDU), 13); break; }
                default:{}
            }
        }

        template<> void MMSpdu::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Confirmed_RequestPDU > (true , MMSpdu_confirmed_RequestPDU), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ResponsePDU > (true , MMSpdu_confirmed_ResponsePDU), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Confirmed_ErrorPDU > (true , MMSpdu_confirmed_ErrorPDU), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Unconfirmed_PDU > (true , MMSpdu_unconfirmed_PDU), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<RejectPDU > (true , MMSpdu_rejectPDU), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<Cancel_RequestPDU > (true , MMSpdu_cancel_RequestPDU), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<Cancel_ResponsePDU > (true , MMSpdu_cancel_ResponsePDU), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<Cancel_ErrorPDU > (true , MMSpdu_cancel_ErrorPDU), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<Initiate_RequestPDU > (true , MMSpdu_initiate_RequestPDU), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<Initiate_ResponsePDU > (true , MMSpdu_initiate_ResponsePDU), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<Initiate_ErrorPDU > (true , MMSpdu_initiate_ErrorPDU), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<Conclude_RequestPDU > (true , MMSpdu_conclude_RequestPDU), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<Conclude_ResponsePDU > (true , MMSpdu_conclude_ResponsePDU), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<Conclude_ErrorPDU > (true , MMSpdu_conclude_ErrorPDU), 13)) return; else free(); break;}
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

 
        // sequence Confirmed-RequestPDU

        template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(invokeID);
            BOOST_ASN_BIND_TAG(listOfModifiers);
            BOOST_ASN_CHOICE(service);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE_TAG(service_ext, 79);
        }

        template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(invokeID);
            BOOST_ASN_BIND_TAG(listOfModifiers);
            BOOST_ASN_CHOICE(service);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE_TAG(service_ext, 79);
        }

 
        // choice ConfirmedServiceRequest

        template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ConfirmedServiceRequest_status:  {BOOST_ASN_IMPLICIT_TAG(value<Status_Request > (false , ConfirmedServiceRequest_status), 0); break; }
                case ConfirmedServiceRequest_getNameList:  {BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Request > (false , ConfirmedServiceRequest_getNameList), 1); break; }
                case ConfirmedServiceRequest_identify:  {BOOST_ASN_IMPLICIT_TAG(value<Identify_Request > (false , ConfirmedServiceRequest_identify), 2); break; }
                case ConfirmedServiceRequest_rename:  {BOOST_ASN_IMPLICIT_TAG(value<Rename_Request > (false , ConfirmedServiceRequest_rename), 3); break; }
                case ConfirmedServiceRequest_read:  {BOOST_ASN_IMPLICIT_TAG(value<Read_Request > (false , ConfirmedServiceRequest_read), 4); break; }
                case ConfirmedServiceRequest_write:  {BOOST_ASN_IMPLICIT_TAG(value<Write_Request > (false , ConfirmedServiceRequest_write), 5); break; }
                case ConfirmedServiceRequest_getVariableAccessAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (false , ConfirmedServiceRequest_getVariableAccessAttributes), 6); break; }
                case ConfirmedServiceRequest_defineNamedVariable:  {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Request > (false , ConfirmedServiceRequest_defineNamedVariable), 7); break; }
                case ConfirmedServiceRequest_defineScatteredAccess:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (false , ConfirmedServiceRequest_defineScatteredAccess), 8); break; }
                case ConfirmedServiceRequest_getScatteredAccessAttributes:  {BOOST_ASN_CHOICE_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (false , ConfirmedServiceRequest_getScatteredAccessAttributes), 9); break; }
                case ConfirmedServiceRequest_deleteVariableAccess:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Request > (false , ConfirmedServiceRequest_deleteVariableAccess), 10); break; }
                case ConfirmedServiceRequest_defineNamedVariableList:  {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Request > (false , ConfirmedServiceRequest_defineNamedVariableList), 11); break; }
                case ConfirmedServiceRequest_getNamedVariableListAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (false , ConfirmedServiceRequest_getNamedVariableListAttributes), 12); break; }
                case ConfirmedServiceRequest_deleteNamedVariableList:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Request > (false , ConfirmedServiceRequest_deleteNamedVariableList), 13); break; }
                case ConfirmedServiceRequest_defineNamedType:  {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Request > (false , ConfirmedServiceRequest_defineNamedType), 14); break; }
                case ConfirmedServiceRequest_getNamedTypeAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (false , ConfirmedServiceRequest_getNamedTypeAttributes), 15); break; }
                case ConfirmedServiceRequest_deleteNamedType:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Request > (false , ConfirmedServiceRequest_deleteNamedType), 16); break; }
                case ConfirmedServiceRequest_input:  {BOOST_ASN_IMPLICIT_TAG(value<Input_Request > (false , ConfirmedServiceRequest_input), 17); break; }
                case ConfirmedServiceRequest_output:  {BOOST_ASN_IMPLICIT_TAG(value<Output_Request > (false , ConfirmedServiceRequest_output), 18); break; }
                case ConfirmedServiceRequest_takeControl:  {BOOST_ASN_IMPLICIT_TAG(value<TakeControl_Request > (false , ConfirmedServiceRequest_takeControl), 19); break; }
                case ConfirmedServiceRequest_relinquishControl:  {BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Request > (false , ConfirmedServiceRequest_relinquishControl), 20); break; }
                case ConfirmedServiceRequest_defineSemaphore:  {BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Request > (false , ConfirmedServiceRequest_defineSemaphore), 21); break; }
                case ConfirmedServiceRequest_deleteSemaphore:  {BOOST_ASN_CHOICE_TAG(value<DeleteSemaphore_Request > (false , ConfirmedServiceRequest_deleteSemaphore), 22); break; }
                case ConfirmedServiceRequest_reportSemaphoreStatus:  {BOOST_ASN_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (false , ConfirmedServiceRequest_reportSemaphoreStatus), 23); break; }
                case ConfirmedServiceRequest_reportPoolSemaphoreStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Request > (false , ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24); break; }
                case ConfirmedServiceRequest_reportSemaphoreEntryStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Request > (false , ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25); break; }
                case ConfirmedServiceRequest_initiateDownloadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Request > (false , ConfirmedServiceRequest_initiateDownloadSequence), 26); break; }
                case ConfirmedServiceRequest_downloadSegment:  {BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Request > (false , ConfirmedServiceRequest_downloadSegment), 27); break; }
                case ConfirmedServiceRequest_terminateDownloadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Request > (false , ConfirmedServiceRequest_terminateDownloadSequence), 28); break; }
                case ConfirmedServiceRequest_initiateUploadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Request > (false , ConfirmedServiceRequest_initiateUploadSequence), 29); break; }
                case ConfirmedServiceRequest_uploadSegment:  {BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Request > (false , ConfirmedServiceRequest_uploadSegment), 30); break; }
                case ConfirmedServiceRequest_terminateUploadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Request > (false , ConfirmedServiceRequest_terminateUploadSequence), 31); break; }
                case ConfirmedServiceRequest_requestDomainDownload:  {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Request > (false , ConfirmedServiceRequest_requestDomainDownload), 32); break; }
                case ConfirmedServiceRequest_requestDomainUpload:  {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Request > (false , ConfirmedServiceRequest_requestDomainUpload), 33); break; }
                case ConfirmedServiceRequest_loadDomainContent:  {BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Request > (false , ConfirmedServiceRequest_loadDomainContent), 34); break; }
                case ConfirmedServiceRequest_storeDomainContent:  {BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Request > (false , ConfirmedServiceRequest_storeDomainContent), 35); break; }
                case ConfirmedServiceRequest_deleteDomain:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Request > (false , ConfirmedServiceRequest_deleteDomain), 36); break; }
                case ConfirmedServiceRequest_getDomainAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Request > (false , ConfirmedServiceRequest_getDomainAttributes), 37); break; }
                case ConfirmedServiceRequest_createProgramInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Request > (false , ConfirmedServiceRequest_createProgramInvocation), 38); break; }
                case ConfirmedServiceRequest_deleteProgramInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Request > (false , ConfirmedServiceRequest_deleteProgramInvocation), 39); break; }
                case ConfirmedServiceRequest_start:  {BOOST_ASN_IMPLICIT_TAG(value<Start_Request > (false , ConfirmedServiceRequest_start), 40); break; }
                case ConfirmedServiceRequest_stop:  {BOOST_ASN_IMPLICIT_TAG(value<Stop_Request > (false , ConfirmedServiceRequest_stop), 41); break; }
                case ConfirmedServiceRequest_resume:  {BOOST_ASN_IMPLICIT_TAG(value<Resume_Request > (false , ConfirmedServiceRequest_resume), 42); break; }
                case ConfirmedServiceRequest_reset:  {BOOST_ASN_IMPLICIT_TAG(value<Reset_Request > (false , ConfirmedServiceRequest_reset), 43); break; }
                case ConfirmedServiceRequest_kill:  {BOOST_ASN_IMPLICIT_TAG(value<Kill_Request > (false , ConfirmedServiceRequest_kill), 44); break; }
                case ConfirmedServiceRequest_getProgramInvocationAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Request > (false , ConfirmedServiceRequest_getProgramInvocationAttributes), 45); break; }
                case ConfirmedServiceRequest_obtainFile:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Request > (false , ConfirmedServiceRequest_obtainFile), 46); break; }
                case ConfirmedServiceRequest_defineEventCondition:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Request > (false , ConfirmedServiceRequest_defineEventCondition), 47); break; }
                case ConfirmedServiceRequest_deleteEventCondition:  {BOOST_ASN_CHOICE_TAG(value<DeleteEventCondition_Request > (false , ConfirmedServiceRequest_deleteEventCondition), 48); break; }
                case ConfirmedServiceRequest_getEventConditionAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetEventConditionAttributes_Request > (false , ConfirmedServiceRequest_getEventConditionAttributes), 49); break; }
                case ConfirmedServiceRequest_reportEventConditionStatus:  {BOOST_ASN_CHOICE_TAG(value<ReportEventConditionStatus_Request > (false , ConfirmedServiceRequest_reportEventConditionStatus), 50); break; }
                case ConfirmedServiceRequest_alterEventConditionMonitoring:  {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Request > (false , ConfirmedServiceRequest_alterEventConditionMonitoring), 51); break; }
                case ConfirmedServiceRequest_triggerEvent:  {BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Request > (false , ConfirmedServiceRequest_triggerEvent), 52); break; }
                case ConfirmedServiceRequest_defineEventAction:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Request > (false , ConfirmedServiceRequest_defineEventAction), 53); break; }
                case ConfirmedServiceRequest_deleteEventAction:  {BOOST_ASN_CHOICE_TAG(value<DeleteEventAction_Request > (false , ConfirmedServiceRequest_deleteEventAction), 54); break; }
                case ConfirmedServiceRequest_getEventActionAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetEventActionAttributes_Request > (false , ConfirmedServiceRequest_getEventActionAttributes), 55); break; }
                case ConfirmedServiceRequest_reportEventActionStatus:  {BOOST_ASN_CHOICE_TAG(value<ReportEventActionStatus_Request > (false , ConfirmedServiceRequest_reportEventActionStatus), 56); break; }
                case ConfirmedServiceRequest_defineEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Request > (false , ConfirmedServiceRequest_defineEventEnrollment), 57); break; }
                case ConfirmedServiceRequest_deleteEventEnrollment:  {BOOST_ASN_CHOICE_TAG(value<DeleteEventEnrollment_Request > (false , ConfirmedServiceRequest_deleteEventEnrollment), 58); break; }
                case ConfirmedServiceRequest_alterEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Request > (false , ConfirmedServiceRequest_alterEventEnrollment), 59); break; }
                case ConfirmedServiceRequest_reportEventEnrollmentStatus:  {BOOST_ASN_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (false , ConfirmedServiceRequest_reportEventEnrollmentStatus), 60); break; }
                case ConfirmedServiceRequest_getEventEnrollmentAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Request > (false , ConfirmedServiceRequest_getEventEnrollmentAttributes), 61); break; }
                case ConfirmedServiceRequest_acknowledgeEventNotification:  {BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Request > (false , ConfirmedServiceRequest_acknowledgeEventNotification), 62); break; }
                case ConfirmedServiceRequest_getAlarmSummary:  {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Request > (false , ConfirmedServiceRequest_getAlarmSummary), 63); break; }
                case ConfirmedServiceRequest_getAlarmEnrollmentSummary:  {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Request > (false , ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64); break; }
                case ConfirmedServiceRequest_readJournal:  {BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Request > (false , ConfirmedServiceRequest_readJournal), 65); break; }
                case ConfirmedServiceRequest_writeJournal:  {BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Request > (false , ConfirmedServiceRequest_writeJournal), 66); break; }
                case ConfirmedServiceRequest_initializeJournal:  {BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Request > (false , ConfirmedServiceRequest_initializeJournal), 67); break; }
                case ConfirmedServiceRequest_reportJournalStatus:  {BOOST_ASN_CHOICE_TAG(value<ReportJournalStatus_Request > (false , ConfirmedServiceRequest_reportJournalStatus), 68); break; }
                case ConfirmedServiceRequest_createJournal:  {BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Request > (false , ConfirmedServiceRequest_createJournal), 69); break; }
                case ConfirmedServiceRequest_deleteJournal:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Request > (false , ConfirmedServiceRequest_deleteJournal), 70); break; }
                case ConfirmedServiceRequest_getCapabilityList:  {BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Request > (false , ConfirmedServiceRequest_getCapabilityList), 71); break; }
                case ConfirmedServiceRequest_fileOpen:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Request > (false , ConfirmedServiceRequest_fileOpen), 72); break; }
                case ConfirmedServiceRequest_fileRead:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Request > (false , ConfirmedServiceRequest_fileRead), 73); break; }
                case ConfirmedServiceRequest_fileClose:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Request > (false , ConfirmedServiceRequest_fileClose), 74); break; }
                case ConfirmedServiceRequest_fileRename:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Request > (false , ConfirmedServiceRequest_fileRename), 75); break; }
                case ConfirmedServiceRequest_fileDelete:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Request > (false , ConfirmedServiceRequest_fileDelete), 76); break; }
                case ConfirmedServiceRequest_fileDirectory:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Request > (false , ConfirmedServiceRequest_fileDirectory), 77); break; }
                case ConfirmedServiceRequest_additionalService:  {BOOST_ASN_CHOICE_TAG(value<AdditionalService_Request > (false , ConfirmedServiceRequest_additionalService), 78); break; }
                case ConfirmedServiceRequest_getDataExchangeAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (false , ConfirmedServiceRequest_getDataExchangeAttributes), 80); break; }
                case ConfirmedServiceRequest_exchangeData:  {BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Request > (false , ConfirmedServiceRequest_exchangeData), 81); break; }
                case ConfirmedServiceRequest_defineAccessControlList:  {BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Request > (false , ConfirmedServiceRequest_defineAccessControlList), 82); break; }
                case ConfirmedServiceRequest_getAccessControlListAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (false , ConfirmedServiceRequest_getAccessControlListAttributes), 83); break; }
                case ConfirmedServiceRequest_reportAccessControlledObjects:  {BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Request > (false , ConfirmedServiceRequest_reportAccessControlledObjects), 84); break; }
                case ConfirmedServiceRequest_deleteAccessControlList:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Request > (false , ConfirmedServiceRequest_deleteAccessControlList), 85); break; }
                case ConfirmedServiceRequest_changeAccessControl:  {BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Request > (false , ConfirmedServiceRequest_changeAccessControl), 86); break; }
                default:{}
            }
        }

        template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Status_Request > (true , ConfirmedServiceRequest_status), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Request > (true , ConfirmedServiceRequest_getNameList), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identify_Request > (true , ConfirmedServiceRequest_identify), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Rename_Request > (true , ConfirmedServiceRequest_rename), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<Read_Request > (true , ConfirmedServiceRequest_read), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<Write_Request > (true , ConfirmedServiceRequest_write), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (true , ConfirmedServiceRequest_getVariableAccessAttributes), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Request > (true , ConfirmedServiceRequest_defineNamedVariable), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (true , ConfirmedServiceRequest_defineScatteredAccess), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_CHOICE_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (true , ConfirmedServiceRequest_getScatteredAccessAttributes), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Request > (true , ConfirmedServiceRequest_deleteVariableAccess), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Request > (true , ConfirmedServiceRequest_defineNamedVariableList), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (true , ConfirmedServiceRequest_getNamedVariableListAttributes), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Request > (true , ConfirmedServiceRequest_deleteNamedVariableList), 13)) return; else free(); break;}
                        case 14:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Request > (true , ConfirmedServiceRequest_defineNamedType), 14)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (true , ConfirmedServiceRequest_getNamedTypeAttributes), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Request > (true , ConfirmedServiceRequest_deleteNamedType), 16)) return; else free(); break;}
                        case 17:  { if (BOOST_ASN_IMPLICIT_TAG(value<Input_Request > (true , ConfirmedServiceRequest_input), 17)) return; else free(); break;}
                        case 18:  { if (BOOST_ASN_IMPLICIT_TAG(value<Output_Request > (true , ConfirmedServiceRequest_output), 18)) return; else free(); break;}
                        case 19:  { if (BOOST_ASN_IMPLICIT_TAG(value<TakeControl_Request > (true , ConfirmedServiceRequest_takeControl), 19)) return; else free(); break;}
                        case 20:  { if (BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Request > (true , ConfirmedServiceRequest_relinquishControl), 20)) return; else free(); break;}
                        case 21:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Request > (true , ConfirmedServiceRequest_defineSemaphore), 21)) return; else free(); break;}
                        case 22:  { if (BOOST_ASN_CHOICE_TAG(value<DeleteSemaphore_Request > (true , ConfirmedServiceRequest_deleteSemaphore), 22)) return; else free(); break;}
                        case 23:  { if (BOOST_ASN_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (true , ConfirmedServiceRequest_reportSemaphoreStatus), 23)) return; else free(); break;}
                        case 24:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Request > (true , ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24)) return; else free(); break;}
                        case 25:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Request > (true , ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25)) return; else free(); break;}
                        case 26:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Request > (true , ConfirmedServiceRequest_initiateDownloadSequence), 26)) return; else free(); break;}
                        case 27:  { if (BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Request > (true , ConfirmedServiceRequest_downloadSegment), 27)) return; else free(); break;}
                        case 28:  { if (BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Request > (true , ConfirmedServiceRequest_terminateDownloadSequence), 28)) return; else free(); break;}
                        case 29:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Request > (true , ConfirmedServiceRequest_initiateUploadSequence), 29)) return; else free(); break;}
                        case 30:  { if (BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Request > (true , ConfirmedServiceRequest_uploadSegment), 30)) return; else free(); break;}
                        case 31:  { if (BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Request > (true , ConfirmedServiceRequest_terminateUploadSequence), 31)) return; else free(); break;}
                        case 32:  { if (BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Request > (true , ConfirmedServiceRequest_requestDomainDownload), 32)) return; else free(); break;}
                        case 33:  { if (BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Request > (true , ConfirmedServiceRequest_requestDomainUpload), 33)) return; else free(); break;}
                        case 34:  { if (BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Request > (true , ConfirmedServiceRequest_loadDomainContent), 34)) return; else free(); break;}
                        case 35:  { if (BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Request > (true , ConfirmedServiceRequest_storeDomainContent), 35)) return; else free(); break;}
                        case 36:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Request > (true , ConfirmedServiceRequest_deleteDomain), 36)) return; else free(); break;}
                        case 37:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Request > (true , ConfirmedServiceRequest_getDomainAttributes), 37)) return; else free(); break;}
                        case 38:  { if (BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Request > (true , ConfirmedServiceRequest_createProgramInvocation), 38)) return; else free(); break;}
                        case 39:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Request > (true , ConfirmedServiceRequest_deleteProgramInvocation), 39)) return; else free(); break;}
                        case 40:  { if (BOOST_ASN_IMPLICIT_TAG(value<Start_Request > (true , ConfirmedServiceRequest_start), 40)) return; else free(); break;}
                        case 41:  { if (BOOST_ASN_IMPLICIT_TAG(value<Stop_Request > (true , ConfirmedServiceRequest_stop), 41)) return; else free(); break;}
                        case 42:  { if (BOOST_ASN_IMPLICIT_TAG(value<Resume_Request > (true , ConfirmedServiceRequest_resume), 42)) return; else free(); break;}
                        case 43:  { if (BOOST_ASN_IMPLICIT_TAG(value<Reset_Request > (true , ConfirmedServiceRequest_reset), 43)) return; else free(); break;}
                        case 44:  { if (BOOST_ASN_IMPLICIT_TAG(value<Kill_Request > (true , ConfirmedServiceRequest_kill), 44)) return; else free(); break;}
                        case 45:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Request > (true , ConfirmedServiceRequest_getProgramInvocationAttributes), 45)) return; else free(); break;}
                        case 46:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Request > (true , ConfirmedServiceRequest_obtainFile), 46)) return; else free(); break;}
                        case 47:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Request > (true , ConfirmedServiceRequest_defineEventCondition), 47)) return; else free(); break;}
                        case 48:  { if (BOOST_ASN_CHOICE_TAG(value<DeleteEventCondition_Request > (true , ConfirmedServiceRequest_deleteEventCondition), 48)) return; else free(); break;}
                        case 49:  { if (BOOST_ASN_CHOICE_TAG(value<GetEventConditionAttributes_Request > (true , ConfirmedServiceRequest_getEventConditionAttributes), 49)) return; else free(); break;}
                        case 50:  { if (BOOST_ASN_CHOICE_TAG(value<ReportEventConditionStatus_Request > (true , ConfirmedServiceRequest_reportEventConditionStatus), 50)) return; else free(); break;}
                        case 51:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Request > (true , ConfirmedServiceRequest_alterEventConditionMonitoring), 51)) return; else free(); break;}
                        case 52:  { if (BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Request > (true , ConfirmedServiceRequest_triggerEvent), 52)) return; else free(); break;}
                        case 53:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Request > (true , ConfirmedServiceRequest_defineEventAction), 53)) return; else free(); break;}
                        case 54:  { if (BOOST_ASN_CHOICE_TAG(value<DeleteEventAction_Request > (true , ConfirmedServiceRequest_deleteEventAction), 54)) return; else free(); break;}
                        case 55:  { if (BOOST_ASN_CHOICE_TAG(value<GetEventActionAttributes_Request > (true , ConfirmedServiceRequest_getEventActionAttributes), 55)) return; else free(); break;}
                        case 56:  { if (BOOST_ASN_CHOICE_TAG(value<ReportEventActionStatus_Request > (true , ConfirmedServiceRequest_reportEventActionStatus), 56)) return; else free(); break;}
                        case 57:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Request > (true , ConfirmedServiceRequest_defineEventEnrollment), 57)) return; else free(); break;}
                        case 58:  { if (BOOST_ASN_CHOICE_TAG(value<DeleteEventEnrollment_Request > (true , ConfirmedServiceRequest_deleteEventEnrollment), 58)) return; else free(); break;}
                        case 59:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Request > (true , ConfirmedServiceRequest_alterEventEnrollment), 59)) return; else free(); break;}
                        case 60:  { if (BOOST_ASN_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (true , ConfirmedServiceRequest_reportEventEnrollmentStatus), 60)) return; else free(); break;}
                        case 61:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Request > (true , ConfirmedServiceRequest_getEventEnrollmentAttributes), 61)) return; else free(); break;}
                        case 62:  { if (BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Request > (true , ConfirmedServiceRequest_acknowledgeEventNotification), 62)) return; else free(); break;}
                        case 63:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Request > (true , ConfirmedServiceRequest_getAlarmSummary), 63)) return; else free(); break;}
                        case 64:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Request > (true , ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64)) return; else free(); break;}
                        case 65:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Request > (true , ConfirmedServiceRequest_readJournal), 65)) return; else free(); break;}
                        case 66:  { if (BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Request > (true , ConfirmedServiceRequest_writeJournal), 66)) return; else free(); break;}
                        case 67:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Request > (true , ConfirmedServiceRequest_initializeJournal), 67)) return; else free(); break;}
                        case 68:  { if (BOOST_ASN_CHOICE_TAG(value<ReportJournalStatus_Request > (true , ConfirmedServiceRequest_reportJournalStatus), 68)) return; else free(); break;}
                        case 69:  { if (BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Request > (true , ConfirmedServiceRequest_createJournal), 69)) return; else free(); break;}
                        case 70:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Request > (true , ConfirmedServiceRequest_deleteJournal), 70)) return; else free(); break;}
                        case 71:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Request > (true , ConfirmedServiceRequest_getCapabilityList), 71)) return; else free(); break;}
                        case 72:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Request > (true , ConfirmedServiceRequest_fileOpen), 72)) return; else free(); break;}
                        case 73:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Request > (true , ConfirmedServiceRequest_fileRead), 73)) return; else free(); break;}
                        case 74:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Request > (true , ConfirmedServiceRequest_fileClose), 74)) return; else free(); break;}
                        case 75:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Request > (true , ConfirmedServiceRequest_fileRename), 75)) return; else free(); break;}
                        case 76:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Request > (true , ConfirmedServiceRequest_fileDelete), 76)) return; else free(); break;}
                        case 77:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Request > (true , ConfirmedServiceRequest_fileDirectory), 77)) return; else free(); break;}
                        case 78:  { if (BOOST_ASN_CHOICE_TAG(value<AdditionalService_Request > (true , ConfirmedServiceRequest_additionalService), 78)) return; else free(); break;}
                        case 80:  { if (BOOST_ASN_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (true , ConfirmedServiceRequest_getDataExchangeAttributes), 80)) return; else free(); break;}
                        case 81:  { if (BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Request > (true , ConfirmedServiceRequest_exchangeData), 81)) return; else free(); break;}
                        case 82:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Request > (true , ConfirmedServiceRequest_defineAccessControlList), 82)) return; else free(); break;}
                        case 83:  { if (BOOST_ASN_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (true , ConfirmedServiceRequest_getAccessControlListAttributes), 83)) return; else free(); break;}
                        case 84:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Request > (true , ConfirmedServiceRequest_reportAccessControlledObjects), 84)) return; else free(); break;}
                        case 85:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Request > (true , ConfirmedServiceRequest_deleteAccessControlList), 85)) return; else free(); break;}
                        case 86:  { if (BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Request > (true , ConfirmedServiceRequest_changeAccessControl), 86)) return; else free(); break;}
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

 
        // choice AdditionalService-Request

        template<> void AdditionalService_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AdditionalService_Request_vMDStop:  {BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Request > (false , AdditionalService_Request_vMDStop), 0); break; }
                case AdditionalService_Request_vMDReset:  {BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Request > (false , AdditionalService_Request_vMDReset), 1); break; }
                case AdditionalService_Request_select:  {BOOST_ASN_IMPLICIT_TAG(value<Select_Request > (false , AdditionalService_Request_select), 2); break; }
                case AdditionalService_Request_alterPI:  {BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Request > (false , AdditionalService_Request_alterPI), 3); break; }
                case AdditionalService_Request_initiateUCLoad:  {BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Request > (false , AdditionalService_Request_initiateUCLoad), 4); break; }
                case AdditionalService_Request_uCLoad:  {BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Request > (false , AdditionalService_Request_uCLoad), 5); break; }
                case AdditionalService_Request_uCUpload:  {BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Request > (false , AdditionalService_Request_uCUpload), 6); break; }
                case AdditionalService_Request_startUC:  {BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Request > (false , AdditionalService_Request_startUC), 7); break; }
                case AdditionalService_Request_stopUC:  {BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Request > (false , AdditionalService_Request_stopUC), 8); break; }
                case AdditionalService_Request_createUC:  {BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Request > (false , AdditionalService_Request_createUC), 9); break; }
                case AdditionalService_Request_addToUC:  {BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Request > (false , AdditionalService_Request_addToUC), 10); break; }
                case AdditionalService_Request_removeFromUC:  {BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Request > (false , AdditionalService_Request_removeFromUC), 11); break; }
                case AdditionalService_Request_getUCAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Request > (false , AdditionalService_Request_getUCAttributes), 12); break; }
                case AdditionalService_Request_loadUCFromFile:  {BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Request > (false , AdditionalService_Request_loadUCFromFile), 13); break; }
                case AdditionalService_Request_storeUCToFile:  {BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Request > (false , AdditionalService_Request_storeUCToFile), 14); break; }
                case AdditionalService_Request_deleteUC:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Request > (false , AdditionalService_Request_deleteUC), 15); break; }
                case AdditionalService_Request_defineECL:  {BOOST_ASN_EXPLICIT_TAG(value<DefineEventConditionList_Request > (false , AdditionalService_Request_defineECL), 16); break; }
                case AdditionalService_Request_deleteECL:  {BOOST_ASN_CHOICE_TAG(value<DeleteEventConditionList_Request > (false , AdditionalService_Request_deleteECL), 17); break; }
                case AdditionalService_Request_addECLReference:  {BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Request > (false , AdditionalService_Request_addECLReference), 18); break; }
                case AdditionalService_Request_removeECLReference:  {BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Request > (false , AdditionalService_Request_removeECLReference), 19); break; }
                case AdditionalService_Request_getECLAttributes:  {BOOST_ASN_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (false , AdditionalService_Request_getECLAttributes), 20); break; }
                case AdditionalService_Request_reportECLStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Request > (false , AdditionalService_Request_reportECLStatus), 21); break; }
                case AdditionalService_Request_alterECLMonitoring:  {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Request > (false , AdditionalService_Request_alterECLMonitoring), 22); break; }
                default:{}
            }
        }

        template<> void AdditionalService_Request::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Request > (true , AdditionalService_Request_vMDStop), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Request > (true , AdditionalService_Request_vMDReset), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Select_Request > (true , AdditionalService_Request_select), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Request > (true , AdditionalService_Request_alterPI), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Request > (true , AdditionalService_Request_initiateUCLoad), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Request > (true , AdditionalService_Request_uCLoad), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Request > (true , AdditionalService_Request_uCUpload), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Request > (true , AdditionalService_Request_startUC), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Request > (true , AdditionalService_Request_stopUC), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Request > (true , AdditionalService_Request_createUC), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Request > (true , AdditionalService_Request_addToUC), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Request > (true , AdditionalService_Request_removeFromUC), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Request > (true , AdditionalService_Request_getUCAttributes), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Request > (true , AdditionalService_Request_loadUCFromFile), 13)) return; else free(); break;}
                        case 14:  { if (BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Request > (true , AdditionalService_Request_storeUCToFile), 14)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Request > (true , AdditionalService_Request_deleteUC), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_EXPLICIT_TAG(value<DefineEventConditionList_Request > (true , AdditionalService_Request_defineECL), 16)) return; else free(); break;}
                        case 17:  { if (BOOST_ASN_CHOICE_TAG(value<DeleteEventConditionList_Request > (true , AdditionalService_Request_deleteECL), 17)) return; else free(); break;}
                        case 18:  { if (BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Request > (true , AdditionalService_Request_addECLReference), 18)) return; else free(); break;}
                        case 19:  { if (BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Request > (true , AdditionalService_Request_removeECLReference), 19)) return; else free(); break;}
                        case 20:  { if (BOOST_ASN_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (true , AdditionalService_Request_getECLAttributes), 20)) return; else free(); break;}
                        case 21:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Request > (true , AdditionalService_Request_reportECLStatus), 21)) return; else free(); break;}
                        case 22:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Request > (true , AdditionalService_Request_alterECLMonitoring), 22)) return; else free(); break;}
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

 
        // choice Request-Detail

        template<> void Request_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Request_Detail_otherRequests:  {BOOST_ASN_BIND_TAG(value<null_type > (false , Request_Detail_otherRequests)); break; }
                case Request_Detail_createProgramInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<CS_CreateProgramInvocation_Request > (false , Request_Detail_createProgramInvocation), 38); break; }
                case Request_Detail_start:  {BOOST_ASN_IMPLICIT_TAG(value<CS_Start_Request > (false , Request_Detail_start), 40); break; }
                case Request_Detail_resume:  {BOOST_ASN_IMPLICIT_TAG(value<CS_Resume_Request > (false , Request_Detail_resume), 42); break; }
                case Request_Detail_defineEventCondition:  {BOOST_ASN_IMPLICIT_TAG(value<CS_DefineEventCondition_Request > (false , Request_Detail_defineEventCondition), 47); break; }
                case Request_Detail_alterEventConditionMonitoring:  {BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventConditionMonitoring_Request > (false , Request_Detail_alterEventConditionMonitoring), 51); break; }
                case Request_Detail_defineEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<CS_DefineEventEnrollment_Request > (false , Request_Detail_defineEventEnrollment), 57); break; }
                case Request_Detail_alterEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventEnrollment_Request > (false , Request_Detail_alterEventEnrollment), 59); break; }
                default:{}
            }
        }

        template<> void Request_Detail::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 38:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_CreateProgramInvocation_Request > (true , Request_Detail_createProgramInvocation), 38)) return; else free(); break;}
                        case 40:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_Start_Request > (true , Request_Detail_start), 40)) return; else free(); break;}
                        case 42:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_Resume_Request > (true , Request_Detail_resume), 42)) return; else free(); break;}
                        case 47:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_DefineEventCondition_Request > (true , Request_Detail_defineEventCondition), 47)) return; else free(); break;}
                        case 51:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventConditionMonitoring_Request > (true , Request_Detail_alterEventConditionMonitoring), 51)) return; else free(); break;}
                        case 57:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_DefineEventEnrollment_Request > (true , Request_Detail_defineEventEnrollment), 57)) return; else free(); break;}
                        case 59:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_AlterEventEnrollment_Request > (true , Request_Detail_alterEventEnrollment), 59)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , Request_Detail_otherRequests))) return; else free();
                }
            }
        }

 
        // sequence Unconfirmed-PDU

        template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(service);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE_TAG(service_ext, 79);
        }

        template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(service);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE_TAG(service_ext, 79);
        }

 
        // choice UnconfirmedService

        template<> void UnconfirmedService::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case UnconfirmedService_informationReport:  {BOOST_ASN_IMPLICIT_TAG(value<InformationReport > (false , UnconfirmedService_informationReport), 0); break; }
                case UnconfirmedService_unsolicitedStatus:  {BOOST_ASN_IMPLICIT_TAG(value<UnsolicitedStatus > (false , UnconfirmedService_unsolicitedStatus), 1); break; }
                case UnconfirmedService_eventNotification:  {BOOST_ASN_IMPLICIT_TAG(value<EventNotification > (false , UnconfirmedService_eventNotification), 2); break; }
                default:{}
            }
        }

        template<> void UnconfirmedService::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<InformationReport > (true , UnconfirmedService_informationReport), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<UnsolicitedStatus > (true , UnconfirmedService_unsolicitedStatus), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<EventNotification > (true , UnconfirmedService_eventNotification), 2)) return; else free(); break;}
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

 
        // choice Unconfirmed-Detail

        template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Unconfirmed_Detail_otherRequests:  {BOOST_ASN_BIND_TAG(value<null_type > (false , Unconfirmed_Detail_otherRequests)); break; }
                case Unconfirmed_Detail_eventNotification:  {BOOST_ASN_IMPLICIT_TAG(value<CS_EventNotification > (false , Unconfirmed_Detail_eventNotification), 2); break; }
                default:{}
            }
        }

        template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_EventNotification > (true , Unconfirmed_Detail_eventNotification), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , Unconfirmed_Detail_otherRequests))) return; else free();
                }
            }
        }

 
        // sequence Confirmed-ResponsePDU

        template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(invokeID);
            BOOST_ASN_CHOICE(service);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE_TAG(service_ext, 79);
        }

        template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(invokeID);
            BOOST_ASN_CHOICE(service);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE_TAG(service_ext, 79);
        }

 
        // choice ConfirmedServiceResponse

        template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ConfirmedServiceResponse_status:  {BOOST_ASN_IMPLICIT_TAG(value<Status_Response > (false , ConfirmedServiceResponse_status), 0); break; }
                case ConfirmedServiceResponse_getNameList:  {BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Response > (false , ConfirmedServiceResponse_getNameList), 1); break; }
                case ConfirmedServiceResponse_identify:  {BOOST_ASN_IMPLICIT_TAG(value<Identify_Response > (false , ConfirmedServiceResponse_identify), 2); break; }
                case ConfirmedServiceResponse_rename:  {BOOST_ASN_IMPLICIT_TAG(value<Rename_Response > (false , ConfirmedServiceResponse_rename), 3); break; }
                case ConfirmedServiceResponse_read:  {BOOST_ASN_IMPLICIT_TAG(value<Read_Response > (false , ConfirmedServiceResponse_read), 4); break; }
                case ConfirmedServiceResponse_getVariableAccessAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetVariableAccessAttributes_Response > (false , ConfirmedServiceResponse_getVariableAccessAttributes), 6); break; }
                case ConfirmedServiceResponse_defineNamedVariable:  {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Response > (false , ConfirmedServiceResponse_defineNamedVariable), 7); break; }
                case ConfirmedServiceResponse_defineScatteredAccess:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (false , ConfirmedServiceResponse_defineScatteredAccess), 8); break; }
                case ConfirmedServiceResponse_getScatteredAccessAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (false , ConfirmedServiceResponse_getScatteredAccessAttributes), 9); break; }
                case ConfirmedServiceResponse_deleteVariableAccess:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Response > (false , ConfirmedServiceResponse_deleteVariableAccess), 10); break; }
                case ConfirmedServiceResponse_defineNamedVariableList:  {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Response > (false , ConfirmedServiceResponse_defineNamedVariableList), 11); break; }
                case ConfirmedServiceResponse_getNamedVariableListAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetNamedVariableListAttributes_Response > (false , ConfirmedServiceResponse_getNamedVariableListAttributes), 12); break; }
                case ConfirmedServiceResponse_deleteNamedVariableList:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Response > (false , ConfirmedServiceResponse_deleteNamedVariableList), 13); break; }
                case ConfirmedServiceResponse_defineNamedType:  {BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Response > (false , ConfirmedServiceResponse_defineNamedType), 14); break; }
                case ConfirmedServiceResponse_getNamedTypeAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetNamedTypeAttributes_Response > (false , ConfirmedServiceResponse_getNamedTypeAttributes), 15); break; }
                case ConfirmedServiceResponse_deleteNamedType:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Response > (false , ConfirmedServiceResponse_deleteNamedType), 16); break; }
                case ConfirmedServiceResponse_input:  {BOOST_ASN_IMPLICIT_TAG(value<Input_Response > (false , ConfirmedServiceResponse_input), 17); break; }
                case ConfirmedServiceResponse_output:  {BOOST_ASN_IMPLICIT_TAG(value<Output_Response > (false , ConfirmedServiceResponse_output), 18); break; }
                case ConfirmedServiceResponse_takeControl:  {BOOST_ASN_CHOICE_TAG(value<TakeControl_Response > (false , ConfirmedServiceResponse_takeControl), 19); break; }
                case ConfirmedServiceResponse_relinquishControl:  {BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Response > (false , ConfirmedServiceResponse_relinquishControl), 20); break; }
                case ConfirmedServiceResponse_defineSemaphore:  {BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Response > (false , ConfirmedServiceResponse_defineSemaphore), 21); break; }
                case ConfirmedServiceResponse_deleteSemaphore:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteSemaphore_Response > (false , ConfirmedServiceResponse_deleteSemaphore), 22); break; }
                case ConfirmedServiceResponse_reportSemaphoreStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreStatus_Response > (false , ConfirmedServiceResponse_reportSemaphoreStatus), 23); break; }
                case ConfirmedServiceResponse_reportPoolSemaphoreStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Response > (false , ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24); break; }
                case ConfirmedServiceResponse_reportSemaphoreEntryStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Response > (false , ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25); break; }
                case ConfirmedServiceResponse_initiateDownloadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Response > (false , ConfirmedServiceResponse_initiateDownloadSequence), 26); break; }
                case ConfirmedServiceResponse_downloadSegment:  {BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Response > (false , ConfirmedServiceResponse_downloadSegment), 27); break; }
                case ConfirmedServiceResponse_terminateDownloadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Response > (false , ConfirmedServiceResponse_terminateDownloadSequence), 28); break; }
                case ConfirmedServiceResponse_initiateUploadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Response > (false , ConfirmedServiceResponse_initiateUploadSequence), 29); break; }
                case ConfirmedServiceResponse_uploadSegment:  {BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Response > (false , ConfirmedServiceResponse_uploadSegment), 30); break; }
                case ConfirmedServiceResponse_terminateUploadSequence:  {BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Response > (false , ConfirmedServiceResponse_terminateUploadSequence), 31); break; }
                case ConfirmedServiceResponse_requestDomainDownload:  {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Response > (false , ConfirmedServiceResponse_requestDomainDownload), 32); break; }
                case ConfirmedServiceResponse_requestDomainUpload:  {BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Response > (false , ConfirmedServiceResponse_requestDomainUpload), 33); break; }
                case ConfirmedServiceResponse_loadDomainContent:  {BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Response > (false , ConfirmedServiceResponse_loadDomainContent), 34); break; }
                case ConfirmedServiceResponse_storeDomainContent:  {BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Response > (false , ConfirmedServiceResponse_storeDomainContent), 35); break; }
                case ConfirmedServiceResponse_deleteDomain:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Response > (false , ConfirmedServiceResponse_deleteDomain), 36); break; }
                case ConfirmedServiceResponse_getDomainAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Response > (false , ConfirmedServiceResponse_getDomainAttributes), 37); break; }
                case ConfirmedServiceResponse_createProgramInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Response > (false , ConfirmedServiceResponse_createProgramInvocation), 38); break; }
                case ConfirmedServiceResponse_deleteProgramInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Response > (false , ConfirmedServiceResponse_deleteProgramInvocation), 39); break; }
                case ConfirmedServiceResponse_start:  {BOOST_ASN_IMPLICIT_TAG(value<Start_Response > (false , ConfirmedServiceResponse_start), 40); break; }
                case ConfirmedServiceResponse_stop:  {BOOST_ASN_IMPLICIT_TAG(value<Stop_Response > (false , ConfirmedServiceResponse_stop), 41); break; }
                case ConfirmedServiceResponse_resume:  {BOOST_ASN_IMPLICIT_TAG(value<Resume_Response > (false , ConfirmedServiceResponse_resume), 42); break; }
                case ConfirmedServiceResponse_reset:  {BOOST_ASN_IMPLICIT_TAG(value<Reset_Response > (false , ConfirmedServiceResponse_reset), 43); break; }
                case ConfirmedServiceResponse_kill:  {BOOST_ASN_IMPLICIT_TAG(value<Kill_Response > (false , ConfirmedServiceResponse_kill), 44); break; }
                case ConfirmedServiceResponse_getProgramInvocationAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Response > (false , ConfirmedServiceResponse_getProgramInvocationAttributes), 45); break; }
                case ConfirmedServiceResponse_obtainFile:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Response > (false , ConfirmedServiceResponse_obtainFile), 46); break; }
                case ConfirmedServiceResponse_defineEventCondition:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Response > (false , ConfirmedServiceResponse_defineEventCondition), 47); break; }
                case ConfirmedServiceResponse_deleteEventCondition:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventCondition_Response > (false , ConfirmedServiceResponse_deleteEventCondition), 48); break; }
                case ConfirmedServiceResponse_getEventConditionAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionAttributes_Response > (false , ConfirmedServiceResponse_getEventConditionAttributes), 49); break; }
                case ConfirmedServiceResponse_reportEventConditionStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionStatus_Response > (false , ConfirmedServiceResponse_reportEventConditionStatus), 50); break; }
                case ConfirmedServiceResponse_alterEventConditionMonitoring:  {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Response > (false , ConfirmedServiceResponse_alterEventConditionMonitoring), 51); break; }
                case ConfirmedServiceResponse_triggerEvent:  {BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Response > (false , ConfirmedServiceResponse_triggerEvent), 52); break; }
                case ConfirmedServiceResponse_defineEventAction:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Response > (false , ConfirmedServiceResponse_defineEventAction), 53); break; }
                case ConfirmedServiceResponse_deleteEventAction:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventAction_Response > (false , ConfirmedServiceResponse_deleteEventAction), 54); break; }
                case ConfirmedServiceResponse_getEventActionAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetEventActionAttributes_Response > (false , ConfirmedServiceResponse_getEventActionAttributes), 55); break; }
                case ConfirmedServiceResponse_reportEventActionStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportEventActionStatus_Response > (false , ConfirmedServiceResponse_reportEventActionStatus), 56); break; }
                case ConfirmedServiceResponse_defineEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Response > (false , ConfirmedServiceResponse_defineEventEnrollment), 57); break; }
                case ConfirmedServiceResponse_deleteEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventEnrollment_Response > (false , ConfirmedServiceResponse_deleteEventEnrollment), 58); break; }
                case ConfirmedServiceResponse_alterEventEnrollment:  {BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Response > (false , ConfirmedServiceResponse_alterEventEnrollment), 59); break; }
                case ConfirmedServiceResponse_reportEventEnrollmentStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportEventEnrollmentStatus_Response > (false , ConfirmedServiceResponse_reportEventEnrollmentStatus), 60); break; }
                case ConfirmedServiceResponse_getEventEnrollmentAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Response > (false , ConfirmedServiceResponse_getEventEnrollmentAttributes), 61); break; }
                case ConfirmedServiceResponse_acknowledgeEventNotification:  {BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Response > (false , ConfirmedServiceResponse_acknowledgeEventNotification), 62); break; }
                case ConfirmedServiceResponse_getAlarmSummary:  {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Response > (false , ConfirmedServiceResponse_getAlarmSummary), 63); break; }
                case ConfirmedServiceResponse_getAlarmEnrollmentSummary:  {BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Response > (false , ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64); break; }
                case ConfirmedServiceResponse_readJournal:  {BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Response > (false , ConfirmedServiceResponse_readJournal), 65); break; }
                case ConfirmedServiceResponse_writeJournal:  {BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Response > (false , ConfirmedServiceResponse_writeJournal), 66); break; }
                case ConfirmedServiceResponse_initializeJournal:  {BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Response > (false , ConfirmedServiceResponse_initializeJournal), 67); break; }
                case ConfirmedServiceResponse_reportJournalStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportJournalStatus_Response > (false , ConfirmedServiceResponse_reportJournalStatus), 68); break; }
                case ConfirmedServiceResponse_createJournal:  {BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Response > (false , ConfirmedServiceResponse_createJournal), 69); break; }
                case ConfirmedServiceResponse_deleteJournal:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Response > (false , ConfirmedServiceResponse_deleteJournal), 70); break; }
                case ConfirmedServiceResponse_getCapabilityList:  {BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Response > (false , ConfirmedServiceResponse_getCapabilityList), 71); break; }
                case ConfirmedServiceResponse_fileOpen:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Response > (false , ConfirmedServiceResponse_fileOpen), 72); break; }
                case ConfirmedServiceResponse_fileRead:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Response > (false , ConfirmedServiceResponse_fileRead), 73); break; }
                case ConfirmedServiceResponse_fileClose:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Response > (false , ConfirmedServiceResponse_fileClose), 74); break; }
                case ConfirmedServiceResponse_fileRename:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Response > (false , ConfirmedServiceResponse_fileRename), 75); break; }
                case ConfirmedServiceResponse_fileDelete:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Response > (false , ConfirmedServiceResponse_fileDelete), 76); break; }
                case ConfirmedServiceResponse_fileDirectory:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Response > (false , ConfirmedServiceResponse_fileDirectory), 77); break; }
                case ConfirmedServiceResponse_additionalService:  {BOOST_ASN_CHOICE_TAG(value<AdditionalService_Response > (false , ConfirmedServiceResponse_additionalService), 78); break; }
                case ConfirmedServiceResponse_getDataExchangeAttributes:  {BOOST_ASN_EXPLICIT_TAG(value<GetDataExchangeAttributes_Response > (false , ConfirmedServiceResponse_getDataExchangeAttributes), 80); break; }
                case ConfirmedServiceResponse_exchangeData:  {BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Response > (false , ConfirmedServiceResponse_exchangeData), 81); break; }
                case ConfirmedServiceResponse_defineAccessControlList:  {BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Response > (false , ConfirmedServiceResponse_defineAccessControlList), 82); break; }
                case ConfirmedServiceResponse_getAccessControlListAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetAccessControlListAttributes_Response > (false , ConfirmedServiceResponse_getAccessControlListAttributes), 83); break; }
                case ConfirmedServiceResponse_reportAccessControlledObjects:  {BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Response > (false , ConfirmedServiceResponse_reportAccessControlledObjects), 84); break; }
                case ConfirmedServiceResponse_deleteAccessControlList:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Response > (false , ConfirmedServiceResponse_deleteAccessControlList), 85); break; }
                case ConfirmedServiceResponse_changeAccessControl:  {BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Response > (false , ConfirmedServiceResponse_changeAccessControl), 86); break; }
                default:{}
            }
        }

        template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Status_Response > (true , ConfirmedServiceResponse_status), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetNameList_Response > (true , ConfirmedServiceResponse_getNameList), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identify_Response > (true , ConfirmedServiceResponse_identify), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Rename_Response > (true , ConfirmedServiceResponse_rename), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<Read_Response > (true , ConfirmedServiceResponse_read), 4)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetVariableAccessAttributes_Response > (true , ConfirmedServiceResponse_getVariableAccessAttributes), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariable_Response > (true , ConfirmedServiceResponse_defineNamedVariable), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (true , ConfirmedServiceResponse_defineScatteredAccess), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (true , ConfirmedServiceResponse_getScatteredAccessAttributes), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Response > (true , ConfirmedServiceResponse_deleteVariableAccess), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineNamedVariableList_Response > (true , ConfirmedServiceResponse_defineNamedVariableList), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetNamedVariableListAttributes_Response > (true , ConfirmedServiceResponse_getNamedVariableListAttributes), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Response > (true , ConfirmedServiceResponse_deleteNamedVariableList), 13)) return; else free(); break;}
                        case 14:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineNamedType_Response > (true , ConfirmedServiceResponse_defineNamedType), 14)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetNamedTypeAttributes_Response > (true , ConfirmedServiceResponse_getNamedTypeAttributes), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Response > (true , ConfirmedServiceResponse_deleteNamedType), 16)) return; else free(); break;}
                        case 17:  { if (BOOST_ASN_IMPLICIT_TAG(value<Input_Response > (true , ConfirmedServiceResponse_input), 17)) return; else free(); break;}
                        case 18:  { if (BOOST_ASN_IMPLICIT_TAG(value<Output_Response > (true , ConfirmedServiceResponse_output), 18)) return; else free(); break;}
                        case 19:  { if (BOOST_ASN_CHOICE_TAG(value<TakeControl_Response > (true , ConfirmedServiceResponse_takeControl), 19)) return; else free(); break;}
                        case 20:  { if (BOOST_ASN_IMPLICIT_TAG(value<RelinquishControl_Response > (true , ConfirmedServiceResponse_relinquishControl), 20)) return; else free(); break;}
                        case 21:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineSemaphore_Response > (true , ConfirmedServiceResponse_defineSemaphore), 21)) return; else free(); break;}
                        case 22:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteSemaphore_Response > (true , ConfirmedServiceResponse_deleteSemaphore), 22)) return; else free(); break;}
                        case 23:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreStatus_Response > (true , ConfirmedServiceResponse_reportSemaphoreStatus), 23)) return; else free(); break;}
                        case 24:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Response > (true , ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24)) return; else free(); break;}
                        case 25:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Response > (true , ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25)) return; else free(); break;}
                        case 26:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitiateDownloadSequence_Response > (true , ConfirmedServiceResponse_initiateDownloadSequence), 26)) return; else free(); break;}
                        case 27:  { if (BOOST_ASN_IMPLICIT_TAG(value<DownloadSegment_Response > (true , ConfirmedServiceResponse_downloadSegment), 27)) return; else free(); break;}
                        case 28:  { if (BOOST_ASN_IMPLICIT_TAG(value<TerminateDownloadSequence_Response > (true , ConfirmedServiceResponse_terminateDownloadSequence), 28)) return; else free(); break;}
                        case 29:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitiateUploadSequence_Response > (true , ConfirmedServiceResponse_initiateUploadSequence), 29)) return; else free(); break;}
                        case 30:  { if (BOOST_ASN_IMPLICIT_TAG(value<UploadSegment_Response > (true , ConfirmedServiceResponse_uploadSegment), 30)) return; else free(); break;}
                        case 31:  { if (BOOST_ASN_IMPLICIT_TAG(value<TerminateUploadSequence_Response > (true , ConfirmedServiceResponse_terminateUploadSequence), 31)) return; else free(); break;}
                        case 32:  { if (BOOST_ASN_IMPLICIT_TAG(value<RequestDomainDownload_Response > (true , ConfirmedServiceResponse_requestDomainDownload), 32)) return; else free(); break;}
                        case 33:  { if (BOOST_ASN_IMPLICIT_TAG(value<RequestDomainUpload_Response > (true , ConfirmedServiceResponse_requestDomainUpload), 33)) return; else free(); break;}
                        case 34:  { if (BOOST_ASN_IMPLICIT_TAG(value<LoadDomainContent_Response > (true , ConfirmedServiceResponse_loadDomainContent), 34)) return; else free(); break;}
                        case 35:  { if (BOOST_ASN_IMPLICIT_TAG(value<StoreDomainContent_Response > (true , ConfirmedServiceResponse_storeDomainContent), 35)) return; else free(); break;}
                        case 36:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteDomain_Response > (true , ConfirmedServiceResponse_deleteDomain), 36)) return; else free(); break;}
                        case 37:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetDomainAttributes_Response > (true , ConfirmedServiceResponse_getDomainAttributes), 37)) return; else free(); break;}
                        case 38:  { if (BOOST_ASN_IMPLICIT_TAG(value<CreateProgramInvocation_Response > (true , ConfirmedServiceResponse_createProgramInvocation), 38)) return; else free(); break;}
                        case 39:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteProgramInvocation_Response > (true , ConfirmedServiceResponse_deleteProgramInvocation), 39)) return; else free(); break;}
                        case 40:  { if (BOOST_ASN_IMPLICIT_TAG(value<Start_Response > (true , ConfirmedServiceResponse_start), 40)) return; else free(); break;}
                        case 41:  { if (BOOST_ASN_IMPLICIT_TAG(value<Stop_Response > (true , ConfirmedServiceResponse_stop), 41)) return; else free(); break;}
                        case 42:  { if (BOOST_ASN_IMPLICIT_TAG(value<Resume_Response > (true , ConfirmedServiceResponse_resume), 42)) return; else free(); break;}
                        case 43:  { if (BOOST_ASN_IMPLICIT_TAG(value<Reset_Response > (true , ConfirmedServiceResponse_reset), 43)) return; else free(); break;}
                        case 44:  { if (BOOST_ASN_IMPLICIT_TAG(value<Kill_Response > (true , ConfirmedServiceResponse_kill), 44)) return; else free(); break;}
                        case 45:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Response > (true , ConfirmedServiceResponse_getProgramInvocationAttributes), 45)) return; else free(); break;}
                        case 46:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Response > (true , ConfirmedServiceResponse_obtainFile), 46)) return; else free(); break;}
                        case 47:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventCondition_Response > (true , ConfirmedServiceResponse_defineEventCondition), 47)) return; else free(); break;}
                        case 48:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteEventCondition_Response > (true , ConfirmedServiceResponse_deleteEventCondition), 48)) return; else free(); break;}
                        case 49:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionAttributes_Response > (true , ConfirmedServiceResponse_getEventConditionAttributes), 49)) return; else free(); break;}
                        case 50:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionStatus_Response > (true , ConfirmedServiceResponse_reportEventConditionStatus), 50)) return; else free(); break;}
                        case 51:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Response > (true , ConfirmedServiceResponse_alterEventConditionMonitoring), 51)) return; else free(); break;}
                        case 52:  { if (BOOST_ASN_IMPLICIT_TAG(value<TriggerEvent_Response > (true , ConfirmedServiceResponse_triggerEvent), 52)) return; else free(); break;}
                        case 53:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventAction_Response > (true , ConfirmedServiceResponse_defineEventAction), 53)) return; else free(); break;}
                        case 54:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteEventAction_Response > (true , ConfirmedServiceResponse_deleteEventAction), 54)) return; else free(); break;}
                        case 55:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetEventActionAttributes_Response > (true , ConfirmedServiceResponse_getEventActionAttributes), 55)) return; else free(); break;}
                        case 56:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportEventActionStatus_Response > (true , ConfirmedServiceResponse_reportEventActionStatus), 56)) return; else free(); break;}
                        case 57:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventEnrollment_Response > (true , ConfirmedServiceResponse_defineEventEnrollment), 57)) return; else free(); break;}
                        case 58:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteEventEnrollment_Response > (true , ConfirmedServiceResponse_deleteEventEnrollment), 58)) return; else free(); break;}
                        case 59:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterEventEnrollment_Response > (true , ConfirmedServiceResponse_alterEventEnrollment), 59)) return; else free(); break;}
                        case 60:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportEventEnrollmentStatus_Response > (true , ConfirmedServiceResponse_reportEventEnrollmentStatus), 60)) return; else free(); break;}
                        case 61:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Response > (true , ConfirmedServiceResponse_getEventEnrollmentAttributes), 61)) return; else free(); break;}
                        case 62:  { if (BOOST_ASN_IMPLICIT_TAG(value<AcknowledgeEventNotification_Response > (true , ConfirmedServiceResponse_acknowledgeEventNotification), 62)) return; else free(); break;}
                        case 63:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetAlarmSummary_Response > (true , ConfirmedServiceResponse_getAlarmSummary), 63)) return; else free(); break;}
                        case 64:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Response > (true , ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64)) return; else free(); break;}
                        case 65:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReadJournal_Response > (true , ConfirmedServiceResponse_readJournal), 65)) return; else free(); break;}
                        case 66:  { if (BOOST_ASN_IMPLICIT_TAG(value<WriteJournal_Response > (true , ConfirmedServiceResponse_writeJournal), 66)) return; else free(); break;}
                        case 67:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitializeJournal_Response > (true , ConfirmedServiceResponse_initializeJournal), 67)) return; else free(); break;}
                        case 68:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportJournalStatus_Response > (true , ConfirmedServiceResponse_reportJournalStatus), 68)) return; else free(); break;}
                        case 69:  { if (BOOST_ASN_IMPLICIT_TAG(value<CreateJournal_Response > (true , ConfirmedServiceResponse_createJournal), 69)) return; else free(); break;}
                        case 70:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteJournal_Response > (true , ConfirmedServiceResponse_deleteJournal), 70)) return; else free(); break;}
                        case 71:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetCapabilityList_Response > (true , ConfirmedServiceResponse_getCapabilityList), 71)) return; else free(); break;}
                        case 72:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Response > (true , ConfirmedServiceResponse_fileOpen), 72)) return; else free(); break;}
                        case 73:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Response > (true , ConfirmedServiceResponse_fileRead), 73)) return; else free(); break;}
                        case 74:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Response > (true , ConfirmedServiceResponse_fileClose), 74)) return; else free(); break;}
                        case 75:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Response > (true , ConfirmedServiceResponse_fileRename), 75)) return; else free(); break;}
                        case 76:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Response > (true , ConfirmedServiceResponse_fileDelete), 76)) return; else free(); break;}
                        case 77:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Response > (true , ConfirmedServiceResponse_fileDirectory), 77)) return; else free(); break;}
                        case 78:  { if (BOOST_ASN_CHOICE_TAG(value<AdditionalService_Response > (true , ConfirmedServiceResponse_additionalService), 78)) return; else free(); break;}
                        case 80:  { if (BOOST_ASN_EXPLICIT_TAG(value<GetDataExchangeAttributes_Response > (true , ConfirmedServiceResponse_getDataExchangeAttributes), 80)) return; else free(); break;}
                        case 81:  { if (BOOST_ASN_IMPLICIT_TAG(value<ExchangeData_Response > (true , ConfirmedServiceResponse_exchangeData), 81)) return; else free(); break;}
                        case 82:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineAccessControlList_Response > (true , ConfirmedServiceResponse_defineAccessControlList), 82)) return; else free(); break;}
                        case 83:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetAccessControlListAttributes_Response > (true , ConfirmedServiceResponse_getAccessControlListAttributes), 83)) return; else free(); break;}
                        case 84:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportAccessControlledObjects_Response > (true , ConfirmedServiceResponse_reportAccessControlledObjects), 84)) return; else free(); break;}
                        case 85:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteAccessControlList_Response > (true , ConfirmedServiceResponse_deleteAccessControlList), 85)) return; else free(); break;}
                        case 86:  { if (BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Response > (true , ConfirmedServiceResponse_changeAccessControl), 86)) return; else free(); break;}
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

 
        // choice AdditionalService-Response

        template<> void AdditionalService_Response::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AdditionalService_Response_vMDStop:  {BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Response > (false , AdditionalService_Response_vMDStop), 0); break; }
                case AdditionalService_Response_vMDReset:  {BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Response > (false , AdditionalService_Response_vMDReset), 1); break; }
                case AdditionalService_Response_select:  {BOOST_ASN_IMPLICIT_TAG(value<Select_Response > (false , AdditionalService_Response_select), 2); break; }
                case AdditionalService_Response_alterPI:  {BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Response > (false , AdditionalService_Response_alterPI), 3); break; }
                case AdditionalService_Response_initiateUCLoad:  {BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Response > (false , AdditionalService_Response_initiateUCLoad), 4); break; }
                case AdditionalService_Response_uCLoad:  {BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Response > (false , AdditionalService_Response_uCLoad), 5); break; }
                case AdditionalService_Response_uCUpload:  {BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Response > (false , AdditionalService_Response_uCUpload), 6); break; }
                case AdditionalService_Response_startUC:  {BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Response > (false , AdditionalService_Response_startUC), 7); break; }
                case AdditionalService_Response_stopUC:  {BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Response > (false , AdditionalService_Response_stopUC), 8); break; }
                case AdditionalService_Response_createUC:  {BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Response > (false , AdditionalService_Response_createUC), 9); break; }
                case AdditionalService_Response_addToUC:  {BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Response > (false , AdditionalService_Response_addToUC), 10); break; }
                case AdditionalService_Response_removeFromUC:  {BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Response > (false , AdditionalService_Response_removeFromUC), 11); break; }
                case AdditionalService_Response_getUCAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Response > (false , AdditionalService_Response_getUCAttributes), 12); break; }
                case AdditionalService_Response_loadUCFromFile:  {BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Response > (false , AdditionalService_Response_loadUCFromFile), 13); break; }
                case AdditionalService_Response_storeUCToFile:  {BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Response > (false , AdditionalService_Response_storeUCToFile), 14); break; }
                case AdditionalService_Response_deleteUC:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Response > (false , AdditionalService_Response_deleteUC), 15); break; }
                case AdditionalService_Response_defineECL:  {BOOST_ASN_IMPLICIT_TAG(value<DefineEventConditionList_Response > (false , AdditionalService_Response_defineECL), 16); break; }
                case AdditionalService_Response_deleteECL:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteEventConditionList_Response > (false , AdditionalService_Response_deleteECL), 17); break; }
                case AdditionalService_Response_addECLReference:  {BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Response > (false , AdditionalService_Response_addECLReference), 18); break; }
                case AdditionalService_Response_removeECLReference:  {BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Response > (false , AdditionalService_Response_removeECLReference), 19); break; }
                case AdditionalService_Response_getECLAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionListAttributes_Response > (false , AdditionalService_Response_getECLAttributes), 20); break; }
                case AdditionalService_Response_reportECLStatus:  {BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Response > (false , AdditionalService_Response_reportECLStatus), 21); break; }
                case AdditionalService_Response_alterECLMonitoring:  {BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Response > (false , AdditionalService_Response_alterECLMonitoring), 22); break; }
                default:{}
            }
        }

        template<> void AdditionalService_Response::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<VMDStop_Response > (true , AdditionalService_Response_vMDStop), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<VMDReset_Response > (true , AdditionalService_Response_vMDReset), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Select_Response > (true , AdditionalService_Response_select), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Response > (true , AdditionalService_Response_alterPI), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<InitiateUnitControlLoad_Response > (true , AdditionalService_Response_initiateUCLoad), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<UnitControlLoadSegment_Response > (true , AdditionalService_Response_uCLoad), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<UnitControlUpload_Response > (true , AdditionalService_Response_uCUpload), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Response > (true , AdditionalService_Response_startUC), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Response > (true , AdditionalService_Response_stopUC), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<CreateUnitControl_Response > (true , AdditionalService_Response_createUC), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<AddToUnitControl_Response > (true , AdditionalService_Response_addToUC), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<RemoveFromUnitControl_Response > (true , AdditionalService_Response_removeFromUC), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetUnitControlAttributes_Response > (true , AdditionalService_Response_getUCAttributes), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<LoadUnitControlFromFile_Response > (true , AdditionalService_Response_loadUCFromFile), 13)) return; else free(); break;}
                        case 14:  { if (BOOST_ASN_IMPLICIT_TAG(value<StoreUnitControlToFile_Response > (true , AdditionalService_Response_storeUCToFile), 14)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteUnitControl_Response > (true , AdditionalService_Response_deleteUC), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_IMPLICIT_TAG(value<DefineEventConditionList_Response > (true , AdditionalService_Response_defineECL), 16)) return; else free(); break;}
                        case 17:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteEventConditionList_Response > (true , AdditionalService_Response_deleteECL), 17)) return; else free(); break;}
                        case 18:  { if (BOOST_ASN_IMPLICIT_TAG(value<AddEventConditionListReference_Response > (true , AdditionalService_Response_addECLReference), 18)) return; else free(); break;}
                        case 19:  { if (BOOST_ASN_IMPLICIT_TAG(value<RemoveEventConditionListReference_Response > (true , AdditionalService_Response_removeECLReference), 19)) return; else free(); break;}
                        case 20:  { if (BOOST_ASN_IMPLICIT_TAG(value<GetEventConditionListAttributes_Response > (true , AdditionalService_Response_getECLAttributes), 20)) return; else free(); break;}
                        case 21:  { if (BOOST_ASN_IMPLICIT_TAG(value<ReportEventConditionListStatus_Response > (true , AdditionalService_Response_reportECLStatus), 21)) return; else free(); break;}
                        case 22:  { if (BOOST_ASN_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Response > (true , AdditionalService_Response_alterECLMonitoring), 22)) return; else free(); break;}
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

 
        // choice Response-Detail

        template<> void Response_Detail::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Response_Detail_otherRequests:  {BOOST_ASN_BIND_TAG(value<null_type > (false , Response_Detail_otherRequests)); break; }
                case Response_Detail_status:  {BOOST_ASN_CHOICE_TAG(value<CS_Status_Response > (false , Response_Detail_status), 0); break; }
                case Response_Detail_getProgramInvocationAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<CS_GetProgramInvocationAttributes_Response > (false , Response_Detail_getProgramInvocationAttributes), 45); break; }
                case Response_Detail_getEventConditionAttributes:  {BOOST_ASN_IMPLICIT_TAG(value<CS_GetEventConditionAttributes_Response > (false , Response_Detail_getEventConditionAttributes), 49); break; }
                default:{}
            }
        }

        template<> void Response_Detail::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<CS_Status_Response > (true , Response_Detail_status), 0)) return; else free(); break;}
                        case 45:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_GetProgramInvocationAttributes_Response > (true , Response_Detail_getProgramInvocationAttributes), 45)) return; else free(); break;}
                        case 49:  { if (BOOST_ASN_IMPLICIT_TAG(value<CS_GetEventConditionAttributes_Response > (true , Response_Detail_getEventConditionAttributes), 49)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , Response_Detail_otherRequests))) return; else free();
                }
            }
        }

 
        // sequence Confirmed-ErrorPDU

        template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(invokeID, 0);
            BOOST_ASN_IMPLICIT_TAG(modifierPosition, 1);
            BOOST_ASN_IMPLICIT_TAG(serviceError, 2);
        }

        template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(invokeID, 0);
            BOOST_ASN_IMPLICIT_TAG(modifierPosition, 1);
            BOOST_ASN_IMPLICIT_TAG(serviceError, 2);
        }

 
        // sequence ServiceError

    const int ServiceError::errorClass_type::vmd_state_other = 0;
    const int ServiceError::errorClass_type::vmd_state_vmd_state_conflict = 1;
    const int ServiceError::errorClass_type::vmd_state_vmd_operational_problem = 2;
    const int ServiceError::errorClass_type::vmd_state_domain_transfer_problem = 3;
    const int ServiceError::errorClass_type::vmd_state_state_machine_id_invalid = 4;

    const int ServiceError::errorClass_type::application_reference_other = 0;
    const int ServiceError::errorClass_type::application_reference_application_unreachable = 1;
    const int ServiceError::errorClass_type::application_reference_connection_lost = 2;
    const int ServiceError::errorClass_type::application_reference_application_reference_invalid = 3;
    const int ServiceError::errorClass_type::application_reference_context_unsupported = 4;

    const int ServiceError::errorClass_type::definition_other = 0;
    const int ServiceError::errorClass_type::definition_object_undefined = 1;
    const int ServiceError::errorClass_type::definition_invalid_address = 2;
    const int ServiceError::errorClass_type::definition_type_unsupported = 3;
    const int ServiceError::errorClass_type::definition_type_inconsistent = 4;
    const int ServiceError::errorClass_type::definition_object_exists = 5;
    const int ServiceError::errorClass_type::definition_object_attribute_inconsistent = 6;

    const int ServiceError::errorClass_type::resource_other = 0;
    const int ServiceError::errorClass_type::resource_memory_unavailable = 1;
    const int ServiceError::errorClass_type::resource_processor_resource_unavailable = 2;
    const int ServiceError::errorClass_type::resource_mass_storage_unavailable = 3;
    const int ServiceError::errorClass_type::resource_capability_unavailable = 4;
    const int ServiceError::errorClass_type::resource_capability_unknown = 5;

    const int ServiceError::errorClass_type::service_other = 0;
    const int ServiceError::errorClass_type::service_primitives_out_of_sequence = 1;
    const int ServiceError::errorClass_type::service_object_state_conflict = 2;
    const int ServiceError::errorClass_type::service_continuation_invalid = 4;
    const int ServiceError::errorClass_type::service_object_constraint_conflict = 5;

    const int ServiceError::errorClass_type::service_preempt_other = 0;
    const int ServiceError::errorClass_type::service_preempt_timeout = 1;
    const int ServiceError::errorClass_type::service_preempt_deadlock = 2;
    const int ServiceError::errorClass_type::service_preempt_cancel = 3;

    const int ServiceError::errorClass_type::time_resolution_other = 0;
    const int ServiceError::errorClass_type::time_resolution_unsupportable_time_resolution = 1;

    const int ServiceError::errorClass_type::access_other = 0;
    const int ServiceError::errorClass_type::access_object_access_unsupported = 1;
    const int ServiceError::errorClass_type::access_object_non_existent = 2;
    const int ServiceError::errorClass_type::access_object_access_denied = 3;
    const int ServiceError::errorClass_type::access_object_invalidated = 4;

    const int ServiceError::errorClass_type::initiate_other = 0;
    const int ServiceError::errorClass_type::initiate_max_services_outstanding_calling_insufficient = 3;
    const int ServiceError::errorClass_type::initiate_max_services_outstanding_called_insufficient = 4;
    const int ServiceError::errorClass_type::initiate_service_CBB_insufficient = 5;
    const int ServiceError::errorClass_type::initiate_parameter_CBB_insufficient = 6;
    const int ServiceError::errorClass_type::initiate_nesting_level_insufficient = 7;

    const int ServiceError::errorClass_type::conclude_other = 0;
    const int ServiceError::errorClass_type::conclude_further_communication_required = 1;

    const int ServiceError::errorClass_type::cancel_other = 0;
    const int ServiceError::errorClass_type::cancel_invoke_id_unknown = 1;
    const int ServiceError::errorClass_type::cancel_cancel_not_possible = 2;

    const int ServiceError::errorClass_type::file_other = 0;
    const int ServiceError::errorClass_type::file_filename_ambiguous = 1;
    const int ServiceError::errorClass_type::file_file_busy = 2;
    const int ServiceError::errorClass_type::file_filename_syntax_error = 3;
    const int ServiceError::errorClass_type::file_content_type_invalid = 4;
    const int ServiceError::errorClass_type::file_position_invalid = 5;
    const int ServiceError::errorClass_type::file_file_access_denied = 6;
    const int ServiceError::errorClass_type::file_file_non_existent = 7;
    const int ServiceError::errorClass_type::file_duplicate_filename = 8;
    const int ServiceError::errorClass_type::file_insufficient_space_in_filestore = 9;


        template<> void ServiceError::errorClass_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case errorClass_type_vmd_state:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_vmd_state), 0); break; }
                case errorClass_type_application_reference:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_application_reference), 1); break; }
                case errorClass_type_definition:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_definition), 2); break; }
                case errorClass_type_resource:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_resource), 3); break; }
                case errorClass_type_service:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_service), 4); break; }
                case errorClass_type_service_preempt:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_service_preempt), 5); break; }
                case errorClass_type_time_resolution:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_time_resolution), 6); break; }
                case errorClass_type_access:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_access), 7); break; }
                case errorClass_type_initiate:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_initiate), 8); break; }
                case errorClass_type_conclude:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_conclude), 9); break; }
                case errorClass_type_cancel:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_cancel), 10); break; }
                case errorClass_type_file:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_file), 11); break; }
                case errorClass_type_others:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , errorClass_type_others), 12); break; }
                default:{}
            }
        }

        template<> void ServiceError::errorClass_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_vmd_state), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_application_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_definition), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_resource), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_service), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_service_preempt), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_time_resolution), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_access), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_initiate), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_conclude), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_cancel), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_file), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , errorClass_type_others), 12)) return; else free(); break;}
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

 


        template<> void ServiceError::serviceSpecificInfo_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case serviceSpecificInfo_type_obtainFile:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Error > (false , serviceSpecificInfo_type_obtainFile), 0); break; }
                case serviceSpecificInfo_type_start:  {BOOST_ASN_IMPLICIT_TAG(value<Start_Error > (false , serviceSpecificInfo_type_start), 1); break; }
                case serviceSpecificInfo_type_stop:  {BOOST_ASN_IMPLICIT_TAG(value<Stop_Error > (false , serviceSpecificInfo_type_stop), 2); break; }
                case serviceSpecificInfo_type_resume:  {BOOST_ASN_IMPLICIT_TAG(value<Resume_Error > (false , serviceSpecificInfo_type_resume), 3); break; }
                case serviceSpecificInfo_type_reset:  {BOOST_ASN_IMPLICIT_TAG(value<Reset_Error > (false , serviceSpecificInfo_type_reset), 4); break; }
                case serviceSpecificInfo_type_deleteVariableAccess:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Error > (false , serviceSpecificInfo_type_deleteVariableAccess), 5); break; }
                case serviceSpecificInfo_type_deleteNamedVariableList:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Error > (false , serviceSpecificInfo_type_deleteNamedVariableList), 6); break; }
                case serviceSpecificInfo_type_deleteNamedType:  {BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Error > (false , serviceSpecificInfo_type_deleteNamedType), 7); break; }
                case serviceSpecificInfo_type_defineEventEnrollment_Error:  {BOOST_ASN_CHOICE_TAG(value<DefineEventEnrollment_Error > (false , serviceSpecificInfo_type_defineEventEnrollment_Error), 8); break; }
                case serviceSpecificInfo_type_fileRename:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Error > (false , serviceSpecificInfo_type_fileRename), 9); break; }
                case serviceSpecificInfo_type_additionalService:  {BOOST_ASN_CHOICE_TAG(value<AdditionalService_Error > (false , serviceSpecificInfo_type_additionalService), 10); break; }
                case serviceSpecificInfo_type_changeAccessControl:  {BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Error > (false , serviceSpecificInfo_type_changeAccessControl), 11); break; }
                default:{}
            }
        }

        template<> void ServiceError::serviceSpecificInfo_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Error > (true , serviceSpecificInfo_type_obtainFile), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Start_Error > (true , serviceSpecificInfo_type_start), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Stop_Error > (true , serviceSpecificInfo_type_stop), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Resume_Error > (true , serviceSpecificInfo_type_resume), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<Reset_Error > (true , serviceSpecificInfo_type_reset), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteVariableAccess_Error > (true , serviceSpecificInfo_type_deleteVariableAccess), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedVariableList_Error > (true , serviceSpecificInfo_type_deleteNamedVariableList), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<DeleteNamedType_Error > (true , serviceSpecificInfo_type_deleteNamedType), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_CHOICE_TAG(value<DefineEventEnrollment_Error > (true , serviceSpecificInfo_type_defineEventEnrollment_Error), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Error > (true , serviceSpecificInfo_type_fileRename), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_CHOICE_TAG(value<AdditionalService_Error > (true , serviceSpecificInfo_type_additionalService), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<ChangeAccessControl_Error > (true , serviceSpecificInfo_type_changeAccessControl), 11)) return; else free(); break;}
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

 

        template<> void ServiceError::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(errorClass, 0);
            BOOST_ASN_IMPLICIT_TAG(additionalCode, 1);
            BOOST_ASN_IMPLICIT_TAG(additionalDescription, 2);
            BOOST_ASN_EXPLICIT_TAG(serviceSpecificInfo, 3);
        }

        template<> void ServiceError::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(errorClass, 0);
            BOOST_ASN_IMPLICIT_TAG(additionalCode, 1);
            BOOST_ASN_IMPLICIT_TAG(additionalDescription, 2);
            BOOST_ASN_EXPLICIT_TAG(serviceSpecificInfo, 3);
        }

 
        // choice AdditionalService-Error

        template<> void AdditionalService_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AdditionalService_Error_defineEcl:  {BOOST_ASN_CHOICE_TAG(value<DefineEventConditionList_Error > (false , AdditionalService_Error_defineEcl), 0); break; }
                case AdditionalService_Error_addECLReference:  {BOOST_ASN_CHOICE_TAG(value<AddEventConditionListReference_Error > (false , AdditionalService_Error_addECLReference), 1); break; }
                case AdditionalService_Error_removeECLReference:  {BOOST_ASN_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (false , AdditionalService_Error_removeECLReference), 2); break; }
                case AdditionalService_Error_initiateUC:  {BOOST_ASN_CHOICE_TAG(value<InitiateUnitControl_Error > (false , AdditionalService_Error_initiateUC), 3); break; }
                case AdditionalService_Error_startUC:  {BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Error > (false , AdditionalService_Error_startUC), 4); break; }
                case AdditionalService_Error_stopUC:  {BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Error > (false , AdditionalService_Error_stopUC), 5); break; }
                case AdditionalService_Error_deleteUC:  {BOOST_ASN_CHOICE_TAG(value<DeleteUnitControl_Error > (false , AdditionalService_Error_deleteUC), 6); break; }
                case AdditionalService_Error_loadUCFromFile:  {BOOST_ASN_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (false , AdditionalService_Error_loadUCFromFile), 7); break; }
                default:{}
            }
        }

        template<> void AdditionalService_Error::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<DefineEventConditionList_Error > (true , AdditionalService_Error_defineEcl), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<AddEventConditionListReference_Error > (true , AdditionalService_Error_addECLReference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (true , AdditionalService_Error_removeECLReference), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_CHOICE_TAG(value<InitiateUnitControl_Error > (true , AdditionalService_Error_initiateUC), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<StartUnitControl_Error > (true , AdditionalService_Error_startUC), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<StopUnitControl_Error > (true , AdditionalService_Error_stopUC), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_CHOICE_TAG(value<DeleteUnitControl_Error > (true , AdditionalService_Error_deleteUC), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (true , AdditionalService_Error_loadUCFromFile), 7)) return; else free(); break;}
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

 
    const int maxIdentifier = 32;

        // choice ObjectName


        template<> void ObjectName::domain_specific_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(domainID);
            BOOST_ASN_BIND_TAG(itemID);
        }

        template<> void ObjectName::domain_specific_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(domainID);
            BOOST_ASN_BIND_TAG(itemID);
        }

 

        template<> void ObjectName::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ObjectName_vmd_specific:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , ObjectName_vmd_specific), 0); break; }
                case ObjectName_domain_specific:  {BOOST_ASN_IMPLICIT_TAG(value<domain_specific_type > (false , ObjectName_domain_specific), 1); break; }
                case ObjectName_aa_specific:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , ObjectName_aa_specific), 2); break; }
                default:{}
            }
        }

        template<> void ObjectName::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , ObjectName_vmd_specific), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<domain_specific_type > (true , ObjectName_domain_specific), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , ObjectName_aa_specific), 2)) return; else free(); break;}
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

 
        // choice ObjectClass
    const int ObjectClass::basicObjectClass_namedVariable = 0;
    const int ObjectClass::basicObjectClass_scatteredAccess = 1;
    const int ObjectClass::basicObjectClass_namedVariableList = 2;
    const int ObjectClass::basicObjectClass_namedType = 3;
    const int ObjectClass::basicObjectClass_semaphore = 4;
    const int ObjectClass::basicObjectClass_eventCondition = 5;
    const int ObjectClass::basicObjectClass_eventAction = 6;
    const int ObjectClass::basicObjectClass_eventEnrollment = 7;
    const int ObjectClass::basicObjectClass_journal = 8;
    const int ObjectClass::basicObjectClass_domain = 9;
    const int ObjectClass::basicObjectClass_programInvocation = 10;
    const int ObjectClass::basicObjectClass_operatorStation = 11;
    const int ObjectClass::basicObjectClass_dataExchange = 12;
    const int ObjectClass::basicObjectClass_accessControlList = 13;

    const int ObjectClass::csObjectClass_eventConditionList = 0;
    const int ObjectClass::csObjectClass_unitControl = 1;


        template<> void ObjectClass::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ObjectClass_basicObjectClass:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , ObjectClass_basicObjectClass), 0); break; }
                case ObjectClass_csObjectClass:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , ObjectClass_csObjectClass), 1); break; }
                default:{}
            }
        }

        template<> void ObjectClass::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , ObjectClass_basicObjectClass), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , ObjectClass_csObjectClass), 1)) return; else free(); break;}
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

 
        // sequence Initiate-RequestPDU


        template<> void Initiate_RequestPDU::initRequestDetail_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(proposedVersionNumber, 0);
            BOOST_ASN_IMPLICIT_TAG(proposedParameterCBB, 1);
            BOOST_ASN_IMPLICIT_TAG(servicesSupportedCalling, 2);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(additionalSupportedCalling, 3);
            BOOST_ASN_IMPLICIT_TAG(additionalCbbSupportedCalling, 4);
            BOOST_ASN_IMPLICIT_TAG(privilegeClassIdentityCalling, 5);
        }

        template<> void Initiate_RequestPDU::initRequestDetail_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(proposedVersionNumber, 0);
            BOOST_ASN_IMPLICIT_TAG(proposedParameterCBB, 1);
            BOOST_ASN_IMPLICIT_TAG(servicesSupportedCalling, 2);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(additionalSupportedCalling, 3);
            BOOST_ASN_IMPLICIT_TAG(additionalCbbSupportedCalling, 4);
            BOOST_ASN_IMPLICIT_TAG(privilegeClassIdentityCalling, 5);
        }

 

        template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(localDetailCalling, 0);
            BOOST_ASN_IMPLICIT_TAG(proposedMaxServOutstandingCalling, 1);
            BOOST_ASN_IMPLICIT_TAG(proposedMaxServOutstandingCalled, 2);
            BOOST_ASN_IMPLICIT_TAG(proposedDataStructureNestingLevel, 3);
            BOOST_ASN_IMPLICIT_TAG(initRequestDetail, 4);
        }

        template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(localDetailCalling, 0);
            BOOST_ASN_IMPLICIT_TAG(proposedMaxServOutstandingCalling, 1);
            BOOST_ASN_IMPLICIT_TAG(proposedMaxServOutstandingCalled, 2);
            BOOST_ASN_IMPLICIT_TAG(proposedDataStructureNestingLevel, 3);
            BOOST_ASN_IMPLICIT_TAG(initRequestDetail, 4);
        }

 
        // sequence Initiate-ResponsePDU


        template<> void Initiate_ResponsePDU::initResponseDetail_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(negotiatedVersionNumber, 0);
            BOOST_ASN_IMPLICIT_TAG(negotiatedParameterCBB, 1);
            BOOST_ASN_IMPLICIT_TAG(servicesSupportedCalled, 2);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(additionalSupportedCalled, 3);
            BOOST_ASN_IMPLICIT_TAG(additionalCbbSupportedCalled, 4);
            BOOST_ASN_IMPLICIT_TAG(privilegeClassIdentityCalled, 5);
        }

        template<> void Initiate_ResponsePDU::initResponseDetail_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(negotiatedVersionNumber, 0);
            BOOST_ASN_IMPLICIT_TAG(negotiatedParameterCBB, 1);
            BOOST_ASN_IMPLICIT_TAG(servicesSupportedCalled, 2);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(additionalSupportedCalled, 3);
            BOOST_ASN_IMPLICIT_TAG(additionalCbbSupportedCalled, 4);
            BOOST_ASN_IMPLICIT_TAG(privilegeClassIdentityCalled, 5);
        }

 

        template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(localDetailCalled, 0);
            BOOST_ASN_IMPLICIT_TAG(negotiatedMaxServOutstandingCalling, 1);
            BOOST_ASN_IMPLICIT_TAG(negotiatedMaxServOutstandingCalled, 2);
            BOOST_ASN_IMPLICIT_TAG(negotiatedDataStructureNestingLevel, 3);
            BOOST_ASN_IMPLICIT_TAG(initResponseDetail, 4);
        }

        template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(localDetailCalled, 0);
            BOOST_ASN_IMPLICIT_TAG(negotiatedMaxServOutstandingCalling, 1);
            BOOST_ASN_IMPLICIT_TAG(negotiatedMaxServOutstandingCalled, 2);
            BOOST_ASN_IMPLICIT_TAG(negotiatedDataStructureNestingLevel, 3);
            BOOST_ASN_IMPLICIT_TAG(initResponseDetail, 4);
        }

 
        // sequence Cancel-ErrorPDU

        template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(originalInvokeID, 0);
            BOOST_ASN_IMPLICIT_TAG(serviceError, 1);
        }

        template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(originalInvokeID, 0);
            BOOST_ASN_IMPLICIT_TAG(serviceError, 1);
        }

 
        // sequence RejectPDU

    const int RejectPDU::rejectReason_type::confirmed_requestPDU_other = 0;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_unrecognized_service = 1;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_unrecognized_modifier = 2;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_invalid_invokeID = 3;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_invalid_argument = 4;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_invalid_modifier = 5;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_max_serv_outstanding_exceeded = 6;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_max_recursion_exceeded = 8;
    const int RejectPDU::rejectReason_type::confirmed_requestPDU_value_out_of_range = 9;

    const int RejectPDU::rejectReason_type::confirmed_responsePDU_other = 0;
    const int RejectPDU::rejectReason_type::confirmed_responsePDU_unrecognized_service = 1;
    const int RejectPDU::rejectReason_type::confirmed_responsePDU_invalid_invokeID = 2;
    const int RejectPDU::rejectReason_type::confirmed_responsePDU_invalid_result = 3;
    const int RejectPDU::rejectReason_type::confirmed_responsePDU_max_recursion_exceeded = 5;
    const int RejectPDU::rejectReason_type::confirmed_responsePDU_value_out_of_range = 6;

    const int RejectPDU::rejectReason_type::confirmed_errorPDU_other = 0;
    const int RejectPDU::rejectReason_type::confirmed_errorPDU_unrecognized_service = 1;
    const int RejectPDU::rejectReason_type::confirmed_errorPDU_invalid_invokeID = 2;
    const int RejectPDU::rejectReason_type::confirmed_errorPDU_invalid_serviceError = 3;
    const int RejectPDU::rejectReason_type::confirmed_errorPDU_value_out_of_range = 4;

    const int RejectPDU::rejectReason_type::unconfirmedPDU_other = 0;
    const int RejectPDU::rejectReason_type::unconfirmedPDU_unrecognized_service = 1;
    const int RejectPDU::rejectReason_type::unconfirmedPDU_invalid_argument = 2;
    const int RejectPDU::rejectReason_type::unconfirmedPDU_max_recursion_exceeded = 3;
    const int RejectPDU::rejectReason_type::unconfirmedPDU_value_out_of_range = 4;

    const int RejectPDU::rejectReason_type::pdu_error_unknown_pdu_type = 0;
    const int RejectPDU::rejectReason_type::pdu_error_invalid_pdu = 1;
    const int RejectPDU::rejectReason_type::pdu_error_illegal_acse_mapping = 2;

    const int RejectPDU::rejectReason_type::cancel_requestPDU_other = 0;
    const int RejectPDU::rejectReason_type::cancel_requestPDU_invalid_invokeID = 1;

    const int RejectPDU::rejectReason_type::cancel_responsePDU_other = 0;
    const int RejectPDU::rejectReason_type::cancel_responsePDU_invalid_invokeID = 1;

    const int RejectPDU::rejectReason_type::cancel_errorPDU_other = 0;
    const int RejectPDU::rejectReason_type::cancel_errorPDU_invalid_invokeID = 1;
    const int RejectPDU::rejectReason_type::cancel_errorPDU_invalid_serviceError = 2;
    const int RejectPDU::rejectReason_type::cancel_errorPDU_value_out_of_range = 3;

    const int RejectPDU::rejectReason_type::conclude_requestPDU_other = 0;
    const int RejectPDU::rejectReason_type::conclude_requestPDU_invalid_argument = 1;

    const int RejectPDU::rejectReason_type::conclude_responsePDU_other = 0;
    const int RejectPDU::rejectReason_type::conclude_responsePDU_invalid_result = 1;

    const int RejectPDU::rejectReason_type::conclude_errorPDU_other = 0;
    const int RejectPDU::rejectReason_type::conclude_errorPDU_invalid_serviceError = 1;
    const int RejectPDU::rejectReason_type::conclude_errorPDU_value_out_of_range = 2;


        template<> void RejectPDU::rejectReason_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case rejectReason_type_confirmed_requestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_confirmed_requestPDU), 1); break; }
                case rejectReason_type_confirmed_responsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_confirmed_responsePDU), 2); break; }
                case rejectReason_type_confirmed_errorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_confirmed_errorPDU), 3); break; }
                case rejectReason_type_unconfirmedPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_unconfirmedPDU), 4); break; }
                case rejectReason_type_pdu_error:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_pdu_error), 5); break; }
                case rejectReason_type_cancel_requestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_cancel_requestPDU), 6); break; }
                case rejectReason_type_cancel_responsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_cancel_responsePDU), 7); break; }
                case rejectReason_type_cancel_errorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_cancel_errorPDU), 8); break; }
                case rejectReason_type_conclude_requestPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_conclude_requestPDU), 9); break; }
                case rejectReason_type_conclude_responsePDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_conclude_responsePDU), 10); break; }
                case rejectReason_type_conclude_errorPDU:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , rejectReason_type_conclude_errorPDU), 11); break; }
                default:{}
            }
        }

        template<> void RejectPDU::rejectReason_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_confirmed_requestPDU), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_confirmed_responsePDU), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_confirmed_errorPDU), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_unconfirmedPDU), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_pdu_error), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_cancel_requestPDU), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_cancel_responsePDU), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_cancel_errorPDU), 8)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_conclude_requestPDU), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_conclude_responsePDU), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , rejectReason_type_conclude_errorPDU), 11)) return; else free(); break;}
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

 

        template<> void RejectPDU::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(originalInvokeID, 0);
            BOOST_ASN_CHOICE(rejectReason);
        }

        template<> void RejectPDU::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(originalInvokeID, 0);
            BOOST_ASN_CHOICE(rejectReason);
        }

 
        // sequence DefineAccessControlList-Request


        template<> void DefineAccessControlList_Request::accessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(readAccessCondition, 0);
            BOOST_ASN_CHOICE_TAG(storeAccessCondition, 1);
            BOOST_ASN_CHOICE_TAG(writeAccessCondition, 2);
            BOOST_ASN_CHOICE_TAG(loadAccessCondition, 3);
            BOOST_ASN_CHOICE_TAG(executeAccessCondition, 4);
            BOOST_ASN_CHOICE_TAG(deleteAccessCondition, 5);
            BOOST_ASN_CHOICE_TAG(editAccessCondition, 6);
        }

        template<> void DefineAccessControlList_Request::accessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(readAccessCondition, 0);
            BOOST_ASN_CHOICE_TAG(storeAccessCondition, 1);
            BOOST_ASN_CHOICE_TAG(writeAccessCondition, 2);
            BOOST_ASN_CHOICE_TAG(loadAccessCondition, 3);
            BOOST_ASN_CHOICE_TAG(executeAccessCondition, 4);
            BOOST_ASN_CHOICE_TAG(deleteAccessCondition, 5);
            BOOST_ASN_CHOICE_TAG(editAccessCondition, 6);
        }

 

        template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControlListName, 0);
            BOOST_ASN_IMPLICIT_TAG(accessControlListElements, 1);
        }

        template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControlListName, 0);
            BOOST_ASN_IMPLICIT_TAG(accessControlListElements, 1);
        }

 
        // choice GetAccessControlListAttributes-Request


        template<> void GetAccessControlListAttributes_Request::namedObject_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_CHOICE_TAG(objectName, 1);
        }

        template<> void GetAccessControlListAttributes_Request::namedObject_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_CHOICE_TAG(objectName, 1);
        }

 

        template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case GetAccessControlListAttributes_Request_accessControlListName:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , GetAccessControlListAttributes_Request_accessControlListName), 0); break; }
                case GetAccessControlListAttributes_Request_vMD:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , GetAccessControlListAttributes_Request_vMD), 1); break; }
                case GetAccessControlListAttributes_Request_namedObject:  {BOOST_ASN_IMPLICIT_TAG(value<namedObject_type > (false , GetAccessControlListAttributes_Request_namedObject), 2); break; }
                default:{}
            }
        }

        template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , GetAccessControlListAttributes_Request_accessControlListName), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , GetAccessControlListAttributes_Request_vMD), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<namedObject_type > (true , GetAccessControlListAttributes_Request_namedObject), 2)) return; else free(); break;}
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

 
        // sequence GetAccessControlListAttributes-Response


        template<> void GetAccessControlListAttributes_Response::accessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(readAccessCondition, 0);
            BOOST_ASN_CHOICE_TAG(storeAccessCondition, 1);
            BOOST_ASN_CHOICE_TAG(writeAccessCondition, 2);
            BOOST_ASN_CHOICE_TAG(loadAccessCondition, 3);
            BOOST_ASN_CHOICE_TAG(executeAccessCondition, 4);
            BOOST_ASN_CHOICE_TAG(deleteAccessCondition, 5);
            BOOST_ASN_CHOICE_TAG(editAccessCondition, 6);
        }

        template<> void GetAccessControlListAttributes_Response::accessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(readAccessCondition, 0);
            BOOST_ASN_CHOICE_TAG(storeAccessCondition, 1);
            BOOST_ASN_CHOICE_TAG(writeAccessCondition, 2);
            BOOST_ASN_CHOICE_TAG(loadAccessCondition, 3);
            BOOST_ASN_CHOICE_TAG(executeAccessCondition, 4);
            BOOST_ASN_CHOICE_TAG(deleteAccessCondition, 5);
            BOOST_ASN_CHOICE_TAG(editAccessCondition, 6);
        }

 


        template<> void GetAccessControlListAttributes_Response::references_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_IMPLICIT_TAG(objectCount, 1);
        }

        template<> void GetAccessControlListAttributes_Response::references_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_IMPLICIT_TAG(objectCount, 1);
        }

 

        template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(name, 0);
            BOOST_ASN_IMPLICIT_TAG(accessControlListElements, 1);
            BOOST_ASN_IMPLICIT_TAG(vMDuse, 2);
            BOOST_ASN_IMPLICIT_TAG(references, 3);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 4);
        }

        template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(name, 0);
            BOOST_ASN_IMPLICIT_TAG(accessControlListElements, 1);
            BOOST_ASN_IMPLICIT_TAG(vMDuse, 2);
            BOOST_ASN_IMPLICIT_TAG(references, 3);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 4);
        }

 
        // sequence ReportAccessControlledObjects-Request

        template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 0);
            BOOST_ASN_CHOICE_TAG(objectClass, 1);
            BOOST_ASN_CHOICE_TAG(continueAfter, 2);
        }

        template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 0);
            BOOST_ASN_CHOICE_TAG(objectClass, 1);
            BOOST_ASN_CHOICE_TAG(continueAfter, 2);
        }

 
        // sequence ReportAccessControlledObjects-Response

        template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfNames, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfNames, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence ChangeAccessControl-Request




        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case objectScope_type_specific:  {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , objectScope_type_specific), 0); break; }
                case objectScope_type_aa_specific:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_aa_specific), 1); break; }
                case objectScope_type_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , objectScope_type_domain), 2); break; }
                case objectScope_type_vmd:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_vmd), 3); break; }
                default:{}
            }
        }

        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , objectScope_type_specific), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_aa_specific), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , objectScope_type_domain), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_vmd), 3)) return; else free(); break;}
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

 

        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_EXPLICIT_TAG(objectScope, 1);
        }

        template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_EXPLICIT_TAG(objectScope, 1);
        }

 

        template<> void ChangeAccessControl_Request::scopeOfChange_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case scopeOfChange_type_vMDOnly:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , scopeOfChange_type_vMDOnly), 0); break; }
                case scopeOfChange_type_listOfObjects:  {BOOST_ASN_IMPLICIT_TAG(value<listOfObjects_type > (false , scopeOfChange_type_listOfObjects), 1); break; }
                default:{}
            }
        }

        template<> void ChangeAccessControl_Request::scopeOfChange_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , scopeOfChange_type_vMDOnly), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<listOfObjects_type > (true , scopeOfChange_type_listOfObjects), 1)) return; else free(); break;}
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

 

        template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(scopeOfChange);
            BOOST_ASN_IMPLICIT_TAG(accessControlListName, 2);
        }

        template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(scopeOfChange);
            BOOST_ASN_IMPLICIT_TAG(accessControlListName, 2);
        }

 
        // sequence ChangeAccessControl-Response

        template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberChanged, 1);
        }

        template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberChanged, 1);
        }

 
        // sequence StatusResponse
    const int StatusResponse::vmdLogicalStatus_state_changes_allowed = 0;
    const int StatusResponse::vmdLogicalStatus_no_state_changes_allowed = 1;
    const int StatusResponse::vmdLogicalStatus_limited_services_permitted = 2;
    const int StatusResponse::vmdLogicalStatus_support_services_allowed = 3;

    const int StatusResponse::vmdPhysicalStatus_operational = 0;
    const int StatusResponse::vmdPhysicalStatus_partially_operational = 1;
    const int StatusResponse::vmdPhysicalStatus_inoperable = 2;
    const int StatusResponse::vmdPhysicalStatus_needs_commissioning = 3;


        template<> void StatusResponse::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(vmdLogicalStatus, 0);
            BOOST_ASN_IMPLICIT_TAG(vmdPhysicalStatus, 1);
            BOOST_ASN_IMPLICIT_TAG(localDetail, 2);
        }

        template<> void StatusResponse::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(vmdLogicalStatus, 0);
            BOOST_ASN_IMPLICIT_TAG(vmdPhysicalStatus, 1);
            BOOST_ASN_IMPLICIT_TAG(localDetail, 2);
        }

 
        // choice CS-Status-Response



        template<> void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case selectedProgramInvocation_type_programInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , selectedProgramInvocation_type_programInvocation), 3); break; }
                case selectedProgramInvocation_type_noneSelected:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , selectedProgramInvocation_type_noneSelected), 4); break; }
                default:{}
            }
        }

        template<> void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , selectedProgramInvocation_type_programInvocation), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , selectedProgramInvocation_type_noneSelected), 4)) return; else free(); break;}
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

 

        template<> void CS_Status_Response::fullResponse_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(operationState, 0);
            BOOST_ASN_IMPLICIT_TAG(extendedStatus, 1);
            BOOST_ASN_IMPLICIT_TAG(extendedStatusMask, 2);
            BOOST_ASN_CHOICE(selectedProgramInvocation);
        }

        template<> void CS_Status_Response::fullResponse_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(operationState, 0);
            BOOST_ASN_IMPLICIT_TAG(extendedStatus, 1);
            BOOST_ASN_IMPLICIT_TAG(extendedStatusMask, 2);
            BOOST_ASN_CHOICE(selectedProgramInvocation);
        }

 

        template<> void CS_Status_Response::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_Status_Response_fullResponse:  {BOOST_ASN_BIND_TAG(value<fullResponse_type > (false , CS_Status_Response_fullResponse)); break; }
                case CS_Status_Response_noExtraResponse:  {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_Status_Response_noExtraResponse)); break; }
                default:{}
            }
        }

        template<> void CS_Status_Response::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<fullResponse_type > (true , CS_Status_Response_fullResponse))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , CS_Status_Response_noExtraResponse))) return; else free();
                }
            }
        }

 
    const int OperationState_idle = 0;
    const int OperationState_loaded = 1;
    const int OperationState_ready = 2;
    const int OperationState_executing = 3;
    const int OperationState_motion_paused = 4;
    const int OperationState_manualInterventionRequired = 5;

    const bitstring_type ExtendedStatus_safetyInterlocksViolated = bitstring_type(true, 0);
    const bitstring_type ExtendedStatus_anyPhysicalResourcePowerOn = bitstring_type(true, 1);
    const bitstring_type ExtendedStatus_allPhysicalResourcesCalibrated = bitstring_type(true, 2);
    const bitstring_type ExtendedStatus_localControl = bitstring_type(true, 3);

        // sequence GetNameList-Request


        template<> void GetNameList_Request::objectScope_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case objectScope_type_vmdSpecific:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_vmdSpecific), 0); break; }
                case objectScope_type_domainSpecific:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , objectScope_type_domainSpecific), 1); break; }
                case objectScope_type_aaSpecific:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , objectScope_type_aaSpecific), 2); break; }
                default:{}
            }
        }

        template<> void GetNameList_Request::objectScope_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_vmdSpecific), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , objectScope_type_domainSpecific), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , objectScope_type_aaSpecific), 2)) return; else free(); break;}
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

 

        template<> void GetNameList_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_EXPLICIT_TAG(objectScope, 1);
            BOOST_ASN_IMPLICIT_TAG(continueAfter, 2);
        }

        template<> void GetNameList_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_EXPLICIT_TAG(objectScope, 1);
            BOOST_ASN_IMPLICIT_TAG(continueAfter, 2);
        }

 
        // sequence GetNameList-Response

        template<> void GetNameList_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfIdentifier, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void GetNameList_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfIdentifier, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence Identify-Response

        template<> void Identify_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(vendorName, 0);
            BOOST_ASN_IMPLICIT_TAG(modelName, 1);
            BOOST_ASN_IMPLICIT_TAG(revision, 2);
            BOOST_ASN_IMPLICIT_TAG(listOfAbstractSyntaxes, 3);
        }

        template<> void Identify_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(vendorName, 0);
            BOOST_ASN_IMPLICIT_TAG(modelName, 1);
            BOOST_ASN_IMPLICIT_TAG(revision, 2);
            BOOST_ASN_IMPLICIT_TAG(listOfAbstractSyntaxes, 3);
        }

 
        // sequence Rename-Request

        template<> void Rename_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_CHOICE_TAG(currentName, 1);
            BOOST_ASN_IMPLICIT_TAG(newIdentifier, 2);
        }

        template<> void Rename_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(objectClass, 0);
            BOOST_ASN_CHOICE_TAG(currentName, 1);
            BOOST_ASN_IMPLICIT_TAG(newIdentifier, 2);
        }

 
        // sequence GetCapabilityList-Request

        template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(continueAfter);
        }

        template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(continueAfter);
        }

 
        // sequence GetCapabilityList-Response

        template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence InitiateDownloadSequence-Request

        template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
            BOOST_ASN_IMPLICIT_TAG(sharable, 2);
        }

        template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
            BOOST_ASN_IMPLICIT_TAG(sharable, 2);
        }

 
        // sequence DownloadSegment-Response

        template<> void DownloadSegment_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(loadData);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void DownloadSegment_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(loadData);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // choice LoadData

        template<> void LoadData::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case LoadData_non_coded:  {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , LoadData_non_coded), 0); break; }
                case LoadData_coded:  {BOOST_ASN_BIND_TAG(value<external_type > (false , LoadData_coded)); break; }
                case LoadData_embedded:  {BOOST_ASN_BIND_TAG(value<embeded_type > (false , LoadData_embedded)); break; }
                default:{}
            }
        }

        template<> void LoadData::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , LoadData_non_coded), 0)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<external_type > (true , LoadData_coded))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<embeded_type > (true , LoadData_embedded))) return; else free();
                }
            }
        }

 
        // sequence TerminateDownloadSequence-Request

        template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(discard, 1);
        }

        template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(discard, 1);
        }

 
        // sequence InitiateUploadSequence-Response

        template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(ulsmID, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
        }

        template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(ulsmID, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
        }

 
        // sequence UploadSegment-Response

        template<> void UploadSegment_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(loadData);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void UploadSegment_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(loadData);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence RequestDomainDownload-Request

        template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
            BOOST_ASN_IMPLICIT_TAG(sharable, 2);
            BOOST_ASN_IMPLICIT_TAG(fileName, 4);
        }

        template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
            BOOST_ASN_IMPLICIT_TAG(sharable, 2);
            BOOST_ASN_IMPLICIT_TAG(fileName, 4);
        }

 
        // sequence RequestDomainUpload-Request

        template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
        }

        template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
        }

 
        // sequence LoadDomainContent-Request

        template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
            BOOST_ASN_IMPLICIT_TAG(sharable, 2);
            BOOST_ASN_IMPLICIT_TAG(fileName, 4);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 5);
        }

        template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 1);
            BOOST_ASN_IMPLICIT_TAG(sharable, 2);
            BOOST_ASN_IMPLICIT_TAG(fileName, 4);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 5);
        }

 
        // sequence StoreDomainContent-Request

        template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 2);
        }

        template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 2);
        }

 
        // sequence GetDomainAttributes-Response

        template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 0);
            BOOST_ASN_IMPLICIT_TAG(state, 1);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 2);
            BOOST_ASN_IMPLICIT_TAG(sharable, 3);
            BOOST_ASN_IMPLICIT_TAG(listOfProgramInvocations, 4);
            BOOST_ASN_IMPLICIT_TAG(uploadInProgress, 5);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 6);
        }

        template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfCapabilities, 0);
            BOOST_ASN_IMPLICIT_TAG(state, 1);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 2);
            BOOST_ASN_IMPLICIT_TAG(sharable, 3);
            BOOST_ASN_IMPLICIT_TAG(listOfProgramInvocations, 4);
            BOOST_ASN_IMPLICIT_TAG(uploadInProgress, 5);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 6);
        }

 
        // sequence CreateProgramInvocation-Request

        template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfDomainNames, 1);
            BOOST_ASN_IMPLICIT_TAG(reusable, 2);
            BOOST_ASN_IMPLICIT_TAG(monitorType, 3);
        }

        template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfDomainNames, 1);
            BOOST_ASN_IMPLICIT_TAG(reusable, 2);
            BOOST_ASN_IMPLICIT_TAG(monitorType, 3);
        }

 
    const int CS_CreateProgramInvocation_Request_normal = 0;
    const int CS_CreateProgramInvocation_Request_controlling = 1;
    const int CS_CreateProgramInvocation_Request_controlled = 2;

        // sequence Start-Request


        template<> void Start_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case executionArgument_type_simpleString:  {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString), 1); break; }
                case executionArgument_type_encodedString:  {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break; }
                case executionArgument_type_embeddedString:  {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_embeddedString)); break; }
                default:{}
            }
        }

        template<> void Start_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_embeddedString))) return; else free();
                }
            }
        }

 

        template<> void Start_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_CHOICE(executionArgument);
        }

        template<> void Start_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_CHOICE(executionArgument);
        }

 
        // choice CS-Start-Request


        template<> void CS_Start_Request_impl::controlling_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(startLocation, 0);
            BOOST_ASN_CHOICE_TAG(startCount, 1);
        }

        template<> void CS_Start_Request_impl::controlling_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(startLocation, 0);
            BOOST_ASN_CHOICE_TAG(startCount, 1);
        }

 

        template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_Start_Request_impl_normal:  {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_Start_Request_impl_normal)); break; }
                case CS_Start_Request_impl_controlling:  {BOOST_ASN_BIND_TAG(value<controlling_type > (false , CS_Start_Request_impl_controlling)); break; }
                default:{}
            }
        }

        template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , CS_Start_Request_impl_normal))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<controlling_type > (true , CS_Start_Request_impl_controlling))) return; else free();
                }
            }
        }

 
        // choice StartCount

        template<> void StartCount::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case StartCount_noLimit:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , StartCount_noLimit), 0); break; }
                case StartCount_cycleCount:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , StartCount_cycleCount), 1); break; }
                case StartCount_stepCount:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , StartCount_stepCount), 2); break; }
                default:{}
            }
        }

        template<> void StartCount::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , StartCount_noLimit), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , StartCount_cycleCount), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , StartCount_stepCount), 2)) return; else free(); break;}
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

 
        // sequence Stop-Request

        template<> void Stop_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
        }

        template<> void Stop_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
        }

 
        // sequence Resume-Request


        template<> void Resume_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case executionArgument_type_simpleString:  {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString), 1); break; }
                case executionArgument_type_encodedString:  {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break; }
                case executionArgument_type_enmbeddedString:  {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_enmbeddedString)); break; }
                default:{}
            }
        }

        template<> void Resume_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_enmbeddedString))) return; else free();
                }
            }
        }

 

        template<> void Resume_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_CHOICE(executionArgument);
        }

        template<> void Resume_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_CHOICE(executionArgument);
        }

 
        // choice CS-Resume-Request



        template<> void CS_Resume_Request_impl::controlling_type::modeType_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case modeType_type_continueMode:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , modeType_type_continueMode), 0); break; }
                case modeType_type_changeMode:  {BOOST_ASN_CHOICE_TAG(value<StartCount > (false , modeType_type_changeMode), 1); break; }
                default:{}
            }
        }

        template<> void CS_Resume_Request_impl::controlling_type::modeType_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , modeType_type_continueMode), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<StartCount > (true , modeType_type_changeMode), 1)) return; else free(); break;}
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

 

        template<> void CS_Resume_Request_impl::controlling_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(modeType);
        }

        template<> void CS_Resume_Request_impl::controlling_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(modeType);
        }

 

        template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_Resume_Request_impl_normal:  {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_Resume_Request_impl_normal)); break; }
                case CS_Resume_Request_impl_controlling:  {BOOST_ASN_BIND_TAG(value<controlling_type > (false , CS_Resume_Request_impl_controlling)); break; }
                default:{}
            }
        }

        template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::input_coder& arch){
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
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , CS_Resume_Request_impl_normal))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<controlling_type > (true , CS_Resume_Request_impl_controlling))) return; else free();
                }
            }
        }

 
        // sequence Reset-Request

        template<> void Reset_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
        }

        template<> void Reset_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
        }

 
        // sequence Kill-Request

        template<> void Kill_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
        }

        template<> void Kill_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
        }

 
        // sequence GetProgramInvocationAttributes-Response


        template<> void GetProgramInvocationAttributes_Response::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case executionArgument_type_simpleString:  {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString), 5); break; }
                case executionArgument_type_encodedString:  {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break; }
                case executionArgument_type_enmbeddedString:  {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_enmbeddedString)); break; }
                default:{}
            }
        }

        template<> void GetProgramInvocationAttributes_Response::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString), 5)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_enmbeddedString))) return; else free();
                }
            }
        }

 

        template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(state, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfDomainNames, 1);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 2);
            BOOST_ASN_IMPLICIT_TAG(reusable, 3);
            BOOST_ASN_IMPLICIT_TAG(monitor, 4);
            BOOST_ASN_CHOICE(executionArgument);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 6);
        }

        template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(state, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfDomainNames, 1);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 2);
            BOOST_ASN_IMPLICIT_TAG(reusable, 3);
            BOOST_ASN_IMPLICIT_TAG(monitor, 4);
            BOOST_ASN_CHOICE(executionArgument);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 6);
        }

 
        // sequence CS-GetProgramInvocationAttributes-Response




        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case runningMode_type_freeRunning:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , runningMode_type_freeRunning), 0); break; }
                case runningMode_type_cycleLimited:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , runningMode_type_cycleLimited), 1); break; }
                case runningMode_type_stepLimited:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , runningMode_type_stepLimited), 2); break; }
                default:{}
            }
        }

        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , runningMode_type_freeRunning), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , runningMode_type_cycleLimited), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , runningMode_type_stepLimited), 2)) return; else free(); break;}
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

 

        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlledPI, 0);
            BOOST_ASN_IMPLICIT_TAG(programLocation, 1);
            BOOST_ASN_EXPLICIT_TAG(runningMode, 2);
        }

        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlledPI, 0);
            BOOST_ASN_IMPLICIT_TAG(programLocation, 1);
            BOOST_ASN_EXPLICIT_TAG(runningMode, 2);
        }

 


        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case controlled_type_controllingPI:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , controlled_type_controllingPI), 0); break; }
                case controlled_type_none:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , controlled_type_none), 1); break; }
                default:{}
            }
        }

        template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , controlled_type_controllingPI), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , controlled_type_none), 1)) return; else free(); break;}
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

 

        template<> void CS_GetProgramInvocationAttributes_Response::control_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case control_type_controlling:  {BOOST_ASN_IMPLICIT_TAG(value<controlling_type > (false , control_type_controlling), 0); break; }
                case control_type_controlled:  {BOOST_ASN_EXPLICIT_TAG(value<controlled_type > (false , control_type_controlled), 1); break; }
                case control_type_normal:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , control_type_normal), 2); break; }
                default:{}
            }
        }

        template<> void CS_GetProgramInvocationAttributes_Response::control_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<controlling_type > (true , control_type_controlling), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_EXPLICIT_TAG(value<controlled_type > (true , control_type_controlled), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , control_type_normal), 2)) return; else free(); break;}
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

 

        template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(errorCode, 0);
            BOOST_ASN_EXPLICIT_TAG(control, 1);
        }

        template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(errorCode, 0);
            BOOST_ASN_EXPLICIT_TAG(control, 1);
        }

 
        // sequence Select-Request

        template<> void Select_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlling, 0);
            BOOST_ASN_IMPLICIT_TAG(controlled, 1);
        }

        template<> void Select_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlling, 0);
            BOOST_ASN_IMPLICIT_TAG(controlled, 1);
        }

 
        // sequence AlterProgramInvocationAttributes-Request

        template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 0);
            BOOST_ASN_CHOICE_TAG(startCount, 1);
        }

        template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 0);
            BOOST_ASN_CHOICE_TAG(startCount, 1);
        }

 
        // sequence ReconfigureProgramInvocation-Request

        template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(oldProgramInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(newProgramInvocationName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainsToAdd, 2);
            BOOST_ASN_IMPLICIT_TAG(domainsToRemove, 3);
        }

        template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(oldProgramInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(newProgramInvocationName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainsToAdd, 2);
            BOOST_ASN_IMPLICIT_TAG(domainsToRemove, 3);
        }

 
        // choice ControlElement


        template<> void ControlElement::beginDomainDef_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 1);
            BOOST_ASN_IMPLICIT_TAG(capabilities, 2);
            BOOST_ASN_IMPLICIT_TAG(sharable, 3);
            BOOST_ASN_CHOICE_TAG(loadData, 4);
        }

        template<> void ControlElement::beginDomainDef_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 1);
            BOOST_ASN_IMPLICIT_TAG(capabilities, 2);
            BOOST_ASN_IMPLICIT_TAG(sharable, 3);
            BOOST_ASN_CHOICE_TAG(loadData, 4);
        }

 


        template<> void ControlElement::continueDomainDef_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 1);
            BOOST_ASN_CHOICE_TAG(loadData, 3);
        }

        template<> void ControlElement::continueDomainDef_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domainName, 1);
            BOOST_ASN_CHOICE_TAG(loadData, 3);
        }

 


        template<> void ControlElement::piDefinition_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(piName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfDomains, 1);
            BOOST_ASN_IMPLICIT_TAG(reusable, 2);
            BOOST_ASN_IMPLICIT_TAG(monitorType, 3);
            BOOST_ASN_IMPLICIT_TAG(pIState, 4);
        }

        template<> void ControlElement::piDefinition_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(piName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfDomains, 1);
            BOOST_ASN_IMPLICIT_TAG(reusable, 2);
            BOOST_ASN_IMPLICIT_TAG(monitorType, 3);
            BOOST_ASN_IMPLICIT_TAG(pIState, 4);
        }

 

        template<> void ControlElement::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case ControlElement_beginDomainDef:  {BOOST_ASN_EXPLICIT_TAG(value<beginDomainDef_type > (false , ControlElement_beginDomainDef), 0); break; }
                case ControlElement_continueDomainDef:  {BOOST_ASN_EXPLICIT_TAG(value<continueDomainDef_type > (false , ControlElement_continueDomainDef), 1); break; }
                case ControlElement_endDomainDef:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , ControlElement_endDomainDef), 2); break; }
                case ControlElement_piDefinition:  {BOOST_ASN_IMPLICIT_TAG(value<piDefinition_type > (false , ControlElement_piDefinition), 3); break; }
                default:{}
            }
        }

        template<> void ControlElement::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_EXPLICIT_TAG(value<beginDomainDef_type > (true , ControlElement_beginDomainDef), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_EXPLICIT_TAG(value<continueDomainDef_type > (true , ControlElement_continueDomainDef), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , ControlElement_endDomainDef), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<piDefinition_type > (true , ControlElement_piDefinition), 3)) return; else free(); break;}
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

 
        // choice InitiateUnitControl-Error

        template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case InitiateUnitControl_Error_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , InitiateUnitControl_Error_domain), 0); break; }
                case InitiateUnitControl_Error_programInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , InitiateUnitControl_Error_programInvocation), 1); break; }
                default:{}
            }
        }

        template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , InitiateUnitControl_Error_domain), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , InitiateUnitControl_Error_programInvocation), 1)) return; else free(); break;}
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

 
        // sequence UnitControlLoadSegment-Response

        template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlElements, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlElements, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence UnitControlUpload-Request


        template<> void UnitControlUpload_Request::continueAfter_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case continueAfter_type_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , continueAfter_type_domain), 1); break; }
                case continueAfter_type_ulsmID:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , continueAfter_type_ulsmID), 2); break; }
                case continueAfter_type_programInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , continueAfter_type_programInvocation), 3); break; }
                default:{}
            }
        }

        template<> void UnitControlUpload_Request::continueAfter_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , continueAfter_type_domain), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , continueAfter_type_ulsmID), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , continueAfter_type_programInvocation), 3)) return; else free(); break;}
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

 

        template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_CHOICE(continueAfter);
        }

        template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_CHOICE(continueAfter);
        }

 
        // sequence UnitControlUpload-Response


        template<> void UnitControlUpload_Response::nextElement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case nextElement_type_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , nextElement_type_domain), 1); break; }
                case nextElement_type_ulsmID:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , nextElement_type_ulsmID), 2); break; }
                case nextElement_type_programInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , nextElement_type_programInvocation), 3); break; }
                default:{}
            }
        }

        template<> void UnitControlUpload_Response::nextElement_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , nextElement_type_domain), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , nextElement_type_ulsmID), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , nextElement_type_programInvocation), 3)) return; else free(); break;}
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

 

        template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlElements, 0);
            BOOST_ASN_CHOICE(nextElement);
        }

        template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(controlElements, 0);
            BOOST_ASN_CHOICE(nextElement);
        }

 
        // sequence StartUnitControl-Request


        template<> void StartUnitControl_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case executionArgument_type_simpleString:  {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , executionArgument_type_simpleString), 1); break; }
                case executionArgument_type_encodedString:  {BOOST_ASN_BIND_TAG(value<external_type > (false , executionArgument_type_encodedString)); break; }
                case executionArgument_type_enmbeddedString:  {BOOST_ASN_BIND_TAG(value<embeded_type > (false , executionArgument_type_enmbeddedString)); break; }
                default:{}
            }
        }

        template<> void StartUnitControl_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , executionArgument_type_simpleString), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<external_type > (true , executionArgument_type_encodedString))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<embeded_type > (true , executionArgument_type_enmbeddedString))) return; else free();
                }
            }
        }

 

        template<> void StartUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_CHOICE(executionArgument);
        }

        template<> void StartUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_CHOICE(executionArgument);
        }

 
        // sequence StartUnitControl-Error

        template<> void StartUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(programInvocationState, 1);
        }

        template<> void StartUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(programInvocationState, 1);
        }

 
        // sequence StopUnitControl-Error

        template<> void StopUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(programInvocationState, 1);
        }

        template<> void StopUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationName, 0);
            BOOST_ASN_IMPLICIT_TAG(programInvocationState, 1);
        }

 
        // sequence CreateUnitControl-Request

        template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControl, 0);
            BOOST_ASN_IMPLICIT_TAG(domains, 1);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 2);
        }

        template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControl, 0);
            BOOST_ASN_IMPLICIT_TAG(domains, 1);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 2);
        }

 
        // sequence AddToUnitControl-Request

        template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControl, 0);
            BOOST_ASN_IMPLICIT_TAG(domains, 1);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 2);
        }

        template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControl, 0);
            BOOST_ASN_IMPLICIT_TAG(domains, 1);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 2);
        }

 
        // sequence RemoveFromUnitControl-Request

        template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControl, 0);
            BOOST_ASN_IMPLICIT_TAG(domains, 1);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 2);
        }

        template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControl, 0);
            BOOST_ASN_IMPLICIT_TAG(domains, 1);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 2);
        }

 
        // sequence GetUnitControlAttributes-Response

        template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domains, 0);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 1);
        }

        template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(domains, 0);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 1);
        }

 
        // sequence LoadUnitControlFromFile-Request

        template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 2);
        }

        template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 2);
        }

 
        // choice LoadUnitControlFromFile-Error

        template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case LoadUnitControlFromFile_Error_none:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , LoadUnitControlFromFile_Error_none), 0); break; }
                case LoadUnitControlFromFile_Error_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , LoadUnitControlFromFile_Error_domain), 1); break; }
                case LoadUnitControlFromFile_Error_programInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , LoadUnitControlFromFile_Error_programInvocation), 2); break; }
                default:{}
            }
        }

        template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , LoadUnitControlFromFile_Error_none), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , LoadUnitControlFromFile_Error_domain), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , LoadUnitControlFromFile_Error_programInvocation), 2)) return; else free(); break;}
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

 
        // sequence StoreUnitControlToFile-Request

        template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 2);
        }

        template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unitControlName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileName, 1);
            BOOST_ASN_IMPLICIT_TAG(thirdParty, 2);
        }

 
        // choice DeleteUnitControl-Error

        template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteUnitControl_Error_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteUnitControl_Error_domain), 0); break; }
                case DeleteUnitControl_Error_programInvocation:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteUnitControl_Error_programInvocation), 1); break; }
                default:{}
            }
        }

        template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteUnitControl_Error_domain), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteUnitControl_Error_programInvocation), 1)) return; else free(); break;}
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

 
        // choice TypeSpecification

        template<> void TypeSpecification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case TypeSpecification_typeName:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , TypeSpecification_typeName), 0); break; }
                case TypeSpecification_typeDescription:  {BOOST_ASN_CHOICE(value<MMS_Object_Module_1::TypeDescription > (false , TypeSpecification_typeDescription)); break; }
                default:{}
            }
        }

        template<> void TypeSpecification::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , TypeSpecification_typeName), 0)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true , TypeSpecification_typeDescription))) return; else free();
                }
            }
        }

 



        template<> void AlternateAccess_sequence_of::named_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(componentName, 0);
            BOOST_ASN_CHOICE(access);
        }

        template<> void AlternateAccess_sequence_of::named_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(componentName, 0);
            BOOST_ASN_CHOICE(access);
        }

 

        template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AlternateAccess_sequence_of_unnamed:  {BOOST_ASN_CHOICE(value<AlternateAccessSelection > (false , AlternateAccess_sequence_of_unnamed)); break; }
                case AlternateAccess_sequence_of_named:  {BOOST_ASN_IMPLICIT_TAG(value<named_type > (false , AlternateAccess_sequence_of_named), 5); break; }
                default:{}
            }
        }

        template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<named_type > (true , AlternateAccess_sequence_of_named), 5)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_CHOICE(value<AlternateAccessSelection > (true , AlternateAccess_sequence_of_unnamed))) return; else free();
                }
            }
        }

 
        // choice AlternateAccessSelection




        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(lowIndex, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfElements, 1);
        }

        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(lowIndex, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfElements, 1);
        }

 

        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case accessSelection_type_component:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , accessSelection_type_component), 0); break; }
                case accessSelection_type_index:  {BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (false , accessSelection_type_index), 1); break; }
                case accessSelection_type_indexRange:  {BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (false , accessSelection_type_indexRange), 2); break; }
                case accessSelection_type_allElements:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , accessSelection_type_allElements), 3); break; }
                default:{}
            }
        }

        template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , accessSelection_type_component), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (true , accessSelection_type_index), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (true , accessSelection_type_indexRange), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , accessSelection_type_allElements), 3)) return; else free(); break;}
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

 

        template<> void AlternateAccessSelection::selectAlternateAccess_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(accessSelection);
            BOOST_ASN_BIND_TAG(alternateAccess);
        }

        template<> void AlternateAccessSelection::selectAlternateAccess_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(accessSelection);
            BOOST_ASN_BIND_TAG(alternateAccess);
        }

 



        template<> void AlternateAccessSelection::selectAccess_type::indexRange_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(lowIndex, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfElements, 1);
        }

        template<> void AlternateAccessSelection::selectAccess_type::indexRange_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(lowIndex, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfElements, 1);
        }

 

        template<> void AlternateAccessSelection::selectAccess_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case selectAccess_type_component:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , selectAccess_type_component), 1); break; }
                case selectAccess_type_index:  {BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (false , selectAccess_type_index), 2); break; }
                case selectAccess_type_indexRange:  {BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (false , selectAccess_type_indexRange), 3); break; }
                case selectAccess_type_allElements:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , selectAccess_type_allElements), 4); break; }
                default:{}
            }
        }

        template<> void AlternateAccessSelection::selectAccess_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , selectAccess_type_component), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (true , selectAccess_type_index), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<indexRange_type > (true , selectAccess_type_indexRange), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , selectAccess_type_allElements), 4)) return; else free(); break;}
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

 

        template<> void AlternateAccessSelection::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AlternateAccessSelection_selectAlternateAccess:  {BOOST_ASN_IMPLICIT_TAG(value<selectAlternateAccess_type > (false , AlternateAccessSelection_selectAlternateAccess), 0); break; }
                case AlternateAccessSelection_selectAccess:  {BOOST_ASN_CHOICE(value<selectAccess_type > (false , AlternateAccessSelection_selectAccess)); break; }
                default:{}
            }
        }

        template<> void AlternateAccessSelection::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<selectAlternateAccess_type > (true , AlternateAccessSelection_selectAlternateAccess), 0)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_CHOICE(value<selectAccess_type > (true , AlternateAccessSelection_selectAccess))) return; else free();
                }
            }
        }

 
        // choice AccessResult

        template<> void AccessResult::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AccessResult_failure:  {BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (false , AccessResult_failure), 0); break; }
                case AccessResult_success:  {BOOST_ASN_CHOICE(value<Data > (false , AccessResult_success)); break; }
                default:{}
            }
        }

        template<> void AccessResult::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (true , AccessResult_failure), 0)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_CHOICE(value<Data > (true , AccessResult_success))) return; else free();
                }
            }
        }

 
        // choice Data

        template<> void Data::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Data_array:  {BOOST_ASN_IMPLICIT_TAG(value<array_type > (false , Data_array), 1); break; }
                case Data_structure:  {BOOST_ASN_IMPLICIT_TAG(value<structure_type > (false , Data_structure), 2); break; }
                case Data_boolean:  {BOOST_ASN_IMPLICIT_TAG(value<bool > (false , Data_boolean), 3); break; }
                case Data_bit_string:  {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , Data_bit_string), 4); break; }
                case Data_integer:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , Data_integer), 5); break; }
                case Data_unsignedV:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , Data_unsignedV), 6); break; }
                case Data_floating_point:  {BOOST_ASN_IMPLICIT_TAG(value<FloatingPoint > (false , Data_floating_point), 7); break; }
                case Data_octet_string:  {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , Data_octet_string), 9); break; }
                case Data_visible_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , Data_visible_string), 10); break; }
                case Data_generalized_time:  {BOOST_ASN_IMPLICIT_TAG(value<gentime_type > (false , Data_generalized_time), 11); break; }
                case Data_binary_time:  {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , Data_binary_time), 12); break; }
                case Data_bcd:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , Data_bcd), 13); break; }
                case Data_booleanArray:  {BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (false , Data_booleanArray), 14); break; }
                case Data_objId:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , Data_objId), 15); break; }
                case Data_mMSString:  {BOOST_ASN_IMPLICIT_TAG(value<MMSString > (false , Data_mMSString), 16); break; }
                default:{}
            }
        }

        template<> void Data::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<array_type > (true , Data_array), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<structure_type > (true , Data_structure), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<bool > (true , Data_boolean), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , Data_bit_string), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , Data_integer), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , Data_unsignedV), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<FloatingPoint > (true , Data_floating_point), 7)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , Data_octet_string), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , Data_visible_string), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<gentime_type > (true , Data_generalized_time), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , Data_binary_time), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , Data_bcd), 13)) return; else free(); break;}
                        case 14:  { if (BOOST_ASN_IMPLICIT_TAG(value<bitstring_type > (true , Data_booleanArray), 14)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , Data_objId), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMSString > (true , Data_mMSString), 16)) return; else free(); break;}
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

        // choice VariableAccessSpecification


        template<> void VariableAccessSpecification::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(variableSpecification);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 5);
        }

        template<> void VariableAccessSpecification::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(variableSpecification);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 5);
        }

 

        template<> void VariableAccessSpecification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case VariableAccessSpecification_listOfVariable:  {BOOST_ASN_IMPLICIT_TAG(value<listOfVariable_type > (false , VariableAccessSpecification_listOfVariable), 0); break; }
                case VariableAccessSpecification_variableListName:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , VariableAccessSpecification_variableListName), 1); break; }
                default:{}
            }
        }

        template<> void VariableAccessSpecification::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<listOfVariable_type > (true , VariableAccessSpecification_listOfVariable), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , VariableAccessSpecification_variableListName), 1)) return; else free(); break;}
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

 
        // choice VariableSpecification


        template<> void VariableSpecification::variableDescription_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(address);
            BOOST_ASN_CHOICE(typeSpecification);
        }

        template<> void VariableSpecification::variableDescription_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(address);
            BOOST_ASN_CHOICE(typeSpecification);
        }

 

        template<> void VariableSpecification::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case VariableSpecification_name:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , VariableSpecification_name), 0); break; }
                case VariableSpecification_address:  {BOOST_ASN_CHOICE_TAG(value<MMS_Object_Module_1::Address > (false , VariableSpecification_address), 1); break; }
                case VariableSpecification_variableDescription:  {BOOST_ASN_IMPLICIT_TAG(value<variableDescription_type > (false , VariableSpecification_variableDescription), 2); break; }
                case VariableSpecification_scatteredAccessDescription:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ScatteredAccessDescription > (false , VariableSpecification_scatteredAccessDescription), 3); break; }
                case VariableSpecification_invalidated:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , VariableSpecification_invalidated), 4); break; }
                default:{}
            }
        }

        template<> void VariableSpecification::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , VariableSpecification_name), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<MMS_Object_Module_1::Address > (true , VariableSpecification_address), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<variableDescription_type > (true , VariableSpecification_variableDescription), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ScatteredAccessDescription > (true , VariableSpecification_scatteredAccessDescription), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , VariableSpecification_invalidated), 4)) return; else free(); break;}
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

 
        // sequence Read-Request

        template<> void Read_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(specificationWithResult, 0);
            BOOST_ASN_CHOICE_TAG(variableAccessSpecification, 1);
        }

        template<> void Read_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(specificationWithResult, 0);
            BOOST_ASN_CHOICE_TAG(variableAccessSpecification, 1);
        }

 
        // sequence Read-Response

        template<> void Read_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(variableAccessSpecification, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfAccessResult, 1);
        }

        template<> void Read_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(variableAccessSpecification, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfAccessResult, 1);
        }

 
        // sequence Write-Request

        template<> void Write_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(variableAccessSpecification);
            BOOST_ASN_IMPLICIT_TAG(listOfData, 0);
        }

        template<> void Write_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(variableAccessSpecification);
            BOOST_ASN_IMPLICIT_TAG(listOfData, 0);
        }

 


        template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Write_Response_sequence_of_failure:  {BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (false , Write_Response_sequence_of_failure), 0); break; }
                case Write_Response_sequence_of_success:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , Write_Response_sequence_of_success), 1); break; }
                default:{}
            }
        }

        template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<DataAccessError > (true , Write_Response_sequence_of_failure), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , Write_Response_sequence_of_success), 1)) return; else free(); break;}
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

 
        // sequence InformationReport

        template<> void InformationReport::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(variableAccessSpecification);
            BOOST_ASN_IMPLICIT_TAG(listOfAccessResult, 0);
        }

        template<> void InformationReport::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(variableAccessSpecification);
            BOOST_ASN_IMPLICIT_TAG(listOfAccessResult, 0);
        }

 
        // choice GetVariableAccessAttributes-Request

        template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case GetVariableAccessAttributes_Request_name:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , GetVariableAccessAttributes_Request_name), 0); break; }
                case GetVariableAccessAttributes_Request_address:  {BOOST_ASN_CHOICE_TAG(value<MMS_Object_Module_1::Address > (false , GetVariableAccessAttributes_Request_address), 1); break; }
                default:{}
            }
        }

        template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , GetVariableAccessAttributes_Request_name), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<MMS_Object_Module_1::Address > (true , GetVariableAccessAttributes_Request_address), 1)) return; else free(); break;}
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

 
        // sequence GetVariableAccessAttributes-Response

        template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_CHOICE_TAG(address, 1);
            BOOST_ASN_CHOICE_TAG(typeDescription, 2);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 3);
            BOOST_ASN_IMPLICIT_TAG(meaning, 4);
        }

        template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_CHOICE_TAG(address, 1);
            BOOST_ASN_CHOICE_TAG(typeDescription, 2);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 3);
            BOOST_ASN_IMPLICIT_TAG(meaning, 4);
        }

 
        // sequence DefineNamedVariable-Request

        template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(variableName, 0);
            BOOST_ASN_CHOICE_TAG(address, 1);
            BOOST_ASN_CHOICE_TAG(typeSpecification, 2);
        }

        template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(variableName, 0);
            BOOST_ASN_CHOICE_TAG(address, 1);
            BOOST_ASN_CHOICE_TAG(typeSpecification, 2);
        }

 
        // sequence DeleteVariableAccess-Request
    const int DeleteVariableAccess_Request::scopeOfDelete_specific = 0;
    const int DeleteVariableAccess_Request::scopeOfDelete_aa_specific = 1;
    const int DeleteVariableAccess_Request::scopeOfDelete_domain = 2;
    const int DeleteVariableAccess_Request::scopeOfDelete_vmd = 3;


        template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfDelete, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainName, 2);
        }

        template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfDelete, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainName, 2);
        }

 
        // sequence DeleteVariableAccess-Response

        template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberDeleted, 1);
        }

        template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberDeleted, 1);
        }

 
        // sequence DefineNamedVariableList-Request


        template<> void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(variableSpecification);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 5);
        }

        template<> void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(variableSpecification);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 5);
        }

 

        template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(variableListName);
            BOOST_ASN_IMPLICIT_TAG(listOfVariable, 0);
        }

        template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(variableListName);
            BOOST_ASN_IMPLICIT_TAG(listOfVariable, 0);
        }

 
        // sequence GetNamedVariableListAttributes-Response


        template<> void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(variableSpecification);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 5);
        }

        template<> void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(variableSpecification);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 5);
        }

 

        template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfVariable, 1);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 2);
        }

        template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfVariable, 1);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 2);
        }

 
        // sequence DeleteNamedVariableList-Request
    const int DeleteNamedVariableList_Request::scopeOfDelete_specific = 0;
    const int DeleteNamedVariableList_Request::scopeOfDelete_aa_specific = 1;
    const int DeleteNamedVariableList_Request::scopeOfDelete_domain = 2;
    const int DeleteNamedVariableList_Request::scopeOfDelete_vmd = 3;


        template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfDelete, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfVariableListName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainName, 2);
        }

        template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfDelete, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfVariableListName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainName, 2);
        }

 
        // sequence DeleteNamedVariableList-Response

        template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberDeleted, 1);
        }

        template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberDeleted, 1);
        }

 
        // sequence DefineNamedType-Request

        template<> void DefineNamedType_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(typeName);
            BOOST_ASN_CHOICE(typeSpecification);
        }

        template<> void DefineNamedType_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(typeName);
            BOOST_ASN_CHOICE(typeSpecification);
        }

 
        // sequence GetNamedTypeAttributes-Response

        template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_CHOICE(typeSpecification);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 1);
            BOOST_ASN_IMPLICIT_TAG(meaning, 4);
        }

        template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_CHOICE(typeSpecification);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 1);
            BOOST_ASN_IMPLICIT_TAG(meaning, 4);
        }

 
        // sequence DeleteNamedType-Request
    const int DeleteNamedType_Request::scopeOfDelete_specific = 0;
    const int DeleteNamedType_Request::scopeOfDelete_aa_specific = 1;
    const int DeleteNamedType_Request::scopeOfDelete_domain = 2;
    const int DeleteNamedType_Request::scopeOfDelete_vmd = 3;


        template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfDelete, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfTypeName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainName, 2);
        }

        template<> void DeleteNamedType_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfDelete, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfTypeName, 1);
            BOOST_ASN_IMPLICIT_TAG(domainName, 2);
        }

 
        // sequence DeleteNamedType-Response

        template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberDeleted, 1);
        }

        template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(numberMatched, 0);
            BOOST_ASN_IMPLICIT_TAG(numberDeleted, 1);
        }

 
        // sequence ExchangeData-Request

        template<> void ExchangeData_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(dataExchangeName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfRequestData, 1);
        }

        template<> void ExchangeData_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(dataExchangeName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfRequestData, 1);
        }

 
        // sequence ExchangeData-Response

        template<> void ExchangeData_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfResponseData, 0);
        }

        template<> void ExchangeData_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfResponseData, 0);
        }

 
        // sequence GetDataExchangeAttributes-Response

        template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(inUse, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfRequestTypeDescriptions, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfResponseTypeDescriptions, 2);
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 3);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 4);
        }

        template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(inUse, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfRequestTypeDescriptions, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfResponseTypeDescriptions, 2);
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 3);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 4);
        }

 
        // sequence TakeControl-Request

        template<> void TakeControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(acceptableDelay, 3);
            BOOST_ASN_IMPLICIT_TAG(controlTimeOut, 4);
            BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut, 5);
            BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost, 6);
            BOOST_ASN_IMPLICIT_TAG(applicationToPreempt, 7);
        }

        template<> void TakeControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(acceptableDelay, 3);
            BOOST_ASN_IMPLICIT_TAG(controlTimeOut, 4);
            BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut, 5);
            BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost, 6);
            BOOST_ASN_IMPLICIT_TAG(applicationToPreempt, 7);
        }

 
        // choice TakeControl-Response

        template<> void TakeControl_Response::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case TakeControl_Response_noResult:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TakeControl_Response_noResult), 0); break; }
                case TakeControl_Response_namedToken:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , TakeControl_Response_namedToken), 1); break; }
                default:{}
            }
        }

        template<> void TakeControl_Response::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TakeControl_Response_noResult), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , TakeControl_Response_namedToken), 1)) return; else free(); break;}
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

 
        // sequence RelinquishControl-Request

        template<> void RelinquishControl_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 1);
        }

        template<> void RelinquishControl_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 1);
        }

 
        // sequence DefineSemaphore-Request

        template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfTokens, 1);
        }

        template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfTokens, 1);
        }

 
        // sequence ReportSemaphoreStatus-Response
    const int ReportSemaphoreStatus_Response::classV_token = 0;
    const int ReportSemaphoreStatus_Response::classV_pool = 1;


        template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(classV, 1);
            BOOST_ASN_IMPLICIT_TAG(numberOfTokens, 2);
            BOOST_ASN_IMPLICIT_TAG(numberOfOwnedTokens, 3);
            BOOST_ASN_IMPLICIT_TAG(numberOfHungTokens, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 5);
        }

        template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(classV, 1);
            BOOST_ASN_IMPLICIT_TAG(numberOfTokens, 2);
            BOOST_ASN_IMPLICIT_TAG(numberOfOwnedTokens, 3);
            BOOST_ASN_IMPLICIT_TAG(numberOfHungTokens, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 5);
        }

 
        // sequence ReportPoolSemaphoreStatus-Request

        template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(nameToStartAfter, 1);
        }

        template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(nameToStartAfter, 1);
        }

 
        // sequence ReportPoolSemaphoreStatus-Response


        template<> void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case listOfNamedTokens_type_sequence_of_freeNamedToken:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , listOfNamedTokens_type_sequence_of_freeNamedToken), 0); break; }
                case listOfNamedTokens_type_sequence_of_ownedNamedToken:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , listOfNamedTokens_type_sequence_of_ownedNamedToken), 1); break; }
                case listOfNamedTokens_type_sequence_of_hungNamedToken:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , listOfNamedTokens_type_sequence_of_hungNamedToken), 2); break; }
                default:{}
            }
        }

        template<> void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , listOfNamedTokens_type_sequence_of_freeNamedToken), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , listOfNamedTokens_type_sequence_of_ownedNamedToken), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , listOfNamedTokens_type_sequence_of_hungNamedToken), 2)) return; else free(); break;}
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

 

        template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfNamedTokens, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfNamedTokens, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence ReportSemaphoreEntryStatus-Request
    const int ReportSemaphoreEntryStatus_Request::state_queued = 0;
    const int ReportSemaphoreEntryStatus_Request::state_owner = 1;
    const int ReportSemaphoreEntryStatus_Request::state_hung = 2;


        template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(state, 1);
            BOOST_ASN_IMPLICIT_TAG(entryIDToStartAfter, 2);
        }

        template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(state, 1);
            BOOST_ASN_IMPLICIT_TAG(entryIDToStartAfter, 2);
        }

 
        // sequence ReportSemaphoreEntryStatus-Response

        template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfSemaphoreEntry, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfSemaphoreEntry, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence SemaphoreEntry
    const int SemaphoreEntry::entryClass_simple = 0;
    const int SemaphoreEntry::entryClass_modifier = 1;


        template<> void SemaphoreEntry::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(entryID, 0);
            BOOST_ASN_IMPLICIT_TAG(entryClass, 1);
            BOOST_ASN_EXPLICIT_TAG(applicationReference, 2);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 3);
            BOOST_ASN_IMPLICIT_TAG(priority, 4);
            BOOST_ASN_IMPLICIT_TAG(remainingTimeOut, 5);
            BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut, 6);
            BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost, 7);
        }

        template<> void SemaphoreEntry::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(entryID, 0);
            BOOST_ASN_IMPLICIT_TAG(entryClass, 1);
            BOOST_ASN_EXPLICIT_TAG(applicationReference, 2);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 3);
            BOOST_ASN_IMPLICIT_TAG(priority, 4);
            BOOST_ASN_IMPLICIT_TAG(remainingTimeOut, 5);
            BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut, 6);
            BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost, 7);
        }

 
        // sequence AttachToSemaphore

        template<> void AttachToSemaphore::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(acceptableDelay, 3);
            BOOST_ASN_IMPLICIT_TAG(controlTimeOut, 4);
            BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut, 5);
            BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost, 6);
        }

        template<> void AttachToSemaphore::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(semaphoreName, 0);
            BOOST_ASN_IMPLICIT_TAG(namedToken, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(acceptableDelay, 3);
            BOOST_ASN_IMPLICIT_TAG(controlTimeOut, 4);
            BOOST_ASN_IMPLICIT_TAG(abortOnTimeOut, 5);
            BOOST_ASN_IMPLICIT_TAG(relinquishIfConnectionLost, 6);
        }

 
        // sequence Input-Request

        template<> void Input_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(operatorStationName, 0);
            BOOST_ASN_IMPLICIT_TAG(echo, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfPromptData, 2);
            BOOST_ASN_IMPLICIT_TAG(inputTimeOut, 3);
        }

        template<> void Input_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(operatorStationName, 0);
            BOOST_ASN_IMPLICIT_TAG(echo, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfPromptData, 2);
            BOOST_ASN_IMPLICIT_TAG(inputTimeOut, 3);
        }

 
        // sequence Output-Request

        template<> void Output_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(operatorStationName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfOutputData, 1);
        }

        template<> void Output_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(operatorStationName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfOutputData, 1);
        }

 
        // sequence TriggerEvent-Request

        template<> void TriggerEvent_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(priority, 1);
        }

        template<> void TriggerEvent_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(priority, 1);
        }

 
        // sequence EventNotification




        template<> void EventNotification::actionResult_type::successOrFailure_type::success_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(confirmedServiceResponse);
            BOOST_ASN_CHOICE_TAG(cs_Response_Detail, 79);
        }

        template<> void EventNotification::actionResult_type::successOrFailure_type::success_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(confirmedServiceResponse);
            BOOST_ASN_CHOICE_TAG(cs_Response_Detail, 79);
        }

 


        template<> void EventNotification::actionResult_type::successOrFailure_type::failure_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(modifierPosition, 0);
            BOOST_ASN_IMPLICIT_TAG(serviceError, 1);
        }

        template<> void EventNotification::actionResult_type::successOrFailure_type::failure_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(modifierPosition, 0);
            BOOST_ASN_IMPLICIT_TAG(serviceError, 1);
        }

 

        template<> void EventNotification::actionResult_type::successOrFailure_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case successOrFailure_type_success:  {BOOST_ASN_IMPLICIT_TAG(value<success_type > (false , successOrFailure_type_success), 0); break; }
                case successOrFailure_type_failure:  {BOOST_ASN_IMPLICIT_TAG(value<failure_type > (false , successOrFailure_type_failure), 1); break; }
                default:{}
            }
        }

        template<> void EventNotification::actionResult_type::successOrFailure_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<success_type > (true , successOrFailure_type_success), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<failure_type > (true , successOrFailure_type_failure), 1)) return; else free(); break;}
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

 

        template<> void EventNotification::actionResult_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(eventActionName);
            BOOST_ASN_CHOICE(successOrFailure);
        }

        template<> void EventNotification::actionResult_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(eventActionName);
            BOOST_ASN_CHOICE(successOrFailure);
        }

 

        template<> void EventNotification::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(severity, 2);
            BOOST_ASN_IMPLICIT_TAG(currentState, 3);
            BOOST_ASN_CHOICE_TAG(transitionTime, 4);
            BOOST_ASN_IMPLICIT_TAG(notificationLost, 6);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 7);
            BOOST_ASN_IMPLICIT_TAG(actionResult, 8);
        }

        template<> void EventNotification::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(severity, 2);
            BOOST_ASN_IMPLICIT_TAG(currentState, 3);
            BOOST_ASN_CHOICE_TAG(transitionTime, 4);
            BOOST_ASN_IMPLICIT_TAG(notificationLost, 6);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 7);
            BOOST_ASN_IMPLICIT_TAG(actionResult, 8);
        }

 
        // choice CS-EventNotification

        template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_EventNotification_impl_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , CS_EventNotification_impl_string), 0); break; }
                case CS_EventNotification_impl_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , CS_EventNotification_impl_index), 1); break; }
                case CS_EventNotification_impl_noEnhancement:  {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_EventNotification_impl_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , CS_EventNotification_impl_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , CS_EventNotification_impl_index), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , CS_EventNotification_impl_noEnhancement))) return; else free();
                }
            }
        }

 
        // sequence AcknowledgeEventNotification-Request

        template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_IMPLICIT_TAG(acknowledgedState, 2);
            BOOST_ASN_CHOICE_TAG(timeOfAcknowledgedTransition, 3);
        }

        template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_IMPLICIT_TAG(acknowledgedState, 2);
            BOOST_ASN_CHOICE_TAG(timeOfAcknowledgedTransition, 3);
        }

 
        // sequence GetAlarmSummary-Request
    const int GetAlarmSummary_Request::acknowledgementFilter_not_acked = 0;
    const int GetAlarmSummary_Request::acknowledgementFilter_acked = 1;
    const int GetAlarmSummary_Request::acknowledgementFilter_all = 2;



        template<> void GetAlarmSummary_Request::severityFilter_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mostSevere, 0);
            BOOST_ASN_IMPLICIT_TAG(leastSevere, 1);
        }

        template<> void GetAlarmSummary_Request::severityFilter_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mostSevere, 0);
            BOOST_ASN_IMPLICIT_TAG(leastSevere, 1);
        }

 

        template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(enrollmentsOnly, 0);
            BOOST_ASN_IMPLICIT_TAG(activeAlarmsOnly, 1);
            BOOST_ASN_IMPLICIT_TAG(acknowledgementFilter, 2);
            BOOST_ASN_IMPLICIT_TAG(severityFilter, 3);
            BOOST_ASN_CHOICE_TAG(continueAfter, 5);
        }

        template<> void GetAlarmSummary_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(enrollmentsOnly, 0);
            BOOST_ASN_IMPLICIT_TAG(activeAlarmsOnly, 1);
            BOOST_ASN_IMPLICIT_TAG(acknowledgementFilter, 2);
            BOOST_ASN_IMPLICIT_TAG(severityFilter, 3);
            BOOST_ASN_CHOICE_TAG(continueAfter, 5);
        }

 
        // sequence GetAlarmSummary-Response

        template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfAlarmSummary, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfAlarmSummary, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence AlarmSummary
    const int AlarmSummary::unacknowledgedState_none = 0;
    const int AlarmSummary::unacknowledgedState_active = 1;
    const int AlarmSummary::unacknowledgedState_idle = 2;
    const int AlarmSummary::unacknowledgedState_both = 3;


        template<> void AlarmSummary::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(severity, 1);
            BOOST_ASN_IMPLICIT_TAG(currentState, 2);
            BOOST_ASN_IMPLICIT_TAG(unacknowledgedState, 3);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 4);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 5);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 6);
        }

        template<> void AlarmSummary::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(severity, 1);
            BOOST_ASN_IMPLICIT_TAG(currentState, 2);
            BOOST_ASN_IMPLICIT_TAG(unacknowledgedState, 3);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 4);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 5);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 6);
        }

 
        // choice EN-Additional-Detail

        template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case EN_Additional_Detail_impl_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , EN_Additional_Detail_impl_string), 0); break; }
                case EN_Additional_Detail_impl_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , EN_Additional_Detail_impl_index), 1); break; }
                case EN_Additional_Detail_impl_noEnhancement:  {BOOST_ASN_BIND_TAG(value<null_type > (false , EN_Additional_Detail_impl_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , EN_Additional_Detail_impl_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , EN_Additional_Detail_impl_index), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , EN_Additional_Detail_impl_noEnhancement))) return; else free();
                }
            }
        }

 
        // sequence GetAlarmEnrollmentSummary-Request
    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter_not_acked = 0;
    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter_acked = 1;
    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter_all = 2;



        template<> void GetAlarmEnrollmentSummary_Request::severityFilter_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mostSevere, 0);
            BOOST_ASN_IMPLICIT_TAG(leastSevere, 1);
        }

        template<> void GetAlarmEnrollmentSummary_Request::severityFilter_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mostSevere, 0);
            BOOST_ASN_IMPLICIT_TAG(leastSevere, 1);
        }

 

        template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(enrollmentsOnly, 0);
            BOOST_ASN_IMPLICIT_TAG(activeAlarmsOnly, 1);
            BOOST_ASN_IMPLICIT_TAG(acknowledgementFilter, 2);
            BOOST_ASN_IMPLICIT_TAG(severityFilter, 3);
            BOOST_ASN_CHOICE_TAG(continueAfter, 5);
        }

        template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(enrollmentsOnly, 0);
            BOOST_ASN_IMPLICIT_TAG(activeAlarmsOnly, 1);
            BOOST_ASN_IMPLICIT_TAG(acknowledgementFilter, 2);
            BOOST_ASN_IMPLICIT_TAG(severityFilter, 3);
            BOOST_ASN_CHOICE_TAG(continueAfter, 5);
        }

 
        // sequence GetAlarmEnrollmentSummary-Response

        template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfAlarmEnrollmentSummary, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfAlarmEnrollmentSummary, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence AlarmEnrollmentSummary

        template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 2);
            BOOST_ASN_IMPLICIT_TAG(severity, 3);
            BOOST_ASN_IMPLICIT_TAG(currentState, 4);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 5);
            BOOST_ASN_IMPLICIT_TAG(notificationLost, 6);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 7);
            BOOST_ASN_IMPLICIT_TAG(enrollmentState, 8);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 9);
            BOOST_ASN_CHOICE_TAG(timeActiveAcknowledged, 10);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 11);
            BOOST_ASN_CHOICE_TAG(timeIdleAcknowledged, 12);
        }

        template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 2);
            BOOST_ASN_IMPLICIT_TAG(severity, 3);
            BOOST_ASN_IMPLICIT_TAG(currentState, 4);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 5);
            BOOST_ASN_IMPLICIT_TAG(notificationLost, 6);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 7);
            BOOST_ASN_IMPLICIT_TAG(enrollmentState, 8);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 9);
            BOOST_ASN_CHOICE_TAG(timeActiveAcknowledged, 10);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 11);
            BOOST_ASN_CHOICE_TAG(timeIdleAcknowledged, 12);
        }

 
        // sequence AttachToEventCondition

        template<> void AttachToEventCondition::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(causingTransitions, 2);
            BOOST_ASN_IMPLICIT_TAG(acceptableDelay, 3);
        }

        template<> void AttachToEventCondition::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(causingTransitions, 2);
            BOOST_ASN_IMPLICIT_TAG(acceptableDelay, 3);
        }

 
        // sequence DefineEventCondition-Request

        template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(classV, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(severity, 3);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 4);
            BOOST_ASN_CHOICE_TAG(monitoredVariable, 6);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 7);
        }

        template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(classV, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(severity, 3);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 4);
            BOOST_ASN_CHOICE_TAG(monitoredVariable, 6);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 7);
        }

 
        // choice CS-DefineEventCondition-Request

        template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_DefineEventCondition_Request_impl_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , CS_DefineEventCondition_Request_impl_string), 0); break; }
                case CS_DefineEventCondition_Request_impl_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , CS_DefineEventCondition_Request_impl_index), 1); break; }
                case CS_DefineEventCondition_Request_impl_noEnhancement:  {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_DefineEventCondition_Request_impl_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , CS_DefineEventCondition_Request_impl_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , CS_DefineEventCondition_Request_impl_index), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , CS_DefineEventCondition_Request_impl_noEnhancement))) return; else free();
                }
            }
        }

 
        // choice DeleteEventCondition-Request

        template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteEventCondition_Request_specific:  {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , DeleteEventCondition_Request_specific), 0); break; }
                case DeleteEventCondition_Request_aa_specific:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventCondition_Request_aa_specific), 1); break; }
                case DeleteEventCondition_Request_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteEventCondition_Request_domain), 2); break; }
                case DeleteEventCondition_Request_vmd:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventCondition_Request_vmd), 3); break; }
                default:{}
            }
        }

        template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , DeleteEventCondition_Request_specific), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventCondition_Request_aa_specific), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteEventCondition_Request_domain), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventCondition_Request_vmd), 3)) return; else free(); break;}
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

 
        // sequence GetEventConditionAttributes-Response


        template<> void GetEventConditionAttributes_Response::monitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case monitoredVariable_type_variableReference:  {BOOST_ASN_CHOICE_TAG(value<VariableSpecification > (false , monitoredVariable_type_variableReference), 0); break; }
                case monitoredVariable_type_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , monitoredVariable_type_undefined), 1); break; }
                default:{}
            }
        }

        template<> void GetEventConditionAttributes_Response::monitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<VariableSpecification > (true , monitoredVariable_type_variableReference), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , monitoredVariable_type_undefined), 1)) return; else free(); break;}
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

 

        template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(classV, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(severity, 3);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 4);
            BOOST_ASN_EXPLICIT_TAG(monitoredVariable, 6);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 7);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 8);
        }

        template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(classV, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(severity, 3);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 4);
            BOOST_ASN_EXPLICIT_TAG(monitoredVariable, 6);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 7);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 8);
        }

 
        // sequence CS-GetEventConditionAttributes-Response


        template<> void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case groupPriorityOverride_type_priority:  {BOOST_ASN_IMPLICIT_TAG(value<MMS_Object_Module_1::Priority > (false , groupPriorityOverride_type_priority), 0); break; }
                case groupPriorityOverride_type_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , groupPriorityOverride_type_undefined), 1); break; }
                default:{}
            }
        }

        template<> void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMS_Object_Module_1::Priority > (true , groupPriorityOverride_type_priority), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , groupPriorityOverride_type_undefined), 1)) return; else free(); break;}
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

 


        template<> void CS_GetEventConditionAttributes_Response::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case displayEnhancement_type_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , displayEnhancement_type_string), 0); break; }
                case displayEnhancement_type_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_index), 1); break; }
                case displayEnhancement_type_noEnhancement:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , displayEnhancement_type_noEnhancement), 2); break; }
                default:{}
            }
        }

        template<> void CS_GetEventConditionAttributes_Response::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , displayEnhancement_type_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_index), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , displayEnhancement_type_noEnhancement), 2)) return; else free(); break;}
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

 

        template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(groupPriorityOverride, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfReferencingECL, 1);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 2);
        }

        template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(groupPriorityOverride, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfReferencingECL, 1);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 2);
        }

 
        // sequence ReportEventConditionStatus-Response

        template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(currentState, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfEventEnrollments, 1);
            BOOST_ASN_IMPLICIT_TAG(enabled, 2);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 3);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 4);
        }

        template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(currentState, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfEventEnrollments, 1);
            BOOST_ASN_IMPLICIT_TAG(enabled, 2);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 3);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 4);
        }

 
        // sequence AlterEventConditionMonitoring-Request

        template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(enabled, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 3);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 4);
        }

        template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(enabled, 1);
            BOOST_ASN_IMPLICIT_TAG(priority, 2);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 3);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 4);
        }

 
        // sequence CS-AlterEventConditionMonitoring-Request


        template<> void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case changeDisplay_type_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , changeDisplay_type_string), 0); break; }
                case changeDisplay_type_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , changeDisplay_type_index), 1); break; }
                case changeDisplay_type_noEnhancement:  {BOOST_ASN_EXPLICIT_TAG(value<null_type > (false , changeDisplay_type_noEnhancement), 2); break; }
                default:{}
            }
        }

        template<> void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , changeDisplay_type_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , changeDisplay_type_index), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_EXPLICIT_TAG(value<null_type > (true , changeDisplay_type_noEnhancement), 2)) return; else free(); break;}
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

 

        template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(changeDisplay);
        }

        template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(changeDisplay);
        }

 
        // sequence DefineEventAction-Request

        template<> void DefineEventAction_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventActionName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfModifier, 1);
            BOOST_ASN_CHOICE_TAG(confirmedServiceRequest, 2);
            BOOST_ASN_CHOICE_TAG(cs_extension, 79);
        }

        template<> void DefineEventAction_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventActionName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfModifier, 1);
            BOOST_ASN_CHOICE_TAG(confirmedServiceRequest, 2);
            BOOST_ASN_CHOICE_TAG(cs_extension, 79);
        }

 
        // choice DeleteEventAction-Request

        template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteEventAction_Request_specific:  {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , DeleteEventAction_Request_specific), 0); break; }
                case DeleteEventAction_Request_aa_specific:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventAction_Request_aa_specific), 1); break; }
                case DeleteEventAction_Request_domain:  {BOOST_ASN_IMPLICIT_TAG(value<Identifier > (false , DeleteEventAction_Request_domain), 3); break; }
                case DeleteEventAction_Request_vmd:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , DeleteEventAction_Request_vmd), 4); break; }
                default:{}
            }
        }

        template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , DeleteEventAction_Request_specific), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventAction_Request_aa_specific), 1)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<Identifier > (true , DeleteEventAction_Request_domain), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , DeleteEventAction_Request_vmd), 4)) return; else free(); break;}
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

 
        // sequence GetEventActionAttributes-Response

        template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfModifier, 1);
            BOOST_ASN_CHOICE_TAG(confirmedServiceRequest, 2);
            BOOST_ASN_CHOICE_TAG(cs_extension, 79);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 3);
        }

        template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfModifier, 1);
            BOOST_ASN_CHOICE_TAG(confirmedServiceRequest, 2);
            BOOST_ASN_CHOICE_TAG(cs_extension, 79);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 3);
        }

 
        // sequence DefineEventEnrollment-Request

        template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions, 2);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 3);
            BOOST_ASN_CHOICE_TAG(eventActionName, 4);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 5);
        }

        template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions, 2);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 3);
            BOOST_ASN_CHOICE_TAG(eventActionName, 4);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 5);
        }

 
        // choice CS-DefineEventEnrollment-Request

        template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case CS_DefineEventEnrollment_Request_impl_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , CS_DefineEventEnrollment_Request_impl_string), 0); break; }
                case CS_DefineEventEnrollment_Request_impl_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , CS_DefineEventEnrollment_Request_impl_index), 1); break; }
                case CS_DefineEventEnrollment_Request_impl_noEnhancement:  {BOOST_ASN_BIND_TAG(value<null_type > (false , CS_DefineEventEnrollment_Request_impl_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , CS_DefineEventEnrollment_Request_impl_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , CS_DefineEventEnrollment_Request_impl_index), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , CS_DefineEventEnrollment_Request_impl_noEnhancement))) return; else free();
                }
            }
        }

 
        // choice DeleteEventEnrollment-Request

        template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case DeleteEventEnrollment_Request_specific:  {BOOST_ASN_IMPLICIT_TAG(value<specific_type > (false , DeleteEventEnrollment_Request_specific), 0); break; }
                case DeleteEventEnrollment_Request_ec:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , DeleteEventEnrollment_Request_ec), 1); break; }
                case DeleteEventEnrollment_Request_ea:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , DeleteEventEnrollment_Request_ea), 2); break; }
                default:{}
            }
        }

        template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<specific_type > (true , DeleteEventEnrollment_Request_specific), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , DeleteEventEnrollment_Request_ec), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , DeleteEventEnrollment_Request_ea), 2)) return; else free(); break;}
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

 
        // sequence GetEventEnrollmentAttributes-Request
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_specific = 0;
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_client = 1;
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_ec = 2;
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_ea = 3;


        template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfRequest, 0);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollmentNames, 1);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 2);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 3);
            BOOST_ASN_CHOICE_TAG(eventActionName, 4);
            BOOST_ASN_CHOICE_TAG(continueAfter, 5);
        }

        template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(scopeOfRequest, 0);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollmentNames, 1);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 2);
            BOOST_ASN_CHOICE_TAG(eventConditionName, 3);
            BOOST_ASN_CHOICE_TAG(eventActionName, 4);
            BOOST_ASN_CHOICE_TAG(continueAfter, 5);
        }

 
        // sequence GetEventEnrollmentAttributes-Response

        template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfEEAttributes, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfEEAttributes, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence EEAttributes


        template<> void EEAttributes::eventConditionName_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case eventConditionName_type_eventCondition:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , eventConditionName_type_eventCondition), 0); break; }
                case eventConditionName_type_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , eventConditionName_type_undefined), 1); break; }
                default:{}
            }
        }

        template<> void EEAttributes::eventConditionName_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , eventConditionName_type_eventCondition), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , eventConditionName_type_undefined), 1)) return; else free(); break;}
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

 


        template<> void EEAttributes::eventActionName_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case eventActionName_type_eventAction:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , eventActionName_type_eventAction), 0); break; }
                case eventActionName_type_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , eventActionName_type_undefined), 1); break; }
                default:{}
            }
        }

        template<> void EEAttributes::eventActionName_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , eventActionName_type_eventAction), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , eventActionName_type_undefined), 1)) return; else free(); break;}
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

 


        template<> void EEAttributes::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case displayEnhancement_type_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , displayEnhancement_type_string), 0); break; }
                case displayEnhancement_type_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_index), 1); break; }
                case displayEnhancement_type_noEnhancement:  {BOOST_ASN_BIND_TAG(value<null_type > (false , displayEnhancement_type_noEnhancement)); break; }
                default:{}
            }
        }

        template<> void EEAttributes::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , displayEnhancement_type_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_index), 1)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , displayEnhancement_type_noEnhancement))) return; else free();
                }
            }
        }

 

        template<> void EEAttributes::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_EXPLICIT_TAG(eventConditionName, 1);
            BOOST_ASN_EXPLICIT_TAG(eventActionName, 2);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 3);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 4);
            BOOST_ASN_IMPLICIT_TAG(enrollmentClass, 5);
            BOOST_ASN_IMPLICIT_TAG(duration, 6);
            BOOST_ASN_IMPLICIT_TAG(invokeID, 7);
            BOOST_ASN_IMPLICIT_TAG(remainingAcceptableDelay, 8);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 9);
        }

        template<> void EEAttributes::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_EXPLICIT_TAG(eventConditionName, 1);
            BOOST_ASN_EXPLICIT_TAG(eventActionName, 2);
            BOOST_ASN_EXPLICIT_TAG(clientApplication, 3);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 4);
            BOOST_ASN_IMPLICIT_TAG(enrollmentClass, 5);
            BOOST_ASN_IMPLICIT_TAG(duration, 6);
            BOOST_ASN_IMPLICIT_TAG(invokeID, 7);
            BOOST_ASN_IMPLICIT_TAG(remainingAcceptableDelay, 8);
            BOOST_ASN_EXPLICIT_TAG(displayEnhancement, 9);
        }

 
        // sequence ReportEventEnrollmentStatus-Response

        template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions, 0);
            BOOST_ASN_IMPLICIT_TAG(notificationLost, 1);
            BOOST_ASN_IMPLICIT_TAG(duration, 2);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 3);
            BOOST_ASN_IMPLICIT_TAG(currentState, 4);
        }

        template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions, 0);
            BOOST_ASN_IMPLICIT_TAG(notificationLost, 1);
            BOOST_ASN_IMPLICIT_TAG(duration, 2);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 3);
            BOOST_ASN_IMPLICIT_TAG(currentState, 4);
        }

 
        // sequence AlterEventEnrollment-Request

        template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions, 1);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 2);
        }

        template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventEnrollmentName, 0);
            BOOST_ASN_IMPLICIT_TAG(eventConditionTransitions, 1);
            BOOST_ASN_IMPLICIT_TAG(alarmAcknowledgmentRule, 2);
        }

 
        // sequence AlterEventEnrollment-Response


        template<> void AlterEventEnrollment_Response::currentState_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case currentState_type_state:  {BOOST_ASN_IMPLICIT_TAG(value<EE_State > (false , currentState_type_state), 0); break; }
                case currentState_type_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , currentState_type_undefined), 1); break; }
                default:{}
            }
        }

        template<> void AlterEventEnrollment_Response::currentState_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<EE_State > (true , currentState_type_state), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , currentState_type_undefined), 1)) return; else free(); break;}
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

 

        template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(currentState, 0);
            BOOST_ASN_CHOICE_TAG(transitionTime, 1);
        }

        template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(currentState, 0);
            BOOST_ASN_CHOICE_TAG(transitionTime, 1);
        }

 
        // sequence CS-AlterEventEnrollment-Request


        template<> void CS_AlterEventEnrollment_Request::changeDisplay_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case changeDisplay_type_string:  {BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (false , changeDisplay_type_string), 0); break; }
                case changeDisplay_type_index:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , changeDisplay_type_index), 1); break; }
                case changeDisplay_type_noEnhancement:  {BOOST_ASN_EXPLICIT_TAG(value<null_type > (false , changeDisplay_type_noEnhancement), 2); break; }
                default:{}
            }
        }

        template<> void CS_AlterEventEnrollment_Request::changeDisplay_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<visiblestring_type > (true , changeDisplay_type_string), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , changeDisplay_type_index), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_EXPLICIT_TAG(value<null_type > (true , changeDisplay_type_noEnhancement), 2)) return; else free(); break;}
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

 

        template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE(changeDisplay);
        }

        template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE(changeDisplay);
        }

 
    const int EE_State_disabled = 0;
    const int EE_State_idle = 1;
    const int EE_State_active = 2;
    const int EE_State_activeNoAckA = 3;
    const int EE_State_idleNoAckI = 4;
    const int EE_State_idleNoAckA = 5;
    const int EE_State_idleAcked = 6;
    const int EE_State_activeAcked = 7;
    const int EE_State_undefined = 8;

        // sequence DefineEventConditionList-Request

        template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

        template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

 
        // sequence AddEventConditionListReference-Request

        template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

        template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

 
        // sequence RemoveEventConditionListReference-Request

        template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

        template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

 
        // choice RemoveEventConditionListReference-Error

        template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case RemoveEventConditionListReference_Error_eventCondition:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , RemoveEventConditionListReference_Error_eventCondition), 0); break; }
                case RemoveEventConditionListReference_Error_eventConditionList:  {BOOST_ASN_CHOICE_TAG(value<ObjectName > (false , RemoveEventConditionListReference_Error_eventConditionList), 1); break; }
                default:{}
            }
        }

        template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , RemoveEventConditionListReference_Error_eventCondition), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_CHOICE_TAG(value<ObjectName > (true , RemoveEventConditionListReference_Error_eventConditionList), 1)) return; else free(); break;}
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

 
        // sequence GetEventConditionListAttributes-Response

        template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

        template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionName, 1);
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionListName, 2);
        }

 
        // sequence ReportEventConditionListStatus-Request

        template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(continueAfter, 1);
        }

        template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(continueAfter, 1);
        }

 
        // sequence ReportEventConditionListStatus-Response

        template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionStatus, 1);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 2);
        }

        template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfEventConditionStatus, 1);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 2);
        }

 
        // sequence EventConditionStatus

        template<> void EventConditionStatus::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(currentState, 1);
            BOOST_ASN_IMPLICIT_TAG(numberOfEventEnrollments, 2);
            BOOST_ASN_IMPLICIT_TAG(enabled, 3);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 4);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 5);
        }

        template<> void EventConditionStatus::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(currentState, 1);
            BOOST_ASN_IMPLICIT_TAG(numberOfEventEnrollments, 2);
            BOOST_ASN_IMPLICIT_TAG(enabled, 3);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToActive, 4);
            BOOST_ASN_CHOICE_TAG(timeOfLastTransitionToIdle, 5);
        }

 
        // sequence AlterEventConditionListMonitoring-Request


        template<> void AlterEventConditionListMonitoring_Request::priorityChange_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case priorityChange_type_priorityValue:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , priorityChange_type_priorityValue), 0); break; }
                case priorityChange_type_priorityReset:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , priorityChange_type_priorityReset), 1); break; }
                default:{}
            }
        }

        template<> void AlterEventConditionListMonitoring_Request::priorityChange_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , priorityChange_type_priorityValue), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , priorityChange_type_priorityReset), 1)) return; else free(); break;}
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

 

        template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(enabled, 1);
            BOOST_ASN_EXPLICIT_TAG(priorityChange, 2);
        }

        template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionListName, 0);
            BOOST_ASN_IMPLICIT_TAG(enabled, 1);
            BOOST_ASN_EXPLICIT_TAG(priorityChange, 2);
        }

 
        // sequence ReadJournal-Request


        template<> void ReadJournal_Request::rangeStartSpecification_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case rangeStartSpecification_type_startingTime:  {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , rangeStartSpecification_type_startingTime), 0); break; }
                case rangeStartSpecification_type_startingEntry:  {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , rangeStartSpecification_type_startingEntry), 1); break; }
                default:{}
            }
        }

        template<> void ReadJournal_Request::rangeStartSpecification_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , rangeStartSpecification_type_startingTime), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , rangeStartSpecification_type_startingEntry), 1)) return; else free(); break;}
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

 


        template<> void ReadJournal_Request::rangeStopSpecification_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case rangeStopSpecification_type_endingTime:  {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , rangeStopSpecification_type_endingTime), 0); break; }
                case rangeStopSpecification_type_numberOfEntries:  {BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (false , rangeStopSpecification_type_numberOfEntries), 1); break; }
                default:{}
            }
        }

        template<> void ReadJournal_Request::rangeStopSpecification_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , rangeStopSpecification_type_endingTime), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (true , rangeStopSpecification_type_numberOfEntries), 1)) return; else free(); break;}
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

 


        template<> void ReadJournal_Request::entryToStartAfter_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(timeSpecification, 0);
            BOOST_ASN_IMPLICIT_TAG(entrySpecification, 1);
        }

        template<> void ReadJournal_Request::entryToStartAfter_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(timeSpecification, 0);
            BOOST_ASN_IMPLICIT_TAG(entrySpecification, 1);
        }

 

        template<> void ReadJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
            BOOST_ASN_EXPLICIT_TAG(rangeStartSpecification, 1);
            BOOST_ASN_EXPLICIT_TAG(rangeStopSpecification, 2);
            BOOST_ASN_IMPLICIT_TAG(listOfVariables, 4);
            BOOST_ASN_IMPLICIT_TAG(entryToStartAfter, 5);
        }

        template<> void ReadJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
            BOOST_ASN_EXPLICIT_TAG(rangeStartSpecification, 1);
            BOOST_ASN_EXPLICIT_TAG(rangeStopSpecification, 2);
            BOOST_ASN_IMPLICIT_TAG(listOfVariables, 4);
            BOOST_ASN_IMPLICIT_TAG(entryToStartAfter, 5);
        }

 
        // sequence ReadJournal-Response

        template<> void ReadJournal_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfJournalEntry, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void ReadJournal_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(listOfJournalEntry, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence JournalEntry

        template<> void JournalEntry::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(entryIdentifier, 0);
            BOOST_ASN_EXPLICIT_TAG(originatingApplication, 1);
            BOOST_ASN_IMPLICIT_TAG(entryContent, 2);
        }

        template<> void JournalEntry::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(entryIdentifier, 0);
            BOOST_ASN_EXPLICIT_TAG(originatingApplication, 1);
            BOOST_ASN_IMPLICIT_TAG(entryContent, 2);
        }

 
        // sequence WriteJournal-Request

        template<> void WriteJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfJournalEntry, 1);
        }

        template<> void WriteJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfJournalEntry, 1);
        }

 
        // sequence InitializeJournal-Request


        template<> void InitializeJournal_Request::limitSpecification_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(limitingTime, 0);
            BOOST_ASN_IMPLICIT_TAG(limitingEntry, 1);
        }

        template<> void InitializeJournal_Request::limitSpecification_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(limitingTime, 0);
            BOOST_ASN_IMPLICIT_TAG(limitingEntry, 1);
        }

 

        template<> void InitializeJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
            BOOST_ASN_IMPLICIT_TAG(limitSpecification, 1);
        }

        template<> void InitializeJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
            BOOST_ASN_IMPLICIT_TAG(limitSpecification, 1);
        }

 
        // sequence ReportJournalStatus-Response

        template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(currentEntries, 0);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 1);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 2);
        }

        template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(currentEntries, 0);
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 1);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 2);
        }

 
        // sequence CreateJournal-Request

        template<> void CreateJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
        }

        template<> void CreateJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
        }

 
        // sequence DeleteJournal-Request

        template<> void DeleteJournal_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
        }

        template<> void DeleteJournal_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(journalName, 0);
        }

 
        // sequence EntryContent




        template<> void EntryContent::entryForm_type::data_type::event_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(currentState, 1);
        }

        template<> void EntryContent::entryForm_type::data_type::event_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(eventConditionName, 0);
            BOOST_ASN_IMPLICIT_TAG(currentState, 1);
        }

 

        template<> void EntryContent::entryForm_type::data_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(event, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfVariables, 1);
        }

        template<> void EntryContent::entryForm_type::data_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(event, 0);
            BOOST_ASN_IMPLICIT_TAG(listOfVariables, 1);
        }

 

        template<> void EntryContent::entryForm_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case entryForm_type_data:  {BOOST_ASN_IMPLICIT_TAG(value<data_type > (false , entryForm_type_data), 2); break; }
                case entryForm_type_annotation:  {BOOST_ASN_EXPLICIT_TAG(value<MMSString > (false , entryForm_type_annotation), 3); break; }
                default:{}
            }
        }

        template<> void EntryContent::entryForm_type::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<data_type > (true , entryForm_type_data), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_EXPLICIT_TAG(value<MMSString > (true , entryForm_type_annotation), 3)) return; else free(); break;}
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

 

        template<> void EntryContent::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(occurrenceTime, 0);
            BOOST_ASN_CHOICE(entryForm);
        }

        template<> void EntryContent::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(occurrenceTime, 0);
            BOOST_ASN_CHOICE(entryForm);
        }

 
} 
