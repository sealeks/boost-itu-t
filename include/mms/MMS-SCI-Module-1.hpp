#ifndef ___MMS_SCI_MODULE_1
#define ___MMS_SCI_MODULE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {

    ITU_T_USE_UNIVESAL_DECL;


    struct SCI_Information;
    struct VMD_File;
    struct Access_Control_List_instance;
    struct Domain_instance;
    struct Program_Invocation_instance;
    struct Unit_Control_instance;
    struct Unnamed_Variable_instance;
    struct Named_Variable_instance;
    struct Named_Variable_List_instance;
    struct Variable_List_Item_instance;
    struct Named_Type_instance;
    struct Data_Exchange_instance;
    struct Semaphore_instance;
    struct Operator_Station_instance;
    struct Event_Condition_instance;
    struct Event_Action_instance;
    struct Event_Enrollment_instance;
    struct Event_Condition_List_instance;
    struct Journal_instance;
    struct Journal_Entry_instance;
    struct Service_and_Parameter_CBBs;
    struct GeneralManagementParameters;
    struct VMDSupportParameters;
    struct DomainManagementParameters;
    struct ProgramInvocationManagementParameters;
    struct VariableAccessParameters;
    struct DataParameters;
    struct SemaphoreManagementParameters;
    struct OperatorCommunicationParameters;
    struct ErrorParameters;
    struct FileManagementParameters;



}

#include "MMS-Environment-1.hpp"
#include "MMS-Object-Module-1.hpp"
#include "ISO-9506-MMS-1.hpp"

namespace MMS_SCI_Module_1 {

    // import   from  MMS-Environment-1

    using MMS_Environment_1::ApplicationReference;


    // import   from  MMS-Object-Module-1

    using MMS_Object_Module_1::AccessCondition;
    using MMS_Object_Module_1::AdditionalCBBOptions;
    using MMS_Object_Module_1::AdditionalSupportOptions;
    using MMS_Object_Module_1::Address;
    using MMS_Object_Module_1::AlarmAckRule;
    using MMS_Object_Module_1::DomainState;
    using MMS_Object_Module_1::LogicalStatus;
    using MMS_Object_Module_1::Modifier;
    using MMS_Object_Module_1::ParameterSupportOptions;
    using MMS_Object_Module_1::PhysicalStatus;
    using MMS_Object_Module_1::Priority;
    using MMS_Object_Module_1::ProgramInvocationState;
    using MMS_Object_Module_1::ServiceSupportOptions;
    using MMS_Object_Module_1::Severity;
    using MMS_Object_Module_1::Transitions;
    using MMS_Object_Module_1::TypeDescription;


    // import   from  ISO-9506-MMS-1

    using ISO_9506_MMS_1::AlternateAccess;
    using ISO_9506_MMS_1::ConfirmedServiceRequest;
    using ISO_9506_MMS_1::AttachToEventCondition;
    using ISO_9506_MMS_1::AttachToSemaphore;
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


    // sequence SCI-Information

    struct SCI_Information {

        SCI_Information();

        SCI_Information(const VMD_File& arg__partOne,
                const Service_and_Parameter_CBBs& arg__partTwo);

        ITU_T_HOLDERH_DECL(partOne, VMD_File);
        ITU_T_HOLDERH_DECL(partTwo, Service_and_Parameter_CBBs);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence VMD-File

    struct VMD_File {

        struct Selected_Program_Invocation_type;

        enum Selected_Program_Invocation_type_enum {

            Selected_Program_Invocation_type_null = 0,
            Selected_Program_Invocation_type_selectedProgram,
            Selected_Program_Invocation_type_noneSelected,
        };

        struct Selected_Program_Invocation_type : public ITU_T_CHOICE(Selected_Program_Invocation_type_enum) {


            ITU_T_CHOICE_CTORS(Selected_Program_Invocation_type);

            ITU_T_CHOICEC_DECL(selectedProgram, Program_Invocation_instance, Selected_Program_Invocation_type_selectedProgram);
            ITU_T_CHOICES_DECL(noneSelected, null_type, Selected_Program_Invocation_type_noneSelected); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< Access_Control_List_instance > AccessControlLists_type;
        typedef sequence_of< Domain_instance > Domains_type;
        typedef sequence_of< Program_Invocation_instance > ProgramInvocations_type;
        typedef sequence_of< Unit_Control_instance > UnitControls_type;
        typedef sequence_of< Unnamed_Variable_instance > UnnamedVariables_type;
        typedef sequence_of< Named_Variable_instance > NamedVariables_type;
        typedef sequence_of< Named_Variable_List_instance > NamedVariableLists_type;
        typedef sequence_of< Named_Type_instance > NamedTypes_type;
        typedef sequence_of< Data_Exchange_instance > DataExchanges_type;
        typedef sequence_of< Semaphore_instance > Semaphores_type;
        typedef sequence_of< Operator_Station_instance > OperatorStations_type;
        typedef sequence_of< Event_Condition_instance > EventConditions_type;
        typedef sequence_of< Event_Action_instance > EventActions_type;
        typedef sequence_of< Event_Enrollment_instance > EventEnrollments_type;
        typedef sequence_of< Event_Condition_List_instance > EventConditionLists_type;
        typedef sequence_of< Journal_instance > Journals_type;

        typedef sequence_of< ISO_9506_MMS_1::MMSString > Capabilities_type;

        VMD_File();

        VMD_File(const MMS_Environment_1::ApplicationReference& arg__executiveFunction,
                const ISO_9506_MMS_1::MMSString& arg__vendorName,
                const ISO_9506_MMS_1::MMSString& arg__modelName,
                const ISO_9506_MMS_1::MMSString& arg__revision,
                const oid_type& arg__abstractSyntaxes,
                const Access_Control_List_instance& arg__accessControl,
                const MMS_Object_Module_1::LogicalStatus& arg__logicalStatus,
                const Capabilities_type& arg__capabilities,
                const MMS_Object_Module_1::PhysicalStatus& arg__physicalStatus,
                const bit_string& arg__local_detail,
                const AccessControlLists_type& arg__accessControlLists,
                const Domains_type& arg__domains,
                const ProgramInvocations_type& arg__programInvocations,
                const UnitControls_type& arg__unitControls,
                const UnnamedVariables_type& arg__unnamedVariables,
                const NamedVariables_type& arg__namedVariables,
                const NamedVariableLists_type& arg__namedVariableLists,
                const NamedTypes_type& arg__namedTypes,
                const DataExchanges_type& arg__dataExchanges,
                const Semaphores_type& arg__semaphores,
                const OperatorStations_type& arg__operatorStations,
                const EventConditions_type& arg__eventConditions,
                const EventActions_type& arg__eventActions,
                const EventEnrollments_type& arg__eventEnrollments,
                const EventConditionLists_type& arg__eventConditionLists,
                const Journals_type& arg__journals);

