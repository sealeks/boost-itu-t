#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    // set  PersonnelRecord

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*title_, 0);
        ITU_T_BIND_TAG(*number_);
        ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
        ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
        ITU_T_IMPLICIT_TAG(children_, 3);
        ITU_T_RESET_EXTENTION;
    }

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*title_, 0);
        ITU_T_BIND_TAG(*number_);
        ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
        ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
        ITU_T_IMPLICIT_TAG(children_, 3);
        ITU_T_RESET_EXTENTION;
    }

    // set  ChildInformation

    template<> void ChildInformation::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);
        ITU_T_RESET_EXTENTION;
        ITU_T_IMPLICIT_TAG(sex_, 1);
    }

    template<> void ChildInformation::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);
        ITU_T_RESET_EXTENTION;
        ITU_T_IMPLICIT_TAG(sex_, 1);
    }

    // sequence Name

    template<> void Name_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*givenName_);
        ITU_T_BIND_TAG(*initial_);
        ITU_T_BIND_TAG(*familyName_);
        ITU_T_RESET_EXTENTION;
    }

    template<> void Name_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*givenName_);
        ITU_T_BIND_TAG(*initial_);
        ITU_T_BIND_TAG(*familyName_);
        ITU_T_RESET_EXTENTION;
    }

    // sequence A

    template<> void A::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*a_, 0);
        ITU_T_RESET_EXTENTION;
        ITU_T_EXPLICIT_TAG(b_, 1);
        ITU_T_EXPLICIT_TAG(c_, 2);
        ITU_T_EXPLICIT_TAG(d_, 3);
        ITU_T_EXPLICIT_TAG(e_, 4);
    }

    template<> void A::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*a_, 0);
        ITU_T_RESET_EXTENTION;
        ITU_T_EXPLICIT_TAG(b_, 1);
        ITU_T_EXPLICIT_TAG(c_, 2);
        ITU_T_EXPLICIT_TAG(d_, 3);
        ITU_T_EXPLICIT_TAG(e_, 4);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

