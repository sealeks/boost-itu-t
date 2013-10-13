//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef        _ITU_ASN1_SEM_OBJECTSETASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_OBJECTSETASSIGNMENT_IMPLEMENTATIUON_H_

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

        definedobjectset_atom* as_defined();

        defnobjectset_atom* as_defn();

        fromobjectobjectset_atom* as_fromobject();

        fromobjectsetobjectset_atom* as_fromobjectset();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_type builtin_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobjectobjectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjectobjectset_atom : public objectset_atom {

    public:

        fromobjectobjectset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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
    // fromobjectsetobjectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjectsetobjectset_atom : public objectset_atom {

    public:

        fromobjectsetobjectset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj = objectset_atom_ptr());

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
    // defineobjectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class definedobjectset_atom : public objectset_atom {

    public:

        definedobjectset_atom(basic_entity_ptr scope, const std::string& reff) : objectset_atom(scope, reff, os_defined) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    };


    /////////////////////////////////////////////////////////////////////////        
    // defnobjectset_atom
    /////////////////////////////////////////////////////////////////////////  

    class defnobjectset_atom : public objectset_atom {

    public:

        defnobjectset_atom(basic_entity_ptr scope, object_atom_vct objs = object_atom_vct())
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

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;
        class_atom_ptr class_;
    };


}

#endif	

