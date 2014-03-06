#ifndef ___TEST1
#define ___TEST1

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    using boost::asn1::null_type;
    using boost::asn1::enumerated_type;
    using boost::asn1::bitstring_type;
    using boost::asn1::octetstring_type;
    using boost::asn1::oid_type;
    using boost::asn1::reloid_type;
    using boost::asn1::utctime_type;
    using boost::asn1::gentime_type;
    using boost::asn1::ia5string_type;
    using boost::asn1::printablestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::numericstring_type;
    using boost::asn1::universalstring_type;
    using boost::asn1::bmpstring_type;
    using boost::asn1::utf8string_type;
    using boost::asn1::generalstring_type;
    using boost::asn1::graphicstring_type;
    using boost::asn1::t61string_type;
    using boost::asn1::t61string_type;
    using boost::asn1::videotexstring_type;
    using boost::asn1::objectdescriptor_type;
    using boost::asn1::external_type;
    using boost::asn1::embeded_type;
    using boost::asn1::characterstring_type;
    using boost::asn1::any_type;
    using boost::asn1::value_holder;
    using boost::asn1::default_holder;


    struct PersonnelRecord_impl;
    struct ChildInformation;
    struct Name_impl;


    ITU_T_IMPLICIT_TYPEDEF(EmployeeNumber, int, 2, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(Date, visiblestring_type, 3, APPLICATION_CLASS);

    ITU_T_IMPLICIT_TYPEDEF(PersonnelRecord, PersonnelRecord_impl, 0, APPLICATION_CLASS);
    ITU_T_IMPLICIT_TYPEDEF(Name, Name_impl, 1, APPLICATION_CLASS);


}


namespace Test1 {


    // set PersonnelRecord

    struct PersonnelRecord_impl {

        typedef std::vector< ChildInformation > Children_type;


        PersonnelRecord_impl();

        PersonnelRecord_impl(const Name& arg__name,
                const visiblestring_type& arg__title,
                const EmployeeNumber& arg__number,
                const Date& arg__dateOfHire,
                const Name& arg__nameOfSpouse);

        PersonnelRecord_impl(boost::shared_ptr< Name> arg__name,
                boost::shared_ptr< visiblestring_type> arg__title,
                boost::shared_ptr< EmployeeNumber> arg__number,
                boost::shared_ptr< Date> arg__dateOfHire,
                boost::shared_ptr< Name> arg__nameOfSpouse,
                boost::shared_ptr< Children_type> arg__children);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(title, visiblestring_type);
        ITU_T_HOLDERH_DECL(number, EmployeeNumber);
        ITU_T_HOLDERH_DECL(dateOfHire, Date);
        ITU_T_HOLDERH_DECL(nameOfSpouse, Name);
        ITU_T_OPTIONAL_DECL(children, Children_type);

        ITU_T_ARCHIVE_FUNC;
    };

    // set ChildInformation

    struct ChildInformation {

        ChildInformation();

        ChildInformation(const Name& arg__name,
                const Date& arg__dateOfBirth);

        ITU_T_HOLDERH_DECL(name, Name);
        ITU_T_HOLDERH_DECL(dateOfBirth, Date);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence Name

    struct Name_impl {

        Name_impl();

        Name_impl(const visiblestring_type& arg__givenName,
                const visiblestring_type& arg__initial,
                const visiblestring_type& arg__familyName);

        ITU_T_HOLDERH_DECL(givenName, visiblestring_type);
        ITU_T_HOLDERH_DECL(initial, visiblestring_type);
        ITU_T_HOLDERH_DECL(familyName, visiblestring_type);

        ITU_T_ARCHIVE_FUNC;
    };

    template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void PersonnelRecord_impl::serialize(boost::asn1::x690::input_coder& arch);
    template<> void ChildInformation::serialize(boost::asn1::x690::output_coder& arch);
    template<> void ChildInformation::serialize(boost::asn1::x690::input_coder& arch);
    template<> void Name_impl::serialize(boost::asn1::x690::output_coder& arch);
    template<> void Name_impl::serialize(boost::asn1::x690::input_coder& arch);
}

ITU_T_SET_REGESTRATE(Test1::PersonnelRecord_impl)
ITU_T_SET_REGESTRATE(Test1::ChildInformation)


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___TEST1 */
