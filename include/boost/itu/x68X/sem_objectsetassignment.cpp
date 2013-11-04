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

    definedobjectset_atom_ptr objectset_atom::as_defined() {
        return boost::dynamic_pointer_cast<definedobjectset_atom> (self());
    }

    defnobjectset_atom_ptr objectset_atom::as_defn() {
        return boost::dynamic_pointer_cast<defnobjectset_atom> (self());
    }

    fromobjectobjectset_atom_ptr objectset_atom::as_fromobject() {
        return boost::dynamic_pointer_cast<fromobjectobjectset_atom> (self());
    }

    fromobjectsetobjectset_atom_ptr objectset_atom::as_fromobjectset() {
        return boost::dynamic_pointer_cast<fromobjectsetobjectset_atom> (self());
    }

    void objectset_atom::resolve(basic_atom_ptr holder) {
        if (builtin_ == os_defined)
            resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defineobjectset_atom
    /////////////////////////////////////////////////////////////////////////    

    void definedobjectset_atom::resolve(basic_atom_ptr holder) {
        resolve_reff();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectobjectset_atom
    /////////////////////////////////////////////////////////////////////////        

    fromobjectobjectset_atom::fromobjectobjectset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp ,refffld))) {
    };

    void fromobjectobjectset_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectsetobjectset_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectsetobjectset_atom::fromobjectsetobjectset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObjects), objectset_(obj), field_(basic_atom_ptr(new basic_atom(scp ,refffld))) {
    };

    void fromobjectsetobjectset_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // defnobjectset_atom
    /////////////////////////////////////////////////////////////////////////      

    void defnobjectset_atom::resolve(basic_atom_ptr holder) {
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
    }


}
