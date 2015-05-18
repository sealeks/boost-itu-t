#ifndef ___REMOTE_OPERATIONS_INFORMATION_OBJECTS
#define ___REMOTE_OPERATIONS_INFORMATION_OBJECTS

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Remote_Operations_Information_Objects {

    using boost::asn1::null_type;
    using boost::asn1::enumerated_type;
    using boost::asn1::bitstring_type;
    using boost::asn1::octetstring_type;
    using boost::asn1::oid_type;
    using boost::asn1::reloid_type;
    using boost::asn1::utctime_type;
    using boost::asn1::gentime_type;
    using boost::asn1::ia5string_type;
    using boost::asn1::printablestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::numericstring_type;
    using boost::asn1::universalstring_type;
    using boost::asn1::bmpstring_type;
    using boost::asn1::utf8string_type;
    using boost::asn1::generalstring_type;
    using boost::asn1::graphicstring_type;
    using boost::asn1::t61string_type;
    using boost::asn1::t61string_type;
    using boost::asn1::videotexstring_type;
    using boost::asn1::objectdescriptor_type;
    using boost::asn1::external_type;
    using boost::asn1::embeded_type;
    using boost::asn1::characterstring_type;
    using boost::asn1::any_type;
    using boost::asn1::value_holder;
    using boost::asn1::default_holder;
    using boost::shared_ptr;

    struct Code;


    typedef int Priority;


}

#include <boost/itu/x22X/presentation/Remote-Operations-Useful-Definitions.hpp>

namespace Remote_Operations_Information_Objects {

    // import   from  Remote-Operations-Useful-Definitions



    // choice Code

    enum Code_enum {

        Code_null = 0,
        Code_local,
        Code_global,
    };

    struct Code : public ITU_T_CHOICE(Code_enum) {

        Code() : ITU_T_CHOICE(Code_enum) () {
        }

        template<typename T > Code(boost::shared_ptr< T> vl, Code_enum enm) :
                ITU_T_CHOICE(Code_enum) (vl, static_cast<int> (enm)) {
        }

        template<typename T > Code(const T& vl, Code_enum enm) :
                ITU_T_CHOICE(Code_enum) (new T(vl), static_cast<int> (enm)) {
        }

        ITU_T_CHOICES_DECL(local, int, Code_local); // primitive
        ITU_T_CHOICES_DECL(global, oid_type, Code_global); // primitive

        ITU_T_ARCHIVE_FUNC;
    };

    template<> void Code::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Code::serialize(boost::asn1::x690::input_coder& arch);
}

ITU_T_CHOICE_REGESTRATE(Remote_Operations_Information_Objects::Code)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___REMOTE_OPERATIONS_INFORMATION_OBJECTS */
