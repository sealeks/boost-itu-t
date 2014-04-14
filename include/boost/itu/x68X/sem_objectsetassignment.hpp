//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef        _ITU_T_SEM_OBJECTSETASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_OBJECTSETASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>

namespace x680 {


    /////////////////////////////////////////////////////////////////////////   
    // OBJECTSET
    /////////////////////////////////////////////////////////////////////////        
    // objectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class objectset_atom : public basic_atom {

    public:

        objectset_atom(basic_entity_ptr scope, objectset_type tp);
        objectset_atom(basic_entity_ptr scope, const std::string& reff, objectset_type tp);

        objectset_type builtin() const {
            return builtin_;
        }

        virtual bool isrefferrence() const;

        defined_objectset_atom_ptr as_defined();

        defn_objectset_atom_ptr as_defn();

        fromobject_objectset_atom_ptr as_fromobject();

        fromobjects_objectset_atom_ptr as_fromobjectset();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_type builtin_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // defineobjectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class defined_objectset_atom : public objectset_atom {

    public:

        defined_objectset_atom(basic_entity_ptr scope, const std::string& reff) : objectset_atom(scope, reff, os_defined) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    };


    /////////////////////////////////////////////////////////////////////////        
    // defn_objectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class defn_objectset_atom : public objectset_atom {

    public:

        defn_objectset_atom(basic_entity_ptr scope, object_atom_vct objs = object_atom_vct())
        : objectset_atom(scope, os_Strait), objects_(objs) {
        };

        object_atom_vct& objects() {
            return objects_;
        }

        void objects(object_atom_vct vl) {
            objects_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        object_atom_vct objects_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobject_objectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobject_objectset_atom : public objectset_atom {

    public:

        fromobject_objectset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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
    // fromobjects_objectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjects_objectset_atom : public objectset_atom {

    public:

        fromobjects_objectset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj = objectset_atom_ptr());

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
    // objectsetassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    class objectsetassignment_entity : public assignment_entity {

    public:
        objectsetassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, objectset_atom_ptr objs = objectset_atom_ptr());

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        objectset_atom_ptr objectset() const;

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        const x680::syntactic::objectset_assignment& synctas() const {
            return synctas_;
        }

        void synctas(const x680::syntactic::objectset_assignment& vl) {
            synctas_ = vl;
        }

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual basic_atom_ptr atom() const ;
        
    protected:                

        virtual void assign_from(assignment_entity_ptr from);

    private:

        objectset_atom_ptr objectset_;
        class_atom_ptr class_;
        x680::syntactic::objectset_assignment synctas_;
    };


}

#endif	

