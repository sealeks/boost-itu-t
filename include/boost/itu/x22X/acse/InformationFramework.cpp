#include "InformationFramework.hpp"

namespace InformationFramework {

 
    const int AttributeUsage_userApplications = 0;
    const int AttributeUsage_directoryOperation = 1;
    const int AttributeUsage_distributedOperation = 2;
    const int AttributeUsage_dSAOperation = 3;

    const boost::array<boost::asn1::oidindx_type, 4> id_mr_distinguishedNameMatch_OID_ARR = { 2, 5, 13, 1};
    const boost::asn1::oid_type id_mr_distinguishedNameMatch  = boost::asn1::oid_type(id_mr_distinguishedNameMatch_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 4> id_mr_objectIdentifierMatch_OID_ARR = { 2, 5, 13, 0};
    const boost::asn1::oid_type id_mr_objectIdentifierMatch  = boost::asn1::oid_type(id_mr_objectIdentifierMatch_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 4> id_at_objectClass_OID_ARR = { 2, 5, 4, 0};
    const boost::asn1::oid_type id_at_objectClass  = boost::asn1::oid_type(id_at_objectClass_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 4> id_at_aliasedEntryName_OID_ARR = { 2, 5, 4, 1};
    const boost::asn1::oid_type id_at_aliasedEntryName  = boost::asn1::oid_type(id_at_aliasedEntryName_OID_ARR );

} 
