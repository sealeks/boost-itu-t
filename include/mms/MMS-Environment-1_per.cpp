#include "MMS-Environment-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {

    template<> void ApplicationReference::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(ap_title_) + ITU_T_OPTIONAL_PER(ap_invocation_id_) + ITU_T_OPTIONAL_PER(ae_qualifier_) + ITU_T_OPTIONAL_PER(ae_invocation_id_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(ap_title_);
        ITU_T_BIND_PER(ap_invocation_id_);
        ITU_T_BIND_PER(ae_qualifier_);
        ITU_T_BIND_PER(ae_invocation_id_);
    }

    template<> void ApplicationReference::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(4);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(ap_title_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(ap_invocation_id_);
        ITU_T_OPTIONAL_CHECK_PER(2) ITU_T_BIND_PER(ae_qualifier_);
        ITU_T_OPTIONAL_CHECK_PER(3) ITU_T_BIND_PER(ae_invocation_id_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

