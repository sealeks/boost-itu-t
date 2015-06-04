#include "MMS-Environment-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {



    // sequence ApplicationReference

    template<> void ApplicationReference::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(ap_title_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(ap_invocation_id_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(ae_qualifier_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(ae_invocation_id_, 3, CONTEXT_CLASS);
    }

    template<> void ApplicationReference::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(ap_title_, 0, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(ap_invocation_id_, 1, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(ae_qualifier_, 2, CONTEXT_CLASS);
        ITU_T_BIND_EXPLICIT(ae_invocation_id_, 3, CONTEXT_CLASS);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

