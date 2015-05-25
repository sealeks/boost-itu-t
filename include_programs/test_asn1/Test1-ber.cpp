#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    // set  PersonnelRecord

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_BIND_TAG(*number_);
        ITU_T_EXPLICIT_TAG(*title_, 0);
        ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
        ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
        ITU_T_IMPLICIT_TAG(children_, 3);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_BIND_TAG(*number_);
        ITU_T_EXPLICIT_TAG(*title_, 0);
        ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
        ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
        ITU_T_IMPLICIT_TAG(children_, 3);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    // set  PersonnelRecord-s

    template<> void PersonnelRecord_s_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_BIND_TAG(*number_);
        ITU_T_EXPLICIT_TAG(*title_, 0);
        ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
        ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
        ITU_T_IMPLICIT_TAG(children_, 3);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    template<> void PersonnelRecord_s_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_BIND_TAG(*number_);
        ITU_T_EXPLICIT_TAG(*title_, 0);
        ITU_T_EXPLICIT_TAG(*dateOfHire_, 1);
        ITU_T_EXPLICIT_TAG(*nameOfSpouse_, 2);
        ITU_T_IMPLICIT_TAG(children_, 3);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    // set  ChildInformation

    template<> void ChildInformation::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);

        ITU_T_RESET_EXTENTION;

        ITU_T_IMPLICIT_TAG(sex_, 1);
        ITU_T_RESET_EXTENTION;

    }

    template<> void ChildInformation::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);

        ITU_T_RESET_EXTENTION;

        ITU_T_IMPLICIT_TAG(sex_, 1);
        ITU_T_RESET_EXTENTION;

    }

    // set  ChildInformation-s

    template<> void ChildInformation_s::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    template<> void ChildInformation_s::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*name_);
        ITU_T_EXPLICIT_TAG(*dateOfBirth_, 0);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    // sequence Name

    template<> void Name_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*givenName_);
        ITU_T_BIND_TAG(*initial_);
        ITU_T_BIND_TAG(*familyName_);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    template<> void Name_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*givenName_);
        ITU_T_BIND_TAG(*initial_);
        ITU_T_BIND_TAG(*familyName_);

        ITU_T_RESET_EXTENTION;

        ITU_T_RESET_EXTENTION;

    }

    // sequence Ax

    template<> void Ax::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(*a_);
        ITU_T_BIND_TAG(*b_);
        ITU_T_BIND_CHOICE(*c_);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(*g_);
        ITU_T_BIND_TAG(h_);
        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(i_);
        ITU_T_BIND_TAG(j_);
    }

    template<> void Ax::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(*a_);
        ITU_T_BIND_TAG(*b_);
        ITU_T_BIND_CHOICE(*c_);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(*g_);
        ITU_T_BIND_TAG(h_);
        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(i_);
        ITU_T_BIND_TAG(j_);
    }

    // choice c

    template<> void Ax::C_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case C_type_d:
            {
                ITU_T_BIND_TAG(*value<integer_type > (false, C_type_d));
                break;
            }
            case C_type_e:
            {
                ITU_T_BIND_TAG(*value<bool > (false, C_type_e));
                break;
            }
            case C_type_f:
            {
                ITU_T_BIND_TAG(*value<ia5string_type > (false, C_type_f));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Ax::C_type::serialize(boost::asn1::x690::input_coder& arch) {

        if (ITU_T_BIND_TAG(*value<integer_type > (true, C_type_d))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<bool > (true, C_type_e))) return;
        else free();
        if (ITU_T_BIND_TAG(*value<ia5string_type > (true, C_type_f))) return;
        else free();
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

