#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {




    //  helper name:   Date           type:  alphabet helper     //    Sc (  [ 8 ]     //    c8C (  [ 0  ...   9 ]   

    struct Date__shelper {

        static void out(boost::asn1::x691::output_coder& stream, boost::asn1::visiblestring_type::value_type vl) {
            stream.add_bitmap(boost::asn1::bitstring_type(static_cast<boost::asn1::octet_sequnce::value_type>(vl - '\x30'), 4));
        }

        static boost::asn1::visiblestring_type::value_type in(boost::asn1::x691::input_coder& stream) {
            boost::asn1::bitstring_type vl = stream.get_pop_bmp(4);
            boost::asn1::octet_sequnce tmp = vl.as_octet_sequnce();
            if (!tmp.empty())
                return ((tmp[0] >> 4) & '\x7F') + '\x30';
            return 0;
        }

        static std::size_t bits_count(bool aligned) {
            return 4;
                }

        };


        template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_OPTIONAL_DECL_PER =  ITU_T_OPTIONAL_PER(children_);

            ITU_T_OPTIONAL_SET_PER;

            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_PER(*number_);
            ITU_T_BIND_PER(*title_);
            ITU_T_BIND_EXSIZE_SNGLCONSTRS( visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
            ITU_T_BIND_PER(*nameOfSpouse_);
            ITU_T_BIND_PER(children_);
        }

        template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_OPTIONAL_GET_PER(1 );

            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_PER(*number_);
            ITU_T_BIND_PER(*title_);
            ITU_T_BIND_EXSIZE_SNGLCONSTRS( visiblestring_type, Date__shelper,  *(*dateOfHire_), 8);
            ITU_T_BIND_PER(*nameOfSpouse_);
            ITU_T_OPTIONAL_CHECK_PER(0)  ITU_T_BIND_PER(children_);
        }


        template<> void ChildInformation::serialize(boost::asn1::x691::output_coder& arch){
            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_EXSIZE_SNGLCONSTRS( visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);
        }

        template<> void ChildInformation::serialize(boost::asn1::x691::input_coder& arch){
            ITU_T_BIND_PER(*name_);
            ITU_T_BIND_EXSIZE_SNGLCONSTRS( visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);
        }


        template<> void Name_impl::serialize(boost::asn1::x691::output_coder& arch){
            ITU_T_BIND_PER(*givenName_);
            ITU_T_BIND_SIZE_SNGLCONSTRS( *initial_, 1);
            ITU_T_BIND_PER(*familyName_);
        }

        template<> void Name_impl::serialize(boost::asn1::x691::input_coder& arch){
            ITU_T_BIND_PER(*givenName_);
            ITU_T_BIND_SIZE_SNGLCONSTRS( *initial_, 1);
            ITU_T_BIND_PER(*familyName_);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

