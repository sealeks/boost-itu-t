#include "MMS-SCI-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_SCI_Module_1 {



    // sequence SCI-Information

    template<> void SCI_Information::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(partOne_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(partTwo_, 1, CONTEXT_CLASS);
    }

    template<> void SCI_Information::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(partOne_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(partTwo_, 1, CONTEXT_CLASS);
    }

    // sequence VMD-File

    template<> void VMD_File::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(executiveFunction_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(vendorName_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(modelName_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(revision_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(abstractSyntaxes_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(logicalStatus_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(capabilities_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(physicalStatus_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(local_detail_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControlLists_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unitControls_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unnamedVariables_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariables_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariableLists_, 16, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTypes_, 17, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dataExchanges_, 18, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(semaphores_, 19, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(operatorStations_, 20, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 21, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventActions_, 22, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 23, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditionLists_, 24, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(journals_, 25, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_CHOICE(selected_Program_Invocation_);

        ITU_T_RESET_EXTENTION;

    }

    template<> void VMD_File::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(executiveFunction_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(vendorName_, 1, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(modelName_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(revision_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(abstractSyntaxes_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(logicalStatus_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(capabilities_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(physicalStatus_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(local_detail_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControlLists_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unitControls_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unnamedVariables_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariables_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariableLists_, 16, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTypes_, 17, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dataExchanges_, 18, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(semaphores_, 19, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(operatorStations_, 20, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 21, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventActions_, 22, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 23, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditionLists_, 24, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(journals_, 25, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_CHOICE(selected_Program_Invocation_);

        ITU_T_RESET_EXTENTION;

    }

    // choice selected-Program-Invocation

    template<> void VMD_File::Selected_Program_Invocation_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Selected_Program_Invocation_type_selectedProgram:
            {
                ITU_T_BIND_IMPLICIT(value<Program_Invocation_instance > (false, Selected_Program_Invocation_type_selectedProgram), 26, CONTEXT_CLASS);
                break;
            }
            case Selected_Program_Invocation_type_noneSelected:
            {
                ITU_T_BIND_IMPLICIT(value<null_type > (false, Selected_Program_Invocation_type_noneSelected), 27, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<Program_Invocation_instance > (true, Selected_Program_Invocation_type_selectedProgram), 26, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 27:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<null_type > (true, Selected_Program_Invocation_type_noneSelected), 27, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Access_Control_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Access_Control_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(readAccessCondition_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(storeAccessCondition_, 5, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(writeAccessCondition_, 6, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(loadAccessCondition_, 7, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(executeAccessCondition_, 8, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(deleteAccessCondition_, 9, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(editAccessCondition_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControlLists_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unitControls_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unnamedVariables_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariables_, 16, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariableLists_, 17, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTypes_, 18, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dataExchanges_, 19, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(semaphores_, 20, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(operatorStations_, 21, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 22, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventActions_, 23, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 24, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(journals_, 25, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_IMPLICIT(eventConditionLists_, 26, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    template<> void Access_Control_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(readAccessCondition_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(storeAccessCondition_, 5, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(writeAccessCondition_, 6, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(loadAccessCondition_, 7, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(executeAccessCondition_, 8, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(deleteAccessCondition_, 9, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(editAccessCondition_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControlLists_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unitControls_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unnamedVariables_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariables_, 16, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariableLists_, 17, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTypes_, 18, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dataExchanges_, 19, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(semaphores_, 20, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(operatorStations_, 21, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 22, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventActions_, 23, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 24, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(journals_, 25, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_IMPLICIT(eventConditionLists_, 26, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    // sequence Domain-instance

    template<> void Domain_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Domain_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Domain_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(capabilities_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(state_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(sharable_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariables_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariableLists_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTypes_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventActions_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditionLists_, 14, CONTEXT_CLASS);
    }

    template<> void Domain_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(capabilities_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(state_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(sharable_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariables_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedVariableLists_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTypes_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventActions_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditionLists_, 14, CONTEXT_CLASS);
    }

    // sequence Program-Invocation-instance

    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Program_Invocation_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Program_Invocation_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(programInvocationState_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(reusable_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(monitor_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventCondition_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventAction_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollment_, 10, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(executionArgument_, 11, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_IMPLICIT(control_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(controlling_Program_Invocation_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(controlled_Program_Invocations_, 14, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    template<> void Program_Invocation_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(programInvocationState_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(reusable_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(monitor_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventCondition_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventAction_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollment_, 10, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(executionArgument_, 11, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_IMPLICIT(control_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(controlling_Program_Invocation_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(controlled_Program_Invocations_, 14, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    // sequence Unit-Control-instance

    template<> void Unit_Control_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Unit_Control_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Unit_Control_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 5, CONTEXT_CLASS);
    }

    template<> void Unit_Control_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domains_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocations_, 5, CONTEXT_CLASS);
    }

    // sequence Unnamed-Variable-instance

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(address_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(typeDescription_, 2, CONTEXT_CLASS);
    }

    template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(address_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControl_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(typeDescription_, 2, CONTEXT_CLASS);
    }

    // sequence Named-Variable-instance

    template<> void Named_Variable_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Named_Variable_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Named_Variable_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(typeDescription_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(address_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(meaning_, 6, CONTEXT_CLASS);
    }

    template<> void Named_Variable_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(typeDescription_, 4, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(address_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(meaning_, 6, CONTEXT_CLASS);
    }

    // sequence Named-Variable-List-instance

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Named_Variable_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(listOfVariables_, 4, CONTEXT_CLASS);
    }

    template<> void Named_Variable_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(listOfVariables_, 4, CONTEXT_CLASS);
    }

    // sequence Variable-List-Item-instance

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(unnamedItem_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedItem_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(alternateAccess_, 2, CONTEXT_CLASS);
    }

    template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(unnamedItem_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedItem_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(alternateAccess_, 2, CONTEXT_CLASS);
    }

    // sequence Named-Type-instance

    template<> void Named_Type_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Named_Type_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Named_Type_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(typeDescription_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(meaning_, 5, CONTEXT_CLASS);
    }

    template<> void Named_Type_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(typeDescription_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(meaning_, 5, CONTEXT_CLASS);
    }

    // sequence Data-Exchange-instance

    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Data_Exchange_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Data_Exchange_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(request_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(response_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(linked_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocation_, 7, CONTEXT_CLASS);
    }

    template<> void Data_Exchange_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(request_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(response_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(linked_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocation_, 7, CONTEXT_CLASS);
    }

    // sequence Semaphore-instance

    template<> void Semaphore_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Semaphore_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Semaphore_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(classV_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(numberOfTokens_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTokens_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventCondition_, 7, CONTEXT_CLASS);
    }

    template<> void Semaphore_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(classV_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(numberOfTokens_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(namedTokens_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventCondition_, 7, CONTEXT_CLASS);
    }

    // sequence Operator-Station-instance

    template<> void Operator_Station_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Operator_Station_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Operator_Station_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(stationType_, 4, CONTEXT_CLASS);
    }

    template<> void Operator_Station_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(stationType_, 4, CONTEXT_CLASS);
    }

    // sequence Event-Condition-instance

    template<> void Event_Condition_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Event_Condition_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Event_Condition_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(ecClass_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(ecState_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(priority_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(severity_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(enabled_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 10, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(monitoredVariable_);
        ITU_T_BIND_IMPLICIT(evaluationInterval_, 14, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_CHOICE(displayEnhancement_);
        ITU_T_BIND_CHOICE(group_Priority_Override_);
        ITU_T_BIND_IMPLICIT(referencingEventConditionLists_, 20, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    template<> void Event_Condition_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(ecClass_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(ecState_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(priority_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(severity_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(enabled_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(alarmSummaryReports_, 10, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(monitoredVariable_);
        ITU_T_BIND_IMPLICIT(evaluationInterval_, 14, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_CHOICE(displayEnhancement_);
        ITU_T_BIND_CHOICE(group_Priority_Override_);
        ITU_T_BIND_IMPLICIT(referencingEventConditionLists_, 20, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    // choice monitoredVariable

    template<> void Event_Condition_instance::Definition_type::Details_type::MonitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case MonitoredVariable_type_named:
            {
                ITU_T_BIND_IMPLICIT(value<Named_Variable_instance > (false, MonitoredVariable_type_named), 11, CONTEXT_CLASS);
                break;
            }
            case MonitoredVariable_type_unnamed:
            {
                ITU_T_BIND_IMPLICIT(value<Unnamed_Variable_instance > (false, MonitoredVariable_type_unnamed), 12, CONTEXT_CLASS);
                break;
            }
            case MonitoredVariable_type_unspecified:
            {
                ITU_T_BIND_IMPLICIT(value<null_type > (false, MonitoredVariable_type_unspecified), 13, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<Named_Variable_instance > (true, MonitoredVariable_type_named), 11, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Unnamed_Variable_instance > (true, MonitoredVariable_type_unnamed), 12, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<null_type > (true, MonitoredVariable_type_unspecified), 13, CONTEXT_CLASS)) return;
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
                ITU_T_BIND_EXPLICIT(value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text), 15, CONTEXT_CLASS);
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_BIND_IMPLICIT(value<integer_type > (false, DisplayEnhancement_type_number), 16, CONTEXT_CLASS);
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_BIND_IMPLICIT(value<null_type > (false, DisplayEnhancement_type_none), 17, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_EXPLICIT(value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text), 15, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<integer_type > (true, DisplayEnhancement_type_number), 16, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 17:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<null_type > (true, DisplayEnhancement_type_none), 17, CONTEXT_CLASS)) return;
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
                ITU_T_BIND_IMPLICIT(value<MMS_Object_Module_1::Priority > (false, Group_Priority_Override_type_priority), 18, CONTEXT_CLASS);
                break;
            }
            case Group_Priority_Override_type_undefined:
            {
                ITU_T_BIND_IMPLICIT(value<null_type > (false, Group_Priority_Override_type_undefined), 19, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<MMS_Object_Module_1::Priority > (true, Group_Priority_Override_type_priority), 18, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 19:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<null_type > (true, Group_Priority_Override_type_undefined), 19, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Event_Action_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Event_Action_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(confirmedServiceRequest_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(modifiers_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 6, CONTEXT_CLASS);
    }

    template<> void Event_Action_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(confirmedServiceRequest_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(modifiers_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventEnrollments_, 6, CONTEXT_CLASS);
    }

    // sequence Event-Enrollment-instance

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Event_Enrollment_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eeClass_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventCondition_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(ecTransitions_, 6, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(remainingDelay_);
        ITU_T_BIND_IMPLICIT(eventAction_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(duration_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(clientApplication_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aaRule_, 12, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_CHOICE(displayEnhancement_);

        ITU_T_RESET_EXTENTION;

    }

    template<> void Event_Enrollment_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eeClass_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventCondition_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(ecTransitions_, 6, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(remainingDelay_);
        ITU_T_BIND_IMPLICIT(eventAction_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(duration_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(clientApplication_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(aaRule_, 12, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_CHOICE(displayEnhancement_);

        ITU_T_RESET_EXTENTION;

    }

    // choice remainingDelay

    template<> void Event_Enrollment_instance::Definition_type::Details_type::RemainingDelay_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case RemainingDelay_type_time:
            {
                ITU_T_BIND_IMPLICIT(value<integer_type > (false, RemainingDelay_type_time), 7, CONTEXT_CLASS);
                break;
            }
            case RemainingDelay_type_forever:
            {
                ITU_T_BIND_IMPLICIT(value<null_type > (false, RemainingDelay_type_forever), 8, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<integer_type > (true, RemainingDelay_type_time), 7, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 8:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<null_type > (true, RemainingDelay_type_forever), 8, CONTEXT_CLASS)) return;
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
                ITU_T_BIND_EXPLICIT(value<ISO_9506_MMS_1::MMSString > (false, DisplayEnhancement_type_text), 13, CONTEXT_CLASS);
                break;
            }
            case DisplayEnhancement_type_number:
            {
                ITU_T_BIND_IMPLICIT(value<integer_type > (false, DisplayEnhancement_type_number), 14, CONTEXT_CLASS);
                break;
            }
            case DisplayEnhancement_type_none:
            {
                ITU_T_BIND_IMPLICIT(value<null_type > (false, DisplayEnhancement_type_none), 15, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_EXPLICIT(value<ISO_9506_MMS_1::MMSString > (true, DisplayEnhancement_type_text), 13, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 14:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<integer_type > (true, DisplayEnhancement_type_number), 14, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<null_type > (true, DisplayEnhancement_type_none), 15, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Event_Condition_List_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditionLists_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(referencingEventConditionLists_, 6, CONTEXT_CLASS);
    }

    template<> void Event_Condition_List_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditions_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventConditionLists_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(referencingEventConditionLists_, 6, CONTEXT_CLASS);
    }

    // sequence Journal-instance

    template<> void Journal_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    template<> void Journal_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE(definition_);
    }

    // choice definition

    template<> void Journal_instance::Definition_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Definition_type_reference:
            {
                ITU_T_BIND_IMPLICIT(value<oid_type > (false, Definition_type_reference), 1, CONTEXT_CLASS);
                break;
            }
            case Definition_type_details:
            {
                ITU_T_BIND_IMPLICIT(value<Details_type > (false, Definition_type_details), 2, CONTEXT_CLASS);
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
                        if (ITU_T_BIND_IMPLICIT(value<oid_type > (true, Definition_type_reference), 1, CONTEXT_CLASS)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_BIND_IMPLICIT(value<Details_type > (true, Definition_type_details), 2, CONTEXT_CLASS)) return;
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
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(entries_, 4, CONTEXT_CLASS);
    }

    template<> void Journal_instance::Definition_type::Details_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(accessControl_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(entries_, 4, CONTEXT_CLASS);
    }

    // sequence Journal-Entry-instance

    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(journal_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(entry_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(clientApplication_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(timeStamp_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(orderOfReceipt_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(informationType_, 5, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(textComment_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventTransitionRecord_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(journalVariables_, 10, CONTEXT_CLASS);
    }

    template<> void Journal_Entry_instance::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(journal_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(entry_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(clientApplication_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(timeStamp_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(orderOfReceipt_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(informationType_, 5, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(textComment_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(eventTransitionRecord_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(journalVariables_, 10, CONTEXT_CLASS);
    }

    // sequence eventTransitionRecord

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(currentState_, 9, CONTEXT_CLASS);
    }

    template<> void Journal_Entry_instance::EventTransitionRecord_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(name_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(currentState_, 9, CONTEXT_CLASS);
    }

    // sequence 

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(variableTag_, 11, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(valueSpecification_, 12, CONTEXT_CLASS);
    }

    template<> void Journal_Entry_instance::JournalVariables_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(variableTag_, 11, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(valueSpecification_, 12, CONTEXT_CLASS);
    }

    // sequence Service-and-Parameter-CBBs

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(services_Client_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(services_Server_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(parameters_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(nest_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(extendedServices_Client_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(extendedServices_Server_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(extendedParameters_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(generalManagement_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(vMDSupport_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domainManagement_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocation_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(variableAccess_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dataParameters_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(semaphoreManagement_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(operatorCommunication_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(errors_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(fileManagement_, 16, CONTEXT_CLASS);
    }

    template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(services_Client_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(services_Server_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(parameters_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(nest_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(extendedServices_Client_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(extendedServices_Server_, 5, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(extendedParameters_, 6, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(generalManagement_, 7, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(vMDSupport_, 8, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(domainManagement_, 9, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(programInvocation_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(variableAccess_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(dataParameters_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(semaphoreManagement_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(operatorCommunication_, 14, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(errors_, 15, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(fileManagement_, 16, CONTEXT_CLASS);
    }

    // sequence GeneralManagementParameters

    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(localDetail_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(supportForTime_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(granularityOfTime_, 4, CONTEXT_CLASS);
    }

    template<> void GeneralManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(localDetail_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(supportForTime_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(granularityOfTime_, 4, CONTEXT_CLASS);
    }

    // sequence supportForTime

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(timeOfDay_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(timeSequence_, 3, CONTEXT_CLASS);
    }

    template<> void GeneralManagementParameters::SupportForTime_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(timeOfDay_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(timeSequence_, 3, CONTEXT_CLASS);
    }

    // sequence VMDSupportParameters

    template<> void VMDSupportParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(localDetail_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(extendedDerivation_, 1, CONTEXT_CLASS);
    }

    template<> void VMDSupportParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(localDetail_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(extendedDerivation_, 1, CONTEXT_CLASS);
    }

    // sequence DomainManagementParameters

    template<> void DomainManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(loadDataOctet_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(loadDataSyntax_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(maxUploads_, 2, CONTEXT_CLASS);
    }

    template<> void DomainManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(loadDataOctet_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(loadDataSyntax_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(maxUploads_, 2, CONTEXT_CLASS);
    }

    // sequence ProgramInvocationManagementParameters

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(executionArgMaxSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(executionArgParseRules_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(executionArgSyntaxes_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(programLoction_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(stepMode_, 4, CONTEXT_CLASS);
    }

    template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(executionArgMaxSize_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(executionArgParseRules_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(executionArgSyntaxes_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(programLoction_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(stepMode_, 4, CONTEXT_CLASS);
    }

    // sequence VariableAccessParameters

    template<> void VariableAccessParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(uninterruptibleAccess_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(singleMode_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unnamedMode_, 2, CONTEXT_CLASS);
    }

    template<> void VariableAccessParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(uninterruptibleAccess_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(singleMode_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unnamedMode_, 2, CONTEXT_CLASS);
    }

    // sequence DataParameters

    template<> void DataParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(bit_stringV_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(integer_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unsignedV_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(floating_point_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(octet_stringV_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(visible_stringV_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(binary_time_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(bcd_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(mmsString_, 14, CONTEXT_CLASS);
    }

    template<> void DataParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(bit_stringV_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(integer_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(unsignedV_, 2, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(floating_point_, 3, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(octet_stringV_, 10, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(visible_stringV_, 11, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(binary_time_, 12, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(bcd_, 13, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(mmsString_, 14, CONTEXT_CLASS);
    }

    // sequence floating-point

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(total_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(exponent_, 5, CONTEXT_CLASS);
    }

    template<> void DataParameters::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(total_, 4, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(exponent_, 5, CONTEXT_CLASS);
    }

    // sequence SemaphoreManagementParameters

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(algorithm_, 0, CONTEXT_CLASS);
    }

    template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(algorithm_, 0, CONTEXT_CLASS);
    }

    // sequence OperatorCommunicationParameters

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(input_time_out_, 0, CONTEXT_CLASS);
    }

    template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(input_time_out_, 0, CONTEXT_CLASS);
    }

    // sequence ErrorParameters

    template<> void ErrorParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(additionalCode_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(additionalDetial_, 1, CONTEXT_CLASS);
    }

    template<> void ErrorParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(additionalCode_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(additionalDetial_, 1, CONTEXT_CLASS);
    }

    // sequence additionalDetial

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(size_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(syntax_, 3, CONTEXT_CLASS);
    }

    template<> void ErrorParameters::AdditionalDetial_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(size_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(syntax_, 3, CONTEXT_CLASS);
    }

    // sequence FileManagementParameters

    template<> void FileManagementParameters::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(fileName_, 0, CONTEXT_CLASS);
    }

    template<> void FileManagementParameters::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(fileName_, 0, CONTEXT_CLASS);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

