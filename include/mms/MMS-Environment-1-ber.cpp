#include "MMS-Environment-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {

    // sequence ApplicationReference

    template<> void ApplicationReference::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(ap_title_, 0);
        ITU_T_EXPLICIT_TAG(ap_invocation_id_, 1);
        ITU_T_CHOICE_TAG(ae_qualifier_, 2);
        ITU_T_EXPLICIT_TAG(ae_invocation_id_, 3);
    }

    template<> void ApplicationReference::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(ap_title_, 0);
        ITU_T_EXPLICIT_TAG(ap_invocation_id_, 1);
        ITU_T_CHOICE_TAG(ae_qualifier_, 2);
        ITU_T_EXPLICIT_TAG(ae_invocation_id_, 3);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

