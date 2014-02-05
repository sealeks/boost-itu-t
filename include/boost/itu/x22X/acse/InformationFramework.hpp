#ifndef ___INFORMATIONFRAMEWORK
#define ___INFORMATIONFRAMEWORK

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace InformationFramework {

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

    struct Name;  
    struct AttributeTypeAndDistinguishedValue;  
    struct Context;  

    typedef enumerated_type AttributeUsage;  


} 
#include "UsefulDefinitions.hpp"

namespace InformationFramework {

  // import   from  UsefulDefinitions



    typedef std::vector< RelativeDistinguishedName> RDNSequence;
    typedef std::deque< AttributeTypeAndDistinguishedValue> RelativeDistinguishedName;
    typedef RDNSequence DistinguishedName;  


        // choice Name
        enum Name_enum {
            Name_null = 0, 
            Name_rdnSequence,}; 
 
        struct Name : public BOOST_ASN_CHOICE_STRUCT(Name_enum) {


            Name() :  BOOST_ASN_CHOICE_STRUCT(Name_enum) () {}
 
            BOOST_ASN_VALUE_CHOICE(rdnSequence, RDNSequence, Name_rdnSequence);

            template<typename Archive> void serialize(Archive& arch){
                if (arch.__input__()){
                    int __tag_id__ =arch.test_id();
                    switch(arch.test_class()){
                        case 0x0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x40: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0x80: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        case 0xC0: {
                            switch(__tag_id__){
                            default:{}
                            }
                        }
                        default: {
                                 if (BOOST_ASN_BIND_TAG(value<RDNSequence > (true , Name_rdnSequence))) return; else free();
                        }
                    }
                } else {
                    switch(type()){
                        case Name_rdnSequence:  {BOOST_ASN_BIND_TAG(value<RDNSequence > (false , Name_rdnSequence)); break; }
                        default:{}
                    }
                }
            }
        }; 
 
        // sequence AttributeTypeAndDistinguishedValue
        struct AttributeTypeAndDistinguishedValue{        struct valuesWithContext_type_set_of;

        typedef std::deque< valuesWithContext_type_set_of> valuesWithContext_type;


            AttributeTypeAndDistinguishedValue() : type(), value() {} 
 
            boost::asn1::value_holder<any_type> type;
            boost::asn1::value_holder<any_type> value;
            boost::shared_ptr<bool> primaryDistinguished;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, primaryDistinguished)

            boost::shared_ptr<valuesWithContext_type> valuesWithContext;
            BOOST_ASN_VALUE_FUNC_DECLARATE(valuesWithContext_type, valuesWithContext)


            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_BIND_TAG(type);
                BOOST_ASN_BIND_TAG(value);
                BOOST_ASN_BIND_TAG(primaryDistinguished);
                BOOST_ASN_BIND_TAG(valuesWithContext);
            }
        };
 
        // sequence Context
        struct Context{
        typedef std::deque< any_type> contextValues_type;


            Context() : contextType(), contextValues() {} 
 
            boost::asn1::value_holder<any_type> contextType;
            boost::asn1::value_holder<contextValues_type> contextValues;
            boost::shared_ptr<bool> fallback;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, fallback)


            template<typename Archive> void serialize(Archive& arch){
                BOOST_ASN_BIND_TAG(contextType);
                BOOST_ASN_BIND_TAG(contextValues);
                BOOST_ASN_BIND_TAG(fallback);
            }
        };
 
        const int AttributeUsage_userApplications = 0;
        const int AttributeUsage_directoryOperation = 1;
        const int AttributeUsage_distributedOperation = 2;
        const int AttributeUsage_dSAOperation = 3;

    const boost::array<boost::asn1::oidindx_type, 2> id_mr_distinguishedNameMatch_OID_ARR = { ???num???, 1};
    const boost::asn1::oid_type id_mr_distinguishedNameMatch  = boost::asn1::oid_type(id_mr_distinguishedNameMatch_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 2> id_mr_objectIdentifierMatch_OID_ARR = { ???num???, 0};
    const boost::asn1::oid_type id_mr_objectIdentifierMatch  = boost::asn1::oid_type(id_mr_objectIdentifierMatch_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 2> id_at_objectClass_OID_ARR = { ???num???, 0};
    const boost::asn1::oid_type id_at_objectClass  = boost::asn1::oid_type(id_at_objectClass_OID_ARR );

    const boost::array<boost::asn1::oidindx_type, 2> id_at_aliasedEntryName_OID_ARR = { ???num???, 1};
    const boost::asn1::oid_type id_at_aliasedEntryName  = boost::asn1::oid_type(id_at_aliasedEntryName_OID_ARR );

} 


    BOOST_ASN_CHOICE_REGESTRATE(InformationFramework::Name)

#endif  /*___INFORMATIONFRAMEWORK */
