#ifndef ___UNITTEST1B
#define ___UNITTEST1B

#include <cstdlib>
#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <set>
#include <limits>
#include <iostream>

#include <boost/make_shared.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>
#include <boost/itu/coder/asn1_stream.hpp>
#include "Test1.hpp"
#include "Test1b.hpp"

#include <boost/itu/time/DefinedTime.hpp>

#define DEBUG_VAL_ITU(a)  tsstr.clear(); std::cout << #a " = "  <<  a  << "    ===> ";   tsstr << a;
#define DEBUG_VAL_ITU_READ(a)     tsstr >> a; std::cout << "read     " <<  #a " = "  <<  a << " as_dt : "  << a.as_datetime() <<  " wd:" << ((a.as_datetime().is_special()) ? 0 : (int)(a.as_datetime().date().day_of_week())) << "\n-----------------------------------------------------------------------------------\n";
#define DEBUG_VAL_ITU_TREAD(a)     tsstr >> a; std::cout << "read     " <<  #a " = "  <<  a << " as_tm : "  << a.as_time() << "\n-----------------------------------------------------------------------------------\n";
#define DEBUG_VAL_ITU_DREAD(a)     tsstr >> a; std::cout << "read     " <<  #a " = "  <<  a  << "\n-----------------------------------------------------------------------------------\n";

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif

using namespace boost::asn1;

namespace Test1b {

    template<typename T>
    inline void test(T& tsstr) {
        DEBUG_VAL_ITU(b1)
        DEBUG_VAL_ITU(b2)
        DEBUG_VAL_ITU(i0)
        DEBUG_VAL_ITU(i1)
        DEBUG_VAL_ITU(i1_1)
        DEBUG_VAL_ITU(i2)
        DEBUG_VAL_ITU(i2_1)
        DEBUG_VAL_ITU(i2_2)
        DEBUG_VAL_ITU(i3)
        DEBUG_VAL_ITU(i3_1)
        DEBUG_VAL_ITU(i3_2)
        DEBUG_VAL_ITU(i4)
        DEBUG_VAL_ITU(i4_1)
        DEBUG_VAL_ITU(i4_2)
        DEBUG_VAL_ITU(bs0)
        DEBUG_VAL_ITU(bs1)
        DEBUG_VAL_ITU(bs2)
        DEBUG_VAL_ITU(bs3)
        DEBUG_VAL_ITU(bs4)
        DEBUG_VAL_ITU(bs5);
        DEBUG_VAL_ITU(os0)
        DEBUG_VAL_ITU(os1)
        DEBUG_VAL_ITU(os2)
        DEBUG_VAL_ITU(oi1)
        DEBUG_VAL_ITU(nl1)
        DEBUG_VAL_ITU(nl2)
        DEBUG_VAL_ITU(oi2)
        DEBUG_VAL_ITU(oi3)
        DEBUG_VAL_ITU(od1)
        DEBUG_VAL_ITU(od2)
        DEBUG_VAL_ITU(od3)
        DEBUG_VAL_ITU(rl1)
        DEBUG_VAL_ITU(rl2)
        DEBUG_VAL_ITU(rl3)
        DEBUG_VAL_ITU(rl4)
        DEBUG_VAL_ITU(rl5)
        DEBUG_VAL_ITU(rl6)
        DEBUG_VAL_ITU(rl7)
        /*DEBUG_VAL_ITU(enu1)
        DEBUG_VAL_ITU(enu2)
        DEBUG_VAL_ITU(enu3)
        DEBUG_VAL_ITU(enu4)*/
        DEBUG_VAL_ITU(utf1)
        DEBUG_VAL_ITU(utf2)
        DEBUG_VAL_ITU(utf3)
        DEBUG_VAL_ITU(roi1)
        DEBUG_VAL_ITU(roi2)
        DEBUG_VAL_ITU(roi3)
        DEBUG_VAL_ITU(ns1)
        DEBUG_VAL_ITU(ns2)
        DEBUG_VAL_ITU(ns3)
        DEBUG_VAL_ITU(ps1)
        DEBUG_VAL_ITU(ps2)
        DEBUG_VAL_ITU(ps3)
        DEBUG_VAL_ITU(tl1)
        DEBUG_VAL_ITU(tl2)
        DEBUG_VAL_ITU(tl3)
        DEBUG_VAL_ITU(tlx1)
        DEBUG_VAL_ITU(tlx2)
        DEBUG_VAL_ITU(tlx3)
        DEBUG_VAL_ITU(vdx1)
        DEBUG_VAL_ITU(vdx2)
        DEBUG_VAL_ITU(vdx3)
        DEBUG_VAL_ITU(ia1)
        DEBUG_VAL_ITU(ia2)
        DEBUG_VAL_ITU(ia3)
        DEBUG_VAL_ITU(ut1)
        DEBUG_VAL_ITU(ut2)
        DEBUG_VAL_ITU(ut3)
        DEBUG_VAL_ITU(gt1)
        DEBUG_VAL_ITU(gt2)
        DEBUG_VAL_ITU(gt3)
        DEBUG_VAL_ITU(grph1)
        DEBUG_VAL_ITU(grph2)
        DEBUG_VAL_ITU(grph3)
        DEBUG_VAL_ITU(vs1)
        DEBUG_VAL_ITU(vs2)
        DEBUG_VAL_ITU(vs3)
        DEBUG_VAL_ITU(genrl1)
        DEBUG_VAL_ITU(genrl2)
        DEBUG_VAL_ITU(genrl3)
        DEBUG_VAL_ITU(unv1)
        DEBUG_VAL_ITU(unv2)
        DEBUG_VAL_ITU(unv3)
        DEBUG_VAL_ITU(bmp1)
        DEBUG_VAL_ITU(bmp2)
        DEBUG_VAL_ITU(bmp3)
        DEBUG_VAL_ITU(oidir1)
        DEBUG_VAL_ITU(oidir2)
        DEBUG_VAL_ITU(oidir3)
        DEBUG_VAL_ITU(roidir1)
        DEBUG_VAL_ITU(roidir2)
        DEBUG_VAL_ITU(roidir3)
    }

}


