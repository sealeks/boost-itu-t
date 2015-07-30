#include "DefinedTime.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif

namespace boost {
    namespace asn1 {






        //  helper name:   TIME_DIFFERENCE__enumerated           type:  enumerated helper    
        ITU_T_PER_ENUMCODER(TIME_DIFFERENCE__enumerated__helper, false, ITU_T_ARRAY(0, 1));

        // sequence CENTURY-ENCODING

        template<> void CENTURY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(as_number_, static_cast<uint8_t> (0), static_cast<uint8_t> (99));
        }

        template<> void CENTURY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(as_number_, static_cast<uint8_t> (0), static_cast<uint8_t> (99));
        }

        // sequence ANY-CENTURY-ENCODING

        template<> void ANY_CENTURY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(as_number_);
        }

        template<> void ANY_CENTURY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(as_number_);
        }

        // choice YEAR-ENCODING

        template<> void YEAR_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case YEAR_ENCODING_immediate:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 3);
                    ITU_T_BIND_NUM_CONSTRAINT(value<uint16_t > (false, YEAR_ENCODING_immediate), static_cast<uint16_t> (2005), static_cast<uint16_t> (2020));
                    break;
                }
                case YEAR_ENCODING_near_future:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 3);
                    ITU_T_BIND_NUM_CONSTRAINT(value<uint16_t > (false, YEAR_ENCODING_near_future), static_cast<uint16_t> (2021), static_cast<uint16_t> (2276));
                    break;
                }
                case YEAR_ENCODING_near_past:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 3);
                    ITU_T_BIND_NUM_CONSTRAINT(value<uint16_t > (false, YEAR_ENCODING_near_past), static_cast<uint16_t> (1749), static_cast<uint16_t> (2004));
                    break;
                }
                case YEAR_ENCODING_remainder:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 3);
                    ITU_T_BIND_PER(value<integer_type > (false, YEAR_ENCODING_remainder));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void YEAR_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(3);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_NUM_CONSTRAINT(value<uint16_t > (true, YEAR_ENCODING_immediate), static_cast<uint16_t> (2005), static_cast<uint16_t> (2020));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_NUM_CONSTRAINT(value<uint16_t > (true, YEAR_ENCODING_near_future), static_cast<uint16_t> (2021), static_cast<uint16_t> (2276));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_NUM_CONSTRAINT(value<uint16_t > (true, YEAR_ENCODING_near_past), static_cast<uint16_t> (1749), static_cast<uint16_t> (2004));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<integer_type > (true, YEAR_ENCODING_remainder));
                    break;
                }
                default:
                {
                }
            }
        }

        // sequence ANY-YEAR-ENCODING

        template<> void ANY_YEAR_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(as_number_);
        }

        template<> void ANY_YEAR_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(as_number_);
        }

        // sequence YEAR-MONTH-ENCODING

        template<> void YEAR_MONTH_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
        }

        template<> void YEAR_MONTH_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
        }

        // sequence ANY-YEAR-MONTH-ENCODING

        template<> void ANY_YEAR_MONTH_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
        }

        template<> void ANY_YEAR_MONTH_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
        }

        // sequence DATE-ENCODING

        template<> void DATE_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
        }

        template<> void DATE_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
        }

        // sequence ANY-DATE-ENCODING

        template<> void ANY_DATE_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
        }

        template<> void ANY_DATE_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
        }

        // sequence YEAR-DAY-ENCODING

        template<> void YEAR_DAY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint16_t> (1), static_cast<uint16_t> (366));
        }

        template<> void YEAR_DAY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint16_t> (1), static_cast<uint16_t> (366));
        }

        // sequence ANY-YEAR-DAY-ENCODING

        template<> void ANY_YEAR_DAY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint16_t> (1), static_cast<uint16_t> (366));
        }

        template<> void ANY_YEAR_DAY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint16_t> (1), static_cast<uint16_t> (366));
        }

        // sequence YEAR-WEEK-ENCODING

        template<> void YEAR_WEEK_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
        }

        template<> void YEAR_WEEK_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
        }

        // sequence ANY-YEAR-WEEK-ENCODING

        template<> void ANY_YEAR_WEEK_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
        }

        template<> void ANY_YEAR_WEEK_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
        }

        // sequence YEAR-WEEK-DAY-ENCODING

        template<> void YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (7));
        }

        template<> void YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (7));
        }

        // sequence ANY-YEAR-WEEK-DAY-ENCODING

        template<> void ANY_YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (7));
        }

        template<> void ANY_YEAR_WEEK_DAY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (7));
        }

        // sequence HOURS-ENCODING

        template<> void HOURS_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(as_number_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
        }

        template<> void HOURS_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(as_number_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
        }

        // sequence HOURS-UTC-ENCODING

        template<> void HOURS_UTC_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(as_number_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
        }

        template<> void HOURS_UTC_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(as_number_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
        }

        // sequence HOURS-AND-DIFF-ENCODING

        template<> void HOURS_AND_DIFF_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(local_hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_PER(time_difference_);
        }

        template<> void HOURS_AND_DIFF_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(local_hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_PER(time_difference_);
        }

        // sequence TIME-DIFFERENCE

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(minutes_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER_ENUM(sign_, TIME_DIFFERENCE__enumerated__helper);
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (1), static_cast<uint8_t> (59));
        }

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_BIND_PER_ENUM(sign_, TIME_DIFFERENCE__enumerated__helper);
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (1), static_cast<uint8_t> (59));
        }

        // sequence MINUTES-ENCODING

        template<> void MINUTES_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
        }

        template<> void MINUTES_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
        }

        // sequence MINUTES-UTC-ENCODING

        template<> void MINUTES_UTC_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
        }

        template<> void MINUTES_UTC_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
        }

        // sequence MINUTES-AND-DIFF-ENCODING

        template<> void MINUTES_AND_DIFF_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        template<> void MINUTES_AND_DIFF_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }



        // sequence TIME-OF-DAY-ENCODING

        template<> void TIME_OF_DAY_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        template<> void TIME_OF_DAY_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        // sequence TIME-OF-DAY-UTC-ENCODING

        template<> void TIME_OF_DAY_UTC_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        template<> void TIME_OF_DAY_UTC_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        // sequence TIME-OF-DAY-AND-DIFF-ENCODING

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        // sequence local-time

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        template<> void TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        // sequence HOURS-AND-FRACTION-ENCODING

        template<> void HOURS_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void HOURS_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence HOURS-UTC-AND-FRACTION-ENCODING

        template<> void HOURS_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void HOURS_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence HOURS-AND-DIFF-AND-FRACTION-ENCODING

        template<> void HOURS_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(local_hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            ITU_T_BIND_PER(time_difference_);
        }

        template<> void HOURS_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(local_hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            ITU_T_BIND_PER(time_difference_);
        }

        // sequence MINUTES-AND-FRACTION-ENCODING

        template<> void MINUTES_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void MINUTES_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence MINUTES-UTC-AND-FRACTION-ENCODING

        template<> void MINUTES_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void MINUTES_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence MINUTES-AND-DIFF-AND-FRACTION-ENCODING

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        // sequence local-time

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence TIME-OF-DAY-AND-FRACTION-ENCODING

        template<> void TIME_OF_DAY_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void TIME_OF_DAY_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence TIME-OF-DAY-UTC-AND-FRACTION-ENCODING

        template<> void TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(local_time_);
            ITU_T_BIND_PER(time_difference_);
        }

        // sequence local-time

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        template<> void TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
        }

        // sequence DURATION-INTERVAL-ENCODING

        template<> void DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(years_) +
                    ITU_T_EXISTS_BMP(months_) +
                    ITU_T_EXISTS_BMP(weeks_) +
                    ITU_T_EXISTS_BMP(days_) +
                    ITU_T_EXISTS_BMP(hours_) +
                    ITU_T_EXISTS_BMP(minutes_) +
                    ITU_T_EXISTS_BMP(seconds_) +
                    ITU_T_EXISTS_BMP(fractional_part_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_NUM_CONSTRAINT_EXT(years_, static_cast<integer_type> (0), static_cast<integer_type> (31));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(months_, static_cast<integer_type> (0), static_cast<integer_type> (15));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(weeks_, static_cast<integer_type> (0), static_cast<integer_type> (63));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(days_, static_cast<integer_type> (0), static_cast<integer_type> (31));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(hours_, static_cast<integer_type> (0), static_cast<integer_type> (31));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(minutes_, static_cast<integer_type> (0), static_cast<integer_type> (63));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(seconds_, static_cast<integer_type> (0), static_cast<integer_type> (63));
            ITU_T_BIND_PER(fractional_part_);
        }

        template<> void DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(8);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRAINT_EXT(years_, static_cast<integer_type> (0), static_cast<integer_type> (31));
            ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_NUM_CONSTRAINT_EXT(months_, static_cast<integer_type> (0), static_cast<integer_type> (15));
            ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_NUM_CONSTRAINT_EXT(weeks_, static_cast<integer_type> (0), static_cast<integer_type> (63));
            ITU_T_OPTIONAL_CHECK(3) ITU_T_BIND_NUM_CONSTRAINT_EXT(days_, static_cast<integer_type> (0), static_cast<integer_type> (31));
            ITU_T_OPTIONAL_CHECK(4) ITU_T_BIND_NUM_CONSTRAINT_EXT(hours_, static_cast<integer_type> (0), static_cast<integer_type> (31));
            ITU_T_OPTIONAL_CHECK(5) ITU_T_BIND_NUM_CONSTRAINT_EXT(minutes_, static_cast<integer_type> (0), static_cast<integer_type> (63));
            ITU_T_OPTIONAL_CHECK(6) ITU_T_BIND_NUM_CONSTRAINT_EXT(seconds_, static_cast<integer_type> (0), static_cast<integer_type> (63));
            ITU_T_OPTIONAL_CHECK(7) ITU_T_BIND_PER(fractional_part_);
        }

        // sequence fractional-part

        template<> void DURATION_INTERVAL_ENCODING::Fractional_part_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT_EXT(number_of_digits_, static_cast<integer_type> (1), static_cast<integer_type> (3));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fractional_value_, static_cast<integer_type> (1), static_cast<integer_type> (999));
        }

        template<> void DURATION_INTERVAL_ENCODING::Fractional_part_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT_EXT(number_of_digits_, static_cast<integer_type> (1), static_cast<integer_type> (3));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fractional_value_, static_cast<integer_type> (1), static_cast<integer_type> (999));
        }

        // sequence REC-DURATION-INTERVAL-ENCODING

        template<> void REC_DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void REC_DURATION_INTERVAL_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
        }

        // choice MIXED-ENCODING

        template<> void MIXED_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case MIXED_ENCODING_date_C_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 52);
                    ITU_T_BIND_PER(value<CENTURY_ENCODING > (false, MIXED_ENCODING_date_C_Basic));
                    break;
                }
                case MIXED_ENCODING_date_C_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 52);
                    ITU_T_BIND_PER(value<ANY_CENTURY_ENCODING > (false, MIXED_ENCODING_date_C_L));
                    break;
                }
                case MIXED_ENCODING_date_Y_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 52);
                    ITU_T_BIND_PER(value<YEAR_ENCODING > (false, MIXED_ENCODING_date_Y_Basic));
                    break;
                }
                case MIXED_ENCODING_date_Y_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 52);
                    ITU_T_BIND_PER(value<ANY_YEAR_ENCODING > (false, MIXED_ENCODING_date_Y_L));
                    break;
                }
                case MIXED_ENCODING_date_YM_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 52);
                    ITU_T_BIND_PER(value<YEAR_MONTH_ENCODING > (false, MIXED_ENCODING_date_YM_Basic));
                    break;
                }
                case MIXED_ENCODING_date_YM_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 52);
                    ITU_T_BIND_PER(value<ANY_YEAR_MONTH_ENCODING > (false, MIXED_ENCODING_date_YM_L));
                    break;
                }
                case MIXED_ENCODING_date_YMD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 52);
                    ITU_T_BIND_PER(value<DATE_ENCODING > (false, MIXED_ENCODING_date_YMD_Basic));
                    break;
                }
                case MIXED_ENCODING_date_YMD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 52);
                    ITU_T_BIND_PER(value<ANY_DATE_ENCODING > (false, MIXED_ENCODING_date_YMD_L));
                    break;
                }
                case MIXED_ENCODING_date_YD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 52);
                    ITU_T_BIND_PER(value<YEAR_DAY_ENCODING > (false, MIXED_ENCODING_date_YD_Basic));
                    break;
                }
                case MIXED_ENCODING_date_YD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 52);
                    ITU_T_BIND_PER(value<ANY_YEAR_DAY_ENCODING > (false, MIXED_ENCODING_date_YD_L));
                    break;
                }
                case MIXED_ENCODING_date_YW_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 52);
                    ITU_T_BIND_PER(value<YEAR_WEEK_ENCODING > (false, MIXED_ENCODING_date_YW_Basic));
                    break;
                }
                case MIXED_ENCODING_date_YW_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 52);
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_ENCODING > (false, MIXED_ENCODING_date_YW_L));
                    break;
                }
                case MIXED_ENCODING_date_YWD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 52);
                    ITU_T_BIND_PER(value<YEAR_WEEK_DAY_ENCODING > (false, MIXED_ENCODING_date_YWD_Basic));
                    break;
                }
                case MIXED_ENCODING_date_YWD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 52);
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_DAY_ENCODING > (false, MIXED_ENCODING_date_YWD_L));
                    break;
                }
                case MIXED_ENCODING_time_H_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(14, 52);
                    ITU_T_BIND_PER(value<HOURS_ENCODING > (false, MIXED_ENCODING_time_H_L));
                    break;
                }
                case MIXED_ENCODING_time_H_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(15, 52);
                    ITU_T_BIND_PER(value<HOURS_UTC_ENCODING > (false, MIXED_ENCODING_time_H_Z));
                    break;
                }
                case MIXED_ENCODING_time_H_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(16, 52);
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_ENCODING > (false, MIXED_ENCODING_time_H_LD));
                    break;
                }
                case MIXED_ENCODING_time_HM_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(17, 52);
                    ITU_T_BIND_PER(value<MINUTES_ENCODING > (false, MIXED_ENCODING_time_HM_L));
                    break;
                }
                case MIXED_ENCODING_time_HM_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(18, 52);
                    ITU_T_BIND_PER(value<MINUTES_UTC_ENCODING > (false, MIXED_ENCODING_time_HM_Z));
                    break;
                }
                case MIXED_ENCODING_time_HM_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(19, 52);
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_ENCODING > (false, MIXED_ENCODING_time_HM_LD));
                    break;
                }
                case MIXED_ENCODING_time_HMS_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(20, 52);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_ENCODING > (false, MIXED_ENCODING_time_HMS_L));
                    break;
                }
                case MIXED_ENCODING_time_HMS_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(21, 52);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_ENCODING > (false, MIXED_ENCODING_time_HMS_Z));
                    break;
                }
                case MIXED_ENCODING_time_HMS_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(22, 52);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_ENCODING > (false, MIXED_ENCODING_time_HMS_LD));
                    break;
                }
                case MIXED_ENCODING_time_HFn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(23, 52);
                    ITU_T_BIND_PER(value<Time_HFn_L_type > (false, MIXED_ENCODING_time_HFn_L));
                    break;
                }
                case MIXED_ENCODING_time_HFn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(24, 52);
                    ITU_T_BIND_PER(value<Time_HFn_Z_type > (false, MIXED_ENCODING_time_HFn_Z));
                    break;
                }
                case MIXED_ENCODING_time_HFn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(25, 52);
                    ITU_T_BIND_PER(value<Time_HFn_LD_type > (false, MIXED_ENCODING_time_HFn_LD));
                    break;
                }
                case MIXED_ENCODING_time_HMFn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(26, 52);
                    ITU_T_BIND_PER(value<Time_HMFn_L_type > (false, MIXED_ENCODING_time_HMFn_L));
                    break;
                }
                case MIXED_ENCODING_time_HMFn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(27, 52);
                    ITU_T_BIND_PER(value<Time_HMFn_Z_type > (false, MIXED_ENCODING_time_HMFn_Z));
                    break;
                }
                case MIXED_ENCODING_time_HMFn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(28, 52);
                    ITU_T_BIND_PER(value<Time_HMFn_LD_type > (false, MIXED_ENCODING_time_HMFn_LD));
                    break;
                }
                case MIXED_ENCODING_time_HMFSn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(29, 52);
                    ITU_T_BIND_PER(value<Time_HMFSn_L_type > (false, MIXED_ENCODING_time_HMFSn_L));
                    break;
                }
                case MIXED_ENCODING_time_HMFSn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(30, 52);
                    ITU_T_BIND_PER(value<Time_HMFSn_Z_type > (false, MIXED_ENCODING_time_HMFSn_Z));
                    break;
                }
                case MIXED_ENCODING_time_HMFSn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(31, 52);
                    ITU_T_BIND_PER(value<Time_HMFSn_LD_type > (false, MIXED_ENCODING_time_HMFSn_LD));
                    break;
                }
                case MIXED_ENCODING_date_time:
                {
                    ITU_T_SET_CONSTAINED_INDX(32, 52);
                    ITU_T_BIND_PER(value<Date_time_type > (false, MIXED_ENCODING_date_time));
                    break;
                }
                case MIXED_ENCODING_iterval_SE_Date:
                {
                    ITU_T_SET_CONSTAINED_INDX(33, 52);
                    ITU_T_BIND_PER(value<Iterval_SE_Date_type > (false, MIXED_ENCODING_iterval_SE_Date));
                    break;
                }
                case MIXED_ENCODING_iterval_SE_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(34, 52);
                    ITU_T_BIND_PER(value<Iterval_SE_Time_type > (false, MIXED_ENCODING_iterval_SE_Time));
                    break;
                }
                case MIXED_ENCODING_iterval_SE_Date_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(35, 52);
                    ITU_T_BIND_PER(value<Iterval_SE_Date_Time_type > (false, MIXED_ENCODING_iterval_SE_Date_Time));
                    break;
                }
                case MIXED_ENCODING_iterval_D:
                {
                    ITU_T_SET_CONSTAINED_INDX(36, 52);
                    ITU_T_BIND_PER(value<DURATION_INTERVAL_ENCODING > (false, MIXED_ENCODING_iterval_D));
                    break;
                }
                case MIXED_ENCODING_iterval_SD_Date:
                {
                    ITU_T_SET_CONSTAINED_INDX(37, 52);
                    ITU_T_BIND_PER(value<Iterval_SD_Date_type > (false, MIXED_ENCODING_iterval_SD_Date));
                    break;
                }
                case MIXED_ENCODING_iterval_SD_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(38, 52);
                    ITU_T_BIND_PER(value<Iterval_SD_Time_type > (false, MIXED_ENCODING_iterval_SD_Time));
                    break;
                }
                case MIXED_ENCODING_iterval_SD_Date_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(39, 52);
                    ITU_T_BIND_PER(value<Iterval_SD_Date_Time_type > (false, MIXED_ENCODING_iterval_SD_Date_Time));
                    break;
                }
                case MIXED_ENCODING_iterval_DE_Date:
                {
                    ITU_T_SET_CONSTAINED_INDX(40, 52);
                    ITU_T_BIND_PER(value<Iterval_DE_Date_type > (false, MIXED_ENCODING_iterval_DE_Date));
                    break;
                }
                case MIXED_ENCODING_iterval_DE_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(41, 52);
                    ITU_T_BIND_PER(value<Iterval_DE_Time_type > (false, MIXED_ENCODING_iterval_DE_Time));
                    break;
                }
                case MIXED_ENCODING_iterval_DE_Date_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(42, 52);
                    ITU_T_BIND_PER(value<Iterval_DE_Date_Time_type > (false, MIXED_ENCODING_iterval_DE_Date_Time));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SE_Date:
                {
                    ITU_T_SET_CONSTAINED_INDX(43, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_SE_Date_type > (false, MIXED_ENCODING_rec_Interval_SE_Date));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SE_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(44, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_SE_Time_type > (false, MIXED_ENCODING_rec_Interval_SE_Time));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SE_Date_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(45, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_SE_Date_Time_type > (false, MIXED_ENCODING_rec_Interval_SE_Date_Time));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_D:
                {
                    ITU_T_SET_CONSTAINED_INDX(46, 52);
                    ITU_T_BIND_PER(value<REC_DURATION_INTERVAL_ENCODING > (false, MIXED_ENCODING_rec_Interval_D));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SD_Date:
                {
                    ITU_T_SET_CONSTAINED_INDX(47, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_SD_Date_type > (false, MIXED_ENCODING_rec_Interval_SD_Date));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SD_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(48, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_SD_Time_type > (false, MIXED_ENCODING_rec_Interval_SD_Time));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_SD_Date_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(49, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_SD_Date_Time_type > (false, MIXED_ENCODING_rec_Interval_SD_Date_Time));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_DE_Date:
                {
                    ITU_T_SET_CONSTAINED_INDX(50, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_DE_Date_type > (false, MIXED_ENCODING_rec_Interval_DE_Date));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_DE_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(51, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_DE_Time_type > (false, MIXED_ENCODING_rec_Interval_DE_Time));
                    break;
                }
                case MIXED_ENCODING_rec_Interval_DE_Date_Time:
                {
                    ITU_T_SET_CONSTAINED_INDX(52, 52);
                    ITU_T_BIND_PER(value<Rec_Interval_DE_Date_Time_type > (false, MIXED_ENCODING_rec_Interval_DE_Date_Time));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void MIXED_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(52);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<CENTURY_ENCODING > (true, MIXED_ENCODING_date_C_Basic));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<ANY_CENTURY_ENCODING > (true, MIXED_ENCODING_date_C_L));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<YEAR_ENCODING > (true, MIXED_ENCODING_date_Y_Basic));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_ENCODING > (true, MIXED_ENCODING_date_Y_L));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<YEAR_MONTH_ENCODING > (true, MIXED_ENCODING_date_YM_Basic));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_MONTH_ENCODING > (true, MIXED_ENCODING_date_YM_L));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(value<DATE_ENCODING > (true, MIXED_ENCODING_date_YMD_Basic));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(value<ANY_DATE_ENCODING > (true, MIXED_ENCODING_date_YMD_L));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(value<YEAR_DAY_ENCODING > (true, MIXED_ENCODING_date_YD_Basic));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_DAY_ENCODING > (true, MIXED_ENCODING_date_YD_L));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(value<YEAR_WEEK_ENCODING > (true, MIXED_ENCODING_date_YW_Basic));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_ENCODING > (true, MIXED_ENCODING_date_YW_L));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(value<YEAR_WEEK_DAY_ENCODING > (true, MIXED_ENCODING_date_YWD_Basic));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_DAY_ENCODING > (true, MIXED_ENCODING_date_YWD_L));
                    break;
                }
                case 14:
                {
                    ITU_T_BIND_PER(value<HOURS_ENCODING > (true, MIXED_ENCODING_time_H_L));
                    break;
                }
                case 15:
                {
                    ITU_T_BIND_PER(value<HOURS_UTC_ENCODING > (true, MIXED_ENCODING_time_H_Z));
                    break;
                }
                case 16:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_ENCODING > (true, MIXED_ENCODING_time_H_LD));
                    break;
                }
                case 17:
                {
                    ITU_T_BIND_PER(value<MINUTES_ENCODING > (true, MIXED_ENCODING_time_HM_L));
                    break;
                }
                case 18:
                {
                    ITU_T_BIND_PER(value<MINUTES_UTC_ENCODING > (true, MIXED_ENCODING_time_HM_Z));
                    break;
                }
                case 19:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_ENCODING > (true, MIXED_ENCODING_time_HM_LD));
                    break;
                }
                case 20:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_ENCODING > (true, MIXED_ENCODING_time_HMS_L));
                    break;
                }
                case 21:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_ENCODING > (true, MIXED_ENCODING_time_HMS_Z));
                    break;
                }
                case 22:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_ENCODING > (true, MIXED_ENCODING_time_HMS_LD));
                    break;
                }
                case 23:
                {
                    ITU_T_BIND_PER(value<Time_HFn_L_type > (true, MIXED_ENCODING_time_HFn_L));
                    break;
                }
                case 24:
                {
                    ITU_T_BIND_PER(value<Time_HFn_Z_type > (true, MIXED_ENCODING_time_HFn_Z));
                    break;
                }
                case 25:
                {
                    ITU_T_BIND_PER(value<Time_HFn_LD_type > (true, MIXED_ENCODING_time_HFn_LD));
                    break;
                }
                case 26:
                {
                    ITU_T_BIND_PER(value<Time_HMFn_L_type > (true, MIXED_ENCODING_time_HMFn_L));
                    break;
                }
                case 27:
                {
                    ITU_T_BIND_PER(value<Time_HMFn_Z_type > (true, MIXED_ENCODING_time_HMFn_Z));
                    break;
                }
                case 28:
                {
                    ITU_T_BIND_PER(value<Time_HMFn_LD_type > (true, MIXED_ENCODING_time_HMFn_LD));
                    break;
                }
                case 29:
                {
                    ITU_T_BIND_PER(value<Time_HMFSn_L_type > (true, MIXED_ENCODING_time_HMFSn_L));
                    break;
                }
                case 30:
                {
                    ITU_T_BIND_PER(value<Time_HMFSn_Z_type > (true, MIXED_ENCODING_time_HMFSn_Z));
                    break;
                }
                case 31:
                {
                    ITU_T_BIND_PER(value<Time_HMFSn_LD_type > (true, MIXED_ENCODING_time_HMFSn_LD));
                    break;
                }
                case 32:
                {
                    ITU_T_BIND_PER(value<Date_time_type > (true, MIXED_ENCODING_date_time));
                    break;
                }
                case 33:
                {
                    ITU_T_BIND_PER(value<Iterval_SE_Date_type > (true, MIXED_ENCODING_iterval_SE_Date));
                    break;
                }
                case 34:
                {
                    ITU_T_BIND_PER(value<Iterval_SE_Time_type > (true, MIXED_ENCODING_iterval_SE_Time));
                    break;
                }
                case 35:
                {
                    ITU_T_BIND_PER(value<Iterval_SE_Date_Time_type > (true, MIXED_ENCODING_iterval_SE_Date_Time));
                    break;
                }
                case 36:
                {
                    ITU_T_BIND_PER(value<DURATION_INTERVAL_ENCODING > (true, MIXED_ENCODING_iterval_D));
                    break;
                }
                case 37:
                {
                    ITU_T_BIND_PER(value<Iterval_SD_Date_type > (true, MIXED_ENCODING_iterval_SD_Date));
                    break;
                }
                case 38:
                {
                    ITU_T_BIND_PER(value<Iterval_SD_Time_type > (true, MIXED_ENCODING_iterval_SD_Time));
                    break;
                }
                case 39:
                {
                    ITU_T_BIND_PER(value<Iterval_SD_Date_Time_type > (true, MIXED_ENCODING_iterval_SD_Date_Time));
                    break;
                }
                case 40:
                {
                    ITU_T_BIND_PER(value<Iterval_DE_Date_type > (true, MIXED_ENCODING_iterval_DE_Date));
                    break;
                }
                case 41:
                {
                    ITU_T_BIND_PER(value<Iterval_DE_Time_type > (true, MIXED_ENCODING_iterval_DE_Time));
                    break;
                }
                case 42:
                {
                    ITU_T_BIND_PER(value<Iterval_DE_Date_Time_type > (true, MIXED_ENCODING_iterval_DE_Date_Time));
                    break;
                }
                case 43:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_SE_Date_type > (true, MIXED_ENCODING_rec_Interval_SE_Date));
                    break;
                }
                case 44:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_SE_Time_type > (true, MIXED_ENCODING_rec_Interval_SE_Time));
                    break;
                }
                case 45:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_SE_Date_Time_type > (true, MIXED_ENCODING_rec_Interval_SE_Date_Time));
                    break;
                }
                case 46:
                {
                    ITU_T_BIND_PER(value<REC_DURATION_INTERVAL_ENCODING > (true, MIXED_ENCODING_rec_Interval_D));
                    break;
                }
                case 47:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_SD_Date_type > (true, MIXED_ENCODING_rec_Interval_SD_Date));
                    break;
                }
                case 48:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_SD_Time_type > (true, MIXED_ENCODING_rec_Interval_SD_Time));
                    break;
                }
                case 49:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_SD_Date_Time_type > (true, MIXED_ENCODING_rec_Interval_SD_Date_Time));
                    break;
                }
                case 50:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_DE_Date_type > (true, MIXED_ENCODING_rec_Interval_DE_Date));
                    break;
                }
                case 51:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_DE_Time_type > (true, MIXED_ENCODING_rec_Interval_DE_Time));
                    break;
                }
                case 52:
                {
                    ITU_T_BIND_PER(value<Rec_Interval_DE_Date_Time_type > (true, MIXED_ENCODING_rec_Interval_DE_Date_Time));
                    break;
                }
                default:
                {
                }
            }
        }

        // sequence time-HFn-L

        template<> void MIXED_ENCODING::Time_HFn_L_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HFn_L_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HFn-Z

        template<> void MIXED_ENCODING::Time_HFn_Z_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HFn_Z_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HFn-LD

        template<> void MIXED_ENCODING::Time_HFn_LD_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HFn_LD_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HMFn-L

        template<> void MIXED_ENCODING::Time_HMFn_L_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HMFn_L_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HMFn-Z

        template<> void MIXED_ENCODING::Time_HMFn_Z_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HMFn_Z_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HMFn-LD

        template<> void MIXED_ENCODING::Time_HMFn_LD_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HMFn_LD_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HMFSn-L

        template<> void MIXED_ENCODING::Time_HMFSn_L_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HMFSn_L_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HMFSn-Z

        template<> void MIXED_ENCODING::Time_HMFSn_Z_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HMFSn_Z_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence time-HMFSn-LD

        template<> void MIXED_ENCODING::Time_HMFSn_LD_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        template<> void MIXED_ENCODING::Time_HMFSn_LD_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_value_);
        }

        // sequence date-time

        template<> void MIXED_ENCODING::Date_time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Date_time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence iterval-SE-Date

        template<> void MIXED_ENCODING::Iterval_SE_Date_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        // sequence iterval-SE-Time

        template<> void MIXED_ENCODING::Iterval_SE_Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        // sequence iterval-SE-Date-Time

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        // sequence start

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence end

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence iterval-SD-Date

        template<> void MIXED_ENCODING::Iterval_SD_Date_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Date_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        // sequence iterval-SD-Time

        template<> void MIXED_ENCODING::Iterval_SD_Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        // sequence iterval-SD-Date-Time

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        // sequence start

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence iterval-DE-Date

        template<> void MIXED_ENCODING::Iterval_DE_Date_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Date_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        // sequence iterval-DE-Time

        template<> void MIXED_ENCODING::Iterval_DE_Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        // sequence iterval-DE-Date-Time

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        // sequence end

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence rec-Interval-SE-Date

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        // sequence rec-Interval-SE-Time

        template<> void MIXED_ENCODING::Rec_Interval_SE_Time_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        // sequence rec-Interval-SE-Date-Time

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(end_);
        }

        // sequence start

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence end

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence rec-Interval-SD-Date

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        // sequence rec-Interval-SD-Time

        template<> void MIXED_ENCODING::Rec_Interval_SD_Time_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        // sequence rec-Interval-SD-Date-Time

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(start_);
            ITU_T_BIND_PER(duration_);
        }

        // sequence start

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // sequence rec-Interval-DE-Date

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        // sequence rec-Interval-DE-Time

        template<> void MIXED_ENCODING::Rec_Interval_DE_Time_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        // sequence rec-Interval-DE-Date-Time

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
            ITU_T_BIND_PER(duration_);
            ITU_T_BIND_PER(end_);
        }

        // sequence end

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        template<> void MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(date_);
            ITU_T_BIND_PER(time_);
        }

        // choice DATE-TYPE

        template<> void DATE_TYPE::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case DATE_TYPE_dt_C_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 13);
                    ITU_T_BIND_PER(value<CENTURY_ENCODING > (false, DATE_TYPE_dt_C_Basic));
                    break;
                }
                case DATE_TYPE_dt_C_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 13);
                    ITU_T_BIND_PER(value<ANY_CENTURY_ENCODING > (false, DATE_TYPE_dt_C_L));
                    break;
                }
                case DATE_TYPE_dt_Y_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 13);
                    ITU_T_BIND_PER(value<YEAR_ENCODING > (false, DATE_TYPE_dt_Y_Basic));
                    break;
                }
                case DATE_TYPE_dt_Y_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_ENCODING > (false, DATE_TYPE_dt_Y_L));
                    break;
                }
                case DATE_TYPE_dt_YM_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 13);
                    ITU_T_BIND_PER(value<YEAR_MONTH_ENCODING > (false, DATE_TYPE_dt_YM_Basic));
                    break;
                }
                case DATE_TYPE_dt_YM_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_MONTH_ENCODING > (false, DATE_TYPE_dt_YM_L));
                    break;
                }
                case DATE_TYPE_dt_YMD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 13);
                    ITU_T_BIND_PER(value<DATE_ENCODING > (false, DATE_TYPE_dt_YMD_Basic));
                    break;
                }
                case DATE_TYPE_dt_YMD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 13);
                    ITU_T_BIND_PER(value<ANY_DATE_ENCODING > (false, DATE_TYPE_dt_YMD_L));
                    break;
                }
                case DATE_TYPE_dt_YD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 13);
                    ITU_T_BIND_PER(value<YEAR_DAY_ENCODING > (false, DATE_TYPE_dt_YD_Basic));
                    break;
                }
                case DATE_TYPE_dt_YD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_DAY_ENCODING > (false, DATE_TYPE_dt_YD_L));
                    break;
                }
                case DATE_TYPE_dt_YW_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 13);
                    ITU_T_BIND_PER(value<YEAR_WEEK_ENCODING > (false, DATE_TYPE_dt_YW_Basic));
                    break;
                }
                case DATE_TYPE_dt_YW_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_ENCODING > (false, DATE_TYPE_dt_YW_L));
                    break;
                }
                case DATE_TYPE_dt_YWD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 13);
                    ITU_T_BIND_PER(value<YEAR_WEEK_DAY_ENCODING > (false, DATE_TYPE_dt_YWD_Basic));
                    break;
                }
                case DATE_TYPE_dt_YWD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_DAY_ENCODING > (false, DATE_TYPE_dt_YWD_L));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void DATE_TYPE::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(13);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<CENTURY_ENCODING > (true, DATE_TYPE_dt_C_Basic));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<ANY_CENTURY_ENCODING > (true, DATE_TYPE_dt_C_L));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<YEAR_ENCODING > (true, DATE_TYPE_dt_Y_Basic));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_ENCODING > (true, DATE_TYPE_dt_Y_L));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<YEAR_MONTH_ENCODING > (true, DATE_TYPE_dt_YM_Basic));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_MONTH_ENCODING > (true, DATE_TYPE_dt_YM_L));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(value<DATE_ENCODING > (true, DATE_TYPE_dt_YMD_Basic));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(value<ANY_DATE_ENCODING > (true, DATE_TYPE_dt_YMD_L));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(value<YEAR_DAY_ENCODING > (true, DATE_TYPE_dt_YD_Basic));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_DAY_ENCODING > (true, DATE_TYPE_dt_YD_L));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(value<YEAR_WEEK_ENCODING > (true, DATE_TYPE_dt_YW_Basic));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_ENCODING > (true, DATE_TYPE_dt_YW_L));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(value<YEAR_WEEK_DAY_ENCODING > (true, DATE_TYPE_dt_YWD_Basic));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_DAY_ENCODING > (true, DATE_TYPE_dt_YWD_L));
                    break;
                }
                default:
                {
                }
            }
        }

        // sequence TIME-TYPE

        template<> void TIME_TYPE::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(number_of_digits_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_type_);
        }

        template<> void TIME_TYPE::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_SIMICONSTRAINT(number_of_digits_, static_cast<integer_type> (1));
            ITU_T_BIND_PER(time_type_);
        }

        // choice time-type

        template<> void TIME_TYPE::Time_type_type::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case Time_type_type_tm_H_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 17);
                    ITU_T_BIND_PER(value<HOURS_ENCODING > (false, Time_type_type_tm_H_L));
                    break;
                }
                case Time_type_type_tm_H_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 17);
                    ITU_T_BIND_PER(value<HOURS_UTC_ENCODING > (false, Time_type_type_tm_H_Z));
                    break;
                }
                case Time_type_type_tm_H_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 17);
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_ENCODING > (false, Time_type_type_tm_H_LD));
                    break;
                }
                case Time_type_type_tm_HM_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 17);
                    ITU_T_BIND_PER(value<MINUTES_ENCODING > (false, Time_type_type_tm_HM_L));
                    break;
                }
                case Time_type_type_tm_HM_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 17);
                    ITU_T_BIND_PER(value<MINUTES_UTC_ENCODING > (false, Time_type_type_tm_HM_Z));
                    break;
                }
                case Time_type_type_tm_HM_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 17);
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_ENCODING > (false, Time_type_type_tm_HM_LD));
                    break;
                }
                case Time_type_type_tm_HMS_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_ENCODING > (false, Time_type_type_tm_HMS_L));
                    break;
                }
                case Time_type_type_tm_HMS_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_ENCODING > (false, Time_type_type_tm_HMS_Z));
                    break;
                }
                case Time_type_type_tm_HMS_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_ENCODING > (false, Time_type_type_tm_HMS_LD));
                    break;
                }
                case Time_type_type_tm_HFn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 17);
                    ITU_T_BIND_PER(value<HOURS_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HFn_L));
                    break;
                }
                case Time_type_type_tm_HFn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 17);
                    ITU_T_BIND_PER(value<HOURS_UTC_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HFn_Z));
                    break;
                }
                case Time_type_type_tm_HFn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 17);
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HFn_LD));
                    break;
                }
                case Time_type_type_tm_HMFn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 17);
                    ITU_T_BIND_PER(value<MINUTES_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFn_L));
                    break;
                }
                case Time_type_type_tm_HMFn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 17);
                    ITU_T_BIND_PER(value<MINUTES_UTC_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFn_Z));
                    break;
                }
                case Time_type_type_tm_HMFn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(14, 17);
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFn_LD));
                    break;
                }
                case Time_type_type_tm_HMFSn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(15, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFSn_L));
                    break;
                }
                case Time_type_type_tm_HMFSn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(16, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFSn_Z));
                    break;
                }
                case Time_type_type_tm_HMFSn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(17, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING > (false, Time_type_type_tm_HMFSn_LD));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void TIME_TYPE::Time_type_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(17);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<HOURS_ENCODING > (true, Time_type_type_tm_H_L));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<HOURS_UTC_ENCODING > (true, Time_type_type_tm_H_Z));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_ENCODING > (true, Time_type_type_tm_H_LD));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<MINUTES_ENCODING > (true, Time_type_type_tm_HM_L));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<MINUTES_UTC_ENCODING > (true, Time_type_type_tm_HM_Z));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_ENCODING > (true, Time_type_type_tm_HM_LD));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_ENCODING > (true, Time_type_type_tm_HMS_L));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_ENCODING > (true, Time_type_type_tm_HMS_Z));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_ENCODING > (true, Time_type_type_tm_HMS_LD));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HFn_L));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(value<HOURS_UTC_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HFn_Z));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HFn_LD));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFn_L));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(value<MINUTES_UTC_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFn_Z));
                    break;
                }
                case 14:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFn_LD));
                    break;
                }
                case 15:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFSn_L));
                    break;
                }
                case 16:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFSn_Z));
                    break;
                }
                case 17:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING > (true, Time_type_type_tm_HMFSn_LD));
                    break;
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

