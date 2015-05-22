#include "MMS-SCI-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {

    // sequence SCI-Information

    SCI_Information::SCI_Information() : partOne_(), partTwo_() {
    };

    SCI_Information::SCI_Information(const VMD_File& arg__partOne,
            const Service_and_Parameter_CBBs& arg__partTwo) :
    partOne_(arg__partOne),
    partTwo_(arg__partTwo) {
    };


    ITU_T_HOLDERH_DEFN(SCI_Information::partOne, partOne, VMD_File);
    ITU_T_HOLDERH_DEFN(SCI_Information::partTwo, partTwo, Service_and_Parameter_CBBs);

    // sequence VMD-File

    VMD_File::VMD_File() : executiveFunction_(), vendorName_(), modelName_(), revision_(), abstractSyntaxes_(), accessControl_(), logicalStatus_(), capabilities_(), physicalStatus_(), local_detail_(), accessControlLists_(), domains_(), programInvocations_(), unitControls_(), unnamedVariables_(), namedVariables_(), namedVariableLists_(), namedTypes_(), dataExchanges_(), semaphores_(), operatorStations_(), eventConditions_(), eventActions_(), eventEnrollments_(), eventConditionLists_(), journals_() {
    };

    VMD_File::VMD_File(const MMS_Environment_1::ApplicationReference& arg__executiveFunction,
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
            const Journals_type& arg__journals) :
    executiveFunction_(arg__executiveFunction),
    vendorName_(arg__vendorName),
    modelName_(arg__modelName),
    revision_(arg__revision),
    abstractSyntaxes_(arg__abstractSyntaxes),
    accessControl_(arg__accessControl),
    logicalStatus_(arg__logicalStatus),
    capabilities_(arg__capabilities),
    physicalStatus_(arg__physicalStatus),
    local_detail_(arg__local_detail),
    accessControlLists_(arg__accessControlLists),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations),
    unitControls_(arg__unitControls),
    unnamedVariables_(arg__unnamedVariables),
    namedVariables_(arg__namedVariables),
    namedVariableLists_(arg__namedVariableLists),
    namedTypes_(arg__namedTypes),
    dataExchanges_(arg__dataExchanges),
    semaphores_(arg__semaphores),
    operatorStations_(arg__operatorStations),
    eventConditions_(arg__eventConditions),
    eventActions_(arg__eventActions),
    eventEnrollments_(arg__eventEnrollments),
    eventConditionLists_(arg__eventConditionLists),
    journals_(arg__journals) {
    };

    VMD_File::VMD_File(shared_ptr< MMS_Environment_1::ApplicationReference> arg__executiveFunction,
            shared_ptr< ISO_9506_MMS_1::MMSString> arg__vendorName,
            shared_ptr< ISO_9506_MMS_1::MMSString> arg__modelName,
            shared_ptr< ISO_9506_MMS_1::MMSString> arg__revision,
            shared_ptr< oid_type> arg__abstractSyntaxes,
            shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< MMS_Object_Module_1::LogicalStatus> arg__logicalStatus,
            shared_ptr< Capabilities_type> arg__capabilities,
            shared_ptr< MMS_Object_Module_1::PhysicalStatus> arg__physicalStatus,
            shared_ptr< bitstring_type> arg__local_detail,
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
            shared_ptr< Selected_Program_Invocation_type> arg__selected_Program_Invocation) :
    executiveFunction_(arg__executiveFunction),
    vendorName_(arg__vendorName),
    modelName_(arg__modelName),
    revision_(arg__revision),
    abstractSyntaxes_(arg__abstractSyntaxes),
    accessControl_(arg__accessControl),
    logicalStatus_(arg__logicalStatus),
    capabilities_(arg__capabilities),
    physicalStatus_(arg__physicalStatus),
    local_detail_(arg__local_detail),
    accessControlLists_(arg__accessControlLists),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations),
    unitControls_(arg__unitControls),
    unnamedVariables_(arg__unnamedVariables),
    namedVariables_(arg__namedVariables),
    namedVariableLists_(arg__namedVariableLists),
    namedTypes_(arg__namedTypes),
    dataExchanges_(arg__dataExchanges),
    semaphores_(arg__semaphores),
    operatorStations_(arg__operatorStations),
    eventConditions_(arg__eventConditions),
    eventActions_(arg__eventActions),
    eventEnrollments_(arg__eventEnrollments),
    eventConditionLists_(arg__eventConditionLists),
    journals_(arg__journals),
    selected_Program_Invocation_(arg__selected_Program_Invocation) {
    };



    ITU_T_CHOICEC_DEFN(VMD_File::Selected_Program_Invocation_type::selectedProgram, selectedProgram, Program_Invocation_instance, Selected_Program_Invocation_type_selectedProgram);
    ITU_T_CHOICES_DEFN(VMD_File::Selected_Program_Invocation_type::noneSelected, noneSelected, null_type, Selected_Program_Invocation_type_noneSelected);


    ITU_T_HOLDERH_DEFN(VMD_File::executiveFunction, executiveFunction, MMS_Environment_1::ApplicationReference);
    ITU_T_HOLDERH_DEFN(VMD_File::vendorName, vendorName, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(VMD_File::modelName, modelName, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(VMD_File::revision, revision, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(VMD_File::abstractSyntaxes, abstractSyntaxes, oid_type);
    ITU_T_HOLDERH_DEFN(VMD_File::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(VMD_File::logicalStatus, logicalStatus, MMS_Object_Module_1::LogicalStatus);
    ITU_T_HOLDERH_DEFN(VMD_File::capabilities, capabilities, VMD_File::Capabilities_type);
    ITU_T_HOLDERH_DEFN(VMD_File::physicalStatus, physicalStatus, MMS_Object_Module_1::PhysicalStatus);
    ITU_T_HOLDERH_DEFN(VMD_File::local_detail, local_detail, bitstring_type);
    ITU_T_HOLDERH_DEFN(VMD_File::accessControlLists, accessControlLists, VMD_File::AccessControlLists_type);
    ITU_T_HOLDERH_DEFN(VMD_File::domains, domains, VMD_File::Domains_type);
    ITU_T_HOLDERH_DEFN(VMD_File::programInvocations, programInvocations, VMD_File::ProgramInvocations_type);
    ITU_T_HOLDERH_DEFN(VMD_File::unitControls, unitControls, VMD_File::UnitControls_type);
    ITU_T_HOLDERH_DEFN(VMD_File::unnamedVariables, unnamedVariables, VMD_File::UnnamedVariables_type);
    ITU_T_HOLDERH_DEFN(VMD_File::namedVariables, namedVariables, VMD_File::NamedVariables_type);
    ITU_T_HOLDERH_DEFN(VMD_File::namedVariableLists, namedVariableLists, VMD_File::NamedVariableLists_type);
    ITU_T_HOLDERH_DEFN(VMD_File::namedTypes, namedTypes, VMD_File::NamedTypes_type);
    ITU_T_HOLDERH_DEFN(VMD_File::dataExchanges, dataExchanges, VMD_File::DataExchanges_type);
    ITU_T_HOLDERH_DEFN(VMD_File::semaphores, semaphores, VMD_File::Semaphores_type);
    ITU_T_HOLDERH_DEFN(VMD_File::operatorStations, operatorStations, VMD_File::OperatorStations_type);
    ITU_T_HOLDERH_DEFN(VMD_File::eventConditions, eventConditions, VMD_File::EventConditions_type);
    ITU_T_HOLDERH_DEFN(VMD_File::eventActions, eventActions, VMD_File::EventActions_type);
    ITU_T_HOLDERH_DEFN(VMD_File::eventEnrollments, eventEnrollments, VMD_File::EventEnrollments_type);
    ITU_T_HOLDERH_DEFN(VMD_File::eventConditionLists, eventConditionLists, VMD_File::EventConditionLists_type);
    ITU_T_HOLDERH_DEFN(VMD_File::journals, journals, VMD_File::Journals_type);
    ITU_T_OPTIONAL_DEFN(VMD_File::selected_Program_Invocation, selected_Program_Invocation, VMD_File::Selected_Program_Invocation_type);

    // sequence Access-Control-List-instance

    Access_Control_List_instance::Access_Control_List_instance() : name_(), definition_() {
    };

    Access_Control_List_instance::Access_Control_List_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Access_Control_List_instance::Definition_type::Details_type::Details_type() : accessControl_(), accessControlLists_(), domains_(), programInvocations_(), unitControls_(), unnamedVariables_(), namedVariables_(), namedVariableLists_(), namedTypes_(), dataExchanges_(), semaphores_(), operatorStations_(), eventConditions_(), eventActions_(), eventEnrollments_(), journals_() {
    };

    Access_Control_List_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
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
            const Journals_type& arg__journals) :
    accessControl_(arg__accessControl),
    accessControlLists_(arg__accessControlLists),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations),
    unitControls_(arg__unitControls),
    unnamedVariables_(arg__unnamedVariables),
    namedVariables_(arg__namedVariables),
    namedVariableLists_(arg__namedVariableLists),
    namedTypes_(arg__namedTypes),
    dataExchanges_(arg__dataExchanges),
    semaphores_(arg__semaphores),
    operatorStations_(arg__operatorStations),
    eventConditions_(arg__eventConditions),
    eventActions_(arg__eventActions),
    eventEnrollments_(arg__eventEnrollments),
    journals_(arg__journals) {
    };

    Access_Control_List_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
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
            shared_ptr< EventConditionLists_type> arg__eventConditionLists) :
    accessControl_(arg__accessControl),
    readAccessCondition_(arg__readAccessCondition),
    storeAccessCondition_(arg__storeAccessCondition),
    writeAccessCondition_(arg__writeAccessCondition),
    loadAccessCondition_(arg__loadAccessCondition),
    executeAccessCondition_(arg__executeAccessCondition),
    deleteAccessCondition_(arg__deleteAccessCondition),
    editAccessCondition_(arg__editAccessCondition),
    accessControlLists_(arg__accessControlLists),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations),
    unitControls_(arg__unitControls),
    unnamedVariables_(arg__unnamedVariables),
    namedVariables_(arg__namedVariables),
    namedVariableLists_(arg__namedVariableLists),
    namedTypes_(arg__namedTypes),
    dataExchanges_(arg__dataExchanges),
    semaphores_(arg__semaphores),
    operatorStations_(arg__operatorStations),
    eventConditions_(arg__eventConditions),
    eventActions_(arg__eventActions),
    eventEnrollments_(arg__eventEnrollments),
    journals_(arg__journals),
    eventConditionLists_(arg__eventConditionLists) {
    };


    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::readAccessCondition, readAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::storeAccessCondition, storeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::writeAccessCondition, writeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::loadAccessCondition, loadAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::executeAccessCondition, executeAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::deleteAccessCondition, deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::editAccessCondition, editAccessCondition, MMS_Object_Module_1::AccessCondition);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::accessControlLists, accessControlLists, Access_Control_List_instance::Definition_type::Details_type::AccessControlLists_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::domains, domains, Access_Control_List_instance::Definition_type::Details_type::Domains_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::programInvocations, programInvocations, Access_Control_List_instance::Definition_type::Details_type::ProgramInvocations_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::unitControls, unitControls, Access_Control_List_instance::Definition_type::Details_type::UnitControls_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::unnamedVariables, unnamedVariables, Access_Control_List_instance::Definition_type::Details_type::UnnamedVariables_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::namedVariables, namedVariables, Access_Control_List_instance::Definition_type::Details_type::NamedVariables_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::namedVariableLists, namedVariableLists, Access_Control_List_instance::Definition_type::Details_type::NamedVariableLists_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::namedTypes, namedTypes, Access_Control_List_instance::Definition_type::Details_type::NamedTypes_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::dataExchanges, dataExchanges, Access_Control_List_instance::Definition_type::Details_type::DataExchanges_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::semaphores, semaphores, Access_Control_List_instance::Definition_type::Details_type::Semaphores_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::operatorStations, operatorStations, Access_Control_List_instance::Definition_type::Details_type::OperatorStations_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::eventConditions, eventConditions, Access_Control_List_instance::Definition_type::Details_type::EventConditions_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::eventActions, eventActions, Access_Control_List_instance::Definition_type::Details_type::EventActions_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::eventEnrollments, eventEnrollments, Access_Control_List_instance::Definition_type::Details_type::EventEnrollments_type);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::Definition_type::Details_type::journals, journals, Access_Control_List_instance::Definition_type::Details_type::Journals_type);
    ITU_T_OPTIONAL_DEFN(Access_Control_List_instance::Definition_type::Details_type::eventConditionLists, eventConditionLists, Access_Control_List_instance::Definition_type::Details_type::EventConditionLists_type);


    ITU_T_CHOICES_DEFN(Access_Control_List_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Access_Control_List_instance::Definition_type::details, details, Access_Control_List_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Access_Control_List_instance::definition, definition, Access_Control_List_instance::Definition_type);

    // sequence Domain-instance

    Domain_instance::Domain_instance() : name_(), definition_() {
    };

    Domain_instance::Domain_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Domain_instance::Definition_type::Details_type::Details_type() : capabilities_(), state_(), accessControl_(), sharable_(), programInvocations_(), namedVariables_(), namedVariableLists_(), namedTypes_(), eventConditions_(), eventActions_(), eventEnrollments_(), eventConditionLists_() {
    };

    Domain_instance::Definition_type::Details_type::Details_type(const Capabilities_type& arg__capabilities,
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
            const EventConditionLists_type& arg__eventConditionLists) :
    capabilities_(arg__capabilities),
    state_(arg__state),
    accessControl_(arg__accessControl),
    sharable_(arg__sharable),
    programInvocations_(arg__programInvocations),
    namedVariables_(arg__namedVariables),
    namedVariableLists_(arg__namedVariableLists),
    namedTypes_(arg__namedTypes),
    eventConditions_(arg__eventConditions),
    eventActions_(arg__eventActions),
    eventEnrollments_(arg__eventEnrollments),
    eventConditionLists_(arg__eventConditionLists) {
    };


    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::capabilities, capabilities, Domain_instance::Definition_type::Details_type::Capabilities_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::state, state, MMS_Object_Module_1::DomainState);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::sharable, sharable, bool);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::programInvocations, programInvocations, Domain_instance::Definition_type::Details_type::ProgramInvocations_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::namedVariables, namedVariables, Domain_instance::Definition_type::Details_type::NamedVariables_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::namedVariableLists, namedVariableLists, Domain_instance::Definition_type::Details_type::NamedVariableLists_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::namedTypes, namedTypes, Domain_instance::Definition_type::Details_type::NamedTypes_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::eventConditions, eventConditions, Domain_instance::Definition_type::Details_type::EventConditions_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::eventActions, eventActions, Domain_instance::Definition_type::Details_type::EventActions_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::eventEnrollments, eventEnrollments, Domain_instance::Definition_type::Details_type::EventEnrollments_type);
    ITU_T_HOLDERH_DEFN(Domain_instance::Definition_type::Details_type::eventConditionLists, eventConditionLists, Domain_instance::Definition_type::Details_type::EventConditionLists_type);


    ITU_T_CHOICES_DEFN(Domain_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Domain_instance::Definition_type::details, details, Domain_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Domain_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Domain_instance::definition, definition, Domain_instance::Definition_type);

    // sequence Program-Invocation-instance

    Program_Invocation_instance::Program_Invocation_instance() : name_(), definition_() {
    };

    Program_Invocation_instance::Program_Invocation_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Program_Invocation_instance::Definition_type::Details_type::Details_type() : programInvocationState_(), domains_(), accessControl_(), reusable_(), monitor_(), executionArgument_() {
    };

    Program_Invocation_instance::Definition_type::Details_type::Details_type(const MMS_Object_Module_1::ProgramInvocationState& arg__programInvocationState,
            const Domains_type& arg__domains,
            const AccessControl_type& arg__accessControl,
            const bool& arg__reusable,
            const bool& arg__monitor,
            const ISO_9506_MMS_1::MMSString& arg__executionArgument) :
    programInvocationState_(arg__programInvocationState),
    domains_(arg__domains),
    accessControl_(arg__accessControl),
    reusable_(arg__reusable),
    monitor_(arg__monitor),
    executionArgument_(arg__executionArgument) {
    };

    Program_Invocation_instance::Definition_type::Details_type::Details_type(shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__programInvocationState,
            shared_ptr< Domains_type> arg__domains,
            shared_ptr< AccessControl_type> arg__accessControl,
            shared_ptr< bool> arg__reusable,
            shared_ptr< bool> arg__monitor,
            shared_ptr< EventCondition_type> arg__eventCondition,
            shared_ptr< EventAction_type> arg__eventAction,
            shared_ptr< EventEnrollment_type> arg__eventEnrollment,
            shared_ptr< ISO_9506_MMS_1::MMSString> arg__executionArgument,
            shared_ptr< MMS_Object_Module_1::Control_State> arg__control,
            shared_ptr< Program_Invocation_instance> arg__controlling_Program_Invocation,
            shared_ptr< Controlled_Program_Invocations_type> arg__controlled_Program_Invocations) :
    programInvocationState_(arg__programInvocationState),
    domains_(arg__domains),
    accessControl_(arg__accessControl),
    reusable_(arg__reusable),
    monitor_(arg__monitor),
    eventCondition_(arg__eventCondition),
    eventAction_(arg__eventAction),
    eventEnrollment_(arg__eventEnrollment),
    executionArgument_(arg__executionArgument),
    control_(arg__control),
    controlling_Program_Invocation_(arg__controlling_Program_Invocation),
    controlled_Program_Invocations_(arg__controlled_Program_Invocations) {
    };


    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::Definition_type::Details_type::programInvocationState, programInvocationState, MMS_Object_Module_1::ProgramInvocationState);
    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::Definition_type::Details_type::domains, domains, Program_Invocation_instance::Definition_type::Details_type::Domains_type);
    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::Definition_type::Details_type::accessControl, accessControl, Program_Invocation_instance::Definition_type::Details_type::AccessControl_type);
    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::Definition_type::Details_type::reusable, reusable, bool);
    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::Definition_type::Details_type::monitor, monitor, bool);
    ITU_T_OPTIONAL_DEFN(Program_Invocation_instance::Definition_type::Details_type::eventCondition, eventCondition, Program_Invocation_instance::Definition_type::Details_type::EventCondition_type);
    ITU_T_OPTIONAL_DEFN(Program_Invocation_instance::Definition_type::Details_type::eventAction, eventAction, Program_Invocation_instance::Definition_type::Details_type::EventAction_type);
    ITU_T_OPTIONAL_DEFN(Program_Invocation_instance::Definition_type::Details_type::eventEnrollment, eventEnrollment, Program_Invocation_instance::Definition_type::Details_type::EventEnrollment_type);
    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::Definition_type::Details_type::executionArgument, executionArgument, ISO_9506_MMS_1::MMSString);
    ITU_T_OPTIONAL_DEFN(Program_Invocation_instance::Definition_type::Details_type::control, control, MMS_Object_Module_1::Control_State);
    ITU_T_OPTIONAL_DEFN(Program_Invocation_instance::Definition_type::Details_type::controlling_Program_Invocation, controlling_Program_Invocation, Program_Invocation_instance);
    ITU_T_OPTIONAL_DEFN(Program_Invocation_instance::Definition_type::Details_type::controlled_Program_Invocations, controlled_Program_Invocations, Program_Invocation_instance::Definition_type::Details_type::Controlled_Program_Invocations_type);


    ITU_T_CHOICES_DEFN(Program_Invocation_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Program_Invocation_instance::Definition_type::details, details, Program_Invocation_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Program_Invocation_instance::definition, definition, Program_Invocation_instance::Definition_type);

    // sequence Unit-Control-instance

    Unit_Control_instance::Unit_Control_instance() : name_(), definition_() {
    };

    Unit_Control_instance::Unit_Control_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Unit_Control_instance::Definition_type::Details_type::Details_type() : accessControl_(), domains_(), programInvocations_() {
    };

    Unit_Control_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const Domains_type& arg__domains,
            const ProgramInvocations_type& arg__programInvocations) :
    accessControl_(arg__accessControl),
    domains_(arg__domains),
    programInvocations_(arg__programInvocations) {
    };


    ITU_T_HOLDERH_DEFN(Unit_Control_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Unit_Control_instance::Definition_type::Details_type::domains, domains, Unit_Control_instance::Definition_type::Details_type::Domains_type);
    ITU_T_HOLDERH_DEFN(Unit_Control_instance::Definition_type::Details_type::programInvocations, programInvocations, Unit_Control_instance::Definition_type::Details_type::ProgramInvocations_type);


    ITU_T_CHOICES_DEFN(Unit_Control_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Unit_Control_instance::Definition_type::details, details, Unit_Control_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Unit_Control_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Unit_Control_instance::definition, definition, Unit_Control_instance::Definition_type);

    // sequence Unnamed-Variable-instance

    Unnamed_Variable_instance::Unnamed_Variable_instance() : address_(), accessControl_(), typeDescription_() {
    };

    Unnamed_Variable_instance::Unnamed_Variable_instance(const MMS_Object_Module_1::Address& arg__address,
            const Access_Control_List_instance& arg__accessControl,
            const MMS_Object_Module_1::TypeDescription& arg__typeDescription) :
    address_(arg__address),
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription) {
    };


    ITU_T_HOLDERH_DEFN(Unnamed_Variable_instance::address, address, MMS_Object_Module_1::Address);
    ITU_T_HOLDERH_DEFN(Unnamed_Variable_instance::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Unnamed_Variable_instance::typeDescription, typeDescription, MMS_Object_Module_1::TypeDescription);

    // sequence Named-Variable-instance

    Named_Variable_instance::Named_Variable_instance() : name_(), definition_() {
    };

    Named_Variable_instance::Named_Variable_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Named_Variable_instance::Definition_type::Details_type::Details_type() : accessControl_(), typeDescription_() {
    };

    Named_Variable_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const MMS_Object_Module_1::TypeDescription& arg__typeDescription) :
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription) {
    };

    Named_Variable_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
            shared_ptr< MMS_Object_Module_1::Address> arg__address,
            shared_ptr< visiblestring_type> arg__meaning) :
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription),
    address_(arg__address),
    meaning_(arg__meaning) {
    };


    ITU_T_HOLDERH_DEFN(Named_Variable_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Named_Variable_instance::Definition_type::Details_type::typeDescription, typeDescription, MMS_Object_Module_1::TypeDescription);
    ITU_T_OPTIONAL_DEFN(Named_Variable_instance::Definition_type::Details_type::address, address, MMS_Object_Module_1::Address);
    ITU_T_OPTIONAL_DEFN(Named_Variable_instance::Definition_type::Details_type::meaning, meaning, visiblestring_type);


    ITU_T_CHOICES_DEFN(Named_Variable_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Named_Variable_instance::Definition_type::details, details, Named_Variable_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Named_Variable_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Named_Variable_instance::definition, definition, Named_Variable_instance::Definition_type);

    // sequence Named-Variable-List-instance

    Named_Variable_List_instance::Named_Variable_List_instance() : name_(), definition_() {
    };

    Named_Variable_List_instance::Named_Variable_List_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Named_Variable_List_instance::Definition_type::Details_type::Details_type() : accessControl_(), listOfVariables_() {
    };

    Named_Variable_List_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const ListOfVariables_type& arg__listOfVariables) :
    accessControl_(arg__accessControl),
    listOfVariables_(arg__listOfVariables) {
    };


    ITU_T_HOLDERH_DEFN(Named_Variable_List_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Named_Variable_List_instance::Definition_type::Details_type::listOfVariables, listOfVariables, Named_Variable_List_instance::Definition_type::Details_type::ListOfVariables_type);


    ITU_T_CHOICES_DEFN(Named_Variable_List_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Named_Variable_List_instance::Definition_type::details, details, Named_Variable_List_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Named_Variable_List_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Named_Variable_List_instance::definition, definition, Named_Variable_List_instance::Definition_type);

    // sequence Variable-List-Item-instance

    Variable_List_Item_instance::Variable_List_Item_instance() {
    };

    Variable_List_Item_instance::Variable_List_Item_instance(shared_ptr< Unnamed_Variable_instance> arg__unnamedItem,
            shared_ptr< Named_Variable_instance> arg__namedItem,
            shared_ptr< ISO_9506_MMS_1::AlternateAccess> arg__alternateAccess) :
    unnamedItem_(arg__unnamedItem),
    namedItem_(arg__namedItem),
    alternateAccess_(arg__alternateAccess) {
    };


    ITU_T_OPTIONAL_DEFN(Variable_List_Item_instance::unnamedItem, unnamedItem, Unnamed_Variable_instance);
    ITU_T_OPTIONAL_DEFN(Variable_List_Item_instance::namedItem, namedItem, Named_Variable_instance);
    ITU_T_OPTIONAL_DEFN(Variable_List_Item_instance::alternateAccess, alternateAccess, ISO_9506_MMS_1::AlternateAccess);

    // sequence Named-Type-instance

    Named_Type_instance::Named_Type_instance() : name_(), definition_() {
    };

    Named_Type_instance::Named_Type_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Named_Type_instance::Definition_type::Details_type::Details_type() : accessControl_(), typeDescription_() {
    };

    Named_Type_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const MMS_Object_Module_1::TypeDescription& arg__typeDescription) :
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription) {
    };

    Named_Type_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
            shared_ptr< visiblestring_type> arg__meaning) :
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription),
    meaning_(arg__meaning) {
    };


    ITU_T_HOLDERH_DEFN(Named_Type_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Named_Type_instance::Definition_type::Details_type::typeDescription, typeDescription, MMS_Object_Module_1::TypeDescription);
    ITU_T_OPTIONAL_DEFN(Named_Type_instance::Definition_type::Details_type::meaning, meaning, visiblestring_type);


    ITU_T_CHOICES_DEFN(Named_Type_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Named_Type_instance::Definition_type::details, details, Named_Type_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Named_Type_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Named_Type_instance::definition, definition, Named_Type_instance::Definition_type);

    // sequence Data-Exchange-instance

    Data_Exchange_instance::Data_Exchange_instance() : name_(), definition_() {
    };

    Data_Exchange_instance::Data_Exchange_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Data_Exchange_instance::Definition_type::Details_type::Details_type() : accessControl_(), request_(), response_(), linked_() {
    };

    Data_Exchange_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const Request_type& arg__request,
            const Response_type& arg__response,
            const bool& arg__linked) :
    accessControl_(arg__accessControl),
    request_(arg__request),
    response_(arg__response),
    linked_(arg__linked) {
    };

    Data_Exchange_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< Request_type> arg__request,
            shared_ptr< Response_type> arg__response,
            shared_ptr< bool> arg__linked,
            shared_ptr< Program_Invocation_instance> arg__programInvocation) :
    accessControl_(arg__accessControl),
    request_(arg__request),
    response_(arg__response),
    linked_(arg__linked),
    programInvocation_(arg__programInvocation) {
    };


    ITU_T_HOLDERH_DEFN(Data_Exchange_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Data_Exchange_instance::Definition_type::Details_type::request, request, Data_Exchange_instance::Definition_type::Details_type::Request_type);
    ITU_T_HOLDERH_DEFN(Data_Exchange_instance::Definition_type::Details_type::response, response, Data_Exchange_instance::Definition_type::Details_type::Response_type);
    ITU_T_HOLDERH_DEFN(Data_Exchange_instance::Definition_type::Details_type::linked, linked, bool);
    ITU_T_OPTIONAL_DEFN(Data_Exchange_instance::Definition_type::Details_type::programInvocation, programInvocation, Program_Invocation_instance);


    ITU_T_CHOICES_DEFN(Data_Exchange_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Data_Exchange_instance::Definition_type::details, details, Data_Exchange_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Data_Exchange_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Data_Exchange_instance::definition, definition, Data_Exchange_instance::Definition_type);

    // sequence Semaphore-instance

    Semaphore_instance::Semaphore_instance() : name_(), definition_() {
    };

    Semaphore_instance::Semaphore_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };



    const enumerated_type Semaphore_instance::Definition_type::Details_type::classV_token = 0;
    const enumerated_type Semaphore_instance::Definition_type::Details_type::classV_pool = 1;

    Semaphore_instance::Definition_type::Details_type::Details_type() : accessControl_(), classV_(), eventCondition_() {
    };

    Semaphore_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const enumerated_type& arg__classV,
            const Event_Condition_instance& arg__eventCondition) :
    accessControl_(arg__accessControl),
    classV_(arg__classV),
    eventCondition_(arg__eventCondition) {
    };

    Semaphore_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< enumerated_type> arg__classV,
            shared_ptr< integer_type> arg__numberOfTokens,
            shared_ptr< NamedTokens_type> arg__namedTokens,
            shared_ptr< Event_Condition_instance> arg__eventCondition) :
    accessControl_(arg__accessControl),
    classV_(arg__classV),
    numberOfTokens_(arg__numberOfTokens),
    namedTokens_(arg__namedTokens),
    eventCondition_(arg__eventCondition) {
    };


    ITU_T_HOLDERH_DEFN(Semaphore_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Semaphore_instance::Definition_type::Details_type::classV, classV, enumerated_type);
    ITU_T_OPTIONAL_DEFN(Semaphore_instance::Definition_type::Details_type::numberOfTokens, numberOfTokens, integer_type);
    ITU_T_OPTIONAL_DEFN(Semaphore_instance::Definition_type::Details_type::namedTokens, namedTokens, Semaphore_instance::Definition_type::Details_type::NamedTokens_type);
    ITU_T_HOLDERH_DEFN(Semaphore_instance::Definition_type::Details_type::eventCondition, eventCondition, Event_Condition_instance);


    ITU_T_CHOICES_DEFN(Semaphore_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Semaphore_instance::Definition_type::details, details, Semaphore_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Semaphore_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Semaphore_instance::definition, definition, Semaphore_instance::Definition_type);

    // sequence Operator-Station-instance

    Operator_Station_instance::Operator_Station_instance() : name_(), definition_() {
    };

    Operator_Station_instance::Operator_Station_instance(const ISO_9506_MMS_1::Identifier& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };



    const enumerated_type Operator_Station_instance::Definition_type::Details_type::stationType_entry = 0;
    const enumerated_type Operator_Station_instance::Definition_type::Details_type::stationType_display = 1;
    const enumerated_type Operator_Station_instance::Definition_type::Details_type::stationType_entry_display = 2;

    Operator_Station_instance::Definition_type::Details_type::Details_type() : accessControl_(), stationType_() {
    };

    Operator_Station_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const enumerated_type& arg__stationType) :
    accessControl_(arg__accessControl),
    stationType_(arg__stationType) {
    };


    ITU_T_HOLDERH_DEFN(Operator_Station_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Operator_Station_instance::Definition_type::Details_type::stationType, stationType, enumerated_type);


    ITU_T_CHOICES_DEFN(Operator_Station_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Operator_Station_instance::Definition_type::details, details, Operator_Station_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Operator_Station_instance::name, name, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(Operator_Station_instance::definition, definition, Operator_Station_instance::Definition_type);

    // sequence Event-Condition-instance

    Event_Condition_instance::Event_Condition_instance() : name_(), definition_() {
    };

    Event_Condition_instance::Event_Condition_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Event_Condition_instance::Definition_type::Details_type::Details_type() : accessControl_(), ecClass_(), ecState_(), priority_(), severity_(), eventEnrollments_() {
    };

    Event_Condition_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const MMS_Object_Module_1::EC_Class& arg__ecClass,
            const MMS_Object_Module_1::EC_State& arg__ecState,
            const MMS_Object_Module_1::Priority& arg__priority,
            const MMS_Object_Module_1::Severity& arg__severity,
            const EventEnrollments_type& arg__eventEnrollments) :
    accessControl_(arg__accessControl),
    ecClass_(arg__ecClass),
    ecState_(arg__ecState),
    priority_(arg__priority),
    severity_(arg__severity),
    eventEnrollments_(arg__eventEnrollments) {
    };

    Event_Condition_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< MMS_Object_Module_1::EC_Class> arg__ecClass,
            shared_ptr< MMS_Object_Module_1::EC_State> arg__ecState,
            shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
            shared_ptr< EventEnrollments_type> arg__eventEnrollments,
            shared_ptr< bool> arg__enabled,
            shared_ptr< bool> arg__alarmSummaryReports,
            shared_ptr< MonitoredVariable_type> arg__monitoredVariable,
            shared_ptr< integer_type> arg__evaluationInterval,
            shared_ptr< DisplayEnhancement_type> arg__displayEnhancement,
            shared_ptr< Group_Priority_Override_type> arg__group_Priority_Override,
            shared_ptr< ReferencingEventConditionLists_type> arg__referencingEventConditionLists) :
    accessControl_(arg__accessControl),
    ecClass_(arg__ecClass),
    ecState_(arg__ecState),
    priority_(arg__priority),
    severity_(arg__severity),
    eventEnrollments_(arg__eventEnrollments),
    enabled_(arg__enabled),
    alarmSummaryReports_(arg__alarmSummaryReports),
    monitoredVariable_(arg__monitoredVariable),
    evaluationInterval_(arg__evaluationInterval),
    displayEnhancement_(arg__displayEnhancement),
    group_Priority_Override_(arg__group_Priority_Override),
    referencingEventConditionLists_(arg__referencingEventConditionLists) {
    };



    ITU_T_CHOICEC_DEFN(Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::named, named, Named_Variable_instance, MonitoredVariable_type_named);
    ITU_T_CHOICEC_DEFN(Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::unnamed, unnamed, Unnamed_Variable_instance, MonitoredVariable_type_unnamed);
    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::unspecified, unspecified, null_type, MonitoredVariable_type_unspecified);



    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::text, text, ISO_9506_MMS_1::MMSString, DisplayEnhancement_type_text);
    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::number, number, integer_type, DisplayEnhancement_type_number);
    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::none, none, null_type, DisplayEnhancement_type_none);



    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::priority, priority, MMS_Object_Module_1::Priority, Group_Priority_Override_type_priority);
    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::undefined, undefined, null_type, Group_Priority_Override_type_undefined);


    ITU_T_HOLDERH_DEFN(Event_Condition_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Event_Condition_instance::Definition_type::Details_type::ecClass, ecClass, MMS_Object_Module_1::EC_Class);
    ITU_T_HOLDERH_DEFN(Event_Condition_instance::Definition_type::Details_type::ecState, ecState, MMS_Object_Module_1::EC_State);
    ITU_T_HOLDERH_DEFN(Event_Condition_instance::Definition_type::Details_type::priority, priority, MMS_Object_Module_1::Priority);
    ITU_T_HOLDERH_DEFN(Event_Condition_instance::Definition_type::Details_type::severity, severity, MMS_Object_Module_1::Severity);
    ITU_T_HOLDERH_DEFN(Event_Condition_instance::Definition_type::Details_type::eventEnrollments, eventEnrollments, Event_Condition_instance::Definition_type::Details_type::EventEnrollments_type);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::enabled, enabled, bool);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::alarmSummaryReports, alarmSummaryReports, bool);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::monitoredVariable, monitoredVariable, Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::evaluationInterval, evaluationInterval, integer_type);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::displayEnhancement, displayEnhancement, Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::group_Priority_Override, group_Priority_Override, Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type);
    ITU_T_OPTIONAL_DEFN(Event_Condition_instance::Definition_type::Details_type::referencingEventConditionLists, referencingEventConditionLists, Event_Condition_instance::Definition_type::Details_type::ReferencingEventConditionLists_type);


    ITU_T_CHOICES_DEFN(Event_Condition_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Event_Condition_instance::Definition_type::details, details, Event_Condition_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Event_Condition_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Event_Condition_instance::definition, definition, Event_Condition_instance::Definition_type);

    // sequence Event-Action-instance

    Event_Action_instance::Event_Action_instance() : name_(), definition_() {
    };

    Event_Action_instance::Event_Action_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Event_Action_instance::Definition_type::Details_type::Details_type() : accessControl_(), confirmedServiceRequest_(), modifiers_(), eventEnrollments_() {
    };

    Event_Action_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const ISO_9506_MMS_1::ConfirmedServiceRequest& arg__confirmedServiceRequest,
            const Modifiers_type& arg__modifiers,
            const EventEnrollments_type& arg__eventEnrollments) :
    accessControl_(arg__accessControl),
    confirmedServiceRequest_(arg__confirmedServiceRequest),
    modifiers_(arg__modifiers),
    eventEnrollments_(arg__eventEnrollments) {
    };


    ITU_T_HOLDERH_DEFN(Event_Action_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Event_Action_instance::Definition_type::Details_type::confirmedServiceRequest, confirmedServiceRequest, ISO_9506_MMS_1::ConfirmedServiceRequest);
    ITU_T_HOLDERH_DEFN(Event_Action_instance::Definition_type::Details_type::modifiers, modifiers, Event_Action_instance::Definition_type::Details_type::Modifiers_type);
    ITU_T_HOLDERH_DEFN(Event_Action_instance::Definition_type::Details_type::eventEnrollments, eventEnrollments, Event_Action_instance::Definition_type::Details_type::EventEnrollments_type);


    ITU_T_CHOICES_DEFN(Event_Action_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Event_Action_instance::Definition_type::details, details, Event_Action_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Event_Action_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Event_Action_instance::definition, definition, Event_Action_instance::Definition_type);

    // sequence Event-Enrollment-instance

    Event_Enrollment_instance::Event_Enrollment_instance() : name_(), definition_() {
    };

    Event_Enrollment_instance::Event_Enrollment_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Event_Enrollment_instance::Definition_type::Details_type::Details_type() : accessControl_(), eeClass_(), eventCondition_(), ecTransitions_() {
    };

    Event_Enrollment_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const MMS_Object_Module_1::EE_Class& arg__eeClass,
            const Event_Condition_instance& arg__eventCondition,
            const MMS_Object_Module_1::Transitions& arg__ecTransitions) :
    accessControl_(arg__accessControl),
    eeClass_(arg__eeClass),
    eventCondition_(arg__eventCondition),
    ecTransitions_(arg__ecTransitions) {
    };

    Event_Enrollment_instance::Definition_type::Details_type::Details_type(shared_ptr< Access_Control_List_instance> arg__accessControl,
            shared_ptr< MMS_Object_Module_1::EE_Class> arg__eeClass,
            shared_ptr< Event_Condition_instance> arg__eventCondition,
            shared_ptr< MMS_Object_Module_1::Transitions> arg__ecTransitions,
            shared_ptr< RemainingDelay_type> arg__remainingDelay,
            shared_ptr< Event_Action_instance> arg__eventAction,
            shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__aaRule,
            shared_ptr< DisplayEnhancement_type> arg__displayEnhancement) :
    accessControl_(arg__accessControl),
    eeClass_(arg__eeClass),
    eventCondition_(arg__eventCondition),
    ecTransitions_(arg__ecTransitions),
    remainingDelay_(arg__remainingDelay),
    eventAction_(arg__eventAction),
    duration_(arg__duration),
    clientApplication_(arg__clientApplication),
    aaRule_(arg__aaRule),
    displayEnhancement_(arg__displayEnhancement) {
    };



    ITU_T_CHOICES_DEFN(Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::time, time, integer_type, RemainingDelay_type_time);
    ITU_T_CHOICES_DEFN(Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::forever, forever, null_type, RemainingDelay_type_forever);



    ITU_T_CHOICES_DEFN(Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::text, text, ISO_9506_MMS_1::MMSString, DisplayEnhancement_type_text);
    ITU_T_CHOICES_DEFN(Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::number, number, integer_type, DisplayEnhancement_type_number);
    ITU_T_CHOICES_DEFN(Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::none, none, null_type, DisplayEnhancement_type_none);


    ITU_T_HOLDERH_DEFN(Event_Enrollment_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Event_Enrollment_instance::Definition_type::Details_type::eeClass, eeClass, MMS_Object_Module_1::EE_Class);
    ITU_T_HOLDERH_DEFN(Event_Enrollment_instance::Definition_type::Details_type::eventCondition, eventCondition, Event_Condition_instance);
    ITU_T_HOLDERH_DEFN(Event_Enrollment_instance::Definition_type::Details_type::ecTransitions, ecTransitions, MMS_Object_Module_1::Transitions);
    ITU_T_OPTIONAL_DEFN(Event_Enrollment_instance::Definition_type::Details_type::remainingDelay, remainingDelay, Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type);
    ITU_T_OPTIONAL_DEFN(Event_Enrollment_instance::Definition_type::Details_type::eventAction, eventAction, Event_Action_instance);
    ITU_T_OPTIONAL_DEFN(Event_Enrollment_instance::Definition_type::Details_type::duration, duration, MMS_Object_Module_1::EE_Duration);
    ITU_T_OPTIONAL_DEFN(Event_Enrollment_instance::Definition_type::Details_type::clientApplication, clientApplication, MMS_Environment_1::ApplicationReference);
    ITU_T_OPTIONAL_DEFN(Event_Enrollment_instance::Definition_type::Details_type::aaRule, aaRule, MMS_Object_Module_1::AlarmAckRule);
    ITU_T_OPTIONAL_DEFN(Event_Enrollment_instance::Definition_type::Details_type::displayEnhancement, displayEnhancement, Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type);


    ITU_T_CHOICES_DEFN(Event_Enrollment_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Event_Enrollment_instance::Definition_type::details, details, Event_Enrollment_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Event_Enrollment_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Event_Enrollment_instance::definition, definition, Event_Enrollment_instance::Definition_type);

    // sequence Event-Condition-List-instance

    Event_Condition_List_instance::Event_Condition_List_instance() : name_(), definition_() {
    };

    Event_Condition_List_instance::Event_Condition_List_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Event_Condition_List_instance::Definition_type::Details_type::Details_type() : accessControl_(), eventConditions_(), eventConditionLists_(), referencingEventConditionLists_() {
    };

    Event_Condition_List_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const EventConditions_type& arg__eventConditions,
            const EventConditionLists_type& arg__eventConditionLists,
            const ReferencingEventConditionLists_type& arg__referencingEventConditionLists) :
    accessControl_(arg__accessControl),
    eventConditions_(arg__eventConditions),
    eventConditionLists_(arg__eventConditionLists),
    referencingEventConditionLists_(arg__referencingEventConditionLists) {
    };


    ITU_T_HOLDERH_DEFN(Event_Condition_List_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Event_Condition_List_instance::Definition_type::Details_type::eventConditions, eventConditions, Event_Condition_List_instance::Definition_type::Details_type::EventConditions_type);
    ITU_T_HOLDERH_DEFN(Event_Condition_List_instance::Definition_type::Details_type::eventConditionLists, eventConditionLists, Event_Condition_List_instance::Definition_type::Details_type::EventConditionLists_type);
    ITU_T_HOLDERH_DEFN(Event_Condition_List_instance::Definition_type::Details_type::referencingEventConditionLists, referencingEventConditionLists, Event_Condition_List_instance::Definition_type::Details_type::ReferencingEventConditionLists_type);


    ITU_T_CHOICES_DEFN(Event_Condition_List_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Event_Condition_List_instance::Definition_type::details, details, Event_Condition_List_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Event_Condition_List_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Event_Condition_List_instance::definition, definition, Event_Condition_List_instance::Definition_type);

    // sequence Journal-instance

    Journal_instance::Journal_instance() : name_(), definition_() {
    };

    Journal_instance::Journal_instance(const ISO_9506_MMS_1::ObjectName& arg__name,
            const Definition_type& arg__definition) :
    name_(arg__name),
    definition_(arg__definition) {
    };

    Journal_instance::Definition_type::Details_type::Details_type() : accessControl_(), entries_() {
    };

    Journal_instance::Definition_type::Details_type::Details_type(const Access_Control_List_instance& arg__accessControl,
            const Entries_type& arg__entries) :
    accessControl_(arg__accessControl),
    entries_(arg__entries) {
    };


    ITU_T_HOLDERH_DEFN(Journal_instance::Definition_type::Details_type::accessControl, accessControl, Access_Control_List_instance);
    ITU_T_HOLDERH_DEFN(Journal_instance::Definition_type::Details_type::entries, entries, Journal_instance::Definition_type::Details_type::Entries_type);


    ITU_T_CHOICES_DEFN(Journal_instance::Definition_type::reference, reference, oid_type, Definition_type_reference);
    ITU_T_CHOICEC_DEFN(Journal_instance::Definition_type::details, details, Journal_instance::Definition_type::Details_type, Definition_type_details);


    ITU_T_HOLDERH_DEFN(Journal_instance::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Journal_instance::definition, definition, Journal_instance::Definition_type);

    // sequence Journal-Entry-instance
    const enumerated_type Journal_Entry_instance::informationType_annotation = 0;
    const enumerated_type Journal_Entry_instance::informationType_event_data = 1;
    const enumerated_type Journal_Entry_instance::informationType_data = 2;

    Journal_Entry_instance::Journal_Entry_instance() : journal_(), entry_(), clientApplication_(), timeStamp_(), orderOfReceipt_(), informationType_() {
    };

    Journal_Entry_instance::Journal_Entry_instance(const Journal_instance& arg__journal,
            const octetstring_type& arg__entry,
            const MMS_Environment_1::ApplicationReference& arg__clientApplication,
            const ISO_9506_MMS_1::TimeOfDay& arg__timeStamp,
            const integer_type& arg__orderOfReceipt,
            const enumerated_type& arg__informationType) :
    journal_(arg__journal),
    entry_(arg__entry),
    clientApplication_(arg__clientApplication),
    timeStamp_(arg__timeStamp),
    orderOfReceipt_(arg__orderOfReceipt),
    informationType_(arg__informationType) {
    };

    Journal_Entry_instance::Journal_Entry_instance(shared_ptr< Journal_instance> arg__journal,
            shared_ptr< octetstring_type> arg__entry,
            shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            shared_ptr< ISO_9506_MMS_1::TimeOfDay> arg__timeStamp,
            shared_ptr< integer_type> arg__orderOfReceipt,
            shared_ptr< enumerated_type> arg__informationType,
            shared_ptr< ISO_9506_MMS_1::MMS255String> arg__textComment,
            shared_ptr< EventTransitionRecord_type> arg__eventTransitionRecord,
            shared_ptr< JournalVariables_type> arg__journalVariables) :
    journal_(arg__journal),
    entry_(arg__entry),
    clientApplication_(arg__clientApplication),
    timeStamp_(arg__timeStamp),
    orderOfReceipt_(arg__orderOfReceipt),
    informationType_(arg__informationType),
    textComment_(arg__textComment),
    eventTransitionRecord_(arg__eventTransitionRecord),
    journalVariables_(arg__journalVariables) {
    };

    Journal_Entry_instance::EventTransitionRecord_type::EventTransitionRecord_type() : name_(), currentState_() {
    };

    Journal_Entry_instance::EventTransitionRecord_type::EventTransitionRecord_type(const ISO_9506_MMS_1::ObjectName& arg__name,
            const MMS_Object_Module_1::EC_State& arg__currentState) :
    name_(arg__name),
    currentState_(arg__currentState) {
    };


    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::EventTransitionRecord_type::name, name, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::EventTransitionRecord_type::currentState, currentState, MMS_Object_Module_1::EC_State);

    Journal_Entry_instance::JournalVariables_type_sequence_of::JournalVariables_type_sequence_of() : variableTag_(), valueSpecification_() {
    };

    Journal_Entry_instance::JournalVariables_type_sequence_of::JournalVariables_type_sequence_of(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
            const ISO_9506_MMS_1::Data& arg__valueSpecification) :
    variableTag_(arg__variableTag),
    valueSpecification_(arg__valueSpecification) {
    };


    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::JournalVariables_type_sequence_of::variableTag, variableTag, ISO_9506_MMS_1::MMS255String);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::JournalVariables_type_sequence_of::valueSpecification, valueSpecification, ISO_9506_MMS_1::Data);


    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::journal, journal, Journal_instance);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::entry, entry, octetstring_type);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::clientApplication, clientApplication, MMS_Environment_1::ApplicationReference);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::timeStamp, timeStamp, ISO_9506_MMS_1::TimeOfDay);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::orderOfReceipt, orderOfReceipt, integer_type);
    ITU_T_HOLDERH_DEFN(Journal_Entry_instance::informationType, informationType, enumerated_type);
    ITU_T_OPTIONAL_DEFN(Journal_Entry_instance::textComment, textComment, ISO_9506_MMS_1::MMS255String);
    ITU_T_OPTIONAL_DEFN(Journal_Entry_instance::eventTransitionRecord, eventTransitionRecord, Journal_Entry_instance::EventTransitionRecord_type);
    ITU_T_OPTIONAL_DEFN(Journal_Entry_instance::journalVariables, journalVariables, Journal_Entry_instance::JournalVariables_type);

    // sequence Service-and-Parameter-CBBs

    Service_and_Parameter_CBBs::Service_and_Parameter_CBBs() : services_Client_(), services_Server_(), parameters_(), nest_(), extendedServices_Client_(), extendedServices_Server_(), extendedParameters_(), generalManagement_(), vMDSupport_(), domainManagement_(), programInvocation_(), variableAccess_(), dataParameters_(), semaphoreManagement_(), operatorCommunication_(), errors_(), fileManagement_() {
    };

    Service_and_Parameter_CBBs::Service_and_Parameter_CBBs(const MMS_Object_Module_1::ServiceSupportOptions& arg__services_Client,
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
            const FileManagementParameters& arg__fileManagement) :
    services_Client_(arg__services_Client),
    services_Server_(arg__services_Server),
    parameters_(arg__parameters),
    nest_(arg__nest),
    extendedServices_Client_(arg__extendedServices_Client),
    extendedServices_Server_(arg__extendedServices_Server),
    extendedParameters_(arg__extendedParameters),
    generalManagement_(arg__generalManagement),
    vMDSupport_(arg__vMDSupport),
    domainManagement_(arg__domainManagement),
    programInvocation_(arg__programInvocation),
    variableAccess_(arg__variableAccess),
    dataParameters_(arg__dataParameters),
    semaphoreManagement_(arg__semaphoreManagement),
    operatorCommunication_(arg__operatorCommunication),
    errors_(arg__errors),
    fileManagement_(arg__fileManagement) {
    };


    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::services_Client, services_Client, MMS_Object_Module_1::ServiceSupportOptions);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::services_Server, services_Server, MMS_Object_Module_1::ServiceSupportOptions);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::parameters, parameters, MMS_Object_Module_1::ParameterSupportOptions);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::nest, nest, integer_type);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::extendedServices_Client, extendedServices_Client, MMS_Object_Module_1::AdditionalSupportOptions);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::extendedServices_Server, extendedServices_Server, MMS_Object_Module_1::AdditionalSupportOptions);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::extendedParameters, extendedParameters, MMS_Object_Module_1::AdditionalCBBOptions);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::generalManagement, generalManagement, GeneralManagementParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::vMDSupport, vMDSupport, VMDSupportParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::domainManagement, domainManagement, DomainManagementParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::programInvocation, programInvocation, ProgramInvocationManagementParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::variableAccess, variableAccess, VariableAccessParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::dataParameters, dataParameters, DataParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::semaphoreManagement, semaphoreManagement, SemaphoreManagementParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::operatorCommunication, operatorCommunication, OperatorCommunicationParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::errors, errors, ErrorParameters);
    ITU_T_HOLDERH_DEFN(Service_and_Parameter_CBBs::fileManagement, fileManagement, FileManagementParameters);

    // sequence GeneralManagementParameters

    GeneralManagementParameters::GeneralManagementParameters() : localDetail_(), supportForTime_(), granularityOfTime_() {
    };

    GeneralManagementParameters::GeneralManagementParameters(const ISO_9506_MMS_1::MMSString& arg__localDetail,
            const SupportForTime_type& arg__supportForTime,
            const integer_type& arg__granularityOfTime) :
    localDetail_(arg__localDetail),
    supportForTime_(arg__supportForTime),
    granularityOfTime_(arg__granularityOfTime) {
    };

    GeneralManagementParameters::SupportForTime_type::SupportForTime_type() : timeOfDay_(), timeSequence_() {
    };

    GeneralManagementParameters::SupportForTime_type::SupportForTime_type(const bool& arg__timeOfDay,
            const bool& arg__timeSequence) :
    timeOfDay_(arg__timeOfDay),
    timeSequence_(arg__timeSequence) {
    };


    ITU_T_HOLDERH_DEFN(GeneralManagementParameters::SupportForTime_type::timeOfDay, timeOfDay, bool);
    ITU_T_HOLDERH_DEFN(GeneralManagementParameters::SupportForTime_type::timeSequence, timeSequence, bool);


    ITU_T_HOLDERH_DEFN(GeneralManagementParameters::localDetail, localDetail, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(GeneralManagementParameters::supportForTime, supportForTime, GeneralManagementParameters::SupportForTime_type);
    ITU_T_HOLDERH_DEFN(GeneralManagementParameters::granularityOfTime, granularityOfTime, integer_type);

    // sequence VMDSupportParameters

    VMDSupportParameters::VMDSupportParameters() : localDetail_(), extendedDerivation_() {
    };

    VMDSupportParameters::VMDSupportParameters(const ISO_9506_MMS_1::MMSString& arg__localDetail,
            const ISO_9506_MMS_1::MMSString& arg__extendedDerivation) :
    localDetail_(arg__localDetail),
    extendedDerivation_(arg__extendedDerivation) {
    };


    ITU_T_HOLDERH_DEFN(VMDSupportParameters::localDetail, localDetail, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(VMDSupportParameters::extendedDerivation, extendedDerivation, ISO_9506_MMS_1::MMSString);

    // sequence DomainManagementParameters

    DomainManagementParameters::DomainManagementParameters() : loadDataOctet_(), loadDataSyntax_(), maxUploads_() {
    };

    DomainManagementParameters::DomainManagementParameters(const ISO_9506_MMS_1::MMSString& arg__loadDataOctet,
            const LoadDataSyntax_type& arg__loadDataSyntax,
            const integer_type& arg__maxUploads) :
    loadDataOctet_(arg__loadDataOctet),
    loadDataSyntax_(arg__loadDataSyntax),
    maxUploads_(arg__maxUploads) {
    };


    ITU_T_HOLDERH_DEFN(DomainManagementParameters::loadDataOctet, loadDataOctet, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(DomainManagementParameters::loadDataSyntax, loadDataSyntax, DomainManagementParameters::LoadDataSyntax_type);
    ITU_T_HOLDERH_DEFN(DomainManagementParameters::maxUploads, maxUploads, integer_type);

    // sequence ProgramInvocationManagementParameters

    ProgramInvocationManagementParameters::ProgramInvocationManagementParameters() : executionArgMaxSize_(), executionArgParseRules_(), executionArgSyntaxes_(), programLoction_(), stepMode_() {
    };

    ProgramInvocationManagementParameters::ProgramInvocationManagementParameters(const integer_type& arg__executionArgMaxSize,
            const ISO_9506_MMS_1::MMSString& arg__executionArgParseRules,
            const ExecutionArgSyntaxes_type& arg__executionArgSyntaxes,
            const ISO_9506_MMS_1::MMSString& arg__programLoction,
            const bool& arg__stepMode) :
    executionArgMaxSize_(arg__executionArgMaxSize),
    executionArgParseRules_(arg__executionArgParseRules),
    executionArgSyntaxes_(arg__executionArgSyntaxes),
    programLoction_(arg__programLoction),
    stepMode_(arg__stepMode) {
    };


    ITU_T_HOLDERH_DEFN(ProgramInvocationManagementParameters::executionArgMaxSize, executionArgMaxSize, integer_type);
    ITU_T_HOLDERH_DEFN(ProgramInvocationManagementParameters::executionArgParseRules, executionArgParseRules, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(ProgramInvocationManagementParameters::executionArgSyntaxes, executionArgSyntaxes, ProgramInvocationManagementParameters::ExecutionArgSyntaxes_type);
    ITU_T_HOLDERH_DEFN(ProgramInvocationManagementParameters::programLoction, programLoction, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(ProgramInvocationManagementParameters::stepMode, stepMode, bool);

    // sequence VariableAccessParameters

    VariableAccessParameters::VariableAccessParameters() : uninterruptibleAccess_(), singleMode_(), unnamedMode_() {
    };

    VariableAccessParameters::VariableAccessParameters(const ISO_9506_MMS_1::MMSString& arg__uninterruptibleAccess,
            const bool& arg__singleMode,
            const bool& arg__unnamedMode) :
    uninterruptibleAccess_(arg__uninterruptibleAccess),
    singleMode_(arg__singleMode),
    unnamedMode_(arg__unnamedMode) {
    };


    ITU_T_HOLDERH_DEFN(VariableAccessParameters::uninterruptibleAccess, uninterruptibleAccess, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(VariableAccessParameters::singleMode, singleMode, bool);
    ITU_T_HOLDERH_DEFN(VariableAccessParameters::unnamedMode, unnamedMode, bool);

    // sequence DataParameters

    DataParameters::DataParameters() {
    };

    DataParameters::DataParameters(shared_ptr< integer_type> arg__bit_string,
            shared_ptr< integer_type> arg__integer,
            shared_ptr< integer_type> arg__unsignedV,
            shared_ptr< Floating_point_type> arg__floating_point,
            shared_ptr< integer_type> arg__octet_string,
            shared_ptr< integer_type> arg__visible_string,
            shared_ptr< bool> arg__binary_time,
            shared_ptr< integer_type> arg__bcd,
            shared_ptr< integer_type> arg__mmsString) :
    bit_string_(arg__bit_string),
    integer_(arg__integer),
    unsignedV_(arg__unsignedV),
    floating_point_(arg__floating_point),
    octet_string_(arg__octet_string),
    visible_string_(arg__visible_string),
    binary_time_(arg__binary_time),
    bcd_(arg__bcd),
    mmsString_(arg__mmsString) {
    };

    DataParameters::Floating_point_type::Floating_point_type() : total_(), exponent_() {
    };

    DataParameters::Floating_point_type::Floating_point_type(const integer_type& arg__total,
            const integer_type& arg__exponent) :
    total_(arg__total),
    exponent_(arg__exponent) {
    };


    ITU_T_HOLDERH_DEFN(DataParameters::Floating_point_type::total, total, integer_type);
    ITU_T_HOLDERH_DEFN(DataParameters::Floating_point_type::exponent, exponent, integer_type);


    ITU_T_OPTIONAL_DEFN(DataParameters::bit_string, bit_string, integer_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::integer, integer, integer_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::unsignedV, unsignedV, integer_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::floating_point, floating_point, DataParameters::Floating_point_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::octet_string, octet_string, integer_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::visible_string, visible_string, integer_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::binary_time, binary_time, bool);
    ITU_T_OPTIONAL_DEFN(DataParameters::bcd, bcd, integer_type);
    ITU_T_OPTIONAL_DEFN(DataParameters::mmsString, mmsString, integer_type);

    // sequence SemaphoreManagementParameters

    SemaphoreManagementParameters::SemaphoreManagementParameters() : algorithm_() {
    };

    SemaphoreManagementParameters::SemaphoreManagementParameters(const ISO_9506_MMS_1::MMSString& arg__algorithm) :
    algorithm_(arg__algorithm) {
    };


    ITU_T_HOLDERH_DEFN(SemaphoreManagementParameters::algorithm, algorithm, ISO_9506_MMS_1::MMSString);

    // sequence OperatorCommunicationParameters

    OperatorCommunicationParameters::OperatorCommunicationParameters() : input_time_out_() {
    };

    OperatorCommunicationParameters::OperatorCommunicationParameters(const integer_type& arg__input_time_out) :
    input_time_out_(arg__input_time_out) {
    };


    ITU_T_HOLDERH_DEFN(OperatorCommunicationParameters::input_time_out, input_time_out, integer_type);

    // sequence ErrorParameters

    ErrorParameters::ErrorParameters() : additionalCode_(), additionalDetial_() {
    };

    ErrorParameters::ErrorParameters(const ISO_9506_MMS_1::MMSString& arg__additionalCode,
            const AdditionalDetial_type& arg__additionalDetial) :
    additionalCode_(arg__additionalCode),
    additionalDetial_(arg__additionalDetial) {
    };

    ErrorParameters::AdditionalDetial_type::AdditionalDetial_type() : size_(), syntax_() {
    };

    ErrorParameters::AdditionalDetial_type::AdditionalDetial_type(const integer_type& arg__size,
            const ISO_9506_MMS_1::MMSString& arg__syntax) :
    size_(arg__size),
    syntax_(arg__syntax) {
    };


    ITU_T_HOLDERH_DEFN(ErrorParameters::AdditionalDetial_type::size, size, integer_type);
    ITU_T_HOLDERH_DEFN(ErrorParameters::AdditionalDetial_type::syntax, syntax, ISO_9506_MMS_1::MMSString);


    ITU_T_HOLDERH_DEFN(ErrorParameters::additionalCode, additionalCode, ISO_9506_MMS_1::MMSString);
    ITU_T_HOLDERH_DEFN(ErrorParameters::additionalDetial, additionalDetial, ErrorParameters::AdditionalDetial_type);

    // sequence FileManagementParameters

    FileManagementParameters::FileManagementParameters() : fileName_() {
    };

    FileManagementParameters::FileManagementParameters(const ISO_9506_MMS_1::MMSString& arg__fileName) :
    fileName_(arg__fileName) {
    };


    ITU_T_HOLDERH_DEFN(FileManagementParameters::fileName, fileName, ISO_9506_MMS_1::MMSString);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

