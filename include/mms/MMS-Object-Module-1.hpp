#ifndef ___MMS_OBJECT_MODULE_1
#define ___MMS_OBJECT_MODULE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {

    ITU_T_USE_UNIVESAL_DECL;


    struct ModifierStep;
    struct Modifier;
    struct AccessCondition;
    struct Address;
    struct TypeDescription;
    struct EventTime;
    struct Journal_Variable;


    typedef uint8_t VMDState; //   Ic(  [ 0  ...   5 ]   
    typedef bit_string ServiceSupportOptions; //    Sc (  [ 93 ]   
    typedef bit_string ParameterSupportOptions; //    Sc (  [ 18 ]   
    typedef bit_string AdditionalSupportOptions; //    Sc (  [ 23 ]   
    typedef bit_string AdditionalCBBOptions; //    Sc (  [ 3 ]   
    typedef uint8_t DomainState; //   Ic(  [ 0  ...   15 ]   
    typedef uint8_t ULState; //   Ic(  [ 0  ...   6 ]   
    typedef uint8_t ProgramInvocationState; //   Ic(  [ 0  ...   8 ]   
    typedef uint8_t Control_State; //   Ic(  [ 0  ...   2 ]   
    typedef uint8_t Running_Mode; //   Ic(  [ 0  ...   2 ]   
    typedef uint8_t Priority; //   Ic(  [ 0  ...   127 ]   
    typedef uint8_t EC_Class; //   Ic(  [ 0  ...   1 ]   
    typedef uint8_t EC_State; //   Ic(  [ 0  ...   2 ]   
    typedef uint8_t Severity; //   Ic(  [ 0  ...   127 ]   
    typedef uint8_t EE_Class; //   Ic(  [ 0  ...   1 ]   
    typedef bit_string Transitions; //    Sc (  [ 7 ]   
    typedef uint8_t EE_Duration; //   Ic(  [ 0  ...   1 ]   
    typedef uint8_t AlarmAckRule; //   Ic(  [ 0  ...   3 ]   
    typedef uint8_t LogicalStatus;
    ITU_T_PREFIXED_DECLARE(LogicalStatus, ITU_T_ARRAY(prefixed_type(0, CONTEXT_CLASS)), false); //  initial =implicit  //   Ic(  [ 0  ...   3 ]   
    typedef uint8_t PhysicalStatus;
    ITU_T_PREFIXED_DECLARE(PhysicalStatus, ITU_T_ARRAY(prefixed_type(1, CONTEXT_CLASS)), false); //  initial =implicit  //   Ic(  [ 0  ...   3 ]   

    const Priority normalPriority = 64;

    const Severity normalSeverity = 64;

    ITU_T_OID(mMSNamedVariable, ITU_T_VARRAY(1, 0, 9506, 1, 5, 1));
    ITU_T_OID(mMSAccessControlList, ITU_T_VARRAY(1, 0, 9506, 1, 5, 2));
    ITU_T_OID(mMSEventCondition, ITU_T_VARRAY(1, 0, 9506, 1, 5, 3));

}

#include <mms/MMS-Environment-1.hpp>
#include <boost/itu/x22X/acse/ACSE-1.hpp>
#include <mms/ISO-9506-MMS-1.hpp>

namespace MMS_Object_Module_1 {

    // import   from  MMS-Environment-1

    using MMS_Environment_1::ApplicationReference;


    // import   from  ACSE-1



    // import   from  ISO-9506-MMS-1

    using ISO_9506_MMS_1::AlternateAccess;
    using ISO_9506_MMS_1::ConfirmedServiceRequest;
    using ISO_9506_MMS_1::AttachToSemaphore;
    using ISO_9506_MMS_1::AttachToEventCondition;
    using ISO_9506_MMS_1::Data;
    using ISO_9506_MMS_1::Identifier;
    using ISO_9506_MMS_1::Integer8;
    using ISO_9506_MMS_1::Integer32;
    using ISO_9506_MMS_1::MMSString;
    using ISO_9506_MMS_1::MMS255String;
    using ISO_9506_MMS_1::ObjectName;
    using ISO_9506_MMS_1::TimeOfDay;
    using ISO_9506_MMS_1::TypeSpecification;
    using ISO_9506_MMS_1::Unsigned32;
    using ISO_9506_MMS_1::Unsigned8;


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

    struct ModifierStep {

        ModifierStep();

