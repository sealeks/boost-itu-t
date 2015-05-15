#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {




        //  helper name:   ChildInformation__enumerated_type           type:  enumerated helper    
        ITU_T_PER_ENUMCODER(ChildInformation__enumerated_type__helper, ITU_T_ARRAY(1, 2, 3));


                //  helper name:   Date           type:  alphabet helper     //    Sc (  [ 8 ]     //    c8C (  [ 0  ...   9 ]   

        struct Date__shelper {

        static void out(boost::asn1::x691::output_coder& stream, boost::asn1::visiblestring_type::value_type vl) {
            stream.add_bitmap(boost::asn1::bitstring_type(boost::asn1::octet_sequnce(1,
                    boost::asn1::octet_sequnce::value_type((vl - '\x30') << 4)), 4));
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
            if (!tmp.empty())
                return stream.aligned() ? tmp[0] : ((tmp[0] >> 2) & '\x3F') + '\x3F';
            return 0;
                }

        static std::size_t bits_count(bool aligned) {
            return aligned ? 8 : 6;
                }

        };


        template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_EXTENTION_SET_PER;

            ITU_T_OPTIONAL_DECL_PER =  ITU_T_OPTIONAL_PER(children_);

            ITU_T_OPTIONAL_SET_PER;

            ITU_T_BIND_PER(*(*name_));
            ITU_T_BIND_NUM_CONSTRE( *(*number_), 0, 9999);
            ITU_T_BIND_PER(*title_);
            ITU_T_BIND_EXSIZE_SNGLCONSTRE( visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
            ITU_T_BIND_PER(*(*nameOfSpouse_));
            ITU_T_BIND_SIZE_SNGLCONSTRE( children_, 2);
        }

        template<> void PersonnelRecord_impl::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_EXTENTION_GET_PER;

            ITU_T_OPTIONAL_GET_PER(1 );

            ITU_T_BIND_PER(*(*name_));
            ITU_T_BIND_NUM_CONSTRE( *(*number_), 0, 9999);
            ITU_T_BIND_PER(*title_);
            ITU_T_BIND_EXSIZE_SNGLCONSTRE( visiblestring_type, Date__shelper, *(*dateOfHire_), 8);
            ITU_T_BIND_PER(*(*nameOfSpouse_));
            ITU_T_OPTIONAL_CHECK_PER(0)  ITU_T_BIND_SIZE_SNGLCONSTRE( children_, 2);
        }


        template<> void ChildInformation::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_EXTENTION_SET_PER;
            ITU_T_BIND_PER(*(*name_));
            ITU_T_BIND_EXSIZE_SNGLCONSTRE( visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);
            
        }

        template<> void ChildInformation::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_EXTENTION_GET_PER;
            ITU_T_BIND_PER(*(*name_));
            ITU_T_BIND_EXSIZE_SNGLCONSTRE( visiblestring_type, Date__shelper, *(*dateOfBirth_), 8);
            
        }


        template<> void Name_impl::serialize(boost::asn1::x691::output_coder& arch){

            ITU_T_EXTENTION_SET_PER;
            ITU_T_BIND_EXSIZE_CONSTRE( visiblestring_type, NameString__shelper, *givenName_, 1, 64);
            ITU_T_BIND_EXSIZE_SNGLCONSTRS( visiblestring_type, NameString__shelper, *initial_, 1);
            ITU_T_BIND_EXSIZE_CONSTRE( visiblestring_type, NameString__shelper, *familyName_, 1, 64);
        }

        template<> void Name_impl::serialize(boost::asn1::x691::input_coder& arch){

            ITU_T_EXTENTION_GET_PER;
            ITU_T_BIND_EXSIZE_CONSTRE( visiblestring_type, NameString__shelper, *givenName_, 1, 64);
            ITU_T_BIND_EXSIZE_SNGLCONSTRS( visiblestring_type, NameString__shelper, *initial_, 1);
            ITU_T_BIND_EXSIZE_CONSTRE( visiblestring_type, NameString__shelper, *familyName_, 1, 64);
        }

} 


#ifdef _MSC_VER
#pragma warning(pop)
#endif

