//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_VALUESETASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_VALUESETASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>

namespace x680 {


    typedef std::vector<std::string> snotation_vector;

    /////////////////////////////////////////////////////////////////////////   
    // VALUESET
    /////////////////////////////////////////////////////////////////////////   
    // valueset_atom
    /////////////////////////////////////////////////////////////////////////  

    class valueset_atom : public basic_atom {

    public:
        valueset_atom(basic_entity_ptr scope, valueset_type tp);
        valueset_atom(basic_entity_ptr scope, const std::string& reff, valueset_type tp);

        valueset_type builtin() const {
            return builtin_;
        }

        constraints_atom_ptr set() const {
            return set_;
        }

        void set(constraints_atom_ptr vl) {
            set_ = vl;
        }

        virtual bool isrefferrence() const;

        fromobject_valueset_atom_ptr as_fromobject();

        fromobjects_valueset_atom_ptr as_fromobjectset();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        valueset_type builtin_;
        constraints_atom_ptr set_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobject_valueset_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobject_valueset_atom : public valueset_atom {

    public:

        fromobject_valueset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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
    // fromobjects_valueset_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjects_valueset_atom : public valueset_atom {

    public:

        fromobjects_valueset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj = objectset_atom_ptr());

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;
        basic_atom_ptr field_;

    };




    /////////////////////////////////////////////////////////////////////////   
    // constraints_atom
    /////////////////////////////////////////////////////////////////////////  

    class constraints_atom : public basic_atom {

    public:

        constraints_atom(basic_entity_ptr scp, const std::string& reff) :
        basic_atom(at_Constraints, scp, reff) {
        };

        constraints_atom(basic_entity_ptr scp, const constraint_atom_vct& fst, bool ext = false) :
        basic_atom(at_Constraints, scp), constraintline_(fst), extend_(ext) {
        };

        constraints_atom(basic_entity_ptr scp, const constraint_atom_vct& fst, const constraint_atom_vct& scd) :
        basic_atom(at_Constraints, scp), constraintline_(fst), extendline_(scd), extend_(true) {
        };

        constraint_atom_vct& constraintline() {
            return constraintline_;
        }

        constraint_atom_vct& extendline() {
            return extendline_;
        }

        bool extend() const {
            return (!extendline_.empty()) || extend_;
        }

        void extend(bool val) {
            extend_ = val;
        }

        ////

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    protected:

        constraint_atom_vct constraintline_;
        constraint_atom_vct extendline_;
        bool extend_;

    };




    /////////////////////////////////////////////////////////////////////////   
    // constraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class constraint_atom : public basic_atom {

    public:
        constraint_atom(constraint_type tp = cns_nodef);
        constraint_atom(basic_entity_ptr scp, constraint_type tp);
        constraint_atom(basic_entity_ptr scp, const std::string& reff, constraint_type tp);

        constraint_type cotstrtype() const {
            return cotstrtype_;
        }

        valueconstraint_atom_ptr as_valueconstraint();
        
        valuesetconstraint_atom_ptr as_valuesetconstraint();        

        fromdefined_objects_constraint_atom_ptr as_fromdefinedset();

        fromdefined_constraint_atom_ptr as_fromdefined();

        valueconstraint_atom_ptr as_pattern();

        typeconstraint_atom_ptr as_subtypeconstraint();

        typeconstraint_atom_ptr as_typeconstraint();

        rangeconstraint_atom_ptr as_range();

        rangeconstraint_atom_ptr as_strictrange();

        rangeconstraint_atom_ptr as_duration();

        rangeconstraint_atom_ptr as_timepoint();

        rangeconstraint_atom_ptr as_reccurence();

        namedconstraint_atom_ptr as_named();

        complexconstraint_atom_ptr as_complex();

        complexconstraint_atom_ptr as_size();

        complexconstraint_atom_ptr as_permitted();

        complexconstraint_atom_ptr as_singletype();

        multipletypeconstraint_atom_ptr as_multipletypeconstraint();

        stringconstraint_atom_ptr as_property();

        userconstraint_atom_ptr as_user();

        contentconstraint_atom_ptr as_content();

        relationconstraint_atom_ptr as_relation();

        tableconstraint_atom_ptr as_table();

        tvosoconstraint_atom_ptr as_tvoso();

        unionconstraint_atom_ptr as_union();

        intersectionconstraint_atom_ptr as_intersection();

        exceptconstraint_atom_ptr as_except();

        allconstraint_atom_ptr as_all();

        extentionconstraint_atom_ptr as_extention();

        exceptionconstraint_atom_ptr as_exception();


    private:

        constraint_type cotstrtype_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // valueconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class valueconstraint_atom : public constraint_atom {

    public:

        valueconstraint_atom(basic_entity_ptr scp, constraint_type tpc, value_atom_ptr vl) : constraint_atom(scp, tpc), value_(vl) {
        };