        ModifierStep(const integer_type& arg__modifierID,
                const Modifier& arg__modifier);

        ITU_T_HOLDERH_DECL(modifierID, integer_type);
        ITU_T_HOLDERH_DECL(modifier, Modifier);

        ITU_T_ARCHIVE_FUNC;
    };

    // choice Modifier

    enum Modifier_enum {

        Modifier_null = 0,
        Modifier_eventModifier,
        Modifier_semaphoreModifier,
    };

    struct Modifier : public ITU_T_CHOICE(Modifier_enum) {


        ITU_T_CHOICE_CTORS(Modifier);

        ITU_T_CHOICEC_DECL(eventModifier, ISO_9506_MMS_1::AttachToEventCondition, Modifier_eventModifier);
        ITU_T_CHOICEC_DECL(semaphoreModifier, ISO_9506_MMS_1::AttachToSemaphore, Modifier_semaphoreModifier);

        ITU_T_ARCHIVE_FUNC;
    };

    const ServiceSupportOptions serviceSupportOptions_status = bit_string(true, 0);
    const ServiceSupportOptions serviceSupportOptions_getNameList = bit_string(true, 1);
    const ServiceSupportOptions serviceSupportOptions_identify = bit_string(true, 2);
    const ServiceSupportOptions serviceSupportOptions_rename = bit_string(true, 3);
    const ServiceSupportOptions serviceSupportOptions_read = bit_string(true, 4);
    const ServiceSupportOptions serviceSupportOptions_write = bit_string(true, 5);
    const ServiceSupportOptions serviceSupportOptions_getVariableAccessAttributes = bit_string(true, 6);
    const ServiceSupportOptions serviceSupportOptions_defineNamedVariable = bit_string(true, 7);
    const ServiceSupportOptions serviceSupportOptions_defineScatteredAccess = bit_string(true, 8);
    const ServiceSupportOptions serviceSupportOptions_getScatteredAccessAttributes = bit_string(true, 9);
    const ServiceSupportOptions serviceSupportOptions_deleteVariableAccess = bit_string(true, 10);
    const ServiceSupportOptions serviceSupportOptions_defineNamedVariableList = bit_string(true, 11);
    const ServiceSupportOptions serviceSupportOptions_getNamedVariableListAttributes = bit_string(true, 12);
    const ServiceSupportOptions serviceSupportOptions_deleteNamedVariableList = bit_string(true, 13);
    const ServiceSupportOptions serviceSupportOptions_defineNamedType = bit_string(true, 14);
    const ServiceSupportOptions serviceSupportOptions_getNamedTypeAttributes = bit_string(true, 15);
    const ServiceSupportOptions serviceSupportOptions_deleteNamedType = bit_string(true, 16);
    const ServiceSupportOptions serviceSupportOptions_input = bit_string(true, 17);
    const ServiceSupportOptions serviceSupportOptions_output = bit_string(true, 18);
    const ServiceSupportOptions serviceSupportOptions_takeControl = bit_string(true, 19);
    const ServiceSupportOptions serviceSupportOptions_relinquishControl = bit_string(true, 20);
    const ServiceSupportOptions serviceSupportOptions_defineSemaphore = bit_string(true, 21);
    const ServiceSupportOptions serviceSupportOptions_deleteSemaphore = bit_string(true, 22);
    const ServiceSupportOptions serviceSupportOptions_reportSemaphoreStatus = bit_string(true, 23);
    const ServiceSupportOptions serviceSupportOptions_reportPoolSemaphoreStatus = bit_string(true, 24);
    const ServiceSupportOptions serviceSupportOptions_reportSemaphoreEntryStatus = bit_string(true, 25);
    const ServiceSupportOptions serviceSupportOptions_initiateDownloadSequence = bit_string(true, 26);
    const ServiceSupportOptions serviceSupportOptions_downloadSegment = bit_string(true, 27);
    const ServiceSupportOptions serviceSupportOptions_terminateDownloadSequence = bit_string(true, 28);
    const ServiceSupportOptions serviceSupportOptions_initiateUploadSequence = bit_string(true, 29);
    const ServiceSupportOptions serviceSupportOptions_uploadSegment = bit_string(true, 30);
    const ServiceSupportOptions serviceSupportOptions_terminateUploadSequence = bit_string(true, 31);
    const ServiceSupportOptions serviceSupportOptions_requestDomainDownload = bit_string(true, 32);
    const ServiceSupportOptions serviceSupportOptions_requestDomainUpload = bit_string(true, 33);
    const ServiceSupportOptions serviceSupportOptions_loadDomainContent = bit_string(true, 34);
    const ServiceSupportOptions serviceSupportOptions_storeDomainContent = bit_string(true, 35);
    const ServiceSupportOptions serviceSupportOptions_deleteDomain = bit_string(true, 36);
    const ServiceSupportOptions serviceSupportOptions_getDomainAttributes = bit_string(true, 37);
    const ServiceSupportOptions serviceSupportOptions_createProgramInvocation = bit_string(true, 38);
    const ServiceSupportOptions serviceSupportOptions_deleteProgramInvocation = bit_string(true, 39);
    const ServiceSupportOptions serviceSupportOptions_start = bit_string(true, 40);
    const ServiceSupportOptions serviceSupportOptions_stop = bit_string(true, 41);
    const ServiceSupportOptions serviceSupportOptions_resume = bit_string(true, 42);
    const ServiceSupportOptions serviceSupportOptions_reset = bit_string(true, 43);
    const ServiceSupportOptions serviceSupportOptions_kill = bit_string(true, 44);
    const ServiceSupportOptions serviceSupportOptions_getProgramInvocationAttributes = bit_string(true, 45);
    const ServiceSupportOptions serviceSupportOptions_obtainFile = bit_string(true, 46);
    const ServiceSupportOptions serviceSupportOptions_defineEventCondition = bit_string(true, 47);
    const ServiceSupportOptions serviceSupportOptions_deleteEventCondition = bit_string(true, 48);
    const ServiceSupportOptions serviceSupportOptions_getEventConditionAttributes = bit_string(true, 49);
    const ServiceSupportOptions serviceSupportOptions_reportEventConditionStatus = bit_string(true, 50);
    const ServiceSupportOptions serviceSupportOptions_alterEventConditionMonitoring = bit_string(true, 51);
    const ServiceSupportOptions serviceSupportOptions_triggerEvent = bit_string(true, 52);
    const ServiceSupportOptions serviceSupportOptions_defineEventAction = bit_string(true, 53);
    const ServiceSupportOptions serviceSupportOptions_deleteEventAction = bit_string(true, 54);
    const ServiceSupportOptions serviceSupportOptions_getEventActionAttributes = bit_string(true, 55);
    const ServiceSupportOptions serviceSupportOptions_reportEventActionStatus = bit_string(true, 56);
    const ServiceSupportOptions serviceSupportOptions_defineEventEnrollment = bit_string(true, 57);
    const ServiceSupportOptions serviceSupportOptions_deleteEventEnrollment = bit_string(true, 58);
    const ServiceSupportOptions serviceSupportOptions_alterEventEnrollment = bit_string(true, 59);
    const ServiceSupportOptions serviceSupportOptions_reportEventEnrollmentStatus = bit_string(true, 60);
    const ServiceSupportOptions serviceSupportOptions_getEventEnrollmentAttributes = bit_string(true, 61);
    const ServiceSupportOptions serviceSupportOptions_acknowledgeEventNotification = bit_string(true, 62);
    const ServiceSupportOptions serviceSupportOptions_getAlarmSummary = bit_string(true, 63);
    const ServiceSupportOptions serviceSupportOptions_getAlarmEnrollmentSummary = bit_string(true, 64);
    const ServiceSupportOptions serviceSupportOptions_readJournal = bit_string(true, 65);
    const ServiceSupportOptions serviceSupportOptions_writeJournal = bit_string(true, 66);
    const ServiceSupportOptions serviceSupportOptions_initializeJournal = bit_string(true, 67);
    const ServiceSupportOptions serviceSupportOptions_reportJournalStatus = bit_string(true, 68);
    const ServiceSupportOptions serviceSupportOptions_createJournal = bit_string(true, 69);
    const ServiceSupportOptions serviceSupportOptions_deleteJournal = bit_string(true, 70);
    const ServiceSupportOptions serviceSupportOptions_getCapabilityList = bit_string(true, 71);
    const ServiceSupportOptions serviceSupportOptions_fileOpen = bit_string(true, 72);
    const ServiceSupportOptions serviceSupportOptions_fileRead = bit_string(true, 73);
    const ServiceSupportOptions serviceSupportOptions_fileClose = bit_string(true, 74);
    const ServiceSupportOptions serviceSupportOptions_fileRename = bit_string(true, 75);
    const ServiceSupportOptions serviceSupportOptions_fileDelete = bit_string(true, 76);
    const ServiceSupportOptions serviceSupportOptions_fileDirectory = bit_string(true, 77);
    const ServiceSupportOptions serviceSupportOptions_unsolicitedStatus = bit_string(true, 78);
    const ServiceSupportOptions serviceSupportOptions_informationReport = bit_string(true, 79);
    const ServiceSupportOptions serviceSupportOptions_eventNotification = bit_string(true, 80);
    const ServiceSupportOptions serviceSupportOptions_attachToEventCondition = bit_string(true, 81);
    const ServiceSupportOptions serviceSupportOptions_attachToSemaphore = bit_string(true, 82);
    const ServiceSupportOptions serviceSupportOptions_conclude = bit_string(true, 83);
    const ServiceSupportOptions serviceSupportOptions_cancel = bit_string(true, 84);
    const ServiceSupportOptions serviceSupportOptions_getDataExchangeAttributes = bit_string(true, 85);
    const ServiceSupportOptions serviceSupportOptions_exchangeData = bit_string(true, 86);
    const ServiceSupportOptions serviceSupportOptions_defineAccessControlList = bit_string(true, 87);
    const ServiceSupportOptions serviceSupportOptions_getAccessControlListAttributes = bit_string(true, 88);
    const ServiceSupportOptions serviceSupportOptions_reportAccessControlledObjects = bit_string(true, 89);
    const ServiceSupportOptions serviceSupportOptions_deleteAccessControlList = bit_string(true, 90);
    const ServiceSupportOptions serviceSupportOptions_alterAccessControl = bit_string(true, 91);
    const ServiceSupportOptions serviceSupportOptions_reconfigureProgramInvocation = bit_string(true, 92);

    const ParameterSupportOptions parameterSupportOptions_str1 = bit_string(true, 0);
    const ParameterSupportOptions parameterSupportOptions_str2 = bit_string(true, 1);
    const ParameterSupportOptions parameterSupportOptions_vnam = bit_string(true, 2);
    const ParameterSupportOptions parameterSupportOptions_valt = bit_string(true, 3);
    const ParameterSupportOptions parameterSupportOptions_vadr = bit_string(true, 4);
    const ParameterSupportOptions parameterSupportOptions_vsca = bit_string(true, 5);
    const ParameterSupportOptions parameterSupportOptions_tpy = bit_string(true, 6);
    const ParameterSupportOptions parameterSupportOptions_vlis = bit_string(true, 7);
    const ParameterSupportOptions parameterSupportOptions_cei = bit_string(true, 10);
    const ParameterSupportOptions parameterSupportOptions_aco = bit_string(true, 11);
    const ParameterSupportOptions parameterSupportOptions_sem = bit_string(true, 12);
    const ParameterSupportOptions parameterSupportOptions_csr = bit_string(true, 13);
    const ParameterSupportOptions parameterSupportOptions_csnc = bit_string(true, 14);
    const ParameterSupportOptions parameterSupportOptions_csplc = bit_string(true, 15);
    const ParameterSupportOptions parameterSupportOptions_cspi = bit_string(true, 16);
    const ParameterSupportOptions parameterSupportOptions_char = bit_string(true, 17);

    const AdditionalSupportOptions additionalSupportOptions_vMDStop = bit_string(true, 0);
    const AdditionalSupportOptions additionalSupportOptions_vMDReset = bit_string(true, 1);
    const AdditionalSupportOptions additionalSupportOptions_select = bit_string(true, 2);
    const AdditionalSupportOptions additionalSupportOptions_alterProgramInvocationAttributes = bit_string(true, 3);
    const AdditionalSupportOptions additionalSupportOptions_initiateUnitControlLoad = bit_string(true, 4);
    const AdditionalSupportOptions additionalSupportOptions_unitControlLoadSegment = bit_string(true, 5);
    const AdditionalSupportOptions additionalSupportOptions_unitControlUpload = bit_string(true, 6);
    const AdditionalSupportOptions additionalSupportOptions_startUnitControl = bit_string(true, 7);
    const AdditionalSupportOptions additionalSupportOptions_stopUnitControl = bit_string(true, 8);
    const AdditionalSupportOptions additionalSupportOptions_createUnitControl = bit_string(true, 9);
    const AdditionalSupportOptions additionalSupportOptions_addToUnitControl = bit_string(true, 10);
    const AdditionalSupportOptions additionalSupportOptions_removeFromUnitControl = bit_string(true, 11);
    const AdditionalSupportOptions additionalSupportOptions_getUnitControlAttributes = bit_string(true, 12);
    const AdditionalSupportOptions additionalSupportOptions_loadUnitControlFromFile = bit_string(true, 13);
    const AdditionalSupportOptions additionalSupportOptions_storeUnitControlToFile = bit_string(true, 14);
    const AdditionalSupportOptions additionalSupportOptions_deleteUnitControl = bit_string(true, 15);
    const AdditionalSupportOptions additionalSupportOptions_defineEventConditionList = bit_string(true, 16);
    const AdditionalSupportOptions additionalSupportOptions_deleteEventConditionList = bit_string(true, 17);
    const AdditionalSupportOptions additionalSupportOptions_addEventConditionListReference = bit_string(true, 18);
    const AdditionalSupportOptions additionalSupportOptions_removeEventConditionListReference = bit_string(true, 19);
    const AdditionalSupportOptions additionalSupportOptions_getEventConditionListAttributes = bit_string(true, 20);
    const AdditionalSupportOptions additionalSupportOptions_reportEventConditionListStatus = bit_string(true, 21);
    const AdditionalSupportOptions additionalSupportOptions_alterEventConditionListMonitoring = bit_string(true, 22);

