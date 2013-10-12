//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_VALUEASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_VALUEASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>

namespace x680 {


    /////////////////////////////////////////////////////////////////////////   
    // VALUE
    /////////////////////////////////////////////////////////////////////////      
    // value_atom
    /////////////////////////////////////////////////////////////////////////  

    class value_atom : public basic_atom {

    public:
        value_atom(basic_entity_ptr scp, value_type tpv);
        value_atom(basic_entity_ptr scp, const std::string& reff, value_type tpv);

        value_type valtype() const {
            return valtype_;
        }

        numvalue_atom* as_number();

        realvalue_atom* as_real();

        boolvalue_atom* as_bool();

        strvalue_atom* as_cstr();

        namedvalue_atom* as_named();

        structvalue_atom* as_struct();

        structvalue_atom* as_objid();

        structvalue_atom* as_valuelist();

        structvalue_atom* as_definedlist();

        structvalue_atom* as_numberlist();

        structvalue_atom* as_list();

        definedvalue_atom* as_defined();

        fromobjectvalue_atom* as_fromobject();

        assignvalue_atom* as_assign();

        choicevalue_atom* as_choice();

        openvalue_atom* as_open();

        nullvalue_atom* as_null();

        emptyvalue_atom* as_empty();


    protected:

        void resolve_vect(value_vct& vl);

    private:

        value_type valtype_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // numvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class numvalue_atom : public value_atom {

    public:

        numvalue_atom(int vl) : value_atom(basic_entity_ptr(), v_number), value_(vl) {
        };

        int value() const {
            return value_;
        }

    private:

        int value_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // realvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class realvalue_atom : public value_atom {

    public:

        realvalue_atom(double vl) : value_atom(basic_entity_ptr(), v_real), value_(vl) {
        };

        double value() const {
            return value_;
        }

    private:

        double value_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // realvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class boolvalue_atom : public value_atom {

    public:

        boolvalue_atom(bool vl) : value_atom(basic_entity_ptr(), v_boolean), value_(vl) {
        };

        bool value() const {
            return value_;
        }

    private:

        bool value_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // strvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class strvalue_atom : public value_atom {

    public:

        strvalue_atom(const std::string& vl, value_type tpv) : value_atom(basic_entity_ptr(), tpv), value_(vl) {
        };

        std::string value() const {
            return value_;
        }

    private:

        std::string value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // namedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class namedvalue_atom : public value_atom {

    public:

        namedvalue_atom(const std::string& nm, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_named_value), name_(nm), value_(vl) {
        };

        std::string name() const {
            return name_;
        }

        value_atom_ptr value() const {
            return value_;
        }

        virtual void resolve();


    private:

        std::string name_;
        value_atom_ptr value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // structvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class structvalue_atom : public value_atom {

    public:

        structvalue_atom(value_type tpv, value_vct vls)
        : value_atom(basic_entity_ptr(), tpv), values_(vls) {
        };

        value_vct& values() {
            return values_;
        }

        virtual void resolve();

    private:

        value_vct values_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // definedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class definedvalue_atom : public value_atom {

    public:

        definedvalue_atom(const std::string& rff, basic_entity_ptr scp)
        : value_atom(scp, rff, v_defined) {
        };

        virtual void resolve();

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobjectvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class fromobjectvalue_atom : public value_atom {

    public:

        fromobjectvalue_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

        object_atom_ptr object() const {
            return object_;
        }

        void object(object_atom_ptr vl) {
            object_ = vl;
        }

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        virtual void resolve();

    private:

        object_atom_ptr object_;
        basic_atom_ptr field_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // assignvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class assignvalue_atom : public value_atom {

    public:

        assignvalue_atom(const std::string& id, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_defined_assign), name_(id), value_(vl) {
        };

        const std::string& name() const {
            return name_;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        virtual void resolve();




    private:

        std::string name_;
        value_atom_ptr value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // choicevalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class choicevalue_atom : public value_atom {

    public:

        choicevalue_atom(const std::string& id, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_choice), name_(id), value_(vl) {
        };

        const std::string& name() const {
            return name_;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        virtual void resolve();


    private:

        std::string name_;
        value_atom_ptr value_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // openvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class openvalue_atom : public value_atom {

    public:

        openvalue_atom(type_atom_ptr tp, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_open), type_(tp), value_(vl) {
        };

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        virtual void resolve();




    private:

        type_atom_ptr type_;
        value_atom_ptr value_;
    };





    /////////////////////////////////////////////////////////////////////////   
    // nullvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class nullvalue_atom : public value_atom {

    public:

        nullvalue_atom() : value_atom(basic_entity_ptr(), v_null) {
        };

    };



    /////////////////////////////////////////////////////////////////////////   
    // emptyvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class emptyvalue_atom : public value_atom {

    public:

        emptyvalue_atom() : value_atom(basic_entity_ptr(), v_empty) {
        };

    };

    /////////////////////////////////////////////////////////////////////////   
    // valueassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valueassignment_entity : public assignment_entity {

    public:
        valueassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl = value_atom_ptr());

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        void check_value_with_exception(value_type tp);


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();


    private:

        type_atom_ptr type_;
        value_atom_ptr value_;
    };



}

#endif	

