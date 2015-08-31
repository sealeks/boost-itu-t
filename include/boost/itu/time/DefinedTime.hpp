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

#define ITU_T_TIME_COUTTP_FN( nm)  friend std::ostream& operator<<(std::ostream& stream, const nm & vl) {return stream <<  vl.format() << " : " << vl.as_string();};
#define ITU_T_TIME_COUTTP_NCFN( nm)  friend std::ostream& operator<<(std::ostream& stream, nm vl) {return stream <<  vl.format() << " : " << vl.as_string();};
#define ITU_T_TIME_X690_FN_DECL             void serialize(boost::asn1::x690::output_coder& arch) {\
                time_serialize(*this, arch);}\
            void serialize(boost::asn1::x690::input_coder& arch) {\
                time_serialize(*this, arch);}\
                
#define ITU_T_TIME_X690_FN_ID_DECL( id)             void serialize(boost::asn1::x690::output_coder& arch) {\
                time_serialize_num(*this, id , arch);}\
            void serialize(boost::asn1::x690::input_coder& arch) {\
                time_serialize_num(*this, id , arch);}\
                

namespace boost {
    namespace asn1 {

        const std::size_t DEFAULT_TM_FRACTION = 3;
        const std::size_t MAX_TM_FRACTION = 9;

        const std::size_t DEFAULT_CENTUTY_FRACTION = 2;
        const std::size_t MAX_CENTURY_FRACTION = 12;

