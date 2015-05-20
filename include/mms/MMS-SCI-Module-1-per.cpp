#include "MMS-SCI-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {




    //  helper name:   Semaphore_instance__Definition_type__Details_type__enumerated_type           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(Semaphore_instance__Definition_type__Details_type__enumerated_type__helper, false, ITU_T_ARRAY(0, 1));


    //  helper name:   Operator_Station_instance__Definition_type__Details_type__enumerated_type           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(Operator_Station_instance__Definition_type__Details_type__enumerated_type__helper, false, ITU_T_ARRAY(0, 1, 2));


    //  helper name:   Journal_Entry_instance__enumerated_type           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(Journal_Entry_instance__enumerated_type__helper, false, ITU_T_ARRAY(0, 1, 2));

    template<> void SCI_Information::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*partOne_);
        ITU_T_BIND_PER(*partTwo_);
    }

    template<> void SCI_Information::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*partOne_);
        ITU_T_BIND_PER(*partTwo_);
    }

    template<> void VMD_File::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;
        ITU_T_BIND_PER(*executiveFunction_);
        ITU_T_BIND_PER(*vendorName_);
        ITU_T_BIND_PER(*modelName_);
        ITU_T_BIND_PER(*revision_);
        ITU_T_BIND_PER(*abstractSyntaxes_);
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_NUM_CONSTRS(*(*logicalStatus_), (uint8_t) (0), (uint8_t) (3));
        ITU_T_BIND_PER(*capabilities_);
        ITU_T_BIND_NUM_CONSTRS(*(*physicalStatus_), (uint8_t) (0), (uint8_t) (3));
        ITU_T_BIND_PER(*local_detail_);
        ITU_T_BIND_PER(*accessControlLists_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
        ITU_T_BIND_PER(*unitControls_);
        ITU_T_BIND_PER(*unnamedVariables_);
        ITU_T_BIND_PER(*namedVariables_);
        ITU_T_BIND_PER(*namedVariableLists_);
        ITU_T_BIND_PER(*namedTypes_);
        ITU_T_BIND_PER(*dataExchanges_);
        ITU_T_BIND_PER(*semaphores_);
        ITU_T_BIND_PER(*operatorStations_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventActions_);
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(*eventConditionLists_);
        ITU_T_BIND_PER(*journals_);
    }

    template<> void VMD_File::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;
        ITU_T_BIND_PER(*executiveFunction_);
        ITU_T_BIND_PER(*vendorName_);
        ITU_T_BIND_PER(*modelName_);
        ITU_T_BIND_PER(*revision_);
        ITU_T_BIND_PER(*abstractSyntaxes_);
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_NUM_CONSTRS(*(*logicalStatus_), (uint8_t) (0), (uint8_t) (3));
        ITU_T_BIND_PER(*capabilities_);
        ITU_T_BIND_NUM_CONSTRS(*(*physicalStatus_), (uint8_t) (0), (uint8_t) (3));
        ITU_T_BIND_PER(*local_detail_);
        ITU_T_BIND_PER(*accessControlLists_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
        ITU_T_BIND_PER(*unitControls_);
        ITU_T_BIND_PER(*unnamedVariables_);
        ITU_T_BIND_PER(*namedVariables_);
        ITU_T_BIND_PER(*namedVariableLists_);
        ITU_T_BIND_PER(*namedTypes_);
        ITU_T_BIND_PER(*dataExchanges_);
        ITU_T_BIND_PER(*semaphores_);
        ITU_T_BIND_PER(*operatorStations_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventActions_);
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(*eventConditionLists_);
        ITU_T_BIND_PER(*journals_);
    }

    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Selected_Program_Invocation_type_selectedProgram:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<Program_Invocation_instance > (false, Selected_Program_Invocation_type_selectedProgram));
                break;
            }
            case Selected_Program_Invocation_type_noneSelected:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, Selected_Program_Invocation_type_noneSelected));
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
                ITU_T_BIND_PER(*value<Program_Invocation_instance > (true, Selected_Program_Invocation_type_selectedProgram));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Selected_Program_Invocation_type_noneSelected));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Access_Control_List_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Access_Control_List_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(readAccessCondition_) + ITU_T_OPTIONAL_PER(storeAccessCondition_) + ITU_T_OPTIONAL_PER(writeAccessCondition_) + ITU_T_OPTIONAL_PER(loadAccessCondition_) + ITU_T_OPTIONAL_PER(executeAccessCondition_) + ITU_T_OPTIONAL_PER(deleteAccessCondition_) + ITU_T_OPTIONAL_PER(editAccessCondition_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_BIND_PER(editAccessCondition_);
        ITU_T_BIND_PER(*accessControlLists_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
        ITU_T_BIND_PER(*unitControls_);
        ITU_T_BIND_PER(*unnamedVariables_);
        ITU_T_BIND_PER(*namedVariables_);
        ITU_T_BIND_PER(*namedVariableLists_);
        ITU_T_BIND_PER(*namedTypes_);
        ITU_T_BIND_PER(*dataExchanges_);
        ITU_T_BIND_PER(*semaphores_);
        ITU_T_BIND_PER(*operatorStations_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventActions_);
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(*journals_);
    }

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;

        ITU_T_OPTIONAL_GET_PER(7);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(readAccessCondition_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(storeAccessCondition_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(writeAccessCondition_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(loadAccessCondition_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(executeAccessCondition_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(deleteAccessCondition_);
        ITU_T_OPTIONAL_CHECK_PER(6) ITU_T_BIND_PER(editAccessCondition_);
        ITU_T_BIND_PER(*accessControlLists_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
        ITU_T_BIND_PER(*unitControls_);
        ITU_T_BIND_PER(*unnamedVariables_);
        ITU_T_BIND_PER(*namedVariables_);
        ITU_T_BIND_PER(*namedVariableLists_);
        ITU_T_BIND_PER(*namedTypes_);
        ITU_T_BIND_PER(*dataExchanges_);
        ITU_T_BIND_PER(*semaphores_);
        ITU_T_BIND_PER(*operatorStations_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventActions_);
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(*journals_);
    }

    template<> void Domain_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Domain_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*capabilities_);
        ITU_T_BIND_NUM_CONSTRS(*state_, (uint8_t) (0), (uint8_t) (15));
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*programInvocations_);
        ITU_T_BIND_PER(*namedVariables_);
        ITU_T_BIND_PER(*namedVariableLists_);
        ITU_T_BIND_PER(*namedTypes_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventActions_);
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(*eventConditionLists_);
    }

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*capabilities_);
        ITU_T_BIND_NUM_CONSTRS(*state_, (uint8_t) (0), (uint8_t) (15));
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*sharable_);
        ITU_T_BIND_PER(*programInvocations_);
        ITU_T_BIND_PER(*namedVariables_);
        ITU_T_BIND_PER(*namedVariableLists_);
        ITU_T_BIND_PER(*namedTypes_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventActions_);
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(*eventConditionLists_);
    }

    template<> void Program_Invocation_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Program_Invocation_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(eventCondition_) + ITU_T_OPTIONAL_PER(eventAction_) + ITU_T_OPTIONAL_PER(eventEnrollment_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_NUM_CONSTRS(*programInvocationState_, (uint8_t) (0), (uint8_t) (8));
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*reusable_);
        ITU_T_BIND_PER(*monitor_);
        ITU_T_BIND_PER(eventCondition_);
        ITU_T_BIND_PER(eventAction_);
        ITU_T_BIND_PER(eventEnrollment_);
        ITU_T_BIND_PER(*executionArgument_);
    }

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;

        ITU_T_OPTIONAL_GET_PER(3);

        ITU_T_BIND_NUM_CONSTRS(*programInvocationState_, (uint8_t) (0), (uint8_t) (8));
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*reusable_);
        ITU_T_BIND_PER(*monitor_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(eventCondition_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(eventAction_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(eventEnrollment_);
        ITU_T_BIND_PER(*executionArgument_);
    }

    template<> void Unit_Control_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Unit_Control_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*domains_);
        ITU_T_BIND_PER(*programInvocations_);
    }

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*address_);
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*typeDescription_);
    }

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*address_);
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*typeDescription_);
    }

    template<> void Named_Variable_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Named_Variable_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(address_) + ITU_T_OPTIONAL_PER(meaning_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*typeDescription_);
        ITU_T_BIND_PER(address_);
        ITU_T_BIND_PER(meaning_);
    }

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*typeDescription_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(address_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(meaning_);
    }

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*listOfVariables_);
    }

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*listOfVariables_);
    }

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(unnamedItem_) + ITU_T_OPTIONAL_PER(namedItem_) + ITU_T_OPTIONAL_PER(alternateAccess_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(unnamedItem_);
        ITU_T_BIND_PER(namedItem_);
        ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(3);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(unnamedItem_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(namedItem_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void Named_Type_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Named_Type_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(meaning_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*typeDescription_);
        ITU_T_BIND_PER(meaning_);
    }

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*typeDescription_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(meaning_);
    }

    template<> void Data_Exchange_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Data_Exchange_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(programInvocation_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*request_);
        ITU_T_BIND_PER(*response_);
        ITU_T_BIND_PER(*linked_);
        ITU_T_BIND_PER(programInvocation_);
    }

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*request_);
        ITU_T_BIND_PER(*response_);
        ITU_T_BIND_PER(*linked_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(programInvocation_);
    }

    template<> void Semaphore_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Semaphore_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(numberOfTokens_) + ITU_T_OPTIONAL_PER(namedTokens_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER_ENUM(*classV_, Semaphore_instance__Definition_type__Details_type__enumerated_type__helper);
        ITU_T_BIND_PER(numberOfTokens_);
        ITU_T_BIND_PER(namedTokens_);
        ITU_T_BIND_PER(*eventCondition_);
    }

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER_ENUM(*classV_, Semaphore_instance__Definition_type__Details_type__enumerated_type__helper);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(numberOfTokens_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(namedTokens_);
        ITU_T_BIND_PER(*eventCondition_);
    }

    template<> void Operator_Station_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Operator_Station_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER_ENUM(*stationType_, Operator_Station_instance__Definition_type__Details_type__enumerated_type__helper);
    }

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER_ENUM(*stationType_, Operator_Station_instance__Definition_type__Details_type__enumerated_type__helper);
    }

    template<> void Event_Condition_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Condition_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(enabled_) + ITU_T_OPTIONAL_PER(alarmSummaryReports_) + ITU_T_OPTIONAL_PER(monitoredVariable_) + ITU_T_OPTIONAL_PER(evaluationInterval_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_NUM_CONSTRS(*ecClass_, (uint8_t) (0), (uint8_t) (1));
        ITU_T_BIND_NUM_CONSTRS(*ecState_, (uint8_t) (0), (uint8_t) (2));
        ITU_T_BIND_NUM_CONSTRS(*priority_, (uint8_t) (0), (uint8_t) (127));
        ITU_T_BIND_NUM_CONSTRS(*severity_, (uint8_t) (0), (uint8_t) (127));
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_BIND_PER(enabled_);
        ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_BIND_PER(evaluationInterval_);
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;

        ITU_T_OPTIONAL_GET_PER(4);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_NUM_CONSTRS(*ecClass_, (uint8_t) (0), (uint8_t) (1));
        ITU_T_BIND_NUM_CONSTRS(*ecState_, (uint8_t) (0), (uint8_t) (2));
        ITU_T_BIND_NUM_CONSTRS(*priority_, (uint8_t) (0), (uint8_t) (127));
        ITU_T_BIND_NUM_CONSTRS(*severity_, (uint8_t) (0), (uint8_t) (127));
        ITU_T_BIND_PER(*eventEnrollments_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(enabled_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(alarmSummaryReports_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(monitoredVariable_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(evaluationInterval_);
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case MonitoredVariable_type_named:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<Named_Variable_instance > (false, MonitoredVariable_type_named));
                break;
            }
            case MonitoredVariable_type_unnamed:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<Unnamed_Variable_instance > (false, MonitoredVariable_type_unnamed));
                break;
            }
            case MonitoredVariable_type_unspecified:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, MonitoredVariable_type_unspecified));
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
                ITU_T_BIND_PER(*value<Named_Variable_instance > (true, MonitoredVariable_type_named));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Unnamed_Variable_instance > (true, MonitoredVariable_type_unnamed));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, MonitoredVariable_type_unspecified));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text));
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, DisplayEnhancement_type_number));
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, DisplayEnhancement_type_none));
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
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, DisplayEnhancement_type_number));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DisplayEnhancement_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_instance::Definition_type::Details_type::Group_Priority_Override_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Group_Priority_Override_type_priority:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_NUM_CONSTRS(*value<MMS_Object_Module_1::Priority > (false, Group_Priority_Override_type_priority), (uint8_t) (0), (uint8_t) (127));
                break;
            }
            case Group_Priority_Override_type_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, Group_Priority_Override_type_undefined));
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
                ITU_T_BIND_NUM_CONSTRS(*value<MMS_Object_Module_1::Priority > (true, Group_Priority_Override_type_priority), (uint8_t) (0), (uint8_t) (127));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, Group_Priority_Override_type_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Action_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Action_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*confirmedServiceRequest_);
        ITU_T_BIND_PER(*modifiers_);
        ITU_T_BIND_PER(*eventEnrollments_);
    }

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*confirmedServiceRequest_);
        ITU_T_BIND_PER(*modifiers_);
        ITU_T_BIND_PER(*eventEnrollments_);
    }

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(remainingDelay_) + ITU_T_OPTIONAL_PER(eventAction_) + ITU_T_OPTIONAL_PER(duration_) + ITU_T_OPTIONAL_PER(clientApplication_) + ITU_T_OPTIONAL_PER(aaRule_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_NUM_CONSTRS(*eeClass_, (uint8_t) (0), (uint8_t) (1));
        ITU_T_BIND_PER(*eventCondition_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*ecTransitions_, 7);
        ITU_T_BIND_PER(remainingDelay_);
        ITU_T_BIND_PER(eventAction_);
        ITU_T_BIND_NUM_CONSTRS(duration_, (uint8_t) (0), (uint8_t) (1));
        ITU_T_BIND_PER(clientApplication_);
        ITU_T_BIND_NUM_CONSTRS(aaRule_, (uint8_t) (0), (uint8_t) (3));
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;

        ITU_T_OPTIONAL_GET_PER(5);

        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_NUM_CONSTRS(*eeClass_, (uint8_t) (0), (uint8_t) (1));
        ITU_T_BIND_PER(*eventCondition_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*ecTransitions_, 7);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(remainingDelay_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(eventAction_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_NUM_CONSTRS(duration_, (uint8_t) (0), (uint8_t) (1));
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(clientApplication_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_NUM_CONSTRS(aaRule_, (uint8_t) (0), (uint8_t) (3));
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case RemainingDelay_type_time:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<integer_type > (false, RemainingDelay_type_time));
                break;
            }
            case RemainingDelay_type_forever:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<null_type > (false, RemainingDelay_type_forever));
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
                ITU_T_BIND_PER(*value<integer_type > (true, RemainingDelay_type_time));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<null_type > (true, RemainingDelay_type_forever));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text));
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<integer_type > (false, DisplayEnhancement_type_number));
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, DisplayEnhancement_type_none));
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
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<integer_type > (true, DisplayEnhancement_type_number));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, DisplayEnhancement_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventConditionLists_);
        ITU_T_BIND_PER(*referencingEventConditionLists_);
    }

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*eventConditions_);
        ITU_T_BIND_PER(*eventConditionLists_);
        ITU_T_BIND_PER(*referencingEventConditionLists_);
    }

    template<> void Journal_instance::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Journal_instance::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_PER(*definition_);
    }

    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<oid_type > (false, Definition_type_reference));
                break;
            }
            case Definition_type_details:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<Details_type > (false, Definition_type_details));
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
                ITU_T_BIND_PER(*value<oid_type > (true, Definition_type_reference));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<Details_type > (true, Definition_type_details));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*entries_);
    }

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*accessControl_);
        ITU_T_BIND_PER(*entries_);
    }

    template<> void Journal_Entry_instance::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(textComment_) + ITU_T_OPTIONAL_PER(eventTransitionRecord_) + ITU_T_OPTIONAL_PER(journalVariables_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*journal_);
        ITU_T_BIND_PER(*entry_);
        ITU_T_BIND_PER(*clientApplication_);
        ITU_T_BIND_SIZE_CONSTRS(*timeStamp_, 4, 6);
        ITU_T_BIND_PER(*orderOfReceipt_);
        ITU_T_BIND_PER_ENUM(*informationType_, Journal_Entry_instance__enumerated_type__helper);
        ITU_T_BIND_PER(textComment_);
        ITU_T_BIND_PER(eventTransitionRecord_);
        ITU_T_BIND_PER(journalVariables_);
    }

    template<> void Journal_Entry_instance::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(3);

        ITU_T_BIND_PER(*journal_);
        ITU_T_BIND_PER(*entry_);
        ITU_T_BIND_PER(*clientApplication_);
        ITU_T_BIND_SIZE_CONSTRS(*timeStamp_, 4, 6);
        ITU_T_BIND_PER(*orderOfReceipt_);
        ITU_T_BIND_PER_ENUM(*informationType_, Journal_Entry_instance__enumerated_type__helper);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(textComment_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(eventTransitionRecord_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(journalVariables_);
    }

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_NUM_CONSTRS(*currentState_, (uint8_t) (0), (uint8_t) (2));
    }

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*name_);
        ITU_T_BIND_NUM_CONSTRS(*currentState_, (uint8_t) (0), (uint8_t) (2));
    }

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*variableTag_);
        ITU_T_BIND_PER(*valueSpecification_);
    }

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*variableTag_);
        ITU_T_BIND_PER(*valueSpecification_);
    }

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_SIZE_SNGLCONSTRS(*services_Client_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*services_Server_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*parameters_, 18);
        ITU_T_BIND_PER(*nest_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedServices_Client_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedServices_Server_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedParameters_, 3);
        ITU_T_BIND_PER(*generalManagement_);
        ITU_T_BIND_PER(*vMDSupport_);
        ITU_T_BIND_PER(*domainManagement_);
        ITU_T_BIND_PER(*programInvocation_);
        ITU_T_BIND_PER(*variableAccess_);
        ITU_T_BIND_PER(*dataParameters_);
        ITU_T_BIND_PER(*semaphoreManagement_);
        ITU_T_BIND_PER(*operatorCommunication_);
        ITU_T_BIND_PER(*errors_);
        ITU_T_BIND_PER(*fileManagement_);
    }

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_SIZE_SNGLCONSTRS(*services_Client_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*services_Server_, 93);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*parameters_, 18);
        ITU_T_BIND_PER(*nest_);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedServices_Client_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedServices_Server_, 23);
        ITU_T_BIND_SIZE_SNGLCONSTRS(*extendedParameters_, 3);
        ITU_T_BIND_PER(*generalManagement_);
        ITU_T_BIND_PER(*vMDSupport_);
        ITU_T_BIND_PER(*domainManagement_);
        ITU_T_BIND_PER(*programInvocation_);
        ITU_T_BIND_PER(*variableAccess_);
        ITU_T_BIND_PER(*dataParameters_);
        ITU_T_BIND_PER(*semaphoreManagement_);
        ITU_T_BIND_PER(*operatorCommunication_);
        ITU_T_BIND_PER(*errors_);
        ITU_T_BIND_PER(*fileManagement_);
    }

    template<> void GeneralManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*localDetail_);
        ITU_T_BIND_PER(*supportForTime_);
        ITU_T_BIND_PER(*granularityOfTime_);
    }

    template<> void GeneralManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*localDetail_);
        ITU_T_BIND_PER(*supportForTime_);
        ITU_T_BIND_PER(*granularityOfTime_);
    }

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*timeOfDay_);
        ITU_T_BIND_PER(*timeSequence_);
    }

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*timeOfDay_);
        ITU_T_BIND_PER(*timeSequence_);
    }

    template<> void VMDSupportParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*localDetail_);
        ITU_T_BIND_PER(*extendedDerivation_);
    }

    template<> void VMDSupportParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*localDetail_);
        ITU_T_BIND_PER(*extendedDerivation_);
    }

    template<> void DomainManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*loadDataOctet_);
        ITU_T_BIND_PER(*loadDataSyntax_);
        ITU_T_BIND_PER(*maxUploads_);
    }

    template<> void DomainManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*loadDataOctet_);
        ITU_T_BIND_PER(*loadDataSyntax_);
        ITU_T_BIND_PER(*maxUploads_);
    }

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*executionArgMaxSize_);
        ITU_T_BIND_PER(*executionArgParseRules_);
        ITU_T_BIND_PER(*executionArgSyntaxes_);
        ITU_T_BIND_PER(*programLoction_);
        ITU_T_BIND_PER(*stepMode_);
    }

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*executionArgMaxSize_);
        ITU_T_BIND_PER(*executionArgParseRules_);
        ITU_T_BIND_PER(*executionArgSyntaxes_);
        ITU_T_BIND_PER(*programLoction_);
        ITU_T_BIND_PER(*stepMode_);
    }

    template<> void VariableAccessParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*uninterruptibleAccess_);
        ITU_T_BIND_PER(*singleMode_);
        ITU_T_BIND_PER(*unnamedMode_);
    }

    template<> void VariableAccessParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*uninterruptibleAccess_);
        ITU_T_BIND_PER(*singleMode_);
        ITU_T_BIND_PER(*unnamedMode_);
    }

    template<> void DataParameters::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(bit_string_) + ITU_T_OPTIONAL_PER(integer_) + ITU_T_OPTIONAL_PER(unsignedV_) + ITU_T_OPTIONAL_PER(floating_point_) + ITU_T_OPTIONAL_PER(octet_string_) + ITU_T_OPTIONAL_PER(visible_string_) + ITU_T_OPTIONAL_PER(binary_time_) + ITU_T_OPTIONAL_PER(bcd_) + ITU_T_OPTIONAL_PER(mmsString_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(bit_string_);
        ITU_T_BIND_PER(integer_);
        ITU_T_BIND_PER(unsignedV_);
        ITU_T_BIND_PER(floating_point_);
        ITU_T_BIND_PER(octet_string_);
        ITU_T_BIND_PER(visible_string_);
        ITU_T_BIND_PER(binary_time_);
        ITU_T_BIND_PER(bcd_);
        ITU_T_BIND_PER(mmsString_);
    }

    template<> void DataParameters::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(9);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(bit_string_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(integer_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(unsignedV_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(floating_point_);
        ITU_T_OPTIONAL_CHECK_PER(4) ITU_T_BIND_PER(octet_string_);
        ITU_T_OPTIONAL_CHECK_PER(5) ITU_T_BIND_PER(visible_string_);
        ITU_T_OPTIONAL_CHECK_PER(6) ITU_T_BIND_PER(binary_time_);
        ITU_T_OPTIONAL_CHECK_PER(7) ITU_T_BIND_PER(bcd_);
        ITU_T_OPTIONAL_CHECK_PER(8) ITU_T_BIND_PER(mmsString_);
    }

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*total_);
        ITU_T_BIND_PER(*exponent_);
    }

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*total_);
        ITU_T_BIND_PER(*exponent_);
    }

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*algorithm_);
    }

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*algorithm_);
    }

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*input_time_out_);
    }

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*input_time_out_);
    }

    template<> void ErrorParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*additionalCode_);
        ITU_T_BIND_PER(*additionalDetial_);
    }

    template<> void ErrorParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*additionalCode_);
        ITU_T_BIND_PER(*additionalDetial_);
    }

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*size_);
        ITU_T_BIND_PER(*syntax_);
    }

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*size_);
        ITU_T_BIND_PER(*syntax_);
    }

    template<> void FileManagementParameters::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
    }

    template<> void FileManagementParameters::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

