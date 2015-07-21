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

#define DEBUG_VAL_ITU(a)  std::cout << #a " = "  <<  a  << "    ===> ";   tsstr << a;

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
        DEBUG_VAL_ITU(nl1)
        DEBUG_VAL_ITU(nl2)
        DEBUG_VAL_ITU(oi1)
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
        
        CENTURY_ENCODING cetn_enc=19;
        CENTURY_ENCODING cetn_enc1=std::string("16");
        CENTURY_ENCODING cetn_enc2="21";        
        CENTURY_ENCODING cetn_enc3=boost::asn1::base_date_time(boost::asn1::base_date_time::date_type(1812, 1, 12));              
        ANY_CENTURY_ENCODING acetn_enc(19);        
        
        DEBUG_VAL_ITU(cetn_enc)      
        DEBUG_VAL_ITU(cetn_enc1)  
        std::cout << cetn_enc1.as_datetime() << std::endl;
        DEBUG_VAL_ITU(cetn_enc2)                  
        DEBUG_VAL_ITU(cetn_enc3)                       
        DEBUG_VAL_ITU(acetn_enc)                 

    }

}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1B */
