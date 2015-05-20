#include "InformationFramework.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace InformationFramework {

    // choice Name

        template<> void Name::serialize(boost::asn1::x690::output_coder& arch){
            switch(type()){
                case Name_rdnSequence:  {ITU_T_BIND_TAG(*value<RDNSequence > (false , Name_rdnSequence)); break; }
                default:{}
            }
        }

        template<> void Name::serialize(boost::asn1::x690::input_coder& arch){

                 if (ITU_T_BIND_TAG(*value<RDNSequence > (true , Name_rdnSequence))) return; else free();
        }

    // sequence AttributeTypeAndDistinguishedValue

        template<> void AttributeTypeAndDistinguishedValue::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(*type_);
            ITU_T_BIND_TAG(*value_);
            ITU_T_BIND_TAG(primaryDistinguished_);
            ITU_T_BIND_TAG(valuesWithContext_);
        }

        template<> void AttributeTypeAndDistinguishedValue::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(*type_);
            ITU_T_BIND_TAG(*value_);
            ITU_T_BIND_TAG(primaryDistinguished_);
            ITU_T_BIND_TAG(valuesWithContext_);
        }

    // sequence 

        template<> void AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_EXPLICIT_TAG(distingAttrValue_, 0);
            ITU_T_BIND_TAG(*contextList_);
        }

        template<> void AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_EXPLICIT_TAG(distingAttrValue_, 0);
            ITU_T_BIND_TAG(*contextList_);
        }

    // sequence Context

        template<> void Context::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(*contextType_);
            ITU_T_BIND_TAG(*contextValues_);
            ITU_T_BIND_TAG(fallback_);
        }

        template<> void Context::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(*contextType_);
            ITU_T_BIND_TAG(*contextValues_);
            ITU_T_BIND_TAG(fallback_);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

