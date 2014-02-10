#ifndef ___MMS_SCI_MODULE_1
#define ___MMS_SCI_MODULE_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {

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
        struct SCI_Information{



            SCI_Information() : partOne(), partTwo() {} 
 
            boost::asn1::value_holder<VMD_File> partOne;
            boost::asn1::value_holder<Service_and_Parameter_CBBs> partTwo;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence VMD-File
        struct VMD_File{


            enum selected_Program_Invocation_type_enum {
                selected_Program_Invocation_type_null = 0, 
                selected_Program_Invocation_type_selectedProgram,
                selected_Program_Invocation_type_noneSelected,}; 
 
            struct selected_Program_Invocation_type : public BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) {



                selected_Program_Invocation_type() :  BOOST_ASN_CHOICE_STRUCT(selected_Program_Invocation_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(selectedProgram, Program_Invocation_instance, selected_Program_Invocation_type_selectedProgram);
                BOOST_ASN_VALUE_CHOICE(noneSelected, null_type, selected_Program_Invocation_type_noneSelected);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 
        typedef std::vector< ISO_9506_MMS_1::MMSString> capabilities_type;
        typedef std::vector< Access_Control_List_instance> accessControlLists_type;
        typedef std::vector< Domain_instance> domains_type;
        typedef std::vector< Program_Invocation_instance> programInvocations_type;
        typedef std::vector< Unit_Control_instance> unitControls_type;
        typedef std::vector< Unnamed_Variable_instance> unnamedVariables_type;
        typedef std::vector< Named_Variable_instance> namedVariables_type;
        typedef std::vector< Named_Variable_List_instance> namedVariableLists_type;
        typedef std::vector< Named_Type_instance> namedTypes_type;
        typedef std::vector< Data_Exchange_instance> dataExchanges_type;
        typedef std::vector< Semaphore_instance> semaphores_type;
        typedef std::vector< Operator_Station_instance> operatorStations_type;
        typedef std::vector< Event_Condition_instance> eventConditions_type;
        typedef std::vector< Event_Action_instance> eventActions_type;
        typedef std::vector< Event_Enrollment_instance> eventEnrollments_type;
        typedef std::vector< Event_Condition_List_instance> eventConditionLists_type;
        typedef std::vector< Journal_instance> journals_type;


            VMD_File() : executiveFunction(), vendorName(), modelName(), revision(), abstractSyntaxes(), accessControl(), logicalStatus(), capabilities(), physicalStatus(), local_detail(), accessControlLists(), domains(), programInvocations(), unitControls(), unnamedVariables(), namedVariables(), namedVariableLists(), namedTypes(), dataExchanges(), semaphores(), operatorStations(), eventConditions(), eventActions(), eventEnrollments(), eventConditionLists(), journals(), selected_Program_Invocation() {} 
 
            boost::asn1::value_holder<MMS_Environment_1::ApplicationReference> executiveFunction;
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> vendorName;
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> modelName;
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> revision;
            boost::asn1::value_holder<oid_type> abstractSyntaxes;
            boost::asn1::value_holder<Access_Control_List_instance> accessControl;
            boost::asn1::value_holder<MMS_Object_Module_1::LogicalStatus> logicalStatus;
            boost::asn1::value_holder<capabilities_type> capabilities;
            boost::asn1::value_holder<MMS_Object_Module_1::PhysicalStatus> physicalStatus;
            boost::asn1::value_holder<bitstring_type> local_detail;
            boost::asn1::value_holder<accessControlLists_type> accessControlLists;
            boost::asn1::value_holder<domains_type> domains;
            boost::asn1::value_holder<programInvocations_type> programInvocations;
            boost::asn1::value_holder<unitControls_type> unitControls;
            boost::asn1::value_holder<unnamedVariables_type> unnamedVariables;
            boost::asn1::value_holder<namedVariables_type> namedVariables;
            boost::asn1::value_holder<namedVariableLists_type> namedVariableLists;
            boost::asn1::value_holder<namedTypes_type> namedTypes;
            boost::asn1::value_holder<dataExchanges_type> dataExchanges;
            boost::asn1::value_holder<semaphores_type> semaphores;
            boost::asn1::value_holder<operatorStations_type> operatorStations;
            boost::asn1::value_holder<eventConditions_type> eventConditions;
            boost::asn1::value_holder<eventActions_type> eventActions;
            boost::asn1::value_holder<eventEnrollments_type> eventEnrollments;
            boost::asn1::value_holder<eventConditionLists_type> eventConditionLists;
            boost::asn1::value_holder<journals_type> journals;
            boost::shared_ptr<selected_Program_Invocation_type> selected_Program_Invocation; // after extention
            BOOST_ASN_VALUE_FUNC_DECLARATE(selected_Program_Invocation_type, selected_Program_Invocation)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Access-Control-List-instance
        struct Access_Control_List_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< Access_Control_List_instance> accessControlLists_type;
                typedef std::vector< Domain_instance> domains_type;
                typedef std::vector< Program_Invocation_instance> programInvocations_type;
                typedef std::vector< Unit_Control_instance> unitControls_type;
                typedef std::vector< Unnamed_Variable_instance> unnamedVariables_type;
                typedef std::vector< Named_Variable_instance> namedVariables_type;
                typedef std::vector< Named_Variable_List_instance> namedVariableLists_type;
                typedef std::vector< Named_Type_instance> namedTypes_type;
                typedef std::vector< Data_Exchange_instance> dataExchanges_type;
                typedef std::vector< Semaphore_instance> semaphores_type;
                typedef std::vector< Operator_Station_instance> operatorStations_type;
                typedef std::vector< Event_Condition_instance> eventConditions_type;
                typedef std::vector< Event_Action_instance> eventActions_type;
                typedef std::vector< Event_Enrollment_instance> eventEnrollments_type;
                typedef std::vector< Journal_instance> journals_type;
                typedef std::vector< Event_Condition_List_instance> eventConditionLists_type;


                    details_type() : accessControl(), accessControlLists(), domains(), programInvocations(), unitControls(), unnamedVariables(), namedVariables(), namedVariableLists(), namedTypes(), dataExchanges(), semaphores(), operatorStations(), eventConditions(), eventActions(), eventEnrollments(), journals(), eventConditionLists() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> readAccessCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> storeAccessCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> writeAccessCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> loadAccessCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> executeAccessCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> deleteAccessCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::AccessCondition> editAccessCondition;
                    boost::asn1::value_holder<accessControlLists_type> accessControlLists;
                    boost::asn1::value_holder<domains_type> domains;
                    boost::asn1::value_holder<programInvocations_type> programInvocations;
                    boost::asn1::value_holder<unitControls_type> unitControls;
                    boost::asn1::value_holder<unnamedVariables_type> unnamedVariables;
                    boost::asn1::value_holder<namedVariables_type> namedVariables;
                    boost::asn1::value_holder<namedVariableLists_type> namedVariableLists;
                    boost::asn1::value_holder<namedTypes_type> namedTypes;
                    boost::asn1::value_holder<dataExchanges_type> dataExchanges;
                    boost::asn1::value_holder<semaphores_type> semaphores;
                    boost::asn1::value_holder<operatorStations_type> operatorStations;
                    boost::asn1::value_holder<eventConditions_type> eventConditions;
                    boost::asn1::value_holder<eventActions_type> eventActions;
                    boost::asn1::value_holder<eventEnrollments_type> eventEnrollments;
                    boost::asn1::value_holder<journals_type> journals;
                    boost::shared_ptr<eventConditionLists_type> eventConditionLists; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(eventConditionLists_type, eventConditionLists)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Access_Control_List_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Domain-instance
        struct Domain_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< ISO_9506_MMS_1::MMSString> capabilities_type;
                typedef std::vector< Program_Invocation_instance> programInvocations_type;
                typedef std::vector< Named_Variable_instance> namedVariables_type;
                typedef std::vector< Named_Variable_List_instance> namedVariableLists_type;
                typedef std::vector< Named_Type_instance> namedTypes_type;
                typedef std::vector< Event_Condition_instance> eventConditions_type;
                typedef std::vector< Event_Action_instance> eventActions_type;
                typedef std::vector< Event_Enrollment_instance> eventEnrollments_type;
                typedef std::vector< Event_Condition_List_instance> eventConditionLists_type;


                    details_type() : capabilities(), state(), accessControl(), sharable(), programInvocations(), namedVariables(), namedVariableLists(), namedTypes(), eventConditions(), eventActions(), eventEnrollments(), eventConditionLists() {} 
 
                    boost::asn1::value_holder<capabilities_type> capabilities;
                    boost::asn1::value_holder<MMS_Object_Module_1::DomainState> state;
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<bool> sharable;
                    boost::asn1::value_holder<programInvocations_type> programInvocations;
                    boost::asn1::value_holder<namedVariables_type> namedVariables;
                    boost::asn1::value_holder<namedVariableLists_type> namedVariableLists;
                    boost::asn1::value_holder<namedTypes_type> namedTypes;
                    boost::asn1::value_holder<eventConditions_type> eventConditions;
                    boost::asn1::value_holder<eventActions_type> eventActions;
                    boost::asn1::value_holder<eventEnrollments_type> eventEnrollments;
                    boost::asn1::value_holder<eventConditionLists_type> eventConditionLists;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Domain_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Program-Invocation-instance
        struct Program_Invocation_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< Domain_instance> domains_type;
                typedef std::vector< Access_Control_List_instance> accessControl_type;
                typedef std::vector< Event_Condition_instance> eventCondition_type;
                typedef std::vector< Event_Action_instance> eventAction_type;
                typedef std::vector< Event_Enrollment_instance> eventEnrollment_type;
                typedef std::vector< Program_Invocation_instance> controlled_Program_Invocations_type;


                    details_type() : programInvocationState(), domains(), accessControl(), reusable(), monitor(), executionArgument(), control(), controlling_Program_Invocation() {} 
 
                    boost::asn1::value_holder<MMS_Object_Module_1::ProgramInvocationState> programInvocationState;
                    boost::asn1::value_holder<domains_type> domains;
                    boost::asn1::value_holder<accessControl_type> accessControl;
                    boost::asn1::value_holder<bool> reusable;
                    boost::asn1::value_holder<bool> monitor;
                    boost::shared_ptr<eventCondition_type> eventCondition;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(eventCondition_type, eventCondition)

                    boost::shared_ptr<eventAction_type> eventAction;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(eventAction_type, eventAction)

                    boost::shared_ptr<eventEnrollment_type> eventEnrollment;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(eventEnrollment_type, eventEnrollment)

                    boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> executionArgument;
                    boost::shared_ptr<MMS_Object_Module_1::Control_State> control; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::Control_State, control)

                    boost::shared_ptr<Program_Invocation_instance> controlling_Program_Invocation; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(Program_Invocation_instance, controlling_Program_Invocation)

                    boost::shared_ptr<controlled_Program_Invocations_type> controlled_Program_Invocations; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(controlled_Program_Invocations_type, controlled_Program_Invocations)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Program_Invocation_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Unit-Control-instance
        struct Unit_Control_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< Domain_instance> domains_type;
                typedef std::vector< Program_Invocation_instance> programInvocations_type;


                    details_type() : accessControl(), domains(), programInvocations() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<domains_type> domains;
                    boost::asn1::value_holder<programInvocations_type> programInvocations;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Unit_Control_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Unnamed-Variable-instance
        struct Unnamed_Variable_instance{



            Unnamed_Variable_instance() : address(), accessControl(), typeDescription() {} 
 
            boost::asn1::value_holder<MMS_Object_Module_1::Address> address;
            boost::asn1::value_holder<Access_Control_List_instance> accessControl;
            boost::asn1::value_holder<MMS_Object_Module_1::TypeDescription> typeDescription;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Named-Variable-instance
        struct Named_Variable_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{



                    details_type() : accessControl(), typeDescription() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<MMS_Object_Module_1::TypeDescription> typeDescription;
                    boost::asn1::value_holder<MMS_Object_Module_1::Address> address;
                    boost::shared_ptr<visiblestring_type> meaning;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, meaning)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Named_Variable_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Named-Variable-List-instance
        struct Named_Variable_List_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< Variable_List_Item_instance> listOfVariables_type;


                    details_type() : accessControl(), listOfVariables() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<listOfVariables_type> listOfVariables;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Named_Variable_List_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Variable-List-Item-instance
        struct Variable_List_Item_instance{



            Variable_List_Item_instance() {} 
 
            boost::shared_ptr<Unnamed_Variable_instance> unnamedItem;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Unnamed_Variable_instance, unnamedItem)

            boost::shared_ptr<Named_Variable_instance> namedItem;
            BOOST_ASN_VALUE_FUNC_DECLARATE(Named_Variable_instance, namedItem)

            boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess> alternateAccess;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::AlternateAccess, alternateAccess)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Named-Type-instance
        struct Named_Type_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{



                    details_type() : accessControl(), typeDescription() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<MMS_Object_Module_1::TypeDescription> typeDescription;
                    boost::shared_ptr<visiblestring_type> meaning;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(visiblestring_type, meaning)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Named_Type_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Data-Exchange-instance
        struct Data_Exchange_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< MMS_Object_Module_1::TypeDescription> request_type;
                typedef std::vector< MMS_Object_Module_1::TypeDescription> response_type;


                    details_type() : accessControl(), request(), response(), linked() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<request_type> request;
                    boost::asn1::value_holder<response_type> response;
                    boost::asn1::value_holder<bool> linked;
                    boost::shared_ptr<Program_Invocation_instance> programInvocation;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(Program_Invocation_instance, programInvocation)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Data_Exchange_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Semaphore-instance
        struct Semaphore_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< visiblestring_type> namedTokens_type;

                    static const int classV_token;
                    static const int classV_pool;


                    details_type() : accessControl(), classV(), eventCondition() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<enumerated_type> classV;
                    boost::shared_ptr<int> numberOfTokens;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(int, numberOfTokens)

                    boost::shared_ptr<namedTokens_type> namedTokens;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(namedTokens_type, namedTokens)

                    boost::asn1::value_holder<Event_Condition_instance> eventCondition;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Semaphore_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Operator-Station-instance
        struct Operator_Station_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{


                    static const int stationType_entry;
                    static const int stationType_display;
                    static const int stationType_entry_display;


                    details_type() : accessControl(), stationType() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<enumerated_type> stationType;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Operator_Station_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Identifier> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Event-Condition-instance
        struct Event_Condition_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{


                    enum monitoredVariable_type_enum {
                        monitoredVariable_type_null = 0, 
                        monitoredVariable_type_named,
                        monitoredVariable_type_unnamed,
                        monitoredVariable_type_unspecified,}; 
 
                    struct monitoredVariable_type : public BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) {



                        monitoredVariable_type() :  BOOST_ASN_CHOICE_STRUCT(monitoredVariable_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(named, Named_Variable_instance, monitoredVariable_type_named);
                        BOOST_ASN_VALUE_CHOICE(unnamed, Unnamed_Variable_instance, monitoredVariable_type_unnamed);
                        BOOST_ASN_VALUE_CHOICE(unspecified, null_type, monitoredVariable_type_unspecified);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 

                    enum displayEnhancement_type_enum {
                        displayEnhancement_type_null = 0, 
                        displayEnhancement_type_text,
                        displayEnhancement_type_number,
                        displayEnhancement_type_none,}; 
 
                    struct displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {



                        displayEnhancement_type() :  BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(text, ISO_9506_MMS_1::MMSString, displayEnhancement_type_text);
                        BOOST_ASN_VALUE_CHOICE(number, int, displayEnhancement_type_number);
                        BOOST_ASN_VALUE_CHOICE(none, null_type, displayEnhancement_type_none);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 

                    enum group_Priority_Override_type_enum {
                        group_Priority_Override_type_null = 0, 
                        group_Priority_Override_type_priority,
                        group_Priority_Override_type_undefined,}; 
 
                    struct group_Priority_Override_type : public BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) {



                        group_Priority_Override_type() :  BOOST_ASN_CHOICE_STRUCT(group_Priority_Override_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(priority, MMS_Object_Module_1::Priority, group_Priority_Override_type_priority);
                        BOOST_ASN_VALUE_CHOICE(undefined, null_type, group_Priority_Override_type_undefined);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 
                typedef std::vector< Event_Enrollment_instance> eventEnrollments_type;
                typedef std::vector< Event_Condition_List_instance> referencingEventConditionLists_type;


                    details_type() : accessControl(), ecClass(), ecState(), priority(), severity(), eventEnrollments(), displayEnhancement(), referencingEventConditionLists() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<MMS_Object_Module_1::EC_Class> ecClass;
                    boost::asn1::value_holder<MMS_Object_Module_1::EC_State> ecState;
                    boost::asn1::value_holder<MMS_Object_Module_1::Priority> priority;
                    boost::asn1::value_holder<MMS_Object_Module_1::Severity> severity;
                    boost::asn1::value_holder<eventEnrollments_type> eventEnrollments;
                    boost::shared_ptr<bool> enabled;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(bool, enabled)

                    boost::shared_ptr<bool> alarmSummaryReports;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(bool, alarmSummaryReports)

                    boost::asn1::value_holder<monitoredVariable_type> monitoredVariable;
                    boost::shared_ptr<int> evaluationInterval;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(int, evaluationInterval)

                    boost::shared_ptr<displayEnhancement_type> displayEnhancement; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(displayEnhancement_type, displayEnhancement)

                    boost::shared_ptr<group_Priority_Override_type> group_Priority_Override; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(group_Priority_Override_type, group_Priority_Override)

                    boost::shared_ptr<referencingEventConditionLists_type> referencingEventConditionLists; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(referencingEventConditionLists_type, referencingEventConditionLists)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Event_Condition_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Event-Action-instance
        struct Event_Action_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< MMS_Object_Module_1::Modifier> modifiers_type;
                typedef std::vector< Event_Enrollment_instance> eventEnrollments_type;


                    details_type() : accessControl(), confirmedServiceRequest(), modifiers(), eventEnrollments() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<ISO_9506_MMS_1::ConfirmedServiceRequest> confirmedServiceRequest;
                    boost::asn1::value_holder<modifiers_type> modifiers;
                    boost::asn1::value_holder<eventEnrollments_type> eventEnrollments;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Event_Action_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Event-Enrollment-instance
        struct Event_Enrollment_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{


                    enum remainingDelay_type_enum {
                        remainingDelay_type_null = 0, 
                        remainingDelay_type_time,
                        remainingDelay_type_forever,}; 
 
                    struct remainingDelay_type : public BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) {



                        remainingDelay_type() :  BOOST_ASN_CHOICE_STRUCT(remainingDelay_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(time, int, remainingDelay_type_time);
                        BOOST_ASN_VALUE_CHOICE(forever, null_type, remainingDelay_type_forever);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 

                    enum displayEnhancement_type_enum {
                        displayEnhancement_type_null = 0, 
                        displayEnhancement_type_text,
                        displayEnhancement_type_number,
                        displayEnhancement_type_none,}; 
 
                    struct displayEnhancement_type : public BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) {



                        displayEnhancement_type() :  BOOST_ASN_CHOICE_STRUCT(displayEnhancement_type_enum) () {}
 
                        BOOST_ASN_VALUE_CHOICE(text, ISO_9506_MMS_1::MMSString, displayEnhancement_type_text);
                        BOOST_ASN_VALUE_CHOICE(number, int, displayEnhancement_type_number);
                        BOOST_ASN_VALUE_CHOICE(none, null_type, displayEnhancement_type_none);

                        BOOST_ASN_ARCHIVE_FUNC;
                    }; 
 


                    details_type() : accessControl(), eeClass(), eventCondition(), ecTransitions(), displayEnhancement() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<MMS_Object_Module_1::EE_Class> eeClass;
                    boost::asn1::value_holder<Event_Condition_instance> eventCondition;
                    boost::asn1::value_holder<MMS_Object_Module_1::Transitions> ecTransitions;
                    boost::asn1::value_holder<remainingDelay_type> remainingDelay;
                    boost::shared_ptr<Event_Action_instance> eventAction;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(Event_Action_instance, eventAction)

                    boost::shared_ptr<MMS_Object_Module_1::EE_Duration> duration;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::EE_Duration, duration)

                    boost::shared_ptr<MMS_Environment_1::ApplicationReference> clientApplication;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, clientApplication)

                    boost::shared_ptr<MMS_Object_Module_1::AlarmAckRule> aaRule;
                    BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Object_Module_1::AlarmAckRule, aaRule)

                    boost::shared_ptr<displayEnhancement_type> displayEnhancement; // after extention
                    BOOST_ASN_VALUE_FUNC_DECLARATE(displayEnhancement_type, displayEnhancement)


                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Event_Enrollment_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Event-Condition-List-instance
        struct Event_Condition_List_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< Event_Condition_instance> eventConditions_type;
                typedef std::vector< Event_Condition_List_instance> eventConditionLists_type;
                typedef std::vector< Event_Condition_List_instance> referencingEventConditionLists_type;


                    details_type() : accessControl(), eventConditions(), eventConditionLists(), referencingEventConditionLists() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<eventConditions_type> eventConditions;
                    boost::asn1::value_holder<eventConditionLists_type> eventConditionLists;
                    boost::asn1::value_holder<referencingEventConditionLists_type> referencingEventConditionLists;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Event_Condition_List_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Journal-instance
        struct Journal_instance{


            enum definition_type_enum {
                definition_type_null = 0, 
                definition_type_reference,
                definition_type_details,}; 
 
            struct definition_type : public BOOST_ASN_CHOICE_STRUCT(definition_type_enum) {


                struct details_type{

                typedef std::vector< Journal_Entry_instance> entries_type;


                    details_type() : accessControl(), entries() {} 
 
                    boost::asn1::value_holder<Access_Control_List_instance> accessControl;
                    boost::asn1::value_holder<entries_type> entries;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 


                definition_type() :  BOOST_ASN_CHOICE_STRUCT(definition_type_enum) () {}
 
                BOOST_ASN_VALUE_CHOICE(reference, oid_type, definition_type_reference);
                BOOST_ASN_VALUE_CHOICE(details, details_type, definition_type_details);

                BOOST_ASN_ARCHIVE_FUNC;
            }; 
 


            Journal_instance() : name(), definition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
            boost::asn1::value_holder<definition_type> definition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Journal-Entry-instance
        struct Journal_Entry_instance{
        struct journalVariables_type_sequence_of;


            struct eventTransitionRecord_type{



                eventTransitionRecord_type() : name(), currentState() {} 
 
                boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> name;
                boost::asn1::value_holder<MMS_Object_Module_1::EC_State> currentState;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 

                struct journalVariables_type_sequence_of{



                    journalVariables_type_sequence_of() : variableTag(), valueSpecification() {} 
 
                    boost::asn1::value_holder<ISO_9506_MMS_1::MMS255String> variableTag;
                    boost::asn1::value_holder<ISO_9506_MMS_1::Data> valueSpecification;

                    BOOST_ASN_ARCHIVE_FUNC;
                };
 
        typedef std::vector< journalVariables_type_sequence_of> journalVariables_type;

            static const int informationType_annotation;
            static const int informationType_event_data;
            static const int informationType_data;


            Journal_Entry_instance() : journal(), entry(), clientApplication(), timeStamp(), orderOfReceipt(), informationType() {} 
 
            boost::asn1::value_holder<Journal_instance> journal;
            boost::asn1::value_holder<octetstring_type> entry;
            boost::asn1::value_holder<MMS_Environment_1::ApplicationReference> clientApplication;
            boost::asn1::value_holder<ISO_9506_MMS_1::TimeOfDay> timeStamp;
            boost::asn1::value_holder<int> orderOfReceipt;
            boost::asn1::value_holder<enumerated_type> informationType;
            boost::shared_ptr<ISO_9506_MMS_1::MMS255String> textComment;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::MMS255String, textComment)

            boost::shared_ptr<eventTransitionRecord_type> eventTransitionRecord;
            BOOST_ASN_VALUE_FUNC_DECLARATE(eventTransitionRecord_type, eventTransitionRecord)

            boost::shared_ptr<journalVariables_type> journalVariables;
            BOOST_ASN_VALUE_FUNC_DECLARATE(journalVariables_type, journalVariables)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence Service-and-Parameter-CBBs
        struct Service_and_Parameter_CBBs{



            Service_and_Parameter_CBBs() : services_Client(), services_Server(), parameters(), nest(), extendedServices_Client(), extendedServices_Server(), extendedParameters(), generalManagement(), vMDSupport(), domainManagement(), programInvocation(), variableAccess(), dataParameters(), semaphoreManagement(), operatorCommunication(), errors(), fileManagement() {} 
 
            boost::asn1::value_holder<MMS_Object_Module_1::ServiceSupportOptions> services_Client;
            boost::asn1::value_holder<MMS_Object_Module_1::ServiceSupportOptions> services_Server;
            boost::asn1::value_holder<MMS_Object_Module_1::ParameterSupportOptions> parameters;
            boost::asn1::value_holder<int> nest;
            boost::asn1::value_holder<MMS_Object_Module_1::AdditionalSupportOptions> extendedServices_Client;
            boost::asn1::value_holder<MMS_Object_Module_1::AdditionalSupportOptions> extendedServices_Server;
            boost::asn1::value_holder<MMS_Object_Module_1::AdditionalCBBOptions> extendedParameters;
            boost::asn1::value_holder<GeneralManagementParameters> generalManagement;
            boost::asn1::value_holder<VMDSupportParameters> vMDSupport;
            boost::asn1::value_holder<DomainManagementParameters> domainManagement;
            boost::asn1::value_holder<ProgramInvocationManagementParameters> programInvocation;
            boost::asn1::value_holder<VariableAccessParameters> variableAccess;
            boost::asn1::value_holder<DataParameters> dataParameters;
            boost::asn1::value_holder<SemaphoreManagementParameters> semaphoreManagement;
            boost::asn1::value_holder<OperatorCommunicationParameters> operatorCommunication;
            boost::asn1::value_holder<ErrorParameters> errors;
            boost::asn1::value_holder<FileManagementParameters> fileManagement;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GeneralManagementParameters
        struct GeneralManagementParameters{


            struct supportForTime_type{



                supportForTime_type() : timeOfDay(), timeSequence() {} 
 
                boost::asn1::value_holder<bool> timeOfDay;
                boost::asn1::value_holder<bool> timeSequence;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            GeneralManagementParameters() : localDetail(), supportForTime(), granularityOfTime() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> localDetail;
            boost::asn1::value_holder<supportForTime_type> supportForTime;
            boost::asn1::value_holder<int> granularityOfTime;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence VMDSupportParameters
        struct VMDSupportParameters{



            VMDSupportParameters() : localDetail(), extendedDerivation() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> localDetail;
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> extendedDerivation;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DomainManagementParameters
        struct DomainManagementParameters{

        typedef std::vector< oid_type> loadDataSyntax_type;


            DomainManagementParameters() : loadDataOctet(), loadDataSyntax(), maxUploads() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> loadDataOctet;
            boost::asn1::value_holder<loadDataSyntax_type> loadDataSyntax;
            boost::asn1::value_holder<int> maxUploads;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ProgramInvocationManagementParameters
        struct ProgramInvocationManagementParameters{

        typedef std::vector< oid_type> executionArgSyntaxes_type;


            ProgramInvocationManagementParameters() : executionArgMaxSize(), executionArgParseRules(), executionArgSyntaxes(), programLoction(), stepMode() {} 
 
            boost::asn1::value_holder<int> executionArgMaxSize;
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> executionArgParseRules;
            boost::asn1::value_holder<executionArgSyntaxes_type> executionArgSyntaxes;
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> programLoction;
            boost::asn1::value_holder<bool> stepMode;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence VariableAccessParameters
        struct VariableAccessParameters{



            VariableAccessParameters() : uninterruptibleAccess(), singleMode(), unnamedMode() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> uninterruptibleAccess;
            boost::asn1::value_holder<bool> singleMode;
            boost::asn1::value_holder<bool> unnamedMode;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DataParameters
        struct DataParameters{


            struct floating_point_type{



                floating_point_type() : total(), exponent() {} 
 
                boost::asn1::value_holder<int> total;
                boost::asn1::value_holder<int> exponent;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            DataParameters() {} 
 
            boost::shared_ptr<int> bit_string;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, bit_string)

            boost::shared_ptr<int> integer;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, integer)

            boost::shared_ptr<int> unsignedV;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, unsignedV)

            boost::shared_ptr<floating_point_type> floating_point;
            BOOST_ASN_VALUE_FUNC_DECLARATE(floating_point_type, floating_point)

            boost::shared_ptr<int> octet_string;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, octet_string)

            boost::shared_ptr<int> visible_string;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, visible_string)

            boost::shared_ptr<bool> binary_time;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, binary_time)

            boost::shared_ptr<int> bcd;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, bcd)

            boost::shared_ptr<int> mmsString;
            BOOST_ASN_VALUE_FUNC_DECLARATE(int, mmsString)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence SemaphoreManagementParameters
        struct SemaphoreManagementParameters{



            SemaphoreManagementParameters() : algorithm() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> algorithm;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence OperatorCommunicationParameters
        struct OperatorCommunicationParameters{



            OperatorCommunicationParameters() : input_time_out() {} 
 
            boost::asn1::value_holder<int> input_time_out;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence ErrorParameters
        struct ErrorParameters{


            struct additionalDetial_type{



                additionalDetial_type() : size(), syntax() {} 
 
                boost::asn1::value_holder<int> size;
                boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> syntax;

                BOOST_ASN_ARCHIVE_FUNC;
            };
 


            ErrorParameters() : additionalCode(), additionalDetial() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> additionalCode;
            boost::asn1::value_holder<additionalDetial_type> additionalDetial;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence FileManagementParameters
        struct FileManagementParameters{



            FileManagementParameters() : fileName() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::MMSString> fileName;

            BOOST_ASN_ARCHIVE_FUNC;
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

