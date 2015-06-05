#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {


    ITU_T_PREFIXED_DECLARE(PersonnelRecord__DateOfHire, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS), prefixed_type(1, CONTEXT_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(PersonnelRecord__NameOfSpouse, ITU_T_ARRAY(prefixed_type(1, APPLICATION_CLASS), prefixed_type(2, CONTEXT_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(PersonnelRecord_s__DateOfHire, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS), prefixed_type(1, CONTEXT_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(PersonnelRecord_s__NameOfSpouse, ITU_T_ARRAY(prefixed_type(1, APPLICATION_CLASS), prefixed_type(2, CONTEXT_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(ChildInformation__DateOfBirth, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS), prefixed_type(0, CONTEXT_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(ChildInformation_s__DateOfBirth, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS), prefixed_type(0, CONTEXT_CLASS)), false); //  initial =implicit

    // set  PersonnelRecord

    template<> void PersonnelRecord::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_IMPLICIT(number_, 2, APPLICATION_CLASS);
        ITU_T_BIND_EXPLICIT(title_, 0, CONTEXT_CLASS);
        ITU_T_BIND_PREFIXED(dateOfHire_, PersonnelRecord__DateOfHire);
        ITU_T_BIND_PREFIXED(nameOfSpouse_, PersonnelRecord__NameOfSpouse);
        ITU_T_BIND_IMPLICIT(children_, 3, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    template<> void PersonnelRecord::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_IMPLICIT(number_, 2, APPLICATION_CLASS);
        ITU_T_BIND_EXPLICIT(title_, 0, CONTEXT_CLASS);
        ITU_T_BIND_PREFIXED(dateOfHire_, PersonnelRecord__DateOfHire);
        ITU_T_BIND_PREFIXED(nameOfSpouse_, PersonnelRecord__NameOfSpouse);
        ITU_T_BIND_IMPLICIT(children_, 3, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    // set  PersonnelRecord-s

    template<> void PersonnelRecord_s::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_IMPLICIT(number_, 2, APPLICATION_CLASS);
        ITU_T_BIND_EXPLICIT(title_, 0, CONTEXT_CLASS);
        ITU_T_BIND_PREFIXED(dateOfHire_, PersonnelRecord_s__DateOfHire);
        ITU_T_BIND_PREFIXED(nameOfSpouse_, PersonnelRecord_s__NameOfSpouse);
        ITU_T_BIND_IMPLICIT(children_, 3, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    template<> void PersonnelRecord_s::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_IMPLICIT(number_, 2, APPLICATION_CLASS);
        ITU_T_BIND_EXPLICIT(title_, 0, CONTEXT_CLASS);
        ITU_T_BIND_PREFIXED(dateOfHire_, PersonnelRecord_s__DateOfHire);
        ITU_T_BIND_PREFIXED(nameOfSpouse_, PersonnelRecord_s__NameOfSpouse);
        ITU_T_BIND_IMPLICIT(children_, 3, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    // set  ChildInformation

    template<> void ChildInformation::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_PREFIXED(dateOfBirth_, ChildInformation__DateOfBirth);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_IMPLICIT(sex_, 1, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    template<> void ChildInformation::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_PREFIXED(dateOfBirth_, ChildInformation__DateOfBirth);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_IMPLICIT(sex_, 1, CONTEXT_CLASS);

        ITU_T_RESET_EXTENTION;

    }

    // set  ChildInformation-s

    template<> void ChildInformation_s::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_PREFIXED(dateOfBirth_, ChildInformation_s__DateOfBirth);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    template<> void ChildInformation_s::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(name_, 1, APPLICATION_CLASS);
        ITU_T_BIND_PREFIXED(dateOfBirth_, ChildInformation_s__DateOfBirth);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    // sequence Name

    template<> void Name::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(givenName_);
        ITU_T_BIND_TAG(initial_);
        ITU_T_BIND_TAG(familyName_);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    template<> void Name::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(givenName_);
        ITU_T_BIND_TAG(initial_);
        ITU_T_BIND_TAG(familyName_);

        ITU_T_RESET_EXTENTION;


        ITU_T_RESET_EXTENTION;

    }

    // sequence Ax

    template<> void Ax::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(a_);
        ITU_T_BIND_TAG(b_);
        ITU_T_BIND_CHOICE(c_);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(g_);
        ITU_T_BIND_TAG(h_);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(i_);
        ITU_T_BIND_TAG(j_);
    }

    template<> void Ax::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(a_);
        ITU_T_BIND_TAG(b_);
        ITU_T_BIND_CHOICE(c_);

        ITU_T_RESET_EXTENTION;

        ITU_T_BIND_TAG(g_);
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
                ITU_T_BIND_TAG(value<integer_type > (false, C_type_d));
                break;
            }
            case C_type_e:
            {
                ITU_T_BIND_TAG(value<bool > (false, C_type_e));
                break;
            }
            case C_type_f:
            {
                ITU_T_BIND_TAG(value<ia5_string > (false, C_type_f));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Ax::C_type::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    case 2:
                    {
                        if (ITU_T_BIND_TAG(value<integer_type > (true, C_type_d))) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_BIND_TAG(value<bool > (true, C_type_e))) return;
                        else free();
                        break;
                    }
                    case 22:
                    {
                        if (ITU_T_BIND_TAG(value<ia5_string > (true, C_type_f))) return;
                        else free();
                        break;
                    }
                    default:
                    {
                    }
                }
            }
            default:
            {
            }
        }
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