        value_atom_ptr value() {
            return value_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        value_atom_ptr value_;

    };
    
    
       /////////////////////////////////////////////////////////////////////////   
    // valuesetconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class valuesetconstraint_atom : public constraint_atom {

    public:

        valuesetconstraint_atom(basic_entity_ptr scp, valueset_atom_ptr vl) : constraint_atom(scp, cns_ValueSet), valueset_(vl) {
        };

        valueset_atom_ptr valueset() {
            return valueset_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        valueset_atom_ptr valueset_;

    }; 


    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_objects_constraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromdefined_objects_constraint_atom : public constraint_atom {

    public:

        fromdefined_objects_constraint_atom(basic_entity_ptr scope, const std::string& refffld, objectset_atom_ptr objs = objectset_atom_ptr());

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_constraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromdefined_constraint_atom : public constraint_atom {

    public:

        fromdefined_constraint_atom(basic_entity_ptr scope, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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
    // typeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class typeconstraint_atom : public constraint_atom {

    public:

        typeconstraint_atom(basic_entity_ptr scp, constraint_type tpc, typeassignment_entity_ptr tp, bool incl) :
        constraint_atom(scp, tpc), typeassignment_(tp), includes_(incl) {
        };
        
        type_atom_ptr type();
        
        typeassignment_entity_ptr typeassignment() {
            return typeassignment_;
        }

        void typeassignment(typeassignment_entity_ptr vl) {
            typeassignment_ = vl;
        }        

        bool includdes() {
            return includes_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        typeassignment_entity_ptr typeassignment_;
        bool includes_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // stringconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class stringconstraint_atom : public constraint_atom {

    public:

        stringconstraint_atom(basic_entity_ptr scp, constraint_type tpc, const std::string& prop) :
        constraint_atom(scp, tpc), property_(prop) {
        };

        std::string property() {
            return property_;
        }

    private:

        std::string property_;


    };


    /////////////////////////////////////////////////////////////////////////   
    // rangeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class rangeconstraint_atom : public constraint_atom {

    public:

        rangeconstraint_atom(basic_entity_ptr scp, constraint_type tpc, value_atom_ptr fr, range_type frtp, value_atom_ptr to, range_type totp);

        value_atom_ptr from() {
            return from_;
        }

        range_type fromtype() {
            return fromtype_;
        }

        value_atom_ptr to() {
            return to_;
        }

        range_type totype() {
            return totype_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        value_atom_ptr from_;
        range_type fromtype_;
        value_atom_ptr to_;
        range_type totype_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // namedconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class namedconstraint_atom : public constraint_atom {

    public:

        namedconstraint_atom(basic_entity_ptr scp, const std::string& nm, constraints_atom_ptr ctrs, constraintmarker_type mrkr = cmk_none) :
        constraint_atom(scp, cns_NamedConstraint), name_(nm), constraints_(ctrs), marker_(mrkr) {
        };

        namedconstraint_atom(basic_entity_ptr scp, const std::string& nm, constraintmarker_type mrkr = cmk_none) :
        constraint_atom(scp, cns_NamedConstraint), name_(nm), marker_(mrkr) {
        };

        std::string name() {
            return name_;
        }

        constraints_atom_ptr constraints() {
            return constraints_;
        }

        constraintmarker_type marker() {
            return marker_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        std::string name_;
        constraints_atom_ptr constraints_;
        constraintmarker_type marker_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // multipletypeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class multipletypeconstraint_atom : public constraint_atom {

    public:

        multipletypeconstraint_atom(basic_entity_ptr scp, const constraint_atom_vct& fst) :
        constraint_atom(scp, cns_MultipleTypeConstraints), components_(fst) {
        };

        constraint_atom_vct& components() {
            return components_;
        }

        bool full() const;

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


    protected:

        constraint_atom_vct components_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // complexconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class complexconstraint_atom : public constraint_atom {

    public:

        complexconstraint_atom(basic_entity_ptr scp, constraint_type tpc, constraints_atom_ptr ctrs) :
        constraint_atom(scp, tpc), constraints_(ctrs) {
        };

        constraints_atom_ptr constraints() {
            return constraints_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


    private:

        constraints_atom_ptr constraints_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // unionconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class unionconstraint_atom : public constraint_atom {

    public:

        unionconstraint_atom() : constraint_atom(cns_UNION) {
        }
    };




    /////////////////////////////////////////////////////////////////////////   
    // intersectionconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class intersectionconstraint_atom : public constraint_atom {

    public:

        intersectionconstraint_atom() : constraint_atom(cns_INTERSECTION) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // exceptconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class exceptconstraint_atom : public constraint_atom {

    public:

        exceptconstraint_atom() : constraint_atom(cns_EXCEPT) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // allconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class allconstraint_atom : public constraint_atom {

    public:

        allconstraint_atom() : constraint_atom(cns_ALLEXCEPT) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // exceptconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class extentionconstraint_atom : public constraint_atom {

    public:

        extentionconstraint_atom() : constraint_atom(cns_EXTENTION) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // exceptionconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class exceptionconstraint_atom : public constraint_atom {

    public:

        exceptionconstraint_atom(basic_entity_ptr scp, int vl)
        : constraint_atom(scp, cns_EXCEPTION), value_(value_atom_ptr(new numvalue_atom(vl))),
        type_(type_atom_ptr(new type_atom(scp, t_INTEGER))) {
        }

        exceptionconstraint_atom(basic_entity_ptr scp, std::string vl)
        : constraint_atom(scp, cns_EXCEPTION), value_(value_atom_ptr(new defined_value_atom(vl, scp))),
        type_(type_atom_ptr(new type_atom(scp, t_INTEGER))) {
        }

        exceptionconstraint_atom(basic_entity_ptr scp, type_atom_ptr tp, value_atom_ptr vl)
        : constraint_atom(scp, cns_EXCEPTION), value_(vl), type_(tp) {
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr val) {
            value_ = val;
        }

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr val) {
            type_ = val;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        value_atom_ptr value_;
        type_atom_ptr type_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // userconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class userconstraint_atom : public constraint_atom {

    public:

        userconstraint_atom(basic_entity_ptr scp, uargument_entity_vct vct)
        : constraint_atom(scp, cns_UserDefinedConstraint), arguments_(vct) {
        }

        uargument_entity_vct& arguments() {
            return arguments_;
        }

        void arguments(uargument_entity_vct vl) {
            arguments_ = vl;
        }

        bool has_arguments() const {
            return !arguments_.empty();
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        uargument_entity_vct arguments_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // contentconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class contentconstraint_atom : public constraint_atom {

    public:

        contentconstraint_atom(basic_entity_ptr scp, type_atom_ptr tp, value_atom_ptr vl)
        : constraint_atom(scp, cns_Contents), value_(vl), type_(tp) {
        }

        contentconstraint_atom(basic_entity_ptr scp, type_atom_ptr tp)
        : constraint_atom(scp, cns_Contents), type_(tp) {
        }

        contentconstraint_atom(basic_entity_ptr scp, value_atom_ptr vl)
        : constraint_atom(scp, cns_Contents), value_(vl) {
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr val) {
            value_ = val;
        }

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr val) {
            type_ = val;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:


        value_atom_ptr value_;
        type_atom_ptr type_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // relationconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class relationconstraint_atom : public constraint_atom {

    public:

        relationconstraint_atom(basic_entity_ptr scp, objectset_atom_ptr objs, snotation_vector nots)
        : constraint_atom(scp, cns_ComponentRelation), objectset_(objs), snotation_(nots) {
        }

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr val) {
            objectset_ = val;
        }

        const snotation_vector& snotation() const {
            return snotation_;
        }

        void snotation(snotation_vector val) {
            snotation_ = val;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:


        objectset_atom_ptr objectset_;
        snotation_vector snotation_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // tableconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class tableconstraint_atom : public constraint_atom {

    public:

        tableconstraint_atom(basic_entity_ptr scp, objectset_atom_ptr objs)
        : constraint_atom(scp, cns_SimpleTableConstraint), objectset_(objs) {
        }

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr val) {
            objectset_ = val;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:


        objectset_atom_ptr objectset_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // tvosoconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class tvosoconstraint_atom : public constraint_atom {

    public:

        tvosoconstraint_atom(basic_entity_ptr scp, const std::string& reff = "");

        type_atom_ptr type();

        typeassignment_entity_ptr typeassignment() {
            return typeassignment_;
        }

        void typeassignment(typeassignment_entity_ptr vl) {
            typeassignment_ = vl;
        }

        valueset_atom_ptr valueset() const {
            return valueset_;
        }

        void valueset(valueset_atom_ptr val) {
            valueset_ = val;
        }

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr val) {
            objectset_ = val;
        }

        argument_enum tp() const {
            return tp_;
        }

        void tp(argument_enum val) {
            tp_ = val;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:


        objectset_atom_ptr objectset_;
        valueset_atom_ptr valueset_;
        typeassignment_entity_ptr typeassignment_;
        argument_enum tp_;

    };




    /////////////////////////////////////////////////////////////////////////   
    // valuesetassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valuesetassignment_entity : public assignment_entity {

    public:
        valuesetassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, valueset_atom_ptr vl = valueset_atom_ptr());

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        valueset_atom_ptr valueset() const;

        void valueset(valueset_atom_ptr vl) {
            valueset_ = vl;
        }

        const x680::syntactic::valueset_assignment& synctas() const {
            return synctas_;
        }

        void synctas(const x680::syntactic::valueset_assignment& vl) {
            synctas_ = vl;
        }


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual basic_atom_ptr atom() const;
              
    protected:        
              
        virtual void assign_from(assignment_entity_ptr from);

    private:

        type_atom_ptr type_;
        valueset_atom_ptr valueset_;
        x680::syntactic::valueset_assignment synctas_;
    };


}

#endif	

