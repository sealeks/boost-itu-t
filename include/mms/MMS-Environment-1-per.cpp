#include "MMS-Environment-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {



    // sequence ApplicationReference

    template<> void ApplicationReference::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(ap_title_) +
                ITU_T_EXISTS_BMP(ap_invocation_id_) +
                ITU_T_EXISTS_BMP(ae_qualifier_) +
                ITU_T_EXISTS_BMP(ae_invocation_id_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(ap_title_);
        ITU_T_BIND_PER(ap_invocation_id_);
        ITU_T_BIND_PER(ae_qualifier_);
        ITU_T_BIND_PER(ae_invocation_id_);
    }

    template<> void ApplicationReference::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_READ(4);

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(ap_title_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(ap_invocation_id_);
        ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(ae_qualifier_);
        ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_PER(ae_invocation_id_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

