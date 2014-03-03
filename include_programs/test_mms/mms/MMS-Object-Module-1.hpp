#ifndef ___MMS_OBJECT_MODULE_1
#define ___MMS_OBJECT_MODULE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {

    using boost::asn1::null_type;
    using boost::asn1::enumerated_type;
    using boost::asn1::bitstring_type;
    using boost::asn1::octetstring_type;
    using boost::asn1::oid_type;
    using boost::asn1::reloid_type;
    using boost::asn1::utctime_type;
    using boost::asn1::gentime_type;
    using boost::asn1::ia5string_type;
    using boost::asn1::printablestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::numericstring_type;
    using boost::asn1::universalstring_type;
    using boost::asn1::bmpstring_type;
    using boost::asn1::utf8string_type;
    using boost::asn1::generalstring_type;
    using boost::asn1::graphicstring_type;
    using boost::asn1::t61string_type;
    using boost::asn1::t61string_type;
    using boost::asn1::videotexstring_type;
    using boost::asn1::objectdescriptor_type;
    using boost::asn1::external_type;
    using boost::asn1::embeded_type;
    using boost::asn1::characterstring_type;
    using boost::asn1::any_type;
    using boost::asn1::value_holder;
    using boost::asn1::default_holder;


    struct ModifierStep;
    struct Modifier;
    struct AccessCondition;
    struct Address;
    struct TypeDescription;
    struct EventTime;
    struct Journal_Variable;


    typedef int VMDState;
    typedef bitstring_type ServiceSupportOptions;
    typedef bitstring_type ParameterSupportOptions;
    typedef bitstring_type AdditionalSupportOptions;
    typedef bitstring_type AdditionalCBBOptions;
    typedef int DomainState;
    typedef int ULState;
    typedef int ProgramInvocationState;
    typedef int Control_State;
    typedef int Running_Mode;
    typedef int Priority;
    typedef int EC_Class;
    typedef int EC_State;
    typedef int Severity;
    typedef int EE_Class;
    typedef bitstring_type Transitions;
    typedef int EE_Duration;
    typedef int AlarmAckRule;
    ITU_T_IMPLICIT_TYPEDEF(LogicalStatus, int, 0, CONTEXT_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(PhysicalStatus, int, 1, CONTEXT_CLASS);

    extern const Priority normalPriority;
    extern const Severity normalSeverity;
    extern const oid_type mMSNamedVariable;
    extern const oid_type mMSAccessControlList;
    extern const oid_type mMSEventCondition;

}

