#ifndef ___TEST1
#define ___TEST1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    ITU_T_USE_UNIVESAL_DECL;


    struct PersonnelRecord;
    struct PersonnelRecord_s;
    struct ChildInformation;
    struct ChildInformation_s;
    struct Name;
    struct Ax;


    typedef octet_string OctetsStr;
    typedef integer_type AI;
    typedef bool BI;
    typedef double RI;
    typedef visible_string NameString; //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ -  ...   . ]   [ A  ...   Z ]   [ a  ...   z ]   
    typedef integer_type EmployeeNumber;
    ITU_T_PREFIXED_DECLARE(EmployeeNumber, ITU_T_ARRAY(prefixed_type(2, APPLICATION_CLASS)), false); //  initial =implicit  //   Ic(  [ 0  ...   9999 ]   ...ext...) 
    typedef visible_string Date;
    ITU_T_PREFIXED_DECLARE(Date, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS)), false); //  initial =implicit  //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   
    typedef sequence_of< visible_string > Seq; //    Sc (  [ 2 ]   ...ext...)   //  struct of ->  

    ITU_T_IMPLICIT_TYPEDEF(PersonnelRecord__impl_helper, PersonnelRecord, 0, APPLICATION_CLASS);
    ITU_T_PREFIXED_DECLARE(PersonnelRecord, ITU_T_ARRAY(prefixed_type(0, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_IMPLICIT_TYPEDEF(PersonnelRecord_s__impl_helper, PersonnelRecord_s, 0, APPLICATION_CLASS);
    ITU_T_PREFIXED_DECLARE(PersonnelRecord_s, ITU_T_ARRAY(prefixed_type(0, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_IMPLICIT_TYPEDEF(Name__impl_helper, Name, 1, APPLICATION_CLASS);
    ITU_T_PREFIXED_DECLARE(Name, ITU_T_ARRAY(prefixed_type(1, APPLICATION_CLASS)), false); //  initial =implicit

    ITU_T_OCTETS(otst1, ITU_T_VARRAY('\x31', '\x39'));

    ITU_T_TP_OCTETS(OctetsStr, otst2, ITU_T_VARRAY('\x31', '\x39', '\x78', '\x45', '\x67', '\x89', '\x34'));

    ITU_T_BITS(btst1, ITU_T_VARRAY('\xF5', '\x66'), 0);

    ITU_T_BITS(btst2, ITU_T_VARRAY('\x57', '\x7'), 4);

    ITU_T_OID(acse_as_id, ITU_T_VARRAY(2, 2, 1, 0, 1));

    ITU_T_OID(aCSE_id, ITU_T_VARRAY(2, 2, 3, 1, 1));

    const printable_string pstr1 = "abvgd";

    const printable_string pstr2 = "abvgdfffJ";

    const ia5_string nul = "\x0";

    const ia5_string soh = "\x1";

    const ia5_string stx = "\x2";

    const ia5_string etx = "\x3";

    const ia5_string eot = "\x4";

    const ia5_string enq = "\x5";

    const ia5_string ack = "\x6";

    const ia5_string bel = "\x7";

    const ia5_string bs = "\x8";

    const ia5_string istr1 = "abvgdDC";

    const AI ai = 3;

    const BI bi = true;

    const RI ri = 9;


}


namespace Test1 {


    // set  PersonnelRecord

    struct PersonnelRecord {

        typedef sequence_of< ChildInformation > Children_type; //    Sc (  [ 2 ]   ...ext...) 


        PersonnelRecord();

        PersonnelRecord(const Name& arg__name,
                const visible_string& arg__title,
                const EmployeeNumber& arg__number,
                const Date& arg__dateOfHire,
                const Name& arg__nameOfSpouse);

        PersonnelRecord(ITU_T_SHARED(Name) arg__name,
                ITU_T_SHARED(visible_string) arg__title,
                ITU_T_SHARED(EmployeeNumber) arg__number,
                ITU_T_SHARED(Date) arg__dateOfHire,
                ITU_T_SHARED(Name) arg__nameOfSpouse,
                ITU_T_SHARED(Children_type) arg__children);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(title, visible_string);
        ITU_T_HOLDERH_DECL(number, EmployeeNumber); //   Ic(  [ 0  ...   9999 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(dateOfHire, Date); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   
        ITU_T_HOLDERH_DECL(nameOfSpouse, Name);
        ITU_T_OPTIONAL_DECL(children, Children_type); //    Sc (  [ 2 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // set  PersonnelRecord-s

    struct PersonnelRecord_s {

        typedef sequence_of< ChildInformation_s > Children_type; //    Sc (  [ 2 ]   ...ext...) 


        PersonnelRecord_s();

        PersonnelRecord_s(const Name& arg__name,
                const visible_string& arg__title,
                const EmployeeNumber& arg__number,
                const Date& arg__dateOfHire,
                const Name& arg__nameOfSpouse);

        PersonnelRecord_s(ITU_T_SHARED(Name) arg__name,
                ITU_T_SHARED(visible_string) arg__title,
                ITU_T_SHARED(EmployeeNumber) arg__number,
                ITU_T_SHARED(Date) arg__dateOfHire,
                ITU_T_SHARED(Name) arg__nameOfSpouse,
                ITU_T_SHARED(Children_type) arg__children);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(title, visible_string);
        ITU_T_HOLDERH_DECL(number, EmployeeNumber); //   Ic(  [ 0  ...   9999 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(dateOfHire, Date); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   
        ITU_T_HOLDERH_DECL(nameOfSpouse, Name);
        ITU_T_OPTIONAL_DECL(children, Children_type); //    Sc (  [ 2 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // set  ChildInformation

    struct ChildInformation {

        static const enumerated sex_male;
        static const enumerated sex_female;
        static const enumerated sex_unknown;


        ChildInformation();

        ChildInformation(const Name& arg__name,
                const Date& arg__dateOfBirth);

        ChildInformation(ITU_T_SHARED(Name) arg__name,
                ITU_T_SHARED(Date) arg__dateOfBirth,
                ITU_T_SHARED(enumerated) arg__sex);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(dateOfBirth, Date); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   
        ITU_T_OPTIONAL_DECL(sex, enumerated);

        ITU_T_ARCHIVE_FUNC;
    };

    // set  ChildInformation-s

    struct ChildInformation_s {

        ChildInformation_s();

        ChildInformation_s(const Name& arg__name,
                const Date& arg__dateOfBirth);

        ChildInformation_s(ITU_T_SHARED(Name) arg__name,
                ITU_T_SHARED(Date) arg__dateOfBirth);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(dateOfBirth, Date); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Name

    struct Name {

        Name();

        Name(const NameString& arg__givenName,
                const NameString& arg__initial,
                const NameString& arg__familyName);

        Name(ITU_T_SHARED(NameString) arg__givenName,
                ITU_T_SHARED(NameString) arg__initial,
                ITU_T_SHARED(NameString) arg__familyName);

        ITU_T_HOLDERH_DECL(givenName, NameString); //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ -  ...   . ]   [ A  ...   Z ]   [ a  ...   z ]   
        ITU_T_HOLDERH_DECL(initial, NameString); //    Sc (  [ 1 ]     //    c8C (  [ -  ...   . ]   [ A  ...   Z ]   [ a  ...   z ]   
        ITU_T_HOLDERH_DECL(familyName, NameString); //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ -  ...   . ]   [ A  ...   Z ]   [ a  ...   z ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Ax

    struct Ax {

        struct C_type;

        enum C_type_enum {

            C_type_null = 0,
            C_type_d,
            C_type_e,
            C_type_f,
        };

        struct C_type : public ITU_T_CHOICE(C_type_enum) {


            ITU_T_CHOICE_CTORS(C_type);

            ITU_T_CHOICES_DECL(d, integer_type, C_type_d); // primitive
            ITU_T_CHOICES_DECL(e, bool, C_type_e); // primitive
            ITU_T_CHOICES_DECL(f, ia5_string, C_type_f); // primitive

            ITU_T_ARCHIVE_FUNC;
        };


        Ax();

        Ax(const uint8_t& arg__a,
                const bool& arg__b,
                const C_type& arg__c);

        Ax(ITU_T_SHARED(uint8_t) arg__a,
                ITU_T_SHARED(bool) arg__b,
                ITU_T_SHARED(C_type) arg__c,
                ITU_T_SHARED(numeric_string) arg__g,
                ITU_T_SHARED(bool) arg__h,
                ITU_T_SHARED(bmp_string) arg__i,
                ITU_T_SHARED(printable_string) arg__j);

        ITU_T_HOLDERH_DECL(a, uint8_t); //   Ic(  [ 250  ...   253 ]   
        ITU_T_HOLDERH_DECL(b, bool);
        ITU_T_HOLDERH_DECL(c, C_type);
        ITU_T_OPTIONAL_DECL(g, numeric_string); //    Sc (  [ 3 ]   
        ITU_T_OPTIONAL_DECL(h, bool);
        ITU_T_OPTIONAL_DECL(i, bmp_string);
        ITU_T_OPTIONAL_DECL(j, printable_string);

        ITU_T_ARCHIVE_FUNC;
    };

    // struct var

    static PersonnelRecord __valT() {
        static PersonnelRecord valT = PersonnelRecord(ITU_T_MAKE(Name)(ITU_T_MAKE(NameString)("John"),
                ITU_T_MAKE(NameString)("P"),
                ITU_T_MAKE(NameString)("Smith")),
                ITU_T_MAKE(visible_string)("Director"),
                ITU_T_MAKE(EmployeeNumber)(51),
                ITU_T_MAKE(Date)("19710917"),
                ITU_T_MAKE(Name)(ITU_T_MAKE(NameString)("Mary"),
                ITU_T_MAKE(NameString)("T"),
                ITU_T_MAKE(NameString)("Smith")),
                ITU_T_MAKE(PersonnelRecord::Children_type)(PersonnelRecord::Children_type()));

        valT.children()->push_back(ChildInformation(ITU_T_MAKE(Name)(ITU_T_MAKE(NameString)("Ralph"),
                ITU_T_MAKE(NameString)("T"),
                ITU_T_MAKE(NameString)("Smith")),
                ITU_T_MAKE(Date)("19571111"),
                ITU_T_SHARED(enumerated)()));
        valT.children()->push_back(ChildInformation(ITU_T_MAKE(Name)(ITU_T_MAKE(NameString)("Susan"),
                ITU_T_MAKE(NameString)("B"),
                ITU_T_MAKE(NameString)("Jones")),
                ITU_T_MAKE(Date)("19590717"),
                ITU_T_MAKE(enumerated)(2)));
        return valT;
    };

    static PersonnelRecord valT = __valT();

    static Ax __valAx() {
        static Ax valAx = Ax(ITU_T_MAKE(uint8_t)(253),
                ITU_T_MAKE(bool)(true),
                ITU_T_MAKE(Ax::C_type)(ITU_T_MAKE(bool)(true), Ax::C_type_e),
                ITU_T_MAKE(numeric_string)("123"),
                ITU_T_MAKE(bool)(true),
                ITU_T_SHARED(bmp_string)(),
                ITU_T_SHARED(printable_string)());

        return valAx;
    };

    static Ax valAx = __valAx();

    static Seq __seqS() {
        static Seq seqS = Seq();

        return seqS;
    };

    static Seq seqS = __seqS();


    // std::cout methods

    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord& vl);
    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord::Children_type& vl);
    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord_s& vl);
    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord_s::Children_type& vl);
    std::ostream& operator<<(std::ostream& stream, const ChildInformation& vl);
    std::ostream& operator<<(std::ostream& stream, const ChildInformation_s& vl);
    std::ostream& operator<<(std::ostream& stream, const Name& vl);
    std::ostream& operator<<(std::ostream& stream, const Ax& vl);
    std::ostream& operator<<(std::ostream& stream, const Ax::C_type& vl);

    ITU_T_ARCHIVE_X690_DECL(PersonnelRecord);
    ITU_T_ARCHIVE_X690_DECL(PersonnelRecord_s);
    ITU_T_ARCHIVE_X690_DECL(ChildInformation);
    ITU_T_ARCHIVE_X690_DECL(ChildInformation_s);
    ITU_T_ARCHIVE_X690_DECL(Name);
    ITU_T_ARCHIVE_X690_DECL(Ax);
    ITU_T_ARCHIVE_X690_DECL(Ax::C_type);

    ITU_T_ARCHIVE_X691_DECL(PersonnelRecord);
    ITU_T_ARCHIVE_X691_DECL(PersonnelRecord_s);
    ITU_T_ARCHIVE_X691_DECL(ChildInformation);
    ITU_T_ARCHIVE_X691_DECL(ChildInformation_s);
    ITU_T_ARCHIVE_X691_DECL(Name);
    ITU_T_ARCHIVE_X691_DECL(Ax);
    ITU_T_ARCHIVE_X691_DECL(Ax::C_type);

}

ITU_T_SET_REGESTRATE(Test1::PersonnelRecord)
ITU_T_SET_REGESTRATE(Test1::PersonnelRecord_s)
ITU_T_SET_REGESTRATE(Test1::ChildInformation)
ITU_T_SET_REGESTRATE(Test1::ChildInformation_s)

ITU_T_CHOICE_REGESTRATE(Test1::Ax::C_type)

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1 */
