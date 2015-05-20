#include "MMS-Object-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {



    // sequence ModifierStep

    template<> void ModifierStep::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*modifierID_);
        ITU_T_BIND_PER(*modifier_);
    }

    template<> void ModifierStep::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*modifierID_);
        ITU_T_BIND_PER(*modifier_);
    }

    // choice Modifier

    template<> void Modifier::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Modifier_eventModifier:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::AttachToEventCondition > (false, Modifier_eventModifier));
                break;
            }
            case Modifier_semaphoreModifier:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::AttachToSemaphore > (false, Modifier_semaphoreModifier));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Modifier::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::AttachToEventCondition > (true, Modifier_eventModifier));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::AttachToSemaphore > (true, Modifier_semaphoreModifier));
                break;
            }
            default:
            {
            }
        }
    }

    // choice AccessCondition

    template<> void AccessCondition::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case AccessCondition_never:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 5);
                ITU_T_BIND_PER(*value<null_type > (false, AccessCondition_never));
                break;
            }
            case AccessCondition_semaphore:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 5);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::Identifier > (false, AccessCondition_semaphore));
                break;
            }
            case AccessCondition_user:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 5);
                ITU_T_BIND_PER(*value<User_type > (false, AccessCondition_user));
                break;
            }
            case AccessCondition_password:
            {
                ITU_T_SET_CONSTAINED_INDX(3, 5);
                ITU_T_BIND_PER(*value<ACSE_1::Authentication_value > (false, AccessCondition_password));
                break;
            }
            case AccessCondition_joint:
            {
                ITU_T_SET_CONSTAINED_INDX(4, 5);
                ITU_T_BIND_PER(*value<Joint_type > (false, AccessCondition_joint));
                break;
            }
            case AccessCondition_alternate:
            {
                ITU_T_SET_CONSTAINED_INDX(5, 5);
                ITU_T_BIND_PER(*value<Alternate_type > (false, AccessCondition_alternate));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessCondition::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(5);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, AccessCondition_never));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::Identifier > (true, AccessCondition_semaphore));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<User_type > (true, AccessCondition_user));
                break;
            }
            case 3:
            {
                ITU_T_BIND_PER(*value<ACSE_1::Authentication_value > (true, AccessCondition_password));
                break;
            }
            case 4:
            {
                ITU_T_BIND_PER(*value<Joint_type > (true, AccessCondition_joint));
                break;
            }
            case 5:
            {
                ITU_T_BIND_PER(*value<Alternate_type > (true, AccessCondition_alternate));
                break;
            }
            default:
            {
            }
        }
    }

    // choice user

    template<> void AccessCondition::User_type::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case User_type_none:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 1);
                ITU_T_BIND_PER(*value<null_type > (false, User_type_none));
                break;
            }
            case User_type_association:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 1);
                ITU_T_BIND_PER(*value<MMS_Environment_1::ApplicationReference > (false, User_type_association));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AccessCondition::User_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(1);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_PER(*value<null_type > (true, User_type_none));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<MMS_Environment_1::ApplicationReference > (true, User_type_association));
                break;
            }
            default:
            {
            }
        }
    }

    // choice Address

    template<> void Address::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case Address_numericAddress:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned32 > (false, Address_numericAddress), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case Address_symbolicAddress:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::MMSString > (false, Address_symbolicAddress));
                break;
            }
            case Address_unconstrainedAddress:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<octetstring_type > (false, Address_unconstrainedAddress));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Address::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned32 > (true, Address_numericAddress), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 1:
            {
                ITU_T_BIND_PER(*value<ISO_9506_MMS_1::MMSString > (true, Address_symbolicAddress));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<octetstring_type > (true, Address_unconstrainedAddress));
                break;
            }
            default:
            {
            }
        }
    }

    // choice TypeDescription

    template<> void TypeDescription::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_SET_PER;

        if (ITU_T_EXTENTION_CHECK_PER) {
            switch (type()) {
                case TypeDescription_array:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 12);
                    ITU_T_BIND_PER(*value<Array_type > (false, TypeDescription_array));
                    break;
                }
                case TypeDescription_structure:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 12);
                    ITU_T_BIND_PER(*value<Structure_type > (false, TypeDescription_structure));
                    break;
                }
                case TypeDescription_boolean:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 12);
                    ITU_T_BIND_PER(*value<null_type > (false, TypeDescription_boolean));
                    break;
                }
                case TypeDescription_bit_string:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 12);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_bit_string), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case TypeDescription_integer:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 12);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_integer), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                    break;
                }
                case TypeDescription_unsignedV:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 12);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_unsignedV), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                    break;
                }
                case TypeDescription_floating_point:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 12);
                    ITU_T_BIND_PER(*value<Floating_point_type > (false, TypeDescription_floating_point));
                    break;
                }
                case TypeDescription_octet_string:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 12);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_octet_string), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case TypeDescription_visible_string:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 12);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_visible_string), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case TypeDescription_generalized_time:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 12);
                    ITU_T_BIND_PER(*value<null_type > (false, TypeDescription_generalized_time));
                    break;
                }
                case TypeDescription_binary_time:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 12);
                    ITU_T_BIND_PER(*value<bool > (false, TypeDescription_binary_time));
                    break;
                }
                case TypeDescription_bcd:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 12);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned8 > (false, TypeDescription_bcd), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                    break;
                }
                case TypeDescription_objId:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 12);
                    ITU_T_BIND_PER(*value<null_type > (false, TypeDescription_objId));
                    break;
                }
                default:
                {
                }
            }
        }
        else {
            switch (type()) {
                case TypeDescription_mMSString:
                {
                    ITU_T_SET_NSN_SMALL_INDX(0);
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_mMSString), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                default:
                {
                }
            }
        }
    }

    template<> void TypeDescription::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_GET_PER;

        if (ITU_T_EXTENTION_CHECK_PER) {

            ITU_T_GET_CONSTAINED_INDX(12);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(*value<Array_type > (true, TypeDescription_array));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(*value<Structure_type > (true, TypeDescription_structure));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(*value<null_type > (true, TypeDescription_boolean));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_bit_string), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_integer), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_unsignedV), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(*value<Floating_point_type > (true, TypeDescription_floating_point));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_octet_string), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (true, TypeDescription_visible_string), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(*value<null_type > (true, TypeDescription_generalized_time));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(*value<bool > (true, TypeDescription_binary_time));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned8 > (true, TypeDescription_bcd), static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(*value<null_type > (true, TypeDescription_objId));
                    break;
                }
                default:
                {
                }
            }
        }
        else {

            ITU_T_GET_NSN_SMALL_INDX;

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Integer32 > (false, TypeDescription_mMSString), static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
                    break;
                }
                default:
                {
                }
            }
        }
    }

    // sequence array

    template<> void TypeDescription::Array_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(packed_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(packed_);
        ITU_T_BIND_NUM_CONSTRS(*numberOfElements_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*elementType_);
    }

    template<> void TypeDescription::Array_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(packed_);
        ITU_T_BIND_NUM_CONSTRS(*numberOfElements_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*elementType_);
    }

    // sequence structure

    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(packed_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(packed_);
        ITU_T_BIND_PER(*components_);
    }

    template<> void TypeDescription::Structure_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(packed_);
        ITU_T_BIND_PER(*components_);
    }

    // sequence 

    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(componentName_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(componentName_);
        ITU_T_BIND_PER(*componentType_);
    }

    template<> void TypeDescription::Structure_type::Components_type_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(componentName_);
        ITU_T_BIND_PER(*componentType_);
    }

    // sequence floating-point

    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*format_width_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*exponent_width_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    template<> void TypeDescription::Floating_point_type::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*format_width_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
        ITU_T_BIND_NUM_CONSTRS(*exponent_width_, static_cast<uint8_t> (0), static_cast<uint8_t> (std::numeric_limits<int8_t>::max()));
    }

    // choice EventTime

    template<> void EventTime::serialize(boost::asn1::x691::output_coder& arch) {
        switch (type()) {
            case EventTime_timeOfDay:
            {
                ITU_T_SET_CONSTAINED_INDX(0, 2);
                ITU_T_BIND_SIZE_CONSTRS(*value<ISO_9506_MMS_1::TimeOfDay > (false, EventTime_timeOfDay), 4, 6);
                break;
            }
            case EventTime_timeSequenceIdentifier:
            {
                ITU_T_SET_CONSTAINED_INDX(1, 2);
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned32 > (false, EventTime_timeSequenceIdentifier), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case EventTime_undefined:
            {
                ITU_T_SET_CONSTAINED_INDX(2, 2);
                ITU_T_BIND_PER(*value<null_type > (false, EventTime_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void EventTime::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_GET_CONSTAINED_INDX(2);

        switch (__indx__) {
            case 0:
            {
                ITU_T_BIND_SIZE_CONSTRS(*value<ISO_9506_MMS_1::TimeOfDay > (true, EventTime_timeOfDay), 4, 6);
                break;
            }
            case 1:
            {
                ITU_T_BIND_NUM_CONSTRS(*value<ISO_9506_MMS_1::Unsigned32 > (true, EventTime_timeSequenceIdentifier), static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
                break;
            }
            case 2:
            {
                ITU_T_BIND_PER(*value<null_type > (true, EventTime_undefined));
                break;
            }
            default:
            {
            }
        }
    }

    // sequence Journal-Variable

    template<> void Journal_Variable::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*variableTag_);
        ITU_T_BIND_PER(*valueSpecification_);
    }

    template<> void Journal_Variable::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*variableTag_);
        ITU_T_BIND_PER(*valueSpecification_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

