#include "MMS-Environment-1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {

    // sequence ApplicationReference

    ApplicationReference::ApplicationReference() {
    };

    ApplicationReference::ApplicationReference(boost::shared_ptr< ACSE_1::AP_title> arg__ap_title,
            boost::shared_ptr< ACSE_1::AP_invocation_identifier> arg__ap_invocation_id,
            boost::shared_ptr< ACSE_1::AE_qualifier> arg__ae_qualifier,
            boost::shared_ptr< ACSE_1::AE_invocation_identifier> arg__ae_invocation_id) :
    ap_title_(arg__ap_title),
    ap_invocation_id_(arg__ap_invocation_id),
    ae_qualifier_(arg__ae_qualifier),
    ae_invocation_id_(arg__ae_invocation_id) {
    };

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

    boost::shared_ptr<ACSE_1::AP_title> ApplicationReference::ap_title__new() {
        return ap_title_ = boost::shared_ptr<ACSE_1::AP_title>(new ACSE_1::AP_title());
    }

    void ApplicationReference::ap_title(const ACSE_1::AP_title& vl) {
        ap_title_ = boost::shared_ptr<ACSE_1::AP_title>(new ACSE_1::AP_title(vl));
    }

    boost::shared_ptr<ACSE_1::AP_invocation_identifier> ApplicationReference::ap_invocation_id__new() {
        return ap_invocation_id_ = boost::shared_ptr<ACSE_1::AP_invocation_identifier>(new ACSE_1::AP_invocation_identifier());
    }

    void ApplicationReference::ap_invocation_id(const ACSE_1::AP_invocation_identifier& vl) {
        ap_invocation_id_ = boost::shared_ptr<ACSE_1::AP_invocation_identifier>(new ACSE_1::AP_invocation_identifier(vl));
    }

    boost::shared_ptr<ACSE_1::AE_qualifier> ApplicationReference::ae_qualifier__new() {
        return ae_qualifier_ = boost::shared_ptr<ACSE_1::AE_qualifier>(new ACSE_1::AE_qualifier());
    }

    void ApplicationReference::ae_qualifier(const ACSE_1::AE_qualifier& vl) {
        ae_qualifier_ = boost::shared_ptr<ACSE_1::AE_qualifier>(new ACSE_1::AE_qualifier(vl));
    }

    boost::shared_ptr<ACSE_1::AE_invocation_identifier> ApplicationReference::ae_invocation_id__new() {
        return ae_invocation_id_ = boost::shared_ptr<ACSE_1::AE_invocation_identifier>(new ACSE_1::AE_invocation_identifier());
    }

    void ApplicationReference::ae_invocation_id(const ACSE_1::AE_invocation_identifier& vl) {
        ae_invocation_id_ = boost::shared_ptr<ACSE_1::AE_invocation_identifier>(new ACSE_1::AE_invocation_identifier(vl));
    }


}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

