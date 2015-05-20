#include "InformationFramework.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace InformationFramework {




        //  helper name:   AttributeUsage           type:  enumerated helper    
        ITU_T_PER_ENUMCODER(AttributeUsage__helper, false, ITU_T_ARRAY(0, 1, 2, 3));

    // choice Name

        template<> void Name::serialize(boost::asn1::x691::output_coder& arch){ITU_T_BIND_PER(*value<RDNSequence > (false , Name_rdnSequence))
        }

        template<> void Name::serialize(boost::asn1::x691::input_coder& arch){ITU_T_BIND_PER(*value<RDNSequence > (true , Name_rdnSequence))
        }

    // sequence AttributeTypeAndDistinguishedValue

        template<> void AttributeTypeAndDistinguishedValue::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_OPTIONAL_DECL_PER =  ITU_T_OPTIONAL_PER(primaryDistinguished_) +  ITU_T_OPTIONAL_PER(valuesWithContext_);

            ITU_T_OPTIONAL_SET_PER;

            ITU_T_BIND_PER(*type_);
            ITU_T_BIND_PER(*value_);
            ITU_T_BIND_PER(primaryDistinguished_);
            ITU_T_BIND_SIZE_SEMICONSTRS( valuesWithContext_, 1);
        }

        template<> void AttributeTypeAndDistinguishedValue::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_OPTIONAL_GET_PER(2 );

            ITU_T_BIND_PER(*type_);
            ITU_T_BIND_PER(*value_);
            ITU_T_OPTIONAL_CHECK_PER(0)  ITU_T_BIND_PER(primaryDistinguished_);
            ITU_T_OPTIONAL_CHECK_PER(1)  ITU_T_BIND_SIZE_SEMICONSTRS( valuesWithContext_, 1);
        }

    // sequence 

        template<> void AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_OPTIONAL_DECL_PER =  ITU_T_OPTIONAL_PER(distingAttrValue_);

            ITU_T_OPTIONAL_SET_PER;

            ITU_T_BIND_PER(distingAttrValue_);
            ITU_T_BIND_SIZE_SEMICONSTRS( *contextList_, 1);
        }

        template<> void AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_OPTIONAL_GET_PER(1 );

            ITU_T_OPTIONAL_CHECK_PER(0)  ITU_T_BIND_PER(distingAttrValue_);
            ITU_T_BIND_SIZE_SEMICONSTRS( *contextList_, 1);
        }

    // sequence Context

        template<> void Context::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_OPTIONAL_DECL_PER =  ITU_T_OPTIONAL_PER(fallback_);

            ITU_T_OPTIONAL_SET_PER;

            ITU_T_BIND_PER(*contextType_);
            ITU_T_BIND_SIZE_SEMICONSTRS( *contextValues_, 1);
            ITU_T_BIND_PER(fallback_);
        }

        template<> void Context::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_OPTIONAL_GET_PER(1 );

            ITU_T_BIND_PER(*contextType_);
            ITU_T_BIND_SIZE_SEMICONSTRS( *contextValues_, 1);
            ITU_T_OPTIONAL_CHECK_PER(0)  ITU_T_BIND_PER(fallback_);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

