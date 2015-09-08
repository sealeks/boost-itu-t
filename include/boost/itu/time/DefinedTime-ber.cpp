#include "DefinedTime.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif


namespace boost {
    namespace asn1 {

        using namespace time_detail;

        // choice DATE-TYPE

        template<> void DATE_TYPE::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void DATE_TYPE::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }


        // sequence TIME-TYPE

        template<> void TIME_TYPE::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void TIME_TYPE::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }


        // sequence TIME-TYPE

        template<> void DATE_TIME_ENC::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void DATE_TIME_ENC::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }


        template<> void MIXED_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void MIXED_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }        
        
    }
}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

