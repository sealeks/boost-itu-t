#include "ISO-9506-MMS-1.hpp"

namespace ISO_9506_MMS_1 {

    // choice MMSpdu

    void MMSpdu::cancel_RequestPDU(const Cancel_RequestPDU& vl) {
        set<Cancel_RequestPDU>(new Cancel_RequestPDU(vl), MMSpdu_cancel_RequestPDU);
    }

    void MMSpdu::cancel_ResponsePDU(const Cancel_ResponsePDU& vl) {
        set<Cancel_ResponsePDU>(new Cancel_ResponsePDU(vl), MMSpdu_cancel_ResponsePDU);
    }

    void MMSpdu::conclude_RequestPDU(const Conclude_RequestPDU& vl) {
        set<Conclude_RequestPDU>(new Conclude_RequestPDU(vl), MMSpdu_conclude_RequestPDU);
    }

    void MMSpdu::conclude_ResponsePDU(const Conclude_ResponsePDU& vl) {
        set<Conclude_ResponsePDU>(new Conclude_ResponsePDU(vl), MMSpdu_conclude_ResponsePDU);
    }

    template<> void MMSpdu::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case MMSpdu_confirmed_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Confirmed_RequestPDU > (false, MMSpdu_confirmed_RequestPDU), 0);
                break;
            }
            case MMSpdu_confirmed_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<Confirmed_ResponsePDU > (false, MMSpdu_confirmed_ResponsePDU), 1);
                break;
            }
            case MMSpdu_confirmed_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Confirmed_ErrorPDU > (false, MMSpdu_confirmed_ErrorPDU), 2);
                break;
            }
            case MMSpdu_unconfirmed_PDU:
            {
                ITU_T_IMPLICIT_TAG(value<Unconfirmed_PDU > (false, MMSpdu_unconfirmed_PDU), 3);
                break;
            }
            case MMSpdu_rejectPDU:
            {
                ITU_T_IMPLICIT_TAG(value<RejectPDU > (false, MMSpdu_rejectPDU), 4);
                break;
            }
            case MMSpdu_cancel_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Cancel_RequestPDU > (false, MMSpdu_cancel_RequestPDU), 5);
                break;
            }
            case MMSpdu_cancel_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<Cancel_ResponsePDU > (false, MMSpdu_cancel_ResponsePDU), 6);
                break;
            }
            case MMSpdu_cancel_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Cancel_ErrorPDU > (false, MMSpdu_cancel_ErrorPDU), 7);
                break;
            }
            case MMSpdu_initiate_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Initiate_RequestPDU > (false, MMSpdu_initiate_RequestPDU), 8);
                break;
            }
            case MMSpdu_initiate_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<Initiate_ResponsePDU > (false, MMSpdu_initiate_ResponsePDU), 9);
                break;
            }
            case MMSpdu_initiate_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Initiate_ErrorPDU > (false, MMSpdu_initiate_ErrorPDU), 10);
                break;
            }
            case MMSpdu_conclude_RequestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Conclude_RequestPDU > (false, MMSpdu_conclude_RequestPDU), 11);
                break;
            }
            case MMSpdu_conclude_ResponsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<Conclude_ResponsePDU > (false, MMSpdu_conclude_ResponsePDU), 12);
                break;
            }
            case MMSpdu_conclude_ErrorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<Conclude_ErrorPDU > (false, MMSpdu_conclude_ErrorPDU), 13);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Confirmed_RequestPDU > (true, MMSpdu_confirmed_RequestPDU), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Confirmed_ResponsePDU > (true, MMSpdu_confirmed_ResponsePDU), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Confirmed_ErrorPDU > (true, MMSpdu_confirmed_ErrorPDU), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Unconfirmed_PDU > (true, MMSpdu_unconfirmed_PDU), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RejectPDU > (true, MMSpdu_rejectPDU), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Cancel_RequestPDU > (true, MMSpdu_cancel_RequestPDU), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Cancel_ResponsePDU > (true, MMSpdu_cancel_ResponsePDU), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Cancel_ErrorPDU > (true, MMSpdu_cancel_ErrorPDU), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Initiate_RequestPDU > (true, MMSpdu_initiate_RequestPDU), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Initiate_ResponsePDU > (true, MMSpdu_initiate_ResponsePDU), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Initiate_ErrorPDU > (true, MMSpdu_initiate_ErrorPDU), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Conclude_RequestPDU > (true, MMSpdu_conclude_RequestPDU), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Conclude_ResponsePDU > (true, MMSpdu_conclude_ResponsePDU), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Conclude_ErrorPDU > (true, MMSpdu_conclude_ErrorPDU), 13)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    Confirmed_RequestPDU::Confirmed_RequestPDU() : invokeID_(), service_() {
    };

    Confirmed_RequestPDU::Confirmed_RequestPDU(const Unsigned32& arg__invokeID,
            const ConfirmedServiceRequest& arg__service) :
    invokeID_(arg__invokeID),
    service_(arg__service) {
    };

    Confirmed_RequestPDU::Confirmed_RequestPDU(boost::shared_ptr< Unsigned32> arg__invokeID,
            boost::shared_ptr< listOfModifiers_type> arg__listOfModifiers,
            boost::shared_ptr< ConfirmedServiceRequest> arg__service,
            boost::shared_ptr< Request_Detail> arg__service_ext) :
    invokeID_(arg__invokeID),
    listOfModifiers_(arg__listOfModifiers),
    service_(arg__service),
    service_ext_(arg__service_ext) {
    };

    template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(invokeID_);
        ITU_T_BIND_TAG(listOfModifiers_);
        ITU_T_BIND_CHOICE(service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    template<> void Confirmed_RequestPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(invokeID_);
        ITU_T_BIND_TAG(listOfModifiers_);
        ITU_T_BIND_CHOICE(service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    Unsigned32& Confirmed_RequestPDU::invokeID() {
        return *invokeID_;
    }

    const Unsigned32& Confirmed_RequestPDU::invokeID() const {
        return *invokeID_;
    }

    void Confirmed_RequestPDU::invokeID(const Unsigned32& vl) {
        invokeID_ = vl;
    }

    void Confirmed_RequestPDU::invokeID(boost::shared_ptr< Unsigned32> vl) {
        invokeID_ = vl;
    }

    boost::shared_ptr<Confirmed_RequestPDU::listOfModifiers_type> Confirmed_RequestPDU::listOfModifiers__new() {
        return listOfModifiers_ = boost::shared_ptr<listOfModifiers_type>(new listOfModifiers_type());
    }

    void Confirmed_RequestPDU::listOfModifiers(const listOfModifiers_type& vl) {
        listOfModifiers_ = boost::shared_ptr<listOfModifiers_type>(new listOfModifiers_type(vl));
    }

    ConfirmedServiceRequest& Confirmed_RequestPDU::service() {
        return *service_;
    }

    const ConfirmedServiceRequest& Confirmed_RequestPDU::service() const {
        return *service_;
    }

    void Confirmed_RequestPDU::service(const ConfirmedServiceRequest& vl) {
        service_ = vl;
    }

    void Confirmed_RequestPDU::service(boost::shared_ptr< ConfirmedServiceRequest> vl) {
        service_ = vl;
    }

    boost::shared_ptr<Request_Detail> Confirmed_RequestPDU::service_ext__new() {
        return service_ext_ = boost::shared_ptr<Request_Detail>(new Request_Detail());
    }

    void Confirmed_RequestPDU::service_ext(const Request_Detail& vl) {
        service_ext_ = boost::shared_ptr<Request_Detail>(new Request_Detail(vl));
    }


    // choice ConfirmedServiceRequest

    void ConfirmedServiceRequest::status(const Status_Request& vl) {
        set<Status_Request>(new Status_Request(vl), ConfirmedServiceRequest_status);
    }

    void ConfirmedServiceRequest::identify(const Identify_Request& vl) {
        set<Identify_Request>(new Identify_Request(vl), ConfirmedServiceRequest_identify);
    }

    void ConfirmedServiceRequest::downloadSegment(const DownloadSegment_Request& vl) {
        set<DownloadSegment_Request>(new DownloadSegment_Request(vl), ConfirmedServiceRequest_downloadSegment);
    }

    void ConfirmedServiceRequest::initiateUploadSequence(const InitiateUploadSequence_Request& vl) {
        set<InitiateUploadSequence_Request>(new InitiateUploadSequence_Request(vl), ConfirmedServiceRequest_initiateUploadSequence);
    }

    void ConfirmedServiceRequest::uploadSegment(const UploadSegment_Request& vl) {
        set<UploadSegment_Request>(new UploadSegment_Request(vl), ConfirmedServiceRequest_uploadSegment);
    }

    void ConfirmedServiceRequest::terminateUploadSequence(const TerminateUploadSequence_Request& vl) {
        set<TerminateUploadSequence_Request>(new TerminateUploadSequence_Request(vl), ConfirmedServiceRequest_terminateUploadSequence);
    }

    void ConfirmedServiceRequest::deleteDomain(const DeleteDomain_Request& vl) {
        set<DeleteDomain_Request>(new DeleteDomain_Request(vl), ConfirmedServiceRequest_deleteDomain);
    }

    void ConfirmedServiceRequest::getDomainAttributes(const GetDomainAttributes_Request& vl) {
        set<GetDomainAttributes_Request>(new GetDomainAttributes_Request(vl), ConfirmedServiceRequest_getDomainAttributes);
    }

    void ConfirmedServiceRequest::deleteProgramInvocation(const DeleteProgramInvocation_Request& vl) {
        set<DeleteProgramInvocation_Request>(new DeleteProgramInvocation_Request(vl), ConfirmedServiceRequest_deleteProgramInvocation);
    }

    void ConfirmedServiceRequest::getProgramInvocationAttributes(const GetProgramInvocationAttributes_Request& vl) {
        set<GetProgramInvocationAttributes_Request>(new GetProgramInvocationAttributes_Request(vl), ConfirmedServiceRequest_getProgramInvocationAttributes);
    }

    void ConfirmedServiceRequest::fileRead(const ISO_9506_MMS_1A::FileRead_Request& vl) {
        set<ISO_9506_MMS_1A::FileRead_Request>(new ISO_9506_MMS_1A::FileRead_Request(vl), ConfirmedServiceRequest_fileRead);
    }

    void ConfirmedServiceRequest::fileClose(const ISO_9506_MMS_1A::FileClose_Request& vl) {
        set<ISO_9506_MMS_1A::FileClose_Request>(new ISO_9506_MMS_1A::FileClose_Request(vl), ConfirmedServiceRequest_fileClose);
    }

    void ConfirmedServiceRequest::deleteAccessControlList(const DeleteAccessControlList_Request& vl) {
        set<DeleteAccessControlList_Request>(new DeleteAccessControlList_Request(vl), ConfirmedServiceRequest_deleteAccessControlList);
    }

    template<> void ConfirmedServiceRequest::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConfirmedServiceRequest_status:
            {
                ITU_T_IMPLICIT_TAG(value<Status_Request > (false, ConfirmedServiceRequest_status), 0);
                break;
            }
            case ConfirmedServiceRequest_getNameList:
            {
                ITU_T_IMPLICIT_TAG(value<GetNameList_Request > (false, ConfirmedServiceRequest_getNameList), 1);
                break;
            }
            case ConfirmedServiceRequest_identify:
            {
                ITU_T_IMPLICIT_TAG(value<Identify_Request > (false, ConfirmedServiceRequest_identify), 2);
                break;
            }
            case ConfirmedServiceRequest_rename:
            {
                ITU_T_IMPLICIT_TAG(value<Rename_Request > (false, ConfirmedServiceRequest_rename), 3);
                break;
            }
            case ConfirmedServiceRequest_read:
            {
                ITU_T_IMPLICIT_TAG(value<Read_Request > (false, ConfirmedServiceRequest_read), 4);
                break;
            }
            case ConfirmedServiceRequest_write:
            {
                ITU_T_IMPLICIT_TAG(value<Write_Request > (false, ConfirmedServiceRequest_write), 5);
                break;
            }
            case ConfirmedServiceRequest_getVariableAccessAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (false, ConfirmedServiceRequest_getVariableAccessAttributes), 6);
                break;
            }
            case ConfirmedServiceRequest_defineNamedVariable:
            {
                ITU_T_IMPLICIT_TAG(value<DefineNamedVariable_Request > (false, ConfirmedServiceRequest_defineNamedVariable), 7);
                break;
            }
            case ConfirmedServiceRequest_defineScatteredAccess:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (false, ConfirmedServiceRequest_defineScatteredAccess), 8);
                break;
            }
            case ConfirmedServiceRequest_getScatteredAccessAttributes:
            {
                ITU_T_CHOICE_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (false, ConfirmedServiceRequest_getScatteredAccessAttributes), 9);
                break;
            }
            case ConfirmedServiceRequest_deleteVariableAccess:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteVariableAccess_Request > (false, ConfirmedServiceRequest_deleteVariableAccess), 10);
                break;
            }
            case ConfirmedServiceRequest_defineNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(value<DefineNamedVariableList_Request > (false, ConfirmedServiceRequest_defineNamedVariableList), 11);
                break;
            }
            case ConfirmedServiceRequest_getNamedVariableListAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (false, ConfirmedServiceRequest_getNamedVariableListAttributes), 12);
                break;
            }
            case ConfirmedServiceRequest_deleteNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteNamedVariableList_Request > (false, ConfirmedServiceRequest_deleteNamedVariableList), 13);
                break;
            }
            case ConfirmedServiceRequest_defineNamedType:
            {
                ITU_T_IMPLICIT_TAG(value<DefineNamedType_Request > (false, ConfirmedServiceRequest_defineNamedType), 14);
                break;
            }
            case ConfirmedServiceRequest_getNamedTypeAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (false, ConfirmedServiceRequest_getNamedTypeAttributes), 15);
                break;
            }
            case ConfirmedServiceRequest_deleteNamedType:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteNamedType_Request > (false, ConfirmedServiceRequest_deleteNamedType), 16);
                break;
            }
            case ConfirmedServiceRequest_input:
            {
                ITU_T_IMPLICIT_TAG(value<Input_Request > (false, ConfirmedServiceRequest_input), 17);
                break;
            }
            case ConfirmedServiceRequest_output:
            {
                ITU_T_IMPLICIT_TAG(value<Output_Request > (false, ConfirmedServiceRequest_output), 18);
                break;
            }
            case ConfirmedServiceRequest_takeControl:
            {
                ITU_T_IMPLICIT_TAG(value<TakeControl_Request > (false, ConfirmedServiceRequest_takeControl), 19);
                break;
            }
            case ConfirmedServiceRequest_relinquishControl:
            {
                ITU_T_IMPLICIT_TAG(value<RelinquishControl_Request > (false, ConfirmedServiceRequest_relinquishControl), 20);
                break;
            }
            case ConfirmedServiceRequest_defineSemaphore:
            {
                ITU_T_IMPLICIT_TAG(value<DefineSemaphore_Request > (false, ConfirmedServiceRequest_defineSemaphore), 21);
                break;
            }
            case ConfirmedServiceRequest_deleteSemaphore:
            {
                ITU_T_CHOICE_TAG(value<DeleteSemaphore_Request > (false, ConfirmedServiceRequest_deleteSemaphore), 22);
                break;
            }
            case ConfirmedServiceRequest_reportSemaphoreStatus:
            {
                ITU_T_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (false, ConfirmedServiceRequest_reportSemaphoreStatus), 23);
                break;
            }
            case ConfirmedServiceRequest_reportPoolSemaphoreStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Request > (false, ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24);
                break;
            }
            case ConfirmedServiceRequest_reportSemaphoreEntryStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Request > (false, ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25);
                break;
            }
            case ConfirmedServiceRequest_initiateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<InitiateDownloadSequence_Request > (false, ConfirmedServiceRequest_initiateDownloadSequence), 26);
                break;
            }
            case ConfirmedServiceRequest_downloadSegment:
            {
                ITU_T_IMPLICIT_TAG(value<DownloadSegment_Request > (false, ConfirmedServiceRequest_downloadSegment), 27);
                break;
            }
            case ConfirmedServiceRequest_terminateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<TerminateDownloadSequence_Request > (false, ConfirmedServiceRequest_terminateDownloadSequence), 28);
                break;
            }
            case ConfirmedServiceRequest_initiateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<InitiateUploadSequence_Request > (false, ConfirmedServiceRequest_initiateUploadSequence), 29);
                break;
            }
            case ConfirmedServiceRequest_uploadSegment:
            {
                ITU_T_IMPLICIT_TAG(value<UploadSegment_Request > (false, ConfirmedServiceRequest_uploadSegment), 30);
                break;
            }
            case ConfirmedServiceRequest_terminateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<TerminateUploadSequence_Request > (false, ConfirmedServiceRequest_terminateUploadSequence), 31);
                break;
            }
            case ConfirmedServiceRequest_requestDomainDownload:
            {
                ITU_T_IMPLICIT_TAG(value<RequestDomainDownload_Request > (false, ConfirmedServiceRequest_requestDomainDownload), 32);
                break;
            }
            case ConfirmedServiceRequest_requestDomainUpload:
            {
                ITU_T_IMPLICIT_TAG(value<RequestDomainUpload_Request > (false, ConfirmedServiceRequest_requestDomainUpload), 33);
                break;
            }
            case ConfirmedServiceRequest_loadDomainContent:
            {
                ITU_T_IMPLICIT_TAG(value<LoadDomainContent_Request > (false, ConfirmedServiceRequest_loadDomainContent), 34);
                break;
            }
            case ConfirmedServiceRequest_storeDomainContent:
            {
                ITU_T_IMPLICIT_TAG(value<StoreDomainContent_Request > (false, ConfirmedServiceRequest_storeDomainContent), 35);
                break;
            }
            case ConfirmedServiceRequest_deleteDomain:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteDomain_Request > (false, ConfirmedServiceRequest_deleteDomain), 36);
                break;
            }
            case ConfirmedServiceRequest_getDomainAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetDomainAttributes_Request > (false, ConfirmedServiceRequest_getDomainAttributes), 37);
                break;
            }
            case ConfirmedServiceRequest_createProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<CreateProgramInvocation_Request > (false, ConfirmedServiceRequest_createProgramInvocation), 38);
                break;
            }
            case ConfirmedServiceRequest_deleteProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteProgramInvocation_Request > (false, ConfirmedServiceRequest_deleteProgramInvocation), 39);
                break;
            }
            case ConfirmedServiceRequest_start:
            {
                ITU_T_IMPLICIT_TAG(value<Start_Request > (false, ConfirmedServiceRequest_start), 40);
                break;
            }
            case ConfirmedServiceRequest_stop:
            {
                ITU_T_IMPLICIT_TAG(value<Stop_Request > (false, ConfirmedServiceRequest_stop), 41);
                break;
            }
            case ConfirmedServiceRequest_resume:
            {
                ITU_T_IMPLICIT_TAG(value<Resume_Request > (false, ConfirmedServiceRequest_resume), 42);
                break;
            }
            case ConfirmedServiceRequest_reset:
            {
                ITU_T_IMPLICIT_TAG(value<Reset_Request > (false, ConfirmedServiceRequest_reset), 43);
                break;
            }
            case ConfirmedServiceRequest_kill:
            {
                ITU_T_IMPLICIT_TAG(value<Kill_Request > (false, ConfirmedServiceRequest_kill), 44);
                break;
            }
            case ConfirmedServiceRequest_getProgramInvocationAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Request > (false, ConfirmedServiceRequest_getProgramInvocationAttributes), 45);
                break;
            }
            case ConfirmedServiceRequest_obtainFile:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Request > (false, ConfirmedServiceRequest_obtainFile), 46);
                break;
            }
            case ConfirmedServiceRequest_defineEventCondition:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventCondition_Request > (false, ConfirmedServiceRequest_defineEventCondition), 47);
                break;
            }
            case ConfirmedServiceRequest_deleteEventCondition:
            {
                ITU_T_CHOICE_TAG(value<DeleteEventCondition_Request > (false, ConfirmedServiceRequest_deleteEventCondition), 48);
                break;
            }
            case ConfirmedServiceRequest_getEventConditionAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetEventConditionAttributes_Request > (false, ConfirmedServiceRequest_getEventConditionAttributes), 49);
                break;
            }
            case ConfirmedServiceRequest_reportEventConditionStatus:
            {
                ITU_T_CHOICE_TAG(value<ReportEventConditionStatus_Request > (false, ConfirmedServiceRequest_reportEventConditionStatus), 50);
                break;
            }
            case ConfirmedServiceRequest_alterEventConditionMonitoring:
            {
                ITU_T_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Request > (false, ConfirmedServiceRequest_alterEventConditionMonitoring), 51);
                break;
            }
            case ConfirmedServiceRequest_triggerEvent:
            {
                ITU_T_IMPLICIT_TAG(value<TriggerEvent_Request > (false, ConfirmedServiceRequest_triggerEvent), 52);
                break;
            }
            case ConfirmedServiceRequest_defineEventAction:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventAction_Request > (false, ConfirmedServiceRequest_defineEventAction), 53);
                break;
            }
            case ConfirmedServiceRequest_deleteEventAction:
            {
                ITU_T_CHOICE_TAG(value<DeleteEventAction_Request > (false, ConfirmedServiceRequest_deleteEventAction), 54);
                break;
            }
            case ConfirmedServiceRequest_getEventActionAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetEventActionAttributes_Request > (false, ConfirmedServiceRequest_getEventActionAttributes), 55);
                break;
            }
            case ConfirmedServiceRequest_reportEventActionStatus:
            {
                ITU_T_CHOICE_TAG(value<ReportEventActionStatus_Request > (false, ConfirmedServiceRequest_reportEventActionStatus), 56);
                break;
            }
            case ConfirmedServiceRequest_defineEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventEnrollment_Request > (false, ConfirmedServiceRequest_defineEventEnrollment), 57);
                break;
            }
            case ConfirmedServiceRequest_deleteEventEnrollment:
            {
                ITU_T_CHOICE_TAG(value<DeleteEventEnrollment_Request > (false, ConfirmedServiceRequest_deleteEventEnrollment), 58);
                break;
            }
            case ConfirmedServiceRequest_alterEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<AlterEventEnrollment_Request > (false, ConfirmedServiceRequest_alterEventEnrollment), 59);
                break;
            }
            case ConfirmedServiceRequest_reportEventEnrollmentStatus:
            {
                ITU_T_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (false, ConfirmedServiceRequest_reportEventEnrollmentStatus), 60);
                break;
            }
            case ConfirmedServiceRequest_getEventEnrollmentAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Request > (false, ConfirmedServiceRequest_getEventEnrollmentAttributes), 61);
                break;
            }
            case ConfirmedServiceRequest_acknowledgeEventNotification:
            {
                ITU_T_IMPLICIT_TAG(value<AcknowledgeEventNotification_Request > (false, ConfirmedServiceRequest_acknowledgeEventNotification), 62);
                break;
            }
            case ConfirmedServiceRequest_getAlarmSummary:
            {
                ITU_T_IMPLICIT_TAG(value<GetAlarmSummary_Request > (false, ConfirmedServiceRequest_getAlarmSummary), 63);
                break;
            }
            case ConfirmedServiceRequest_getAlarmEnrollmentSummary:
            {
                ITU_T_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Request > (false, ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64);
                break;
            }
            case ConfirmedServiceRequest_readJournal:
            {
                ITU_T_IMPLICIT_TAG(value<ReadJournal_Request > (false, ConfirmedServiceRequest_readJournal), 65);
                break;
            }
            case ConfirmedServiceRequest_writeJournal:
            {
                ITU_T_IMPLICIT_TAG(value<WriteJournal_Request > (false, ConfirmedServiceRequest_writeJournal), 66);
                break;
            }
            case ConfirmedServiceRequest_initializeJournal:
            {
                ITU_T_IMPLICIT_TAG(value<InitializeJournal_Request > (false, ConfirmedServiceRequest_initializeJournal), 67);
                break;
            }
            case ConfirmedServiceRequest_reportJournalStatus:
            {
                ITU_T_CHOICE_TAG(value<ReportJournalStatus_Request > (false, ConfirmedServiceRequest_reportJournalStatus), 68);
                break;
            }
            case ConfirmedServiceRequest_createJournal:
            {
                ITU_T_IMPLICIT_TAG(value<CreateJournal_Request > (false, ConfirmedServiceRequest_createJournal), 69);
                break;
            }
            case ConfirmedServiceRequest_deleteJournal:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteJournal_Request > (false, ConfirmedServiceRequest_deleteJournal), 70);
                break;
            }
            case ConfirmedServiceRequest_getCapabilityList:
            {
                ITU_T_IMPLICIT_TAG(value<GetCapabilityList_Request > (false, ConfirmedServiceRequest_getCapabilityList), 71);
                break;
            }
            case ConfirmedServiceRequest_fileOpen:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Request > (false, ConfirmedServiceRequest_fileOpen), 72);
                break;
            }
            case ConfirmedServiceRequest_fileRead:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Request > (false, ConfirmedServiceRequest_fileRead), 73);
                break;
            }
            case ConfirmedServiceRequest_fileClose:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Request > (false, ConfirmedServiceRequest_fileClose), 74);
                break;
            }
            case ConfirmedServiceRequest_fileRename:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Request > (false, ConfirmedServiceRequest_fileRename), 75);
                break;
            }
            case ConfirmedServiceRequest_fileDelete:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Request > (false, ConfirmedServiceRequest_fileDelete), 76);
                break;
            }
            case ConfirmedServiceRequest_fileDirectory:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Request > (false, ConfirmedServiceRequest_fileDirectory), 77);
                break;
            }
            case ConfirmedServiceRequest_additionalService:
            {
                ITU_T_CHOICE_TAG(value<AdditionalService_Request > (false, ConfirmedServiceRequest_additionalService), 78);
                break;
            }
            case ConfirmedServiceRequest_getDataExchangeAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (false, ConfirmedServiceRequest_getDataExchangeAttributes), 80);
                break;
            }
            case ConfirmedServiceRequest_exchangeData:
            {
                ITU_T_IMPLICIT_TAG(value<ExchangeData_Request > (false, ConfirmedServiceRequest_exchangeData), 81);
                break;
            }
            case ConfirmedServiceRequest_defineAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(value<DefineAccessControlList_Request > (false, ConfirmedServiceRequest_defineAccessControlList), 82);
                break;
            }
            case ConfirmedServiceRequest_getAccessControlListAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (false, ConfirmedServiceRequest_getAccessControlListAttributes), 83);
                break;
            }
            case ConfirmedServiceRequest_reportAccessControlledObjects:
            {
                ITU_T_IMPLICIT_TAG(value<ReportAccessControlledObjects_Request > (false, ConfirmedServiceRequest_reportAccessControlledObjects), 84);
                break;
            }
            case ConfirmedServiceRequest_deleteAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteAccessControlList_Request > (false, ConfirmedServiceRequest_deleteAccessControlList), 85);
                break;
            }
            case ConfirmedServiceRequest_changeAccessControl:
            {
                ITU_T_IMPLICIT_TAG(value<ChangeAccessControl_Request > (false, ConfirmedServiceRequest_changeAccessControl), 86);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Status_Request > (true, ConfirmedServiceRequest_status), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetNameList_Request > (true, ConfirmedServiceRequest_getNameList), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identify_Request > (true, ConfirmedServiceRequest_identify), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Rename_Request > (true, ConfirmedServiceRequest_rename), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Read_Request > (true, ConfirmedServiceRequest_read), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Write_Request > (true, ConfirmedServiceRequest_write), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetVariableAccessAttributes_Request > (true, ConfirmedServiceRequest_getVariableAccessAttributes), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineNamedVariable_Request > (true, ConfirmedServiceRequest_defineNamedVariable), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Request > (true, ConfirmedServiceRequest_defineScatteredAccess), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_CHOICE_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Request > (true, ConfirmedServiceRequest_getScatteredAccessAttributes), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteVariableAccess_Request > (true, ConfirmedServiceRequest_deleteVariableAccess), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineNamedVariableList_Request > (true, ConfirmedServiceRequest_defineNamedVariableList), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetNamedVariableListAttributes_Request > (true, ConfirmedServiceRequest_getNamedVariableListAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteNamedVariableList_Request > (true, ConfirmedServiceRequest_deleteNamedVariableList), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineNamedType_Request > (true, ConfirmedServiceRequest_defineNamedType), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetNamedTypeAttributes_Request > (true, ConfirmedServiceRequest_getNamedTypeAttributes), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteNamedType_Request > (true, ConfirmedServiceRequest_deleteNamedType), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Input_Request > (true, ConfirmedServiceRequest_input), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Output_Request > (true, ConfirmedServiceRequest_output), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TakeControl_Request > (true, ConfirmedServiceRequest_takeControl), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RelinquishControl_Request > (true, ConfirmedServiceRequest_relinquishControl), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineSemaphore_Request > (true, ConfirmedServiceRequest_defineSemaphore), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_CHOICE_TAG(value<DeleteSemaphore_Request > (true, ConfirmedServiceRequest_deleteSemaphore), 22)) return;
                        else free();
                        break;
                    }
                    case 23:
                    {
                        if (ITU_T_CHOICE_TAG(value<ReportSemaphoreStatus_Request > (true, ConfirmedServiceRequest_reportSemaphoreStatus), 23)) return;
                        else free();
                        break;
                    }
                    case 24:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Request > (true, ConfirmedServiceRequest_reportPoolSemaphoreStatus), 24)) return;
                        else free();
                        break;
                    }
                    case 25:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Request > (true, ConfirmedServiceRequest_reportSemaphoreEntryStatus), 25)) return;
                        else free();
                        break;
                    }
                    case 26:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitiateDownloadSequence_Request > (true, ConfirmedServiceRequest_initiateDownloadSequence), 26)) return;
                        else free();
                        break;
                    }
                    case 27:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DownloadSegment_Request > (true, ConfirmedServiceRequest_downloadSegment), 27)) return;
                        else free();
                        break;
                    }
                    case 28:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TerminateDownloadSequence_Request > (true, ConfirmedServiceRequest_terminateDownloadSequence), 28)) return;
                        else free();
                        break;
                    }
                    case 29:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitiateUploadSequence_Request > (true, ConfirmedServiceRequest_initiateUploadSequence), 29)) return;
                        else free();
                        break;
                    }
                    case 30:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UploadSegment_Request > (true, ConfirmedServiceRequest_uploadSegment), 30)) return;
                        else free();
                        break;
                    }
                    case 31:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TerminateUploadSequence_Request > (true, ConfirmedServiceRequest_terminateUploadSequence), 31)) return;
                        else free();
                        break;
                    }
                    case 32:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RequestDomainDownload_Request > (true, ConfirmedServiceRequest_requestDomainDownload), 32)) return;
                        else free();
                        break;
                    }
                    case 33:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RequestDomainUpload_Request > (true, ConfirmedServiceRequest_requestDomainUpload), 33)) return;
                        else free();
                        break;
                    }
                    case 34:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<LoadDomainContent_Request > (true, ConfirmedServiceRequest_loadDomainContent), 34)) return;
                        else free();
                        break;
                    }
                    case 35:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StoreDomainContent_Request > (true, ConfirmedServiceRequest_storeDomainContent), 35)) return;
                        else free();
                        break;
                    }
                    case 36:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteDomain_Request > (true, ConfirmedServiceRequest_deleteDomain), 36)) return;
                        else free();
                        break;
                    }
                    case 37:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetDomainAttributes_Request > (true, ConfirmedServiceRequest_getDomainAttributes), 37)) return;
                        else free();
                        break;
                    }
                    case 38:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CreateProgramInvocation_Request > (true, ConfirmedServiceRequest_createProgramInvocation), 38)) return;
                        else free();
                        break;
                    }
                    case 39:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteProgramInvocation_Request > (true, ConfirmedServiceRequest_deleteProgramInvocation), 39)) return;
                        else free();
                        break;
                    }
                    case 40:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Start_Request > (true, ConfirmedServiceRequest_start), 40)) return;
                        else free();
                        break;
                    }
                    case 41:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Stop_Request > (true, ConfirmedServiceRequest_stop), 41)) return;
                        else free();
                        break;
                    }
                    case 42:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Resume_Request > (true, ConfirmedServiceRequest_resume), 42)) return;
                        else free();
                        break;
                    }
                    case 43:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Reset_Request > (true, ConfirmedServiceRequest_reset), 43)) return;
                        else free();
                        break;
                    }
                    case 44:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Kill_Request > (true, ConfirmedServiceRequest_kill), 44)) return;
                        else free();
                        break;
                    }
                    case 45:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Request > (true, ConfirmedServiceRequest_getProgramInvocationAttributes), 45)) return;
                        else free();
                        break;
                    }
                    case 46:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Request > (true, ConfirmedServiceRequest_obtainFile), 46)) return;
                        else free();
                        break;
                    }
                    case 47:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventCondition_Request > (true, ConfirmedServiceRequest_defineEventCondition), 47)) return;
                        else free();
                        break;
                    }
                    case 48:
                    {
                        if (ITU_T_CHOICE_TAG(value<DeleteEventCondition_Request > (true, ConfirmedServiceRequest_deleteEventCondition), 48)) return;
                        else free();
                        break;
                    }
                    case 49:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetEventConditionAttributes_Request > (true, ConfirmedServiceRequest_getEventConditionAttributes), 49)) return;
                        else free();
                        break;
                    }
                    case 50:
                    {
                        if (ITU_T_CHOICE_TAG(value<ReportEventConditionStatus_Request > (true, ConfirmedServiceRequest_reportEventConditionStatus), 50)) return;
                        else free();
                        break;
                    }
                    case 51:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Request > (true, ConfirmedServiceRequest_alterEventConditionMonitoring), 51)) return;
                        else free();
                        break;
                    }
                    case 52:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TriggerEvent_Request > (true, ConfirmedServiceRequest_triggerEvent), 52)) return;
                        else free();
                        break;
                    }
                    case 53:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventAction_Request > (true, ConfirmedServiceRequest_defineEventAction), 53)) return;
                        else free();
                        break;
                    }
                    case 54:
                    {
                        if (ITU_T_CHOICE_TAG(value<DeleteEventAction_Request > (true, ConfirmedServiceRequest_deleteEventAction), 54)) return;
                        else free();
                        break;
                    }
                    case 55:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetEventActionAttributes_Request > (true, ConfirmedServiceRequest_getEventActionAttributes), 55)) return;
                        else free();
                        break;
                    }
                    case 56:
                    {
                        if (ITU_T_CHOICE_TAG(value<ReportEventActionStatus_Request > (true, ConfirmedServiceRequest_reportEventActionStatus), 56)) return;
                        else free();
                        break;
                    }
                    case 57:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventEnrollment_Request > (true, ConfirmedServiceRequest_defineEventEnrollment), 57)) return;
                        else free();
                        break;
                    }
                    case 58:
                    {
                        if (ITU_T_CHOICE_TAG(value<DeleteEventEnrollment_Request > (true, ConfirmedServiceRequest_deleteEventEnrollment), 58)) return;
                        else free();
                        break;
                    }
                    case 59:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterEventEnrollment_Request > (true, ConfirmedServiceRequest_alterEventEnrollment), 59)) return;
                        else free();
                        break;
                    }
                    case 60:
                    {
                        if (ITU_T_CHOICE_TAG(value<ReportEventEnrollmentStatus_Request > (true, ConfirmedServiceRequest_reportEventEnrollmentStatus), 60)) return;
                        else free();
                        break;
                    }
                    case 61:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Request > (true, ConfirmedServiceRequest_getEventEnrollmentAttributes), 61)) return;
                        else free();
                        break;
                    }
                    case 62:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AcknowledgeEventNotification_Request > (true, ConfirmedServiceRequest_acknowledgeEventNotification), 62)) return;
                        else free();
                        break;
                    }
                    case 63:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetAlarmSummary_Request > (true, ConfirmedServiceRequest_getAlarmSummary), 63)) return;
                        else free();
                        break;
                    }
                    case 64:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Request > (true, ConfirmedServiceRequest_getAlarmEnrollmentSummary), 64)) return;
                        else free();
                        break;
                    }
                    case 65:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReadJournal_Request > (true, ConfirmedServiceRequest_readJournal), 65)) return;
                        else free();
                        break;
                    }
                    case 66:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<WriteJournal_Request > (true, ConfirmedServiceRequest_writeJournal), 66)) return;
                        else free();
                        break;
                    }
                    case 67:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitializeJournal_Request > (true, ConfirmedServiceRequest_initializeJournal), 67)) return;
                        else free();
                        break;
                    }
                    case 68:
                    {
                        if (ITU_T_CHOICE_TAG(value<ReportJournalStatus_Request > (true, ConfirmedServiceRequest_reportJournalStatus), 68)) return;
                        else free();
                        break;
                    }
                    case 69:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CreateJournal_Request > (true, ConfirmedServiceRequest_createJournal), 69)) return;
                        else free();
                        break;
                    }
                    case 70:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteJournal_Request > (true, ConfirmedServiceRequest_deleteJournal), 70)) return;
                        else free();
                        break;
                    }
                    case 71:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetCapabilityList_Request > (true, ConfirmedServiceRequest_getCapabilityList), 71)) return;
                        else free();
                        break;
                    }
                    case 72:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Request > (true, ConfirmedServiceRequest_fileOpen), 72)) return;
                        else free();
                        break;
                    }
                    case 73:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Request > (true, ConfirmedServiceRequest_fileRead), 73)) return;
                        else free();
                        break;
                    }
                    case 74:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Request > (true, ConfirmedServiceRequest_fileClose), 74)) return;
                        else free();
                        break;
                    }
                    case 75:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Request > (true, ConfirmedServiceRequest_fileRename), 75)) return;
                        else free();
                        break;
                    }
                    case 76:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Request > (true, ConfirmedServiceRequest_fileDelete), 76)) return;
                        else free();
                        break;
                    }
                    case 77:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Request > (true, ConfirmedServiceRequest_fileDirectory), 77)) return;
                        else free();
                        break;
                    }
                    case 78:
                    {
                        if (ITU_T_CHOICE_TAG(value<AdditionalService_Request > (true, ConfirmedServiceRequest_additionalService), 78)) return;
                        else free();
                        break;
                    }
                    case 80:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetDataExchangeAttributes_Request > (true, ConfirmedServiceRequest_getDataExchangeAttributes), 80)) return;
                        else free();
                        break;
                    }
                    case 81:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ExchangeData_Request > (true, ConfirmedServiceRequest_exchangeData), 81)) return;
                        else free();
                        break;
                    }
                    case 82:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineAccessControlList_Request > (true, ConfirmedServiceRequest_defineAccessControlList), 82)) return;
                        else free();
                        break;
                    }
                    case 83:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetAccessControlListAttributes_Request > (true, ConfirmedServiceRequest_getAccessControlListAttributes), 83)) return;
                        else free();
                        break;
                    }
                    case 84:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportAccessControlledObjects_Request > (true, ConfirmedServiceRequest_reportAccessControlledObjects), 84)) return;
                        else free();
                        break;
                    }
                    case 85:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteAccessControlList_Request > (true, ConfirmedServiceRequest_deleteAccessControlList), 85)) return;
                        else free();
                        break;
                    }
                    case 86:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ChangeAccessControl_Request > (true, ConfirmedServiceRequest_changeAccessControl), 86)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void AdditionalService_Request::vMDStop(const VMDStop_Request& vl) {
        set<VMDStop_Request>(new VMDStop_Request(vl), AdditionalService_Request_vMDStop);
    }

    void AdditionalService_Request::vMDReset(const VMDReset_Request& vl) {
        set<VMDReset_Request>(new VMDReset_Request(vl), AdditionalService_Request_vMDReset);
    }

    void AdditionalService_Request::initiateUCLoad(const InitiateUnitControlLoad_Request& vl) {
        set<InitiateUnitControlLoad_Request>(new InitiateUnitControlLoad_Request(vl), AdditionalService_Request_initiateUCLoad);
    }

    void AdditionalService_Request::uCLoad(const UnitControlLoadSegment_Request& vl) {
        set<UnitControlLoadSegment_Request>(new UnitControlLoadSegment_Request(vl), AdditionalService_Request_uCLoad);
    }

    void AdditionalService_Request::stopUC(const StopUnitControl_Request& vl) {
        set<StopUnitControl_Request>(new StopUnitControl_Request(vl), AdditionalService_Request_stopUC);
    }

    void AdditionalService_Request::getUCAttributes(const GetUnitControlAttributes_Request& vl) {
        set<GetUnitControlAttributes_Request>(new GetUnitControlAttributes_Request(vl), AdditionalService_Request_getUCAttributes);
    }

    void AdditionalService_Request::deleteUC(const DeleteUnitControl_Request& vl) {
        set<DeleteUnitControl_Request>(new DeleteUnitControl_Request(vl), AdditionalService_Request_deleteUC);
    }

    template<> void AdditionalService_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Request_vMDStop:
            {
                ITU_T_IMPLICIT_TAG(value<VMDStop_Request > (false, AdditionalService_Request_vMDStop), 0);
                break;
            }
            case AdditionalService_Request_vMDReset:
            {
                ITU_T_IMPLICIT_TAG(value<VMDReset_Request > (false, AdditionalService_Request_vMDReset), 1);
                break;
            }
            case AdditionalService_Request_select:
            {
                ITU_T_IMPLICIT_TAG(value<Select_Request > (false, AdditionalService_Request_select), 2);
                break;
            }
            case AdditionalService_Request_alterPI:
            {
                ITU_T_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Request > (false, AdditionalService_Request_alterPI), 3);
                break;
            }
            case AdditionalService_Request_initiateUCLoad:
            {
                ITU_T_IMPLICIT_TAG(value<InitiateUnitControlLoad_Request > (false, AdditionalService_Request_initiateUCLoad), 4);
                break;
            }
            case AdditionalService_Request_uCLoad:
            {
                ITU_T_IMPLICIT_TAG(value<UnitControlLoadSegment_Request > (false, AdditionalService_Request_uCLoad), 5);
                break;
            }
            case AdditionalService_Request_uCUpload:
            {
                ITU_T_IMPLICIT_TAG(value<UnitControlUpload_Request > (false, AdditionalService_Request_uCUpload), 6);
                break;
            }
            case AdditionalService_Request_startUC:
            {
                ITU_T_IMPLICIT_TAG(value<StartUnitControl_Request > (false, AdditionalService_Request_startUC), 7);
                break;
            }
            case AdditionalService_Request_stopUC:
            {
                ITU_T_IMPLICIT_TAG(value<StopUnitControl_Request > (false, AdditionalService_Request_stopUC), 8);
                break;
            }
            case AdditionalService_Request_createUC:
            {
                ITU_T_IMPLICIT_TAG(value<CreateUnitControl_Request > (false, AdditionalService_Request_createUC), 9);
                break;
            }
            case AdditionalService_Request_addToUC:
            {
                ITU_T_IMPLICIT_TAG(value<AddToUnitControl_Request > (false, AdditionalService_Request_addToUC), 10);
                break;
            }
            case AdditionalService_Request_removeFromUC:
            {
                ITU_T_IMPLICIT_TAG(value<RemoveFromUnitControl_Request > (false, AdditionalService_Request_removeFromUC), 11);
                break;
            }
            case AdditionalService_Request_getUCAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetUnitControlAttributes_Request > (false, AdditionalService_Request_getUCAttributes), 12);
                break;
            }
            case AdditionalService_Request_loadUCFromFile:
            {
                ITU_T_IMPLICIT_TAG(value<LoadUnitControlFromFile_Request > (false, AdditionalService_Request_loadUCFromFile), 13);
                break;
            }
            case AdditionalService_Request_storeUCToFile:
            {
                ITU_T_IMPLICIT_TAG(value<StoreUnitControlToFile_Request > (false, AdditionalService_Request_storeUCToFile), 14);
                break;
            }
            case AdditionalService_Request_deleteUC:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteUnitControl_Request > (false, AdditionalService_Request_deleteUC), 15);
                break;
            }
            case AdditionalService_Request_defineECL:
            {
                ITU_T_EXPLICIT_TAG(value<DefineEventConditionList_Request > (false, AdditionalService_Request_defineECL), 16);
                break;
            }
            case AdditionalService_Request_deleteECL:
            {
                ITU_T_CHOICE_TAG(value<DeleteEventConditionList_Request > (false, AdditionalService_Request_deleteECL), 17);
                break;
            }
            case AdditionalService_Request_addECLReference:
            {
                ITU_T_IMPLICIT_TAG(value<AddEventConditionListReference_Request > (false, AdditionalService_Request_addECLReference), 18);
                break;
            }
            case AdditionalService_Request_removeECLReference:
            {
                ITU_T_IMPLICIT_TAG(value<RemoveEventConditionListReference_Request > (false, AdditionalService_Request_removeECLReference), 19);
                break;
            }
            case AdditionalService_Request_getECLAttributes:
            {
                ITU_T_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (false, AdditionalService_Request_getECLAttributes), 20);
                break;
            }
            case AdditionalService_Request_reportECLStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportEventConditionListStatus_Request > (false, AdditionalService_Request_reportECLStatus), 21);
                break;
            }
            case AdditionalService_Request_alterECLMonitoring:
            {
                ITU_T_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Request > (false, AdditionalService_Request_alterECLMonitoring), 22);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<VMDStop_Request > (true, AdditionalService_Request_vMDStop), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<VMDReset_Request > (true, AdditionalService_Request_vMDReset), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Select_Request > (true, AdditionalService_Request_select), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Request > (true, AdditionalService_Request_alterPI), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitiateUnitControlLoad_Request > (true, AdditionalService_Request_initiateUCLoad), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UnitControlLoadSegment_Request > (true, AdditionalService_Request_uCLoad), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UnitControlUpload_Request > (true, AdditionalService_Request_uCUpload), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StartUnitControl_Request > (true, AdditionalService_Request_startUC), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StopUnitControl_Request > (true, AdditionalService_Request_stopUC), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CreateUnitControl_Request > (true, AdditionalService_Request_createUC), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AddToUnitControl_Request > (true, AdditionalService_Request_addToUC), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RemoveFromUnitControl_Request > (true, AdditionalService_Request_removeFromUC), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetUnitControlAttributes_Request > (true, AdditionalService_Request_getUCAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<LoadUnitControlFromFile_Request > (true, AdditionalService_Request_loadUCFromFile), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StoreUnitControlToFile_Request > (true, AdditionalService_Request_storeUCToFile), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteUnitControl_Request > (true, AdditionalService_Request_deleteUC), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<DefineEventConditionList_Request > (true, AdditionalService_Request_defineECL), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_CHOICE_TAG(value<DeleteEventConditionList_Request > (true, AdditionalService_Request_deleteECL), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AddEventConditionListReference_Request > (true, AdditionalService_Request_addECLReference), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RemoveEventConditionListReference_Request > (true, AdditionalService_Request_removeECLReference), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_CHOICE_TAG(value<GetEventConditionListAttributes_Request > (true, AdditionalService_Request_getECLAttributes), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportEventConditionListStatus_Request > (true, AdditionalService_Request_reportECLStatus), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Request > (true, AdditionalService_Request_alterECLMonitoring), 22)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void Request_Detail::otherRequests(const null_type& vl) {
        set<null_type>(new null_type(vl), Request_Detail_otherRequests);
    }

    void Request_Detail::createProgramInvocation(const CS_CreateProgramInvocation_Request& vl) {
        set<CS_CreateProgramInvocation_Request>(new CS_CreateProgramInvocation_Request(vl), Request_Detail_createProgramInvocation);
    }

    template<> void Request_Detail::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Request_Detail_otherRequests:
            {
                ITU_T_BIND_TAG(value<null_type > (false, Request_Detail_otherRequests));
                break;
            }
            case Request_Detail_createProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<CS_CreateProgramInvocation_Request > (false, Request_Detail_createProgramInvocation), 38);
                break;
            }
            case Request_Detail_start:
            {
                ITU_T_IMPLICIT_TAG(value<CS_Start_Request > (false, Request_Detail_start), 40);
                break;
            }
            case Request_Detail_resume:
            {
                ITU_T_IMPLICIT_TAG(value<CS_Resume_Request > (false, Request_Detail_resume), 42);
                break;
            }
            case Request_Detail_defineEventCondition:
            {
                ITU_T_IMPLICIT_TAG(value<CS_DefineEventCondition_Request > (false, Request_Detail_defineEventCondition), 47);
                break;
            }
            case Request_Detail_alterEventConditionMonitoring:
            {
                ITU_T_IMPLICIT_TAG(value<CS_AlterEventConditionMonitoring_Request > (false, Request_Detail_alterEventConditionMonitoring), 51);
                break;
            }
            case Request_Detail_defineEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<CS_DefineEventEnrollment_Request > (false, Request_Detail_defineEventEnrollment), 57);
                break;
            }
            case Request_Detail_alterEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<CS_AlterEventEnrollment_Request > (false, Request_Detail_alterEventEnrollment), 59);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 38:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_CreateProgramInvocation_Request > (true, Request_Detail_createProgramInvocation), 38)) return;
                        else free();
                        break;
                    }
                    case 40:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_Start_Request > (true, Request_Detail_start), 40)) return;
                        else free();
                        break;
                    }
                    case 42:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_Resume_Request > (true, Request_Detail_resume), 42)) return;
                        else free();
                        break;
                    }
                    case 47:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_DefineEventCondition_Request > (true, Request_Detail_defineEventCondition), 47)) return;
                        else free();
                        break;
                    }
                    case 51:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_AlterEventConditionMonitoring_Request > (true, Request_Detail_alterEventConditionMonitoring), 51)) return;
                        else free();
                        break;
                    }
                    case 57:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_DefineEventEnrollment_Request > (true, Request_Detail_defineEventEnrollment), 57)) return;
                        else free();
                        break;
                    }
                    case 59:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_AlterEventEnrollment_Request > (true, Request_Detail_alterEventEnrollment), 59)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, Request_Detail_otherRequests))) return;
                else free();
            }
        }
    }


    // sequence Unconfirmed-PDU

    Unconfirmed_PDU::Unconfirmed_PDU() : service_() {
    };

    Unconfirmed_PDU::Unconfirmed_PDU(const UnconfirmedService& arg__service) :
    service_(arg__service) {
    };

    Unconfirmed_PDU::Unconfirmed_PDU(boost::shared_ptr< UnconfirmedService> arg__service,
            boost::shared_ptr< Unconfirmed_Detail> arg__service_ext) :
    service_(arg__service),
    service_ext_(arg__service_ext) {
    };

    template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    template<> void Unconfirmed_PDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    UnconfirmedService& Unconfirmed_PDU::service() {
        return *service_;
    }

    const UnconfirmedService& Unconfirmed_PDU::service() const {
        return *service_;
    }

    void Unconfirmed_PDU::service(const UnconfirmedService& vl) {
        service_ = vl;
    }

    void Unconfirmed_PDU::service(boost::shared_ptr< UnconfirmedService> vl) {
        service_ = vl;
    }

    boost::shared_ptr<Unconfirmed_Detail> Unconfirmed_PDU::service_ext__new() {
        return service_ext_ = boost::shared_ptr<Unconfirmed_Detail>(new Unconfirmed_Detail());
    }

    void Unconfirmed_PDU::service_ext(const Unconfirmed_Detail& vl) {
        service_ext_ = boost::shared_ptr<Unconfirmed_Detail>(new Unconfirmed_Detail(vl));
    }


    // choice UnconfirmedService

    template<> void UnconfirmedService::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case UnconfirmedService_informationReport:
            {
                ITU_T_IMPLICIT_TAG(value<InformationReport > (false, UnconfirmedService_informationReport), 0);
                break;
            }
            case UnconfirmedService_unsolicitedStatus:
            {
                ITU_T_IMPLICIT_TAG(value<UnsolicitedStatus > (false, UnconfirmedService_unsolicitedStatus), 1);
                break;
            }
            case UnconfirmedService_eventNotification:
            {
                ITU_T_IMPLICIT_TAG(value<EventNotification > (false, UnconfirmedService_eventNotification), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InformationReport > (true, UnconfirmedService_informationReport), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UnsolicitedStatus > (true, UnconfirmedService_unsolicitedStatus), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<EventNotification > (true, UnconfirmedService_eventNotification), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void Unconfirmed_Detail::otherRequests(const null_type& vl) {
        set<null_type>(new null_type(vl), Unconfirmed_Detail_otherRequests);
    }

    template<> void Unconfirmed_Detail::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Unconfirmed_Detail_otherRequests:
            {
                ITU_T_BIND_TAG(value<null_type > (false, Unconfirmed_Detail_otherRequests));
                break;
            }
            case Unconfirmed_Detail_eventNotification:
            {
                ITU_T_IMPLICIT_TAG(value<CS_EventNotification > (false, Unconfirmed_Detail_eventNotification), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_EventNotification > (true, Unconfirmed_Detail_eventNotification), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, Unconfirmed_Detail_otherRequests))) return;
                else free();
            }
        }
    }


    // sequence Confirmed-ResponsePDU

    Confirmed_ResponsePDU::Confirmed_ResponsePDU() : invokeID_(), service_() {
    };

    Confirmed_ResponsePDU::Confirmed_ResponsePDU(const Unsigned32& arg__invokeID,
            const ConfirmedServiceResponse& arg__service) :
    invokeID_(arg__invokeID),
    service_(arg__service) {
    };

    Confirmed_ResponsePDU::Confirmed_ResponsePDU(boost::shared_ptr< Unsigned32> arg__invokeID,
            boost::shared_ptr< ConfirmedServiceResponse> arg__service,
            boost::shared_ptr< Response_Detail> arg__service_ext) :
    invokeID_(arg__invokeID),
    service_(arg__service),
    service_ext_(arg__service_ext) {
    };

    template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(invokeID_);
        ITU_T_BIND_CHOICE(service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    template<> void Confirmed_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(invokeID_);
        ITU_T_BIND_CHOICE(service_);
        ITU_T_EXTENTION;
        ITU_T_CHOICE_TAG(service_ext_, 79);
    }

    Unsigned32& Confirmed_ResponsePDU::invokeID() {
        return *invokeID_;
    }

    const Unsigned32& Confirmed_ResponsePDU::invokeID() const {
        return *invokeID_;
    }

    void Confirmed_ResponsePDU::invokeID(const Unsigned32& vl) {
        invokeID_ = vl;
    }

    void Confirmed_ResponsePDU::invokeID(boost::shared_ptr< Unsigned32> vl) {
        invokeID_ = vl;
    }

    ConfirmedServiceResponse& Confirmed_ResponsePDU::service() {
        return *service_;
    }

    const ConfirmedServiceResponse& Confirmed_ResponsePDU::service() const {
        return *service_;
    }

    void Confirmed_ResponsePDU::service(const ConfirmedServiceResponse& vl) {
        service_ = vl;
    }

    void Confirmed_ResponsePDU::service(boost::shared_ptr< ConfirmedServiceResponse> vl) {
        service_ = vl;
    }

    boost::shared_ptr<Response_Detail> Confirmed_ResponsePDU::service_ext__new() {
        return service_ext_ = boost::shared_ptr<Response_Detail>(new Response_Detail());
    }

    void Confirmed_ResponsePDU::service_ext(const Response_Detail& vl) {
        service_ext_ = boost::shared_ptr<Response_Detail>(new Response_Detail(vl));
    }


    // choice ConfirmedServiceResponse

    void ConfirmedServiceResponse::rename(const Rename_Response& vl) {
        set<Rename_Response>(new Rename_Response(vl), ConfirmedServiceResponse_rename);
    }

    void ConfirmedServiceResponse::defineNamedVariable(const DefineNamedVariable_Response& vl) {
        set<DefineNamedVariable_Response>(new DefineNamedVariable_Response(vl), ConfirmedServiceResponse_defineNamedVariable);
    }

    void ConfirmedServiceResponse::defineScatteredAccess(const ISO_9506_MMS_1A::DefineScatteredAccess_Response& vl) {
        set<ISO_9506_MMS_1A::DefineScatteredAccess_Response>(new ISO_9506_MMS_1A::DefineScatteredAccess_Response(vl), ConfirmedServiceResponse_defineScatteredAccess);
    }

    void ConfirmedServiceResponse::defineNamedVariableList(const DefineNamedVariableList_Response& vl) {
        set<DefineNamedVariableList_Response>(new DefineNamedVariableList_Response(vl), ConfirmedServiceResponse_defineNamedVariableList);
    }

    void ConfirmedServiceResponse::defineNamedType(const DefineNamedType_Response& vl) {
        set<DefineNamedType_Response>(new DefineNamedType_Response(vl), ConfirmedServiceResponse_defineNamedType);
    }

    void ConfirmedServiceResponse::input(const Input_Response& vl) {
        set<Input_Response>(new Input_Response(vl), ConfirmedServiceResponse_input);
    }

    void ConfirmedServiceResponse::output(const Output_Response& vl) {
        set<Output_Response>(new Output_Response(vl), ConfirmedServiceResponse_output);
    }

    void ConfirmedServiceResponse::relinquishControl(const RelinquishControl_Response& vl) {
        set<RelinquishControl_Response>(new RelinquishControl_Response(vl), ConfirmedServiceResponse_relinquishControl);
    }

    void ConfirmedServiceResponse::defineSemaphore(const DefineSemaphore_Response& vl) {
        set<DefineSemaphore_Response>(new DefineSemaphore_Response(vl), ConfirmedServiceResponse_defineSemaphore);
    }

    void ConfirmedServiceResponse::deleteSemaphore(const DeleteSemaphore_Response& vl) {
        set<DeleteSemaphore_Response>(new DeleteSemaphore_Response(vl), ConfirmedServiceResponse_deleteSemaphore);
    }

    void ConfirmedServiceResponse::initiateDownloadSequence(const InitiateDownloadSequence_Response& vl) {
        set<InitiateDownloadSequence_Response>(new InitiateDownloadSequence_Response(vl), ConfirmedServiceResponse_initiateDownloadSequence);
    }

    void ConfirmedServiceResponse::terminateDownloadSequence(const TerminateDownloadSequence_Response& vl) {
        set<TerminateDownloadSequence_Response>(new TerminateDownloadSequence_Response(vl), ConfirmedServiceResponse_terminateDownloadSequence);
    }

    void ConfirmedServiceResponse::terminateUploadSequence(const TerminateUploadSequence_Response& vl) {
        set<TerminateUploadSequence_Response>(new TerminateUploadSequence_Response(vl), ConfirmedServiceResponse_terminateUploadSequence);
    }

    void ConfirmedServiceResponse::requestDomainDownload(const RequestDomainDownload_Response& vl) {
        set<RequestDomainDownload_Response>(new RequestDomainDownload_Response(vl), ConfirmedServiceResponse_requestDomainDownload);
    }

    void ConfirmedServiceResponse::requestDomainUpload(const RequestDomainUpload_Response& vl) {
        set<RequestDomainUpload_Response>(new RequestDomainUpload_Response(vl), ConfirmedServiceResponse_requestDomainUpload);
    }

    void ConfirmedServiceResponse::loadDomainContent(const LoadDomainContent_Response& vl) {
        set<LoadDomainContent_Response>(new LoadDomainContent_Response(vl), ConfirmedServiceResponse_loadDomainContent);
    }

    void ConfirmedServiceResponse::storeDomainContent(const StoreDomainContent_Response& vl) {
        set<StoreDomainContent_Response>(new StoreDomainContent_Response(vl), ConfirmedServiceResponse_storeDomainContent);
    }

    void ConfirmedServiceResponse::deleteDomain(const DeleteDomain_Response& vl) {
        set<DeleteDomain_Response>(new DeleteDomain_Response(vl), ConfirmedServiceResponse_deleteDomain);
    }

    void ConfirmedServiceResponse::createProgramInvocation(const CreateProgramInvocation_Response& vl) {
        set<CreateProgramInvocation_Response>(new CreateProgramInvocation_Response(vl), ConfirmedServiceResponse_createProgramInvocation);
    }

    void ConfirmedServiceResponse::deleteProgramInvocation(const DeleteProgramInvocation_Response& vl) {
        set<DeleteProgramInvocation_Response>(new DeleteProgramInvocation_Response(vl), ConfirmedServiceResponse_deleteProgramInvocation);
    }

    void ConfirmedServiceResponse::start(const Start_Response& vl) {
        set<Start_Response>(new Start_Response(vl), ConfirmedServiceResponse_start);
    }

    void ConfirmedServiceResponse::stop(const Stop_Response& vl) {
        set<Stop_Response>(new Stop_Response(vl), ConfirmedServiceResponse_stop);
    }

    void ConfirmedServiceResponse::resume(const Resume_Response& vl) {
        set<Resume_Response>(new Resume_Response(vl), ConfirmedServiceResponse_resume);
    }

    void ConfirmedServiceResponse::reset(const Reset_Response& vl) {
        set<Reset_Response>(new Reset_Response(vl), ConfirmedServiceResponse_reset);
    }

    void ConfirmedServiceResponse::kill(const Kill_Response& vl) {
        set<Kill_Response>(new Kill_Response(vl), ConfirmedServiceResponse_kill);
    }

    void ConfirmedServiceResponse::obtainFile(const ISO_9506_MMS_1A::ObtainFile_Response& vl) {
        set<ISO_9506_MMS_1A::ObtainFile_Response>(new ISO_9506_MMS_1A::ObtainFile_Response(vl), ConfirmedServiceResponse_obtainFile);
    }

    void ConfirmedServiceResponse::defineEventCondition(const DefineEventCondition_Response& vl) {
        set<DefineEventCondition_Response>(new DefineEventCondition_Response(vl), ConfirmedServiceResponse_defineEventCondition);
    }

    void ConfirmedServiceResponse::deleteEventCondition(const DeleteEventCondition_Response& vl) {
        set<DeleteEventCondition_Response>(new DeleteEventCondition_Response(vl), ConfirmedServiceResponse_deleteEventCondition);
    }

    void ConfirmedServiceResponse::alterEventConditionMonitoring(const AlterEventConditionMonitoring_Response& vl) {
        set<AlterEventConditionMonitoring_Response>(new AlterEventConditionMonitoring_Response(vl), ConfirmedServiceResponse_alterEventConditionMonitoring);
    }

    void ConfirmedServiceResponse::triggerEvent(const TriggerEvent_Response& vl) {
        set<TriggerEvent_Response>(new TriggerEvent_Response(vl), ConfirmedServiceResponse_triggerEvent);
    }

    void ConfirmedServiceResponse::defineEventAction(const DefineEventAction_Response& vl) {
        set<DefineEventAction_Response>(new DefineEventAction_Response(vl), ConfirmedServiceResponse_defineEventAction);
    }

    void ConfirmedServiceResponse::deleteEventAction(const DeleteEventAction_Response& vl) {
        set<DeleteEventAction_Response>(new DeleteEventAction_Response(vl), ConfirmedServiceResponse_deleteEventAction);
    }

    void ConfirmedServiceResponse::reportEventActionStatus(const ReportEventActionStatus_Response& vl) {
        set<ReportEventActionStatus_Response>(new ReportEventActionStatus_Response(vl), ConfirmedServiceResponse_reportEventActionStatus);
    }

    void ConfirmedServiceResponse::defineEventEnrollment(const DefineEventEnrollment_Response& vl) {
        set<DefineEventEnrollment_Response>(new DefineEventEnrollment_Response(vl), ConfirmedServiceResponse_defineEventEnrollment);
    }

    void ConfirmedServiceResponse::deleteEventEnrollment(const DeleteEventEnrollment_Response& vl) {
        set<DeleteEventEnrollment_Response>(new DeleteEventEnrollment_Response(vl), ConfirmedServiceResponse_deleteEventEnrollment);
    }

    void ConfirmedServiceResponse::acknowledgeEventNotification(const AcknowledgeEventNotification_Response& vl) {
        set<AcknowledgeEventNotification_Response>(new AcknowledgeEventNotification_Response(vl), ConfirmedServiceResponse_acknowledgeEventNotification);
    }

    void ConfirmedServiceResponse::writeJournal(const WriteJournal_Response& vl) {
        set<WriteJournal_Response>(new WriteJournal_Response(vl), ConfirmedServiceResponse_writeJournal);
    }

    void ConfirmedServiceResponse::initializeJournal(const InitializeJournal_Response& vl) {
        set<InitializeJournal_Response>(new InitializeJournal_Response(vl), ConfirmedServiceResponse_initializeJournal);
    }

    void ConfirmedServiceResponse::createJournal(const CreateJournal_Response& vl) {
        set<CreateJournal_Response>(new CreateJournal_Response(vl), ConfirmedServiceResponse_createJournal);
    }

    void ConfirmedServiceResponse::deleteJournal(const DeleteJournal_Response& vl) {
        set<DeleteJournal_Response>(new DeleteJournal_Response(vl), ConfirmedServiceResponse_deleteJournal);
    }

    void ConfirmedServiceResponse::fileClose(const ISO_9506_MMS_1A::FileClose_Response& vl) {
        set<ISO_9506_MMS_1A::FileClose_Response>(new ISO_9506_MMS_1A::FileClose_Response(vl), ConfirmedServiceResponse_fileClose);
    }

    void ConfirmedServiceResponse::fileRename(const ISO_9506_MMS_1A::FileRename_Response& vl) {
        set<ISO_9506_MMS_1A::FileRename_Response>(new ISO_9506_MMS_1A::FileRename_Response(vl), ConfirmedServiceResponse_fileRename);
    }

    void ConfirmedServiceResponse::fileDelete(const ISO_9506_MMS_1A::FileDelete_Response& vl) {
        set<ISO_9506_MMS_1A::FileDelete_Response>(new ISO_9506_MMS_1A::FileDelete_Response(vl), ConfirmedServiceResponse_fileDelete);
    }

    void ConfirmedServiceResponse::defineAccessControlList(const DefineAccessControlList_Response& vl) {
        set<DefineAccessControlList_Response>(new DefineAccessControlList_Response(vl), ConfirmedServiceResponse_defineAccessControlList);
    }

    void ConfirmedServiceResponse::deleteAccessControlList(const DeleteAccessControlList_Response& vl) {
        set<DeleteAccessControlList_Response>(new DeleteAccessControlList_Response(vl), ConfirmedServiceResponse_deleteAccessControlList);
    }

    template<> void ConfirmedServiceResponse::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ConfirmedServiceResponse_status:
            {
                ITU_T_IMPLICIT_TAG(value<Status_Response > (false, ConfirmedServiceResponse_status), 0);
                break;
            }
            case ConfirmedServiceResponse_getNameList:
            {
                ITU_T_IMPLICIT_TAG(value<GetNameList_Response > (false, ConfirmedServiceResponse_getNameList), 1);
                break;
            }
            case ConfirmedServiceResponse_identify:
            {
                ITU_T_IMPLICIT_TAG(value<Identify_Response > (false, ConfirmedServiceResponse_identify), 2);
                break;
            }
            case ConfirmedServiceResponse_rename:
            {
                ITU_T_IMPLICIT_TAG(value<Rename_Response > (false, ConfirmedServiceResponse_rename), 3);
                break;
            }
            case ConfirmedServiceResponse_read:
            {
                ITU_T_IMPLICIT_TAG(value<Read_Response > (false, ConfirmedServiceResponse_read), 4);
                break;
            }
            case ConfirmedServiceResponse_getVariableAccessAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetVariableAccessAttributes_Response > (false, ConfirmedServiceResponse_getVariableAccessAttributes), 6);
                break;
            }
            case ConfirmedServiceResponse_defineNamedVariable:
            {
                ITU_T_IMPLICIT_TAG(value<DefineNamedVariable_Response > (false, ConfirmedServiceResponse_defineNamedVariable), 7);
                break;
            }
            case ConfirmedServiceResponse_defineScatteredAccess:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (false, ConfirmedServiceResponse_defineScatteredAccess), 8);
                break;
            }
            case ConfirmedServiceResponse_getScatteredAccessAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (false, ConfirmedServiceResponse_getScatteredAccessAttributes), 9);
                break;
            }
            case ConfirmedServiceResponse_deleteVariableAccess:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteVariableAccess_Response > (false, ConfirmedServiceResponse_deleteVariableAccess), 10);
                break;
            }
            case ConfirmedServiceResponse_defineNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(value<DefineNamedVariableList_Response > (false, ConfirmedServiceResponse_defineNamedVariableList), 11);
                break;
            }
            case ConfirmedServiceResponse_getNamedVariableListAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetNamedVariableListAttributes_Response > (false, ConfirmedServiceResponse_getNamedVariableListAttributes), 12);
                break;
            }
            case ConfirmedServiceResponse_deleteNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteNamedVariableList_Response > (false, ConfirmedServiceResponse_deleteNamedVariableList), 13);
                break;
            }
            case ConfirmedServiceResponse_defineNamedType:
            {
                ITU_T_IMPLICIT_TAG(value<DefineNamedType_Response > (false, ConfirmedServiceResponse_defineNamedType), 14);
                break;
            }
            case ConfirmedServiceResponse_getNamedTypeAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetNamedTypeAttributes_Response > (false, ConfirmedServiceResponse_getNamedTypeAttributes), 15);
                break;
            }
            case ConfirmedServiceResponse_deleteNamedType:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteNamedType_Response > (false, ConfirmedServiceResponse_deleteNamedType), 16);
                break;
            }
            case ConfirmedServiceResponse_input:
            {
                ITU_T_IMPLICIT_TAG(value<Input_Response > (false, ConfirmedServiceResponse_input), 17);
                break;
            }
            case ConfirmedServiceResponse_output:
            {
                ITU_T_IMPLICIT_TAG(value<Output_Response > (false, ConfirmedServiceResponse_output), 18);
                break;
            }
            case ConfirmedServiceResponse_takeControl:
            {
                ITU_T_CHOICE_TAG(value<TakeControl_Response > (false, ConfirmedServiceResponse_takeControl), 19);
                break;
            }
            case ConfirmedServiceResponse_relinquishControl:
            {
                ITU_T_IMPLICIT_TAG(value<RelinquishControl_Response > (false, ConfirmedServiceResponse_relinquishControl), 20);
                break;
            }
            case ConfirmedServiceResponse_defineSemaphore:
            {
                ITU_T_IMPLICIT_TAG(value<DefineSemaphore_Response > (false, ConfirmedServiceResponse_defineSemaphore), 21);
                break;
            }
            case ConfirmedServiceResponse_deleteSemaphore:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteSemaphore_Response > (false, ConfirmedServiceResponse_deleteSemaphore), 22);
                break;
            }
            case ConfirmedServiceResponse_reportSemaphoreStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportSemaphoreStatus_Response > (false, ConfirmedServiceResponse_reportSemaphoreStatus), 23);
                break;
            }
            case ConfirmedServiceResponse_reportPoolSemaphoreStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Response > (false, ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24);
                break;
            }
            case ConfirmedServiceResponse_reportSemaphoreEntryStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Response > (false, ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25);
                break;
            }
            case ConfirmedServiceResponse_initiateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<InitiateDownloadSequence_Response > (false, ConfirmedServiceResponse_initiateDownloadSequence), 26);
                break;
            }
            case ConfirmedServiceResponse_downloadSegment:
            {
                ITU_T_IMPLICIT_TAG(value<DownloadSegment_Response > (false, ConfirmedServiceResponse_downloadSegment), 27);
                break;
            }
            case ConfirmedServiceResponse_terminateDownloadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<TerminateDownloadSequence_Response > (false, ConfirmedServiceResponse_terminateDownloadSequence), 28);
                break;
            }
            case ConfirmedServiceResponse_initiateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<InitiateUploadSequence_Response > (false, ConfirmedServiceResponse_initiateUploadSequence), 29);
                break;
            }
            case ConfirmedServiceResponse_uploadSegment:
            {
                ITU_T_IMPLICIT_TAG(value<UploadSegment_Response > (false, ConfirmedServiceResponse_uploadSegment), 30);
                break;
            }
            case ConfirmedServiceResponse_terminateUploadSequence:
            {
                ITU_T_IMPLICIT_TAG(value<TerminateUploadSequence_Response > (false, ConfirmedServiceResponse_terminateUploadSequence), 31);
                break;
            }
            case ConfirmedServiceResponse_requestDomainDownload:
            {
                ITU_T_IMPLICIT_TAG(value<RequestDomainDownload_Response > (false, ConfirmedServiceResponse_requestDomainDownload), 32);
                break;
            }
            case ConfirmedServiceResponse_requestDomainUpload:
            {
                ITU_T_IMPLICIT_TAG(value<RequestDomainUpload_Response > (false, ConfirmedServiceResponse_requestDomainUpload), 33);
                break;
            }
            case ConfirmedServiceResponse_loadDomainContent:
            {
                ITU_T_IMPLICIT_TAG(value<LoadDomainContent_Response > (false, ConfirmedServiceResponse_loadDomainContent), 34);
                break;
            }
            case ConfirmedServiceResponse_storeDomainContent:
            {
                ITU_T_IMPLICIT_TAG(value<StoreDomainContent_Response > (false, ConfirmedServiceResponse_storeDomainContent), 35);
                break;
            }
            case ConfirmedServiceResponse_deleteDomain:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteDomain_Response > (false, ConfirmedServiceResponse_deleteDomain), 36);
                break;
            }
            case ConfirmedServiceResponse_getDomainAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetDomainAttributes_Response > (false, ConfirmedServiceResponse_getDomainAttributes), 37);
                break;
            }
            case ConfirmedServiceResponse_createProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<CreateProgramInvocation_Response > (false, ConfirmedServiceResponse_createProgramInvocation), 38);
                break;
            }
            case ConfirmedServiceResponse_deleteProgramInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteProgramInvocation_Response > (false, ConfirmedServiceResponse_deleteProgramInvocation), 39);
                break;
            }
            case ConfirmedServiceResponse_start:
            {
                ITU_T_IMPLICIT_TAG(value<Start_Response > (false, ConfirmedServiceResponse_start), 40);
                break;
            }
            case ConfirmedServiceResponse_stop:
            {
                ITU_T_IMPLICIT_TAG(value<Stop_Response > (false, ConfirmedServiceResponse_stop), 41);
                break;
            }
            case ConfirmedServiceResponse_resume:
            {
                ITU_T_IMPLICIT_TAG(value<Resume_Response > (false, ConfirmedServiceResponse_resume), 42);
                break;
            }
            case ConfirmedServiceResponse_reset:
            {
                ITU_T_IMPLICIT_TAG(value<Reset_Response > (false, ConfirmedServiceResponse_reset), 43);
                break;
            }
            case ConfirmedServiceResponse_kill:
            {
                ITU_T_IMPLICIT_TAG(value<Kill_Response > (false, ConfirmedServiceResponse_kill), 44);
                break;
            }
            case ConfirmedServiceResponse_getProgramInvocationAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Response > (false, ConfirmedServiceResponse_getProgramInvocationAttributes), 45);
                break;
            }
            case ConfirmedServiceResponse_obtainFile:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Response > (false, ConfirmedServiceResponse_obtainFile), 46);
                break;
            }
            case ConfirmedServiceResponse_defineEventCondition:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventCondition_Response > (false, ConfirmedServiceResponse_defineEventCondition), 47);
                break;
            }
            case ConfirmedServiceResponse_deleteEventCondition:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteEventCondition_Response > (false, ConfirmedServiceResponse_deleteEventCondition), 48);
                break;
            }
            case ConfirmedServiceResponse_getEventConditionAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetEventConditionAttributes_Response > (false, ConfirmedServiceResponse_getEventConditionAttributes), 49);
                break;
            }
            case ConfirmedServiceResponse_reportEventConditionStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportEventConditionStatus_Response > (false, ConfirmedServiceResponse_reportEventConditionStatus), 50);
                break;
            }
            case ConfirmedServiceResponse_alterEventConditionMonitoring:
            {
                ITU_T_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Response > (false, ConfirmedServiceResponse_alterEventConditionMonitoring), 51);
                break;
            }
            case ConfirmedServiceResponse_triggerEvent:
            {
                ITU_T_IMPLICIT_TAG(value<TriggerEvent_Response > (false, ConfirmedServiceResponse_triggerEvent), 52);
                break;
            }
            case ConfirmedServiceResponse_defineEventAction:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventAction_Response > (false, ConfirmedServiceResponse_defineEventAction), 53);
                break;
            }
            case ConfirmedServiceResponse_deleteEventAction:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteEventAction_Response > (false, ConfirmedServiceResponse_deleteEventAction), 54);
                break;
            }
            case ConfirmedServiceResponse_getEventActionAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetEventActionAttributes_Response > (false, ConfirmedServiceResponse_getEventActionAttributes), 55);
                break;
            }
            case ConfirmedServiceResponse_reportEventActionStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportEventActionStatus_Response > (false, ConfirmedServiceResponse_reportEventActionStatus), 56);
                break;
            }
            case ConfirmedServiceResponse_defineEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventEnrollment_Response > (false, ConfirmedServiceResponse_defineEventEnrollment), 57);
                break;
            }
            case ConfirmedServiceResponse_deleteEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteEventEnrollment_Response > (false, ConfirmedServiceResponse_deleteEventEnrollment), 58);
                break;
            }
            case ConfirmedServiceResponse_alterEventEnrollment:
            {
                ITU_T_IMPLICIT_TAG(value<AlterEventEnrollment_Response > (false, ConfirmedServiceResponse_alterEventEnrollment), 59);
                break;
            }
            case ConfirmedServiceResponse_reportEventEnrollmentStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportEventEnrollmentStatus_Response > (false, ConfirmedServiceResponse_reportEventEnrollmentStatus), 60);
                break;
            }
            case ConfirmedServiceResponse_getEventEnrollmentAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Response > (false, ConfirmedServiceResponse_getEventEnrollmentAttributes), 61);
                break;
            }
            case ConfirmedServiceResponse_acknowledgeEventNotification:
            {
                ITU_T_IMPLICIT_TAG(value<AcknowledgeEventNotification_Response > (false, ConfirmedServiceResponse_acknowledgeEventNotification), 62);
                break;
            }
            case ConfirmedServiceResponse_getAlarmSummary:
            {
                ITU_T_IMPLICIT_TAG(value<GetAlarmSummary_Response > (false, ConfirmedServiceResponse_getAlarmSummary), 63);
                break;
            }
            case ConfirmedServiceResponse_getAlarmEnrollmentSummary:
            {
                ITU_T_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Response > (false, ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64);
                break;
            }
            case ConfirmedServiceResponse_readJournal:
            {
                ITU_T_IMPLICIT_TAG(value<ReadJournal_Response > (false, ConfirmedServiceResponse_readJournal), 65);
                break;
            }
            case ConfirmedServiceResponse_writeJournal:
            {
                ITU_T_IMPLICIT_TAG(value<WriteJournal_Response > (false, ConfirmedServiceResponse_writeJournal), 66);
                break;
            }
            case ConfirmedServiceResponse_initializeJournal:
            {
                ITU_T_IMPLICIT_TAG(value<InitializeJournal_Response > (false, ConfirmedServiceResponse_initializeJournal), 67);
                break;
            }
            case ConfirmedServiceResponse_reportJournalStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportJournalStatus_Response > (false, ConfirmedServiceResponse_reportJournalStatus), 68);
                break;
            }
            case ConfirmedServiceResponse_createJournal:
            {
                ITU_T_IMPLICIT_TAG(value<CreateJournal_Response > (false, ConfirmedServiceResponse_createJournal), 69);
                break;
            }
            case ConfirmedServiceResponse_deleteJournal:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteJournal_Response > (false, ConfirmedServiceResponse_deleteJournal), 70);
                break;
            }
            case ConfirmedServiceResponse_getCapabilityList:
            {
                ITU_T_IMPLICIT_TAG(value<GetCapabilityList_Response > (false, ConfirmedServiceResponse_getCapabilityList), 71);
                break;
            }
            case ConfirmedServiceResponse_fileOpen:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Response > (false, ConfirmedServiceResponse_fileOpen), 72);
                break;
            }
            case ConfirmedServiceResponse_fileRead:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Response > (false, ConfirmedServiceResponse_fileRead), 73);
                break;
            }
            case ConfirmedServiceResponse_fileClose:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Response > (false, ConfirmedServiceResponse_fileClose), 74);
                break;
            }
            case ConfirmedServiceResponse_fileRename:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Response > (false, ConfirmedServiceResponse_fileRename), 75);
                break;
            }
            case ConfirmedServiceResponse_fileDelete:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Response > (false, ConfirmedServiceResponse_fileDelete), 76);
                break;
            }
            case ConfirmedServiceResponse_fileDirectory:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Response > (false, ConfirmedServiceResponse_fileDirectory), 77);
                break;
            }
            case ConfirmedServiceResponse_additionalService:
            {
                ITU_T_CHOICE_TAG(value<AdditionalService_Response > (false, ConfirmedServiceResponse_additionalService), 78);
                break;
            }
            case ConfirmedServiceResponse_getDataExchangeAttributes:
            {
                ITU_T_EXPLICIT_TAG(value<GetDataExchangeAttributes_Response > (false, ConfirmedServiceResponse_getDataExchangeAttributes), 80);
                break;
            }
            case ConfirmedServiceResponse_exchangeData:
            {
                ITU_T_IMPLICIT_TAG(value<ExchangeData_Response > (false, ConfirmedServiceResponse_exchangeData), 81);
                break;
            }
            case ConfirmedServiceResponse_defineAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(value<DefineAccessControlList_Response > (false, ConfirmedServiceResponse_defineAccessControlList), 82);
                break;
            }
            case ConfirmedServiceResponse_getAccessControlListAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetAccessControlListAttributes_Response > (false, ConfirmedServiceResponse_getAccessControlListAttributes), 83);
                break;
            }
            case ConfirmedServiceResponse_reportAccessControlledObjects:
            {
                ITU_T_IMPLICIT_TAG(value<ReportAccessControlledObjects_Response > (false, ConfirmedServiceResponse_reportAccessControlledObjects), 84);
                break;
            }
            case ConfirmedServiceResponse_deleteAccessControlList:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteAccessControlList_Response > (false, ConfirmedServiceResponse_deleteAccessControlList), 85);
                break;
            }
            case ConfirmedServiceResponse_changeAccessControl:
            {
                ITU_T_IMPLICIT_TAG(value<ChangeAccessControl_Response > (false, ConfirmedServiceResponse_changeAccessControl), 86);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Status_Response > (true, ConfirmedServiceResponse_status), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetNameList_Response > (true, ConfirmedServiceResponse_getNameList), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identify_Response > (true, ConfirmedServiceResponse_identify), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Rename_Response > (true, ConfirmedServiceResponse_rename), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Read_Response > (true, ConfirmedServiceResponse_read), 4)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetVariableAccessAttributes_Response > (true, ConfirmedServiceResponse_getVariableAccessAttributes), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineNamedVariable_Response > (true, ConfirmedServiceResponse_defineNamedVariable), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::DefineScatteredAccess_Response > (true, ConfirmedServiceResponse_defineScatteredAccess), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::GetScatteredAccessAttributes_Response > (true, ConfirmedServiceResponse_getScatteredAccessAttributes), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteVariableAccess_Response > (true, ConfirmedServiceResponse_deleteVariableAccess), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineNamedVariableList_Response > (true, ConfirmedServiceResponse_defineNamedVariableList), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetNamedVariableListAttributes_Response > (true, ConfirmedServiceResponse_getNamedVariableListAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteNamedVariableList_Response > (true, ConfirmedServiceResponse_deleteNamedVariableList), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineNamedType_Response > (true, ConfirmedServiceResponse_defineNamedType), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetNamedTypeAttributes_Response > (true, ConfirmedServiceResponse_getNamedTypeAttributes), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteNamedType_Response > (true, ConfirmedServiceResponse_deleteNamedType), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Input_Response > (true, ConfirmedServiceResponse_input), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Output_Response > (true, ConfirmedServiceResponse_output), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_CHOICE_TAG(value<TakeControl_Response > (true, ConfirmedServiceResponse_takeControl), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RelinquishControl_Response > (true, ConfirmedServiceResponse_relinquishControl), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineSemaphore_Response > (true, ConfirmedServiceResponse_defineSemaphore), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteSemaphore_Response > (true, ConfirmedServiceResponse_deleteSemaphore), 22)) return;
                        else free();
                        break;
                    }
                    case 23:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportSemaphoreStatus_Response > (true, ConfirmedServiceResponse_reportSemaphoreStatus), 23)) return;
                        else free();
                        break;
                    }
                    case 24:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportPoolSemaphoreStatus_Response > (true, ConfirmedServiceResponse_reportPoolSemaphoreStatus), 24)) return;
                        else free();
                        break;
                    }
                    case 25:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportSemaphoreEntryStatus_Response > (true, ConfirmedServiceResponse_reportSemaphoreEntryStatus), 25)) return;
                        else free();
                        break;
                    }
                    case 26:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitiateDownloadSequence_Response > (true, ConfirmedServiceResponse_initiateDownloadSequence), 26)) return;
                        else free();
                        break;
                    }
                    case 27:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DownloadSegment_Response > (true, ConfirmedServiceResponse_downloadSegment), 27)) return;
                        else free();
                        break;
                    }
                    case 28:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TerminateDownloadSequence_Response > (true, ConfirmedServiceResponse_terminateDownloadSequence), 28)) return;
                        else free();
                        break;
                    }
                    case 29:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitiateUploadSequence_Response > (true, ConfirmedServiceResponse_initiateUploadSequence), 29)) return;
                        else free();
                        break;
                    }
                    case 30:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UploadSegment_Response > (true, ConfirmedServiceResponse_uploadSegment), 30)) return;
                        else free();
                        break;
                    }
                    case 31:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TerminateUploadSequence_Response > (true, ConfirmedServiceResponse_terminateUploadSequence), 31)) return;
                        else free();
                        break;
                    }
                    case 32:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RequestDomainDownload_Response > (true, ConfirmedServiceResponse_requestDomainDownload), 32)) return;
                        else free();
                        break;
                    }
                    case 33:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RequestDomainUpload_Response > (true, ConfirmedServiceResponse_requestDomainUpload), 33)) return;
                        else free();
                        break;
                    }
                    case 34:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<LoadDomainContent_Response > (true, ConfirmedServiceResponse_loadDomainContent), 34)) return;
                        else free();
                        break;
                    }
                    case 35:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StoreDomainContent_Response > (true, ConfirmedServiceResponse_storeDomainContent), 35)) return;
                        else free();
                        break;
                    }
                    case 36:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteDomain_Response > (true, ConfirmedServiceResponse_deleteDomain), 36)) return;
                        else free();
                        break;
                    }
                    case 37:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetDomainAttributes_Response > (true, ConfirmedServiceResponse_getDomainAttributes), 37)) return;
                        else free();
                        break;
                    }
                    case 38:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CreateProgramInvocation_Response > (true, ConfirmedServiceResponse_createProgramInvocation), 38)) return;
                        else free();
                        break;
                    }
                    case 39:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteProgramInvocation_Response > (true, ConfirmedServiceResponse_deleteProgramInvocation), 39)) return;
                        else free();
                        break;
                    }
                    case 40:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Start_Response > (true, ConfirmedServiceResponse_start), 40)) return;
                        else free();
                        break;
                    }
                    case 41:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Stop_Response > (true, ConfirmedServiceResponse_stop), 41)) return;
                        else free();
                        break;
                    }
                    case 42:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Resume_Response > (true, ConfirmedServiceResponse_resume), 42)) return;
                        else free();
                        break;
                    }
                    case 43:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Reset_Response > (true, ConfirmedServiceResponse_reset), 43)) return;
                        else free();
                        break;
                    }
                    case 44:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Kill_Response > (true, ConfirmedServiceResponse_kill), 44)) return;
                        else free();
                        break;
                    }
                    case 45:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetProgramInvocationAttributes_Response > (true, ConfirmedServiceResponse_getProgramInvocationAttributes), 45)) return;
                        else free();
                        break;
                    }
                    case 46:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Response > (true, ConfirmedServiceResponse_obtainFile), 46)) return;
                        else free();
                        break;
                    }
                    case 47:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventCondition_Response > (true, ConfirmedServiceResponse_defineEventCondition), 47)) return;
                        else free();
                        break;
                    }
                    case 48:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteEventCondition_Response > (true, ConfirmedServiceResponse_deleteEventCondition), 48)) return;
                        else free();
                        break;
                    }
                    case 49:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetEventConditionAttributes_Response > (true, ConfirmedServiceResponse_getEventConditionAttributes), 49)) return;
                        else free();
                        break;
                    }
                    case 50:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportEventConditionStatus_Response > (true, ConfirmedServiceResponse_reportEventConditionStatus), 50)) return;
                        else free();
                        break;
                    }
                    case 51:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterEventConditionMonitoring_Response > (true, ConfirmedServiceResponse_alterEventConditionMonitoring), 51)) return;
                        else free();
                        break;
                    }
                    case 52:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TriggerEvent_Response > (true, ConfirmedServiceResponse_triggerEvent), 52)) return;
                        else free();
                        break;
                    }
                    case 53:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventAction_Response > (true, ConfirmedServiceResponse_defineEventAction), 53)) return;
                        else free();
                        break;
                    }
                    case 54:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteEventAction_Response > (true, ConfirmedServiceResponse_deleteEventAction), 54)) return;
                        else free();
                        break;
                    }
                    case 55:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetEventActionAttributes_Response > (true, ConfirmedServiceResponse_getEventActionAttributes), 55)) return;
                        else free();
                        break;
                    }
                    case 56:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportEventActionStatus_Response > (true, ConfirmedServiceResponse_reportEventActionStatus), 56)) return;
                        else free();
                        break;
                    }
                    case 57:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventEnrollment_Response > (true, ConfirmedServiceResponse_defineEventEnrollment), 57)) return;
                        else free();
                        break;
                    }
                    case 58:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteEventEnrollment_Response > (true, ConfirmedServiceResponse_deleteEventEnrollment), 58)) return;
                        else free();
                        break;
                    }
                    case 59:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterEventEnrollment_Response > (true, ConfirmedServiceResponse_alterEventEnrollment), 59)) return;
                        else free();
                        break;
                    }
                    case 60:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportEventEnrollmentStatus_Response > (true, ConfirmedServiceResponse_reportEventEnrollmentStatus), 60)) return;
                        else free();
                        break;
                    }
                    case 61:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetEventEnrollmentAttributes_Response > (true, ConfirmedServiceResponse_getEventEnrollmentAttributes), 61)) return;
                        else free();
                        break;
                    }
                    case 62:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AcknowledgeEventNotification_Response > (true, ConfirmedServiceResponse_acknowledgeEventNotification), 62)) return;
                        else free();
                        break;
                    }
                    case 63:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetAlarmSummary_Response > (true, ConfirmedServiceResponse_getAlarmSummary), 63)) return;
                        else free();
                        break;
                    }
                    case 64:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetAlarmEnrollmentSummary_Response > (true, ConfirmedServiceResponse_getAlarmEnrollmentSummary), 64)) return;
                        else free();
                        break;
                    }
                    case 65:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReadJournal_Response > (true, ConfirmedServiceResponse_readJournal), 65)) return;
                        else free();
                        break;
                    }
                    case 66:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<WriteJournal_Response > (true, ConfirmedServiceResponse_writeJournal), 66)) return;
                        else free();
                        break;
                    }
                    case 67:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitializeJournal_Response > (true, ConfirmedServiceResponse_initializeJournal), 67)) return;
                        else free();
                        break;
                    }
                    case 68:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportJournalStatus_Response > (true, ConfirmedServiceResponse_reportJournalStatus), 68)) return;
                        else free();
                        break;
                    }
                    case 69:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CreateJournal_Response > (true, ConfirmedServiceResponse_createJournal), 69)) return;
                        else free();
                        break;
                    }
                    case 70:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteJournal_Response > (true, ConfirmedServiceResponse_deleteJournal), 70)) return;
                        else free();
                        break;
                    }
                    case 71:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetCapabilityList_Response > (true, ConfirmedServiceResponse_getCapabilityList), 71)) return;
                        else free();
                        break;
                    }
                    case 72:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileOpen_Response > (true, ConfirmedServiceResponse_fileOpen), 72)) return;
                        else free();
                        break;
                    }
                    case 73:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRead_Response > (true, ConfirmedServiceResponse_fileRead), 73)) return;
                        else free();
                        break;
                    }
                    case 74:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileClose_Response > (true, ConfirmedServiceResponse_fileClose), 74)) return;
                        else free();
                        break;
                    }
                    case 75:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Response > (true, ConfirmedServiceResponse_fileRename), 75)) return;
                        else free();
                        break;
                    }
                    case 76:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDelete_Response > (true, ConfirmedServiceResponse_fileDelete), 76)) return;
                        else free();
                        break;
                    }
                    case 77:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileDirectory_Response > (true, ConfirmedServiceResponse_fileDirectory), 77)) return;
                        else free();
                        break;
                    }
                    case 78:
                    {
                        if (ITU_T_CHOICE_TAG(value<AdditionalService_Response > (true, ConfirmedServiceResponse_additionalService), 78)) return;
                        else free();
                        break;
                    }
                    case 80:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<GetDataExchangeAttributes_Response > (true, ConfirmedServiceResponse_getDataExchangeAttributes), 80)) return;
                        else free();
                        break;
                    }
                    case 81:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ExchangeData_Response > (true, ConfirmedServiceResponse_exchangeData), 81)) return;
                        else free();
                        break;
                    }
                    case 82:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineAccessControlList_Response > (true, ConfirmedServiceResponse_defineAccessControlList), 82)) return;
                        else free();
                        break;
                    }
                    case 83:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetAccessControlListAttributes_Response > (true, ConfirmedServiceResponse_getAccessControlListAttributes), 83)) return;
                        else free();
                        break;
                    }
                    case 84:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportAccessControlledObjects_Response > (true, ConfirmedServiceResponse_reportAccessControlledObjects), 84)) return;
                        else free();
                        break;
                    }
                    case 85:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteAccessControlList_Response > (true, ConfirmedServiceResponse_deleteAccessControlList), 85)) return;
                        else free();
                        break;
                    }
                    case 86:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ChangeAccessControl_Response > (true, ConfirmedServiceResponse_changeAccessControl), 86)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void AdditionalService_Response::vMDStop(const VMDStop_Response& vl) {
        set<VMDStop_Response>(new VMDStop_Response(vl), AdditionalService_Response_vMDStop);
    }

    void AdditionalService_Response::select(const Select_Response& vl) {
        set<Select_Response>(new Select_Response(vl), AdditionalService_Response_select);
    }

    void AdditionalService_Response::alterPI(const AlterProgramInvocationAttributes_Response& vl) {
        set<AlterProgramInvocationAttributes_Response>(new AlterProgramInvocationAttributes_Response(vl), AdditionalService_Response_alterPI);
    }

    void AdditionalService_Response::initiateUCLoad(const InitiateUnitControlLoad_Response& vl) {
        set<InitiateUnitControlLoad_Response>(new InitiateUnitControlLoad_Response(vl), AdditionalService_Response_initiateUCLoad);
    }

    void AdditionalService_Response::startUC(const StartUnitControl_Response& vl) {
        set<StartUnitControl_Response>(new StartUnitControl_Response(vl), AdditionalService_Response_startUC);
    }

    void AdditionalService_Response::stopUC(const StopUnitControl_Response& vl) {
        set<StopUnitControl_Response>(new StopUnitControl_Response(vl), AdditionalService_Response_stopUC);
    }

    void AdditionalService_Response::createUC(const CreateUnitControl_Response& vl) {
        set<CreateUnitControl_Response>(new CreateUnitControl_Response(vl), AdditionalService_Response_createUC);
    }

    void AdditionalService_Response::addToUC(const AddToUnitControl_Response& vl) {
        set<AddToUnitControl_Response>(new AddToUnitControl_Response(vl), AdditionalService_Response_addToUC);
    }

    void AdditionalService_Response::removeFromUC(const RemoveFromUnitControl_Response& vl) {
        set<RemoveFromUnitControl_Response>(new RemoveFromUnitControl_Response(vl), AdditionalService_Response_removeFromUC);
    }

    void AdditionalService_Response::loadUCFromFile(const LoadUnitControlFromFile_Response& vl) {
        set<LoadUnitControlFromFile_Response>(new LoadUnitControlFromFile_Response(vl), AdditionalService_Response_loadUCFromFile);
    }

    void AdditionalService_Response::storeUCToFile(const StoreUnitControlToFile_Response& vl) {
        set<StoreUnitControlToFile_Response>(new StoreUnitControlToFile_Response(vl), AdditionalService_Response_storeUCToFile);
    }

    void AdditionalService_Response::deleteUC(const DeleteUnitControl_Response& vl) {
        set<DeleteUnitControl_Response>(new DeleteUnitControl_Response(vl), AdditionalService_Response_deleteUC);
    }

    void AdditionalService_Response::defineECL(const DefineEventConditionList_Response& vl) {
        set<DefineEventConditionList_Response>(new DefineEventConditionList_Response(vl), AdditionalService_Response_defineECL);
    }

    void AdditionalService_Response::deleteECL(const DeleteEventConditionList_Response& vl) {
        set<DeleteEventConditionList_Response>(new DeleteEventConditionList_Response(vl), AdditionalService_Response_deleteECL);
    }

    void AdditionalService_Response::addECLReference(const AddEventConditionListReference_Response& vl) {
        set<AddEventConditionListReference_Response>(new AddEventConditionListReference_Response(vl), AdditionalService_Response_addECLReference);
    }

    void AdditionalService_Response::removeECLReference(const RemoveEventConditionListReference_Response& vl) {
        set<RemoveEventConditionListReference_Response>(new RemoveEventConditionListReference_Response(vl), AdditionalService_Response_removeECLReference);
    }

    void AdditionalService_Response::alterECLMonitoring(const AlterEventConditionListMonitoring_Response& vl) {
        set<AlterEventConditionListMonitoring_Response>(new AlterEventConditionListMonitoring_Response(vl), AdditionalService_Response_alterECLMonitoring);
    }

    template<> void AdditionalService_Response::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Response_vMDStop:
            {
                ITU_T_IMPLICIT_TAG(value<VMDStop_Response > (false, AdditionalService_Response_vMDStop), 0);
                break;
            }
            case AdditionalService_Response_vMDReset:
            {
                ITU_T_IMPLICIT_TAG(value<VMDReset_Response > (false, AdditionalService_Response_vMDReset), 1);
                break;
            }
            case AdditionalService_Response_select:
            {
                ITU_T_IMPLICIT_TAG(value<Select_Response > (false, AdditionalService_Response_select), 2);
                break;
            }
            case AdditionalService_Response_alterPI:
            {
                ITU_T_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Response > (false, AdditionalService_Response_alterPI), 3);
                break;
            }
            case AdditionalService_Response_initiateUCLoad:
            {
                ITU_T_IMPLICIT_TAG(value<InitiateUnitControlLoad_Response > (false, AdditionalService_Response_initiateUCLoad), 4);
                break;
            }
            case AdditionalService_Response_uCLoad:
            {
                ITU_T_IMPLICIT_TAG(value<UnitControlLoadSegment_Response > (false, AdditionalService_Response_uCLoad), 5);
                break;
            }
            case AdditionalService_Response_uCUpload:
            {
                ITU_T_IMPLICIT_TAG(value<UnitControlUpload_Response > (false, AdditionalService_Response_uCUpload), 6);
                break;
            }
            case AdditionalService_Response_startUC:
            {
                ITU_T_IMPLICIT_TAG(value<StartUnitControl_Response > (false, AdditionalService_Response_startUC), 7);
                break;
            }
            case AdditionalService_Response_stopUC:
            {
                ITU_T_IMPLICIT_TAG(value<StopUnitControl_Response > (false, AdditionalService_Response_stopUC), 8);
                break;
            }
            case AdditionalService_Response_createUC:
            {
                ITU_T_IMPLICIT_TAG(value<CreateUnitControl_Response > (false, AdditionalService_Response_createUC), 9);
                break;
            }
            case AdditionalService_Response_addToUC:
            {
                ITU_T_IMPLICIT_TAG(value<AddToUnitControl_Response > (false, AdditionalService_Response_addToUC), 10);
                break;
            }
            case AdditionalService_Response_removeFromUC:
            {
                ITU_T_IMPLICIT_TAG(value<RemoveFromUnitControl_Response > (false, AdditionalService_Response_removeFromUC), 11);
                break;
            }
            case AdditionalService_Response_getUCAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetUnitControlAttributes_Response > (false, AdditionalService_Response_getUCAttributes), 12);
                break;
            }
            case AdditionalService_Response_loadUCFromFile:
            {
                ITU_T_IMPLICIT_TAG(value<LoadUnitControlFromFile_Response > (false, AdditionalService_Response_loadUCFromFile), 13);
                break;
            }
            case AdditionalService_Response_storeUCToFile:
            {
                ITU_T_IMPLICIT_TAG(value<StoreUnitControlToFile_Response > (false, AdditionalService_Response_storeUCToFile), 14);
                break;
            }
            case AdditionalService_Response_deleteUC:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteUnitControl_Response > (false, AdditionalService_Response_deleteUC), 15);
                break;
            }
            case AdditionalService_Response_defineECL:
            {
                ITU_T_IMPLICIT_TAG(value<DefineEventConditionList_Response > (false, AdditionalService_Response_defineECL), 16);
                break;
            }
            case AdditionalService_Response_deleteECL:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteEventConditionList_Response > (false, AdditionalService_Response_deleteECL), 17);
                break;
            }
            case AdditionalService_Response_addECLReference:
            {
                ITU_T_IMPLICIT_TAG(value<AddEventConditionListReference_Response > (false, AdditionalService_Response_addECLReference), 18);
                break;
            }
            case AdditionalService_Response_removeECLReference:
            {
                ITU_T_IMPLICIT_TAG(value<RemoveEventConditionListReference_Response > (false, AdditionalService_Response_removeECLReference), 19);
                break;
            }
            case AdditionalService_Response_getECLAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<GetEventConditionListAttributes_Response > (false, AdditionalService_Response_getECLAttributes), 20);
                break;
            }
            case AdditionalService_Response_reportECLStatus:
            {
                ITU_T_IMPLICIT_TAG(value<ReportEventConditionListStatus_Response > (false, AdditionalService_Response_reportECLStatus), 21);
                break;
            }
            case AdditionalService_Response_alterECLMonitoring:
            {
                ITU_T_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Response > (false, AdditionalService_Response_alterECLMonitoring), 22);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<VMDStop_Response > (true, AdditionalService_Response_vMDStop), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<VMDReset_Response > (true, AdditionalService_Response_vMDReset), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Select_Response > (true, AdditionalService_Response_select), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterProgramInvocationAttributes_Response > (true, AdditionalService_Response_alterPI), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<InitiateUnitControlLoad_Response > (true, AdditionalService_Response_initiateUCLoad), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UnitControlLoadSegment_Response > (true, AdditionalService_Response_uCLoad), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<UnitControlUpload_Response > (true, AdditionalService_Response_uCUpload), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StartUnitControl_Response > (true, AdditionalService_Response_startUC), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StopUnitControl_Response > (true, AdditionalService_Response_stopUC), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CreateUnitControl_Response > (true, AdditionalService_Response_createUC), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AddToUnitControl_Response > (true, AdditionalService_Response_addToUC), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RemoveFromUnitControl_Response > (true, AdditionalService_Response_removeFromUC), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetUnitControlAttributes_Response > (true, AdditionalService_Response_getUCAttributes), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<LoadUnitControlFromFile_Response > (true, AdditionalService_Response_loadUCFromFile), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StoreUnitControlToFile_Response > (true, AdditionalService_Response_storeUCToFile), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteUnitControl_Response > (true, AdditionalService_Response_deleteUC), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DefineEventConditionList_Response > (true, AdditionalService_Response_defineECL), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteEventConditionList_Response > (true, AdditionalService_Response_deleteECL), 17)) return;
                        else free();
                        break;
                    }
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AddEventConditionListReference_Response > (true, AdditionalService_Response_addECLReference), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<RemoveEventConditionListReference_Response > (true, AdditionalService_Response_removeECLReference), 19)) return;
                        else free();
                        break;
                    }
                    case 20:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<GetEventConditionListAttributes_Response > (true, AdditionalService_Response_getECLAttributes), 20)) return;
                        else free();
                        break;
                    }
                    case 21:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ReportEventConditionListStatus_Response > (true, AdditionalService_Response_reportECLStatus), 21)) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<AlterEventConditionListMonitoring_Response > (true, AdditionalService_Response_alterECLMonitoring), 22)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void Response_Detail::otherRequests(const null_type& vl) {
        set<null_type>(new null_type(vl), Response_Detail_otherRequests);
    }

    template<> void Response_Detail::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Response_Detail_otherRequests:
            {
                ITU_T_BIND_TAG(value<null_type > (false, Response_Detail_otherRequests));
                break;
            }
            case Response_Detail_status:
            {
                ITU_T_CHOICE_TAG(value<CS_Status_Response > (false, Response_Detail_status), 0);
                break;
            }
            case Response_Detail_getProgramInvocationAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<CS_GetProgramInvocationAttributes_Response > (false, Response_Detail_getProgramInvocationAttributes), 45);
                break;
            }
            case Response_Detail_getEventConditionAttributes:
            {
                ITU_T_IMPLICIT_TAG(value<CS_GetEventConditionAttributes_Response > (false, Response_Detail_getEventConditionAttributes), 49);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<CS_Status_Response > (true, Response_Detail_status), 0)) return;
                        else free();
                        break;
                    }
                    case 45:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_GetProgramInvocationAttributes_Response > (true, Response_Detail_getProgramInvocationAttributes), 45)) return;
                        else free();
                        break;
                    }
                    case 49:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<CS_GetEventConditionAttributes_Response > (true, Response_Detail_getEventConditionAttributes), 49)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, Response_Detail_otherRequests))) return;
                else free();
            }
        }
    }


    // sequence Confirmed-ErrorPDU

    Confirmed_ErrorPDU::Confirmed_ErrorPDU() : invokeID_(), serviceError_() {
    };

    Confirmed_ErrorPDU::Confirmed_ErrorPDU(const Unsigned32& arg__invokeID,
            const ServiceError& arg__serviceError) :
    invokeID_(arg__invokeID),
    serviceError_(arg__serviceError) {
    };

    Confirmed_ErrorPDU::Confirmed_ErrorPDU(boost::shared_ptr< Unsigned32> arg__invokeID,
            boost::shared_ptr< Unsigned32> arg__modifierPosition,
            boost::shared_ptr< ServiceError> arg__serviceError) :
    invokeID_(arg__invokeID),
    modifierPosition_(arg__modifierPosition),
    serviceError_(arg__serviceError) {
    };

    template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(invokeID_, 0);
        ITU_T_IMPLICIT_TAG(modifierPosition_, 1);
        ITU_T_IMPLICIT_TAG(serviceError_, 2);
    }

    template<> void Confirmed_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(invokeID_, 0);
        ITU_T_IMPLICIT_TAG(modifierPosition_, 1);
        ITU_T_IMPLICIT_TAG(serviceError_, 2);
    }

    Unsigned32& Confirmed_ErrorPDU::invokeID() {
        return *invokeID_;
    }

    const Unsigned32& Confirmed_ErrorPDU::invokeID() const {
        return *invokeID_;
    }

    void Confirmed_ErrorPDU::invokeID(const Unsigned32& vl) {
        invokeID_ = vl;
    }

    void Confirmed_ErrorPDU::invokeID(boost::shared_ptr< Unsigned32> vl) {
        invokeID_ = vl;
    }

    boost::shared_ptr<Unsigned32> Confirmed_ErrorPDU::modifierPosition__new() {
        return modifierPosition_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void Confirmed_ErrorPDU::modifierPosition(const Unsigned32& vl) {
        modifierPosition_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    ServiceError& Confirmed_ErrorPDU::serviceError() {
        return *serviceError_;
    }

    const ServiceError& Confirmed_ErrorPDU::serviceError() const {
        return *serviceError_;
    }

    void Confirmed_ErrorPDU::serviceError(const ServiceError& vl) {
        serviceError_ = vl;
    }

    void Confirmed_ErrorPDU::serviceError(boost::shared_ptr< ServiceError> vl) {
        serviceError_ = vl;
    }


    // sequence ServiceError

    ServiceError::ServiceError() : errorClass_() {
    };

    ServiceError::ServiceError(const errorClass_type& arg__errorClass) :
    errorClass_(arg__errorClass) {
    };

    ServiceError::ServiceError(boost::shared_ptr< errorClass_type> arg__errorClass,
            boost::shared_ptr< int> arg__additionalCode,
            boost::shared_ptr< visiblestring_type> arg__additionalDescription,
            boost::shared_ptr< serviceSpecificInfo_type> arg__serviceSpecificInfo) :
    errorClass_(arg__errorClass),
    additionalCode_(arg__additionalCode),
    additionalDescription_(arg__additionalDescription),
    serviceSpecificInfo_(arg__serviceSpecificInfo) {
    };


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

    void ServiceError::errorClass_type::vmd_state(const int& vl) {
        set<int>(new int(vl), errorClass_type_vmd_state);
    }

    void ServiceError::errorClass_type::application_reference(const int& vl) {
        set<int>(new int(vl), errorClass_type_application_reference);
    }

    void ServiceError::errorClass_type::definition(const int& vl) {
        set<int>(new int(vl), errorClass_type_definition);
    }

    void ServiceError::errorClass_type::resource(const int& vl) {
        set<int>(new int(vl), errorClass_type_resource);
    }

    void ServiceError::errorClass_type::service(const int& vl) {
        set<int>(new int(vl), errorClass_type_service);
    }

    void ServiceError::errorClass_type::service_preempt(const int& vl) {
        set<int>(new int(vl), errorClass_type_service_preempt);
    }

    void ServiceError::errorClass_type::time_resolution(const int& vl) {
        set<int>(new int(vl), errorClass_type_time_resolution);
    }

    void ServiceError::errorClass_type::access(const int& vl) {
        set<int>(new int(vl), errorClass_type_access);
    }

    void ServiceError::errorClass_type::initiate(const int& vl) {
        set<int>(new int(vl), errorClass_type_initiate);
    }

    void ServiceError::errorClass_type::conclude(const int& vl) {
        set<int>(new int(vl), errorClass_type_conclude);
    }

    void ServiceError::errorClass_type::cancel(const int& vl) {
        set<int>(new int(vl), errorClass_type_cancel);
    }

    void ServiceError::errorClass_type::file(const int& vl) {
        set<int>(new int(vl), errorClass_type_file);
    }

    void ServiceError::errorClass_type::others(const int& vl) {
        set<int>(new int(vl), errorClass_type_others);
    }

    template<> void ServiceError::errorClass_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case errorClass_type_vmd_state:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_vmd_state), 0);
                break;
            }
            case errorClass_type_application_reference:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_application_reference), 1);
                break;
            }
            case errorClass_type_definition:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_definition), 2);
                break;
            }
            case errorClass_type_resource:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_resource), 3);
                break;
            }
            case errorClass_type_service:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_service), 4);
                break;
            }
            case errorClass_type_service_preempt:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_service_preempt), 5);
                break;
            }
            case errorClass_type_time_resolution:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_time_resolution), 6);
                break;
            }
            case errorClass_type_access:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_access), 7);
                break;
            }
            case errorClass_type_initiate:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_initiate), 8);
                break;
            }
            case errorClass_type_conclude:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_conclude), 9);
                break;
            }
            case errorClass_type_cancel:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_cancel), 10);
                break;
            }
            case errorClass_type_file:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_file), 11);
                break;
            }
            case errorClass_type_others:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, errorClass_type_others), 12);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ServiceError::errorClass_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_vmd_state), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_application_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_definition), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_resource), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_service), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_service_preempt), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_time_resolution), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_access), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_initiate), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_conclude), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_cancel), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_file), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, errorClass_type_others), 12)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void ServiceError::serviceSpecificInfo_type::obtainFile(const ISO_9506_MMS_1A::ObtainFile_Error& vl) {
        set<ISO_9506_MMS_1A::ObtainFile_Error>(new ISO_9506_MMS_1A::ObtainFile_Error(vl), serviceSpecificInfo_type_obtainFile);
    }

    void ServiceError::serviceSpecificInfo_type::start(const Start_Error& vl) {
        set<Start_Error>(new Start_Error(vl), serviceSpecificInfo_type_start);
    }

    void ServiceError::serviceSpecificInfo_type::stop(const Stop_Error& vl) {
        set<Stop_Error>(new Stop_Error(vl), serviceSpecificInfo_type_stop);
    }

    void ServiceError::serviceSpecificInfo_type::resume(const Resume_Error& vl) {
        set<Resume_Error>(new Resume_Error(vl), serviceSpecificInfo_type_resume);
    }

    void ServiceError::serviceSpecificInfo_type::reset(const Reset_Error& vl) {
        set<Reset_Error>(new Reset_Error(vl), serviceSpecificInfo_type_reset);
    }

    void ServiceError::serviceSpecificInfo_type::deleteVariableAccess(const DeleteVariableAccess_Error& vl) {
        set<DeleteVariableAccess_Error>(new DeleteVariableAccess_Error(vl), serviceSpecificInfo_type_deleteVariableAccess);
    }

    void ServiceError::serviceSpecificInfo_type::deleteNamedVariableList(const DeleteNamedVariableList_Error& vl) {
        set<DeleteNamedVariableList_Error>(new DeleteNamedVariableList_Error(vl), serviceSpecificInfo_type_deleteNamedVariableList);
    }

    void ServiceError::serviceSpecificInfo_type::deleteNamedType(const DeleteNamedType_Error& vl) {
        set<DeleteNamedType_Error>(new DeleteNamedType_Error(vl), serviceSpecificInfo_type_deleteNamedType);
    }

    void ServiceError::serviceSpecificInfo_type::fileRename(const ISO_9506_MMS_1A::FileRename_Error& vl) {
        set<ISO_9506_MMS_1A::FileRename_Error>(new ISO_9506_MMS_1A::FileRename_Error(vl), serviceSpecificInfo_type_fileRename);
    }

    void ServiceError::serviceSpecificInfo_type::changeAccessControl(const ChangeAccessControl_Error& vl) {
        set<ChangeAccessControl_Error>(new ChangeAccessControl_Error(vl), serviceSpecificInfo_type_changeAccessControl);
    }

    template<> void ServiceError::serviceSpecificInfo_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case serviceSpecificInfo_type_obtainFile:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Error > (false, serviceSpecificInfo_type_obtainFile), 0);
                break;
            }
            case serviceSpecificInfo_type_start:
            {
                ITU_T_IMPLICIT_TAG(value<Start_Error > (false, serviceSpecificInfo_type_start), 1);
                break;
            }
            case serviceSpecificInfo_type_stop:
            {
                ITU_T_IMPLICIT_TAG(value<Stop_Error > (false, serviceSpecificInfo_type_stop), 2);
                break;
            }
            case serviceSpecificInfo_type_resume:
            {
                ITU_T_IMPLICIT_TAG(value<Resume_Error > (false, serviceSpecificInfo_type_resume), 3);
                break;
            }
            case serviceSpecificInfo_type_reset:
            {
                ITU_T_IMPLICIT_TAG(value<Reset_Error > (false, serviceSpecificInfo_type_reset), 4);
                break;
            }
            case serviceSpecificInfo_type_deleteVariableAccess:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteVariableAccess_Error > (false, serviceSpecificInfo_type_deleteVariableAccess), 5);
                break;
            }
            case serviceSpecificInfo_type_deleteNamedVariableList:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteNamedVariableList_Error > (false, serviceSpecificInfo_type_deleteNamedVariableList), 6);
                break;
            }
            case serviceSpecificInfo_type_deleteNamedType:
            {
                ITU_T_IMPLICIT_TAG(value<DeleteNamedType_Error > (false, serviceSpecificInfo_type_deleteNamedType), 7);
                break;
            }
            case serviceSpecificInfo_type_defineEventEnrollment_Error:
            {
                ITU_T_CHOICE_TAG(value<DefineEventEnrollment_Error > (false, serviceSpecificInfo_type_defineEventEnrollment_Error), 8);
                break;
            }
            case serviceSpecificInfo_type_fileRename:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Error > (false, serviceSpecificInfo_type_fileRename), 9);
                break;
            }
            case serviceSpecificInfo_type_additionalService:
            {
                ITU_T_CHOICE_TAG(value<AdditionalService_Error > (false, serviceSpecificInfo_type_additionalService), 10);
                break;
            }
            case serviceSpecificInfo_type_changeAccessControl:
            {
                ITU_T_IMPLICIT_TAG(value<ChangeAccessControl_Error > (false, serviceSpecificInfo_type_changeAccessControl), 11);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ServiceError::serviceSpecificInfo_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ObtainFile_Error > (true, serviceSpecificInfo_type_obtainFile), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Start_Error > (true, serviceSpecificInfo_type_start), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Stop_Error > (true, serviceSpecificInfo_type_stop), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Resume_Error > (true, serviceSpecificInfo_type_resume), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Reset_Error > (true, serviceSpecificInfo_type_reset), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteVariableAccess_Error > (true, serviceSpecificInfo_type_deleteVariableAccess), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteNamedVariableList_Error > (true, serviceSpecificInfo_type_deleteNamedVariableList), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DeleteNamedType_Error > (true, serviceSpecificInfo_type_deleteNamedType), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_CHOICE_TAG(value<DefineEventEnrollment_Error > (true, serviceSpecificInfo_type_defineEventEnrollment_Error), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::FileRename_Error > (true, serviceSpecificInfo_type_fileRename), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_CHOICE_TAG(value<AdditionalService_Error > (true, serviceSpecificInfo_type_additionalService), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ChangeAccessControl_Error > (true, serviceSpecificInfo_type_changeAccessControl), 11)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void ServiceError::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(errorClass_, 0);
        ITU_T_IMPLICIT_TAG(additionalCode_, 1);
        ITU_T_IMPLICIT_TAG(additionalDescription_, 2);
        ITU_T_CHOICE_TAG(serviceSpecificInfo_, 3);
    }

    template<> void ServiceError::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(errorClass_, 0);
        ITU_T_IMPLICIT_TAG(additionalCode_, 1);
        ITU_T_IMPLICIT_TAG(additionalDescription_, 2);
        ITU_T_CHOICE_TAG(serviceSpecificInfo_, 3);
    }

    ServiceError::errorClass_type& ServiceError::errorClass() {
        return *errorClass_;
    }

    const ServiceError::errorClass_type& ServiceError::errorClass() const {
        return *errorClass_;
    }

    void ServiceError::errorClass(const errorClass_type& vl) {
        errorClass_ = vl;
    }

    void ServiceError::errorClass(boost::shared_ptr< errorClass_type> vl) {
        errorClass_ = vl;
    }

    boost::shared_ptr<int> ServiceError::additionalCode__new() {
        return additionalCode_ = boost::shared_ptr<int>(new int());
    }

    void ServiceError::additionalCode(const int& vl) {
        additionalCode_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<visiblestring_type> ServiceError::additionalDescription__new() {
        return additionalDescription_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void ServiceError::additionalDescription(const visiblestring_type& vl) {
        additionalDescription_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    boost::shared_ptr<ServiceError::serviceSpecificInfo_type> ServiceError::serviceSpecificInfo__new() {
        return serviceSpecificInfo_ = boost::shared_ptr<serviceSpecificInfo_type>(new serviceSpecificInfo_type());
    }

    void ServiceError::serviceSpecificInfo(const serviceSpecificInfo_type& vl) {
        serviceSpecificInfo_ = boost::shared_ptr<serviceSpecificInfo_type>(new serviceSpecificInfo_type(vl));
    }


    // choice AdditionalService-Error

    template<> void AdditionalService_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AdditionalService_Error_defineEcl:
            {
                ITU_T_CHOICE_TAG(value<DefineEventConditionList_Error > (false, AdditionalService_Error_defineEcl), 0);
                break;
            }
            case AdditionalService_Error_addECLReference:
            {
                ITU_T_CHOICE_TAG(value<AddEventConditionListReference_Error > (false, AdditionalService_Error_addECLReference), 1);
                break;
            }
            case AdditionalService_Error_removeECLReference:
            {
                ITU_T_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (false, AdditionalService_Error_removeECLReference), 2);
                break;
            }
            case AdditionalService_Error_initiateUC:
            {
                ITU_T_CHOICE_TAG(value<InitiateUnitControl_Error > (false, AdditionalService_Error_initiateUC), 3);
                break;
            }
            case AdditionalService_Error_startUC:
            {
                ITU_T_IMPLICIT_TAG(value<StartUnitControl_Error > (false, AdditionalService_Error_startUC), 4);
                break;
            }
            case AdditionalService_Error_stopUC:
            {
                ITU_T_IMPLICIT_TAG(value<StopUnitControl_Error > (false, AdditionalService_Error_stopUC), 5);
                break;
            }
            case AdditionalService_Error_deleteUC:
            {
                ITU_T_CHOICE_TAG(value<DeleteUnitControl_Error > (false, AdditionalService_Error_deleteUC), 6);
                break;
            }
            case AdditionalService_Error_loadUCFromFile:
            {
                ITU_T_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (false, AdditionalService_Error_loadUCFromFile), 7);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<DefineEventConditionList_Error > (true, AdditionalService_Error_defineEcl), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<AddEventConditionListReference_Error > (true, AdditionalService_Error_addECLReference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_CHOICE_TAG(value<RemoveEventConditionListReference_Error > (true, AdditionalService_Error_removeECLReference), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_CHOICE_TAG(value<InitiateUnitControl_Error > (true, AdditionalService_Error_initiateUC), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StartUnitControl_Error > (true, AdditionalService_Error_startUC), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<StopUnitControl_Error > (true, AdditionalService_Error_stopUC), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_CHOICE_TAG(value<DeleteUnitControl_Error > (true, AdditionalService_Error_deleteUC), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_CHOICE_TAG(value<LoadUnitControlFromFile_Error > (true, AdditionalService_Error_loadUCFromFile), 7)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    const int maxIdentifier = 32;

    // choice ObjectName

    ObjectName::domain_specific_type::domain_specific_type() : domainID_(), itemID_() {
    };

    ObjectName::domain_specific_type::domain_specific_type(const Identifier& arg__domainID,
            const Identifier& arg__itemID) :
    domainID_(arg__domainID),
    itemID_(arg__itemID) {
    };

    template<> void ObjectName::domain_specific_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(domainID_);
        ITU_T_BIND_TAG(itemID_);
    }

    template<> void ObjectName::domain_specific_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(domainID_);
        ITU_T_BIND_TAG(itemID_);
    }

    Identifier& ObjectName::domain_specific_type::domainID() {
        return *domainID_;
    }

    const Identifier& ObjectName::domain_specific_type::domainID() const {
        return *domainID_;
    }

    void ObjectName::domain_specific_type::domainID(const Identifier& vl) {
        domainID_ = vl;
    }

    void ObjectName::domain_specific_type::domainID(boost::shared_ptr< Identifier> vl) {
        domainID_ = vl;
    }

    Identifier& ObjectName::domain_specific_type::itemID() {
        return *itemID_;
    }

    const Identifier& ObjectName::domain_specific_type::itemID() const {
        return *itemID_;
    }

    void ObjectName::domain_specific_type::itemID(const Identifier& vl) {
        itemID_ = vl;
    }

    void ObjectName::domain_specific_type::itemID(boost::shared_ptr< Identifier> vl) {
        itemID_ = vl;
    }

    void ObjectName::vmd_specific(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), ObjectName_vmd_specific);
    }

    void ObjectName::aa_specific(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), ObjectName_aa_specific);
    }

    template<> void ObjectName::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ObjectName_vmd_specific:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, ObjectName_vmd_specific), 0);
                break;
            }
            case ObjectName_domain_specific:
            {
                ITU_T_IMPLICIT_TAG(value<domain_specific_type > (false, ObjectName_domain_specific), 1);
                break;
            }
            case ObjectName_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, ObjectName_aa_specific), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, ObjectName_vmd_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<domain_specific_type > (true, ObjectName_domain_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, ObjectName_aa_specific), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void ObjectClass::basicObjectClass(const int& vl) {
        set<int>(new int(vl), ObjectClass_basicObjectClass);
    }

    void ObjectClass::csObjectClass(const int& vl) {
        set<int>(new int(vl), ObjectClass_csObjectClass);
    }

    template<> void ObjectClass::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ObjectClass_basicObjectClass:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, ObjectClass_basicObjectClass), 0);
                break;
            }
            case ObjectClass_csObjectClass:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, ObjectClass_csObjectClass), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, ObjectClass_basicObjectClass), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, ObjectClass_csObjectClass), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    Initiate_RequestPDU::Initiate_RequestPDU() : proposedMaxServOutstandingCalling_(), proposedMaxServOutstandingCalled_(), initRequestDetail_() {
    };

    Initiate_RequestPDU::Initiate_RequestPDU(const Integer16& arg__proposedMaxServOutstandingCalling,
            const Integer16& arg__proposedMaxServOutstandingCalled,
            const initRequestDetail_type& arg__initRequestDetail) :
    proposedMaxServOutstandingCalling_(arg__proposedMaxServOutstandingCalling),
    proposedMaxServOutstandingCalled_(arg__proposedMaxServOutstandingCalled),
    initRequestDetail_(arg__initRequestDetail) {
    };

    Initiate_RequestPDU::Initiate_RequestPDU(boost::shared_ptr< Integer32> arg__localDetailCalling,
            boost::shared_ptr< Integer16> arg__proposedMaxServOutstandingCalling,
            boost::shared_ptr< Integer16> arg__proposedMaxServOutstandingCalled,
            boost::shared_ptr< Integer8> arg__proposedDataStructureNestingLevel,
            boost::shared_ptr< initRequestDetail_type> arg__initRequestDetail) :
    localDetailCalling_(arg__localDetailCalling),
    proposedMaxServOutstandingCalling_(arg__proposedMaxServOutstandingCalling),
    proposedMaxServOutstandingCalled_(arg__proposedMaxServOutstandingCalled),
    proposedDataStructureNestingLevel_(arg__proposedDataStructureNestingLevel),
    initRequestDetail_(arg__initRequestDetail) {
    };

    Initiate_RequestPDU::initRequestDetail_type::initRequestDetail_type() : proposedVersionNumber_(), proposedParameterCBB_(), servicesSupportedCalling_() {
    };

    Initiate_RequestPDU::initRequestDetail_type::initRequestDetail_type(const Integer16& arg__proposedVersionNumber,
            const MMS_Object_Module_1::ParameterSupportOptions& arg__proposedParameterCBB,
            const MMS_Object_Module_1::ServiceSupportOptions& arg__servicesSupportedCalling) :
    proposedVersionNumber_(arg__proposedVersionNumber),
    proposedParameterCBB_(arg__proposedParameterCBB),
    servicesSupportedCalling_(arg__servicesSupportedCalling) {
    };

    Initiate_RequestPDU::initRequestDetail_type::initRequestDetail_type(boost::shared_ptr< Integer16> arg__proposedVersionNumber,
            boost::shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> arg__proposedParameterCBB,
            boost::shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> arg__servicesSupportedCalling,
            boost::shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> arg__additionalSupportedCalling,
            boost::shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> arg__additionalCbbSupportedCalling,
            boost::shared_ptr< visiblestring_type> arg__privilegeClassIdentityCalling) :
    proposedVersionNumber_(arg__proposedVersionNumber),
    proposedParameterCBB_(arg__proposedParameterCBB),
    servicesSupportedCalling_(arg__servicesSupportedCalling),
    additionalSupportedCalling_(arg__additionalSupportedCalling),
    additionalCbbSupportedCalling_(arg__additionalCbbSupportedCalling),
    privilegeClassIdentityCalling_(arg__privilegeClassIdentityCalling) {
    };

    template<> void Initiate_RequestPDU::initRequestDetail_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(proposedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(proposedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(servicesSupportedCalling_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalling_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalling_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalling_, 5);
    }

    template<> void Initiate_RequestPDU::initRequestDetail_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(proposedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(proposedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(servicesSupportedCalling_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalling_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalling_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalling_, 5);
    }

    Integer16& Initiate_RequestPDU::initRequestDetail_type::proposedVersionNumber() {
        return *proposedVersionNumber_;
    }

    const Integer16& Initiate_RequestPDU::initRequestDetail_type::proposedVersionNumber() const {
        return *proposedVersionNumber_;
    }

    void Initiate_RequestPDU::initRequestDetail_type::proposedVersionNumber(const Integer16& vl) {
        proposedVersionNumber_ = vl;
    }

    void Initiate_RequestPDU::initRequestDetail_type::proposedVersionNumber(boost::shared_ptr< Integer16> vl) {
        proposedVersionNumber_ = vl;
    }

    MMS_Object_Module_1::ParameterSupportOptions& Initiate_RequestPDU::initRequestDetail_type::proposedParameterCBB() {
        return *proposedParameterCBB_;
    }

    const MMS_Object_Module_1::ParameterSupportOptions& Initiate_RequestPDU::initRequestDetail_type::proposedParameterCBB() const {
        return *proposedParameterCBB_;
    }

    void Initiate_RequestPDU::initRequestDetail_type::proposedParameterCBB(const MMS_Object_Module_1::ParameterSupportOptions& vl) {
        proposedParameterCBB_ = vl;
    }

    void Initiate_RequestPDU::initRequestDetail_type::proposedParameterCBB(boost::shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> vl) {
        proposedParameterCBB_ = vl;
    }

    MMS_Object_Module_1::ServiceSupportOptions& Initiate_RequestPDU::initRequestDetail_type::servicesSupportedCalling() {
        return *servicesSupportedCalling_;
    }

    const MMS_Object_Module_1::ServiceSupportOptions& Initiate_RequestPDU::initRequestDetail_type::servicesSupportedCalling() const {
        return *servicesSupportedCalling_;
    }

    void Initiate_RequestPDU::initRequestDetail_type::servicesSupportedCalling(const MMS_Object_Module_1::ServiceSupportOptions& vl) {
        servicesSupportedCalling_ = vl;
    }

    void Initiate_RequestPDU::initRequestDetail_type::servicesSupportedCalling(boost::shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> vl) {
        servicesSupportedCalling_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::AdditionalSupportOptions> Initiate_RequestPDU::initRequestDetail_type::additionalSupportedCalling__new() {
        return additionalSupportedCalling_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalSupportOptions>(new MMS_Object_Module_1::AdditionalSupportOptions());
    }

    void Initiate_RequestPDU::initRequestDetail_type::additionalSupportedCalling(const MMS_Object_Module_1::AdditionalSupportOptions& vl) {
        additionalSupportedCalling_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalSupportOptions>(new MMS_Object_Module_1::AdditionalSupportOptions(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AdditionalCBBOptions> Initiate_RequestPDU::initRequestDetail_type::additionalCbbSupportedCalling__new() {
        return additionalCbbSupportedCalling_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalCBBOptions>(new MMS_Object_Module_1::AdditionalCBBOptions());
    }

    void Initiate_RequestPDU::initRequestDetail_type::additionalCbbSupportedCalling(const MMS_Object_Module_1::AdditionalCBBOptions& vl) {
        additionalCbbSupportedCalling_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalCBBOptions>(new MMS_Object_Module_1::AdditionalCBBOptions(vl));
    }

    boost::shared_ptr<visiblestring_type> Initiate_RequestPDU::initRequestDetail_type::privilegeClassIdentityCalling__new() {
        return privilegeClassIdentityCalling_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void Initiate_RequestPDU::initRequestDetail_type::privilegeClassIdentityCalling(const visiblestring_type& vl) {
        privilegeClassIdentityCalling_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalling_, 0);
        ITU_T_IMPLICIT_TAG(proposedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(proposedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(proposedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(initRequestDetail_, 4);
    }

    template<> void Initiate_RequestPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalling_, 0);
        ITU_T_IMPLICIT_TAG(proposedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(proposedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(proposedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(initRequestDetail_, 4);
    }

    boost::shared_ptr<Integer32> Initiate_RequestPDU::localDetailCalling__new() {
        return localDetailCalling_ = boost::shared_ptr<Integer32>(new Integer32());
    }

    void Initiate_RequestPDU::localDetailCalling(const Integer32& vl) {
        localDetailCalling_ = boost::shared_ptr<Integer32>(new Integer32(vl));
    }

    Integer16& Initiate_RequestPDU::proposedMaxServOutstandingCalling() {
        return *proposedMaxServOutstandingCalling_;
    }

    const Integer16& Initiate_RequestPDU::proposedMaxServOutstandingCalling() const {
        return *proposedMaxServOutstandingCalling_;
    }

    void Initiate_RequestPDU::proposedMaxServOutstandingCalling(const Integer16& vl) {
        proposedMaxServOutstandingCalling_ = vl;
    }

    void Initiate_RequestPDU::proposedMaxServOutstandingCalling(boost::shared_ptr< Integer16> vl) {
        proposedMaxServOutstandingCalling_ = vl;
    }

    Integer16& Initiate_RequestPDU::proposedMaxServOutstandingCalled() {
        return *proposedMaxServOutstandingCalled_;
    }

    const Integer16& Initiate_RequestPDU::proposedMaxServOutstandingCalled() const {
        return *proposedMaxServOutstandingCalled_;
    }

    void Initiate_RequestPDU::proposedMaxServOutstandingCalled(const Integer16& vl) {
        proposedMaxServOutstandingCalled_ = vl;
    }

    void Initiate_RequestPDU::proposedMaxServOutstandingCalled(boost::shared_ptr< Integer16> vl) {
        proposedMaxServOutstandingCalled_ = vl;
    }

    boost::shared_ptr<Integer8> Initiate_RequestPDU::proposedDataStructureNestingLevel__new() {
        return proposedDataStructureNestingLevel_ = boost::shared_ptr<Integer8>(new Integer8());
    }

    void Initiate_RequestPDU::proposedDataStructureNestingLevel(const Integer8& vl) {
        proposedDataStructureNestingLevel_ = boost::shared_ptr<Integer8>(new Integer8(vl));
    }

    Initiate_RequestPDU::initRequestDetail_type& Initiate_RequestPDU::initRequestDetail() {
        return *initRequestDetail_;
    }

    const Initiate_RequestPDU::initRequestDetail_type& Initiate_RequestPDU::initRequestDetail() const {
        return *initRequestDetail_;
    }

    void Initiate_RequestPDU::initRequestDetail(const initRequestDetail_type& vl) {
        initRequestDetail_ = vl;
    }

    void Initiate_RequestPDU::initRequestDetail(boost::shared_ptr< initRequestDetail_type> vl) {
        initRequestDetail_ = vl;
    }


    // sequence Initiate-ResponsePDU

    Initiate_ResponsePDU::Initiate_ResponsePDU() : negotiatedMaxServOutstandingCalling_(), negotiatedMaxServOutstandingCalled_(), initResponseDetail_() {
    };

    Initiate_ResponsePDU::Initiate_ResponsePDU(const Integer16& arg__negotiatedMaxServOutstandingCalling,
            const Integer16& arg__negotiatedMaxServOutstandingCalled,
            const initResponseDetail_type& arg__initResponseDetail) :
    negotiatedMaxServOutstandingCalling_(arg__negotiatedMaxServOutstandingCalling),
    negotiatedMaxServOutstandingCalled_(arg__negotiatedMaxServOutstandingCalled),
    initResponseDetail_(arg__initResponseDetail) {
    };

    Initiate_ResponsePDU::Initiate_ResponsePDU(boost::shared_ptr< Integer32> arg__localDetailCalled,
            boost::shared_ptr< Integer16> arg__negotiatedMaxServOutstandingCalling,
            boost::shared_ptr< Integer16> arg__negotiatedMaxServOutstandingCalled,
            boost::shared_ptr< Integer8> arg__negotiatedDataStructureNestingLevel,
            boost::shared_ptr< initResponseDetail_type> arg__initResponseDetail) :
    localDetailCalled_(arg__localDetailCalled),
    negotiatedMaxServOutstandingCalling_(arg__negotiatedMaxServOutstandingCalling),
    negotiatedMaxServOutstandingCalled_(arg__negotiatedMaxServOutstandingCalled),
    negotiatedDataStructureNestingLevel_(arg__negotiatedDataStructureNestingLevel),
    initResponseDetail_(arg__initResponseDetail) {
    };

    Initiate_ResponsePDU::initResponseDetail_type::initResponseDetail_type() : negotiatedVersionNumber_(), negotiatedParameterCBB_(), servicesSupportedCalled_() {
    };

    Initiate_ResponsePDU::initResponseDetail_type::initResponseDetail_type(const Integer16& arg__negotiatedVersionNumber,
            const MMS_Object_Module_1::ParameterSupportOptions& arg__negotiatedParameterCBB,
            const MMS_Object_Module_1::ServiceSupportOptions& arg__servicesSupportedCalled) :
    negotiatedVersionNumber_(arg__negotiatedVersionNumber),
    negotiatedParameterCBB_(arg__negotiatedParameterCBB),
    servicesSupportedCalled_(arg__servicesSupportedCalled) {
    };

    Initiate_ResponsePDU::initResponseDetail_type::initResponseDetail_type(boost::shared_ptr< Integer16> arg__negotiatedVersionNumber,
            boost::shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> arg__negotiatedParameterCBB,
            boost::shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> arg__servicesSupportedCalled,
            boost::shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> arg__additionalSupportedCalled,
            boost::shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> arg__additionalCbbSupportedCalled,
            boost::shared_ptr< visiblestring_type> arg__privilegeClassIdentityCalled) :
    negotiatedVersionNumber_(arg__negotiatedVersionNumber),
    negotiatedParameterCBB_(arg__negotiatedParameterCBB),
    servicesSupportedCalled_(arg__servicesSupportedCalled),
    additionalSupportedCalled_(arg__additionalSupportedCalled),
    additionalCbbSupportedCalled_(arg__additionalCbbSupportedCalled),
    privilegeClassIdentityCalled_(arg__privilegeClassIdentityCalled) {
    };

    template<> void Initiate_ResponsePDU::initResponseDetail_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(negotiatedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(negotiatedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(servicesSupportedCalled_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalled_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalled_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalled_, 5);
    }

    template<> void Initiate_ResponsePDU::initResponseDetail_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(negotiatedVersionNumber_, 0);
        ITU_T_IMPLICIT_TAG(negotiatedParameterCBB_, 1);
        ITU_T_IMPLICIT_TAG(servicesSupportedCalled_, 2);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(additionalSupportedCalled_, 3);
        ITU_T_IMPLICIT_TAG(additionalCbbSupportedCalled_, 4);
        ITU_T_IMPLICIT_TAG(privilegeClassIdentityCalled_, 5);
    }

    Integer16& Initiate_ResponsePDU::initResponseDetail_type::negotiatedVersionNumber() {
        return *negotiatedVersionNumber_;
    }

    const Integer16& Initiate_ResponsePDU::initResponseDetail_type::negotiatedVersionNumber() const {
        return *negotiatedVersionNumber_;
    }

    void Initiate_ResponsePDU::initResponseDetail_type::negotiatedVersionNumber(const Integer16& vl) {
        negotiatedVersionNumber_ = vl;
    }

    void Initiate_ResponsePDU::initResponseDetail_type::negotiatedVersionNumber(boost::shared_ptr< Integer16> vl) {
        negotiatedVersionNumber_ = vl;
    }

    MMS_Object_Module_1::ParameterSupportOptions& Initiate_ResponsePDU::initResponseDetail_type::negotiatedParameterCBB() {
        return *negotiatedParameterCBB_;
    }

    const MMS_Object_Module_1::ParameterSupportOptions& Initiate_ResponsePDU::initResponseDetail_type::negotiatedParameterCBB() const {
        return *negotiatedParameterCBB_;
    }

    void Initiate_ResponsePDU::initResponseDetail_type::negotiatedParameterCBB(const MMS_Object_Module_1::ParameterSupportOptions& vl) {
        negotiatedParameterCBB_ = vl;
    }

    void Initiate_ResponsePDU::initResponseDetail_type::negotiatedParameterCBB(boost::shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> vl) {
        negotiatedParameterCBB_ = vl;
    }

    MMS_Object_Module_1::ServiceSupportOptions& Initiate_ResponsePDU::initResponseDetail_type::servicesSupportedCalled() {
        return *servicesSupportedCalled_;
    }

    const MMS_Object_Module_1::ServiceSupportOptions& Initiate_ResponsePDU::initResponseDetail_type::servicesSupportedCalled() const {
        return *servicesSupportedCalled_;
    }

    void Initiate_ResponsePDU::initResponseDetail_type::servicesSupportedCalled(const MMS_Object_Module_1::ServiceSupportOptions& vl) {
        servicesSupportedCalled_ = vl;
    }

    void Initiate_ResponsePDU::initResponseDetail_type::servicesSupportedCalled(boost::shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> vl) {
        servicesSupportedCalled_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::AdditionalSupportOptions> Initiate_ResponsePDU::initResponseDetail_type::additionalSupportedCalled__new() {
        return additionalSupportedCalled_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalSupportOptions>(new MMS_Object_Module_1::AdditionalSupportOptions());
    }

    void Initiate_ResponsePDU::initResponseDetail_type::additionalSupportedCalled(const MMS_Object_Module_1::AdditionalSupportOptions& vl) {
        additionalSupportedCalled_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalSupportOptions>(new MMS_Object_Module_1::AdditionalSupportOptions(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AdditionalCBBOptions> Initiate_ResponsePDU::initResponseDetail_type::additionalCbbSupportedCalled__new() {
        return additionalCbbSupportedCalled_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalCBBOptions>(new MMS_Object_Module_1::AdditionalCBBOptions());
    }

    void Initiate_ResponsePDU::initResponseDetail_type::additionalCbbSupportedCalled(const MMS_Object_Module_1::AdditionalCBBOptions& vl) {
        additionalCbbSupportedCalled_ = boost::shared_ptr<MMS_Object_Module_1::AdditionalCBBOptions>(new MMS_Object_Module_1::AdditionalCBBOptions(vl));
    }

    boost::shared_ptr<visiblestring_type> Initiate_ResponsePDU::initResponseDetail_type::privilegeClassIdentityCalled__new() {
        return privilegeClassIdentityCalled_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void Initiate_ResponsePDU::initResponseDetail_type::privilegeClassIdentityCalled(const visiblestring_type& vl) {
        privilegeClassIdentityCalled_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalled_, 0);
        ITU_T_IMPLICIT_TAG(negotiatedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(negotiatedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(negotiatedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(initResponseDetail_, 4);
    }

    template<> void Initiate_ResponsePDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(localDetailCalled_, 0);
        ITU_T_IMPLICIT_TAG(negotiatedMaxServOutstandingCalling_, 1);
        ITU_T_IMPLICIT_TAG(negotiatedMaxServOutstandingCalled_, 2);
        ITU_T_IMPLICIT_TAG(negotiatedDataStructureNestingLevel_, 3);
        ITU_T_IMPLICIT_TAG(initResponseDetail_, 4);
    }

    boost::shared_ptr<Integer32> Initiate_ResponsePDU::localDetailCalled__new() {
        return localDetailCalled_ = boost::shared_ptr<Integer32>(new Integer32());
    }

    void Initiate_ResponsePDU::localDetailCalled(const Integer32& vl) {
        localDetailCalled_ = boost::shared_ptr<Integer32>(new Integer32(vl));
    }

    Integer16& Initiate_ResponsePDU::negotiatedMaxServOutstandingCalling() {
        return *negotiatedMaxServOutstandingCalling_;
    }

    const Integer16& Initiate_ResponsePDU::negotiatedMaxServOutstandingCalling() const {
        return *negotiatedMaxServOutstandingCalling_;
    }

    void Initiate_ResponsePDU::negotiatedMaxServOutstandingCalling(const Integer16& vl) {
        negotiatedMaxServOutstandingCalling_ = vl;
    }

    void Initiate_ResponsePDU::negotiatedMaxServOutstandingCalling(boost::shared_ptr< Integer16> vl) {
        negotiatedMaxServOutstandingCalling_ = vl;
    }

    Integer16& Initiate_ResponsePDU::negotiatedMaxServOutstandingCalled() {
        return *negotiatedMaxServOutstandingCalled_;
    }

    const Integer16& Initiate_ResponsePDU::negotiatedMaxServOutstandingCalled() const {
        return *negotiatedMaxServOutstandingCalled_;
    }

    void Initiate_ResponsePDU::negotiatedMaxServOutstandingCalled(const Integer16& vl) {
        negotiatedMaxServOutstandingCalled_ = vl;
    }

    void Initiate_ResponsePDU::negotiatedMaxServOutstandingCalled(boost::shared_ptr< Integer16> vl) {
        negotiatedMaxServOutstandingCalled_ = vl;
    }

    boost::shared_ptr<Integer8> Initiate_ResponsePDU::negotiatedDataStructureNestingLevel__new() {
        return negotiatedDataStructureNestingLevel_ = boost::shared_ptr<Integer8>(new Integer8());
    }

    void Initiate_ResponsePDU::negotiatedDataStructureNestingLevel(const Integer8& vl) {
        negotiatedDataStructureNestingLevel_ = boost::shared_ptr<Integer8>(new Integer8(vl));
    }

    Initiate_ResponsePDU::initResponseDetail_type& Initiate_ResponsePDU::initResponseDetail() {
        return *initResponseDetail_;
    }

    const Initiate_ResponsePDU::initResponseDetail_type& Initiate_ResponsePDU::initResponseDetail() const {
        return *initResponseDetail_;
    }

    void Initiate_ResponsePDU::initResponseDetail(const initResponseDetail_type& vl) {
        initResponseDetail_ = vl;
    }

    void Initiate_ResponsePDU::initResponseDetail(boost::shared_ptr< initResponseDetail_type> vl) {
        initResponseDetail_ = vl;
    }


    // sequence Cancel-ErrorPDU

    Cancel_ErrorPDU::Cancel_ErrorPDU() : originalInvokeID_(), serviceError_() {
    };

    Cancel_ErrorPDU::Cancel_ErrorPDU(const Unsigned32& arg__originalInvokeID,
            const ServiceError& arg__serviceError) :
    originalInvokeID_(arg__originalInvokeID),
    serviceError_(arg__serviceError) {
    };

    template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(originalInvokeID_, 0);
        ITU_T_IMPLICIT_TAG(serviceError_, 1);
    }

    template<> void Cancel_ErrorPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(originalInvokeID_, 0);
        ITU_T_IMPLICIT_TAG(serviceError_, 1);
    }

    Unsigned32& Cancel_ErrorPDU::originalInvokeID() {
        return *originalInvokeID_;
    }

    const Unsigned32& Cancel_ErrorPDU::originalInvokeID() const {
        return *originalInvokeID_;
    }

    void Cancel_ErrorPDU::originalInvokeID(const Unsigned32& vl) {
        originalInvokeID_ = vl;
    }

    void Cancel_ErrorPDU::originalInvokeID(boost::shared_ptr< Unsigned32> vl) {
        originalInvokeID_ = vl;
    }

    ServiceError& Cancel_ErrorPDU::serviceError() {
        return *serviceError_;
    }

    const ServiceError& Cancel_ErrorPDU::serviceError() const {
        return *serviceError_;
    }

    void Cancel_ErrorPDU::serviceError(const ServiceError& vl) {
        serviceError_ = vl;
    }

    void Cancel_ErrorPDU::serviceError(boost::shared_ptr< ServiceError> vl) {
        serviceError_ = vl;
    }


    // sequence RejectPDU

    RejectPDU::RejectPDU() : rejectReason_() {
    };

    RejectPDU::RejectPDU(const rejectReason_type& arg__rejectReason) :
    rejectReason_(arg__rejectReason) {
    };

    RejectPDU::RejectPDU(boost::shared_ptr< Unsigned32> arg__originalInvokeID,
            boost::shared_ptr< rejectReason_type> arg__rejectReason) :
    originalInvokeID_(arg__originalInvokeID),
    rejectReason_(arg__rejectReason) {
    };


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

    void RejectPDU::rejectReason_type::confirmed_requestPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_confirmed_requestPDU);
    }

    void RejectPDU::rejectReason_type::confirmed_responsePDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_confirmed_responsePDU);
    }

    void RejectPDU::rejectReason_type::confirmed_errorPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_confirmed_errorPDU);
    }

    void RejectPDU::rejectReason_type::unconfirmedPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_unconfirmedPDU);
    }

    void RejectPDU::rejectReason_type::pdu_error(const int& vl) {
        set<int>(new int(vl), rejectReason_type_pdu_error);
    }

    void RejectPDU::rejectReason_type::cancel_requestPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_cancel_requestPDU);
    }

    void RejectPDU::rejectReason_type::cancel_responsePDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_cancel_responsePDU);
    }

    void RejectPDU::rejectReason_type::cancel_errorPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_cancel_errorPDU);
    }

    void RejectPDU::rejectReason_type::conclude_requestPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_conclude_requestPDU);
    }

    void RejectPDU::rejectReason_type::conclude_responsePDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_conclude_responsePDU);
    }

    void RejectPDU::rejectReason_type::conclude_errorPDU(const int& vl) {
        set<int>(new int(vl), rejectReason_type_conclude_errorPDU);
    }

    template<> void RejectPDU::rejectReason_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case rejectReason_type_confirmed_requestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_confirmed_requestPDU), 1);
                break;
            }
            case rejectReason_type_confirmed_responsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_confirmed_responsePDU), 2);
                break;
            }
            case rejectReason_type_confirmed_errorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_confirmed_errorPDU), 3);
                break;
            }
            case rejectReason_type_unconfirmedPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_unconfirmedPDU), 4);
                break;
            }
            case rejectReason_type_pdu_error:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_pdu_error), 5);
                break;
            }
            case rejectReason_type_cancel_requestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_cancel_requestPDU), 6);
                break;
            }
            case rejectReason_type_cancel_responsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_cancel_responsePDU), 7);
                break;
            }
            case rejectReason_type_cancel_errorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_cancel_errorPDU), 8);
                break;
            }
            case rejectReason_type_conclude_requestPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_conclude_requestPDU), 9);
                break;
            }
            case rejectReason_type_conclude_responsePDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_conclude_responsePDU), 10);
                break;
            }
            case rejectReason_type_conclude_errorPDU:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, rejectReason_type_conclude_errorPDU), 11);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void RejectPDU::rejectReason_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_confirmed_requestPDU), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_confirmed_responsePDU), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_confirmed_errorPDU), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_unconfirmedPDU), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_pdu_error), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_cancel_requestPDU), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_cancel_responsePDU), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_cancel_errorPDU), 8)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_conclude_requestPDU), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_conclude_responsePDU), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, rejectReason_type_conclude_errorPDU), 11)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void RejectPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(originalInvokeID_, 0);
        ITU_T_BIND_CHOICE(rejectReason_);
    }

    template<> void RejectPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(originalInvokeID_, 0);
        ITU_T_BIND_CHOICE(rejectReason_);
    }

    boost::shared_ptr<Unsigned32> RejectPDU::originalInvokeID__new() {
        return originalInvokeID_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void RejectPDU::originalInvokeID(const Unsigned32& vl) {
        originalInvokeID_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    RejectPDU::rejectReason_type& RejectPDU::rejectReason() {
        return *rejectReason_;
    }

    const RejectPDU::rejectReason_type& RejectPDU::rejectReason() const {
        return *rejectReason_;
    }

    void RejectPDU::rejectReason(const rejectReason_type& vl) {
        rejectReason_ = vl;
    }

    void RejectPDU::rejectReason(boost::shared_ptr< rejectReason_type> vl) {
        rejectReason_ = vl;
    }


    // sequence DefineAccessControlList-Request

    DefineAccessControlList_Request::DefineAccessControlList_Request() : accessControlListName_(), accessControlListElements_() {
    };

    DefineAccessControlList_Request::DefineAccessControlList_Request(const Identifier& arg__accessControlListName,
            const accessControlListElements_type& arg__accessControlListElements) :
    accessControlListName_(arg__accessControlListName),
    accessControlListElements_(arg__accessControlListElements) {
    };

    DefineAccessControlList_Request::accessControlListElements_type::accessControlListElements_type() {
    };

    DefineAccessControlList_Request::accessControlListElements_type::accessControlListElements_type(boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition) :
    readAccessCondition_(arg__readAccessCondition),
    storeAccessCondition_(arg__storeAccessCondition),
    writeAccessCondition_(arg__writeAccessCondition),
    loadAccessCondition_(arg__loadAccessCondition),
    executeAccessCondition_(arg__executeAccessCondition),
    deleteAccessCondition_(arg__deleteAccessCondition),
    editAccessCondition_(arg__editAccessCondition) {
    };

    template<> void DefineAccessControlList_Request::accessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    template<> void DefineAccessControlList_Request::accessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::readAccessCondition__new() {
        return readAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::readAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        readAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::storeAccessCondition__new() {
        return storeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::storeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        storeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::writeAccessCondition__new() {
        return writeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::writeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        writeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::loadAccessCondition__new() {
        return loadAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::loadAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        loadAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::executeAccessCondition__new() {
        return executeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::executeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        executeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::deleteAccessCondition__new() {
        return deleteAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::deleteAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        deleteAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> DefineAccessControlList_Request::accessControlListElements_type::editAccessCondition__new() {
        return editAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void DefineAccessControlList_Request::accessControlListElements_type::editAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        editAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(accessControlListName_, 0);
        ITU_T_IMPLICIT_TAG(accessControlListElements_, 1);
    }

    template<> void DefineAccessControlList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(accessControlListName_, 0);
        ITU_T_IMPLICIT_TAG(accessControlListElements_, 1);
    }

    Identifier& DefineAccessControlList_Request::accessControlListName() {
        return *accessControlListName_;
    }

    const Identifier& DefineAccessControlList_Request::accessControlListName() const {
        return *accessControlListName_;
    }

    void DefineAccessControlList_Request::accessControlListName(const Identifier& vl) {
        accessControlListName_ = vl;
    }

    void DefineAccessControlList_Request::accessControlListName(boost::shared_ptr< Identifier> vl) {
        accessControlListName_ = vl;
    }

    DefineAccessControlList_Request::accessControlListElements_type& DefineAccessControlList_Request::accessControlListElements() {
        return *accessControlListElements_;
    }

    const DefineAccessControlList_Request::accessControlListElements_type& DefineAccessControlList_Request::accessControlListElements() const {
        return *accessControlListElements_;
    }

    void DefineAccessControlList_Request::accessControlListElements(const accessControlListElements_type& vl) {
        accessControlListElements_ = vl;
    }

    void DefineAccessControlList_Request::accessControlListElements(boost::shared_ptr< accessControlListElements_type> vl) {
        accessControlListElements_ = vl;
    }


    // choice GetAccessControlListAttributes-Request

    GetAccessControlListAttributes_Request::namedObject_type::namedObject_type() : objectClass_(), objectName_() {
    };

    GetAccessControlListAttributes_Request::namedObject_type::namedObject_type(const ObjectClass& arg__objectClass,
            const ObjectName& arg__objectName) :
    objectClass_(arg__objectClass),
    objectName_(arg__objectName) {
    };

    template<> void GetAccessControlListAttributes_Request::namedObject_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(objectName_, 1);
    }

    template<> void GetAccessControlListAttributes_Request::namedObject_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(objectName_, 1);
    }

    ObjectClass& GetAccessControlListAttributes_Request::namedObject_type::objectClass() {
        return *objectClass_;
    }

    const ObjectClass& GetAccessControlListAttributes_Request::namedObject_type::objectClass() const {
        return *objectClass_;
    }

    void GetAccessControlListAttributes_Request::namedObject_type::objectClass(const ObjectClass& vl) {
        objectClass_ = vl;
    }

    void GetAccessControlListAttributes_Request::namedObject_type::objectClass(boost::shared_ptr< ObjectClass> vl) {
        objectClass_ = vl;
    }

    ObjectName& GetAccessControlListAttributes_Request::namedObject_type::objectName() {
        return *objectName_;
    }

    const ObjectName& GetAccessControlListAttributes_Request::namedObject_type::objectName() const {
        return *objectName_;
    }

    void GetAccessControlListAttributes_Request::namedObject_type::objectName(const ObjectName& vl) {
        objectName_ = vl;
    }

    void GetAccessControlListAttributes_Request::namedObject_type::objectName(boost::shared_ptr< ObjectName> vl) {
        objectName_ = vl;
    }

    void GetAccessControlListAttributes_Request::accessControlListName(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), GetAccessControlListAttributes_Request_accessControlListName);
    }

    void GetAccessControlListAttributes_Request::vMD(const null_type& vl) {
        set<null_type>(new null_type(vl), GetAccessControlListAttributes_Request_vMD);
    }

    template<> void GetAccessControlListAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case GetAccessControlListAttributes_Request_accessControlListName:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, GetAccessControlListAttributes_Request_accessControlListName), 0);
                break;
            }
            case GetAccessControlListAttributes_Request_vMD:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, GetAccessControlListAttributes_Request_vMD), 1);
                break;
            }
            case GetAccessControlListAttributes_Request_namedObject:
            {
                ITU_T_IMPLICIT_TAG(value<namedObject_type > (false, GetAccessControlListAttributes_Request_namedObject), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, GetAccessControlListAttributes_Request_accessControlListName), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, GetAccessControlListAttributes_Request_vMD), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<namedObject_type > (true, GetAccessControlListAttributes_Request_namedObject), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    // sequence GetAccessControlListAttributes-Response

    GetAccessControlListAttributes_Response::GetAccessControlListAttributes_Response() : name_(), accessControlListElements_(), vMDuse_(), references_() {
    };

    GetAccessControlListAttributes_Response::GetAccessControlListAttributes_Response(const Identifier& arg__name,
            const accessControlListElements_type& arg__accessControlListElements,
            const bool& arg__vMDuse,
            const references_type& arg__references) :
    name_(arg__name),
    accessControlListElements_(arg__accessControlListElements),
    vMDuse_(arg__vMDuse),
    references_(arg__references) {
    };

    GetAccessControlListAttributes_Response::GetAccessControlListAttributes_Response(boost::shared_ptr< Identifier> arg__name,
            boost::shared_ptr< accessControlListElements_type> arg__accessControlListElements,
            boost::shared_ptr< bool> arg__vMDuse,
            boost::shared_ptr< references_type> arg__references,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    name_(arg__name),
    accessControlListElements_(arg__accessControlListElements),
    vMDuse_(arg__vMDuse),
    references_(arg__references),
    accessControlList_(arg__accessControlList) {
    };

    GetAccessControlListAttributes_Response::accessControlListElements_type::accessControlListElements_type() {
    };

    GetAccessControlListAttributes_Response::accessControlListElements_type::accessControlListElements_type(boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
            boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition) :
    readAccessCondition_(arg__readAccessCondition),
    storeAccessCondition_(arg__storeAccessCondition),
    writeAccessCondition_(arg__writeAccessCondition),
    loadAccessCondition_(arg__loadAccessCondition),
    executeAccessCondition_(arg__executeAccessCondition),
    deleteAccessCondition_(arg__deleteAccessCondition),
    editAccessCondition_(arg__editAccessCondition) {
    };

    template<> void GetAccessControlListAttributes_Response::accessControlListElements_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    template<> void GetAccessControlListAttributes_Response::accessControlListElements_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(readAccessCondition_, 0);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 1);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 2);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 3);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 4);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 5);
        ITU_T_CHOICE_TAG(editAccessCondition_, 6);
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::readAccessCondition__new() {
        return readAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::readAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        readAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::storeAccessCondition__new() {
        return storeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::storeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        storeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::writeAccessCondition__new() {
        return writeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::writeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        writeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::loadAccessCondition__new() {
        return loadAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::loadAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        loadAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::executeAccessCondition__new() {
        return executeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::executeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        executeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::deleteAccessCondition__new() {
        return deleteAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::deleteAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        deleteAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> GetAccessControlListAttributes_Response::accessControlListElements_type::editAccessCondition__new() {
        return editAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void GetAccessControlListAttributes_Response::accessControlListElements_type::editAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        editAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    GetAccessControlListAttributes_Response::references_type_sequence_of::references_type_sequence_of() : objectClass_(), objectCount_() {
    };

    GetAccessControlListAttributes_Response::references_type_sequence_of::references_type_sequence_of(const ObjectClass& arg__objectClass,
            const int& arg__objectCount) :
    objectClass_(arg__objectClass),
    objectCount_(arg__objectCount) {
    };

    template<> void GetAccessControlListAttributes_Response::references_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_IMPLICIT_TAG(objectCount_, 1);
    }

    template<> void GetAccessControlListAttributes_Response::references_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_IMPLICIT_TAG(objectCount_, 1);
    }

    ObjectClass& GetAccessControlListAttributes_Response::references_type_sequence_of::objectClass() {
        return *objectClass_;
    }

    const ObjectClass& GetAccessControlListAttributes_Response::references_type_sequence_of::objectClass() const {
        return *objectClass_;
    }

    void GetAccessControlListAttributes_Response::references_type_sequence_of::objectClass(const ObjectClass& vl) {
        objectClass_ = vl;
    }

    void GetAccessControlListAttributes_Response::references_type_sequence_of::objectClass(boost::shared_ptr< ObjectClass> vl) {
        objectClass_ = vl;
    }

    int& GetAccessControlListAttributes_Response::references_type_sequence_of::objectCount() {
        return *objectCount_;
    }

    const int& GetAccessControlListAttributes_Response::references_type_sequence_of::objectCount() const {
        return *objectCount_;
    }

    void GetAccessControlListAttributes_Response::references_type_sequence_of::objectCount(const int& vl) {
        objectCount_ = vl;
    }

    void GetAccessControlListAttributes_Response::references_type_sequence_of::objectCount(boost::shared_ptr< int> vl) {
        objectCount_ = vl;
    }

    template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(name_, 0);
        ITU_T_IMPLICIT_TAG(accessControlListElements_, 1);
        ITU_T_IMPLICIT_TAG(vMDuse_, 2);
        ITU_T_IMPLICIT_TAG(references_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    template<> void GetAccessControlListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(name_, 0);
        ITU_T_IMPLICIT_TAG(accessControlListElements_, 1);
        ITU_T_IMPLICIT_TAG(vMDuse_, 2);
        ITU_T_IMPLICIT_TAG(references_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    Identifier& GetAccessControlListAttributes_Response::name() {
        return *name_;
    }

    const Identifier& GetAccessControlListAttributes_Response::name() const {
        return *name_;
    }

    void GetAccessControlListAttributes_Response::name(const Identifier& vl) {
        name_ = vl;
    }

    void GetAccessControlListAttributes_Response::name(boost::shared_ptr< Identifier> vl) {
        name_ = vl;
    }

    GetAccessControlListAttributes_Response::accessControlListElements_type& GetAccessControlListAttributes_Response::accessControlListElements() {
        return *accessControlListElements_;
    }

    const GetAccessControlListAttributes_Response::accessControlListElements_type& GetAccessControlListAttributes_Response::accessControlListElements() const {
        return *accessControlListElements_;
    }

    void GetAccessControlListAttributes_Response::accessControlListElements(const accessControlListElements_type& vl) {
        accessControlListElements_ = vl;
    }

    void GetAccessControlListAttributes_Response::accessControlListElements(boost::shared_ptr< accessControlListElements_type> vl) {
        accessControlListElements_ = vl;
    }

    bool& GetAccessControlListAttributes_Response::vMDuse() {
        return *vMDuse_;
    }

    const bool& GetAccessControlListAttributes_Response::vMDuse() const {
        return *vMDuse_;
    }

    void GetAccessControlListAttributes_Response::vMDuse(const bool& vl) {
        vMDuse_ = vl;
    }

    void GetAccessControlListAttributes_Response::vMDuse(boost::shared_ptr< bool> vl) {
        vMDuse_ = vl;
    }

    GetAccessControlListAttributes_Response::references_type& GetAccessControlListAttributes_Response::references() {
        return *references_;
    }

    const GetAccessControlListAttributes_Response::references_type& GetAccessControlListAttributes_Response::references() const {
        return *references_;
    }

    void GetAccessControlListAttributes_Response::references(const references_type& vl) {
        references_ = vl;
    }

    void GetAccessControlListAttributes_Response::references(boost::shared_ptr< references_type> vl) {
        references_ = vl;
    }

    boost::shared_ptr<Identifier> GetAccessControlListAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetAccessControlListAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence ReportAccessControlledObjects-Request

    ReportAccessControlledObjects_Request::ReportAccessControlledObjects_Request() : accessControlList_(), objectClass_() {
    };

    ReportAccessControlledObjects_Request::ReportAccessControlledObjects_Request(const Identifier& arg__accessControlList,
            const ObjectClass& arg__objectClass) :
    accessControlList_(arg__accessControlList),
    objectClass_(arg__objectClass) {
    };

    ReportAccessControlledObjects_Request::ReportAccessControlledObjects_Request(boost::shared_ptr< Identifier> arg__accessControlList,
            boost::shared_ptr< ObjectClass> arg__objectClass,
            boost::shared_ptr< ObjectName> arg__continueAfter) :
    accessControlList_(arg__accessControlList),
    objectClass_(arg__objectClass),
    continueAfter_(arg__continueAfter) {
    };

    template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(accessControlList_, 0);
        ITU_T_CHOICE_TAG(objectClass_, 1);
        ITU_T_CHOICE_TAG(continueAfter_, 2);
    }

    template<> void ReportAccessControlledObjects_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(accessControlList_, 0);
        ITU_T_CHOICE_TAG(objectClass_, 1);
        ITU_T_CHOICE_TAG(continueAfter_, 2);
    }

    Identifier& ReportAccessControlledObjects_Request::accessControlList() {
        return *accessControlList_;
    }

    const Identifier& ReportAccessControlledObjects_Request::accessControlList() const {
        return *accessControlList_;
    }

    void ReportAccessControlledObjects_Request::accessControlList(const Identifier& vl) {
        accessControlList_ = vl;
    }

    void ReportAccessControlledObjects_Request::accessControlList(boost::shared_ptr< Identifier> vl) {
        accessControlList_ = vl;
    }

    ObjectClass& ReportAccessControlledObjects_Request::objectClass() {
        return *objectClass_;
    }

    const ObjectClass& ReportAccessControlledObjects_Request::objectClass() const {
        return *objectClass_;
    }

    void ReportAccessControlledObjects_Request::objectClass(const ObjectClass& vl) {
        objectClass_ = vl;
    }

    void ReportAccessControlledObjects_Request::objectClass(boost::shared_ptr< ObjectClass> vl) {
        objectClass_ = vl;
    }

    boost::shared_ptr<ObjectName> ReportAccessControlledObjects_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void ReportAccessControlledObjects_Request::continueAfter(const ObjectName& vl) {
        continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }


    // sequence ReportAccessControlledObjects-Response

    ReportAccessControlledObjects_Response::ReportAccessControlledObjects_Response() : listOfNames_() {
    };

    ReportAccessControlledObjects_Response::ReportAccessControlledObjects_Response(const listOfNames_type& arg__listOfNames) :
    listOfNames_(arg__listOfNames) {
    };

    ReportAccessControlledObjects_Response::ReportAccessControlledObjects_Response(boost::shared_ptr< listOfNames_type> arg__listOfNames,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfNames_(arg__listOfNames),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReportAccessControlledObjects_Response::moreFollows__default = false;

    template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfNames_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReportAccessControlledObjects_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfNames_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    ReportAccessControlledObjects_Response::listOfNames_type& ReportAccessControlledObjects_Response::listOfNames() {
        return *listOfNames_;
    }

    const ReportAccessControlledObjects_Response::listOfNames_type& ReportAccessControlledObjects_Response::listOfNames() const {
        return *listOfNames_;
    }

    void ReportAccessControlledObjects_Response::listOfNames(const listOfNames_type& vl) {
        listOfNames_ = vl;
    }

    void ReportAccessControlledObjects_Response::listOfNames(boost::shared_ptr< listOfNames_type> vl) {
        listOfNames_ = vl;
    }

    const bool& ReportAccessControlledObjects_Response::moreFollows() const {
        return *moreFollows_;
    }

    void ReportAccessControlledObjects_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void ReportAccessControlledObjects_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence ChangeAccessControl-Request

    ChangeAccessControl_Request::ChangeAccessControl_Request() : scopeOfChange_(), accessControlListName_() {
    };

    ChangeAccessControl_Request::ChangeAccessControl_Request(const scopeOfChange_type& arg__scopeOfChange,
            const Identifier& arg__accessControlListName) :
    scopeOfChange_(arg__scopeOfChange),
    accessControlListName_(arg__accessControlListName) {
    };

    ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::listOfObjects_type() : objectClass_(), objectScope_() {
    };

    ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::listOfObjects_type(const ObjectClass& arg__objectClass,
            const objectScope_type& arg__objectScope) :
    objectClass_(arg__objectClass),
    objectScope_(arg__objectScope) {
    };

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::aa_specific(const null_type& vl) {
        set<null_type>(new null_type(vl), objectScope_type_aa_specific);
    }

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), objectScope_type_domain);
    }

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::vmd(const null_type& vl) {
        set<null_type>(new null_type(vl), objectScope_type_vmd);
    }

    template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case objectScope_type_specific:
            {
                ITU_T_IMPLICIT_TAG(value<specific_type > (false, objectScope_type_specific), 0);
                break;
            }
            case objectScope_type_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, objectScope_type_aa_specific), 1);
                break;
            }
            case objectScope_type_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, objectScope_type_domain), 2);
                break;
            }
            case objectScope_type_vmd:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, objectScope_type_vmd), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<specific_type > (true, objectScope_type_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, objectScope_type_aa_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, objectScope_type_domain), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, objectScope_type_vmd), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(objectScope_, 1);
    }

    template<> void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(objectScope_, 1);
    }

    ObjectClass& ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectClass() {
        return *objectClass_;
    }

    const ObjectClass& ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectClass() const {
        return *objectClass_;
    }

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectClass(const ObjectClass& vl) {
        objectClass_ = vl;
    }

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectClass(boost::shared_ptr< ObjectClass> vl) {
        objectClass_ = vl;
    }

    ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type& ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope() {
        return *objectScope_;
    }

    const ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope_type& ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope() const {
        return *objectScope_;
    }

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope(const objectScope_type& vl) {
        objectScope_ = vl;
    }

    void ChangeAccessControl_Request::scopeOfChange_type::listOfObjects_type::objectScope(boost::shared_ptr< objectScope_type> vl) {
        objectScope_ = vl;
    }

    void ChangeAccessControl_Request::scopeOfChange_type::vMDOnly(const null_type& vl) {
        set<null_type>(new null_type(vl), scopeOfChange_type_vMDOnly);
    }

    template<> void ChangeAccessControl_Request::scopeOfChange_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case scopeOfChange_type_vMDOnly:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, scopeOfChange_type_vMDOnly), 0);
                break;
            }
            case scopeOfChange_type_listOfObjects:
            {
                ITU_T_IMPLICIT_TAG(value<listOfObjects_type > (false, scopeOfChange_type_listOfObjects), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ChangeAccessControl_Request::scopeOfChange_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, scopeOfChange_type_vMDOnly), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<listOfObjects_type > (true, scopeOfChange_type_listOfObjects), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(scopeOfChange_);
        ITU_T_IMPLICIT_TAG(accessControlListName_, 2);
    }

    template<> void ChangeAccessControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(scopeOfChange_);
        ITU_T_IMPLICIT_TAG(accessControlListName_, 2);
    }

    ChangeAccessControl_Request::scopeOfChange_type& ChangeAccessControl_Request::scopeOfChange() {
        return *scopeOfChange_;
    }

    const ChangeAccessControl_Request::scopeOfChange_type& ChangeAccessControl_Request::scopeOfChange() const {
        return *scopeOfChange_;
    }

    void ChangeAccessControl_Request::scopeOfChange(const scopeOfChange_type& vl) {
        scopeOfChange_ = vl;
    }

    void ChangeAccessControl_Request::scopeOfChange(boost::shared_ptr< scopeOfChange_type> vl) {
        scopeOfChange_ = vl;
    }

    Identifier& ChangeAccessControl_Request::accessControlListName() {
        return *accessControlListName_;
    }

    const Identifier& ChangeAccessControl_Request::accessControlListName() const {
        return *accessControlListName_;
    }

    void ChangeAccessControl_Request::accessControlListName(const Identifier& vl) {
        accessControlListName_ = vl;
    }

    void ChangeAccessControl_Request::accessControlListName(boost::shared_ptr< Identifier> vl) {
        accessControlListName_ = vl;
    }


    // sequence ChangeAccessControl-Response

    ChangeAccessControl_Response::ChangeAccessControl_Response() : numberMatched_(), numberChanged_() {
    };

    ChangeAccessControl_Response::ChangeAccessControl_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberChanged) :
    numberMatched_(arg__numberMatched),
    numberChanged_(arg__numberChanged) {
    };

    template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberChanged_, 1);
    }

    template<> void ChangeAccessControl_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberChanged_, 1);
    }

    Unsigned32& ChangeAccessControl_Response::numberMatched() {
        return *numberMatched_;
    }

    const Unsigned32& ChangeAccessControl_Response::numberMatched() const {
        return *numberMatched_;
    }

    void ChangeAccessControl_Response::numberMatched(const Unsigned32& vl) {
        numberMatched_ = vl;
    }

    void ChangeAccessControl_Response::numberMatched(boost::shared_ptr< Unsigned32> vl) {
        numberMatched_ = vl;
    }

    Unsigned32& ChangeAccessControl_Response::numberChanged() {
        return *numberChanged_;
    }

    const Unsigned32& ChangeAccessControl_Response::numberChanged() const {
        return *numberChanged_;
    }

    void ChangeAccessControl_Response::numberChanged(const Unsigned32& vl) {
        numberChanged_ = vl;
    }

    void ChangeAccessControl_Response::numberChanged(boost::shared_ptr< Unsigned32> vl) {
        numberChanged_ = vl;
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

    StatusResponse::StatusResponse() : vmdLogicalStatus_(), vmdPhysicalStatus_() {
    };

    StatusResponse::StatusResponse(const int& arg__vmdLogicalStatus,
            const int& arg__vmdPhysicalStatus) :
    vmdLogicalStatus_(arg__vmdLogicalStatus),
    vmdPhysicalStatus_(arg__vmdPhysicalStatus) {
    };

    StatusResponse::StatusResponse(boost::shared_ptr< int> arg__vmdLogicalStatus,
            boost::shared_ptr< int> arg__vmdPhysicalStatus,
            boost::shared_ptr< bitstring_type> arg__localDetail) :
    vmdLogicalStatus_(arg__vmdLogicalStatus),
    vmdPhysicalStatus_(arg__vmdPhysicalStatus),
    localDetail_(arg__localDetail) {
    };

    template<> void StatusResponse::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(vmdLogicalStatus_, 0);
        ITU_T_IMPLICIT_TAG(vmdPhysicalStatus_, 1);
        ITU_T_IMPLICIT_TAG(localDetail_, 2);
    }

    template<> void StatusResponse::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(vmdLogicalStatus_, 0);
        ITU_T_IMPLICIT_TAG(vmdPhysicalStatus_, 1);
        ITU_T_IMPLICIT_TAG(localDetail_, 2);
    }

    int& StatusResponse::vmdLogicalStatus() {
        return *vmdLogicalStatus_;
    }

    const int& StatusResponse::vmdLogicalStatus() const {
        return *vmdLogicalStatus_;
    }

    void StatusResponse::vmdLogicalStatus(const int& vl) {
        vmdLogicalStatus_ = vl;
    }

    void StatusResponse::vmdLogicalStatus(boost::shared_ptr< int> vl) {
        vmdLogicalStatus_ = vl;
    }

    int& StatusResponse::vmdPhysicalStatus() {
        return *vmdPhysicalStatus_;
    }

    const int& StatusResponse::vmdPhysicalStatus() const {
        return *vmdPhysicalStatus_;
    }

    void StatusResponse::vmdPhysicalStatus(const int& vl) {
        vmdPhysicalStatus_ = vl;
    }

    void StatusResponse::vmdPhysicalStatus(boost::shared_ptr< int> vl) {
        vmdPhysicalStatus_ = vl;
    }

    boost::shared_ptr<bitstring_type> StatusResponse::localDetail__new() {
        return localDetail_ = boost::shared_ptr<bitstring_type>(new bitstring_type());
    }

    void StatusResponse::localDetail(const bitstring_type& vl) {
        localDetail_ = boost::shared_ptr<bitstring_type>(new bitstring_type(vl));
    }


    // choice CS-Status-Response

    CS_Status_Response::fullResponse_type::fullResponse_type() : operationState_(), extendedStatus_(), selectedProgramInvocation_() {
    };

    CS_Status_Response::fullResponse_type::fullResponse_type(const OperationState& arg__operationState,
            const ExtendedStatus& arg__extendedStatus,
            const selectedProgramInvocation_type& arg__selectedProgramInvocation) :
    operationState_(arg__operationState),
    extendedStatus_(arg__extendedStatus),
    selectedProgramInvocation_(arg__selectedProgramInvocation) {
    };

    CS_Status_Response::fullResponse_type::fullResponse_type(boost::shared_ptr< OperationState> arg__operationState,
            boost::shared_ptr< ExtendedStatus> arg__extendedStatus,
            boost::shared_ptr< ExtendedStatus> arg__extendedStatusMask,
            boost::shared_ptr< selectedProgramInvocation_type> arg__selectedProgramInvocation) :
    operationState_(arg__operationState),
    extendedStatus_(arg__extendedStatus),
    extendedStatusMask_(arg__extendedStatusMask),
    selectedProgramInvocation_(arg__selectedProgramInvocation) {
    };

    void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::programInvocation(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), selectedProgramInvocation_type_programInvocation);
    }

    void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::noneSelected(const null_type& vl) {
        set<null_type>(new null_type(vl), selectedProgramInvocation_type_noneSelected);
    }

    template<> void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case selectedProgramInvocation_type_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, selectedProgramInvocation_type_programInvocation), 3);
                break;
            }
            case selectedProgramInvocation_type_noneSelected:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, selectedProgramInvocation_type_noneSelected), 4);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Status_Response::fullResponse_type::selectedProgramInvocation_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, selectedProgramInvocation_type_programInvocation), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, selectedProgramInvocation_type_noneSelected), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    const ExtendedStatus CS_Status_Response::fullResponse_type::extendedStatusMask__default = ExtendedStatus(boost::asn1::bitstring_type(static_cast<uint8_t> (15), 4));

    template<> void CS_Status_Response::fullResponse_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(operationState_, 0);
        ITU_T_IMPLICIT_TAG(extendedStatus_, 1);
        ITU_T_IMPLICIT_TAG(extendedStatusMask_, 2);
        ITU_T_BIND_CHOICE(selectedProgramInvocation_);
    }

    template<> void CS_Status_Response::fullResponse_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(operationState_, 0);
        ITU_T_IMPLICIT_TAG(extendedStatus_, 1);
        ITU_T_IMPLICIT_TAG(extendedStatusMask_, 2);
        ITU_T_BIND_CHOICE(selectedProgramInvocation_);
    }

    OperationState& CS_Status_Response::fullResponse_type::operationState() {
        return *operationState_;
    }

    const OperationState& CS_Status_Response::fullResponse_type::operationState() const {
        return *operationState_;
    }

    void CS_Status_Response::fullResponse_type::operationState(const OperationState& vl) {
        operationState_ = vl;
    }

    void CS_Status_Response::fullResponse_type::operationState(boost::shared_ptr< OperationState> vl) {
        operationState_ = vl;
    }

    ExtendedStatus& CS_Status_Response::fullResponse_type::extendedStatus() {
        return *extendedStatus_;
    }

    const ExtendedStatus& CS_Status_Response::fullResponse_type::extendedStatus() const {
        return *extendedStatus_;
    }

    void CS_Status_Response::fullResponse_type::extendedStatus(const ExtendedStatus& vl) {
        extendedStatus_ = vl;
    }

    void CS_Status_Response::fullResponse_type::extendedStatus(boost::shared_ptr< ExtendedStatus> vl) {
        extendedStatus_ = vl;
    }

    const ExtendedStatus& CS_Status_Response::fullResponse_type::extendedStatusMask() const {
        return *extendedStatusMask_;
    }

    void CS_Status_Response::fullResponse_type::extendedStatusMask(const ExtendedStatus& vl) {
        extendedStatusMask_ = vl;
    }

    void CS_Status_Response::fullResponse_type::extendedStatusMask(boost::shared_ptr< ExtendedStatus> vl) {
        extendedStatusMask_ = vl;
    }

    CS_Status_Response::fullResponse_type::selectedProgramInvocation_type& CS_Status_Response::fullResponse_type::selectedProgramInvocation() {
        return *selectedProgramInvocation_;
    }

    const CS_Status_Response::fullResponse_type::selectedProgramInvocation_type& CS_Status_Response::fullResponse_type::selectedProgramInvocation() const {
        return *selectedProgramInvocation_;
    }

    void CS_Status_Response::fullResponse_type::selectedProgramInvocation(const selectedProgramInvocation_type& vl) {
        selectedProgramInvocation_ = vl;
    }

    void CS_Status_Response::fullResponse_type::selectedProgramInvocation(boost::shared_ptr< selectedProgramInvocation_type> vl) {
        selectedProgramInvocation_ = vl;
    }

    void CS_Status_Response::noExtraResponse(const null_type& vl) {
        set<null_type>(new null_type(vl), CS_Status_Response_noExtraResponse);
    }

    template<> void CS_Status_Response::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_Status_Response_fullResponse:
            {
                ITU_T_BIND_TAG(value<fullResponse_type > (false, CS_Status_Response_fullResponse));
                break;
            }
            case CS_Status_Response_noExtraResponse:
            {
                ITU_T_BIND_TAG(value<null_type > (false, CS_Status_Response_noExtraResponse));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Status_Response::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<fullResponse_type > (true, CS_Status_Response_fullResponse))) return;
                else free();
                if (ITU_T_BIND_TAG(value<null_type > (true, CS_Status_Response_noExtraResponse))) return;
                else free();
            }
        }
    }


    const OperationState OperationState_idle = 0;
    const OperationState OperationState_loaded = 1;
    const OperationState OperationState_ready = 2;
    const OperationState OperationState_executing = 3;
    const OperationState OperationState_motion_paused = 4;
    const OperationState OperationState_manualInterventionRequired = 5;

    const ExtendedStatus ExtendedStatus_safetyInterlocksViolated = bitstring_type(true, 0);
    const ExtendedStatus ExtendedStatus_anyPhysicalResourcePowerOn = bitstring_type(true, 1);
    const ExtendedStatus ExtendedStatus_allPhysicalResourcesCalibrated = bitstring_type(true, 2);
    const ExtendedStatus ExtendedStatus_localControl = bitstring_type(true, 3);

    // sequence GetNameList-Request

    GetNameList_Request::GetNameList_Request() : objectClass_(), objectScope_() {
    };

    GetNameList_Request::GetNameList_Request(const ObjectClass& arg__objectClass,
            const objectScope_type& arg__objectScope) :
    objectClass_(arg__objectClass),
    objectScope_(arg__objectScope) {
    };

    GetNameList_Request::GetNameList_Request(boost::shared_ptr< ObjectClass> arg__objectClass,
            boost::shared_ptr< objectScope_type> arg__objectScope,
            boost::shared_ptr< Identifier> arg__continueAfter) :
    objectClass_(arg__objectClass),
    objectScope_(arg__objectScope),
    continueAfter_(arg__continueAfter) {
    };

    void GetNameList_Request::objectScope_type::vmdSpecific(const null_type& vl) {
        set<null_type>(new null_type(vl), objectScope_type_vmdSpecific);
    }

    void GetNameList_Request::objectScope_type::domainSpecific(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), objectScope_type_domainSpecific);
    }

    void GetNameList_Request::objectScope_type::aaSpecific(const null_type& vl) {
        set<null_type>(new null_type(vl), objectScope_type_aaSpecific);
    }

    template<> void GetNameList_Request::objectScope_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case objectScope_type_vmdSpecific:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, objectScope_type_vmdSpecific), 0);
                break;
            }
            case objectScope_type_domainSpecific:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, objectScope_type_domainSpecific), 1);
                break;
            }
            case objectScope_type_aaSpecific:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, objectScope_type_aaSpecific), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetNameList_Request::objectScope_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, objectScope_type_vmdSpecific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, objectScope_type_domainSpecific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, objectScope_type_aaSpecific), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void GetNameList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(objectScope_, 1);
        ITU_T_IMPLICIT_TAG(continueAfter_, 2);
    }

    template<> void GetNameList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(objectScope_, 1);
        ITU_T_IMPLICIT_TAG(continueAfter_, 2);
    }

    ObjectClass& GetNameList_Request::objectClass() {
        return *objectClass_;
    }

    const ObjectClass& GetNameList_Request::objectClass() const {
        return *objectClass_;
    }

    void GetNameList_Request::objectClass(const ObjectClass& vl) {
        objectClass_ = vl;
    }

    void GetNameList_Request::objectClass(boost::shared_ptr< ObjectClass> vl) {
        objectClass_ = vl;
    }

    GetNameList_Request::objectScope_type& GetNameList_Request::objectScope() {
        return *objectScope_;
    }

    const GetNameList_Request::objectScope_type& GetNameList_Request::objectScope() const {
        return *objectScope_;
    }

    void GetNameList_Request::objectScope(const objectScope_type& vl) {
        objectScope_ = vl;
    }

    void GetNameList_Request::objectScope(boost::shared_ptr< objectScope_type> vl) {
        objectScope_ = vl;
    }

    boost::shared_ptr<Identifier> GetNameList_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetNameList_Request::continueAfter(const Identifier& vl) {
        continueAfter_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence GetNameList-Response

    GetNameList_Response::GetNameList_Response() : listOfIdentifier_() {
    };

    GetNameList_Response::GetNameList_Response(const listOfIdentifier_type& arg__listOfIdentifier) :
    listOfIdentifier_(arg__listOfIdentifier) {
    };

    GetNameList_Response::GetNameList_Response(boost::shared_ptr< listOfIdentifier_type> arg__listOfIdentifier,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfIdentifier_(arg__listOfIdentifier),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetNameList_Response::moreFollows__default = true;

    template<> void GetNameList_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfIdentifier_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetNameList_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfIdentifier_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    GetNameList_Response::listOfIdentifier_type& GetNameList_Response::listOfIdentifier() {
        return *listOfIdentifier_;
    }

    const GetNameList_Response::listOfIdentifier_type& GetNameList_Response::listOfIdentifier() const {
        return *listOfIdentifier_;
    }

    void GetNameList_Response::listOfIdentifier(const listOfIdentifier_type& vl) {
        listOfIdentifier_ = vl;
    }

    void GetNameList_Response::listOfIdentifier(boost::shared_ptr< listOfIdentifier_type> vl) {
        listOfIdentifier_ = vl;
    }

    const bool& GetNameList_Response::moreFollows() const {
        return *moreFollows_;
    }

    void GetNameList_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void GetNameList_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


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

    Identify_Response::Identify_Response(boost::shared_ptr< MMSString> arg__vendorName,
            boost::shared_ptr< MMSString> arg__modelName,
            boost::shared_ptr< MMSString> arg__revision,
            boost::shared_ptr< listOfAbstractSyntaxes_type> arg__listOfAbstractSyntaxes) :
    vendorName_(arg__vendorName),
    modelName_(arg__modelName),
    revision_(arg__revision),
    listOfAbstractSyntaxes_(arg__listOfAbstractSyntaxes) {
    };

    template<> void Identify_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(vendorName_, 0);
        ITU_T_IMPLICIT_TAG(modelName_, 1);
        ITU_T_IMPLICIT_TAG(revision_, 2);
        ITU_T_IMPLICIT_TAG(listOfAbstractSyntaxes_, 3);
    }

    template<> void Identify_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(vendorName_, 0);
        ITU_T_IMPLICIT_TAG(modelName_, 1);
        ITU_T_IMPLICIT_TAG(revision_, 2);
        ITU_T_IMPLICIT_TAG(listOfAbstractSyntaxes_, 3);
    }

    MMSString& Identify_Response::vendorName() {
        return *vendorName_;
    }

    const MMSString& Identify_Response::vendorName() const {
        return *vendorName_;
    }

    void Identify_Response::vendorName(const MMSString& vl) {
        vendorName_ = vl;
    }

    void Identify_Response::vendorName(boost::shared_ptr< MMSString> vl) {
        vendorName_ = vl;
    }

    MMSString& Identify_Response::modelName() {
        return *modelName_;
    }

    const MMSString& Identify_Response::modelName() const {
        return *modelName_;
    }

    void Identify_Response::modelName(const MMSString& vl) {
        modelName_ = vl;
    }

    void Identify_Response::modelName(boost::shared_ptr< MMSString> vl) {
        modelName_ = vl;
    }

    MMSString& Identify_Response::revision() {
        return *revision_;
    }

    const MMSString& Identify_Response::revision() const {
        return *revision_;
    }

    void Identify_Response::revision(const MMSString& vl) {
        revision_ = vl;
    }

    void Identify_Response::revision(boost::shared_ptr< MMSString> vl) {
        revision_ = vl;
    }

    boost::shared_ptr<Identify_Response::listOfAbstractSyntaxes_type> Identify_Response::listOfAbstractSyntaxes__new() {
        return listOfAbstractSyntaxes_ = boost::shared_ptr<listOfAbstractSyntaxes_type>(new listOfAbstractSyntaxes_type());
    }

    void Identify_Response::listOfAbstractSyntaxes(const listOfAbstractSyntaxes_type& vl) {
        listOfAbstractSyntaxes_ = boost::shared_ptr<listOfAbstractSyntaxes_type>(new listOfAbstractSyntaxes_type(vl));
    }


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

    template<> void Rename_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(currentName_, 1);
        ITU_T_IMPLICIT_TAG(newIdentifier_, 2);
    }

    template<> void Rename_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(objectClass_, 0);
        ITU_T_CHOICE_TAG(currentName_, 1);
        ITU_T_IMPLICIT_TAG(newIdentifier_, 2);
    }

    ObjectClass& Rename_Request::objectClass() {
        return *objectClass_;
    }

    const ObjectClass& Rename_Request::objectClass() const {
        return *objectClass_;
    }

    void Rename_Request::objectClass(const ObjectClass& vl) {
        objectClass_ = vl;
    }

    void Rename_Request::objectClass(boost::shared_ptr< ObjectClass> vl) {
        objectClass_ = vl;
    }

    ObjectName& Rename_Request::currentName() {
        return *currentName_;
    }

    const ObjectName& Rename_Request::currentName() const {
        return *currentName_;
    }

    void Rename_Request::currentName(const ObjectName& vl) {
        currentName_ = vl;
    }

    void Rename_Request::currentName(boost::shared_ptr< ObjectName> vl) {
        currentName_ = vl;
    }

    Identifier& Rename_Request::newIdentifier() {
        return *newIdentifier_;
    }

    const Identifier& Rename_Request::newIdentifier() const {
        return *newIdentifier_;
    }

    void Rename_Request::newIdentifier(const Identifier& vl) {
        newIdentifier_ = vl;
    }

    void Rename_Request::newIdentifier(boost::shared_ptr< Identifier> vl) {
        newIdentifier_ = vl;
    }


    // sequence GetCapabilityList-Request

    GetCapabilityList_Request::GetCapabilityList_Request() {
    };

    GetCapabilityList_Request::GetCapabilityList_Request(boost::shared_ptr< MMSString> arg__continueAfter) :
    continueAfter_(arg__continueAfter) {
    };

    template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(continueAfter_);
    }

    template<> void GetCapabilityList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(continueAfter_);
    }

    boost::shared_ptr<MMSString> GetCapabilityList_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<MMSString>(new MMSString());
    }

    void GetCapabilityList_Request::continueAfter(const MMSString& vl) {
        continueAfter_ = boost::shared_ptr<MMSString>(new MMSString(vl));
    }


    // sequence GetCapabilityList-Response

    GetCapabilityList_Response::GetCapabilityList_Response() : listOfCapabilities_() {
    };

    GetCapabilityList_Response::GetCapabilityList_Response(const listOfCapabilities_type& arg__listOfCapabilities) :
    listOfCapabilities_(arg__listOfCapabilities) {
    };

    GetCapabilityList_Response::GetCapabilityList_Response(boost::shared_ptr< listOfCapabilities_type> arg__listOfCapabilities,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfCapabilities_(arg__listOfCapabilities),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetCapabilityList_Response::moreFollows__default = true;

    template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetCapabilityList_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    GetCapabilityList_Response::listOfCapabilities_type& GetCapabilityList_Response::listOfCapabilities() {
        return *listOfCapabilities_;
    }

    const GetCapabilityList_Response::listOfCapabilities_type& GetCapabilityList_Response::listOfCapabilities() const {
        return *listOfCapabilities_;
    }

    void GetCapabilityList_Response::listOfCapabilities(const listOfCapabilities_type& vl) {
        listOfCapabilities_ = vl;
    }

    void GetCapabilityList_Response::listOfCapabilities(boost::shared_ptr< listOfCapabilities_type> vl) {
        listOfCapabilities_ = vl;
    }

    const bool& GetCapabilityList_Response::moreFollows() const {
        return *moreFollows_;
    }

    void GetCapabilityList_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void GetCapabilityList_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence InitiateDownloadSequence-Request

    InitiateDownloadSequence_Request::InitiateDownloadSequence_Request() : domainName_(), listOfCapabilities_(), sharable_() {
    };

    InitiateDownloadSequence_Request::InitiateDownloadSequence_Request(const Identifier& arg__domainName,
            const listOfCapabilities_type& arg__listOfCapabilities,
            const bool& arg__sharable) :
    domainName_(arg__domainName),
    listOfCapabilities_(arg__listOfCapabilities),
    sharable_(arg__sharable) {
    };

    template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(sharable_, 2);
    }

    template<> void InitiateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(sharable_, 2);
    }

    Identifier& InitiateDownloadSequence_Request::domainName() {
        return *domainName_;
    }

    const Identifier& InitiateDownloadSequence_Request::domainName() const {
        return *domainName_;
    }

    void InitiateDownloadSequence_Request::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void InitiateDownloadSequence_Request::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    InitiateDownloadSequence_Request::listOfCapabilities_type& InitiateDownloadSequence_Request::listOfCapabilities() {
        return *listOfCapabilities_;
    }

    const InitiateDownloadSequence_Request::listOfCapabilities_type& InitiateDownloadSequence_Request::listOfCapabilities() const {
        return *listOfCapabilities_;
    }

    void InitiateDownloadSequence_Request::listOfCapabilities(const listOfCapabilities_type& vl) {
        listOfCapabilities_ = vl;
    }

    void InitiateDownloadSequence_Request::listOfCapabilities(boost::shared_ptr< listOfCapabilities_type> vl) {
        listOfCapabilities_ = vl;
    }

    bool& InitiateDownloadSequence_Request::sharable() {
        return *sharable_;
    }

    const bool& InitiateDownloadSequence_Request::sharable() const {
        return *sharable_;
    }

    void InitiateDownloadSequence_Request::sharable(const bool& vl) {
        sharable_ = vl;
    }

    void InitiateDownloadSequence_Request::sharable(boost::shared_ptr< bool> vl) {
        sharable_ = vl;
    }


    // sequence DownloadSegment-Response

    DownloadSegment_Response::DownloadSegment_Response() : loadData_() {
    };

    DownloadSegment_Response::DownloadSegment_Response(const LoadData& arg__loadData) :
    loadData_(arg__loadData) {
    };

    DownloadSegment_Response::DownloadSegment_Response(boost::shared_ptr< LoadData> arg__loadData,
            boost::shared_ptr< bool> arg__moreFollows) :
    loadData_(arg__loadData),
    moreFollows_(arg__moreFollows) {
    };

    const bool DownloadSegment_Response::moreFollows__default = true;

    template<> void DownloadSegment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void DownloadSegment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    LoadData& DownloadSegment_Response::loadData() {
        return *loadData_;
    }

    const LoadData& DownloadSegment_Response::loadData() const {
        return *loadData_;
    }

    void DownloadSegment_Response::loadData(const LoadData& vl) {
        loadData_ = vl;
    }

    void DownloadSegment_Response::loadData(boost::shared_ptr< LoadData> vl) {
        loadData_ = vl;
    }

    const bool& DownloadSegment_Response::moreFollows() const {
        return *moreFollows_;
    }

    void DownloadSegment_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void DownloadSegment_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // choice LoadData

    void LoadData::non_coded(const octetstring_type& vl) {
        set<octetstring_type>(new octetstring_type(vl), LoadData_non_coded);
    }

    void LoadData::coded(const external_type& vl) {
        set<external_type>(new external_type(vl), LoadData_coded);
    }

    void LoadData::embedded(const embeded_type& vl) {
        set<embeded_type>(new embeded_type(vl), LoadData_embedded);
    }

    template<> void LoadData::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case LoadData_non_coded:
            {
                ITU_T_IMPLICIT_TAG(value<octetstring_type > (false, LoadData_non_coded), 0);
                break;
            }
            case LoadData_coded:
            {
                ITU_T_BIND_TAG(value<external_type > (false, LoadData_coded));
                break;
            }
            case LoadData_embedded:
            {
                ITU_T_BIND_TAG(value<embeded_type > (false, LoadData_embedded));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<octetstring_type > (true, LoadData_non_coded), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<external_type > (true, LoadData_coded))) return;
                else free();
                if (ITU_T_BIND_TAG(value<embeded_type > (true, LoadData_embedded))) return;
                else free();
            }
        }
    }


    // sequence TerminateDownloadSequence-Request

    TerminateDownloadSequence_Request::TerminateDownloadSequence_Request() : domainName_() {
    };

    TerminateDownloadSequence_Request::TerminateDownloadSequence_Request(const Identifier& arg__domainName) :
    domainName_(arg__domainName) {
    };

    TerminateDownloadSequence_Request::TerminateDownloadSequence_Request(boost::shared_ptr< Identifier> arg__domainName,
            boost::shared_ptr< ServiceError> arg__discard) :
    domainName_(arg__domainName),
    discard_(arg__discard) {
    };

    template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(discard_, 1);
    }

    template<> void TerminateDownloadSequence_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(discard_, 1);
    }

    Identifier& TerminateDownloadSequence_Request::domainName() {
        return *domainName_;
    }

    const Identifier& TerminateDownloadSequence_Request::domainName() const {
        return *domainName_;
    }

    void TerminateDownloadSequence_Request::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void TerminateDownloadSequence_Request::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    boost::shared_ptr<ServiceError> TerminateDownloadSequence_Request::discard__new() {
        return discard_ = boost::shared_ptr<ServiceError>(new ServiceError());
    }

    void TerminateDownloadSequence_Request::discard(const ServiceError& vl) {
        discard_ = boost::shared_ptr<ServiceError>(new ServiceError(vl));
    }


    // sequence InitiateUploadSequence-Response

    InitiateUploadSequence_Response::InitiateUploadSequence_Response() : ulsmID_(), listOfCapabilities_() {
    };

    InitiateUploadSequence_Response::InitiateUploadSequence_Response(const Integer32& arg__ulsmID,
            const listOfCapabilities_type& arg__listOfCapabilities) :
    ulsmID_(arg__ulsmID),
    listOfCapabilities_(arg__listOfCapabilities) {
    };

    template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(ulsmID_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
    }

    template<> void InitiateUploadSequence_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(ulsmID_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
    }

    Integer32& InitiateUploadSequence_Response::ulsmID() {
        return *ulsmID_;
    }

    const Integer32& InitiateUploadSequence_Response::ulsmID() const {
        return *ulsmID_;
    }

    void InitiateUploadSequence_Response::ulsmID(const Integer32& vl) {
        ulsmID_ = vl;
    }

    void InitiateUploadSequence_Response::ulsmID(boost::shared_ptr< Integer32> vl) {
        ulsmID_ = vl;
    }

    InitiateUploadSequence_Response::listOfCapabilities_type& InitiateUploadSequence_Response::listOfCapabilities() {
        return *listOfCapabilities_;
    }

    const InitiateUploadSequence_Response::listOfCapabilities_type& InitiateUploadSequence_Response::listOfCapabilities() const {
        return *listOfCapabilities_;
    }

    void InitiateUploadSequence_Response::listOfCapabilities(const listOfCapabilities_type& vl) {
        listOfCapabilities_ = vl;
    }

    void InitiateUploadSequence_Response::listOfCapabilities(boost::shared_ptr< listOfCapabilities_type> vl) {
        listOfCapabilities_ = vl;
    }


    // sequence UploadSegment-Response

    UploadSegment_Response::UploadSegment_Response() : loadData_() {
    };

    UploadSegment_Response::UploadSegment_Response(const LoadData& arg__loadData) :
    loadData_(arg__loadData) {
    };

    UploadSegment_Response::UploadSegment_Response(boost::shared_ptr< LoadData> arg__loadData,
            boost::shared_ptr< bool> arg__moreFollows) :
    loadData_(arg__loadData),
    moreFollows_(arg__moreFollows) {
    };

    const bool UploadSegment_Response::moreFollows__default = true;

    template<> void UploadSegment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void UploadSegment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(loadData_);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    LoadData& UploadSegment_Response::loadData() {
        return *loadData_;
    }

    const LoadData& UploadSegment_Response::loadData() const {
        return *loadData_;
    }

    void UploadSegment_Response::loadData(const LoadData& vl) {
        loadData_ = vl;
    }

    void UploadSegment_Response::loadData(boost::shared_ptr< LoadData> vl) {
        loadData_ = vl;
    }

    const bool& UploadSegment_Response::moreFollows() const {
        return *moreFollows_;
    }

    void UploadSegment_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void UploadSegment_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


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

    RequestDomainDownload_Request::RequestDomainDownload_Request(boost::shared_ptr< Identifier> arg__domainName,
            boost::shared_ptr< listOfCapabilities_type> arg__listOfCapabilities,
            boost::shared_ptr< bool> arg__sharable,
            boost::shared_ptr< FileName> arg__fileName) :
    domainName_(arg__domainName),
    listOfCapabilities_(arg__listOfCapabilities),
    sharable_(arg__sharable),
    fileName_(arg__fileName) {
    };

    template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(sharable_, 2);
        ITU_T_IMPLICIT_TAG(fileName_, 4);
    }

    template<> void RequestDomainDownload_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(sharable_, 2);
        ITU_T_IMPLICIT_TAG(fileName_, 4);
    }

    Identifier& RequestDomainDownload_Request::domainName() {
        return *domainName_;
    }

    const Identifier& RequestDomainDownload_Request::domainName() const {
        return *domainName_;
    }

    void RequestDomainDownload_Request::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void RequestDomainDownload_Request::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    boost::shared_ptr<RequestDomainDownload_Request::listOfCapabilities_type> RequestDomainDownload_Request::listOfCapabilities__new() {
        return listOfCapabilities_ = boost::shared_ptr<listOfCapabilities_type>(new listOfCapabilities_type());
    }

    void RequestDomainDownload_Request::listOfCapabilities(const listOfCapabilities_type& vl) {
        listOfCapabilities_ = boost::shared_ptr<listOfCapabilities_type>(new listOfCapabilities_type(vl));
    }

    bool& RequestDomainDownload_Request::sharable() {
        return *sharable_;
    }

    const bool& RequestDomainDownload_Request::sharable() const {
        return *sharable_;
    }

    void RequestDomainDownload_Request::sharable(const bool& vl) {
        sharable_ = vl;
    }

    void RequestDomainDownload_Request::sharable(boost::shared_ptr< bool> vl) {
        sharable_ = vl;
    }

    FileName& RequestDomainDownload_Request::fileName() {
        return *fileName_;
    }

    const FileName& RequestDomainDownload_Request::fileName() const {
        return *fileName_;
    }

    void RequestDomainDownload_Request::fileName(const FileName& vl) {
        fileName_ = vl;
    }

    void RequestDomainDownload_Request::fileName(boost::shared_ptr< FileName> vl) {
        fileName_ = vl;
    }


    // sequence RequestDomainUpload-Request

    RequestDomainUpload_Request::RequestDomainUpload_Request() : domainName_(), fileName_() {
    };

    RequestDomainUpload_Request::RequestDomainUpload_Request(const Identifier& arg__domainName,
            const FileName& arg__fileName) :
    domainName_(arg__domainName),
    fileName_(arg__fileName) {
    };

    template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
    }

    template<> void RequestDomainUpload_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
    }

    Identifier& RequestDomainUpload_Request::domainName() {
        return *domainName_;
    }

    const Identifier& RequestDomainUpload_Request::domainName() const {
        return *domainName_;
    }

    void RequestDomainUpload_Request::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void RequestDomainUpload_Request::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    FileName& RequestDomainUpload_Request::fileName() {
        return *fileName_;
    }

    const FileName& RequestDomainUpload_Request::fileName() const {
        return *fileName_;
    }

    void RequestDomainUpload_Request::fileName(const FileName& vl) {
        fileName_ = vl;
    }

    void RequestDomainUpload_Request::fileName(boost::shared_ptr< FileName> vl) {
        fileName_ = vl;
    }


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

    LoadDomainContent_Request::LoadDomainContent_Request(boost::shared_ptr< Identifier> arg__domainName,
            boost::shared_ptr< listOfCapabilities_type> arg__listOfCapabilities,
            boost::shared_ptr< bool> arg__sharable,
            boost::shared_ptr< FileName> arg__fileName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    domainName_(arg__domainName),
    listOfCapabilities_(arg__listOfCapabilities),
    sharable_(arg__sharable),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };

    template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(sharable_, 2);
        ITU_T_IMPLICIT_TAG(fileName_, 4);
        ITU_T_IMPLICIT_TAG(thirdParty_, 5);
    }

    template<> void LoadDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 1);
        ITU_T_IMPLICIT_TAG(sharable_, 2);
        ITU_T_IMPLICIT_TAG(fileName_, 4);
        ITU_T_IMPLICIT_TAG(thirdParty_, 5);
    }

    Identifier& LoadDomainContent_Request::domainName() {
        return *domainName_;
    }

    const Identifier& LoadDomainContent_Request::domainName() const {
        return *domainName_;
    }

    void LoadDomainContent_Request::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void LoadDomainContent_Request::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    boost::shared_ptr<LoadDomainContent_Request::listOfCapabilities_type> LoadDomainContent_Request::listOfCapabilities__new() {
        return listOfCapabilities_ = boost::shared_ptr<listOfCapabilities_type>(new listOfCapabilities_type());
    }

    void LoadDomainContent_Request::listOfCapabilities(const listOfCapabilities_type& vl) {
        listOfCapabilities_ = boost::shared_ptr<listOfCapabilities_type>(new listOfCapabilities_type(vl));
    }

    bool& LoadDomainContent_Request::sharable() {
        return *sharable_;
    }

    const bool& LoadDomainContent_Request::sharable() const {
        return *sharable_;
    }

    void LoadDomainContent_Request::sharable(const bool& vl) {
        sharable_ = vl;
    }

    void LoadDomainContent_Request::sharable(boost::shared_ptr< bool> vl) {
        sharable_ = vl;
    }

    FileName& LoadDomainContent_Request::fileName() {
        return *fileName_;
    }

    const FileName& LoadDomainContent_Request::fileName() const {
        return *fileName_;
    }

    void LoadDomainContent_Request::fileName(const FileName& vl) {
        fileName_ = vl;
    }

    void LoadDomainContent_Request::fileName(boost::shared_ptr< FileName> vl) {
        fileName_ = vl;
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> LoadDomainContent_Request::thirdParty__new() {
        return thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void LoadDomainContent_Request::thirdParty(const MMS_Environment_1::ApplicationReference& vl) {
        thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }


    // sequence StoreDomainContent-Request

    StoreDomainContent_Request::StoreDomainContent_Request() : domainName_(), fileName_() {
    };

    StoreDomainContent_Request::StoreDomainContent_Request(const Identifier& arg__domainName,
            const FileName& arg__fileName) :
    domainName_(arg__domainName),
    fileName_(arg__fileName) {
    };

    StoreDomainContent_Request::StoreDomainContent_Request(boost::shared_ptr< Identifier> arg__domainName,
            boost::shared_ptr< FileName> arg__fileName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    domainName_(arg__domainName),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };

    template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    template<> void StoreDomainContent_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    Identifier& StoreDomainContent_Request::domainName() {
        return *domainName_;
    }

    const Identifier& StoreDomainContent_Request::domainName() const {
        return *domainName_;
    }

    void StoreDomainContent_Request::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void StoreDomainContent_Request::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    FileName& StoreDomainContent_Request::fileName() {
        return *fileName_;
    }

    const FileName& StoreDomainContent_Request::fileName() const {
        return *fileName_;
    }

    void StoreDomainContent_Request::fileName(const FileName& vl) {
        fileName_ = vl;
    }

    void StoreDomainContent_Request::fileName(boost::shared_ptr< FileName> vl) {
        fileName_ = vl;
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> StoreDomainContent_Request::thirdParty__new() {
        return thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void StoreDomainContent_Request::thirdParty(const MMS_Environment_1::ApplicationReference& vl) {
        thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }


    // sequence GetDomainAttributes-Response

    GetDomainAttributes_Response::GetDomainAttributes_Response() : listOfCapabilities_(), state_(), mmsDeletable_(), sharable_(), listOfProgramInvocations_(), uploadInProgress_() {
    };

    GetDomainAttributes_Response::GetDomainAttributes_Response(const listOfCapabilities_type& arg__listOfCapabilities,
            const MMS_Object_Module_1::DomainState& arg__state,
            const bool& arg__mmsDeletable,
            const bool& arg__sharable,
            const listOfProgramInvocations_type& arg__listOfProgramInvocations,
            const Integer8& arg__uploadInProgress) :
    listOfCapabilities_(arg__listOfCapabilities),
    state_(arg__state),
    mmsDeletable_(arg__mmsDeletable),
    sharable_(arg__sharable),
    listOfProgramInvocations_(arg__listOfProgramInvocations),
    uploadInProgress_(arg__uploadInProgress) {
    };

    GetDomainAttributes_Response::GetDomainAttributes_Response(boost::shared_ptr< listOfCapabilities_type> arg__listOfCapabilities,
            boost::shared_ptr< MMS_Object_Module_1::DomainState> arg__state,
            boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< bool> arg__sharable,
            boost::shared_ptr< listOfProgramInvocations_type> arg__listOfProgramInvocations,
            boost::shared_ptr< Integer8> arg__uploadInProgress,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    listOfCapabilities_(arg__listOfCapabilities),
    state_(arg__state),
    mmsDeletable_(arg__mmsDeletable),
    sharable_(arg__sharable),
    listOfProgramInvocations_(arg__listOfProgramInvocations),
    uploadInProgress_(arg__uploadInProgress),
    accessControlList_(arg__accessControlList) {
    };

    template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(state_, 1);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(sharable_, 3);
        ITU_T_IMPLICIT_TAG(listOfProgramInvocations_, 4);
        ITU_T_IMPLICIT_TAG(uploadInProgress_, 5);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    template<> void GetDomainAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfCapabilities_, 0);
        ITU_T_IMPLICIT_TAG(state_, 1);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(sharable_, 3);
        ITU_T_IMPLICIT_TAG(listOfProgramInvocations_, 4);
        ITU_T_IMPLICIT_TAG(uploadInProgress_, 5);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    GetDomainAttributes_Response::listOfCapabilities_type& GetDomainAttributes_Response::listOfCapabilities() {
        return *listOfCapabilities_;
    }

    const GetDomainAttributes_Response::listOfCapabilities_type& GetDomainAttributes_Response::listOfCapabilities() const {
        return *listOfCapabilities_;
    }

    void GetDomainAttributes_Response::listOfCapabilities(const listOfCapabilities_type& vl) {
        listOfCapabilities_ = vl;
    }

    void GetDomainAttributes_Response::listOfCapabilities(boost::shared_ptr< listOfCapabilities_type> vl) {
        listOfCapabilities_ = vl;
    }

    MMS_Object_Module_1::DomainState& GetDomainAttributes_Response::state() {
        return *state_;
    }

    const MMS_Object_Module_1::DomainState& GetDomainAttributes_Response::state() const {
        return *state_;
    }

    void GetDomainAttributes_Response::state(const MMS_Object_Module_1::DomainState& vl) {
        state_ = vl;
    }

    void GetDomainAttributes_Response::state(boost::shared_ptr< MMS_Object_Module_1::DomainState> vl) {
        state_ = vl;
    }

    bool& GetDomainAttributes_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& GetDomainAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetDomainAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetDomainAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    bool& GetDomainAttributes_Response::sharable() {
        return *sharable_;
    }

    const bool& GetDomainAttributes_Response::sharable() const {
        return *sharable_;
    }

    void GetDomainAttributes_Response::sharable(const bool& vl) {
        sharable_ = vl;
    }

    void GetDomainAttributes_Response::sharable(boost::shared_ptr< bool> vl) {
        sharable_ = vl;
    }

    GetDomainAttributes_Response::listOfProgramInvocations_type& GetDomainAttributes_Response::listOfProgramInvocations() {
        return *listOfProgramInvocations_;
    }

    const GetDomainAttributes_Response::listOfProgramInvocations_type& GetDomainAttributes_Response::listOfProgramInvocations() const {
        return *listOfProgramInvocations_;
    }

    void GetDomainAttributes_Response::listOfProgramInvocations(const listOfProgramInvocations_type& vl) {
        listOfProgramInvocations_ = vl;
    }

    void GetDomainAttributes_Response::listOfProgramInvocations(boost::shared_ptr< listOfProgramInvocations_type> vl) {
        listOfProgramInvocations_ = vl;
    }

    Integer8& GetDomainAttributes_Response::uploadInProgress() {
        return *uploadInProgress_;
    }

    const Integer8& GetDomainAttributes_Response::uploadInProgress() const {
        return *uploadInProgress_;
    }

    void GetDomainAttributes_Response::uploadInProgress(const Integer8& vl) {
        uploadInProgress_ = vl;
    }

    void GetDomainAttributes_Response::uploadInProgress(boost::shared_ptr< Integer8> vl) {
        uploadInProgress_ = vl;
    }

    boost::shared_ptr<Identifier> GetDomainAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetDomainAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence CreateProgramInvocation-Request

    CreateProgramInvocation_Request::CreateProgramInvocation_Request() : programInvocationName_(), listOfDomainNames_() {
    };

    CreateProgramInvocation_Request::CreateProgramInvocation_Request(const Identifier& arg__programInvocationName,
            const listOfDomainNames_type& arg__listOfDomainNames) :
    programInvocationName_(arg__programInvocationName),
    listOfDomainNames_(arg__listOfDomainNames) {
    };

    CreateProgramInvocation_Request::CreateProgramInvocation_Request(boost::shared_ptr< Identifier> arg__programInvocationName,
            boost::shared_ptr< listOfDomainNames_type> arg__listOfDomainNames,
            boost::shared_ptr< bool> arg__reusable,
            boost::shared_ptr< bool> arg__monitorType) :
    programInvocationName_(arg__programInvocationName),
    listOfDomainNames_(arg__listOfDomainNames),
    reusable_(arg__reusable),
    monitorType_(arg__monitorType) {
    };

    const bool CreateProgramInvocation_Request::reusable__default = true;

    template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
    }

    template<> void CreateProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
    }

    Identifier& CreateProgramInvocation_Request::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& CreateProgramInvocation_Request::programInvocationName() const {
        return *programInvocationName_;
    }

    void CreateProgramInvocation_Request::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void CreateProgramInvocation_Request::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }

    CreateProgramInvocation_Request::listOfDomainNames_type& CreateProgramInvocation_Request::listOfDomainNames() {
        return *listOfDomainNames_;
    }

    const CreateProgramInvocation_Request::listOfDomainNames_type& CreateProgramInvocation_Request::listOfDomainNames() const {
        return *listOfDomainNames_;
    }

    void CreateProgramInvocation_Request::listOfDomainNames(const listOfDomainNames_type& vl) {
        listOfDomainNames_ = vl;
    }

    void CreateProgramInvocation_Request::listOfDomainNames(boost::shared_ptr< listOfDomainNames_type> vl) {
        listOfDomainNames_ = vl;
    }

    const bool& CreateProgramInvocation_Request::reusable() const {
        return *reusable_;
    }

    void CreateProgramInvocation_Request::reusable(const bool& vl) {
        reusable_ = vl;
    }

    void CreateProgramInvocation_Request::reusable(boost::shared_ptr< bool> vl) {
        reusable_ = vl;
    }

    boost::shared_ptr<bool> CreateProgramInvocation_Request::monitorType__new() {
        return monitorType_ = boost::shared_ptr<bool>(new bool());
    }

    void CreateProgramInvocation_Request::monitorType(const bool& vl) {
        monitorType_ = boost::shared_ptr<bool>(new bool(vl));
    }


    const CS_CreateProgramInvocation_Request CS_CreateProgramInvocation_Request_normal = 0;
    const CS_CreateProgramInvocation_Request CS_CreateProgramInvocation_Request_controlling = 1;
    const CS_CreateProgramInvocation_Request CS_CreateProgramInvocation_Request_controlled = 2;

    // sequence Start-Request

    Start_Request::Start_Request() : programInvocationName_() {
    };

    Start_Request::Start_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    Start_Request::Start_Request(boost::shared_ptr< Identifier> arg__programInvocationName,
            boost::shared_ptr< executionArgument_type> arg__executionArgument) :
    programInvocationName_(arg__programInvocationName),
    executionArgument_(arg__executionArgument) {
    };

    void Start_Request::executionArgument_type::simpleString(const MMSString& vl) {
        set<MMSString>(new MMSString(vl), executionArgument_type_simpleString);
    }

    void Start_Request::executionArgument_type::encodedString(const external_type& vl) {
        set<external_type>(new external_type(vl), executionArgument_type_encodedString);
    }

    void Start_Request::executionArgument_type::embeddedString(const embeded_type& vl) {
        set<embeded_type>(new embeded_type(vl), executionArgument_type_embeddedString);
    }

    template<> void Start_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case executionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(value<MMSString > (false, executionArgument_type_simpleString), 1);
                break;
            }
            case executionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(value<external_type > (false, executionArgument_type_encodedString));
                break;
            }
            case executionArgument_type_embeddedString:
            {
                ITU_T_BIND_TAG(value<embeded_type > (false, executionArgument_type_embeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Start_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<MMSString > (true, executionArgument_type_simpleString), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<external_type > (true, executionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(value<embeded_type > (true, executionArgument_type_embeddedString))) return;
                else free();
            }
        }
    }

    template<> void Start_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    template<> void Start_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    Identifier& Start_Request::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& Start_Request::programInvocationName() const {
        return *programInvocationName_;
    }

    void Start_Request::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void Start_Request::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }

    boost::shared_ptr<Start_Request::executionArgument_type> Start_Request::executionArgument__new() {
        return executionArgument_ = boost::shared_ptr<executionArgument_type>(new executionArgument_type());
    }

    void Start_Request::executionArgument(const executionArgument_type& vl) {
        executionArgument_ = boost::shared_ptr<executionArgument_type>(new executionArgument_type(vl));
    }


    // choice CS-Start-Request

    CS_Start_Request_impl::controlling_type::controlling_type() {
    };

    CS_Start_Request_impl::controlling_type::controlling_type(boost::shared_ptr< visiblestring_type> arg__startLocation,
            boost::shared_ptr< StartCount> arg__startCount) :
    startLocation_(arg__startLocation),
    startCount_(arg__startCount) {
    };

    template<> void CS_Start_Request_impl::controlling_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(startLocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    template<> void CS_Start_Request_impl::controlling_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(startLocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    boost::shared_ptr<visiblestring_type> CS_Start_Request_impl::controlling_type::startLocation__new() {
        return startLocation_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void CS_Start_Request_impl::controlling_type::startLocation(const visiblestring_type& vl) {
        startLocation_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    boost::shared_ptr<StartCount> CS_Start_Request_impl::controlling_type::startCount__new() {
        return startCount_ = boost::shared_ptr<StartCount>(new StartCount());
    }

    void CS_Start_Request_impl::controlling_type::startCount(const StartCount& vl) {
        startCount_ = boost::shared_ptr<StartCount>(new StartCount(vl));
    }

    void CS_Start_Request_impl::normal(const null_type& vl) {
        set<null_type>(new null_type(vl), CS_Start_Request_impl_normal);
    }

    template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_Start_Request_impl_normal:
            {
                ITU_T_BIND_TAG(value<null_type > (false, CS_Start_Request_impl_normal));
                break;
            }
            case CS_Start_Request_impl_controlling:
            {
                ITU_T_BIND_TAG(value<controlling_type > (false, CS_Start_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Start_Request_impl::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, CS_Start_Request_impl_normal))) return;
                else free();
                if (ITU_T_BIND_TAG(value<controlling_type > (true, CS_Start_Request_impl_controlling))) return;
                else free();
            }
        }
    }


    // choice StartCount

    void StartCount::noLimit(const null_type& vl) {
        set<null_type>(new null_type(vl), StartCount_noLimit);
    }

    void StartCount::cycleCount(const int& vl) {
        set<int>(new int(vl), StartCount_cycleCount);
    }

    void StartCount::stepCount(const int& vl) {
        set<int>(new int(vl), StartCount_stepCount);
    }

    template<> void StartCount::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case StartCount_noLimit:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, StartCount_noLimit), 0);
                break;
            }
            case StartCount_cycleCount:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, StartCount_cycleCount), 1);
                break;
            }
            case StartCount_stepCount:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, StartCount_stepCount), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, StartCount_noLimit), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, StartCount_cycleCount), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, StartCount_stepCount), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    Stop_Request::Stop_Request() : programInvocationName_() {
    };

    Stop_Request::Stop_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    template<> void Stop_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
    }

    template<> void Stop_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
    }

    Identifier& Stop_Request::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& Stop_Request::programInvocationName() const {
        return *programInvocationName_;
    }

    void Stop_Request::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void Stop_Request::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }


    // sequence Resume-Request

    Resume_Request::Resume_Request() : programInvocationName_() {
    };

    Resume_Request::Resume_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    Resume_Request::Resume_Request(boost::shared_ptr< Identifier> arg__programInvocationName,
            boost::shared_ptr< executionArgument_type> arg__executionArgument) :
    programInvocationName_(arg__programInvocationName),
    executionArgument_(arg__executionArgument) {
    };

    void Resume_Request::executionArgument_type::simpleString(const MMSString& vl) {
        set<MMSString>(new MMSString(vl), executionArgument_type_simpleString);
    }

    void Resume_Request::executionArgument_type::encodedString(const external_type& vl) {
        set<external_type>(new external_type(vl), executionArgument_type_encodedString);
    }

    void Resume_Request::executionArgument_type::enmbeddedString(const embeded_type& vl) {
        set<embeded_type>(new embeded_type(vl), executionArgument_type_enmbeddedString);
    }

    template<> void Resume_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case executionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(value<MMSString > (false, executionArgument_type_simpleString), 1);
                break;
            }
            case executionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(value<external_type > (false, executionArgument_type_encodedString));
                break;
            }
            case executionArgument_type_enmbeddedString:
            {
                ITU_T_BIND_TAG(value<embeded_type > (false, executionArgument_type_enmbeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Resume_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<MMSString > (true, executionArgument_type_simpleString), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<external_type > (true, executionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(value<embeded_type > (true, executionArgument_type_enmbeddedString))) return;
                else free();
            }
        }
    }

    template<> void Resume_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    template<> void Resume_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    Identifier& Resume_Request::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& Resume_Request::programInvocationName() const {
        return *programInvocationName_;
    }

    void Resume_Request::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void Resume_Request::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }

    boost::shared_ptr<Resume_Request::executionArgument_type> Resume_Request::executionArgument__new() {
        return executionArgument_ = boost::shared_ptr<executionArgument_type>(new executionArgument_type());
    }

    void Resume_Request::executionArgument(const executionArgument_type& vl) {
        executionArgument_ = boost::shared_ptr<executionArgument_type>(new executionArgument_type(vl));
    }


    // choice CS-Resume-Request

    CS_Resume_Request_impl::controlling_type::controlling_type() : modeType_() {
    };

    CS_Resume_Request_impl::controlling_type::controlling_type(const modeType_type& arg__modeType) :
    modeType_(arg__modeType) {
    };

    void CS_Resume_Request_impl::controlling_type::modeType_type::continueMode(const null_type& vl) {
        set<null_type>(new null_type(vl), modeType_type_continueMode);
    }

    template<> void CS_Resume_Request_impl::controlling_type::modeType_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case modeType_type_continueMode:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, modeType_type_continueMode), 0);
                break;
            }
            case modeType_type_changeMode:
            {
                ITU_T_CHOICE_TAG(value<StartCount > (false, modeType_type_changeMode), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Resume_Request_impl::controlling_type::modeType_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, modeType_type_continueMode), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<StartCount > (true, modeType_type_changeMode), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void CS_Resume_Request_impl::controlling_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(modeType_);
    }

    template<> void CS_Resume_Request_impl::controlling_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(modeType_);
    }

    CS_Resume_Request_impl::controlling_type::modeType_type& CS_Resume_Request_impl::controlling_type::modeType() {
        return *modeType_;
    }

    const CS_Resume_Request_impl::controlling_type::modeType_type& CS_Resume_Request_impl::controlling_type::modeType() const {
        return *modeType_;
    }

    void CS_Resume_Request_impl::controlling_type::modeType(const modeType_type& vl) {
        modeType_ = vl;
    }

    void CS_Resume_Request_impl::controlling_type::modeType(boost::shared_ptr< modeType_type> vl) {
        modeType_ = vl;
    }

    void CS_Resume_Request_impl::normal(const null_type& vl) {
        set<null_type>(new null_type(vl), CS_Resume_Request_impl_normal);
    }

    template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_Resume_Request_impl_normal:
            {
                ITU_T_BIND_TAG(value<null_type > (false, CS_Resume_Request_impl_normal));
                break;
            }
            case CS_Resume_Request_impl_controlling:
            {
                ITU_T_BIND_TAG(value<controlling_type > (false, CS_Resume_Request_impl_controlling));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_Resume_Request_impl::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, CS_Resume_Request_impl_normal))) return;
                else free();
                if (ITU_T_BIND_TAG(value<controlling_type > (true, CS_Resume_Request_impl_controlling))) return;
                else free();
            }
        }
    }


    // sequence Reset-Request

    Reset_Request::Reset_Request() : programInvocationName_() {
    };

    Reset_Request::Reset_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    template<> void Reset_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
    }

    template<> void Reset_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
    }

    Identifier& Reset_Request::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& Reset_Request::programInvocationName() const {
        return *programInvocationName_;
    }

    void Reset_Request::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void Reset_Request::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }


    // sequence Kill-Request

    Kill_Request::Kill_Request() : programInvocationName_() {
    };

    Kill_Request::Kill_Request(const Identifier& arg__programInvocationName) :
    programInvocationName_(arg__programInvocationName) {
    };

    template<> void Kill_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
    }

    template<> void Kill_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
    }

    Identifier& Kill_Request::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& Kill_Request::programInvocationName() const {
        return *programInvocationName_;
    }

    void Kill_Request::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void Kill_Request::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }


    // sequence GetProgramInvocationAttributes-Response

    GetProgramInvocationAttributes_Response::GetProgramInvocationAttributes_Response() : state_(), listOfDomainNames_(), mmsDeletable_(), reusable_(), monitor_(), executionArgument_() {
    };

    GetProgramInvocationAttributes_Response::GetProgramInvocationAttributes_Response(const MMS_Object_Module_1::ProgramInvocationState& arg__state,
            const listOfDomainNames_type& arg__listOfDomainNames,
            const bool& arg__mmsDeletable,
            const bool& arg__reusable,
            const bool& arg__monitor,
            const executionArgument_type& arg__executionArgument) :
    state_(arg__state),
    listOfDomainNames_(arg__listOfDomainNames),
    mmsDeletable_(arg__mmsDeletable),
    reusable_(arg__reusable),
    monitor_(arg__monitor),
    executionArgument_(arg__executionArgument) {
    };

    GetProgramInvocationAttributes_Response::GetProgramInvocationAttributes_Response(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__state,
            boost::shared_ptr< listOfDomainNames_type> arg__listOfDomainNames,
            boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< bool> arg__reusable,
            boost::shared_ptr< bool> arg__monitor,
            boost::shared_ptr< executionArgument_type> arg__executionArgument,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    state_(arg__state),
    listOfDomainNames_(arg__listOfDomainNames),
    mmsDeletable_(arg__mmsDeletable),
    reusable_(arg__reusable),
    monitor_(arg__monitor),
    executionArgument_(arg__executionArgument),
    accessControlList_(arg__accessControlList) {
    };

    void GetProgramInvocationAttributes_Response::executionArgument_type::simpleString(const MMSString& vl) {
        set<MMSString>(new MMSString(vl), executionArgument_type_simpleString);
    }

    void GetProgramInvocationAttributes_Response::executionArgument_type::encodedString(const external_type& vl) {
        set<external_type>(new external_type(vl), executionArgument_type_encodedString);
    }

    void GetProgramInvocationAttributes_Response::executionArgument_type::enmbeddedString(const embeded_type& vl) {
        set<embeded_type>(new embeded_type(vl), executionArgument_type_enmbeddedString);
    }

    template<> void GetProgramInvocationAttributes_Response::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case executionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(value<MMSString > (false, executionArgument_type_simpleString), 5);
                break;
            }
            case executionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(value<external_type > (false, executionArgument_type_encodedString));
                break;
            }
            case executionArgument_type_enmbeddedString:
            {
                ITU_T_BIND_TAG(value<embeded_type > (false, executionArgument_type_enmbeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetProgramInvocationAttributes_Response::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<MMSString > (true, executionArgument_type_simpleString), 5)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<external_type > (true, executionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(value<embeded_type > (true, executionArgument_type_enmbeddedString))) return;
                else free();
            }
        }
    }

    template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(state_, 0);
        ITU_T_IMPLICIT_TAG(listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(reusable_, 3);
        ITU_T_IMPLICIT_TAG(monitor_, 4);
        ITU_T_BIND_CHOICE(executionArgument_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    template<> void GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(state_, 0);
        ITU_T_IMPLICIT_TAG(listOfDomainNames_, 1);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 2);
        ITU_T_IMPLICIT_TAG(reusable_, 3);
        ITU_T_IMPLICIT_TAG(monitor_, 4);
        ITU_T_BIND_CHOICE(executionArgument_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 6);
    }

    MMS_Object_Module_1::ProgramInvocationState& GetProgramInvocationAttributes_Response::state() {
        return *state_;
    }

    const MMS_Object_Module_1::ProgramInvocationState& GetProgramInvocationAttributes_Response::state() const {
        return *state_;
    }

    void GetProgramInvocationAttributes_Response::state(const MMS_Object_Module_1::ProgramInvocationState& vl) {
        state_ = vl;
    }

    void GetProgramInvocationAttributes_Response::state(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> vl) {
        state_ = vl;
    }

    GetProgramInvocationAttributes_Response::listOfDomainNames_type& GetProgramInvocationAttributes_Response::listOfDomainNames() {
        return *listOfDomainNames_;
    }

    const GetProgramInvocationAttributes_Response::listOfDomainNames_type& GetProgramInvocationAttributes_Response::listOfDomainNames() const {
        return *listOfDomainNames_;
    }

    void GetProgramInvocationAttributes_Response::listOfDomainNames(const listOfDomainNames_type& vl) {
        listOfDomainNames_ = vl;
    }

    void GetProgramInvocationAttributes_Response::listOfDomainNames(boost::shared_ptr< listOfDomainNames_type> vl) {
        listOfDomainNames_ = vl;
    }

    bool& GetProgramInvocationAttributes_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& GetProgramInvocationAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetProgramInvocationAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetProgramInvocationAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    bool& GetProgramInvocationAttributes_Response::reusable() {
        return *reusable_;
    }

    const bool& GetProgramInvocationAttributes_Response::reusable() const {
        return *reusable_;
    }

    void GetProgramInvocationAttributes_Response::reusable(const bool& vl) {
        reusable_ = vl;
    }

    void GetProgramInvocationAttributes_Response::reusable(boost::shared_ptr< bool> vl) {
        reusable_ = vl;
    }

    bool& GetProgramInvocationAttributes_Response::monitor() {
        return *monitor_;
    }

    const bool& GetProgramInvocationAttributes_Response::monitor() const {
        return *monitor_;
    }

    void GetProgramInvocationAttributes_Response::monitor(const bool& vl) {
        monitor_ = vl;
    }

    void GetProgramInvocationAttributes_Response::monitor(boost::shared_ptr< bool> vl) {
        monitor_ = vl;
    }

    GetProgramInvocationAttributes_Response::executionArgument_type& GetProgramInvocationAttributes_Response::executionArgument() {
        return *executionArgument_;
    }

    const GetProgramInvocationAttributes_Response::executionArgument_type& GetProgramInvocationAttributes_Response::executionArgument() const {
        return *executionArgument_;
    }

    void GetProgramInvocationAttributes_Response::executionArgument(const executionArgument_type& vl) {
        executionArgument_ = vl;
    }

    void GetProgramInvocationAttributes_Response::executionArgument(boost::shared_ptr< executionArgument_type> vl) {
        executionArgument_ = vl;
    }

    boost::shared_ptr<Identifier> GetProgramInvocationAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetProgramInvocationAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence CS-GetProgramInvocationAttributes-Response

    CS_GetProgramInvocationAttributes_Response::CS_GetProgramInvocationAttributes_Response() : errorCode_(), control_() {
    };

    CS_GetProgramInvocationAttributes_Response::CS_GetProgramInvocationAttributes_Response(const int& arg__errorCode,
            const control_type& arg__control) :
    errorCode_(arg__errorCode),
    control_(arg__control) {
    };

    CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlling_type() : controlledPI_(), runningMode_() {
    };

    CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlling_type(const controlledPI_type& arg__controlledPI,
            const runningMode_type& arg__runningMode) :
    controlledPI_(arg__controlledPI),
    runningMode_(arg__runningMode) {
    };

    CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlling_type(boost::shared_ptr< controlledPI_type> arg__controlledPI,
            boost::shared_ptr< visiblestring_type> arg__programLocation,
            boost::shared_ptr< runningMode_type> arg__runningMode) :
    controlledPI_(arg__controlledPI),
    programLocation_(arg__programLocation),
    runningMode_(arg__runningMode) {
    };

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::freeRunning(const null_type& vl) {
        set<null_type>(new null_type(vl), runningMode_type_freeRunning);
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::cycleLimited(const int& vl) {
        set<int>(new int(vl), runningMode_type_cycleLimited);
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::stepLimited(const int& vl) {
        set<int>(new int(vl), runningMode_type_stepLimited);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case runningMode_type_freeRunning:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, runningMode_type_freeRunning), 0);
                break;
            }
            case runningMode_type_cycleLimited:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, runningMode_type_cycleLimited), 1);
                break;
            }
            case runningMode_type_stepLimited:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, runningMode_type_stepLimited), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, runningMode_type_freeRunning), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, runningMode_type_cycleLimited), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, runningMode_type_stepLimited), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlledPI_, 0);
        ITU_T_IMPLICIT_TAG(programLocation_, 1);
        ITU_T_CHOICE_TAG(runningMode_, 2);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlledPI_, 0);
        ITU_T_IMPLICIT_TAG(programLocation_, 1);
        ITU_T_CHOICE_TAG(runningMode_, 2);
    }

    CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlledPI_type& CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlledPI() {
        return *controlledPI_;
    }

    const CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlledPI_type& CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlledPI() const {
        return *controlledPI_;
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlledPI(const controlledPI_type& vl) {
        controlledPI_ = vl;
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::controlledPI(boost::shared_ptr< controlledPI_type> vl) {
        controlledPI_ = vl;
    }

    boost::shared_ptr<visiblestring_type> CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::programLocation__new() {
        return programLocation_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::programLocation(const visiblestring_type& vl) {
        programLocation_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type& CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode() {
        return *runningMode_;
    }

    const CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode_type& CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode() const {
        return *runningMode_;
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode(const runningMode_type& vl) {
        runningMode_ = vl;
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlling_type::runningMode(boost::shared_ptr< runningMode_type> vl) {
        runningMode_ = vl;
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::controllingPI(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), controlled_type_controllingPI);
    }

    void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::none(const null_type& vl) {
        set<null_type>(new null_type(vl), controlled_type_none);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case controlled_type_controllingPI:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, controlled_type_controllingPI), 0);
                break;
            }
            case controlled_type_none:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, controlled_type_none), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::controlled_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, controlled_type_controllingPI), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, controlled_type_none), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void CS_GetProgramInvocationAttributes_Response::control_type::normal(const null_type& vl) {
        set<null_type>(new null_type(vl), control_type_normal);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case control_type_controlling:
            {
                ITU_T_IMPLICIT_TAG(value<controlling_type > (false, control_type_controlling), 0);
                break;
            }
            case control_type_controlled:
            {
                ITU_T_CHOICE_TAG(value<controlled_type > (false, control_type_controlled), 1);
                break;
            }
            case control_type_normal:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, control_type_normal), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetProgramInvocationAttributes_Response::control_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<controlling_type > (true, control_type_controlling), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<controlled_type > (true, control_type_controlled), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, control_type_normal), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(errorCode_, 0);
        ITU_T_CHOICE_TAG(control_, 1);
    }

    template<> void CS_GetProgramInvocationAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(errorCode_, 0);
        ITU_T_CHOICE_TAG(control_, 1);
    }

    int& CS_GetProgramInvocationAttributes_Response::errorCode() {
        return *errorCode_;
    }

    const int& CS_GetProgramInvocationAttributes_Response::errorCode() const {
        return *errorCode_;
    }

    void CS_GetProgramInvocationAttributes_Response::errorCode(const int& vl) {
        errorCode_ = vl;
    }

    void CS_GetProgramInvocationAttributes_Response::errorCode(boost::shared_ptr< int> vl) {
        errorCode_ = vl;
    }

    CS_GetProgramInvocationAttributes_Response::control_type& CS_GetProgramInvocationAttributes_Response::control() {
        return *control_;
    }

    const CS_GetProgramInvocationAttributes_Response::control_type& CS_GetProgramInvocationAttributes_Response::control() const {
        return *control_;
    }

    void CS_GetProgramInvocationAttributes_Response::control(const control_type& vl) {
        control_ = vl;
    }

    void CS_GetProgramInvocationAttributes_Response::control(boost::shared_ptr< control_type> vl) {
        control_ = vl;
    }


    // sequence Select-Request

    Select_Request::Select_Request() {
    };

    Select_Request::Select_Request(boost::shared_ptr< Identifier> arg__controlling,
            boost::shared_ptr< controlled_type> arg__controlled) :
    controlling_(arg__controlling),
    controlled_(arg__controlled) {
    };

    template<> void Select_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlling_, 0);
        ITU_T_IMPLICIT_TAG(controlled_, 1);
    }

    template<> void Select_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlling_, 0);
        ITU_T_IMPLICIT_TAG(controlled_, 1);
    }

    boost::shared_ptr<Identifier> Select_Request::controlling__new() {
        return controlling_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void Select_Request::controlling(const Identifier& vl) {
        controlling_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    boost::shared_ptr<Select_Request::controlled_type> Select_Request::controlled__new() {
        return controlled_ = boost::shared_ptr<controlled_type>(new controlled_type());
    }

    void Select_Request::controlled(const controlled_type& vl) {
        controlled_ = boost::shared_ptr<controlled_type>(new controlled_type(vl));
    }


    // sequence AlterProgramInvocationAttributes-Request

    AlterProgramInvocationAttributes_Request::AlterProgramInvocationAttributes_Request() : programInvocation_() {
    };

    AlterProgramInvocationAttributes_Request::AlterProgramInvocationAttributes_Request(const Identifier& arg__programInvocation) :
    programInvocation_(arg__programInvocation) {
    };

    AlterProgramInvocationAttributes_Request::AlterProgramInvocationAttributes_Request(boost::shared_ptr< Identifier> arg__programInvocation,
            boost::shared_ptr< StartCount> arg__startCount) :
    programInvocation_(arg__programInvocation),
    startCount_(arg__startCount) {
    };

    template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    template<> void AlterProgramInvocationAttributes_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocation_, 0);
        ITU_T_CHOICE_TAG(startCount_, 1);
    }

    Identifier& AlterProgramInvocationAttributes_Request::programInvocation() {
        return *programInvocation_;
    }

    const Identifier& AlterProgramInvocationAttributes_Request::programInvocation() const {
        return *programInvocation_;
    }

    void AlterProgramInvocationAttributes_Request::programInvocation(const Identifier& vl) {
        programInvocation_ = vl;
    }

    void AlterProgramInvocationAttributes_Request::programInvocation(boost::shared_ptr< Identifier> vl) {
        programInvocation_ = vl;
    }

    boost::shared_ptr<StartCount> AlterProgramInvocationAttributes_Request::startCount__new() {
        return startCount_ = boost::shared_ptr<StartCount>(new StartCount());
    }

    void AlterProgramInvocationAttributes_Request::startCount(const StartCount& vl) {
        startCount_ = boost::shared_ptr<StartCount>(new StartCount(vl));
    }


    // sequence ReconfigureProgramInvocation-Request

    ReconfigureProgramInvocation_Request::ReconfigureProgramInvocation_Request() : oldProgramInvocationName_(), domainsToAdd_(), domainsToRemove_() {
    };

    ReconfigureProgramInvocation_Request::ReconfigureProgramInvocation_Request(const Identifier& arg__oldProgramInvocationName,
            const domainsToAdd_type& arg__domainsToAdd,
            const domainsToRemove_type& arg__domainsToRemove) :
    oldProgramInvocationName_(arg__oldProgramInvocationName),
    domainsToAdd_(arg__domainsToAdd),
    domainsToRemove_(arg__domainsToRemove) {
    };

    ReconfigureProgramInvocation_Request::ReconfigureProgramInvocation_Request(boost::shared_ptr< Identifier> arg__oldProgramInvocationName,
            boost::shared_ptr< Identifier> arg__newProgramInvocationName,
            boost::shared_ptr< domainsToAdd_type> arg__domainsToAdd,
            boost::shared_ptr< domainsToRemove_type> arg__domainsToRemove) :
    oldProgramInvocationName_(arg__oldProgramInvocationName),
    newProgramInvocationName_(arg__newProgramInvocationName),
    domainsToAdd_(arg__domainsToAdd),
    domainsToRemove_(arg__domainsToRemove) {
    };

    template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(oldProgramInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(newProgramInvocationName_, 1);
        ITU_T_IMPLICIT_TAG(domainsToAdd_, 2);
        ITU_T_IMPLICIT_TAG(domainsToRemove_, 3);
    }

    template<> void ReconfigureProgramInvocation_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(oldProgramInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(newProgramInvocationName_, 1);
        ITU_T_IMPLICIT_TAG(domainsToAdd_, 2);
        ITU_T_IMPLICIT_TAG(domainsToRemove_, 3);
    }

    Identifier& ReconfigureProgramInvocation_Request::oldProgramInvocationName() {
        return *oldProgramInvocationName_;
    }

    const Identifier& ReconfigureProgramInvocation_Request::oldProgramInvocationName() const {
        return *oldProgramInvocationName_;
    }

    void ReconfigureProgramInvocation_Request::oldProgramInvocationName(const Identifier& vl) {
        oldProgramInvocationName_ = vl;
    }

    void ReconfigureProgramInvocation_Request::oldProgramInvocationName(boost::shared_ptr< Identifier> vl) {
        oldProgramInvocationName_ = vl;
    }

    boost::shared_ptr<Identifier> ReconfigureProgramInvocation_Request::newProgramInvocationName__new() {
        return newProgramInvocationName_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void ReconfigureProgramInvocation_Request::newProgramInvocationName(const Identifier& vl) {
        newProgramInvocationName_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    ReconfigureProgramInvocation_Request::domainsToAdd_type& ReconfigureProgramInvocation_Request::domainsToAdd() {
        return *domainsToAdd_;
    }

    const ReconfigureProgramInvocation_Request::domainsToAdd_type& ReconfigureProgramInvocation_Request::domainsToAdd() const {
        return *domainsToAdd_;
    }

    void ReconfigureProgramInvocation_Request::domainsToAdd(const domainsToAdd_type& vl) {
        domainsToAdd_ = vl;
    }

    void ReconfigureProgramInvocation_Request::domainsToAdd(boost::shared_ptr< domainsToAdd_type> vl) {
        domainsToAdd_ = vl;
    }

    ReconfigureProgramInvocation_Request::domainsToRemove_type& ReconfigureProgramInvocation_Request::domainsToRemove() {
        return *domainsToRemove_;
    }

    const ReconfigureProgramInvocation_Request::domainsToRemove_type& ReconfigureProgramInvocation_Request::domainsToRemove() const {
        return *domainsToRemove_;
    }

    void ReconfigureProgramInvocation_Request::domainsToRemove(const domainsToRemove_type& vl) {
        domainsToRemove_ = vl;
    }

    void ReconfigureProgramInvocation_Request::domainsToRemove(boost::shared_ptr< domainsToRemove_type> vl) {
        domainsToRemove_ = vl;
    }


    // choice ControlElement

    ControlElement::beginDomainDef_type::beginDomainDef_type() : domainName_(), capabilities_(), sharable_() {
    };

    ControlElement::beginDomainDef_type::beginDomainDef_type(const Identifier& arg__domainName,
            const capabilities_type& arg__capabilities,
            const bool& arg__sharable) :
    domainName_(arg__domainName),
    capabilities_(arg__capabilities),
    sharable_(arg__sharable) {
    };

    ControlElement::beginDomainDef_type::beginDomainDef_type(boost::shared_ptr< Identifier> arg__domainName,
            boost::shared_ptr< capabilities_type> arg__capabilities,
            boost::shared_ptr< bool> arg__sharable,
            boost::shared_ptr< LoadData> arg__loadData) :
    domainName_(arg__domainName),
    capabilities_(arg__capabilities),
    sharable_(arg__sharable),
    loadData_(arg__loadData) {
    };

    template<> void ControlElement::beginDomainDef_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 1);
        ITU_T_IMPLICIT_TAG(capabilities_, 2);
        ITU_T_IMPLICIT_TAG(sharable_, 3);
        ITU_T_CHOICE_TAG(loadData_, 4);
    }

    template<> void ControlElement::beginDomainDef_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 1);
        ITU_T_IMPLICIT_TAG(capabilities_, 2);
        ITU_T_IMPLICIT_TAG(sharable_, 3);
        ITU_T_CHOICE_TAG(loadData_, 4);
    }

    Identifier& ControlElement::beginDomainDef_type::domainName() {
        return *domainName_;
    }

    const Identifier& ControlElement::beginDomainDef_type::domainName() const {
        return *domainName_;
    }

    void ControlElement::beginDomainDef_type::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void ControlElement::beginDomainDef_type::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    ControlElement::beginDomainDef_type::capabilities_type& ControlElement::beginDomainDef_type::capabilities() {
        return *capabilities_;
    }

    const ControlElement::beginDomainDef_type::capabilities_type& ControlElement::beginDomainDef_type::capabilities() const {
        return *capabilities_;
    }

    void ControlElement::beginDomainDef_type::capabilities(const capabilities_type& vl) {
        capabilities_ = vl;
    }

    void ControlElement::beginDomainDef_type::capabilities(boost::shared_ptr< capabilities_type> vl) {
        capabilities_ = vl;
    }

    bool& ControlElement::beginDomainDef_type::sharable() {
        return *sharable_;
    }

    const bool& ControlElement::beginDomainDef_type::sharable() const {
        return *sharable_;
    }

    void ControlElement::beginDomainDef_type::sharable(const bool& vl) {
        sharable_ = vl;
    }

    void ControlElement::beginDomainDef_type::sharable(boost::shared_ptr< bool> vl) {
        sharable_ = vl;
    }

    boost::shared_ptr<LoadData> ControlElement::beginDomainDef_type::loadData__new() {
        return loadData_ = boost::shared_ptr<LoadData>(new LoadData());
    }

    void ControlElement::beginDomainDef_type::loadData(const LoadData& vl) {
        loadData_ = boost::shared_ptr<LoadData>(new LoadData(vl));
    }

    ControlElement::continueDomainDef_type::continueDomainDef_type() : domainName_(), loadData_() {
    };

    ControlElement::continueDomainDef_type::continueDomainDef_type(const Identifier& arg__domainName,
            const LoadData& arg__loadData) :
    domainName_(arg__domainName),
    loadData_(arg__loadData) {
    };

    template<> void ControlElement::continueDomainDef_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 1);
        ITU_T_CHOICE_TAG(loadData_, 3);
    }

    template<> void ControlElement::continueDomainDef_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domainName_, 1);
        ITU_T_CHOICE_TAG(loadData_, 3);
    }

    Identifier& ControlElement::continueDomainDef_type::domainName() {
        return *domainName_;
    }

    const Identifier& ControlElement::continueDomainDef_type::domainName() const {
        return *domainName_;
    }

    void ControlElement::continueDomainDef_type::domainName(const Identifier& vl) {
        domainName_ = vl;
    }

    void ControlElement::continueDomainDef_type::domainName(boost::shared_ptr< Identifier> vl) {
        domainName_ = vl;
    }

    LoadData& ControlElement::continueDomainDef_type::loadData() {
        return *loadData_;
    }

    const LoadData& ControlElement::continueDomainDef_type::loadData() const {
        return *loadData_;
    }

    void ControlElement::continueDomainDef_type::loadData(const LoadData& vl) {
        loadData_ = vl;
    }

    void ControlElement::continueDomainDef_type::loadData(boost::shared_ptr< LoadData> vl) {
        loadData_ = vl;
    }

    ControlElement::piDefinition_type::piDefinition_type() : piName_(), listOfDomains_() {
    };

    ControlElement::piDefinition_type::piDefinition_type(const Identifier& arg__piName,
            const listOfDomains_type& arg__listOfDomains) :
    piName_(arg__piName),
    listOfDomains_(arg__listOfDomains) {
    };

    ControlElement::piDefinition_type::piDefinition_type(boost::shared_ptr< Identifier> arg__piName,
            boost::shared_ptr< listOfDomains_type> arg__listOfDomains,
            boost::shared_ptr< bool> arg__reusable,
            boost::shared_ptr< bool> arg__monitorType,
            boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__pIState) :
    piName_(arg__piName),
    listOfDomains_(arg__listOfDomains),
    reusable_(arg__reusable),
    monitorType_(arg__monitorType),
    pIState_(arg__pIState) {
    };

    const bool ControlElement::piDefinition_type::reusable__default = true;

    template<> void ControlElement::piDefinition_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(piName_, 0);
        ITU_T_IMPLICIT_TAG(listOfDomains_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
        ITU_T_IMPLICIT_TAG(pIState_, 4);
    }

    template<> void ControlElement::piDefinition_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(piName_, 0);
        ITU_T_IMPLICIT_TAG(listOfDomains_, 1);
        ITU_T_IMPLICIT_TAG(reusable_, 2);
        ITU_T_IMPLICIT_TAG(monitorType_, 3);
        ITU_T_IMPLICIT_TAG(pIState_, 4);
    }

    Identifier& ControlElement::piDefinition_type::piName() {
        return *piName_;
    }

    const Identifier& ControlElement::piDefinition_type::piName() const {
        return *piName_;
    }

    void ControlElement::piDefinition_type::piName(const Identifier& vl) {
        piName_ = vl;
    }

    void ControlElement::piDefinition_type::piName(boost::shared_ptr< Identifier> vl) {
        piName_ = vl;
    }

    ControlElement::piDefinition_type::listOfDomains_type& ControlElement::piDefinition_type::listOfDomains() {
        return *listOfDomains_;
    }

    const ControlElement::piDefinition_type::listOfDomains_type& ControlElement::piDefinition_type::listOfDomains() const {
        return *listOfDomains_;
    }

    void ControlElement::piDefinition_type::listOfDomains(const listOfDomains_type& vl) {
        listOfDomains_ = vl;
    }

    void ControlElement::piDefinition_type::listOfDomains(boost::shared_ptr< listOfDomains_type> vl) {
        listOfDomains_ = vl;
    }

    const bool& ControlElement::piDefinition_type::reusable() const {
        return *reusable_;
    }

    void ControlElement::piDefinition_type::reusable(const bool& vl) {
        reusable_ = vl;
    }

    void ControlElement::piDefinition_type::reusable(boost::shared_ptr< bool> vl) {
        reusable_ = vl;
    }

    boost::shared_ptr<bool> ControlElement::piDefinition_type::monitorType__new() {
        return monitorType_ = boost::shared_ptr<bool>(new bool());
    }

    void ControlElement::piDefinition_type::monitorType(const bool& vl) {
        monitorType_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::ProgramInvocationState> ControlElement::piDefinition_type::pIState__new() {
        return pIState_ = boost::shared_ptr<MMS_Object_Module_1::ProgramInvocationState>(new MMS_Object_Module_1::ProgramInvocationState());
    }

    void ControlElement::piDefinition_type::pIState(const MMS_Object_Module_1::ProgramInvocationState& vl) {
        pIState_ = boost::shared_ptr<MMS_Object_Module_1::ProgramInvocationState>(new MMS_Object_Module_1::ProgramInvocationState(vl));
    }

    void ControlElement::endDomainDef(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), ControlElement_endDomainDef);
    }

    template<> void ControlElement::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ControlElement_beginDomainDef:
            {
                ITU_T_EXPLICIT_TAG(value<beginDomainDef_type > (false, ControlElement_beginDomainDef), 0);
                break;
            }
            case ControlElement_continueDomainDef:
            {
                ITU_T_EXPLICIT_TAG(value<continueDomainDef_type > (false, ControlElement_continueDomainDef), 1);
                break;
            }
            case ControlElement_endDomainDef:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, ControlElement_endDomainDef), 2);
                break;
            }
            case ControlElement_piDefinition:
            {
                ITU_T_IMPLICIT_TAG(value<piDefinition_type > (false, ControlElement_piDefinition), 3);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<beginDomainDef_type > (true, ControlElement_beginDomainDef), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<continueDomainDef_type > (true, ControlElement_continueDomainDef), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, ControlElement_endDomainDef), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<piDefinition_type > (true, ControlElement_piDefinition), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    // choice InitiateUnitControl-Error

    void InitiateUnitControl_Error::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), InitiateUnitControl_Error_domain);
    }

    void InitiateUnitControl_Error::programInvocation(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), InitiateUnitControl_Error_programInvocation);
    }

    template<> void InitiateUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case InitiateUnitControl_Error_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, InitiateUnitControl_Error_domain), 0);
                break;
            }
            case InitiateUnitControl_Error_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, InitiateUnitControl_Error_programInvocation), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, InitiateUnitControl_Error_domain), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, InitiateUnitControl_Error_programInvocation), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    UnitControlLoadSegment_Response::UnitControlLoadSegment_Response() : controlElements_() {
    };

    UnitControlLoadSegment_Response::UnitControlLoadSegment_Response(const controlElements_type& arg__controlElements) :
    controlElements_(arg__controlElements) {
    };

    UnitControlLoadSegment_Response::UnitControlLoadSegment_Response(boost::shared_ptr< controlElements_type> arg__controlElements,
            boost::shared_ptr< bool> arg__moreFollows) :
    controlElements_(arg__controlElements),
    moreFollows_(arg__moreFollows) {
    };

    const bool UnitControlLoadSegment_Response::moreFollows__default = true;

    template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlElements_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void UnitControlLoadSegment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlElements_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    UnitControlLoadSegment_Response::controlElements_type& UnitControlLoadSegment_Response::controlElements() {
        return *controlElements_;
    }

    const UnitControlLoadSegment_Response::controlElements_type& UnitControlLoadSegment_Response::controlElements() const {
        return *controlElements_;
    }

    void UnitControlLoadSegment_Response::controlElements(const controlElements_type& vl) {
        controlElements_ = vl;
    }

    void UnitControlLoadSegment_Response::controlElements(boost::shared_ptr< controlElements_type> vl) {
        controlElements_ = vl;
    }

    const bool& UnitControlLoadSegment_Response::moreFollows() const {
        return *moreFollows_;
    }

    void UnitControlLoadSegment_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void UnitControlLoadSegment_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence UnitControlUpload-Request

    UnitControlUpload_Request::UnitControlUpload_Request() : unitControlName_() {
    };

    UnitControlUpload_Request::UnitControlUpload_Request(const Identifier& arg__unitControlName) :
    unitControlName_(arg__unitControlName) {
    };

    UnitControlUpload_Request::UnitControlUpload_Request(boost::shared_ptr< Identifier> arg__unitControlName,
            boost::shared_ptr< continueAfter_type> arg__continueAfter) :
    unitControlName_(arg__unitControlName),
    continueAfter_(arg__continueAfter) {
    };

    void UnitControlUpload_Request::continueAfter_type::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), continueAfter_type_domain);
    }

    void UnitControlUpload_Request::continueAfter_type::ulsmID(const int& vl) {
        set<int>(new int(vl), continueAfter_type_ulsmID);
    }

    void UnitControlUpload_Request::continueAfter_type::programInvocation(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), continueAfter_type_programInvocation);
    }

    template<> void UnitControlUpload_Request::continueAfter_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case continueAfter_type_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, continueAfter_type_domain), 1);
                break;
            }
            case continueAfter_type_ulsmID:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, continueAfter_type_ulsmID), 2);
                break;
            }
            case continueAfter_type_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, continueAfter_type_programInvocation), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnitControlUpload_Request::continueAfter_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, continueAfter_type_domain), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, continueAfter_type_ulsmID), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, continueAfter_type_programInvocation), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_BIND_CHOICE(continueAfter_);
    }

    template<> void UnitControlUpload_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_BIND_CHOICE(continueAfter_);
    }

    Identifier& UnitControlUpload_Request::unitControlName() {
        return *unitControlName_;
    }

    const Identifier& UnitControlUpload_Request::unitControlName() const {
        return *unitControlName_;
    }

    void UnitControlUpload_Request::unitControlName(const Identifier& vl) {
        unitControlName_ = vl;
    }

    void UnitControlUpload_Request::unitControlName(boost::shared_ptr< Identifier> vl) {
        unitControlName_ = vl;
    }

    boost::shared_ptr<UnitControlUpload_Request::continueAfter_type> UnitControlUpload_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<continueAfter_type>(new continueAfter_type());
    }

    void UnitControlUpload_Request::continueAfter(const continueAfter_type& vl) {
        continueAfter_ = boost::shared_ptr<continueAfter_type>(new continueAfter_type(vl));
    }


    // sequence UnitControlUpload-Response

    UnitControlUpload_Response::UnitControlUpload_Response() : controlElements_() {
    };

    UnitControlUpload_Response::UnitControlUpload_Response(const controlElements_type& arg__controlElements) :
    controlElements_(arg__controlElements) {
    };

    UnitControlUpload_Response::UnitControlUpload_Response(boost::shared_ptr< controlElements_type> arg__controlElements,
            boost::shared_ptr< nextElement_type> arg__nextElement) :
    controlElements_(arg__controlElements),
    nextElement_(arg__nextElement) {
    };

    void UnitControlUpload_Response::nextElement_type::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), nextElement_type_domain);
    }

    void UnitControlUpload_Response::nextElement_type::ulsmID(const int& vl) {
        set<int>(new int(vl), nextElement_type_ulsmID);
    }

    void UnitControlUpload_Response::nextElement_type::programInvocation(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), nextElement_type_programInvocation);
    }

    template<> void UnitControlUpload_Response::nextElement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case nextElement_type_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, nextElement_type_domain), 1);
                break;
            }
            case nextElement_type_ulsmID:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, nextElement_type_ulsmID), 2);
                break;
            }
            case nextElement_type_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, nextElement_type_programInvocation), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void UnitControlUpload_Response::nextElement_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, nextElement_type_domain), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, nextElement_type_ulsmID), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, nextElement_type_programInvocation), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlElements_, 0);
        ITU_T_BIND_CHOICE(nextElement_);
    }

    template<> void UnitControlUpload_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(controlElements_, 0);
        ITU_T_BIND_CHOICE(nextElement_);
    }

    UnitControlUpload_Response::controlElements_type& UnitControlUpload_Response::controlElements() {
        return *controlElements_;
    }

    const UnitControlUpload_Response::controlElements_type& UnitControlUpload_Response::controlElements() const {
        return *controlElements_;
    }

    void UnitControlUpload_Response::controlElements(const controlElements_type& vl) {
        controlElements_ = vl;
    }

    void UnitControlUpload_Response::controlElements(boost::shared_ptr< controlElements_type> vl) {
        controlElements_ = vl;
    }

    boost::shared_ptr<UnitControlUpload_Response::nextElement_type> UnitControlUpload_Response::nextElement__new() {
        return nextElement_ = boost::shared_ptr<nextElement_type>(new nextElement_type());
    }

    void UnitControlUpload_Response::nextElement(const nextElement_type& vl) {
        nextElement_ = boost::shared_ptr<nextElement_type>(new nextElement_type(vl));
    }


    // sequence StartUnitControl-Request

    StartUnitControl_Request::StartUnitControl_Request() : unitControlName_() {
    };

    StartUnitControl_Request::StartUnitControl_Request(const Identifier& arg__unitControlName) :
    unitControlName_(arg__unitControlName) {
    };

    StartUnitControl_Request::StartUnitControl_Request(boost::shared_ptr< Identifier> arg__unitControlName,
            boost::shared_ptr< executionArgument_type> arg__executionArgument) :
    unitControlName_(arg__unitControlName),
    executionArgument_(arg__executionArgument) {
    };

    void StartUnitControl_Request::executionArgument_type::simpleString(const MMSString& vl) {
        set<MMSString>(new MMSString(vl), executionArgument_type_simpleString);
    }

    void StartUnitControl_Request::executionArgument_type::encodedString(const external_type& vl) {
        set<external_type>(new external_type(vl), executionArgument_type_encodedString);
    }

    void StartUnitControl_Request::executionArgument_type::enmbeddedString(const embeded_type& vl) {
        set<embeded_type>(new embeded_type(vl), executionArgument_type_enmbeddedString);
    }

    template<> void StartUnitControl_Request::executionArgument_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case executionArgument_type_simpleString:
            {
                ITU_T_IMPLICIT_TAG(value<MMSString > (false, executionArgument_type_simpleString), 1);
                break;
            }
            case executionArgument_type_encodedString:
            {
                ITU_T_BIND_TAG(value<external_type > (false, executionArgument_type_encodedString));
                break;
            }
            case executionArgument_type_enmbeddedString:
            {
                ITU_T_BIND_TAG(value<embeded_type > (false, executionArgument_type_enmbeddedString));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void StartUnitControl_Request::executionArgument_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<MMSString > (true, executionArgument_type_simpleString), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<external_type > (true, executionArgument_type_encodedString))) return;
                else free();
                if (ITU_T_BIND_TAG(value<embeded_type > (true, executionArgument_type_enmbeddedString))) return;
                else free();
            }
        }
    }

    template<> void StartUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    template<> void StartUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_BIND_CHOICE(executionArgument_);
    }

    Identifier& StartUnitControl_Request::unitControlName() {
        return *unitControlName_;
    }

    const Identifier& StartUnitControl_Request::unitControlName() const {
        return *unitControlName_;
    }

    void StartUnitControl_Request::unitControlName(const Identifier& vl) {
        unitControlName_ = vl;
    }

    void StartUnitControl_Request::unitControlName(boost::shared_ptr< Identifier> vl) {
        unitControlName_ = vl;
    }

    boost::shared_ptr<StartUnitControl_Request::executionArgument_type> StartUnitControl_Request::executionArgument__new() {
        return executionArgument_ = boost::shared_ptr<executionArgument_type>(new executionArgument_type());
    }

    void StartUnitControl_Request::executionArgument(const executionArgument_type& vl) {
        executionArgument_ = boost::shared_ptr<executionArgument_type>(new executionArgument_type(vl));
    }


    // sequence StartUnitControl-Error

    StartUnitControl_Error::StartUnitControl_Error() : programInvocationName_(), programInvocationState_() {
    };

    StartUnitControl_Error::StartUnitControl_Error(const Identifier& arg__programInvocationName,
            const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState) :
    programInvocationName_(arg__programInvocationName),
    programInvocationState_(arg__programInvocationState) {
    };

    template<> void StartUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(programInvocationState_, 1);
    }

    template<> void StartUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(programInvocationState_, 1);
    }

    Identifier& StartUnitControl_Error::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& StartUnitControl_Error::programInvocationName() const {
        return *programInvocationName_;
    }

    void StartUnitControl_Error::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void StartUnitControl_Error::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }

    MMS_Object_Module_1::ProgramInvocationState& StartUnitControl_Error::programInvocationState() {
        return *programInvocationState_;
    }

    const MMS_Object_Module_1::ProgramInvocationState& StartUnitControl_Error::programInvocationState() const {
        return *programInvocationState_;
    }

    void StartUnitControl_Error::programInvocationState(const MMS_Object_Module_1::ProgramInvocationState& vl) {
        programInvocationState_ = vl;
    }

    void StartUnitControl_Error::programInvocationState(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> vl) {
        programInvocationState_ = vl;
    }


    // sequence StopUnitControl-Error

    StopUnitControl_Error::StopUnitControl_Error() : programInvocationName_(), programInvocationState_() {
    };

    StopUnitControl_Error::StopUnitControl_Error(const Identifier& arg__programInvocationName,
            const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState) :
    programInvocationName_(arg__programInvocationName),
    programInvocationState_(arg__programInvocationState) {
    };

    template<> void StopUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(programInvocationState_, 1);
    }

    template<> void StopUnitControl_Error::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(programInvocationName_, 0);
        ITU_T_IMPLICIT_TAG(programInvocationState_, 1);
    }

    Identifier& StopUnitControl_Error::programInvocationName() {
        return *programInvocationName_;
    }

    const Identifier& StopUnitControl_Error::programInvocationName() const {
        return *programInvocationName_;
    }

    void StopUnitControl_Error::programInvocationName(const Identifier& vl) {
        programInvocationName_ = vl;
    }

    void StopUnitControl_Error::programInvocationName(boost::shared_ptr< Identifier> vl) {
        programInvocationName_ = vl;
    }

    MMS_Object_Module_1::ProgramInvocationState& StopUnitControl_Error::programInvocationState() {
        return *programInvocationState_;
    }

    const MMS_Object_Module_1::ProgramInvocationState& StopUnitControl_Error::programInvocationState() const {
        return *programInvocationState_;
    }

    void StopUnitControl_Error::programInvocationState(const MMS_Object_Module_1::ProgramInvocationState& vl) {
        programInvocationState_ = vl;
    }

    void StopUnitControl_Error::programInvocationState(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> vl) {
        programInvocationState_ = vl;
    }


    // sequence CreateUnitControl-Request

    CreateUnitControl_Request::CreateUnitControl_Request() : unitControl_(), domains_(), programInvocations_() {
    };

    CreateUnitControl_Request::CreateUnitControl_Request(const Identifier& arg__unitControl,
            const domains_type& arg__domains,
            const programInvocations_type& arg__programInvocations) :
    unitControl_(arg__unitControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };

    template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControl_, 0);
        ITU_T_IMPLICIT_TAG(domains_, 1);
        ITU_T_IMPLICIT_TAG(programInvocations_, 2);
    }

    template<> void CreateUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControl_, 0);
        ITU_T_IMPLICIT_TAG(domains_, 1);
        ITU_T_IMPLICIT_TAG(programInvocations_, 2);
    }

    Identifier& CreateUnitControl_Request::unitControl() {
        return *unitControl_;
    }

    const Identifier& CreateUnitControl_Request::unitControl() const {
        return *unitControl_;
    }

    void CreateUnitControl_Request::unitControl(const Identifier& vl) {
        unitControl_ = vl;
    }

    void CreateUnitControl_Request::unitControl(boost::shared_ptr< Identifier> vl) {
        unitControl_ = vl;
    }

    CreateUnitControl_Request::domains_type& CreateUnitControl_Request::domains() {
        return *domains_;
    }

    const CreateUnitControl_Request::domains_type& CreateUnitControl_Request::domains() const {
        return *domains_;
    }

    void CreateUnitControl_Request::domains(const domains_type& vl) {
        domains_ = vl;
    }

    void CreateUnitControl_Request::domains(boost::shared_ptr< domains_type> vl) {
        domains_ = vl;
    }

    CreateUnitControl_Request::programInvocations_type& CreateUnitControl_Request::programInvocations() {
        return *programInvocations_;
    }

    const CreateUnitControl_Request::programInvocations_type& CreateUnitControl_Request::programInvocations() const {
        return *programInvocations_;
    }

    void CreateUnitControl_Request::programInvocations(const programInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void CreateUnitControl_Request::programInvocations(boost::shared_ptr< programInvocations_type> vl) {
        programInvocations_ = vl;
    }


    // sequence AddToUnitControl-Request

    AddToUnitControl_Request::AddToUnitControl_Request() : unitControl_(), domains_(), programInvocations_() {
    };

    AddToUnitControl_Request::AddToUnitControl_Request(const Identifier& arg__unitControl,
            const domains_type& arg__domains,
            const programInvocations_type& arg__programInvocations) :
    unitControl_(arg__unitControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };

    template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControl_, 0);
        ITU_T_IMPLICIT_TAG(domains_, 1);
        ITU_T_IMPLICIT_TAG(programInvocations_, 2);
    }

    template<> void AddToUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControl_, 0);
        ITU_T_IMPLICIT_TAG(domains_, 1);
        ITU_T_IMPLICIT_TAG(programInvocations_, 2);
    }

    Identifier& AddToUnitControl_Request::unitControl() {
        return *unitControl_;
    }

    const Identifier& AddToUnitControl_Request::unitControl() const {
        return *unitControl_;
    }

    void AddToUnitControl_Request::unitControl(const Identifier& vl) {
        unitControl_ = vl;
    }

    void AddToUnitControl_Request::unitControl(boost::shared_ptr< Identifier> vl) {
        unitControl_ = vl;
    }

    AddToUnitControl_Request::domains_type& AddToUnitControl_Request::domains() {
        return *domains_;
    }

    const AddToUnitControl_Request::domains_type& AddToUnitControl_Request::domains() const {
        return *domains_;
    }

    void AddToUnitControl_Request::domains(const domains_type& vl) {
        domains_ = vl;
    }

    void AddToUnitControl_Request::domains(boost::shared_ptr< domains_type> vl) {
        domains_ = vl;
    }

    AddToUnitControl_Request::programInvocations_type& AddToUnitControl_Request::programInvocations() {
        return *programInvocations_;
    }

    const AddToUnitControl_Request::programInvocations_type& AddToUnitControl_Request::programInvocations() const {
        return *programInvocations_;
    }

    void AddToUnitControl_Request::programInvocations(const programInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void AddToUnitControl_Request::programInvocations(boost::shared_ptr< programInvocations_type> vl) {
        programInvocations_ = vl;
    }


    // sequence RemoveFromUnitControl-Request

    RemoveFromUnitControl_Request::RemoveFromUnitControl_Request() : unitControl_(), domains_(), programInvocations_() {
    };

    RemoveFromUnitControl_Request::RemoveFromUnitControl_Request(const Identifier& arg__unitControl,
            const domains_type& arg__domains,
            const programInvocations_type& arg__programInvocations) :
    unitControl_(arg__unitControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };

    template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControl_, 0);
        ITU_T_IMPLICIT_TAG(domains_, 1);
        ITU_T_IMPLICIT_TAG(programInvocations_, 2);
    }

    template<> void RemoveFromUnitControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControl_, 0);
        ITU_T_IMPLICIT_TAG(domains_, 1);
        ITU_T_IMPLICIT_TAG(programInvocations_, 2);
    }

    Identifier& RemoveFromUnitControl_Request::unitControl() {
        return *unitControl_;
    }

    const Identifier& RemoveFromUnitControl_Request::unitControl() const {
        return *unitControl_;
    }

    void RemoveFromUnitControl_Request::unitControl(const Identifier& vl) {
        unitControl_ = vl;
    }

    void RemoveFromUnitControl_Request::unitControl(boost::shared_ptr< Identifier> vl) {
        unitControl_ = vl;
    }

    RemoveFromUnitControl_Request::domains_type& RemoveFromUnitControl_Request::domains() {
        return *domains_;
    }

    const RemoveFromUnitControl_Request::domains_type& RemoveFromUnitControl_Request::domains() const {
        return *domains_;
    }

    void RemoveFromUnitControl_Request::domains(const domains_type& vl) {
        domains_ = vl;
    }

    void RemoveFromUnitControl_Request::domains(boost::shared_ptr< domains_type> vl) {
        domains_ = vl;
    }

    RemoveFromUnitControl_Request::programInvocations_type& RemoveFromUnitControl_Request::programInvocations() {
        return *programInvocations_;
    }

    const RemoveFromUnitControl_Request::programInvocations_type& RemoveFromUnitControl_Request::programInvocations() const {
        return *programInvocations_;
    }

    void RemoveFromUnitControl_Request::programInvocations(const programInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void RemoveFromUnitControl_Request::programInvocations(boost::shared_ptr< programInvocations_type> vl) {
        programInvocations_ = vl;
    }


    // sequence GetUnitControlAttributes-Response

    GetUnitControlAttributes_Response::GetUnitControlAttributes_Response() : domains_(), programInvocations_() {
    };

    GetUnitControlAttributes_Response::GetUnitControlAttributes_Response(const domains_type& arg__domains,
            const programInvocations_type& arg__programInvocations) :
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };

    template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(domains_, 0);
        ITU_T_IMPLICIT_TAG(programInvocations_, 1);
    }

    template<> void GetUnitControlAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(domains_, 0);
        ITU_T_IMPLICIT_TAG(programInvocations_, 1);
    }

    GetUnitControlAttributes_Response::domains_type& GetUnitControlAttributes_Response::domains() {
        return *domains_;
    }

    const GetUnitControlAttributes_Response::domains_type& GetUnitControlAttributes_Response::domains() const {
        return *domains_;
    }

    void GetUnitControlAttributes_Response::domains(const domains_type& vl) {
        domains_ = vl;
    }

    void GetUnitControlAttributes_Response::domains(boost::shared_ptr< domains_type> vl) {
        domains_ = vl;
    }

    GetUnitControlAttributes_Response::programInvocations_type& GetUnitControlAttributes_Response::programInvocations() {
        return *programInvocations_;
    }

    const GetUnitControlAttributes_Response::programInvocations_type& GetUnitControlAttributes_Response::programInvocations() const {
        return *programInvocations_;
    }

    void GetUnitControlAttributes_Response::programInvocations(const programInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void GetUnitControlAttributes_Response::programInvocations(boost::shared_ptr< programInvocations_type> vl) {
        programInvocations_ = vl;
    }


    // sequence LoadUnitControlFromFile-Request

    LoadUnitControlFromFile_Request::LoadUnitControlFromFile_Request() : unitControlName_(), fileName_() {
    };

    LoadUnitControlFromFile_Request::LoadUnitControlFromFile_Request(const Identifier& arg__unitControlName,
            const FileName& arg__fileName) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName) {
    };

    LoadUnitControlFromFile_Request::LoadUnitControlFromFile_Request(boost::shared_ptr< Identifier> arg__unitControlName,
            boost::shared_ptr< FileName> arg__fileName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };

    template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    template<> void LoadUnitControlFromFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    Identifier& LoadUnitControlFromFile_Request::unitControlName() {
        return *unitControlName_;
    }

    const Identifier& LoadUnitControlFromFile_Request::unitControlName() const {
        return *unitControlName_;
    }

    void LoadUnitControlFromFile_Request::unitControlName(const Identifier& vl) {
        unitControlName_ = vl;
    }

    void LoadUnitControlFromFile_Request::unitControlName(boost::shared_ptr< Identifier> vl) {
        unitControlName_ = vl;
    }

    FileName& LoadUnitControlFromFile_Request::fileName() {
        return *fileName_;
    }

    const FileName& LoadUnitControlFromFile_Request::fileName() const {
        return *fileName_;
    }

    void LoadUnitControlFromFile_Request::fileName(const FileName& vl) {
        fileName_ = vl;
    }

    void LoadUnitControlFromFile_Request::fileName(boost::shared_ptr< FileName> vl) {
        fileName_ = vl;
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> LoadUnitControlFromFile_Request::thirdParty__new() {
        return thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void LoadUnitControlFromFile_Request::thirdParty(const MMS_Environment_1::ApplicationReference& vl) {
        thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }


    // choice LoadUnitControlFromFile-Error

    void LoadUnitControlFromFile_Error::none(const null_type& vl) {
        set<null_type>(new null_type(vl), LoadUnitControlFromFile_Error_none);
    }

    void LoadUnitControlFromFile_Error::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), LoadUnitControlFromFile_Error_domain);
    }

    void LoadUnitControlFromFile_Error::programInvocation(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), LoadUnitControlFromFile_Error_programInvocation);
    }

    template<> void LoadUnitControlFromFile_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case LoadUnitControlFromFile_Error_none:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, LoadUnitControlFromFile_Error_none), 0);
                break;
            }
            case LoadUnitControlFromFile_Error_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, LoadUnitControlFromFile_Error_domain), 1);
                break;
            }
            case LoadUnitControlFromFile_Error_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, LoadUnitControlFromFile_Error_programInvocation), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, LoadUnitControlFromFile_Error_none), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, LoadUnitControlFromFile_Error_domain), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, LoadUnitControlFromFile_Error_programInvocation), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    StoreUnitControlToFile_Request::StoreUnitControlToFile_Request() : unitControlName_(), fileName_() {
    };

    StoreUnitControlToFile_Request::StoreUnitControlToFile_Request(const Identifier& arg__unitControlName,
            const FileName& arg__fileName) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName) {
    };

    StoreUnitControlToFile_Request::StoreUnitControlToFile_Request(boost::shared_ptr< Identifier> arg__unitControlName,
            boost::shared_ptr< FileName> arg__fileName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__thirdParty) :
    unitControlName_(arg__unitControlName),
    fileName_(arg__fileName),
    thirdParty_(arg__thirdParty) {
    };

    template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    template<> void StoreUnitControlToFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unitControlName_, 0);
        ITU_T_IMPLICIT_TAG(fileName_, 1);
        ITU_T_IMPLICIT_TAG(thirdParty_, 2);
    }

    Identifier& StoreUnitControlToFile_Request::unitControlName() {
        return *unitControlName_;
    }

    const Identifier& StoreUnitControlToFile_Request::unitControlName() const {
        return *unitControlName_;
    }

    void StoreUnitControlToFile_Request::unitControlName(const Identifier& vl) {
        unitControlName_ = vl;
    }

    void StoreUnitControlToFile_Request::unitControlName(boost::shared_ptr< Identifier> vl) {
        unitControlName_ = vl;
    }

    FileName& StoreUnitControlToFile_Request::fileName() {
        return *fileName_;
    }

    const FileName& StoreUnitControlToFile_Request::fileName() const {
        return *fileName_;
    }

    void StoreUnitControlToFile_Request::fileName(const FileName& vl) {
        fileName_ = vl;
    }

    void StoreUnitControlToFile_Request::fileName(boost::shared_ptr< FileName> vl) {
        fileName_ = vl;
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> StoreUnitControlToFile_Request::thirdParty__new() {
        return thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void StoreUnitControlToFile_Request::thirdParty(const MMS_Environment_1::ApplicationReference& vl) {
        thirdParty_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }


    // choice DeleteUnitControl-Error

    void DeleteUnitControl_Error::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), DeleteUnitControl_Error_domain);
    }

    void DeleteUnitControl_Error::programInvocation(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), DeleteUnitControl_Error_programInvocation);
    }

    template<> void DeleteUnitControl_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteUnitControl_Error_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, DeleteUnitControl_Error_domain), 0);
                break;
            }
            case DeleteUnitControl_Error_programInvocation:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, DeleteUnitControl_Error_programInvocation), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, DeleteUnitControl_Error_domain), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, DeleteUnitControl_Error_programInvocation), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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
                ITU_T_CHOICE_TAG(value<ObjectName > (false, TypeSpecification_typeName), 0);
                break;
            }
            case TypeSpecification_typeDescription:
            {
                ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (false, TypeSpecification_typeDescription));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, TypeSpecification_typeName), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(value<MMS_Object_Module_1::TypeDescription > (true, TypeSpecification_typeDescription))) return;
                else free();
            }
        }
    }

    AlternateAccess_sequence_of::named_type::named_type() : componentName_(), access_() {
    };

    AlternateAccess_sequence_of::named_type::named_type(const Identifier& arg__componentName,
            const AlternateAccessSelection& arg__access) :
    componentName_(arg__componentName),
    access_(arg__access) {
    };

    template<> void AlternateAccess_sequence_of::named_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_BIND_CHOICE(access_);
    }

    template<> void AlternateAccess_sequence_of::named_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_BIND_CHOICE(access_);
    }

    Identifier& AlternateAccess_sequence_of::named_type::componentName() {
        return *componentName_;
    }

    const Identifier& AlternateAccess_sequence_of::named_type::componentName() const {
        return *componentName_;
    }

    void AlternateAccess_sequence_of::named_type::componentName(const Identifier& vl) {
        componentName_ = vl;
    }

    void AlternateAccess_sequence_of::named_type::componentName(boost::shared_ptr< Identifier> vl) {
        componentName_ = vl;
    }

    AlternateAccessSelection& AlternateAccess_sequence_of::named_type::access() {
        return *access_;
    }

    const AlternateAccessSelection& AlternateAccess_sequence_of::named_type::access() const {
        return *access_;
    }

    void AlternateAccess_sequence_of::named_type::access(const AlternateAccessSelection& vl) {
        access_ = vl;
    }

    void AlternateAccess_sequence_of::named_type::access(boost::shared_ptr< AlternateAccessSelection> vl) {
        access_ = vl;
    }

    template<> void AlternateAccess_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AlternateAccess_sequence_of_unnamed:
            {
                ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (false, AlternateAccess_sequence_of_unnamed));
                break;
            }
            case AlternateAccess_sequence_of_named:
            {
                ITU_T_IMPLICIT_TAG(value<named_type > (false, AlternateAccess_sequence_of_named), 5);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<named_type > (true, AlternateAccess_sequence_of_named), 5)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(value<AlternateAccessSelection > (true, AlternateAccess_sequence_of_unnamed))) return;
                else free();
            }
        }
    }


    // choice AlternateAccessSelection

    AlternateAccessSelection::selectAlternateAccess_type::selectAlternateAccess_type() : accessSelection_(), alternateAccess_() {
    };

    AlternateAccessSelection::selectAlternateAccess_type::selectAlternateAccess_type(const accessSelection_type& arg__accessSelection,
            const AlternateAccess& arg__alternateAccess) :
    accessSelection_(arg__accessSelection),
    alternateAccess_(arg__alternateAccess) {
    };

    AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::indexRange_type() : lowIndex_(), numberOfElements_() {
    };

    AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::indexRange_type(const Unsigned32& arg__lowIndex,
            const Unsigned32& arg__numberOfElements) :
    lowIndex_(arg__lowIndex),
    numberOfElements_(arg__numberOfElements) {
    };

    template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(numberOfElements_, 1);
    }

    template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(numberOfElements_, 1);
    }

    Unsigned32& AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::lowIndex() {
        return *lowIndex_;
    }

    const Unsigned32& AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::lowIndex() const {
        return *lowIndex_;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::lowIndex(const Unsigned32& vl) {
        lowIndex_ = vl;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::lowIndex(boost::shared_ptr< Unsigned32> vl) {
        lowIndex_ = vl;
    }

    Unsigned32& AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::numberOfElements() {
        return *numberOfElements_;
    }

    const Unsigned32& AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::numberOfElements() const {
        return *numberOfElements_;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::numberOfElements(const Unsigned32& vl) {
        numberOfElements_ = vl;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::indexRange_type::numberOfElements(boost::shared_ptr< Unsigned32> vl) {
        numberOfElements_ = vl;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::component(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), accessSelection_type_component);
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::index(const Unsigned32& vl) {
        set<Unsigned32>(new Unsigned32(vl), accessSelection_type_index);
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::allElements(const null_type& vl) {
        set<null_type>(new null_type(vl), accessSelection_type_allElements);
    }

    template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case accessSelection_type_component:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, accessSelection_type_component), 0);
                break;
            }
            case accessSelection_type_index:
            {
                ITU_T_IMPLICIT_TAG(value<Unsigned32 > (false, accessSelection_type_index), 1);
                break;
            }
            case accessSelection_type_indexRange:
            {
                ITU_T_IMPLICIT_TAG(value<indexRange_type > (false, accessSelection_type_indexRange), 2);
                break;
            }
            case accessSelection_type_allElements:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, accessSelection_type_allElements), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, accessSelection_type_component), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Unsigned32 > (true, accessSelection_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<indexRange_type > (true, accessSelection_type_indexRange), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, accessSelection_type_allElements), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void AlternateAccessSelection::selectAlternateAccess_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(accessSelection_);
        ITU_T_BIND_TAG(alternateAccess_);
    }

    template<> void AlternateAccessSelection::selectAlternateAccess_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(accessSelection_);
        ITU_T_BIND_TAG(alternateAccess_);
    }

    AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type& AlternateAccessSelection::selectAlternateAccess_type::accessSelection() {
        return *accessSelection_;
    }

    const AlternateAccessSelection::selectAlternateAccess_type::accessSelection_type& AlternateAccessSelection::selectAlternateAccess_type::accessSelection() const {
        return *accessSelection_;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection(const accessSelection_type& vl) {
        accessSelection_ = vl;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::accessSelection(boost::shared_ptr< accessSelection_type> vl) {
        accessSelection_ = vl;
    }

    AlternateAccess& AlternateAccessSelection::selectAlternateAccess_type::alternateAccess() {
        return *alternateAccess_;
    }

    const AlternateAccess& AlternateAccessSelection::selectAlternateAccess_type::alternateAccess() const {
        return *alternateAccess_;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::alternateAccess(const AlternateAccess& vl) {
        alternateAccess_ = vl;
    }

    void AlternateAccessSelection::selectAlternateAccess_type::alternateAccess(boost::shared_ptr< AlternateAccess> vl) {
        alternateAccess_ = vl;
    }

    AlternateAccessSelection::selectAccess_type::indexRange_type::indexRange_type() : lowIndex_(), numberOfElements_() {
    };

    AlternateAccessSelection::selectAccess_type::indexRange_type::indexRange_type(const Unsigned32& arg__lowIndex,
            const Unsigned32& arg__numberOfElements) :
    lowIndex_(arg__lowIndex),
    numberOfElements_(arg__numberOfElements) {
    };

    template<> void AlternateAccessSelection::selectAccess_type::indexRange_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(numberOfElements_, 1);
    }

    template<> void AlternateAccessSelection::selectAccess_type::indexRange_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(lowIndex_, 0);
        ITU_T_IMPLICIT_TAG(numberOfElements_, 1);
    }

    Unsigned32& AlternateAccessSelection::selectAccess_type::indexRange_type::lowIndex() {
        return *lowIndex_;
    }

    const Unsigned32& AlternateAccessSelection::selectAccess_type::indexRange_type::lowIndex() const {
        return *lowIndex_;
    }

    void AlternateAccessSelection::selectAccess_type::indexRange_type::lowIndex(const Unsigned32& vl) {
        lowIndex_ = vl;
    }

    void AlternateAccessSelection::selectAccess_type::indexRange_type::lowIndex(boost::shared_ptr< Unsigned32> vl) {
        lowIndex_ = vl;
    }

    Unsigned32& AlternateAccessSelection::selectAccess_type::indexRange_type::numberOfElements() {
        return *numberOfElements_;
    }

    const Unsigned32& AlternateAccessSelection::selectAccess_type::indexRange_type::numberOfElements() const {
        return *numberOfElements_;
    }

    void AlternateAccessSelection::selectAccess_type::indexRange_type::numberOfElements(const Unsigned32& vl) {
        numberOfElements_ = vl;
    }

    void AlternateAccessSelection::selectAccess_type::indexRange_type::numberOfElements(boost::shared_ptr< Unsigned32> vl) {
        numberOfElements_ = vl;
    }

    void AlternateAccessSelection::selectAccess_type::component(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), selectAccess_type_component);
    }

    void AlternateAccessSelection::selectAccess_type::index(const Unsigned32& vl) {
        set<Unsigned32>(new Unsigned32(vl), selectAccess_type_index);
    }

    void AlternateAccessSelection::selectAccess_type::allElements(const null_type& vl) {
        set<null_type>(new null_type(vl), selectAccess_type_allElements);
    }

    template<> void AlternateAccessSelection::selectAccess_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case selectAccess_type_component:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, selectAccess_type_component), 1);
                break;
            }
            case selectAccess_type_index:
            {
                ITU_T_IMPLICIT_TAG(value<Unsigned32 > (false, selectAccess_type_index), 2);
                break;
            }
            case selectAccess_type_indexRange:
            {
                ITU_T_IMPLICIT_TAG(value<indexRange_type > (false, selectAccess_type_indexRange), 3);
                break;
            }
            case selectAccess_type_allElements:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, selectAccess_type_allElements), 4);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlternateAccessSelection::selectAccess_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, selectAccess_type_component), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Unsigned32 > (true, selectAccess_type_index), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<indexRange_type > (true, selectAccess_type_indexRange), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, selectAccess_type_allElements), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void AlternateAccessSelection::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AlternateAccessSelection_selectAlternateAccess:
            {
                ITU_T_IMPLICIT_TAG(value<selectAlternateAccess_type > (false, AlternateAccessSelection_selectAlternateAccess), 0);
                break;
            }
            case AlternateAccessSelection_selectAccess:
            {
                ITU_T_BIND_CHOICE(value<selectAccess_type > (false, AlternateAccessSelection_selectAccess));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<selectAlternateAccess_type > (true, AlternateAccessSelection_selectAlternateAccess), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(value<selectAccess_type > (true, AlternateAccessSelection_selectAccess))) return;
                else free();
            }
        }
    }


    // choice AccessResult

    void AccessResult::failure(const DataAccessError& vl) {
        set<DataAccessError>(new DataAccessError(vl), AccessResult_failure);
    }

    template<> void AccessResult::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AccessResult_failure:
            {
                ITU_T_IMPLICIT_TAG(value<DataAccessError > (false, AccessResult_failure), 0);
                break;
            }
            case AccessResult_success:
            {
                ITU_T_BIND_CHOICE(value<Data > (false, AccessResult_success));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DataAccessError > (true, AccessResult_failure), 0)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_CHOICE(value<Data > (true, AccessResult_success))) return;
                else free();
            }
        }
    }


    // choice Data

    void Data::boolean(const bool& vl) {
        set<bool>(new bool(vl), Data_boolean);
    }

    void Data::bit_string(const bitstring_type& vl) {
        set<bitstring_type>(new bitstring_type(vl), Data_bit_string);
    }

    void Data::integer(const int& vl) {
        set<int>(new int(vl), Data_integer);
    }

    void Data::unsignedV(const int& vl) {
        set<int>(new int(vl), Data_unsignedV);
    }

    void Data::floating_point(const FloatingPoint& vl) {
        set<FloatingPoint>(new FloatingPoint(vl), Data_floating_point);
    }

    void Data::octet_string(const octetstring_type& vl) {
        set<octetstring_type>(new octetstring_type(vl), Data_octet_string);
    }

    void Data::visible_string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), Data_visible_string);
    }

    void Data::generalized_time(const gentime_type& vl) {
        set<gentime_type>(new gentime_type(vl), Data_generalized_time);
    }

    void Data::binary_time(const TimeOfDay& vl) {
        set<TimeOfDay>(new TimeOfDay(vl), Data_binary_time);
    }

    void Data::bcd(const int& vl) {
        set<int>(new int(vl), Data_bcd);
    }

    void Data::booleanArray(const bitstring_type& vl) {
        set<bitstring_type>(new bitstring_type(vl), Data_booleanArray);
    }

    void Data::objId(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Data_objId);
    }

    void Data::mMSString(const MMSString& vl) {
        set<MMSString>(new MMSString(vl), Data_mMSString);
    }

    template<> void Data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Data_array:
            {
                ITU_T_IMPLICIT_TAG(value<array_type > (false, Data_array), 1);
                break;
            }
            case Data_structure:
            {
                ITU_T_IMPLICIT_TAG(value<structure_type > (false, Data_structure), 2);
                break;
            }
            case Data_boolean:
            {
                ITU_T_IMPLICIT_TAG(value<bool > (false, Data_boolean), 3);
                break;
            }
            case Data_bit_string:
            {
                ITU_T_IMPLICIT_TAG(value<bitstring_type > (false, Data_bit_string), 4);
                break;
            }
            case Data_integer:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, Data_integer), 5);
                break;
            }
            case Data_unsignedV:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, Data_unsignedV), 6);
                break;
            }
            case Data_floating_point:
            {
                ITU_T_IMPLICIT_TAG(value<FloatingPoint > (false, Data_floating_point), 7);
                break;
            }
            case Data_octet_string:
            {
                ITU_T_IMPLICIT_TAG(value<octetstring_type > (false, Data_octet_string), 9);
                break;
            }
            case Data_visible_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, Data_visible_string), 10);
                break;
            }
            case Data_generalized_time:
            {
                ITU_T_IMPLICIT_TAG(value<gentime_type > (false, Data_generalized_time), 11);
                break;
            }
            case Data_binary_time:
            {
                ITU_T_IMPLICIT_TAG(value<TimeOfDay > (false, Data_binary_time), 12);
                break;
            }
            case Data_bcd:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, Data_bcd), 13);
                break;
            }
            case Data_booleanArray:
            {
                ITU_T_IMPLICIT_TAG(value<bitstring_type > (false, Data_booleanArray), 14);
                break;
            }
            case Data_objId:
            {
                ITU_T_IMPLICIT_TAG(value<oid_type > (false, Data_objId), 15);
                break;
            }
            case Data_mMSString:
            {
                ITU_T_IMPLICIT_TAG(value<MMSString > (false, Data_mMSString), 16);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<array_type > (true, Data_array), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<structure_type > (true, Data_structure), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<bool > (true, Data_boolean), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<bitstring_type > (true, Data_bit_string), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, Data_integer), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, Data_unsignedV), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<FloatingPoint > (true, Data_floating_point), 7)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<octetstring_type > (true, Data_octet_string), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, Data_visible_string), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<gentime_type > (true, Data_generalized_time), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TimeOfDay > (true, Data_binary_time), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, Data_bcd), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<bitstring_type > (true, Data_booleanArray), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<oid_type > (true, Data_objId), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<MMSString > (true, Data_mMSString), 16)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    const DataAccessError DataAccessError_object_invalidated = 0;
    const DataAccessError DataAccessError_hardware_fault = 1;
    const DataAccessError DataAccessError_temporarily_unavailable = 2;
    const DataAccessError DataAccessError_object_access_denied = 3;
    const DataAccessError DataAccessError_object_undefined = 4;
    const DataAccessError DataAccessError_invalid_address = 5;
    const DataAccessError DataAccessError_type_unsupported = 6;
    const DataAccessError DataAccessError_type_inconsistent = 7;
    const DataAccessError DataAccessError_object_attribute_inconsistent = 8;
    const DataAccessError DataAccessError_object_access_unsupported = 9;
    const DataAccessError DataAccessError_object_non_existent = 10;
    const DataAccessError DataAccessError_object_value_invalid = 11;

    // choice VariableAccessSpecification

    VariableAccessSpecification::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of() : variableSpecification_() {
    };

    VariableAccessSpecification::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    VariableAccessSpecification::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of(boost::shared_ptr< VariableSpecification> arg__variableSpecification,
            boost::shared_ptr< AlternateAccess> arg__alternateAccess) :
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };

    template<> void VariableAccessSpecification::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    template<> void VariableAccessSpecification::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    VariableSpecification& VariableAccessSpecification::listOfVariable_type_sequence_of::variableSpecification() {
        return *variableSpecification_;
    }

    const VariableSpecification& VariableAccessSpecification::listOfVariable_type_sequence_of::variableSpecification() const {
        return *variableSpecification_;
    }

    void VariableAccessSpecification::listOfVariable_type_sequence_of::variableSpecification(const VariableSpecification& vl) {
        variableSpecification_ = vl;
    }

    void VariableAccessSpecification::listOfVariable_type_sequence_of::variableSpecification(boost::shared_ptr< VariableSpecification> vl) {
        variableSpecification_ = vl;
    }

    boost::shared_ptr<AlternateAccess> VariableAccessSpecification::listOfVariable_type_sequence_of::alternateAccess__new() {
        return alternateAccess_ = boost::shared_ptr<AlternateAccess>(new AlternateAccess());
    }

    void VariableAccessSpecification::listOfVariable_type_sequence_of::alternateAccess(const AlternateAccess& vl) {
        alternateAccess_ = boost::shared_ptr<AlternateAccess>(new AlternateAccess(vl));
    }

    template<> void VariableAccessSpecification::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case VariableAccessSpecification_listOfVariable:
            {
                ITU_T_IMPLICIT_TAG(value<listOfVariable_type > (false, VariableAccessSpecification_listOfVariable), 0);
                break;
            }
            case VariableAccessSpecification_variableListName:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, VariableAccessSpecification_variableListName), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<listOfVariable_type > (true, VariableAccessSpecification_listOfVariable), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, VariableAccessSpecification_variableListName), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    // choice VariableSpecification

    VariableSpecification::variableDescription_type::variableDescription_type() : address_(), typeSpecification_() {
    };

    VariableSpecification::variableDescription_type::variableDescription_type(const MMS_Object_Module_1::Address& arg__address,
            const TypeSpecification& arg__typeSpecification) :
    address_(arg__address),
    typeSpecification_(arg__typeSpecification) {
    };

    template<> void VariableSpecification::variableDescription_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(address_);
        ITU_T_BIND_CHOICE(typeSpecification_);
    }

    template<> void VariableSpecification::variableDescription_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(address_);
        ITU_T_BIND_CHOICE(typeSpecification_);
    }

    MMS_Object_Module_1::Address& VariableSpecification::variableDescription_type::address() {
        return *address_;
    }

    const MMS_Object_Module_1::Address& VariableSpecification::variableDescription_type::address() const {
        return *address_;
    }

    void VariableSpecification::variableDescription_type::address(const MMS_Object_Module_1::Address& vl) {
        address_ = vl;
    }

    void VariableSpecification::variableDescription_type::address(boost::shared_ptr< MMS_Object_Module_1::Address> vl) {
        address_ = vl;
    }

    TypeSpecification& VariableSpecification::variableDescription_type::typeSpecification() {
        return *typeSpecification_;
    }

    const TypeSpecification& VariableSpecification::variableDescription_type::typeSpecification() const {
        return *typeSpecification_;
    }

    void VariableSpecification::variableDescription_type::typeSpecification(const TypeSpecification& vl) {
        typeSpecification_ = vl;
    }

    void VariableSpecification::variableDescription_type::typeSpecification(boost::shared_ptr< TypeSpecification> vl) {
        typeSpecification_ = vl;
    }

    void VariableSpecification::invalidated(const null_type& vl) {
        set<null_type>(new null_type(vl), VariableSpecification_invalidated);
    }

    template<> void VariableSpecification::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case VariableSpecification_name:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, VariableSpecification_name), 0);
                break;
            }
            case VariableSpecification_address:
            {
                ITU_T_CHOICE_TAG(value<MMS_Object_Module_1::Address > (false, VariableSpecification_address), 1);
                break;
            }
            case VariableSpecification_variableDescription:
            {
                ITU_T_IMPLICIT_TAG(value<variableDescription_type > (false, VariableSpecification_variableDescription), 2);
                break;
            }
            case VariableSpecification_scatteredAccessDescription:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ScatteredAccessDescription > (false, VariableSpecification_scatteredAccessDescription), 3);
                break;
            }
            case VariableSpecification_invalidated:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, VariableSpecification_invalidated), 4);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, VariableSpecification_name), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<MMS_Object_Module_1::Address > (true, VariableSpecification_address), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<variableDescription_type > (true, VariableSpecification_variableDescription), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1A::ScatteredAccessDescription > (true, VariableSpecification_scatteredAccessDescription), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, VariableSpecification_invalidated), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    // sequence Read-Request

    Read_Request::Read_Request() : variableAccessSpecification_() {
    };

    Read_Request::Read_Request(const VariableAccessSpecification& arg__variableAccessSpecification) :
    variableAccessSpecification_(arg__variableAccessSpecification) {
    };

    Read_Request::Read_Request(boost::shared_ptr< bool> arg__specificationWithResult,
            boost::shared_ptr< VariableAccessSpecification> arg__variableAccessSpecification) :
    specificationWithResult_(arg__specificationWithResult),
    variableAccessSpecification_(arg__variableAccessSpecification) {
    };

    const bool Read_Request::specificationWithResult__default = false;

    template<> void Read_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(specificationWithResult_, 0);
        ITU_T_CHOICE_TAG(variableAccessSpecification_, 1);
    }

    template<> void Read_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(specificationWithResult_, 0);
        ITU_T_CHOICE_TAG(variableAccessSpecification_, 1);
    }

    const bool& Read_Request::specificationWithResult() const {
        return *specificationWithResult_;
    }

    void Read_Request::specificationWithResult(const bool& vl) {
        specificationWithResult_ = vl;
    }

    void Read_Request::specificationWithResult(boost::shared_ptr< bool> vl) {
        specificationWithResult_ = vl;
    }

    VariableAccessSpecification& Read_Request::variableAccessSpecification() {
        return *variableAccessSpecification_;
    }

    const VariableAccessSpecification& Read_Request::variableAccessSpecification() const {
        return *variableAccessSpecification_;
    }

    void Read_Request::variableAccessSpecification(const VariableAccessSpecification& vl) {
        variableAccessSpecification_ = vl;
    }

    void Read_Request::variableAccessSpecification(boost::shared_ptr< VariableAccessSpecification> vl) {
        variableAccessSpecification_ = vl;
    }


    // sequence Read-Response

    Read_Response::Read_Response() : listOfAccessResult_() {
    };

    Read_Response::Read_Response(const listOfAccessResult_type& arg__listOfAccessResult) :
    listOfAccessResult_(arg__listOfAccessResult) {
    };

    Read_Response::Read_Response(boost::shared_ptr< VariableAccessSpecification> arg__variableAccessSpecification,
            boost::shared_ptr< listOfAccessResult_type> arg__listOfAccessResult) :
    variableAccessSpecification_(arg__variableAccessSpecification),
    listOfAccessResult_(arg__listOfAccessResult) {
    };

    template<> void Read_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(variableAccessSpecification_, 0);
        ITU_T_IMPLICIT_TAG(listOfAccessResult_, 1);
    }

    template<> void Read_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(variableAccessSpecification_, 0);
        ITU_T_IMPLICIT_TAG(listOfAccessResult_, 1);
    }

    boost::shared_ptr<VariableAccessSpecification> Read_Response::variableAccessSpecification__new() {
        return variableAccessSpecification_ = boost::shared_ptr<VariableAccessSpecification>(new VariableAccessSpecification());
    }

    void Read_Response::variableAccessSpecification(const VariableAccessSpecification& vl) {
        variableAccessSpecification_ = boost::shared_ptr<VariableAccessSpecification>(new VariableAccessSpecification(vl));
    }

    Read_Response::listOfAccessResult_type& Read_Response::listOfAccessResult() {
        return *listOfAccessResult_;
    }

    const Read_Response::listOfAccessResult_type& Read_Response::listOfAccessResult() const {
        return *listOfAccessResult_;
    }

    void Read_Response::listOfAccessResult(const listOfAccessResult_type& vl) {
        listOfAccessResult_ = vl;
    }

    void Read_Response::listOfAccessResult(boost::shared_ptr< listOfAccessResult_type> vl) {
        listOfAccessResult_ = vl;
    }


    // sequence Write-Request

    Write_Request::Write_Request() : variableAccessSpecification_(), listOfData_() {
    };

    Write_Request::Write_Request(const VariableAccessSpecification& arg__variableAccessSpecification,
            const listOfData_type& arg__listOfData) :
    variableAccessSpecification_(arg__variableAccessSpecification),
    listOfData_(arg__listOfData) {
    };

    template<> void Write_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(listOfData_, 0);
    }

    template<> void Write_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(listOfData_, 0);
    }

    VariableAccessSpecification& Write_Request::variableAccessSpecification() {
        return *variableAccessSpecification_;
    }

    const VariableAccessSpecification& Write_Request::variableAccessSpecification() const {
        return *variableAccessSpecification_;
    }

    void Write_Request::variableAccessSpecification(const VariableAccessSpecification& vl) {
        variableAccessSpecification_ = vl;
    }

    void Write_Request::variableAccessSpecification(boost::shared_ptr< VariableAccessSpecification> vl) {
        variableAccessSpecification_ = vl;
    }

    Write_Request::listOfData_type& Write_Request::listOfData() {
        return *listOfData_;
    }

    const Write_Request::listOfData_type& Write_Request::listOfData() const {
        return *listOfData_;
    }

    void Write_Request::listOfData(const listOfData_type& vl) {
        listOfData_ = vl;
    }

    void Write_Request::listOfData(boost::shared_ptr< listOfData_type> vl) {
        listOfData_ = vl;
    }

    void Write_Response_sequence_of::failure(const DataAccessError& vl) {
        set<DataAccessError>(new DataAccessError(vl), Write_Response_sequence_of_failure);
    }

    void Write_Response_sequence_of::success(const null_type& vl) {
        set<null_type>(new null_type(vl), Write_Response_sequence_of_success);
    }

    template<> void Write_Response_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Write_Response_sequence_of_failure:
            {
                ITU_T_IMPLICIT_TAG(value<DataAccessError > (false, Write_Response_sequence_of_failure), 0);
                break;
            }
            case Write_Response_sequence_of_success:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, Write_Response_sequence_of_success), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<DataAccessError > (true, Write_Response_sequence_of_failure), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, Write_Response_sequence_of_success), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    InformationReport::InformationReport() : variableAccessSpecification_(), listOfAccessResult_() {
    };

    InformationReport::InformationReport(const VariableAccessSpecification& arg__variableAccessSpecification,
            const listOfAccessResult_type& arg__listOfAccessResult) :
    variableAccessSpecification_(arg__variableAccessSpecification),
    listOfAccessResult_(arg__listOfAccessResult) {
    };

    template<> void InformationReport::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(listOfAccessResult_, 0);
    }

    template<> void InformationReport::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(variableAccessSpecification_);
        ITU_T_IMPLICIT_TAG(listOfAccessResult_, 0);
    }

    VariableAccessSpecification& InformationReport::variableAccessSpecification() {
        return *variableAccessSpecification_;
    }

    const VariableAccessSpecification& InformationReport::variableAccessSpecification() const {
        return *variableAccessSpecification_;
    }

    void InformationReport::variableAccessSpecification(const VariableAccessSpecification& vl) {
        variableAccessSpecification_ = vl;
    }

    void InformationReport::variableAccessSpecification(boost::shared_ptr< VariableAccessSpecification> vl) {
        variableAccessSpecification_ = vl;
    }

    InformationReport::listOfAccessResult_type& InformationReport::listOfAccessResult() {
        return *listOfAccessResult_;
    }

    const InformationReport::listOfAccessResult_type& InformationReport::listOfAccessResult() const {
        return *listOfAccessResult_;
    }

    void InformationReport::listOfAccessResult(const listOfAccessResult_type& vl) {
        listOfAccessResult_ = vl;
    }

    void InformationReport::listOfAccessResult(boost::shared_ptr< listOfAccessResult_type> vl) {
        listOfAccessResult_ = vl;
    }


    // choice GetVariableAccessAttributes-Request

    template<> void GetVariableAccessAttributes_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case GetVariableAccessAttributes_Request_name:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, GetVariableAccessAttributes_Request_name), 0);
                break;
            }
            case GetVariableAccessAttributes_Request_address:
            {
                ITU_T_CHOICE_TAG(value<MMS_Object_Module_1::Address > (false, GetVariableAccessAttributes_Request_address), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, GetVariableAccessAttributes_Request_name), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<MMS_Object_Module_1::Address > (true, GetVariableAccessAttributes_Request_address), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    GetVariableAccessAttributes_Response::GetVariableAccessAttributes_Response() : mmsDeletable_(), typeDescription_() {
    };

    GetVariableAccessAttributes_Response::GetVariableAccessAttributes_Response(const bool& arg__mmsDeletable,
            const MMS_Object_Module_1::TypeDescription& arg__typeDescription) :
    mmsDeletable_(arg__mmsDeletable),
    typeDescription_(arg__typeDescription) {
    };

    GetVariableAccessAttributes_Response::GetVariableAccessAttributes_Response(boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< MMS_Object_Module_1::Address> arg__address,
            boost::shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
            boost::shared_ptr< Identifier> arg__accessControlList,
            boost::shared_ptr< visiblestring_type> arg__meaning) :
    mmsDeletable_(arg__mmsDeletable),
    address_(arg__address),
    typeDescription_(arg__typeDescription),
    accessControlList_(arg__accessControlList),
    meaning_(arg__meaning) {
    };

    template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_CHOICE_TAG(address_, 1);
        ITU_T_CHOICE_TAG(typeDescription_, 2);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    template<> void GetVariableAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_CHOICE_TAG(address_, 1);
        ITU_T_CHOICE_TAG(typeDescription_, 2);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    bool& GetVariableAccessAttributes_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& GetVariableAccessAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetVariableAccessAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetVariableAccessAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::Address> GetVariableAccessAttributes_Response::address__new() {
        return address_ = boost::shared_ptr<MMS_Object_Module_1::Address>(new MMS_Object_Module_1::Address());
    }

    void GetVariableAccessAttributes_Response::address(const MMS_Object_Module_1::Address& vl) {
        address_ = boost::shared_ptr<MMS_Object_Module_1::Address>(new MMS_Object_Module_1::Address(vl));
    }

    MMS_Object_Module_1::TypeDescription& GetVariableAccessAttributes_Response::typeDescription() {
        return *typeDescription_;
    }

    const MMS_Object_Module_1::TypeDescription& GetVariableAccessAttributes_Response::typeDescription() const {
        return *typeDescription_;
    }

    void GetVariableAccessAttributes_Response::typeDescription(const MMS_Object_Module_1::TypeDescription& vl) {
        typeDescription_ = vl;
    }

    void GetVariableAccessAttributes_Response::typeDescription(boost::shared_ptr< MMS_Object_Module_1::TypeDescription> vl) {
        typeDescription_ = vl;
    }

    boost::shared_ptr<Identifier> GetVariableAccessAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetVariableAccessAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    boost::shared_ptr<visiblestring_type> GetVariableAccessAttributes_Response::meaning__new() {
        return meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void GetVariableAccessAttributes_Response::meaning(const visiblestring_type& vl) {
        meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }


    // sequence DefineNamedVariable-Request

    DefineNamedVariable_Request::DefineNamedVariable_Request() : variableName_(), address_() {
    };

    DefineNamedVariable_Request::DefineNamedVariable_Request(const ObjectName& arg__variableName,
            const MMS_Object_Module_1::Address& arg__address) :
    variableName_(arg__variableName),
    address_(arg__address) {
    };

    DefineNamedVariable_Request::DefineNamedVariable_Request(boost::shared_ptr< ObjectName> arg__variableName,
            boost::shared_ptr< MMS_Object_Module_1::Address> arg__address,
            boost::shared_ptr< TypeSpecification> arg__typeSpecification) :
    variableName_(arg__variableName),
    address_(arg__address),
    typeSpecification_(arg__typeSpecification) {
    };

    template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(variableName_, 0);
        ITU_T_CHOICE_TAG(address_, 1);
        ITU_T_CHOICE_TAG(typeSpecification_, 2);
    }

    template<> void DefineNamedVariable_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(variableName_, 0);
        ITU_T_CHOICE_TAG(address_, 1);
        ITU_T_CHOICE_TAG(typeSpecification_, 2);
    }

    ObjectName& DefineNamedVariable_Request::variableName() {
        return *variableName_;
    }

    const ObjectName& DefineNamedVariable_Request::variableName() const {
        return *variableName_;
    }

    void DefineNamedVariable_Request::variableName(const ObjectName& vl) {
        variableName_ = vl;
    }

    void DefineNamedVariable_Request::variableName(boost::shared_ptr< ObjectName> vl) {
        variableName_ = vl;
    }

    MMS_Object_Module_1::Address& DefineNamedVariable_Request::address() {
        return *address_;
    }

    const MMS_Object_Module_1::Address& DefineNamedVariable_Request::address() const {
        return *address_;
    }

    void DefineNamedVariable_Request::address(const MMS_Object_Module_1::Address& vl) {
        address_ = vl;
    }

    void DefineNamedVariable_Request::address(boost::shared_ptr< MMS_Object_Module_1::Address> vl) {
        address_ = vl;
    }

    boost::shared_ptr<TypeSpecification> DefineNamedVariable_Request::typeSpecification__new() {
        return typeSpecification_ = boost::shared_ptr<TypeSpecification>(new TypeSpecification());
    }

    void DefineNamedVariable_Request::typeSpecification(const TypeSpecification& vl) {
        typeSpecification_ = boost::shared_ptr<TypeSpecification>(new TypeSpecification(vl));
    }


    // sequence DeleteVariableAccess-Request
    const int DeleteVariableAccess_Request::scopeOfDelete_specific = 0;
    const int DeleteVariableAccess_Request::scopeOfDelete_aa_specific = 1;
    const int DeleteVariableAccess_Request::scopeOfDelete_domain = 2;
    const int DeleteVariableAccess_Request::scopeOfDelete_vmd = 3;

    DeleteVariableAccess_Request::DeleteVariableAccess_Request() {
    };

    DeleteVariableAccess_Request::DeleteVariableAccess_Request(boost::shared_ptr< int> arg__scopeOfDelete,
            boost::shared_ptr< listOfName_type> arg__listOfName,
            boost::shared_ptr< Identifier> arg__domainName) :
    scopeOfDelete_(arg__scopeOfDelete),
    listOfName_(arg__listOfName),
    domainName_(arg__domainName) {
    };

    const int DeleteVariableAccess_Request::scopeOfDelete__default = 0;

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

    const int& DeleteVariableAccess_Request::scopeOfDelete() const {
        return *scopeOfDelete_;
    }

    void DeleteVariableAccess_Request::scopeOfDelete(const int& vl) {
        scopeOfDelete_ = vl;
    }

    void DeleteVariableAccess_Request::scopeOfDelete(boost::shared_ptr< int> vl) {
        scopeOfDelete_ = vl;
    }

    boost::shared_ptr<DeleteVariableAccess_Request::listOfName_type> DeleteVariableAccess_Request::listOfName__new() {
        return listOfName_ = boost::shared_ptr<listOfName_type>(new listOfName_type());
    }

    void DeleteVariableAccess_Request::listOfName(const listOfName_type& vl) {
        listOfName_ = boost::shared_ptr<listOfName_type>(new listOfName_type(vl));
    }

    boost::shared_ptr<Identifier> DeleteVariableAccess_Request::domainName__new() {
        return domainName_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void DeleteVariableAccess_Request::domainName(const Identifier& vl) {
        domainName_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence DeleteVariableAccess-Response

    DeleteVariableAccess_Response::DeleteVariableAccess_Response() : numberMatched_(), numberDeleted_() {
    };

    DeleteVariableAccess_Response::DeleteVariableAccess_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberDeleted) :
    numberMatched_(arg__numberMatched),
    numberDeleted_(arg__numberDeleted) {
    };

    template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberDeleted_, 1);
    }

    template<> void DeleteVariableAccess_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberDeleted_, 1);
    }

    Unsigned32& DeleteVariableAccess_Response::numberMatched() {
        return *numberMatched_;
    }

    const Unsigned32& DeleteVariableAccess_Response::numberMatched() const {
        return *numberMatched_;
    }

    void DeleteVariableAccess_Response::numberMatched(const Unsigned32& vl) {
        numberMatched_ = vl;
    }

    void DeleteVariableAccess_Response::numberMatched(boost::shared_ptr< Unsigned32> vl) {
        numberMatched_ = vl;
    }

    Unsigned32& DeleteVariableAccess_Response::numberDeleted() {
        return *numberDeleted_;
    }

    const Unsigned32& DeleteVariableAccess_Response::numberDeleted() const {
        return *numberDeleted_;
    }

    void DeleteVariableAccess_Response::numberDeleted(const Unsigned32& vl) {
        numberDeleted_ = vl;
    }

    void DeleteVariableAccess_Response::numberDeleted(boost::shared_ptr< Unsigned32> vl) {
        numberDeleted_ = vl;
    }


    // sequence DefineNamedVariableList-Request

    DefineNamedVariableList_Request::DefineNamedVariableList_Request() : variableListName_(), listOfVariable_() {
    };

    DefineNamedVariableList_Request::DefineNamedVariableList_Request(const ObjectName& arg__variableListName,
            const listOfVariable_type& arg__listOfVariable) :
    variableListName_(arg__variableListName),
    listOfVariable_(arg__listOfVariable) {
    };

    DefineNamedVariableList_Request::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of() : variableSpecification_() {
    };

    DefineNamedVariableList_Request::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    DefineNamedVariableList_Request::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of(boost::shared_ptr< VariableSpecification> arg__variableSpecification,
            boost::shared_ptr< AlternateAccess> arg__alternateAccess) :
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };

    template<> void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    template<> void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    VariableSpecification& DefineNamedVariableList_Request::listOfVariable_type_sequence_of::variableSpecification() {
        return *variableSpecification_;
    }

    const VariableSpecification& DefineNamedVariableList_Request::listOfVariable_type_sequence_of::variableSpecification() const {
        return *variableSpecification_;
    }

    void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::variableSpecification(const VariableSpecification& vl) {
        variableSpecification_ = vl;
    }

    void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::variableSpecification(boost::shared_ptr< VariableSpecification> vl) {
        variableSpecification_ = vl;
    }

    boost::shared_ptr<AlternateAccess> DefineNamedVariableList_Request::listOfVariable_type_sequence_of::alternateAccess__new() {
        return alternateAccess_ = boost::shared_ptr<AlternateAccess>(new AlternateAccess());
    }

    void DefineNamedVariableList_Request::listOfVariable_type_sequence_of::alternateAccess(const AlternateAccess& vl) {
        alternateAccess_ = boost::shared_ptr<AlternateAccess>(new AlternateAccess(vl));
    }

    template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(variableListName_);
        ITU_T_IMPLICIT_TAG(listOfVariable_, 0);
    }

    template<> void DefineNamedVariableList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(variableListName_);
        ITU_T_IMPLICIT_TAG(listOfVariable_, 0);
    }

    ObjectName& DefineNamedVariableList_Request::variableListName() {
        return *variableListName_;
    }

    const ObjectName& DefineNamedVariableList_Request::variableListName() const {
        return *variableListName_;
    }

    void DefineNamedVariableList_Request::variableListName(const ObjectName& vl) {
        variableListName_ = vl;
    }

    void DefineNamedVariableList_Request::variableListName(boost::shared_ptr< ObjectName> vl) {
        variableListName_ = vl;
    }

    DefineNamedVariableList_Request::listOfVariable_type& DefineNamedVariableList_Request::listOfVariable() {
        return *listOfVariable_;
    }

    const DefineNamedVariableList_Request::listOfVariable_type& DefineNamedVariableList_Request::listOfVariable() const {
        return *listOfVariable_;
    }

    void DefineNamedVariableList_Request::listOfVariable(const listOfVariable_type& vl) {
        listOfVariable_ = vl;
    }

    void DefineNamedVariableList_Request::listOfVariable(boost::shared_ptr< listOfVariable_type> vl) {
        listOfVariable_ = vl;
    }


    // sequence GetNamedVariableListAttributes-Response

    GetNamedVariableListAttributes_Response::GetNamedVariableListAttributes_Response() : mmsDeletable_(), listOfVariable_() {
    };

    GetNamedVariableListAttributes_Response::GetNamedVariableListAttributes_Response(const bool& arg__mmsDeletable,
            const listOfVariable_type& arg__listOfVariable) :
    mmsDeletable_(arg__mmsDeletable),
    listOfVariable_(arg__listOfVariable) {
    };

    GetNamedVariableListAttributes_Response::GetNamedVariableListAttributes_Response(boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< listOfVariable_type> arg__listOfVariable,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    listOfVariable_(arg__listOfVariable),
    accessControlList_(arg__accessControlList) {
    };

    GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of() : variableSpecification_() {
    };

    GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of(const VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::listOfVariable_type_sequence_of(boost::shared_ptr< VariableSpecification> arg__variableSpecification,
            boost::shared_ptr< AlternateAccess> arg__alternateAccess) :
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };

    template<> void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    template<> void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(variableSpecification_);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 5);
    }

    VariableSpecification& GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::variableSpecification() {
        return *variableSpecification_;
    }

    const VariableSpecification& GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::variableSpecification() const {
        return *variableSpecification_;
    }

    void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::variableSpecification(const VariableSpecification& vl) {
        variableSpecification_ = vl;
    }

    void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::variableSpecification(boost::shared_ptr< VariableSpecification> vl) {
        variableSpecification_ = vl;
    }

    boost::shared_ptr<AlternateAccess> GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::alternateAccess__new() {
        return alternateAccess_ = boost::shared_ptr<AlternateAccess>(new AlternateAccess());
    }

    void GetNamedVariableListAttributes_Response::listOfVariable_type_sequence_of::alternateAccess(const AlternateAccess& vl) {
        alternateAccess_ = boost::shared_ptr<AlternateAccess>(new AlternateAccess(vl));
    }

    template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    template<> void GetNamedVariableListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    bool& GetNamedVariableListAttributes_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& GetNamedVariableListAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetNamedVariableListAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetNamedVariableListAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    GetNamedVariableListAttributes_Response::listOfVariable_type& GetNamedVariableListAttributes_Response::listOfVariable() {
        return *listOfVariable_;
    }

    const GetNamedVariableListAttributes_Response::listOfVariable_type& GetNamedVariableListAttributes_Response::listOfVariable() const {
        return *listOfVariable_;
    }

    void GetNamedVariableListAttributes_Response::listOfVariable(const listOfVariable_type& vl) {
        listOfVariable_ = vl;
    }

    void GetNamedVariableListAttributes_Response::listOfVariable(boost::shared_ptr< listOfVariable_type> vl) {
        listOfVariable_ = vl;
    }

    boost::shared_ptr<Identifier> GetNamedVariableListAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetNamedVariableListAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence DeleteNamedVariableList-Request
    const int DeleteNamedVariableList_Request::scopeOfDelete_specific = 0;
    const int DeleteNamedVariableList_Request::scopeOfDelete_aa_specific = 1;
    const int DeleteNamedVariableList_Request::scopeOfDelete_domain = 2;
    const int DeleteNamedVariableList_Request::scopeOfDelete_vmd = 3;

    DeleteNamedVariableList_Request::DeleteNamedVariableList_Request() {
    };

    DeleteNamedVariableList_Request::DeleteNamedVariableList_Request(boost::shared_ptr< int> arg__scopeOfDelete,
            boost::shared_ptr< listOfVariableListName_type> arg__listOfVariableListName,
            boost::shared_ptr< Identifier> arg__domainName) :
    scopeOfDelete_(arg__scopeOfDelete),
    listOfVariableListName_(arg__listOfVariableListName),
    domainName_(arg__domainName) {
    };

    const int DeleteNamedVariableList_Request::scopeOfDelete__default = 0;

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

    const int& DeleteNamedVariableList_Request::scopeOfDelete() const {
        return *scopeOfDelete_;
    }

    void DeleteNamedVariableList_Request::scopeOfDelete(const int& vl) {
        scopeOfDelete_ = vl;
    }

    void DeleteNamedVariableList_Request::scopeOfDelete(boost::shared_ptr< int> vl) {
        scopeOfDelete_ = vl;
    }

    boost::shared_ptr<DeleteNamedVariableList_Request::listOfVariableListName_type> DeleteNamedVariableList_Request::listOfVariableListName__new() {
        return listOfVariableListName_ = boost::shared_ptr<listOfVariableListName_type>(new listOfVariableListName_type());
    }

    void DeleteNamedVariableList_Request::listOfVariableListName(const listOfVariableListName_type& vl) {
        listOfVariableListName_ = boost::shared_ptr<listOfVariableListName_type>(new listOfVariableListName_type(vl));
    }

    boost::shared_ptr<Identifier> DeleteNamedVariableList_Request::domainName__new() {
        return domainName_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void DeleteNamedVariableList_Request::domainName(const Identifier& vl) {
        domainName_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence DeleteNamedVariableList-Response

    DeleteNamedVariableList_Response::DeleteNamedVariableList_Response() : numberMatched_(), numberDeleted_() {
    };

    DeleteNamedVariableList_Response::DeleteNamedVariableList_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberDeleted) :
    numberMatched_(arg__numberMatched),
    numberDeleted_(arg__numberDeleted) {
    };

    template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberDeleted_, 1);
    }

    template<> void DeleteNamedVariableList_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberDeleted_, 1);
    }

    Unsigned32& DeleteNamedVariableList_Response::numberMatched() {
        return *numberMatched_;
    }

    const Unsigned32& DeleteNamedVariableList_Response::numberMatched() const {
        return *numberMatched_;
    }

    void DeleteNamedVariableList_Response::numberMatched(const Unsigned32& vl) {
        numberMatched_ = vl;
    }

    void DeleteNamedVariableList_Response::numberMatched(boost::shared_ptr< Unsigned32> vl) {
        numberMatched_ = vl;
    }

    Unsigned32& DeleteNamedVariableList_Response::numberDeleted() {
        return *numberDeleted_;
    }

    const Unsigned32& DeleteNamedVariableList_Response::numberDeleted() const {
        return *numberDeleted_;
    }

    void DeleteNamedVariableList_Response::numberDeleted(const Unsigned32& vl) {
        numberDeleted_ = vl;
    }

    void DeleteNamedVariableList_Response::numberDeleted(boost::shared_ptr< Unsigned32> vl) {
        numberDeleted_ = vl;
    }


    // sequence DefineNamedType-Request

    DefineNamedType_Request::DefineNamedType_Request() : typeName_(), typeSpecification_() {
    };

    DefineNamedType_Request::DefineNamedType_Request(const ObjectName& arg__typeName,
            const TypeSpecification& arg__typeSpecification) :
    typeName_(arg__typeName),
    typeSpecification_(arg__typeSpecification) {
    };

    template<> void DefineNamedType_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(typeName_);
        ITU_T_BIND_CHOICE(typeSpecification_);
    }

    template<> void DefineNamedType_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(typeName_);
        ITU_T_BIND_CHOICE(typeSpecification_);
    }

    ObjectName& DefineNamedType_Request::typeName() {
        return *typeName_;
    }

    const ObjectName& DefineNamedType_Request::typeName() const {
        return *typeName_;
    }

    void DefineNamedType_Request::typeName(const ObjectName& vl) {
        typeName_ = vl;
    }

    void DefineNamedType_Request::typeName(boost::shared_ptr< ObjectName> vl) {
        typeName_ = vl;
    }

    TypeSpecification& DefineNamedType_Request::typeSpecification() {
        return *typeSpecification_;
    }

    const TypeSpecification& DefineNamedType_Request::typeSpecification() const {
        return *typeSpecification_;
    }

    void DefineNamedType_Request::typeSpecification(const TypeSpecification& vl) {
        typeSpecification_ = vl;
    }

    void DefineNamedType_Request::typeSpecification(boost::shared_ptr< TypeSpecification> vl) {
        typeSpecification_ = vl;
    }


    // sequence GetNamedTypeAttributes-Response

    GetNamedTypeAttributes_Response::GetNamedTypeAttributes_Response() : mmsDeletable_(), typeSpecification_() {
    };

    GetNamedTypeAttributes_Response::GetNamedTypeAttributes_Response(const bool& arg__mmsDeletable,
            const TypeSpecification& arg__typeSpecification) :
    mmsDeletable_(arg__mmsDeletable),
    typeSpecification_(arg__typeSpecification) {
    };

    GetNamedTypeAttributes_Response::GetNamedTypeAttributes_Response(boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< TypeSpecification> arg__typeSpecification,
            boost::shared_ptr< Identifier> arg__accessControlList,
            boost::shared_ptr< visiblestring_type> arg__meaning) :
    mmsDeletable_(arg__mmsDeletable),
    typeSpecification_(arg__typeSpecification),
    accessControlList_(arg__accessControlList),
    meaning_(arg__meaning) {
    };

    template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_BIND_CHOICE(typeSpecification_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 1);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    template<> void GetNamedTypeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_BIND_CHOICE(typeSpecification_);
        ITU_T_IMPLICIT_TAG(accessControlList_, 1);
        ITU_T_IMPLICIT_TAG(meaning_, 4);
    }

    bool& GetNamedTypeAttributes_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& GetNamedTypeAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetNamedTypeAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetNamedTypeAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    TypeSpecification& GetNamedTypeAttributes_Response::typeSpecification() {
        return *typeSpecification_;
    }

    const TypeSpecification& GetNamedTypeAttributes_Response::typeSpecification() const {
        return *typeSpecification_;
    }

    void GetNamedTypeAttributes_Response::typeSpecification(const TypeSpecification& vl) {
        typeSpecification_ = vl;
    }

    void GetNamedTypeAttributes_Response::typeSpecification(boost::shared_ptr< TypeSpecification> vl) {
        typeSpecification_ = vl;
    }

    boost::shared_ptr<Identifier> GetNamedTypeAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetNamedTypeAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    boost::shared_ptr<visiblestring_type> GetNamedTypeAttributes_Response::meaning__new() {
        return meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void GetNamedTypeAttributes_Response::meaning(const visiblestring_type& vl) {
        meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }


    // sequence DeleteNamedType-Request
    const int DeleteNamedType_Request::scopeOfDelete_specific = 0;
    const int DeleteNamedType_Request::scopeOfDelete_aa_specific = 1;
    const int DeleteNamedType_Request::scopeOfDelete_domain = 2;
    const int DeleteNamedType_Request::scopeOfDelete_vmd = 3;

    DeleteNamedType_Request::DeleteNamedType_Request() {
    };

    DeleteNamedType_Request::DeleteNamedType_Request(boost::shared_ptr< int> arg__scopeOfDelete,
            boost::shared_ptr< listOfTypeName_type> arg__listOfTypeName,
            boost::shared_ptr< Identifier> arg__domainName) :
    scopeOfDelete_(arg__scopeOfDelete),
    listOfTypeName_(arg__listOfTypeName),
    domainName_(arg__domainName) {
    };

    const int DeleteNamedType_Request::scopeOfDelete__default = 0;

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

    const int& DeleteNamedType_Request::scopeOfDelete() const {
        return *scopeOfDelete_;
    }

    void DeleteNamedType_Request::scopeOfDelete(const int& vl) {
        scopeOfDelete_ = vl;
    }

    void DeleteNamedType_Request::scopeOfDelete(boost::shared_ptr< int> vl) {
        scopeOfDelete_ = vl;
    }

    boost::shared_ptr<DeleteNamedType_Request::listOfTypeName_type> DeleteNamedType_Request::listOfTypeName__new() {
        return listOfTypeName_ = boost::shared_ptr<listOfTypeName_type>(new listOfTypeName_type());
    }

    void DeleteNamedType_Request::listOfTypeName(const listOfTypeName_type& vl) {
        listOfTypeName_ = boost::shared_ptr<listOfTypeName_type>(new listOfTypeName_type(vl));
    }

    boost::shared_ptr<Identifier> DeleteNamedType_Request::domainName__new() {
        return domainName_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void DeleteNamedType_Request::domainName(const Identifier& vl) {
        domainName_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence DeleteNamedType-Response

    DeleteNamedType_Response::DeleteNamedType_Response() : numberMatched_(), numberDeleted_() {
    };

    DeleteNamedType_Response::DeleteNamedType_Response(const Unsigned32& arg__numberMatched,
            const Unsigned32& arg__numberDeleted) :
    numberMatched_(arg__numberMatched),
    numberDeleted_(arg__numberDeleted) {
    };

    template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberDeleted_, 1);
    }

    template<> void DeleteNamedType_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(numberMatched_, 0);
        ITU_T_IMPLICIT_TAG(numberDeleted_, 1);
    }

    Unsigned32& DeleteNamedType_Response::numberMatched() {
        return *numberMatched_;
    }

    const Unsigned32& DeleteNamedType_Response::numberMatched() const {
        return *numberMatched_;
    }

    void DeleteNamedType_Response::numberMatched(const Unsigned32& vl) {
        numberMatched_ = vl;
    }

    void DeleteNamedType_Response::numberMatched(boost::shared_ptr< Unsigned32> vl) {
        numberMatched_ = vl;
    }

    Unsigned32& DeleteNamedType_Response::numberDeleted() {
        return *numberDeleted_;
    }

    const Unsigned32& DeleteNamedType_Response::numberDeleted() const {
        return *numberDeleted_;
    }

    void DeleteNamedType_Response::numberDeleted(const Unsigned32& vl) {
        numberDeleted_ = vl;
    }

    void DeleteNamedType_Response::numberDeleted(boost::shared_ptr< Unsigned32> vl) {
        numberDeleted_ = vl;
    }


    // sequence ExchangeData-Request

    ExchangeData_Request::ExchangeData_Request() : dataExchangeName_(), listOfRequestData_() {
    };

    ExchangeData_Request::ExchangeData_Request(const ObjectName& arg__dataExchangeName,
            const listOfRequestData_type& arg__listOfRequestData) :
    dataExchangeName_(arg__dataExchangeName),
    listOfRequestData_(arg__listOfRequestData) {
    };

    template<> void ExchangeData_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(dataExchangeName_, 0);
        ITU_T_IMPLICIT_TAG(listOfRequestData_, 1);
    }

    template<> void ExchangeData_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(dataExchangeName_, 0);
        ITU_T_IMPLICIT_TAG(listOfRequestData_, 1);
    }

    ObjectName& ExchangeData_Request::dataExchangeName() {
        return *dataExchangeName_;
    }

    const ObjectName& ExchangeData_Request::dataExchangeName() const {
        return *dataExchangeName_;
    }

    void ExchangeData_Request::dataExchangeName(const ObjectName& vl) {
        dataExchangeName_ = vl;
    }

    void ExchangeData_Request::dataExchangeName(boost::shared_ptr< ObjectName> vl) {
        dataExchangeName_ = vl;
    }

    ExchangeData_Request::listOfRequestData_type& ExchangeData_Request::listOfRequestData() {
        return *listOfRequestData_;
    }

    const ExchangeData_Request::listOfRequestData_type& ExchangeData_Request::listOfRequestData() const {
        return *listOfRequestData_;
    }

    void ExchangeData_Request::listOfRequestData(const listOfRequestData_type& vl) {
        listOfRequestData_ = vl;
    }

    void ExchangeData_Request::listOfRequestData(boost::shared_ptr< listOfRequestData_type> vl) {
        listOfRequestData_ = vl;
    }


    // sequence ExchangeData-Response

    ExchangeData_Response::ExchangeData_Response() : listOfResponseData_() {
    };

    ExchangeData_Response::ExchangeData_Response(const listOfResponseData_type& arg__listOfResponseData) :
    listOfResponseData_(arg__listOfResponseData) {
    };

    template<> void ExchangeData_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfResponseData_, 0);
    }

    template<> void ExchangeData_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfResponseData_, 0);
    }

    ExchangeData_Response::listOfResponseData_type& ExchangeData_Response::listOfResponseData() {
        return *listOfResponseData_;
    }

    const ExchangeData_Response::listOfResponseData_type& ExchangeData_Response::listOfResponseData() const {
        return *listOfResponseData_;
    }

    void ExchangeData_Response::listOfResponseData(const listOfResponseData_type& vl) {
        listOfResponseData_ = vl;
    }

    void ExchangeData_Response::listOfResponseData(boost::shared_ptr< listOfResponseData_type> vl) {
        listOfResponseData_ = vl;
    }


    // sequence GetDataExchangeAttributes-Response

    GetDataExchangeAttributes_Response::GetDataExchangeAttributes_Response() : inUse_(), listOfRequestTypeDescriptions_(), listOfResponseTypeDescriptions_() {
    };

    GetDataExchangeAttributes_Response::GetDataExchangeAttributes_Response(const bool& arg__inUse,
            const listOfRequestTypeDescriptions_type& arg__listOfRequestTypeDescriptions,
            const listOfResponseTypeDescriptions_type& arg__listOfResponseTypeDescriptions) :
    inUse_(arg__inUse),
    listOfRequestTypeDescriptions_(arg__listOfRequestTypeDescriptions),
    listOfResponseTypeDescriptions_(arg__listOfResponseTypeDescriptions) {
    };

    GetDataExchangeAttributes_Response::GetDataExchangeAttributes_Response(boost::shared_ptr< bool> arg__inUse,
            boost::shared_ptr< listOfRequestTypeDescriptions_type> arg__listOfRequestTypeDescriptions,
            boost::shared_ptr< listOfResponseTypeDescriptions_type> arg__listOfResponseTypeDescriptions,
            boost::shared_ptr< Identifier> arg__programInvocation,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    inUse_(arg__inUse),
    listOfRequestTypeDescriptions_(arg__listOfRequestTypeDescriptions),
    listOfResponseTypeDescriptions_(arg__listOfResponseTypeDescriptions),
    programInvocation_(arg__programInvocation),
    accessControlList_(arg__accessControlList) {
    };

    template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(inUse_, 0);
        ITU_T_IMPLICIT_TAG(listOfRequestTypeDescriptions_, 1);
        ITU_T_IMPLICIT_TAG(listOfResponseTypeDescriptions_, 2);
        ITU_T_IMPLICIT_TAG(programInvocation_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    template<> void GetDataExchangeAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(inUse_, 0);
        ITU_T_IMPLICIT_TAG(listOfRequestTypeDescriptions_, 1);
        ITU_T_IMPLICIT_TAG(listOfResponseTypeDescriptions_, 2);
        ITU_T_IMPLICIT_TAG(programInvocation_, 3);
        ITU_T_IMPLICIT_TAG(accessControlList_, 4);
    }

    bool& GetDataExchangeAttributes_Response::inUse() {
        return *inUse_;
    }

    const bool& GetDataExchangeAttributes_Response::inUse() const {
        return *inUse_;
    }

    void GetDataExchangeAttributes_Response::inUse(const bool& vl) {
        inUse_ = vl;
    }

    void GetDataExchangeAttributes_Response::inUse(boost::shared_ptr< bool> vl) {
        inUse_ = vl;
    }

    GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions_type& GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions() {
        return *listOfRequestTypeDescriptions_;
    }

    const GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions_type& GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions() const {
        return *listOfRequestTypeDescriptions_;
    }

    void GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions(const listOfRequestTypeDescriptions_type& vl) {
        listOfRequestTypeDescriptions_ = vl;
    }

    void GetDataExchangeAttributes_Response::listOfRequestTypeDescriptions(boost::shared_ptr< listOfRequestTypeDescriptions_type> vl) {
        listOfRequestTypeDescriptions_ = vl;
    }

    GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions_type& GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions() {
        return *listOfResponseTypeDescriptions_;
    }

    const GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions_type& GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions() const {
        return *listOfResponseTypeDescriptions_;
    }

    void GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions(const listOfResponseTypeDescriptions_type& vl) {
        listOfResponseTypeDescriptions_ = vl;
    }

    void GetDataExchangeAttributes_Response::listOfResponseTypeDescriptions(boost::shared_ptr< listOfResponseTypeDescriptions_type> vl) {
        listOfResponseTypeDescriptions_ = vl;
    }

    boost::shared_ptr<Identifier> GetDataExchangeAttributes_Response::programInvocation__new() {
        return programInvocation_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetDataExchangeAttributes_Response::programInvocation(const Identifier& vl) {
        programInvocation_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    boost::shared_ptr<Identifier> GetDataExchangeAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetDataExchangeAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence TakeControl-Request

    TakeControl_Request::TakeControl_Request() : semaphoreName_() {
    };

    TakeControl_Request::TakeControl_Request(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    TakeControl_Request::TakeControl_Request(boost::shared_ptr< ObjectName> arg__semaphoreName,
            boost::shared_ptr< Identifier> arg__namedToken,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< Unsigned32> arg__acceptableDelay,
            boost::shared_ptr< Unsigned32> arg__controlTimeOut,
            boost::shared_ptr< bool> arg__abortOnTimeOut,
            boost::shared_ptr< bool> arg__relinquishIfConnectionLost,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__applicationToPreempt) :
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

    template<> void TakeControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
        ITU_T_IMPLICIT_TAG(applicationToPreempt_, 7);
    }

    template<> void TakeControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
        ITU_T_IMPLICIT_TAG(applicationToPreempt_, 7);
    }

    ObjectName& TakeControl_Request::semaphoreName() {
        return *semaphoreName_;
    }

    const ObjectName& TakeControl_Request::semaphoreName() const {
        return *semaphoreName_;
    }

    void TakeControl_Request::semaphoreName(const ObjectName& vl) {
        semaphoreName_ = vl;
    }

    void TakeControl_Request::semaphoreName(boost::shared_ptr< ObjectName> vl) {
        semaphoreName_ = vl;
    }

    boost::shared_ptr<Identifier> TakeControl_Request::namedToken__new() {
        return namedToken_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void TakeControl_Request::namedToken(const Identifier& vl) {
        namedToken_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    const MMS_Object_Module_1::Priority& TakeControl_Request::priority() const {
        return *priority_;
    }

    void TakeControl_Request::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = vl;
    }

    void TakeControl_Request::priority(boost::shared_ptr< MMS_Object_Module_1::Priority> vl) {
        priority_ = vl;
    }

    boost::shared_ptr<Unsigned32> TakeControl_Request::acceptableDelay__new() {
        return acceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void TakeControl_Request::acceptableDelay(const Unsigned32& vl) {
        acceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<Unsigned32> TakeControl_Request::controlTimeOut__new() {
        return controlTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void TakeControl_Request::controlTimeOut(const Unsigned32& vl) {
        controlTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<bool> TakeControl_Request::abortOnTimeOut__new() {
        return abortOnTimeOut_ = boost::shared_ptr<bool>(new bool());
    }

    void TakeControl_Request::abortOnTimeOut(const bool& vl) {
        abortOnTimeOut_ = boost::shared_ptr<bool>(new bool(vl));
    }

    const bool& TakeControl_Request::relinquishIfConnectionLost() const {
        return *relinquishIfConnectionLost_;
    }

    void TakeControl_Request::relinquishIfConnectionLost(const bool& vl) {
        relinquishIfConnectionLost_ = vl;
    }

    void TakeControl_Request::relinquishIfConnectionLost(boost::shared_ptr< bool> vl) {
        relinquishIfConnectionLost_ = vl;
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> TakeControl_Request::applicationToPreempt__new() {
        return applicationToPreempt_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void TakeControl_Request::applicationToPreempt(const MMS_Environment_1::ApplicationReference& vl) {
        applicationToPreempt_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }


    // choice TakeControl-Response

    void TakeControl_Response::noResult(const null_type& vl) {
        set<null_type>(new null_type(vl), TakeControl_Response_noResult);
    }

    void TakeControl_Response::namedToken(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), TakeControl_Response_namedToken);
    }

    template<> void TakeControl_Response::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case TakeControl_Response_noResult:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, TakeControl_Response_noResult), 0);
                break;
            }
            case TakeControl_Response_namedToken:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, TakeControl_Response_namedToken), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, TakeControl_Response_noResult), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, TakeControl_Response_namedToken), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    RelinquishControl_Request::RelinquishControl_Request() : semaphoreName_() {
    };

    RelinquishControl_Request::RelinquishControl_Request(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    RelinquishControl_Request::RelinquishControl_Request(boost::shared_ptr< ObjectName> arg__semaphoreName,
            boost::shared_ptr< Identifier> arg__namedToken) :
    semaphoreName_(arg__semaphoreName),
    namedToken_(arg__namedToken) {
    };

    template<> void RelinquishControl_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
    }

    template<> void RelinquishControl_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
    }

    ObjectName& RelinquishControl_Request::semaphoreName() {
        return *semaphoreName_;
    }

    const ObjectName& RelinquishControl_Request::semaphoreName() const {
        return *semaphoreName_;
    }

    void RelinquishControl_Request::semaphoreName(const ObjectName& vl) {
        semaphoreName_ = vl;
    }

    void RelinquishControl_Request::semaphoreName(boost::shared_ptr< ObjectName> vl) {
        semaphoreName_ = vl;
    }

    boost::shared_ptr<Identifier> RelinquishControl_Request::namedToken__new() {
        return namedToken_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void RelinquishControl_Request::namedToken(const Identifier& vl) {
        namedToken_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence DefineSemaphore-Request

    DefineSemaphore_Request::DefineSemaphore_Request() : semaphoreName_(), numberOfTokens_() {
    };

    DefineSemaphore_Request::DefineSemaphore_Request(const ObjectName& arg__semaphoreName,
            const Unsigned16& arg__numberOfTokens) :
    semaphoreName_(arg__semaphoreName),
    numberOfTokens_(arg__numberOfTokens) {
    };

    template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(numberOfTokens_, 1);
    }

    template<> void DefineSemaphore_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(numberOfTokens_, 1);
    }

    ObjectName& DefineSemaphore_Request::semaphoreName() {
        return *semaphoreName_;
    }

    const ObjectName& DefineSemaphore_Request::semaphoreName() const {
        return *semaphoreName_;
    }

    void DefineSemaphore_Request::semaphoreName(const ObjectName& vl) {
        semaphoreName_ = vl;
    }

    void DefineSemaphore_Request::semaphoreName(boost::shared_ptr< ObjectName> vl) {
        semaphoreName_ = vl;
    }

    Unsigned16& DefineSemaphore_Request::numberOfTokens() {
        return *numberOfTokens_;
    }

    const Unsigned16& DefineSemaphore_Request::numberOfTokens() const {
        return *numberOfTokens_;
    }

    void DefineSemaphore_Request::numberOfTokens(const Unsigned16& vl) {
        numberOfTokens_ = vl;
    }

    void DefineSemaphore_Request::numberOfTokens(boost::shared_ptr< Unsigned16> vl) {
        numberOfTokens_ = vl;
    }


    // sequence ReportSemaphoreStatus-Response
    const int ReportSemaphoreStatus_Response::classV_token = 0;
    const int ReportSemaphoreStatus_Response::classV_pool = 1;

    ReportSemaphoreStatus_Response::ReportSemaphoreStatus_Response() : mmsDeletable_(), classV_(), numberOfTokens_(), numberOfOwnedTokens_(), numberOfHungTokens_() {
    };

    ReportSemaphoreStatus_Response::ReportSemaphoreStatus_Response(const bool& arg__mmsDeletable,
            const int& arg__classV,
            const Unsigned16& arg__numberOfTokens,
            const Unsigned16& arg__numberOfOwnedTokens,
            const Unsigned16& arg__numberOfHungTokens) :
    mmsDeletable_(arg__mmsDeletable),
    classV_(arg__classV),
    numberOfTokens_(arg__numberOfTokens),
    numberOfOwnedTokens_(arg__numberOfOwnedTokens),
    numberOfHungTokens_(arg__numberOfHungTokens) {
    };

    ReportSemaphoreStatus_Response::ReportSemaphoreStatus_Response(boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< int> arg__classV,
            boost::shared_ptr< Unsigned16> arg__numberOfTokens,
            boost::shared_ptr< Unsigned16> arg__numberOfOwnedTokens,
            boost::shared_ptr< Unsigned16> arg__numberOfHungTokens,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    classV_(arg__classV),
    numberOfTokens_(arg__numberOfTokens),
    numberOfOwnedTokens_(arg__numberOfOwnedTokens),
    numberOfHungTokens_(arg__numberOfHungTokens),
    accessControlList_(arg__accessControlList) {
    };

    template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(classV_, 1);
        ITU_T_IMPLICIT_TAG(numberOfTokens_, 2);
        ITU_T_IMPLICIT_TAG(numberOfOwnedTokens_, 3);
        ITU_T_IMPLICIT_TAG(numberOfHungTokens_, 4);
        ITU_T_IMPLICIT_TAG(accessControlList_, 5);
    }

    template<> void ReportSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(classV_, 1);
        ITU_T_IMPLICIT_TAG(numberOfTokens_, 2);
        ITU_T_IMPLICIT_TAG(numberOfOwnedTokens_, 3);
        ITU_T_IMPLICIT_TAG(numberOfHungTokens_, 4);
        ITU_T_IMPLICIT_TAG(accessControlList_, 5);
    }

    bool& ReportSemaphoreStatus_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& ReportSemaphoreStatus_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void ReportSemaphoreStatus_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void ReportSemaphoreStatus_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    int& ReportSemaphoreStatus_Response::classV() {
        return *classV_;
    }

    const int& ReportSemaphoreStatus_Response::classV() const {
        return *classV_;
    }

    void ReportSemaphoreStatus_Response::classV(const int& vl) {
        classV_ = vl;
    }

    void ReportSemaphoreStatus_Response::classV(boost::shared_ptr< int> vl) {
        classV_ = vl;
    }

    Unsigned16& ReportSemaphoreStatus_Response::numberOfTokens() {
        return *numberOfTokens_;
    }

    const Unsigned16& ReportSemaphoreStatus_Response::numberOfTokens() const {
        return *numberOfTokens_;
    }

    void ReportSemaphoreStatus_Response::numberOfTokens(const Unsigned16& vl) {
        numberOfTokens_ = vl;
    }

    void ReportSemaphoreStatus_Response::numberOfTokens(boost::shared_ptr< Unsigned16> vl) {
        numberOfTokens_ = vl;
    }

    Unsigned16& ReportSemaphoreStatus_Response::numberOfOwnedTokens() {
        return *numberOfOwnedTokens_;
    }

    const Unsigned16& ReportSemaphoreStatus_Response::numberOfOwnedTokens() const {
        return *numberOfOwnedTokens_;
    }

    void ReportSemaphoreStatus_Response::numberOfOwnedTokens(const Unsigned16& vl) {
        numberOfOwnedTokens_ = vl;
    }

    void ReportSemaphoreStatus_Response::numberOfOwnedTokens(boost::shared_ptr< Unsigned16> vl) {
        numberOfOwnedTokens_ = vl;
    }

    Unsigned16& ReportSemaphoreStatus_Response::numberOfHungTokens() {
        return *numberOfHungTokens_;
    }

    const Unsigned16& ReportSemaphoreStatus_Response::numberOfHungTokens() const {
        return *numberOfHungTokens_;
    }

    void ReportSemaphoreStatus_Response::numberOfHungTokens(const Unsigned16& vl) {
        numberOfHungTokens_ = vl;
    }

    void ReportSemaphoreStatus_Response::numberOfHungTokens(boost::shared_ptr< Unsigned16> vl) {
        numberOfHungTokens_ = vl;
    }

    boost::shared_ptr<Identifier> ReportSemaphoreStatus_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void ReportSemaphoreStatus_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence ReportPoolSemaphoreStatus-Request

    ReportPoolSemaphoreStatus_Request::ReportPoolSemaphoreStatus_Request() : semaphoreName_() {
    };

    ReportPoolSemaphoreStatus_Request::ReportPoolSemaphoreStatus_Request(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    ReportPoolSemaphoreStatus_Request::ReportPoolSemaphoreStatus_Request(boost::shared_ptr< ObjectName> arg__semaphoreName,
            boost::shared_ptr< Identifier> arg__nameToStartAfter) :
    semaphoreName_(arg__semaphoreName),
    nameToStartAfter_(arg__nameToStartAfter) {
    };

    template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(nameToStartAfter_, 1);
    }

    template<> void ReportPoolSemaphoreStatus_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(nameToStartAfter_, 1);
    }

    ObjectName& ReportPoolSemaphoreStatus_Request::semaphoreName() {
        return *semaphoreName_;
    }

    const ObjectName& ReportPoolSemaphoreStatus_Request::semaphoreName() const {
        return *semaphoreName_;
    }

    void ReportPoolSemaphoreStatus_Request::semaphoreName(const ObjectName& vl) {
        semaphoreName_ = vl;
    }

    void ReportPoolSemaphoreStatus_Request::semaphoreName(boost::shared_ptr< ObjectName> vl) {
        semaphoreName_ = vl;
    }

    boost::shared_ptr<Identifier> ReportPoolSemaphoreStatus_Request::nameToStartAfter__new() {
        return nameToStartAfter_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void ReportPoolSemaphoreStatus_Request::nameToStartAfter(const Identifier& vl) {
        nameToStartAfter_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence ReportPoolSemaphoreStatus-Response

    ReportPoolSemaphoreStatus_Response::ReportPoolSemaphoreStatus_Response() : listOfNamedTokens_() {
    };

    ReportPoolSemaphoreStatus_Response::ReportPoolSemaphoreStatus_Response(const listOfNamedTokens_type& arg__listOfNamedTokens) :
    listOfNamedTokens_(arg__listOfNamedTokens) {
    };

    ReportPoolSemaphoreStatus_Response::ReportPoolSemaphoreStatus_Response(boost::shared_ptr< listOfNamedTokens_type> arg__listOfNamedTokens,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfNamedTokens_(arg__listOfNamedTokens),
    moreFollows_(arg__moreFollows) {
    };

    void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::freeNamedToken(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), listOfNamedTokens_type_sequence_of_freeNamedToken);
    }

    void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::ownedNamedToken(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), listOfNamedTokens_type_sequence_of_ownedNamedToken);
    }

    void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::hungNamedToken(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), listOfNamedTokens_type_sequence_of_hungNamedToken);
    }

    template<> void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case listOfNamedTokens_type_sequence_of_freeNamedToken:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, listOfNamedTokens_type_sequence_of_freeNamedToken), 0);
                break;
            }
            case listOfNamedTokens_type_sequence_of_ownedNamedToken:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, listOfNamedTokens_type_sequence_of_ownedNamedToken), 1);
                break;
            }
            case listOfNamedTokens_type_sequence_of_hungNamedToken:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, listOfNamedTokens_type_sequence_of_hungNamedToken), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, listOfNamedTokens_type_sequence_of_freeNamedToken), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, listOfNamedTokens_type_sequence_of_ownedNamedToken), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, listOfNamedTokens_type_sequence_of_hungNamedToken), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    const bool ReportPoolSemaphoreStatus_Response::moreFollows__default = true;

    template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfNamedTokens_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReportPoolSemaphoreStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfNamedTokens_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type& ReportPoolSemaphoreStatus_Response::listOfNamedTokens() {
        return *listOfNamedTokens_;
    }

    const ReportPoolSemaphoreStatus_Response::listOfNamedTokens_type& ReportPoolSemaphoreStatus_Response::listOfNamedTokens() const {
        return *listOfNamedTokens_;
    }

    void ReportPoolSemaphoreStatus_Response::listOfNamedTokens(const listOfNamedTokens_type& vl) {
        listOfNamedTokens_ = vl;
    }

    void ReportPoolSemaphoreStatus_Response::listOfNamedTokens(boost::shared_ptr< listOfNamedTokens_type> vl) {
        listOfNamedTokens_ = vl;
    }

    const bool& ReportPoolSemaphoreStatus_Response::moreFollows() const {
        return *moreFollows_;
    }

    void ReportPoolSemaphoreStatus_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void ReportPoolSemaphoreStatus_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence ReportSemaphoreEntryStatus-Request
    const int ReportSemaphoreEntryStatus_Request::state_queued = 0;
    const int ReportSemaphoreEntryStatus_Request::state_owner = 1;
    const int ReportSemaphoreEntryStatus_Request::state_hung = 2;

    ReportSemaphoreEntryStatus_Request::ReportSemaphoreEntryStatus_Request() : semaphoreName_(), state_() {
    };

    ReportSemaphoreEntryStatus_Request::ReportSemaphoreEntryStatus_Request(const ObjectName& arg__semaphoreName,
            const int& arg__state) :
    semaphoreName_(arg__semaphoreName),
    state_(arg__state) {
    };

    ReportSemaphoreEntryStatus_Request::ReportSemaphoreEntryStatus_Request(boost::shared_ptr< ObjectName> arg__semaphoreName,
            boost::shared_ptr< int> arg__state,
            boost::shared_ptr< octetstring_type> arg__entryIDToStartAfter) :
    semaphoreName_(arg__semaphoreName),
    state_(arg__state),
    entryIDToStartAfter_(arg__entryIDToStartAfter) {
    };

    template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(state_, 1);
        ITU_T_IMPLICIT_TAG(entryIDToStartAfter_, 2);
    }

    template<> void ReportSemaphoreEntryStatus_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(state_, 1);
        ITU_T_IMPLICIT_TAG(entryIDToStartAfter_, 2);
    }

    ObjectName& ReportSemaphoreEntryStatus_Request::semaphoreName() {
        return *semaphoreName_;
    }

    const ObjectName& ReportSemaphoreEntryStatus_Request::semaphoreName() const {
        return *semaphoreName_;
    }

    void ReportSemaphoreEntryStatus_Request::semaphoreName(const ObjectName& vl) {
        semaphoreName_ = vl;
    }

    void ReportSemaphoreEntryStatus_Request::semaphoreName(boost::shared_ptr< ObjectName> vl) {
        semaphoreName_ = vl;
    }

    int& ReportSemaphoreEntryStatus_Request::state() {
        return *state_;
    }

    const int& ReportSemaphoreEntryStatus_Request::state() const {
        return *state_;
    }

    void ReportSemaphoreEntryStatus_Request::state(const int& vl) {
        state_ = vl;
    }

    void ReportSemaphoreEntryStatus_Request::state(boost::shared_ptr< int> vl) {
        state_ = vl;
    }

    boost::shared_ptr<octetstring_type> ReportSemaphoreEntryStatus_Request::entryIDToStartAfter__new() {
        return entryIDToStartAfter_ = boost::shared_ptr<octetstring_type>(new octetstring_type());
    }

    void ReportSemaphoreEntryStatus_Request::entryIDToStartAfter(const octetstring_type& vl) {
        entryIDToStartAfter_ = boost::shared_ptr<octetstring_type>(new octetstring_type(vl));
    }


    // sequence ReportSemaphoreEntryStatus-Response

    ReportSemaphoreEntryStatus_Response::ReportSemaphoreEntryStatus_Response() : listOfSemaphoreEntry_() {
    };

    ReportSemaphoreEntryStatus_Response::ReportSemaphoreEntryStatus_Response(const listOfSemaphoreEntry_type& arg__listOfSemaphoreEntry) :
    listOfSemaphoreEntry_(arg__listOfSemaphoreEntry) {
    };

    ReportSemaphoreEntryStatus_Response::ReportSemaphoreEntryStatus_Response(boost::shared_ptr< listOfSemaphoreEntry_type> arg__listOfSemaphoreEntry,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfSemaphoreEntry_(arg__listOfSemaphoreEntry),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReportSemaphoreEntryStatus_Response::moreFollows__default = true;

    template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfSemaphoreEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReportSemaphoreEntryStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfSemaphoreEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry_type& ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry() {
        return *listOfSemaphoreEntry_;
    }

    const ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry_type& ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry() const {
        return *listOfSemaphoreEntry_;
    }

    void ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry(const listOfSemaphoreEntry_type& vl) {
        listOfSemaphoreEntry_ = vl;
    }

    void ReportSemaphoreEntryStatus_Response::listOfSemaphoreEntry(boost::shared_ptr< listOfSemaphoreEntry_type> vl) {
        listOfSemaphoreEntry_ = vl;
    }

    const bool& ReportSemaphoreEntryStatus_Response::moreFollows() const {
        return *moreFollows_;
    }

    void ReportSemaphoreEntryStatus_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void ReportSemaphoreEntryStatus_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence SemaphoreEntry
    const int SemaphoreEntry::entryClass_simple = 0;
    const int SemaphoreEntry::entryClass_modifier = 1;

    SemaphoreEntry::SemaphoreEntry() : entryID_(), entryClass_(), applicationReference_() {
    };

    SemaphoreEntry::SemaphoreEntry(const octetstring_type& arg__entryID,
            const int& arg__entryClass,
            const MMS_Environment_1::ApplicationReference& arg__applicationReference) :
    entryID_(arg__entryID),
    entryClass_(arg__entryClass),
    applicationReference_(arg__applicationReference) {
    };

    SemaphoreEntry::SemaphoreEntry(boost::shared_ptr< octetstring_type> arg__entryID,
            boost::shared_ptr< int> arg__entryClass,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__applicationReference,
            boost::shared_ptr< Identifier> arg__namedToken,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< Unsigned32> arg__remainingTimeOut,
            boost::shared_ptr< bool> arg__abortOnTimeOut,
            boost::shared_ptr< bool> arg__relinquishIfConnectionLost) :
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

    template<> void SemaphoreEntry::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(entryID_, 0);
        ITU_T_IMPLICIT_TAG(entryClass_, 1);
        ITU_T_EXPLICIT_TAG(applicationReference_, 2);
        ITU_T_IMPLICIT_TAG(namedToken_, 3);
        ITU_T_IMPLICIT_TAG(priority_, 4);
        ITU_T_IMPLICIT_TAG(remainingTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 6);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 7);
    }

    template<> void SemaphoreEntry::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(entryID_, 0);
        ITU_T_IMPLICIT_TAG(entryClass_, 1);
        ITU_T_EXPLICIT_TAG(applicationReference_, 2);
        ITU_T_IMPLICIT_TAG(namedToken_, 3);
        ITU_T_IMPLICIT_TAG(priority_, 4);
        ITU_T_IMPLICIT_TAG(remainingTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 6);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 7);
    }

    octetstring_type& SemaphoreEntry::entryID() {
        return *entryID_;
    }

    const octetstring_type& SemaphoreEntry::entryID() const {
        return *entryID_;
    }

    void SemaphoreEntry::entryID(const octetstring_type& vl) {
        entryID_ = vl;
    }

    void SemaphoreEntry::entryID(boost::shared_ptr< octetstring_type> vl) {
        entryID_ = vl;
    }

    int& SemaphoreEntry::entryClass() {
        return *entryClass_;
    }

    const int& SemaphoreEntry::entryClass() const {
        return *entryClass_;
    }

    void SemaphoreEntry::entryClass(const int& vl) {
        entryClass_ = vl;
    }

    void SemaphoreEntry::entryClass(boost::shared_ptr< int> vl) {
        entryClass_ = vl;
    }

    MMS_Environment_1::ApplicationReference& SemaphoreEntry::applicationReference() {
        return *applicationReference_;
    }

    const MMS_Environment_1::ApplicationReference& SemaphoreEntry::applicationReference() const {
        return *applicationReference_;
    }

    void SemaphoreEntry::applicationReference(const MMS_Environment_1::ApplicationReference& vl) {
        applicationReference_ = vl;
    }

    void SemaphoreEntry::applicationReference(boost::shared_ptr< MMS_Environment_1::ApplicationReference> vl) {
        applicationReference_ = vl;
    }

    boost::shared_ptr<Identifier> SemaphoreEntry::namedToken__new() {
        return namedToken_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void SemaphoreEntry::namedToken(const Identifier& vl) {
        namedToken_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    const MMS_Object_Module_1::Priority& SemaphoreEntry::priority() const {
        return *priority_;
    }

    void SemaphoreEntry::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = vl;
    }

    void SemaphoreEntry::priority(boost::shared_ptr< MMS_Object_Module_1::Priority> vl) {
        priority_ = vl;
    }

    boost::shared_ptr<Unsigned32> SemaphoreEntry::remainingTimeOut__new() {
        return remainingTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void SemaphoreEntry::remainingTimeOut(const Unsigned32& vl) {
        remainingTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<bool> SemaphoreEntry::abortOnTimeOut__new() {
        return abortOnTimeOut_ = boost::shared_ptr<bool>(new bool());
    }

    void SemaphoreEntry::abortOnTimeOut(const bool& vl) {
        abortOnTimeOut_ = boost::shared_ptr<bool>(new bool(vl));
    }

    const bool& SemaphoreEntry::relinquishIfConnectionLost() const {
        return *relinquishIfConnectionLost_;
    }

    void SemaphoreEntry::relinquishIfConnectionLost(const bool& vl) {
        relinquishIfConnectionLost_ = vl;
    }

    void SemaphoreEntry::relinquishIfConnectionLost(boost::shared_ptr< bool> vl) {
        relinquishIfConnectionLost_ = vl;
    }


    // sequence AttachToSemaphore

    AttachToSemaphore::AttachToSemaphore() : semaphoreName_() {
    };

    AttachToSemaphore::AttachToSemaphore(const ObjectName& arg__semaphoreName) :
    semaphoreName_(arg__semaphoreName) {
    };

    AttachToSemaphore::AttachToSemaphore(boost::shared_ptr< ObjectName> arg__semaphoreName,
            boost::shared_ptr< Identifier> arg__namedToken,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< Unsigned32> arg__acceptableDelay,
            boost::shared_ptr< Unsigned32> arg__controlTimeOut,
            boost::shared_ptr< bool> arg__abortOnTimeOut,
            boost::shared_ptr< bool> arg__relinquishIfConnectionLost) :
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

    template<> void AttachToSemaphore::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
    }

    template<> void AttachToSemaphore::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(semaphoreName_, 0);
        ITU_T_IMPLICIT_TAG(namedToken_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
        ITU_T_IMPLICIT_TAG(controlTimeOut_, 4);
        ITU_T_IMPLICIT_TAG(abortOnTimeOut_, 5);
        ITU_T_IMPLICIT_TAG(relinquishIfConnectionLost_, 6);
    }

    ObjectName& AttachToSemaphore::semaphoreName() {
        return *semaphoreName_;
    }

    const ObjectName& AttachToSemaphore::semaphoreName() const {
        return *semaphoreName_;
    }

    void AttachToSemaphore::semaphoreName(const ObjectName& vl) {
        semaphoreName_ = vl;
    }

    void AttachToSemaphore::semaphoreName(boost::shared_ptr< ObjectName> vl) {
        semaphoreName_ = vl;
    }

    boost::shared_ptr<Identifier> AttachToSemaphore::namedToken__new() {
        return namedToken_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void AttachToSemaphore::namedToken(const Identifier& vl) {
        namedToken_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }

    const MMS_Object_Module_1::Priority& AttachToSemaphore::priority() const {
        return *priority_;
    }

    void AttachToSemaphore::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = vl;
    }

    void AttachToSemaphore::priority(boost::shared_ptr< MMS_Object_Module_1::Priority> vl) {
        priority_ = vl;
    }

    boost::shared_ptr<Unsigned32> AttachToSemaphore::acceptableDelay__new() {
        return acceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void AttachToSemaphore::acceptableDelay(const Unsigned32& vl) {
        acceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<Unsigned32> AttachToSemaphore::controlTimeOut__new() {
        return controlTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void AttachToSemaphore::controlTimeOut(const Unsigned32& vl) {
        controlTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<bool> AttachToSemaphore::abortOnTimeOut__new() {
        return abortOnTimeOut_ = boost::shared_ptr<bool>(new bool());
    }

    void AttachToSemaphore::abortOnTimeOut(const bool& vl) {
        abortOnTimeOut_ = boost::shared_ptr<bool>(new bool(vl));
    }

    const bool& AttachToSemaphore::relinquishIfConnectionLost() const {
        return *relinquishIfConnectionLost_;
    }

    void AttachToSemaphore::relinquishIfConnectionLost(const bool& vl) {
        relinquishIfConnectionLost_ = vl;
    }

    void AttachToSemaphore::relinquishIfConnectionLost(boost::shared_ptr< bool> vl) {
        relinquishIfConnectionLost_ = vl;
    }


    // sequence Input-Request

    Input_Request::Input_Request() : operatorStationName_() {
    };

    Input_Request::Input_Request(const Identifier& arg__operatorStationName) :
    operatorStationName_(arg__operatorStationName) {
    };

    Input_Request::Input_Request(boost::shared_ptr< Identifier> arg__operatorStationName,
            boost::shared_ptr< bool> arg__echo,
            boost::shared_ptr< listOfPromptData_type> arg__listOfPromptData,
            boost::shared_ptr< Unsigned32> arg__inputTimeOut) :
    operatorStationName_(arg__operatorStationName),
    echo_(arg__echo),
    listOfPromptData_(arg__listOfPromptData),
    inputTimeOut_(arg__inputTimeOut) {
    };

    const bool Input_Request::echo__default = true;

    template<> void Input_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(echo_, 1);
        ITU_T_IMPLICIT_TAG(listOfPromptData_, 2);
        ITU_T_IMPLICIT_TAG(inputTimeOut_, 3);
    }

    template<> void Input_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(echo_, 1);
        ITU_T_IMPLICIT_TAG(listOfPromptData_, 2);
        ITU_T_IMPLICIT_TAG(inputTimeOut_, 3);
    }

    Identifier& Input_Request::operatorStationName() {
        return *operatorStationName_;
    }

    const Identifier& Input_Request::operatorStationName() const {
        return *operatorStationName_;
    }

    void Input_Request::operatorStationName(const Identifier& vl) {
        operatorStationName_ = vl;
    }

    void Input_Request::operatorStationName(boost::shared_ptr< Identifier> vl) {
        operatorStationName_ = vl;
    }

    const bool& Input_Request::echo() const {
        return *echo_;
    }

    void Input_Request::echo(const bool& vl) {
        echo_ = vl;
    }

    void Input_Request::echo(boost::shared_ptr< bool> vl) {
        echo_ = vl;
    }

    boost::shared_ptr<Input_Request::listOfPromptData_type> Input_Request::listOfPromptData__new() {
        return listOfPromptData_ = boost::shared_ptr<listOfPromptData_type>(new listOfPromptData_type());
    }

    void Input_Request::listOfPromptData(const listOfPromptData_type& vl) {
        listOfPromptData_ = boost::shared_ptr<listOfPromptData_type>(new listOfPromptData_type(vl));
    }

    boost::shared_ptr<Unsigned32> Input_Request::inputTimeOut__new() {
        return inputTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void Input_Request::inputTimeOut(const Unsigned32& vl) {
        inputTimeOut_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }


    // sequence Output-Request

    Output_Request::Output_Request() : operatorStationName_(), listOfOutputData_() {
    };

    Output_Request::Output_Request(const Identifier& arg__operatorStationName,
            const listOfOutputData_type& arg__listOfOutputData) :
    operatorStationName_(arg__operatorStationName),
    listOfOutputData_(arg__listOfOutputData) {
    };

    template<> void Output_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(listOfOutputData_, 1);
    }

    template<> void Output_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(operatorStationName_, 0);
        ITU_T_IMPLICIT_TAG(listOfOutputData_, 1);
    }

    Identifier& Output_Request::operatorStationName() {
        return *operatorStationName_;
    }

    const Identifier& Output_Request::operatorStationName() const {
        return *operatorStationName_;
    }

    void Output_Request::operatorStationName(const Identifier& vl) {
        operatorStationName_ = vl;
    }

    void Output_Request::operatorStationName(boost::shared_ptr< Identifier> vl) {
        operatorStationName_ = vl;
    }

    Output_Request::listOfOutputData_type& Output_Request::listOfOutputData() {
        return *listOfOutputData_;
    }

    const Output_Request::listOfOutputData_type& Output_Request::listOfOutputData() const {
        return *listOfOutputData_;
    }

    void Output_Request::listOfOutputData(const listOfOutputData_type& vl) {
        listOfOutputData_ = vl;
    }

    void Output_Request::listOfOutputData(boost::shared_ptr< listOfOutputData_type> vl) {
        listOfOutputData_ = vl;
    }


    // sequence TriggerEvent-Request

    TriggerEvent_Request::TriggerEvent_Request() : eventConditionName_() {
    };

    TriggerEvent_Request::TriggerEvent_Request(const ObjectName& arg__eventConditionName) :
    eventConditionName_(arg__eventConditionName) {
    };

    TriggerEvent_Request::TriggerEvent_Request(boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority) :
    eventConditionName_(arg__eventConditionName),
    priority_(arg__priority) {
    };

    template<> void TriggerEvent_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(priority_, 1);
    }

    template<> void TriggerEvent_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(priority_, 1);
    }

    ObjectName& TriggerEvent_Request::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& TriggerEvent_Request::eventConditionName() const {
        return *eventConditionName_;
    }

    void TriggerEvent_Request::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void TriggerEvent_Request::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::Priority> TriggerEvent_Request::priority__new() {
        return priority_ = boost::shared_ptr<MMS_Object_Module_1::Priority>(new MMS_Object_Module_1::Priority());
    }

    void TriggerEvent_Request::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = boost::shared_ptr<MMS_Object_Module_1::Priority>(new MMS_Object_Module_1::Priority(vl));
    }


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

    EventNotification::EventNotification(boost::shared_ptr< ObjectName> arg__eventEnrollmentName,
            boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
            boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__transitionTime,
            boost::shared_ptr< bool> arg__notificationLost,
            boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            boost::shared_ptr< actionResult_type> arg__actionResult) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    transitionTime_(arg__transitionTime),
    notificationLost_(arg__notificationLost),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    actionResult_(arg__actionResult) {
    };

    EventNotification::actionResult_type::actionResult_type() : eventActionName_(), successOrFailure_() {
    };

    EventNotification::actionResult_type::actionResult_type(const ObjectName& arg__eventActionName,
            const successOrFailure_type& arg__successOrFailure) :
    eventActionName_(arg__eventActionName),
    successOrFailure_(arg__successOrFailure) {
    };

    EventNotification::actionResult_type::successOrFailure_type::success_type::success_type() : confirmedServiceResponse_() {
    };

    EventNotification::actionResult_type::successOrFailure_type::success_type::success_type(const ConfirmedServiceResponse& arg__confirmedServiceResponse) :
    confirmedServiceResponse_(arg__confirmedServiceResponse) {
    };

    EventNotification::actionResult_type::successOrFailure_type::success_type::success_type(boost::shared_ptr< ConfirmedServiceResponse> arg__confirmedServiceResponse,
            boost::shared_ptr< Response_Detail> arg__cs_Response_Detail) :
    confirmedServiceResponse_(arg__confirmedServiceResponse),
    cs_Response_Detail_(arg__cs_Response_Detail) {
    };

    template<> void EventNotification::actionResult_type::successOrFailure_type::success_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(confirmedServiceResponse_);
        ITU_T_CHOICE_TAG(cs_Response_Detail_, 79);
    }

    template<> void EventNotification::actionResult_type::successOrFailure_type::success_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(confirmedServiceResponse_);
        ITU_T_CHOICE_TAG(cs_Response_Detail_, 79);
    }

    ConfirmedServiceResponse& EventNotification::actionResult_type::successOrFailure_type::success_type::confirmedServiceResponse() {
        return *confirmedServiceResponse_;
    }

    const ConfirmedServiceResponse& EventNotification::actionResult_type::successOrFailure_type::success_type::confirmedServiceResponse() const {
        return *confirmedServiceResponse_;
    }

    void EventNotification::actionResult_type::successOrFailure_type::success_type::confirmedServiceResponse(const ConfirmedServiceResponse& vl) {
        confirmedServiceResponse_ = vl;
    }

    void EventNotification::actionResult_type::successOrFailure_type::success_type::confirmedServiceResponse(boost::shared_ptr< ConfirmedServiceResponse> vl) {
        confirmedServiceResponse_ = vl;
    }

    boost::shared_ptr<Response_Detail> EventNotification::actionResult_type::successOrFailure_type::success_type::cs_Response_Detail__new() {
        return cs_Response_Detail_ = boost::shared_ptr<Response_Detail>(new Response_Detail());
    }

    void EventNotification::actionResult_type::successOrFailure_type::success_type::cs_Response_Detail(const Response_Detail& vl) {
        cs_Response_Detail_ = boost::shared_ptr<Response_Detail>(new Response_Detail(vl));
    }

    EventNotification::actionResult_type::successOrFailure_type::failure_type::failure_type() : serviceError_() {
    };

    EventNotification::actionResult_type::successOrFailure_type::failure_type::failure_type(const ServiceError& arg__serviceError) :
    serviceError_(arg__serviceError) {
    };

    EventNotification::actionResult_type::successOrFailure_type::failure_type::failure_type(boost::shared_ptr< Unsigned32> arg__modifierPosition,
            boost::shared_ptr< ServiceError> arg__serviceError) :
    modifierPosition_(arg__modifierPosition),
    serviceError_(arg__serviceError) {
    };

    template<> void EventNotification::actionResult_type::successOrFailure_type::failure_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(modifierPosition_, 0);
        ITU_T_IMPLICIT_TAG(serviceError_, 1);
    }

    template<> void EventNotification::actionResult_type::successOrFailure_type::failure_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(modifierPosition_, 0);
        ITU_T_IMPLICIT_TAG(serviceError_, 1);
    }

    boost::shared_ptr<Unsigned32> EventNotification::actionResult_type::successOrFailure_type::failure_type::modifierPosition__new() {
        return modifierPosition_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void EventNotification::actionResult_type::successOrFailure_type::failure_type::modifierPosition(const Unsigned32& vl) {
        modifierPosition_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    ServiceError& EventNotification::actionResult_type::successOrFailure_type::failure_type::serviceError() {
        return *serviceError_;
    }

    const ServiceError& EventNotification::actionResult_type::successOrFailure_type::failure_type::serviceError() const {
        return *serviceError_;
    }

    void EventNotification::actionResult_type::successOrFailure_type::failure_type::serviceError(const ServiceError& vl) {
        serviceError_ = vl;
    }

    void EventNotification::actionResult_type::successOrFailure_type::failure_type::serviceError(boost::shared_ptr< ServiceError> vl) {
        serviceError_ = vl;
    }

    template<> void EventNotification::actionResult_type::successOrFailure_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case successOrFailure_type_success:
            {
                ITU_T_IMPLICIT_TAG(value<success_type > (false, successOrFailure_type_success), 0);
                break;
            }
            case successOrFailure_type_failure:
            {
                ITU_T_IMPLICIT_TAG(value<failure_type > (false, successOrFailure_type_failure), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EventNotification::actionResult_type::successOrFailure_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<success_type > (true, successOrFailure_type_success), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<failure_type > (true, successOrFailure_type_failure), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void EventNotification::actionResult_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(eventActionName_);
        ITU_T_BIND_CHOICE(successOrFailure_);
    }

    template<> void EventNotification::actionResult_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(eventActionName_);
        ITU_T_BIND_CHOICE(successOrFailure_);
    }

    ObjectName& EventNotification::actionResult_type::eventActionName() {
        return *eventActionName_;
    }

    const ObjectName& EventNotification::actionResult_type::eventActionName() const {
        return *eventActionName_;
    }

    void EventNotification::actionResult_type::eventActionName(const ObjectName& vl) {
        eventActionName_ = vl;
    }

    void EventNotification::actionResult_type::eventActionName(boost::shared_ptr< ObjectName> vl) {
        eventActionName_ = vl;
    }

    EventNotification::actionResult_type::successOrFailure_type& EventNotification::actionResult_type::successOrFailure() {
        return *successOrFailure_;
    }

    const EventNotification::actionResult_type::successOrFailure_type& EventNotification::actionResult_type::successOrFailure() const {
        return *successOrFailure_;
    }

    void EventNotification::actionResult_type::successOrFailure(const successOrFailure_type& vl) {
        successOrFailure_ = vl;
    }

    void EventNotification::actionResult_type::successOrFailure(boost::shared_ptr< successOrFailure_type> vl) {
        successOrFailure_ = vl;
    }


    const bool EventNotification::notificationLost__default = false;

    template<> void EventNotification::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(severity_, 2);
        ITU_T_IMPLICIT_TAG(currentState_, 3);
        ITU_T_CHOICE_TAG(transitionTime_, 4);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(actionResult_, 8);
    }

    template<> void EventNotification::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(severity_, 2);
        ITU_T_IMPLICIT_TAG(currentState_, 3);
        ITU_T_CHOICE_TAG(transitionTime_, 4);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(actionResult_, 8);
    }

    ObjectName& EventNotification::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& EventNotification::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void EventNotification::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void EventNotification::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    ObjectName& EventNotification::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& EventNotification::eventConditionName() const {
        return *eventConditionName_;
    }

    void EventNotification::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void EventNotification::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    MMS_Object_Module_1::Severity& EventNotification::severity() {
        return *severity_;
    }

    const MMS_Object_Module_1::Severity& EventNotification::severity() const {
        return *severity_;
    }

    void EventNotification::severity(const MMS_Object_Module_1::Severity& vl) {
        severity_ = vl;
    }

    void EventNotification::severity(boost::shared_ptr< MMS_Object_Module_1::Severity> vl) {
        severity_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::EC_State> EventNotification::currentState__new() {
        return currentState_ = boost::shared_ptr<MMS_Object_Module_1::EC_State>(new MMS_Object_Module_1::EC_State());
    }

    void EventNotification::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = boost::shared_ptr<MMS_Object_Module_1::EC_State>(new MMS_Object_Module_1::EC_State(vl));
    }

    MMS_Object_Module_1::EventTime& EventNotification::transitionTime() {
        return *transitionTime_;
    }

    const MMS_Object_Module_1::EventTime& EventNotification::transitionTime() const {
        return *transitionTime_;
    }

    void EventNotification::transitionTime(const MMS_Object_Module_1::EventTime& vl) {
        transitionTime_ = vl;
    }

    void EventNotification::transitionTime(boost::shared_ptr< MMS_Object_Module_1::EventTime> vl) {
        transitionTime_ = vl;
    }

    const bool& EventNotification::notificationLost() const {
        return *notificationLost_;
    }

    void EventNotification::notificationLost(const bool& vl) {
        notificationLost_ = vl;
    }

    void EventNotification::notificationLost(boost::shared_ptr< bool> vl) {
        notificationLost_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> EventNotification::alarmAcknowledgmentRule__new() {
        return alarmAcknowledgmentRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule());
    }

    void EventNotification::alarmAcknowledgmentRule(const MMS_Object_Module_1::AlarmAckRule& vl) {
        alarmAcknowledgmentRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule(vl));
    }

    boost::shared_ptr<EventNotification::actionResult_type> EventNotification::actionResult__new() {
        return actionResult_ = boost::shared_ptr<actionResult_type>(new actionResult_type());
    }

    void EventNotification::actionResult(const actionResult_type& vl) {
        actionResult_ = boost::shared_ptr<actionResult_type>(new actionResult_type(vl));
    }


    // choice CS-EventNotification

    void CS_EventNotification_impl::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), CS_EventNotification_impl_string);
    }

    void CS_EventNotification_impl::index(const int& vl) {
        set<int>(new int(vl), CS_EventNotification_impl_index);
    }

    void CS_EventNotification_impl::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), CS_EventNotification_impl_noEnhancement);
    }

    template<> void CS_EventNotification_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_EventNotification_impl_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, CS_EventNotification_impl_string), 0);
                break;
            }
            case CS_EventNotification_impl_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, CS_EventNotification_impl_index), 1);
                break;
            }
            case CS_EventNotification_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(value<null_type > (false, CS_EventNotification_impl_noEnhancement));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, CS_EventNotification_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, CS_EventNotification_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, CS_EventNotification_impl_noEnhancement))) return;
                else free();
            }
        }
    }


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

    template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(acknowledgedState_, 2);
        ITU_T_CHOICE_TAG(timeOfAcknowledgedTransition_, 3);
    }

    template<> void AcknowledgeEventNotification_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(acknowledgedState_, 2);
        ITU_T_CHOICE_TAG(timeOfAcknowledgedTransition_, 3);
    }

    ObjectName& AcknowledgeEventNotification_Request::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& AcknowledgeEventNotification_Request::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void AcknowledgeEventNotification_Request::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void AcknowledgeEventNotification_Request::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    MMS_Object_Module_1::EC_State& AcknowledgeEventNotification_Request::acknowledgedState() {
        return *acknowledgedState_;
    }

    const MMS_Object_Module_1::EC_State& AcknowledgeEventNotification_Request::acknowledgedState() const {
        return *acknowledgedState_;
    }

    void AcknowledgeEventNotification_Request::acknowledgedState(const MMS_Object_Module_1::EC_State& vl) {
        acknowledgedState_ = vl;
    }

    void AcknowledgeEventNotification_Request::acknowledgedState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        acknowledgedState_ = vl;
    }

    MMS_Object_Module_1::EventTime& AcknowledgeEventNotification_Request::timeOfAcknowledgedTransition() {
        return *timeOfAcknowledgedTransition_;
    }

    const MMS_Object_Module_1::EventTime& AcknowledgeEventNotification_Request::timeOfAcknowledgedTransition() const {
        return *timeOfAcknowledgedTransition_;
    }

    void AcknowledgeEventNotification_Request::timeOfAcknowledgedTransition(const MMS_Object_Module_1::EventTime& vl) {
        timeOfAcknowledgedTransition_ = vl;
    }

    void AcknowledgeEventNotification_Request::timeOfAcknowledgedTransition(boost::shared_ptr< MMS_Object_Module_1::EventTime> vl) {
        timeOfAcknowledgedTransition_ = vl;
    }


    // sequence GetAlarmSummary-Request
    const int GetAlarmSummary_Request::acknowledgementFilter_not_acked = 0;
    const int GetAlarmSummary_Request::acknowledgementFilter_acked = 1;
    const int GetAlarmSummary_Request::acknowledgementFilter_all = 2;

    GetAlarmSummary_Request::GetAlarmSummary_Request() {
    };

    GetAlarmSummary_Request::GetAlarmSummary_Request(boost::shared_ptr< bool> arg__enrollmentsOnly,
            boost::shared_ptr< bool> arg__activeAlarmsOnly,
            boost::shared_ptr< int> arg__acknowledgementFilter,
            boost::shared_ptr< severityFilter_type> arg__severityFilter,
            boost::shared_ptr< ObjectName> arg__continueAfter) :
    enrollmentsOnly_(arg__enrollmentsOnly),
    activeAlarmsOnly_(arg__activeAlarmsOnly),
    acknowledgementFilter_(arg__acknowledgementFilter),
    severityFilter_(arg__severityFilter),
    continueAfter_(arg__continueAfter) {
    };

    GetAlarmSummary_Request::severityFilter_type::severityFilter_type() : mostSevere_(), leastSevere_() {
    };

    GetAlarmSummary_Request::severityFilter_type::severityFilter_type(const Unsigned8& arg__mostSevere,
            const Unsigned8& arg__leastSevere) :
    mostSevere_(arg__mostSevere),
    leastSevere_(arg__leastSevere) {
    };

    template<> void GetAlarmSummary_Request::severityFilter_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(leastSevere_, 1);
    }

    template<> void GetAlarmSummary_Request::severityFilter_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(leastSevere_, 1);
    }

    Unsigned8& GetAlarmSummary_Request::severityFilter_type::mostSevere() {
        return *mostSevere_;
    }

    const Unsigned8& GetAlarmSummary_Request::severityFilter_type::mostSevere() const {
        return *mostSevere_;
    }

    void GetAlarmSummary_Request::severityFilter_type::mostSevere(const Unsigned8& vl) {
        mostSevere_ = vl;
    }

    void GetAlarmSummary_Request::severityFilter_type::mostSevere(boost::shared_ptr< Unsigned8> vl) {
        mostSevere_ = vl;
    }

    Unsigned8& GetAlarmSummary_Request::severityFilter_type::leastSevere() {
        return *leastSevere_;
    }

    const Unsigned8& GetAlarmSummary_Request::severityFilter_type::leastSevere() const {
        return *leastSevere_;
    }

    void GetAlarmSummary_Request::severityFilter_type::leastSevere(const Unsigned8& vl) {
        leastSevere_ = vl;
    }

    void GetAlarmSummary_Request::severityFilter_type::leastSevere(boost::shared_ptr< Unsigned8> vl) {
        leastSevere_ = vl;
    }


    const bool GetAlarmSummary_Request::enrollmentsOnly__default = true;

    const bool GetAlarmSummary_Request::activeAlarmsOnly__default = true;

    const int GetAlarmSummary_Request::acknowledgementFilter__default = 0;

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

    const bool& GetAlarmSummary_Request::enrollmentsOnly() const {
        return *enrollmentsOnly_;
    }

    void GetAlarmSummary_Request::enrollmentsOnly(const bool& vl) {
        enrollmentsOnly_ = vl;
    }

    void GetAlarmSummary_Request::enrollmentsOnly(boost::shared_ptr< bool> vl) {
        enrollmentsOnly_ = vl;
    }

    const bool& GetAlarmSummary_Request::activeAlarmsOnly() const {
        return *activeAlarmsOnly_;
    }

    void GetAlarmSummary_Request::activeAlarmsOnly(const bool& vl) {
        activeAlarmsOnly_ = vl;
    }

    void GetAlarmSummary_Request::activeAlarmsOnly(boost::shared_ptr< bool> vl) {
        activeAlarmsOnly_ = vl;
    }

    const int& GetAlarmSummary_Request::acknowledgementFilter() const {
        return *acknowledgementFilter_;
    }

    void GetAlarmSummary_Request::acknowledgementFilter(const int& vl) {
        acknowledgementFilter_ = vl;
    }

    void GetAlarmSummary_Request::acknowledgementFilter(boost::shared_ptr< int> vl) {
        acknowledgementFilter_ = vl;
    }

    boost::shared_ptr<GetAlarmSummary_Request::severityFilter_type> GetAlarmSummary_Request::severityFilter__new() {
        return severityFilter_ = boost::shared_ptr<severityFilter_type>(new severityFilter_type());
    }

    void GetAlarmSummary_Request::severityFilter(const severityFilter_type& vl) {
        severityFilter_ = boost::shared_ptr<severityFilter_type>(new severityFilter_type(vl));
    }

    boost::shared_ptr<ObjectName> GetAlarmSummary_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void GetAlarmSummary_Request::continueAfter(const ObjectName& vl) {
        continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }


    // sequence GetAlarmSummary-Response

    GetAlarmSummary_Response::GetAlarmSummary_Response() : listOfAlarmSummary_() {
    };

    GetAlarmSummary_Response::GetAlarmSummary_Response(const listOfAlarmSummary_type& arg__listOfAlarmSummary) :
    listOfAlarmSummary_(arg__listOfAlarmSummary) {
    };

    GetAlarmSummary_Response::GetAlarmSummary_Response(boost::shared_ptr< listOfAlarmSummary_type> arg__listOfAlarmSummary,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfAlarmSummary_(arg__listOfAlarmSummary),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetAlarmSummary_Response::moreFollows__default = false;

    template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfAlarmSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetAlarmSummary_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfAlarmSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    GetAlarmSummary_Response::listOfAlarmSummary_type& GetAlarmSummary_Response::listOfAlarmSummary() {
        return *listOfAlarmSummary_;
    }

    const GetAlarmSummary_Response::listOfAlarmSummary_type& GetAlarmSummary_Response::listOfAlarmSummary() const {
        return *listOfAlarmSummary_;
    }

    void GetAlarmSummary_Response::listOfAlarmSummary(const listOfAlarmSummary_type& vl) {
        listOfAlarmSummary_ = vl;
    }

    void GetAlarmSummary_Response::listOfAlarmSummary(boost::shared_ptr< listOfAlarmSummary_type> vl) {
        listOfAlarmSummary_ = vl;
    }

    const bool& GetAlarmSummary_Response::moreFollows() const {
        return *moreFollows_;
    }

    void GetAlarmSummary_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void GetAlarmSummary_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence AlarmSummary
    const int AlarmSummary::unacknowledgedState_none = 0;
    const int AlarmSummary::unacknowledgedState_active = 1;
    const int AlarmSummary::unacknowledgedState_idle = 2;
    const int AlarmSummary::unacknowledgedState_both = 3;

    AlarmSummary::AlarmSummary() : eventConditionName_(), severity_(), currentState_(), unacknowledgedState_() {
    };

    AlarmSummary::AlarmSummary(const ObjectName& arg__eventConditionName,
            const Unsigned8& arg__severity,
            const MMS_Object_Module_1::EC_State& arg__currentState,
            const int& arg__unacknowledgedState) :
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    unacknowledgedState_(arg__unacknowledgedState) {
    };

    AlarmSummary::AlarmSummary(boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< Unsigned8> arg__severity,
            boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            boost::shared_ptr< int> arg__unacknowledgedState,
            boost::shared_ptr< EN_Additional_Detail> arg__displayEnhancement,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle) :
    eventConditionName_(arg__eventConditionName),
    severity_(arg__severity),
    currentState_(arg__currentState),
    unacknowledgedState_(arg__unacknowledgedState),
    displayEnhancement_(arg__displayEnhancement),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle) {
    };

    template<> void AlarmSummary::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(severity_, 1);
        ITU_T_IMPLICIT_TAG(currentState_, 2);
        ITU_T_IMPLICIT_TAG(unacknowledgedState_, 3);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 5);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 6);
    }

    template<> void AlarmSummary::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(severity_, 1);
        ITU_T_IMPLICIT_TAG(currentState_, 2);
        ITU_T_IMPLICIT_TAG(unacknowledgedState_, 3);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 5);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 6);
    }

    ObjectName& AlarmSummary::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& AlarmSummary::eventConditionName() const {
        return *eventConditionName_;
    }

    void AlarmSummary::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void AlarmSummary::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    Unsigned8& AlarmSummary::severity() {
        return *severity_;
    }

    const Unsigned8& AlarmSummary::severity() const {
        return *severity_;
    }

    void AlarmSummary::severity(const Unsigned8& vl) {
        severity_ = vl;
    }

    void AlarmSummary::severity(boost::shared_ptr< Unsigned8> vl) {
        severity_ = vl;
    }

    MMS_Object_Module_1::EC_State& AlarmSummary::currentState() {
        return *currentState_;
    }

    const MMS_Object_Module_1::EC_State& AlarmSummary::currentState() const {
        return *currentState_;
    }

    void AlarmSummary::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = vl;
    }

    void AlarmSummary::currentState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        currentState_ = vl;
    }

    int& AlarmSummary::unacknowledgedState() {
        return *unacknowledgedState_;
    }

    const int& AlarmSummary::unacknowledgedState() const {
        return *unacknowledgedState_;
    }

    void AlarmSummary::unacknowledgedState(const int& vl) {
        unacknowledgedState_ = vl;
    }

    void AlarmSummary::unacknowledgedState(boost::shared_ptr< int> vl) {
        unacknowledgedState_ = vl;
    }

    boost::shared_ptr<EN_Additional_Detail> AlarmSummary::displayEnhancement__new() {
        return displayEnhancement_ = boost::shared_ptr<EN_Additional_Detail>(new EN_Additional_Detail());
    }

    void AlarmSummary::displayEnhancement(const EN_Additional_Detail& vl) {
        displayEnhancement_ = boost::shared_ptr<EN_Additional_Detail>(new EN_Additional_Detail(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> AlarmSummary::timeOfLastTransitionToActive__new() {
        return timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void AlarmSummary::timeOfLastTransitionToActive(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> AlarmSummary::timeOfLastTransitionToIdle__new() {
        return timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void AlarmSummary::timeOfLastTransitionToIdle(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }


    // choice EN-Additional-Detail

    void EN_Additional_Detail_impl::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), EN_Additional_Detail_impl_string);
    }

    void EN_Additional_Detail_impl::index(const int& vl) {
        set<int>(new int(vl), EN_Additional_Detail_impl_index);
    }

    void EN_Additional_Detail_impl::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), EN_Additional_Detail_impl_noEnhancement);
    }

    template<> void EN_Additional_Detail_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EN_Additional_Detail_impl_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, EN_Additional_Detail_impl_string), 0);
                break;
            }
            case EN_Additional_Detail_impl_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, EN_Additional_Detail_impl_index), 1);
                break;
            }
            case EN_Additional_Detail_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(value<null_type > (false, EN_Additional_Detail_impl_noEnhancement));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, EN_Additional_Detail_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, EN_Additional_Detail_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, EN_Additional_Detail_impl_noEnhancement))) return;
                else free();
            }
        }
    }


    // sequence GetAlarmEnrollmentSummary-Request
    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter_not_acked = 0;
    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter_acked = 1;
    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter_all = 2;

    GetAlarmEnrollmentSummary_Request::GetAlarmEnrollmentSummary_Request() {
    };

    GetAlarmEnrollmentSummary_Request::GetAlarmEnrollmentSummary_Request(boost::shared_ptr< bool> arg__enrollmentsOnly,
            boost::shared_ptr< bool> arg__activeAlarmsOnly,
            boost::shared_ptr< int> arg__acknowledgementFilter,
            boost::shared_ptr< severityFilter_type> arg__severityFilter,
            boost::shared_ptr< ObjectName> arg__continueAfter) :
    enrollmentsOnly_(arg__enrollmentsOnly),
    activeAlarmsOnly_(arg__activeAlarmsOnly),
    acknowledgementFilter_(arg__acknowledgementFilter),
    severityFilter_(arg__severityFilter),
    continueAfter_(arg__continueAfter) {
    };

    GetAlarmEnrollmentSummary_Request::severityFilter_type::severityFilter_type() : mostSevere_(), leastSevere_() {
    };

    GetAlarmEnrollmentSummary_Request::severityFilter_type::severityFilter_type(const Unsigned8& arg__mostSevere,
            const Unsigned8& arg__leastSevere) :
    mostSevere_(arg__mostSevere),
    leastSevere_(arg__leastSevere) {
    };

    template<> void GetAlarmEnrollmentSummary_Request::severityFilter_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(leastSevere_, 1);
    }

    template<> void GetAlarmEnrollmentSummary_Request::severityFilter_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mostSevere_, 0);
        ITU_T_IMPLICIT_TAG(leastSevere_, 1);
    }

    Unsigned8& GetAlarmEnrollmentSummary_Request::severityFilter_type::mostSevere() {
        return *mostSevere_;
    }

    const Unsigned8& GetAlarmEnrollmentSummary_Request::severityFilter_type::mostSevere() const {
        return *mostSevere_;
    }

    void GetAlarmEnrollmentSummary_Request::severityFilter_type::mostSevere(const Unsigned8& vl) {
        mostSevere_ = vl;
    }

    void GetAlarmEnrollmentSummary_Request::severityFilter_type::mostSevere(boost::shared_ptr< Unsigned8> vl) {
        mostSevere_ = vl;
    }

    Unsigned8& GetAlarmEnrollmentSummary_Request::severityFilter_type::leastSevere() {
        return *leastSevere_;
    }

    const Unsigned8& GetAlarmEnrollmentSummary_Request::severityFilter_type::leastSevere() const {
        return *leastSevere_;
    }

    void GetAlarmEnrollmentSummary_Request::severityFilter_type::leastSevere(const Unsigned8& vl) {
        leastSevere_ = vl;
    }

    void GetAlarmEnrollmentSummary_Request::severityFilter_type::leastSevere(boost::shared_ptr< Unsigned8> vl) {
        leastSevere_ = vl;
    }


    const bool GetAlarmEnrollmentSummary_Request::enrollmentsOnly__default = true;

    const bool GetAlarmEnrollmentSummary_Request::activeAlarmsOnly__default = true;

    const int GetAlarmEnrollmentSummary_Request::acknowledgementFilter__default = 0;

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

    const bool& GetAlarmEnrollmentSummary_Request::enrollmentsOnly() const {
        return *enrollmentsOnly_;
    }

    void GetAlarmEnrollmentSummary_Request::enrollmentsOnly(const bool& vl) {
        enrollmentsOnly_ = vl;
    }

    void GetAlarmEnrollmentSummary_Request::enrollmentsOnly(boost::shared_ptr< bool> vl) {
        enrollmentsOnly_ = vl;
    }

    const bool& GetAlarmEnrollmentSummary_Request::activeAlarmsOnly() const {
        return *activeAlarmsOnly_;
    }

    void GetAlarmEnrollmentSummary_Request::activeAlarmsOnly(const bool& vl) {
        activeAlarmsOnly_ = vl;
    }

    void GetAlarmEnrollmentSummary_Request::activeAlarmsOnly(boost::shared_ptr< bool> vl) {
        activeAlarmsOnly_ = vl;
    }

    const int& GetAlarmEnrollmentSummary_Request::acknowledgementFilter() const {
        return *acknowledgementFilter_;
    }

    void GetAlarmEnrollmentSummary_Request::acknowledgementFilter(const int& vl) {
        acknowledgementFilter_ = vl;
    }

    void GetAlarmEnrollmentSummary_Request::acknowledgementFilter(boost::shared_ptr< int> vl) {
        acknowledgementFilter_ = vl;
    }

    boost::shared_ptr<GetAlarmEnrollmentSummary_Request::severityFilter_type> GetAlarmEnrollmentSummary_Request::severityFilter__new() {
        return severityFilter_ = boost::shared_ptr<severityFilter_type>(new severityFilter_type());
    }

    void GetAlarmEnrollmentSummary_Request::severityFilter(const severityFilter_type& vl) {
        severityFilter_ = boost::shared_ptr<severityFilter_type>(new severityFilter_type(vl));
    }

    boost::shared_ptr<ObjectName> GetAlarmEnrollmentSummary_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void GetAlarmEnrollmentSummary_Request::continueAfter(const ObjectName& vl) {
        continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }


    // sequence GetAlarmEnrollmentSummary-Response

    GetAlarmEnrollmentSummary_Response::GetAlarmEnrollmentSummary_Response() : listOfAlarmEnrollmentSummary_() {
    };

    GetAlarmEnrollmentSummary_Response::GetAlarmEnrollmentSummary_Response(const listOfAlarmEnrollmentSummary_type& arg__listOfAlarmEnrollmentSummary) :
    listOfAlarmEnrollmentSummary_(arg__listOfAlarmEnrollmentSummary) {
    };

    GetAlarmEnrollmentSummary_Response::GetAlarmEnrollmentSummary_Response(boost::shared_ptr< listOfAlarmEnrollmentSummary_type> arg__listOfAlarmEnrollmentSummary,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfAlarmEnrollmentSummary_(arg__listOfAlarmEnrollmentSummary),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetAlarmEnrollmentSummary_Response::moreFollows__default = false;

    template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfAlarmEnrollmentSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetAlarmEnrollmentSummary_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfAlarmEnrollmentSummary_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary_type& GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary() {
        return *listOfAlarmEnrollmentSummary_;
    }

    const GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary_type& GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary() const {
        return *listOfAlarmEnrollmentSummary_;
    }

    void GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary(const listOfAlarmEnrollmentSummary_type& vl) {
        listOfAlarmEnrollmentSummary_ = vl;
    }

    void GetAlarmEnrollmentSummary_Response::listOfAlarmEnrollmentSummary(boost::shared_ptr< listOfAlarmEnrollmentSummary_type> vl) {
        listOfAlarmEnrollmentSummary_ = vl;
    }

    const bool& GetAlarmEnrollmentSummary_Response::moreFollows() const {
        return *moreFollows_;
    }

    void GetAlarmEnrollmentSummary_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void GetAlarmEnrollmentSummary_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


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

    AlarmEnrollmentSummary::AlarmEnrollmentSummary(boost::shared_ptr< ObjectName> arg__eventEnrollmentName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            boost::shared_ptr< Unsigned8> arg__severity,
            boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            boost::shared_ptr< EN_Additional_Detail> arg__displayEnhancement,
            boost::shared_ptr< bool> arg__notificationLost,
            boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            boost::shared_ptr< EE_State> arg__enrollmentState,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeActiveAcknowledged,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeIdleAcknowledged) :
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

    template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_EXPLICIT_TAG(clientApplication_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(currentState_, 4);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 5);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(enrollmentState_, 8);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 9);
        ITU_T_CHOICE_TAG(timeActiveAcknowledged_, 10);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 11);
        ITU_T_CHOICE_TAG(timeIdleAcknowledged_, 12);
    }

    template<> void AlarmEnrollmentSummary::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_EXPLICIT_TAG(clientApplication_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(currentState_, 4);
        ITU_T_EXPLICIT_TAG(displayEnhancement_, 5);
        ITU_T_IMPLICIT_TAG(notificationLost_, 6);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 7);
        ITU_T_IMPLICIT_TAG(enrollmentState_, 8);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 9);
        ITU_T_CHOICE_TAG(timeActiveAcknowledged_, 10);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 11);
        ITU_T_CHOICE_TAG(timeIdleAcknowledged_, 12);
    }

    ObjectName& AlarmEnrollmentSummary::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& AlarmEnrollmentSummary::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void AlarmEnrollmentSummary::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void AlarmEnrollmentSummary::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> AlarmEnrollmentSummary::clientApplication__new() {
        return clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void AlarmEnrollmentSummary::clientApplication(const MMS_Environment_1::ApplicationReference& vl) {
        clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }

    Unsigned8& AlarmEnrollmentSummary::severity() {
        return *severity_;
    }

    const Unsigned8& AlarmEnrollmentSummary::severity() const {
        return *severity_;
    }

    void AlarmEnrollmentSummary::severity(const Unsigned8& vl) {
        severity_ = vl;
    }

    void AlarmEnrollmentSummary::severity(boost::shared_ptr< Unsigned8> vl) {
        severity_ = vl;
    }

    MMS_Object_Module_1::EC_State& AlarmEnrollmentSummary::currentState() {
        return *currentState_;
    }

    const MMS_Object_Module_1::EC_State& AlarmEnrollmentSummary::currentState() const {
        return *currentState_;
    }

    void AlarmEnrollmentSummary::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = vl;
    }

    void AlarmEnrollmentSummary::currentState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        currentState_ = vl;
    }

    boost::shared_ptr<EN_Additional_Detail> AlarmEnrollmentSummary::displayEnhancement__new() {
        return displayEnhancement_ = boost::shared_ptr<EN_Additional_Detail>(new EN_Additional_Detail());
    }

    void AlarmEnrollmentSummary::displayEnhancement(const EN_Additional_Detail& vl) {
        displayEnhancement_ = boost::shared_ptr<EN_Additional_Detail>(new EN_Additional_Detail(vl));
    }

    const bool& AlarmEnrollmentSummary::notificationLost() const {
        return *notificationLost_;
    }

    void AlarmEnrollmentSummary::notificationLost(const bool& vl) {
        notificationLost_ = vl;
    }

    void AlarmEnrollmentSummary::notificationLost(boost::shared_ptr< bool> vl) {
        notificationLost_ = vl;
    }

    MMS_Object_Module_1::AlarmAckRule& AlarmEnrollmentSummary::alarmAcknowledgmentRule() {
        return *alarmAcknowledgmentRule_;
    }

    const MMS_Object_Module_1::AlarmAckRule& AlarmEnrollmentSummary::alarmAcknowledgmentRule() const {
        return *alarmAcknowledgmentRule_;
    }

    void AlarmEnrollmentSummary::alarmAcknowledgmentRule(const MMS_Object_Module_1::AlarmAckRule& vl) {
        alarmAcknowledgmentRule_ = vl;
    }

    void AlarmEnrollmentSummary::alarmAcknowledgmentRule(boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> vl) {
        alarmAcknowledgmentRule_ = vl;
    }

    boost::shared_ptr<EE_State> AlarmEnrollmentSummary::enrollmentState__new() {
        return enrollmentState_ = boost::shared_ptr<EE_State>(new EE_State());
    }

    void AlarmEnrollmentSummary::enrollmentState(const EE_State& vl) {
        enrollmentState_ = boost::shared_ptr<EE_State>(new EE_State(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> AlarmEnrollmentSummary::timeOfLastTransitionToActive__new() {
        return timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void AlarmEnrollmentSummary::timeOfLastTransitionToActive(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> AlarmEnrollmentSummary::timeActiveAcknowledged__new() {
        return timeActiveAcknowledged_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void AlarmEnrollmentSummary::timeActiveAcknowledged(const MMS_Object_Module_1::EventTime& vl) {
        timeActiveAcknowledged_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> AlarmEnrollmentSummary::timeOfLastTransitionToIdle__new() {
        return timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void AlarmEnrollmentSummary::timeOfLastTransitionToIdle(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> AlarmEnrollmentSummary::timeIdleAcknowledged__new() {
        return timeIdleAcknowledged_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void AlarmEnrollmentSummary::timeIdleAcknowledged(const MMS_Object_Module_1::EventTime& vl) {
        timeIdleAcknowledged_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }


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

    AttachToEventCondition::AttachToEventCondition(boost::shared_ptr< ObjectName> arg__eventEnrollmentName,
            boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< MMS_Object_Module_1::Transitions> arg__causingTransitions,
            boost::shared_ptr< Unsigned32> arg__acceptableDelay) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    causingTransitions_(arg__causingTransitions),
    acceptableDelay_(arg__acceptableDelay) {
    };

    template<> void AttachToEventCondition::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(causingTransitions_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
    }

    template<> void AttachToEventCondition::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(causingTransitions_, 2);
        ITU_T_IMPLICIT_TAG(acceptableDelay_, 3);
    }

    ObjectName& AttachToEventCondition::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& AttachToEventCondition::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void AttachToEventCondition::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void AttachToEventCondition::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    ObjectName& AttachToEventCondition::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& AttachToEventCondition::eventConditionName() const {
        return *eventConditionName_;
    }

    void AttachToEventCondition::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void AttachToEventCondition::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    MMS_Object_Module_1::Transitions& AttachToEventCondition::causingTransitions() {
        return *causingTransitions_;
    }

    const MMS_Object_Module_1::Transitions& AttachToEventCondition::causingTransitions() const {
        return *causingTransitions_;
    }

    void AttachToEventCondition::causingTransitions(const MMS_Object_Module_1::Transitions& vl) {
        causingTransitions_ = vl;
    }

    void AttachToEventCondition::causingTransitions(boost::shared_ptr< MMS_Object_Module_1::Transitions> vl) {
        causingTransitions_ = vl;
    }

    boost::shared_ptr<Unsigned32> AttachToEventCondition::acceptableDelay__new() {
        return acceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void AttachToEventCondition::acceptableDelay(const Unsigned32& vl) {
        acceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }


    // sequence DefineEventCondition-Request

    DefineEventCondition_Request::DefineEventCondition_Request() : eventConditionName_(), classV_() {
    };

    DefineEventCondition_Request::DefineEventCondition_Request(const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::EC_Class& arg__classV) :
    eventConditionName_(arg__eventConditionName),
    classV_(arg__classV) {
    };

    DefineEventCondition_Request::DefineEventCondition_Request(boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< MMS_Object_Module_1::EC_Class> arg__classV,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< Unsigned8> arg__severity,
            boost::shared_ptr< bool> arg__alarmSummaryReports,
            boost::shared_ptr< VariableSpecification> arg__monitoredVariable,
            boost::shared_ptr< Unsigned32> arg__evaluationInterval) :
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

    template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
    }

    template<> void DefineEventCondition_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
    }

    ObjectName& DefineEventCondition_Request::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& DefineEventCondition_Request::eventConditionName() const {
        return *eventConditionName_;
    }

    void DefineEventCondition_Request::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void DefineEventCondition_Request::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    MMS_Object_Module_1::EC_Class& DefineEventCondition_Request::classV() {
        return *classV_;
    }

    const MMS_Object_Module_1::EC_Class& DefineEventCondition_Request::classV() const {
        return *classV_;
    }

    void DefineEventCondition_Request::classV(const MMS_Object_Module_1::EC_Class& vl) {
        classV_ = vl;
    }

    void DefineEventCondition_Request::classV(boost::shared_ptr< MMS_Object_Module_1::EC_Class> vl) {
        classV_ = vl;
    }

    const MMS_Object_Module_1::Priority& DefineEventCondition_Request::priority() const {
        return *priority_;
    }

    void DefineEventCondition_Request::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = vl;
    }

    void DefineEventCondition_Request::priority(boost::shared_ptr< MMS_Object_Module_1::Priority> vl) {
        priority_ = vl;
    }

    const Unsigned8& DefineEventCondition_Request::severity() const {
        return *severity_;
    }

    void DefineEventCondition_Request::severity(const Unsigned8& vl) {
        severity_ = vl;
    }

    void DefineEventCondition_Request::severity(boost::shared_ptr< Unsigned8> vl) {
        severity_ = vl;
    }

    boost::shared_ptr<bool> DefineEventCondition_Request::alarmSummaryReports__new() {
        return alarmSummaryReports_ = boost::shared_ptr<bool>(new bool());
    }

    void DefineEventCondition_Request::alarmSummaryReports(const bool& vl) {
        alarmSummaryReports_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<VariableSpecification> DefineEventCondition_Request::monitoredVariable__new() {
        return monitoredVariable_ = boost::shared_ptr<VariableSpecification>(new VariableSpecification());
    }

    void DefineEventCondition_Request::monitoredVariable(const VariableSpecification& vl) {
        monitoredVariable_ = boost::shared_ptr<VariableSpecification>(new VariableSpecification(vl));
    }

    boost::shared_ptr<Unsigned32> DefineEventCondition_Request::evaluationInterval__new() {
        return evaluationInterval_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void DefineEventCondition_Request::evaluationInterval(const Unsigned32& vl) {
        evaluationInterval_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }


    // choice CS-DefineEventCondition-Request

    void CS_DefineEventCondition_Request_impl::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), CS_DefineEventCondition_Request_impl_string);
    }

    void CS_DefineEventCondition_Request_impl::index(const int& vl) {
        set<int>(new int(vl), CS_DefineEventCondition_Request_impl_index);
    }

    void CS_DefineEventCondition_Request_impl::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), CS_DefineEventCondition_Request_impl_noEnhancement);
    }

    template<> void CS_DefineEventCondition_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_DefineEventCondition_Request_impl_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, CS_DefineEventCondition_Request_impl_string), 0);
                break;
            }
            case CS_DefineEventCondition_Request_impl_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, CS_DefineEventCondition_Request_impl_index), 1);
                break;
            }
            case CS_DefineEventCondition_Request_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(value<null_type > (false, CS_DefineEventCondition_Request_impl_noEnhancement));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, CS_DefineEventCondition_Request_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, CS_DefineEventCondition_Request_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, CS_DefineEventCondition_Request_impl_noEnhancement))) return;
                else free();
            }
        }
    }


    // choice DeleteEventCondition-Request

    void DeleteEventCondition_Request::aa_specific(const null_type& vl) {
        set<null_type>(new null_type(vl), DeleteEventCondition_Request_aa_specific);
    }

    void DeleteEventCondition_Request::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), DeleteEventCondition_Request_domain);
    }

    void DeleteEventCondition_Request::vmd(const null_type& vl) {
        set<null_type>(new null_type(vl), DeleteEventCondition_Request_vmd);
    }

    template<> void DeleteEventCondition_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteEventCondition_Request_specific:
            {
                ITU_T_IMPLICIT_TAG(value<specific_type > (false, DeleteEventCondition_Request_specific), 0);
                break;
            }
            case DeleteEventCondition_Request_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, DeleteEventCondition_Request_aa_specific), 1);
                break;
            }
            case DeleteEventCondition_Request_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, DeleteEventCondition_Request_domain), 2);
                break;
            }
            case DeleteEventCondition_Request_vmd:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, DeleteEventCondition_Request_vmd), 3);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<specific_type > (true, DeleteEventCondition_Request_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, DeleteEventCondition_Request_aa_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, DeleteEventCondition_Request_domain), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, DeleteEventCondition_Request_vmd), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    GetEventConditionAttributes_Response::GetEventConditionAttributes_Response() : classV_() {
    };

    GetEventConditionAttributes_Response::GetEventConditionAttributes_Response(const MMS_Object_Module_1::EC_Class& arg__classV) :
    classV_(arg__classV) {
    };

    GetEventConditionAttributes_Response::GetEventConditionAttributes_Response(boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< MMS_Object_Module_1::EC_Class> arg__classV,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< Unsigned8> arg__severity,
            boost::shared_ptr< bool> arg__alarmSummaryReports,
            boost::shared_ptr< monitoredVariable_type> arg__monitoredVariable,
            boost::shared_ptr< Unsigned32> arg__evaluationInterval,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    classV_(arg__classV),
    priority_(arg__priority),
    severity_(arg__severity),
    alarmSummaryReports_(arg__alarmSummaryReports),
    monitoredVariable_(arg__monitoredVariable),
    evaluationInterval_(arg__evaluationInterval),
    accessControlList_(arg__accessControlList) {
    };

    void GetEventConditionAttributes_Response::monitoredVariable_type::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), monitoredVariable_type_undefined);
    }

    template<> void GetEventConditionAttributes_Response::monitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case monitoredVariable_type_variableReference:
            {
                ITU_T_CHOICE_TAG(value<VariableSpecification > (false, monitoredVariable_type_variableReference), 0);
                break;
            }
            case monitoredVariable_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, monitoredVariable_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void GetEventConditionAttributes_Response::monitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<VariableSpecification > (true, monitoredVariable_type_variableReference), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, monitoredVariable_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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


    const bool GetEventConditionAttributes_Response::mmsDeletable__default = false;

    const MMS_Object_Module_1::Priority GetEventConditionAttributes_Response::priority__default = MMS_Object_Module_1::Priority(64);

    const Unsigned8 GetEventConditionAttributes_Response::severity__default = Unsigned8(64);

    const bool GetEventConditionAttributes_Response::alarmSummaryReports__default = false;

    template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
        ITU_T_IMPLICIT_TAG(accessControlList_, 8);
    }

    template<> void GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(classV_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(severity_, 3);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 4);
        ITU_T_CHOICE_TAG(monitoredVariable_, 6);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 7);
        ITU_T_IMPLICIT_TAG(accessControlList_, 8);
    }

    const bool& GetEventConditionAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetEventConditionAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetEventConditionAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    MMS_Object_Module_1::EC_Class& GetEventConditionAttributes_Response::classV() {
        return *classV_;
    }

    const MMS_Object_Module_1::EC_Class& GetEventConditionAttributes_Response::classV() const {
        return *classV_;
    }

    void GetEventConditionAttributes_Response::classV(const MMS_Object_Module_1::EC_Class& vl) {
        classV_ = vl;
    }

    void GetEventConditionAttributes_Response::classV(boost::shared_ptr< MMS_Object_Module_1::EC_Class> vl) {
        classV_ = vl;
    }

    const MMS_Object_Module_1::Priority& GetEventConditionAttributes_Response::priority() const {
        return *priority_;
    }

    void GetEventConditionAttributes_Response::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = vl;
    }

    void GetEventConditionAttributes_Response::priority(boost::shared_ptr< MMS_Object_Module_1::Priority> vl) {
        priority_ = vl;
    }

    const Unsigned8& GetEventConditionAttributes_Response::severity() const {
        return *severity_;
    }

    void GetEventConditionAttributes_Response::severity(const Unsigned8& vl) {
        severity_ = vl;
    }

    void GetEventConditionAttributes_Response::severity(boost::shared_ptr< Unsigned8> vl) {
        severity_ = vl;
    }

    const bool& GetEventConditionAttributes_Response::alarmSummaryReports() const {
        return *alarmSummaryReports_;
    }

    void GetEventConditionAttributes_Response::alarmSummaryReports(const bool& vl) {
        alarmSummaryReports_ = vl;
    }

    void GetEventConditionAttributes_Response::alarmSummaryReports(boost::shared_ptr< bool> vl) {
        alarmSummaryReports_ = vl;
    }

    boost::shared_ptr<GetEventConditionAttributes_Response::monitoredVariable_type> GetEventConditionAttributes_Response::monitoredVariable__new() {
        return monitoredVariable_ = boost::shared_ptr<monitoredVariable_type>(new monitoredVariable_type());
    }

    void GetEventConditionAttributes_Response::monitoredVariable(const monitoredVariable_type& vl) {
        monitoredVariable_ = boost::shared_ptr<monitoredVariable_type>(new monitoredVariable_type(vl));
    }

    boost::shared_ptr<Unsigned32> GetEventConditionAttributes_Response::evaluationInterval__new() {
        return evaluationInterval_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void GetEventConditionAttributes_Response::evaluationInterval(const Unsigned32& vl) {
        evaluationInterval_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<Identifier> GetEventConditionAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetEventConditionAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence CS-GetEventConditionAttributes-Response

    CS_GetEventConditionAttributes_Response::CS_GetEventConditionAttributes_Response() : displayEnhancement_() {
    };

    CS_GetEventConditionAttributes_Response::CS_GetEventConditionAttributes_Response(const displayEnhancement_type& arg__displayEnhancement) :
    displayEnhancement_(arg__displayEnhancement) {
    };

    CS_GetEventConditionAttributes_Response::CS_GetEventConditionAttributes_Response(boost::shared_ptr< groupPriorityOverride_type> arg__groupPriorityOverride,
            boost::shared_ptr< listOfReferencingECL_type> arg__listOfReferencingECL,
            boost::shared_ptr< displayEnhancement_type> arg__displayEnhancement) :
    groupPriorityOverride_(arg__groupPriorityOverride),
    listOfReferencingECL_(arg__listOfReferencingECL),
    displayEnhancement_(arg__displayEnhancement) {
    };

    void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::priority(const MMS_Object_Module_1::Priority& vl) {
        set<MMS_Object_Module_1::Priority>(new MMS_Object_Module_1::Priority(vl), groupPriorityOverride_type_priority);
    }

    void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), groupPriorityOverride_type_undefined);
    }

    template<> void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case groupPriorityOverride_type_priority:
            {
                ITU_T_IMPLICIT_TAG(value<MMS_Object_Module_1::Priority > (false, groupPriorityOverride_type_priority), 0);
                break;
            }
            case groupPriorityOverride_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, groupPriorityOverride_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetEventConditionAttributes_Response::groupPriorityOverride_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<MMS_Object_Module_1::Priority > (true, groupPriorityOverride_type_priority), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, groupPriorityOverride_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void CS_GetEventConditionAttributes_Response::displayEnhancement_type::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), displayEnhancement_type_string);
    }

    void CS_GetEventConditionAttributes_Response::displayEnhancement_type::index(const int& vl) {
        set<int>(new int(vl), displayEnhancement_type_index);
    }

    void CS_GetEventConditionAttributes_Response::displayEnhancement_type::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), displayEnhancement_type_noEnhancement);
    }

    template<> void CS_GetEventConditionAttributes_Response::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case displayEnhancement_type_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, displayEnhancement_type_string), 0);
                break;
            }
            case displayEnhancement_type_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, displayEnhancement_type_index), 1);
                break;
            }
            case displayEnhancement_type_noEnhancement:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, displayEnhancement_type_noEnhancement), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_GetEventConditionAttributes_Response::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, displayEnhancement_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, displayEnhancement_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, displayEnhancement_type_noEnhancement), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(groupPriorityOverride_, 0);
        ITU_T_IMPLICIT_TAG(listOfReferencingECL_, 1);
        ITU_T_CHOICE_TAG(displayEnhancement_, 2);
    }

    template<> void CS_GetEventConditionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(groupPriorityOverride_, 0);
        ITU_T_IMPLICIT_TAG(listOfReferencingECL_, 1);
        ITU_T_CHOICE_TAG(displayEnhancement_, 2);
    }

    boost::shared_ptr<CS_GetEventConditionAttributes_Response::groupPriorityOverride_type> CS_GetEventConditionAttributes_Response::groupPriorityOverride__new() {
        return groupPriorityOverride_ = boost::shared_ptr<groupPriorityOverride_type>(new groupPriorityOverride_type());
    }

    void CS_GetEventConditionAttributes_Response::groupPriorityOverride(const groupPriorityOverride_type& vl) {
        groupPriorityOverride_ = boost::shared_ptr<groupPriorityOverride_type>(new groupPriorityOverride_type(vl));
    }

    boost::shared_ptr<CS_GetEventConditionAttributes_Response::listOfReferencingECL_type> CS_GetEventConditionAttributes_Response::listOfReferencingECL__new() {
        return listOfReferencingECL_ = boost::shared_ptr<listOfReferencingECL_type>(new listOfReferencingECL_type());
    }

    void CS_GetEventConditionAttributes_Response::listOfReferencingECL(const listOfReferencingECL_type& vl) {
        listOfReferencingECL_ = boost::shared_ptr<listOfReferencingECL_type>(new listOfReferencingECL_type(vl));
    }

    CS_GetEventConditionAttributes_Response::displayEnhancement_type& CS_GetEventConditionAttributes_Response::displayEnhancement() {
        return *displayEnhancement_;
    }

    const CS_GetEventConditionAttributes_Response::displayEnhancement_type& CS_GetEventConditionAttributes_Response::displayEnhancement() const {
        return *displayEnhancement_;
    }

    void CS_GetEventConditionAttributes_Response::displayEnhancement(const displayEnhancement_type& vl) {
        displayEnhancement_ = vl;
    }

    void CS_GetEventConditionAttributes_Response::displayEnhancement(boost::shared_ptr< displayEnhancement_type> vl) {
        displayEnhancement_ = vl;
    }


    // sequence ReportEventConditionStatus-Response

    ReportEventConditionStatus_Response::ReportEventConditionStatus_Response() : currentState_(), numberOfEventEnrollments_() {
    };

    ReportEventConditionStatus_Response::ReportEventConditionStatus_Response(const MMS_Object_Module_1::EC_State& arg__currentState,
            const Unsigned32& arg__numberOfEventEnrollments) :
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments) {
    };

    ReportEventConditionStatus_Response::ReportEventConditionStatus_Response(boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            boost::shared_ptr< Unsigned32> arg__numberOfEventEnrollments,
            boost::shared_ptr< bool> arg__enabled,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle) :
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments),
    enabled_(arg__enabled),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle) {
    };

    template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(currentState_, 0);
        ITU_T_IMPLICIT_TAG(numberOfEventEnrollments_, 1);
        ITU_T_IMPLICIT_TAG(enabled_, 2);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 4);
    }

    template<> void ReportEventConditionStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(currentState_, 0);
        ITU_T_IMPLICIT_TAG(numberOfEventEnrollments_, 1);
        ITU_T_IMPLICIT_TAG(enabled_, 2);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 4);
    }

    MMS_Object_Module_1::EC_State& ReportEventConditionStatus_Response::currentState() {
        return *currentState_;
    }

    const MMS_Object_Module_1::EC_State& ReportEventConditionStatus_Response::currentState() const {
        return *currentState_;
    }

    void ReportEventConditionStatus_Response::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = vl;
    }

    void ReportEventConditionStatus_Response::currentState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        currentState_ = vl;
    }

    Unsigned32& ReportEventConditionStatus_Response::numberOfEventEnrollments() {
        return *numberOfEventEnrollments_;
    }

    const Unsigned32& ReportEventConditionStatus_Response::numberOfEventEnrollments() const {
        return *numberOfEventEnrollments_;
    }

    void ReportEventConditionStatus_Response::numberOfEventEnrollments(const Unsigned32& vl) {
        numberOfEventEnrollments_ = vl;
    }

    void ReportEventConditionStatus_Response::numberOfEventEnrollments(boost::shared_ptr< Unsigned32> vl) {
        numberOfEventEnrollments_ = vl;
    }

    boost::shared_ptr<bool> ReportEventConditionStatus_Response::enabled__new() {
        return enabled_ = boost::shared_ptr<bool>(new bool());
    }

    void ReportEventConditionStatus_Response::enabled(const bool& vl) {
        enabled_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> ReportEventConditionStatus_Response::timeOfLastTransitionToActive__new() {
        return timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void ReportEventConditionStatus_Response::timeOfLastTransitionToActive(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> ReportEventConditionStatus_Response::timeOfLastTransitionToIdle__new() {
        return timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void ReportEventConditionStatus_Response::timeOfLastTransitionToIdle(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }


    // sequence AlterEventConditionMonitoring-Request

    AlterEventConditionMonitoring_Request::AlterEventConditionMonitoring_Request() : eventConditionName_() {
    };

    AlterEventConditionMonitoring_Request::AlterEventConditionMonitoring_Request(const ObjectName& arg__eventConditionName) :
    eventConditionName_(arg__eventConditionName) {
    };

    AlterEventConditionMonitoring_Request::AlterEventConditionMonitoring_Request(boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< bool> arg__enabled,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< bool> arg__alarmSummaryReports,
            boost::shared_ptr< Unsigned32> arg__evaluationInterval) :
    eventConditionName_(arg__eventConditionName),
    enabled_(arg__enabled),
    priority_(arg__priority),
    alarmSummaryReports_(arg__alarmSummaryReports),
    evaluationInterval_(arg__evaluationInterval) {
    };

    template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(enabled_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 3);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 4);
    }

    template<> void AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(enabled_, 1);
        ITU_T_IMPLICIT_TAG(priority_, 2);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 3);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 4);
    }

    ObjectName& AlterEventConditionMonitoring_Request::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& AlterEventConditionMonitoring_Request::eventConditionName() const {
        return *eventConditionName_;
    }

    void AlterEventConditionMonitoring_Request::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void AlterEventConditionMonitoring_Request::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    boost::shared_ptr<bool> AlterEventConditionMonitoring_Request::enabled__new() {
        return enabled_ = boost::shared_ptr<bool>(new bool());
    }

    void AlterEventConditionMonitoring_Request::enabled(const bool& vl) {
        enabled_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::Priority> AlterEventConditionMonitoring_Request::priority__new() {
        return priority_ = boost::shared_ptr<MMS_Object_Module_1::Priority>(new MMS_Object_Module_1::Priority());
    }

    void AlterEventConditionMonitoring_Request::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = boost::shared_ptr<MMS_Object_Module_1::Priority>(new MMS_Object_Module_1::Priority(vl));
    }

    boost::shared_ptr<bool> AlterEventConditionMonitoring_Request::alarmSummaryReports__new() {
        return alarmSummaryReports_ = boost::shared_ptr<bool>(new bool());
    }

    void AlterEventConditionMonitoring_Request::alarmSummaryReports(const bool& vl) {
        alarmSummaryReports_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<Unsigned32> AlterEventConditionMonitoring_Request::evaluationInterval__new() {
        return evaluationInterval_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void AlterEventConditionMonitoring_Request::evaluationInterval(const Unsigned32& vl) {
        evaluationInterval_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }


    // sequence CS-AlterEventConditionMonitoring-Request

    CS_AlterEventConditionMonitoring_Request::CS_AlterEventConditionMonitoring_Request() {
    };

    CS_AlterEventConditionMonitoring_Request::CS_AlterEventConditionMonitoring_Request(boost::shared_ptr< changeDisplay_type> arg__changeDisplay) :
    changeDisplay_(arg__changeDisplay) {
    };

    void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), changeDisplay_type_string);
    }

    void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::index(const int& vl) {
        set<int>(new int(vl), changeDisplay_type_index);
    }

    void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), changeDisplay_type_noEnhancement);
    }

    template<> void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case changeDisplay_type_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, changeDisplay_type_string), 0);
                break;
            }
            case changeDisplay_type_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, changeDisplay_type_index), 1);
                break;
            }
            case changeDisplay_type_noEnhancement:
            {
                ITU_T_EXPLICIT_TAG(value<null_type > (false, changeDisplay_type_noEnhancement), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_AlterEventConditionMonitoring_Request::changeDisplay_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, changeDisplay_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, changeDisplay_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<null_type > (true, changeDisplay_type_noEnhancement), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    template<> void CS_AlterEventConditionMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    boost::shared_ptr<CS_AlterEventConditionMonitoring_Request::changeDisplay_type> CS_AlterEventConditionMonitoring_Request::changeDisplay__new() {
        return changeDisplay_ = boost::shared_ptr<changeDisplay_type>(new changeDisplay_type());
    }

    void CS_AlterEventConditionMonitoring_Request::changeDisplay(const changeDisplay_type& vl) {
        changeDisplay_ = boost::shared_ptr<changeDisplay_type>(new changeDisplay_type(vl));
    }


    // sequence DefineEventAction-Request

    DefineEventAction_Request::DefineEventAction_Request() : eventActionName_(), confirmedServiceRequest_() {
    };

    DefineEventAction_Request::DefineEventAction_Request(const ObjectName& arg__eventActionName,
            const ConfirmedServiceRequest& arg__confirmedServiceRequest) :
    eventActionName_(arg__eventActionName),
    confirmedServiceRequest_(arg__confirmedServiceRequest) {
    };

    DefineEventAction_Request::DefineEventAction_Request(boost::shared_ptr< ObjectName> arg__eventActionName,
            boost::shared_ptr< listOfModifier_type> arg__listOfModifier,
            boost::shared_ptr< ConfirmedServiceRequest> arg__confirmedServiceRequest,
            boost::shared_ptr< Request_Detail> arg__cs_extension) :
    eventActionName_(arg__eventActionName),
    listOfModifier_(arg__listOfModifier),
    confirmedServiceRequest_(arg__confirmedServiceRequest),
    cs_extension_(arg__cs_extension) {
    };

    template<> void DefineEventAction_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventActionName_, 0);
        ITU_T_IMPLICIT_TAG(listOfModifier_, 1);
        ITU_T_CHOICE_TAG(confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
    }

    template<> void DefineEventAction_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventActionName_, 0);
        ITU_T_IMPLICIT_TAG(listOfModifier_, 1);
        ITU_T_CHOICE_TAG(confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
    }

    ObjectName& DefineEventAction_Request::eventActionName() {
        return *eventActionName_;
    }

    const ObjectName& DefineEventAction_Request::eventActionName() const {
        return *eventActionName_;
    }

    void DefineEventAction_Request::eventActionName(const ObjectName& vl) {
        eventActionName_ = vl;
    }

    void DefineEventAction_Request::eventActionName(boost::shared_ptr< ObjectName> vl) {
        eventActionName_ = vl;
    }

    boost::shared_ptr<DefineEventAction_Request::listOfModifier_type> DefineEventAction_Request::listOfModifier__new() {
        return listOfModifier_ = boost::shared_ptr<listOfModifier_type>(new listOfModifier_type());
    }

    void DefineEventAction_Request::listOfModifier(const listOfModifier_type& vl) {
        listOfModifier_ = boost::shared_ptr<listOfModifier_type>(new listOfModifier_type(vl));
    }

    ConfirmedServiceRequest& DefineEventAction_Request::confirmedServiceRequest() {
        return *confirmedServiceRequest_;
    }

    const ConfirmedServiceRequest& DefineEventAction_Request::confirmedServiceRequest() const {
        return *confirmedServiceRequest_;
    }

    void DefineEventAction_Request::confirmedServiceRequest(const ConfirmedServiceRequest& vl) {
        confirmedServiceRequest_ = vl;
    }

    void DefineEventAction_Request::confirmedServiceRequest(boost::shared_ptr< ConfirmedServiceRequest> vl) {
        confirmedServiceRequest_ = vl;
    }

    boost::shared_ptr<Request_Detail> DefineEventAction_Request::cs_extension__new() {
        return cs_extension_ = boost::shared_ptr<Request_Detail>(new Request_Detail());
    }

    void DefineEventAction_Request::cs_extension(const Request_Detail& vl) {
        cs_extension_ = boost::shared_ptr<Request_Detail>(new Request_Detail(vl));
    }


    // choice DeleteEventAction-Request

    void DeleteEventAction_Request::aa_specific(const null_type& vl) {
        set<null_type>(new null_type(vl), DeleteEventAction_Request_aa_specific);
    }

    void DeleteEventAction_Request::domain(const Identifier& vl) {
        set<Identifier>(new Identifier(vl), DeleteEventAction_Request_domain);
    }

    void DeleteEventAction_Request::vmd(const null_type& vl) {
        set<null_type>(new null_type(vl), DeleteEventAction_Request_vmd);
    }

    template<> void DeleteEventAction_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteEventAction_Request_specific:
            {
                ITU_T_IMPLICIT_TAG(value<specific_type > (false, DeleteEventAction_Request_specific), 0);
                break;
            }
            case DeleteEventAction_Request_aa_specific:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, DeleteEventAction_Request_aa_specific), 1);
                break;
            }
            case DeleteEventAction_Request_domain:
            {
                ITU_T_IMPLICIT_TAG(value<Identifier > (false, DeleteEventAction_Request_domain), 3);
                break;
            }
            case DeleteEventAction_Request_vmd:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, DeleteEventAction_Request_vmd), 4);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<specific_type > (true, DeleteEventAction_Request_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, DeleteEventAction_Request_aa_specific), 1)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Identifier > (true, DeleteEventAction_Request_domain), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, DeleteEventAction_Request_vmd), 4)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    GetEventActionAttributes_Response::GetEventActionAttributes_Response() : listOfModifier_(), confirmedServiceRequest_() {
    };

    GetEventActionAttributes_Response::GetEventActionAttributes_Response(const listOfModifier_type& arg__listOfModifier,
            const ConfirmedServiceRequest& arg__confirmedServiceRequest) :
    listOfModifier_(arg__listOfModifier),
    confirmedServiceRequest_(arg__confirmedServiceRequest) {
    };

    GetEventActionAttributes_Response::GetEventActionAttributes_Response(boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< listOfModifier_type> arg__listOfModifier,
            boost::shared_ptr< ConfirmedServiceRequest> arg__confirmedServiceRequest,
            boost::shared_ptr< Request_Detail> arg__cs_extension,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    listOfModifier_(arg__listOfModifier),
    confirmedServiceRequest_(arg__confirmedServiceRequest),
    cs_extension_(arg__cs_extension),
    accessControlList_(arg__accessControlList) {
    };

    const bool GetEventActionAttributes_Response::mmsDeletable__default = false;

    template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(listOfModifier_, 1);
        ITU_T_CHOICE_TAG(confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
    }

    template<> void GetEventActionAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(listOfModifier_, 1);
        ITU_T_CHOICE_TAG(confirmedServiceRequest_, 2);
        ITU_T_CHOICE_TAG(cs_extension_, 79);
        ITU_T_IMPLICIT_TAG(accessControlList_, 3);
    }

    const bool& GetEventActionAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetEventActionAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetEventActionAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    GetEventActionAttributes_Response::listOfModifier_type& GetEventActionAttributes_Response::listOfModifier() {
        return *listOfModifier_;
    }

    const GetEventActionAttributes_Response::listOfModifier_type& GetEventActionAttributes_Response::listOfModifier() const {
        return *listOfModifier_;
    }

    void GetEventActionAttributes_Response::listOfModifier(const listOfModifier_type& vl) {
        listOfModifier_ = vl;
    }

    void GetEventActionAttributes_Response::listOfModifier(boost::shared_ptr< listOfModifier_type> vl) {
        listOfModifier_ = vl;
    }

    ConfirmedServiceRequest& GetEventActionAttributes_Response::confirmedServiceRequest() {
        return *confirmedServiceRequest_;
    }

    const ConfirmedServiceRequest& GetEventActionAttributes_Response::confirmedServiceRequest() const {
        return *confirmedServiceRequest_;
    }

    void GetEventActionAttributes_Response::confirmedServiceRequest(const ConfirmedServiceRequest& vl) {
        confirmedServiceRequest_ = vl;
    }

    void GetEventActionAttributes_Response::confirmedServiceRequest(boost::shared_ptr< ConfirmedServiceRequest> vl) {
        confirmedServiceRequest_ = vl;
    }

    boost::shared_ptr<Request_Detail> GetEventActionAttributes_Response::cs_extension__new() {
        return cs_extension_ = boost::shared_ptr<Request_Detail>(new Request_Detail());
    }

    void GetEventActionAttributes_Response::cs_extension(const Request_Detail& vl) {
        cs_extension_ = boost::shared_ptr<Request_Detail>(new Request_Detail(vl));
    }

    boost::shared_ptr<Identifier> GetEventActionAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void GetEventActionAttributes_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


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

    DefineEventEnrollment_Request::DefineEventEnrollment_Request(boost::shared_ptr< ObjectName> arg__eventEnrollmentName,
            boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
            boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            boost::shared_ptr< ObjectName> arg__eventActionName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    eventConditionTransitions_(arg__eventConditionTransitions),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    eventActionName_(arg__eventActionName),
    clientApplication_(arg__clientApplication) {
    };

    template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 2);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 3);
        ITU_T_CHOICE_TAG(eventActionName_, 4);
        ITU_T_EXPLICIT_TAG(clientApplication_, 5);
    }

    template<> void DefineEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 2);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 3);
        ITU_T_CHOICE_TAG(eventActionName_, 4);
        ITU_T_EXPLICIT_TAG(clientApplication_, 5);
    }

    ObjectName& DefineEventEnrollment_Request::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& DefineEventEnrollment_Request::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void DefineEventEnrollment_Request::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void DefineEventEnrollment_Request::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    ObjectName& DefineEventEnrollment_Request::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& DefineEventEnrollment_Request::eventConditionName() const {
        return *eventConditionName_;
    }

    void DefineEventEnrollment_Request::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void DefineEventEnrollment_Request::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    MMS_Object_Module_1::Transitions& DefineEventEnrollment_Request::eventConditionTransitions() {
        return *eventConditionTransitions_;
    }

    const MMS_Object_Module_1::Transitions& DefineEventEnrollment_Request::eventConditionTransitions() const {
        return *eventConditionTransitions_;
    }

    void DefineEventEnrollment_Request::eventConditionTransitions(const MMS_Object_Module_1::Transitions& vl) {
        eventConditionTransitions_ = vl;
    }

    void DefineEventEnrollment_Request::eventConditionTransitions(boost::shared_ptr< MMS_Object_Module_1::Transitions> vl) {
        eventConditionTransitions_ = vl;
    }

    MMS_Object_Module_1::AlarmAckRule& DefineEventEnrollment_Request::alarmAcknowledgmentRule() {
        return *alarmAcknowledgmentRule_;
    }

    const MMS_Object_Module_1::AlarmAckRule& DefineEventEnrollment_Request::alarmAcknowledgmentRule() const {
        return *alarmAcknowledgmentRule_;
    }

    void DefineEventEnrollment_Request::alarmAcknowledgmentRule(const MMS_Object_Module_1::AlarmAckRule& vl) {
        alarmAcknowledgmentRule_ = vl;
    }

    void DefineEventEnrollment_Request::alarmAcknowledgmentRule(boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> vl) {
        alarmAcknowledgmentRule_ = vl;
    }

    boost::shared_ptr<ObjectName> DefineEventEnrollment_Request::eventActionName__new() {
        return eventActionName_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void DefineEventEnrollment_Request::eventActionName(const ObjectName& vl) {
        eventActionName_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> DefineEventEnrollment_Request::clientApplication__new() {
        return clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void DefineEventEnrollment_Request::clientApplication(const MMS_Environment_1::ApplicationReference& vl) {
        clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }


    // choice CS-DefineEventEnrollment-Request

    void CS_DefineEventEnrollment_Request_impl::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), CS_DefineEventEnrollment_Request_impl_string);
    }

    void CS_DefineEventEnrollment_Request_impl::index(const int& vl) {
        set<int>(new int(vl), CS_DefineEventEnrollment_Request_impl_index);
    }

    void CS_DefineEventEnrollment_Request_impl::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), CS_DefineEventEnrollment_Request_impl_noEnhancement);
    }

    template<> void CS_DefineEventEnrollment_Request_impl::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CS_DefineEventEnrollment_Request_impl_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, CS_DefineEventEnrollment_Request_impl_string), 0);
                break;
            }
            case CS_DefineEventEnrollment_Request_impl_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, CS_DefineEventEnrollment_Request_impl_index), 1);
                break;
            }
            case CS_DefineEventEnrollment_Request_impl_noEnhancement:
            {
                ITU_T_BIND_TAG(value<null_type > (false, CS_DefineEventEnrollment_Request_impl_noEnhancement));
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, CS_DefineEventEnrollment_Request_impl_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, CS_DefineEventEnrollment_Request_impl_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, CS_DefineEventEnrollment_Request_impl_noEnhancement))) return;
                else free();
            }
        }
    }


    // choice DeleteEventEnrollment-Request

    template<> void DeleteEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DeleteEventEnrollment_Request_specific:
            {
                ITU_T_IMPLICIT_TAG(value<specific_type > (false, DeleteEventEnrollment_Request_specific), 0);
                break;
            }
            case DeleteEventEnrollment_Request_ec:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, DeleteEventEnrollment_Request_ec), 1);
                break;
            }
            case DeleteEventEnrollment_Request_ea:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, DeleteEventEnrollment_Request_ea), 2);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<specific_type > (true, DeleteEventEnrollment_Request_specific), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, DeleteEventEnrollment_Request_ec), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, DeleteEventEnrollment_Request_ea), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_specific = 0;
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_client = 1;
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_ec = 2;
    const int GetEventEnrollmentAttributes_Request::scopeOfRequest_ea = 3;

    GetEventEnrollmentAttributes_Request::GetEventEnrollmentAttributes_Request() {
    };

    GetEventEnrollmentAttributes_Request::GetEventEnrollmentAttributes_Request(boost::shared_ptr< int> arg__scopeOfRequest,
            boost::shared_ptr< eventEnrollmentNames_type> arg__eventEnrollmentNames,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< ObjectName> arg__eventActionName,
            boost::shared_ptr< ObjectName> arg__continueAfter) :
    scopeOfRequest_(arg__scopeOfRequest),
    eventEnrollmentNames_(arg__eventEnrollmentNames),
    clientApplication_(arg__clientApplication),
    eventConditionName_(arg__eventConditionName),
    eventActionName_(arg__eventActionName),
    continueAfter_(arg__continueAfter) {
    };

    const int GetEventEnrollmentAttributes_Request::scopeOfRequest__default = 1;

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

    const int& GetEventEnrollmentAttributes_Request::scopeOfRequest() const {
        return *scopeOfRequest_;
    }

    void GetEventEnrollmentAttributes_Request::scopeOfRequest(const int& vl) {
        scopeOfRequest_ = vl;
    }

    void GetEventEnrollmentAttributes_Request::scopeOfRequest(boost::shared_ptr< int> vl) {
        scopeOfRequest_ = vl;
    }

    boost::shared_ptr<GetEventEnrollmentAttributes_Request::eventEnrollmentNames_type> GetEventEnrollmentAttributes_Request::eventEnrollmentNames__new() {
        return eventEnrollmentNames_ = boost::shared_ptr<eventEnrollmentNames_type>(new eventEnrollmentNames_type());
    }

    void GetEventEnrollmentAttributes_Request::eventEnrollmentNames(const eventEnrollmentNames_type& vl) {
        eventEnrollmentNames_ = boost::shared_ptr<eventEnrollmentNames_type>(new eventEnrollmentNames_type(vl));
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> GetEventEnrollmentAttributes_Request::clientApplication__new() {
        return clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void GetEventEnrollmentAttributes_Request::clientApplication(const MMS_Environment_1::ApplicationReference& vl) {
        clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }

    boost::shared_ptr<ObjectName> GetEventEnrollmentAttributes_Request::eventConditionName__new() {
        return eventConditionName_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void GetEventEnrollmentAttributes_Request::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }

    boost::shared_ptr<ObjectName> GetEventEnrollmentAttributes_Request::eventActionName__new() {
        return eventActionName_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void GetEventEnrollmentAttributes_Request::eventActionName(const ObjectName& vl) {
        eventActionName_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }

    boost::shared_ptr<ObjectName> GetEventEnrollmentAttributes_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName());
    }

    void GetEventEnrollmentAttributes_Request::continueAfter(const ObjectName& vl) {
        continueAfter_ = boost::shared_ptr<ObjectName>(new ObjectName(vl));
    }


    // sequence GetEventEnrollmentAttributes-Response

    GetEventEnrollmentAttributes_Response::GetEventEnrollmentAttributes_Response() : listOfEEAttributes_() {
    };

    GetEventEnrollmentAttributes_Response::GetEventEnrollmentAttributes_Response(const listOfEEAttributes_type& arg__listOfEEAttributes) :
    listOfEEAttributes_(arg__listOfEEAttributes) {
    };

    GetEventEnrollmentAttributes_Response::GetEventEnrollmentAttributes_Response(boost::shared_ptr< listOfEEAttributes_type> arg__listOfEEAttributes,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfEEAttributes_(arg__listOfEEAttributes),
    moreFollows_(arg__moreFollows) {
    };

    const bool GetEventEnrollmentAttributes_Response::moreFollows__default = false;

    template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfEEAttributes_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void GetEventEnrollmentAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfEEAttributes_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    GetEventEnrollmentAttributes_Response::listOfEEAttributes_type& GetEventEnrollmentAttributes_Response::listOfEEAttributes() {
        return *listOfEEAttributes_;
    }

    const GetEventEnrollmentAttributes_Response::listOfEEAttributes_type& GetEventEnrollmentAttributes_Response::listOfEEAttributes() const {
        return *listOfEEAttributes_;
    }

    void GetEventEnrollmentAttributes_Response::listOfEEAttributes(const listOfEEAttributes_type& vl) {
        listOfEEAttributes_ = vl;
    }

    void GetEventEnrollmentAttributes_Response::listOfEEAttributes(boost::shared_ptr< listOfEEAttributes_type> vl) {
        listOfEEAttributes_ = vl;
    }

    const bool& GetEventEnrollmentAttributes_Response::moreFollows() const {
        return *moreFollows_;
    }

    void GetEventEnrollmentAttributes_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void GetEventEnrollmentAttributes_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence EEAttributes

    EEAttributes::EEAttributes() : eventEnrollmentName_(), eventConditionName_(), enrollmentClass_(), displayEnhancement_() {
    };

    EEAttributes::EEAttributes(const ObjectName& arg__eventEnrollmentName,
            const eventConditionName_type& arg__eventConditionName,
            const MMS_Object_Module_1::EE_Class& arg__enrollmentClass,
            const displayEnhancement_type& arg__displayEnhancement) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionName_(arg__eventConditionName),
    enrollmentClass_(arg__enrollmentClass),
    displayEnhancement_(arg__displayEnhancement) {
    };

    EEAttributes::EEAttributes(boost::shared_ptr< ObjectName> arg__eventEnrollmentName,
            boost::shared_ptr< eventConditionName_type> arg__eventConditionName,
            boost::shared_ptr< eventActionName_type> arg__eventActionName,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< MMS_Object_Module_1::EE_Class> arg__enrollmentClass,
            boost::shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
            boost::shared_ptr< Unsigned32> arg__invokeID,
            boost::shared_ptr< Unsigned32> arg__remainingAcceptableDelay,
            boost::shared_ptr< displayEnhancement_type> arg__displayEnhancement) :
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

    void EEAttributes::eventConditionName_type::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), eventConditionName_type_undefined);
    }

    template<> void EEAttributes::eventConditionName_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case eventConditionName_type_eventCondition:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, eventConditionName_type_eventCondition), 0);
                break;
            }
            case eventConditionName_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, eventConditionName_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::eventConditionName_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, eventConditionName_type_eventCondition), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, eventConditionName_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void EEAttributes::eventActionName_type::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), eventActionName_type_undefined);
    }

    template<> void EEAttributes::eventActionName_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case eventActionName_type_eventAction:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, eventActionName_type_eventAction), 0);
                break;
            }
            case eventActionName_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, eventActionName_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::eventActionName_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, eventActionName_type_eventAction), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, eventActionName_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void EEAttributes::displayEnhancement_type::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), displayEnhancement_type_string);
    }

    void EEAttributes::displayEnhancement_type::index(const int& vl) {
        set<int>(new int(vl), displayEnhancement_type_index);
    }

    void EEAttributes::displayEnhancement_type::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), displayEnhancement_type_noEnhancement);
    }

    template<> void EEAttributes::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case displayEnhancement_type_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, displayEnhancement_type_string), 0);
                break;
            }
            case displayEnhancement_type_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, displayEnhancement_type_index), 1);
                break;
            }
            case displayEnhancement_type_noEnhancement:
            {
                ITU_T_BIND_TAG(value<null_type > (false, displayEnhancement_type_noEnhancement));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EEAttributes::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, displayEnhancement_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, displayEnhancement_type_index), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<null_type > (true, displayEnhancement_type_noEnhancement))) return;
                else free();
            }
        }
    }


    const bool EEAttributes::mmsDeletable__default = false;

    const MMS_Object_Module_1::EE_Duration EEAttributes::duration__default = MMS_Object_Module_1::EE_Duration(0);

    template<> void EEAttributes::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_CHOICE_TAG(eventActionName_, 2);
        ITU_T_EXPLICIT_TAG(clientApplication_, 3);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 4);
        ITU_T_IMPLICIT_TAG(enrollmentClass_, 5);
        ITU_T_IMPLICIT_TAG(duration_, 6);
        ITU_T_IMPLICIT_TAG(invokeID_, 7);
        ITU_T_IMPLICIT_TAG(remainingAcceptableDelay_, 8);
        ITU_T_CHOICE_TAG(displayEnhancement_, 9);
    }

    template<> void EEAttributes::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_CHOICE_TAG(eventConditionName_, 1);
        ITU_T_CHOICE_TAG(eventActionName_, 2);
        ITU_T_EXPLICIT_TAG(clientApplication_, 3);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 4);
        ITU_T_IMPLICIT_TAG(enrollmentClass_, 5);
        ITU_T_IMPLICIT_TAG(duration_, 6);
        ITU_T_IMPLICIT_TAG(invokeID_, 7);
        ITU_T_IMPLICIT_TAG(remainingAcceptableDelay_, 8);
        ITU_T_CHOICE_TAG(displayEnhancement_, 9);
    }

    ObjectName& EEAttributes::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& EEAttributes::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void EEAttributes::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void EEAttributes::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    EEAttributes::eventConditionName_type& EEAttributes::eventConditionName() {
        return *eventConditionName_;
    }

    const EEAttributes::eventConditionName_type& EEAttributes::eventConditionName() const {
        return *eventConditionName_;
    }

    void EEAttributes::eventConditionName(const eventConditionName_type& vl) {
        eventConditionName_ = vl;
    }

    void EEAttributes::eventConditionName(boost::shared_ptr< eventConditionName_type> vl) {
        eventConditionName_ = vl;
    }

    boost::shared_ptr<EEAttributes::eventActionName_type> EEAttributes::eventActionName__new() {
        return eventActionName_ = boost::shared_ptr<eventActionName_type>(new eventActionName_type());
    }

    void EEAttributes::eventActionName(const eventActionName_type& vl) {
        eventActionName_ = boost::shared_ptr<eventActionName_type>(new eventActionName_type(vl));
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> EEAttributes::clientApplication__new() {
        return clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void EEAttributes::clientApplication(const MMS_Environment_1::ApplicationReference& vl) {
        clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }

    const bool& EEAttributes::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void EEAttributes::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void EEAttributes::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    MMS_Object_Module_1::EE_Class& EEAttributes::enrollmentClass() {
        return *enrollmentClass_;
    }

    const MMS_Object_Module_1::EE_Class& EEAttributes::enrollmentClass() const {
        return *enrollmentClass_;
    }

    void EEAttributes::enrollmentClass(const MMS_Object_Module_1::EE_Class& vl) {
        enrollmentClass_ = vl;
    }

    void EEAttributes::enrollmentClass(boost::shared_ptr< MMS_Object_Module_1::EE_Class> vl) {
        enrollmentClass_ = vl;
    }

    const MMS_Object_Module_1::EE_Duration& EEAttributes::duration() const {
        return *duration_;
    }

    void EEAttributes::duration(const MMS_Object_Module_1::EE_Duration& vl) {
        duration_ = vl;
    }

    void EEAttributes::duration(boost::shared_ptr< MMS_Object_Module_1::EE_Duration> vl) {
        duration_ = vl;
    }

    boost::shared_ptr<Unsigned32> EEAttributes::invokeID__new() {
        return invokeID_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void EEAttributes::invokeID(const Unsigned32& vl) {
        invokeID_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    boost::shared_ptr<Unsigned32> EEAttributes::remainingAcceptableDelay__new() {
        return remainingAcceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32());
    }

    void EEAttributes::remainingAcceptableDelay(const Unsigned32& vl) {
        remainingAcceptableDelay_ = boost::shared_ptr<Unsigned32>(new Unsigned32(vl));
    }

    EEAttributes::displayEnhancement_type& EEAttributes::displayEnhancement() {
        return *displayEnhancement_;
    }

    const EEAttributes::displayEnhancement_type& EEAttributes::displayEnhancement() const {
        return *displayEnhancement_;
    }

    void EEAttributes::displayEnhancement(const displayEnhancement_type& vl) {
        displayEnhancement_ = vl;
    }

    void EEAttributes::displayEnhancement(boost::shared_ptr< displayEnhancement_type> vl) {
        displayEnhancement_ = vl;
    }


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

    ReportEventEnrollmentStatus_Response::ReportEventEnrollmentStatus_Response(boost::shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
            boost::shared_ptr< bool> arg__notificationLost,
            boost::shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
            boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule,
            boost::shared_ptr< EE_State> arg__currentState) :
    eventConditionTransitions_(arg__eventConditionTransitions),
    notificationLost_(arg__notificationLost),
    duration_(arg__duration),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule),
    currentState_(arg__currentState) {
    };

    const bool ReportEventEnrollmentStatus_Response::notificationLost__default = false;

    template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 0);
        ITU_T_IMPLICIT_TAG(notificationLost_, 1);
        ITU_T_IMPLICIT_TAG(duration_, 2);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 3);
        ITU_T_IMPLICIT_TAG(currentState_, 4);
    }

    template<> void ReportEventEnrollmentStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 0);
        ITU_T_IMPLICIT_TAG(notificationLost_, 1);
        ITU_T_IMPLICIT_TAG(duration_, 2);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 3);
        ITU_T_IMPLICIT_TAG(currentState_, 4);
    }

    MMS_Object_Module_1::Transitions& ReportEventEnrollmentStatus_Response::eventConditionTransitions() {
        return *eventConditionTransitions_;
    }

    const MMS_Object_Module_1::Transitions& ReportEventEnrollmentStatus_Response::eventConditionTransitions() const {
        return *eventConditionTransitions_;
    }

    void ReportEventEnrollmentStatus_Response::eventConditionTransitions(const MMS_Object_Module_1::Transitions& vl) {
        eventConditionTransitions_ = vl;
    }

    void ReportEventEnrollmentStatus_Response::eventConditionTransitions(boost::shared_ptr< MMS_Object_Module_1::Transitions> vl) {
        eventConditionTransitions_ = vl;
    }

    const bool& ReportEventEnrollmentStatus_Response::notificationLost() const {
        return *notificationLost_;
    }

    void ReportEventEnrollmentStatus_Response::notificationLost(const bool& vl) {
        notificationLost_ = vl;
    }

    void ReportEventEnrollmentStatus_Response::notificationLost(boost::shared_ptr< bool> vl) {
        notificationLost_ = vl;
    }

    MMS_Object_Module_1::EE_Duration& ReportEventEnrollmentStatus_Response::duration() {
        return *duration_;
    }

    const MMS_Object_Module_1::EE_Duration& ReportEventEnrollmentStatus_Response::duration() const {
        return *duration_;
    }

    void ReportEventEnrollmentStatus_Response::duration(const MMS_Object_Module_1::EE_Duration& vl) {
        duration_ = vl;
    }

    void ReportEventEnrollmentStatus_Response::duration(boost::shared_ptr< MMS_Object_Module_1::EE_Duration> vl) {
        duration_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> ReportEventEnrollmentStatus_Response::alarmAcknowledgmentRule__new() {
        return alarmAcknowledgmentRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule());
    }

    void ReportEventEnrollmentStatus_Response::alarmAcknowledgmentRule(const MMS_Object_Module_1::AlarmAckRule& vl) {
        alarmAcknowledgmentRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule(vl));
    }

    EE_State& ReportEventEnrollmentStatus_Response::currentState() {
        return *currentState_;
    }

    const EE_State& ReportEventEnrollmentStatus_Response::currentState() const {
        return *currentState_;
    }

    void ReportEventEnrollmentStatus_Response::currentState(const EE_State& vl) {
        currentState_ = vl;
    }

    void ReportEventEnrollmentStatus_Response::currentState(boost::shared_ptr< EE_State> vl) {
        currentState_ = vl;
    }


    // sequence AlterEventEnrollment-Request

    AlterEventEnrollment_Request::AlterEventEnrollment_Request() : eventEnrollmentName_() {
    };

    AlterEventEnrollment_Request::AlterEventEnrollment_Request(const ObjectName& arg__eventEnrollmentName) :
    eventEnrollmentName_(arg__eventEnrollmentName) {
    };

    AlterEventEnrollment_Request::AlterEventEnrollment_Request(boost::shared_ptr< ObjectName> arg__eventEnrollmentName,
            boost::shared_ptr< MMS_Object_Module_1::Transitions> arg__eventConditionTransitions,
            boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__alarmAcknowledgmentRule) :
    eventEnrollmentName_(arg__eventEnrollmentName),
    eventConditionTransitions_(arg__eventConditionTransitions),
    alarmAcknowledgmentRule_(arg__alarmAcknowledgmentRule) {
    };

    template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 1);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 2);
    }

    template<> void AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventEnrollmentName_, 0);
        ITU_T_IMPLICIT_TAG(eventConditionTransitions_, 1);
        ITU_T_IMPLICIT_TAG(alarmAcknowledgmentRule_, 2);
    }

    ObjectName& AlterEventEnrollment_Request::eventEnrollmentName() {
        return *eventEnrollmentName_;
    }

    const ObjectName& AlterEventEnrollment_Request::eventEnrollmentName() const {
        return *eventEnrollmentName_;
    }

    void AlterEventEnrollment_Request::eventEnrollmentName(const ObjectName& vl) {
        eventEnrollmentName_ = vl;
    }

    void AlterEventEnrollment_Request::eventEnrollmentName(boost::shared_ptr< ObjectName> vl) {
        eventEnrollmentName_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::Transitions> AlterEventEnrollment_Request::eventConditionTransitions__new() {
        return eventConditionTransitions_ = boost::shared_ptr<MMS_Object_Module_1::Transitions>(new MMS_Object_Module_1::Transitions());
    }

    void AlterEventEnrollment_Request::eventConditionTransitions(const MMS_Object_Module_1::Transitions& vl) {
        eventConditionTransitions_ = boost::shared_ptr<MMS_Object_Module_1::Transitions>(new MMS_Object_Module_1::Transitions(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> AlterEventEnrollment_Request::alarmAcknowledgmentRule__new() {
        return alarmAcknowledgmentRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule());
    }

    void AlterEventEnrollment_Request::alarmAcknowledgmentRule(const MMS_Object_Module_1::AlarmAckRule& vl) {
        alarmAcknowledgmentRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule(vl));
    }


    // sequence AlterEventEnrollment-Response

    AlterEventEnrollment_Response::AlterEventEnrollment_Response() : currentState_(), transitionTime_() {
    };

    AlterEventEnrollment_Response::AlterEventEnrollment_Response(const currentState_type& arg__currentState,
            const MMS_Object_Module_1::EventTime& arg__transitionTime) :
    currentState_(arg__currentState),
    transitionTime_(arg__transitionTime) {
    };

    void AlterEventEnrollment_Response::currentState_type::state(const EE_State& vl) {
        set<EE_State>(new EE_State(vl), currentState_type_state);
    }

    void AlterEventEnrollment_Response::currentState_type::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), currentState_type_undefined);
    }

    template<> void AlterEventEnrollment_Response::currentState_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case currentState_type_state:
            {
                ITU_T_IMPLICIT_TAG(value<EE_State > (false, currentState_type_state), 0);
                break;
            }
            case currentState_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, currentState_type_undefined), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlterEventEnrollment_Response::currentState_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<EE_State > (true, currentState_type_state), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, currentState_type_undefined), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(currentState_, 0);
        ITU_T_CHOICE_TAG(transitionTime_, 1);
    }

    template<> void AlterEventEnrollment_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(currentState_, 0);
        ITU_T_CHOICE_TAG(transitionTime_, 1);
    }

    AlterEventEnrollment_Response::currentState_type& AlterEventEnrollment_Response::currentState() {
        return *currentState_;
    }

    const AlterEventEnrollment_Response::currentState_type& AlterEventEnrollment_Response::currentState() const {
        return *currentState_;
    }

    void AlterEventEnrollment_Response::currentState(const currentState_type& vl) {
        currentState_ = vl;
    }

    void AlterEventEnrollment_Response::currentState(boost::shared_ptr< currentState_type> vl) {
        currentState_ = vl;
    }

    MMS_Object_Module_1::EventTime& AlterEventEnrollment_Response::transitionTime() {
        return *transitionTime_;
    }

    const MMS_Object_Module_1::EventTime& AlterEventEnrollment_Response::transitionTime() const {
        return *transitionTime_;
    }

    void AlterEventEnrollment_Response::transitionTime(const MMS_Object_Module_1::EventTime& vl) {
        transitionTime_ = vl;
    }

    void AlterEventEnrollment_Response::transitionTime(boost::shared_ptr< MMS_Object_Module_1::EventTime> vl) {
        transitionTime_ = vl;
    }


    // sequence CS-AlterEventEnrollment-Request

    CS_AlterEventEnrollment_Request::CS_AlterEventEnrollment_Request() {
    };

    CS_AlterEventEnrollment_Request::CS_AlterEventEnrollment_Request(boost::shared_ptr< changeDisplay_type> arg__changeDisplay) :
    changeDisplay_(arg__changeDisplay) {
    };

    void CS_AlterEventEnrollment_Request::changeDisplay_type::string(const visiblestring_type& vl) {
        set<visiblestring_type>(new visiblestring_type(vl), changeDisplay_type_string);
    }

    void CS_AlterEventEnrollment_Request::changeDisplay_type::index(const int& vl) {
        set<int>(new int(vl), changeDisplay_type_index);
    }

    void CS_AlterEventEnrollment_Request::changeDisplay_type::noEnhancement(const null_type& vl) {
        set<null_type>(new null_type(vl), changeDisplay_type_noEnhancement);
    }

    template<> void CS_AlterEventEnrollment_Request::changeDisplay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case changeDisplay_type_string:
            {
                ITU_T_IMPLICIT_TAG(value<visiblestring_type > (false, changeDisplay_type_string), 0);
                break;
            }
            case changeDisplay_type_index:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, changeDisplay_type_index), 1);
                break;
            }
            case changeDisplay_type_noEnhancement:
            {
                ITU_T_EXPLICIT_TAG(value<null_type > (false, changeDisplay_type_noEnhancement), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CS_AlterEventEnrollment_Request::changeDisplay_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<visiblestring_type > (true, changeDisplay_type_string), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, changeDisplay_type_index), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<null_type > (true, changeDisplay_type_noEnhancement), 2)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    template<> void CS_AlterEventEnrollment_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE(changeDisplay_);
    }

    boost::shared_ptr<CS_AlterEventEnrollment_Request::changeDisplay_type> CS_AlterEventEnrollment_Request::changeDisplay__new() {
        return changeDisplay_ = boost::shared_ptr<changeDisplay_type>(new changeDisplay_type());
    }

    void CS_AlterEventEnrollment_Request::changeDisplay(const changeDisplay_type& vl) {
        changeDisplay_ = boost::shared_ptr<changeDisplay_type>(new changeDisplay_type(vl));
    }


    const EE_State EE_State_disabled = 0;
    const EE_State EE_State_idle = 1;
    const EE_State EE_State_active = 2;
    const EE_State EE_State_activeNoAckA = 3;
    const EE_State EE_State_idleNoAckI = 4;
    const EE_State EE_State_idleNoAckA = 5;
    const EE_State EE_State_idleAcked = 6;
    const EE_State EE_State_activeAcked = 7;
    const EE_State EE_State_undefined = 8;

    // sequence DefineEventConditionList-Request

    DefineEventConditionList_Request::DefineEventConditionList_Request() : eventConditionListName_(), listOfEventConditionName_() {
    };

    DefineEventConditionList_Request::DefineEventConditionList_Request(const ObjectName& arg__eventConditionListName,
            const listOfEventConditionName_type& arg__listOfEventConditionName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName) {
    };

    DefineEventConditionList_Request::DefineEventConditionList_Request(boost::shared_ptr< ObjectName> arg__eventConditionListName,
            boost::shared_ptr< listOfEventConditionName_type> arg__listOfEventConditionName,
            boost::shared_ptr< listOfEventConditionListName_type> arg__listOfEventConditionListName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };

    template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void DefineEventConditionList_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    ObjectName& DefineEventConditionList_Request::eventConditionListName() {
        return *eventConditionListName_;
    }

    const ObjectName& DefineEventConditionList_Request::eventConditionListName() const {
        return *eventConditionListName_;
    }

    void DefineEventConditionList_Request::eventConditionListName(const ObjectName& vl) {
        eventConditionListName_ = vl;
    }

    void DefineEventConditionList_Request::eventConditionListName(boost::shared_ptr< ObjectName> vl) {
        eventConditionListName_ = vl;
    }

    DefineEventConditionList_Request::listOfEventConditionName_type& DefineEventConditionList_Request::listOfEventConditionName() {
        return *listOfEventConditionName_;
    }

    const DefineEventConditionList_Request::listOfEventConditionName_type& DefineEventConditionList_Request::listOfEventConditionName() const {
        return *listOfEventConditionName_;
    }

    void DefineEventConditionList_Request::listOfEventConditionName(const listOfEventConditionName_type& vl) {
        listOfEventConditionName_ = vl;
    }

    void DefineEventConditionList_Request::listOfEventConditionName(boost::shared_ptr< listOfEventConditionName_type> vl) {
        listOfEventConditionName_ = vl;
    }

    boost::shared_ptr<DefineEventConditionList_Request::listOfEventConditionListName_type> DefineEventConditionList_Request::listOfEventConditionListName__new() {
        return listOfEventConditionListName_ = boost::shared_ptr<listOfEventConditionListName_type>(new listOfEventConditionListName_type());
    }

    void DefineEventConditionList_Request::listOfEventConditionListName(const listOfEventConditionListName_type& vl) {
        listOfEventConditionListName_ = boost::shared_ptr<listOfEventConditionListName_type>(new listOfEventConditionListName_type(vl));
    }


    // sequence AddEventConditionListReference-Request

    AddEventConditionListReference_Request::AddEventConditionListReference_Request() : eventConditionListName_(), listOfEventConditionName_() {
    };

    AddEventConditionListReference_Request::AddEventConditionListReference_Request(const ObjectName& arg__eventConditionListName,
            const listOfEventConditionName_type& arg__listOfEventConditionName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName) {
    };

    AddEventConditionListReference_Request::AddEventConditionListReference_Request(boost::shared_ptr< ObjectName> arg__eventConditionListName,
            boost::shared_ptr< listOfEventConditionName_type> arg__listOfEventConditionName,
            boost::shared_ptr< listOfEventConditionListName_type> arg__listOfEventConditionListName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };

    template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void AddEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    ObjectName& AddEventConditionListReference_Request::eventConditionListName() {
        return *eventConditionListName_;
    }

    const ObjectName& AddEventConditionListReference_Request::eventConditionListName() const {
        return *eventConditionListName_;
    }

    void AddEventConditionListReference_Request::eventConditionListName(const ObjectName& vl) {
        eventConditionListName_ = vl;
    }

    void AddEventConditionListReference_Request::eventConditionListName(boost::shared_ptr< ObjectName> vl) {
        eventConditionListName_ = vl;
    }

    AddEventConditionListReference_Request::listOfEventConditionName_type& AddEventConditionListReference_Request::listOfEventConditionName() {
        return *listOfEventConditionName_;
    }

    const AddEventConditionListReference_Request::listOfEventConditionName_type& AddEventConditionListReference_Request::listOfEventConditionName() const {
        return *listOfEventConditionName_;
    }

    void AddEventConditionListReference_Request::listOfEventConditionName(const listOfEventConditionName_type& vl) {
        listOfEventConditionName_ = vl;
    }

    void AddEventConditionListReference_Request::listOfEventConditionName(boost::shared_ptr< listOfEventConditionName_type> vl) {
        listOfEventConditionName_ = vl;
    }

    boost::shared_ptr<AddEventConditionListReference_Request::listOfEventConditionListName_type> AddEventConditionListReference_Request::listOfEventConditionListName__new() {
        return listOfEventConditionListName_ = boost::shared_ptr<listOfEventConditionListName_type>(new listOfEventConditionListName_type());
    }

    void AddEventConditionListReference_Request::listOfEventConditionListName(const listOfEventConditionListName_type& vl) {
        listOfEventConditionListName_ = boost::shared_ptr<listOfEventConditionListName_type>(new listOfEventConditionListName_type(vl));
    }


    // sequence RemoveEventConditionListReference-Request

    RemoveEventConditionListReference_Request::RemoveEventConditionListReference_Request() : eventConditionListName_(), listOfEventConditionName_(), listOfEventConditionListName_() {
    };

    RemoveEventConditionListReference_Request::RemoveEventConditionListReference_Request(const ObjectName& arg__eventConditionListName,
            const listOfEventConditionName_type& arg__listOfEventConditionName,
            const listOfEventConditionListName_type& arg__listOfEventConditionListName) :
    eventConditionListName_(arg__eventConditionListName),
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };

    template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void RemoveEventConditionListReference_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    ObjectName& RemoveEventConditionListReference_Request::eventConditionListName() {
        return *eventConditionListName_;
    }

    const ObjectName& RemoveEventConditionListReference_Request::eventConditionListName() const {
        return *eventConditionListName_;
    }

    void RemoveEventConditionListReference_Request::eventConditionListName(const ObjectName& vl) {
        eventConditionListName_ = vl;
    }

    void RemoveEventConditionListReference_Request::eventConditionListName(boost::shared_ptr< ObjectName> vl) {
        eventConditionListName_ = vl;
    }

    RemoveEventConditionListReference_Request::listOfEventConditionName_type& RemoveEventConditionListReference_Request::listOfEventConditionName() {
        return *listOfEventConditionName_;
    }

    const RemoveEventConditionListReference_Request::listOfEventConditionName_type& RemoveEventConditionListReference_Request::listOfEventConditionName() const {
        return *listOfEventConditionName_;
    }

    void RemoveEventConditionListReference_Request::listOfEventConditionName(const listOfEventConditionName_type& vl) {
        listOfEventConditionName_ = vl;
    }

    void RemoveEventConditionListReference_Request::listOfEventConditionName(boost::shared_ptr< listOfEventConditionName_type> vl) {
        listOfEventConditionName_ = vl;
    }

    RemoveEventConditionListReference_Request::listOfEventConditionListName_type& RemoveEventConditionListReference_Request::listOfEventConditionListName() {
        return *listOfEventConditionListName_;
    }

    const RemoveEventConditionListReference_Request::listOfEventConditionListName_type& RemoveEventConditionListReference_Request::listOfEventConditionListName() const {
        return *listOfEventConditionListName_;
    }

    void RemoveEventConditionListReference_Request::listOfEventConditionListName(const listOfEventConditionListName_type& vl) {
        listOfEventConditionListName_ = vl;
    }

    void RemoveEventConditionListReference_Request::listOfEventConditionListName(boost::shared_ptr< listOfEventConditionListName_type> vl) {
        listOfEventConditionListName_ = vl;
    }


    // choice RemoveEventConditionListReference-Error

    template<> void RemoveEventConditionListReference_Error::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RemoveEventConditionListReference_Error_eventCondition:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, RemoveEventConditionListReference_Error_eventCondition), 0);
                break;
            }
            case RemoveEventConditionListReference_Error_eventConditionList:
            {
                ITU_T_CHOICE_TAG(value<ObjectName > (false, RemoveEventConditionListReference_Error_eventConditionList), 1);
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
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, RemoveEventConditionListReference_Error_eventCondition), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_CHOICE_TAG(value<ObjectName > (true, RemoveEventConditionListReference_Error_eventConditionList), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    GetEventConditionListAttributes_Response::GetEventConditionListAttributes_Response() : listOfEventConditionName_() {
    };

    GetEventConditionListAttributes_Response::GetEventConditionListAttributes_Response(const listOfEventConditionName_type& arg__listOfEventConditionName) :
    listOfEventConditionName_(arg__listOfEventConditionName) {
    };

    GetEventConditionListAttributes_Response::GetEventConditionListAttributes_Response(boost::shared_ptr< listOfEventConditionName_type> arg__listOfEventConditionName,
            boost::shared_ptr< listOfEventConditionListName_type> arg__listOfEventConditionListName) :
    listOfEventConditionName_(arg__listOfEventConditionName),
    listOfEventConditionListName_(arg__listOfEventConditionListName) {
    };

    template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    template<> void GetEventConditionListAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfEventConditionName_, 1);
        ITU_T_IMPLICIT_TAG(listOfEventConditionListName_, 2);
    }

    GetEventConditionListAttributes_Response::listOfEventConditionName_type& GetEventConditionListAttributes_Response::listOfEventConditionName() {
        return *listOfEventConditionName_;
    }

    const GetEventConditionListAttributes_Response::listOfEventConditionName_type& GetEventConditionListAttributes_Response::listOfEventConditionName() const {
        return *listOfEventConditionName_;
    }

    void GetEventConditionListAttributes_Response::listOfEventConditionName(const listOfEventConditionName_type& vl) {
        listOfEventConditionName_ = vl;
    }

    void GetEventConditionListAttributes_Response::listOfEventConditionName(boost::shared_ptr< listOfEventConditionName_type> vl) {
        listOfEventConditionName_ = vl;
    }

    boost::shared_ptr<GetEventConditionListAttributes_Response::listOfEventConditionListName_type> GetEventConditionListAttributes_Response::listOfEventConditionListName__new() {
        return listOfEventConditionListName_ = boost::shared_ptr<listOfEventConditionListName_type>(new listOfEventConditionListName_type());
    }

    void GetEventConditionListAttributes_Response::listOfEventConditionListName(const listOfEventConditionListName_type& vl) {
        listOfEventConditionListName_ = boost::shared_ptr<listOfEventConditionListName_type>(new listOfEventConditionListName_type(vl));
    }


    // sequence ReportEventConditionListStatus-Request

    ReportEventConditionListStatus_Request::ReportEventConditionListStatus_Request() : eventConditionListName_() {
    };

    ReportEventConditionListStatus_Request::ReportEventConditionListStatus_Request(const ObjectName& arg__eventConditionListName) :
    eventConditionListName_(arg__eventConditionListName) {
    };

    ReportEventConditionListStatus_Request::ReportEventConditionListStatus_Request(boost::shared_ptr< ObjectName> arg__eventConditionListName,
            boost::shared_ptr< Identifier> arg__continueAfter) :
    eventConditionListName_(arg__eventConditionListName),
    continueAfter_(arg__continueAfter) {
    };

    template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(continueAfter_, 1);
    }

    template<> void ReportEventConditionListStatus_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(continueAfter_, 1);
    }

    ObjectName& ReportEventConditionListStatus_Request::eventConditionListName() {
        return *eventConditionListName_;
    }

    const ObjectName& ReportEventConditionListStatus_Request::eventConditionListName() const {
        return *eventConditionListName_;
    }

    void ReportEventConditionListStatus_Request::eventConditionListName(const ObjectName& vl) {
        eventConditionListName_ = vl;
    }

    void ReportEventConditionListStatus_Request::eventConditionListName(boost::shared_ptr< ObjectName> vl) {
        eventConditionListName_ = vl;
    }

    boost::shared_ptr<Identifier> ReportEventConditionListStatus_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void ReportEventConditionListStatus_Request::continueAfter(const Identifier& vl) {
        continueAfter_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence ReportEventConditionListStatus-Response

    ReportEventConditionListStatus_Response::ReportEventConditionListStatus_Response() : listOfEventConditionStatus_() {
    };

    ReportEventConditionListStatus_Response::ReportEventConditionListStatus_Response(const listOfEventConditionStatus_type& arg__listOfEventConditionStatus) :
    listOfEventConditionStatus_(arg__listOfEventConditionStatus) {
    };

    ReportEventConditionListStatus_Response::ReportEventConditionListStatus_Response(boost::shared_ptr< listOfEventConditionStatus_type> arg__listOfEventConditionStatus,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfEventConditionStatus_(arg__listOfEventConditionStatus),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReportEventConditionListStatus_Response::moreFollows__default = true;

    template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfEventConditionStatus_, 1);
        ITU_T_IMPLICIT_TAG(moreFollows_, 2);
    }

    template<> void ReportEventConditionListStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfEventConditionStatus_, 1);
        ITU_T_IMPLICIT_TAG(moreFollows_, 2);
    }

    ReportEventConditionListStatus_Response::listOfEventConditionStatus_type& ReportEventConditionListStatus_Response::listOfEventConditionStatus() {
        return *listOfEventConditionStatus_;
    }

    const ReportEventConditionListStatus_Response::listOfEventConditionStatus_type& ReportEventConditionListStatus_Response::listOfEventConditionStatus() const {
        return *listOfEventConditionStatus_;
    }

    void ReportEventConditionListStatus_Response::listOfEventConditionStatus(const listOfEventConditionStatus_type& vl) {
        listOfEventConditionStatus_ = vl;
    }

    void ReportEventConditionListStatus_Response::listOfEventConditionStatus(boost::shared_ptr< listOfEventConditionStatus_type> vl) {
        listOfEventConditionStatus_ = vl;
    }

    const bool& ReportEventConditionListStatus_Response::moreFollows() const {
        return *moreFollows_;
    }

    void ReportEventConditionListStatus_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void ReportEventConditionListStatus_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


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

    EventConditionStatus::EventConditionStatus(boost::shared_ptr< ObjectName> arg__eventConditionName,
            boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__currentState,
            boost::shared_ptr< Unsigned32> arg__numberOfEventEnrollments,
            boost::shared_ptr< bool> arg__enabled,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToActive,
            boost::shared_ptr< MMS_Object_Module_1::EventTime> arg__timeOfLastTransitionToIdle) :
    eventConditionName_(arg__eventConditionName),
    currentState_(arg__currentState),
    numberOfEventEnrollments_(arg__numberOfEventEnrollments),
    enabled_(arg__enabled),
    timeOfLastTransitionToActive_(arg__timeOfLastTransitionToActive),
    timeOfLastTransitionToIdle_(arg__timeOfLastTransitionToIdle) {
    };

    template<> void EventConditionStatus::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(currentState_, 1);
        ITU_T_IMPLICIT_TAG(numberOfEventEnrollments_, 2);
        ITU_T_IMPLICIT_TAG(enabled_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 5);
    }

    template<> void EventConditionStatus::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(currentState_, 1);
        ITU_T_IMPLICIT_TAG(numberOfEventEnrollments_, 2);
        ITU_T_IMPLICIT_TAG(enabled_, 3);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToActive_, 4);
        ITU_T_CHOICE_TAG(timeOfLastTransitionToIdle_, 5);
    }

    ObjectName& EventConditionStatus::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& EventConditionStatus::eventConditionName() const {
        return *eventConditionName_;
    }

    void EventConditionStatus::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void EventConditionStatus::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    MMS_Object_Module_1::EC_State& EventConditionStatus::currentState() {
        return *currentState_;
    }

    const MMS_Object_Module_1::EC_State& EventConditionStatus::currentState() const {
        return *currentState_;
    }

    void EventConditionStatus::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = vl;
    }

    void EventConditionStatus::currentState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        currentState_ = vl;
    }

    Unsigned32& EventConditionStatus::numberOfEventEnrollments() {
        return *numberOfEventEnrollments_;
    }

    const Unsigned32& EventConditionStatus::numberOfEventEnrollments() const {
        return *numberOfEventEnrollments_;
    }

    void EventConditionStatus::numberOfEventEnrollments(const Unsigned32& vl) {
        numberOfEventEnrollments_ = vl;
    }

    void EventConditionStatus::numberOfEventEnrollments(boost::shared_ptr< Unsigned32> vl) {
        numberOfEventEnrollments_ = vl;
    }

    boost::shared_ptr<bool> EventConditionStatus::enabled__new() {
        return enabled_ = boost::shared_ptr<bool>(new bool());
    }

    void EventConditionStatus::enabled(const bool& vl) {
        enabled_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> EventConditionStatus::timeOfLastTransitionToActive__new() {
        return timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void EventConditionStatus::timeOfLastTransitionToActive(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToActive_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EventTime> EventConditionStatus::timeOfLastTransitionToIdle__new() {
        return timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime());
    }

    void EventConditionStatus::timeOfLastTransitionToIdle(const MMS_Object_Module_1::EventTime& vl) {
        timeOfLastTransitionToIdle_ = boost::shared_ptr<MMS_Object_Module_1::EventTime>(new MMS_Object_Module_1::EventTime(vl));
    }


    // sequence AlterEventConditionListMonitoring-Request

    AlterEventConditionListMonitoring_Request::AlterEventConditionListMonitoring_Request() : eventConditionListName_(), enabled_() {
    };

    AlterEventConditionListMonitoring_Request::AlterEventConditionListMonitoring_Request(const ObjectName& arg__eventConditionListName,
            const bool& arg__enabled) :
    eventConditionListName_(arg__eventConditionListName),
    enabled_(arg__enabled) {
    };

    AlterEventConditionListMonitoring_Request::AlterEventConditionListMonitoring_Request(boost::shared_ptr< ObjectName> arg__eventConditionListName,
            boost::shared_ptr< bool> arg__enabled,
            boost::shared_ptr< priorityChange_type> arg__priorityChange) :
    eventConditionListName_(arg__eventConditionListName),
    enabled_(arg__enabled),
    priorityChange_(arg__priorityChange) {
    };

    void AlterEventConditionListMonitoring_Request::priorityChange_type::priorityValue(const int& vl) {
        set<int>(new int(vl), priorityChange_type_priorityValue);
    }

    void AlterEventConditionListMonitoring_Request::priorityChange_type::priorityReset(const null_type& vl) {
        set<null_type>(new null_type(vl), priorityChange_type_priorityReset);
    }

    template<> void AlterEventConditionListMonitoring_Request::priorityChange_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case priorityChange_type_priorityValue:
            {
                ITU_T_IMPLICIT_TAG(value<int > (false, priorityChange_type_priorityValue), 0);
                break;
            }
            case priorityChange_type_priorityReset:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, priorityChange_type_priorityReset), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AlterEventConditionListMonitoring_Request::priorityChange_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<int > (true, priorityChange_type_priorityValue), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, priorityChange_type_priorityReset), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(enabled_, 1);
        ITU_T_CHOICE_TAG(priorityChange_, 2);
    }

    template<> void AlterEventConditionListMonitoring_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionListName_, 0);
        ITU_T_IMPLICIT_TAG(enabled_, 1);
        ITU_T_CHOICE_TAG(priorityChange_, 2);
    }

    ObjectName& AlterEventConditionListMonitoring_Request::eventConditionListName() {
        return *eventConditionListName_;
    }

    const ObjectName& AlterEventConditionListMonitoring_Request::eventConditionListName() const {
        return *eventConditionListName_;
    }

    void AlterEventConditionListMonitoring_Request::eventConditionListName(const ObjectName& vl) {
        eventConditionListName_ = vl;
    }

    void AlterEventConditionListMonitoring_Request::eventConditionListName(boost::shared_ptr< ObjectName> vl) {
        eventConditionListName_ = vl;
    }

    bool& AlterEventConditionListMonitoring_Request::enabled() {
        return *enabled_;
    }

    const bool& AlterEventConditionListMonitoring_Request::enabled() const {
        return *enabled_;
    }

    void AlterEventConditionListMonitoring_Request::enabled(const bool& vl) {
        enabled_ = vl;
    }

    void AlterEventConditionListMonitoring_Request::enabled(boost::shared_ptr< bool> vl) {
        enabled_ = vl;
    }

    boost::shared_ptr<AlterEventConditionListMonitoring_Request::priorityChange_type> AlterEventConditionListMonitoring_Request::priorityChange__new() {
        return priorityChange_ = boost::shared_ptr<priorityChange_type>(new priorityChange_type());
    }

    void AlterEventConditionListMonitoring_Request::priorityChange(const priorityChange_type& vl) {
        priorityChange_ = boost::shared_ptr<priorityChange_type>(new priorityChange_type(vl));
    }


    // sequence ReadJournal-Request

    ReadJournal_Request::ReadJournal_Request() : journalName_() {
    };

    ReadJournal_Request::ReadJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };

    ReadJournal_Request::ReadJournal_Request(boost::shared_ptr< ObjectName> arg__journalName,
            boost::shared_ptr< rangeStartSpecification_type> arg__rangeStartSpecification,
            boost::shared_ptr< rangeStopSpecification_type> arg__rangeStopSpecification,
            boost::shared_ptr< listOfVariables_type> arg__listOfVariables,
            boost::shared_ptr< entryToStartAfter_type> arg__entryToStartAfter) :
    journalName_(arg__journalName),
    rangeStartSpecification_(arg__rangeStartSpecification),
    rangeStopSpecification_(arg__rangeStopSpecification),
    listOfVariables_(arg__listOfVariables),
    entryToStartAfter_(arg__entryToStartAfter) {
    };

    void ReadJournal_Request::rangeStartSpecification_type::startingTime(const TimeOfDay& vl) {
        set<TimeOfDay>(new TimeOfDay(vl), rangeStartSpecification_type_startingTime);
    }

    void ReadJournal_Request::rangeStartSpecification_type::startingEntry(const octetstring_type& vl) {
        set<octetstring_type>(new octetstring_type(vl), rangeStartSpecification_type_startingEntry);
    }

    template<> void ReadJournal_Request::rangeStartSpecification_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case rangeStartSpecification_type_startingTime:
            {
                ITU_T_IMPLICIT_TAG(value<TimeOfDay > (false, rangeStartSpecification_type_startingTime), 0);
                break;
            }
            case rangeStartSpecification_type_startingEntry:
            {
                ITU_T_IMPLICIT_TAG(value<octetstring_type > (false, rangeStartSpecification_type_startingEntry), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReadJournal_Request::rangeStartSpecification_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TimeOfDay > (true, rangeStartSpecification_type_startingTime), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<octetstring_type > (true, rangeStartSpecification_type_startingEntry), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    void ReadJournal_Request::rangeStopSpecification_type::endingTime(const TimeOfDay& vl) {
        set<TimeOfDay>(new TimeOfDay(vl), rangeStopSpecification_type_endingTime);
    }

    void ReadJournal_Request::rangeStopSpecification_type::numberOfEntries(const Integer32& vl) {
        set<Integer32>(new Integer32(vl), rangeStopSpecification_type_numberOfEntries);
    }

    template<> void ReadJournal_Request::rangeStopSpecification_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case rangeStopSpecification_type_endingTime:
            {
                ITU_T_IMPLICIT_TAG(value<TimeOfDay > (false, rangeStopSpecification_type_endingTime), 0);
                break;
            }
            case rangeStopSpecification_type_numberOfEntries:
            {
                ITU_T_IMPLICIT_TAG(value<Integer32 > (false, rangeStopSpecification_type_numberOfEntries), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ReadJournal_Request::rangeStopSpecification_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<TimeOfDay > (true, rangeStopSpecification_type_endingTime), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Integer32 > (true, rangeStopSpecification_type_numberOfEntries), 1)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    ReadJournal_Request::entryToStartAfter_type::entryToStartAfter_type() : timeSpecification_(), entrySpecification_() {
    };

    ReadJournal_Request::entryToStartAfter_type::entryToStartAfter_type(const TimeOfDay& arg__timeSpecification,
            const octetstring_type& arg__entrySpecification) :
    timeSpecification_(arg__timeSpecification),
    entrySpecification_(arg__entrySpecification) {
    };

    template<> void ReadJournal_Request::entryToStartAfter_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(timeSpecification_, 0);
        ITU_T_IMPLICIT_TAG(entrySpecification_, 1);
    }

    template<> void ReadJournal_Request::entryToStartAfter_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(timeSpecification_, 0);
        ITU_T_IMPLICIT_TAG(entrySpecification_, 1);
    }

    TimeOfDay& ReadJournal_Request::entryToStartAfter_type::timeSpecification() {
        return *timeSpecification_;
    }

    const TimeOfDay& ReadJournal_Request::entryToStartAfter_type::timeSpecification() const {
        return *timeSpecification_;
    }

    void ReadJournal_Request::entryToStartAfter_type::timeSpecification(const TimeOfDay& vl) {
        timeSpecification_ = vl;
    }

    void ReadJournal_Request::entryToStartAfter_type::timeSpecification(boost::shared_ptr< TimeOfDay> vl) {
        timeSpecification_ = vl;
    }

    octetstring_type& ReadJournal_Request::entryToStartAfter_type::entrySpecification() {
        return *entrySpecification_;
    }

    const octetstring_type& ReadJournal_Request::entryToStartAfter_type::entrySpecification() const {
        return *entrySpecification_;
    }

    void ReadJournal_Request::entryToStartAfter_type::entrySpecification(const octetstring_type& vl) {
        entrySpecification_ = vl;
    }

    void ReadJournal_Request::entryToStartAfter_type::entrySpecification(boost::shared_ptr< octetstring_type> vl) {
        entrySpecification_ = vl;
    }

    template<> void ReadJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
        ITU_T_CHOICE_TAG(rangeStartSpecification_, 1);
        ITU_T_CHOICE_TAG(rangeStopSpecification_, 2);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 4);
        ITU_T_IMPLICIT_TAG(entryToStartAfter_, 5);
    }

    template<> void ReadJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
        ITU_T_CHOICE_TAG(rangeStartSpecification_, 1);
        ITU_T_CHOICE_TAG(rangeStopSpecification_, 2);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 4);
        ITU_T_IMPLICIT_TAG(entryToStartAfter_, 5);
    }

    ObjectName& ReadJournal_Request::journalName() {
        return *journalName_;
    }

    const ObjectName& ReadJournal_Request::journalName() const {
        return *journalName_;
    }

    void ReadJournal_Request::journalName(const ObjectName& vl) {
        journalName_ = vl;
    }

    void ReadJournal_Request::journalName(boost::shared_ptr< ObjectName> vl) {
        journalName_ = vl;
    }

    boost::shared_ptr<ReadJournal_Request::rangeStartSpecification_type> ReadJournal_Request::rangeStartSpecification__new() {
        return rangeStartSpecification_ = boost::shared_ptr<rangeStartSpecification_type>(new rangeStartSpecification_type());
    }

    void ReadJournal_Request::rangeStartSpecification(const rangeStartSpecification_type& vl) {
        rangeStartSpecification_ = boost::shared_ptr<rangeStartSpecification_type>(new rangeStartSpecification_type(vl));
    }

    boost::shared_ptr<ReadJournal_Request::rangeStopSpecification_type> ReadJournal_Request::rangeStopSpecification__new() {
        return rangeStopSpecification_ = boost::shared_ptr<rangeStopSpecification_type>(new rangeStopSpecification_type());
    }

    void ReadJournal_Request::rangeStopSpecification(const rangeStopSpecification_type& vl) {
        rangeStopSpecification_ = boost::shared_ptr<rangeStopSpecification_type>(new rangeStopSpecification_type(vl));
    }

    boost::shared_ptr<ReadJournal_Request::listOfVariables_type> ReadJournal_Request::listOfVariables__new() {
        return listOfVariables_ = boost::shared_ptr<listOfVariables_type>(new listOfVariables_type());
    }

    void ReadJournal_Request::listOfVariables(const listOfVariables_type& vl) {
        listOfVariables_ = boost::shared_ptr<listOfVariables_type>(new listOfVariables_type(vl));
    }

    boost::shared_ptr<ReadJournal_Request::entryToStartAfter_type> ReadJournal_Request::entryToStartAfter__new() {
        return entryToStartAfter_ = boost::shared_ptr<entryToStartAfter_type>(new entryToStartAfter_type());
    }

    void ReadJournal_Request::entryToStartAfter(const entryToStartAfter_type& vl) {
        entryToStartAfter_ = boost::shared_ptr<entryToStartAfter_type>(new entryToStartAfter_type(vl));
    }


    // sequence ReadJournal-Response

    ReadJournal_Response::ReadJournal_Response() : listOfJournalEntry_() {
    };

    ReadJournal_Response::ReadJournal_Response(const listOfJournalEntry_type& arg__listOfJournalEntry) :
    listOfJournalEntry_(arg__listOfJournalEntry) {
    };

    ReadJournal_Response::ReadJournal_Response(boost::shared_ptr< listOfJournalEntry_type> arg__listOfJournalEntry,
            boost::shared_ptr< bool> arg__moreFollows) :
    listOfJournalEntry_(arg__listOfJournalEntry),
    moreFollows_(arg__moreFollows) {
    };

    const bool ReadJournal_Response::moreFollows__default = false;

    template<> void ReadJournal_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfJournalEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void ReadJournal_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(listOfJournalEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    ReadJournal_Response::listOfJournalEntry_type& ReadJournal_Response::listOfJournalEntry() {
        return *listOfJournalEntry_;
    }

    const ReadJournal_Response::listOfJournalEntry_type& ReadJournal_Response::listOfJournalEntry() const {
        return *listOfJournalEntry_;
    }

    void ReadJournal_Response::listOfJournalEntry(const listOfJournalEntry_type& vl) {
        listOfJournalEntry_ = vl;
    }

    void ReadJournal_Response::listOfJournalEntry(boost::shared_ptr< listOfJournalEntry_type> vl) {
        listOfJournalEntry_ = vl;
    }

    const bool& ReadJournal_Response::moreFollows() const {
        return *moreFollows_;
    }

    void ReadJournal_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void ReadJournal_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


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

    template<> void JournalEntry::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(entryIdentifier_, 0);
        ITU_T_EXPLICIT_TAG(originatingApplication_, 1);
        ITU_T_IMPLICIT_TAG(entryContent_, 2);
    }

    template<> void JournalEntry::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(entryIdentifier_, 0);
        ITU_T_EXPLICIT_TAG(originatingApplication_, 1);
        ITU_T_IMPLICIT_TAG(entryContent_, 2);
    }

    octetstring_type& JournalEntry::entryIdentifier() {
        return *entryIdentifier_;
    }

    const octetstring_type& JournalEntry::entryIdentifier() const {
        return *entryIdentifier_;
    }

    void JournalEntry::entryIdentifier(const octetstring_type& vl) {
        entryIdentifier_ = vl;
    }

    void JournalEntry::entryIdentifier(boost::shared_ptr< octetstring_type> vl) {
        entryIdentifier_ = vl;
    }

    MMS_Environment_1::ApplicationReference& JournalEntry::originatingApplication() {
        return *originatingApplication_;
    }

    const MMS_Environment_1::ApplicationReference& JournalEntry::originatingApplication() const {
        return *originatingApplication_;
    }

    void JournalEntry::originatingApplication(const MMS_Environment_1::ApplicationReference& vl) {
        originatingApplication_ = vl;
    }

    void JournalEntry::originatingApplication(boost::shared_ptr< MMS_Environment_1::ApplicationReference> vl) {
        originatingApplication_ = vl;
    }

    EntryContent& JournalEntry::entryContent() {
        return *entryContent_;
    }

    const EntryContent& JournalEntry::entryContent() const {
        return *entryContent_;
    }

    void JournalEntry::entryContent(const EntryContent& vl) {
        entryContent_ = vl;
    }

    void JournalEntry::entryContent(boost::shared_ptr< EntryContent> vl) {
        entryContent_ = vl;
    }


    // sequence WriteJournal-Request

    WriteJournal_Request::WriteJournal_Request() : journalName_(), listOfJournalEntry_() {
    };

    WriteJournal_Request::WriteJournal_Request(const ObjectName& arg__journalName,
            const listOfJournalEntry_type& arg__listOfJournalEntry) :
    journalName_(arg__journalName),
    listOfJournalEntry_(arg__listOfJournalEntry) {
    };

    template<> void WriteJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
        ITU_T_IMPLICIT_TAG(listOfJournalEntry_, 1);
    }

    template<> void WriteJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
        ITU_T_IMPLICIT_TAG(listOfJournalEntry_, 1);
    }

    ObjectName& WriteJournal_Request::journalName() {
        return *journalName_;
    }

    const ObjectName& WriteJournal_Request::journalName() const {
        return *journalName_;
    }

    void WriteJournal_Request::journalName(const ObjectName& vl) {
        journalName_ = vl;
    }

    void WriteJournal_Request::journalName(boost::shared_ptr< ObjectName> vl) {
        journalName_ = vl;
    }

    WriteJournal_Request::listOfJournalEntry_type& WriteJournal_Request::listOfJournalEntry() {
        return *listOfJournalEntry_;
    }

    const WriteJournal_Request::listOfJournalEntry_type& WriteJournal_Request::listOfJournalEntry() const {
        return *listOfJournalEntry_;
    }

    void WriteJournal_Request::listOfJournalEntry(const listOfJournalEntry_type& vl) {
        listOfJournalEntry_ = vl;
    }

    void WriteJournal_Request::listOfJournalEntry(boost::shared_ptr< listOfJournalEntry_type> vl) {
        listOfJournalEntry_ = vl;
    }


    // sequence InitializeJournal-Request

    InitializeJournal_Request::InitializeJournal_Request() : journalName_() {
    };

    InitializeJournal_Request::InitializeJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };

    InitializeJournal_Request::InitializeJournal_Request(boost::shared_ptr< ObjectName> arg__journalName,
            boost::shared_ptr< limitSpecification_type> arg__limitSpecification) :
    journalName_(arg__journalName),
    limitSpecification_(arg__limitSpecification) {
    };

    InitializeJournal_Request::limitSpecification_type::limitSpecification_type() : limitingTime_() {
    };

    InitializeJournal_Request::limitSpecification_type::limitSpecification_type(const TimeOfDay& arg__limitingTime) :
    limitingTime_(arg__limitingTime) {
    };

    InitializeJournal_Request::limitSpecification_type::limitSpecification_type(boost::shared_ptr< TimeOfDay> arg__limitingTime,
            boost::shared_ptr< octetstring_type> arg__limitingEntry) :
    limitingTime_(arg__limitingTime),
    limitingEntry_(arg__limitingEntry) {
    };

    template<> void InitializeJournal_Request::limitSpecification_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(limitingTime_, 0);
        ITU_T_IMPLICIT_TAG(limitingEntry_, 1);
    }

    template<> void InitializeJournal_Request::limitSpecification_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(limitingTime_, 0);
        ITU_T_IMPLICIT_TAG(limitingEntry_, 1);
    }

    TimeOfDay& InitializeJournal_Request::limitSpecification_type::limitingTime() {
        return *limitingTime_;
    }

    const TimeOfDay& InitializeJournal_Request::limitSpecification_type::limitingTime() const {
        return *limitingTime_;
    }

    void InitializeJournal_Request::limitSpecification_type::limitingTime(const TimeOfDay& vl) {
        limitingTime_ = vl;
    }

    void InitializeJournal_Request::limitSpecification_type::limitingTime(boost::shared_ptr< TimeOfDay> vl) {
        limitingTime_ = vl;
    }

    boost::shared_ptr<octetstring_type> InitializeJournal_Request::limitSpecification_type::limitingEntry__new() {
        return limitingEntry_ = boost::shared_ptr<octetstring_type>(new octetstring_type());
    }

    void InitializeJournal_Request::limitSpecification_type::limitingEntry(const octetstring_type& vl) {
        limitingEntry_ = boost::shared_ptr<octetstring_type>(new octetstring_type(vl));
    }

    template<> void InitializeJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
        ITU_T_IMPLICIT_TAG(limitSpecification_, 1);
    }

    template<> void InitializeJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
        ITU_T_IMPLICIT_TAG(limitSpecification_, 1);
    }

    ObjectName& InitializeJournal_Request::journalName() {
        return *journalName_;
    }

    const ObjectName& InitializeJournal_Request::journalName() const {
        return *journalName_;
    }

    void InitializeJournal_Request::journalName(const ObjectName& vl) {
        journalName_ = vl;
    }

    void InitializeJournal_Request::journalName(boost::shared_ptr< ObjectName> vl) {
        journalName_ = vl;
    }

    boost::shared_ptr<InitializeJournal_Request::limitSpecification_type> InitializeJournal_Request::limitSpecification__new() {
        return limitSpecification_ = boost::shared_ptr<limitSpecification_type>(new limitSpecification_type());
    }

    void InitializeJournal_Request::limitSpecification(const limitSpecification_type& vl) {
        limitSpecification_ = boost::shared_ptr<limitSpecification_type>(new limitSpecification_type(vl));
    }


    // sequence ReportJournalStatus-Response

    ReportJournalStatus_Response::ReportJournalStatus_Response() : currentEntries_(), mmsDeletable_() {
    };

    ReportJournalStatus_Response::ReportJournalStatus_Response(const Unsigned32& arg__currentEntries,
            const bool& arg__mmsDeletable) :
    currentEntries_(arg__currentEntries),
    mmsDeletable_(arg__mmsDeletable) {
    };

    ReportJournalStatus_Response::ReportJournalStatus_Response(boost::shared_ptr< Unsigned32> arg__currentEntries,
            boost::shared_ptr< bool> arg__mmsDeletable,
            boost::shared_ptr< Identifier> arg__accessControlList) :
    currentEntries_(arg__currentEntries),
    mmsDeletable_(arg__mmsDeletable),
    accessControlList_(arg__accessControlList) {
    };

    template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(currentEntries_, 0);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    template<> void ReportJournalStatus_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(currentEntries_, 0);
        ITU_T_IMPLICIT_TAG(mmsDeletable_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    Unsigned32& ReportJournalStatus_Response::currentEntries() {
        return *currentEntries_;
    }

    const Unsigned32& ReportJournalStatus_Response::currentEntries() const {
        return *currentEntries_;
    }

    void ReportJournalStatus_Response::currentEntries(const Unsigned32& vl) {
        currentEntries_ = vl;
    }

    void ReportJournalStatus_Response::currentEntries(boost::shared_ptr< Unsigned32> vl) {
        currentEntries_ = vl;
    }

    bool& ReportJournalStatus_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& ReportJournalStatus_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void ReportJournalStatus_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void ReportJournalStatus_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    boost::shared_ptr<Identifier> ReportJournalStatus_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<Identifier>(new Identifier());
    }

    void ReportJournalStatus_Response::accessControlList(const Identifier& vl) {
        accessControlList_ = boost::shared_ptr<Identifier>(new Identifier(vl));
    }


    // sequence CreateJournal-Request

    CreateJournal_Request::CreateJournal_Request() : journalName_() {
    };

    CreateJournal_Request::CreateJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };

    template<> void CreateJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
    }

    template<> void CreateJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
    }

    ObjectName& CreateJournal_Request::journalName() {
        return *journalName_;
    }

    const ObjectName& CreateJournal_Request::journalName() const {
        return *journalName_;
    }

    void CreateJournal_Request::journalName(const ObjectName& vl) {
        journalName_ = vl;
    }

    void CreateJournal_Request::journalName(boost::shared_ptr< ObjectName> vl) {
        journalName_ = vl;
    }


    // sequence DeleteJournal-Request

    DeleteJournal_Request::DeleteJournal_Request() : journalName_() {
    };

    DeleteJournal_Request::DeleteJournal_Request(const ObjectName& arg__journalName) :
    journalName_(arg__journalName) {
    };

    template<> void DeleteJournal_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
    }

    template<> void DeleteJournal_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(journalName_, 0);
    }

    ObjectName& DeleteJournal_Request::journalName() {
        return *journalName_;
    }

    const ObjectName& DeleteJournal_Request::journalName() const {
        return *journalName_;
    }

    void DeleteJournal_Request::journalName(const ObjectName& vl) {
        journalName_ = vl;
    }

    void DeleteJournal_Request::journalName(boost::shared_ptr< ObjectName> vl) {
        journalName_ = vl;
    }


    // sequence EntryContent

    EntryContent::EntryContent() : occurrenceTime_(), entryForm_() {
    };

    EntryContent::EntryContent(const TimeOfDay& arg__occurrenceTime,
            const entryForm_type& arg__entryForm) :
    occurrenceTime_(arg__occurrenceTime),
    entryForm_(arg__entryForm) {
    };

    EntryContent::entryForm_type::data_type::data_type() {
    };

    EntryContent::entryForm_type::data_type::data_type(boost::shared_ptr< event_type> arg__event,
            boost::shared_ptr< listOfVariables_type> arg__listOfVariables) :
    event_(arg__event),
    listOfVariables_(arg__listOfVariables) {
    };

    EntryContent::entryForm_type::data_type::event_type::event_type() : eventConditionName_(), currentState_() {
    };

    EntryContent::entryForm_type::data_type::event_type::event_type(const ObjectName& arg__eventConditionName,
            const MMS_Object_Module_1::EC_State& arg__currentState) :
    eventConditionName_(arg__eventConditionName),
    currentState_(arg__currentState) {
    };

    template<> void EntryContent::entryForm_type::data_type::event_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(currentState_, 1);
    }

    template<> void EntryContent::entryForm_type::data_type::event_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(eventConditionName_, 0);
        ITU_T_IMPLICIT_TAG(currentState_, 1);
    }

    ObjectName& EntryContent::entryForm_type::data_type::event_type::eventConditionName() {
        return *eventConditionName_;
    }

    const ObjectName& EntryContent::entryForm_type::data_type::event_type::eventConditionName() const {
        return *eventConditionName_;
    }

    void EntryContent::entryForm_type::data_type::event_type::eventConditionName(const ObjectName& vl) {
        eventConditionName_ = vl;
    }

    void EntryContent::entryForm_type::data_type::event_type::eventConditionName(boost::shared_ptr< ObjectName> vl) {
        eventConditionName_ = vl;
    }

    MMS_Object_Module_1::EC_State& EntryContent::entryForm_type::data_type::event_type::currentState() {
        return *currentState_;
    }

    const MMS_Object_Module_1::EC_State& EntryContent::entryForm_type::data_type::event_type::currentState() const {
        return *currentState_;
    }

    void EntryContent::entryForm_type::data_type::event_type::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = vl;
    }

    void EntryContent::entryForm_type::data_type::event_type::currentState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        currentState_ = vl;
    }

    template<> void EntryContent::entryForm_type::data_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(event_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 1);
    }

    template<> void EntryContent::entryForm_type::data_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(event_, 0);
        ITU_T_IMPLICIT_TAG(listOfVariables_, 1);
    }

    boost::shared_ptr<EntryContent::entryForm_type::data_type::event_type> EntryContent::entryForm_type::data_type::event__new() {
        return event_ = boost::shared_ptr<event_type>(new event_type());
    }

    void EntryContent::entryForm_type::data_type::event(const event_type& vl) {
        event_ = boost::shared_ptr<event_type>(new event_type(vl));
    }

    boost::shared_ptr<EntryContent::entryForm_type::data_type::listOfVariables_type> EntryContent::entryForm_type::data_type::listOfVariables__new() {
        return listOfVariables_ = boost::shared_ptr<listOfVariables_type>(new listOfVariables_type());
    }

    void EntryContent::entryForm_type::data_type::listOfVariables(const listOfVariables_type& vl) {
        listOfVariables_ = boost::shared_ptr<listOfVariables_type>(new listOfVariables_type(vl));
    }

    void EntryContent::entryForm_type::annotation(const MMSString& vl) {
        set<MMSString>(new MMSString(vl), entryForm_type_annotation);
    }

    template<> void EntryContent::entryForm_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case entryForm_type_data:
            {
                ITU_T_IMPLICIT_TAG(value<data_type > (false, entryForm_type_data), 2);
                break;
            }
            case entryForm_type_annotation:
            {
                ITU_T_EXPLICIT_TAG(value<MMSString > (false, entryForm_type_annotation), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EntryContent::entryForm_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<data_type > (true, entryForm_type_data), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<MMSString > (true, entryForm_type_annotation), 3)) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
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

    template<> void EntryContent::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(occurrenceTime_, 0);
        ITU_T_BIND_CHOICE(entryForm_);
    }

    template<> void EntryContent::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(occurrenceTime_, 0);
        ITU_T_BIND_CHOICE(entryForm_);
    }

    TimeOfDay& EntryContent::occurrenceTime() {
        return *occurrenceTime_;
    }

    const TimeOfDay& EntryContent::occurrenceTime() const {
        return *occurrenceTime_;
    }

    void EntryContent::occurrenceTime(const TimeOfDay& vl) {
        occurrenceTime_ = vl;
    }

    void EntryContent::occurrenceTime(boost::shared_ptr< TimeOfDay> vl) {
        occurrenceTime_ = vl;
    }

    EntryContent::entryForm_type& EntryContent::entryForm() {
        return *entryForm_;
    }

    const EntryContent::entryForm_type& EntryContent::entryForm() const {
        return *entryForm_;
    }

    void EntryContent::entryForm(const entryForm_type& vl) {
        entryForm_ = vl;
    }

    void EntryContent::entryForm(boost::shared_ptr< entryForm_type> vl) {
        entryForm_ = vl;
    }


}
