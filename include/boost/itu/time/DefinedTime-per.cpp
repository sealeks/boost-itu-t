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



        // sequence YEAR-MONTH-ENCODING

        template<> void YEAR_MONTH_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
        }

        template<> void YEAR_MONTH_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
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


        // sequence DATE-ENCODING

        template<> void DATE::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
        }

        template<> void DATE::serialize(boost::asn1::x691::input_coder& arch) {
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


        // sequence YEAR-WEEK-ENCODING

        template<> void YEAR_WEEK_ENCODING::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(year_);
            ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
        }

        template<> void YEAR_WEEK_ENCODING::serialize(boost::asn1::x691::input_coder& arch) {
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

            bool minus = (*sign_).value();

            ITU_T_BIND_PER(minus);
            //ITU_T_BIND_PER_ENUM(sign_, TIME_DIFFERENCE__enumerated__helper);
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (1), static_cast<uint8_t> (59));
        }

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(1);

            bool minus = false;

            ITU_T_BIND_PER(minus);
            //ITU_T_BIND_PER_ENUM(sign_, TIME_DIFFERENCE__enumerated__helper);
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (15));
            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (1), static_cast<uint8_t> (59));

            sign(minus ? sign_negative : sign_positive);
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

        // sequence TIME-OF-DAY

        template<> void TIME_OF_DAY::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
            ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
            ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
        }

        template<> void TIME_OF_DAY::serialize(boost::asn1::x691::input_coder& arch) {
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



        // sequence DURATION

        template<> void DURATION::serialize(boost::asn1::x691::output_coder& arch) {

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

        template<> void DURATION::serialize(boost::asn1::x691::input_coder& arch) {

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

        template<> void DURATION::Fractional_part_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_NUM_CONSTRAINT_EXT(number_of_digits_, static_cast<integer_type> (1), static_cast<integer_type> (3));
            ITU_T_BIND_NUM_CONSTRAINT_EXT(fractional_value_, static_cast<integer_type> (1), static_cast<integer_type> (999));
        }

        template<> void DURATION::Fractional_part_type::serialize(boost::asn1::x691::input_coder& arch) {
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




        // choice DATE-TYPE

        template<> void DATE_TYPE::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case DATE_TYPE_date_C_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 13);
                    ITU_T_BIND_PER(value<CENTURY_ENCODING > (false, DATE_TYPE_date_C_Basic));
                    break;
                }
                case DATE_TYPE_date_C_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 13);
                    ITU_T_BIND_PER(value<ANY_CENTURY > (false, DATE_TYPE_date_C_L));
                    break;
                }
                case DATE_TYPE_date_Y_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 13);
                    ITU_T_BIND_PER(value<YEAR_ENCODING > (false, DATE_TYPE_date_Y_Basic));
                    break;
                }
                case DATE_TYPE_date_Y_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR > (false, DATE_TYPE_date_Y_L));
                    break;
                }
                case DATE_TYPE_date_YM_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 13);
                    ITU_T_BIND_PER(value<YEAR_MONTH_ENCODING > (false, DATE_TYPE_date_YM_Basic));
                    break;
                }
                case DATE_TYPE_date_YM_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_MONTH > (false, DATE_TYPE_date_YM_L));
                    break;
                }
                case DATE_TYPE_date_YMD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 13);
                    ITU_T_BIND_PER(value<DATE_ENCODING > (false, DATE_TYPE_date_YMD_Basic));
                    break;
                }
                case DATE_TYPE_date_YMD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 13);
                    ITU_T_BIND_PER(value<ANY_DATE > (false, DATE_TYPE_date_YMD_L));
                    break;
                }
                case DATE_TYPE_date_YD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 13);
                    ITU_T_BIND_PER(value<YEAR_DAY_ENCODING > (false, DATE_TYPE_date_YD_Basic));
                    break;
                }
                case DATE_TYPE_date_YD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_DAY > (false, DATE_TYPE_date_YD_L));
                    break;
                }
                case DATE_TYPE_date_YW_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 13);
                    ITU_T_BIND_PER(value<YEAR_WEEK_ENCODING > (false, DATE_TYPE_date_YW_Basic));
                    break;
                }
                case DATE_TYPE_date_YW_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK > (false, DATE_TYPE_date_YW_L));
                    break;
                }
                case DATE_TYPE_date_YWD_Basic:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 13);
                    ITU_T_BIND_PER(value<YEAR_WEEK_DAY_ENCODING > (false, DATE_TYPE_date_YWD_Basic));
                    break;
                }
                case DATE_TYPE_date_YWD_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 13);
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_DAY > (false, DATE_TYPE_date_YWD_L));
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
                    ITU_T_BIND_PER(value<CENTURY_ENCODING > (true, DATE_TYPE_date_C_Basic));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<ANY_CENTURY > (true, DATE_TYPE_date_C_L));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<YEAR_ENCODING > (true, DATE_TYPE_date_Y_Basic));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR > (true, DATE_TYPE_date_Y_L));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<YEAR_MONTH_ENCODING > (true, DATE_TYPE_date_YM_Basic));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_MONTH > (true, DATE_TYPE_date_YM_L));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(value<DATE_ENCODING > (true, DATE_TYPE_date_YMD_Basic));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(value<ANY_DATE > (true, DATE_TYPE_date_YMD_L));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(value<YEAR_DAY_ENCODING > (true, DATE_TYPE_date_YD_Basic));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_DAY > (true, DATE_TYPE_date_YD_L));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(value<YEAR_WEEK_ENCODING > (true, DATE_TYPE_date_YW_Basic));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK > (true, DATE_TYPE_date_YW_L));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(value<YEAR_WEEK_DAY_ENCODING > (true, DATE_TYPE_date_YWD_Basic));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(value<ANY_YEAR_WEEK_DAY > (true, DATE_TYPE_date_YWD_L));
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

        template<> void TIME_TYPE::Time_type::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case Time_type_time_H_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 17);
                    ITU_T_BIND_PER(value<HOURS_ENCODING > (false, Time_type_time_H_L));
                    break;
                }
                case Time_type_time_H_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 17);
                    ITU_T_BIND_PER(value<HOURS_UTC_ENCODING > (false, Time_type_time_H_Z));
                    break;
                }
                case Time_type_time_H_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 17);
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_ENCODING > (false, Time_type_time_H_LD));
                    break;
                }
                case Time_type_time_HM_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 17);
                    ITU_T_BIND_PER(value<MINUTES_ENCODING > (false, Time_type_time_HM_L));
                    break;
                }
                case Time_type_time_HM_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 17);
                    ITU_T_BIND_PER(value<MINUTES_UTC_ENCODING > (false, Time_type_time_HM_Z));
                    break;
                }
                case Time_type_time_HM_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 17);
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_ENCODING > (false, Time_type_time_HM_LD));
                    break;
                }
                case Time_type_time_HMS_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(6, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_ENCODING > (false, Time_type_time_HMS_L));
                    break;
                }
                case Time_type_time_HMS_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(7, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_ENCODING > (false, Time_type_time_HMS_Z));
                    break;
                }
                case Time_type_time_HMS_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(8, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_ENCODING > (false, Time_type_time_HMS_LD));
                    break;
                }
                case Time_type_time_HFn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(9, 17);
                    ITU_T_BIND_PER(value<HOURS_AND_FRACTION > (false, Time_type_time_HFn_L));
                    break;
                }
                case Time_type_time_HFn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(10, 17);
                    ITU_T_BIND_PER(value<HOURS_UTC_AND_FRACTION > (false, Time_type_time_HFn_Z));
                    break;
                }
                case Time_type_time_HFn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(11, 17);
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_AND_FRACTION > (false, Time_type_time_HFn_LD));
                    break;
                }
                case Time_type_time_HMFn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(12, 17);
                    ITU_T_BIND_PER(value<MINUTES_AND_FRACTION > (false, Time_type_time_HMFn_L));
                    break;
                }
                case Time_type_time_HMFn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(13, 17);
                    ITU_T_BIND_PER(value<MINUTES_UTC_AND_FRACTION > (false, Time_type_time_HMFn_Z));
                    break;
                }
                case Time_type_time_HMFn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(14, 17);
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_AND_FRACTION > (false, Time_type_time_HMFn_LD));
                    break;
                }
                case Time_type_time_HMFSn_L:
                {
                    ITU_T_SET_CONSTAINED_INDX(15, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_FRACTION > (false, Time_type_time_HMFSn_L));
                    break;
                }
                case Time_type_time_HMFSn_Z:
                {
                    ITU_T_SET_CONSTAINED_INDX(16, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_AND_FRACTION > (false, Time_type_time_HMFSn_Z));
                    break;
                }
                case Time_type_time_HMFSn_LD:
                {
                    ITU_T_SET_CONSTAINED_INDX(17, 17);
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_AND_FRACTION > (false, Time_type_time_HMFSn_LD));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void TIME_TYPE::Time_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(17);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<HOURS_ENCODING > (true, Time_type_time_H_L));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<HOURS_UTC_ENCODING > (true, Time_type_time_H_Z));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_ENCODING > (true, Time_type_time_H_LD));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<MINUTES_ENCODING > (true, Time_type_time_HM_L));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<MINUTES_UTC_ENCODING > (true, Time_type_time_HM_Z));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_ENCODING > (true, Time_type_time_HM_LD));
                    break;
                }
                case 6:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_ENCODING > (true, Time_type_time_HMS_L));
                    break;
                }
                case 7:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_ENCODING > (true, Time_type_time_HMS_Z));
                    break;
                }
                case 8:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_ENCODING > (true, Time_type_time_HMS_LD));
                    break;
                }
                case 9:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_FRACTION > (true, Time_type_time_HFn_L));
                    break;
                }
                case 10:
                {
                    ITU_T_BIND_PER(value<HOURS_UTC_AND_FRACTION > (true, Time_type_time_HFn_Z));
                    break;
                }
                case 11:
                {
                    ITU_T_BIND_PER(value<HOURS_AND_DIFF_AND_FRACTION > (true, Time_type_time_HFn_LD));
                    break;
                }
                case 12:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_FRACTION > (true, Time_type_time_HMFn_L));
                    break;
                }
                case 13:
                {
                    ITU_T_BIND_PER(value<MINUTES_UTC_AND_FRACTION > (true, Time_type_time_HMFn_Z));
                    break;
                }
                case 14:
                {
                    ITU_T_BIND_PER(value<MINUTES_AND_DIFF_AND_FRACTION > (true, Time_type_time_HMFn_LD));
                    break;
                }
                case 15:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_FRACTION > (true, Time_type_time_HMFSn_L));
                    break;
                }
                case 16:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_UTC_AND_FRACTION > (true, Time_type_time_HMFSn_Z));
                    break;
                }
                case 17:
                {
                    ITU_T_BIND_PER(value<TIME_OF_DAY_AND_DIFF_AND_FRACTION > (true, Time_type_time_HMFSn_LD));
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