#include "MMS-Environment-1.hpp"
#include <boost/itu/x22X/acse/ACSE-1.hpp>
#include "ISO-9506-MMS-1.hpp"

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


    extern const LogicalStatus LogicalStatus_state_changes_allowed;
    extern const LogicalStatus LogicalStatus_no_state_changes_allowed;
    extern const LogicalStatus LogicalStatus_limited_services_permitted;
    extern const LogicalStatus LogicalStatus_support_services_allowed;

    extern const PhysicalStatus PhysicalStatus_operational;
    extern const PhysicalStatus PhysicalStatus_partially_operational;
    extern const PhysicalStatus PhysicalStatus_inoperable;
    extern const PhysicalStatus PhysicalStatus_needs_commissioning;

    extern const VMDState VMDState_idle;
    extern const VMDState VMDState_loaded;
    extern const VMDState VMDState_ready;
    extern const VMDState VMDState_executing;
    extern const VMDState VMDState_motion_paused;
    extern const VMDState VMDState_manualInterventionRequired;

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

    struct Modifier : public ITU_T_STRUCT(Modifier_enum) {

        Modifier() : ITU_T_STRUCT(Modifier_enum) () {
        }

        template<typename T > Modifier(boost::shared_ptr< T> vl, Modifier_enum enm) :
                ITU_T_STRUCT(Modifier_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(eventModifier, ISO_9506_MMS_1::AttachToEventCondition, Modifier_eventModifier);
        ITU_T_CHOICE_DECL(semaphoreModifier, ISO_9506_MMS_1::AttachToSemaphore, Modifier_semaphoreModifier);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const ServiceSupportOptions ServiceSupportOptions_status;
    extern const ServiceSupportOptions ServiceSupportOptions_getNameList;
    extern const ServiceSupportOptions ServiceSupportOptions_identify;
    extern const ServiceSupportOptions ServiceSupportOptions_rename;
    extern const ServiceSupportOptions ServiceSupportOptions_read;
    extern const ServiceSupportOptions ServiceSupportOptions_write;
    extern const ServiceSupportOptions ServiceSupportOptions_getVariableAccessAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_defineNamedVariable;
    extern const ServiceSupportOptions ServiceSupportOptions_defineScatteredAccess;
    extern const ServiceSupportOptions ServiceSupportOptions_getScatteredAccessAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteVariableAccess;
    extern const ServiceSupportOptions ServiceSupportOptions_defineNamedVariableList;
    extern const ServiceSupportOptions ServiceSupportOptions_getNamedVariableListAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteNamedVariableList;
    extern const ServiceSupportOptions ServiceSupportOptions_defineNamedType;
    extern const ServiceSupportOptions ServiceSupportOptions_getNamedTypeAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteNamedType;
    extern const ServiceSupportOptions ServiceSupportOptions_input;
    extern const ServiceSupportOptions ServiceSupportOptions_output;
    extern const ServiceSupportOptions ServiceSupportOptions_takeControl;
    extern const ServiceSupportOptions ServiceSupportOptions_relinquishControl;
    extern const ServiceSupportOptions ServiceSupportOptions_defineSemaphore;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteSemaphore;
    extern const ServiceSupportOptions ServiceSupportOptions_reportSemaphoreStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_reportPoolSemaphoreStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_reportSemaphoreEntryStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_initiateDownloadSequence;
    extern const ServiceSupportOptions ServiceSupportOptions_downloadSegment;
    extern const ServiceSupportOptions ServiceSupportOptions_terminateDownloadSequence;
    extern const ServiceSupportOptions ServiceSupportOptions_initiateUploadSequence;
    extern const ServiceSupportOptions ServiceSupportOptions_uploadSegment;
    extern const ServiceSupportOptions ServiceSupportOptions_terminateUploadSequence;
    extern const ServiceSupportOptions ServiceSupportOptions_requestDomainDownload;
    extern const ServiceSupportOptions ServiceSupportOptions_requestDomainUpload;
    extern const ServiceSupportOptions ServiceSupportOptions_loadDomainContent;
    extern const ServiceSupportOptions ServiceSupportOptions_storeDomainContent;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteDomain;
    extern const ServiceSupportOptions ServiceSupportOptions_getDomainAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_createProgramInvocation;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteProgramInvocation;
    extern const ServiceSupportOptions ServiceSupportOptions_start;
    extern const ServiceSupportOptions ServiceSupportOptions_stop;
    extern const ServiceSupportOptions ServiceSupportOptions_resume;
    extern const ServiceSupportOptions ServiceSupportOptions_reset;
    extern const ServiceSupportOptions ServiceSupportOptions_kill;
    extern const ServiceSupportOptions ServiceSupportOptions_getProgramInvocationAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_obtainFile;
    extern const ServiceSupportOptions ServiceSupportOptions_defineEventCondition;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteEventCondition;
    extern const ServiceSupportOptions ServiceSupportOptions_getEventConditionAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_reportEventConditionStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_alterEventConditionMonitoring;
    extern const ServiceSupportOptions ServiceSupportOptions_triggerEvent;
    extern const ServiceSupportOptions ServiceSupportOptions_defineEventAction;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteEventAction;
    extern const ServiceSupportOptions ServiceSupportOptions_getEventActionAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_reportEventActionStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_defineEventEnrollment;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteEventEnrollment;
    extern const ServiceSupportOptions ServiceSupportOptions_alterEventEnrollment;
    extern const ServiceSupportOptions ServiceSupportOptions_reportEventEnrollmentStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_getEventEnrollmentAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_acknowledgeEventNotification;
    extern const ServiceSupportOptions ServiceSupportOptions_getAlarmSummary;
    extern const ServiceSupportOptions ServiceSupportOptions_getAlarmEnrollmentSummary;
    extern const ServiceSupportOptions ServiceSupportOptions_readJournal;
    extern const ServiceSupportOptions ServiceSupportOptions_writeJournal;
    extern const ServiceSupportOptions ServiceSupportOptions_initializeJournal;
    extern const ServiceSupportOptions ServiceSupportOptions_reportJournalStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_createJournal;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteJournal;
    extern const ServiceSupportOptions ServiceSupportOptions_getCapabilityList;
    extern const ServiceSupportOptions ServiceSupportOptions_fileOpen;
    extern const ServiceSupportOptions ServiceSupportOptions_fileRead;
    extern const ServiceSupportOptions ServiceSupportOptions_fileClose;
    extern const ServiceSupportOptions ServiceSupportOptions_fileRename;
    extern const ServiceSupportOptions ServiceSupportOptions_fileDelete;
    extern const ServiceSupportOptions ServiceSupportOptions_fileDirectory;
    extern const ServiceSupportOptions ServiceSupportOptions_unsolicitedStatus;
    extern const ServiceSupportOptions ServiceSupportOptions_informationReport;
    extern const ServiceSupportOptions ServiceSupportOptions_eventNotification;
    extern const ServiceSupportOptions ServiceSupportOptions_attachToEventCondition;
    extern const ServiceSupportOptions ServiceSupportOptions_attachToSemaphore;
    extern const ServiceSupportOptions ServiceSupportOptions_conclude;
    extern const ServiceSupportOptions ServiceSupportOptions_cancel;
    extern const ServiceSupportOptions ServiceSupportOptions_getDataExchangeAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_exchangeData;
    extern const ServiceSupportOptions ServiceSupportOptions_defineAccessControlList;
    extern const ServiceSupportOptions ServiceSupportOptions_getAccessControlListAttributes;
    extern const ServiceSupportOptions ServiceSupportOptions_reportAccessControlledObjects;
    extern const ServiceSupportOptions ServiceSupportOptions_deleteAccessControlList;
    extern const ServiceSupportOptions ServiceSupportOptions_alterAccessControl;
    extern const ServiceSupportOptions ServiceSupportOptions_reconfigureProgramInvocation;

    extern const ParameterSupportOptions ParameterSupportOptions_str1;
    extern const ParameterSupportOptions ParameterSupportOptions_str2;
    extern const ParameterSupportOptions ParameterSupportOptions_vnam;
    extern const ParameterSupportOptions ParameterSupportOptions_valt;
    extern const ParameterSupportOptions ParameterSupportOptions_vadr;
    extern const ParameterSupportOptions ParameterSupportOptions_vsca;
    extern const ParameterSupportOptions ParameterSupportOptions_tpy;
    extern const ParameterSupportOptions ParameterSupportOptions_vlis;
    extern const ParameterSupportOptions ParameterSupportOptions_cei;
    extern const ParameterSupportOptions ParameterSupportOptions_aco;
    extern const ParameterSupportOptions ParameterSupportOptions_sem;
    extern const ParameterSupportOptions ParameterSupportOptions_csr;
    extern const ParameterSupportOptions ParameterSupportOptions_csnc;
    extern const ParameterSupportOptions ParameterSupportOptions_csplc;
    extern const ParameterSupportOptions ParameterSupportOptions_cspi;
    extern const ParameterSupportOptions ParameterSupportOptions_char;

    extern const AdditionalSupportOptions AdditionalSupportOptions_vMDStop;
    extern const AdditionalSupportOptions AdditionalSupportOptions_vMDReset;
    extern const AdditionalSupportOptions AdditionalSupportOptions_select;
    extern const AdditionalSupportOptions AdditionalSupportOptions_alterProgramInvocationAttributes;
    extern const AdditionalSupportOptions AdditionalSupportOptions_initiateUnitControlLoad;
    extern const AdditionalSupportOptions AdditionalSupportOptions_unitControlLoadSegment;
    extern const AdditionalSupportOptions AdditionalSupportOptions_unitControlUpload;
    extern const AdditionalSupportOptions AdditionalSupportOptions_startUnitControl;
    extern const AdditionalSupportOptions AdditionalSupportOptions_stopUnitControl;
    extern const AdditionalSupportOptions AdditionalSupportOptions_createUnitControl;
    extern const AdditionalSupportOptions AdditionalSupportOptions_addToUnitControl;
    extern const AdditionalSupportOptions AdditionalSupportOptions_removeFromUnitControl;
    extern const AdditionalSupportOptions AdditionalSupportOptions_getUnitControlAttributes;
    extern const AdditionalSupportOptions AdditionalSupportOptions_loadUnitControlFromFile;
    extern const AdditionalSupportOptions AdditionalSupportOptions_storeUnitControlToFile;
    extern const AdditionalSupportOptions AdditionalSupportOptions_deleteUnitControl;
    extern const AdditionalSupportOptions AdditionalSupportOptions_defineEventConditionList;
    extern const AdditionalSupportOptions AdditionalSupportOptions_deleteEventConditionList;
    extern const AdditionalSupportOptions AdditionalSupportOptions_addEventConditionListReference;
    extern const AdditionalSupportOptions AdditionalSupportOptions_removeEventConditionListReference;
    extern const AdditionalSupportOptions AdditionalSupportOptions_getEventConditionListAttributes;
    extern const AdditionalSupportOptions AdditionalSupportOptions_reportEventConditionListStatus;
    extern const AdditionalSupportOptions AdditionalSupportOptions_alterEventConditionListMonitoring;

    extern const AdditionalCBBOptions AdditionalCBBOptions_des;
    extern const AdditionalCBBOptions AdditionalCBBOptions_dei;
    extern const AdditionalCBBOptions AdditionalCBBOptions_recl;

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

    struct AccessCondition : public ITU_T_STRUCT(AccessCondition_enum) {


        struct user_type;

        enum user_type_enum {

            user_type_null = 0,
            user_type_association,
            user_type_none,
        };

        struct user_type : public ITU_T_STRUCT(user_type_enum) {

            user_type() : ITU_T_STRUCT(user_type_enum) () {
            }

            template<typename T > user_type(boost::shared_ptr< T> vl, user_type_enum enm) :
                    ITU_T_STRUCT(user_type_enum) (vl, static_cast<int> (enm)) {
            }

            ITU_T_CHOICE_DECL(association, MMS_Environment_1::ApplicationReference, user_type_association);
            ITU_T_CHOICE_DECL(none, null_type, user_type_none);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef std::vector< AccessCondition > joint_type;
        typedef std::vector< AccessCondition > alternate_type;

        AccessCondition() : ITU_T_STRUCT(AccessCondition_enum) () {
        }

        template<typename T > AccessCondition(boost::shared_ptr< T> vl, AccessCondition_enum enm) :
                ITU_T_STRUCT(AccessCondition_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(never, null_type, AccessCondition_never);
        ITU_T_CHOICE_DECL(semaphore, ISO_9506_MMS_1::Identifier, AccessCondition_semaphore);
        ITU_T_CHOICE_DECL(user, user_type, AccessCondition_user);
        ITU_T_CHOICE_DECL(password, ACSE_1::Authentication_value, AccessCondition_password);
        ITU_T_CHOICE_DECL(joint, joint_type, AccessCondition_joint);
        ITU_T_CHOICE_DECL(alternate, alternate_type, AccessCondition_alternate);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const DomainState DomainState_non_existent;
    extern const DomainState DomainState_loading;
    extern const DomainState DomainState_ready;
    extern const DomainState DomainState_in_use;
    extern const DomainState DomainState_complete;
    extern const DomainState DomainState_incomplete;
    extern const DomainState DomainState_d1;
    extern const DomainState DomainState_d2;
    extern const DomainState DomainState_d3;
    extern const DomainState DomainState_d4;
    extern const DomainState DomainState_d5;
    extern const DomainState DomainState_d6;
    extern const DomainState DomainState_d7;
    extern const DomainState DomainState_d8;
    extern const DomainState DomainState_d9;

    extern const ULState ULState_non_existent;
    extern const ULState ULState_uploading;
    extern const ULState ULState_uploaded;
    extern const ULState ULState_u1;
    extern const ULState ULState_u2;
    extern const ULState ULState_u3;
    extern const ULState ULState_u4;

    extern const ProgramInvocationState ProgramInvocationState_non_existent;
    extern const ProgramInvocationState ProgramInvocationState_unrunnable;
    extern const ProgramInvocationState ProgramInvocationState_idle;
    extern const ProgramInvocationState ProgramInvocationState_running;
    extern const ProgramInvocationState ProgramInvocationState_stopped;
    extern const ProgramInvocationState ProgramInvocationState_starting;
    extern const ProgramInvocationState ProgramInvocationState_stopping;
    extern const ProgramInvocationState ProgramInvocationState_resuming;
    extern const ProgramInvocationState ProgramInvocationState_resetting;

    extern const Control_State Control_State_normal;
    extern const Control_State Control_State_controlling;
    extern const Control_State Control_State_controlled;

    extern const Running_Mode Running_Mode_free_run;
    extern const Running_Mode Running_Mode_cycle_limited;
    extern const Running_Mode Running_Mode_step_limited;

    // choice Address

    enum Address_enum {

        Address_null = 0,
        Address_numericAddress,
        Address_symbolicAddress,
        Address_unconstrainedAddress,
    };

    struct Address : public ITU_T_STRUCT(Address_enum) {

        Address() : ITU_T_STRUCT(Address_enum) () {
        }

        template<typename T > Address(boost::shared_ptr< T> vl, Address_enum enm) :
                ITU_T_STRUCT(Address_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(numericAddress, ISO_9506_MMS_1::Unsigned32, Address_numericAddress);
        ITU_T_CHOICE_DECL(symbolicAddress, ISO_9506_MMS_1::MMSString, Address_symbolicAddress);
        ITU_T_CHOICE_DECL(unconstrainedAddress, octetstring_type, Address_unconstrainedAddress);

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

    struct TypeDescription : public ITU_T_STRUCT(TypeDescription_enum) {


        struct array_type;
        struct structure_type;
        struct floating_point_type;

        struct array_type {

            static const bool packed__default;

            array_type();

            array_type(const ISO_9506_MMS_1::Unsigned32& arg__numberOfElements,
                    const ISO_9506_MMS_1::TypeSpecification& arg__elementType);

            array_type(boost::shared_ptr< bool> arg__packed,
                    boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__numberOfElements,
                    boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__elementType);

            ITU_T_DEFAULTH_DECL(packed, bool, packed__default);
            ITU_T_HOLDERH_DECL(numberOfElements, ISO_9506_MMS_1::Unsigned32);
            ITU_T_HOLDERH_DECL(elementType, ISO_9506_MMS_1::TypeSpecification);

            ITU_T_ARCHIVE_FUNC;
        };

        struct structure_type {

            struct components_type_sequence_of;

            struct components_type_sequence_of {

                components_type_sequence_of();

                components_type_sequence_of(const ISO_9506_MMS_1::TypeSpecification& arg__componentType);

                components_type_sequence_of(boost::shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
                        boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__componentType);

                ITU_T_OPTIONAL_DECL(componentName, ISO_9506_MMS_1::Identifier);
                ITU_T_HOLDERH_DECL(componentType, ISO_9506_MMS_1::TypeSpecification);

                ITU_T_ARCHIVE_FUNC;
            };



            typedef std::vector< components_type_sequence_of > components_type;

            static const bool packed__default;

            structure_type();

            structure_type(const components_type& arg__components);

            structure_type(boost::shared_ptr< bool> arg__packed,
                    boost::shared_ptr< components_type> arg__components);

            ITU_T_DEFAULTH_DECL(packed, bool, packed__default);
            ITU_T_HOLDERH_DECL(components, components_type);

            ITU_T_ARCHIVE_FUNC;
        };

        struct floating_point_type {

            floating_point_type();

            floating_point_type(const ISO_9506_MMS_1::Unsigned8& arg__format_width,
                    const ISO_9506_MMS_1::Unsigned8& arg__exponent_width);

            ITU_T_HOLDERH_DECL(format_width, ISO_9506_MMS_1::Unsigned8);
            ITU_T_HOLDERH_DECL(exponent_width, ISO_9506_MMS_1::Unsigned8);

            ITU_T_ARCHIVE_FUNC;
        };

        TypeDescription() : ITU_T_STRUCT(TypeDescription_enum) () {
        }

        template<typename T > TypeDescription(boost::shared_ptr< T> vl, TypeDescription_enum enm) :
                ITU_T_STRUCT(TypeDescription_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(array, array_type, TypeDescription_array);
        ITU_T_CHOICE_DECL(structure, structure_type, TypeDescription_structure);
        ITU_T_CHOICE_DECL(boolean, null_type, TypeDescription_boolean);
        ITU_T_CHOICE_DECL(bit_string, ISO_9506_MMS_1::Integer32, TypeDescription_bit_string);
        ITU_T_CHOICE_DECL(integer, ISO_9506_MMS_1::Unsigned8, TypeDescription_integer);
        ITU_T_CHOICE_DECL(unsignedV, ISO_9506_MMS_1::Unsigned8, TypeDescription_unsignedV);
        ITU_T_CHOICE_DECL(floating_point, floating_point_type, TypeDescription_floating_point);
        ITU_T_CHOICE_DECL(octet_string, ISO_9506_MMS_1::Integer32, TypeDescription_octet_string);
        ITU_T_CHOICE_DECL(visible_string, ISO_9506_MMS_1::Integer32, TypeDescription_visible_string);
        ITU_T_CHOICE_DECL(generalized_time, null_type, TypeDescription_generalized_time);
        ITU_T_CHOICE_DECL(binary_time, bool, TypeDescription_binary_time);
        ITU_T_CHOICE_DECL(bcd, ISO_9506_MMS_1::Unsigned8, TypeDescription_bcd);
        ITU_T_CHOICE_DECL(objId, null_type, TypeDescription_objId);
        ITU_T_CHOICE_DECL(mMSString, ISO_9506_MMS_1::Integer32, TypeDescription_mMSString);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const EC_Class EC_Class_network_triggered;
    extern const EC_Class EC_Class_monitored;

    extern const EC_State EC_State_disabled;
    extern const EC_State EC_State_idle;
    extern const EC_State EC_State_active;

    // choice EventTime

    enum EventTime_enum {

        EventTime_null = 0,
        EventTime_timeOfDay,
        EventTime_timeSequenceIdentifier,
        EventTime_undefined,
    };

    struct EventTime : public ITU_T_STRUCT(EventTime_enum) {

        EventTime() : ITU_T_STRUCT(EventTime_enum) () {
        }

        template<typename T > EventTime(boost::shared_ptr< T> vl, EventTime_enum enm) :
                ITU_T_STRUCT(EventTime_enum) (vl, static_cast<int> (enm)) {
        }

        ITU_T_CHOICE_DECL(timeOfDay, ISO_9506_MMS_1::TimeOfDay, EventTime_timeOfDay);
        ITU_T_CHOICE_DECL(timeSequenceIdentifier, ISO_9506_MMS_1::Unsigned32, EventTime_timeSequenceIdentifier);
        ITU_T_CHOICE_DECL(undefined, null_type, EventTime_undefined);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const EE_Class EE_Class_modifier;
    extern const EE_Class EE_Class_notification;

    extern const Transitions Transitions_idle_to_disabled;
    extern const Transitions Transitions_active_to_disabled;
    extern const Transitions Transitions_disabled_to_idle;
    extern const Transitions Transitions_active_to_idle;
    extern const Transitions Transitions_disabled_to_active;
    extern const Transitions Transitions_idle_to_active;
    extern const Transitions Transitions_any_to_deleted;

    extern const EE_Duration EE_Duration_current;
    extern const EE_Duration EE_Duration_permanent;

    extern const AlarmAckRule AlarmAckRule_none;
    extern const AlarmAckRule AlarmAckRule_simple;
    extern const AlarmAckRule AlarmAckRule_ack_active;
    extern const AlarmAckRule AlarmAckRule_ack_all;

    // sequence Journal-Variable

    struct Journal_Variable {

        Journal_Variable();

        Journal_Variable(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
                const ISO_9506_MMS_1::Data& arg__valueSpecification);

        ITU_T_HOLDERH_DECL(variableTag, ISO_9506_MMS_1::MMS255String);
        ITU_T_HOLDERH_DECL(valueSpecification, ISO_9506_MMS_1::Data);

        ITU_T_ARCHIVE_FUNC;
    };

    template<> void ModifierStep::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ModifierStep::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Modifier::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Modifier::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AccessCondition::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AccessCondition::serialize(boost::asn1::x690::input_coder& arch);
    template<> void AccessCondition::user_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AccessCondition::user_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Address::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Address::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::array_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::array_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::structure_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::structure_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::structure_type::components_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::structure_type::components_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::floating_point_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::floating_point_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void EventTime::serialize(boost::asn1::x690::output_coder& arch);
    template<> void EventTime::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Variable::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Variable::serialize(boost::asn1::x690::input_coder& arch);
}

ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::Modifier)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition::user_type)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::Address)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::TypeDescription)
ITU_T_CHOICE_REGESTRATE(MMS_Object_Module_1::EventTime)

#endif  /*___MMS_OBJECT_MODULE_1 */

