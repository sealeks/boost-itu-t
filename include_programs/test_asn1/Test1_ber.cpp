#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {


        template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(*name_);
            ITU_T_EXPLICIT_TAG(*title_, 0);
            ITU_T_BIND_TAG(*number_);
            ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
            ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
            ITU_T_IMPLICIT_TAG(children_, 3);
        }

        template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(*name_);
            ITU_T_EXPLICIT_TAG(*title_, 0);
            ITU_T_BIND_TAG(*number_);
            ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
            ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
            ITU_T_IMPLICIT_TAG(children_, 3);
        }


        template<> void ChildInformation::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(*name_);
            ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);
        }

        template<> void ChildInformation::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(*name_);
            ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);
        }


        template<> void Name_impl::serialize(boost::asn1::x690::output_coder& arch){
            ITU_T_BIND_TAG(*givenName_);
            ITU_T_BIND_TAG(*initial_);
            ITU_T_BIND_TAG(*familyName_);
        }

        template<> void Name_impl::serialize(boost::asn1::x690::input_coder& arch){
            ITU_T_BIND_TAG(*givenName_);
            ITU_T_BIND_TAG(*initial_);
            ITU_T_BIND_TAG(*familyName_);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif
