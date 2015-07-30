#ifndef ___DEFINEDTIME
#define ___DEFINEDTIME

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace boost {
    namespace asn1 {

        namespace time_detail {

            template<typename T>
            const T& to_range(const T& val, const T& min, const T& max) {
                return val < min ? min : (val < max ? val : max);
            }

            template<typename T>
            std::string to_string(const T& val, std::size_t sz = 0, std::string::value_type nlchar = 0) {
                try {
                    std::string rslt = boost::lexical_cast<std::string > (val);
                    return (sz && nlchar && (rslt.size() < sz)) ? (std::string(sz - rslt.size(), nlchar) + rslt) : rslt;
                }
                catch (boost::bad_lexical_cast) {
                }
                return (sz && nlchar) ? std::string(nlchar, sz) : "";
            }

            template<typename T>
            visible_string to_visible_string(const T& val, std::size_t sz = 0, std::string::value_type nlchar = 0) {
                return visible_string(to_string(val, sz, nlchar));
            }

            template<typename T>
            T string_to_def(const std::string& val, const T& def = 0, const std::string& escchars = "") {
                try {
                    if (!val.empty()) {
                        if (escchars.empty())
                            return boost::lexical_cast<T > (val);
                        else {
                            std::string::size_type it = val.find_first_not_of(escchars);
                            if (it != 0) {
                                std::string vl = val.substr(it != std::string::npos ? it : val.size() - 1);
                                return boost::lexical_cast<T > (vl);
                            }
                            return boost::lexical_cast<T > (val);
                        }
                    }
                }
                catch (boost::bad_lexical_cast) {
                }
                return def;
            }

            template<typename T>
            T visible_string_to_def(const visible_string& val, const T& def = 0, const std::string& escchars = "") {
                return string_to_def(std::string(val.c_str()), def, escchars);
            }


            // reverse substring |sssssssss|sssssss|sssssssssssss|
            //                                  bg                 beg    sz                                  end        
            // ,    if sz=0, full size from beg    

            inline std::string drct_substr(const std::string& vl, std::string::size_type beg = 0, std::string::size_type sz = 0) {
                std::string::size_type size = vl.size();
                if (beg < size) {
                    if (sz)
                        return vl.substr(beg, ((beg + sz) < size) ? sz : (size - beg));
                    else
                        return vl.substr(beg);
                }
                return "";
            }

            inline std::string drct_substr(const visible_string& vl, std::string::size_type beg = 0, std::string::size_type sz = 0) {
                return drct_substr(visible_string(vl), beg, sz);
            }


            // reverse substring |sssssssss|sssssss|sssssssssssss|
            //                                beg                 bgs       eps                 end        
            // endps=end-eps, sz=eps-bgs,    if sz=0, full size from beg    

            inline std::string revrs_substr(const std::string& vl, std::string::size_type endps = 0, std::string::size_type sz = 0) {
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

            inline std::string revrs_substr(const visible_string& vl, std::string::size_type endps = 0, std::string::size_type sz = 0) {
                return revrs_substr(visible_string(vl), endps, sz);
            }

        }


        struct CENTURY_ENCODING;
        struct ANY_CENTURY_ENCODING;
        struct YEAR_ENCODING;
        struct ANY_YEAR_ENCODING;
        struct YEAR_MONTH_ENCODING;
        struct ANY_YEAR_MONTH_ENCODING;
        struct DATE_ENCODING;
        struct ANY_DATE_ENCODING;
        struct YEAR_DAY_ENCODING;
        struct ANY_YEAR_DAY_ENCODING;
        struct YEAR_WEEK_ENCODING;
        struct ANY_YEAR_WEEK_ENCODING;
        struct YEAR_WEEK_DAY_ENCODING;
        struct ANY_YEAR_WEEK_DAY_ENCODING;
        struct HOURS_ENCODING;
        struct HOURS_UTC_ENCODING;
        struct HOURS_AND_DIFF_ENCODING;
        struct TIME_DIFFERENCE;
        struct MINUTES_ENCODING;
        struct MINUTES_UTC_ENCODING;
        struct MINUTES_AND_DIFF_ENCODING;
        struct TIME_OF_DAY_ENCODING;
        struct TIME_OF_DAY_UTC_ENCODING;
        struct TIME_OF_DAY_AND_DIFF_ENCODING;
        struct HOURS_AND_FRACTION_ENCODING;
        struct HOURS_UTC_AND_FRACTION_ENCODING;
        struct HOURS_AND_DIFF_AND_FRACTION_ENCODING;
        struct MINUTES_AND_FRACTION_ENCODING;
        struct MINUTES_UTC_AND_FRACTION_ENCODING;
        struct MINUTES_AND_DIFF_AND_FRACTION_ENCODING;
        struct TIME_OF_DAY_AND_FRACTION_ENCODING;
        struct TIME_OF_DAY_UTC_AND_FRACTION_ENCODING;
        struct TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING;
        struct DURATION_INTERVAL_ENCODING;
        struct REC_DURATION_INTERVAL_ENCODING;
        struct MIXED_ENCODING;
        struct DATE_TYPE;
        struct TIME_TYPE;







        // sequence CENTURY-ENCODING

        struct CENTURY_ENCODING {
            CENTURY_ENCODING();

            CENTURY_ENCODING(const uint8_t& arg__vl);

            CENTURY_ENCODING(const std::string& vl);

            CENTURY_ENCODING(const char* vl);

            CENTURY_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(as_number, uint8_t); //   Ic(  [ 0  ...   99 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-CENTURY-ENCODING

        struct ANY_CENTURY_ENCODING {
            ANY_CENTURY_ENCODING();

            ANY_CENTURY_ENCODING(const integer_type& arg__vl);

            ANY_CENTURY_ENCODING(const std::string& vl);

            ANY_CENTURY_ENCODING(const char* vl);

            ANY_CENTURY_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(as_number, integer_type);

            ITU_T_ARCHIVE_FUNC;
        };





        // choice YEAR-ENCODING

        enum YEAR_ENCODING_enum {
            YEAR_ENCODING_null = 0,
            YEAR_ENCODING_immediate,
            YEAR_ENCODING_near_future,
            YEAR_ENCODING_near_past,
            YEAR_ENCODING_remainder,
        };

        struct YEAR_ENCODING : public ITU_T_CHOICE(YEAR_ENCODING_enum) {


            ITU_T_CHOICE_CTORS(YEAR_ENCODING);

            YEAR_ENCODING(integer_type vl);

            YEAR_ENCODING(const std::string & v);

            YEAR_ENCODING(const char* v);

            YEAR_ENCODING(const base_date_time & v);

            ITU_T_CHOICES_DECL(immediate, uint16_t, YEAR_ENCODING_immediate); // primitive  //   Ic(  [ 2005  ...   2020 ]   
            ITU_T_CHOICES_DECL(near_future, uint16_t, YEAR_ENCODING_near_future); // primitive  //   Ic(  [ 2021  ...   2276 ]   
            ITU_T_CHOICES_DECL(near_past, uint16_t, YEAR_ENCODING_near_past); // primitive  //   Ic(  [ 1749  ...   2004 ]   
            ITU_T_CHOICES_DECL(remainder, integer_type, YEAR_ENCODING_remainder); // primitive  //   Ic(  [ ... ]   

            base_date_time as_datetime() const;

            base_date as_date() const;

            integer_type as_number() const;

            void as_number(integer_type v);

            std::string as_string() const;

            void as_string(const std::string & vl);

            ITU_T_ARCHIVE_FUNC;
        };




        // sequence ANY-YEAR-ENCODING

        struct ANY_YEAR_ENCODING {
            ANY_YEAR_ENCODING();

            ANY_YEAR_ENCODING(const integer_type& arg__val);

            ANY_YEAR_ENCODING(const std::string& vl);

            ANY_YEAR_ENCODING(const char* vl);

            ANY_YEAR_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(as_number, integer_type);

            ITU_T_ARCHIVE_FUNC;
        };







        // sequence YEAR-MONTH-ENCODING

        struct YEAR_MONTH_ENCODING {
            YEAR_MONTH_ENCODING();

            YEAR_MONTH_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month);

            YEAR_MONTH_ENCODING(const std::string& vl);

            YEAR_MONTH_ENCODING(const char* vl);

            YEAR_MONTH_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);


            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   

            ITU_T_ARCHIVE_FUNC;
        };






        // sequence ANY-YEAR-MONTH-ENCODING

        struct ANY_YEAR_MONTH_ENCODING {
            ANY_YEAR_MONTH_ENCODING();

            ANY_YEAR_MONTH_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month);

            ANY_YEAR_MONTH_ENCODING(const std::string& vl);

            ANY_YEAR_MONTH_ENCODING(const char* vl);

            ANY_YEAR_MONTH_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, ANY_YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   

            ITU_T_ARCHIVE_FUNC;
        };




        // sequence DATE-ENCODING

        struct DATE_ENCODING {
            DATE_ENCODING();

            DATE_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month,
                    const uint8_t& arg__day);

            DATE_ENCODING(const std::string& vl);

            DATE_ENCODING(const char* vl);

            DATE_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   31 ]   

            ITU_T_ARCHIVE_FUNC;
        };






        // sequence ANY-DATE-ENCODING

        struct ANY_DATE_ENCODING {
            ANY_DATE_ENCODING();

            ANY_DATE_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month,
                    const uint8_t& arg__day);

            ANY_DATE_ENCODING(const std::string& vl);

            ANY_DATE_ENCODING(const char* vl);

            ANY_DATE_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, ANY_YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   31 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence YEAR-DAY-ENCODING

        struct YEAR_DAY_ENCODING {
            YEAR_DAY_ENCODING();

            YEAR_DAY_ENCODING(integer_type arg__year,
                    const uint16_t& arg__day);

            YEAR_DAY_ENCODING(const std::string& vl);

            YEAR_DAY_ENCODING(const char* vl);

            YEAR_DAY_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(day, uint16_t); //   Ic(  [ 1  ...   366 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-YEAR-DAY-ENCODING

        struct ANY_YEAR_DAY_ENCODING {
            ANY_YEAR_DAY_ENCODING();

            ANY_YEAR_DAY_ENCODING(integer_type arg__year,
                    const uint16_t& arg__day);

            ANY_YEAR_DAY_ENCODING(const std::string& vl);

            ANY_YEAR_DAY_ENCODING(const char* vl);

            ANY_YEAR_DAY_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, ANY_YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(day, uint16_t); //   Ic(  [ 1  ...   366 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence YEAR-WEEK-ENCODING

        struct YEAR_WEEK_ENCODING {
            YEAR_WEEK_ENCODING();

            YEAR_WEEK_ENCODING(const YEAR_ENCODING& arg__year,
                    const uint8_t& arg__week);

            YEAR_WEEK_ENCODING(const std::string& vl);

            YEAR_WEEK_ENCODING(const char* vl);

            YEAR_WEEK_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-YEAR-WEEK-ENCODING

        struct ANY_YEAR_WEEK_ENCODING {
            ANY_YEAR_WEEK_ENCODING();

            ANY_YEAR_WEEK_ENCODING(const ANY_YEAR_ENCODING& arg__year,
                    const uint8_t& arg__week);

            ANY_YEAR_WEEK_ENCODING(const std::string& vl);

            ANY_YEAR_WEEK_ENCODING(const char* vl);

            ANY_YEAR_WEEK_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, ANY_YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence YEAR-WEEK-DAY-ENCODING

        struct YEAR_WEEK_DAY_ENCODING {
            YEAR_WEEK_DAY_ENCODING();

            YEAR_WEEK_DAY_ENCODING(const YEAR_ENCODING& arg__year,
                    const uint8_t& arg__week,
                    const uint8_t& arg__day);

            YEAR_WEEK_DAY_ENCODING(const std::string& vl);

            YEAR_WEEK_DAY_ENCODING(const char* vl);

            YEAR_WEEK_DAY_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   7 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-YEAR-WEEK-DAY-ENCODING

        struct ANY_YEAR_WEEK_DAY_ENCODING {
            ANY_YEAR_WEEK_DAY_ENCODING();

            ANY_YEAR_WEEK_DAY_ENCODING(const ANY_YEAR_ENCODING& arg__year,
                    const uint8_t& arg__week,
                    const uint8_t& arg__day);

            ANY_YEAR_WEEK_DAY_ENCODING(const std::string& vl);

            ANY_YEAR_WEEK_DAY_ENCODING(const char* vl);

            ANY_YEAR_WEEK_DAY_ENCODING(const base_date_time& vl);

            base_date_time as_datetime() const;

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, ANY_YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   7 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence HOURS-ENCODING

        struct HOURS_ENCODING {
            HOURS_ENCODING();

            HOURS_ENCODING(const uint8_t& arg__val);

            HOURS_ENCODING(const std::string& vl);

            HOURS_ENCODING(const char* vl);

            HOURS_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(as_number, uint8_t); //   Ic(  [ 0  ...   24 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence HOURS-UTC-ENCODING

        struct HOURS_UTC_ENCODING {
            HOURS_UTC_ENCODING();

            HOURS_UTC_ENCODING(const uint8_t& arg__val);

            HOURS_UTC_ENCODING(const std::string& vl);

            HOURS_UTC_ENCODING(const char* vl);

            HOURS_UTC_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(as_number, uint8_t); //   Ic(  [ 0  ...   24 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence TIME-DIFFERENCE

        struct TIME_DIFFERENCE {
            static const enumerated sign_positive;
            static const enumerated sign_negative;


            TIME_DIFFERENCE();

            TIME_DIFFERENCE(const int8_t& arg__hours,
                    const uint8_t& arg__minutes = 0);

            TIME_DIFFERENCE(const std::string& vl);

            TIME_DIFFERENCE(const char* vl);

            /*TIME_DIFFERENCE(const base_time_duration& vl);

            base_time_duration as_time() const;*/

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(sign, enumerated);
            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   15 ]   
            ITU_T_OPTIONAL_DECL(minutes, uint8_t); //   Ic(  [ 1  ...   59 ]   

            ITU_T_ARCHIVE_FUNC;
        };




        // sequence HOURS-AND-DIFF-ENCODING

        struct HOURS_AND_DIFF_ENCODING {
            HOURS_AND_DIFF_ENCODING();

            HOURS_AND_DIFF_ENCODING(const uint8_t& arg__local_hours,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE());

            HOURS_AND_DIFF_ENCODING(const std::string& vl);

            HOURS_AND_DIFF_ENCODING(const char* vl);

            HOURS_AND_DIFF_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(local_hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            ITU_T_ARCHIVE_FUNC;
        };




        // sequence MINUTES-ENCODING

        struct MINUTES_ENCODING {
            MINUTES_ENCODING();

            MINUTES_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes);

            MINUTES_ENCODING(const std::string& vl);

            MINUTES_ENCODING(const char* vl);

            MINUTES_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);



            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence MINUTES-UTC-ENCODING

        struct MINUTES_UTC_ENCODING {
            MINUTES_UTC_ENCODING();

            MINUTES_UTC_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes);

            MINUTES_UTC_ENCODING(const std::string& vl);

            MINUTES_UTC_ENCODING(const char* vl);

            MINUTES_UTC_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);



            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   

            ITU_T_ARCHIVE_FUNC;
        };





        // sequence MINUTES-AND-DIFF-ENCODING

        struct MINUTES_AND_DIFF_ENCODING {
            MINUTES_AND_DIFF_ENCODING();

            MINUTES_AND_DIFF_ENCODING(const MINUTES_ENCODING& arg__time,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE());

            MINUTES_AND_DIFF_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE());

            MINUTES_AND_DIFF_ENCODING(const std::string& vl);

            MINUTES_AND_DIFF_ENCODING(const char* vl);

            MINUTES_AND_DIFF_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(local_time, MINUTES_ENCODING);
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            ITU_T_ARCHIVE_FUNC;
        };






        // sequence TIME-OF-DAY-ENCODING

        struct TIME_OF_DAY_ENCODING {
            TIME_OF_DAY_ENCODING();

            TIME_OF_DAY_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds);

            TIME_OF_DAY_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(uint8_t) arg__minutes,
                    ITU_T_SHARED(uint8_t) arg__seconds);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence TIME-OF-DAY-UTC-ENCODING

        struct TIME_OF_DAY_UTC_ENCODING {
            TIME_OF_DAY_UTC_ENCODING();

            TIME_OF_DAY_UTC_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds);

            TIME_OF_DAY_UTC_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(uint8_t) arg__minutes,
                    ITU_T_SHARED(uint8_t) arg__seconds);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence TIME-OF-DAY-AND-DIFF-ENCODING

        struct TIME_OF_DAY_AND_DIFF_ENCODING {
            struct Local_time_type;

            struct Local_time_type {
                Local_time_type();

                Local_time_type(const uint8_t& arg__hours,
                        const uint8_t& arg__minutes,
                        const uint8_t& arg__seconds);

                Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                        ITU_T_SHARED(uint8_t) arg__minutes,
                        ITU_T_SHARED(uint8_t) arg__seconds);

                ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
                ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
                ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   

                ITU_T_ARCHIVE_FUNC;
            };


            TIME_OF_DAY_AND_DIFF_ENCODING();

            TIME_OF_DAY_AND_DIFF_ENCODING(const Local_time_type& arg__local_time,
                    const TIME_DIFFERENCE& arg__time_difference);

            TIME_OF_DAY_AND_DIFF_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                    ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference);

            ITU_T_HOLDERH_DECL(local_time, Local_time_type);
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence HOURS-AND-FRACTION-ENCODING

        struct HOURS_AND_FRACTION_ENCODING {
            HOURS_AND_FRACTION_ENCODING();

            HOURS_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const integer_type& arg__fraction);

            HOURS_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(integer_type) arg__fraction);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence HOURS-UTC-AND-FRACTION-ENCODING

        struct HOURS_UTC_AND_FRACTION_ENCODING {
            HOURS_UTC_AND_FRACTION_ENCODING();

            HOURS_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const integer_type& arg__fraction);

            HOURS_UTC_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(integer_type) arg__fraction);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence HOURS-AND-DIFF-AND-FRACTION-ENCODING

        struct HOURS_AND_DIFF_AND_FRACTION_ENCODING {
            HOURS_AND_DIFF_AND_FRACTION_ENCODING();

            HOURS_AND_DIFF_AND_FRACTION_ENCODING(const uint8_t& arg__local_hours,
                    const integer_type& arg__fraction,
                    const TIME_DIFFERENCE& arg__time_difference);

            HOURS_AND_DIFF_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__local_hours,
                    ITU_T_SHARED(integer_type) arg__fraction,
                    ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference);

            ITU_T_HOLDERH_DECL(local_hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence MINUTES-AND-FRACTION-ENCODING

        struct MINUTES_AND_FRACTION_ENCODING {
            MINUTES_AND_FRACTION_ENCODING();

            MINUTES_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const integer_type& arg__fraction);

            MINUTES_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(uint8_t) arg__minutes,
                    ITU_T_SHARED(integer_type) arg__fraction);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence MINUTES-UTC-AND-FRACTION-ENCODING

        struct MINUTES_UTC_AND_FRACTION_ENCODING {
            MINUTES_UTC_AND_FRACTION_ENCODING();

            MINUTES_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const integer_type& arg__fraction);

            MINUTES_UTC_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(uint8_t) arg__minutes,
                    ITU_T_SHARED(integer_type) arg__fraction);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence MINUTES-AND-DIFF-AND-FRACTION-ENCODING

        struct MINUTES_AND_DIFF_AND_FRACTION_ENCODING {
            struct Local_time_type;

            struct Local_time_type {
                Local_time_type();

                Local_time_type(const uint8_t& arg__hours,
                        const uint8_t& arg__minutes,
                        const integer_type& arg__fraction);

                Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                        ITU_T_SHARED(uint8_t) arg__minutes,
                        ITU_T_SHARED(integer_type) arg__fraction);

                ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
                ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
                ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

                ITU_T_ARCHIVE_FUNC;
            };


            MINUTES_AND_DIFF_AND_FRACTION_ENCODING();

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING(const Local_time_type& arg__local_time,
                    const TIME_DIFFERENCE& arg__time_difference);

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                    ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference);

            ITU_T_HOLDERH_DECL(local_time, Local_time_type);
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence TIME-OF-DAY-AND-FRACTION-ENCODING

        struct TIME_OF_DAY_AND_FRACTION_ENCODING {
            TIME_OF_DAY_AND_FRACTION_ENCODING();

            TIME_OF_DAY_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds,
                    const integer_type& arg__fraction);

            TIME_OF_DAY_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(uint8_t) arg__minutes,
                    ITU_T_SHARED(uint8_t) arg__seconds,
                    ITU_T_SHARED(integer_type) arg__fraction);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence TIME-OF-DAY-UTC-AND-FRACTION-ENCODING

        struct TIME_OF_DAY_UTC_AND_FRACTION_ENCODING {
            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING();

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds,
                    const integer_type& arg__fraction);

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(ITU_T_SHARED(uint8_t) arg__hours,
                    ITU_T_SHARED(uint8_t) arg__minutes,
                    ITU_T_SHARED(uint8_t) arg__seconds,
                    ITU_T_SHARED(integer_type) arg__fraction);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   
            ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        struct TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING {
            struct Local_time_type;

            struct Local_time_type {
                Local_time_type();

                Local_time_type(const uint8_t& arg__hours,
                        const uint8_t& arg__minutes,
                        const uint8_t& arg__seconds,
                        const integer_type& arg__fraction);

                Local_time_type(ITU_T_SHARED(uint8_t) arg__hours,
                        ITU_T_SHARED(uint8_t) arg__minutes,
                        ITU_T_SHARED(uint8_t) arg__seconds,
                        ITU_T_SHARED(integer_type) arg__fraction);

                ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
                ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
                ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   
                ITU_T_HOLDERH_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

                ITU_T_ARCHIVE_FUNC;
            };


            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING();

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(const Local_time_type& arg__local_time,
                    const TIME_DIFFERENCE& arg__time_difference);

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(ITU_T_SHARED(Local_time_type) arg__local_time,
                    ITU_T_SHARED(TIME_DIFFERENCE) arg__time_difference);

            ITU_T_HOLDERH_DECL(local_time, Local_time_type);
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence DURATION-INTERVAL-ENCODING

        struct DURATION_INTERVAL_ENCODING {
            struct Fractional_part_type;

            struct Fractional_part_type {
                Fractional_part_type();

                Fractional_part_type(const integer_type& arg__number_of_digits,
                        const integer_type& arg__fractional_value);

                Fractional_part_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(integer_type) arg__fractional_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...   3 ]   ...ext...) 
                ITU_T_HOLDERH_DECL(fractional_value, integer_type); //   Ic(  [ 1  ...   999 ]   ...ext...) 

                ITU_T_ARCHIVE_FUNC;
            };


            DURATION_INTERVAL_ENCODING();

            DURATION_INTERVAL_ENCODING(ITU_T_SHARED(integer_type) arg__years,
                    ITU_T_SHARED(integer_type) arg__months,
                    ITU_T_SHARED(integer_type) arg__weeks,
                    ITU_T_SHARED(integer_type) arg__days,
                    ITU_T_SHARED(integer_type) arg__hours,
                    ITU_T_SHARED(integer_type) arg__minutes,
                    ITU_T_SHARED(integer_type) arg__seconds,
                    ITU_T_SHARED(Fractional_part_type) arg__fractional_part);

            ITU_T_OPTIONAL_DECL(years, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(months, integer_type); //   Ic(  [ 0  ...   15 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(weeks, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(days, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(hours, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(minutes, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(seconds, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(fractional_part, Fractional_part_type);

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence REC-DURATION-INTERVAL-ENCODING

        struct REC_DURATION_INTERVAL_ENCODING {
            REC_DURATION_INTERVAL_ENCODING();

            REC_DURATION_INTERVAL_ENCODING(const DURATION_INTERVAL_ENCODING& arg__duration);

            REC_DURATION_INTERVAL_ENCODING(ITU_T_SHARED(integer_type) arg__recurrence,
                    ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

            ITU_T_OPTIONAL_DECL(recurrence, integer_type);
            ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

            ITU_T_ARCHIVE_FUNC;
        };

        // choice MIXED-ENCODING

        enum MIXED_ENCODING_enum {
            MIXED_ENCODING_null = 0,
            MIXED_ENCODING_date_C_Basic,
            MIXED_ENCODING_date_C_L,
            MIXED_ENCODING_date_Y_Basic,
            MIXED_ENCODING_date_Y_L,
            MIXED_ENCODING_date_YM_Basic,
            MIXED_ENCODING_date_YM_L,
            MIXED_ENCODING_date_YMD_Basic,
            MIXED_ENCODING_date_YMD_L,
            MIXED_ENCODING_date_YD_Basic,
            MIXED_ENCODING_date_YD_L,
            MIXED_ENCODING_date_YW_Basic,
            MIXED_ENCODING_date_YW_L,
            MIXED_ENCODING_date_YWD_Basic,
            MIXED_ENCODING_date_YWD_L,
            MIXED_ENCODING_time_H_L,
            MIXED_ENCODING_time_H_Z,
            MIXED_ENCODING_time_H_LD,
            MIXED_ENCODING_time_HM_L,
            MIXED_ENCODING_time_HM_Z,
            MIXED_ENCODING_time_HM_LD,
            MIXED_ENCODING_time_HMS_L,
            MIXED_ENCODING_time_HMS_Z,
            MIXED_ENCODING_time_HMS_LD,
            MIXED_ENCODING_time_HFn_L,
            MIXED_ENCODING_time_HFn_Z,
            MIXED_ENCODING_time_HFn_LD,
            MIXED_ENCODING_time_HMFn_L,
            MIXED_ENCODING_time_HMFn_Z,
            MIXED_ENCODING_time_HMFn_LD,
            MIXED_ENCODING_time_HMFSn_L,
            MIXED_ENCODING_time_HMFSn_Z,
            MIXED_ENCODING_time_HMFSn_LD,
            MIXED_ENCODING_date_time,
            MIXED_ENCODING_iterval_SE_Date,
            MIXED_ENCODING_iterval_SE_Time,
            MIXED_ENCODING_iterval_SE_Date_Time,
            MIXED_ENCODING_iterval_D,
            MIXED_ENCODING_iterval_SD_Date,
            MIXED_ENCODING_iterval_SD_Time,
            MIXED_ENCODING_iterval_SD_Date_Time,
            MIXED_ENCODING_iterval_DE_Date,
            MIXED_ENCODING_iterval_DE_Time,
            MIXED_ENCODING_iterval_DE_Date_Time,
            MIXED_ENCODING_rec_Interval_SE_Date,
            MIXED_ENCODING_rec_Interval_SE_Time,
            MIXED_ENCODING_rec_Interval_SE_Date_Time,
            MIXED_ENCODING_rec_Interval_D,
            MIXED_ENCODING_rec_Interval_SD_Date,
            MIXED_ENCODING_rec_Interval_SD_Time,
            MIXED_ENCODING_rec_Interval_SD_Date_Time,
            MIXED_ENCODING_rec_Interval_DE_Date,
            MIXED_ENCODING_rec_Interval_DE_Time,
            MIXED_ENCODING_rec_Interval_DE_Date_Time,
        };

        struct MIXED_ENCODING : public ITU_T_CHOICE(MIXED_ENCODING_enum) {


            struct Time_HFn_L_type;
            struct Time_HFn_Z_type;
            struct Time_HFn_LD_type;
            struct Time_HMFn_L_type;
            struct Time_HMFn_Z_type;
            struct Time_HMFn_LD_type;
            struct Time_HMFSn_L_type;
            struct Time_HMFSn_Z_type;
            struct Time_HMFSn_LD_type;
            struct Date_time_type;
            struct Iterval_SE_Date_type;
            struct Iterval_SE_Time_type;
            struct Iterval_SE_Date_Time_type;
            struct Iterval_SD_Date_type;
            struct Iterval_SD_Time_type;
            struct Iterval_SD_Date_Time_type;
            struct Iterval_DE_Date_type;
            struct Iterval_DE_Time_type;
            struct Iterval_DE_Date_Time_type;
            struct Rec_Interval_SE_Date_type;
            struct Rec_Interval_SE_Time_type;
            struct Rec_Interval_SE_Date_Time_type;
            struct Rec_Interval_SD_Date_type;
            struct Rec_Interval_SD_Time_type;
            struct Rec_Interval_SD_Date_Time_type;
            struct Rec_Interval_DE_Date_type;
            struct Rec_Interval_DE_Time_type;
            struct Rec_Interval_DE_Date_Time_type;

            struct Time_HFn_L_type {
                Time_HFn_L_type();

                Time_HFn_L_type(const integer_type& arg__number_of_digits,
                        const HOURS_AND_FRACTION_ENCODING& arg__time_value);

                Time_HFn_L_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(HOURS_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, HOURS_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HFn_Z_type {
                Time_HFn_Z_type();

                Time_HFn_Z_type(const integer_type& arg__number_of_digits,
                        const HOURS_UTC_AND_FRACTION_ENCODING& arg__time_value);

                Time_HFn_Z_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(HOURS_UTC_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, HOURS_UTC_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HFn_LD_type {
                Time_HFn_LD_type();

                Time_HFn_LD_type(const integer_type& arg__number_of_digits,
                        const HOURS_AND_DIFF_AND_FRACTION_ENCODING& arg__time_value);

                Time_HFn_LD_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(HOURS_AND_DIFF_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, HOURS_AND_DIFF_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HMFn_L_type {
                Time_HMFn_L_type();

                Time_HMFn_L_type(const integer_type& arg__number_of_digits,
                        const MINUTES_AND_FRACTION_ENCODING& arg__time_value);

                Time_HMFn_L_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(MINUTES_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, MINUTES_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HMFn_Z_type {
                Time_HMFn_Z_type();

                Time_HMFn_Z_type(const integer_type& arg__number_of_digits,
                        const MINUTES_UTC_AND_FRACTION_ENCODING& arg__time_value);

                Time_HMFn_Z_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(MINUTES_UTC_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, MINUTES_UTC_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HMFn_LD_type {
                Time_HMFn_LD_type();

                Time_HMFn_LD_type(const integer_type& arg__number_of_digits,
                        const MINUTES_AND_DIFF_AND_FRACTION_ENCODING& arg__time_value);

                Time_HMFn_LD_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(MINUTES_AND_DIFF_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, MINUTES_AND_DIFF_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HMFSn_L_type {
                Time_HMFSn_L_type();

                Time_HMFSn_L_type(const integer_type& arg__number_of_digits,
                        const TIME_OF_DAY_AND_FRACTION_ENCODING& arg__time_value);

                Time_HMFSn_L_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(TIME_OF_DAY_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, TIME_OF_DAY_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HMFSn_Z_type {
                Time_HMFSn_Z_type();

                Time_HMFSn_Z_type(const integer_type& arg__number_of_digits,
                        const TIME_OF_DAY_UTC_AND_FRACTION_ENCODING& arg__time_value);

                Time_HMFSn_Z_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Time_HMFSn_LD_type {
                Time_HMFSn_LD_type();

                Time_HMFSn_LD_type(const integer_type& arg__number_of_digits,
                        const TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING& arg__time_value);

                Time_HMFSn_LD_type(ITU_T_SHARED(integer_type) arg__number_of_digits,
                        ITU_T_SHARED(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING) arg__time_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
                ITU_T_HOLDERH_DECL(time_value, TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Date_time_type {
                Date_time_type();

                Date_time_type(const DATE_TYPE& arg__date,
                        const TIME_TYPE& arg__time);

                Date_time_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                        ITU_T_SHARED(TIME_TYPE) arg__time);

                ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_SE_Date_type {
                Iterval_SE_Date_type();

                Iterval_SE_Date_type(const DATE_TYPE& arg__start,
                        const DATE_TYPE& arg__end);

                Iterval_SE_Date_type(ITU_T_SHARED(DATE_TYPE) arg__start,
                        ITU_T_SHARED(DATE_TYPE) arg__end);

                ITU_T_HOLDERH_DECL(start, DATE_TYPE);
                ITU_T_HOLDERH_DECL(end, DATE_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_SE_Time_type {
                Iterval_SE_Time_type();

                Iterval_SE_Time_type(const TIME_TYPE& arg__start,
                        const TIME_TYPE& arg__end);

                Iterval_SE_Time_type(ITU_T_SHARED(TIME_TYPE) arg__start,
                        ITU_T_SHARED(TIME_TYPE) arg__end);

                ITU_T_HOLDERH_DECL(start, TIME_TYPE);
                ITU_T_HOLDERH_DECL(end, TIME_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_SE_Date_Time_type {
                struct Start_type;
                struct End_type;

                struct Start_type {
                    Start_type();

                    Start_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };

                struct End_type {
                    End_type();

                    End_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };


                Iterval_SE_Date_Time_type();

                Iterval_SE_Date_Time_type(const Start_type& arg__start,
                        const End_type& arg__end);

                Iterval_SE_Date_Time_type(ITU_T_SHARED(Start_type) arg__start,
                        ITU_T_SHARED(End_type) arg__end);

                ITU_T_HOLDERH_DECL(start, Start_type);
                ITU_T_HOLDERH_DECL(end, End_type);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_SD_Date_type {
                Iterval_SD_Date_type();

                Iterval_SD_Date_type(const DATE_TYPE& arg__start,
                        const DURATION_INTERVAL_ENCODING& arg__duration);

                Iterval_SD_Date_type(ITU_T_SHARED(DATE_TYPE) arg__start,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

                ITU_T_HOLDERH_DECL(start, DATE_TYPE);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_SD_Time_type {
                Iterval_SD_Time_type();

                Iterval_SD_Time_type(const TIME_TYPE& arg__start,
                        const DURATION_INTERVAL_ENCODING& arg__duration);

                Iterval_SD_Time_type(ITU_T_SHARED(TIME_TYPE) arg__start,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

                ITU_T_HOLDERH_DECL(start, TIME_TYPE);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_SD_Date_Time_type {
                struct Start_type;

                struct Start_type {
                    Start_type();

                    Start_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };


                Iterval_SD_Date_Time_type();

                Iterval_SD_Date_Time_type(const Start_type& arg__start,
                        const DURATION_INTERVAL_ENCODING& arg__duration);

                Iterval_SD_Date_Time_type(ITU_T_SHARED(Start_type) arg__start,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

                ITU_T_HOLDERH_DECL(start, Start_type);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_DE_Date_type {
                Iterval_DE_Date_type();

                Iterval_DE_Date_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                        const DATE_TYPE& arg__end);

                Iterval_DE_Date_type(ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                        ITU_T_SHARED(DATE_TYPE) arg__end);

                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);
                ITU_T_HOLDERH_DECL(end, DATE_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_DE_Time_type {
                Iterval_DE_Time_type();

                Iterval_DE_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                        const TIME_TYPE& arg__end);

                Iterval_DE_Time_type(ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                        ITU_T_SHARED(TIME_TYPE) arg__end);

                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);
                ITU_T_HOLDERH_DECL(end, TIME_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Iterval_DE_Date_Time_type {
                struct End_type;

                struct End_type {
                    End_type();

                    End_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };


                Iterval_DE_Date_Time_type();

                Iterval_DE_Date_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                        const End_type& arg__end);

                Iterval_DE_Date_Time_type(ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                        ITU_T_SHARED(End_type) arg__end);

                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);
                ITU_T_HOLDERH_DECL(end, End_type);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_SE_Date_type {
                Rec_Interval_SE_Date_type();

                Rec_Interval_SE_Date_type(const DATE_TYPE& arg__start,
                        const DATE_TYPE& arg__end);

                Rec_Interval_SE_Date_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(DATE_TYPE) arg__start,
                        ITU_T_SHARED(DATE_TYPE) arg__end);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(start, DATE_TYPE);
                ITU_T_HOLDERH_DECL(end, DATE_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_SE_Time_type {
                Rec_Interval_SE_Time_type();

                Rec_Interval_SE_Time_type(const TIME_TYPE& arg__start,
                        const TIME_TYPE& arg__end);

                Rec_Interval_SE_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(TIME_TYPE) arg__start,
                        ITU_T_SHARED(TIME_TYPE) arg__end);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(start, TIME_TYPE);
                ITU_T_HOLDERH_DECL(end, TIME_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_SE_Date_Time_type {
                struct Start_type;
                struct End_type;

                struct Start_type {
                    Start_type();

                    Start_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };

                struct End_type {
                    End_type();

                    End_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };


                Rec_Interval_SE_Date_Time_type();

                Rec_Interval_SE_Date_Time_type(const Start_type& arg__start,
                        const End_type& arg__end);

                Rec_Interval_SE_Date_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(Start_type) arg__start,
                        ITU_T_SHARED(End_type) arg__end);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(start, Start_type);
                ITU_T_HOLDERH_DECL(end, End_type);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_SD_Date_type {
                Rec_Interval_SD_Date_type();

                Rec_Interval_SD_Date_type(const DATE_TYPE& arg__start,
                        const DURATION_INTERVAL_ENCODING& arg__duration);

                Rec_Interval_SD_Date_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(DATE_TYPE) arg__start,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(start, DATE_TYPE);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_SD_Time_type {
                Rec_Interval_SD_Time_type();

                Rec_Interval_SD_Time_type(const TIME_TYPE& arg__start,
                        const DURATION_INTERVAL_ENCODING& arg__duration);

                Rec_Interval_SD_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(TIME_TYPE) arg__start,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(start, TIME_TYPE);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_SD_Date_Time_type {
                struct Start_type;

                struct Start_type {
                    Start_type();

                    Start_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    Start_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };


                Rec_Interval_SD_Date_Time_type();

                Rec_Interval_SD_Date_Time_type(const Start_type& arg__start,
                        const DURATION_INTERVAL_ENCODING& arg__duration);

                Rec_Interval_SD_Date_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(Start_type) arg__start,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(start, Start_type);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_DE_Date_type {
                Rec_Interval_DE_Date_type();

                Rec_Interval_DE_Date_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                        const DATE_TYPE& arg__end);

                Rec_Interval_DE_Date_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                        ITU_T_SHARED(DATE_TYPE) arg__end);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);
                ITU_T_HOLDERH_DECL(end, DATE_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_DE_Time_type {
                Rec_Interval_DE_Time_type();

                Rec_Interval_DE_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                        const TIME_TYPE& arg__end);

                Rec_Interval_DE_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                        ITU_T_SHARED(TIME_TYPE) arg__end);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);
                ITU_T_HOLDERH_DECL(end, TIME_TYPE);

                ITU_T_ARCHIVE_FUNC;
            };

            struct Rec_Interval_DE_Date_Time_type {
                struct End_type;

                struct End_type {
                    End_type();

                    End_type(const DATE_TYPE& arg__date,
                            const TIME_TYPE& arg__time);

                    End_type(ITU_T_SHARED(DATE_TYPE) arg__date,
                            ITU_T_SHARED(TIME_TYPE) arg__time);

                    ITU_T_HOLDERH_DECL(date, DATE_TYPE);
                    ITU_T_HOLDERH_DECL(time, TIME_TYPE);

                    ITU_T_ARCHIVE_FUNC;
                };


                Rec_Interval_DE_Date_Time_type();

                Rec_Interval_DE_Date_Time_type(const DURATION_INTERVAL_ENCODING& arg__duration,
                        const End_type& arg__end);

                Rec_Interval_DE_Date_Time_type(ITU_T_SHARED(integer_type) arg__recurrence,
                        ITU_T_SHARED(DURATION_INTERVAL_ENCODING) arg__duration,
                        ITU_T_SHARED(End_type) arg__end);

                ITU_T_OPTIONAL_DECL(recurrence, integer_type);
                ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);
                ITU_T_HOLDERH_DECL(end, End_type);

                ITU_T_ARCHIVE_FUNC;
            };


            ITU_T_CHOICE_CTORS(MIXED_ENCODING);

            ITU_T_CHOICEC_DECL(date_C_Basic, CENTURY_ENCODING, MIXED_ENCODING_date_C_Basic);
            ITU_T_CHOICEC_DECL(date_C_L, ANY_CENTURY_ENCODING, MIXED_ENCODING_date_C_L);
            ITU_T_CHOICEC_DECL(date_Y_Basic, YEAR_ENCODING, MIXED_ENCODING_date_Y_Basic);
            ITU_T_CHOICEC_DECL(date_Y_L, ANY_YEAR_ENCODING, MIXED_ENCODING_date_Y_L);
            ITU_T_CHOICEC_DECL(date_YM_Basic, YEAR_MONTH_ENCODING, MIXED_ENCODING_date_YM_Basic);
            ITU_T_CHOICEC_DECL(date_YM_L, ANY_YEAR_MONTH_ENCODING, MIXED_ENCODING_date_YM_L);
            ITU_T_CHOICEC_DECL(date_YMD_Basic, DATE_ENCODING, MIXED_ENCODING_date_YMD_Basic);
            ITU_T_CHOICEC_DECL(date_YMD_L, ANY_DATE_ENCODING, MIXED_ENCODING_date_YMD_L);
            ITU_T_CHOICEC_DECL(date_YD_Basic, YEAR_DAY_ENCODING, MIXED_ENCODING_date_YD_Basic);
            ITU_T_CHOICEC_DECL(date_YD_L, ANY_YEAR_DAY_ENCODING, MIXED_ENCODING_date_YD_L);
            ITU_T_CHOICEC_DECL(date_YW_Basic, YEAR_WEEK_ENCODING, MIXED_ENCODING_date_YW_Basic);
            ITU_T_CHOICEC_DECL(date_YW_L, ANY_YEAR_WEEK_ENCODING, MIXED_ENCODING_date_YW_L);
            ITU_T_CHOICEC_DECL(date_YWD_Basic, YEAR_WEEK_DAY_ENCODING, MIXED_ENCODING_date_YWD_Basic);
            ITU_T_CHOICEC_DECL(date_YWD_L, ANY_YEAR_WEEK_DAY_ENCODING, MIXED_ENCODING_date_YWD_L);
            ITU_T_CHOICEC_DECL(time_H_L, HOURS_ENCODING, MIXED_ENCODING_time_H_L);
            ITU_T_CHOICEC_DECL(time_H_Z, HOURS_UTC_ENCODING, MIXED_ENCODING_time_H_Z);
            ITU_T_CHOICEC_DECL(time_H_LD, HOURS_AND_DIFF_ENCODING, MIXED_ENCODING_time_H_LD);
            ITU_T_CHOICEC_DECL(time_HM_L, MINUTES_ENCODING, MIXED_ENCODING_time_HM_L);
            ITU_T_CHOICEC_DECL(time_HM_Z, MINUTES_UTC_ENCODING, MIXED_ENCODING_time_HM_Z);
            ITU_T_CHOICEC_DECL(time_HM_LD, MINUTES_AND_DIFF_ENCODING, MIXED_ENCODING_time_HM_LD);
            ITU_T_CHOICEC_DECL(time_HMS_L, TIME_OF_DAY_ENCODING, MIXED_ENCODING_time_HMS_L);
            ITU_T_CHOICEC_DECL(time_HMS_Z, TIME_OF_DAY_UTC_ENCODING, MIXED_ENCODING_time_HMS_Z);
            ITU_T_CHOICEC_DECL(time_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, MIXED_ENCODING_time_HMS_LD);
            ITU_T_CHOICEC_DECL(time_HFn_L, Time_HFn_L_type, MIXED_ENCODING_time_HFn_L);
            ITU_T_CHOICEC_DECL(time_HFn_Z, Time_HFn_Z_type, MIXED_ENCODING_time_HFn_Z);
            ITU_T_CHOICEC_DECL(time_HFn_LD, Time_HFn_LD_type, MIXED_ENCODING_time_HFn_LD);
            ITU_T_CHOICEC_DECL(time_HMFn_L, Time_HMFn_L_type, MIXED_ENCODING_time_HMFn_L);
            ITU_T_CHOICEC_DECL(time_HMFn_Z, Time_HMFn_Z_type, MIXED_ENCODING_time_HMFn_Z);
            ITU_T_CHOICEC_DECL(time_HMFn_LD, Time_HMFn_LD_type, MIXED_ENCODING_time_HMFn_LD);
            ITU_T_CHOICEC_DECL(time_HMFSn_L, Time_HMFSn_L_type, MIXED_ENCODING_time_HMFSn_L);
            ITU_T_CHOICEC_DECL(time_HMFSn_Z, Time_HMFSn_Z_type, MIXED_ENCODING_time_HMFSn_Z);
            ITU_T_CHOICEC_DECL(time_HMFSn_LD, Time_HMFSn_LD_type, MIXED_ENCODING_time_HMFSn_LD);
            ITU_T_CHOICEC_DECL(date_time, Date_time_type, MIXED_ENCODING_date_time);
            ITU_T_CHOICEC_DECL(iterval_SE_Date, Iterval_SE_Date_type, MIXED_ENCODING_iterval_SE_Date);
            ITU_T_CHOICEC_DECL(iterval_SE_Time, Iterval_SE_Time_type, MIXED_ENCODING_iterval_SE_Time);
            ITU_T_CHOICEC_DECL(iterval_SE_Date_Time, Iterval_SE_Date_Time_type, MIXED_ENCODING_iterval_SE_Date_Time);
            ITU_T_CHOICEC_DECL(iterval_D, DURATION_INTERVAL_ENCODING, MIXED_ENCODING_iterval_D);
            ITU_T_CHOICEC_DECL(iterval_SD_Date, Iterval_SD_Date_type, MIXED_ENCODING_iterval_SD_Date);
            ITU_T_CHOICEC_DECL(iterval_SD_Time, Iterval_SD_Time_type, MIXED_ENCODING_iterval_SD_Time);
            ITU_T_CHOICEC_DECL(iterval_SD_Date_Time, Iterval_SD_Date_Time_type, MIXED_ENCODING_iterval_SD_Date_Time);
            ITU_T_CHOICEC_DECL(iterval_DE_Date, Iterval_DE_Date_type, MIXED_ENCODING_iterval_DE_Date);
            ITU_T_CHOICEC_DECL(iterval_DE_Time, Iterval_DE_Time_type, MIXED_ENCODING_iterval_DE_Time);
            ITU_T_CHOICEC_DECL(iterval_DE_Date_Time, Iterval_DE_Date_Time_type, MIXED_ENCODING_iterval_DE_Date_Time);
            ITU_T_CHOICEC_DECL(rec_Interval_SE_Date, Rec_Interval_SE_Date_type, MIXED_ENCODING_rec_Interval_SE_Date);
            ITU_T_CHOICEC_DECL(rec_Interval_SE_Time, Rec_Interval_SE_Time_type, MIXED_ENCODING_rec_Interval_SE_Time);
            ITU_T_CHOICEC_DECL(rec_Interval_SE_Date_Time, Rec_Interval_SE_Date_Time_type, MIXED_ENCODING_rec_Interval_SE_Date_Time);
            ITU_T_CHOICEC_DECL(rec_Interval_D, REC_DURATION_INTERVAL_ENCODING, MIXED_ENCODING_rec_Interval_D);
            ITU_T_CHOICEC_DECL(rec_Interval_SD_Date, Rec_Interval_SD_Date_type, MIXED_ENCODING_rec_Interval_SD_Date);
            ITU_T_CHOICEC_DECL(rec_Interval_SD_Time, Rec_Interval_SD_Time_type, MIXED_ENCODING_rec_Interval_SD_Time);
            ITU_T_CHOICEC_DECL(rec_Interval_SD_Date_Time, Rec_Interval_SD_Date_Time_type, MIXED_ENCODING_rec_Interval_SD_Date_Time);
            ITU_T_CHOICEC_DECL(rec_Interval_DE_Date, Rec_Interval_DE_Date_type, MIXED_ENCODING_rec_Interval_DE_Date);
            ITU_T_CHOICEC_DECL(rec_Interval_DE_Time, Rec_Interval_DE_Time_type, MIXED_ENCODING_rec_Interval_DE_Time);
            ITU_T_CHOICEC_DECL(rec_Interval_DE_Date_Time, Rec_Interval_DE_Date_Time_type, MIXED_ENCODING_rec_Interval_DE_Date_Time);

            ITU_T_ARCHIVE_FUNC;
        };

        // choice DATE-TYPE

        enum DATE_TYPE_enum {
            DATE_TYPE_null = 0,
            DATE_TYPE_dt_C_Basic,
            DATE_TYPE_dt_C_L,
            DATE_TYPE_dt_Y_Basic,
            DATE_TYPE_dt_Y_L,
            DATE_TYPE_dt_YM_Basic,
            DATE_TYPE_dt_YM_L,
            DATE_TYPE_dt_YMD_Basic,
            DATE_TYPE_dt_YMD_L,
            DATE_TYPE_dt_YD_Basic,
            DATE_TYPE_dt_YD_L,
            DATE_TYPE_dt_YW_Basic,
            DATE_TYPE_dt_YW_L,
            DATE_TYPE_dt_YWD_Basic,
            DATE_TYPE_dt_YWD_L,
        };

        struct DATE_TYPE : public ITU_T_CHOICE(DATE_TYPE_enum) {


            ITU_T_CHOICE_CTORS(DATE_TYPE);

            ITU_T_CHOICEC_DECL(dt_C_Basic, CENTURY_ENCODING, DATE_TYPE_dt_C_Basic);
            ITU_T_CHOICEC_DECL(dt_C_L, ANY_CENTURY_ENCODING, DATE_TYPE_dt_C_L);
            ITU_T_CHOICEC_DECL(dt_Y_Basic, YEAR_ENCODING, DATE_TYPE_dt_Y_Basic);
            ITU_T_CHOICEC_DECL(dt_Y_L, ANY_YEAR_ENCODING, DATE_TYPE_dt_Y_L);
            ITU_T_CHOICEC_DECL(dt_YM_Basic, YEAR_MONTH_ENCODING, DATE_TYPE_dt_YM_Basic);
            ITU_T_CHOICEC_DECL(dt_YM_L, ANY_YEAR_MONTH_ENCODING, DATE_TYPE_dt_YM_L);
            ITU_T_CHOICEC_DECL(dt_YMD_Basic, DATE_ENCODING, DATE_TYPE_dt_YMD_Basic);
            ITU_T_CHOICEC_DECL(dt_YMD_L, ANY_DATE_ENCODING, DATE_TYPE_dt_YMD_L);
            ITU_T_CHOICEC_DECL(dt_YD_Basic, YEAR_DAY_ENCODING, DATE_TYPE_dt_YD_Basic);
            ITU_T_CHOICEC_DECL(dt_YD_L, ANY_YEAR_DAY_ENCODING, DATE_TYPE_dt_YD_L);
            ITU_T_CHOICEC_DECL(dt_YW_Basic, YEAR_WEEK_ENCODING, DATE_TYPE_dt_YW_Basic);
            ITU_T_CHOICEC_DECL(dt_YW_L, ANY_YEAR_WEEK_ENCODING, DATE_TYPE_dt_YW_L);
            ITU_T_CHOICEC_DECL(dt_YWD_Basic, YEAR_WEEK_DAY_ENCODING, DATE_TYPE_dt_YWD_Basic);
            ITU_T_CHOICEC_DECL(dt_YWD_L, ANY_YEAR_WEEK_DAY_ENCODING, DATE_TYPE_dt_YWD_L);

            ITU_T_ARCHIVE_FUNC;
        };

        // sequence TIME-TYPE

        struct TIME_TYPE {
            struct Time_type_type;

            enum Time_type_type_enum {
                Time_type_type_null = 0,
                Time_type_type_tm_H_L,
                Time_type_type_tm_H_Z,
                Time_type_type_tm_H_LD,
                Time_type_type_tm_HM_L,
                Time_type_type_tm_HM_Z,
                Time_type_type_tm_HM_LD,
                Time_type_type_tm_HMS_L,
                Time_type_type_tm_HMS_Z,
                Time_type_type_tm_HMS_LD,
                Time_type_type_tm_HFn_L,
                Time_type_type_tm_HFn_Z,
                Time_type_type_tm_HFn_LD,
                Time_type_type_tm_HMFn_L,
                Time_type_type_tm_HMFn_Z,
                Time_type_type_tm_HMFn_LD,
                Time_type_type_tm_HMFSn_L,
                Time_type_type_tm_HMFSn_Z,
                Time_type_type_tm_HMFSn_LD,
            };

            struct Time_type_type : public ITU_T_CHOICE(Time_type_type_enum) {


                ITU_T_CHOICE_CTORS(Time_type_type);

                ITU_T_CHOICEC_DECL(tm_H_L, HOURS_ENCODING, Time_type_type_tm_H_L);
                ITU_T_CHOICEC_DECL(tm_H_Z, HOURS_UTC_ENCODING, Time_type_type_tm_H_Z);
                ITU_T_CHOICEC_DECL(tm_H_LD, HOURS_AND_DIFF_ENCODING, Time_type_type_tm_H_LD);
                ITU_T_CHOICEC_DECL(tm_HM_L, MINUTES_ENCODING, Time_type_type_tm_HM_L);
                ITU_T_CHOICEC_DECL(tm_HM_Z, MINUTES_UTC_ENCODING, Time_type_type_tm_HM_Z);
                ITU_T_CHOICEC_DECL(tm_HM_LD, MINUTES_AND_DIFF_ENCODING, Time_type_type_tm_HM_LD);
                ITU_T_CHOICEC_DECL(tm_HMS_L, TIME_OF_DAY_ENCODING, Time_type_type_tm_HMS_L);
                ITU_T_CHOICEC_DECL(tm_HMS_Z, TIME_OF_DAY_UTC_ENCODING, Time_type_type_tm_HMS_Z);
                ITU_T_CHOICEC_DECL(tm_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, Time_type_type_tm_HMS_LD);
                ITU_T_CHOICEC_DECL(tm_HFn_L, HOURS_AND_FRACTION_ENCODING, Time_type_type_tm_HFn_L);
                ITU_T_CHOICEC_DECL(tm_HFn_Z, HOURS_UTC_AND_FRACTION_ENCODING, Time_type_type_tm_HFn_Z);
                ITU_T_CHOICEC_DECL(tm_HFn_LD, HOURS_AND_DIFF_AND_FRACTION_ENCODING, Time_type_type_tm_HFn_LD);
                ITU_T_CHOICEC_DECL(tm_HMFn_L, MINUTES_AND_FRACTION_ENCODING, Time_type_type_tm_HMFn_L);
                ITU_T_CHOICEC_DECL(tm_HMFn_Z, MINUTES_UTC_AND_FRACTION_ENCODING, Time_type_type_tm_HMFn_Z);
                ITU_T_CHOICEC_DECL(tm_HMFn_LD, MINUTES_AND_DIFF_AND_FRACTION_ENCODING, Time_type_type_tm_HMFn_LD);
                ITU_T_CHOICEC_DECL(tm_HMFSn_L, TIME_OF_DAY_AND_FRACTION_ENCODING, Time_type_type_tm_HMFSn_L);
                ITU_T_CHOICEC_DECL(tm_HMFSn_Z, TIME_OF_DAY_UTC_AND_FRACTION_ENCODING, Time_type_type_tm_HMFSn_Z);
                ITU_T_CHOICEC_DECL(tm_HMFSn_LD, TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING, Time_type_type_tm_HMFSn_LD);

                ITU_T_ARCHIVE_FUNC;
            };


            TIME_TYPE();

            TIME_TYPE(const Time_type_type& arg__time_type);

            TIME_TYPE(ITU_T_SHARED(integer_type) arg__number_of_digits,
                    ITU_T_SHARED(Time_type_type) arg__time_type);

            ITU_T_OPTIONAL_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...    ]   
            ITU_T_HOLDERH_DECL(time_type, Time_type_type);

            ITU_T_ARCHIVE_FUNC;
        };

        // struct var



        // std::cout methods

        std::ostream& operator<<(std::ostream& stream, const CENTURY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_CENTURY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const YEAR_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const YEAR_MONTH_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_MONTH_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const DATE_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_DATE_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const YEAR_DAY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_DAY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const YEAR_WEEK_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_WEEK_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const YEAR_WEEK_DAY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const ANY_YEAR_WEEK_DAY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const HOURS_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const HOURS_UTC_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const HOURS_AND_DIFF_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_DIFFERENCE& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_UTC_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_UTC_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const HOURS_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const HOURS_UTC_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const HOURS_AND_DIFF_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_UTC_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_UTC_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const DURATION_INTERVAL_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const DURATION_INTERVAL_ENCODING::Fractional_part_type& vl);
        std::ostream& operator<<(std::ostream& stream, const REC_DURATION_INTERVAL_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HFn_L_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HFn_Z_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HFn_LD_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFn_L_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFn_Z_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFn_LD_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFSn_L_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFSn_Z_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Time_HMFSn_LD_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Date_time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Date_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Date_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Date_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Date_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Date_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Date_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Date_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Date_Time_type& vl);
        std::ostream& operator<<(std::ostream& stream, const MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type& vl);
        std::ostream& operator<<(std::ostream& stream, const DATE_TYPE& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_TYPE& vl);
        std::ostream& operator<<(std::ostream& stream, const TIME_TYPE::Time_type_type& vl);

        ITU_T_ARCHIVE_X690_DECL(CENTURY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_CENTURY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(YEAR_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_YEAR_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(YEAR_MONTH_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_YEAR_MONTH_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(DATE_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_DATE_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(YEAR_DAY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_YEAR_DAY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(YEAR_WEEK_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_YEAR_WEEK_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(YEAR_WEEK_DAY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(ANY_YEAR_WEEK_DAY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(HOURS_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(HOURS_UTC_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(HOURS_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_DIFFERENCE);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_UTC_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_UTC_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type);
        ITU_T_ARCHIVE_X690_DECL(HOURS_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(HOURS_UTC_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(HOURS_AND_DIFF_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_UTC_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_AND_DIFF_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type);
        ITU_T_ARCHIVE_X690_DECL(DURATION_INTERVAL_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(DURATION_INTERVAL_ENCODING::Fractional_part_type);
        ITU_T_ARCHIVE_X690_DECL(REC_DURATION_INTERVAL_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HFn_L_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HFn_Z_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HFn_LD_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HMFn_L_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HMFn_Z_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HMFn_LD_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HMFSn_L_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HMFSn_Z_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Time_HMFSn_LD_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Date_time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SE_Date_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SE_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SE_Date_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SD_Date_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SD_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SD_Date_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_DE_Date_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_DE_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_DE_Date_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SE_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SD_Date_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SD_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_DE_Date_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_DE_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type);
        ITU_T_ARCHIVE_X690_DECL(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X690_DECL(DATE_TYPE);
        ITU_T_ARCHIVE_X690_DECL(TIME_TYPE);
        ITU_T_ARCHIVE_X690_DECL(TIME_TYPE::Time_type_type);

        ITU_T_ARCHIVE_X691_DECL(CENTURY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_CENTURY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_YEAR_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_MONTH_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_YEAR_MONTH_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DATE_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_DATE_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_YEAR_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_WEEK_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_YEAR_WEEK_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_WEEK_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(ANY_YEAR_WEEK_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_UTC_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_DIFFERENCE);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_UTC_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_UTC_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_AND_DIFF_ENCODING::Local_time_type);
        ITU_T_ARCHIVE_X691_DECL(HOURS_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_UTC_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_AND_DIFF_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_UTC_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_AND_DIFF_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING::Local_time_type);
        ITU_T_ARCHIVE_X691_DECL(DURATION_INTERVAL_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DURATION_INTERVAL_ENCODING::Fractional_part_type);
        ITU_T_ARCHIVE_X691_DECL(REC_DURATION_INTERVAL_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HFn_L_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HFn_Z_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HFn_LD_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HMFn_L_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HMFn_Z_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HMFn_LD_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HMFSn_L_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HMFSn_Z_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Time_HMFSn_LD_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Date_time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SE_Date_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SE_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SE_Date_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SE_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SD_Date_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SD_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SD_Date_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_SD_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_DE_Date_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_DE_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_DE_Date_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Iterval_DE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SE_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SD_Date_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SD_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_SD_Date_Time_type::Start_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_DE_Date_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_DE_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type);
        ITU_T_ARCHIVE_X691_DECL(MIXED_ENCODING::Rec_Interval_DE_Date_Time_type::End_type);
        ITU_T_ARCHIVE_X691_DECL(DATE_TYPE);
        ITU_T_ARCHIVE_X691_DECL(TIME_TYPE);
        ITU_T_ARCHIVE_X691_DECL(TIME_TYPE::Time_type_type);



        ITU_T_INTERNAL_REGESTRATE(CENTURY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_CENTURY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(YEAR_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_YEAR_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(YEAR_MONTH_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_YEAR_MONTH_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(DATE_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_DATE_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(YEAR_DAY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_YEAR_DAY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(YEAR_WEEK_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_YEAR_WEEK_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(YEAR_WEEK_DAY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(ANY_YEAR_WEEK_DAY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(HOURS_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(HOURS_UTC_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(HOURS_AND_DIFF_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_DIFFERENCE, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MINUTES_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MINUTES_UTC_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MINUTES_AND_DIFF_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_OF_DAY_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_OF_DAY_UTC_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_OF_DAY_AND_DIFF_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(HOURS_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(HOURS_UTC_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(HOURS_AND_DIFF_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MINUTES_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MINUTES_UTC_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MINUTES_AND_DIFF_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_OF_DAY_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(DURATION_INTERVAL_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(REC_DURATION_INTERVAL_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(MIXED_ENCODING, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(DATE_TYPE, TYPE_TIME);
        ITU_T_INTERNAL_REGESTRATE(TIME_TYPE, TYPE_TIME);


    }
}

ITU_T_CHOICE_REGESTRATE(boost::asn1::YEAR_ENCODING)
ITU_T_CHOICE_REGESTRATE(boost::asn1::MIXED_ENCODING)
ITU_T_CHOICE_REGESTRATE(boost::asn1::DATE_TYPE)
ITU_T_CHOICE_REGESTRATE(boost::asn1::TIME_TYPE::Time_type_type)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___DEFINEDTIME */
