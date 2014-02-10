#include "MMS-Object-Module-1.hpp"

namespace MMS_Object_Module_1 {

    const int LogicalStatus_state_changes_allowed = 0;
    const int LogicalStatus_no_state_changes_allowed = 1;
    const int LogicalStatus_limited_services_permitted = 2;
    const int LogicalStatus_support_services_allowed = 3;

    const int PhysicalStatus_operational = 0;
    const int PhysicalStatus_partially_operational = 1;
    const int PhysicalStatus_inoperable = 2;
    const int PhysicalStatus_needs_commissioning = 3;

    const int VMDState_idle = 0;
    const int VMDState_loaded = 1;
    const int VMDState_ready = 2;
    const int VMDState_executing = 3;
    const int VMDState_motion_paused = 4;
    const int VMDState_manualInterventionRequired = 5;

        // sequence ModifierStep

        template<> void ModifierStep::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(modifierID);
            BOOST_ASN_CHOICE(modifier);
        }

        template<> void ModifierStep::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(modifierID);
            BOOST_ASN_CHOICE(modifier);
        }

 
        // choice Modifier

        template<> void Modifier::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Modifier_eventModifier:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToEventCondition > (false , Modifier_eventModifier), 0); break; }
                case Modifier_semaphoreModifier:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToSemaphore > (false , Modifier_semaphoreModifier), 1); break; }
                default:{}
            }
        }

        template<> void Modifier::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToEventCondition > (true , Modifier_eventModifier), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::AttachToSemaphore > (true , Modifier_semaphoreModifier), 1)) return; else free(); break;}
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

 
    const bitstring_type ServiceSupportOptions_status = bitstring_type(true, 0);
    const bitstring_type ServiceSupportOptions_getNameList = bitstring_type(true, 1);
    const bitstring_type ServiceSupportOptions_identify = bitstring_type(true, 2);
    const bitstring_type ServiceSupportOptions_rename = bitstring_type(true, 3);
    const bitstring_type ServiceSupportOptions_read = bitstring_type(true, 4);
    const bitstring_type ServiceSupportOptions_write = bitstring_type(true, 5);
    const bitstring_type ServiceSupportOptions_getVariableAccessAttributes = bitstring_type(true, 6);
    const bitstring_type ServiceSupportOptions_defineNamedVariable = bitstring_type(true, 7);
    const bitstring_type ServiceSupportOptions_defineScatteredAccess = bitstring_type(true, 8);
    const bitstring_type ServiceSupportOptions_getScatteredAccessAttributes = bitstring_type(true, 9);
    const bitstring_type ServiceSupportOptions_deleteVariableAccess = bitstring_type(true, 10);
    const bitstring_type ServiceSupportOptions_defineNamedVariableList = bitstring_type(true, 11);
    const bitstring_type ServiceSupportOptions_getNamedVariableListAttributes = bitstring_type(true, 12);
    const bitstring_type ServiceSupportOptions_deleteNamedVariableList = bitstring_type(true, 13);
    const bitstring_type ServiceSupportOptions_defineNamedType = bitstring_type(true, 14);
    const bitstring_type ServiceSupportOptions_getNamedTypeAttributes = bitstring_type(true, 15);
    const bitstring_type ServiceSupportOptions_deleteNamedType = bitstring_type(true, 16);
    const bitstring_type ServiceSupportOptions_input = bitstring_type(true, 17);
    const bitstring_type ServiceSupportOptions_output = bitstring_type(true, 18);
    const bitstring_type ServiceSupportOptions_takeControl = bitstring_type(true, 19);
    const bitstring_type ServiceSupportOptions_relinquishControl = bitstring_type(true, 20);
    const bitstring_type ServiceSupportOptions_defineSemaphore = bitstring_type(true, 21);
    const bitstring_type ServiceSupportOptions_deleteSemaphore = bitstring_type(true, 22);
    const bitstring_type ServiceSupportOptions_reportSemaphoreStatus = bitstring_type(true, 23);
    const bitstring_type ServiceSupportOptions_reportPoolSemaphoreStatus = bitstring_type(true, 24);
    const bitstring_type ServiceSupportOptions_reportSemaphoreEntryStatus = bitstring_type(true, 25);
    const bitstring_type ServiceSupportOptions_initiateDownloadSequence = bitstring_type(true, 26);
    const bitstring_type ServiceSupportOptions_downloadSegment = bitstring_type(true, 27);
    const bitstring_type ServiceSupportOptions_terminateDownloadSequence = bitstring_type(true, 28);
    const bitstring_type ServiceSupportOptions_initiateUploadSequence = bitstring_type(true, 29);
    const bitstring_type ServiceSupportOptions_uploadSegment = bitstring_type(true, 30);
    const bitstring_type ServiceSupportOptions_terminateUploadSequence = bitstring_type(true, 31);
    const bitstring_type ServiceSupportOptions_requestDomainDownload = bitstring_type(true, 32);
    const bitstring_type ServiceSupportOptions_requestDomainUpload = bitstring_type(true, 33);
    const bitstring_type ServiceSupportOptions_loadDomainContent = bitstring_type(true, 34);
    const bitstring_type ServiceSupportOptions_storeDomainContent = bitstring_type(true, 35);
    const bitstring_type ServiceSupportOptions_deleteDomain = bitstring_type(true, 36);
    const bitstring_type ServiceSupportOptions_getDomainAttributes = bitstring_type(true, 37);
    const bitstring_type ServiceSupportOptions_createProgramInvocation = bitstring_type(true, 38);
    const bitstring_type ServiceSupportOptions_deleteProgramInvocation = bitstring_type(true, 39);
    const bitstring_type ServiceSupportOptions_start = bitstring_type(true, 40);
    const bitstring_type ServiceSupportOptions_stop = bitstring_type(true, 41);
    const bitstring_type ServiceSupportOptions_resume = bitstring_type(true, 42);
    const bitstring_type ServiceSupportOptions_reset = bitstring_type(true, 43);
    const bitstring_type ServiceSupportOptions_kill = bitstring_type(true, 44);
    const bitstring_type ServiceSupportOptions_getProgramInvocationAttributes = bitstring_type(true, 45);
    const bitstring_type ServiceSupportOptions_obtainFile = bitstring_type(true, 46);
    const bitstring_type ServiceSupportOptions_defineEventCondition = bitstring_type(true, 47);
    const bitstring_type ServiceSupportOptions_deleteEventCondition = bitstring_type(true, 48);
    const bitstring_type ServiceSupportOptions_getEventConditionAttributes = bitstring_type(true, 49);
    const bitstring_type ServiceSupportOptions_reportEventConditionStatus = bitstring_type(true, 50);
    const bitstring_type ServiceSupportOptions_alterEventConditionMonitoring = bitstring_type(true, 51);
    const bitstring_type ServiceSupportOptions_triggerEvent = bitstring_type(true, 52);
    const bitstring_type ServiceSupportOptions_defineEventAction = bitstring_type(true, 53);
    const bitstring_type ServiceSupportOptions_deleteEventAction = bitstring_type(true, 54);
    const bitstring_type ServiceSupportOptions_getEventActionAttributes = bitstring_type(true, 55);
    const bitstring_type ServiceSupportOptions_reportEventActionStatus = bitstring_type(true, 56);
    const bitstring_type ServiceSupportOptions_defineEventEnrollment = bitstring_type(true, 57);
    const bitstring_type ServiceSupportOptions_deleteEventEnrollment = bitstring_type(true, 58);
    const bitstring_type ServiceSupportOptions_alterEventEnrollment = bitstring_type(true, 59);
    const bitstring_type ServiceSupportOptions_reportEventEnrollmentStatus = bitstring_type(true, 60);
    const bitstring_type ServiceSupportOptions_getEventEnrollmentAttributes = bitstring_type(true, 61);
    const bitstring_type ServiceSupportOptions_acknowledgeEventNotification = bitstring_type(true, 62);
    const bitstring_type ServiceSupportOptions_getAlarmSummary = bitstring_type(true, 63);
    const bitstring_type ServiceSupportOptions_getAlarmEnrollmentSummary = bitstring_type(true, 64);
    const bitstring_type ServiceSupportOptions_readJournal = bitstring_type(true, 65);
    const bitstring_type ServiceSupportOptions_writeJournal = bitstring_type(true, 66);
    const bitstring_type ServiceSupportOptions_initializeJournal = bitstring_type(true, 67);
    const bitstring_type ServiceSupportOptions_reportJournalStatus = bitstring_type(true, 68);
    const bitstring_type ServiceSupportOptions_createJournal = bitstring_type(true, 69);
    const bitstring_type ServiceSupportOptions_deleteJournal = bitstring_type(true, 70);
    const bitstring_type ServiceSupportOptions_getCapabilityList = bitstring_type(true, 71);
    const bitstring_type ServiceSupportOptions_fileOpen = bitstring_type(true, 72);
    const bitstring_type ServiceSupportOptions_fileRead = bitstring_type(true, 73);
    const bitstring_type ServiceSupportOptions_fileClose = bitstring_type(true, 74);
    const bitstring_type ServiceSupportOptions_fileRename = bitstring_type(true, 75);
    const bitstring_type ServiceSupportOptions_fileDelete = bitstring_type(true, 76);
    const bitstring_type ServiceSupportOptions_fileDirectory = bitstring_type(true, 77);
    const bitstring_type ServiceSupportOptions_unsolicitedStatus = bitstring_type(true, 78);
    const bitstring_type ServiceSupportOptions_informationReport = bitstring_type(true, 79);
    const bitstring_type ServiceSupportOptions_eventNotification = bitstring_type(true, 80);
    const bitstring_type ServiceSupportOptions_attachToEventCondition = bitstring_type(true, 81);
    const bitstring_type ServiceSupportOptions_attachToSemaphore = bitstring_type(true, 82);
    const bitstring_type ServiceSupportOptions_conclude = bitstring_type(true, 83);
    const bitstring_type ServiceSupportOptions_cancel = bitstring_type(true, 84);
    const bitstring_type ServiceSupportOptions_getDataExchangeAttributes = bitstring_type(true, 85);
    const bitstring_type ServiceSupportOptions_exchangeData = bitstring_type(true, 86);
    const bitstring_type ServiceSupportOptions_defineAccessControlList = bitstring_type(true, 87);
    const bitstring_type ServiceSupportOptions_getAccessControlListAttributes = bitstring_type(true, 88);
    const bitstring_type ServiceSupportOptions_reportAccessControlledObjects = bitstring_type(true, 89);
    const bitstring_type ServiceSupportOptions_deleteAccessControlList = bitstring_type(true, 90);
    const bitstring_type ServiceSupportOptions_alterAccessControl = bitstring_type(true, 91);
    const bitstring_type ServiceSupportOptions_reconfigureProgramInvocation = bitstring_type(true, 92);

    const bitstring_type ParameterSupportOptions_str1 = bitstring_type(true, 0);
    const bitstring_type ParameterSupportOptions_str2 = bitstring_type(true, 1);
    const bitstring_type ParameterSupportOptions_vnam = bitstring_type(true, 2);
    const bitstring_type ParameterSupportOptions_valt = bitstring_type(true, 3);
    const bitstring_type ParameterSupportOptions_vadr = bitstring_type(true, 4);
    const bitstring_type ParameterSupportOptions_vsca = bitstring_type(true, 5);
    const bitstring_type ParameterSupportOptions_tpy = bitstring_type(true, 6);
    const bitstring_type ParameterSupportOptions_vlis = bitstring_type(true, 7);
    const bitstring_type ParameterSupportOptions_cei = bitstring_type(true, 10);
    const bitstring_type ParameterSupportOptions_aco = bitstring_type(true, 11);
    const bitstring_type ParameterSupportOptions_sem = bitstring_type(true, 12);
    const bitstring_type ParameterSupportOptions_csr = bitstring_type(true, 13);
    const bitstring_type ParameterSupportOptions_csnc = bitstring_type(true, 14);
    const bitstring_type ParameterSupportOptions_csplc = bitstring_type(true, 15);
    const bitstring_type ParameterSupportOptions_cspi = bitstring_type(true, 16);
    const bitstring_type ParameterSupportOptions_char = bitstring_type(true, 17);

    const bitstring_type AdditionalSupportOptions_vMDStop = bitstring_type(true, 0);
    const bitstring_type AdditionalSupportOptions_vMDReset = bitstring_type(true, 1);
    const bitstring_type AdditionalSupportOptions_select = bitstring_type(true, 2);
    const bitstring_type AdditionalSupportOptions_alterProgramInvocationAttributes = bitstring_type(true, 3);
    const bitstring_type AdditionalSupportOptions_initiateUnitControlLoad = bitstring_type(true, 4);
    const bitstring_type AdditionalSupportOptions_unitControlLoadSegment = bitstring_type(true, 5);
    const bitstring_type AdditionalSupportOptions_unitControlUpload = bitstring_type(true, 6);
    const bitstring_type AdditionalSupportOptions_startUnitControl = bitstring_type(true, 7);
    const bitstring_type AdditionalSupportOptions_stopUnitControl = bitstring_type(true, 8);
    const bitstring_type AdditionalSupportOptions_createUnitControl = bitstring_type(true, 9);
    const bitstring_type AdditionalSupportOptions_addToUnitControl = bitstring_type(true, 10);
    const bitstring_type AdditionalSupportOptions_removeFromUnitControl = bitstring_type(true, 11);
    const bitstring_type AdditionalSupportOptions_getUnitControlAttributes = bitstring_type(true, 12);
    const bitstring_type AdditionalSupportOptions_loadUnitControlFromFile = bitstring_type(true, 13);
    const bitstring_type AdditionalSupportOptions_storeUnitControlToFile = bitstring_type(true, 14);
    const bitstring_type AdditionalSupportOptions_deleteUnitControl = bitstring_type(true, 15);
    const bitstring_type AdditionalSupportOptions_defineEventConditionList = bitstring_type(true, 16);
    const bitstring_type AdditionalSupportOptions_deleteEventConditionList = bitstring_type(true, 17);
    const bitstring_type AdditionalSupportOptions_addEventConditionListReference = bitstring_type(true, 18);
    const bitstring_type AdditionalSupportOptions_removeEventConditionListReference = bitstring_type(true, 19);
    const bitstring_type AdditionalSupportOptions_getEventConditionListAttributes = bitstring_type(true, 20);
    const bitstring_type AdditionalSupportOptions_reportEventConditionListStatus = bitstring_type(true, 21);
    const bitstring_type AdditionalSupportOptions_alterEventConditionListMonitoring = bitstring_type(true, 22);

    const bitstring_type AdditionalCBBOptions_des = bitstring_type(true, 0);
    const bitstring_type AdditionalCBBOptions_dei = bitstring_type(true, 1);
    const bitstring_type AdditionalCBBOptions_recl = bitstring_type(true, 2);

        // choice AccessCondition


        template<> void AccessCondition::user_type::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case user_type_association:  {BOOST_ASN_BIND_TAG(value<MMS_Environment_1::ApplicationReference > (false , user_type_association)); break; }
                case user_type_none:  {BOOST_ASN_BIND_TAG(value<null_type > (false , user_type_none)); break; }
                default:{}
            }
        }

        template<> void AccessCondition::user_type::serialize(boost::asn1::x690::input_coder& arch){
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
                    default:{}
                    }
                }
                case 0xC0: {
                    switch(__tag_id__){
                    default:{}
                    }
                }
                default: {
                         if (BOOST_ASN_BIND_TAG(value<MMS_Environment_1::ApplicationReference > (true , user_type_association))) return; else free();
                         if (BOOST_ASN_BIND_TAG(value<null_type > (true , user_type_none))) return; else free();
                }
            }
        }

 

        template<> void AccessCondition::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case AccessCondition_never:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , AccessCondition_never), 0); break; }
                case AccessCondition_semaphore:  {BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::Identifier > (false , AccessCondition_semaphore), 1); break; }
                case AccessCondition_user:  {BOOST_ASN_CHOICE_TAG(value<user_type > (false , AccessCondition_user), 2); break; }
                case AccessCondition_password:  {BOOST_ASN_CHOICE_TAG(value<ACSE_1::Authentication_value > (false , AccessCondition_password), 3); break; }
                case AccessCondition_joint:  {BOOST_ASN_IMPLICIT_TAG(value<joint_type > (false , AccessCondition_joint), 4); break; }
                case AccessCondition_alternate:  {BOOST_ASN_IMPLICIT_TAG(value<alternate_type > (false , AccessCondition_alternate), 5); break; }
                default:{}
            }
        }

        template<> void AccessCondition::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , AccessCondition_never), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::Identifier > (true , AccessCondition_semaphore), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_CHOICE_TAG(value<user_type > (true , AccessCondition_user), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_CHOICE_TAG(value<ACSE_1::Authentication_value > (true , AccessCondition_password), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<joint_type > (true , AccessCondition_joint), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<alternate_type > (true , AccessCondition_alternate), 5)) return; else free(); break;}
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

 
    const int DomainState_non_existent = 0;
    const int DomainState_loading = 1;
    const int DomainState_ready = 2;
    const int DomainState_in_use = 3;
    const int DomainState_complete = 4;
    const int DomainState_incomplete = 5;
    const int DomainState_d1 = 7;
    const int DomainState_d2 = 8;
    const int DomainState_d3 = 9;
    const int DomainState_d4 = 10;
    const int DomainState_d5 = 11;
    const int DomainState_d6 = 12;
    const int DomainState_d7 = 13;
    const int DomainState_d8 = 14;
    const int DomainState_d9 = 15;

    const int ULState_non_existent = 0;
    const int ULState_uploading = 1;
    const int ULState_uploaded = 2;
    const int ULState_u1 = 3;
    const int ULState_u2 = 4;
    const int ULState_u3 = 5;
    const int ULState_u4 = 6;

    const int ProgramInvocationState_non_existent = 0;
    const int ProgramInvocationState_unrunnable = 1;
    const int ProgramInvocationState_idle = 2;
    const int ProgramInvocationState_running = 3;
    const int ProgramInvocationState_stopped = 4;
    const int ProgramInvocationState_starting = 5;
    const int ProgramInvocationState_stopping = 6;
    const int ProgramInvocationState_resuming = 7;
    const int ProgramInvocationState_resetting = 8;

    const int Control_State_normal = 0;
    const int Control_State_controlling = 1;
    const int Control_State_controlled = 2;

    const int Running_Mode_free_run = 0;
    const int Running_Mode_cycle_limited = 1;
    const int Running_Mode_step_limited = 2;

        // choice Address

        template<> void Address::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Address_numericAddress:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (false , Address_numericAddress), 0); break; }
                case Address_symbolicAddress:  {BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (false , Address_symbolicAddress), 1); break; }
                case Address_unconstrainedAddress:  {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , Address_unconstrainedAddress), 2); break; }
                default:{}
            }
        }

        template<> void Address::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (true , Address_numericAddress), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::MMSString > (true , Address_symbolicAddress), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , Address_unconstrainedAddress), 2)) return; else free(); break;}
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

 
        // choice TypeDescription


        template<> void TypeDescription::array_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(packed, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfElements, 1);
            BOOST_ASN_CHOICE_TAG(elementType, 2);
        }

        template<> void TypeDescription::array_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(packed, 0);
            BOOST_ASN_IMPLICIT_TAG(numberOfElements, 1);
            BOOST_ASN_CHOICE_TAG(elementType, 2);
        }

 



        template<> void TypeDescription::structure_type::components_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(componentName, 0);
            BOOST_ASN_CHOICE_TAG(componentType, 1);
        }

        template<> void TypeDescription::structure_type::components_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(componentName, 0);
            BOOST_ASN_CHOICE_TAG(componentType, 1);
        }

 

        template<> void TypeDescription::structure_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(packed, 0);
            BOOST_ASN_IMPLICIT_TAG(components, 1);
        }

        template<> void TypeDescription::structure_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(packed, 0);
            BOOST_ASN_IMPLICIT_TAG(components, 1);
        }

 


        template<> void TypeDescription::floating_point_type::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(format_width);
            BOOST_ASN_BIND_TAG(exponent_width);
        }

        template<> void TypeDescription::floating_point_type::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(format_width);
            BOOST_ASN_BIND_TAG(exponent_width);
        }

 

        template<> void TypeDescription::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case TypeDescription_array:  {BOOST_ASN_IMPLICIT_TAG(value<array_type > (false , TypeDescription_array), 1); break; }
                case TypeDescription_structure:  {BOOST_ASN_IMPLICIT_TAG(value<structure_type > (false , TypeDescription_structure), 2); break; }
                case TypeDescription_boolean:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TypeDescription_boolean), 3); break; }
                case TypeDescription_bit_string:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false , TypeDescription_bit_string), 4); break; }
                case TypeDescription_integer:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (false , TypeDescription_integer), 5); break; }
                case TypeDescription_unsignedV:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (false , TypeDescription_unsignedV), 6); break; }
                case TypeDescription_floating_point:  {BOOST_ASN_IMPLICIT_TAG(value<floating_point_type > (false , TypeDescription_floating_point), 7); break; }
                case TypeDescription_octet_string:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false , TypeDescription_octet_string), 9); break; }
                case TypeDescription_visible_string:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false , TypeDescription_visible_string), 10); break; }
                case TypeDescription_generalized_time:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TypeDescription_generalized_time), 11); break; }
                case TypeDescription_binary_time:  {BOOST_ASN_IMPLICIT_TAG(value<bool > (false , TypeDescription_binary_time), 12); break; }
                case TypeDescription_bcd:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (false , TypeDescription_bcd), 13); break; }
                case TypeDescription_objId:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TypeDescription_objId), 15); break; }
                case TypeDescription_mMSString:  {BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (false , TypeDescription_mMSString), 16); break; }
                default:{}
            }
        }

        template<> void TypeDescription::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<array_type > (true , TypeDescription_array), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<structure_type > (true , TypeDescription_structure), 2)) return; else free(); break;}
                        case 3:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TypeDescription_boolean), 3)) return; else free(); break;}
                        case 4:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true , TypeDescription_bit_string), 4)) return; else free(); break;}
                        case 5:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (true , TypeDescription_integer), 5)) return; else free(); break;}
                        case 6:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (true , TypeDescription_unsignedV), 6)) return; else free(); break;}
                        case 7:  { if (BOOST_ASN_IMPLICIT_TAG(value<floating_point_type > (true , TypeDescription_floating_point), 7)) return; else free(); break;}
                        case 9:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true , TypeDescription_octet_string), 9)) return; else free(); break;}
                        case 10:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true , TypeDescription_visible_string), 10)) return; else free(); break;}
                        case 11:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TypeDescription_generalized_time), 11)) return; else free(); break;}
                        case 12:  { if (BOOST_ASN_IMPLICIT_TAG(value<bool > (true , TypeDescription_binary_time), 12)) return; else free(); break;}
                        case 13:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned8 > (true , TypeDescription_bcd), 13)) return; else free(); break;}
                        case 15:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TypeDescription_objId), 15)) return; else free(); break;}
                        case 16:  { if (BOOST_ASN_EXPLICIT_TAG(value<ISO_9506_MMS_1::Integer32 > (true , TypeDescription_mMSString), 16)) return; else free(); break;}
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

 
    const int normalPriority = 64;

    const int EC_Class_network_triggered = 0;
    const int EC_Class_monitored = 1;

    const int EC_State_disabled = 0;
    const int EC_State_idle = 1;
    const int EC_State_active = 2;

    const int normalSeverity = 64;

        // choice EventTime

        template<> void EventTime::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case EventTime_timeOfDay:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::TimeOfDay > (false , EventTime_timeOfDay), 0); break; }
                case EventTime_timeSequenceIdentifier:  {BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (false , EventTime_timeSequenceIdentifier), 1); break; }
                case EventTime_undefined:  {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , EventTime_undefined), 2); break; }
                default:{}
            }
        }

        template<> void EventTime::serialize(boost::asn1::x690::input_coder& arch){
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
                        case 0:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::TimeOfDay > (true , EventTime_timeOfDay), 0)) return; else free(); break;}
                        case 1:  { if (BOOST_ASN_IMPLICIT_TAG(value<ISO_9506_MMS_1::Unsigned32 > (true , EventTime_timeSequenceIdentifier), 1)) return; else free(); break;}
                        case 2:  { if (BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , EventTime_undefined), 2)) return; else free(); break;}
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

 
    const int EE_Class_modifier = 0;
    const int EE_Class_notification = 1;

    const bitstring_type Transitions_idle_to_disabled = bitstring_type(true, 0);
    const bitstring_type Transitions_active_to_disabled = bitstring_type(true, 1);
    const bitstring_type Transitions_disabled_to_idle = bitstring_type(true, 2);
    const bitstring_type Transitions_active_to_idle = bitstring_type(true, 3);
    const bitstring_type Transitions_disabled_to_active = bitstring_type(true, 4);
    const bitstring_type Transitions_idle_to_active = bitstring_type(true, 5);
    const bitstring_type Transitions_any_to_deleted = bitstring_type(true, 6);

    const int EE_Duration_current = 0;
    const int EE_Duration_permanent = 1;

    const int AlarmAckRule_none = 0;
    const int AlarmAckRule_simple = 1;
    const int AlarmAckRule_ack_active = 2;
    const int AlarmAckRule_ack_all = 3;

        // sequence Journal-Variable

        template<> void Journal_Variable::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_BIND_TAG(variableTag);
            BOOST_ASN_CHOICE(valueSpecification);
        }

        template<> void Journal_Variable::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_BIND_TAG(variableTag);
            BOOST_ASN_CHOICE(valueSpecification);
        }

 
    const boost::array<boost::asn1::oidindx_type, 6> mMSNamedVariable_OID_ARR = { 1, 0, 9506, 1, 5, 1};
    const boost::asn1::oid_type mMSNamedVariable  = boost::asn1::oid_type(mMSNamedVariable_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 6> mMSAccessControlList_OID_ARR = { 1, 0, 9506, 1, 5, 2};
    const boost::asn1::oid_type mMSAccessControlList  = boost::asn1::oid_type(mMSAccessControlList_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 6> mMSEventCondition_OID_ARR = { 1, 0, 9506, 1, 5, 3};
    const boost::asn1::oid_type mMSEventCondition  = boost::asn1::oid_type(mMSEventCondition_OID_ARR );

} 
