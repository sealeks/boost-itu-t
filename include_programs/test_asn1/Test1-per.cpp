#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {




    //  helper name:   ChildInformation__enumerated_type           type:  enumerated helper    
    ITU_T_PER_ENUMCODER(ChildInformation__enumerated_type__helper, false, ITU_T_ARRAY(1, 2, 3));


    //  helper name:   Date           type:  alphabet helper     //    Sc (  [ 8 ]     //    c8C (  [ 0  ...   9 ]   

    struct Date__shelper {

        static void out(boost::asn1::x691::output_coder& stream, boost::asn1::visiblestring_type::value_type vl) {
            stream.add_bitmap(boost::asn1::bitstring_type(boost::asn1::octet_sequnce(1,
                    boost::asn1::octet_sequnce::value_type((vl - '\x30') << 4)), 4));
        }

        static boost::asn1::visiblestring_type::value_type in(boost::asn1::x691::input_coder& stream) {
            boost::asn1::bitstring_type vl = stream.get_pop_bmp(4);
            boost::asn1::octet_sequnce tmp = vl.as_octet_sequnce();
            if (!tmp.empty()) {
                tmp[0] >>= 4;
                tmp[0] &= '\xF';
                return (tmp[0] + '\x30');
            }
            return 0;
        }

        static std::size_t bits_count(bool aligned) {
            return 4;
        }

    };


    //  helper name:   NameString           type:  alphabet helper     //    Sc (  [ 1  ...   64 ]     //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   

    struct NameString__shelper {

        static void out(boost::asn1::x691::output_coder& stream, boost::asn1::visiblestring_type::value_type vl) {
            stream.add_bitmap(bitstring_type(boost::asn1::octet_sequnce(1, stream.aligned() ?
                    boost::asn1::octet_sequnce::value_type(vl) :
                    boost::asn1::octet_sequnce::value_type(((vl < '\x60') ? (vl - '\x3F') : (vl - '\x61' + '\x1C')) << 2)),
                    stream.aligned() ? 0 : 2));
        }

        static boost::asn1::visiblestring_type::value_type in(boost::asn1::x691::input_coder& stream) {
            boost::asn1::bitstring_type vl = stream.get_pop_bmp(stream.aligned() ? 8 : 6);
            boost::asn1::octet_sequnce tmp = vl.as_octet_sequnce();
            if (!tmp.empty()) {
                if (!stream.aligned()) {
                    tmp[0] >>= 2;
                    tmp[0] &= '\x3F';
                    if (tmp[0] > 27)
                        return (tmp[0] - 28) + 97;
                    else if (tmp[0] > 1)
                        return (tmp[0] - 2) + 65;
                    return tmp[0] + 45;
                }
                return tmp[0];
            }
            return 0;
        }

        static std::size_t bits_count(bool aligned) {
            return aligned ? 8 : 6;
        }

    };

    // set  PersonnelRecord

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_NULL;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(children_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_NUM_CONSTRE(*(*number_), static_cast<integer_type> (0), static_cast<integer_type> (9999));
        ITU_T_BIND_PER(*title_);
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
        ITU_T_BIND_PER(*(*nameOfSpouse_));
        ITU_T_BIND_SIZE_SNGLCONSTRE(children_, 2);
    }

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_NUM_CONSTRE(*(*number_), static_cast<integer_type> (0), static_cast<integer_type> (9999));
        ITU_T_BIND_PER(*title_);
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
        ITU_T_BIND_PER(*(*nameOfSpouse_));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_SIZE_SNGLCONSTRE(children_, 2);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            ITU_T_PER_CLEAR_EXTENTIONS(0);
        };

    }

    // set  PersonnelRecord-s

    template<> void PersonnelRecord_s_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_NULL;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(children_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_NUM_CONSTRE(*(*number_), static_cast<integer_type> (0), static_cast<integer_type> (9999));
        ITU_T_BIND_PER(*title_);
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
        ITU_T_BIND_PER(*(*nameOfSpouse_));
        ITU_T_BIND_SIZE_SNGLCONSTRE(children_, 2);
    }

    template<> void PersonnelRecord_s_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(1);

        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_NUM_CONSTRE(*(*number_), static_cast<integer_type> (0), static_cast<integer_type> (9999));
        ITU_T_BIND_PER(*title_);
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
        ITU_T_BIND_PER(*(*nameOfSpouse_));
        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_SIZE_SNGLCONSTRE(children_, 2);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            ITU_T_PER_CLEAR_EXTENTIONS(0);
        };

    }

    // set  ChildInformation

    template<> void ChildInformation::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(sex_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;

        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_BIND_PER_ENUM(sex_, ChildInformation__enumerated_type__helper);
                ITU_T_PER_END_OPEN;
            }

        };

    }

    template<> void ChildInformation::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_BIND_PER_ENUM(sex_, ChildInformation__enumerated_type__helper);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(1);
        };

    }

    // set  ChildInformation-s

    template<> void ChildInformation_s::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_NULL;

        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);
    }

    template<> void ChildInformation_s::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_PER(*(*name_));
        ITU_T_BIND_EXSIZE_SNGLCONSTRE(visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            ITU_T_PER_CLEAR_EXTENTIONS(0);
        };

    }

    // sequence Name

    template<> void Name_impl::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_NULL;

        ITU_T_BIND_EXSIZE_CONSTRE(visiblestring_type, NameString__shelper, *givenName_, 1, 64);
        ITU_T_BIND_EXSIZE_SNGLCONSTRS(visiblestring_type, NameString__shelper, *initial_, 1);
        ITU_T_BIND_EXSIZE_CONSTRE(visiblestring_type, NameString__shelper, *familyName_, 1, 64);
    }

    template<> void Name_impl::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;
        ITU_T_BIND_EXSIZE_CONSTRE(visiblestring_type, NameString__shelper, *givenName_, 1, 64);
        ITU_T_BIND_EXSIZE_SNGLCONSTRS(visiblestring_type, NameString__shelper, *initial_, 1);
        ITU_T_BIND_EXSIZE_CONSTRE(visiblestring_type, NameString__shelper, *familyName_, 1, 64);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            ITU_T_PER_CLEAR_EXTENTIONS(0);
        };

    }

    // sequence Ax

    template<> void Ax::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_GROUP_BOOL(0) = ITU_T_EXISTS_BOOL(g_) ||
                ITU_T_EXISTS_BOOL(h_);

        ITU_T_EXTENTION_GROUPS_BMP = ITU_T_EXTENTION_GROUP_AS_BMP(0);

        ITU_T_EXTENTION_WRITE;


        ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(i_) +
                ITU_T_EXISTS_BMP(j_);

        ITU_T_OPTIONAL_WRITE;

        ITU_T_BIND_NUM_CONSTRS(*a_, static_cast<uint8_t> (250), static_cast<uint8_t> (253));
        ITU_T_BIND_PER(*b_);
        ITU_T_BIND_PER(*c_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_WRITE;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_OPEN;
                ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(h_);
                ITU_T_OPTIONAL_WRITE;
                ITU_T_BIND_SIZE_SNGLCONSTRS(*g_, 3);
                ITU_T_BIND_PER(h_);
                ITU_T_PER_END_OPEN;
            }

        };

        ITU_T_BIND_PER(i_);
        ITU_T_BIND_PER(j_);
    }

    template<> void Ax::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        ITU_T_OPTIONAL_READ(2);

        ITU_T_BIND_NUM_CONSTRS(*a_, static_cast<uint8_t> (250), static_cast<uint8_t> (253));
        ITU_T_BIND_PER(*b_);
        ITU_T_BIND_PER(*c_);

        if (ITU_T_EXTENTION) {

            ITU_T_EXTENTION_GROUPS_READ;

            if (ITU_T_EXTENTION_GROUPS_CHECK(0)) {
                ITU_T_PER_START_PARSE_OPEN;
                ITU_T_OPTIONAL_READ(1);

                ITU_T_BIND_SIZE_SNGLCONSTRS(*g_, 3);
                ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(h_);
                ITU_T_PER_END_PARSE_OPEN;
            }

            ITU_T_PER_CLEAR_EXTENTIONS(1);
        };

        ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(i_);
        ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(j_);
    }

    // choice c

    template<> void Ax::C_type::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_EXTENTION_WRITE_CHOICE(C_type_e, C_type_f);

        if (ITU_T_EXTENTION) {
            ITU_T_BIND_PER(*value<integer_type > (false, C_type_d));
        } else {
            switch (type()) {
                case C_type_e:
                {
                    ITU_T_SET_NSN_SMALL_INDX(0);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<bool > (false, C_type_e));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                case C_type_f:
                {
                    ITU_T_SET_NSN_SMALL_INDX(1);
                    ITU_T_PER_START_OPEN;
                    ITU_T_BIND_PER(*value<ia5string_type > (false, C_type_f));
                    ITU_T_PER_END_OPEN;
                    break;
                }
                default:
                {
                }
            }
        }
    }

    template<> void Ax::C_type::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_EXTENTION_READ;

        if (ITU_T_EXTENTION) {
            ITU_T_BIND_PER(*value<integer_type > (true, C_type_d));
        } else {

            ITU_T_GET_NSN_SMALL_INDX;

            switch (__indx__) {
                case 0:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<bool > (false, C_type_e));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                case 1:
                {
                    ITU_T_PER_START_PARSE_OPEN;
                    ITU_T_BIND_PER(*value<ia5string_type > (false, C_type_f));
                    ITU_T_PER_END_PARSE_OPEN;
                    break;
                }
                default:
                {
                    ITU_T_PER_CLEAR_EXTENTION;
                }
            }
        }
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

