#ifndef ___INFORMATIONFRAMEWORK
#define ___INFORMATIONFRAMEWORK

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace InformationFramework {

    ITU_T_USE_UNIVESAL_DECL;


        struct Name;
        struct AttributeTypeAndDistinguishedValue;
        struct Context;


        typedef enumerated_type AttributeUsage;

        typedef std::deque< AttributeTypeAndDistinguishedValue > RelativeDistinguishedName;  //    Sc (  [ 1  ...    ]   
        typedef std::vector< RelativeDistinguishedName > RDNSequence;  //  struct of ->    //    Sc (  [ 1  ...    ]   
        typedef RDNSequence DistinguishedName;  //  struct of ->    //    Sc (  [ 1  ...    ]   

        ITU_T_OID( id_mr_distinguishedNameMatch , ITU_T_VARRAY(  2, 5, 13, 1));
        ITU_T_OID( id_mr_objectIdentifierMatch , ITU_T_VARRAY(  2, 5, 13, 0));
        ITU_T_OID( id_at_objectClass , ITU_T_VARRAY(  2, 5, 4, 0));
        ITU_T_OID( id_at_aliasedEntryName , ITU_T_VARRAY(  2, 5, 4, 1));

} 

#include "UsefulDefinitions.hpp"

namespace InformationFramework {

    // import   from  UsefulDefinitions




        // choice Name
        enum Name_enum {
            Name_null = 0, 
            Name_rdnSequence,}; 
 
        struct Name : public ITU_T_CHOICE(Name_enum) {


            ITU_T_CHOICE_CTORS(Name);

            ITU_T_CHOICEC_DECL(rdnSequence, RDNSequence, Name_rdnSequence);       //  struct of ->    //    Sc (  [ 1  ...    ]   

            ITU_T_ARCHIVE_FUNC;
        }; 
 
        // sequence AttributeTypeAndDistinguishedValue
        struct AttributeTypeAndDistinguishedValue{


            struct ValuesWithContext_type_set_of;


            struct ValuesWithContext_type_set_of{



                    typedef std::deque< Context > ContextList_type;  //    Sc (  [ 1  ...    ]   


                ValuesWithContext_type_set_of(); 

                ValuesWithContext_type_set_of(const ContextList_type&  arg__contextList);

                ValuesWithContext_type_set_of(shared_ptr< any_type>  arg__distingAttrValue,
                     shared_ptr< ContextList_type>  arg__contextList);

                ITU_T_OPTIONAL_DECL(distingAttrValue, any_type);
                ITU_T_HOLDERH_DECL(contextList, ContextList_type);  //    Sc (  [ 1  ...    ]   

                ITU_T_ARCHIVE_FUNC;
            };
 


                typedef std::deque< ValuesWithContext_type_set_of > ValuesWithContext_type;  //    Sc (  [ 1  ...    ]   

            static const bool primaryDistinguished__default;

            AttributeTypeAndDistinguishedValue(); 

            AttributeTypeAndDistinguishedValue(const any_type&  arg__type,
                 const any_type&  arg__value);

            AttributeTypeAndDistinguishedValue(shared_ptr< any_type>  arg__type,
                 shared_ptr< any_type>  arg__value,
                 shared_ptr< bool>  arg__primaryDistinguished,
                 shared_ptr< ValuesWithContext_type>  arg__valuesWithContext);

            ITU_T_HOLDERH_DECL(type, any_type);
            ITU_T_HOLDERH_DECL(value, any_type);
            ITU_T_DEFAULTH_DECL(primaryDistinguished, bool, primaryDistinguished__default);
            ITU_T_OPTIONAL_DECL(valuesWithContext, ValuesWithContext_type);  //    Sc (  [ 1  ...    ]   

            ITU_T_ARCHIVE_FUNC;
        };
 
        // sequence Context
        struct Context{



                typedef std::deque< any_type > ContextValues_type;  //    Sc (  [ 1  ...    ]   

            static const bool fallback__default;

            Context(); 

            Context(const any_type&  arg__contextType,
                 const ContextValues_type&  arg__contextValues);

            Context(shared_ptr< any_type>  arg__contextType,
                 shared_ptr< ContextValues_type>  arg__contextValues,
                 shared_ptr< bool>  arg__fallback);

            ITU_T_HOLDERH_DECL(contextType, any_type);
            ITU_T_HOLDERH_DECL(contextValues, ContextValues_type);  //    Sc (  [ 1  ...    ]   
            ITU_T_DEFAULTH_DECL(fallback, bool, fallback__default);

            ITU_T_ARCHIVE_FUNC;
        };
 
        const AttributeUsage attributeUsage_userApplications = 0;
        const AttributeUsage attributeUsage_directoryOperation = 1;
        const AttributeUsage attributeUsage_distributedOperation = 2;
        const AttributeUsage attributeUsage_dSAOperation = 3;

    ITU_T_ARCHIVE_X690_DECL(Name);
    ITU_T_ARCHIVE_X690_DECL(AttributeTypeAndDistinguishedValue);
    ITU_T_ARCHIVE_X690_DECL(AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of);
    ITU_T_ARCHIVE_X690_DECL(Context);

    ITU_T_ARCHIVE_X691_DECL(Name);
    ITU_T_ARCHIVE_X691_DECL(AttributeTypeAndDistinguishedValue);
    ITU_T_ARCHIVE_X691_DECL(AttributeTypeAndDistinguishedValue::ValuesWithContext_type_set_of);
    ITU_T_ARCHIVE_X691_DECL(Context);

} 

ITU_T_CHOICE_REGESTRATE(InformationFramework::Name)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___INFORMATIONFRAMEWORK */
