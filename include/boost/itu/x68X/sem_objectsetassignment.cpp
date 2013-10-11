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
    : basic_atom(scope), builtin_(tp) {
    }

    objectset_atom::objectset_atom(basic_entity_ptr scope, const std::string& reff, objectset_type tp)
    : basic_atom(reff, scope), builtin_(tp) {
    }

    definedobjectset_atom* objectset_atom::as_defined() {
        return dynamic_cast<definedobjectset_atom*> (this);
    }

    defnobjectset_atom* objectset_atom::as_defn() {
        return dynamic_cast<defnobjectset_atom*> (this);
    }

    fromobjectobjectset_atom* objectset_atom::as_fromobject() {
        return dynamic_cast<fromobjectobjectset_atom*> (this);
    }

    fromobjectsetobjectset_atom* objectset_atom::as_fromobjectset() {
        return dynamic_cast<fromobjectsetobjectset_atom*> (this);
    }

    void objectset_atom::resolve() {
        if (builtin_ == os_defined)
            resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defineobjectset_atom
    /////////////////////////////////////////////////////////////////////////    

    void definedobjectset_atom::resolve() {
        resolve_reff();
    }  

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectobjectset_atom
    /////////////////////////////////////////////////////////////////////////        

    fromobjectobjectset_atom::fromobjectobjectset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectobjectset_atom::resolve() {
        if (object())
            object()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectsetobjectset_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectsetobjectset_atom::fromobjectsetobjectset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObjects), objectset_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectsetobjectset_atom::resolve() {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // defnobjectset_atom
    /////////////////////////////////////////////////////////////////////////      

    void defnobjectset_atom::resolve() {
        for (object_atom_vct::iterator it = objects_.begin(); it != objects_.end(); ++it) {
            (*it)->resolve();
        }
    };

    /////////////////////////////////////////////////////////////////////////   
    // objectsetassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    objectsetassignment_entity::objectsetassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, objectset_atom_ptr objs) :
    assignment_entity(scope, nm, et_ObjectSet), class_(cls), objectset_(objs) {
    };

    basic_entity_ptr objectsetassignment_entity::find_by_name(const std::string& nm, bool all) {
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
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    void objectsetassignment_entity::resolve() {
        assignment_entity::resolve();
        if (_class())
            _class()->resolve();
        if (objectset())
            objectset()->resolve();
    }


}
