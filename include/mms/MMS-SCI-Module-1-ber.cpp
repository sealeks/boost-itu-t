#include "MMS-SCI-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {

    // sequence SCI-Information

    template<> void SCI_Information::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*partOne_, 0);
        ITU_T_IMPLICIT_TAG(*partTwo_, 1);
    }

    template<> void SCI_Information::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*partOne_, 0);
        ITU_T_IMPLICIT_TAG(*partTwo_, 1);
    }

    // sequence VMD-File

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
        ITU_T_RESET_EXTENTION;
        ITU_T_BIND_CHOICE(selected_Program_Invocation_);
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
        ITU_T_RESET_EXTENTION;
        ITU_T_BIND_CHOICE(selected_Program_Invocation_);
    }

    // choice selected-Program-Invocation

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
            default:
            {
            }
        }
    }

    // sequence Access-Control-List-instance

    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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
        ITU_T_RESET_EXTENTION;
        ITU_T_IMPLICIT_TAG(eventConditionLists_, 26);
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
        ITU_T_RESET_EXTENTION;
        ITU_T_IMPLICIT_TAG(eventConditionLists_, 26);
    }

    // sequence Domain-instance

    template<> void Domain_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Domain_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Program-Invocation-instance

    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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
        ITU_T_RESET_EXTENTION;
        ITU_T_IMPLICIT_TAG(control_, 12);
        ITU_T_IMPLICIT_TAG(controlling_Program_Invocation_, 13);
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
        ITU_T_RESET_EXTENTION;
        ITU_T_IMPLICIT_TAG(control_, 12);
        ITU_T_IMPLICIT_TAG(controlling_Program_Invocation_, 13);
        ITU_T_IMPLICIT_TAG(controlled_Program_Invocations_, 14);
    }

    // sequence Unit-Control-instance

    template<> void Unit_Control_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Unit_Control_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Unnamed-Variable-instance

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

    // sequence Named-Variable-instance

    template<> void Named_Variable_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Named_Variable_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Named-Variable-List-instance

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*listOfVariables_, 4);
    }

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*listOfVariables_, 4);
    }

    // sequence Variable-List-Item-instance

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

    // sequence Named-Type-instance

    template<> void Named_Type_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Named_Type_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Data-Exchange-instance

    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Semaphore-instance

    template<> void Semaphore_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Semaphore_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Operator-Station-instance

    template<> void Operator_Station_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Operator_Station_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*stationType_, 4);
    }

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*stationType_, 4);
    }

    // sequence Event-Condition-instance

    template<> void Event_Condition_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Condition_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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
        ITU_T_RESET_EXTENTION;
        ITU_T_BIND_CHOICE(displayEnhancement_);
        ITU_T_BIND_CHOICE(group_Priority_Override_);
        ITU_T_IMPLICIT_TAG(referencingEventConditionLists_, 20);
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
        ITU_T_RESET_EXTENTION;
        ITU_T_BIND_CHOICE(displayEnhancement_);
        ITU_T_BIND_CHOICE(group_Priority_Override_);
        ITU_T_IMPLICIT_TAG(referencingEventConditionLists_, 20);
    }

    // choice monitoredVariable

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
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void Event_Condition_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text), 15);
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, DisplayEnhancement_type_number), 16);
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
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, DisplayEnhancement_type_number), 16)) return;
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
            default:
            {
            }
        }
    }

    // choice group-Priority-Override

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
            default:
            {
            }
        }
    }

    // sequence Event-Action-instance

    template<> void Event_Action_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Action_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Event-Enrollment-instance

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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
        ITU_T_RESET_EXTENTION;
        ITU_T_BIND_CHOICE(displayEnhancement_);
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
        ITU_T_RESET_EXTENTION;
        ITU_T_BIND_CHOICE(displayEnhancement_);
    }

    // choice remainingDelay

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RemainingDelay_type_time:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, RemainingDelay_type_time), 7);
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
            case 0x80:
            {
                switch (__tag_id__) {
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, RemainingDelay_type_time), 7)) return;
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
            default:
            {
            }
        }
    }

    // choice displayEnhancement

    template<> void Event_Enrollment_instance::Definition_type::Details_type::DisplayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case DisplayEnhancement_type_text:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text), 13);
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_IMPLICIT_TAG(*value<integer_type > (false, DisplayEnhancement_type_number), 14);
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
                        if (ITU_T_IMPLICIT_TAG(*value<integer_type > (true, DisplayEnhancement_type_number), 14)) return;
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
            default:
            {
            }
        }
    }

    // sequence Event-Condition-List-instance

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

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

    // sequence Journal-instance

    template<> void Journal_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    template<> void Journal_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 0);
        ITU_T_BIND_CHOICE(*definition_);
    }

    // choice definition

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
            default:
            {
            }
        }
    }

    // sequence details

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*entries_, 4);
    }

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*accessControl_, 3);
        ITU_T_IMPLICIT_TAG(*entries_, 4);
    }

    // sequence Journal-Entry-instance

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

    // sequence eventTransitionRecord

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 8);
        ITU_T_IMPLICIT_TAG(*currentState_, 9);
    }

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*name_, 8);
        ITU_T_IMPLICIT_TAG(*currentState_, 9);
    }

    // sequence 

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*variableTag_, 11);
        ITU_T_CHOICE_TAG(*valueSpecification_, 12);
    }

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*variableTag_, 11);
        ITU_T_CHOICE_TAG(*valueSpecification_, 12);
    }

    // sequence Service-and-Parameter-CBBs

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

    // sequence GeneralManagementParameters

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

    // sequence supportForTime

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*timeOfDay_, 2);
        ITU_T_IMPLICIT_TAG(*timeSequence_, 3);
    }

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*timeOfDay_, 2);
        ITU_T_IMPLICIT_TAG(*timeSequence_, 3);
    }

    // sequence VMDSupportParameters

    template<> void VMDSupportParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*localDetail_, 0);
        ITU_T_EXPLICIT_TAG(*extendedDerivation_, 1);
    }

    template<> void VMDSupportParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*localDetail_, 0);
        ITU_T_EXPLICIT_TAG(*extendedDerivation_, 1);
    }

    // sequence DomainManagementParameters

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

    // sequence ProgramInvocationManagementParameters

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

    // sequence VariableAccessParameters

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

    // sequence DataParameters

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

    // sequence floating-point

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*total_, 4);
        ITU_T_IMPLICIT_TAG(*exponent_, 5);
    }

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*total_, 4);
        ITU_T_IMPLICIT_TAG(*exponent_, 5);
    }

    // sequence SemaphoreManagementParameters

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*algorithm_, 0);
    }

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*algorithm_, 0);
    }

    // sequence OperatorCommunicationParameters

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*input_time_out_, 0);
    }

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*input_time_out_, 0);
    }

    // sequence ErrorParameters

    template<> void ErrorParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*additionalCode_, 0);
        ITU_T_IMPLICIT_TAG(*additionalDetial_, 1);
    }

    template<> void ErrorParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*additionalCode_, 0);
        ITU_T_IMPLICIT_TAG(*additionalDetial_, 1);
    }

    // sequence additionalDetial

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*size_, 2);
        ITU_T_EXPLICIT_TAG(*syntax_, 3);
    }

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*size_, 2);
        ITU_T_EXPLICIT_TAG(*syntax_, 3);
    }

    // sequence FileManagementParameters

    template<> void FileManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*fileName_, 0);
    }

    template<> void FileManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*fileName_, 0);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

