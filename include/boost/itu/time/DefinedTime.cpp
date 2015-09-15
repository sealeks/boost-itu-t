
#include <string>

#include "DefinedTime.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif


namespace boost {
    namespace asn1 {

        namespace time_detail {




            // reverse substring |sssssssss|sssssss|sssssssssssss|
            //                                  bg                 beg    sz                                  end        
            // ,    if sz=0, full size from beg    

            std::string drct_substr(const std::string& vl, std::string::size_type beg, std::string::size_type sz) {
                std::string::size_type size = vl.size();
                if (beg < size) {
                    if (sz)
                        return vl.substr(beg, ((beg + sz) < size) ? sz : (size - beg));
                    else
                        return vl.substr(beg);
                }
                return "";
            }

            std::string drct_substr(const visible_string& vl, std::string::size_type beg, std::string::size_type sz) {
                return drct_substr(std::string(vl.c_str()), beg, sz);
            }


            // reverse substring |sssssssss|sssssss|sssssssssssss|
            //                                beg                 bgs       eps                 end        
            // endps=end-eps, sz=eps-bgs,    if sz=0, full size from beg    

            std::string revrs_substr(const std::string& vl, std::string::size_type endps, std::string::size_type sz) {
                std::string::size_type size = vl.size();
                if (endps < size) {
                    if (sz)
                        return vl.substr((((size - endps) > sz) ? (size - endps - sz) : 0),
                            ((size - endps) > sz) ? sz : (size - endps));
                    else
                        return vl.substr(0, size - endps);
                }
                return "";
            }

            std::string revrs_substr(const visible_string& vl, std::string::size_type endps, std::string::size_type sz) {
                return revrs_substr(std::string(vl.c_str()), endps, sz);
            }

            std::string get_str_marker(const std::string& vl, std::string::value_type markchar) {
                std::string::size_type fit = vl.find_first_of(markchar);
                if (fit != std::string::npos) {
                    std::string subvl = vl.substr(0, fit);
                    std::string::size_type sit = subvl.find_last_not_of("0123456789+-");
                    if (sit != std::string::npos)
                        return subvl.substr(sit + 1);
                    return subvl;
                }
                return "";
            }

            integer_type get_numstr_marker(const std::string& vl, std::string::value_type markchar) {
                return string_to_def<integer_type>(get_str_marker(vl, markchar));
            }

            std::string normalize_str_size(const std::string& vl, std::string::size_type sz) {
                if (vl.size() == sz)
                    return vl;
                else if (vl.size() > sz)
                    return vl.substr(0, sz);
                else
                    return vl + std::string(sz - vl.size(), '0');
            }

            std::string normalize_time_str(std::string vl) {
                boost::algorithm::erase_last(vl, "\"");
                boost::algorithm::erase_first(vl, "\"");
                bool hassign = (!vl.empty() && vl[0] == '-');
                boost::algorithm::erase_all(vl, "-");
                boost::algorithm::erase_all(vl, ":");
                boost::algorithm::replace_all(vl, ".", ",");
                if (hassign)
                    return "-" + vl;
                return vl;
            }

            std::string normalizeLR_time_str(std::string vl) {
                boost::algorithm::erase_last(vl, "\"");
                boost::algorithm::erase_first(vl, "\"");
                boost::algorithm::erase_first(vl, "-");
                boost::algorithm::replace_all(vl, ".", ",");
                return vl;
            }

            uint64_t pow10(std::size_t n) {
                if (n) {
                    uint64_t rslt = 10;
                    std::size_t k = 1;
                    while ((k * 2) <= n) {
                        rslt *= rslt;
                        k *= 2;
                    }
                    if (k < n)
                        rslt *= pow10(n - k);
                    return rslt;
                }
                return 1;
            }

            std::size_t minute_fraction_HF(integer_type f, std::size_t n) {
                if (n > 0)
                    return ((static_cast<uint64_t> (f) * 6) / pow10(n - 1)) % 60;
                return 0;
            }

            std::size_t second_fraction_HF(integer_type f, std::size_t n) {
                if (n > 1)
                    return ((static_cast<uint64_t> (f) * 36) /
                            static_cast<uint64_t> (pow10(n - 2))) % 60;
                return 0;
            }

            std::size_t microsecond_fraction_HF(integer_type f, std::size_t n) {
                if (n > 2) {
                    uint64_t r = static_cast<uint64_t> (f);
                    if (n < 9)
                        return ((r * 36 * pow10(8 - n)) -((r * 36) / pow10(n - 2))*1000000) % 1000000;
                    else
                        return ((r * 36 / pow10(n - 8)) -((r * 36) / pow10(n - 2))*1000000) % 1000000;
                }
                return 0;
            }

            std::size_t nanosecond_fraction_HF(integer_type f, std::size_t n) {
                if (n > 2) {
                    uint64_t r = static_cast<uint64_t> (f);
                    if (n < 12)
                        return ((r * 36 * pow10(11 - n)) -((r * 36) / pow10(n - 2))*1000000000) % 1000000000;
                    else
                        return ((r * 36 / pow10(n - 11)) -((r * 36) / pow10(n - 2))*1000000000) % 1000000000;
                }
                return 0;
            }

            std::size_t second_fraction_HMF(integer_type f, std::size_t n) {
                if (n > 0)
                    return ((static_cast<uint64_t> (f) * 6) / pow10(n - 1)) % 60;
                return 0;
            }

            std::size_t microsecond_fraction_HMF(integer_type f, std::size_t n) {
                if (n > 1) {
                    uint64_t r = static_cast<uint64_t> (f);
                    if (n < 8)
                        return ((r * 6 * pow10(7 - n)) -((r * 6) / pow10(n - 1))*1000000) % 1000000;
                    else
                        return ((r * 6 / pow10(n - 7)) -((r * 6) / pow10(n - 1))*1000000) % 1000000;
                }
                return 0;
            }

            std::size_t nanosecond_fraction_HMF(integer_type f, std::size_t n) {
                if (n > 1) {
                    uint64_t r = static_cast<uint64_t> (f);
                    if (n < 11)
                        return ((r * 6 * pow10(10 - n)) -((r * 6) / pow10(n - 1))*1000000000) % 1000000000;
                    else
                        return ((r * 6 / pow10(n - 10)) -((r * 6) / pow10(n - 1))*1000000000) % 1000000000;
                }
                return 0;
            }

            std::size_t microsecond_fraction_HMSF(integer_type f, std::size_t n) {
                if (n > 0) {
                    if (n < 6)
                        return (pow10(6 - n) * static_cast<uint64_t> (f)) % 1000000;
                    else
                        return (static_cast<uint64_t> (f) / pow10(n - 6)) % 1000000;
                }
                return 0;
            }

            std::size_t nanosecond_fraction_HMSF(integer_type f, std::size_t n) {
                if (n > 0) {
                    if (n < 9)
                        return (pow10(9 - n) * static_cast<uint64_t> (f)) % 1000000000;
                    else
                        return (static_cast<uint64_t> (f) / pow10(n - 9)) % 1000000000;
                }
                return 0;
            }

            integer_type HF_to_fraction(base_time_duration dtd, std::size_t n) {
                if (!dtd.is_special() && n) {
                    if (dtd.hours())
                        dtd = dtd - base_time_duration(dtd.hours(), 0, 0);
                    if (n < 9)
                        return dtd.total_microseconds() / (36 * pow10(8 - n));
                    else
                        return (dtd.total_microseconds() * pow10(n - 8)) / 36;
                }
                return 0;
            }

            integer_type HMF_to_fraction(base_time_duration dtd, std::size_t n) {
                if (!dtd.is_special() && n) {
                    if (dtd.minutes() || dtd.hours())
                        dtd = dtd - base_time_duration(dtd.hours(), dtd.minutes(), 0);
                    if (n < 8)
                        return dtd.total_microseconds() / (6 * pow10(7 - n));
                    else
                        return (dtd.total_microseconds() * pow10(n - 7)) / 6;
                }
                return 0;
            }

            integer_type HMSF_to_fraction(base_time_duration dtd, std::size_t n) {
                if (!dtd.is_special() && n) {
                    if (dtd.minutes() || dtd.hours() || dtd.seconds())
                        dtd = dtd - base_time_duration(dtd.hours(), dtd.minutes(), dtd.seconds());
                    if (n < 7)
                        return dtd.total_microseconds() / (pow10(6 - n));
                    else
                        return (dtd.total_microseconds() * pow10(n - 6));
                }
                return 0;
            }

        }

        using namespace time_detail;

        // sequence CENTURY-ENCODING

        CENTURY_ENCODING::CENTURY_ENCODING() : as_number_(0) {
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const uint8_t& arg__val) :
        as_number_(to_range(arg__val, (uint8_t) 0, (uint8_t) 99)) {
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const std::string& vl) :
        as_number_(0) {
            as_string(vl);
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const char* vl) :
        as_number_(0) {
            as_string(vl);
        };

        CENTURY_ENCODING::CENTURY_ENCODING(const base_date& vl) :
        as_number_(to_range<uint8_t>(vl.is_special() ? 0 : (vl.year() / 100), (uint8_t) 0, (uint8_t) 99)) {
        }