    const AdditionalCBBOptions additionalCBBOptions_des = bit_string(true, 0);
    const AdditionalCBBOptions additionalCBBOptions_dei = bit_string(true, 1);
    const AdditionalCBBOptions additionalCBBOptions_recl = bit_string(true, 2);

    // choice AccessCondition

    enum AccessCondition_enum {

        AccessCondition_null = 0,
        AccessCondition_never,
        AccessCondition_semaphore,
        AccessCondition_user,
        AccessCondition_password,
        AccessCondition_joint,
        AccessCondition_alternate,
    };

    struct AccessCondition : public ITU_T_CHOICE(AccessCondition_enum) {


        struct User_type;

        enum User_type_enum {

            User_type_null = 0,
            User_type_association,
            User_type_none,
        };

        struct User_type : public ITU_T_CHOICE(User_type_enum) {


            ITU_T_CHOICE_CTORS(User_type);

            ITU_T_CHOICEC_DECL(association, MMS_Environment_1::ApplicationReference, User_type_association);
            ITU_T_CHOICES_DECL(none, null_type, User_type_none); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< AccessCondition > Joint_type;
        typedef sequence_of< AccessCondition > Alternate_type;


        ITU_T_CHOICE_CTORS(AccessCondition);

        ITU_T_CHOICES_DECL(never, null_type, AccessCondition_never); // primitive
        ITU_T_CHOICES_DECL(semaphore, ISO_9506_MMS_1::Identifier, AccessCondition_semaphore); // primitive
        ITU_T_CHOICEC_DECL(user, User_type, AccessCondition_user);
        ITU_T_CHOICEC_DECL(password, ACSE_1::Authentication_value, AccessCondition_password);
        ITU_T_CHOICEC_DECL(joint, Joint_type, AccessCondition_joint);
        ITU_T_CHOICEC_DECL(alternate, Alternate_type, AccessCondition_alternate);

        ITU_T_ARCHIVE_FUNC;
    };

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

    enum Address_enum {

        Address_null = 0,
        Address_numericAddress,
        Address_symbolicAddress,
        Address_unconstrainedAddress,
    };

    struct Address : public ITU_T_CHOICE(Address_enum) {


        ITU_T_CHOICE_CTORS(Address);

        ITU_T_CHOICES_DECL(numericAddress, ISO_9506_MMS_1::Unsigned32, Address_numericAddress); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(symbolicAddress, ISO_9506_MMS_1::MMSString, Address_symbolicAddress); // primitive
        ITU_T_CHOICES_DECL(unconstrainedAddress, octet_string, Address_unconstrainedAddress); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice TypeDescription

    enum TypeDescription_enum {

        TypeDescription_null = 0,
        TypeDescription_array,
        TypeDescription_structure,
        TypeDescription_boolean,
        TypeDescription_bit_stringV,
        TypeDescription_integer,
        TypeDescription_unsignedV,
        TypeDescription_floating_point,
        TypeDescription_octet_stringV,
        TypeDescription_visible_stringV,
        TypeDescription_generalized_time,
        TypeDescription_binary_time,
        TypeDescription_bcd,
        TypeDescription_objId,
        TypeDescription_mMSString,
    };

