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


    typedef int VMDState; //   Ic(  [ 0  ...   5 ]   
    typedef bitstring_type ServiceSupportOptions; //    Sc (  [ 93 ]   
    typedef bitstring_type ParameterSupportOptions; //    Sc (  [ 18 ]   
    typedef bitstring_type AdditionalSupportOptions; //    Sc (  [ 23 ]   
    typedef bitstring_type AdditionalCBBOptions; //    Sc (  [ 3 ]   
    typedef int DomainState; //   Ic(  [ 0  ...   15 ]   
    typedef int ULState; //   Ic(  [ 0  ...   6 ]   
    typedef int ProgramInvocationState; //   Ic(  [ 0  ...   8 ]   
    typedef int Control_State; //   Ic(  [ 0  ...   2 ]   
    typedef int Running_Mode; //   Ic(  [ 0  ...   2 ]   
    typedef int Priority; //   Ic(  [ 0  ...   127 ]   
    typedef int EC_Class; //   Ic(  [ 0  ...   1 ]   
    typedef int EC_State; //   Ic(  [ 0  ...   2 ]   
    typedef int Severity; //   Ic(  [ 0  ...   127 ]   
    typedef int EE_Class; //   Ic(  [ 0  ...   1 ]   
    typedef bitstring_type Transitions; //    Sc (  [ 7 ]   
    typedef int EE_Duration; //   Ic(  [ 0  ...   1 ]   
    typedef int AlarmAckRule; //   Ic(  [ 0  ...   3 ]   
    ITU_T_IMPLICIT_TYPEDEF(LogicalStatus, int, 0, CONTEXT_CLASS); //   Ic(  [ 0  ...   3 ]   
    ITU_T_IMPLICIT_TYPEDEF(PhysicalStatus, int, 1, CONTEXT_CLASS); //   Ic(  [ 0  ...   3 ]   

    extern const Priority normalPriority;
    extern const Severity normalSeverity;
    extern const oid_type mMSNamedVariable;
    extern const oid_type mMSAccessControlList;
    extern const oid_type mMSEventCondition;

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


    extern const LogicalStatus logicalStatus_state_changes_allowed;
    extern const LogicalStatus logicalStatus_no_state_changes_allowed;
    extern const LogicalStatus logicalStatus_limited_services_permitted;
    extern const LogicalStatus logicalStatus_support_services_allowed;

    extern const PhysicalStatus physicalStatus_operational;
    extern const PhysicalStatus physicalStatus_partially_operational;
    extern const PhysicalStatus physicalStatus_inoperable;
    extern const PhysicalStatus physicalStatus_needs_commissioning;

    extern const VMDState vMDState_idle;
    extern const VMDState vMDState_loaded;
    extern const VMDState vMDState_ready;
    extern const VMDState vMDState_executing;
    extern const VMDState vMDState_motion_paused;
    extern const VMDState vMDState_manualInterventionRequired;

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

        Modifier() : ITU_T_CHOICE(Modifier_enum) () {
        }

        template<typename T > Modifier(boost::shared_ptr< T> vl, Modifier_enum enm) :
                ITU_T_CHOICE(Modifier_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > Modifier(const T& vl, Modifier_enum enm) :
                ITU_T_CHOICE(Modifier_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICEC_DECL(eventModifier, ISO_9506_MMS_1::AttachToEventCondition, Modifier_eventModifier);
        ITU_T_CHOICEC_DECL(semaphoreModifier, ISO_9506_MMS_1::AttachToSemaphore, Modifier_semaphoreModifier);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const ServiceSupportOptions serviceSupportOptions_status;
    extern const ServiceSupportOptions serviceSupportOptions_getNameList;
    extern const ServiceSupportOptions serviceSupportOptions_identify;
    extern const ServiceSupportOptions serviceSupportOptions_rename;
    extern const ServiceSupportOptions serviceSupportOptions_read;
    extern const ServiceSupportOptions serviceSupportOptions_write;
    extern const ServiceSupportOptions serviceSupportOptions_getVariableAccessAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_defineNamedVariable;
    extern const ServiceSupportOptions serviceSupportOptions_defineScatteredAccess;
    extern const ServiceSupportOptions serviceSupportOptions_getScatteredAccessAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_deleteVariableAccess;
    extern const ServiceSupportOptions serviceSupportOptions_defineNamedVariableList;
    extern const ServiceSupportOptions serviceSupportOptions_getNamedVariableListAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_deleteNamedVariableList;
    extern const ServiceSupportOptions serviceSupportOptions_defineNamedType;
    extern const ServiceSupportOptions serviceSupportOptions_getNamedTypeAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_deleteNamedType;
    extern const ServiceSupportOptions serviceSupportOptions_input;
    extern const ServiceSupportOptions serviceSupportOptions_output;
    extern const ServiceSupportOptions serviceSupportOptions_takeControl;
    extern const ServiceSupportOptions serviceSupportOptions_relinquishControl;
    extern const ServiceSupportOptions serviceSupportOptions_defineSemaphore;
    extern const ServiceSupportOptions serviceSupportOptions_deleteSemaphore;
    extern const ServiceSupportOptions serviceSupportOptions_reportSemaphoreStatus;
    extern const ServiceSupportOptions serviceSupportOptions_reportPoolSemaphoreStatus;
    extern const ServiceSupportOptions serviceSupportOptions_reportSemaphoreEntryStatus;
    extern const ServiceSupportOptions serviceSupportOptions_initiateDownloadSequence;
    extern const ServiceSupportOptions serviceSupportOptions_downloadSegment;
    extern const ServiceSupportOptions serviceSupportOptions_terminateDownloadSequence;
    extern const ServiceSupportOptions serviceSupportOptions_initiateUploadSequence;
    extern const ServiceSupportOptions serviceSupportOptions_uploadSegment;
    extern const ServiceSupportOptions serviceSupportOptions_terminateUploadSequence;
    extern const ServiceSupportOptions serviceSupportOptions_requestDomainDownload;
    extern const ServiceSupportOptions serviceSupportOptions_requestDomainUpload;
    extern const ServiceSupportOptions serviceSupportOptions_loadDomainContent;
    extern const ServiceSupportOptions serviceSupportOptions_storeDomainContent;
    extern const ServiceSupportOptions serviceSupportOptions_deleteDomain;
    extern const ServiceSupportOptions serviceSupportOptions_getDomainAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_createProgramInvocation;
    extern const ServiceSupportOptions serviceSupportOptions_deleteProgramInvocation;
    extern const ServiceSupportOptions serviceSupportOptions_start;
    extern const ServiceSupportOptions serviceSupportOptions_stop;
    extern const ServiceSupportOptions serviceSupportOptions_resume;
    extern const ServiceSupportOptions serviceSupportOptions_reset;
    extern const ServiceSupportOptions serviceSupportOptions_kill;
    extern const ServiceSupportOptions serviceSupportOptions_getProgramInvocationAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_obtainFile;
    extern const ServiceSupportOptions serviceSupportOptions_defineEventCondition;
    extern const ServiceSupportOptions serviceSupportOptions_deleteEventCondition;
    extern const ServiceSupportOptions serviceSupportOptions_getEventConditionAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_reportEventConditionStatus;
    extern const ServiceSupportOptions serviceSupportOptions_alterEventConditionMonitoring;
    extern const ServiceSupportOptions serviceSupportOptions_triggerEvent;
    extern const ServiceSupportOptions serviceSupportOptions_defineEventAction;
    extern const ServiceSupportOptions serviceSupportOptions_deleteEventAction;
    extern const ServiceSupportOptions serviceSupportOptions_getEventActionAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_reportEventActionStatus;
    extern const ServiceSupportOptions serviceSupportOptions_defineEventEnrollment;
    extern const ServiceSupportOptions serviceSupportOptions_deleteEventEnrollment;
    extern const ServiceSupportOptions serviceSupportOptions_alterEventEnrollment;
    extern const ServiceSupportOptions serviceSupportOptions_reportEventEnrollmentStatus;
    extern const ServiceSupportOptions serviceSupportOptions_getEventEnrollmentAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_acknowledgeEventNotification;
    extern const ServiceSupportOptions serviceSupportOptions_getAlarmSummary;
    extern const ServiceSupportOptions serviceSupportOptions_getAlarmEnrollmentSummary;
    extern const ServiceSupportOptions serviceSupportOptions_readJournal;
    extern const ServiceSupportOptions serviceSupportOptions_writeJournal;
    extern const ServiceSupportOptions serviceSupportOptions_initializeJournal;
    extern const ServiceSupportOptions serviceSupportOptions_reportJournalStatus;
    extern const ServiceSupportOptions serviceSupportOptions_createJournal;
    extern const ServiceSupportOptions serviceSupportOptions_deleteJournal;
    extern const ServiceSupportOptions serviceSupportOptions_getCapabilityList;
    extern const ServiceSupportOptions serviceSupportOptions_fileOpen;
    extern const ServiceSupportOptions serviceSupportOptions_fileRead;
    extern const ServiceSupportOptions serviceSupportOptions_fileClose;
    extern const ServiceSupportOptions serviceSupportOptions_fileRename;
    extern const ServiceSupportOptions serviceSupportOptions_fileDelete;
    extern const ServiceSupportOptions serviceSupportOptions_fileDirectory;
    extern const ServiceSupportOptions serviceSupportOptions_unsolicitedStatus;
    extern const ServiceSupportOptions serviceSupportOptions_informationReport;
    extern const ServiceSupportOptions serviceSupportOptions_eventNotification;
    extern const ServiceSupportOptions serviceSupportOptions_attachToEventCondition;
    extern const ServiceSupportOptions serviceSupportOptions_attachToSemaphore;
    extern const ServiceSupportOptions serviceSupportOptions_conclude;
    extern const ServiceSupportOptions serviceSupportOptions_cancel;
    extern const ServiceSupportOptions serviceSupportOptions_getDataExchangeAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_exchangeData;
    extern const ServiceSupportOptions serviceSupportOptions_defineAccessControlList;
    extern const ServiceSupportOptions serviceSupportOptions_getAccessControlListAttributes;
    extern const ServiceSupportOptions serviceSupportOptions_reportAccessControlledObjects;
    extern const ServiceSupportOptions serviceSupportOptions_deleteAccessControlList;
    extern const ServiceSupportOptions serviceSupportOptions_alterAccessControl;
    extern const ServiceSupportOptions serviceSupportOptions_reconfigureProgramInvocation;

    extern const ParameterSupportOptions parameterSupportOptions_str1;
    extern const ParameterSupportOptions parameterSupportOptions_str2;
    extern const ParameterSupportOptions parameterSupportOptions_vnam;
    extern const ParameterSupportOptions parameterSupportOptions_valt;
    extern const ParameterSupportOptions parameterSupportOptions_vadr;
    extern const ParameterSupportOptions parameterSupportOptions_vsca;
    extern const ParameterSupportOptions parameterSupportOptions_tpy;
    extern const ParameterSupportOptions parameterSupportOptions_vlis;
    extern const ParameterSupportOptions parameterSupportOptions_cei;
    extern const ParameterSupportOptions parameterSupportOptions_aco;
    extern const ParameterSupportOptions parameterSupportOptions_sem;
    extern const ParameterSupportOptions parameterSupportOptions_csr;
    extern const ParameterSupportOptions parameterSupportOptions_csnc;
    extern const ParameterSupportOptions parameterSupportOptions_csplc;
    extern const ParameterSupportOptions parameterSupportOptions_cspi;
    extern const ParameterSupportOptions parameterSupportOptions_char;

    extern const AdditionalSupportOptions additionalSupportOptions_vMDStop;
    extern const AdditionalSupportOptions additionalSupportOptions_vMDReset;
    extern const AdditionalSupportOptions additionalSupportOptions_select;
    extern const AdditionalSupportOptions additionalSupportOptions_alterProgramInvocationAttributes;
    extern const AdditionalSupportOptions additionalSupportOptions_initiateUnitControlLoad;
    extern const AdditionalSupportOptions additionalSupportOptions_unitControlLoadSegment;
    extern const AdditionalSupportOptions additionalSupportOptions_unitControlUpload;
    extern const AdditionalSupportOptions additionalSupportOptions_startUnitControl;
    extern const AdditionalSupportOptions additionalSupportOptions_stopUnitControl;
    extern const AdditionalSupportOptions additionalSupportOptions_createUnitControl;
    extern const AdditionalSupportOptions additionalSupportOptions_addToUnitControl;
    extern const AdditionalSupportOptions additionalSupportOptions_removeFromUnitControl;
    extern const AdditionalSupportOptions additionalSupportOptions_getUnitControlAttributes;
    extern const AdditionalSupportOptions additionalSupportOptions_loadUnitControlFromFile;
    extern const AdditionalSupportOptions additionalSupportOptions_storeUnitControlToFile;
    extern const AdditionalSupportOptions additionalSupportOptions_deleteUnitControl;
    extern const AdditionalSupportOptions additionalSupportOptions_defineEventConditionList;
    extern const AdditionalSupportOptions additionalSupportOptions_deleteEventConditionList;
    extern const AdditionalSupportOptions additionalSupportOptions_addEventConditionListReference;
    extern const AdditionalSupportOptions additionalSupportOptions_removeEventConditionListReference;
    extern const AdditionalSupportOptions additionalSupportOptions_getEventConditionListAttributes;
    extern const AdditionalSupportOptions additionalSupportOptions_reportEventConditionListStatus;
    extern const AdditionalSupportOptions additionalSupportOptions_alterEventConditionListMonitoring;

    extern const AdditionalCBBOptions additionalCBBOptions_des;
    extern const AdditionalCBBOptions additionalCBBOptions_dei;
    extern const AdditionalCBBOptions additionalCBBOptions_recl;

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

            User_type() : ITU_T_CHOICE(User_type_enum) () {
            }

            template<typename T > User_type(boost::shared_ptr< T> vl, User_type_enum enm) :
                    ITU_T_CHOICE(User_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > User_type(const T& vl, User_type_enum enm) :
                    ITU_T_CHOICE(User_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

            ITU_T_CHOICEC_DECL(association, MMS_Environment_1::ApplicationReference, User_type_association);
            ITU_T_CHOICES_DECL(none, null_type, User_type_none); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef std::vector< AccessCondition > Joint_type;
        typedef std::vector< AccessCondition > Alternate_type;

        AccessCondition() : ITU_T_CHOICE(AccessCondition_enum) () {
        }

        template<typename T > AccessCondition(boost::shared_ptr< T> vl, AccessCondition_enum enm) :
                ITU_T_CHOICE(AccessCondition_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > AccessCondition(const T& vl, AccessCondition_enum enm) :
                ITU_T_CHOICE(AccessCondition_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICES_DECL(never, null_type, AccessCondition_never); // primitive
        ITU_T_CHOICES_DECL(semaphore, ISO_9506_MMS_1::Identifier, AccessCondition_semaphore); // primitive
        ITU_T_CHOICEC_DECL(user, User_type, AccessCondition_user);
        ITU_T_CHOICEC_DECL(password, ACSE_1::Authentication_value, AccessCondition_password);
        ITU_T_CHOICEC_DECL(joint, Joint_type, AccessCondition_joint);
        ITU_T_CHOICEC_DECL(alternate, Alternate_type, AccessCondition_alternate);

        ITU_T_ARCHIVE_FUNC;
    };

    extern const DomainState domainState_non_existent;
    extern const DomainState domainState_loading;
    extern const DomainState domainState_ready;
    extern const DomainState domainState_in_use;
    extern const DomainState domainState_complete;
    extern const DomainState domainState_incomplete;
    extern const DomainState domainState_d1;
    extern const DomainState domainState_d2;
    extern const DomainState domainState_d3;
    extern const DomainState domainState_d4;
    extern const DomainState domainState_d5;
    extern const DomainState domainState_d6;
    extern const DomainState domainState_d7;
    extern const DomainState domainState_d8;
    extern const DomainState domainState_d9;

    extern const ULState uLState_non_existent;
    extern const ULState uLState_uploading;
    extern const ULState uLState_uploaded;
    extern const ULState uLState_u1;
    extern const ULState uLState_u2;
    extern const ULState uLState_u3;
    extern const ULState uLState_u4;

    extern const ProgramInvocationState programInvocationState_non_existent;
    extern const ProgramInvocationState programInvocationState_unrunnable;
    extern const ProgramInvocationState programInvocationState_idle;
    extern const ProgramInvocationState programInvocationState_running;
    extern const ProgramInvocationState programInvocationState_stopped;
    extern const ProgramInvocationState programInvocationState_starting;
    extern const ProgramInvocationState programInvocationState_stopping;
    extern const ProgramInvocationState programInvocationState_resuming;
    extern const ProgramInvocationState programInvocationState_resetting;

    extern const Control_State control_State_normal;
    extern const Control_State control_State_controlling;
    extern const Control_State control_State_controlled;

    extern const Running_Mode running_Mode_free_run;
    extern const Running_Mode running_Mode_cycle_limited;
    extern const Running_Mode running_Mode_step_limited;

    // choice Address

    enum Address_enum {

        Address_null = 0,
        Address_numericAddress,
        Address_symbolicAddress,
        Address_unconstrainedAddress,
    };

    struct Address : public ITU_T_CHOICE(Address_enum) {

        Address() : ITU_T_CHOICE(Address_enum) () {
        }

        template<typename T > Address(boost::shared_ptr< T> vl, Address_enum enm) :
                ITU_T_CHOICE(Address_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > Address(const T& vl, Address_enum enm) :
                ITU_T_CHOICE(Address_enum) (new T(vl), static_cast<int> (enm)) {
        }

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

            Array_type(boost::shared_ptr< bool> arg__packed,
                    boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__numberOfElements,
                    boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__elementType);

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

                Components_type_sequence_of(boost::shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
                        boost::shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__componentType);

                ITU_T_OPTIONAL_DECL(componentName, ISO_9506_MMS_1::Identifier);
                ITU_T_HOLDERH_DECL(componentType, ISO_9506_MMS_1::TypeSpecification);

                ITU_T_ARCHIVE_FUNC;
            };



            typedef std::vector< Components_type_sequence_of > Components_type;

            static const bool packed__default;

            Structure_type();

            Structure_type(const Components_type& arg__components);

            Structure_type(boost::shared_ptr< bool> arg__packed,
                    boost::shared_ptr< Components_type> arg__components);

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

        TypeDescription() : ITU_T_CHOICE(TypeDescription_enum) () {
        }

        template<typename T > TypeDescription(boost::shared_ptr< T> vl, TypeDescription_enum enm) :
                ITU_T_CHOICE(TypeDescription_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > TypeDescription(const T& vl, TypeDescription_enum enm) :
                ITU_T_CHOICE(TypeDescription_enum) (new T(vl), static_cast<int> (enm)) {
        }

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

    extern const EC_Class eC_Class_network_triggered;
    extern const EC_Class eC_Class_monitored;

    extern const EC_State eC_State_disabled;
    extern const EC_State eC_State_idle;
    extern const EC_State eC_State_active;

    // choice EventTime

    enum EventTime_enum {

        EventTime_null = 0,
        EventTime_timeOfDay,
        EventTime_timeSequenceIdentifier,
        EventTime_undefined,
    };

    struct EventTime : public ITU_T_CHOICE(EventTime_enum) {

        EventTime() : ITU_T_CHOICE(EventTime_enum) () {
        }

        template<typename T > EventTime(boost::shared_ptr< T> vl, EventTime_enum enm) :
                ITU_T_CHOICE(EventTime_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > EventTime(const T& vl, EventTime_enum enm) :
                ITU_T_CHOICE(EventTime_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICES_DECL(timeOfDay, ISO_9506_MMS_1::TimeOfDay, EventTime_timeOfDay); // primitive  //    Sc (  [ 4  ...   6 ]   
        ITU_T_CHOICES_DECL(timeSequenceIdentifier, ISO_9506_MMS_1::Unsigned32, EventTime_timeSequenceIdentifier); // primitive  //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_CHOICES_DECL(undefined, null_type, EventTime_undefined); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    extern const EE_Class eE_Class_modifier;
    extern const EE_Class eE_Class_notification;

    extern const Transitions transitions_idle_to_disabled;
    extern const Transitions transitions_active_to_disabled;
    extern const Transitions transitions_disabled_to_idle;
    extern const Transitions transitions_active_to_idle;
    extern const Transitions transitions_disabled_to_active;
    extern const Transitions transitions_idle_to_active;
    extern const Transitions transitions_any_to_deleted;

    extern const EE_Duration eE_Duration_current;
    extern const EE_Duration eE_Duration_permanent;

    extern const AlarmAckRule alarmAckRule_none;
    extern const AlarmAckRule alarmAckRule_simple;
    extern const AlarmAckRule alarmAckRule_ack_active;
    extern const AlarmAckRule alarmAckRule_ack_all;

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
    template<> void AccessCondition::User_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void AccessCondition::User_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Address::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Address::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::Array_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::Array_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void EventTime::serialize(boost::asn1::x690::output_coder& arch);
    template<> void EventTime::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Variable::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Variable::serialize(boost::asn1::x690::input_coder& arch);
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
