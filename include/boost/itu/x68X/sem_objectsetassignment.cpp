//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {



    /////////////////////////////////////////////////////////////////////////   
    // OBJECTSET
    /////////////////////////////////////////////////////////////////////////       
    /////////////////////////////////////////////////////////////////////////   
    // object_atom
    /////////////////////////////////////////////////////////////////////////  

    objectset_atom::objectset_atom(basic_entity_ptr scope, objectset_type tp)
    : basic_atom(at_ObjectSet, scope), builtin_(tp) {
    }

    objectset_atom::objectset_atom(basic_entity_ptr scope, const std::string& reff, objectset_type tp)
    : basic_atom(at_ObjectSet, scope, reff), builtin_(tp) {
    }

    bool objectset_atom::isrefferrence() const {
        return (((builtin_ == os_defined)
                || (builtin_ == os_ObjectSetFromObject)
                || (builtin_ == os_ObjectSetFromObjects)) && (reff()));
    }

    defined_objectset_atom_ptr objectset_atom::as_defined() {
        return builtin_ == os_defined ?
                boost::static_pointer_cast<defined_objectset_atom> (self()) : defined_objectset_atom_ptr();
    }

    defn_objectset_atom_ptr objectset_atom::as_defn() {
        return builtin_ == os_Strait ?
                boost::static_pointer_cast<defn_objectset_atom> (self()) : defn_objectset_atom_ptr();
    }

    fromobject_objectset_atom_ptr objectset_atom::as_fromobject() {
        return builtin_ == os_ObjectSetFromObject ?
                boost::static_pointer_cast<fromobject_objectset_atom> (self()) : fromobject_objectset_atom_ptr();
    }

    fromobjects_objectset_atom_ptr objectset_atom::as_fromobjectset() {
        return builtin_ == os_ObjectSetFromObjects ?
                boost::static_pointer_cast<fromobjects_objectset_atom> (self()) : fromobjects_objectset_atom_ptr();
    }

    void objectset_atom::resolve(basic_atom_ptr holder) {
        if (builtin_ == os_defined)
            resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defineobjectset_atom
    /////////////////////////////////////////////////////////////////////////    

    void defined_objectset_atom::resolve(basic_atom_ptr holder) {
        resolve_reff();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobject_objectset_atom
    /////////////////////////////////////////////////////////////////////////        

    fromobject_objectset_atom::fromobject_objectset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobject_objectset_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
        if (object()->reff()) {
            assignment_entity_ptr tmpasmt = object()->reff()->as_assigment();
            if (tmpasmt) {
                if (tmpasmt->find_component(field_->expectedname())) {
                    reff(tmpasmt->find_component(field_->expectedname()));
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjects_objectset_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjects_objectset_atom::fromobjects_objectset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObjects), objectset_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobjects_objectset_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
        if (objectset()->reff()) {
            assignment_entity_ptr tmpasmt = objectset()->reff()->as_assigment();
            if (tmpasmt) {
                if (tmpasmt->find_component(field_->expectedname())) {
                    reff(tmpasmt->find_component(field_->expectedname()));
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////        
    // defn_objectset_atom
    /////////////////////////////////////////////////////////////////////////      

    void defn_objectset_atom::resolve(basic_atom_ptr holder) {
        for (object_atom_vct::iterator it = objects_.begin(); it != objects_.end(); ++it) {
            (*it)->resolve();
        }
    };

    /////////////////////////////////////////////////////////////////////////   
    // objectsetassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    objectsetassignment_entity::objectsetassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, objectset_atom_ptr objs) :
    assignment_entity(scope, nm, et_ObjectSet), objectset_(objs), class_(cls) {
    };

    basic_atom_ptr objectsetassignment_entity::atom() const {
        return objectset_;
    }    

    objectset_atom_ptr objectsetassignment_entity::objectset() const {
        return objectset_;
    }

    basic_entity_ptr objectsetassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (basic_entity_ptr argfnd = assignment_entity::find_by_name(nm))
            return argfnd;
        if (scope()) {
            prefind(nm, scope()->childs());
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
                if (nm == (*it)->name()) {
                    return *it;
                }
        }
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

    void objectsetassignment_entity::resolve(basic_atom_ptr holder) {
        assignment_entity::resolve(holder);
        if (_class())
            _class()->resolve();
        if (objectset())
            objectset()->resolve();
        assignment_entity::resolve_complex<objectsetassignment_entity>();
    }

    void objectsetassignment_entity::assign_from(assignment_entity_ptr from) {
        if (from->as_objectsetassigment()) {
            assignment_entity::assign_from(from);
            objectset_atom_ptr selftype = objectset_;
            objectset_ = from->as_objectsetassigment()->objectset_;
        }
    }


}