        VMD_File(shared_ptr< MMS_Environment_1::ApplicationReference> arg__executiveFunction,
                shared_ptr< ISO_9506_MMS_1::MMSString> arg__vendorName,
                shared_ptr< ISO_9506_MMS_1::MMSString> arg__modelName,
                shared_ptr< ISO_9506_MMS_1::MMSString> arg__revision,
                shared_ptr< oid_type> arg__abstractSyntaxes,
                shared_ptr< Access_Control_List_instance> arg__accessControl,
                shared_ptr< MMS_Object_Module_1::LogicalStatus> arg__logicalStatus,
                shared_ptr< Capabilities_type> arg__capabilities,
                shared_ptr< MMS_Object_Module_1::PhysicalStatus> arg__physicalStatus,
                shared_ptr< bit_string> arg__local_detail,
                shared_ptr< AccessControlLists_type> arg__accessControlLists,
                shared_ptr< Domains_type> arg__domains,
                shared_ptr< ProgramInvocations_type> arg__programInvocations,
                shared_ptr< UnitControls_type> arg__unitControls,
                shared_ptr< UnnamedVariables_type> arg__unnamedVariables,
                shared_ptr< NamedVariables_type> arg__namedVariables,
                shared_ptr< NamedVariableLists_type> arg__namedVariableLists,
                shared_ptr< NamedTypes_type> arg__namedTypes,
                shared_ptr< DataExchanges_type> arg__dataExchanges,
                shared_ptr< Semaphores_type> arg__semaphores,
                shared_ptr< OperatorStations_type> arg__operatorStations,
                shared_ptr< EventConditions_type> arg__eventConditions,
                shared_ptr< EventActions_type> arg__eventActions,
                shared_ptr< EventEnrollments_type> arg__eventEnrollments,
                shared_ptr< EventConditionLists_type> arg__eventConditionLists,
                shared_ptr< Journals_type> arg__journals,
                shared_ptr< Selected_Program_Invocation_type> arg__selected_Program_Invocation = shared_ptr< Selected_Program_Invocation_type>());

