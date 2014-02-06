#ifndef ___USEFULDEFINITIONS
#define ___USEFULDEFINITIONS

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace UsefulDefinitions {

    using  boost::asn1::null_type;
    using  boost::asn1::enumerated_type;
    using  boost::asn1::bitstring_type;
    using  boost::asn1::octetstring_type;
    using  boost::asn1::oid_type;
    using  boost::asn1::reloid_type;
    using  boost::asn1::utctime_type;
    using  boost::asn1::gentime_type;
    using  boost::asn1::ia5string_type;
    using  boost::asn1::printablestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::numericstring_type;
    using  boost::asn1::universalstring_type;
    using  boost::asn1::bmpstring_type;
    using  boost::asn1::utf8string_type;
    using  boost::asn1::generalstring_type;
    using  boost::asn1::graphicstring_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::videotexstring_type;
    using  boost::asn1::objectdescriptor_type;
    using  boost::asn1::external_type;
    using  boost::asn1::embeded_type;
    using  boost::asn1::characterstring_type;
    using  boost::asn1::any_type;


    typedef oid_type ID;  


} 

namespace UsefulDefinitions {


    extern const boost::asn1::oid_type ds;

    extern const boost::asn1::oid_type module;

    extern const boost::asn1::oid_type serviceElement;

    extern const boost::asn1::oid_type applicationContext;

    extern const boost::asn1::oid_type attributeType;

    extern const boost::asn1::oid_type attributeSyntax;

    extern const boost::asn1::oid_type objectClass;

    extern const boost::asn1::oid_type algorithm;

    extern const boost::asn1::oid_type abstractSyntax;

    extern const boost::asn1::oid_type dsaOperationalAttribute;

    extern const boost::asn1::oid_type matchingRule;

    extern const boost::asn1::oid_type knowledgeMatchingRule;

    extern const boost::asn1::oid_type nameForm;

    extern const boost::asn1::oid_type group;

    extern const boost::asn1::oid_type subentry;

    extern const boost::asn1::oid_type operationalAttributeType;

    extern const boost::asn1::oid_type operationalBinding;

    extern const boost::asn1::oid_type schemaObjectClass;

    extern const boost::asn1::oid_type schemaOperationalAttribute;

    extern const boost::asn1::oid_type administrativeRoles;

    extern const boost::asn1::oid_type accessControlAttribute;

    extern const boost::asn1::oid_type rosObject;

    extern const boost::asn1::oid_type contract;

    extern const boost::asn1::oid_type package;

    extern const boost::asn1::oid_type accessControlSchemes;

    extern const boost::asn1::oid_type certificateExtension;

    extern const boost::asn1::oid_type managementObject;

    extern const boost::asn1::oid_type attributeValueContext;

    extern const boost::asn1::oid_type idmProtocol;

    extern const boost::asn1::oid_type problem;

    extern const boost::asn1::oid_type notification;

    extern const boost::asn1::oid_type matchingRestriction;

    extern const boost::asn1::oid_type controlAttributeType;

    extern const boost::asn1::oid_type usefulDefinitions;

    extern const boost::asn1::oid_type informationFramework;

    extern const boost::asn1::oid_type directoryAbstractService;

    extern const boost::asn1::oid_type distributedOperations;

    extern const boost::asn1::oid_type protocolObjectIdentifiers;

    extern const boost::asn1::oid_type selectedAttributeTypes;

    extern const boost::asn1::oid_type selectedObjectClasses;

    extern const boost::asn1::oid_type authenticationFramework;

    extern const boost::asn1::oid_type algorithmObjectIdentifiers;

    extern const boost::asn1::oid_type directoryObjectIdentifiers;

    extern const boost::asn1::oid_type upperBounds;

    extern const boost::asn1::oid_type dap;

    extern const boost::asn1::oid_type dsp;

    extern const boost::asn1::oid_type distributedDirectoryOIDs;

    extern const boost::asn1::oid_type directoryShadowOIDs;

    extern const boost::asn1::oid_type directoryShadowAbstractService;

    extern const boost::asn1::oid_type disp;

    extern const boost::asn1::oid_type dop;

    extern const boost::asn1::oid_type opBindingManagement;

    extern const boost::asn1::oid_type opBindingOIDs;

    extern const boost::asn1::oid_type hierarchicalOperationalBindings;

    extern const boost::asn1::oid_type dsaOperationalAttributeTypes;

    extern const boost::asn1::oid_type schemaAdministration;

    extern const boost::asn1::oid_type basicAccessControl;

    extern const boost::asn1::oid_type directoryOperationalBindingTypes;

    extern const boost::asn1::oid_type certificateExtensions;

    extern const boost::asn1::oid_type directoryManagement;

    extern const boost::asn1::oid_type enhancedSecurity;

    extern const boost::asn1::oid_type iDMProtocolSpecification;

    extern const boost::asn1::oid_type directoryIDMProtocols;

} 


#endif  /*___USEFULDEFINITIONS */

