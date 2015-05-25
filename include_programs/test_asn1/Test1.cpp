#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    // set  PersonnelRecord

    PersonnelRecord_impl::PersonnelRecord_impl() : name_(), title_(), number_(), dateOfHire_(), nameOfSpouse_() {
    };

    PersonnelRecord_impl::PersonnelRecord_impl(const Name& arg__name,
            const visiblestring_type& arg__title,
            const EmployeeNumber& arg__number,
            const Date& arg__dateOfHire,
            const Name& arg__nameOfSpouse) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse) {
    };

    PersonnelRecord_impl::PersonnelRecord_impl(shared_ptr< Name> arg__name,
            shared_ptr< visiblestring_type> arg__title,
            shared_ptr< EmployeeNumber> arg__number,
            shared_ptr< Date> arg__dateOfHire,
            shared_ptr< Name> arg__nameOfSpouse,
            shared_ptr< Children_type> arg__children) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse),
    children_(arg__children) {
    };


    ITU_T_HOLDERH_DEFN(PersonnelRecord_impl::name, name, Name);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_impl::title, title, visiblestring_type);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_impl::number, number, EmployeeNumber);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_impl::dateOfHire, dateOfHire, Date);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_impl::nameOfSpouse, nameOfSpouse, Name);
    ITU_T_OPTIONAL_DEFN(PersonnelRecord_impl::children, children, PersonnelRecord_impl::Children_type);

    // set  PersonnelRecord-s

    PersonnelRecord_s_impl::PersonnelRecord_s_impl() : name_(), title_(), number_(), dateOfHire_(), nameOfSpouse_() {
    };

    PersonnelRecord_s_impl::PersonnelRecord_s_impl(const Name& arg__name,
            const visiblestring_type& arg__title,
            const EmployeeNumber& arg__number,
            const Date& arg__dateOfHire,
            const Name& arg__nameOfSpouse) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse) {
    };

    PersonnelRecord_s_impl::PersonnelRecord_s_impl(shared_ptr< Name> arg__name,
            shared_ptr< visiblestring_type> arg__title,
            shared_ptr< EmployeeNumber> arg__number,
            shared_ptr< Date> arg__dateOfHire,
            shared_ptr< Name> arg__nameOfSpouse,
            shared_ptr< Children_type> arg__children) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse),
    children_(arg__children) {
    };


    ITU_T_HOLDERH_DEFN(PersonnelRecord_s_impl::name, name, Name);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s_impl::title, title, visiblestring_type);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s_impl::number, number, EmployeeNumber);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s_impl::dateOfHire, dateOfHire, Date);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s_impl::nameOfSpouse, nameOfSpouse, Name);
    ITU_T_OPTIONAL_DEFN(PersonnelRecord_s_impl::children, children, PersonnelRecord_s_impl::Children_type);

    // set  ChildInformation
    const enumerated_type ChildInformation::sex_male = 1;
    const enumerated_type ChildInformation::sex_female = 2;
    const enumerated_type ChildInformation::sex_unknown = 3;

    ChildInformation::ChildInformation() : name_(), dateOfBirth_() {
    };

    ChildInformation::ChildInformation(const Name& arg__name,
            const Date& arg__dateOfBirth) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth) {
    };

    ChildInformation::ChildInformation(shared_ptr< Name> arg__name,
            shared_ptr< Date> arg__dateOfBirth,
            shared_ptr< enumerated_type> arg__sex) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth),
    sex_(arg__sex) {
    };


    ITU_T_HOLDERH_DEFN(ChildInformation::name, name, Name);
    ITU_T_HOLDERH_DEFN(ChildInformation::dateOfBirth, dateOfBirth, Date);
    ITU_T_OPTIONAL_DEFN(ChildInformation::sex, sex, enumerated_type);

    // set  ChildInformation-s

    ChildInformation_s::ChildInformation_s() : name_(), dateOfBirth_() {
    };

    ChildInformation_s::ChildInformation_s(const Name& arg__name,
            const Date& arg__dateOfBirth) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth) {
    };


    ITU_T_HOLDERH_DEFN(ChildInformation_s::name, name, Name);
    ITU_T_HOLDERH_DEFN(ChildInformation_s::dateOfBirth, dateOfBirth, Date);

    // sequence Name

    Name_impl::Name_impl() : givenName_(), initial_(), familyName_() {
    };

    Name_impl::Name_impl(const NameString& arg__givenName,
            const NameString& arg__initial,
            const NameString& arg__familyName) :
    givenName_(arg__givenName),
    initial_(arg__initial),
    familyName_(arg__familyName) {
    };


    ITU_T_HOLDERH_DEFN(Name_impl::givenName, givenName, NameString);
    ITU_T_HOLDERH_DEFN(Name_impl::initial, initial, NameString);
    ITU_T_HOLDERH_DEFN(Name_impl::familyName, familyName, NameString);

    // sequence Ax

    Ax::Ax() : a_(), b_(), c_() {
    };

    Ax::Ax(const uint8_t& arg__a,
            const bool& arg__b,
            const C_type& arg__c) :
    a_(arg__a),
    b_(arg__b),
    c_(arg__c) {
    };

    Ax::Ax(shared_ptr< uint8_t> arg__a,
            shared_ptr< bool> arg__b,
            shared_ptr< C_type> arg__c,
            shared_ptr< numericstring_type> arg__g,
            shared_ptr< bool> arg__h,
            shared_ptr< bmpstring_type> arg__i,
            shared_ptr< printablestring_type> arg__j) :
    a_(arg__a),
    b_(arg__b),
    c_(arg__c),
    g_(arg__g),
    h_(arg__h),
    i_(arg__i),
    j_(arg__j) {
    };



    ITU_T_CHOICES_DEFN(Ax::C_type::d, d, integer_type, C_type_d);
    ITU_T_CHOICES_DEFN(Ax::C_type::e, e, bool, C_type_e);
    ITU_T_CHOICES_DEFN(Ax::C_type::f, f, ia5string_type, C_type_f);


    ITU_T_HOLDERH_DEFN(Ax::a, a, uint8_t);
    ITU_T_HOLDERH_DEFN(Ax::b, b, bool);
    ITU_T_HOLDERH_DEFN(Ax::c, c, Ax::C_type);
    ITU_T_OPTIONAL_DEFN(Ax::g, g, numericstring_type);
    ITU_T_OPTIONAL_DEFN(Ax::h, h, bool);
    ITU_T_OPTIONAL_DEFN(Ax::i, i, bmpstring_type);
    ITU_T_OPTIONAL_DEFN(Ax::j, j, printablestring_type);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