    struct TypeDescription : public ITU_T_CHOICE(TypeDescription_enum) {


        struct Array_type;
        struct Structure_type;
        struct Floating_point_type;

        struct Array_type {

            static const bool packed__default;

            Array_type();

            Array_type(const ISO_9506_MMS_1::Unsigned32& arg__numberOfElements,
                    const ISO_9506_MMS_1::TypeSpecification& arg__elementType);

            Array_type(shared_ptr< bool> arg__packed,
                    shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__numberOfElements,
                    shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__elementType);

            ITU_T_DEFAULTH_DECL(packed, bool, packed__default);
            ITU_T_HOLDERH_DECL(numberOfElements, ISO_9506_MMS_1::Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
            ITU_T_HOLDERH_DECL(elementType, ISO_9506_MMS_1::TypeSpecification);

            ITU_T_ARCHIVE_FUNC;
        };

        struct Structure_type {

            struct Components_type_sequence_of;

            struct Components_type_sequence_of {

                Components_type_sequence_of();

                Components_type_sequence_of(const ISO_9506_MMS_1::TypeSpecification& arg__componentType);

                Components_type_sequence_of(shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
                        shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__componentType);

                ITU_T_OPTIONAL_DECL(componentName, ISO_9506_MMS_1::Identifier);
                ITU_T_HOLDERH_DECL(componentType, ISO_9506_MMS_1::TypeSpecification);

                ITU_T_ARCHIVE_FUNC;
            };



            typedef sequence_of< Components_type_sequence_of > Components_type;

            static const bool packed__default;

            Structure_type();

            Structure_type(const Components_type& arg__components);

            Structure_type(shared_ptr< bool> arg__packed,
                    shared_ptr< Components_type> arg__components);

