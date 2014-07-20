#include "MMS-Object-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {

    const LogicalStatus logicalStatus_state_changes_allowed = 0;
    const LogicalStatus logicalStatus_no_state_changes_allowed = 1;
    const LogicalStatus logicalStatus_limited_services_permitted = 2;
    const LogicalStatus logicalStatus_support_services_allowed = 3;

    const PhysicalStatus physicalStatus_operational = 0;
    const PhysicalStatus physicalStatus_partially_operational = 1;
    const PhysicalStatus physicalStatus_inoperable = 2;
    const PhysicalStatus physicalStatus_needs_commissioning = 3;

    const VMDState vMDState_idle = 0;
    const VMDState vMDState_loaded = 1;
    const VMDState vMDState_ready = 2;
    const VMDState vMDState_executing = 3;
    const VMDState vMDState_motion_paused = 4;
    const VMDState vMDState_manualInterventionRequired = 5;

    // sequence ModifierStep

    ModifierStep::ModifierStep() : modifierID_(), modifier_() {
    };

    ModifierStep::ModifierStep(const int& arg__modifierID,
            const Modifier& arg__modifier) :
    modifierID_(arg__modifierID),
    modifier_(arg__modifier) {
    };

    template<> void ModifierStep::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(modifierID_);
        ITU_T_BIND_CHOICE(modifier_);
    }

    template<> void ModifierStep::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(modifierID_);
        ITU_T_BIND_CHOICE(modifier_);
    }

    int& ModifierStep::modifierID() {
        return *modifierID_;
    }

    const int& ModifierStep::modifierID() const {
        return *modifierID_;
    }

    void ModifierStep::modifierID(const int& vl) {
        modifierID_ = vl;
    }

    void ModifierStep::modifierID(boost::shared_ptr< int> vl) {
        modifierID_ = vl;
    }

    Modifier& ModifierStep::modifier() {
        return *modifier_;
    }

    const Modifier& ModifierStep::modifier() const {
        return *modifier_;
    }

    void ModifierStep::modifier(const Modifier& vl) {
        modifier_ = vl;
    }

    void ModifierStep::modifier(boost::shared_ptr< Modifier> vl) {
        modifier_ = vl;
    }


    // choice Modifier

    template<> void Modifier::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Modifier_eventModifier:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToEventCondition > (false, Modifier_eventModifier), 0);
                break;
            }
            case Modifier_semaphoreModifier:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToSemaphore > (false, Modifier_semaphoreModifier), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Modifier::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToEventCondition > (true, Modifier_eventModifier), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToSemaphore > (true, Modifier_semaphoreModifier), 1)) return;
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


    const ServiceSupportOptions serviceSupportOptions_status = bitstring_type(true, 0);
    const ServiceSupportOptions serviceSupportOptions_getNameList = bitstring_type(true, 1);
    const ServiceSupportOptions serviceSupportOptions_identify = bitstring_type(true, 2);
    const ServiceSupportOptions serviceSupportOptions_rename = bitstring_type(true, 3);
    const ServiceSupportOptions serviceSupportOptions_read = bitstring_type(true, 4);
    const ServiceSupportOptions serviceSupportOptions_write = bitstring_type(true, 5);
    const ServiceSupportOptions serviceSupportOptions_getVariableAccessAttributes = bitstring_type(true, 6);
    const ServiceSupportOptions serviceSupportOptions_defineNamedVariable = bitstring_type(true, 7);
    const ServiceSupportOptions serviceSupportOptions_defineScatteredAccess = bitstring_type(true, 8);
    const ServiceSupportOptions serviceSupportOptions_getScatteredAccessAttributes = bitstring_type(true, 9);
    const ServiceSupportOptions serviceSupportOptions_deleteVariableAccess = bitstring_type(true, 10);
    const ServiceSupportOptions serviceSupportOptions_defineNamedVariableList = bitstring_type(true, 11);
    const ServiceSupportOptions serviceSupportOptions_getNamedVariableListAttributes = bitstring_type(true, 12);
    const ServiceSupportOptions serviceSupportOptions_deleteNamedVariableList = bitstring_type(true, 13);
    const ServiceSupportOptions serviceSupportOptions_defineNamedType = bitstring_type(true, 14);
    const ServiceSupportOptions serviceSupportOptions_getNamedTypeAttributes = bitstring_type(true, 15);
    const ServiceSupportOptions serviceSupportOptions_deleteNamedType = bitstring_type(true, 16);
    const ServiceSupportOptions serviceSupportOptions_input = bitstring_type(true, 17);
    const ServiceSupportOptions serviceSupportOptions_output = bitstring_type(true, 18);
    const ServiceSupportOptions serviceSupportOptions_takeControl = bitstring_type(true, 19);
    const ServiceSupportOptions serviceSupportOptions_relinquishControl = bitstring_type(true, 20);
    const ServiceSupportOptions serviceSupportOptions_defineSemaphore = bitstring_type(true, 21);
    const ServiceSupportOptions serviceSupportOptions_deleteSemaphore = bitstring_type(true, 22);
    const ServiceSupportOptions serviceSupportOptions_reportSemaphoreStatus = bitstring_type(true, 23);
    const ServiceSupportOptions serviceSupportOptions_reportPoolSemaphoreStatus = bitstring_type(true, 24);
    const ServiceSupportOptions serviceSupportOptions_reportSemaphoreEntryStatus = bitstring_type(true, 25);
    const ServiceSupportOptions serviceSupportOptions_initiateDownloadSequence = bitstring_type(true, 26);
    const ServiceSupportOptions serviceSupportOptions_downloadSegment = bitstring_type(true, 27);
    const ServiceSupportOptions serviceSupportOptions_terminateDownloadSequence = bitstring_type(true, 28);
    const ServiceSupportOptions serviceSupportOptions_initiateUploadSequence = bitstring_type(true, 29);
    const ServiceSupportOptions serviceSupportOptions_uploadSegment = bitstring_type(true, 30);
    const ServiceSupportOptions serviceSupportOptions_terminateUploadSequence = bitstring_type(true, 31);
    const ServiceSupportOptions serviceSupportOptions_requestDomainDownload = bitstring_type(true, 32);
    const ServiceSupportOptions serviceSupportOptions_requestDomainUpload = bitstring_type(true, 33);
    const ServiceSupportOptions serviceSupportOptions_loadDomainContent = bitstring_type(true, 34);
    const ServiceSupportOptions serviceSupportOptions_storeDomainContent = bitstring_type(true, 35);
    const ServiceSupportOptions serviceSupportOptions_deleteDomain = bitstring_type(true, 36);
    const ServiceSupportOptions serviceSupportOptions_getDomainAttributes = bitstring_type(true, 37);
    const ServiceSupportOptions serviceSupportOptions_createProgramInvocation = bitstring_type(true, 38);
    const ServiceSupportOptions serviceSupportOptions_deleteProgramInvocation = bitstring_type(true, 39);
    const ServiceSupportOptions serviceSupportOptions_start = bitstring_type(true, 40);
    const ServiceSupportOptions serviceSupportOptions_stop = bitstring_type(true, 41);
    const ServiceSupportOptions serviceSupportOptions_resume = bitstring_type(true, 42);
    const ServiceSupportOptions serviceSupportOptions_reset = bitstring_type(true, 43);
    const ServiceSupportOptions serviceSupportOptions_kill = bitstring_type(true, 44);
    const ServiceSupportOptions serviceSupportOptions_getProgramInvocationAttributes = bitstring_type(true, 45);
    const ServiceSupportOptions serviceSupportOptions_obtainFile = bitstring_type(true, 46);
    const ServiceSupportOptions serviceSupportOptions_defineEventCondition = bitstring_type(true, 47);
    const ServiceSupportOptions serviceSupportOptions_deleteEventCondition = bitstring_type(true, 48);
    const ServiceSupportOptions serviceSupportOptions_getEventConditionAttributes = bitstring_type(true, 49);
    const ServiceSupportOptions serviceSupportOptions_reportEventConditionStatus = bitstring_type(true, 50);
    const ServiceSupportOptions serviceSupportOptions_alterEventConditionMonitoring = bitstring_type(true, 51);
    const ServiceSupportOptions serviceSupportOptions_triggerEvent = bitstring_type(true, 52);
    const ServiceSupportOptions serviceSupportOptions_defineEventAction = bitstring_type(true, 53);
    const ServiceSupportOptions serviceSupportOptions_deleteEventAction = bitstring_type(true, 54);
    const ServiceSupportOptions serviceSupportOptions_getEventActionAttributes = bitstring_type(true, 55);
    const ServiceSupportOptions serviceSupportOptions_reportEventActionStatus = bitstring_type(true, 56);
    const ServiceSupportOptions serviceSupportOptions_defineEventEnrollment = bitstring_type(true, 57);
    const ServiceSupportOptions serviceSupportOptions_deleteEventEnrollment = bitstring_type(true, 58);
    const ServiceSupportOptions serviceSupportOptions_alterEventEnrollment = bitstring_type(true, 59);
    const ServiceSupportOptions serviceSupportOptions_reportEventEnrollmentStatus = bitstring_type(true, 60);
    const ServiceSupportOptions serviceSupportOptions_getEventEnrollmentAttributes = bitstring_type(true, 61);
    const ServiceSupportOptions serviceSupportOptions_acknowledgeEventNotification = bitstring_type(true, 62);
    const ServiceSupportOptions serviceSupportOptions_getAlarmSummary = bitstring_type(true, 63);
    const ServiceSupportOptions serviceSupportOptions_getAlarmEnrollmentSummary = bitstring_type(true, 64);
    const ServiceSupportOptions serviceSupportOptions_readJournal = bitstring_type(true, 65);
    const ServiceSupportOptions serviceSupportOptions_writeJournal = bitstring_type(true, 66);
    const ServiceSupportOptions serviceSupportOptions_initializeJournal = bitstring_type(true, 67);
    const ServiceSupportOptions serviceSupportOptions_reportJournalStatus = bitstring_type(true, 68);
    const ServiceSupportOptions serviceSupportOptions_createJournal = bitstring_type(true, 69);
    const ServiceSupportOptions serviceSupportOptions_deleteJournal = bitstring_type(true, 70);
    const ServiceSupportOptions serviceSupportOptions_getCapabilityList = bitstring_type(true, 71);
    const ServiceSupportOptions serviceSupportOptions_fileOpen = bitstring_type(true, 72);
    const ServiceSupportOptions serviceSupportOptions_fileRead = bitstring_type(true, 73);
    const ServiceSupportOptions serviceSupportOptions_fileClose = bitstring_type(true, 74);
    const ServiceSupportOptions serviceSupportOptions_fileRename = bitstring_type(true, 75);
    const ServiceSupportOptions serviceSupportOptions_fileDelete = bitstring_type(true, 76);
    const ServiceSupportOptions serviceSupportOptions_fileDirectory = bitstring_type(true, 77);
    const ServiceSupportOptions serviceSupportOptions_unsolicitedStatus = bitstring_type(true, 78);
    const ServiceSupportOptions serviceSupportOptions_informationReport = bitstring_type(true, 79);
    const ServiceSupportOptions serviceSupportOptions_eventNotification = bitstring_type(true, 80);
    const ServiceSupportOptions serviceSupportOptions_attachToEventCondition = bitstring_type(true, 81);
    const ServiceSupportOptions serviceSupportOptions_attachToSemaphore = bitstring_type(true, 82);
    const ServiceSupportOptions serviceSupportOptions_conclude = bitstring_type(true, 83);
    const ServiceSupportOptions serviceSupportOptions_cancel = bitstring_type(true, 84);
    const ServiceSupportOptions serviceSupportOptions_getDataExchangeAttributes = bitstring_type(true, 85);
    const ServiceSupportOptions serviceSupportOptions_exchangeData = bitstring_type(true, 86);
    const ServiceSupportOptions serviceSupportOptions_defineAccessControlList = bitstring_type(true, 87);
    const ServiceSupportOptions serviceSupportOptions_getAccessControlListAttributes = bitstring_type(true, 88);
    const ServiceSupportOptions serviceSupportOptions_reportAccessControlledObjects = bitstring_type(true, 89);
    const ServiceSupportOptions serviceSupportOptions_deleteAccessControlList = bitstring_type(true, 90);
    const ServiceSupportOptions serviceSupportOptions_alterAccessControl = bitstring_type(true, 91);
    const ServiceSupportOptions serviceSupportOptions_reconfigureProgramInvocation = bitstring_type(true, 92);

    const ParameterSupportOptions parameterSupportOptions_str1 = bitstring_type(true, 0);
    const ParameterSupportOptions parameterSupportOptions_str2 = bitstring_type(true, 1);
    const ParameterSupportOptions parameterSupportOptions_vnam = bitstring_type(true, 2);
    const ParameterSupportOptions parameterSupportOptions_valt = bitstring_type(true, 3);
    const ParameterSupportOptions parameterSupportOptions_vadr = bitstring_type(true, 4);
    const ParameterSupportOptions parameterSupportOptions_vsca = bitstring_type(true, 5);
    const ParameterSupportOptions parameterSupportOptions_tpy = bitstring_type(true, 6);
    const ParameterSupportOptions parameterSupportOptions_vlis = bitstring_type(true, 7);
    const ParameterSupportOptions parameterSupportOptions_cei = bitstring_type(true, 10);
    const ParameterSupportOptions parameterSupportOptions_aco = bitstring_type(true, 11);
    const ParameterSupportOptions parameterSupportOptions_sem = bitstring_type(true, 12);
    const ParameterSupportOptions parameterSupportOptions_csr = bitstring_type(true, 13);
    const ParameterSupportOptions parameterSupportOptions_csnc = bitstring_type(true, 14);
    const ParameterSupportOptions parameterSupportOptions_csplc = bitstring_type(true, 15);
    const ParameterSupportOptions parameterSupportOptions_cspi = bitstring_type(true, 16);
    const ParameterSupportOptions parameterSupportOptions_char = bitstring_type(true, 17);

    const AdditionalSupportOptions additionalSupportOptions_vMDStop = bitstring_type(true, 0);
    const AdditionalSupportOptions additionalSupportOptions_vMDReset = bitstring_type(true, 1);
    const AdditionalSupportOptions additionalSupportOptions_select = bitstring_type(true, 2);
    const AdditionalSupportOptions additionalSupportOptions_alterProgramInvocationAttributes = bitstring_type(true, 3);
    const AdditionalSupportOptions additionalSupportOptions_initiateUnitControlLoad = bitstring_type(true, 4);
    const AdditionalSupportOptions additionalSupportOptions_unitControlLoadSegment = bitstring_type(true, 5);
    const AdditionalSupportOptions additionalSupportOptions_unitControlUpload = bitstring_type(true, 6);
    const AdditionalSupportOptions additionalSupportOptions_startUnitControl = bitstring_type(true, 7);
    const AdditionalSupportOptions additionalSupportOptions_stopUnitControl = bitstring_type(true, 8);
    const AdditionalSupportOptions additionalSupportOptions_createUnitControl = bitstring_type(true, 9);
    const AdditionalSupportOptions additionalSupportOptions_addToUnitControl = bitstring_type(true, 10);
    const AdditionalSupportOptions additionalSupportOptions_removeFromUnitControl = bitstring_type(true, 11);
    const AdditionalSupportOptions additionalSupportOptions_getUnitControlAttributes = bitstring_type(true, 12);
    const AdditionalSupportOptions additionalSupportOptions_loadUnitControlFromFile = bitstring_type(true, 13);
    const AdditionalSupportOptions additionalSupportOptions_storeUnitControlToFile = bitstring_type(true, 14);
    const AdditionalSupportOptions additionalSupportOptions_deleteUnitControl = bitstring_type(true, 15);
    const AdditionalSupportOptions additionalSupportOptions_defineEventConditionList = bitstring_type(true, 16);
    const AdditionalSupportOptions additionalSupportOptions_deleteEventConditionList = bitstring_type(true, 17);
    const AdditionalSupportOptions additionalSupportOptions_addEventConditionListReference = bitstring_type(true, 18);
    const AdditionalSupportOptions additionalSupportOptions_removeEventConditionListReference = bitstring_type(true, 19);
    const AdditionalSupportOptions additionalSupportOptions_getEventConditionListAttributes = bitstring_type(true, 20);
    const AdditionalSupportOptions additionalSupportOptions_reportEventConditionListStatus = bitstring_type(true, 21);
    const AdditionalSupportOptions additionalSupportOptions_alterEventConditionListMonitoring = bitstring_type(true, 22);

    const AdditionalCBBOptions additionalCBBOptions_des = bitstring_type(true, 0);
    const AdditionalCBBOptions additionalCBBOptions_dei = bitstring_type(true, 1);
    const AdditionalCBBOptions additionalCBBOptions_recl = bitstring_type(true, 2);

    // choice AccessCondition

    void AccessCondition::User_type::none(const null_type& vl) {
        set<null_type>(new null_type(vl), User_type_none);
    }

    template<> void AccessCondition::User_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_type_association:
            {
                ITU_T_BIND_TAG(value<MMS_Environment_1::ApplicationReference > (false, User_type_association));
                break;
            }
            case User_type_none:
            {
                ITU_T_BIND_TAG(value<null_type > (false, User_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessCondition::User_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(value<MMS_Environment_1::ApplicationReference > (true, User_type_association))) return;
                else free();
                if (ITU_T_BIND_TAG(value<null_type > (true, User_type_none))) return;
                else free();
            }
        }
    }

    void AccessCondition::never(const null_type& vl) {
        set<null_type>(new null_type(vl), AccessCondition_never);
    }

    void AccessCondition::semaphore(const ISO_9506_MMS_1::Identifier& vl) {
        set<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier(vl), AccessCondition_semaphore);
    }

    template<> void AccessCondition::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AccessCondition_never:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, AccessCondition_never), 0);
                break;
            }
            case AccessCondition_semaphore:
            {
                ITU_T_EXPLICIT_TAG(value<ISO_9506_MMS_1::Identifier > (false, AccessCondition_semaphore), 1);
                break;
            }
            case AccessCondition_user:
            {
                ITU_T_CHOICE_TAG(value<User_type > (false, AccessCondition_user), 2);
                break;
            }
            case AccessCondition_password:
            {
                ITU_T_CHOICE_TAG(value<ACSE_1::Authentication_value > (false, AccessCondition_password), 3);
                break;
            }
            case AccessCondition_joint:
            {
                ITU_T_IMPLICIT_TAG(value<Joint_type > (false, AccessCondition_joint), 4);
                break;
            }
            case AccessCondition_alternate:
            {
                ITU_T_IMPLICIT_TAG(value<Alternate_type > (false, AccessCondition_alternate), 5);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessCondition::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, AccessCondition_never), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<ISO_9506_MMS_1::Identifier > (true, AccessCondition_semaphore), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_CHOICE_TAG(value<User_type > (true, AccessCondition_user), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_CHOICE_TAG(value<ACSE_1::Authentication_value > (true, AccessCondition_password), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Joint_type > (true, AccessCondition_joint), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Alternate_type > (true, AccessCondition_alternate), 5)) return;
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


    const DomainState domainState_non_existent = 0;
    const DomainState domainState_loading = 1;
    const DomainState domainState_ready = 2;
    const DomainState domainState_in_use = 3;
    const DomainState domainState_complete = 4;
    const DomainState domainState_incomplete = 5;
    const DomainState domainState_d1 = 7;
    const DomainState domainState_d2 = 8;
    const DomainState domainState_d3 = 9;
    const DomainState domainState_d4 = 10;
    const DomainState domainState_d5 = 11;
    const DomainState domainState_d6 = 12;
    const DomainState domainState_d7 = 13;
    const DomainState domainState_d8 = 14;
    const DomainState domainState_d9 = 15;

    const ULState uLState_non_existent = 0;
    const ULState uLState_uploading = 1;
    const ULState uLState_uploaded = 2;
    const ULState uLState_u1 = 3;
    const ULState uLState_u2 = 4;
    const ULState uLState_u3 = 5;
    const ULState uLState_u4 = 6;

    const ProgramInvocationState programInvocationState_non_existent = 0;
    const ProgramInvocationState programInvocationState_unrunnable = 1;
    const ProgramInvocationState programInvocationState_idle = 2;
    const ProgramInvocationState programInvocationState_running = 3;
    const ProgramInvocationState programInvocationState_stopped = 4;
    const ProgramInvocationState programInvocationState_starting = 5;
    const ProgramInvocationState programInvocationState_stopping = 6;
    const ProgramInvocationState programInvocationState_resuming = 7;
    const ProgramInvocationState programInvocationState_resetting = 8;

    const Control_State control_State_normal = 0;
    const Control_State control_State_controlling = 1;
    const Control_State control_State_controlled = 2;

    const Running_Mode running_Mode_free_run = 0;
    const Running_Mode running_Mode_cycle_limited = 1;
    const Running_Mode running_Mode_step_limited = 2;

    // choice Address

    void Address::numericAddress(const ISO_9506_MMS_1::Unsigned32& vl) {
        set<ISO_9506_MMS_1::Unsigned32>(new ISO_9506_MMS_1::Unsigned32(vl), Address_numericAddress);
    }

    void Address::symbolicAddress(const ISO_9506_MMS_1::MMSString& vl) {
        set<ISO_9506_MMS_1::MMSString>(new ISO_9506_MMS_1::MMSString(vl), Address_symbolicAddress);
    }

    void Address::unconstrainedAddress(const octetstring_type& vl) {
        set<octetstring_type>(new octetstring_type(vl), Address_unconstrainedAddress);
    }

    template<> void Address::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Address_numericAddress:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (false, Address_numericAddress), 0);
                break;
            }
            case Address_symbolicAddress:
            {
                ITU_T_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (false, Address_symbolicAddress), 1);
                break;
            }
            case Address_unconstrainedAddress:
            {
                ITU_T_IMPLICIT_TAG(value<octetstring_type > (false, Address_unconstrainedAddress), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Address::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (true, Address_numericAddress), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (true, Address_symbolicAddress), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<octetstring_type > (true, Address_unconstrainedAddress), 2)) return;
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


    // choice TypeDescription

    TypeDescription::Array_type::Array_type() : numberOfElements_(), elementType_() {
    };

    TypeDescription::Array_type::Array_type(const ISO_9506_MMS_1::Unsigned32& arg__numberOfElements,
            const ISO_9506_MMS_1::TypeSpecification& arg__elementType) :
    numberOfElements_(arg__numberOfElements),
    elementType_(arg__elementType) {
    };

    TypeDescription::Array_type::Array_type(boost::shared_ptr< bool> arg__packed,
            boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__numberOfElements,
            boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__elementType) :
    packed_(arg__packed),
    numberOfElements_(arg__numberOfElements),
    elementType_(arg__elementType) {
    };

    const bool TypeDescription::Array_type::packed__default = false;

    template<> void TypeDescription::Array_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_, 0);
        ITU_T_IMPLICIT_TAG(numberOfElements_, 1);
        ITU_T_CHOICE_TAG(elementType_, 2);
    }

    template<> void TypeDescription::Array_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_, 0);
        ITU_T_IMPLICIT_TAG(numberOfElements_, 1);
        ITU_T_CHOICE_TAG(elementType_, 2);
    }

    const bool& TypeDescription::Array_type::packed() const {
        return *packed_;
    }

    void TypeDescription::Array_type::packed(const bool& vl) {
        packed_ = vl;
    }

    void TypeDescription::Array_type::packed(boost::shared_ptr< bool> vl) {
        packed_ = vl;
    }

    ISO_9506_MMS_1::Unsigned32& TypeDescription::Array_type::numberOfElements() {
        return *numberOfElements_;
    }

    const ISO_9506_MMS_1::Unsigned32& TypeDescription::Array_type::numberOfElements() const {
        return *numberOfElements_;
    }

    void TypeDescription::Array_type::numberOfElements(const ISO_9506_MMS_1::Unsigned32& vl) {
        numberOfElements_ = vl;
    }

    void TypeDescription::Array_type::numberOfElements(boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> vl) {
        numberOfElements_ = vl;
    }

    ISO_9506_MMS_1::TypeSpecification& TypeDescription::Array_type::elementType() {
        return *elementType_;
    }

    const ISO_9506_MMS_1::TypeSpecification& TypeDescription::Array_type::elementType() const {
        return *elementType_;
    }

    void TypeDescription::Array_type::elementType(const ISO_9506_MMS_1::TypeSpecification& vl) {
        elementType_ = vl;
    }

    void TypeDescription::Array_type::elementType(boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> vl) {
        elementType_ = vl;
    }

    TypeDescription::Structure_type::Structure_type() : components_() {
    };

    TypeDescription::Structure_type::Structure_type(const Components_type& arg__components) :
    components_(arg__components) {
    };

    TypeDescription::Structure_type::Structure_type(boost::shared_ptr< bool> arg__packed,
            boost::shared_ptr< Components_type> arg__components) :
    packed_(arg__packed),
    components_(arg__components) {
    };

    TypeDescription::Structure_type::Components_type_sequence_of::Components_type_sequence_of() : componentType_() {
    };

    TypeDescription::Structure_type::Components_type_sequence_of::Components_type_sequence_of(const ISO_9506_MMS_1::TypeSpecification& arg__componentType) :
    componentType_(arg__componentType) {
    };

    TypeDescription::Structure_type::Components_type_sequence_of::Components_type_sequence_of(boost::shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
            boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__componentType) :
    componentName_(arg__componentName),
    componentType_(arg__componentType) {
    };

    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_CHOICE_TAG(componentType_, 1);
    }

    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_CHOICE_TAG(componentType_, 1);
    }

    boost::shared_ptr<ISO_9506_MMS_1::Identifier> TypeDescription::Structure_type::Components_type_sequence_of::componentName__new() {
        return componentName_ = boost::shared_ptr<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier());
    }

    void TypeDescription::Structure_type::Components_type_sequence_of::componentName(const ISO_9506_MMS_1::Identifier& vl) {
        componentName_ = boost::shared_ptr<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier(vl));
    }

    ISO_9506_MMS_1::TypeSpecification& TypeDescription::Structure_type::Components_type_sequence_of::componentType() {
        return *componentType_;
    }

    const ISO_9506_MMS_1::TypeSpecification& TypeDescription::Structure_type::Components_type_sequence_of::componentType() const {
        return *componentType_;
    }

    void TypeDescription::Structure_type::Components_type_sequence_of::componentType(const ISO_9506_MMS_1::TypeSpecification& vl) {
        componentType_ = vl;
    }

    void TypeDescription::Structure_type::Components_type_sequence_of::componentType(boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> vl) {
        componentType_ = vl;
    }


    const bool TypeDescription::Structure_type::packed__default = false;

    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_, 0);
        ITU_T_IMPLICIT_TAG(components_, 1);
    }

    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_, 0);
        ITU_T_IMPLICIT_TAG(components_, 1);
    }

    const bool& TypeDescription::Structure_type::packed() const {
        return *packed_;
    }

    void TypeDescription::Structure_type::packed(const bool& vl) {
        packed_ = vl;
    }

    void TypeDescription::Structure_type::packed(boost::shared_ptr< bool> vl) {
        packed_ = vl;
    }

    TypeDescription::Structure_type::Components_type& TypeDescription::Structure_type::components() {
        return *components_;
    }

    const TypeDescription::Structure_type::Components_type& TypeDescription::Structure_type::components() const {
        return *components_;
    }

    void TypeDescription::Structure_type::components(const Components_type& vl) {
        components_ = vl;
    }

    void TypeDescription::Structure_type::components(boost::shared_ptr< Components_type> vl) {
        components_ = vl;
    }

    TypeDescription::Floating_point_type::Floating_point_type() : format_width_(), exponent_width_() {
    };

    TypeDescription::Floating_point_type::Floating_point_type(const ISO_9506_MMS_1::Unsigned8& arg__format_width,
            const ISO_9506_MMS_1::Unsigned8& arg__exponent_width) :
    format_width_(arg__format_width),
    exponent_width_(arg__exponent_width) {
    };

    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(format_width_);
        ITU_T_BIND_TAG(exponent_width_);
    }

    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(format_width_);
        ITU_T_BIND_TAG(exponent_width_);
    }

    ISO_9506_MMS_1::Unsigned8& TypeDescription::Floating_point_type::format_width() {
        return *format_width_;
    }

    const ISO_9506_MMS_1::Unsigned8& TypeDescription::Floating_point_type::format_width() const {
        return *format_width_;
    }

    void TypeDescription::Floating_point_type::format_width(const ISO_9506_MMS_1::Unsigned8& vl) {
        format_width_ = vl;
    }

    void TypeDescription::Floating_point_type::format_width(boost::shared_ptr< ISO_9506_MMS_1::Unsigned8> vl) {
        format_width_ = vl;
    }

    ISO_9506_MMS_1::Unsigned8& TypeDescription::Floating_point_type::exponent_width() {
        return *exponent_width_;
    }

    const ISO_9506_MMS_1::Unsigned8& TypeDescription::Floating_point_type::exponent_width() const {
        return *exponent_width_;
    }

    void TypeDescription::Floating_point_type::exponent_width(const ISO_9506_MMS_1::Unsigned8& vl) {
        exponent_width_ = vl;
    }

    void TypeDescription::Floating_point_type::exponent_width(boost::shared_ptr< ISO_9506_MMS_1::Unsigned8> vl) {
        exponent_width_ = vl;
    }

    void TypeDescription::boolean(const null_type& vl) {
        set<null_type>(new null_type(vl), TypeDescription_boolean);
    }

    void TypeDescription::bit_string(const ISO_9506_MMS_1::Integer32& vl) {
        set<ISO_9506_MMS_1::Integer32>(new ISO_9506_MMS_1::Integer32(vl), TypeDescription_bit_string);
    }

    void TypeDescription::integer(const ISO_9506_MMS_1::Unsigned8& vl) {
        set<ISO_9506_MMS_1::Unsigned8>(new ISO_9506_MMS_1::Unsigned8(vl), TypeDescription_integer);
    }

    void TypeDescription::unsignedV(const ISO_9506_MMS_1::Unsigned8& vl) {
        set<ISO_9506_MMS_1::Unsigned8>(new ISO_9506_MMS_1::Unsigned8(vl), TypeDescription_unsignedV);
    }

    void TypeDescription::octet_string(const ISO_9506_MMS_1::Integer32& vl) {
        set<ISO_9506_MMS_1::Integer32>(new ISO_9506_MMS_1::Integer32(vl), TypeDescription_octet_string);
    }

    void TypeDescription::visible_string(const ISO_9506_MMS_1::Integer32& vl) {
        set<ISO_9506_MMS_1::Integer32>(new ISO_9506_MMS_1::Integer32(vl), TypeDescription_visible_string);
    }

    void TypeDescription::generalized_time(const null_type& vl) {
        set<null_type>(new null_type(vl), TypeDescription_generalized_time);
    }

    void TypeDescription::binary_time(const bool& vl) {
        set<bool>(new bool(vl), TypeDescription_binary_time);
    }

    void TypeDescription::bcd(const ISO_9506_MMS_1::Unsigned8& vl) {
        set<ISO_9506_MMS_1::Unsigned8>(new ISO_9506_MMS_1::Unsigned8(vl), TypeDescription_bcd);
    }

    void TypeDescription::objId(const null_type& vl) {
        set<null_type>(new null_type(vl), TypeDescription_objId);
    }

    void TypeDescription::mMSString(const ISO_9506_MMS_1::Integer32& vl) {
        set<ISO_9506_MMS_1::Integer32>(new ISO_9506_MMS_1::Integer32(vl), TypeDescription_mMSString);
    }

    template<> void TypeDescription::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case TypeDescription_array:
            {
                ITU_T_IMPLICIT_TAG(value<Array_type > (false, TypeDescription_array), 1);
                break;
            }
            case TypeDescription_structure:
            {
                ITU_T_IMPLICIT_TAG(value<Structure_type > (false, TypeDescription_structure), 2);
                break;
            }
            case TypeDescription_boolean:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, TypeDescription_boolean), 3);
                break;
            }
            case TypeDescription_bit_string:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_bit_string), 4);
                break;
            }
            case TypeDescription_integer:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_integer), 5);
                break;
            }
            case TypeDescription_unsignedV:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_unsignedV), 6);
                break;
            }
            case TypeDescription_floating_point:
            {
                ITU_T_IMPLICIT_TAG(value<Floating_point_type > (false, TypeDescription_floating_point), 7);
                break;
            }
            case TypeDescription_octet_string:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_octet_string), 9);
                break;
            }
            case TypeDescription_visible_string:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_visible_string), 10);
                break;
            }
            case TypeDescription_generalized_time:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, TypeDescription_generalized_time), 11);
                break;
            }
            case TypeDescription_binary_time:
            {
                ITU_T_IMPLICIT_TAG(value<bool > (false, TypeDescription_binary_time), 12);
                break;
            }
            case TypeDescription_bcd:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_bcd), 13);
                break;
            }
            case TypeDescription_objId:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, TypeDescription_objId), 15);
                break;
            }
            case TypeDescription_mMSString:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_mMSString), 16);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void TypeDescription::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<Array_type > (true, TypeDescription_array), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Structure_type > (true, TypeDescription_structure), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, TypeDescription_boolean), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_bit_string), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_integer), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_unsignedV), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<Floating_point_type > (true, TypeDescription_floating_point), 7)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_octet_string), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_visible_string), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, TypeDescription_generalized_time), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<bool > (true, TypeDescription_binary_time), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_bcd), 13)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, TypeDescription_objId), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_mMSString), 16)) return;
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


    const Priority normalPriority = 64;

    const EC_Class eC_Class_network_triggered = 0;
    const EC_Class eC_Class_monitored = 1;

    const EC_State eC_State_disabled = 0;
    const EC_State eC_State_idle = 1;
    const EC_State eC_State_active = 2;

    const Severity normalSeverity = 64;

    // choice EventTime

    void EventTime::timeOfDay(const ISO_9506_MMS_1::TimeOfDay& vl) {
        set<ISO_9506_MMS_1::TimeOfDay>(new ISO_9506_MMS_1::TimeOfDay(vl), EventTime_timeOfDay);
    }

    void EventTime::timeSequenceIdentifier(const ISO_9506_MMS_1::Unsigned32& vl) {
        set<ISO_9506_MMS_1::Unsigned32>(new ISO_9506_MMS_1::Unsigned32(vl), EventTime_timeSequenceIdentifier);
    }

    void EventTime::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), EventTime_undefined);
    }

    template<> void EventTime::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EventTime_timeOfDay:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::TimeOfDay > (false, EventTime_timeOfDay), 0);
                break;
            }
            case EventTime_timeSequenceIdentifier:
            {
                ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (false, EventTime_timeSequenceIdentifier), 1);
                break;
            }
            case EventTime_undefined:
            {
                ITU_T_IMPLICIT_TAG(value<null_type > (false, EventTime_undefined), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EventTime::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::TimeOfDay > (true, EventTime_timeOfDay), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (true, EventTime_timeSequenceIdentifier), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<null_type > (true, EventTime_undefined), 2)) return;
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


    const EE_Class eE_Class_modifier = 0;
    const EE_Class eE_Class_notification = 1;

    const Transitions transitions_idle_to_disabled = bitstring_type(true, 0);
    const Transitions transitions_active_to_disabled = bitstring_type(true, 1);
    const Transitions transitions_disabled_to_idle = bitstring_type(true, 2);
    const Transitions transitions_active_to_idle = bitstring_type(true, 3);
    const Transitions transitions_disabled_to_active = bitstring_type(true, 4);
    const Transitions transitions_idle_to_active = bitstring_type(true, 5);
    const Transitions transitions_any_to_deleted = bitstring_type(true, 6);

    const EE_Duration eE_Duration_current = 0;
    const EE_Duration eE_Duration_permanent = 1;

    const AlarmAckRule alarmAckRule_none = 0;
    const AlarmAckRule alarmAckRule_simple = 1;
    const AlarmAckRule alarmAckRule_ack_active = 2;
    const AlarmAckRule alarmAckRule_ack_all = 3;

    // sequence Journal-Variable

    Journal_Variable::Journal_Variable() : variableTag_(), valueSpecification_() {
    };

    Journal_Variable::Journal_Variable(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
            const ISO_9506_MMS_1::Data& arg__valueSpecification) :
    variableTag_(arg__variableTag),
    valueSpecification_(arg__valueSpecification) {
    };

    template<> void Journal_Variable::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(variableTag_);
        ITU_T_BIND_CHOICE(valueSpecification_);
    }

    template<> void Journal_Variable::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(variableTag_);
        ITU_T_BIND_CHOICE(valueSpecification_);
    }

    ISO_9506_MMS_1::MMS255String& Journal_Variable::variableTag() {
        return *variableTag_;
    }

    const ISO_9506_MMS_1::MMS255String& Journal_Variable::variableTag() const {
        return *variableTag_;
    }

    void Journal_Variable::variableTag(const ISO_9506_MMS_1::MMS255String& vl) {
        variableTag_ = vl;
    }

    void Journal_Variable::variableTag(boost::shared_ptr< ISO_9506_MMS_1::MMS255String> vl) {
        variableTag_ = vl;
    }

    ISO_9506_MMS_1::Data& Journal_Variable::valueSpecification() {
        return *valueSpecification_;
    }

    const ISO_9506_MMS_1::Data& Journal_Variable::valueSpecification() const {
        return *valueSpecification_;
    }

    void Journal_Variable::valueSpecification(const ISO_9506_MMS_1::Data& vl) {
        valueSpecification_ = vl;
    }

    void Journal_Variable::valueSpecification(boost::shared_ptr< ISO_9506_MMS_1::Data> vl) {
        valueSpecification_ = vl;
    }


    const boost::array<boost::asn1::oidindx_type, 6> mMSNamedVariable_OID_ARR = {1, 0, 9506, 1, 5, 1};
    const oid_type mMSNamedVariable = boost::asn1::oid_type(mMSNamedVariable_OID_ARR);

    const boost::array<boost::asn1::oidindx_type, 6> mMSAccessControlList_OID_ARR = {1, 0, 9506, 1, 5, 2};
    const oid_type mMSAccessControlList = boost::asn1::oid_type(mMSAccessControlList_OID_ARR);

    const boost::array<boost::asn1::oidindx_type, 6> mMSEventCondition_OID_ARR = {1, 0, 9506, 1, 5, 3};
    const oid_type mMSEventCondition = boost::asn1::oid_type(mMSEventCondition_OID_ARR);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

