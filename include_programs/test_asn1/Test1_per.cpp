#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {


        template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::output_coder& arch){
            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_PER(*title_);
            ITU_T_BIND_PER(*number_);
            ITU_T_BIND_PER(*dateOfHire_);
            ITU_T_BIND_PER(*nameOfSpouse_);
            ITU_T_BIND_PER(children_);
        }

        template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::input_coder& arch){
            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_PER(*title_);
            ITU_T_BIND_PER(*number_);
            ITU_T_BIND_PER(*dateOfHire_);
            ITU_T_BIND_PER(*nameOfSpouse_);
            ITU_T_BIND_PER(children_);
        }


        template<> void ChildInformation::serialize(boost::asn1::x691::output_coder& arch){
            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_PER(*dateOfBirth_);
        }

        template<> void ChildInformation::serialize(boost::asn1::x691::input_coder& arch){
            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_PER(*dateOfBirth_);
        }


        template<> void Name_impl::serialize(boost::asn1::x691::output_coder& arch){
            ITU_T_BIND_PER(*givenName_);
            ITU_T_BIND_PER(*initial_);
            ITU_T_BIND_PER(*familyName_);
        }

        template<> void Name_impl::serialize(boost::asn1::x691::input_coder& arch){
            ITU_T_BIND_PER(*givenName_);
            ITU_T_BIND_PER(*initial_);
            ITU_T_BIND_PER(*familyName_);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

