//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {


    /////////////////////////////////////////////////////////////////////////   
    // CLASS
    /////////////////////////////////////////////////////////////////////////    
    // field_entity
    /////////////////////////////////////////////////////////////////////////  

    field_entity::field_entity(basic_entity_ptr scope, const std::string& nm, fieldkind_type tp, tagmarker_type mkr) :
    basic_entity(scope, nm, et_ClassField), fieldkind_(tp), marker_(mkr) {
    }

    typefield_entity_ptr field_entity::as_typefield() {
        return (fieldkind_ == fkind_TypeFieldSpec) ? 
            boost::static_pointer_cast<typefield_entity> (self()) : typefield_entity_ptr();
    }

    valuefield_entity_ptr field_entity::as_valuefield() {
        return (fieldkind_ == fkind_FixedTypeValueFieldSpec) ? 
            boost::static_pointer_cast<valuefield_entity> (self()) : valuefield_entity_ptr();
    }

    valuesetfield_entity_ptr field_entity::as_valuesetfield() {
        return (fieldkind_ == fkind_FixedTypeValueSetFieldSpec) ? 
            boost::static_pointer_cast<valuesetfield_entity> (self()) : valuesetfield_entity_ptr();
    }

    reffvaluefield_entity_ptr field_entity::as_reffvaluefield() {
        return (fieldkind_ == fkind_VariableTypeValueFieldSpec) ? 
            boost::static_pointer_cast<reffvaluefield_entity> (self()) : reffvaluefield_entity_ptr();
    }

    reffvaluesetfield_entity_ptr field_entity::as_reffvaluesetfield() {
        return (fieldkind_ == fkind_VariableTypeValueSetFieldSpec) ? 
            boost::static_pointer_cast<reffvaluesetfield_entity> (self()) : reffvaluesetfield_entity_ptr();
    }

    objectfield_entity_ptr field_entity::as_objectfield() {
        return (fieldkind_ == fkind_ObjectFieldSpec) ? 
            boost::static_pointer_cast<objectfield_entity> (self()) : objectfield_entity_ptr();
    }

    objectsetfield_entity_ptr field_entity::as_objectsetfield() {
        return (fieldkind_ == fkind_ObjectSetFieldSpec) ? 
            boost::static_pointer_cast<objectsetfield_entity> (self()) : objectsetfield_entity_ptr();
    }

    undeffield_entity_ptr field_entity::as_undeffield() {
        return (fieldkind_ == fkind_FixedType_or_Object) ?
            boost::static_pointer_cast<undeffield_entity> (self()) : undeffield_entity_ptr();
    }

    undefsetfield_entity_ptr field_entity::as_undefsetfield() {
        return (fieldkind_ == fkind_FixedTypeSet_or_ObjectSet) ? 
            boost::static_pointer_cast<undefsetfield_entity> (self()) : undefsetfield_entity_ptr();
    }

    /////////////////////////////////////////////////////////////////////////   
    // typefield_entity
    /////////////////////////////////////////////////////////////////////////  

    void typefield_entity::resolve(basic_atom_ptr holder) {
        if (_default())
            _default()->resolve_reff();
    }

    /////////////////////////////////////////////////////////////////////////   
    // valuefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void valuefield_entity::resolve(basic_atom_ptr holder) {
        if (type())
            type()->resolve_reff();
        if (_default())
            _default()->resolve_reff(type());
    }


    /////////////////////////////////////////////////////////////////////////   
    // valuefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void valuesetfield_entity::resolve(basic_atom_ptr holder) {
        if (type())
            type()->resolve_reff();
        if (_default())
            _default()->resolve_reff(type());
    }

    /////////////////////////////////////////////////////////////////////////   
    // reffvaluefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void reffvaluefield_entity::resolve(basic_atom_ptr holder) {
        if (_default())
            _default()->resolve_reff();
        if (field()->expecteddef()) {
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (field()->expectedname() == (*it)->name()) {
                    if (((*it)->as_classfield()) && ((*it)->as_classfield()->fieldkind() != fkind_TypeFieldSpec))
                        semantics::error("Field '" + name() + "' refference error in " + source_throw());
                    field()->reff(*it);
                    return;
                }
            }
        }
        referenceerror_throw("Field refference error :",field()->expectedname());
    }


    /////////////////////////////////////////////////////////////////////////   
    // reffvaluefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void reffvaluesetfield_entity::resolve(basic_atom_ptr holder) {
        if (_default())
            _default()->resolve_reff();
        if (field()->expecteddef()) {
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (field()->expectedname() == (*it)->name()) {
                    if (((*it)->as_classfield()) && ((*it)->as_classfield()->fieldkind() != fkind_TypeFieldSpec))
                        semantics::error("Field '" + name() + "' refference error in " + source_throw());
                    field()->reff(*it);
                    return;
                }
            }
        }
        referenceerror_throw("Field refference error :",field()->expectedname());
    }

    /////////////////////////////////////////////////////////////////////////   
    // objectfield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void objectfield_entity::resolve(basic_atom_ptr holder) {
        if (_class())
            _class()->resolve_reff();
        if (_default())
            _default()->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // objectsetfield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void objectsetfield_entity::resolve(basic_atom_ptr holder) {
        if (_class())
            _class()->resolve_reff();
        if (_default())
            _default()->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // undeffield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void undeffield_entity::resolve(basic_atom_ptr holder) {

    }


    /////////////////////////////////////////////////////////////////////////   
    // undeffield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void undefsetfield_entity::resolve(basic_atom_ptr holder) {

    }


    /////////////////////////////////////////////////////////////////////////   
    // sintax_atom
    /////////////////////////////////////////////////////////////////////////      

    groupsyntax_atom_ptr syntax_atom::as_group() {
        return isgroup_ ? 
            boost::static_pointer_cast<groupsyntax_atom> (self()) : groupsyntax_atom_ptr();
    }

    void syntax_atom::resolve(basic_atom_ptr holder) {
        if (expecteddef()) {
            if (expectedname().empty()){
                return;}
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (expectedname() == (*it)->name()) {
                    reff(*it);
                    return;
                }
            }
            scope()->referenceerror_throw("Field refference error :", expectedname());
        }
    }

    /////////////////////////////////////////////////////////////////////////   
    // groupsyntax_atom
    ///////////////////////////////////////////////////////////////////////// 

    void groupsyntax_atom::resolve(basic_atom_ptr holder) {
        for (syntax_atom_vct::iterator it = group_.begin(); it != group_.end(); ++it)
            (*it)->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    //class_atom
    /////////////////////////////////////////////////////////////////////////   

    class_atom::class_atom(basic_entity_ptr scope, definedclass_type tp)
    : basic_atom(at_Class, scope), builtin_(tp) {
    }

    class_atom::class_atom(basic_entity_ptr scope, const std::string& reff, definedclass_type tp)
    : basic_atom(at_Class, scope, reff), builtin_(tp) {
    }

    bool class_atom::isrefferrence() const {
        return (((builtin_ == cl_Reference)
                || (builtin_ == cl_TYPE_IDENTIFIER)
                || (builtin_ == cl_ABSTRACT_SYNTAX)) && (reff()));
    }    

    void class_atom::resolve(basic_atom_ptr holder) {
        if (builtin_ == cl_Reference)
            resolve_reff();
    }



    /////////////////////////////////////////////////////////////////////////   
    // classassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    classassignment_entity::classassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp) :
    assignment_entity(scope, nm, et_Class), class_(tp) {
    };

    class_atom_ptr classassignment_entity::_class() const {
        return class_;
    }

    basic_entity_ptr classassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (basic_entity_ptr argfnd = assignment_entity::find_by_name(nm))
            return argfnd;          
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

    void classassignment_entity::resolve(basic_atom_ptr holder) {
        assignment_entity::resolve(holder);
        if (_class())
            _class()->resolve();
        if (withsyntax())
            withsyntax()->resolve();
        resolve_child();
    }

    void classassignment_entity::preresolve() {
        assignment_entity::preresolve();
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
            if ((*it)->as_classfield()) {
                if ((*it)->as_classfield()->as_undeffield()) {
                    undeffield_entity_ptr tmp = (*it)->as_classfield()->as_undeffield();
                    basic_entity_ptr fnd = scope()->find(tmp->big()->reff());
                    if (fnd) {
                        if (fnd->kind() == et_Type) {
                            type_atom_ptr tp = type_atom_ptr(new type_atom(scope(), tmp->big()->reff()->name(), t_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaultv())
                                    tmp->referenceerror_throw("Classassignment resolve error : ", tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new valuefield_entity(scope(), tmp->name(), tp, tmp->_defaultv()));
                            } else
                                *it = basic_entity_ptr(new valuefield_entity(scope(), tmp->name(), tp, false, tmp->marker()));
                        }
                        if (fnd->kind() == et_Class) {
                            class_atom_ptr tp = class_atom_ptr(new class_atom(scope(), tmp->big()->reff()->name(), cl_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaulto())
                                    tmp->referenceerror_throw("Classassignment resolve error : ", tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new objectfield_entity(scope(), tmp->name(), tp, tmp->_defaulto()));
                            } else
                                *it = basic_entity_ptr(new objectfield_entity(scope(), tmp->name(), tp, tmp->marker()));
                        }
                    } else
                        tmp->referenceerror_throw("Classassignment resolve error : ", tmp->big()->reff()->name());
                } else if ((*it)->as_classfield()->as_undefsetfield()) {
                    undefsetfield_entity_ptr tmp = (*it)->as_classfield()->as_undefsetfield();
                    basic_entity_ptr fnd = scope()->find(tmp->big()->reff());
                    if (fnd) {
                        if (fnd->kind() == et_Type) {
                            type_atom_ptr tp = type_atom_ptr(new type_atom(scope(), tmp->big()->reff()->name(), t_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaultv())
                                    tmp->referenceerror_throw("Classassignment resolve error : ", tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new valuesetfield_entity(scope(), tmp->name(), tp, tmp->_defaultv()));
                            } else
                                *it = basic_entity_ptr(new valuesetfield_entity(scope(), tmp->name(), tp, tmp->marker()));
                        }
                        if (fnd->kind() == et_Class) {
                            class_atom_ptr tp = class_atom_ptr(new class_atom(scope(), tmp->big()->reff()->name(), cl_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaulto())
                                    tmp->referenceerror_throw("Classassignment resolve error : ", tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new objectsetfield_entity(scope(), tmp->name(), tp, tmp->_defaulto()));
                            } else
                                *it = basic_entity_ptr(new objectsetfield_entity(scope(), tmp->name(), tp, tmp->marker()));
                        }
                    } else
                        tmp->referenceerror_throw("Classassignment resolve error : ", tmp->big()->reff()->name());
                }
            }
        }
    }



}
