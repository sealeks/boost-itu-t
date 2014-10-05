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

    template<> void SCI_Information::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*partOne_, 0);
        ITU_T_IMPLICIT_TAG(*partTwo_, 1);
    }

    template<> void SCI_Information::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*partOne_, 0);
        ITU_T_IMPLICIT_TAG(*partTwo_, 1);
    }

    VMD_File& SCI_Information::partOne() {
        return *partOne_;
    }

    const VMD_File& SCI_Information::partOne() const {
        return *partOne_;
    }

    void SCI_Information::partOne(const VMD_File& vl) {
        partOne_ = vl;
    }

    void SCI_Information::partOne(boost::shared_ptr< VMD_File> vl) {
        partOne_ = vl;
    }

    Service_and_Parameter_CBBs& SCI_Information::partTwo() {
        return *partTwo_;
    }

    const Service_and_Parameter_CBBs& SCI_Information::partTwo() const {
        return *partTwo_;
    }

    void SCI_Information::partTwo(const Service_and_Parameter_CBBs& vl) {
        partTwo_ = vl;
    }

    void SCI_Information::partTwo(boost::shared_ptr< Service_and_Parameter_CBBs> vl) {
        partTwo_ = vl;
    }


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

    VMD_File::VMD_File(boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__executiveFunction,
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
            boost::shared_ptr< Selected_Program_Invocation_type> arg__selected_Program_Invocation) :
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

    void VMD_File::Selected_Program_Invocation_type::noneSelected(const null_type& vl) {
        set<null_type>(new null_type(vl), Selected_Program_Invocation_type_noneSelected);
    }

    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Selected_Program_Invocation_type_selectedProgram:
            {
                ITU_T_IMPLICIT_TAG(*value<Program_Invocation_instance > (false, Selected_Program_Invocation_type_selectedProgram), 26);
                break;
            }
            case Selected_Program_Invocation_type_noneSelected:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, Selected_Program_Invocation_type_noneSelected), 27);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 26:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Program_Invocation_instance > (true, Selected_Program_Invocation_type_selectedProgram), 26)) return;
                        else free();
                        break;
                    }
                    case 27:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, Selected_Program_Invocation_type_noneSelected), 27)) return;
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

    template<> void VMD_File::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*executiveFunction_, 0);
        ITU_T_EXPLICIT_TAG(*vendorName_, 1);
        ITU_T_EXPLICIT_TAG(*modelName_, 2);
        ITU_T_EXPLICIT_TAG(*revision_, 3);
        ITU_T_IMPLICIT_TAG(*abstractSyntaxes_, 4);
        ITU_T_IMPLICIT_TAG(*accessControl_, 5);
        ITU_T_IMPLICIT_TAG(*logicalStatus_, 6);
        ITU_T_IMPLICIT_TAG(*capabilities_, 7);
        ITU_T_IMPLICIT_TAG(*physicalStatus_, 8);
        ITU_T_IMPLICIT_TAG(*local_detail_, 9);
        ITU_T_IMPLICIT_TAG(*accessControlLists_, 10);
        ITU_T_IMPLICIT_TAG(*domains_, 11);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 12);
        ITU_T_IMPLICIT_TAG(*unitControls_, 13);
        ITU_T_IMPLICIT_TAG(*unnamedVariables_, 14);
        ITU_T_IMPLICIT_TAG(*namedVariables_, 15);
        ITU_T_IMPLICIT_TAG(*namedVariableLists_, 16);
        ITU_T_IMPLICIT_TAG(*namedTypes_, 17);
        ITU_T_IMPLICIT_TAG(*dataExchanges_, 18);
        ITU_T_IMPLICIT_TAG(*semaphores_, 19);
        ITU_T_IMPLICIT_TAG(*operatorStations_, 20);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 21);
        ITU_T_IMPLICIT_TAG(*eventActions_, 22);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 23);
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 24);
        ITU_T_IMPLICIT_TAG(*journals_, 25);
        ITU_T_EXTENTION;
        ITU_T_BIND_CHOICE(*selected_Program_Invocation_);
    }

    template<> void VMD_File::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*executiveFunction_, 0);
        ITU_T_EXPLICIT_TAG(*vendorName_, 1);
        ITU_T_EXPLICIT_TAG(*modelName_, 2);
        ITU_T_EXPLICIT_TAG(*revision_, 3);
        ITU_T_IMPLICIT_TAG(*abstractSyntaxes_, 4);
        ITU_T_IMPLICIT_TAG(*accessControl_, 5);
        ITU_T_IMPLICIT_TAG(*logicalStatus_, 6);
        ITU_T_IMPLICIT_TAG(*capabilities_, 7);
        ITU_T_IMPLICIT_TAG(*physicalStatus_, 8);
        ITU_T_IMPLICIT_TAG(*local_detail_, 9);
        ITU_T_IMPLICIT_TAG(*accessControlLists_, 10);
        ITU_T_IMPLICIT_TAG(*domains_, 11);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 12);
        ITU_T_IMPLICIT_TAG(*unitControls_, 13);
        ITU_T_IMPLICIT_TAG(*unnamedVariables_, 14);
        ITU_T_IMPLICIT_TAG(*namedVariables_, 15);
        ITU_T_IMPLICIT_TAG(*namedVariableLists_, 16);
        ITU_T_IMPLICIT_TAG(*namedTypes_, 17);
        ITU_T_IMPLICIT_TAG(*dataExchanges_, 18);
        ITU_T_IMPLICIT_TAG(*semaphores_, 19);
        ITU_T_IMPLICIT_TAG(*operatorStations_, 20);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 21);
        ITU_T_IMPLICIT_TAG(*eventActions_, 22);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 23);
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 24);
        ITU_T_IMPLICIT_TAG(*journals_, 25);
        ITU_T_EXTENTION;
        ITU_T_BIND_CHOICE(*selected_Program_Invocation_);
    }

    MMS_Environment_1::ApplicationReference& VMD_File::executiveFunction() {
        return *executiveFunction_;
    }

    const MMS_Environment_1::ApplicationReference& VMD_File::executiveFunction() const {
        return *executiveFunction_;
    }

    void VMD_File::executiveFunction(const MMS_Environment_1::ApplicationReference& vl) {
        executiveFunction_ = vl;
    }

    void VMD_File::executiveFunction(boost::shared_ptr< MMS_Environment_1::ApplicationReference> vl) {
        executiveFunction_ = vl;
    }

    ISO_9506_MMS_1::MMSString& VMD_File::vendorName() {
        return *vendorName_;
    }

    const ISO_9506_MMS_1::MMSString& VMD_File::vendorName() const {
        return *vendorName_;
    }

    void VMD_File::vendorName(const ISO_9506_MMS_1::MMSString& vl) {
        vendorName_ = vl;
    }

    void VMD_File::vendorName(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        vendorName_ = vl;
    }

    ISO_9506_MMS_1::MMSString& VMD_File::modelName() {
        return *modelName_;
    }

    const ISO_9506_MMS_1::MMSString& VMD_File::modelName() const {
        return *modelName_;
    }

    void VMD_File::modelName(const ISO_9506_MMS_1::MMSString& vl) {
        modelName_ = vl;
    }

    void VMD_File::modelName(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        modelName_ = vl;
    }

    ISO_9506_MMS_1::MMSString& VMD_File::revision() {
        return *revision_;
    }

    const ISO_9506_MMS_1::MMSString& VMD_File::revision() const {
        return *revision_;
    }

    void VMD_File::revision(const ISO_9506_MMS_1::MMSString& vl) {
        revision_ = vl;
    }

    void VMD_File::revision(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        revision_ = vl;
    }

    oid_type& VMD_File::abstractSyntaxes() {
        return *abstractSyntaxes_;
    }

    const oid_type& VMD_File::abstractSyntaxes() const {
        return *abstractSyntaxes_;
    }

    void VMD_File::abstractSyntaxes(const oid_type& vl) {
        abstractSyntaxes_ = vl;
    }

    void VMD_File::abstractSyntaxes(boost::shared_ptr< oid_type> vl) {
        abstractSyntaxes_ = vl;
    }

    Access_Control_List_instance& VMD_File::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& VMD_File::accessControl() const {
        return *accessControl_;
    }

    void VMD_File::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void VMD_File::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    MMS_Object_Module_1::LogicalStatus& VMD_File::logicalStatus() {
        return *logicalStatus_;
    }

    const MMS_Object_Module_1::LogicalStatus& VMD_File::logicalStatus() const {
        return *logicalStatus_;
    }

    void VMD_File::logicalStatus(const MMS_Object_Module_1::LogicalStatus& vl) {
        logicalStatus_ = vl;
    }

    void VMD_File::logicalStatus(boost::shared_ptr< MMS_Object_Module_1::LogicalStatus> vl) {
        logicalStatus_ = vl;
    }

    VMD_File::Capabilities_type& VMD_File::capabilities() {
        return *capabilities_;
    }

    const VMD_File::Capabilities_type& VMD_File::capabilities() const {
        return *capabilities_;
    }

    void VMD_File::capabilities(const Capabilities_type& vl) {
        capabilities_ = vl;
    }

    void VMD_File::capabilities(boost::shared_ptr< Capabilities_type> vl) {
        capabilities_ = vl;
    }

    MMS_Object_Module_1::PhysicalStatus& VMD_File::physicalStatus() {
        return *physicalStatus_;
    }

    const MMS_Object_Module_1::PhysicalStatus& VMD_File::physicalStatus() const {
        return *physicalStatus_;
    }

    void VMD_File::physicalStatus(const MMS_Object_Module_1::PhysicalStatus& vl) {
        physicalStatus_ = vl;
    }

    void VMD_File::physicalStatus(boost::shared_ptr< MMS_Object_Module_1::PhysicalStatus> vl) {
        physicalStatus_ = vl;
    }

    bitstring_type& VMD_File::local_detail() {
        return *local_detail_;
    }

    const bitstring_type& VMD_File::local_detail() const {
        return *local_detail_;
    }

    void VMD_File::local_detail(const bitstring_type& vl) {
        local_detail_ = vl;
    }

    void VMD_File::local_detail(boost::shared_ptr< bitstring_type> vl) {
        local_detail_ = vl;
    }

    VMD_File::AccessControlLists_type& VMD_File::accessControlLists() {
        return *accessControlLists_;
    }

    const VMD_File::AccessControlLists_type& VMD_File::accessControlLists() const {
        return *accessControlLists_;
    }

    void VMD_File::accessControlLists(const AccessControlLists_type& vl) {
        accessControlLists_ = vl;
    }

    void VMD_File::accessControlLists(boost::shared_ptr< AccessControlLists_type> vl) {
        accessControlLists_ = vl;
    }

    VMD_File::Domains_type& VMD_File::domains() {
        return *domains_;
    }

    const VMD_File::Domains_type& VMD_File::domains() const {
        return *domains_;
    }

    void VMD_File::domains(const Domains_type& vl) {
        domains_ = vl;
    }

    void VMD_File::domains(boost::shared_ptr< Domains_type> vl) {
        domains_ = vl;
    }

    VMD_File::ProgramInvocations_type& VMD_File::programInvocations() {
        return *programInvocations_;
    }

    const VMD_File::ProgramInvocations_type& VMD_File::programInvocations() const {
        return *programInvocations_;
    }

    void VMD_File::programInvocations(const ProgramInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void VMD_File::programInvocations(boost::shared_ptr< ProgramInvocations_type> vl) {
        programInvocations_ = vl;
    }

    VMD_File::UnitControls_type& VMD_File::unitControls() {
        return *unitControls_;
    }

    const VMD_File::UnitControls_type& VMD_File::unitControls() const {
        return *unitControls_;
    }

    void VMD_File::unitControls(const UnitControls_type& vl) {
        unitControls_ = vl;
    }

    void VMD_File::unitControls(boost::shared_ptr< UnitControls_type> vl) {
        unitControls_ = vl;
    }

    VMD_File::UnnamedVariables_type& VMD_File::unnamedVariables() {
        return *unnamedVariables_;
    }

    const VMD_File::UnnamedVariables_type& VMD_File::unnamedVariables() const {
        return *unnamedVariables_;
    }

    void VMD_File::unnamedVariables(const UnnamedVariables_type& vl) {
        unnamedVariables_ = vl;
    }

    void VMD_File::unnamedVariables(boost::shared_ptr< UnnamedVariables_type> vl) {
        unnamedVariables_ = vl;
    }

    VMD_File::NamedVariables_type& VMD_File::namedVariables() {
        return *namedVariables_;
    }

    const VMD_File::NamedVariables_type& VMD_File::namedVariables() const {
        return *namedVariables_;
    }

    void VMD_File::namedVariables(const NamedVariables_type& vl) {
        namedVariables_ = vl;
    }

    void VMD_File::namedVariables(boost::shared_ptr< NamedVariables_type> vl) {
        namedVariables_ = vl;
    }

    VMD_File::NamedVariableLists_type& VMD_File::namedVariableLists() {
        return *namedVariableLists_;
    }

    const VMD_File::NamedVariableLists_type& VMD_File::namedVariableLists() const {
        return *namedVariableLists_;
    }

    void VMD_File::namedVariableLists(const NamedVariableLists_type& vl) {
        namedVariableLists_ = vl;
    }

    void VMD_File::namedVariableLists(boost::shared_ptr< NamedVariableLists_type> vl) {
        namedVariableLists_ = vl;
    }

    VMD_File::NamedTypes_type& VMD_File::namedTypes() {
        return *namedTypes_;
    }

    const VMD_File::NamedTypes_type& VMD_File::namedTypes() const {
        return *namedTypes_;
    }

    void VMD_File::namedTypes(const NamedTypes_type& vl) {
        namedTypes_ = vl;
    }

    void VMD_File::namedTypes(boost::shared_ptr< NamedTypes_type> vl) {
        namedTypes_ = vl;
    }

    VMD_File::DataExchanges_type& VMD_File::dataExchanges() {
        return *dataExchanges_;
    }

    const VMD_File::DataExchanges_type& VMD_File::dataExchanges() const {
        return *dataExchanges_;
    }

    void VMD_File::dataExchanges(const DataExchanges_type& vl) {
        dataExchanges_ = vl;
    }

    void VMD_File::dataExchanges(boost::shared_ptr< DataExchanges_type> vl) {
        dataExchanges_ = vl;
    }

    VMD_File::Semaphores_type& VMD_File::semaphores() {
        return *semaphores_;
    }

    const VMD_File::Semaphores_type& VMD_File::semaphores() const {
        return *semaphores_;
    }

    void VMD_File::semaphores(const Semaphores_type& vl) {
        semaphores_ = vl;
    }

    void VMD_File::semaphores(boost::shared_ptr< Semaphores_type> vl) {
        semaphores_ = vl;
    }

    VMD_File::OperatorStations_type& VMD_File::operatorStations() {
        return *operatorStations_;
    }

    const VMD_File::OperatorStations_type& VMD_File::operatorStations() const {
        return *operatorStations_;
    }

    void VMD_File::operatorStations(const OperatorStations_type& vl) {
        operatorStations_ = vl;
    }

    void VMD_File::operatorStations(boost::shared_ptr< OperatorStations_type> vl) {
        operatorStations_ = vl;
    }

    VMD_File::EventConditions_type& VMD_File::eventConditions() {
        return *eventConditions_;
    }

    const VMD_File::EventConditions_type& VMD_File::eventConditions() const {
        return *eventConditions_;
    }

    void VMD_File::eventConditions(const EventConditions_type& vl) {
        eventConditions_ = vl;
    }

    void VMD_File::eventConditions(boost::shared_ptr< EventConditions_type> vl) {
        eventConditions_ = vl;
    }

    VMD_File::EventActions_type& VMD_File::eventActions() {
        return *eventActions_;
    }

    const VMD_File::EventActions_type& VMD_File::eventActions() const {
        return *eventActions_;
    }

    void VMD_File::eventActions(const EventActions_type& vl) {
        eventActions_ = vl;
    }

    void VMD_File::eventActions(boost::shared_ptr< EventActions_type> vl) {
        eventActions_ = vl;
    }

    VMD_File::EventEnrollments_type& VMD_File::eventEnrollments() {
        return *eventEnrollments_;
    }

    const VMD_File::EventEnrollments_type& VMD_File::eventEnrollments() const {
        return *eventEnrollments_;
    }

    void VMD_File::eventEnrollments(const EventEnrollments_type& vl) {
        eventEnrollments_ = vl;
    }

    void VMD_File::eventEnrollments(boost::shared_ptr< EventEnrollments_type> vl) {
        eventEnrollments_ = vl;
    }

    VMD_File::EventConditionLists_type& VMD_File::eventConditionLists() {
        return *eventConditionLists_;
    }

    const VMD_File::EventConditionLists_type& VMD_File::eventConditionLists() const {
        return *eventConditionLists_;
    }

    void VMD_File::eventConditionLists(const EventConditionLists_type& vl) {
        eventConditionLists_ = vl;
    }

    void VMD_File::eventConditionLists(boost::shared_ptr< EventConditionLists_type> vl) {
        eventConditionLists_ = vl;
    }

    VMD_File::Journals_type& VMD_File::journals() {
        return *journals_;
    }

    const VMD_File::Journals_type& VMD_File::journals() const {
        return *journals_;
    }

    void VMD_File::journals(const Journals_type& vl) {
        journals_ = vl;
    }

    void VMD_File::journals(boost::shared_ptr< Journals_type> vl) {
        journals_ = vl;
    }

    boost::shared_ptr<VMD_File::Selected_Program_Invocation_type> VMD_File::selected_Program_Invocation__new() {
        return selected_Program_Invocation_ = boost::shared_ptr<Selected_Program_Invocation_type>(new Selected_Program_Invocation_type());
    }

    void VMD_File::selected_Program_Invocation(const Selected_Program_Invocation_type& vl) {
        selected_Program_Invocation_ = boost::shared_ptr<Selected_Program_Invocation_type>(new Selected_Program_Invocation_type(vl));
    }


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

    Access_Control_List_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
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
            boost::shared_ptr< EventConditionLists_type> arg__eventConditionLists) :
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

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(readAccessCondition_, 4);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 5);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 6);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 7);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 8);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 9);
        ITU_T_CHOICE_TAG(editAccessCondition_, 10);
        ITU_T_IMPLICIT_TAG(*accessControlLists_, 11);
        ITU_T_IMPLICIT_TAG(*domains_, 12);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 13);
        ITU_T_IMPLICIT_TAG(*unitControls_, 14);
        ITU_T_IMPLICIT_TAG(*unnamedVariables_, 15);
        ITU_T_IMPLICIT_TAG(*namedVariables_, 16);
        ITU_T_IMPLICIT_TAG(*namedVariableLists_, 17);
        ITU_T_IMPLICIT_TAG(*namedTypes_, 18);
        ITU_T_IMPLICIT_TAG(*dataExchanges_, 19);
        ITU_T_IMPLICIT_TAG(*semaphores_, 20);
        ITU_T_IMPLICIT_TAG(*operatorStations_, 21);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 22);
        ITU_T_IMPLICIT_TAG(*eventActions_, 23);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 24);
        ITU_T_IMPLICIT_TAG(*journals_, 25);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 26);
    }

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(readAccessCondition_, 4);
        ITU_T_CHOICE_TAG(storeAccessCondition_, 5);
        ITU_T_CHOICE_TAG(writeAccessCondition_, 6);
        ITU_T_CHOICE_TAG(loadAccessCondition_, 7);
        ITU_T_CHOICE_TAG(executeAccessCondition_, 8);
        ITU_T_CHOICE_TAG(deleteAccessCondition_, 9);
        ITU_T_CHOICE_TAG(editAccessCondition_, 10);
        ITU_T_IMPLICIT_TAG(*accessControlLists_, 11);
        ITU_T_IMPLICIT_TAG(*domains_, 12);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 13);
        ITU_T_IMPLICIT_TAG(*unitControls_, 14);
        ITU_T_IMPLICIT_TAG(*unnamedVariables_, 15);
        ITU_T_IMPLICIT_TAG(*namedVariables_, 16);
        ITU_T_IMPLICIT_TAG(*namedVariableLists_, 17);
        ITU_T_IMPLICIT_TAG(*namedTypes_, 18);
        ITU_T_IMPLICIT_TAG(*dataExchanges_, 19);
        ITU_T_IMPLICIT_TAG(*semaphores_, 20);
        ITU_T_IMPLICIT_TAG(*operatorStations_, 21);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 22);
        ITU_T_IMPLICIT_TAG(*eventActions_, 23);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 24);
        ITU_T_IMPLICIT_TAG(*journals_, 25);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 26);
    }

    Access_Control_List_instance& Access_Control_List_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Access_Control_List_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::readAccessCondition__new() {
        return readAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::readAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        readAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::storeAccessCondition__new() {
        return storeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::storeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        storeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::writeAccessCondition__new() {
        return writeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::writeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        writeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::loadAccessCondition__new() {
        return loadAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::loadAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        loadAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::executeAccessCondition__new() {
        return executeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::executeAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        executeAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::deleteAccessCondition__new() {
        return deleteAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::deleteAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        deleteAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AccessCondition> Access_Control_List_instance::Definition_type::Details_type::editAccessCondition__new() {
        return editAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition());
    }

    void Access_Control_List_instance::Definition_type::Details_type::editAccessCondition(const MMS_Object_Module_1::AccessCondition& vl) {
        editAccessCondition_ = boost::shared_ptr<MMS_Object_Module_1::AccessCondition>(new MMS_Object_Module_1::AccessCondition(vl));
    }

    Access_Control_List_instance::Definition_type::Details_type::AccessControlLists_type& Access_Control_List_instance::Definition_type::Details_type::accessControlLists() {
        return *accessControlLists_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::AccessControlLists_type& Access_Control_List_instance::Definition_type::Details_type::accessControlLists() const {
        return *accessControlLists_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::accessControlLists(const AccessControlLists_type& vl) {
        accessControlLists_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::accessControlLists(boost::shared_ptr< AccessControlLists_type> vl) {
        accessControlLists_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::Domains_type& Access_Control_List_instance::Definition_type::Details_type::domains() {
        return *domains_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::Domains_type& Access_Control_List_instance::Definition_type::Details_type::domains() const {
        return *domains_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::domains(const Domains_type& vl) {
        domains_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::domains(boost::shared_ptr< Domains_type> vl) {
        domains_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::ProgramInvocations_type& Access_Control_List_instance::Definition_type::Details_type::programInvocations() {
        return *programInvocations_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::ProgramInvocations_type& Access_Control_List_instance::Definition_type::Details_type::programInvocations() const {
        return *programInvocations_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::programInvocations(const ProgramInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::programInvocations(boost::shared_ptr< ProgramInvocations_type> vl) {
        programInvocations_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::UnitControls_type& Access_Control_List_instance::Definition_type::Details_type::unitControls() {
        return *unitControls_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::UnitControls_type& Access_Control_List_instance::Definition_type::Details_type::unitControls() const {
        return *unitControls_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::unitControls(const UnitControls_type& vl) {
        unitControls_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::unitControls(boost::shared_ptr< UnitControls_type> vl) {
        unitControls_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::UnnamedVariables_type& Access_Control_List_instance::Definition_type::Details_type::unnamedVariables() {
        return *unnamedVariables_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::UnnamedVariables_type& Access_Control_List_instance::Definition_type::Details_type::unnamedVariables() const {
        return *unnamedVariables_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::unnamedVariables(const UnnamedVariables_type& vl) {
        unnamedVariables_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::unnamedVariables(boost::shared_ptr< UnnamedVariables_type> vl) {
        unnamedVariables_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::NamedVariables_type& Access_Control_List_instance::Definition_type::Details_type::namedVariables() {
        return *namedVariables_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::NamedVariables_type& Access_Control_List_instance::Definition_type::Details_type::namedVariables() const {
        return *namedVariables_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::namedVariables(const NamedVariables_type& vl) {
        namedVariables_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::namedVariables(boost::shared_ptr< NamedVariables_type> vl) {
        namedVariables_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::NamedVariableLists_type& Access_Control_List_instance::Definition_type::Details_type::namedVariableLists() {
        return *namedVariableLists_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::NamedVariableLists_type& Access_Control_List_instance::Definition_type::Details_type::namedVariableLists() const {
        return *namedVariableLists_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::namedVariableLists(const NamedVariableLists_type& vl) {
        namedVariableLists_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::namedVariableLists(boost::shared_ptr< NamedVariableLists_type> vl) {
        namedVariableLists_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::NamedTypes_type& Access_Control_List_instance::Definition_type::Details_type::namedTypes() {
        return *namedTypes_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::NamedTypes_type& Access_Control_List_instance::Definition_type::Details_type::namedTypes() const {
        return *namedTypes_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::namedTypes(const NamedTypes_type& vl) {
        namedTypes_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::namedTypes(boost::shared_ptr< NamedTypes_type> vl) {
        namedTypes_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::DataExchanges_type& Access_Control_List_instance::Definition_type::Details_type::dataExchanges() {
        return *dataExchanges_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::DataExchanges_type& Access_Control_List_instance::Definition_type::Details_type::dataExchanges() const {
        return *dataExchanges_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::dataExchanges(const DataExchanges_type& vl) {
        dataExchanges_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::dataExchanges(boost::shared_ptr< DataExchanges_type> vl) {
        dataExchanges_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::Semaphores_type& Access_Control_List_instance::Definition_type::Details_type::semaphores() {
        return *semaphores_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::Semaphores_type& Access_Control_List_instance::Definition_type::Details_type::semaphores() const {
        return *semaphores_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::semaphores(const Semaphores_type& vl) {
        semaphores_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::semaphores(boost::shared_ptr< Semaphores_type> vl) {
        semaphores_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::OperatorStations_type& Access_Control_List_instance::Definition_type::Details_type::operatorStations() {
        return *operatorStations_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::OperatorStations_type& Access_Control_List_instance::Definition_type::Details_type::operatorStations() const {
        return *operatorStations_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::operatorStations(const OperatorStations_type& vl) {
        operatorStations_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::operatorStations(boost::shared_ptr< OperatorStations_type> vl) {
        operatorStations_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::EventConditions_type& Access_Control_List_instance::Definition_type::Details_type::eventConditions() {
        return *eventConditions_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::EventConditions_type& Access_Control_List_instance::Definition_type::Details_type::eventConditions() const {
        return *eventConditions_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventConditions(const EventConditions_type& vl) {
        eventConditions_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventConditions(boost::shared_ptr< EventConditions_type> vl) {
        eventConditions_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::EventActions_type& Access_Control_List_instance::Definition_type::Details_type::eventActions() {
        return *eventActions_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::EventActions_type& Access_Control_List_instance::Definition_type::Details_type::eventActions() const {
        return *eventActions_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventActions(const EventActions_type& vl) {
        eventActions_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventActions(boost::shared_ptr< EventActions_type> vl) {
        eventActions_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::EventEnrollments_type& Access_Control_List_instance::Definition_type::Details_type::eventEnrollments() {
        return *eventEnrollments_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::EventEnrollments_type& Access_Control_List_instance::Definition_type::Details_type::eventEnrollments() const {
        return *eventEnrollments_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventEnrollments(const EventEnrollments_type& vl) {
        eventEnrollments_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventEnrollments(boost::shared_ptr< EventEnrollments_type> vl) {
        eventEnrollments_ = vl;
    }

    Access_Control_List_instance::Definition_type::Details_type::Journals_type& Access_Control_List_instance::Definition_type::Details_type::journals() {
        return *journals_;
    }

    const Access_Control_List_instance::Definition_type::Details_type::Journals_type& Access_Control_List_instance::Definition_type::Details_type::journals() const {
        return *journals_;
    }

    void Access_Control_List_instance::Definition_type::Details_type::journals(const Journals_type& vl) {
        journals_ = vl;
    }

    void Access_Control_List_instance::Definition_type::Details_type::journals(boost::shared_ptr< Journals_type> vl) {
        journals_ = vl;
    }

    boost::shared_ptr<Access_Control_List_instance::Definition_type::Details_type::EventConditionLists_type> Access_Control_List_instance::Definition_type::Details_type::eventConditionLists__new() {
        return eventConditionLists_ = boost::shared_ptr<EventConditionLists_type>(new EventConditionLists_type());
    }

    void Access_Control_List_instance::Definition_type::Details_type::eventConditionLists(const EventConditionLists_type& vl) {
        eventConditionLists_ = boost::shared_ptr<EventConditionLists_type>(new EventConditionLists_type(vl));
    }

    void Access_Control_List_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Access_Control_List_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Access_Control_List_instance::name() const {
        return *name_;
    }

    void Access_Control_List_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Access_Control_List_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Access_Control_List_instance::Definition_type& Access_Control_List_instance::definition() {
        return *definition_;
    }

    const Access_Control_List_instance::Definition_type& Access_Control_List_instance::definition() const {
        return *definition_;
    }

    void Access_Control_List_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Access_Control_List_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*capabilities_, 3);
        ITU_T_IMPLICIT_TAG(*state_, 4);
        ITU_T_IMPLICIT_TAG(*accessControl_, 5);
        ITU_T_IMPLICIT_TAG(*sharable_, 6);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 7);
        ITU_T_IMPLICIT_TAG(*namedVariables_, 8);
        ITU_T_IMPLICIT_TAG(*namedVariableLists_, 9);
        ITU_T_IMPLICIT_TAG(*namedTypes_, 10);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 11);
        ITU_T_IMPLICIT_TAG(*eventActions_, 12);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 13);
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 14);
    }

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*capabilities_, 3);
        ITU_T_IMPLICIT_TAG(*state_, 4);
        ITU_T_IMPLICIT_TAG(*accessControl_, 5);
        ITU_T_IMPLICIT_TAG(*sharable_, 6);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 7);
        ITU_T_IMPLICIT_TAG(*namedVariables_, 8);
        ITU_T_IMPLICIT_TAG(*namedVariableLists_, 9);
        ITU_T_IMPLICIT_TAG(*namedTypes_, 10);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 11);
        ITU_T_IMPLICIT_TAG(*eventActions_, 12);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 13);
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 14);
    }

    Domain_instance::Definition_type::Details_type::Capabilities_type& Domain_instance::Definition_type::Details_type::capabilities() {
        return *capabilities_;
    }

    const Domain_instance::Definition_type::Details_type::Capabilities_type& Domain_instance::Definition_type::Details_type::capabilities() const {
        return *capabilities_;
    }

    void Domain_instance::Definition_type::Details_type::capabilities(const Capabilities_type& vl) {
        capabilities_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::capabilities(boost::shared_ptr< Capabilities_type> vl) {
        capabilities_ = vl;
    }

    MMS_Object_Module_1::DomainState& Domain_instance::Definition_type::Details_type::state() {
        return *state_;
    }

    const MMS_Object_Module_1::DomainState& Domain_instance::Definition_type::Details_type::state() const {
        return *state_;
    }

    void Domain_instance::Definition_type::Details_type::state(const MMS_Object_Module_1::DomainState& vl) {
        state_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::state(boost::shared_ptr< MMS_Object_Module_1::DomainState> vl) {
        state_ = vl;
    }

    Access_Control_List_instance& Domain_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Domain_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Domain_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    bool& Domain_instance::Definition_type::Details_type::sharable() {
        return *sharable_;
    }

    const bool& Domain_instance::Definition_type::Details_type::sharable() const {
        return *sharable_;
    }

    void Domain_instance::Definition_type::Details_type::sharable(const bool& vl) {
        sharable_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::sharable(boost::shared_ptr< bool> vl) {
        sharable_ = vl;
    }

    Domain_instance::Definition_type::Details_type::ProgramInvocations_type& Domain_instance::Definition_type::Details_type::programInvocations() {
        return *programInvocations_;
    }

    const Domain_instance::Definition_type::Details_type::ProgramInvocations_type& Domain_instance::Definition_type::Details_type::programInvocations() const {
        return *programInvocations_;
    }

    void Domain_instance::Definition_type::Details_type::programInvocations(const ProgramInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::programInvocations(boost::shared_ptr< ProgramInvocations_type> vl) {
        programInvocations_ = vl;
    }

    Domain_instance::Definition_type::Details_type::NamedVariables_type& Domain_instance::Definition_type::Details_type::namedVariables() {
        return *namedVariables_;
    }

    const Domain_instance::Definition_type::Details_type::NamedVariables_type& Domain_instance::Definition_type::Details_type::namedVariables() const {
        return *namedVariables_;
    }

    void Domain_instance::Definition_type::Details_type::namedVariables(const NamedVariables_type& vl) {
        namedVariables_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::namedVariables(boost::shared_ptr< NamedVariables_type> vl) {
        namedVariables_ = vl;
    }

    Domain_instance::Definition_type::Details_type::NamedVariableLists_type& Domain_instance::Definition_type::Details_type::namedVariableLists() {
        return *namedVariableLists_;
    }

    const Domain_instance::Definition_type::Details_type::NamedVariableLists_type& Domain_instance::Definition_type::Details_type::namedVariableLists() const {
        return *namedVariableLists_;
    }

    void Domain_instance::Definition_type::Details_type::namedVariableLists(const NamedVariableLists_type& vl) {
        namedVariableLists_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::namedVariableLists(boost::shared_ptr< NamedVariableLists_type> vl) {
        namedVariableLists_ = vl;
    }

    Domain_instance::Definition_type::Details_type::NamedTypes_type& Domain_instance::Definition_type::Details_type::namedTypes() {
        return *namedTypes_;
    }

    const Domain_instance::Definition_type::Details_type::NamedTypes_type& Domain_instance::Definition_type::Details_type::namedTypes() const {
        return *namedTypes_;
    }

    void Domain_instance::Definition_type::Details_type::namedTypes(const NamedTypes_type& vl) {
        namedTypes_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::namedTypes(boost::shared_ptr< NamedTypes_type> vl) {
        namedTypes_ = vl;
    }

    Domain_instance::Definition_type::Details_type::EventConditions_type& Domain_instance::Definition_type::Details_type::eventConditions() {
        return *eventConditions_;
    }

    const Domain_instance::Definition_type::Details_type::EventConditions_type& Domain_instance::Definition_type::Details_type::eventConditions() const {
        return *eventConditions_;
    }

    void Domain_instance::Definition_type::Details_type::eventConditions(const EventConditions_type& vl) {
        eventConditions_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::eventConditions(boost::shared_ptr< EventConditions_type> vl) {
        eventConditions_ = vl;
    }

    Domain_instance::Definition_type::Details_type::EventActions_type& Domain_instance::Definition_type::Details_type::eventActions() {
        return *eventActions_;
    }

    const Domain_instance::Definition_type::Details_type::EventActions_type& Domain_instance::Definition_type::Details_type::eventActions() const {
        return *eventActions_;
    }

    void Domain_instance::Definition_type::Details_type::eventActions(const EventActions_type& vl) {
        eventActions_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::eventActions(boost::shared_ptr< EventActions_type> vl) {
        eventActions_ = vl;
    }

    Domain_instance::Definition_type::Details_type::EventEnrollments_type& Domain_instance::Definition_type::Details_type::eventEnrollments() {
        return *eventEnrollments_;
    }

    const Domain_instance::Definition_type::Details_type::EventEnrollments_type& Domain_instance::Definition_type::Details_type::eventEnrollments() const {
        return *eventEnrollments_;
    }

    void Domain_instance::Definition_type::Details_type::eventEnrollments(const EventEnrollments_type& vl) {
        eventEnrollments_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::eventEnrollments(boost::shared_ptr< EventEnrollments_type> vl) {
        eventEnrollments_ = vl;
    }

    Domain_instance::Definition_type::Details_type::EventConditionLists_type& Domain_instance::Definition_type::Details_type::eventConditionLists() {
        return *eventConditionLists_;
    }

    const Domain_instance::Definition_type::Details_type::EventConditionLists_type& Domain_instance::Definition_type::Details_type::eventConditionLists() const {
        return *eventConditionLists_;
    }

    void Domain_instance::Definition_type::Details_type::eventConditionLists(const EventConditionLists_type& vl) {
        eventConditionLists_ = vl;
    }

    void Domain_instance::Definition_type::Details_type::eventConditionLists(boost::shared_ptr< EventConditionLists_type> vl) {
        eventConditionLists_ = vl;
    }

    void Domain_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Domain_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Domain_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Domain_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Domain_instance::name() const {
        return *name_;
    }

    void Domain_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Domain_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Domain_instance::Definition_type& Domain_instance::definition() {
        return *definition_;
    }

    const Domain_instance::Definition_type& Domain_instance::definition() const {
        return *definition_;
    }

    void Domain_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Domain_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    Program_Invocation_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> arg__programInvocationState,
            boost::shared_ptr< Domains_type> arg__domains,
            boost::shared_ptr< AccessControl_type> arg__accessControl,
            boost::shared_ptr< bool> arg__reusable,
            boost::shared_ptr< bool> arg__monitor,
            boost::shared_ptr< EventCondition_type> arg__eventCondition,
            boost::shared_ptr< EventAction_type> arg__eventAction,
            boost::shared_ptr< EventEnrollment_type> arg__eventEnrollment,
            boost::shared_ptr< ISO_9506_MMS_1::MMSString> arg__executionArgument,
            boost::shared_ptr< MMS_Object_Module_1::Control_State> arg__control,
            boost::shared_ptr< Program_Invocation_instance> arg__controlling_Program_Invocation,
            boost::shared_ptr< Controlled_Program_Invocations_type> arg__controlled_Program_Invocations) :
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

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationState_, 3);
        ITU_T_IMPLICIT_TAG(*domains_, 4);
        ITU_T_IMPLICIT_TAG(*accessControl_, 5);
        ITU_T_IMPLICIT_TAG(*reusable_, 6);
        ITU_T_IMPLICIT_TAG(*monitor_, 7);
        ITU_T_IMPLICIT_TAG(eventCondition_, 8);
        ITU_T_IMPLICIT_TAG(eventAction_, 9);
        ITU_T_IMPLICIT_TAG(eventEnrollment_, 10);
        ITU_T_EXPLICIT_TAG(*executionArgument_, 11);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(*control_, 12);
        ITU_T_IMPLICIT_TAG(*controlling_Program_Invocation_, 13);
        ITU_T_IMPLICIT_TAG(controlled_Program_Invocations_, 14);
    }

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*programInvocationState_, 3);
        ITU_T_IMPLICIT_TAG(*domains_, 4);
        ITU_T_IMPLICIT_TAG(*accessControl_, 5);
        ITU_T_IMPLICIT_TAG(*reusable_, 6);
        ITU_T_IMPLICIT_TAG(*monitor_, 7);
        ITU_T_IMPLICIT_TAG(eventCondition_, 8);
        ITU_T_IMPLICIT_TAG(eventAction_, 9);
        ITU_T_IMPLICIT_TAG(eventEnrollment_, 10);
        ITU_T_EXPLICIT_TAG(*executionArgument_, 11);
        ITU_T_EXTENTION;
        ITU_T_IMPLICIT_TAG(*control_, 12);
        ITU_T_IMPLICIT_TAG(*controlling_Program_Invocation_, 13);
        ITU_T_IMPLICIT_TAG(controlled_Program_Invocations_, 14);
    }

    MMS_Object_Module_1::ProgramInvocationState& Program_Invocation_instance::Definition_type::Details_type::programInvocationState() {
        return *programInvocationState_;
    }

    const MMS_Object_Module_1::ProgramInvocationState& Program_Invocation_instance::Definition_type::Details_type::programInvocationState() const {
        return *programInvocationState_;
    }

    void Program_Invocation_instance::Definition_type::Details_type::programInvocationState(const MMS_Object_Module_1::ProgramInvocationState& vl) {
        programInvocationState_ = vl;
    }

    void Program_Invocation_instance::Definition_type::Details_type::programInvocationState(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> vl) {
        programInvocationState_ = vl;
    }

    Program_Invocation_instance::Definition_type::Details_type::Domains_type& Program_Invocation_instance::Definition_type::Details_type::domains() {
        return *domains_;
    }

    const Program_Invocation_instance::Definition_type::Details_type::Domains_type& Program_Invocation_instance::Definition_type::Details_type::domains() const {
        return *domains_;
    }

    void Program_Invocation_instance::Definition_type::Details_type::domains(const Domains_type& vl) {
        domains_ = vl;
    }

    void Program_Invocation_instance::Definition_type::Details_type::domains(boost::shared_ptr< Domains_type> vl) {
        domains_ = vl;
    }

    Program_Invocation_instance::Definition_type::Details_type::AccessControl_type& Program_Invocation_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Program_Invocation_instance::Definition_type::Details_type::AccessControl_type& Program_Invocation_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Program_Invocation_instance::Definition_type::Details_type::accessControl(const AccessControl_type& vl) {
        accessControl_ = vl;
    }

    void Program_Invocation_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< AccessControl_type> vl) {
        accessControl_ = vl;
    }

    bool& Program_Invocation_instance::Definition_type::Details_type::reusable() {
        return *reusable_;
    }

    const bool& Program_Invocation_instance::Definition_type::Details_type::reusable() const {
        return *reusable_;
    }

    void Program_Invocation_instance::Definition_type::Details_type::reusable(const bool& vl) {
        reusable_ = vl;
    }

    void Program_Invocation_instance::Definition_type::Details_type::reusable(boost::shared_ptr< bool> vl) {
        reusable_ = vl;
    }

    bool& Program_Invocation_instance::Definition_type::Details_type::monitor() {
        return *monitor_;
    }

    const bool& Program_Invocation_instance::Definition_type::Details_type::monitor() const {
        return *monitor_;
    }

    void Program_Invocation_instance::Definition_type::Details_type::monitor(const bool& vl) {
        monitor_ = vl;
    }

    void Program_Invocation_instance::Definition_type::Details_type::monitor(boost::shared_ptr< bool> vl) {
        monitor_ = vl;
    }

    boost::shared_ptr<Program_Invocation_instance::Definition_type::Details_type::EventCondition_type> Program_Invocation_instance::Definition_type::Details_type::eventCondition__new() {
        return eventCondition_ = boost::shared_ptr<EventCondition_type>(new EventCondition_type());
    }

    void Program_Invocation_instance::Definition_type::Details_type::eventCondition(const EventCondition_type& vl) {
        eventCondition_ = boost::shared_ptr<EventCondition_type>(new EventCondition_type(vl));
    }

    boost::shared_ptr<Program_Invocation_instance::Definition_type::Details_type::EventAction_type> Program_Invocation_instance::Definition_type::Details_type::eventAction__new() {
        return eventAction_ = boost::shared_ptr<EventAction_type>(new EventAction_type());
    }

    void Program_Invocation_instance::Definition_type::Details_type::eventAction(const EventAction_type& vl) {
        eventAction_ = boost::shared_ptr<EventAction_type>(new EventAction_type(vl));
    }

    boost::shared_ptr<Program_Invocation_instance::Definition_type::Details_type::EventEnrollment_type> Program_Invocation_instance::Definition_type::Details_type::eventEnrollment__new() {
        return eventEnrollment_ = boost::shared_ptr<EventEnrollment_type>(new EventEnrollment_type());
    }

    void Program_Invocation_instance::Definition_type::Details_type::eventEnrollment(const EventEnrollment_type& vl) {
        eventEnrollment_ = boost::shared_ptr<EventEnrollment_type>(new EventEnrollment_type(vl));
    }

    ISO_9506_MMS_1::MMSString& Program_Invocation_instance::Definition_type::Details_type::executionArgument() {
        return *executionArgument_;
    }

    const ISO_9506_MMS_1::MMSString& Program_Invocation_instance::Definition_type::Details_type::executionArgument() const {
        return *executionArgument_;
    }

    void Program_Invocation_instance::Definition_type::Details_type::executionArgument(const ISO_9506_MMS_1::MMSString& vl) {
        executionArgument_ = vl;
    }

    void Program_Invocation_instance::Definition_type::Details_type::executionArgument(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        executionArgument_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::Control_State> Program_Invocation_instance::Definition_type::Details_type::control__new() {
        return control_ = boost::shared_ptr<MMS_Object_Module_1::Control_State>(new MMS_Object_Module_1::Control_State());
    }

    void Program_Invocation_instance::Definition_type::Details_type::control(const MMS_Object_Module_1::Control_State& vl) {
        control_ = boost::shared_ptr<MMS_Object_Module_1::Control_State>(new MMS_Object_Module_1::Control_State(vl));
    }

    boost::shared_ptr<Program_Invocation_instance> Program_Invocation_instance::Definition_type::Details_type::controlling_Program_Invocation__new() {
        return controlling_Program_Invocation_ = boost::shared_ptr<Program_Invocation_instance>(new Program_Invocation_instance());
    }

    void Program_Invocation_instance::Definition_type::Details_type::controlling_Program_Invocation(const Program_Invocation_instance& vl) {
        controlling_Program_Invocation_ = boost::shared_ptr<Program_Invocation_instance>(new Program_Invocation_instance(vl));
    }

    boost::shared_ptr<Program_Invocation_instance::Definition_type::Details_type::Controlled_Program_Invocations_type> Program_Invocation_instance::Definition_type::Details_type::controlled_Program_Invocations__new() {
        return controlled_Program_Invocations_ = boost::shared_ptr<Controlled_Program_Invocations_type>(new Controlled_Program_Invocations_type());
    }

    void Program_Invocation_instance::Definition_type::Details_type::controlled_Program_Invocations(const Controlled_Program_Invocations_type& vl) {
        controlled_Program_Invocations_ = boost::shared_ptr<Controlled_Program_Invocations_type>(new Controlled_Program_Invocations_type(vl));
    }

    void Program_Invocation_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Program_Invocation_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Program_Invocation_instance::name() const {
        return *name_;
    }

    void Program_Invocation_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Program_Invocation_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Program_Invocation_instance::Definition_type& Program_Invocation_instance::definition() {
        return *definition_;
    }

    const Program_Invocation_instance::Definition_type& Program_Invocation_instance::definition() const {
        return *definition_;
    }

    void Program_Invocation_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Program_Invocation_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*domains_, 4);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 5);
    }

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*domains_, 4);
        ITU_T_IMPLICIT_TAG(*programInvocations_, 5);
    }

    Access_Control_List_instance& Unit_Control_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Unit_Control_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Unit_Control_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Unit_Control_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    Unit_Control_instance::Definition_type::Details_type::Domains_type& Unit_Control_instance::Definition_type::Details_type::domains() {
        return *domains_;
    }

    const Unit_Control_instance::Definition_type::Details_type::Domains_type& Unit_Control_instance::Definition_type::Details_type::domains() const {
        return *domains_;
    }

    void Unit_Control_instance::Definition_type::Details_type::domains(const Domains_type& vl) {
        domains_ = vl;
    }

    void Unit_Control_instance::Definition_type::Details_type::domains(boost::shared_ptr< Domains_type> vl) {
        domains_ = vl;
    }

    Unit_Control_instance::Definition_type::Details_type::ProgramInvocations_type& Unit_Control_instance::Definition_type::Details_type::programInvocations() {
        return *programInvocations_;
    }

    const Unit_Control_instance::Definition_type::Details_type::ProgramInvocations_type& Unit_Control_instance::Definition_type::Details_type::programInvocations() const {
        return *programInvocations_;
    }

    void Unit_Control_instance::Definition_type::Details_type::programInvocations(const ProgramInvocations_type& vl) {
        programInvocations_ = vl;
    }

    void Unit_Control_instance::Definition_type::Details_type::programInvocations(boost::shared_ptr< ProgramInvocations_type> vl) {
        programInvocations_ = vl;
    }

    void Unit_Control_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Unit_Control_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Unit_Control_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Unit_Control_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Unit_Control_instance::name() const {
        return *name_;
    }

    void Unit_Control_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Unit_Control_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Unit_Control_instance::Definition_type& Unit_Control_instance::definition() {
        return *definition_;
    }

    const Unit_Control_instance::Definition_type& Unit_Control_instance::definition() const {
        return *definition_;
    }

    void Unit_Control_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Unit_Control_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*address_, 0);
        ITU_T_IMPLICIT_TAG(*accessControl_, 1);
        ITU_T_CHOICE_TAG(*typeDescription_, 2);
    }

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*address_, 0);
        ITU_T_IMPLICIT_TAG(*accessControl_, 1);
        ITU_T_CHOICE_TAG(*typeDescription_, 2);
    }

    MMS_Object_Module_1::Address& Unnamed_Variable_instance::address() {
        return *address_;
    }

    const MMS_Object_Module_1::Address& Unnamed_Variable_instance::address() const {
        return *address_;
    }

    void Unnamed_Variable_instance::address(const MMS_Object_Module_1::Address& vl) {
        address_ = vl;
    }

    void Unnamed_Variable_instance::address(boost::shared_ptr< MMS_Object_Module_1::Address> vl) {
        address_ = vl;
    }

    Access_Control_List_instance& Unnamed_Variable_instance::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Unnamed_Variable_instance::accessControl() const {
        return *accessControl_;
    }

    void Unnamed_Variable_instance::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Unnamed_Variable_instance::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    MMS_Object_Module_1::TypeDescription& Unnamed_Variable_instance::typeDescription() {
        return *typeDescription_;
    }

    const MMS_Object_Module_1::TypeDescription& Unnamed_Variable_instance::typeDescription() const {
        return *typeDescription_;
    }

    void Unnamed_Variable_instance::typeDescription(const MMS_Object_Module_1::TypeDescription& vl) {
        typeDescription_ = vl;
    }

    void Unnamed_Variable_instance::typeDescription(boost::shared_ptr< MMS_Object_Module_1::TypeDescription> vl) {
        typeDescription_ = vl;
    }


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

    Named_Variable_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
            boost::shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
            boost::shared_ptr< MMS_Object_Module_1::Address> arg__address,
            boost::shared_ptr< visiblestring_type> arg__meaning) :
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription),
    address_(arg__address),
    meaning_(arg__meaning) {
    };

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(*typeDescription_, 4);
        ITU_T_CHOICE_TAG(address_, 5);
        ITU_T_IMPLICIT_TAG(meaning_, 6);
    }

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(*typeDescription_, 4);
        ITU_T_CHOICE_TAG(address_, 5);
        ITU_T_IMPLICIT_TAG(meaning_, 6);
    }

    Access_Control_List_instance& Named_Variable_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Named_Variable_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Named_Variable_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Named_Variable_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    MMS_Object_Module_1::TypeDescription& Named_Variable_instance::Definition_type::Details_type::typeDescription() {
        return *typeDescription_;
    }

    const MMS_Object_Module_1::TypeDescription& Named_Variable_instance::Definition_type::Details_type::typeDescription() const {
        return *typeDescription_;
    }

    void Named_Variable_instance::Definition_type::Details_type::typeDescription(const MMS_Object_Module_1::TypeDescription& vl) {
        typeDescription_ = vl;
    }

    void Named_Variable_instance::Definition_type::Details_type::typeDescription(boost::shared_ptr< MMS_Object_Module_1::TypeDescription> vl) {
        typeDescription_ = vl;
    }

    boost::shared_ptr<MMS_Object_Module_1::Address> Named_Variable_instance::Definition_type::Details_type::address__new() {
        return address_ = boost::shared_ptr<MMS_Object_Module_1::Address>(new MMS_Object_Module_1::Address());
    }

    void Named_Variable_instance::Definition_type::Details_type::address(const MMS_Object_Module_1::Address& vl) {
        address_ = boost::shared_ptr<MMS_Object_Module_1::Address>(new MMS_Object_Module_1::Address(vl));
    }

    boost::shared_ptr<visiblestring_type> Named_Variable_instance::Definition_type::Details_type::meaning__new() {
        return meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void Named_Variable_instance::Definition_type::Details_type::meaning(const visiblestring_type& vl) {
        meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    void Named_Variable_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Named_Variable_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Named_Variable_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Named_Variable_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Named_Variable_instance::name() const {
        return *name_;
    }

    void Named_Variable_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Named_Variable_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Named_Variable_instance::Definition_type& Named_Variable_instance::definition() {
        return *definition_;
    }

    const Named_Variable_instance::Definition_type& Named_Variable_instance::definition() const {
        return *definition_;
    }

    void Named_Variable_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Named_Variable_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*listOfVariables_, 4);
    }

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*listOfVariables_, 4);
    }

    Access_Control_List_instance& Named_Variable_List_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Named_Variable_List_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Named_Variable_List_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Named_Variable_List_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    Named_Variable_List_instance::Definition_type::Details_type::ListOfVariables_type& Named_Variable_List_instance::Definition_type::Details_type::listOfVariables() {
        return *listOfVariables_;
    }

    const Named_Variable_List_instance::Definition_type::Details_type::ListOfVariables_type& Named_Variable_List_instance::Definition_type::Details_type::listOfVariables() const {
        return *listOfVariables_;
    }

    void Named_Variable_List_instance::Definition_type::Details_type::listOfVariables(const ListOfVariables_type& vl) {
        listOfVariables_ = vl;
    }

    void Named_Variable_List_instance::Definition_type::Details_type::listOfVariables(boost::shared_ptr< ListOfVariables_type> vl) {
        listOfVariables_ = vl;
    }

    void Named_Variable_List_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Named_Variable_List_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Named_Variable_List_instance::name() const {
        return *name_;
    }

    void Named_Variable_List_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Named_Variable_List_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Named_Variable_List_instance::Definition_type& Named_Variable_List_instance::definition() {
        return *definition_;
    }

    const Named_Variable_List_instance::Definition_type& Named_Variable_List_instance::definition() const {
        return *definition_;
    }

    void Named_Variable_List_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Named_Variable_List_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


    // sequence Variable-List-Item-instance

    Variable_List_Item_instance::Variable_List_Item_instance() {
    };

    Variable_List_Item_instance::Variable_List_Item_instance(boost::shared_ptr< Unnamed_Variable_instance> arg__unnamedItem,
            boost::shared_ptr< Named_Variable_instance> arg__namedItem,
            boost::shared_ptr< ISO_9506_MMS_1::AlternateAccess> arg__alternateAccess) :
    unnamedItem_(arg__unnamedItem),
    namedItem_(arg__namedItem),
    alternateAccess_(arg__alternateAccess) {
    };

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(unnamedItem_, 0);
        ITU_T_IMPLICIT_TAG(namedItem_, 1);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 2);
    }

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(unnamedItem_, 0);
        ITU_T_IMPLICIT_TAG(namedItem_, 1);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 2);
    }

    boost::shared_ptr<Unnamed_Variable_instance> Variable_List_Item_instance::unnamedItem__new() {
        return unnamedItem_ = boost::shared_ptr<Unnamed_Variable_instance>(new Unnamed_Variable_instance());
    }

    void Variable_List_Item_instance::unnamedItem(const Unnamed_Variable_instance& vl) {
        unnamedItem_ = boost::shared_ptr<Unnamed_Variable_instance>(new Unnamed_Variable_instance(vl));
    }

    boost::shared_ptr<Named_Variable_instance> Variable_List_Item_instance::namedItem__new() {
        return namedItem_ = boost::shared_ptr<Named_Variable_instance>(new Named_Variable_instance());
    }

    void Variable_List_Item_instance::namedItem(const Named_Variable_instance& vl) {
        namedItem_ = boost::shared_ptr<Named_Variable_instance>(new Named_Variable_instance(vl));
    }

    boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess> Variable_List_Item_instance::alternateAccess__new() {
        return alternateAccess_ = boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess>(new ISO_9506_MMS_1::AlternateAccess());
    }

    void Variable_List_Item_instance::alternateAccess(const ISO_9506_MMS_1::AlternateAccess& vl) {
        alternateAccess_ = boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess>(new ISO_9506_MMS_1::AlternateAccess(vl));
    }


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

    Named_Type_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
            boost::shared_ptr< MMS_Object_Module_1::TypeDescription> arg__typeDescription,
            boost::shared_ptr< visiblestring_type> arg__meaning) :
    accessControl_(arg__accessControl),
    typeDescription_(arg__typeDescription),
    meaning_(arg__meaning) {
    };

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(*typeDescription_, 4);
        ITU_T_IMPLICIT_TAG(meaning_, 5);
    }

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(*typeDescription_, 4);
        ITU_T_IMPLICIT_TAG(meaning_, 5);
    }

    Access_Control_List_instance& Named_Type_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Named_Type_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Named_Type_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Named_Type_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    MMS_Object_Module_1::TypeDescription& Named_Type_instance::Definition_type::Details_type::typeDescription() {
        return *typeDescription_;
    }

    const MMS_Object_Module_1::TypeDescription& Named_Type_instance::Definition_type::Details_type::typeDescription() const {
        return *typeDescription_;
    }

    void Named_Type_instance::Definition_type::Details_type::typeDescription(const MMS_Object_Module_1::TypeDescription& vl) {
        typeDescription_ = vl;
    }

    void Named_Type_instance::Definition_type::Details_type::typeDescription(boost::shared_ptr< MMS_Object_Module_1::TypeDescription> vl) {
        typeDescription_ = vl;
    }

    boost::shared_ptr<visiblestring_type> Named_Type_instance::Definition_type::Details_type::meaning__new() {
        return meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type());
    }

    void Named_Type_instance::Definition_type::Details_type::meaning(const visiblestring_type& vl) {
        meaning_ = boost::shared_ptr<visiblestring_type>(new visiblestring_type(vl));
    }

    void Named_Type_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Named_Type_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Named_Type_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Named_Type_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Named_Type_instance::name() const {
        return *name_;
    }

    void Named_Type_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Named_Type_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Named_Type_instance::Definition_type& Named_Type_instance::definition() {
        return *definition_;
    }

    const Named_Type_instance::Definition_type& Named_Type_instance::definition() const {
        return *definition_;
    }

    void Named_Type_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Named_Type_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    Data_Exchange_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
            boost::shared_ptr< Request_type> arg__request,
            boost::shared_ptr< Response_type> arg__response,
            boost::shared_ptr< bool> arg__linked,
            boost::shared_ptr< Program_Invocation_instance> arg__programInvocation) :
    accessControl_(arg__accessControl),
    request_(arg__request),
    response_(arg__response),
    linked_(arg__linked),
    programInvocation_(arg__programInvocation) {
    };

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*request_, 4);
        ITU_T_IMPLICIT_TAG(*response_, 5);
        ITU_T_IMPLICIT_TAG(*linked_, 6);
        ITU_T_IMPLICIT_TAG(programInvocation_, 7);
    }

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*request_, 4);
        ITU_T_IMPLICIT_TAG(*response_, 5);
        ITU_T_IMPLICIT_TAG(*linked_, 6);
        ITU_T_IMPLICIT_TAG(programInvocation_, 7);
    }

    Access_Control_List_instance& Data_Exchange_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Data_Exchange_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Data_Exchange_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Data_Exchange_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    Data_Exchange_instance::Definition_type::Details_type::Request_type& Data_Exchange_instance::Definition_type::Details_type::request() {
        return *request_;
    }

    const Data_Exchange_instance::Definition_type::Details_type::Request_type& Data_Exchange_instance::Definition_type::Details_type::request() const {
        return *request_;
    }

    void Data_Exchange_instance::Definition_type::Details_type::request(const Request_type& vl) {
        request_ = vl;
    }

    void Data_Exchange_instance::Definition_type::Details_type::request(boost::shared_ptr< Request_type> vl) {
        request_ = vl;
    }

    Data_Exchange_instance::Definition_type::Details_type::Response_type& Data_Exchange_instance::Definition_type::Details_type::response() {
        return *response_;
    }

    const Data_Exchange_instance::Definition_type::Details_type::Response_type& Data_Exchange_instance::Definition_type::Details_type::response() const {
        return *response_;
    }

    void Data_Exchange_instance::Definition_type::Details_type::response(const Response_type& vl) {
        response_ = vl;
    }

    void Data_Exchange_instance::Definition_type::Details_type::response(boost::shared_ptr< Response_type> vl) {
        response_ = vl;
    }

    bool& Data_Exchange_instance::Definition_type::Details_type::linked() {
        return *linked_;
    }

    const bool& Data_Exchange_instance::Definition_type::Details_type::linked() const {
        return *linked_;
    }

    void Data_Exchange_instance::Definition_type::Details_type::linked(const bool& vl) {
        linked_ = vl;
    }

    void Data_Exchange_instance::Definition_type::Details_type::linked(boost::shared_ptr< bool> vl) {
        linked_ = vl;
    }

    boost::shared_ptr<Program_Invocation_instance> Data_Exchange_instance::Definition_type::Details_type::programInvocation__new() {
        return programInvocation_ = boost::shared_ptr<Program_Invocation_instance>(new Program_Invocation_instance());
    }

    void Data_Exchange_instance::Definition_type::Details_type::programInvocation(const Program_Invocation_instance& vl) {
        programInvocation_ = boost::shared_ptr<Program_Invocation_instance>(new Program_Invocation_instance(vl));
    }

    void Data_Exchange_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Data_Exchange_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Data_Exchange_instance::name() const {
        return *name_;
    }

    void Data_Exchange_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Data_Exchange_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Data_Exchange_instance::Definition_type& Data_Exchange_instance::definition() {
        return *definition_;
    }

    const Data_Exchange_instance::Definition_type& Data_Exchange_instance::definition() const {
        return *definition_;
    }

    void Data_Exchange_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Data_Exchange_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    Semaphore_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
            boost::shared_ptr< enumerated_type> arg__classV,
            boost::shared_ptr< int> arg__numberOfTokens,
            boost::shared_ptr< NamedTokens_type> arg__namedTokens,
            boost::shared_ptr< Event_Condition_instance> arg__eventCondition) :
    accessControl_(arg__accessControl),
    classV_(arg__classV),
    numberOfTokens_(arg__numberOfTokens),
    namedTokens_(arg__namedTokens),
    eventCondition_(arg__eventCondition) {
    };

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*classV_, 4);
        ITU_T_IMPLICIT_TAG(numberOfTokens_, 5);
        ITU_T_IMPLICIT_TAG(namedTokens_, 6);
        ITU_T_IMPLICIT_TAG(*eventCondition_, 7);
    }

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*classV_, 4);
        ITU_T_IMPLICIT_TAG(numberOfTokens_, 5);
        ITU_T_IMPLICIT_TAG(namedTokens_, 6);
        ITU_T_IMPLICIT_TAG(*eventCondition_, 7);
    }

    Access_Control_List_instance& Semaphore_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Semaphore_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Semaphore_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Semaphore_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    enumerated_type& Semaphore_instance::Definition_type::Details_type::classV() {
        return *classV_;
    }

    const enumerated_type& Semaphore_instance::Definition_type::Details_type::classV() const {
        return *classV_;
    }

    void Semaphore_instance::Definition_type::Details_type::classV(const enumerated_type& vl) {
        classV_ = vl;
    }

    void Semaphore_instance::Definition_type::Details_type::classV(boost::shared_ptr< enumerated_type> vl) {
        classV_ = vl;
    }

    boost::shared_ptr<int> Semaphore_instance::Definition_type::Details_type::numberOfTokens__new() {
        return numberOfTokens_ = boost::shared_ptr<int>(new int());
    }

    void Semaphore_instance::Definition_type::Details_type::numberOfTokens(const int& vl) {
        numberOfTokens_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<Semaphore_instance::Definition_type::Details_type::NamedTokens_type> Semaphore_instance::Definition_type::Details_type::namedTokens__new() {
        return namedTokens_ = boost::shared_ptr<NamedTokens_type>(new NamedTokens_type());
    }

    void Semaphore_instance::Definition_type::Details_type::namedTokens(const NamedTokens_type& vl) {
        namedTokens_ = boost::shared_ptr<NamedTokens_type>(new NamedTokens_type(vl));
    }

    Event_Condition_instance& Semaphore_instance::Definition_type::Details_type::eventCondition() {
        return *eventCondition_;
    }

    const Event_Condition_instance& Semaphore_instance::Definition_type::Details_type::eventCondition() const {
        return *eventCondition_;
    }

    void Semaphore_instance::Definition_type::Details_type::eventCondition(const Event_Condition_instance& vl) {
        eventCondition_ = vl;
    }

    void Semaphore_instance::Definition_type::Details_type::eventCondition(boost::shared_ptr< Event_Condition_instance> vl) {
        eventCondition_ = vl;
    }

    void Semaphore_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Semaphore_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Semaphore_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Semaphore_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Semaphore_instance::name() const {
        return *name_;
    }

    void Semaphore_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Semaphore_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Semaphore_instance::Definition_type& Semaphore_instance::definition() {
        return *definition_;
    }

    const Semaphore_instance::Definition_type& Semaphore_instance::definition() const {
        return *definition_;
    }

    void Semaphore_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Semaphore_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*stationType_, 4);
    }

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*stationType_, 4);
    }

    Access_Control_List_instance& Operator_Station_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Operator_Station_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Operator_Station_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Operator_Station_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    enumerated_type& Operator_Station_instance::Definition_type::Details_type::stationType() {
        return *stationType_;
    }

    const enumerated_type& Operator_Station_instance::Definition_type::Details_type::stationType() const {
        return *stationType_;
    }

    void Operator_Station_instance::Definition_type::Details_type::stationType(const enumerated_type& vl) {
        stationType_ = vl;
    }

    void Operator_Station_instance::Definition_type::Details_type::stationType(boost::shared_ptr< enumerated_type> vl) {
        stationType_ = vl;
    }

    void Operator_Station_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Operator_Station_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Operator_Station_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::Identifier& Operator_Station_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::Identifier& Operator_Station_instance::name() const {
        return *name_;
    }

    void Operator_Station_instance::name(const ISO_9506_MMS_1::Identifier& vl) {
        name_ = vl;
    }

    void Operator_Station_instance::name(boost::shared_ptr< ISO_9506_MMS_1::Identifier> vl) {
        name_ = vl;
    }

    Operator_Station_instance::Definition_type& Operator_Station_instance::definition() {
        return *definition_;
    }

    const Operator_Station_instance::Definition_type& Operator_Station_instance::definition() const {
        return *definition_;
    }

    void Operator_Station_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Operator_Station_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    Event_Condition_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
            boost::shared_ptr< MMS_Object_Module_1::EC_Class> arg__ecClass,
            boost::shared_ptr< MMS_Object_Module_1::EC_State> arg__ecState,
            boost::shared_ptr< MMS_Object_Module_1::Priority> arg__priority,
            boost::shared_ptr< MMS_Object_Module_1::Severity> arg__severity,
            boost::shared_ptr< EventEnrollments_type> arg__eventEnrollments,
            boost::shared_ptr< bool> arg__enabled,
            boost::shared_ptr< bool> arg__alarmSummaryReports,
            boost::shared_ptr< MonitoredVariable_type> arg__monitoredVariable,
            boost::shared_ptr< int> arg__evaluationInterval,
            boost::shared_ptr< DisplayEnhancement_type> arg__displayEnhancement,
            boost::shared_ptr< Group_Priority_Override_type> arg__group_Priority_Override,
            boost::shared_ptr< ReferencingEventConditionLists_type> arg__referencingEventConditionLists) :
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

    void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::unspecified(const null_type& vl) {
        set<null_type>(new null_type(vl), MonitoredVariable_type_unspecified);
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case MonitoredVariable_type_named:
            {
                ITU_T_IMPLICIT_TAG(*value<Named_Variable_instance > (false, MonitoredVariable_type_named), 11);
                break;
            }
            case MonitoredVariable_type_unnamed:
            {
                ITU_T_IMPLICIT_TAG(*value<Unnamed_Variable_instance > (false, MonitoredVariable_type_unnamed), 12);
                break;
            }
            case MonitoredVariable_type_unspecified:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, MonitoredVariable_type_unspecified), 13);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Named_Variable_instance > (true, MonitoredVariable_type_named), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Unnamed_Variable_instance > (true, MonitoredVariable_type_unnamed), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, MonitoredVariable_type_unspecified), 13)) return;
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

    void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::text(const ISO_9506_MMS_1::MMSString& vl) {
        set<ISO_9506_MMS_1::MMSString>(new ISO_9506_MMS_1::MMSString(vl), DisplayEnhancement_type_text);
    }

    void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::number(const int& vl) {
        set<int>(new int(vl), DisplayEnhancement_type_number);
    }

    void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::none(const null_type& vl) {
        set<null_type>(new null_type(vl), DisplayEnhancement_type_none);
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text), 15);
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_IMPLICIT_TAG(*value<int > (false, DisplayEnhancement_type_number), 16);
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DisplayEnhancement_type_none), 17);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 15:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<int > (true, DisplayEnhancement_type_number), 16)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DisplayEnhancement_type_none), 17)) return;
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

    void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::priority(const MMS_Object_Module_1::Priority& vl) {
        set<MMS_Object_Module_1::Priority>(new MMS_Object_Module_1::Priority(vl), Group_Priority_Override_type_priority);
    }

    void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::undefined(const null_type& vl) {
        set<null_type>(new null_type(vl), Group_Priority_Override_type_undefined);
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Group_Priority_Override_type_priority:
            {
                ITU_T_IMPLICIT_TAG(*value<MMS_Object_Module_1::Priority > (false, Group_Priority_Override_type_priority), 18);
                break;
            }
            case Group_Priority_Override_type_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, Group_Priority_Override_type_undefined), 19);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 18:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<MMS_Object_Module_1::Priority > (true, Group_Priority_Override_type_priority), 18)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, Group_Priority_Override_type_undefined), 19)) return;
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

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*ecClass_, 4);
        ITU_T_IMPLICIT_TAG(*ecState_, 5);
        ITU_T_IMPLICIT_TAG(*priority_, 6);
        ITU_T_IMPLICIT_TAG(*severity_, 7);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 8);
        ITU_T_IMPLICIT_TAG(enabled_, 9);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 10);
        ITU_T_BIND_CHOICE(monitoredVariable_);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 14);
        ITU_T_EXTENTION;
        ITU_T_BIND_CHOICE(*displayEnhancement_);
        ITU_T_BIND_CHOICE(group_Priority_Override_);
        ITU_T_IMPLICIT_TAG(*referencingEventConditionLists_, 20);
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*ecClass_, 4);
        ITU_T_IMPLICIT_TAG(*ecState_, 5);
        ITU_T_IMPLICIT_TAG(*priority_, 6);
        ITU_T_IMPLICIT_TAG(*severity_, 7);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 8);
        ITU_T_IMPLICIT_TAG(enabled_, 9);
        ITU_T_IMPLICIT_TAG(alarmSummaryReports_, 10);
        ITU_T_BIND_CHOICE(monitoredVariable_);
        ITU_T_IMPLICIT_TAG(evaluationInterval_, 14);
        ITU_T_EXTENTION;
        ITU_T_BIND_CHOICE(*displayEnhancement_);
        ITU_T_BIND_CHOICE(group_Priority_Override_);
        ITU_T_IMPLICIT_TAG(*referencingEventConditionLists_, 20);
    }

    Access_Control_List_instance& Event_Condition_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Event_Condition_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Event_Condition_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Event_Condition_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    MMS_Object_Module_1::EC_Class& Event_Condition_instance::Definition_type::Details_type::ecClass() {
        return *ecClass_;
    }

    const MMS_Object_Module_1::EC_Class& Event_Condition_instance::Definition_type::Details_type::ecClass() const {
        return *ecClass_;
    }

    void Event_Condition_instance::Definition_type::Details_type::ecClass(const MMS_Object_Module_1::EC_Class& vl) {
        ecClass_ = vl;
    }

    void Event_Condition_instance::Definition_type::Details_type::ecClass(boost::shared_ptr< MMS_Object_Module_1::EC_Class> vl) {
        ecClass_ = vl;
    }

    MMS_Object_Module_1::EC_State& Event_Condition_instance::Definition_type::Details_type::ecState() {
        return *ecState_;
    }

    const MMS_Object_Module_1::EC_State& Event_Condition_instance::Definition_type::Details_type::ecState() const {
        return *ecState_;
    }

    void Event_Condition_instance::Definition_type::Details_type::ecState(const MMS_Object_Module_1::EC_State& vl) {
        ecState_ = vl;
    }

    void Event_Condition_instance::Definition_type::Details_type::ecState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        ecState_ = vl;
    }

    MMS_Object_Module_1::Priority& Event_Condition_instance::Definition_type::Details_type::priority() {
        return *priority_;
    }

    const MMS_Object_Module_1::Priority& Event_Condition_instance::Definition_type::Details_type::priority() const {
        return *priority_;
    }

    void Event_Condition_instance::Definition_type::Details_type::priority(const MMS_Object_Module_1::Priority& vl) {
        priority_ = vl;
    }

    void Event_Condition_instance::Definition_type::Details_type::priority(boost::shared_ptr< MMS_Object_Module_1::Priority> vl) {
        priority_ = vl;
    }

    MMS_Object_Module_1::Severity& Event_Condition_instance::Definition_type::Details_type::severity() {
        return *severity_;
    }

    const MMS_Object_Module_1::Severity& Event_Condition_instance::Definition_type::Details_type::severity() const {
        return *severity_;
    }

    void Event_Condition_instance::Definition_type::Details_type::severity(const MMS_Object_Module_1::Severity& vl) {
        severity_ = vl;
    }

    void Event_Condition_instance::Definition_type::Details_type::severity(boost::shared_ptr< MMS_Object_Module_1::Severity> vl) {
        severity_ = vl;
    }

    Event_Condition_instance::Definition_type::Details_type::EventEnrollments_type& Event_Condition_instance::Definition_type::Details_type::eventEnrollments() {
        return *eventEnrollments_;
    }

    const Event_Condition_instance::Definition_type::Details_type::EventEnrollments_type& Event_Condition_instance::Definition_type::Details_type::eventEnrollments() const {
        return *eventEnrollments_;
    }

    void Event_Condition_instance::Definition_type::Details_type::eventEnrollments(const EventEnrollments_type& vl) {
        eventEnrollments_ = vl;
    }

    void Event_Condition_instance::Definition_type::Details_type::eventEnrollments(boost::shared_ptr< EventEnrollments_type> vl) {
        eventEnrollments_ = vl;
    }

    boost::shared_ptr<bool> Event_Condition_instance::Definition_type::Details_type::enabled__new() {
        return enabled_ = boost::shared_ptr<bool>(new bool());
    }

    void Event_Condition_instance::Definition_type::Details_type::enabled(const bool& vl) {
        enabled_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<bool> Event_Condition_instance::Definition_type::Details_type::alarmSummaryReports__new() {
        return alarmSummaryReports_ = boost::shared_ptr<bool>(new bool());
    }

    void Event_Condition_instance::Definition_type::Details_type::alarmSummaryReports(const bool& vl) {
        alarmSummaryReports_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type> Event_Condition_instance::Definition_type::Details_type::monitoredVariable__new() {
        return monitoredVariable_ = boost::shared_ptr<MonitoredVariable_type>(new MonitoredVariable_type());
    }

    void Event_Condition_instance::Definition_type::Details_type::monitoredVariable(const MonitoredVariable_type& vl) {
        monitoredVariable_ = boost::shared_ptr<MonitoredVariable_type>(new MonitoredVariable_type(vl));
    }

    boost::shared_ptr<int> Event_Condition_instance::Definition_type::Details_type::evaluationInterval__new() {
        return evaluationInterval_ = boost::shared_ptr<int>(new int());
    }

    void Event_Condition_instance::Definition_type::Details_type::evaluationInterval(const int& vl) {
        evaluationInterval_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type> Event_Condition_instance::Definition_type::Details_type::displayEnhancement__new() {
        return displayEnhancement_ = boost::shared_ptr<DisplayEnhancement_type>(new DisplayEnhancement_type());
    }

    void Event_Condition_instance::Definition_type::Details_type::displayEnhancement(const DisplayEnhancement_type& vl) {
        displayEnhancement_ = boost::shared_ptr<DisplayEnhancement_type>(new DisplayEnhancement_type(vl));
    }

    boost::shared_ptr<Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type> Event_Condition_instance::Definition_type::Details_type::group_Priority_Override__new() {
        return group_Priority_Override_ = boost::shared_ptr<Group_Priority_Override_type>(new Group_Priority_Override_type());
    }

    void Event_Condition_instance::Definition_type::Details_type::group_Priority_Override(const Group_Priority_Override_type& vl) {
        group_Priority_Override_ = boost::shared_ptr<Group_Priority_Override_type>(new Group_Priority_Override_type(vl));
    }

    boost::shared_ptr<Event_Condition_instance::Definition_type::Details_type::ReferencingEventConditionLists_type> Event_Condition_instance::Definition_type::Details_type::referencingEventConditionLists__new() {
        return referencingEventConditionLists_ = boost::shared_ptr<ReferencingEventConditionLists_type>(new ReferencingEventConditionLists_type());
    }

    void Event_Condition_instance::Definition_type::Details_type::referencingEventConditionLists(const ReferencingEventConditionLists_type& vl) {
        referencingEventConditionLists_ = boost::shared_ptr<ReferencingEventConditionLists_type>(new ReferencingEventConditionLists_type(vl));
    }

    void Event_Condition_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Event_Condition_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Condition_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Event_Condition_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Event_Condition_instance::name() const {
        return *name_;
    }

    void Event_Condition_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Event_Condition_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Event_Condition_instance::Definition_type& Event_Condition_instance::definition() {
        return *definition_;
    }

    const Event_Condition_instance::Definition_type& Event_Condition_instance::definition() const {
        return *definition_;
    }

    void Event_Condition_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Event_Condition_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(*confirmedServiceRequest_, 4);
        ITU_T_IMPLICIT_TAG(*modifiers_, 5);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 6);
    }

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_CHOICE_TAG(*confirmedServiceRequest_, 4);
        ITU_T_IMPLICIT_TAG(*modifiers_, 5);
        ITU_T_IMPLICIT_TAG(*eventEnrollments_, 6);
    }

    Access_Control_List_instance& Event_Action_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Event_Action_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Event_Action_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Event_Action_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    ISO_9506_MMS_1::ConfirmedServiceRequest& Event_Action_instance::Definition_type::Details_type::confirmedServiceRequest() {
        return *confirmedServiceRequest_;
    }

    const ISO_9506_MMS_1::ConfirmedServiceRequest& Event_Action_instance::Definition_type::Details_type::confirmedServiceRequest() const {
        return *confirmedServiceRequest_;
    }

    void Event_Action_instance::Definition_type::Details_type::confirmedServiceRequest(const ISO_9506_MMS_1::ConfirmedServiceRequest& vl) {
        confirmedServiceRequest_ = vl;
    }

    void Event_Action_instance::Definition_type::Details_type::confirmedServiceRequest(boost::shared_ptr< ISO_9506_MMS_1::ConfirmedServiceRequest> vl) {
        confirmedServiceRequest_ = vl;
    }

    Event_Action_instance::Definition_type::Details_type::Modifiers_type& Event_Action_instance::Definition_type::Details_type::modifiers() {
        return *modifiers_;
    }

    const Event_Action_instance::Definition_type::Details_type::Modifiers_type& Event_Action_instance::Definition_type::Details_type::modifiers() const {
        return *modifiers_;
    }

    void Event_Action_instance::Definition_type::Details_type::modifiers(const Modifiers_type& vl) {
        modifiers_ = vl;
    }

    void Event_Action_instance::Definition_type::Details_type::modifiers(boost::shared_ptr< Modifiers_type> vl) {
        modifiers_ = vl;
    }

    Event_Action_instance::Definition_type::Details_type::EventEnrollments_type& Event_Action_instance::Definition_type::Details_type::eventEnrollments() {
        return *eventEnrollments_;
    }

    const Event_Action_instance::Definition_type::Details_type::EventEnrollments_type& Event_Action_instance::Definition_type::Details_type::eventEnrollments() const {
        return *eventEnrollments_;
    }

    void Event_Action_instance::Definition_type::Details_type::eventEnrollments(const EventEnrollments_type& vl) {
        eventEnrollments_ = vl;
    }

    void Event_Action_instance::Definition_type::Details_type::eventEnrollments(boost::shared_ptr< EventEnrollments_type> vl) {
        eventEnrollments_ = vl;
    }

    void Event_Action_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Event_Action_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Action_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Event_Action_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Event_Action_instance::name() const {
        return *name_;
    }

    void Event_Action_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Event_Action_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Event_Action_instance::Definition_type& Event_Action_instance::definition() {
        return *definition_;
    }

    const Event_Action_instance::Definition_type& Event_Action_instance::definition() const {
        return *definition_;
    }

    void Event_Action_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Event_Action_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    Event_Enrollment_instance::Definition_type::Details_type::Details_type(boost::shared_ptr< Access_Control_List_instance> arg__accessControl,
            boost::shared_ptr< MMS_Object_Module_1::EE_Class> arg__eeClass,
            boost::shared_ptr< Event_Condition_instance> arg__eventCondition,
            boost::shared_ptr< MMS_Object_Module_1::Transitions> arg__ecTransitions,
            boost::shared_ptr< RemainingDelay_type> arg__remainingDelay,
            boost::shared_ptr< Event_Action_instance> arg__eventAction,
            boost::shared_ptr< MMS_Object_Module_1::EE_Duration> arg__duration,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> arg__aaRule,
            boost::shared_ptr< DisplayEnhancement_type> arg__displayEnhancement) :
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

    void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::time(const int& vl) {
        set<int>(new int(vl), RemainingDelay_type_time);
    }

    void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::forever(const null_type& vl) {
        set<null_type>(new null_type(vl), RemainingDelay_type_forever);
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RemainingDelay_type_time:
            {
                ITU_T_IMPLICIT_TAG(*value<int > (false, RemainingDelay_type_time), 7);
                break;
            }
            case RemainingDelay_type_forever:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, RemainingDelay_type_forever), 8);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<int > (true, RemainingDelay_type_time), 7)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, RemainingDelay_type_forever), 8)) return;
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

    void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::text(const ISO_9506_MMS_1::MMSString& vl) {
        set<ISO_9506_MMS_1::MMSString>(new ISO_9506_MMS_1::MMSString(vl), DisplayEnhancement_type_text);
    }

    void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::number(const int& vl) {
        set<int>(new int(vl), DisplayEnhancement_type_number);
    }

    void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::none(const null_type& vl) {
        set<null_type>(new null_type(vl), DisplayEnhancement_type_none);
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text), 13);
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_IMPLICIT_TAG(*value<int > (false, DisplayEnhancement_type_number), 14);
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, DisplayEnhancement_type_none), 15);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 13:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text), 13)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<int > (true, DisplayEnhancement_type_number), 14)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, DisplayEnhancement_type_none), 15)) return;
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

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*eeClass_, 4);
        ITU_T_IMPLICIT_TAG(*eventCondition_, 5);
        ITU_T_IMPLICIT_TAG(*ecTransitions_, 6);
        ITU_T_BIND_CHOICE(remainingDelay_);
        ITU_T_IMPLICIT_TAG(eventAction_, 9);
        ITU_T_IMPLICIT_TAG(duration_, 10);
        ITU_T_IMPLICIT_TAG(clientApplication_, 11);
        ITU_T_IMPLICIT_TAG(aaRule_, 12);
        ITU_T_EXTENTION;
        ITU_T_BIND_CHOICE(*displayEnhancement_);
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*eeClass_, 4);
        ITU_T_IMPLICIT_TAG(*eventCondition_, 5);
        ITU_T_IMPLICIT_TAG(*ecTransitions_, 6);
        ITU_T_BIND_CHOICE(remainingDelay_);
        ITU_T_IMPLICIT_TAG(eventAction_, 9);
        ITU_T_IMPLICIT_TAG(duration_, 10);
        ITU_T_IMPLICIT_TAG(clientApplication_, 11);
        ITU_T_IMPLICIT_TAG(aaRule_, 12);
        ITU_T_EXTENTION;
        ITU_T_BIND_CHOICE(*displayEnhancement_);
    }

    Access_Control_List_instance& Event_Enrollment_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Event_Enrollment_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    MMS_Object_Module_1::EE_Class& Event_Enrollment_instance::Definition_type::Details_type::eeClass() {
        return *eeClass_;
    }

    const MMS_Object_Module_1::EE_Class& Event_Enrollment_instance::Definition_type::Details_type::eeClass() const {
        return *eeClass_;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::eeClass(const MMS_Object_Module_1::EE_Class& vl) {
        eeClass_ = vl;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::eeClass(boost::shared_ptr< MMS_Object_Module_1::EE_Class> vl) {
        eeClass_ = vl;
    }

    Event_Condition_instance& Event_Enrollment_instance::Definition_type::Details_type::eventCondition() {
        return *eventCondition_;
    }

    const Event_Condition_instance& Event_Enrollment_instance::Definition_type::Details_type::eventCondition() const {
        return *eventCondition_;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::eventCondition(const Event_Condition_instance& vl) {
        eventCondition_ = vl;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::eventCondition(boost::shared_ptr< Event_Condition_instance> vl) {
        eventCondition_ = vl;
    }

    MMS_Object_Module_1::Transitions& Event_Enrollment_instance::Definition_type::Details_type::ecTransitions() {
        return *ecTransitions_;
    }

    const MMS_Object_Module_1::Transitions& Event_Enrollment_instance::Definition_type::Details_type::ecTransitions() const {
        return *ecTransitions_;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::ecTransitions(const MMS_Object_Module_1::Transitions& vl) {
        ecTransitions_ = vl;
    }

    void Event_Enrollment_instance::Definition_type::Details_type::ecTransitions(boost::shared_ptr< MMS_Object_Module_1::Transitions> vl) {
        ecTransitions_ = vl;
    }

    boost::shared_ptr<Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type> Event_Enrollment_instance::Definition_type::Details_type::remainingDelay__new() {
        return remainingDelay_ = boost::shared_ptr<RemainingDelay_type>(new RemainingDelay_type());
    }

    void Event_Enrollment_instance::Definition_type::Details_type::remainingDelay(const RemainingDelay_type& vl) {
        remainingDelay_ = boost::shared_ptr<RemainingDelay_type>(new RemainingDelay_type(vl));
    }

    boost::shared_ptr<Event_Action_instance> Event_Enrollment_instance::Definition_type::Details_type::eventAction__new() {
        return eventAction_ = boost::shared_ptr<Event_Action_instance>(new Event_Action_instance());
    }

    void Event_Enrollment_instance::Definition_type::Details_type::eventAction(const Event_Action_instance& vl) {
        eventAction_ = boost::shared_ptr<Event_Action_instance>(new Event_Action_instance(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::EE_Duration> Event_Enrollment_instance::Definition_type::Details_type::duration__new() {
        return duration_ = boost::shared_ptr<MMS_Object_Module_1::EE_Duration>(new MMS_Object_Module_1::EE_Duration());
    }

    void Event_Enrollment_instance::Definition_type::Details_type::duration(const MMS_Object_Module_1::EE_Duration& vl) {
        duration_ = boost::shared_ptr<MMS_Object_Module_1::EE_Duration>(new MMS_Object_Module_1::EE_Duration(vl));
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> Event_Enrollment_instance::Definition_type::Details_type::clientApplication__new() {
        return clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void Event_Enrollment_instance::Definition_type::Details_type::clientApplication(const MMS_Environment_1::ApplicationReference& vl) {
        clientApplication_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }

    boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> Event_Enrollment_instance::Definition_type::Details_type::aaRule__new() {
        return aaRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule());
    }

    void Event_Enrollment_instance::Definition_type::Details_type::aaRule(const MMS_Object_Module_1::AlarmAckRule& vl) {
        aaRule_ = boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule>(new MMS_Object_Module_1::AlarmAckRule(vl));
    }

    boost::shared_ptr<Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type> Event_Enrollment_instance::Definition_type::Details_type::displayEnhancement__new() {
        return displayEnhancement_ = boost::shared_ptr<DisplayEnhancement_type>(new DisplayEnhancement_type());
    }

    void Event_Enrollment_instance::Definition_type::Details_type::displayEnhancement(const DisplayEnhancement_type& vl) {
        displayEnhancement_ = boost::shared_ptr<DisplayEnhancement_type>(new DisplayEnhancement_type(vl));
    }

    void Event_Enrollment_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Event_Enrollment_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Event_Enrollment_instance::name() const {
        return *name_;
    }

    void Event_Enrollment_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Event_Enrollment_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Event_Enrollment_instance::Definition_type& Event_Enrollment_instance::definition() {
        return *definition_;
    }

    const Event_Enrollment_instance::Definition_type& Event_Enrollment_instance::definition() const {
        return *definition_;
    }

    void Event_Enrollment_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Event_Enrollment_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 4);
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 5);
        ITU_T_IMPLICIT_TAG(*referencingEventConditionLists_, 6);
    }

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*eventConditions_, 4);
        ITU_T_IMPLICIT_TAG(*eventConditionLists_, 5);
        ITU_T_IMPLICIT_TAG(*referencingEventConditionLists_, 6);
    }

    Access_Control_List_instance& Event_Condition_List_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Event_Condition_List_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    Event_Condition_List_instance::Definition_type::Details_type::EventConditions_type& Event_Condition_List_instance::Definition_type::Details_type::eventConditions() {
        return *eventConditions_;
    }

    const Event_Condition_List_instance::Definition_type::Details_type::EventConditions_type& Event_Condition_List_instance::Definition_type::Details_type::eventConditions() const {
        return *eventConditions_;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::eventConditions(const EventConditions_type& vl) {
        eventConditions_ = vl;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::eventConditions(boost::shared_ptr< EventConditions_type> vl) {
        eventConditions_ = vl;
    }

    Event_Condition_List_instance::Definition_type::Details_type::EventConditionLists_type& Event_Condition_List_instance::Definition_type::Details_type::eventConditionLists() {
        return *eventConditionLists_;
    }

    const Event_Condition_List_instance::Definition_type::Details_type::EventConditionLists_type& Event_Condition_List_instance::Definition_type::Details_type::eventConditionLists() const {
        return *eventConditionLists_;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::eventConditionLists(const EventConditionLists_type& vl) {
        eventConditionLists_ = vl;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::eventConditionLists(boost::shared_ptr< EventConditionLists_type> vl) {
        eventConditionLists_ = vl;
    }

    Event_Condition_List_instance::Definition_type::Details_type::ReferencingEventConditionLists_type& Event_Condition_List_instance::Definition_type::Details_type::referencingEventConditionLists() {
        return *referencingEventConditionLists_;
    }

    const Event_Condition_List_instance::Definition_type::Details_type::ReferencingEventConditionLists_type& Event_Condition_List_instance::Definition_type::Details_type::referencingEventConditionLists() const {
        return *referencingEventConditionLists_;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::referencingEventConditionLists(const ReferencingEventConditionLists_type& vl) {
        referencingEventConditionLists_ = vl;
    }

    void Event_Condition_List_instance::Definition_type::Details_type::referencingEventConditionLists(boost::shared_ptr< ReferencingEventConditionLists_type> vl) {
        referencingEventConditionLists_ = vl;
    }

    void Event_Condition_List_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Event_Condition_List_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Event_Condition_List_instance::name() const {
        return *name_;
    }

    void Event_Condition_List_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Event_Condition_List_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Event_Condition_List_instance::Definition_type& Event_Condition_List_instance::definition() {
        return *definition_;
    }

    const Event_Condition_List_instance::Definition_type& Event_Condition_List_instance::definition() const {
        return *definition_;
    }

    void Event_Condition_List_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Event_Condition_List_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*entries_, 4);
    }

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*entries_, 4);
    }

    Access_Control_List_instance& Journal_instance::Definition_type::Details_type::accessControl() {
        return *accessControl_;
    }

    const Access_Control_List_instance& Journal_instance::Definition_type::Details_type::accessControl() const {
        return *accessControl_;
    }

    void Journal_instance::Definition_type::Details_type::accessControl(const Access_Control_List_instance& vl) {
        accessControl_ = vl;
    }

    void Journal_instance::Definition_type::Details_type::accessControl(boost::shared_ptr< Access_Control_List_instance> vl) {
        accessControl_ = vl;
    }

    Journal_instance::Definition_type::Details_type::Entries_type& Journal_instance::Definition_type::Details_type::entries() {
        return *entries_;
    }

    const Journal_instance::Definition_type::Details_type::Entries_type& Journal_instance::Definition_type::Details_type::entries() const {
        return *entries_;
    }

    void Journal_instance::Definition_type::Details_type::entries(const Entries_type& vl) {
        entries_ = vl;
    }

    void Journal_instance::Definition_type::Details_type::entries(boost::shared_ptr< Entries_type> vl) {
        entries_ = vl;
    }

    void Journal_instance::Definition_type::reference(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Definition_type_reference);
    }

    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_IMPLICIT_TAG(*value<oid_type > (false, Definition_type_reference), 1);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_IMPLICIT_TAG(*value<Details_type > (false, Definition_type_details), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<oid_type > (true, Definition_type_reference), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Details_type > (true, Definition_type_details), 2)) return;
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

    template<> void Journal_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Journal_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    ISO_9506_MMS_1::ObjectName& Journal_instance::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Journal_instance::name() const {
        return *name_;
    }

    void Journal_instance::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Journal_instance::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    Journal_instance::Definition_type& Journal_instance::definition() {
        return *definition_;
    }

    const Journal_instance::Definition_type& Journal_instance::definition() const {
        return *definition_;
    }

    void Journal_instance::definition(const Definition_type& vl) {
        definition_ = vl;
    }

    void Journal_instance::definition(boost::shared_ptr< Definition_type> vl) {
        definition_ = vl;
    }


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
            const int& arg__orderOfReceipt,
            const enumerated_type& arg__informationType) :
    journal_(arg__journal),
    entry_(arg__entry),
    clientApplication_(arg__clientApplication),
    timeStamp_(arg__timeStamp),
    orderOfReceipt_(arg__orderOfReceipt),
    informationType_(arg__informationType) {
    };

    Journal_Entry_instance::Journal_Entry_instance(boost::shared_ptr< Journal_instance> arg__journal,
            boost::shared_ptr< octetstring_type> arg__entry,
            boost::shared_ptr< MMS_Environment_1::ApplicationReference> arg__clientApplication,
            boost::shared_ptr< ISO_9506_MMS_1::TimeOfDay> arg__timeStamp,
            boost::shared_ptr< int> arg__orderOfReceipt,
            boost::shared_ptr< enumerated_type> arg__informationType,
            boost::shared_ptr< ISO_9506_MMS_1::MMS255String> arg__textComment,
            boost::shared_ptr< EventTransitionRecord_type> arg__eventTransitionRecord,
            boost::shared_ptr< JournalVariables_type> arg__journalVariables) :
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

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 8);
        ITU_T_IMPLICIT_TAG(*currentState_, 9);
    }

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 8);
        ITU_T_IMPLICIT_TAG(*currentState_, 9);
    }

    ISO_9506_MMS_1::ObjectName& Journal_Entry_instance::EventTransitionRecord_type::name() {
        return *name_;
    }

    const ISO_9506_MMS_1::ObjectName& Journal_Entry_instance::EventTransitionRecord_type::name() const {
        return *name_;
    }

    void Journal_Entry_instance::EventTransitionRecord_type::name(const ISO_9506_MMS_1::ObjectName& vl) {
        name_ = vl;
    }

    void Journal_Entry_instance::EventTransitionRecord_type::name(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        name_ = vl;
    }

    MMS_Object_Module_1::EC_State& Journal_Entry_instance::EventTransitionRecord_type::currentState() {
        return *currentState_;
    }

    const MMS_Object_Module_1::EC_State& Journal_Entry_instance::EventTransitionRecord_type::currentState() const {
        return *currentState_;
    }

    void Journal_Entry_instance::EventTransitionRecord_type::currentState(const MMS_Object_Module_1::EC_State& vl) {
        currentState_ = vl;
    }

    void Journal_Entry_instance::EventTransitionRecord_type::currentState(boost::shared_ptr< MMS_Object_Module_1::EC_State> vl) {
        currentState_ = vl;
    }

    Journal_Entry_instance::JournalVariables_type_sequence_of::JournalVariables_type_sequence_of() : variableTag_(), valueSpecification_() {
    };

    Journal_Entry_instance::JournalVariables_type_sequence_of::JournalVariables_type_sequence_of(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
            const ISO_9506_MMS_1::Data& arg__valueSpecification) :
    variableTag_(arg__variableTag),
    valueSpecification_(arg__valueSpecification) {
    };

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*variableTag_, 11);
        ITU_T_CHOICE_TAG(*valueSpecification_, 12);
    }

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*variableTag_, 11);
        ITU_T_CHOICE_TAG(*valueSpecification_, 12);
    }

    ISO_9506_MMS_1::MMS255String& Journal_Entry_instance::JournalVariables_type_sequence_of::variableTag() {
        return *variableTag_;
    }

    const ISO_9506_MMS_1::MMS255String& Journal_Entry_instance::JournalVariables_type_sequence_of::variableTag() const {
        return *variableTag_;
    }

    void Journal_Entry_instance::JournalVariables_type_sequence_of::variableTag(const ISO_9506_MMS_1::MMS255String& vl) {
        variableTag_ = vl;
    }

    void Journal_Entry_instance::JournalVariables_type_sequence_of::variableTag(boost::shared_ptr< ISO_9506_MMS_1::MMS255String> vl) {
        variableTag_ = vl;
    }

    ISO_9506_MMS_1::Data& Journal_Entry_instance::JournalVariables_type_sequence_of::valueSpecification() {
        return *valueSpecification_;
    }

    const ISO_9506_MMS_1::Data& Journal_Entry_instance::JournalVariables_type_sequence_of::valueSpecification() const {
        return *valueSpecification_;
    }

    void Journal_Entry_instance::JournalVariables_type_sequence_of::valueSpecification(const ISO_9506_MMS_1::Data& vl) {
        valueSpecification_ = vl;
    }

    void Journal_Entry_instance::JournalVariables_type_sequence_of::valueSpecification(boost::shared_ptr< ISO_9506_MMS_1::Data> vl) {
        valueSpecification_ = vl;
    }

    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*journal_, 0);
        ITU_T_IMPLICIT_TAG(*entry_, 1);
        ITU_T_IMPLICIT_TAG(*clientApplication_, 2);
        ITU_T_IMPLICIT_TAG(*timeStamp_, 3);
        ITU_T_IMPLICIT_TAG(*orderOfReceipt_, 4);
        ITU_T_IMPLICIT_TAG(*informationType_, 5);
        ITU_T_EXPLICIT_TAG(textComment_, 6);
        ITU_T_IMPLICIT_TAG(eventTransitionRecord_, 7);
        ITU_T_IMPLICIT_TAG(journalVariables_, 10);
    }

    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*journal_, 0);
        ITU_T_IMPLICIT_TAG(*entry_, 1);
        ITU_T_IMPLICIT_TAG(*clientApplication_, 2);
        ITU_T_IMPLICIT_TAG(*timeStamp_, 3);
        ITU_T_IMPLICIT_TAG(*orderOfReceipt_, 4);
        ITU_T_IMPLICIT_TAG(*informationType_, 5);
        ITU_T_EXPLICIT_TAG(textComment_, 6);
        ITU_T_IMPLICIT_TAG(eventTransitionRecord_, 7);
        ITU_T_IMPLICIT_TAG(journalVariables_, 10);
    }

    Journal_instance& Journal_Entry_instance::journal() {
        return *journal_;
    }

    const Journal_instance& Journal_Entry_instance::journal() const {
        return *journal_;
    }

    void Journal_Entry_instance::journal(const Journal_instance& vl) {
        journal_ = vl;
    }

    void Journal_Entry_instance::journal(boost::shared_ptr< Journal_instance> vl) {
        journal_ = vl;
    }

    octetstring_type& Journal_Entry_instance::entry() {
        return *entry_;
    }

    const octetstring_type& Journal_Entry_instance::entry() const {
        return *entry_;
    }

    void Journal_Entry_instance::entry(const octetstring_type& vl) {
        entry_ = vl;
    }

    void Journal_Entry_instance::entry(boost::shared_ptr< octetstring_type> vl) {
        entry_ = vl;
    }

    MMS_Environment_1::ApplicationReference& Journal_Entry_instance::clientApplication() {
        return *clientApplication_;
    }

    const MMS_Environment_1::ApplicationReference& Journal_Entry_instance::clientApplication() const {
        return *clientApplication_;
    }

    void Journal_Entry_instance::clientApplication(const MMS_Environment_1::ApplicationReference& vl) {
        clientApplication_ = vl;
    }

    void Journal_Entry_instance::clientApplication(boost::shared_ptr< MMS_Environment_1::ApplicationReference> vl) {
        clientApplication_ = vl;
    }

    ISO_9506_MMS_1::TimeOfDay& Journal_Entry_instance::timeStamp() {
        return *timeStamp_;
    }

    const ISO_9506_MMS_1::TimeOfDay& Journal_Entry_instance::timeStamp() const {
        return *timeStamp_;
    }

    void Journal_Entry_instance::timeStamp(const ISO_9506_MMS_1::TimeOfDay& vl) {
        timeStamp_ = vl;
    }

    void Journal_Entry_instance::timeStamp(boost::shared_ptr< ISO_9506_MMS_1::TimeOfDay> vl) {
        timeStamp_ = vl;
    }

    int& Journal_Entry_instance::orderOfReceipt() {
        return *orderOfReceipt_;
    }

    const int& Journal_Entry_instance::orderOfReceipt() const {
        return *orderOfReceipt_;
    }

    void Journal_Entry_instance::orderOfReceipt(const int& vl) {
        orderOfReceipt_ = vl;
    }

    void Journal_Entry_instance::orderOfReceipt(boost::shared_ptr< int> vl) {
        orderOfReceipt_ = vl;
    }

    enumerated_type& Journal_Entry_instance::informationType() {
        return *informationType_;
    }

    const enumerated_type& Journal_Entry_instance::informationType() const {
        return *informationType_;
    }

    void Journal_Entry_instance::informationType(const enumerated_type& vl) {
        informationType_ = vl;
    }

    void Journal_Entry_instance::informationType(boost::shared_ptr< enumerated_type> vl) {
        informationType_ = vl;
    }

    boost::shared_ptr<ISO_9506_MMS_1::MMS255String> Journal_Entry_instance::textComment__new() {
        return textComment_ = boost::shared_ptr<ISO_9506_MMS_1::MMS255String>(new ISO_9506_MMS_1::MMS255String());
    }

    void Journal_Entry_instance::textComment(const ISO_9506_MMS_1::MMS255String& vl) {
        textComment_ = boost::shared_ptr<ISO_9506_MMS_1::MMS255String>(new ISO_9506_MMS_1::MMS255String(vl));
    }

    boost::shared_ptr<Journal_Entry_instance::EventTransitionRecord_type> Journal_Entry_instance::eventTransitionRecord__new() {
        return eventTransitionRecord_ = boost::shared_ptr<EventTransitionRecord_type>(new EventTransitionRecord_type());
    }

    void Journal_Entry_instance::eventTransitionRecord(const EventTransitionRecord_type& vl) {
        eventTransitionRecord_ = boost::shared_ptr<EventTransitionRecord_type>(new EventTransitionRecord_type(vl));
    }

    boost::shared_ptr<Journal_Entry_instance::JournalVariables_type> Journal_Entry_instance::journalVariables__new() {
        return journalVariables_ = boost::shared_ptr<JournalVariables_type>(new JournalVariables_type());
    }

    void Journal_Entry_instance::journalVariables(const JournalVariables_type& vl) {
        journalVariables_ = boost::shared_ptr<JournalVariables_type>(new JournalVariables_type(vl));
    }


    // sequence Service-and-Parameter-CBBs

    Service_and_Parameter_CBBs::Service_and_Parameter_CBBs() : services_Client_(), services_Server_(), parameters_(), nest_(), extendedServices_Client_(), extendedServices_Server_(), extendedParameters_(), generalManagement_(), vMDSupport_(), domainManagement_(), programInvocation_(), variableAccess_(), dataParameters_(), semaphoreManagement_(), operatorCommunication_(), errors_(), fileManagement_() {
    };

    Service_and_Parameter_CBBs::Service_and_Parameter_CBBs(const MMS_Object_Module_1::ServiceSupportOptions& arg__services_Client,
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

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*services_Client_, 0);
        ITU_T_IMPLICIT_TAG(*services_Server_, 1);
        ITU_T_IMPLICIT_TAG(*parameters_, 2);
        ITU_T_IMPLICIT_TAG(*nest_, 3);
        ITU_T_IMPLICIT_TAG(*extendedServices_Client_, 4);
        ITU_T_IMPLICIT_TAG(*extendedServices_Server_, 5);
        ITU_T_IMPLICIT_TAG(*extendedParameters_, 6);
        ITU_T_IMPLICIT_TAG(*generalManagement_, 7);
        ITU_T_IMPLICIT_TAG(*vMDSupport_, 8);
        ITU_T_IMPLICIT_TAG(*domainManagement_, 9);
        ITU_T_IMPLICIT_TAG(*programInvocation_, 10);
        ITU_T_IMPLICIT_TAG(*variableAccess_, 11);
        ITU_T_IMPLICIT_TAG(*dataParameters_, 12);
        ITU_T_IMPLICIT_TAG(*semaphoreManagement_, 13);
        ITU_T_IMPLICIT_TAG(*operatorCommunication_, 14);
        ITU_T_IMPLICIT_TAG(*errors_, 15);
        ITU_T_IMPLICIT_TAG(*fileManagement_, 16);
    }

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*services_Client_, 0);
        ITU_T_IMPLICIT_TAG(*services_Server_, 1);
        ITU_T_IMPLICIT_TAG(*parameters_, 2);
        ITU_T_IMPLICIT_TAG(*nest_, 3);
        ITU_T_IMPLICIT_TAG(*extendedServices_Client_, 4);
        ITU_T_IMPLICIT_TAG(*extendedServices_Server_, 5);
        ITU_T_IMPLICIT_TAG(*extendedParameters_, 6);
        ITU_T_IMPLICIT_TAG(*generalManagement_, 7);
        ITU_T_IMPLICIT_TAG(*vMDSupport_, 8);
        ITU_T_IMPLICIT_TAG(*domainManagement_, 9);
        ITU_T_IMPLICIT_TAG(*programInvocation_, 10);
        ITU_T_IMPLICIT_TAG(*variableAccess_, 11);
        ITU_T_IMPLICIT_TAG(*dataParameters_, 12);
        ITU_T_IMPLICIT_TAG(*semaphoreManagement_, 13);
        ITU_T_IMPLICIT_TAG(*operatorCommunication_, 14);
        ITU_T_IMPLICIT_TAG(*errors_, 15);
        ITU_T_IMPLICIT_TAG(*fileManagement_, 16);
    }

    MMS_Object_Module_1::ServiceSupportOptions& Service_and_Parameter_CBBs::services_Client() {
        return *services_Client_;
    }

    const MMS_Object_Module_1::ServiceSupportOptions& Service_and_Parameter_CBBs::services_Client() const {
        return *services_Client_;
    }

    void Service_and_Parameter_CBBs::services_Client(const MMS_Object_Module_1::ServiceSupportOptions& vl) {
        services_Client_ = vl;
    }

    void Service_and_Parameter_CBBs::services_Client(boost::shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> vl) {
        services_Client_ = vl;
    }

    MMS_Object_Module_1::ServiceSupportOptions& Service_and_Parameter_CBBs::services_Server() {
        return *services_Server_;
    }

    const MMS_Object_Module_1::ServiceSupportOptions& Service_and_Parameter_CBBs::services_Server() const {
        return *services_Server_;
    }

    void Service_and_Parameter_CBBs::services_Server(const MMS_Object_Module_1::ServiceSupportOptions& vl) {
        services_Server_ = vl;
    }

    void Service_and_Parameter_CBBs::services_Server(boost::shared_ptr< MMS_Object_Module_1::ServiceSupportOptions> vl) {
        services_Server_ = vl;
    }

    MMS_Object_Module_1::ParameterSupportOptions& Service_and_Parameter_CBBs::parameters() {
        return *parameters_;
    }

    const MMS_Object_Module_1::ParameterSupportOptions& Service_and_Parameter_CBBs::parameters() const {
        return *parameters_;
    }

    void Service_and_Parameter_CBBs::parameters(const MMS_Object_Module_1::ParameterSupportOptions& vl) {
        parameters_ = vl;
    }

    void Service_and_Parameter_CBBs::parameters(boost::shared_ptr< MMS_Object_Module_1::ParameterSupportOptions> vl) {
        parameters_ = vl;
    }

    int& Service_and_Parameter_CBBs::nest() {
        return *nest_;
    }

    const int& Service_and_Parameter_CBBs::nest() const {
        return *nest_;
    }

    void Service_and_Parameter_CBBs::nest(const int& vl) {
        nest_ = vl;
    }

    void Service_and_Parameter_CBBs::nest(boost::shared_ptr< int> vl) {
        nest_ = vl;
    }

    MMS_Object_Module_1::AdditionalSupportOptions& Service_and_Parameter_CBBs::extendedServices_Client() {
        return *extendedServices_Client_;
    }

    const MMS_Object_Module_1::AdditionalSupportOptions& Service_and_Parameter_CBBs::extendedServices_Client() const {
        return *extendedServices_Client_;
    }

    void Service_and_Parameter_CBBs::extendedServices_Client(const MMS_Object_Module_1::AdditionalSupportOptions& vl) {
        extendedServices_Client_ = vl;
    }

    void Service_and_Parameter_CBBs::extendedServices_Client(boost::shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> vl) {
        extendedServices_Client_ = vl;
    }

    MMS_Object_Module_1::AdditionalSupportOptions& Service_and_Parameter_CBBs::extendedServices_Server() {
        return *extendedServices_Server_;
    }

    const MMS_Object_Module_1::AdditionalSupportOptions& Service_and_Parameter_CBBs::extendedServices_Server() const {
        return *extendedServices_Server_;
    }

    void Service_and_Parameter_CBBs::extendedServices_Server(const MMS_Object_Module_1::AdditionalSupportOptions& vl) {
        extendedServices_Server_ = vl;
    }

    void Service_and_Parameter_CBBs::extendedServices_Server(boost::shared_ptr< MMS_Object_Module_1::AdditionalSupportOptions> vl) {
        extendedServices_Server_ = vl;
    }

    MMS_Object_Module_1::AdditionalCBBOptions& Service_and_Parameter_CBBs::extendedParameters() {
        return *extendedParameters_;
    }

    const MMS_Object_Module_1::AdditionalCBBOptions& Service_and_Parameter_CBBs::extendedParameters() const {
        return *extendedParameters_;
    }

    void Service_and_Parameter_CBBs::extendedParameters(const MMS_Object_Module_1::AdditionalCBBOptions& vl) {
        extendedParameters_ = vl;
    }

    void Service_and_Parameter_CBBs::extendedParameters(boost::shared_ptr< MMS_Object_Module_1::AdditionalCBBOptions> vl) {
        extendedParameters_ = vl;
    }

    GeneralManagementParameters& Service_and_Parameter_CBBs::generalManagement() {
        return *generalManagement_;
    }

    const GeneralManagementParameters& Service_and_Parameter_CBBs::generalManagement() const {
        return *generalManagement_;
    }

    void Service_and_Parameter_CBBs::generalManagement(const GeneralManagementParameters& vl) {
        generalManagement_ = vl;
    }

    void Service_and_Parameter_CBBs::generalManagement(boost::shared_ptr< GeneralManagementParameters> vl) {
        generalManagement_ = vl;
    }

    VMDSupportParameters& Service_and_Parameter_CBBs::vMDSupport() {
        return *vMDSupport_;
    }

    const VMDSupportParameters& Service_and_Parameter_CBBs::vMDSupport() const {
        return *vMDSupport_;
    }

    void Service_and_Parameter_CBBs::vMDSupport(const VMDSupportParameters& vl) {
        vMDSupport_ = vl;
    }

    void Service_and_Parameter_CBBs::vMDSupport(boost::shared_ptr< VMDSupportParameters> vl) {
        vMDSupport_ = vl;
    }

    DomainManagementParameters& Service_and_Parameter_CBBs::domainManagement() {
        return *domainManagement_;
    }

    const DomainManagementParameters& Service_and_Parameter_CBBs::domainManagement() const {
        return *domainManagement_;
    }

    void Service_and_Parameter_CBBs::domainManagement(const DomainManagementParameters& vl) {
        domainManagement_ = vl;
    }

    void Service_and_Parameter_CBBs::domainManagement(boost::shared_ptr< DomainManagementParameters> vl) {
        domainManagement_ = vl;
    }

    ProgramInvocationManagementParameters& Service_and_Parameter_CBBs::programInvocation() {
        return *programInvocation_;
    }

    const ProgramInvocationManagementParameters& Service_and_Parameter_CBBs::programInvocation() const {
        return *programInvocation_;
    }

    void Service_and_Parameter_CBBs::programInvocation(const ProgramInvocationManagementParameters& vl) {
        programInvocation_ = vl;
    }

    void Service_and_Parameter_CBBs::programInvocation(boost::shared_ptr< ProgramInvocationManagementParameters> vl) {
        programInvocation_ = vl;
    }

    VariableAccessParameters& Service_and_Parameter_CBBs::variableAccess() {
        return *variableAccess_;
    }

    const VariableAccessParameters& Service_and_Parameter_CBBs::variableAccess() const {
        return *variableAccess_;
    }

    void Service_and_Parameter_CBBs::variableAccess(const VariableAccessParameters& vl) {
        variableAccess_ = vl;
    }

    void Service_and_Parameter_CBBs::variableAccess(boost::shared_ptr< VariableAccessParameters> vl) {
        variableAccess_ = vl;
    }

    DataParameters& Service_and_Parameter_CBBs::dataParameters() {
        return *dataParameters_;
    }

    const DataParameters& Service_and_Parameter_CBBs::dataParameters() const {
        return *dataParameters_;
    }

    void Service_and_Parameter_CBBs::dataParameters(const DataParameters& vl) {
        dataParameters_ = vl;
    }

    void Service_and_Parameter_CBBs::dataParameters(boost::shared_ptr< DataParameters> vl) {
        dataParameters_ = vl;
    }

    SemaphoreManagementParameters& Service_and_Parameter_CBBs::semaphoreManagement() {
        return *semaphoreManagement_;
    }

    const SemaphoreManagementParameters& Service_and_Parameter_CBBs::semaphoreManagement() const {
        return *semaphoreManagement_;
    }

    void Service_and_Parameter_CBBs::semaphoreManagement(const SemaphoreManagementParameters& vl) {
        semaphoreManagement_ = vl;
    }

    void Service_and_Parameter_CBBs::semaphoreManagement(boost::shared_ptr< SemaphoreManagementParameters> vl) {
        semaphoreManagement_ = vl;
    }

    OperatorCommunicationParameters& Service_and_Parameter_CBBs::operatorCommunication() {
        return *operatorCommunication_;
    }

    const OperatorCommunicationParameters& Service_and_Parameter_CBBs::operatorCommunication() const {
        return *operatorCommunication_;
    }

    void Service_and_Parameter_CBBs::operatorCommunication(const OperatorCommunicationParameters& vl) {
        operatorCommunication_ = vl;
    }

    void Service_and_Parameter_CBBs::operatorCommunication(boost::shared_ptr< OperatorCommunicationParameters> vl) {
        operatorCommunication_ = vl;
    }

    ErrorParameters& Service_and_Parameter_CBBs::errors() {
        return *errors_;
    }

    const ErrorParameters& Service_and_Parameter_CBBs::errors() const {
        return *errors_;
    }

    void Service_and_Parameter_CBBs::errors(const ErrorParameters& vl) {
        errors_ = vl;
    }

    void Service_and_Parameter_CBBs::errors(boost::shared_ptr< ErrorParameters> vl) {
        errors_ = vl;
    }

    FileManagementParameters& Service_and_Parameter_CBBs::fileManagement() {
        return *fileManagement_;
    }

    const FileManagementParameters& Service_and_Parameter_CBBs::fileManagement() const {
        return *fileManagement_;
    }

    void Service_and_Parameter_CBBs::fileManagement(const FileManagementParameters& vl) {
        fileManagement_ = vl;
    }

    void Service_and_Parameter_CBBs::fileManagement(boost::shared_ptr< FileManagementParameters> vl) {
        fileManagement_ = vl;
    }


    // sequence GeneralManagementParameters

    GeneralManagementParameters::GeneralManagementParameters() : localDetail_(), supportForTime_(), granularityOfTime_() {
    };

    GeneralManagementParameters::GeneralManagementParameters(const ISO_9506_MMS_1::MMSString& arg__localDetail,
            const SupportForTime_type& arg__supportForTime,
            const int& arg__granularityOfTime) :
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

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*timeOfDay_, 2);
        ITU_T_IMPLICIT_TAG(*timeSequence_, 3);
    }

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*timeOfDay_, 2);
        ITU_T_IMPLICIT_TAG(*timeSequence_, 3);
    }

    bool& GeneralManagementParameters::SupportForTime_type::timeOfDay() {
        return *timeOfDay_;
    }

    const bool& GeneralManagementParameters::SupportForTime_type::timeOfDay() const {
        return *timeOfDay_;
    }

    void GeneralManagementParameters::SupportForTime_type::timeOfDay(const bool& vl) {
        timeOfDay_ = vl;
    }

    void GeneralManagementParameters::SupportForTime_type::timeOfDay(boost::shared_ptr< bool> vl) {
        timeOfDay_ = vl;
    }

    bool& GeneralManagementParameters::SupportForTime_type::timeSequence() {
        return *timeSequence_;
    }

    const bool& GeneralManagementParameters::SupportForTime_type::timeSequence() const {
        return *timeSequence_;
    }

    void GeneralManagementParameters::SupportForTime_type::timeSequence(const bool& vl) {
        timeSequence_ = vl;
    }

    void GeneralManagementParameters::SupportForTime_type::timeSequence(boost::shared_ptr< bool> vl) {
        timeSequence_ = vl;
    }

    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*localDetail_, 0);
        ITU_T_IMPLICIT_TAG(*supportForTime_, 1);
        ITU_T_IMPLICIT_TAG(*granularityOfTime_, 4);
    }

    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*localDetail_, 0);
        ITU_T_IMPLICIT_TAG(*supportForTime_, 1);
        ITU_T_IMPLICIT_TAG(*granularityOfTime_, 4);
    }

    ISO_9506_MMS_1::MMSString& GeneralManagementParameters::localDetail() {
        return *localDetail_;
    }

    const ISO_9506_MMS_1::MMSString& GeneralManagementParameters::localDetail() const {
        return *localDetail_;
    }

    void GeneralManagementParameters::localDetail(const ISO_9506_MMS_1::MMSString& vl) {
        localDetail_ = vl;
    }

    void GeneralManagementParameters::localDetail(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        localDetail_ = vl;
    }

    GeneralManagementParameters::SupportForTime_type& GeneralManagementParameters::supportForTime() {
        return *supportForTime_;
    }

    const GeneralManagementParameters::SupportForTime_type& GeneralManagementParameters::supportForTime() const {
        return *supportForTime_;
    }

    void GeneralManagementParameters::supportForTime(const SupportForTime_type& vl) {
        supportForTime_ = vl;
    }

    void GeneralManagementParameters::supportForTime(boost::shared_ptr< SupportForTime_type> vl) {
        supportForTime_ = vl;
    }

    int& GeneralManagementParameters::granularityOfTime() {
        return *granularityOfTime_;
    }

    const int& GeneralManagementParameters::granularityOfTime() const {
        return *granularityOfTime_;
    }

    void GeneralManagementParameters::granularityOfTime(const int& vl) {
        granularityOfTime_ = vl;
    }

    void GeneralManagementParameters::granularityOfTime(boost::shared_ptr< int> vl) {
        granularityOfTime_ = vl;
    }


    // sequence VMDSupportParameters

    VMDSupportParameters::VMDSupportParameters() : localDetail_(), extendedDerivation_() {
    };

    VMDSupportParameters::VMDSupportParameters(const ISO_9506_MMS_1::MMSString& arg__localDetail,
            const ISO_9506_MMS_1::MMSString& arg__extendedDerivation) :
    localDetail_(arg__localDetail),
    extendedDerivation_(arg__extendedDerivation) {
    };

    template<> void VMDSupportParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*localDetail_, 0);
        ITU_T_EXPLICIT_TAG(*extendedDerivation_, 1);
    }

    template<> void VMDSupportParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*localDetail_, 0);
        ITU_T_EXPLICIT_TAG(*extendedDerivation_, 1);
    }

    ISO_9506_MMS_1::MMSString& VMDSupportParameters::localDetail() {
        return *localDetail_;
    }

    const ISO_9506_MMS_1::MMSString& VMDSupportParameters::localDetail() const {
        return *localDetail_;
    }

    void VMDSupportParameters::localDetail(const ISO_9506_MMS_1::MMSString& vl) {
        localDetail_ = vl;
    }

    void VMDSupportParameters::localDetail(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        localDetail_ = vl;
    }

    ISO_9506_MMS_1::MMSString& VMDSupportParameters::extendedDerivation() {
        return *extendedDerivation_;
    }

    const ISO_9506_MMS_1::MMSString& VMDSupportParameters::extendedDerivation() const {
        return *extendedDerivation_;
    }

    void VMDSupportParameters::extendedDerivation(const ISO_9506_MMS_1::MMSString& vl) {
        extendedDerivation_ = vl;
    }

    void VMDSupportParameters::extendedDerivation(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        extendedDerivation_ = vl;
    }


    // sequence DomainManagementParameters

    DomainManagementParameters::DomainManagementParameters() : loadDataOctet_(), loadDataSyntax_(), maxUploads_() {
    };

    DomainManagementParameters::DomainManagementParameters(const ISO_9506_MMS_1::MMSString& arg__loadDataOctet,
            const LoadDataSyntax_type& arg__loadDataSyntax,
            const int& arg__maxUploads) :
    loadDataOctet_(arg__loadDataOctet),
    loadDataSyntax_(arg__loadDataSyntax),
    maxUploads_(arg__maxUploads) {
    };

    template<> void DomainManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*loadDataOctet_, 0);
        ITU_T_IMPLICIT_TAG(*loadDataSyntax_, 1);
        ITU_T_IMPLICIT_TAG(*maxUploads_, 2);
    }

    template<> void DomainManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*loadDataOctet_, 0);
        ITU_T_IMPLICIT_TAG(*loadDataSyntax_, 1);
        ITU_T_IMPLICIT_TAG(*maxUploads_, 2);
    }

    ISO_9506_MMS_1::MMSString& DomainManagementParameters::loadDataOctet() {
        return *loadDataOctet_;
    }

    const ISO_9506_MMS_1::MMSString& DomainManagementParameters::loadDataOctet() const {
        return *loadDataOctet_;
    }

    void DomainManagementParameters::loadDataOctet(const ISO_9506_MMS_1::MMSString& vl) {
        loadDataOctet_ = vl;
    }

    void DomainManagementParameters::loadDataOctet(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        loadDataOctet_ = vl;
    }

    DomainManagementParameters::LoadDataSyntax_type& DomainManagementParameters::loadDataSyntax() {
        return *loadDataSyntax_;
    }

    const DomainManagementParameters::LoadDataSyntax_type& DomainManagementParameters::loadDataSyntax() const {
        return *loadDataSyntax_;
    }

    void DomainManagementParameters::loadDataSyntax(const LoadDataSyntax_type& vl) {
        loadDataSyntax_ = vl;
    }

    void DomainManagementParameters::loadDataSyntax(boost::shared_ptr< LoadDataSyntax_type> vl) {
        loadDataSyntax_ = vl;
    }

    int& DomainManagementParameters::maxUploads() {
        return *maxUploads_;
    }

    const int& DomainManagementParameters::maxUploads() const {
        return *maxUploads_;
    }

    void DomainManagementParameters::maxUploads(const int& vl) {
        maxUploads_ = vl;
    }

    void DomainManagementParameters::maxUploads(boost::shared_ptr< int> vl) {
        maxUploads_ = vl;
    }


    // sequence ProgramInvocationManagementParameters

    ProgramInvocationManagementParameters::ProgramInvocationManagementParameters() : executionArgMaxSize_(), executionArgParseRules_(), executionArgSyntaxes_(), programLoction_(), stepMode_() {
    };

    ProgramInvocationManagementParameters::ProgramInvocationManagementParameters(const int& arg__executionArgMaxSize,
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

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*executionArgMaxSize_, 0);
        ITU_T_EXPLICIT_TAG(*executionArgParseRules_, 1);
        ITU_T_IMPLICIT_TAG(*executionArgSyntaxes_, 2);
        ITU_T_EXPLICIT_TAG(*programLoction_, 3);
        ITU_T_IMPLICIT_TAG(*stepMode_, 4);
    }

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*executionArgMaxSize_, 0);
        ITU_T_EXPLICIT_TAG(*executionArgParseRules_, 1);
        ITU_T_IMPLICIT_TAG(*executionArgSyntaxes_, 2);
        ITU_T_EXPLICIT_TAG(*programLoction_, 3);
        ITU_T_IMPLICIT_TAG(*stepMode_, 4);
    }

    int& ProgramInvocationManagementParameters::executionArgMaxSize() {
        return *executionArgMaxSize_;
    }

    const int& ProgramInvocationManagementParameters::executionArgMaxSize() const {
        return *executionArgMaxSize_;
    }

    void ProgramInvocationManagementParameters::executionArgMaxSize(const int& vl) {
        executionArgMaxSize_ = vl;
    }

    void ProgramInvocationManagementParameters::executionArgMaxSize(boost::shared_ptr< int> vl) {
        executionArgMaxSize_ = vl;
    }

    ISO_9506_MMS_1::MMSString& ProgramInvocationManagementParameters::executionArgParseRules() {
        return *executionArgParseRules_;
    }

    const ISO_9506_MMS_1::MMSString& ProgramInvocationManagementParameters::executionArgParseRules() const {
        return *executionArgParseRules_;
    }

    void ProgramInvocationManagementParameters::executionArgParseRules(const ISO_9506_MMS_1::MMSString& vl) {
        executionArgParseRules_ = vl;
    }

    void ProgramInvocationManagementParameters::executionArgParseRules(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        executionArgParseRules_ = vl;
    }

    ProgramInvocationManagementParameters::ExecutionArgSyntaxes_type& ProgramInvocationManagementParameters::executionArgSyntaxes() {
        return *executionArgSyntaxes_;
    }

    const ProgramInvocationManagementParameters::ExecutionArgSyntaxes_type& ProgramInvocationManagementParameters::executionArgSyntaxes() const {
        return *executionArgSyntaxes_;
    }

    void ProgramInvocationManagementParameters::executionArgSyntaxes(const ExecutionArgSyntaxes_type& vl) {
        executionArgSyntaxes_ = vl;
    }

    void ProgramInvocationManagementParameters::executionArgSyntaxes(boost::shared_ptr< ExecutionArgSyntaxes_type> vl) {
        executionArgSyntaxes_ = vl;
    }

    ISO_9506_MMS_1::MMSString& ProgramInvocationManagementParameters::programLoction() {
        return *programLoction_;
    }

    const ISO_9506_MMS_1::MMSString& ProgramInvocationManagementParameters::programLoction() const {
        return *programLoction_;
    }

    void ProgramInvocationManagementParameters::programLoction(const ISO_9506_MMS_1::MMSString& vl) {
        programLoction_ = vl;
    }

    void ProgramInvocationManagementParameters::programLoction(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        programLoction_ = vl;
    }

    bool& ProgramInvocationManagementParameters::stepMode() {
        return *stepMode_;
    }

    const bool& ProgramInvocationManagementParameters::stepMode() const {
        return *stepMode_;
    }

    void ProgramInvocationManagementParameters::stepMode(const bool& vl) {
        stepMode_ = vl;
    }

    void ProgramInvocationManagementParameters::stepMode(boost::shared_ptr< bool> vl) {
        stepMode_ = vl;
    }


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

    template<> void VariableAccessParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*uninterruptibleAccess_, 0);
        ITU_T_IMPLICIT_TAG(*singleMode_, 1);
        ITU_T_IMPLICIT_TAG(*unnamedMode_, 2);
    }

    template<> void VariableAccessParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*uninterruptibleAccess_, 0);
        ITU_T_IMPLICIT_TAG(*singleMode_, 1);
        ITU_T_IMPLICIT_TAG(*unnamedMode_, 2);
    }

    ISO_9506_MMS_1::MMSString& VariableAccessParameters::uninterruptibleAccess() {
        return *uninterruptibleAccess_;
    }

    const ISO_9506_MMS_1::MMSString& VariableAccessParameters::uninterruptibleAccess() const {
        return *uninterruptibleAccess_;
    }

    void VariableAccessParameters::uninterruptibleAccess(const ISO_9506_MMS_1::MMSString& vl) {
        uninterruptibleAccess_ = vl;
    }

    void VariableAccessParameters::uninterruptibleAccess(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        uninterruptibleAccess_ = vl;
    }

    bool& VariableAccessParameters::singleMode() {
        return *singleMode_;
    }

    const bool& VariableAccessParameters::singleMode() const {
        return *singleMode_;
    }

    void VariableAccessParameters::singleMode(const bool& vl) {
        singleMode_ = vl;
    }

    void VariableAccessParameters::singleMode(boost::shared_ptr< bool> vl) {
        singleMode_ = vl;
    }

    bool& VariableAccessParameters::unnamedMode() {
        return *unnamedMode_;
    }

    const bool& VariableAccessParameters::unnamedMode() const {
        return *unnamedMode_;
    }

    void VariableAccessParameters::unnamedMode(const bool& vl) {
        unnamedMode_ = vl;
    }

    void VariableAccessParameters::unnamedMode(boost::shared_ptr< bool> vl) {
        unnamedMode_ = vl;
    }


    // sequence DataParameters

    DataParameters::DataParameters() {
    };

    DataParameters::DataParameters(boost::shared_ptr< int> arg__bit_string,
            boost::shared_ptr< int> arg__integer,
            boost::shared_ptr< int> arg__unsignedV,
            boost::shared_ptr< Floating_point_type> arg__floating_point,
            boost::shared_ptr< int> arg__octet_string,
            boost::shared_ptr< int> arg__visible_string,
            boost::shared_ptr< bool> arg__binary_time,
            boost::shared_ptr< int> arg__bcd,
            boost::shared_ptr< int> arg__mmsString) :
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

    DataParameters::Floating_point_type::Floating_point_type(const int& arg__total,
            const int& arg__exponent) :
    total_(arg__total),
    exponent_(arg__exponent) {
    };

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*total_, 4);
        ITU_T_IMPLICIT_TAG(*exponent_, 5);
    }

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*total_, 4);
        ITU_T_IMPLICIT_TAG(*exponent_, 5);
    }

    int& DataParameters::Floating_point_type::total() {
        return *total_;
    }

    const int& DataParameters::Floating_point_type::total() const {
        return *total_;
    }

    void DataParameters::Floating_point_type::total(const int& vl) {
        total_ = vl;
    }

    void DataParameters::Floating_point_type::total(boost::shared_ptr< int> vl) {
        total_ = vl;
    }

    int& DataParameters::Floating_point_type::exponent() {
        return *exponent_;
    }

    const int& DataParameters::Floating_point_type::exponent() const {
        return *exponent_;
    }

    void DataParameters::Floating_point_type::exponent(const int& vl) {
        exponent_ = vl;
    }

    void DataParameters::Floating_point_type::exponent(boost::shared_ptr< int> vl) {
        exponent_ = vl;
    }

    template<> void DataParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(bit_string_, 0);
        ITU_T_IMPLICIT_TAG(integer_, 1);
        ITU_T_IMPLICIT_TAG(unsignedV_, 2);
        ITU_T_IMPLICIT_TAG(floating_point_, 3);
        ITU_T_IMPLICIT_TAG(octet_string_, 10);
        ITU_T_IMPLICIT_TAG(visible_string_, 11);
        ITU_T_IMPLICIT_TAG(binary_time_, 12);
        ITU_T_IMPLICIT_TAG(bcd_, 13);
        ITU_T_IMPLICIT_TAG(mmsString_, 14);
    }

    template<> void DataParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(bit_string_, 0);
        ITU_T_IMPLICIT_TAG(integer_, 1);
        ITU_T_IMPLICIT_TAG(unsignedV_, 2);
        ITU_T_IMPLICIT_TAG(floating_point_, 3);
        ITU_T_IMPLICIT_TAG(octet_string_, 10);
        ITU_T_IMPLICIT_TAG(visible_string_, 11);
        ITU_T_IMPLICIT_TAG(binary_time_, 12);
        ITU_T_IMPLICIT_TAG(bcd_, 13);
        ITU_T_IMPLICIT_TAG(mmsString_, 14);
    }

    boost::shared_ptr<int> DataParameters::bit_string__new() {
        return bit_string_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::bit_string(const int& vl) {
        bit_string_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<int> DataParameters::integer__new() {
        return integer_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::integer(const int& vl) {
        integer_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<int> DataParameters::unsignedV__new() {
        return unsignedV_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::unsignedV(const int& vl) {
        unsignedV_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<DataParameters::Floating_point_type> DataParameters::floating_point__new() {
        return floating_point_ = boost::shared_ptr<Floating_point_type>(new Floating_point_type());
    }

    void DataParameters::floating_point(const Floating_point_type& vl) {
        floating_point_ = boost::shared_ptr<Floating_point_type>(new Floating_point_type(vl));
    }

    boost::shared_ptr<int> DataParameters::octet_string__new() {
        return octet_string_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::octet_string(const int& vl) {
        octet_string_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<int> DataParameters::visible_string__new() {
        return visible_string_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::visible_string(const int& vl) {
        visible_string_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<bool> DataParameters::binary_time__new() {
        return binary_time_ = boost::shared_ptr<bool>(new bool());
    }

    void DataParameters::binary_time(const bool& vl) {
        binary_time_ = boost::shared_ptr<bool>(new bool(vl));
    }

    boost::shared_ptr<int> DataParameters::bcd__new() {
        return bcd_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::bcd(const int& vl) {
        bcd_ = boost::shared_ptr<int>(new int(vl));
    }

    boost::shared_ptr<int> DataParameters::mmsString__new() {
        return mmsString_ = boost::shared_ptr<int>(new int());
    }

    void DataParameters::mmsString(const int& vl) {
        mmsString_ = boost::shared_ptr<int>(new int(vl));
    }


    // sequence SemaphoreManagementParameters

    SemaphoreManagementParameters::SemaphoreManagementParameters() : algorithm_() {
    };

    SemaphoreManagementParameters::SemaphoreManagementParameters(const ISO_9506_MMS_1::MMSString& arg__algorithm) :
    algorithm_(arg__algorithm) {
    };

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*algorithm_, 0);
    }

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*algorithm_, 0);
    }

    ISO_9506_MMS_1::MMSString& SemaphoreManagementParameters::algorithm() {
        return *algorithm_;
    }

    const ISO_9506_MMS_1::MMSString& SemaphoreManagementParameters::algorithm() const {
        return *algorithm_;
    }

    void SemaphoreManagementParameters::algorithm(const ISO_9506_MMS_1::MMSString& vl) {
        algorithm_ = vl;
    }

    void SemaphoreManagementParameters::algorithm(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        algorithm_ = vl;
    }


    // sequence OperatorCommunicationParameters

    OperatorCommunicationParameters::OperatorCommunicationParameters() : input_time_out_() {
    };

    OperatorCommunicationParameters::OperatorCommunicationParameters(const int& arg__input_time_out) :
    input_time_out_(arg__input_time_out) {
    };

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*input_time_out_, 0);
    }

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*input_time_out_, 0);
    }

    int& OperatorCommunicationParameters::input_time_out() {
        return *input_time_out_;
    }

    const int& OperatorCommunicationParameters::input_time_out() const {
        return *input_time_out_;
    }

    void OperatorCommunicationParameters::input_time_out(const int& vl) {
        input_time_out_ = vl;
    }

    void OperatorCommunicationParameters::input_time_out(boost::shared_ptr< int> vl) {
        input_time_out_ = vl;
    }


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

    ErrorParameters::AdditionalDetial_type::AdditionalDetial_type(const int& arg__size,
            const ISO_9506_MMS_1::MMSString& arg__syntax) :
    size_(arg__size),
    syntax_(arg__syntax) {
    };

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*size_, 2);
        ITU_T_EXPLICIT_TAG(*syntax_, 3);
    }

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*size_, 2);
        ITU_T_EXPLICIT_TAG(*syntax_, 3);
    }

    int& ErrorParameters::AdditionalDetial_type::size() {
        return *size_;
    }

    const int& ErrorParameters::AdditionalDetial_type::size() const {
        return *size_;
    }

    void ErrorParameters::AdditionalDetial_type::size(const int& vl) {
        size_ = vl;
    }

    void ErrorParameters::AdditionalDetial_type::size(boost::shared_ptr< int> vl) {
        size_ = vl;
    }

    ISO_9506_MMS_1::MMSString& ErrorParameters::AdditionalDetial_type::syntax() {
        return *syntax_;
    }

    const ISO_9506_MMS_1::MMSString& ErrorParameters::AdditionalDetial_type::syntax() const {
        return *syntax_;
    }

    void ErrorParameters::AdditionalDetial_type::syntax(const ISO_9506_MMS_1::MMSString& vl) {
        syntax_ = vl;
    }

    void ErrorParameters::AdditionalDetial_type::syntax(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        syntax_ = vl;
    }

    template<> void ErrorParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*additionalCode_, 0);
        ITU_T_IMPLICIT_TAG(*additionalDetial_, 1);
    }

    template<> void ErrorParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*additionalCode_, 0);
        ITU_T_IMPLICIT_TAG(*additionalDetial_, 1);
    }

    ISO_9506_MMS_1::MMSString& ErrorParameters::additionalCode() {
        return *additionalCode_;
    }

    const ISO_9506_MMS_1::MMSString& ErrorParameters::additionalCode() const {
        return *additionalCode_;
    }

    void ErrorParameters::additionalCode(const ISO_9506_MMS_1::MMSString& vl) {
        additionalCode_ = vl;
    }

    void ErrorParameters::additionalCode(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        additionalCode_ = vl;
    }

    ErrorParameters::AdditionalDetial_type& ErrorParameters::additionalDetial() {
        return *additionalDetial_;
    }

    const ErrorParameters::AdditionalDetial_type& ErrorParameters::additionalDetial() const {
        return *additionalDetial_;
    }

    void ErrorParameters::additionalDetial(const AdditionalDetial_type& vl) {
        additionalDetial_ = vl;
    }

    void ErrorParameters::additionalDetial(boost::shared_ptr< AdditionalDetial_type> vl) {
        additionalDetial_ = vl;
    }


    // sequence FileManagementParameters

    FileManagementParameters::FileManagementParameters() : fileName_() {
    };

    FileManagementParameters::FileManagementParameters(const ISO_9506_MMS_1::MMSString& arg__fileName) :
    fileName_(arg__fileName) {
    };

    template<> void FileManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*fileName_, 0);
    }

    template<> void FileManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*fileName_, 0);
    }

    ISO_9506_MMS_1::MMSString& FileManagementParameters::fileName() {
        return *fileName_;
    }

    const ISO_9506_MMS_1::MMSString& FileManagementParameters::fileName() const {
        return *fileName_;
    }

    void FileManagementParameters::fileName(const ISO_9506_MMS_1::MMSString& vl) {
        fileName_ = vl;
    }

    void FileManagementParameters::fileName(boost::shared_ptr< ISO_9506_MMS_1::MMSString> vl) {
        fileName_ = vl;
    }


}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

