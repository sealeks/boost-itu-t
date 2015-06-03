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


    typedef visible_string NameString; //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   
    typedef integer_type EmployeeNumber;
    ITU_T_PREFIXED_DECLARE(EmployeeNumber, ITU_T_ARRAY(prefixed_type(2, APPLICATION_CLASS)), false); //  initial =implicit  //   Ic(  [ 0  ...   9999 ]   ...ext...) 
    typedef visible_string Date;
    ITU_T_PREFIXED_DECLARE(Date, ITU_T_ARRAY(prefixed_type(3, APPLICATION_CLASS)), false); //  initial =implicit  //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   

    ITU_T_PREFIXED_DECLARE(PersonnelRecord, ITU_T_ARRAY(prefixed_type(0, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(PersonnelRecord_s, ITU_T_ARRAY(prefixed_type(0, APPLICATION_CLASS)), false); //  initial =implicit
    ITU_T_PREFIXED_DECLARE(Name, ITU_T_ARRAY(prefixed_type(1, APPLICATION_CLASS)), false); //  initial =implicit


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

        PersonnelRecord(shared_ptr< Name> arg__name,
                shared_ptr< visible_string> arg__title,
                shared_ptr< EmployeeNumber> arg__number,
                shared_ptr< Date> arg__dateOfHire,
                shared_ptr< Name> arg__nameOfSpouse,
                shared_ptr< Children_type> arg__children);

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

        PersonnelRecord_s(shared_ptr< Name> arg__name,
                shared_ptr< visible_string> arg__title,
                shared_ptr< EmployeeNumber> arg__number,
                shared_ptr< Date> arg__dateOfHire,
                shared_ptr< Name> arg__nameOfSpouse,
                shared_ptr< Children_type> arg__children);

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

        ChildInformation(shared_ptr< Name> arg__name,
                shared_ptr< Date> arg__dateOfBirth,
                shared_ptr< enumerated> arg__sex = shared_ptr< enumerated>());

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

        ITU_T_HOLDERH_DECL(givenName, NameString); //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   
        ITU_T_HOLDERH_DECL(initial, NameString); //    Sc (  [ 1 ]     //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   
        ITU_T_HOLDERH_DECL(familyName, NameString); //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   

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

        Ax(shared_ptr< uint8_t> arg__a,
                shared_ptr< bool> arg__b,
                shared_ptr< C_type> arg__c,
                shared_ptr< numeric_string> arg__g = shared_ptr< numeric_string>(),
                shared_ptr< bool> arg__h = shared_ptr< bool>(),
                shared_ptr< bmp_string> arg__i = shared_ptr< bmp_string>(),
                shared_ptr< printable_string> arg__j = shared_ptr< printable_string>());

        ITU_T_HOLDERH_DECL(a, uint8_t); //   Ic(  [ 250  ...   253 ]   
        ITU_T_HOLDERH_DECL(b, bool);
        ITU_T_HOLDERH_DECL(c, C_type);
        ITU_T_OPTIONAL_DECL(g, numeric_string); //    Sc (  [ 3 ]   
        ITU_T_OPTIONAL_DECL(h, bool);
        ITU_T_OPTIONAL_DECL(i, bmp_string);
        ITU_T_OPTIONAL_DECL(j, printable_string);

        ITU_T_ARCHIVE_FUNC;
    };

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