            ITU_T_DEFAULTH_DECL(packed, bool, packed__default);
            ITU_T_HOLDERH_DECL(components, Components_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct Floating_point_type {

            Floating_point_type();

            Floating_point_type(const ISO_9506_MMS_1::Unsigned8& arg__format_width,
                    const ISO_9506_MMS_1::Unsigned8& arg__exponent_width);

            ITU_T_HOLDERH_DECL(format_width, ISO_9506_MMS_1::Unsigned8); //   Ic(  [ 0  ...   127 ]   
            ITU_T_HOLDERH_DECL(exponent_width, ISO_9506_MMS_1::Unsigned8); //   Ic(  [ 0  ...   127 ]   

            ITU_T_ARCHIVE_FUNC;
        };


        ITU_T_CHOICE_CTORS(TypeDescription);

        ITU_T_CHOICEC_DECL(array, Array_type, TypeDescription_array);
        ITU_T_CHOICEC_DECL(structure, Structure_type, TypeDescription_structure);
        ITU_T_CHOICES_DECL(boolean, null_type, TypeDescription_boolean); // primitive
        ITU_T_CHOICES_DECL(bit_stringV, ISO_9506_MMS_1::Integer32, TypeDescription_bit_stringV); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(integer, ISO_9506_MMS_1::Unsigned8, TypeDescription_integer); // primitive  //   Ic(  [ 0  ...   127 ]   
        ITU_T_CHOICES_DECL(unsignedV, ISO_9506_MMS_1::Unsigned8, TypeDescription_unsignedV); // primitive  //   Ic(  [ 0  ...   127 ]   
        ITU_T_CHOICEC_DECL(floating_point, Floating_point_type, TypeDescription_floating_point);
        ITU_T_CHOICES_DECL(octet_stringV, ISO_9506_MMS_1::Integer32, TypeDescription_octet_stringV); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(visible_stringV, ISO_9506_MMS_1::Integer32, TypeDescription_visible_stringV); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(generalized_time, null_type, TypeDescription_generalized_time); // primitive
        ITU_T_CHOICES_DECL(binary_time, bool, TypeDescription_binary_time); // primitive
        ITU_T_CHOICES_DECL(bcd, ISO_9506_MMS_1::Unsigned8, TypeDescription_bcd); // primitive  //   Ic(  [ 0  ...   127 ]   
        ITU_T_CHOICES_DECL(objId, null_type, TypeDescription_objId); // primitive
        ITU_T_CHOICES_DECL(mMSString, ISO_9506_MMS_1::Integer32, TypeDescription_mMSString); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    const EC_Class eC_Class_network_triggered = 0;
    const EC_Class eC_Class_monitored = 1;

    const EC_State eC_State_disabled = 0;
    const EC_State eC_State_idle = 1;
    const EC_State eC_State_active = 2;

    // choice EventTime

    enum EventTime_enum {

        EventTime_null = 0,
        EventTime_timeOfDay,
        EventTime_timeSequenceIdentifier,
        EventTime_undefined,
    };

    struct EventTime : public ITU_T_CHOICE(EventTime_enum) {


        ITU_T_CHOICE_CTORS(EventTime);

        ITU_T_CHOICES_DECL(timeOfDay, ISO_9506_MMS_1::TimeOfDay, EventTime_timeOfDay); // primitive  //    Sc (  [ 4  ...   6 ]   
        ITU_T_CHOICES_DECL(timeSequenceIdentifier, ISO_9506_MMS_1::Unsigned32, EventTime_timeSequenceIdentifier); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(undefined, null_type, EventTime_undefined); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    const EE_Class eE_Class_modifier = 0;
    const EE_Class eE_Class_notification = 1;

    const Transitions transitions_idle_to_disabled = bit_string(true, 0);
    const Transitions transitions_active_to_disabled = bit_string(true, 1);
    const Transitions transitions_disabled_to_idle = bit_string(true, 2);
    const Transitions transitions_active_to_idle = bit_string(true, 3);
    const Transitions transitions_disabled_to_active = bit_string(true, 4);
    const Transitions transitions_idle_to_active = bit_string(true, 5);
    const Transitions transitions_any_to_deleted = bit_string(true, 6);

    const EE_Duration eE_Duration_current = 0;
    const EE_Duration eE_Duration_permanent = 1;

    const AlarmAckRule alarmAckRule_none = 0;
    const AlarmAckRule alarmAckRule_simple = 1;
    const AlarmAckRule alarmAckRule_ack_active = 2;
    const AlarmAckRule alarmAckRule_ack_all = 3;

    // sequence Journal-Variable

    struct Journal_Variable {

        Journal_Variable();

        Journal_Variable(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
                const ISO_9506_MMS_1::Data& arg__valueSpecification);

        ITU_T_HOLDERH_DECL(variableTag, ISO_9506_MMS_1::MMS255String);
        ITU_T_HOLDERH_DECL(valueSpecification, ISO_9506_MMS_1::Data);

        ITU_T_ARCHIVE_FUNC;
    };

    ITU_T_ARCHIVE_X690_DECL(ModifierStep);
    ITU_T_ARCHIVE_X690_DECL(Modifier);
    ITU_T_ARCHIVE_X690_DECL(AccessCondition);
    ITU_T_ARCHIVE_X690_DECL(AccessCondition::User_type);
    ITU_T_ARCHIVE_X690_DECL(Address);
    ITU_T_ARCHIVE_X690_DECL(TypeDescription);
    ITU_T_ARCHIVE_X690_DECL(TypeDescription::Array_type);
    ITU_T_ARCHIVE_X690_DECL(TypeDescription::Structure_type);
    ITU_T_ARCHIVE_X690_DECL(TypeDescription::Structure_type::Components_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(TypeDescription::Floating_point_type);
    ITU_T_ARCHIVE_X690_DECL(EventTime);
    ITU_T_ARCHIVE_X690_DECL(Journal_Variable);

    ITU_T_ARCHIVE_X691_DECL(ModifierStep);
    ITU_T_ARCHIVE_X691_DECL(Modifier);
    ITU_T_ARCHIVE_X691_DECL(AccessCondition);
    ITU_T_ARCHIVE_X691_DECL(AccessCondition::User_type);
    ITU_T_ARCHIVE_X691_DECL(Address);
    ITU_T_ARCHIVE_X691_DECL(TypeDescription);
    ITU_T_ARCHIVE_X691_DECL(TypeDescription::Array_type);
    ITU_T_ARCHIVE_X691_DECL(TypeDescription::Structure_type);
    ITU_T_ARCHIVE_X691_DECL(TypeDescription::Structure_type::Components_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(TypeDescription::Floating_point_type);
    ITU_T_ARCHIVE_X691_DECL(EventTime);
    ITU_T_ARCHIVE_X691_DECL(Journal_Variable);

}

ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::Modifier)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition::User_type)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::Address)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::TypeDescription)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::EventTime)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___MMS_OBJECT_MODULE_1 */
