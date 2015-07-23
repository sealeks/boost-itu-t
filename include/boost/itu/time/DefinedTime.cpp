#include "DefinedTime.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif


namespace boost {
    namespace asn1 {

        using namespace time_detail;

        // sequence CENTURY-ENCODING

        CENTURY_ENCODING::CENTURY_ENCODING() : as_number_() {
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const uint8_t& arg__val) :
        as_number_(to_range(arg__val, (uint8_t) 0, (uint8_t) 99)) {
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const std::string& vl) :
        as_number_(to_range<uint8_t>(string_to_def<int>(vl), (uint8_t) 0, (uint8_t) 99)) {
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const char* vl) :
        as_number_(to_range<uint8_t>(string_to_def<int>(std::string(vl)), (uint8_t) 0, (uint8_t) 99)) {
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const base_date_time& vl) :
        as_number_(to_range<uint8_t>(vl.is_special() ? 0 : (vl.date().year() / 100), (uint8_t) 0, (uint8_t) 99)) {
        }

        base_date_time CENTURY_ENCODING::as_datetime() const {
            try {
                return base_date_time(base_date(static_cast<int> (as_number())*100, 1, 1));
            } catch (...) {
            }
            return base_date_time();
        }

        base_date CENTURY_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (as_number())*100, 1, 1);
            } catch (...) {
            }
            return base_date();
        }


        ITU_T_HOLDERH_DEFN(CENTURY_ENCODING::as_number, as_number, uint8_t);






        // sequence ANY-CENTURY-ENCODING

        ANY_CENTURY_ENCODING::ANY_CENTURY_ENCODING() : as_number_() {
        };

        ANY_CENTURY_ENCODING::ANY_CENTURY_ENCODING(const integer_type& arg__val) :
        as_number_(arg__val) {
        };

        ANY_CENTURY_ENCODING::ANY_CENTURY_ENCODING(const std::string& vl) :
        as_number_(string_to_def<integer_type>(vl)) {
        };

        ANY_CENTURY_ENCODING::ANY_CENTURY_ENCODING(const char* vl) :
        as_number_(string_to_def<integer_type>(std::string(vl))) {
        };

        ANY_CENTURY_ENCODING::ANY_CENTURY_ENCODING(const base_date_time& vl) :
        as_number_(vl.is_special() ? 0 : (vl.date().year() / 100)) {
        }

        base_date_time ANY_CENTURY_ENCODING::as_datetime() const {
            try {
                return base_date_time(base_date(static_cast<int> (as_number())*100, 1, 1));
            } catch (...) {
            }
            return base_date_time();
        }

        base_date ANY_CENTURY_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (as_number())*100, 1, 1);
            } catch (...) {
            }
            return base_date();
        }


        ITU_T_HOLDERH_DEFN(ANY_CENTURY_ENCODING::as_number, as_number, integer_type);






        // choice YEAR-ENCODING

        YEAR_ENCODING::YEAR_ENCODING(integer_type vl) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_number(vl);
        }

        YEAR_ENCODING::YEAR_ENCODING(const std::string& v) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_number(string_to_def<integer_type>(v));
        }

        YEAR_ENCODING::YEAR_ENCODING(const char* v) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_number(string_to_def<integer_type>(std::string(v)));
        }

        YEAR_ENCODING::YEAR_ENCODING(const base_date_time& v) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_number(v.is_special() ? 0 : (integer_type) v.date().year());
        }



        ITU_T_CHOICES_DEFN(YEAR_ENCODING::immediate, immediate, uint16_t, YEAR_ENCODING_immediate);
        ITU_T_CHOICES_DEFN(YEAR_ENCODING::near_future, near_future, uint16_t, YEAR_ENCODING_near_future);
        ITU_T_CHOICES_DEFN(YEAR_ENCODING::near_past, near_past, uint16_t, YEAR_ENCODING_near_past);
        ITU_T_CHOICES_DEFN(YEAR_ENCODING::remainder, remainder, integer_type, YEAR_ENCODING_remainder);

        integer_type YEAR_ENCODING::as_number() const {
            switch (type()) {
                case YEAR_ENCODING_immediate: return static_cast<integer_type> (*(immediate()));
                case YEAR_ENCODING_near_future: return static_cast<integer_type> (*(near_future()));
                case YEAR_ENCODING_near_past: return static_cast<integer_type> (*(near_past()));
                case YEAR_ENCODING_remainder: return static_cast<integer_type> (*(remainder()));
                default:
                {
                }
            }
            return 0;
        }

        void YEAR_ENCODING::as_number(integer_type v) {
            if (v < 1749 || v > 2276)
                remainder(v);
            else if (v <= 2004)
                near_past(static_cast<uint16_t> (v));
            else if (v <= 2020)
                immediate(static_cast<uint16_t> (v));
            else
                near_future(static_cast<uint16_t> (v));
        }

        base_date_time YEAR_ENCODING::as_datetime() const {
            try {
                return base_date_time(base_date(static_cast<int> (as_number()), 1, 1));
            } catch (...) {
            }
            return base_date_time();
        }

        base_date YEAR_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (as_number()), 1, 1);
            } catch (...) {
            }
            return base_date();
        }


        // sequence ANY-YEAR-ENCODING

        ANY_YEAR_ENCODING::ANY_YEAR_ENCODING() : as_number_() {
        };

        ANY_YEAR_ENCODING::ANY_YEAR_ENCODING(const integer_type& arg__val) :
        as_number_(arg__val) {
        };

        ANY_YEAR_ENCODING::ANY_YEAR_ENCODING(const std::string& vl) :
        as_number_(string_to_def<integer_type>(vl)) {
        };

        ANY_YEAR_ENCODING::ANY_YEAR_ENCODING(const char* vl) :
        as_number_(string_to_def<integer_type>(std::string(vl))) {
        };

        ANY_YEAR_ENCODING::ANY_YEAR_ENCODING(const base_date_time& vl) :
        as_number_(vl.is_special() ? 0 : (integer_type) vl.date().year()) {
        }

        base_date_time ANY_YEAR_ENCODING::as_datetime() const {
            try {
                return base_date_time(base_date(static_cast<int> (as_number()), 1, 1));
            } catch (...) {
            }
            return base_date_time();
        }

        base_date ANY_YEAR_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (as_number()), 1, 1);
            } catch (...) {
            }
            return base_date();
        }


        ITU_T_HOLDERH_DEFN(ANY_YEAR_ENCODING::as_number, as_number, integer_type);






        // sequence YEAR-MONTH-ENCODING

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING() : year_(), month_(1) {
        };

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(integer_type arg__year,
                const uint8_t& arg__month) :
        year_(arg__year), month_(to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)) {
        };

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(const std::string& vl) :
        year_(vl.size() > 2 ? vl.substr(0, vl.size() - 2) : ""),
        month_(to_range<uint8_t>(string_to_def<int>(vl.size() >= 2 ? vl.substr(vl.size() - 2) : ""), (uint8_t) 1, (uint8_t) 12)) {
        }

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(const char* v) : year_(), month_(1) {
            std::string vl = v;
            year(vl.size() > 2 ? vl.substr(0, vl.size() - 2) : "");
            month(to_range<uint8_t>(string_to_def<int>(vl.size() >= 2 ? vl.substr(vl.size() - 2) : ""), (uint8_t) 1, (uint8_t) 12));
        }

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(const base_date_time& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.date().year()),
        month_(vl.is_special() ? 1 : (uint8_t) vl.date().month()) {
        }

        base_date_time YEAR_MONTH_ENCODING::as_datetime() const {
            try {
                return base_date_time(base_date(static_cast<int> (year().as_number()), (int) month(), 1));
            } catch (...) {
            }
            return base_date_time();
        }

        base_date YEAR_MONTH_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (year().as_number()), (int) month(), 1);
            } catch (...) {
            }
            return base_date();
        }


        ITU_T_HOLDERH_DEFN(YEAR_MONTH_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_MONTH_ENCODING::month, month, uint8_t);



        // sequence ANY-YEAR-MONTH-ENCODING

        ANY_YEAR_MONTH_ENCODING::ANY_YEAR_MONTH_ENCODING() : year_(), month_() {
        };

        ANY_YEAR_MONTH_ENCODING::ANY_YEAR_MONTH_ENCODING(integer_type arg__year,
                const uint8_t& arg__month) :
        year_(arg__year), month_(to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)) {
        };

        ANY_YEAR_MONTH_ENCODING::ANY_YEAR_MONTH_ENCODING(const std::string& vl) :
        year_(vl.size() > 2 ? vl.substr(0, vl.size() - 2) : ""),
        month_(to_range<uint8_t>(string_to_def<int>(vl.size() >= 2 ? vl.substr(vl.size() - 2) : ""), (uint8_t) 1, (uint8_t) 12)) {
        }

        ANY_YEAR_MONTH_ENCODING::ANY_YEAR_MONTH_ENCODING(const char* v) : year_(), month_(1) {
            std::string vl = v;
            year(vl.size() > 2 ? vl.substr(0, vl.size() - 2) : "");
            month(to_range<uint8_t>(string_to_def<int>(vl.size() >= 2 ? vl.substr(vl.size() - 2) : ""), (uint8_t) 1, (uint8_t) 12));
        }

        ANY_YEAR_MONTH_ENCODING::ANY_YEAR_MONTH_ENCODING(const base_date_time& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.date().year()),
        month_(vl.is_special() ? 1 : (uint8_t) vl.date().month()) {
        }

        base_date_time ANY_YEAR_MONTH_ENCODING::as_datetime() const {
            try {
                return base_date_time(base_date(static_cast<int> (year().as_number()), (int) month(), 1));
            } catch (...) {
            }
            return base_date_time();
        }

        base_date ANY_YEAR_MONTH_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (year().as_number()), (int) month(), 1);
            } catch (...) {
            }
            return base_date();
        }


        ITU_T_HOLDERH_DEFN(ANY_YEAR_MONTH_ENCODING::year, year, ANY_YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(ANY_YEAR_MONTH_ENCODING::month, month, uint8_t);

        // sequence DATE-ENCODING

        DATE_ENCODING::DATE_ENCODING() : year_(), month_(), day_() {
        };

        DATE_ENCODING::DATE_ENCODING(const YEAR_ENCODING& arg__year,
                const uint8_t& arg__month,
                const uint8_t& arg__day) :
        year_(arg__year),
        month_(arg__month),
        day_(arg__day) {
        };

        DATE_ENCODING::DATE_ENCODING(ITU_T_SHARED(YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint8_t) arg__month,
                ITU_T_SHARED(uint8_t) arg__day) :
        year_(arg__year),
        month_(arg__month),
        day_(arg__day) {
        };


        ITU_T_HOLDERH_DEFN(DATE_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(DATE_ENCODING::month, month, uint8_t);
        ITU_T_HOLDERH_DEFN(DATE_ENCODING::day, day, uint8_t);

        // sequence ANY-DATE-ENCODING

        ANY_DATE_ENCODING::ANY_DATE_ENCODING() : year_(), month_(), day_() {
        };

        ANY_DATE_ENCODING::ANY_DATE_ENCODING(const ANY_YEAR_ENCODING& arg__year,
                const uint8_t& arg__month,
                const uint8_t& arg__day) :
        year_(arg__year),
        month_(arg__month),
        day_(arg__day) {
        };

        ANY_DATE_ENCODING::ANY_DATE_ENCODING(ITU_T_SHARED(ANY_YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint8_t) arg__month,
                ITU_T_SHARED(uint8_t) arg__day) :
        year_(arg__year),
        month_(arg__month),
        day_(arg__day) {
        };


        ITU_T_HOLDERH_DEFN(ANY_DATE_ENCODING::year, year, ANY_YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(ANY_DATE_ENCODING::month, month, uint8_t);
        ITU_T_HOLDERH_DEFN(ANY_DATE_ENCODING::day, day, uint8_t);

        // sequence YEAR-DAY-ENCODING

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING() : year_(), day_() {
        };

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING(const YEAR_ENCODING& arg__year,
                const uint16_t& arg__day) :
        year_(arg__year),
        day_(arg__day) {
        };

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING(ITU_T_SHARED(YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint16_t) arg__day) :
        year_(arg__year),
        day_(arg__day) {
        };


        ITU_T_HOLDERH_DEFN(YEAR_DAY_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_DAY_ENCODING::day, day, uint16_t);

        // sequence ANY-YEAR-DAY-ENCODING

        ANY_YEAR_DAY_ENCODING::ANY_YEAR_DAY_ENCODING() : year_(), day_() {
        };

        ANY_YEAR_DAY_ENCODING::ANY_YEAR_DAY_ENCODING(const ANY_YEAR_ENCODING& arg__year,
                const uint16_t& arg__day) :
        year_(arg__year),
        day_(arg__day) {
        };

        ANY_YEAR_DAY_ENCODING::ANY_YEAR_DAY_ENCODING(ITU_T_SHARED(ANY_YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint16_t) arg__day) :
        year_(arg__year),
        day_(arg__day) {
        };


        ITU_T_HOLDERH_DEFN(ANY_YEAR_DAY_ENCODING::year, year, ANY_YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(ANY_YEAR_DAY_ENCODING::day, day, uint16_t);

        // sequence YEAR-WEEK-ENCODING

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING() : year_(), week_() {
        };

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING(const YEAR_ENCODING& arg__year,
                const uint8_t& arg__week) :
        year_(arg__year),
        week_(arg__week) {
        };

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING(ITU_T_SHARED(YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint8_t) arg__week) :
        year_(arg__year),
        week_(arg__week) {
        };


        ITU_T_HOLDERH_DEFN(YEAR_WEEK_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_WEEK_ENCODING::week, week, uint8_t);

        // sequence ANY-YEAR-WEEK-ENCODING

        ANY_YEAR_WEEK_ENCODING::ANY_YEAR_WEEK_ENCODING() : year_(), week_() {
        };

        ANY_YEAR_WEEK_ENCODING::ANY_YEAR_WEEK_ENCODING(const ANY_YEAR_ENCODING& arg__year,
                const uint8_t& arg__week) :
        year_(arg__year),
        week_(arg__week) {
        };

        ANY_YEAR_WEEK_ENCODING::ANY_YEAR_WEEK_ENCODING(ITU_T_SHARED(ANY_YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint8_t) arg__week) :
        year_(arg__year),
        week_(arg__week) {
        };


        ITU_T_HOLDERH_DEFN(ANY_YEAR_WEEK_ENCODING::year, year, ANY_YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(ANY_YEAR_WEEK_ENCODING::week, week, uint8_t);

        // sequence YEAR-WEEK-DAY-ENCODING

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING() : year_(), week_(), day_() {
        };

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING(const YEAR_ENCODING& arg__year,
                const uint8_t& arg__week,
                const uint8_t& arg__day) :
        year_(arg__year),
        week_(arg__week),
        day_(arg__day) {
        };

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING(ITU_T_SHARED(YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint8_t) arg__week,
                ITU_T_SHARED(uint8_t) arg__day) :
        year_(arg__year),
        week_(arg__week),
        day_(arg__day) {
        };


        ITU_T_HOLDERH_DEFN(YEAR_WEEK_DAY_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_WEEK_DAY_ENCODING::week, week, uint8_t);
        ITU_T_HOLDERH_DEFN(YEAR_WEEK_DAY_ENCODING::day, day, uint8_t);

        // sequence ANY-YEAR-WEEK-DAY-ENCODING

        ANY_YEAR_WEEK_DAY_ENCODING::ANY_YEAR_WEEK_DAY_ENCODING() : year_(), week_(), day_() {
        };

        ANY_YEAR_WEEK_DAY_ENCODING::ANY_YEAR_WEEK_DAY_ENCODING(const ANY_YEAR_ENCODING& arg__year,
                const uint8_t& arg__week,
                const uint8_t& arg__day) :
        year_(arg__year),
        week_(arg__week),
        day_(arg__day) {
        };

        ANY_YEAR_WEEK_DAY_ENCODING::ANY_YEAR_WEEK_DAY_ENCODING(ITU_T_SHARED(ANY_YEAR_ENCODING) arg__year,
                ITU_T_SHARED(uint8_t) arg__week,
                ITU_T_SHARED(uint8_t) arg__day) :
        year_(arg__year),
        week_(arg__week),
        day_(arg__day) {
        };


        ITU_T_HOLDERH_DEFN(ANY_YEAR_WEEK_DAY_ENCODING::year, year, ANY_YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(ANY_YEAR_WEEK_DAY_ENCODING::week, week, uint8_t);
        ITU_T_HOLDERH_DEFN(ANY_YEAR_WEEK_DAY_ENCODING::day, day, uint8_t);

        // sequence HOURS-ENCODING

        HOURS_ENCODING::HOURS_ENCODING() : as_number_() {
        };

        HOURS_ENCODING::HOURS_ENCODING(const uint8_t& arg__val) :
        as_number_(arg__val) {
        };

        HOURS_ENCODING::HOURS_ENCODING(ITU_T_SHARED(uint8_t) arg__val) :
        as_number_(arg__val) {
        };


        ITU_T_HOLDERH_DEFN(HOURS_ENCODING::as_number, as_number, uint8_t);

        // sequence HOURS-UTC-ENCODING

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING() : as_number_() {
        };

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING(const uint8_t& arg__val) :
        as_number_(arg__val) {
        };

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING(ITU_T_SHARED(uint8_t) arg__val) :
        as_number_(arg__val) {
        };


        ITU_T_HOLDERH_DEFN(HOURS_UTC_ENCODING::as_number, as_number, uint8_t);

        // sequence HOURS-AND-DIFF-ENCODING

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING() : local_hours_(), time_difference_() {
        };

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING(const uint8_t& arg__local_hours,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_hours_(arg__local_hours),
        time_difference_(arg__time_difference) {
        };

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING(ITU_T_SHARED(uint8_t) arg__local_hours,
                ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference) :
        local_hours_(arg__local_hours),
        time_difference_(arg__time_difference) {
        };


        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_ENCODING::local_hours, local_hours, uint8_t);
        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);

        // sequence TIME-DIFFERENCE
        const enumerated TIME_DIFFERENCE::sign_positive = 0;
        const enumerated TIME_DIFFERENCE::sign_negative = 1;

        TIME_DIFFERENCE::TIME_DIFFERENCE() : sign_(), hours_() {
        };

        TIME_DIFFERENCE::TIME_DIFFERENCE(const enumerated& arg__sign,
                const uint8_t& arg__hours) :
        sign_(arg__sign),
        hours_(arg__hours) {
        };

        TIME_DIFFERENCE::TIME_DIFFERENCE(ITU_T_SHARED(enumerated) arg__sign,
                ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes) :
        sign_(arg__sign),
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };


        ITU_T_HOLDERH_DEFN(TIME_DIFFERENCE::sign, sign, enumerated);
        ITU_T_HOLDERH_DEFN(TIME_DIFFERENCE::hours, hours, uint8_t);
        ITU_T_OPTIONAL_DEFN(TIME_DIFFERENCE::minutes, minutes, uint8_t);

        // sequence MINUTES-ENCODING

        MINUTES_ENCODING::MINUTES_ENCODING() : hours_(), minutes_() {
        };

        MINUTES_ENCODING::MINUTES_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes) :
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };

        MINUTES_ENCODING::MINUTES_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes) :
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };


        ITU_T_HOLDERH_DEFN(MINUTES_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_ENCODING::minutes, minutes, uint8_t);

        // sequence MINUTES-UTC-ENCODING

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING() : hours_(), minutes_() {
        };

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes) :
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes) :
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };


        ITU_T_HOLDERH_DEFN(MINUTES_UTC_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_UTC_ENCODING::minutes, minutes, uint8_t);

        // sequence MINUTES-AND-DIFF-ENCODING

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING() : local_time_(), time_difference_() {
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(const Local_time_type& arg__local_time,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        MINUTES_AND_DIFF_ENCODING::Local_time_type::Local_time_type() : hours_(), minutes_() {
        };

        MINUTES_AND_DIFF_ENCODING::Local_time_type::Local_time_type(const uint8_t& arg__hours,
                const uint8_t& arg__minutes) :
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };

        MINUTES_AND_DIFF_ENCODING::Local_time_type::Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes) :
        hours_(arg__hours),
        minutes_(arg__minutes) {
        };


        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_ENCODING::Local_time_type::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_ENCODING::Local_time_type::minutes, minutes, uint8_t);


        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_ENCODING::local_time, local_time, MINUTES_AND_DIFF_ENCODING::Local_time_type);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);

        // sequence TIME-OF-DAY-ENCODING

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING() : hours_(), minutes_(), seconds_() {
        };

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds) {
        };

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(uint8_t) arg__seconds) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds) {
        };


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_ENCODING::seconds, seconds, uint8_t);

        // sequence TIME-OF-DAY-UTC-ENCODING

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING() : hours_(), minutes_(), seconds_() {
        };

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds) {
        };

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(uint8_t) arg__seconds) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds) {
        };


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_ENCODING::seconds, seconds, uint8_t);

        // sequence TIME-OF-DAY-AND-DIFF-ENCODING

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING() : local_time_(), time_difference_() {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(const Local_time_type& arg__local_time,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::Local_time_type() : hours_(), minutes_(), seconds_() {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::Local_time_type(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds) {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(uint8_t) arg__seconds) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds) {
        };


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type::seconds, seconds, uint8_t);


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::local_time, local_time, TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);

        // sequence HOURS-AND-FRACTION-ENCODING

        HOURS_AND_FRACTION_ENCODING::HOURS_AND_FRACTION_ENCODING() : hours_(), fraction_() {
        };

        HOURS_AND_FRACTION_ENCODING::HOURS_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        fraction_(arg__fraction) {
        };

        HOURS_AND_FRACTION_ENCODING::HOURS_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(HOURS_AND_FRACTION_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(HOURS_AND_FRACTION_ENCODING::fraction, fraction, integer_type);

        // sequence HOURS-UTC-AND-FRACTION-ENCODING

        HOURS_UTC_AND_FRACTION_ENCODING::HOURS_UTC_AND_FRACTION_ENCODING() : hours_(), fraction_() {
        };

        HOURS_UTC_AND_FRACTION_ENCODING::HOURS_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        fraction_(arg__fraction) {
        };

        HOURS_UTC_AND_FRACTION_ENCODING::HOURS_UTC_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(HOURS_UTC_AND_FRACTION_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(HOURS_UTC_AND_FRACTION_ENCODING::fraction, fraction, integer_type);

        // sequence HOURS-AND-DIFF-AND-FRACTION-ENCODING

        HOURS_AND_DIFF_AND_FRACTION_ENCODING::HOURS_AND_DIFF_AND_FRACTION_ENCODING() : local_hours_(), fraction_(), time_difference_() {
        };

        HOURS_AND_DIFF_AND_FRACTION_ENCODING::HOURS_AND_DIFF_AND_FRACTION_ENCODING(const uint8_t& arg__local_hours,
                const integer_type& arg__fraction,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_hours_(arg__local_hours),
        fraction_(arg__fraction),
        time_difference_(arg__time_difference) {
        };

        HOURS_AND_DIFF_AND_FRACTION_ENCODING::HOURS_AND_DIFF_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__local_hours,
                ITU_T_SHARED(integer_type) arg__fraction,
                ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference) :
        local_hours_(arg__local_hours),
        fraction_(arg__fraction),
        time_difference_(arg__time_difference) {
        };


        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_AND_FRACTION_ENCODING::local_hours, local_hours, uint8_t);
        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_AND_FRACTION_ENCODING::fraction, fraction, integer_type);
        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_AND_FRACTION_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);

        // sequence MINUTES-AND-FRACTION-ENCODING

        MINUTES_AND_FRACTION_ENCODING::MINUTES_AND_FRACTION_ENCODING() : hours_(), minutes_(), fraction_() {
        };

        MINUTES_AND_FRACTION_ENCODING::MINUTES_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        fraction_(arg__fraction) {
        };

        MINUTES_AND_FRACTION_ENCODING::MINUTES_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(MINUTES_AND_FRACTION_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_FRACTION_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_FRACTION_ENCODING::fraction, fraction, integer_type);

        // sequence MINUTES-UTC-AND-FRACTION-ENCODING

        MINUTES_UTC_AND_FRACTION_ENCODING::MINUTES_UTC_AND_FRACTION_ENCODING() : hours_(), minutes_(), fraction_() {
        };

        MINUTES_UTC_AND_FRACTION_ENCODING::MINUTES_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        fraction_(arg__fraction) {
        };

        MINUTES_UTC_AND_FRACTION_ENCODING::MINUTES_UTC_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(MINUTES_UTC_AND_FRACTION_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_UTC_AND_FRACTION_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_UTC_AND_FRACTION_ENCODING::fraction, fraction, integer_type);

        // sequence MINUTES-AND-DIFF-AND-FRACTION-ENCODING

        MINUTES_AND_DIFF_AND_FRACTION_ENCODING::MINUTES_AND_DIFF_AND_FRACTION_ENCODING() : local_time_(), time_difference_() {
        };

        MINUTES_AND_DIFF_AND_FRACTION_ENCODING::MINUTES_AND_DIFF_AND_FRACTION_ENCODING(const Local_time_type& arg__local_time,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        MINUTES_AND_DIFF_AND_FRACTION_ENCODING::MINUTES_AND_DIFF_AND_FRACTION_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::Local_time_type() : hours_(), minutes_(), fraction_() {
        };

        MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::Local_time_type(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        fraction_(arg__fraction) {
        };

        MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::fraction, fraction, integer_type);


        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::local_time, local_time, MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);

        // sequence TIME-OF-DAY-AND-FRACTION-ENCODING

        TIME_OF_DAY_AND_FRACTION_ENCODING::TIME_OF_DAY_AND_FRACTION_ENCODING() : hours_(), minutes_(), seconds_(), fraction_() {
        };

        TIME_OF_DAY_AND_FRACTION_ENCODING::TIME_OF_DAY_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fraction_(arg__fraction) {
        };

        TIME_OF_DAY_AND_FRACTION_ENCODING::TIME_OF_DAY_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(uint8_t) arg__seconds,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_FRACTION_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_FRACTION_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_FRACTION_ENCODING::seconds, seconds, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_FRACTION_ENCODING::fraction, fraction, integer_type);

        // sequence TIME-OF-DAY-UTC-AND-FRACTION-ENCODING

        TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::TIME_OF_DAY_UTC_AND_FRACTION_ENCODING() : hours_(), minutes_(), seconds_(), fraction_() {
        };

        TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fraction_(arg__fraction) {
        };

        TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(uint8_t) arg__seconds,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::seconds, seconds, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING::fraction, fraction, integer_type);

        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING() : local_time_(), time_difference_() {
        };

        TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(const Local_time_type& arg__local_time,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::Local_time_type() : hours_(), minutes_(), seconds_(), fraction_() {
        };

        TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::Local_time_type(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds,
                const integer_type& arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fraction_(arg__fraction) {
        };

        TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                ITU_T_SHARED(uint8_t) arg__minutes,
                ITU_T_SHARED(uint8_t) arg__seconds,
                ITU_T_SHARED(integer_type) arg__fraction) :
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fraction_(arg__fraction) {
        };


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::seconds, seconds, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type::fraction, fraction, integer_type);


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::local_time, local_time, TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);

        // sequence DURATION-INTERVAL-ENCODING

        DURATION_INTERVAL_ENCODING::DURATION_INTERVAL_ENCODING() {
        };

        DURATION_INTERVAL_ENCODING::DURATION_INTERVAL_ENCODING(ITU_T_SHARED(integer_type) arg__years,
                ITU_T_SHARED(integer_type) arg__months,
                ITU_T_SHARED(integer_type) arg__weeks,
                ITU_T_SHARED(integer_type) arg__days,
                ITU_T_SHARED(integer_type) arg__hours,
                ITU_T_SHARED(integer_type) arg__minutes,
                ITU_T_SHARED(integer_type) arg__seconds,
                ITU_T_SHARED(Fractional_part_type) arg__fractional_part) :
        years_(arg__years),
        months_(arg__months),
        weeks_(arg__weeks),
        days_(arg__days),
        hours_(arg__hours),
        minutes_(arg__minutes),
        seconds_(arg__seconds),
        fractional_part_(arg__fractional_part) {
        };

        DURATION_INTERVAL_ENCODING::Fractional_part_type::Fractional_part_type() : number_of_digits_(), fractional_value_() {
        };

        DURATION_INTERVAL_ENCODING::Fractional_part_type::Fractional_part_type(const integer_type& arg__number_of_digits,
                const integer_type& arg__fractional_value) :
        number_of_digits_(arg__number_of_digits),
        fractional_value_(arg__fractional_value) {
        };

        DURATION_INTERVAL_ENCODING::Fractional_part_type::Fractional_part_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(integer_type) arg__fractional_value) :
        number_of_digits_(arg__number_of_digits),
        fractional_value_(arg__fractional_value) {
        };


        ITU_T_HOLDERH_DEFN(DURATION_INTERVAL_ENCODING::Fractional_part_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(DURATION_INTERVAL_ENCODING::Fractional_part_type::fractional_value, fractional_value, integer_type);


        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::years, years, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::months, months, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::weeks, weeks, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::days, days, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::hours, hours, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::minutes, minutes, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::seconds, seconds, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION_INTERVAL_ENCODING::fractional_part, fractional_part, DURATION_INTERVAL_ENCODING::Fractional_part_type);

        // sequence REC-DURATION-INTERVAL-ENCODING

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING() : duration_() {
        };

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING(const DURATION_INTERVAL_ENCODING& arg__duration) :
        duration_(arg__duration) {
        };

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        recurrence_(arg__recurrence),
        duration_(arg__duration) {
        };


        ITU_T_OPTIONAL_DEFN(REC_DURATION_INTERVAL_ENCODING::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(REC_DURATION_INTERVAL_ENCODING::duration, duration, DURATION_INTERVAL_ENCODING);

        // choice MIXED-ENCODING

        MIXED_ENCODING::Time_HFn_L_type::Time_HFn_L_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HFn_L_type::Time_HFn_L_type(const integer_type& arg__number_of_digits,
                const HOURS_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HFn_L_type::Time_HFn_L_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(HOURS_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HFn_L_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HFn_L_type::time_value, time_value, HOURS_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HFn_Z_type::Time_HFn_Z_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HFn_Z_type::Time_HFn_Z_type(const integer_type& arg__number_of_digits,
                const HOURS_UTC_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HFn_Z_type::Time_HFn_Z_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(HOURS_UTC_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HFn_Z_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HFn_Z_type::time_value, time_value, HOURS_UTC_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HFn_LD_type::Time_HFn_LD_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HFn_LD_type::Time_HFn_LD_type(const integer_type& arg__number_of_digits,
                const HOURS_AND_DIFF_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HFn_LD_type::Time_HFn_LD_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(HOURS_AND_DIFF_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HFn_LD_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HFn_LD_type::time_value, time_value, HOURS_AND_DIFF_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HMFn_L_type::Time_HMFn_L_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HMFn_L_type::Time_HMFn_L_type(const integer_type& arg__number_of_digits,
                const MINUTES_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HMFn_L_type::Time_HMFn_L_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(MINUTES_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFn_L_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFn_L_type::time_value, time_value, MINUTES_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HMFn_Z_type::Time_HMFn_Z_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HMFn_Z_type::Time_HMFn_Z_type(const integer_type& arg__number_of_digits,
                const MINUTES_UTC_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HMFn_Z_type::Time_HMFn_Z_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(MINUTES_UTC_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFn_Z_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFn_Z_type::time_value, time_value, MINUTES_UTC_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HMFn_LD_type::Time_HMFn_LD_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HMFn_LD_type::Time_HMFn_LD_type(const integer_type& arg__number_of_digits,
                const MINUTES_AND_DIFF_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HMFn_LD_type::Time_HMFn_LD_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(MINUTES_AND_DIFF_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFn_LD_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFn_LD_type::time_value, time_value, MINUTES_AND_DIFF_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HMFSn_L_type::Time_HMFSn_L_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HMFSn_L_type::Time_HMFSn_L_type(const integer_type& arg__number_of_digits,
                const TIME_OF_DAY_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HMFSn_L_type::Time_HMFSn_L_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(TIME_OF_DAY_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFSn_L_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFSn_L_type::time_value, time_value, TIME_OF_DAY_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HMFSn_Z_type::Time_HMFSn_Z_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HMFSn_Z_type::Time_HMFSn_Z_type(const integer_type& arg__number_of_digits,
                const TIME_OF_DAY_UTC_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HMFSn_Z_type::Time_HMFSn_Z_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFSn_Z_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFSn_Z_type::time_value, time_value, TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Time_HMFSn_LD_type::Time_HMFSn_LD_type() : number_of_digits_(), time_value_() {
        };

        MIXED_ENCODING::Time_HMFSn_LD_type::Time_HMFSn_LD_type(const integer_type& arg__number_of_digits,
                const TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING& arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };

        MIXED_ENCODING::Time_HMFSn_LD_type::Time_HMFSn_LD_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING) arg__time_value) :
        number_of_digits_(arg__number_of_digits),
        time_value_(arg__time_value) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFSn_LD_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Time_HMFSn_LD_type::time_value, time_value, TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);

        MIXED_ENCODING::Date_time_type::Date_time_type() : date_(), time_() {
        };

        MIXED_ENCODING::Date_time_type::Date_time_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Date_time_type::Date_time_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Date_time_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Date_time_type::time, time, TIME_TYPE);

        MIXED_ENCODING::Iterval_SE_Date_type::Iterval_SE_Date_type() : start_(), end_() {
        };

        MIXED_ENCODING::Iterval_SE_Date_type::Iterval_SE_Date_type(const DATE_TYPE& arg__start,
                const DATE_TYPE& arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_SE_Date_type::Iterval_SE_Date_type(ITU_T_SHARED(DATE_TYPE) arg__start,
                ITU_T_SHARED(DATE_TYPE) arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_type::start, start, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_type::end, end, DATE_TYPE);

        MIXED_ENCODING::Iterval_SE_Time_type::Iterval_SE_Time_type() : start_(), end_() {
        };

        MIXED_ENCODING::Iterval_SE_Time_type::Iterval_SE_Time_type(const TIME_TYPE& arg__start,
                const TIME_TYPE& arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_SE_Time_type::Iterval_SE_Time_type(ITU_T_SHARED(TIME_TYPE) arg__start,
                ITU_T_SHARED(TIME_TYPE) arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Time_type::start, start, TIME_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Time_type::end, end, TIME_TYPE);

        MIXED_ENCODING::Iterval_SE_Date_Time_type::Iterval_SE_Date_Time_type() : start_(), end_() {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::Iterval_SE_Date_Time_type(const Start_type& arg__start,
                const End_type& arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::Iterval_SE_Date_Time_type(ITU_T_SHARED(Start_type) arg__start,
                ITU_T_SHARED(End_type) arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::Start_type() : date_(), time_() {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::Start_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type::time, time, TIME_TYPE);

        MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::End_type() : date_(), time_() {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::End_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type::time, time, TIME_TYPE);


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_Time_type::start, start, MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SE_Date_Time_type::end, end, MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type);

        MIXED_ENCODING::Iterval_SD_Date_type::Iterval_SD_Date_type() : start_(), duration_() {
        };

        MIXED_ENCODING::Iterval_SD_Date_type::Iterval_SD_Date_type(const DATE_TYPE& arg__start,
                const DURATION_INTERVAL_ENCODING& arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Iterval_SD_Date_type::Iterval_SD_Date_type(ITU_T_SHARED(DATE_TYPE) arg__start,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Date_type::start, start, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Date_type::duration, duration, DURATION_INTERVAL_ENCODING);

        MIXED_ENCODING::Iterval_SD_Time_type::Iterval_SD_Time_type() : start_(), duration_() {
        };

        MIXED_ENCODING::Iterval_SD_Time_type::Iterval_SD_Time_type(const TIME_TYPE& arg__start,
                const DURATION_INTERVAL_ENCODING& arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Iterval_SD_Time_type::Iterval_SD_Time_type(ITU_T_SHARED(TIME_TYPE) arg__start,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Time_type::start, start, TIME_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);

        MIXED_ENCODING::Iterval_SD_Date_Time_type::Iterval_SD_Date_Time_type() : start_(), duration_() {
        };

        MIXED_ENCODING::Iterval_SD_Date_Time_type::Iterval_SD_Date_Time_type(const Start_type& arg__start,
                const DURATION_INTERVAL_ENCODING& arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Iterval_SD_Date_Time_type::Iterval_SD_Date_Time_type(ITU_T_SHARED(Start_type) arg__start,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::Start_type() : date_(), time_() {
        };

        MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::Start_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type::time, time, TIME_TYPE);


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Date_Time_type::start, start, MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_SD_Date_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);

        MIXED_ENCODING::Iterval_DE_Date_type::Iterval_DE_Date_type() : duration_(), end_() {
        };

        MIXED_ENCODING::Iterval_DE_Date_type::Iterval_DE_Date_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                const DATE_TYPE& arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_DE_Date_type::Iterval_DE_Date_type(ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                ITU_T_SHARED(DATE_TYPE) arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Date_type::duration, duration, DURATION_INTERVAL_ENCODING);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Date_type::end, end, DATE_TYPE);

        MIXED_ENCODING::Iterval_DE_Time_type::Iterval_DE_Time_type() : duration_(), end_() {
        };

        MIXED_ENCODING::Iterval_DE_Time_type::Iterval_DE_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                const TIME_TYPE& arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_DE_Time_type::Iterval_DE_Time_type(ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                ITU_T_SHARED(TIME_TYPE) arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Time_type::end, end, TIME_TYPE);

        MIXED_ENCODING::Iterval_DE_Date_Time_type::Iterval_DE_Date_Time_type() : duration_(), end_() {
        };

        MIXED_ENCODING::Iterval_DE_Date_Time_type::Iterval_DE_Date_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                const End_type& arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_DE_Date_Time_type::Iterval_DE_Date_Time_type(ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                ITU_T_SHARED(End_type) arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::End_type() : date_(), time_() {
        };

        MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::End_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type::time, time, TIME_TYPE);


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Date_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Iterval_DE_Date_Time_type::end, end, MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type);

        MIXED_ENCODING::Rec_Interval_SE_Date_type::Rec_Interval_SE_Date_type() : start_(), end_() {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_type::Rec_Interval_SE_Date_type(const DATE_TYPE& arg__start,
                const DATE_TYPE& arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_type::Rec_Interval_SE_Date_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(DATE_TYPE) arg__start,
                ITU_T_SHARED(DATE_TYPE) arg__end) :
        recurrence_(arg__recurrence),
        start_(arg__start),
        end_(arg__end) {
        };


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_type::start, start, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_type::end, end, DATE_TYPE);

        MIXED_ENCODING::Rec_Interval_SE_Time_type::Rec_Interval_SE_Time_type() : start_(), end_() {
        };

        MIXED_ENCODING::Rec_Interval_SE_Time_type::Rec_Interval_SE_Time_type(const TIME_TYPE& arg__start,
                const TIME_TYPE& arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_SE_Time_type::Rec_Interval_SE_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(TIME_TYPE) arg__start,
                ITU_T_SHARED(TIME_TYPE) arg__end) :
        recurrence_(arg__recurrence),
        start_(arg__start),
        end_(arg__end) {
        };


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_SE_Time_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Time_type::start, start, TIME_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Time_type::end, end, TIME_TYPE);

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Rec_Interval_SE_Date_Time_type() : start_(), end_() {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Rec_Interval_SE_Date_Time_type(const Start_type& arg__start,
                const End_type& arg__end) :
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Rec_Interval_SE_Date_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(Start_type) arg__start,
                ITU_T_SHARED(End_type) arg__end) :
        recurrence_(arg__recurrence),
        start_(arg__start),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::Start_type() : date_(), time_() {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::Start_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type::time, time, TIME_TYPE);

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::End_type() : date_(), time_() {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::End_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type::time, time, TIME_TYPE);


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::start, start, MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::end, end, MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type);

        MIXED_ENCODING::Rec_Interval_SD_Date_type::Rec_Interval_SD_Date_type() : start_(), duration_() {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_type::Rec_Interval_SD_Date_type(const DATE_TYPE& arg__start,
                const DURATION_INTERVAL_ENCODING& arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_type::Rec_Interval_SD_Date_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(DATE_TYPE) arg__start,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        recurrence_(arg__recurrence),
        start_(arg__start),
        duration_(arg__duration) {
        };


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_type::start, start, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_type::duration, duration, DURATION_INTERVAL_ENCODING);

        MIXED_ENCODING::Rec_Interval_SD_Time_type::Rec_Interval_SD_Time_type() : start_(), duration_() {
        };

        MIXED_ENCODING::Rec_Interval_SD_Time_type::Rec_Interval_SD_Time_type(const TIME_TYPE& arg__start,
                const DURATION_INTERVAL_ENCODING& arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Rec_Interval_SD_Time_type::Rec_Interval_SD_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(TIME_TYPE) arg__start,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        recurrence_(arg__recurrence),
        start_(arg__start),
        duration_(arg__duration) {
        };


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_SD_Time_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Time_type::start, start, TIME_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);

        MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Rec_Interval_SD_Date_Time_type() : start_(), duration_() {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Rec_Interval_SD_Date_Time_type(const Start_type& arg__start,
                const DURATION_INTERVAL_ENCODING& arg__duration) :
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Rec_Interval_SD_Date_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(Start_type) arg__start,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration) :
        recurrence_(arg__recurrence),
        start_(arg__start),
        duration_(arg__duration) {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::Start_type() : date_(), time_() {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::Start_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type::time, time, TIME_TYPE);


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::start, start, MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);

        MIXED_ENCODING::Rec_Interval_DE_Date_type::Rec_Interval_DE_Date_type() : duration_(), end_() {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_type::Rec_Interval_DE_Date_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                const DATE_TYPE& arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_type::Rec_Interval_DE_Date_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                ITU_T_SHARED(DATE_TYPE) arg__end) :
        recurrence_(arg__recurrence),
        duration_(arg__duration),
        end_(arg__end) {
        };


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_type::duration, duration, DURATION_INTERVAL_ENCODING);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_type::end, end, DATE_TYPE);

        MIXED_ENCODING::Rec_Interval_DE_Time_type::Rec_Interval_DE_Time_type() : duration_(), end_() {
        };

        MIXED_ENCODING::Rec_Interval_DE_Time_type::Rec_Interval_DE_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                const TIME_TYPE& arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_DE_Time_type::Rec_Interval_DE_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                ITU_T_SHARED(TIME_TYPE) arg__end) :
        recurrence_(arg__recurrence),
        duration_(arg__duration),
        end_(arg__end) {
        };


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_DE_Time_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Time_type::end, end, TIME_TYPE);

        MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::Rec_Interval_DE_Date_Time_type() : duration_(), end_() {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::Rec_Interval_DE_Date_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                const End_type& arg__end) :
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::Rec_Interval_DE_Date_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                ITU_T_SHARED(End_type) arg__end) :
        recurrence_(arg__recurrence),
        duration_(arg__duration),
        end_(arg__end) {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::End_type() : date_(), time_() {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::End_type(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                ITU_T_SHARED(TIME_TYPE) arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };


        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type::time, time, TIME_TYPE);


        ITU_T_OPTIONAL_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::duration, duration, DURATION_INTERVAL_ENCODING);
        ITU_T_HOLDERH_DEFN(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::end, end, MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type);


        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_C_Basic, date_C_Basic, CENTURY_ENCODING, MIXED_ENCODING_date_C_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_C_L, date_C_L, ANY_CENTURY_ENCODING, MIXED_ENCODING_date_C_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_Y_Basic, date_Y_Basic, YEAR_ENCODING, MIXED_ENCODING_date_Y_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_Y_L, date_Y_L, ANY_YEAR_ENCODING, MIXED_ENCODING_date_Y_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YM_Basic, date_YM_Basic, YEAR_MONTH_ENCODING, MIXED_ENCODING_date_YM_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YM_L, date_YM_L, ANY_YEAR_MONTH_ENCODING, MIXED_ENCODING_date_YM_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YMD_Basic, date_YMD_Basic, DATE_ENCODING, MIXED_ENCODING_date_YMD_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YMD_L, date_YMD_L, ANY_DATE_ENCODING, MIXED_ENCODING_date_YMD_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YD_Basic, date_YD_Basic, YEAR_DAY_ENCODING, MIXED_ENCODING_date_YD_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YD_L, date_YD_L, ANY_YEAR_DAY_ENCODING, MIXED_ENCODING_date_YD_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YW_Basic, date_YW_Basic, YEAR_WEEK_ENCODING, MIXED_ENCODING_date_YW_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YW_L, date_YW_L, ANY_YEAR_WEEK_ENCODING, MIXED_ENCODING_date_YW_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YWD_Basic, date_YWD_Basic, YEAR_WEEK_DAY_ENCODING, MIXED_ENCODING_date_YWD_Basic);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_YWD_L, date_YWD_L, ANY_YEAR_WEEK_DAY_ENCODING, MIXED_ENCODING_date_YWD_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_H_L, time_H_L, HOURS_ENCODING, MIXED_ENCODING_time_H_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_H_Z, time_H_Z, HOURS_UTC_ENCODING, MIXED_ENCODING_time_H_Z);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_H_LD, time_H_LD, HOURS_AND_DIFF_ENCODING, MIXED_ENCODING_time_H_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HM_L, time_HM_L, MINUTES_ENCODING, MIXED_ENCODING_time_HM_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HM_Z, time_HM_Z, MINUTES_UTC_ENCODING, MIXED_ENCODING_time_HM_Z);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HM_LD, time_HM_LD, MINUTES_AND_DIFF_ENCODING, MIXED_ENCODING_time_HM_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMS_L, time_HMS_L, TIME_OF_DAY_ENCODING, MIXED_ENCODING_time_HMS_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMS_Z, time_HMS_Z, TIME_OF_DAY_UTC_ENCODING, MIXED_ENCODING_time_HMS_Z);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMS_LD, time_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, MIXED_ENCODING_time_HMS_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HFn_L, time_HFn_L, MIXED_ENCODING::Time_HFn_L_type, MIXED_ENCODING_time_HFn_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HFn_Z, time_HFn_Z, MIXED_ENCODING::Time_HFn_Z_type, MIXED_ENCODING_time_HFn_Z);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HFn_LD, time_HFn_LD, MIXED_ENCODING::Time_HFn_LD_type, MIXED_ENCODING_time_HFn_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMFn_L, time_HMFn_L, MIXED_ENCODING::Time_HMFn_L_type, MIXED_ENCODING_time_HMFn_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMFn_Z, time_HMFn_Z, MIXED_ENCODING::Time_HMFn_Z_type, MIXED_ENCODING_time_HMFn_Z);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMFn_LD, time_HMFn_LD, MIXED_ENCODING::Time_HMFn_LD_type, MIXED_ENCODING_time_HMFn_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMFSn_L, time_HMFSn_L, MIXED_ENCODING::Time_HMFSn_L_type, MIXED_ENCODING_time_HMFSn_L);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMFSn_Z, time_HMFSn_Z, MIXED_ENCODING::Time_HMFSn_Z_type, MIXED_ENCODING_time_HMFSn_Z);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::time_HMFSn_LD, time_HMFSn_LD, MIXED_ENCODING::Time_HMFSn_LD_type, MIXED_ENCODING_time_HMFSn_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::date_time, date_time, MIXED_ENCODING::Date_time_type, MIXED_ENCODING_date_time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_SE_Date, iterval_SE_Date, MIXED_ENCODING::Iterval_SE_Date_type, MIXED_ENCODING_iterval_SE_Date);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_SE_Time, iterval_SE_Time, MIXED_ENCODING::Iterval_SE_Time_type, MIXED_ENCODING_iterval_SE_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_SE_Date_Time, iterval_SE_Date_Time, MIXED_ENCODING::Iterval_SE_Date_Time_type, MIXED_ENCODING_iterval_SE_Date_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_D, iterval_D, DURATION_INTERVAL_ENCODING, MIXED_ENCODING_iterval_D);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_SD_Date, iterval_SD_Date, MIXED_ENCODING::Iterval_SD_Date_type, MIXED_ENCODING_iterval_SD_Date);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_SD_Time, iterval_SD_Time, MIXED_ENCODING::Iterval_SD_Time_type, MIXED_ENCODING_iterval_SD_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_SD_Date_Time, iterval_SD_Date_Time, MIXED_ENCODING::Iterval_SD_Date_Time_type, MIXED_ENCODING_iterval_SD_Date_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_DE_Date, iterval_DE_Date, MIXED_ENCODING::Iterval_DE_Date_type, MIXED_ENCODING_iterval_DE_Date);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_DE_Time, iterval_DE_Time, MIXED_ENCODING::Iterval_DE_Time_type, MIXED_ENCODING_iterval_DE_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::iterval_DE_Date_Time, iterval_DE_Date_Time, MIXED_ENCODING::Iterval_DE_Date_Time_type, MIXED_ENCODING_iterval_DE_Date_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_SE_Date, rec_Interval_SE_Date, MIXED_ENCODING::Rec_Interval_SE_Date_type, MIXED_ENCODING_rec_Interval_SE_Date);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_SE_Time, rec_Interval_SE_Time, MIXED_ENCODING::Rec_Interval_SE_Time_type, MIXED_ENCODING_rec_Interval_SE_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_SE_Date_Time, rec_Interval_SE_Date_Time, MIXED_ENCODING::Rec_Interval_SE_Date_Time_type, MIXED_ENCODING_rec_Interval_SE_Date_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_D, rec_Interval_D, REC_DURATION_INTERVAL_ENCODING, MIXED_ENCODING_rec_Interval_D);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_SD_Date, rec_Interval_SD_Date, MIXED_ENCODING::Rec_Interval_SD_Date_type, MIXED_ENCODING_rec_Interval_SD_Date);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_SD_Time, rec_Interval_SD_Time, MIXED_ENCODING::Rec_Interval_SD_Time_type, MIXED_ENCODING_rec_Interval_SD_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_SD_Date_Time, rec_Interval_SD_Date_Time, MIXED_ENCODING::Rec_Interval_SD_Date_Time_type, MIXED_ENCODING_rec_Interval_SD_Date_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_DE_Date, rec_Interval_DE_Date, MIXED_ENCODING::Rec_Interval_DE_Date_type, MIXED_ENCODING_rec_Interval_DE_Date);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_DE_Time, rec_Interval_DE_Time, MIXED_ENCODING::Rec_Interval_DE_Time_type, MIXED_ENCODING_rec_Interval_DE_Time);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::rec_Interval_DE_Date_Time, rec_Interval_DE_Date_Time, MIXED_ENCODING::Rec_Interval_DE_Date_Time_type, MIXED_ENCODING_rec_Interval_DE_Date_Time);

        // choice DATE-TYPE

        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_C_Basic, dt_C_Basic, CENTURY_ENCODING, DATE_TYPE_dt_C_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_C_L, dt_C_L, ANY_CENTURY_ENCODING, DATE_TYPE_dt_C_L);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_Y_Basic, dt_Y_Basic, YEAR_ENCODING, DATE_TYPE_dt_Y_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_Y_L, dt_Y_L, ANY_YEAR_ENCODING, DATE_TYPE_dt_Y_L);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YM_Basic, dt_YM_Basic, YEAR_MONTH_ENCODING, DATE_TYPE_dt_YM_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YM_L, dt_YM_L, ANY_YEAR_MONTH_ENCODING, DATE_TYPE_dt_YM_L);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YMD_Basic, dt_YMD_Basic, DATE_ENCODING, DATE_TYPE_dt_YMD_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YMD_L, dt_YMD_L, ANY_DATE_ENCODING, DATE_TYPE_dt_YMD_L);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YD_Basic, dt_YD_Basic, YEAR_DAY_ENCODING, DATE_TYPE_dt_YD_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YD_L, dt_YD_L, ANY_YEAR_DAY_ENCODING, DATE_TYPE_dt_YD_L);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YW_Basic, dt_YW_Basic, YEAR_WEEK_ENCODING, DATE_TYPE_dt_YW_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YW_L, dt_YW_L, ANY_YEAR_WEEK_ENCODING, DATE_TYPE_dt_YW_L);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YWD_Basic, dt_YWD_Basic, YEAR_WEEK_DAY_ENCODING, DATE_TYPE_dt_YWD_Basic);
        ITU_T_CHOICEC_DEFN(DATE_TYPE::dt_YWD_L, dt_YWD_L, ANY_YEAR_WEEK_DAY_ENCODING, DATE_TYPE_dt_YWD_L);

        // sequence TIME-TYPE

        TIME_TYPE::TIME_TYPE() : time_type_() {
        };

        TIME_TYPE::TIME_TYPE(const Time_type_type& arg__time_type) :
        time_type_(arg__time_type) {
        };

        TIME_TYPE::TIME_TYPE(ITU_T_SHARED(integer_type) arg__number_of_digits,
                ITU_T_SHARED(Time_type_type) arg__time_type) :
        number_of_digits_(arg__number_of_digits),
        time_type_(arg__time_type) {
        };



        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_H_L, tm_H_L, HOURS_ENCODING, Time_type_type_tm_H_L);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_H_Z, tm_H_Z, HOURS_UTC_ENCODING, Time_type_type_tm_H_Z);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_H_LD, tm_H_LD, HOURS_AND_DIFF_ENCODING, Time_type_type_tm_H_LD);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HM_L, tm_HM_L, MINUTES_ENCODING, Time_type_type_tm_HM_L);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HM_Z, tm_HM_Z, MINUTES_UTC_ENCODING, Time_type_type_tm_HM_Z);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HM_LD, tm_HM_LD, MINUTES_AND_DIFF_ENCODING, Time_type_type_tm_HM_LD);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMS_L, tm_HMS_L, TIME_OF_DAY_ENCODING, Time_type_type_tm_HMS_L);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMS_Z, tm_HMS_Z, TIME_OF_DAY_UTC_ENCODING, Time_type_type_tm_HMS_Z);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMS_LD, tm_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, Time_type_type_tm_HMS_LD);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HFn_L, tm_HFn_L, HOURS_AND_FRACTION_ENCODING, Time_type_type_tm_HFn_L);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HFn_Z, tm_HFn_Z, HOURS_UTC_AND_FRACTION_ENCODING, Time_type_type_tm_HFn_Z);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HFn_LD, tm_HFn_LD, HOURS_AND_DIFF_AND_FRACTION_ENCODING, Time_type_type_tm_HFn_LD);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMFn_L, tm_HMFn_L, MINUTES_AND_FRACTION_ENCODING, Time_type_type_tm_HMFn_L);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMFn_Z, tm_HMFn_Z, MINUTES_UTC_AND_FRACTION_ENCODING, Time_type_type_tm_HMFn_Z);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMFn_LD, tm_HMFn_LD, MINUTES_AND_DIFF_AND_FRACTION_ENCODING, Time_type_type_tm_HMFn_LD);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMFSn_L, tm_HMFSn_L, TIME_OF_DAY_AND_FRACTION_ENCODING, Time_type_type_tm_HMFSn_L);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMFSn_Z, tm_HMFSn_Z, TIME_OF_DAY_UTC_AND_FRACTION_ENCODING, Time_type_type_tm_HMFSn_Z);
        ITU_T_CHOICEC_DEFN(TIME_TYPE::Time_type_type::tm_HMFSn_LD, tm_HMFSn_LD, TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING, Time_type_type_tm_HMFSn_LD);


        ITU_T_OPTIONAL_DEFN(TIME_TYPE::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(TIME_TYPE::time_type, time_type, TIME_TYPE::Time_type_type);

        // std::cout methods

        std::ostream& operator<<(std::ostream& stream, const CENTURY_ENCODING& vl) {
            return stream << "CC : " << static_cast<int> (vl.as_number());
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_CENTURY_ENCODING& vl) {
            return stream << "+CC : " << vl.as_number();
        };

        std::ostream& operator<<(std::ostream& stream, const YEAR_ENCODING& vl) {
            return stream << "YYYY : " << vl.as_number();
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_ENCODING& vl) {
            return stream << "+YYYY : " << vl.as_number();
        };

        std::ostream& operator<<(std::ostream& stream, const YEAR_MONTH_ENCODING& vl) {
            return stream << "YYYYMM" << to_string(vl.year(), 4, '0') << to_string((int) vl.month(), 2, '0');
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_MONTH_ENCODING& vl) {
            return stream << "+YYYYMM" << to_string(vl.year()) << to_string((int) vl.month(), 2, '0');
        };

        std::ostream& operator<<(std::ostream& stream, const DATE_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", month :  " << vl.month();
            stream << ", day :  " << vl.day();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_DATE_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", month :  " << vl.month();
            stream << ", day :  " << vl.day();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const YEAR_DAY_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", day :  " << vl.day();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_DAY_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", day :  " << vl.day();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const YEAR_WEEK_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", week :  " << vl.week();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_WEEK_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", week :  " << vl.week();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const YEAR_WEEK_DAY_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", week :  " << vl.week();
            stream << ", day :  " << vl.day();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_WEEK_DAY_ENCODING& vl) {
            stream << "{ ";
            stream << "year :  " << vl.year();
            stream << ", week :  " << vl.week();
            stream << ", day :  " << vl.day();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const HOURS_ENCODING& vl) {
            stream << "{ ";
            stream << "hour :  " << vl.as_number();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const HOURS_UTC_ENCODING& vl) {
            stream << "{ ";
            stream << "hour :  " << vl.as_number();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const HOURS_AND_DIFF_ENCODING& vl) {
            stream << "{ ";
            stream << "local_hours :  " << vl.local_hours();
            stream << ", time_difference :  " << vl.time_difference();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_DIFFERENCE& vl) {
            stream << "{ ";
            stream << "sign :  " << vl.sign();
            stream << ", hours :  " << vl.hours();
            if (vl.minutes()) stream << ", minutes :  " << *(vl.minutes());
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_UTC_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_ENCODING& vl) {
            stream << "{ ";
            stream << "local_time :  " << vl.local_time();
            stream << ", time_difference :  " << vl.time_difference();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_ENCODING::Local_time_type& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", seconds :  " << vl.seconds();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_UTC_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", seconds :  " << vl.seconds();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_ENCODING& vl) {
            stream << "{ ";
            stream << "local_time :  " << vl.local_time();
            stream << ", time_difference :  " << vl.time_difference();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", seconds :  " << vl.seconds();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const HOURS_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const HOURS_UTC_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const HOURS_AND_DIFF_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "local_hours :  " << vl.local_hours();
            stream << ", fraction :  " << vl.fraction();
            stream << ", time_difference :  " << vl.time_difference();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_UTC_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "local_time :  " << vl.local_time();
            stream << ", time_difference :  " << vl.time_difference();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", seconds :  " << vl.seconds();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_UTC_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", seconds :  " << vl.seconds();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING& vl) {
            stream << "{ ";
            stream << "local_time :  " << vl.local_time();
            stream << ", time_difference :  " << vl.time_difference();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type& vl) {
            stream << "{ ";
            stream << "hours :  " << vl.hours();
            stream << ", minutes :  " << vl.minutes();
            stream << ", seconds :  " << vl.seconds();
            stream << ", fraction :  " << vl.fraction();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const DURATION_INTERVAL_ENCODING& vl) {
            stream << "{ ";
            if (vl.years()) stream << "years :  " << *(vl.years());
            if (vl.months()) stream << ", months :  " << *(vl.months());
            if (vl.weeks()) stream << ", weeks :  " << *(vl.weeks());
            if (vl.days()) stream << ", days :  " << *(vl.days());
            if (vl.hours()) stream << ", hours :  " << *(vl.hours());
            if (vl.minutes()) stream << ", minutes :  " << *(vl.minutes());
            if (vl.seconds()) stream << ", seconds :  " << *(vl.seconds());
            if (vl.fractional_part()) stream << ", fractional_part :  " << *(vl.fractional_part());
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const DURATION_INTERVAL_ENCODING::Fractional_part_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", fractional_value :  " << vl.fractional_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const REC_DURATION_INTERVAL_ENCODING& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING& vl) {
            stream << "{ ";
            switch (vl.type()) {
                case MIXED_ENCODING_date_C_Basic: stream << "date_C_Basic :  " << *(vl.date_C_Basic());
                    break;
                case MIXED_ENCODING_date_C_L: stream << "date_C_L :  " << *(vl.date_C_L());
                    break;
                case MIXED_ENCODING_date_Y_Basic: stream << "date_Y_Basic :  " << *(vl.date_Y_Basic());
                    break;
                case MIXED_ENCODING_date_Y_L: stream << "date_Y_L :  " << *(vl.date_Y_L());
                    break;
                case MIXED_ENCODING_date_YM_Basic: stream << "date_YM_Basic :  " << *(vl.date_YM_Basic());
                    break;
                case MIXED_ENCODING_date_YM_L: stream << "date_YM_L :  " << *(vl.date_YM_L());
                    break;
                case MIXED_ENCODING_date_YMD_Basic: stream << "date_YMD_Basic :  " << *(vl.date_YMD_Basic());
                    break;
                case MIXED_ENCODING_date_YMD_L: stream << "date_YMD_L :  " << *(vl.date_YMD_L());
                    break;
                case MIXED_ENCODING_date_YD_Basic: stream << "date_YD_Basic :  " << *(vl.date_YD_Basic());
                    break;
                case MIXED_ENCODING_date_YD_L: stream << "date_YD_L :  " << *(vl.date_YD_L());
                    break;
                case MIXED_ENCODING_date_YW_Basic: stream << "date_YW_Basic :  " << *(vl.date_YW_Basic());
                    break;
                case MIXED_ENCODING_date_YW_L: stream << "date_YW_L :  " << *(vl.date_YW_L());
                    break;
                case MIXED_ENCODING_date_YWD_Basic: stream << "date_YWD_Basic :  " << *(vl.date_YWD_Basic());
                    break;
                case MIXED_ENCODING_date_YWD_L: stream << "date_YWD_L :  " << *(vl.date_YWD_L());
                    break;
                case MIXED_ENCODING_time_H_L: stream << "time_H_L :  " << *(vl.time_H_L());
                    break;
                case MIXED_ENCODING_time_H_Z: stream << "time_H_Z :  " << *(vl.time_H_Z());
                    break;
                case MIXED_ENCODING_time_H_LD: stream << "time_H_LD :  " << *(vl.time_H_LD());
                    break;
                case MIXED_ENCODING_time_HM_L: stream << "time_HM_L :  " << *(vl.time_HM_L());
                    break;
                case MIXED_ENCODING_time_HM_Z: stream << "time_HM_Z :  " << *(vl.time_HM_Z());
                    break;
                case MIXED_ENCODING_time_HM_LD: stream << "time_HM_LD :  " << *(vl.time_HM_LD());
                    break;
                case MIXED_ENCODING_time_HMS_L: stream << "time_HMS_L :  " << *(vl.time_HMS_L());
                    break;
                case MIXED_ENCODING_time_HMS_Z: stream << "time_HMS_Z :  " << *(vl.time_HMS_Z());
                    break;
                case MIXED_ENCODING_time_HMS_LD: stream << "time_HMS_LD :  " << *(vl.time_HMS_LD());
                    break;
                case MIXED_ENCODING_time_HFn_L: stream << "time_HFn_L :  " << *(vl.time_HFn_L());
                    break;
                case MIXED_ENCODING_time_HFn_Z: stream << "time_HFn_Z :  " << *(vl.time_HFn_Z());
                    break;
                case MIXED_ENCODING_time_HFn_LD: stream << "time_HFn_LD :  " << *(vl.time_HFn_LD());
                    break;
                case MIXED_ENCODING_time_HMFn_L: stream << "time_HMFn_L :  " << *(vl.time_HMFn_L());
                    break;
                case MIXED_ENCODING_time_HMFn_Z: stream << "time_HMFn_Z :  " << *(vl.time_HMFn_Z());
                    break;
                case MIXED_ENCODING_time_HMFn_LD: stream << "time_HMFn_LD :  " << *(vl.time_HMFn_LD());
                    break;
                case MIXED_ENCODING_time_HMFSn_L: stream << "time_HMFSn_L :  " << *(vl.time_HMFSn_L());
                    break;
                case MIXED_ENCODING_time_HMFSn_Z: stream << "time_HMFSn_Z :  " << *(vl.time_HMFSn_Z());
                    break;
                case MIXED_ENCODING_time_HMFSn_LD: stream << "time_HMFSn_LD :  " << *(vl.time_HMFSn_LD());
                    break;
                case MIXED_ENCODING_date_time: stream << "date_time :  " << *(vl.date_time());
                    break;
                case MIXED_ENCODING_iterval_SE_Date: stream << "iterval_SE_Date :  " << *(vl.iterval_SE_Date());
                    break;
                case MIXED_ENCODING_iterval_SE_Time: stream << "iterval_SE_Time :  " << *(vl.iterval_SE_Time());
                    break;
                case MIXED_ENCODING_iterval_SE_Date_Time: stream << "iterval_SE_Date_Time :  " << *(vl.iterval_SE_Date_Time());
                    break;
                case MIXED_ENCODING_iterval_D: stream << "iterval_D :  " << *(vl.iterval_D());
                    break;
                case MIXED_ENCODING_iterval_SD_Date: stream << "iterval_SD_Date :  " << *(vl.iterval_SD_Date());
                    break;
                case MIXED_ENCODING_iterval_SD_Time: stream << "iterval_SD_Time :  " << *(vl.iterval_SD_Time());
                    break;
                case MIXED_ENCODING_iterval_SD_Date_Time: stream << "iterval_SD_Date_Time :  " << *(vl.iterval_SD_Date_Time());
                    break;
                case MIXED_ENCODING_iterval_DE_Date: stream << "iterval_DE_Date :  " << *(vl.iterval_DE_Date());
                    break;
                case MIXED_ENCODING_iterval_DE_Time: stream << "iterval_DE_Time :  " << *(vl.iterval_DE_Time());
                    break;
                case MIXED_ENCODING_iterval_DE_Date_Time: stream << "iterval_DE_Date_Time :  " << *(vl.iterval_DE_Date_Time());
                    break;
                case MIXED_ENCODING_rec_Interval_SE_Date: stream << "rec_Interval_SE_Date :  " << *(vl.rec_Interval_SE_Date());
                    break;
                case MIXED_ENCODING_rec_Interval_SE_Time: stream << "rec_Interval_SE_Time :  " << *(vl.rec_Interval_SE_Time());
                    break;
                case MIXED_ENCODING_rec_Interval_SE_Date_Time: stream << "rec_Interval_SE_Date_Time :  " << *(vl.rec_Interval_SE_Date_Time());
                    break;
                case MIXED_ENCODING_rec_Interval_D: stream << "rec_Interval_D :  " << *(vl.rec_Interval_D());
                    break;
                case MIXED_ENCODING_rec_Interval_SD_Date: stream << "rec_Interval_SD_Date :  " << *(vl.rec_Interval_SD_Date());
                    break;
                case MIXED_ENCODING_rec_Interval_SD_Time: stream << "rec_Interval_SD_Time :  " << *(vl.rec_Interval_SD_Time());
                    break;
                case MIXED_ENCODING_rec_Interval_SD_Date_Time: stream << "rec_Interval_SD_Date_Time :  " << *(vl.rec_Interval_SD_Date_Time());
                    break;
                case MIXED_ENCODING_rec_Interval_DE_Date: stream << "rec_Interval_DE_Date :  " << *(vl.rec_Interval_DE_Date());
                    break;
                case MIXED_ENCODING_rec_Interval_DE_Time: stream << "rec_Interval_DE_Time :  " << *(vl.rec_Interval_DE_Time());
                    break;
                case MIXED_ENCODING_rec_Interval_DE_Date_Time: stream << "rec_Interval_DE_Date_Time :  " << *(vl.rec_Interval_DE_Date_Time());
                    break;
                default:
                {
                    stream << " null ";
                }
            };
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HFn_L_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HFn_Z_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HFn_LD_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFn_L_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFn_Z_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFn_LD_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFSn_L_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFSn_Z_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFSn_LD_type& vl) {
            stream << "{ ";
            stream << "number_of_digits :  " << vl.number_of_digits();
            stream << ", time_value :  " << vl.time_value();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Date_time_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_type& vl) {
            stream << "{ ";
            stream << "start :  " << vl.start();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Time_type& vl) {
            stream << "{ ";
            stream << "start :  " << vl.start();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_Time_type& vl) {
            stream << "{ ";
            stream << "start :  " << vl.start();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Date_type& vl) {
            stream << "{ ";
            stream << "start :  " << vl.start();
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Time_type& vl) {
            stream << "{ ";
            stream << "start :  " << vl.start();
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Date_Time_type& vl) {
            stream << "{ ";
            stream << "start :  " << vl.start();
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Date_type& vl) {
            stream << "{ ";
            stream << "duration :  " << vl.duration();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Time_type& vl) {
            stream << "{ ";
            stream << "duration :  " << vl.duration();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Date_Time_type& vl) {
            stream << "{ ";
            stream << "duration :  " << vl.duration();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", start :  " << vl.start();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Time_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", start :  " << vl.start();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_Time_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", start :  " << vl.start();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Date_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", start :  " << vl.start();
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Time_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", start :  " << vl.start();
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Date_Time_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", start :  " << vl.start();
            stream << ", duration :  " << vl.duration();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Date_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", duration :  " << vl.duration();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Time_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", duration :  " << vl.duration();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Date_Time_type& vl) {
            stream << "{ ";
            if (vl.recurrence()) stream << "recurrence :  " << *(vl.recurrence());
            stream << ", duration :  " << vl.duration();
            stream << ", end :  " << vl.end();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type& vl) {
            stream << "{ ";
            stream << "date :  " << vl.date();
            stream << ", time :  " << vl.time();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const DATE_TYPE& vl) {
            stream << "{ ";
            switch (vl.type()) {
                case DATE_TYPE_dt_C_Basic: stream << "dt_C_Basic :  " << *(vl.dt_C_Basic());
                    break;
                case DATE_TYPE_dt_C_L: stream << "dt_C_L :  " << *(vl.dt_C_L());
                    break;
                case DATE_TYPE_dt_Y_Basic: stream << "dt_Y_Basic :  " << *(vl.dt_Y_Basic());
                    break;
                case DATE_TYPE_dt_Y_L: stream << "dt_Y_L :  " << *(vl.dt_Y_L());
                    break;
                case DATE_TYPE_dt_YM_Basic: stream << "dt_YM_Basic :  " << *(vl.dt_YM_Basic());
                    break;
                case DATE_TYPE_dt_YM_L: stream << "dt_YM_L :  " << *(vl.dt_YM_L());
                    break;
                case DATE_TYPE_dt_YMD_Basic: stream << "dt_YMD_Basic :  " << *(vl.dt_YMD_Basic());
                    break;
                case DATE_TYPE_dt_YMD_L: stream << "dt_YMD_L :  " << *(vl.dt_YMD_L());
                    break;
                case DATE_TYPE_dt_YD_Basic: stream << "dt_YD_Basic :  " << *(vl.dt_YD_Basic());
                    break;
                case DATE_TYPE_dt_YD_L: stream << "dt_YD_L :  " << *(vl.dt_YD_L());
                    break;
                case DATE_TYPE_dt_YW_Basic: stream << "dt_YW_Basic :  " << *(vl.dt_YW_Basic());
                    break;
                case DATE_TYPE_dt_YW_L: stream << "dt_YW_L :  " << *(vl.dt_YW_L());
                    break;
                case DATE_TYPE_dt_YWD_Basic: stream << "dt_YWD_Basic :  " << *(vl.dt_YWD_Basic());
                    break;
                case DATE_TYPE_dt_YWD_L: stream << "dt_YWD_L :  " << *(vl.dt_YWD_L());
                    break;
                default:
                {
                    stream << " null ";
                }
            };
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_TYPE& vl) {
            stream << "{ ";
            if (vl.number_of_digits()) stream << "number_of_digits :  " << *(vl.number_of_digits());
            stream << ", time_type :  " << vl.time_type();
            stream << " }";
            return stream;
        };

        std::ostream& operator<<(std::ostream& stream, const TIME_TYPE::Time_type_type& vl) {
            stream << "{ ";
            switch (vl.type()) {
                case TIME_TYPE::Time_type_type_tm_H_L: stream << "tm_H_L :  " << *(vl.tm_H_L());
                    break;
                case TIME_TYPE::Time_type_type_tm_H_Z: stream << "tm_H_Z :  " << *(vl.tm_H_Z());
                    break;
                case TIME_TYPE::Time_type_type_tm_H_LD: stream << "tm_H_LD :  " << *(vl.tm_H_LD());
                    break;
                case TIME_TYPE::Time_type_type_tm_HM_L: stream << "tm_HM_L :  " << *(vl.tm_HM_L());
                    break;
                case TIME_TYPE::Time_type_type_tm_HM_Z: stream << "tm_HM_Z :  " << *(vl.tm_HM_Z());
                    break;
                case TIME_TYPE::Time_type_type_tm_HM_LD: stream << "tm_HM_LD :  " << *(vl.tm_HM_LD());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMS_L: stream << "tm_HMS_L :  " << *(vl.tm_HMS_L());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMS_Z: stream << "tm_HMS_Z :  " << *(vl.tm_HMS_Z());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMS_LD: stream << "tm_HMS_LD :  " << *(vl.tm_HMS_LD());
                    break;
                case TIME_TYPE::Time_type_type_tm_HFn_L: stream << "tm_HFn_L :  " << *(vl.tm_HFn_L());
                    break;
                case TIME_TYPE::Time_type_type_tm_HFn_Z: stream << "tm_HFn_Z :  " << *(vl.tm_HFn_Z());
                    break;
                case TIME_TYPE::Time_type_type_tm_HFn_LD: stream << "tm_HFn_LD :  " << *(vl.tm_HFn_LD());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMFn_L: stream << "tm_HMFn_L :  " << *(vl.tm_HMFn_L());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMFn_Z: stream << "tm_HMFn_Z :  " << *(vl.tm_HMFn_Z());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMFn_LD: stream << "tm_HMFn_LD :  " << *(vl.tm_HMFn_LD());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMFSn_L: stream << "tm_HMFSn_L :  " << *(vl.tm_HMFSn_L());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMFSn_Z: stream << "tm_HMFSn_Z :  " << *(vl.tm_HMFSn_Z());
                    break;
                case TIME_TYPE::Time_type_type_tm_HMFSn_LD: stream << "tm_HMFSn_LD :  " << *(vl.tm_HMFSn_LD());
                    break;
                default:
                {
                    stream << " null ";
                }
            };
            stream << " }";
            return stream;
        };

    }
}

#define ITU_T_DEFINE_TIME_TYPE(nm) void output_coder::operator&(const nm & vl) {\
                direct_serialize(vl, *this);}\
            void input_coder::operator&( nm & vl) {\
                direct_serialize(vl, *this); }                

namespace boost {
    namespace asn1 {
        namespace x690 {

            ITU_T_DEFINE_TIME_TYPE(CENTURY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_CENTURY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_YEAR_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_MONTH_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_YEAR_MONTH_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DATE_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_DATE_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_YEAR_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_WEEK_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_YEAR_WEEK_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_WEEK_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(ANY_YEAR_WEEK_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_UTC_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_AND_DIFF_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_DIFFERENCE);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_UTC_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_AND_DIFF_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_UTC_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_AND_DIFF_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_UTC_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_AND_DIFF_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_UTC_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_AND_DIFF_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DURATION_INTERVAL_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(REC_DURATION_INTERVAL_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MIXED_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DATE_TYPE);
            ITU_T_DEFINE_TIME_TYPE(TIME_TYPE);

        }
    }
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