        ITU_T_HOLDERH_DECL(executiveFunction, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(vendorName, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(modelName, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(revision, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(abstractSyntaxes, oid_type);
        ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
        ITU_T_HOLDERH_DECL(logicalStatus, MMS_Object_Module_1::LogicalStatus); //   Ic(  [ 0  ...   3 ]   
        ITU_T_HOLDERH_DECL(capabilities, Capabilities_type);
        ITU_T_HOLDERH_DECL(physicalStatus, MMS_Object_Module_1::PhysicalStatus); //   Ic(  [ 0  ...   3 ]   
        ITU_T_HOLDERH_DECL(local_detail, bit_string);
        ITU_T_HOLDERH_DECL(accessControlLists, AccessControlLists_type);
        ITU_T_HOLDERH_DECL(domains, Domains_type);
        ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);
        ITU_T_HOLDERH_DECL(unitControls, UnitControls_type);
        ITU_T_HOLDERH_DECL(unnamedVariables, UnnamedVariables_type);
        ITU_T_HOLDERH_DECL(namedVariables, NamedVariables_type);
        ITU_T_HOLDERH_DECL(namedVariableLists, NamedVariableLists_type);
        ITU_T_HOLDERH_DECL(namedTypes, NamedTypes_type);
        ITU_T_HOLDERH_DECL(dataExchanges, DataExchanges_type);
        ITU_T_HOLDERH_DECL(semaphores, Semaphores_type);
        ITU_T_HOLDERH_DECL(operatorStations, OperatorStations_type);
        ITU_T_HOLDERH_DECL(eventConditions, EventConditions_type);
        ITU_T_HOLDERH_DECL(eventActions, EventActions_type);
        ITU_T_HOLDERH_DECL(eventEnrollments, EventEnrollments_type);
        ITU_T_HOLDERH_DECL(eventConditionLists, EventConditionLists_type);
        ITU_T_HOLDERH_DECL(journals, Journals_type);
        ITU_T_OPTIONAL_DECL(selected_Program_Invocation, Selected_Program_Invocation_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Access-Control-List-instance

    struct Access_Control_List_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Access_Control_List_instance > AccessControlLists_type;
                typedef sequence_of< Domain_instance > Domains_type;
                typedef sequence_of< Program_Invocation_instance > ProgramInvocations_type;
                typedef sequence_of< Unit_Control_instance > UnitControls_type;
                typedef sequence_of< Unnamed_Variable_instance > UnnamedVariables_type;
                typedef sequence_of< Named_Variable_instance > NamedVariables_type;
                typedef sequence_of< Named_Variable_List_instance > NamedVariableLists_type;
                typedef sequence_of< Named_Type_instance > NamedTypes_type;
                typedef sequence_of< Data_Exchange_instance > DataExchanges_type;
                typedef sequence_of< Semaphore_instance > Semaphores_type;
                typedef sequence_of< Operator_Station_instance > OperatorStations_type;
                typedef sequence_of< Event_Condition_instance > EventConditions_type;
                typedef sequence_of< Event_Action_instance > EventActions_type;
                typedef sequence_of< Event_Enrollment_instance > EventEnrollments_type;
                typedef sequence_of< Journal_instance > Journals_type;
                typedef sequence_of< Event_Condition_List_instance > EventConditionLists_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const AccessControlLists_type& arg__accessControlLists,
                        const Domains_type& arg__domains,
                        const ProgramInvocations_type& arg__programInvocations,
                        const UnitControls_type& arg__unitControls,
                        const UnnamedVariables_type& arg__unnamedVariables,
                        const NamedVariables_type& arg__namedVariables,
                        const NamedVariableLists_type& arg__namedVariableLists,
                        const NamedTypes_type& arg__namedTypes,
                        const DataExchanges_type& arg__dataExchanges,
                        const Semaphores_type& arg__semaphores,
                        const OperatorStations_type& arg__operatorStations,
                        const EventConditions_type& arg__eventConditions,
                        const EventActions_type& arg__eventActions,
                        const EventEnrollments_type& arg__eventEnrollments,
                        const Journals_type& arg__journals);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
                        shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition,
                        shared_ptr< AccessControlLists_type> arg__accessControlLists,
                        shared_ptr< Domains_type> arg__domains,
                        shared_ptr< ProgramInvocations_type> arg__programInvocations,
                        shared_ptr< UnitControls_type> arg__unitControls,
                        shared_ptr< UnnamedVariables_type> arg__unnamedVariables,
                        shared_ptr< NamedVariables_type> arg__namedVariables,
                        shared_ptr< NamedVariableLists_type> arg__namedVariableLists,
                        shared_ptr< NamedTypes_type> arg__namedTypes,
                        shared_ptr< DataExchanges_type> arg__dataExchanges,
                        shared_ptr< Semaphores_type> arg__semaphores,
                        shared_ptr< OperatorStations_type> arg__operatorStations,
                        shared_ptr< EventConditions_type> arg__eventConditions,
                        shared_ptr< EventActions_type> arg__eventActions,
                        shared_ptr< EventEnrollments_type> arg__eventEnrollments,
                        shared_ptr< Journals_type> arg__journals,
                        shared_ptr< EventConditionLists_type> arg__eventConditionLists = shared_ptr< EventConditionLists_type>());

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_OPTIONAL_DECL(readAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_OPTIONAL_DECL(storeAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_OPTIONAL_DECL(writeAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_OPTIONAL_DECL(loadAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_OPTIONAL_DECL(executeAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_OPTIONAL_DECL(deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_OPTIONAL_DECL(editAccessCondition, MMS_Object_Module_1::AccessCondition);
                ITU_T_HOLDERH_DECL(accessControlLists, AccessControlLists_type);
                ITU_T_HOLDERH_DECL(domains, Domains_type);
                ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);
                ITU_T_HOLDERH_DECL(unitControls, UnitControls_type);
                ITU_T_HOLDERH_DECL(unnamedVariables, UnnamedVariables_type);
                ITU_T_HOLDERH_DECL(namedVariables, NamedVariables_type);
                ITU_T_HOLDERH_DECL(namedVariableLists, NamedVariableLists_type);
                ITU_T_HOLDERH_DECL(namedTypes, NamedTypes_type);
                ITU_T_HOLDERH_DECL(dataExchanges, DataExchanges_type);
                ITU_T_HOLDERH_DECL(semaphores, Semaphores_type);
                ITU_T_HOLDERH_DECL(operatorStations, OperatorStations_type);
                ITU_T_HOLDERH_DECL(eventConditions, EventConditions_type);
                ITU_T_HOLDERH_DECL(eventActions, EventActions_type);
                ITU_T_HOLDERH_DECL(eventEnrollments, EventEnrollments_type);
                ITU_T_HOLDERH_DECL(journals, Journals_type);
                ITU_T_OPTIONAL_DECL(eventConditionLists, EventConditionLists_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Access_Control_List_instance();

        Access_Control_List_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Domain-instance

    struct Domain_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Program_Invocation_instance > ProgramInvocations_type;
                typedef sequence_of< Named_Variable_instance > NamedVariables_type;
                typedef sequence_of< Named_Variable_List_instance > NamedVariableLists_type;
                typedef sequence_of< Named_Type_instance > NamedTypes_type;
                typedef sequence_of< Event_Condition_instance > EventConditions_type;
                typedef sequence_of< Event_Action_instance > EventActions_type;
                typedef sequence_of< Event_Enrollment_instance > EventEnrollments_type;
                typedef sequence_of< Event_Condition_List_instance > EventConditionLists_type;

                typedef sequence_of< ISO_9506_MMS_1::MMSString > Capabilities_type;

                Details_type();

                Details_type(const Capabilities_type& arg__capabilities,
                        const MMS_Object_Module_1::DomainState& arg__state,
                        const Access_Control_List_instance& arg__accessControl,
                        const bool& arg__sharable,
                        const ProgramInvocations_type& arg__programInvocations,
                        const NamedVariables_type& arg__namedVariables,
                        const NamedVariableLists_type& arg__namedVariableLists,
                        const NamedTypes_type& arg__namedTypes,
                        const EventConditions_type& arg__eventConditions,
                        const EventActions_type& arg__eventActions,
                        const EventEnrollments_type& arg__eventEnrollments,
                        const EventConditionLists_type& arg__eventConditionLists);

                ITU_T_HOLDERH_DECL(capabilities, Capabilities_type);
                ITU_T_HOLDERH_DECL(state, MMS_Object_Module_1::DomainState); //   Ic(  [ 0  ...   15 ]   
                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(sharable, bool);
                ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);
                ITU_T_HOLDERH_DECL(namedVariables, NamedVariables_type);
                ITU_T_HOLDERH_DECL(namedVariableLists, NamedVariableLists_type);
                ITU_T_HOLDERH_DECL(namedTypes, NamedTypes_type);
                ITU_T_HOLDERH_DECL(eventConditions, EventConditions_type);
                ITU_T_HOLDERH_DECL(eventActions, EventActions_type);
                ITU_T_HOLDERH_DECL(eventEnrollments, EventEnrollments_type);
                ITU_T_HOLDERH_DECL(eventConditionLists, EventConditionLists_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Domain_instance();

        Domain_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Program-Invocation-instance

    struct Program_Invocation_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Domain_instance > Domains_type;
                typedef sequence_of< Access_Control_List_instance > AccessControl_type;
                typedef sequence_of< Event_Condition_instance > EventCondition_type;
                typedef sequence_of< Event_Action_instance > EventAction_type;
                typedef sequence_of< Event_Enrollment_instance > EventEnrollment_type;
                typedef sequence_of< Program_Invocation_instance > Controlled_Program_Invocations_type;


                Details_type();

                Details_type(const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState,
                        const Domains_type& arg__domains,
                        const AccessControl_type& arg__accessControl,
                        const bool& arg__reusable,
                        const bool& arg__monitor,
                        const ISO_9506_MMS_1::MMSString& arg__executionArgument);

                Details_type(shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__programInvocationState,
                        shared_ptr< Domains_type> arg__domains,
                        shared_ptr< AccessControl_type> arg__accessControl,
                        shared_ptr< bool> arg__reusable,
                        shared_ptr< bool> arg__monitor,
                        shared_ptr< EventCondition_type> arg__eventCondition,
                        shared_ptr< EventAction_type> arg__eventAction,
                        shared_ptr< EventEnrollment_type> arg__eventEnrollment,
                        shared_ptr< ISO_9506_MMS_1::MMSString> arg__executionArgument,
                        shared_ptr< MMS_Object_Module_1::Control_State> arg__control = shared_ptr< MMS_Object_Module_1::Control_State>(),
                        shared_ptr< Program_Invocation_instance> arg__controlling_Program_Invocation = shared_ptr< Program_Invocation_instance>(),
                        shared_ptr< Controlled_Program_Invocations_type> arg__controlled_Program_Invocations = shared_ptr< Controlled_Program_Invocations_type>());

                ITU_T_HOLDERH_DECL(programInvocationState, MMS_Object_Module_1::ProgramInvocationState); //   Ic(  [ 0  ...   8 ]   
                ITU_T_HOLDERH_DECL(domains, Domains_type);
                ITU_T_HOLDERH_DECL(accessControl, AccessControl_type);
                ITU_T_HOLDERH_DECL(reusable, bool);
                ITU_T_HOLDERH_DECL(monitor, bool);
                ITU_T_OPTIONAL_DECL(eventCondition, EventCondition_type);
                ITU_T_OPTIONAL_DECL(eventAction, EventAction_type);
                ITU_T_OPTIONAL_DECL(eventEnrollment, EventEnrollment_type);
                ITU_T_HOLDERH_DECL(executionArgument, ISO_9506_MMS_1::MMSString);
                ITU_T_OPTIONAL_DECL(control, MMS_Object_Module_1::Control_State); //   Ic(  [ 0  ...   2 ]   
                ITU_T_OPTIONAL_DECL(controlling_Program_Invocation, Program_Invocation_instance);
                ITU_T_OPTIONAL_DECL(controlled_Program_Invocations, Controlled_Program_Invocations_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Program_Invocation_instance();

        Program_Invocation_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Unit-Control-instance

    struct Unit_Control_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Domain_instance > Domains_type;
                typedef sequence_of< Program_Invocation_instance > ProgramInvocations_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const Domains_type& arg__domains,
                        const ProgramInvocations_type& arg__programInvocations);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(domains, Domains_type);
                ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Unit_Control_instance();

        Unit_Control_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Unnamed-Variable-instance

    struct Unnamed_Variable_instance {

        Unnamed_Variable_instance();

        Unnamed_Variable_instance(const MMS_Object_Module_1::Address& arg__address,
                const Access_Control_List_instance& arg__accessControl,
                const MMS_Object_Module_1::TypeDescription& arg__typeDescription);

        ITU_T_HOLDERH_DECL(address, MMS_Object_Module_1::Address);
        ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
        ITU_T_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Named-Variable-instance

    struct Named_Variable_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const MMS_Object_Module_1::TypeDescription& arg__typeDescription);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
                        shared_ptr< MMS_Object_Module_1::Address> arg__address,
                        shared_ptr< visible_string> arg__meaning);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
                ITU_T_OPTIONAL_DECL(address, MMS_Object_Module_1::Address);
                ITU_T_OPTIONAL_DECL(meaning, visible_string);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Named_Variable_instance();

        Named_Variable_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Named-Variable-List-instance

    struct Named_Variable_List_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Variable_List_Item_instance > ListOfVariables_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const ListOfVariables_type& arg__listOfVariables);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(listOfVariables, ListOfVariables_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Named_Variable_List_instance();

        Named_Variable_List_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Variable-List-Item-instance

    struct Variable_List_Item_instance {

        Variable_List_Item_instance();

        Variable_List_Item_instance(shared_ptr< Unnamed_Variable_instance> arg__unnamedItem,
                shared_ptr< Named_Variable_instance> arg__namedItem,
                shared_ptr< ISO_9506_MMS_1::AlternateAccess> arg__alternateAccess);

        ITU_T_OPTIONAL_DECL(unnamedItem, Unnamed_Variable_instance);
        ITU_T_OPTIONAL_DECL(namedItem, Named_Variable_instance);
        ITU_T_OPTIONAL_DECL(alternateAccess, ISO_9506_MMS_1::AlternateAccess);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Named-Type-instance

    struct Named_Type_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const MMS_Object_Module_1::TypeDescription& arg__typeDescription);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
                        shared_ptr< visible_string> arg__meaning);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
                ITU_T_OPTIONAL_DECL(meaning, visible_string);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Named_Type_instance();

        Named_Type_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Data-Exchange-instance

    struct Data_Exchange_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< MMS_Object_Module_1::TypeDescription > Request_type;
                typedef sequence_of< MMS_Object_Module_1::TypeDescription > Response_type;

                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const Request_type& arg__request,
                        const Response_type& arg__response,
                        const bool& arg__linked);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< Request_type> arg__request,
                        shared_ptr< Response_type> arg__response,
                        shared_ptr< bool> arg__linked,
                        shared_ptr< Program_Invocation_instance> arg__programInvocation);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(request, Request_type);
                ITU_T_HOLDERH_DECL(response, Response_type);
                ITU_T_HOLDERH_DECL(linked, bool);
                ITU_T_OPTIONAL_DECL(programInvocation, Program_Invocation_instance);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Data_Exchange_instance();

        Data_Exchange_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Semaphore-instance

    struct Semaphore_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< visible_string > NamedTokens_type; //  struct of ->  

                static const enumerated classV_token;
                static const enumerated classV_pool;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const enumerated& arg__classV,
                        const Event_Condition_instance& arg__eventCondition);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< enumerated> arg__classV,
                        shared_ptr< integer_type> arg__numberOfTokens,
                        shared_ptr< NamedTokens_type> arg__namedTokens,
                        shared_ptr< Event_Condition_instance> arg__eventCondition);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(classV, enumerated);
                ITU_T_OPTIONAL_DECL(numberOfTokens, integer_type);
                ITU_T_OPTIONAL_DECL(namedTokens, NamedTokens_type); //  struct of ->  
                ITU_T_HOLDERH_DECL(eventCondition, Event_Condition_instance);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Semaphore_instance();

        Semaphore_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Operator-Station-instance

    struct Operator_Station_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                static const enumerated stationType_entry;
                static const enumerated stationType_display;
                static const enumerated stationType_entry_display;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const enumerated& arg__stationType);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(stationType, enumerated);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Operator_Station_instance();

        Operator_Station_instance(const ISO_9506_MMS_1::Identifier& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Event-Condition-instance

    struct Event_Condition_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                struct MonitoredVariable_type;
                struct DisplayEnhancement_type;
                struct Group_Priority_Override_type;

                enum MonitoredVariable_type_enum {

                    MonitoredVariable_type_null = 0,
                    MonitoredVariable_type_named,
                    MonitoredVariable_type_unnamed,
                    MonitoredVariable_type_unspecified,
                };

                struct MonitoredVariable_type : public ITU_T_CHOICE(MonitoredVariable_type_enum) {


                    ITU_T_CHOICE_CTORS(MonitoredVariable_type);

                    ITU_T_CHOICEC_DECL(named, Named_Variable_instance, MonitoredVariable_type_named);
                    ITU_T_CHOICEC_DECL(unnamed, Unnamed_Variable_instance, MonitoredVariable_type_unnamed);
                    ITU_T_CHOICES_DECL(unspecified, null_type, MonitoredVariable_type_unspecified); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };

                enum DisplayEnhancement_type_enum {

                    DisplayEnhancement_type_null = 0,
                    DisplayEnhancement_type_text,
                    DisplayEnhancement_type_number,
                    DisplayEnhancement_type_none,
                };

                struct DisplayEnhancement_type : public ITU_T_CHOICE(DisplayEnhancement_type_enum) {


                    ITU_T_CHOICE_CTORS(DisplayEnhancement_type);

                    ITU_T_CHOICES_DECL(text, ISO_9506_MMS_1::MMSString, DisplayEnhancement_type_text); // primitive
                    ITU_T_CHOICES_DECL(number, integer_type, DisplayEnhancement_type_number); // primitive
                    ITU_T_CHOICES_DECL(none, null_type, DisplayEnhancement_type_none); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };

                enum Group_Priority_Override_type_enum {

                    Group_Priority_Override_type_null = 0,
                    Group_Priority_Override_type_priority,
                    Group_Priority_Override_type_undefined,
                };

                struct Group_Priority_Override_type : public ITU_T_CHOICE(Group_Priority_Override_type_enum) {


                    ITU_T_CHOICE_CTORS(Group_Priority_Override_type);

                    ITU_T_CHOICES_DECL(priority, MMS_Object_Module_1::Priority, Group_Priority_Override_type_priority); // primitive  //   Ic(  [ 0  ...   127 ]   
                    ITU_T_CHOICES_DECL(undefined, null_type, Group_Priority_Override_type_undefined); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };



                typedef sequence_of< Event_Enrollment_instance > EventEnrollments_type;
                typedef sequence_of< Event_Condition_List_instance > ReferencingEventConditionLists_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const MMS_Object_Module_1::EC_Class& arg__ecClass,
                        const MMS_Object_Module_1::EC_State& arg__ecState,
                        const MMS_Object_Module_1::Priority& arg__priority,
                        const MMS_Object_Module_1::Severity& arg__severity,
                        const EventEnrollments_type& arg__eventEnrollments);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< MMS_Object_Module_1::EC_Class> arg__ecClass,
                        shared_ptr< MMS_Object_Module_1::EC_State> arg__ecState,
                        shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                        shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
                        shared_ptr< EventEnrollments_type> arg__eventEnrollments,
                        shared_ptr< bool> arg__enabled,
                        shared_ptr< bool> arg__alarmSummaryReports,
                        shared_ptr< MonitoredVariable_type> arg__monitoredVariable,
                        shared_ptr< integer_type> arg__evaluationInterval,
                        shared_ptr< DisplayEnhancement_type> arg__displayEnhancement = shared_ptr< DisplayEnhancement_type>(),
                        shared_ptr< Group_Priority_Override_type> arg__group_Priority_Override = shared_ptr< Group_Priority_Override_type>(),
                        shared_ptr< ReferencingEventConditionLists_type> arg__referencingEventConditionLists = shared_ptr< ReferencingEventConditionLists_type>());

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(ecClass, MMS_Object_Module_1::EC_Class); //   Ic(  [ 0  ...   1 ]   
                ITU_T_HOLDERH_DECL(ecState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   
                ITU_T_HOLDERH_DECL(priority, MMS_Object_Module_1::Priority); //   Ic(  [ 0  ...   127 ]   
                ITU_T_HOLDERH_DECL(severity, MMS_Object_Module_1::Severity); //   Ic(  [ 0  ...   127 ]   
                ITU_T_HOLDERH_DECL(eventEnrollments, EventEnrollments_type);
                ITU_T_OPTIONAL_DECL(enabled, bool);
                ITU_T_OPTIONAL_DECL(alarmSummaryReports, bool);
                ITU_T_OPTIONAL_DECL(monitoredVariable, MonitoredVariable_type);
                ITU_T_OPTIONAL_DECL(evaluationInterval, integer_type);
                ITU_T_OPTIONAL_DECL(displayEnhancement, DisplayEnhancement_type);
                ITU_T_OPTIONAL_DECL(group_Priority_Override, Group_Priority_Override_type);
                ITU_T_OPTIONAL_DECL(referencingEventConditionLists, ReferencingEventConditionLists_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Event_Condition_instance();

        Event_Condition_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Event-Action-instance

    struct Event_Action_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Event_Enrollment_instance > EventEnrollments_type;

                typedef sequence_of< MMS_Object_Module_1::Modifier > Modifiers_type;

                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const ISO_9506_MMS_1::ConfirmedServiceRequest& arg__confirmedServiceRequest,
                        const Modifiers_type& arg__modifiers,
                        const EventEnrollments_type& arg__eventEnrollments);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(confirmedServiceRequest, ISO_9506_MMS_1::ConfirmedServiceRequest);
                ITU_T_HOLDERH_DECL(modifiers, Modifiers_type);
                ITU_T_HOLDERH_DECL(eventEnrollments, EventEnrollments_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Event_Action_instance();

        Event_Action_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Event-Enrollment-instance

    struct Event_Enrollment_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                struct RemainingDelay_type;
                struct DisplayEnhancement_type;

                enum RemainingDelay_type_enum {

                    RemainingDelay_type_null = 0,
                    RemainingDelay_type_time,
                    RemainingDelay_type_forever,
                };

                struct RemainingDelay_type : public ITU_T_CHOICE(RemainingDelay_type_enum) {


                    ITU_T_CHOICE_CTORS(RemainingDelay_type);

                    ITU_T_CHOICES_DECL(time, integer_type, RemainingDelay_type_time); // primitive
                    ITU_T_CHOICES_DECL(forever, null_type, RemainingDelay_type_forever); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };

                enum DisplayEnhancement_type_enum {

                    DisplayEnhancement_type_null = 0,
                    DisplayEnhancement_type_text,
                    DisplayEnhancement_type_number,
                    DisplayEnhancement_type_none,
                };

                struct DisplayEnhancement_type : public ITU_T_CHOICE(DisplayEnhancement_type_enum) {


                    ITU_T_CHOICE_CTORS(DisplayEnhancement_type);

                    ITU_T_CHOICES_DECL(text, ISO_9506_MMS_1::MMSString, DisplayEnhancement_type_text); // primitive
                    ITU_T_CHOICES_DECL(number, integer_type, DisplayEnhancement_type_number); // primitive
                    ITU_T_CHOICES_DECL(none, null_type, DisplayEnhancement_type_none); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const MMS_Object_Module_1::EE_Class& arg__eeClass,
                        const Event_Condition_instance& arg__eventCondition,
                        const MMS_Object_Module_1::Transitions& arg__ecTransitions);

                Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
                        shared_ptr< MMS_Object_Module_1::EE_Class> arg__eeClass,
                        shared_ptr< Event_Condition_instance> arg__eventCondition,
                        shared_ptr< MMS_Object_Module_1::Transitions> arg__ecTransitions,
                        shared_ptr< RemainingDelay_type> arg__remainingDelay,
                        shared_ptr< Event_Action_instance> arg__eventAction,
                        shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
                        shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                        shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__aaRule,
                        shared_ptr< DisplayEnhancement_type> arg__displayEnhancement = shared_ptr< DisplayEnhancement_type>());

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(eeClass, MMS_Object_Module_1::EE_Class); //   Ic(  [ 0  ...   1 ]   
                ITU_T_HOLDERH_DECL(eventCondition, Event_Condition_instance);
                ITU_T_HOLDERH_DECL(ecTransitions, MMS_Object_Module_1::Transitions); //    Sc (  [ 7 ]   
                ITU_T_OPTIONAL_DECL(remainingDelay, RemainingDelay_type);
                ITU_T_OPTIONAL_DECL(eventAction, Event_Action_instance);
                ITU_T_OPTIONAL_DECL(duration, MMS_Object_Module_1::EE_Duration); //   Ic(  [ 0  ...   1 ]   
                ITU_T_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
                ITU_T_OPTIONAL_DECL(aaRule, MMS_Object_Module_1::AlarmAckRule); //   Ic(  [ 0  ...   3 ]   
                ITU_T_OPTIONAL_DECL(displayEnhancement, DisplayEnhancement_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Event_Enrollment_instance();

        Event_Enrollment_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Event-Condition-List-instance

    struct Event_Condition_List_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Event_Condition_instance > EventConditions_type;
                typedef sequence_of< Event_Condition_List_instance > EventConditionLists_type;
                typedef sequence_of< Event_Condition_List_instance > ReferencingEventConditionLists_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const EventConditions_type& arg__eventConditions,
                        const EventConditionLists_type& arg__eventConditionLists,
                        const ReferencingEventConditionLists_type& arg__referencingEventConditionLists);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(eventConditions, EventConditions_type);
                ITU_T_HOLDERH_DECL(eventConditionLists, EventConditionLists_type);
                ITU_T_HOLDERH_DECL(referencingEventConditionLists, ReferencingEventConditionLists_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Event_Condition_List_instance();

        Event_Condition_List_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Journal-instance

    struct Journal_instance {

        struct Definition_type;

        enum Definition_type_enum {

            Definition_type_null = 0,
            Definition_type_reference,
            Definition_type_details,
        };

        struct Definition_type : public ITU_T_CHOICE(Definition_type_enum) {


            struct Details_type;

            struct Details_type {

                typedef sequence_of< Journal_Entry_instance > Entries_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const Entries_type& arg__entries);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(entries, Entries_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(Definition_type);

            ITU_T_CHOICES_DECL(reference, oid_type, Definition_type_reference); // primitive
            ITU_T_CHOICEC_DECL(details, Details_type, Definition_type_details);

            ITU_T_ARCHIVE_FUNC;
        };


        Journal_instance();

        Journal_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
                const Definition_type& arg__definition);

        ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(definition, Definition_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Journal-Entry-instance

    struct Journal_Entry_instance {

        struct EventTransitionRecord_type;
        struct JournalVariables_type_sequence_of;

        struct EventTransitionRecord_type {

            EventTransitionRecord_type();

            EventTransitionRecord_type(const ISO_9506_MMS_1::ObjectName& arg__name,
                    const MMS_Object_Module_1::EC_State& arg__currentState);

            ITU_T_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
            ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State); //   Ic(  [ 0  ...   2 ]   

            ITU_T_ARCHIVE_FUNC;
        };

        struct JournalVariables_type_sequence_of {

            JournalVariables_type_sequence_of();

            JournalVariables_type_sequence_of(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
                    const ISO_9506_MMS_1::Data& arg__valueSpecification);

            ITU_T_HOLDERH_DECL(variableTag, ISO_9506_MMS_1::MMS255String);
            ITU_T_HOLDERH_DECL(valueSpecification, ISO_9506_MMS_1::Data);

            ITU_T_ARCHIVE_FUNC;
        };



        typedef sequence_of< JournalVariables_type_sequence_of > JournalVariables_type;

        static const enumerated informationType_annotation;
        static const enumerated informationType_event_data;
        static const enumerated informationType_data;


        Journal_Entry_instance();

        Journal_Entry_instance(const Journal_instance& arg__journal,
                const octet_string& arg__entry,
                const MMS_Environment_1::ApplicationReference& arg__clientApplication,
                const ISO_9506_MMS_1::TimeOfDay& arg__timeStamp,
                const integer_type& arg__orderOfReceipt,
                const enumerated& arg__informationType);

        Journal_Entry_instance(shared_ptr< Journal_instance> arg__journal,
                shared_ptr< octet_string> arg__entry,
                shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                shared_ptr< ISO_9506_MMS_1::TimeOfDay> arg__timeStamp,
                shared_ptr< integer_type> arg__orderOfReceipt,
                shared_ptr< enumerated> arg__informationType,
                shared_ptr< ISO_9506_MMS_1::MMS255String> arg__textComment,
                shared_ptr< EventTransitionRecord_type> arg__eventTransitionRecord,
                shared_ptr< JournalVariables_type> arg__journalVariables);

        ITU_T_HOLDERH_DECL(journal, Journal_instance);
        ITU_T_HOLDERH_DECL(entry, octet_string);
        ITU_T_HOLDERH_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(timeStamp, ISO_9506_MMS_1::TimeOfDay); //    Sc (  [ 4  ...   6 ]   
        ITU_T_HOLDERH_DECL(orderOfReceipt, integer_type);
        ITU_T_HOLDERH_DECL(informationType, enumerated);
        ITU_T_OPTIONAL_DECL(textComment, ISO_9506_MMS_1::MMS255String);
        ITU_T_OPTIONAL_DECL(eventTransitionRecord, EventTransitionRecord_type);
        ITU_T_OPTIONAL_DECL(journalVariables, JournalVariables_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Service-and-Parameter-CBBs

    struct Service_and_Parameter_CBBs {

        Service_and_Parameter_CBBs();

        Service_and_Parameter_CBBs(const MMS_Object_Module_1::ServiceSupportOptions& arg__services_Client,
                const MMS_Object_Module_1::ServiceSupportOptions& arg__services_Server,
                const MMS_Object_Module_1::ParameterSupportOptions& arg__parameters,
                const integer_type& arg__nest,
                const MMS_Object_Module_1::AdditionalSupportOptions& arg__extendedServices_Client,
                const MMS_Object_Module_1::AdditionalSupportOptions& arg__extendedServices_Server,
                const MMS_Object_Module_1::AdditionalCBBOptions& arg__extendedParameters,
                const GeneralManagementParameters& arg__generalManagement,
                const VMDSupportParameters& arg__vMDSupport,
                const DomainManagementParameters& arg__domainManagement,
                const ProgramInvocationManagementParameters& arg__programInvocation,
                const VariableAccessParameters& arg__variableAccess,
                const DataParameters& arg__dataParameters,
                const SemaphoreManagementParameters& arg__semaphoreManagement,
                const OperatorCommunicationParameters& arg__operatorCommunication,
                const ErrorParameters& arg__errors,
                const FileManagementParameters& arg__fileManagement);

        ITU_T_HOLDERH_DECL(services_Client, MMS_Object_Module_1::ServiceSupportOptions); //    Sc (  [ 93 ]   
        ITU_T_HOLDERH_DECL(services_Server, MMS_Object_Module_1::ServiceSupportOptions); //    Sc (  [ 93 ]   
        ITU_T_HOLDERH_DECL(parameters, MMS_Object_Module_1::ParameterSupportOptions); //    Sc (  [ 18 ]   
        ITU_T_HOLDERH_DECL(nest, integer_type);
        ITU_T_HOLDERH_DECL(extendedServices_Client, MMS_Object_Module_1::AdditionalSupportOptions); //    Sc (  [ 23 ]   
        ITU_T_HOLDERH_DECL(extendedServices_Server, MMS_Object_Module_1::AdditionalSupportOptions); //    Sc (  [ 23 ]   
        ITU_T_HOLDERH_DECL(extendedParameters, MMS_Object_Module_1::AdditionalCBBOptions); //    Sc (  [ 3 ]   
        ITU_T_HOLDERH_DECL(generalManagement, GeneralManagementParameters);
        ITU_T_HOLDERH_DECL(vMDSupport, VMDSupportParameters);
        ITU_T_HOLDERH_DECL(domainManagement, DomainManagementParameters);
        ITU_T_HOLDERH_DECL(programInvocation, ProgramInvocationManagementParameters);
        ITU_T_HOLDERH_DECL(variableAccess, VariableAccessParameters);
        ITU_T_HOLDERH_DECL(dataParameters, DataParameters);
        ITU_T_HOLDERH_DECL(semaphoreManagement, SemaphoreManagementParameters);
        ITU_T_HOLDERH_DECL(operatorCommunication, OperatorCommunicationParameters);
        ITU_T_HOLDERH_DECL(errors, ErrorParameters);
        ITU_T_HOLDERH_DECL(fileManagement, FileManagementParameters);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GeneralManagementParameters

    struct GeneralManagementParameters {

        struct SupportForTime_type;

        struct SupportForTime_type {

            SupportForTime_type();

            SupportForTime_type(const bool& arg__timeOfDay,
                    const bool& arg__timeSequence);

            ITU_T_HOLDERH_DECL(timeOfDay, bool);
            ITU_T_HOLDERH_DECL(timeSequence, bool);

            ITU_T_ARCHIVE_FUNC;
        };


        GeneralManagementParameters();

        GeneralManagementParameters(const ISO_9506_MMS_1::MMSString& arg__localDetail,
                const SupportForTime_type& arg__supportForTime,
                const integer_type& arg__granularityOfTime);

        ITU_T_HOLDERH_DECL(localDetail, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(supportForTime, SupportForTime_type);
        ITU_T_HOLDERH_DECL(granularityOfTime, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence VMDSupportParameters

    struct VMDSupportParameters {

        VMDSupportParameters();

        VMDSupportParameters(const ISO_9506_MMS_1::MMSString& arg__localDetail,
                const ISO_9506_MMS_1::MMSString& arg__extendedDerivation);

        ITU_T_HOLDERH_DECL(localDetail, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(extendedDerivation, ISO_9506_MMS_1::MMSString);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DomainManagementParameters

    struct DomainManagementParameters {

        typedef sequence_of< oid_type > LoadDataSyntax_type;


        DomainManagementParameters();

        DomainManagementParameters(const ISO_9506_MMS_1::MMSString& arg__loadDataOctet,
                const LoadDataSyntax_type& arg__loadDataSyntax,
                const integer_type& arg__maxUploads);

        ITU_T_HOLDERH_DECL(loadDataOctet, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(loadDataSyntax, LoadDataSyntax_type);
        ITU_T_HOLDERH_DECL(maxUploads, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ProgramInvocationManagementParameters

    struct ProgramInvocationManagementParameters {

        typedef sequence_of< oid_type > ExecutionArgSyntaxes_type;


        ProgramInvocationManagementParameters();

        ProgramInvocationManagementParameters(const integer_type& arg__executionArgMaxSize,
                const ISO_9506_MMS_1::MMSString& arg__executionArgParseRules,
                const ExecutionArgSyntaxes_type& arg__executionArgSyntaxes,
                const ISO_9506_MMS_1::MMSString& arg__programLoction,
                const bool& arg__stepMode);

        ITU_T_HOLDERH_DECL(executionArgMaxSize, integer_type);
        ITU_T_HOLDERH_DECL(executionArgParseRules, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(executionArgSyntaxes, ExecutionArgSyntaxes_type);
        ITU_T_HOLDERH_DECL(programLoction, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(stepMode, bool);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence VariableAccessParameters

    struct VariableAccessParameters {

        VariableAccessParameters();

        VariableAccessParameters(const ISO_9506_MMS_1::MMSString& arg__uninterruptibleAccess,
                const bool& arg__singleMode,
                const bool& arg__unnamedMode);

        ITU_T_HOLDERH_DECL(uninterruptibleAccess, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(singleMode, bool);
        ITU_T_HOLDERH_DECL(unnamedMode, bool);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DataParameters

    struct DataParameters {

        struct Floating_point_type;

        struct Floating_point_type {

            Floating_point_type();

            Floating_point_type(const integer_type& arg__total,
                    const integer_type& arg__exponent);

            ITU_T_HOLDERH_DECL(total, integer_type);
            ITU_T_HOLDERH_DECL(exponent, integer_type);

            ITU_T_ARCHIVE_FUNC;
        };


        DataParameters();

        DataParameters(shared_ptr< integer_type> arg__bit_stringV,
                shared_ptr< integer_type> arg__integer,
                shared_ptr< integer_type> arg__unsignedV,
                shared_ptr< Floating_point_type> arg__floating_point,
                shared_ptr< integer_type> arg__octet_stringV,
                shared_ptr< integer_type> arg__visible_stringV,
                shared_ptr< bool> arg__binary_time,
                shared_ptr< integer_type> arg__bcd,
                shared_ptr< integer_type> arg__mmsString);

        ITU_T_OPTIONAL_DECL(bit_stringV, integer_type);
        ITU_T_OPTIONAL_DECL(integer, integer_type);
        ITU_T_OPTIONAL_DECL(unsignedV, integer_type);
        ITU_T_OPTIONAL_DECL(floating_point, Floating_point_type);
        ITU_T_OPTIONAL_DECL(octet_stringV, integer_type);
        ITU_T_OPTIONAL_DECL(visible_stringV, integer_type);
        ITU_T_OPTIONAL_DECL(binary_time, bool);
        ITU_T_OPTIONAL_DECL(bcd, integer_type);
        ITU_T_OPTIONAL_DECL(mmsString, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence SemaphoreManagementParameters

    struct SemaphoreManagementParameters {

        SemaphoreManagementParameters();

        SemaphoreManagementParameters(const ISO_9506_MMS_1::MMSString& arg__algorithm);

        ITU_T_HOLDERH_DECL(algorithm, ISO_9506_MMS_1::MMSString);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence OperatorCommunicationParameters

    struct OperatorCommunicationParameters {

        OperatorCommunicationParameters();

        OperatorCommunicationParameters(const integer_type& arg__input_time_out);

        ITU_T_HOLDERH_DECL(input_time_out, integer_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ErrorParameters

    struct ErrorParameters {

        struct AdditionalDetial_type;

        struct AdditionalDetial_type {

            AdditionalDetial_type();

            AdditionalDetial_type(const integer_type& arg__size,
                    const ISO_9506_MMS_1::MMSString& arg__syntax);

            ITU_T_HOLDERH_DECL(size, integer_type);
            ITU_T_HOLDERH_DECL(syntax, ISO_9506_MMS_1::MMSString);

            ITU_T_ARCHIVE_FUNC;
        };


        ErrorParameters();

        ErrorParameters(const ISO_9506_MMS_1::MMSString& arg__additionalCode,
                const AdditionalDetial_type& arg__additionalDetial);

        ITU_T_HOLDERH_DECL(additionalCode, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(additionalDetial, AdditionalDetial_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence FileManagementParameters

    struct FileManagementParameters {

        FileManagementParameters();

        FileManagementParameters(const ISO_9506_MMS_1::MMSString& arg__fileName);

        ITU_T_HOLDERH_DECL(fileName, ISO_9506_MMS_1::MMSString);

        ITU_T_ARCHIVE_FUNC;
    };

    ITU_T_ARCHIVE_X690_DECL(SCI_Information);
    ITU_T_ARCHIVE_X690_DECL(VMD_File);
    ITU_T_ARCHIVE_X690_DECL(VMD_File::Selected_Program_Invocation_type);
    ITU_T_ARCHIVE_X690_DECL(Access_Control_List_instance);
    ITU_T_ARCHIVE_X690_DECL(Access_Control_List_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Access_Control_List_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Domain_instance);
    ITU_T_ARCHIVE_X690_DECL(Domain_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Domain_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Program_Invocation_instance);
    ITU_T_ARCHIVE_X690_DECL(Program_Invocation_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Program_Invocation_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Unit_Control_instance);
    ITU_T_ARCHIVE_X690_DECL(Unit_Control_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Unit_Control_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Unnamed_Variable_instance);
    ITU_T_ARCHIVE_X690_DECL(Named_Variable_instance);
    ITU_T_ARCHIVE_X690_DECL(Named_Variable_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Named_Variable_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Named_Variable_List_instance);
    ITU_T_ARCHIVE_X690_DECL(Named_Variable_List_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Named_Variable_List_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Variable_List_Item_instance);
    ITU_T_ARCHIVE_X690_DECL(Named_Type_instance);
    ITU_T_ARCHIVE_X690_DECL(Named_Type_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Named_Type_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Data_Exchange_instance);
    ITU_T_ARCHIVE_X690_DECL(Data_Exchange_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Data_Exchange_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Semaphore_instance);
    ITU_T_ARCHIVE_X690_DECL(Semaphore_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Semaphore_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Operator_Station_instance);
    ITU_T_ARCHIVE_X690_DECL(Operator_Station_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Operator_Station_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_instance);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Action_instance);
    ITU_T_ARCHIVE_X690_DECL(Event_Action_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Action_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Enrollment_instance);
    ITU_T_ARCHIVE_X690_DECL(Event_Enrollment_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Enrollment_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_List_instance);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_List_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Event_Condition_List_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Journal_instance);
    ITU_T_ARCHIVE_X690_DECL(Journal_instance::Definition_type);
    ITU_T_ARCHIVE_X690_DECL(Journal_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X690_DECL(Journal_Entry_instance);
    ITU_T_ARCHIVE_X690_DECL(Journal_Entry_instance::EventTransitionRecord_type);
    ITU_T_ARCHIVE_X690_DECL(Journal_Entry_instance::JournalVariables_type_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(Service_and_Parameter_CBBs);
    ITU_T_ARCHIVE_X690_DECL(GeneralManagementParameters);
    ITU_T_ARCHIVE_X690_DECL(GeneralManagementParameters::SupportForTime_type);
    ITU_T_ARCHIVE_X690_DECL(VMDSupportParameters);
    ITU_T_ARCHIVE_X690_DECL(DomainManagementParameters);
    ITU_T_ARCHIVE_X690_DECL(ProgramInvocationManagementParameters);
    ITU_T_ARCHIVE_X690_DECL(VariableAccessParameters);
    ITU_T_ARCHIVE_X690_DECL(DataParameters);
    ITU_T_ARCHIVE_X690_DECL(DataParameters::Floating_point_type);
    ITU_T_ARCHIVE_X690_DECL(SemaphoreManagementParameters);
    ITU_T_ARCHIVE_X690_DECL(OperatorCommunicationParameters);
    ITU_T_ARCHIVE_X690_DECL(ErrorParameters);
    ITU_T_ARCHIVE_X690_DECL(ErrorParameters::AdditionalDetial_type);
    ITU_T_ARCHIVE_X690_DECL(FileManagementParameters);

    ITU_T_ARCHIVE_X691_DECL(SCI_Information);
    ITU_T_ARCHIVE_X691_DECL(VMD_File);
    ITU_T_ARCHIVE_X691_DECL(VMD_File::Selected_Program_Invocation_type);
    ITU_T_ARCHIVE_X691_DECL(Access_Control_List_instance);
    ITU_T_ARCHIVE_X691_DECL(Access_Control_List_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Access_Control_List_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Domain_instance);
    ITU_T_ARCHIVE_X691_DECL(Domain_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Domain_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Program_Invocation_instance);
    ITU_T_ARCHIVE_X691_DECL(Program_Invocation_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Program_Invocation_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Unit_Control_instance);
    ITU_T_ARCHIVE_X691_DECL(Unit_Control_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Unit_Control_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Unnamed_Variable_instance);
    ITU_T_ARCHIVE_X691_DECL(Named_Variable_instance);
    ITU_T_ARCHIVE_X691_DECL(Named_Variable_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Named_Variable_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Named_Variable_List_instance);
    ITU_T_ARCHIVE_X691_DECL(Named_Variable_List_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Named_Variable_List_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Variable_List_Item_instance);
    ITU_T_ARCHIVE_X691_DECL(Named_Type_instance);
    ITU_T_ARCHIVE_X691_DECL(Named_Type_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Named_Type_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Data_Exchange_instance);
    ITU_T_ARCHIVE_X691_DECL(Data_Exchange_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Data_Exchange_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Semaphore_instance);
    ITU_T_ARCHIVE_X691_DECL(Semaphore_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Semaphore_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Operator_Station_instance);
    ITU_T_ARCHIVE_X691_DECL(Operator_Station_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Operator_Station_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_instance);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Action_instance);
    ITU_T_ARCHIVE_X691_DECL(Event_Action_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Action_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Enrollment_instance);
    ITU_T_ARCHIVE_X691_DECL(Event_Enrollment_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Enrollment_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_List_instance);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_List_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Event_Condition_List_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Journal_instance);
    ITU_T_ARCHIVE_X691_DECL(Journal_instance::Definition_type);
    ITU_T_ARCHIVE_X691_DECL(Journal_instance::Definition_type::Details_type);
    ITU_T_ARCHIVE_X691_DECL(Journal_Entry_instance);
    ITU_T_ARCHIVE_X691_DECL(Journal_Entry_instance::EventTransitionRecord_type);
    ITU_T_ARCHIVE_X691_DECL(Journal_Entry_instance::JournalVariables_type_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(Service_and_Parameter_CBBs);
    ITU_T_ARCHIVE_X691_DECL(GeneralManagementParameters);
    ITU_T_ARCHIVE_X691_DECL(GeneralManagementParameters::SupportForTime_type);
    ITU_T_ARCHIVE_X691_DECL(VMDSupportParameters);
    ITU_T_ARCHIVE_X691_DECL(DomainManagementParameters);
    ITU_T_ARCHIVE_X691_DECL(ProgramInvocationManagementParameters);
    ITU_T_ARCHIVE_X691_DECL(VariableAccessParameters);
    ITU_T_ARCHIVE_X691_DECL(DataParameters);
    ITU_T_ARCHIVE_X691_DECL(DataParameters::Floating_point_type);
    ITU_T_ARCHIVE_X691_DECL(SemaphoreManagementParameters);
    ITU_T_ARCHIVE_X691_DECL(OperatorCommunicationParameters);
    ITU_T_ARCHIVE_X691_DECL(ErrorParameters);
    ITU_T_ARCHIVE_X691_DECL(ErrorParameters::AdditionalDetial_type);
    ITU_T_ARCHIVE_X691_DECL(FileManagementParameters);

}

ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::VMD_File::Selected_Program_Invocation_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Access_Control_List_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Domain_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Program_Invocation_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Unit_Control_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Variable_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Variable_List_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Type_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Data_Exchange_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Semaphore_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Operator_Station_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Action_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_List_instance::Definition_type)
ITU_T_CHOICE_REGESTRATE(MMS_SCI_Module_1::Journal_instance::Definition_type)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___MMS_SCI_MODULE_1 */
