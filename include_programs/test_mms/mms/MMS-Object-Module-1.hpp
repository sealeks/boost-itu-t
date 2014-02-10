#ifndef ___MMS_OBJECT_MODULE_1
#define ___MMS_OBJECT_MODULE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {

    using  boost::asn1::null_type;
    using  boost::asn1::enumerated_type;
    using  boost::asn1::bitstring_type;
    using  boost::asn1::octetstring_type;
    using  boost::asn1::oid_type;
    using  boost::asn1::reloid_type;
    using  boost::asn1::utctime_type;
    using  boost::asn1::gentime_type;
    using  boost::asn1::ia5string_type;
    using  boost::asn1::printablestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::numericstring_type;
    using  boost::asn1::universalstring_type;
    using  boost::asn1::bmpstring_type;
    using  boost::asn1::utf8string_type;
    using  boost::asn1::generalstring_type;
    using  boost::asn1::graphicstring_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::videotexstring_type;
    using  boost::asn1::objectdescriptor_type;
    using  boost::asn1::external_type;
    using  boost::asn1::embeded_type;
    using  boost::asn1::characterstring_type;
    using  boost::asn1::any_type;

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

    BOOST_ASN_IMPLICIT_TYPEDEF(LogicalStatus, int,  0, CONTEXT_CLASS);  
    BOOST_ASN_IMPLICIT_TYPEDEF(PhysicalStatus, int,  1, CONTEXT_CLASS);  




        extern const int normalPriority;

        extern const int normalSeverity;

        extern const boost::asn1::oid_type mMSNamedVariable;

        extern const boost::asn1::oid_type mMSAccessControlList;

        extern const boost::asn1::oid_type mMSEventCondition;

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



        extern const int LogicalStatus_state_changes_allowed;
        extern const int LogicalStatus_no_state_changes_allowed;
        extern const int LogicalStatus_limited_services_permitted;
        extern const int LogicalStatus_support_services_allowed;

        extern const int PhysicalStatus_operational;
        extern const int PhysicalStatus_partially_operational;
        extern const int PhysicalStatus_inoperable;
        extern const int PhysicalStatus_needs_commissioning;

        extern const int VMDState_idle;
        extern const int VMDState_loaded;
        extern const int VMDState_ready;
        extern const int VMDState_executing;
        extern const int VMDState_motion_paused;
        extern const int VMDState_manualInterventionRequired;

        // sequence ModifierStep
        struct ModifierStep{



            ModifierStep() : modifierID(), modifier() {} 
 
            boost::asn1::value_holder<int> modifierID;
            boost::asn1::value_holder<Modifier> modifier;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // choice Modifier
        enum Modifier_enum {
            Modifier_null = 0, 
            Modifier_eventModifier,
            Modifier_semaphoreModifier,}; 
 
        struct Modifier : public BOOST_ASN_CHOICE_STRUCT(Modifier_enum) {



            Modifier() :  BOOST_ASN_CHOICE_STRUCT(Modifier_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(eventModifier, ISO_9506_MMS_1::AttachToEventCondition, Modifier_eventModifier);
            BOOST_ASN_VALUE_CHOICE(semaphoreModifier, ISO_9506_MMS_1::AttachToSemaphore, Modifier_semaphoreModifier);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const bitstring_type ServiceSupportOptions_status;
        extern const bitstring_type ServiceSupportOptions_getNameList;
        extern const bitstring_type ServiceSupportOptions_identify;
        extern const bitstring_type ServiceSupportOptions_rename;
        extern const bitstring_type ServiceSupportOptions_read;
        extern const bitstring_type ServiceSupportOptions_write;
        extern const bitstring_type ServiceSupportOptions_getVariableAccessAttributes;
        extern const bitstring_type ServiceSupportOptions_defineNamedVariable;
        extern const bitstring_type ServiceSupportOptions_defineScatteredAccess;
        extern const bitstring_type ServiceSupportOptions_getScatteredAccessAttributes;
        extern const bitstring_type ServiceSupportOptions_deleteVariableAccess;
        extern const bitstring_type ServiceSupportOptions_defineNamedVariableList;
        extern const bitstring_type ServiceSupportOptions_getNamedVariableListAttributes;
        extern const bitstring_type ServiceSupportOptions_deleteNamedVariableList;
        extern const bitstring_type ServiceSupportOptions_defineNamedType;
        extern const bitstring_type ServiceSupportOptions_getNamedTypeAttributes;
        extern const bitstring_type ServiceSupportOptions_deleteNamedType;
        extern const bitstring_type ServiceSupportOptions_input;
        extern const bitstring_type ServiceSupportOptions_output;
        extern const bitstring_type ServiceSupportOptions_takeControl;
        extern const bitstring_type ServiceSupportOptions_relinquishControl;
        extern const bitstring_type ServiceSupportOptions_defineSemaphore;
        extern const bitstring_type ServiceSupportOptions_deleteSemaphore;
        extern const bitstring_type ServiceSupportOptions_reportSemaphoreStatus;
        extern const bitstring_type ServiceSupportOptions_reportPoolSemaphoreStatus;
        extern const bitstring_type ServiceSupportOptions_reportSemaphoreEntryStatus;
        extern const bitstring_type ServiceSupportOptions_initiateDownloadSequence;
        extern const bitstring_type ServiceSupportOptions_downloadSegment;
        extern const bitstring_type ServiceSupportOptions_terminateDownloadSequence;
        extern const bitstring_type ServiceSupportOptions_initiateUploadSequence;
        extern const bitstring_type ServiceSupportOptions_uploadSegment;
        extern const bitstring_type ServiceSupportOptions_terminateUploadSequence;
        extern const bitstring_type ServiceSupportOptions_requestDomainDownload;
        extern const bitstring_type ServiceSupportOptions_requestDomainUpload;
        extern const bitstring_type ServiceSupportOptions_loadDomainContent;
        extern const bitstring_type ServiceSupportOptions_storeDomainContent;
        extern const bitstring_type ServiceSupportOptions_deleteDomain;
        extern const bitstring_type ServiceSupportOptions_getDomainAttributes;
        extern const bitstring_type ServiceSupportOptions_createProgramInvocation;
        extern const bitstring_type ServiceSupportOptions_deleteProgramInvocation;
        extern const bitstring_type ServiceSupportOptions_start;
        extern const bitstring_type ServiceSupportOptions_stop;
        extern const bitstring_type ServiceSupportOptions_resume;
        extern const bitstring_type ServiceSupportOptions_reset;
        extern const bitstring_type ServiceSupportOptions_kill;
        extern const bitstring_type ServiceSupportOptions_getProgramInvocationAttributes;
        extern const bitstring_type ServiceSupportOptions_obtainFile;
        extern const bitstring_type ServiceSupportOptions_defineEventCondition;
        extern const bitstring_type ServiceSupportOptions_deleteEventCondition;
        extern const bitstring_type ServiceSupportOptions_getEventConditionAttributes;
        extern const bitstring_type ServiceSupportOptions_reportEventConditionStatus;
        extern const bitstring_type ServiceSupportOptions_alterEventConditionMonitoring;
        extern const bitstring_type ServiceSupportOptions_triggerEvent;
        extern const bitstring_type ServiceSupportOptions_defineEventAction;
        extern const bitstring_type ServiceSupportOptions_deleteEventAction;
        extern const bitstring_type ServiceSupportOptions_getEventActionAttributes;
        extern const bitstring_type ServiceSupportOptions_reportEventActionStatus;
        extern const bitstring_type ServiceSupportOptions_defineEventEnrollment;
        extern const bitstring_type ServiceSupportOptions_deleteEventEnrollment;
        extern const bitstring_type ServiceSupportOptions_alterEventEnrollment;
        extern const bitstring_type ServiceSupportOptions_reportEventEnrollmentStatus;
        extern const bitstring_type ServiceSupportOptions_getEventEnrollmentAttributes;
        extern const bitstring_type ServiceSupportOptions_acknowledgeEventNotification;
        extern const bitstring_type ServiceSupportOptions_getAlarmSummary;
        extern const bitstring_type ServiceSupportOptions_getAlarmEnrollmentSummary;
        extern const bitstring_type ServiceSupportOptions_readJournal;
        extern const bitstring_type ServiceSupportOptions_writeJournal;
        extern const bitstring_type ServiceSupportOptions_initializeJournal;
        extern const bitstring_type ServiceSupportOptions_reportJournalStatus;
        extern const bitstring_type ServiceSupportOptions_createJournal;
        extern const bitstring_type ServiceSupportOptions_deleteJournal;
        extern const bitstring_type ServiceSupportOptions_getCapabilityList;
        extern const bitstring_type ServiceSupportOptions_fileOpen;
        extern const bitstring_type ServiceSupportOptions_fileRead;
        extern const bitstring_type ServiceSupportOptions_fileClose;
        extern const bitstring_type ServiceSupportOptions_fileRename;
        extern const bitstring_type ServiceSupportOptions_fileDelete;
        extern const bitstring_type ServiceSupportOptions_fileDirectory;
        extern const bitstring_type ServiceSupportOptions_unsolicitedStatus;
        extern const bitstring_type ServiceSupportOptions_informationReport;
        extern const bitstring_type ServiceSupportOptions_eventNotification;
        extern const bitstring_type ServiceSupportOptions_attachToEventCondition;
        extern const bitstring_type ServiceSupportOptions_attachToSemaphore;
        extern const bitstring_type ServiceSupportOptions_conclude;
        extern const bitstring_type ServiceSupportOptions_cancel;
        extern const bitstring_type ServiceSupportOptions_getDataExchangeAttributes;
        extern const bitstring_type ServiceSupportOptions_exchangeData;
        extern const bitstring_type ServiceSupportOptions_defineAccessControlList;
        extern const bitstring_type ServiceSupportOptions_getAccessControlListAttributes;
        extern const bitstring_type ServiceSupportOptions_reportAccessControlledObjects;
        extern const bitstring_type ServiceSupportOptions_deleteAccessControlList;
        extern const bitstring_type ServiceSupportOptions_alterAccessControl;
        extern const bitstring_type ServiceSupportOptions_reconfigureProgramInvocation;

        extern const bitstring_type ParameterSupportOptions_str1;
        extern const bitstring_type ParameterSupportOptions_str2;
        extern const bitstring_type ParameterSupportOptions_vnam;
        extern const bitstring_type ParameterSupportOptions_valt;
        extern const bitstring_type ParameterSupportOptions_vadr;
        extern const bitstring_type ParameterSupportOptions_vsca;
        extern const bitstring_type ParameterSupportOptions_tpy;
        extern const bitstring_type ParameterSupportOptions_vlis;
        extern const bitstring_type ParameterSupportOptions_cei;
        extern const bitstring_type ParameterSupportOptions_aco;
        extern const bitstring_type ParameterSupportOptions_sem;
        extern const bitstring_type ParameterSupportOptions_csr;
        extern const bitstring_type ParameterSupportOptions_csnc;
        extern const bitstring_type ParameterSupportOptions_csplc;
        extern const bitstring_type ParameterSupportOptions_cspi;
        extern const bitstring_type ParameterSupportOptions_char;

        extern const bitstring_type AdditionalSupportOptions_vMDStop;
        extern const bitstring_type AdditionalSupportOptions_vMDReset;
        extern const bitstring_type AdditionalSupportOptions_select;
        extern const bitstring_type AdditionalSupportOptions_alterProgramInvocationAttributes;
        extern const bitstring_type AdditionalSupportOptions_initiateUnitControlLoad;
        extern const bitstring_type AdditionalSupportOptions_unitControlLoadSegment;
        extern const bitstring_type AdditionalSupportOptions_unitControlUpload;
        extern const bitstring_type AdditionalSupportOptions_startUnitControl;
        extern const bitstring_type AdditionalSupportOptions_stopUnitControl;
        extern const bitstring_type AdditionalSupportOptions_createUnitControl;
        extern const bitstring_type AdditionalSupportOptions_addToUnitControl;
        extern const bitstring_type AdditionalSupportOptions_removeFromUnitControl;
        extern const bitstring_type AdditionalSupportOptions_getUnitControlAttributes;
        extern const bitstring_type AdditionalSupportOptions_loadUnitControlFromFile;
        extern const bitstring_type AdditionalSupportOptions_storeUnitControlToFile;
        extern const bitstring_type AdditionalSupportOptions_deleteUnitControl;
        extern const bitstring_type AdditionalSupportOptions_defineEventConditionList;
        extern const bitstring_type AdditionalSupportOptions_deleteEventConditionList;
        extern const bitstring_type AdditionalSupportOptions_addEventConditionListReference;
        extern const bitstring_type AdditionalSupportOptions_removeEventConditionListReference;
        extern const bitstring_type AdditionalSupportOptions_getEventConditionListAttributes;
        extern const bitstring_type AdditionalSupportOptions_reportEventConditionListStatus;
        extern const bitstring_type AdditionalSupportOptions_alterEventConditionListMonitoring;

        extern const bitstring_type AdditionalCBBOptions_des;
        extern const bitstring_type AdditionalCBBOptions_dei;
        extern const bitstring_type AdditionalCBBOptions_recl;

        // choice AccessCondition
        enum AccessCondition_enum {
            AccessCondition_null = 0, 
            AccessCondition_never,
            AccessCondition_semaphore,
            AccessCondition_user,
            AccessCondition_password,
            AccessCondition_joint,
            AccessCondition_alternate,}; 
 
        struct AccessCondition : public BOOST_ASN_CHOICE_STRUCT(AccessCondition_enum) {


            enum user_type_enum {
                user_type_null = 0, 
                user_type_association,
                user_type_none,}; 
 
            struct user_type : public BOOST_ASN_CHOICE_STRUCT(user_type_enum) {



                user_type() :  BOOST_ASN_CHOICE_STRUCT(user_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(association, MMS_Environment_1::ApplicationReference, user_type_association);
                BOOST_ASN_VALUE_CHOICE(none, null_type, user_type_none);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        typedef std::vector< AccessCondition> joint_type;
        typedef std::vector< AccessCondition> alternate_type;


            AccessCondition() :  BOOST_ASN_CHOICE_STRUCT(AccessCondition_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(never, null_type, AccessCondition_never);
            BOOST_ASN_VALUE_CHOICE(semaphore, ISO_9506_MMS_1::Identifier, AccessCondition_semaphore);
            BOOST_ASN_VALUE_CHOICE(user, user_type, AccessCondition_user);
            BOOST_ASN_VALUE_CHOICE(password, ACSE_1::Authentication_value, AccessCondition_password);
            BOOST_ASN_VALUE_CHOICE(joint, joint_type, AccessCondition_joint);
            BOOST_ASN_VALUE_CHOICE(alternate, alternate_type, AccessCondition_alternate);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const int DomainState_non_existent;
        extern const int DomainState_loading;
        extern const int DomainState_ready;
        extern const int DomainState_in_use;
        extern const int DomainState_complete;
        extern const int DomainState_incomplete;
        extern const int DomainState_d1;
        extern const int DomainState_d2;
        extern const int DomainState_d3;
        extern const int DomainState_d4;
        extern const int DomainState_d5;
        extern const int DomainState_d6;
        extern const int DomainState_d7;
        extern const int DomainState_d8;
        extern const int DomainState_d9;

        extern const int ULState_non_existent;
        extern const int ULState_uploading;
        extern const int ULState_uploaded;
        extern const int ULState_u1;
        extern const int ULState_u2;
        extern const int ULState_u3;
        extern const int ULState_u4;

        extern const int ProgramInvocationState_non_existent;
        extern const int ProgramInvocationState_unrunnable;
        extern const int ProgramInvocationState_idle;
        extern const int ProgramInvocationState_running;
        extern const int ProgramInvocationState_stopped;
        extern const int ProgramInvocationState_starting;
        extern const int ProgramInvocationState_stopping;
        extern const int ProgramInvocationState_resuming;
        extern const int ProgramInvocationState_resetting;

        extern const int Control_State_normal;
        extern const int Control_State_controlling;
        extern const int Control_State_controlled;

        extern const int Running_Mode_free_run;
        extern const int Running_Mode_cycle_limited;
        extern const int Running_Mode_step_limited;

        // choice Address
        enum Address_enum {
            Address_null = 0, 
            Address_numericAddress,
            Address_symbolicAddress,
            Address_unconstrainedAddress,}; 
 
        struct Address : public BOOST_ASN_CHOICE_STRUCT(Address_enum) {



            Address() :  BOOST_ASN_CHOICE_STRUCT(Address_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(numericAddress, ISO_9506_MMS_1::Unsigned32, Address_numericAddress);
            BOOST_ASN_VALUE_CHOICE(symbolicAddress, ISO_9506_MMS_1::MMSString, Address_symbolicAddress);
            BOOST_ASN_VALUE_CHOICE(unconstrainedAddress, octetstring_type, Address_unconstrainedAddress);

            BOOST_ASN_ARCHIVE_FUNC;
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
            TypeDescription_mMSString,}; 
 
        struct TypeDescription : public BOOST_ASN_CHOICE_STRUCT(TypeDescription_enum) {


            struct array_type{



                array_type() : numberOfElements(), elementType() {} 
 
                boost::shared_ptr<bool> packed;
                BOOST_ASN_VALUE_FUNC_DECLARATE(bool, packed)

                boost::asn1::value_holder<ISO_9506_MMS_1::Unsigned32> numberOfElements;
                boost::asn1::value_holder<ISO_9506_MMS_1::TypeSpecification> elementType;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            struct structure_type{
            struct components_type_sequence_of;


                    struct components_type_sequence_of{



                        components_type_sequence_of() : componentType() {} 
 
                        boost::shared_ptr<ISO_9506_MMS_1::Identifier> componentName;
                        BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::Identifier, componentName)

                        boost::asn1::value_holder<ISO_9506_MMS_1::TypeSpecification> componentType;

                        BOOST_ASN_ARCHIVE_FUNC;
                    };
 
            typedef std::vector< components_type_sequence_of> components_type;


                structure_type() : components() {} 
 
                boost::shared_ptr<bool> packed;
                BOOST_ASN_VALUE_FUNC_DECLARATE(bool, packed)

                boost::asn1::value_holder<components_type> components;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

            struct floating_point_type{



                floating_point_type() : format_width(), exponent_width() {} 
 
                boost::asn1::value_holder<ISO_9506_MMS_1::Unsigned8> format_width;
                boost::asn1::value_holder<ISO_9506_MMS_1::Unsigned8> exponent_width;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            TypeDescription() :  BOOST_ASN_CHOICE_STRUCT(TypeDescription_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(array, array_type, TypeDescription_array);
            BOOST_ASN_VALUE_CHOICE(structure, structure_type, TypeDescription_structure);
            BOOST_ASN_VALUE_CHOICE(boolean, null_type, TypeDescription_boolean);
            BOOST_ASN_VALUE_CHOICE(bit_string, ISO_9506_MMS_1::Integer32, TypeDescription_bit_string);
            BOOST_ASN_VALUE_CHOICE(integer, ISO_9506_MMS_1::Unsigned8, TypeDescription_integer);
            BOOST_ASN_VALUE_CHOICE(unsignedV, ISO_9506_MMS_1::Unsigned8, TypeDescription_unsignedV);
            BOOST_ASN_VALUE_CHOICE(floating_point, floating_point_type, TypeDescription_floating_point);
            BOOST_ASN_VALUE_CHOICE(octet_string, ISO_9506_MMS_1::Integer32, TypeDescription_octet_string);
            BOOST_ASN_VALUE_CHOICE(visible_string, ISO_9506_MMS_1::Integer32, TypeDescription_visible_string);
            BOOST_ASN_VALUE_CHOICE(generalized_time, null_type, TypeDescription_generalized_time);
            BOOST_ASN_VALUE_CHOICE(binary_time, bool, TypeDescription_binary_time);
            BOOST_ASN_VALUE_CHOICE(bcd, ISO_9506_MMS_1::Unsigned8, TypeDescription_bcd);
            BOOST_ASN_VALUE_CHOICE(objId, null_type, TypeDescription_objId);
            BOOST_ASN_VALUE_CHOICE(mMSString, ISO_9506_MMS_1::Integer32, TypeDescription_mMSString);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const int EC_Class_network_triggered;
        extern const int EC_Class_monitored;

        extern const int EC_State_disabled;
        extern const int EC_State_idle;
        extern const int EC_State_active;

        // choice EventTime
        enum EventTime_enum {
            EventTime_null = 0, 
            EventTime_timeOfDay,
            EventTime_timeSequenceIdentifier,
            EventTime_undefined,}; 
 
        struct EventTime : public BOOST_ASN_CHOICE_STRUCT(EventTime_enum) {



            EventTime() :  BOOST_ASN_CHOICE_STRUCT(EventTime_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(timeOfDay, ISO_9506_MMS_1::TimeOfDay, EventTime_timeOfDay);
            BOOST_ASN_VALUE_CHOICE(timeSequenceIdentifier, ISO_9506_MMS_1::Unsigned32, EventTime_timeSequenceIdentifier);
            BOOST_ASN_VALUE_CHOICE(undefined, null_type, EventTime_undefined);

            BOOST_ASN_ARCHIVE_FUNC;
        }; 
 
        extern const int EE_Class_modifier;
        extern const int EE_Class_notification;

        extern const bitstring_type Transitions_idle_to_disabled;
        extern const bitstring_type Transitions_active_to_disabled;
        extern const bitstring_type Transitions_disabled_to_idle;
        extern const bitstring_type Transitions_active_to_idle;
        extern const bitstring_type Transitions_disabled_to_active;
        extern const bitstring_type Transitions_idle_to_active;
        extern const bitstring_type Transitions_any_to_deleted;

        extern const int EE_Duration_current;
        extern const int EE_Duration_permanent;

        extern const int AlarmAckRule_none;
        extern const int AlarmAckRule_simple;
        extern const int AlarmAckRule_ack_active;
        extern const int AlarmAckRule_ack_all;

        // sequence Journal-Variable
        struct Journal_Variable{



            Journal_Variable() : variableTag(), valueSpecification() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMS255String> variableTag;
            boost::asn1::value_holder<ISO_9506_MMS_1::Data> valueSpecification;

            BOOST_ASN_ARCHIVE_FUNC;
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

BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::Modifier)
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition)
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition::user_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::Address)
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::TypeDescription)
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::EventTime)

#endif  /*___MMS_OBJECT_MODULE_1 */

