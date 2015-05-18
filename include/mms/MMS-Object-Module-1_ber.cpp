#include "MMS-Object-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {

    template<> void ModifierStep::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*modifierID_);
        ITU_T_BIND_CHOICE(*modifier_);
    }

    template<> void ModifierStep::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*modifierID_);
        ITU_T_BIND_CHOICE(*modifier_);
    }

    template<> void Modifier::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Modifier_eventModifier:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::AttachToEventCondition > (false, Modifier_eventModifier), 0);
                break;
            }
            case Modifier_semaphoreModifier:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::AttachToSemaphore > (false, Modifier_semaphoreModifier), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Modifier::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::AttachToEventCondition > (true, Modifier_eventModifier), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::AttachToSemaphore > (true, Modifier_semaphoreModifier), 1)) return;
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

    template<> void AccessCondition::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AccessCondition_never:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, AccessCondition_never), 0);
                break;
            }
            case AccessCondition_semaphore:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::Identifier > (false, AccessCondition_semaphore), 1);
                break;
            }
            case AccessCondition_user:
            {
                ITU_T_CHOICE_TAG(*value<User_type > (false, AccessCondition_user), 2);
                break;
            }
            case AccessCondition_password:
            {
                ITU_T_CHOICE_TAG(*value<ACSE_1::Authentication_value > (false, AccessCondition_password), 3);
                break;
            }
            case AccessCondition_joint:
            {
                ITU_T_IMPLICIT_TAG(*value<Joint_type > (false, AccessCondition_joint), 4);
                break;
            }
            case AccessCondition_alternate:
            {
                ITU_T_IMPLICIT_TAG(*value<Alternate_type > (false, AccessCondition_alternate), 5);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessCondition::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, AccessCondition_never), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::Identifier > (true, AccessCondition_semaphore), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_CHOICE_TAG(*value<User_type > (true, AccessCondition_user), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_CHOICE_TAG(*value<ACSE_1::Authentication_value > (true, AccessCondition_password), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Joint_type > (true, AccessCondition_joint), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Alternate_type > (true, AccessCondition_alternate), 5)) return;
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

    template<> void AccessCondition::User_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_type_association:
            {
                ITU_T_BIND_TAG(*value<MMS_Environment_1::ApplicationReference > (false, User_type_association));
                break;
            }
            case User_type_none:
            {
                ITU_T_BIND_TAG(*value<null_type > (false, User_type_none));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessCondition::User_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(*value<MMS_Environment_1::ApplicationReference > (true, User_type_association))) return;
                else free();
                if (ITU_T_BIND_TAG(*value<null_type > (true, User_type_none))) return;
                else free();
            }
        }
    }

    template<> void Address::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Address_numericAddress:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned32 > (false, Address_numericAddress), 0);
                break;
            }
            case Address_symbolicAddress:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (false, Address_symbolicAddress), 1);
                break;
            }
            case Address_unconstrainedAddress:
            {
                ITU_T_IMPLICIT_TAG(*value<octetstring_type > (false, Address_unconstrainedAddress), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Address::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned32 > (true, Address_numericAddress), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::MMSString > (true, Address_symbolicAddress), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<octetstring_type > (true, Address_unconstrainedAddress), 2)) return;
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

    template<> void TypeDescription::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case TypeDescription_array:
            {
                ITU_T_IMPLICIT_TAG(*value<Array_type > (false, TypeDescription_array), 1);
                break;
            }
            case TypeDescription_structure:
            {
                ITU_T_IMPLICIT_TAG(*value<Structure_type > (false, TypeDescription_structure), 2);
                break;
            }
            case TypeDescription_boolean:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, TypeDescription_boolean), 3);
                break;
            }
            case TypeDescription_bit_string:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_bit_string), 4);
                break;
            }
            case TypeDescription_integer:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_integer), 5);
                break;
            }
            case TypeDescription_unsignedV:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_unsignedV), 6);
                break;
            }
            case TypeDescription_floating_point:
            {
                ITU_T_IMPLICIT_TAG(*value<Floating_point_type > (false, TypeDescription_floating_point), 7);
                break;
            }
            case TypeDescription_octet_string:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_octet_string), 9);
                break;
            }
            case TypeDescription_visible_string:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_visible_string), 10);
                break;
            }
            case TypeDescription_generalized_time:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, TypeDescription_generalized_time), 11);
                break;
            }
            case TypeDescription_binary_time:
            {
                ITU_T_IMPLICIT_TAG(*value<bool > (false, TypeDescription_binary_time), 12);
                break;
            }
            case TypeDescription_bcd:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_bcd), 13);
                break;
            }
            case TypeDescription_objId:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, TypeDescription_objId), 15);
                break;
            }
            case TypeDescription_mMSString:
            {
                ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_mMSString), 16);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void TypeDescription::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(*value<Array_type > (true, TypeDescription_array), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Structure_type > (true, TypeDescription_structure), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, TypeDescription_boolean), 3)) return;
                        else free();
                        break;
                    }
                    case 4:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_bit_string), 4)) return;
                        else free();
                        break;
                    }
                    case 5:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_integer), 5)) return;
                        else free();
                        break;
                    }
                    case 6:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_unsignedV), 6)) return;
                        else free();
                        break;
                    }
                    case 7:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<Floating_point_type > (true, TypeDescription_floating_point), 7)) return;
                        else free();
                        break;
                    }
                    case 9:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_octet_string), 9)) return;
                        else free();
                        break;
                    }
                    case 10:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_visible_string), 10)) return;
                        else free();
                        break;
                    }
                    case 11:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, TypeDescription_generalized_time), 11)) return;
                        else free();
                        break;
                    }
                    case 12:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<bool > (true, TypeDescription_binary_time), 12)) return;
                        else free();
                        break;
                    }
                    case 13:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_bcd), 13)) return;
                        else free();
                        break;
                    }
                    case 15:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, TypeDescription_objId), 15)) return;
                        else free();
                        break;
                    }
                    case 16:
                    {
                        if (ITU_T_EXPLICIT_TAG(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_mMSString), 16)) return;
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

    template<> void TypeDescription::Array_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(*numberOfElements_, 1);
        ITU_T_CHOICE_TAG(*elementType_, 2);
    }

    template<> void TypeDescription::Array_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(*numberOfElements_, 1);
        ITU_T_CHOICE_TAG(*elementType_, 2);
    }

    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(*components_, 1);
    }

    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(packed_.get_shared(), 0);
        ITU_T_IMPLICIT_TAG(*components_, 1);
    }

    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_CHOICE_TAG(*componentType_, 1);
    }

    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_CHOICE_TAG(*componentType_, 1);
    }

    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*format_width_);
        ITU_T_BIND_TAG(*exponent_width_);
    }

    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*format_width_);
        ITU_T_BIND_TAG(*exponent_width_);
    }

    template<> void EventTime::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case EventTime_timeOfDay:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::TimeOfDay > (false, EventTime_timeOfDay), 0);
                break;
            }
            case EventTime_timeSequenceIdentifier:
            {
                ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned32 > (false, EventTime_timeSequenceIdentifier), 1);
                break;
            }
            case EventTime_undefined:
            {
                ITU_T_IMPLICIT_TAG(*value<null_type > (false, EventTime_undefined), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EventTime::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::TimeOfDay > (true, EventTime_timeOfDay), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<ISO_9506_MMS_1::Unsigned32 > (true, EventTime_timeSequenceIdentifier), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(*value<null_type > (true, EventTime_undefined), 2)) return;
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

    template<> void Journal_Variable::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*variableTag_);
        ITU_T_BIND_CHOICE(*valueSpecification_);
    }

    template<> void Journal_Variable::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*variableTag_);
        ITU_T_BIND_CHOICE(*valueSpecification_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