        const std::size_t DEFAULT_YEAR_FRACTION = 4;
        const std::size_t MAX_YEAR_FRACTION = 12;


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
                } catch (boost::bad_lexical_cast) {
                }
                return (sz && nlchar) ? std::string(nlchar, sz) : "";
            }

            template<typename T>
            visible_string to_visible_string(const T& val, std::size_t sz = 0, std::string::value_type nlchar = 0) {
                return visible_string(to_string(val, sz, nlchar));
            }

            template<typename T>
            T string_to_def(const std::string& v, const T& def = 0, const std::string& escchars = "") {
                try {
                    if (!v.empty()) {
                        if (escchars.empty())
                            return boost::lexical_cast<T > (v);
                        else {
                            std::string val = v;
                            std::string signstr = "";
                            if ((v[0] == '+') || (v[0] == '-')) {
                                signstr = v.substr(0, 1);
                                val = v.substr(1);
                            }
                            std::string::size_type it = val.find_first_not_of(escchars);
                            if (it != 0) {
                                std::string vl = val.substr(it != std::string::npos ? it : val.size() - 1);
                                return boost::lexical_cast<T > (signstr + vl);
                            }
                            return boost::lexical_cast<T > (v);
                        }
                    }
                } catch (boost::bad_lexical_cast) {
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

            std::string drct_substr(const std::string& vl, std::string::size_type beg = 0, std::string::size_type sz = 0);

            std::string drct_substr(const visible_string& vl, std::string::size_type beg = 0, std::string::size_type sz = 0);


            // reverse substring |sssssssss|sssssss|sssssssssssss|
            //                                beg         bgs       eps                 end        
            // endps=end-eps, sz=eps-bgs,    if sz=0, full size from beg    

            std::string revrs_substr(const std::string& vl, std::string::size_type endps = 0, std::string::size_type sz = 0);

            std::string revrs_substr(const visible_string& vl, std::string::size_type endps = 0, std::string::size_type sz = 0);


            std::string get_str_marker(const std::string& vl, std::string::value_type markchar);

            integer_type get_numstr_marker(const std::string& vl, std::string::value_type markchar);



            std::string normalize_str_size(const std::string& vl, std::string::size_type sz);

            std::string normalize_time_str(std::string vl);



            std::string normalizeLR_time_str(std::string vl);


            uint64_t pow10(std::size_t n);

            std::size_t minute_fraction_HF(integer_type f, std::size_t n);

            std::size_t second_fraction_HF(integer_type f, std::size_t n);

            std::size_t microsecond_fraction_HF(integer_type f, std::size_t n);

            std::size_t nanosecond_fraction_HF(integer_type f, std::size_t n);

            std::size_t second_fraction_HMF(integer_type f, std::size_t n);

            std::size_t microsecond_fraction_HMF(integer_type f, std::size_t n);

            std::size_t nanosecond_fraction_HMF(integer_type f, std::size_t n);

            std::size_t microsecond_fraction_HMSF(integer_type f, std::size_t n);

            std::size_t nanosecond_fraction_HMSF(integer_type f, std::size_t n);

            integer_type HF_to_fraction(base_time_duration dtd, std::size_t n);

            integer_type HMF_to_fraction(base_time_duration dtd, std::size_t n);

            integer_type HMSF_to_fraction(base_time_duration dtd, std::size_t n);

        }

        template<typename T>
        inline void time_serialize(const T& vl, boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = vl.as_string();
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
        }

        template<typename T>
        inline void time_serialize(T& vl, boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, TYPE_TIME, UNIVERSAL_CLASS);
            vl.as_string(std::string(tmpval.c_str()));
        }

        template<typename T>
        inline void time_serialize_num(const T& vl, id_type ID, boost::asn1::x690::output_coder& arch) {
            visible_string tmpval = vl.as_string();
            ITU_T_BIND_IMPLICIT(tmpval, ID, UNIVERSAL_CLASS);
        }

        template<typename T>
        inline void time_serialize_num(T& vl, id_type ID, boost::asn1::x690::input_coder& arch) {
            visible_string tmpval;
            ITU_T_BIND_IMPLICIT(tmpval, ID, UNIVERSAL_CLASS);
            vl.as_string(std::string(tmpval.c_str()));
        }








        // sequence CENTURY-ENCODING

        struct CENTURY_ENCODING {

            CENTURY_ENCODING();

            CENTURY_ENCODING(const uint8_t& arg__vl);

            CENTURY_ENCODING(const std::string& vl);

            CENTURY_ENCODING(const char* vl);

            CENTURY_ENCODING(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            std::string format() const {
                return "CC";
            }

            ITU_T_TIME_COUTTP_FN(CENTURY_ENCODING);

            ITU_T_HOLDERH_DECL(as_number, uint8_t); //   Ic(  [ 0  ...   99 ]   


            ITU_T_TIME_X690_FN_DECL
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-CENTURY-ENCODING

        template<std::size_t N = DEFAULT_CENTUTY_FRACTION >
        struct ANY_CENTURY_ENCODING {

            static std::size_t NF() {
                return (N > MAX_CENTURY_FRACTION) ? MAX_CENTURY_FRACTION : N;
            }

            ANY_CENTURY_ENCODING() : as_number_() {
            };

            ANY_CENTURY_ENCODING(const integer_type& arg__val) :
            as_number_(arg__val) {
            };

            ANY_CENTURY_ENCODING(const std::string& vl) :
            as_number_(0) {
                as_string(vl);
            };

            ANY_CENTURY_ENCODING(const char* vl) :
            as_number_(0) {
                as_string(vl);
            };

            ANY_CENTURY_ENCODING(const base_date& vl) :
            as_number_(vl.is_special() ? 0 : (vl.year() / 100)) {
            }

            base_date as_date() const {
                try {
                    return base_date(static_cast<int> (as_number())*100, 1, 1);
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return std::string((as_number() < 0) ? "-" : "") +
                        time_detail::to_string(static_cast<int> (std::abs(as_number())), NF(), '0') + "C";
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::revrs_substr(time_detail::normalize_time_str(v), 1);
                as_number(time_detail::string_to_def(vl, 0, "0"));
            }

            ITU_T_HOLDERH_T_DECL(as_number, integer_type);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(as_number_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(as_number_);
            }

            std::string format() const {
                return std::string((NF() ? NF() : 1), 'C');
            }

            ITU_T_TIME_COUTTP_FN(ANY_CENTURY_ENCODING);

            ITU_T_TIME_X690_FN_DECL
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

            YEAR_ENCODING(const base_date & v);

            ITU_T_CHOICES_DECL(immediate, uint16_t, YEAR_ENCODING_immediate); // primitive  //   Ic(  [ 2005  ...   2020 ]   
            ITU_T_CHOICES_DECL(near_future, uint16_t, YEAR_ENCODING_near_future); // primitive  //   Ic(  [ 2021  ...   2276 ]   
            ITU_T_CHOICES_DECL(near_past, uint16_t, YEAR_ENCODING_near_past); // primitive  //   Ic(  [ 1749  ...   2004 ]   
            ITU_T_CHOICES_DECL(remainder, integer_type, YEAR_ENCODING_remainder); // primitive  //   Ic(  [ ... ]   

            base_date as_date() const;

            integer_type as_number() const;

            void as_number(integer_type v);

            std::string as_string() const;

            void as_string(const std::string & vl);

            std::string format() const {
                return "YYYY";
            }

            ITU_T_TIME_COUTTP_FN(YEAR_ENCODING);

            ITU_T_TIME_X690_FN_DECL
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-YEAR-ENCODING

        template<std::size_t N = DEFAULT_YEAR_FRACTION >
        struct ANY_YEAR_ENCODING {

            static std::size_t NF() {
                return (N > MAX_YEAR_FRACTION) ? MAX_YEAR_FRACTION : N;
            }

            ANY_YEAR_ENCODING() : as_number_() {
            };

            ANY_YEAR_ENCODING(const integer_type& arg__val) :
            as_number_(arg__val) {
            };

            ANY_YEAR_ENCODING(const std::string& vl) :
            as_number_(0) {
                as_string(vl);
            };

            ANY_YEAR_ENCODING(const char* vl) :
            as_number_(0) {
                as_string(vl);
            };

            ANY_YEAR_ENCODING(const base_date& vl) :
            as_number_(vl.is_special() ? 0 : (integer_type) vl.year()) {
            }

            base_date as_date() const {
                try {
                    return base_date(static_cast<int> (as_number()), 1, 1);
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return std::string((as_number() < 0) ? "-" : "") +
                        time_detail::to_string(static_cast<int> (std::abs(as_number())), NF(), '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                as_number(time_detail::string_to_def(vl, 0, "0"));
            }

            ITU_T_HOLDERH_T_DECL(as_number, integer_type);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(as_number_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(as_number_);
            }

            std::string format() const {
                return std::string((NF() ? NF() : 1), 'Y');
            }

            ITU_T_TIME_COUTTP_FN(ANY_YEAR_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };







        // sequence YEAR-MONTH-ENCODING

        struct YEAR_MONTH_ENCODING {

            YEAR_MONTH_ENCODING();

            YEAR_MONTH_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month);

            YEAR_MONTH_ENCODING(const std::string& vl);

            YEAR_MONTH_ENCODING(const char* vl);

            YEAR_MONTH_ENCODING(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);


            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   

            std::string format() const {
                return year().format() + "-MM";
            }

            ITU_T_TIME_COUTTP_FN(YEAR_MONTH_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };






        // sequence ANY-YEAR-MONTH-ENCODING

        template<std::size_t N = DEFAULT_YEAR_FRACTION >
        struct ANY_YEAR_MONTH_ENCODING {

            typedef ANY_YEAR_ENCODING<N> ANY_YEAR_TYPE;

            static std::size_t NF() {
                return (N > MAX_YEAR_FRACTION) ? MAX_YEAR_FRACTION : N;
            }

            ANY_YEAR_MONTH_ENCODING() : year_(), month_() {
            };

            ANY_YEAR_MONTH_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month) :
            year_(arg__year),
            month_(time_detail::to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)) {
            };

            ANY_YEAR_MONTH_ENCODING(const std::string& vl) : year_(), month_(1) {
                as_string(vl);
            }

            ANY_YEAR_MONTH_ENCODING(const char* vl) : year_(), month_(1) {
                as_string(vl);
            }

            ANY_YEAR_MONTH_ENCODING(const base_date& vl) :
            year_(vl.is_special() ? 0 : (integer_type) vl.year()),
            month_(vl.is_special() ? 1 : (uint8_t) vl.month()) {
            }

            base_date as_date() const {
                try {
                    return base_date(static_cast<int> (year().as_number()), (int) month(), 1);
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return year().as_string() + "-" + time_detail::to_string(static_cast<int> (month()), 2, '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                year(time_detail::revrs_substr(vl, 2));
                month(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 12));
            }


            ITU_T_HOLDERH_T_DECL(year, ANY_YEAR_TYPE);
            ITU_T_HOLDERH_T_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
            }

            std::string format() const {
                return year().format() + "-MM";
            }

            ITU_T_TIME_COUTTP_FN(ANY_YEAR_MONTH_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            DATE_ENCODING(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   31 ]   

            std::string format() const {
                return year().format() + "-MM-DD";
            }

            ITU_T_TIME_COUTTP_FN(DATE_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };



        // sequence DATE

        struct DATE {

            DATE();

            DATE(integer_type arg__year,
                    const uint8_t& arg__month,
                    const uint8_t& arg__day);

            DATE(const std::string& vl);

            DATE(const char* vl);

            DATE(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   31 ]   

            std::string format() const {
                return year().format() + "-MM-DD";
            }

            ITU_T_TIME_COUTTP_FN(DATE);

            ITU_T_TIME_X690_FN_ID_DECL(TYPE_DATE);
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-DATE-ENCODING

        template<std::size_t N = DEFAULT_YEAR_FRACTION >
        struct ANY_DATE_ENCODING {

            typedef ANY_YEAR_ENCODING<N> ANY_YEAR_TYPE;

            static std::size_t NF() {
                return (N > MAX_YEAR_FRACTION) ? MAX_YEAR_FRACTION : N;
            }

            ANY_DATE_ENCODING() : year_(), month_(1), day_(1) {
            };

            ANY_DATE_ENCODING(integer_type arg__year,
                    const uint8_t& arg__month,
                    const uint8_t& arg__day) :
            year_(arg__year),
            month_(time_detail::to_range<uint8_t>(arg__month, (uint8_t) 1, (uint8_t) 12)),
            day_(time_detail::to_range<uint8_t>(arg__day, (uint8_t) 1, (uint8_t) 31)) {
            };

            ANY_DATE_ENCODING(const std::string& vl) : year_(), month_(1), day_(1) {
                as_string(vl);
            }

            ANY_DATE_ENCODING(const char* vl) : year_(), month_(1), day_(1) {
                as_string(vl);
            }

            ANY_DATE_ENCODING(const base_date& vl) :
            year_(vl.is_special() ? 0 : (integer_type) vl.year()),
            month_(vl.is_special() ? 1 : (uint8_t) vl.month()),
            day_(vl.is_special() ? 1 : (uint8_t) vl.day()) {
            }

            base_date as_date() const {
                try {
                    return base_date(static_cast<int> (year().as_number()), (int) month(), (int) day());
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return year().as_string() + "-" + time_detail::to_string(static_cast<int> (month()), 2, '0') +
                        "-" + time_detail::to_string(static_cast<int> (day()), 2, '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                year(time_detail::revrs_substr(vl, 4));
                month(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 2, 2)), (uint8_t) 1, (uint8_t) 12));
                day(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 31));
            }


            ITU_T_HOLDERH_T_DECL(year, ANY_YEAR_TYPE);
            ITU_T_HOLDERH_T_DECL(month, uint8_t); //   Ic(  [ 1  ...   12 ]   
            ITU_T_HOLDERH_T_DECL(day, uint8_t); //   Ic(  [ 1  ...   31 ]   

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
                ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(month_, static_cast<uint8_t> (1), static_cast<uint8_t> (12));
                ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (31));
            }

            std::string format() const {
                return year().format() + "-MM-DD";
            }

            ITU_T_TIME_COUTTP_FN(ANY_DATE_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence YEAR-DAY-ENCODING

        struct YEAR_DAY_ENCODING {

            YEAR_DAY_ENCODING();

            YEAR_DAY_ENCODING(integer_type arg__year,
                    const uint16_t& arg__day);

            YEAR_DAY_ENCODING(const std::string& vl);

            YEAR_DAY_ENCODING(const char* vl);

            YEAR_DAY_ENCODING(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(day, uint16_t); //   Ic(  [ 1  ...   366 ]   

            std::string format() const {
                return year().format() + "-DDD";
            }

            ITU_T_TIME_COUTTP_FN(YEAR_DAY_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };






        // sequence ANY-YEAR-DAY-ENCODING

        template<std::size_t N = DEFAULT_YEAR_FRACTION >
        struct ANY_YEAR_DAY_ENCODING {

            typedef ANY_YEAR_ENCODING<N> ANY_YEAR_TYPE;

            static std::size_t NF() {
                return (N > MAX_YEAR_FRACTION) ? MAX_YEAR_FRACTION : N;
            }

            ANY_YEAR_DAY_ENCODING() : year_(), day_(1) {
            };

            ANY_YEAR_DAY_ENCODING(integer_type arg__year,
                    const uint16_t& arg__day) :
            year_(arg__year),
            day_(time_detail::to_range<uint16_t>(arg__day, (uint16_t) 1, (uint16_t) 366)) {
            };

            ANY_YEAR_DAY_ENCODING(const std::string& vl) : year_(), day_(1) {
                as_string(vl);
            }

            ANY_YEAR_DAY_ENCODING(const char* vl) : year_(), day_(1) {
                as_string(vl);
            }

            ANY_YEAR_DAY_ENCODING(const base_date& vl) :
            year_(vl.is_special() ? 0 : (integer_type) vl.year()),
            day_(vl.is_special() ? 1 : (uint16_t) vl.day_of_year()) {
            }

            base_date as_date() const {
                try {
                    return base_date(static_cast<int> (year().as_number()), 1, 1) +
                            base_date_time::date_duration_type(day() ? day() - 1 : 0);
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return year().as_string() + "-" + time_detail::to_string(static_cast<int> (day()), 3, '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                year(time_detail::revrs_substr(vl, 3));
                day(time_detail::to_range<uint16_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 0, 3)), (uint16_t) 1, (uint16_t) 366));
            }


            ITU_T_HOLDERH_T_DECL(year, ANY_YEAR_TYPE);
            ITU_T_HOLDERH_T_DECL(day, uint16_t); //   Ic(  [ 1  ...   366 ]   

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint16_t> (1), static_cast<uint16_t> (366));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint16_t> (1), static_cast<uint16_t> (366));
            }

            std::string format() const {
                return year().format() + "-DDD";
            }

            ITU_T_TIME_COUTTP_FN(ANY_YEAR_DAY_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence YEAR-WEEK-ENCODING

        struct YEAR_WEEK_ENCODING {

            YEAR_WEEK_ENCODING();

            YEAR_WEEK_ENCODING(const YEAR_ENCODING& arg__year,
                    const uint8_t& arg__week);

            YEAR_WEEK_ENCODING(const std::string& vl);

            YEAR_WEEK_ENCODING(const char* vl);

            YEAR_WEEK_ENCODING(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   

            std::string format() const {
                return year().format() + "-Www";
            }

            ITU_T_TIME_COUTTP_FN(YEAR_WEEK_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-YEAR-WEEK-ENCODING

        template<std::size_t N = DEFAULT_YEAR_FRACTION >
        struct ANY_YEAR_WEEK_ENCODING {

            typedef ANY_YEAR_ENCODING<N> ANY_YEAR_TYPE;

            static std::size_t NF() {
                return (N > MAX_YEAR_FRACTION) ? MAX_YEAR_FRACTION : N;
            }

            ANY_YEAR_WEEK_ENCODING() : year_(), week_(1) {
            };

            ANY_YEAR_WEEK_ENCODING(integer_type arg__year,
                    const uint8_t& arg__week) :
            year_(arg__year),
            week_(time_detail::to_range<uint8_t>(arg__week, (uint8_t) 1, (uint8_t) 53)) {
            };

            ANY_YEAR_WEEK_ENCODING(const std::string& vl) : year_(), week_(1) {
                as_string(vl);
            }

            ANY_YEAR_WEEK_ENCODING(const char* vl) : year_(), week_(1) {
                as_string(vl);
            }

            ANY_YEAR_WEEK_ENCODING(const base_date& vl) :
            year_(vl.is_special() ? 0 : (integer_type) vl.year()),
            week_(vl.is_special() ? 1 : (uint8_t) vl.week_number()) {
            }

            base_date as_date() const {
                try {
                    base_date tmp(static_cast<int> (year().as_number()), 1, 1);
                    std::size_t dwst = (std::size_t)tmp.day_of_week();
                    return tmp + base_date_time::date_duration_type((dwst > 4) ? (8 - dwst) : (1 - dwst)) +
                            base_date_time::date_duration_type((week() > 1) ? (7 * (week() - 1)) : 0);
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return year().as_string() + "-W" + time_detail::to_string(static_cast<int> (week()), 2, '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                year(time_detail::revrs_substr(vl, 3));
                week(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 0, 2)), (uint8_t) 1, (uint8_t) 53));
            }

            ITU_T_HOLDERH_T_DECL(year, ANY_YEAR_TYPE);
            ITU_T_HOLDERH_T_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
            }

            std::string format() const {
                return year().format() + "-Www";
            }

            ITU_T_TIME_COUTTP_FN(ANY_YEAR_WEEK_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            YEAR_WEEK_DAY_ENCODING(const base_date& vl);

            base_date as_date() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(year, YEAR_ENCODING);
            ITU_T_HOLDERH_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   
            ITU_T_HOLDERH_DECL(day, uint8_t); //   Ic(  [ 1  ...   7 ]   

            std::string format() const {
                return year().format() + "-Www-D";
            }

            ITU_T_TIME_COUTTP_FN(YEAR_WEEK_DAY_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence ANY-YEAR-WEEK-DAY-ENCODING

        template<std::size_t N = DEFAULT_YEAR_FRACTION >
        struct ANY_YEAR_WEEK_DAY_ENCODING {

            typedef ANY_YEAR_ENCODING<N> ANY_YEAR_TYPE;

            static std::size_t NF() {
                return (N > MAX_YEAR_FRACTION) ? MAX_YEAR_FRACTION : N;
            }

            ANY_YEAR_WEEK_DAY_ENCODING() : year_(), week_(1), day_(1) {
            };

            ANY_YEAR_WEEK_DAY_ENCODING(integer_type arg__year,
                    const uint8_t& arg__week,
                    const uint8_t& arg__day) :
            year_(arg__year),
            week_(time_detail::to_range<uint8_t>(arg__week, (uint8_t) 1, (uint8_t) 53)),
            day_(time_detail::to_range<uint8_t>(arg__day, (uint8_t) 1, (uint8_t) 7)) {
            };

            ANY_YEAR_WEEK_DAY_ENCODING(const std::string& vl) : year_(), week_(1) {
                as_string(vl);
            }

            ANY_YEAR_WEEK_DAY_ENCODING(const char* vl) : year_(), week_(1) {
                as_string(vl);
            }

            ANY_YEAR_WEEK_DAY_ENCODING(const base_date& vl) :
            year_(vl.is_special() ? 0 : (integer_type) vl.year()),
            week_(vl.is_special() ? 1 : (uint8_t) vl.week_number()),
            day_(vl.is_special() ? 1 : (uint8_t) vl.day_of_week()) {
            }

            base_date as_date() const {
                try {
                    base_date tmp(static_cast<int> (year().as_number()), 1, 1);
                    std::size_t dwst = (std::size_t)tmp.day_of_week();
                    return tmp + base_date_time::date_duration_type((dwst > 4) ? (8 - dwst) : (1 - dwst)) +
                            base_date_time::date_duration_type(((week() > 1) ? (7 * (week() - 1)) : 0) + ((day() > 1) ? (day() - 1) : 0));
                } catch (...) {
                }
                return base_date();
            }

            std::string as_string() const {
                return year().as_string() + "-W" + time_detail::to_string(static_cast<int> (week()), 2, '0') +
                        "-" + time_detail::to_string(static_cast<int> (day()), 1);
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                year(time_detail::revrs_substr(vl, 4));
                week(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 1, 2)), (uint8_t) 1, (uint8_t) 53));
                day(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(time_detail::revrs_substr(vl, 0, 1)), (uint8_t) 1, (uint8_t) 7));
            }

            ITU_T_HOLDERH_T_DECL(year, ANY_YEAR_TYPE);
            ITU_T_HOLDERH_T_DECL(week, uint8_t); //   Ic(  [ 1  ...   53 ]   
            ITU_T_HOLDERH_T_DECL(day, uint8_t); //   Ic(  [ 1  ...   7 ]   

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
                ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (7));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(year_);
                ITU_T_BIND_NUM_CONSTRAINT(week_, static_cast<uint8_t> (1), static_cast<uint8_t> (53));
                ITU_T_BIND_NUM_CONSTRAINT(day_, static_cast<uint8_t> (1), static_cast<uint8_t> (7));
            }

            std::string format() const {
                return year().format() + "-Www-D";
            }

            ITU_T_TIME_COUTTP_FN(ANY_YEAR_WEEK_DAY_ENCODING);


            ITU_T_TIME_X690_FN_DECL;
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

            std::string format() const {
                return "hh";
            }

            ITU_T_TIME_COUTTP_FN(HOURS_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            std::string format() const {
                return "hhZ";
            }

            ITU_T_TIME_COUTTP_FN(HOURS_UTC_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            std::string format() const {
                return "+hh[::mm]";
            }

            ITU_T_HOLDERH_DECL(sign, enumerated);
            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   15 ]   
            ITU_T_OPTIONAL_DECL(minutes, uint8_t); //   Ic(  [ 1  ...   59 ]   


            ITU_T_TIME_COUTTP_FN(TIME_DIFFERENCE);

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

            std::string format() const {
                return "hh" + time_difference().format();
            }

            ITU_T_TIME_COUTTP_FN(HOURS_AND_DIFF_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            std::string format() const {
                return "hh:mm";
            }

            ITU_T_TIME_COUTTP_FN(MINUTES_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            std::string format() const {
                return "hh:mmZ";
            }

            ITU_T_TIME_COUTTP_FN(MINUTES_UTC_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
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

            std::string format() const {
                return "hh:mm" + time_difference().format();
            }

            ITU_T_TIME_COUTTP_FN(MINUTES_AND_DIFF_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence TIME-OF-DAY-ENCODING

        struct TIME_OF_DAY_ENCODING {

            TIME_OF_DAY_ENCODING();

            TIME_OF_DAY_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds);

            TIME_OF_DAY_ENCODING(const std::string& vl);

            TIME_OF_DAY_ENCODING(const char* vl);

            TIME_OF_DAY_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   

            std::string format() const {
                return "hh:mm::ss";
            }

            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };



        // sequence TIME-OF-DAY

        struct TIME_OF_DAY {

            TIME_OF_DAY();

            TIME_OF_DAY(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds);

            TIME_OF_DAY(const std::string& vl);

            TIME_OF_DAY(const char* vl);

            TIME_OF_DAY(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   

            std::string format() const {
                return "hh:mm::ss";
            }

            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY);

            ITU_T_TIME_X690_FN_ID_DECL(TYPE_TIME_OF_DAY);
            ITU_T_ARCHIVE_FUNC;
        };




        // sequence TIME-OF-DAY-UTC-ENCODING

        struct TIME_OF_DAY_UTC_ENCODING {

            TIME_OF_DAY_UTC_ENCODING();

            TIME_OF_DAY_UTC_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds);

            TIME_OF_DAY_UTC_ENCODING(const std::string& vl);

            TIME_OF_DAY_UTC_ENCODING(const char* vl);

            TIME_OF_DAY_UTC_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]   
            ITU_T_HOLDERH_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   

            std::string format() const {
                return "hh:mm::ssZ";
            }

            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY_UTC_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence TIME-OF-DAY-AND-DIFF-ENCODING

        struct TIME_OF_DAY_AND_DIFF_ENCODING {

            TIME_OF_DAY_AND_DIFF_ENCODING();

            TIME_OF_DAY_AND_DIFF_ENCODING(const TIME_OF_DAY_ENCODING& arg__local_time,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE());

            TIME_OF_DAY_AND_DIFF_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE());

            TIME_OF_DAY_AND_DIFF_ENCODING(const std::string& vl);

            TIME_OF_DAY_AND_DIFF_ENCODING(const char* vl);

            TIME_OF_DAY_AND_DIFF_ENCODING(const base_time_duration& vl);

            base_time_duration as_time() const;

            std::string as_string() const;

            void as_string(const std::string& vl);

            ITU_T_HOLDERH_DECL(local_time, TIME_OF_DAY_ENCODING);
            ITU_T_HOLDERH_DECL(time_difference, TIME_DIFFERENCE);

            std::string format() const {
                return "hh:mm:ss" + time_difference().format();
            }

            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY_AND_DIFF_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence HOURS-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct HOURS_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            HOURS_AND_FRACTION_ENCODING() : hours_(), fraction_() {
            };

            HOURS_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const integer_type& arg__fraction) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            fraction_(arg__fraction) {
            };

            HOURS_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), fraction_() {
                as_string(vl);
            };

            HOURS_AND_FRACTION_ENCODING(const char* vl) : hours_(), fraction_() {
                as_string(vl);
            };

            HOURS_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            fraction_(time_detail::HF_to_fraction(vl, frc ? frc : NF())) {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()),
                            time_detail::minute_fraction_HF(fraction(), frc ? frc : NF()),
                            time_detail::second_fraction_HF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vl, 3), NF()), 0));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            std::string format() const {
                return "hh," + std::string(NF() ? NF() : 1, 'n');
            };

            ITU_T_TIME_COUTTP_FN(HOURS_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence HOURS-UTC-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct HOURS_UTC_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            HOURS_UTC_AND_FRACTION_ENCODING() : hours_(), fraction_() {
            };

            HOURS_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const integer_type& arg__fraction) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            fraction_(arg__fraction) {
            };

            HOURS_UTC_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), fraction_() {
                as_string(vl);
            };

            HOURS_UTC_AND_FRACTION_ENCODING(const char* vl) : hours_(), fraction_() {
                as_string(vl);
            };

            HOURS_UTC_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            fraction_(time_detail::HF_to_fraction(vl, frc ? frc : NF())) {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()),
                            time_detail::minute_fraction_HF(fraction(), frc ? frc : NF()),
                            time_detail::second_fraction_HF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0') + "Z";
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::revrs_substr(time_detail::normalize_time_str(v), 1);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vl, 3), NF()), 0));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            std::string format() const {
                return "hh," + std::string(NF() ? NF() : 1, 'n') + "Z: ";
            };

            ITU_T_TIME_COUTTP_FN(HOURS_UTC_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };








        // sequence HOURS-AND-DIFF-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct HOURS_AND_DIFF_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            HOURS_AND_DIFF_AND_FRACTION_ENCODING() : hours_(), fraction_(), time_difference_() {
            };

            HOURS_AND_DIFF_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const integer_type& arg__fraction,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE()) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            fraction_(arg__fraction),
            time_difference_(arg__time_difference) {
            };

            HOURS_AND_DIFF_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), fraction_(), time_difference_() {
                as_string(vl);
            };

            HOURS_AND_DIFF_AND_FRACTION_ENCODING(const char* vl) : hours_(), fraction_(), time_difference_() {
                as_string(vl);
            };

            HOURS_AND_DIFF_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            fraction_(time_detail::HF_to_fraction(vl, frc ? frc : NF())),
            time_difference_() {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()),
                            time_detail::minute_fraction_HF(fraction(), frc ? frc : NF()),
                            time_detail::second_fraction_HF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0') +
                        time_difference().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('-');
                if (it == std::string::npos)
                    it = vl.find_first_of('+');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vll, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vll, 3), NF()), 0));
                time_difference(TIME_DIFFERENCE(vlr));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 
            ITU_T_HOLDERH_T_DECL(time_difference, TIME_DIFFERENCE);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
                ITU_T_BIND_PER(time_difference_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
                ITU_T_BIND_PER(time_difference_);
            }

            std::string format() const {
                return "hh," + std::string(NF() ? NF() : 1, 'n') + time_difference().format();
            };


            ITU_T_TIME_COUTTP_FN(HOURS_AND_DIFF_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;

        };






        // sequence MINUTES-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct MINUTES_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            MINUTES_AND_FRACTION_ENCODING() : hours_(), minutes_(), fraction_() {
            };

            MINUTES_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const integer_type& arg__fraction) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
            fraction_(arg__fraction) {
            };

            MINUTES_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), minutes_(), fraction_() {
                as_string(vl);
            };

            MINUTES_AND_FRACTION_ENCODING(const char* vl) : hours_(), minutes_(), fraction_() {
                as_string(vl);
            };

            MINUTES_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
            fraction_(time_detail::HMF_to_fraction(vl, frc ? frc : NF())) {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()),
                            time_detail::second_fraction_HMF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + ":" +
                        time_detail::to_string(static_cast<integer_type> (minutes()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                minutes(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vl, 5), NF()), 0));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]               
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            std::string format() const {
                return "hh:mm," + std::string(NF() ? NF() : 1, 'n');
            };

            ITU_T_TIME_COUTTP_FN(MINUTES_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };








        // sequence MINUTES-UTC-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct MINUTES_UTC_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            MINUTES_UTC_AND_FRACTION_ENCODING() : hours_(), minutes_(), fraction_() {
            };

            MINUTES_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const integer_type& arg__fraction) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
            fraction_(arg__fraction) {
            };

            MINUTES_UTC_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), minutes_(), fraction_() {
                as_string(vl);
            };

            MINUTES_UTC_AND_FRACTION_ENCODING(const char* vl) : hours_(), minutes_(), fraction_() {
                as_string(vl);
            };

            MINUTES_UTC_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
            fraction_(time_detail::HMF_to_fraction(vl, frc ? frc : NF())) {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()),
                            time_detail::second_fraction_HMF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + ":" +
                        time_detail::to_string(static_cast<integer_type> (minutes()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0') + "Z";
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::revrs_substr(time_detail::normalize_time_str(v), 1);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                minutes(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vl, 5), NF()), 0));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]               
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            std::string format() const {
                return "hh:mm," + std::string(NF() ? NF() : 1, 'n') + "Z";
            };

            ITU_T_TIME_COUTTP_FN(MINUTES_UTC_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };








        // sequence MINUTES-AND-DIFF-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct MINUTES_AND_DIFF_AND_FRACTION_ENCODING {

            typedef MINUTES_AND_FRACTION_ENCODING<N> MINUTES_AND_FRACTION;

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING() : local_time_(), time_difference_() {
            };

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const integer_type& arg__fraction,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE()) :
            local_time_(MINUTES_AND_FRACTION(arg__hours, arg__minutes, arg__fraction)),
            time_difference_(arg__time_difference) {
            };

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING(const std::string& vl) : local_time_(), time_difference_() {
                as_string(vl);
            };

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING(const char* vl) : local_time_(), time_difference_() {
                as_string(vl);
            };

            MINUTES_AND_DIFF_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            local_time_(MINUTES_AND_FRACTION(vl, frc)),
            time_difference_() {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                return local_time().as_time(frc);
            }

            std::string as_string() const {
                return local_time().as_string() + time_difference().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('-');
                if (it == std::string::npos)
                    it = vl.find_first_of('+');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it);
                local_time(MINUTES_AND_FRACTION(vll));
                time_difference(TIME_DIFFERENCE(vlr));
            }

            ITU_T_HOLDERH_T_DECL(local_time, MINUTES_AND_FRACTION);
            ITU_T_HOLDERH_T_DECL(time_difference, TIME_DIFFERENCE);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(local_time_);
                ITU_T_BIND_PER(time_difference_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(local_time_);
                ITU_T_BIND_PER(time_difference_);
            }

            std::string format() const {
                return "hh:mm," + std::string(NF() ? NF() : 1, 'n') + time_difference().format();
            };

            ITU_T_TIME_COUTTP_FN(MINUTES_AND_DIFF_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };







        // sequence TIME-OF-DAY-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct TIME_OF_DAY_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            TIME_OF_DAY_AND_FRACTION_ENCODING() : hours_(), minutes_(), seconds_(), fraction_() {
            };

            TIME_OF_DAY_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds,
                    const integer_type& arg__fraction) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
            seconds_(time_detail::to_range(arg__seconds, (uint8_t) 0, (uint8_t) 60)),
            fraction_(arg__fraction) {
            };

            TIME_OF_DAY_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), minutes_(), seconds_(), fraction_() {
                as_string(vl);
            };

            TIME_OF_DAY_AND_FRACTION_ENCODING(const char* vl) : hours_(), minutes_(), seconds_(), fraction_() {
                as_string(vl);
            };

            TIME_OF_DAY_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
            seconds_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.seconds(), (uint8_t) 0, (uint8_t) 60)),
            fraction_(time_detail::HMSF_to_fraction(vl, frc ? frc : NF())) {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()),
                            static_cast<int> (seconds())) +
                            base_microseconds(time_detail::microsecond_fraction_HMSF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + ":" +
                        time_detail::to_string(static_cast<integer_type> (minutes()), 2, '0') + ":" +
                        time_detail::to_string(static_cast<integer_type> (seconds()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0');
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                minutes(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
                seconds(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 4, 2), 0, "0"), (uint8_t) 0, (uint8_t) 60));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vl, 7), NF()), 0));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]             
            ITU_T_HOLDERH_T_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]               
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            std::string format() const {
                return "hh:mm:ss," + std::string(NF() ? NF() : 1, 'n');
            };

            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;

        };







        // sequence TIME-OF-DAY-UTC-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct TIME_OF_DAY_UTC_AND_FRACTION_ENCODING {

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING() : hours_(), minutes_(), seconds_(), fraction_() {
            };

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds,
                    const integer_type& arg__fraction) :
            hours_(time_detail::to_range(arg__hours, (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range(arg__minutes, (uint8_t) 0, (uint8_t) 59)),
            seconds_(time_detail::to_range(arg__seconds, (uint8_t) 0, (uint8_t) 60)),
            fraction_(arg__fraction) {
            };

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(const std::string& vl) : hours_(), minutes_(), seconds_(), fraction_() {
                as_string(vl);
            };

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(const char* vl) : hours_(), minutes_(), seconds_(), fraction_() {
                as_string(vl);
            };

            TIME_OF_DAY_UTC_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            hours_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.hours(), (uint8_t) 0, (uint8_t) 24)),
            minutes_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.minutes(), (uint8_t) 0, (uint8_t) 59)),
            seconds_(time_detail::to_range<uint8_t>(vl.is_special() ? 0 : vl.seconds(), (uint8_t) 0, (uint8_t) 60)),
            fraction_(time_detail::HMSF_to_fraction(vl, frc ? frc : NF())) {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                try {
                    return base_time_duration(static_cast<int> (hours()), static_cast<int> (minutes()),
                            static_cast<int> (seconds())) +
                            base_microseconds(time_detail::microsecond_fraction_HMSF(fraction(), frc ? frc : NF()));
                } catch (...) {
                }
                return base_time_duration();
            }

            std::string as_string() const {
                return time_detail::to_string(static_cast<integer_type> (hours()), 2, '0') + ":" +
                        time_detail::to_string(static_cast<integer_type> (minutes()), 2, '0') + ":" +
                        time_detail::to_string(static_cast<integer_type> (seconds()), 2, '0') + "," +
                        time_detail::to_string(static_cast<integer_type> (fraction()), NF(), '0') + "Z";
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::revrs_substr(time_detail::normalize_time_str(v), 1);
                hours(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 0, 2), 0, "0"), (uint8_t) 0, (uint8_t) 24));
                minutes(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 2, 2), 0, "0"), (uint8_t) 0, (uint8_t) 59));
                seconds(time_detail::to_range<uint8_t>(time_detail::string_to_def<int>(
                        time_detail::drct_substr(vl, 4, 2), 0, "0"), (uint8_t) 0, (uint8_t) 60));
                fraction(time_detail::string_to_def<int>(time_detail::normalize_str_size(time_detail::drct_substr(vl, 7), NF()), 0));
            }

            ITU_T_HOLDERH_T_DECL(hours, uint8_t); //   Ic(  [ 0  ...   24 ]   
            ITU_T_HOLDERH_T_DECL(minutes, uint8_t); //   Ic(  [ 0  ...   59 ]      
            ITU_T_HOLDERH_T_DECL(seconds, uint8_t); //   Ic(  [ 0  ...   60 ]   
            ITU_T_HOLDERH_T_DECL(fraction, integer_type); //   Ic(  [ 0  ...   999 ]   ...ext...) 

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_NUM_CONSTRAINT(hours_, static_cast<uint8_t> (0), static_cast<uint8_t> (24));
                ITU_T_BIND_NUM_CONSTRAINT(minutes_, static_cast<uint8_t> (0), static_cast<uint8_t> (59));
                ITU_T_BIND_NUM_CONSTRAINT(seconds_, static_cast<uint8_t> (0), static_cast<uint8_t> (60));
                ITU_T_BIND_NUM_CONSTRAINT_EXT(fraction_, static_cast<integer_type> (0), static_cast<integer_type> (999));
            }

            std::string format() const {
                return "hh:mm:ss," + std::string(NF() ? NF() : 1, 'n') + "Z";
            };


            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;

        };






        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        template<std::size_t N = DEFAULT_TM_FRACTION >
        struct TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING {

            typedef TIME_OF_DAY_AND_FRACTION_ENCODING<N> TIME_OF_DAY_AND_FRACTION;

            static std::size_t NF() {
                return (N > MAX_TM_FRACTION) ? MAX_TM_FRACTION : N;
            }

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING() : local_time_(), time_difference_() {
            };

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(const uint8_t& arg__hours,
                    const uint8_t& arg__minutes,
                    const uint8_t& arg__seconds,
                    const integer_type& arg__fraction,
                    const TIME_DIFFERENCE& arg__time_difference = TIME_DIFFERENCE()) :
            local_time_(TIME_OF_DAY_AND_FRACTION(arg__hours, arg__minutes, arg__seconds, arg__fraction)),
            time_difference_(arg__time_difference) {
            };

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(const std::string& vl) : local_time_(), time_difference_() {
                as_string(vl);
            };

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(const char* vl) : local_time_(), time_difference_() {
                as_string(vl);
            };

            TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING(const base_time_duration& vl, std::size_t frc = 0) :
            local_time_(TIME_OF_DAY_AND_FRACTION(vl, frc)),
            time_difference_() {
            };

            base_time_duration as_time(std::size_t frc = 0) const {
                return local_time().as_time(frc);
            }

            std::string as_string() const {
                return local_time().as_string() + time_difference().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('-');
                if (it == std::string::npos)
                    it = vl.find_first_of('+');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it);
                local_time(TIME_OF_DAY_AND_FRACTION(vll));
                time_difference(TIME_DIFFERENCE(vlr));
            }

            ITU_T_HOLDERH_T_DECL(local_time, TIME_OF_DAY_AND_FRACTION);
            ITU_T_HOLDERH_T_DECL(time_difference, TIME_DIFFERENCE);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(local_time_);
                ITU_T_BIND_PER(time_difference_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(local_time_);
                ITU_T_BIND_PER(time_difference_);
            }

            std::string format() const {
                return "hh:mm:ss," + std::string(NF() ? NF() : 1, 'n') + time_difference().format();
            };


            ITU_T_TIME_COUTTP_FN(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };







        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        template<typename DT, typename TM>
        struct DATE_TIME_ENCODING {

            typedef DT DATE_TYPE;
            typedef TM TIME_TYPE;

            DATE_TIME_ENCODING() : date_(), time_() {
            };

            DATE_TIME_ENCODING(const DATE_TYPE& arg__date,
                    const TIME_TYPE& arg__time) :
            date_(arg__date),
            time_(arg__time) {
            };

            DATE_TIME_ENCODING(const std::string& vl) : date_(), time_() {
                as_string(vl);
            };

            DATE_TIME_ENCODING(const char* vl) : date_(), time_() {
                as_string(vl);
            };

            DATE_TIME_ENCODING(const base_date_time& vl) :
            date_(DATE((!vl.is_special() && !vl.date().is_special()) ?
            vl.date() : base_date())),
            time_(TIME_OF_DAY((!vl.is_special() && !vl.time_of_day().is_special()) ?
            vl.time_of_day() : base_time_duration())) {
            };

            base_date_time as_datetime() const {
                try {
                    return base_date_time(as_date()) + as_time();
                } catch (...) {
                }
                return base_date_time();
            }

            base_date as_date() const {
                return date().as_date();
            }

            base_time_duration as_time() const {
                return time().as_time();
            }

            std::string as_string() const {
                return date().as_string() + "T" + time().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('T');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
                date(DATE_TYPE(vll));
                time(TIME_TYPE(vlr));
            };

            ITU_T_HOLDERH_T_DECL(date, DATE_TYPE);
            ITU_T_HOLDERH_T_DECL(time, TIME_TYPE);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(date_);
                ITU_T_BIND_PER(time_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(date_);
                ITU_T_BIND_PER(time_);
            }

            std::string format() const {
                return date().format() + "T" + time().format();
            };

            ITU_T_TIME_COUTTP_FN(DATE_TIME_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };






        // sequence TIME-OF-DAY-AND-DIFF-AND-FRACTION-ENCODING

        struct DATE_TIME {

            typedef DATE DATE_TYPE;
            typedef TIME_OF_DAY TIME_TYPE;

            DATE_TIME() : date_(), time_() {
            };

            DATE_TIME(const DATE& arg__date,
                    const TIME_OF_DAY& arg__time) :
            date_(arg__date),
            time_(arg__time) {
            };

            DATE_TIME(const std::string& vl) : date_(), time_() {
                as_string(vl);
            };

            DATE_TIME(const char* vl) : date_(), time_() {
                as_string(vl);
            };

            DATE_TIME(const base_date_time& vl) :
            date_(DATE((!vl.is_special() && !vl.date().is_special()) ?
            vl.date() : base_date())),
            time_(TIME_OF_DAY((!vl.is_special() && !vl.time_of_day().is_special()) ?
            vl.time_of_day() : base_time_duration())) {
            };

            base_date_time as_datetime() const {
                try {
                    return base_date_time(as_date()) + as_time();
                } catch (...) {
                }
                return base_date_time();
            }

            base_date as_date() const {
                return date().as_date();
            }

            base_time_duration as_time() const {
                return time().as_time();
            }

            std::string as_string() const {
                return date().as_string() + "T" + time().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('T');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
                date(DATE(vll));
                time(TIME_OF_DAY(vlr));
            };

            ITU_T_HOLDERH_T_DECL(date, DATE);
            ITU_T_HOLDERH_T_DECL(time, TIME_OF_DAY);

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(date_);
                ITU_T_BIND_PER(time_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(date_);
                ITU_T_BIND_PER(time_);
            }

            std::string format() const {
                return date().format() + "T" + time().format();
            };

            ITU_T_TIME_COUTTP_FN(DATE_TIME);

            ITU_T_TIME_X690_FN_ID_DECL(TYPE_DATE_TIME);
            ITU_T_ARCHIVE_FUNC;
        };





        // temlate for
        // sequence START-END-DATE-INTERVAL-ENCODING
        // sequence START-END-TIME-INTERVAL-ENCODING      
        // sequence START-END-DATE-TIME-INTERVAL-ENCODING

        template<typename T>
        struct START_END_INTERVAL_ENCODING {

            typedef T Tm_Type;

            START_END_INTERVAL_ENCODING() : start_(), end_() {
            };

            START_END_INTERVAL_ENCODING(const Tm_Type& arg__start,
                    const Tm_Type& arg__end) :
            start_(arg__start),
            end_(arg__end) {
            };

            START_END_INTERVAL_ENCODING(const std::string& vl) : start_(), end_() {
                as_string(vl);
            };

            START_END_INTERVAL_ENCODING(const char* vl) : start_(), end_() {
                as_string(vl);
            };

            std::string as_string() const {
                return start().as_string() + "/" + end().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('/');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
                start(Tm_Type(vll));
                end(Tm_Type(vlr));
            };

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(end_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(end_);
            }

            std::string format() const {
                return start().format() + "/" + end().format();
            };

            ITU_T_HOLDERH_DECL(start, Tm_Type);
            ITU_T_HOLDERH_DECL(end, Tm_Type);

            ITU_T_TIME_COUTTP_FN(START_END_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // sequence DURATION-INTERVAL-ENCODING

        struct DURATION_INTERVAL_ENCODING {

            struct Fractional_part_type;

            struct Fractional_part_type {

                Fractional_part_type();

                Fractional_part_type(const integer_type& arg__number_of_digits,
                        const integer_type& arg__fractional_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...   3 ]   ...ext...) 
                ITU_T_HOLDERH_DECL(fractional_value, integer_type); //   Ic(  [ 1  ...   999 ]   ...ext...) 

                ITU_T_ARCHIVE_FUNC;
            };



            DURATION_INTERVAL_ENCODING(integer_type arg__years = 0,
                    integer_type arg__months = 0,
                    integer_type arg__weeks = 0,
                    integer_type arg__days = 0,
                    integer_type arg__hours = 0,
                    integer_type arg__minutes = 0,
                    integer_type arg__seconds = 0,
                    ITU_T_SHARED(Fractional_part_type) arg__fractional_part = ITU_T_SHARED(Fractional_part_type)());


            DURATION_INTERVAL_ENCODING(const std::string& vl);

            DURATION_INTERVAL_ENCODING(const char* vl);

            //DURATION_INTERVAL_ENCODING(const base_duration& vl);            

            std::string as_string() const;

            void as_string(const std::string& v);

            //base_duration as_duration() const;         

            ITU_T_OPTIONAL_DECL(years, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(months, integer_type); //   Ic(  [ 0  ...   15 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(weeks, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(days, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(hours, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(minutes, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(seconds, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(fractional_part, Fractional_part_type);

            std::string format() const {
                return "PnYnMnWnDTnHnMnS";
            };

            ITU_T_TIME_COUTTP_FN(DURATION_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };








        // sequence DURATION

        struct DURATION {

            struct Fractional_part_type;

            struct Fractional_part_type {

                Fractional_part_type();

                Fractional_part_type(const integer_type& arg__number_of_digits,
                        const integer_type& arg__fractional_value);

                ITU_T_HOLDERH_DECL(number_of_digits, integer_type); //   Ic(  [ 1  ...   3 ]   ...ext...) 
                ITU_T_HOLDERH_DECL(fractional_value, integer_type); //   Ic(  [ 1  ...   999 ]   ...ext...) 

                ITU_T_ARCHIVE_FUNC;
            };



            DURATION(integer_type arg__years = 0,
                    integer_type arg__months = 0,
                    integer_type arg__weeks = 0,
                    integer_type arg__days = 0,
                    integer_type arg__hours = 0,
                    integer_type arg__minutes = 0,
                    integer_type arg__seconds = 0,
                    ITU_T_SHARED(Fractional_part_type) arg__fractional_part = ITU_T_SHARED(Fractional_part_type)());


            DURATION(const std::string& vl);

            DURATION(const char* vl);

            //DURATION(const base_duration& vl);            

            std::string as_string() const;

            void as_string(const std::string& v);

            //base_duration as_duration() const;         

            ITU_T_OPTIONAL_DECL(years, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(months, integer_type); //   Ic(  [ 0  ...   15 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(weeks, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(days, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(hours, integer_type); //   Ic(  [ 0  ...   31 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(minutes, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(seconds, integer_type); //   Ic(  [ 0  ...   63 ]   ...ext...) 
            ITU_T_OPTIONAL_DECL(fractional_part, Fractional_part_type);

            std::string format() const {
                return "PnYnMnWnDTnHnMnS";
            };

            ITU_T_TIME_COUTTP_FN(DURATION);

            ITU_T_TIME_X690_FN_ID_DECL(TYPE_DURATION);
            ITU_T_ARCHIVE_FUNC;
        };




        // temlate for
        // sequence START-DATE-IDURATION-NTERVAL-ENCODING
        // sequence START-TIME-DURATION-INTERVAL-ENCODING      
        // sequence START-DATE-TIME-DURATION-INTERVAL-ENCODING

        template<typename T>
        struct START_DURATION_INTERVAL_ENCODING {

            typedef T Tm_Type;

            START_DURATION_INTERVAL_ENCODING() : start_(), duration_() {
            };

            START_DURATION_INTERVAL_ENCODING(const Tm_Type& arg__start,
                    const DURATION& arg__duration) :
            start_(arg__start),
            duration_(arg__duration) {
            };

            START_DURATION_INTERVAL_ENCODING(const std::string& vl) : start_(), duration_() {
                as_string(vl);
            };

            START_DURATION_INTERVAL_ENCODING(const char* vl) : start_(), duration_() {
                as_string(vl);
            };

            std::string as_string() const {
                return start().as_string() + "/" + duration().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('/');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
                start(Tm_Type(vll));
                duration(DURATION(vlr));
            };

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(duration_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(duration_);
            }

            std::string format() const {
                return start().format() + "/" + duration().format();
            };

            ITU_T_HOLDERH_DECL(start, Tm_Type);
            ITU_T_HOLDERH_DECL(duration, DURATION);

            ITU_T_TIME_COUTTP_FN(START_DURATION_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };






        // temlate for
        // sequence DURATION-END-DATE-INTERVAL-ENCODING
        // sequence DURATION-END-TIME-INTERVAL-ENCODING      
        // sequence DURATION-END-DATE-TIME-INTERVAL-ENCODING

        template<typename T>
        struct DURATION_END_INTERVAL_ENCODING {

            typedef T Tm_Type;

            DURATION_END_INTERVAL_ENCODING() : duration_(), end_() {
            };

            DURATION_END_INTERVAL_ENCODING(const Tm_Type& arg__duration,
                    const Tm_Type& arg__end) :
            duration_(arg__duration),
            end_(arg__end) {
            };

            DURATION_END_INTERVAL_ENCODING(const std::string& vl) : duration_(), end_() {
                as_string(vl);
            };

            DURATION_END_INTERVAL_ENCODING(const char* vl) : duration_(), end_() {
                as_string(vl);
            };

            std::string as_string() const {
                return duration().as_string() + "/" + end().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('/');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vlr = (it == std::string::npos) ? "" : vl.substr(it + 1);
                duration(Tm_Type(vll));
                end(Tm_Type(vlr));
            };

            void serialize(boost::asn1::x691::output_coder& arch) {
                ITU_T_BIND_PER(duration_);
                ITU_T_BIND_PER(end_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {
                ITU_T_BIND_PER(duration_);
                ITU_T_BIND_PER(end_);
            }

            std::string format() const {
                return duration().format() + "/" + end().format();
            };

            ITU_T_HOLDERH_DECL(duration, DURATION);
            ITU_T_HOLDERH_DECL(end, Tm_Type);

            ITU_T_TIME_COUTTP_FN(DURATION_END_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };




        // temlate for
        // sequence REC-START-END-DATE-INTERVAL-ENCODING
        // sequence REC-START-END-TIME-INTERVAL-ENCODING      
        // sequence REC-START-END-DATE-TIME-INTERVAL-ENCODING

        template<typename T>
        struct REC_START_END_INTERVAL_ENCODING {

            typedef T Tm_Type;

            REC_START_END_INTERVAL_ENCODING() : recurrence_(), start_(), end_() {
            };

            REC_START_END_INTERVAL_ENCODING(const Tm_Type& arg__start,
                    const Tm_Type& arg__end,
                    integer_type arg__recurrence = 0) :
            recurrence_(arg__recurrence ? ITU_T_MAKE(integer_type)(arg__recurrence) :
            (ITU_T_SHARED(integer_type)())),
            start_(arg__start),
            end_(arg__end) {
            };

            REC_START_END_INTERVAL_ENCODING(const std::string& vl) : recurrence_(), start_(), end_() {
                as_string(vl);
            };

            REC_START_END_INTERVAL_ENCODING(const char* vl) : recurrence_(), start_(), end_() {
                as_string(vl);
            };

            std::string as_string() const {
                return "R" + ((recurrence() && *recurrence()) ? (time_detail::to_string(*recurrence())) : (std::string()))
                        + "/" + start().as_string() + "/" + end().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('/');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vl2 = (it == std::string::npos) ? "" : vl.substr(it + 1);
                std::string::size_type it2 = vl2.find_first_of('/');
                std::string vls = (it2 == std::string::npos) ? vl2 : vl2.substr(0, it2);
                std::string vlr = (it2 == std::string::npos) ? "" : vl2.substr(it2 + 1);
                if (vll.size() > 1) {
                    vll = vll.substr(1);
                    integer_type rc = time_detail::string_to_def<integer_type>(vll);
                    recurrence_ = rc ? (ITU_T_MAKE(integer_type)(rc)) :
                            (ITU_T_SHARED(integer_type)());
                } else
                    recurrence_ = ITU_T_SHARED(integer_type)();
                start(Tm_Type(vls));
                end(Tm_Type(vlr));
            };

            void serialize(boost::asn1::x691::output_coder& arch) {

                ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

                ITU_T_OPTIONAL_WRITE;

                ITU_T_BIND_PER(recurrence_);
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(end_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {

                ITU_T_OPTIONAL_READ(1);

                ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(end_);
            }

            std::string format() const {
                return "Rn/" + start().format() + "/" + end().format();
            };

            ITU_T_OPTIONAL_DECL(recurrence, integer_type);
            ITU_T_HOLDERH_DECL(start, Tm_Type);
            ITU_T_HOLDERH_DECL(end, Tm_Type);

            ITU_T_TIME_COUTTP_FN(REC_START_END_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };




        // sequence REC-DURATION-INTERVAL-ENCODING

        struct REC_DURATION_INTERVAL_ENCODING {

            REC_DURATION_INTERVAL_ENCODING();

            REC_DURATION_INTERVAL_ENCODING(
                    const DURATION_INTERVAL_ENCODING& arg__duration,
                    integer_type arg__recurrence = 0);

            REC_DURATION_INTERVAL_ENCODING(const std::string& vl);

            REC_DURATION_INTERVAL_ENCODING(const char* vl);

            std::string as_string() const;

            void as_string(const std::string& v);

            std::string format() const {
                return "Rn/" + duration().format();
            };

            ITU_T_OPTIONAL_DECL(recurrence, integer_type);
            ITU_T_HOLDERH_DECL(duration, DURATION_INTERVAL_ENCODING);

            ITU_T_TIME_COUTTP_FN(REC_DURATION_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };






        // temlate for
        // sequence REC-START-DATE-DURATION-INTERVAL-ENCODING
        // sequence REC-START-TIME-DURATION-INTERVAL-ENCODING      
        // sequence REC-START-DATE-TIME-DURATION-INTERVAL-ENCODING

        template<typename T>
        struct REC_START_DURATION_INTERVAL_ENCODING {

            typedef T Tm_Type;

            REC_START_DURATION_INTERVAL_ENCODING() : recurrence_(), start_(), duration_() {
            };

            REC_START_DURATION_INTERVAL_ENCODING(const Tm_Type& arg__start,
                    const DURATION& arg__duration,
                    integer_type arg__recurrence = 0) :
            recurrence_(arg__recurrence ? ITU_T_MAKE(integer_type)(arg__recurrence) :
            (ITU_T_SHARED(integer_type)())),
            start_(arg__start),
            duration_(arg__duration) {
            };

            REC_START_DURATION_INTERVAL_ENCODING(const std::string& vl) : recurrence_(), start_(), duration_() {
                as_string(vl);
            };

            REC_START_DURATION_INTERVAL_ENCODING(const char* vl) : recurrence_(), start_(), duration_() {
                as_string(vl);
            };

            std::string as_string() const {
                return "R" + ((recurrence() && *recurrence()) ? (time_detail::to_string(*recurrence())) : (std::string()))
                        + "/" + start().as_string() + "/" + duration().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('/');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vl2 = (it == std::string::npos) ? "" : vl.substr(it + 1);
                std::string::size_type it2 = vl2.find_first_of('/');
                std::string vls = (it2 == std::string::npos) ? vl2 : vl2.substr(0, it2);
                std::string vlr = (it2 == std::string::npos) ? "" : vl2.substr(it2 + 1);
                if (vll.size() > 1) {
                    vll = vll.substr(1);
                    integer_type rc = time_detail::string_to_def<integer_type>(vll);
                    recurrence_ = rc ? (ITU_T_MAKE(integer_type)(rc)) :
                            (ITU_T_SHARED(integer_type)());
                } else
                    recurrence_ = ITU_T_SHARED(integer_type)();
                start(Tm_Type(vls));
                duration(DURATION(vlr));
            };

            void serialize(boost::asn1::x691::output_coder& arch) {

                ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

                ITU_T_OPTIONAL_WRITE;

                ITU_T_BIND_PER(recurrence_);
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(duration_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {

                ITU_T_OPTIONAL_READ(1);

                ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
                ITU_T_BIND_PER(start_);
                ITU_T_BIND_PER(duration_);
            }

            std::string format() const {
                return "Rn/" + start().format() + "/" + duration().format();
            };

            ITU_T_OPTIONAL_DECL(recurrence, integer_type);
            ITU_T_HOLDERH_DECL(start, Tm_Type);
            ITU_T_HOLDERH_DECL(duration, DURATION);

            ITU_T_TIME_COUTTP_FN(REC_START_DURATION_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        // temlate for
        // sequence REC-DURATION-END-DATE-INTERVAL-ENCODING
        // sequence REC-DURATION-END-TIME-INTERVAL-ENCODING      
        // sequence REC-DURATION-END-DATE-TIME-INTERVAL-ENCODING

        template<typename T>
        struct REC_DURATION_END_INTERVAL_ENCODING {

            typedef T Tm_Type;

            REC_DURATION_END_INTERVAL_ENCODING() : recurrence_(), duration_(), end_() {
            };

            REC_DURATION_END_INTERVAL_ENCODING(const DURATION& arg__duration,
                    const Tm_Type& arg__end,
                    integer_type arg__recurrence = 0) :
            recurrence_(arg__recurrence ? ITU_T_MAKE(integer_type)(arg__recurrence) :
            (ITU_T_SHARED(integer_type)())),
            duration_(arg__duration),
            end_(arg__end) {
            };

            REC_DURATION_END_INTERVAL_ENCODING(const std::string& vl) : recurrence_(), duration_(), end_() {
                as_string(vl);
            };

            REC_DURATION_END_INTERVAL_ENCODING(const char* vl) : recurrence_(), duration_(), end_() {
                as_string(vl);
            };

            std::string as_string() const {
                return "R" + ((recurrence() && *recurrence()) ? (time_detail::to_string(*recurrence())) : (std::string()))
                        + "/" + duration().as_string() + "/" + end().as_string();
            }

            void as_string(const std::string& v) {
                std::string vl = time_detail::normalize_time_str(v);
                std::string::size_type it = vl.find_first_of('/');
                std::string vll = (it == std::string::npos) ? vl : vl.substr(0, it);
                std::string vl2 = (it == std::string::npos) ? "" : vl.substr(it + 1);
                std::string::size_type it2 = vl2.find_first_of('/');
                std::string vls = (it2 == std::string::npos) ? vl2 : vl2.substr(0, it2);
                std::string vlr = (it2 == std::string::npos) ? "" : vl2.substr(it2 + 1);
                if (vll.size() > 1) {
                    vll = vll.substr(1);
                    integer_type rc = time_detail::string_to_def<integer_type>(vll);
                    recurrence_ = rc ? (ITU_T_MAKE(integer_type)(rc)) :
                            (ITU_T_SHARED(integer_type)());
                } else
                    recurrence_ = ITU_T_SHARED(integer_type)();
                duration(DURATION(vls));
                end(Tm_Type(vlr));
            };

            void serialize(boost::asn1::x691::output_coder& arch) {

                ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(recurrence_);

                ITU_T_OPTIONAL_WRITE;

                ITU_T_BIND_PER(recurrence_);
                ITU_T_BIND_PER(duration_);
                ITU_T_BIND_PER(end_);
            }

            void serialize(boost::asn1::x691::input_coder& arch) {

                ITU_T_OPTIONAL_READ(1);

                ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(recurrence_);
                ITU_T_BIND_PER(duration_);
                ITU_T_BIND_PER(end_);
            }

            std::string format() const {
                return "Rn/" + duration().format() + "/" + end().format();
            };

            ITU_T_OPTIONAL_DECL(recurrence, integer_type);
            ITU_T_HOLDERH_DECL(duration, DURATION);
            ITU_T_HOLDERH_DECL(end, Tm_Type);

            ITU_T_TIME_COUTTP_FN(REC_DURATION_END_INTERVAL_ENCODING);

            ITU_T_TIME_X690_FN_DECL;
            ITU_T_ARCHIVE_FUNC;
        };





        typedef ANY_CENTURY_ENCODING<0> ANY_CENTURY;
        typedef ANY_YEAR_ENCODING<0> ANY_YEAR;
        typedef ANY_YEAR_MONTH_ENCODING<0> ANY_YEAR_MONTH;
        typedef ANY_DATE_ENCODING<0> ANY_DATE;
        typedef ANY_YEAR_DAY_ENCODING<0> ANY_YEAR_DAY;
        typedef ANY_YEAR_WEEK_ENCODING<0> ANY_YEAR_WEEK;
        typedef ANY_YEAR_WEEK_DAY_ENCODING<0> ANY_YEAR_WEEK_DAY;


        // choice DATE-TYPE

        enum DATE_TYPE_enum {

            DATE_TYPE_null = 0,
            DATE_TYPE_date_C_Basic,
            DATE_TYPE_date_C_L,
            DATE_TYPE_date_Y_Basic,
            DATE_TYPE_date_Y_L,
            DATE_TYPE_date_YM_Basic,
            DATE_TYPE_date_YM_L,
            DATE_TYPE_date_YMD_Basic,
            DATE_TYPE_date_YMD_L,
            DATE_TYPE_date_YD_Basic,
            DATE_TYPE_date_YD_L,
            DATE_TYPE_date_YW_Basic,
            DATE_TYPE_date_YW_L,
            DATE_TYPE_date_YWD_Basic,
            DATE_TYPE_date_YWD_L,
        };

        struct DATE_TYPE : public ITU_T_CHOICE(DATE_TYPE_enum) {


            ITU_T_CHOICE_CTORS(DATE_TYPE);

            DATE_TYPE(const std::string & vl);

            DATE_TYPE(const char* vl);

            DATE_TYPE(const base_date & vl, DATE_TYPE_enum enm);

            base_date as_date();

            std::string as_string();

            void as_string(const std::string & v);


            ITU_T_CHOICES_DECL(date_C_Basic, CENTURY_ENCODING, DATE_TYPE_date_C_Basic); // primitive
            ITU_T_CHOICES_DECL(date_C_L, ANY_CENTURY, DATE_TYPE_date_C_L); // primitive
            ITU_T_CHOICES_DECL(date_Y_Basic, YEAR_ENCODING, DATE_TYPE_date_Y_Basic); // primitive
            ITU_T_CHOICES_DECL(date_Y_L, ANY_YEAR, DATE_TYPE_date_Y_L); // primitive
            ITU_T_CHOICES_DECL(date_YM_Basic, YEAR_MONTH_ENCODING, DATE_TYPE_date_YM_Basic); // primitive
            ITU_T_CHOICES_DECL(date_YM_L, ANY_YEAR_MONTH, DATE_TYPE_date_YM_L); // primitive
            ITU_T_CHOICES_DECL(date_YMD_Basic, DATE_ENCODING, DATE_TYPE_date_YMD_Basic); // primitive
            ITU_T_CHOICES_DECL(date_YMD_L, ANY_DATE, DATE_TYPE_date_YMD_L); // primitive
            ITU_T_CHOICES_DECL(date_YD_Basic, YEAR_DAY_ENCODING, DATE_TYPE_date_YD_Basic); // primitive
            ITU_T_CHOICES_DECL(date_YD_L, ANY_YEAR_DAY, DATE_TYPE_date_YD_L); // primitive
            ITU_T_CHOICES_DECL(date_YW_Basic, YEAR_WEEK_ENCODING, DATE_TYPE_date_YW_Basic); // primitive
            ITU_T_CHOICES_DECL(date_YW_L, ANY_YEAR_WEEK, DATE_TYPE_date_YW_L); // primitive
            ITU_T_CHOICES_DECL(date_YWD_Basic, YEAR_WEEK_DAY_ENCODING, DATE_TYPE_date_YWD_Basic); // primitive
            ITU_T_CHOICES_DECL(date_YWD_L, ANY_YEAR_WEEK_DAY, DATE_TYPE_date_YWD_L); // primitive

            std::string format();

            ITU_T_TIME_COUTTP_NCFN(DATE_TYPE);

            ITU_T_ARCHIVE_FUNC;
        };
        



        
        
        

        typedef HOURS_AND_FRACTION_ENCODING<0> HOURS_AND_FRACTION;
        typedef HOURS_UTC_AND_FRACTION_ENCODING<0> HOURS_UTC_AND_FRACTION;
        typedef HOURS_AND_DIFF_AND_FRACTION_ENCODING<0> HOURS_AND_DIFF_AND_FRACTION;
        typedef MINUTES_AND_FRACTION_ENCODING<0> MINUTES_AND_FRACTION;
        typedef MINUTES_UTC_AND_FRACTION_ENCODING<0> MINUTES_UTC_AND_FRACTION;
        typedef MINUTES_AND_DIFF_AND_FRACTION_ENCODING<0> MINUTES_AND_DIFF_AND_FRACTION;
        typedef TIME_OF_DAY_AND_FRACTION_ENCODING<0> TIME_OF_DAY_AND_FRACTION;
        typedef TIME_OF_DAY_UTC_AND_FRACTION_ENCODING<0> TIME_OF_DAY_UTC_AND_FRACTION;
        typedef TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING<0> TIME_OF_DAY_AND_DIFF_AND_FRACTION;


        // sequence TIME-TYPE

        struct TIME_TYPE {

            struct Time_type;

            enum Time_type_enum {

                Time_type_null = 0,
                Time_type_time_H_L,
                Time_type_time_H_Z,
                Time_type_time_H_LD,
                Time_type_time_HM_L,
                Time_type_time_HM_Z,
                Time_type_time_HM_LD,
                Time_type_time_HMS_L,
                Time_type_time_HMS_Z,
                Time_type_time_HMS_LD,
                Time_type_time_HFn_L,
                Time_type_time_HFn_Z,
                Time_type_time_HFn_LD,
                Time_type_time_HMFn_L,
                Time_type_time_HMFn_Z,
                Time_type_time_HMFn_LD,
                Time_type_time_HMFSn_L,
                Time_type_time_HMFSn_Z,
                Time_type_time_HMFSn_LD,
            };

            struct Time_type : public ITU_T_CHOICE(Time_type_enum) {


                ITU_T_CHOICE_CTORS(Time_type);

                ITU_T_CHOICES_DECL(time_H_L, HOURS_ENCODING, Time_type_time_H_L); // primitive
                ITU_T_CHOICES_DECL(time_H_Z, HOURS_UTC_ENCODING, Time_type_time_H_Z); // primitive
                ITU_T_CHOICES_DECL(time_H_LD, HOURS_AND_DIFF_ENCODING, Time_type_time_H_LD); // primitive
                ITU_T_CHOICES_DECL(time_HM_L, MINUTES_ENCODING, Time_type_time_HM_L); // primitive
                ITU_T_CHOICES_DECL(time_HM_Z, MINUTES_UTC_ENCODING, Time_type_time_HM_Z); // primitive
                ITU_T_CHOICES_DECL(time_HM_LD, MINUTES_AND_DIFF_ENCODING, Time_type_time_HM_LD); // primitive
                ITU_T_CHOICES_DECL(time_HMS_L, TIME_OF_DAY_ENCODING, Time_type_time_HMS_L); // primitive
                ITU_T_CHOICES_DECL(time_HMS_Z, TIME_OF_DAY_UTC_ENCODING, Time_type_time_HMS_Z); // primitive
                ITU_T_CHOICES_DECL(time_HMS_LD, TIME_OF_DAY_AND_DIFF_ENCODING, Time_type_time_HMS_LD); // primitive
                ITU_T_CHOICES_DECL(time_HFn_L, HOURS_AND_FRACTION, Time_type_time_HFn_L); // primitive
                ITU_T_CHOICES_DECL(time_HFn_Z, HOURS_UTC_AND_FRACTION, Time_type_time_HFn_Z); // primitive
                ITU_T_CHOICES_DECL(time_HFn_LD, HOURS_AND_DIFF_AND_FRACTION, Time_type_time_HFn_LD); // primitive
                ITU_T_CHOICES_DECL(time_HMFn_L, MINUTES_AND_FRACTION, Time_type_time_HMFn_L); // primitive
                ITU_T_CHOICES_DECL(time_HMFn_Z, MINUTES_UTC_AND_FRACTION, Time_type_time_HMFn_Z); // primitive
                ITU_T_CHOICES_DECL(time_HMFn_LD, MINUTES_AND_DIFF_AND_FRACTION, Time_type_time_HMFn_LD); // primitive
                ITU_T_CHOICES_DECL(time_HMFSn_L, TIME_OF_DAY_AND_FRACTION, Time_type_time_HMFSn_L); // primitive
                ITU_T_CHOICES_DECL(time_HMFSn_Z, TIME_OF_DAY_UTC_AND_FRACTION, Time_type_time_HMFSn_Z); // primitive
                ITU_T_CHOICES_DECL(time_HMFSn_LD, TIME_OF_DAY_AND_DIFF_AND_FRACTION, Time_type_time_HMFSn_LD); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            TIME_TYPE();

            TIME_TYPE(const Time_type& arg__time_type);

            TIME_TYPE(const std::string & vl);

            TIME_TYPE(const char* vl);

            TIME_TYPE(const base_date & vl, Time_type_enum enm);

            base_time_duration as_time();

            std::string as_string();

            void as_string(const std::string & v);           
            
            std::string format();

            ITU_T_OPTIONAL_DECL(number_of_digits, integer_type);  //   Ic(  [ 1  ...    ]   
            ITU_T_HOLDERH_DECL(time_type, Time_type);            
            ITU_T_TIME_COUTTP_NCFN(TIME_TYPE);            
            
            ITU_T_ARCHIVE_FUNC;
        };        
        
        
        
        


        ITU_T_ARCHIVE_X690_DECL(DATE_TYPE);
        ITU_T_ARCHIVE_X690_DECL(TIME_TYPE);       

        ITU_T_ARCHIVE_X691_DECL(CENTURY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_MONTH_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DATE_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DATE);
        ITU_T_ARCHIVE_X691_DECL(YEAR_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_WEEK_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(YEAR_WEEK_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_UTC_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(HOURS_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_DIFFERENCE);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_UTC_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(MINUTES_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_UTC_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(TIME_OF_DAY_AND_DIFF_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DURATION_INTERVAL_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DURATION_INTERVAL_ENCODING::Fractional_part_type);
        ITU_T_ARCHIVE_X691_DECL(DURATION);
        ITU_T_ARCHIVE_X691_DECL(DURATION::Fractional_part_type);
        ITU_T_ARCHIVE_X691_DECL(REC_DURATION_INTERVAL_ENCODING);
        ITU_T_ARCHIVE_X691_DECL(DATE_TYPE);
        ITU_T_ARCHIVE_X691_DECL(TIME_TYPE);
        ITU_T_ARCHIVE_X691_DECL(TIME_TYPE::Time_type);       
        
    }
}

ITU_T_CHOICE_REGESTRATE(boost::asn1::YEAR_ENCODING);
ITU_T_CHOICE_REGESTRATE(boost::asn1::DATE_TYPE);
ITU_T_CHOICE_REGESTRATE(boost::asn1::TIME_TYPE::Time_type);

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___DEFINEDTIME */
