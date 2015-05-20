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
    typedef bitstring_type ServiceSupportOptions; //    Sc (  [ 93 ]   
    typedef bitstring_type ParameterSupportOptions; //    Sc (  [ 18 ]   
    typedef bitstring_type AdditionalSupportOptions; //    Sc (  [ 23 ]   
    typedef bitstring_type AdditionalCBBOptions; //    Sc (  [ 3 ]   
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
    typedef bitstring_type Transitions; //    Sc (  [ 7 ]   
    typedef uint8_t EE_Duration; //   Ic(  [ 0  ...   1 ]   
    typedef uint8_t AlarmAckRule; //   Ic(  [ 0  ...   3 ]   
    ITU_T_IMPLICIT_TYPEDEF(LogicalStatus, uint8_t, 0, CONTEXT_CLASS); //   Ic(  [ 0  ...   3 ]   
    ITU_T_IMPLICIT_TYPEDEF(PhysicalStatus, uint8_t, 1, CONTEXT_CLASS); //   Ic(  [ 0  ...   3 ]   

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

        ModifierStep(const int& arg__modifierID,
                const Modifier& arg__modifier);

        ITU_T_HOLDERH_DECL(modifierID, int);
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



        typedef std::vector< AccessCondition > Joint_type;
        typedef std::vector< AccessCondition > Alternate_type;


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
        ITU_T_CHOICES_DECL(unconstrainedAddress, octetstring_type, Address_unconstrainedAddress); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    // choice TypeDescription

    enum TypeDescription_enum {

        TypeDescription_null = 0,
        TypeDescription_array,
        TypeDescription_structure,
        TypeDescription_boolean,
        TypeDescription_bit_string,
        TypeDescription_integer,
        TypeDescription_unsignedV,
        TypeDescription_floating_point,
        TypeDescription_octet_string,
        TypeDescription_visible_string,
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



            typedef std::vector< Components_type_sequence_of > Components_type;

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
        ITU_T_CHOICES_DECL(bit_string, ISO_9506_MMS_1::Integer32, TypeDescription_bit_string); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(integer, ISO_9506_MMS_1::Unsigned8, TypeDescription_integer); // primitive  //   Ic(  [ 0  ...   127 ]   
        ITU_T_CHOICES_DECL(unsignedV, ISO_9506_MMS_1::Unsigned8, TypeDescription_unsignedV); // primitive  //   Ic(  [ 0  ...   127 ]   
        ITU_T_CHOICEC_DECL(floating_point, Floating_point_type, TypeDescription_floating_point);
        ITU_T_CHOICES_DECL(octet_string, ISO_9506_MMS_1::Integer32, TypeDescription_octet_string); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(visible_string, ISO_9506_MMS_1::Integer32, TypeDescription_visible_string); // primitive  //   Ic(  [ -2147483648  ...   2147483647 ]   
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
