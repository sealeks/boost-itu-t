#include "ISO-9506-MMS-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1 {



    // choice MMSpdu

    template<> void MMSpdu::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case MMSpdu_confirmed_RequestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 13);
                ITU_T_BIND_PER(*value<Confirmed_RequestPDU > (false, MMSpdu_confirmed_RequestPDU));
                break;
            }
            case MMSpdu_confirmed_ResponsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 13);
                ITU_T_BIND_PER(*value<Confirmed_ResponsePDU > (false, MMSpdu_confirmed_ResponsePDU));
                break;
            }
            case MMSpdu_confirmed_ErrorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 13);
                ITU_T_BIND_PER(*value<Confirmed_ErrorPDU > (false, MMSpdu_confirmed_ErrorPDU));
                break;
            }
            case MMSpdu_unconfirmed_PDU:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 13);
                ITU_T_BIND_PER(*value<Unconfirmed_PDU > (false, MMSpdu_unconfirmed_PDU));
                break;
            }
            case MMSpdu_rejectPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 13);
                ITU_T_BIND_PER(*value<RejectPDU > (false, MMSpdu_rejectPDU));
                break;
            }
            case MMSpdu_cancel_RequestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 13);
                ITU_T_BIND_NUM_CONSTRS(*value<Cancel_RequestPDU > (false, MMSpdu_cancel_RequestPDU), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case MMSpdu_cancel_ResponsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 13);
                ITU_T_BIND_NUM_CONSTRS(*value<Cancel_ResponsePDU > (false, MMSpdu_cancel_ResponsePDU), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case MMSpdu_cancel_ErrorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 13);
                ITU_T_BIND_PER(*value<Cancel_ErrorPDU > (false, MMSpdu_cancel_ErrorPDU));
                break;
            }
            case MMSpdu_initiate_RequestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(8, 13);
                ITU_T_BIND_PER(*value<Initiate_RequestPDU > (false, MMSpdu_initiate_RequestPDU));
                break;
            }
            case MMSpdu_initiate_ResponsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(9, 13);
                ITU_T_BIND_PER(*value<Initiate_ResponsePDU > (false, MMSpdu_initiate_ResponsePDU));
                break;
            }
            case MMSpdu_initiate_ErrorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(10, 13);
                ITU_T_BIND_PER(*value<Initiate_ErrorPDU > (false, MMSpdu_initiate_ErrorPDU));
                break;
            }
            case MMSpdu_conclude_RequestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(11, 13);
                ITU_T_BIND_PER(*value<Conclude_RequestPDU > (false, MMSpdu_conclude_RequestPDU));
                break;
            }
            case MMSpdu_conclude_ResponsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(12, 13);
                ITU_T_BIND_PER(*value<Conclude_ResponsePDU > (false, MMSpdu_conclude_ResponsePDU));
                break;
            }
            case MMSpdu_conclude_ErrorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(13, 13);
                ITU_T_BIND_PER(*value<Conclude_ErrorPDU > (false, MMSpdu_conclude_ErrorPDU));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void MMSpdu::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(13);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Confirmed_RequestPDU > (true, MMSpdu_confirmed_RequestPDU));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Confirmed_ResponsePDU > (true, MMSpdu_confirmed_ResponsePDU));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Confirmed_ErrorPDU > (true, MMSpdu_confirmed_ErrorPDU));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<Unconfirmed_PDU > (true, MMSpdu_unconfirmed_PDU));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<RejectPDU > (true, MMSpdu_rejectPDU));
                break;
            }
            case 5:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Cancel_RequestPDU > (true, MMSpdu_cancel_RequestPDU), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 6:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Cancel_ResponsePDU > (true, MMSpdu_cancel_ResponsePDU), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(*value<Cancel_ErrorPDU > (true, MMSpdu_cancel_ErrorPDU));
                break;
            }
            case 8:
            {
                ITU_T_BIND_PER(*value<Initiate_RequestPDU > (true, MMSpdu_initiate_RequestPDU));
                break;
            }
            case 9:
            {
                ITU_T_BIND_PER(*value<Initiate_ResponsePDU > (true, MMSpdu_initiate_ResponsePDU));
                break;
            }
            case 10:
            {
                ITU_T_BIND_PER(*value<Initiate_ErrorPDU > (true, MMSpdu_initiate_ErrorPDU));
                break;
            }
            case 11:
            {
                ITU_T_BIND_PER(*value<Conclude_RequestPDU > (true, MMSpdu_conclude_RequestPDU));
                break;
            }
            case 12:
            {
                ITU_T_BIND_PER(*value<Conclude_ResponsePDU > (true, MMSpdu_conclude_ResponsePDU));
                break;
            }
            case 13:
            {
                ITU_T_BIND_PER(*value<Conclude_ErrorPDU > (true, MMSpdu_conclude_ErrorPDU));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Confirmed-RequestPDU

    template<> void Confirmed_RequestPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(service_ext_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfModifiers_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(listOfModifiers_);
        ITU_T_BIND_PER(*service_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_PER(service_ext_);
                ITU_T_PER_END_OPEN;
            }

        };

    }

    template<> void Confirmed_RequestPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_NUM_CONSTRS(*invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfModifiers_);
        ITU_T_BIND_PER(*service_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_PER(service_ext_);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(1);
        };

    }

    // choice ConfirmedServiceRequest

    template<> void ConfirmedServiceRequest::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_CHOICE(ConfirmedServiceRequest_additionalService, ConfirmedServiceRequest_changeAccessControl);

        if (ITU_T_EXTENTION) {
            switch (type()) {
                case ConfirmedServiceRequest_status:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 77);
                    ITU_T_BIND_PER(*value<Status_Request > (false, ConfirmedServiceRequest_status));
                    break;
                }
                case ConfirmedServiceRequest_getNameList:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 77);
                    ITU_T_BIND_PER(*value<GetNameList_Request > (false, ConfirmedServiceRequest_getNameList));
                    break;
                }
                case ConfirmedServiceRequest_identify:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 77);
                    ITU_T_BIND_PER(*value<Identify_Request > (false, ConfirmedServiceRequest_identify));
                    break;
                }
                case ConfirmedServiceRequest_rename:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 77);
                    ITU_T_BIND_PER(*value<Rename_Request > (false, ConfirmedServiceRequest_rename));
                    break;
                }
                case ConfirmedServiceRequest_read:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 77);
                    ITU_T_BIND_PER(*value<Read_Request > (false, ConfirmedServiceRequest_read));
                    break;
                }
                case ConfirmedServiceRequest_write:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 77);
                    ITU_T_BIND_PER(*value<Write_Request > (false, ConfirmedServiceRequest_write));
                    break;
                }
                case ConfirmedServiceRequest_getVariableAccessAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 77);
                    ITU_T_BIND_PER(*value<GetVariableAccessAttributes_Request > (false, ConfirmedServiceRequest_getVariableAccessAttributes));
                    break;
                }
                case ConfirmedServiceRequest_defineNamedVariable:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 77);
                    ITU_T_BIND_PER(*value<DefineNamedVariable_Request > (false, ConfirmedServiceRequest_defineNamedVariable));
                    break;
                }
                case ConfirmedServiceRequest_defineScatteredAccess:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (false, ConfirmedServiceRequest_defineScatteredAccess));
                    break;
                }
                case ConfirmedServiceRequest_getScatteredAccessAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (false, ConfirmedServiceRequest_getScatteredAccessAttributes));
                    break;
                }
                case ConfirmedServiceRequest_deleteVariableAccess:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 77);
                    ITU_T_BIND_PER(*value<DeleteVariableAccess_Request > (false, ConfirmedServiceRequest_deleteVariableAccess));
                    break;
                }
                case ConfirmedServiceRequest_defineNamedVariableList:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 77);
                    ITU_T_BIND_PER(*value<DefineNamedVariableList_Request > (false, ConfirmedServiceRequest_defineNamedVariableList));
                    break;
                }
                case ConfirmedServiceRequest_getNamedVariableListAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 77);
                    ITU_T_BIND_PER(*value<GetNamedVariableListAttributes_Request > (false, ConfirmedServiceRequest_getNamedVariableListAttributes));
                    break;
                }
                case ConfirmedServiceRequest_deleteNamedVariableList:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 77);
                    ITU_T_BIND_PER(*value<DeleteNamedVariableList_Request > (false, ConfirmedServiceRequest_deleteNamedVariableList));
                    break;
                }
                case ConfirmedServiceRequest_defineNamedType:
                {
                    ITU_T_SET_CONSTAINED_INDX(14, 77);
                    ITU_T_BIND_PER(*value<DefineNamedType_Request > (false, ConfirmedServiceRequest_defineNamedType));
                    break;
                }
                case ConfirmedServiceRequest_getNamedTypeAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(15, 77);
                    ITU_T_BIND_PER(*value<GetNamedTypeAttributes_Request > (false, ConfirmedServiceRequest_getNamedTypeAttributes));
                    break;
                }
                case ConfirmedServiceRequest_deleteNamedType:
                {
                    ITU_T_SET_CONSTAINED_INDX(16, 77);
                    ITU_T_BIND_PER(*value<DeleteNamedType_Request > (false, ConfirmedServiceRequest_deleteNamedType));
                    break;
                }
                case ConfirmedServiceRequest_input:
                {
                    ITU_T_SET_CONSTAINED_INDX(17, 77);
                    ITU_T_BIND_PER(*value<Input_Request > (false, ConfirmedServiceRequest_input));
                    break;
                }
                case ConfirmedServiceRequest_output:
                {
                    ITU_T_SET_CONSTAINED_INDX(18, 77);
                    ITU_T_BIND_PER(*value<Output_Request > (false, ConfirmedServiceRequest_output));
                    break;
                }
                case ConfirmedServiceRequest_takeControl:
                {
                    ITU_T_SET_CONSTAINED_INDX(19, 77);
                    ITU_T_BIND_PER(*value<TakeControl_Request > (false, ConfirmedServiceRequest_takeControl));
                    break;
                }
                case ConfirmedServiceRequest_relinquishControl:
                {
                    ITU_T_SET_CONSTAINED_INDX(20, 77);
                    ITU_T_BIND_PER(*value<RelinquishControl_Request > (false, ConfirmedServiceRequest_relinquishControl));
                    break;
                }
                case ConfirmedServiceRequest_defineSemaphore:
                {
                    ITU_T_SET_CONSTAINED_INDX(21, 77);
                    ITU_T_BIND_PER(*value<DefineSemaphore_Request > (false, ConfirmedServiceRequest_defineSemaphore));
                    break;
                }
                case ConfirmedServiceRequest_deleteSemaphore:
                {
                    ITU_T_SET_CONSTAINED_INDX(22, 77);
                    ITU_T_BIND_PER(*value<DeleteSemaphore_Request > (false, ConfirmedServiceRequest_deleteSemaphore));
                    break;
                }
                case ConfirmedServiceRequest_reportSemaphoreStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(23, 77);
                    ITU_T_BIND_PER(*value<ReportSemaphoreStatus_Request > (false, ConfirmedServiceRequest_reportSemaphoreStatus));
                    break;
                }
                case ConfirmedServiceRequest_reportPoolSemaphoreStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(24, 77);
                    ITU_T_BIND_PER(*value<ReportPoolSemaphoreStatus_Request > (false, ConfirmedServiceRequest_reportPoolSemaphoreStatus));
                    break;
                }
                case ConfirmedServiceRequest_reportSemaphoreEntryStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(25, 77);
                    ITU_T_BIND_PER(*value<ReportSemaphoreEntryStatus_Request > (false, ConfirmedServiceRequest_reportSemaphoreEntryStatus));
                    break;
                }
                case ConfirmedServiceRequest_initiateDownloadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(26, 77);
                    ITU_T_BIND_PER(*value<InitiateDownloadSequence_Request > (false, ConfirmedServiceRequest_initiateDownloadSequence));
                    break;
                }
                case ConfirmedServiceRequest_downloadSegment:
                {
                    ITU_T_SET_CONSTAINED_INDX(27, 77);
                    ITU_T_BIND_PER(*value<DownloadSegment_Request > (false, ConfirmedServiceRequest_downloadSegment));
                    break;
                }
                case ConfirmedServiceRequest_terminateDownloadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(28, 77);
                    ITU_T_BIND_PER(*value<TerminateDownloadSequence_Request > (false, ConfirmedServiceRequest_terminateDownloadSequence));
                    break;
                }
                case ConfirmedServiceRequest_initiateUploadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(29, 77);
                    ITU_T_BIND_PER(*value<InitiateUploadSequence_Request > (false, ConfirmedServiceRequest_initiateUploadSequence));
                    break;
                }
                case ConfirmedServiceRequest_uploadSegment:
                {
                    ITU_T_SET_CONSTAINED_INDX(30, 77);
                    ITU_T_BIND_NUM_CONSTRS(*value<UploadSegment_Request > (false, ConfirmedServiceRequest_uploadSegment), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceRequest_terminateUploadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(31, 77);
                    ITU_T_BIND_NUM_CONSTRS(*value<TerminateUploadSequence_Request > (false, ConfirmedServiceRequest_terminateUploadSequence), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceRequest_requestDomainDownload:
                {
                    ITU_T_SET_CONSTAINED_INDX(32, 77);
                    ITU_T_BIND_PER(*value<RequestDomainDownload_Request > (false, ConfirmedServiceRequest_requestDomainDownload));
                    break;
                }
                case ConfirmedServiceRequest_requestDomainUpload:
                {
                    ITU_T_SET_CONSTAINED_INDX(33, 77);
                    ITU_T_BIND_PER(*value<RequestDomainUpload_Request > (false, ConfirmedServiceRequest_requestDomainUpload));
                    break;
                }
                case ConfirmedServiceRequest_loadDomainContent:
                {
                    ITU_T_SET_CONSTAINED_INDX(34, 77);
                    ITU_T_BIND_PER(*value<LoadDomainContent_Request > (false, ConfirmedServiceRequest_loadDomainContent));
                    break;
                }
                case ConfirmedServiceRequest_storeDomainContent:
                {
                    ITU_T_SET_CONSTAINED_INDX(35, 77);
                    ITU_T_BIND_PER(*value<StoreDomainContent_Request > (false, ConfirmedServiceRequest_storeDomainContent));
                    break;
                }
                case ConfirmedServiceRequest_deleteDomain:
                {
                    ITU_T_SET_CONSTAINED_INDX(36, 77);
                    ITU_T_BIND_PER(*value<DeleteDomain_Request > (false, ConfirmedServiceRequest_deleteDomain));
                    break;
                }
                case ConfirmedServiceRequest_getDomainAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(37, 77);
                    ITU_T_BIND_PER(*value<GetDomainAttributes_Request > (false, ConfirmedServiceRequest_getDomainAttributes));
                    break;
                }
                case ConfirmedServiceRequest_createProgramInvocation:
                {
                    ITU_T_SET_CONSTAINED_INDX(38, 77);
                    ITU_T_BIND_PER(*value<CreateProgramInvocation_Request > (false, ConfirmedServiceRequest_createProgramInvocation));
                    break;
                }
                case ConfirmedServiceRequest_deleteProgramInvocation:
                {
                    ITU_T_SET_CONSTAINED_INDX(39, 77);
                    ITU_T_BIND_PER(*value<DeleteProgramInvocation_Request > (false, ConfirmedServiceRequest_deleteProgramInvocation));
                    break;
                }
                case ConfirmedServiceRequest_start:
                {
                    ITU_T_SET_CONSTAINED_INDX(40, 77);
                    ITU_T_BIND_PER(*value<Start_Request > (false, ConfirmedServiceRequest_start));
                    break;
                }
                case ConfirmedServiceRequest_stop:
                {
                    ITU_T_SET_CONSTAINED_INDX(41, 77);
                    ITU_T_BIND_PER(*value<Stop_Request > (false, ConfirmedServiceRequest_stop));
                    break;
                }
                case ConfirmedServiceRequest_resume:
                {
                    ITU_T_SET_CONSTAINED_INDX(42, 77);
                    ITU_T_BIND_PER(*value<Resume_Request > (false, ConfirmedServiceRequest_resume));
                    break;
                }
                case ConfirmedServiceRequest_reset:
                {
                    ITU_T_SET_CONSTAINED_INDX(43, 77);
                    ITU_T_BIND_PER(*value<Reset_Request > (false, ConfirmedServiceRequest_reset));
                    break;
                }
                case ConfirmedServiceRequest_kill:
                {
                    ITU_T_SET_CONSTAINED_INDX(44, 77);
                    ITU_T_BIND_PER(*value<Kill_Request > (false, ConfirmedServiceRequest_kill));
                    break;
                }
                case ConfirmedServiceRequest_getProgramInvocationAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(45, 77);
                    ITU_T_BIND_PER(*value<GetProgramInvocationAttributes_Request > (false, ConfirmedServiceRequest_getProgramInvocationAttributes));
                    break;
                }
                case ConfirmedServiceRequest_obtainFile:
                {
                    ITU_T_SET_CONSTAINED_INDX(46, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::ObtainFile_Request > (false, ConfirmedServiceRequest_obtainFile));
                    break;
                }
                case ConfirmedServiceRequest_defineEventCondition:
                {
                    ITU_T_SET_CONSTAINED_INDX(47, 77);
                    ITU_T_BIND_PER(*value<DefineEventCondition_Request > (false, ConfirmedServiceRequest_defineEventCondition));
                    break;
                }
                case ConfirmedServiceRequest_deleteEventCondition:
                {
                    ITU_T_SET_CONSTAINED_INDX(48, 77);
                    ITU_T_BIND_PER(*value<DeleteEventCondition_Request > (false, ConfirmedServiceRequest_deleteEventCondition));
                    break;
                }
                case ConfirmedServiceRequest_getEventConditionAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(49, 77);
                    ITU_T_BIND_PER(*value<GetEventConditionAttributes_Request > (false, ConfirmedServiceRequest_getEventConditionAttributes));
                    break;
                }
                case ConfirmedServiceRequest_reportEventConditionStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(50, 77);
                    ITU_T_BIND_PER(*value<ReportEventConditionStatus_Request > (false, ConfirmedServiceRequest_reportEventConditionStatus));
                    break;
                }
                case ConfirmedServiceRequest_alterEventConditionMonitoring:
                {
                    ITU_T_SET_CONSTAINED_INDX(51, 77);
                    ITU_T_BIND_PER(*value<AlterEventConditionMonitoring_Request > (false, ConfirmedServiceRequest_alterEventConditionMonitoring));
                    break;
                }
                case ConfirmedServiceRequest_triggerEvent:
                {
                    ITU_T_SET_CONSTAINED_INDX(52, 77);
                    ITU_T_BIND_PER(*value<TriggerEvent_Request > (false, ConfirmedServiceRequest_triggerEvent));
                    break;
                }
                case ConfirmedServiceRequest_defineEventAction:
                {
                    ITU_T_SET_CONSTAINED_INDX(53, 77);
                    ITU_T_BIND_PER(*value<DefineEventAction_Request > (false, ConfirmedServiceRequest_defineEventAction));
                    break;
                }
                case ConfirmedServiceRequest_deleteEventAction:
                {
                    ITU_T_SET_CONSTAINED_INDX(54, 77);
                    ITU_T_BIND_PER(*value<DeleteEventAction_Request > (false, ConfirmedServiceRequest_deleteEventAction));
                    break;
                }
                case ConfirmedServiceRequest_getEventActionAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(55, 77);
                    ITU_T_BIND_PER(*value<GetEventActionAttributes_Request > (false, ConfirmedServiceRequest_getEventActionAttributes));
                    break;
                }
                case ConfirmedServiceRequest_reportEventActionStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(56, 77);
                    ITU_T_BIND_PER(*value<ReportEventActionStatus_Request > (false, ConfirmedServiceRequest_reportEventActionStatus));
                    break;
                }
                case ConfirmedServiceRequest_defineEventEnrollment:
                {
                    ITU_T_SET_CONSTAINED_INDX(57, 77);
                    ITU_T_BIND_PER(*value<DefineEventEnrollment_Request > (false, ConfirmedServiceRequest_defineEventEnrollment));
                    break;
                }
                case ConfirmedServiceRequest_deleteEventEnrollment:
                {
                    ITU_T_SET_CONSTAINED_INDX(58, 77);
                    ITU_T_BIND_PER(*value<DeleteEventEnrollment_Request > (false, ConfirmedServiceRequest_deleteEventEnrollment));
                    break;
                }
                case ConfirmedServiceRequest_alterEventEnrollment:
                {
                    ITU_T_SET_CONSTAINED_INDX(59, 77);
                    ITU_T_BIND_PER(*value<AlterEventEnrollment_Request > (false, ConfirmedServiceRequest_alterEventEnrollment));
                    break;
                }
                case ConfirmedServiceRequest_reportEventEnrollmentStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(60, 77);
                    ITU_T_BIND_PER(*value<ReportEventEnrollmentStatus_Request > (false, ConfirmedServiceRequest_reportEventEnrollmentStatus));
                    break;
                }
                case ConfirmedServiceRequest_getEventEnrollmentAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(61, 77);
                    ITU_T_BIND_PER(*value<GetEventEnrollmentAttributes_Request > (false, ConfirmedServiceRequest_getEventEnrollmentAttributes));
                    break;
                }
                case ConfirmedServiceRequest_acknowledgeEventNotification:
                {
                    ITU_T_SET_CONSTAINED_INDX(62, 77);
                    ITU_T_BIND_PER(*value<AcknowledgeEventNotification_Request > (false, ConfirmedServiceRequest_acknowledgeEventNotification));
                    break;
                }
                case ConfirmedServiceRequest_getAlarmSummary:
                {
                    ITU_T_SET_CONSTAINED_INDX(63, 77);
                    ITU_T_BIND_PER(*value<GetAlarmSummary_Request > (false, ConfirmedServiceRequest_getAlarmSummary));
                    break;
                }
                case ConfirmedServiceRequest_getAlarmEnrollmentSummary:
                {
                    ITU_T_SET_CONSTAINED_INDX(64, 77);
                    ITU_T_BIND_PER(*value<GetAlarmEnrollmentSummary_Request > (false, ConfirmedServiceRequest_getAlarmEnrollmentSummary));
                    break;
                }
                case ConfirmedServiceRequest_readJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(65, 77);
                    ITU_T_BIND_PER(*value<ReadJournal_Request > (false, ConfirmedServiceRequest_readJournal));
                    break;
                }
                case ConfirmedServiceRequest_writeJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(66, 77);
                    ITU_T_BIND_PER(*value<WriteJournal_Request > (false, ConfirmedServiceRequest_writeJournal));
                    break;
                }
                case ConfirmedServiceRequest_initializeJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(67, 77);
                    ITU_T_BIND_PER(*value<InitializeJournal_Request > (false, ConfirmedServiceRequest_initializeJournal));
                    break;
                }
                case ConfirmedServiceRequest_reportJournalStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(68, 77);
                    ITU_T_BIND_PER(*value<ReportJournalStatus_Request > (false, ConfirmedServiceRequest_reportJournalStatus));
                    break;
                }
                case ConfirmedServiceRequest_createJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(69, 77);
                    ITU_T_BIND_PER(*value<CreateJournal_Request > (false, ConfirmedServiceRequest_createJournal));
                    break;
                }
                case ConfirmedServiceRequest_deleteJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(70, 77);
                    ITU_T_BIND_PER(*value<DeleteJournal_Request > (false, ConfirmedServiceRequest_deleteJournal));
                    break;
                }
                case ConfirmedServiceRequest_getCapabilityList:
                {
                    ITU_T_SET_CONSTAINED_INDX(71, 77);
                    ITU_T_BIND_PER(*value<GetCapabilityList_Request > (false, ConfirmedServiceRequest_getCapabilityList));
                    break;
                }
                case ConfirmedServiceRequest_fileOpen:
                {
                    ITU_T_SET_CONSTAINED_INDX(72, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileOpen_Request > (false, ConfirmedServiceRequest_fileOpen));
                    break;
                }
                case ConfirmedServiceRequest_fileRead:
                {
                    ITU_T_SET_CONSTAINED_INDX(73, 77);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::FileRead_Request > (false, ConfirmedServiceRequest_fileRead), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceRequest_fileClose:
                {
                    ITU_T_SET_CONSTAINED_INDX(74, 77);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::FileClose_Request > (false, ConfirmedServiceRequest_fileClose), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceRequest_fileRename:
                {
                    ITU_T_SET_CONSTAINED_INDX(75, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileRename_Request > (false, ConfirmedServiceRequest_fileRename));
                    break;
                }
                case ConfirmedServiceRequest_fileDelete:
                {
                    ITU_T_SET_CONSTAINED_INDX(76, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDelete_Request > (false, ConfirmedServiceRequest_fileDelete));
                    break;
                }
                case ConfirmedServiceRequest_fileDirectory:
                {
                    ITU_T_SET_CONSTAINED_INDX(77, 77);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDirectory_Request > (false, ConfirmedServiceRequest_fileDirectory));
                    break;
                }
                default:
                {
                }
            }
        }
        else {
            switch (type()) {
                case ConfirmedServiceRequest_additionalService:
                {
                    ITU_T_SET_NSN_SMALL_INDX(0);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<AdditionalService_Request > (false, ConfirmedServiceRequest_additionalService));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_getDataExchangeAttributes:
                {
                    ITU_T_SET_NSN_SMALL_INDX(1);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<GetDataExchangeAttributes_Request > (false, ConfirmedServiceRequest_getDataExchangeAttributes));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_exchangeData:
                {
                    ITU_T_SET_NSN_SMALL_INDX(2);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ExchangeData_Request > (false, ConfirmedServiceRequest_exchangeData));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_defineAccessControlList:
                {
                    ITU_T_SET_NSN_SMALL_INDX(3);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<DefineAccessControlList_Request > (false, ConfirmedServiceRequest_defineAccessControlList));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_getAccessControlListAttributes:
                {
                    ITU_T_SET_NSN_SMALL_INDX(4);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<GetAccessControlListAttributes_Request > (false, ConfirmedServiceRequest_getAccessControlListAttributes));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_reportAccessControlledObjects:
                {
                    ITU_T_SET_NSN_SMALL_INDX(5);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ReportAccessControlledObjects_Request > (false, ConfirmedServiceRequest_reportAccessControlledObjects));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_deleteAccessControlList:
                {
                    ITU_T_SET_NSN_SMALL_INDX(6);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<DeleteAccessControlList_Request > (false, ConfirmedServiceRequest_deleteAccessControlList));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceRequest_changeAccessControl:
                {
                    ITU_T_SET_NSN_SMALL_INDX(7);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ChangeAccessControl_Request > (false, ConfirmedServiceRequest_changeAccessControl));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                default:
                {
                }
            }
        }
    }

    template<> void ConfirmedServiceRequest::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        if (ITU_T_EXTENTION) {

            ITU_T_GET_CONSTAINED_INDX(77);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(*value<Status_Request > (true, ConfirmedServiceRequest_status));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(*value<GetNameList_Request > (true, ConfirmedServiceRequest_getNameList));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(*value<Identify_Request > (true, ConfirmedServiceRequest_identify));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(*value<Rename_Request > (true, ConfirmedServiceRequest_rename));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(*value<Read_Request > (true, ConfirmedServiceRequest_read));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(*value<Write_Request > (true, ConfirmedServiceRequest_write));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(*value<GetVariableAccessAttributes_Request > (true, ConfirmedServiceRequest_getVariableAccessAttributes));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(*value<DefineNamedVariable_Request > (true, ConfirmedServiceRequest_defineNamedVariable));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (true, ConfirmedServiceRequest_defineScatteredAccess));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (true, ConfirmedServiceRequest_getScatteredAccessAttributes));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(*value<DeleteVariableAccess_Request > (true, ConfirmedServiceRequest_deleteVariableAccess));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(*value<DefineNamedVariableList_Request > (true, ConfirmedServiceRequest_defineNamedVariableList));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(*value<GetNamedVariableListAttributes_Request > (true, ConfirmedServiceRequest_getNamedVariableListAttributes));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(*value<DeleteNamedVariableList_Request > (true, ConfirmedServiceRequest_deleteNamedVariableList));
                    break;
                }
                case 14:
                {
                    ITU_T_BIND_PER(*value<DefineNamedType_Request > (true, ConfirmedServiceRequest_defineNamedType));
                    break;
                }
                case 15:
                {
                    ITU_T_BIND_PER(*value<GetNamedTypeAttributes_Request > (true, ConfirmedServiceRequest_getNamedTypeAttributes));
                    break;
                }
                case 16:
                {
                    ITU_T_BIND_PER(*value<DeleteNamedType_Request > (true, ConfirmedServiceRequest_deleteNamedType));
                    break;
                }
                case 17:
                {
                    ITU_T_BIND_PER(*value<Input_Request > (true, ConfirmedServiceRequest_input));
                    break;
                }
                case 18:
                {
                    ITU_T_BIND_PER(*value<Output_Request > (true, ConfirmedServiceRequest_output));
                    break;
                }
                case 19:
                {
                    ITU_T_BIND_PER(*value<TakeControl_Request > (true, ConfirmedServiceRequest_takeControl));
                    break;
                }
                case 20:
                {
                    ITU_T_BIND_PER(*value<RelinquishControl_Request > (true, ConfirmedServiceRequest_relinquishControl));
                    break;
                }
                case 21:
                {
                    ITU_T_BIND_PER(*value<DefineSemaphore_Request > (true, ConfirmedServiceRequest_defineSemaphore));
                    break;
                }
                case 22:
                {
                    ITU_T_BIND_PER(*value<DeleteSemaphore_Request > (true, ConfirmedServiceRequest_deleteSemaphore));
                    break;
                }
                case 23:
                {
                    ITU_T_BIND_PER(*value<ReportSemaphoreStatus_Request > (true, ConfirmedServiceRequest_reportSemaphoreStatus));
                    break;
                }
                case 24:
                {
                    ITU_T_BIND_PER(*value<ReportPoolSemaphoreStatus_Request > (true, ConfirmedServiceRequest_reportPoolSemaphoreStatus));
                    break;
                }
                case 25:
                {
                    ITU_T_BIND_PER(*value<ReportSemaphoreEntryStatus_Request > (true, ConfirmedServiceRequest_reportSemaphoreEntryStatus));
                    break;
                }
                case 26:
                {
                    ITU_T_BIND_PER(*value<InitiateDownloadSequence_Request > (true, ConfirmedServiceRequest_initiateDownloadSequence));
                    break;
                }
                case 27:
                {
                    ITU_T_BIND_PER(*value<DownloadSegment_Request > (true, ConfirmedServiceRequest_downloadSegment));
                    break;
                }
                case 28:
                {
                    ITU_T_BIND_PER(*value<TerminateDownloadSequence_Request > (true, ConfirmedServiceRequest_terminateDownloadSequence));
                    break;
                }
                case 29:
                {
                    ITU_T_BIND_PER(*value<InitiateUploadSequence_Request > (true, ConfirmedServiceRequest_initiateUploadSequence));
                    break;
                }
                case 30:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<UploadSegment_Request > (true, ConfirmedServiceRequest_uploadSegment), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 31:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<TerminateUploadSequence_Request > (true, ConfirmedServiceRequest_terminateUploadSequence), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 32:
                {
                    ITU_T_BIND_PER(*value<RequestDomainDownload_Request > (true, ConfirmedServiceRequest_requestDomainDownload));
                    break;
                }
                case 33:
                {
                    ITU_T_BIND_PER(*value<RequestDomainUpload_Request > (true, ConfirmedServiceRequest_requestDomainUpload));
                    break;
                }
                case 34:
                {
                    ITU_T_BIND_PER(*value<LoadDomainContent_Request > (true, ConfirmedServiceRequest_loadDomainContent));
                    break;
                }
                case 35:
                {
                    ITU_T_BIND_PER(*value<StoreDomainContent_Request > (true, ConfirmedServiceRequest_storeDomainContent));
                    break;
                }
                case 36:
                {
                    ITU_T_BIND_PER(*value<DeleteDomain_Request > (true, ConfirmedServiceRequest_deleteDomain));
                    break;
                }
                case 37:
                {
                    ITU_T_BIND_PER(*value<GetDomainAttributes_Request > (true, ConfirmedServiceRequest_getDomainAttributes));
                    break;
                }
                case 38:
                {
                    ITU_T_BIND_PER(*value<CreateProgramInvocation_Request > (true, ConfirmedServiceRequest_createProgramInvocation));
                    break;
                }
                case 39:
                {
                    ITU_T_BIND_PER(*value<DeleteProgramInvocation_Request > (true, ConfirmedServiceRequest_deleteProgramInvocation));
                    break;
                }
                case 40:
                {
                    ITU_T_BIND_PER(*value<Start_Request > (true, ConfirmedServiceRequest_start));
                    break;
                }
                case 41:
                {
                    ITU_T_BIND_PER(*value<Stop_Request > (true, ConfirmedServiceRequest_stop));
                    break;
                }
                case 42:
                {
                    ITU_T_BIND_PER(*value<Resume_Request > (true, ConfirmedServiceRequest_resume));
                    break;
                }
                case 43:
                {
                    ITU_T_BIND_PER(*value<Reset_Request > (true, ConfirmedServiceRequest_reset));
                    break;
                }
                case 44:
                {
                    ITU_T_BIND_PER(*value<Kill_Request > (true, ConfirmedServiceRequest_kill));
                    break;
                }
                case 45:
                {
                    ITU_T_BIND_PER(*value<GetProgramInvocationAttributes_Request > (true, ConfirmedServiceRequest_getProgramInvocationAttributes));
                    break;
                }
                case 46:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::ObtainFile_Request > (true, ConfirmedServiceRequest_obtainFile));
                    break;
                }
                case 47:
                {
                    ITU_T_BIND_PER(*value<DefineEventCondition_Request > (true, ConfirmedServiceRequest_defineEventCondition));
                    break;
                }
                case 48:
                {
                    ITU_T_BIND_PER(*value<DeleteEventCondition_Request > (true, ConfirmedServiceRequest_deleteEventCondition));
                    break;
                }
                case 49:
                {
                    ITU_T_BIND_PER(*value<GetEventConditionAttributes_Request > (true, ConfirmedServiceRequest_getEventConditionAttributes));
                    break;
                }
                case 50:
                {
                    ITU_T_BIND_PER(*value<ReportEventConditionStatus_Request > (true, ConfirmedServiceRequest_reportEventConditionStatus));
                    break;
                }
                case 51:
                {
                    ITU_T_BIND_PER(*value<AlterEventConditionMonitoring_Request > (true, ConfirmedServiceRequest_alterEventConditionMonitoring));
                    break;
                }
                case 52:
                {
                    ITU_T_BIND_PER(*value<TriggerEvent_Request > (true, ConfirmedServiceRequest_triggerEvent));
                    break;
                }
                case 53:
                {
                    ITU_T_BIND_PER(*value<DefineEventAction_Request > (true, ConfirmedServiceRequest_defineEventAction));
                    break;
                }
                case 54:
                {
                    ITU_T_BIND_PER(*value<DeleteEventAction_Request > (true, ConfirmedServiceRequest_deleteEventAction));
                    break;
                }
                case 55:
                {
                    ITU_T_BIND_PER(*value<GetEventActionAttributes_Request > (true, ConfirmedServiceRequest_getEventActionAttributes));
                    break;
                }
                case 56:
                {
                    ITU_T_BIND_PER(*value<ReportEventActionStatus_Request > (true, ConfirmedServiceRequest_reportEventActionStatus));
                    break;
                }
                case 57:
                {
                    ITU_T_BIND_PER(*value<DefineEventEnrollment_Request > (true, ConfirmedServiceRequest_defineEventEnrollment));
                    break;
                }
                case 58:
                {
                    ITU_T_BIND_PER(*value<DeleteEventEnrollment_Request > (true, ConfirmedServiceRequest_deleteEventEnrollment));
                    break;
                }
                case 59:
                {
                    ITU_T_BIND_PER(*value<AlterEventEnrollment_Request > (true, ConfirmedServiceRequest_alterEventEnrollment));
                    break;
                }
                case 60:
                {
                    ITU_T_BIND_PER(*value<ReportEventEnrollmentStatus_Request > (true, ConfirmedServiceRequest_reportEventEnrollmentStatus));
                    break;
                }
                case 61:
                {
                    ITU_T_BIND_PER(*value<GetEventEnrollmentAttributes_Request > (true, ConfirmedServiceRequest_getEventEnrollmentAttributes));
                    break;
                }
                case 62:
                {
                    ITU_T_BIND_PER(*value<AcknowledgeEventNotification_Request > (true, ConfirmedServiceRequest_acknowledgeEventNotification));
                    break;
                }
                case 63:
                {
                    ITU_T_BIND_PER(*value<GetAlarmSummary_Request > (true, ConfirmedServiceRequest_getAlarmSummary));
                    break;
                }
                case 64:
                {
                    ITU_T_BIND_PER(*value<GetAlarmEnrollmentSummary_Request > (true, ConfirmedServiceRequest_getAlarmEnrollmentSummary));
                    break;
                }
                case 65:
                {
                    ITU_T_BIND_PER(*value<ReadJournal_Request > (true, ConfirmedServiceRequest_readJournal));
                    break;
                }
                case 66:
                {
                    ITU_T_BIND_PER(*value<WriteJournal_Request > (true, ConfirmedServiceRequest_writeJournal));
                    break;
                }
                case 67:
                {
                    ITU_T_BIND_PER(*value<InitializeJournal_Request > (true, ConfirmedServiceRequest_initializeJournal));
                    break;
                }
                case 68:
                {
                    ITU_T_BIND_PER(*value<ReportJournalStatus_Request > (true, ConfirmedServiceRequest_reportJournalStatus));
                    break;
                }
                case 69:
                {
                    ITU_T_BIND_PER(*value<CreateJournal_Request > (true, ConfirmedServiceRequest_createJournal));
                    break;
                }
                case 70:
                {
                    ITU_T_BIND_PER(*value<DeleteJournal_Request > (true, ConfirmedServiceRequest_deleteJournal));
                    break;
                }
                case 71:
                {
                    ITU_T_BIND_PER(*value<GetCapabilityList_Request > (true, ConfirmedServiceRequest_getCapabilityList));
                    break;
                }
                case 72:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileOpen_Request > (true, ConfirmedServiceRequest_fileOpen));
                    break;
                }
                case 73:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::FileRead_Request > (true, ConfirmedServiceRequest_fileRead), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 74:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::FileClose_Request > (true, ConfirmedServiceRequest_fileClose), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 75:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileRename_Request > (true, ConfirmedServiceRequest_fileRename));
                    break;
                }
                case 76:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDelete_Request > (true, ConfirmedServiceRequest_fileDelete));
                    break;
                }
                case 77:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDirectory_Request > (true, ConfirmedServiceRequest_fileDirectory));
                    break;
                }
                default:
                {
                }
            }
        }
        else {

            ITU_T_GET_NSN_SMALL_INDX;

            switch (__indx__) {
                case 0:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<AdditionalService_Request > (false, ConfirmedServiceRequest_additionalService));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 1:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<GetDataExchangeAttributes_Request > (false, ConfirmedServiceRequest_getDataExchangeAttributes));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 2:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ExchangeData_Request > (false, ConfirmedServiceRequest_exchangeData));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 3:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<DefineAccessControlList_Request > (false, ConfirmedServiceRequest_defineAccessControlList));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 4:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<GetAccessControlListAttributes_Request > (false, ConfirmedServiceRequest_getAccessControlListAttributes));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 5:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ReportAccessControlledObjects_Request > (false, ConfirmedServiceRequest_reportAccessControlledObjects));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 6:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<DeleteAccessControlList_Request > (false, ConfirmedServiceRequest_deleteAccessControlList));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 7:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ChangeAccessControl_Request > (false, ConfirmedServiceRequest_changeAccessControl));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                default:
                {
                    ITU_T_PER_CLEAR_EXTENTION;
                }
            }
        }
    }

    // choice AdditionalService-Request

    template<> void AdditionalService_Request::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Request_vMDStop:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 22);
                ITU_T_BIND_PER(*value<VMDStop_Request > (false, AdditionalService_Request_vMDStop));
                break;
            }
            case AdditionalService_Request_vMDReset:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 22);
                ITU_T_BIND_PER(*value<VMDReset_Request > (false, AdditionalService_Request_vMDReset));
                break;
            }
            case AdditionalService_Request_select:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 22);
                ITU_T_BIND_PER(*value<Select_Request > (false, AdditionalService_Request_select));
                break;
            }
            case AdditionalService_Request_alterPI:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 22);
                ITU_T_BIND_PER(*value<AlterProgramInvocationAttributes_Request > (false, AdditionalService_Request_alterPI));
                break;
            }
            case AdditionalService_Request_initiateUCLoad:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 22);
                ITU_T_BIND_PER(*value<InitiateUnitControlLoad_Request > (false, AdditionalService_Request_initiateUCLoad));
                break;
            }
            case AdditionalService_Request_uCLoad:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 22);
                ITU_T_BIND_PER(*value<UnitControlLoadSegment_Request > (false, AdditionalService_Request_uCLoad));
                break;
            }
            case AdditionalService_Request_uCUpload:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 22);
                ITU_T_BIND_PER(*value<UnitControlUpload_Request > (false, AdditionalService_Request_uCUpload));
                break;
            }
            case AdditionalService_Request_startUC:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 22);
                ITU_T_BIND_PER(*value<StartUnitControl_Request > (false, AdditionalService_Request_startUC));
                break;
            }
            case AdditionalService_Request_stopUC:
            {
                ITU_T_SET_CONSTAINED_INDX(8, 22);
                ITU_T_BIND_PER(*value<StopUnitControl_Request > (false, AdditionalService_Request_stopUC));
                break;
            }
            case AdditionalService_Request_createUC:
            {
                ITU_T_SET_CONSTAINED_INDX(9, 22);
                ITU_T_BIND_PER(*value<CreateUnitControl_Request > (false, AdditionalService_Request_createUC));
                break;
            }
            case AdditionalService_Request_addToUC:
            {
                ITU_T_SET_CONSTAINED_INDX(10, 22);
                ITU_T_BIND_PER(*value<AddToUnitControl_Request > (false, AdditionalService_Request_addToUC));
                break;
            }
            case AdditionalService_Request_removeFromUC:
            {
                ITU_T_SET_CONSTAINED_INDX(11, 22);
                ITU_T_BIND_PER(*value<RemoveFromUnitControl_Request > (false, AdditionalService_Request_removeFromUC));
                break;
            }
            case AdditionalService_Request_getUCAttributes:
            {
                ITU_T_SET_CONSTAINED_INDX(12, 22);
                ITU_T_BIND_PER(*value<GetUnitControlAttributes_Request > (false, AdditionalService_Request_getUCAttributes));
                break;
            }
            case AdditionalService_Request_loadUCFromFile:
            {
                ITU_T_SET_CONSTAINED_INDX(13, 22);
                ITU_T_BIND_PER(*value<LoadUnitControlFromFile_Request > (false, AdditionalService_Request_loadUCFromFile));
                break;
            }
            case AdditionalService_Request_storeUCToFile:
            {
                ITU_T_SET_CONSTAINED_INDX(14, 22);
                ITU_T_BIND_PER(*value<StoreUnitControlToFile_Request > (false, AdditionalService_Request_storeUCToFile));
                break;
            }
            case AdditionalService_Request_deleteUC:
            {
                ITU_T_SET_CONSTAINED_INDX(15, 22);
                ITU_T_BIND_PER(*value<DeleteUnitControl_Request > (false, AdditionalService_Request_deleteUC));
                break;
            }
            case AdditionalService_Request_defineECL:
            {
                ITU_T_SET_CONSTAINED_INDX(16, 22);
                ITU_T_BIND_PER(*value<DefineEventConditionList_Request > (false, AdditionalService_Request_defineECL));
                break;
            }
            case AdditionalService_Request_deleteECL:
            {
                ITU_T_SET_CONSTAINED_INDX(17, 22);
                ITU_T_BIND_PER(*value<DeleteEventConditionList_Request > (false, AdditionalService_Request_deleteECL));
                break;
            }
            case AdditionalService_Request_addECLReference:
            {
                ITU_T_SET_CONSTAINED_INDX(18, 22);
                ITU_T_BIND_PER(*value<AddEventConditionListReference_Request > (false, AdditionalService_Request_addECLReference));
                break;
            }
            case AdditionalService_Request_removeECLReference:
            {
                ITU_T_SET_CONSTAINED_INDX(19, 22);
                ITU_T_BIND_PER(*value<RemoveEventConditionListReference_Request > (false, AdditionalService_Request_removeECLReference));
                break;
            }
            case AdditionalService_Request_getECLAttributes:
            {
                ITU_T_SET_CONSTAINED_INDX(20, 22);
                ITU_T_BIND_PER(*value<GetEventConditionListAttributes_Request > (false, AdditionalService_Request_getECLAttributes));
                break;
            }
            case AdditionalService_Request_reportECLStatus:
            {
                ITU_T_SET_CONSTAINED_INDX(21, 22);
                ITU_T_BIND_PER(*value<ReportEventConditionListStatus_Request > (false, AdditionalService_Request_reportECLStatus));
                break;
            }
            case AdditionalService_Request_alterECLMonitoring:
            {
                ITU_T_SET_CONSTAINED_INDX(22, 22);
                ITU_T_BIND_PER(*value<AlterEventConditionListMonitoring_Request > (false, AdditionalService_Request_alterECLMonitoring));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AdditionalService_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(22);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<VMDStop_Request > (true, AdditionalService_Request_vMDStop));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<VMDReset_Request > (true, AdditionalService_Request_vMDReset));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Select_Request > (true, AdditionalService_Request_select));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<AlterProgramInvocationAttributes_Request > (true, AdditionalService_Request_alterPI));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<InitiateUnitControlLoad_Request > (true, AdditionalService_Request_initiateUCLoad));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*value<UnitControlLoadSegment_Request > (true, AdditionalService_Request_uCLoad));
                break;
            }
            case 6:
            {
                ITU_T_BIND_PER(*value<UnitControlUpload_Request > (true, AdditionalService_Request_uCUpload));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(*value<StartUnitControl_Request > (true, AdditionalService_Request_startUC));
                break;
            }
            case 8:
            {
                ITU_T_BIND_PER(*value<StopUnitControl_Request > (true, AdditionalService_Request_stopUC));
                break;
            }
            case 9:
            {
                ITU_T_BIND_PER(*value<CreateUnitControl_Request > (true, AdditionalService_Request_createUC));
                break;
            }
            case 10:
            {
                ITU_T_BIND_PER(*value<AddToUnitControl_Request > (true, AdditionalService_Request_addToUC));
                break;
            }
            case 11:
            {
                ITU_T_BIND_PER(*value<RemoveFromUnitControl_Request > (true, AdditionalService_Request_removeFromUC));
                break;
            }
            case 12:
            {
                ITU_T_BIND_PER(*value<GetUnitControlAttributes_Request > (true, AdditionalService_Request_getUCAttributes));
                break;
            }
            case 13:
            {
                ITU_T_BIND_PER(*value<LoadUnitControlFromFile_Request > (true, AdditionalService_Request_loadUCFromFile));
                break;
            }
            case 14:
            {
                ITU_T_BIND_PER(*value<StoreUnitControlToFile_Request > (true, AdditionalService_Request_storeUCToFile));
                break;
            }
            case 15:
            {
                ITU_T_BIND_PER(*value<DeleteUnitControl_Request > (true, AdditionalService_Request_deleteUC));
                break;
            }
            case 16:
            {
                ITU_T_BIND_PER(*value<DefineEventConditionList_Request > (true, AdditionalService_Request_defineECL));
                break;
            }
            case 17:
            {
                ITU_T_BIND_PER(*value<DeleteEventConditionList_Request > (true, AdditionalService_Request_deleteECL));
                break;
            }
            case 18:
            {
                ITU_T_BIND_PER(*value<AddEventConditionListReference_Request > (true, AdditionalService_Request_addECLReference));
                break;
            }
            case 19:
            {
                ITU_T_BIND_PER(*value<RemoveEventConditionListReference_Request > (true, AdditionalService_Request_removeECLReference));
                break;
            }
            case 20:
            {
                ITU_T_BIND_PER(*value<GetEventConditionListAttributes_Request > (true, AdditionalService_Request_getECLAttributes));
                break;
            }
            case 21:
            {
                ITU_T_BIND_PER(*value<ReportEventConditionListStatus_Request > (true, AdditionalService_Request_reportECLStatus));
                break;
            }
            case 22:
            {
                ITU_T_BIND_PER(*value<AlterEventConditionListMonitoring_Request > (true, AdditionalService_Request_alterECLMonitoring));
                break;
            }
            default:
            {
            }
        }
    }

    // choice Request-Detail

    template<> void Request_Detail::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Request_Detail_otherRequests:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 7);
                ITU_T_BIND_PER(*value<null_type > (false, Request_Detail_otherRequests));
                break;
            }
            case Request_Detail_createProgramInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 7);
                ITU_T_BIND_NUM_CONSTRS(*value<CS_CreateProgramInvocation_Request > (false, Request_Detail_createProgramInvocation), static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                break;
            }
            case Request_Detail_start:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 7);
                ITU_T_BIND_PER(*(*value<CS_Start_Request > (false, Request_Detail_start)));
                break;
            }
            case Request_Detail_resume:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 7);
                ITU_T_BIND_PER(*(*value<CS_Resume_Request > (false, Request_Detail_resume)));
                break;
            }
            case Request_Detail_defineEventCondition:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 7);
                ITU_T_BIND_PER(*(*value<CS_DefineEventCondition_Request > (false, Request_Detail_defineEventCondition)));
                break;
            }
            case Request_Detail_alterEventConditionMonitoring:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 7);
                ITU_T_BIND_PER(*value<CS_AlterEventConditionMonitoring_Request > (false, Request_Detail_alterEventConditionMonitoring));
                break;
            }
            case Request_Detail_defineEventEnrollment:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 7);
                ITU_T_BIND_PER(*(*value<CS_DefineEventEnrollment_Request > (false, Request_Detail_defineEventEnrollment)));
                break;
            }
            case Request_Detail_alterEventEnrollment:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 7);
                ITU_T_BIND_PER(*value<CS_AlterEventEnrollment_Request > (false, Request_Detail_alterEventEnrollment));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Request_Detail::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(7);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Request_Detail_otherRequests));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<CS_CreateProgramInvocation_Request > (true, Request_Detail_createProgramInvocation), static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*(*value<CS_Start_Request > (true, Request_Detail_start)));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*(*value<CS_Resume_Request > (true, Request_Detail_resume)));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*(*value<CS_DefineEventCondition_Request > (true, Request_Detail_defineEventCondition)));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*value<CS_AlterEventConditionMonitoring_Request > (true, Request_Detail_alterEventConditionMonitoring));
                break;
            }
            case 6:
            {
                ITU_T_BIND_PER(*(*value<CS_DefineEventEnrollment_Request > (true, Request_Detail_defineEventEnrollment)));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(*value<CS_AlterEventEnrollment_Request > (true, Request_Detail_alterEventEnrollment));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Unconfirmed-PDU

    template<> void Unconfirmed_PDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(service_ext_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;

        ITU_T_BIND_PER(*service_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_PER(service_ext_);
                ITU_T_PER_END_OPEN;
            }

        };

    }

    template<> void Unconfirmed_PDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_PER(*service_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_PER(service_ext_);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(1);
        };

    }

    // choice UnconfirmedService

    template<> void UnconfirmedService::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case UnconfirmedService_informationReport:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<InformationReport > (false, UnconfirmedService_informationReport));
                break;
            }
            case UnconfirmedService_unsolicitedStatus:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<UnsolicitedStatus > (false, UnconfirmedService_unsolicitedStatus));
                break;
            }
            case UnconfirmedService_eventNotification:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<EventNotification > (false, UnconfirmedService_eventNotification));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnconfirmedService::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<InformationReport > (true, UnconfirmedService_informationReport));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<UnsolicitedStatus > (true, UnconfirmedService_unsolicitedStatus));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<EventNotification > (true, UnconfirmedService_eventNotification));
                break;
            }
            default:
            {
            }
        }
    }

    // choice Unconfirmed-Detail

    template<> void Unconfirmed_Detail::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Unconfirmed_Detail_otherRequests:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, Unconfirmed_Detail_otherRequests));
                break;
            }
            case Unconfirmed_Detail_eventNotification:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*(*value<CS_EventNotification > (false, Unconfirmed_Detail_eventNotification)));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Unconfirmed_Detail::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Unconfirmed_Detail_otherRequests));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*(*value<CS_EventNotification > (true, Unconfirmed_Detail_eventNotification)));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Confirmed-ResponsePDU

    template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(service_ext_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*service_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_PER(service_ext_);
                ITU_T_PER_END_OPEN;
            }

        };

    }

    template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_NUM_CONSTRS(*invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*service_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_PER(service_ext_);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(1);
        };

    }

    // choice ConfirmedServiceResponse

    template<> void ConfirmedServiceResponse::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_CHOICE(ConfirmedServiceResponse_additionalService, ConfirmedServiceResponse_changeAccessControl);

        if (ITU_T_EXTENTION) {
            switch (type()) {
                case ConfirmedServiceResponse_status:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 76);
                    ITU_T_BIND_PER(*value<Status_Response > (false, ConfirmedServiceResponse_status));
                    break;
                }
                case ConfirmedServiceResponse_getNameList:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 76);
                    ITU_T_BIND_PER(*value<GetNameList_Response > (false, ConfirmedServiceResponse_getNameList));
                    break;
                }
                case ConfirmedServiceResponse_identify:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 76);
                    ITU_T_BIND_PER(*value<Identify_Response > (false, ConfirmedServiceResponse_identify));
                    break;
                }
                case ConfirmedServiceResponse_rename:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 76);
                    ITU_T_BIND_PER(*value<Rename_Response > (false, ConfirmedServiceResponse_rename));
                    break;
                }
                case ConfirmedServiceResponse_read:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 76);
                    ITU_T_BIND_PER(*value<Read_Response > (false, ConfirmedServiceResponse_read));
                    break;
                }
                case ConfirmedServiceResponse_getVariableAccessAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 76);
                    ITU_T_BIND_PER(*value<GetVariableAccessAttributes_Response > (false, ConfirmedServiceResponse_getVariableAccessAttributes));
                    break;
                }
                case ConfirmedServiceResponse_defineNamedVariable:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 76);
                    ITU_T_BIND_PER(*value<DefineNamedVariable_Response > (false, ConfirmedServiceResponse_defineNamedVariable));
                    break;
                }
                case ConfirmedServiceResponse_defineScatteredAccess:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (false, ConfirmedServiceResponse_defineScatteredAccess));
                    break;
                }
                case ConfirmedServiceResponse_getScatteredAccessAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (false, ConfirmedServiceResponse_getScatteredAccessAttributes));
                    break;
                }
                case ConfirmedServiceResponse_deleteVariableAccess:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 76);
                    ITU_T_BIND_PER(*value<DeleteVariableAccess_Response > (false, ConfirmedServiceResponse_deleteVariableAccess));
                    break;
                }
                case ConfirmedServiceResponse_defineNamedVariableList:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 76);
                    ITU_T_BIND_PER(*value<DefineNamedVariableList_Response > (false, ConfirmedServiceResponse_defineNamedVariableList));
                    break;
                }
                case ConfirmedServiceResponse_getNamedVariableListAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 76);
                    ITU_T_BIND_PER(*value<GetNamedVariableListAttributes_Response > (false, ConfirmedServiceResponse_getNamedVariableListAttributes));
                    break;
                }
                case ConfirmedServiceResponse_deleteNamedVariableList:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 76);
                    ITU_T_BIND_PER(*value<DeleteNamedVariableList_Response > (false, ConfirmedServiceResponse_deleteNamedVariableList));
                    break;
                }
                case ConfirmedServiceResponse_defineNamedType:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 76);
                    ITU_T_BIND_PER(*value<DefineNamedType_Response > (false, ConfirmedServiceResponse_defineNamedType));
                    break;
                }
                case ConfirmedServiceResponse_getNamedTypeAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(14, 76);
                    ITU_T_BIND_PER(*value<GetNamedTypeAttributes_Response > (false, ConfirmedServiceResponse_getNamedTypeAttributes));
                    break;
                }
                case ConfirmedServiceResponse_deleteNamedType:
                {
                    ITU_T_SET_CONSTAINED_INDX(15, 76);
                    ITU_T_BIND_PER(*value<DeleteNamedType_Response > (false, ConfirmedServiceResponse_deleteNamedType));
                    break;
                }
                case ConfirmedServiceResponse_input:
                {
                    ITU_T_SET_CONSTAINED_INDX(16, 76);
                    ITU_T_BIND_PER(*value<Input_Response > (false, ConfirmedServiceResponse_input));
                    break;
                }
                case ConfirmedServiceResponse_output:
                {
                    ITU_T_SET_CONSTAINED_INDX(17, 76);
                    ITU_T_BIND_PER(*value<Output_Response > (false, ConfirmedServiceResponse_output));
                    break;
                }
                case ConfirmedServiceResponse_takeControl:
                {
                    ITU_T_SET_CONSTAINED_INDX(18, 76);
                    ITU_T_BIND_PER(*value<TakeControl_Response > (false, ConfirmedServiceResponse_takeControl));
                    break;
                }
                case ConfirmedServiceResponse_relinquishControl:
                {
                    ITU_T_SET_CONSTAINED_INDX(19, 76);
                    ITU_T_BIND_PER(*value<RelinquishControl_Response > (false, ConfirmedServiceResponse_relinquishControl));
                    break;
                }
                case ConfirmedServiceResponse_defineSemaphore:
                {
                    ITU_T_SET_CONSTAINED_INDX(20, 76);
                    ITU_T_BIND_PER(*value<DefineSemaphore_Response > (false, ConfirmedServiceResponse_defineSemaphore));
                    break;
                }
                case ConfirmedServiceResponse_deleteSemaphore:
                {
                    ITU_T_SET_CONSTAINED_INDX(21, 76);
                    ITU_T_BIND_PER(*value<DeleteSemaphore_Response > (false, ConfirmedServiceResponse_deleteSemaphore));
                    break;
                }
                case ConfirmedServiceResponse_reportSemaphoreStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(22, 76);
                    ITU_T_BIND_PER(*value<ReportSemaphoreStatus_Response > (false, ConfirmedServiceResponse_reportSemaphoreStatus));
                    break;
                }
                case ConfirmedServiceResponse_reportPoolSemaphoreStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(23, 76);
                    ITU_T_BIND_PER(*value<ReportPoolSemaphoreStatus_Response > (false, ConfirmedServiceResponse_reportPoolSemaphoreStatus));
                    break;
                }
                case ConfirmedServiceResponse_reportSemaphoreEntryStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(24, 76);
                    ITU_T_BIND_PER(*value<ReportSemaphoreEntryStatus_Response > (false, ConfirmedServiceResponse_reportSemaphoreEntryStatus));
                    break;
                }
                case ConfirmedServiceResponse_initiateDownloadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(25, 76);
                    ITU_T_BIND_PER(*value<InitiateDownloadSequence_Response > (false, ConfirmedServiceResponse_initiateDownloadSequence));
                    break;
                }
                case ConfirmedServiceResponse_downloadSegment:
                {
                    ITU_T_SET_CONSTAINED_INDX(26, 76);
                    ITU_T_BIND_PER(*value<DownloadSegment_Response > (false, ConfirmedServiceResponse_downloadSegment));
                    break;
                }
                case ConfirmedServiceResponse_terminateDownloadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(27, 76);
                    ITU_T_BIND_PER(*value<TerminateDownloadSequence_Response > (false, ConfirmedServiceResponse_terminateDownloadSequence));
                    break;
                }
                case ConfirmedServiceResponse_initiateUploadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(28, 76);
                    ITU_T_BIND_PER(*value<InitiateUploadSequence_Response > (false, ConfirmedServiceResponse_initiateUploadSequence));
                    break;
                }
                case ConfirmedServiceResponse_uploadSegment:
                {
                    ITU_T_SET_CONSTAINED_INDX(29, 76);
                    ITU_T_BIND_PER(*value<UploadSegment_Response > (false, ConfirmedServiceResponse_uploadSegment));
                    break;
                }
                case ConfirmedServiceResponse_terminateUploadSequence:
                {
                    ITU_T_SET_CONSTAINED_INDX(30, 76);
                    ITU_T_BIND_PER(*value<TerminateUploadSequence_Response > (false, ConfirmedServiceResponse_terminateUploadSequence));
                    break;
                }
                case ConfirmedServiceResponse_requestDomainDownload:
                {
                    ITU_T_SET_CONSTAINED_INDX(31, 76);
                    ITU_T_BIND_PER(*value<RequestDomainDownload_Response > (false, ConfirmedServiceResponse_requestDomainDownload));
                    break;
                }
                case ConfirmedServiceResponse_requestDomainUpload:
                {
                    ITU_T_SET_CONSTAINED_INDX(32, 76);
                    ITU_T_BIND_PER(*value<RequestDomainUpload_Response > (false, ConfirmedServiceResponse_requestDomainUpload));
                    break;
                }
                case ConfirmedServiceResponse_loadDomainContent:
                {
                    ITU_T_SET_CONSTAINED_INDX(33, 76);
                    ITU_T_BIND_PER(*value<LoadDomainContent_Response > (false, ConfirmedServiceResponse_loadDomainContent));
                    break;
                }
                case ConfirmedServiceResponse_storeDomainContent:
                {
                    ITU_T_SET_CONSTAINED_INDX(34, 76);
                    ITU_T_BIND_PER(*value<StoreDomainContent_Response > (false, ConfirmedServiceResponse_storeDomainContent));
                    break;
                }
                case ConfirmedServiceResponse_deleteDomain:
                {
                    ITU_T_SET_CONSTAINED_INDX(35, 76);
                    ITU_T_BIND_PER(*value<DeleteDomain_Response > (false, ConfirmedServiceResponse_deleteDomain));
                    break;
                }
                case ConfirmedServiceResponse_getDomainAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(36, 76);
                    ITU_T_BIND_PER(*value<GetDomainAttributes_Response > (false, ConfirmedServiceResponse_getDomainAttributes));
                    break;
                }
                case ConfirmedServiceResponse_createProgramInvocation:
                {
                    ITU_T_SET_CONSTAINED_INDX(37, 76);
                    ITU_T_BIND_PER(*value<CreateProgramInvocation_Response > (false, ConfirmedServiceResponse_createProgramInvocation));
                    break;
                }
                case ConfirmedServiceResponse_deleteProgramInvocation:
                {
                    ITU_T_SET_CONSTAINED_INDX(38, 76);
                    ITU_T_BIND_PER(*value<DeleteProgramInvocation_Response > (false, ConfirmedServiceResponse_deleteProgramInvocation));
                    break;
                }
                case ConfirmedServiceResponse_start:
                {
                    ITU_T_SET_CONSTAINED_INDX(39, 76);
                    ITU_T_BIND_PER(*value<Start_Response > (false, ConfirmedServiceResponse_start));
                    break;
                }
                case ConfirmedServiceResponse_stop:
                {
                    ITU_T_SET_CONSTAINED_INDX(40, 76);
                    ITU_T_BIND_PER(*value<Stop_Response > (false, ConfirmedServiceResponse_stop));
                    break;
                }
                case ConfirmedServiceResponse_resume:
                {
                    ITU_T_SET_CONSTAINED_INDX(41, 76);
                    ITU_T_BIND_PER(*value<Resume_Response > (false, ConfirmedServiceResponse_resume));
                    break;
                }
                case ConfirmedServiceResponse_reset:
                {
                    ITU_T_SET_CONSTAINED_INDX(42, 76);
                    ITU_T_BIND_PER(*value<Reset_Response > (false, ConfirmedServiceResponse_reset));
                    break;
                }
                case ConfirmedServiceResponse_kill:
                {
                    ITU_T_SET_CONSTAINED_INDX(43, 76);
                    ITU_T_BIND_PER(*value<Kill_Response > (false, ConfirmedServiceResponse_kill));
                    break;
                }
                case ConfirmedServiceResponse_getProgramInvocationAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(44, 76);
                    ITU_T_BIND_PER(*value<GetProgramInvocationAttributes_Response > (false, ConfirmedServiceResponse_getProgramInvocationAttributes));
                    break;
                }
                case ConfirmedServiceResponse_obtainFile:
                {
                    ITU_T_SET_CONSTAINED_INDX(45, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::ObtainFile_Response > (false, ConfirmedServiceResponse_obtainFile));
                    break;
                }
                case ConfirmedServiceResponse_defineEventCondition:
                {
                    ITU_T_SET_CONSTAINED_INDX(46, 76);
                    ITU_T_BIND_PER(*value<DefineEventCondition_Response > (false, ConfirmedServiceResponse_defineEventCondition));
                    break;
                }
                case ConfirmedServiceResponse_deleteEventCondition:
                {
                    ITU_T_SET_CONSTAINED_INDX(47, 76);
                    ITU_T_BIND_NUM_CONSTRS(*value<DeleteEventCondition_Response > (false, ConfirmedServiceResponse_deleteEventCondition), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceResponse_getEventConditionAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(48, 76);
                    ITU_T_BIND_PER(*value<GetEventConditionAttributes_Response > (false, ConfirmedServiceResponse_getEventConditionAttributes));
                    break;
                }
                case ConfirmedServiceResponse_reportEventConditionStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(49, 76);
                    ITU_T_BIND_PER(*value<ReportEventConditionStatus_Response > (false, ConfirmedServiceResponse_reportEventConditionStatus));
                    break;
                }
                case ConfirmedServiceResponse_alterEventConditionMonitoring:
                {
                    ITU_T_SET_CONSTAINED_INDX(50, 76);
                    ITU_T_BIND_PER(*value<AlterEventConditionMonitoring_Response > (false, ConfirmedServiceResponse_alterEventConditionMonitoring));
                    break;
                }
                case ConfirmedServiceResponse_triggerEvent:
                {
                    ITU_T_SET_CONSTAINED_INDX(51, 76);
                    ITU_T_BIND_PER(*value<TriggerEvent_Response > (false, ConfirmedServiceResponse_triggerEvent));
                    break;
                }
                case ConfirmedServiceResponse_defineEventAction:
                {
                    ITU_T_SET_CONSTAINED_INDX(52, 76);
                    ITU_T_BIND_PER(*value<DefineEventAction_Response > (false, ConfirmedServiceResponse_defineEventAction));
                    break;
                }
                case ConfirmedServiceResponse_deleteEventAction:
                {
                    ITU_T_SET_CONSTAINED_INDX(53, 76);
                    ITU_T_BIND_NUM_CONSTRS(*value<DeleteEventAction_Response > (false, ConfirmedServiceResponse_deleteEventAction), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceResponse_getEventActionAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(54, 76);
                    ITU_T_BIND_PER(*value<GetEventActionAttributes_Response > (false, ConfirmedServiceResponse_getEventActionAttributes));
                    break;
                }
                case ConfirmedServiceResponse_reportEventActionStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(55, 76);
                    ITU_T_BIND_NUM_CONSTRS(*value<ReportEventActionStatus_Response > (false, ConfirmedServiceResponse_reportEventActionStatus), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceResponse_defineEventEnrollment:
                {
                    ITU_T_SET_CONSTAINED_INDX(56, 76);
                    ITU_T_BIND_PER(*value<DefineEventEnrollment_Response > (false, ConfirmedServiceResponse_defineEventEnrollment));
                    break;
                }
                case ConfirmedServiceResponse_deleteEventEnrollment:
                {
                    ITU_T_SET_CONSTAINED_INDX(57, 76);
                    ITU_T_BIND_NUM_CONSTRS(*value<DeleteEventEnrollment_Response > (false, ConfirmedServiceResponse_deleteEventEnrollment), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceResponse_alterEventEnrollment:
                {
                    ITU_T_SET_CONSTAINED_INDX(58, 76);
                    ITU_T_BIND_PER(*value<AlterEventEnrollment_Response > (false, ConfirmedServiceResponse_alterEventEnrollment));
                    break;
                }
                case ConfirmedServiceResponse_reportEventEnrollmentStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(59, 76);
                    ITU_T_BIND_PER(*value<ReportEventEnrollmentStatus_Response > (false, ConfirmedServiceResponse_reportEventEnrollmentStatus));
                    break;
                }
                case ConfirmedServiceResponse_getEventEnrollmentAttributes:
                {
                    ITU_T_SET_CONSTAINED_INDX(60, 76);
                    ITU_T_BIND_PER(*value<GetEventEnrollmentAttributes_Response > (false, ConfirmedServiceResponse_getEventEnrollmentAttributes));
                    break;
                }
                case ConfirmedServiceResponse_acknowledgeEventNotification:
                {
                    ITU_T_SET_CONSTAINED_INDX(61, 76);
                    ITU_T_BIND_PER(*value<AcknowledgeEventNotification_Response > (false, ConfirmedServiceResponse_acknowledgeEventNotification));
                    break;
                }
                case ConfirmedServiceResponse_getAlarmSummary:
                {
                    ITU_T_SET_CONSTAINED_INDX(62, 76);
                    ITU_T_BIND_PER(*value<GetAlarmSummary_Response > (false, ConfirmedServiceResponse_getAlarmSummary));
                    break;
                }
                case ConfirmedServiceResponse_getAlarmEnrollmentSummary:
                {
                    ITU_T_SET_CONSTAINED_INDX(63, 76);
                    ITU_T_BIND_PER(*value<GetAlarmEnrollmentSummary_Response > (false, ConfirmedServiceResponse_getAlarmEnrollmentSummary));
                    break;
                }
                case ConfirmedServiceResponse_readJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(64, 76);
                    ITU_T_BIND_PER(*value<ReadJournal_Response > (false, ConfirmedServiceResponse_readJournal));
                    break;
                }
                case ConfirmedServiceResponse_writeJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(65, 76);
                    ITU_T_BIND_PER(*value<WriteJournal_Response > (false, ConfirmedServiceResponse_writeJournal));
                    break;
                }
                case ConfirmedServiceResponse_initializeJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(66, 76);
                    ITU_T_BIND_NUM_CONSTRS(*value<InitializeJournal_Response > (false, ConfirmedServiceResponse_initializeJournal), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case ConfirmedServiceResponse_reportJournalStatus:
                {
                    ITU_T_SET_CONSTAINED_INDX(67, 76);
                    ITU_T_BIND_PER(*value<ReportJournalStatus_Response > (false, ConfirmedServiceResponse_reportJournalStatus));
                    break;
                }
                case ConfirmedServiceResponse_createJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(68, 76);
                    ITU_T_BIND_PER(*value<CreateJournal_Response > (false, ConfirmedServiceResponse_createJournal));
                    break;
                }
                case ConfirmedServiceResponse_deleteJournal:
                {
                    ITU_T_SET_CONSTAINED_INDX(69, 76);
                    ITU_T_BIND_PER(*value<DeleteJournal_Response > (false, ConfirmedServiceResponse_deleteJournal));
                    break;
                }
                case ConfirmedServiceResponse_getCapabilityList:
                {
                    ITU_T_SET_CONSTAINED_INDX(70, 76);
                    ITU_T_BIND_PER(*value<GetCapabilityList_Response > (false, ConfirmedServiceResponse_getCapabilityList));
                    break;
                }
                case ConfirmedServiceResponse_fileOpen:
                {
                    ITU_T_SET_CONSTAINED_INDX(71, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileOpen_Response > (false, ConfirmedServiceResponse_fileOpen));
                    break;
                }
                case ConfirmedServiceResponse_fileRead:
                {
                    ITU_T_SET_CONSTAINED_INDX(72, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileRead_Response > (false, ConfirmedServiceResponse_fileRead));
                    break;
                }
                case ConfirmedServiceResponse_fileClose:
                {
                    ITU_T_SET_CONSTAINED_INDX(73, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileClose_Response > (false, ConfirmedServiceResponse_fileClose));
                    break;
                }
                case ConfirmedServiceResponse_fileRename:
                {
                    ITU_T_SET_CONSTAINED_INDX(74, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileRename_Response > (false, ConfirmedServiceResponse_fileRename));
                    break;
                }
                case ConfirmedServiceResponse_fileDelete:
                {
                    ITU_T_SET_CONSTAINED_INDX(75, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDelete_Response > (false, ConfirmedServiceResponse_fileDelete));
                    break;
                }
                case ConfirmedServiceResponse_fileDirectory:
                {
                    ITU_T_SET_CONSTAINED_INDX(76, 76);
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDirectory_Response > (false, ConfirmedServiceResponse_fileDirectory));
                    break;
                }
                default:
                {
                }
            }
        }
        else {
            switch (type()) {
                case ConfirmedServiceResponse_additionalService:
                {
                    ITU_T_SET_NSN_SMALL_INDX(0);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<AdditionalService_Response > (false, ConfirmedServiceResponse_additionalService));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_getDataExchangeAttributes:
                {
                    ITU_T_SET_NSN_SMALL_INDX(1);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<GetDataExchangeAttributes_Response > (false, ConfirmedServiceResponse_getDataExchangeAttributes));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_exchangeData:
                {
                    ITU_T_SET_NSN_SMALL_INDX(2);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ExchangeData_Response > (false, ConfirmedServiceResponse_exchangeData));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_defineAccessControlList:
                {
                    ITU_T_SET_NSN_SMALL_INDX(3);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<DefineAccessControlList_Response > (false, ConfirmedServiceResponse_defineAccessControlList));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_getAccessControlListAttributes:
                {
                    ITU_T_SET_NSN_SMALL_INDX(4);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<GetAccessControlListAttributes_Response > (false, ConfirmedServiceResponse_getAccessControlListAttributes));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_reportAccessControlledObjects:
                {
                    ITU_T_SET_NSN_SMALL_INDX(5);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ReportAccessControlledObjects_Response > (false, ConfirmedServiceResponse_reportAccessControlledObjects));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_deleteAccessControlList:
                {
                    ITU_T_SET_NSN_SMALL_INDX(6);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<DeleteAccessControlList_Response > (false, ConfirmedServiceResponse_deleteAccessControlList));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case ConfirmedServiceResponse_changeAccessControl:
                {
                    ITU_T_SET_NSN_SMALL_INDX(7);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ChangeAccessControl_Response > (false, ConfirmedServiceResponse_changeAccessControl));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                default:
                {
                }
            }
        }
    }

    template<> void ConfirmedServiceResponse::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        if (ITU_T_EXTENTION) {

            ITU_T_GET_CONSTAINED_INDX(76);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(*value<Status_Response > (true, ConfirmedServiceResponse_status));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(*value<GetNameList_Response > (true, ConfirmedServiceResponse_getNameList));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(*value<Identify_Response > (true, ConfirmedServiceResponse_identify));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(*value<Rename_Response > (true, ConfirmedServiceResponse_rename));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(*value<Read_Response > (true, ConfirmedServiceResponse_read));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(*value<GetVariableAccessAttributes_Response > (true, ConfirmedServiceResponse_getVariableAccessAttributes));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(*value<DefineNamedVariable_Response > (true, ConfirmedServiceResponse_defineNamedVariable));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (true, ConfirmedServiceResponse_defineScatteredAccess));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (true, ConfirmedServiceResponse_getScatteredAccessAttributes));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(*value<DeleteVariableAccess_Response > (true, ConfirmedServiceResponse_deleteVariableAccess));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(*value<DefineNamedVariableList_Response > (true, ConfirmedServiceResponse_defineNamedVariableList));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(*value<GetNamedVariableListAttributes_Response > (true, ConfirmedServiceResponse_getNamedVariableListAttributes));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(*value<DeleteNamedVariableList_Response > (true, ConfirmedServiceResponse_deleteNamedVariableList));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(*value<DefineNamedType_Response > (true, ConfirmedServiceResponse_defineNamedType));
                    break;
                }
                case 14:
                {
                    ITU_T_BIND_PER(*value<GetNamedTypeAttributes_Response > (true, ConfirmedServiceResponse_getNamedTypeAttributes));
                    break;
                }
                case 15:
                {
                    ITU_T_BIND_PER(*value<DeleteNamedType_Response > (true, ConfirmedServiceResponse_deleteNamedType));
                    break;
                }
                case 16:
                {
                    ITU_T_BIND_PER(*value<Input_Response > (true, ConfirmedServiceResponse_input));
                    break;
                }
                case 17:
                {
                    ITU_T_BIND_PER(*value<Output_Response > (true, ConfirmedServiceResponse_output));
                    break;
                }
                case 18:
                {
                    ITU_T_BIND_PER(*value<TakeControl_Response > (true, ConfirmedServiceResponse_takeControl));
                    break;
                }
                case 19:
                {
                    ITU_T_BIND_PER(*value<RelinquishControl_Response > (true, ConfirmedServiceResponse_relinquishControl));
                    break;
                }
                case 20:
                {
                    ITU_T_BIND_PER(*value<DefineSemaphore_Response > (true, ConfirmedServiceResponse_defineSemaphore));
                    break;
                }
                case 21:
                {
                    ITU_T_BIND_PER(*value<DeleteSemaphore_Response > (true, ConfirmedServiceResponse_deleteSemaphore));
                    break;
                }
                case 22:
                {
                    ITU_T_BIND_PER(*value<ReportSemaphoreStatus_Response > (true, ConfirmedServiceResponse_reportSemaphoreStatus));
                    break;
                }
                case 23:
                {
                    ITU_T_BIND_PER(*value<ReportPoolSemaphoreStatus_Response > (true, ConfirmedServiceResponse_reportPoolSemaphoreStatus));
                    break;
                }
                case 24:
                {
                    ITU_T_BIND_PER(*value<ReportSemaphoreEntryStatus_Response > (true, ConfirmedServiceResponse_reportSemaphoreEntryStatus));
                    break;
                }
                case 25:
                {
                    ITU_T_BIND_PER(*value<InitiateDownloadSequence_Response > (true, ConfirmedServiceResponse_initiateDownloadSequence));
                    break;
                }
                case 26:
                {
                    ITU_T_BIND_PER(*value<DownloadSegment_Response > (true, ConfirmedServiceResponse_downloadSegment));
                    break;
                }
                case 27:
                {
                    ITU_T_BIND_PER(*value<TerminateDownloadSequence_Response > (true, ConfirmedServiceResponse_terminateDownloadSequence));
                    break;
                }
                case 28:
                {
                    ITU_T_BIND_PER(*value<InitiateUploadSequence_Response > (true, ConfirmedServiceResponse_initiateUploadSequence));
                    break;
                }
                case 29:
                {
                    ITU_T_BIND_PER(*value<UploadSegment_Response > (true, ConfirmedServiceResponse_uploadSegment));
                    break;
                }
                case 30:
                {
                    ITU_T_BIND_PER(*value<TerminateUploadSequence_Response > (true, ConfirmedServiceResponse_terminateUploadSequence));
                    break;
                }
                case 31:
                {
                    ITU_T_BIND_PER(*value<RequestDomainDownload_Response > (true, ConfirmedServiceResponse_requestDomainDownload));
                    break;
                }
                case 32:
                {
                    ITU_T_BIND_PER(*value<RequestDomainUpload_Response > (true, ConfirmedServiceResponse_requestDomainUpload));
                    break;
                }
                case 33:
                {
                    ITU_T_BIND_PER(*value<LoadDomainContent_Response > (true, ConfirmedServiceResponse_loadDomainContent));
                    break;
                }
                case 34:
                {
                    ITU_T_BIND_PER(*value<StoreDomainContent_Response > (true, ConfirmedServiceResponse_storeDomainContent));
                    break;
                }
                case 35:
                {
                    ITU_T_BIND_PER(*value<DeleteDomain_Response > (true, ConfirmedServiceResponse_deleteDomain));
                    break;
                }
                case 36:
                {
                    ITU_T_BIND_PER(*value<GetDomainAttributes_Response > (true, ConfirmedServiceResponse_getDomainAttributes));
                    break;
                }
                case 37:
                {
                    ITU_T_BIND_PER(*value<CreateProgramInvocation_Response > (true, ConfirmedServiceResponse_createProgramInvocation));
                    break;
                }
                case 38:
                {
                    ITU_T_BIND_PER(*value<DeleteProgramInvocation_Response > (true, ConfirmedServiceResponse_deleteProgramInvocation));
                    break;
                }
                case 39:
                {
                    ITU_T_BIND_PER(*value<Start_Response > (true, ConfirmedServiceResponse_start));
                    break;
                }
                case 40:
                {
                    ITU_T_BIND_PER(*value<Stop_Response > (true, ConfirmedServiceResponse_stop));
                    break;
                }
                case 41:
                {
                    ITU_T_BIND_PER(*value<Resume_Response > (true, ConfirmedServiceResponse_resume));
                    break;
                }
                case 42:
                {
                    ITU_T_BIND_PER(*value<Reset_Response > (true, ConfirmedServiceResponse_reset));
                    break;
                }
                case 43:
                {
                    ITU_T_BIND_PER(*value<Kill_Response > (true, ConfirmedServiceResponse_kill));
                    break;
                }
                case 44:
                {
                    ITU_T_BIND_PER(*value<GetProgramInvocationAttributes_Response > (true, ConfirmedServiceResponse_getProgramInvocationAttributes));
                    break;
                }
                case 45:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::ObtainFile_Response > (true, ConfirmedServiceResponse_obtainFile));
                    break;
                }
                case 46:
                {
                    ITU_T_BIND_PER(*value<DefineEventCondition_Response > (true, ConfirmedServiceResponse_defineEventCondition));
                    break;
                }
                case 47:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<DeleteEventCondition_Response > (true, ConfirmedServiceResponse_deleteEventCondition), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 48:
                {
                    ITU_T_BIND_PER(*value<GetEventConditionAttributes_Response > (true, ConfirmedServiceResponse_getEventConditionAttributes));
                    break;
                }
                case 49:
                {
                    ITU_T_BIND_PER(*value<ReportEventConditionStatus_Response > (true, ConfirmedServiceResponse_reportEventConditionStatus));
                    break;
                }
                case 50:
                {
                    ITU_T_BIND_PER(*value<AlterEventConditionMonitoring_Response > (true, ConfirmedServiceResponse_alterEventConditionMonitoring));
                    break;
                }
                case 51:
                {
                    ITU_T_BIND_PER(*value<TriggerEvent_Response > (true, ConfirmedServiceResponse_triggerEvent));
                    break;
                }
                case 52:
                {
                    ITU_T_BIND_PER(*value<DefineEventAction_Response > (true, ConfirmedServiceResponse_defineEventAction));
                    break;
                }
                case 53:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<DeleteEventAction_Response > (true, ConfirmedServiceResponse_deleteEventAction), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 54:
                {
                    ITU_T_BIND_PER(*value<GetEventActionAttributes_Response > (true, ConfirmedServiceResponse_getEventActionAttributes));
                    break;
                }
                case 55:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ReportEventActionStatus_Response > (true, ConfirmedServiceResponse_reportEventActionStatus), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 56:
                {
                    ITU_T_BIND_PER(*value<DefineEventEnrollment_Response > (true, ConfirmedServiceResponse_defineEventEnrollment));
                    break;
                }
                case 57:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<DeleteEventEnrollment_Response > (true, ConfirmedServiceResponse_deleteEventEnrollment), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 58:
                {
                    ITU_T_BIND_PER(*value<AlterEventEnrollment_Response > (true, ConfirmedServiceResponse_alterEventEnrollment));
                    break;
                }
                case 59:
                {
                    ITU_T_BIND_PER(*value<ReportEventEnrollmentStatus_Response > (true, ConfirmedServiceResponse_reportEventEnrollmentStatus));
                    break;
                }
                case 60:
                {
                    ITU_T_BIND_PER(*value<GetEventEnrollmentAttributes_Response > (true, ConfirmedServiceResponse_getEventEnrollmentAttributes));
                    break;
                }
                case 61:
                {
                    ITU_T_BIND_PER(*value<AcknowledgeEventNotification_Response > (true, ConfirmedServiceResponse_acknowledgeEventNotification));
                    break;
                }
                case 62:
                {
                    ITU_T_BIND_PER(*value<GetAlarmSummary_Response > (true, ConfirmedServiceResponse_getAlarmSummary));
                    break;
                }
                case 63:
                {
                    ITU_T_BIND_PER(*value<GetAlarmEnrollmentSummary_Response > (true, ConfirmedServiceResponse_getAlarmEnrollmentSummary));
                    break;
                }
                case 64:
                {
                    ITU_T_BIND_PER(*value<ReadJournal_Response > (true, ConfirmedServiceResponse_readJournal));
                    break;
                }
                case 65:
                {
                    ITU_T_BIND_PER(*value<WriteJournal_Response > (true, ConfirmedServiceResponse_writeJournal));
                    break;
                }
                case 66:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<InitializeJournal_Response > (true, ConfirmedServiceResponse_initializeJournal), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 67:
                {
                    ITU_T_BIND_PER(*value<ReportJournalStatus_Response > (true, ConfirmedServiceResponse_reportJournalStatus));
                    break;
                }
                case 68:
                {
                    ITU_T_BIND_PER(*value<CreateJournal_Response > (true, ConfirmedServiceResponse_createJournal));
                    break;
                }
                case 69:
                {
                    ITU_T_BIND_PER(*value<DeleteJournal_Response > (true, ConfirmedServiceResponse_deleteJournal));
                    break;
                }
                case 70:
                {
                    ITU_T_BIND_PER(*value<GetCapabilityList_Response > (true, ConfirmedServiceResponse_getCapabilityList));
                    break;
                }
                case 71:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileOpen_Response > (true, ConfirmedServiceResponse_fileOpen));
                    break;
                }
                case 72:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileRead_Response > (true, ConfirmedServiceResponse_fileRead));
                    break;
                }
                case 73:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileClose_Response > (true, ConfirmedServiceResponse_fileClose));
                    break;
                }
                case 74:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileRename_Response > (true, ConfirmedServiceResponse_fileRename));
                    break;
                }
                case 75:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDelete_Response > (true, ConfirmedServiceResponse_fileDelete));
                    break;
                }
                case 76:
                {
                    ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::FileDirectory_Response > (true, ConfirmedServiceResponse_fileDirectory));
                    break;
                }
                default:
                {
                }
            }
        }
        else {

            ITU_T_GET_NSN_SMALL_INDX;

            switch (__indx__) {
                case 0:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<AdditionalService_Response > (false, ConfirmedServiceResponse_additionalService));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 1:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<GetDataExchangeAttributes_Response > (false, ConfirmedServiceResponse_getDataExchangeAttributes));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 2:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ExchangeData_Response > (false, ConfirmedServiceResponse_exchangeData));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 3:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<DefineAccessControlList_Response > (false, ConfirmedServiceResponse_defineAccessControlList));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 4:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<GetAccessControlListAttributes_Response > (false, ConfirmedServiceResponse_getAccessControlListAttributes));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 5:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ReportAccessControlledObjects_Response > (false, ConfirmedServiceResponse_reportAccessControlledObjects));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 6:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<DeleteAccessControlList_Response > (false, ConfirmedServiceResponse_deleteAccessControlList));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 7:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ChangeAccessControl_Response > (false, ConfirmedServiceResponse_changeAccessControl));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                default:
                {
                    ITU_T_PER_CLEAR_EXTENTION;
                }
            }
        }
    }

    // choice AdditionalService-Response

    template<> void AdditionalService_Response::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Response_vMDStop:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 22);
                ITU_T_BIND_PER(*value<VMDStop_Response > (false, AdditionalService_Response_vMDStop));
                break;
            }
            case AdditionalService_Response_vMDReset:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 22);
                ITU_T_BIND_PER(*value<VMDReset_Response > (false, AdditionalService_Response_vMDReset));
                break;
            }
            case AdditionalService_Response_select:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 22);
                ITU_T_BIND_PER(*value<Select_Response > (false, AdditionalService_Response_select));
                break;
            }
            case AdditionalService_Response_alterPI:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 22);
                ITU_T_BIND_PER(*value<AlterProgramInvocationAttributes_Response > (false, AdditionalService_Response_alterPI));
                break;
            }
            case AdditionalService_Response_initiateUCLoad:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 22);
                ITU_T_BIND_PER(*value<InitiateUnitControlLoad_Response > (false, AdditionalService_Response_initiateUCLoad));
                break;
            }
            case AdditionalService_Response_uCLoad:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 22);
                ITU_T_BIND_PER(*value<UnitControlLoadSegment_Response > (false, AdditionalService_Response_uCLoad));
                break;
            }
            case AdditionalService_Response_uCUpload:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 22);
                ITU_T_BIND_PER(*value<UnitControlUpload_Response > (false, AdditionalService_Response_uCUpload));
                break;
            }
            case AdditionalService_Response_startUC:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 22);
                ITU_T_BIND_PER(*value<StartUnitControl_Response > (false, AdditionalService_Response_startUC));
                break;
            }
            case AdditionalService_Response_stopUC:
            {
                ITU_T_SET_CONSTAINED_INDX(8, 22);
                ITU_T_BIND_PER(*value<StopUnitControl_Response > (false, AdditionalService_Response_stopUC));
                break;
            }
            case AdditionalService_Response_createUC:
            {
                ITU_T_SET_CONSTAINED_INDX(9, 22);
                ITU_T_BIND_PER(*value<CreateUnitControl_Response > (false, AdditionalService_Response_createUC));
                break;
            }
            case AdditionalService_Response_addToUC:
            {
                ITU_T_SET_CONSTAINED_INDX(10, 22);
                ITU_T_BIND_PER(*value<AddToUnitControl_Response > (false, AdditionalService_Response_addToUC));
                break;
            }
            case AdditionalService_Response_removeFromUC:
            {
                ITU_T_SET_CONSTAINED_INDX(11, 22);
                ITU_T_BIND_PER(*value<RemoveFromUnitControl_Response > (false, AdditionalService_Response_removeFromUC));
                break;
            }
            case AdditionalService_Response_getUCAttributes:
            {
                ITU_T_SET_CONSTAINED_INDX(12, 22);
                ITU_T_BIND_PER(*value<GetUnitControlAttributes_Response > (false, AdditionalService_Response_getUCAttributes));
                break;
            }
            case AdditionalService_Response_loadUCFromFile:
            {
                ITU_T_SET_CONSTAINED_INDX(13, 22);
                ITU_T_BIND_PER(*value<LoadUnitControlFromFile_Response > (false, AdditionalService_Response_loadUCFromFile));
                break;
            }
            case AdditionalService_Response_storeUCToFile:
            {
                ITU_T_SET_CONSTAINED_INDX(14, 22);
                ITU_T_BIND_PER(*value<StoreUnitControlToFile_Response > (false, AdditionalService_Response_storeUCToFile));
                break;
            }
            case AdditionalService_Response_deleteUC:
            {
                ITU_T_SET_CONSTAINED_INDX(15, 22);
                ITU_T_BIND_PER(*value<DeleteUnitControl_Response > (false, AdditionalService_Response_deleteUC));
                break;
            }
            case AdditionalService_Response_defineECL:
            {
                ITU_T_SET_CONSTAINED_INDX(16, 22);
                ITU_T_BIND_PER(*value<DefineEventConditionList_Response > (false, AdditionalService_Response_defineECL));
                break;
            }
            case AdditionalService_Response_deleteECL:
            {
                ITU_T_SET_CONSTAINED_INDX(17, 22);
                ITU_T_BIND_PER(*value<DeleteEventConditionList_Response > (false, AdditionalService_Response_deleteECL));
                break;
            }
            case AdditionalService_Response_addECLReference:
            {
                ITU_T_SET_CONSTAINED_INDX(18, 22);
                ITU_T_BIND_PER(*value<AddEventConditionListReference_Response > (false, AdditionalService_Response_addECLReference));
                break;
            }
            case AdditionalService_Response_removeECLReference:
            {
                ITU_T_SET_CONSTAINED_INDX(19, 22);
                ITU_T_BIND_PER(*value<RemoveEventConditionListReference_Response > (false, AdditionalService_Response_removeECLReference));
                break;
            }
            case AdditionalService_Response_getECLAttributes:
            {
                ITU_T_SET_CONSTAINED_INDX(20, 22);
                ITU_T_BIND_PER(*value<GetEventConditionListAttributes_Response > (false, AdditionalService_Response_getECLAttributes));
                break;
            }
            case AdditionalService_Response_reportECLStatus:
            {
                ITU_T_SET_CONSTAINED_INDX(21, 22);
                ITU_T_BIND_PER(*value<ReportEventConditionListStatus_Response > (false, AdditionalService_Response_reportECLStatus));
                break;
            }
            case AdditionalService_Response_alterECLMonitoring:
            {
                ITU_T_SET_CONSTAINED_INDX(22, 22);
                ITU_T_BIND_PER(*value<AlterEventConditionListMonitoring_Response > (false, AdditionalService_Response_alterECLMonitoring));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AdditionalService_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(22);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<VMDStop_Response > (true, AdditionalService_Response_vMDStop));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<VMDReset_Response > (true, AdditionalService_Response_vMDReset));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Select_Response > (true, AdditionalService_Response_select));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<AlterProgramInvocationAttributes_Response > (true, AdditionalService_Response_alterPI));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<InitiateUnitControlLoad_Response > (true, AdditionalService_Response_initiateUCLoad));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*value<UnitControlLoadSegment_Response > (true, AdditionalService_Response_uCLoad));
                break;
            }
            case 6:
            {
                ITU_T_BIND_PER(*value<UnitControlUpload_Response > (true, AdditionalService_Response_uCUpload));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(*value<StartUnitControl_Response > (true, AdditionalService_Response_startUC));
                break;
            }
            case 8:
            {
                ITU_T_BIND_PER(*value<StopUnitControl_Response > (true, AdditionalService_Response_stopUC));
                break;
            }
            case 9:
            {
                ITU_T_BIND_PER(*value<CreateUnitControl_Response > (true, AdditionalService_Response_createUC));
                break;
            }
            case 10:
            {
                ITU_T_BIND_PER(*value<AddToUnitControl_Response > (true, AdditionalService_Response_addToUC));
                break;
            }
            case 11:
            {
                ITU_T_BIND_PER(*value<RemoveFromUnitControl_Response > (true, AdditionalService_Response_removeFromUC));
                break;
            }
            case 12:
            {
                ITU_T_BIND_PER(*value<GetUnitControlAttributes_Response > (true, AdditionalService_Response_getUCAttributes));
                break;
            }
            case 13:
            {
                ITU_T_BIND_PER(*value<LoadUnitControlFromFile_Response > (true, AdditionalService_Response_loadUCFromFile));
                break;
            }
            case 14:
            {
                ITU_T_BIND_PER(*value<StoreUnitControlToFile_Response > (true, AdditionalService_Response_storeUCToFile));
                break;
            }
            case 15:
            {
                ITU_T_BIND_PER(*value<DeleteUnitControl_Response > (true, AdditionalService_Response_deleteUC));
                break;
            }
            case 16:
            {
                ITU_T_BIND_PER(*value<DefineEventConditionList_Response > (true, AdditionalService_Response_defineECL));
                break;
            }
            case 17:
            {
                ITU_T_BIND_PER(*value<DeleteEventConditionList_Response > (true, AdditionalService_Response_deleteECL));
                break;
            }
            case 18:
            {
                ITU_T_BIND_PER(*value<AddEventConditionListReference_Response > (true, AdditionalService_Response_addECLReference));
                break;
            }
            case 19:
            {
                ITU_T_BIND_PER(*value<RemoveEventConditionListReference_Response > (true, AdditionalService_Response_removeECLReference));
                break;
            }
            case 20:
            {
                ITU_T_BIND_PER(*value<GetEventConditionListAttributes_Response > (true, AdditionalService_Response_getECLAttributes));
                break;
            }
            case 21:
            {
                ITU_T_BIND_PER(*value<ReportEventConditionListStatus_Response > (true, AdditionalService_Response_reportECLStatus));
                break;
            }
            case 22:
            {
                ITU_T_BIND_PER(*value<AlterEventConditionListMonitoring_Response > (true, AdditionalService_Response_alterECLMonitoring));
                break;
            }
            default:
            {
            }
        }
    }

    // choice Response-Detail

    template<> void Response_Detail::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Response_Detail_otherRequests:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<null_type > (false, Response_Detail_otherRequests));
                break;
            }
            case Response_Detail_status:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(*value<CS_Status_Response > (false, Response_Detail_status));
                break;
            }
            case Response_Detail_getProgramInvocationAttributes:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<CS_GetProgramInvocationAttributes_Response > (false, Response_Detail_getProgramInvocationAttributes));
                break;
            }
            case Response_Detail_getEventConditionAttributes:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<CS_GetEventConditionAttributes_Response > (false, Response_Detail_getEventConditionAttributes));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Response_Detail::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Response_Detail_otherRequests));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<CS_Status_Response > (true, Response_Detail_status));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<CS_GetProgramInvocationAttributes_Response > (true, Response_Detail_getProgramInvocationAttributes));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<CS_GetEventConditionAttributes_Response > (true, Response_Detail_getEventConditionAttributes));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Confirmed-ErrorPDU

    template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(modifierPosition_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(modifierPosition_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*serviceError_);
    }

    template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_NUM_CONSTRS(*invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(modifierPosition_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*serviceError_);
    }

    // sequence ServiceError

    template<> void ServiceError::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(additionalCode_) +
                ITU_T_EXISTS_BMP(additionalDescription_) +
                ITU_T_EXISTS_BMP(serviceSpecificInfo_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*errorClass_);
        ITU_T_BIND_PER(additionalCode_);
        ITU_T_BIND_PER(additionalDescription_);
        ITU_T_BIND_PER(serviceSpecificInfo_);
    }

    template<> void ServiceError::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(*errorClass_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(additionalCode_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(additionalDescription_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(serviceSpecificInfo_);
    }

    // choice errorClass

    template<> void ServiceError::ErrorClass_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ErrorClass_type_vmd_state:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_vmd_state), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case ErrorClass_type_application_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_application_reference), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case ErrorClass_type_definition:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_definition), static_cast<uint8_t> (0), static_cast<uint8_t> (6));
                break;
            }
            case ErrorClass_type_resource:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_resource), static_cast<uint8_t> (0), static_cast<uint8_t> (5));
                break;
            }
            case ErrorClass_type_service:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_service), static_cast<uint8_t> (0), static_cast<uint8_t> (5));
                break;
            }
            case ErrorClass_type_service_preempt:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_service_preempt), static_cast<uint8_t> (0), static_cast<uint8_t> (3));
                break;
            }
            case ErrorClass_type_time_resolution:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_time_resolution), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case ErrorClass_type_access:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_access), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case ErrorClass_type_initiate:
            {
                ITU_T_SET_CONSTAINED_INDX(8, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_initiate), static_cast<uint8_t> (0), static_cast<uint8_t> (7));
                break;
            }
            case ErrorClass_type_conclude:
            {
                ITU_T_SET_CONSTAINED_INDX(9, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_conclude), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case ErrorClass_type_cancel:
            {
                ITU_T_SET_CONSTAINED_INDX(10, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_cancel), static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                break;
            }
            case ErrorClass_type_file:
            {
                ITU_T_SET_CONSTAINED_INDX(11, 12);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ErrorClass_type_file), static_cast<uint8_t> (0), static_cast<uint8_t> (9));
                break;
            }
            case ErrorClass_type_others:
            {
                ITU_T_SET_CONSTAINED_INDX(12, 12);
                ITU_T_BIND_PER(*value<integer_type > (false, ErrorClass_type_others));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ServiceError::ErrorClass_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(12);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_vmd_state), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_application_reference), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case 2:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_definition), static_cast<uint8_t> (0), static_cast<uint8_t> (6));
                break;
            }
            case 3:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_resource), static_cast<uint8_t> (0), static_cast<uint8_t> (5));
                break;
            }
            case 4:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_service), static_cast<uint8_t> (0), static_cast<uint8_t> (5));
                break;
            }
            case 5:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_service_preempt), static_cast<uint8_t> (0), static_cast<uint8_t> (3));
                break;
            }
            case 6:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_time_resolution), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 7:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_access), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case 8:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_initiate), static_cast<uint8_t> (0), static_cast<uint8_t> (7));
                break;
            }
            case 9:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_conclude), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 10:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_cancel), static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                break;
            }
            case 11:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ErrorClass_type_file), static_cast<uint8_t> (0), static_cast<uint8_t> (9));
                break;
            }
            case 12:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, ErrorClass_type_others));
                break;
            }
            default:
            {
            }
        }
    }

    // choice serviceSpecificInfo

    template<> void ServiceError::ServiceSpecificInfo_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ServiceSpecificInfo_type_obtainFile:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::ObtainFile_Error > (false, ServiceSpecificInfo_type_obtainFile), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case ServiceSpecificInfo_type_start:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<Start_Error > (false, ServiceSpecificInfo_type_start), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case ServiceSpecificInfo_type_stop:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<Stop_Error > (false, ServiceSpecificInfo_type_stop), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case ServiceSpecificInfo_type_resume:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<Resume_Error > (false, ServiceSpecificInfo_type_resume), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case ServiceSpecificInfo_type_reset:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<Reset_Error > (false, ServiceSpecificInfo_type_reset), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case ServiceSpecificInfo_type_deleteVariableAccess:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<DeleteVariableAccess_Error > (false, ServiceSpecificInfo_type_deleteVariableAccess), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case ServiceSpecificInfo_type_deleteNamedVariableList:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<DeleteNamedVariableList_Error > (false, ServiceSpecificInfo_type_deleteNamedVariableList), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case ServiceSpecificInfo_type_deleteNamedType:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<DeleteNamedType_Error > (false, ServiceSpecificInfo_type_deleteNamedType), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case ServiceSpecificInfo_type_defineEventEnrollment_Error:
            {
                ITU_T_SET_CONSTAINED_INDX(8, 11);
                ITU_T_BIND_PER(*value<DefineEventEnrollment_Error > (false, ServiceSpecificInfo_type_defineEventEnrollment_Error));
                break;
            }
            case ServiceSpecificInfo_type_fileRename:
            {
                ITU_T_SET_CONSTAINED_INDX(9, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::FileRename_Error > (false, ServiceSpecificInfo_type_fileRename), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case ServiceSpecificInfo_type_additionalService:
            {
                ITU_T_SET_CONSTAINED_INDX(10, 11);
                ITU_T_BIND_PER(*value<AdditionalService_Error > (false, ServiceSpecificInfo_type_additionalService));
                break;
            }
            case ServiceSpecificInfo_type_changeAccessControl:
            {
                ITU_T_SET_CONSTAINED_INDX(11, 11);
                ITU_T_BIND_NUM_CONSTRS(*value<ChangeAccessControl_Error > (false, ServiceSpecificInfo_type_changeAccessControl), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ServiceError::ServiceSpecificInfo_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(11);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::ObtainFile_Error > (true, ServiceSpecificInfo_type_obtainFile), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Start_Error > (true, ServiceSpecificInfo_type_start), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case 2:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Stop_Error > (true, ServiceSpecificInfo_type_stop), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case 3:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Resume_Error > (true, ServiceSpecificInfo_type_resume), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case 4:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Reset_Error > (true, ServiceSpecificInfo_type_reset), static_cast<uint8_t> (0), static_cast<uint8_t> (8));
                break;
            }
            case 5:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<DeleteVariableAccess_Error > (true, ServiceSpecificInfo_type_deleteVariableAccess), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 6:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<DeleteNamedVariableList_Error > (true, ServiceSpecificInfo_type_deleteNamedVariableList), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 7:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<DeleteNamedType_Error > (true, ServiceSpecificInfo_type_deleteNamedType), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 8:
            {
                ITU_T_BIND_PER(*value<DefineEventEnrollment_Error > (true, ServiceSpecificInfo_type_defineEventEnrollment_Error));
                break;
            }
            case 9:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1A::FileRename_Error > (true, ServiceSpecificInfo_type_fileRename), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 10:
            {
                ITU_T_BIND_PER(*value<AdditionalService_Error > (true, ServiceSpecificInfo_type_additionalService));
                break;
            }
            case 11:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<ChangeAccessControl_Error > (true, ServiceSpecificInfo_type_changeAccessControl), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            default:
            {
            }
        }
    }

    // choice AdditionalService-Error

    template<> void AdditionalService_Error::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Error_defineEcl:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 7);
                ITU_T_BIND_PER(*value<DefineEventConditionList_Error > (false, AdditionalService_Error_defineEcl));
                break;
            }
            case AdditionalService_Error_addECLReference:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 7);
                ITU_T_BIND_PER(*value<AddEventConditionListReference_Error > (false, AdditionalService_Error_addECLReference));
                break;
            }
            case AdditionalService_Error_removeECLReference:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 7);
                ITU_T_BIND_PER(*value<RemoveEventConditionListReference_Error > (false, AdditionalService_Error_removeECLReference));
                break;
            }
            case AdditionalService_Error_initiateUC:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 7);
                ITU_T_BIND_PER(*value<InitiateUnitControl_Error > (false, AdditionalService_Error_initiateUC));
                break;
            }
            case AdditionalService_Error_startUC:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 7);
                ITU_T_BIND_PER(*value<StartUnitControl_Error > (false, AdditionalService_Error_startUC));
                break;
            }
            case AdditionalService_Error_stopUC:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 7);
                ITU_T_BIND_PER(*value<StopUnitControl_Error > (false, AdditionalService_Error_stopUC));
                break;
            }
            case AdditionalService_Error_deleteUC:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 7);
                ITU_T_BIND_PER(*value<DeleteUnitControl_Error > (false, AdditionalService_Error_deleteUC));
                break;
            }
            case AdditionalService_Error_loadUCFromFile:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 7);
                ITU_T_BIND_PER(*value<LoadUnitControlFromFile_Error > (false, AdditionalService_Error_loadUCFromFile));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AdditionalService_Error::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(7);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<DefineEventConditionList_Error > (true, AdditionalService_Error_defineEcl));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<AddEventConditionListReference_Error > (true, AdditionalService_Error_addECLReference));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<RemoveEventConditionListReference_Error > (true, AdditionalService_Error_removeECLReference));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<InitiateUnitControl_Error > (true, AdditionalService_Error_initiateUC));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<StartUnitControl_Error > (true, AdditionalService_Error_startUC));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*value<StopUnitControl_Error > (true, AdditionalService_Error_stopUC));
                break;
            }
            case 6:
            {
                ITU_T_BIND_PER(*value<DeleteUnitControl_Error > (true, AdditionalService_Error_deleteUC));
                break;
            }
            case 7:
            {
                ITU_T_BIND_PER(*value<LoadUnitControlFromFile_Error > (true, AdditionalService_Error_loadUCFromFile));
                break;
            }
            default:
            {
            }
        }
    }

    // choice ObjectName

    template<> void ObjectName::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ObjectName_vmd_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ObjectName_vmd_specific));
                break;
            }
            case ObjectName_domain_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<Domain_specific_type > (false, ObjectName_domain_specific));
                break;
            }
            case ObjectName_aa_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ObjectName_aa_specific));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ObjectName::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ObjectName_vmd_specific));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Domain_specific_type > (true, ObjectName_domain_specific));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ObjectName_aa_specific));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence domain-specific

    template<> void ObjectName::Domain_specific_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*domainID_);
        ITU_T_BIND_PER(*itemID_);
    }

    template<> void ObjectName::Domain_specific_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*domainID_);
        ITU_T_BIND_PER(*itemID_);
    }

    // choice ObjectClass

    template<> void ObjectClass::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_CHOICE(ObjectClass_csObjectClass, ObjectClass_csObjectClass);

        if (ITU_T_EXTENTION) {
            ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ObjectClass_basicObjectClass), static_cast<uint8_t> (0), static_cast<uint8_t> (13))
        }
        else {
            switch (type()) {
                case ObjectClass_csObjectClass:
                {
                    ITU_T_SET_NSN_SMALL_INDX(0);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ObjectClass_csObjectClass), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                default:
                {
                }
            }
        }
    }

    template<> void ObjectClass::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        if (ITU_T_EXTENTION) {
            ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, ObjectClass_basicObjectClass), static_cast<uint8_t> (0), static_cast<uint8_t> (13))
        }
        else {

            ITU_T_GET_NSN_SMALL_INDX;

            switch (__indx__) {
                case 0:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, ObjectClass_csObjectClass), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                default:
                {
                    ITU_T_PER_CLEAR_EXTENTION;
                }
            }
        }
    }

    // sequence Initiate-RequestPDU

    template<> void Initiate_RequestPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(localDetailCalling_) +
                ITU_T_EXISTS_BMP(proposedDataStructureNestingLevel_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(localDetailCalling_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*proposedMaxServOutstandingCalling_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*proposedMaxServOutstandingCalled_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(proposedDataStructureNestingLevel_, static_cast<int8_t> (-128), static_cast<int8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(*initRequestDetail_);
    }

    template<> void Initiate_RequestPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(localDetailCalling_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*proposedMaxServOutstandingCalling_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*proposedMaxServOutstandingCalled_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(proposedDataStructureNestingLevel_, static_cast<int8_t> (-128), static_cast<int8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(*initRequestDetail_);
    }

    // sequence initRequestDetail

    template<> void Initiate_RequestPDU::InitRequestDetail_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(additionalSupportedCalling_);
        ITU_T_EXTENTION_GROUP_BOOL(1) = ITU_T_EXISTS_BOOL(additionalCbbSupportedCalling_);
        ITU_T_EXTENTION_GROUP_BOOL(2) = ITU_T_EXISTS_BOOL(privilegeClassIdentityCalling_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0) + ITU_T_EXTENTION_GROUP_AS_BMP(1) + ITU_T_EXTENTION_GROUP_AS_BMP(2);

        ITU_T_EXTENTION_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*proposedVersionNumber_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_SIZE_SNGLCONSTRS(*proposedParameterCBB_, 18);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*servicesSupportedCalling_, 93);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalSupportedCalling_, 23);
                ITU_T_PER_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalCbbSupportedCalling_, 3);
                ITU_T_PER_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_PER(*privilegeClassIdentityCalling_);
                ITU_T_PER_END_OPEN;
            }

        };

    }

    template<> void Initiate_RequestPDU::InitRequestDetail_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_NUM_CONSTRS(*proposedVersionNumber_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_SIZE_SNGLCONSTRS(*proposedParameterCBB_, 18);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*servicesSupportedCalling_, 93);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalSupportedCalling_, 23);
                ITU_T_PER_END_PARSE_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalCbbSupportedCalling_, 3);
                ITU_T_PER_END_PARSE_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_PER(*privilegeClassIdentityCalling_);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(3);
        };

    }

    // sequence Initiate-ResponsePDU

    template<> void Initiate_ResponsePDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(localDetailCalled_) +
                ITU_T_EXISTS_BMP(negotiatedDataStructureNestingLevel_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(localDetailCalled_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*negotiatedMaxServOutstandingCalling_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*negotiatedMaxServOutstandingCalled_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(negotiatedDataStructureNestingLevel_, static_cast<int8_t> (-128), static_cast<int8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(*initResponseDetail_);
    }

    template<> void Initiate_ResponsePDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(localDetailCalled_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*negotiatedMaxServOutstandingCalling_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*negotiatedMaxServOutstandingCalled_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(negotiatedDataStructureNestingLevel_, static_cast<int8_t> (-128), static_cast<int8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(*initResponseDetail_);
    }

    // sequence initResponseDetail

    template<> void Initiate_ResponsePDU::InitResponseDetail_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(additionalSupportedCalled_);
        ITU_T_EXTENTION_GROUP_BOOL(1) = ITU_T_EXISTS_BOOL(additionalCbbSupportedCalled_);
        ITU_T_EXTENTION_GROUP_BOOL(2) = ITU_T_EXISTS_BOOL(privilegeClassIdentityCalled_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0) + ITU_T_EXTENTION_GROUP_AS_BMP(1) + ITU_T_EXTENTION_GROUP_AS_BMP(2);

        ITU_T_EXTENTION_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*negotiatedVersionNumber_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_SIZE_SNGLCONSTRS(*negotiatedParameterCBB_, 18);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*servicesSupportedCalled_, 93);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalSupportedCalled_, 23);
                ITU_T_PER_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalCbbSupportedCalled_, 3);
                ITU_T_PER_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_PER(*privilegeClassIdentityCalled_);
                ITU_T_PER_END_OPEN;
            }

        };

    }

    template<> void Initiate_ResponsePDU::InitResponseDetail_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_NUM_CONSTRS(*negotiatedVersionNumber_, static_cast<int16_t> (std::numeric_limits<int16_t>::min()), static_cast<int16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_SIZE_SNGLCONSTRS(*negotiatedParameterCBB_, 18);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*servicesSupportedCalled_, 93);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalSupportedCalled_, 23);
                ITU_T_PER_END_PARSE_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*additionalCbbSupportedCalled_, 3);
                ITU_T_PER_END_PARSE_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_PER(*privilegeClassIdentityCalled_);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(3);
        };

    }

    // sequence Cancel-ErrorPDU

    template<> void Cancel_ErrorPDU::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*originalInvokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*serviceError_);
    }

    template<> void Cancel_ErrorPDU::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*originalInvokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*serviceError_);
    }

    // sequence RejectPDU

    template<> void RejectPDU::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(originalInvokeID_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(originalInvokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*rejectReason_);
    }

    template<> void RejectPDU::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(originalInvokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*rejectReason_);
    }

    // choice rejectReason

    template<> void RejectPDU::RejectReason_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RejectReason_type_confirmed_requestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_confirmed_requestPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (9));
                break;
            }
            case RejectReason_type_confirmed_responsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_confirmed_responsePDU), static_cast<uint8_t> (0), static_cast<uint8_t> (6));
                break;
            }
            case RejectReason_type_confirmed_errorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_confirmed_errorPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case RejectReason_type_unconfirmedPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_unconfirmedPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case RejectReason_type_pdu_error:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 10);
                ITU_T_BIND_PER(*value<integer_type > (false, RejectReason_type_pdu_error));
                break;
            }
            case RejectReason_type_cancel_requestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_cancel_requestPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case RejectReason_type_cancel_responsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(6, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_cancel_responsePDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case RejectReason_type_cancel_errorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(7, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_cancel_errorPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (3));
                break;
            }
            case RejectReason_type_conclude_requestPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(8, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_conclude_requestPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case RejectReason_type_conclude_responsePDU:
            {
                ITU_T_SET_CONSTAINED_INDX(9, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_conclude_responsePDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case RejectReason_type_conclude_errorPDU:
            {
                ITU_T_SET_CONSTAINED_INDX(10, 10);
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (false, RejectReason_type_conclude_errorPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RejectPDU::RejectReason_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(10);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_confirmed_requestPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (9));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_confirmed_responsePDU), static_cast<uint8_t> (0), static_cast<uint8_t> (6));
                break;
            }
            case 2:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_confirmed_errorPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case 3:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_unconfirmedPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (4));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, RejectReason_type_pdu_error));
                break;
            }
            case 5:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_cancel_requestPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 6:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_cancel_responsePDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 7:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_cancel_errorPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (3));
                break;
            }
            case 8:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_conclude_requestPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 9:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_conclude_responsePDU), static_cast<uint8_t> (0), static_cast<uint8_t> (1));
                break;
            }
            case 10:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<uint8_t > (true, RejectReason_type_conclude_errorPDU), static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence DefineAccessControlList-Request

    template<> void DefineAccessControlList_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControlListName_);
        ITU_T_BIND_PER(*accessControlListElements_);
    }

    template<> void DefineAccessControlList_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControlListName_);
        ITU_T_BIND_PER(*accessControlListElements_);
    }

    // sequence accessControlListElements

    template<> void DefineAccessControlList_Request::AccessControlListElements_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(readAccessCondition_) +
                ITU_T_EXISTS_BMP(storeAccessCondition_) +
                ITU_T_EXISTS_BMP(writeAccessCondition_) +
                ITU_T_EXISTS_BMP(loadAccessCondition_) +
                ITU_T_EXISTS_BMP(executeAccessCondition_) +
                ITU_T_EXISTS_BMP(deleteAccessCondition_) +
                ITU_T_EXISTS_BMP(editAccessCondition_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_BIND_PER(editAccessCondition_);
    }

    template<> void DefineAccessControlList_Request::AccessControlListElements_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(7);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(editAccessCondition_);
    }

    // choice GetAccessControlListAttributes-Request

    template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case GetAccessControlListAttributes_Request_accessControlListName:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, GetAccessControlListAttributes_Request_accessControlListName));
                break;
            }
            case GetAccessControlListAttributes_Request_vMD:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<null_type > (false, GetAccessControlListAttributes_Request_vMD));
                break;
            }
            case GetAccessControlListAttributes_Request_namedObject:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<NamedObject_type > (false, GetAccessControlListAttributes_Request_namedObject));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, GetAccessControlListAttributes_Request_accessControlListName));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, GetAccessControlListAttributes_Request_vMD));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<NamedObject_type > (true, GetAccessControlListAttributes_Request_namedObject));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence namedObject

    template<> void GetAccessControlListAttributes_Request::NamedObject_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectName_);
    }

    template<> void GetAccessControlListAttributes_Request::NamedObject_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectName_);
    }

    // sequence GetAccessControlListAttributes-Response

    template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*accessControlListElements_);
        ITU_T_BIND_PER(*vMDuse_);
        ITU_T_BIND_PER(*references_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*accessControlListElements_);
        ITU_T_BIND_PER(*vMDuse_);
        ITU_T_BIND_PER(*references_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence accessControlListElements

    template<> void GetAccessControlListAttributes_Response::AccessControlListElements_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(readAccessCondition_) +
                ITU_T_EXISTS_BMP(storeAccessCondition_) +
                ITU_T_EXISTS_BMP(writeAccessCondition_) +
                ITU_T_EXISTS_BMP(loadAccessCondition_) +
                ITU_T_EXISTS_BMP(executeAccessCondition_) +
                ITU_T_EXISTS_BMP(deleteAccessCondition_) +
                ITU_T_EXISTS_BMP(editAccessCondition_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_BIND_PER(editAccessCondition_);
    }

    template<> void GetAccessControlListAttributes_Response::AccessControlListElements_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(7);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(editAccessCondition_);
    }

    // sequence 

    template<> void GetAccessControlListAttributes_Response::References_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectCount_);
    }

    template<> void GetAccessControlListAttributes_Response::References_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectCount_);
    }

    // sequence ReportAccessControlledObjects-Request

    template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*accessControlList_);
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*accessControlList_);
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence ReportAccessControlledObjects-Response

    template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfNames_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfNames_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence ChangeAccessControl-Request

    template<> void ChangeAccessControl_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*scopeOfChange_);
        ITU_T_BIND_PER(*accessControlListName_);
    }

    template<> void ChangeAccessControl_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*scopeOfChange_);
        ITU_T_BIND_PER(*accessControlListName_);
    }

    // choice scopeOfChange

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ScopeOfChange_type_vMDOnly:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, ScopeOfChange_type_vMDOnly));
                break;
            }
            case ScopeOfChange_type_listOfObjects:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<ListOfObjects_type > (false, ScopeOfChange_type_listOfObjects));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ScopeOfChange_type_vMDOnly));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ListOfObjects_type > (true, ScopeOfChange_type_listOfObjects));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence listOfObjects

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectScope_);
    }

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectScope_);
    }

    // choice objectScope

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ObjectScope_type_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<Specific_type > (false, ObjectScope_type_specific));
                break;
            }
            case ObjectScope_type_aa_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(*value<null_type > (false, ObjectScope_type_aa_specific));
                break;
            }
            case ObjectScope_type_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<Identifier > (false, ObjectScope_type_domain));
                break;
            }
            case ObjectScope_type_vmd:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<null_type > (false, ObjectScope_type_vmd));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ChangeAccessControl_Request::ScopeOfChange_type::ListOfObjects_type::ObjectScope_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Specific_type > (true, ObjectScope_type_specific));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ObjectScope_type_aa_specific));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ObjectScope_type_domain));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ObjectScope_type_vmd));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence ChangeAccessControl-Response

    template<> void ChangeAccessControl_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberChanged_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void ChangeAccessControl_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberChanged_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence StatusResponse

    template<> void StatusResponse::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(localDetail_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*vmdLogicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_NUM_CONSTRS(*vmdPhysicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_SIZE_CONSTRS(localDetail_, 0, 128);
    }

    template<> void StatusResponse::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_NUM_CONSTRS(*vmdLogicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_NUM_CONSTRS(*vmdPhysicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_SIZE_CONSTRS(localDetail_, 0, 128);
    }

    // choice CS-Status-Response

    template<> void CS_Status_Response::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CS_Status_Response_noExtraResponse:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, CS_Status_Response_noExtraResponse));
                break;
            }
            case CS_Status_Response_fullResponse:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<FullResponse_type > (false, CS_Status_Response_fullResponse));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Status_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CS_Status_Response_noExtraResponse));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<FullResponse_type > (true, CS_Status_Response_fullResponse));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence fullResponse

    template<> void CS_Status_Response::FullResponse_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(extendedStatusMask_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*operationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (5));
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedStatus_, 4);
        ITU_T_BIND_SIZE_SNGLCONSTRS(extendedStatusMask_, 4);
        ITU_T_BIND_PER(*selectedProgramInvocation_);
    }

    template<> void CS_Status_Response::FullResponse_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_NUM_CONSTRS(*operationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (5));
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedStatus_, 4);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_SIZE_SNGLCONSTRS(extendedStatusMask_, 4);
        ITU_T_BIND_PER(*selectedProgramInvocation_);
    }

    // choice selectedProgramInvocation

    template<> void CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case SelectedProgramInvocation_type_programInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, SelectedProgramInvocation_type_programInvocation));
                break;
            }
            case SelectedProgramInvocation_type_noneSelected:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, SelectedProgramInvocation_type_noneSelected));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Status_Response::FullResponse_type::SelectedProgramInvocation_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, SelectedProgramInvocation_type_programInvocation));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, SelectedProgramInvocation_type_noneSelected));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetNameList-Request

    template<> void GetNameList_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectScope_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void GetNameList_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*objectScope_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(continueAfter_);
    }

    // choice objectScope

    template<> void GetNameList_Request::ObjectScope_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ObjectScope_type_vmdSpecific:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, ObjectScope_type_vmdSpecific));
                break;
            }
            case ObjectScope_type_domainSpecific:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ObjectScope_type_domainSpecific));
                break;
            }
            case ObjectScope_type_aaSpecific:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, ObjectScope_type_aaSpecific));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetNameList_Request::ObjectScope_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ObjectScope_type_vmdSpecific));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ObjectScope_type_domainSpecific));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ObjectScope_type_aaSpecific));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetNameList-Response

    template<> void GetNameList_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfIdentifier_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void GetNameList_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfIdentifier_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence Identify-Response

    template<> void Identify_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfAbstractSyntaxes_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*vendorName_);
        ITU_T_BIND_PER(*modelName_);
        ITU_T_BIND_PER(*revision_);
        ITU_T_BIND_PER(listOfAbstractSyntaxes_);
    }

    template<> void Identify_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*vendorName_);
        ITU_T_BIND_PER(*modelName_);
        ITU_T_BIND_PER(*revision_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfAbstractSyntaxes_);
    }

    // sequence Rename-Request

    template<> void Rename_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*currentName_);
        ITU_T_BIND_PER(*newIdentifier_);
    }

    template<> void Rename_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*objectClass_);
        ITU_T_BIND_PER(*currentName_);
        ITU_T_BIND_PER(*newIdentifier_);
    }

    // sequence GetCapabilityList-Request

    template<> void GetCapabilityList_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void GetCapabilityList_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence GetCapabilityList-Response

    template<> void GetCapabilityList_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfCapabilities_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void GetCapabilityList_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfCapabilities_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence InitiateDownloadSequence-Request

    template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*listOfCapabilities_);
        ITU_T_BIND_PER(*sharable_);
    }

    template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*listOfCapabilities_);
        ITU_T_BIND_PER(*sharable_);
    }

    // sequence DownloadSegment-Response

    template<> void DownloadSegment_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*loadData_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void DownloadSegment_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*loadData_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // choice LoadData

    template<> void LoadData::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case LoadData_coded:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<external_type > (false, LoadData_coded));
                break;
            }
            case LoadData_embedded:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<embeded_type > (false, LoadData_embedded));
                break;
            }
            case LoadData_non_coded:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<octetstring_type > (false, LoadData_non_coded));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void LoadData::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<external_type > (true, LoadData_coded));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<embeded_type > (true, LoadData_embedded));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<octetstring_type > (true, LoadData_non_coded));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence TerminateDownloadSequence-Request

    template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(discard_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(discard_);
    }

    template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*domainName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(discard_);
    }

    // sequence InitiateUploadSequence-Response

    template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*ulsmID_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*listOfCapabilities_);
    }

    template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*ulsmID_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*listOfCapabilities_);
    }

    // sequence UploadSegment-Response

    template<> void UploadSegment_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*loadData_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void UploadSegment_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*loadData_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence RequestDomainDownload-Request

    template<> void RequestDomainDownload_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfCapabilities_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(listOfCapabilities_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*fileName_);
    }

    template<> void RequestDomainDownload_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*domainName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfCapabilities_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*fileName_);
    }

    // sequence RequestDomainUpload-Request

    template<> void RequestDomainUpload_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*fileName_);
    }

    template<> void RequestDomainUpload_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*fileName_);
    }

    // sequence LoadDomainContent-Request

    template<> void LoadDomainContent_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfCapabilities_) +
                ITU_T_EXISTS_BMP(thirdParty_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(listOfCapabilities_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(thirdParty_);
    }

    template<> void LoadDomainContent_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*domainName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfCapabilities_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(thirdParty_);
    }

    // sequence StoreDomainContent-Request

    template<> void StoreDomainContent_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(thirdParty_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(thirdParty_);
    }

    template<> void StoreDomainContent_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(thirdParty_);
    }

    // sequence GetDomainAttributes-Response

    template<> void GetDomainAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfCapabilities_);
        ITU_T_BIND_NUM_CONSTRS(*state_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*listOfProgramInvocations_);
        ITU_T_BIND_NUM_CONSTRS(*uploadInProgress_, static_cast<int8_t> (-128), static_cast<int8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetDomainAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfCapabilities_);
        ITU_T_BIND_NUM_CONSTRS(*state_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*listOfProgramInvocations_);
        ITU_T_BIND_NUM_CONSTRS(*uploadInProgress_, static_cast<int8_t> (-128), static_cast<int8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence CreateProgramInvocation-Request

    template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(reusable_) +
                ITU_T_EXISTS_BMP(monitorType_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_PER(*listOfDomainNames_);
        ITU_T_BIND_PER(reusable_);
        ITU_T_BIND_PER(monitorType_);
    }

    template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_PER(*listOfDomainNames_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(reusable_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(monitorType_);
    }

    // sequence Start-Request

    template<> void Start_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(executionArgument_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_PER(executionArgument_);
    }

    template<> void Start_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(executionArgument_);
    }

    // choice executionArgument

    template<> void Start_Request::ExecutionArgument_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_embeddedString:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<embeded_type > (false, ExecutionArgument_type_embeddedString));
                break;
            }
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<MMSString > (false, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Start_Request::ExecutionArgument_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<external_type > (true, ExecutionArgument_type_encodedString));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<embeded_type > (true, ExecutionArgument_type_embeddedString));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<MMSString > (true, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    // choice CS-Start-Request

    template<> void CS_Start_Request_impl::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CS_Start_Request_impl_normal:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, CS_Start_Request_impl_normal));
                break;
            }
            case CS_Start_Request_impl_controlling:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Controlling_type > (false, CS_Start_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Start_Request_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CS_Start_Request_impl_normal));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Controlling_type > (true, CS_Start_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence controlling

    template<> void CS_Start_Request_impl::Controlling_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(startLocation_) +
                ITU_T_EXISTS_BMP(startCount_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(startLocation_);
        ITU_T_BIND_PER(startCount_);
    }

    template<> void CS_Start_Request_impl::Controlling_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(startLocation_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(startCount_);
    }

    // choice StartCount

    template<> void StartCount::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case StartCount_noLimit:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, StartCount_noLimit));
                break;
            }
            case StartCount_cycleCount:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, StartCount_cycleCount));
                break;
            }
            case StartCount_stepCount:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, StartCount_stepCount));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void StartCount::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, StartCount_noLimit));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, StartCount_cycleCount));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, StartCount_stepCount));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Stop-Request

    template<> void Stop_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
    }

    template<> void Stop_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
    }

    // sequence Resume-Request

    template<> void Resume_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(executionArgument_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_PER(executionArgument_);
    }

    template<> void Resume_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(executionArgument_);
    }

    // choice executionArgument

    template<> void Resume_Request::ExecutionArgument_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_enmbeddedString:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<embeded_type > (false, ExecutionArgument_type_enmbeddedString));
                break;
            }
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<MMSString > (false, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Resume_Request::ExecutionArgument_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<external_type > (true, ExecutionArgument_type_encodedString));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<embeded_type > (true, ExecutionArgument_type_enmbeddedString));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<MMSString > (true, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    // choice CS-Resume-Request

    template<> void CS_Resume_Request_impl::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CS_Resume_Request_impl_normal:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, CS_Resume_Request_impl_normal));
                break;
            }
            case CS_Resume_Request_impl_controlling:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Controlling_type > (false, CS_Resume_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Resume_Request_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CS_Resume_Request_impl_normal));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Controlling_type > (true, CS_Resume_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence controlling

    template<> void CS_Resume_Request_impl::Controlling_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*modeType_);
    }

    template<> void CS_Resume_Request_impl::Controlling_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*modeType_);
    }

    // choice modeType

    template<> void CS_Resume_Request_impl::Controlling_type::ModeType_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ModeType_type_continueMode:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, ModeType_type_continueMode));
                break;
            }
            case ModeType_type_changeMode:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<StartCount > (false, ModeType_type_changeMode));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Resume_Request_impl::Controlling_type::ModeType_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ModeType_type_continueMode));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<StartCount > (true, ModeType_type_changeMode));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Reset-Request

    template<> void Reset_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
    }

    template<> void Reset_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
    }

    // sequence Kill-Request

    template<> void Kill_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
    }

    template<> void Kill_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
    }

    // sequence GetProgramInvocationAttributes-Response

    template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*state_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
        ITU_T_BIND_PER(*listOfDomainNames_);
        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*reusable_);
        ITU_T_BIND_PER(*monitor_);
        ITU_T_BIND_PER(*executionArgument_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_NUM_CONSTRS(*state_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
        ITU_T_BIND_PER(*listOfDomainNames_);
        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*reusable_);
        ITU_T_BIND_PER(*monitor_);
        ITU_T_BIND_PER(*executionArgument_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
    }

    // choice executionArgument

    template<> void GetProgramInvocationAttributes_Response::ExecutionArgument_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_enmbeddedString:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<embeded_type > (false, ExecutionArgument_type_enmbeddedString));
                break;
            }
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<MMSString > (false, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetProgramInvocationAttributes_Response::ExecutionArgument_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<external_type > (true, ExecutionArgument_type_encodedString));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<embeded_type > (true, ExecutionArgument_type_enmbeddedString));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<MMSString > (true, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence CS-GetProgramInvocationAttributes-Response

    template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*errorCode_);
        ITU_T_BIND_PER(*control_);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*errorCode_);
        ITU_T_BIND_PER(*control_);
    }

    // choice control

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Control_type_controlling:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Controlling_type > (false, Control_type_controlling));
                break;
            }
            case Control_type_controlled:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<Controlled_type > (false, Control_type_controlled));
                break;
            }
            case Control_type_normal:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, Control_type_normal));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Controlling_type > (true, Control_type_controlling));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Controlled_type > (true, Control_type_controlled));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Control_type_normal));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence controlling

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(programLocation_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*controlledPI_);
        ITU_T_BIND_PER(programLocation_);
        ITU_T_BIND_PER(*runningMode_);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*controlledPI_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(programLocation_);
        ITU_T_BIND_PER(*runningMode_);
    }

    // choice runningMode

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RunningMode_type_freeRunning:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, RunningMode_type_freeRunning));
                break;
            }
            case RunningMode_type_cycleLimited:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, RunningMode_type_cycleLimited));
                break;
            }
            case RunningMode_type_stepLimited:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, RunningMode_type_stepLimited));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlling_type::RunningMode_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, RunningMode_type_freeRunning));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, RunningMode_type_cycleLimited));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, RunningMode_type_stepLimited));
                break;
            }
            default:
            {
            }
        }
    }

    // choice controlled

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Controlled_type_controllingPI:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, Controlled_type_controllingPI));
                break;
            }
            case Controlled_type_none:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, Controlled_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::Control_type::Controlled_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, Controlled_type_controllingPI));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Controlled_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Select-Request

    template<> void Select_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(controlling_) +
                ITU_T_EXISTS_BMP(controlled_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(controlling_);
        ITU_T_BIND_PER(controlled_);
    }

    template<> void Select_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(controlling_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(controlled_);
    }

    // sequence AlterProgramInvocationAttributes-Request

    template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(startCount_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*programInvocation_);
        ITU_T_BIND_PER(startCount_);
    }

    template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*programInvocation_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(startCount_);
    }

    // sequence ReconfigureProgramInvocation-Request

    template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(newProgramInvocationName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*oldProgramInvocationName_);
        ITU_T_BIND_PER(newProgramInvocationName_);
        ITU_T_BIND_PER(*domainsToAdd_);
        ITU_T_BIND_PER(*domainsToRemove_);
    }

    template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*oldProgramInvocationName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(newProgramInvocationName_);
        ITU_T_BIND_PER(*domainsToAdd_);
        ITU_T_BIND_PER(*domainsToRemove_);
    }

    // choice ControlElement

    template<> void ControlElement::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ControlElement_beginDomainDef:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<BeginDomainDef_type > (false, ControlElement_beginDomainDef));
                break;
            }
            case ControlElement_continueDomainDef:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(*value<ContinueDomainDef_type > (false, ControlElement_continueDomainDef));
                break;
            }
            case ControlElement_endDomainDef:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<Identifier > (false, ControlElement_endDomainDef));
                break;
            }
            case ControlElement_piDefinition:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<PiDefinition_type > (false, ControlElement_piDefinition));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ControlElement::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<BeginDomainDef_type > (true, ControlElement_beginDomainDef));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ContinueDomainDef_type > (true, ControlElement_continueDomainDef));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ControlElement_endDomainDef));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<PiDefinition_type > (true, ControlElement_piDefinition));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence beginDomainDef

    template<> void ControlElement::BeginDomainDef_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(loadData_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*capabilities_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(loadData_);
    }

    template<> void ControlElement::BeginDomainDef_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*capabilities_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(loadData_);
    }

    // sequence continueDomainDef

    template<> void ControlElement::ContinueDomainDef_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*loadData_);
    }

    template<> void ControlElement::ContinueDomainDef_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*domainName_);
        ITU_T_BIND_PER(*loadData_);
    }

    // sequence piDefinition

    template<> void ControlElement::PiDefinition_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(reusable_) +
                ITU_T_EXISTS_BMP(monitorType_) +
                ITU_T_EXISTS_BMP(pIState_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*piName_);
        ITU_T_BIND_PER(*listOfDomains_);
        ITU_T_BIND_PER(reusable_);
        ITU_T_BIND_PER(monitorType_);
        ITU_T_BIND_NUM_CONSTRS(pIState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
    }

    template<> void ControlElement::PiDefinition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(*piName_);
        ITU_T_BIND_PER(*listOfDomains_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(reusable_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(monitorType_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(pIState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
    }

    // choice InitiateUnitControl-Error

    template<> void InitiateUnitControl_Error::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case InitiateUnitControl_Error_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, InitiateUnitControl_Error_domain));
                break;
            }
            case InitiateUnitControl_Error_programInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, InitiateUnitControl_Error_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void InitiateUnitControl_Error::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, InitiateUnitControl_Error_domain));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, InitiateUnitControl_Error_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence UnitControlLoadSegment-Response

    template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*controlElements_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*controlElements_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence UnitControlUpload-Request

    template<> void UnitControlUpload_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void UnitControlUpload_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(continueAfter_);
    }

    // choice continueAfter

    template<> void UnitControlUpload_Request::ContinueAfter_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ContinueAfter_type_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ContinueAfter_type_domain));
                break;
            }
            case ContinueAfter_type_ulsmID:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, ContinueAfter_type_ulsmID));
                break;
            }
            case ContinueAfter_type_programInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ContinueAfter_type_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnitControlUpload_Request::ContinueAfter_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ContinueAfter_type_domain));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, ContinueAfter_type_ulsmID));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ContinueAfter_type_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence UnitControlUpload-Response

    template<> void UnitControlUpload_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(nextElement_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*controlElements_);
        ITU_T_BIND_PER(nextElement_);
    }

    template<> void UnitControlUpload_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*controlElements_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(nextElement_);
    }

    // choice nextElement

    template<> void UnitControlUpload_Response::NextElement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case NextElement_type_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, NextElement_type_domain));
                break;
            }
            case NextElement_type_ulsmID:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, NextElement_type_ulsmID));
                break;
            }
            case NextElement_type_programInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, NextElement_type_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnitControlUpload_Response::NextElement_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, NextElement_type_domain));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, NextElement_type_ulsmID));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, NextElement_type_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence StartUnitControl-Request

    template<> void StartUnitControl_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(executionArgument_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_BIND_PER(executionArgument_);
    }

    template<> void StartUnitControl_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(executionArgument_);
    }

    // choice executionArgument

    template<> void StartUnitControl_Request::ExecutionArgument_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ExecutionArgument_type_encodedString:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<external_type > (false, ExecutionArgument_type_encodedString));
                break;
            }
            case ExecutionArgument_type_enmbeddedString:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<embeded_type > (false, ExecutionArgument_type_enmbeddedString));
                break;
            }
            case ExecutionArgument_type_simpleString:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<MMSString > (false, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void StartUnitControl_Request::ExecutionArgument_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<external_type > (true, ExecutionArgument_type_encodedString));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<embeded_type > (true, ExecutionArgument_type_enmbeddedString));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<MMSString > (true, ExecutionArgument_type_simpleString));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence StartUnitControl-Error

    template<> void StartUnitControl_Error::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_NUM_CONSTRS(*programInvocationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
    }

    template<> void StartUnitControl_Error::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_NUM_CONSTRS(*programInvocationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
    }

    // sequence StopUnitControl-Error

    template<> void StopUnitControl_Error::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_NUM_CONSTRS(*programInvocationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
    }

    template<> void StopUnitControl_Error::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*programInvocationName_);
        ITU_T_BIND_NUM_CONSTRS(*programInvocationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
    }

    // sequence CreateUnitControl-Request

    template<> void CreateUnitControl_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*unitControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    template<> void CreateUnitControl_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*unitControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    // sequence AddToUnitControl-Request

    template<> void AddToUnitControl_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*unitControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    template<> void AddToUnitControl_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*unitControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    // sequence RemoveFromUnitControl-Request

    template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*unitControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*unitControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    // sequence GetUnitControlAttributes-Response

    template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    // sequence LoadUnitControlFromFile-Request

    template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(thirdParty_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(thirdParty_);
    }

    template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(thirdParty_);
    }

    // choice LoadUnitControlFromFile-Error

    template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case LoadUnitControlFromFile_Error_none:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, LoadUnitControlFromFile_Error_none));
                break;
            }
            case LoadUnitControlFromFile_Error_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, LoadUnitControlFromFile_Error_domain));
                break;
            }
            case LoadUnitControlFromFile_Error_programInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, LoadUnitControlFromFile_Error_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, LoadUnitControlFromFile_Error_none));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, LoadUnitControlFromFile_Error_domain));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, LoadUnitControlFromFile_Error_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence StoreUnitControlToFile-Request

    template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(thirdParty_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(thirdParty_);
    }

    template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*unitControlName_);
        ITU_T_BIND_PER(*fileName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(thirdParty_);
    }

    // choice DeleteUnitControl-Error

    template<> void DeleteUnitControl_Error::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DeleteUnitControl_Error_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, DeleteUnitControl_Error_domain));
                break;
            }
            case DeleteUnitControl_Error_programInvocation:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, DeleteUnitControl_Error_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteUnitControl_Error::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, DeleteUnitControl_Error_domain));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, DeleteUnitControl_Error_programInvocation));
                break;
            }
            default:
            {
            }
        }
    }

    // choice TypeSpecification

    template<> void TypeSpecification::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case TypeSpecification_typeDescription:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<MMS_Object_Module_1::TypeDescription > (false, TypeSpecification_typeDescription));
                break;
            }
            case TypeSpecification_typeName:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, TypeSpecification_typeName));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void TypeSpecification::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<MMS_Object_Module_1::TypeDescription > (true, TypeSpecification_typeDescription));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, TypeSpecification_typeName));
                break;
            }
            default:
            {
            }
        }
    }

    // choice 

    template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AlternateAccess_sequence_of_unnamed:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<AlternateAccessSelection > (false, AlternateAccess_sequence_of_unnamed));
                break;
            }
            case AlternateAccess_sequence_of_named:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Named_type > (false, AlternateAccess_sequence_of_named));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<AlternateAccessSelection > (true, AlternateAccess_sequence_of_unnamed));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Named_type > (true, AlternateAccess_sequence_of_named));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence named

    template<> void AlternateAccess_sequence_of::Named_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*componentName_);
        ITU_T_BIND_PER(*access_);
    }

    template<> void AlternateAccess_sequence_of::Named_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*componentName_);
        ITU_T_BIND_PER(*access_);
    }

    // choice AlternateAccessSelection

    template<> void AlternateAccessSelection::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AlternateAccessSelection_selectAccess:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<SelectAccess_type > (false, AlternateAccessSelection_selectAccess));
                break;
            }
            case AlternateAccessSelection_selectAlternateAccess:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<SelectAlternateAccess_type > (false, AlternateAccessSelection_selectAlternateAccess));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<SelectAccess_type > (true, AlternateAccessSelection_selectAccess));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<SelectAlternateAccess_type > (true, AlternateAccessSelection_selectAlternateAccess));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence selectAlternateAccess

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessSelection_);
        ITU_T_BIND_PER(*alternateAccess_);
    }

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessSelection_);
        ITU_T_BIND_PER(*alternateAccess_);
    }

    // choice accessSelection

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AccessSelection_type_component:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<Identifier > (false, AccessSelection_type_component));
                break;
            }
            case AccessSelection_type_index:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_NUM_CONSTRS(*value<Unsigned32 > (false, AccessSelection_type_index), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case AccessSelection_type_indexRange:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<IndexRange_type > (false, AccessSelection_type_indexRange));
                break;
            }
            case AccessSelection_type_allElements:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<null_type > (false, AccessSelection_type_allElements));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, AccessSelection_type_component));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Unsigned32 > (true, AccessSelection_type_index), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<IndexRange_type > (true, AccessSelection_type_indexRange));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<null_type > (true, AccessSelection_type_allElements));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence indexRange

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*lowIndex_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfElements_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void AlternateAccessSelection::SelectAlternateAccess_type::AccessSelection_type::IndexRange_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*lowIndex_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfElements_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // choice selectAccess

    template<> void AlternateAccessSelection::SelectAccess_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case SelectAccess_type_component:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<Identifier > (false, SelectAccess_type_component));
                break;
            }
            case SelectAccess_type_index:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_NUM_CONSTRS(*value<Unsigned32 > (false, SelectAccess_type_index), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case SelectAccess_type_indexRange:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<IndexRange_type > (false, SelectAccess_type_indexRange));
                break;
            }
            case SelectAccess_type_allElements:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<null_type > (false, SelectAccess_type_allElements));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::SelectAccess_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, SelectAccess_type_component));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Unsigned32 > (true, SelectAccess_type_index), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<IndexRange_type > (true, SelectAccess_type_indexRange));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<null_type > (true, SelectAccess_type_allElements));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence indexRange

    template<> void AlternateAccessSelection::SelectAccess_type::IndexRange_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*lowIndex_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfElements_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void AlternateAccessSelection::SelectAccess_type::IndexRange_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*lowIndex_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfElements_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // choice AccessResult

    template<> void AccessResult::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AccessResult_success:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Data > (false, AccessResult_success));
                break;
            }
            case AccessResult_failure:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_NUM_CONSTRS(*value<DataAccessError > (false, AccessResult_failure), static_cast<uint8_t> (0), static_cast<uint8_t> (11));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessResult::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Data > (true, AccessResult_success));
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<DataAccessError > (true, AccessResult_failure), static_cast<uint8_t> (0), static_cast<uint8_t> (11));
                break;
            }
            default:
            {
            }
        }
    }

    // choice Data

    template<> void Data::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_CHOICE(Data_mMSString, Data_mMSString);

        if (ITU_T_EXTENTION) {
            switch (type()) {
                case Data_array:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 13);
                    ITU_T_BIND_PER(*value<Array_type > (false, Data_array));
                    break;
                }
                case Data_structure:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 13);
                    ITU_T_BIND_PER(*value<Structure_type > (false, Data_structure));
                    break;
                }
                case Data_boolean:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 13);
                    ITU_T_BIND_PER(*value<bool > (false, Data_boolean));
                    break;
                }
                case Data_bit_string:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 13);
                    ITU_T_BIND_PER(*value<bitstring_type > (false, Data_bit_string));
                    break;
                }
                case Data_integer:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 13);
                    ITU_T_BIND_PER(*value<integer_type > (false, Data_integer));
                    break;
                }
                case Data_unsignedV:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 13);
                    ITU_T_BIND_PER(*value<integer_type > (false, Data_unsignedV));
                    break;
                }
                case Data_floating_point:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 13);
                    ITU_T_BIND_PER(*value<FloatingPoint > (false, Data_floating_point));
                    break;
                }
                case Data_octet_string:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 13);
                    ITU_T_BIND_PER(*value<octetstring_type > (false, Data_octet_string));
                    break;
                }
                case Data_visible_string:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 13);
                    ITU_T_BIND_PER(*value<visiblestring_type > (false, Data_visible_string));
                    break;
                }
                case Data_generalized_time:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 13);
                    ITU_T_BIND_PER(*value<gentime_type > (false, Data_generalized_time));
                    break;
                }
                case Data_binary_time:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 13);
                    ITU_T_BIND_SIZE_CONSTRS(*value<TimeOfDay > (false, Data_binary_time), 4, 6);
                    break;
                }
                case Data_bcd:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 13);
                    ITU_T_BIND_PER(*value<integer_type > (false, Data_bcd));
                    break;
                }
                case Data_booleanArray:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 13);
                    ITU_T_BIND_PER(*value<bitstring_type > (false, Data_booleanArray));
                    break;
                }
                case Data_objId:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 13);
                    ITU_T_BIND_PER(*value<oid_type > (false, Data_objId));
                    break;
                }
                default:
                {
                }
            }
        }
        else {
            switch (type()) {
                case Data_mMSString:
                {
                    ITU_T_SET_NSN_SMALL_INDX(0);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<MMSString > (false, Data_mMSString));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                default:
                {
                }
            }
        }
    }

    template<> void Data::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        if (ITU_T_EXTENTION) {

            ITU_T_GET_CONSTAINED_INDX(13);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(*value<Array_type > (true, Data_array));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(*value<Structure_type > (true, Data_structure));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(*value<bool > (true, Data_boolean));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(*value<bitstring_type > (true, Data_bit_string));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(*value<integer_type > (true, Data_integer));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(*value<integer_type > (true, Data_unsignedV));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(*value<FloatingPoint > (true, Data_floating_point));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(*value<octetstring_type > (true, Data_octet_string));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(*value<visiblestring_type > (true, Data_visible_string));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(*value<gentime_type > (true, Data_generalized_time));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_SIZE_CONSTRS(*value<TimeOfDay > (true, Data_binary_time), 4, 6);
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(*value<integer_type > (true, Data_bcd));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(*value<bitstring_type > (true, Data_booleanArray));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(*value<oid_type > (true, Data_objId));
                    break;
                }
                default:
                {
                }
            }
        }
        else {

            ITU_T_GET_NSN_SMALL_INDX;

            switch (__indx__) {
                case 0:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<MMSString > (false, Data_mMSString));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                default:
                {
                    ITU_T_PER_CLEAR_EXTENTION;
                }
            }
        }
    }

    // choice VariableAccessSpecification

    template<> void VariableAccessSpecification::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case VariableAccessSpecification_listOfVariable:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ListOfVariable_type > (false, VariableAccessSpecification_listOfVariable));
                break;
            }
            case VariableAccessSpecification_variableListName:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, VariableAccessSpecification_variableListName));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void VariableAccessSpecification::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ListOfVariable_type > (true, VariableAccessSpecification_listOfVariable));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, VariableAccessSpecification_variableListName));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence 

    template<> void VariableAccessSpecification::ListOfVariable_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(alternateAccess_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void VariableAccessSpecification::ListOfVariable_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(alternateAccess_);
    }

    // choice VariableSpecification

    template<> void VariableSpecification::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case VariableSpecification_name:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 4);
                ITU_T_BIND_PER(*value<ObjectName > (false, VariableSpecification_name));
                break;
            }
            case VariableSpecification_address:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 4);
                ITU_T_BIND_PER(*value<MMS_Object_Module_1::Address > (false, VariableSpecification_address));
                break;
            }
            case VariableSpecification_variableDescription:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 4);
                ITU_T_BIND_PER(*value<VariableDescription_type > (false, VariableSpecification_variableDescription));
                break;
            }
            case VariableSpecification_scatteredAccessDescription:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 4);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::ScatteredAccessDescription > (false, VariableSpecification_scatteredAccessDescription));
                break;
            }
            case VariableSpecification_invalidated:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 4);
                ITU_T_BIND_PER(*value<null_type > (false, VariableSpecification_invalidated));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void VariableSpecification::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(4);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, VariableSpecification_name));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<MMS_Object_Module_1::Address > (true, VariableSpecification_address));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<VariableDescription_type > (true, VariableSpecification_variableDescription));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1A::ScatteredAccessDescription > (true, VariableSpecification_scatteredAccessDescription));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<null_type > (true, VariableSpecification_invalidated));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence variableDescription

    template<> void VariableSpecification::VariableDescription_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*address_);
        ITU_T_BIND_PER(*typeSpecification_);
    }

    template<> void VariableSpecification::VariableDescription_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*address_);
        ITU_T_BIND_PER(*typeSpecification_);
    }

    // sequence Read-Request

    template<> void Read_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(specificationWithResult_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(specificationWithResult_);
        ITU_T_BIND_PER(*variableAccessSpecification_);
    }

    template<> void Read_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(specificationWithResult_);
        ITU_T_BIND_PER(*variableAccessSpecification_);
    }

    // sequence Read-Response

    template<> void Read_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(variableAccessSpecification_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(variableAccessSpecification_);
        ITU_T_BIND_PER(*listOfAccessResult_);
    }

    template<> void Read_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(variableAccessSpecification_);
        ITU_T_BIND_PER(*listOfAccessResult_);
    }

    // sequence Write-Request

    template<> void Write_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*variableAccessSpecification_);
        ITU_T_BIND_PER(*listOfData_);
    }

    template<> void Write_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*variableAccessSpecification_);
        ITU_T_BIND_PER(*listOfData_);
    }

    // choice 

    template<> void Write_Response_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Write_Response_sequence_of_failure:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_NUM_CONSTRS(*value<DataAccessError > (false, Write_Response_sequence_of_failure), static_cast<uint8_t> (0), static_cast<uint8_t> (11));
                break;
            }
            case Write_Response_sequence_of_success:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, Write_Response_sequence_of_success));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Write_Response_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<DataAccessError > (true, Write_Response_sequence_of_failure), static_cast<uint8_t> (0), static_cast<uint8_t> (11));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Write_Response_sequence_of_success));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence InformationReport

    template<> void InformationReport::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*variableAccessSpecification_);
        ITU_T_BIND_PER(*listOfAccessResult_);
    }

    template<> void InformationReport::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*variableAccessSpecification_);
        ITU_T_BIND_PER(*listOfAccessResult_);
    }

    // choice GetVariableAccessAttributes-Request

    template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case GetVariableAccessAttributes_Request_name:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, GetVariableAccessAttributes_Request_name));
                break;
            }
            case GetVariableAccessAttributes_Request_address:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<MMS_Object_Module_1::Address > (false, GetVariableAccessAttributes_Request_address));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, GetVariableAccessAttributes_Request_name));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<MMS_Object_Module_1::Address > (true, GetVariableAccessAttributes_Request_address));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetVariableAccessAttributes-Response

    template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(address_) +
                ITU_T_EXISTS_BMP(accessControlList_) +
                ITU_T_EXISTS_BMP(meaning_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(address_);
        ITU_T_BIND_PER(*typeDescription_);
        ITU_T_BIND_PER(accessControlList_);
        ITU_T_BIND_PER(meaning_);
    }

    template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(address_);
        ITU_T_BIND_PER(*typeDescription_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(accessControlList_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(meaning_);
    }

    // sequence DefineNamedVariable-Request

    template<> void DefineNamedVariable_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(typeSpecification_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*variableName_);
        ITU_T_BIND_PER(*address_);
        ITU_T_BIND_PER(typeSpecification_);
    }

    template<> void DefineNamedVariable_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*variableName_);
        ITU_T_BIND_PER(*address_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(typeSpecification_);
    }

    // sequence DeleteVariableAccess-Request

    template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(scopeOfDelete_) +
                ITU_T_EXISTS_BMP(listOfName_) +
                ITU_T_EXISTS_BMP(domainName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(scopeOfDelete_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(listOfName_);
        ITU_T_BIND_PER(domainName_);
    }

    template<> void DeleteVariableAccess_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(scopeOfDelete_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(listOfName_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(domainName_);
    }

    // sequence DeleteVariableAccess-Response

    template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberDeleted_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberDeleted_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence DefineNamedVariableList-Request

    template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*variableListName_);
        ITU_T_BIND_PER(*listOfVariable_);
    }

    template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*variableListName_);
        ITU_T_BIND_PER(*listOfVariable_);
    }

    // sequence 

    template<> void DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(alternateAccess_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void DefineNamedVariableList_Request::ListOfVariable_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(alternateAccess_);
    }

    // sequence GetNamedVariableListAttributes-Response

    template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*listOfVariable_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*listOfVariable_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence 

    template<> void GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(alternateAccess_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void GetNamedVariableListAttributes_Response::ListOfVariable_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(alternateAccess_);
    }

    // sequence DeleteNamedVariableList-Request

    template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(scopeOfDelete_) +
                ITU_T_EXISTS_BMP(listOfVariableListName_) +
                ITU_T_EXISTS_BMP(domainName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(scopeOfDelete_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(listOfVariableListName_);
        ITU_T_BIND_PER(domainName_);
    }

    template<> void DeleteNamedVariableList_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(scopeOfDelete_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(listOfVariableListName_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(domainName_);
    }

    // sequence DeleteNamedVariableList-Response

    template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberDeleted_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberDeleted_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence DefineNamedType-Request

    template<> void DefineNamedType_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*typeName_);
        ITU_T_BIND_PER(*typeSpecification_);
    }

    template<> void DefineNamedType_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*typeName_);
        ITU_T_BIND_PER(*typeSpecification_);
    }

    // sequence GetNamedTypeAttributes-Response

    template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_) +
                ITU_T_EXISTS_BMP(meaning_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*typeSpecification_);
        ITU_T_BIND_PER(accessControlList_);
        ITU_T_BIND_PER(meaning_);
    }

    template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*typeSpecification_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(meaning_);
    }

    // sequence DeleteNamedType-Request

    template<> void DeleteNamedType_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(scopeOfDelete_) +
                ITU_T_EXISTS_BMP(listOfTypeName_) +
                ITU_T_EXISTS_BMP(domainName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(scopeOfDelete_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(listOfTypeName_);
        ITU_T_BIND_PER(domainName_);
    }

    template<> void DeleteNamedType_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(scopeOfDelete_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(listOfTypeName_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(domainName_);
    }

    // sequence DeleteNamedType-Response

    template<> void DeleteNamedType_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberDeleted_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void DeleteNamedType_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*numberMatched_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberDeleted_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence ExchangeData-Request

    template<> void ExchangeData_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*dataExchangeName_);
        ITU_T_BIND_PER(*listOfRequestData_);
    }

    template<> void ExchangeData_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*dataExchangeName_);
        ITU_T_BIND_PER(*listOfRequestData_);
    }

    // sequence ExchangeData-Response

    template<> void ExchangeData_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*listOfResponseData_);
    }

    template<> void ExchangeData_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*listOfResponseData_);
    }

    // sequence GetDataExchangeAttributes-Response

    template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(programInvocation_) +
                ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*inUse_);
        ITU_T_BIND_PER(*listOfRequestTypeDescriptions_);
        ITU_T_BIND_PER(*listOfResponseTypeDescriptions_);
        ITU_T_BIND_PER(programInvocation_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*inUse_);
        ITU_T_BIND_PER(*listOfRequestTypeDescriptions_);
        ITU_T_BIND_PER(*listOfResponseTypeDescriptions_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(programInvocation_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence TakeControl-Request

    template<> void TakeControl_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(namedToken_) +
                ITU_T_EXISTS_BMP(priority_) +
                ITU_T_EXISTS_BMP(acceptableDelay_) +
                ITU_T_EXISTS_BMP(controlTimeOut_) +
                ITU_T_EXISTS_BMP(abortOnTimeOut_) +
                ITU_T_EXISTS_BMP(relinquishIfConnectionLost_) +
                ITU_T_EXISTS_BMP(applicationToPreempt_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_PER(namedToken_);
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(acceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(controlTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(abortOnTimeOut_);
        ITU_T_BIND_PER(relinquishIfConnectionLost_);
        ITU_T_BIND_PER(applicationToPreempt_);
    }

    template<> void TakeControl_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(7);

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(namedToken_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(acceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_NUM_CONSTRS(controlTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(abortOnTimeOut_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(relinquishIfConnectionLost_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(applicationToPreempt_);
    }

    // choice TakeControl-Response

    template<> void TakeControl_Response::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case TakeControl_Response_noResult:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, TakeControl_Response_noResult));
                break;
            }
            case TakeControl_Response_namedToken:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Identifier > (false, TakeControl_Response_namedToken));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void TakeControl_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, TakeControl_Response_noResult));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, TakeControl_Response_namedToken));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence RelinquishControl-Request

    template<> void RelinquishControl_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(namedToken_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_PER(namedToken_);
    }

    template<> void RelinquishControl_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(namedToken_);
    }

    // sequence DefineSemaphore-Request

    template<> void DefineSemaphore_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_NUM_CONSTRS(*numberOfTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
    }

    template<> void DefineSemaphore_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_NUM_CONSTRS(*numberOfTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
    }

    // sequence ReportSemaphoreStatus-Response

    template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_NUM_CONSTRS(*classV_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(*numberOfTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfOwnedTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfHungTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_NUM_CONSTRS(*classV_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(*numberOfTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfOwnedTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*numberOfHungTokens_, static_cast<uint16_t> (0), static_cast<uint16_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence ReportPoolSemaphoreStatus-Request

    template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(nameToStartAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_PER(nameToStartAfter_);
    }

    template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(nameToStartAfter_);
    }

    // sequence ReportPoolSemaphoreStatus-Response

    template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfNamedTokens_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfNamedTokens_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // choice 

    template<> void ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ListOfNamedTokens_type_sequence_of_freeNamedToken:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ListOfNamedTokens_type_sequence_of_freeNamedToken));
                break;
            }
            case ListOfNamedTokens_type_sequence_of_ownedNamedToken:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ListOfNamedTokens_type_sequence_of_ownedNamedToken));
                break;
            }
            case ListOfNamedTokens_type_sequence_of_hungNamedToken:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<Identifier > (false, ListOfNamedTokens_type_sequence_of_hungNamedToken));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReportPoolSemaphoreStatus_Response::ListOfNamedTokens_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ListOfNamedTokens_type_sequence_of_freeNamedToken));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ListOfNamedTokens_type_sequence_of_ownedNamedToken));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, ListOfNamedTokens_type_sequence_of_hungNamedToken));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence ReportSemaphoreEntryStatus-Request

    template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(entryIDToStartAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_NUM_CONSTRS(*state_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(entryIDToStartAfter_);
    }

    template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_NUM_CONSTRS(*state_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(entryIDToStartAfter_);
    }

    // sequence ReportSemaphoreEntryStatus-Response

    template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfSemaphoreEntry_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfSemaphoreEntry_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence SemaphoreEntry

    template<> void SemaphoreEntry::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(namedToken_) +
                ITU_T_EXISTS_BMP(priority_) +
                ITU_T_EXISTS_BMP(remainingTimeOut_) +
                ITU_T_EXISTS_BMP(abortOnTimeOut_) +
                ITU_T_EXISTS_BMP(relinquishIfConnectionLost_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*entryID_);
        ITU_T_BIND_NUM_CONSTRS(*entryClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_PER(*applicationReference_);
        ITU_T_BIND_PER(namedToken_);
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(remainingTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(abortOnTimeOut_);
        ITU_T_BIND_PER(relinquishIfConnectionLost_);
    }

    template<> void SemaphoreEntry::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(5);

        ITU_T_BIND_PER(*entryID_);
        ITU_T_BIND_NUM_CONSTRS(*entryClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_PER(*applicationReference_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(namedToken_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(remainingTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(abortOnTimeOut_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(relinquishIfConnectionLost_);
    }

    // sequence AttachToSemaphore

    template<> void AttachToSemaphore::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(namedToken_) +
                ITU_T_EXISTS_BMP(priority_) +
                ITU_T_EXISTS_BMP(acceptableDelay_) +
                ITU_T_EXISTS_BMP(controlTimeOut_) +
                ITU_T_EXISTS_BMP(abortOnTimeOut_) +
                ITU_T_EXISTS_BMP(relinquishIfConnectionLost_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_BIND_PER(namedToken_);
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(acceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(controlTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(abortOnTimeOut_);
        ITU_T_BIND_PER(relinquishIfConnectionLost_);
    }

    template<> void AttachToSemaphore::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(6);

        ITU_T_BIND_PER(*semaphoreName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(namedToken_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(acceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_NUM_CONSTRS(controlTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(abortOnTimeOut_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(relinquishIfConnectionLost_);
    }

    // sequence Input-Request

    template<> void Input_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(echo_) +
                ITU_T_EXISTS_BMP(listOfPromptData_) +
                ITU_T_EXISTS_BMP(inputTimeOut_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*operatorStationName_);
        ITU_T_BIND_PER(echo_);
        ITU_T_BIND_PER(listOfPromptData_);
        ITU_T_BIND_NUM_CONSTRS(inputTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void Input_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(*operatorStationName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(echo_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(listOfPromptData_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(inputTimeOut_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence Output-Request

    template<> void Output_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*operatorStationName_);
        ITU_T_BIND_PER(*listOfOutputData_);
    }

    template<> void Output_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*operatorStationName_);
        ITU_T_BIND_PER(*listOfOutputData_);
    }

    // sequence TriggerEvent-Request

    template<> void TriggerEvent_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(priority_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    template<> void TriggerEvent_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    // sequence EventNotification

    template<> void EventNotification::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(currentState_) +
                ITU_T_EXISTS_BMP(notificationLost_) +
                ITU_T_EXISTS_BMP(alarmAcknowledgmentRule_) +
                ITU_T_EXISTS_BMP(actionResult_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(*transitionTime_);
        ITU_T_BIND_PER(notificationLost_);
        ITU_T_BIND_NUM_CONSTRS(alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(actionResult_);
    }

    template<> void EventNotification::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(*transitionTime_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(notificationLost_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(actionResult_);
    }

    // sequence actionResult

    template<> void EventNotification::ActionResult_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*eventActionName_);
        ITU_T_BIND_PER(*successOrFailure_);
    }

    template<> void EventNotification::ActionResult_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*eventActionName_);
        ITU_T_BIND_PER(*successOrFailure_);
    }

    // choice successOrFailure

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case SuccessOrFailure_type_success:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Success_type > (false, SuccessOrFailure_type_success));
                break;
            }
            case SuccessOrFailure_type_failure:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Failure_type > (false, SuccessOrFailure_type_failure));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Success_type > (true, SuccessOrFailure_type_success));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Failure_type > (true, SuccessOrFailure_type_failure));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence success

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(cs_Response_Detail_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*confirmedServiceResponse_);
        ITU_T_BIND_PER(cs_Response_Detail_);
    }

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Success_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*confirmedServiceResponse_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(cs_Response_Detail_);
    }

    // sequence failure

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(modifierPosition_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(modifierPosition_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*serviceError_);
    }

    template<> void EventNotification::ActionResult_type::SuccessOrFailure_type::Failure_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(modifierPosition_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*serviceError_);
    }

    // choice CS-EventNotification

    template<> void CS_EventNotification_impl::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CS_EventNotification_impl_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, CS_EventNotification_impl_noEnhancement));
                break;
            }
            case CS_EventNotification_impl_string:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, CS_EventNotification_impl_string));
                break;
            }
            case CS_EventNotification_impl_index:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, CS_EventNotification_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_EventNotification_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CS_EventNotification_impl_noEnhancement));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, CS_EventNotification_impl_string));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, CS_EventNotification_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence AcknowledgeEventNotification-Request

    template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_NUM_CONSTRS(*acknowledgedState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(*timeOfAcknowledgedTransition_);
    }

    template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_NUM_CONSTRS(*acknowledgedState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(*timeOfAcknowledgedTransition_);
    }

    // sequence GetAlarmSummary-Request

    template<> void GetAlarmSummary_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(enrollmentsOnly_) +
                ITU_T_EXISTS_BMP(activeAlarmsOnly_) +
                ITU_T_EXISTS_BMP(acknowledgementFilter_) +
                ITU_T_EXISTS_BMP(severityFilter_) +
                ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(enrollmentsOnly_);
        ITU_T_BIND_PER(activeAlarmsOnly_);
        ITU_T_BIND_NUM_CONSTRS(acknowledgementFilter_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(severityFilter_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void GetAlarmSummary_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(5);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(enrollmentsOnly_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(activeAlarmsOnly_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(acknowledgementFilter_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(severityFilter_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence severityFilter

    template<> void GetAlarmSummary_Request::SeverityFilter_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*mostSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*leastSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    template<> void GetAlarmSummary_Request::SeverityFilter_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*mostSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*leastSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    // sequence GetAlarmSummary-Response

    template<> void GetAlarmSummary_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfAlarmSummary_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void GetAlarmSummary_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfAlarmSummary_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence AlarmSummary

    template<> void AlarmSummary::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(displayEnhancement_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToActive_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToIdle_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRS(*unacknowledgedState_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(*(*displayEnhancement_));
        ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
    }

    template<> void AlarmSummary::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRS(*unacknowledgedState_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(*(*displayEnhancement_));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
    }

    // choice EN-Additional-Detail

    template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case EN_Additional_Detail_impl_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, EN_Additional_Detail_impl_noEnhancement));
                break;
            }
            case EN_Additional_Detail_impl_string:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, EN_Additional_Detail_impl_string));
                break;
            }
            case EN_Additional_Detail_impl_index:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, EN_Additional_Detail_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, EN_Additional_Detail_impl_noEnhancement));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, EN_Additional_Detail_impl_string));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, EN_Additional_Detail_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetAlarmEnrollmentSummary-Request

    template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(enrollmentsOnly_) +
                ITU_T_EXISTS_BMP(activeAlarmsOnly_) +
                ITU_T_EXISTS_BMP(acknowledgementFilter_) +
                ITU_T_EXISTS_BMP(severityFilter_) +
                ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(enrollmentsOnly_);
        ITU_T_BIND_PER(activeAlarmsOnly_);
        ITU_T_BIND_NUM_CONSTRS(acknowledgementFilter_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(severityFilter_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void GetAlarmEnrollmentSummary_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(5);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(enrollmentsOnly_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(activeAlarmsOnly_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(acknowledgementFilter_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(severityFilter_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence severityFilter

    template<> void GetAlarmEnrollmentSummary_Request::SeverityFilter_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*mostSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*leastSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    template<> void GetAlarmEnrollmentSummary_Request::SeverityFilter_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*mostSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*leastSevere_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    // sequence GetAlarmEnrollmentSummary-Response

    template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfAlarmEnrollmentSummary_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfAlarmEnrollmentSummary_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence AlarmEnrollmentSummary

    template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(clientApplication_) +
                ITU_T_EXISTS_BMP(displayEnhancement_) +
                ITU_T_EXISTS_BMP(notificationLost_) +
                ITU_T_EXISTS_BMP(enrollmentState_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToActive_) +
                ITU_T_EXISTS_BMP(timeActiveAcknowledged_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToIdle_) +
                ITU_T_EXISTS_BMP(timeIdleAcknowledged_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_NUM_CONSTRS(*severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_PER(*(*displayEnhancement_));
        ITU_T_BIND_PER(notificationLost_);
        ITU_T_BIND_NUM_CONSTRS(*alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(enrollmentState_);
        ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_BIND_PER(timeActiveAcknowledged_);
        ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
        ITU_T_BIND_PER(timeIdleAcknowledged_);
    }

    template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(8);

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_NUM_CONSTRS(*severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(*(*displayEnhancement_));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(notificationLost_);
        ITU_T_BIND_NUM_CONSTRS(*alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(enrollmentState_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(timeActiveAcknowledged_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
        ITU_T_OPTIONAL_CHECK(7) ITU_T_BIND_PER(timeIdleAcknowledged_);
    }

    // sequence AttachToEventCondition

    template<> void AttachToEventCondition::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(acceptableDelay_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*causingTransitions_, 7);
        ITU_T_BIND_NUM_CONSTRS(acceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void AttachToEventCondition::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*causingTransitions_, 7);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(acceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence DefineEventCondition-Request

    template<> void DefineEventCondition_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(priority_) +
                ITU_T_EXISTS_BMP(severity_) +
                ITU_T_EXISTS_BMP(alarmSummaryReports_) +
                ITU_T_EXISTS_BMP(monitoredVariable_) +
                ITU_T_EXISTS_BMP(evaluationInterval_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*classV_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_BIND_NUM_CONSTRS(evaluationInterval_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void DefineEventCondition_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(5);

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*classV_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_NUM_CONSTRS(evaluationInterval_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // choice CS-DefineEventCondition-Request

    template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CS_DefineEventCondition_Request_impl_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, CS_DefineEventCondition_Request_impl_noEnhancement));
                break;
            }
            case CS_DefineEventCondition_Request_impl_string:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, CS_DefineEventCondition_Request_impl_string));
                break;
            }
            case CS_DefineEventCondition_Request_impl_index:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, CS_DefineEventCondition_Request_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CS_DefineEventCondition_Request_impl_noEnhancement));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, CS_DefineEventCondition_Request_impl_string));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, CS_DefineEventCondition_Request_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    // choice DeleteEventCondition-Request

    template<> void DeleteEventCondition_Request::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DeleteEventCondition_Request_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<Specific_type > (false, DeleteEventCondition_Request_specific));
                break;
            }
            case DeleteEventCondition_Request_aa_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(*value<null_type > (false, DeleteEventCondition_Request_aa_specific));
                break;
            }
            case DeleteEventCondition_Request_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<Identifier > (false, DeleteEventCondition_Request_domain));
                break;
            }
            case DeleteEventCondition_Request_vmd:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<null_type > (false, DeleteEventCondition_Request_vmd));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteEventCondition_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Specific_type > (true, DeleteEventCondition_Request_specific));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DeleteEventCondition_Request_aa_specific));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, DeleteEventCondition_Request_domain));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DeleteEventCondition_Request_vmd));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetEventConditionAttributes-Response

    template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(mmsDeletable_) +
                ITU_T_EXISTS_BMP(priority_) +
                ITU_T_EXISTS_BMP(severity_) +
                ITU_T_EXISTS_BMP(alarmSummaryReports_) +
                ITU_T_EXISTS_BMP(monitoredVariable_) +
                ITU_T_EXISTS_BMP(evaluationInterval_) +
                ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(mmsDeletable_);
        ITU_T_BIND_NUM_CONSTRS(*classV_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_BIND_NUM_CONSTRS(evaluationInterval_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(7);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(mmsDeletable_);
        ITU_T_BIND_NUM_CONSTRS(*classV_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRS(severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_NUM_CONSTRS(evaluationInterval_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(accessControlList_);
    }

    // choice monitoredVariable

    template<> void GetEventConditionAttributes_Response::MonitoredVariable_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case MonitoredVariable_type_variableReference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<VariableSpecification > (false, MonitoredVariable_type_variableReference));
                break;
            }
            case MonitoredVariable_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, MonitoredVariable_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetEventConditionAttributes_Response::MonitoredVariable_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<VariableSpecification > (true, MonitoredVariable_type_variableReference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, MonitoredVariable_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence CS-GetEventConditionAttributes-Response

    template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(groupPriorityOverride_) +
                ITU_T_EXISTS_BMP(listOfReferencingECL_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(groupPriorityOverride_);
        ITU_T_BIND_PER(listOfReferencingECL_);
        ITU_T_BIND_PER(*displayEnhancement_);
    }

    template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(groupPriorityOverride_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(listOfReferencingECL_);
        ITU_T_BIND_PER(*displayEnhancement_);
    }

    // choice groupPriorityOverride

    template<> void CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case GroupPriorityOverride_type_priority:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_NUM_CONSTRS(*value<MMS_Object_Module_1::Priority > (false, GroupPriorityOverride_type_priority), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                break;
            }
            case GroupPriorityOverride_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, GroupPriorityOverride_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetEventConditionAttributes_Response::GroupPriorityOverride_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<MMS_Object_Module_1::Priority > (true, GroupPriorityOverride_type_priority), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, GroupPriorityOverride_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_string:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, DisplayEnhancement_type_string));
                break;
            }
            case DisplayEnhancement_type_index:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, DisplayEnhancement_type_index));
                break;
            }
            case DisplayEnhancement_type_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, DisplayEnhancement_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetEventConditionAttributes_Response::DisplayEnhancement_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, DisplayEnhancement_type_string));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, DisplayEnhancement_type_index));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DisplayEnhancement_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence ReportEventConditionStatus-Response

    template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(enabled_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToActive_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToIdle_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRS(*numberOfEventEnrollments_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(enabled_);
        ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
    }

    template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRS(*numberOfEventEnrollments_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(enabled_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
    }

    // sequence AlterEventConditionMonitoring-Request

    template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(enabled_) +
                ITU_T_EXISTS_BMP(priority_) +
                ITU_T_EXISTS_BMP(alarmSummaryReports_) +
                ITU_T_EXISTS_BMP(evaluationInterval_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_PER(enabled_);
        ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_BIND_NUM_CONSTRS(evaluationInterval_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(enabled_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_NUM_CONSTRS(evaluationInterval_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence CS-AlterEventConditionMonitoring-Request

    template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(changeDisplay_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(changeDisplay_);
    }

    template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(changeDisplay_);
    }

    // choice changeDisplay

    template<> void CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ChangeDisplay_type_string:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, ChangeDisplay_type_string));
                break;
            }
            case ChangeDisplay_type_index:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, ChangeDisplay_type_index));
                break;
            }
            case ChangeDisplay_type_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, ChangeDisplay_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_AlterEventConditionMonitoring_Request::ChangeDisplay_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, ChangeDisplay_type_string));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, ChangeDisplay_type_index));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ChangeDisplay_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence DefineEventAction-Request

    template<> void DefineEventAction_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfModifier_) +
                ITU_T_EXISTS_BMP(cs_extension_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventActionName_);
        ITU_T_BIND_PER(listOfModifier_);
        ITU_T_BIND_PER(*confirmedServiceRequest_);
        ITU_T_BIND_PER(cs_extension_);
    }

    template<> void DefineEventAction_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*eventActionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfModifier_);
        ITU_T_BIND_PER(*confirmedServiceRequest_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(cs_extension_);
    }

    // choice DeleteEventAction-Request

    template<> void DeleteEventAction_Request::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DeleteEventAction_Request_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 3);
                ITU_T_BIND_PER(*value<Specific_type > (false, DeleteEventAction_Request_specific));
                break;
            }
            case DeleteEventAction_Request_aa_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 3);
                ITU_T_BIND_PER(*value<null_type > (false, DeleteEventAction_Request_aa_specific));
                break;
            }
            case DeleteEventAction_Request_domain:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 3);
                ITU_T_BIND_PER(*value<Identifier > (false, DeleteEventAction_Request_domain));
                break;
            }
            case DeleteEventAction_Request_vmd:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 3);
                ITU_T_BIND_PER(*value<null_type > (false, DeleteEventAction_Request_vmd));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteEventAction_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(3);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Specific_type > (true, DeleteEventAction_Request_specific));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DeleteEventAction_Request_aa_specific));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<Identifier > (true, DeleteEventAction_Request_domain));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DeleteEventAction_Request_vmd));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetEventActionAttributes-Response

    template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(mmsDeletable_) +
                ITU_T_EXISTS_BMP(cs_extension_) +
                ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(mmsDeletable_);
        ITU_T_BIND_PER(*listOfModifier_);
        ITU_T_BIND_PER(*confirmedServiceRequest_);
        ITU_T_BIND_PER(cs_extension_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(mmsDeletable_);
        ITU_T_BIND_PER(*listOfModifier_);
        ITU_T_BIND_PER(*confirmedServiceRequest_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(cs_extension_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence DefineEventEnrollment-Request

    template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(eventActionName_) +
                ITU_T_EXISTS_BMP(clientApplication_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*eventConditionTransitions_, 7);
        ITU_T_BIND_NUM_CONSTRS(*alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(eventActionName_);
        ITU_T_BIND_PER(clientApplication_);
    }

    template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*eventConditionTransitions_, 7);
        ITU_T_BIND_NUM_CONSTRS(*alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(eventActionName_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(clientApplication_);
    }

    // choice CS-DefineEventEnrollment-Request

    template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CS_DefineEventEnrollment_Request_impl_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, CS_DefineEventEnrollment_Request_impl_noEnhancement));
                break;
            }
            case CS_DefineEventEnrollment_Request_impl_string:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, CS_DefineEventEnrollment_Request_impl_string));
                break;
            }
            case CS_DefineEventEnrollment_Request_impl_index:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, CS_DefineEventEnrollment_Request_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CS_DefineEventEnrollment_Request_impl_noEnhancement));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, CS_DefineEventEnrollment_Request_impl_string));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, CS_DefineEventEnrollment_Request_impl_index));
                break;
            }
            default:
            {
            }
        }
    }

    // choice DeleteEventEnrollment-Request

    template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DeleteEventEnrollment_Request_specific:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Specific_type > (false, DeleteEventEnrollment_Request_specific));
                break;
            }
            case DeleteEventEnrollment_Request_ec:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<ObjectName > (false, DeleteEventEnrollment_Request_ec));
                break;
            }
            case DeleteEventEnrollment_Request_ea:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<ObjectName > (false, DeleteEventEnrollment_Request_ea));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Specific_type > (true, DeleteEventEnrollment_Request_specific));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, DeleteEventEnrollment_Request_ec));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, DeleteEventEnrollment_Request_ea));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetEventEnrollmentAttributes-Request

    template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(scopeOfRequest_) +
                ITU_T_EXISTS_BMP(eventEnrollmentNames_) +
                ITU_T_EXISTS_BMP(clientApplication_) +
                ITU_T_EXISTS_BMP(eventConditionName_) +
                ITU_T_EXISTS_BMP(eventActionName_) +
                ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(scopeOfRequest_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(eventEnrollmentNames_);
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_PER(eventConditionName_);
        ITU_T_BIND_PER(eventActionName_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void GetEventEnrollmentAttributes_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(6);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRS(scopeOfRequest_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(eventEnrollmentNames_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(clientApplication_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(eventConditionName_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(eventActionName_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence GetEventEnrollmentAttributes-Response

    template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfEEAttributes_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfEEAttributes_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence EEAttributes

    template<> void EEAttributes::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(eventActionName_) +
                ITU_T_EXISTS_BMP(clientApplication_) +
                ITU_T_EXISTS_BMP(mmsDeletable_) +
                ITU_T_EXISTS_BMP(duration_) +
                ITU_T_EXISTS_BMP(invokeID_) +
                ITU_T_EXISTS_BMP(remainingAcceptableDelay_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_PER(eventActionName_);
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_PER(mmsDeletable_);
        ITU_T_BIND_NUM_CONSTRS(*enrollmentClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(duration_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(remainingAcceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*displayEnhancement_);
    }

    template<> void EEAttributes::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(6);

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(eventActionName_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(clientApplication_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(mmsDeletable_);
        ITU_T_BIND_NUM_CONSTRS(*enrollmentClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_NUM_CONSTRS(duration_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_NUM_CONSTRS(invokeID_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_NUM_CONSTRS(remainingAcceptableDelay_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*displayEnhancement_);
    }

    // choice eventConditionName

    template<> void EEAttributes::EventConditionName_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case EventConditionName_type_eventCondition:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, EventConditionName_type_eventCondition));
                break;
            }
            case EventConditionName_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, EventConditionName_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::EventConditionName_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, EventConditionName_type_eventCondition));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, EventConditionName_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // choice eventActionName

    template<> void EEAttributes::EventActionName_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case EventActionName_type_eventAction:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, EventActionName_type_eventAction));
                break;
            }
            case EventActionName_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, EventActionName_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::EventActionName_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, EventActionName_type_eventAction));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, EventActionName_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void EEAttributes::DisplayEnhancement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<null_type > (false, DisplayEnhancement_type_noEnhancement));
                break;
            }
            case DisplayEnhancement_type_string:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, DisplayEnhancement_type_string));
                break;
            }
            case DisplayEnhancement_type_index:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, DisplayEnhancement_type_index));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::DisplayEnhancement_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DisplayEnhancement_type_noEnhancement));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, DisplayEnhancement_type_string));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, DisplayEnhancement_type_index));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence ReportEventEnrollmentStatus-Response

    template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(notificationLost_) +
                ITU_T_EXISTS_BMP(alarmAcknowledgmentRule_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_SIZE_SNGLCONSTRS(*eventConditionTransitions_, 7);
        ITU_T_BIND_PER(notificationLost_);
        ITU_T_BIND_NUM_CONSTRS(*duration_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRS(alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(*currentState_);
    }

    template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_SIZE_SNGLCONSTRS(*eventConditionTransitions_, 7);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(notificationLost_);
        ITU_T_BIND_NUM_CONSTRS(*duration_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(*currentState_);
    }

    // sequence AlterEventEnrollment-Request

    template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(eventConditionTransitions_) +
                ITU_T_EXISTS_BMP(alarmAcknowledgmentRule_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(eventConditionTransitions_, 7);
        ITU_T_BIND_NUM_CONSTRS(alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
    }

    template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(*eventEnrollmentName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_SIZE_SNGLCONSTRS(eventConditionTransitions_, 7);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRS(alarmAcknowledgmentRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
    }

    // sequence AlterEventEnrollment-Response

    template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*currentState_);
        ITU_T_BIND_PER(*transitionTime_);
    }

    template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*currentState_);
        ITU_T_BIND_PER(*transitionTime_);
    }

    // choice currentState

    template<> void AlterEventEnrollment_Response::CurrentState_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case CurrentState_type_state:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<EE_State > (false, CurrentState_type_state));
                break;
            }
            case CurrentState_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, CurrentState_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlterEventEnrollment_Response::CurrentState_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<EE_State > (true, CurrentState_type_state));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, CurrentState_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence CS-AlterEventEnrollment-Request

    template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(changeDisplay_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(changeDisplay_);
    }

    template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(changeDisplay_);
    }

    // choice changeDisplay

    template<> void CS_AlterEventEnrollment_Request::ChangeDisplay_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case ChangeDisplay_type_string:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<visiblestring_type > (false, ChangeDisplay_type_string));
                break;
            }
            case ChangeDisplay_type_index:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, ChangeDisplay_type_index));
                break;
            }
            case ChangeDisplay_type_noEnhancement:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, ChangeDisplay_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_AlterEventEnrollment_Request::ChangeDisplay_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<visiblestring_type > (true, ChangeDisplay_type_string));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, ChangeDisplay_type_index));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, ChangeDisplay_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence DefineEventConditionList-Request

    template<> void DefineEventConditionList_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfEventConditionListName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_BIND_PER(listOfEventConditionListName_);
    }

    template<> void DefineEventConditionList_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfEventConditionListName_);
    }

    // sequence AddEventConditionListReference-Request

    template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfEventConditionListName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_BIND_PER(listOfEventConditionListName_);
    }

    template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfEventConditionListName_);
    }

    // sequence RemoveEventConditionListReference-Request

    template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_BIND_PER(*listOfEventConditionListName_);
    }

    template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_BIND_PER(*listOfEventConditionListName_);
    }

    // choice RemoveEventConditionListReference-Error

    template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RemoveEventConditionListReference_Error_eventCondition:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, RemoveEventConditionListReference_Error_eventCondition));
                break;
            }
            case RemoveEventConditionListReference_Error_eventConditionList:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<ObjectName > (false, RemoveEventConditionListReference_Error_eventConditionList));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, RemoveEventConditionListReference_Error_eventCondition));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ObjectName > (true, RemoveEventConditionListReference_Error_eventConditionList));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence GetEventConditionListAttributes-Response

    template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(listOfEventConditionListName_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_BIND_PER(listOfEventConditionListName_);
    }

    template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfEventConditionName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(listOfEventConditionListName_);
    }

    // sequence ReportEventConditionListStatus-Request

    template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence ReportEventConditionListStatus-Response

    template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfEventConditionStatus_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfEventConditionStatus_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence EventConditionStatus

    template<> void EventConditionStatus::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(enabled_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToActive_) +
                ITU_T_EXISTS_BMP(timeOfLastTransitionToIdle_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRS(*numberOfEventEnrollments_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(enabled_);
        ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
    }

    template<> void EventConditionStatus::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRS(*numberOfEventEnrollments_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(enabled_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(timeOfLastTransitionToActive_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(timeOfLastTransitionToIdle_);
    }

    // sequence AlterEventConditionListMonitoring-Request

    template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(priorityChange_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*enabled_);
        ITU_T_BIND_PER(priorityChange_);
    }

    template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*eventConditionListName_);
        ITU_T_BIND_PER(*enabled_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(priorityChange_);
    }

    // choice priorityChange

    template<> void AlterEventConditionListMonitoring_Request::PriorityChange_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case PriorityChange_type_priorityValue:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<integer_type > (false, PriorityChange_type_priorityValue));
                break;
            }
            case PriorityChange_type_priorityReset:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, PriorityChange_type_priorityReset));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlterEventConditionListMonitoring_Request::PriorityChange_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, PriorityChange_type_priorityValue));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, PriorityChange_type_priorityReset));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence ReadJournal-Request

    template<> void ReadJournal_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(rangeStartSpecification_) +
                ITU_T_EXISTS_BMP(rangeStopSpecification_) +
                ITU_T_EXISTS_BMP(listOfVariables_) +
                ITU_T_EXISTS_BMP(entryToStartAfter_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*journalName_);
        ITU_T_BIND_PER(rangeStartSpecification_);
        ITU_T_BIND_PER(rangeStopSpecification_);
        ITU_T_BIND_PER(listOfVariables_);
        ITU_T_BIND_PER(entryToStartAfter_);
    }

    template<> void ReadJournal_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_BIND_PER(*journalName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(rangeStartSpecification_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(rangeStopSpecification_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(listOfVariables_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(entryToStartAfter_);
    }

    // choice rangeStartSpecification

    template<> void ReadJournal_Request::RangeStartSpecification_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RangeStartSpecification_type_startingTime:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_SIZE_CONSTRS(*value<TimeOfDay > (false, RangeStartSpecification_type_startingTime), 4, 6);
                break;
            }
            case RangeStartSpecification_type_startingEntry:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<octetstring_type > (false, RangeStartSpecification_type_startingEntry));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReadJournal_Request::RangeStartSpecification_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_SIZE_CONSTRS(*value<TimeOfDay > (true, RangeStartSpecification_type_startingTime), 4, 6);
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<octetstring_type > (true, RangeStartSpecification_type_startingEntry));
                break;
            }
            default:
            {
            }
        }
    }

    // choice rangeStopSpecification

    template<> void ReadJournal_Request::RangeStopSpecification_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RangeStopSpecification_type_endingTime:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_SIZE_CONSTRS(*value<TimeOfDay > (false, RangeStopSpecification_type_endingTime), 4, 6);
                break;
            }
            case RangeStopSpecification_type_numberOfEntries:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_NUM_CONSTRS(*value<Integer32 > (false, RangeStopSpecification_type_numberOfEntries), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReadJournal_Request::RangeStopSpecification_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_SIZE_CONSTRS(*value<TimeOfDay > (true, RangeStopSpecification_type_endingTime), 4, 6);
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<Integer32 > (true, RangeStopSpecification_type_numberOfEntries), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence entryToStartAfter

    template<> void ReadJournal_Request::EntryToStartAfter_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_SIZE_CONSTRS(*timeSpecification_, 4, 6);
        ITU_T_BIND_PER(*entrySpecification_);
    }

    template<> void ReadJournal_Request::EntryToStartAfter_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_SIZE_CONSTRS(*timeSpecification_, 4, 6);
        ITU_T_BIND_PER(*entrySpecification_);
    }

    // sequence ReadJournal-Response

    template<> void ReadJournal_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*listOfJournalEntry_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void ReadJournal_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*listOfJournalEntry_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence JournalEntry

    template<> void JournalEntry::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*entryIdentifier_);
        ITU_T_BIND_PER(*originatingApplication_);
        ITU_T_BIND_PER(*entryContent_);
    }

    template<> void JournalEntry::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*entryIdentifier_);
        ITU_T_BIND_PER(*originatingApplication_);
        ITU_T_BIND_PER(*entryContent_);
    }

    // sequence WriteJournal-Request

    template<> void WriteJournal_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*journalName_);
        ITU_T_BIND_PER(*listOfJournalEntry_);
    }

    template<> void WriteJournal_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*journalName_);
        ITU_T_BIND_PER(*listOfJournalEntry_);
    }

    // sequence InitializeJournal-Request

    template<> void InitializeJournal_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(limitSpecification_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*journalName_);
        ITU_T_BIND_PER(limitSpecification_);
    }

    template<> void InitializeJournal_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*journalName_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(limitSpecification_);
    }

    // sequence limitSpecification

    template<> void InitializeJournal_Request::LimitSpecification_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(limitingEntry_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_SIZE_CONSTRS(*limitingTime_, 4, 6);
        ITU_T_BIND_PER(limitingEntry_);
    }

    template<> void InitializeJournal_Request::LimitSpecification_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_SIZE_CONSTRS(*limitingTime_, 4, 6);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(limitingEntry_);
    }

    // sequence ReportJournalStatus-Response

    template<> void ReportJournalStatus_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*currentEntries_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void ReportJournalStatus_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_NUM_CONSTRS(*currentEntries_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(accessControlList_);
    }

    // sequence CreateJournal-Request

    template<> void CreateJournal_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*journalName_);
    }

    template<> void CreateJournal_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*journalName_);
    }

    // sequence DeleteJournal-Request

    template<> void DeleteJournal_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*journalName_);
    }

    template<> void DeleteJournal_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*journalName_);
    }

    // sequence EntryContent

    template<> void EntryContent::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_SIZE_CONSTRS(*occurrenceTime_, 4, 6);
        ITU_T_BIND_PER(*entryForm_);
    }

    template<> void EntryContent::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_SIZE_CONSTRS(*occurrenceTime_, 4, 6);
        ITU_T_BIND_PER(*entryForm_);
    }

    // choice entryForm

    template<> void EntryContent::EntryForm_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case EntryForm_type_data:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Data_type > (false, EntryForm_type_data));
                break;
            }
            case EntryForm_type_annotation:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<MMSString > (false, EntryForm_type_annotation));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EntryContent::EntryForm_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<Data_type > (true, EntryForm_type_data));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<MMSString > (true, EntryForm_type_annotation));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence data

    template<> void EntryContent::EntryForm_type::Data_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(event_) +
                ITU_T_EXISTS_BMP(listOfVariables_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(event_);
        ITU_T_BIND_PER(listOfVariables_);
    }

    template<> void EntryContent::EntryForm_type::Data_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(event_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(listOfVariables_);
    }

    // sequence event

    template<> void EntryContent::EntryForm_type::Data_type::Event_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
    }

    template<> void EntryContent::EntryForm_type::Data_type::Event_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*eventConditionName_);
        ITU_T_BIND_NUM_CONSTRS(*currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

