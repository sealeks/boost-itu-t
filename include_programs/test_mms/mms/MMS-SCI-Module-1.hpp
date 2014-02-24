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

        SCI_Information(const VMD_File& __partOne,
                const Service_and_Parameter_CBBs& __partTwo);

        BOOST_ASN_VALUE_HOLDERH_DECL(partOne, VMD_File);
        BOOST_ASN_VALUE_HOLDERH_DECL(partTwo, Service_and_Parameter_CBBs);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<VMD_File> partOne_;
        value_holder<Service_and_Parameter_CBBs> partTwo_;
    };

    // sequence VMD-File

    struct VMD_File {

        struct selected_Program_Invocation_type;

        enum selected_Program_Invocation_type_enum {

            selected_Program_Invocation_type_null = 0,
            selected_Program_Invocation_type_selectedProgram,
            selected_Program_Invocation_type_noneSelected,
        };

        struct selected_Program_Invocation_type : public BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) {

            selected_Program_Invocation_type() : BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) () {
            }

            template<typename T > selected_Program_Invocation_type(boost::shared_ptr< T> vl, selected_Program_Invocation_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(selectedProgram, Program_Invocation_instance, selected_Program_Invocation_type_selectedProgram);
            BOOST_ASN_VALUE_CHOICE(noneSelected, null_type, selected_Program_Invocation_type_noneSelected);

            BOOST_ASN_ARCHIVE_FUNC;
        };



        typedef std::vector< Access_Control_List_instance > accessControlLists_type;
        typedef std::vector< Domain_instance > domains_type;
        typedef std::vector< Program_Invocation_instance > programInvocations_type;
        typedef std::vector< Unit_Control_instance > unitControls_type;
        typedef std::vector< Unnamed_Variable_instance > unnamedVariables_type;
        typedef std::vector< Named_Variable_instance > namedVariables_type;
        typedef std::vector< Named_Variable_List_instance > namedVariableLists_type;
        typedef std::vector< Named_Type_instance > namedTypes_type;
        typedef std::vector< Data_Exchange_instance > dataExchanges_type;
        typedef std::vector< Semaphore_instance > semaphores_type;
        typedef std::vector< Operator_Station_instance > operatorStations_type;
        typedef std::vector< Event_Condition_instance > eventConditions_type;
        typedef std::vector< Event_Action_instance > eventActions_type;
        typedef std::vector< Event_Enrollment_instance > eventEnrollments_type;
        typedef std::vector< Event_Condition_List_instance > eventConditionLists_type;
        typedef std::vector< Journal_instance > journals_type;

        typedef std::vector< ISO_9506_MMS_1::MMSString > capabilities_type;

        VMD_File();

        VMD_File(const MMS_Environment_1::ApplicationReference& __executiveFunction,
                const ISO_9506_MMS_1::MMSString& __vendorName,
                const ISO_9506_MMS_1::MMSString& __modelName,
                const ISO_9506_MMS_1::MMSString& __revision,
                const oid_type& __abstractSyntaxes,
                const Access_Control_List_instance& __accessControl,
                const MMS_Object_Module_1::LogicalStatus& __logicalStatus,
                const capabilities_type& __capabilities,
                const MMS_Object_Module_1::PhysicalStatus& __physicalStatus,
                const bitstring_type& __local_detail,
                const accessControlLists_type& __accessControlLists,
                const domains_type& __domains,
                const programInvocations_type& __programInvocations,
                const unitControls_type& __unitControls,
                const unnamedVariables_type& __unnamedVariables,
                const namedVariables_type& __namedVariables,
                const namedVariableLists_type& __namedVariableLists,
                const namedTypes_type& __namedTypes,
                const dataExchanges_type& __dataExchanges,
                const semaphores_type& __semaphores,
                const operatorStations_type& __operatorStations,
                const eventConditions_type& __eventConditions,
                const eventActions_type& __eventActions,
                const eventEnrollments_type& __eventEnrollments,
                const eventConditionLists_type& __eventConditionLists,
                const journals_type& __journals);

        VMD_File(boost::shared_ptr< MMS_Environment_1::ApplicationReference> __executiveFunction,
                boost::shared_ptr< ISO_9506_MMS_1::MMSString> __vendorName,
                boost::shared_ptr< ISO_9506_MMS_1::MMSString> __modelName,
                boost::shared_ptr< ISO_9506_MMS_1::MMSString> __revision,
                boost::shared_ptr< oid_type> __abstractSyntaxes,
                boost::shared_ptr< Access_Control_List_instance> __accessControl,
                boost::shared_ptr< MMS_Object_Module_1::LogicalStatus> __logicalStatus,
                boost::shared_ptr< capabilities_type> __capabilities,
                boost::shared_ptr< MMS_Object_Module_1::PhysicalStatus> __physicalStatus,
                boost::shared_ptr< bitstring_type> __local_detail,
                boost::shared_ptr< accessControlLists_type> __accessControlLists,
                boost::shared_ptr< domains_type> __domains,
                boost::shared_ptr< programInvocations_type> __programInvocations,
                boost::shared_ptr< unitControls_type> __unitControls,
                boost::shared_ptr< unnamedVariables_type> __unnamedVariables,
                boost::shared_ptr< namedVariables_type> __namedVariables,
                boost::shared_ptr< namedVariableLists_type> __namedVariableLists,
                boost::shared_ptr< namedTypes_type> __namedTypes,
                boost::shared_ptr< dataExchanges_type> __dataExchanges,
                boost::shared_ptr< semaphores_type> __semaphores,
                boost::shared_ptr< operatorStations_type> __operatorStations,
                boost::shared_ptr< eventConditions_type> __eventConditions,
                boost::shared_ptr< eventActions_type> __eventActions,
                boost::shared_ptr< eventEnrollments_type> __eventEnrollments,
                boost::shared_ptr< eventConditionLists_type> __eventConditionLists,
                boost::shared_ptr< journals_type> __journals,
                boost::shared_ptr< selected_Program_Invocation_type> __selected_Program_Invocation = boost::shared_ptr< selected_Program_Invocation_type>());

        BOOST_ASN_VALUE_HOLDERH_DECL(executiveFunction, MMS_Environment_1::ApplicationReference);
        BOOST_ASN_VALUE_HOLDERH_DECL(vendorName, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(modelName, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(revision, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(abstractSyntaxes, oid_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
        BOOST_ASN_VALUE_HOLDERH_DECL(logicalStatus, MMS_Object_Module_1::LogicalStatus);
        BOOST_ASN_VALUE_HOLDERH_DECL(capabilities, capabilities_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(physicalStatus, MMS_Object_Module_1::PhysicalStatus);
        BOOST_ASN_VALUE_HOLDERH_DECL(local_detail, bitstring_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(accessControlLists, accessControlLists_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(domains, domains_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(programInvocations, programInvocations_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(unitControls, unitControls_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(unnamedVariables, unnamedVariables_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(namedVariables, namedVariables_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(namedVariableLists, namedVariableLists_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(namedTypes, namedTypes_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(dataExchanges, dataExchanges_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(semaphores, semaphores_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(operatorStations, operatorStations_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(eventConditions, eventConditions_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(eventActions, eventActions_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(eventEnrollments, eventEnrollments_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(eventConditionLists, eventConditionLists_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(journals, journals_type);
        BOOST_ASN_VALUE_OPTIONAL_DECL(selected_Program_Invocation, selected_Program_Invocation_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<MMS_Environment_1::ApplicationReference> executiveFunction_;
        value_holder<ISO_9506_MMS_1::MMSString> vendorName_;
        value_holder<ISO_9506_MMS_1::MMSString> modelName_;
        value_holder<ISO_9506_MMS_1::MMSString> revision_;
        value_holder<oid_type> abstractSyntaxes_;
        value_holder<Access_Control_List_instance> accessControl_;
        value_holder<MMS_Object_Module_1::LogicalStatus> logicalStatus_;
        value_holder<capabilities_type> capabilities_;
        value_holder<MMS_Object_Module_1::PhysicalStatus> physicalStatus_;
        value_holder<bitstring_type> local_detail_;
        value_holder<accessControlLists_type> accessControlLists_;
        value_holder<domains_type> domains_;
        value_holder<programInvocations_type> programInvocations_;
        value_holder<unitControls_type> unitControls_;
        value_holder<unnamedVariables_type> unnamedVariables_;
        value_holder<namedVariables_type> namedVariables_;
        value_holder<namedVariableLists_type> namedVariableLists_;
        value_holder<namedTypes_type> namedTypes_;
        value_holder<dataExchanges_type> dataExchanges_;
        value_holder<semaphores_type> semaphores_;
        value_holder<operatorStations_type> operatorStations_;
        value_holder<eventConditions_type> eventConditions_;
        value_holder<eventActions_type> eventActions_;
        value_holder<eventEnrollments_type> eventEnrollments_;
        value_holder<eventConditionLists_type> eventConditionLists_;
        value_holder<journals_type> journals_;
        boost::shared_ptr<selected_Program_Invocation_type> selected_Program_Invocation_; // after extention
    };

    // sequence Access-Control-List-instance

    struct Access_Control_List_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Access_Control_List_instance > accessControlLists_type;
                typedef std::vector< Domain_instance > domains_type;
                typedef std::vector< Program_Invocation_instance > programInvocations_type;
                typedef std::vector< Unit_Control_instance > unitControls_type;
                typedef std::vector< Unnamed_Variable_instance > unnamedVariables_type;
                typedef std::vector< Named_Variable_instance > namedVariables_type;
                typedef std::vector< Named_Variable_List_instance > namedVariableLists_type;
                typedef std::vector< Named_Type_instance > namedTypes_type;
                typedef std::vector< Data_Exchange_instance > dataExchanges_type;
                typedef std::vector< Semaphore_instance > semaphores_type;
                typedef std::vector< Operator_Station_instance > operatorStations_type;
                typedef std::vector< Event_Condition_instance > eventConditions_type;
                typedef std::vector< Event_Action_instance > eventActions_type;
                typedef std::vector< Event_Enrollment_instance > eventEnrollments_type;
                typedef std::vector< Journal_instance > journals_type;
                typedef std::vector< Event_Condition_List_instance > eventConditionLists_type;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const accessControlLists_type& __accessControlLists,
                        const domains_type& __domains,
                        const programInvocations_type& __programInvocations,
                        const unitControls_type& __unitControls,
                        const unnamedVariables_type& __unnamedVariables,
                        const namedVariables_type& __namedVariables,
                        const namedVariableLists_type& __namedVariableLists,
                        const namedTypes_type& __namedTypes,
                        const dataExchanges_type& __dataExchanges,
                        const semaphores_type& __semaphores,
                        const operatorStations_type& __operatorStations,
                        const eventConditions_type& __eventConditions,
                        const eventActions_type& __eventActions,
                        const eventEnrollments_type& __eventEnrollments,
                        const journals_type& __journals);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __readAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __storeAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __writeAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __loadAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __executeAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __deleteAccessCondition,
                        boost::shared_ptr< MMS_Object_Module_1::AccessCondition> __editAccessCondition,
                        boost::shared_ptr< accessControlLists_type> __accessControlLists,
                        boost::shared_ptr< domains_type> __domains,
                        boost::shared_ptr< programInvocations_type> __programInvocations,
                        boost::shared_ptr< unitControls_type> __unitControls,
                        boost::shared_ptr< unnamedVariables_type> __unnamedVariables,
                        boost::shared_ptr< namedVariables_type> __namedVariables,
                        boost::shared_ptr< namedVariableLists_type> __namedVariableLists,
                        boost::shared_ptr< namedTypes_type> __namedTypes,
                        boost::shared_ptr< dataExchanges_type> __dataExchanges,
                        boost::shared_ptr< semaphores_type> __semaphores,
                        boost::shared_ptr< operatorStations_type> __operatorStations,
                        boost::shared_ptr< eventConditions_type> __eventConditions,
                        boost::shared_ptr< eventActions_type> __eventActions,
                        boost::shared_ptr< eventEnrollments_type> __eventEnrollments,
                        boost::shared_ptr< journals_type> __journals,
                        boost::shared_ptr< eventConditionLists_type> __eventConditionLists = boost::shared_ptr< eventConditionLists_type>());

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_OPTIONAL_DECL(readAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_OPTIONAL_DECL(storeAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_OPTIONAL_DECL(writeAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_OPTIONAL_DECL(loadAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_OPTIONAL_DECL(executeAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_OPTIONAL_DECL(deleteAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_OPTIONAL_DECL(editAccessCondition, MMS_Object_Module_1::AccessCondition);
                BOOST_ASN_VALUE_HOLDERH_DECL(accessControlLists, accessControlLists_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(domains, domains_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(programInvocations, programInvocations_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(unitControls, unitControls_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(unnamedVariables, unnamedVariables_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(namedVariables, namedVariables_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(namedVariableLists, namedVariableLists_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(namedTypes, namedTypes_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(dataExchanges, dataExchanges_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(semaphores, semaphores_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(operatorStations, operatorStations_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventConditions, eventConditions_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventActions, eventActions_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventEnrollments, eventEnrollments_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(journals, journals_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(eventConditionLists, eventConditionLists_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> readAccessCondition_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> storeAccessCondition_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> writeAccessCondition_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> loadAccessCondition_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> executeAccessCondition_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> deleteAccessCondition_;
                boost::shared_ptr<MMS_Object_Module_1::AccessCondition> editAccessCondition_;
                value_holder<accessControlLists_type> accessControlLists_;
                value_holder<domains_type> domains_;
                value_holder<programInvocations_type> programInvocations_;
                value_holder<unitControls_type> unitControls_;
                value_holder<unnamedVariables_type> unnamedVariables_;
                value_holder<namedVariables_type> namedVariables_;
                value_holder<namedVariableLists_type> namedVariableLists_;
                value_holder<namedTypes_type> namedTypes_;
                value_holder<dataExchanges_type> dataExchanges_;
                value_holder<semaphores_type> semaphores_;
                value_holder<operatorStations_type> operatorStations_;
                value_holder<eventConditions_type> eventConditions_;
                value_holder<eventActions_type> eventActions_;
                value_holder<eventEnrollments_type> eventEnrollments_;
                value_holder<journals_type> journals_;
                boost::shared_ptr<eventConditionLists_type> eventConditionLists_; // after extention
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Access_Control_List_instance();

        Access_Control_List_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Domain-instance

    struct Domain_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Program_Invocation_instance > programInvocations_type;
                typedef std::vector< Named_Variable_instance > namedVariables_type;
                typedef std::vector< Named_Variable_List_instance > namedVariableLists_type;
                typedef std::vector< Named_Type_instance > namedTypes_type;
                typedef std::vector< Event_Condition_instance > eventConditions_type;
                typedef std::vector< Event_Action_instance > eventActions_type;
                typedef std::vector< Event_Enrollment_instance > eventEnrollments_type;
                typedef std::vector< Event_Condition_List_instance > eventConditionLists_type;

                typedef std::vector< ISO_9506_MMS_1::MMSString > capabilities_type;

                details_type();

                details_type(const capabilities_type& __capabilities,
                        const MMS_Object_Module_1::DomainState& __state,
                        const Access_Control_List_instance& __accessControl,
                        const bool& __sharable,
                        const programInvocations_type& __programInvocations,
                        const namedVariables_type& __namedVariables,
                        const namedVariableLists_type& __namedVariableLists,
                        const namedTypes_type& __namedTypes,
                        const eventConditions_type& __eventConditions,
                        const eventActions_type& __eventActions,
                        const eventEnrollments_type& __eventEnrollments,
                        const eventConditionLists_type& __eventConditionLists);

                BOOST_ASN_VALUE_HOLDERH_DECL(capabilities, capabilities_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(state, MMS_Object_Module_1::DomainState);
                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(sharable, bool);
                BOOST_ASN_VALUE_HOLDERH_DECL(programInvocations, programInvocations_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(namedVariables, namedVariables_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(namedVariableLists, namedVariableLists_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(namedTypes, namedTypes_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventConditions, eventConditions_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventActions, eventActions_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventEnrollments, eventEnrollments_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventConditionLists, eventConditionLists_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<capabilities_type> capabilities_;
                value_holder<MMS_Object_Module_1::DomainState> state_;
                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<bool> sharable_;
                value_holder<programInvocations_type> programInvocations_;
                value_holder<namedVariables_type> namedVariables_;
                value_holder<namedVariableLists_type> namedVariableLists_;
                value_holder<namedTypes_type> namedTypes_;
                value_holder<eventConditions_type> eventConditions_;
                value_holder<eventActions_type> eventActions_;
                value_holder<eventEnrollments_type> eventEnrollments_;
                value_holder<eventConditionLists_type> eventConditionLists_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Domain_instance();

        Domain_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Program-Invocation-instance

    struct Program_Invocation_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Domain_instance > domains_type;
                typedef std::vector< Access_Control_List_instance > accessControl_type;
                typedef std::vector< Event_Condition_instance > eventCondition_type;
                typedef std::vector< Event_Action_instance > eventAction_type;
                typedef std::vector< Event_Enrollment_instance > eventEnrollment_type;
                typedef std::vector< Program_Invocation_instance > controlled_Program_Invocations_type;


                details_type();

                details_type(const MMS_Object_Module_1::ProgramInvocationState& __programInvocationState,
                        const domains_type& __domains,
                        const accessControl_type& __accessControl,
                        const bool& __reusable,
                        const bool& __monitor,
                        const ISO_9506_MMS_1::MMSString& __executionArgument);

                details_type(boost::shared_ptr< MMS_Object_Module_1::ProgramInvocationState> __programInvocationState,
                        boost::shared_ptr< domains_type> __domains,
                        boost::shared_ptr< accessControl_type> __accessControl,
                        boost::shared_ptr< bool> __reusable,
                        boost::shared_ptr< bool> __monitor,
                        boost::shared_ptr< eventCondition_type> __eventCondition,
                        boost::shared_ptr< eventAction_type> __eventAction,
                        boost::shared_ptr< eventEnrollment_type> __eventEnrollment,
                        boost::shared_ptr< ISO_9506_MMS_1::MMSString> __executionArgument,
                        boost::shared_ptr< MMS_Object_Module_1::Control_State> __control = boost::shared_ptr< MMS_Object_Module_1::Control_State>(),
                        boost::shared_ptr< Program_Invocation_instance> __controlling_Program_Invocation = boost::shared_ptr< Program_Invocation_instance>(),
                        boost::shared_ptr< controlled_Program_Invocations_type> __controlled_Program_Invocations = boost::shared_ptr< controlled_Program_Invocations_type>());

                BOOST_ASN_VALUE_HOLDERH_DECL(programInvocationState, MMS_Object_Module_1::ProgramInvocationState);
                BOOST_ASN_VALUE_HOLDERH_DECL(domains, domains_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, accessControl_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(reusable, bool);
                BOOST_ASN_VALUE_HOLDERH_DECL(monitor, bool);
                BOOST_ASN_VALUE_OPTIONAL_DECL(eventCondition, eventCondition_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(eventAction, eventAction_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(eventEnrollment, eventEnrollment_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(executionArgument, ISO_9506_MMS_1::MMSString);
                BOOST_ASN_VALUE_OPTIONAL_DECL(control, MMS_Object_Module_1::Control_State);
                BOOST_ASN_VALUE_OPTIONAL_DECL(controlling_Program_Invocation, Program_Invocation_instance);
                BOOST_ASN_VALUE_OPTIONAL_DECL(controlled_Program_Invocations, controlled_Program_Invocations_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<MMS_Object_Module_1::ProgramInvocationState> programInvocationState_;
                value_holder<domains_type> domains_;
                value_holder<accessControl_type> accessControl_;
                value_holder<bool> reusable_;
                value_holder<bool> monitor_;
                boost::shared_ptr<eventCondition_type> eventCondition_;
                boost::shared_ptr<eventAction_type> eventAction_;
                boost::shared_ptr<eventEnrollment_type> eventEnrollment_;
                value_holder<ISO_9506_MMS_1::MMSString> executionArgument_;
                boost::shared_ptr<MMS_Object_Module_1::Control_State> control_; // after extention
                boost::shared_ptr<Program_Invocation_instance> controlling_Program_Invocation_; // after extention
                boost::shared_ptr<controlled_Program_Invocations_type> controlled_Program_Invocations_; // after extention
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Program_Invocation_instance();

        Program_Invocation_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Unit-Control-instance

    struct Unit_Control_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Domain_instance > domains_type;
                typedef std::vector< Program_Invocation_instance > programInvocations_type;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const domains_type& __domains,
                        const programInvocations_type& __programInvocations);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(domains, domains_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(programInvocations, programInvocations_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<domains_type> domains_;
                value_holder<programInvocations_type> programInvocations_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Unit_Control_instance();

        Unit_Control_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Unnamed-Variable-instance

    struct Unnamed_Variable_instance {

        Unnamed_Variable_instance();

        Unnamed_Variable_instance(const MMS_Object_Module_1::Address& __address,
                const Access_Control_List_instance& __accessControl,
                const MMS_Object_Module_1::TypeDescription& __typeDescription);

        BOOST_ASN_VALUE_HOLDERH_DECL(address, MMS_Object_Module_1::Address);
        BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
        BOOST_ASN_VALUE_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<MMS_Object_Module_1::Address> address_;
        value_holder<Access_Control_List_instance> accessControl_;
        value_holder<MMS_Object_Module_1::TypeDescription> typeDescription_;
    };

    // sequence Named-Variable-instance

    struct Named_Variable_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const MMS_Object_Module_1::TypeDescription& __typeDescription);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::TypeDescription> __typeDescription,
                        boost::shared_ptr< MMS_Object_Module_1::Address> __address,
                        boost::shared_ptr< visiblestring_type> __meaning);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
                BOOST_ASN_VALUE_OPTIONAL_DECL(address, MMS_Object_Module_1::Address);
                BOOST_ASN_VALUE_OPTIONAL_DECL(meaning, visiblestring_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<MMS_Object_Module_1::TypeDescription> typeDescription_;
                boost::shared_ptr<MMS_Object_Module_1::Address> address_;
                boost::shared_ptr<visiblestring_type> meaning_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Named_Variable_instance();

        Named_Variable_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Named-Variable-List-instance

    struct Named_Variable_List_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Variable_List_Item_instance > listOfVariables_type;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const listOfVariables_type& __listOfVariables);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(listOfVariables, listOfVariables_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<listOfVariables_type> listOfVariables_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Named_Variable_List_instance();

        Named_Variable_List_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Variable-List-Item-instance

    struct Variable_List_Item_instance {

        Variable_List_Item_instance();

        Variable_List_Item_instance(boost::shared_ptr< Unnamed_Variable_instance> __unnamedItem,
                boost::shared_ptr< Named_Variable_instance> __namedItem,
                boost::shared_ptr< ISO_9506_MMS_1::AlternateAccess> __alternateAccess);

        BOOST_ASN_VALUE_OPTIONAL_DECL(unnamedItem, Unnamed_Variable_instance);
        BOOST_ASN_VALUE_OPTIONAL_DECL(namedItem, Named_Variable_instance);
        BOOST_ASN_VALUE_OPTIONAL_DECL(alternateAccess, ISO_9506_MMS_1::AlternateAccess);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<Unnamed_Variable_instance> unnamedItem_;
        boost::shared_ptr<Named_Variable_instance> namedItem_;
        boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess> alternateAccess_;
    };

    // sequence Named-Type-instance

    struct Named_Type_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const MMS_Object_Module_1::TypeDescription& __typeDescription);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::TypeDescription> __typeDescription,
                        boost::shared_ptr< visiblestring_type> __meaning);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(typeDescription, MMS_Object_Module_1::TypeDescription);
                BOOST_ASN_VALUE_OPTIONAL_DECL(meaning, visiblestring_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<MMS_Object_Module_1::TypeDescription> typeDescription_;
                boost::shared_ptr<visiblestring_type> meaning_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Named_Type_instance();

        Named_Type_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Data-Exchange-instance

    struct Data_Exchange_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< MMS_Object_Module_1::TypeDescription > request_type;
                typedef std::vector< MMS_Object_Module_1::TypeDescription > response_type;

                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const request_type& __request,
                        const response_type& __response,
                        const bool& __linked);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< request_type> __request,
                        boost::shared_ptr< response_type> __response,
                        boost::shared_ptr< bool> __linked,
                        boost::shared_ptr< Program_Invocation_instance> __programInvocation);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(request, request_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(response, response_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(linked, bool);
                BOOST_ASN_VALUE_OPTIONAL_DECL(programInvocation, Program_Invocation_instance);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<request_type> request_;
                value_holder<response_type> response_;
                value_holder<bool> linked_;
                boost::shared_ptr<Program_Invocation_instance> programInvocation_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Data_Exchange_instance();

        Data_Exchange_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Semaphore-instance

    struct Semaphore_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< visiblestring_type > namedTokens_type;

                static const enumerated_type classV_token;
                static const enumerated_type classV_pool;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const enumerated_type& __classV,
                        const Event_Condition_instance& __eventCondition);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< enumerated_type> __classV,
                        boost::shared_ptr< int> __numberOfTokens,
                        boost::shared_ptr< namedTokens_type> __namedTokens,
                        boost::shared_ptr< Event_Condition_instance> __eventCondition);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(classV, enumerated_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(numberOfTokens, int);
                BOOST_ASN_VALUE_OPTIONAL_DECL(namedTokens, namedTokens_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventCondition, Event_Condition_instance);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<enumerated_type> classV_;
                boost::shared_ptr<int> numberOfTokens_;
                boost::shared_ptr<namedTokens_type> namedTokens_;
                value_holder<Event_Condition_instance> eventCondition_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Semaphore_instance();

        Semaphore_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Operator-Station-instance

    struct Operator_Station_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                static const enumerated_type stationType_entry;
                static const enumerated_type stationType_display;
                static const enumerated_type stationType_entry_display;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const enumerated_type& __stationType);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(stationType, enumerated_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<enumerated_type> stationType_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Operator_Station_instance();

        Operator_Station_instance(const ISO_9506_MMS_1::Identifier& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Identifier> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Event-Condition-instance

    struct Event_Condition_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                struct monitoredVariable_type;
                struct displayEnhancement_type;
                struct group_Priority_Override_type;

                enum monitoredVariable_type_enum {

                    monitoredVariable_type_null = 0,
                    monitoredVariable_type_named,
                    monitoredVariable_type_unnamed,
                    monitoredVariable_type_unspecified,
                };

                struct monitoredVariable_type : public BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) {

                    monitoredVariable_type() : BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) () {
                    }

                    template<typename T > monitoredVariable_type(boost::shared_ptr< T> vl, monitoredVariable_type_enum enm) :
                            BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    BOOST_ASN_VALUE_CHOICE(named, Named_Variable_instance, monitoredVariable_type_named);
                    BOOST_ASN_VALUE_CHOICE(unnamed, Unnamed_Variable_instance, monitoredVariable_type_unnamed);
                    BOOST_ASN_VALUE_CHOICE(unspecified, null_type, monitoredVariable_type_unspecified);

                    BOOST_ASN_ARCHIVE_FUNC;
                };

                enum displayEnhancement_type_enum {

                    displayEnhancement_type_null = 0,
                    displayEnhancement_type_text,
                    displayEnhancement_type_number,
                    displayEnhancement_type_none,
                };

                struct displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {

                    displayEnhancement_type() : BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) () {
                    }

                    template<typename T > displayEnhancement_type(boost::shared_ptr< T> vl, displayEnhancement_type_enum enm) :
                            BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    BOOST_ASN_VALUE_CHOICE(text, ISO_9506_MMS_1::MMSString, displayEnhancement_type_text);
                    BOOST_ASN_VALUE_CHOICE(number, int, displayEnhancement_type_number);
                    BOOST_ASN_VALUE_CHOICE(none, null_type, displayEnhancement_type_none);

                    BOOST_ASN_ARCHIVE_FUNC;
                };

                enum group_Priority_Override_type_enum {

                    group_Priority_Override_type_null = 0,
                    group_Priority_Override_type_priority,
                    group_Priority_Override_type_undefined,
                };

                struct group_Priority_Override_type : public BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) {

                    group_Priority_Override_type() : BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) () {
                    }

                    template<typename T > group_Priority_Override_type(boost::shared_ptr< T> vl, group_Priority_Override_type_enum enm) :
                            BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    BOOST_ASN_VALUE_CHOICE(priority, MMS_Object_Module_1::Priority, group_Priority_Override_type_priority);
                    BOOST_ASN_VALUE_CHOICE(undefined, null_type, group_Priority_Override_type_undefined);

                    BOOST_ASN_ARCHIVE_FUNC;
                };



                typedef std::vector< Event_Enrollment_instance > eventEnrollments_type;
                typedef std::vector< Event_Condition_List_instance > referencingEventConditionLists_type;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const MMS_Object_Module_1::EC_Class& __ecClass,
                        const MMS_Object_Module_1::EC_State& __ecState,
                        const MMS_Object_Module_1::Priority& __priority,
                        const MMS_Object_Module_1::Severity& __severity,
                        const eventEnrollments_type& __eventEnrollments);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::EC_Class> __ecClass,
                        boost::shared_ptr< MMS_Object_Module_1::EC_State> __ecState,
                        boost::shared_ptr< MMS_Object_Module_1::Priority> __priority,
                        boost::shared_ptr< MMS_Object_Module_1::Severity> __severity,
                        boost::shared_ptr< eventEnrollments_type> __eventEnrollments,
                        boost::shared_ptr< bool> __enabled,
                        boost::shared_ptr< bool> __alarmSummaryReports,
                        boost::shared_ptr< monitoredVariable_type> __monitoredVariable,
                        boost::shared_ptr< int> __evaluationInterval,
                        boost::shared_ptr< displayEnhancement_type> __displayEnhancement = boost::shared_ptr< displayEnhancement_type>(),
                        boost::shared_ptr< group_Priority_Override_type> __group_Priority_Override = boost::shared_ptr< group_Priority_Override_type>(),
                        boost::shared_ptr< referencingEventConditionLists_type> __referencingEventConditionLists = boost::shared_ptr< referencingEventConditionLists_type>());

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(ecClass, MMS_Object_Module_1::EC_Class);
                BOOST_ASN_VALUE_HOLDERH_DECL(ecState, MMS_Object_Module_1::EC_State);
                BOOST_ASN_VALUE_HOLDERH_DECL(priority, MMS_Object_Module_1::Priority);
                BOOST_ASN_VALUE_HOLDERH_DECL(severity, MMS_Object_Module_1::Severity);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventEnrollments, eventEnrollments_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(enabled, bool);
                BOOST_ASN_VALUE_OPTIONAL_DECL(alarmSummaryReports, bool);
                BOOST_ASN_VALUE_OPTIONAL_DECL(monitoredVariable, monitoredVariable_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(evaluationInterval, int);
                BOOST_ASN_VALUE_OPTIONAL_DECL(displayEnhancement, displayEnhancement_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(group_Priority_Override, group_Priority_Override_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(referencingEventConditionLists, referencingEventConditionLists_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<MMS_Object_Module_1::EC_Class> ecClass_;
                value_holder<MMS_Object_Module_1::EC_State> ecState_;
                value_holder<MMS_Object_Module_1::Priority> priority_;
                value_holder<MMS_Object_Module_1::Severity> severity_;
                value_holder<eventEnrollments_type> eventEnrollments_;
                boost::shared_ptr<bool> enabled_;
                boost::shared_ptr<bool> alarmSummaryReports_;
                boost::shared_ptr<monitoredVariable_type> monitoredVariable_;
                boost::shared_ptr<int> evaluationInterval_;
                boost::shared_ptr<displayEnhancement_type> displayEnhancement_; // after extention
                boost::shared_ptr<group_Priority_Override_type> group_Priority_Override_; // after extention
                boost::shared_ptr<referencingEventConditionLists_type> referencingEventConditionLists_; // after extention
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Event_Condition_instance();

        Event_Condition_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Event-Action-instance

    struct Event_Action_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Event_Enrollment_instance > eventEnrollments_type;

                typedef std::vector< MMS_Object_Module_1::Modifier > modifiers_type;

                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const ISO_9506_MMS_1::ConfirmedServiceRequest& __confirmedServiceRequest,
                        const modifiers_type& __modifiers,
                        const eventEnrollments_type& __eventEnrollments);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(confirmedServiceRequest, ISO_9506_MMS_1::ConfirmedServiceRequest);
                BOOST_ASN_VALUE_HOLDERH_DECL(modifiers, modifiers_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventEnrollments, eventEnrollments_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<ISO_9506_MMS_1::ConfirmedServiceRequest> confirmedServiceRequest_;
                value_holder<modifiers_type> modifiers_;
                value_holder<eventEnrollments_type> eventEnrollments_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Event_Action_instance();

        Event_Action_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Event-Enrollment-instance

    struct Event_Enrollment_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                struct remainingDelay_type;
                struct displayEnhancement_type;

                enum remainingDelay_type_enum {

                    remainingDelay_type_null = 0,
                    remainingDelay_type_time,
                    remainingDelay_type_forever,
                };

                struct remainingDelay_type : public BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) {

                    remainingDelay_type() : BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) () {
                    }

                    template<typename T > remainingDelay_type(boost::shared_ptr< T> vl, remainingDelay_type_enum enm) :
                            BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    BOOST_ASN_VALUE_CHOICE(time, int, remainingDelay_type_time);
                    BOOST_ASN_VALUE_CHOICE(forever, null_type, remainingDelay_type_forever);

                    BOOST_ASN_ARCHIVE_FUNC;
                };

                enum displayEnhancement_type_enum {

                    displayEnhancement_type_null = 0,
                    displayEnhancement_type_text,
                    displayEnhancement_type_number,
                    displayEnhancement_type_none,
                };

                struct displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {

                    displayEnhancement_type() : BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) () {
                    }

                    template<typename T > displayEnhancement_type(boost::shared_ptr< T> vl, displayEnhancement_type_enum enm) :
                            BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) (vl, static_cast<int> (enm)) {
                    }

                    BOOST_ASN_VALUE_CHOICE(text, ISO_9506_MMS_1::MMSString, displayEnhancement_type_text);
                    BOOST_ASN_VALUE_CHOICE(number, int, displayEnhancement_type_number);
                    BOOST_ASN_VALUE_CHOICE(none, null_type, displayEnhancement_type_none);

                    BOOST_ASN_ARCHIVE_FUNC;
                };


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const MMS_Object_Module_1::EE_Class& __eeClass,
                        const Event_Condition_instance& __eventCondition,
                        const MMS_Object_Module_1::Transitions& __ecTransitions);

                details_type(boost::shared_ptr< Access_Control_List_instance> __accessControl,
                        boost::shared_ptr< MMS_Object_Module_1::EE_Class> __eeClass,
                        boost::shared_ptr< Event_Condition_instance> __eventCondition,
                        boost::shared_ptr< MMS_Object_Module_1::Transitions> __ecTransitions,
                        boost::shared_ptr< remainingDelay_type> __remainingDelay,
                        boost::shared_ptr< Event_Action_instance> __eventAction,
                        boost::shared_ptr< MMS_Object_Module_1::EE_Duration> __duration,
                        boost::shared_ptr< MMS_Environment_1::ApplicationReference> __clientApplication,
                        boost::shared_ptr< MMS_Object_Module_1::AlarmAckRule> __aaRule,
                        boost::shared_ptr< displayEnhancement_type> __displayEnhancement = boost::shared_ptr< displayEnhancement_type>());

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(eeClass, MMS_Object_Module_1::EE_Class);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventCondition, Event_Condition_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(ecTransitions, MMS_Object_Module_1::Transitions);
                BOOST_ASN_VALUE_OPTIONAL_DECL(remainingDelay, remainingDelay_type);
                BOOST_ASN_VALUE_OPTIONAL_DECL(eventAction, Event_Action_instance);
                BOOST_ASN_VALUE_OPTIONAL_DECL(duration, MMS_Object_Module_1::EE_Duration);
                BOOST_ASN_VALUE_OPTIONAL_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
                BOOST_ASN_VALUE_OPTIONAL_DECL(aaRule, MMS_Object_Module_1::AlarmAckRule);
                BOOST_ASN_VALUE_OPTIONAL_DECL(displayEnhancement, displayEnhancement_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<MMS_Object_Module_1::EE_Class> eeClass_;
                value_holder<Event_Condition_instance> eventCondition_;
                value_holder<MMS_Object_Module_1::Transitions> ecTransitions_;
                boost::shared_ptr<remainingDelay_type> remainingDelay_;
                boost::shared_ptr<Event_Action_instance> eventAction_;
                boost::shared_ptr<MMS_Object_Module_1::EE_Duration> duration_;
                boost::shared_ptr<MMS_Environment_1::ApplicationReference> clientApplication_;
                boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> aaRule_;
                boost::shared_ptr<displayEnhancement_type> displayEnhancement_; // after extention
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Event_Enrollment_instance();

        Event_Enrollment_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Event-Condition-List-instance

    struct Event_Condition_List_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Event_Condition_instance > eventConditions_type;
                typedef std::vector< Event_Condition_List_instance > eventConditionLists_type;
                typedef std::vector< Event_Condition_List_instance > referencingEventConditionLists_type;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const eventConditions_type& __eventConditions,
                        const eventConditionLists_type& __eventConditionLists,
                        const referencingEventConditionLists_type& __referencingEventConditionLists);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventConditions, eventConditions_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(eventConditionLists, eventConditionLists_type);
                BOOST_ASN_VALUE_HOLDERH_DECL(referencingEventConditionLists, referencingEventConditionLists_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<eventConditions_type> eventConditions_;
                value_holder<eventConditionLists_type> eventConditionLists_;
                value_holder<referencingEventConditionLists_type> referencingEventConditionLists_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Event_Condition_List_instance();

        Event_Condition_List_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Journal-instance

    struct Journal_instance {

        struct definition_type;

        enum definition_type_enum {

            definition_type_null = 0,
            definition_type_reference,
            definition_type_details,
        };

        struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


            struct details_type;

            struct details_type {

                typedef std::vector< Journal_Entry_instance > entries_type;


                details_type();

                details_type(const Access_Control_List_instance& __accessControl,
                        const entries_type& __entries);

                BOOST_ASN_VALUE_HOLDERH_DECL(accessControl, Access_Control_List_instance);
                BOOST_ASN_VALUE_HOLDERH_DECL(entries, entries_type);

                BOOST_ASN_ARCHIVE_FUNC;

            private:

                value_holder<Access_Control_List_instance> accessControl_;
                value_holder<entries_type> entries_;
            };

            definition_type() : BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {
            }

            template<typename T > definition_type(boost::shared_ptr< T> vl, definition_type_enum enm) :
                    BOOST_ASN_CHOICE_STRUCT(definition_type_enum) (vl, static_cast<int> (enm)) {
            }

            BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
            BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

            BOOST_ASN_ARCHIVE_FUNC;
        };


        Journal_instance();

        Journal_instance(const ISO_9506_MMS_1::ObjectName& __name,
                const definition_type& __definition);

        BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(definition, definition_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> name_;
        value_holder<definition_type> definition_;
    };

    // sequence Journal-Entry-instance

    struct Journal_Entry_instance {

        struct eventTransitionRecord_type;
        struct journalVariables_type_sequence_of;

        struct eventTransitionRecord_type {

            eventTransitionRecord_type();

            eventTransitionRecord_type(const ISO_9506_MMS_1::ObjectName& __name,
                    const MMS_Object_Module_1::EC_State& __currentState);

            BOOST_ASN_VALUE_HOLDERH_DECL(name, ISO_9506_MMS_1::ObjectName);
            BOOST_ASN_VALUE_HOLDERH_DECL(currentState, MMS_Object_Module_1::EC_State);

            BOOST_ASN_ARCHIVE_FUNC;

        private:

            value_holder<ISO_9506_MMS_1::ObjectName> name_;
            value_holder<MMS_Object_Module_1::EC_State> currentState_;
        };

        struct journalVariables_type_sequence_of {

            journalVariables_type_sequence_of();

            journalVariables_type_sequence_of(const ISO_9506_MMS_1::MMS255String& __variableTag,
                    const ISO_9506_MMS_1::Data& __valueSpecification);

            BOOST_ASN_VALUE_HOLDERH_DECL(variableTag, ISO_9506_MMS_1::MMS255String);
            BOOST_ASN_VALUE_HOLDERH_DECL(valueSpecification, ISO_9506_MMS_1::Data);

            BOOST_ASN_ARCHIVE_FUNC;

        private:

            value_holder<ISO_9506_MMS_1::MMS255String> variableTag_;
            value_holder<ISO_9506_MMS_1::Data> valueSpecification_;
        };



        typedef std::vector< journalVariables_type_sequence_of > journalVariables_type;

        static const enumerated_type informationType_annotation;
        static const enumerated_type informationType_event_data;
        static const enumerated_type informationType_data;


        Journal_Entry_instance();

        Journal_Entry_instance(const Journal_instance& __journal,
                const octetstring_type& __entry,
                const MMS_Environment_1::ApplicationReference& __clientApplication,
                const ISO_9506_MMS_1::TimeOfDay& __timeStamp,
                const int& __orderOfReceipt,
                const enumerated_type& __informationType);

        Journal_Entry_instance(boost::shared_ptr< Journal_instance> __journal,
                boost::shared_ptr< octetstring_type> __entry,
                boost::shared_ptr< MMS_Environment_1::ApplicationReference> __clientApplication,
                boost::shared_ptr< ISO_9506_MMS_1::TimeOfDay> __timeStamp,
                boost::shared_ptr< int> __orderOfReceipt,
                boost::shared_ptr< enumerated_type> __informationType,
                boost::shared_ptr< ISO_9506_MMS_1::MMS255String> __textComment,
                boost::shared_ptr< eventTransitionRecord_type> __eventTransitionRecord,
                boost::shared_ptr< journalVariables_type> __journalVariables);

        BOOST_ASN_VALUE_HOLDERH_DECL(journal, Journal_instance);
        BOOST_ASN_VALUE_HOLDERH_DECL(entry, octetstring_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(clientApplication, MMS_Environment_1::ApplicationReference);
        BOOST_ASN_VALUE_HOLDERH_DECL(timeStamp, ISO_9506_MMS_1::TimeOfDay);
        BOOST_ASN_VALUE_HOLDERH_DECL(orderOfReceipt, int);
        BOOST_ASN_VALUE_HOLDERH_DECL(informationType, enumerated_type);
        BOOST_ASN_VALUE_OPTIONAL_DECL(textComment, ISO_9506_MMS_1::MMS255String);
        BOOST_ASN_VALUE_OPTIONAL_DECL(eventTransitionRecord, eventTransitionRecord_type);
        BOOST_ASN_VALUE_OPTIONAL_DECL(journalVariables, journalVariables_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<Journal_instance> journal_;
        value_holder<octetstring_type> entry_;
        value_holder<MMS_Environment_1::ApplicationReference> clientApplication_;
        value_holder<ISO_9506_MMS_1::TimeOfDay> timeStamp_;
        value_holder<int> orderOfReceipt_;
        value_holder<enumerated_type> informationType_;
        boost::shared_ptr<ISO_9506_MMS_1::MMS255String> textComment_;
        boost::shared_ptr<eventTransitionRecord_type> eventTransitionRecord_;
        boost::shared_ptr<journalVariables_type> journalVariables_;
    };

    // sequence Service-and-Parameter-CBBs

    struct Service_and_Parameter_CBBs {

        Service_and_Parameter_CBBs();

        Service_and_Parameter_CBBs(const MMS_Object_Module_1::ServiceSupportOptions& __services_Client,
                const MMS_Object_Module_1::ServiceSupportOptions& __services_Server,
                const MMS_Object_Module_1::ParameterSupportOptions& __parameters,
                const int& __nest,
                const MMS_Object_Module_1::AdditionalSupportOptions& __extendedServices_Client,
                const MMS_Object_Module_1::AdditionalSupportOptions& __extendedServices_Server,
                const MMS_Object_Module_1::AdditionalCBBOptions& __extendedParameters,
                const GeneralManagementParameters& __generalManagement,
                const VMDSupportParameters& __vMDSupport,
                const DomainManagementParameters& __domainManagement,
                const ProgramInvocationManagementParameters& __programInvocation,
                const VariableAccessParameters& __variableAccess,
                const DataParameters& __dataParameters,
                const SemaphoreManagementParameters& __semaphoreManagement,
                const OperatorCommunicationParameters& __operatorCommunication,
                const ErrorParameters& __errors,
                const FileManagementParameters& __fileManagement);

        BOOST_ASN_VALUE_HOLDERH_DECL(services_Client, MMS_Object_Module_1::ServiceSupportOptions);
        BOOST_ASN_VALUE_HOLDERH_DECL(services_Server, MMS_Object_Module_1::ServiceSupportOptions);
        BOOST_ASN_VALUE_HOLDERH_DECL(parameters, MMS_Object_Module_1::ParameterSupportOptions);
        BOOST_ASN_VALUE_HOLDERH_DECL(nest, int);
        BOOST_ASN_VALUE_HOLDERH_DECL(extendedServices_Client, MMS_Object_Module_1::AdditionalSupportOptions);
        BOOST_ASN_VALUE_HOLDERH_DECL(extendedServices_Server, MMS_Object_Module_1::AdditionalSupportOptions);
        BOOST_ASN_VALUE_HOLDERH_DECL(extendedParameters, MMS_Object_Module_1::AdditionalCBBOptions);
        BOOST_ASN_VALUE_HOLDERH_DECL(generalManagement, GeneralManagementParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(vMDSupport, VMDSupportParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(domainManagement, DomainManagementParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(programInvocation, ProgramInvocationManagementParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(variableAccess, VariableAccessParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(dataParameters, DataParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(semaphoreManagement, SemaphoreManagementParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(operatorCommunication, OperatorCommunicationParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(errors, ErrorParameters);
        BOOST_ASN_VALUE_HOLDERH_DECL(fileManagement, FileManagementParameters);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<MMS_Object_Module_1::ServiceSupportOptions> services_Client_;
        value_holder<MMS_Object_Module_1::ServiceSupportOptions> services_Server_;
        value_holder<MMS_Object_Module_1::ParameterSupportOptions> parameters_;
        value_holder<int> nest_;
        value_holder<MMS_Object_Module_1::AdditionalSupportOptions> extendedServices_Client_;
        value_holder<MMS_Object_Module_1::AdditionalSupportOptions> extendedServices_Server_;
        value_holder<MMS_Object_Module_1::AdditionalCBBOptions> extendedParameters_;
        value_holder<GeneralManagementParameters> generalManagement_;
        value_holder<VMDSupportParameters> vMDSupport_;
        value_holder<DomainManagementParameters> domainManagement_;
        value_holder<ProgramInvocationManagementParameters> programInvocation_;
        value_holder<VariableAccessParameters> variableAccess_;
        value_holder<DataParameters> dataParameters_;
        value_holder<SemaphoreManagementParameters> semaphoreManagement_;
        value_holder<OperatorCommunicationParameters> operatorCommunication_;
        value_holder<ErrorParameters> errors_;
        value_holder<FileManagementParameters> fileManagement_;
    };

    // sequence GeneralManagementParameters

    struct GeneralManagementParameters {

        struct supportForTime_type;

        struct supportForTime_type {

            supportForTime_type();

            supportForTime_type(const bool& __timeOfDay,
                    const bool& __timeSequence);

            BOOST_ASN_VALUE_HOLDERH_DECL(timeOfDay, bool);
            BOOST_ASN_VALUE_HOLDERH_DECL(timeSequence, bool);

            BOOST_ASN_ARCHIVE_FUNC;

        private:

            value_holder<bool> timeOfDay_;
            value_holder<bool> timeSequence_;
        };


        GeneralManagementParameters();

        GeneralManagementParameters(const ISO_9506_MMS_1::MMSString& __localDetail,
                const supportForTime_type& __supportForTime,
                const int& __granularityOfTime);

        BOOST_ASN_VALUE_HOLDERH_DECL(localDetail, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(supportForTime, supportForTime_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(granularityOfTime, int);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> localDetail_;
        value_holder<supportForTime_type> supportForTime_;
        value_holder<int> granularityOfTime_;
    };

    // sequence VMDSupportParameters

    struct VMDSupportParameters {

        VMDSupportParameters();

        VMDSupportParameters(const ISO_9506_MMS_1::MMSString& __localDetail,
                const ISO_9506_MMS_1::MMSString& __extendedDerivation);

        BOOST_ASN_VALUE_HOLDERH_DECL(localDetail, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(extendedDerivation, ISO_9506_MMS_1::MMSString);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> localDetail_;
        value_holder<ISO_9506_MMS_1::MMSString> extendedDerivation_;
    };

    // sequence DomainManagementParameters

    struct DomainManagementParameters {

        typedef std::vector< oid_type > loadDataSyntax_type;


        DomainManagementParameters();

        DomainManagementParameters(const ISO_9506_MMS_1::MMSString& __loadDataOctet,
                const loadDataSyntax_type& __loadDataSyntax,
                const int& __maxUploads);

        BOOST_ASN_VALUE_HOLDERH_DECL(loadDataOctet, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(loadDataSyntax, loadDataSyntax_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(maxUploads, int);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> loadDataOctet_;
        value_holder<loadDataSyntax_type> loadDataSyntax_;
        value_holder<int> maxUploads_;
    };

    // sequence ProgramInvocationManagementParameters

    struct ProgramInvocationManagementParameters {

        typedef std::vector< oid_type > executionArgSyntaxes_type;


        ProgramInvocationManagementParameters();

        ProgramInvocationManagementParameters(const int& __executionArgMaxSize,
                const ISO_9506_MMS_1::MMSString& __executionArgParseRules,
                const executionArgSyntaxes_type& __executionArgSyntaxes,
                const ISO_9506_MMS_1::MMSString& __programLoction,
                const bool& __stepMode);

        BOOST_ASN_VALUE_HOLDERH_DECL(executionArgMaxSize, int);
        BOOST_ASN_VALUE_HOLDERH_DECL(executionArgParseRules, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(executionArgSyntaxes, executionArgSyntaxes_type);
        BOOST_ASN_VALUE_HOLDERH_DECL(programLoction, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(stepMode, bool);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<int> executionArgMaxSize_;
        value_holder<ISO_9506_MMS_1::MMSString> executionArgParseRules_;
        value_holder<executionArgSyntaxes_type> executionArgSyntaxes_;
        value_holder<ISO_9506_MMS_1::MMSString> programLoction_;
        value_holder<bool> stepMode_;
    };

    // sequence VariableAccessParameters

    struct VariableAccessParameters {

        VariableAccessParameters();

        VariableAccessParameters(const ISO_9506_MMS_1::MMSString& __uninterruptibleAccess,
                const bool& __singleMode,
                const bool& __unnamedMode);

        BOOST_ASN_VALUE_HOLDERH_DECL(uninterruptibleAccess, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(singleMode, bool);
        BOOST_ASN_VALUE_HOLDERH_DECL(unnamedMode, bool);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> uninterruptibleAccess_;
        value_holder<bool> singleMode_;
        value_holder<bool> unnamedMode_;
    };

    // sequence DataParameters

    struct DataParameters {

        struct floating_point_type;

        struct floating_point_type {

            floating_point_type();

            floating_point_type(const int& __total,
                    const int& __exponent);

            BOOST_ASN_VALUE_HOLDERH_DECL(total, int);
            BOOST_ASN_VALUE_HOLDERH_DECL(exponent, int);

            BOOST_ASN_ARCHIVE_FUNC;

        private:

            value_holder<int> total_;
            value_holder<int> exponent_;
        };


        DataParameters();

        DataParameters(boost::shared_ptr< int> __bit_string,
                boost::shared_ptr< int> __integer,
                boost::shared_ptr< int> __unsignedV,
                boost::shared_ptr< floating_point_type> __floating_point,
                boost::shared_ptr< int> __octet_string,
                boost::shared_ptr< int> __visible_string,
                boost::shared_ptr< bool> __binary_time,
                boost::shared_ptr< int> __bcd,
                boost::shared_ptr< int> __mmsString);

        BOOST_ASN_VALUE_OPTIONAL_DECL(bit_string, int);
        BOOST_ASN_VALUE_OPTIONAL_DECL(integer, int);
        BOOST_ASN_VALUE_OPTIONAL_DECL(unsignedV, int);
        BOOST_ASN_VALUE_OPTIONAL_DECL(floating_point, floating_point_type);
        BOOST_ASN_VALUE_OPTIONAL_DECL(octet_string, int);
        BOOST_ASN_VALUE_OPTIONAL_DECL(visible_string, int);
        BOOST_ASN_VALUE_OPTIONAL_DECL(binary_time, bool);
        BOOST_ASN_VALUE_OPTIONAL_DECL(bcd, int);
        BOOST_ASN_VALUE_OPTIONAL_DECL(mmsString, int);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<int> bit_string_;
        boost::shared_ptr<int> integer_;
        boost::shared_ptr<int> unsignedV_;
        boost::shared_ptr<floating_point_type> floating_point_;
        boost::shared_ptr<int> octet_string_;
        boost::shared_ptr<int> visible_string_;
        boost::shared_ptr<bool> binary_time_;
        boost::shared_ptr<int> bcd_;
        boost::shared_ptr<int> mmsString_;
    };

    // sequence SemaphoreManagementParameters

    struct SemaphoreManagementParameters {

        SemaphoreManagementParameters();

        SemaphoreManagementParameters(const ISO_9506_MMS_1::MMSString& __algorithm);

        BOOST_ASN_VALUE_HOLDERH_DECL(algorithm, ISO_9506_MMS_1::MMSString);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> algorithm_;
    };

    // sequence OperatorCommunicationParameters

    struct OperatorCommunicationParameters {

        OperatorCommunicationParameters();

        OperatorCommunicationParameters(const int& __input_time_out);

        BOOST_ASN_VALUE_HOLDERH_DECL(input_time_out, int);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<int> input_time_out_;
    };

    // sequence ErrorParameters

    struct ErrorParameters {

        struct additionalDetial_type;

        struct additionalDetial_type {

            additionalDetial_type();

            additionalDetial_type(const int& __size,
                    const ISO_9506_MMS_1::MMSString& __syntax);

            BOOST_ASN_VALUE_HOLDERH_DECL(size, int);
            BOOST_ASN_VALUE_HOLDERH_DECL(syntax, ISO_9506_MMS_1::MMSString);

            BOOST_ASN_ARCHIVE_FUNC;

        private:

            value_holder<int> size_;
            value_holder<ISO_9506_MMS_1::MMSString> syntax_;
        };


        ErrorParameters();

        ErrorParameters(const ISO_9506_MMS_1::MMSString& __additionalCode,
                const additionalDetial_type& __additionalDetial);

        BOOST_ASN_VALUE_HOLDERH_DECL(additionalCode, ISO_9506_MMS_1::MMSString);
        BOOST_ASN_VALUE_HOLDERH_DECL(additionalDetial, additionalDetial_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> additionalCode_;
        value_holder<additionalDetial_type> additionalDetial_;
    };

    // sequence FileManagementParameters

    struct FileManagementParameters {

        FileManagementParameters();

        FileManagementParameters(const ISO_9506_MMS_1::MMSString& __fileName);

        BOOST_ASN_VALUE_HOLDERH_DECL(fileName, ISO_9506_MMS_1::MMSString);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::MMSString> fileName_;
    };

    template<> void SCI_Information::serialize(boost::asn1::x690::output_coder& arch);
    template<> void SCI_Information::serialize(boost::asn1::x690::input_coder& arch);
    template<> void VMD_File::serialize(boost::asn1::x690::output_coder& arch);
    template<> void VMD_File::serialize(boost::asn1::x690::input_coder& arch);
    template<> void VMD_File::selected_Program_Invocation_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void VMD_File::selected_Program_Invocation_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Access_Control_List_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Access_Control_List_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Access_Control_List_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Access_Control_List_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Domain_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Domain_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Domain_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Domain_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Domain_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Domain_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Program_Invocation_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Program_Invocation_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Program_Invocation_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Program_Invocation_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unit_Control_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unit_Control_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unit_Control_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unit_Control_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unit_Control_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unit_Control_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_List_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_List_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Variable_List_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Variable_List_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Type_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Type_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Type_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Type_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Named_Type_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Named_Type_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Data_Exchange_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Data_Exchange_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Data_Exchange_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Data_Exchange_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Semaphore_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Semaphore_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Semaphore_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Semaphore_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Semaphore_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Semaphore_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Operator_Station_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Operator_Station_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Operator_Station_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Operator_Station_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Operator_Station_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Operator_Station_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::monitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::monitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::group_Priority_Override_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_instance::definition_type::details_type::group_Priority_Override_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Action_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Action_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Action_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Action_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Action_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Action_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::details_type::remainingDelay_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::details_type::remainingDelay_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Enrollment_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_List_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_List_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Event_Condition_List_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Event_Condition_List_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Entry_instance::eventTransitionRecord_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Entry_instance::eventTransitionRecord_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Journal_Entry_instance::journalVariables_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Journal_Entry_instance::journalVariables_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::input_coder& arch);
    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void GeneralManagementParameters::supportForTime_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void GeneralManagementParameters::supportForTime_type::serialize(boost::asn1::x690::input_coder& arch);
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
    template<> void DataParameters::floating_point_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void DataParameters::floating_point_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ErrorParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ErrorParameters::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ErrorParameters::additionalDetial_type::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ErrorParameters::additionalDetial_type::serialize(boost::asn1::x690::input_coder& arch);
    template<> void FileManagementParameters::serialize(boost::asn1::x690::output_coder& arch);
    template<> void FileManagementParameters::serialize(boost::asn1::x690::input_coder& arch);
}

BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::VMD_File::selected_Program_Invocation_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Access_Control_List_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Domain_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Program_Invocation_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Unit_Control_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Variable_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Variable_List_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Named_Type_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Data_Exchange_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Semaphore_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Operator_Station_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type::details_type::monitoredVariable_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type::details_type::displayEnhancement_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_instance::definition_type::details_type::group_Priority_Override_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Action_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::definition_type::details_type::remainingDelay_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Enrollment_instance::definition_type::details_type::displayEnhancement_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Event_Condition_List_instance::definition_type)
BOOST_ASN_CHOICE_REGESTRATE(MMS_SCI_Module_1::Journal_instance::definition_type)

#endif  /*___MMS_SCI_MODULE_1 */