        base_date CENTURY_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (as_number())*100, 1, 1);
            }
            catch (...) {
            }
            return base_date();
        }

        std::string CENTURY_ENCODING::as_string() const {
            return to_string(static_cast<int> (as_number()), 2, '0') + "C";
        }

        void CENTURY_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            as_number(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 1), 0, "0"),
                                        (uint8_t) 0, (uint8_t) 99));
        }


        ITU_T_HOLDERH_DEFN(CENTURY_ENCODING::as_number, as_number, uint8_t);




        // sequence ANY-CENTURY-ENCODING

        // choice YEAR-ENCODING

        YEAR_ENCODING::YEAR_ENCODING(integer_type vl) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_number(vl);
        }

        YEAR_ENCODING::YEAR_ENCODING(const std::string& vl) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_string(vl);
        }

        YEAR_ENCODING::YEAR_ENCODING(const char* vl) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_string(vl);
        }

        YEAR_ENCODING::YEAR_ENCODING(const base_date& v) :
        ITU_T_CHOICE_CTORS_INHERITED(YEAR_ENCODING) {
            as_number(v.is_special() ? 0 : (integer_type) v.year());
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

        base_date YEAR_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (as_number()), 1, 1);
            }
            catch (...) {
            }
            return base_date();
        }

        std::string YEAR_ENCODING::as_string() const {
            return to_string(static_cast<int> (as_number()), 4, '0');
        }

        void YEAR_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            as_number(to_range<integer_type>(string_to_def<int>(vl, 0, "0"),
                                             (integer_type) 0, (integer_type) 9999));
        }


        // sequence ANY-YEAR-ENCODING

        // sequence YEAR-MONTH-ENCODING

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING() : year_(), month_(1) {
        };

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(integer_type arg__year,
                const uint8_t& arg__month) :
        year_(arg__year), month_(to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)) {
        };

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(const std::string& vl) : year_(), month_(1) {
            as_string(vl);
        }

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(const char* vl) : year_(), month_(1) {
            as_string(vl);
        }

        YEAR_MONTH_ENCODING::YEAR_MONTH_ENCODING(const base_date& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.year()),
        month_(vl.is_special() ? 1 : (uint8_t) vl.month()) {
        }

        base_date YEAR_MONTH_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (year().as_number()), (int) month(), 1);
            }
            catch (...) {
            }
            return base_date();
        }

        std::string YEAR_MONTH_ENCODING::as_string() const {
            return year().as_string() + "-" + to_string(static_cast<int> (month()), 2, '0');
        }

        void YEAR_MONTH_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            year(revrs_substr(vl, 2));
            month(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 12));
        }

        ITU_T_HOLDERH_DEFN(YEAR_MONTH_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_MONTH_ENCODING::month, month, uint8_t);




        // sequence ANY-YEAR-MONTH-ENCODING

        // sequence DATE-ENCODING

        DATE_ENCODING::DATE_ENCODING() : year_(), month_(1), day_(1) {
        };

        DATE_ENCODING::DATE_ENCODING(integer_type arg__year,
                const uint8_t& arg__month,
                const uint8_t& arg__day) :
        year_(arg__year),
        month_(to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)),
        day_(to_range<uint8_t>(arg__day, (uint8_t) 1, (uint8_t) 31)) {
        };

        DATE_ENCODING::DATE_ENCODING(const std::string& vl) : year_(), month_(1), day_(1) {
            as_string(vl);
        }

        DATE_ENCODING::DATE_ENCODING(const char* vl) : year_(), month_(1), day_(1) {
            as_string(vl);
        }

        DATE_ENCODING::DATE_ENCODING(const base_date& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.year()),
        month_(vl.is_special() ? 1 : (uint8_t) vl.month()),
        day_(vl.is_special() ? 1 : (uint8_t) vl.day()) {
        }

        base_date DATE_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (year().as_number()), (int) month(), (int) day());
            }
            catch (...) {
            }
            return base_date();
        }

        std::string DATE_ENCODING::as_string() const {
            return year().as_string() + "-" + to_string(static_cast<int> (month()), 2, '0') +
                    "-" + to_string(static_cast<int> (day()), 2, '0');
        }

        void DATE_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            year(revrs_substr(vl, 4));
            month(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 2, 2)), (uint8_t) 1, (uint8_t) 12));
            day(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 31));
        }

        ITU_T_HOLDERH_DEFN(DATE_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(DATE_ENCODING::month, month, uint8_t);
        ITU_T_HOLDERH_DEFN(DATE_ENCODING::day, day, uint8_t);







        // sequence DATE-ENCODING

        DATE::DATE() : year_(), month_(1), day_(1) {
        };

        DATE::DATE(integer_type arg__year,
                const uint8_t& arg__month,
                const uint8_t& arg__day) :
        year_(arg__year),
        month_(to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)),
        day_(to_range<uint8_t>(arg__day, (uint8_t) 1, (uint8_t) 31)) {
        };

        DATE::DATE(const std::string& vl) : year_(), month_(1), day_(1) {
            as_string(vl);
        }

        DATE::DATE(const char* vl) : year_(), month_(1), day_(1) {
            as_string(vl);
        }

        DATE::DATE(const base_date& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.year()),
        month_(vl.is_special() ? 1 : (uint8_t) vl.month()),
        day_(vl.is_special() ? 1 : (uint8_t) vl.day()) {
        }

        base_date DATE::as_date() const {
            try {
                return base_date(static_cast<int> (year().as_number()), (int) month(), (int) day());
            }
            catch (...) {
            }
            return base_date();
        }

        std::string DATE::as_string() const {
            return year().as_string() + "-" + to_string(static_cast<int> (month()), 2, '0') +
                    "-" + to_string(static_cast<int> (day()), 2, '0');
        }

        void DATE::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            year(revrs_substr(vl, 4));
            month(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 2, 2)), (uint8_t) 1, (uint8_t) 12));
            day(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 31));
        }

        ITU_T_HOLDERH_DEFN(DATE::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(DATE::month, month, uint8_t);
        ITU_T_HOLDERH_DEFN(DATE::day, day, uint8_t);





        // sequence ANY-DATE-ENCODING

        // sequence YEAR-DAY-ENCODING

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING() : year_(), day_(1) {
        };

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING(integer_type arg__year,
                const uint16_t& arg__day) :
        year_(arg__year),
        day_(to_range<uint16_t>(arg__day, (uint16_t) 1, (uint16_t) 366)) {
        };

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING(const std::string& vl) : year_(), day_(1) {
            as_string(vl);
        }

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING(const char* vl) : year_(), day_(1) {
            as_string(vl);
        }

        YEAR_DAY_ENCODING::YEAR_DAY_ENCODING(const base_date& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.year()),
        day_(vl.is_special() ? 1 : (uint16_t) vl.day_of_year()) {
        }

        base_date YEAR_DAY_ENCODING::as_date() const {
            try {
                return base_date(static_cast<int> (year().as_number()), 1, 1) +
                        base_date_time::date_duration_type(day() ? day() - 1 : 0);
            }
            catch (...) {
            }
            return base_date();
        }

        std::string YEAR_DAY_ENCODING::as_string() const {
            return year().as_string() + "-" + to_string(static_cast<int> (day()), 3, '0');
        }

        void YEAR_DAY_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            year(revrs_substr(vl, 3));
            day(to_range<uint16_t>(string_to_def<int>(revrs_substr(vl, 0, 3)), (uint16_t) 1, (uint16_t) 366));
        }


        ITU_T_HOLDERH_DEFN(YEAR_DAY_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_DAY_ENCODING::day, day, uint16_t);





        // sequence ANY-YEAR-DAY-ENCODING

        // sequence YEAR-WEEK-ENCODING

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING() : year_(), week_(1) {
        };

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING(const YEAR_ENCODING& arg__year,
                const uint8_t& arg__week) :
        year_(arg__year),
        week_(to_range<uint8_t>(arg__week, (uint8_t) 1, (uint8_t) 53)) {
        };

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING(const std::string& vl) : year_(), week_(1) {
            as_string(vl);
        }

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING(const char* vl) : year_(), week_(1) {
            as_string(vl);
        }

        YEAR_WEEK_ENCODING::YEAR_WEEK_ENCODING(const base_date& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.year()),
        week_(vl.is_special() ? 1 : (uint8_t) vl.week_number()) {
        }

        base_date YEAR_WEEK_ENCODING::as_date() const {
            try {
                base_date tmp(static_cast<int> (year().as_number()), 1, 1);
                std::size_t dwst = (std::size_t)tmp.day_of_week();
                return tmp + base_date_time::date_duration_type((dwst > 4) ? (8 - dwst) : (1 - dwst)) +
                        base_date_time::date_duration_type((week() > 1) ? (7 * (week() - 1)) : 0);
            }
            catch (...) {
            }
            return base_date();
        }

        std::string YEAR_WEEK_ENCODING::as_string() const {
            return year().as_string() + "-W" + to_string(static_cast<int> (week()), 2, '0');
        }

        void YEAR_WEEK_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            year(revrs_substr(vl, 3));
            week(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 53));
        }



        ITU_T_HOLDERH_DEFN(YEAR_WEEK_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_WEEK_ENCODING::week, week, uint8_t);







        // sequence ANY-YEAR-WEEK-ENCODING

        // sequence YEAR-WEEK-DAY-ENCODING

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING() : year_(), week_(1), day_(1) {
        };

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING(const YEAR_ENCODING& arg__year,
                const uint8_t& arg__week,
                const uint8_t& arg__day) :
        year_(arg__year),
        week_(to_range<uint8_t>(arg__week, (uint8_t) 1, (uint8_t) 53)),
        day_(to_range<uint8_t>(arg__day, (uint8_t) 1, (uint8_t) 7)) {
        };

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING(const std::string& vl) : year_(), week_(1) {
            as_string(vl);
        }

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING(const char* vl) : year_(), week_(1) {
            as_string(vl);
        }

        YEAR_WEEK_DAY_ENCODING::YEAR_WEEK_DAY_ENCODING(const base_date& vl) :
        year_(vl.is_special() ? 0 : (integer_type) vl.year()),
        week_(vl.is_special() ? 1 : (uint8_t) vl.week_number()),
        day_(vl.is_special() ? 1 : (uint8_t) vl.day_of_week()) {
        }

        base_date YEAR_WEEK_DAY_ENCODING::as_date() const {
            try {
                base_date tmp(static_cast<int> (year().as_number()), 1, 1);
                std::size_t dwst = (std::size_t)tmp.day_of_week();
                return tmp + base_date_time::date_duration_type((dwst > 4) ? (8 - dwst) : (1 - dwst)) +
                        base_date_time::date_duration_type(((week() > 1) ? (7 * (week() - 1)) : 0) + ((day() > 1) ? (day() - 1) : 0));
            }
            catch (...) {
            }
            return base_date();
        }

        std::string YEAR_WEEK_DAY_ENCODING::as_string() const {
            return year().as_string() + "-W" + to_string(static_cast<int> (week()), 2, '0') +
                    "-" + to_string(static_cast<int> (day()), 1);
        }

        void YEAR_WEEK_DAY_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            year(revrs_substr(vl, 4));
            week(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 1, 2)), (uint8_t) 1, (uint8_t) 53));
            day(to_range<uint8_t>(string_to_def<int>(revrs_substr(vl, 0, 1)), (uint8_t) 1, (uint8_t) 7));
        }


        ITU_T_HOLDERH_DEFN(YEAR_WEEK_DAY_ENCODING::year, year, YEAR_ENCODING);
        ITU_T_HOLDERH_DEFN(YEAR_WEEK_DAY_ENCODING::week, week, uint8_t);
        ITU_T_HOLDERH_DEFN(YEAR_WEEK_DAY_ENCODING::day, day, uint8_t);







        // sequence ANY-YEAR-WEEK-DAY-ENCODING

        // sequence HOURS-ENCODING

        HOURS_ENCODING::HOURS_ENCODING() : as_number_() {
        };

        HOURS_ENCODING::HOURS_ENCODING(const uint8_t& arg__val) :
        as_number_(to_range(arg__val, (uint8_t) 0, (uint8_t) 24)) {
        };

        HOURS_ENCODING::HOURS_ENCODING(const std::string& vl) :
        as_number_(0) {
            as_string(vl);
        };

        HOURS_ENCODING::HOURS_ENCODING(const char* vl) :
        as_number_(0) {
            as_string(vl);
        };

        HOURS_ENCODING::HOURS_ENCODING(const base_time_duration& vl) :
        as_number_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)) {
        };

        base_time_duration HOURS_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (as_number()), 0, 0);
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string HOURS_ENCODING::as_string() const {
            return to_string(static_cast<int> (as_number()), 2, '0');
        }

        void HOURS_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            as_number(to_range<uint8_t>(string_to_def<int>(vl, 0, "0"), (uint8_t) 0, (uint8_t) 24));
        }


        ITU_T_HOLDERH_DEFN(HOURS_ENCODING::as_number, as_number, uint8_t);





        // sequence HOURS-UTC-ENCODING

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING() : as_number_() {
        };

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING(const uint8_t& arg__val) :
        as_number_(to_range(arg__val, (uint8_t) 0, (uint8_t) 24)) {
        };

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING(const std::string& vl) :
        as_number_(0) {
            as_string(vl);
        };

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING(const char* vl) :
        as_number_(0) {
            as_string(vl);
        };

        HOURS_UTC_ENCODING::HOURS_UTC_ENCODING(const base_time_duration& vl) :
        as_number_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)) {
        };

        base_time_duration HOURS_UTC_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (as_number()), 0, 0);
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string HOURS_UTC_ENCODING::as_string() const {
            return to_string(static_cast<int> (as_number()), 2, '0') + "Z";
        }

        void HOURS_UTC_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            as_number(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
        }



        ITU_T_HOLDERH_DEFN(HOURS_UTC_ENCODING::as_number, as_number, uint8_t);






        // sequence TIME-DIFFERENCE
        const enumerated TIME_DIFFERENCE::sign_positive = 0;
        const enumerated TIME_DIFFERENCE::sign_negative = 1;

        TIME_DIFFERENCE::TIME_DIFFERENCE() : sign_(), hours_() {
        };

        TIME_DIFFERENCE::TIME_DIFFERENCE(const int8_t& arg__hours,
                const uint8_t& arg__minutes) :
        sign_(arg__hours < 0 ? sign_negative : sign_positive),
        hours_(static_cast<uint8_t> (std::abs(to_range<int8_t>(arg__minutes, (int8_t) (-15), (int8_t) 15)))) {
            if (arg__minutes)
                minutes(to_range<uint8_t>(arg__minutes, (uint8_t) 1, (uint8_t) 59));
        };

        TIME_DIFFERENCE::TIME_DIFFERENCE(const std::string& vl) : sign_(), hours_() {
            as_string(vl);
        };

        TIME_DIFFERENCE::TIME_DIFFERENCE(const char* vl) : sign_(), hours_() {
            as_string(vl);
        };

        /*TIME_DIFFERENCE::TIME_DIFFERENCE(const base_time_duration& vl) :
        as_number_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)) {
        };


        base_time_duration TIME_DIFFERENCE::as_time() const {
            try {
                return base_time_duration(static_cast<int> (as_number()),0,0);
            } catch (...) {
            }
            return base_time_duration();
        }*/

        std::string TIME_DIFFERENCE::as_string() const {
            std::string rslt(sign() == sign_positive ? "+" : "-");
            rslt += to_string(static_cast<int> (hours()), 2, '0');
            if (minutes())
                rslt += (":" + to_string(static_cast<int> (*minutes()), 2, '0'));
            return rslt;
        }

        void TIME_DIFFERENCE::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            sign((!vl.empty() && vl[0] == '-') ? sign_negative : sign_positive);
            hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 1, 2), 0, "0"), (uint8_t) 0, (uint8_t) 15));
            if (vl.size() > 3)
                minutes(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 3, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
        }


        ITU_T_HOLDERH_DEFN(TIME_DIFFERENCE::sign, sign, enumerated);
        ITU_T_HOLDERH_DEFN(TIME_DIFFERENCE::hours, hours, uint8_t);
        ITU_T_OPTIONAL_DEFN(TIME_DIFFERENCE::minutes, minutes, uint8_t);

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x690::output_coder& arch) {
            time_serialize(*this, arch);
        }

        template<> void TIME_DIFFERENCE::serialize(boost::asn1::x690::input_coder& arch) {
            time_serialize(*this, arch);
        }

        // sequence HOURS-AND-DIFF-ENCODING

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING() : local_hours_(), time_difference_() {
        };

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING(const uint8_t& arg__local_hours,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_hours_(to_range(arg__local_hours, (uint8_t) 0, (uint8_t) 24)),
        time_difference_(arg__time_difference) {
        };

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING(const std::string& vl)
        : local_hours_(), time_difference_() {
            as_string(vl);
        };

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING(const char* vl)
        : local_hours_(), time_difference_() {
            as_string(vl);
        };

        HOURS_AND_DIFF_ENCODING::HOURS_AND_DIFF_ENCODING(const base_time_duration& vl)
        : local_hours_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
        time_difference_() {
        };

        base_time_duration HOURS_AND_DIFF_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (local_hours()), 0, 0);
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string HOURS_AND_DIFF_ENCODING::as_string() const {
            return to_string(static_cast<int> (local_hours()), 2, '0') + time_difference().as_string();
        }

        void HOURS_AND_DIFF_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            local_hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
            time_difference(TIME_DIFFERENCE(drct_substr(vl, 2)));
        }


        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_ENCODING::local_hours, local_hours, uint8_t);
        ITU_T_HOLDERH_DEFN(HOURS_AND_DIFF_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);






        // sequence MINUTES-ENCODING

        MINUTES_ENCODING::MINUTES_ENCODING() : hours_(), minutes_() {
        };

        MINUTES_ENCODING::MINUTES_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes) :
        hours_(to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)) {
        };

        MINUTES_ENCODING::MINUTES_ENCODING(const std::string& vl) :
        hours_(), minutes_() {
            as_string(vl);
        };

        MINUTES_ENCODING::MINUTES_ENCODING(const char* vl) :
        hours_(), minutes_() {
            as_string(vl);
        };

        MINUTES_ENCODING::MINUTES_ENCODING(const base_time_duration& vl) :
        hours_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)) {
        };

        base_time_duration MINUTES_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()), 0);
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string MINUTES_ENCODING::as_string() const {
            return to_string(static_cast<int> (hours()), 2, '0') + ":" +
                    to_string(static_cast<int> (minutes()), 2, '0');
        }

        void MINUTES_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
            minutes(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
        }


        ITU_T_HOLDERH_DEFN(MINUTES_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_ENCODING::minutes, minutes, uint8_t);







        // sequence MINUTES-UTC-ENCODING

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING() : hours_(), minutes_() {
        };

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes) :
        hours_(to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)) {
        };

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING(const std::string& vl) :
        hours_(), minutes_() {
            as_string(vl);
        };

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING(const char* vl) :
        hours_(), minutes_() {
            as_string(vl);
        };

        MINUTES_UTC_ENCODING::MINUTES_UTC_ENCODING(const base_time_duration& vl) :
        hours_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)) {
        };

        base_time_duration MINUTES_UTC_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()), 0);
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string MINUTES_UTC_ENCODING::as_string() const {
            return to_string(static_cast<int> (hours()), 2, '0') + ":" +
                    to_string(static_cast<int> (minutes()), 2, '0') + "Z";
        }

        void MINUTES_UTC_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
            minutes(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
        }


        ITU_T_HOLDERH_DEFN(MINUTES_UTC_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(MINUTES_UTC_ENCODING::minutes, minutes, uint8_t);







        // sequence MINUTES-AND-DIFF-ENCODING

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING() : local_time_(), time_difference_() {
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(const MINUTES_ENCODING& arg__time,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(arg__time),
        time_difference_(arg__time_difference) {
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(MINUTES_ENCODING(arg__hours, arg__minutes)),
        time_difference_(arg__time_difference) {
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(const std::string& vl) :
        local_time_(), time_difference_() {
            as_string(vl);
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(const char* vl) :
        local_time_(), time_difference_() {
            as_string(vl);
        };

        MINUTES_AND_DIFF_ENCODING::MINUTES_AND_DIFF_ENCODING(const base_time_duration& vl) :
        local_time_(vl), time_difference_() {
        };

        base_time_duration MINUTES_AND_DIFF_ENCODING::as_time() const {
            try {
                return local_time().as_time();
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string MINUTES_AND_DIFF_ENCODING::as_string() const {
            return local_time().as_string() + time_difference().as_string();
        }

        void MINUTES_AND_DIFF_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            local_time(MINUTES_ENCODING(drct_substr(vl, 0, 4)));
            time_difference(TIME_DIFFERENCE(drct_substr(vl, 4)));
        }


        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_ENCODING::local_time, local_time, MINUTES_ENCODING);
        ITU_T_HOLDERH_DEFN(MINUTES_AND_DIFF_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);






        // sequence TIME-OF-DAY-ENCODING

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING() : hours_(), minutes_(), seconds_() {
        };

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds) :
        hours_(to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
        seconds_(to_range(arg__seconds, (uint8_t) 0, (uint8_t) 60)) {
        };

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING(const std::string& vl) :
        hours_(), minutes_(), seconds_() {
            as_string(vl);
        };

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING(const char* vl) :
        hours_(), minutes_(), seconds_() {
            as_string(vl);
        };

        TIME_OF_DAY_ENCODING::TIME_OF_DAY_ENCODING(const base_time_duration& vl) :
        hours_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
        seconds_(to_range<uint8_t>(vl.is_special() ? 0 : vl.seconds(), (uint8_t) 0, (uint8_t) 60)) {
        };

        base_time_duration TIME_OF_DAY_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()), static_cast<int> (seconds()));
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string TIME_OF_DAY_ENCODING::as_string() const {
            return to_string(static_cast<int> (hours()), 2, '0') + ":" +
                    to_string(static_cast<int> (minutes()), 2, '0') + ":" +
                    to_string(static_cast<int> (seconds()), 2, '0');
        }

        void TIME_OF_DAY_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
            minutes(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
            seconds(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 4, 2), 0, "0"), (uint8_t) 0, (uint8_t) 60));
        }

        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_ENCODING::seconds, seconds, uint8_t);





        // sequence TIME-OF-DAY

        TIME_OF_DAY::TIME_OF_DAY() : hours_(), minutes_(), seconds_() {
        };

        TIME_OF_DAY::TIME_OF_DAY(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds) :
        hours_(to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
        seconds_(to_range(arg__seconds, (uint8_t) 0, (uint8_t) 60)) {
        };

        TIME_OF_DAY::TIME_OF_DAY(const std::string& vl) :
        hours_(), minutes_(), seconds_() {
            as_string(vl);
        };

        TIME_OF_DAY::TIME_OF_DAY(const char* vl) :
        hours_(), minutes_(), seconds_() {
            as_string(vl);
        };

        TIME_OF_DAY::TIME_OF_DAY(const base_time_duration& vl) :
        hours_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
        seconds_(to_range<uint8_t>(vl.is_special() ? 0 : vl.seconds(), (uint8_t) 0, (uint8_t) 60)) {
        };

        base_time_duration TIME_OF_DAY::as_time() const {
            try {
                return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()), static_cast<int> (seconds()));
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string TIME_OF_DAY::as_string() const {
            return to_string(static_cast<int> (hours()), 2, '0') + ":" +
                    to_string(static_cast<int> (minutes()), 2, '0') + ":" +
                    to_string(static_cast<int> (seconds()), 2, '0');
        }

        void TIME_OF_DAY::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
            minutes(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
            seconds(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 4, 2), 0, "0"), (uint8_t) 0, (uint8_t) 60));
        }

        ITU_T_HOLDERH_DEFN(TIME_OF_DAY::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY::seconds, seconds, uint8_t);






        // sequence TIME-OF-DAY-UTC-ENCODING

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING() : hours_(), minutes_(), seconds_() {
        };

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds) :
        hours_(to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
        seconds_(to_range(arg__seconds, (uint8_t) 0, (uint8_t) 60)) {
        };

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING(const std::string& vl) :
        hours_(), minutes_(), seconds_() {
            as_string(vl);
        };

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING(const char* vl) :
        hours_(), minutes_(), seconds_() {
            as_string(vl);
        };

        TIME_OF_DAY_UTC_ENCODING::TIME_OF_DAY_UTC_ENCODING(const base_time_duration& vl) :
        hours_(to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
        minutes_(to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
        seconds_(to_range<uint8_t>(vl.is_special() ? 0 : vl.seconds(), (uint8_t) 0, (uint8_t) 60)) {
        };

        base_time_duration TIME_OF_DAY_UTC_ENCODING::as_time() const {
            try {
                return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()), static_cast<int> (seconds()));
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string TIME_OF_DAY_UTC_ENCODING::as_string() const {
            return to_string(static_cast<int> (hours()), 2, '0') + ":" +
                    to_string(static_cast<int> (minutes()), 2, '0') + ":" +
                    to_string(static_cast<int> (seconds()), 2, '0') + "Z";
        }

        void TIME_OF_DAY_UTC_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            hours(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
            minutes(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
            seconds(to_range<uint8_t>(string_to_def<int>(drct_substr(vl, 4, 2), 0, "0"), (uint8_t) 0, (uint8_t) 60));
        }


        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_ENCODING::hours, hours, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_ENCODING::minutes, minutes, uint8_t);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_UTC_ENCODING::seconds, seconds, uint8_t);





        // sequence TIME-OF-DAY-AND-DIFF-ENCODING

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING() : local_time_(), time_difference_() {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(const TIME_OF_DAY_ENCODING& arg__local_time,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(arg__local_time),
        time_difference_(arg__time_difference) {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(const uint8_t& arg__hours,
                const uint8_t& arg__minutes,
                const uint8_t& arg__seconds,
                const TIME_DIFFERENCE& arg__time_difference) :
        local_time_(TIME_OF_DAY_ENCODING(arg__hours, arg__minutes, arg__seconds)),
        time_difference_(arg__time_difference) {
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(const std::string& vl) :
        local_time_(), time_difference_() {
            as_string(vl);
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(const char* vl) :
        local_time_(), time_difference_() {
            as_string(vl);
        };

        TIME_OF_DAY_AND_DIFF_ENCODING::TIME_OF_DAY_AND_DIFF_ENCODING(const base_time_duration& vl) :
        local_time_(vl), time_difference_() {
        };

        base_time_duration TIME_OF_DAY_AND_DIFF_ENCODING::as_time() const {
            try {
                return local_time().as_time();
            }
            catch (...) {
            }
            return base_time_duration();
        }

        std::string TIME_OF_DAY_AND_DIFF_ENCODING::as_string() const {
            return local_time().as_string() + time_difference().as_string();
        }

        void TIME_OF_DAY_AND_DIFF_ENCODING::as_string(const std::string& v) {
            std::string vl = normalize_time_str(v);
            local_time(TIME_OF_DAY_ENCODING(drct_substr(vl, 0, 6)));
            time_difference(TIME_DIFFERENCE(drct_substr(vl, 6)));
        }



        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::local_time, local_time, TIME_OF_DAY_ENCODING);
        ITU_T_HOLDERH_DEFN(TIME_OF_DAY_AND_DIFF_ENCODING::time_difference, time_difference, TIME_DIFFERENCE);





        // sequence DURATION-INTERVAL-ENCODING

        DURATION_INTERVAL_ENCODING::DURATION_INTERVAL_ENCODING(integer_type arg__years,
                integer_type arg__months,
                integer_type arg__weeks,
                integer_type arg__days,
                integer_type arg__hours,
                integer_type arg__minutes,
                integer_type arg__seconds,
                ITU_T_SHARED(Fractional_part_type) arg__fractional_part) :
        years_(arg__years ? ITU_T_MAKE(integer_type)(arg__years) : (ITU_T_SHARED(integer_type)())),
        months_(arg__months ? ITU_T_MAKE(integer_type)(arg__months) : (ITU_T_SHARED(integer_type)())),
        weeks_(arg__weeks ? ITU_T_MAKE(integer_type)(arg__weeks) : (ITU_T_SHARED(integer_type)())),
        days_(arg__days ? ITU_T_MAKE(integer_type)(arg__days) : (ITU_T_SHARED(integer_type)())),
        hours_(arg__hours ? ITU_T_MAKE(integer_type)(arg__hours) : (ITU_T_SHARED(integer_type)())),
        minutes_(arg__minutes ? ITU_T_MAKE(integer_type)(arg__minutes) : (ITU_T_SHARED(integer_type)())),
        seconds_(arg__seconds ? ITU_T_MAKE(integer_type)(arg__seconds) : (ITU_T_SHARED(integer_type)())),
        fractional_part_(arg__fractional_part) {
        };

        DURATION_INTERVAL_ENCODING::DURATION_INTERVAL_ENCODING(const std::string& vl) {
            as_string(vl);
        };

        DURATION_INTERVAL_ENCODING::DURATION_INTERVAL_ENCODING(const char* vl) {
            as_string(vl);
        };

        /*DURATION_INTERVAL_ENCODING::DURATION_INTERVAL_ENCODING(const base_time_duration& vl){          
        }*/

        std::string DURATION_INTERVAL_ENCODING::as_string() const {
            std::string rslt = "P";
            if (years())
                rslt += (to_string(*years()) + "Y");
            if (months())
                rslt += (to_string(*months()) + "M");
            if (weeks())
                rslt += (to_string(*weeks()) + "W");
            if (days())
                rslt += (to_string(*days()) + "D");
            if (hours() || minutes() || seconds()) {
                rslt += "T";
                if (hours())
                    rslt += (to_string(*hours()) + "H");
                if (minutes())
                    rslt += (to_string(*minutes()) + "M");
                if (seconds())
                    rslt += (to_string(*seconds()) + "S");
            }
            else {

            }
            return rslt;
        }

        void DURATION_INTERVAL_ENCODING::as_string(const std::string& v) {
            std::string vl = time_detail::normalize_time_str(v);
            std::string::size_type it = vl.find_first_of('T');
            std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
            std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
            integer_type arg__years = get_numstr_marker(vll, 'Y');
            integer_type arg__months = get_numstr_marker(vll, 'M');
            integer_type arg__weeks = get_numstr_marker(vll, 'W');
            integer_type arg__days = get_numstr_marker(vll, 'D');
            integer_type arg__hours = get_numstr_marker(vlr, 'H');
            integer_type arg__minutes = get_numstr_marker(vlr, 'M');
            integer_type arg__seconds = get_numstr_marker(vlr, 'S');
            years(arg__years ? ITU_T_MAKE(integer_type)(arg__years) : (ITU_T_SHARED(integer_type)()));
            months(arg__months ? ITU_T_MAKE(integer_type)(arg__months) : (ITU_T_SHARED(integer_type)()));
            weeks(arg__weeks ? ITU_T_MAKE(integer_type)(arg__weeks) : (ITU_T_SHARED(integer_type)()));
            days(arg__days ? ITU_T_MAKE(integer_type)(arg__days) : (ITU_T_SHARED(integer_type)()));
            hours(arg__hours ? ITU_T_MAKE(integer_type)(arg__hours) : (ITU_T_SHARED(integer_type)()));
            minutes(arg__minutes ? ITU_T_MAKE(integer_type)(arg__minutes) : (ITU_T_SHARED(integer_type)()));
            seconds(arg__seconds ? ITU_T_MAKE(integer_type)(arg__seconds) : (ITU_T_SHARED(integer_type)()));
        }

        /*base_duration DURATION_INTERVAL_ENCODING::as_duration() const {
            try {
                base_duration rslt;
                rslt.
                return base_time_duration();
            }            catch (...) {
            }
            return base_time_duration();
        }*/

        DURATION_INTERVAL_ENCODING::Fractional_part_type::Fractional_part_type() : number_of_digits_(), fractional_value_() {
        };

        DURATION_INTERVAL_ENCODING::Fractional_part_type::Fractional_part_type(const integer_type& arg__number_of_digits,
                const integer_type& arg__fractional_value) :
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








        // sequence DURATION

        DURATION::DURATION(integer_type arg__years,
                integer_type arg__months,
                integer_type arg__weeks,
                integer_type arg__days,
                integer_type arg__hours,
                integer_type arg__minutes,
                integer_type arg__seconds,
                ITU_T_SHARED(Fractional_part_type) arg__fractional_part) :
        years_(arg__years ? ITU_T_MAKE(integer_type)(arg__years) : (ITU_T_SHARED(integer_type)())),
        months_(arg__months ? ITU_T_MAKE(integer_type)(arg__months) : (ITU_T_SHARED(integer_type)())),
        weeks_(arg__weeks ? ITU_T_MAKE(integer_type)(arg__weeks) : (ITU_T_SHARED(integer_type)())),
        days_(arg__days ? ITU_T_MAKE(integer_type)(arg__days) : (ITU_T_SHARED(integer_type)())),
        hours_(arg__hours ? ITU_T_MAKE(integer_type)(arg__hours) : (ITU_T_SHARED(integer_type)())),
        minutes_(arg__minutes ? ITU_T_MAKE(integer_type)(arg__minutes) : (ITU_T_SHARED(integer_type)())),
        seconds_(arg__seconds ? ITU_T_MAKE(integer_type)(arg__seconds) : (ITU_T_SHARED(integer_type)())),
        fractional_part_(arg__fractional_part) {
        };

        DURATION::DURATION(const std::string& vl) {
            as_string(vl);
        };

        DURATION::DURATION(const char* vl) {
            as_string(vl);
        };

        /*DURATION::DURATION(const base_time_duration& vl){          
        }*/

        std::string DURATION::as_string() const {
            std::string rslt = "P";
            if (years())
                rslt += (to_string(*years()) + "Y");
            if (months())
                rslt += (to_string(*months()) + "M");
            if (weeks())
                rslt += (to_string(*weeks()) + "W");
            if (days())
                rslt += (to_string(*days()) + "D");
            if (hours() || minutes() || seconds()) {
                rslt += "T";
                if (hours())
                    rslt += (to_string(*hours()) + "H");
                if (minutes())
                    rslt += (to_string(*minutes()) + "M");
                if (seconds())
                    rslt += (to_string(*seconds()) + "S");
            }
            else {

            }
            return rslt;
        }

        void DURATION::as_string(const std::string& v) {
            std::string vl = time_detail::normalize_time_str(v);
            std::string::size_type it = vl.find_first_of('T');
            std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
            std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
            integer_type arg__years = get_numstr_marker(vll, 'Y');
            integer_type arg__months = get_numstr_marker(vll, 'M');
            integer_type arg__weeks = get_numstr_marker(vll, 'W');
            integer_type arg__days = get_numstr_marker(vll, 'D');
            integer_type arg__hours = get_numstr_marker(vlr, 'H');
            integer_type arg__minutes = get_numstr_marker(vlr, 'M');
            integer_type arg__seconds = get_numstr_marker(vlr, 'S');
            years(arg__years ? ITU_T_MAKE(integer_type)(arg__years) : (ITU_T_SHARED(integer_type)()));
            months(arg__months ? ITU_T_MAKE(integer_type)(arg__months) : (ITU_T_SHARED(integer_type)()));
            weeks(arg__weeks ? ITU_T_MAKE(integer_type)(arg__weeks) : (ITU_T_SHARED(integer_type)()));
            days(arg__days ? ITU_T_MAKE(integer_type)(arg__days) : (ITU_T_SHARED(integer_type)()));
            hours(arg__hours ? ITU_T_MAKE(integer_type)(arg__hours) : (ITU_T_SHARED(integer_type)()));
            minutes(arg__minutes ? ITU_T_MAKE(integer_type)(arg__minutes) : (ITU_T_SHARED(integer_type)()));
            seconds(arg__seconds ? ITU_T_MAKE(integer_type)(arg__seconds) : (ITU_T_SHARED(integer_type)()));
        }

        /*base_duration DURATION::as_duration() const {
            try {
                base_duration rslt;
                rslt.
                return base_time_duration();
            }            catch (...) {
            }
            return base_time_duration();
        }*/

        DURATION::Fractional_part_type::Fractional_part_type() : number_of_digits_(), fractional_value_() {
        };

        DURATION::Fractional_part_type::Fractional_part_type(const integer_type& arg__number_of_digits,
                const integer_type& arg__fractional_value) :
        number_of_digits_(arg__number_of_digits),
        fractional_value_(arg__fractional_value) {
        };


        ITU_T_HOLDERH_DEFN(DURATION::Fractional_part_type::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(DURATION::Fractional_part_type::fractional_value, fractional_value, integer_type);


        ITU_T_OPTIONAL_DEFN(DURATION::years, years, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::months, months, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::weeks, weeks, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::days, days, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::hours, hours, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::minutes, minutes, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::seconds, seconds, integer_type);
        ITU_T_OPTIONAL_DEFN(DURATION::fractional_part, fractional_part, DURATION::Fractional_part_type);



        // sequence REC-DURATION-INTERVAL-ENCODING

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING() : duration_() {
        };

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING(const DURATION_INTERVAL_ENCODING& arg__duration,
                integer_type arg__recurrence) :
        recurrence_(arg__recurrence ? ITU_T_MAKE(integer_type)(arg__recurrence) : ITU_T_SHARED(integer_type)()),
        duration_(arg__duration) {
        };

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING(const std::string& vl) {
            as_string(vl);
        };

        REC_DURATION_INTERVAL_ENCODING::REC_DURATION_INTERVAL_ENCODING(const char* vl) {
            as_string(vl);
        };

        std::string REC_DURATION_INTERVAL_ENCODING::as_string() const {
            std::string rslt = "";
            if (recurrence())
                rslt += ("R" + to_string(recurrence()));
            return rslt + duration().as_string();
        }

        void REC_DURATION_INTERVAL_ENCODING::as_string(const std::string& v) {
            std::string vl = time_detail::normalize_time_str(v);
            std::string::size_type it = vl.find_first_of('P');
            std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it + 1);
            std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
            integer_type arg__recurrence = get_numstr_marker(vll, 'P');
            recurrence(arg__recurrence ? ITU_T_MAKE(integer_type)(arg__recurrence) : ITU_T_SHARED(integer_type)());
            duration(DURATION_INTERVAL_ENCODING(vlr));
        }

        ITU_T_OPTIONAL_DEFN(REC_DURATION_INTERVAL_ENCODING::recurrence, recurrence, integer_type);
        ITU_T_HOLDERH_DEFN(REC_DURATION_INTERVAL_ENCODING::duration, duration, DURATION_INTERVAL_ENCODING);





        // choice DATE-TYPE

        DATE_TYPE::DATE_TYPE(const std::string& vl) : ITU_T_CHOICE_CTORS_INHERITED(DATE_TYPE) {
            as_string(vl);
        };

        DATE_TYPE::DATE_TYPE(const char* vl) : ITU_T_CHOICE_CTORS_INHERITED(DATE_TYPE) {
            as_string(vl);
        };

        DATE_TYPE::DATE_TYPE(const base_date & vl, DATE_TYPE_enum enm) : ITU_T_CHOICE_CTORS_INHERITED(DATE_TYPE) {
            if (!vl.is_special()) {
                switch (enm) {
                    case DATE_TYPE_date_C_Basic: date_C_Basic(CENTURY_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_C_L: date_C_L(ANY_CENTURY(vl));
                        break;
                    case DATE_TYPE_date_Y_Basic: date_Y_Basic(YEAR_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_Y_L: date_Y_L(ANY_YEAR(vl));
                        break;
                    case DATE_TYPE_date_YM_Basic: date_YM_Basic(YEAR_MONTH_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_YM_L: date_YM_L(ANY_YEAR_MONTH(vl));
                        break;
                    case DATE_TYPE_date_YMD_Basic: date_YMD_Basic(DATE_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_YMD_L: date_YMD_L(ANY_DATE(vl));
                        break;
                    case DATE_TYPE_date_YD_Basic: date_YD_Basic(YEAR_DAY_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_YD_L: date_YD_L(ANY_YEAR_DAY(vl));
                        break;
                    case DATE_TYPE_date_YW_Basic: date_YW_Basic(YEAR_WEEK_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_YW_L: date_YW_L(ANY_YEAR_WEEK(vl));
                        break;
                    case DATE_TYPE_date_YWD_Basic: date_YWD_Basic(YEAR_WEEK_DAY_ENCODING(vl));
                        break;
                    case DATE_TYPE_date_YWD_L: date_YWD_L(ANY_YEAR_WEEK_DAY(vl));
                        break;
                    default:
                    {
                    }
                }
            }
        };

        base_date DATE_TYPE::as_date() {
            switch (type()) {
                case DATE_TYPE_date_C_Basic: return date_C_Basic() ? date_C_Basic()->as_date(): base_date();
                case DATE_TYPE_date_C_L: return date_C_L() ? date_C_L()->as_date(): base_date();
                case DATE_TYPE_date_Y_Basic: return date_Y_Basic() ? date_Y_Basic()->as_date(): base_date();
                case DATE_TYPE_date_Y_L: return date_Y_L() ? date_Y_L()->as_date(): base_date();
                case DATE_TYPE_date_YM_Basic: return date_YM_Basic() ? date_YM_Basic()->as_date(): base_date();
                case DATE_TYPE_date_YM_L: return date_YM_L() ? date_YM_L()->as_date(): base_date();
                case DATE_TYPE_date_YMD_Basic: return date_YMD_Basic() ? date_YMD_Basic()->as_date(): base_date();
                case DATE_TYPE_date_YMD_L: return date_YMD_L() ? date_YMD_L()->as_date(): base_date();
                case DATE_TYPE_date_YD_Basic: return date_YD_Basic() ? date_YD_Basic()->as_date(): base_date();
                case DATE_TYPE_date_YD_L: return date_YD_L() ? date_YD_L()->as_date(): base_date();
                case DATE_TYPE_date_YW_Basic: return date_YW_Basic() ? date_YW_Basic()->as_date(): base_date();
                case DATE_TYPE_date_YW_L: return date_YW_L() ? date_YW_L()->as_date(): base_date();
                case DATE_TYPE_date_YWD_Basic: return date_YWD_Basic() ? date_YWD_Basic()->as_date(): base_date();
                case DATE_TYPE_date_YWD_L: return date_YWD_L() ? date_YWD_L()->as_date(): base_date();
                default:
                {
                }
            }
            return base_date();
        }

        std::string DATE_TYPE::as_string() {
            switch (type()) {
                case DATE_TYPE_date_C_Basic: return date_C_Basic() ? date_C_Basic()->as_string(): std::string();
                case DATE_TYPE_date_C_L: return date_C_L() ? date_C_L()->as_string(): std::string();
                case DATE_TYPE_date_Y_Basic: return date_Y_Basic() ? date_Y_Basic()->as_string(): std::string();
                case DATE_TYPE_date_Y_L: return date_Y_L() ? date_Y_L()->as_string(): std::string();
                case DATE_TYPE_date_YM_Basic: return date_YM_Basic() ? date_YM_Basic()->as_string(): std::string();
                case DATE_TYPE_date_YM_L: return date_YM_L() ? date_YM_L()->as_string(): std::string();
                case DATE_TYPE_date_YMD_Basic: return date_YMD_Basic() ? date_YMD_Basic()->as_string(): std::string();
                case DATE_TYPE_date_YMD_L: return date_YMD_L() ? date_YMD_L()->as_string(): std::string();
                case DATE_TYPE_date_YD_Basic: return date_YD_Basic() ? date_YD_Basic()->as_string(): std::string();
                case DATE_TYPE_date_YD_L: return date_YD_L() ? date_YD_L()->as_string(): std::string();
                case DATE_TYPE_date_YW_Basic: return date_YW_Basic() ? date_YW_Basic()->as_string(): std::string();
                case DATE_TYPE_date_YW_L: return date_YW_L() ? date_YW_L()->as_string(): std::string();
                case DATE_TYPE_date_YWD_Basic: return date_YWD_Basic() ? date_YWD_Basic()->as_string(): std::string();
                case DATE_TYPE_date_YWD_L: return date_YWD_L() ? date_YWD_L()->as_string(): std::string();
                default:
                {
                }
            }
            return "";
        }

        void DATE_TYPE::as_string(const std::string& vl) {
            std::string tmpl = normalizeLR_time_str(vl);
            std::string::size_type it = tmpl.find_first_of('W');
            if (it == std::string::npos) {
                it = tmpl.find_last_of('-');
                if (it == std::string::npos) {
                    it = tmpl.find_first_of('C');
                    if (it == std::string::npos) {
                        if (tmpl.size() == 4)
                            date_Y_Basic(YEAR_ENCODING(vl));
                        else
                            date_Y_L(ANY_YEAR(vl));
                    }
                    else {
                        if (tmpl.size() == 3)
                            date_C_Basic(CENTURY_ENCODING(vl));
                        else
                            date_C_L(ANY_CENTURY(vl));
                    }
                }
                else {
                    // if (size-it)>3 YD                  
                    if ((tmpl.size() - it) > 3) {
                        if (it == 4)
                            date_YD_Basic(YEAR_DAY_ENCODING(vl));
                        else
                            date_YD_L(ANY_YEAR_DAY(vl));
                    }
                    else {
                        std::string::size_type itf = tmpl.find_first_of('-');
                        std::string::size_type itl = tmpl.find_last_of('-');
                        if (itf != itl) {
                            if (tmpl.size() == 4)
                                date_YMD_Basic(DATE_ENCODING(vl));
                            else
                                date_YMD_L(ANY_DATE(vl));
                        }
                        else {
                            if (tmpl.size() == 4)
                                date_YM_Basic(YEAR_MONTH_ENCODING(vl));
                            else
                                date_YM_L(ANY_YEAR_MONTH(vl));
                        }
                    }
                }
            }
            else {
                // if (size-it)>3 YWD else YW
                if ((tmpl.size() - it) > 3) {
                    if (it == 4)
                        date_YWD_Basic(YEAR_WEEK_DAY_ENCODING(vl));
                    else
                        date_YWD_L(ANY_YEAR_WEEK_DAY(vl));
                }
                else {
                    if (it == 4)
                        date_YW_Basic(YEAR_WEEK_ENCODING(vl));
                    else
                        date_YW_L(ANY_YEAR_WEEK(vl));
                }
            }
        };

        std::string DATE_TYPE::format() {
            switch (type()) {
                case DATE_TYPE_date_C_Basic: return date_C_Basic() ? date_C_Basic()->format(): std::string();
                case DATE_TYPE_date_C_L: return date_C_L() ? date_C_L()->format(): std::string();
                case DATE_TYPE_date_Y_Basic: return date_Y_Basic() ? date_Y_Basic()->format(): std::string();
                case DATE_TYPE_date_Y_L: return date_Y_L() ? date_Y_L()->format(): std::string();
                case DATE_TYPE_date_YM_Basic: return date_YM_Basic() ? date_YM_Basic()->format(): std::string();
                case DATE_TYPE_date_YM_L: return date_YM_L() ? date_YM_L()->format(): std::string();
                case DATE_TYPE_date_YMD_Basic: return date_YMD_Basic() ? date_YMD_Basic()->format(): std::string();
                case DATE_TYPE_date_YMD_L: return date_YMD_L() ? date_YMD_L()->format(): std::string();
                case DATE_TYPE_date_YD_Basic: return date_YD_Basic() ? date_YD_Basic()->format(): std::string();
                case DATE_TYPE_date_YD_L: return date_YD_L() ? date_YD_L()->format(): std::string();
                case DATE_TYPE_date_YW_Basic: return date_YW_Basic() ? date_YW_Basic()->format(): std::string();
                case DATE_TYPE_date_YW_L: return date_YW_L() ? date_YW_L()->format(): std::string();
                case DATE_TYPE_date_YWD_Basic: return date_YWD_Basic() ? date_YWD_Basic()->format(): std::string();
                case DATE_TYPE_date_YWD_L: return date_YWD_L() ? date_YWD_L()->format(): std::string();
                default:
                {
                }
            }
            return "";
        }

        template<> void DATE_TYPE::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void DATE_TYPE::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }

        ITU_T_CHOICES_DEFN(DATE_TYPE::date_C_Basic, date_C_Basic, CENTURY_ENCODING, DATE_TYPE_date_C_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_C_L, date_C_L, ANY_CENTURY, DATE_TYPE_date_C_L);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_Y_Basic, date_Y_Basic, YEAR_ENCODING, DATE_TYPE_date_Y_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_Y_L, date_Y_L, ANY_YEAR, DATE_TYPE_date_Y_L);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YM_Basic, date_YM_Basic, YEAR_MONTH_ENCODING, DATE_TYPE_date_YM_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YM_L, date_YM_L, ANY_YEAR_MONTH, DATE_TYPE_date_YM_L);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YMD_Basic, date_YMD_Basic, DATE_ENCODING, DATE_TYPE_date_YMD_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YMD_L, date_YMD_L, ANY_DATE, DATE_TYPE_date_YMD_L);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YD_Basic, date_YD_Basic, YEAR_DAY_ENCODING, DATE_TYPE_date_YD_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YD_L, date_YD_L, ANY_YEAR_DAY, DATE_TYPE_date_YD_L);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YW_Basic, date_YW_Basic, YEAR_WEEK_ENCODING, DATE_TYPE_date_YW_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YW_L, date_YW_L, ANY_YEAR_WEEK, DATE_TYPE_date_YW_L);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YWD_Basic, date_YWD_Basic, YEAR_WEEK_DAY_ENCODING, DATE_TYPE_date_YWD_Basic);
        ITU_T_CHOICES_DEFN(DATE_TYPE::date_YWD_L, date_YWD_L, ANY_YEAR_WEEK_DAY, DATE_TYPE_date_YWD_L);




        // sequence TIME-TYPE

        TIME_TYPE::TIME_TYPE() : time_type_() {
        };

        TIME_TYPE::TIME_TYPE(const Time_type& arg__time_type) :
        time_type_(arg__time_type) {
        };

        TIME_TYPE::TIME_TYPE(const std::string & vl) : time_type_() {
            as_string(vl);
        };

        TIME_TYPE::TIME_TYPE(const char* vl) : time_type_() {
            as_string(vl);
        };

        TIME_TYPE::TIME_TYPE(const base_time_duration & vl, Time_type_enum enm) : time_type_() {
            if (!vl.is_special()) {
                switch (enm) {
                    case Time_type_time_H_L: time_type().time_H_L(HOURS_ENCODING(vl));
                        break;
                    case Time_type_time_H_Z: time_type().time_H_Z(HOURS_UTC_ENCODING(vl));
                        break;
                    case Time_type_time_H_LD: time_type().time_H_LD(HOURS_AND_DIFF_ENCODING(vl));
                        break;
                    case Time_type_time_HM_L: time_type().time_HM_L(MINUTES_ENCODING(vl));
                        break;
                    case Time_type_time_HM_Z: time_type().time_HM_Z(MINUTES_UTC_ENCODING(vl));
                        break;
                    case Time_type_time_HM_LD: time_type().time_HM_LD(MINUTES_AND_DIFF_ENCODING(vl));
                        break;
                    case Time_type_time_HMS_L: time_type().time_HMS_L(TIME_OF_DAY_ENCODING(vl));
                        break;
                    case Time_type_time_HMS_Z: time_type().time_HMS_Z(TIME_OF_DAY_UTC_ENCODING(vl));
                        break;
                    case Time_type_time_HMS_LD: time_type().time_HMS_LD(TIME_OF_DAY_AND_DIFF_ENCODING(vl));
                        break;
                    case Time_type_time_HFn_L: time_type().time_HFn_L(HOURS_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HFn_Z: time_type().time_HFn_Z(HOURS_UTC_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HFn_LD: time_type().time_HFn_LD(HOURS_AND_DIFF_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HMFn_L: time_type().time_HMFn_L(MINUTES_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HMFn_Z: time_type().time_HMFn_Z(MINUTES_UTC_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HMFn_LD: time_type().time_HMFn_LD(MINUTES_AND_DIFF_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HMFSn_L: time_type().time_HMFSn_L(TIME_OF_DAY_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HMFSn_Z: time_type().time_HMFSn_Z(TIME_OF_DAY_UTC_AND_FRACTION(vl));
                        break;
                    case Time_type_time_HMFSn_LD: time_type().time_HMFSn_LD(TIME_OF_DAY_AND_DIFF_AND_FRACTION(vl));
                        break;
                    default:
                    {
                    }
                }
            }
        };

        base_time_duration TIME_TYPE::as_time() {
            switch (time_type().type()) {
                case Time_type_time_H_L: return time_type().time_H_L() ? time_type().time_H_L()->as_time(): base_time_duration();
                case Time_type_time_H_Z: return time_type().time_H_Z() ? time_type().time_H_Z()->as_time(): base_time_duration();
                case Time_type_time_H_LD: return time_type().time_H_LD() ? time_type().time_H_LD()->as_time(): base_time_duration();
                case Time_type_time_HM_L: return time_type().time_HM_L() ? time_type().time_HM_L()->as_time(): base_time_duration();
                case Time_type_time_HM_Z: return time_type().time_HM_Z() ? time_type().time_HM_Z()->as_time(): base_time_duration();
                case Time_type_time_HM_LD: return time_type().time_HM_LD() ? time_type().time_HM_LD()->as_time(): base_time_duration();
                case Time_type_time_HMS_L: return time_type().time_HMS_L() ? time_type().time_HMS_L()->as_time(): base_time_duration();
                case Time_type_time_HMS_Z: return time_type().time_HMS_Z() ? time_type().time_HMS_Z()->as_time(): base_time_duration();
                case Time_type_time_HMS_LD: return time_type().time_HMS_LD() ? time_type().time_HMS_LD()->as_time(): base_time_duration();
                case Time_type_time_HFn_L: return time_type().time_HFn_L() ? time_type().time_HFn_L()->as_time(): base_time_duration();
                case Time_type_time_HFn_Z: return time_type().time_HFn_Z() ? time_type().time_HFn_Z()->as_time(): base_time_duration();
                case Time_type_time_HFn_LD: return time_type().time_HFn_LD() ? time_type().time_HFn_LD()->as_time(): base_time_duration();
                case Time_type_time_HMFn_L: return time_type().time_HMFn_L() ? time_type().time_HMFn_L()->as_time(): base_time_duration();
                case Time_type_time_HMFn_Z: return time_type().time_HMFn_Z() ? time_type().time_HMFn_Z()->as_time(): base_time_duration();
                case Time_type_time_HMFn_LD: return time_type().time_HMFn_LD() ? time_type().time_HMFn_LD()->as_time(): base_time_duration();
                case Time_type_time_HMFSn_L: return time_type().time_HMFSn_L() ? time_type().time_HMFSn_L()->as_time(): base_time_duration();
                case Time_type_time_HMFSn_Z: return time_type().time_HMFSn_Z() ? time_type().time_HMFSn_Z()->as_time(): base_time_duration();
                case Time_type_time_HMFSn_LD: return time_type().time_HMFSn_LD() ? time_type().time_HMFSn_LD()->as_time(): base_time_duration();
                default:
                {
                }
            }
            return base_time_duration();
        };

        std::string TIME_TYPE::as_string() {
            switch (time_type().type()) {
                case Time_type_time_H_L: return time_type().time_H_L() ? time_type().time_H_L()->as_string(): "";
                case Time_type_time_H_Z: return time_type().time_H_Z() ? time_type().time_H_Z()->as_string(): "";
                case Time_type_time_H_LD: return time_type().time_H_LD() ? time_type().time_H_LD()->as_string(): "";
                case Time_type_time_HM_L: return time_type().time_HM_L() ? time_type().time_HM_L()->as_string(): "";
                case Time_type_time_HM_Z: return time_type().time_HM_Z() ? time_type().time_HM_Z()->as_string(): "";
                case Time_type_time_HM_LD: return time_type().time_HM_LD() ? time_type().time_HM_LD()->as_string(): "";
                case Time_type_time_HMS_L: return time_type().time_HMS_L() ? time_type().time_HMS_L()->as_string(): "";
                case Time_type_time_HMS_Z: return time_type().time_HMS_Z() ? time_type().time_HMS_Z()->as_string(): "";
                case Time_type_time_HMS_LD: return time_type().time_HMS_LD() ? time_type().time_HMS_LD()->as_string(): "";
                case Time_type_time_HFn_L: return time_type().time_HFn_L() ? time_type().time_HFn_L()->as_string(): "";
                case Time_type_time_HFn_Z: return time_type().time_HFn_Z() ? time_type().time_HFn_Z()->as_string(): "";
                case Time_type_time_HFn_LD: return time_type().time_HFn_LD() ? time_type().time_HFn_LD()->as_string(): "";
                case Time_type_time_HMFn_L: return time_type().time_HMFn_L() ? time_type().time_HMFn_L()->as_string(): "";
                case Time_type_time_HMFn_Z: return time_type().time_HMFn_Z() ? time_type().time_HMFn_Z()->as_string(): "";
                case Time_type_time_HMFn_LD: return time_type().time_HMFn_LD() ? time_type().time_HMFn_LD()->as_string(): "";
                case Time_type_time_HMFSn_L: return time_type().time_HMFSn_L() ? time_type().time_HMFSn_L()->as_string(): "";
                case Time_type_time_HMFSn_Z: return time_type().time_HMFSn_Z() ? time_type().time_HMFSn_Z()->as_string(): "";
                case Time_type_time_HMFSn_LD: return time_type().time_HMFSn_LD() ? time_type().time_HMFSn_LD()->as_string(): "";
                default:
                {
                }
            }
            return "";
        };

        void TIME_TYPE::as_string(const std::string & vl) {
            std::string tmpl = normalizeLR_time_str(vl);
            std::string::size_type itpl = tmpl.find_last_of('-');
            std::string::size_type itmn = tmpl.find_last_of('+');
            bool dtp = ((itpl != std::string::npos) && (itpl)) || ((itmn != std::string::npos) && (itmn));
            bool ztp = (tmpl.find_first_of('Z') != std::string::npos);
            if (dtp) {
                if (itpl != std::string::npos)
                    tmpl = tmpl.substr(0, itpl);
                else if (itmn != std::string::npos)
                    tmpl = tmpl.substr(0, itmn);
            }
            std::string::size_type fit = (tmpl.find_last_of('.') != std::string::npos) ?
                    tmpl.find_last_of('.') : tmpl.find_last_of(',');
            bool ftp = (fit != std::string::npos);
            std::size_t fpart = 0;
            if (fit != std::string::npos)
                fpart = tmpl.size() - fit - 1;
            std::string::size_type itf = tmpl.find_first_of(':');
            std::string::size_type itl = tmpl.find_last_of(':');
            if ((itf == std::string::npos) && (itl == std::string::npos)) {
                if (ftp) {
                    if (fpart)
                        number_of_digits(fpart);
                    if (dtp)
                        time_type().time_HFn_LD(HOURS_AND_DIFF_AND_FRACTION(vl));
                    else if (ztp)
                        time_type().time_HFn_Z(HOURS_UTC_AND_FRACTION(vl));
                    else
                        time_type().time_HFn_L(HOURS_AND_FRACTION(vl));
                }
                else {
                    if (dtp)
                        time_type().time_H_LD(HOURS_AND_DIFF_ENCODING(vl));
                    else if (ztp)
                        time_type().time_H_Z(HOURS_UTC_ENCODING(vl));
                    else
                        time_type().time_H_L(HOURS_ENCODING(vl));
                }
            }
            else if (itf == itl) {
                if (ftp) {
                    if (fpart)
                        number_of_digits(fpart);
                    if (dtp)
                        time_type().time_HMFn_LD(MINUTES_AND_DIFF_AND_FRACTION(vl));
                    else if (ztp)
                        time_type().time_HMFn_Z(MINUTES_UTC_AND_FRACTION(vl));
                    else
                        time_type().time_HMFn_L(MINUTES_AND_FRACTION(vl));
                }
                else {
                    if (dtp)
                        time_type().time_HM_LD(MINUTES_AND_DIFF_ENCODING(vl));
                    else if (ztp)
                        time_type().time_HM_Z(MINUTES_UTC_ENCODING(vl));
                    else
                        time_type().time_HM_L(MINUTES_ENCODING(vl));
                }
            }
            else {
                if (ftp) {
                    if (fpart)
                        number_of_digits(fpart);
                    if (dtp)
                        time_type().time_HMFSn_LD(TIME_OF_DAY_AND_DIFF_AND_FRACTION(vl));
                    else if (ztp)
                        time_type().time_HMFSn_Z(TIME_OF_DAY_UTC_AND_FRACTION(vl));
                    else
                        time_type().time_HMFSn_L(TIME_OF_DAY_AND_FRACTION(vl));
                }
                else {
                    if (dtp)
                        time_type().time_HMS_LD(TIME_OF_DAY_AND_DIFF_ENCODING(vl));
                    else if (ztp)
                        time_type().time_HMS_Z(TIME_OF_DAY_UTC_ENCODING(vl));
                    else
                        time_type().time_HMS_L(TIME_OF_DAY_ENCODING(vl));
                }
            }
        };

        std::string TIME_TYPE::format() {
            switch (time_type().type()) {
                case Time_type_time_H_L: return time_type().time_H_L() ? time_type().time_H_L()->format(): "";
                case Time_type_time_H_Z: return time_type().time_H_Z() ? time_type().time_H_Z()->format(): "";
                case Time_type_time_H_LD: return time_type().time_H_LD() ? time_type().time_H_LD()->format(): "";
                case Time_type_time_HM_L: return time_type().time_HM_L() ? time_type().time_HM_L()->format(): "";
                case Time_type_time_HM_Z: return time_type().time_HM_Z() ? time_type().time_HM_Z()->format(): "";
                case Time_type_time_HM_LD: return time_type().time_HM_LD() ? time_type().time_HM_LD()->format(): "";
                case Time_type_time_HMS_L: return time_type().time_HMS_L() ? time_type().time_HMS_L()->format(): "";
                case Time_type_time_HMS_Z: return time_type().time_HMS_Z() ? time_type().time_HMS_Z()->format(): "";
                case Time_type_time_HMS_LD: return time_type().time_HMS_LD() ? time_type().time_HMS_LD()->format(): "";
                case Time_type_time_HFn_L: return time_type().time_HFn_L() ? time_type().time_HFn_L()->format(): "";
                case Time_type_time_HFn_Z: return time_type().time_HFn_Z() ? time_type().time_HFn_Z()->format(): "";
                case Time_type_time_HFn_LD: return time_type().time_HFn_LD() ? time_type().time_HFn_LD()->format(): "";
                case Time_type_time_HMFn_L: return time_type().time_HMFn_L() ? time_type().time_HMFn_L()->format(): "";
                case Time_type_time_HMFn_Z: return time_type().time_HMFn_Z() ? time_type().time_HMFn_Z()->format(): "";
                case Time_type_time_HMFn_LD: return time_type().time_HMFn_LD() ? time_type().time_HMFn_LD()->format(): "";
                case Time_type_time_HMFSn_L: return time_type().time_HMFSn_L() ? time_type().time_HMFSn_L()->format(): "";
                case Time_type_time_HMFSn_Z: return time_type().time_HMFSn_Z() ? time_type().time_HMFSn_Z()->format(): "";
                case Time_type_time_HMFSn_LD: return time_type().time_HMFSn_LD() ? time_type().time_HMFSn_LD()->format(): "";
                default:
                {
                }
            }
        };

        template<> void TIME_TYPE::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void TIME_TYPE::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }

        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_H_L, time_H_L, HOURS_ENCODING, Time_type_time_H_L);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_H_Z, time_H_Z, HOURS_UTC_ENCODING, Time_type_time_H_Z);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_H_LD, time_H_LD, HOURS_AND_DIFF_ENCODING, Time_type_time_H_LD);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HM_L, time_HM_L, MINUTES_ENCODING, Time_type_time_HM_L);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HM_Z, time_HM_Z, MINUTES_UTC_ENCODING, Time_type_time_HM_Z);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HM_LD, time_HM_LD, MINUTES_AND_DIFF_ENCODING, Time_type_time_HM_LD);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMS_L, time_HMS_L, TIME_OF_DAY_ENCODING, Time_type_time_HMS_L);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMS_Z, time_HMS_Z, TIME_OF_DAY_UTC_ENCODING, Time_type_time_HMS_Z);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMS_LD, time_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, Time_type_time_HMS_LD);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HFn_L, time_HFn_L, HOURS_AND_FRACTION, Time_type_time_HFn_L);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HFn_Z, time_HFn_Z, HOURS_UTC_AND_FRACTION, Time_type_time_HFn_Z);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HFn_LD, time_HFn_LD, HOURS_AND_DIFF_AND_FRACTION, Time_type_time_HFn_LD);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMFn_L, time_HMFn_L, MINUTES_AND_FRACTION, Time_type_time_HMFn_L);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMFn_Z, time_HMFn_Z, MINUTES_UTC_AND_FRACTION, Time_type_time_HMFn_Z);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMFn_LD, time_HMFn_LD, MINUTES_AND_DIFF_AND_FRACTION, Time_type_time_HMFn_LD);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMFSn_L, time_HMFSn_L, TIME_OF_DAY_AND_FRACTION, Time_type_time_HMFSn_L);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMFSn_Z, time_HMFSn_Z, TIME_OF_DAY_UTC_AND_FRACTION, Time_type_time_HMFSn_Z);
        ITU_T_CHOICES_DEFN(TIME_TYPE::Time_type::time_HMFSn_LD, time_HMFSn_LD, TIME_OF_DAY_AND_DIFF_AND_FRACTION, Time_type_time_HMFSn_LD);


        ITU_T_OPTIONAL_DEFN(TIME_TYPE::number_of_digits, number_of_digits, integer_type);
        ITU_T_HOLDERH_DEFN(TIME_TYPE::time_type, time_type, TIME_TYPE::Time_type);





        // sequence DATE-TIME-ENC

        DATE_TIME_ENC::DATE_TIME_ENC() : date_(), time_() {
        };

        DATE_TIME_ENC::DATE_TIME_ENC(const DATE_TYPE& arg__date,
                const TIME_TYPE& arg__time) :
        date_(arg__date),
        time_(arg__time) {
        };

        DATE_TIME_ENC::DATE_TIME_ENC(const std::string & vl) : date_(), time_() {
            as_string(vl);
        };

        DATE_TIME_ENC::DATE_TIME_ENC(const char* vl) : date_(), time_() {
            as_string(vl);
        };

        base_date_time DATE_TIME_ENC::as_date_time() {
            return (date().as_date().is_special() || time().as_time().is_special()) ? (base_date_time()) :
                    (base_date_time(date().as_date()) + time().as_time());
        }

        std::string DATE_TIME_ENC::as_string() {
            return date().as_string() + "T" + time().as_string();
        }

        void DATE_TIME_ENC::as_string(const std::string & vl) {
            std::string tmpl = normalizeLR_time_str(vl);
            std::string::size_type it = tmpl.find_first_of('T');
            if ((it != std::string::npos) && (it < tmpl.size())) {
                date(DATE_TYPE(tmpl.substr(0, it)));
                time(TIME_TYPE(tmpl.substr(it + 1)));
            }
        }

        std::string DATE_TIME_ENC::format() {
            return date().format() + "T" + time().format();
        }

        template<> void DATE_TIME_ENC::serialize(boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<> void DATE_TIME_ENC::serialize(boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            as_string(std::string(tmpval.c_str()));
        }


        ITU_T_HOLDERH_DEFN(DATE_TIME_ENC::date, date, DATE_TYPE);
        ITU_T_HOLDERH_DEFN(DATE_TIME_ENC::time, time, TIME_TYPE);









        // choice MIXED-ENCODING

        MIXED_ENCODING::MIXED_ENCODING(const std::string & vl) : ITU_T_CHOICE_CTORS_INHERITED(MIXED_ENCODING) {
            as_string(vl);
        }

        MIXED_ENCODING::MIXED_ENCODING(const char* vl) {
            as_string(vl);
        }

        std::string MIXED_ENCODING::as_string() {
            return "";
        }

        void MIXED_ENCODING::as_string(const std::string & v) {

        }

        std::string MIXED_ENCODING::format() {
            return "";
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

        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_C_Basic, tm_C_Basic, CENTURY_ENCODING, mx_tm_C_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_C_L, tm_C_L, ANY_CENTURY, mx_tm_C_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Y_Basic, tm_Y_Basic, YEAR_ENCODING, mx_tm_Y_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Y_L, tm_Y_L, ANY_YEAR, mx_tm_Y_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YM_Basic, tm_YM_Basic, YEAR_MONTH_ENCODING, mx_tm_YM_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YM_L, tm_YM_L, ANY_YEAR_MONTH, mx_tm_YM_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YMD_Basic, tm_YMD_Basic, DATE_ENCODING, mx_tm_YMD_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YMD_L, tm_YMD_L, ANY_DATE, mx_tm_YMD_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YD_Basic, tm_YD_Basic, YEAR_DAY_ENCODING, mx_tm_YD_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YD_L, tm_YD_L, ANY_YEAR_DAY, mx_tm_YD_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YW_Basic, tm_YW_Basic, YEAR_WEEK_ENCODING, mx_tm_YW_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YW_L, tm_YW_L, ANY_YEAR_WEEK, mx_tm_YW_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YWD_Basic, tm_YWD_Basic, YEAR_WEEK_DAY_ENCODING, mx_tm_YWD_Basic);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_YWD_L, tm_YWD_L, ANY_YEAR_WEEK_DAY, mx_tm_YWD_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_H_L, tm_H_L, HOURS_ENCODING, mx_tm_H_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_H_Z, tm_H_Z, HOURS_UTC_ENCODING, mx_tm_H_Z);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_H_LD, tm_H_LD, HOURS_AND_DIFF_ENCODING, mx_tm_H_LD);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HM_L, tm_HM_L, MINUTES_ENCODING, mx_tm_HM_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HM_Z, tm_HM_Z, MINUTES_UTC_ENCODING, mx_tm_HM_Z);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HM_LD, tm_HM_LD, MINUTES_AND_DIFF_ENCODING, mx_tm_HM_LD);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMS_L, tm_HMS_L, TIME_OF_DAY_ENCODING, mx_tm_HMS_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMS_Z, tm_HMS_Z, TIME_OF_DAY_UTC_ENCODING, mx_tm_HMS_Z);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMS_LD, tm_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, mx_tm_HMS_LD);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HFn_L, tm_HFn_L, HOURS_AND_FRACTION_ENC, mx_tm_HFn_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HFn_Z, tm_HFn_Z, HOURS_UTC_AND_FRACTION_ENC, mx_tm_HFn_Z);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HFn_LD, tm_HFn_LD, HOURS_AND_DIFF_AND_FRACTION_ENC, mx_tm_HFn_LD);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMFn_L, tm_HMFn_L, MINUTES_AND_FRACTION_ENC, mx_tm_HMFn_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMFn_Z, tm_HMFn_Z, MINUTES_UTC_AND_FRACTION_ENC, mx_tm_HMFn_Z);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMFn_LD, tm_HMFn_LD, MINUTES_AND_DIFF_AND_FRACTION_ENC, mx_tm_HMFn_LD);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMFSn_L, tm_HMFSn_L, TIME_OF_DAY_AND_FRACTION_ENC, mx_tm_HMFSn_L);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMFSn_Z, tm_HMFSn_Z, TIME_OF_DAY_UTC_AND_FRACTION_ENC, mx_tm_HMFSn_Z);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_HMFSn_LD, tm_HMFSn_LD, TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENC, mx_tm_HMFSn_LD);
        ITU_T_CHOICEC_DEFN(MIXED_ENCODING::tm_DTT, tm_DTT, DATE_TIME_ENC, mx_tm_DTT);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Pse_D, tm_Pse_D, START_END_DATE_INTERVAL_ENC, mx_tm_Pse_D);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Pse_T, tm_Pse_T, START_END_TIME_INTERVAL_ENC, mx_tm_Pse_T);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Pse_DT, tm_Pse_DT, START_END_DATE_TIME_INTERVAL_ENC, mx_tm_Pse_DT);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_DU, tm_DU, DURATION_INTERVAL_ENC, mx_tm_DU);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Psi_D, tm_Psi_D, START_DATE_DURATION_INTERVAL_ENC, mx_tm_Psi_D);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Psi_T, tm_Psi_T, START_TIME_DURATION_INTERVAL_ENC, mx_tm_Psi_T);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Psi_DT, tm_Psi_DT, START_DATE_TIME_DURATION_INTERVAL_ENC, mx_tm_Psi_DT);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Pde_D, tm_Pde_D, DURATION_END_DATE_INTERVAL_ENC, mx_tm_Pde_D);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Pde_T, tm_Pde_T, DURATION_END_TIME_INTERVAL_ENC, mx_tm_Pde_T);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Pde_DT, tm_Pde_DT, DURATION_END_DATE_TIME_INTERVAL_ENC, mx_tm_Pde_DT);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Rse_D, tm_Rse_D, REC_START_END_DATE_INTERVAL_ENC, mx_tm_Rse_D);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Rse_T, tm_Rse_T, REC_START_END_TIME_INTERVAL_ENC, mx_tm_Rse_T);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Rse_DT, tm_Rse_DT, REC_START_END_DATE_TIME_INTERVAL_ENC, mx_tm_Rse_DT);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_RDU, tm_RDU, REC_DURATION_INTERVAL_ENC, mx_tm_RDU);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Rsd_D, tm_Rsd_D, REC_START_DATE_DURATION_INTERVAL_ENC, mx_tm_Rsd_D);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Rsd_T, tm_Rsd_T, REC_START_TIME_DURATION_INTERVAL_ENC, mx_tm_Rsd_T);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Rsd_DT, tm_Rsd_DT, REC_START_DATE_TIME_DURATION_INTERVAL_ENC, mx_tm_Rsd_DT);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Red_D, tm_Red_D, REC_DURATION_END_DATE_INTERVAL_ENC, mx_tm_Red_D);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Red_T, tm_Red_T, REC_DURATION_END_TIME_INTERVAL_ENC, mx_tm_Red_T);
        ITU_T_CHOICES_DEFN(MIXED_ENCODING::tm_Red_DT, tm_Red_DT, REC_DURATION_END_DATE_TIME_INTERVAL_ENC, mx_tm_Red_DT);




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
            ITU_T_DEFINE_TIME_TYPE(YEAR_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_MONTH_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DATE_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DATE);
            ITU_T_DEFINE_TIME_TYPE(YEAR_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_WEEK_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(YEAR_WEEK_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_UTC_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(HOURS_AND_DIFF_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_DIFFERENCE);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_UTC_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(MINUTES_AND_DIFF_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_UTC_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(TIME_OF_DAY_AND_DIFF_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DATE_TIME);
            ITU_T_DEFINE_TIME_TYPE(DURATION_INTERVAL_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DURATION);
            ITU_T_DEFINE_TIME_TYPE(REC_DURATION_INTERVAL_ENCODING);
            ITU_T_DEFINE_TIME_TYPE(DATE_TYPE);
            ITU_T_DEFINE_TIME_TYPE(TIME_TYPE);
            ITU_T_DEFINE_TIME_TYPE(DATE_TIME_ENC);
            ITU_T_DEFINE_TIME_TYPE(MIXED_ENCODING);
        }
    }
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif


