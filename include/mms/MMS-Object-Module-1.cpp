#include "MMS-Object-Module-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Object_Module_1 {

    // sequence ModifierStep

    ModifierStep::ModifierStep() : modifierID_(), modifier_() {
    };

    ModifierStep::ModifierStep(const integer_type& arg__modifierID,
            const Modifier& arg__modifier) :
    modifierID_(arg__modifierID),
    modifier_(arg__modifier) {
    };


    ITU_T_HOLDERH_DEFN(ModifierStep::modifierID, modifierID, integer_type);
    ITU_T_HOLDERH_DEFN(ModifierStep::modifier, modifier, Modifier);

    // choice Modifier

    ITU_T_CHOICEC_DEFN(Modifier::eventModifier, eventModifier, ISO_9506_MMS_1::AttachToEventCondition, Modifier_eventModifier);
    ITU_T_CHOICEC_DEFN(Modifier::semaphoreModifier, semaphoreModifier, ISO_9506_MMS_1::AttachToSemaphore, Modifier_semaphoreModifier);

    // choice AccessCondition


    ITU_T_CHOICEC_DEFN(AccessCondition::User_type::association, association, MMS_Environment_1::ApplicationReference, User_type_association);
    ITU_T_CHOICES_DEFN(AccessCondition::User_type::none, none, null_type, User_type_none);


    ITU_T_CHOICES_DEFN(AccessCondition::never, never, null_type, AccessCondition_never);
    ITU_T_CHOICES_DEFN(AccessCondition::semaphore, semaphore, ISO_9506_MMS_1::Identifier, AccessCondition_semaphore);
    ITU_T_CHOICEC_DEFN(AccessCondition::user, user, AccessCondition::User_type, AccessCondition_user);
    ITU_T_CHOICEC_DEFN(AccessCondition::password, password, ACSE_1::Authentication_value, AccessCondition_password);
    ITU_T_CHOICEC_DEFN(AccessCondition::joint, joint, AccessCondition::Joint_type, AccessCondition_joint);
    ITU_T_CHOICEC_DEFN(AccessCondition::alternate, alternate, AccessCondition::Alternate_type, AccessCondition_alternate);

    // choice Address

    ITU_T_CHOICES_DEFN(Address::numericAddress, numericAddress, ISO_9506_MMS_1::Unsigned32, Address_numericAddress);
    ITU_T_CHOICES_DEFN(Address::symbolicAddress, symbolicAddress, ISO_9506_MMS_1::MMSString, Address_symbolicAddress);
    ITU_T_CHOICES_DEFN(Address::unconstrainedAddress, unconstrainedAddress, octetstring_type, Address_unconstrainedAddress);

    // choice TypeDescription

    TypeDescription::Array_type::Array_type() : numberOfElements_(), elementType_() {
    };

    TypeDescription::Array_type::Array_type(const ISO_9506_MMS_1::Unsigned32& arg__numberOfElements,
            const ISO_9506_MMS_1::TypeSpecification& arg__elementType) :
    numberOfElements_(arg__numberOfElements),
    elementType_(arg__elementType) {
    };

    TypeDescription::Array_type::Array_type(shared_ptr< bool> arg__packed,
            shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__numberOfElements,
            shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__elementType) :
    packed_(arg__packed),
    numberOfElements_(arg__numberOfElements),
    elementType_(arg__elementType) {
    };

    const bool TypeDescription::Array_type::packed__default = false;


    ITU_T_DEFAULTH_DEFN(TypeDescription::Array_type::packed, packed, bool);
    ITU_T_HOLDERH_DEFN(TypeDescription::Array_type::numberOfElements, numberOfElements, ISO_9506_MMS_1::Unsigned32);
    ITU_T_HOLDERH_DEFN(TypeDescription::Array_type::elementType, elementType, ISO_9506_MMS_1::TypeSpecification);

    TypeDescription::Structure_type::Structure_type() : components_() {
    };

    TypeDescription::Structure_type::Structure_type(const Components_type& arg__components) :
    components_(arg__components) {
    };

    TypeDescription::Structure_type::Structure_type(shared_ptr< bool> arg__packed,
            shared_ptr< Components_type> arg__components) :
    packed_(arg__packed),
    components_(arg__components) {
    };

    TypeDescription::Structure_type::Components_type_sequence_of::Components_type_sequence_of() : componentType_() {
    };

    TypeDescription::Structure_type::Components_type_sequence_of::Components_type_sequence_of(const ISO_9506_MMS_1::TypeSpecification& arg__componentType) :
    componentType_(arg__componentType) {
    };

    TypeDescription::Structure_type::Components_type_sequence_of::Components_type_sequence_of(shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
            shared_ptr< ISO_9506_MMS_1::TypeSpecification> arg__componentType) :
    componentName_(arg__componentName),
    componentType_(arg__componentType) {
    };


    ITU_T_OPTIONAL_DEFN(TypeDescription::Structure_type::Components_type_sequence_of::componentName, componentName, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(TypeDescription::Structure_type::Components_type_sequence_of::componentType, componentType, ISO_9506_MMS_1::TypeSpecification);

    const bool TypeDescription::Structure_type::packed__default = false;


    ITU_T_DEFAULTH_DEFN(TypeDescription::Structure_type::packed, packed, bool);
    ITU_T_HOLDERH_DEFN(TypeDescription::Structure_type::components, components, TypeDescription::Structure_type::Components_type);

    TypeDescription::Floating_point_type::Floating_point_type() : format_width_(), exponent_width_() {
    };

    TypeDescription::Floating_point_type::Floating_point_type(const ISO_9506_MMS_1::Unsigned8& arg__format_width,
            const ISO_9506_MMS_1::Unsigned8& arg__exponent_width) :
    format_width_(arg__format_width),
    exponent_width_(arg__exponent_width) {
    };


    ITU_T_HOLDERH_DEFN(TypeDescription::Floating_point_type::format_width, format_width, ISO_9506_MMS_1::Unsigned8);
    ITU_T_HOLDERH_DEFN(TypeDescription::Floating_point_type::exponent_width, exponent_width, ISO_9506_MMS_1::Unsigned8);


    ITU_T_CHOICEC_DEFN(TypeDescription::array, array, TypeDescription::Array_type, TypeDescription_array);
    ITU_T_CHOICEC_DEFN(TypeDescription::structure, structure, TypeDescription::Structure_type, TypeDescription_structure);
    ITU_T_CHOICES_DEFN(TypeDescription::boolean, boolean, null_type, TypeDescription_boolean);
    ITU_T_CHOICES_DEFN(TypeDescription::bit_string, bit_string, ISO_9506_MMS_1::Integer32, TypeDescription_bit_string);
    ITU_T_CHOICES_DEFN(TypeDescription::integer, integer, ISO_9506_MMS_1::Unsigned8, TypeDescription_integer);
    ITU_T_CHOICES_DEFN(TypeDescription::unsignedV, unsignedV, ISO_9506_MMS_1::Unsigned8, TypeDescription_unsignedV);
    ITU_T_CHOICEC_DEFN(TypeDescription::floating_point, floating_point, TypeDescription::Floating_point_type, TypeDescription_floating_point);
    ITU_T_CHOICES_DEFN(TypeDescription::octet_string, octet_string, ISO_9506_MMS_1::Integer32, TypeDescription_octet_string);
    ITU_T_CHOICES_DEFN(TypeDescription::visible_string, visible_string, ISO_9506_MMS_1::Integer32, TypeDescription_visible_string);
    ITU_T_CHOICES_DEFN(TypeDescription::generalized_time, generalized_time, null_type, TypeDescription_generalized_time);
    ITU_T_CHOICES_DEFN(TypeDescription::binary_time, binary_time, bool, TypeDescription_binary_time);
    ITU_T_CHOICES_DEFN(TypeDescription::bcd, bcd, ISO_9506_MMS_1::Unsigned8, TypeDescription_bcd);
    ITU_T_CHOICES_DEFN(TypeDescription::objId, objId, null_type, TypeDescription_objId);
    ITU_T_CHOICES_DEFN(TypeDescription::mMSString, mMSString, ISO_9506_MMS_1::Integer32, TypeDescription_mMSString);

    // choice EventTime

    ITU_T_CHOICES_DEFN(EventTime::timeOfDay, timeOfDay, ISO_9506_MMS_1::TimeOfDay, EventTime_timeOfDay);
    ITU_T_CHOICES_DEFN(EventTime::timeSequenceIdentifier, timeSequenceIdentifier, ISO_9506_MMS_1::Unsigned32, EventTime_timeSequenceIdentifier);
    ITU_T_CHOICES_DEFN(EventTime::undefined, undefined, null_type, EventTime_undefined);

    // sequence Journal-Variable

    Journal_Variable::Journal_Variable() : variableTag_(), valueSpecification_() {
    };

    Journal_Variable::Journal_Variable(const ISO_9506_MMS_1::MMS255String& arg__variableTag,
            const ISO_9506_MMS_1::Data& arg__valueSpecification) :
    variableTag_(arg__variableTag),
    valueSpecification_(arg__valueSpecification) {
    };


    ITU_T_HOLDERH_DEFN(Journal_Variable::variableTag, variableTag, ISO_9506_MMS_1::MMS255String);
    ITU_T_HOLDERH_DEFN(Journal_Variable::valueSpecification, valueSpecification, ISO_9506_MMS_1::Data);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