namespace Test1 {

    static PersonnelRecord_s iPRt;

    template<typename T>
    inline void test(T& tsstr) {


        DEBUG_VAL_ITU(valAx)
        DEBUG_VAL_ITU(valT)
    }

}

namespace TestTm {

    using namespace boost::asn1;

    template<typename T>
    inline void test(T& tsstr) {

        CENTURY_ENCODING cetn_enc=3;
        CENTURY_ENCODING cetn_enc1=std::string("04C");
        CENTURY_ENCODING cetn_enc2="21C";        
        CENTURY_ENCODING cetn_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 1, 12));              
        ANY_CENTURY_ENCODING<3> acetn_enc(19);        
        
        CENTURY_ENCODING cetn_enc_r;
        CENTURY_ENCODING cetn_enc1_r;
        CENTURY_ENCODING cetn_enc2_r;        
        CENTURY_ENCODING cetn_enc3_r;              
        ANY_CENTURY_ENCODING<3> acetn_enc_r;             
        
        
        DEBUG_VAL_ITU(cetn_enc)
        DEBUG_VAL_ITU_READ(cetn_enc_r);
        DEBUG_VAL_ITU(cetn_enc1)  
        DEBUG_VAL_ITU_READ(cetn_enc1_r);                
        DEBUG_VAL_ITU(cetn_enc2)   
        DEBUG_VAL_ITU_READ(cetn_enc2_r);                
        DEBUG_VAL_ITU(cetn_enc3) 
        DEBUG_VAL_ITU_READ(cetn_enc3_r);                
        DEBUG_VAL_ITU(acetn_enc)                 
        DEBUG_VAL_ITU_READ(acetn_enc_r);
        
        YEAR_ENCODING year_enc=1943;
        YEAR_ENCODING year_enc1=std::string("2004");
        YEAR_ENCODING year_enc2="2125";        
        YEAR_ENCODING year_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 1, 12));              
        ANY_YEAR_ENCODING<5> ayear_enc(1958);        
        
        YEAR_ENCODING year_enc_r;
        YEAR_ENCODING year_enc1_r;
        YEAR_ENCODING year_enc2_r;        
        YEAR_ENCODING year_enc3_r;              
        ANY_YEAR_ENCODING<5> ayear_enc_r;             
        
        
        DEBUG_VAL_ITU(year_enc)
        DEBUG_VAL_ITU_READ(year_enc_r);
        DEBUG_VAL_ITU(year_enc1)  
        DEBUG_VAL_ITU_READ(year_enc1_r);                
        DEBUG_VAL_ITU(year_enc2)   
        DEBUG_VAL_ITU_READ(year_enc2_r);                
        DEBUG_VAL_ITU(year_enc3) 
        DEBUG_VAL_ITU_READ(year_enc3_r);                
        DEBUG_VAL_ITU(ayear_enc)                 
        DEBUG_VAL_ITU_READ(ayear_enc_r);        
        
        YEAR_MONTH_ENCODING year_month_enc(1941,6);
        YEAR_MONTH_ENCODING year_month_enc1=std::string("2004-08");
        YEAR_MONTH_ENCODING year_month_enc2="2015-07";        
        YEAR_MONTH_ENCODING year_month_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_MONTH_ENCODING<5> ayear_month_enc(1958, 7);        
        
        YEAR_MONTH_ENCODING year_month_enc_r;
        YEAR_MONTH_ENCODING year_month_enc1_r;
        YEAR_MONTH_ENCODING year_month_enc2_r;        
        YEAR_MONTH_ENCODING year_month_enc3_r;              
        ANY_YEAR_MONTH_ENCODING<5> ayear_month_enc_r;             
        
        
        DEBUG_VAL_ITU(year_month_enc)
        DEBUG_VAL_ITU_READ(year_month_enc_r);
        DEBUG_VAL_ITU(year_month_enc1)  
        DEBUG_VAL_ITU_READ(year_month_enc1_r);                
        DEBUG_VAL_ITU(year_month_enc2)   
        DEBUG_VAL_ITU_READ(year_month_enc2_r);                
        DEBUG_VAL_ITU(year_month_enc3) 
        DEBUG_VAL_ITU_READ(year_month_enc3_r);                
        DEBUG_VAL_ITU(ayear_month_enc)                 
        DEBUG_VAL_ITU_READ(ayear_month_enc_r);         
        
        
        DATE_ENCODING date_enc(1941,6,22);
        DATE_ENCODING date_enc1=std::string("2004-08-30");
        DATE_ENCODING date_enc2="2015-07-24";        
        DATE_ENCODING date_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_DATE_ENCODING<5> adate_enc(1958, 7,6);        
        
        DATE_ENCODING date_enc_r;
        DATE_ENCODING date_enc1_r;
        DATE_ENCODING date_enc2_r;        
        DATE_ENCODING date_enc3_r;              
        ANY_DATE_ENCODING<5> adate_enc_r;             
        
        
        DEBUG_VAL_ITU(date_enc)
        DEBUG_VAL_ITU_READ(date_enc_r);
        DEBUG_VAL_ITU(date_enc1)  
        DEBUG_VAL_ITU_READ(date_enc1_r);                
        DEBUG_VAL_ITU(date_enc2)   
        DEBUG_VAL_ITU_READ(date_enc2_r);                
        DEBUG_VAL_ITU(date_enc3) 
        DEBUG_VAL_ITU_READ(date_enc3_r);                
        DEBUG_VAL_ITU(adate_enc)                 
        DEBUG_VAL_ITU_READ(adate_enc_r);            
        
        
        YEAR_DAY_ENCODING year_day_enc(1941,64);
        YEAR_DAY_ENCODING year_day_enc1=std::string("2004-085");
        YEAR_DAY_ENCODING year_day_enc2="2015-186";        
        YEAR_DAY_ENCODING year_day_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_DAY_ENCODING<5> ayear_day_enc(1958, 78);        
        
        YEAR_DAY_ENCODING year_day_enc_r;
        YEAR_DAY_ENCODING year_day_enc1_r;
        YEAR_DAY_ENCODING year_day_enc2_r;        
        YEAR_DAY_ENCODING year_day_enc3_r;              
        ANY_YEAR_DAY_ENCODING<5> ayear_day_enc_r;             
        
        
        DEBUG_VAL_ITU(year_day_enc)
        DEBUG_VAL_ITU_READ(year_day_enc_r);
        DEBUG_VAL_ITU(year_day_enc1)  
        DEBUG_VAL_ITU_READ(year_day_enc1_r);                
        DEBUG_VAL_ITU(year_day_enc2)   
        DEBUG_VAL_ITU_READ(year_day_enc2_r);                
        DEBUG_VAL_ITU(year_day_enc3) 
        DEBUG_VAL_ITU_READ(year_day_enc3_r);                
        DEBUG_VAL_ITU(ayear_day_enc)                 
        DEBUG_VAL_ITU_READ(ayear_day_enc_r);

      
        
        YEAR_WEEK_ENCODING year_week_enc(1941,12);
        YEAR_WEEK_ENCODING year_week_enc1=std::string("2004-W40");
        YEAR_WEEK_ENCODING year_week_enc2="2015-W18";        
        YEAR_WEEK_ENCODING year_week_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_WEEK_ENCODING<5> ayear_week_enc(1958, 43);        
        
        YEAR_WEEK_ENCODING year_week_enc_r;
        YEAR_WEEK_ENCODING year_week_enc1_r;
        YEAR_WEEK_ENCODING year_week_enc2_r;        
        YEAR_WEEK_ENCODING year_week_enc3_r;              
        ANY_YEAR_WEEK_ENCODING<5> ayear_week_enc_r;             
        
        
        DEBUG_VAL_ITU(year_week_enc)
        DEBUG_VAL_ITU_READ(year_week_enc_r);
        DEBUG_VAL_ITU(year_week_enc1)  
        DEBUG_VAL_ITU_READ(year_week_enc1_r);                
        DEBUG_VAL_ITU(year_week_enc2)   
        DEBUG_VAL_ITU_READ(year_week_enc2_r);                
        DEBUG_VAL_ITU(year_week_enc3) 
        DEBUG_VAL_ITU_READ(year_week_enc3_r);                
        DEBUG_VAL_ITU(ayear_week_enc)                 
        DEBUG_VAL_ITU_READ(ayear_week_enc_r);         
        
        
        
        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc(1941,12, 4);
        YEAR_WEEK_DAY_ENCODING year_week_day_enc1=std::string("2004-W40-2");
        YEAR_WEEK_DAY_ENCODING year_week_day_enc2="2015-W18-4";        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_WEEK_DAY_ENCODING<5> ayear_week_day_enc(1958, 43,5);        
        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc_r;
        YEAR_WEEK_DAY_ENCODING year_week_day_enc1_r;
        YEAR_WEEK_DAY_ENCODING year_week_day_enc2_r;        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc3_r;              
        ANY_YEAR_WEEK_DAY_ENCODING<5> ayear_week_day_enc_r;             
        
        
        DEBUG_VAL_ITU(year_week_day_enc)
        DEBUG_VAL_ITU_READ(year_week_day_enc_r);
        DEBUG_VAL_ITU(year_week_day_enc1)  
        DEBUG_VAL_ITU_READ(year_week_day_enc1_r);                
        DEBUG_VAL_ITU(year_week_day_enc2)   
        DEBUG_VAL_ITU_READ(year_week_day_enc2_r);                
        DEBUG_VAL_ITU(year_week_day_enc3) 
        DEBUG_VAL_ITU_READ(year_week_day_enc3_r);                
        DEBUG_VAL_ITU(ayear_week_day_enc)                 
        DEBUG_VAL_ITU_READ(ayear_week_day_enc_r);              

        /*HOURS_ENCODING hors_enc = 3;
        HOURS_ENCODING hors_enc1 = std::string("04");
        HOURS_ENCODING hors_enc2 = "21";
        HOURS_ENCODING hors_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        HOURS_ENCODING hors_enc_r;
        HOURS_ENCODING hors_enc1_r;
        HOURS_ENCODING hors_enc2_r;
        HOURS_ENCODING hors_enc3_r;


        DEBUG_VAL_ITU(hors_enc)
        DEBUG_VAL_ITU_TREAD(hors_enc_r);
        DEBUG_VAL_ITU(hors_enc1)
        DEBUG_VAL_ITU_TREAD(hors_enc1_r);
        DEBUG_VAL_ITU(hors_enc2)
        DEBUG_VAL_ITU_TREAD(hors_enc2_r);
        DEBUG_VAL_ITU(hors_enc3)
        DEBUG_VAL_ITU_TREAD(hors_enc3_r);

        HOURS_UTC_ENCODING hors_utc_enc = 3;
        HOURS_UTC_ENCODING hors_utc_enc1 = std::string("04");
        HOURS_UTC_ENCODING hors_utc_enc2 = "21";
        HOURS_UTC_ENCODING hors_utc_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        HOURS_UTC_ENCODING hors_utc_enc_r;
        HOURS_UTC_ENCODING hors_utc_enc1_r;
        HOURS_UTC_ENCODING hors_utc_enc2_r;
        HOURS_UTC_ENCODING hors_utc_enc3_r;


        DEBUG_VAL_ITU(hors_utc_enc)
        DEBUG_VAL_ITU_TREAD(hors_utc_enc_r);
        DEBUG_VAL_ITU(hors_utc_enc1)
        DEBUG_VAL_ITU_TREAD(hors_utc_enc1_r);
        DEBUG_VAL_ITU(hors_utc_enc2)
        DEBUG_VAL_ITU_TREAD(hors_utc_enc2_r);
        DEBUG_VAL_ITU(hors_utc_enc3)
        DEBUG_VAL_ITU_TREAD(hors_utc_enc3_r);

        HOURS_AND_DIFF_ENCODING hors_diff_enc = 3;
        HOURS_AND_DIFF_ENCODING hors_diff_enc1 = std::string("04+04");
        HOURS_AND_DIFF_ENCODING hors_diff_enc2 = "21+0345";
        HOURS_AND_DIFF_ENCODING hors_diff_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        HOURS_AND_DIFF_ENCODING hors_diff_enc_r;
        HOURS_AND_DIFF_ENCODING hors_diff_enc1_r;
        HOURS_AND_DIFF_ENCODING hors_diff_enc2_r;
        HOURS_AND_DIFF_ENCODING hors_diff_enc3_r;


        DEBUG_VAL_ITU(hors_diff_enc)
        DEBUG_VAL_ITU_TREAD(hors_diff_enc_r);
        DEBUG_VAL_ITU(hors_diff_enc1)
        DEBUG_VAL_ITU_TREAD(hors_diff_enc1_r);
        DEBUG_VAL_ITU(hors_diff_enc2)
        DEBUG_VAL_ITU_TREAD(hors_diff_enc2_r);
        DEBUG_VAL_ITU(hors_diff_enc3)
        DEBUG_VAL_ITU_TREAD(hors_diff_enc3_r)*/
                
                
                
                
                
                
                
                
        MINUTES_ENCODING minuts_enc (3, 25);
        MINUTES_ENCODING minuts_enc1 = std::string("0412");
        MINUTES_ENCODING minuts_enc2 = "2105";
        MINUTES_ENCODING minuts_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        MINUTES_ENCODING minuts_enc_r;
        MINUTES_ENCODING minuts_enc1_r;
        MINUTES_ENCODING minuts_enc2_r;
        MINUTES_ENCODING minuts_enc3_r;


        DEBUG_VAL_ITU(minuts_enc)
        DEBUG_VAL_ITU_TREAD(minuts_enc_r);
        DEBUG_VAL_ITU(minuts_enc1)
        DEBUG_VAL_ITU_TREAD(minuts_enc1_r);
        DEBUG_VAL_ITU(minuts_enc2)
        DEBUG_VAL_ITU_TREAD(minuts_enc2_r);
        DEBUG_VAL_ITU(minuts_enc3)
        DEBUG_VAL_ITU_TREAD(minuts_enc3_r);

        MINUTES_UTC_ENCODING minuts_utc_enc(3, 45);
        MINUTES_UTC_ENCODING minuts_utc_enc1 = std::string("0445");
        MINUTES_UTC_ENCODING minuts_utc_enc2 = "2155";
        MINUTES_UTC_ENCODING minuts_utc_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        MINUTES_UTC_ENCODING minuts_utc_enc_r;
        MINUTES_UTC_ENCODING minuts_utc_enc1_r;
        MINUTES_UTC_ENCODING minuts_utc_enc2_r;
        MINUTES_UTC_ENCODING minuts_utc_enc3_r;


        DEBUG_VAL_ITU(minuts_utc_enc)
        DEBUG_VAL_ITU_TREAD(minuts_utc_enc_r);
        DEBUG_VAL_ITU(minuts_utc_enc1)
        DEBUG_VAL_ITU_TREAD(minuts_utc_enc1_r);
        DEBUG_VAL_ITU(minuts_utc_enc2)
        DEBUG_VAL_ITU_TREAD(minuts_utc_enc2_r);
        DEBUG_VAL_ITU(minuts_utc_enc3)
        DEBUG_VAL_ITU_TREAD(minuts_utc_enc3_r);

        MINUTES_AND_DIFF_ENCODING minuts_diff_enc (3, 45);
        MINUTES_AND_DIFF_ENCODING minuts_diff_enc1 = std::string("0456+04");
        MINUTES_AND_DIFF_ENCODING minuts_diff_enc2 = "2112-0330";
        MINUTES_AND_DIFF_ENCODING minuts_diff_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        MINUTES_AND_DIFF_ENCODING minuts_diff_enc_r;
        MINUTES_AND_DIFF_ENCODING minuts_diff_enc1_r;
        MINUTES_AND_DIFF_ENCODING minuts_diff_enc2_r;
        MINUTES_AND_DIFF_ENCODING minuts_diff_enc3_r;


        DEBUG_VAL_ITU(minuts_diff_enc)
        DEBUG_VAL_ITU_TREAD(minuts_diff_enc_r);
        DEBUG_VAL_ITU(minuts_diff_enc1)
        DEBUG_VAL_ITU_TREAD(minuts_diff_enc1_r);
        DEBUG_VAL_ITU(minuts_diff_enc2)
        DEBUG_VAL_ITU_TREAD(minuts_diff_enc2_r);
        DEBUG_VAL_ITU(minuts_diff_enc3)
        DEBUG_VAL_ITU_TREAD(minuts_diff_enc3_r);
        
        
        
        
        
        TIME_OF_DAY_ENCODING time_of_day_enc (3, 25, 43);
        TIME_OF_DAY_ENCODING time_of_day_enc1 = std::string("041256");
        TIME_OF_DAY_ENCODING time_of_day_enc2 = "210534";
        TIME_OF_DAY_ENCODING time_of_day_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        TIME_OF_DAY_ENCODING time_of_day_enc_r;
        TIME_OF_DAY_ENCODING time_of_day_enc1_r;
        TIME_OF_DAY_ENCODING time_of_day_enc2_r;
        TIME_OF_DAY_ENCODING time_of_day_enc3_r;


        DEBUG_VAL_ITU(time_of_day_enc)
        DEBUG_VAL_ITU_TREAD(time_of_day_enc_r);
        DEBUG_VAL_ITU(time_of_day_enc1)
        DEBUG_VAL_ITU_TREAD(time_of_day_enc1_r);
        DEBUG_VAL_ITU(time_of_day_enc2)
        DEBUG_VAL_ITU_TREAD(time_of_day_enc2_r);
        DEBUG_VAL_ITU(time_of_day_enc3)
        DEBUG_VAL_ITU_TREAD(time_of_day_enc3_r);

        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc(3, 45, 10);
        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc1 = std::string("044534");
        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc2 = "215512";
        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc_r;
        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc1_r;
        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc2_r;
        TIME_OF_DAY_UTC_ENCODING time_of_day_utc_enc3_r;


        DEBUG_VAL_ITU(time_of_day_utc_enc)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_enc_r);
        DEBUG_VAL_ITU(time_of_day_utc_enc1)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_enc1_r);
        DEBUG_VAL_ITU(time_of_day_utc_enc2)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_enc2_r);
        DEBUG_VAL_ITU(time_of_day_utc_enc3)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_enc3_r);

        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc (3, 45, 05);
        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc1 = std::string("045620+0420");
        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc2 = "211245-0330";
        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc_r;
        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc1_r;
        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc2_r;
        TIME_OF_DAY_AND_DIFF_ENCODING time_of_day_diff_enc3_r;


        DEBUG_VAL_ITU(time_of_day_diff_enc)
        DEBUG_VAL_ITU_TREAD(time_of_day_diff_enc_r);
        DEBUG_VAL_ITU(time_of_day_diff_enc1)
        DEBUG_VAL_ITU_TREAD(time_of_day_diff_enc1_r);
        DEBUG_VAL_ITU(time_of_day_diff_enc2)
        DEBUG_VAL_ITU_TREAD(time_of_day_diff_enc2_r);
        DEBUG_VAL_ITU(time_of_day_diff_enc3)
        DEBUG_VAL_ITU_TREAD(time_of_day_diff_enc3_r)   
                
        typedef HOURS_AND_FRACTION_ENCODING<4> HOURS_AND_FRACTION;
        
        HOURS_AND_FRACTION hours_and_fract_enc (3,3450);
        HOURS_AND_FRACTION hours_and_fract_enc1 = std::string("08,45");
        HOURS_AND_FRACTION hours_and_fract_enc2 = "23,6";
        HOURS_AND_FRACTION hours_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        HOURS_AND_FRACTION hours_and_fract_enc_r;
        HOURS_AND_FRACTION hours_and_fract_enc1_r;
        HOURS_AND_FRACTION hours_and_fract_enc2_r;
        HOURS_AND_FRACTION hours_and_fract_enc3_r;


        DEBUG_VAL_ITU(hours_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(hours_and_fract_enc_r);
        DEBUG_VAL_ITU(hours_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(hours_and_fract_enc1_r);
        DEBUG_VAL_ITU(hours_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(hours_and_fract_enc2_r);
        DEBUG_VAL_ITU(hours_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(hours_and_fract_enc3_r);
        
        typedef HOURS_UTC_AND_FRACTION_ENCODING<4> HOURS_UTC_AND_FRACTION;
        
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc (3,3450);
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc1 = std::string("08,45Z");
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc2 = "23,6Z";
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc_r;
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc1_r;
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc2_r;
        HOURS_UTC_AND_FRACTION hours_utc_and_fract_enc3_r;


        DEBUG_VAL_ITU(hours_utc_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(hours_utc_and_fract_enc_r);
        DEBUG_VAL_ITU(hours_utc_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(hours_utc_and_fract_enc1_r);
        DEBUG_VAL_ITU(hours_utc_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(hours_utc_and_fract_enc2_r);
        DEBUG_VAL_ITU(hours_utc_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(hours_utc_and_fract_enc3_r);        
        
        typedef HOURS_AND_DIFF_AND_FRACTION_ENCODING<4> HOURS_AND_DIFF_AND_FRACTION;
        
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc (3,3450,"+05");
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc1 = std::string("08,45+05:30");
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc2 = "23,68+04:00";
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc_r;
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc1_r;
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc2_r;
        HOURS_AND_DIFF_AND_FRACTION hours_d_and_fract_enc3_r;


        DEBUG_VAL_ITU(hours_d_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(hours_d_and_fract_enc_r);
        DEBUG_VAL_ITU(hours_d_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(hours_d_and_fract_enc1_r);
        DEBUG_VAL_ITU(hours_d_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(hours_d_and_fract_enc2_r);
        DEBUG_VAL_ITU(hours_d_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(hours_d_and_fract_enc3_r);             
                
          typedef MINUTES_AND_FRACTION_ENCODING<4> MINUTES_AND_FRACTION;
        
        MINUTES_AND_FRACTION minutes_and_fract_enc (3,30,3450);
        MINUTES_AND_FRACTION minutes_and_fract_enc1 = std::string("08:20,45");
        MINUTES_AND_FRACTION minutes_and_fract_enc2 = "23:59,6";
        MINUTES_AND_FRACTION minutes_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        MINUTES_AND_FRACTION minutes_and_fract_enc_r;
        MINUTES_AND_FRACTION minutes_and_fract_enc1_r;
        MINUTES_AND_FRACTION minutes_and_fract_enc2_r;
        MINUTES_AND_FRACTION minutes_and_fract_enc3_r;


        DEBUG_VAL_ITU(minutes_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(minutes_and_fract_enc_r);
        DEBUG_VAL_ITU(minutes_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(minutes_and_fract_enc1_r);
        DEBUG_VAL_ITU(minutes_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(minutes_and_fract_enc2_r);
        DEBUG_VAL_ITU(minutes_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(minutes_and_fract_enc3_r);
        
        typedef MINUTES_UTC_AND_FRACTION_ENCODING<4> MINUTES_UTC_AND_FRACTION;
        
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc (3,40,3450);
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc1 = std::string("08:45,45Z");
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc2 = "23:46,6Z";
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc_r;
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc1_r;
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc2_r;
        MINUTES_UTC_AND_FRACTION minutes_utc_and_fract_enc3_r;


        DEBUG_VAL_ITU(minutes_utc_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(minutes_utc_and_fract_enc_r);
        DEBUG_VAL_ITU(minutes_utc_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(minutes_utc_and_fract_enc1_r);
        DEBUG_VAL_ITU(minutes_utc_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(minutes_utc_and_fract_enc2_r);
        DEBUG_VAL_ITU(minutes_utc_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(minutes_utc_and_fract_enc3_r);        
        
        typedef MINUTES_AND_DIFF_AND_FRACTION_ENCODING<4> MINUTES_AND_DIFF_AND_FRACTION;
        
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc (3, 45 ,3450,"+05");
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc1 = std::string("08:01,45+05:30");
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc2 = "23:50,68+04:00";
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc_r;
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc1_r;
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc2_r;
        MINUTES_AND_DIFF_AND_FRACTION minutes_d_and_fract_enc3_r;


        DEBUG_VAL_ITU(minutes_d_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(minutes_d_and_fract_enc_r);
        DEBUG_VAL_ITU(minutes_d_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(minutes_d_and_fract_enc1_r);
        DEBUG_VAL_ITU(minutes_d_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(minutes_d_and_fract_enc2_r);
        DEBUG_VAL_ITU(minutes_d_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(minutes_d_and_fract_enc3_r);
        
        
        
        
         typedef TIME_OF_DAY_AND_FRACTION_ENCODING<4> TIME_OF_DAY_AND_FRACTION;
        
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc (3,30,20, 3450);
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc1 = std::string("08:20:46,45");
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc2 = "23:59:12,6";
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc_r;
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc1_r;
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc2_r;
        TIME_OF_DAY_AND_FRACTION time_of_day_and_fract_enc3_r;


        DEBUG_VAL_ITU(time_of_day_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(time_of_day_and_fract_enc_r);
        DEBUG_VAL_ITU(time_of_day_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(time_of_day_and_fract_enc1_r);
        DEBUG_VAL_ITU(time_of_day_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(time_of_day_and_fract_enc2_r);
        DEBUG_VAL_ITU(time_of_day_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(time_of_day_and_fract_enc3_r);
        
        typedef TIME_OF_DAY_UTC_AND_FRACTION_ENCODING<4> TIME_OF_DAY_UTC_AND_FRACTION;
        
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc (3,40,56, 3450);
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc1 = std::string("08:45:44,45Z");
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc2 = "23:46:23,6Z";
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc_r;
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc1_r;
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc2_r;
        TIME_OF_DAY_UTC_AND_FRACTION time_of_day_utc_and_fract_enc3_r;


        DEBUG_VAL_ITU(time_of_day_utc_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_and_fract_enc_r);
        DEBUG_VAL_ITU(time_of_day_utc_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_and_fract_enc1_r);
        DEBUG_VAL_ITU(time_of_day_utc_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_and_fract_enc2_r);
        DEBUG_VAL_ITU(time_of_day_utc_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(time_of_day_utc_and_fract_enc3_r);        
        
        typedef TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING<4> TIME_OF_DAY_AND_DIFF_AND_FRACTION;
        
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc (3, 45, 44 ,3450,"+05");
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc1 = std::string("08:01:44,45+05:30");
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc2 = "23:50:45,68+04:00";
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc3 = boost::asn1::base_time_duration(4, 23, 40);

        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc_r;
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc1_r;
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc2_r;
        TIME_OF_DAY_AND_DIFF_AND_FRACTION time_of_day_d_and_fract_enc3_r;


        DEBUG_VAL_ITU(time_of_day_d_and_fract_enc)
        DEBUG_VAL_ITU_TREAD(time_of_day_d_and_fract_enc_r);
        DEBUG_VAL_ITU(time_of_day_d_and_fract_enc1)
        DEBUG_VAL_ITU_TREAD(time_of_day_d_and_fract_enc1_r);
        DEBUG_VAL_ITU(time_of_day_d_and_fract_enc2)
        DEBUG_VAL_ITU_TREAD(time_of_day_d_and_fract_enc2_r);
        DEBUG_VAL_ITU(time_of_day_d_and_fract_enc3)
        DEBUG_VAL_ITU_TREAD(time_of_day_d_and_fract_enc3_r);        
        
        typedef DATE_TIME_ENCODING<ANY_DATE_ENCODING<4>, TIME_OF_DAY_ENCODING> DATE_TIME_ENC;
        
        DATE_TIME_ENC date_time_enc_1 ="2015-08-05T19:30:33";
        DATE_TIME_ENC date_time_enc_1_r;
        
        DEBUG_VAL_ITU(date_time_enc_1)
        DEBUG_VAL_ITU_READ(date_time_enc_1_r);    
        
        
        DURATION_INTERVAL_ENCODING durat_enc (3, 6);
        DURATION_INTERVAL_ENCODING durat_enc1 = std::string("P1Y2M15DT12H30M0S");
        DURATION_INTERVAL_ENCODING durat_enc2 = "P1Y2M15DT12H30M0S";
        DURATION_INTERVAL_ENCODING durat_enc3 = "P23W";

        DURATION_INTERVAL_ENCODING durat_enc_r;
        DURATION_INTERVAL_ENCODING durat_enc1_r;
        DURATION_INTERVAL_ENCODING durat_enc2_r;
        DURATION_INTERVAL_ENCODING durat_enc3_r;


        DEBUG_VAL_ITU(durat_enc)
        DEBUG_VAL_ITU_DREAD(durat_enc_r);
        DEBUG_VAL_ITU(durat_enc1)
        DEBUG_VAL_ITU_DREAD(durat_enc1_r);
        DEBUG_VAL_ITU(durat_enc2)
        DEBUG_VAL_ITU_DREAD(durat_enc2_r);
        DEBUG_VAL_ITU(durat_enc3)
        DEBUG_VAL_ITU_DREAD(durat_enc3_r);        
        
        /*std::cout << boost::asn1::time_detail::minute_fraction_HF(499,3)  << std::endl;
        std::cout << boost::asn1::time_detail::second_fraction_HF(2, 2)  << std::endl;     
        std::cout << boost::asn1::time_detail::microsecond_fraction_HF(9999, 4 )  << std::endl;        
        std::cout << boost::asn1::time_detail::microsecond_fraction_HF(99999, 5 )  << std::endl;         
        std::cout << boost::asn1::time_detail::microsecond_fraction_HF(999999, 6 )  << std::endl;        
        std::cout << boost::asn1::time_detail::microsecond_fraction_HF(9999999, 7 )  << std::endl;         
        std::cout << boost::asn1::time_detail::microsecond_fraction_HF(99999999, 8 )  << std::endl;        
        std::cout << boost::asn1::time_detail::microsecond_fraction_HF(999999999, 9 )  << std::endl;       
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HF(9999, 4 )  << std::endl;        
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HF(99999, 5 )  << std::endl;         
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HF(999999, 6 )  << std::endl;        
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HF(9999999, 7 )  << std::endl;         
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HF(99999999, 8 )  << std::endl;        
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HF(999999999, 9 )  << std::endl; 
        
        std::cout << boost::asn1::time_detail::second_fraction_HMF(54, 2)  << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMF(1, 4) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMF(1, 5) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMF(1, 6) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMF(1, 7) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMF(1, 8) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMF(1, 9) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMF(9999, 4) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMF(99999, 5) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMF(999999, 6) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMF(9999999, 7) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMF(99999999, 8) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMF(999999999, 9) << std::endl; 
        
        
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 1) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1,2) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 3) << std::endl;        
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 4) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 5) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 6) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 7) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 8) << std::endl;
        std::cout << boost::asn1::time_detail::microsecond_fraction_HMSF(1, 9) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(9, 1) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(99, 2) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(999, 3) << std::endl;        
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(9999, 4) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(99999, 5) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(999999, 6) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(9999999, 7) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(99999999, 8) << std::endl;
        std::cout << boost::asn1::time_detail::nanosecond_fraction_HMSF(999999999, 9) << std::endl;
                
        //std::cout << boost::asn1::time_detail::normalize_time_str("\"yy-yy-y:y")  << std::endl;
        
        std::cout << "tst: =" << boost::asn1::time_detail::get_numstr_marker(std::string("P8887Y655M-42D+241H76W66S"), 'Y')  << std::endl;
        std::cout << "tst: =" << boost::asn1::time_detail::get_numstr_marker(std::string("P8887Y655M-42D+241H76W66S"), 'M')  << std::endl;        
         std::cout << "tst: =" << boost::asn1::time_detail::get_numstr_marker(std::string("P8887Y655M-42D+241H76W66S"), 'D')  << std::endl;        
         std::cout << "tst: =" << boost::asn1::time_detail::get_numstr_marker(std::string("P8887Y655M-42D+241H76W66S"), 'H')  << std::endl;           
         std::cout << "tst: =" << boost::asn1::time_detail::get_numstr_marker(std::string("TP8887Y655M-42D+241H76W66S"), 'P')  << std::endl;             
         std::cout << "tst: =" << boost::asn1::time_detail::get_numstr_marker(std::string("P8887Y655M-42D+241H76W66S"), 'P')  << std::endl;   */         
    }

}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1B */
