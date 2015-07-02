#ifndef ___TEST1B
#define ___TEST1B

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1b {

    ITU_T_USE_UNIVESAL_DECL;


    typedef bool BooleanType;
    typedef bool BI;
    typedef uint8_t AI1; //   Ic(  [ 0  ...   253 ]   
    typedef uint32_t AI2; //   Ic(  [ 0  ...   67000 ]   
    typedef integer_type AI3; //   Ic(  [ 0  ...   64 ]   ...ext...) 
    typedef integer_type AI4; //   Ic(  [ 64  ...    ]   
    typedef bit_string BS1;
    typedef null_type NullType;
    typedef double RLT;
    typedef enumerated ENU1;
    typedef enumerated ENU2;
    typedef enumerated ENU3;
    typedef enumerated ENU4;

    const BooleanType b1 = true;

    const BooleanType b2 = false;

    const integer_type i0 = 3;

    const AI1 i1 = 3;

    const AI1 i1_1 = 120;

    const AI2 i2 = 3;

    const AI2 i2_1 = 120;

    const AI2 i2_2 = 66000;

    const AI3 i3 = 3;

    const AI3 i3_1 = 120;

    const AI3 i3_2 = 66000;

    const AI4 i4 = 64;

    const AI4 i4_1 = 120;

    const AI4 i4_2 = 66000;

    ITU_T_BITS(bs0, ITU_T_VARRAY('\xA0'), 5);

    ITU_T_BITS(bs1, ITU_T_VARRAY('\xF5', '\x66'), 0);

    ITU_T_BITS(bs2, ITU_T_VARRAY('\x57', '\x70'), 4);

    const BS1 bs3 = bit_string(true, 1);

    const BS1 bs4 = bit_string(true, 2);

    const BS1 bs5 = bit_string(bit_string(true, 1) | bit_string(true, 2) | bit_string(true, 5));

    ITU_T_OCTETS(os0, ITU_T_VARRAY('\x20'));

    ITU_T_OCTETS(os1, ITU_T_VARRAY('\xF5', '\x66'));

    ITU_T_OCTETS(os2, ITU_T_VARRAY('\x31', '\x39', '\x78', '\x45', '\x67', '\x89', '\x34', '\x31', '\x39', '\x78', '\x45', '\x67', '\x89', '\x34'));

    const NullType nl1 = null_type();

    const null_type nl2 = null_type();

    ITU_T_OID(oi1, ITU_T_VARRAY(1, 0, 2, 3, 4, 5));

    ITU_T_OID(oi2, ITU_T_VARRAY(1, 2, 29, 56, 32));

    ITU_T_OID(oi3, ITU_T_VARRAY(1, 0, 2, 3, 4, 500));

    const object_descriptor od1 = "abcdef";

    const object_descriptor od2 = "123456abcdefabcdef";

    const object_descriptor od3 = "123456abcdef123456abcdefabcdefB";

    const double rl1 = 8.5600000000000005;

    const double rl2 = -80.560000000000002;

    const double rl3 = std::numeric_limits<double>::infinity();

    const double rl4 = -std::numeric_limits<double>::infinity();

    const double rl5 = std::numeric_limits<double>::quiet_NaN();

    const RLT rl6 = -80.561000000000007;

    const RLT rl7 = std::numeric_limits<double>::infinity();

    const ENU1 enu1 = 2;

    const ENU2 enu2 = 3;

    const ENU3 enu3 = 4;

    const ENU4 enu4 = 1;

    const utf8_string utf1 = "\xCA\xAB";

    const utf8_string utf2 = "\xCA\xAC\xCA\xAB\xCA\xAB";

    const utf8_string utf3 = "Yhqwre";

    ITU_T_RELOID(roi1, ITU_T_VARRAY(2, 3, 4, 5));

    ITU_T_RELOID(roi2, ITU_T_VARRAY(56, 32));

    ITU_T_RELOID(roi3, ITU_T_VARRAY(3, 4, 500));

    const numeric_string ns1 = "345";

    const numeric_string ns2 = "123456345345";

    const numeric_string ns3 = "1234563451234563453452";

    const printable_string ps1 = "pdfg456%^^345";

    const printable_string ps2 = "123456pdfg456%^^345pdfg456%^^345";

    const printable_string ps3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const t61_string tl1 = "pdfg456%^^345";

    const t61_string tl2 = "123456pdfg456%^^345pdfg456%^^345";

    const t61_string tl3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const t61_string tlx1 = "pdfg456%^^345";

    const t61_string tlx2 = "123456pdfg456%^^345pdfg456%^^345";

    const t61_string tlx3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const videotex_string vdx1 = "pdfg456%^^345";

    const videotex_string vdx2 = "123456pdfg456%^^345pdfg456%^^345";

    const videotex_string vdx3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const ia5_string ia1 = "\x30";

    const ia5_string ia2 = "A00r";

    const ia5_string ia3 = "1234560A00rb";

    const utctime ut1 = "8201021200";

    const utctime ut2 = "0101021200Z";

    const utctime ut3 = "0101020700-0500";

    const gentime gt1 = "19851106210627.3";

    const gentime gt2 = "19851106210627.3Z";

    const gentime gt3 = "198511062106.456";

    const graphic_string grph1 = "pdfg456%^^345";

    const graphic_string grph2 = "123456pdfg456%^^345pdfg456%^^345";

    const graphic_string grph3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const visible_string vs1 = "pdfg456%^^345";

    const visible_string vs2 = "123456pdfg456%^^345pdfg456%^^345";

    const visible_string vs3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const general_string genrl1 = "pdfg456%^^345";

    const general_string genrl2 = "123456pdfg456%^^345pdfg456%^^345";

    const general_string genrl3 = "123456pdfg456%^^345123456pdfg456%^^345pdfg456%^^345b";

    const universal_string unv1 = "\xCA\xAB";

    const universal_string unv2 = "\xCA\xAC\xCA\xAB\xCA\xAB";

    const universal_string unv3 = "\xCA\xB3\xCA\xAB\xCA\xAC\xCA\xAB\xCA\xAB\xD8\x82";

    const bmp_string bmp1 = "\xCA\xAB";

    const bmp_string bmp2 = "\xCA\xAC\xCA\xAB\xCA\xAB";

    const bmp_string bmp3 = "\xCA\xB3\xCA\xAB\xCA\xAC\xCA\xAB\xCA\xAB\xD8\x82";

    const oid_iri_type oidir1 = "\xCA\xAB";

    const oid_iri_type oidir2 = "\xCA\xAC\xCA\xAB\xCA\xAB";

    const oid_iri_type oidir3 = "jkjkdjjfhjdjhfjhdjfdjj/jhjhfjhdskhjh/";

    const reloid_iri_type roidir1 = "\xCA\xAB";

    const reloid_iri_type roidir2 = "\xCA\xAC\xCA\xAB\xCA\xAB";

    const reloid_iri_type roidir3 = "jkjkdjjfhjdjhfjhdjfdjj/jhjhfjhdskhjh/";


}


namespace Test1b {

    const BS1 bS1_a = bit_string(true, 1);
    const BS1 bS1_b = bit_string(true, 2);
    const BS1 bS1_c = bit_string(true, 3);
    const BS1 bS1_d = bit_string(true, 4);
    const BS1 bS1_e = bit_string(true, 5);

    const ENU1 eNU1_a = 0;
    const ENU1 eNU1_b = 1;
    const ENU1 eNU1_c = 2;

    const ENU2 eNU2_a = 1;
    const ENU2 eNU2_b = 2;
    const ENU2 eNU2_c = 0;
    const ENU2 eNU2_d = 3;

    const ENU3 eNU3_a = 0;
    const ENU3 eNU3_b = 1;
    const ENU3 eNU3_c = 3;
    const ENU3 eNU3_d = 4;

    const ENU4 eNU4_a = 0;
    const ENU4 eNU4_z = 25;
    const ENU4 eNU4_d = 1;

    // struct var



    // std::cout methods

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1B */
