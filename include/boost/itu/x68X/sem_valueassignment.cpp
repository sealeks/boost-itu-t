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
    : basic_atom(at_Value, scp), valtype_(tpv) {
    }

    value_atom::value_atom(basic_entity_ptr scp, const std::string& reff, value_type tpv)
    : basic_atom(at_Value, scp, reff), valtype_(tpv) {
    }
   

    bool value_atom::isrefferrence() const {
        return (((valtype()==v_defined) 
                || (valtype()==v_defined_assign)
                || (valtype()==v_ValueFromObject)) && (reff()));}

    numvalue_atom_ptr value_atom::as_number() {
        return (valtype() == v_number) ?
                boost::static_pointer_cast<numvalue_atom> (self()) : numvalue_atom_ptr();
    }

    realvalue_atom_ptr value_atom::as_real() {
        return (valtype() == v_real) ?
                boost::static_pointer_cast<realvalue_atom> (self()) : realvalue_atom_ptr();
    }

    boolvalue_atom_ptr value_atom::as_bool() {
        return (valtype() == v_boolean) ?
                boost::static_pointer_cast<boolvalue_atom> (self()) : boolvalue_atom_ptr();
    }

    strvalue_atom_ptr value_atom::as_cstr() {
        return ((valtype() == v_bstring) || (valtype() == v_hstring) || (valtype() == v_cstring)) ?
                boost::static_pointer_cast<strvalue_atom> (self()) : strvalue_atom_ptr();
    }

    namedvalue_atom_ptr value_atom::as_named() {
        return (valtype() == v_named_value) ?
                boost::static_pointer_cast<namedvalue_atom> (self()) : namedvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_struct() {
        return (valtype() == v_struct) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_objid() {
        return (valtype() == v_objectid) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_valuelist() {
        return (valtype() == v_value_list) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_definedlist() {
        return (valtype() == v_defined_list) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_numberlist() {
        return (valtype() == v_number_list) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_list() {
        return ((valtype() == v_struct) || (valtype() == v_struct) || (valtype() == v_objectid) ||
                (valtype() == v_value_list) || (valtype() == v_defined_list) || (valtype() == v_number_list)) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    defined_value_atom_ptr value_atom::as_defined() {
        return (valtype() == v_defined) ?
                boost::static_pointer_cast<defined_value_atom> (self()) : defined_value_atom_ptr();
    }

    fromobject_value_atom_ptr value_atom::as_fromobject() {
        return (valtype() == v_ValueFromObject) ?
                boost::static_pointer_cast<fromobject_value_atom> (self()) : fromobject_value_atom_ptr();
    }

    choicevalue_atom_ptr value_atom::as_choice() {
        return (valtype() == v_choice) ?
                boost::static_pointer_cast<choicevalue_atom> (self()) : choicevalue_atom_ptr();
    }

    openvalue_atom_ptr value_atom::as_open() {
        return (valtype() == v_open) ?
                boost::static_pointer_cast<openvalue_atom> (self()) : openvalue_atom_ptr();
    }

    assignvalue_atom_ptr value_atom::as_assign() {
        return (valtype() == v_defined_assign) ?
                boost::static_pointer_cast<assignvalue_atom> (self()) : assignvalue_atom_ptr();
    }

    nullvalue_atom_ptr value_atom::as_null() {
        return (valtype() == v_null) ?
                boost::static_pointer_cast<nullvalue_atom> (self()) : nullvalue_atom_ptr();
    }

    emptyvalue_atom_ptr value_atom::as_empty() {
        return (valtype() == v_empty) ?
                boost::static_pointer_cast<emptyvalue_atom> (self()) : emptyvalue_atom_ptr();
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
    // defined_value_atom
    /////////////////////////////////////////////////////////////////////////      

    void defined_value_atom::resolve(basic_atom_ptr holder) {
        resolve_reff(holder);
    }


    /////////////////////////////////////////////////////////////////////////     
    // fromobject_value_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobject_value_atom::fromobject_value_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : value_atom(scp, v_ValueFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp ,refffld))) {
    };

    void fromobject_value_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve(holder);
        if (object()->reff()) {
            assignment_entity_ptr tmpasmt=object()->reff()->as_assigment(); 
            if (tmpasmt) {
                if (tmpasmt->find_component(field_->expectedname())) {
                    reff(tmpasmt->find_component(field_->expectedname()));
                }
            }
        }          
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
