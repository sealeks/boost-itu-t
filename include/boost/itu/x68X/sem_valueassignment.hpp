//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_VALUEASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_VALUEASSIGNMENT_IMPLEMENTATIUON_H_

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

        virtual bool isrefferrence() const;

        value_atom_ptr skip_defined(bool except_abstract = false);

        numvalue_atom_ptr as_number();

        realvalue_atom_ptr as_real();

        boolvalue_atom_ptr as_bool();

        strvalue_atom_ptr as_cstr();

        namedvalue_atom_ptr as_named();

        structvalue_atom_ptr as_struct();

        structvalue_atom_ptr as_objid();

        structvalue_atom_ptr as_valuelist();

        structvalue_atom_ptr as_definedlist();

        structvalue_atom_ptr as_numberlist();

        structvalue_atom_ptr as_list();

        defined_value_atom_ptr as_defined();

        fromobject_value_atom_ptr as_fromobject();

        assignvalue_atom_ptr as_assign();

        choicevalue_atom_ptr as_choice();

        openvalue_atom_ptr as_open();

        nullvalue_atom_ptr as_null();

        emptyvalue_atom_ptr as_empty();

        template< typename T>
        boost::shared_ptr<T> get_value(bool except_abstract = false) {
            return boost::shared_ptr<T>();
        }

        template< typename T>
        boost::shared_ptr<T> get_value_parent(bool except_abstract = false);


    protected:

        void resolve_vect(value_vct& vl, basic_atom_ptr holder = basic_atom_ptr());

    private:

        value_type valtype_;

    };

    template<>
    boost::shared_ptr<null_initer> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<int64_t> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<std::string::value_type> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<std::size_t> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<bool> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<double> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<std::string> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<quadruple> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<tuple> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<string_vector> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<num_vector> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<unum_vector> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<bstring_initer> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<hstring_initer> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<tuple_vector> value_atom::get_value(bool except_abstract);

    template<>
    boost::shared_ptr<quadruple_vector> value_atom::get_value(bool except_abstract);



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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        value_vct values_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // defined_value_atom
    /////////////////////////////////////////////////////////////////////////      

    class defined_value_atom : public value_atom {

    public:

        defined_value_atom(const std::string& rff, basic_entity_ptr scp)
        : value_atom(scp, rff, v_defined) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobject_value_atom
    /////////////////////////////////////////////////////////////////////////      

    class fromobject_value_atom : public value_atom {

    public:

        fromobject_value_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());




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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());




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

        value_atom_ptr value() const;

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        void check_value_with_exception(value_type tp);


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual basic_atom_ptr atom() const {
            return value_;
        }

         virtual basic_atom_ptr typed_atom() const;       

    private:

        type_atom_ptr type_;
        value_atom_ptr value_;
    };

    template< typename T>
    boost::shared_ptr<T> value_atom::get_value_parent(bool except_abstract) {
        if (as_defined()) {
            if ((as_defined()->reff()) && (as_defined()->reff()->as_valueassigment())) {
                if (as_defined()->reff()->as_valueassigment()->value()) {
                    if ((except_abstract) && (as_defined()->reff()->as_valueassigment()->value()->isdummy()))
                        return boost::shared_ptr<T>();
                    return as_defined()->reff()->as_valueassigment()->value()->get_value<T>(except_abstract);
                }
            }
        }
        return boost::shared_ptr<T>();
    }

}

#endif	

