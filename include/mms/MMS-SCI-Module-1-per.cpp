#include "MMS-SCI-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {




    //  helper name:   Semaphore_instance__Definition_type__Details_type__enumerated           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(Semaphore_instance__Definition_type__Details_type__enumerated__helper, false, ITU_T_ARRAY(0, 1));


    //  helper name:   Operator_Station_instance__Definition_type__Details_type__enumerated           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(Operator_Station_instance__Definition_type__Details_type__enumerated__helper, false, ITU_T_ARRAY(0, 1, 2));


    //  helper name:   Journal_Entry_instance__enumerated           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(Journal_Entry_instance__enumerated__helper, false, ITU_T_ARRAY(0, 1, 2));

    // sequence SCI-Information

    template<> void SCI_Information::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(partOne_);
        ITU_T_BIND_PER(partTwo_);
    }

    template<> void SCI_Information::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(partOne_);
        ITU_T_BIND_PER(partTwo_);
    }

    // sequence VMD-File

    template<> void VMD_File::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(selected_Program_Invocation_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;

        ITU_T_BIND_PER(executiveFunction_);
        ITU_T_BIND_PER(vendorName_);
        ITU_T_BIND_PER(modelName_);
        ITU_T_BIND_PER(revision_);
        ITU_T_BIND_PER(abstractSyntaxes_);
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_NUM_CONSTRAINT(logicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(capabilities_);
        ITU_T_BIND_NUM_CONSTRAINT(physicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(local_detail_);
        ITU_T_BIND_PER(accessControlLists_);
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(programInvocations_);
        ITU_T_BIND_PER(unitControls_);
        ITU_T_BIND_PER(unnamedVariables_);
        ITU_T_BIND_PER(namedVariables_);
        ITU_T_BIND_PER(namedVariableLists_);
        ITU_T_BIND_PER(namedTypes_);
        ITU_T_BIND_PER(dataExchanges_);
        ITU_T_BIND_PER(semaphores_);
        ITU_T_BIND_PER(operatorStations_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventActions_);
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(eventConditionLists_);
        ITU_T_BIND_PER(journals_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(selected_Program_Invocation_);
                ITU_T_END_OPEN;
            }

        };

    }

    template<> void VMD_File::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_PER(executiveFunction_);
        ITU_T_BIND_PER(vendorName_);
        ITU_T_BIND_PER(modelName_);
        ITU_T_BIND_PER(revision_);
        ITU_T_BIND_PER(abstractSyntaxes_);
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_NUM_CONSTRAINT(logicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(capabilities_);
        ITU_T_BIND_NUM_CONSTRAINT(physicalStatus_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));
        ITU_T_BIND_PER(local_detail_);
        ITU_T_BIND_PER(accessControlLists_);
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(programInvocations_);
        ITU_T_BIND_PER(unitControls_);
        ITU_T_BIND_PER(unnamedVariables_);
        ITU_T_BIND_PER(namedVariables_);
        ITU_T_BIND_PER(namedVariableLists_);
        ITU_T_BIND_PER(namedTypes_);
        ITU_T_BIND_PER(dataExchanges_);
        ITU_T_BIND_PER(semaphores_);
        ITU_T_BIND_PER(operatorStations_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventActions_);
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(eventConditionLists_);
        ITU_T_BIND_PER(journals_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(selected_Program_Invocation_);
                ITU_T_END_OPEN;
            }

            ITU_T_CLEAR_EXTENTIONS(1);
        };

    }

    // choice selected-Program-Invocation

    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Selected_Program_Invocation_type_selectedProgram:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<Program_Invocation_instance > (false, Selected_Program_Invocation_type_selectedProgram));
                break;
            }
            case Selected_Program_Invocation_type_noneSelected:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<null_type > (false, Selected_Program_Invocation_type_noneSelected));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<Program_Invocation_instance > (true, Selected_Program_Invocation_type_selectedProgram));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<null_type > (true, Selected_Program_Invocation_type_noneSelected));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Access-Control-List-instance

    template<> void Access_Control_List_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Access_Control_List_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(eventConditionLists_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(readAccessCondition_) +
                ITU_T_EXISTS_BMP(storeAccessCondition_) +
                ITU_T_EXISTS_BMP(writeAccessCondition_) +
                ITU_T_EXISTS_BMP(loadAccessCondition_) +
                ITU_T_EXISTS_BMP(executeAccessCondition_) +
                ITU_T_EXISTS_BMP(deleteAccessCondition_) +
                ITU_T_EXISTS_BMP(editAccessCondition_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_BIND_PER(editAccessCondition_);
        ITU_T_BIND_PER(accessControlLists_);
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(programInvocations_);
        ITU_T_BIND_PER(unitControls_);
        ITU_T_BIND_PER(unnamedVariables_);
        ITU_T_BIND_PER(namedVariables_);
        ITU_T_BIND_PER(namedVariableLists_);
        ITU_T_BIND_PER(namedTypes_);
        ITU_T_BIND_PER(dataExchanges_);
        ITU_T_BIND_PER(semaphores_);
        ITU_T_BIND_PER(operatorStations_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventActions_);
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(journals_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(eventConditionLists_);
                ITU_T_END_OPEN;
            }

        };

    }

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(7);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(editAccessCondition_);
        ITU_T_BIND_PER(accessControlLists_);
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(programInvocations_);
        ITU_T_BIND_PER(unitControls_);
        ITU_T_BIND_PER(unnamedVariables_);
        ITU_T_BIND_PER(namedVariables_);
        ITU_T_BIND_PER(namedVariableLists_);
        ITU_T_BIND_PER(namedTypes_);
        ITU_T_BIND_PER(dataExchanges_);
        ITU_T_BIND_PER(semaphores_);
        ITU_T_BIND_PER(operatorStations_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventActions_);
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(journals_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(eventConditionLists_);
                ITU_T_END_OPEN;
            }

            ITU_T_CLEAR_EXTENTIONS(1);
        };

    }

    // sequence Domain-instance

    template<> void Domain_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Domain_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(capabilities_);
        ITU_T_BIND_NUM_CONSTRAINT(state_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(sharable_);
        ITU_T_BIND_PER(programInvocations_);
        ITU_T_BIND_PER(namedVariables_);
        ITU_T_BIND_PER(namedVariableLists_);
        ITU_T_BIND_PER(namedTypes_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventActions_);
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(eventConditionLists_);
    }

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(capabilities_);
        ITU_T_BIND_NUM_CONSTRAINT(state_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(sharable_);
        ITU_T_BIND_PER(programInvocations_);
        ITU_T_BIND_PER(namedVariables_);
        ITU_T_BIND_PER(namedVariableLists_);
        ITU_T_BIND_PER(namedTypes_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventActions_);
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(eventConditionLists_);
    }

    // sequence Program-Invocation-instance

    template<> void Program_Invocation_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Program_Invocation_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(control_);
        ITU_T_EXTENTION_GROUP_BOOL(1) = ITU_T_EXISTS_BOOL(controlling_Program_Invocation_);
        ITU_T_EXTENTION_GROUP_BOOL(2) = ITU_T_EXISTS_BOOL(controlled_Program_Invocations_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0) + ITU_T_EXTENTION_GROUP_AS_BMP(1) + ITU_T_EXTENTION_GROUP_AS_BMP(2);

        ITU_T_EXTENTION_WRITE;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(eventCondition_) +
                ITU_T_EXISTS_BMP(eventAction_) +
                ITU_T_EXISTS_BMP(eventEnrollment_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRAINT(programInvocationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(reusable_);
        ITU_T_BIND_PER(monitor_);
        ITU_T_BIND_PER(eventCondition_);
        ITU_T_BIND_PER(eventAction_);
        ITU_T_BIND_PER(eventEnrollment_);
        ITU_T_BIND_PER(executionArgument_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_NUM_CONSTRAINT(control_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(controlling_Program_Invocation_);
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(controlled_Program_Invocations_);
                ITU_T_END_OPEN;
            }

        };

    }

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_NUM_CONSTRAINT(programInvocationState_, static_cast<uint8_t> (0), static_cast<uint8_t> (8));
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(reusable_);
        ITU_T_BIND_PER(monitor_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(eventCondition_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(eventAction_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(eventEnrollment_);
        ITU_T_BIND_PER(executionArgument_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_NUM_CONSTRAINT(control_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(controlling_Program_Invocation_);
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(controlled_Program_Invocations_);
                ITU_T_END_OPEN;
            }

            ITU_T_CLEAR_EXTENTIONS(3);
        };

    }

    // sequence Unit-Control-instance

    template<> void Unit_Control_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Unit_Control_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(programInvocations_);
    }

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(domains_);
        ITU_T_BIND_PER(programInvocations_);
    }

    // sequence Unnamed-Variable-instance

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(address_);
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(typeDescription_);
    }

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(address_);
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(typeDescription_);
    }

    // sequence Named-Variable-instance

    template<> void Named_Variable_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Named_Variable_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(address_) +
                ITU_T_EXISTS_BMP(meaning_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(typeDescription_);
        ITU_T_BIND_PER(address_);
        ITU_T_BIND_PER(meaning_);
    }

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(typeDescription_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(address_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(meaning_);
    }

    // sequence Named-Variable-List-instance

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(listOfVariables_);
    }

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(listOfVariables_);
    }

    // sequence Variable-List-Item-instance

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(unnamedItem_) +
                ITU_T_EXISTS_BMP(namedItem_) +
                ITU_T_EXISTS_BMP(alternateAccess_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(unnamedItem_);
        ITU_T_BIND_PER(namedItem_);
        ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(unnamedItem_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(namedItem_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(alternateAccess_);
    }

    // sequence Named-Type-instance

    template<> void Named_Type_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Named_Type_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(meaning_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(typeDescription_);
        ITU_T_BIND_PER(meaning_);
    }

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(typeDescription_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(meaning_);
    }

    // sequence Data-Exchange-instance

    template<> void Data_Exchange_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Data_Exchange_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(programInvocation_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(request_);
        ITU_T_BIND_PER(response_);
        ITU_T_BIND_PER(linked_);
        ITU_T_BIND_PER(programInvocation_);
    }

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(request_);
        ITU_T_BIND_PER(response_);
        ITU_T_BIND_PER(linked_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(programInvocation_);
    }

    // sequence Semaphore-instance

    template<> void Semaphore_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Semaphore_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(numberOfTokens_) +
                ITU_T_EXISTS_BMP(namedTokens_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER_ENUM(classV_, Semaphore_instance__Definition_type__Details_type__enumerated__helper);
        ITU_T_BIND_PER(numberOfTokens_);
        ITU_T_BIND_PER(namedTokens_);
        ITU_T_BIND_PER(eventCondition_);
    }

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER_ENUM(classV_, Semaphore_instance__Definition_type__Details_type__enumerated__helper);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(numberOfTokens_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(namedTokens_);
        ITU_T_BIND_PER(eventCondition_);
    }

    // sequence Operator-Station-instance

    template<> void Operator_Station_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Operator_Station_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER_ENUM(stationType_, Operator_Station_instance__Definition_type__Details_type__enumerated__helper);
    }

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER_ENUM(stationType_, Operator_Station_instance__Definition_type__Details_type__enumerated__helper);
    }

    // sequence Event-Condition-instance

    template<> void Event_Condition_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Event_Condition_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(displayEnhancement_);
        ITU_T_EXTENTION_GROUP_BOOL(1) = ITU_T_EXISTS_BOOL(group_Priority_Override_);
        ITU_T_EXTENTION_GROUP_BOOL(2) = ITU_T_EXISTS_BOOL(referencingEventConditionLists_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0) + ITU_T_EXTENTION_GROUP_AS_BMP(1) + ITU_T_EXTENTION_GROUP_AS_BMP(2);

        ITU_T_EXTENTION_WRITE;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(enabled_) +
                ITU_T_EXISTS_BMP(alarmSummaryReports_) +
                ITU_T_EXISTS_BMP(monitoredVariable_) +
                ITU_T_EXISTS_BMP(evaluationInterval_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_NUM_CONSTRAINT(ecClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRAINT(ecState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRAINT(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRAINT(severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_BIND_PER(enabled_);
        ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_BIND_PER(evaluationInterval_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(displayEnhancement_);
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(group_Priority_Override_);
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(referencingEventConditionLists_);
                ITU_T_END_OPEN;
            }

        };

    }

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(4);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_NUM_CONSTRAINT(ecClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_NUM_CONSTRAINT(ecState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
        ITU_T_BIND_NUM_CONSTRAINT(priority_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRAINT(severity_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_PER(eventEnrollments_);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(enabled_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(evaluationInterval_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(displayEnhancement_);
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(1)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(group_Priority_Override_);
                ITU_T_END_OPEN;
            }

            if (ITU_T_EXTENTION_GROUPS_CHECK(2)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(referencingEventConditionLists_);
                ITU_T_END_OPEN;
            }

            ITU_T_CLEAR_EXTENTIONS(3);
        };

    }

    // choice monitoredVariable

    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case MonitoredVariable_type_named:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<Named_Variable_instance > (false, MonitoredVariable_type_named));
                break;
            }
            case MonitoredVariable_type_unnamed:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(value<Unnamed_Variable_instance > (false, MonitoredVariable_type_unnamed));
                break;
            }
            case MonitoredVariable_type_unspecified:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<null_type > (false, MonitoredVariable_type_unspecified));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<Named_Variable_instance > (true, MonitoredVariable_type_named));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Unnamed_Variable_instance > (true, MonitoredVariable_type_unnamed));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<null_type > (true, MonitoredVariable_type_unspecified));
                break;
            }
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text));
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(value<integer_type > (false, DisplayEnhancement_type_number));
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<null_type > (false, DisplayEnhancement_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<integer_type > (true, DisplayEnhancement_type_number));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<null_type > (true, DisplayEnhancement_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    // choice group-Priority-Override

    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Group_Priority_Override_type_priority:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_NUM_CONSTRAINT(value<MMS_Object_Module_1::Priority > (false, Group_Priority_Override_type_priority), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                break;
            }
            case Group_Priority_Override_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<null_type > (false, Group_Priority_Override_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRAINT(value<MMS_Object_Module_1::Priority > (true, Group_Priority_Override_type_priority), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<null_type > (true, Group_Priority_Override_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Event-Action-instance

    template<> void Event_Action_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Event_Action_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(confirmedServiceRequest_);
        ITU_T_BIND_PER(modifiers_);
        ITU_T_BIND_PER(eventEnrollments_);
    }

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(confirmedServiceRequest_);
        ITU_T_BIND_PER(modifiers_);
        ITU_T_BIND_PER(eventEnrollments_);
    }

    // sequence Event-Enrollment-instance

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(displayEnhancement_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(remainingDelay_) +
                ITU_T_EXISTS_BMP(eventAction_) +
                ITU_T_EXISTS_BMP(duration_) +
                ITU_T_EXISTS_BMP(clientApplication_) +
                ITU_T_EXISTS_BMP(aaRule_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_NUM_CONSTRAINT(eeClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_PER(eventCondition_);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(ecTransitions_, 7);
        ITU_T_BIND_PER(remainingDelay_);
        ITU_T_BIND_PER(eventAction_);
        ITU_T_BIND_NUM_CONSTRAINT(duration_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_NUM_CONSTRAINT(aaRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(displayEnhancement_);
                ITU_T_END_OPEN;
            }

        };

    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(5);

        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_NUM_CONSTRAINT(eeClass_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_BIND_PER(eventCondition_);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(ecTransitions_, 7);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(remainingDelay_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(eventAction_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRAINT(duration_, static_cast<uint8_t> (0), static_cast<uint8_t> (1));
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(clientApplication_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_NUM_CONSTRAINT(aaRule_, static_cast<uint8_t> (0), static_cast<uint8_t> (3));

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_START_OPEN;
                ITU_T_BIND_PER(displayEnhancement_);
                ITU_T_END_OPEN;
            }

            ITU_T_CLEAR_EXTENTIONS(1);
        };

    }

    // choice remainingDelay

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RemainingDelay_type_time:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<integer_type > (false, RemainingDelay_type_time));
                break;
            }
            case RemainingDelay_type_forever:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<null_type > (false, RemainingDelay_type_forever));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<integer_type > (true, RemainingDelay_type_time));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<null_type > (true, RemainingDelay_type_forever));
                break;
            }
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text));
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(value<integer_type > (false, DisplayEnhancement_type_number));
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(value<null_type > (false, DisplayEnhancement_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<integer_type > (true, DisplayEnhancement_type_number));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(value<null_type > (true, DisplayEnhancement_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Event-Condition-List-instance

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventConditionLists_);
        ITU_T_BIND_PER(referencingEventConditionLists_);
    }

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(eventConditions_);
        ITU_T_BIND_PER(eventConditionLists_);
        ITU_T_BIND_PER(referencingEventConditionLists_);
    }

    // sequence Journal-instance

    template<> void Journal_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    template<> void Journal_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_PER(definition_);
    }

    // choice definition

    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(value<Details_type > (false, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(entries_);
    }

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(accessControl_);
        ITU_T_BIND_PER(entries_);
    }

    // sequence Journal-Entry-instance

    template<> void Journal_Entry_instance::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(textComment_) +
                ITU_T_EXISTS_BMP(eventTransitionRecord_) +
                ITU_T_EXISTS_BMP(journalVariables_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(journal_);
        ITU_T_BIND_PER(entry_);
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_SIZE_CONSTRAINT(timeStamp_, 4, 6);
        ITU_T_BIND_PER(orderOfReceipt_);
        ITU_T_BIND_PER_ENUM(informationType_, Journal_Entry_instance__enumerated__helper);
        ITU_T_BIND_PER(textComment_);
        ITU_T_BIND_PER(eventTransitionRecord_);
        ITU_T_BIND_PER(journalVariables_);
    }

    template<> void Journal_Entry_instance::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(3);

        ITU_T_BIND_PER(journal_);
        ITU_T_BIND_PER(entry_);
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_SIZE_CONSTRAINT(timeStamp_, 4, 6);
        ITU_T_BIND_PER(orderOfReceipt_);
        ITU_T_BIND_PER_ENUM(informationType_, Journal_Entry_instance__enumerated__helper);
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(textComment_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(eventTransitionRecord_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(journalVariables_);
    }

    // sequence eventTransitionRecord

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_NUM_CONSTRAINT(currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
    }

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(name_);
        ITU_T_BIND_NUM_CONSTRAINT(currentState_, static_cast<uint8_t> (0), static_cast<uint8_t> (2));
    }

    // sequence 

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(variableTag_);
        ITU_T_BIND_PER(valueSpecification_);
    }

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(variableTag_);
        ITU_T_BIND_PER(valueSpecification_);
    }

    // sequence Service-and-Parameter-CBBs

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(services_Client_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(services_Server_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(parameters_, 18);
        ITU_T_BIND_PER(nest_);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(extendedServices_Client_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(extendedServices_Server_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(extendedParameters_, 3);
        ITU_T_BIND_PER(generalManagement_);
        ITU_T_BIND_PER(vMDSupport_);
        ITU_T_BIND_PER(domainManagement_);
        ITU_T_BIND_PER(programInvocation_);
        ITU_T_BIND_PER(variableAccess_);
        ITU_T_BIND_PER(dataParameters_);
        ITU_T_BIND_PER(semaphoreManagement_);
        ITU_T_BIND_PER(operatorCommunication_);
        ITU_T_BIND_PER(errors_);
        ITU_T_BIND_PER(fileManagement_);
    }

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(services_Client_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(services_Server_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(parameters_, 18);
        ITU_T_BIND_PER(nest_);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(extendedServices_Client_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(extendedServices_Server_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRAINT(extendedParameters_, 3);
        ITU_T_BIND_PER(generalManagement_);
        ITU_T_BIND_PER(vMDSupport_);
        ITU_T_BIND_PER(domainManagement_);
        ITU_T_BIND_PER(programInvocation_);
        ITU_T_BIND_PER(variableAccess_);
        ITU_T_BIND_PER(dataParameters_);
        ITU_T_BIND_PER(semaphoreManagement_);
        ITU_T_BIND_PER(operatorCommunication_);
        ITU_T_BIND_PER(errors_);
        ITU_T_BIND_PER(fileManagement_);
    }

    // sequence GeneralManagementParameters

    template<> void GeneralManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(localDetail_);
        ITU_T_BIND_PER(supportForTime_);
        ITU_T_BIND_PER(granularityOfTime_);
    }

    template<> void GeneralManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(localDetail_);
        ITU_T_BIND_PER(supportForTime_);
        ITU_T_BIND_PER(granularityOfTime_);
    }

    // sequence supportForTime

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(timeOfDay_);
        ITU_T_BIND_PER(timeSequence_);
    }

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(timeOfDay_);
        ITU_T_BIND_PER(timeSequence_);
    }

    // sequence VMDSupportParameters

    template<> void VMDSupportParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(localDetail_);
        ITU_T_BIND_PER(extendedDerivation_);
    }

    template<> void VMDSupportParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(localDetail_);
        ITU_T_BIND_PER(extendedDerivation_);
    }

    // sequence DomainManagementParameters

    template<> void DomainManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(loadDataOctet_);
        ITU_T_BIND_PER(loadDataSyntax_);
        ITU_T_BIND_PER(maxUploads_);
    }

    template<> void DomainManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(loadDataOctet_);
        ITU_T_BIND_PER(loadDataSyntax_);
        ITU_T_BIND_PER(maxUploads_);
    }

    // sequence ProgramInvocationManagementParameters

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(executionArgMaxSize_);
        ITU_T_BIND_PER(executionArgParseRules_);
        ITU_T_BIND_PER(executionArgSyntaxes_);
        ITU_T_BIND_PER(programLoction_);
        ITU_T_BIND_PER(stepMode_);
    }

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(executionArgMaxSize_);
        ITU_T_BIND_PER(executionArgParseRules_);
        ITU_T_BIND_PER(executionArgSyntaxes_);
        ITU_T_BIND_PER(programLoction_);
        ITU_T_BIND_PER(stepMode_);
    }

    // sequence VariableAccessParameters

    template<> void VariableAccessParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(uninterruptibleAccess_);
        ITU_T_BIND_PER(singleMode_);
        ITU_T_BIND_PER(unnamedMode_);
    }

    template<> void VariableAccessParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(uninterruptibleAccess_);
        ITU_T_BIND_PER(singleMode_);
        ITU_T_BIND_PER(unnamedMode_);
    }

    // sequence DataParameters

    template<> void DataParameters::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(bit_stringV_) +
                ITU_T_EXISTS_BMP(integer_) +
                ITU_T_EXISTS_BMP(unsignedV_) +
                ITU_T_EXISTS_BMP(floating_point_) +
                ITU_T_EXISTS_BMP(octet_stringV_) +
                ITU_T_EXISTS_BMP(visible_stringV_) +
                ITU_T_EXISTS_BMP(binary_time_) +
                ITU_T_EXISTS_BMP(bcd_) +
                ITU_T_EXISTS_BMP(mmsString_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(bit_stringV_);
        ITU_T_BIND_PER(integer_);
        ITU_T_BIND_PER(unsignedV_);
        ITU_T_BIND_PER(floating_point_);
        ITU_T_BIND_PER(octet_stringV_);
        ITU_T_BIND_PER(visible_stringV_);
        ITU_T_BIND_PER(binary_time_);
        ITU_T_BIND_PER(bcd_);
        ITU_T_BIND_PER(mmsString_);
    }

    template<> void DataParameters::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(9);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(bit_stringV_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(integer_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(unsignedV_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(floating_point_);
        ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_PER(octet_stringV_);
        ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_PER(visible_stringV_);
        ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_PER(binary_time_);
        ITU_T_OPTIONAL_CHECK(7) ITU_T_BIND_PER(bcd_);
        ITU_T_OPTIONAL_CHECK(8) ITU_T_BIND_PER(mmsString_);
    }

    // sequence floating-point

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(total_);
        ITU_T_BIND_PER(exponent_);
    }

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(total_);
        ITU_T_BIND_PER(exponent_);
    }

    // sequence SemaphoreManagementParameters

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(algorithm_);
    }

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(algorithm_);
    }

    // sequence OperatorCommunicationParameters

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(input_time_out_);
    }

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(input_time_out_);
    }

    // sequence ErrorParameters

    template<> void ErrorParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(additionalCode_);
        ITU_T_BIND_PER(additionalDetial_);
    }

    template<> void ErrorParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(additionalCode_);
        ITU_T_BIND_PER(additionalDetial_);
    }

    // sequence additionalDetial

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(size_);
        ITU_T_BIND_PER(syntax_);
    }

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(size_);
        ITU_T_BIND_PER(syntax_);
    }

    // sequence FileManagementParameters

    template<> void FileManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(fileName_);
    }

    template<> void FileManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(fileName_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

