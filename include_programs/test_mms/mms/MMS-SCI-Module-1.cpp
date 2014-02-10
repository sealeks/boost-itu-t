#include "MMS-SCI-Module-1.hpp"

namespace MMS_SCI_Module_1 {

        // sequence SCI-Information

        template<> void SCI_Information::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(partOne, 0);
            BOOST_ASN_IMPLICIT_TAG(partTwo, 1);
        }

        template<> void SCI_Information::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(partOne, 0);
            BOOST_ASN_IMPLICIT_TAG(partTwo, 1);
        }

 
        // sequence VMD-File


        template<> void VMD_File::selected_Program_Invocation_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case selected_Program_Invocation_type_selectedProgram:  {BOOST_ASN_IMPLICIT_TAG(value<Program_Invocation_instance > (false , selected_Program_Invocation_type_selectedProgram), 26); break; }
                case selected_Program_Invocation_type_noneSelected:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , selected_Program_Invocation_type_noneSelected), 27); break; }
                default:{}
            }
        }

        template<> void VMD_File::selected_Program_Invocation_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 26:  { if (BOOST_ASN_IMPLICIT_TAG(value<Program_Invocation_instance > (true , selected_Program_Invocation_type_selectedProgram), 26)) return; else free(); break;}
                        case 27:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , selected_Program_Invocation_type_noneSelected), 27)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void VMD_File::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(executiveFunction, 0);
            BOOST_ASN_EXPLICIT_TAG(vendorName, 1);
            BOOST_ASN_EXPLICIT_TAG(modelName, 2);
            BOOST_ASN_EXPLICIT_TAG(revision, 3);
            BOOST_ASN_IMPLICIT_TAG(abstractSyntaxes, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 5);
            BOOST_ASN_IMPLICIT_TAG(logicalStatus, 6);
            BOOST_ASN_IMPLICIT_TAG(capabilities, 7);
            BOOST_ASN_IMPLICIT_TAG(physicalStatus, 8);
            BOOST_ASN_IMPLICIT_TAG(local_detail, 9);
            BOOST_ASN_IMPLICIT_TAG(accessControlLists, 10);
            BOOST_ASN_IMPLICIT_TAG(domains, 11);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 12);
            BOOST_ASN_IMPLICIT_TAG(unitControls, 13);
            BOOST_ASN_IMPLICIT_TAG(unnamedVariables, 14);
            BOOST_ASN_IMPLICIT_TAG(namedVariables, 15);
            BOOST_ASN_IMPLICIT_TAG(namedVariableLists, 16);
            BOOST_ASN_IMPLICIT_TAG(namedTypes, 17);
            BOOST_ASN_IMPLICIT_TAG(dataExchanges, 18);
            BOOST_ASN_IMPLICIT_TAG(semaphores, 19);
            BOOST_ASN_IMPLICIT_TAG(operatorStations, 20);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 21);
            BOOST_ASN_IMPLICIT_TAG(eventActions, 22);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 23);
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 24);
            BOOST_ASN_IMPLICIT_TAG(journals, 25);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE(selected_Program_Invocation);
        }

        template<> void VMD_File::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(executiveFunction, 0);
            BOOST_ASN_EXPLICIT_TAG(vendorName, 1);
            BOOST_ASN_EXPLICIT_TAG(modelName, 2);
            BOOST_ASN_EXPLICIT_TAG(revision, 3);
            BOOST_ASN_IMPLICIT_TAG(abstractSyntaxes, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 5);
            BOOST_ASN_IMPLICIT_TAG(logicalStatus, 6);
            BOOST_ASN_IMPLICIT_TAG(capabilities, 7);
            BOOST_ASN_IMPLICIT_TAG(physicalStatus, 8);
            BOOST_ASN_IMPLICIT_TAG(local_detail, 9);
            BOOST_ASN_IMPLICIT_TAG(accessControlLists, 10);
            BOOST_ASN_IMPLICIT_TAG(domains, 11);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 12);
            BOOST_ASN_IMPLICIT_TAG(unitControls, 13);
            BOOST_ASN_IMPLICIT_TAG(unnamedVariables, 14);
            BOOST_ASN_IMPLICIT_TAG(namedVariables, 15);
            BOOST_ASN_IMPLICIT_TAG(namedVariableLists, 16);
            BOOST_ASN_IMPLICIT_TAG(namedTypes, 17);
            BOOST_ASN_IMPLICIT_TAG(dataExchanges, 18);
            BOOST_ASN_IMPLICIT_TAG(semaphores, 19);
            BOOST_ASN_IMPLICIT_TAG(operatorStations, 20);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 21);
            BOOST_ASN_IMPLICIT_TAG(eventActions, 22);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 23);
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 24);
            BOOST_ASN_IMPLICIT_TAG(journals, 25);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE(selected_Program_Invocation);
        }

 
        // sequence Access-Control-List-instance



        template<> void Access_Control_List_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(readAccessCondition, 4);
            BOOST_ASN_CHOICE_TAG(storeAccessCondition, 5);
            BOOST_ASN_CHOICE_TAG(writeAccessCondition, 6);
            BOOST_ASN_CHOICE_TAG(loadAccessCondition, 7);
            BOOST_ASN_CHOICE_TAG(executeAccessCondition, 8);
            BOOST_ASN_CHOICE_TAG(deleteAccessCondition, 9);
            BOOST_ASN_CHOICE_TAG(editAccessCondition, 10);
            BOOST_ASN_IMPLICIT_TAG(accessControlLists, 11);
            BOOST_ASN_IMPLICIT_TAG(domains, 12);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 13);
            BOOST_ASN_IMPLICIT_TAG(unitControls, 14);
            BOOST_ASN_IMPLICIT_TAG(unnamedVariables, 15);
            BOOST_ASN_IMPLICIT_TAG(namedVariables, 16);
            BOOST_ASN_IMPLICIT_TAG(namedVariableLists, 17);
            BOOST_ASN_IMPLICIT_TAG(namedTypes, 18);
            BOOST_ASN_IMPLICIT_TAG(dataExchanges, 19);
            BOOST_ASN_IMPLICIT_TAG(semaphores, 20);
            BOOST_ASN_IMPLICIT_TAG(operatorStations, 21);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 22);
            BOOST_ASN_IMPLICIT_TAG(eventActions, 23);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 24);
            BOOST_ASN_IMPLICIT_TAG(journals, 25);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 26);
        }

        template<> void Access_Control_List_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(readAccessCondition, 4);
            BOOST_ASN_CHOICE_TAG(storeAccessCondition, 5);
            BOOST_ASN_CHOICE_TAG(writeAccessCondition, 6);
            BOOST_ASN_CHOICE_TAG(loadAccessCondition, 7);
            BOOST_ASN_CHOICE_TAG(executeAccessCondition, 8);
            BOOST_ASN_CHOICE_TAG(deleteAccessCondition, 9);
            BOOST_ASN_CHOICE_TAG(editAccessCondition, 10);
            BOOST_ASN_IMPLICIT_TAG(accessControlLists, 11);
            BOOST_ASN_IMPLICIT_TAG(domains, 12);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 13);
            BOOST_ASN_IMPLICIT_TAG(unitControls, 14);
            BOOST_ASN_IMPLICIT_TAG(unnamedVariables, 15);
            BOOST_ASN_IMPLICIT_TAG(namedVariables, 16);
            BOOST_ASN_IMPLICIT_TAG(namedVariableLists, 17);
            BOOST_ASN_IMPLICIT_TAG(namedTypes, 18);
            BOOST_ASN_IMPLICIT_TAG(dataExchanges, 19);
            BOOST_ASN_IMPLICIT_TAG(semaphores, 20);
            BOOST_ASN_IMPLICIT_TAG(operatorStations, 21);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 22);
            BOOST_ASN_IMPLICIT_TAG(eventActions, 23);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 24);
            BOOST_ASN_IMPLICIT_TAG(journals, 25);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 26);
        }

 

        template<> void Access_Control_List_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Access_Control_List_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Access_Control_List_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Access_Control_List_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Domain-instance



        template<> void Domain_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(capabilities, 3);
            BOOST_ASN_IMPLICIT_TAG(state, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 5);
            BOOST_ASN_IMPLICIT_TAG(sharable, 6);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 7);
            BOOST_ASN_IMPLICIT_TAG(namedVariables, 8);
            BOOST_ASN_IMPLICIT_TAG(namedVariableLists, 9);
            BOOST_ASN_IMPLICIT_TAG(namedTypes, 10);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 11);
            BOOST_ASN_IMPLICIT_TAG(eventActions, 12);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 13);
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 14);
        }

        template<> void Domain_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(capabilities, 3);
            BOOST_ASN_IMPLICIT_TAG(state, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 5);
            BOOST_ASN_IMPLICIT_TAG(sharable, 6);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 7);
            BOOST_ASN_IMPLICIT_TAG(namedVariables, 8);
            BOOST_ASN_IMPLICIT_TAG(namedVariableLists, 9);
            BOOST_ASN_IMPLICIT_TAG(namedTypes, 10);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 11);
            BOOST_ASN_IMPLICIT_TAG(eventActions, 12);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 13);
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 14);
        }

 

        template<> void Domain_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Domain_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Domain_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Domain_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Program-Invocation-instance



        template<> void Program_Invocation_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationState, 3);
            BOOST_ASN_IMPLICIT_TAG(domains, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 5);
            BOOST_ASN_IMPLICIT_TAG(reusable, 6);
            BOOST_ASN_IMPLICIT_TAG(monitor, 7);
            BOOST_ASN_IMPLICIT_TAG(eventCondition, 8);
            BOOST_ASN_IMPLICIT_TAG(eventAction, 9);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollment, 10);
            BOOST_ASN_EXPLICIT_TAG(executionArgument, 11);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(control, 12);
            BOOST_ASN_IMPLICIT_TAG(controlling_Program_Invocation, 13);
            BOOST_ASN_IMPLICIT_TAG(controlled_Program_Invocations, 14);
        }

        template<> void Program_Invocation_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(programInvocationState, 3);
            BOOST_ASN_IMPLICIT_TAG(domains, 4);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 5);
            BOOST_ASN_IMPLICIT_TAG(reusable, 6);
            BOOST_ASN_IMPLICIT_TAG(monitor, 7);
            BOOST_ASN_IMPLICIT_TAG(eventCondition, 8);
            BOOST_ASN_IMPLICIT_TAG(eventAction, 9);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollment, 10);
            BOOST_ASN_EXPLICIT_TAG(executionArgument, 11);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_IMPLICIT_TAG(control, 12);
            BOOST_ASN_IMPLICIT_TAG(controlling_Program_Invocation, 13);
            BOOST_ASN_IMPLICIT_TAG(controlled_Program_Invocations, 14);
        }

 

        template<> void Program_Invocation_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Program_Invocation_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Program_Invocation_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Program_Invocation_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Unit-Control-instance



        template<> void Unit_Control_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(domains, 4);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 5);
        }

        template<> void Unit_Control_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(domains, 4);
            BOOST_ASN_IMPLICIT_TAG(programInvocations, 5);
        }

 

        template<> void Unit_Control_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Unit_Control_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Unit_Control_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Unit_Control_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Unnamed-Variable-instance

        template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(address, 0);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 1);
            BOOST_ASN_CHOICE_TAG(typeDescription, 2);
        }

        template<> void Unnamed_Variable_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(address, 0);
            BOOST_ASN_IMPLICIT_TAG(accessControl, 1);
            BOOST_ASN_CHOICE_TAG(typeDescription, 2);
        }

 
        // sequence Named-Variable-instance



        template<> void Named_Variable_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(typeDescription, 4);
            BOOST_ASN_CHOICE_TAG(address, 5);
            BOOST_ASN_IMPLICIT_TAG(meaning, 6);
        }

        template<> void Named_Variable_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(typeDescription, 4);
            BOOST_ASN_CHOICE_TAG(address, 5);
            BOOST_ASN_IMPLICIT_TAG(meaning, 6);
        }

 

        template<> void Named_Variable_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Named_Variable_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Named_Variable_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Named_Variable_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Named-Variable-List-instance



        template<> void Named_Variable_List_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(listOfVariables, 4);
        }

        template<> void Named_Variable_List_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(listOfVariables, 4);
        }

 

        template<> void Named_Variable_List_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Named_Variable_List_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Named_Variable_List_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Variable-List-Item-instance

        template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unnamedItem, 0);
            BOOST_ASN_IMPLICIT_TAG(namedItem, 1);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 2);
        }

        template<> void Variable_List_Item_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(unnamedItem, 0);
            BOOST_ASN_IMPLICIT_TAG(namedItem, 1);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 2);
        }

 
        // sequence Named-Type-instance



        template<> void Named_Type_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(typeDescription, 4);
            BOOST_ASN_IMPLICIT_TAG(meaning, 5);
        }

        template<> void Named_Type_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(typeDescription, 4);
            BOOST_ASN_IMPLICIT_TAG(meaning, 5);
        }

 

        template<> void Named_Type_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Named_Type_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Named_Type_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Named_Type_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Data-Exchange-instance



        template<> void Data_Exchange_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(request, 4);
            BOOST_ASN_IMPLICIT_TAG(response, 5);
            BOOST_ASN_IMPLICIT_TAG(linked, 6);
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 7);
        }

        template<> void Data_Exchange_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(request, 4);
            BOOST_ASN_IMPLICIT_TAG(response, 5);
            BOOST_ASN_IMPLICIT_TAG(linked, 6);
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 7);
        }

 

        template<> void Data_Exchange_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Data_Exchange_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Data_Exchange_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Data_Exchange_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Semaphore-instance


    const int Semaphore_instance::definition_type::details_type::classV_token = 0;
    const int Semaphore_instance::definition_type::details_type::classV_pool = 1;


        template<> void Semaphore_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(classV, 4);
            BOOST_ASN_IMPLICIT_TAG(numberOfTokens, 5);
            BOOST_ASN_IMPLICIT_TAG(namedTokens, 6);
            BOOST_ASN_IMPLICIT_TAG(eventCondition, 7);
        }

        template<> void Semaphore_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(classV, 4);
            BOOST_ASN_IMPLICIT_TAG(numberOfTokens, 5);
            BOOST_ASN_IMPLICIT_TAG(namedTokens, 6);
            BOOST_ASN_IMPLICIT_TAG(eventCondition, 7);
        }

 

        template<> void Semaphore_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Semaphore_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Semaphore_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Semaphore_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Operator-Station-instance


    const int Operator_Station_instance::definition_type::details_type::stationType_entry = 0;
    const int Operator_Station_instance::definition_type::details_type::stationType_display = 1;
    const int Operator_Station_instance::definition_type::details_type::stationType_entry_display = 2;


        template<> void Operator_Station_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(stationType, 4);
        }

        template<> void Operator_Station_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(stationType, 4);
        }

 

        template<> void Operator_Station_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Operator_Station_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Operator_Station_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Operator_Station_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Event-Condition-instance




        template<> void Event_Condition_instance::definition_type::details_type::monitoredVariable_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case monitoredVariable_type_named:  {BOOST_ASN_IMPLICIT_TAG(value<Named_Variable_instance > (false , monitoredVariable_type_named), 11); break; }
                case monitoredVariable_type_unnamed:  {BOOST_ASN_IMPLICIT_TAG(value<Unnamed_Variable_instance > (false , monitoredVariable_type_unnamed), 12); break; }
                case monitoredVariable_type_unspecified:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , monitoredVariable_type_unspecified), 13); break; }
                default:{}
            }
        }

        template<> void Event_Condition_instance::definition_type::details_type::monitoredVariable_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<Named_Variable_instance > (true , monitoredVariable_type_named), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<Unnamed_Variable_instance > (true , monitoredVariable_type_unnamed), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , monitoredVariable_type_unspecified), 13)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 


        template<> void Event_Condition_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case displayEnhancement_type_text:  {BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (false , displayEnhancement_type_text), 15); break; }
                case displayEnhancement_type_number:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_number), 16); break; }
                case displayEnhancement_type_none:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , displayEnhancement_type_none), 17); break; }
                default:{}
            }
        }

        template<> void Event_Condition_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 15:  { if (BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (true , displayEnhancement_type_text), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_number), 16)) return; else free(); break;}
                        case 17:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , displayEnhancement_type_none), 17)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 


        template<> void Event_Condition_instance::definition_type::details_type::group_Priority_Override_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case group_Priority_Override_type_priority:  {BOOST_ASN_IMPLICIT_TAG(value<MMS_Object_Module_1::Priority > (false , group_Priority_Override_type_priority), 18); break; }
                case group_Priority_Override_type_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , group_Priority_Override_type_undefined), 19); break; }
                default:{}
            }
        }

        template<> void Event_Condition_instance::definition_type::details_type::group_Priority_Override_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 18:  { if (BOOST_ASN_IMPLICIT_TAG(value<MMS_Object_Module_1::Priority > (true , group_Priority_Override_type_priority), 18)) return; else free(); break;}
                        case 19:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , group_Priority_Override_type_undefined), 19)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Event_Condition_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(ecClass, 4);
            BOOST_ASN_IMPLICIT_TAG(ecState, 5);
            BOOST_ASN_IMPLICIT_TAG(priority, 6);
            BOOST_ASN_IMPLICIT_TAG(severity, 7);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 8);
            BOOST_ASN_IMPLICIT_TAG(enabled, 9);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 10);
            BOOST_ASN_CHOICE(monitoredVariable);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 14);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE(displayEnhancement);
            BOOST_ASN_CHOICE(group_Priority_Override);
            BOOST_ASN_IMPLICIT_TAG(referencingEventConditionLists, 20);
        }

        template<> void Event_Condition_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(ecClass, 4);
            BOOST_ASN_IMPLICIT_TAG(ecState, 5);
            BOOST_ASN_IMPLICIT_TAG(priority, 6);
            BOOST_ASN_IMPLICIT_TAG(severity, 7);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 8);
            BOOST_ASN_IMPLICIT_TAG(enabled, 9);
            BOOST_ASN_IMPLICIT_TAG(alarmSummaryReports, 10);
            BOOST_ASN_CHOICE(monitoredVariable);
            BOOST_ASN_IMPLICIT_TAG(evaluationInterval, 14);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE(displayEnhancement);
            BOOST_ASN_CHOICE(group_Priority_Override);
            BOOST_ASN_IMPLICIT_TAG(referencingEventConditionLists, 20);
        }

 

        template<> void Event_Condition_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Event_Condition_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Event_Condition_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Event_Condition_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Event-Action-instance



        template<> void Event_Action_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(confirmedServiceRequest, 4);
            BOOST_ASN_IMPLICIT_TAG(modifiers, 5);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 6);
        }

        template<> void Event_Action_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_CHOICE_TAG(confirmedServiceRequest, 4);
            BOOST_ASN_IMPLICIT_TAG(modifiers, 5);
            BOOST_ASN_IMPLICIT_TAG(eventEnrollments, 6);
        }

 

        template<> void Event_Action_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Event_Action_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Event_Action_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Event_Action_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Event-Enrollment-instance




        template<> void Event_Enrollment_instance::definition_type::details_type::remainingDelay_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case remainingDelay_type_time:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , remainingDelay_type_time), 7); break; }
                case remainingDelay_type_forever:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , remainingDelay_type_forever), 8); break; }
                default:{}
            }
        }

        template<> void Event_Enrollment_instance::definition_type::details_type::remainingDelay_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , remainingDelay_type_time), 7)) return; else free(); break;}
                        case 8:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , remainingDelay_type_forever), 8)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 


        template<> void Event_Enrollment_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case displayEnhancement_type_text:  {BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (false , displayEnhancement_type_text), 13); break; }
                case displayEnhancement_type_number:  {BOOST_ASN_IMPLICIT_TAG(value<int > (false , displayEnhancement_type_number), 14); break; }
                case displayEnhancement_type_none:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , displayEnhancement_type_none), 15); break; }
                default:{}
            }
        }

        template<> void Event_Enrollment_instance::definition_type::details_type::displayEnhancement_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 13:  { if (BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (true , displayEnhancement_type_text), 13)) return; else free(); break;}
                        case 14:  { if (BOOST_ASN_IMPLICIT_TAG(value<int > (true , displayEnhancement_type_number), 14)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , displayEnhancement_type_none), 15)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Event_Enrollment_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(eeClass, 4);
            BOOST_ASN_IMPLICIT_TAG(eventCondition, 5);
            BOOST_ASN_IMPLICIT_TAG(ecTransitions, 6);
            BOOST_ASN_CHOICE(remainingDelay);
            BOOST_ASN_IMPLICIT_TAG(eventAction, 9);
            BOOST_ASN_IMPLICIT_TAG(duration, 10);
            BOOST_ASN_IMPLICIT_TAG(clientApplication, 11);
            BOOST_ASN_IMPLICIT_TAG(aaRule, 12);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE(displayEnhancement);
        }

        template<> void Event_Enrollment_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(eeClass, 4);
            BOOST_ASN_IMPLICIT_TAG(eventCondition, 5);
            BOOST_ASN_IMPLICIT_TAG(ecTransitions, 6);
            BOOST_ASN_CHOICE(remainingDelay);
            BOOST_ASN_IMPLICIT_TAG(eventAction, 9);
            BOOST_ASN_IMPLICIT_TAG(duration, 10);
            BOOST_ASN_IMPLICIT_TAG(clientApplication, 11);
            BOOST_ASN_IMPLICIT_TAG(aaRule, 12);
            BOOST_ASN_EXTENTION;
            BOOST_ASN_CHOICE(displayEnhancement);
        }

 

        template<> void Event_Enrollment_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Event_Enrollment_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Event_Enrollment_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Event-Condition-List-instance



        template<> void Event_Condition_List_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 4);
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 5);
            BOOST_ASN_IMPLICIT_TAG(referencingEventConditionLists, 6);
        }

        template<> void Event_Condition_List_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(eventConditions, 4);
            BOOST_ASN_IMPLICIT_TAG(eventConditionLists, 5);
            BOOST_ASN_IMPLICIT_TAG(referencingEventConditionLists, 6);
        }

 

        template<> void Event_Condition_List_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Event_Condition_List_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Event_Condition_List_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Journal-instance



        template<> void Journal_instance::definition_type::details_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(entries, 4);
        }

        template<> void Journal_instance::definition_type::details_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(accessControl, 3);
            BOOST_ASN_IMPLICIT_TAG(entries, 4);
        }

 

        template<> void Journal_instance::definition_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case definition_type_reference:  {BOOST_ASN_IMPLICIT_TAG(value<oid_type > (false , definition_type_reference), 1); break; }
                case definition_type_details:  {BOOST_ASN_IMPLICIT_TAG(value<details_type > (false , definition_type_details), 2); break; }
                default:{}
            }
        }

        template<> void Journal_instance::definition_type::serialize(boost::asn1::x690::input_coder& arch){
            int __tag_id__ =arch.test_id();
            switch(arch.test_class()){
                case 0x0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x40: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                case 0x80: {
                    switch(__tag_id__){
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<oid_type > (true , definition_type_reference), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<details_type > (true , definition_type_details), 2)) return; else free(); break;}
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                }
            }
        }

 

        template<> void Journal_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

        template<> void Journal_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 0);
            BOOST_ASN_CHOICE(definition);
        }

 
        // sequence Journal-Entry-instance
    const int Journal_Entry_instance::informationType_annotation = 0;
    const int Journal_Entry_instance::informationType_event_data = 1;
    const int Journal_Entry_instance::informationType_data = 2;



        template<> void Journal_Entry_instance::eventTransitionRecord_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 8);
            BOOST_ASN_IMPLICIT_TAG(currentState, 9);
        }

        template<> void Journal_Entry_instance::eventTransitionRecord_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(name, 8);
            BOOST_ASN_IMPLICIT_TAG(currentState, 9);
        }

 


        template<> void Journal_Entry_instance::journalVariables_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(variableTag, 11);
            BOOST_ASN_CHOICE_TAG(valueSpecification, 12);
        }

        template<> void Journal_Entry_instance::journalVariables_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(variableTag, 11);
            BOOST_ASN_CHOICE_TAG(valueSpecification, 12);
        }

 

        template<> void Journal_Entry_instance::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(journal, 0);
            BOOST_ASN_IMPLICIT_TAG(entry, 1);
            BOOST_ASN_IMPLICIT_TAG(clientApplication, 2);
            BOOST_ASN_IMPLICIT_TAG(timeStamp, 3);
            BOOST_ASN_IMPLICIT_TAG(orderOfReceipt, 4);
            BOOST_ASN_IMPLICIT_TAG(informationType, 5);
            BOOST_ASN_EXPLICIT_TAG(textComment, 6);
            BOOST_ASN_IMPLICIT_TAG(eventTransitionRecord, 7);
            BOOST_ASN_IMPLICIT_TAG(journalVariables, 10);
        }

        template<> void Journal_Entry_instance::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(journal, 0);
            BOOST_ASN_IMPLICIT_TAG(entry, 1);
            BOOST_ASN_IMPLICIT_TAG(clientApplication, 2);
            BOOST_ASN_IMPLICIT_TAG(timeStamp, 3);
            BOOST_ASN_IMPLICIT_TAG(orderOfReceipt, 4);
            BOOST_ASN_IMPLICIT_TAG(informationType, 5);
            BOOST_ASN_EXPLICIT_TAG(textComment, 6);
            BOOST_ASN_IMPLICIT_TAG(eventTransitionRecord, 7);
            BOOST_ASN_IMPLICIT_TAG(journalVariables, 10);
        }

 
        // sequence Service-and-Parameter-CBBs

        template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(services_Client, 0);
            BOOST_ASN_IMPLICIT_TAG(services_Server, 1);
            BOOST_ASN_IMPLICIT_TAG(parameters, 2);
            BOOST_ASN_IMPLICIT_TAG(nest, 3);
            BOOST_ASN_IMPLICIT_TAG(extendedServices_Client, 4);
            BOOST_ASN_IMPLICIT_TAG(extendedServices_Server, 5);
            BOOST_ASN_IMPLICIT_TAG(extendedParameters, 6);
            BOOST_ASN_IMPLICIT_TAG(generalManagement, 7);
            BOOST_ASN_IMPLICIT_TAG(vMDSupport, 8);
            BOOST_ASN_IMPLICIT_TAG(domainManagement, 9);
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 10);
            BOOST_ASN_IMPLICIT_TAG(variableAccess, 11);
            BOOST_ASN_IMPLICIT_TAG(dataParameters, 12);
            BOOST_ASN_IMPLICIT_TAG(semaphoreManagement, 13);
            BOOST_ASN_IMPLICIT_TAG(operatorCommunication, 14);
            BOOST_ASN_IMPLICIT_TAG(errors, 15);
            BOOST_ASN_IMPLICIT_TAG(fileManagement, 16);
        }

        template<> void Service_and_Parameter_CBBs::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(services_Client, 0);
            BOOST_ASN_IMPLICIT_TAG(services_Server, 1);
            BOOST_ASN_IMPLICIT_TAG(parameters, 2);
            BOOST_ASN_IMPLICIT_TAG(nest, 3);
            BOOST_ASN_IMPLICIT_TAG(extendedServices_Client, 4);
            BOOST_ASN_IMPLICIT_TAG(extendedServices_Server, 5);
            BOOST_ASN_IMPLICIT_TAG(extendedParameters, 6);
            BOOST_ASN_IMPLICIT_TAG(generalManagement, 7);
            BOOST_ASN_IMPLICIT_TAG(vMDSupport, 8);
            BOOST_ASN_IMPLICIT_TAG(domainManagement, 9);
            BOOST_ASN_IMPLICIT_TAG(programInvocation, 10);
            BOOST_ASN_IMPLICIT_TAG(variableAccess, 11);
            BOOST_ASN_IMPLICIT_TAG(dataParameters, 12);
            BOOST_ASN_IMPLICIT_TAG(semaphoreManagement, 13);
            BOOST_ASN_IMPLICIT_TAG(operatorCommunication, 14);
            BOOST_ASN_IMPLICIT_TAG(errors, 15);
            BOOST_ASN_IMPLICIT_TAG(fileManagement, 16);
        }

 
        // sequence GeneralManagementParameters


        template<> void GeneralManagementParameters::supportForTime_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(timeOfDay, 2);
            BOOST_ASN_IMPLICIT_TAG(timeSequence, 3);
        }

        template<> void GeneralManagementParameters::supportForTime_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(timeOfDay, 2);
            BOOST_ASN_IMPLICIT_TAG(timeSequence, 3);
        }

 

        template<> void GeneralManagementParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(localDetail, 0);
            BOOST_ASN_IMPLICIT_TAG(supportForTime, 1);
            BOOST_ASN_IMPLICIT_TAG(granularityOfTime, 4);
        }

        template<> void GeneralManagementParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(localDetail, 0);
            BOOST_ASN_IMPLICIT_TAG(supportForTime, 1);
            BOOST_ASN_IMPLICIT_TAG(granularityOfTime, 4);
        }

 
        // sequence VMDSupportParameters

        template<> void VMDSupportParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(localDetail, 0);
            BOOST_ASN_EXPLICIT_TAG(extendedDerivation, 1);
        }

        template<> void VMDSupportParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(localDetail, 0);
            BOOST_ASN_EXPLICIT_TAG(extendedDerivation, 1);
        }

 
        // sequence DomainManagementParameters

        template<> void DomainManagementParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(loadDataOctet, 0);
            BOOST_ASN_IMPLICIT_TAG(loadDataSyntax, 1);
            BOOST_ASN_IMPLICIT_TAG(maxUploads, 2);
        }

        template<> void DomainManagementParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(loadDataOctet, 0);
            BOOST_ASN_IMPLICIT_TAG(loadDataSyntax, 1);
            BOOST_ASN_IMPLICIT_TAG(maxUploads, 2);
        }

 
        // sequence ProgramInvocationManagementParameters

        template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(executionArgMaxSize, 0);
            BOOST_ASN_EXPLICIT_TAG(executionArgParseRules, 1);
            BOOST_ASN_IMPLICIT_TAG(executionArgSyntaxes, 2);
            BOOST_ASN_EXPLICIT_TAG(programLoction, 3);
            BOOST_ASN_IMPLICIT_TAG(stepMode, 4);
        }

        template<> void ProgramInvocationManagementParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(executionArgMaxSize, 0);
            BOOST_ASN_EXPLICIT_TAG(executionArgParseRules, 1);
            BOOST_ASN_IMPLICIT_TAG(executionArgSyntaxes, 2);
            BOOST_ASN_EXPLICIT_TAG(programLoction, 3);
            BOOST_ASN_IMPLICIT_TAG(stepMode, 4);
        }

 
        // sequence VariableAccessParameters

        template<> void VariableAccessParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(uninterruptibleAccess, 0);
            BOOST_ASN_IMPLICIT_TAG(singleMode, 1);
            BOOST_ASN_IMPLICIT_TAG(unnamedMode, 2);
        }

        template<> void VariableAccessParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(uninterruptibleAccess, 0);
            BOOST_ASN_IMPLICIT_TAG(singleMode, 1);
            BOOST_ASN_IMPLICIT_TAG(unnamedMode, 2);
        }

 
        // sequence DataParameters


        template<> void DataParameters::floating_point_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(total, 4);
            BOOST_ASN_IMPLICIT_TAG(exponent, 5);
        }

        template<> void DataParameters::floating_point_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(total, 4);
            BOOST_ASN_IMPLICIT_TAG(exponent, 5);
        }

 

        template<> void DataParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(bit_string, 0);
            BOOST_ASN_IMPLICIT_TAG(integer, 1);
            BOOST_ASN_IMPLICIT_TAG(unsignedV, 2);
            BOOST_ASN_IMPLICIT_TAG(floating_point, 3);
            BOOST_ASN_IMPLICIT_TAG(octet_string, 10);
            BOOST_ASN_IMPLICIT_TAG(visible_string, 11);
            BOOST_ASN_IMPLICIT_TAG(binary_time, 12);
            BOOST_ASN_IMPLICIT_TAG(bcd, 13);
            BOOST_ASN_IMPLICIT_TAG(mmsString, 14);
        }

        template<> void DataParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(bit_string, 0);
            BOOST_ASN_IMPLICIT_TAG(integer, 1);
            BOOST_ASN_IMPLICIT_TAG(unsignedV, 2);
            BOOST_ASN_IMPLICIT_TAG(floating_point, 3);
            BOOST_ASN_IMPLICIT_TAG(octet_string, 10);
            BOOST_ASN_IMPLICIT_TAG(visible_string, 11);
            BOOST_ASN_IMPLICIT_TAG(binary_time, 12);
            BOOST_ASN_IMPLICIT_TAG(bcd, 13);
            BOOST_ASN_IMPLICIT_TAG(mmsString, 14);
        }

 
        // sequence SemaphoreManagementParameters

        template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(algorithm, 0);
        }

        template<> void SemaphoreManagementParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(algorithm, 0);
        }

 
        // sequence OperatorCommunicationParameters

        template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(input_time_out, 0);
        }

        template<> void OperatorCommunicationParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(input_time_out, 0);
        }

 
        // sequence ErrorParameters


        template<> void ErrorParameters::additionalDetial_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(size, 2);
            BOOST_ASN_EXPLICIT_TAG(syntax, 3);
        }

        template<> void ErrorParameters::additionalDetial_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(size, 2);
            BOOST_ASN_EXPLICIT_TAG(syntax, 3);
        }

 

        template<> void ErrorParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(additionalCode, 0);
            BOOST_ASN_IMPLICIT_TAG(additionalDetial, 1);
        }

        template<> void ErrorParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(additionalCode, 0);
            BOOST_ASN_IMPLICIT_TAG(additionalDetial, 1);
        }

 
        // sequence FileManagementParameters

        template<> void FileManagementParameters::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(fileName, 0);
        }

        template<> void FileManagementParameters::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(fileName, 0);
        }

 
} 
