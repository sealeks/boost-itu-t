#ifndef ___MMS_ENVIRONMENT_1
#define ___MMS_ENVIRONMENT_1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace MMS_Environment_1 {

    ITU_T_USE_UNIVESAL_DECL;


    struct ApplicationReference;



}

#include <boost/itu/x22X/acse/ACSE-1.hpp>

namespace MMS_Environment_1 {

    // import   from  ACSE-1



    // sequence ApplicationReference

    struct ApplicationReference {

        ApplicationReference();

        ApplicationReference(shared_ptr< ACSE_1::AP_title> arg__ap_title,
                shared_ptr< ACSE_1::AP_invocation_identifier> arg__ap_invocation_id,
                shared_ptr< ACSE_1::AE_qualifier> arg__ae_qualifier,
                shared_ptr< ACSE_1::AE_invocation_identifier> arg__ae_invocation_id);

        ITU_T_OPTIONAL_DECL(ap_title, ACSE_1::AP_title);
        ITU_T_OPTIONAL_DECL(ap_invocation_id, ACSE_1::AP_invocation_identifier);
        ITU_T_OPTIONAL_DECL(ae_qualifier, ACSE_1::AE_qualifier);
        ITU_T_OPTIONAL_DECL(ae_invocation_id, ACSE_1::AE_invocation_identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    ITU_T_ARCHIVE_X690_DECL(ApplicationReference);

    ITU_T_ARCHIVE_X691_DECL(ApplicationReference);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___MMS_ENVIRONMENT_1 */
