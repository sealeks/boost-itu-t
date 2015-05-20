#include "InformationFramework.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace InformationFramework {

        // choice Name

        ITU_T_CHOICEC_DEFN( Name::rdnSequence, rdnSequence, RDNSequence, Name_rdnSequence);
 
        // sequence AttributeTypeAndDistinguishedValue

    AttributeTypeAndDistinguishedValue::AttributeTypeAndDistinguishedValue() : type_(), value_() {}; 
 
    AttributeTypeAndDistinguishedValue::AttributeTypeAndDistinguishedValue(const any_type&  arg__type,
        const any_type&  arg__value) : 
        type_(arg__type),
        value_(arg__value) {}; 
 
    AttributeTypeAndDistinguishedValue::AttributeTypeAndDistinguishedValue(shared_ptr< any_type>  arg__type,
        shared_ptr< any_type>  arg__value,
        shared_ptr< bool>  arg__primaryDistinguished,
        shared_ptr< ValuesWithContext_type>  arg__valuesWithContext) : 
        type_(arg__type),
        value_(arg__value),
        primaryDistinguished_(arg__primaryDistinguished),
        valuesWithContext_(arg__valuesWithContext) {}; 
 


    AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::ValuesWithContext_type_set_of() : contextList_() {}; 
 
    AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::ValuesWithContext_type_set_of(const ContextList_type&  arg__contextList) : 
        contextList_(arg__contextList) {}; 
 
    AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::ValuesWithContext_type_set_of(shared_ptr< any_type>  arg__distingAttrValue,
        shared_ptr< ContextList_type>  arg__contextList) : 
        distingAttrValue_(arg__distingAttrValue),
        contextList_(arg__contextList) {}; 
 

        ITU_T_OPTIONAL_DEFN( AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::distingAttrValue, distingAttrValue, any_type);
        ITU_T_HOLDERH_DEFN( AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::contextList, contextList, AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::ContextList_type);
 
    const bool AttributeTypeAndDistinguishedValue::primaryDistinguished__default = true;


        ITU_T_HOLDERH_DEFN( AttributeTypeAndDistinguishedValue::type, type, any_type);
        ITU_T_HOLDERH_DEFN( AttributeTypeAndDistinguishedValue::value, value, any_type);
        ITU_T_DEFAULTH_DEFN( AttributeTypeAndDistinguishedValue::primaryDistinguished, primaryDistinguished, bool);
        ITU_T_OPTIONAL_DEFN( AttributeTypeAndDistinguishedValue::valuesWithContext, valuesWithContext, AttributeTypeAndDistinguishedValue::ValuesWithContext_type);
 
        // sequence Context

    Context::Context() : contextType_(), contextValues_() {}; 
 
    Context::Context(const any_type&  arg__contextType,
        const ContextValues_type&  arg__contextValues) : 
        contextType_(arg__contextType),
        contextValues_(arg__contextValues) {}; 
 
    Context::Context(shared_ptr< any_type>  arg__contextType,
        shared_ptr< ContextValues_type>  arg__contextValues,
        shared_ptr< bool>  arg__fallback) : 
        contextType_(arg__contextType),
        contextValues_(arg__contextValues),
        fallback_(arg__fallback) {}; 
 
    const bool Context::fallback__default = false;


        ITU_T_HOLDERH_DEFN( Context::contextType, contextType, any_type);
        ITU_T_HOLDERH_DEFN( Context::contextValues, contextValues, Context::ContextValues_type);
        ITU_T_DEFAULTH_DEFN( Context::fallback, fallback, bool);
 
} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

