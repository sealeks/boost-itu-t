#include "Test1.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Test1 {

    // set PersonnelRecord

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

    PersonnelRecord_impl::PersonnelRecord_impl(boost::shared_ptr< Name> arg__name,
            boost::shared_ptr< visiblestring_type> arg__title,
            boost::shared_ptr< EmployeeNumber> arg__number,
            boost::shared_ptr< Date> arg__dateOfHire,
            boost::shared_ptr< Name> arg__nameOfSpouse,
            boost::shared_ptr< Children_type> arg__children) :
    name_(arg__name),
    title_(arg__title),
    number_(arg__number),
    dateOfHire_(arg__dateOfHire),
    nameOfSpouse_(arg__nameOfSpouse),
    children_(arg__children) {
    };

    Name& PersonnelRecord_impl::name() {
        return *name_;
    }

    const Name& PersonnelRecord_impl::name() const {
        return *name_;
    }

    void PersonnelRecord_impl::name(const Name& vl) {
        name_ = vl;
    }

    void PersonnelRecord_impl::name(boost::shared_ptr< Name> vl) {
        name_ = vl;
    }

    visiblestring_type& PersonnelRecord_impl::title() {
        return *title_;
    }

    const visiblestring_type& PersonnelRecord_impl::title() const {
        return *title_;
    }

    void PersonnelRecord_impl::title(const visiblestring_type& vl) {
        title_ = vl;
    }

    void PersonnelRecord_impl::title(boost::shared_ptr< visiblestring_type> vl) {
        title_ = vl;
    }

    EmployeeNumber& PersonnelRecord_impl::number() {
        return *number_;
    }

    const EmployeeNumber& PersonnelRecord_impl::number() const {
        return *number_;
    }

    void PersonnelRecord_impl::number(const EmployeeNumber& vl) {
        number_ = vl;
    }

    void PersonnelRecord_impl::number(boost::shared_ptr< EmployeeNumber> vl) {
        number_ = vl;
    }

    Date& PersonnelRecord_impl::dateOfHire() {
        return *dateOfHire_;
    }

    const Date& PersonnelRecord_impl::dateOfHire() const {
        return *dateOfHire_;
    }

    void PersonnelRecord_impl::dateOfHire(const Date& vl) {
        dateOfHire_ = vl;
    }

    void PersonnelRecord_impl::dateOfHire(boost::shared_ptr< Date> vl) {
        dateOfHire_ = vl;
    }

    Name& PersonnelRecord_impl::nameOfSpouse() {
        return *nameOfSpouse_;
    }

    const Name& PersonnelRecord_impl::nameOfSpouse() const {
        return *nameOfSpouse_;
    }

    void PersonnelRecord_impl::nameOfSpouse(const Name& vl) {
        nameOfSpouse_ = vl;
    }

    void PersonnelRecord_impl::nameOfSpouse(boost::shared_ptr< Name> vl) {
        nameOfSpouse_ = vl;
    }

    boost::shared_ptr<PersonnelRecord_impl::Children_type> PersonnelRecord_impl::children__new() {
        return children_ = boost::shared_ptr<Children_type>(new Children_type());
    }

    void PersonnelRecord_impl::children(const Children_type& vl) {
        children_ = boost::shared_ptr<Children_type>(new Children_type(vl));
    }


    // set ChildInformation
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

    ChildInformation::ChildInformation(boost::shared_ptr< Name> arg__name,
            boost::shared_ptr< Date> arg__dateOfBirth,
            boost::shared_ptr< enumerated_type> arg__sex) :
    name_(arg__name),
    dateOfBirth_(arg__dateOfBirth),
    sex_(arg__sex) {
    };

    Name& ChildInformation::name() {
        return *name_;
    }

    const Name& ChildInformation::name() const {
        return *name_;
    }

    void ChildInformation::name(const Name& vl) {
        name_ = vl;
    }

    void ChildInformation::name(boost::shared_ptr< Name> vl) {
        name_ = vl;
    }

    Date& ChildInformation::dateOfBirth() {
        return *dateOfBirth_;
    }

    const Date& ChildInformation::dateOfBirth() const {
        return *dateOfBirth_;
    }

    void ChildInformation::dateOfBirth(const Date& vl) {
        dateOfBirth_ = vl;
    }

    void ChildInformation::dateOfBirth(boost::shared_ptr< Date> vl) {
        dateOfBirth_ = vl;
    }

    boost::shared_ptr<enumerated_type> ChildInformation::sex__new() {
        return sex_ = boost::shared_ptr<enumerated_type>(new enumerated_type());
    }

    void ChildInformation::sex(const enumerated_type& vl) {
        sex_ = boost::shared_ptr<enumerated_type>(new enumerated_type(vl));
    }


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

    NameString& Name_impl::givenName() {
        return *givenName_;
    }

    const NameString& Name_impl::givenName() const {
        return *givenName_;
    }

    void Name_impl::givenName(const NameString& vl) {
        givenName_ = vl;
    }

    void Name_impl::givenName(boost::shared_ptr< NameString> vl) {
        givenName_ = vl;
    }

    NameString& Name_impl::initial() {
        return *initial_;
    }

    const NameString& Name_impl::initial() const {
        return *initial_;
    }

    void Name_impl::initial(const NameString& vl) {
        initial_ = vl;
    }

    void Name_impl::initial(boost::shared_ptr< NameString> vl) {
        initial_ = vl;
    }

    NameString& Name_impl::familyName() {
        return *familyName_;
    }

    const NameString& Name_impl::familyName() const {
        return *familyName_;
    }

    void Name_impl::familyName(const NameString& vl) {
        familyName_ = vl;
    }

    void Name_impl::familyName(boost::shared_ptr< NameString> vl) {
        familyName_ = vl;
    }


}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

