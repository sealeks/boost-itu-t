#include "DefinedTime.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif


namespace boost {
    namespace asn1 {


        using namespace time_detail;  

        // sequence CENTURY-ENCODING

        template<> void CENTURY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(as_number()), 2, '0');
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void CENTURY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_number(visible_string_to_def(tmpval, 0, "0"));
        }

        // sequence ANY-CENTURY-ENCODING

        template<> void ANY_CENTURY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(as_number()));
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void ANY_CENTURY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_number(visible_string_to_def(tmpval, 0));
        }

        // choice YEAR-ENCODING

        template<> void YEAR_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(as_number()));
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void YEAR_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_number(visible_string_to_def(tmpval, 0, "0"));
        }

        // sequence ANY-YEAR-ENCODING

        template<> void ANY_YEAR_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(as_number()));
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void ANY_YEAR_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_number(visible_string_to_def(tmpval, 0, "0"));
        }

        // sequence YEAR-MONTH-ENCODING

        template<> void YEAR_MONTH_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(year().as_number()), 4,'0') + 
                    to_visible_string(static_cast<int>(month()), 2,'0');
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void YEAR_MONTH_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            std::string yr=tmpval.size()>2 ? tmpval.substr(0,tmpval.size()-2) : "";
            std::string mth=tmpval.size()>=2 ? tmpval.substr(tmpval.size()-2) : "";  
            year(string_to_def(yr, 0, "0"));
            month(string_to_def(mth, 0, "0"));
        }

        // sequence ANY-YEAR-MONTH-ENCODING

        template<> void ANY_YEAR_MONTH_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(year().as_number())) + 
                    to_visible_string(static_cast<int>(month()), 2,'0');
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void ANY_YEAR_MONTH_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            std::string yr=tmpval.size()>2 ? tmpval.substr(0,tmpval.size()-2) : "";
            std::string mth=tmpval.size()>=2 ? tmpval.substr(tmpval.size()-2) : "";  
            year(string_to_def(yr, 0, "0"));
            month(string_to_def(mth, 0, "0"));
        }

        // sequence DATE-ENCODING

        template<> void DATE_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(year().as_number()), 4,'0') + 
                    to_visible_string(static_cast<int>(month()), 2,'0')+to_visible_string(static_cast<int>(day()), 2,'0');
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void DATE_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            std::string yr=tmpval.size()>4 ? tmpval.substr(0,tmpval.size()-4) : "";
            std::string mth=tmpval.size()>=4 ? tmpval.substr(tmpval.size()-4,2) : "";  
            std::string dy=tmpval.size()>=2 ? tmpval.substr(tmpval.size()-2,2) : "";            
            year(string_to_def(yr, 0, "0"));
            month(string_to_def(mth, 0, "0"));
            day(string_to_def(dy, 0, "0"));
        }

        // sequence ANY-DATE-ENCODING

        template<> void ANY_DATE_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval=to_visible_string(static_cast<int>(year().as_number())) + 
                    to_visible_string(static_cast<int>(month()), 2,'0')+to_visible_string(static_cast<int>(day()), 2,'0');
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void ANY_DATE_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            std::string yr=tmpval.size()>4 ? tmpval.substr(0,tmpval.size()-4) : "";
            std::string mth=tmpval.size()>=4 ? tmpval.substr(tmpval.size()-4,2) : "";  
            std::string dy=tmpval.size()>=2 ? tmpval.substr(tmpval.size()-2,2) : "";            
            year(string_to_def(yr, 0, "0"));
            month(string_to_def(mth, 0, "0"));
            day(string_to_def(dy, 0, "0"));
        }

        // sequence YEAR-DAY-ENCODING

        template<> void YEAR_DAY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 1, CONTEXT_CLASS);
        }

        template<> void YEAR_DAY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 1, CONTEXT_CLASS);
        }

        // sequence ANY-YEAR-DAY-ENCODING

        template<> void ANY_YEAR_DAY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 1, CONTEXT_CLASS);
        }

        template<> void ANY_YEAR_DAY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 1, CONTEXT_CLASS);
        }

        // sequence YEAR-WEEK-ENCODING

        template<> void YEAR_WEEK_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
        }

        template<> void YEAR_WEEK_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
        }

        // sequence ANY-YEAR-WEEK-ENCODING

        template<> void ANY_YEAR_WEEK_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
        }

        template<> void ANY_YEAR_WEEK_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
        }

        // sequence YEAR-WEEK-DAY-ENCODING

        template<> void YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 2, CONTEXT_CLASS);
        }

        template<> void YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 2, CONTEXT_CLASS);
        }

        // sequence ANY-YEAR-WEEK-DAY-ENCODING

        template<> void ANY_YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 2, CONTEXT_CLASS);
        }

        template<> void ANY_YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(year_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(week_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(day_, 2, CONTEXT_CLASS);
        }

        // sequence HOURS-ENCODING

        template<> void HOURS_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(as_number_, 0, CONTEXT_CLASS);
        }

        template<> void HOURS_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(as_number_, 0, CONTEXT_CLASS);
        }

        // sequence HOURS-UTC-ENCODING

        template<> void HOURS_UTC_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(as_number_, 0, CONTEXT_CLASS);
        }

        template<> void HOURS_UTC_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(as_number_, 0, CONTEXT_CLASS);
        }

        // sequence HOURS-AND-DIFF-ENCODING

        template<> void HOURS_AND_DIFF_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        template<> void HOURS_AND_DIFF_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        // sequence TIME-DIFFERENCE

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(sign_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(hours_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 2, CONTEXT_CLASS);
        }

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(sign_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(hours_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 2, CONTEXT_CLASS);
        }

        // sequence MINUTES-ENCODING

        template<> void MINUTES_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
        }

        template<> void MINUTES_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
        }

        // sequence MINUTES-UTC-ENCODING

        template<> void MINUTES_UTC_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
        }

        template<> void MINUTES_UTC_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
        }

        // sequence MINUTES-AND-DIFF-ENCODING

        template<> void MINUTES_AND_DIFF_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        template<> void MINUTES_AND_DIFF_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        // sequence local-time

        template<> void MINUTES_AND_DIFF_ENCODING::Local_time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
        }

        template<> void MINUTES_AND_DIFF_ENCODING::Local_time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
        }

        // sequence TIME-OF-DAY-ENCODING

        template<> void TIME_OF_DAY_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
        }

        // sequence TIME-OF-DAY-UTC-ENCODING

        template<> void TIME_OF_DAY_UTC_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_UTC_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
        }

        // sequence TIME-OF-DAY-AND-DIFF-ENCODING

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        // sequence local-time

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
        }

        // sequence HOURS-AND-FRACTION-ENCODING

        template<> void HOURS_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 1, CONTEXT_CLASS);
        }

        template<> void HOURS_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 1, CONTEXT_CLASS);
        }

        // sequence HOURS-UTC-AND-FRACTION-ENCODING

        template<> void HOURS_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 1, CONTEXT_CLASS);
        }

        template<> void HOURS_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 1, CONTEXT_CLASS);
        }

        // sequence HOURS-AND-DIFF-AND-FRACTION-ENCODING

        template<> void HOURS_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 2, CONTEXT_CLASS);
        }

        template<> void HOURS_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 2, CONTEXT_CLASS);
        }

        // sequence MINUTES-AND-FRACTION-ENCODING

        template<> void MINUTES_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 2, CONTEXT_CLASS);
        }

        template<> void MINUTES_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 2, CONTEXT_CLASS);
        }

        // sequence MINUTES-UTC-AND-FRACTION-ENCODING

        template<> void MINUTES_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 2, CONTEXT_CLASS);
        }

        template<> void MINUTES_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 2, CONTEXT_CLASS);
        }

        // sequence MINUTES-AND-DIFF-AND-FRACTION-ENCODING

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        // sequence local-time

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 2, CONTEXT_CLASS);
        }

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 2, CONTEXT_CLASS);
        }

        // sequence TIME-OF-DAY-AND-FRACTION-ENCODING

        template<> void TIME_OF_DAY_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 3, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 3, CONTEXT_CLASS);
        }

        // sequence TIME-OF-DAY-UTC-AND-FRACTION-ENCODING

        template<> void TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 3, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 3, CONTEXT_CLASS);
        }

        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(local_time_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_difference_, 1, CONTEXT_CLASS);
        }

        // sequence local-time

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 3, CONTEXT_CLASS);
        }

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(hours_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fraction_, 3, CONTEXT_CLASS);
        }

        // sequence DURATION-INTERVAL-ENCODING

        template<> void DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(years_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(months_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(weeks_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(days_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(hours_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fractional_part_, 7, CONTEXT_CLASS);
        }

        template<> void DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(years_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(months_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(weeks_, 2, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(days_, 3, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(hours_, 4, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(minutes_, 5, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(seconds_, 6, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fractional_part_, 7, CONTEXT_CLASS);
        }

        // sequence fractional-part

        template<> void DURATION_INTERVAL_ENCODING::Fractional_part_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fractional_value_, 1, CONTEXT_CLASS);
        }

        template<> void DURATION_INTERVAL_ENCODING::Fractional_part_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(fractional_value_, 1, CONTEXT_CLASS);
        }

        // sequence REC-DURATION-INTERVAL-ENCODING

        template<> void REC_DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        template<> void REC_DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        // choice MIXED-ENCODING

        template<> void MIXED_ENCODING::serialize(boost::asn1::x690::output_coder& arch) {
            switch (type()) {
                case MIXED_ENCODING_date_C_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<CENTURY_ENCODING > (false, MIXED_ENCODING_date_C_Basic), 0, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_C_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_CENTURY_ENCODING > (false, MIXED_ENCODING_date_C_L), 1, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_Y_Basic:
                {
                    ITU_T_BIND_CHOICE_TAG(value<YEAR_ENCODING > (false, MIXED_ENCODING_date_Y_Basic), 2, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_Y_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_ENCODING > (false, MIXED_ENCODING_date_Y_L), 3, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YM_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_MONTH_ENCODING > (false, MIXED_ENCODING_date_YM_Basic), 4, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YM_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_MONTH_ENCODING > (false, MIXED_ENCODING_date_YM_L), 5, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YMD_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<DATE_ENCODING > (false, MIXED_ENCODING_date_YMD_Basic), 6, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YMD_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_DATE_ENCODING > (false, MIXED_ENCODING_date_YMD_L), 7, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YD_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_DAY_ENCODING > (false, MIXED_ENCODING_date_YD_Basic), 8, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YD_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_DAY_ENCODING > (false, MIXED_ENCODING_date_YD_L), 9, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YW_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_ENCODING > (false, MIXED_ENCODING_date_YW_Basic), 10, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YW_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_ENCODING > (false, MIXED_ENCODING_date_YW_L), 11, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YWD_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_DAY_ENCODING > (false, MIXED_ENCODING_date_YWD_Basic), 12, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_YWD_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_DAY_ENCODING > (false, MIXED_ENCODING_date_YWD_L), 13, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_H_L:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_ENCODING > (false, MIXED_ENCODING_time_H_L), 14, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_H_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_UTC_ENCODING > (false, MIXED_ENCODING_time_H_Z), 15, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_H_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_AND_DIFF_ENCODING > (false, MIXED_ENCODING_time_H_LD), 16, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HM_L:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_ENCODING > (false, MIXED_ENCODING_time_HM_L), 17, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HM_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_UTC_ENCODING > (false, MIXED_ENCODING_time_HM_Z), 18, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HM_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_AND_DIFF_ENCODING > (false, MIXED_ENCODING_time_HM_LD), 19, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMS_L:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_ENCODING > (false, MIXED_ENCODING_time_HMS_L), 20, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMS_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_UTC_ENCODING > (false, MIXED_ENCODING_time_HMS_Z), 21, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMS_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_DIFF_ENCODING > (false, MIXED_ENCODING_time_HMS_LD), 22, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HFn_L:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HFn_L_type > (false, MIXED_ENCODING_time_HFn_L), 23, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HFn_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HFn_Z_type > (false, MIXED_ENCODING_time_HFn_Z), 24, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HFn_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HFn_LD_type > (false, MIXED_ENCODING_time_HFn_LD), 25, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMFn_L:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HMFn_L_type > (false, MIXED_ENCODING_time_HMFn_L), 26, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMFn_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HMFn_Z_type > (false, MIXED_ENCODING_time_HMFn_Z), 27, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMFn_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HMFn_LD_type > (false, MIXED_ENCODING_time_HMFn_LD), 28, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMFSn_L:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HMFSn_L_type > (false, MIXED_ENCODING_time_HMFSn_L), 29, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMFSn_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HMFSn_Z_type > (false, MIXED_ENCODING_time_HMFSn_Z), 30, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_time_HMFSn_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<Time_HMFSn_LD_type > (false, MIXED_ENCODING_time_HMFSn_LD), 31, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_date_time:
                {
                    ITU_T_BIND_IMPLICIT(value<Date_time_type > (false, MIXED_ENCODING_date_time), 32, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_SE_Date:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_SE_Date_type > (false, MIXED_ENCODING_iterval_SE_Date), 33, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_SE_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_SE_Time_type > (false, MIXED_ENCODING_iterval_SE_Time), 34, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_SE_Date_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_SE_Date_Time_type > (false, MIXED_ENCODING_iterval_SE_Date_Time), 35, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_D:
                {
                    ITU_T_BIND_IMPLICIT(value<DURATION_INTERVAL_ENCODING > (false, MIXED_ENCODING_iterval_D), 36, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_SD_Date:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_SD_Date_type > (false, MIXED_ENCODING_iterval_SD_Date), 37, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_SD_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_SD_Time_type > (false, MIXED_ENCODING_iterval_SD_Time), 38, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_SD_Date_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_SD_Date_Time_type > (false, MIXED_ENCODING_iterval_SD_Date_Time), 39, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_DE_Date:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_DE_Date_type > (false, MIXED_ENCODING_iterval_DE_Date), 40, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_DE_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_DE_Time_type > (false, MIXED_ENCODING_iterval_DE_Time), 41, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_iterval_DE_Date_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Iterval_DE_Date_Time_type > (false, MIXED_ENCODING_iterval_DE_Date_Time), 42, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SE_Date:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_SE_Date_type > (false, MIXED_ENCODING_rec_Interval_SE_Date), 43, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SE_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_SE_Time_type > (false, MIXED_ENCODING_rec_Interval_SE_Time), 44, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SE_Date_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_SE_Date_Time_type > (false, MIXED_ENCODING_rec_Interval_SE_Date_Time), 45, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_D:
                {
                    ITU_T_BIND_IMPLICIT(value<REC_DURATION_INTERVAL_ENCODING > (false, MIXED_ENCODING_rec_Interval_D), 46, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SD_Date:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_SD_Date_type > (false, MIXED_ENCODING_rec_Interval_SD_Date), 47, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SD_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_SD_Time_type > (false, MIXED_ENCODING_rec_Interval_SD_Time), 48, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SD_Date_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_SD_Date_Time_type > (false, MIXED_ENCODING_rec_Interval_SD_Date_Time), 49, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_DE_Date:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_DE_Date_type > (false, MIXED_ENCODING_rec_Interval_DE_Date), 50, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_DE_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_DE_Time_type > (false, MIXED_ENCODING_rec_Interval_DE_Time), 51, CONTEXT_CLASS);
                    break;
                }
                case MIXED_ENCODING_rec_Interval_DE_Date_Time:
                {
                    ITU_T_BIND_IMPLICIT(value<Rec_Interval_DE_Date_Time_type > (false, MIXED_ENCODING_rec_Interval_DE_Date_Time), 52, CONTEXT_CLASS);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void MIXED_ENCODING::serialize(boost::asn1::x690::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            switch (arch.test_class()) {
                case 0x80:
                {
                    switch (__tag_id__) {
                        case 0:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<CENTURY_ENCODING > (true, MIXED_ENCODING_date_C_Basic), 0, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 1:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_CENTURY_ENCODING > (true, MIXED_ENCODING_date_C_L), 1, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_BIND_CHOICE_TAG(value<YEAR_ENCODING > (true, MIXED_ENCODING_date_Y_Basic), 2, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 3:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_ENCODING > (true, MIXED_ENCODING_date_Y_L), 3, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 4:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_MONTH_ENCODING > (true, MIXED_ENCODING_date_YM_Basic), 4, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 5:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_MONTH_ENCODING > (true, MIXED_ENCODING_date_YM_L), 5, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 6:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<DATE_ENCODING > (true, MIXED_ENCODING_date_YMD_Basic), 6, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 7:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_DATE_ENCODING > (true, MIXED_ENCODING_date_YMD_L), 7, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 8:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_DAY_ENCODING > (true, MIXED_ENCODING_date_YD_Basic), 8, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 9:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_DAY_ENCODING > (true, MIXED_ENCODING_date_YD_L), 9, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 10:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_ENCODING > (true, MIXED_ENCODING_date_YW_Basic), 10, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 11:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_ENCODING > (true, MIXED_ENCODING_date_YW_L), 11, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 12:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_DAY_ENCODING > (true, MIXED_ENCODING_date_YWD_Basic), 12, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 13:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_DAY_ENCODING > (true, MIXED_ENCODING_date_YWD_L), 13, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 14:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_ENCODING > (true, MIXED_ENCODING_time_H_L), 14, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 15:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_UTC_ENCODING > (true, MIXED_ENCODING_time_H_Z), 15, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 16:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_AND_DIFF_ENCODING > (true, MIXED_ENCODING_time_H_LD), 16, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 17:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_ENCODING > (true, MIXED_ENCODING_time_HM_L), 17, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 18:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_UTC_ENCODING > (true, MIXED_ENCODING_time_HM_Z), 18, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 19:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_AND_DIFF_ENCODING > (true, MIXED_ENCODING_time_HM_LD), 19, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 20:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_ENCODING > (true, MIXED_ENCODING_time_HMS_L), 20, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 21:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_UTC_ENCODING > (true, MIXED_ENCODING_time_HMS_Z), 21, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 22:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_DIFF_ENCODING > (true, MIXED_ENCODING_time_HMS_LD), 22, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 23:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HFn_L_type > (true, MIXED_ENCODING_time_HFn_L), 23, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 24:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HFn_Z_type > (true, MIXED_ENCODING_time_HFn_Z), 24, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 25:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HFn_LD_type > (true, MIXED_ENCODING_time_HFn_LD), 25, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 26:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HMFn_L_type > (true, MIXED_ENCODING_time_HMFn_L), 26, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 27:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HMFn_Z_type > (true, MIXED_ENCODING_time_HMFn_Z), 27, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 28:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HMFn_LD_type > (true, MIXED_ENCODING_time_HMFn_LD), 28, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 29:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HMFSn_L_type > (true, MIXED_ENCODING_time_HMFSn_L), 29, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 30:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HMFSn_Z_type > (true, MIXED_ENCODING_time_HMFSn_Z), 30, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 31:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Time_HMFSn_LD_type > (true, MIXED_ENCODING_time_HMFSn_LD), 31, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 32:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Date_time_type > (true, MIXED_ENCODING_date_time), 32, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 33:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_SE_Date_type > (true, MIXED_ENCODING_iterval_SE_Date), 33, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 34:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_SE_Time_type > (true, MIXED_ENCODING_iterval_SE_Time), 34, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 35:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_SE_Date_Time_type > (true, MIXED_ENCODING_iterval_SE_Date_Time), 35, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 36:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<DURATION_INTERVAL_ENCODING > (true, MIXED_ENCODING_iterval_D), 36, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 37:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_SD_Date_type > (true, MIXED_ENCODING_iterval_SD_Date), 37, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 38:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_SD_Time_type > (true, MIXED_ENCODING_iterval_SD_Time), 38, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 39:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_SD_Date_Time_type > (true, MIXED_ENCODING_iterval_SD_Date_Time), 39, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 40:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_DE_Date_type > (true, MIXED_ENCODING_iterval_DE_Date), 40, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 41:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_DE_Time_type > (true, MIXED_ENCODING_iterval_DE_Time), 41, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 42:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Iterval_DE_Date_Time_type > (true, MIXED_ENCODING_iterval_DE_Date_Time), 42, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 43:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_SE_Date_type > (true, MIXED_ENCODING_rec_Interval_SE_Date), 43, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 44:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_SE_Time_type > (true, MIXED_ENCODING_rec_Interval_SE_Time), 44, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 45:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_SE_Date_Time_type > (true, MIXED_ENCODING_rec_Interval_SE_Date_Time), 45, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 46:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<REC_DURATION_INTERVAL_ENCODING > (true, MIXED_ENCODING_rec_Interval_D), 46, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 47:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_SD_Date_type > (true, MIXED_ENCODING_rec_Interval_SD_Date), 47, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 48:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_SD_Time_type > (true, MIXED_ENCODING_rec_Interval_SD_Time), 48, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 49:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_SD_Date_Time_type > (true, MIXED_ENCODING_rec_Interval_SD_Date_Time), 49, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 50:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_DE_Date_type > (true, MIXED_ENCODING_rec_Interval_DE_Date), 50, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 51:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_DE_Time_type > (true, MIXED_ENCODING_rec_Interval_DE_Time), 51, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 52:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<Rec_Interval_DE_Date_Time_type > (true, MIXED_ENCODING_rec_Interval_DE_Date_Time), 52, CONTEXT_CLASS)) return;
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

        // sequence time-HFn-L

        template<> void MIXED_ENCODING::Time_HFn_L_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HFn_L_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HFn-Z

        template<> void MIXED_ENCODING::Time_HFn_Z_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HFn_Z_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HFn-LD

        template<> void MIXED_ENCODING::Time_HFn_LD_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HFn_LD_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HMFn-L

        template<> void MIXED_ENCODING::Time_HMFn_L_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HMFn_L_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HMFn-Z

        template<> void MIXED_ENCODING::Time_HMFn_Z_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HMFn_Z_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HMFn-LD

        template<> void MIXED_ENCODING::Time_HMFn_LD_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HMFn_LD_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HMFSn-L

        template<> void MIXED_ENCODING::Time_HMFSn_L_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HMFSn_L_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HMFSn-Z

        template<> void MIXED_ENCODING::Time_HMFSn_Z_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HMFSn_Z_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence time-HMFSn-LD

        template<> void MIXED_ENCODING::Time_HMFSn_LD_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Time_HMFSn_LD_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_value_, 1, CONTEXT_CLASS);
        }

        // sequence date-time

        template<> void MIXED_ENCODING::Date_time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Date_time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-SE-Date

        template<> void MIXED_ENCODING::Iterval_SE_Date_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-SE-Time

        template<> void MIXED_ENCODING::Iterval_SE_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-SE-Date-Time

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        // sequence start

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence end

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-SD-Date

        template<> void MIXED_ENCODING::Iterval_SD_Date_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Date_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-SD-Time

        template<> void MIXED_ENCODING::Iterval_SD_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-SD-Date-Time

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(start_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
        }

        // sequence start

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-DE-Date

        template<> void MIXED_ENCODING::Iterval_DE_Date_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(duration_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Date_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(duration_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-DE-Time

        template<> void MIXED_ENCODING::Iterval_DE_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(duration_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(duration_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        // sequence iterval-DE-Date-Time

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(duration_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(duration_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 1, CONTEXT_CLASS);
        }

        // sequence end

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence rec-Interval-SE-Date

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 2, CONTEXT_CLASS);
        }

        // sequence rec-Interval-SE-Time

        template<> void MIXED_ENCODING::Rec_Interval_SE_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        // sequence rec-Interval-SE-Date-Time

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        // sequence start

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence end

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence rec-Interval-SD-Date

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
        }

        // sequence rec-Interval-SD-Time

        template<> void MIXED_ENCODING::Rec_Interval_SD_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
        }

        // sequence rec-Interval-SD-Date-Time

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(start_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 2, CONTEXT_CLASS);
        }

        // sequence start

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // sequence rec-Interval-DE-Date

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(end_, 2, CONTEXT_CLASS);
        }

        // sequence rec-Interval-DE-Time

        template<> void MIXED_ENCODING::Rec_Interval_DE_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        // sequence rec-Interval-DE-Date-Time

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(recurrence_, 0, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(duration_, 1, CONTEXT_CLASS);
            ITU_T_BIND_IMPLICIT(end_, 2, CONTEXT_CLASS);
        }

        // sequence end

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_CHOICE_TAG(date_, 0, CONTEXT_CLASS);
            ITU_T_BIND_EXPLICIT(time_, 1, CONTEXT_CLASS);
        }

        // choice DATE-TYPE

        template<> void DATE_TYPE::serialize(boost::asn1::x690::output_coder& arch) {
            switch (type()) {
                case DATE_TYPE_dt_C_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<CENTURY_ENCODING > (false, DATE_TYPE_dt_C_Basic), 0, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_C_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_CENTURY_ENCODING > (false, DATE_TYPE_dt_C_L), 1, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_Y_Basic:
                {
                    ITU_T_BIND_CHOICE_TAG(value<YEAR_ENCODING > (false, DATE_TYPE_dt_Y_Basic), 2, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_Y_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_ENCODING > (false, DATE_TYPE_dt_Y_L), 3, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YM_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_MONTH_ENCODING > (false, DATE_TYPE_dt_YM_Basic), 4, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YM_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_MONTH_ENCODING > (false, DATE_TYPE_dt_YM_L), 5, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YMD_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<DATE_ENCODING > (false, DATE_TYPE_dt_YMD_Basic), 6, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YMD_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_DATE_ENCODING > (false, DATE_TYPE_dt_YMD_L), 7, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YD_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_DAY_ENCODING > (false, DATE_TYPE_dt_YD_Basic), 8, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YD_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_DAY_ENCODING > (false, DATE_TYPE_dt_YD_L), 9, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YW_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_ENCODING > (false, DATE_TYPE_dt_YW_Basic), 10, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YW_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_ENCODING > (false, DATE_TYPE_dt_YW_L), 11, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YWD_Basic:
                {
                    ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_DAY_ENCODING > (false, DATE_TYPE_dt_YWD_Basic), 12, CONTEXT_CLASS);
                    break;
                }
                case DATE_TYPE_dt_YWD_L:
                {
                    ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_DAY_ENCODING > (false, DATE_TYPE_dt_YWD_L), 13, CONTEXT_CLASS);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void DATE_TYPE::serialize(boost::asn1::x690::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            switch (arch.test_class()) {
                case 0x80:
                {
                    switch (__tag_id__) {
                        case 0:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<CENTURY_ENCODING > (true, DATE_TYPE_dt_C_Basic), 0, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 1:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_CENTURY_ENCODING > (true, DATE_TYPE_dt_C_L), 1, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_BIND_CHOICE_TAG(value<YEAR_ENCODING > (true, DATE_TYPE_dt_Y_Basic), 2, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 3:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_ENCODING > (true, DATE_TYPE_dt_Y_L), 3, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 4:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_MONTH_ENCODING > (true, DATE_TYPE_dt_YM_Basic), 4, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 5:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_MONTH_ENCODING > (true, DATE_TYPE_dt_YM_L), 5, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 6:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<DATE_ENCODING > (true, DATE_TYPE_dt_YMD_Basic), 6, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 7:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_DATE_ENCODING > (true, DATE_TYPE_dt_YMD_L), 7, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 8:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_DAY_ENCODING > (true, DATE_TYPE_dt_YD_Basic), 8, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 9:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_DAY_ENCODING > (true, DATE_TYPE_dt_YD_L), 9, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 10:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_ENCODING > (true, DATE_TYPE_dt_YW_Basic), 10, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 11:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_ENCODING > (true, DATE_TYPE_dt_YW_L), 11, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 12:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<YEAR_WEEK_DAY_ENCODING > (true, DATE_TYPE_dt_YWD_Basic), 12, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 13:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<ANY_YEAR_WEEK_DAY_ENCODING > (true, DATE_TYPE_dt_YWD_L), 13, CONTEXT_CLASS)) return;
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

        // sequence TIME-TYPE

        template<> void TIME_TYPE::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(time_type_, 1, CONTEXT_CLASS);
        }

        template<> void TIME_TYPE::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_IMPLICIT(number_of_digits_, 0, CONTEXT_CLASS);
            ITU_T_BIND_CHOICE_TAG(time_type_, 1, CONTEXT_CLASS);
        }

        // choice time-type

        template<> void TIME_TYPE::Time_type_type::serialize(boost::asn1::x690::output_coder& arch) {
            switch (type()) {
                case Time_type_type_tm_H_L:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_ENCODING > (false, Time_type_type_tm_H_L), 0, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_H_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_UTC_ENCODING > (false, Time_type_type_tm_H_Z), 1, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_H_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_AND_DIFF_ENCODING > (false, Time_type_type_tm_H_LD), 2, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HM_L:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_ENCODING > (false, Time_type_type_tm_HM_L), 3, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HM_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_UTC_ENCODING > (false, Time_type_type_tm_HM_Z), 4, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HM_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_AND_DIFF_ENCODING > (false, Time_type_type_tm_HM_LD), 5, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMS_L:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_ENCODING > (false, Time_type_type_tm_HMS_L), 6, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMS_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_UTC_ENCODING > (false, Time_type_type_tm_HMS_Z), 7, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMS_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_DIFF_ENCODING > (false, Time_type_type_tm_HMS_LD), 8, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HFn_L:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HFn_L), 9, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HFn_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_UTC_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HFn_Z), 10, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HFn_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<HOURS_AND_DIFF_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HFn_LD), 11, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMFn_L:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFn_L), 12, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMFn_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_UTC_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFn_Z), 13, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMFn_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<MINUTES_AND_DIFF_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFn_LD), 14, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMFSn_L:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFSn_L), 15, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMFSn_Z:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_UTC_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFSn_Z), 16, CONTEXT_CLASS);
                    break;
                }
                case Time_type_type_tm_HMFSn_LD:
                {
                    ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFSn_LD), 17, CONTEXT_CLASS);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void TIME_TYPE::Time_type_type::serialize(boost::asn1::x690::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            switch (arch.test_class()) {
                case 0x80:
                {
                    switch (__tag_id__) {
                        case 0:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_ENCODING > (true, Time_type_type_tm_H_L), 0, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 1:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_UTC_ENCODING > (true, Time_type_type_tm_H_Z), 1, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_AND_DIFF_ENCODING > (true, Time_type_type_tm_H_LD), 2, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 3:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_ENCODING > (true, Time_type_type_tm_HM_L), 3, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 4:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_UTC_ENCODING > (true, Time_type_type_tm_HM_Z), 4, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 5:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_AND_DIFF_ENCODING > (true, Time_type_type_tm_HM_LD), 5, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 6:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_ENCODING > (true, Time_type_type_tm_HMS_L), 6, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 7:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_UTC_ENCODING > (true, Time_type_type_tm_HMS_Z), 7, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 8:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_DIFF_ENCODING > (true, Time_type_type_tm_HMS_LD), 8, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 9:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HFn_L), 9, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 10:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_UTC_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HFn_Z), 10, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 11:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<HOURS_AND_DIFF_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HFn_LD), 11, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 12:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFn_L), 12, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 13:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_UTC_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFn_Z), 13, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 14:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<MINUTES_AND_DIFF_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFn_LD), 14, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 15:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFSn_L), 15, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 16:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_UTC_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFSn_Z), 16, CONTEXT_CLASS)) return;
                            else free();
                            break;
                        }
                        case 17:
                        {
                            if (ITU_T_BIND_IMPLICIT(value<TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFSn_LD), 17, CONTEXT_CLASS)) return;
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
}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

