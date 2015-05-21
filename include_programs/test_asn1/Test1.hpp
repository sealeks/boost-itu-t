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


    struct PersonnelRecord_impl;
    struct ChildInformation;
    struct Name_impl;
    struct A;


    typedef visiblestring_type NameString; //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   
    ITU_T_IMPLICIT_TYPEDEF(EmployeeNumber, integer_type, 2, APPLICATION_CLASS); //   Ic(  [ 0  ...   9999 ]   ...ext...) 
    ITU_T_IMPLICIT_TYPEDEF(Date, visiblestring_type, 3, APPLICATION_CLASS); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   

    ITU_T_IMPLICIT_TYPEDEF(PersonnelRecord, PersonnelRecord_impl, 0, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(Name, Name_impl, 1, APPLICATION_CLASS);


}


namespace Test1 {


    // set  PersonnelRecord

    struct PersonnelRecord_impl {

        typedef std::vector< ChildInformation > Children_type; //    Sc (  [ 2 ]   ...ext...) 


        PersonnelRecord_impl();

        PersonnelRecord_impl(const Name& arg__name,
                const visiblestring_type& arg__title,
                const EmployeeNumber& arg__number,
                const Date& arg__dateOfHire,
                const Name& arg__nameOfSpouse);

        PersonnelRecord_impl(shared_ptr< Name> arg__name,
                shared_ptr< visiblestring_type> arg__title,
                shared_ptr< EmployeeNumber> arg__number,
                shared_ptr< Date> arg__dateOfHire,
                shared_ptr< Name> arg__nameOfSpouse,
                shared_ptr< Children_type> arg__children);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(title, visiblestring_type);
        ITU_T_HOLDERH_DECL(number, EmployeeNumber); //   Ic(  [ 0  ...   9999 ]   ...ext...) 
        ITU_T_HOLDERH_DECL(dateOfHire, Date); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   
        ITU_T_HOLDERH_DECL(nameOfSpouse, Name);
        ITU_T_OPTIONAL_DECL(children, Children_type); //    Sc (  [ 2 ]   ...ext...) 

        ITU_T_ARCHIVE_FUNC;
    };

    // set  ChildInformation

    struct ChildInformation {

        static const enumerated_type sex_male;
        static const enumerated_type sex_female;
        static const enumerated_type sex_unknown;


        ChildInformation();

        ChildInformation(const Name& arg__name,
                const Date& arg__dateOfBirth);

        ChildInformation(shared_ptr< Name> arg__name,
                shared_ptr< Date> arg__dateOfBirth,
                shared_ptr< enumerated_type> arg__sex = boost::shared_ptr< enumerated_type>());

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(dateOfBirth, Date); //    Sc (  [ 8 ]   ...ext...)   //    c8C (  [ 0  ...   9 ]   
        ITU_T_OPTIONAL_DECL(sex, enumerated_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Name

    struct Name_impl {

        Name_impl();

        Name_impl(const NameString& arg__givenName,
                const NameString& arg__initial,
                const NameString& arg__familyName);

        ITU_T_HOLDERH_DECL(givenName, NameString); //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   
        ITU_T_HOLDERH_DECL(initial, NameString); //    Sc (  [ 1 ]     //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   
        ITU_T_HOLDERH_DECL(familyName, NameString); //    Sc (  [ 1  ...   64 ]   ...ext...)   //    c8C (  [ - ]   [ A  ...   Z ]   [ a  ...   z ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence A

    struct A {

        A();

        A(const integer_type& arg__a);

        A(shared_ptr< integer_type> arg__a,
                shared_ptr< bool> arg__b = boost::shared_ptr< bool>(),
                shared_ptr< bool> arg__c = boost::shared_ptr< bool>(),
                shared_ptr< bool> arg__d = boost::shared_ptr< bool>(),
                shared_ptr< bool> arg__e = boost::shared_ptr< bool>());

        ITU_T_HOLDERH_DECL(a, integer_type);
        ITU_T_OPTIONAL_DECL(b, bool);
        ITU_T_OPTIONAL_DECL(c, bool);
        ITU_T_OPTIONAL_DECL(d, bool);
        ITU_T_OPTIONAL_DECL(e, bool);

        ITU_T_ARCHIVE_FUNC;
    };

    ITU_T_ARCHIVE_X690_DECL(PersonnelRecord_impl);
    ITU_T_ARCHIVE_X690_DECL(ChildInformation);
    ITU_T_ARCHIVE_X690_DECL(Name_impl);
    ITU_T_ARCHIVE_X690_DECL(A);

    ITU_T_ARCHIVE_X691_DECL(PersonnelRecord_impl);
    ITU_T_ARCHIVE_X691_DECL(ChildInformation);
    ITU_T_ARCHIVE_X691_DECL(Name_impl);
    ITU_T_ARCHIVE_X691_DECL(A);

}

ITU_T_SET_REGESTRATE(Test1::PersonnelRecord_impl)
ITU_T_SET_REGESTRATE(Test1::ChildInformation)


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1 */
