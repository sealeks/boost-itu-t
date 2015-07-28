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
        CENTURY_ENCODING cetn_enc1=std::string("4");
        CENTURY_ENCODING cetn_enc2="21";        
        CENTURY_ENCODING cetn_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 1, 12));              
        ANY_CENTURY_ENCODING acetn_enc(19);        
        
        CENTURY_ENCODING cetn_enc_r;
        CENTURY_ENCODING cetn_enc1_r;
        CENTURY_ENCODING cetn_enc2_r;        
        CENTURY_ENCODING cetn_enc3_r;              
        ANY_CENTURY_ENCODING acetn_enc_r;             
        
        
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
        ANY_YEAR_ENCODING ayear_enc(1958);        
        
        YEAR_ENCODING year_enc_r;
        YEAR_ENCODING year_enc1_r;
        YEAR_ENCODING year_enc2_r;        
        YEAR_ENCODING year_enc3_r;              
        ANY_YEAR_ENCODING ayear_enc_r;             
        
        
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
        YEAR_MONTH_ENCODING year_month_enc1=std::string("200408");
        YEAR_MONTH_ENCODING year_month_enc2="201507";        
        YEAR_MONTH_ENCODING year_month_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_MONTH_ENCODING ayear_month_enc(1958, 7);        
        
        YEAR_MONTH_ENCODING year_month_enc_r;
        YEAR_MONTH_ENCODING year_month_enc1_r;
        YEAR_MONTH_ENCODING year_month_enc2_r;        
        YEAR_MONTH_ENCODING year_month_enc3_r;              
        ANY_YEAR_MONTH_ENCODING ayear_month_enc_r;             
        
        
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
        DATE_ENCODING date_enc1=std::string("20040830");
        DATE_ENCODING date_enc2="20150724";        
        DATE_ENCODING date_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_DATE_ENCODING adate_enc(1958, 7,6);        
        
        DATE_ENCODING date_enc_r;
        DATE_ENCODING date_enc1_r;
        DATE_ENCODING date_enc2_r;        
        DATE_ENCODING date_enc3_r;              
        ANY_DATE_ENCODING adate_enc_r;             
        
        
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
        YEAR_DAY_ENCODING year_day_enc1=std::string("2004085");
        YEAR_DAY_ENCODING year_day_enc2="2015186";        
        YEAR_DAY_ENCODING year_day_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_DAY_ENCODING ayear_day_enc(1958, 78);        
        
        YEAR_DAY_ENCODING year_day_enc_r;
        YEAR_DAY_ENCODING year_day_enc1_r;
        YEAR_DAY_ENCODING year_day_enc2_r;        
        YEAR_DAY_ENCODING year_day_enc3_r;              
        ANY_YEAR_DAY_ENCODING ayear_day_enc_r;             
        
        
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
        YEAR_WEEK_ENCODING year_week_enc1=std::string("2004W40");
        YEAR_WEEK_ENCODING year_week_enc2="2015W18";        
        YEAR_WEEK_ENCODING year_week_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_WEEK_ENCODING ayear_week_enc(1958, 43);        
        
        YEAR_WEEK_ENCODING year_week_enc_r;
        YEAR_WEEK_ENCODING year_week_enc1_r;
        YEAR_WEEK_ENCODING year_week_enc2_r;        
        YEAR_WEEK_ENCODING year_week_enc3_r;              
        ANY_YEAR_WEEK_ENCODING ayear_week_enc_r;             
        
        
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
        YEAR_WEEK_DAY_ENCODING year_week_day_enc1=std::string("2004W402");
        YEAR_WEEK_DAY_ENCODING year_week_day_enc2="2015W184";        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 2, 12));              
        ANY_YEAR_WEEK_DAY_ENCODING ayear_week_day_enc(1958, 43,5);        
        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc_r;
        YEAR_WEEK_DAY_ENCODING year_week_day_enc1_r;
        YEAR_WEEK_DAY_ENCODING year_week_day_enc2_r;        
        YEAR_WEEK_DAY_ENCODING year_week_day_enc3_r;              
        ANY_YEAR_WEEK_DAY_ENCODING ayear_week_day_enc_r;             
        
        
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
        
        
    }

}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1B */
