#ifndef ___MMS_SCI_MODULE_1
#define ___MMS_SCI_MODULE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {

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

            Selected_Program_Invocation_type() : ITU_T_CHOICE(Selected_Program_Invocation_type_enum) () {
            }

            template<typename T > Selected_Program_Invocation_type(boost::shared_ptr< T> vl, Selected_Program_Invocation_type_enum enm) :
                    ITU_T_CHOICE(Selected_Program_Invocation_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Selected_Program_Invocation_type(const T& vl, Selected_Program_Invocation_type_enum enm) :
                    ITU_T_CHOICE(Selected_Program_Invocation_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

            ITU_T_CHOICEC_DECL(selectedProgram, Program_Invocation_instance, Selected_Program_Invocation_type_selectedProgram);
            ITU_T_CHOICES_DECL(noneSelected, null_type, Selected_Program_Invocation_type_noneSelected); // primitive

            ITU_T_ARCHIVE_FUNC;
        };



        typedef std::vector< Access_Control_List_instance > AccessControlLists_type;
        typedef std::vector< Domain_instance > Domains_type;
        typedef std::vector< Program_Invocation_instance > ProgramInvocations_type;
        typedef std::vector< Unit_Control_instance > UnitControls_type;
        typedef std::vector< Unnamed_Variable_instance > UnnamedVariables_type;
        typedef std::vector< Named_Variable_instance > NamedVariables_type;
        typedef std::vector< Named_Variable_List_instance > NamedVariableLists_type;
        typedef std::vector< Named_Type_instance > NamedTypes_type;
        typedef std::vector< Data_Exchange_instance > DataExchanges_type;
        typedef std::vector< Semaphore_instance > Semaphores_type;
        typedef std::vector< Operator_Station_instance > OperatorStations_type;
        typedef std::vector< Event_Condition_instance > EventConditions_type;
        typedef std::vector< Event_Action_instance > EventActions_type;
        typedef std::vector< Event_Enrollment_instance > EventEnrollments_type;
        typedef std::vector< Event_Condition_List_instance > EventConditionLists_type;
        typedef std::vector< Journal_instance > Journals_type;

        typedef std::vector< ISO_9506_MMS_1::MMSString > Capabilities_type;

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
                const bitstring_type& arg__local_detail,
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

        VMD_File(boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__executiveFunction,
                boost::shared_ptr< ISO_9506_MMS_1::MMSString> arg__vendorName,
                boost::shared_ptr< ISO_9506_MMS_1::MMSString> arg__modelName,
                boost::shared_ptr< ISO_9506_MMS_1::MMSString> arg__revision,
                boost::shared_ptr< oid_type> arg__abstractSyntaxes,
                boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                boost::shared_ptr< MMS_Object_Module_1::LogicalStatus> arg__logicalStatus,
                boost::shared_ptr< Capabilities_type> arg__capabilities,
                boost::shared_ptr< MMS_Object_Module_1::PhysicalStatus> arg__physicalStatus,
                boost::shared_ptr< bitstring_type> arg__local_detail,
                boost::shared_ptr< AccessControlLists_type> arg__accessControlLists,
                boost::shared_ptr< Domains_type> arg__domains,
                boost::shared_ptr< ProgramInvocations_type> arg__programInvocations,
                boost::shared_ptr< UnitControls_type> arg__unitControls,
                boost::shared_ptr< UnnamedVariables_type> arg__unnamedVariables,
                boost::shared_ptr< NamedVariables_type> arg__namedVariables,
                boost::shared_ptr< NamedVariableLists_type> arg__namedVariableLists,
                boost::shared_ptr< NamedTypes_type> arg__namedTypes,
                boost::shared_ptr< DataExchanges_type> arg__dataExchanges,
                boost::shared_ptr< Semaphores_type> arg__semaphores,
                boost::shared_ptr< OperatorStations_type> arg__operatorStations,
                boost::shared_ptr< EventConditions_type> arg__eventConditions,
                boost::shared_ptr< EventActions_type> arg__eventActions,
                boost::shared_ptr< EventEnrollments_type> arg__eventEnrollments,
                boost::shared_ptr< EventConditionLists_type> arg__eventConditionLists,
                boost::shared_ptr< Journals_type> arg__journals,
                boost::shared_ptr< Selected_Program_Invocation_type> arg__selected_Program_Invocation = boost::shared_ptr< Selected_Program_Invocation_type>());

        ITU_T_HOLDERH_DECL(executiveFunction, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(vendorName, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(modelName, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(revision, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(abstractSyntaxes, oid_type);
        ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
        ITU_T_HOLDERH_DECL(logicalStatus, MMS_Object_Module_1::LogicalStatus);
        ITU_T_HOLDERH_DECL(capabilities, Capabilities_type);
        ITU_T_HOLDERH_DECL(physicalStatus, MMS_Object_Module_1::PhysicalStatus);
        ITU_T_HOLDERH_DECL(local_detail, bitstring_type);
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

                typedef std::vector< Access_Control_List_instance > AccessControlLists_type;
                typedef std::vector< Domain_instance > Domains_type;
                typedef std::vector< Program_Invocation_instance > ProgramInvocations_type;
                typedef std::vector< Unit_Control_instance > UnitControls_type;
                typedef std::vector< Unnamed_Variable_instance > UnnamedVariables_type;
                typedef std::vector< Named_Variable_instance > NamedVariables_type;
                typedef std::vector< Named_Variable_List_instance > NamedVariableLists_type;
                typedef std::vector< Named_Type_instance > NamedTypes_type;
                typedef std::vector< Data_Exchange_instance > DataExchanges_type;
                typedef std::vector< Semaphore_instance > Semaphores_type;
                typedef std::vector< Operator_Station_instance > OperatorStations_type;
                typedef std::vector< Event_Condition_instance > EventConditions_type;
                typedef std::vector< Event_Action_instance > EventActions_type;
                typedef std::vector< Event_Enrollment_instance > EventEnrollments_type;
                typedef std::vector< Journal_instance > Journals_type;
                typedef std::vector< Event_Condition_List_instance > EventConditionLists_type;


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

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__readAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__storeAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__writeAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__loadAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__executeAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__deleteAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> arg__editAccessCondition,
                        boost::shared_ptr< AccessControlLists_type> arg__accessControlLists,
                        boost::shared_ptr< Domains_type> arg__domains,
                        boost::shared_ptr< ProgramInvocations_type> arg__programInvocations,
                        boost::shared_ptr< UnitControls_type> arg__unitControls,
                        boost::shared_ptr< UnnamedVariables_type> arg__unnamedVariables,
                        boost::shared_ptr< NamedVariables_type> arg__namedVariables,
                        boost::shared_ptr< NamedVariableLists_type> arg__namedVariableLists,
                        boost::shared_ptr< NamedTypes_type> arg__namedTypes,
                        boost::shared_ptr< DataExchanges_type> arg__dataExchanges,
                        boost::shared_ptr< Semaphores_type> arg__semaphores,
                        boost::shared_ptr< OperatorStations_type> arg__operatorStations,
                        boost::shared_ptr< EventConditions_type> arg__eventConditions,
                        boost::shared_ptr< EventActions_type> arg__eventActions,
                        boost::shared_ptr< EventEnrollments_type> arg__eventEnrollments,
                        boost::shared_ptr< Journals_type> arg__journals,
                        boost::shared_ptr< EventConditionLists_type> arg__eventConditionLists = boost::shared_ptr< EventConditionLists_type>());

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

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Program_Invocation_instance > ProgramInvocations_type;
                typedef std::vector< Named_Variable_instance > NamedVariables_type;
                typedef std::vector< Named_Variable_List_instance > NamedVariableLists_type;
                typedef std::vector< Named_Type_instance > NamedTypes_type;
                typedef std::vector< Event_Condition_instance > EventConditions_type;
                typedef std::vector< Event_Action_instance > EventActions_type;
                typedef std::vector< Event_Enrollment_instance > EventEnrollments_type;
                typedef std::vector< Event_Condition_List_instance > EventConditionLists_type;

                typedef std::vector< ISO_9506_MMS_1::MMSString > Capabilities_type;

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
                ITU_T_HOLDERH_DECL(state, MMS_Object_Module_1::DomainState);
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

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Domain_instance > Domains_type;
                typedef std::vector< Access_Control_List_instance > AccessControl_type;
                typedef std::vector< Event_Condition_instance > EventCondition_type;
                typedef std::vector< Event_Action_instance > EventAction_type;
                typedef std::vector< Event_Enrollment_instance > EventEnrollment_type;
                typedef std::vector< Program_Invocation_instance > Controlled_Program_Invocations_type;


                Details_type();

                Details_type(const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState,
                        const Domains_type& arg__domains,
                        const AccessControl_type& arg__accessControl,
                        const bool& arg__reusable,
                        const bool& arg__monitor,
                        const ISO_9506_MMS_1::MMSString& arg__executionArgument);

                Details_type(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__programInvocationState,
                        boost::shared_ptr< Domains_type> arg__domains,
                        boost::shared_ptr< AccessControl_type> arg__accessControl,
                        boost::shared_ptr< bool> arg__reusable,
                        boost::shared_ptr< bool> arg__monitor,
                        boost::shared_ptr< EventCondition_type> arg__eventCondition,
                        boost::shared_ptr< EventAction_type> arg__eventAction,
                        boost::shared_ptr< EventEnrollment_type> arg__eventEnrollment,
                        boost::shared_ptr< ISO_9506_MMS_1::MMSString> arg__executionArgument,
                        boost::shared_ptr< MMS_Object_Module_1::Control_State> arg__control = boost::shared_ptr< MMS_Object_Module_1::Control_State>(),
                        boost::shared_ptr< Program_Invocation_instance> arg__controlling_Program_Invocation = boost::shared_ptr< Program_Invocation_instance>(),
                        boost::shared_ptr< Controlled_Program_Invocations_type> arg__controlled_Program_Invocations = boost::shared_ptr< Controlled_Program_Invocations_type>());

                ITU_T_HOLDERH_DECL(programInvocationState, MMS_Object_Module_1::ProgramInvocationState);
                ITU_T_HOLDERH_DECL(domains, Domains_type);
                ITU_T_HOLDERH_DECL(accessControl, AccessControl_type);
                ITU_T_HOLDERH_DECL(reusable, bool);
                ITU_T_HOLDERH_DECL(monitor, bool);
                ITU_T_OPTIONAL_DECL(eventCondition, EventCondition_type);
                ITU_T_OPTIONAL_DECL(eventAction, EventAction_type);
                ITU_T_OPTIONAL_DECL(eventEnrollment, EventEnrollment_type);
                ITU_T_HOLDERH_DECL(executionArgument, ISO_9506_MMS_1::MMSString);
                ITU_T_OPTIONAL_DECL(control, MMS_Object_Module_1::Control_State);
                ITU_T_OPTIONAL_DECL(controlling_Program_Invocation, Program_Invocation_instance);
                ITU_T_OPTIONAL_DECL(controlled_Program_Invocations, Controlled_Program_Invocations_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Domain_instance > Domains_type;
                typedef std::vector< Program_Invocation_instance > ProgramInvocations_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const Domains_type& arg__domains,
                        const ProgramInvocations_type& arg__programInvocations);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(domains, Domains_type);
                ITU_T_HOLDERH_DECL(programInvocations, ProgramInvocations_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
                        boost::shared_ptr< MMS_Object_Module_1::Address> arg__address,
                        boost::shared_ptr< visiblestring_type> arg__meaning);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
                ITU_T_OPTIONAL_DECL(address, MMS_Object_Module_1::Address);
                ITU_T_OPTIONAL_DECL(meaning, visiblestring_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Variable_List_Item_instance > ListOfVariables_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const ListOfVariables_type& arg__listOfVariables);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(listOfVariables, ListOfVariables_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

        Variable_List_Item_instance(boost::shared_ptr< Unnamed_Variable_instance> arg__unnamedItem,
                boost::shared_ptr< Named_Variable_instance> arg__namedItem,
                boost::shared_ptr< ISO_9506_MMS_1::AlternateAccess> arg__alternateAccess);

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

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
                        boost::shared_ptr< visiblestring_type> arg__meaning);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
                ITU_T_OPTIONAL_DECL(meaning, visiblestring_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< MMS_Object_Module_1::TypeDescription > Request_type;
                typedef std::vector< MMS_Object_Module_1::TypeDescription > Response_type;

                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const Request_type& arg__request,
                        const Response_type& arg__response,
                        const bool& arg__linked);

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< Request_type> arg__request,
                        boost::shared_ptr< Response_type> arg__response,
                        boost::shared_ptr< bool> arg__linked,
                        boost::shared_ptr< Program_Invocation_instance> arg__programInvocation);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(request, Request_type);
                ITU_T_HOLDERH_DECL(response, Response_type);
                ITU_T_HOLDERH_DECL(linked, bool);
                ITU_T_OPTIONAL_DECL(programInvocation, Program_Invocation_instance);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< visiblestring_type > NamedTokens_type;

                static const enumerated_type classV_token;
                static const enumerated_type classV_pool;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const enumerated_type& arg__classV,
                        const Event_Condition_instance& arg__eventCondition);

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< enumerated_type> arg__classV,
                        boost::shared_ptr< int> arg__numberOfTokens,
                        boost::shared_ptr< NamedTokens_type> arg__namedTokens,
                        boost::shared_ptr< Event_Condition_instance> arg__eventCondition);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(classV, enumerated_type);
                ITU_T_OPTIONAL_DECL(numberOfTokens, int);
                ITU_T_OPTIONAL_DECL(namedTokens, NamedTokens_type);
                ITU_T_HOLDERH_DECL(eventCondition, Event_Condition_instance);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                static const enumerated_type stationType_entry;
                static const enumerated_type stationType_display;
                static const enumerated_type stationType_entry_display;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const enumerated_type& arg__stationType);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(stationType, enumerated_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                    MonitoredVariable_type() : ITU_T_CHOICE(MonitoredVariable_type_enum) () {
                    }

                    template<typename T > MonitoredVariable_type(boost::shared_ptr< T> vl, MonitoredVariable_type_enum enm) :
                            ITU_T_CHOICE(MonitoredVariable_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    template<typename T > MonitoredVariable_type(const T& vl, MonitoredVariable_type_enum enm) :
                            ITU_T_CHOICE(MonitoredVariable_type_enum) (new T(vl), static_cast<int> (enm)) {
                    }

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

                    DisplayEnhancement_type() : ITU_T_CHOICE(DisplayEnhancement_type_enum) () {
                    }

                    template<typename T > DisplayEnhancement_type(boost::shared_ptr< T> vl, DisplayEnhancement_type_enum enm) :
                            ITU_T_CHOICE(DisplayEnhancement_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    template<typename T > DisplayEnhancement_type(const T& vl, DisplayEnhancement_type_enum enm) :
                            ITU_T_CHOICE(DisplayEnhancement_type_enum) (new T(vl), static_cast<int> (enm)) {
                    }

                    ITU_T_CHOICES_DECL(text, ISO_9506_MMS_1::MMSString, DisplayEnhancement_type_text); // primitive
                    ITU_T_CHOICES_DECL(number, int, DisplayEnhancement_type_number); // primitive
                    ITU_T_CHOICES_DECL(none, null_type, DisplayEnhancement_type_none); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };

                enum Group_Priority_Override_type_enum {

                    Group_Priority_Override_type_null = 0,
                    Group_Priority_Override_type_priority,
                    Group_Priority_Override_type_undefined,
                };

                struct Group_Priority_Override_type : public ITU_T_CHOICE(Group_Priority_Override_type_enum) {

                    Group_Priority_Override_type() : ITU_T_CHOICE(Group_Priority_Override_type_enum) () {
                    }

                    template<typename T > Group_Priority_Override_type(boost::shared_ptr< T> vl, Group_Priority_Override_type_enum enm) :
                            ITU_T_CHOICE(Group_Priority_Override_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    template<typename T > Group_Priority_Override_type(const T& vl, Group_Priority_Override_type_enum enm) :
                            ITU_T_CHOICE(Group_Priority_Override_type_enum) (new T(vl), static_cast<int> (enm)) {
                    }

                    ITU_T_CHOICES_DECL(priority, MMS_Object_Module_1::Priority, Group_Priority_Override_type_priority); // primitive
                    ITU_T_CHOICES_DECL(undefined, null_type, Group_Priority_Override_type_undefined); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };



                typedef std::vector< Event_Enrollment_instance > EventEnrollments_type;
                typedef std::vector< Event_Condition_List_instance > ReferencingEventConditionLists_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const MMS_Object_Module_1::EC_Class& arg__ecClass,
                        const MMS_Object_Module_1::EC_State& arg__ecState,
                        const MMS_Object_Module_1::Priority& arg__priority,
                        const MMS_Object_Module_1::Severity& arg__severity,
                        const EventEnrollments_type& arg__eventEnrollments);

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::EC_Class> arg__ecClass,
                        boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__ecState,
                        boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
                        boost::shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
                        boost::shared_ptr< EventEnrollments_type> arg__eventEnrollments,
                        boost::shared_ptr< bool> arg__enabled,
                        boost::shared_ptr< bool> arg__alarmSummaryReports,
                        boost::shared_ptr< MonitoredVariable_type> arg__monitoredVariable,
                        boost::shared_ptr< int> arg__evaluationInterval,
                        boost::shared_ptr< DisplayEnhancement_type> arg__displayEnhancement = boost::shared_ptr< DisplayEnhancement_type>(),
                        boost::shared_ptr< Group_Priority_Override_type> arg__group_Priority_Override = boost::shared_ptr< Group_Priority_Override_type>(),
                        boost::shared_ptr< ReferencingEventConditionLists_type> arg__referencingEventConditionLists = boost::shared_ptr< ReferencingEventConditionLists_type>());

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(ecClass, MMS_Object_Module_1::EC_Class);
                ITU_T_HOLDERH_DECL(ecState, MMS_Object_Module_1::EC_State);
                ITU_T_HOLDERH_DECL(priority, MMS_Object_Module_1::Priority);
                ITU_T_HOLDERH_DECL(severity, MMS_Object_Module_1::Severity);
                ITU_T_HOLDERH_DECL(eventEnrollments, EventEnrollments_type);
                ITU_T_OPTIONAL_DECL(enabled, bool);
                ITU_T_OPTIONAL_DECL(alarmSummaryReports, bool);
                ITU_T_OPTIONAL_DECL(monitoredVariable, MonitoredVariable_type);
                ITU_T_OPTIONAL_DECL(evaluationInterval, int);
                ITU_T_OPTIONAL_DECL(displayEnhancement, DisplayEnhancement_type);
                ITU_T_OPTIONAL_DECL(group_Priority_Override, Group_Priority_Override_type);
                ITU_T_OPTIONAL_DECL(referencingEventConditionLists, ReferencingEventConditionLists_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Event_Enrollment_instance > EventEnrollments_type;

                typedef std::vector< MMS_Object_Module_1::Modifier > Modifiers_type;

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

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                    RemainingDelay_type() : ITU_T_CHOICE(RemainingDelay_type_enum) () {
                    }

                    template<typename T > RemainingDelay_type(boost::shared_ptr< T> vl, RemainingDelay_type_enum enm) :
                            ITU_T_CHOICE(RemainingDelay_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    template<typename T > RemainingDelay_type(const T& vl, RemainingDelay_type_enum enm) :
                            ITU_T_CHOICE(RemainingDelay_type_enum) (new T(vl), static_cast<int> (enm)) {
                    }

                    ITU_T_CHOICES_DECL(time, int, RemainingDelay_type_time); // primitive
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

                    DisplayEnhancement_type() : ITU_T_CHOICE(DisplayEnhancement_type_enum) () {
                    }

                    template<typename T > DisplayEnhancement_type(boost::shared_ptr< T> vl, DisplayEnhancement_type_enum enm) :
                            ITU_T_CHOICE(DisplayEnhancement_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    template<typename T > DisplayEnhancement_type(const T& vl, DisplayEnhancement_type_enum enm) :
                            ITU_T_CHOICE(DisplayEnhancement_type_enum) (new T(vl), static_cast<int> (enm)) {
                    }

                    ITU_T_CHOICES_DECL(text, ISO_9506_MMS_1::MMSString, DisplayEnhancement_type_text); // primitive
                    ITU_T_CHOICES_DECL(number, int, DisplayEnhancement_type_number); // primitive
                    ITU_T_CHOICES_DECL(none, null_type, DisplayEnhancement_type_none); // primitive

                    ITU_T_ARCHIVE_FUNC;
                };


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const MMS_Object_Module_1::EE_Class& arg__eeClass,
                        const Event_Condition_instance& arg__eventCondition,
                        const MMS_Object_Module_1::Transitions& arg__ecTransitions);

                Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::EE_Class> arg__eeClass,
                        boost::shared_ptr< Event_Condition_instance> arg__eventCondition,
                        boost::shared_ptr< MMS_Object_Module_1::Transitions> arg__ecTransitions,
                        boost::shared_ptr< RemainingDelay_type> arg__remainingDelay,
                        boost::shared_ptr< Event_Action_instance> arg__eventAction,
                        boost::shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
                        boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                        boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__aaRule,
                        boost::shared_ptr< DisplayEnhancement_type> arg__displayEnhancement = boost::shared_ptr< DisplayEnhancement_type>());

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(eeClass, MMS_Object_Module_1::EE_Class);
                ITU_T_HOLDERH_DECL(eventCondition, Event_Condition_instance);
                ITU_T_HOLDERH_DECL(ecTransitions, MMS_Object_Module_1::Transitions);
                ITU_T_OPTIONAL_DECL(remainingDelay, RemainingDelay_type);
                ITU_T_OPTIONAL_DECL(eventAction, Event_Action_instance);
                ITU_T_OPTIONAL_DECL(duration, MMS_Object_Module_1::EE_Duration);
                ITU_T_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
                ITU_T_OPTIONAL_DECL(aaRule, MMS_Object_Module_1::AlarmAckRule);
                ITU_T_OPTIONAL_DECL(displayEnhancement, DisplayEnhancement_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Event_Condition_instance > EventConditions_type;
                typedef std::vector< Event_Condition_List_instance > EventConditionLists_type;
                typedef std::vector< Event_Condition_List_instance > ReferencingEventConditionLists_type;


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

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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

                typedef std::vector< Journal_Entry_instance > Entries_type;


                Details_type();

                Details_type(const Access_Control_List_instance& arg__accessControl,
                        const Entries_type& arg__entries);

                ITU_T_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                ITU_T_HOLDERH_DECL(entries, Entries_type);

                ITU_T_ARCHIVE_FUNC;
            };

            Definition_type() : ITU_T_CHOICE(Definition_type_enum) () {
            }

            template<typename T > Definition_type(boost::shared_ptr< T> vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            template<typename T > Definition_type(const T& vl, Definition_type_enum enm) :
                    ITU_T_CHOICE(Definition_type_enum) (new T(vl), static_cast<int> (enm)) {
            }

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
            ITU_T_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State);

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



        typedef std::vector< JournalVariables_type_sequence_of > JournalVariables_type;

        static const enumerated_type informationType_annotation;
        static const enumerated_type informationType_event_data;
        static const enumerated_type informationType_data;


        Journal_Entry_instance();

        Journal_Entry_instance(const Journal_instance& arg__journal,
                const octetstring_type& arg__entry,
                const MMS_Environment_1::ApplicationReference& arg__clientApplication,
                const ISO_9506_MMS_1::TimeOfDay& arg__timeStamp,
                const int& arg__orderOfReceipt,
                const enumerated_type& arg__informationType);

        Journal_Entry_instance(boost::shared_ptr< Journal_instance> arg__journal,
                boost::shared_ptr< octetstring_type> arg__entry,
                boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
                boost::shared_ptr< ISO_9506_MMS_1::TimeOfDay> arg__timeStamp,
                boost::shared_ptr< int> arg__orderOfReceipt,
                boost::shared_ptr< enumerated_type> arg__informationType,
                boost::shared_ptr< ISO_9506_MMS_1::MMS255String> arg__textComment,
                boost::shared_ptr< EventTransitionRecord_type> arg__eventTransitionRecord,
                boost::shared_ptr< JournalVariables_type> arg__journalVariables);

        ITU_T_HOLDERH_DECL(journal, Journal_instance);
        ITU_T_HOLDERH_DECL(entry, octetstring_type);
        ITU_T_HOLDERH_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(timeStamp, ISO_9506_MMS_1::TimeOfDay);
        ITU_T_HOLDERH_DECL(orderOfReceipt, int);
        ITU_T_HOLDERH_DECL(informationType, enumerated_type);
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
                const int& arg__nest,
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

        ITU_T_HOLDERH_DECL(services_Client, MMS_Object_Module_1::ServiceSupportOptions);
        ITU_T_HOLDERH_DECL(services_Server, MMS_Object_Module_1::ServiceSupportOptions);
        ITU_T_HOLDERH_DECL(parameters, MMS_Object_Module_1::ParameterSupportOptions);
        ITU_T_HOLDERH_DECL(nest, int);
        ITU_T_HOLDERH_DECL(extendedServices_Client, MMS_Object_Module_1::AdditionalSupportOptions);
        ITU_T_HOLDERH_DECL(extendedServices_Server, MMS_Object_Module_1::AdditionalSupportOptions);
        ITU_T_HOLDERH_DECL(extendedParameters, MMS_Object_Module_1::AdditionalCBBOptions);
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
                const int& arg__granularityOfTime);

        ITU_T_HOLDERH_DECL(localDetail, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(supportForTime, SupportForTime_type);
        ITU_T_HOLDERH_DECL(granularityOfTime, int);

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

        typedef std::vector< oid_type > LoadDataSyntax_type;


        DomainManagementParameters();

        DomainManagementParameters(const ISO_9506_MMS_1::MMSString& arg__loadDataOctet,
                const LoadDataSyntax_type& arg__loadDataSyntax,
                const int& arg__maxUploads);

        ITU_T_HOLDERH_DECL(loadDataOctet, ISO_9506_MMS_1::MMSString);
        ITU_T_HOLDERH_DECL(loadDataSyntax, LoadDataSyntax_type);
        ITU_T_HOLDERH_DECL(maxUploads, int);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ProgramInvocationManagementParameters

    struct ProgramInvocationManagementParameters {

        typedef std::vector< oid_type > ExecutionArgSyntaxes_type;


        ProgramInvocationManagementParameters();

        ProgramInvocationManagementParameters(const int& arg__executionArgMaxSize,
                const ISO_9506_MMS_1::MMSString& arg__executionArgParseRules,
                const ExecutionArgSyntaxes_type& arg__executionArgSyntaxes,
                const ISO_9506_MMS_1::MMSString& arg__programLoction,
                const bool& arg__stepMode);

        ITU_T_HOLDERH_DECL(executionArgMaxSize, int);
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

            Floating_point_type(const int& arg__total,
                    const int& arg__exponent);

            ITU_T_HOLDERH_DECL(total, int);
            ITU_T_HOLDERH_DECL(exponent, int);

            ITU_T_ARCHIVE_FUNC;
        };


        DataParameters();

        DataParameters(boost::shared_ptr< int> arg__bit_string,
                boost::shared_ptr< int> arg__integer,
                boost::shared_ptr< int> arg__unsignedV,
                boost::shared_ptr< Floating_point_type> arg__floating_point,
                boost::shared_ptr< int> arg__octet_string,
                boost::shared_ptr< int> arg__visible_string,
                boost::shared_ptr< bool> arg__binary_time,
                boost::shared_ptr< int> arg__bcd,
                boost::shared_ptr< int> arg__mmsString);

        ITU_T_OPTIONAL_DECL(bit_string, int);
        ITU_T_OPTIONAL_DECL(integer, int);
        ITU_T_OPTIONAL_DECL(unsignedV, int);
        ITU_T_OPTIONAL_DECL(floating_point, Floating_point_type);
        ITU_T_OPTIONAL_DECL(octet_string, int);
        ITU_T_OPTIONAL_DECL(visible_string, int);
        ITU_T_OPTIONAL_DECL(binary_time, bool);
        ITU_T_OPTIONAL_DECL(bcd, int);
        ITU_T_OPTIONAL_DECL(mmsString, int);

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

        OperatorCommunicationParameters(const int& arg__input_time_out);

        ITU_T_HOLDERH_DECL(input_time_out, int);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence ErrorParameters

    struct ErrorParameters {

        struct AdditionalDetial_type;

        struct AdditionalDetial_type {

            AdditionalDetial_type();

            AdditionalDetial_type(const int& arg__size,
                    const ISO_9506_MMS_1::MMSString& arg__syntax);

            ITU_T_HOLDERH_DECL(size, int);
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

    template<> void SCI_Information::serialize(boost::asn1::x690::output_coder& arch);
    template<> void SCI_Information::serialize(boost::asn1::x690::input_coder& arch);
    template<> void VMD_File::serialize(boost::asn1::x690::output_coder& arch);
    template<> void VMD_File::serialize(boost::asn1::x690::input_coder& arch);
    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Domain_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Domain_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unit_Control_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unit_Control_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Type_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Type_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Semaphore_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Semaphore_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Operator_Station_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Operator_Station_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Action_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Action_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::input_coder& arch);
    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void VMDSupportParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void VMDSupportParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void DomainManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void DomainManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void VariableAccessParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void VariableAccessParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void DataParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void DataParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ErrorParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ErrorParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void FileManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void FileManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
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
