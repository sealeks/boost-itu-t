//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {



    /////////////////////////////////////////////////////////////////////////   
    // VALUE
    ///////////////////////////////////////////////////////////////////////// 
    // value_atom
    /////////////////////////////////////////////////////////////////////////       

    value_atom::value_atom(basic_entity_ptr scp, value_type tpv)
    : basic_atom(scp), valtype_(tpv) {
    }

    value_atom::value_atom(basic_entity_ptr scp, const std::string& reff, value_type tpv)
    : basic_atom(reff, scp), valtype_(tpv) {
    }

    numvalue_atom* value_atom::as_number() {
        return dynamic_cast<numvalue_atom*> (this);
    }

    realvalue_atom* value_atom::as_real() {
        return dynamic_cast<realvalue_atom*> (this);
    }

    boolvalue_atom* value_atom::as_bool() {
        return dynamic_cast<boolvalue_atom*> (this);
    }

    strvalue_atom* value_atom::as_cstr() {
        return dynamic_cast<strvalue_atom*> (this);
    }

    namedvalue_atom* value_atom::as_named() {
        return dynamic_cast<namedvalue_atom*> (this);
    }

    structvalue_atom* value_atom::as_struct() {
        return (valtype() == v_struct) ? dynamic_cast<structvalue_atom*> (this) : 0;
    }

    structvalue_atom* value_atom::as_objid() {
        return (valtype() == v_objectid) ? dynamic_cast<structvalue_atom*> (this) : 0;
    }

    structvalue_atom* value_atom::as_valuelist() {
        return (valtype() == v_value_list) ? dynamic_cast<structvalue_atom*> (this) : 0;
    }

    structvalue_atom* value_atom::as_definedlist() {
        return (valtype() == v_defined_list) ? dynamic_cast<structvalue_atom*> (this) : 0;
    }

    structvalue_atom* value_atom::as_numberlist() {
        return (valtype() == v_number_list) ? dynamic_cast<structvalue_atom*> (this) : 0;
    }

    structvalue_atom* value_atom::as_list() {
        return dynamic_cast<structvalue_atom*> (this);
    }

    definedvalue_atom* value_atom::as_defined() {
        return dynamic_cast<definedvalue_atom*> (this);
    }

    fromobjectvalue_atom* value_atom::as_fromobject() {
        return dynamic_cast<fromobjectvalue_atom*> (this);
    }

    choicevalue_atom* value_atom::as_choice() {
        return dynamic_cast<choicevalue_atom*> (this);
    }

    openvalue_atom* value_atom::as_open() {
        return dynamic_cast<openvalue_atom*> (this);
    }

    assignvalue_atom* value_atom::as_assign() {
        return dynamic_cast<assignvalue_atom*> (this);
    }

    nullvalue_atom* value_atom::as_null() {
        return dynamic_cast<nullvalue_atom*> (this);
    }

    emptyvalue_atom* value_atom::as_empty() {
        return dynamic_cast<emptyvalue_atom*> (this);
    }

    void value_atom::resolve_vect(value_vct& vl, basic_atom_ptr holder ) {
        for (value_vct::iterator it = vl.begin(); it != vl.end(); ++it)
            (*it)->resolve_reff(holder);
    }




    /////////////////////////////////////////////////////////////////////////   
    // namedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void namedvalue_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff(holder);
    }



    /////////////////////////////////////////////////////////////////////////   
    // structvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void structvalue_atom::resolve(basic_atom_ptr holder) {
        resolve_vect(values_, holder);
    }


    /////////////////////////////////////////////////////////////////////////   
    // definedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void definedvalue_atom::resolve(basic_atom_ptr holder) {
        resolve_reff(holder);
    }


    /////////////////////////////////////////////////////////////////////////     
    // fromobjectvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectvalue_atom::fromobjectvalue_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : value_atom(scp, v_ValueFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectvalue_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve(holder);
    }


    /////////////////////////////////////////////////////////////////////////   
    // assignvalue_atom
    ///////////////////////////////////////////////////////////////////////// 

    void assignvalue_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff(holder);
    }

    /////////////////////////////////////////////////////////////////////////   
    // choicevalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void choicevalue_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff(holder);
    }


    /////////////////////////////////////////////////////////////////////////   
    // openvalue_atom_atom
    /////////////////////////////////////////////////////////////////////////      

    void openvalue_atom::resolve(basic_atom_ptr holder) {
        if (type_)
            type_->resolve();
        if (value_)
            value_->resolve_reff(type_);
    }



    /////////////////////////////////////////////////////////////////////////   
    // valueassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    valueassignment_entity::valueassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl) :
    assignment_entity(scope, nm, et_Value), type_(tp), value_(vl) {
    };

    void valueassignment_entity::check_value_with_exception(value_type tp) {
        if ((value()) && (value()->root()) && (value()->root()->as_value())) {
            if (value()->root()->as_value()->valtype() != tp)
                throw semantics::error("value '" + name() + "' has invalid type " +
                    modulerefname());
        }
    }

    basic_entity_ptr valueassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (sch & local_search) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if ((type()->reff() && (type()->reff()->name()!=nm))) {
                type()->resolve_reff(basic_atom_ptr(), sch);              
                if (basic_entity_ptr fnd = type()->reff()->find_by_name(nm, sch))
                    return fnd;
            }
        }
        if (!(sch & extend_search))
                return basic_entity_ptr();        
        if (basic_entity_ptr fnd = assignment_entity::find_by_name(nm))
            return fnd;
        if (scope()) {
            prefind(nm, scope()->childs());
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
                if (nm == (*it)->name())
                    return *it;
        }
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

    void valueassignment_entity::resolve(basic_atom_ptr holder) {
        assignment_entity::resolve(holder);
        resolve_child();
        type()->resolve();
        if (value())
            value()->resolve(type());
    }



}
