#include "MMS-Environment-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {

    // sequence ApplicationReference

    ApplicationReference::ApplicationReference() {
    };

    ApplicationReference::ApplicationReference(shared_ptr< ACSE_1::AP_title> arg__ap_title,
            shared_ptr< ACSE_1::AP_invocation_identifier> arg__ap_invocation_id,
            shared_ptr< ACSE_1::AE_qualifier> arg__ae_qualifier,
            shared_ptr< ACSE_1::AE_invocation_identifier> arg__ae_invocation_id) :
    ap_title_(arg__ap_title),
    ap_invocation_id_(arg__ap_invocation_id),
    ae_qualifier_(arg__ae_qualifier),
    ae_invocation_id_(arg__ae_invocation_id) {
    };


    ITU_T_OPTIONAL_DEFN(ApplicationReference::ap_title, ap_title, ACSE_1::AP_title);
    ITU_T_OPTIONAL_DEFN(ApplicationReference::ap_invocation_id, ap_invocation_id, ACSE_1::AP_invocation_identifier);
    ITU_T_OPTIONAL_DEFN(ApplicationReference::ae_qualifier, ae_qualifier, ACSE_1::AE_qualifier);
    ITU_T_OPTIONAL_DEFN(ApplicationReference::ae_invocation_id, ae_invocation_id, ACSE_1::AE_invocation_identifier);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

