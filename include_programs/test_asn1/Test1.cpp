#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    // set  PersonnelRecord

    PersonnelRecord::PersonnelRecord() : name_(), title_(), number_(), dateOfHire_(), nameOfSpouse_() {
    };

    PersonnelRecord::PersonnelRecord(const Name& arg__name,
            const visible_string& arg__title,
            const EmployeeNumber& arg__number,
            const Date& arg__dateOfHire,
            const Name& arg__nameOfSpouse) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse) {
    };

    PersonnelRecord::PersonnelRecord(ITU_T_SHARED(Name) arg__name,
            ITU_T_SHARED(visible_string) arg__title,
            ITU_T_SHARED(EmployeeNumber) arg__number,
            ITU_T_SHARED(Date) arg__dateOfHire,
            ITU_T_SHARED(Name) arg__nameOfSpouse,
            ITU_T_SHARED(Children_type) arg__children) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse),
    children_(arg__children) {
    };


    ITU_T_HOLDERH_DEFN(PersonnelRecord::name, name, Name);
    ITU_T_HOLDERH_DEFN(PersonnelRecord::title, title, visible_string);
    ITU_T_HOLDERH_DEFN(PersonnelRecord::number, number, EmployeeNumber);
    ITU_T_HOLDERH_DEFN(PersonnelRecord::dateOfHire, dateOfHire, Date);
    ITU_T_HOLDERH_DEFN(PersonnelRecord::nameOfSpouse, nameOfSpouse, Name);
    ITU_T_OPTIONAL_DEFN(PersonnelRecord::children, children, PersonnelRecord::Children_type);

    // set  PersonnelRecord-s

    PersonnelRecord_s::PersonnelRecord_s() : name_(), title_(), number_(), dateOfHire_(), nameOfSpouse_() {
    };

    PersonnelRecord_s::PersonnelRecord_s(const Name& arg__name,
            const visible_string& arg__title,
            const EmployeeNumber& arg__number,
            const Date& arg__dateOfHire,
            const Name& arg__nameOfSpouse) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse) {
    };

    PersonnelRecord_s::PersonnelRecord_s(ITU_T_SHARED(Name) arg__name,
            ITU_T_SHARED(visible_string) arg__title,
            ITU_T_SHARED(EmployeeNumber) arg__number,
            ITU_T_SHARED(Date) arg__dateOfHire,
            ITU_T_SHARED(Name) arg__nameOfSpouse,
            ITU_T_SHARED(Children_type) arg__children) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse),
    children_(arg__children) {
    };


    ITU_T_HOLDERH_DEFN(PersonnelRecord_s::name, name, Name);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s::title, title, visible_string);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s::number, number, EmployeeNumber);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s::dateOfHire, dateOfHire, Date);
    ITU_T_HOLDERH_DEFN(PersonnelRecord_s::nameOfSpouse, nameOfSpouse, Name);
    ITU_T_OPTIONAL_DEFN(PersonnelRecord_s::children, children, PersonnelRecord_s::Children_type);

    // set  ChildInformation
    const enumerated ChildInformation::sex_male = 1;
    const enumerated ChildInformation::sex_female = 2;
    const enumerated ChildInformation::sex_unknown = 3;

    ChildInformation::ChildInformation() : name_(), dateOfBirth_() {
    };

    ChildInformation::ChildInformation(const Name& arg__name,
            const Date& arg__dateOfBirth) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth) {
    };

    ChildInformation::ChildInformation(ITU_T_SHARED(Name) arg__name,
            ITU_T_SHARED(Date) arg__dateOfBirth,
            ITU_T_SHARED(enumerated) arg__sex) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth),
    sex_(arg__sex) {
    };


    ITU_T_HOLDERH_DEFN(ChildInformation::name, name, Name);
    ITU_T_HOLDERH_DEFN(ChildInformation::dateOfBirth, dateOfBirth, Date);
    ITU_T_OPTIONAL_DEFN(ChildInformation::sex, sex, enumerated);

    // set  ChildInformation-s

    ChildInformation_s::ChildInformation_s() : name_(), dateOfBirth_() {
    };

    ChildInformation_s::ChildInformation_s(const Name& arg__name,
            const Date& arg__dateOfBirth) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth) {
    };

    ChildInformation_s::ChildInformation_s(ITU_T_SHARED(Name) arg__name,
            ITU_T_SHARED(Date) arg__dateOfBirth) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth) {
    };


    ITU_T_HOLDERH_DEFN(ChildInformation_s::name, name, Name);
    ITU_T_HOLDERH_DEFN(ChildInformation_s::dateOfBirth, dateOfBirth, Date);

    // sequence Name

    Name::Name() : givenName_(), initial_(), familyName_() {
    };

    Name::Name(const NameString& arg__givenName,
            const NameString& arg__initial,
            const NameString& arg__familyName) :
    givenName_(arg__givenName),
    initial_(arg__initial),
    familyName_(arg__familyName) {
    };

    Name::Name(ITU_T_SHARED(NameString) arg__givenName,
            ITU_T_SHARED(NameString) arg__initial,
            ITU_T_SHARED(NameString) arg__familyName) :
    givenName_(arg__givenName),
    initial_(arg__initial),
    familyName_(arg__familyName) {
    };


    ITU_T_HOLDERH_DEFN(Name::givenName, givenName, NameString);
    ITU_T_HOLDERH_DEFN(Name::initial, initial, NameString);
    ITU_T_HOLDERH_DEFN(Name::familyName, familyName, NameString);

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

    Ax::Ax(ITU_T_SHARED(uint8_t) arg__a,
            ITU_T_SHARED(bool) arg__b,
            ITU_T_SHARED(C_type) arg__c,
            ITU_T_SHARED(numeric_string) arg__g,
            ITU_T_SHARED(bool) arg__h,
            ITU_T_SHARED(bmp_string) arg__i,
            ITU_T_SHARED(printable_string) arg__j) :
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
    ITU_T_CHOICES_DEFN(Ax::C_type::f, f, ia5_string, C_type_f);


    ITU_T_HOLDERH_DEFN(Ax::a, a, uint8_t);
    ITU_T_HOLDERH_DEFN(Ax::b, b, bool);
    ITU_T_HOLDERH_DEFN(Ax::c, c, Ax::C_type);
    ITU_T_OPTIONAL_DEFN(Ax::g, g, numeric_string);
    ITU_T_OPTIONAL_DEFN(Ax::h, h, bool);
    ITU_T_OPTIONAL_DEFN(Ax::i, i, bmp_string);
    ITU_T_OPTIONAL_DEFN(Ax::j, j, printable_string);

    // std::cout methods

    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord& vl) {
        stream << "{ ";
        stream << "name :  " << vl.name();
        stream << ", title :  " << "\"" << vl.title() << "\"";
        stream << ", number :  " << vl.number();
        stream << ", dateOfHire :  " << "\"" << vl.dateOfHire() << "\"";
        stream << ", nameOfSpouse :  " << vl.nameOfSpouse();
        if (vl.children()) stream << ", children :  " << *(vl.children());
        stream << " }";
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord::Children_type& vl) {
        for (PersonnelRecord::Children_type::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            stream << " {" << *it << "}";
        };
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord_s& vl) {
        stream << "{ ";
        stream << "name :  " << vl.name();
        stream << ", title :  " << "\"" << vl.title() << "\"";
        stream << ", number :  " << vl.number();
        stream << ", dateOfHire :  " << "\"" << vl.dateOfHire() << "\"";
        stream << ", nameOfSpouse :  " << vl.nameOfSpouse();
        if (vl.children()) stream << ", children :  " << *(vl.children());
        stream << " }";
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const PersonnelRecord_s::Children_type& vl) {
        for (PersonnelRecord_s::Children_type::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            stream << " {" << *it << "}";
        };
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const ChildInformation& vl) {
        stream << "{ ";
        stream << "name :  " << vl.name();
        stream << ", dateOfBirth :  " << "\"" << vl.dateOfBirth() << "\"";
        if (vl.sex()) stream << ", sex :  " << *(vl.sex());
        stream << " }";
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const ChildInformation_s& vl) {
        stream << "{ ";
        stream << "name :  " << vl.name();
        stream << ", dateOfBirth :  " << "\"" << vl.dateOfBirth() << "\"";
        stream << " }";
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const Name& vl) {
        stream << "{ ";
        stream << "givenName :  " << "\"" << vl.givenName() << "\"";
        stream << ", initial :  " << "\"" << vl.initial() << "\"";
        stream << ", familyName :  " << "\"" << vl.familyName() << "\"";
        stream << " }";
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const Ax& vl) {
        stream << "{ ";
        stream << "a :  " << vl.a();
        stream << ", b :  " << vl.b();
        stream << ", c :  " << vl.c();
        if (vl.g()) stream << ", g :  " << "\"" << *(vl.g()) << "\"";
        if (vl.h()) stream << ", h :  " << *(vl.h());
        if (vl.i()) stream << ", i :  " << "\"" << *(vl.i()) << "\"";
        if (vl.j()) stream << ", j :  " << "\"" << *(vl.j()) << "\"";
        stream << " }";
        return stream;
    };

    std::ostream& operator<<(std::ostream& stream, const Ax::C_type& vl) {
        stream << "{ ";
        switch (vl.type()) {
            case Ax::C_type_d: stream << "d :  " << *(vl.d());
                break;
            case Ax::C_type_e: stream << "e :  " << *(vl.e());
                break;
            case Ax::C_type_f: stream << "f :  " << "\"" << *(vl.f()) << "\"";
                break;
            default:
            {
                stream << " null ";
            }
        };
        stream << " }";
        return stream;
    };


}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

